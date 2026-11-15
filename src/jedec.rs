//! Pure-Rust JESD3-C JEDEC fuse-map generator.
//!
//! Operates entirely in memory with no OS/file access, making it 100%
//! compatible with `wasm32-unknown-unknown`.

use core::fmt;
use std::collections::HashMap;

use crate::cube::Part;
pub use crate::device::{DeviceConfig, TargetDevice};
use crate::pla::Pla;

/// ASCII Start-of-Text (`0x02`) opening a JEDEC JESD3-C transmission.
pub const STX: char = '\x02';

/// ASCII End-of-Text (`0x03`) closing the JEDEC body before the transmission checksum.
pub const ETX: char = '\x03';

/// Errors produced when configuring a target PLD or translating a [`Pla`] to JEDEC.
#[derive(Clone, Debug, PartialEq, Eq)]
pub enum JedecError {
    /// The requested device name is not supported yet.
    UnsupportedDevice(String),
    /// The PLA has more inputs than the target device supports.
    TooManyInputs { pla_inputs: usize, max_inputs: usize },
    /// The PLA has more outputs than the target device supports.
    TooManyOutputs { pla_outputs: usize, max_outputs: usize },
    /// An output requires more product terms than its assigned macrocell provides.
    TooManyProductTerms {
        output: usize,
        required: usize,
        available: usize,
    },
    /// A fuse block exceeds the device's total fuse count.
    FuseOutOfRange { addr: usize, len: usize, total_fuses: usize },
    /// A signal was assigned to a pin that cannot act as an input (e.g. GND/VCC).
    InvalidPinForInput { signal: String, pin: usize },
    /// A signal was assigned to a pin that has no output macrocell (e.g. pins 1..13, 24).
    InvalidPinForOutput { signal: String, pin: usize },
    /// Two signals of the same direction were assigned to the same physical pin.
    DuplicatePinAssignment { pin: usize, first: String, second: String },
    /// Failed to parse the JSON pin-mapping payload.
    InvalidPinMapJson(String),
}

impl fmt::Display for JedecError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            JedecError::UnsupportedDevice(name) => {
                write!(
                    f,
                    "unsupported target device {name:?} (supported: GAL22V10, CY37032VP44)"
                )
            }
            JedecError::TooManyInputs {
                pla_inputs,
                max_inputs,
            } => write!(
                f,
                "PLA has {pla_inputs} inputs, but device supports at most {max_inputs}"
            ),
            JedecError::TooManyOutputs {
                pla_outputs,
                max_outputs,
            } => write!(
                f,
                "PLA has {pla_outputs} outputs, but device supports at most {max_outputs}"
            ),
            JedecError::TooManyProductTerms {
                output,
                required,
                available,
            } => write!(
                f,
                "output {output} needs {required} product terms, but macrocell only has {available}"
            ),
            JedecError::FuseOutOfRange {
                addr,
                len,
                total_fuses,
            } => write!(
                f,
                "fuse block at L{addr:04} (len {len}) exceeds total fuses ({total_fuses})"
            ),
            JedecError::InvalidPinForInput { signal, pin } => write!(
                f,
                "pin {pin} cannot be used as an input for signal {signal:?}"
            ),
            JedecError::InvalidPinForOutput { signal, pin } => write!(
                f,
                "pin {pin} has no output macrocell for signal {signal:?}"
            ),
            JedecError::DuplicatePinAssignment { pin, first, second } => write!(
                f,
                "physical pin {pin} is assigned to both {first:?} and {second:?}"
            ),
            JedecError::InvalidPinMapJson(msg) => write!(f, "invalid pin_map JSON: {msg}"),
        }
    }
}

impl std::error::Error for JedecError {}

/// A single `*L<addr> <bits>` fuse-programming block.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct FuseBlock {
    /// Starting decimal fuse address.
    pub address: usize,
    /// Fuse bits (`false` = `'0'`, `true` = `'1'`).
    pub bits: Vec<bool>,
}

/// In-memory representation of a JESD3-C JEDEC file.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct JedecFile {
    /// Header title placed immediately after STX (`\x02`).
    pub header: String,
    /// `NOTE ...` metadata lines.
    pub notes: Vec<String>,
    /// Package pin count (`*QP<pins>`).
    pub pins: usize,
    /// Total fuse count (`*QF<total_fuses>`).
    pub total_fuses: usize,
    /// Default fuse state (`*F0` or `*F1`).
    pub default_fuse: bool,
    /// Programmed fuse blocks (`*L<addr> <bits>`).
    pub blocks: Vec<FuseBlock>,
}

