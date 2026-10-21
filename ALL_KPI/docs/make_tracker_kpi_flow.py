"""Generate the Tracker-KPI I/O flow diagram (HTML) for the Desktop.

Source of truth (read-only):
  ALL_KPI/KPI/UDP_KPI/kpi_server.py
  ALL_KPI/KPI/UDP_KPI/a_persistence_layer/hdf_wrapper.py
  ALL_KPI/KPI/UDP_KPI/a_persistence_layer/kpi_hdf_parser.py
  ALL_KPI/KPI/UDP_KPI/b_data_storage/kpi_data_model_storage.py
  ALL_KPI/KPI/UDP_KPI/b_data_storage/kpi_config_storage.py
  ALL_KPI/KPI/UDP_KPI/c_business_layer/kpi_factory.py
  ALL_KPI/KPI/UDP_KPI/c_business_layer/tracker_matching_kpi.py
  ALL_KPI/KPI/UDP_KPI/d_presentation_layer/kpi_html_gen.py

Usage:  python make_tracker_kpi_flow.py [output.html]
"""
from __future__ import annotations

import json
import os
import sys

DEFAULT_OUT = r"C:\Users\ouymc2\Desktop\Tracker_KPI_IO_Flow_Diagram.html"

# --------------------------------------------------------------------------
# Nodes:  id, step, lane, title, file:line, IN, OUT, note
# --------------------------------------------------------------------------
LANES = [
    ("L0", "ENTRY &amp; ORCHESTRATION", "#3b1f5e"),
    ("L1", "PERSISTENCE &mdash; HDF5 READ", "#1f4e5f"),
    ("L2", "DATA STORAGE &mdash; CONTAINER", "#1f4e2e"),
    ("L3", "BUSINESS &mdash; TRACKER KPI", "#5f3a1f"),
    ("L4", "PRESENTATION &mdash; PLOTS + HTML", "#5f1f3a"),
    ("L5", "OUTPUTS", "#2e2e2e"),
]

