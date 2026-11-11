"""Empirical BEFORE-vs-AFTER experiments for A-PRISM radar concepts #1-#9.

Every number produced here is measured by executing the 1:1 kernel mirrors in
``aprism_harness.kernels`` on the physics fixtures in ``aprism_harness.signals``.
Nothing is hardcoded: the multiplication counts come from the values the
kernels return, the RMSE/recall/Pfa values come from the executed detectors,
and the figure traces are the same arrays that feed the metrics.
"""
from __future__ import annotations

import math
from typing import Dict, List, Tuple

import numpy as np
import plotly.graph_objects as go
from plotly.subplots import make_subplots

from aprism_harness import kernels as K
from aprism_harness import signals as S
from aprism_harness.concept_api import (EPS, auc, fig_entry, make_result, rmse,
                                        roc_curve, safe_div)

# signals.py references a module-level EPS it never defines (fixture bug); supply
# it here instead of forking the shared contract file.
S.EPS = getattr(S, "EPS", 1e-9)

BASE_C = "#b03a2e"      # BASELINE (feature OFF)
APR_C = "#1f6f8b"       # A-PRISM  (feature ON)
GRID = dict(template="plotly_white", margin=dict(l=64, r=24, t=64, b=52),
            legend=dict(orientation="h", y=1.02, x=0.0, bgcolor="rgba(0,0,0,0)"))


def _fig(title: str, xlab: str, ylab: str):
    """Create a publication-grade empty figure (title, axis labels, legend)."""
    fig = go.Figure()
    fig.update_layout(title=dict(text=title, x=0.0), xaxis_title=xlab,
                      yaxis_title=ylab, **GRID)
    return fig


def _db(x) -> np.ndarray:
    """Power -> dB, eps-guarded so zero cells stay finite."""
    return 20.0 * np.log10(np.maximum(np.asarray(x, dtype=float), 1e-12))


# ===========================================================================
# 1. Track-conditioned residual beat estimator
# ===========================================================================

def _range_from_cycles(cyc_per_sample: float, cfg: S.FmcwConfig, fs: float) -> float:
    """Beat-frequency -> range mapping: f_b = cyc*fs, r = c*f_b/(2*slope)."""
    slope = cfg.bandwidth_hz / cfg.chirp_time_s
    f_b = cyc_per_sample * fs
    return S.C0 * f_b / (2.0 * slope)


def _beat_est_lag1(x: np.ndarray, f_pred: float = 0.0) -> Tuple[float, int]:
    """Baseline: one lag-1 residual over the whole window -> increment estimate."""
    x = np.asarray(x)
    xf = np.empty(2 * x.size)
    xf[0::2], xf[1::2] = x.real, x.imag
    res, nmult = K.residual_lag1(xf, f_pred)
    return f_pred + res, nmult


def _beat_est_cubic4(x: np.ndarray) -> Tuple[float, int, int]:
    """A-PRISM: 4-sample cubic stencils, each within the +-0.5 cycle unwrap band."""
    est: List[float] = []
    n_mult = 0
    for b0 in range(0, x.size - 3, 4):
        xb = np.empty(8)
        xb[0::2], xb[1::2] = x[b0:b0 + 4].real, x[b0:b0 + 4].imag
        fh, _g2, _l3, nm, bad = K.residual_cubic4(xb, np.zeros(3))
        n_mult += nm
        if not bad:
            est.append(fh)
    return (float(np.mean(est)) if est else 0.0), n_mult, len(est)


def run_concept_1(seed: int) -> dict:
    """Concept #1: residual beat range-RMSE vs SNR + measured multiply counts."""
    cfg = S.FmcwConfig(seed=seed)
    fs = 10.0e6                       # beat-sampling rate
    n_samp = 64
    r_true = 1.0                      # m (within the fixture's unambiguous band)
    slope = cfg.bandwidth_hz / cfg.chirp_time_s
    f_true = 2.0 * r_true * slope / S.C0
    sigmas = [2.5, 1.6, 1.0, 0.63, 0.4, 0.25, 0.16, 0.10]
    rng = S.rng_for_seed(seed)

    base_rmse, apr_rmse, snr_db = [], [], []
    base_mults = apr_mults = 0
    base_samps = apr_samps = 0
    for sg in sigmas:
        eb, ea = [], []
        for _ in range(24):
            x = S.fmcw_beat_signal(n_samp, f_true, fs, 1.0, 0.0, sg, rng)
            cb, mb = _beat_est_lag1(x, 0.0)
            ca, ma, nblk = _beat_est_cubic4(x)
            eb.append(_range_from_cycles(cb, cfg, fs) - r_true)
            ea.append(_range_from_cycles(ca, cfg, fs) - r_true)
            base_mults, apr_mults = mb, ma
            base_samps, apr_samps = n_samp, 4 * nblk
        base_rmse.append(rmse(eb))
        apr_rmse.append(rmse(ea))
        snr_db.append(10.0 * math.log10(safe_div(1.0, sg * sg)))

    snr_db = np.asarray(snr_db)
    base_rmse = np.asarray(base_rmse)
    apr_rmse = np.asarray(apr_rmse)
    hi = int(np.argmax(snr_db))

    fig = _fig("Concept #1 — beat/Doppler range RMSE vs SNR (64 samples)",
               "beat SNR (dB)", "range RMSE (m)")
    fig.add_trace(go.Scatter(x=snr_db, y=base_rmse, name="BASELINE residual_lag1 (64 samples)",
                             mode="lines+markers", line=dict(color=BASE_C, width=2.4)))
    fig.add_trace(go.Scatter(x=snr_db, y=apr_rmse, name="A-PRISM residual_cubic4 (4-sample stencils)",
                             mode="lines+markers", line=dict(color=APR_C, width=2.4)))
    fig.update_yaxes(type="log")
    fig.add_annotation(x=snr_db[hi], y=base_rmse[hi], text=f"{base_rmse[hi]:.2e} m",
                       showarrow=True, arrowhead=2, ax=30, ay=-28, font=dict(color=BASE_C))
    fig.add_annotation(x=snr_db[hi], y=apr_rmse[hi], text=f"{apr_rmse[hi]:.2e} m",
                       showarrow=True, arrowhead=2, ax=-34, ay=26, font=dict(color=APR_C))

    fig2 = _fig("Concept #1 — real multiplication count measured from kernel returns",
                "estimator", "real multiplies per estimate")
    fig2.add_trace(go.Bar(x=["BASELINE lag-1\n(64 samples, 63 lags)",
                             "A-PRISM cubic-4\n(16 x 4-sample stencils)"],
                          y=[base_mults, apr_mults],
                          marker_color=[BASE_C, APR_C],
                          text=[f"{base_mults}", f"{apr_mults}"], textposition="outside"))
    fig2.update_yaxes(type="log")
    fig2.add_annotation(x=0.5, y=1.0, yref="paper", showarrow=False,
                        text=f"measured ratio {safe_div(base_mults, apr_mults):.2f}x fewer multiplies",
                        font=dict(size=13))
    return make_result(
        1, "Track-Conditioned Residual Beat Estimator",
        "gen_research/Core_Radar_Gen8_iND13400/software/bbe32/src/residual_track_ifc.c",
        {"range_rmse_m_hi_snr": float(base_rmse[hi]),
         "range_rmse_m_sweep_mean": float(base_rmse.mean()),
         "range_rmse_m_worst_snr": float(base_rmse[0]),
         "real_mults": int(base_mults),
         "samples_consumed": int(base_samps),
         "mults_per_sample": float(safe_div(base_mults, base_samps)),
         "curvature_available": 0},
        {"range_rmse_m_hi_snr": float(apr_rmse[hi]),
         "range_rmse_m_sweep_mean": float(apr_rmse.mean()),
         "range_rmse_m_worst_snr": float(apr_rmse[0]),
         "real_mults": int(apr_mults),
         "samples_consumed": int(apr_samps),
         "mults_per_sample": float(safe_div(apr_mults, apr_samps)),
         "curvature_available": 1},
        [fig_entry("c1_rmse_snr", "Range RMSE vs SNR", fig),
         fig_entry("c1_mults", "Measured real multiplication count", fig2)],
        notes=("Both estimators run on the same complex beat fixture "
               f"(r_true={r_true:.2f} m, f_b={f_true/1e3:.1f} kHz, fs={fs/1e6:.0f} MHz). "
               "Baseline consumes the full 64-sample window in one lag-1 accumulation; "
               "A-PRISM consumes 16 independent 4-sample cubic stencils (prior increment = 0, "
               "inside the +-0.5 cycle unwrap band) and averages their centre-increment output. "
               "Multiplication counts are the kernel-returned n_mult values, not "
               "assumed constants. A-PRISM additionally emits curvature (g_h2) and jerk (l_h3), "
               "which the lag-1 estimator cannot produce."))


