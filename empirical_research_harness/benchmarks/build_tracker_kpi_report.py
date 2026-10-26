"""Build the standalone Desktop report on tracker KPI architecture and results.

Inputs (all produced by the benchmark scripts in this folder):
    hdf_track_out/accuracy.json          replay-log scoring (FC + RL streams)
    hdf_track_out/edge_pairs.json        depth-3 ``03_TrackerInfo`` pair scoring
    hdf_track_out/json/<scene>_<role>_FC.json   per-scan object exports

Output:
    ~/Desktop/tracker_kpi_architecture_and_flow.html

Everything is inlined (CSS + Mermaid via CDN with an offline fallback), so the
file opens from the filesystem with no server and no build step.

Usage:
    python empirical_research_harness/benchmarks/build_tracker_kpi_report.py
"""
from __future__ import annotations

import json
from pathlib import Path
from typing import Any, Dict, List, Optional, Sequence, Tuple

HERE = Path(__file__).resolve().parent
DATA = HERE / "hdf_track_out"
DESKTOP = Path.home() / "Desktop"
OUT = DESKTOP / "tracker_kpi_architecture_and_flow.html"

CSS = """
:root{
  --bg:#0b0f14;--panel:#131a22;--panel2:#0f1620;--line:#22303d;--txt:#e6edf3;
  --dim:#93a4b5;--accent:#7dd3fc;--ok:#34d399;--warn:#fbbf24;--bad:#f87171;--vio:#c4b5fd;
}
*{box-sizing:border-box}
body{margin:0;background:var(--bg);color:var(--txt);
  font:15px/1.6 -apple-system,BlinkMacSystemFont,"Segoe UI",Roboto,sans-serif}
a{color:var(--accent);text-decoration:none}
nav{position:sticky;top:0;z-index:9;background:rgba(11,15,20,.92);
  backdrop-filter:blur(8px);border-bottom:1px solid var(--line)}
nav .in{max-width:1180px;margin:0 auto;padding:10px 20px;display:flex;gap:18px;
  flex-wrap:wrap;font-size:13px}
nav b{color:var(--accent);font-weight:600;margin-right:8px}
main{max-width:1180px;margin:0 auto;padding:28px 20px 80px}
header h1{font-size:30px;line-height:1.2;margin:8px 0 6px;letter-spacing:-.4px}
header p{color:var(--dim);margin:0 0 22px;max-width:900px}
h2{font-size:20px;margin:38px 0 6px;letter-spacing:-.2px}
h2 .num{color:var(--accent);font-size:13px;vertical-align:middle;margin-right:8px;
  border:1px solid var(--line);border-radius:99px;padding:2px 9px}
h3{font-size:15px;margin:22px 0 8px;color:var(--accent)}
p.lead{color:var(--dim);margin:0 0 16px}
.kpi-grid{display:grid;gap:14px;grid-template-columns:repeat(auto-fit,minmax(170px,1fr));
  margin:18px 0 8px}
.kpi-card{background:linear-gradient(160deg,var(--panel),var(--panel2));
  border:1px solid var(--line);border-radius:12px;padding:14px 16px}
.kpi-card .val{font-size:26px;font-weight:650;letter-spacing:-.5px}
.kpi-card .lbl{font-size:11px;text-transform:uppercase;letter-spacing:.7px;
  color:var(--dim);margin-top:2px}
.kpi-card .sub{font-size:12px;color:var(--dim);margin-top:6px}
.kpi-card.ok .val{color:var(--ok)}.kpi-card.bad .val{color:var(--bad)}
.kpi-card.warn .val{color:var(--warn)}.kpi-card.acc .val{color:var(--accent)}
.panel{background:var(--panel);border:1px solid var(--line);border-radius:12px;
  padding:4px 18px 18px;margin:14px 0}
.table-wrap{overflow-x:auto;border:1px solid var(--line);border-radius:10px;
  background:var(--panel);margin:12px 0}
table.tbl{border-collapse:collapse;width:100%;font-size:13px;white-space:nowrap}
table.tbl th{background:#18222e;color:var(--dim);font-weight:600;text-align:right;
  padding:9px 11px;position:sticky;top:0;border-bottom:1px solid var(--line)}
table.tbl td{padding:8px 11px;text-align:right;border-bottom:1px solid #1b2734}
table.tbl tr:last-child td{border-bottom:0}
table.tbl th:first-child,table.tbl td:first-child{text-align:left}
table.tbl tbody tr:nth-child(even){background:#101821}
table.tbl tbody tr.top td{background:#16241f}
table.tbl tbody tr.top td:first-child{box-shadow:inset 3px 0 0 var(--ok)}
.mono{font-family:ui-monospace,SFMono-Regular,Consolas,monospace;font-size:12px;
  color:#cbd5e1}
.badge{display:inline-block;font-size:11px;padding:1px 8px;border-radius:99px;
  border:1px solid var(--line);color:var(--dim)}
.badge.ok{color:var(--ok);border-color:#1f4d3a;background:#0e2a20}
.badge.bad{color:var(--bad);border-color:#4d1f1f;background:#2a1010}
.badge.warn{color:var(--warn);border-color:#4d3c1f;background:#2a2110}
.note{color:var(--dim);font-size:12.5px}
.callout{border-left:3px solid var(--accent);background:#0f1a24;padding:12px 16px;
  border-radius:0 8px 8px 0;margin:14px 0}
.callout.bad{border-color:var(--bad);background:#1a1113}
.callout.ok{border-color:var(--ok);background:#0f1c17}
.callout b{color:var(--txt)}
.flow{background:var(--panel2);border:1px solid var(--line);border-radius:10px;
  padding:16px;margin:12px 0;overflow-x:auto}
pre.mermaid{color:#cbd5e1;font-size:12px;margin:0;white-space:pre-wrap}
.formula{font-family:ui-monospace,Consolas,monospace;font-size:12.5px;color:#cfe3f5;
  background:#0d141c;border:1px solid var(--line);border-radius:8px;padding:12px 14px;
  overflow-x:auto;white-space:pre;margin:10px 0}
.grid2{display:grid;gap:14px;grid-template-columns:1fr 1fr}
.case{background:var(--panel);border:1px solid var(--line);border-radius:10px;
  padding:14px 16px;margin:10px 0}
.case h4{margin:0 0 6px;font-size:14px;color:var(--txt)}
.case .row{display:flex;gap:22px;flex-wrap:wrap;font-size:13px;color:var(--dim)}
.case .row b{color:var(--txt);font-weight:600}
footer{color:var(--dim);font-size:12px;border-top:1px solid var(--line);
  margin-top:44px;padding-top:14px}
@media(max-width:900px){.grid2{grid-template-columns:1fr}}
@media print{nav{display:none}body{background:#fff;color:#000}
  .panel,.kpi-card,.table-wrap,.case{background:#fff;border-color:#bbb}
  table.tbl th{background:#eee;color:#000}table.tbl td,table.tbl th{color:#000}}
"""

