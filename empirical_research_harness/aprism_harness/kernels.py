"""1:1 Python/numpy mirrors of the A-PRISM research kernels.

Every function here is a faithful re-implementation of production C/C++ code so
that BASELINE (feature OFF) and A-PRISM (feature ON) can be executed on
identical inputs and their outputs compared empirically.

Source of truth (read-only references):
  Gen8 DSP firmware : gen_research/Core_Radar_Gen8_iND13400/software/bbe32/
  DC tracker / SIL  : gen_research/core-resim-dc-emb-library/

All divisions are eps-guarded (EPS = 1e-9) per the harness engineering rules.
"""
from __future__ import annotations

import math
from dataclasses import dataclass, field
from typing import Optional, Sequence, Tuple

import numpy as np

EPS = 1e-9
TWO_PI = 6.283185307179586
RAD2DEG = 57.29577951308232

# ---------------------------------------------------------------------------
# Gen8: A-PRISM adaptive CFAR  (appl_adaptive_cfar.c / appl_cfar_ifc.c)
# ---------------------------------------------------------------------------

APRISM_CFAR_EMA_LAMBDA = 0.02      # aprism_adaptive_cfar.h
APRISM_CFAR_WALL_MULT = 12.0       # stored, never read by any function
APRISM_CFAR_MAX_REFS = 64
APRISM_CFAR_DEFAULT_PFA = 1e-4

# Reference-window radii by range bin (R0_SMALL/MID/LARGE).
R0_SMALL, R0_MID, R0_LARGE = 8, 16, 32


