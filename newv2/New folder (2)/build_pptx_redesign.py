#!/usr/bin/env python3
"""Rebuild APRISM Executive Presentation — 16:9 widescreen, zero overlap."""
from pptx import Presentation
from pptx.util import Inches, Pt, Emu
from pptx.dml.color import RGBColor
from pptx.enum.text import PP_ALIGN, MSO_ANCHOR
from pptx.enum.shapes import MSO_SHAPE, MSO_CONNECTOR
from pptx.enum.chart import XL_CHART_TYPE
import os

# ---- Palette ----
BG = RGBColor(11, 19, 27)          # #0B131B
CARD = RGBColor(18, 32, 44)         # #12202C
LINE = RGBColor(31, 53, 71)         # #1F3547
WHITE = RGBColor(255, 255, 255)
SEC = RGBColor(159, 180, 194)       # #9FB4C2
GREEN = RGBColor(53, 224, 161)      # #35E0A1
BLUE = RGBColor(65, 182, 255)       # #41B6FF
RED = RGBColor(255, 107, 107)       # #FF6B6B

SLIDE_WIDTH = Inches(13.333)
SLIDE_HEIGHT = Inches(7.5)

# ---- Helper builders ----
def add_bg(slide):
    slide.background.fill.solid()
    slide.background.fill.fore_color.rgb = BG

def add_rect(slide, left, top, width, height, fill_color, line_color=LINE, line_width=Pt(0.5)):
    shape = slide.shapes.add_shape(MSO_SHAPE.ROUNDED_RECTANGLE, left, top, width, height)
    shape.fill.solid()
    shape.fill.fore_color.rgb = fill_color
    shape.line.fill.background()
    shape.line.color.rgb = line_color
    shape.line.width = line_width
    shape.adjustments[0] = 0.05  # slight corner radius
    return shape

def add_textbox(slide, left, top, width, height, text, font_color=WHITE, font_size=Pt(10), bold=False, align=PP_ALIGN.LEFT):
    txBox = slide.shapes.add_textbox(left, top, width, height)
    tf = txBox.text_frame
    tf.word_wrap = True
    p = tf.paragraphs[0]
    p.text = text
    p.font.size = font_size
    p.font.color.rgb = font_color
    p.font.bold = bold
    p.font.name = "Calibri"
    p.alignment = align
    p.space_after = Pt(2)
    tf.margin_left = Inches(0.05)
    tf.margin_right = Inches(0.05)
    tf.margin_top = Inches(0.05)
    tf.margin_bottom = Inches(0.05)
    return txBox

def add_arrow(slide, left, top, width, height, fill_color=LINE):
    # Thin arrow connector
    arrow = slide.shapes.add_shape(MSO_SHAPE.RIGHT_ARROW, left, top, width, height)
    arrow.fill.solid(); arrow.fill.fore_color.rgb = fill_color
    arrow.line.fill.background()
    return arrow

# =======================
# PRESENTATION
# =======================
prs = Presentation()
prs.slide_width = SLIDE_WIDTH
prs.slide_height = SLIDE_HEIGHT

# ============================================================
# SLIDE 1: The Cluster Slicing Failure & The Alignment Bottleneck
# ============================================================
slide = prs.slides.add_slide(prs.slide_layouts[6])  # blank
add_bg(slide)

# Header band
hdr = add_rect(slide, Inches(0.8), Inches(0.35), Inches(11.733), Inches(0.8), CARD)
add_textbox(slide, Inches(1.0), Inches(0.38), Inches(11.2), Inches(0.4),
            "SLIDE 1  ·  THE CLUSTER SLICING FAILURE  ·  A-PRISM EXECUTIVE BRIEFING",
            font_color=SEC, font_size=Pt(9), bold=False)
add_textbox(slide, Inches(1.0), Inches(0.65), Inches(11.0), Inches(0.45),
            "Why a 300-Log Distributed Replay Drops 360,000 Frames — and Where AF Dynamic Alignment Becomes the Wall",
            font_color=WHITE, font_size=Pt(16), bold=True)

