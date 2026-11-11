# A-PRISM OT Handoff — what the object-tracker team implements, exactly where

Audience: owner team of the internal Gerrit repo `CORECOMP/ALSW/OT_ObjectTracking`
(`C:\git\OT_ObjectTracking`). This document lives in the Gen8 repo only as a
handoff spec — **no OT files were read for editing and none are modified**.
Base: the team's current Gerrit `dev`/integration branch (not the old local
`master`, not the GitHub `core-radar-object-tracker` snapshot, not the
uncommitted local CMake/variant edits).

Conventions below use inspected Gerrit paths
(`modules/F360Core/sw/F360TrackerLib/...`, namespace `f360_variant_A`).
Variant sizing (`f360_variant_definition.h`, currently being edited locally
toward variant C) must be confirmed with the OT team — array bounds
(`NUMBER_OF_OBJECT_TRACKS`, `MAX_DETS_IN_OBJ_TRK`, …) constrain any new
per-track/per-detection state.

## 0. Pipeline order constraint (verified in `Fusion360/f360_tracker.cpp`)

`Time_Update_Tracks → Pre_Association_Track_Management →
Detection_To_Track_Association → Clustering/Grouping → Measurement_Update_Tracks
→ Initialize_Tracks → Post_Update_Track_Adjustments → Track_Classification →
Track_Validity (multipath marking, ghost-reflection checks, confidence)`.
Consequence: anything that must influence the EKF update (ghost assimilation,
gate widening, R scaling) belongs at association/measurement-update time —
`Track_Validity()` runs after the update and is too late for that scan.

## 1. Run-14 ghost-as-virtual-aperture (score 80, KEEP — highest priority)

Current state: `track_validity/` (`f360_detect_multipath.cpp`,
`f360_is_reflective_guardrail_track.cpp`, `Determine_Reflected_Obj`) only
classifies/penalizes suspected mirrors (`mirror_prob`, coast/downselection
effects). No ghost measurement is assimilated.
Implement: (a) pair direct/ghost detections pre-association (reuse SEP
reflection geometry where valid; add the estimated-geometry pair engine for
the N9 blind spot); (b) add a ghost measurement row in
`measurement_update_tracks/` (`Msmt_Update_ObjTrks_{CCA_Moveable,CTCA}` family)
with shared-reflector covariance `R_eff = R + J Σ Jᵀ` alongside the existing
Joseph update; (c) guard against double-counting the same evidence in
`mirror_prob` suppression — one ghost, one role per scan (update XOR penalize),
decided by the pair classifier.
Tests: extend the existing multipath/association unit + qualtest suites with
same-range decoy pairs, curved-reflector scenes, and direct-only baselines.

## 2. N9/N20g pair consensus + curved rails (74/68)

`Is_Ghost_Reflected_By_SEP` family already reflects candidates across SEP
tangents with similarity thresholds in `f360_calibrations.cpp`
(`k_tv_refl_gr_trk_*`: diffs 5.5/5.5 m, rel-vel 0.2, heading 20°, sep window
±80 m). Add: moving-target point-plus-tangent evidence and the Hermite
curved-rail path as an alternative hypothesis engine next to — not inside —
these checks; report ambiguity (single-scan fit ambiguity is expected) and
keep classification robust while fit stays ambiguous.

## 3. N5 adaptive gate (71) + N24 rank gate (63)

Current: `Calc_Range_Rate_Threshold()` (FOV-edge/coast adjustments),
`Try_To_Dealiase_Range_Rate()`, geometry/cost scoring in
`Determine_Association_Hypothesis()` (`f360_detection_association_support_functions.cpp`,
`f360_determine_association_hypothesis.cpp`).
Implement: acceleration + innovation-energy gate expansion with hard bounds
at the hypothesis gate; frozen rank calibration + reachable-tube + quorum as
a separate, explicitly-versioned gate state (new calibration fields +
store, default conservative); log ambiguous bundles instead of silently
picking. Validate recall AND clutter selectivity + track RMSE.

## 4. T5 spectral R / conformal / Gram (67/67/60)

`r_mat` construction points already exist
(`Filling_Msmt_Cov_By_H_RR_CTCA`, `normalized_rr_variance = N *
k_ref_msmt_cov_cca`, `k_ref_msmt_cov_cca = 0.9F` default). Implement
entropy/SNR-scaled R, conformal credible handling, and (only) the decoupled
Gram channels here; keep Joseph updates; never ship the joint-position form
(it regressed 6.77×). Calibrations involved:
`k_ref_msmt_cov_cca`, `k_range_rate_score_threshold = 2.0F`, velocity
variances — confirm which are tunable vs fixed with the OT owner
(some values here are load-bearing defaults, e.g. thresholds at 3.0/5.55).

## 5. Ghost bookkeeping already present — reuse, don't duplicate

`mirror_prob` (threshold `k_mirror_prob_threshold = 0.30F`), coast/kill
rules for mirrors, downselection ghost checks, multipath event counters
with forgetting factors, XTRK logging blocks. New work must write into
these fields through the existing update paths, not parallel state.

## 6. Process (from the tracker's own README)

Feature branch off team `dev`; repo pre-commit hooks + Jenkins Verified
(build + format + tests) must pass; release via `version.yaml` automation.
Validate with the tracker unit/qualification suites plus Gen8 SiL replay
with UDP/CAN KPI contracts; keep flag-OFF baselines bit-comparable.
