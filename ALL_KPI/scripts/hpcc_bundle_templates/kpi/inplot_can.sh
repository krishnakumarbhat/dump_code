#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
export BUNDLE_ROOT="${HPCC_BUNDLE_ROOT:-$(cd "$SCRIPT_DIR/.." && pwd)}"
export HPCC_PROJECT_ROOT="${HPCC_PROJECT_ROOT:-$BUNDLE_ROOT/bundle_src}"
# shellcheck disable=SC1091
source "$BUNDLE_ROOT/bundle_common.sh"

WAIT_FOR_COMPLETION=0
if [[ "${1:-}" == '--wait' ]]; then
    WAIT_FOR_COMPLETION=1
    shift
fi

if [[ $# -lt 2 || $# -gt 4 ]]; then
    echo 'Usage: inplot_can.sh [--wait] <config.xml> <inputs.json> [output_dir] [plot_config.json]' >&2
    exit 1
fi

CONFIG_XML="$(bundle_abs_path "$1")"
INPUT_JSON="$(bundle_abs_path "$2")"
OUTPUT_DIR=''
PLOT_CONFIG=''

if [[ $# -ge 3 && -n "${3:-}" ]]; then
    OUTPUT_DIR="$(bundle_abs_path "$3")"
fi
if [[ $# -ge 4 && -n "${4:-}" ]]; then
    PLOT_CONFIG="$(bundle_abs_path "$4")"
fi

bundle_ensure_file "$CONFIG_XML"
bundle_ensure_file "$INPUT_JSON"
if [[ -n "$PLOT_CONFIG" ]]; then
    bundle_ensure_file "$PLOT_CONFIG"
fi

if [[ -z "$OUTPUT_DIR" ]]; then
    OUTPUT_DIR="$(bundle_default_output_dir "$BUNDLE_ROOT" can_interactive)"
else
    mkdir -p "$OUTPUT_DIR"
fi

# Prefer the CAN Interactive Plot image. Its plot app accepts the full JSON batch
# and keeps CAN KPI integration inside the CAN-specific pipeline.
COMBINED_IMAGE="$SCRIPT_DIR/can_intplot/canintplot_kpi.simg"
USE_COMBINED=0
if [[ -f "$COMBINED_IMAGE" ]]; then
    USE_COMBINED=1
fi

(( WAIT_FOR_COMPLETION )) || bundle_require_tmux
RUN_DIR="$(bundle_user_run_dir can_interactive)"
SESSION_NAME="$(id -un 2>/dev/null || printf '%s' user)_can_intplot_$(bundle_timestamp)"
MAIN_EXIT="$RUN_DIR/can_intplot.exit"
MAIN_LOG="$RUN_DIR/can_intplot.log"
MAIN_SCRIPT="$RUN_DIR/can_intplot_window.sh"

if (( USE_COMBINED )); then
    cat > "$MAIN_SCRIPT" <<EOF
#!/usr/bin/env bash
set -uo pipefail
exec > >(tee -a "$MAIN_LOG") 2>&1
# shellcheck source=/dev/null
source "$BUNDLE_ROOT/bundle_common.sh"
echo '[inplot_can] combined CAN KPI + Interactive Plot run'
# The plot app is only a ZMQ client; the CAN KPI server must run beside it.
port=\$(( 20000 + (\$\$ % 20000) ))
bundle_set_container_env CAN_KPI_SERVER_HOST 127.0.0.1
bundle_set_container_env CAN_KPI_SERVER_PORT "\$port"
bundle_run_image --app server "$COMBINED_IMAGE" "\$port" > "$RUN_DIR/can_kpi_server.log" 2>&1 &
server_pid=\$!
trap 'kill "\$server_pid" >/dev/null 2>&1 || true' EXIT
if ! bundle_wait_for_port 127.0.0.1 "\$port" 90 1; then
  echo "[inplot_can] CAN KPI server failed on port \$port"; cat "$RUN_DIR/can_kpi_server.log"
  printf '1' > "$MAIN_EXIT"; exit 1
fi
bundle_run_image --app plot "$COMBINED_IMAGE" "$CONFIG_XML" "$INPUT_JSON" "$OUTPUT_DIR"${PLOT_CONFIG:+ "$PLOT_CONFIG"}
status=\$?
printf '%s' "\$status" > "$MAIN_EXIT"
exit "\$status"
EOF
else
    cat > "$MAIN_SCRIPT" <<EOF
#!/usr/bin/env bash
set -uo pipefail
exec > >(tee -a "$MAIN_LOG") 2>&1
echo '[inplot_can] experimental sequential CAN + Interactive Plot flow'
"$BUNDLE_ROOT/kpi/can/run_can.sh" "$INPUT_JSON" "$OUTPUT_DIR/can_kpi"
run_plot_cmd=("$BUNDLE_ROOT/kpi/int_plot/run_intplot.sh" "$CONFIG_XML" "$INPUT_JSON" "$OUTPUT_DIR/interactive_plot")
if [[ -n "$PLOT_CONFIG" ]]; then
  run_plot_cmd+=("$PLOT_CONFIG")
fi
"\${run_plot_cmd[@]}"
status=\$?
printf '%s' "\$status" > "$MAIN_EXIT"
exit "\$status"
EOF
fi

chmod +x "$MAIN_SCRIPT"
rm -f "$MAIN_EXIT"
# Slurm jobs pass --wait and compute nodes often lack tmux: run in the foreground.
if (( WAIT_FOR_COMPLETION )); then
    bash "$MAIN_SCRIPT"
    exit "$(cat "$MAIN_EXIT" 2>/dev/null || echo 1)"
fi
tmux kill-session -t "$SESSION_NAME" >/dev/null 2>&1 || true
tmux new-session -d -s "$SESSION_NAME" -n main "bash '$MAIN_SCRIPT'"

echo "tmux_session=$SESSION_NAME"
echo "run_dir=$RUN_DIR"
echo "log=$MAIN_LOG"
echo "attach=tmux attach -t $SESSION_NAME"

if (( WAIT_FOR_COMPLETION == 0 )); then
    exit 0
fi

while [[ ! -f "$MAIN_EXIT" ]]; do
    sleep 2
done
exit "$(cat "$MAIN_EXIT")"
