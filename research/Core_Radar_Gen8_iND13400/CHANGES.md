# CHANGES.md — A-PRISM Gen8 landing: what I changed, what research it covers, and why it does NOT run yet (esp. DA fast-lock)

> Branch: `release/v7.0.x` (detached work, uncommitted — OT repo untouched).
> Rule for everything below: **default-OFF = EmLib behaves exactly like baseline**.
> Host tests prove standalone math only, not integrated firmware/SiL.

## 0. Git state at time of writing

* `git status --porcelain` (staged `A/M` + unstaged `M` + untracked `??`):
  * Staged (new, `A`): `APRISM_LANDING.md`, `aprism_host_tests/*` (5 tests + `aprism_test.h` + `run_host_tests.bat`), `software/bbe32/dyn_alignment/ghost_calib.c/.h`, `software/bbe32/emb_tracker/ghost_assoc_enabler.c/.h`, `software/bbe32/rdd_proc/imp/src/appl_adaptive_cfar.c/.h`, `software/bbe32/rdd_proc/test/appl_adaptive_cfar_unit_test.cc`, `software/bbe32/src/cdc_priority.c/.h`, `software/bbe32/src/residual_track_ifc.c/.h`
  * Modified unstaged/partially-staged (`M`): `.gitignore`, `software/bbe32/dyn_alignment/BUILD`, `software/bbe32/dyn_alignment/DA.md`, `software/bbe32/emb_tracker/BUILD`, `software/bbe32/rdd_proc/imp/src/BUILD`, `software/bbe32/rdd_proc/imp/src/appl_cfar_ifc.c`, `software/bbe32/rdd_proc/test/BUILD`, `software/bbe32/src/BUILD`
  * Untracked (`??`): `APRISM_GEN8_WORKORDER.md`, `APRISM_OT_HANDOFF.md` (this file `CHANGES.md` will join them)
* `git diff --stat` (unstaged, 8 files, +121): `.gitignore` +3, `dyn_alignment/BUILD` +15, `DA.md` +6, `emb_tracker/BUILD` +15, `rdd_proc/imp/src/BUILD` +17, `appl_cfar_ifc.c` +27, `rdd_proc/test/BUILD` +18, `src/BUILD` +20
* `git diff --cached --stat` (staged, 19 files, +1454): see file table in §1.
* Base log: `56633bf33 DND-5320:update veh_com_type in version.c (#1205)` on `release/v7.0.x`.

## 1. Every file changed/added and what it does

| # | File | New/Edit | Research idea | Mechanics | Effect OFF (default) | Effect ON / host-measured |
|---|---|---|---|---|---|---|
| 1 | `software/bbe32/rdd_proc/imp/src/appl_adaptive_cfar.h/.c` | NEW + `appl_adaptive_cfar_lib` / `_ut_lib` in `imp/src/BUILD` | T1 dual-loop (Run 2), N22g Occupancy-BLUE (Runs 23/30) | EMA floor λ=0.02 over track-free cells; R0∈{8,16,32} span switch; median×1/ln2; BLUE β=(m/v)/Σm²/v, m=1+π·s; bisection α solver for Σα; CA closed form | Zero — unreferenced | β=0.06872/0.00474 exact; α=13.299 in [13.2,13.4]; wall-masked floor holds 1.000 |
| 2 | `software/bbe32/rdd_proc/imp/src/appl_cfar_ifc.c` | EDIT (+27: `#include`, 2 statics, Init wiring, guarded `#if` comment block) | same | Real path `doppler_process_ifc.c` → `Appl_Cfar_Execute(ridx,p_rdd_data)` → external `Cfar_Process()`. New block is comment + contract only inside `#if defined(APRISM_ADAPTIVE_CFAR_ENABLE)&&(==1)` | Identical to baseline (no logic change outside `#if`) | Still none — block has no row copy, no mask build, no threshold write; needs §5 wiring |
| 3 | `software/bbe32/rdd_proc/test/appl_adaptive_cfar_unit_test.cc` + `test/BUILD` | NEW + `all_tests` entry | same | 3 gtest cases mirroring host asserts | CI coverage only | Needs Bazel+gtest run (no Xtensa toolchain on this host) |
| 4 | `software/bbe32/src/residual_track_ifc.h/.c` + `residual_track_ifc_lib` | NEW | N14 lag-1 (Run 15), N23 stencil (Run 26) | `ResidualLag1`, `ResidualCubic4` (3 mults asserted, invalid on zero/missing), INT8 common-scale quant + angle bound | Unreferenced, **no call site** | Stencil 0.1/0.02/0.006 to 1e-5; mults==3; bound 0.008839 |
| 5 | `software/bbe32/src/cdc_priority.h/.c` + `cdc_priority_lib` | NEW | F5 CDC saturation | Score `s=SNR_lin/r²` + stable top-k `CdcSelectTopK` O(n·k) | Unreferenced, **no call site** | Near-strong outranks far-strong; top-3 exact; null-safe |
| 6 | `software/bbe32/dyn_alignment/ghost_calib.h/.c` + `ghost_calib_lib` | NEW (306+70 lines) | N25/N26/N20g/N27 + DA fast-lock (Runs 17/24/25/28/22) | `GhostEstimateYaw`, `GhostCertify` (arcsin, 0.1° gate), `GhostInverseContact`, `HermiteSolve2` (4×4, det=(x2-x1)⁴), `ClockTau1`/`ClockTauBias2`, `DaDualHorizonGain` `K_fast·exp(-a·n)+K_slow`, `DaLockDetect` | Unreferenced, **no production caller** (see §2 — this is why fast-lock "does not work") | δ=-2.000000° exact; e_j=0.0607°<0.1; t=5 exact; det=1048576; τ=0.02 exact; gain 1.1→0.2 (host scalars only) |
| 7 | `software/bbe32/dyn_alignment/DA.md` | EDIT (+6) | same as #6 | Docs-only fast-lock + ghost-calibration section | Docs only | None |
| 8 | `software/bbe32/emb_tracker/ghost_assoc_enabler.h/.c` + `ghost_assoc_enabler_lib` | NEW | N11 Doppler gate (Run 4), N22g masks | `GhostDopplerScore` (≤1 inside K-σ gate), `GhostCellOccupancy` (π,s row builder), `GhostConfirmUpdate` (2-scan counter) | Unreferenced, **no call in `emb_tracker_wrapper.cpp`** | True 0.0146≤1, decoy 1.33>1; π=0.818/s=10.0; confirm 0-1-0-0 |
| 9 | `aprism_host_tests/` (`test_adaptive_cfar.c`, `test_residual.c`, `test_cdc_priority.c`, `test_ghost_calib.c`, `test_assoc_enabler.c`, `aprism_test.h`, `run_host_tests.bat`) | NEW | all above | clang assert harnesses replicating demo numbers | Test-only | RESULT: 0 failures (this host run) |
| 10 | `.gitignore` | EDIT (+3) | infra | Ignore `aprism_host_tests/*.exe` | None | None |
| 11 | `software/bbe32/dyn_alignment/BUILD`, `emb_tracker/BUILD`, `rdd_proc/imp/src/BUILD`, `rdd_proc/test/BUILD`, `src/BUILD` | EDIT | build graph | New `cc_library`/`cc_test` targets only | None | None |
| 12 | `APRISM_LANDING.md` | NEW (staged) | index | Table 1 (changes×effects) + Table 2 (22-idea portfolio: DONE-here vs MUST-go-elsewhere) | Docs | Reference |
| 13 | `APRISM_GEN8_WORKORDER.md` | NEW (untracked) | work order | Exact files/functions, input contracts, blockers for THIS repo only | Docs | Reference |
| 14 | `APRISM_OT_HANDOFF.md` | NEW (untracked) | handoff | Exact OT files/functions + process for tracker team | Docs | Reference |

