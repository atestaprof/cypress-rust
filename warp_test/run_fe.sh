#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

export CYPRESS_DIR="$(winepath -w "$SCRIPT_DIR")"
wine vhdlfe.exe -t test test.vhd
