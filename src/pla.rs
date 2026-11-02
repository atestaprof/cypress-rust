//! Parser, representation, and formatter for Berkeley Espresso `.pla` files.
//!
//! Supports standard PLA directives (`.i`, `.o`, `.p`, `.ilb`, `.ob`,
//! `.type f|fd|fr|fdr`, `.e`/`.end`) and `#` comments, operating purely in
//! memory for full `wasm32-unknown-unknown` compatibility.

use core::fmt;
use std::str::FromStr;

use crate::cover::MvCover;
use crate::cube::{cube_distance, Cube, MvCube, Part};
use crate::espresso::minimize_mv;

/// Interpretation of the cubes in a `.pla` file (`.type` directive).
#[derive(Clone, Copy, Debug, PartialEq, Eq, Default)]
pub enum PlaType {
    /// ON-set only (`.type f`).
    F,
    /// ON-set and don't-care set (`.type fd`, Berkeley Espresso default).
    #[default]
    Fd,
    /// ON-set and OFF-set (`.type fr`; unspecified points are don't-cares).
    Fr,
    /// ON-set, don't-care set, and OFF-set (`.type fdr`).
    Fdr,
}

impl PlaType {
    pub fn as_str(self) -> &'static str {
        match self {
            PlaType::F => "f",
            PlaType::Fd => "fd",
            PlaType::Fr => "fr",
            PlaType::Fdr => "fdr",
        }
    }
}

/// Errors returned when parsing a `.pla` description.
#[derive(Clone, Debug, PartialEq, Eq)]
pub enum PlaError {
    /// Missing `.i <nin>` directive.
    MissingInputs,
    /// Missing `.o <nout>` directive.
    MissingOutputs,
    /// A header directive appeared more than once.
    DuplicateDirective { line: usize, directive: String },
    /// Unrecognized `.directive`.
    UnknownDirective { line: usize, directive: String },
    /// Invalid integer argument to `.i`, `.o`, or `.p`.
    InvalidNumber { line: usize, directive: String, value: String },
    /// Unrecognized `.type` value (expected `f`, `fd`, `fr`, or `fdr`).
    UnknownType { line: usize, value: String },
    /// Number of labels in `.ilb` or `.ob` does not match `.i` or `.o`.
    BadLabelCount { line: usize, directive: String, expected: usize, found: usize },
    /// A product-term line appeared before `.i` and `.o` were specified.
    CubeBeforeDimensions { line: usize },
    /// A product-term line does not have `nin + nout` symbols.
    BadCubeLength { line: usize, expected: usize, found: usize },
    /// Invalid symbol in the binary input part of a cube.
    BadInputChar { line: usize, ch: char },
    /// Invalid symbol in the output part of a cube.
    BadOutputChar { line: usize, ch: char },
    /// ON-set and OFF-set intersect on `output` in `.type fr` or `.type fdr`.
    ConflictingOnOff { output: usize },
}

impl fmt::Display for PlaError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            PlaError::MissingInputs => write!(f, "missing .i directive in PLA"),
            PlaError::MissingOutputs => write!(f, "missing .o directive in PLA"),
            PlaError::DuplicateDirective { line, directive } => {
                write!(f, "line {line}: duplicate {directive} directive")
            }
            PlaError::UnknownDirective { line, directive } => {
                write!(f, "line {line}: unknown PLA directive {directive:?}")
            }
            PlaError::InvalidNumber { line, directive, value } => {
                write!(f, "line {line}: invalid number {value:?} for {directive}")
            }
            PlaError::UnknownType { line, value } => {
                write!(f, "line {line}: unsupported PLA .type {value:?}")
            }
            PlaError::BadLabelCount { line, directive, expected, found } => {
                write!(f, "line {line}: {directive} has {found} labels, expected {expected}")
            }
            PlaError::CubeBeforeDimensions { line } => {
                write!(f, "line {line}: cube row before .i and .o directives")
            }
            PlaError::BadCubeLength { line, expected, found } => {
                write!(f, "line {line}: cube has {found} symbols, expected {expected}")
            }
            PlaError::BadInputChar { line, ch } => {
                write!(f, "line {line}: invalid PLA input character {ch:?}")
            }
            PlaError::BadOutputChar { line, ch } => {
                write!(f, "line {line}: invalid PLA output character {ch:?}")
            }
            PlaError::ConflictingOnOff { output } => {
                write!(f, "ON-set and OFF-set overlap on output {output}")
            }
        }
    }
}

