/* Host test: CDC priority packing (F5 mitigation). */
#include "aprism_test.h"
#include "cdc_priority.h"

#include <stdio.h>

int main(void)
{
    float snr[6] = {20.0f, 5.0f, 30.0f, 5.0f, 12.0f, 5.0f};
    float rng[6] = {10.0f, 10.0f, 150.0f, 150.0f, 60.0f, 60.0f};
    float sc[6];
    int32_t idx[6];
    int i, kept;
    for (i = 0; i < 6; i++) {
        sc[i] = CdcPriorityScore(snr[i], rng[i]);
    }
    /* near-strong (20dB@10m) must outrank far-strong (30dB@150m)? no:
     * 30dB@150m: 1000/22500=0.044; 20dB@10m: 100/100=1.0 -> near wins. */
    printf("[score] near-strong=%.4f far-strong=%.4f\n", sc[0], sc[2]);
    APRISM_CHECK(sc[0] > sc[2]);
    kept = CdcSelectTopK(sc, 6, 3, idx);
    printf("[topk] kept=%d idx=%d,%d,%d\n", kept, (int)idx[0], (int)idx[1], (int)idx[2]);
    APRISM_CHECK(kept == 3);
    APRISM_CHECK(idx[0] == 0); /* 20dB@10m first */
    APRISM_CHECK(CdcSelectTopK(sc, 6, 0, idx) == 0);
    APRISM_CHECK(CdcSelectTopK(NULL, 6, 3, idx) == 0);
    APRISM_REPORT("test_cdc_priority");
}
