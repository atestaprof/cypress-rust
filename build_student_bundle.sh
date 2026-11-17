#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "${ROOT_DIR}"

BUNDLE_ROOT="${ROOT_DIR}/student_bundle"
OUT_DIR="${BUNDLE_ROOT}/vhd2prs"
ZIP_PATH="${BUNDLE_ROOT}/vhd2prs_portable.zip"

# Localizar fuentes mínimas desde warp_test/ (con fallback a galaxy/warp)
resolve_src() {
  local rel="$1"
  local alt="$2"
  if [[ -e "${ROOT_DIR}/warp_test/${rel}" ]]; then
    echo "${ROOT_DIR}/warp_test/${rel}"
  elif [[ -n "${alt}" && -e "${ROOT_DIR}/${alt}" ]]; then
    echo "${ROOT_DIR}/${alt}"
  else
    echo "Error: No se encontró ${rel} ni ${alt}" >&2
    exit 1
  fi
}

VHDLFE_SRC="$(resolve_src "vhdlfe.exe" "galaxy/warp/bin/vhdlfe.exe")"
VHDLMSG_SRC="$(resolve_src "vhdl.msg" "galaxy/warp/bin/vhdl.msg")"
WARPRC_SRC="$(resolve_src "warp.rc" "galaxy/warp/bin/warp.rc")"
IEEE_SRC="$(resolve_src "lib/ieee" "galaxy/warp/lib/ieee")"
COMMON_SRC="$(resolve_src "lib/common" "galaxy/warp/lib/common")"
EXAMPLE_SRC="${ROOT_DIR}/warp_test/gal_native.vhd"

if [[ ! -f "${EXAMPLE_SRC}" ]]; then
  echo "Error: No se encontró ${EXAMPLE_SRC}" >&2
  exit 1
fi

echo "[1/4] Preparando ${OUT_DIR}..."
rm -rf "${OUT_DIR}" "${ZIP_PATH}"
mkdir -p "${OUT_DIR}/lib"

echo "[2/4] Copiando binarios mínimos y bibliotecas (ieee, common)..."
cp "${VHDLFE_SRC}" "${OUT_DIR}/vhdlfe.exe"
cp "${VHDLMSG_SRC}" "${OUT_DIR}/vhdl.msg"
cp "${WARPRC_SRC}" "${OUT_DIR}/warp.rc"
cp -R "${IEEE_SRC}" "${OUT_DIR}/lib/ieee"
cp -R "${COMMON_SRC}" "${OUT_DIR}/lib/common"
cp "${EXAMPLE_SRC}" "${OUT_DIR}/ejemplo_compuerta.vhd"

# Limpiar .DS_Store si existiera
find "${OUT_DIR}" -name ".DS_Store" -delete

echo "[3/4] Generando scripts vhd2prs.bat, vhd2prs.sh y LEEME_ESTUDIANTES.txt..."

cat > "${OUT_DIR}/vhd2prs.bat" <<'BAT'
@echo off
setlocal enabledelayedexpansion

if "%~1"=="" (
    echo Uso: Arrastra un archivo .vhd sobre vhd2prs.bat o ejecuta:
    echo   vhd2prs.bat mi_diseno.vhd
    echo.
    pause
    exit /b 1
)

if not exist "%~1" (
    echo [ERROR] No se encontro el archivo: "%~1"
    echo.
    pause
    exit /b 1
)

set "BUNDLE_DIR=%~dp0"
if "%BUNDLE_DIR:~-1%"=="\" set "BUNDLE_DIR=%BUNDLE_DIR:~0,-1%"
set "CYPRESS_DIR=%BUNDLE_DIR%"
set "WARP_LIB=%BUNDLE_DIR%\lib"

pushd "%~dp1"
"%BUNDLE_DIR%\vhdlfe.exe" -t "%~n1" "%~nx1"
set "ERR=%ERRORLEVEL%"
popd

echo.
if "%ERR%"=="0" (
    echo [OK] Archivo generado: "%~dpn1.prs"
    echo      Ya puedes arrastrarlo a https://atestaprof.github.io/cypress-rust/
) else (
    echo [ERROR] vhdlfe.exe termino con codigo de error %ERR%.
)
echo.
pause
exit /b %ERR%
BAT