# ---- LEFT COLUMN (The Attempt) ----
left_card = add_rect(slide, Inches(0.8), Inches(1.35), Inches(5.2), Inches(4.8), CARD)
add_textbox(slide, Inches(1.0), Inches(1.45), Inches(4.8), Inches(0.4),
            "THE ATTEMPT — Cluster Chunking (20 Nodes)", font_color=GREEN, font_size=Pt(12), bold=True)

# Vector diagram: 300 logs -> nodes
box_w, box_h = Inches(0.9), Inches(0.35)
for i in range(5):
    b = add_rect(slide, Inches(1.2), Inches(2.05 + i*0.42), Inches(3.8), box_h, RGBColor(22, 40, 60))
    label = f"Log Chunk {i*20+1}-{i*20+20}" if i < 4 else "Log Chunk 281–300 (Node 20)"
    add_textbox(slide, Inches(1.25), Inches(2.08 + i*0.42), Inches(3.7), Inches(0.3),
                label, font_color=WHITE, font_size=Pt(7), bold=False)

# Overlap indicator
add_rect(slide, Inches(1.2), Inches(4.0), Inches(3.8), Inches(0.25), RGBColor(255, 107, 107), line_color=RED)
add_textbox(slide, Inches(1.25), Inches(4.02), Inches(3.7), Inches(0.2),
            "OVERLAP ZONE: Log 16 → Node 2 (16-log warm-up chunk)", font_color=WHITE, font_size=Pt(7), bold=True)

# Small explanation text
add_textbox(slide, Inches(1.2), Inches(4.35), Inches(4.5), Inches(1.8),
            "• 300 logs split into 20 HPCC nodes.\n"
            "• Each node gets 15 logs + 1 warm-up overlap (16 total).\n"
            "• EKF tracker adapts in ~10–20 frames inside warm-up.\n"
            "• 16-log overlap successfully bootstraps ego-motion state.",
            font_color=SEC, font_size=Pt(8), bold=False)

# Connector arrow
add_textbox(slide, Inches(5.45), Inches(2.3), Inches(0.6), Inches(0.3),
            "→", font_color=BLUE, font_size=Pt(24), bold=True, align=PP_ALIGN.CENTER)

# ---- RIGHT COLUMN (The Failure) ----
right_card = add_rect(slide, Inches(6.0), Inches(1.35), Inches(6.5), Inches(4.8), CARD)
add_textbox(slide, Inches(6.2), Inches(1.45), Inches(6.1), Inches(0.4),
            "THE FAILURE — FMCW Pipeline Wall (AF Dynamic Alignment)", font_color=RED, font_size=Pt(12), bold=True)

# Pipeline diagram (horizontal flow with boxes)
pipeline_items = ["ADC", "Range FFT", "Doppler FFT", "CFAR", "CDC", "Beamforming", "AF Dynamic Alignment"]
for idx, item in enumerate(pipeline_items):
    x_start = Inches(6.4 + idx * 0.78)
    box = add_rect(slide, x_start, Inches(2.2), Inches(0.7), Inches(0.35), RGBColor(22, 40, 60), line_color=LINE)
    add_textbox(slide, x_start, Inches(2.22), Inches(0.7), Inches(0.32), item,
                font_color=WHITE, font_size=Pt(6.5), bold=False, align=PP_ALIGN.CENTER)
    # Arrow between boxes
    if idx < len(pipeline_items) - 1:
        arr = slide.shapes.add_shape(MSO_SHAPE.RIGHT_ARROW,
                                      x_start + Inches(0.72), Inches(2.28), Inches(0.15), Inches(0.06))
        arr.fill.solid(); arr.fill.fore_color.rgb = BLUE; arr.line.fill.background()

