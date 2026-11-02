//! Positional-cube representation of a product term.
//!
//! Each binary variable uses 2 bits, matching Espresso's `set` encoding:
//!
//! | bits | meaning                              |
//! |------|--------------------------------------|
//! | `01` | variable complemented (value 0)      |
//! | `10` | variable asserted (value 1)          |
//! | `11` | don't care (variable absent)         |
//! | `00` | empty part (cube is contradictory)   |
//!
//! 16 variables are packed in each `u32` word (variable `i` lives in word
//! `i / 16`, bits `2*(i%16)` and `2*(i%16)+1`). Unused padding bits of the last
//! word are always kept at `1`, so that they never look "empty".

use core::fmt;

/// Variables stored per 32-bit word.
pub const VARS_PER_WORD: usize = 16;
/// Selects the low bit of every 2-bit field.
const LOW_MASK: u32 = 0x5555_5555;

/// State of one variable inside a cube.
#[derive(Clone, Copy, PartialEq, Eq, PartialOrd, Ord, Debug, Hash)]
pub enum Part {
    Empty = 0,
    Zero = 1,
    One = 2,
    DontCare = 3,
}

impl Part {
    fn from_bits(b: u32) -> Part {
        match b & 3 {
            0 => Part::Empty,
            1 => Part::Zero,
            2 => Part::One,
            _ => Part::DontCare,
        }
    }
}

/// Error produced when parsing a textual cube.
#[derive(Clone, Debug, PartialEq, Eq)]
pub enum ParseError {
    /// The cube text does not have the expected number of variables.
    BadLength { expected: usize, found: usize },
    /// A character other than `0`, `1` or `-` was found.
    BadChar(char),
}

impl fmt::Display for ParseError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            ParseError::BadLength { expected, found } => {
                write!(f, "cube has {found} variables, expected {expected}")
            }
            ParseError::BadChar(c) => write!(f, "invalid cube character {c:?}"),
        }
    }
}

impl std::error::Error for ParseError {}

/// A product term over `nvars` binary variables.
#[derive(Clone, PartialEq, Eq, PartialOrd, Ord, Hash, Debug)]
pub struct Cube {
    nvars: usize,
    words: Vec<u32>,
}

/// Number of words needed for `nvars` variables (at least one).
fn words_for(nvars: usize) -> usize {
    ((nvars + VARS_PER_WORD - 1) / VARS_PER_WORD).max(1)
}

impl Cube {
    /// The universe cube (all variables don't-care).
    pub fn universe(nvars: usize) -> Cube {
        Cube { nvars, words: vec![u32::MAX; words_for(nvars)] }
    }

    /// Cube with a single literal `part` on `var`, don't-care elsewhere.
    pub fn literal(nvars: usize, var: usize, part: Part) -> Cube {
        let mut c = Cube::universe(nvars);
        c.set(var, part);
        c
    }

    /// Minterm cube; variable 0 is the most significant bit of `m`.
    pub fn from_minterm(nvars: usize, m: u64) -> Cube {
        let mut c = Cube::universe(nvars);
        for i in 0..nvars {
            let bit = (m >> (nvars - 1 - i)) & 1;
            c.set(i, if bit == 1 { Part::One } else { Part::Zero });
        }
        c
    }

    /// Parse a cube such as `"01-1"` for a function of `nvars` variables.
    pub fn parse(nvars: usize, s: &str) -> Result<Cube, ParseError> {
        let found = s.chars().count();
        if found != nvars {
            return Err(ParseError::BadLength { expected: nvars, found });
        }
        let mut c = Cube::universe(nvars);
        for (i, ch) in s.chars().enumerate() {
            let p = match ch {
                '0' => Part::Zero,
                '1' => Part::One,
                '-' => Part::DontCare,
                other => return Err(ParseError::BadChar(other)),
            };
            c.set(i, p);
        }
        Ok(c)
    }

    /// Number of variables.
    pub fn nvars(&self) -> usize {
        self.nvars
    }

    /// Raw bit words.
    pub fn words(&self) -> &[u32] {
        &self.words
    }

    /// Read the state of variable `var`.
    pub fn get(&self, var: usize) -> Part {
        debug_assert!(var < self.nvars);
        let shift = 2 * (var % VARS_PER_WORD);
        Part::from_bits(self.words[var / VARS_PER_WORD] >> shift)
    }