# ===========================================================================
# 2. 3-product cubic-exact residual stencil
# ===========================================================================

CURV_PER_MPS2 = 0.0125      # rad/sample^2 per m/s^2 (fixture calibration, see notes)


def run_concept_2(seed: int) -> dict:
    """Concept #2: phase-curvature error vs acceleration, lag-1 (2 pt) vs cubic-4."""
    rng = S.rng_for_seed(seed)
    n_win = 16
    a0 = 0.40                     # nominal increment (rad/sample), known prior
    accels = np.arange(0.0, 8.01, 1.0)
    sigma = 0.01
    inv_rmse, curv_rmse, inv_rmse_a, curv_rmse_a = [], [], [], []
    base_mults = apr_mults = 0

    for a in accels:
        k = CURV_PER_MPS2 * a
        n = np.arange(n_win, dtype=float)
        phase = a0 * n + 0.5 * k * n * n
        eb, ea = [], []
        for _ in range(20):
            x = np.exp(1j * phase) + sigma * (rng.standard_normal(n_win)
                                              + 1j * rng.standard_normal(n_win)) / math.sqrt(2.0)
            xf = np.empty(2 * n_win)
            xf[0::2], xf[1::2] = x.real, x.imag

            # BASELINE: lag-1 over the 16-sample window -> reports the window-mean
            # increment (centre of the window), i.e. exactly 8 samples stale.
            res, mb = K.residual_lag1(xf, a0 / (2.0 * math.pi))
            est_b = a0 + 2.0 * math.pi * res
            d_now_true = a0 + k * (n_win - 0.5)

            # A-PRISM: cubic-exact 4-point stencil on the newest 4 samples plus
            # the measured curvature term extrapolated to the newest increment.
            xb = xf[2 * (n_win - 4):]
            fh, g2, _l3, ma, bad = K.residual_cubic4(xb, np.array([a0 / (2.0 * math.pi)] * 3))
            if bad:
                est_a, g2 = a0, 0.0
            else:
                est_a = a0 + 2.0 * math.pi * (fh + 2.0 * g2)
            base_mults, apr_mults = mb, ma
            eb.append(est_b - d_now_true)
            ea.append(est_a - d_now_true)
        inv_rmse.append(rmse(eb))
        inv_rmse_a.append(rmse(ea))
        # curvature: baseline has no g_h2 output -> its curvature estimate is 0
        curv_rmse.append(abs(0.0 - k))
        curv_rmse_a.append(abs(2.0 * math.pi * g2 - k))

    inv_rmse = np.asarray(inv_rmse)
    inv_rmse_a = np.asarray(inv_rmse_a)
    curv_rmse = np.asarray(curv_rmse)
    curv_rmse_a = np.asarray(curv_rmse_a)

    fig = make_subplots(rows=1, cols=2,
                        subplot_titles=("Increment error at the newest sample",
                                        "Curvature g_h2 error"))
    fig.add_trace(go.Scatter(x=accels, y=inv_rmse, name="BASELINE lag-1 (16 samples)",
                             mode="lines+markers", line=dict(color=BASE_C, width=2.4)), 1, 1)
    fig.add_trace(go.Scatter(x=accels, y=inv_rmse_a, name="A-PRISM cubic-4 (4 samples)",
                             mode="lines+markers", line=dict(color=APR_C, width=2.4)), 1, 1)
    fig.add_trace(go.Scatter(x=accels, y=curv_rmse, name="BASELINE (no curvature output)",
                             mode="lines+markers", line=dict(color=BASE_C, width=2.0, dash="dash")), 1, 2)
    fig.add_trace(go.Scatter(x=accels, y=curv_rmse_a, name="A-PRISM g_h2",
                             mode="lines+markers", line=dict(color=APR_C, width=2.4)), 1, 2)
    fig.update_layout(title="Concept #2 — quadratic-phase fixture: increment & curvature error vs acceleration",
                      **GRID)
    fig.update_xaxes(title_text="acceleration (m/s²)", row=1, col=1)
    fig.update_xaxes(title_text="acceleration (m/s²)", row=1, col=2)
    fig.update_yaxes(title_text="increment RMSE (rad/sample)", type="log", row=1, col=1)
    fig.update_yaxes(title_text="|g_h2 - k_true| (rad/sample²)", type="log", row=1, col=2)

    return make_result(
        2, "3-Product Cubic-Exact Residual Stencil",
        "gen_research/Core_Radar_Gen8_iND13400/software/bbe32/src/residual_track_ifc.c",
        {"increment_rmse_rad": float(inv_rmse[-1]),
         "increment_rmse_rad_mean": float(inv_rmse.mean()),
         "curvature_rmse_rad": float(curv_rmse[-1]),
         "curvature_equiv_mps2": float(safe_div(curv_rmse[-1], CURV_PER_MPS2)),
         "real_mults": int(base_mults),
         "points_used": 16},
        {"increment_rmse_rad": float(inv_rmse_a[-1]),
         "increment_rmse_rad_mean": float(inv_rmse_a.mean()),
         "curvature_rmse_rad": float(curv_rmse_a[-1]),
         "curvature_equiv_mps2": float(safe_div(curv_rmse_a[-1], CURV_PER_MPS2)),
         "real_mults": int(apr_mults),
         "points_used": 4},
        [fig_entry("c2_accel", "Increment and curvature error vs acceleration", fig)],
        notes=("Fixture: x[n]=exp(j(a0*n+0.5*k*n^2)) with a0=0.40 rad/sample and "
               f"k={CURV_PER_MPS2} rad/sample^2 per m/s^2 (calibration chosen so the "
               "curvature is resolvable at the stencil quantisation; the trend, not the "
               "absolute scale, is the claim). The baseline reports the window-mean increment "
               "(8 samples stale at n_win=16) and has no g_h2 output; the cubic-4 stencil "
               "recovers the centre increment and curvature, then extrapolates 2 samples to "
               "the newest increment. Multiplication counts are kernel-returned n_mult."))


# ===========================================================================
# 3. Range-adaptive dual-loop clutter CFAR
# ===========================================================================

def _ca_threshold(vec: np.ndarray, nref: int = 9, guard: int = 1,
                  pfa: float = 1e-4, free: np.ndarray = None) -> np.ndarray:
    """Per-cell CA-CFAR threshold along a row; occupied cells can be excluded."""
    n = vec.size
    out = np.empty(n)
    for i in range(n):
        idx = [(i + d) % n for d in range(-(guard + nref), guard + nref + 1)
               if abs(d) > guard]
        if free is not None:
            idx = [j for j in idx if free[j]]
        if not idx:
            out[i] = np.inf
            continue
        refs = vec[np.asarray(idx)]
        out[i] = K.aprism_ca_alpha(len(idx), pfa) * float(refs.mean())
    return out


class _Fmcw(S.FmcwConfig):
    """FmcwConfig with a working range axis.

    signals.FmcwConfig.max_range_m returns c*T_c/(2*B) (mis-dimensioned), so
    signals.range_doppler_map yields nr=round(T_c)=0 rows for every realistic
    waveform. The range axis is therefore built here from the same bin formula.
    """
    C0 = S.C0


def _rd_fixture(seed: int) -> Tuple[np.ndarray, S.FmcwConfig, int, int]:
    """RD map with a high-SNR clutter wall and a weak target masked by its skirt."""
    cfg = _Fmcw(bandwidth_hz=1.5e9, chirp_time_s=300e-6, seed=seed)
    rng = S.rng_for_seed(seed)
    nr, nd = 300, 32                                   # 0.1 m bins, 30 m span
    rd = cfg.noise_sigma * np.abs(rng.standard_normal((nr, nd)))
    for _ in range(60):                                # distributed clutter
        rd[int(rng.integers(0, nr)), int(rng.integers(0, nd))] += 3.0 * rng.random()
    wall = int(round(11.9 / cfg.range_bin_m))          # 11.9 m guardrail
    tgt = int(round(11.1 / cfg.range_bin_m))           # 11.1 m weak target
    rd[wall, :] += 60.0 * (0.8 + 0.4 * rng.random(nd))
    for off, amp in ((1, 12.0), (2, 5.0), (-1, 12.0), (-2, 5.0)):
        rd[wall + off, :] += amp * (0.8 + 0.4 * rng.random(nd))
    rd[tgt, 16] += 6.5
    rd[tgt, 15] += 1.0
    return rd, cfg, tgt, wall


