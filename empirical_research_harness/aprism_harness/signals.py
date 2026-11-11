"""Physics-grounded radar signal fixtures for the empirical harness.

Everything is generated from first principles so that BASELINE and A-PRISM see
bit-identical inputs:

  FMCW beat signal      x[n] = A * exp(j(2*pi*f_b*n*T_s + phi)) + w[n]
  Range                 r    = c * tau / 2,  tau = 2r/c
  Range-Doppler cell    power = SNR_lin * exp(-4*pi*r^4/(lambda^2*sigma^2))
  Speed                 v    = f_d * lambda / 2

No measurement is hardcoded: every "before" and "after" number in the results is
measured by running the mirrored kernels on these fixtures.
"""
from __future__ import annotations

import math
from dataclasses import dataclass
from typing import List, Optional, Sequence, Tuple

import numpy as np

C0 = 299_792_458.0
EPS = 1e-9


@dataclass
class FmcwConfig:
    """Waveform / sensor configuration (77 GHz automotive-class)."""
    bandwidth_hz: float = 4.0e9          # B
    chirp_time_s: float = 40.0e-6        # T_c
    carrier_hz: float = 77.0e9           # f_c
    num_chirps: int = 64
    num_fast_samples: int = 256          # N per chirp
    num_slow_samples: int = 32           # doppler FFT
    range_res_m: float = 0.35
    velocity_res_mps: float = 0.12
    noise_sigma: float = 0.35
    seed: int = 0

    @property
    def range_bin_m(self) -> float:
        return self.C0 / (2.0 * self.bandwidth_hz)

    @property
    def max_range_m(self) -> float:
        # Unambiguous range is set by the fast-time sample count: one range bin
        # per c/(2B) of delay across num_fast_samples bins.
        return self.range_bin_m * self.num_fast_samples

    @property
    def lambda_m(self) -> float:
        return self.C0 / self.carrier_hz

    @property
    def max_doppler_mps(self) -> float:
        return self.lambda_m / (4.0 * self.chirp_time_s)


@dataclass
class Target:
    """One point target in the sensor frame."""
    range_m: float
    speed_mps: float
    az_deg: float = 0.0
    el_deg: float = 0.0
    snr_db: float = 20.0
    rcs_m2: float = 10.0
    bistatic: bool = False
    double_bounce: bool = False
    label: str = ""


@dataclass
class Scene:
    """A synthetic scene: targets + clutter + noise configuration."""
    cfg: FmcwConfig
    targets: List[Target]
    n_clutter: int = 0
    clutter_snr_db: float = 5.0


def rng_for_seed(seed: int) -> np.random.Generator:
    return np.random.default_rng(seed)


def snr_db_to_lin(snr_db: float) -> float:
    return 10.0 ** (float(snr_db) / 10.0)


def fmcw_beat_signal(n: int, f_doppler_hz: float, fs: float, amp: float = 1.0,
                     phase: float = 0.0, sigma: float = 0.35,
                     rng: Optional[np.random.Generator] = None) -> np.ndarray:
    """Complex beat signal x[n] = A*exp(j(2*pi*f_d*n/fs + phi)) + w[n]."""
    if rng is None:
        rng = np.random.default_rng(0)
    t = np.arange(n, dtype=float) / fs
    clean = amp * np.exp(1j * (2.0 * np.pi * f_doppler_hz * t + phase))
    noise = sigma * (rng.standard_normal(n) + 1j * rng.standard_normal(n)) / math.sqrt(2.0)
    return clean + noise


def range_doppler_map(scene: Scene) -> Tuple[np.ndarray, np.ndarray, np.ndarray]:
    """Return (rd_map[range, doppler], range_axis_m, doppler_axis_mps)."""
    cfg = scene.cfg
    nr = int(round(cfg.max_range_m / cfg.range_bin_m))
    nd = cfg.num_slow_samples
    rd = np.zeros((nr, nd), dtype=float)

    rng = rng_for_seed(cfg.seed)
    for t in scene.targets:
        rbin = int(round(t.range_m / cfg.range_bin_m))
        if not (0 <= rbin < nr):
            continue
        vbin = int(round((t.speed_mps / cfg.max_doppler_mps) * (nd / 2.0)))
        vbin = int(np.clip(vbin, 0, nd - 1))
        sigma = cfg.range_res_m
        for r in range(max(0, rbin - 4), min(nr, rbin + 5)):
            dr = (r - rbin) * cfg.range_bin_m
            w = math.exp(-4.0 * math.pi * (t.range_m ** 4) /
                         ((cfg.lambda_m ** 2) * (sigma ** 2 + dr ** 2 + EPS)))
            rd[r, vbin] += snr_db_to_lin(t.snr_db) * w

    for _ in range(scene.n_clutter):
        rbin = int(rng.integers(0, nr))
        vbin = int(rng.integers(0, nd))
        rd[rbin, vbin] += snr_db_to_lin(scene.clutter_snr_db) * rng.uniform(0.3, 1.0)

    rd += cfg.noise_sigma * rng.standard_normal((nr, nd))
    rd = np.maximum(rd, 0.0)

    range_axis = np.arange(nr) * cfg.range_bin_m
    doppler_axis = np.linspace(-cfg.max_doppler_mps, cfg.max_doppler_mps, nd)
    return rd, range_axis, doppler_axis


