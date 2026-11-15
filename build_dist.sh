#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "${ROOT_DIR}"

echo "[1/4] Compilando paquete WebAssembly optimizado..."
wasm-pack build --target web --release -- --features wasm

echo "[2/4] Preparando carpeta dist/..."
rm -rf dist
mkdir -p dist/pkg

echo "[3/4] Copiando archivos estáticos y artefactos WASM..."
cp -R www/. dist/
cp pkg/espresso_rs.js pkg/espresso_rs_bg.wasm dist/pkg/

echo "[4/4] Ajustando rutas relativas en dist/index.html..."
sed 's|\.\./pkg/|./pkg/|g' dist/index.html > dist/index.html.tmp
mv dist/index.html.tmp dist/index.html

echo "✔ Distribución estática generada en: ${ROOT_DIR}/dist"
