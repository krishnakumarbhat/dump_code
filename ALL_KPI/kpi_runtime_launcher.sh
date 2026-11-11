#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
export BUNDLE_ROOT="${HPCC_BUNDLE_ROOT:-$SCRIPT_DIR}"
export HPCC_PROJECT_ROOT="${HPCC_PROJECT_ROOT:-$SCRIPT_DIR/bundle_src}"
# shellcheck disable=SC1091
source "$SCRIPT_DIR/bundle_common.sh"

usage() {
    cat <<'EOF'
Usage: kpi_runtime_launcher.sh --target <can_kpi|udp_kpi|interactive_plot> \
  [--source-target <can_kpi|udp_kpi>] \
  [--interactive-mode <disabled|enabled|only>] \
  [--input-mode <json|hdf|mf4|mf4_json>] \
  [--json-path <file.json>] \
  [--input-hdf <input.h5> --output-hdf <output.h5>] \
  [--config-xml <ConfigInteractivePlots.xml>] \
  [--optional-config <plot_config.json>] \
  [--output-dir <dir>] \
  [--port <zmq_port>] \
  [--detached]
EOF
}

TARGET=''
SOURCE_TARGET='udp_kpi'
INTERACTIVE_MODE='disabled'
INPUT_MODE='json'
JSON_PATH=''
INPUT_HDF=''
OUTPUT_HDF=''
OUTPUT_DIR=''
CONFIG_XML=''
OPTIONAL_CONFIG=''
PORT="${KPI_SERVER_PORT:-5560}"
DETACHED=0

while [[ $# -gt 0 ]]; do
    case "$1" in
        --target)
            TARGET="$2"
            shift 2
            ;;
        --source-target)
            SOURCE_TARGET="$2"
            shift 2
            ;;
        --interactive-mode)
            INTERACTIVE_MODE="$2"
            shift 2
            ;;
        --input-mode)
            INPUT_MODE="$2"
            shift 2
            ;;
        --json-path)
            JSON_PATH="$(bundle_abs_path "$2")"
            shift 2
            ;;
        --input-hdf)
            INPUT_HDF="$(bundle_abs_path "$2")"
            shift 2
            ;;
        --output-hdf)
            OUTPUT_HDF="$(bundle_abs_path "$2")"
            shift 2
            ;;
        --output-dir)
            OUTPUT_DIR="$(bundle_abs_path "$2")"
            shift 2
            ;;
        --config-xml)
            CONFIG_XML="$(bundle_abs_path "$2")"
            shift 2
            ;;
        --optional-config)
            OPTIONAL_CONFIG="$(bundle_abs_path "$2")"
            shift 2
            ;;
        --port)
            PORT="$2"
            shift 2
            ;;
        --detached)
            DETACHED=1
            shift
            ;;
        -h|--help)
            usage
            exit 0
            ;;
        *)
            echo "Unknown argument: $1" >&2
            usage >&2
            exit 1
            ;;
    esac
done

if [[ -z "$TARGET" ]]; then
    usage >&2
    exit 1
fi

if [[ "$SOURCE_TARGET" != 'can_kpi' ]]; then
    SOURCE_TARGET='udp_kpi'
fi
if [[ "$INTERACTIVE_MODE" != 'enabled' && "$INTERACTIVE_MODE" != 'only' ]]; then
    INTERACTIVE_MODE='disabled'
fi
if [[ "$TARGET" == 'interactive_plot' ]]; then
    INTERACTIVE_MODE='only'
fi
case "$INPUT_MODE" in hdf|mf4|mf4_json) ;; *) INPUT_MODE='json' ;; esac

if [[ -z "$OUTPUT_DIR" ]]; then
    OUTPUT_DIR="$(bundle_default_output_dir "$BUNDLE_ROOT" "$TARGET")"
else
    mkdir -p "$OUTPUT_DIR"
fi

if [[ -n "$OPTIONAL_CONFIG" ]]; then
    if [[ -d "$OPTIONAL_CONFIG" ]]; then
        echo "Optional config path is a directory; ignoring it: $OPTIONAL_CONFIG" >&2
        OPTIONAL_CONFIG=''
    else
        bundle_ensure_file "$OPTIONAL_CONFIG"
    fi
fi