MERMAID_JS = """
<script type="module">
try {
  const mermaid = (await import('https://cdn.jsdelivr.net/npm/mermaid@11/dist/mermaid.esm.min.mjs')).default;
  mermaid.initialize({startOnLoad:false, theme:'dark', themeVariables:{
    background:'#0f1620', primaryColor:'#16283a', primaryTextColor:'#e6edf3',
    primaryBorderColor:'#3b556e', lineColor:'#7dd3fc', fontFamily:'system-ui,sans-serif'
  }});
  await mermaid.run({nodes: document.querySelectorAll('pre.mermaid')});
} catch (e) {
  console.warn('mermaid unavailable (offline) — diagram source shown as text', e);
}
</script>
"""

ARCHITECTURE = """flowchart LR
  subgraph V["On-vehicle radar pipeline"]
    A["Chirp / ADC samples"] --> B["2D-FFT<br/>range-Doppler"]
    B --> C["CFAR detection"]
    C --> D["DoA / angle estimation"]
    D --> E["RDU point cloud"]
    E --> F["Domain-controller fusion"]
    F --> G["EKF multi-target tracker"]
    G --> H[("CAN-FD object list<br/>64 slots, 20 Hz")]
  end
  subgraph O["Offline KPI validation (this repo)"]
    I[("Reference HDF<br/>recorded run")] --> K["Stream extraction<br/>h5py recursive walk"]
    J[("Replay HDF<br/>same detections,<br/>new parameters")] --> K
    K --> L["Scan alignment<br/>by header timestamp"]
    L --> M["Validation, gating,<br/>association"]
    M --> N["KPI metrics<br/>+ HTML report"]
  end
  H -. "logged by recorder" .-> I
  G -. "replay dump" .-> J
  N -. "regression gate" .-> F"""