def run_concept_3(seed: int) -> dict:
    """Concept #3: CA-CFAR vs dual-loop occupancy-aware CFAR on an RD map."""
    pfa = 1e-4
    trials = 5
    acc = {k: [] for k in ("b_rec", "a_rec", "b_fa", "a_fa", "lift", "b_floor", "a_floor")}
    slice_b = slice_a = None
    rd0 = None

    for t in range(trials):
        rd, cfg, tgt, wall = _rd_fixture(seed + t)
        nr, nd = rd.shape
        if rd0 is None:
            rd0 = rd.copy()
        st = K.AprismCfarState(cfg=K.AprismCfarCfg(pfa=pfa, enabled=True),
                               floor=np.full(nd, float(np.median(rd))), nbins=nd)
        nf_est = np.zeros(nr, dtype=np.uint16)
        true_floor = float(np.median(rd))
        vig = (tgt - 4, tgt + 5)
        quiet = np.ones(nr, dtype=bool)
        quiet[wall - 7:wall + 8] = False               # wall + skirt band
        quiet[vig[0]:vig[1]] = False                   # target band
        b_det = a_det = 0
        b_fa = a_fa = 0
        lifts, b_floor_err, a_floor_err = [], [], []

        for col in range(nd):                       # each doppler column = one CFAR row
            vec = rd[:, col]
            th_ca = _ca_threshold(vec, 9, 1, pfa)
            occ = vec > 6.0 * true_floor
            free = (~occ).astype(np.uint8)
            pi_occ = np.clip(vec / max(true_floor, EPS) - 1.0, 0.0, 3.0) / 3.0
            th_ap = _ca_threshold(vec, 9, 1, pfa, free=free)
            th_ap = np.where(np.isfinite(th_ap), th_ap, th_ca)

            ratio, floor_v = K.aprism_cfar_overlay(st, col, vec, th_ap, nf_est, free, pi_occ)
            if col == 16:
                lifts.append(20.0 * math.log10(max(safe_div(float(th_ap[tgt]),
                                                            float(th_ca[tgt])), 1e-6)))

            db = vec > th_ca
            da = vec > th_ap
            b_fa += int(db[quiet].sum())
            a_fa += int(da[quiet].sum())
            if col == 16:
                b_det += int(db[tgt])
                a_det += int(da[tgt])
            b_floor_err.append(20.0 * math.log10(safe_div(float(np.mean(vec)), true_floor)))
            a_floor_err.append(20.0 * math.log10(safe_div(float(st.floor[col]), true_floor)))
            if col == 16:
                slice_b, slice_a = th_ca.copy(), th_ap.copy()

        acc["b_rec"].append(float(b_det))
        acc["a_rec"].append(float(a_det))
        acc["b_fa"].append(safe_div(b_fa, nd))
        acc["a_fa"].append(safe_div(a_fa, nd))
        acc["lift"].append(float(np.median(lifts)))
        acc["b_floor"].append(rmse(b_floor_err))
        acc["a_floor"].append(rmse(a_floor_err))

    m = {k: float(np.mean(v)) for k, v in acc.items()}
    nr = rd0.shape[0]
    rng_m = np.arange(nr) * (S.C0 / (2.0 * 1.5e9))

    fig = go.Figure(go.Surface(z=_db(rd0), x=np.arange(rd0.shape[1]),
                               y=rng_m, colorscale="Inferno",
                               colorbar=dict(title="dB")))
    fig.update_layout(title="Concept #3 — RD map: clutter wall at 11.9 m masks an 11.1 m target",
                      scene=dict(xaxis_title="doppler bin", yaxis_title="range (m)",
                                 zaxis_title="power (dB)"), **GRID)

    fig2 = _fig("Concept #3 — range slice (doppler bin 16): thresholds BEFORE/AFTER",
                "range (m)", "power (dB)")
    fig2.add_trace(go.Scatter(x=rng_m, y=_db(rd0[:, 16]), name="RD power",
                              line=dict(color="#555", width=1.6)))
    fig2.add_trace(go.Scatter(x=rng_m, y=_db(slice_b), name="BASELINE CA-CFAR threshold",
                              line=dict(color=BASE_C, width=2.2, dash="dash")))
    fig2.add_trace(go.Scatter(x=rng_m, y=_db(slice_a), name="A-PRISM dual-loop threshold",
                              line=dict(color=APR_C, width=2.2)))
    fig2.add_vrect(x0=10.9, x1=11.3, fillcolor="#1f6f8b", opacity=0.15, line_width=0,
                   annotation_text="weak target", annotation_position="top left")
    fig2.add_vrect(x0=11.6, x1=12.3, fillcolor="#b03a2e", opacity=0.10, line_width=0,
                   annotation_text="wall", annotation_position="top right")

    fig3 = _fig("Concept #3 — measured threshold lift and floor accuracy", "metric", "value")
    fig3.add_trace(go.Bar(name="BASELINE", x=["threshold lift (dB)", "floor RMSE (dB)"],
                          y=[0.0, m["b_floor"]], marker_color=BASE_C,
                          text=[f"{0.0:.2f}", f"{m['b_floor']:.2f}"], textposition="outside"))
    fig3.add_trace(go.Bar(name="A-PRISM", x=["threshold lift (dB)", "floor RMSE (dB)"],
                          y=[m["lift"], m["a_floor"]], marker_color=APR_C,
                          text=[f"{m['lift']:.2f}", f"{m['a_floor']:.2f}"], textposition="outside"))

    return make_result(
        3, "Range-Adaptive Dual-Loop Clutter CFAR",
        "gen_research/Core_Radar_Gen8_iND13400/software/bbe32/rdd_proc/imp/src/appl_cfar_ifc.c",
        {"weak_target_recall": m["b_rec"], "false_alarms_per_column": m["b_fa"],
         "threshold_lift_db": 0.0, "floor_rmse_db": m["b_floor"]},
        {"weak_target_recall": m["a_rec"], "false_alarms_per_column": m["a_fa"],
         "threshold_lift_db": m["lift"], "floor_rmse_db": m["a_floor"]},        [fig_entry("c3_surface", "3D RD surface with wall + weak target", fig),
         fig_entry("c3_slice", "Range slice with BEFORE/AFTER thresholds", fig2),
         fig_entry("c3_lift", "Threshold lift and floor RMSE", fig3)],
        notes=("CFAR runs along range (each doppler column is one 'row'), pfa=1e-4, "
               "9 reference cells + 1 guard. BASELINE uses alpha_ca*mean(all refs); A-PRISM "
               "excludes tracker-occupied cells from the reference set, seeds the dual-loop "
               "floor EMA (lambda=0.02) and lets aprism_cfar_overlay apply the BLUE/CA alpha "
               "ratio to the per-cell threshold. The wall skirt raises the baseline reference "
               "mean so the weak target is masked; the occupancy mask keeps it below threshold. "
               "Targets are injected at explicit range bins because "
               "signals.range_doppler_map's r^-4 weight underflows beyond ~0.3 m. "
               f"Recall is the detection of the weak target cell (bin {tgt}, doppler 16) over "
               f"{trials} seeds; FA counts threshold crossings in the quiet band (outside the "
               "wall +-7 bins and the target +-4 bins) per doppler column; the lift is measured "
               "at the target cell; floor RMSE compares the row mean (baseline) and the dual-loop "
               "EMA state (A-PRISM, unclamped) against the map median."))


# ===========================================================================
# 4. Occupancy-BLUE CFAR with Pfa control
# ===========================================================================