    /// Write the state of variable `var`.
    pub fn set(&mut self, var: usize, part: Part) {
        debug_assert!(var < self.nvars);
        let shift = 2 * (var % VARS_PER_WORD);
        let w = &mut self.words[var / VARS_PER_WORD];
        *w = (*w & !(3u32 << shift)) | ((part as u32) << shift);
    }

    /// True if some variable has an empty (`00`) part.
    pub fn is_empty(&self) -> bool {
        self.words.iter().any(|&w| ((w | (w >> 1)) & LOW_MASK) != LOW_MASK)
    }

    /// True if every variable is don't-care.
    pub fn is_universe(&self) -> bool {
        self.words.iter().all(|&w| w == u32::MAX)
    }

    /// Number of literals (variables that are `01` or `10`).
    pub fn literals(&self) -> usize {
        self.words
            .iter()
            .map(|&w| ((w ^ (w >> 1)) & LOW_MASK).count_ones() as usize)
            .sum()
    }

    /// Smallest cube containing both `self` and `other` (bitwise OR).
    pub fn supercube(&self, other: &Cube) -> Cube {
        debug_assert_eq!(self.nvars, other.nvars);
        Cube {
            nvars: self.nvars,
            words: self.words.iter().zip(&other.words).map(|(a, b)| a | b).collect(),
        }
    }

    /// Cofactor of `self` with respect to `c`: `None` if they are disjoint,
    /// otherwise `self | !c`.
    pub fn cofactor(&self, c: &Cube) -> Option<Cube> {
        if cube_distance(self, c) > 0 {
            return None;
        }
        Some(Cube {
            nvars: self.nvars,
            words: self.words.iter().zip(&c.words).map(|(a, b)| a | !b).collect(),
        })
    }

    /// Complement of a single cube as a list of cubes (De Morgan).
    pub fn complement(&self) -> Vec<Cube> {
        let mut out = Vec::new();
        for v in 0..self.nvars {
            let flipped = match self.get(v) {
                Part::Zero => Part::One,
                Part::One => Part::Zero,
                _ => continue,
            };
            out.push(Cube::literal(self.nvars, v, flipped));
        }
        out
    }

    /// True if the (completely specified) minterm `m` lies inside this cube.
    pub fn contains_minterm(&self, m: u64) -> bool {
        cube_contains(self, &Cube::from_minterm(self.nvars, m))
    }
}

impl fmt::Display for Cube {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        for v in 0..self.nvars {
            let ch = match self.get(v) {
                Part::Zero => '0',
                Part::One => '1',
                Part::DontCare => '-',
                Part::Empty => '?',
            };
            write!(f, "{ch}")?;
        }
        Ok(())
    }
}

/// Intersection of two cubes (bitwise AND). May be empty; check [`Cube::is_empty`].
pub fn cube_intersect(a: &Cube, b: &Cube) -> Cube {
    debug_assert_eq!(a.nvars, b.nvars);
    Cube {
        nvars: a.nvars,
        words: a.words.iter().zip(&b.words).map(|(x, y)| x & y).collect(),
    }
}

/// Distance between two cubes: number of variables whose intersection is empty.
pub fn cube_distance(a: &Cube, b: &Cube) -> usize {
    debug_assert_eq!(a.nvars, b.nvars);
    a.words
        .iter()
        .zip(&b.words)
        .map(|(x, y)| {
            let t = x & y;
            (!(t | (t >> 1)) & LOW_MASK).count_ones() as usize
        })
        .sum()
}

/// Containment / subsumption: true if `a` contains `b` (`b ⊆ a`).
pub fn cube_contains(a: &Cube, b: &Cube) -> bool {
    debug_assert_eq!(a.nvars, b.nvars);
    a.words.iter().zip(&b.words).all(|(x, y)| y & !x == 0)
}

/// Outputs stored per 32-bit word in [`MvCube`].
pub const OUTS_PER_WORD: usize = 32;

fn out_words_for(nout: usize) -> usize {
    (nout + OUTS_PER_WORD - 1) / OUTS_PER_WORD
}

fn last_out_mask(nout: usize) -> u32 {
    let rem = nout % OUTS_PER_WORD;
    if rem == 0 {
        u32::MAX
    } else {
        (1u32 << rem) - 1
    }
}