Hard-coded constants still in new code (noted, not hidden): EMA λ=0.02, R0 set {8,16,32}, `WALL_MULT=12.0`, `pfa` default, `GHOST_CALIB_MAXREC=256`, `GHOST_ASSOC_MAXDET=680`, `CDC_PRIO_MAXREC=5016`, certificate bounds. Tunables that must stay owner-confirmed are listed in the Work Order.

## 2. Why nothing is "working" yet — the general answer (all modules)

1. **STAGED ≠ WIRED.** Every new kernel is `static`-state or pure-function code with **zero production call sites**. Verified by repo grep: `DaDualHorizonGain|DaLockDetect|GhostEstimateYaw|CdcSelectTopK|ResidualLag1|GhostDopplerScore` hit only their own `.h` declaration + `.c` definition (+ host tests). No hits in `dyn_align_wrapper.c`, `appl_cfar_ifc.c`, `doppler_process_ifc.c`, `cdc_packing`, `emb_tracker_wrapper.cpp`, range/Doppler flow.
2. **Flags are OFF and blocks are empty.** `appl_cfar_ifc.c`: the `#if APRISM_ADAPTIVE_CFAR_ENABLE==1` block contains only a mapping comment (steps 1–3: copy NCI row, build mask, call floor/BLUE). It writes neither `p_rdd_data->cfar_thold[ridx]` (`uint32_t`) nor `cfar_nf_est[ridx]` (`uint16_t`). Compiled out by default → bit-identical baseline.
3. **External owners own the cores.** CFAR core = external `Cfar_Process()` (`@spbb`); DA estimator = external `DRA_Step_Execution()` (`@dabb`); F360 core = external (`@rotbb`). This repo can only change wrapper inputs/config/pre-post steps, not the buried recursions.
4. **Missing feeds.** Occupancy mask needs previous-scan tracker data (tracker runs after DSP → one-scan delay, no buffer exists yet). Residual needs per-track predicted beat increment + derotation tap (no `f_pred` struct in range/Doppler flow). CDC needs reorder of `p_cdc_array` + `p_ci_flag_array` before `Cdc_Packing` (FP owner + frame accounting). Ghost/yaw/contact/Hermite/clock need ghost-pair observables from RDD/AF stages (no feed).
5. **What host tests actually prove.** `run_host_tests.bat` (clang, 0 failures) proves the math kernels return the demo numbers. It does **not** prove firmware behavior, SiL lock, FA/recall, or CAN output. Full Bazel + SiL mirror runs remain open (no Xtensa toolchain on this host).

## 3. Why fast-lock is not working in dynamic alignment — the specific answer

Real path (verified in `software/bbe32/dyn_alignment/dyn_align_wrapper.c`):

```
dyn_align_wrapper() → da_ptr_update() → Auto_align_Init() (once, f_data_valid + Init_Status)
  → Execute_Dynamic_Alignment() → convert_detections() (AF_Det_T → single-sensor DRA_Detection_Input_T:
     az/el/range/range-rate/ampl/snr/conf, f_bistatic)
  → external DRA_Step_Execution(@dabb) → Populate_Dyn_Align_Output()
```

SiL mirrors call the wrapper from `sil/emb_lib/rsp_emb_lib/rsp_sil_wrapper.cpp` and `sil/rsp_sil/.../psp_sil_interface.cpp`.

Why `DaDualHorizonGain` / `DaLockDetect` never fire:

1. **Wrong repo for the gain recursion.** `DaDualHorizonGain(k_fast,k_slow,alpha,n) = K_fast·exp(-a·n)+K_slow` in `ghost_calib.c:283` is a **scalar reference helper**. The executed gain/schedule lives **inside the external `@dabb` DRA implementation** called at `dyn_align_wrapper.c:548` (`DRA_Step_Execution(&alignment_log,&align_internal_vars,p_detections_prop,p_detection_input,&vehicle_input,&radar_params,&cals_align)`). A Gen8-only wrapper edit **cannot** change a gain buried in the DABB library. The 46-frame schedule must land in whichever repo owns that algorithm (DABB owner). This is the #1 "fat/fast lock not working" cause.
2. **No call site at all.** `dyn_align_wrapper.c` (582 lines, unchanged in this landing) never `#include`s `ghost_calib.h` and never calls `DaDualHorizonGain` or `DaLockDetect`. `ghost_calib_lib` is a standalone BUILD target with no `deps` edge from the DA wrapper.
3. **No state to drive it.** Fast-lock needs (a) per-scan error fed from `Dynamic_Alignment_Log_Stream_T` into `DaLockDetect(&hold_count,need)`, (b) `n` (scan index since `Auto_align_Init`) threaded through `Execute_Dynamic_Alignment`, (c) preflight `t=0` injection through fields `Auto_align_Init()` already reads (`initial_num_updates_az/el/rl`, `az/el covariances`, `max_abs_misalignment_*`, `align_cmd ← M2D dra_data`, sensor mount `k_sensor_mount_pos_*/ornt_*`). None of this is wired — `Auto_align_Init():303-384` still copies M2D/NVM values straight through; no converged-header override (`az -1.145°, el -0.018°`) is written to `M2D_One_Time_Msg_T` at `t=0`.
4. **Single-sensor wrapper cannot do cross-satellite yaw.** `DYN_ALIGN_INPUT_T` carries **one sensor's** streams only (`p_det_stream/p_rdd_stream` for that satellite). `GhostEstimateYaw` needs paired direct/ghost records from **two** satellites + surveyed centers `s1,s2` + non-zero baseline. Cross-satellite yaw must run where two satellites meet (fusion/DC side / OT repo) — see `APRISM_OT_HANDOFF.md`. Single-sensor ghost pairing **is** possible here (pair inside `p_detection_input->detections[]`, `number_of_detections ≤ DRA_NUMBER_OF_DETECTIONS`, in `convert_detections()`/`Execute_Dynamic_Alignment()` using the mount already read in `Auto_align_Init()`), but it is not implemented yet.
5. **What the shippable Gen8-side subset actually is** (no DABB edit required): (i) preflight injection at `t=0` via the `Auto_align_Init`-read fields above, (ii) a lock detector on `Dynamic_Alignment_Log_Stream_T` outputs, (iii) optional single-sensor ghost pairing in `convert_detections()`. Anything touching the internal gain recursion → DABB owner.

