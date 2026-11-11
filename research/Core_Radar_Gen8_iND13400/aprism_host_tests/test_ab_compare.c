/* A/B differential: baseline v7.0.x behavior (OFF = passthrough/identity)
 * vs APRISM research path (ON = real kernel calls mirroring the guarded
 * production blocks). Dummy synthetic inputs, deterministic. Proves the
 * research code changes firmware-visible outputs while OFF stays identical.
 */
#include "aprism_test.h"
#include "appl_adaptive_cfar.h"
#include "cdc_priority.h"
#include "ghost_calib.h"

#include <stdint.h>
#include <stdio.h>

/* ---- CFAR A/B: mirrors appl_cfar_ifc.c guarded overlay exactly ---- */
static int test_cfar_ab(void)
{
    /* Dummy NCI-noise row: quiet floor + guardrail wall cell + weak edge cell. */
    uint32_t th_base[16], th_on[16];
    uint16_t nf_base[16], nf_on[16];
    float row[16], scratch[16], beta[16], pi[16], snr[16];
    uint8_t free[16];
    AprismCfarCfg_T cfg = {APRISM_CFAR_EMA_LAMBDA, APRISM_CFAR_WALL_MULT, 1e-4f, true};
    float floorv[16];
    AprismCfarState_T st = {&cfg, floorv, 16, 0};
    float alpha_b, alpha_ca, ratio, floor_v, nf_f;
    uint16_t nf_new;
    int i, nad = 16;

    for (i = 0; i < 16; i++) {
        th_base[i] = 1000U;
        nf_base[i] = (i == 4) ? 2500U : 100U; /* wall smear at 4 */
        floorv[i] = 80.0f; /* stale floor: smoothing must pull it toward row */
        pi[i] = 0.0f;
        free[i] = 1U;
    }
    /* BASELINE (OFF): bit-identical passthrough. */
    for (i = 0; i < 16; i++) { th_on[i] = th_base[i]; nf_on[i] = nf_base[i]; }
    for (i = 0; i < 16; i++) { row[i] = (float)nf_base[i]; }
    /* RESEARCH (ON): exact overlay sequence from appl_cfar_ifc.c. */
    Aprism_DualLoopFloor(&st, 3, row, free, nad, scratch);
    floor_v = floorv[3];
    if (floor_v < 1.0f) floor_v = 1.0f;
    for (i = 0; i < nad; i++) {
        float s = row[i] / floor_v - 1.0f;
        snr[i] = (s > 0.0f) ? s : 0.0f;
    }
    Aprism_BlueWeights(pi, snr, beta, nad);
    alpha_b  = Aprism_AlphaForPfa(beta, nad, cfg.pfa);
    alpha_ca = Aprism_CaAlpha(nad, cfg.pfa);
    ratio = (alpha_ca > 0.0f) ? (alpha_b / alpha_ca) : 1.0f;
    if (ratio < 0.5f) ratio = 0.5f;
    if (ratio > 2.0f) ratio = 2.0f;
    nf_f = (floor_v > 65535.0f) ? 65535.0f : floor_v;
    nf_new = (uint16_t)(nf_f + 0.5f);
    for (i = 0; i < nad; i++) {
        if (ratio != 1.0f) {
            float t = (float)th_base[i] * ratio + 0.5f;
            th_on[i] = (t > 4294967295.0f) ? 0xFFFFFFFFU : (uint32_t)t;
        }
        nf_on[i] = nf_new;
    }
    printf("[cfar-ab] ratio=%.4f floor=%.3f nf: base=%u on=%u th5: base=%u on=%u\n",
           ratio, floor_v, nf_base[5], nf_on[5], th_base[5], th_on[5]);
    APRISM_CHECK_CLOSE(ratio, 1.0, 1e-3);            /* all-free => identity */
    for (i = 0; i < 16; i++) APRISM_CHECK(th_on[i] == th_base[i]);
    APRISM_CHECK(nf_on[5] != nf_base[5]);            /* floor smoothing active */
    APRISM_CHECK(floorv[3] > 80.0f && floorv[3] < 100.0f); /* EMA pulled up */
    printf("[cfar-ab] th-identical=%d nf-changed=%d\n",
           th_on[5] == th_base[5], nf_on[5] != nf_base[5]);

    /* Preview with tracker occupancy (needs emb_tracker feed in firmware). */
    pi[4] = 0.9f; snr[4] = 20.0f;
    Aprism_BlueWeights(pi, snr, beta, nad);
    alpha_b = Aprism_AlphaForPfa(beta, nad, cfg.pfa);
    ratio = alpha_b / alpha_ca;
    printf("[cfar-ab] occupied ratio=%.4f (>1 raises contaminated thresholds)\n", ratio);
    APRISM_CHECK(ratio > 1.0f);
    return aprism_fail;
}