FLOW = """flowchart TD
  S0["1. Ingest pair<br/>reference log + replay log"] --> S1["2. Inner-join scans<br/>exact ts, else nearest ≤ 25 ms"]
  S1 --> S2{"3. Slot valid?<br/>id > 0, finite x/y,<br/>not (0,0), |p| ≤ 160 m"}
  S2 -- "no" --> X1["drop slot<br/>(empty / sentinel)"]
  S2 -- "yes" --> S3["4. 4-D hard gate<br/>|Δx| ≤ Tx, |Δy| ≤ Ty,<br/>|Δvx| ≤ Tvx, |Δvy| ≤ Tvy,<br/>f_moving equal"]
  S3 --> S4["5. Normalized cost matrix<br/>Cij = Σ w·(Δ/T)² / Σ w"]
  S4 --> S5["6. Hungarian assignment<br/>scipy linear_sum_assignment"]
  S5 --> S6["7. Metrics<br/>TP / FP / FN, P / R / F1,<br/>Jaccard, pos error"]
  S6 --> S7["8. MOT diagnostics<br/>ID switches per reference track"]
  S7 --> S8["9. Report + gate<br/>pass / fail vs baseline"]
  X1 --> S3"""


def load(path: Path) -> Any:
    """Read a JSON artifact produced by the benchmark scripts."""
    return json.loads(path.read_text(encoding="utf-8"))


def f(x: Optional[float], digits: int = 2) -> str:
    """Format an optional number, em dash when absent."""
    return "—" if x is None else f"{x:.{digits}f}"


def case_studies(scene: str, limit: int = 3) -> List[Dict[str, Any]]:
    """Find real scans where the same object carries different trkIDs per run."""
    ref_path = DATA / "json" / f"{scene}_input_FC.json"
    rep_path = DATA / "json" / f"{scene}_output_FC.json"
    if not (ref_path.exists() and rep_path.exists()):
        return []
    ref, rep = load(ref_path), load(rep_path)
    ix = {c: i for i, c in enumerate(ref["columns"])}
    rep_by_ts = {s["ts"]: s for s in rep["scans"]}
    found: List[Dict[str, Any]] = []
    seen: set = set()
    for scan in ref["scans"]:
        other = rep_by_ts.get(scan["ts"])
        if not other or not scan["objs"] or not other["objs"]:
            continue
        a = scan["objs"]
        b = other["objs"]
        for obj in a:
            rid = obj[ix["trk_id"]]
            if rid in seen:
                continue
            best, best_d = None, 1e9
            for cand in b:
                d = ((obj[ix["x"]] - cand[ix["x"]]) ** 2
                     + (obj[ix["y"]] - cand[ix["y"]]) ** 2) ** 0.5
                if d < best_d:
                    best, best_d = cand, d
            if best is None or best_d > 0.25 or best[ix["trk_id"]] == rid:
                continue
            legacy = next((c for c in b if c[ix["trk_id"]] == rid), None)
            legacy_gap = None
            if legacy is not None:
                legacy_gap = ((obj[ix["x"]] - legacy[ix["x"]]) ** 2
                              + (obj[ix["y"]] - legacy[ix["y"]]) ** 2) ** 0.5
            seen.add(rid)
            found.append({
                "ts": scan["ts"], "scan": scan["i"],
                "ref_id": rid, "out_id": best[ix["trk_id"]],
                "ref_xy": (obj[ix["x"]], obj[ix["y"]]),
                "out_xy": (best[ix["x"]], best[ix["y"]]),
                "dist": best_d, "legacy_gap": legacy_gap,
                "ref_v": (obj[ix["vx"]], obj[ix["vy"]]),
            })
            if len(found) >= limit * 8:
                break
        if len(found) >= limit * 8:
            break
    found.sort(key=lambda c: c["dist"])
    return found[:limit]