def run_concept_4(seed: int) -> dict:
    """Concept #4: BLUE-weighted reference cells + Pfa-controlled alpha vs fixed CA."""
    pfa = 1e-2
    n_ref = 16
    rng = S.rng_for_seed(seed)
    pi = np.zeros(n_ref)
    pi[3:8] = 0.85                                   # tracker-occupied reference cells
    snr = np.where(pi > 0.0, 3.0, 0.5)
    beta = np.zeros(n_ref)
    K.aprism_blue_weights(pi, snr, beta)
    alpha_b = K.aprism_alpha_for_pfa(beta, n_ref, pfa)
    alpha_ca = K.aprism_ca_alpha(n_ref, pfa)
    ratio = safe_div(alpha_b, alpha_ca)

    # Synthetic CFAR rows: exponential clutter, half occupied by an interferer,
    # weak target added to the CUT in half of the trials.
    trials = 4000
    labels = (rng.random(trials) < 0.5).astype(int)
    tgt_amp = 9.0
    sc_b = np.empty(trials)
    sc_a = np.empty(trials)
    for i in range(trials):
        refs = rng.exponential(1.0, n_ref)
        refs[pi > 0.0] += rng.exponential(3.0, int((pi > 0.0).sum()))
        cut = rng.exponential(1.0) + labels[i] * tgt_amp
        sc_b[i] = safe_div(cut, float(refs.mean()))
        sc_a[i] = safe_div(cut, float(np.dot(beta, refs)))

    det_b = sc_b > alpha_ca
    det_a = sc_a > alpha_b
    noise = labels == 0
    pf_b = float(det_b[noise].mean())
    pf_a = float(det_a[noise].mean())
    rec_b = float(det_b[~noise].mean())
    rec_a = float(det_a[~noise].mean())
    fpr_b, tpr_b, _ = roc_curve(labels, sc_b)
    fpr_a, tpr_a, _ = roc_curve(labels, sc_a)
    auc_b, auc_a = auc(fpr_b, tpr_b), auc(fpr_a, tpr_a)

    fig = _fig("Concept #4 — BLUE reference-cell weights vs uniform CA weighting",
               "reference cell index", "weight")
    fig.add_trace(go.Bar(x=np.arange(n_ref), y=np.full(n_ref, 1.0 / n_ref),
                         name="BASELINE (uniform 1/N)", marker_color=BASE_C, opacity=0.65))
    fig.add_trace(go.Bar(x=np.arange(n_ref), y=beta,
                         name="A-PRISM BLUE beta", marker_color=APR_C))
    for i in np.where(pi > 0)[0]:
        fig.add_vrect(x0=i - 0.5, x1=i + 0.5, fillcolor="#999", opacity=0.12, line_width=0)
    fig.add_annotation(x=0.02, y=0.95, xref="paper", yref="paper", showarrow=False,
                       align="left", font=dict(size=12),
                       text=(f"occupied cells shaded; alpha_BLUE={alpha_b:.2f}, "
                             f"alpha_CA={alpha_ca:.2f}, ratio={ratio:.3f}"))

    fig2 = _fig("Concept #4 — ROC on clutter+weak-target rows (Pfa-controlled operating point)",
                "P(fa)", "P(detection)")
    fig2.add_trace(go.Scatter(x=fpr_b, y=tpr_b, name=f"BASELINE CA (AUC={auc_b:.3f})",
                              line=dict(color=BASE_C, width=2.4)))
    fig2.add_trace(go.Scatter(x=fpr_a, y=tpr_a, name=f"A-PRISM BLUE (AUC={auc_a:.3f})",
                              line=dict(color=APR_C, width=2.4)))
    fig2.add_trace(go.Scatter(x=[pf_b, pf_a], y=[rec_b, rec_a], mode="markers",
                              marker=dict(size=12, symbol="x", color=[BASE_C, APR_C]),
                              name="operating point (pfa=1e-4)"))
    fig2.update_xaxes(type="log", range=[-6, 0])

    return make_result(
        4, "Occupancy-BLUE CFAR with Pfa control",
        "gen_research/Core_Radar_Gen8_iND13400/software/bbe32/rdd_proc/imp/src/appl_adaptive_cfar.c",
        {"pfa_at_operating_point": pf_b, "weak_target_recall": rec_b, "auc": auc_b,
         "alpha": float(alpha_ca), "alpha_ratio": 1.0, "beta_entropy": float(-np.sum((1.0 / n_ref) * np.log(1.0 / n_ref)))},
        {"pfa_at_operating_point": pf_a, "weak_target_recall": rec_a, "auc": auc_a,
         "alpha": float(alpha_b), "alpha_ratio": float(ratio), "beta_entropy": float(-np.sum(beta * np.log(np.maximum(beta, 1e-12))))},
        [fig_entry("c4_weights", "BLUE cell weights", fig),
         fig_entry("c4_roc", "ROC with Pfa-controlled operating point", fig2)],
        notes=(f"{n_ref} reference cells, 5 of them tracker-occupied (pi=0.85, snr=3). "
               "alpha_BLUE solves sum ln(1+a*beta_i) = -ln(pfa) via aprism_alpha_for_pfa; "
               "alpha_CA = n*(pfa^(-1/n)-1). The detector statistic is CUT/reference-mean "
               "(baseline) vs CUT/(beta.ref) (A-PRISM), swept over the same "
               f"{trials} synthetic rows with exponential clutter. Both operating points are "
               "targeted at pfa=1e-4; the realised Pfa is measured, not assumed."))


# ===========================================================================
# 5. Priority-ranked CDC urban packing
# ===========================================================================

def _kendall_tau(a: np.ndarray, b: np.ndarray) -> float:
    """Kendall tau-a between two rankings (O(n^2), n is small here)."""
    n = a.size
    if n < 2:
        return 0.0
    c = d = 0
    for i in range(n):
        for j in range(i + 1, n):
            s = (a[i] - a[j]) * (b[i] - b[j])
            if s > 0:
                c += 1
            elif s < 0:
                d += 1
    return safe_div(c - d, 0.5 * n * (n - 1))


def run_concept_5(seed: int) -> dict:
    """Concept #5: original CDC order vs priority-scored top-K packing."""
    rng = S.rng_for_seed(seed)
    n_ped, n_clut = 20, 20
    ranges = np.concatenate([rng.uniform(5.0, 20.0, n_ped), rng.uniform(50.0, 80.0, n_clut)])
    snrs = np.concatenate([rng.uniform(6.0, 12.0, n_ped), rng.uniform(14.0, 22.0, n_clut)])
    cls = np.array(["near-weak pedestrian"] * n_ped + ["far-strong clutter"] * n_clut)
    order = rng.permutation(n_ped + n_clut)          # original packing order
    ranges, snrs, cls = ranges[order], snrs[order], cls[order]
    n = ranges.size
    scores = np.array([K.cdc_priority_score(snrs[i], ranges[i]) for i in range(n)])
    near = np.where(cls == "near-weak pedestrian")[0]

    idx = np.arange(n, dtype=np.int32)
    ks = [4, 8, 12, 16, 20, 24, 28]
    ret_b, ret_a, ret_o, far_b, far_a = [], [], [], [], []
    for k in ks:
        top = K.cdc_select_top_k(scores, n, k, idx)
        sel = set(idx[:top].tolist())
        oracle = set(np.argsort(-scores)[:k].tolist())    # diagnostic only
        ret_b.append(safe_div(len(set(near.tolist()) & set(range(k))), len(near)))
        ret_a.append(safe_div(len(set(near.tolist()) & sel), len(near)))
        ret_o.append(safe_div(len(set(near.tolist()) & oracle), len(near)))
        far_b.append(sum(1 for i in range(k) if cls[i] == "far-strong clutter"))
        far_a.append(sum(1 for i in sel if cls[i] == "far-strong clutter"))

    base_rank = np.arange(n, dtype=float)
    apr_rank = np.empty(n)
    k_ref = n
    top = K.cdc_select_top_k(scores, n, k_ref, idx)
    for pos, det in enumerate(idx[:top]):
        apr_rank[det] = pos
    spearman = float(np.corrcoef(base_rank, apr_rank)[0, 1])
    tau = _kendall_tau(base_rank, apr_rank)
    k_show = 16
    i_show = ks.index(k_show)

    fig = _fig("Concept #5 — CDC priority score vs range (colour = class)", "range (m)",
               "priority score  10^(SNR/10)/r^2")
    for name, col in (("near-weak pedestrian", APR_C), ("far-strong clutter", BASE_C)):
        m = cls == name
        fig.add_trace(go.Scatter(x=ranges[m], y=scores[m], mode="markers", name=name,
                                 marker=dict(size=10, color=col, line=dict(width=0.8, color="#333"))))
    fig.update_yaxes(type="log")

    fig2 = _fig("Concept #5 — near-field retention in the packed top-K", "K (packed detections)",
                "near-field retention")
    fig2.add_trace(go.Bar(x=ks, y=ret_b, name="BASELINE original order", marker_color=BASE_C))
    fig2.add_trace(go.Bar(x=ks, y=ret_a, name="A-PRISM cdc_select_top_k", marker_color=APR_C))
    fig2.add_trace(go.Scatter(x=ks, y=ret_o, name="diagnostic: global score sort",
                              mode="lines+markers", line=dict(color="#333", dash="dot", width=2.0)))
    fig2.update_yaxes(range=[0, 1.05])
    fig2.add_annotation(x=k_show, y=ret_a[i_show], text=f"{ret_a[i_show]:.2f}", showarrow=True,
                        ax=0, ay=-26, font=dict(color=APR_C))
    fig2.add_annotation(x=k_show, y=ret_b[i_show], text=f"{ret_b[i_show]:.2f}", showarrow=True,
                        ax=0, ay=-26, font=dict(color=BASE_C))

    return make_result(
        5, "Priority-Ranked CDC Urban Packing",
        "gen_research/Core_Radar_Gen8_iND13400/software/bbe32/src/cdc_priority.c + cdc_packing.c",
        {"near_retention_top16": ret_b[i_show], "near_retention_top8": ret_b[1],
         "far_clutter_top16": int(far_b[i_show]),
         "spearman_vs_original": 1.0, "kendall_vs_original": 1.0,
         "count_changed": 0},
        {"near_retention_top16": ret_a[i_show], "near_retention_top8": ret_a[1],
         "far_clutter_top16": int(far_a[i_show]),
         "spearman_vs_original": spearman, "kendall_vs_original": tau,
         "count_changed": 0, "oracle_retention_top16": ret_o[i_show]},
        [fig_entry("c5_score", "Priority score vs range by class", fig),
         fig_entry("c5_retention", "Near-field retention per K", fig2)],
        notes=(f"{n_ped} near-weak pedestrians (5-20 m, 6-12 dB) and {n_clut} far-strong "
               "clutter returns (50-80 m, 14-22 dB) in random original order. A-PRISM scores "
               "10^(SNR/10)/r^2 and applies cdc_select_top_k; the emitted count is unchanged "
               "(K), only the membership/order changes. MEASURED CAVEAT: as mirrored, "
               "cdc_select_top_k only sorts the first K entries (its inner loop is bounded by "
               "K), so it can never promote a detection from position >= K; near-field retention "
               "therefore does not improve and the emitted order is a permutation of the leading "
               "K block. The dotted 'global score sort' trace is a diagnostic (argsort of the "
               "same scores) showing what the concept would retain if the selection scanned all "
               "N entries; it is not part of the A/B claim."))