# Red outline box around AF Alignment
outline = add_rect(slide, Inches(10.85), Inches(2.1), Inches(2.0), Inches(0.6), RGBColor(0,0,0), line_color=RED, line_width=Pt(3))
outline.fill.background()  # transparent fill, red outline only works with line; adjust
outline.fill.solid(); outline.fill.fore_color.rgb = RGBColor(11,19,27)  # dark fill so only outline shows? Actually we want outline visible
outline.line.color.rgb = RED; outline.line.width = Pt(2.5)
add_textbox(slide, Inches(10.95), Inches(2.32), Inches(1.8), Inches(0.3),
            "THE WALL\n30–40 logs (400 frames / 20 min)", font_color=RED, font_size=Pt(8), bold=True, align=PP_ALIGN.CENTER)

# Below pipeline: explanation
add_textbox(slide, Inches(6.2), Inches(2.95), Inches(6.1), Inches(1.2),
            "FMCW pipeline requires 30–40 logs (~400 frames, $K_0=0.0025$) for boresight convergence.\n"
            "A 1-log warm-up (16-log overlap) is mathematically impossible for AF Alignment.\n"
            "Result: 360,000 frames dropped across the 20-node cluster replay due to Tier-2 angle KPI violations.",
            font_color=SEC, font_size=Pt(9), bold=False)

# Arrow pointing down to banner
add_textbox(slide, Inches(11.5), Inches(4.2), Inches(0.5), Inches(0.3),
            "↓", font_color=BLUE, font_size=Pt(20), bold=True, align=PP_ALIGN.CENTER)

# ---- BOTTOM SPEAKER BANNER ----
banner = add_rect(slide, Inches(0.8), Inches(6.35), Inches(11.733), Inches(0.7), CARD)
add_textbox(slide, Inches(1.0), Inches(6.4), Inches(11.4), Inches(0.6),
            "TAKEAWAY  ·  Cluster chunking with 16-log overlap bootstraps the Kalman tracker, but AF Dynamic Alignment demands 30–40 logs to converge — making a 1-log warm-up impossible and forcing 360k dropped frames.",
            font_color=WHITE, font_size=Pt(11), bold=True, align=PP_ALIGN.CENTER)

prs.save("C:\\Users\\ouymc2\\Desktop\\APRISM_Executive_Demo.pptx")
print("Slide 1 saved.")

# ============================================================
# SLIDE 2: Breakthrough 1 — Dual-Horizon Fast DA & Preflight Seeding
# ============================================================
slide = prs.slides.add_slide(prs.slide_layouts[6])
add_bg(slide)

hdr = add_rect(slide, Inches(0.8), Inches(0.35), Inches(11.733), Inches(0.8), CARD)
add_textbox(slide, Inches(1.0), Inches(0.38), Inches(11.2), Inches(0.4),
            "SLIDE 2  ·  BREAKTHROUGH 1  ·  PAPER 1 (IEEE T-IV / IV 2027)", font_color=SEC, font_size=Pt(9), bold=False)
add_textbox(slide, Inches(1.0), Inches(0.65), Inches(11.0), Inches(0.45),
            "Overcoming the Cold-Start Barrier via Dual-Horizon Dynamic Alignment + Preflight Header Seeding",
            font_color=WHITE, font_size=Pt(16), bold=True)

# ---- LEFT: Equations & Intuition ----
left_card = add_rect(slide, Inches(0.8), Inches(1.35), Inches(5.5), Inches(4.8), CARD)
add_textbox(slide, Inches(1.0), Inches(1.45), Inches(5.1), Inches(0.35),
            "FORMULATION & INTUITION", font_color=GREEN, font_size=Pt(12), bold=True)

# Equations block
add_textbox(slide, Inches(1.0), Inches(1.95), Inches(5.1), Inches(0.6),
            "$K_{\\mathrm{DA}}(N) = K_{\\mathrm{fast}} e^{-\\alpha N} + K_{\\mathrm{slow}}$\n"
            "$\\quad \\; K_{\\mathrm{fast}}=0.05, \\; K_{\\mathrm{slow}}=0.0025, \\; \\alpha=0.08$",
            font_color=WHITE, font_size=Pt(10), bold=True)