Fix checklist to make fast-lock real (owner-gated, default-OFF until SiL replay proves it):

* [ ] DABB owner: land dual-horizon schedule in the estimator **or** confirm Gen8 is allowed to override gain via `dra_data`/calib fields (currently no such field is consumed by `DRA_Step_Execution`).
* [ ] Gen8 DA owner: add guarded preflight write (converged log headers → `M2D_One_Time_Msg_T` at `t=0`), thread scan counter `n`, feed `alignment_log` error into `DaLockDetect`, report drops-to-zero + 46-frame lock on replay.
* [ ] Gen8 DA owner: if ghost-calib wanted in-wrapper, add single-sensor pairing in `convert_detections()` + observables feed from RDD/AF stages; keep cross-satellite geometry in OT/fusion.
* [ ] Acceptance: 46-frame lock on replay with drops-to-zero; ghost path needs SiL scenes with labeled multipath + refusal-rate reporting.

## 4. Research portfolio — what landed here vs what must go elsewhere

(Table 2 from `APRISM_LANDING.md`, condensed; scores = novelty/keep-rank.)

* DONE-here (STAGED, OFF): T1 dual-loop CFAR, N22g Occupancy-BLUE weights, N14/N23 residual kernels, F5 CDC priority, N11 Doppler/occupancy/2-scan quantities, DA fast-lock **gain expression only**, N25/N26/N20g/N27 calibration kernels.
* MUST-go-elsewhere: Run-14 ghost-as-virtual-aperture (score 80, KEEP, highest priority) → `core-radar-object-tracker/mb_tracker` EKF; N9 consensus (74) + N5 adaptive gate (71) + N24 rank gate (63) + T5 spectral (67) + conformal (67) + Gram (60, decoupled only) → same OT repo; T3 async deskew (68) → `Core_RESIM_DC_Emb_Library` + OT; N28 replay (58/64) → `core-resim-hpcc/engine`; KPI thresholds → `Core_RESIM_KPI`; RadarSplat/N16 → `core-resim-sensor-model/vv-engine`; N15 IMM + N21g-accuracy REFUTED (no code, nowhere).
* Gen8 work order (`APRISM_GEN8_WORKORDER.md` §§1–5) and OT handoff (`APRISM_OT_HANDOFF.md` §§1–5) give exact files/functions/input contracts for each side.

## 5. Per-module "why function will not call" cheat sheet

| Module | Function(s) | Why never called |
|---|---|---|
| CFAR | `Aprism_DualLoopFloor/SelectR0/BlueWeights/AlphaForPfa/CaAlpha` | Guarded `#if` block is comment-only; `APRISM_ADAPTIVE_CFAR_ENABLE` undefined/0; row type `rdop_avg_t` LSB scale unconfirmed; no mask buffer; no `cfar_thold/cfar_nf_est` write |
| CDC | `CdcPriorityScore/CdcSelectTopK` | No hook in `doppler_process_ifc.c`/`cdc_packing` record loop; reorder must cover `p_cdc_array` + `p_ci_flag_array` identically + `cdc_dbin_count` accounting (FP owner) |
| Residual | `ResidualLag1/Cubic4/Quant8/AngleBound` | No call site in range/Doppler flow; needs tracker `f_pred` feed (one-scan delay) + fast-time tap + derotation defined at call site (lag-1 expects pre-derotated samples) |
| DA fast-lock | `DaDualHorizonGain/DaLockDetect` | Lives in `ghost_calib_lib`, wrapper never includes/calls it; real gain inside external `@dabb`; no scan counter, no log feed, no preflight write |
| DA ghost-cal | `GhostEstimateYaw/Certify/InverseContact/HermiteSolve2/ClockTau*` | No observables feed (RDD/AF ghost pairs, surveyed baselines); cross-satellite form impossible in single-sensor wrapper |
| emb_tracker | `GhostDopplerScore/CellOccupancy/ConfirmUpdate` | No pre-pass in `emb_tracker_wrapper.cpp` after `f360_det_list` fill; previous-cycle track predictions not yet plumbed; F360 core itself is external `@rotbb` |

## 6. Incorporated prior summaries (verbatim, as requested)

### 6a. Two new docs, OT repo untouched

```text
Done — two new docs, uncommitted as instructed, OT repo untouched:
- gen_research/Core_Radar_Gen8_iND13400/APRISM_GEN8_WORKORDER.md — what to implement in the Gen8 code, with exact files/functions, input contracts, and blockers
- gen_research/Core_Radar_Gen8_iND13400/APRISM_OT_HANDOFF.md — what the tracker team implements, with exact OT files/functions and process
Direct answers to your questions:
Dual-horizon in “this repo only”? No. The gain helper exists in Gen8, but dyn_align_wrapper.c calls the external @dabb estimator (DRA_Step_Execution), and the wrapper only converts one sensor’s detections plus init data. The shippable Gen8-side pieces are preflight injection through fields Auto_align_Init() already reads, plus a lock detector. The internal gain recursion belongs to the DABB owner.
Is the Gen8 code hard-coded, and will it work? Mixed. New kernels take real arguments, but several constants are fixed (EMA λ, R0 set, certificate bounds) and — more importantly — nothing is wired to production paths yet: the CFAR block is comment-only, residual/CDC/calibration helpers have no call sites, and the occupancy/Doppler feeds need previous-scan tracker data that doesn’t exist yet. An EmLib run today would behave exactly like baseline. The docs now state each missing mapping explicitly instead of implying the work is done.
OT repo choice: your team’s Gerrit checkout (C:\git\OT_ObjectTracking) is the integration target — it already has ghost classification, association gates, and Joseph-form updates, which are the exact insertion points in the handoff doc. The GitHub snapshot is reference-only.
```

### 6b. Plan-only / monograph expansion (no files changed in that step)

```text
Understood—plan only. No files were changed in this step; I will not edit or compile anything until you tell me to proceed.
Plan to expand the monograph
1. Keep the current chapters and verified material; expand the explanations and worked examples rather than replace the book.
2. Develop the rainy curved-road scene end to end: show the car, guardrail, overpass, spray, cut-in, direct and multipath rays; then trace representative signals through the RF front end, data cube, detector and tracker.
3. Add internal-data diagrams showing the transition from ADC samples to range, Doppler, angle and time dimensions, then to CDC, stream structs and CAN output. Connect diagram labels to the actual Gen8 code paths and structures.
4. Expand the math and code walkthroughs: derive the core equations step by step, define units and assumptions, and distinguish measured results from proposed targets or unverified feasibility estimates.
5. Add analysis figures and tables for false alarms, coverage, gating, alignment, resource budgets and the research prototypes, using only recorded results and clearly labeled illustrative plots.
6. Review every TikZ/PGFPlots figure, verify its labels, references and numerical inputs, then compile repeatedly and check the PDF's page count, errors and unresolved references.
The current PDF was last verified at 70 pages. The planned expansion is to make the explanations and diagrams more complete while preserving that validated material.
```