impl std::error::Error for PlaError {}

/// Parsed two-level Programmable Logic Array (`.pla`).
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct Pla {
    pub nin: usize,
    pub nout: usize,
    pub pla_type: PlaType,
    pub input_labels: Option<Vec<String>>,
    pub output_labels: Option<Vec<String>>,
    pub on: MvCover,
    pub dc: MvCover,
}

fn parse_single_usize<'a>(
    line: usize,
    directive: &str,
    mut toks: impl Iterator<Item = &'a str>,
) -> Result<usize, PlaError> {
    let val_str = toks.next().ok_or_else(|| PlaError::InvalidNumber {
        line,
        directive: directive.to_string(),
        value: String::new(),
    })?;
    if let Some(extra) = toks.next() {
        return Err(PlaError::InvalidNumber {
            line,
            directive: directive.to_string(),
            value: format!("{val_str} {extra}"),
        });
    }
    val_str.parse::<usize>().map_err(|_| PlaError::InvalidNumber {
        line,
        directive: directive.to_string(),
        value: val_str.to_string(),
    })
}

impl Pla {
    /// Empty PLA of dimensions `(nin, nout)`.
    pub fn new(nin: usize, nout: usize) -> Pla {
        Pla {
            nin,
            nout,
            pla_type: PlaType::Fd,
            input_labels: None,
            output_labels: None,
            on: MvCover::new(nin, nout),
            dc: MvCover::new(nin, nout),
        }
    }