add_textbox(slide, Inches(1.0), Inches(2.65), Inches(5.1), Inches(0.35),
            "Stationary Doppler Gate:\n"
            "$|v_r + v_{\\mathrm{ego}} \\cos\\theta| \\le \\epsilon$  (clutter rejection)",
            font_color=BLUE, font_size=Pt(10), bold=True)

add_textbox(slide, Inches(1.0), Inches(3.05), Inches(5.1), Inches(0.35),
            "Preflight Seeding (t = 0):\n"
            "Converged header $\\theta_{\\mathrm{az}}=-1.145^\\circ$ injected at replay start",
            font_color=WHITE, font_size=Pt(10), bold=True)

# Intuition bullets
add_textbox(slide, Inches(1.0), Inches(3.55), Inches(5.1), Inches(1.8),
            "INTUITION:\n"
            "• Straightening crooked glasses in the first 2 seconds.\n"
            "• Exponential decay pulls gain from 0.05 → 0.0025 in 46 frames.\n"
            "• Doppler stationary gate prevents clutter contamination.\n"
            "• Preflight seeding eliminates replay latency entirely.",
            font_color=SEC, font_size=Pt(9), bold=False)

# ---- RIGHT: High-res plot ----
right_card = add_rect(slide, Inches(6.6), Inches(1.35), Inches(5.9), Inches(4.8), CARD)
add_textbox(slide, Inches(6.8), Inches(1.45), Inches(5.5), Inches(0.35),
            "EMPIRICAL RESULT — BORESIGHT LOCK", font_color=GREEN, font_size=Pt(12), bold=True)

# Insert plot image (maintain aspect ratio)
plot_path = "C:\\Users\\ouymc2\\Desktop\\aprism_figs\\plot_dual_horizon.png"
if os.path.exists(plot_path):
    slide.shapes.add_picture(plot_path, Inches(6.9), Inches(2.0), Inches(5.3), Inches(3.0))

# Stats box under plot
stats_box = add_rect(slide, Inches(6.9), Inches(5.1), Inches(5.3), Inches(0.9), RGBColor(11,19,27), line_color=LINE)
add_textbox(slide, Inches(7.0), Inches(5.2), Inches(5.0), Inches(0.7),
            "LOCK FRAME 46  |  2.3 s\nBASELINE: 400 frames (20 min)  →  360k frames saved per 20-node replay",
            font_color=WHITE, font_size=Pt(9), bold=True, align=PP_ALIGN.CENTER)

# ---- BOTTOM BANNER ----
banner = add_rect(slide, Inches(0.8), Inches(6.35), Inches(11.733), Inches(0.7), CARD)
add_textbox(slide, Inches(1.0), Inches(6.4), Inches(11.4), Inches(0.6),
            "TAKEAWAY  ·  Our Dual-Horizon exponential gain schedule locks sensor boresight in 46 frames (<2.3 s) instead of 400 frames, completely eliminating the 30-log cluster warm-up barrier.",
            font_color=WHITE, font_size=Pt(11), bold=True, align=PP_ALIGN.CENTER)

prs.save("C:\\Users\\ouymc2\\Desktop\\APRISM_Executive_Demo.pptx")
print("Slide 2 saved.")

# ============================================================
# SLIDE 3: Breakthrough 2 — Virtual Aperture, Adaptive Gating
# ============================================================
slide = prs.slides.add_slide(prs.slide_layouts[6])
add_bg(slide)

hdr = add_rect(slide, Inches(0.8), Inches(0.35), Inches(11.733), Inches(0.8), CARD)
add_textbox(slide, Inches(1.0), Inches(0.38), Inches(11.2), Inches(0.4),
            "SLIDE 3  ·  BREAKTHROUGH 2  ·  PAPER 2 (IEEE TAES / RADAR CONF OCT 30)", font_color=SEC, font_size=Pt(9), bold=False)
add_textbox(slide, Inches(1.0), Inches(0.65), Inches(11.0), Inches(0.45),
            "Exploiting Specular Multipath — Virtual Aperture EKF, Rank-1 Bearing Invariants, and Adaptive Gating",
            font_color=WHITE, font_size=Pt(16), bold=True)

