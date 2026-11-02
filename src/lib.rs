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
pub mod espresso;
pub mod pla;

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
pub use pla::{minimize_pla, Pla, PlaError, PlaType};

/// Parse a Berkeley `.pla` text description, run joint multi-output Espresso
/// minimization, and return the minimized `.pla` text (or an error message).
///
/// Exported to WebAssembly via `wasm-bindgen` when compiled with `--features wasm`.
#[cfg_attr(feature = "wasm", wasm_bindgen)]
pub fn run_espresso(pla_text: &str) -> Result<String, String> {
    minimize_pla(pla_text).map_err(|e| e.to_string())
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
}
