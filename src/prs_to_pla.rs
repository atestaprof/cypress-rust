//! Pure-Rust, WASM-compatible bridge from parsed Cypress `.prs` ASTs
//! (`PrsDocument`) to Berkeley Espresso `.pla` truth-table/SOP format.
//!
//! This module mirrors the `.pla` emission structure of Cypress `topld.exe`
//! (`pld2pla.cpp`): `.i`, `.o`, `.ilb`, `.ob`, `.phase`, `.p`, `.type f`,
//! ON-set product cubes, and `.e`, with zero `std::fs` or `unsafe` usage.

use std::collections::{BTreeMap, HashSet};
use std::fmt;

use crate::prs_parser::{PrsDocument, PrsField, PrsNode, ResolvedRef};

/// Errors returned when lowering a `PrsDocument` into `.pla` format.
#[derive(Clone, Debug, PartialEq, Eq)]
pub enum PrsToPlaError {
    /// Failed to parse the raw `.prs` byte stream.
    Parse(String),
    /// No `Port_syms` entity interface was found in the `.prs` document.
    MissingPorts,
    /// No `Simple_assignment_statement` equations were found.
    MissingAssignments,
    /// An AST node had an unexpected structure or unsupported construct.
    UnsupportedAst(String),
}

impl fmt::Display for PrsToPlaError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            PrsToPlaError::Parse(msg) => write!(f, "PRS parse error: {msg}"),
            PrsToPlaError::MissingPorts => write!(f, "no Port_syms found in PRS document"),
            PrsToPlaError::MissingAssignments => {
                write!(f, "no Simple_assignment_statement found in PRS document")
            }
            PrsToPlaError::UnsupportedAst(msg) => write!(f, "unsupported PRS AST: {msg}"),
        }
    }
}

impl std::error::Error for PrsToPlaError {}

/// Boolean expression AST lowered from Cypress `.prs` expression nodes.
#[derive(Clone, Debug, PartialEq, Eq)]
pub enum BoolExpr {
    Const(bool),
    Var(String),
    Not(Box<BoolExpr>),
    And(Vec<BoolExpr>),
    Or(Vec<BoolExpr>),
    Xor(Vec<BoolExpr>),
    Nand(Vec<BoolExpr>),
    Nor(Vec<BoolExpr>),
    Xnor(Vec<BoolExpr>),
}

impl fmt::Display for BoolExpr {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            BoolExpr::Const(true) => write!(f, "1"),
            BoolExpr::Const(false) => write!(f, "0"),
            BoolExpr::Var(name) => write!(f, "{name}"),
            BoolExpr::Not(inner) => match inner.as_ref() {
                BoolExpr::Var(_) | BoolExpr::Const(_) => write!(f, "NOT {inner}"),
                _ => write!(f, "NOT ({inner})"),
            },
            BoolExpr::And(args) => write_nary(f, "AND", args),
            BoolExpr::Or(args) => write_nary(f, "OR", args),
            BoolExpr::Xor(args) => write_nary(f, "XOR", args),
            BoolExpr::Nand(args) => write!(f, "NAND({})", join_args(args)),
            BoolExpr::Nor(args) => write!(f, "NOR({})", join_args(args)),
            BoolExpr::Xnor(args) => write!(f, "XNOR({})", join_args(args)),
        }
    }
}

fn join_args(args: &[BoolExpr]) -> String {
    args.iter()
        .map(ToString::to_string)
        .collect::<Vec<_>>()
        .join(", ")
}

fn write_nary(f: &mut fmt::Formatter<'_>, op: &str, args: &[BoolExpr]) -> fmt::Result {
    let parts: Vec<String> = args
        .iter()
        .map(|a| match a {
            BoolExpr::Var(_) | BoolExpr::Const(_) | BoolExpr::Not(_) => a.to_string(),
            _ => format!("({a})"),
        })
        .collect();
    write!(f, "{}", parts.join(&format!(" {op} ")))
}

/// Extracted entity interface and combinational equations from a `.prs` file.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct PrsCircuit {
    pub entity_name: Option<String>,
    pub inputs: Vec<String>,
    pub outputs: Vec<String>,
    pub equations: BTreeMap<String, BoolExpr>,
    /// Physical pin assignments extracted from VHDL `pin_numbers` / `PIN_NUMBER` attributes.
    pub pin_assignments: BTreeMap<String, usize>,
}

#[derive(Clone, Debug)]
struct PortInfo {
    name: String,
    dir: PortDir,
    bits: Option<Vec<String>>,
}