# ---- LEFT: Virtual Aperture & The 15.2° Flaw ----
left_card = add_rect(slide, Inches(0.8), Inches(1.35), Inches(5.6), Inches(4.8), CARD)
add_textbox(slide, Inches(1.0), Inches(1.45), Inches(5.2), Inches(0.35),
            "VIRTUAL APERTURE  ·  THE 15.2° MIRROR FLAW", font_color=RED, font_size=Pt(12), bold=True)

# Diagram text: Target Mirroring vs Virtual Sensor
add_textbox(slide, Inches(1.0), Inches(1.95), Inches(5.2), Inches(0.8),
            "WRONG (Target Mirroring):\n"
            "$\\mathbf{p}^* = \\mathbf{p} - 2(\\hat{\\mathbf{n}} \\cdot \\mathbf{p} - d)\\hat{\\mathbf{n}}$\n"
            "→ Bearing error $15.19^\\circ$ ($8.0$ m at $30$ m)\n"
            "Range = exact (zero error); angle = broken",
            font_color=RED, font_size=Pt(9), bold=True)

add_rect(slide, Inches(1.0), Inches(2.85), Inches(5.2), Inches(0.02), RGBColor(31,53,71))

add_textbox(slide, Inches(1.0), Inches(2.95), Inches(5.2), Inches(0.8),
            "CORRECT (Virtual Sensor Origin):\n"
            "$\\mathbf{s}^* = 2d\\hat{\\mathbf{n}}$  →  $\\mathbf{p} - \\mathbf{p}_s = 2d\\hat{\\mathbf{n}}$\n"
            "Rank-1 Invariant: $\\Vert{}\\mathbf{p} - \\mathbf{p}_s - 2d\\hat{\\mathbf{n}}\\Vert{} = 0$\n"
            "Sensor-origin mirror eliminates $15.19^\\circ$ bearing error",
            font_color=GREEN, font_size=Pt(9), bold=True)

# EKF augmentation box
add_rect(slide, Inches(1.0), Inches(4.0), Inches(5.2), Inches(0.85), RGBColor(18,32,44), line_color=BLUE)
add_textbox(slide, Inches(1.1), Inches(4.08), Inches(5.0), Inches(0.7),
            "EKF AUGMENTATION: $\\mathbf{R}_{\\mathrm{eff}} = \\mathrm{diag}(\\sigma^2) + \\mathbf{J}_\\xi \\boldsymbol{\\Sigma}_\\xi \\mathbf{J}_\\xi^T$\n"
            "→ Turns specular reflection into second virtual eye\n"
            "Position RMSE: $1.969 \\mathrm{m} \\rightarrow 0.651 \\mathrm{m}$  (–67%)",
            font_color=WHITE, font_size=Pt(9), bold=False)

# ---- RIGHT: Adaptive Gating ----
right_card = add_rect(slide, Inches(6.8), Inches(1.35), Inches(5.7), Inches(4.8), CARD)
add_textbox(slide, Inches(7.0), Inches(1.45), Inches(5.3), Inches(0.35),
            "KINEMATICS-AWARE ADAPTIVE GATING", font_color=BLUE, font_size=Pt(12), bold=True)

# IMM failure explanation
add_textbox(slide, Inches(7.0), Inches(1.95), Inches(5.3), Inches(0.9),
            "WHY IMM GATING FAILS:\n"
            "• Mode probability switches ONLY after association.\n"
            "• During $6 \\mathrm{m/s}^2$ cut-in: causal circularity (key locked inside box).\n"
            "• Cut-in recall: $88.0\\%$ (IMM) vs $99.6\\%$ (adaptive).",
            font_color=RED, font_size=Pt(9), bold=False)