NODES = [
    # ---- L0 ----
    dict(id="n_zmq", step="1", lane="L0", title="ZMQ REP socket (tcp://*:5555)",
         src="UDP_KPI/kpi_server.py:65  start()",
         io="IN: protobuf bytes (zlib-free wire)<br>OUT: protobuf bytes",
         note="Blocks on recv(); a raw <code>b'\\n\\x04ping'</code> short-circuits to a "
              "<code>PongMessage</code> without touching HDF5."),
    dict(id="n_req", step="2", lane="L0", title="RequestMessage.ParseFromString",
         src="UDP_KPI/kpi_server.py:139",
         io="IN: <code>sensor_id</code>, <code>base_name</code>, input/output file paths<br>"
            "OUT: populated request object",
         note="Falls back to an error <code>ReplyMessage</code> on any exception."),
    dict(id="n_handle", step="3", lane="L0", title="_handle_sensor_data_ready_generate_only()",
         src="UDP_KPI/kpi_server.py:144",
         io="IN: RequestMessage<br>OUT: <code>html_path</code> (str)",
         note="The only path that reaches the KPI engine."),

    # ---- L1 ----
    dict(id="n_parse", step="4", lane="L1", title="parse_for_kpi()",
         src="UDP_KPI/a_persistence_layer/hdf_wrapper.py:954",
         io="IN: sensor_id, input_file_path, output_dir, base_name, kpi_subdir, output_file_path<br>"
            "OUT: output_file_path (str)",
         note="Normalises paths, <code>ensure_dir(output_dir)</code>, then raises "
              "<code>ValueError</code> if any required field is empty."),
    dict(id="n_wrapper", step="5", lane="L1", title="KPIHDFWrapper(KPIProcessingConfig)",
         src="UDP_KPI/a_persistence_layer/hdf_wrapper.py:971",
         io="IN: KPIProcessingConfig<br>OUT: h5py <code>File</code> handles (input + output)",
         note="Sets the umask, opens both HDF5 files and builds one "
              "<code>KPI_DataModelStorage</code> per side."),
    dict(id="n_parser", step="6", lane="L1", title="KPIHDFParser.parse() &mdash; DFS traversal",
         src="UDP_KPI/a_persistence_layer/kpi_hdf_parser.py:57",
         io="IN: h5py.Group, storage, header_names<br>OUT: populated storage",
         note="Depth-first, <b>pre-order</b>: the group is visited before its children, "
              "datasets of the group are stored, then child groups recurse."),
    dict(id="n_parsegrp", step="7", lane="L1", title="parse_grp() &mdash; stream + signal filter",
         src="UDP_KPI/a_persistence_layer/kpi_hdf_parser.py:96",
         io="IN: h5py.Group<br>OUT: list of (dataset_name, dataset) to store",
         note="Depth-2 groups whose name is not a known stream are skipped with their whole "
              "subtree. <code>canonical_stream_name()</code> maps "
              "<code>OBJECT_LIST_STREAM &rarr; TRACKER_STREAM</code>. Only names present in "
              "<code>valid_names</code> (config keys + aliases) survive."),
    dict(id="n_setval", step="8", lane="L1", title="storage.set_value(dataset, signal_name, grp_name)",
         src="UDP_KPI/b_data_storage/kpi_data_model_storage.py:228",
         io="IN: h5py.Dataset (n_scans, n_slots), signal name, group name<br>"
            "OUT: storage key (str)",
         note="Parent/child discipline: the first signal of a group creates the parent "
              "key <code>\"{parent}_None\"</code>; later signals become children "
              "<code>\"{parent}_{child}\"</code>."),
    dict(id="n_align", step="9", lane="L1", title="_align_dataset_rows()",
         src="UDP_KPI/b_data_storage/kpi_data_model_storage.py:206",
         io="IN: dataset, selected/missing index sets<br>OUT: aligned dataset",
         note="Applies the selected-index subset, or drops missing indices. Without "
              "either, the dataset is returned untouched."),
    dict(id="n_proc", step="10", lane="L1", title="_process_dataset() + child append",
         src="UDP_KPI/b_data_storage/kpi_data_model_storage.py:323 / 296",
         io="IN: aligned dataset, key_stream, key_grp<br>"
            "OUT: <code>_data_container[scan_idx][grp][signal]</code> rows",
         note="Rows are rounded to 2 decimals. Length mismatches (heterogeneous HDFs, e.g. "
              "CCA 283 vs R11 570) are truncated or padded rather than dropping the signal."),

    # ---- L2 ----
    dict(id="n_container", step="11", lane="L2", title="_data_container &mdash; the scan-indexed cube",
         src="UDP_KPI/b_data_storage/kpi_data_model_storage.py:53",
         io="IN: (scan_idx, grp_idx, signal_idx)<br>"
            "OUT: np.ndarray row of n_slots values",
         note="<code>dict[scan_idx] &rarr; list[group] &rarr; list[signal] &rarr; ndarray(n_slots)</code>. "
              "One entry per scan, per group, per signal."),
    dict(id="n_maps", step="12", lane="L2", title="_signal_to_value / _value_to_signal",
         src="UDP_KPI/b_data_storage/kpi_data_model_storage.py:309",
         io="IN: signal_name, grp_name, key<br>OUT: <code>{grp_name: key}</code> mapping",
         note="Reverse index used by <code>get_value()</code> to locate a signal's slot "
              "without scanning the whole cube."),
    dict(id="n_getval", step="13", lane="L2", title="KPI_DataModelStorage.get_value(data, signal_name)",
         src="UDP_KPI/b_data_storage/kpi_data_model_storage.py:393",
         io="IN: storage, signal_name (exact or alias)<br>"
            "OUT: <code>(stacked 2-D array, \"success\")</code>",
         note="Resolves the alias via <code>_resolve_signal_mapping()</code> when the exact "
              "name is absent. Rows are NaN-padded to the widest row &rarr; "
              "<code>(n_scans, max_slots)</code>."),

    # ---- L3 ----
    dict(id="n_model", step="14", lane="L3", title="KpiDataModel(data, sensor)",
         src="UDP_KPI/c_business_layer/kpi_factory.py:35",
         io="IN: {stream: {input, output}} dict + sensor name<br>OUT: html_sections, per_kpi_sections",
         note="Creates a temp dir for plot files, then immediately runs the KPI tasks."),
    dict(id="n_tasks", step="15", lane="L3", title="_process_kpis() &mdash; 3 parallel tasks",
         src="UDP_KPI/c_business_layer/kpi_factory.py:60",
         io="IN: self.data, self.sensor<br>OUT: list of KPI result dicts",
         note="tasks = [alignment, <b>tracker</b>, detection]. The tracker task is a no-op "
              "unless <code>'TRACKER_STREAM'</code> is a key of <code>data</code>."),
    dict(id="n_exec", step="16", lane="L3", title="Executor selection",
         src="UDP_KPI/c_business_layer/kpi_factory.py:93",
         io="IN: env <code>KPI_EXECUTOR_MODE</code>, <code>KPI_DISABLE_MULTIPROC</code><br>"
            "OUT: serial | thread | process execution",
         note="Default <b>thread</b>. <code>process</code> falls back to thread on failure. "
              "A failure in one task is logged and the other two still complete."),
    dict(id="n_runtracker", step="17", lane="L3", title="_run_tracker()",
         src="UDP_KPI/c_business_layer/kpi_factory.py:21",
         io="IN: data['TRACKER_STREAM']<br>OUT: [result dict]",
         note="Pulls <code>models['input']</code> and <code>models['output']</code> and calls "
              "<code>process_tracker_kpi(...)</code> with stream name "
              "<code>'TRACKER_STREAM'</code>."),
    dict(id="n_prockpi", step="18", lane="L3", title="process_tracker_kpi(input, output, sensor, stream)",
         src="UDP_KPI/c_business_layer/tracker_matching_kpi.py:896",
         io="IN: 2 &times; KPI_DataModelStorage, sensor_id, stream_name<br>"
            "OUT: {kpi_results, html_content, success, sensor_id}",
         note="Thin wrapper. Any exception &rarr; success=False with an error paragraph."),
    dict(id="n_cls", step="19", lane="L3", title="TrackerMappingKPIHDF.__init__()",
         src="UDP_KPI/c_business_layer/tracker_matching_kpi.py:56",
         io="IN: storages, sensor_id, stream_name<br>OUT: thresholds tx, ty, tvx, tvy, max_valid_distance",
         note="Reads <code>KPI_VALIDATION_RULES['tracker_thresholds']</code>: "
              "tx=ty=0.01 m, tvx=tvy=0.02 m/s, max_valid_distance=160 m."),
    dict(id="n_proc_matching", step="20", lane="L3", title="process_tracker_matching() &mdash; 5 phases",
         src="UDP_KPI/c_business_layer/tracker_matching_kpi.py:132",
         io="IN: self<br>OUT: bool success",
         note="Phase order: (a) extract &rarr; (b) required-signal check &rarr; "
              "(c) match &rarr; (d) calculate KPIs &rarr; (e) HTML report."),

    # ---- L4 / L3 sub ----
    dict(id="n_extract", step="21", lane="L3", title="extract_tracker_data_from_hdf()",
         src="UDP_KPI/c_business_layer/tracker_matching_kpi.py:94",
         io="IN: KPI_DataModelStorage<br>OUT: {canonical_name &rarr; (n_scans, n_slots) float array}",
         note="Resolves 9 canonical signals through <code>TRACKER_SIGNAL_ALIASES</code>, "
              "first usable alias wins. Handles both the classic <code>vcs_*</code> layout "
              "and the AshokLeyland <code>object_*</code> layout."),
    dict(id="n_reqchk", step="22", lane="L3", title="Required-signal gate",
         src="UDP_KPI/c_business_layer/tracker_matching_kpi.py:139",
         io="IN: input_tracker_data, output_tracker_data<br>OUT: continue | return False",
         note="Requires <code>track_id</code>, <code>x_position</code>, <code>y_position</code> "
              "on BOTH sides. Missing &rarr; warning + <code>return False</code> (no report)."),
    dict(id="n_match", step="23", lane="L3", title="match_tracker_data() &mdash; CORE",
         src="UDP_KPI/c_business_layer/tracker_matching_kpi.py:167",
         io="IN: {canonical &rarr; 2-D array} &times; 2<br>"
            "OUT: matched_tracks, per_scan, id_overlap, tp/fp/fn totals",
         note="Composite key (scan, trkID) with one-to-one consume, CAN-KPI hashmap "
              "discipline. Complexity O(scans &times; slots)."),
    dict(id="n_kpi", step="24", lane="L3", title="calculate_tracker_kpis()",
         src="UDP_KPI/c_business_layer/tracker_matching_kpi.py:451",
         io="IN: matching_results<br>OUT: summary_stats + kpi_results",
         note="Zero matches still yield a valid 0% result &mdash; it never returns an empty "
              "<code>kpi_results</code> when data was extracted."),
    dict(id="n_plots", step="25", lane="L4", title="generate_plots()",
         src="UDP_KPI/c_business_layer/tracker_matching_kpi.py:658",
         io="IN: matched_tracks_df<br>OUT: (pos_plot_html, scatter_2d_html)",
         note="Plot A = 2&times;2 subplots (X pos, Y pos, bird-eye, error histogram). "
              "Plot B = bird-eye scatter with <code>scaleanchor</code> for a true 1:1 aspect."),
    dict(id="n_html", step="26", lane="L4", title="generate_html_report()",
         src="UDP_KPI/c_business_layer/tracker_matching_kpi.py:747",
         io="IN: summary_stats, kpi_results, per_scan, plot HTML<br>OUT: self.html_content (str)",
         note="Emits the hero accuracy line, the &quot;How to read this report&quot; block, "
              "detailed stats, the per-scan TP/FP/FN table, the threshold configuration "
              "and both interactive plots."),
    dict(id="n_results", step="27", lane="L5", title="get_results()",
         src="UDP_KPI/c_business_layer/tracker_matching_kpi.py:886",
         io="IN: self<br>OUT: {kpi_results, html_content, success, sensor_id}",
         note="<code>success</code> is simply <code>bool(self.kpi_results)</code>."),

    # ---- L5 ----
    dict(id="n_save", step="28", lane="L5", title="KpiDataModel._save_html_report()",
         src="UDP_KPI/c_business_layer/kpi_factory.py:130",
         io="IN: self.html_sections (all 3 KPIs)<br>OUT: KPI report .html file on disk",
         note="Wraps every KPI section in one document; also exposes "
              "<code>get_kpi_htmls()</code> for per-KPI sidecar saving."),
    dict(id="n_reply", step="29", lane="L5", title="ReplyMessage(html_file_path, status=\"success\")",
         src="UDP_KPI/kpi_server.py:146",
         io="IN: html_path<br>OUT: protobuf reply to the client",
         note="The client later polls with <code>b'\\n\\x0crequest_html'</code> to retrieve "
              "the path of the most recent report."),

    # ---- sub-flow of match_tracker_data ----
    dict(id="m_scan", step="23.1", lane="M", title="FOR scan i in range(n_scans)",
         src="tracker_matching_kpi.py:248",
         io="IN: n_scans = min(input rows, output rows)<br>OUT: one per_scan record",
         note="Rows of input and output are scan-aligned by the wrapper, so row i of both "
              "sides is the same scan."),
    dict(id="m_valid", step="23.2", lane="M", title="_valid_mask()",
         src="tracker_matching_kpi.py:117",
         io="IN: trkID row, x row, y row<br>OUT: boolean mask",
         note="Valid &harr; finite trkID <b>and</b> trkID &ne; 0 (0 = unused slot in the "
              "AshokLeyland padded resim) <b>and</b> finite x and y."),
    dict(id="m_range", step="23.3", lane="M", title="Range gate",
         src="tracker_matching_kpi.py:259",
         io="IN: x, y, max_valid_distance = 160 m<br>OUT: masked valid set",
         note="<code>hypot(x, y) &le; 160</code> on both sides. Applied only when the "
              "configured maximum is finite and &gt; 0."),
    dict(id="m_inmap", step="23.4", lane="M", title="Build in_map &mdash; trkID &rarr; deque",
         src="tracker_matching_kpi.py:272",
         io="IN: valid input slots<br>OUT: {trkID: deque(payload)}, in_order list",
         note="Payload = (x, y, vx, vy, f_moving, slot). <code>in_order</code> preserves "
              "slot order, which drives the greedy pairing order."),
    dict(id="m_outmap", step="23.5", lane="M", title="Build out_map",
         src="tracker_matching_kpi.py:291",
         io="IN: valid output slots<br>OUT: {trkID: deque(payload)}",
         note="Same structure for the output side; leftover deques are the FP source."),
    dict(id="m_pair", step="23.6", lane="M", title="Greedy one-to-one pairing",
         src="tracker_matching_kpi.py:312",
         io="IN: in_order, out_map<br>OUT: TP / FN(paired) / FN(unpaired)",
         note="For each input ID in slot order: pop one output with the same ID. "
              "No output with that ID &rarr; FN (unpaired). A popped output that fails the "
              "kinematics matrix &rarr; FN (paired)."),
    dict(id="m_matrix", step="23.7", lane="M", title="Kinematics matrix &mdash; 5 conditions",
         src="tracker_matching_kpi.py:320",
         io="IN: input payload, output payload<br>OUT: pos_ok, vx_ok, vy_ok, fm_ok",
         note="<code>|dx| &le; 0.01 m</code> AND <code>|dy| &le; 0.01 m</code> AND "
              "<code>|dvx| &le; 0.02 m/s</code> AND <code>|dvy| &le; 0.02 m/s</code> AND "
              "<code>f_moving</code> equal. A velocity axis is <b>skipped</b> when either "
              "side is NaN (flagged on the pair); a NaN <code>f_moving</code> is a mismatch."),
    dict(id="m_tp", step="23.8", lane="M", title="TP &mdash; record the pair",
         src="tracker_matching_kpi.py:346",
         io="IN: passing pair<br>OUT: matched_tracks entry, position + velocity error",
         note="Spatial error = <code>hypot(dx, dy)</code>; velocity error = "
              "<code>norm(v_in - v_out)</code> (only if finite)."),
    dict(id="m_fp", step="23.9", lane="M", title="FP &mdash; leftover output deques",
         src="tracker_matching_kpi.py:375",
         io="IN: out_map after pairing<br>OUT: scan_fp",
         note="Every output still sitting in a deque is a false positive "
              "(an ID the output invented)."),
    dict(id="m_perScan", step="23.10", lane="M", title="per_scan record",
         src="tracker_matching_kpi.py:389",
         io="IN: scan counters<br>OUT: {scan_row, scan_value, tp, fp, fn, acc_pct, n_in, n_out}",
         note="acc_pct = TP/(TP+FN) &times; 100; 100% for an empty scan, 0% when only "
              "spurious outputs exist."),
    dict(id="m_overlap", step="23.11", lane="M", title="id_overlap diagnostic",
         src="tracker_matching_kpi.py:402",
         io="IN: in_id_set, out_id_set<br>OUT: {common, union, input_only, output_only}",
         note="Distinguishes &quot;the ID was never present&quot; from &quot;the ID was "
              "present but the kinematics failed&quot;."),
    dict(id="m_df", step="23.12", lane="M", title="matched_tracks_df",
         src="tracker_matching_kpi.py:425",
         io="IN: matched_tracks list<br>OUT: pandas DataFrame (capped at 2000 rows)",
         note="<b>Only the plots are capped</b> &mdash; every statistic uses the full list."),
]

