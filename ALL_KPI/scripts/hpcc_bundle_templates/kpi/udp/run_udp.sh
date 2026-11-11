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
  run_udp.sh <kpi.json> [output_dir]
  run_udp.sh --hdf <input.h5> <output.h5> [output_dir]
  run_udp.sh zmq [port]
EOF
}

IMAGE_PATH="$SCRIPT_DIR/udp_kpi.simg"
bundle_ensure_file "$IMAGE_PATH"

run_udp_image() {
    # Existing UDP images may predate the SciPy dependency. The Plot image has
    # the complete UDP_KPI package and matching Python/SciPy; do not bind binary
    # extensions from a different Python version into the old UDP image.
    local runtime_bin fallback mode
    runtime_bin="$(bundle_runtime_bin)"
    if "$runtime_bin" exec "$IMAGE_PATH" python -c 'import scipy.optimize' >/dev/null 2>&1; then
        bundle_run_image "$IMAGE_PATH" "$@"
        return
    fi
    fallback="$BUNDLE_ROOT/kpi/int_plot/intplot_kpi.simg"
    bundle_ensure_file "$fallback"
    mode="$1"
    shift
    local -a args=("$runtime_bin" exec --bind "$BUNDLE_ROOT:$BUNDLE_ROOT" --env PYTHONPATH=/app)
    local mount_root
    for mount_root in /net /mnt /scratch; do
        [[ ! -d "$mount_root" ]] || args+=(--bind "$mount_root:$mount_root")
    done
    echo '[run_udp] Using compatible UDP package/SciPy in Interactive Plot image'
    if [[ "$mode" == 'zmq' ]]; then
        args+=("$fallback" python -m UDP_KPI.kpi_server zmq "$@")
    else
        args+=("$fallback" python -m UDP_KPI.kpi_server "$@")
    fi
    "${args[@]}"
}

case "${1:-}" in
    -h|--help|'')
        usage
        exit 0
        ;;
    zmq)
        PORT="${2:-5560}"
        echo "[run_udp] zmq_port=$PORT"
        run_udp_image zmq "$PORT"
        ;;
    --hdf)
        INPUT_HDF="$(bundle_abs_path "$2")"
        OUTPUT_HDF="$(bundle_abs_path "$3")"
        OUTPUT_DIR="${4:-}"
        if [[ -z "$OUTPUT_DIR" ]]; then
            OUTPUT_DIR="$(bundle_default_output_dir "$BUNDLE_ROOT" udp_kpi)"
        else
            OUTPUT_DIR="$(bundle_abs_path "$OUTPUT_DIR")"
            mkdir -p "$OUTPUT_DIR"
        fi
        bundle_ensure_file "$INPUT_HDF"
        bundle_ensure_file "$OUTPUT_HDF"
        echo "[run_udp] input=$INPUT_HDF"
        echo "[run_udp] output=$OUTPUT_HDF"
        echo "[run_udp] html_dir=$OUTPUT_DIR"
        run_udp_image hdf "$INPUT_HDF" "$OUTPUT_HDF" "$OUTPUT_DIR"
        ;;
    *)
        INPUT_JSON="$(bundle_abs_path "$1")"
        OUTPUT_DIR="${2:-}"
        if [[ -z "$OUTPUT_DIR" ]]; then
            OUTPUT_DIR="$(bundle_default_output_dir "$BUNDLE_ROOT" udp_kpi)"
        else
            OUTPUT_DIR="$(bundle_abs_path "$OUTPUT_DIR")"
            mkdir -p "$OUTPUT_DIR"
        fi
        bundle_ensure_file "$INPUT_JSON"
        echo "[run_udp] json=$INPUT_JSON"
        echo "[run_udp] html_dir=$OUTPUT_DIR"
        run_udp_image json "$INPUT_JSON" "$OUTPUT_DIR"
        ;;
esac
