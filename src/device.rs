//! Target PLD/CPLD device definitions and physical pin-to-fusemap geometry.
//!
//! Pure Rust, `wasm32-unknown-unknown` compatible.

use crate::jedec::JedecError;

/// Supported programmable logic target architectures.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum TargetDevice {
    /// Standard Lattice GAL16V8 (20-pin DIP, 16 array inputs, 8 OLMCs, 2194 fuses, `*F0*`).
    Gal16V8,
    /// Generic Lattice/standard GAL22V10 (24-pin, 22 inputs, 10 OLMCs, 5828 fuses, `*F0*`).
    Gal22V10,
    /// Cypress Ultra37000 CY37032VP44 (44-pin PLCC, 37 logical pins, 32 macrocells, 15034 fuses, `*F1*`).
    Cy37032,
}

impl TargetDevice {
    /// Parse a device identifier string from the frontend or CLI.
    pub fn from_name(name: &str) -> Result<Self, JedecError> {
        let normalized = name.trim().to_ascii_uppercase();
        match normalized.as_str() {
            "GAL16V8" | "16V8" | "PALCE16V8" => Ok(Self::Gal16V8),
            "" | "DEFAULT" | "GAL22V10" | "22V10" | "PALCE22V10" => Ok(Self::Gal22V10),
            "CY37032" | "CY37032VP44" | "CY37032P44" | "C32P44" | "ULTRA37000" => {
                Ok(Self::Cy37032)
            }
            _ => Err(JedecError::UnsupportedDevice(name.to_string())),
        }
    }

    /// Return the [`DeviceConfig`] for this target architecture.
    pub fn config(self) -> DeviceConfig {
        match self {
            Self::Gal16V8 => DeviceConfig::gal16v8(),
            Self::Gal22V10 => DeviceConfig::gal22v10(),
            Self::Cy37032 => DeviceConfig::cy37032(),
        }
    }
}

/// Parameterized target device fuse-map geometry.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct DeviceConfig {
    /// Target device family.
    pub target: TargetDevice,
    /// Device part name (e.g. `"GAL22V10"`, `"CY37032VP44"`).
    pub name: String,
    /// Logical pin count written to `*QP`.
    pub pins: usize,
    /// Physical package pin count (e.g. 24 for DIP-24, 44 for PLCC-44).
    pub package_pins: usize,
    /// Maximum logic inputs available to the AND array.
    pub max_inputs: usize,
    /// Maximum output macrocells.
    pub max_outputs: usize,
    /// Total number of programmable fuses (`*QF`).
    pub total_fuses: usize,
    /// Default unprogrammed fuse state (`false` = `*F0*`, `true` = `*F1*`).
    pub default_fuse: bool,
    /// Number of columns per product-term row (`2 * array_inputs`).
    pub cols_per_term: usize,
    /// Number of logic product-term rows per output macrocell.
    pub terms_per_output: Vec<usize>,
    /// Starting fuse address of each output macrocell's product-term block (or OE row on GAL22V10).
    pub output_base_fuse: Vec<usize>,
    /// Starting fuse address of the macrocell configuration bits.
    pub config_base_fuse: usize,
}

impl DeviceConfig {
    /// Resolve a [`DeviceConfig`] from a device name.
    pub fn from_name(name: &str) -> Result<Self, JedecError> {
        Ok(TargetDevice::from_name(name)?.config())
    }

    /// Standard Lattice GAL16V8 geometry (20-pin DIP, 16 AND-array inputs, 8 OLMCs, 2194 fuses, `*F0*`):
    /// - Pin 1: CLK / IN
    /// - Pins 2..=9: Dedicated inputs
    /// - Pin 10: GND, Pin 20: VCC
    /// - Pin 11: /OE / IN
    /// - Pins 12..=19: I/O OLMCs (8 macrocells × 8 PTs × 32 cols = 2048 fuses)
    /// - Config / XOR / UES / PTD / SYN / AC0 / AC1: 2048..2194 (146 fuses)
    pub fn gal16v8() -> Self {
        let max_inputs = 16;
        let cols_per_term = max_inputs * 2; // 32
        let terms_per_output = vec![8; 8];
        let output_base_fuse: Vec<usize> = (0..8).map(|olmc| olmc * 8 * cols_per_term).collect();
        let config_base_fuse = 2048;
        let total_fuses = 2194; // 2048 + 8 XOR + 64 UES + 64 PTD + 1 SYN + 1 AC0 + 8 AC1

        Self {
            target: TargetDevice::Gal16V8,
            name: "GAL16V8".to_string(),
            pins: 20,
            package_pins: 20,
            max_inputs,
            max_outputs: terms_per_output.len(),
            total_fuses,
            default_fuse: false,
            cols_per_term,
            terms_per_output,
            output_base_fuse,
            config_base_fuse,
        }
    }