# --------------------------------------------------------------------------
# Edges: (from, to, label, style)   style: '' | 'dashed'
# --------------------------------------------------------------------------
EDGES = [
    ("n_zmq", "n_req", "protobuf bytes"),
    ("n_req", "n_handle", "RequestMessage"),
    ("n_handle", "n_parse", "sensor_id + paths"),
    ("n_parse", "n_wrapper", "KPIProcessingConfig"),
    ("n_wrapper", "n_parser", "h5py.Group + storage"),
    ("n_parser", "n_parsegrp", "pre-order DFS"),
    ("n_parsegrp", "n_setval", "dataset + signal_name"),
    ("n_setval", "n_align", "dataset"),
    ("n_align", "n_proc", "aligned dataset"),
    ("n_proc", "n_container", "rows"),
    ("n_proc", "n_maps", "signal_name, key"),
    ("n_container", "n_getval", "cube"),
    ("n_maps", "n_getval", "reverse index"),
    ("n_getval", "n_model", "storage objects"),
    ("n_model", "n_tasks", "data, sensor"),
    ("n_tasks", "n_exec", "3 tasks"),
    ("n_exec", "n_runtracker", "tracker task"),
    ("n_runtracker", "n_prockpi", "input, output storage"),
    ("n_prockpi", "n_cls", "TrackerMappingKPIHDF"),
    ("n_cls", "n_proc_matching", "thresholds"),
    ("n_proc_matching", "n_extract", "phase (a)"),
    ("n_extract", "n_reqchk", "canonical arrays"),
    ("n_reqchk", "n_match", "phase (c)"),
    ("n_match", "n_kpi", "phase (d)"),
    ("n_kpi", "n_plots", "phase (e)"),
    ("n_plots", "n_html", "plot HTML"),
    ("n_html", "n_results", "html_content"),
    ("n_results", "n_save", "html sections"),
    ("n_save", "n_reply", "html_path"),

    # sub-flow
    ("n_match", "m_scan", "expand"),
    ("m_scan", "m_valid", "23.2"),
    ("m_valid", "m_range", "23.3"),
    ("m_range", "m_inmap", "23.4"),
    ("m_inmap", "m_outmap", "23.5"),
    ("m_outmap", "m_pair", "23.6"),
    ("m_pair", "m_matrix", "23.7"),
    ("m_matrix", "m_tp", "all pass"),
    ("m_matrix", "m_fp", "fail / leftover"),
    ("m_tp", "m_perScan", "23.10"),
    ("m_fp", "m_perScan", "23.9"),
    ("m_perScan", "m_overlap", "23.11"),
    ("m_overlap", "m_df", "23.12"),
]

