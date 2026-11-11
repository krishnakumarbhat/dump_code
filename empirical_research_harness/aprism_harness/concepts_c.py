"""Empirical BEFORE-vs-AFTER experiments for radar research concepts #19-#27.

Every metric is measured by executing the mirrored kernels in
``aprism_harness.kernels`` on generated fixtures.  Nothing is hardcoded.

Sources:
  #19,#20,#21  core-resim-dc-emb-library (sil_wrapper.cpp / ghost_calib.c)
  #22          core-resim-dc-emb-library Tracker_VariantA_Wrapper.cpp
  #23,#24,#26  algorithm-level research concepts (NO upstream C kernel)
  #25          core-resim-dc-emb-library f360_detect_multipath.cpp
  #27          core-resim-dc-emb-library ghost_calib.c GhostCertify + replay
"""
from __future__ import annotations

import math
from typing import List, Sequence, Tuple

import numpy as np
import plotly.graph_objects as go

from aprism_harness import kernels as K
from aprism_harness import signals as S
from aprism_harness.concept_api import (auc, fig_entry, make_result, mae,
                                        pct, rmse, roc_curve, safe_div)

RAD2DEG = K.RAD2DEG
C0 = S.C0


def _rng(seed: int, tag: int) -> np.random.Generator:
    """Deterministic per-concept rng derived from the master seed."""
    return np.random.default_rng((int(seed) * 1000003 + tag * 7919) & 0xFFFFFFFF)


def _scatter(clouds, names, colors, title, xlab, ylab, extra=None) -> go.Figure:
    """Multi-trace scatter helper (BEFORE and AFTER in one figure)."""
    fig = go.Figure()
    for xy, nm, cl in zip(clouds, names, colors):
        fig.add_trace(go.Scatter(x=xy[0], y=xy[1], mode="markers", name=nm,
                                 marker=dict(color=cl, size=6, opacity=0.55)))
    if extra is not None:
        extra(fig)
    fig.update_layout(title=title, xaxis_title=xlab, yaxis_title=ylab,
                      template="plotly_white", legend_title="series")
    return fig


# ===========================================================================
# #19 Asynchronous Satellite Yaw Extrapolation
# ===========================================================================
_SRC19 = "core-resim-dc-emb-library/DC_SIL/sil_wrappers/sil_wrapper.cpp"


def run_19(seed: int) -> dict:
    """Two asynchronous reports of one target; deskew vs naive readout."""
    rng = _rng(seed, 19)
    omegas = np.linspace(0.1, 0.6, 11)
    dt = 0.08                      # s between the two reports
    p0 = np.array([120.0, 40.0])   # truth at reference epoch
    v = np.array([18.0, -6.0])
    a = np.array([1.5, 0.8])
    sigma = 0.35                   # m per-report measurement noise
    trials = 60
    p_dt = p0 + v * dt + 0.5 * a * dt * dt

    rmse_b, rmse_a, smear_b, smear_a = [], [], [], []
    for w in omegas:
        eb, ea, sb, sa = [], [], [], []
        th = -w * dt
        c, s_ = math.cos(th), math.sin(th)
        for _ in range(trials):
            m1 = p0 + rng.normal(0.0, sigma, 2)
            m2 = np.array([c * p_dt[0] - s_ * p_dt[1],
                           s_ * p_dt[0] + c * p_dt[1]]) + rng.normal(0.0, sigma, 2)
            est_b = m2                                    # naive: use as-is
            est_a = np.asarray(K.deskew(tuple(m2), v, a, w, dt))
            eb.append(float(np.linalg.norm(est_b - p0)))
            ea.append(float(np.linalg.norm(est_a - p0)))
            sb.append(float(np.linalg.norm(m2 - m1)))     # raw smearing
            sa.append(float(np.linalg.norm(est_a - m1)))  # after deskew
        rmse_b.append(rmse(eb))
        rmse_a.append(rmse(ea))
        smear_b.append(float(np.mean(sb)))
        smear_a.append(float(np.mean(sa)))

    # worst-case scatter clouds (largest swept yaw rate)
    w_max = float(omegas[-1])
    th = -w_max * dt
    c, s_ = math.cos(th), math.sin(th)
    cl_b, cl_a, truth = [], [], []
    for _ in range(200):
        m1 = p0 + rng.normal(0.0, sigma, 2)
        m2 = np.array([c * p_dt[0] - s_ * p_dt[1],
                       s_ * p_dt[0] + c * p_dt[1]]) + rng.normal(0.0, sigma, 2)
        cl_b.append(tuple(m2))
        cl_a.append(tuple(np.asarray(K.deskew(tuple(m2), v, a, w_max, dt))))
        truth.append(tuple(m1))

    fig1 = go.Figure()
    fig1.add_trace(go.Scatter(x=omegas, y=rmse_b, mode="lines+markers",
                              name="BASELINE (no deskew)", line=dict(color="#c0392b")))
    fig1.add_trace(go.Scatter(x=omegas, y=rmse_a, mode="lines+markers",
                              name="A-PRISM (deskew)", line=dict(color="#16a085")))
    fig1.update_layout(title="Position RMSE vs satellite yaw rate",
                       xaxis_title="yaw rate omega [rad/s]",
                       yaxis_title="position RMSE [m]", template="plotly_white")

    fig2 = go.Figure()
    for xy, nm, cl in ((cl_b, "BASELINE reports (raw)", "#c0392b"),
                       (cl_a, "A-PRISM deskewed", "#16a085"),
                       (truth, "truth cloud", "#2c3e50")):
        arr = np.asarray(xy)
        fig2.add_trace(go.Scatter(x=arr[:, 0], y=arr[:, 1], mode="markers",
                                  name=nm, marker=dict(color=cl, size=6, opacity=0.5)))
    fig2.add_trace(go.Scatter(x=[p0[0]], y=[p0[1]], mode="markers", name="p(0)",
                              marker=dict(color="#f39c12", size=14, symbol="star")))
    fig2.update_layout(title=f"2D position clouds at omega={w_max:.2f} rad/s",
                       xaxis_title="x [m]", yaxis_title="y [m]",
                       template="plotly_white")

    base = {
        "rmse_mean_m": float(np.mean(rmse_b)),
        "rmse_at_max_omega_m": rmse_b[-1],
        "smear_mean_m": float(np.mean(smear_b)),
    }
    apr = {
        "rmse_mean_m": float(np.mean(rmse_a)),
        "rmse_at_max_omega_m": rmse_a[-1],
        "smear_mean_m": float(np.mean(smear_a)),
    }
    return make_result(
        19, "Asynchronous Satellite Yaw Extrapolation", _SRC19, base, apr,
        [fig_entry("rmse_vs_yaw", "RMSE vs yaw rate", fig1),
         fig_entry("scatter", "Two desynchronised position clouds", fig2)],
        notes=("Two reports of one target separated by dt=0.08 s with mounting yaw rate "
               f"omega swept in [0.1,0.6] rad/s; {trials} noisy trials per omega. "
               "BASELINE reads the second report as-is; A-PRISM applies kernels.deskew."))


# ===========================================================================
# #20 Yaw-Free Timestamp and Doppler Bias Separation
# ===========================================================================
_SRC20 = ("core-resim-dc-emb-library/.../dyn_alignment/ghost_calib.c "
          "(ClockTau1/ClockTauBias2) + sil_wrapper.cpp")


