//! Safe Rust reimplementation of the core of Berkeley Espresso 2.3
//! (as shipped in Cypress Warp's `minopt.exe`).
//!
//! * [`cube`]     – positional-cube notation (2 bits / variable), [`MvCube`], and cube algebra.
//! * [`cover`]    – single-output ([`Cover`]) and multi-output ([`MvCover`]) covers: containment, tautology, complement.
//! * [`espresso`] – `expand` / `reduce` / `irredundant` / `make_sparse` and minimization loops.
//! * [`pla`]      – Berkeley `.pla` parser, representation ([`Pla`]), and formatter.
//!
//! No `unsafe` in library logic, no threads, no file/OS access: suitable for
//! `wasm32-unknown-unknown` (enable `--features wasm` for `wasm-bindgen` exports).
#![cfg_attr(not(feature = "wasm"), forbid(unsafe_code))]
#![deny(unsafe_code)]

#[cfg(feature = "wasm")]
use wasm_bindgen::prelude::wasm_bindgen;

pub mod cover;
pub mod cube;
pub mod device;
pub mod espresso;
pub mod jedec;
pub mod pla;
pub mod pla_to_eqn;
pub mod prs_parser;
pub mod prs_to_pla;

pub use cover::{Cover, MvCover};
pub use cube::{
    cube_contains, cube_distance, cube_intersect, mv_cube_contains, mv_cube_distance,
    mv_cube_intersect, Cube, MvCube, ParseError, Part,
};
pub use espresso::{
    expand, expand_mv, irredundant, irredundant_mv, make_sparse_mv, minimize,
    minimize_minterms, minimize_multi_minterms, minimize_mv, minimize_strings, reduce,
    reduce_mv,
};
pub use device::{DeviceConfig, TargetDevice};
pub use jedec::{parse_pin_map_json, pla_to_jedec, FuseBlock, JedecError, JedecFile};
pub use pla::{minimize_pla, Pla, PlaError, PlaType};
pub use pla_to_eqn::pla_to_eqn;
pub use prs_parser::{PrsDocument, PrsField, PrsNode, PrsParser, ResolvedRef};
pub use prs_to_pla::{
    circuit_to_pla, extract_circuit, extract_pin_assignments, prs_bytes_to_pla, prs_to_pla,
    BoolExpr, PrsCircuit, PrsToPlaError,
};

/// Parse a Berkeley `.pla` text description, run joint multi-output Espresso
/// minimization, and return the minimized `.pla` text (or an error message).
///
/// Exported to WebAssembly via `wasm-bindgen` when compiled with `--features wasm`.
#[cfg_attr(feature = "wasm", wasm_bindgen)]
pub fn run_espresso(pla_text: &str) -> Result<String, String> {
    minimize_pla(pla_text).map_err(|e| e.to_string())
}

/// Parse a binary Cypress `.prs` file and return a JSON summary containing
/// source files, entity name, input/output ports (`Port_syms`), and extracted
/// boolean equations.
///
/// Exported to WebAssembly via `wasm-bindgen` when compiled with `--features wasm`.
#[cfg_attr(feature = "wasm", wasm_bindgen)]
pub fn parse_prs_summary(bytes: &[u8]) -> Result<String, String> {
    let doc = PrsDocument::from_bytes(bytes).map_err(|e| e.to_string())?;
    let circuit = extract_circuit(&doc).map_err(|e| e.to_string())?;

    let entity_json = match &circuit.entity_name {
        Some(name) => json_string(name),
        None => "null".to_string(),
    };
    let sources_json = json_string_array(&doc.source_files);
    let inputs_json = json_string_array(&circuit.inputs);
    let outputs_json = json_string_array(&circuit.outputs);
    let eqs_json = circuit
        .equations
        .iter()
        .map(|(out, expr)| {
            format!(
                "{{\"output\":{},\"expr\":{}}}",
                json_string(out),
                json_string(&expr.to_string())
            )
        })
        .collect::<Vec<_>>()
        .join(",");

    Ok(format!(
        "{{\"entity\":{entity_json},\"object_count\":{},\"source_files\":{sources_json},\"inputs\":{inputs_json},\"outputs\":{outputs_json},\"equations\":[{eqs_json}]}}",
        doc.objects.len()
    ))
}

/// Convert a binary Cypress `.prs` buffer directly into Berkeley `.pla` text.
///
/// Exported to WebAssembly via `wasm-bindgen` when compiled with `--features wasm`.
#[cfg_attr(feature = "wasm", wasm_bindgen)]
pub fn prs_to_pla_wasm(bytes: &[u8]) -> Result<String, String> {
    prs_bytes_to_pla(bytes).map_err(|e| e.to_string())
}

