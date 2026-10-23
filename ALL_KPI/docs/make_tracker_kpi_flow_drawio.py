"""Generate the Tracker-KPI I/O flow diagram as a Draw.io (.drawio) file.

Reuses the node/edge model from make_tracker_kpi_flow.py so the HTML and the
Draw.io versions can never drift apart.

NOTE: the default output name is distinct on purpose. A richer hand-made
diagram already lives at ~/Desktop/Tracker_KPI_IO_Flow_Diagram.drawio and
must not be overwritten; pass an explicit path to write elsewhere.

Usage:  python make_tracker_kpi_flow_drawio.py [output.drawio]
"""
from __future__ import annotations

import html
import os
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from make_tracker_kpi_flow import EDGES, LANES, NODES  # noqa: E402

DEFAULT_OUT = (r"C:\Users\ouymc2\Desktop"
               r"\Tracker_KPI_IO_Flow_Diagram_7lane.drawio")

# Draw.io palette (dark-ish, prints fine on white too)
LANE_STYLE = {
    "L0": ("ENTRY &amp; ORCHESTRATION", "#dae8fc", "#6c8ebf"),
    "L1": ("PERSISTENCE &mdash; HDF5 READ", "#d5e8d4", "#82b366"),
    "L2": ("DATA STORAGE &mdash; CONTAINER", "#fff2cc", "#d6b656"),
    "L3": ("BUSINESS &mdash; TRACKER KPI", "#ffe6cc", "#d79b00"),
    "M": ("SUB-FLOW &mdash; match_tracker_data() PER-SCAN CORE", "#f8cecc", "#b85450"),
    "L4": ("PRESENTATION &mdash; PLOTS + HTML", "#e1d5e7", "#9673a6"),
    "L5": ("OUTPUTS", "#d5e8d4", "#82b366"),
}

NODE_STYLE = (
    "rounded=1;whiteSpace=wrap;html=1;align=left;verticalAlign=top;"
    "spacingLeft=10;spacingTop=6;spacingRight=10;spacingBottom=6;"
    "fillColor=#ffffff;strokeColor=#666666;fontSize=11;shadow=0;"
    "arcSize=8;"
)
CORE_STYLE = NODE_STYLE.replace("fillColor=#ffffff", "fillColor=#fff2cc").replace(
    "strokeColor=#666666", "strokeColor=#b8862b;strokeWidth=2"
)

NODE_W, NODE_H = 470, 150
COL_X = [30, 520, 1010]
LANE_W = 1520
LANE_HEADER = 34
ROW_GAP = 18


# HTML entities used in the labels are not valid XML entities - convert them to
# their Unicode characters first, then XML-escape the whole label. draw.io
# decodes the attribute back to HTML (styles carry html=1) and renders it.
HTML_ENT = {
    "mdash": "\u2014", "ndash": "\u2013", "nbsp": "\u00a0", "rarr": "\u2192",
    "larr": "\u2190", "cap": "\u2229", "cup": "\u222a", "ne": "\u2260",
    "le": "\u2264", "ge": "\u2265", "infin": "\u221e", "deg": "\u00b0",
    "middot": "\u00b7", "times": "\u00d7", "plusmn": "\u00b1", "sdot": "\u22c5",
    "alpha": "\u03b1", "mu": "\u03bc", "tau": "\u03c4", "eps": "\u03b5",
    "Delta": "\u0394", "Sigma": "\u03a3", "sigma": "\u03c3", "phi": "\u03c6",
    "theta": "\u03b8", "rho": "\u03c1", "psi": "\u03c8", "chi": "\u03c7",
    "le2": "\u2264",
}


def deent(text: str) -> str:
    """Convert HTML entities to Unicode characters."""
    for name, ch in HTML_ENT.items():
        text = text.replace(f"&{name};", ch)
    return text


def esc(text: str) -> str:
    """Escape plain text for a draw.io XML attribute."""
    return html.escape(deent(text), quote=True).replace("\n", "<br>")


def esc_label(raw_html: str) -> str:
    """XML-escape a raw HTML label (draw.io decodes it back when html=1)."""
    return html.escape(raw_html, quote=True).replace("\n", "<br>")


def node_label(n: dict) -> str:
    """Build the draw.io HTML label for a node."""
    io = deent(n["io"])
    note = deent(n["note"])
    return esc_label(
        f"<b>{esc(n['step'])}</b> <b>{esc(n['title'])}</b><br>"
        f"<i>{esc(n['src'])}</i><br><br>"
        f"<b>IO:</b> {io}<br>"
        f"<i>{note}</i>"
    )