# Convertir vhd2prs.bat a CRLF para Windows
python3 -c '
p = "'"${OUT_DIR}/vhd2prs.bat"'"
data = open(p, "rb").read().replace(b"\r\n", b"\n").replace(b"\n", b"\r\n")
open(p, "wb").write(data)
'

cat > "${OUT_DIR}/vhd2prs.sh" <<'SH'
#!/usr/bin/env bash
set -euo pipefail

if [[ $# -lt 1 ]]; then
  echo "Uso: $0 <archivo.vhd>" >&2
  exit 1
fi

VHD_INPUT="$1"
if [[ ! -f "${VHD_INPUT}" ]]; then
  echo "Error: No se encontró el archivo VHDL: ${VHD_INPUT}" >&2
  exit 1
fi

if ! command -v wine >/dev/null 2>&1 || ! command -v winepath >/dev/null 2>&1; then
  echo "Error: 'wine' y 'winepath' son necesarios para ejecutar vhdlfe.exe en Linux/macOS." >&2
  exit 1
fi

BUNDLE_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
VHD_ABS="$(cd "$(dirname "${VHD_INPUT}")" && pwd)/$(basename "${VHD_INPUT}")"
VHD_DIR="$(dirname "${VHD_ABS}")"
VHD_FILE="$(basename "${VHD_ABS}")"
BASE_NAME="${VHD_FILE%.*}"

export CYPRESS_DIR
CYPRESS_DIR="$(winepath -w "${BUNDLE_DIR}")"
export WARP_LIB
WARP_LIB="$(winepath -w "${BUNDLE_DIR}/lib")"

(
  cd "${VHD_DIR}"
  MVK_CONFIG_LOG_LEVEL=0 WINEDEBUG=-all wine "${BUNDLE_DIR}/vhdlfe.exe" -t "${BASE_NAME}" "${VHD_FILE}" </dev/null
)

PRS_OUT="${VHD_DIR}/${BASE_NAME}.prs"
if [[ -f "${PRS_OUT}" ]]; then
  echo "✔ Generado: ${PRS_OUT}"
  echo "  Ya puedes arrastrarlo a https://atestaprof.github.io/cypress-rust/"
else
  echo "Error: vhdlfe.exe no generó ${PRS_OUT}" >&2
  exit 1
fi
SH
chmod +x "${OUT_DIR}/vhd2prs.sh"

cat > "${OUT_DIR}/LEEME_ESTUDIANTES.txt" <<'TXT'
====================================================================
  vhd2prs Portable - Compilador VHDL -> .PRS para GAL / CY37032
====================================================================

Este paquete portátil permite convertir tus archivos VHDL (.vhd) al
formato binario .prs sin instalar toda la suite Cypress Warp.

FLUJO DE TRABAJO EN 3 PASOS:

1. Escribe tu diseño VHDL con asignación de pines nativa:
   Incluye las librerías estándar y de Cypress al inicio de tu archivo:
     library ieee;
     use ieee.std_logic_1164.all;
     use work.cypress.all;

   Declara los pines físicos usando `attribute pin_numbers` (revisa el
   archivo incluido `ejemplo_compuerta.vhd` como plantilla).

2. Convierte el .vhd a .prs:
   - En Windows:
     Arrastra tu archivo .vhd y suéltalo directamente sobre `vhd2prs.bat`
     en el Explorador de Windows (o ejecuta `vhd2prs.bat tu_diseno.vhd`).
   - En Linux / macOS (con Wine instalado):
     Ejecuta `./vhd2prs.sh tu_diseno.vhd`.

   Esto generará `<tu_diseno>.prs` en la misma carpeta de tu `.vhd`.

3. Sintetiza y descarga tu JEDEC en la web:
   Abre https://atestaprof.github.io/cypress-rust/ en tu navegador,
   arrastra el archivo `.prs` generado, selecciona tu chip objetivo
   (GAL16V8, GAL22V10 o CY37032) y descarga tu archivo `.jed` listo
   para programar.
TXT

echo "[4/4] Comprimiendo ${ZIP_PATH}..."
(
  cd "${BUNDLE_ROOT}"
  zip -rq "$(basename "${ZIP_PATH}")" "vhd2prs"
)

echo "✔ Paquete portátil generado:"
ls -lh "${ZIP_PATH}"