KPI_FORMULAS = [
    ("Accuracy (hero) = Recall", "TP / total_valid_input_tracks", "0% when no valid input"),
    ("Precision", "TP / total_valid_output_tracks", "0% when no valid output"),
    ("Overall / Jaccard", "TP / (TP + FP + FN)", "0% when the denominator is 0"),
    ("F1", "2 &times; P &times; R / (P + R)", "0% when P + R = 0"),
    ("Per-scan Acc%", "TP / (TP + FN) &times; 100", "100% for an empty scan, 0% if only FP exist"),
    ("Position error", "hypot(x_in - x_out, y_in - y_out)", "mean / std / max / min over all TPs"),
    ("Velocity error", "norm(v_in - v_out)", "NaN excluded; skipped axes never enter the stats"),
    ("f_moving agreement", "agree / co-occur &times; 100", "NaN or unset flag counts as a mismatch"),
    ("ID overlap", "|in &cap; out| / |in &cup; out|", "diagnostic: presence vs kinematics failure"),
]

GOTCHAS = [
    ("ID 0 is not a track", "<code>trkID == 0</code> marks an unused slot (the AshokLeyland "
     "resim zero-pads), so it is excluded by <code>_valid_mask</code> before anything else."),
    ("A failed gate is a FN, not a skip", "A co-occurring ID whose kinematics matrix fails is "
     "counted as a <b>false negative</b> &mdash; it is not ignored."),
    ("A NaN velocity skips that axis only", "The velocity gate is bypassed when either side is "
     "NaN, and the pair is flagged <code>vx_gate_skipped</code>. The NaN never reaches the "
     "velocity statistics."),
    ("A NaN f_moving is a mismatch", "Unlike velocity, an unset motion flag is a hard mismatch."),
    ("The 2000-row cap is plot-only", "<code>matched_tracks_df</code> is truncated to 2000 rows, "
     "but <b>all statistics use the complete list</b>. Reported counts can exceed the plotted points."),
    ("Zero matches is still success", "A 0% result is a valid report, not a failure. Only a "
     "missing required signal returns <code>success=False</code>."),
    ("ID overlap is the diagnostic", "Low common/union means the misses come from ID "
     "<i>presence</i>, not from the kinematics matrix &mdash; a completely different fix."),
    ("One task failing does not sink the others", "alignment, tracker and detection run "
     "concurrently; each failure is logged in isolation."),
]


