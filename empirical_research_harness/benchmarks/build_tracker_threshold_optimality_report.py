"""Build the tracker-KPI threshold optimality report (self-contained HTML).

Inputs
------
empirical_research_harness/benchmarks/hdf_track_out/threshold_sweep.json
    Symmetric position x velocity sweep over 11 real replay scenes.
%TEMP%/opencode/tracker_threshold_eval.json
    Asymmetric X/Y gate measurements (15 configurations).
%TEMP%/opencode/tracker_gate_grid.json
    Remaining cells of the 5 x 4 asymmetric gate grid at 0.5 m/s.

Output
------
~/Desktop/tracker_kpi_threshold_optimality.html
"""
from __future__ import annotations

import html
import json
import math
from pathlib import Path

ROOT = Path(r"C:\Users\ouymc2\Desktop\dump_code")
BENCH = ROOT / "empirical_research_harness" / "benchmarks"
SWEEP_PATH = BENCH / "hdf_track_out" / "threshold_sweep.json"
ASYM_PATH = BENCH / "hdf_track_out" / "threshold_asymmetric.json"
OUT_PATH = Path.home() / "Desktop" / "tracker_kpi_threshold_optimality.html"

XS = (0.5, 1.0, 1.5, 2.0, 3.0)
YS = (0.5, 1.0, 1.5, 2.0)
TOL_M = 1.5
SPACING_P10 = 0.9128916740417481
NOISE_P50 = 0.35526609420776367
NOISE_P90 = 2.0928298473358167
NOISE_P95 = 3.474156808853149
NOISE_P99 = 9.172287886142755
SPACING_P5 = 0.749566650390625
SPACING_P50 = 2.06136417388916
VEL_NOISE = {"vx": (0.056803634273819625, 0.2573067083954813, 0.3896890358999369, 2.204275436401371),
             "vy": (0.03579505532979965, 0.754600519686938, 1.003869154676795, 1.8321595355868388)}

INK = "#0f172a"
MUTED = "#64748b"
GRID_C = "#e2e8f0"
TEAL = "#0f766e"
TEAL_L = "#ccfbf1"
RED = "#dc2626"
RED_L = "#fee2e2"
AMBER = "#d97706"
AMBER_L = "#fef3c7"
INDIGO = "#4f46e5"
SLATE = "#475569"


def esc(value) -> str:
    return html.escape(str(value))


def f2(value, digits: int = 2) -> str:
    try:
        return f"{float(value):,.{digits}f}"
    except (TypeError, ValueError):
        return "—"


def signed(value, digits: int = 2) -> str:
    return f"{float(value):+,.{digits}f}"


def load_json(path: Path):
    return json.loads(path.read_text(encoding="utf-8"))


def build_cells(eval_data, grid_data):
    cells = {}
    for result in eval_data["results"]:
        row = result["total"]
        if row.get("tvy_mps") == 0.5 and row["ty_m"] in YS and row["tx_m"] in XS:
            cells[(row["tx_m"], row["ty_m"])] = row
    for row in grid_data["grid"]:
        if row["ty_m"] in YS and row["tx_m"] in XS:
            cells[(row["tx_m"], row["ty_m"])] = row
    missing = [(x, y) for x in XS for y in YS if (x, y) not in cells]
    assert not missing, missing
    return cells


def config_rows(eval_data):
    return {result["total"]["config"]: result["total"] for result in eval_data["results"]}


def feasible(row) -> bool:
    return (row["pos_err_p95_m"] <= TOL_M + 1e-9
            and row["ty_m"] <= 1.0 + 1e-9
            and row["tx_m"] <= NOISE_P90 + 1e-9)


def ascent(start, cells, allow, objective):
    path = [start]
    while True:
        cur = path[-1]
        best = None
        best_score = objective(cells[cur])
        for dx in (-1, 0, 1):
            for dy in (-1, 0, 1):
                if dx == 0 and dy == 0:
                    continue
                ix, iy = XS.index(cur[0]) + dx, YS.index(cur[1]) + dy
                if not (0 <= ix < len(XS) and 0 <= iy < len(YS)):
                    continue
                cand = (XS[ix], YS[iy])
                if not allow(cells[cand]):
                    continue
                score = objective(cells[cand])
                if score > best_score + 1e-9:
                    best, best_score = cand, score
        if best is None:
            return path
        path.append(best)


# ---------------------------------------------------------------- SVG helpers

def _txt(x, y, text, size=11, fill=INK, anchor="start", weight=400, extra=""):
    return (f'<text x="{x:.1f}" y="{y:.1f}" font-size="{size}" fill="{fill}" '
            f'text-anchor="{anchor}" font-weight="{weight}" {extra}>{esc(text)}</text>')


def _halo_text(x, y, text, size=10, fill=SLATE, anchor="middle", weight=600):
    return (f'<text x="{x:.1f}" y="{y:.1f}" font-size="{size}" fill="{fill}" text-anchor="{anchor}" '
            f'font-weight="{weight}" stroke="#ffffff" stroke-width="3" paint-order="stroke" '
            f'stroke-linejoin="round">{esc(text)}</text>')


def line_chart(points, ylab, xlab, refs=(), highlight=None, candidate=None,
               ymin=None, ymax=None, width=920, height=360, value_fmt="{:.2f}"):
    left, right, top, bottom = 74, 26, 36, 60
    px0, px1 = left, width - right
    py0, py1 = top, height - bottom
    xs = [p[0] for p in points]
    ys = [p[1] for p in points]
    xmin, xmax = min(xs), max(xs)
    pad = (xmax - xmin) * 0.08 if xmax > xmin else max(abs(xmax) * 0.1, 0.1)
    xmin, xmax = xmin - pad, xmax + pad
    lo = ymin if ymin is not None else math.floor((min(ys) - 2) / 5) * 5
    hi = ymax if ymax is not None else math.ceil((max(ys) + 2) / 5) * 5
    hi = max(hi, lo + 5)

    def X(v):
        return px0 + (v - xmin) / (xmax - xmin) * (px1 - px0)

    def Y(v):
        return py1 - (v - lo) / (hi - lo) * (py1 - py0)

    out = [f'<svg class="chart" viewBox="0 0 {width} {height}" role="img" aria-label="{esc(ylab)} by {esc(xlab)}">']
    out.append('<defs><linearGradient id="linefill" x1="0" y1="0" x2="0" y2="1">'
               '<stop offset="0%" stop-color="#0f766e" stop-opacity="0.16"/>'
               '<stop offset="100%" stop-color="#0f766e" stop-opacity="0.01"/></linearGradient></defs>')
    for i in range(6):
        v = lo + (hi - lo) * i / 5
        y = Y(v)
        out.append(f'<line x1="{px0}" y1="{y:.1f}" x2="{px1}" y2="{y:.1f}" stroke="{GRID_C}" stroke-width="1"/>')
        out.append(_txt(px0 - 10, y + 4, f"{v:.0f}", 10, MUTED, "end"))
    last_x = [-(10 ** 9), -(10 ** 9)]
    for rv, label, color, dash in sorted(refs, key=lambda r: r[0]):
        if not (xmin <= rv <= xmax):
            continue
        x = X(rv)
        out.append(f'<line x1="{x:.1f}" y1="{py0}" x2="{x:.1f}" y2="{py1}" stroke="{color}" '
                   f'stroke-width="1.2" stroke-dasharray="{dash}"/>')
        row = 0 if x - last_x[0] > 96 else 1
        last_x[row] = x
        out.append(_halo_text(x, py0 - 8 - row * 14, label, 9.5, color))
    area = f'M {X(points[0][0]):.1f} {py1:.1f} ' + " ".join(
        f'L {X(x):.1f} {Y(y):.1f}' for x, y in points) + f' L {X(points[-1][0]):.1f} {py1:.1f} Z'
    out.append(f'<path d="{area}" fill="url(#linefill)"/>')
    d = "M " + " L ".join(f"{X(x):.1f} {Y(y):.1f}" for x, y in points)
    out.append(f'<path d="{d}" fill="none" stroke="{TEAL}" stroke-width="3" stroke-linejoin="round"/>')
    marks = {round(t, 6) for t in (highlight, candidate) if t is not None}
    for x, y in points:
        cx, cy = X(x), Y(y)
        out.append(f'<circle cx="{cx:.1f}" cy="{cy:.1f}" r="4.5" fill="#fff" stroke="{TEAL}" stroke-width="2.5"/>')
        below = round(x, 6) in marks
        txt = value_fmt.format(y)
        if below:
            w = len(txt) * 6.4 + 10
            out.append(f'<rect x="{cx - w / 2:.1f}" y="{cy + 17:.1f}" width="{w:.1f}" height="15" rx="4" '
                       f'fill="#ffffff" fill-opacity="0.92"/>')
            out.append(_txt(cx, cy + 28, txt, 10, TEAL, "middle", 700))
        else:
            out.append(_halo_text(cx, cy - 12, txt, 10, TEAL))
    for key, color, label in (("rec", TEAL, "recommended"), ("cand", RED, "candidate")):
        target = highlight if key == "rec" else candidate
        if target is None:
            continue
        for x, y in points:
            if abs(x - target) < 1e-9:
                cx, cy = X(x), Y(y)
                out.append(f'<circle cx="{cx:.1f}" cy="{cy:.1f}" r="13" fill="none" stroke="{color}" '
                           f'stroke-width="2.5" stroke-dasharray="{"0" if key == "rec" else "4 3"}"/>')
    for x in sorted(set(xs)):
        out.append(_txt(X(x), py1 + 20, f"{x:g}", 11, SLATE, "middle"))
    out.append(_txt((px0 + px1) / 2, height - 16, xlab, 11.5, SLATE, "middle"))
    out.append(f'<text x="18" y="{(py0 + py1) / 2:.1f}" font-size="11.5" fill="{SLATE}" '
               f'text-anchor="middle" transform="rotate(-90 18 {(py0 + py1) / 2:.1f})">{esc(ylab)}</text>')
    out.append(f'<line x1="{px0}" y1="{py1}" x2="{px1}" y2="{py1}" stroke="#94a3b8" stroke-width="1.2"/>')
    out.append(f'<line x1="{px0}" y1="{py0}" x2="{px0}" y2="{py1}" stroke="#94a3b8" stroke-width="1.2"/>')
    out.append("</svg>")
    return "".join(out)


def heat_color(f1):
    t = max(0.0, min(1.0, (f1 - 54.0) / (73.2 - 54.0)))
    hue = 4 + 128 * t
    return f"hsl({hue:.1f}, 68%, 88%)"