    /// Parse a Berkeley `.pla` text representation.
    pub fn parse(src: &str) -> Result<Pla, PlaError> {
        let mut nin: Option<usize> = None;
        let mut nout: Option<usize> = None;
        let mut seen_p = false;
        let mut pla_type: Option<PlaType> = None;
        let mut raw_ilb: Option<(usize, Vec<String>)> = None;
        let mut raw_ob: Option<(usize, Vec<String>)> = None;

        let mut f_cubes: Vec<MvCube> = Vec::new();
        let mut d_cubes: Vec<MvCube> = Vec::new();
        let mut r_cubes: Vec<MvCube> = Vec::new();

        for (idx, raw_line) in src.lines().enumerate() {
            let line_no = idx + 1;
            let line = raw_line.split('#').next().unwrap_or("").trim();
            if line.is_empty() {
                continue;
            }

            if line.starts_with('.') {
                let mut toks = line.split_whitespace();
                let dir = toks.next().unwrap();
                match dir {
                    ".i" => {
                        if nin.is_some() {
                            return Err(PlaError::DuplicateDirective {
                                line: line_no,
                                directive: ".i".to_string(),
                            });
                        }
                        nin = Some(parse_single_usize(line_no, ".i", toks)?);
                    }
                    ".o" => {
                        if nout.is_some() {
                            return Err(PlaError::DuplicateDirective {
                                line: line_no,
                                directive: ".o".to_string(),
                            });
                        }
                        nout = Some(parse_single_usize(line_no, ".o", toks)?);
                    }
                    ".p" => {
                        if seen_p {
                            return Err(PlaError::DuplicateDirective {
                                line: line_no,
                                directive: ".p".to_string(),
                            });
                        }
                        let _ = parse_single_usize(line_no, ".p", toks)?;
                        seen_p = true;
                    }
                    ".ilb" => {
                        if raw_ilb.is_some() {
                            return Err(PlaError::DuplicateDirective {
                                line: line_no,
                                directive: ".ilb".to_string(),
                            });
                        }
                        raw_ilb = Some((line_no, toks.map(str::to_string).collect()));
                    }
                    ".ob" => {
                        if raw_ob.is_some() {
                            return Err(PlaError::DuplicateDirective {
                                line: line_no,
                                directive: ".ob".to_string(),
                            });
                        }
                        raw_ob = Some((line_no, toks.map(str::to_string).collect()));
                    }
                    ".type" => {
                        if pla_type.is_some() {
                            return Err(PlaError::DuplicateDirective {
                                line: line_no,
                                directive: ".type".to_string(),
                            });
                        }
                        let val = toks.next().unwrap_or("");
                        if toks.next().is_some() {
                            return Err(PlaError::UnknownType {
                                line: line_no,
                                value: line.to_string(),
                            });
                        }
                        let t = match val {
                            "f" => PlaType::F,
                            "fd" => PlaType::Fd,
                            "fr" => PlaType::Fr,
                            "fdr" => PlaType::Fdr,
                            other => {
                                return Err(PlaError::UnknownType {
                                    line: line_no,
                                    value: other.to_string(),
                                });
                            }
                        };
                        pla_type = Some(t);
                    }
                    ".e" | ".end" => break,
                    other => {
                        return Err(PlaError::UnknownDirective {
                            line: line_no,
                            directive: other.to_string(),
                        });
                    }
                }
                continue;
            }

            let ( Some(n_in), Some(n_out) ) = (nin, nout) else {
                return Err(PlaError::CubeBeforeDimensions { line: line_no });
            };

            let chars: Vec<char> = line
                .chars()
                .filter(|ch| !ch.is_ascii_whitespace() && *ch != '|')
                .collect();
            if chars.len() != n_in + n_out {
                return Err(PlaError::BadCubeLength {
                    line: line_no,
                    expected: n_in + n_out,
                    found: chars.len(),
                });
            }

            let mut input = Cube::universe(n_in);
            for (v, &ch) in chars[..n_in].iter().enumerate() {
                let p = match ch {
                    '0' => Part::Zero,
                    '1' => Part::One,
                    '-' | '2' => Part::DontCare,
                    other => return Err(PlaError::BadInputChar { line: line_no, ch: other }),
                };
                input.set(v, p);
            }

            let mut fc = MvCube::empty_outputs(input.clone(), n_out);
            let mut dc = MvCube::empty_outputs(input.clone(), n_out);
            let mut rc = MvCube::empty_outputs(input, n_out);

            for (k, &ch) in chars[n_in..].iter().enumerate() {
                match ch {
                    '1' | '4' => fc.out_set(k, true),
                    '-' | '2' => dc.out_set(k, true),
                    '0' => rc.out_set(k, true),
                    '~' | '3' => {}
                    other => return Err(PlaError::BadOutputChar { line: line_no, ch: other }),
                }
            }

            if fc.has_any_output() {
                f_cubes.push(fc);
            }
            if dc.has_any_output() {
                d_cubes.push(dc);
            }
            if rc.has_any_output() {
                r_cubes.push(rc);
            }
        }

        let n_in = nin.ok_or(PlaError::MissingInputs)?;
        let n_out = nout.ok_or(PlaError::MissingOutputs)?;

        let input_labels = match raw_ilb {
            Some((lno, labels)) => {
                if labels.len() != n_in {
                    return Err(PlaError::BadLabelCount {
                        line: lno,
                        directive: ".ilb".to_string(),
                        expected: n_in,
                        found: labels.len(),
                    });
                }
                Some(labels)
            }
            None => None,
        };

        let output_labels = match raw_ob {
            Some((lno, labels)) => {
                if labels.len() != n_out {
                    return Err(PlaError::BadLabelCount {
                        line: lno,
                        directive: ".ob".to_string(),
                        expected: n_out,
                        found: labels.len(),
                    });
                }
                Some(labels)
            }
            None => None,
        };

        let resolved_type = pla_type.unwrap_or_default();
        let mut on = MvCover::from_cubes(n_in, n_out, f_cubes);
        on.single_cube_containment();

        let dc = match resolved_type {
            PlaType::F => MvCover::new(n_in, n_out),
            PlaType::Fd => {
                let mut d = MvCover::from_cubes(n_in, n_out, d_cubes);
                d.single_cube_containment();
                d.subtract(&on)
            }
            PlaType::Fr => {
                let mut r = MvCover::from_cubes(n_in, n_out, r_cubes);
                r.single_cube_containment();
                check_disjoint_on_off(&on, &r)?;
                let mut fr = on.clone();
                fr.extend(&r);
                fr.complement()
            }
            PlaType::Fdr => {
                let mut r = MvCover::from_cubes(n_in, n_out, r_cubes);
                r.single_cube_containment();
                check_disjoint_on_off(&on, &r)?;
                let mut d = MvCover::from_cubes(n_in, n_out, d_cubes);
                d.single_cube_containment();
                d.subtract(&on).subtract(&r)
            }
        };

        Ok(Pla {
            nin: n_in,
            nout: n_out,
            pla_type: resolved_type,
            input_labels,
            output_labels,
            on,
            dc,
        })
    }

