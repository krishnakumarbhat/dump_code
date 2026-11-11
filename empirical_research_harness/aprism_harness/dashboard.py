"""Master research-benchmark dashboard generator.

Builds a single self-contained HTML portal comparing BASELINE vs A-PRISM for
every concept, with the governing formula, the measured metrics and the
interactive figures.
"""
from __future__ import annotations

import html
import json
import os
from typing import Any, Dict, List, Optional

from .concept_api import fmt

FORMULAS: Dict[int, str] = {
    1: "residual phase  phi = atan2(Im(x[n] conj(x[n-1])), Re(x[n] conj(x[n-1])));  "
       "baseline lag-1 over N samples vs A-PRISM 3-product cubic stencil",
    2: "eta_j = wrap(meas_j - pred_j);  f_h = (26*e0 - ep - em)/24  (cubic-exact 4-point, 3 products)",
    3: "floor[r] += lambda*(median(free cells) - floor[r]);  "
       "snr = row/floor - 1;  ratio = clamp(alpha_BLUE/alpha_CA, 0.5, 2)",
    4: "BLUE:  m = 1 + pi*s;  v = 2(1 - pi + pi(1+s)^2) - m^2;  w = m/v;  beta = w / sum(m*w);  "
       "alpha solves  sum ln(1 + a*beta_i) = -ln(Pfa)",
    5: "score = 10^(SNR_dB/10) / r^2 ;  CdcSelectTopK -> reorder (count unchanged)",
    6: "ell^2 > |p-s|^2 ;  B = ell - u.d ;  t = (ell^2 - d^2)/(2B) ;  rho = ell - t ;  "
       "q = s + t*u ;  a = (p-q)/rho ;  n = normalize(a-u)",
    7: "K_DA(n) = k_fast*exp(-alpha*n) + k_slow ;  lock after N consecutive |err| <= tol ;  "
       "preflight caps num_updates at 50 (baseline 400)",
    8: "seed accepted iff |az| <= 5 deg AND |el| <= 2 deg AND QF > 0 ;  else cold-start static "
       "(-1.145, -0.018) deg",
    9: "IMM mode switch needs 2 confirmed observations;  A-PRISM replaces the fixed gate with "
       "Gamma_ad = clamp(9.21*(1 + 0.8*a_norm + 0.5*eps), 9.21, 40)",
    10: "Gamma_ad = clamp(9.21*(1 + 0.8*|a|/3 + 0.5*eps), 9.21, 40) ;  widen = Gamma_ad/9.21",
    11: "Gaussian gate:  eps ~ N(0, S) -> chi^2 ;  conformal gate:  eps <= Quantile_{1-alpha}(|eps|) "
        "(empirical CDF)",
    12: "rank gate:  scale = 1 while qseen < qneed ;  else scale = factor (frozen, bounded)",
    13: "|v_r - u.v| <= 3*sqrt(sigma_v^2 + S_v)   (Doppler-invariant ghost rejection)",
    14: "|| p - p_s - 2*d*n || <= 1.0 m   (rank-1 specular invariant) ;  s_virtual = 2*d*n",
    15: "Joseph form:  P+ = (I-KH)P(I-KH)' + K R K' ;  bistatic virtual aperture adds a second "
        "range-rate measurement to fuse",
    16: "R_i = k_ref * (max_dets/N_i) * exp(beta*H/snr)   (spectral-entropy covariance scaling)",
    17: "2-point cubic Hermite on the confluent Vandermonde  [[1,x,x^2,x^3],[0,1,2x,3x^2],...] ;  "
        "curvature guard |g'| <= 2*kappa_max*rho_max",
    18: "XOR: mp_flag != reflective_flag ;  sentinel mirror_prob = -1.0 marks an assimilated track "
        "and is never decayed",
    19: "deskew:  p' = R_z(omega*dt) p - v*dt - 0.5*a*dt^2",
    20: "1 target:  tau = (r*w - d.v)/|v|^2 ;  2 targets:  D = a1*r2 - a2*r1 ;  "
        "tau = (y1*r2 - y2*r1)/D ;  b = (a1*y2 - a2*y1)/D",
    21: "H = sum_i D_i conj(D_j) ;  delta = arg(H) ;  relative yaw cancels the absolute mounting yaw ;  "
        "certificate rho = 4*eps/lmin + (2*eps/lmin)^2",
    22: "fleet replay: adaptive gate + rank gate + XOR sentinel vs fixed gate",
    23: "R^-4 spreading loss ;  weighted-centroid peak alignment vs magnitude-only alignment",
    24: "Blelloch prefix-scan: serial depth N vs 2*log2(N) tree levels ;  result equivalence asserted",
    25: "near-far power normalisation + ghost-conditioned augmentation ;  PR curve",
    26: "quadratic invariant lifting makes the measurement update close linearly ;  "
        "closure residual -> 0",
    27: "guard radius h_k from the certified error transfer bound ;  track-ID equivalence across "
        "shard splits",
}


