# espresso-rs (Release Candidate)

Reimplementación segura en Rust puro (100% compatible con `wasm32-unknown-unknown`, sin `unsafe`) del minimizador lógico heurístico **Berkeley Espresso 2.3** junto con un pipeline completo de síntesis inversa para archivos binarios `.prs` de Cypress Warp y generación de mapas de fusibles **JEDEC (JESD3-C)** con **Bit-Perfect Match** verificado frente al fitter propietario original (`c37kfit.exe`).

---

## Arquitectura del Pipeline

```text
  VHDL (.vhd)
      │  (vhdlfe.exe / frontend)
      ▼
  .prs (AST binario Cypress)
      │  src/prs_parser.rs
      ▼
  Circuito booleano (Puertos + Ecuaciones combinacionales / .d)
      │  src/prs_to_pla.rs
      ▼
  .pla (Berkeley PLA)
      │  src/espresso.rs  (expand → irredundant → reduce → make_sparse)
      ▼
  .pla minimizado
      ├──► src/pla_to_eqn.rs ──► Ecuaciones booleanas SOP (.eqn)
      └──► src/jedec.rs      ──► Mapa de fusibles JESD3-C (.jed)
```

---

## Características Soportadas

- **Parser binario `.prs` ([`src/prs_parser.rs`](src/prs_parser.rs)):**
  Decodifica el AST binario de Cypress (`PrsDocument`, `PrsNode`, `PrsField`), tablas de símbolos (`Port_syms`), referencias cruzadas (`Ref`, `SubobjectRef`) y nodos de expresiones.
- **Extracción de circuitos y expansión a `.pla` ([`src/prs_to_pla.rs`](src/prs_to_pla.rs)):**
  - **Lógica combinacional:** operadores booleanos (`AND`, `OR`, `NAND`, `NOR`, `XOR`, `XNOR`, `NOT`), literales y constantes.
  - **Lógica secuencial (Flip-Flops D):** detección de `rising_edge(clk)` / `clk'event and clk = '1'` en procesos, generando salidas de próximo estado (`.d`).
  - **Indexación de vectores:** soporte para `std_logic_vector`, indexación por bit (`sig(i)`), rangos y concatenaciones.
  - **Multiplexores y control condicional:** sentencias concurrentes `when ... else` y bloques secuenciales/combinacionales `if ... then ... elsif ... else` y `case ... is`.
- **Minimizador Espresso multi-salida ([`src/espresso.rs`](src/espresso.rs)):**
  Representación posicional en palabras de 64 bits ([`src/cube.rs`](src/cube.rs), [`src/cover.rs`](src/cover.rs)), soporte para covers `f`, `fd`, `fr` y `fdr` ([`src/pla.rs`](src/pla.rs)), y minimización heurística conjunta.
- **Exportación de ecuaciones y JEDEC ([`src/device.rs`](src/device.rs), [`src/jedec.rs`](src/jedec.rs)):**
  - [`src/pla_to_eqn.rs`](src/pla_to_eqn.rs): convierte el `.pla` minimizado en ecuaciones SOP legibles (`y = ...;`, `q.d = ...;`).
  - [`src/jedec.rs`](src/jedec.rs): genera archivos estándar JESD3-C (`\x02` STX, `NOTE`, `*QP`, `*QF`, `*F0`/`*F1`, bloques `*L`, checksum de fusibles `*C`, `\x03` ETX y checksum de transmisión de 16 bits) para **Lattice GAL16V8** (20 pines, 2194 fusibles), **Lattice GAL22V10** (24 pines, 5828 fusibles) y **Cypress CY37032VP44** (44 pines PLCC, 15034 fusibles con modelo físico denso, PIM y PTM steering).
- **Interfaz WebAssembly y Pin Planner ([`src/lib.rs`](src/lib.rs), [`www/index.html`](www/index.html)):**
  Ejecución 100% local en el navegador con carga de `.prs`/`.pla` por drag-and-drop, selector de dispositivo (`GAL16V8`, `GAL22V10`, `CY37032`), auto-completado de pines desde atributos VHDL (`prs_pin_map_wasm`), minimización instantánea y descarga directa de `.jed`.

---

## Directivas Nativas VHDL y Auto-Ruteo (`pin_numbers`)

