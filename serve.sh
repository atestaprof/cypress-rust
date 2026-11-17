#!/usr/bin/env bash
set -euo pipefail

# Sirve la raíz del repositorio para que www/index.html pueda importar ../pkg/espresso_rs.js
PORT="${1:-8080}"
ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

if [[ ! -f "${ROOT_DIR}/pkg/espresso_rs.js" ]]; then
  echo "Error: No se encontró pkg/espresso_rs.js." >&2
  echo "Compila primero el paquete WebAssembly ejecutando:" >&2
  echo "  wasm-pack build --target web -- --features wasm" >&2
  exit 1
fi

if [[ ! -f "${ROOT_DIR}/pkg/espresso_rs.js" ]]; then
  echo "Error: No se encontró pkg/espresso_rs.js." >&2
  echo "Compila primero el paquete WebAssembly para evitar errores 404 en el navegador:" >&2
  echo "  wasm-pack build --target web -- --features wasm" >&2
  echo "O bien genera la distribución completa con:" >&2
  echo "  ./build_dist.sh" >&2
  exit 1
fi

echo "Servidor local iniciado en:"
echo "  -> http://localhost:${PORT}/www/index.html"
echo ""
cd "${ROOT_DIR}"
exec python3 -m http.server "${PORT}"