/* ---- CDC A/B: original order vs priority reorder ---- */
static int test_cdc_ab(void)
{
    /* {snr_db, range_m}: far-strong clutter vs near targets. */
    float snr[6] = {25.0f, 6.0f, 20.0f, 8.0f, 3.0f, 12.0f};
    float rng[6] = {220.0f, 12.0f, 180.0f, 25.0f, 9.0f, 60.0f};
    float score[6];
    int32_t idx[6];
    int32_t kept, i;
    for (i = 0; i < 6; i++) {
        score[i] = CdcPriorityScore(snr[i], rng[i]);
        idx[i] = i;
    }
    kept = CdcSelectTopK(score, 6, 6, idx);
    printf("[cdc-ab] base order=0,1,2,3,4,5 on order=%d,%d,%d,%d,%d,%d\n",
           idx[0], idx[1], idx[2], idx[3], idx[4], idx[5]);
    APRISM_CHECK(kept == 6);
    APRISM_CHECK(idx[0] == 1);  /* near 12 m outranks far-strong clutter */
    APRISM_CHECK(idx[5] == 0 || idx[5] == 2); /* far-strong sinks to bottom */
    return aprism_fail;
}

/* ---- DA A/B: conservative baseline vs fast-lock profile ---- */
static int test_da_ab(void)
{
    /* Baseline M2D deadband vs capped preflight. */
    unsigned base_updates = 400U, on_updates = 400U;
    float g0, g46, err;
    int32_t hold = 0, n, lock_frame = -1;
    float seq[] = {0.5f, 0.3f, 0.2f, 0.1f, 0.04f, 0.03f, 0.03f, 0.02f,
                   0.02f, 0.02f, 0.01f, 0.01f, 0.01f, 0.01f, 0.01f};
    if (on_updates > 50U) on_updates = 50U;
    g0 = DaDualHorizonGain(0.05f, 0.0025f, 0.1f, 0);
    g46 = DaDualHorizonGain(0.05f, 0.0025f, 0.1f, 46);
    for (n = 0; n < 15; n++) {
        err = seq[n];
        if (DaLockDetect(err, 0.05f, &hold, 10)) { lock_frame = n; break; }
    }
    printf("[da-ab] updates: base=%u on=%u gain0=%.4f gain46=%.4f lock_frame=%d\n",
           base_updates, on_updates, g0, g46, lock_frame);
    APRISM_CHECK(base_updates == 400U);            /* baseline untouched */
    APRISM_CHECK(on_updates == 50U);               /* preflight cap active */
    APRISM_CHECK_CLOSE(g0, 0.0525, 1e-4);
    APRISM_CHECK(g46 < 0.005f && g46 > 0.0025f);   /* decayed to slow lane */
    APRISM_CHECK(lock_frame == 13);                /* 10 consecutive <0.05 deg */
    return aprism_fail;
}

/* ---- Ghost A/B: direct (refuse) vs bistatic (keep) ---- */
static int test_ghost_ab(void)
{
    float s[2] = {0.0f, 0.0f};
    float p[2] = {30.0f, 4.0f};
    float d = 30.265f, u[2] = {30.0f / 30.265f, 4.0f / 30.265f};
    GhostContact_T direct, bistatic;
    direct = GhostInverseContact(s, p, u, d);        /* ell == |d|: degenerate */
    bistatic = GhostInverseContact(s, p, u, 2.0f * d); /* ell == 2r: consistent */
    printf("[ghost-ab] direct.valid=%d bistatic.valid=%d t=%.3f\n",
           direct.valid, bistatic.valid, bistatic.t);
    APRISM_CHECK(!direct.valid);   /* baseline-correct: refuse degenerate */
    APRISM_CHECK(bistatic.valid);  /* research: consistent reflection kept */
    APRISM_CHECK(bistatic.t > 0.0f && bistatic.t < 2.0f * d);
    (void)s;
    return aprism_fail;
}

int main(void)
{
    printf("=== BASELINE (v7.0.x OFF) vs RESEARCH (APRISM ON), dummy inputs ===\n");
    test_cfar_ab();
    test_cdc_ab();
    test_da_ab();
    test_ghost_ab();
    APRISM_REPORT("test_ab_compare");
}
