#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
export HPCC_RUNTIME_CONFIG="${HPCC_RUNTIME_CONFIG:-$SCRIPT_DIR/hpcc_runtime_5007.env}"
export HPCC_LOG_DIR="${HPCC_LOG_DIR:-$SCRIPT_DIR/logs_5007}"
exec bash "$SCRIPT_DIR/run_hpcc.sh" "$@"