    /// Run joint multi-output Espresso minimization and return the minimized PLA
    /// (as an ON-cover `.type f` with empty don't-care set).
    pub fn minimize(&self) -> Pla {
        let min_on = minimize_mv(&self.on, &self.dc);
        Pla {
            nin: self.nin,
            nout: self.nout,
            pla_type: PlaType::F,
            input_labels: self.input_labels.clone(),
            output_labels: self.output_labels.clone(),
            on: min_on,
            dc: MvCover::new(self.nin, self.nout),
        }
    }

    /// Serialize this PLA into standard Berkeley `.pla` text format.
    pub fn to_pla_string(&self) -> String {
        self.to_string()
    }
}

fn check_disjoint_on_off(on: &MvCover, off: &MvCover) -> Result<(), PlaError> {
    for k in 0..on.nout() {
        let on_k = on.output_cover(k);
        let off_k = off.output_cover(k);
        for a in on_k.iter() {
            for b in off_k.iter() {
                if cube_distance(a, b) == 0 {
                    return Err(PlaError::ConflictingOnOff { output: k });
                }
            }
        }
    }
    Ok(())
}

impl FromStr for Pla {
    type Err = PlaError;

    fn from_str(s: &str) -> Result<Self, Self::Err> {
        Pla::parse(s)
    }
}

impl fmt::Display for Pla {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        writeln!(f, ".i {}", self.nin)?;
        writeln!(f, ".o {}", self.nout)?;
        if let Some(ilb) = &self.input_labels {
            if !ilb.is_empty() {
                writeln!(f, ".ilb {}", ilb.join(" "))?;
            }
        }
        if let Some(ob) = &self.output_labels {
            if !ob.is_empty() {
                writeln!(f, ".ob {}", ob.join(" "))?;
            }
        }
        if !self.dc.is_empty() {
            writeln!(f, ".type fd")?;
        }
        writeln!(f, ".p {}", self.on.len() + self.dc.len())?;

        for c in self.on.iter() {
            let (inp, out) = c.to_pla_strings();
            if self.nin > 0 {
                writeln!(f, "{inp} {out}")?;
            } else {
                writeln!(f, "{out}")?;
            }
        }
        for c in self.dc.iter() {
            if self.nin > 0 {
                write!(f, "{} ", c.input())?;
            }
            for k in 0..self.nout {
                write!(f, "{}", if c.out_get(k) { '-' } else { '0' })?;
            }
            writeln!(f)?;
        }
        writeln!(f, ".e")?;
        Ok(())
    }
}