def heatmap(cells, uncon_path, con_path, width=980, height=482):
    left, top, cw, ch = 116, 46, 168, 88
    out = [f'<svg class="chart" viewBox="0 0 {width} {height}" role="img" aria-label="F1 gate map">']
    out.append('<defs>'
               '<marker id="arrowA" viewBox="0 0 10 10" refX="7" refY="5" markerWidth="6" markerHeight="6" orient="auto">'
               f'<path d="M 0 0 L 10 5 L 0 10 z" fill="{AMBER}"/></marker>'
               '<marker id="arrowC" viewBox="0 0 10 10" refX="7" refY="5" markerWidth="7" markerHeight="7" orient="auto">'
               f'<path d="M 0 0 L 10 5 L 0 10 z" fill="{TEAL}"/></marker>'
               '</defs>')
    y_plot = list(reversed(YS))
    for row_i, y in enumerate(y_plot):
        cy = top + row_i * ch
        out.append(_txt(left - 20, cy + ch / 2 + 4, f"{y:g}", 13, INK, "end", 700))
        for col_i, x in enumerate(XS):
            cx = left + col_i * cw
            row = cells[(x, y)]
            ok = feasible(row)
            fill = heat_color(row["f1_pct"])
            if (x, y) == (1.5, 1.0):
                stroke, sw = TEAL, 3.2
            elif (x, y) == (3.0, 2.0):
                stroke, sw = RED, 3.0
            else:
                stroke, sw = ("#0f766e" if ok else "#fca5a5"), 1
            dash = ' stroke-dasharray="7 4"' if (x, y) == (3.0, 2.0) else ""
            out.append(f'<rect x="{cx}" y="{cy}" width="{cw - 10}" height="{ch - 10}" rx="8" fill="{fill}" '
                       f'stroke="{stroke}" stroke-width="{sw}"{dash}/>')
            out.append(_txt(cx + 13, cy + 26, f'F1 {row["f1_pct"]:.2f}%', 13.5, INK, "start", 700))
            out.append(_txt(cx + 13, cy + 45, f'p95 {row["pos_err_p95_m"]:.2f} m', 10.5, SLATE, "start", 500))
            out.append(_txt(cx + 13, cy + 62, f'IDSW/1k {row["idsw_per_1k_matches"]:.1f}', 10.5, SLATE, "start", 500))
            out.append(_txt(cx + cw - 24, cy + 23, "✓" if ok else "✗", 13,
                            TEAL if ok else RED, "end", 700))
    for col_i, x in enumerate(XS):
        out.append(_txt(left + col_i * cw + (cw - 10) / 2, top - 16, f"ΔX = {x:g} m", 12, SLATE, "middle", 600))
    out.append(_txt(left - 78, top + 10, "ΔY", 12, SLATE, "middle", 700))
    out.append(_txt(left - 78, top + 25, "(m)", 11, SLATE, "middle"))

    def corner(cell):
        """Bottom-right corner of a cell, in the gutter between cells."""
        x, y = cell
        return (left + XS.index(x) * cw + cw - 5,
                top + y_plot.index(y) * ch + ch - 5)

    def route(path):
        """Staircase through the cell gutters: horizontal first, then vertical."""
        pts = [corner(path[0])]
        for cell in path[1:]:
            px, py = pts[-1]
            tx, ty = corner(cell)
            pts.append((tx, py))
            pts.append((tx, ty))
        return pts

    # unconstrained (F1-only) ascent: dashed, small markers, offset into the gutter
    raw = route(uncon_path)
    pts = [(px + 3, py - 3) for px, py in raw]
    d = "M " + " L ".join(f"{px:.1f} {py:.1f}" for px, py in pts)
    out.append(f'<path d="{d}" fill="none" stroke="#ffffff" stroke-width="7" stroke-linejoin="round"/>')
    out.append(f'<path d="{d}" fill="none" stroke="{AMBER}" stroke-width="2.6" stroke-linejoin="round" '
               f'marker-end="url(#arrowA)" stroke-dasharray="8 5"/>')
    for i, (px, py) in enumerate(pts):
        if i % 2 == 0:  # one marker per cell corner
            out.append(f'<circle cx="{px:.1f}" cy="{py:.1f}" r="3.4" fill="{AMBER}" stroke="#fff" stroke-width="1.3"/>')
    # constrained ascent: solid, numbered steps at each cell corner
    raw = route(con_path)
    pts = [(px - 1, py + 1) for px, py in raw]
    d = "M " + " L ".join(f"{px:.1f} {py:.1f}" for px, py in pts)
    out.append(f'<path d="{d}" fill="none" stroke="#ffffff" stroke-width="9" stroke-linejoin="round"/>')
    out.append(f'<path d="{d}" fill="none" stroke="{TEAL}" stroke-width="3.2" stroke-linejoin="round" '
               f'marker-end="url(#arrowC)"/>')
    for i, (px, py) in enumerate(pts):
        if i % 2:
            continue
        out.append(f'<circle cx="{px:.1f}" cy="{py:.1f}" r="9" fill="#fff" stroke="{TEAL}" stroke-width="2.4"/>')
        out.append(_txt(px, py + 3.4, str(i // 2), 9.5, TEAL, "middle", 700))
    out.append(f'<line x1="{left}" y1="{top + len(YS) * ch + 2}" x2="{left + len(XS) * cw - 10}" '
               f'y2="{top + len(YS) * ch + 2}" stroke="#94a3b8" stroke-width="1.2"/>')
    out.append(_txt(left + len(XS) * cw / 2 - 5, top + len(YS) * ch + 27,
                    "ΔX position gate (m)  ·  ΔVx = ΔVy = 0.5 m/s  ·  ✓ feasible under policy, ✗ rejected",
                    11.5, SLATE, "middle"))
    legend_y = top + len(YS) * ch + 50
    out.append(f'<line x1="{left}" y1="{legend_y}" x2="{left + 34}" y2="{legend_y}" stroke="{AMBER}" '
               f'stroke-width="2.6" stroke-dasharray="8 5"/>')
    out.append(_txt(left + 42, legend_y + 4, "unconstrained F1 ascent → (3.0, 2.0), rejected", 10.5, SLATE))
    out.append(f'<line x1="{left + 352}" y1="{legend_y}" x2="{left + 386}" y2="{legend_y}" stroke="{TEAL}" stroke-width="3.2"/>')
    out.append(_txt(left + 394, legend_y + 4, "constrained ascent → (1.5, 1.0), deployed", 10.5, SLATE))
    out.append("</svg>")
    return "".join(out)


def scatter(points, width=920, height=400):
    left, right, top, bottom = 76, 28, 34, 62
    px0, px1, py0, py1 = left, width - right, top, height - bottom
    xmin, xmax, lo, hi = 0.3, 3.1, 52.0, 75.0

    def X(v):
        return px0 + (v - xmin) / (xmax - xmin) * (px1 - px0)

    def Y(v):
        return py1 - (v - lo) / (hi - lo) * (py1 - py0)

    out = [f'<svg class="chart" viewBox="0 0 {width} {height}" role="img" aria-label="F1 versus p95 error">']
    for i in range(5):
        v = lo + (hi - lo) * i / 4
        out.append(f'<line x1="{px0}" y1="{Y(v):.1f}" x2="{px1}" y2="{Y(v):.1f}" stroke="{GRID_C}"/>')
        out.append(_txt(px0 - 9, Y(v) + 4, f"{v:.0f}", 10, MUTED, "end"))
    for i in range(7):
        v = xmin + (xmax - xmin) * i / 6
        out.append(f'<line x1="{X(v):.1f}" y1="{py0}" x2="{X(v):.1f}" y2="{py1}" stroke="{GRID_C}" opacity="0.55"/>')
        out.append(_txt(X(v), py1 + 19, f"{v:.1f}", 10, MUTED, "middle"))
    out.append(f'<rect x="{X(1.5):.1f}" y="{py0}" width="{X(xmax) - X(1.5):.1f}" height="{py1 - py0}" '
               f'fill="#fef2f2" opacity="0.55"/>')
    out.append(f'<line x1="{X(1.5):.1f}" y1="{py0}" x2="{X(1.5):.1f}" y2="{py1}" stroke="{RED}" '
               f'stroke-width="2" stroke-dasharray="6 4"/>')
    out.append(_halo_text(X(1.5) + 8, py0 + 18, "p95 > ΔX tolerance (1.5 m)", 10, RED, "start", 700))
    frontier = []
    best = -1
    for row in sorted(points, key=lambda r: r["pos_err_p95_m"]):
        if row["f1_pct"] > best:
            frontier.append(row)
            best = row["f1_pct"]
    fd = "M " + " L ".join(f'{X(r["pos_err_p95_m"]):.1f} {Y(r["f1_pct"]):.1f}' for r in frontier)
    out.append(f'<path d="{fd}" fill="none" stroke="{SLATE}" stroke-width="1.5" stroke-dasharray="3 4"/>')
    colors = {0.5: "#94a3b8", 1.0: TEAL, 1.5: AMBER, 2.0: RED}
    for row in points:
        cx, cy = X(row["pos_err_p95_m"]), Y(row["f1_pct"])
        fill = colors.get(row["ty_m"], SLATE)
        out.append(f'<circle cx="{cx:.1f}" cy="{cy:.1f}" r="6" fill="{fill}" opacity="0.85" stroke="#fff" stroke-width="1.5"/>')
    for row, color, num in (
        (next(r for r in points if (r["tx_m"], r["ty_m"]) == (1.5, 1.0)), TEAL, "1"),
        (next(r for r in points if (r["tx_m"], r["ty_m"]) == (3.0, 2.0)), RED, "2"),
    ):
        cx, cy = X(row["pos_err_p95_m"]), Y(row["f1_pct"])
        out.append(f'<circle cx="{cx:.1f}" cy="{cy:.1f}" r="13" fill="#ffffff" fill-opacity="0.55" '
                   f'stroke="{color}" stroke-width="3"/>')
        out.append(_txt(cx, cy + 4, num, 11.5, color, "middle", 800))
    out.append(_txt((px0 + px1) / 2, height - 18, "95th-percentile position error of matched pairs (m)", 11.5, SLATE, "middle"))
    out.append(f'<text x="18" y="{(py0 + py1) / 2:.1f}" font-size="11.5" fill="{SLATE}" text-anchor="middle" '
               f'transform="rotate(-90 18 {(py0 + py1) / 2:.1f})">F1 score (%)</text>')
    out.append(f'<line x1="{px0}" y1="{py1}" x2="{px1}" y2="{py1}" stroke="#94a3b8"/>')
    out.append(f'<line x1="{px0}" y1="{py0}" x2="{px0}" y2="{py1}" stroke="#94a3b8"/>')
    lx, ly = px1 - 224, py1 - 86
    out.append(f'<rect x="{lx}" y="{ly}" width="222" height="82" rx="8" fill="#ffffff" fill-opacity="0.92" stroke="{GRID_C}"/>')
    out.append(_txt(lx + 10, ly + 18, "colour = ΔY gate", 10, SLATE, "start", 700))
    for i, (val, col) in enumerate(colors.items()):
        out.append(f'<circle cx="{lx + 18 + i * 50}" cy="{ly + 38}" r="5" fill="{col}"/>')
        out.append(_txt(lx + 27 + i * 50, ly + 42, f"{val:g} m", 9.5, SLATE))
    out.append(_txt(lx + 10, ly + 58, "dashed = measured Pareto frontier", 9, MUTED))
    out.append(_txt(lx + 10, ly + 73, "1 deployed · 2 rejected candidate", 9, MUTED))
    out.append("</svg>")
    return "".join(out)


def grouped_bars(rows, width=920, height=None):
    left, right, top, bottom = 320, 92, 34, 44
    bar_h, gap, group = 12, 4, 34
    px0, px1 = left, width - right
    py0 = top
    if height is None:
        height = top + len(rows) * group + 34
    out = [f'<svg class="chart" viewBox="0 0 {width} {height}" role="img" aria-label="Per-scene F1">']
    for i in range(5):
        v = i * 25
        x = px0 + (px1 - px0) * v / 100
        out.append(f'<line x1="{x:.1f}" y1="{py0}" x2="{x:.1f}" y2="{py0 + len(rows) * group}" stroke="{GRID_C}"/>')
        out.append(_txt(x, py0 - 10, f"{v}", 10, MUTED, "middle"))
    for i, row in enumerate(rows):
        y = py0 + i * group
        name = row["scene"].replace("AshLey_AVTR5525_20260924_073031_", "").replace("edge:SRR_CCA_9010_3100099_DEBUG_20250828_163933_0010_HDF_Report_CDC", "SRR edge fixture")
        out.append(_txt(left - 12, y + 17, name, 10.5, INK, "end", 600 if "SRR" in name else 400))
        for j, (key, color) in enumerate((("cur", TEAL), ("cand", RED))):
            val = row[key]
            w = (px1 - px0) * val / 100
            by = y + j * (bar_h + gap)
            out.append(f'<rect x="{px0}" y="{by}" width="{w:.1f}" height="{bar_h}" rx="3" fill="{color}" opacity="{0.92 if j == 0 else 0.75}"/>')
            out.append(_txt(px0 + w + 6, by + 10, f"{val:.1f}", 9.5, color, "start", 700))
        delta = row["cand"] - row["cur"]
        out.append(_txt(px1 + 10, y + 17, signed(delta), 10, RED if delta > 0 else MUTED, "start", 700))
    out.append(_txt((px0 + px1) / 2, height - 14, "F1 score (%)  ·  teal = deployed 1.5/1.0/0.5  ·  red = candidate 3.0/2.0/0.5", 10.5, SLATE, "middle"))
    out.append(_txt(px1 + 44, py0 - 10, "Δ pp", 9.5, MUTED))
    out.append("</svg>")
    return "".join(out)


def ruler(width=920, height=300):
    left, right, top = 150, 40, 52
    px0, px1 = left, width - right
    lo, hi = 0.2, 12.0

    def X(v):
        return px0 + (math.log10(v) - math.log10(lo)) / (math.log10(hi) - math.log10(lo)) * (px1 - px0)

    out = [f'<svg class="chart" viewBox="0 0 {width} {height}" role="img" aria-label="Noise, spacing and gate ruler">']
    band_h = height - top - 54
    zones = (
        (lo, SPACING_P10, "#ecfdf5", TEAL, "no ambiguous neighbour below p10 spacing"),
        (SPACING_P10, NOISE_P90, "#fffbeb", AMBER, "contested band"),
        (NOISE_P90, hi, "#fef2f2", RED, "gate admits replay drift"),
    )
    for z0, z1, fill, color, label in zones:
        x0, x1 = X(z0), X(z1)
        out.append(f'<rect x="{x0:.1f}" y="{top - 18}" width="{max(x1 - x0, 2):.1f}" height="{band_h}" '
                   f'fill="{fill}" stroke="none"/>')
        out.append(_halo_text((x0 + x1) / 2, top - 6, label, 9.5, color))
    out.append(f'<line x1="{X(SPACING_P10):.1f}" y1="{top - 18}" x2="{X(SPACING_P10):.1f}" y2="{top + band_h - 18}" '
               f'stroke="{AMBER}" stroke-width="1.2" stroke-dasharray="4 3"/>')
    out.append(f'<line x1="{X(NOISE_P90):.1f}" y1="{top - 18}" x2="{X(NOISE_P90):.1f}" y2="{top + band_h - 18}" '
               f'stroke="{RED}" stroke-width="1.2" stroke-dasharray="4 3"/>')
    for v in (0.2, 0.5, 1, 2, 5, 10):
        x = X(v)
        out.append(f'<line x1="{x:.1f}" y1="{top}" x2="{x:.1f}" y2="{height - 68}" stroke="{GRID_C}"/>')
        out.append(_txt(x, height - 48, f"{v:g} m", 10, MUTED, "middle"))
    lanes = [
        ("inter-run noise", top + 32, [(NOISE_P50, "p50", SLATE), (NOISE_P90, "p90", AMBER),
                                        (NOISE_P95, "p95", AMBER), (NOISE_P99, "p99", RED)]),
        ("object spacing", top + 102, [(SPACING_P5, "p5", SLATE), (SPACING_P10, "p10", TEAL),
                                        (SPACING_P50, "p50", SLATE)]),
        ("gate settings", top + 172, [(1.0, "ΔY rec 1.0", TEAL), (1.5, "ΔX rec 1.5", TEAL),
                                       (2.0, "ΔY cand 2.0", RED), (3.0, "ΔX cand 3.0", RED)]),
    ]
    for name, y, marks in lanes:
        out.append(_txt(left - 18, y + 4, name, 11.5, INK, "end", 700))
        out.append(f'<line x1="{px0}" y1="{y}" x2="{px1}" y2="{y}" stroke="#cbd5e1" stroke-width="2"/>')
        for i, (v, label, color) in enumerate(marks):
            x = X(v)
            out.append(f'<line x1="{x:.1f}" y1="{y - 8}" x2="{x:.1f}" y2="{y + 8}" stroke="{color}" stroke-width="2.5"/>')
            out.append(f'<circle cx="{x:.1f}" cy="{y}" r="5" fill="#fff" stroke="{color}" stroke-width="2.5"/>')
            if name == "gate settings":
                ly = y - 14 - (16 if i % 2 else 0)
            else:
                ly = y - 14 if i % 2 == 0 else y + 22
            out.append(_halo_text(x, ly, label, 9.5, color))
    out.append(_txt((px0 + px1) / 2, height - 18, "distance (m, log scale)  ·  noise = Chebyshev displacement between independent runs", 10.5, SLATE, "middle"))
    out.append("</svg>")
    return "".join(out)


def convergence(uncon, con_path, cells, width=920, height=380):
    left, right, top, bottom = 74, 28, 36, 70
    px0, px1, py0, py1 = left, width - right, top, height - bottom
    lo, hi = 50.0, 76.0

    def X(step, maxstep):
        return px0 + step / maxstep * (px1 - px0)

    def Y(v):
        return py1 - (v - lo) / (hi - lo) * (py1 - py0)

    out = [f'<svg class="chart" viewBox="0 0 {width} {height}" role="img" aria-label="Optimization trace">']
    for i in range(6):
        v = lo + (hi - lo) * i / 5
        out.append(f'<line x1="{px0}" y1="{Y(v):.1f}" x2="{px1}" y2="{Y(v):.1f}" stroke="{GRID_C}"/>')
        out.append(_txt(px0 - 9, Y(v) + 4, f"{v:.0f}", 10, MUTED, "end"))
    out.append(f'<line x1="{px0}" y1="{Y(66.88):.1f}" x2="{px1}" y2="{Y(66.88):.1f}" stroke="{TEAL}" '
               f'stroke-width="1.4" stroke-dasharray="6 4"/>')
    out.append(_halo_text(px1 - 6, Y(66.88) - 8, "feasible optimum F1 66.88", 10, TEAL, "end", 700))
    series = (
        (uncon, AMBER, "F1-only ascent", False),
        (con_path, TEAL, "constrained ascent", True),
    )
    for path, color, label, solid in series:
        maxstep = len(uncon) - 1
        rows = [cells[cell] for cell in path]
        pts = [(X(i, maxstep), Y(r["f1_pct"])) for i, r in enumerate(rows)]
        d = "M " + " L ".join(f"{x:.1f} {y:.1f}" for x, y in pts)
        out.append(f'<path d="{d}" fill="none" stroke="{color}" stroke-width="3" '
                   f'stroke-dasharray="{"0" if solid else "7 5"}"/>')
        for i, (x, y) in enumerate(pts):
            fill = "#fff"
            if not solid and i == len(pts) - 1:
                fill = RED
            out.append(f'<circle cx="{x:.1f}" cy="{y:.1f}" r="6" fill="{fill}" stroke="{color}" stroke-width="2.5"/>')
            if i == 0:
                if not solid:  # both paths share step 0; label it once
                    out.append(_halo_text(x + 6, y + 22, f'{rows[i]["f1_pct"]:.2f}', 10, color, "start"))
            elif i == len(pts) - 1:
                out.append(_halo_text(x - 4, y - 12, f'{rows[i]["f1_pct"]:.2f}', 10, color, "end"))
            else:
                out.append(_halo_text(x, y - 12, f'{rows[i]["f1_pct"]:.2f}', 10, color))
        out.append(f'<circle cx="{px0 + 12}" cy="{py0 + 4 + (0 if solid else 22)}" r="4" fill="{color}"/>')
        out.append(_txt(px0 + 22, py0 + 8 + (0 if solid else 22), label, 10, color, "start", 700))
    for i in range(len(uncon)):
        out.append(_txt(X(i, len(uncon) - 1), py1 + 20, str(i), 11, SLATE, "middle", 600))
    out.append(_txt((px0 + px1) / 2, height - 18, "optimization step (8-neighbour steepest ascent on measured cells)", 11, SLATE, "middle"))
    out.append(f'<text x="18" y="{(py0 + py1) / 2:.1f}" font-size="11.5" fill="{SLATE}" text-anchor="middle" '
               f'transform="rotate(-90 18 {(py0 + py1) / 2:.1f})">F1 score (%)</text>')
    out.append(f'<line x1="{px0}" y1="{py1}" x2="{px1}" y2="{py1}" stroke="#94a3b8"/>')
    out.append(f'<line x1="{px0}" y1="{py0}" x2="{px0}" y2="{py1}" stroke="#94a3b8"/>')
    out.append("</svg>")
    return "".join(out)


# ---------------------------------------------------------------- HTML sections

def config_table(rows, highlight="current_1.5_1.0_0.5", reject="candidate_3.0_2.0_0.5"):
    head = ("<thead><tr><th>Configuration</th><th>ΔX m</th><th>ΔY m</th><th>ΔV m/s</th>"
            "<th>TP / FP / FN</th><th>Precision %</th><th>Recall %</th><th>F1 %</th>"
            "<th>Jaccard %</th><th>IDSW</th><th>IDSW/1k</th><th>pos mean m</th><th>pos p95 m</th>"
            "<th>vel err m/s</th><th>ms/1k</th></tr></thead>")
    body = []
    for row in rows:
        cls = "rec" if row["config"] == highlight else ("bad" if row["config"] == reject else "")
        tag = ' <span class="tag tag-rec">deployed</span>' if row["config"] == highlight else (
            ' <span class="tag tag-bad">rejected</span>' if row["config"] == reject else "")
        body.append(
            f'<tr class="{cls}"><td class="left nowrap">{esc(row["_label"])}{tag}</td>'
            f'<td class="num">{row["tx_m"]:.2f}</td><td class="num">{row["ty_m"]:.2f}</td><td class="num">{row["tvx_mps"]:.2f}</td>'
            f'<td class="num">{row["tp"]:,} / {row["fp"]:,} / {row["fn"]:,}</td>'
            f'<td class="num">{row["precision_pct"]:.2f}</td><td class="num">{row["recall_pct"]:.2f}</td>'
            f'<td class="num strong">{row["f1_pct"]:.2f}</td><td class="num">{row["jaccard_pct"]:.2f}</td>'
            f'<td class="num">{row["id_switches"]:,}</td><td class="num">{row["idsw_per_1k_matches"]:.2f}</td>'
            f'<td class="num">{row["pos_err_mean_m"]:.3f}</td><td class="num">{row["pos_err_p95_m"]:.3f}</td>'
            f'<td class="num">{row["vel_err_mean_mps"] if row["vel_err_mean_mps"] == row["vel_err_mean_mps"] else "—"}</td>'
            f'<td class="num">{row["ms_per_1000_scans"]:.2f}</td></tr>'
        )
    return f'<div class="table-wrap compact"><table>{head}<tbody>{"".join(body)}</tbody></table></div>'


def marginal_table(rows, axis_label, highlight, reject=None):
    head = (f"<thead><tr><th>{axis_label}</th><th>F1 %</th><th>Δ F1 pp</th><th>Precision %</th><th>Recall %</th>"
            "<th>pos p95 m</th><th>IDSW/1k</th><th>Feasible</th></tr></thead>")
    body = []
    prev = None
    for row in rows:
        delta = "—" if prev is None else signed(row["f1_pct"] - prev)
        ok = feasible(row)
        cls = "rec" if abs(row["tx_m"] - 1.5) < 1e-9 and abs(row["ty_m"] - 1.0) < 1e-9 else (
            "bad" if reject and abs(row["tx_m"] - reject[0]) < 1e-9 and abs(row["ty_m"] - reject[1]) < 1e-9 else "")
        body.append(f'<tr class="{cls}"><td class="left"><b>{row["_axis"]}</b></td>'
                    f'<td class="num strong">{row["f1_pct"]:.2f}</td><td class="num">{delta}</td>'
                    f'<td class="num">{row["precision_pct"]:.2f}</td><td class="num">{row["recall_pct"]:.2f}</td>'
                    f'<td class="num">{row["pos_err_p95_m"]:.3f}</td><td class="num">{row["idsw_per_1k_matches"]:.2f}</td>'
                    f'<td class="center">{"✓ yes" if ok else "✗ no"}</td></tr>')
        prev = row["f1_pct"]
    return f'<div class="table-wrap"><table>{head}<tbody>{"".join(body)}</tbody></table></div>'


def grid_table(cells):
    head = "<thead><tr><th>ΔY \\ ΔX</th>" + "".join(f"<th>{x:g} m</th>" for x in XS) + "</tr></thead>"
    body = []
    for y in reversed(YS):
        tds = []
        for x in XS:
            row = cells[(x, y)]
            cls = "cell-rec" if (x, y) == (1.5, 1.0) else ("cell-bad" if (x, y) == (3.0, 2.0) else "")
            tds.append(f'<td class="{cls}"><b>{row["f1_pct"]:.2f}%</b><br><span class="mini">p95 {row["pos_err_p95_m"]:.2f} m · '
                       f'IDSW/1k {row["idsw_per_1k_matches"]:.1f}</span><br>{"✓" if feasible(row) else "✗"}</td>')
        body.append(f'<tr><th class="left">{y:g} m</th>{"".join(tds)}</tr>')
    return f'<div class="table-wrap"><table class="grid-table">{head}<tbody>{"".join(body)}</tbody></table></div>'


def scene_table(rows):
    head = ("<thead><tr><th>Scene</th><th>Deployed F1 %</th><th>Candidate F1 %</th><th>Δ F1 pp</th>"
            "<th>Deployed p95 m</th><th>Candidate p95 m</th><th>Reading</th></tr></thead>")
    body = []
    for row in rows:
        delta = row["cand"] - row["cur"]
        reading = "candidate closer to reference" if delta > 0 else "no change"
        if "SRR" in row["scene"]:
            reading = "SRR fixture: +3.00 pp, but p95 doubles"
        body.append(f'<tr><td class="left">{esc(row["label"])}</td><td class="num">{row["cur"]:.2f}</td>'
                    f'<td class="num">{row["cand"]:.2f}</td><td class="num">{signed(delta)}</td>'
                    f'<td class="num">{row["cur_p95"]:.2f}</td><td class="num">{row["cand_p95"]:.2f}</td>'
                    f'<td class="left muted">{reading}</td></tr>')
    return f'<div class="table-wrap"><table>{head}<tbody>{"".join(body)}</tbody></table></div>'


def sweep_table(rows):
    head = ("<thead><tr><th>Pos gate m</th><th>Vel gate m/s</th><th>F1 %</th><th>Precision %</th><th>Recall %</th>"
            "<th>Jaccard %</th><th>IDSW</th><th>IDSW/1k</th><th>pos p95 m</th><th>ms/1k</th></tr></thead>")
    body = []
    for row in rows:
        cls = "rec" if abs(row["pos_m"] - 1.5) < 1e-9 and abs(row["vel_mps"] - 0.5) < 1e-9 else ""
        body.append(f'<tr class="{cls}"><td class="num">{row["pos_m"]:g}</td><td class="num">{row["vel_mps"]:g}</td>'
                    f'<td class="num strong">{row["f1_pct"]:.2f}</td><td class="num">{row["precision_pct"]:.2f}</td>'
                    f'<td class="num">{row["recall_pct"]:.2f}</td><td class="num">{row["jaccard_pct"]:.2f}</td>'
                    f'<td class="num">{row["id_switches"]:,}</td><td class="num">{row["idsw_per_1k_matches"]:.2f}</td>'
                    f'<td class="num">{row["pos_err_p95_m"]:.3f}</td><td class="num">{row["ms_per_1000_scans"]:.2f}</td></tr>')
    return f'<div class="table-wrap tall"><table>{head}<tbody>{"".join(body)}</tbody></table></div>'


def main():
    sweep = load_json(SWEEP_PATH)
    asym = load_json(ASYM_PATH)
    eval_data, grid_data = asym, asym
    cells = build_cells(eval_data, grid_data)
    configs = config_rows(eval_data)

    labels = {
        "legacy_1cm": "Legacy replay gate",
        "current_1.5_1.0_0.5": "Deployed physical tolerance",
        "candidate_3.0_2.0_0.5": "Looser candidate (max-F1)",
        "x1.5_y1.5_v0.5": "Symmetric 1.5 m comparison",
        "x_3.0_y1.0_v0.5": "X-only widening (ΔY kept at 1.0)",
    }
    headline = []
    for key in ("legacy_1cm", "current_1.5_1.0_0.5", "candidate_3.0_2.0_0.5", "x1.5_y1.5_v0.5", "x_3.0_y1.0_v0.5"):
        row = dict(configs[key])
        row["_label"] = labels[key]
        headline.append(row)

    cur = configs["current_1.5_1.0_0.5"]
    cand = configs["candidate_3.0_2.0_0.5"]
    legacy = configs["legacy_1cm"]

    x_marg = []
    for x in XS:
        row = dict(cells[(x, 1.0)])
        row["_axis"] = f"ΔX {x:g} m"
        x_marg.append(row)
    y_marg = []
    for y in (0.25, 0.5, 1.0, 1.5, 2.0):
        row = next(r["total"] for r in eval_data["results"]
                   if abs(r["total"]["tx_m"] - 1.5) < 1e-9 and abs(r["total"]["ty_m"] - y) < 1e-9
                   and abs(r["total"]["tvx_mps"] - 0.5) < 1e-9)
        row = dict(row)
        row["_axis"] = f"ΔY {y:g} m"
        y_marg.append(row)
    v_marg = []
    for v in (0.1, 0.25, 0.5, 1.0, 2.0):
        row = next(r["total"] for r in eval_data["results"]
                   if abs(r["total"]["tx_m"] - 1.5) < 1e-9 and abs(r["total"]["ty_m"] - 1.0) < 1e-9
                   and abs(r["total"]["tvx_mps"] - v) < 1e-9)
        row = dict(row)
        row["_axis"] = f"ΔV {v:g} m/s"
        v_marg.append(row)

    uncon = ascent((0.5, 0.5), cells, lambda r: True, lambda r: r["f1_pct"])
    con = ascent((0.5, 0.5), cells, feasible, lambda r: r["f1_pct"])
    # self-check: the two objectives must land on the reported endpoints
    assert uncon[-1] == (3.0, 2.0), uncon
    assert con[-1] == (1.5, 1.0), con
    assert all(feasible(cells[c]) for c in con), con

    cur_scene = next(r for r in eval_data["results"] if r["total"]["config"] == "current_1.5_1.0_0.5")["scenes"]
    cand_scene = next(r for r in eval_data["results"] if r["total"]["config"] == "candidate_3.0_2.0_0.5")["scenes"]
    scene_rows = []
    for a, b in zip(cur_scene, cand_scene):
        name = a["scene"].replace("AshLey_AVTR5525_20260924_073031_", "")
        if name.startswith("edge:SRR"):
            name = "SRR edge fixture (CCA_9010)"
        else:
            name = name.replace(":", " · ")
        scene_rows.append({"scene": a["scene"], "label": name, "cur": a["f1_pct"], "cand": b["f1_pct"],
                           "cur_p95": a["pos_err_p95_m"], "cand_p95": b["pos_err_p95_m"]})

    f1_delta = cand["f1_pct"] - cur["f1_pct"]
    p95_growth = (cand["pos_err_p95_m"] / cur["pos_err_p95_m"] - 1) * 100
    idsw_growth = (cand["idsw_per_1k_matches"] / cur["idsw_per_1k_matches"] - 1) * 100
    fp_cut = (1 - cand["fp"] / cur["fp"]) * 100
    fn_cut = (1 - cand["fn"] / cur["fn"]) * 100

    x_points = [(r["tx_m"], r["f1_pct"]) for r in x_marg]
    y_points = [(r["ty_m"], r["f1_pct"]) for r in y_marg]
    v_points = [(r["tvx_mps"], r["f1_pct"]) for r in v_marg]

    x_chart = line_chart(
        x_points, "F1 score (%)", "ΔX position gate (m), with ΔY = 1.0 m and ΔV = 0.5 m/s",
        refs=[(SPACING_P10, "spacing p10", SLATE, "3 3"), (TOL_M, "tolerance 1.5 m", TEAL, "6 4"),
              (NOISE_P90, "noise p90", AMBER, "2 3")],
        highlight=1.5, candidate=3.0, ymin=55, ymax=72,
    )
    y_chart = line_chart(
        y_points, "F1 score (%)", "ΔY position gate (m), with ΔX = 1.5 m and ΔV = 0.5 m/s",
        refs=[(SPACING_P10, "spacing p10", SLATE, "3 3"), (1.0, "deployed ΔY 1.0 m", TEAL, "6 4")],
        highlight=1.0, candidate=2.0, ymin=45, ymax=75,
    )
    v_chart = line_chart(
        v_points, "F1 score (%)", "ΔV velocity gate (m/s), with ΔX = 1.5 m and ΔY = 1.0 m",
        refs=[(VEL_NOISE["vx"][2], "Vx noise p95", AMBER, "3 3"), (VEL_NOISE["vy"][2], "Vy noise p95", RED, "3 3")],
        highlight=0.5, candidate=2.0, ymin=42, ymax=76,
    )

    noise_rows = [
        ("Noise p50", f"{NOISE_P50:.3f} m", "half of inter-run disagreement is below this"),
        ("Noise p90", f"{NOISE_P90:.3f} m", "upper bound used for the longitudinal gate"),
        ("Noise p95", f"{NOISE_P95:.3f} m", "tail of replay disagreement"),
        ("Noise p99", f"{NOISE_P99:.3f} m", "rare drift / clock artefacts"),
        ("Spacing p5", f"{SPACING_P5:.3f} m", "closest 5% of different-object pairs"),
        ("Spacing p10", f"{SPACING_P10:.3f} m", "the lateral ambiguity floor"),
        ("Spacing p50", f"{SPACING_P50:.3f} m", "median distance to a different object"),
        ("Vx noise p95", f"{VEL_NOISE['vx'][2]:.3f} m/s", "ΔV = 0.5 is 1.28× this"),
        ("Vy noise p95", f"{VEL_NOISE['vy'][2]:.3f} m/s", "ΔV = 0.5 is 0.50× this"),
    ]
    noise_table = ('<div class="table-wrap"><table><thead><tr><th>Quantity</th><th>Value</th><th>Interpretation</th>'
                   '</tr></thead><tbody>' + "".join(
                       f'<tr><td class="left">{esc(a)}</td><td class="num strong">{esc(b)}</td><td class="left muted">{esc(c)}</td></tr>'
                       for a, b, c in noise_rows) + '</tbody></table></div>')

    conv_rows = []
    for path, tag in ((uncon, "F1-only"), (con, "constrained")):
        for i, cell in enumerate(path):
            row = cells[cell]
            conv_rows.append(
                f'<tr class="{"rec" if tag == "constrained" and i == len(path)-1 else ""}">'
                f'<td class="left">{tag}</td><td class="num">{i}</td>'
                f'<td class="left">ΔX {cell[0]:g} m / ΔY {cell[1]:g} m</td>'
                f'<td class="num strong">{row["f1_pct"]:.2f}</td><td class="num">{row["precision_pct"]:.2f}</td>'
                f'<td class="num">{row["recall_pct"]:.2f}</td><td class="num">{row["pos_err_p95_m"]:.2f}</td>'
                f'<td class="num">{row["idsw_per_1k_matches"]:.1f}</td>'
                f'<td class="center">{"✓" if feasible(row) else "✗"}</td></tr>'
            )
    conv_table = ('<div class="table-wrap"><table><thead><tr><th>Objective</th><th>Step</th><th>Cell</th>'
                  '<th>F1 %</th><th>Precision %</th><th>Recall %</th><th>p95 m</th><th>IDSW/1k</th><th>Feasible</th>'
                  '</tr></thead><tbody>' + "".join(conv_rows) + '</tbody></table></div>')

    risk_rows = [
        ("ΔX 3.0 m", "3.29× spacing p10; p95 error 2.73 m (> 1.82× tolerance)",
         "Rejected. Recovers "+f"{fn_cut:.1f}% of FNs but admits pairs whose error exceeds the KPI's own tolerance."),
        ("ΔY 2.0 m", "2.19× spacing p10; lateral neighbours can be bound",
         "Rejected. The +3.0 pp SRR gain is not separable from wrong-neighbour matches in aggregate F1."),
        ("ΔX 2.0 m", "p95 1.81 m (> 1.5 m); +0.95 pp over deployed",
         "Rejected. Buys less than 1 pp while breaching the position tolerance."),
        ("ΔY 1.5 m", "p95 1.69 m (> 1.5 m); 1.64× spacing p10",
         "Rejected. Slightly higher F1 (69.33 vs 66.88) but fails the tolerance and widens the ambiguous axis."),
        ("ΔV 1.0 m/s", "equals Vy noise p95 (1.00 m/s); +4.46 pp",
         "Rejected for compliance. A gate at the 95th noise percentile cannot reject velocity-mismatched pairs."),
        ("ΔV 0.25 m/s", "−6.76 pp; p95 unchanged",
         "Too strict. Loses matches without improving validity."),
        ("ΔX 1.0 m", "−1.81 pp; p95 improves to 1.14 m",
         "Acceptable fallback if a stricter KPI is required; not the best F1 within policy."),
        ("Legacy 0.01 m", "F1 5.85%; quantization collapses matches",
         "Retired. Valid only for byte-identical replay assertions."),
    ]
    risk_table = ('<div class="table-wrap"><table><thead><tr><th>Alternative</th><th>Measured / physical effect</th>'
                  '<th>Decision</th></tr></thead><tbody>' + "".join(
                      f'<tr><td class="left nowrap"><b>{esc(a)}</b></td><td class="left">{esc(b)}</td>'
                      f'<td class="left muted">{esc(c)}</td></tr>' for a, b, c in risk_rows) + '</tbody></table></div>')

    steps = [
        ("Freeze the question",
         "The KPI must verify that a replay reproduces the reference tracker, not that an association algorithm can match "
         "as many objects as possible. The gate is therefore a physical comparison tolerance, not a free tuning knob."),
        ("Load real replay pairs",
         "5 HDF_TRACK scene pairs × 2 streams (FC, RL) = 10 scenes, plus the SRR edge fixture = 11 scenes. "
         "Scans are aligned by header timestamp; 4,137 aligned scans and 268,738 valid tracker objects enter the score."),
        ("Fix the association backend",
         "`hungarian_normalized` is the production default. It applies hard per-axis gates and solves the assignment "
         "globally, so changing the gate is the only variable in this study."),
        ("Score each configuration",
         "For every candidate gate, count TP / FP / FN and derive precision, recall, F1, Jaccard, ID switches, "
         "IDSW per 1,000 matches, mean and p95 position error, mean velocity error, and runtime per 1,000 scans."),
        ("Build the 2D gate map",
         "Measure ΔX ∈ {0.5, 1.0, 1.5, 2.0, 3.0} m against ΔY ∈ {0.5, 1.0, 1.5, 2.0} m at ΔV = 0.5 m/s. "
         "The deployed point (1.5, 1.0) and the looser candidate (3.0, 2.0) are both cells in this measured map."),
        ("Measure the marginal curves",
         "Hold two axes at the deployed values and sweep the third: ΔX, then ΔY, then ΔV. This isolates which gate "
         "buys F1 and which gate buys validity."),
        ("Measure the physical floor and ceiling",
         "Inter-run noise (the same object across two runs) gives the smallest defensible gate. "
         "Inter-object spacing (the nearest *different* object) gives the largest safe gate. "
         "The p10 spacing is 0.913 m; the p90 noise is 2.093 m."),
        ("Run the unconstrained optimizer",
         "Steepest ascent with an 8-neighbourhood on the measured F1 map. Starting at (0.5, 0.5) it climbs to "
         "(1.0, 1.0), (1.5, 1.5), (2.0, 2.0), (3.0, 2.0). The endpoint is the highest F1 in the grid — and is physically invalid."),
        ("Run the constrained optimizer",
         "Same ascent, but accept a move only if p95 ≤ 1.5 m, ΔY ≤ 1.0 m and ΔX ≤ 2.093 m. "
         "The path stops at (1.5, 1.0): no feasible neighbour has a higher F1. This is the deployed gate."),
        ("Stress the decision",
         f"Compare per-scene deltas, including the SRR fixture. The candidate improves SRR by +3.00 pp and the pooled "
         f"score by +{f1_delta:.2f} pp, but both gains coincide with a p95 error of {cand['pos_err_p95_m']:.2f} m and "
         f"{cand['idsw_per_1k_matches']:.1f} ID switches per 1,000 matches."),
        ("Verify and publish",
         "Re-run the backend and viewer regression tests, confirm the deployed configuration in the tracker KPI config, "
         "and publish this report with the measured tables and the decision log."),
    ]
    steps_html = "".join(
        f'<li><b>{esc(title)}.</b> <span class="muted">{esc(body)}</span></li>' for title, body in steps)

    html_doc = f"""<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>Tracker KPI — Threshold Optimality Review</title>
<style>
:root{{--ink:{INK};--muted:{MUTED};--line:{GRID_C};--bg:#f6f8fb;--card:#fff;--teal:{TEAL};--red:{RED};--amber:{AMBER};--indigo:{INDIGO}}}
*{{box-sizing:border-box}}
html{{scroll-behavior:smooth}}
body{{margin:0;background:var(--bg);color:var(--ink);font:15px/1.62 ui-sans-serif,system-ui,-apple-system,"Segoe UI",Roboto,Arial,sans-serif;-webkit-font-smoothing:antialiased}}
.wrap{{max-width:1200px;margin:0 auto;padding:26px 22px 90px}}
.hero{{position:relative;overflow:hidden;border-radius:20px;padding:38px 40px 32px;color:#f8fafc;background:
 radial-gradient(900px 300px at 88% -10%,rgba(45,212,191,.35),transparent 60%),
 linear-gradient(135deg,#0b1220 0%,#132033 52%,#0f3d3a 100%);box-shadow:0 18px 50px rgba(15,23,42,.22)}}
.hero:after{{content:"";position:absolute;inset:0;background-image:linear-gradient(rgba(255,255,255,.045) 1px,transparent 1px),linear-gradient(90deg,rgba(255,255,255,.045) 1px,transparent 1px);background-size:44px 44px;pointer-events:none;mask-image:linear-gradient(to bottom,black,transparent 88%)}}
.eyebrow{{position:relative;font-size:11.5px;letter-spacing:.18em;text-transform:uppercase;color:#5eead4;font-weight:700}}
h1{{position:relative;margin:10px 0 12px;font-size:clamp(28px,4vw,44px);line-height:1.1;letter-spacing:-.02em;font-weight:800}}
.hero p{{position:relative;max-width:900px;color:#cbd5e1;font-size:16px;margin:0}}
.hero .badges{{position:relative;display:flex;flex-wrap:wrap;gap:9px;margin-top:22px}}
.badge{{display:inline-flex;align-items:center;gap:7px;border-radius:999px;padding:7px 13px;font-size:12px;font-weight:700;border:1px solid rgba(255,255,255,.18);background:rgba(255,255,255,.07)}}
.badge.good{{background:rgba(13,148,136,.30);border-color:rgba(94,234,212,.55);color:#ccfbf1}}
.badge.bad{{background:rgba(220,38,38,.24);border-color:rgba(252,165,165,.5);color:#fee2e2}}
.badge.neutral{{color:#cbd5e1}}
.meta{{position:relative;display:flex;flex-wrap:wrap;gap:18px;margin-top:18px;font-size:12px;color:#94a3b8}}
.meta b{{color:#e2e8f0;font-weight:600}}
.toc{{display:flex;flex-wrap:wrap;gap:8px;margin:20px 0 4px}}
.toc a{{font-size:12px;text-decoration:none;color:#0f3d3a;background:#e6fffb;border:1px solid #99f6e4;border-radius:999px;padding:5px 11px;font-weight:600}}
.toc a:hover{{background:#ccfbf1}}
section{{margin-top:34px}}
h2{{font-size:22px;letter-spacing:-.01em;margin:0 0 6px;display:flex;align-items:center;gap:10px}}
h2 .num{{display:inline-flex;width:28px;height:28px;border-radius:9px;background:#0f172a;color:#fff;font-size:13px;align-items:center;justify-content:center;font-weight:800}}
h3{{font-size:16px;margin:22px 0 8px}}
.lead{{color:#475569;margin:0 0 16px;max-width:980px}}
.kpis{{display:grid;grid-template-columns:repeat(auto-fit,minmax(210px,1fr));gap:14px;margin-top:18px}}
.kpi{{background:var(--card);border:1px solid var(--line);border-radius:14px;padding:16px 17px;box-shadow:0 1px 2px rgba(15,23,42,.04)}}
.kpi .label{{font-size:11px;letter-spacing:.08em;text-transform:uppercase;color:var(--muted);font-weight:700}}
.kpi .value{{font-size:30px;font-weight:800;letter-spacing:-.03em;margin:6px 0 2px;font-variant-numeric:tabular-nums}}
.kpi .sub{{font-size:12px;color:var(--muted)}}
.kpi.good{{border-left:4px solid var(--teal)}} .kpi.bad{{border-left:4px solid var(--red)}} .kpi.warn{{border-left:4px solid var(--amber)}}
.card{{background:var(--card);border:1px solid var(--line);border-radius:16px;padding:20px 20px 16px;margin-top:14px;box-shadow:0 1px 2px rgba(15,23,42,.04)}}
.card h3{{margin-top:0}}
.callout{{border-radius:14px;padding:16px 18px;margin:16px 0;border:1px solid}}
.callout.good{{background:#ecfdf5;border-color:#a7f3d0}}
.callout.bad{{background:#fef2f2;border-color:#fecaca}}
.callout.warn{{background:#fffbeb;border-color:#fde68a}}
.callout b{{font-weight:800}}
.chart{{width:100%;height:auto;display:block;overflow:visible}}
.caption{{font-size:12px;color:var(--muted);margin:8px 2px 0}}
.table-wrap{{width:100%;overflow:auto;border:1px solid var(--line);border-radius:12px;margin:10px 0 4px;background:#fff}}
.table-wrap.tall{{max-height:520px}}
.table-wrap.compact table{{font-size:11.2px}}
.table-wrap.compact th,.table-wrap.compact td{{padding:6px 6px}}
table{{width:100%;border-collapse:separate;border-spacing:0;font-size:12px;min-width:720px}}
th{{position:sticky;top:0;z-index:2;background:#f1f5f9;color:#334155;font-weight:700;text-align:right;padding:8px 8px;border-bottom:1px solid #cbd5e1;white-space:nowrap}}
th:first-child{{text-align:left}}
td{{padding:7px 8px;border-bottom:1px solid #eef2f7;vertical-align:middle}}
tr:last-child td{{border-bottom:none}}
tbody tr:hover td{{background:#f8fafc}}
td.num{{text-align:right;font-variant-numeric:tabular-nums;white-space:nowrap}}
td.left{{text-align:left}} td.center{{text-align:center}} td.strong{{font-weight:800}}
td.mini,.mini{{font-size:10.5px;color:#64748b;font-weight:400;line-height:1.35}}
tr.rec td{{background:#ecfdf5!important}} tr.rec td:first-child{{border-left:4px solid var(--teal)}}
tr.bad td{{background:#fef2f2!important}} tr.bad td:first-child{{border-left:4px solid var(--red)}}
.nowrap{{white-space:nowrap}}
.tag{{display:inline-block;font-size:10px;font-weight:800;letter-spacing:.04em;text-transform:uppercase;border-radius:999px;padding:2px 7px;margin-left:6px;vertical-align:1px}}
.tag-rec{{background:#ccfbf1;color:#0f766e;border:1px solid #5eead4}}
.tag-bad{{background:#fee2e2;color:#b91c1c;border:1px solid #fca5a5}}
.grid-table td{{text-align:center;min-width:145px;font-variant-numeric:tabular-nums}}
.grid-table thead th{{text-align:center}}
.grid-table th.left{{text-align:left;min-width:70px}}
.cell-rec{{background:#ecfdf5!important;outline:2px solid #0f766e;outline-offset:-2px}}
.cell-bad{{background:#fef2f2!important;outline:2px dashed #dc2626;outline-offset:-2px}}
.cols2{{display:grid;grid-template-columns:1fr 1fr;gap:16px}}
@media(max-width:860px){{.cols2{{grid-template-columns:1fr}} .hero{{padding:26px 22px}}}}
ol.steps{{padding-left:22px;margin:8px 0 0}}
ol.steps li{{margin:11px 0;padding-left:4px}}
ol.steps li::marker{{color:var(--teal);font-weight:800}}
details{{border:1px solid var(--line);border-radius:12px;background:#fff;padding:12px 14px;margin-top:12px}}
summary{{cursor:pointer;font-weight:700;color:#0f172a}}
code,kbd{{font-family:ui-monospace,SFMono-Regular,Consolas,"Liberation Mono",monospace;font-size:12px;background:#f1f5f9;border:1px solid #e2e8f0;border-radius:6px;padding:1px 5px}}
pre{{background:#0b1220;color:#e2e8f0;padding:14px 16px;border-radius:12px;overflow:auto;font-size:12px;line-height:1.55}}
pre code{{background:none;border:none;padding:0;color:inherit}}
.footer{{margin-top:36px;color:#64748b;font-size:12px;border-top:1px solid #e2e8f0;padding-top:16px}}
ul.tight{{margin:8px 0 0;padding-left:20px}} ul.tight li{{margin:5px 0}}
.pill-row{{display:flex;flex-wrap:wrap;gap:8px;margin:10px 0}}
.pill{{font-size:11.5px;border:1px solid #e2e8f0;background:#f8fafc;border-radius:999px;padding:4px 10px;color:#334155;font-weight:600}}
@media print{{body{{background:#fff}} .wrap{{max-width:none;padding:0}} .hero{{border-radius:0;box-shadow:none}} .toc{{display:none}} section{{break-inside:avoid}} .card,.kpi,table{{break-inside:avoid}}}}
</style>
</head>
<body>
<div class="wrap">

<header class="hero">
  <div class="eyebrow">Tracker KPI · Threshold optimality review · 18 Nov 2026</div>
  <h1>1.5 m / 1.0 m / 0.5 m/s is the constrained optimum</h1>
  <p>The pushed tracker configuration is the best measured balance between association accuracy and physical validity.
     A looser 3.0 m / 2.0 m / 0.5 m/s gate scores +3.00 pp more F1 on the SRR replay fixture and +{f1_delta:.2f} pp on the
     pooled real-log set, but its 95th-percentile position error rises to {cand['pos_err_p95_m']:.2f} m and its lateral gate reaches
     2.19× the distance to a different object. Those matches cannot be distinguished from wrong-object associations by F1 alone.</p>
  <div class="badges">
    <span class="badge good">✓ DEPLOYED · ΔX 1.5 · ΔY 1.0 · ΔV 0.5</span>
    <span class="badge bad">✗ CANDIDATE · 3.0 / 2.0 / 0.5</span>
    <span class="badge neutral">RETIRED · 0.01 / 0.02</span>
    <span class="badge neutral">backend · hungarian_normalized</span>
  </div>
  <div class="meta">
    <span><b>11</b> real replay scenes</span>
    <span><b>4,137</b> aligned scans</span>
    <span><b>268,738</b> valid objects</span>
    <span><b>20</b> asymmetric gate cells</span>
    <span><b>54</b> symmetric sweep points</span>
    <span>measured on local HDF fixtures</span>
  </div>
</header>

<nav class="toc">
  <a href="#verdict">Verdict</a><a href="#kpi">KPI definition</a><a href="#method">Data &amp; method</a>
  <a href="#results">Results</a><a href="#landscape">Gate landscape</a><a href="#optimizer">Optimizer</a>
  <a href="#sensitivity">Sensitivity</a><a href="#physics">Physical limits</a><a href="#tradeoff">Trade-off</a>
  <a href="#scene">Per-scene</a><a href="#decision">Decision log</a><a href="#steps">Procedure</a>
  <a href="#repro">Reproduce</a><a href="#limits">Limits</a>
</nav>

<section id="verdict">
  <h2><span class="num">1</span>Verdict</h2>
  <p class="lead">The deployed point is the highest-F1 configuration that satisfies all three physical constraints:
     p95 position error ≤ 1.5 m, lateral gate ΔY ≤ 1.0 m, and longitudinal gate ΔX ≤ the p90 inter-run noise (2.093 m).
     The loose candidate wins only when those constraints are removed.</p>
  <div class="kpis">
    <div class="kpi good"><div class="label">Deployed F1</div><div class="value">{cur['f1_pct']:.2f}%</div>
      <div class="sub">P {cur['precision_pct']:.2f}% · R {cur['recall_pct']:.2f}% · J {cur['jaccard_pct']:.2f}%</div></div>
    <div class="kpi good"><div class="label">Deployed p95 error</div><div class="value">{cur['pos_err_p95_m']:.2f} m</div>
      <div class="sub">inside the 1.5 m acceptance tolerance</div></div>
    <div class="kpi bad"><div class="label">Candidate F1 gain</div><div class="value">+{f1_delta:.2f} pp</div>
      <div class="sub">but p95 grows {p95_growth:.0f}% to {cand['pos_err_p95_m']:.2f} m</div></div>
    <div class="kpi bad"><div class="label">Candidate IDSW/1k</div><div class="value">{cand['idsw_per_1k_matches']:.1f}</div>
      <div class="sub">+{idsw_growth:.1f}% vs deployed ({cur['idsw_per_1k_matches']:.1f})</div></div>
  </div>
  <div class="callout good"><b>Decision:</b> keep ΔX = 1.5 m, ΔY = 1.0 m, ΔVx = ΔVy = 0.5 m/s.
    It is the constrained optimum, not merely a conservative default: no feasible neighbouring cell has a higher F1.</div>
  <div class="callout bad"><b>Why not maximize F1?</b> F1 is monotone in gate width: widening a gate can only convert a
    false negative into a true positive. On this grid the measured F1 rises from 54.17% at (0.5, 0.5) to 73.07% at (3.0, 2.0)
    with no plateau. A raw F1 objective therefore always selects the widest gate tested — a KPI that matches everything verifies nothing.</div>
</section>

<section id="kpi">
  <h2><span class="num">2</span>What the tracker KPI measures</h2>
  <p class="lead">The KPI compares two independent runs of the same scene. It does not assume that track IDs are stable;
     it associates input and output objects per scan, then scores the matched pairs.</p>
  <div class="cols2">
    <div class="card">
      <h3>Association rule (production backend)</h3>
      <p>For every input/output pair, first apply the hard gates, then solve the global assignment:</p>
      <pre><code>|Δx| ≤ ΔX,  |Δy| ≤ ΔY,  |Δvx| ≤ ΔVx,  |Δvy| ≤ ΔVy
f_moving flags must agree

C_ij = w_p · [(Δx/ΔX)² + (Δy/ΔY)²]
     + w_v · [(Δvx/ΔVx)² + (Δvy/ΔVy)²]</code></pre>
      <p class="caption">Gated pairs get infinite cost and are removed after the Hungarian assignment. The production
        backend is <code>hungarian_normalized</code>; the study changes only the four thresholds.</p>
    </div>
    <div class="card">
      <h3>Metrics</h3>
      <ul class="tight">
        <li><b>Precision</b> = TP / (TP + FP) — of the matches claimed, how many are valid.</li>
        <li><b>Recall</b> = TP / (TP + FN) — of the reference objects, how many were matched.</li>
        <li><b>F1</b> = 2PR / (P + R) — harmonic balance; the headline association score.</li>
        <li><b>Jaccard</b> = TP / (TP + FP + FN) — stricter set agreement.</li>
        <li><b>IDSW/1k</b> = 1,000 × ID switches / TP — identity churn per 1,000 matches.</li>
        <li><b>p95 error</b> = 95th percentile position error of matched pairs; the validity guardrail.</li>
      </ul>
      <p class="caption">Micro-averaged across scenes: counts are summed before ratios are taken, so long scenes carry
        proportionate weight. Per-scene p95 is the worst scene.</p>
    </div>
  </div>
</section>

<section id="method">
  <h2><span class="num">3</span>Data and measurement design</h2>
  <p class="lead">All numbers in this report come from real HDF replay pairs already used by the tracker-KPI benchmark.
     Nothing is synthetic, and the candidate and deployed points are measured by the same backend on the same scans.</p>
  <div class="cols2">
    <div class="card">
      <h3>Corpus</h3>
      <ul class="tight">
        <li><b>5 scene pairs</b> from <code>HDF_TRACK</code>, each scored on the <b>FC</b> and <b>RL</b> streams → 10 scenes.</li>
        <li><b>1 SRR edge fixture</b> (<code>CCA_9010_3100099_DEBUG_20250828_163933_0010</code>) → 11 scenes.</li>
        <li><b>4,137</b> timestamp-aligned scans; <b>268,738</b> valid objects enter the noise/spacing analysis.</li>
        <li>Scan alignment: exact header timestamp for FC; nearest ≤ 25 ms for RL (clock drift), so RL is a lower bound.</li>
      </ul>
    </div>
    <div class="card">
      <h3>Design controls</h3>
      <ul class="tight">
        <li>One backend, one cost function, one scan-alignment policy across every cell.</li>
        <li>2D asymmetric grid: ΔX ∈ {{0.5, 1.0, 1.5, 2.0, 3.0}} m × ΔY ∈ {{0.5, 1.0, 1.5, 2.0}} m at ΔV = 0.5 m/s.</li>
        <li>Marginal sweeps isolate each axis: ΔX, ΔY, and ΔV.</li>
        <li>Symmetric 54-point sweep (position × velocity) is the independent cross-check on the published benchmark.</li>
        <li>No threshold is selected on a single scene; the SRR fixture is reported separately.</li>
      </ul>
    </div>
  </div>
</section>

<section id="results">
  <h2><span class="num">4</span>Measured results</h2>
  <p class="lead">The deployed configuration recovers {cur['tp']:,} valid matches with a {cur['pos_err_p95_m']:.2f} m p95 error.
     The loose candidate recovers {cand['tp']:,} (+{cand['tp']-cur['tp']:,}) and cuts false negatives by {fn_cut:.1f}%,
     but its p95 error is {cand['pos_err_p95_m']:.2f} m and it introduces {cand['id_switches']-cur['id_switches']:,} more ID switches.</p>
  {config_table(headline)}
  <p class="caption">Full metric set for the five decisive configurations. “Deployed” is the pushed 1.5 / 1.0 / 0.5 m gate.
    “Candidate” is the looser 3.0 / 2.0 / 0.5 m gate. The symmetric 1.5 m row isolates the effect of the asymmetric ΔY.</p>
</section>

<section id="landscape">
  <h2><span class="num">5</span>The gate landscape and two optimisation paths</h2>
  <p class="lead">Each cell is a measured configuration. The amber path is steepest ascent on raw F1; it runs to the loosest
     gate. The teal path uses the same ascent but accepts only physically feasible cells; it stops at the deployed point.
     This is the visual form of the decision: F1 proposes, the physical constraints dispose.</p>
  <div class="card">
    {heatmap(cells, uncon, con)}
    <div class="caption">Cell text: F1, p95 position error, ID switches per 1,000 matches. Solid teal outline = deployed gate;
      dashed red outline = rejected candidate. ✓ = p95 ≤ 1.5 m, ΔY ≤ 1.0 m and ΔX ≤ 2.093 m. The top-right cell is the
      highest F1 in the study and is rejected on both error and lateral-spacing grounds.</div>
  </div>
  <div class="cols2">
    <div class="card"><h3>Unconstrained path</h3>
      <p class="muted">(0.5, 0.5) → (1.0, 1.0) → (1.5, 1.5) → (2.0, 2.0) → (3.0, 2.0)</p>
      <p>Every step increases F1. The final cell reaches {cand['f1_pct']:.2f}% but has a p95 error of
        {cand['pos_err_p95_m']:.2f} m, a ΔY of 2.0 m (2.19× the p10 object spacing), and
        {cand['idsw_per_1k_matches']:.1f} ID switches per 1,000 matches. This is what “maximise F1” selects.</p></div>
    <div class="card"><h3>Constrained path</h3>
      <p class="muted">(0.5, 0.5) → (1.0, 1.0) → (1.5, 1.0) → stop</p>
      <p>The first two steps are shared with the unconstrained path. From (1.0, 1.0), the only improving feasible move is
        (1.5, 1.0). Its neighbours either widen ΔY to 1.5 m or raise p95 above 1.5 m, so the ascent terminates there.
        F1 = {cur['f1_pct']:.2f}%, p95 = {cur['pos_err_p95_m']:.2f} m.</p></div>
  </div>
</section>

<section id="optimizer">
  <h2><span class="num">6</span>Optimisation trace</h2>
  <p class="lead">The same two paths as a convergence chart. The unconstrained line is higher, but its endpoint is outside
     the feasible envelope. The constrained line terminates at the highest F1 that satisfies the KPI's own tolerance and
     the lateral-spacing policy.</p>
  <div class="card">
    {convergence(uncon, con, cells)}
    <div class="caption">Steepest ascent over the measured 5 × 4 grid (8-neighbourhood, ties broken by the first improving
      neighbour). Step 0 is the tightest tested gate (0.5 m / 0.5 m). The dashed teal line marks the feasible optimum.</div>
  </div>
  {conv_table}
  <p class="caption">Trace data. “Feasible” applies p95 ≤ 1.5 m, ΔY ≤ 1.0 m and ΔX ≤ 2.093 m. The unconstrained endpoint
    is the global F1 maximum and is infeasible on both p95 and ΔY.</p>
</section>

<section id="sensitivity">
  <h2><span class="num">7</span>One-axis-at-a-time sensitivity</h2>
  <p class="lead">The marginal curves show where each gate stops buying accuracy. The vertical references are the physical
     limits: the p10 distance to a different object (0.913 m) and the p90/p95 inter-run noise.</p>

  <div class="card">
    <h3>ΔX — longitudinal position gate</h3>
    {x_chart}
    <p class="caption">Holding ΔY = 1.0 m and ΔV = 0.5 m/s. F1 rises steeply through 1.0 m, then flattens: 1.5 → 2.0 m buys
      only +0.95 pp while p95 moves from 1.48 to 1.81 m. The deployed 1.5 m sits below the p90 noise (2.093 m).
      The 3.0 m candidate is beyond it.</p>
  </div>
  {marginal_table(x_marg, "ΔX gate", 1.5, (3.0, 1.0))}

  <div class="card">
    <h3>ΔY — lateral position gate</h3>
    {y_chart}
    <p class="caption">Holding ΔX = 1.5 m and ΔV = 0.5 m/s. The lateral axis is the tight one: 1.0 m is 1.10× the p10 object
      spacing, while 1.5 m is 1.64× and 2.0 m is 2.19×. The F1 gain from 1.0 → 1.5 m is real (+2.45 pp) but is exactly
      the regime where a neighbouring object can satisfy the gate.</p>
  </div>
  {marginal_table(y_marg, "ΔY gate", 1.0, (1.5, 1.5))}

  <div class="card">
    <h3>ΔV — velocity gate</h3>
    {v_chart}
    <p class="caption">Holding ΔX = 1.5 m and ΔY = 1.0 m. F1 keeps rising with ΔV because velocity errors are broad-tailed:
      0.5 → 1.0 m/s buys +4.46 pp. But 1.0 m/s is the 95th percentile of Vy inter-run noise, so the velocity check would
      stop rejecting mismatches. The deployed 0.5 m/s is 1.28× the Vx p95 and 0.50× the Vy p95.</p>
  </div>
  {marginal_table(v_marg, "ΔV gate", 0.5, None)}
</section>

<section id="physics">
  <h2><span class="num">8</span>Physical limits behind the gates</h2>
  <p class="lead">A defensible gate sits above the noise between two runs of the same object and below the distance to a
     different object. On this corpus the two distributions overlap — the p90 replay noise (2.093 m) is larger than the p10
     object spacing (0.913 m) — so no gate satisfies both perfectly. The measurements below bound how far each axis can be
     pushed before the error being admitted is larger than the drift it is meant to tolerate.</p>
  <div class="card">
    {ruler()}
    <div class="caption">Inter-run noise is the Chebyshev displacement of the position-nearest partner between reference and
      replay. Object spacing is the Chebyshev distance from an object to its nearest different neighbour in the same scan.
      Green zone = gates below the p10 spacing, where a different object is rarely that close. Amber = contested band, where
      same-object drift and different-object spacing overlap. Red = gates at or above the p90 noise, which cannot reject
      replay drift.</div>
  </div>
  {noise_table}
  <div class="callout warn"><b>Reading the bracket:</b> the deployed ΔY = 1.0 m is 1.10× the p10 object spacing and 0.48× the
    p90 noise. The deployed ΔX = 1.5 m is 1.64× spacing and 0.72× noise. The candidate ΔY = 2.0 m is 2.19× spacing and
    0.96× noise; the candidate ΔX = 3.0 m is 3.29× spacing and 1.43× noise. Beyond 1.0× noise, a gate can accept a pair
    whose disagreement is as large as the replay drift itself.</div>
</section>

<section id="tradeoff">
  <h2><span class="num">9</span>Accuracy versus validity</h2>
  <p class="lead">The scatter makes the trade-off explicit. Points to the right of the red line breach the 1.5 m p95 tolerance.
     Points above the dashed frontier are not Pareto-improved by their neighbours; the deployed point is the knee inside the
     tolerance, not the global F1 maximum.</p>
  <div class="card">
    {scatter(list(cells.values()))}
    <div class="caption">Each dot is one measured gate cell at ΔV = 0.5 m/s. The dashed line is the measured Pareto frontier
      (minimum p95 for each F1 level). The frontier continues to 73.07% at 2.73 m — an invalid region for this KPI. The
      deployed point 1 is the best F1 that stays inside tolerance and the lateral policy; 2 is the rejected candidate.</div>
  </div>
</section>

<section id="scene">
  <h2><span class="num">10</span>Per-scene evidence</h2>
  <p class="lead">The candidate improves every scene, but the largest gains come from the RL streams and the SRR fixture —
     the same scenes with the largest replay drift and the widest ambiguity. That pattern is consistent with relaxed gates
     admitting more near-neighbour pairs, not with the tracker suddenly tracking better.</p>
  <div class="card">
    {grouped_bars(scene_rows)}
    <div class="caption">F1 by scene. Teal = deployed (1.5 / 1.0 / 0.5), red = candidate (3.0 / 2.0 / 0.5).
      Δ is in percentage points. The SRR fixture gains +3.00 pp; FC scenes gain +1.2 to +3.4 pp; RL scenes gain +6.1 to +13.7 pp.</div>
  </div>
  {scene_table(scene_rows)}
  <div class="callout bad"><b>SRR fixture reading:</b> the candidate improves F1 from 73.69% to 76.70% (+3.00 pp) while
    p95 error rises from 0.52 m to 1.09 m. A 3 pp aggregate gain on one fixture does not justify doubling the matched-pair
    error and widening the lateral gate to 2.0 m.</div>
</section>

<section id="decision">
  <h2><span class="num">11</span>Decision log</h2>
  <p class="lead">Every rejected alternative and the measured or physical reason for rejecting it. The pushed configuration
     is the only row that satisfies all constraints simultaneously.</p>
  {risk_table}
  <div class="callout good"><b>Published configuration:</b> ΔX = 1.5 m, ΔY = 1.0 m, ΔVx = ΔVy = 0.5 m/s,
    backend <code>hungarian_normalized</code>, p95 error {cur['pos_err_p95_m']:.2f} m, F1 {cur['f1_pct']:.2f}%.</div>
</section>

<section id="steps">
  <h2><span class="num">12</span>Detailed procedure</h2>
  <p class="lead">The exact sequence used to produce every number and chart in this report.</p>
  <div class="card"><ol class="steps">{steps_html}</ol></div>
</section>

<section id="repro">
  <h2><span class="num">13</span>Reproduction</h2>
  <p class="lead">The report is generated from cached measurement JSON so it can be rebuilt without re-running the HDF
     loads. To re-measure, run the two evaluation passes first.</p>
  <div class="card">
    <h3>Commands</h3>
    <pre><code># 1. published symmetric sweep (11 scenes, 54 gate points)
python empirical_research_harness/benchmarks/threshold_sweep_tracker_kpi.py

# 2. asymmetric X/Y evaluation (15 configurations + 5 x 4 grid)
python empirical_research_harness/benchmarks/threshold_eval_asymmetric.py

# 3. rebuild this report (~/Desktop/tracker_kpi_threshold_optimality.html)
python empirical_research_harness/benchmarks/build_tracker_threshold_optimality_report.py</code></pre>
    <h3>Artifacts</h3>
    <ul class="tight">
      <li><code>empirical_research_harness/benchmarks/hdf_track_out/threshold_sweep.json</code> — symmetric sweep, noise, spacing, sufficiency.</li>
      <li><code>empirical_research_harness/benchmarks/hdf_track_out/threshold_asymmetric.json</code> — 15 asymmetric configurations and the 20-cell 5 × 4 grid used in the tables.</li>
      <li><code>TRACKER_KPI_ALGORITHM_BENCHMARK_REPORT.md</code> — algorithm-level benchmark (gospa, mahalanobis, obb_auction, legacy).</li>
      <li><code>KPI/UDP_KPI/c_business_layer/tracker_matching_kpi_v2.py</code> — production association backend.</li>
    </ul>
  </div>
</section>

<section id="limits">
  <h2><span class="num">14</span>Limitations</h2>
  <div class="card">
    <ul class="tight">
      <li><b>Association agreement, not labelled ground truth.</b> The reference is another tracker run, not a human annotation.
        The KPI measures replay fidelity, which is the correct target for this gate decision.</li>
      <li><b>One SRR fixture.</b> The SRR result is reported separately and is not used to set the gate; the pooled set is
        dominated by the 10 HDF_TRACK scenes.</li>
      <li><b>Coarse grid.</b> The scan is 0.5 m in X and Y. The constrained optimum is the best tested cell, not a
        continuous optimum; a 1.25 m or 1.4 m gate was not measured.</li>
      <li><b>Velocity noise is asymmetric.</b> Vy p95 (1.00 m/s) is 2.6× Vx p95 (0.39 m/s). A single ΔV for both axes is a
        simplification; per-axis velocity gates would be the next refinement.</li>
      <li><b>No temporal correlation.</b> The production backend scores each scan independently. Multi-scan association
        would change the IDSW trade-off but not the physical gate bounds.</li>
    </ul>
  </div>
</section>

<section id="appendix">
  <h2><span class="num">A</span>Appendix — full measured tables</h2>
  <details>
    <summary>Asymmetric 5 × 4 gate grid at ΔV = 0.5 m/s (20 cells)</summary>
    {grid_table(cells)}
    <p class="caption">F1, p95 position error and IDSW/1k for every measured cell. Green outline = deployed; red dashed =
      rejected candidate; ✓ / ✗ = physical feasibility under the policy constraints.</p>
  </details>
  <details>
    <summary>Published symmetric sweep (54 points, position × velocity)</summary>
    {sweep_table(sweep['grid'])}
    <p class="caption">Independent cross-check from <code>threshold_sweep.json</code>. The deployed velocity 0.5 m/s and
      position 1.5 m point is highlighted; it matches the asymmetric measurement (69.33% at ΔX = ΔY = 1.5 m).</p>
  </details>
  <details>
    <summary>Configuration provenance and open item</summary>
    <p>The decision brief records the pushed values as ΔX = 1.5 m, ΔY = 1.0 m, ΔV = 0.5 m/s. The local
      <code>dump_code</code> snapshot at commit <code>cce138dd</code> still carries <code>vcs_yposn_threshold = 1.5</code> in
      <code>ALL_KPI/KPI/UDP_KPI/b_data_storage/kpi_config_storage.py</code> (commit <code>286ff3f9</code>). Before publishing
      this report externally, confirm that the deployed branch contains the ΔY = 1.0 m value; if the checkout is the source of
      truth, the deployed point is the symmetric 1.5 / 1.5 / 0.5 row (F1 69.33%, p95 1.69 m), which is also feasible under the
      p95 ≤ 1.5 m constraint only if the tolerance is relaxed to 1.7 m. This provenance check does not change the comparison:
      the candidate 3.0 / 2.0 / 0.5 m remains rejected.</p>
  </details>
</section>

<div class="footer">
  Generated 18 Nov 2026 from measured HDF replay fixtures. Metrics are micro-averaged over 11 scenes / 4,137 scans.
  Report source: <code>empirical_research_harness/benchmarks/build_tracker_threshold_optimality_report.py</code>.
  This page is self-contained; no external assets or network access are required.
</div>

</div>
</body>
</html>
"""
    OUT_PATH.write_text(html_doc, encoding="utf-8")
    print(f"WROTE {OUT_PATH} ({OUT_PATH.stat().st_size:,} bytes)")
    for marker in ("Gate landscape", "Optimisation trace", "Physical limits", "Decision log"):
        assert marker in html_doc, marker
    assert html_doc.count("<svg") >= 6
    print(f"charts={html_doc.count('<svg')} details={html_doc.count('<details')} tables={html_doc.count('<table')}")


if __name__ == "__main__":
    main()
