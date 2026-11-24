#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
export BUNDLE_ROOT="${HPCC_BUNDLE_ROOT:-$(cd "$SCRIPT_DIR/../.." && pwd)}"
export HPCC_PROJECT_ROOT="${HPCC_PROJECT_ROOT:-$BUNDLE_ROOT/bundle_src}"
# shellcheck disable=SC1091
source "$BUNDLE_ROOT/bundle_common.sh"

usage() {
    cat <<'EOF'
Usage:
  run_intplot.sh <config.xml> <inputs.json> [output_dir] [plot_config.json ...]
  run_intplot.sh <config.xml> <inputs.json> <plot_config.json> [plot_config.json ...] [output_dir]

Every *.json optional argument is a plot config; they are merged in order
(per-stream union, later file wins per signal) by ResimHTMLReport.py.
EOF
}

if [[ $# -lt 2 ]]; then
    usage >&2
    exit 1
fi

IMAGE_PATH="$SCRIPT_DIR/intplot_kpi.simg"
bundle_ensure_file "$IMAGE_PATH"

CONFIG_XML="$(bundle_abs_path "$1")"
INPUT_JSON="$(bundle_abs_path "$2")"
OUTPUT_DIR=''
PLOT_CONFIGS=()

for argument in "${@:3}"; do
    if [[ "$argument" == *.json ]]; then
        PLOT_CONFIGS+=("$(bundle_abs_path "$argument")")
    elif [[ -z "$OUTPUT_DIR" ]]; then
        OUTPUT_DIR="$(bundle_abs_path "$argument")"
    else
        echo "Could not interpret optional argument: $argument" >&2
        exit 1
    fi
done

if [[ -z "$OUTPUT_DIR" ]]; then
    OUTPUT_DIR="$(bundle_default_output_dir "$BUNDLE_ROOT" interactive_plot)"
else
    mkdir -p "$OUTPUT_DIR"
fi

bundle_ensure_file "$CONFIG_XML"
bundle_ensure_file "$INPUT_JSON"
for plot_config in "${PLOT_CONFIGS[@]}"; do
    bundle_ensure_file "$plot_config"
done

echo "[run_intplot] config=$CONFIG_XML"
echo "[run_intplot] json=$INPUT_JSON"
echo "[run_intplot] output_dir=$OUTPUT_DIR"
if (( ${#PLOT_CONFIGS[@]} )); then
    echo "[run_intplot] plot_configs=${PLOT_CONFIGS[*]}"
    bundle_run_image "$IMAGE_PATH" "$CONFIG_XML" "$INPUT_JSON" "$OUTPUT_DIR" "${PLOT_CONFIGS[@]}"
    exit $?
fi

bundle_run_image "$IMAGE_PATH" "$CONFIG_XML" "$INPUT_JSON" "$OUTPUT_DIR"