/// Parse a `.pla` string, minimize all outputs jointly, and format back to `.pla`.
pub fn minimize_pla(src: &str) -> Result<String, PlaError> {
    Ok(Pla::parse(src)?.minimize().to_pla_string())
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn parse_minimize_and_roundtrip_full_adder() {
        let src = "\
# 1-bit full adder
.i 3
.o 2
.ilb a b cin
.ob sum cout
.p 8
000 00
001 10
010 10
011 01
100 10
101 01
110 01
111 11
.e
ignored trailing text
";
        let pla = Pla::parse(src).unwrap();
        assert_eq!(pla.nin, 3);
        assert_eq!(pla.nout, 2);
        assert_eq!(pla.input_labels.as_ref().unwrap(), &["a", "b", "cin"]);
        assert_eq!(pla.output_labels.as_ref().unwrap(), &["sum", "cout"]);

        let min = pla.minimize();
        let text = min.to_pla_string();
        let reparsed = Pla::parse(&text).unwrap();

        for m in 0..8u64 {
            for k in 0..2 {
                assert_eq!(pla.on.contains_minterm(k, m), reparsed.on.contains_minterm(k, m));
            }
        }
        // Full adder needs <= 7 shared product terms (111 is shared between sum and cout!).
        assert!(reparsed.on.len() <= 7, "got {} terms:\n{text}", reparsed.on.len());
    }

    #[test]
    fn pla_types_fd_fr_fdr_and_conflicts() {
        // .type fd with '2' input DC and '-' output DC
        let fd_src = "\
.i 2
.o 1
.type fd
01 1
10 1
11 -
.e
";
        let min_fd = Pla::parse(fd_src).unwrap().minimize();
        // With 11 as DC, 01 + 10 can expand to -1 + 1- (2 single-literal terms).
        assert_eq!(min_fd.on.len(), 2);
        assert_eq!(min_fd.on.input_literals(), 2);

        // .type fr: 11 is omitted, so 11 becomes DC!
        let fr_src = "\
.i 2
.o 1
.type fr
00 0
01 1
10 1
.end
";
        let min_fr = Pla::parse(fr_src).unwrap().minimize();
        assert!(min_fr.on.contains_minterm(0, 1));
        assert!(min_fr.on.contains_minterm(0, 2));
        assert!(!min_fr.on.contains_minterm(0, 0));
        assert_eq!(min_fr.on.input_literals(), 2);

        // Conflicting ON and OFF in .type fr
        let bad_fr = "\
.i 2
.o 1
.type fr
0- 1
-0 0
.e
";
        assert_eq!(Pla::parse(bad_fr), Err(PlaError::ConflictingOnOff { output: 0 }));

        // .type fdr with pipe separator and '2'/'~' symbols
        let fdr_src = "\
.i 2
.o 2
.type fdr
00 | 01
01 | 1~
12 | -0
.e
";
        let fdr = Pla::parse(fdr_src).unwrap();
        let min_fdr = fdr.minimize();
        assert!(min_fdr.on.contains_minterm(0, 1)); // 01 -> out 0 is 1
        assert!(!min_fdr.on.contains_minterm(0, 0)); // 00 -> out 0 is 0
        assert!(min_fdr.on.contains_minterm(1, 0)); // 00 -> out 1 is 1
        assert!(!min_fdr.on.contains_minterm(1, 2)); // 10 -> out 1 is 0
        assert!(!min_fdr.on.contains_minterm(1, 3)); // 11 -> out 1 is 0
    }

    #[test]
    fn pla_error_reporting() {
        assert_eq!(Pla::parse(".o 1\n.e"), Err(PlaError::MissingInputs));
        assert_eq!(Pla::parse(".i 1\n.e"), Err(PlaError::MissingOutputs));
        assert!(matches!(
            Pla::parse("01 1\n.i 2\n.o 1\n.e"),
            Err(PlaError::CubeBeforeDimensions { line: 1 })
        ));
        assert!(matches!(
            Pla::parse(".i 2\n.o 1\n.ilb a\n.e"),
            Err(PlaError::BadLabelCount { line: 3, .. })
        ));
        assert!(matches!(
            Pla::parse(".i 2\n.o 1\n011 1\n.e"),
            Err(PlaError::BadCubeLength { line: 3, expected: 3, found: 4 })
        ));
    }
}