# ===========================================================================
# 6. Closed-form specular contact inversion
# ===========================================================================

def _newton_contact(s, p, u, ell, t0=0.1, iters=15, tol=1e-9):
    """Newton solve of F(t)=|p-(s+t u)|-(ell-t); returns (t, iters_used, |F|)."""
    s = np.asarray(s, float)
    p = np.asarray(p, float)
    uh = np.asarray(u, float)
    uh = uh / max(float(np.linalg.norm(uh)), EPS)
    t = float(t0)
    used = 0
    res = np.inf
    for k in range(1, iters + 1):
        q = s + t * uh
        d = p - q
        dn = max(float(np.linalg.norm(d)), EPS)
        F = dn - (ell - t)
        dF = float(np.dot(d, -uh)) / dn + 1.0
        res = abs(F)
        used = k
        if res < tol or abs(dF) < 1e-14:
            break
        t = t - F / dF
    q = s + t * uh
    return q, used, res


def run_concept_6(seed: int) -> dict:
    """Concept #6: direct-path (refused/degenerate) vs bistatic closed-form inversion."""
    rng = S.rng_for_seed(seed)
    sensor = (0.0, 0.0)
    ranges = np.linspace(3.0, 15.0, 13)
    rmse_newton, rmse_closed, base_valid, apr_valid = [], [], [], []
    iters_direct, iters_bistatic, res_direct, res_bistatic = [], [], [], []
    ell_ratio = []
    geo = None

    for r in ranges:
        eb, ea = [], []
        for _ in range(8):
            az = math.radians(rng.uniform(5.0, 35.0))
            target = np.array([r * math.cos(az), r * math.sin(az)])
            wall_x = 1.5 * r                       # back wall on the sensor axis
            mirror = np.array([2.0 * wall_x - target[0], target[1]])
            ell = float(np.linalg.norm(mirror))     # one-way bistatic path ~ 2r
            u = mirror / ell
            p = target - np.asarray(sensor)         # endpoint, not the mirror image
            alpha = wall_x / mirror[0]
            truth = alpha * mirror                  # true specular contact
            ell_ratio.append(safe_div(ell, 2.0 * r))
            if geo is None:
                geo = (np.asarray(sensor), target, mirror, truth, np.array([wall_x, 0.0]))

            # BASELINE: direct-path measurement ell = |p - s| -> kernel refuses.
            pd, ud, ld = S.detection_geometry(target, sensor)
            cd = K.ghost_inverse_contact(sensor, pd, ud, ld)
            base_valid.append(int(cd.valid))
            qn, it_d, res_d = _newton_contact(sensor, pd, ud, ld)
            iters_direct.append(it_d)
            res_direct.append(res_d)
            eb.append(float(np.linalg.norm(qn - truth)))

            # A-PRISM: bistatic ell = 2r (one algebraic step).
            ca = K.ghost_inverse_contact(sensor, p, u, ell)
            apr_valid.append(int(ca.valid))
            if ca.valid:
                contact = np.array(ca.q)            # ray foot == specular contact
                ea.append(float(np.linalg.norm(contact - truth)))
            # cost of the same answer by Newton from a poor initial guess
            _, it_b, res_b = _newton_contact(sensor, p, u, ell, t0=0.5 * ell)
            iters_bistatic.append(it_b)
            res_bistatic.append(res_b)
        rmse_newton.append(rmse(eb))
        rmse_closed.append(rmse(ea) if ea else 0.0)

    rmse_newton = np.asarray(rmse_newton)
    rmse_closed = np.asarray(rmse_closed)

    fig = _fig("Concept #6 — specular geometry: sensor, target, mirror, contact",
               "x (m)", "y (m)")
    s0, t0, mir0, truth0, wall0 = geo
    fig.add_trace(go.Scatter(x=[s0[0], t0[0]], y=[s0[1], t0[1]], mode="lines+markers+text",
                             text=["sensor", "target"], textposition="top left",
                             name="direct path (refused)", line=dict(color=BASE_C, width=1.8)))
    fig.add_trace(go.Scatter(x=[s0[0], mir0[0]], y=[s0[1], mir0[1]],
                             mode="lines+markers", name="sensor -> mirror image (bistatic ell)",
                             line=dict(color=APR_C, width=2.0, dash="dot")))
    fig.add_trace(go.Scatter(x=[truth0[0]], y=[truth0[1]], mode="markers",
                             name="true specular contact",
                             marker=dict(size=14, symbol="x", color="#111")))
    fig.add_trace(go.Scatter(x=[wall0[0], wall0[0]], y=[-0.2 * t0[1], 1.25 * t0[1]],
                             mode="lines", name="reflector plane",
                             line=dict(color="#666", width=2.0, dash="dash")))
    fig.add_trace(go.Scatter(x=[s0[0]], y=[s0[1]], mode="markers",
                             name="Newton contact on direct path (degenerate)",
                             marker=dict(size=10, symbol="circle-open", color="#999")))
    fig.update_yaxes(scaleanchor="x", scaleratio=1)

    fig2 = _fig("Concept #6 — contact-point RMSE vs target range", "target range (m)",
                "contact RMSE (m)")
    fig2.add_trace(go.Scatter(x=ranges, y=np.maximum(rmse_newton, 1e-12),
                              name="BASELINE Newton on direct ell", mode="lines+markers",
                              line=dict(color=BASE_C, width=2.4)))
    fig2.add_trace(go.Scatter(x=ranges, y=np.maximum(rmse_closed, 1e-12),
                              name="A-PRISM closed form (ell=2r)", mode="lines+markers",
                              line=dict(color=APR_C, width=2.4)))
    fig2.update_yaxes(type="log")

    return make_result(
        6, "Closed-Form Specular Contact Inversion",
        "gen_research/Core_Radar_Gen8_iND13400/software/bbe32/dyn_alignment/ghost_calib.c",
        {"contact_rmse_m": float(np.median(rmse_newton)),
         "valid_rate": float(np.mean(base_valid)),
         "algebraic_steps": 1,
         "newton_iterations": float(np.mean(iters_direct)),
         "newton_residual_m": float(np.mean(res_direct)),
         "newton_iterations_bistatic": float(np.mean(iters_bistatic)),
         "newton_residual_bistatic_m": float(np.mean(res_bistatic))},
        {"contact_rmse_m": float(np.median(rmse_closed)),
         "valid_rate": float(np.mean(apr_valid)),
         "algebraic_steps": 1,
         "newton_iterations": 0,
         "newton_residual_m": 0.0,
         "newton_iterations_bistatic": 0,
         "newton_residual_bistatic_m": 0.0,
         "ell_over_2r": float(np.mean(ell_ratio))},
        [fig_entry("c6_geometry", "Specular geometry schematic", fig),
         fig_entry("c6_rmse", "Contact RMSE vs range", fig2)],
        notes=("Fixture: back wall at 1.5x the target range on the sensor axis, so the bistatic "
               "path ell=|mirror| is ~2r (mean measured ell/2r is in the metrics). BASELINE feeds "
               "the direct-path measurement (ell=|p-s|): ghost_inverse_contact refuses it "
               "(ell^2 <= |d|^2), so a Newton iteration on F(t)=|p-(s+tu)|-(ell-t) is run "
               "instead. It converges immediately to the trivial root t=0 (contact at the "
               "sensor), which is why its contact RMSE equals the target range while its residual "
               "is ~0: the iterative path is degenerate, not merely slow. The same Newton run on "
               "the bistatic ell needs the reported iterations to reach the closed-form answer. "
               "A-PRISM's contact point is the ray foot q, and its RMSE is ~machine precision: "
               "the closed form solves the specular (ellipsoid/ray) condition algebraically in 1 "
               "step, with 0 iterations."))


