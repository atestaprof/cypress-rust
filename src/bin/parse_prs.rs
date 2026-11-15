use std::fs::File;
use std::io::BufReader;

use espresso_rs::prs_parser::{PrsNode, PrsParser};

fn main() {
    let prs_path = std::env::args()
        .nth(1)
        .unwrap_or_else(|| "warp_test/test.prs".to_string());

    let file = File::open(&prs_path).unwrap_or_else(|_| {
        panic!(
            "No se pudo abrir el archivo {}. Verifica la ruta desde la raíz del repo.",
            prs_path
        );
    });

    let buf_reader = BufReader::new(file);
    let mut parser = PrsParser::new(buf_reader);

    println!("Iniciando escaneo del AST en {}...", prs_path);

    let mut count = 0usize;
    loop {
        match parser.read_pobject() {
            Ok(PrsNode::Eof) => {
                println!("\nEOF (0x1a) alcanzado exitosamente tras {} nodos raíz.", count);
                break;
            }
            Ok(node) => {
                count += 1;
                println!("--- Nodo raíz #{} ---\n{:#?}", count, node);
            }
            Err(e) => {
                eprintln!("\n[!] DETENIDO: {}", e);
                std::process::exit(1);
            }
        }
    }
}
