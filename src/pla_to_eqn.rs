//! Convert a (minimized) PLA truth table into human-readable Boolean equations.
//!
//! Pure Rust implementation compatible with `wasm32-unknown-unknown`.

use crate::cube::Part;
use crate::pla::{Pla, PlaError};

/// Convert PLA text into one Boolean equation per output signal, e.g.:
/// `y = (a & !b) | c;`
/// `q.d = !rst & d;`
pub fn pla_to_eqn(pla_text: &str) -> Result<String, PlaError> {
    let pla = Pla::parse(pla_text)?;

    let in_names: Vec<String> = (0..pla.nin)
        .map(|i| {
            pla.input_labels
                .as_ref()
                .and_then(|v| v.get(i))
                .cloned()
                .unwrap_or_else(|| format!("in{i}"))
        })
        .collect();

    let out_names: Vec<String> = (0..pla.nout)
        .map(|o| {
            pla.output_labels
                .as_ref()
                .and_then(|v| v.get(o))
                .cloned()
                .unwrap_or_else(|| format!("out{o}"))
        })
        .collect();

    let mut lines = Vec::with_capacity(pla.nout);

    for (out_idx, out_name) in out_names.iter().enumerate() {
        let mut terms: Vec<Vec<String>> = Vec::new();
        for cube in pla.on.iter() {
            if !cube.out_get(out_idx) {
                continue;
            }
            let inp = cube.input();
            let mut lits = Vec::new();
            for (var_idx, var_name) in in_names.iter().enumerate() {
                match inp.get(var_idx) {
                    Part::One => lits.push(var_name.clone()),
                    Part::Zero => lits.push(format!("!{var_name}")),
                    Part::DontCare | Part::Empty => {}
                }
            }
            terms.push(lits);
        }

        let rhs = if terms.is_empty() {
            "0".to_string()
        } else {
            let multi_term = terms.len() > 1;
            let formatted_terms: Vec<String> = terms
                .into_iter()
                .map(|lits| {
                    if lits.is_empty() {
                        "1".to_string()
                    } else if lits.len() == 1 {
                        lits.into_iter().next().unwrap()
                    } else {
                        let joined = lits.join(" & ");
                        if multi_term {
                            format!("({joined})")
                        } else {
                            joined
                        }
                    }
                })
                .collect();
            formatted_terms.join(" | ")
        };

        lines.push(format!("{out_name} = {rhs};"));
    }

    Ok(lines.join("\n"))
}

#[cfg(test)]
mod tests {
    use super::pla_to_eqn;

    #[test]
    fn formats_sop_and_sequential_next_state_equations() {
        let pla = "\
.i 3
.o 2
.ilb en rst d
.ob q.d y
.p 3
001 10
1-0 01
-11 01
.e
";
        let eqn = pla_to_eqn(pla).unwrap();
        assert_eq!(
            eqn,
            "q.d = !en & !rst & d;\ny = (en & !d) | (rst & d);"
        );
    }

    #[test]
    fn formats_constants_zero_and_one() {
        let pla = "\
.i 2
.o 2
.ilb a b
.ob z o
.p 1
-- 01
.e
";
        let eqn = pla_to_eqn(pla).unwrap();
        assert_eq!(eqn, "z = 0;\no = 1;");
    }
}