#[derive(Clone, Debug)]
enum LoweredVal {
    Scalar(BoolExpr),
    Vector(Vec<BoolExpr>),
    Others,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum PortDir {
    In,
    Out,
    InOut,
    Unknown,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum Lit {
    Zero,
    One,
    DontCare,
}

impl Lit {
    fn as_char(self) -> char {
        match self {
            Lit::Zero => '0',
            Lit::One => '1',
            Lit::DontCare => '-',
        }
    }

    fn intersect(self, other: Lit) -> Option<Lit> {
        match (self, other) {
            (Lit::DontCare, x) | (x, Lit::DontCare) => Some(x),
            (Lit::Zero, Lit::Zero) => Some(Lit::Zero),
            (Lit::One, Lit::One) => Some(Lit::One),
            _ => None,
        }
    }
}

/// Convert raw `.prs` bytes directly into a `.pla` string (`PlaType::F`).
pub fn prs_bytes_to_pla(bytes: &[u8]) -> Result<String, PrsToPlaError> {
    let doc = PrsDocument::from_bytes(bytes).map_err(|e| PrsToPlaError::Parse(e.to_string()))?;
    prs_to_pla(&doc)
}

/// Convert a parsed `PrsDocument` into a `.pla` string (`PlaType::F`).
pub fn prs_to_pla(doc: &PrsDocument) -> Result<String, PrsToPlaError> {
    let circuit = extract_circuit(doc)?;
    circuit_to_pla(&circuit)
}

/// Extract ports (`Port_syms`) and concurrent/process assignments
/// from a `PrsDocument`.
pub fn extract_circuit(doc: &PrsDocument) -> Result<PrsCircuit, PrsToPlaError> {
    let (entity_name, port_infos) = extract_ports(doc)?;

    let mut vectors: BTreeMap<String, Vec<String>> = collect_all_vectors(doc);
    for p in &port_infos {
        if let Some(bits) = &p.bits {
            vectors.insert(p.name.clone(), bits.clone());
        }
    }

    let mut seq = SeqContext::default();
    let mut raw_assignments = collect_assignments(doc, &vectors, &mut seq)?;
    if raw_assignments.is_empty() {
        return Err(PrsToPlaError::MissingAssignments);
    }

    // Resolve signal aliases (e.g. `count[i] <= cnt[i]` where `cnt[i]` is registered)
    // so registered outputs use their port name (`count[i].d`) and feedback uses `count[i]`.
    let mut port_bit_set = HashSet::new();
    for p in &port_infos {
        if let Some(bits) = &p.bits {
            port_bit_set.extend(bits.iter().cloned());
        } else {
            port_bit_set.insert(p.name.clone());
        }
    }

    let mut subst: BTreeMap<String, String> = BTreeMap::new();
    let mut alias_targets: Vec<String> = Vec::new();
    for (target, expr) in &raw_assignments {
        if port_bit_set.contains(target) && !seq.registered.contains(target) {
            if let BoolExpr::Var(src) = expr {
                if seq.registered.contains(src) && !port_bit_set.contains(src) {
                    subst.insert(src.clone(), target.clone());
                    alias_targets.push(target.clone());
                }
            }
        }
    }

    if !subst.is_empty() {
        let mut updated = BTreeMap::new();
        for (k, v) in raw_assignments {
            if alias_targets.contains(&k) {
                continue;
            }
            let new_key = subst.get(&k).cloned().unwrap_or(k);
            if seq.registered.remove(&new_key) || subst.values().any(|t| t == &new_key) {
                seq.registered.insert(new_key.clone());
            }
            updated.insert(new_key, substitute_vars(v, &subst));
        }
        raw_assignments = updated;
    }

    // Rename registered outputs to `<name>.d` and collect all referenced input vars.
    let mut assignments = BTreeMap::new();
    let mut used_vars = HashSet::new();
    for (target, expr) in raw_assignments {
        collect_expr_vars(&expr, &mut used_vars);
        if seq.registered.contains(&target) {
            assignments.insert(format!("{target}.d"), expr);
        } else {
            assignments.insert(target, expr);
        }
    }

    let target_set: HashSet<String> = assignments.keys().cloned().collect();
    let mut inputs = Vec::new();
    let mut outputs = Vec::new();
    for port in port_infos {
        let bit_names = port.bits.unwrap_or_else(|| vec![port.name]);
        match port.dir {
            PortDir::Out => {
                for bit in bit_names {
                    if seq.registered.contains(&bit) {
                        if used_vars.contains(&bit) {
                            inputs.push(bit.clone());
                        }
                        outputs.push(format!("{bit}.d"));
                    } else {
                        outputs.push(bit);
                    }
                }
            }
            PortDir::In => {
                for bit in bit_names {
                    // Omit pure clock pins from `.ilb` when only used as clock edges.
                    if seq.clocks.contains(&bit) && !used_vars.contains(&bit) {
                        continue;
                    }
                    inputs.push(bit);
                }
            }
            PortDir::InOut | PortDir::Unknown => {
                for bit in bit_names {
                    if seq.registered.contains(&bit) {
                        if used_vars.contains(&bit) {
                            inputs.push(bit.clone());
                        }
                        outputs.push(format!("{bit}.d"));
                    } else if target_set.contains(&bit) {
                        outputs.push(bit);
                    } else if !(seq.clocks.contains(&bit) && !used_vars.contains(&bit)) {
                        inputs.push(bit);
                    }
                }
            }
        }
    }

    if inputs.is_empty() || outputs.is_empty() {
        return Err(PrsToPlaError::MissingPorts);
    }

    let pin_assignments = extract_pin_assignments(doc);

    Ok(PrsCircuit {
        entity_name,
        inputs,
        outputs,
        equations: assignments,
        pin_assignments,
    })
}

/// Extract physical pin assignments from `Dobject_list` / `Attribute` nodes
/// attached to `Port_syms` (e.g. `"a:13 b:10 y:2"`) or `Variable_symbol` (e.g. `"13"`).
pub fn extract_pin_assignments(doc: &PrsDocument) -> BTreeMap<String, usize> {
    let mut pins = BTreeMap::new();

    for node in doc.objects.values() {
        let PrsNode::Object {
            class_name, fields, ..
        } = node
        else {
            continue;
        };
        if class_name != "Port_syms" && class_name != "Variable_symbol" {
            continue;
        }
        let Some(PrsField::OptString(Some(sym_name))) = fields.first() else {
            continue;
        };
        let Some(PrsField::Node(attr_list_node)) = fields.get(4) else {
            continue;
        };

        let mut cursor = attr_list_node.as_ref();
        let mut guard = 0usize;
        while guard < 128 {
            guard += 1;
            let ResolvedRef::Local(PrsNode::Object {
                class_name: list_cls,
                fields: list_fields,
                ..
            }) = doc.resolve(cursor)
            else {
                break;
            };
            if list_cls != "Dobject_list" {
                break;
            }
            if let Some(PrsField::Node(item_node)) = list_fields.first() {
                if let ResolvedRef::Local(PrsNode::Object {
                    class_name: attr_cls,
                    fields: attr_fields,
                    ..
                }) = doc.resolve(item_node.as_ref())
                {
                    if attr_cls == "Attribute" {
                        if let Some(val_str) = extract_attribute_literal(doc, attr_fields) {
                            let unquoted = val_str.trim().trim_matches('"').trim();
                            if class_name == "Variable_symbol" {
                                if let Ok(pin) = unquoted.parse::<usize>() {
                                    pins.insert(sym_name.clone(), pin);
                                    continue;
                                }
                            }
                            for token in unquoted.split(|c: char| c.is_whitespace() || c == ',' || c == ';') {
                                if let Some((sig, pin_str)) = token.split_once(':') {
                                    let sig = sig.trim();
                                    if let Ok(pin) = pin_str.trim().parse::<usize>() {
                                        if !sig.is_empty() {
                                            pins.insert(sig.to_string(), pin);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            match list_fields.get(1) {
                Some(PrsField::Node(next)) => cursor = next.as_ref(),
                _ => break,
            }
        }
    }

    pins
}

fn extract_attribute_literal(doc: &PrsDocument, attr_fields: &[PrsField]) -> Option<String> {
    let PrsField::Node(val_node) = attr_fields.get(1)? else {
        return None;
    };
    let ResolvedRef::Local(PrsNode::Object {
        class_name, fields, ..
    }) = doc.resolve(val_node.as_ref())
    else {
        return None;
    };
    if class_name != "Literal_expr" {
        return None;
    }
    fields.iter().rev().find_map(|f| match f {
        PrsField::OptString(Some(s)) => Some(s.clone()),
        _ => None,
    })
}

#[derive(Default)]
struct SeqContext {
    clocks: HashSet<String>,
    registered: HashSet<String>,
}

fn collect_all_vectors(doc: &PrsDocument) -> BTreeMap<String, Vec<String>> {
    let mut map = BTreeMap::new();
    for node in doc.objects_of_class("Array_variable") {
        if let Some((_, fields)) = as_object(node) {
            if let Some(name) = first_opt_string(fields) {
                let bits = extract_array_variable_bits(doc, name, fields);
                map.insert(name.to_string(), bits);
            }
        }
    }
    map
}

fn substitute_vars(expr: BoolExpr, subst: &BTreeMap<String, String>) -> BoolExpr {
    match expr {
        BoolExpr::Const(b) => BoolExpr::Const(b),
        BoolExpr::Var(name) => BoolExpr::Var(subst.get(&name).cloned().unwrap_or(name)),
        BoolExpr::Not(inner) => BoolExpr::Not(Box::new(substitute_vars(*inner, subst))),
        BoolExpr::And(args) => {
            BoolExpr::And(args.into_iter().map(|a| substitute_vars(a, subst)).collect())
        }
        BoolExpr::Or(args) => {
            BoolExpr::Or(args.into_iter().map(|a| substitute_vars(a, subst)).collect())
        }
        BoolExpr::Xor(args) => {
            BoolExpr::Xor(args.into_iter().map(|a| substitute_vars(a, subst)).collect())
        }
        BoolExpr::Nand(args) => {
            BoolExpr::Nand(args.into_iter().map(|a| substitute_vars(a, subst)).collect())
        }
        BoolExpr::Nor(args) => {
            BoolExpr::Nor(args.into_iter().map(|a| substitute_vars(a, subst)).collect())
        }
        BoolExpr::Xnor(args) => {
            BoolExpr::Xnor(args.into_iter().map(|a| substitute_vars(a, subst)).collect())
        }
    }
}

fn collect_expr_vars(expr: &BoolExpr, out: &mut HashSet<String>) {
    match expr {
        BoolExpr::Const(_) => {}
        BoolExpr::Var(name) => {
            out.insert(name.clone());
        }
        BoolExpr::Not(inner) => collect_expr_vars(inner, out),
        BoolExpr::And(args)
        | BoolExpr::Or(args)
        | BoolExpr::Xor(args)
        | BoolExpr::Nand(args)
        | BoolExpr::Nor(args)
        | BoolExpr::Xnor(args) => {
            for a in args {
                collect_expr_vars(a, out);
            }
        }
    }
}

/// Serialize a `PrsCircuit` into Berkeley `.pla` text (`.type f`).
pub fn circuit_to_pla(circuit: &PrsCircuit) -> Result<String, PrsToPlaError> {
    let nin = circuit.inputs.len();
    let nout = circuit.outputs.len();
    let input_index: BTreeMap<&str, usize> = circuit
        .inputs
        .iter()
        .enumerate()
        .map(|(i, name)| (name.as_str(), i))
        .collect();

    // Collect (input_cube, output_cube) rows for each output's ON-set SOP.
    let mut rows: Vec<(String, String)> = Vec::new();
    for (out_idx, out_name) in circuit.outputs.iter().enumerate() {
        let Some(expr) = circuit.equations.get(out_name) else {
            continue;
        };
        let cubes = expr_to_sop(expr, nin, &input_index)?;
        let mut out_bits = vec!['0'; nout];
        out_bits[out_idx] = '1';
        let out_str: String = out_bits.into_iter().collect();

        for cube in cubes {
            let in_str: String = cube.into_iter().map(Lit::as_char).collect();
            rows.push((in_str, out_str.clone()));
        }
    }

    let phase = "1".repeat(nout);
    let mut out = String::new();
    out.push_str(&format!(".i {nin}\n"));
    out.push_str(&format!(".o {nout}\n"));
    out.push_str(&format!(".ilb {}\n", circuit.inputs.join(" ")));
    out.push_str(&format!(".ob {}\n", circuit.outputs.join(" ")));
    out.push_str(&format!(".phase {phase}\n"));
    out.push_str(&format!(".p {}\n", rows.len()));
    out.push_str(".type f\n");
    for (in_cube, out_cube) in &rows {
        out.push_str(&format!("{in_cube} {out_cube}\n"));
    }
    out.push_str(".e\n");
    Ok(out)
}

fn resolve_local<'a>(doc: &'a PrsDocument, node: &'a PrsNode) -> Option<&'a PrsNode> {
    match doc.resolve(node) {
        ResolvedRef::Local(n) | ResolvedRef::LocalSubobject { node: n, .. } => Some(n),
        _ => None,
    }
}

fn as_object(node: &PrsNode) -> Option<(&str, &[PrsField])> {
    match node {
        PrsNode::Object {
            class_name, fields, ..
        } => Some((class_name.as_str(), fields.as_slice())),
        _ => None,
    }
}

fn first_opt_string(fields: &[PrsField]) -> Option<&str> {
    fields.iter().find_map(|f| match f {
        PrsField::OptString(Some(s)) => Some(s.as_str()),
        _ => None,
    })
}

fn extract_ports(
    doc: &PrsDocument,
) -> Result<(Option<String>, Vec<PortInfo>), PrsToPlaError> {
    let port_syms = doc
        .objects_of_class("Port_syms")
        .into_iter()
        .next()
        .ok_or(PrsToPlaError::MissingPorts)?;
    let (_, ps_fields) = as_object(port_syms).ok_or(PrsToPlaError::MissingPorts)?;
    let entity_name = first_opt_string(ps_fields).map(str::to_string);

    let mut ports = Vec::new();
    let mut visited_var_names = HashSet::new();

    // Traverse Port_syms -> Scope_symbol -> Field_list -> Scope_symbol -> Variable_symbol / Array_variable.
    for field in ps_fields {
        if let PrsField::Node(n) = field {
            if let Some(scope) = resolve_local(doc, n) {
                collect_ports_from_scope(doc, scope, &mut visited_var_names, &mut ports);
            }
        }
    }

    if ports.is_empty() {
        return Err(PrsToPlaError::MissingPorts);
    }
    Ok((entity_name, ports))
}

fn collect_ports_from_scope(
    doc: &PrsDocument,
    node: &PrsNode,
    seen: &mut HashSet<String>,
    out: &mut Vec<PortInfo>,
) {
    let Some((class_name, fields)) = as_object(node) else {
        return;
    };
    match class_name {
        "Scope_symbol" => {
            for f in fields {
                if let PrsField::NodeList(items) = f {
                    for item in items {
                        if let Some(resolved) = resolve_local(doc, item) {
                            collect_ports_from_scope(doc, resolved, seen, out);
                        }
                    }
                }
            }
        }
        "Field_list" => {
            for f in fields {
                if let PrsField::Node(n) = f {
                    if let Some(resolved) = resolve_local(doc, n) {
                        collect_ports_from_scope(doc, resolved, seen, out);
                    }
                }
            }
        }
        "Variable_symbol" => {
            if let Some(name) = first_opt_string(fields) {
                if seen.insert(name.to_string()) {
                    let dir = classify_variable_symbol_dir(fields);
                    out.push(PortInfo {
                        name: name.to_string(),
                        dir,
                        bits: None,
                    });
                }
            }
        }
        "Array_variable" => {
            if let Some(name) = first_opt_string(fields) {
                if seen.insert(name.to_string()) {
                    let dir = classify_variable_symbol_dir(fields);
                    let bits = extract_array_variable_bits(doc, name, fields);
                    out.push(PortInfo {
                        name: name.to_string(),
                        dir,
                        bits: Some(bits),
                    });
                }
            }
        }
        _ => {}
    }
}

fn extract_array_variable_bits(
    doc: &PrsDocument,
    name: &str,
    fields: &[PrsField],
) -> Vec<String> {
    // Try Range_type from Array_variable's fields or its Array_type -> Constrained_type -> Range_type.
    for f in fields {
        if let PrsField::Node(n) = f {
            if let Some(bits) = find_range_bits(doc, name, n, 0) {
                return bits;
            }
        }
    }
    vec![name.to_string()]
}

fn find_range_bits(
    doc: &PrsDocument,
    name: &str,
    node: &PrsNode,
    depth: usize,
) -> Option<Vec<String>> {
    if depth > 4 {
        return None;
    }
    let resolved = resolve_local(doc, node)?;
    let (class_name, fields) = as_object(resolved)?;
    match class_name {
        "Range_type" => {
            let left = match fields.get(6) {
                Some(PrsField::U32(v)) => *v,
                _ => return None,
            };
            let right = match fields.get(7) {
                Some(PrsField::U32(v)) => *v,
                _ => return None,
            };
            let dir = match fields.get(8) {
                Some(PrsField::U16(v)) => *v,
                _ => 65535,
            };
            let mut bits = Vec::new();
            if dir == 65535 || left >= right {
                let mut i = left as i64;
                while i >= right as i64 {
                    bits.push(format!("{name}[{i}]"));
                    i -= 1;
                }
            } else {
                for i in left..=right {
                    bits.push(format!("{name}[{i}]"));
                }
            }
            Some(bits)
        }
        "Array_type" | "Constrained_type" => {
            for f in fields {
                if let PrsField::Node(n) = f {
                    if let Some(bits) = find_range_bits(doc, name, n, depth + 1) {
                        return Some(bits);
                    }
                }
            }
            None
        }
        _ => None,
    }
}

fn classify_variable_symbol_dir(fields: &[PrsField]) -> PortDir {
    // In vhdlfe `.prs` Variable_symbol / Array_variable, the mode byte:
    // 1 = in, 2 = out, 3 = inout.
    let u8s: Vec<u8> = fields
        .iter()
        .filter_map(|f| match f {
            PrsField::U8(v) => Some(*v),
            _ => None,
        })
        .collect();
    if let Some(&mode) = u8s.first() {
        match mode {
            1 => return PortDir::In,
            2 => return PortDir::Out,
            3 => return PortDir::InOut,
            _ => {}
        }
    }
    PortDir::Unknown
}

fn collect_assignments(
    doc: &PrsDocument,
    vectors: &BTreeMap<String, Vec<String>>,
    seq: &mut SeqContext,
) -> Result<BTreeMap<String, BoolExpr>, PrsToPlaError> {
    let mut map = BTreeMap::new();
    let mut visited_stmts: HashSet<u32> = HashSet::new();

    for proc_node in doc.objects_of_class("Process_statement") {
        let Some((_, fields)) = as_object(proc_node) else {
            return Err(PrsToPlaError::UnsupportedAst("non-object process".into()));
        };
        if let Some(PrsField::Node(stmt_list)) = fields.get(2) {
            if !matches!(stmt_list.as_ref(), PrsNode::Null) {
                let stmts = collect_tree_node_list(doc, stmt_list)?;
                eval_stmt_list(doc, &stmts, vectors, seq, &mut map, false, &mut visited_stmts)?;
            }
        }
    }

    for stmt in doc.objects_of_class("Simple_assignment_statement") {
        if let PrsNode::Object { object_id, .. } = stmt {
            if visited_stmts.contains(object_id) {
                continue;
            }
        }
        eval_simple_assignment(doc, stmt, vectors, &mut map)?;
    }
    Ok(map)
}

fn eval_stmt_list(
    doc: &PrsDocument,
    stmts: &[PrsNode],
    vectors: &BTreeMap<String, Vec<String>>,
    seq: &mut SeqContext,
    env: &mut BTreeMap<String, BoolExpr>,
    default_hold: bool,
    visited_stmts: &mut HashSet<u32>,
) -> Result<(), PrsToPlaError> {
    for stmt in stmts {
        let Some(resolved) = resolve_local(doc, stmt) else {
            continue;
        };
        if let PrsNode::Object { object_id, .. } = resolved {
            visited_stmts.insert(*object_id);
        }
        let Some((class_name, fields)) = as_object(resolved) else {
            continue;
        };
        match class_name {
            "Simple_assignment_statement" => {
                eval_simple_assignment(doc, resolved, vectors, env)?;
            }
            "If_statement" => {
                eval_if_statement(doc, fields, vectors, seq, env, default_hold, visited_stmts)?;
            }
            "Case_statement" => {
                eval_case_statement(doc, fields, vectors, seq, env, default_hold, visited_stmts)?;
            }
            "Wait_statement" | "Null_statement" => {}
            other => {
                return Err(PrsToPlaError::UnsupportedAst(format!(
                    "unsupported statement class {other}"
                )));
            }
        }
    }
    Ok(())
}

fn eval_simple_assignment(
    doc: &PrsDocument,
    stmt: &PrsNode,
    vectors: &BTreeMap<String, Vec<String>>,
    env: &mut BTreeMap<String, BoolExpr>,
) -> Result<(), PrsToPlaError> {
    let (_, fields) =
        as_object(stmt).ok_or_else(|| PrsToPlaError::UnsupportedAst("non-object stmt".into()))?;
    let target_node = fields
        .get(1)
        .and_then(|f| match f {
            PrsField::Node(n) => Some(n.as_ref()),
            _ => None,
        })
        .ok_or_else(|| PrsToPlaError::UnsupportedAst("assignment missing target".into()))?;
    let rhs_node = fields
        .get(3)
        .and_then(|f| match f {
            PrsField::Node(n) => Some(n.as_ref()),
            _ => None,
        })
        .ok_or_else(|| PrsToPlaError::UnsupportedAst("assignment missing rhs".into()))?;

    let target_name = extract_target_name(doc, target_node)?;
    if let Some(lhs_bits) = vectors.get(&target_name) {
        if let LoweredVal::Vector(rhs_bits) = lower_val(doc, rhs_node, vectors)? {
            if lhs_bits.len() != rhs_bits.len() {
                return Err(PrsToPlaError::UnsupportedAst(format!(
                    "vector assignment width mismatch for {target_name}: {} vs {}",
                    lhs_bits.len(),
                    rhs_bits.len()
                )));
            }
            for (lhs_bit, rhs_expr) in lhs_bits.iter().zip(rhs_bits) {
                env.insert(lhs_bit.clone(), rhs_expr);
            }
            return Ok(());
        }
    }
    let expr = lower_scalar_expr(doc, rhs_node, vectors)?;
    env.insert(target_name, expr);
    Ok(())
}

enum IfBranchKind {
    Cond(BoolExpr),
    Clocked,
    Else,
}

fn eval_if_statement(
    doc: &PrsDocument,
    fields: &[PrsField],
    vectors: &BTreeMap<String, Vec<String>>,
    seq: &mut SeqContext,
    env: &mut BTreeMap<String, BoolExpr>,
    default_hold: bool,
    visited_stmts: &mut HashSet<u32>,
) -> Result<(), PrsToPlaError> {
    let mut raw_branches: Vec<(Option<PrsNode>, Vec<PrsNode>)> = Vec::new();

    let cond0_node = fields
        .get(1)
        .and_then(|f| match f {
            PrsField::Node(n) => Some(n.as_ref().clone()),
            _ => None,
        })
        .ok_or_else(|| PrsToPlaError::UnsupportedAst("If_statement missing cond".into()))?;
    let then0 = match fields.get(2) {
        Some(PrsField::Node(n)) if !matches!(n.as_ref(), PrsNode::Null) => {
            collect_tree_node_list(doc, n)?
        }
        _ => Vec::new(),
    };
    raw_branches.push((Some(cond0_node), then0));

    if let Some(PrsField::Node(elsif_node)) = fields.get(3) {
        if !matches!(elsif_node.as_ref(), PrsNode::Null) {
            let elsifs = collect_tree_node_list(doc, elsif_node)?;
            for item in elsifs {
                let Some(resolved) = resolve_local(doc, &item) else {
                    continue;
                };
                let Some((cls, ef)) = as_object(resolved) else {
                    continue;
                };
                if cls == "Elseif_clause" {
                    let c_node = ef
                        .get(1)
                        .and_then(|f| match f {
                            PrsField::Node(n) => Some(n.as_ref().clone()),
                            _ => None,
                        })
                        .ok_or_else(|| {
                            PrsToPlaError::UnsupportedAst("Elseif_clause missing cond".into())
                        })?;
                    let body = match ef.get(2) {
                        Some(PrsField::Node(n)) if !matches!(n.as_ref(), PrsNode::Null) => {
                            collect_tree_node_list(doc, n)?
                        }
                        _ => Vec::new(),
                    };
                    raw_branches.push((Some(c_node), body));
                }
            }
        }
    }

    let else_stmts = match fields.get(4) {
        Some(PrsField::Node(n)) if !matches!(n.as_ref(), PrsNode::Null) => {
            collect_tree_node_list(doc, n)?
        }
        _ => Vec::new(),
    };
    if !else_stmts.is_empty() {
        raw_branches.push((None, else_stmts));
    }

    let base_env = env.clone();
    let mut branch_envs: Vec<(IfBranchKind, BTreeMap<String, BoolExpr>)> =
        Vec::with_capacity(raw_branches.len());

    for (cond_opt, stmts) in raw_branches {
        match cond_opt {
            Some(c_node) => {
                if let Some(clk_name) = extract_clock_edge(doc, &c_node) {
                    seq.clocks.insert(clk_name);
                    let mut clocked_env = base_env.clone();
                    eval_stmt_list(
                        doc,
                        &stmts,
                        vectors,
                        seq,
                        &mut clocked_env,
                        true,
                        visited_stmts,
                    )?;
                    for target in clocked_env.keys() {
                        seq.registered.insert(target.clone());
                    }
                    branch_envs.push((IfBranchKind::Clocked, clocked_env));
                } else {
                    let cond = lower_scalar_expr(doc, &c_node, vectors)?;
                    let mut b_env = base_env.clone();
                    eval_stmt_list(
                        doc,
                        &stmts,
                        vectors,
                        seq,
                        &mut b_env,
                        default_hold,
                        visited_stmts,
                    )?;
                    branch_envs.push((IfBranchKind::Cond(cond), b_env));
                }
            }
            None => {
                let mut b_env = base_env.clone();
                eval_stmt_list(
                    doc,
                    &stmts,
                    vectors,
                    seq,
                    &mut b_env,
                    default_hold,
                    visited_stmts,
                )?;
                branch_envs.push((IfBranchKind::Else, b_env));
            }
        }
    }

    let mut all_targets: HashSet<String> = base_env.keys().cloned().collect();
    for (_, b_env) in &branch_envs {
        all_targets.extend(b_env.keys().cloned());
    }

    for target in all_targets {
        let default_expr = || {
            base_env.get(&target).cloned().unwrap_or_else(|| {
                if default_hold {
                    BoolExpr::Var(target.clone())
                } else {
                    BoolExpr::Const(false)
                }
            })
        };

        let mut acc = match branch_envs.last() {
            Some((IfBranchKind::Else, e)) | Some((IfBranchKind::Clocked, e)) => {
                e.get(&target).cloned().unwrap_or_else(default_expr)
            }
            _ => default_expr(),
        };

        for (kind, b_env) in branch_envs.iter().rev() {
            if let IfBranchKind::Cond(cond) = kind {
                let then_val = b_env.get(&target).cloned().unwrap_or_else(default_expr);
                acc = mk_ite(cond.clone(), then_val, acc);
            }
        }
        env.insert(target, acc);
    }

    Ok(())
}

fn extract_clock_signal_name(doc: &PrsDocument, node: &PrsNode) -> Option<String> {
    if let Ok(name) = extract_target_name(doc, node) {
        return Some(name);
    }
    let resolved = resolve_local(doc, node)?;
    let (_, fields) = as_object(resolved)?;
    for f in fields {
        if let PrsField::Node(n) = f {
            if !matches!(n.as_ref(), PrsNode::Null) {
                if let Some(name) = extract_clock_signal_name(doc, n) {
                    return Some(name);
                }
            }
        }
    }
    None
}

fn extract_clock_edge(doc: &PrsDocument, node: &PrsNode) -> Option<String> {
    let resolved = resolve_local(doc, node)?;
    let (class_name, fields) = as_object(resolved)?;
    match class_name {
        "Function_call" => {
            let op_node = fields.get(2).and_then(|f| match f {
                PrsField::Node(n) => Some(n.as_ref()),
                _ => None,
            })?;
            let op_name = resolve_operator_name(doc, op_node).ok()?;
            if matches!(op_name.as_str(), "rising_edge" | "falling_edge") {
                let args_node = fields.get(3).and_then(|f| match f {
                    PrsField::Node(n) => Some(n.as_ref()),
                    _ => None,
                })?;
                let arg_nodes = collect_tree_node_list(doc, args_node).ok()?;
                if let Some(first_arg) = arg_nodes.first() {
                    return extract_clock_signal_name(doc, first_arg);
                }
            }
            None
        }
        "Binary_expr" => {
            let lhs = fields.get(3).and_then(|f| match f {
                PrsField::Node(n) if !matches!(n.as_ref(), PrsNode::Null) => Some(n.as_ref()),
                _ => None,
            });
            let rhs = fields.get(4).and_then(|f| match f {
                PrsField::Node(n) if !matches!(n.as_ref(), PrsNode::Null) => Some(n.as_ref()),
                _ => None,
            });
            match (lhs, rhs) {
                (None, Some(inner)) | (Some(inner), None) => extract_clock_edge(doc, inner),
                (Some(l), Some(r)) => {
                    let op_tag = fields.get(2).and_then(|f| match f {
                        PrsField::U32(v) => Some(*v),
                        _ => None,
                    });
                    // 328 = boolean 'and', 0 = logical 'and', 61 = '='
                    if matches!(op_tag, Some(328) | Some(0) | Some(61)) {
                        if let Some(clk) = extract_clock_edge(doc, l) {
                            return Some(clk);
                        }
                        if let Some(clk) = extract_clock_edge(doc, r) {
                            return Some(clk);
                        }
                    }
                    None
                }
                (None, None) => None,
            }
        }
        "Attribute_name_expr" => {
            let attr_is_event = fields
                .get(3)
                .and_then(|f| match f {
                    PrsField::Node(n) => resolve_local(doc, n),
                    _ => None,
                })
                .and_then(as_object)
                .and_then(|(_, af)| first_opt_string(af))
                .map(|s| s.eq_ignore_ascii_case("event"))
                .unwrap_or(true);
            if !attr_is_event {
                return None;
            }
            let prefix_node = fields.get(2).and_then(|f| match f {
                PrsField::Node(n) => Some(n.as_ref()),
                _ => None,
            })?;
            extract_clock_signal_name(doc, prefix_node)
        }
        _ => None,
    }
}

fn eval_case_statement(
    doc: &PrsDocument,
    fields: &[PrsField],
    vectors: &BTreeMap<String, Vec<String>>,
    seq: &mut SeqContext,
    env: &mut BTreeMap<String, BoolExpr>,
    default_hold: bool,
    visited_stmts: &mut HashSet<u32>,
) -> Result<(), PrsToPlaError> {
    let sel_node = fields
        .get(1)
        .and_then(|f| match f {
            PrsField::Node(n) => Some(n.as_ref()),
            _ => None,
        })
        .ok_or_else(|| PrsToPlaError::UnsupportedAst("Case_statement missing selector".into()))?;
    let sel_val = lower_val(doc, sel_node, vectors)?;

    let alts = match fields.get(2) {
        Some(PrsField::Node(n)) if !matches!(n.as_ref(), PrsNode::Null) => {
            collect_tree_node_list(doc, n)?
        }
        _ => return Ok(()),
    };

    let base_env = env.clone();
    let mut covered_conds: Vec<BoolExpr> = Vec::new();
    let mut alt_results: Vec<(Option<BoolExpr>, BTreeMap<String, BoolExpr>)> = Vec::new();

    for alt in alts {
        let Some(resolved) = resolve_local(doc, &alt) else {
            continue;
        };
        let Some((cls, af)) = as_object(resolved) else {
            continue;
        };
        if cls != "Case_statement_alternative" {
            continue;
        }
        let choices = match af.get(1) {
            Some(PrsField::Node(n)) if !matches!(n.as_ref(), PrsNode::Null) => {
                collect_tree_node_list(doc, n)?
            }
            _ => Vec::new(),
        };
        let stmts = match af.get(2) {
            Some(PrsField::Node(n)) if !matches!(n.as_ref(), PrsNode::Null) => {
                collect_tree_node_list(doc, n)?
            }
            _ => Vec::new(),
        };

        let mut is_others = false;
        let mut choice_conds = Vec::new();
        for ch in choices {
            match lower_val(doc, &ch, vectors)? {
                LoweredVal::Others => {
                    is_others = true;
                }
                other_val => {
                    let eq = build_equality(sel_val.clone(), other_val)?;
                    choice_conds.push(eq);
                }
            }
        }

        let alt_cond = if is_others {
            None
        } else {
            let combined = mk_or_list(choice_conds);
            covered_conds.push(combined.clone());
            Some(combined)
        };

        let mut alt_env = base_env.clone();
        eval_stmt_list(
            doc,
            &stmts,
            vectors,
            seq,
            &mut alt_env,
            default_hold,
            visited_stmts,
        )?;
        alt_results.push((alt_cond, alt_env));
    }

    let mut all_targets: HashSet<String> = base_env.keys().cloned().collect();
    for (_, e) in &alt_results {
        all_targets.extend(e.keys().cloned());
    }

    let others_cond = if covered_conds.is_empty() {
        BoolExpr::Const(true)
    } else {
        mk_not(mk_or_list(covered_conds))
    };

    for target in all_targets {
        let mut terms = Vec::new();
        for (cond_opt, alt_env) in &alt_results {
            let val = alt_env
                .get(&target)
                .cloned()
                .unwrap_or(BoolExpr::Const(false));
            let c = cond_opt.clone().unwrap_or_else(|| others_cond.clone());
            terms.push(mk_and(c, val));
        }
        env.insert(target, mk_or_list(terms));
    }

    Ok(())
}

fn mk_not(e: BoolExpr) -> BoolExpr {
    match e {
        BoolExpr::Const(b) => BoolExpr::Const(!b),
        BoolExpr::Not(inner) => *inner,
        other => BoolExpr::Not(Box::new(other)),
    }
}

fn mk_and(a: BoolExpr, b: BoolExpr) -> BoolExpr {
    match (a, b) {
        (BoolExpr::Const(false), _) | (_, BoolExpr::Const(false)) => BoolExpr::Const(false),
        (BoolExpr::Const(true), x) | (x, BoolExpr::Const(true)) => x,
        (x, y) if x == y => x,
        (x, y) => BoolExpr::And(vec![x, y]),
    }
}

fn mk_or(a: BoolExpr, b: BoolExpr) -> BoolExpr {
    match (a, b) {
        (BoolExpr::Const(true), _) | (_, BoolExpr::Const(true)) => BoolExpr::Const(true),
        (BoolExpr::Const(false), x) | (x, BoolExpr::Const(false)) => x,
        (x, y) if x == y => x,
        (x, y) => BoolExpr::Or(vec![x, y]),
    }
}

fn mk_or_list(items: Vec<BoolExpr>) -> BoolExpr {
    let mut acc = BoolExpr::Const(false);
    for item in items {
        acc = mk_or(acc, item);
    }
    acc
}

fn mk_ite(cond: BoolExpr, then_e: BoolExpr, else_e: BoolExpr) -> BoolExpr {
    if then_e == else_e {
        return then_e;
    }
    mk_or(
        mk_and(cond.clone(), then_e),
        mk_and(mk_not(cond), else_e),
    )
}

fn extract_target_name(doc: &PrsDocument, node: &PrsNode) -> Result<String, PrsToPlaError> {
    let resolved = resolve_local(doc, node)
        .ok_or_else(|| PrsToPlaError::UnsupportedAst("unresolved target node".into()))?;
    let (class_name, fields) = as_object(resolved)
        .ok_or_else(|| PrsToPlaError::UnsupportedAst("target is not an object".into()))?;
    match class_name {
        "Var_expr" => {
            let sym_node = fields
                .get(2)
                .and_then(|f| match f {
                    PrsField::Node(n) => Some(n.as_ref()),
                    _ => None,
                })
                .ok_or_else(|| PrsToPlaError::UnsupportedAst("Var_expr missing symbol".into()))?;
            extract_target_name(doc, sym_node)
        }
        "Array_elem_expr" => {
            let arr_node = fields
                .get(2)
                .and_then(|f| match f {
                    PrsField::Node(n) => Some(n.as_ref()),
                    _ => None,
                })
                .ok_or_else(|| {
                    PrsToPlaError::UnsupportedAst("Array_elem_expr missing array".into())
                })?;
            let idx_node = fields
                .get(3)
                .and_then(|f| match f {
                    PrsField::Node(n) => Some(n.as_ref()),
                    _ => None,
                })
                .ok_or_else(|| {
                    PrsToPlaError::UnsupportedAst("Array_elem_expr missing index".into())
                })?;
            let base = extract_target_name(doc, arr_node)?;
            let idx = extract_int_literal(doc, idx_node)?;
            Ok(format!("{base}[{idx}]"))
        }
        "Variable_symbol" | "Array_variable" => first_opt_string(fields)
            .map(str::to_string)
            .ok_or_else(|| PrsToPlaError::UnsupportedAst("symbol missing name".into())),
        other => Err(PrsToPlaError::UnsupportedAst(format!(
            "expected Var_expr/Variable_symbol/Array_elem_expr, got {other}"
        ))),
    }
}

fn extract_int_literal(doc: &PrsDocument, node: &PrsNode) -> Result<u32, PrsToPlaError> {
    let resolved = resolve_local(doc, node)
        .ok_or_else(|| PrsToPlaError::UnsupportedAst("unresolved int literal".into()))?;
    let (class_name, fields) = as_object(resolved)
        .ok_or_else(|| PrsToPlaError::UnsupportedAst("int literal not object".into()))?;
    if class_name == "Literal_expr" {
        if let Some(PrsField::U32(v)) = fields.get(3) {
            return Ok(*v);
        }
    }
    Err(PrsToPlaError::UnsupportedAst(format!(
        "expected integer Literal_expr, got {class_name}"
    )))
}

fn lower_scalar_expr(
    doc: &PrsDocument,
    node: &PrsNode,
    vectors: &BTreeMap<String, Vec<String>>,
) -> Result<BoolExpr, PrsToPlaError> {
    match lower_val(doc, node, vectors)? {
        LoweredVal::Scalar(e) => Ok(e),
        other => Err(PrsToPlaError::UnsupportedAst(format!(
            "expected scalar boolean expression, got {other:?}"
        ))),
    }
}

fn lower_val(
    doc: &PrsDocument,
    node: &PrsNode,
    vectors: &BTreeMap<String, Vec<String>>,
) -> Result<LoweredVal, PrsToPlaError> {
    let resolved = resolve_local(doc, node)
        .ok_or_else(|| PrsToPlaError::UnsupportedAst("unresolved expression node".into()))?;
    let (class_name, fields) = as_object(resolved)
        .ok_or_else(|| PrsToPlaError::UnsupportedAst("expression is not an object".into()))?;

    match class_name {
        "Var_expr" => {
            let name = extract_target_name(doc, resolved)?;
            if let Some(bits) = vectors.get(&name) {
                Ok(LoweredVal::Vector(
                    bits.iter().cloned().map(BoolExpr::Var).collect(),
                ))
            } else {
                Ok(LoweredVal::Scalar(BoolExpr::Var(name)))
            }
        }
        "Array_elem_expr" => {
            let bit_name = extract_target_name(doc, resolved)?;
            Ok(LoweredVal::Scalar(BoolExpr::Var(bit_name)))
        }
        "Char_literal_expr" => {
            let ch = fields.get(3).and_then(|f| match f {
                PrsField::U8(v) => Some(*v as char),
                _ => None,
            });
            match ch {
                Some('1') => Ok(LoweredVal::Scalar(BoolExpr::Const(true))),
                Some('0') => Ok(LoweredVal::Scalar(BoolExpr::Const(false))),
                other => Err(PrsToPlaError::UnsupportedAst(format!(
                    "unsupported Char_literal_expr {other:?}"
                ))),
            }
        }
        "Literal_expr" => {
            if let Some(s) = first_opt_string(fields) {
                if s.eq_ignore_ascii_case("others") {
                    return Ok(LoweredVal::Others);
                }
                let trimmed = s.trim_matches('"');
                let mut bits = Vec::with_capacity(trimmed.len());
                for ch in trimmed.chars() {
                    match ch {
                        '1' => bits.push(BoolExpr::Const(true)),
                        '0' => bits.push(BoolExpr::Const(false)),
                        _ => {
                            return Err(PrsToPlaError::UnsupportedAst(format!(
                                "unsupported bit-string literal {s:?}"
                            )))
                        }
                    }
                }
                return Ok(LoweredVal::Vector(bits));
            }
            let type_is_null = matches!(
                fields.get(1),
                Some(PrsField::Node(n)) if matches!(n.as_ref(), PrsNode::Null)
            );
            if type_is_null {
                return Ok(LoweredVal::Others);
            }
            Err(PrsToPlaError::UnsupportedAst(
                "unsupported Literal_expr".into(),
            ))
        }
        "Aggregate_expr" => {
            let items = collect_node_list_from_field(doc, fields.get(2))?;
            if items.len() == 1 {
                lower_val(doc, &items[0], vectors)
            } else {
                let mut bits = Vec::with_capacity(items.len());
                for item in items {
                    bits.push(lower_scalar_expr(doc, &item, vectors)?);
                }
                Ok(LoweredVal::Vector(bits))
            }
        }
        "Binary_expr" => {
            // In vhdlfe `.prs`, a single-child Binary_expr wraps an operand in fields[4]
            // while fields[3] is Null.
            let lhs = fields.get(3).and_then(|f| match f {
                PrsField::Node(n) if !matches!(n.as_ref(), PrsNode::Null) => Some(n.as_ref()),
                _ => None,
            });
            let rhs = fields.get(4).and_then(|f| match f {
                PrsField::Node(n) if !matches!(n.as_ref(), PrsNode::Null) => Some(n.as_ref()),
                _ => None,
            });
            match (lhs, rhs) {
                (None, Some(inner)) => lower_val(doc, inner, vectors),
                (Some(inner), None) => lower_val(doc, inner, vectors),
                (Some(l), Some(r)) => {
                    let op_tag = fields.get(2).and_then(|f| match f {
                        PrsField::U32(v) => Some(*v),
                        _ => None,
                    });
                    let lv = lower_val(doc, l, vectors)?;
                    let rv = lower_val(doc, r, vectors)?;
                    match op_tag {
                        Some(0) | Some(328) => match (lv, rv) {
                            (LoweredVal::Scalar(le), LoweredVal::Scalar(re)) => {
                                Ok(LoweredVal::Scalar(BoolExpr::And(vec![le, re])))
                            }
                            _ => Err(PrsToPlaError::UnsupportedAst(
                                "non-scalar AND operand".into(),
                            )),
                        },
                        Some(1) | Some(329) => match (lv, rv) {
                            (LoweredVal::Scalar(le), LoweredVal::Scalar(re)) => {
                                Ok(LoweredVal::Scalar(BoolExpr::Or(vec![le, re])))
                            }
                            _ => Err(PrsToPlaError::UnsupportedAst(
                                "non-scalar OR operand".into(),
                            )),
                        },
                        Some(2) => match (lv, rv) {
                            (LoweredVal::Scalar(le), LoweredVal::Scalar(re)) => {
                                Ok(LoweredVal::Scalar(BoolExpr::Xor(vec![le, re])))
                            }
                            _ => Err(PrsToPlaError::UnsupportedAst(
                                "non-scalar XOR operand".into(),
                            )),
                        },
                        // ASCII '=' (61)
                        Some(61) => Ok(LoweredVal::Scalar(build_equality(lv, rv)?)),
                        // '/=' (not equal)
                        Some(62) | Some(268) => {
                            Ok(LoweredVal::Scalar(mk_not(build_equality(lv, rv)?)))
                        }
                        other => Err(PrsToPlaError::UnsupportedAst(format!(
                            "unknown Binary_expr op tag {other:?}"
                        ))),
                    }
                }
                (None, None) => Err(PrsToPlaError::UnsupportedAst(
                    "empty Binary_expr".to_string(),
                )),
            }
        }
        "Function_call" => {
            let op_node = fields
                .get(2)
                .and_then(|f| match f {
                    PrsField::Node(n) => Some(n.as_ref()),
                    _ => None,
                })
                .ok_or_else(|| {
                    PrsToPlaError::UnsupportedAst("Function_call missing operator".into())
                })?;
            let args_node = fields
                .get(3)
                .and_then(|f| match f {
                    PrsField::Node(n) => Some(n.as_ref()),
                    _ => None,
                })
                .ok_or_else(|| {
                    PrsToPlaError::UnsupportedAst("Function_call missing args".into())
                })?;

            let arg_nodes = collect_tree_node_list(doc, args_node)?;
            let mut args = Vec::with_capacity(arg_nodes.len());
            for arg in arg_nodes {
                args.push(lower_scalar_expr(doc, &arg, vectors)?);
            }

            let op_name = resolve_operator_name(doc, op_node)?;
            Ok(LoweredVal::Scalar(apply_gate_op(&op_name, args)?))
        }
        other => Err(PrsToPlaError::UnsupportedAst(format!(
            "unsupported expression class {other}"
        ))),
    }
}

fn build_equality(lhs: LoweredVal, rhs: LoweredVal) -> Result<BoolExpr, PrsToPlaError> {
    match (lhs, rhs) {
        (LoweredVal::Scalar(a), LoweredVal::Scalar(b)) => Ok(scalar_eq(a, b)),
        (LoweredVal::Vector(va), LoweredVal::Vector(vb)) => {
            if va.len() != vb.len() {
                return Err(PrsToPlaError::UnsupportedAst(format!(
                    "vector width mismatch in comparison: {} vs {}",
                    va.len(),
                    vb.len()
                )));
            }
            let mut acc = BoolExpr::Const(true);
            for (a, b) in va.into_iter().zip(vb) {
                acc = mk_and(acc, scalar_eq(a, b));
            }
            Ok(acc)
        }
        other => Err(PrsToPlaError::UnsupportedAst(format!(
            "incompatible equality operands {other:?}"
        ))),
    }
}

fn scalar_eq(a: BoolExpr, b: BoolExpr) -> BoolExpr {
    match (a, b) {
        (x, BoolExpr::Const(true)) | (BoolExpr::Const(true), x) => x,
        (x, BoolExpr::Const(false)) | (BoolExpr::Const(false), x) => mk_not(x),
        (x, y) => BoolExpr::Xnor(vec![x, y]),
    }
}

fn collect_node_list_from_field(
    doc: &PrsDocument,
    field: Option<&PrsField>,
) -> Result<Vec<PrsNode>, PrsToPlaError> {
    let Some(PrsField::Node(n)) = field else {
        return Err(PrsToPlaError::UnsupportedAst("missing Node field".into()));
    };
    let resolved = resolve_local(doc, n)
        .ok_or_else(|| PrsToPlaError::UnsupportedAst("unresolved list container".into()))?;
    let (_, fields) = as_object(resolved)
        .ok_or_else(|| PrsToPlaError::UnsupportedAst("list container not object".into()))?;
    for f in fields {
        if let PrsField::NodeList(items) = f {
            return Ok(items.clone());
        }
    }
    Err(PrsToPlaError::UnsupportedAst(
        "no NodeList found in container".into(),
    ))
}

fn collect_tree_node_list(
    doc: &PrsDocument,
    node: &PrsNode,
) -> Result<Vec<PrsNode>, PrsToPlaError> {
    let resolved = resolve_local(doc, node)
        .ok_or_else(|| PrsToPlaError::UnsupportedAst("unresolved Tree_node_list".into()))?;
    let (class_name, fields) = as_object(resolved)
        .ok_or_else(|| PrsToPlaError::UnsupportedAst("Tree_node_list not object".into()))?;
    if class_name == "Object_list" {
        for f in fields {
            if let PrsField::NodeList(items) = f {
                return Ok(items.clone());
            }
        }
    }
    for f in fields {
        if let PrsField::Node(inner) = f {
            if !matches!(inner.as_ref(), PrsNode::Null) {
                if let Some(inner_obj) = resolve_local(doc, inner) {
                    let (inner_cls, inner_fields) = as_object(inner_obj).ok_or_else(|| {
                        PrsToPlaError::UnsupportedAst("inner list not object".into())
                    })?;
                    if inner_cls == "Object_list" {
                        for inf in inner_fields {
                            if let PrsField::NodeList(items) = inf {
                                return Ok(items.clone());
                            }
                        }
                    }
                }
            }
        }
    }
    Err(PrsToPlaError::UnsupportedAst(
        "Tree_node_list missing Object_list".into(),
    ))
}

fn resolve_operator_name(doc: &PrsDocument, op_node: &PrsNode) -> Result<String, PrsToPlaError> {
    match doc.resolve(op_node) {
        ResolvedRef::Local(n) | ResolvedRef::LocalSubobject { node: n, .. } => {
            if let Some((_, fields)) = as_object(n) {
                if let Some(name) = first_opt_string(fields) {
                    return Ok(name.to_ascii_lowercase());
                }
            }
            Err(PrsToPlaError::UnsupportedAst(
                "local operator missing name".into(),
            ))
        }
        ResolvedRef::External {
            source_name,
            object_id,
            ..
        } => {
            // Known stdlogic.vif operator object IDs from Cypress Warp.
            let is_stdlogic = source_name
                .map(|s| s.to_ascii_lowercase().contains("stdlogic"))
                .unwrap_or(false);
            if is_stdlogic {
                let op = match object_id {
                    95 => "and",
                    96 => "or",
                    97 => "nand",
                    98 => "nor",
                    99 | 119 => "xor",
                    100 => "xnor",
                    101 | 130 => "not",
                    438 => "rising_edge",
                    439 => "falling_edge",
                    other => {
                        return Err(PrsToPlaError::UnsupportedAst(format!(
                            "unknown stdlogic.vif operator object_id {other}"
                        )))
                    }
                };
                return Ok(op.to_string());
            }
            Err(PrsToPlaError::UnsupportedAst(format!(
                "unknown external operator {:?}#{object_id}",
                source_name
            )))
        }
        other => Err(PrsToPlaError::UnsupportedAst(format!(
            "unresolved operator {other:?}"
        ))),
    }
}

fn apply_gate_op(op: &str, mut args: Vec<BoolExpr>) -> Result<BoolExpr, PrsToPlaError> {
    let op = op.trim_matches('"').to_ascii_lowercase();
    match op.as_str() {
        "and" => Ok(BoolExpr::And(args)),
        "or" => Ok(BoolExpr::Or(args)),
        "nand" => Ok(BoolExpr::Nand(args)),
        "nor" => Ok(BoolExpr::Nor(args)),
        "xor" => Ok(BoolExpr::Xor(args)),
        "xnor" => Ok(BoolExpr::Xnor(args)),
        "not" => {
            if args.len() != 1 {
                return Err(PrsToPlaError::UnsupportedAst(format!(
                    "not expected 1 argument, got {}",
                    args.len()
                )));
            }
            Ok(BoolExpr::Not(Box::new(args.remove(0))))
        }
        other => Err(PrsToPlaError::UnsupportedAst(format!(
            "unsupported gate operator {other:?}"
        ))),
    }
}

fn expr_to_sop(
    expr: &BoolExpr,
    nin: usize,
    input_index: &BTreeMap<&str, usize>,
) -> Result<Vec<Vec<Lit>>, PrsToPlaError> {
    match expr {
        BoolExpr::Const(true) => Ok(vec![vec![Lit::DontCare; nin]]),
        BoolExpr::Const(false) => Ok(Vec::new()),
        BoolExpr::Var(name) => {
            let idx = *input_index.get(name.as_str()).ok_or_else(|| {
                PrsToPlaError::UnsupportedAst(format!("unknown input signal {name:?}"))
            })?;
            let mut cube = vec![Lit::DontCare; nin];
            cube[idx] = Lit::One;
            Ok(vec![cube])
        }
        BoolExpr::Not(inner) => match inner.as_ref() {
            BoolExpr::Const(b) => Ok(if *b {
                Vec::new()
            } else {
                vec![vec![Lit::DontCare; nin]]
            }),
            BoolExpr::Var(name) => {
                let idx = *input_index.get(name.as_str()).ok_or_else(|| {
                    PrsToPlaError::UnsupportedAst(format!("unknown input signal {name:?}"))
                })?;
                let mut cube = vec![Lit::DontCare; nin];
                cube[idx] = Lit::Zero;
                Ok(vec![cube])
            }
            BoolExpr::Not(x) => expr_to_sop(x, nin, input_index),
            BoolExpr::And(args) => {
                let negated: Vec<BoolExpr> =
                    args.iter().cloned().map(|a| BoolExpr::Not(Box::new(a))).collect();
                expr_to_sop(&BoolExpr::Or(negated), nin, input_index)
            }
            BoolExpr::Or(args) => {
                let negated: Vec<BoolExpr> =
                    args.iter().cloned().map(|a| BoolExpr::Not(Box::new(a))).collect();
                expr_to_sop(&BoolExpr::And(negated), nin, input_index)
            }
            BoolExpr::Nand(args) => expr_to_sop(&BoolExpr::And(args.clone()), nin, input_index),
            BoolExpr::Nor(args) => expr_to_sop(&BoolExpr::Or(args.clone()), nin, input_index),
            BoolExpr::Xor(args) => expr_to_sop(&BoolExpr::Xnor(args.clone()), nin, input_index),
            BoolExpr::Xnor(args) => expr_to_sop(&BoolExpr::Xor(args.clone()), nin, input_index),
        },
        BoolExpr::Or(args) => {
            let mut acc = Vec::new();
            for arg in args {
                acc.extend(expr_to_sop(arg, nin, input_index)?);
            }
            Ok(acc)
        }
        BoolExpr::And(args) => {
            let mut acc = vec![vec![Lit::DontCare; nin]];
            for arg in args {
                let rhs = expr_to_sop(arg, nin, input_index)?;
                acc = sop_and(&acc, &rhs);
            }
            Ok(acc)
        }
        BoolExpr::Nand(args) => {
            expr_to_sop(&BoolExpr::Not(Box::new(BoolExpr::And(args.clone()))), nin, input_index)
        }
        BoolExpr::Nor(args) => {
            expr_to_sop(&BoolExpr::Not(Box::new(BoolExpr::Or(args.clone()))), nin, input_index)
        }
        BoolExpr::Xor(args) => {
            if args.is_empty() {
                return Ok(Vec::new());
            }
            let mut iter = args.iter();
            let first = iter.next().unwrap().clone();
            let mut cur = expr_to_sop(&first, nin, input_index)?;
            let mut cur_expr = first;
            for next in iter {
                let not_cur = expr_to_sop(
                    &BoolExpr::Not(Box::new(cur_expr.clone())),
                    nin,
                    input_index,
                )?;
                let next_sop = expr_to_sop(next, nin, input_index)?;
                let not_next =
                    expr_to_sop(&BoolExpr::Not(Box::new(next.clone())), nin, input_index)?;

                let mut combined = sop_and(&cur, &not_next);
                combined.extend(sop_and(&not_cur, &next_sop));
                cur = combined;
                cur_expr = BoolExpr::Xor(vec![cur_expr, next.clone()]);
            }
            Ok(cur)
        }
        BoolExpr::Xnor(args) => {
            if args.is_empty() {
                return Ok(vec![vec![Lit::DontCare; nin]]);
            }
            let mut iter = args.iter();
            let first = iter.next().unwrap().clone();
            let mut cur = expr_to_sop(&first, nin, input_index)?;
            let mut cur_expr = first;
            for next in iter {
                let not_cur = expr_to_sop(
                    &BoolExpr::Not(Box::new(cur_expr.clone())),
                    nin,
                    input_index,
                )?;
                let next_sop = expr_to_sop(next, nin, input_index)?;
                let not_next =
                    expr_to_sop(&BoolExpr::Not(Box::new(next.clone())), nin, input_index)?;

                let mut combined = sop_and(&cur, &next_sop);
                combined.extend(sop_and(&not_cur, &not_next));
                cur = combined;
                cur_expr = BoolExpr::Xnor(vec![cur_expr, next.clone()]);
            }
            Ok(cur)
        }
    }
}

fn sop_and(lhs: &[Vec<Lit>], rhs: &[Vec<Lit>]) -> Vec<Vec<Lit>> {
    let mut out = Vec::new();
    for lc in lhs {
        for rc in rhs {
            let mut merged = Vec::with_capacity(lc.len());
            let mut valid = true;
            for (&a, &b) in lc.iter().zip(rc.iter()) {
                match a.intersect(b) {
                    Some(lit) => merged.push(lit),
                    None => {
                        valid = false;
                        break;
                    }
                }
            }
            if valid {
                out.push(merged);
            }
        }
    }
    out
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::pla::{minimize_pla, Pla, PlaType};

    #[test]
    fn converts_test_prs_to_pla_and_minimizes_truth_table() {
        let bytes = include_bytes!("../warp_test/test.prs");
        let pla_text = prs_bytes_to_pla(bytes).expect("prs_bytes_to_pla should succeed on test.prs");

        let parsed = Pla::parse(&pla_text).expect("generated PLA should parse cleanly");
        assert_eq!(parsed.nin, 2);
        assert_eq!(parsed.nout, 1);
        assert_eq!(parsed.pla_type, PlaType::F);
        assert_eq!(parsed.input_labels.as_deref(), Some(&["a".to_string(), "b".to_string()][..]));
        assert_eq!(parsed.output_labels.as_deref(), Some(&["y".to_string()][..]));

        let minimized_text = minimize_pla(&pla_text).expect("minimize_pla should succeed");
        let minimized = Pla::parse(&minimized_text).expect("minimized PLA should parse cleanly");
        assert_eq!(minimized.nin, 2);
        assert_eq!(minimized.nout, 1);
        assert_eq!(minimized.on.len(), 1);

        let (in_str, out_str) = minimized.on.cubes()[0].to_pla_strings();
        assert_eq!(in_str, "11");
        assert_eq!(out_str, "1");
    }

    #[test]
    fn expands_complex_boolean_gates_to_sop() {
        let circuit = PrsCircuit {
            entity_name: Some("gates".into()),
            inputs: vec!["a".into(), "b".into()],
            outputs: vec!["y".into()],
            equations: BTreeMap::from([(
                "y".into(),
                BoolExpr::Xor(vec![BoolExpr::Var("a".into()), BoolExpr::Var("b".into())]),
            )]),
            pin_assignments: BTreeMap::new(),
        };
        let pla_text = circuit_to_pla(&circuit).expect("circuit_to_pla should succeed");
        let minimized = minimize_pla(&pla_text).expect("minimize_pla should succeed");
        let pla = Pla::parse(&minimized).expect("minimized PLA should parse");
        assert_eq!(pla.on.len(), 2);
    }

    #[test]
    fn converts_mux_when_prs_and_minimizes_truth_table() {
        let bytes = include_bytes!("../warp_test/mux_when.prs");
        let pla_text = prs_bytes_to_pla(bytes).expect("prs_bytes_to_pla should succeed on mux_when.prs");
        let parsed = Pla::parse(&pla_text).expect("mux_when PLA should parse");
        assert_eq!(parsed.nin, 6);
        assert_eq!(parsed.nout, 1);
        assert_eq!(
            parsed.input_labels.as_deref(),
            Some(
                &[
                    "sel[1]".to_string(),
                    "sel[0]".to_string(),
                    "d0".to_string(),
                    "d1".to_string(),
                    "d2".to_string(),
                    "d3".to_string(),
                ][..]
            )
        );
        assert_eq!(parsed.output_labels.as_deref(), Some(&["y".to_string()][..]));

        let minimized_text = minimize_pla(&pla_text).expect("minimize_pla should succeed");
        let minimized = Pla::parse(&minimized_text).expect("minimized mux_when PLA should parse");
        assert_eq!(minimized.on.len(), 4);

        let mut rows: Vec<(String, String)> = minimized
            .on
            .cubes()
            .iter()
            .map(|c| c.to_pla_strings())
            .collect();
        rows.sort();
        assert_eq!(
            rows,
            vec![
                ("001---".to_string(), "1".to_string()),
                ("01-1--".to_string(), "1".to_string()),
                ("10--1-".to_string(), "1".to_string()),
                ("11---1".to_string(), "1".to_string()),
            ]
        );
    }

    #[test]
    fn converts_decoder_proc_prs_and_minimizes_truth_table() {
        let bytes = include_bytes!("../warp_test/decoder_proc.prs");
        let pla_text =
            prs_bytes_to_pla(bytes).expect("prs_bytes_to_pla should succeed on decoder_proc.prs");
        let parsed = Pla::parse(&pla_text).expect("decoder_proc PLA should parse");
        assert_eq!(parsed.nin, 3);
        assert_eq!(parsed.nout, 4);
        assert_eq!(
            parsed.input_labels.as_deref(),
            Some(&["en".to_string(), "sel[1]".to_string(), "sel[0]".to_string()][..])
        );
        assert_eq!(
            parsed.output_labels.as_deref(),
            Some(
                &[
                    "y0".to_string(),
                    "y1".to_string(),
                    "y2".to_string(),
                    "y3".to_string(),
                ][..]
            )
        );

        let minimized_text = minimize_pla(&pla_text).expect("minimize_pla should succeed");
        let minimized =
            Pla::parse(&minimized_text).expect("minimized decoder_proc PLA should parse");
        assert_eq!(minimized.on.len(), 4);

        let mut rows: Vec<(String, String)> = minimized
            .on
            .cubes()
            .iter()
            .map(|c| c.to_pla_strings())
            .collect();
        rows.sort();
        assert_eq!(
            rows,
            vec![
                ("100".to_string(), "1000".to_string()),
                ("101".to_string(), "0100".to_string()),
                ("110".to_string(), "0010".to_string()),
                ("111".to_string(), "0001".to_string()),
            ]
        );
    }

    #[test]
    fn converts_dff_prs_and_exports_next_state_equation() {
        let prs_bytes = include_bytes!("../warp_test/dff.prs");
        let pla_text = prs_bytes_to_pla(prs_bytes).expect("dff.prs should convert to PLA");
        let parsed = Pla::parse(&pla_text).expect("dff PLA should parse");
        assert_eq!(
            parsed.input_labels.as_deref(),
            Some(&["rst".to_string(), "d".to_string()][..])
        );
        assert_eq!(
            parsed.output_labels.as_deref(),
            Some(&["q.d".to_string()][..])
        );

        let minimized_text = minimize_pla(&pla_text).expect("minimize_pla should succeed");
        let minimized = Pla::parse(&minimized_text).expect("minimized dff PLA should parse");
        let rows: Vec<(String, String)> = minimized
            .on
            .cubes()
            .iter()
            .map(|c| c.to_pla_strings())
            .collect();
        assert_eq!(rows, vec![("01".to_string(), "1".to_string())]);

        let eqn = crate::pla_to_eqn(&minimized_text).expect("pla_to_eqn should succeed");
        assert_eq!(eqn, "q.d = !rst & d;");
    }

    #[test]
    fn converts_counter_prs_and_exports_next_state_equations() {
        let prs_bytes = include_bytes!("../warp_test/counter.prs");
        let pla_text = prs_bytes_to_pla(prs_bytes).expect("counter.prs should convert to PLA");
        let parsed = Pla::parse(&pla_text).expect("counter PLA should parse");
        assert_eq!(
            parsed.input_labels.as_deref(),
            Some(
                &[
                    "en".to_string(),
                    "count[3]".to_string(),
                    "count[2]".to_string(),
                    "count[1]".to_string(),
                    "count[0]".to_string(),
                ][..]
            )
        );
        assert_eq!(
            parsed.output_labels.as_deref(),
            Some(
                &[
                    "count[3].d".to_string(),
                    "count[2].d".to_string(),
                    "count[1].d".to_string(),
                    "count[0].d".to_string(),
                ][..]
            )
        );

        let minimized_text = minimize_pla(&pla_text).expect("minimize_pla should succeed");
        let minimized = Pla::parse(&minimized_text).expect("minimized counter PLA should parse");
        assert_eq!(minimized.nin, 5);
        assert_eq!(minimized.nout, 4);

        let eqn = crate::pla_to_eqn(&minimized_text).expect("pla_to_eqn should succeed");
        assert!(eqn.contains("count[3].d = "));
        assert!(eqn.contains("count[0].d = "));

        // Verify truth table semantics of a 4-bit enabled up-counter over all 32 states:
        // next_val == if en == 1 { (cur + 1) & 0xf } else { cur }
        for state in 0u8..32 {
            let en = (state >> 4) & 1;
            let cur = state & 0x0f;
            let expected = if en == 1 { (cur + 1) & 0x0f } else { cur };
            let mut got = 0u8;
            for cube in minimized.on.cubes() {
                let inp = cube.input();
                let mut matches = true;
                for var in 0..5 {
                    let bit = ((state >> (4 - var)) & 1) == 1;
                    match inp.get(var) {
                        crate::cube::Part::One if !bit => {
                            matches = false;
                            break;
                        }
                        crate::cube::Part::Zero if bit => {
                            matches = false;
                            break;
                        }
                        _ => {}
                    }
                }
                if matches {
                    for out in 0..4 {
                        if cube.out_get(out) {
                            got |= 1 << (3 - out);
                        }
                    }
                }
            }
            assert_eq!(
                got, expected,
                "counter mismatch for en={en}, cur={cur:04b}: got={got:04b}, expected={expected:04b}"
            );
        }
    }
}
