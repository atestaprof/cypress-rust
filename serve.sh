#!/usr/bin/env bash
set -euo pipefail

# Sirve la raíz del repositorio para que www/index.html pueda importar ../pkg/espresso_rs.js
PORT="${1:-8080}"
ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

echo "Servidor local iniciado en:"
echo "  -> http://localhost:${PORT}/www/index.html"
echo ""
cd "${ROOT_DIR}"
exec python3 -m http.server "${PORT}"