# Explicit polarity map. Without it every positive delta was flagged
# "(worse)", so a perfect ROC AUC (0.28 -> 1.00) rendered as +254.5% (worse).
HIGHER_IS_BETTER = frozenset({
    "roc_auc", "pr_auc", "auc", "recall", "weak_target_recall", "recall_true",
    "recall_true_association", "recall_at_onset", "span_reduction_factor",
    "id_equivalent_frames", "true_associations_retained", "jaccard",
    "accuracy", "near_retention_top8", "near_retention_top16",
    "correct_selection", "gate_pass_h1", "gate_pass_h2", "valid_rate",
    "coverage_frac", "true_suppressions", "accepted_rate", "sentinel_respected",
    "cert_valid",
})
LOWER_IS_BETTER = frozenset({
    "rmse", "rmse_spray", "rmse_after", "false_associations",
    "false_associations_per_frame", "false_assoc_per_frame",
    "id_switches", "id_changed_frames", "false_accept_rate_decoy",
    "false_accept_rate_tail", "false_alarm_rate", "runtime_ms", "latency",
})

# Substring fallbacks for the families above (rmse_m, position_rmse_m, ...).
_LOWER_TOKENS = (
    "rmse", "false_associat", "false_assoc", "id_switch", "id_changed",
    "runtime_ms", "latency", "false_accept_rate", "false_alarm",
    "false_suppression", "ghosts_assimilated", "mults", "serial_depth",
    "frames_to_", "err_", "_err", "violations", "residual",
)
_HIGHER_TOKENS = (
    "roc_auc", "pr_auc", "recall", "accuracy", "jaccard", "auc",
    "span_reduction", "id_equivalent", "retention", "valid_rate",
    "coverage", "true_suppression", "gate_pass", "associations_retained",
)


def metric_direction(metric: Optional[str]) -> int:
    """+1 when higher is better, -1 when lower is better, 0 when unknown.

    Unknown metrics get NO polarity label - guessing would just replace one
    wrong arrow with another.
    """
    if not metric:
        return 0
    m = str(metric).strip().lower()
    if m in HIGHER_IS_BETTER:
        return 1
    if m in LOWER_IS_BETTER:
        return -1
    # lower-priority families first so "false_suppressions" is not read as
    # "suppressions" (higher) and "id_changed_frames" is not read as "frames".
    if any(t in m for t in _LOWER_TOKENS):
        return -1
    if any(t in m for t in _HIGHER_TOKENS):
        return 1
    return 0


def _delta_cell(base: Any, after: Any, metric: Optional[str] = None) -> str:
    """Percentage change, labelled (better)/(worse) using the metric's polarity."""
    try:
        b = float(base)
        a = float(after)
    except (TypeError, ValueError):
        return ""
    if abs(b) < 1e-12:
        return ""
    change = 100.0 * (a - b) / b
    direction = metric_direction(metric)
    if direction == 0:
        return f"{change:+.1f}%"
    if abs(change) < 1e-12:
        return f"{change:+.1f}% (same)"
    improved = (change > 0) if direction > 0 else (change < 0)
    return f"{change:+.1f}% ({'better' if improved else 'worse'})"


