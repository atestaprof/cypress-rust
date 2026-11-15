use std::collections::HashMap;
use std::io::{self, Cursor, Read, Seek};

#[derive(Debug, Clone)]
pub enum PrsNode {
    Object {
        class_name: String,
        class_id: u16,
        object_id: u32,
        fields: Vec<PrsField>,
    },
    Ref {
        file_id: u8,
        object_id: u32,
    },
    SubobjectRef {
        file_id: u8,
        object_id: u32,
        offset: u32,
    },
    Null,
    Eof,
}

#[derive(Debug, Clone)]
pub enum PrsField {
    U8(u8),
    U16(u16),
    U32(u32),
    OptString(Option<String>),
    IntArray(Vec<u32>),
    NodeList(Vec<PrsNode>),
    Node(Box<PrsNode>),
    TreeNodeHeader {
        line: u16,
        flags1: u8,
        file_idx: u16,
        col_or_id: u32,
        flags2: u8,
        extra_u16: u16,
        flags3: u8,
    },
}

#[derive(Debug, Clone)]
pub enum ResolvedRef<'a> {
    Local(&'a PrsNode),
    LocalSubobject {
        node: &'a PrsNode,
        offset: u32,
    },
    External {
        file_id: u8,
        source_name: Option<&'a str>,
        object_id: u32,
        offset: Option<u32>,
    },
    Null,
    Unresolved {
        file_id: u8,
        object_id: u32,
        offset: Option<u32>,
    },
}

#[derive(Debug, Clone)]
pub struct PrsDocument {
    pub roots: Vec<PrsNode>,
    pub objects: HashMap<(u8, u32), PrsNode>,
    pub source_files: Vec<String>,
}

impl PrsDocument {
    /// Parse a `.prs` binary buffer in memory (WASM-compatible via `Cursor<&[u8]>`).
    pub fn from_bytes(bytes: &[u8]) -> io::Result<Self> {
        Self::from_reader(Cursor::new(bytes))
    }

    /// Parse a `.prs` stream from any `Read + Seek` source.
    pub fn from_reader<R: Read + Seek>(reader: R) -> io::Result<Self> {
        let mut parser = PrsParser::new(reader);
        let mut roots = Vec::new();
        loop {
            match parser.read_pobject()? {
                PrsNode::Eof => break,
                node => roots.push(node),
            }
        }
        let source_files = extract_source_files(&roots);
        Ok(Self {
            roots,
            objects: parser.objects,
            source_files,
        })
    }

    pub fn get_object(&self, file_id: u8, object_id: u32) -> Option<&PrsNode> {
        self.objects.get(&(file_id, object_id))
    }

    pub fn source_name(&self, file_id: u8) -> Option<&str> {
        self.source_files.get(file_id as usize).map(String::as_str)
    }

    /// Resolve a `PrsNode` reference (`Ref`, `SubobjectRef`, `Object`, or `Null`).
    pub fn resolve<'a>(&'a self, node: &'a PrsNode) -> ResolvedRef<'a> {
        match node {
            PrsNode::Object { .. } => ResolvedRef::Local(node),
            PrsNode::Null | PrsNode::Eof => ResolvedRef::Null,
            PrsNode::Ref { file_id, object_id } => {
                if *file_id == 0 {
                    match self.objects.get(&(0, *object_id)) {
                        Some(obj) => ResolvedRef::Local(obj),
                        None => ResolvedRef::Unresolved {
                            file_id: 0,
                            object_id: *object_id,
                            offset: None,
                        },
                    }
                } else {
                    ResolvedRef::External {
                        file_id: *file_id,
                        source_name: self.source_name(*file_id),
                        object_id: *object_id,
                        offset: None,
                    }
                }
            }
            PrsNode::SubobjectRef {
                file_id,
                object_id,
                offset,
            } => {
                if *file_id == 0 {
                    match self.objects.get(&(0, *object_id)) {
                        Some(obj) => ResolvedRef::LocalSubobject {
                            node: obj,
                            offset: *offset,
                        },
                        None => ResolvedRef::Unresolved {
                            file_id: 0,
                            object_id: *object_id,
                            offset: Some(*offset),
                        },
                    }
                } else {
                    ResolvedRef::External {
                        file_id: *file_id,
                        source_name: self.source_name(*file_id),
                        object_id: *object_id,
                        offset: Some(*offset),
                    }
                }
            }
        }
    }