fn full_out_words(nout: usize) -> Vec<u32> {
    let nw = out_words_for(nout);
    if nw == 0 {
        return Vec::new();
    }
    let mut w = vec![u32::MAX; nw];
    w[nw - 1] = last_out_mask(nout);
    w
}

/// Multi-output product term: `nin` binary input variables (`Cube`) plus a
/// single `nout`-valued output part (1 bit per output, matching Espresso's MV
/// representation of multi-output PLAs).
#[derive(Clone, PartialEq, Eq, PartialOrd, Ord, Hash, Debug)]
pub struct MvCube {
    input: Cube,
    nout: usize,
    out_words: Vec<u32>,
}

impl MvCube {
    /// Universe cube: all inputs don't-care and all `nout` outputs active.
    pub fn universe(nin: usize, nout: usize) -> MvCube {
        MvCube {
            input: Cube::universe(nin),
            nout,
            out_words: full_out_words(nout),
        }
    }

    /// Cube with given `input` and all outputs initially `0` (inactive).
    pub fn empty_outputs(input: Cube, nout: usize) -> MvCube {
        MvCube {
            input,
            nout,
            out_words: vec![0u32; out_words_for(nout)],
        }
    }

    /// Cube with given `input` and only `out` active.
    pub fn single_output(input: Cube, nout: usize, out: usize) -> MvCube {
        let mut c = MvCube::empty_outputs(input, nout);
        c.out_set(out, true);
        c
    }

    /// Cube with given `input` and the listed `active_outputs` set to `1`.
    pub fn from_parts(input: Cube, nout: usize, active_outputs: &[usize]) -> MvCube {
        let mut c = MvCube::empty_outputs(input, nout);
        for &o in active_outputs {
            c.out_set(o, true);
        }
        c
    }

    /// Parse input (`0`/`1`/`-`) and output (`0`/`1`/`~`) strings.
    pub fn parse(
        nin: usize,
        nout: usize,
        input_str: &str,
        output_str: &str,
    ) -> Result<MvCube, ParseError> {
        let input = Cube::parse(nin, input_str)?;
        let found = output_str.chars().count();
        if found != nout {
            return Err(ParseError::BadLength { expected: nout, found });
        }
        let mut c = MvCube::empty_outputs(input, nout);
        for (k, ch) in output_str.chars().enumerate() {
            match ch {
                '1' => c.out_set(k, true),
                '0' | '~' => {}
                other => return Err(ParseError::BadChar(other)),
            }
        }
        Ok(c)
    }

    /// Number of binary input variables.
    pub fn nin(&self) -> usize {
        self.input.nvars()
    }

    /// Number of binary outputs.
    pub fn nout(&self) -> usize {
        self.nout
    }

    /// Borrow the binary input cube.
    pub fn input(&self) -> &Cube {
        &self.input
    }

    /// Mutably borrow the binary input cube.
    pub fn input_mut(&mut self) -> &mut Cube {
        &mut self.input
    }

    /// Raw output bitmask words.
    pub fn out_words(&self) -> &[u32] {
        &self.out_words
    }

    /// Read whether output `out` is asserted (`1`).
    pub fn out_get(&self, out: usize) -> bool {
        debug_assert!(out < self.nout);
        let w = self.out_words[out / OUTS_PER_WORD];
        ((w >> (out % OUTS_PER_WORD)) & 1) != 0
    }

    /// Set whether output `out` is asserted (`1`) or inactive (`0`).
    pub fn out_set(&mut self, out: usize, val: bool) {
        debug_assert!(out < self.nout);
        let bit = 1u32 << (out % OUTS_PER_WORD);
        let w = &mut self.out_words[out / OUTS_PER_WORD];
        if val {
            *w |= bit;
        } else {
            *w &= !bit;
        }
    }

    /// Bitwise OR the outputs of `other` into `self`.
    pub fn out_or_assign(&mut self, other: &MvCube) {
        debug_assert_eq!(self.nout, other.nout);
        for (a, b) in self.out_words.iter_mut().zip(&other.out_words) {
            *a |= *b;
        }
    }

    /// True if at least one output bit is `1`.
    pub fn has_any_output(&self) -> bool {
        self.out_words.iter().any(|&w| w != 0)
    }

