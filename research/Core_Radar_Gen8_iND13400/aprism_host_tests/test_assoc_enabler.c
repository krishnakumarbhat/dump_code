/* Host test: association enablers (mirrors Run 4 gate quantities). */
#include "aprism_test.h"
#include "ghost_assoc_enabler.h"

#include <stdio.h>

int main(void)
{
    /* Nominal cut-in: ghost Doppler -1.322 vs parent +0.665 (40-sigma case).
     * Track-velocity prior: v_a=(10,0)-ish lateral; u_sb chosen so that
     * pred = -1.30 (0.022 residual).denominator K=3, sig=(0.05,0.5). */
    {
        float u[2] = {0.0f, -1.0f};
        float va[2] = {0.0f, 1.30f};
        float s = GhostDopplerScore(-1.322f, u, va, 0.05f, 0.5f, 3.0f);
        printf("[doppler] score=%.4f (<=1 inside gate)\n", s);
        APRISM_CHECK(s <= 1.0f);
        /* decoy 2 m/s off prediction must fail */
        s = GhostDopplerScore(0.7f, u, va, 0.05f, 0.5f, 3.0f);
        printf("[doppler] decoy score=%.4f (>1 rejected)\n", s);
        APRISM_CHECK(s > 1.0f);
    }
    /* Occupancy row */
    {
        float pi, sn;
        GhostCellOccupancy(11.0f, 1.0f, 0.0f, 0.9f, &pi, &sn);
        printf("[occ] pi=%.4f s=%.4f (expect ~0.818, 10.0)\n", pi, sn);
        APRISM_CHECK(pi > 0.8f && pi < 0.85f);
        APRISM_CHECK_CLOSE(sn, 10.0f, 1e-4f);
        GhostCellOccupancy(0.5f, 1.0f, 0.0f, 0.9f, &pi, &sn);
        APRISM_CHECK(pi == 0.0f && sn == 0.0f);
    }
    /* Two-scan confirmation */
    {
        uint8_t seen[64] = {0};
        APRISM_CHECK(GhostConfirmUpdate(seen, 7, 64, true) == 0);
        APRISM_CHECK(GhostConfirmUpdate(seen, 7, 64, true) == 1);
        APRISM_CHECK(GhostConfirmUpdate(seen, 7, 64, false) == 0);
        APRISM_CHECK(GhostConfirmUpdate(seen, 7, 64, true) == 0);
    }
    APRISM_REPORT("test_assoc_enabler");
}