    pub fn objects_of_class(&self, class_name: &str) -> Vec<&PrsNode> {
        let mut out: Vec<&PrsNode> = self
            .objects
            .values()
            .filter(|n| matches!(n, PrsNode::Object { class_name: c, .. } if c == class_name))
            .collect();
        out.sort_by_key(|n| match n {
            PrsNode::Object { object_id, .. } => *object_id,
            _ => 0,
        });
        out
    }
}

fn extract_source_files(roots: &[PrsNode]) -> Vec<String> {
    let Some(PrsNode::Object {
        class_name, fields, ..
    }) = roots.first()
    else {
        return Vec::new();
    };
    if class_name != "Source_names" {
        return Vec::new();
    }
    let Some(PrsField::Node(arr_node)) = fields.get(1) else {
        return Vec::new();
    };
    let PrsNode::Object {
        class_name: arr_cls,
        fields: arr_fields,
        ..
    } = arr_node.as_ref()
    else {
        return Vec::new();
    };
    if arr_cls != "Object_array" {
        return Vec::new();
    }
    let Some(PrsField::NodeList(items)) = arr_fields.first() else {
        return Vec::new();
    };
    items
        .iter()
        .filter_map(|item| match item {
            PrsNode::Object {
                class_name, fields, ..
            } if class_name == "String" => match fields.first() {
                Some(PrsField::OptString(Some(s))) => Some(s.clone()),
                _ => None,
            },
            _ => None,
        })
        .collect()
}

pub struct PrsParser<R> {
    reader: R,
    classes: HashMap<u16, String>,
    pub objects: HashMap<(u8, u32), PrsNode>,
}

impl<R: Read + Seek> PrsParser<R> {
    pub fn new(reader: R) -> Self {
        Self {
            reader,
            classes: HashMap::new(),
            objects: HashMap::new(),
        }
    }

    fn read_u8(&mut self) -> io::Result<u8> {
        let mut buf = [0u8; 1];
        self.reader.read_exact(&mut buf)?;
        Ok(buf[0])
    }

    fn read_u16_be(&mut self) -> io::Result<u16> {
        let mut buf = [0u8; 2];
        self.reader.read_exact(&mut buf)?;
        Ok(u16::from_be_bytes(buf))
    }

    fn read_u32_be(&mut self) -> io::Result<u32> {
        let mut buf = [0u8; 4];
        self.reader.read_exact(&mut buf)?;
        Ok(u32::from_be_bytes(buf))
    }

    fn read_c_string(&mut self) -> io::Result<String> {
        let mut bytes = Vec::new();
        loop {
            let b = self.read_u8()?;
            if b == 0x00 {
                break;
            }
            bytes.push(b);
        }
        Ok(String::from_utf8_lossy(&bytes).into_owned())
    }

    /// `FUN_0044ccb0` / `FUN_0044cbd0`: 0x04 -> None, 0x05 -> Some(c_string)
    fn read_opt_c_string(&mut self) -> io::Result<Option<String>> {
        let tag = self.read_u8()?;
        match tag {
            0x04 => Ok(None),
            0x05 => Ok(Some(self.read_c_string()?)),
            _ => {
                let offset = self.reader.stream_position()?;
                Err(io::Error::new(
                    io::ErrorKind::InvalidData,
                    format!(
                        "Esperaba tag de string 0x04/0x05, hallado 0x{:02X} en offset 0x{:X}",
                        tag,
                        offset - 1
                    ),
                ))
            }
        }
    }

    /// `FUN_0044c890`: varint de 16 bits
    fn read_varint16(&mut self) -> io::Result<u16> {
        let b0 = self.read_u8()?;
        match b0 >> 6 {
            0 => Ok(b0 as u16),
            1 => {
                let b1 = self.read_u8()?;
                Ok((((b0 & 0x3f) as u16) << 8) | (b1 as u16))
            }
            _ => self.read_u16_be(),
        }
    }

    /// `FUN_0044c920`: varint de 32 bits
    fn read_varint32(&mut self) -> io::Result<u32> {
        let b0 = self.read_u8()?;
        match b0 >> 5 {
            0 => Ok(b0 as u32),
            1 => {
                let b1 = self.read_u8()?;
                Ok((((b0 & 0x1f) as u32) << 8) | (b1 as u32))
            }
            2 => {
                let b1 = self.read_u8()?;
                let b2 = self.read_u8()?;
                Ok((((b0 & 0x1f) as u32) << 16) | ((b1 as u32) << 8) | (b2 as u32))
            }
            3 => {
                let b1 = self.read_u8()?;
                let b2 = self.read_u8()?;
                let b3 = self.read_u8()?;
                Ok((((b0 & 0x1f) as u32) << 24)
                    | ((b1 as u32) << 16)
                    | ((b2 as u32) << 8)
                    | (b3 as u32))
            }
            _ => self.read_u32_be(),
        }
    }