    /// True if every output `0..nout` is `1` (requires `nout > 0`).
    pub fn has_all_outputs(&self) -> bool {
        let nw = self.out_words.len();
        if nw == 0 {
            return false;
        }
        self.out_words[..nw - 1].iter().all(|&w| w == u32::MAX)
            && self.out_words[nw - 1] == last_out_mask(self.nout)
    }

    /// True if the input part has a contradictory (`00`) variable or no output is active.
    pub fn is_empty(&self) -> bool {
        self.nout == 0 || self.input.is_empty() || !self.has_any_output()
    }

    /// True if all inputs are don't-care and all `nout` outputs are active.
    pub fn is_universe(&self) -> bool {
        self.input.is_universe() && self.has_all_outputs()
    }

    /// Number of binary input literals (`0` or `1` in the AND-plane).
    pub fn input_literals(&self) -> usize {
        self.input.literals()
    }

    /// Number of active outputs (`1`s in the OR-plane).
    pub fn output_ones(&self) -> usize {
        self.out_words.iter().map(|w| w.count_ones() as usize).sum()
    }

    /// Format `(input_string, output_string)` for PLA output.
    pub fn to_pla_strings(&self) -> (String, String) {
        let mut out_s = String::with_capacity(self.nout);
        for k in 0..self.nout {
            out_s.push(if self.out_get(k) { '1' } else { '0' });
        }
        (self.input.to_string(), out_s)
    }

    /// Smallest MV cube containing both `self` and `other`.
    pub fn supercube(&self, other: &MvCube) -> MvCube {
        debug_assert_eq!(self.nout, other.nout);
        MvCube {
            input: self.input.supercube(&other.input),
            nout: self.nout,
            out_words: self
                .out_words
                .iter()
                .zip(&other.out_words)
                .map(|(a, b)| a | b)
                .collect(),
        }
    }

    /// MV cofactor of `self` with respect to `c`: `None` if disjoint, else
    /// `(self.input | !c.input, (self.out | !c.out) & mask)`.
    pub fn cofactor(&self, c: &MvCube) -> Option<MvCube> {
        if mv_cube_distance(self, c) > 0 {
            return None;
        }
        let input = self.input.cofactor(&c.input)?;
        let nw = self.out_words.len();
        let mut out_words: Vec<u32> = self
            .out_words
            .iter()
            .zip(&c.out_words)
            .map(|(a, b)| a | !b)
            .collect();
        if nw > 0 {
            out_words[nw - 1] &= last_out_mask(self.nout);
        }
        Some(MvCube { input, nout: self.nout, out_words })
    }

    /// Complement of a single MV cube as a list of MV cubes (De Morgan).
    pub fn complement(&self) -> Vec<MvCube> {
        if self.nout == 0 {
            return Vec::new();
        }
        if self.is_empty() {
            return vec![MvCube::universe(self.nin(), self.nout)];
        }
        let mut res = Vec::new();
        if !self.has_all_outputs() {
            let nw = self.out_words.len();
            let mut inv_out: Vec<u32> = self.out_words.iter().map(|w| !w).collect();
            inv_out[nw - 1] &= last_out_mask(self.nout);
            res.push(MvCube {
                input: Cube::universe(self.nin()),
                nout: self.nout,
                out_words: inv_out,
            });
        }
        let all_out = full_out_words(self.nout);
        for lit in self.input.complement() {
            res.push(MvCube {
                input: lit,
                nout: self.nout,
                out_words: all_out.clone(),
            });
        }
        res
    }
}

impl fmt::Display for MvCube {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{} ", self.input)?;
        for k in 0..self.nout {
            write!(f, "{}", if self.out_get(k) { '1' } else { '0' })?;
        }
        Ok(())
    }
}

/// Intersection of two MV cubes. Check [`MvCube::is_empty`] on the result.
pub fn mv_cube_intersect(a: &MvCube, b: &MvCube) -> MvCube {
    debug_assert_eq!(a.nout, b.nout);
    MvCube {
        input: cube_intersect(&a.input, &b.input),
        nout: a.nout,
        out_words: a
            .out_words
            .iter()
            .zip(&b.out_words)
            .map(|(x, y)| x & y)
            .collect(),
    }
}