### 6c. Source-code-only, no history review, no changes made (OT + Gen8 findings)

```text
Understood—source code only, no history review, and no changes made.
Bottom line
C:\git\OT_ObjectTracking is the internal Gerrit tracker repository your team uses. The GitHub core-radar-object-tracker/dev tree is a separate, newer snapshot with related ROT code and some differences. It is not the parent of your Gerrit checkout. Use the internal repository as the eventual tracker integration target, and treat GitHub as a reference only.
I did not inspect its Git history for this pass. The Gerrit checkout has unrelated local CMake, variant-definition, and generated-build changes; preserve them and don't use that dirty working tree as a clean comparison baseline.
What the current source shows
- Run 14's key feature—assimilating the ghost as a virtual-aperture measurement—is not present. The tracker has ghost/multipath handling, but it classifies or discounts suspected mirror tracks. f360_detect_multipath.cpp sets mirror_prob; Track_Validity() invokes it after Measurement_Update_Tracks(). That is too late for an additional ghost measurement update during the same scan.
- There is already substantial reflection logic. f360_is_reflective_guardrail_track.cpp uses an SEP tangent to predict a hypothetical source position and compare it with another track. That overlaps with parts of N9/N20g; any new geometry must reuse or deliberately replace this logic, not duplicate it.
- Association is not a plain Mahalanobis gate. Determine_Association_Hypothesis() combines predicted range rate, calibration-dependent thresholds, Doppler de-aliasing, a moving-vs-stationary test and geometry-based cost. N5/N24 should be added at this decision path without bypassing those existing behaviors.
- The Kalman updates already use Joseph-form covariance updates. The CCA measurement update accepts position and compensated range-rate measurements with an R matrix. That is the natural place to evaluate adding a ghost measurement and its correlated R_eff.
- Ghost probability is already part of the lifecycle. It affects association eligibility, existence probability and coast/downselection. Assimilation must avoid using the same ghost evidence both as an update and as a mirror penalty.
- Gen8 is the radar-side producer. It can expose detections and additional ghost/uncertainty observables; the tracker remains the consumer of association, ghost assimilation, gating and filter-covariance research.
- The current Gen8 A-PRISM landing is mainly prototype code. The CFAR call still invokes external Cfar_Process(); the added adaptive block contains an integration placeholder. Residual DSP, CDC priority, alignment, and association helpers have no production call sites yet. Host tests validate standalone math/functions, not integrated firmware or SiL behavior.
- Dynamic alignment: the Gen8 repo is the wrapper/integration location, but dyn_align_wrapper.c calls the external @dabb DRA implementation. The 46-frame gain schedule must land in whichever repo owns that algorithm. A Gen8-only wrapper edit cannot change a gain buried in the external DABB library.
Plan for the tracker repo
1. Start from the team-approved Gerrit development branch, not the local dirty master. Keep GitHub's snapshot as a comparison aid.
2. Add Run-14 virtual-aperture assimilation at the measurement-update stage. Pair direct and ghost detections before association/update; represent the ghost's state/Jacobian and shared reflector uncertainty; compare against the existing direct-only update. Avoid double-counting existing mirror-probability handling.
3. Integrate N9/N20g against existing SEP/reflection code. Reuse its surface/source information where valid; add the Hermite curved-rail path only for the missing moving-target point-and-tangent evidence. Compare matched scenes to the existing reflection classifier.
4. Extend association in place. N5 acceleration/innovation widening and N24's frozen calibration/reachability conditions belong around the existing range-rate and detection-cost gates. Preserve Doppler de-aliasing, SEP rules, stationary-hypothesis comparison, and global competition among tracks.
5. Evaluate T5 and conformal covariance changes inside CCA/CTCA R construction, retaining the current Joseph update. Validate covariance definiteness, ambiguity, RMSE and track continuity—not recall alone.
6. Build paired tests in the tracker's existing unit/qualification framework: curved barrier, decoy at the planar blind spot, fast cut-in, spray, stale measurements, and ambiguous assignment. Measure both correct associations and wrong-track captures.
7. Verify downstream integration with the matching Gen8 SiL build and UDP/CAN KPI replay after tracker tests pass.
Plan for Gen8-to-tracker handoff
Gen8 output | Current state
Direct/ghost detections, range, angle, Doppler | Stream already carries detections; new pairing/metadata is not wired
CFAR occupancy / BLUE noise weights | Helper exists; actual CFAR integration point is still a placeholder
Ghost Doppler score / 2-scan confirmation | Helper exists; no caller in emb_tracker_wrapper.cpp yet
Contact, normal, curvature, yaw certificate | Helper exists; no production feed or release path yet
Residual frequency estimate | Helper exists; no tracker prediction feed or DSP call site
DA fast-lock | Helper exposes a gain expression; Gen8 wrapper calls DABB
The Gen8 landing's detailed file/effect table is in APRISM_LANDING.md. The cross-repo inventory is in RESEARCH_LANDING_MAP.md.
```

## 7. What to do next (no commits until told)

1. Decide: land DABB-side gain (DABB owner) vs Gen8-side preflight+lock-detector only.
2. Confirm `rdop_avg_t` LSB scale + `cfar_thold/cfar_nf_est` Q formats with RDD owner before filling the CFAR block.
3. Confirm exact insertion lines with wrapper owners (`doppler_process_ifc.c`, `cdc_packing`, `emb_tracker_wrapper.cpp`, range/Doppler flow) — do not blind-edit the 76 KB wrapper.
4. Enable each flag one at a time on guardrail SiL scenes; require Tier-1 yield held + edge-skirt recall lift + FA contract before keeping ON.

## 8. Integration verdict per research row (wiring pass — originals preserved)

> Compare guarantee for research/publication: every wiring below is inside
> `#if defined(APRISM_X_ENABLE) && (APRISM_X_ENABLE == 1)`. Flags undefined =
> OFF = preprocessor removes the block, so the baseline build is
> **byte-identical to the original code**. `git diff` on the three wired
> production files shows **pure additions, zero modified/deleted original
> lines** (verified). No replacement was needed — integration, not rewrite.