# MF4 -> HDF with the same MUDP container call as the MUDP pipeline, then KPI runs on HDF.
convert_mf4_inputs() {
    local kpi_socket_port="$PORT"
    export HPCC_BUNDLE_ROOT="${HPCC_BUNDLE_ROOT:-$BUNDLE_ROOT}"
    if [[ -f "$BUNDLE_ROOT/hpcc_runtime.env" ]]; then
        # shellcheck disable=SC1091
        source "$BUNDLE_ROOT/hpcc_runtime.env"
    fi
    # The runtime file's PORT is the web UI port, not the KPI ZMQ socket.
    PORT="$kpi_socket_port"
    echo "[mf4] KPI socket port=$PORT (separate from web UI)"
    # CAN MF4 needs its own converter; the UDP MUDP container cannot read CAN logs.
    if [[ "$TARGET" == 'can_kpi' || ( "$TARGET" == 'interactive_plot' && "$SOURCE_TARGET" == 'can_kpi' ) ]]; then
        if [[ -z "${CAN_MF4_CONVERT_CMD:-}" ]]; then
            echo "CAN MF4 converter is not configured: set CAN_MF4_CONVERT_CMD in hpcc_runtime.env, or use HDF pairs for CAN KPI." >&2
            exit 1
        fi
    else
        local pipeline_config="${MUDP_PIPELINE_CONFIG:-}"
        if [[ -z "$pipeline_config" ]]; then
            if [[ "$BUNDLE_ROOT" == /mnt/* ]]; then
                pipeline_config="${HPCC_MUDP_SOUTHFIELD_CONFIG:-}"
            else
                pipeline_config="${HPCC_MUDP_KRAKOW_CONFIG:-}"
            fi
        fi
        if [[ -n "$pipeline_config" && -f "$pipeline_config" ]]; then
            local key value
            while IFS=: read -r key value || [[ -n "$key" ]]; do
                value="${value//$'\r'/}"
                value="${value#"${value%%[![:space:]]*}"}"
                value="${value%"${value##*[![:space:]]}"}"
                case "$key" in
                    mudp_simg) MUDP_SIMG="${MUDP_SIMG:-$value}" ;;
                    mudp_config) MUDP_CONFIG="${MUDP_CONFIG:-$value}" ;;
                esac
            done < "$pipeline_config"
        fi
        if [[ -z "${MUDP_SIMG:-}" || -z "${MUDP_CONFIG:-}" ]]; then
            echo "UDP MF4 conversion is not configured: set MUDP_SIMG (converter image) and MUDP_CONFIG (extraction XML) in hpcc_runtime.env. HDF input does not require conversion." >&2
            exit 1
        fi
        bundle_ensure_file "$MUDP_SIMG"
        bundle_ensure_file "$MUDP_CONFIG"
    fi
    local work="$OUTPUT_DIR/converted_hdf" py runtime_bin side
    py="$(bundle_python)"
    runtime_bin="$(bundle_runtime_bin)"
    local -a mudp_binds=(--bind "$OUTPUT_DIR:$OUTPUT_DIR")
    local mount_root
    for mount_root in /net /mnt /scratch; do
        [[ ! -d "$mount_root" ]] || mudp_binds+=(--bind "$mount_root:$mount_root")
    done
    mkdir -p "$work/input" "$work/output"
    if [[ "$TARGET" != 'can_kpi' && "$SOURCE_TARGET" != 'can_kpi' ]]; then
        # Site presets may be CSV-only. Change a job-owned XML, never the shared preset.
        "$py" - "$MUDP_CONFIG" "$work/extract_hdf.xml" <<'PY'
import sys, xml.etree.ElementTree as ET
source, target = sys.argv[1:]
tree = ET.parse(source)
root = tree.getroot()
mode = root.find('Data_Extraction_Mode')
if mode is None:
    sys.exit('MUDP XML has no Data_Extraction_Mode section')
for tag, value in [('HDF_MODE', '1'), ('CSV_MODE', '0'), ('CSV_DUMP_EXTRACTION', '0')]:
    node = mode.find(tag)
    if node is None:
        node = ET.SubElement(mode, tag)
    node.text = value
option = root.find('Output_Path_Options')
if option is None:
    option = ET.SubElement(root, 'Output_Path_Options')
option.text = 'SAME_AS_OUTPUT'
tree.write(target, encoding='utf-8', xml_declaration=True)
print('[mf4] Using job-local extraction XML with HDF_MODE=1, CSV_MODE=0')
PY
        MUDP_CONFIG="$work/extract_hdf.xml"
    fi
    "$py" - "$INPUT_MODE" "$JSON_PATH" "$INPUT_HDF" "$OUTPUT_HDF" "$work" <<'PY'
import json, sys
mode, json_path, in_mf4, out_mf4, work = sys.argv[1:]
if mode == 'mf4':
    pairs = ([in_mf4], [out_mf4])
else:
    data = json.load(open(json_path, encoding='utf-8'))
    if isinstance(data, list):
        pairs = ([d['input_path'] for d in data], [d['output_path'] for d in data])
    else:
        pairs = (data.get('INPUT_MF4') or data.get('INPUT_HDF') or [], data.get('OUTPUT_MF4') or data.get('OUTPUT_HDF') or [])
if not pairs[0] or len(pairs[0]) != len(pairs[1]):
    sys.exit('MF4 JSON needs equal-length INPUT_MF4 / OUTPUT_MF4 lists')
for side, files in zip(('input', 'output'), pairs):
    open(f'{work}/{side}.txt', 'w').write('\n'.join(files) + '\n')
PY
    for side in input output; do
        while IFS= read -r mf4_path; do
            [[ -n "$mf4_path" ]] || continue
            [[ "${mf4_path,,}" == *.mf4 ]] || { echo "Expected an MF4 path, got: $mf4_path" >&2; exit 1; }
            bundle_ensure_file "$mf4_path"
        done < "$work/$side.txt"
    done
    for side in input output; do
        echo "[mf4] converting $side MF4 -> HDF"
        if [[ "$TARGET" == 'can_kpi' || ( "$TARGET" == 'interactive_plot' && "$SOURCE_TARGET" == 'can_kpi' ) ]]; then
            # CAN_MF4_CONVERT_CMD template: {list} = file with one MF4 per line, {out} = output dir
            cmd="${CAN_MF4_CONVERT_CMD//\{list\}/$work/$side.txt}"
            cmd="${cmd//\{out\}/$work/$side}"
            mkdir -p "$work/$side"
            bash -c "$cmd" || { echo "CAN MF4 converter failed on $side" >&2; exit 1; }
        else
            "$runtime_bin" exec "${mudp_binds[@]}" "$MUDP_SIMG" /RUN_MUDP.sh "$MUDP_CONFIG" "$work/$side.txt" "$work/$side/"
        fi
    done
    JSON_PATH="$work/pairs.json"
    "$py" - "$work" "$JSON_PATH" <<'PY'
import glob, json, os, re, sys
work, out = sys.argv[1:]
# Remove only the replay version, not sensor/stream suffixes. Otherwise multiple
# sensor HDF files collapse to one dictionary entry and silently lose data.
def stem(p):
    name = os.path.splitext(os.path.basename(p))[0].lower()
    name = re.sub(r'_r[0-9a-z]{6,}(?=_|$)', '', name)
    return name.replace('_orcas', '_b05')
def index(side):
    result = {}
    for p in sorted(glob.glob(f'{work}/{side}/**/*', recursive=True)):
        if os.path.splitext(p)[1].lower() not in ('.h5', '.hdf5', '.hdf'):
            continue
        key = stem(p)
        if key in result:
            sys.exit(f'Ambiguous converted HDF pair: {result[key]} and {p}')
        result[key] = p
    return result
ins, outs = index('input'), index('output')
keys = sorted(set(ins) & set(outs))
if not keys:
    sys.exit('MF4 conversion produced no paired HDF files')
json.dump({'INPUT_HDF': [ins[k] for k in keys], 'OUTPUT_HDF': [outs[k] for k in keys]}, open(out, 'w'), indent=2)
print(f'[mf4] {len(keys)} HDF pair(s) ready: {out}')
PY
    INPUT_MODE='json'
}

if [[ "$INPUT_MODE" == 'mf4' || "$INPUT_MODE" == 'mf4_json' ]]; then
    convert_mf4_inputs
fi

if [[ "$INPUT_MODE" == 'json' ]]; then
    bundle_ensure_file "$JSON_PATH"
else
    bundle_ensure_file "$INPUT_HDF"
    bundle_ensure_file "$OUTPUT_HDF"
fi

if [[ "$INTERACTIVE_MODE" != 'disabled' ]]; then
    if [[ -z "$CONFIG_XML" ]]; then
        CONFIG_XML="$(bundle_default_config_xml "$BUNDLE_ROOT" "$SOURCE_TARGET")"
    fi
    bundle_ensure_file "$CONFIG_XML"
fi

TMP_FILES=()
UDP_PID=''

cleanup() {
    local file_path
    if [[ -n "$UDP_PID" ]]; then
        kill "$UDP_PID" >/dev/null 2>&1 || true
        wait "$UDP_PID" >/dev/null 2>&1 || true
    fi
    for file_path in "${TMP_FILES[@]:-}"; do
        rm -f "$file_path" >/dev/null 2>&1 || true
    done
}
trap cleanup EXIT INT TERM

pair_json_for_interactive() {
    if [[ "$INPUT_MODE" == 'json' ]]; then
        printf '%s\n' "$JSON_PATH"
        return 0
    fi

    local temp_json
    temp_json="$(bundle_make_pair_json "$INPUT_HDF" "$OUTPUT_HDF")"
    TMP_FILES+=("$temp_json")
    printf '%s\n' "$temp_json"
}

run_interactive_plot() {
    local config_path="$1"
    local inputs_json="$2"
    local target_output="$3"
    local -a command
    command=("$BUNDLE_ROOT/kpi/int_plot/run_intplot.sh" "$config_path" "$inputs_json" "$target_output")
    if [[ -n "$OPTIONAL_CONFIG" ]]; then
        command+=("$OPTIONAL_CONFIG")
    fi
    "${command[@]}"
}

wait_for_udp_port_or_exit() {
    local attempts="${HPCC_PORT_WAIT_ATTEMPTS:-90}"
    local delay="${HPCC_PORT_WAIT_DELAY_SECONDS:-2}"
    local attempt
    local status

    for attempt in $(seq 1 "$attempts"); do
        if bundle_wait_for_port 127.0.0.1 "$PORT" 1 0; then
            return 0
        fi
        if ! kill -0 "$UDP_PID" >/dev/null 2>&1; then
            if wait "$UDP_PID"; then
                status=0
            else
                status=$?
            fi
            echo "UDP KPI server exited before port $PORT became ready (status $status)." >&2
            if [[ "$status" == '0' ]]; then
                return 1
            fi
            return "$status"
        fi
        sleep "$delay"
    done

    return 1
}

case "$TARGET" in
    can_kpi)
        if [[ "$INTERACTIVE_MODE" == 'enabled' ]]; then
            local_json="$(pair_json_for_interactive)"
            # inplot_can.sh prefers the combined CAN KPI + Interactive Plot image
            # (kpi/can_intplot/canintplot_kpi.simg) and falls back to the sequential
            # run_can.sh + run_intplot.sh flow when it is not present.
            command=("$BUNDLE_ROOT/kpi/inplot_can.sh" --wait "$CONFIG_XML" "$local_json" "$OUTPUT_DIR")
            if [[ -n "$OPTIONAL_CONFIG" ]]; then
                command+=("$OPTIONAL_CONFIG")
            fi
            "${command[@]}"
            exit 0
        fi

        if [[ "$INPUT_MODE" == 'hdf' ]]; then
            "$BUNDLE_ROOT/kpi/can/run_can.sh" --hdf "$INPUT_HDF" "$OUTPUT_HDF" "$OUTPUT_DIR"
        else
            "$BUNDLE_ROOT/kpi/can/run_can.sh" "$JSON_PATH" "$OUTPUT_DIR"
        fi
        ;;
    udp_kpi)
        if [[ "$INTERACTIVE_MODE" == 'enabled' ]]; then
            local_json="$(pair_json_for_interactive)"
            if (( DETACHED )); then
                command=("$BUNDLE_ROOT/kpi/inplot_udp.sh" "$CONFIG_XML" "$local_json" "$OUTPUT_DIR" "$PORT")
                if [[ -n "$OPTIONAL_CONFIG" ]]; then
                    command+=("$OPTIONAL_CONFIG")
                fi
                "${command[@]}"
                exit 0
            fi
            "$BUNDLE_ROOT/kpi/udp/run_udp.sh" zmq "$PORT" &
            UDP_PID="$!"
            if ! wait_for_udp_port_or_exit; then
                echo "Timed out waiting for UDP KPI server on port $PORT." >&2
                exit 1
            fi
            bundle_set_container_env INTERACTIVE_PLOT_ENABLE_KPI 1
            bundle_set_container_env KPI_SERVER_HOST 127.0.0.1
            bundle_set_container_env KPI_SERVER_PORT "$PORT"
            run_interactive_plot "$CONFIG_XML" "$local_json" "$OUTPUT_DIR"
            exit 0
        fi

        if [[ "$INPUT_MODE" == 'hdf' ]]; then
            "$BUNDLE_ROOT/kpi/udp/run_udp.sh" --hdf "$INPUT_HDF" "$OUTPUT_HDF" "$OUTPUT_DIR"
        else
            "$BUNDLE_ROOT/kpi/udp/run_udp.sh" "$JSON_PATH" "$OUTPUT_DIR"
        fi
        ;;
    interactive_plot)
        local_json="$(pair_json_for_interactive)"
        run_interactive_plot "$CONFIG_XML" "$local_json" "$OUTPUT_DIR"
        ;;
    *)
        echo "Unsupported target: $TARGET" >&2
        exit 1
        ;;
esac