impl JedecFile {
    /// Create a new [`JedecFile`] with default fuse state `0` (`*F0`).
    pub fn new(header: impl Into<String>, pins: usize, total_fuses: usize) -> Self {
        Self {
            header: header.into(),
            notes: Vec::new(),
            pins,
            total_fuses,
            default_fuse: false,
            blocks: Vec::new(),
        }
    }

    /// Add a `NOTE <text>` metadata line.
    pub fn add_note(&mut self, note: impl Into<String>) {
        self.notes.push(note.into());
    }

    /// Append a `*L<address> <bits>` block, validating bounds against `total_fuses`.
    pub fn add_block(&mut self, address: usize, bits: Vec<bool>) -> Result<(), JedecError> {
        if address.saturating_add(bits.len()) > self.total_fuses {
            return Err(JedecError::FuseOutOfRange {
                addr: address,
                len: bits.len(),
                total_fuses: self.total_fuses,
            });
        }
        self.blocks.push(FuseBlock { address, bits });
        Ok(())
    }

    /// Compute the 16-bit JESD3-C fuse checksum over the full fuse array (8 fuses per byte, LSB first).
    pub fn fuse_checksum(&self) -> u16 {
        let num_bytes = self.total_fuses.div_ceil(8);
        let mut bytes = vec![if self.default_fuse { 0xFFu8 } else { 0x00u8 }; num_bytes];
        let rem = self.total_fuses % 8;
        if self.default_fuse && rem != 0 && num_bytes > 0 {
            // Unused padding bits beyond `total_fuses` in the final byte are always 0 per JESD3-C.
            bytes[num_bytes - 1] = (1u8 << rem) - 1;
        }

        for block in &self.blocks {
            for (offset, &bit) in block.bits.iter().enumerate() {
                let fuse_idx = block.address + offset;
                if fuse_idx < self.total_fuses {
                    let byte_idx = fuse_idx / 8;
                    let bit_idx = fuse_idx % 8;
                    if bit {
                        bytes[byte_idx] |= 1 << bit_idx;
                    } else {
                        bytes[byte_idx] &= !(1 << bit_idx);
                    }
                }
            }
        }

        bytes
            .into_iter()
            .fold(0u16, |acc, b| acc.wrapping_add(b as u16))
    }

    /// Compute the strict 16-bit JESD3-C transmission checksum:
    /// unsigned 16-bit sum (modulo 65536) of all ASCII byte values from STX (`\x02`)
    /// through ETX (`\x03`) inclusive.
    pub fn transmission_checksum(body_with_stx_etx: &str) -> u16 {
        body_with_stx_etx
            .as_bytes()
            .iter()
            .fold(0u16, |acc, &b| acc.wrapping_add(b as u16))
    }

    /// Format the complete JESD3-C JEDEC file string, including `\x02`, `*QP`, `*QF`,
    /// `*F0`/`*F1`, `*L` blocks, fuse checksum `*C`, `\x03`, and the 4-hex-digit
    /// 16-bit transmission checksum.
    pub fn to_jedec_string(&self) -> String {
        let mut body = String::new();
        body.push(STX);
        body.push_str(&self.header);
        body.push_str("*\n");

        for note in &self.notes {
            body.push_str("NOTE ");
            body.push_str(note);
            body.push_str("*\n");
        }

        body.push_str(&format!("*QP{}*\n", self.pins));
        body.push_str(&format!("*QF{}*\n", self.total_fuses));
        body.push_str(if self.default_fuse { "*F1*\n" } else { "*F0*\n" });

        let addr_width = self.total_fuses.saturating_sub(1).to_string().len().max(4);
        for block in &self.blocks {
            body.push_str(&format!("*L{:0width$} ", block.address, width = addr_width));
            for &bit in &block.bits {
                body.push(if bit { '1' } else { '0' });
            }
            body.push_str("*\n");
        }

        let fuse_csum = self.fuse_checksum();
        body.push_str(&format!("*C{:04X}*\n", fuse_csum));
        body.push(ETX);

        let tx_csum = Self::transmission_checksum(&body);
        body.push_str(&format!("{tx_csum:04X}\n"));
        body
    }
}