    /// `FUN_0044cd00`: lee un puntero/objeto polimórfico (0x01, 0x02, 0x03, 0x04, 0x06, 0x1a)
    pub fn read_pobject(&mut self) -> io::Result<PrsNode> {
        let tag = match self.read_u8() {
            Ok(b) => b,
            Err(ref e) if e.kind() == io::ErrorKind::UnexpectedEof => return Ok(PrsNode::Eof),
            Err(e) => return Err(e),
        };

        match tag {
            0x01 | 0x02 => self.read_object_body(tag),
            0x03 => {
                let val = self.read_varint32()?;
                Ok(PrsNode::Ref {
                    file_id: ((val >> 24) & 0x7f) as u8,
                    object_id: val & 0x00ff_ffff,
                })
            }
            0x04 => Ok(PrsNode::Null),
            0x06 => {
                let val = self.read_varint32()?;
                let offset = self.read_varint32()?;
                Ok(PrsNode::SubobjectRef {
                    file_id: ((val >> 24) & 0x7f) as u8,
                    object_id: val & 0x00ff_ffff,
                    offset,
                })
            }
            0x1a => Ok(PrsNode::Eof),
            _ => {
                let offset = self.reader.stream_position()?;
                Err(io::Error::new(
                    io::ErrorKind::InvalidData,
                    format!(
                        "Tag desconocido 0x{:02X} en offset 0x{:X}",
                        tag,
                        offset - 1
                    ),
                ))
            }
        }
    }

    /// `FUN_0044d4b0`: objeto embebido por valor (solo 0x01 o 0x02)
    fn read_embedded(&mut self) -> io::Result<PrsNode> {
        let tag = self.read_u8()?;
        match tag {
            0x01 | 0x02 => self.read_object_body(tag),
            _ => {
                let offset = self.reader.stream_position()?;
                Err(io::Error::new(
                    io::ErrorKind::InvalidData,
                    format!(
                        "Esperaba 0x01/0x02 para objeto embebido, hallado 0x{:02X} en offset 0x{:X}",
                        tag,
                        offset - 1
                    ),
                ))
            }
        }
    }

    /// `FUN_0044d150`: cuerpo de definición/instancia de objeto
    fn read_object_body(&mut self, tag: u8) -> io::Result<PrsNode> {
        let (class_name, class_id) = if tag == 0x01 {
            let name = self.read_opt_c_string()?.ok_or_else(|| {
                io::Error::new(io::ErrorKind::InvalidData, "Nombre de clase nulo tras 0x01")
            })?;
            let cid = self.read_varint16()?;
            self.classes.insert(cid, name.clone());
            (name, cid)
        } else {
            let cid = self.read_varint16()?;
            let name = self.classes.get(&cid).cloned().ok_or_else(|| {
                io::Error::new(
                    io::ErrorKind::InvalidData,
                    format!("class_id {} no registrado", cid),
                )
            })?;
            (name, cid)
        };

        let object_id = self.read_varint32()?;
        let fields = self.deserialize_class(&class_name)?;
        let node = PrsNode::Object {
            class_name,
            class_id,
            object_id,
            fields,
        };
        self.objects.insert((0, object_id), node.clone());
        Ok(node)
    }

    fn read_tree_node_header(&mut self) -> io::Result<PrsField> {
        let line = self.read_varint16()?;
        let flags1 = self.read_u8()?;
        let file_idx = self.read_varint16()?;
        let col_or_id = self.read_varint32()?;
        let flags2 = self.read_u8()?;
        let extra_u16 = self.read_varint16()?;
        let flags3 = self.read_u8()?;
        Ok(PrsField::TreeNodeHeader {
            line,
            flags1,
            file_idx,
            col_or_id,
            flags2,
            extra_u16,
            flags3,
        })
    }

    fn push_vsymbol_fields(&mut self, fields: &mut Vec<PrsField>) -> io::Result<()> {
        fields.push(PrsField::OptString(self.read_opt_c_string()?));
        fields.push(PrsField::U16(self.read_varint16()?));
        fields.push(PrsField::U16(self.read_varint16()?));
        fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
        fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
        fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
        Ok(())
    }