def detection_stream(scene: Scene, n_dets: int = 64) -> dict:
    """Detection points in Cartesian sensor frame (range, az, el, snr, v)."""
    cfg = scene.cfg
    rng = rng_for_seed(cfg.seed + 1)
    xs, ys, zs, snrs, vs = [], [], [], [], []
    for _ in range(n_dets):
        t = scene.targets[int(rng.integers(0, len(scene.targets)))] if scene.targets else None
        if t is None:
            continue
        jitter = rng.normal(0.0, cfg.range_bin_m, 3)
        r = max(t.range_m + jitter[0], 0.1)
        az = math.radians(t.az_deg + float(rng.normal(0.0, 1.0)))
        el = math.radians(t.el_deg + float(rng.normal(0.0, 0.5)))
        horiz = r * math.cos(el)
        xs.append(horiz * math.cos(az))
        ys.append(horiz * math.sin(az))
        zs.append(r * math.sin(el))
        snrs.append(t.snr_db + float(rng.normal(0.0, 1.5)))
        vs.append(t.speed_mps + float(rng.normal(0.0, 0.05)))
    return {
        "x": np.asarray(xs), "y": np.asarray(ys), "z": np.asarray(zs),
        "snr_db": np.asarray(snrs), "v": np.asarray(vs),
    }


def specular_geometry(sensor, target, reflector):
    """Bistatic specular geometry: mirror the target about the reflector plane.

    Returns (p, u, ell) where p is the observed detection, u the unit ray from
    the sensor and ell the total path length (2r for a single bounce).
    """
    r = np.asarray(target, dtype=float) - np.asarray(sensor, dtype=float)
    n = np.asarray(reflector, dtype=float) - np.asarray(sensor, dtype=float)
    nn = float(np.dot(n, n))
    if nn < EPS:
        return r, np.array([1.0, 0.0]), 0.0
    n = n / math.sqrt(nn)
    d = float(np.dot(r, n))
    mirror = np.asarray(sensor, dtype=float) + (r - 2.0 * d * n)
    p = mirror - np.asarray(sensor, dtype=float)
    ell = 2.0 * float(np.linalg.norm(r))
    pn = float(np.linalg.norm(p))
    u = p / pn if pn > EPS else np.array([1.0, 0.0])
    return p, u, ell


def detection_geometry(target_xy, sensor=(0.0, 0.0)):
    """Direct-path geometry: (p, u, ell) with ell = |p - s|."""
    s = np.asarray(sensor, dtype=float)
    p = np.asarray(target_xy, dtype=float) - s
    d = float(np.linalg.norm(p))
    u = p / d if d > EPS else np.array([1.0, 0.0])
    return p, u, d


def ekf_truth_trajectory(n_steps: int, dt: float = 0.05,
                         accel_mps2: float = 0.0,
                         v0: float = 20.0) -> dict:
    """Constant-velocity (optionally accelerating) ground truth for KF tests."""
    t = np.arange(n_steps) * dt
    v = v0 + accel_mps2 * t
    x = v0 * t + 0.5 * accel_mps2 * t ** 2
    return {"t": t, "x": x, "v": v, "accel": np.full(n_steps, accel_mps2)}


def kf_measurements(truth: dict, rng: np.random.Generator,
                    sigma: float = 0.5) -> np.ndarray:
    """Noisy position measurements of the truth trajectory."""
    return truth["x"] + sigma * rng.standard_normal(truth["x"].size)


def accelerometer_stream(n: int, accel_mps2: float, sigma: float = 0.1,
                         rng: Optional[np.random.Generator] = None) -> np.ndarray:
    if rng is None:
        rng = np.random.default_rng(0)
    return accel_mps2 + sigma * rng.standard_normal(n)


def doppler_series(n: int, speed_mps: float, cfg: FmcwConfig) -> np.ndarray:
    """Doppler frequency series for a constant radial speed."""
    f_d = 2.0 * speed_mps / cfg.lambda_m
    return np.full(n, f_d)


def constellation_iq(speed_mps: float, cfg: FmcwConfig, n: int = 256,
                     sigma: float = 0.35,
                     rng: Optional[np.random.Generator] = None) -> np.ndarray:
    """Complex IQ beat samples for a target at constant radial speed."""
    if rng is None:
        rng = np.random.default_rng(cfg.seed)
    fs = 1.0 / (2.0 * cfg.chirp_time_s / cfg.num_slow_samples)
    f_d = 2.0 * speed_mps / cfg.lambda_m
    return fmcw_beat_signal(n, f_d, fs, 1.0, 0.0, sigma, rng)