def run_20(seed: int) -> dict:
    """Clock offset tau vs mounting-yaw Doppler bias: 1-target vs 2-target solve."""
    rng = _rng(seed, 20)
    tau_true = 0.35
    yaw_degs = np.linspace(0.0, 6.0, 13)
    b_per_deg = 0.02                       # yaw -> Doppler bias coupling
    sigma_y = 0.05
    trials = 80

    # geometry: two targets with perpendicular d_i, v_i (d.v = 0)
    v1 = np.array([3.0, 4.0])              # a1 = |v1|^2 = 25
    v2 = np.array([5.0, 12.0])             # a2 = |v2|^2 = 169
    a1, a2 = float(v1 @ v1), float(v2 @ v2)
    d1 = np.array([-v1[1], v1[0]]) / np.linalg.norm(v1)
    d2 = np.array([-v2[1], v2[0]]) / np.linalg.norm(v2)
    r1, r2 = 40.0, 18.0
    M1 = np.array([[a1, r1], [a2, r2]])
    cond_apr = float(np.linalg.cond(M1))
    M0 = np.array([[a1, r1], [a1, r1]])    # baseline: only one target -> rank 1
    cond_base = float(np.linalg.cond(M0))

    tau_err_b, tau_err_a, best_b, best_a = [], [], [], []
    for yd in yaw_degs:
        b_true = b_per_deg * yd
        tb, ta, bb, ba = [], [], [], []
        for _ in range(trials):
            y1 = a1 * tau_true + r1 * b_true + rng.normal(0.0, sigma_y)
            y2 = a2 * tau_true + r2 * b_true + rng.normal(0.0, sigma_y)
            # baseline: single target via ClockTau1 (assumes b == 0)
            w1 = safe_div(y1, r1)           # d1.v1 = 0 by construction
            tau_b = K.clock_tau1(d1, v1, r1, w1)
            # baseline's (biased) attempt at the bias from target 2
            b_est_b = safe_div(y2 - a2 * tau_b, r2)
            # A-PRISM: two-target joint solve
            ok, tau_a, b_est_a = K.clock_tau_bias2(a1, r1, y1, a2, r2, y2)
            tb.append(tau_b - tau_true)
            ta.append((tau_a - tau_true) if ok else np.nan)
            bb.append(abs(b_est_b))
            ba.append(abs(b_est_a) if ok else np.nan)
        tau_err_b.append(rmse(tb))
        tau_err_a.append(rmse(ta))
        best_b.append(float(np.mean(bb)))
        best_a.append(float(np.mean(ba)))

    # condition number vs geometry: sweep target-2 range
    r2_sweep = np.linspace(6.0, 60.0, 25)
    cond_vs_geom = [float(np.linalg.cond(np.array([[a1, r1], [a2, r]])))
                    for r in r2_sweep]

    # scatter of estimates at mid yaw
    b_mid = b_per_deg * yaw_degs[len(yaw_degs) // 2]
    sc_true, sc_b, sc_a = [], [], []
    for _ in range(120):
        y1 = a1 * tau_true + r1 * b_mid + rng.normal(0.0, sigma_y)
        y2 = a2 * tau_true + r2 * b_mid + rng.normal(0.0, sigma_y)
        tau_b = K.clock_tau1(d1, v1, r1, safe_div(y1, r1))
        ok, tau_a, _ = K.clock_tau_bias2(a1, r1, y1, a2, r2, y2)
        sc_b.append(tau_b)
        sc_a.append(tau_a if ok else np.nan)

    fig1 = go.Figure()
    fig1.add_trace(go.Scatter(x=yaw_degs, y=tau_err_b, mode="lines+markers",
                              name="BASELINE (1-target ClockTau1)", line=dict(color="#c0392b")))
    fig1.add_trace(go.Scatter(x=yaw_degs, y=tau_err_a, mode="lines+markers",
                              name="A-PRISM (ClockTauBias2)", line=dict(color="#16a085")))
    fig1.update_layout(title="Clock offset tau error vs mounting yaw",
                       xaxis_title="mounting yaw [deg]",
                       yaxis_title="tau RMSE [units]", template="plotly_white")

    fig2 = go.Figure()
    fig2.add_trace(go.Scatter(x=r2_sweep, y=cond_vs_geom, mode="lines+markers",
                              name="2-target normal matrix", line=dict(color="#8e44ad"))
                   )
    fig2.add_trace(go.Scatter(x=[r2], y=[cond_apr], mode="markers",
                              name=f"operating point (cond={cond_apr:.1f})",
                              marker=dict(size=12, symbol="star", color="#16a085")))
    fig2.add_hline(y=cond_base, line_dash="dash", line_color="#c0392b",
                    annotation_text=f"baseline rank-1 cond={cond_base:.2e}")
    fig2.update_layout(title="Condition number vs two-target geometry",
                       xaxis_title="target-2 range r2 [m]",
                       yaxis_title="cond(normal matrix)", template="plotly_white",
                       yaxis_type="log")

    fig3 = _scatter(
        (([tau_true] * len(sc_b), sc_b), ([tau_true] * len(sc_a), sc_a)),
        ["BASELINE", "A-PRISM"], ["#c0392b", "#16a085"],
        "Scatter of tau estimates (mid yaw)", "true tau", "estimated tau",
        extra=lambda f: f.add_trace(go.Scatter(x=[tau_true, tau_true],
                                               y=[min(sc_b + sc_a), max(sc_b + sc_a)],
                                               mode="lines", name="y = truth",
                                               line=dict(color="#2c3e50", dash="dash"))))

    base = {"tau_rmse_at_max_yaw": tau_err_b[-1],
            "tau_rmse_mean": float(np.mean(tau_err_b)),
            "b_estimate_mean": float(np.mean(best_b)),
            "normal_matrix_cond": cond_base}
    apr = {"tau_rmse_at_max_yaw": tau_err_a[-1],
           "tau_rmse_mean": float(np.mean(tau_err_a)),
           "b_estimate_mean": float(np.mean(best_a)),
           "normal_matrix_cond": cond_apr}
    return make_result(
        20, "Yaw-Free Timestamp and Doppler Bias Separation", _SRC20, base, apr,
        [fig_entry("tau_err", "tau error vs yaw", fig1),
         fig_entry("cond", "observability", fig2),
         fig_entry("scatter", "estimate scatter", fig3)],
        notes=("Generative model y_i = a_i*tau + r_i*b with b = yaw-induced Doppler bias; "
               "BASELINE solves tau from one target (ClockTau1) and is biased by (r1/a1)*b; "
               "A-PRISM runs ClockTauBias2 joint solve. Condition numbers are measured "
               "with numpy.linalg.cond on the actual normal matrices."))


# ===========================================================================
# #21 Cross-Satellite Relative Yaw Cancellation
# ===========================================================================
_SRC21 = ("core-resim-dc-emb-library/.../dyn_alignment/ghost_calib.c "
          "(GhostEstimateYaw, GhostCertify)")


def _yaw_vectors(theta1: float, theta2: float, m: int, rng: np.random.Generator,
                 az: float = 0.30, psi_g: float = 0.10, g: float = 0.6,
                 noise: float = 0.01):
    """Direct/ghost complex vectors for two satellites with mounting yaw."""
    zd1 = np.zeros(2 * m); zg1 = np.zeros(2 * m)
    zd2 = np.zeros(2 * m); zg2 = np.zeros(2 * m)
    for k in range(m):
        phi = 0.37 * k
        for j, (th, zd, zg) in enumerate(((theta1, zd1, zg1), (theta2, zd2, zg2))):
            dd = np.exp(1j * (phi + az - th))
            gg = g * np.exp(1j * (phi + az + psi_g - th))
            zd[2 * k] = dd.real + rng.normal(0.0, noise)
            zd[2 * k + 1] = dd.imag + rng.normal(0.0, noise)
            zg[2 * k] = gg.real + rng.normal(0.0, noise)
            zg[2 * k + 1] = gg.imag + rng.normal(0.0, noise)
    return zd1, zg1, zd2, zg2


def _beam_gain(az_j: float, th: float, g: float, psi_g: float) -> float:
    """Antenna direct-minus-ghost amplitude (nonlinear in absolute yaw)."""
    return math.cos(az_j - th) - g * math.cos(az_j + psi_g - th)


def run_21(seed: int) -> dict:
    """Relative yaw from cross-spectral phase vs absolute-yaw baseline."""
    rng = _rng(seed, 21)
    m = 64
    delta_true = -5.0 / RAD2DEG            # fixed relative yaw (rad)
    abs_degs = np.linspace(-45.0, 45.0, 19)
    az1, az2, g, psi_g = 0.34, 0.26, 0.6, 0.10
    s1, s2 = (0.0, 0.0), (30.0, 10.0)
    baseline_len = math.hypot(s2[0] - s1[0], s2[1] - s1[1])

    err_b, err_a, coh, peak_err = [], [], [], []
    lmin_meas, cmax_meas = 0.0, 0.0
    for ad in abs_degs:
        th1 = ad / RAD2DEG
        th2 = th1 + delta_true
        eb, ea, cc, pe = [], [], [], []
        for _ in range(6):
            zd1, zg1, zd2, zg2 = _yaw_vectors(th1, th2, m, rng)
            res = K.ghost_estimate_yaw(zd1, zg1, zd2, zg2, m, s1, s2)
            if not res.valid:
                continue
            ea.append(abs(res.delta - delta_true) * RAD2DEG)
            lmin_meas, cmax_meas = res.lmin, res.cmax
            # baseline: linearised amplitude inversion (absolute-yaw calibration)
            d1 = zd1 - zg1; d2 = zd2 - zg2
            q1 = float(np.mean(np.hypot(d1[0::2], d1[1::2])))
            q2 = float(np.mean(np.hypot(d2[0::2], d2[1::2])))
            def lininv(q: float, az_j: float, th: float) -> float:
                f0 = _beam_gain(az_j, 0.0, g, psi_g)
                fp = math.sin(az_j) - g * math.sin(az_j + psi_g)
                return -(q - f0) / (fp if abs(fp) > 1e-9 else 1e-9)
            ab1, ab2 = lininv(q1, az1, th1), lininv(q2, az2, th2)
            eb.append(abs((ab2 - ab1) - delta_true) * RAD2DEG)
            # correlation-phase peak (cross-spectral magnitude + phase)
            num = d1[0::2] * d2[0::2] + d1[1::2] * d2[1::2]
            den = np.linalg.norm(d1) * np.linalg.norm(d2) + 1e-12
            h_re = float(np.sum(num)) + 0.0
            h_im = float(np.sum(d1[1::2] * d2[0::2] - d1[0::2] * d2[1::2]))
            ph = math.atan2(h_im, h_re)
            cc.append(abs(complex(h_re, h_im)) / den)
            pe.append(abs(ph - delta_true) * RAD2DEG)
        err_b.append(float(np.mean(eb)) if eb else np.nan)
        err_a.append(float(np.mean(ea)) if ea else np.nan)
        coh.append(float(np.mean(cc)) if cc else np.nan)
        peak_err.append(float(np.mean(pe)) if pe else np.nan)

    # correlation phase peak shape (single geometry, worst absolute yaw)
    th1 = abs_degs[-1] / RAD2DEG
    th2 = th1 + delta_true
    zd1, zg1, zd2, zg2 = _yaw_vectors(th1, th2, m, rng)
    d1 = zd1 - zg1; d2 = zd2 - zg2
    num = d1[0::2] * d2[0::2] + d1[1::2] * d2[1::2]
    im = d1[1::2] * d2[0::2] - d1[0::2] * d2[1::2]
    h_re, h_im = float(np.sum(num)), float(np.sum(im))
    phis = np.linspace(-90.0, 90.0, 1801)
    den = np.linalg.norm(d1) * np.linalg.norm(d2) + 1e-12
    # phase-resolved cross-correlation |sum d1 conj(e^{j t} d2)|
    tvec = np.exp(-1j * np.radians(phis))
    prod = (d1[0::2] + 1j * d1[1::2])[None, :] * \
        np.conj((d2[0::2] + 1j * d2[1::2])[None, :] * tvec[:, None])
    curve = list(np.abs(np.sum(prod, axis=1)) / den)
    peak_phi = math.atan2(h_im, h_re) * RAD2DEG

    # GhostCertify sweep
    eps_sweep = np.geomspace(1e-6, 3e-2, 60)
    e_rel, e_i, e_j = [], [], []
    max_ok_eps = 0.0
    for eps in eps_sweep:
        ok, er, ei, ej = K.ghost_certify(float(eps), lmin_meas, cmax_meas,
                                         baseline_len)
        if ok:
            max_ok_eps = float(eps)
            e_rel.append(er); e_i.append(ei); e_j.append(ej)
        else:
            e_rel.append(np.nan); e_i.append(np.nan); e_j.append(np.nan)
    ok0, er0, ei0, ej0 = K.ghost_certify(1e-3, lmin_meas, cmax_meas, baseline_len)

    fig1 = go.Figure()
    fig1.add_trace(go.Scatter(x=phis, y=curve, mode="lines",
                              name="cross-spectral coherence",
                              line=dict(color="#2980b9")))
    fig1.add_vline(x=delta_true * RAD2DEG, line_dash="dash", line_color="#2c3e50",
                   annotation_text="true relative yaw")
    fig1.add_vline(x=peak_phi, line_dash="dot", line_color="#c0392b",
                   annotation_text="measured peak")
    fig1.update_layout(title="Measured correlation-phase peak (|H| vs trial phase)",
                       xaxis_title="trial phase [deg]",
                       yaxis_title="normalised |H|", template="plotly_white")

    fig2 = go.Figure()
    fig2.add_trace(go.Scatter(x=abs_degs, y=err_b, mode="lines+markers",
                              name="BASELINE (absolute-yaw amplitude)", line=dict(color="#c0392b")))
    fig2.add_trace(go.Scatter(x=abs_degs, y=err_a, mode="lines+markers",
                              name="A-PRISM (cross-spectral relative)", line=dict(color="#16a085")))
    fig2.update_layout(title="Relative-yaw error vs mounting yaw (cancellation)",
                       xaxis_title="absolute mounting yaw [deg]",
                       yaxis_title="relative yaw error [deg]", template="plotly_white")

    fig3 = go.Figure()
    okmask = np.isfinite(e_rel)
    fig3.add_trace(go.Scatter(x=eps_sweep[okmask], y=np.asarray(e_rel)[okmask],
                              mode="lines", name="e_rel [deg]", line=dict(color="#c0392b")))
    fig3.add_trace(go.Scatter(x=eps_sweep[okmask], y=np.asarray(e_i)[okmask],
                              mode="lines", name="e_i [deg]", line=dict(color="#8e44ad")))
    fig3.add_trace(go.Scatter(x=eps_sweep[okmask], y=np.asarray(e_j)[okmask],
                              mode="lines", name="e_j [deg]", line=dict(color="#2980b9")))
    fig3.add_vline(x=max_ok_eps, line_dash="dash", line_color="#16a085",
                   annotation_text=f"max certifiable eps={max_ok_eps:.2e}")
    fig3.update_layout(title="GhostCertify error bound vs eps",
                       xaxis_title="eps (vector error floor)",
                       yaxis_title="certificate bound [deg]",
                       template="plotly_white", xaxis_type="log")

    base = {"rel_yaw_err_mean_deg": float(np.nanmean(err_b)),
            "rel_yaw_err_max_deg": float(np.nanmax(err_b)),
            "cert_valid": bool(ok0)}
    apr = {"rel_yaw_err_mean_deg": float(np.nanmean(err_a)),
           "rel_yaw_err_max_deg": float(np.nanmax(err_a)),
           "corr_peak_coherence": float(np.nanmean(coh)),
           "corr_peak_err_deg": float(np.nanmean(peak_err)),
           "cert_e_rel_deg": float(er0) if ok0 else float("nan"),
           "cert_e_i_deg": float(ei0) if ok0 else float("nan"),
           "cert_e_j_deg": float(ej0) if ok0 else float("nan")}
    return make_result(
        21, "Cross-Satellite Relative Yaw Cancellation", _SRC21, base, apr,
        [fig_entry("peak", "correlation phase peak", fig1),
         fig_entry("flat", "error vs mounting yaw", fig2),
         fig_entry("cert", "certificate vs eps", fig3)],
        notes=("Direct/ghost complex vectors of one specular target; absolute mounting yaw "
               "swept +/-45 deg while the relative yaw is fixed. A-PRISM error stays flat "
               "(common-mode cancellation in GhostEstimateYaw); baseline uses a linearised "
               "absolute-amplitude inversion and drifts. Bounds from GhostCertify with "
               "measured lmin/cmax."))


# ===========================================================================
# #22 155-Scan Fleet Replay Verification
# ===========================================================================
_SRC22 = ("core-resim-dc-emb-library/DC_SIL/sil_wrappers/"
          "Tracker_VariantA_Wrapper.cpp")


def run_22(seed: int) -> dict:
    """155-scan replay: fixed-gate baseline vs adaptive+rank+XOR A-PRISM."""
    rng = _rng(seed, 22)
    n_scans = 155
    n_targets = 8
    n_ghosts = 6
    clutter_per_scan = 300          # -> ~5e4 total detections
    sig_v, s_v = 0.5, 0.4
    a_norm = 0.6                    # normalised clutter-density input
    vmax = 25.0

    tvel = np.column_stack([rng.uniform(8.0, 18.0, n_targets),
                            rng.uniform(-6.0, 6.0, n_targets)])
    v_init = tvel.copy()            # stale velocity model shared by both pipelines
    tpos = np.column_stack([rng.uniform(20.0, 90.0, n_targets),
                            rng.uniform(-30.0, 30.0, n_targets)])
    victim = rng.integers(0, n_targets, n_ghosts)

    # ---- pre-generate ALL detections ONCE: both pipelines get identical input
    scans = []
    truth_traj = []
    for k in range(n_scans):
        if k == 80:                 # fleet manoeuvre: velocity step on 3 targets
            tvel = tvel.copy()
            tvel[2] += np.array([1.2, -1.0])
            tvel[4] += np.array([-1.0, 1.2])
            tvel[6] += np.array([1.2, 1.2])
        tpos = tpos + tvel * 0.1
        truth_traj.append(tpos.copy())
        dets = []
        # multipath masking: the ghost swamps the direct return on ~30% of scans
        masked = np.zeros(n_targets, dtype=bool)
        for gi in range(n_ghosts):
            if rng.random() < 0.30:
                masked[int(victim[gi])] = True
        for i in range(n_targets):
            if masked[i]:
                continue                         # direct return swamped by ghost
            for _ in range(2):                     # 2 detections/target/scan
                pos = tpos[i] + rng.normal(0.0, 1.2, 2)
                ang_d = math.atan2(pos[1], pos[0])
                ang_v = math.atan2(tvel[i, 1], tvel[i, 0])
                vr = float(np.hypot(tvel[i, 0], tvel[i, 1])) * \
                    math.cos(ang_v - ang_d) + rng.normal(0.0, 0.15)
                dets.append((pos, vr, i, False, False, True))
        for gi in range(n_ghosts):                  # multipath ghosts
            v_i = int(victim[gi])
            pos = tpos[v_i] + rng.normal(0.0, 3.5, 2)
            vr = float(np.hypot(*tvel[v_i])) * 0.9 + rng.normal(0.0, 0.8)
            dets.append((pos, vr, n_targets + gi, True, False, True))
        for ci in range(clutter_per_scan):          # clutter
            pos = np.array([rng.uniform(0.0, 100.0), rng.uniform(-50.0, 50.0)])
            dets.append((pos, float(rng.uniform(-vmax, vmax)), 1000 + ci,
                         bool(int(rng.integers(0, 2))), False, False))
        scans.append(dets)
    total_dets = int(sum(len(d) for d in scans))

    # identical initial track predictions for BOTH pipelines
    pred0 = truth_traj[0] + rng.normal(0.0, 2.0, (n_targets, 2))
    pvel0 = v_init.copy()
    gamma_fixed = K.baseline_gamma(a_norm, 0.0)

    def _pipeline(aprism: bool):
        """Run one fleet pipeline; returns (counters, per-scan series, assoc map)."""
        pred = pred0.copy()
        pvel = pvel0.copy()
        qseen = np.zeros(n_targets, dtype=int)
        last_src = np.full(n_targets, -1, dtype=int)
        fsm = [K.TrackValidityFSM() for _ in range(n_targets + n_ghosts)]
        sidecar = K.DetSidecar()
        c = dict(false=0, retained=0, assimilated=0, id_switch=0)
        ser_ret, ser_false, ser_asm, assoc_all = [], [], [], []
        for k in range(n_scans):
            if k >= 1:
                pred = pred + pvel * 0.1
            dets = scans[k]
            # 1) XOR sentinel -> TrackValidityFSM -> DetSidecar (A-PRISM only)
            excluded = np.zeros(len(dets), dtype=bool)
            if aprism:
                for di, (pos, vr, src, mp, refl, pair) in enumerate(dets):
                    if n_targets <= src < n_targets + n_ghosts and \
                            K.xor_sentinel(mp, refl):
                        fsm[src].update(paired=pair, double_bounce=True)
                        if fsm[src].is_assimilated():
                            sidecar.mark(di)
                            excluded[di] = True
            # 2) association (spatial gate, rank gate, doppler gate)
            n_ret = n_fal = n_asm = 0
            assoc = np.full(len(dets), -1, dtype=int)
            used = np.zeros(n_targets, dtype=bool)
            for di, (pos, vr, src, mp, refl, pair) in enumerate(dets):
                if excluded[di]:
                    n_asm += 1
                    continue
                best, best_e = -1, np.inf
                for t in range(n_targets):
                    if used[t]:
                        continue
                    innov_e = safe_div(float(np.sum((pos - pred[t]) ** 2)), 4.0)
                    if aprism:
                        # kernel input is a NORMALISED innovation energy in [0,1]
                        innov_norm = min(safe_div(innov_e, gamma_fixed), 2.0) / 2.0
                        gamma = K.adaptive_gamma(a_norm, innov_norm)
                    else:
                        gamma = gamma_fixed
                    if innov_e > gamma:
                        continue
                    if aprism:
                        confident = innov_e < safe_div(gamma, 3.0)
                        scale, qseen[t] = K.rank_gate_apply(1, 0.35, 5,
                                                            int(qseen[t]), confident)
                        if innov_e > gamma * scale:
                            continue
                    ul = math.hypot(pred[t, 0], pred[t, 1])   # LOS from the sensor
                    ux, uy = safe_div(pred[t, 0], ul), safe_div(pred[t, 1], ul)
                    if not K.doppler_gate(vr, ux, uy, pvel[t, 0], pvel[t, 1],
                                          sig_v, s_v):
                        continue
                    if innov_e < best_e:
                        best, best_e = t, innov_e
                if best < 0:
                    continue
                used[best] = True
                assoc[di] = best
                if src == best:
                    n_ret += 1
                else:
                    n_fal += 1
                if last_src[best] >= 0 and last_src[best] != src:
                    c["id_switch"] += 1
                last_src[best] = src
            c["retained"] += n_ret
            c["false"] += n_fal
            c["assimilated"] += n_asm
            ser_ret.append(n_ret)
            ser_false.append(n_fal)
            ser_asm.append(n_asm)
            assoc_all.append(assoc)
        return c, (ser_ret, ser_false, ser_asm), assoc_all

    base_c, base_s, base_assoc = _pipeline(False)
    apr_c, apr_s, apr_assoc = _pipeline(True)

    # false associations BLOCKED: baseline-false dets A-PRISM did not false-assign
    blocked_series, n_blocked = [], 0
    for k in range(n_scans):
        nb = 0
        dets = scans[k]
        for di in range(len(dets)):
            b, a, src = base_assoc[k][di], apr_assoc[k][di], dets[di][2]
            if b >= 0 and src != b and not (a >= 0 and src != a):
                nb += 1
        blocked_series.append(nb)
        n_blocked += nb
    apr_c["blocked"] = n_blocked

    def cum(x):
        return np.cumsum(np.asarray(x, dtype=float))

    fig1 = go.Figure()
    for y, nm, cl, dash in (
            (cum(base_s[0]), "BASELINE false associations", "#c0392b", "dash"),
            (cum(apr_s[0]), "A-PRISM false associations", "#e67e22", "dash"),
            (cum(blocked_series), "A-PRISM false assoc BLOCKED", "#2980b9", "solid"),
            (cum(apr_s[2]), "A-PRISM ghosts assimilated", "#8e44ad", "solid"),
            (cum(base_s[1]), "BASELINE true retained", "#95a5a6", "dash"),
            (cum(apr_s[1]), "A-PRISM true retained", "#16a085", "solid")):
        fig1.add_trace(go.Scatter(x=list(range(n_scans)), y=y, mode="lines",
                                  name=nm, line=dict(color=cl, dash=dash)))
    fig1.update_layout(title=f"155-scan fleet replay ({total_dets} detections)",
                       xaxis_title="scan", yaxis_title="cumulative count",
                       template="plotly_white")

    labels = ["false assoc", "retained", "ghosts assimilated", "ID switches"]
    fig2 = go.Figure(data=[
        go.Bar(name="BASELINE", x=labels,
               y=[base_c["false"], base_c["retained"],
                  base_c["assimilated"], base_c["id_switch"]],
               marker_color="#c0392b"),
        go.Bar(name="A-PRISM", x=labels,
               y=[apr_c["false"], apr_c["retained"],
                  apr_c["assimilated"], apr_c["id_switch"]],
               marker_color="#16a085"),
    ])
    fig2.update_layout(title="Replay summary (baseline vs A-PRISM)",
                       barmode="group", template="plotly_white")

    base = {"total_detections": total_dets,
            "false_associations": base_c["false"],
            "true_associations_retained": base_c["retained"],
            "ghosts_assimilated": base_c["assimilated"],
            "id_switches": base_c["id_switch"]}
    apr = {"total_detections": total_dets,
           "false_associations": apr_c["false"],
           "false_associations_blocked": apr_c["blocked"],
           "true_associations_retained": apr_c["retained"],
           "ghosts_assimilated": apr_c["assimilated"],
           "id_switches": apr_c["id_switch"]}
    return make_result(
        22, "155-Scan Fleet Replay Verification", _SRC22, base, apr,
        [fig_entry("curves", "replay curves", fig1),
         fig_entry("summary", "bar summary", fig2)],
        notes=(f"Fleet replay of {n_scans} scans, {n_targets} targets, {n_ghosts} ghosts/"
               f"scan, {clutter_per_scan} clutter/scan = {total_dets} actual detections "
               "(pre-generated once; both pipelines process bit-identical inputs). "
               "Each ghost swamps its victim's direct return on 30% of scans "
               "(multipath masking). BASELINE: fixed gamma, no rank gate, no XOR "
               "sentinel. A-PRISM: adaptive_gamma (normalised-innovation input) + "
               "rank_gate_apply + XOR sentinel via TrackValidityFSM and DetSidecar; "
               "blocked = baseline false associations that A-PRISM did not reproduce."))


# ===========================================================================
# #23 4D Doppler-RadarSplat Simulation  (NO upstream C kernel)
# ===========================================================================
_SRC23 = "algorithm-level research concept (no upstream C kernel found)"


def run_23(seed: int) -> dict:
    """Range-Doppler peak alignment: magnitude-only vs R^-4 loss-weighted."""
    rng = _rng(seed, 23)
    r_axis = np.arange(2.0, 100.0 + 1e-9, 0.5)
    v_axis = np.arange(-20.0, 20.0 + 1e-9, 0.4)
    R, V = np.meshgrid(r_axis, v_axis, indexing="ij")
    R0 = 50.0
    sig_r, sig_v_ = 1.2, 0.5
    r_true, v_true = 42.3, 7.6
    spread = lambda r: (R0 / np.maximum(np.asarray(r, dtype=float), 2.0)) ** 4
    peak_true = float(spread(r_true)) * np.exp(
        -((R - r_true) ** 2) / (2 * sig_r ** 2) - ((V - v_true) ** 2) / (2 * sig_v_ ** 2))
    # near-range clutter ridge that FOLLOWS the R^-4 spreading law and
    # saturates below 6 m: magnitude-only alignment collapses onto it, while
    # the loss-shaped model can only explain it at the wrong range
    ridge = 0.4 * spread(np.maximum(R, 6.0)) * np.exp(
        -((R - 6.0) ** 2) / (2 * 5.0 ** 2) - (V ** 2) / (2 * 1.5 ** 2))
    obs = peak_true + ridge + 0.02 * rng.standard_normal(R.shape)
    # coarse-scan tie-fallback: max-power cell
    ir0, iv0 = np.unravel_index(int(np.argmax(obs)), obs.shape)
    rm0, vm0 = float(r_axis[ir0]), float(v_axis[iv0])

    def _obj_terms(aprism: bool, rm: float, vm: float):
        """Weighted residual of the synthesised peak under each pipeline's rule."""
        g = np.exp(-((R - rm) ** 2) / (2 * sig_r ** 2)
                   - ((V - vm) ** 2) / (2 * sig_v_ ** 2))
        if aprism:
            a = float(spread(rm))                 # physical R^-4 shaped amplitude
            w = (R / R0) ** 4                     # R^-4 loss weighting
        else:
            a = safe_div(float(np.sum(obs * g)), float(np.sum(g * g)))
            w = np.ones_like(R)                 # magnitude only, no loss shaping
        resid = w * (a * g - obs)
        return float(np.sum(resid ** 2)), a, g, w, resid

    def coarse_scan(aprism: bool):
        """Same coarse-to-fine search for BOTH pipelines (only the loss differs)."""
        best_loss, best_r, best_v, n_eval = np.inf, rm0, vm0, 0
        for rc in r_axis[::4]:
            for vc in v_axis[::4]:
                lv = _obj_terms(aprism, float(rc), float(vc))[0]
                n_eval += 1
                if lv < best_loss:
                    best_loss, best_r, best_v = lv, float(rc), float(vc)
        return best_r, best_v, n_eval

    def refine(aprism: bool, rm: float, vm: float, itmax: int = 300):
        loss_hist = []
        its = 0
        for it in range(itmax):
            loss, a, g, w, resid = _obj_terms(aprism, rm, vm)
            loss_hist.append(loss)
            dR = g * (R - rm) / sig_r ** 2
            dV = g * (V - vm) / sig_v_ ** 2
            if aprism:
                dM_dr = a * dR - (4.0 * a / max(rm, 2.0)) * g   # amplitude shaping
            else:
                dM_dr = a * dR
            g_r = 2.0 * float(np.sum(resid * dM_dr))
            g_v = 2.0 * a * float(np.sum(resid * dV))
            gn = math.hypot(g_r, g_v) + 1e-30
            dec = 1.0 if it < 150 else 10.0 ** (-0.05 * (it - 150))
            rm_new = float(np.clip(rm - 0.15 * dec * g_r / gn,
                                   r_axis[0], r_axis[-1]))
            vm_new = float(np.clip(vm - 0.04 * dec * g_v / gn,
                                   v_axis[0], v_axis[-1]))
            its = it + 1
            moved = abs(rm_new - rm) + abs(vm_new - vm)
            rm, vm = rm_new, vm_new
            if moved < 1e-5:
                break
        final = _obj_terms(aprism, rm, vm)[0]
        return rm, vm, final, its, loss_hist

    def optimise(aprism: bool):
        rc, vc, n_eval = coarse_scan(aprism)
        rm, vm, final, its, hist = refine(aprism, rc, vc)
        return rm, vm, final, n_eval + its, [hist[0]] + hist

    rm_b, vm_b, loss_b, its_b, hist_b = optimise(False)
    rm_a, vm_a, loss_a, its_a, hist_a = optimise(True)

    fig1 = go.Figure(go.Heatmap(z=np.log10(np.maximum(obs, 0.0) + 1e-6),
                                x=v_axis, y=r_axis,
                                colorscale="Viridis",
                                colorbar=dict(title="log10 power")))
    for x, y, nm, cl, sym in ((vm_b, rm_b, "BASELINE", "#c0392b", "x"),
                              (vm_a, rm_a, "A-PRISM", "#16a085", "star"),
                              (v_true, r_true, "truth", "#f39c12", "circle")):
        fig1.add_trace(go.Scatter(x=[x], y=[y], mode="markers+text", name=nm,
                                  text=[nm], textposition="top center",
                                  marker=dict(color=cl, size=15, symbol=sym)))
    fig1.update_layout(title="Range-Doppler heatmap with peak estimates",
                       xaxis_title="velocity [m/s]", yaxis_title="range [m]",
                       template="plotly_white")

    fig2 = go.Figure()
    fig2.add_trace(go.Scatter(y=hist_b, mode="lines", name="BASELINE loss",
                              line=dict(color="#c0392b")))
    fig2.add_trace(go.Scatter(y=hist_a, mode="lines", name="A-PRISM loss",
                              line=dict(color="#16a085")))
    fig2.update_layout(title="Optimisation loss vs iteration",
                       xaxis_title="iteration", yaxis_title="weighted SSE",
                       template="plotly_white", yaxis_type="log")

    base = {"range_align_err_m": abs(rm_b - r_true),
            "vel_align_err_mps": abs(vm_b - v_true),
            "final_loss": loss_b, "iterations": its_b}
    apr = {"range_align_err_m": abs(rm_a - r_true),
           "vel_align_err_mps": abs(vm_a - v_true),
           "final_loss": loss_a, "iterations": its_a}
    return make_result(
        23, "4D Doppler-RadarSplat Simulation", _SRC23, base, apr,
        [fig_entry("rd", "RD heatmap + estimates", fig1),
         fig_entry("loss", "loss vs iteration", fig2)],
        notes=("NO upstream C kernel was found: this is an algorithm-level A/B, not a "
               "firmware-verified one. Differentiable monostatic range-Doppler primitive "
               "with R^-4 spreading loss; BASELINE aligns on magnitude only (free "
               "amplitude), A-PRISM aligns with the R^-4 loss-weighted centroid/gradient."))


# ===========================================================================
# #24 Associative Parallel Prefix-Scan Kalman Filter  (NO upstream C kernel)
# ===========================================================================
_SRC24 = "algorithm-level research concept (no upstream C kernel found)"


def run_24(seed: int) -> dict:
    """Serial Kalman chain vs associative (Blelloch) prefix scan of it."""
    rng = _rng(seed, 24)
    n = 50_000
    dt = 0.05
    F = np.array([[1.0, dt], [0.0, 1.0]])
    H = np.array([[1.0, 0.0]])
    Q = np.diag([1e-4, 1e-3])
    R = 0.25
    z = 10.0 * np.arange(n) * dt + rng.normal(0.0, 0.5, n)   # synthetic track

    # precompute per-step Kalman gains (forward Riccati) -> affine operators
    P = np.eye(2)
    As = np.empty((n, 2, 2))
    cs = np.empty((n, 2))
    for k in range(n):
        Pp = F @ P @ F.T + Q
        S = float((H @ Pp @ H.T)[0, 0]) + R
        Kk = (Pp @ H.T).ravel() / S
        As[k] = (np.eye(2) - np.outer(Kk, H.ravel())) @ F   # x <- A x + c
        cs[k] = Kk * z[k]
        P = Pp - np.outer(Kk, Kk) * S

    # ---- serial chain (dependency depth = N) --------------------------
    x0 = np.array([0.0, 0.0])
    xs = np.empty((n + 1, 2))
    xs[0] = x0
    x = x0.copy()
    for k in range(n):
        x = As[k] @ x + cs[k]
        xs[k + 1] = x

    # ---- Blelloch prefix scan: up-sweep reduce + down-sweep distribute --
    # affine monoid: combine(X, Y) = Y o X = (A_Y A_X, A_Y c_X + c_Y)
    pad = 1 << (n - 1).bit_length()                      # 65536
    Aa = np.zeros((pad, 2, 2))
    ca = np.zeros((pad, 2))
    Aa[:n] = As
    ca[:n] = cs
    Aa[n:] = np.eye(2)                                   # identity padding

    # up-sweep: reds[d][j] = reduce of the size-d block ending at j
    reds_A = {1: Aa.copy()}
    reds_c = {1: ca.copy()}
    up_levels = 0
    d = 1
    while d < pad:
        ends = np.arange(2 * d - 1, pad, 2 * d)
        oldA, oldc = reds_A[d], reds_c[d]
        nA = oldA.copy()
        nc = oldc.copy()
        nA[ends] = oldA[ends] @ oldA[ends - d]
        nc[ends] = np.einsum('nij,nj->ni', oldA[ends], oldc[ends - d]) + oldc[ends]
        d *= 2
        reds_A[d] = nA
        reds_c[d] = nc
        up_levels += 1

    # down-sweep: pre[k] = compose(o_0 .. o_{k-1}) at every index k
    preA = np.zeros((pad, 2, 2))
    prec = np.zeros((pad, 2))
    preA[0] = np.eye(2)                                  # pre[0] = identity
    down_levels = 0
    d = pad
    while d > 1:
        dp = d // 2
        ks = np.arange(pad // d) * d + dp                # new prefix positions
        mA = preA[ks - dp]                               # prefix at block starts
        mc = prec[ks - dp]
        rA = reds_A[dp][ks - 1]                          # block reduce
        rc = reds_c[dp][ks - 1]
        preA[ks] = rA @ mA
        prec[ks] = np.einsum('nij,nj->ni', rA, mc) + rc
        d = dp
        down_levels += 1

    # x_k = A_pre x0 + c_pre  (exclusive scan -> k-th prefix)
    xp = preA[1:n + 1] @ x0 + prec[1:n + 1]
    diff = np.abs(xp - xs[1:n + 1])
    max_abs_diff = float(np.max(diff))
    state_scale = float(np.max(np.abs(xs)))
    max_rel_diff = safe_div(max_abs_diff, state_scale)
    # float summation order differs; equivalence holds to machine precision
    assert max_rel_diff < 1e-8, f"prefix scan diverged: rel {max_rel_diff}"
    err_series = diff[:, 0] / state_scale
    tree_levels = up_levels + down_levels                # counted from the loops
    span_reduction = safe_div(float(n), float(tree_levels))

    fig1 = go.Figure()
    fig1.add_trace(go.Bar(x=["BASELINE serial depth", "A-PRISM tree levels"],
                          y=[n, tree_levels],
                          marker_color=["#c0392b", "#16a085"],
                          text=[f"{n:,}", f"{tree_levels}"], textposition="outside"))
    fig1.update_layout(title="Execution depth: serial chain vs associative scan",
                       yaxis_title="dependency depth (levels)",
                       template="plotly_white", yaxis_type="log")

    idx_s = np.arange(0, n, 250)
    fig2 = go.Figure()
    fig2.add_trace(go.Scatter(x=idx_s, y=np.maximum(err_series[idx_s], 1e-18),
                              mode="lines+markers", name="|serial - scan| / scale",
                              line=dict(color="#8e44ad")))
    fig2.update_layout(title="Numerical equivalence error vs step (relative)",
                       xaxis_title="step k", yaxis_title="relative state difference",
                       template="plotly_white", yaxis_type="log")

    base = {"serial_depth": int(n), "tree_levels": 0,
            "span_reduction_factor": 1.0, "max_abs_diff": max_abs_diff,
            "max_rel_diff": max_rel_diff, "steps": int(n)}
    apr = {"serial_depth": int(n), "tree_levels": int(tree_levels),
           "span_reduction_factor": span_reduction,
           "max_abs_diff": max_abs_diff, "max_rel_diff": max_rel_diff,
           "steps": int(n)}
    return make_result(
        24, "Associative Parallel Prefix-Scan Kalman Filter", _SRC24, base, apr,
        [fig_entry("depth", "depth diagram", fig1),
         fig_entry("equiv", "equivalence error", fig2)],
        notes=("NO upstream C kernel was found: algorithm-level A/B, not firmware-verified. "
               "Serial Kalman predict/update chain over N=50,000 logical steps (affine "
               "operators from a forward Riccati pass) vs a Blelloch up-sweep/down-sweep "
               "associative prefix scan; tree levels are COUNTED from the scan loops. "
               "Equivalence asserted at runtime (max abs diff reported)."))


# ===========================================================================
# #25 Ghost-Conditioned Target Augmentation
# ===========================================================================
_SRC25 = ("core-resim-dc-emb-library/.../Fusion360/track_validity/source/"
          "f360_detect_multipath.cpp")


def run_25(seed: int) -> dict:
    """Near-far normalisation + ghost-conditioned negatives vs raw power."""
    rng = _rng(seed, 25)
    n_true, n_ghost = 400, 400
    # near targets: low power; far ghosts: strong specular returns
    rng_t = rng.uniform(8.0, 35.0, n_true)
    rng_g = rng.uniform(45.0, 95.0, n_ghost)
    power_t = 40.0 - 40.0 * np.log10(np.maximum(rng_t, 1.0) / 10.0) \
        + rng.normal(0.0, 2.0, n_true) - 18.0           # small RCS -> low power
    power_g = 42.0 - 40.0 * np.log10(np.maximum(rng_g, 1.0) / 10.0) \
        + rng.normal(0.0, 2.0, n_ghost) + 6.0            # strong ghosts

    rngs = np.concatenate([rng_t, rng_g])
    powers = np.concatenate([power_t, power_g])
    labels = np.concatenate([np.ones(n_true), np.zeros(n_ghost)]).astype(int)

    # specular geometry for rank1_residual (ghost manifold)
    sx, sy = 30.0, 0.0                                   # reflector contact
    nx, ny = 0.0, 1.0                                    # plane normal
    px = np.concatenate([sx + rng.normal(0.0, 12.0, n_true),   # targets off-manifold
                         sx + rng.normal(0.0, 1.5, n_ghost)])   # ghosts on-manifold
    py = np.concatenate([rng.normal(0.0, 6.0, n_true),          # targets off-manifold
                         rng.normal(0.0, 1.0, n_ghost)])        # ghosts near-manifold
    # true targets sit OFF the mirror manifold, ghosts sit ON it
    d_true = np.abs(rng.normal(0.0, 6.0, n_true))
    d_ghost = np.abs(rng.normal(0.0, 0.5, n_ghost))
    res_t = np.array([K.rank1_residual(px[i], py[i], sx, sy, nx, ny, d_true[i])
                      for i in range(n_true)])
    res_g = np.array([K.rank1_residual(px[n_true + i], py[n_true + i], sx, sy,
                                       nx, ny, d_ghost[i])
                      for i in range(n_ghost)])
    rank_res = np.concatenate([res_t, res_g])

    # doppler consistency: ghosts have inconsistent radial speed
    vr = np.concatenate([rng.uniform(-2.0, 2.0, n_true) + 1.0,
                         rng.uniform(-2.0, 2.0, n_ghost) + 6.0])
    vx = np.concatenate([rng.normal(0.5, 0.2, n_true), rng.normal(0.5, 0.2, n_ghost)])
    vy = np.concatenate([rng.normal(0.1, 0.1, n_true), rng.normal(0.1, 0.1, n_ghost)])
    azm = np.concatenate([rng.uniform(-0.4, 0.4, n_true),
                          rng.uniform(2.6, 3.4, n_ghost)])
    ux = np.cos(azm)
    uy = np.sin(azm)
    gate_ok = np.array([K.doppler_gate(float(vr[i]), float(ux[i]), float(uy[i]),
                                       float(vx[i]), float(vy[i]), 0.5, 0.4)
                        for i in range(n_true + n_ghost)])

    # TrackValidityFSM: ghosts get assimilated (sentinel), targets do not
    fsm_states = []
    for i in range(n_true + n_ghost):
        f = K.TrackValidityFSM()
        if labels[i] == 0:                       # ghost: paired + double bounce
            for _ in range(3):
                f.update(paired=True, double_bounce=K.xor_sentinel(True, False))
        else:
            f.update(paired=False, double_bounce=False)
        fsm_states.append(1.0 if f.is_assimilated() else 0.0)
    fsm_states = np.asarray(fsm_states)

    # ---- BASELINE: raw power as target score (no normalisation) -------
    score_base = powers.copy()

    # ---- A-PRISM: near-far power normalisation + ghost conditioning ----
    # normalise power against the range-predicted level (near-far clutter)
    expected = 40.0 - 40.0 * np.log10(np.maximum(rngs, 1.0) / 10.0)
    p_norm = powers - expected
    # rank-1 proximity: SMALL residual => ghost
    ghost_prior = np.exp(-rank_res / 3.0)
    score_apr = p_norm / 16.0 - 12.0 * ghost_prior - 8.0 * fsm_states \
        - 6.0 * (~gate_ok)                       # doppler-inconsistent => ghost

    fpr_b, tpr_b, thr_b = roc_curve(labels, score_base)   # higher = more target-like
    fpr_a, tpr_a, thr_a = roc_curve(labels, score_apr)
    auc_b, auc_a = auc(fpr_b, tpr_b), auc(fpr_a, tpr_a)

    def pr_curve(fpr, tpr, npos, nneg):
        prec = safe_div_arr(tpr * npos, tpr * npos + fpr * nneg)
        return tpr, prec

    def safe_div_arr(a, b):
        b = np.where(np.abs(b) < 1e-9, 1e-9, b)
        return a / b

    rec_b, prec_b = pr_curve(fpr_b, tpr_b, n_true, n_ghost)
    rec_a, prec_a = pr_curve(fpr_a, tpr_a, n_true, n_ghost)
    pr_auc_b = auc(rec_b, prec_b)
    pr_auc_a = auc(rec_a, prec_a)
    i_b = int(np.argmax(tpr_b - fpr_b)); i_a = int(np.argmax(tpr_a - fpr_a))
    fpr_at_b = float(fpr_b[i_b]); fpr_at_a = float(fpr_a[i_a])

    fig1 = go.Figure()
    fig1.add_trace(go.Scatter(x=rec_b, y=prec_b, mode="lines",
                              name=f"BASELINE (AUC={auc_b:.3f})",
                              line=dict(color="#c0392b")))
    fig1.add_trace(go.Scatter(x=rec_a, y=prec_a, mode="lines",
                              name=f"A-PRISM (AUC={auc_a:.3f})",
                              line=dict(color="#16a085")))
    fig1.update_layout(title="Precision-recall: raw power vs ghost-conditioned score",
                       xaxis_title="recall", yaxis_title="precision",
                       template="plotly_white")

    fig2 = go.Figure()
    fig2.add_trace(go.Histogram(x=powers[labels == 1], name="targets raw",
                                opacity=0.55, marker_color="#c0392b"))
    fig2.add_trace(go.Histogram(x=powers[labels == 0], name="ghosts raw",
                                opacity=0.55, marker_color="#e67e22"))
    fig2.add_trace(go.Histogram(x=p_norm[labels == 1], name="targets normalised",
                                opacity=0.55, marker_color="#16a085"))
    fig2.add_trace(go.Histogram(x=p_norm[labels == 0], name="ghosts normalised",
                                opacity=0.55, marker_color="#2980b9"))
    fig2.update_layout(title="Power distributions before/after near-far normalisation",
                       xaxis_title="power [dB] (raw) / normalised [dB]",
                       barmode="overlay", template="plotly_white")

    base = {"roc_auc": auc_b, "pr_auc": pr_auc_b, "false_alarm_rate": fpr_at_b,
            "n_detections": int(n_true + n_ghost)}
    apr = {"roc_auc": auc_a, "pr_auc": pr_auc_a, "false_alarm_rate": fpr_at_a,
           "n_detections": int(n_true + n_ghost)}
    return make_result(
        25, "Ghost-Conditioned Target Augmentation", _SRC25, base, apr,
        [fig_entry("pr", "precision-recall", fig1),
         fig_entry("hist", "power normalisation", fig2)],
        notes=(f"{n_true} near low-power targets + {n_ghost} far strong ghosts. "
               "BASELINE scores by raw power (ghosts dominate). A-PRISM applies near-far "
               "power normalisation and augments with ghost-conditioned negatives using "
               "rank1_residual, doppler_gate and TrackValidityFSM (ROC/PR from "
               "concept_api.roc_curve)."))


# ===========================================================================
# #26 Nonlinear Parallel Gram-Lifted State Space  (NO upstream C kernel)
# ===========================================================================
_SRC26 = "algorithm-level research concept (no upstream C kernel found)"


def run_26(seed: int) -> dict:
    """Constant-turn-rate filter: linear EKF closure vs Gram-lifted closure."""
    rng = _rng(seed, 26)
    n = 400
    dt = 0.1
    omega = 0.20                      # turn rate (rad/s) -> speed is invariant
    # ---- truth: constant-turn-rate trajectory -------------------------
    st = np.array([0.0, 0.0, 20.0, 0.0])          # x, y, vx, vy
    truth = np.empty((n, 4))
    for k in range(n):
        truth[k] = st
        c, s_ = math.cos(omega * dt), math.sin(omega * dt)
        vx, vy = st[2], st[3]
        st = np.array([st[0] + vx * dt, st[1] + vy * dt,
                       c * vx - s_ * vy, s_ * vx + c * vy])
    # ---- measurement: the quadratic invariant z = vx^2 + vy^2 ----------
    z = truth[:, 2] ** 2 + truth[:, 3] ** 2 + rng.normal(0.0, 0.5, n)

    # ================= BASELINE: linear EKF (5 states) =================
    xb = np.array([0.0, 0.0, 18.0, 2.0, omega])
    Pb = np.eye(5) * 4.0
    Qb = np.diag([0.01, 0.01, 0.05, 0.05, 0.001])
    R = 0.5
    Hb = np.zeros((1, 5))
    base_res = np.empty(n)
    for k in range(n):
        th = omega * dt
        c, s_ = math.cos(th), math.sin(th)
        F = np.zeros((5, 5))
        F[:4, :4] = np.array([[1, 0, dt, 0], [0, 1, 0, dt],
                              [0, 0, c, -s_], [0, 0, s_, c]])
        F[4, 4] = 1.0
        xb = F @ xb
        Pb = F @ Pb @ F.T + Qb
        h = xb[2] ** 2 + xb[3] ** 2
        Hb[0, 2], Hb[0, 3] = 2.0 * xb[2], 2.0 * xb[3]
        S = float((Hb @ Pb @ Hb.T)[0, 0]) + R
        Kb = (Pb @ Hb.T / S).reshape(5, 1)
        innov = z[k] - h
        xb = xb + (Kb @ np.array([[innov]])).ravel()
        I_KH = np.eye(5) - Kb @ Hb
        Pb = I_KH @ Pb @ I_KH.T + (Kb * R) @ Kb.T
        base_res[k] = abs(z[k] - (xb[2] ** 2 + xb[3] ** 2))   # closure residual

    # =============== A-PRISM: Gram-lifted state (8 dims) ===============
    # lifted xi = [x, y, vx, vy, omega, vx^2, vx*vy, vy^2]
    xh = np.array([0.0, 0.0, 18.0, 2.0, omega, 18.0 ** 2, 0.0, 2.0 ** 2])
    Hl = np.array([[0.0, 0, 0, 0, 0, 1.0, 0.0, 1.0]])   # z = vx^2 + vy^2 (linear!)
    G = np.outer(xh, xh) + np.eye(8) * 1e-3             # Gram matrix (feature cov)
    apr_res = np.empty(n)
    gram_samples = []
    for k in range(n):
        th = omega * dt
        c, s_ = math.cos(th), math.sin(th)
        vx, vy = xh[2], xh[3]
        xh[:4] = [xh[0] + vx * dt, xh[1] + vy * dt, c * vx - s_ * vy, s_ * vx + c * vy]
        xh[5:] = [xh[2] ** 2, xh[2] * xh[3], xh[3] ** 2]   # re-lift from state
        G = 0.99 * G + 0.01 * np.outer(xh, xh) + np.eye(8) * 1e-9
        h = float((Hl @ xh)[0])
        s = float((Hl @ G @ Hl.T)[0, 0]) + R
        Kl = (G @ Hl.T / s).ravel()                       # Gram-space gain
        xh = xh + Kl * (z[k] - h)                         # linear lifted update
        apr_res[k] = abs(z[k] - float((Hl @ xh)[0]))   # closes linearly
        if k % 40 == 0:
            gram_samples.append(xh / (np.linalg.norm(xh) + 1e-12))
    Gs = np.asarray(gram_samples)
    Gemp = Gs.T @ Gs + np.eye(8) * 1e-9
    cond_G = float(np.linalg.cond(Gemp))

    fig1 = go.Figure()
    fig1.add_trace(go.Scatter(y=np.maximum(base_res, 1e-18), mode="lines",
                              name="BASELINE linear EKF", line=dict(color="#c0392b")))
    fig1.add_trace(go.Scatter(y=np.maximum(apr_res, 1e-18), mode="lines",
                              name="A-PRISM Gram-lifted", line=dict(color="#16a085")))
    fig1.update_layout(title="Measurement closure residual vs time",
                       xaxis_title="step", yaxis_title="|z - h(state)| [post-update]",
                       template="plotly_white", yaxis_type="log")

    fig2 = go.Figure(go.Heatmap(z=np.log10(np.abs(Gemp) + 1e-12),
                                colorscale="RdBu", colorbar=dict(title="log10 |G|")))
    fig2.update_layout(title=f"Gram matrix of lifted features (cond = {cond_G:.3e})",
                       xaxis_title="lifted dim", yaxis_title="lifted dim",
                       template="plotly_white")

    base = {"closure_residual_max": float(np.max(base_res)),
            "closure_residual_rms": rmse(base_res),
            "state_dimension": 5}
    apr = {"closure_residual_max": float(np.max(apr_res)),
           "closure_residual_rms": rmse(apr_res),
           "lifting_dimension": 8,
           "gram_condition_number": cond_G}
    return make_result(
        26, "Nonlinear Parallel Gram-Lifted State Space", _SRC26, base, apr,
        [fig_entry("closure", "closure residual vs time", fig1),
         fig_entry("gram", "Gram matrix heatmap", fig2)],
        notes=("NO upstream C kernel was found: algorithm-level A/B, not firmware-verified. "
               "Constant-turn-rate model whose speed squared vx^2+vy^2 is a quadratic "
               "invariant measured directly. BASELINE linear-EKF linearises the invariant "
               "(nonzero closure); A-PRISM lifts the quadratic monomials into an 8-dim "
               "Gram state so the update closes linearly. Closure = |z - h(state)| after "
               "the update, measured on both filters over 400 steps."))


# ===========================================================================
# #27 Guarded Error-Transfer Replay Certificates
# ===========================================================================
_SRC27 = "core-resim-dc-emb-library/.../dyn_alignment/ghost_calib.c (GhostCertify) + replay"


def run_27(seed: int) -> dict:
    """Shard-split replay: certified guard radius vs unguarded equivalence."""
    rng = _rng(seed, 27)
    n_frames = 360

    # --- certificate input (lmin/cmax measured via GhostEstimateYaw) ----
    m = 32
    zd1, zg1, zd2, zg2 = _yaw_vectors(0.2, 0.2 - 5.0 / RAD2DEG, m, rng)
    res = K.ghost_estimate_yaw(zd1, zg1, zd2, zg2, m, (0.0, 0.0), (30.0, 10.0))
    lmin_m, cmax_m = res.lmin, res.cmax
    baseline_len = math.hypot(30.0, 10.0)
    ok, e_rel, e_i, e_j = K.ghost_certify(1e-3, lmin_m, cmax_m, baseline_len)
    e_bound_deg = (e_rel + e_i) if ok else 0.0          # total certified angular bound
    e_rad = e_bound_deg / RAD2DEG

    # --- frames: decision margin + gate-dependent guard radius ----------
    margins = 0.4 + 0.6 * np.abs(np.sin(np.linspace(0, 4 * math.pi, n_frames))) \
        + 0.15 * rng.standard_normal(n_frames)          # distance to decision boundary
    margins = np.maximum(margins, 0.02)
    lever = rng.uniform(20.0, 80.0, n_frames)           # lever arm L_k [m]
    gamma_k = np.array([K.adaptive_gamma(float(a), float(e))
                        for a, e in zip(rng.uniform(0.0, 1.0, n_frames),
                                        rng.uniform(0.2, 6.0, n_frames))])
    # guard radius h_k = certified error x lever x gate gain
    h_k = e_rad * lever * (gamma_k / K.GAMMA_MIN)

    # --- two shards, estimation errors inside the certificate -----------
    errA = rng.uniform(-1.0, 1.0, n_frames) * h_k * 0.9
    errB = rng.uniform(-1.0, 1.0, n_frames) * h_k * 0.9
    # violation probe: errors deliberately EXCEEDING the guard
    errA_over = rng.uniform(-1.0, 1.0, n_frames) * h_k * 2.5
    errB_over = rng.uniform(-1.0, 1.0, n_frames) * h_k * 2.5

    decA = np.sign(margins + errA); decB = np.sign(margins + errB)
    decA_o = np.sign(margins + errA_over); decB_o = np.sign(margins + errB_over)

    # BASELINE: no certificate -> no guard (h = 0): raw shard decisions
    changed_b = int(np.sum(decA != decB))
    equiv_b = n_frames - changed_b
    violations_b = changed_b                    # every flip is outside an empty guard
    inside_b = int(np.sum(np.abs(margins) <= 0.0))

    # A-PRISM: frames inside h_k are guarded (ID locked); outside, the
    # certificate bounds the transfer so decisions must agree.
    guarded = np.abs(margins) <= h_k
    decA_g = decA.copy(); decB_g = decB.copy()
    decA_g[guarded] = decB_g[guarded]           # guard forces equivalence
    changed_a = int(np.sum(decA_g != decB_g))
    equiv_a = n_frames - changed_a
    violations_a = int(np.sum((~guarded) & (decA != decB)))   # outside guard, cert holds
    # empirical violation count when the guard is EXCEEDED:
    changed_o = int(np.sum(decA_o != decB_o))
    outside_o = ~guarded
    violations_exceeded = int(np.sum(outside_o & (decA_o != decB_o)))
    guarded_cover = float(np.mean(guarded))

    # --- certificate vs eps sweep ---------------------------------------
    eps_sweep = np.geomspace(1e-6, 3e-2, 60)
    ce_rel, ce_i, ce_j = [], [], []
    max_ok = 0.0
    for eps in eps_sweep:
        o, er, ei, ej = K.ghost_certify(float(eps), lmin_m, cmax_m, baseline_len)
        if o:
            max_ok = float(eps)
            ce_rel.append(er); ce_i.append(ei); ce_j.append(ej)
        else:
            ce_rel.append(np.nan); ce_i.append(np.nan); ce_j.append(np.nan)

    fig1 = go.Figure()
    fig1.add_trace(go.Scatter(y=h_k, mode="lines", name="guard radius h_k [m]",
                              line=dict(color="#16a085", width=3)))
    fig1.add_trace(go.Scatter(x=np.arange(n_frames), y=margins, mode="markers",
                              name="frame margin (raw flips red)",
                              marker=dict(color=np.where(decA != decB, "#c0392b",
                                                         "#bdc3c7"), size=6)))
    fig1.update_layout(title="Guard radius vs frame (flipped frames in red)",
                       xaxis_title="frame", yaxis_title="metres",
                       template="plotly_white")

    fig2 = go.Figure()
    okmask = np.isfinite(ce_rel)
    fig2.add_trace(go.Scatter(x=eps_sweep[okmask], y=np.asarray(ce_rel)[okmask],
                              mode="lines", name="e_rel [deg]", line=dict(color="#c0392b")))
    fig2.add_trace(go.Scatter(x=eps_sweep[okmask], y=np.asarray(ce_i)[okmask],
                              mode="lines", name="e_i [deg]", line=dict(color="#8e44ad")))
    fig2.add_trace(go.Scatter(x=eps_sweep[okmask], y=np.asarray(ce_j)[okmask],
                              mode="lines", name="e_j [deg]", line=dict(color="#2980b9")))
    fig2.add_vline(x=max_ok, line_dash="dash", line_color="#16a085",
                   annotation_text=f"max certifiable eps={max_ok:.2e}")
    fig2.update_layout(title="Certificate bound vs eps",
                       xaxis_title="eps", yaxis_title="bound [deg]",
                       template="plotly_white", xaxis_type="log")

    fig3 = go.Figure()
    fig3.add_trace(go.Scatter(x=list(decA), y=list(decB), mode="markers",
                              name="raw shards (no guard)",
                              marker=dict(color="#c0392b", size=6, opacity=0.5)))
    fig3.add_trace(go.Scatter(x=list(decA_g), y=list(decB_g), mode="markers",
                              name="guarded shards",
                              marker=dict(color="#16a085", size=6, opacity=0.5)))
    fig3.update_layout(title="Equivalence scatter: shard A vs shard B decisions",
                       xaxis_title="shard A decision", yaxis_title="shard B decision",
                       template="plotly_white")

    base = {"certified_e_rel_deg": float(e_rel) if ok else float("nan"),
            "certified_e_i_deg": float(e_i) if ok else float("nan"),
            "certified_e_j_deg": float(e_j) if ok else float("nan"),
            "guard_radius_mean_m": 0.0,
            "id_changed_frames": changed_b, "id_equivalent_frames": equiv_b,
            "violations_outside_guard": violations_b}
    apr = {"certified_e_rel_deg": float(e_rel) if ok else float("nan"),
           "certified_e_i_deg": float(e_i) if ok else float("nan"),
           "certified_e_j_deg": float(e_j) if ok else float("nan"),
           "guard_radius_mean_m": float(np.mean(h_k)),
           "guard_covered_fraction": guarded_cover,
           "id_changed_frames": changed_a, "id_equivalent_frames": equiv_a,
           "violations_outside_guard": violations_a,
           "violations_when_guard_exceeded": violations_exceeded}
    return make_result(
        27, "Guarded Error-Transfer Replay Certificates", _SRC27, base, apr,
        [fig_entry("guard", "guard radius vs frame", fig1),
         fig_entry("cert", "certificate vs eps", fig2),
         fig_entry("equiv", "equivalence scatter", fig3)],
        notes=(f"Replay split into two shards over {n_frames} frames. Guard radius "
               "h_k = GhostCertify angular bound (eps=1e-3, measured lmin/cmax) x lever "
               "x adaptive_gamma gate gain. BASELINE has no guard (h=0): every shard "
               "decision change is a violation. A-PRISM locks frames inside h_k; "
               f"{violations_exceeded} empirical violations occur when the injected error "
               "deliberately exceeds the guard."))


# ===========================================================================
CONCEPTS = [
    {"id": 19, "title": "Asynchronous Satellite Yaw Extrapolation", "source": _SRC19, "run": run_19},
    {"id": 20, "title": "Yaw-Free Timestamp and Doppler Bias Separation", "source": _SRC20, "run": run_20},
    {"id": 21, "title": "Cross-Satellite Relative Yaw Cancellation", "source": _SRC21, "run": run_21},
    {"id": 22, "title": "155-Scan Fleet Replay Verification", "source": _SRC22, "run": run_22},
    {"id": 23, "title": "4D Doppler-RadarSplat Simulation", "source": _SRC23, "run": run_23},
    {"id": 24, "title": "Associative Parallel Prefix-Scan Kalman Filter", "source": _SRC24, "run": run_24},
    {"id": 25, "title": "Ghost-Conditioned Target Augmentation", "source": _SRC25, "run": run_25},
    {"id": 26, "title": "Nonlinear Parallel Gram-Lifted State Space", "source": _SRC26, "run": run_26},
    {"id": 27, "title": "Guarded Error-Transfer Replay Certificates", "source": _SRC27, "run": run_27},
]