    /// Standard generic GAL22V10 geometry (24 pins, 22 inputs, 10 outputs, 5828 fuses, `*F0*`).
    pub fn gal22v10() -> Self {
        let max_inputs = 22;
        let cols_per_term = max_inputs * 2; // 44
        let terms_per_output = vec![8, 10, 12, 14, 16, 16, 14, 12, 10, 8];

        let mut output_base_fuse = Vec::with_capacity(terms_per_output.len());
        let mut cursor = cols_per_term; // skip AR row (row 0)
        for &pts in &terms_per_output {
            output_base_fuse.push(cursor);
            cursor += (1 + pts) * cols_per_term;
        }
        let config_base_fuse = cursor + cols_per_term; // 5808
        let total_fuses = config_base_fuse + terms_per_output.len() * 2; // 5828

        Self {
            target: TargetDevice::Gal22V10,
            name: "GAL22V10".to_string(),
            pins: 24,
            package_pins: 24,
            max_inputs,
            max_outputs: terms_per_output.len(),
            total_fuses,
            default_fuse: false,
            cols_per_term,
            terms_per_output,
            output_base_fuse,
            config_base_fuse,
        }
    }

    /// Cypress Ultra37000 `CY37032VP44` geometry derived from `c32p44.phy` and `pld.opt`:
    /// - `*QP37*`, `*QF15034*`, `*F1*`
    /// - 2 LABs × 7501 fuses (`0..7501` and `7501..15002`), 16 macrocells/LAB (32 total)
    /// - 80 PTM product terms per LAB × 78 columns (39 PIM inputs × 2 polarities) = 6240 fuses/LAB
    /// - 5 dedicated product terms per macrocell (`16 * 5 = 80` PTs/LAB)
    /// - Global / I/O config at `15002..15034`
    pub fn cy37032() -> Self {
        const LAB_STRIDE: usize = 7501;
        const PTS_PER_MC: usize = 5;
        const COLS_PER_TERM: usize = 78;

        let terms_per_output = vec![PTS_PER_MC; 32];
        let mut output_base_fuse = Vec::with_capacity(32);
        for mc in 0..32 {
            let lab = mc / 16;
            let local_mc = mc % 16;
            output_base_fuse.push(lab * LAB_STRIDE + local_mc * PTS_PER_MC * COLS_PER_TERM);
        }

        Self {
            target: TargetDevice::Cy37032,
            name: "CY37032VP44".to_string(),
            pins: 37,
            package_pins: 44,
            max_inputs: 37,
            max_outputs: 32,
            total_fuses: 15034,
            default_fuse: true,
            cols_per_term: COLS_PER_TERM,
            terms_per_output,
            output_base_fuse,
            config_base_fuse: 6978, // LAB 1 macrocell config base (LAB 2 = +7501)
        }
    }

    /// Map a physical package pin number (1-based) to an AND-array input column (0-based).
    pub fn pin_to_input_col(&self, pin: usize) -> Option<usize> {
        match self.target {
            TargetDevice::Gal16V8 => {
                let col = match pin {
                    2..=9 => Some(pin - 2),
                    1 => Some(8),
                    11 => Some(9),
                    19 => Some(10),
                    18 => Some(11),
                    17 => Some(12),
                    14 => Some(13),
                    13 => Some(14),
                    12 => Some(15),
                    _ => None,
                }?;
                (col < self.max_inputs).then_some(col)
            }
            TargetDevice::Gal22V10 => {
                let col = match pin {
                    1..=11 => Some(pin - 1),
                    13 => Some(11),
                    14..=23 => Some(12 + (23 - pin)),
                    _ => None,
                }?;
                (col < self.max_inputs).then_some(col)
            }
            TargetDevice::Cy37032 => match pin {
                2..=9 => Some(pin - 2),
                14..=21 => Some(8 + (pin - 14)),
                24..=31 => Some(16 + (pin - 24)),
                36..=43 => Some(24 + (pin - 36)),
                10 => Some(32),
                13 => Some(33),
                32 => Some(34),
                33 => Some(35),
                35 => Some(36),
                _ => None,
            },
        }
    }

    /// Map a physical package pin number (1-based) to an output macrocell index (0-based).
    pub fn pin_to_output_olmc(&self, pin: usize) -> Option<usize> {
        match self.target {
            TargetDevice::Gal16V8 => {
                if (12..=19).contains(&pin) {
                    let olmc = 19 - pin;
                    (olmc < self.max_outputs).then_some(olmc)
                } else {
                    None
                }
            }
            TargetDevice::Gal22V10 => {
                if (14..=23).contains(&pin) {
                    let olmc = 23 - pin;
                    (olmc < self.max_outputs).then_some(olmc)
                } else {
                    None
                }
            }
            TargetDevice::Cy37032 => match pin {
                2..=9 => Some(pin - 2),
                14..=21 => Some(8 + (pin - 14)),
                24..=31 => Some(16 + (pin - 24)),
                36..=43 => Some(24 + (pin - 36)),
                _ => None,
            },
        }
    }

    /// Map a 0-based `Cy37032` AND-array input column to `(pim_channel, mux_bit)`
    /// in the LAB PIM interconnect array (`L7149` / `L14650`).
    ///
    /// Verified against `c37kfit.exe` + `test.jed`:
    /// - Input col 32 (PLCC-44 Pin 10 / Logical 33) -> PIM channel 12, mux bit 1 (`101111111`)
    /// - Input col 33 (PLCC-44 Pin 13 / Logical 34) -> PIM channel 4, mux bit 3 (`111011111`)
    pub fn input_col_to_pim(&self, col: usize) -> (usize, usize) {
        match col {
            32 => (12, 1),
            33 => (4, 3),
            _ => (col % 39, col % 8),
        }
    }
}