impl fmt::Display for JedecFile {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        f.write_str(&self.to_jedec_string())
    }
}

/// Parse a flat JSON object mapping signal names to 1-based physical pin numbers,
/// e.g. `{"clk": 1, "en": 4, "y": 22}`.
///
/// Returns `Ok(None)` for empty or `"null"` inputs.
pub fn parse_pin_map_json(json: &str) -> Result<Option<HashMap<String, usize>>, JedecError> {
    let trimmed = json.trim();
    if trimmed.is_empty() || trimmed == "null" {
        return Ok(None);
    }
    let bytes = trimmed.as_bytes();
    let mut pos = 0usize;

    let skip_ws = |p: &mut usize| {
        while *p < bytes.len() && bytes[*p].is_ascii_whitespace() {
            *p += 1;
        }
    };

    skip_ws(&mut pos);
    if bytes.get(pos) != Some(&b'{') {
        return Err(JedecError::InvalidPinMapJson("expected '{'".to_string()));
    }
    pos += 1;

    let mut map = HashMap::new();
    skip_ws(&mut pos);
    if bytes.get(pos) == Some(&b'}') {
        pos += 1;
        skip_ws(&mut pos);
        if pos != bytes.len() {
            return Err(JedecError::InvalidPinMapJson("trailing characters after '}'".to_string()));
        }
        return Ok(Some(map));
    }

    loop {
        skip_ws(&mut pos);
        if bytes.get(pos) != Some(&b'"') {
            return Err(JedecError::InvalidPinMapJson("expected string key".to_string()));
        }
        pos += 1;
        let mut key = String::new();
        let mut closed = false;
        while pos < bytes.len() {
            let b = bytes[pos];
            pos += 1;
            if b == b'"' {
                closed = true;
                break;
            }
            if b == b'\\' {
                if pos >= bytes.len() {
                    return Err(JedecError::InvalidPinMapJson("unterminated escape".to_string()));
                }
                let esc = bytes[pos];
                pos += 1;
                match esc {
                    b'"' => key.push('"'),
                    b'\\' => key.push('\\'),
                    b'/' => key.push('/'),
                    b'n' => key.push('\n'),
                    b'r' => key.push('\r'),
                    b't' => key.push('\t'),
                    other => key.push(other as char),
                }
            } else {
                key.push(b as char);
            }
        }
        if !closed {
            return Err(JedecError::InvalidPinMapJson("unterminated string key".to_string()));
        }

        skip_ws(&mut pos);
        if bytes.get(pos) != Some(&b':') {
            return Err(JedecError::InvalidPinMapJson(format!("expected ':' after key {key:?}")));
        }
        pos += 1;

        skip_ws(&mut pos);
        let num_start = pos;
        while pos < bytes.len() && bytes[pos].is_ascii_digit() {
            pos += 1;
        }
        if pos == num_start {
            return Err(JedecError::InvalidPinMapJson(format!("expected pin integer for {key:?}")));
        }
        let pin_str = std::str::from_utf8(&bytes[num_start..pos])
            .map_err(|e| JedecError::InvalidPinMapJson(e.to_string()))?;
        let pin: usize = pin_str
            .parse()
            .map_err(|_| JedecError::InvalidPinMapJson(format!("invalid pin {pin_str:?}")))?;
        map.insert(key, pin);

        skip_ws(&mut pos);
        match bytes.get(pos) {
            Some(&b',') => pos += 1,
            Some(&b'}') => {
                pos += 1;
                break;
            }
            _ => {
                return Err(JedecError::InvalidPinMapJson("expected ',' or '}'".to_string()));
            }
        }
    }

    skip_ws(&mut pos);
    if pos != bytes.len() {
        return Err(JedecError::InvalidPinMapJson("trailing characters after '}'".to_string()));
    }
    Ok(Some(map))
}