# Adaptive gate equation
add_textbox(slide, Inches(7.0), Inches(3.0), Inches(5.3), Inches(1.0),
            "ADAPTIVE FORMULATION:\n"
            "$\\gamma_{\\mathrm{ad}} = \\gamma_0 \\left(1 + 0.8 \\frac{\\Vert{}\\mathbf{a}\\Vert{}}{a_{\\mathrm{max}}} + 0.5 \\frac{\\Vert{}\\mathbf{y}\\Vert{}^2}{\\mathrm{Tr}(\\mathbf{S})}\\right)$\n"
            "Range: $\\gamma \\in [9.21, \\; 40.0]$  ·  Hard-clamped for runtime safety",
            font_color=WHITE, font_size=Pt(9), bold=True)

# Stats box
stats_box = add_rect(slide, Inches(7.0), Inches(4.2), Inches(5.3), Inches(1.0), RGBColor(11,19,27), line_color=GREEN)
add_textbox(slide, Inches(7.1), Inches(4.3), Inches(5.0), Inches(0.8),
            "GATING RESULTS:\n"
            "Cut-in recall  $86.3\\% \\rightarrow 99.6\\%$\n"
            "Innovation dilation + acceleration widening\n"
            "Frozen rank gate $S_{(231)} \\le q \\le S_{(247)}$",
            font_color=WHITE, font_size=Pt(9), bold=False)

# XOR contract note
add_rect(slide, Inches(7.0), Inches(5.35), Inches(5.3), Inches(0.6), RGBColor(18,32,44), line_color=RED)
add_textbox(slide, Inches(7.1), Inches(5.4), Inches(5.0), Inches(0.45),
            "SAFETY CONTRACT: XOR Sentinel  ·  $\\mathrm{APRISM\\_ASSIMILATED\\_MIRROR\\_PROB} = -1.0$  ·  Zero-risk feature flag",
            font_color=WHITE, font_size=Pt(8), bold=True, align=PP_ALIGN.CENTER)

# ---- BANNER ----
banner = add_rect(slide, Inches(0.8), Inches(6.35), Inches(11.733), Inches(0.7), CARD)
add_textbox(slide, Inches(1.0), Inches(6.4), Inches(11.4), Inches(0.6),
            "TAKEAWAY  ·  Correcting the 15.19° mirror angle flaw and assimilating reflections into the EKF cuts position error by 67%, while adaptive gating raises cut-in recall to 99.6%.",
            font_color=WHITE, font_size=Pt(11), bold=True, align=PP_ALIGN.CENTER)

prs.save("C:\\Users\\ouymc2\\Desktop\\APRISM_Executive_Demo.pptx")
print("Slide 3 saved.")

# ============================================================
# SLIDE 4: Real Vehicle Log Verification & Dual-Paper Roadmap
# ============================================================
slide = prs.slides.add_slide(prs.slide_layouts[6])
add_bg(slide)

hdr = add_rect(slide, Inches(0.8), Inches(0.35), Inches(11.733), Inches(0.8), CARD)
add_textbox(slide, Inches(1.0), Inches(0.38), Inches(11.2), Inches(0.4),
            "SLIDE 4  ·  REAL VEHICLE LOG VERIFICATION  ·  PUBLICATION ROADMAP", font_color=SEC, font_size=Pt(9), bold=False)
add_textbox(slide, Inches(1.0), Inches(0.65), Inches(11.0), Inches(0.45),
            "155 Real Fleet Scans — Production Integration Flags Active — Ready for IEEE & Patent Submission",
            font_color=WHITE, font_size=Pt(16), bold=True)

# ---- LEFT: Metrics Table ----
left_card = add_rect(slide, Inches(0.8), Inches(1.35), Inches(5.8), Inches(4.8), CARD)
add_textbox(slide, Inches(1.0), Inches(1.45), Inches(5.4), Inches(0.35),
            "PRODUCTION INTEGRATION  ·  155 SCANS  ·  71,779 DETECTIONS", font_color=GREEN, font_size=Pt(11), bold=True)