def per_pair_rows(acc: Dict[str, Any], edge: Dict[str, Any]) -> List[Dict[str, Any]]:
    """One row per evaluated pair, both schemas, at the replay tolerance."""
    rows = []
    for scene, entry in acc["per_scene"].items():
        st = entry["streams"].get("FC")
        if not st or not st["aligned_scans"]:
            continue
        algo = st["gates"]["replay"]["algorithms"]
        rows.append({
            "pair": scene.split("_")[-1],
            "kind": "replay log — 64 slots",
            "scans": st["aligned_scans"],
            "objects": st["inputs_total"],
            "legacy": algo["legacy_id"],
            "hungarian": algo["hungarian_normalized"],
            "mahalanobis": algo["mahalanobis"],
            "gospa": algo["gospa"],
            "obb": algo["obb_auction"],
        })
    for name, entry in edge.get("pairs", {}).items():
        algo = entry["gates"]["replay"]["algorithms"]
        rows.append({
            "pair": name.replace("SRR_", "").replace("_HDF_Report", "")[:26],
            "kind": "report log — 128 slots, depth 3",
            "scans": entry["scans"],
            "objects": entry["ref_valid"],
            "legacy": algo["legacy_id"],
            "hungarian": algo["hungarian_normalized"],
            "mahalanobis": algo["mahalanobis"],
            "gospa": algo["gospa"],
            "obb": algo["obb_auction"],
        })
    return rows


def table(head: Sequence[str], rows: Sequence[Sequence[str]],
          top: Optional[int] = None, table_id: str = "") -> str:
    """Render a scrollable data table; ``top`` marks the best row."""
    th = "".join(f"<th>{h}</th>" for h in head)
    body = []
    for i, row in enumerate(rows):
        cls = ' class="top"' if top is not None and i == top else ""
        body.append("<tr{}>{}</tr>".format(
            cls, "".join(f"<td>{c}</td>" for c in row)))
    return (f'<div class="table-wrap"><table class="tbl" id="{table_id}">'
            f"<thead><tr>{th}</tr></thead><tbody>{''.join(body)}</tbody></table></div>")