fn resolve_input_columns(
    pla: &Pla,
    config: &DeviceConfig,
    pin_mapping: Option<&HashMap<String, usize>>,
) -> Result<Vec<usize>, JedecError> {
    let mut cols = vec![None; pla.nin];
    let mut used_cols: Vec<Option<String>> = vec![None; config.max_inputs];

    if let Some(map) = pin_mapping {
        for (in_idx, slot) in cols.iter_mut().enumerate() {
            let label = pla
                .input_labels
                .as_ref()
                .and_then(|v| v.get(in_idx))
                .cloned()
                .unwrap_or_else(|| format!("in{in_idx}"));
            if let Some(&pin) = map.get(&label) {
                let col = config
                    .pin_to_input_col(pin)
                    .ok_or_else(|| JedecError::InvalidPinForInput {
                        signal: label.clone(),
                        pin,
                    })?;
                if let Some(prev) = &used_cols[col] {
                    return Err(JedecError::DuplicatePinAssignment {
                        pin,
                        first: prev.clone(),
                        second: label,
                    });
                }
                used_cols[col] = Some(label);
                *slot = Some(col);
            }
        }
    }

    let mut next_free = 0usize;
    for (in_idx, slot) in cols.iter_mut().enumerate() {
        if slot.is_none() {
            while used_cols[next_free].is_some() {
                next_free += 1;
            }
            used_cols[next_free] = Some(format!("in{in_idx}"));
            *slot = Some(next_free);
        }
    }

    Ok(cols.into_iter().map(|c| c.unwrap()).collect())
}

fn resolve_output_olmcs(
    pla: &Pla,
    config: &DeviceConfig,
    pin_mapping: Option<&HashMap<String, usize>>,
) -> Result<Vec<usize>, JedecError> {
    let mut olmcs = vec![None; pla.nout];
    let mut used_olmcs: Vec<Option<String>> = vec![None; config.max_outputs];

    if let Some(map) = pin_mapping {
        for (out_idx, slot) in olmcs.iter_mut().enumerate() {
            let label = pla
                .output_labels
                .as_ref()
                .and_then(|v| v.get(out_idx))
                .cloned()
                .unwrap_or_else(|| format!("out{out_idx}"));
            if let Some(&pin) = map.get(&label) {
                let olmc = config
                    .pin_to_output_olmc(pin)
                    .ok_or_else(|| JedecError::InvalidPinForOutput {
                        signal: label.clone(),
                        pin,
                    })?;
                if let Some(prev) = &used_olmcs[olmc] {
                    return Err(JedecError::DuplicatePinAssignment {
                        pin,
                        first: prev.clone(),
                        second: label,
                    });
                }
                used_olmcs[olmc] = Some(label);
                *slot = Some(olmc);
            }
        }
    }

    let mut next_free = 0usize;
    for (out_idx, slot) in olmcs.iter_mut().enumerate() {
        if slot.is_none() {
            while used_olmcs[next_free].is_some() {
                next_free += 1;
            }
            used_olmcs[next_free] = Some(format!("out{out_idx}"));
            *slot = Some(next_free);
        }
    }

    Ok(olmcs.into_iter().map(|o| o.unwrap()).collect())
}

