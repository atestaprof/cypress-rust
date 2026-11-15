#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
VHD_INPUT="${1:-warp_test/test.vhd}"

if [[ ! -f "${ROOT_DIR}/${VHD_INPUT}" && ! -f "${VHD_INPUT}" ]]; then
  echo "Error: No se encontró el archivo VHDL: ${VHD_INPUT}" >&2
  exit 1
fi

if [[ -f "${ROOT_DIR}/${VHD_INPUT}" ]]; then
  VHD_ABS="${ROOT_DIR}/${VHD_INPUT}"
else
  VHD_ABS="$(cd "$(dirname "${VHD_INPUT}")" && pwd)/$(basename "${VHD_INPUT}")"
fi

VHD_DIR="$(dirname "${VHD_ABS}")"
VHD_FILE="$(basename "${VHD_ABS}")"
BASE_NAME="${VHD_FILE%.*}"

WORK_DIR="$(mktemp -d "${TMPDIR:-/tmp}/verify_jedec.XXXXXX")"
trap 'rm -rf "${WORK_DIR}"' EXIT

PRS_PATH="${VHD_DIR}/${BASE_NAME}.prs"
REF_PLA="${WORK_DIR}/${BASE_NAME}_cyp.pla"
REF_JED="${WORK_DIR}/reference.jed"
GEN_JED="${WORK_DIR}/generated.jed"
REF_NORM="${WORK_DIR}/reference.norm"
GEN_NORM="${WORK_DIR}/generated.norm"

WARP_DIR="${ROOT_DIR}/galaxy/warp"
WARP_BIN="${WARP_DIR}/bin"

GREEN='\033[0;32m'
RED='\033[0;31m'
CYAN='\033[0;36m'
NC='\033[0m'

echo -e "${CYAN}=== Paso B (Pre-build) & Paso A: Flujo Propietario Cypress ===${NC}"
echo "Archivo VHDL: ${VHD_ABS}"

# 1) Ejecutar vhdlfe.exe vía Wine para generar el .prs
(
  cd "${VHD_DIR}"
  export CYPRESS_DIR
  CYPRESS_DIR="$(winepath -w "${WARP_DIR}")"
  MVK_CONFIG_LOG_LEVEL=0 WINEDEBUG=-all wine "${WARP_BIN}/vhdlfe.exe" -t "${BASE_NAME}" "${VHD_FILE}" </dev/null
)

if [[ ! -f "${PRS_PATH}" ]]; then
  echo -e "${RED}Error: vhdlfe.exe no generó ${PRS_PATH}${NC}" >&2
  exit 1
fi

echo -e "${CYAN}=== Paso B: Flujo Rust (prs_parser -> prs_to_pla -> espresso -> jedec) ===${NC}"
(
  cd "${ROOT_DIR}"
  if [[ "${BASE_NAME}" == "test" ]]; then
    cargo run --quiet --bin generate_jed -- "${PRS_PATH}" "${GEN_JED}" CY37032 --emit-cyp-pla "${REF_PLA}" --pin-map '{"a":13,"b":10,"y":2}'
  else
    cargo run --quiet --bin generate_jed -- "${PRS_PATH}" "${GEN_JED}" CY37032 --emit-cyp-pla "${REF_PLA}"
  fi
)

# 2) Ejecutar c37kfit.exe vía Wine desde galaxy/warp/bin para generar reference.jed
(
  cd "${WARP_BIN}"
  REF_PLA_WIN="$(winepath -w "${REF_PLA}")"
  REF_JED_WIN="$(winepath -w "${REF_JED}")"
  REF_RPT_WIN="$(winepath -w "${WORK_DIR}/reference.rpt")"
  MVK_CONFIG_LOG_LEVEL=0 WINEDEBUG=-all wine ./c37kfit.exe "${REF_PLA_WIN}" -OUT "${REF_JED_WIN}" -RPT "${REF_RPT_WIN}" </dev/null >/dev/null
)

if [[ ! -f "${REF_JED}" ]]; then
  echo -e "${RED}Error: c37kfit.exe no generó ${REF_JED}${NC}" >&2
  exit 1
fi

echo -e "${CYAN}=== Paso C: Comparación JEDEC (*L y *C) ===${NC}"

# Extraer mapa completo de 15034 fusibles (aplicando *F0/*F1 y bloques *L/L<addr>) y checksum *C
extract_jedec_core() {
  python3 - "$1" <<'PY'
import re, sys
text = open(sys.argv[1], 'r', encoding='latin-1').read().replace('\r', '')
qf_m = re.search(r'\*?QF(\d+)\*', text)
qf = int(qf_m.group(1)) if qf_m else 15034
f_m = re.search(r'\*?F([01])\*', text)
default_bit = f_m.group(1) if f_m else '1'
fuses = [default_bit] * qf

# Parse each *L<addr> ...* or L<addr> ...* field (stripping *Note:...* comments)
for m in re.finditer(r'(?:^|\n|\*)\s*\*?L(\d+)\s+([01\s]+?)\s*(?=\*)', text):
    addr = int(m.group(1))
    bits = re.sub(r'\s+', '', m.group(2))
    for i, b in enumerate(bits):
        if addr + i < qf:
            fuses[addr + i] = b

# Also handle Cypress multi-line L<addr> blocks where a line has bits followed by *Note:
lines = text.splitlines()
cur_addr = None
for line in lines:
    s = line.strip()
    m_start = re.match(r'^\*?L(\d+)\s*(.*)$', s)
    if m_start:
        cur_addr = int(m_start.group(1))
        rest = m_start.group(2)
        if '*' in rest:
            rest = rest.split('*', 1)[0]
        bits = re.sub(r'[^01]', '', rest)
        for b in bits:
            if cur_addr < qf:
                fuses[cur_addr] = b
                cur_addr += 1
        if '*' in m_start.group(2) and not m_start.group(2).strip().endswith('*Note:'):
            if '*Note:' not in m_start.group(2):
                cur_addr = None
        continue
    if cur_addr is not None:
        if s.startswith('*') or s.startswith('C') or s.startswith('\x03'):
            cur_addr = None
            continue
        bits_part = s.split('*', 1)[0]
        bits = re.sub(r'[^01]', '', bits_part)
        if not bits:
            cur_addr = None
            continue
        for b in bits:
            if cur_addr < qf:
                fuses[cur_addr] = b
                cur_addr += 1
        if '*' in s and '*Note:' not in s:
            cur_addr = None

c_m = re.search(r'(?:^|\n|\*)\*?C([0-9A-Fa-f]{4})\*', text)
cksum = c_m.group(1).upper() if c_m else '0000'
flat = ''.join(fuses)
for i in range(0, len(flat), 78):
    print(f"{i:05d}: {flat[i:i+78]}")
print(f"C{cksum}*")
PY
}

extract_jedec_core "${REF_JED}" > "${REF_NORM}"
extract_jedec_core "${GEN_JED}" > "${GEN_NORM}"

if diff -u "${REF_NORM}" "${GEN_NORM}"; then
  echo -e "${GREEN}✔ ÉXITO: reference.jed y generated.jed coinciden exactamente en matriz *L y checksum *C.${NC}"
  exit 0
else
  echo -e "${RED}✘ DIFERENCIAS DETECTADAS entre reference.jed (Cypress) y generated.jed (Rust).${NC}"
  exit 1
fi