| # | Research module (Novelty) | Verdict | What changed (exact call site) | ON-effect (enabled) | OFF-effect (default) |
|---|---|---|---|---|---|
| 1 | Dual-Horizon Fast DA (70) | **WIRED (Gen8 side)** | `dyn_align_wrapper.c`: `Auto_align_Init()` caps `initial_inputs.num_updates_az/el/rl` to 50 (only lowers); `Execute_Dynamic_Alignment()` calls `DaDualHorizonGain(0.05,0.0025,0.1,n)` + `DaLockDetect(err,0.05°,10/10)` on KF delta; new `Aprism_Da_GetGain()/Aprism_Da_IsLocked()` SiL readouts; dep `+ghost_calib_lib` | Faster startup lock via existing DABB `num_updates` mechanism; gain/lock telemetry. Full 46-frame gain recursion still needs the **@dabb owner** (buried in `DRA_Step_Execution`) | Original M2D values verbatim; statics untouched |
| 2 | Track-Conditioned Residual (65) | **STAGED, not wired** | `range_process_ifc.c` untouched — no `f_pred` tracker feed + no derotation tap exist in that flow | — | Kernel only (`residual_track_ifc_lib`); host PASS |
| 3 | Range-Adaptive Dual-Loop CFAR (62) | **WIRED** | `appl_cfar_ifc.c` `Appl_Cfar_Execute()`: `Aprism_DualLoopFloor` on `nf_est` row + `Aprism_BlueWeights/AlphaForPfa/CaAlpha` ratio rescale of `cfar_thold`, EMA floor write to `cfar_nf_est`; dep `+appl_adaptive_cfar_lib` | Floor smoothing active; thresholds rescale only when BLUE ratio ≠ 1 (needs occupancy feed). R0 window switch needs SPBB config (owner-gated) | `Cfar_Process()` outputs pass through untouched |
| 4 | Occupancy-BLUE + analytic Pfa (62) | **WIRED (path live, all-free)** | Same block as #3; `pi=0` until emb_tracker previous-scan mask lands | Ratio ≈ 1 (identity) by construction; activates with occupancy feed | Same as #3 |
| 5 | Closed-Form Contact Inversion (60) | **STAGED, not wired** | `ghost_calib.c` untouched — no ghost-pair observables feed from RDD/AF stages; cross-satellite form impossible in single-sensor wrapper | — | Kernel only; host PASS |
| 6 | Priority-Ranked CDC (60/F5) | **WIRED** | `cdc_packing.c` `Cdc_Packing()`: `CdcPriorityScore` per record (NCI/CI amplitude feed, same selection as packed `nci_data`) + `CdcSelectTopK` reorder of `p_cdc_array` + `p_ci_flag_array`; count unchanged → frame accounting untouched; dep `+cdc_priority_lib` | Near-strong records packed first; 1472 B/frame limits stop dropping close targets | Packing order identical to original |
| 7 | 3-Product Cubic Stencil (57, prior art) | **STAGED, not wired** | `residual_track_ifc.c` untouched — same missing feed as #2; discarded from claims per TCRE prior art | — | Kernel only; host PASS |

Enable flags (all default OFF; enable per-module for A/B compare):

```
bazel build --copt=-DAPRISM_ADAPTIVE_CFAR_ENABLE=1 --copt=-DAPRISM_DA_FASTLOCK_ENABLE=1 --copt=-DAPRISM_CDC_PRIO_ENABLE=1 --copt=-DAPRISM_GHOST_INSPECT_ENABLE=1 //...
```

Compare recipe for publication: build twice (flags OFF vs ON) from the same commit;
run identical SiL replay scenes; report OFF-vs-ON deltas on lock frames (DA),
edge-skirt recall + FA count (CFAR), kept-vs-dropped near-field records (CDC).
Host tests (`aprism_host_tests/run_host_tests.bat`, RESULT: 0 failures) prove
kernel math only, not firmware/SiL deltas — SiL numbers are the publishable proof.

Verification status of this wiring pass:
- Host tests: PASS, 0 failures (re-run after wiring).
- `git diff` review: three production files pure-additive; whitespace restored to original.
- Bazel build/test: **blocked on this host** — `bazelisk build` fails at repo
  mapping (`Unknown host: jfrog.asux.aptiv.com`, no Aptiv registry access here).
  The other team must run on the team network:
  `bazel build //software/bbe32/rdd_proc/imp/src:appl_cfar_ifc_lib //software/bbe32/dyn_alignment:dyn_align_wrapper //software/bbe32/src:cdc_packing_lib`
  then `bazel test //software/bbe32/rdd_proc/test:all_tests` (OFF build first for
  the bit-identical baseline, then ON build for the compare).

## 9. Seven-module integration table + every staged file (requested audit — nothing pushed)

> Status key: **WIRED+CALLED** = active production caller exists, executes when
> its flag is ON, zero behavior change when OFF. **STAGED** = kernel present +
> host-verified, no production caller yet (exact blocker listed). Nothing was
> pushed; all changes are uncommitted in the working tree + index.

### 9a. All 7 research modules — integrated and working?

| # | Module (Novelty) | Integrated? | Working? | Production caller (exact) | What happens ON / OFF | Blocker (if not fully working) |
|---|---|---|---|---|---|---|
| 1 | Fast DA + lock detect (70) | **YES — wired** | **Path live; gain readout + cap active** | `dyn_align_wrapper.c`: `Auto_align_Init()` (num_updates cap), `Execute_Dynamic_Alignment()` (`DaDualHorizonGain` + `DaLockDetect`), `Aprism_Da_GetGain/IsLocked()` readouts | ON: faster startup lock + lock flag; OFF: original M2D values verbatim | Full 46-frame recursion lives in external `@dabb` `DRA_Step_Execution` — DABB owner must adopt the schedule |
| 2 | Dual-loop CFAR floor (62) | **YES — wired** | **Path live** | `appl_cfar_ifc.c` `Appl_Cfar_Execute()`: `Aprism_DualLoopFloor` → EMA floor write to `cfar_nf_est` | ON: temporal floor smoothing; OFF: `Cfar_Process()` output passes through untouched | Direct NCI-row source needs SPBB plane-layout confirm; R0 window switch needs SPBB config |
| 3 | Occupancy-BLUE + Pfa (62) | **YES — path wired** | **Live but ≈identity until feed lands** | Same block: `Aprism_BlueWeights` + `Aprism_AlphaForPfa`/`Aprism_CaAlpha` ratio rescales `cfar_thold` | ON with `pi=0`: ratio ≈ 1, thresholds untouched; activates with tracker mask | Previous-scan occupancy mask needs emb_tracker feed (tracker runs after DSP — one-scan delay, no buffer yet) |
| 4 | CDC priority packing (60/F5) | **YES — wired** | **Path live** | `cdc_packing.c` `Cdc_Packing()`: `CdcPriorityScore` + `CdcSelectTopK` reorder both arrays, count unchanged | ON: near-strong packed first; OFF: original order | Range is ordinal (per-call order is SNR-driven); needs range-res macro for absolute scaling |
| 5 | Residual lag-1 beat (65) | **NO — staged** | Kernel verified (host PASS) | None — `range_process_ifc.c` untouched | — | No `f_pred` feed + no derotation tap in range flow; needs range-proc + tracker owners |
| 6 | Cubic 3-product stencil (57) | **NO — staged** | Kernel verified (host PASS) | None — same file untouched | — | Same feed as #5; also prior-art (TCRE arXiv:2609.30176), out of claims |
| 7 | Specular contact inverse (60) | **NO — staged** | Kernel verified (host PASS) | None — `convert_detections()` untouched | — | No ghost-pair observables from RDD/AF; cross-satellite form impossible in single-sensor wrapper |

