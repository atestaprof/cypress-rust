$ErrorActionPreference = "Stop"

$RootDir = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $RootDir

Write-Host "[1/4] Compilando paquete WebAssembly optimizado..."
wasm-pack build --target web --release -- --features wasm
if ($LASTEXITCODE -ne 0) {
    throw "wasm-pack build falló con código $LASTEXITCODE"
}

Write-Host "[2/4] Preparando carpeta dist/..."
if (Test-Path "dist") {
    Remove-Item -Recurse -Force "dist"
}
New-Item -ItemType Directory -Force -Path "dist/pkg" | Out-Null

Write-Host "[3/4] Copiando archivos estáticos y artefactos WASM..."
Copy-Item -Path "www/*" -Destination "dist/" -Recurse -Force
Copy-Item -Path "pkg/espresso_rs.js", "pkg/espresso_rs_bg.wasm" -Destination "dist/pkg/" -Force

Write-Host "[4/4] Ajustando rutas relativas en dist/index.html..."
(Get-Content "dist/index.html" -Raw) -replace '\.\./pkg/', './pkg/' | Set-Content "dist/index.html" -NoNewline

Write-Host "Distribución estática generada en: $RootDir\dist"