def build(out_path: str) -> str:
    by_lane: dict[str, list] = {}
    for n in NODES:
        by_lane.setdefault(n["lane"], []).append(n)

    order = ["L0", "L1", "L2", "L3", "M", "L4", "L5"]
    cells: list[str] = []
    edges: list[str] = []

    y = 20
    lane_geo: dict[str, tuple[int, int]] = {}
    for lid in order:
        nodes = by_lane.get(lid, [])
        if not nodes:
            continue
        rows = (len(nodes) + 2) // 3
        lane_h = LANE_HEADER + rows * (NODE_H + ROW_GAP) + 16
        title, fill, stroke = LANE_STYLE[lid]
        cells.append(
            f'<mxCell id="lane_{lid}" value="{esc(title)}" style="swimlane;html=1;'
            f'horizontal=1;startSize={LANE_HEADER};rounded=1;arcSize=6;'
            f'fillColor={fill};strokeColor={stroke};fontSize=13;fontStyle=1;'
            f'align=left;spacingLeft=12;verticalAlign=middle;" vertex="1" parent="1">'
            f'<mxGeometry x="20" y="{y}" width="{LANE_W}" height="{lane_h}" as="geometry"/>'
            f'</mxCell>'
        )
        lane_geo[lid] = (y, lane_h)
        for i, n in enumerate(nodes):
            r, c = divmod(i, 3)
            x = COL_X[c]
            yy = LANE_HEADER + 12 + r * (NODE_H + ROW_GAP)
            style = CORE_STYLE if n["id"] in ("n_match", "m_matrix") else NODE_STYLE
            cells.append(
                f'<mxCell id="{n["id"]}" value="{node_label(n)}" style="{style}" '
                f'vertex="1" parent="lane_{lid}">'
                f'<mxGeometry x="{x}" y="{yy}" width="{NODE_W}" height="{NODE_H}" as="geometry"/>'
                f'</mxCell>'
            )
        y += lane_h + 26

    for i, (src, dst, label) in enumerate(EDGES):
        color = "#b8862b" if src in ("n_match", "m_matrix") else "#666666"
        style = (
            "edgeStyle=orthogonalEdgeStyle;rounded=1;html=1;jumpStyle=arc;jumpSize=8;"
            f"strokeColor={color};strokeWidth=1.5;endArrow=block;endFill=1;"
            "fontSize=9;labelBackgroundColor=#ffffff;exitX=0.5;exitY=1;exitDx=0;exitDy=0;"
            "entryX=0.5;entryY=0;entryDx=0;entryDy=0;"
        )
        edges.append(
            f'<mxCell id="e{i}" value="{esc(label)}" style="{style}" edge="1" parent="1" '
            f'source="{src}" target="{dst}">'
            f'<mxGeometry relative="1" as="geometry"/>'
            f'</mxCell>'
        )

    total_h = y + 40
    xml = (
        '<?xml version="1.0" encoding="UTF-8"?>\n'
        '<mxfile host="app.diagrams.net" agent="aprism-tracker-kpi-flow" '
        f'version="24.7.17" type="device" modified="{time.strftime("%Y-%m-%dT%H:%M:%S.000Z")}">\n'
        '  <diagram id="tracker-kpi-io" name="Tracker KPI IO Flow">\n'
        '    <mxGraphModel dx="1400" dy="900" grid="1" gridSize="10" guides="1" tooltips="1" '
        'connect="1" arrows="1" fold="1" page="1" pageScale="1" pageWidth="1600" '
        f'pageHeight="{total_h}" math="0" shadow="0">\n'
        '      <root>\n'
        '        <mxCell id="0" />\n'
        '        <mxCell id="1" parent="0" />\n'
        + "\n".join("        " + c for c in cells)
        + "\n"
        + "\n".join("        " + e for e in edges)
        + '\n      </root>\n'
        '    </mxGraphModel>\n'
        '  </diagram>\n'
        '</mxfile>\n'
    )
    os.makedirs(os.path.dirname(out_path) or ".", exist_ok=True)
    with open(out_path, "w", encoding="utf-8") as f:
        f.write(xml)
    return out_path


if __name__ == "__main__":
    out = sys.argv[1] if len(sys.argv) > 1 else DEFAULT_OUT
    p = build(out)
    print(f"wrote {p} ({os.path.getsize(p)} bytes)")
    print(f"  nodes={len(NODES)} edges={len(EDGES)}")