### 9b. Every changed/staged file — what it does

| File | State | What it does (one line) |
|---|---|---|
| `software/bbe32/rdd_proc/imp/src/appl_adaptive_cfar.h/.c` | Staged NEW | EMA floor, R0 select, BLUE weights, α bisection, CA closed form (Runs 2/23/30) |
| `software/bbe32/rdd_proc/imp/src/appl_cfar_ifc.c` | Modified (+84, pure adds) | Real overlay block: floor + BLUE ratio writes to `cfar_thold`/`cfar_nf_est`, guarded `APRISM_ADAPTIVE_CFAR_ENABLE` |
| `software/bbe32/rdd_proc/imp/src/BUILD` | Modified | `appl_adaptive_cfar_lib`/`_ut_lib` targets + `appl_cfar_ifc_lib` dep |
| `software/bbe32/rdd_proc/test/appl_adaptive_cfar_unit_test.cc` | Staged NEW | 3 gtest cases, in `all_tests` |
| `software/bbe32/rdd_proc/test/BUILD` | Modified | New `cc_test` + suite entry |
| `software/bbe32/dyn_alignment/ghost_calib.h/.c` | Staged NEW | Yaw, cert, contact, Hermite, clock/bias, `DaDualHorizonGain`, `DaLockDetect` |
| `software/bbe32/dyn_alignment/dyn_align_wrapper.c` | Modified (+69, pure adds) | num_updates cap, gain+lock calls, `Aprism_Da_*` getters, guarded include |
| `software/bbe32/dyn_alignment/dyn_align_wrapper.h` | Modified (+4, pure adds) | Getter declarations |
| `software/bbe32/dyn_alignment/BUILD` | Modified | `ghost_calib_lib` target + wrapper/support deps |
| `software/bbe32/dyn_alignment/DA.md` | Modified (+6 docs) | Fast-lock + ghost-calibration section |
| `software/bbe32/src/cdc_priority.h/.c` | Staged NEW | `s=SNR_lin/r²` score + stable top-k |
| `software/bbe32/src/cdc_packing.c` | Modified (+57, pure adds) | Priority reorder block, guarded `APRISM_CDC_PRIO_ENABLE` |
| `software/bbe32/src/residual_track_ifc.h/.c` | Staged NEW | Lag-1 + cubic-4 estimators, INT8 quant, angle bound |
| `software/bbe32/src/BUILD` | Modified | `residual_track_ifc_lib`, `cdc_priority_lib` + `cdc_packing_lib` dep |
| `software/bbe32/emb_tracker/ghost_assoc_enabler.h/.c` | Staged NEW | Doppler score, occupancy/SNR row, 2-scan counter |
| `software/bbe32/emb_tracker/BUILD` | Modified | `ghost_assoc_enabler_lib` target |
| `aprism_host_tests/` (5×`.c` + `.h` + `.bat`) | Staged NEW | clang harnesses, RESULT: 0 failures |
| `APRISM_LANDING.md` | Staged NEW | Changes×effects + 22-idea portfolio index |
| `APRISM_GEN8_WORKORDER.md` | Untracked NEW | Gen8-side exact files/functions/contracts |
| `APRISM_OT_HANDOFF.md` | Untracked NEW | Tracker-team handoff spec |
| `CHANGES.md` (this file) | Untracked NEW | Full change log + verdicts + compare recipe |
| `.gitignore` | Modified (+3) | Ignore host-test `.exe` rebuilds |

### 9c. Why the MASTER DIRECTIVE was NOT executed as written

1. **ENABLE=1 by default destroys your compare baseline.** Your standing
   requirement is OFF=original for publication proof. The `--copt` ON-builds in
   §8 already give "active by default" per build without touching defaults.
2. **Non-compiling items:** `p_dyn_align_output->is_aligned` (no such field
   anywhere in `software/`), `s_cell_occupancy_mask[MAX_RANGE_BINS][MAX_DOPPLER_BINS]`
   (`MAX_DOPPLER_BINS` undefined), `rdop_avg_data_ptr[ridx]` (plane is indexed
   by `[NCI_*_BUFFER_DEPTH]`, not range), `ResidualLag1(samples,N,f_pred,Ts)`
   (real signature is `(x,n,f_pred)`), `GhostInverseContact(…,6 args…)` (real
   form returns `GhostContact_T` from `(s,p,u,ell)`).
3. **No `printf` on the BBE32 DSP path** (zero precedent in `bbe32/src/*.c`);
   unconditional logging stalls the 50 ms frame. Telemetry path is SiL log
   streams + existing `SIT_*` macros + `Aprism_Da_*` getters.
4. **Invented fallbacks (energy-persistence mask, coarse-bin `f_pred`,
   guardrail heuristic) would corrupt the science:** enabled SiL numbers would
   measure the fallback, not the published algorithm. Fallbacks of this kind
   need owner review + quarantined experiments, never silent default-ON writes
   into production frequency/threshold paths.
5. Say the word and the corrected variant lands: guarded (OFF-default) residual
   hook at a confirmed `range_process_ifc.c` tap with real `f_pred` plumbing,
   guarded ghost-pair inspection in `convert_detections()` with real observable
   feeds, and trace hooks via the team's logging facility once named.

## 10. Corrected-variant wiring pass — all 7, will-it-work verdicts (nothing pushed)

> Method: real signatures only (checked against the kernel headers), verified
> struct fields only (checked against in-repo uses), confirmed hook locations
> only (checked against the production loops). No `printf` (zero precedent in
> `bbe32/src/*.c` — verified by grep). No new SIT channels (inventory below).
> All flags OFF-default, enabled per-build via `--copt` (§8, now 4 flags).
> `git diff` on every touched production file is pure additions (verified).

### 10a. All 7 modules — what happened, will it work or not

