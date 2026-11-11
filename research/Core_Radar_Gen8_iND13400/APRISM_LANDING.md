# A-PRISM Landing — Gen8 iND13400 Repo: Changes × Effects

Branch: `feature/aprism-landing` (off `dev`). Rule: everything new is
**default-OFF** (behavior identical until enabled), self-contained C99,
zero heap, host-verified with clang (`aprism_host_tests/run_host_tests.bat`,
RESULT: 0 failures). Full Bazel build + SiL mirror runs remain open
(no Xtensa toolchain on this host).

## Table 1 — Changes made in THIS repo and how each affects behavior

| # | File(s) changed | Research idea (Run) | What changed (mechanics) | Effect when enabled (measured in host test) | Effect when OFF (default) | Needs to activate |
|---|---|---|---|---|---|---|
| 1 | `rdd_proc/imp/src/appl_adaptive_cfar.h/.c` (new) | T1 dual-loop (2), N22g BLUE (23/30) | EMA floor λ=0.02 over track-free cells; R0∈{8,16,32} span switch; median×1/ln2; BLUE β=(m/v)/Σm²/v; bisection α solver; CA closed form | β=0.06872/0.00474 exact; α=13.299 in [13.2,13.4]; wall-masked floor holds 1.000; R0 boundaries exact | Zero: new code unreferenced | Row mapping (rdop_avg row + occupancy mask), `APRISM_ADAPTIVE_CFAR_ENABLE=1` |
| 2 | `rdd_proc/imp/src/appl_cfar_ifc.c` (hook) | same | #include + static state/flag + Init wiring + guarded `#if` integration block with mapping contract | None (block compiled out) | Identical to baseline (verified: no logic change outside `#if`) | Owner confirms `rdop_avg_t` LSB scale |
| 3 | `rdd_proc/imp/src/BUILD` | same | `appl_adaptive_cfar_lib` + `_ut_lib` targets | Build graph only | None | — |
| 4 | `rdd_proc/test/appl_adaptive_cfar_unit_test.cc` + `test/BUILD` | same | 3 gtest cases mirroring host asserts; added to `all_tests` | CI coverage | None | Bazel + gtest run on host |
| 5 | `src/residual_track_ifc.h/.c` (new) | N14 lag-1 (15), N23 stencil (26) | Lag-1 residual freq; cubic-exact 4-sample stencil (3 mults asserted); INT8 common-scale quant; angle bound | Stencil 0.1/0.02/0.006 to 1e-5; mults==3; bound 0.008839; invalid on zero/missing | Unreferenced (no hooks yet) | Tracker (f_pred) feed + call site in range/doppler flow |
| 6 | `src/cdc_priority.h/.c` (new) | F5 CDC saturation | Score s=SNR_lin/r²; stable top-k selection O(n·k) | Near-strong outranks far-strong; top-3 exact; null-safe | Unreferenced | Call in `cdc_packing.c` record loop |
| 7 | `dyn_alignment/ghost_calib.h/.c` (new) | N25/N26/N20g/N27 + DA fast-lock (17/24/25/28/22) | Yaw est + baseline closure; arcsin cert; contact inverse; Hermite 4×4; clock/bias; K_DA gain; lock detector | δ=-2.000000° exact; e_j=0.0607°<0.1; t=5 exact; Hermite det=1048576, c exact; τ=0.02 exact; gain 1.1→0.2 | Unreferenced | Ghost-pair observables feed from rdd/AF stages |
| 8 | `dyn_alignment/BUILD` | same | `ghost_calib_lib` target | Build graph only | None | — |
| 9 | `dyn_alignment/DA.md` | same | Fast-lock + ghost-calibration sections | Docs only | None | — |
| 10 | `emb_tracker/ghost_assoc_enabler.h/.c` (new) | N11 gate (4), N22g masks | Track-sigma Doppler score; occupancy/SNR row builder; 2-scan confirm counter | True 0.0146≤1, decoy 1.33>1; π=0.818/s=10.0; confirm 0-1-0-0 | Unreferenced | Call in wrapper detection loop (insertion point documented, not blind-edited) |
| 11 | `emb_tracker/BUILD` | same | `ghost_assoc_enabler_lib` target | Build graph only | None | — |
| 12 | `aprism_host_tests/` (new: 5 tests + `.bat`) | all above | clang-compiled assert harnesses replicating demo numbers | 0 failures (this run) | Test-only | — |

## Table 2 — Full research portfolio: DONE here vs MUST go to other repos

| # | Idea (novelty) | Verdict | Status here | Must be done in (repo → block) |
|---|---|---|---|---|
| 1 | T1 dual-loop CFAR (62) | keep-proto | §1 landed, OFF | — (complete pending mapping) |
| 2 | N22g Occupancy-BLUE (62) | keep-proto | §1 landed, OFF | occupancy predictor → object-tracker |
| 3 | N23/N14 residual (57/65) | discard/art | §5 landed as kernel | prediction feed → object-tracker |
| 4 | F5 CDC packing (infra) | keep | §6 landed | call-site wiring (this repo) |
| 5 | N11 Doppler gate (63) | discard/art | §10 quantities landed | association use → object-tracker |
| 6 | Fast-lock DA (70) | keep | §7 gain landed | schedule/conf tuning (this repo) |
| 7 | N25/N26/N20g calibration (58/60/68) | proto/unvalidated | §7 landed | observables feed (this repo) |
| 8 | N27 clock/bias (60) | discard/art | §7 landed | independent tracks → object-tracker |
| 9 | N19 driving align (67) | discard/art | formula in §7 path | — (covered by §7 module) |
| 10 | Run-14 ghost chain (**80**) | KEEP | enablers only (§10) | **full EKF: `core-radar-object-tracker/mb_tracker`** |
| 11 | N9 consensus (74) | KEEP | — (needs pair engine) | **same as 10** |
| 12 | N5 adaptive gate (71) | KEEP | — | **same as 10** |
| 13 | N24 rank gate (63) | proto | — | **same as 10** + calibration store |
| 14 | T5 spectral scaling (67) | proto | — | **same as 10** |
| 15 | Conformal (67) | proto | — | **same as 10**, fusion layer |
| 16 | Gram filter (60) | support/neg | — | **same as 10** (decoupled channels) |
| 17 | T3 async deskew (68) | proto | — | `Core_RESIM_DC_Emb_Library` + object-tracker |
| 18 | N28 replay/prefix-scan (58/64) | proto | — | `core-resim-hpcc`, `core-resim-engine` |
| 19 | KPI thresholds (infra) | keep | — | `Core_RESIM_KPI` (verification side) |
| 20 | RadarSplat/N16 (70/64) | keep-proto | — | `core-resim-sensor-model`, `core-resim-vv-engine` |
| 21 | Gen7/S32R47 ports | — | — | Gen7 repos / s32r47-signal-processing |
| 22 | N15 IMM (55) | REFUTED | documented, no code | nowhere |
| 23 | N21g-accuracy (—) | REFUTED | documented, no code | nowhere |

**Net effect summary:** with flags OFF, this repo behaves bit-identically to `dev`
(new code is unreferenced; the one modified `.c` only gains an `#include`,
static state, Init wiring, and a compiled-out block). Enabling each flag
buys the measured host-test effect in Table 1. Central-tracker wins
(rows 10–16) cannot land here by construction — satellite-side enablers
(§10) are their on-ramp.