El compilador y el Pin Planner web soportan de forma nativa las bibliotecas y atributos de asignación física de pines de Cypress Warp. Los usuarios pueden incluir en su código VHDL:

```vhdl
library ieee;
use ieee.std_logic_1164.all;
use work.cypress.all;

entity gal_native is
    port (
        a : in  std_logic;
        b : in  std_logic;
        y : out std_logic
    );
    attribute pin_numbers of gal_native : entity is "a:13 b:10 y:2";
end gal_native;
```

También se soportan atributos por señal (`attribute pin_numbers of clk : signal is "1";`). El parser `.prs` extrae los nodos `Dobject_list` / `Attribute` y auto-selecciona automáticamente los pines físicos en el CLI (`generate_jed`) y en el Pin Planner web (mostrando la etiqueta **Fijado por VHDL** y validando compatibilidad con el chip elegido).

---

## Validación Bit-Perfect Match (E2E)

El script [`verify_jedec.sh`](verify_jedec.sh) compila el diseño `.vhd` con `vhdlfe.exe` + `c37kfit.exe` (Cypress propietario) y lo compara bit a bit contra el pipeline puro en Rust (`prs_parser` → `prs_to_pla` → `espresso` → `jedec`), logrando **coincidencia exacta (`diff` código 0)** en la matriz completa de 15,034 fusibles y el checksum `*C` para `CY37032VP44` (`./verify_jedec.sh warp_test/gal_native.vhd`), además del soporte verificado para SPLDs `GAL16V8` y `GAL22V10`.

---

## Estructura del Proyecto

| Archivo | Descripción |
| :--- | :--- |
| `src/cube.rs` | Cubos posicionales (2 bits/variable) y cubos multivalor (`MvCube`) |
| `src/cover.rs` | Covers (`Cover`, `MvCover`), tautología, contención y complemento |
| `src/espresso.rs` | Algoritmos `expand`, `reduce`, `irredundant`, `make_sparse` |
| `src/pla.rs` | Parser y formateador de archivos Berkeley `.pla` |
| `src/prs_parser.rs` | Parser del formato binario `.prs` (AST de Cypress Warp) |
| `src/prs_to_pla.rs` | Evaluador simbólico del AST `.prs` a tabla de verdad `.pla` |
| `src/pla_to_eqn.rs` | Conversor de `.pla` a ecuaciones booleanas SOP |
| `src/jedec.rs` | Generador JESD3-C (`JedecFile`, `DeviceConfig`, `pla_to_jedec`) |
| `src/lib.rs` | API pública y endpoints `wasm-bindgen` |
| `www/index.html` | Aplicación web interactiva sin backend |

---

## Comandos de Desarrollo

### Ejecutar suite de pruebas unitarias e integración
```bash
cargo test
```

### Verificar linting con Clippy (objetivo WASM)
```bash
cargo clippy --target wasm32-unknown-unknown --features wasm
```

### Compilar el paquete WebAssembly
```bash
wasm-pack build --target web -- --features wasm
```

### Iniciar el servidor web local
```bash
./serve.sh
```
Luego abre `http://localhost:8080/www/index.html` en tu navegador (puedes pasar otro puerto como argumento: `./serve.sh 3000`).

---

## Despliegue a Producción

Para distribuir la aplicación web como un sitio estático autónomo (sin necesidad de compilar Rust por parte de los usuarios finales), genera la carpeta autocontenida `dist/` utilizando el script correspondiente a tu sistema operativo:

### Linux / macOS
```bash
./build_dist.sh
```

### Windows (PowerShell)
```powershell
.\build_dist.ps1
```

Ambos scripts compilan el binario WebAssembly optimizado para tamaño (`opt-level = "s"`, `lto = true`), copian la interfaz web y los artefactos (`espresso_rs.js` y `espresso_rs_bg.wasm`) dentro de `dist/` y reescriben las importaciones a rutas relativas (`./pkg/`).

### Publicar en GitHub Pages
1. Genera `dist/` ejecutando `./build_dist.sh` o `.\build_dist.ps1`.
2. Sube el contenido de la carpeta `dist/` a la rama `gh-pages` (o configura **GitHub Pages** desde Actions / rama estática apuntando al contenido de `dist/`).
3. Al abrir la URL publicada, toda la síntesis, minimización y generación JEDEC se ejecutará 100% en el navegador del estudiante mediante WebAssembly.