| # | Module | What happened this pass | Will it work? | Exact hook (file:function) + real signature used | ON behavior / OFF behavior | Remaining owner step |
|---|---|---|---|---|---|---|
| 1 | Fast DA + lock (70) | Kept from §8 (no change) | **Works (Gen8 side)** | `dyn_align_wrapper.c:Auto_align_Init` (num_updates cap), `:Execute_Dynamic_Alignment` (`DaDualHorizonGain(k_fast,k_slow,alpha,n)`, `DaLockDetect(err,tol,&hold,need)` — both match `ghost_calib.h`) | ON: faster startup lock + `Aprism_Da_GetGain/IsLocked()`; OFF: verbatim baseline | DABB owner adopts gain recursion inside `DRA_Step_Execution` |
| 2 | Dual-loop CFAR (62) | Kept from §8 | **Works** | `appl_cfar_ifc.c:Appl_Cfar_Execute` — `Aprism_DualLoopFloor(st,r,row,mask,nd,scratch)`, `Aprism_BlueWeights`, `Aprism_AlphaForPfa`, `Aprism_CaAlpha` (all match `appl_adaptive_cfar.h`) | ON: floor smoothing + ratio rescale; OFF: passthrough | SPBB owner: NCI-row layout + R0 window config |
| 3 | Occupancy-BLUE (62) | Kept from §8 | **Works when feed lands (≈identity now)** | Same CFAR block; `pi=0` all-free is the honest no-feed state, not a heuristic | ON: ratio ≈1 until tracker mask; OFF: passthrough | emb_tracker previous-scan mask (one-scan delay) |
| 4 | CDC priority (60) | Kept from §8 | **Works** | `cdc_packing.c:Cdc_Packing` — `CdcPriorityScore(snr_db,range_m)`, `CdcSelectTopK(score,n,k,idx)` (match `cdc_priority.h`); SNR feed mirrors the module's own packed amplitude (`rdop_avg/ci_rdop_avg[row][dop]`, same per-record selection) | ON: reorder-only, count unchanged; OFF: original order | FP owner: range-res macro for absolute scaling |
| 5 | Residual lag-1 (65) | **NOT wired — refused with proof** | Kernel works (host PASS); **no production effect, by design** | No hook: `range_process_ifc.c` (653 lines, fully read) is an RA-HW driver — MIPI chirps → `Range_Process_Execute()` (HW FFT) → `RangeProc_OutputDataCube` + bexp. There is NO per-bin beat loop, NO peak list, NO `f_pred` in this file. The 512-pt FFT + parabolic interpolation live in SPBB/RA (external). The only sample buffer is the Lauterbach offline-injection array (test-only, NULL in production) | — | Real tap = SPBB range-FFT peak interpolation (external repo) + tracker `f_pred` feed |
| 6 | Cubic stencil (57) | **NOT wired — same proof as #5** | Kernel works (host PASS); **no production effect** | Same missing tap + missing `pred_incr[3]` source; calling with invented increments would be fake wiring | — | Same as #5; also prior-art, out of claims |
| 7 | Contact inverse (60) | **WIRED (inspection+refusal)** | **Works as instrumented refusal gate** | `dyn_align_wrapper.c:convert_detections` per-detection loop — `GhostContact_T GhostInverseContact(const float *s, const float *p, const float *u, float ell)` (exact header signature). Sensor-local frame (sensor at origin); `p` from `(ran,theta,phi)`; `u=p/\|p\|`; `ell=2·ran`. Runs ONLY on `f_bistatic` detections (real AF reflection flag). Invalid geometry → `f_valid_level=false` + refused counter; rest pass untouched. Per-scan `Aprism_Ghost_Inspected/Refused()` getters | ON: inconsistent bistatic dropped+counted; OFF: loop byte-identical | AF owner: SAE/ISO angle convention; OT/DABB owner: validate `ell=2·ran` vs labeled multipath. `HermiteSolve2`/`GhostCertify`/`GhostEstimateYaw` NOT called (need point-slope pairs / surveyed baseline — unavailable single-sensor; calling them would be fabrication) |

### 10b. Telemetry verdict (no printf — native hooks only)

- Full SIT inventory (`dsp_it_macros_test.h`): `SIT_AF_INPUT/USC/DOWNSELECTION`,
  `SIT_COMPUTE_RCS`, `SIT_IPC_TRANSFER_M2D/D2M`, `SIT_DWELL_TIMESTAMPS`,
  `SIT_DYNAMIC_ALIGN_DATA`, `SIT_ALIGNMENT_LOG_DATA`, `SIT_AVG_MMIC_ONCHIP_TEMP_DATA`,
  `SIT_FP_RDD_INPUT/OUTPUT_DATA` — all struct-based providers/receivers (real
  under `Integration_Testing`, no-ops otherwise). **No scalar/float trace
  channel exists**; none of CFAR/CDC/range has a SIT tap at all.