/// Translate a parsed [`Pla`] into a [`JedecFile`] using the provided [`DeviceConfig`]
/// and optional physical `pin_mapping` (`signal_name -> 1-based physical pin`).
///
/// When `pin_mapping` is `None` (or omits some signals), unassigned signals fall back
/// sequentially to the next available input column / output macrocell.
pub fn pla_to_jedec(
    pla: &Pla,
    config: &DeviceConfig,
    pin_mapping: Option<HashMap<String, usize>>,
) -> Result<JedecFile, JedecError> {
    if pla.nin > config.max_inputs {
        return Err(JedecError::TooManyInputs {
            pla_inputs: pla.nin,
            max_inputs: config.max_inputs,
        });
    }
    if pla.nout > config.max_outputs {
        return Err(JedecError::TooManyOutputs {
            pla_outputs: pla.nout,
            max_outputs: config.max_outputs,
        });
    }

    let input_cols = resolve_input_columns(pla, config, pin_mapping.as_ref())?;
    let output_olmcs = resolve_output_olmcs(pla, config, pin_mapping.as_ref())?;

    let mut jedec = JedecFile::new(
        format!("espresso-rs JEDEC output ({})", config.name),
        config.pins,
        config.total_fuses,
    );
    jedec.default_fuse = config.default_fuse;
    jedec.add_note(format!("DEVICE {}", config.name));
    jedec.add_note(format!("INPUTS {} OUTPUTS {}", pla.nin, pla.nout));

    if let Some(ilb) = &pla.input_labels {
        jedec.add_note(format!("ILB {}", ilb.join(" ")));
    }
    if let Some(ob) = &pla.output_labels {
        jedec.add_note(format!("OB {}", ob.join(" ")));
    }

    let mut gal_config_bits = vec![false; config.max_outputs * 2];
    let mut gal16v8_config_bits = if config.target == TargetDevice::Gal16V8 {
        let mut cfg = vec![false; 146];
        // SYN = 1, AC0 = 0 (Simple combinational mode, pins 1 and 11 available as inputs)
        cfg[2184 - config.config_base_fuse] = true;
        cfg
    } else {
        Vec::new()
    };

    for (out_idx, &olmc_idx) in output_olmcs.iter().enumerate() {
        let available_pts = config.terms_per_output[olmc_idx];
        let cubes: Vec<_> = pla
            .on
            .iter()
            .filter(|cube| cube.out_get(out_idx))
            .collect();

        if cubes.len() > available_pts {
            return Err(JedecError::TooManyProductTerms {
                output: out_idx,
                required: cubes.len(),
                available: available_pts,
            });
        }

        let base_addr = config.output_base_fuse[olmc_idx];

        match config.target {
            TargetDevice::Gal22V10 | TargetDevice::Gal16V8 => {
                let pt_row_offset = if config.target == TargetDevice::Gal22V10 {
                    if !cubes.is_empty() {
                        jedec.add_block(base_addr, vec![true; config.cols_per_term])?;
                    }
                    // Configure OLMC as combinatorial active-high (S0 = 1, S1 = 1).
                    gal_config_bits[olmc_idx * 2] = true;
                    gal_config_bits[olmc_idx * 2 + 1] = true;
                    1
                } else {
                    // GAL16V8 XOR bit (offset 0..8 from config_base_fuse = 2048): 1 = active high
                    gal16v8_config_bits[olmc_idx] = true;
                    0
                };

                for (pt_idx, cube) in cubes.iter().enumerate() {
                    let row = encode_spld_and_row(cube.input(), input_cols.as_slice(), config.cols_per_term);
                    let pt_addr = base_addr + (pt_row_offset + pt_idx) * config.cols_per_term;
                    jedec.add_block(pt_addr, row)?;

                    if config.target == TargetDevice::Gal16V8 {
                        // Enable PTD bit for this product term (offset 2120 - 2048 = 72)
                        gal16v8_config_bits[72 + olmc_idx * 8 + pt_idx] = true;
                    }
                }
            }
            TargetDevice::Cy37032 => {
                // Handled in dense 15,034-fuse builder below.
                let _ = base_addr;
            }
        }
    }

    match config.target {
        TargetDevice::Cy37032 => {
            build_cy37032_dense_fuses(pla, config, &input_cols, &output_olmcs, &mut jedec)?;
        }
        TargetDevice::Gal22V10 if pla.nout > 0 => {
            jedec.add_block(config.config_base_fuse, gal_config_bits)?;
        }
        TargetDevice::Gal16V8 => {
            jedec.add_block(config.config_base_fuse, gal16v8_config_bits)?;
        }
        TargetDevice::Gal22V10 => {}
    }

    Ok(jedec)
}

/// Encode a single PLA input cube directly across global SPLD AND-array columns
/// (`true_col = phys_col * 2`, `comp_col = true_col + 1`), without PIM or steering.
fn encode_spld_and_row(inp: &crate::cube::Cube, input_cols: &[usize], cols_per_term: usize) -> Vec<bool> {
    let mut row = vec![true; cols_per_term];
    for (in_idx, &phys_col) in input_cols.iter().enumerate() {
        let true_col = phys_col * 2;
        let comp_col = true_col + 1;
        match inp.get(in_idx) {
            Part::One => {
                row[true_col] = false;
                row[comp_col] = true;
            }
            Part::Zero => {
                row[true_col] = true;
                row[comp_col] = false;
            }
            Part::DontCare | Part::Empty => {
                row[true_col] = true;
                row[comp_col] = true;
            }
        }
    }
    row
}