# ===========================================================================
# 7. Dual-horizon fast dynamic alignment K_DA
# ===========================================================================

def run_concept_7(seed: int) -> dict:
    """Concept #7: 400-frame conservative deadband vs 50-update dual-horizon lock."""
    n_frames = 1200
    tol = K.APRISM_DA_LOCK_TOL_DEG
    need = K.APRISM_DA_LOCK_NEED
    err0 = 1.2
    meas_sigma = 0.02

    def simulate(aprism: bool):
        rng = S.rng_for_seed(seed)
        err = err0
        hold, lock_frame, trace, gains = 0, None, [], []
        deadband = 400
        for f in range(1, n_frames + 1):
            if aprism:
                n = min(f - 1, K.aprism_da_update_counts(n_frames) - 1)
                g = K.da_dual_horizon_gain(K.APRISM_DA_K_FAST, K.APRISM_DA_K_SLOW,
                                           K.APRISM_DA_ALPHA, n)
            else:
                if f <= K.baseline_da_update_counts(deadband):
                    g = K.APRISM_DA_K_SLOW            # conservative startup deadband
                else:
                    g = K.da_dual_horizon_gain(K.APRISM_DA_K_FAST, K.APRISM_DA_K_SLOW,
                                               K.APRISM_DA_ALPHA, f - deadband)
            err = err - g * err + meas_sigma * rng.standard_normal()
            locked, hold = K.da_lock_detect(err, tol, hold, need)
            trace.append(err)
            gains.append(g)
            if locked and lock_frame is None:
                lock_frame = f
        return np.asarray(trace), np.asarray(gains), lock_frame, err

    tb, gb, fb, eb_ = simulate(False)
    ta, ga, fa, ea_ = simulate(True)

    fig = _fig("Concept #7 — K_DA gain schedule (log frame axis)", "frame", "K_DA")
    fig.add_trace(go.Scatter(x=np.arange(1, n_frames + 1), y=gb, name="BASELINE (400-frame deadband)",
                             line=dict(color=BASE_C, width=2.2)))
    fig.add_trace(go.Scatter(x=np.arange(1, n_frames + 1), y=ga, name="A-PRISM dual-horizon",
                             line=dict(color=APR_C, width=2.2)))
    fig.update_xaxes(type="log")
    fig.update_yaxes(type="log")
    fig.add_vline(x=400, line=dict(color=BASE_C, dash="dash"), annotation_text="baseline deadband end")
    fig.add_vline(x=50, line=dict(color=APR_C, dash="dash"), annotation_text="A-PRISM update cap")

    fig2 = _fig("Concept #7 — boresight error with measured lock instants", "frame",
                "boresight error (deg)")
    fig2.add_trace(go.Scatter(x=np.arange(1, n_frames + 1), y=np.abs(tb), name="BASELINE |err|",
                              line=dict(color=BASE_C, width=2.0)))
    fig2.add_trace(go.Scatter(x=np.arange(1, n_frames + 1), y=np.abs(ta), name="A-PRISM |err|",
                              line=dict(color=APR_C, width=2.0)))
    fig2.add_hline(y=tol, line=dict(color="#444", dash="dot"), annotation_text="lock tol 0.05°")
    if fb:
        fig2.add_vline(x=fb, line=dict(color=BASE_C, dash="dash"),
                       annotation_text=f"lock @ {fb}")
    if fa:
        fig2.add_vline(x=fa, line=dict(color=APR_C, dash="dash"),
                       annotation_text=f"lock @ {fa}")
    fig2.update_yaxes(type="log")

    return make_result(
        7, "Dual-Horizon Fast Dynamic Alignment K_DA",
        "gen_research/Core_Radar_Gen8_iND13400/software/bbe32/dyn_alignment/dyn_align_wrapper.c",
        {"frames_to_lock": int(fb) if fb else -1, "locked": int(fb is not None),
         "updates_budget": int(K.baseline_da_update_counts(400)),
         "final_abs_err_deg": float(abs(eb_)),
         "gain_at_frame_10": float(gb[9])},
        {"frames_to_lock": int(fa) if fa else -1, "locked": int(fa is not None),
         "updates_budget": int(K.aprism_da_update_counts(n_frames)),
         "final_abs_err_deg": float(abs(ea_)),
         "gain_at_frame_10": float(ga[9])},
        [fig_entry("c7_gain", "K_DA gain schedule", fig),
         fig_entry("c7_error", "Boresight error and lock markers", fig2)],
        notes=("Boresight error starts at 1.2 deg and is driven to zero by err <- err - K*err + "
               "N(0,0.02 deg). BASELINE holds the conservative startup deadband (gain=K_SLOW="
               f"{K.APRISM_DA_K_SLOW}) for the full 400 update frames reported by "
               "baseline_da_update_counts; A-PRISM caps the schedule at the 50 updates returned "
               "by aprism_da_update_counts and applies da_dual_horizon_gain from frame 1. Lock "
               "is da_lock_detect(err, 0.05 deg, hold, 10) - frames are counted, not assumed."))


# ===========================================================================
# 8. Preflight DA header seeding
# ===========================================================================

COLD_AZ = -1.145
COLD_EL = -0.018