def build(out_path: str) -> str:
    by_lane = {lid: [] for lid, *_ in LANES}
    for n in NODES:
        by_lane.setdefault(n["lane"], []).append(n)

    html: list[str] = []
    html.append("""<!DOCTYPE html>
<html lang="en"><head><meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>Tracker KPI &mdash; I/O Flow Diagram (UDP_KPI)</title>
<style>
  :root{--bg:#0d1117;--panel:#161b26;--line:#2a3245;--fg:#e6edf3;--mut:#8b98b0;
        --io:#1d3557;--note:#2d1b3d;--warn:#3d2d1b;--ok:#1b3d2a;--accent:#58a6ff;}
  *{box-sizing:border-box}
  body{margin:0;background:var(--bg);color:var(--fg);
       font-family:"Segoe UI",system-ui,sans-serif;font-size:14px;line-height:1.5}
  header{padding:26px 32px;background:linear-gradient(135deg,#111a2e,#1c1533);
         border-bottom:1px solid var(--line)}
  h1{margin:0 0 6px;font-size:24px}
  .sub{color:var(--mut);font-size:13.5px;max-width:1150px}
  .sub code{background:#0b1220;padding:1px 5px;border-radius:3px;color:#9ecbff}
  .wrap{max-width:1560px;margin:0 auto;padding:20px 26px 70px}
  h2{font-size:18px;margin:30px 0 10px;padding-bottom:6px;border-bottom:1px solid var(--line)}
  h3{font-size:15px;margin:20px 0 8px;color:#c9d6e8}
  .legend{display:flex;gap:18px;flex-wrap:wrap;font-size:12px;color:var(--mut);margin-top:14px}
  .legend span{display:flex;align-items:center;gap:6px}
  .sw{width:14px;height:14px;border-radius:3px;display:inline-block}

  .lane{margin:16px 0;border:1px solid var(--line);border-radius:10px;overflow:hidden;
        background:var(--panel)}
  .lane-hd{padding:9px 14px;font-weight:700;font-size:13px;letter-spacing:.5px;
           color:#fff;display:flex;justify-content:space-between;align-items:center}
  .lane-hd small{font-weight:400;opacity:.85;font-size:11.5px}
  .lane-body{padding:16px 16px 20px;display:flex;flex-direction:column;gap:14px}
  .row{display:flex;gap:14px;align-items:stretch;flex-wrap:wrap}

  .node{flex:1 1 300px;min-width:260px;max-width:420px;border:1px solid var(--line);
        border-radius:9px;background:#111826;position:relative;padding:11px 12px}
  .node .step{display:inline-block;background:#243044;color:#9ecbff;border-radius:10px;
              padding:1px 8px;font-size:11px;font-weight:700;margin-right:6px}
  .node .ttl{font-weight:600;font-size:13.5px;display:block;margin:2px 0 6px}
  .node .src{font-family:Consolas,monospace;font-size:10.5px;color:#7f8ea8;margin-bottom:6px;
             word-break:break-all}
  .iobox{background:#0e1b2e;border-left:3px solid #2f6fb5;border-radius:0 5px 5px 0;
         padding:7px 9px;font-size:11.5px;margin:5px 0}
  .iobox .lbl{color:#5fa8f0;font-weight:700;margin-right:5px}
  .note{background:#1d1428;border-left:3px solid #7a4bbd;border-radius:0 5px 5px 0;
        padding:7px 9px;font-size:11.5px;color:#cbb8e0;margin-top:5px}
  .node.core{border-color:#b8862b;box-shadow:0 0 0 1px #b8862b inset}
  .node.core .ttl{color:#ffd479}

  svg#wires{position:absolute;inset:0;width:100%;height:100%;pointer-events:none;z-index:0}
  .flow{position:relative}
  .flow > *{position:relative;z-index:1}

  table{width:100%;border-collapse:collapse;font-size:12.5px;margin:8px 0}
  th,td{border:1px solid var(--line);padding:7px 9px;text-align:left;vertical-align:top}
  th{background:#1b2333;font-weight:600}
  tr:nth-child(even) td{background:#121824}
  code{background:#0b1220;padding:1px 4px;border-radius:3px;color:#9ecbff;
       font-family:Consolas,monospace;font-size:12px}
  .card{background:var(--panel);border:1px solid var(--line);border-radius:10px;padding:16px 18px}
  .grid2{display:grid;grid-template-columns:1fr 1fr;gap:16px}
  @media(max-width:1100px){.grid2{grid-template-columns:1fr}}
  .pill{display:inline-block;background:#243044;border-radius:10px;padding:2px 9px;
        font-size:11.5px;margin:2px 4px 2px 0;color:#c9d6e8}
  .warn{border-left:3px solid #d29922}
  .srcpath{font-family:Consolas,monospace;font-size:11px;color:#6d7b93}
</style></head><body>
<header>
  <h1>Tracker KPI &mdash; I/O Flow Diagram</h1>
  <div class="sub">Complete data-flow of the <b>tracker KPI</b> inside
    <code>ALL_KPI / KPI / UDP_KPI / c_business_layer / tracker_matching_kpi.py</code>,
    traced from the ZMQ request down to the HDF5 read, the per-scan matching core, the
    KPI arithmetic and the HTML report. Steps are numbered in <b>processing (pre-order)</b>
    sequence. Every I/O shape below was read from the source, not inferred.
  </div>
  <div class="legend">
    <span><i class="sw" style="background:#2f6fb5"></i> I/O boundary</span>
    <span><i class="sw" style="background:#7a4bbd"></i> implementation note</span>
    <span><i class="sw" style="background:#b8862b"></i> core algorithm</span>
    <span>&#9632; step number = execution order</span>
    <span>&#8594; solid = data flow &nbsp;&middot;&nbsp; dashed = sub-flow expansion</span>
  </div>
</header>
<div class="wrap flow">
<svg id="wires"></svg>
""")

    # ---- lanes ----
    order = ["L0", "L1", "L2", "L3", "M", "L4", "L5"]
    lane_meta = {lid: (title, color) for lid, title, color in LANES}
    lane_meta["M"] = ("SUB-FLOW &mdash; match_tracker_data() PER-SCAN CORE", "#4a2a1f")
    lane_note = {
        "L0": "ZMQ request &rarr; HDF generation request",
        "L1": "h5py read, depth-first, alias-filtered",
        "L2": "scan-indexed signal cube + reverse index",
        "L3": "alias resolution, per-scan matching, KPI arithmetic",
        "M": "one iteration of the per-scan matching loop",
        "L4": "plotly figures and the report body",
        "L5": "files and messages leaving the KPI engine",
    }
    for lid in order:
        nodes = by_lane.get(lid, [])
        if not nodes:
            continue
        title, color = lane_meta[lid]
        html.append(f'<div class="lane"><div class="lane-hd" style="background:{color}">'
                    f'<span>{title}</span><small>{lane_note[lid]}</small></div>'
                    f'<div class="lane-body">')
        # group into rows of 3
        for i in range(0, len(nodes), 3):
            chunk = nodes[i:i + 3]
            html.append('<div class="row">')
            for n in chunk:
                cls = "node core" if n["id"] in ("n_match", "m_matrix") else "node"
                html.append(f'<div class="{cls}" id="{n["id"]}">')
                html.append(f'<span class="step">{n["step"]}</span>')
                html.append(f'<span class="ttl">{n["title"]}</span>')
                html.append(f'<div class="src">{n["src"]}</div>')
                html.append(f'<div class="iobox"><span class="lbl">IO</span>{n["io"]}</div>')
                html.append(f'<div class="note">{n["note"]}</div>')
                html.append('</div>')
            html.append('</div>')
        html.append('</div></div>')

    # ---- KPI formulas ----
    html.append('<h2>KPI arithmetic reference</h2><div class="card"><table>'
                '<thead><tr><th>Metric</th><th>Formula</th><th>Edge behaviour</th></tr></thead><tbody>')
    for name, formula, edge in KPI_FORMULAS:
        html.append(f'<tr><td><b>{name}</b></td><td><code>{formula}</code></td>'
                    f'<td>{edge}</td></tr>')
    html.append('</tbody></table></div>')

    # ---- data structures ----
    html.append("""
<h2>Data structures passed between stages</h2>
<div class="card"><table>
<thead><tr><th>Stage</th><th>Structure</th><th>Shape / type</th></tr></thead><tbody>
<tr><td>HDF5 dataset</td><td><code>dataset</code></td><td>ndarray (n_scans, n_slots), one dataset per signal</td></tr>
<tr><td>Storage cube</td><td><code>_data_container</code></td><td>dict[scan_idx] &rarr; list[group] &rarr; list[signal] &rarr; ndarray(n_slots)</td></tr>
<tr><td>Reverse index</td><td><code>_signal_to_value</code></td><td>{signal_name: [ {grp_name: key} ]}</td></tr>
<tr><td>Extracted tracker data</td><td><code>tracker_data</code></td><td>{canonical_name: ndarray (n_scans, n_slots)} &mdash; 9 canonical signals</td></tr>
<tr><td>Matched pairs</td><td><code>matched_tracks</code></td><td>list[dict] with scan_row, input/output track_id &amp; pos &amp; vel, spatial_distance, fmoving_agree, vx/vy_gate_skipped</td></tr>
<tr><td>Per-scan rows</td><td><code>per_scan</code></td><td>list[dict]: scan_row, scan_value, tp, fp, fn, matches, den, acc_pct, n_in, n_out</td></tr>
<tr><td>ID diagnostic</td><td><code>id_overlap</code></td><td>dict: common, union, input_only, output_only, n_input_ids, n_output_ids</td></tr>
<tr><td>Plots</td><td><code>matched_tracks_df</code></td><td>pandas DataFrame, capped at 2000 rows (plot only)</td></tr>
<tr><td>Result</td><td><code>kpi_results</code></td><td>dict: accuracy, numerator, denominator, precision, recall, f1, jaccard, overall, total_fp, total_fn, fmoving_*, per_scan, summary_stats, matching_mode, thresholds</td></tr>
<tr><td>Report</td><td><code>html_content</code></td><td>str &mdash; full KPI section (summary, how-to-read, stats, per-scan table, thresholds, 2 plots)</td></tr>
</tbody></table></div>
""")

    # ---- gotchas ----
    html.append('<h2>Edge cases and traps in this code path</h2><div class="card warn">')
    for title, body in GOTCHAS:
        html.append(f'<p style="margin:9px 0"><b style="color:#e3b341">{title}</b> &mdash; {body}</p>')
    html.append('</div>')

    # ---- source index ----
    html.append("""
<h2>Source index</h2>
<div class="card"><table>
<thead><tr><th>File</th><th>Role in the tracker KPI flow</th></tr></thead><tbody>
<tr><td class="srcpath">UDP_KPI/kpi_server.py</td><td>ZMQ REP server, protobuf request/reply, dispatches to the KPI engine, returns the report path</td></tr>
<tr><td class="srcpath">UDP_KPI/a_persistence_layer/hdf_wrapper.py</td><td><code>parse_for_kpi()</code> entry point, opens the HDF5 files, owns the processing config</td></tr>
<tr><td class="srcpath">UDP_KPI/a_persistence_layer/kpi_hdf_parser.py</td><td><code>KPIHDFParser</code> &mdash; depth-first, pre-order HDF5 traversal with stream and signal-name filtering</td></tr>
<tr><td class="srcpath">UDP_KPI/b_data_storage/kpi_data_model_storage.py</td><td><code>KPI_DataModelStorage</code> &mdash; the scan-indexed container, <code>set_value()</code> / <code>get_value()</code>, alias resolution</td></tr>
<tr><td class="srcpath">UDP_KPI/b_data_storage/kpi_config_storage.py</td><td>Stream registry (<code>STREAM_ALIASES</code>, <code>canonical_stream_name()</code>), signal configs, and <code>KPI_VALIDATION_RULES['tracker_thresholds']</code></td></tr>
<tr><td class="srcpath">UDP_KPI/c_business_layer/kpi_factory.py</td><td><code>KpiDataModel</code> &mdash; runs alignment / tracker / detection concurrently, assembles the report</td></tr>
<tr><td class="srcpath">UDP_KPI/c_business_layer/tracker_matching_kpi.py</td><td><b>The tracker KPI itself</b> &mdash; alias extraction, per-scan matching, KPI arithmetic, plots, report</td></tr>
<tr><td class="srcpath">UDP_KPI/d_presentation_layer/kpi_html_gen.py</td><td>Final HTML report assembly for the KPI sections</td></tr>
<tr><td class="srcpath">UDP_KPI/tests/test_tracker_id_indexed_kpi.py</td><td>Executable proof of the matching semantics (classic layout, matrix-fail, one-sided ID)</td></tr>
</tbody></table></div>
""")

    html.append(f"""
<footer style="color:#6d7b93;font-size:12px;margin-top:26px;border-top:1px solid var(--line);padding-top:12px">
Generated from the live source at
<span class="srcpath">ALL_KPI/KPI/UDP_KPI/</span> &mdash; 29 numbered steps, 7 lanes,
{len(NODES)} nodes, {len(EDGES)} data-flow edges. Every I/O shape, threshold and
branch was read from the code.
</footer>
</div>
<script>
const EDGES = {json.dumps([list(e) for e in EDGES])};
const svg = document.getElementById('wires');
function draw(){{
  const box = document.querySelector('.flow');
  const br = box.getBoundingClientRect();
  svg.setAttribute('viewBox', `0 0 ${{br.width}} ${{br.height}}`);
  svg.setAttribute('width', br.width);
  svg.setAttribute('height', br.height);
  svg.innerHTML = '';
  const defs = document.createElementNS('http://www.w3.org/2000/svg','defs');
  defs.innerHTML = `<marker id="arw" viewBox="0 0 10 10" refX="9" refY="5"
      markerWidth="7" markerHeight="7" orient="auto-start-reverse">
      <path d="M 0 0 L 10 5 L 0 10 z" fill="#5b7fb0"/></marker>
    <marker id="arw2" viewBox="0 0 10 10" refX="9" refY="5"
      markerWidth="7" markerHeight="7" orient="auto-start-reverse">
      <path d="M 0 0 L 10 5 L 0 10 z" fill="#b8862b"/></marker>`;
  svg.appendChild(defs);
  for (const [from,to,label] of EDGES) {{
    const a = document.getElementById(from), b = document.getElementById(to);
    if (!a || !b) continue;
    const ra = a.getBoundingClientRect(), rb = b.getBoundingClientRect();
    const ax = ra.left - br.left, ay = ra.top - br.top;
    const bx = rb.left - br.left, by = rb.top - br.top;
    const acx = ax + ra.width/2, acy = ay + ra.height/2;
    const bcx = bx + rb.width/2, bcy = by + rb.height/2;
    let x1,y1,x2,y2;
    if (Math.abs(bcy - acy) > Math.abs(bcx - acx)) {{
      // mostly vertical
      if (bcy > acy) {{ x1 = acx; y1 = ay + ra.height; x2 = bcx; y2 = by; }}
      else {{ x1 = acx; y1 = ay; x2 = bcx; y2 = by + rb.height; }}
    }} else {{
      // mostly horizontal
      if (bcx > acx) {{ x1 = ax + ra.width; y1 = acy; x2 = bx; y2 = bcy; }}
      else {{ x1 = ax; y1 = acy; x2 = bx + rb.width; y2 = bcy; }}
    }}
    const path = document.createElementNS('http://www.w3.org/2000/svg','path');
    const midx = (x1+x2)/2, midy = (y1+y2)/2;
    const c = Math.abs(x2-x1) > Math.abs(y2-y1)
      ? `M ${{x1}},${{y1}} C ${{midx}},${{y1}} ${{midx}},${{y2}} ${{x2}},${{y2}}`
      : `M ${{x1}},${{y1}} C ${{x1}},${{midy}} ${{x2}},${{midy}} ${{x2}},${{y2}}`;
    path.setAttribute('d', c);
    path.setAttribute('fill','none');
    path.setAttribute('stroke', (from==='n_match'||from==='m_matrix') ? '#b8862b' : '#5b7fb0');
    path.setAttribute('stroke-width','1.5');
    path.setAttribute('opacity','0.75');
    path.setAttribute('marker-end','url(#' + ((from==='n_match'||from==='m_matrix')?'arw2':'arw') + ')');
    svg.appendChild(path);
    if (label) {{
      const t = document.createElementNS('http://www.w3.org/2000/svg','text');
      t.setAttribute('x', midx); t.setAttribute('y', midy - 3);
      t.setAttribute('text-anchor','middle');
      t.setAttribute('font-size','9.5');
      t.setAttribute('fill','#7f9dc4');
      t.textContent = label;
      svg.appendChild(t);
    }}
  }}
}}
window.addEventListener('load', () => {{ setTimeout(draw, 60); }});
window.addEventListener('resize', draw);
</script>
</body></html>""")

    os.makedirs(os.path.dirname(out_path) or ".", exist_ok=True)
    with open(out_path, "w", encoding="utf-8") as f:
        f.write("".join(html))
    return out_path


def export_png(html_path: str, png_path: str) -> str | None:
    """Render the diagram to a full-page PNG using headless Chrome (playwright)."""
    try:
        import asyncio
        from playwright.async_api import async_playwright
    except Exception as ex:
        print(f"[warn] playwright unavailable, skipping PNG: {ex}")
        return None

    async def _run():
        async with async_playwright() as p:
            browser = await p.chromium.launch(channel="chrome")
            page = await browser.new_page(viewport={"width": 1600, "height": 1200})
            await page.goto("file:///" + html_path.replace("\\", "/"))
            await page.wait_for_timeout(2500)
            await page.screenshot(path=png_path, full_page=True)
            await browser.close()

    try:
        asyncio.run(_run())
        return png_path
    except Exception as ex:
        print(f"[warn] PNG export failed: {ex}")
        return None


if __name__ == "__main__":
    out = sys.argv[1] if len(sys.argv) > 1 else DEFAULT_OUT
    p = build(out)
    print(f"wrote {p} ({os.path.getsize(p)} bytes)")
    png = export_png(p, os.path.splitext(out)[0] + ".png")
    if png:
        print(f"wrote {png} ({os.path.getsize(png)} bytes)")
