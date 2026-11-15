use std::collections::HashMap;
use std::env;
use std::fs;
use std::process;

use espresso_rs::{
    circuit_to_pla, extract_circuit, minimize_pla, parse_pin_map_json, pla_to_jedec, Pla,
    PrsDocument, TargetDevice,
};

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() < 2 {
        eprintln!(
            "Uso: {} <archivo.prs> [salida.jed] [dispositivo] [--pin-map <json>] [--emit-cyp-pla <salida.pla>]",
            args.first().map(String::as_str).unwrap_or("generate_jed")
        );
        process::exit(1);
    }

    let prs_path = &args[1];
    let jed_path = args.get(2).map(String::as_str).unwrap_or("generated.jed");
    let device_name = args.get(3).map(String::as_str).unwrap_or("CY37032");
    let pin_map_json = args
        .windows(2)
        .find(|w| w[0] == "--pin-map")
        .map(|w| w[1].as_str())
        .unwrap_or("");
    let cyp_pla_path = args
        .windows(2)
        .find(|w| w[0] == "--emit-cyp-pla")
        .map(|w| w[1].as_str());

    let bytes = fs::read(prs_path).unwrap_or_else(|e| {
        eprintln!("Error leyendo {prs_path}: {e}");
        process::exit(1);
    });

    let doc = PrsDocument::from_bytes(&bytes).unwrap_or_else(|e| {
        eprintln!("Error parseando {prs_path}: {e}");
        process::exit(1);
    });
    let circuit = extract_circuit(&doc).unwrap_or_else(|e| {
        eprintln!("Error extrayendo circuito de {prs_path}: {e}");
        process::exit(1);
    });
    let raw_pla = circuit_to_pla(&circuit).unwrap_or_else(|e| {
        eprintln!("Error convirtiendo {prs_path} a PLA: {e}");
        process::exit(1);
    });

    let minimized_pla = minimize_pla(&raw_pla).unwrap_or_else(|e| {
        eprintln!("Error minimizando PLA con Espresso: {e}");
        process::exit(1);
    });

    let pla = Pla::parse(&minimized_pla).unwrap_or_else(|e| {
        eprintln!("Error parseando PLA minimizado: {e}");
        process::exit(1);
    });

    if let Some(pla_out) = cyp_pla_path {
        let mut cyp_pla = String::new();
        cyp_pla.push_str("#$ TITLE generated_by_espresso_rs\n");
        cyp_pla.push_str("#$ DEVICE CY37032VP44\n");
        let mut pin_names: Vec<String> = Vec::new();
        if let Some(ilb) = &pla.input_labels {
            pin_names.extend(ilb.iter().cloned());
        }
        if let Some(ob) = &pla.output_labels {
            pin_names.extend(ob.iter().cloned());
        }
        if !pin_names.is_empty() {
            cyp_pla.push_str(&format!("#$ PINS {} {}\n", pin_names.len(), pin_names.join(" ")));
        }
        cyp_pla.push_str(&minimized_pla);
        fs::write(pla_out, cyp_pla).unwrap_or_else(|e| {
            eprintln!("Error escribiendo {pla_out}: {e}");
            process::exit(1);
        });
    }

    let device = TargetDevice::from_name(device_name).unwrap_or_else(|e| {
        eprintln!("Dispositivo inválido {device_name:?}: {e}");
        process::exit(1);
    });
    let cli_pin_mapping = parse_pin_map_json(pin_map_json).unwrap_or_else(|e| {
        eprintln!("Error en --pin-map JSON: {e}");
        process::exit(1);
    });
    let pin_mapping = match cli_pin_mapping {
        Some(map) => Some(map),
        None if !circuit.pin_assignments.is_empty() => Some(
            circuit
                .pin_assignments
                .iter()
                .map(|(k, &v)| (k.clone(), v))
                .collect::<HashMap<String, usize>>(),
        ),
        None => None,
    };
    let config = device.config();
    let jedec = pla_to_jedec(&pla, &config, pin_mapping).unwrap_or_else(|e| {
        eprintln!("Error generando JEDEC: {e}");
        process::exit(1);
    });

    fs::write(jed_path, jedec.to_jedec_string()).unwrap_or_else(|e| {
        eprintln!("Error escribiendo {jed_path}: {e}");
        process::exit(1);
    });
}