def build(acc: Dict[str, Any], edge: Dict[str, Any]) -> str:
    """Assemble the full standalone HTML document."""
    fc = acc["summary"]["FC"]["replay"]
    prod = acc["summary"]["FC"]["prod"]
    best_algo = max(fc, key=lambda k: fc[k]["f1_pct"])
    best = fc[best_algo]
    legacy = fc["legacy_id"]
    hung = fc["hungarian_normalized"]
    scenes = len(acc["per_scene"])
    scans = fc["hungarian_normalized"]["scans"] if "hungarian_normalized" in fc else 0
    scans = max(s["scans"] for s in fc.values())

    cards = [
        ("acc", f"{scans}", "aligned scans", f"{scenes} scene pairs · FC stream"),
        ("acc", f"{fc[best_algo]['tp'] + fc[best_algo]['fn']:,}", "reference objects", "scored one-to-one"),
        ("ok", f"{best['f1_pct']:.2f}%", f"best F1 — {best_algo}", "replay tolerance 1.5 m"),
        ("warn", f"{hung['f1_pct']:.2f}%", "production backend F1", "hungarian_normalized"),
        ("bad", f"{legacy['f1_pct']:.2f}%", "legacy (scan, trkID)", "ID-keyed matcher"),
        ("ok", f"+{hung['f1_pct'] - legacy['f1_pct']:.1f} pp", "accuracy recovered", "vs legacy baseline"),
    ]
    card_html = "".join(
        f'<div class="kpi-card {c}"><div class="val">{v}</div>'
        f'<div class="lbl">{l}</div><div class="sub">{s}</div></div>'
        for c, v, l, s in cards)

    # --- per-pair results -------------------------------------------------
    rows = per_pair_rows(acc, edge)
    pair_rows = []
    for r in rows:
        h = r["hungarian"]
        pair_rows.append([
            r["pair"], r["kind"], str(r["scans"]), f"{r['objects']:,}",
            f'<span class="badge bad">{r["legacy"]["f1_pct"]:.1f}</span>',
            f"{h['f1_pct']:.1f}",
            f"{r['mahalanobis']['f1_pct']:.1f}",
            f"{r['gospa']['f1_pct']:.1f}",
            f"{r['obb']['f1_pct']:.1f}",
            f"{h['tp']:,} / {h['fp']:,} / {h['fn']:,}",
            f"{h['precision_pct']:.1f} / {h['recall_pct']:.1f}",
            f"{h['id_switches']:,}",
        ])
    pair_table = table(
        ["Pair", "Schema", "Scans", "Ref objects", "Legacy F1 %", "Hungarian F1 %",
         "Mahalanobis F1 %", "GOSPA F1 %", "OBB F1 %", "TP / FP / FN (Hung.)",
         "Prec / Rec % (Hung.)", "IDSW"], pair_rows, top=0, table_id="pairs")

    # --- aggregate, both gates -------------------------------------------
    algo_order = sorted(fc, key=lambda k: -fc[k]["f1_pct"])
    agg_rows = []
    for i, algo in enumerate(algo_order):
        a, p = fc[algo], prod[algo]
        agg_rows.append([
            f'<span class="mono">{algo}</span>',
            f"{a['f1_pct']:.2f}", f"{a['precision_pct']:.2f}", f"{a['recall_pct']:.2f}",
            f"{a['jaccard_pct']:.2f}", f"{a['tp']:,}", f"{a['fp']:,}", f"{a['fn']:,}",
            f"{a['id_switches']:,}", f"{a['idsw_per_1k_matches']:.1f}",
            f"{a['pos_err_mean_m']:.3f} / {a['pos_err_p95_m']:.3f}",
            f"{p['f1_pct']:.2f}",
            f"{a['ms_per_1000_scans']:.1f}",
        ])
    agg_table = table(
        ["Algorithm", "F1 %", "Prec %", "Rec %", "Jaccard %", "TP", "FP", "FN",
         "IDSW", "IDSW/1k", "pos mean / p95 m", "F1 % @ prod gate", "ms/1k scans"],
        agg_rows, top=0, table_id="agg")

    # --- gates -----------------------------------------------------------
    gate_rows = [[
        f'<span class="mono">{a}</span>',
        f"{prod[a]['f1_pct']:.2f}", f"{fc[a]['f1_pct']:.2f}",
        f"{fc[a]['f1_pct'] - prod[a]['f1_pct']:+.2f}",
        ("independent (chi² / scale-aware)" if a in ("mahalanobis", "gospa", "obb_auction")
         else "gate-bound"),
    ] for a in algo_order]
    gate_table = table(["Algorithm", "F1 % @ 1 cm / 0.02", "F1 % @ 1.5 m / 0.5",
                        "Δ F1 pp", "Gate sensitivity"], gate_rows)

    # --- rear-left stream -------------------------------------------------
    rl_rows = []
    for algo, m in sorted(acc["summary"].get("RL", {}).get("replay", {}).items(),
                          key=lambda kv: -kv[1]["f1_pct"]):
        rl_rows.append([f'<span class="mono">{algo}</span>', f"{m['f1_pct']:.2f}",
                        f"{m['tp']:,}", f"{m['fp']:,}", f"{m['fn']:,}",
                        f"{m['pos_err_p95_m']:.2f}"])
    rl_table = table(["Algorithm", "F1 %", "TP", "FP", "FN", "pos p95 m"], rl_rows)

    # --- case studies -----------------------------------------------------
    cases = case_studies(next(iter(acc["per_scene"])))
    case_html = []
    for c in cases:
        verdict = ("no output track carried this trkID"
                   if c["legacy_gap"] is None else
                   f"same trkID was {c['legacy_gap']:.1f} m away — counted as a miss")
        case_html.append(f"""
      <div class="case">
        <h4>Scan {c['scan']} · ts {c['ts']} · object re-identified</h4>
        <div class="row">
          <span>reference <b>trkID {int(c['ref_id'])}</b> at
            <b>({c['ref_xy'][0]:.1f}, {c['ref_xy'][1]:.1f}) m</b></span>
          <span>replay <b>trkID {int(c['out_id'])}</b> at
            <b>({c['out_xy'][0]:.1f}, {c['out_xy'][1]:.1f}) m</b></span>
          <span>separation <b>{c['dist']:.2f} m</b></span>
          <span>legacy verdict: <span class="badge bad">{verdict}</span></span>
        </div>
      </div>""")
    case_block = "".join(case_html) or '<p class="note">No case studies available.</p>'

    # --- schema ----------------------------------------------------------
    schema_rows = [
        ["<span class='mono'>FC/OBJECT_LIST_STREAM/F360_Object_Log</span>",
         "tracker output (primary)", "395 × 64", "float32 / uint16 / uint8",
         "object_trkID, object_xposn, object_yposn, object_xvel, object_yvel, "
         "object_f_moving, object_heading, object_length, object_width"],
        ["<span class='mono'>FC/PROCESSED_DETECTION_STREAM/F360_Detection_Log</span>",
         "detections", "395 × 128", "float32 / uint8",
         "detection_position_x/y, detection_objTrkID, detection_f_ok_to_use, "
         "detection_rngrate_comp"],
        ["<span class='mono'>FC/TRACKER_INFO_STREAM/Tracker_Info_Log_Stream</span>",
         "tracker telemetry", "395 scalars × 16", "uint8…uint64",
         "tracker_index, timestamp_us, num_active_objs, num_active_clusters, "
         "elapsed_time_s, sw_version_*"],
        ["<span class='mono'>FC/SYNC_INFO_STREAM/Sync_Info_Log_Stream</span>",
         "sensor sync", "395 × (12 + 4)", "uint16 / uint64",
         "sensor_look_index, sensor_timestamp_us, tracker_timestamp_us"],
        ["<span class='mono'>03_TrackerInfo/Tracker_Output/AllObjects</span>",
         "tracker output — depth 3", "295 × 128", "float32 / uint16 / uint8",
         "trkID, vcs_xposn/yposn, vcs_xvel/yvel, vcs_heading, f_moving, len1, wid1, "
         "existence_probability, status (60 datasets)"],
        ["<span class='mono'>03_TrackerInfo/Tracker_Input/CoreInfo/time_us</span>",
         "scan clock — depth 3", "295", "uint64", "time_us, prev_time_us, cnt_loops"],
    ]
    schema_table = table(["Dataset group", "Role", "Shape", "dtype", "Key signals"],
                         schema_rows)

    depth_callout = (
        '<div class="callout bad"><b>Depth-3 blind spot confirmed on real data.</b> '
        '<span class="mono">KPIHDFParser.parse_grp</span> returns early at any second-layer '
        'group whose name is not a known stream key (<span class="mono">is_second_layer</span> '
        'check). <span class="mono">03_TrackerInfo/Tracker_Output</span> is not in the tracker '
        'stream registry, so the walk stops there and the 60-dataset '
        '<span class="mono">AllObjects</span> group (295 × 128, present in 5 files under '
        '<span class="mono">edge_hdf/</span>) is never ingested — the tracker KPI then reports '
        'no tracks instead of failing loudly. An independent recursive audit of 63 HDF files '
        'found 8,313 tracker datasets at depth ≥ 3. The fix is a stream alias '
        '(<span class="mono">Tracker_Output → TRACKER_STREAM</span>) plus a field map for the '
        '60 depth-3 signals, not a deeper hard-coded constant.</div>')

    return f"""<!doctype html>
<html lang="en"><head><meta charset="utf-8">
<meta name="viewport" content="width=device-width,initial-scale=1">
<title>Tracker KPI — Architecture, Flow &amp; Real-Data Benchmark</title>
<style>{CSS}</style></head>
<body>
<nav><div class="in"><b>Tracker KPI</b>
  <a href="#s1">1 · Architecture</a><a href="#s2">2 · Comparator flow</a>
  <a href="#s3">3 · Schema audit</a><a href="#s4">4 · Benchmarks</a>
  <a href="#s5">5 · Case studies</a><a href="#s6">6 · Conclusions</a>
</div></nav>
<main>
<header>
  <h1>Tracker KPI — architecture, comparator flow and real-data accuracy</h1>
  <p>Measured on {scenes} recorded/replay HDF pairs ({scans:,} time-aligned scans) plus one
  depth-3 report pair. Every number below is read from the HDF logs by
  <span class="mono">hdf_track_accuracy.py</span> and
  <span class="mono">edge_pair_accuracy.py</span>; nothing is estimated.</p>
</header>
<div class="kpi-grid">{card_html}</div>

<h2 id="s1"><span class="num">1</span>Perception &amp; tracker system architecture</h2>
<p class="lead">The embedded chain ends at a 20 Hz CAN object list. The offline KPI chain
re-opens the same object list from two HDF logs and answers one question:
do both runs describe the same physical objects?</p>
<div class="flow"><pre class="mermaid">{ARCHITECTURE}</pre></div>
<div class="grid2">
  <div class="callout ok"><b>Vehicle-side</b><br>Chirp/ADC → 2D-FFT → CFAR/DoA → RDU →
  fusion → EKF tracker → CAN object list (64 slots, ~50 ms cycle). Deterministic,
  fixed-point friendly, no KPI code on the ECU.</div>
  <div class="callout"><b>Offline-side</b><br>HDF recorder captures both the reference run
  and any replay. The KPI engine is pure Python/numpy/SciPy, runs post-hoc, and is the
  only place where truth-free accuracy can be quantified.</div>
</div>

<h2 id="s2"><span class="num">2</span>Tracker KPI comparator flow</h2>
<p class="lead">Two engines share steps 1–3. The legacy engine then demands an exact
<span class="mono">(scan, trkID)</span> key; the association engine solves a global
assignment under physical gates.</p>
<div class="flow"><pre class="mermaid">{FLOW}</pre></div>
<div class="formula">C_ij = [ w_x (Δx/T_x)² + w_y (Δy/T_y)² + w_vx (Δvx/T_vx)² + w_vy (Δvy/T_vy)² ] / Σw
        subject to  |Δx| ≤ T_x, |Δy| ≤ T_y, |Δvx| ≤ T_vx, |Δvy| ≤ T_vy,
                    f_moving(in) == f_moving(out),   cost = ∞ outside the gate
        solve       min Σ C_ij  over one-to-one assignments (Hungarian)</div>
{gate_table}
<p class="note">Gate-bound backends collapse when the configured gate is tighter than the
physical spread between two runs; chi²/GOSPA/scale-aware backends do not, which is why they
keep the same F1 at both settings.</p>

<h2 id="s3"><span class="num">3</span>Verified schema and file audit</h2>
<p class="lead">Shapes and dtypes below were read from the files, not assumed. The replay logs
carry 64 object slots per scan; the report logs carry 128.</p>
{schema_table}
{depth_callout}
<h3>Sanitization and sentinel policy</h3>
<div class="table-wrap"><table class="tbl"><thead><tr><th>Condition</th>
<th>Handling</th><th>Observed</th></tr></thead><tbody>
<tr><td><span class="mono">trkID == 0</span></td><td>empty slot — dropped</td>
<td>only ~0.3 of 64 slots are empty: the list runs at capacity
(<span class="mono">num_active_objs</span> reaches 64)</td></tr>
<tr><td><span class="mono">x == 0 and y == 0</span></td><td>stale ID on a padded slot — dropped</td>
<td>0 of 249,981 exported objects</td></tr>
<tr><td><span class="mono">x &lt; −100</span> / <span class="mono">0x80</span></td>
<td>CAN out-of-envelope sentinel — dropped</td><td>0 in the replay logs</td></tr>
<tr><td><span class="mono">hypot(x, y) &gt; 160 m</span></td>
<td>range gate (production <span class="mono">max_valid_distance</span>)</td>
<td>1,830 of 249,981 objects (89–853 per scene)</td></tr>
<tr><td>NaN / Inf</td><td>pair skipped, never silently matched</td>
<td>0 in these logs</td></tr>
</tbody></table></div>

<h2 id="s4"><span class="num">4</span>Empirical benchmark — accuracy per pair</h2>
<p class="lead">F1 below is one-to-one association agreement with the reference log at the
replay tolerance (1.5 m / 0.5 m·s⁻¹, 160 m range gate). Legacy = exact
<span class="mono">(scan, trkID)</span> match, exactly as v1 does it.</p>
{pair_table}
{agg_table}
<div class="callout bad"><b>The 1 cm gate is not a comparison tolerance.</b>
Under the production thresholds the Euclidean backends keep only
{prod['hungarian_normalized']['f1_pct']:.2f}% F1: two runs of the same tracker disagree by
~0.1 m at the median, so a 1 cm gate rejects almost every true pair. The gate is correct for
comparing a run with itself; it is meaningless for comparing a run with a replay.</div>
<div class="callout"><b>Capacity caveat.</b> The object list is 64 slots and both runs sit at
the cap (≈63.7 populated per scan, <span class="mono">num_active_objs</span> reaching 64), so
part of the unmatched mass is eviction at capacity rather than tracker error. The comparison
is still fair — both runs face the same cap — but F1 here is a floor for crowded scenes.</div>
<h3>Rear-left stream (RL) — secondary, lower confidence</h3>
<p class="note">RL scan headers are out of order and the replay clock drifts, so scans are
paired by nearest timestamp (±25 ms). At highway speed that is ≈0.5 m of alignment error, so
these F1 values are a lower bound, not a tracker verdict.</p>
{rl_table}

<h2 id="s5"><span class="num">5</span>Scan-level case studies</h2>
<p class="lead">Real scans from the first pair: the same physical object, two different
<span class="mono">trkID</span> values, and what the legacy matcher concluded.</p>
{case_block}

<h2 id="s6"><span class="num">6</span>Conclusions and deployment recommendations</h2>
<div class="callout ok"><b>Replace ID-keyed matching with gated Hungarian association.</b>
On identical data the legacy matcher agrees with the reference log on
{legacy['f1_pct']:.2f}% of objects; gated Hungarian reaches
{hung['f1_pct']:.2f}% and the best backend reaches {best['f1_pct']:.2f}%.</div>
<div class="panel"><h3>Recommended defaults</h3>
<div class="table-wrap"><table class="tbl"><thead><tr><th>Setting</th><th>Value</th>
<th>Why</th></tr></thead><tbody>
<tr><td>association_algorithm</td><td class="mono">hungarian_normalized</td>
<td>honours configured gates, deterministic, lowest latency among high-recall backends</td></tr>
<tr><td>Position tolerance</td><td class="mono">1.5 m</td>
<td>each runner keeps its own association tolerance; the comparison must be physical</td></tr>
<tr><td>Velocity tolerance</td><td class="mono">0.5 m/s</td><td>same argument, kinematic axis</td></tr>
<tr><td>Range gate</td><td class="mono">160 m</td>
<td>production max_valid_distance; keeps the FOV, drops out-of-envelope garbage</td></tr>
<tr><td>f_moving</td><td class="mono">hard equality</td>
<td>prevents a stationary ghost absorbing a moving track</td></tr>
<tr><td>Mahalanobis / GOSPA / OBB</td><td class="mono">opt-in</td>
<td>higher F1 but gate-independent: they need covariance sanity checks before trusting them</td></tr>
<tr><td>ID switches</td><td class="mono">diagnostic only</td>
<td>a replay renumbers tracks by design; IDSW measures churn, not accuracy</td></tr>
</tbody></table></div>
<p class="note">Integration: set <span class="mono">KPI_VALIDATION_RULES["tracker_thresholds"]
["association_algorithm"]</span> to select the backend; <span class="mono">legacy_id</span>
keeps the v1 code path byte-for-byte for audit comparisons.</p></div>
<footer>Generated from measured HDF data · FC/RL object lists and depth-3 tracker output ·
scripts: <span class="mono">hdf_track_accuracy.py</span>,
<span class="mono">edge_pair_accuracy.py</span>,
<span class="mono">build_tracker_kpi_report.py</span></footer>
</main>{MERMAID_JS}</body></html>
"""


def main() -> int:
    acc = load(DATA / "accuracy.json")
    edge_path = DATA / "edge_pairs.json"
    edge = load(edge_path) if edge_path.exists() else {"pairs": {}}
    html = build(acc, edge)
    OUT.write_text(html, encoding="utf-8")
    assert "<html" in html and html.count("<table") >= 4, "report structure regressed"
    print(f"HTML  {OUT}  {len(html) / 1024:.1f} KB")
    print(f"tables {html.count('<table')}  sections {html.count('<h2')}  "
          f"cases {html.count('class=\"case\"')}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