    fn push_expr_base_fields(&mut self, fields: &mut Vec<PrsField>) -> io::Result<()> {
        fields.push(self.read_tree_node_header()?);
        fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
        Ok(())
    }

    fn push_variable_symbol_fields(&mut self, fields: &mut Vec<PrsField>) -> io::Result<()> {
        self.push_vsymbol_fields(fields)?;
        fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
        fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
        fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
        fields.push(PrsField::U16(self.read_varint16()?));
        fields.push(PrsField::U32(self.read_varint32()?));
        fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
        fields.push(PrsField::U16(self.read_varint16()?));
        fields.push(PrsField::U16(self.read_varint16()?));
        fields.push(PrsField::U8(self.read_u8()?));
        fields.push(PrsField::U8(self.read_u8()?));
        Ok(())
    }

    fn push_type_base_fields(&mut self, fields: &mut Vec<PrsField>) -> io::Result<()> {
        fields.push(PrsField::OptString(self.read_opt_c_string()?));
        fields.push(PrsField::U16(self.read_varint16()?));
        fields.push(PrsField::U16(self.read_varint16()?));
        fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
        fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
        fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
        Ok(())
    }

    fn read_null_term_list(&mut self) -> io::Result<Vec<PrsNode>> {
        let mut items = Vec::new();
        loop {
            let node = self.read_pobject()?;
            if matches!(node, PrsNode::Null) {
                break;
            }
            items.push(node);
        }
        Ok(items)
    }