def aprism_median(values: Sequence[float], scratch: Optional[np.ndarray] = None) -> float:
    """Deterministic median (insertion sort), matching the C helper exactly."""
    arr = np.asarray(values, dtype=float).ravel()
    n = arr.size
    if n == 0:
        return 0.0
    if n % 2 == 1:
        return float(np.sort(arr)[n // 2])
    s = np.sort(arr)
    return 0.5 * float(s[n // 2 - 1] + s[n // 2])


@dataclass
class AprismCfarCfg:
    ema_lambda: float = APRISM_CFAR_EMA_LAMBDA
    wall_mult: float = APRISM_CFAR_WALL_MULT
    pfa: float = APRISM_CFAR_DEFAULT_PFA
    enabled: bool = True


@dataclass
class AprismCfarState:
    cfg: AprismCfarCfg
    floor: np.ndarray
    nbins: int


def aprism_dual_loop_floor(state: AprismCfarState, r: int, row: np.ndarray,
                           free: np.ndarray, nad: int,
                           scratch: Optional[np.ndarray] = None) -> None:
    """Fast/slow dual-loop noise-floor EMA over the free reference cells.

    C: vals[] collects cells with free_mask != 0 (m < 64 cap); med = median(vals);
    floor[r] += lambda * (med - floor[r]).  No wall/skirt/occupancy logic exists.
    """
    if scratch is None:
        scratch = np.zeros(APRISM_CFAR_MAX_REFS, dtype=float)
    vals: list[float] = []
    for i in range(min(nad, APRISM_CFAR_MAX_REFS)):
        if free[i] != 0:
            vals.append(float(row[i]))
            if len(vals) >= APRISM_CFAR_MAX_REFS:
                break
    if not vals:
        return  # hold previous floor
    med = aprism_median(vals, scratch)
    lam = state.cfg.ema_lambda
    state.floor[r] += lam * (med - state.floor[r])


def aprism_blue_weights(pi: np.ndarray, snr: np.ndarray, beta: np.ndarray) -> None:
    """BLUE (bounded linear unbiased) weighting of the reference cells.

    m = 1 + pi*s ;  v = 2*(1 - pi + pi*(1+s)^2) - m^2 ;  w = m/v ;
    beta = w / sum(m*w)   (sums to 1).
    """
    pi = np.asarray(pi, dtype=float)
    snr = np.asarray(snr, dtype=float)
    m = 1.0 + pi * snr
    v = 2.0 * (1.0 - pi + pi * (1.0 + snr) ** 2) - m ** 2
    v = np.maximum(v, 1e-12)
    w = m / v
    den = float(np.sum(m * w))
    if den < 1e-12:
        den = 1e-12
    beta[:] = w / den


def aprism_alpha_for_pfa(beta: np.ndarray, n: int, pfa: float) -> float:
    """Solve sum_i ln(1 + a*beta_i) = -ln(pfa) for a (bracket + 100 bisections)."""
    if pfa <= 0.0:
        return 0.0
    beta = np.asarray(beta, dtype=float).ravel()[:n]
    if beta.size == 0:
        return 0.0
    target = -math.log(pfa)

    def g(a: float) -> float:
        return float(np.sum(np.log1p(a * beta))) + math.log(pfa)

    lo, hi = 0.0, 1.0
    it = 0
    while g(hi) < 0.0 and it < 200:
        hi *= 2.0
        it += 1
    if hi > 1e12:
        return hi
    for _ in range(100):
        mid = 0.5 * (lo + hi)
        if g(mid) < 0.0:
            lo = mid
        else:
            hi = mid
    return 0.5 * (lo + hi)


def aprism_ca_alpha(n: int, pfa: float) -> float:
    """Classical CA (cell averaging) alpha: n * (pfa^(-1/n) - 1)."""
    if n <= 0 or pfa <= 0.0:
        return 0.0
    return n * (pfa ** (-1.0 / n) - 1.0)


def aprism_cfar_overlay(state: AprismCfarState, r: int, row: np.ndarray,
                        thold: np.ndarray, nf_est: np.ndarray,
                        free: Optional[np.ndarray] = None,
                        pi_occ: Optional[np.ndarray] = None) -> Tuple[float, float]:
    """Apply the A-PRISM CFAR overlay to one range row.

    Returns (ratio, floor_v).  Mirrors the guarded block in appl_cfar_ifc.c.
    """
    nad = row.size
    if free is None:
        free = np.ones(nad, dtype=np.uint8)
    if pi_occ is None:
        pi_occ = np.zeros(nad, dtype=float)

    aprism_dual_loop_floor(state, r, row, free, nad)
    floor_v = float(state.floor[r])
    if floor_v < 1.0:
        floor_v = 1.0

    snr = np.maximum(row / max(floor_v, EPS) - 1.0, 0.0)
    beta = np.zeros(nad, dtype=float)
    aprism_blue_weights(pi_occ, snr, beta)
    alpha_b = aprism_alpha_for_pfa(beta, nad, state.cfg.pfa)
    alpha_ca = aprism_ca_alpha(nad, state.cfg.pfa)
    ratio = (alpha_b / alpha_ca) if alpha_ca > 0.0 else 1.0
    ratio = min(max(ratio, 0.5), 2.0)

    nf_new = 0xFFFF if floor_v > 65535.0 else int(floor_v + 0.5)
    for i in range(nad):
        if ratio != 1.0:
            t = float(thold[i]) * ratio + 0.5
            thold[i] = 0xFFFFFFFF if t > 4294967295.0 else np.uint32(t)
        nf_est[i] = np.uint16(nf_new)
    return ratio, floor_v


def baseline_cfar_threshold(nf_est: np.ndarray, k: int = 4) -> np.ndarray:
    """Baseline CA-CFAR threshold: alpha * mean(reference cells) (no A-PRISM overlay)."""
    nf = np.asarray(nf_est, dtype=float)
    return aprism_ca_alpha(k, APRISM_CFAR_DEFAULT_PFA) * nf


# ---------------------------------------------------------------------------
# Gen8: A-PRISM CDC priority ranking  (cdc_priority.c / cdc_packing.c)
# ---------------------------------------------------------------------------


def cdc_priority_score(snr_db: float, range_m: float) -> float:
    """CdcPriorityScore: 10^(snr_db/10) / r^2 with r = max(range_m, 1)."""
    r = max(float(range_m), 1.0)
    return (10.0 ** (float(snr_db) / 10.0)) / (r * r)


def cdc_select_top_k(scores: np.ndarray, n: int, k: int, idx: np.ndarray) -> int:
    """CdcSelectTopK: partial selection, strictly-greater comparison (stable ties)."""
    scores = np.asarray(scores, dtype=float)
    k = min(int(k), int(n))
    if n <= 0 or k <= 0:
        return 0
    for i in range(n):
        idx[i] = i
    # NOTE: the inner bound is n (all candidates), matching CdcSelectTopK in
    # cdc_priority.c:33 (`for (j = i + 1; j < n; j++)`). Bounding it by k made
    # the mirror unable to promote any candidate from position >= k, so it
    # could only permute within the first k slots.
    for i in range(k):
        best = i
        for j in range(i + 1, n):
            if scores[idx[j]] > scores[idx[best]]:
                best = j
        if best != i:
            idx[i], idx[best] = idx[best], idx[i]
    return k


def baseline_cdc_order(count: int) -> np.ndarray:
    """Baseline packing emits detections in original (per-dbin) order."""
    return np.arange(count, dtype=np.int32)


# ---------------------------------------------------------------------------
# Gen8: A-PRISM ghost / specular contact inversion  (ghost_calib.c)
# ---------------------------------------------------------------------------


@dataclass
class GhostContact:
    q: Tuple[float, float] = (0.0, 0.0)     # foot of perpendicular on the ray
    a: Tuple[float, float] = (0.0, 0.0)     # specular contact point
    n: Tuple[float, float] = (0.0, 0.0)     # unit normal
    t: float = 0.0                          # ray parameter
    rho: float = 0.0                        # contact range from foot
    valid: bool = False


def ghost_inverse_contact(s: Sequence[float], p: Sequence[float],
                          u: Sequence[float], ell: float) -> GhostContact:
    """GhostInverseContact: closed-form specular contact inversion.

    Refuses the degenerate direct path (ell <= |p - s|); accepts the bistatic
    path (ell = 2r) whose return leg is consistent with the direct distance.
    """
    out = GhostContact()
    ulen = math.hypot(u[0], u[1])
    if ulen == 0.0:
        return out
    ux, uy = u[0] / ulen, u[1] / ulen
    dx, dy = p[0] - s[0], p[1] - s[1]
    d2 = dx * dx + dy * dy
    if ell * ell <= d2:
        return out                      # ell <= |d| -> degenerate
    ud = ux * dx + uy * dy
    B = ell - ud
    if B <= 1e-12:
        return out
    t = (ell * ell - d2) / (2.0 * B)
    if t <= 0.0 or t >= ell:
        return out
    rho = ell - t
    if rho <= 0.0:
        return out
    out.t = t
    out.rho = rho
    out.q = (s[0] + t * ux, s[1] + t * uy)
    ax = (p[0] - out.q[0]) / rho
    ay = (p[1] - out.q[1]) / rho
    out.a = (ax, ay)
    zx, zy = ax - ux, ay - uy
    nz = math.hypot(zx, zy)
    if nz == 0.0:
        return out                      # collinear a == u
    out.n = (zx / nz, zy / nz)
    out.valid = True
    return out


@dataclass
class GhostYawResult:
    valid: bool = False
    delta: float = 0.0      # relative boresight (rad)
    beta_i: float = 0.0
    beta_j: float = 0.0
    lmin: float = 0.0
    cmax: float = 0.0


def ghost_estimate_yaw(zd1, zg1, zd2, zg2, m, s1, s2) -> GhostYawResult:
    """GhostEstimateYaw: cross-spectral phase of the direct/ghost vector difference."""
    out = GhostYawResult()
    if m <= 0 or m > 4096:
        return out
    h_re = h_im = 0.0
    c1 = np.zeros(2)
    c2 = np.zeros(2)
    lmin = None
    for k in range(m):
        d1x, d1y = zd1[2 * k] - zg1[2 * k], zd1[2 * k + 1] - zg1[2 * k + 1]
        d2x, d2y = zd2[2 * k] - zg2[2 * k], zd2[2 * k + 1] - zg2[2 * k + 1]
        L = math.hypot(d1x, d1y)
        if L < 1e-12:
            return out
        lmin = L if lmin is None else min(lmin, L)
        h_re += d1x * d2x + d1y * d2y
        h_im += d1y * d2x - d1x * d2y
        c1 += 0.5 * np.array([zd1[2 * k] + zg1[2 * k], zd1[2 * k + 1] + zg1[2 * k + 1]])
        c2 += 0.5 * np.array([zd2[2 * k] + zg2[2 * k], zd2[2 * k + 1] + zg2[2 * k + 1]])
    if h_re == 0.0 and h_im == 0.0:
        return out
    out.delta = math.atan2(h_im, h_re)
    c1 /= m
    c2 /= m
    cmax = 0.0
    for k2 in range(m):
        mx = 0.5 * (zd2[2 * k2] + zg2[2 * k2])
        my = 0.5 * (zd2[2 * k2 + 1] + zg2[2 * k2 + 1])
        cmax = max(cmax, math.hypot(mx, my))
    out.cmax = cmax
    out.lmin = lmin if lmin is not None else 0.0
    B = (s2[0] - s1[0], s2[1] - s1[1])
    if math.hypot(*B) == 0.0:
        return out
    ca, sa = math.cos(out.delta), math.sin(out.delta)
    rb = (ca * c2[0] - sa * c2[1], sa * c2[0] + ca * c2[1])
    mean_b = (c1[0] - rb[0], c1[1] - rb[1])
    bx, by = mean_b
    out.beta_i = math.atan2(B[1] * bx - B[0] * by, B[0] * bx + B[1] * by)
    out.beta_j = out.beta_i + out.delta
    out.valid = True
    return out


def ghost_certify(eps: float, lmin: float, cmax: float, baseline: float):
    """GhostCertify: relative-boresight error certificate.

    Returns (ok, e_rel_deg, e_i_deg, e_j_deg) or (False, None, None, None).
    """
    if lmin <= 0.0 or baseline <= 0.0:
        return False, None, None, None
    rho = 4.0 * eps / lmin + (2.0 * eps / lmin) * (2.0 * eps / lmin)
    if rho >= 1.0:
        return False, None, None, None
    e_d = math.asin(min(rho, 1.0))
    eb = 2.0 * eps + 2.0 * cmax * math.sin(e_d / 2.0)
    if eb >= baseline:
        return False, None, None, None
    e_i = math.asin(min(eb / baseline, 1.0))
    return True, e_d * RAD2DEG, e_i * RAD2DEG, (e_i + e_d) * RAD2DEG


def hermite_solve2(xs, ys, slopes, c: np.ndarray) -> float:
    """HermiteSolve2: 2-point cubic Hermite fit; returns |det| scale (x2-x1)^4."""
    x1, x2 = float(xs[0]), float(xs[1])
    V = np.array([
        [1.0, x1, x1 * x1, x1 * x1 * x1],
        [0.0, 1.0, 2.0 * x1, 3.0 * x1 * x1],
        [1.0, x2, x2 * x2, x2 * x2 * x2],
        [0.0, 1.0, 2.0 * x2, 3.0 * x2 * x2],
    ], dtype=float)
    z = np.array([ys[0], slopes[0], ys[1], slopes[1]], dtype=float)
    try:
        c[:] = np.linalg.solve(V, z)
    except np.linalg.LinAlgError:
        c[:] = 0.0
        return 0.0
    h = x2 - x1
    return h * h * h * h


def clock_tau1(d, v, r: float, w: float) -> float:
    """ClockTau1: single-target clock offset (tau) from a range/Doppler pair."""
    den = v[0] * v[0] + v[1] * v[1]
    if den <= 0.0:
        return 0.0
    return (r * w - (d[0] * v[0] + d[1] * v[1])) / den


def clock_tau_bias2(a1, r1, y1, a2, r2, y2):
    """ClockTauBias2: two-target joint (tau, bias) solve. Returns (ok, tau, b)."""
    D = a1 * r2 - a2 * r1
    if D == 0.0:
        return False, 0.0, 0.0
    tau = (y1 * r2 - y2 * r1) / D
    b = (a1 * y2 - a2 * y1) / D
    return True, tau, b


# ---------------------------------------------------------------------------
# Gen8: A-PRISM dual-horizon dynamic alignment  (dyn_align_wrapper.c)
# ---------------------------------------------------------------------------

APRISM_DA_K_FAST = 0.05
APRISM_DA_K_SLOW = 0.0025
APRISM_DA_ALPHA = 0.1
APRISM_DA_LOCK_TOL_DEG = 0.05
APRISM_DA_LOCK_NEED = 10
APRISM_DA_MAX_UPDATES = 50


def da_dual_horizon_gain(k_fast: float, k_slow: float, alpha: float, n: int) -> float:
    """K_DA(n) = k_fast * exp(-alpha*n) + k_slow."""
    if n < 0:
        n = 0
    return k_fast * math.exp(-alpha * float(n)) + k_slow


def da_lock_detect(err_deg: float, tol_deg: float, hold_count: int, need: int) -> Tuple[bool, int]:
    """DaLockDetect: lock after `need` consecutive scans with |err| <= tol."""
    e = abs(err_deg)
    hold = hold_count + 1 if e <= tol_deg else 0
    return (hold >= need), hold


def baseline_da_update_counts(num_updates: int) -> int:
    """Baseline conservative M2D startup deadband (uncapped)."""
    return num_updates


def aprism_da_update_counts(num_updates: int) -> int:
    """A-PRISM preflight cap: lock completes in ~46 frames instead of ~400."""
    return min(num_updates, APRISM_DA_MAX_UPDATES)


# ---------------------------------------------------------------------------
# Gen8: A-PRISM residual beat estimator  (residual_track_ifc.c)
# ---------------------------------------------------------------------------


def rtr_wrap_half(d: float) -> float:
    """Wrap to [-0.5, 0.5) using round()."""
    return d - round(d)


def residual_lag1(x: np.ndarray, f_pred: float = 0.0) -> Tuple[float, int]:
    """ResidualLag1: baseline 2-point lag-1 residual phase.

    Returns (residual, n_real_mults).  n samples -> (n-1) complex multiplies
    -> 4 real multiplies each.
    """
    x = np.asarray(x, dtype=float).ravel()
    n = x.size // 2
    acc_re = acc_im = 0.0
    nmult = 0
    for i in range(1, n):
        a_re, a_im = x[2 * i], x[2 * i + 1]
        b_re, b_im = x[2 * (i - 1)], x[2 * (i - 1) + 1]
        acc_re += a_re * b_re + a_im * b_im
        acc_im += a_im * b_re - a_re * b_im
        nmult += 4
    return math.atan2(acc_im, acc_re) / TWO_PI, nmult


def residual_cubic4(x: np.ndarray, pred_incr: np.ndarray):
    """ResidualCubic4: 3-product cubic-exact 4-point residual stencil.

    Returns (fh, g_h2, l_h3, n_mult, invalid).
    """
    x = np.asarray(x, dtype=float).ravel()
    pred_incr = np.asarray(pred_incr, dtype=float).ravel()
    eta = np.zeros(3)
    maxamp = 0.0
    for j in range(4):
        a = abs(x[2 * j]) + abs(x[2 * j + 1])
        maxamp = max(maxamp, a)
    if maxamp == 0.0 or pred_incr.size < 3:
        return 0.0, 0.0, 0.0, 0, True
    nm = 0
    for j in range(3):
        a_re, a_im = x[2 * (j + 1)], x[2 * (j + 1) + 1]
        b_re, b_im = x[2 * j], x[2 * j + 1]
        c_re = a_re * b_re + a_im * b_im
        c_im = a_im * b_re - a_re * b_im
        nm += 4                      # exactly one complex multiply per lag
        meas = math.atan2(c_im, c_re) / TWO_PI
        eta[j] = rtr_wrap_half(meas - pred_incr[j])
    em, e0, ep = eta[0], eta[1], eta[2]
    fh = (26.0 * e0 - ep - em) / 24.0
    g_h2 = (ep - em) / 2.0
    l_h3 = ep - 2.0 * e0 + em
    return fh, g_h2, l_h3, nm, False


def residual_quant8(re: float, im: float, scale: float):
    """ResidualQuant8: int8 quantisation of a complex residual."""
    if scale <= 0.0:
        scale = 1.0
    t = int(round(re / scale))
    t = 127 if t > 127 else (-127 if t < -127 else t)
    tq = int(round(im / scale))
    tq = 127 if tq > 127 else (-127 if tq < -127 else tq)
    return t, tq, float(t) * scale, float(tq) * scale


def residual_quant_angle_bound(amplitude: float) -> float:
    """Worst-case vector error sqrt(1/2) LSB over amplitude."""
    if amplitude <= 0.0:
        return 0.0
    return math.asin(min(0.70710678 / amplitude, 1.0))


# ---------------------------------------------------------------------------
# DC tracker: A-PRISM hooks and gating  (aprism_ot_hooks.h / aprism_dc_hooks.h)
# ---------------------------------------------------------------------------

MIRROR_PROB = -1.0
MAXDET = 1024
GHOST_SIGMA_XI = 0.4
RANK1_TOL = 1.0
GAMMA_MIN = 9.21
GAMMA_MAX = 40.0


def adaptive_gamma(a_norm: float, innov_e: float, g0: float = GAMMA_MIN) -> float:
    """Adaptive_gamma: Gamma_ad = clamp(9.21*(1 + 0.8*a_norm + 0.5*innov_e), 9.21, 40)."""
    return float(np.clip(g0 * (1.0 + 0.8 * a_norm + 0.5 * innov_e), GAMMA_MIN, GAMMA_MAX))


def baseline_gamma(a_norm: float, innov_e: float) -> float:
    """Baseline gate: fixed threshold, no kinematic adaptation."""
    return GAMMA_MIN


def rank_gate_apply(ver: int, factor: float, qneed: int, qseen: int, confident: bool) -> Tuple[float, int]:
    """Rank_Gate_Apply: contamination-budgeted frozen-rank gate.

    Returns (scale, qseen).  Scale collapses to `factor` once `qneed`
    consecutive confident observations have been seen.
    """
    qseen = qseen + 1 if confident else 0
    if ver == 0 or qseen < qneed:
        return 1.0, qseen
    return factor, qseen


def doppler_gate(vr: float, ux: float, uy: float, vx: float, vy: float,
                 sig_v: float, s_v: float) -> bool:
    """Doppler_Gate: |v_r - u.v| <= 3*sqrt(sigma_v^2 + S_v)."""
    resid = abs(vr - (ux * vx + uy * vy))
    bound = 3.0 * math.sqrt(sig_v * sig_v + s_v)
    return resid <= bound


def entropy_scale(r0: float, H: float, snr: float, beta: float = 1.0) -> float:
    """Entropy_Scale: R <- R * exp(beta * H / snr)."""
    s = max(snr, 1e-6)
    return r0 * math.exp(beta * H / s)


def rank1_residual(px, py, sx, sy, nx, ny, d) -> float:
    """Rank1_Residual: || p - p_s - 2*d*n ||."""
    return math.hypot(px - sx - 2.0 * d * nx, py - sy - 2.0 * d * ny)


def virtual_sensor(nx, ny, d) -> Tuple[float, float]:
    """Virtual_Sensor: mirrored sensor position s = 2*d*n."""
    return 2.0 * d * nx, 2.0 * d * ny


def reff_inflate(r: float, jac: float, sig: float) -> float:
    """Reff_Inflate: R_eff = R + (J*sigma)^2."""
    return r + (jac * sig) ** 2


def curvature_ok(gp: float, k_max: float = 0.05, rho_max: float = 60.0) -> bool:
    """Curvature_Ok: |g'| <= 2*kappa_max*rho_max."""
    return abs(gp) <= 2.0 * k_max * rho_max


class TrackValidityFSM:
    """XOR sentinel contract: mirror_prob == -1.0 marks an assimilated track."""

    def __init__(self) -> None:
        self.mirror_prob = 0.0
        self.count = 0

    def update(self, paired: bool, double_bounce: bool, decay: float = 0.10,
               hold_below: float = 0.99, need: int = 10, curv_max: float = 0.01,
               curv: float = 0.0) -> None:
        if paired and double_bounce:
            self.mirror_prob = MIRROR_PROB
            self.count = 0
            return
        if self.mirror_prob == MIRROR_PROB:
            return                       # sentinel: never decay away
        self.mirror_prob -= decay
        if self.mirror_prob < hold_below or self.count < need or curv > curv_max:
            self.count = 0
        else:
            self.count += 1

    def is_assimilated(self) -> bool:
        return self.mirror_prob == MIRROR_PROB

    def resolve(self) -> None:
        if self.mirror_prob == MIRROR_PROB:
            self.mirror_prob = 0.0


class DetSidecar:
    """1024-entry detection sidecar marking assimilated detections."""

    def __init__(self) -> None:
        self.seen = np.zeros(MAXDET, dtype=np.uint8)

    def mark(self, idx: int) -> None:
        self.seen[idx & (MAXDET - 1)] = 1

    def marked(self, idx: int) -> bool:
        return self.seen[idx & (MAXDET - 1)] != 0

    def reset(self) -> None:
        self.seen[:] = 0


class ConfirmStore:
    """Two-scan confirmation counter for gated detections."""

    def __init__(self) -> None:
        self.count = np.zeros(MAXDET, dtype=np.uint8)

    def update(self, pid: int, n: int, gated: bool) -> int:
        if gated:
            self.count[pid & (MAXDET - 1)] = min(int(self.count[pid & (MAXDET - 1)]) + 1, 2)
        else:
            self.count[pid & (MAXDET - 1)] = 0
        return int(self.count[pid & (MAXDET - 1)])

    def confirmed(self, pid: int) -> bool:
        return self.count[pid & (MAXDET - 1)] >= 2

    def reset(self) -> None:
        self.count[:] = 0


# ---------------------------------------------------------------------------
# DC tracker: measurement update (CCA moveable + CTCA)
# ---------------------------------------------------------------------------


def kalman_update(st, H, R, z, P=None, F=None, Q=None):
    """Joseph-form Kalman update for the 6-state CCA moveable tracker.

    st : (x, vx, ax, y, vy, ay)
    P  : prior covariance (default: identity).  MUST be fed back from the
         previous step, otherwise the filter degenerates to a memoryless
         update and the error ellipse is meaningless.
    F, Q : optional predict step applied before the update (st <- F st,
           P <- F P F' + Q).

    Returns (st_new, P_new, K, innov, S).
    """
    st = np.asarray(st, dtype=float).copy()
    P = np.eye(6) if P is None else np.asarray(P, dtype=float).copy()
    if F is not None and Q is not None:
        st = np.asarray(F, dtype=float) @ st
        P = np.asarray(F, dtype=float) @ P @ np.asarray(F, dtype=float).T + np.asarray(Q, dtype=float)
    H = np.asarray(H, dtype=float)
    R = np.asarray(R, dtype=float)
    z = np.asarray(z, dtype=float)

    HPHt = H @ P @ H.T
    S = HPHt + R
    K = P @ H.T @ np.linalg.pinv(S)
    innov = z - H @ st
    st_new = st + K @ innov
    I_KH = np.eye(6) - K @ H
    P_new = I_KH @ P @ I_KH.T + K @ R @ K.T
    return st_new, P_new, K, innov, S


def cca_rr_measurement(st, R_rr_add: float = 4.0, crossing: bool = False,
                       n_dets: int = 1, k_ref: float = 1.0) -> float:
    """CCA moveable range-rate measurement: z = vx*cos + vy*sin."""
    _, vx, _, _, vy, _ = st
    return vx * math.cos(0.0) + vy * math.sin(0.0)


def ctca_covariance(n_dets: int, max_dets: int, k_ref: float,
                    entropy: float = 0.0, snr: float = 1.0, beta: float = 1.0) -> float:
    """CTCA measurement covariance with the A-PRISM spectral-entropy scaling."""
    if n_dets == 0:
        return float("inf")
    r = k_ref * (max_dets / float(n_dets))
    return entropy_scale(r, entropy, snr, beta)


def preflight_seed(az_rad: float, el_rad: float, qf: float,
                   max_az_deg: float = 5.0, max_el_deg: float = 2.0) -> Optional[Tuple[float, float]]:
    """DC-1 preflight DA header seeding.

    Accepts a header boresight when |az| <= 5 deg, |el| <= 2 deg and the
    quality factor is positive; otherwise falls back to the cold-start static
    estimate (-1.145, -0.018) degrees.
    """
    if qf > 0.0 and abs(math.degrees(az_rad)) <= max_az_deg and abs(math.degrees(el_rad)) <= max_el_deg:
        return az_rad * 0.0174532925, el_rad * 0.0174532925
    return -1.145 * 0.0174532925, -0.018 * 0.0174532925


def deskew(p, v, a, omega: float, dt: float):
    """DC-2 asynchronous deskew: p' = R_z(w*dt) p - v*dt - 0.5*a*dt^2."""
    th = omega * dt
    c, s = math.cos(th), math.sin(th)
    px, py = p[0], p[1]
    return (c * px - s * py - v[0] * dt - 0.5 * a[0] * dt * dt,
            s * px + c * py - v[1] * dt - 0.5 * a[1] * dt * dt)


# ---------------------------------------------------------------------------
# DC tracker: multipath / ghost disambiguation
# ---------------------------------------------------------------------------

MP_POISSON_LIMIT = 3.4
MP_ALPHA = 0.98


def mp_poisson_rate(events: int, t: float) -> float:
    """Multipath event rate estimate: lambda = (1 + events) / (1 + t)."""
    return (1.0 + events) / (1.0 + max(t, EPS))


def mp_is_elevated(events: int, t: float) -> bool:
    """True when the multipath event rate exceeds the production limit."""
    return mp_poisson_rate(events, t) > MP_POISSON_LIMIT


def xor_sentinel(mp_flag: bool, reflective_flag: bool) -> bool:
    """XOR guard: a detection is only multipath-marked when exactly one flag is set."""
    return mp_flag != reflective_flag