def _delta_html(base: Any, after: Any, metric: Optional[str]) -> str:
    """_delta_cell wrapped in a colour class (green better, red worse)."""
    txt = _delta_cell(base, after, metric)
    if not txt:
        return ""
    cls = "neutral"
    direction = metric_direction(metric)
    try:
        b, a = float(base), float(after)
        change = 100.0 * (a - b) / b
        if direction > 0:
            cls = "better" if change > 0 else ("worse" if change < 0 else "neutral")
        elif direction < 0:
            cls = "better" if change < 0 else ("worse" if change > 0 else "neutral")
    except (TypeError, ValueError, ZeroDivisionError):
        pass
    return f'<span class="{cls}">{txt}</span>'


def build_dashboard(results: List[Dict[str, Any]], out_html: str,
                    artifacts: Dict[int, List[Dict[str, Any]]],
                    meta: Dict[str, Any]) -> str:
    """Render the master portal."""
    e = html.escape
    parts: List[str] = []
    parts.append(f"""<!DOCTYPE html>
<html lang="en"><head><meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>APRISM Empirical Research Benchmarks</title>
<script src="https://cdn.plot.ly/plotly-2.35.2.min.js" charset="utf-8"></script>
<style>
  :root {{ --bg:#0b1020; --panel:#141a30; --line:#253056; --fg:#e8ecf8; --mut:#93a0c4;
           --ok:#2ecc71; --bad:#e74c3c; --base:#e67e22; --after:#3498db; }}
  * {{ box-sizing:border-box; }}
  body {{ margin:0; background:var(--bg); color:var(--fg);
         font-family:"Segoe UI",system-ui,-apple-system,sans-serif; }}
  header {{ padding:28px 32px; background:linear-gradient(135deg,#0d1330,#1b2a55);
            border-bottom:1px solid var(--line); }}
  h1 {{ margin:0 0 6px; font-size:25px; letter-spacing:.3px; }}
  .sub {{ color:var(--mut); font-size:13.5px; }}
  .wrap {{ max-width:1500px; margin:0 auto; padding:22px 26px 60px; }}
  .meta {{ display:flex; gap:26px; flex-wrap:wrap; margin-top:16px; font-size:12.5px; color:var(--mut); }}
  .meta b {{ color:var(--fg); }}
  table {{ width:100%; border-collapse:collapse; font-size:13px; margin-bottom:8px; }}
  th,td {{ border:1px solid var(--line); padding:7px 9px; text-align:left; vertical-align:top; }}
  th {{ background:#1a2240; font-weight:600; }}
  tr:nth-child(even) td {{ background:#10162b; }}
  .card {{ background:var(--panel); border:1px solid var(--line); border-radius:10px;
           margin:18px 0; padding:18px 20px; }}
  .card h2 {{ margin:0 0 4px; font-size:18px; }}
  .src {{ color:var(--mut); font-size:12px; font-family:Consolas,monospace; word-break:break-all; }}
  .formula {{ background:#0e1428; border-left:3px solid var(--after); padding:9px 12px;
              margin:11px 0; font-family:Consolas,monospace; font-size:12.5px; color:#cfe0ff;
              white-space:pre-wrap; }}
  .notes {{ color:var(--mut); font-size:12.5px; margin-top:8px; }}
  .base {{ color:var(--base); }} .after {{ color:var(--after); }}
  .better {{ color:var(--ok); font-weight:600; }}
  .worse {{ color:var(--bad); font-weight:600; }}
  .neutral {{ color:var(--mut); }}
  .frame {{ width:100%; height:640px; border:1px solid var(--line); border-radius:8px;
            background:#0a0f20; margin-top:12px; }}
  .links a {{ color:#7fb3ff; margin-right:14px; font-size:12.5px; }}
  .tag {{ display:inline-block; padding:1px 8px; border-radius:10px; font-size:11px;
          border:1px solid var(--line); color:var(--mut); margin-left:8px; }}
</style></head><body>
<header>
  <h1>APRISM &mdash; Empirical Research Benchmarks</h1>
  <div class="sub">Baseline (production path, feature OFF) vs A-PRISM (research path, feature ON).
  Every value below is <b>measured</b> by executing 1:1 Python mirrors of the production C/C++ kernels
  on physics-grounded fixtures. No result is hardcoded.</div>
  <div class="meta">
    <div>concepts: <b>{len(results)}</b></div>
    <div>generated: <b>{e(str(meta.get('generated', '')))}</b></div>
    <div>seeds: <b>{e(str(meta.get('seeds', '')))}</b></div>
    <div>elapsed: <b>{meta.get('elapsed_s', 0):.1f}s</b></div>
    <div>figures: <b>{sum(len(v) for v in artifacts.values())}</b></div>
  </div>
</header>
<div class="wrap">
<h3 style="margin-top:6px">Summary</h3>
<table id="summary"><thead><tr>
  <th>#</th><th>Concept</th><th>Key metric</th><th class="base">Baseline</th>
  <th class="after">A-PRISM</th><th>Change</th><th>Figures</th>
</tr></thead><tbody></tbody></table>
""")

    rows = []
    for r in results:
        b_m = r["baseline"]["metrics"]
        a_m = r["aprism"]["metrics"]
        # pick the headline metric: first shared key
        shared = [k for k in b_m if k in a_m]
        if not shared:
            shared = list(b_m.keys())[:1]
        key = shared[0] if shared else ""
        rows.append(
            f"<tr><td>{r['id']}</td><td>{e(r['title'])}</td>"
            f"<td>{e(key)}</td><td class='base'>{e(fmt(b_m.get(key)))}</td>"
            f"<td class='after'>{e(fmt(a_m.get(key)))}</td>"
            f"<td>{_delta_html(b_m.get(key), a_m.get(key), key)}</td>"
            f"<td>{len(artifacts.get(r['id'], []))}</td></tr>"
        )
    parts.append("".join(rows))
    parts.append("</tbody></table>")

    for r in results:
        cid = r["id"]
        b_m = r["baseline"]["metrics"]
        a_m = r["aprism"]["metrics"]
        all_keys = list(b_m.keys()) + [k for k in a_m if k not in b_m]
        mrows = []
        for k in all_keys:
            b_v = b_m.get(k)
            a_v = a_m.get(k)
            mrows.append(
                f"<tr><td>{e(str(k))}</td><td class='base'>{e(fmt(b_v))}</td>"
                f"<td class='after'>{e(fmt(a_v))}</td><td>{_delta_html(b_v, a_v, k)}</td></tr>"
            )
        arts = artifacts.get(cid, [])
        links = " ".join(
            f'<a href="{e(os.path.relpath(a["html"], os.path.dirname(out_html)))}" target="_blank">HTML</a>'
            + (f'<a href="{e(os.path.relpath(a["png"], os.path.dirname(out_html)))}" target="_blank">PNG</a>'
               if a.get("png") else "")
            for a in arts
        )
        frames = "".join(
            f'<iframe class="frame" src="{e(os.path.relpath(a["html"], os.path.dirname(out_html)))}"></iframe>'
            for a in arts
        )
        formula = FORMULAS.get(cid, "")
        parts.append(f"""
<div class="card" id="c{cid}">
  <h2>{cid}. {e(r['title'])}<span class="tag">{e(r['baseline']['label'])} &rarr; {e(r['aprism']['label'])}</span></h2>
  <div class="src">{e(r['source'])}</div>
  <div class="formula">{e(formula)}</div>
  <table><thead><tr><th>Metric</th><th class="base">Baseline</th><th class="after">A-PRISM</th><th>Change</th></tr></thead>
  <tbody>{''.join(mrows)}</tbody></table>
  {f'<div class="notes">{e(r["notes"])}</div>' if r.get('notes') else ''}
  <div class="links">{links}</div>
  {frames}
</div>""")

    parts.append("</div></body></html>")

    os.makedirs(os.path.dirname(out_html), exist_ok=True)
    with open(out_html, "w", encoding="utf-8") as f:
        f.write("".join(parts))
    return out_html