# Table
rows = [
    ["Metric", "Baseline (OFF)", "A-PRISM (ON)", "Delta"],
    ["Unit Tests", "Baseline pass", "40 / 40 PASS", "Verified"],
    ["Ghost Assimilation", "0 (suppressed)", "10,130 (151/155)", "+100%"],
    ["Associations (155 scans)", "9,478 OFF", "9,131 ON", "–347 (2-scan)"],
    ["Velocity Shift ($v_x$)", "—", "$0.910 / 3.743$ m/s", "Refined"],
    ["Position RMSE", "$1.969$ m", "$0.651$ m", "–67.0%"],
    ["Module Build", "MSVC C++17 clean", "Zero regression", "Bit-identical OFF"],
    ["Safety Flags", "N/A", "#if APRISM_*_ENABLE == 1", "Zero-risk"],
]

# Create a table using shapes for full control
col_widths = [Inches(1.4), Inches(1.3), Inches(1.6), Inches(1.2)]
start_x = Inches(1.0)
start_y = Inches(2.1)

for r_idx, row in enumerate(rows):
    y = start_y + Inches(r_idx * 0.38)
    for c_idx, cell_text in enumerate(row):
        cell_bg = RGBColor(22, 40, 60) if r_idx == 0 else RGBColor(11, 19, 27) if r_idx % 2 == 0 else RGBColor(18, 32, 44)
        cell_color = GREEN if r_idx == 0 else WHITE
        cell_bold = True if r_idx == 0 else False
        cell_size = Pt(7)
        cell = add_rect(slide, start_x + sum(col_widths[:c_idx]), y, col_widths[c_idx], Inches(0.32), cell_bg, line_color=LINE)
        add_textbox(slide, start_x + sum(col_widths[:c_idx]) + Inches(0.03), y + Inches(0.02), col_widths[c_idx] - Inches(0.06), Inches(0.28),
                    cell_text, font_color=cell_color, font_size=cell_size, bold=cell_bold, align=PP_ALIGN.CENTER)

# ---- RIGHT: Plot + Roadmap ----
right_card = add_rect(slide, Inches(6.9), Inches(1.35), Inches(5.6), Inches(4.8), CARD)
add_textbox(slide, Inches(7.1), Inches(1.45), Inches(5.2), Inches(0.35),
            "FLEET REPLAY  ·  PLOT & ROADMAP", font_color=BLUE, font_size=Pt(12), bold=True)

# Insert plot image
plot_path2 = "C:\\Users\\ouymc2\\Desktop\\aprism_figs\\plot_fleet_replay.png"
if os.path.exists(plot_path2):
    slide.shapes.add_picture(plot_path2, Inches(7.1), Inches(2.0), Inches(5.2), Inches(2.5))

# Roadmap text
roadmap_box = add_rect(slide, Inches(7.1), Inches(4.65), Inches(5.2), Inches(1.6), RGBColor(11,19,27), line_color=LINE)
add_textbox(slide, Inches(7.2), Inches(4.75), Inches(5.0), Inches(1.4),
            "PUBLICATION SCHEDULE\n"
            "• Paper 1 (Fast Alignment): IEEE T-IV / IV 2027 — November submission\n"
            "• Paper 2 (Virtual Aperture): IEEE TAES / Radar Conf — October 30\n"
            "• Patent IDF Appendix attached to both papers\n"
            "• All modules compiled; feature flags protect baseline",
            font_color=WHITE, font_size=Pt(8.5), bold=False)

# ---- BANNER ----
banner = add_rect(slide, Inches(0.8), Inches(6.35), Inches(11.733), Inches(0.7), CARD)
add_textbox(slide, Inches(1.0), Inches(6.4), Inches(11.4), Inches(0.6),
            "TAKEAWAY  ·  All modules compiled, verified on 155 real fleet scans behind zero-risk feature flags, and ready for two IEEE and Patent (IDF) submissions.",
            font_color=WHITE, font_size=Pt(11), bold=True, align=PP_ALIGN.CENTER)

prs.save("C:\\Users\\ouymc2\\Desktop\\APRISM_Executive_Demo.pptx")
print("Slide 4 saved. PPTX complete.")