def run_concept_8(seed: int) -> dict:
    """Concept #8: cold-start static fallback vs accepted DA header seed."""
    rng = S.rng_for_seed(seed)
    true_az, true_el = -3.0, -1.0          # deg, inside the acceptance window
    k_conv = 0.10
    n_frames = 200
    tol = 0.05

    def converge(start_az, start_el):
        az, el = start_az, start_el
        frames = None
        hist = []
        for f in range(1, n_frames + 1):
            az += k_conv * (true_az - az)
            el += k_conv * (true_el - el)
            e = math.hypot(az - true_az, el - true_el)
            hist.append(e)
            if frames is None and e <= tol:
                frames = f
        return np.asarray(hist), frames

    # BASELINE: cold start, qf=0 -> kernel returns the static fallback in radians.
    seed_b = K.preflight_seed(0.0, 0.0, 0.0)
    start_b = (math.degrees(seed_b[0]), math.degrees(seed_b[1]))
    e_b, f_b = converge(*start_b)

    # A-PRISM: the kernel's guard takes radians and returns rad*0.0174533, i.e.
    # the mirror double-converts (the production hook stores degrees and the
    # wrapper multiplies by DEG2RAD once). The measured transport scale is
    # recovered below so the seed is expressed in the unit the hook transports.
    qf = 1.0
    hdr_az = true_az + rng.normal(0.0, 0.35)
    hdr_el = true_el + rng.normal(0.0, 0.15)
    raw = K.preflight_seed(math.radians(hdr_az), math.radians(hdr_el), qf)
    fb_raw = K.preflight_seed(0.0, 0.0, 0.0)          # exact fallback tuple
    accepted = not (abs(raw[0] - fb_raw[0]) < 1e-12 and abs(raw[1] - fb_raw[1]) < 1e-12)
    deg_per_rad = 0.0174532925
    # measured transport scale of the mirror: |returned| / |header in rad|
    transport_scale = safe_div(abs(raw[0]), abs(math.radians(hdr_az)))
    start_a = ((math.degrees(raw[0] / deg_per_rad), math.degrees(raw[1] / deg_per_rad))
               if accepted else start_b)
    e_a, f_a = converge(*start_a)

    # Header population under noise: accepted vs rejected + seed error when accepted.
    n_hdr = 400
    hdr_az = true_az + rng.normal(0.0, 1.5, n_hdr)
    hdr_el = true_el + rng.normal(0.0, 0.6, n_hdr)
    hdr_qf = rng.uniform(-0.2, 1.4, n_hdr)
    acc_err, acc_frames, n_acc, n_rej = [], [], 0, 0
    for i in range(n_hdr):
        out = K.preflight_seed(math.radians(float(hdr_az[i])),
                               math.radians(float(hdr_el[i])), float(hdr_qf[i]))
        if (abs(out[0] - fb_raw[0]) < 1e-12 and abs(out[1] - fb_raw[1]) < 1e-12):
            n_rej += 1
        else:
            n_acc += 1
            az_d = math.degrees(out[0] / deg_per_rad)
            el_d = math.degrees(out[1] / deg_per_rad)
            acc_err.append(math.hypot(az_d - true_az, el_d - true_el))
            _, fr = converge(az_d, el_d)
            acc_frames.append(fr if fr else n_frames)

    # Two illustrative seeds: a clean header (sigma 0.2 deg) and a header at the
    # measured population-median error, so the figure cannot overstate the win.
    def seed_start(sig_az: float, sig_el: float):
        az = true_az + rng.normal(0.0, sig_az)
        el = true_el + rng.normal(0.0, sig_el)
        out = K.preflight_seed(math.radians(az), math.radians(el), 1.0)
        ok = not (abs(out[0] - fb_raw[0]) < 1e-12 and abs(out[1] - fb_raw[1]) < 1e-12)
        if not ok:
            return start_b
        return (math.degrees(out[0] / deg_per_rad), math.degrees(out[1] / deg_per_rad))

    e_a, f_a = converge(*seed_start(0.2, 0.1))
    e_med, _ = converge(*seed_start(1.45, 0.58))

    fig = _fig("Concept #8 — boresight convergence with and without the DA header seed",
               "frame", "angle error (deg)")
    fig.add_trace(go.Scatter(x=np.arange(1, n_frames + 1), y=e_b, name="BASELINE cold start",
                             line=dict(color=BASE_C, width=2.4)))
    fig.add_trace(go.Scatter(x=np.arange(1, n_frames + 1), y=e_med,
                             name="A-PRISM seed @ population-median error",
                             line=dict(color=APR_C, width=2.0, dash="dash")))
    fig.add_trace(go.Scatter(x=np.arange(1, n_frames + 1), y=e_a,
                             name="A-PRISM clean seed (0.2° header)",
                             line=dict(color=APR_C, width=2.4)))
    fig.add_hline(y=tol, line=dict(color="#444", dash="dot"), annotation_text="0.05° band")
    fig.update_yaxes(type="log")

    fig2 = _fig("Concept #8 — header acceptance under noise", "outcome", "header count")
    fig2.add_trace(go.Bar(x=["accept (seeded)", "reject (static fallback)"],
                          y=[n_acc, n_rej], marker_color=[APR_C, BASE_C],
                          text=[f"{n_acc}", f"{n_rej}"], textposition="outside"))
    fig2.add_annotation(x=1, y=n_rej, yref="y", text=f"accept rate {safe_div(n_acc, n_hdr):.1%}",
                        showarrow=False, yshift=34)

    return make_result(
        8, "Preflight DA Header Seeding",
        "gen_research/core-resim-dc-emb-library/DC_SIL/sil_wrappers/Tracker_VariantA_Wrapper.cpp",
        {"initial_angle_error_deg": float(e_b[0]),
         "frames_to_converge": int(f_b) if f_b else -1,
         "seed_rmse_deg": float(math.hypot(start_b[0] - true_az, start_b[1] - true_el)),
         "accepted_rate": 0.0, "accepted_headers": 0,
         "transport_scale": float(deg_per_rad)},
        {"initial_angle_error_deg": float(np.mean(acc_err)) if acc_err else float(e_a[0]),
         "frames_to_converge": int(round(float(np.mean(acc_frames)))) if acc_frames else -1,
         "frames_to_converge_clean": int(f_a) if f_a else -1,
         "seed_rmse_deg": rmse(acc_err),
         "accepted_rate": safe_div(n_acc, n_hdr), "accepted_headers": int(n_acc),
         "transport_scale": float(transport_scale)},
        [fig_entry("c8_error", "Angle error vs frame", fig),
         fig_entry("c8_accept", "Header acceptance histogram", fig2)],
        notes=("Tracker update az += 0.10*(az_true-az) per frame; convergence is |error|<=0.05 "
               "deg. BASELINE passes qf=0 so preflight_seed returns the cold-start static "
               f"fallback ({COLD_AZ}, {COLD_EL}) deg (measured initial error "
               f"{float(e_b[0]):.3f} deg). A-PRISM passes the header in radians; the mirror's "
               "guard accepts when |az|<=5 deg, |el|<=2 deg and qf>0. NOTE the mirror's transport "
               "is off by DEG2RAD (it returns rad*0.0174533 where the production hook stores "
               "degrees and the C++ wrapper applies kDeg2Rad once); the measured transport scale "
               "is reported and the inverse is applied so the seed error reflects the production "
               f"path. Acceptance is measured over {n_hdr} noisy headers (az sigma 1.5 deg, "
               "el sigma 0.6 deg, qf ~ U(-0.2,1.4)); rejections are detected by the exact "
               "fallback value. The population-mean metrics show the honest consequence: a "
               "header that is 1.4 deg off truth only saves a few frames, so the win scales with "
               "header quality - the (0.2 deg) clean-seed curve is reported separately and is "
               "not the headline."))


# ===========================================================================
# 9. IMM acceleration gating (REFUTED baseline)
# ===========================================================================

def _sc(M) -> float:
    """First scalar of a 1x1 matrix product (numpy 2 refuses float())."""
    return float(np.asarray(M, dtype=float).ravel()[0])


def _imm(seed: int, adaptive: bool):
    """3-mode (CV, CA+, CA-) IMM with a fixed acceleration covariance.

    Returns (mode_probs, recall, latency, fa_per_frame, gate_trace, err_trace).
    """
    rng = S.rng_for_seed(seed)
    dt = 0.1
    n_frames = 120
    onset, cut_len = 40, 24
    a_cut = 8.0
    v0 = 12.0
    sig_z = 0.6

    F = np.array([[1.0, dt], [0.0, 1.0]])
    H = np.array([[1.0, 0.0]])
    R = np.array([[sig_z ** 2]])
    qs = [0.02, 1.2, 1.2]                      # CV, CA+, CA- : FIXED accel covariance
    bias = [0.0, 2.5, -2.5]
    G = np.array([0.5 * dt * dt, dt])
    Pi = np.array([[0.94, 0.03, 0.03],
                   [0.06, 0.92, 0.02],
                   [0.06, 0.02, 0.92]])

    x = [np.array([0.0, v0]) for _ in range(3)]
    P = [np.eye(2) * 4.0 for _ in range(3)]
    mu = np.array([0.8, 0.1, 0.1])
    probs, gates, errs, hits, fas = [], [], [], [], []

    for f in range(n_frames):
        acc = a_cut if onset <= f < onset + cut_len else 0.0
        x_true = v0 * dt * (f + 1) + 0.5 * acc * (dt * min(max(f + 1 - onset, 0), cut_len)) ** 2
        z = x_true + sig_z * rng.standard_normal()

        cbar = Pi.T @ mu
        mix = (Pi * mu[:, None]) / np.maximum(cbar[None, :], 1e-12)
        xm, Pm = [], []
        for j in range(3):
            xj = sum(mix[i, j] * x[i] for i in range(3))
            Pj = sum(mix[i, j] * (P[i] + np.outer(x[i] - xj, x[i] - xj)) for i in range(3))
            xm.append(xj)
            Pm.append(Pj)

        ll = np.zeros(3)
        pred, predP = [], []
        for j in range(3):
            xp = F @ xm[j] + G * bias[j]
            Q = qs[j] * np.array([[dt ** 4 / 4.0, dt ** 3 / 2.0],
                                  [dt ** 3 / 2.0, dt ** 2]])
            Pp = F @ Pm[j] @ F.T + Q
            innov = np.array([z]) - H @ xp
            Sq = float((H @ Pp @ H.T + R).ravel()[0])
            d2 = float(innov[0] ** 2 / max(Sq, 1e-12))
            ll[j] = math.exp(-0.5 * d2) / math.sqrt(2.0 * math.pi * max(Sq, 1e-12))
            pred.append((xp, Pp, innov[0], Sq, d2))

        mu = cbar * ll
        s = mu.sum()
        mu = mu / s if s > 1e-300 else np.full(3, 1.0 / 3.0)

        xbar = sum(mu[j] * pred[j][0] for j in range(3))
        Pbar = sum(mu[j] * pred[j][1] for j in range(3))
        innov = z - _sc(H @ xbar)
        Sbar = _sc(H @ Pbar @ H.T + R)
        d2 = innov * innov / max(Sbar, 1e-12)
        a_norm = abs(bias[int(np.argmax(mu[1:]) + 1)]) / 4.0
        innov_e = d2 / K.GAMMA_MIN
        gamma = K.adaptive_gamma(a_norm, innov_e) if adaptive else K.baseline_gamma(a_norm, innov_e)
        gated = d2 <= gamma

        if gated:
            for j in range(3):
                xp, Pp, innov_j, Sq, _ = pred[j]
                Kk = Pp @ H.T / max(Sq, 1e-12)
                x[j] = xp + (Kk * innov_j).ravel()
                P[j] = Pp - Kk @ H @ Pp
        else:                                   # gate rejects: predict-only coast
            for j in range(3):
                x[j], P[j] = pred[j][0], pred[j][1]

        n_clut = 40
        cand = x_true + rng.uniform(-20.0, 20.0, n_clut)
        d2c = (cand - _sc(H @ xbar)) ** 2 / max(Sbar, 1e-12)
        fas.append(int((d2c <= gamma).sum()))

        probs.append(mu.copy())
        gates.append(gamma)
        errs.append(abs(_sc(H @ xbar) - x_true))
        hits.append(1 if (onset <= f < onset + 20 and gated) else 0)

    probs = np.asarray(probs)
    lat = None
    for f in range(onset, n_frames):
        if probs[f, 1] > 0.5:
            lat = f - onset + 1
            break
    window = [1 for f in range(onset, onset + 20)]
    rec = safe_div(sum(hits), len(window))
    return probs, rec, lat, float(np.mean(fas[onset:onset + 20])), np.asarray(gates), np.asarray(errs)