/// MV distance between two cubes: number of disjoint binary input variables
/// plus `1` if their output masks are disjoint.
pub fn mv_cube_distance(a: &MvCube, b: &MvCube) -> usize {
    debug_assert_eq!(a.nout, b.nout);
    let out_disjoint = a.out_words.iter().zip(&b.out_words).all(|(x, y)| (x & y) == 0);
    cube_distance(&a.input, &b.input) + usize::from(out_disjoint)
}

/// MV containment: true if `a` contains `b` (`b ⊆ a`).
pub fn mv_cube_contains(a: &MvCube, b: &MvCube) -> bool {
    debug_assert_eq!(a.nout, b.nout);
    if b.is_empty() {
        return true;
    }
    if a.is_empty() {
        return false;
    }
    cube_contains(&a.input, &b.input)
        && a.out_words.iter().zip(&b.out_words).all(|(x, y)| y & !x == 0)
}

#[cfg(test)]
mod tests {
    use super::*;

    fn c(s: &str) -> Cube {
        Cube::parse(s.len(), s).unwrap()
    }

    #[test]
    fn roundtrip_and_encoding() {
        let x = c("01-1");
        assert_eq!(x.to_string(), "01-1");
        assert_eq!(x.get(0), Part::Zero);
        assert_eq!(x.get(1), Part::One);
        assert_eq!(x.get(2), Part::DontCare);
        assert_eq!(x.literals(), 3);
        assert!(Cube::parse(3, "01").is_err());
        assert!(Cube::parse(2, "0x").is_err());
    }

    #[test]
    fn intersect_distance_contains() {
        assert_eq!(cube_intersect(&c("1-0"), &c("-10")).to_string(), "110");
        assert!(cube_intersect(&c("1--"), &c("0--")).is_empty());
        assert_eq!(cube_distance(&c("10-"), &c("01-")), 2);
        assert_eq!(cube_distance(&c("1--"), &c("-0-")), 0);
        assert!(cube_contains(&c("1--"), &c("10-")));
        assert!(!cube_contains(&c("10-"), &c("1--")));
    }

    #[test]
    fn works_across_word_boundaries() {
        let n = 40;
        let mut a = Cube::universe(n);
        let mut b = Cube::universe(n);
        a.set(35, Part::One);
        b.set(35, Part::Zero);
        assert_eq!(cube_distance(&a, &b), 1);
        assert_eq!(a.literals(), 1);
        assert!(cube_contains(&Cube::universe(n), &a));
    }

    #[test]
    fn minterm_and_complement() {
        let m = Cube::from_minterm(3, 0b101);
        assert_eq!(m.to_string(), "101");
        assert_eq!(c("10-").complement().len(), 2);
    }

    #[test]
    fn mv_cube_algebra_and_word_boundaries() {
        let a = MvCube::parse(3, 2, "1-0", "11").unwrap();
        let b = MvCube::parse(3, 2, "-10", "01").unwrap();
        let inter = mv_cube_intersect(&a, &b);
        assert_eq!(inter.to_string(), "110 01");
        assert_eq!(mv_cube_distance(&a, &b), 0);
        assert!(mv_cube_contains(&a, &MvCube::parse(3, 2, "110", "01").unwrap()));
        assert!(!mv_cube_contains(&b, &a));

        let d = MvCube::parse(3, 2, "1-0", "10").unwrap();
        assert_eq!(mv_cube_distance(&b, &d), 1); // disjoint outputs only
        assert!(mv_cube_intersect(&b, &d).is_empty());

        // Cofactor and single-cube complement.
        let cof = a.cofactor(&MvCube::parse(3, 2, "110", "10").unwrap()).unwrap();
        assert!(cof.is_universe());
        let comp = d.complement();
        for m in 0..8u64 {
            let mc = Cube::from_minterm(3, m);
            for k in 0..2 {
                let pt = MvCube::single_output(mc.clone(), 2, k);
                let in_d = mv_cube_contains(&d, &pt);
                let in_comp = comp.iter().any(|cc| mv_cube_contains(cc, &pt));
                assert_ne!(in_d, in_comp);
            }
        }

        // Across 32-output word boundary.
        let mut wide = MvCube::empty_outputs(Cube::universe(4), 40);
        wide.out_set(0, true);
        wide.out_set(35, true);
        assert_eq!(wide.output_ones(), 2);
        assert!(!wide.has_all_outputs());
        assert!(MvCube::universe(4, 40).is_universe());
    }
}