/// Build the full 15,034-fuse dense CY37032VP44 image matching `c32p44.phy` defaults:
/// - 2 LABs × 7,501 fuses (`0..7501`, `7501..15002`)
/// - Global dedicated input / static fuses (`15002..15034`)
fn build_cy37032_dense_fuses(
    pla: &Pla,
    config: &DeviceConfig,
    input_cols: &[usize],
    output_olmcs: &[usize],
    jedec: &mut JedecFile,
) -> Result<(), JedecError> {
    const LAB_STRIDE: usize = 7501;
    const COLS: usize = 78;
    const PTM_PTS: usize = 80;
    const CTRL_PTS: usize = 7;

    let mut fuses = vec![true; config.total_fuses];

    // Initialize both LABs with Cypress c32p44.phy defaults
    for lab in 0..2 {
        let lb = lab * LAB_STRIDE;
        // 6240..6786 (7 control PTs) and 0..6240 (80 PTM PTs) are already `true` (`1`).

        // 6786..6978: PTM Steering Array (16 macrocells × 12 bits = 192 zeros)
        fuses[lb + 6786..lb + 6978].fill(false);

        // 6978..7090: Macrocells Config Bits (16 × 7 bits: "1111001" = COMB, AL, APAR=1)
        for mc in 0..16 {
            let off = lb + 6978 + mc * 7;
            fuses[off..off + 7].copy_from_slice(&[true, true, true, true, false, false, true]);
        }

        // 7090..7138: OE Muxes (16 × 3 bits = 48 zeros)
        fuses[lb + 7090..lb + 7138].fill(false);

        // 7138..7149: Bank Polarity Config (11 zeros)
        fuses[lb + 7138..lb + 7149].fill(false);

        // 7149..7500: PIM Interconnect Array (39 × 9 bits: "111111110")
        for pim in 0..39 {
            let off = lb + 7149 + pim * 9;
            fuses[off..off + 9].copy_from_slice(&[true, true, true, true, true, true, true, true, false]);
        }

        // 7500: LAB Power (0 = HIGHPWRLAB)
        fuses[lb + 7500] = false;
    }

    // 15002..15022: Dedicated inputs 33..37 (5 × 4 bits: "1100")
    for inp in 0..5 {
        let off = 15002 + inp * 4;
        fuses[off..off + 4].copy_from_slice(&[true, true, false, false]);
    }
    // 15022..15026: CIPOL (4 zeros), 15026: BUS_HOLD (0), 15027..15034: STATIC FUSES (7 zeros)
    fuses[15022..15034].fill(false);

    // Map each PLA output to its macrocell, PT rows, steering, polarity (AH), and OE (VCC)
    for (out_idx, &olmc_idx) in output_olmcs.iter().enumerate() {
        let cubes: Vec<_> = pla.on.iter().filter(|c| c.out_get(out_idx)).collect();
        if cubes.is_empty() {
            continue;
        }
        let lab = olmc_idx / 16;
        let local_mc = olmc_idx % 16;
        let lb = lab * LAB_STRIDE;

        // Macrocell POL = AH ("1111101")
        fuses[lb + 6978 + local_mc * 7 + 4] = true;
        // OE2 = VCC ("100")
        fuses[lb + 7090 + local_mc * 3] = true;

        for (pt_idx, cube) in cubes.iter().enumerate() {
            let pt_row = local_mc * 4 + 2 + pt_idx;
            if pt_row >= PTM_PTS {
                return Err(JedecError::TooManyProductTerms {
                    output: out_idx,
                    required: pt_idx + 1,
                    available: 5,
                });
            }
            let row_off = lb + pt_row * COLS;
            let inp = cube.input();
            for (in_idx, &phys_col) in input_cols.iter().enumerate() {
                let (pim_col, mux_bit) = config.input_col_to_pim(phys_col);
                let true_col = pim_col * 2;
                let comp_col = true_col + 1;
                match inp.get(in_idx) {
                    Part::One => {
                        fuses[row_off + true_col] = false;
                        fuses[row_off + comp_col] = true;
                    }
                    Part::Zero => {
                        fuses[row_off + true_col] = true;
                        fuses[row_off + comp_col] = false;
                    }
                    Part::DontCare | Part::Empty => {}
                }
                // Program PIM mux for this input in the active LAB
                let pim_off = lb + 7149 + pim_col * 9;
                fuses[pim_off..pim_off + 9].fill(true);
                fuses[pim_off + mux_bit] = false;
            }
            // Program PTM steering bit for this macrocell (bit 1 -> PT #2)
            let steer_bit = 1 + pt_idx;
            if steer_bit < 12 {
                fuses[lb + 6786 + local_mc * 12 + steer_bit] = true;
            }
        }
    }

    // Emit dense blocks matching c37kfit.exe layout
    let _ = CTRL_PTS;
    jedec.add_block(0, fuses)?;
    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn transmission_checksum_sums_all_ascii_bytes_from_stx_to_etx() {
        let pla = Pla::parse(
            "\
.i 2
.o 1
.ilb a b
.ob y
.p 1
11 1
.e
",
        )
        .unwrap();

        let cfg = DeviceConfig::gal22v10();
        let jedec = pla_to_jedec(&pla, &cfg, None).unwrap();
        let text = jedec.to_jedec_string();

        assert!(text.starts_with(STX), "JEDEC must start with STX (0x02)");
        assert!(text.contains("*QP24*"));
        assert!(text.contains("*QF5828*"));
        assert!(text.contains("*F0*"));
        assert!(text.contains("*L0044 "));
        assert!(text.contains("*L0088 0101"));

        let etx_pos = text.find(ETX).expect("JEDEC must contain ETX (0x03)");
        let transmitted = &text[..=etx_pos];
        let expected_sum: u16 = transmitted
            .as_bytes()
            .iter()
            .fold(0u16, |acc, &b| acc.wrapping_add(b as u16));

        let suffix = text[etx_pos + 1..].trim();
        assert_eq!(
            suffix,
            format!("{expected_sum:04X}"),
            "transmission checksum after ETX must equal 16-bit ASCII sum of STX..=ETX"
        );
    }

    #[test]
    fn rejects_pla_exceeding_device_limits() {
        let cfg = DeviceConfig::gal22v10();
        let too_many_in = Pla::parse(".i 23\n.o 1\n.e\n").unwrap();
        assert!(matches!(
            pla_to_jedec(&too_many_in, &cfg, None),
            Err(JedecError::TooManyInputs { .. })
        ));

        let too_many_out = Pla::parse(".i 2\n.o 11\n.e\n").unwrap();
        assert!(matches!(
            pla_to_jedec(&too_many_out, &cfg, None),
            Err(JedecError::TooManyOutputs { .. })
        ));
    }

    #[test]
    fn manual_pin_mapping_places_fuses_at_exact_physical_addresses() {
        let pla = Pla::parse(
            "\
.i 2
.o 1
.ilb en d
.ob y
.p 1
10 1
.e
",
        )
        .unwrap();

        let cfg = DeviceConfig::gal22v10();
        // Force: en -> Pin 4 (input col 3 -> bits 6..8),
        //        d  -> Pin 5 (input col 4 -> bits 8..10),
        //        y  -> Pin 22 (OLMC 1 -> OE at L0440, PT0 at L0484)
        let pin_map = parse_pin_map_json(r#"{"en": 4, "d": 5, "y": 22}"#).unwrap();
        let jedec = pla_to_jedec(&pla, &cfg, pin_map).unwrap();
        let text = jedec.to_jedec_string();

        // OE row for OLMC 1 (Pin 22) starts at 44 + 9 * 44 = 440
        assert!(text.contains("*L0440 11111111111111111111111111111111111111111111*"));
        // PT0 row for OLMC 1 starts at 484:
        // cols 0..3 -> 111111, col 3 (en=1) -> 01, col 4 (d=0) -> 10, remaining -> all 1s
        assert!(text.contains("*L0484 11111101101111111111111111111111111111111111*"));
        // Config bits at 5808: OLMC 0 is unused (00), OLMC 1 is combinatorial active-high (11)
        assert!(text.contains("*L5808 00110000000000000000*"));
    }

    #[test]
    fn cy37032_generates_valid_15034_fuse_jedec_with_f1_default_and_checksum() {
        let pla = Pla::parse(
            "\
.i 2
.o 1
.ilb a b
.ob y
.p 1
11 1
.e
",
        )
        .unwrap();

        let cfg = TargetDevice::Cy37032.config();
        // Map a -> Pin 10 (dedicated input col 32), b -> Pin 13 (col 33), y -> Pin 24 (LAB 2 MC 0)
        let pin_map = parse_pin_map_json(r#"{"a": 10, "b": 13, "y": 24}"#).unwrap();
        let jedec = pla_to_jedec(&pla, &cfg, pin_map).unwrap();
        let text = jedec.to_jedec_string();

        assert!(text.contains("*QP37*"));
        assert!(text.contains("*QF15034*"));
        assert!(text.contains("*F1*"));
        // Dense 15,034-fuse image emitted starting at L00000
        assert!(text.contains("*L00000 "));

        let etx_pos = text.find(ETX).unwrap();
        let expected_sum: u16 = text[..=etx_pos]
            .as_bytes()
            .iter()
            .fold(0u16, |acc, &b| acc.wrapping_add(b as u16));
        assert_eq!(text[etx_pos + 1..].trim(), format!("{expected_sum:04X}"));
    }

    #[test]
    fn cy37032_fuse_checksum_matches_cypress_cfd21_on_test_jed_image() {
        let pla = Pla::parse(".i 2\n.o 1\n.ilb a b\n.ob y\n.p 1\n11 1\n.e\n").unwrap();
        let cfg = TargetDevice::Cy37032.config();
        let mut jedec = pla_to_jedec(&pla, &cfg, None).unwrap();
        // Verify dense 15,034-bit block length
        assert_eq!(jedec.blocks.len(), 1);
        assert_eq!(jedec.blocks[0].bits.len(), 15034);

        // Replicate exact c37kfit.exe placement from warp_test/test.jed:
        // Reset PT0 row 0 to all 1s, place a&b at PT2 (offset 156, cols 8 & 24),
        // steering bit 1 at 6786, PIM4="111011111" & PIM12="101111111".
        let bits = &mut jedec.blocks[0].bits;
        bits[0..234].fill(true);
        bits[156 + 8] = false;
        bits[156 + 24] = false;
        bits[6786] = false;
        bits[6786 + 1] = true;
        // Restore PIM 0, 1 to unused "111111110"
        bits[7149..7149 + 9].copy_from_slice(&[true, true, true, true, true, true, true, true, false]);
        bits[7149 + 9..7149 + 18].copy_from_slice(&[true, true, true, true, true, true, true, true, false]);
        // Set PIM 4 = "111011111" and PIM 12 = "101111111"
        bits[7149 + 4 * 9..7149 + 5 * 9]
            .copy_from_slice(&[true, true, true, false, true, true, true, true, true]);
        bits[7149 + 12 * 9..7149 + 13 * 9]
            .copy_from_slice(&[true, false, true, true, true, true, true, true, true]);

        assert_eq!(
            jedec.fuse_checksum(),
            0xFD21,
            "16-bit fuse checksum must match Cypress c37kfit.exe CFD21*"
        );
    }

    #[test]
    fn gal16v8_generates_valid_2194_fuse_jedec_with_checksum() {
        let pla = Pla::parse(
            "\
.i 2
.o 1
.ilb a b
.ob y
.p 1
11 1
.e
",
        )
        .unwrap();

        let cfg = TargetDevice::Gal16V8.config();
        assert_eq!(cfg.total_fuses, 2194);
        assert_eq!(cfg.pins, 20);

        // Map a -> Pin 2 (input col 0), b -> Pin 3 (input col 1), y -> Pin 19 (OLMC 0)
        let pin_map = parse_pin_map_json(r#"{"a": 2, "b": 3, "y": 19}"#).unwrap();
        let jedec = pla_to_jedec(&pla, &cfg, pin_map).unwrap();
        let text = jedec.to_jedec_string();

        assert!(text.contains("*QP20*"));
        assert!(text.contains("*QF2194*"));
        assert!(text.contains("*F0*"));
        // OLMC 0 PT 0 starts at L0000: a=1 (true_col=0->0, comp=1), b=1 (true_col=2->0, comp=1)
        assert!(text.contains("*L0000 01011111111111111111111111111111*"));
        // Reject assigning an output to dedicated input pins 2..=9
        let bad_out = parse_pin_map_json(r#"{"a": 2, "b": 3, "y": 4}"#).unwrap();
        assert!(pla_to_jedec(&pla, &cfg, bad_out).is_err());

        let expected_fuse_csum = format!("*C{:04X}*", jedec.fuse_checksum());
        assert!(text.contains(&expected_fuse_csum));

        let etx_pos = text.find(ETX).unwrap();
        let expected_tx = JedecFile::transmission_checksum(&text[..=etx_pos]);
        assert_eq!(text[etx_pos + 1..].trim(), format!("{expected_tx:04X}"));
    }
}