/// Extract VHDL `pin_numbers` / `PIN_NUMBER` attribute assignments from a `.prs`
/// binary buffer as a JSON object string (e.g. `{"a":13,"b":10,"y":2}`).
#[cfg_attr(feature = "wasm", wasm_bindgen)]
pub fn prs_pin_map_wasm(bytes: &[u8]) -> Result<String, String> {
    let doc = PrsDocument::from_bytes(bytes).map_err(|e| e.to_string())?;
    let pins = extract_pin_assignments(&doc);
    let entries: Vec<String> = pins
        .into_iter()
        .map(|(sig, pin)| format!("{}:{}", json_string(&sig), pin))
        .collect();
    Ok(format!("{{{}}}", entries.join(",")))
}

/// Convert a (minimized) Berkeley `.pla` text description into human-readable
/// Boolean equations using `.ilb` and `.ob` labels.
///
/// Exported to WebAssembly via `wasm-bindgen` when compiled with `--features wasm`.
#[cfg_attr(feature = "wasm", wasm_bindgen)]
pub fn pla_to_eqn_wasm(pla_text: &str) -> Result<String, String> {
    pla_to_eqn(pla_text).map_err(|e| e.to_string())
}

/// Convert a (minimized) Berkeley `.pla` text description into a JESD3-C JEDEC
/// fuse-map string for `device_name` (e.g. `"GAL22V10"`), using an optional JSON
/// pin-mapping object (e.g. `{"clk": 1, "en": 2, "y": 22}`).
///
/// Exported to WebAssembly via `wasm-bindgen` when compiled with `--features wasm`.
#[cfg_attr(feature = "wasm", wasm_bindgen)]
pub fn pla_to_jedec_wasm(
    pla_text: &str,
    device_name: &str,
    pin_map_json: &str,
) -> Result<String, String> {
    let pla = Pla::parse(pla_text).map_err(|e| e.to_string())?;
    let config = DeviceConfig::from_name(device_name).map_err(|e| e.to_string())?;
    let pin_mapping = parse_pin_map_json(pin_map_json).map_err(|e| e.to_string())?;
    let jedec = pla_to_jedec(&pla, &config, pin_mapping).map_err(|e| e.to_string())?;
    Ok(jedec.to_jedec_string())
}

fn json_string(s: &str) -> String {
    let mut out = String::with_capacity(s.len() + 2);
    out.push('"');
    for ch in s.chars() {
        match ch {
            '"' => out.push_str("\\\""),
            '\\' => out.push_str("\\\\"),
            '\n' => out.push_str("\\n"),
            '\r' => out.push_str("\\r"),
            '\t' => out.push_str("\\t"),
            c if (c as u32) < 0x20 => out.push_str(&format!("\\u{:04x}", c as u32)),
            c => out.push(c),
        }
    }
    out.push('"');
    out
}

fn json_string_array(items: &[String]) -> String {
    let inner = items
        .iter()
        .map(|s| json_string(s))
        .collect::<Vec<_>>()
        .join(",");
    format!("[{inner}]")
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn run_espresso_ok_and_err() {
        let input = "\
.i 3
.o 2
.ilb a b c
.ob f0 f1
001 11
110 10
111 10
010 01
011 01
.e
";
        let out = run_espresso(input).expect("valid PLA should minimize");
        let parsed = Pla::parse(&out).expect("output PLA should parse");
        assert_eq!(parsed.nin, 3);
        assert_eq!(parsed.nout, 2);
        assert_eq!(parsed.on.len(), 3);

        let err = run_espresso("invalid pla without dimensions").unwrap_err();
        assert!(err.contains("line 1"), "unexpected error message: {err}");
    }

    #[test]
    fn wasm_prs_endpoints_work_on_test_prs() {
        let bytes = include_bytes!("../warp_test/test.prs");
        let summary = parse_prs_summary(bytes).expect("parse_prs_summary should succeed");
        assert!(summary.contains("\"entity\":\"test\""));
        assert!(summary.contains("\"inputs\":[\"a\",\"b\"]"));
        assert!(summary.contains("\"outputs\":[\"y\"]"));
        assert!(summary.contains("\"output\":\"y\",\"expr\":\"a AND b\""));

        let pla = prs_to_pla_wasm(bytes).expect("prs_to_pla_wasm should succeed");
        let minimized = run_espresso(&pla).expect("run_espresso on converted PLA should succeed");
        let parsed = Pla::parse(&minimized).expect("minimized PLA should parse");
        assert_eq!(parsed.on.len(), 1);

        let jedec = pla_to_jedec_wasm(&minimized, "GAL22V10", "")
            .expect("pla_to_jedec_wasm should succeed");
        assert!(jedec.starts_with('\x02'));
        assert!(jedec.contains("*QF5828*"));
        assert!(jedec.contains('\x03'));

        let mapped_jedec = pla_to_jedec_wasm(&minimized, "GAL22V10", r#"{"a": 4, "b": 5, "y": 22}"#)
            .expect("pla_to_jedec_wasm with pin_map_json should succeed");
        assert!(mapped_jedec.contains("*L0484 1111110101"));
    }
}