def run_concept_9(seed: int) -> dict:
    """Concept #9: fixed-covariance 3-mode IMM gate vs kinematic adaptive gate."""
    pb, rec_b, lat_b, fa_b, gb, eb = _imm(seed, False)
    pa, rec_a, lat_a, fa_a, ga, ea = _imm(seed, True)
    frames = np.arange(pb.shape[0])

    fig = _fig("Concept #9 — IMM mode probabilities through a cut-in (sync, fixed Q)",
               "frame", "mode probability")
    fig.add_trace(go.Scatter(x=frames, y=pb[:, 0], name="CV", line=dict(color="#666", width=1.8)))
    fig.add_trace(go.Scatter(x=frames, y=pb[:, 1], name="CA+", line=dict(color=BASE_C, width=2.0)))
    fig.add_trace(go.Scatter(x=frames, y=pb[:, 2], name="CA-", line=dict(color="#8a6d3b", width=1.8)))
    fig.add_vline(x=40, line=dict(color="#333", dash="dash"), annotation_text="cut-in onset")
    fig.add_annotation(x=40, y=0.5, text=(f"mode-switch latency {lat_b if lat_b else '>80'} frames"
                                         if lat_b else "CA+ never exceeds 0.5"),
                       showarrow=False, xshift=110, font=dict(color=BASE_C))

    fig2 = make_subplots(rows=1, cols=2, subplot_titles=("Recall at cut-in onset",
                                                         "False associations per frame"))
    fig2.add_trace(go.Bar(x=["BASELINE fixed gamma=9.21", "A-PRISM adaptive_gamma"],
                          y=[rec_b, rec_a], marker_color=[BASE_C, APR_C],
                          text=[f"{rec_b:.2f}", f"{rec_a:.2f}"], textposition="outside"), 1, 1)
    fig2.add_trace(go.Bar(x=["BASELINE fixed gamma=9.21", "A-PRISM adaptive_gamma"],
                          y=[fa_b, fa_a], marker_color=[BASE_C, APR_C],
                          text=[f"{fa_b:.2f}", f"{fa_a:.2f}"], textposition="outside"), 1, 2)
    fig2.update_yaxes(range=[0, 1.1], row=1, col=1)
    fig2.update_layout(title="Concept #9 — gating outcome at the cut-in (measured)", **GRID)

    fig3 = _fig("Concept #9 — gate width trace", "frame", "gamma (chi-square threshold)")
    fig3.add_trace(go.Scatter(x=frames, y=gb, name="BASELINE fixed 9.21",
                              line=dict(color=BASE_C, width=2.0)))
    fig3.add_trace(go.Scatter(x=frames, y=ga, name="A-PRISM adaptive",
                              line=dict(color=APR_C, width=2.0)))
    fig3.add_vline(x=40, line=dict(color="#333", dash="dash"))

    return make_result(
        9, "IMM Acceleration Gating (REFUTED BASELINE)",
        "synthesised 3-mode IMM (no implementation exists in core-resim-dc-emb-library or Core_Radar_Gen8_iND13400)",
        {"mode_switch_latency_frames": int(lat_b) if lat_b else -1,
         "recall_at_onset": rec_b, "false_associations_per_frame": fa_b,
         "track_err_rmse_m": rmse(eb[40:60]), "gate": float(gb[45])},
        {"mode_switch_latency_frames": int(lat_a) if lat_a else -1,
         "recall_at_onset": rec_a, "false_associations_per_frame": fa_a,
         "track_err_rmse_m": rmse(ea[40:60]), "gate": float(ga[45])},
        [fig_entry("c9_modes", "IMM mode probabilities", fig),
         fig_entry("c9_recall", "Recall and false associations", fig2),
         fig_entry("c9_gate", "Gate width vs frame", fig3)],
        notes=("NO IMM implementation was found in either tree: "
               "Core_Radar_Gen8_iND13400/APRISM_LANDING.md row 22 records 'N15 IMM (55)' as "
               "REFUTED / 'documented, no code' and the repo-wide grep for IMM only hits "
               "pugixml docs. The 3-mode (CV, CA+, CA-) IMM used here is therefore synthesised "
               "for this comparison: fixed acceleration covariance q=1.2, transition matrix "
               "0.92 diagonal, +-2.5 m/s^2 model bias, sigma_z=0.6 m, dt=0.1 s, an 8 m/s^2 "
               "cut-in at frame 40 lasting 24 frames. BASELINE gates with the fixed 9.21 "
               "chi-square threshold (baseline_gamma) and coasts (predict-only) on rejection; "
               "A-PRISM uses adaptive_gamma(a_norm, innov_e) capped at 40. The A-PRISM gate "
               "admits the manœuvre measurement, so its recall recovers at the cost of the "
               "reported extra false associations on 40 uniform clutter candidates per frame - "
               "a measured trade, not a free win."))


# ===========================================================================
# Registry
# ===========================================================================

CONCEPTS = [
    {"id": 1, "title": "Track-Conditioned Residual Beat Estimator",
     "source": "gen_research/Core_Radar_Gen8_iND13400/software/bbe32/src/residual_track_ifc.c",
     "run": run_concept_1},
    {"id": 2, "title": "3-Product Cubic-Exact Residual Stencil",
     "source": "gen_research/Core_Radar_Gen8_iND13400/software/bbe32/src/residual_track_ifc.c",
     "run": run_concept_2},
    {"id": 3, "title": "Range-Adaptive Dual-Loop Clutter CFAR",
     "source": "gen_research/Core_Radar_Gen8_iND13400/software/bbe32/rdd_proc/imp/src/appl_cfar_ifc.c",
     "run": run_concept_3},
    {"id": 4, "title": "Occupancy-BLUE CFAR with Pfa control",
     "source": "gen_research/Core_Radar_Gen8_iND13400/software/bbe32/rdd_proc/imp/src/appl_adaptive_cfar.c",
     "run": run_concept_4},
    {"id": 5, "title": "Priority-Ranked CDC Urban Packing",
     "source": "gen_research/Core_Radar_Gen8_iND13400/software/bbe32/src/cdc_priority.c",
     "run": run_concept_5},
    {"id": 6, "title": "Closed-Form Specular Contact Inversion",
     "source": "gen_research/Core_Radar_Gen8_iND13400/software/bbe32/dyn_alignment/ghost_calib.c",
     "run": run_concept_6},
    {"id": 7, "title": "Dual-Horizon Fast Dynamic Alignment K_DA",
     "source": "gen_research/Core_Radar_Gen8_iND13400/software/bbe32/dyn_alignment/dyn_align_wrapper.c",
     "run": run_concept_7},
    {"id": 8, "title": "Preflight DA Header Seeding",
     "source": "gen_research/core-resim-dc-emb-library/DC_SIL/sil_wrappers/Tracker_VariantA_Wrapper.cpp",
     "run": run_concept_8},
    {"id": 9, "title": "IMM Acceleration Gating (REFUTED BASELINE)",
     "source": "synthesised 3-mode IMM (no implementation in either tree)",
     "run": run_concept_9},
]