    /// Despachador de campos por nombre de clase (extraído de Ghidra `vhdlfe.exe`)
    fn deserialize_class(&mut self, class_name: &str) -> io::Result<Vec<PrsField>> {
        let mut fields = Vec::new();
        match class_name {
            "String" => {
                fields.push(PrsField::OptString(self.read_opt_c_string()?));
            }
            "Int_array" => {
                let count = self.read_varint32()? as usize;
                let mut vals = Vec::with_capacity(count);
                for _ in 0..count {
                    vals.push(self.read_varint32()?);
                }
                fields.push(PrsField::IntArray(vals));
            }
            "Object_array" => {
                let count = self.read_varint32()? as usize;
                let mut items = Vec::with_capacity(count);
                for _ in 0..count {
                    items.push(self.read_pobject()?);
                }
                fields.push(PrsField::NodeList(items));
            }
            "Object_list" => {
                fields.push(PrsField::NodeList(self.read_null_term_list()?));
            }
            "Tree_node_list" => {
                fields.push(self.read_tree_node_header()?);
                fields.push(PrsField::Node(Box::new(self.read_embedded()?)));
            }
            "Source_names" => {
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::U32(self.read_varint32()?));
            }
            "Design_file" => {
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::Node(Box::new(self.read_embedded()?)));
                fields.push(PrsField::Node(Box::new(self.read_embedded()?)));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::OptString(self.read_opt_c_string()?));
            }
            "Symbol_table" => {
                // Base class (00431020): 1 PObject (Scope_symbol)
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                // Symbol_table (00412a50): u8, u8, 16 PObjects
                fields.push(PrsField::U8(self.read_u8()?));
                fields.push(PrsField::U8(self.read_u8()?));
                for _ in 0..16 {
                    fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                }
            }
            "Vsymbol" => {
                self.push_vsymbol_fields(&mut fields)?;
            }
            "Variable_symbol" => {
                self.push_variable_symbol_fields(&mut fields)?;
            }
            "Array_variable" => {
                self.push_variable_symbol_fields(&mut fields)?;
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::U32(self.read_varint32()?));
                fields.push(PrsField::U32(self.read_varint32()?));
                fields.push(PrsField::U32(self.read_varint32()?));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::U32(self.read_varint32()?));
                fields.push(PrsField::U32(self.read_varint32()?));
            }
            "Scope_symbol" => {
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::NodeList(self.read_null_term_list()?));
            }
            "Use_sym_table" | "Use_item" => {
                fields.push(PrsField::OptString(self.read_opt_c_string()?));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
            }
            "Use_all" => {
                fields.push(PrsField::OptString(self.read_opt_c_string()?));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::U32(self.read_varint32()?));
            }
            "Parent_type" => {
                self.push_vsymbol_fields(&mut fields)?;
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
            }
            "Field_list" => {
                self.push_vsymbol_fields(&mut fields)?;
                // Base 0041e610 (1 PObject) + Field_list (1 PObject)
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
            }
            "Port_syms" => {
                self.push_vsymbol_fields(&mut fields)?;
                // Base 0041e610 (1 PObject) + Port_syms (2 PObjects)
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
            }
            "Arch_subprog_body" => {
                fields.push(self.read_tree_node_header()?);
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::U32(self.read_varint32()?));
            }
            "Process_statement" => {
                fields.push(self.read_tree_node_header()?);
                fields.push(PrsField::OptString(self.read_opt_c_string()?));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
            }
            "Simple_assignment_statement" => {
                fields.push(self.read_tree_node_header()?);
                for _ in 0..5 {
                    fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                }
            }
            "Wait_statement" => {
                fields.push(self.read_tree_node_header()?);
                for _ in 0..3 {
                    fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                }
                fields.push(PrsField::U32(self.read_varint32()?));
            }
            "Var_expr" => {
                self.push_expr_base_fields(&mut fields)?;
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::U16(self.read_varint16()?));
            }
            "Aggregate_expr" => {
                self.push_expr_base_fields(&mut fields)?;
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
            }
            "Binary_expr" => {
                self.push_expr_base_fields(&mut fields)?;
                fields.push(PrsField::U32(self.read_varint32()?));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
            }
            "Function_call" => {
                self.push_expr_base_fields(&mut fields)?;
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::U32(self.read_varint32()?));
            }
            "Literal_expr" => {
                self.push_expr_base_fields(&mut fields)?;
                fields.push(PrsField::OptString(self.read_opt_c_string()?));
                fields.push(PrsField::U32(self.read_varint32()?));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
            }
            "Char_literal_expr" => {
                self.push_expr_base_fields(&mut fields)?;
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::U8(self.read_u8()?));
            }
            "Array_elem_expr" => {
                self.push_expr_base_fields(&mut fields)?;
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
            }
            "Attribute_name_expr" => {
                self.push_expr_base_fields(&mut fields)?;
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
            }
            "Dobject_list" => {
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
            }
            "Attribute" => {
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::U8(self.read_u8()?));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
            }
            "Range_type" => {
                self.push_type_base_fields(&mut fields)?;
                // Range_type (0041cba0)
                fields.push(PrsField::U32(self.read_varint32()?));
                fields.push(PrsField::U32(self.read_varint32()?));
                fields.push(PrsField::U16(self.read_varint16()?));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::U16(self.read_varint16()?));
            }
            "Constrained_type" => {
                self.push_type_base_fields(&mut fields)?;
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
            }
            "Array_type" => {
                self.push_type_base_fields(&mut fields)?;
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::U16(self.read_varint16()?));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::U32(self.read_varint32()?));
            }
            "If_statement" => {
                fields.push(self.read_tree_node_header()?);
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
            }
            "Elseif_clause" => {
                fields.push(self.read_tree_node_header()?);
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
            }
            "Case_statement" => {
                fields.push(self.read_tree_node_header()?);
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::U32(self.read_varint32()?));
                fields.push(PrsField::U8(self.read_u8()?));
                fields.push(PrsField::U8(self.read_u8()?));
            }
            "Case_statement_alternative" => {
                fields.push(self.read_tree_node_header()?);
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
                fields.push(PrsField::Node(Box::new(self.read_pobject()?)));
            }
            "Poly_head" => {
                let kind = self.read_varint32()?;
                fields.push(PrsField::U32(kind));
                if kind == 0 || kind == 1 {
                    fields.push(PrsField::OptString(self.read_opt_c_string()?));
                    fields.push(PrsField::OptString(self.read_opt_c_string()?));
                    fields.push(PrsField::OptString(self.read_opt_c_string()?));
                    if kind == 1 {
                        fields.push(PrsField::U32(self.read_varint32()?));
                    }
                }
            }
            other => {
                let offset = self.reader.stream_position()?;
                return Err(io::Error::new(
                    io::ErrorKind::InvalidData,
                    format!("Clase no soportada '{}' en offset 0x{:X}", other, offset),
                ));
            }
        }
        Ok(fields)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    const TEST_PRS: &[u8] = include_bytes!("../warp_test/test.prs");

    fn vsymbol_name(node: &PrsNode) -> Option<&str> {
        match node {
            PrsNode::Object { fields, .. } => match fields.first() {
                Some(PrsField::OptString(Some(name))) => Some(name.as_str()),
                _ => None,
            },
            _ => None,
        }
    }

    #[test]
    fn parses_test_prs_and_resolves_entity_ports_and_assignments() {
        let doc = PrsDocument::from_bytes(TEST_PRS).expect("test.prs should parse cleanly");

        // Source_names mapping (file_id 1 -> cypress.vif, file_id 4 -> stdlogic.vif)
        assert_eq!(
            doc.source_name(1),
            Some("$$REL$$lib\\common\\work\\cypress.vif")
        );
        assert_eq!(
            doc.source_name(4),
            Some("$$REL$$lib\\ieee\\work\\stdlogic.vif")
        );

        // Verify Port_syms for entity `test` and resolve its Scope_symbol ports (`a`, `b`, `y`)
        let port_syms = doc.objects_of_class("Port_syms");
        assert_eq!(port_syms.len(), 1);
        assert_eq!(vsymbol_name(port_syms[0]), Some("test"));

        let port_scope_ref = match port_syms[0] {
            PrsNode::Object { fields, .. } => match &fields[6] {
                PrsField::Node(n) => n.as_ref(),
                other => panic!("unexpected Port_syms field: {other:?}"),
            },
            _ => unreachable!(),
        };
        let ResolvedRef::Local(PrsNode::Object {
            class_name,
            fields: scope_fields,
            ..
        }) = doc.resolve(port_scope_ref)
        else {
            panic!("Port_syms scope reference should resolve locally");
        };
        assert_eq!(class_name, "Scope_symbol");

        let PrsField::NodeList(entity_items) = &scope_fields[2] else {
            panic!("Scope_symbol should contain NodeList");
        };
        let field_list = entity_items
            .iter()
            .find(|n| matches!(n, PrsNode::Object { class_name, .. } if class_name == "Field_list"))
            .expect("entity scope should contain Field_list");
        assert_eq!(vsymbol_name(field_list), Some("'test' port list"));

        let port_list_scope_ref = match field_list {
            PrsNode::Object { fields, .. } => match &fields[6] {
                PrsField::Node(n) => n.as_ref(),
                other => panic!("unexpected Field_list field: {other:?}"),
            },
            _ => unreachable!(),
        };
        let ResolvedRef::Local(PrsNode::Object {
            class_name: port_scope_cls,
            fields: port_scope_fields,
            ..
        }) = doc.resolve(port_list_scope_ref)
        else {
            panic!("Field_list scope reference should resolve locally");
        };
        assert_eq!(port_scope_cls, "Scope_symbol");

        let PrsField::NodeList(port_nodes) = &port_scope_fields[2] else {
            panic!("port Scope_symbol should contain NodeList");
        };
        let port_names: Vec<&str> = port_nodes.iter().filter_map(vsymbol_name).collect();
        assert_eq!(port_names, vec!["a", "b", "y"]);

        // Verify external reference in Var_expr resolves to stdlogic.vif (file_id == 4)
        let var_exprs = doc.objects_of_class("Var_expr");
        assert!(!var_exprs.is_empty());
        let first_type_ref = match var_exprs[0] {
            PrsNode::Object { fields, .. } => match &fields[1] {
                PrsField::Node(n) => n.as_ref(),
                other => panic!("unexpected Var_expr type field: {other:?}"),
            },
            _ => unreachable!(),
        };
        assert!(matches!(
            doc.resolve(first_type_ref),
            ResolvedRef::External {
                file_id: 4,
                source_name: Some("$$REL$$lib\\ieee\\work\\stdlogic.vif"),
                ..
            }
        ));

        // Verify Simple_assignment_statement (`y <= a and b;` on line 14) resolves target `y`
        let assignments = doc.objects_of_class("Simple_assignment_statement");
        assert_eq!(assignments.len(), 1);
        let target_ref = match assignments[0] {
            PrsNode::Object { fields, .. } => match &fields[1] {
                PrsField::Node(n) => n.as_ref(),
                other => panic!("unexpected assignment target field: {other:?}"),
            },
            _ => unreachable!(),
        };
        let ResolvedRef::Local(PrsNode::Object {
            class_name: tgt_cls,
            fields: tgt_fields,
            ..
        }) = doc.resolve(target_ref)
        else {
            panic!("assignment target should resolve to local Var_expr");
        };
        assert_eq!(tgt_cls, "Var_expr");

        let PrsField::Node(sym_ref) = &tgt_fields[2] else {
            panic!("Var_expr should reference target symbol");
        };
        let ResolvedRef::Local(sym_node) = doc.resolve(sym_ref) else {
            panic!("target symbol should resolve locally");
        };
        assert_eq!(vsymbol_name(sym_node), Some("y"));
    }
}