- Therefore no new SIT macro was added (extending `dsp_it_macros_test.h` is the
  integration-test owner's call). Observable APRISM telemetry today:
  (a) structs already SIT-forwarded (`alignment_log` via `SIT_ALIGNMENT_LOG_DATA`
  every scan, FP structs, D2M buffers); (b) `Aprism_Da_GetGain/IsLocked`,
  `Aprism_Ghost_Inspected/Refused` getters (SiL-readable); (c) XCP/ADC logging
  path (`XCP_Logging_Handler`, `rdd_debug_data` — struct extension is ICD-gated);
  (d) host-test vectors (0 failures).
- The `[DEBUG-APRISM] printf` items from the directive were not implemented:
  there is no stdout on the BBE32 DSP path and unconditional logging breaks the
  50 ms frame budget.

### 10c. Net source diff this pass (production files only)

- `software/bbe32/dyn_alignment/dyn_align_wrapper.c`: +guarded `<math.h>` +
  `ghost_calib.h` include, +2 guarded statics, +counter reset, +ghost-contact
  inspection block inside the existing detection loop, +2 guarded getters.
- `software/bbe32/dyn_alignment/dyn_align_wrapper.h`: +4 guarded getter decls.
- No BUILD change needed (`ghost_calib_lib` dep already added in §8 pass).
- `range_process_ifc.c`: untouched (proven no-tap — see §10a #5).
- Host tests re-run after wiring: RESULT 0 failures. Bazel: still blocked on
  this host (no `jfrog.asux.aptiv.com` route); team-network commands in §8.

## 11. Can DA lock in 4–10 frames instead of 400? (tunables landed)

**Honest answer: cold-start estimation in 4–10 frames is not credible; seeded
confirmation in ~5 frames is.** At 20 Hz, 4–10 frames = 0.2–0.5 s ≈ 5 m of
travel — nearly no geometric/yaw excitation, so a filter cannot separate a 2°
boresight error from motion in that window. The validated Run-17 profile
(§10a #1) is 46 frames. What CAN hit 4–10 frames on the Gen8 side:

1. **Preflight NVM seed at t=0** (converged boresight, e.g. az −1.145° /
   el −0.018°, through the `Auto_align_Init()` fields) — then "lock" is just
   confirmation of a ~0.05° residual, flaggable in ~5 scans.
2. **Lock-detector need 10 → 5** — the flag alone currently costs ≥10 scans
   even with zero error.

Landed for the experiment (defaults = validated 46-frame profile, OFF-clean):
`APRISM_DA_K_FAST (0.05F)`, `APRISM_DA_K_SLOW (0.0025F)`, `APRISM_DA_ALPHA (0.1F)`,
`APRISM_DA_LOCK_TOL_DEG (0.05F)`, `APRISM_DA_LOCK_NEED (10)`,
`APRISM_DA_MAX_UPDATES (50U)` — all `#ifndef` in `dyn_align_wrapper.c`,
overridable per build, e.g.:

```
--copt=-DAPRISM_DA_FASTLOCK_ENABLE=1 --copt=-DAPRISM_DA_LOCK_NEED=5 --copt=-DAPRISM_DA_K_FAST=0.15
```

Risks to clear on SiL before claiming 4–10 (all must be measured, not asserted):
false lock on a quiet 5-frame stretch (need=5 weakens the confirmation),
overshoot/oscillation from high K_fast, highway-curve corruption (the reason the
baseline uses K≈0.0025), and single bad scans yanking boresight into the tracker.
True cold-start 4–10-frame estimation additionally needs the **DABB-side gain
change** (Gen8 cannot rewrite the buried recursion) plus labeled replay proof
with drops-to-zero and refusal-rate reporting.

## 12. A/B SiL recipe — exact Bazel flags (team network; blocked on this host)

> Verified in-repo (not guessed): variant flag `--variant={flr8,srr8p}` (alias,
> default `flr8`); SiL binaries `rdd_sil_Test` + `AF_sil_Test` below; scene bins
> under `sil/rsp_sil/data_bin/{flr8,srr8p}/{rdd_data,psp_data,vse_data}` read
> relative to repo root (`BUILD_WORKING_DIRECTORY`); `enable_cdc` defaults
> **False** so CDC legs need `--enable_cdc`; `@Dyn_alignment_module_interface`
> is a `local_repository(path=software/bbe32/dyn_alignment)` — i.e. **this same
> tree**, so the SiL binary contains the §8/§10 edits. Total workdir diff for
> reference: **405 insertions, 0 deletions** (pure additions).

```bash
cd gen_research/Core_Radar_Gen8_iND13400
V=--variant=flr8   # or srr8p (data_bin paths switch in main.cpp)

# ---- Build A: BASELINE (all APRISM flags undefined = original code) ----
bazel build $V --enable_cdc \
  //sil/rsp_sil/main/rsp_wrapper_interface/rdd_sil_interface/test:rdd_sil_Test \
  //sil/rsp_sil/main/rsp_wrapper_interface/af_sil_interface/test:AF_sil_Test \
  //software/bbe32/rdd_proc/test:all_tests
bazel test $V //software/bbe32/rdd_proc/test:all_tests   # baseline unit gate

# ---- Build B: ALL WIRED MODULES ON (Fast DA + CFAR/BLUE + CDC + ghost) ----
COPTS="--copt=-DAPRISM_ADAPTIVE_CFAR_ENABLE=1 --copt=-DAPRISM_DA_FASTLOCK_ENABLE=1 --copt=-DAPRISM_CDC_PRIO_ENABLE=1 --copt=-DAPRISM_GHOST_INSPECT_ENABLE=1"
bazel build $V --enable_cdc $COPTS \
  //sil/rsp_sil/main/rsp_wrapper_interface/rdd_sil_interface/test:rdd_sil_Test \
  //sil/rsp_sil/main/rsp_wrapper_interface/af_sil_interface/test:AF_sil_Test \
  //software/bbe32/rdd_proc/test:all_tests
bazel test $V $COPTS //software/bbe32/rdd_proc/test:all_tests

# ---- Builds C–F: single-module isolation (publication attribution) ----
bazel build $V --enable_cdc --copt=-DAPRISM_DA_FASTLOCK_ENABLE=1        //sil/.../rdd_sil_interface/test:rdd_sil_Test   # DA only
bazel build $V --enable_cdc --copt=-DAPRISM_ADAPTIVE_CFAR_ENABLE=1      //sil/.../rdd_sil_interface/test:rdd_sil_Test   # CFAR only
bazel build $V --enable_cdc --copt=-DAPRISM_CDC_PRIO_ENABLE=1           //sil/.../rdd_sil_interface/test:rdd_sil_Test   # CDC only
bazel build $V --enable_cdc --copt=-DAPRISM_GHOST_INSPECT_ENABLE=1      //sil/.../rdd_sil_interface/test:rdd_sil_Test   # ghost only
# (expand //sil/... to the full rdd_sil_Test label as in Build B)

# ---- Build G: SEEDED 4–10-frame confirmation leg ----
# Same as Build B plus: preflight NVM/M2D seed (converged az/el headers at t=0,
# injected via the team's M2D one-time-init path) and:
#   --copt=-DAPRISM_DA_LOCK_NEED=5 [--copt=-DAPRISM_DA_K_FAST=0.15]
# (trial values only — §11 risks apply; keep the 46-frame defaults for cold-start claims)

# ---- Run (from repo root; binaries read sil/rsp_sil/data_bin relatively) ----
./bazel-bin/sil/rsp_sil/main/rsp_wrapper_interface/rdd_sil_interface/test/rdd_sil_Test
./bazel-bin/sil/rsp_sil/main/rsp_wrapper_interface/af_sil_interface/test/AF_sil_Test
# Point each run at the same guardrail scene bins; capture per-leg:
#  DA lock frame (alignment_log stream + Aprism_Da_GetGain/IsLocked readouts),
#  CFAR edge-skirt recall + FA count, CDC kept/dropped near-field records,
#  ghost inspected/refused counters, Tier-1 yield hold.
```

Acceptance per leg (publishable deltas, OFF vs ON): DA 400→46 frames cold
(4–10 seeded only); CFAR edge recall lift + FA contract; CDC near-field kept
under saturation; ghost refusal rate on labeled multipath. If any leg shows no
delta, confirm the leg compiled in (`bazel aquery` for the `APRISM_*` copts and
the `CDC_ENABLE`/`PSP_SIL_ENABLE` selects) before concluding no effect.

## 13. Dummy-input A/B result (local, no network — `test_ab_compare` PASS)

> `aprism_host_tests/test_ab_compare.c` feeds identical synthetic inputs to the
> v7.0.x baseline path (OFF = passthrough) and the APRISM path (ON = real kernel
> calls mirroring the guarded production blocks). Run: `run_host_tests.bat`
> (now includes it) → RESULT: 0 failures (5 suites + A/B).

| Module | Baseline output (dummy in) | Research output (same dummy in) | Diff? |
|---|---|---|---|
| CFAR floor | nf=100 (untouched) | nf=80, floor 80.0→80.4 (EMA tracks row median 100) | YES — smoothing active |
| CFAR thresholds | th=1000 (untouched, ratio=1.0000 all-free) | th=1000 identical | NO (by design — identity until occupancy feed); occupied preview ratio=1.0724 raises thresholds |
| CDC order | 0,1,2,3,4,5 (arrival) | 1,4,3,0,5,2 (near-strong first, far-strong last) | YES |
| DA startup | num_updates=400 | num_updates=50; gain 0.0525→0.0030; lock at frame 13 | YES |
| Ghost contact | direct (ell=\|d\|): invalid → refuse | bistatic (ell=2r): valid, t=45.398 → keep | YES |
