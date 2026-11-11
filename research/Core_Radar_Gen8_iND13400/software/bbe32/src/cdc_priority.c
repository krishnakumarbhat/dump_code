/* A-PRISM CDC priority implementation. See header for contract. */
#include "cdc_priority.h"

#include <math.h>

float CdcPriorityScore(float snr_db, float range_m)
{
    /* s = SNR_lin / r^2: near strong returns outrank far weak clutter. */
    float r = range_m;
    float snr_lin;
    if (r < 1.0f) {
        r = 1.0f;
    }
    snr_lin = powf(10.0f, snr_db / 10.0f);
    return snr_lin / (r * r);
}

int32_t CdcSelectTopK(const float *score, int32_t n, int32_t k, int32_t *idx)
{
    int32_t i, j, kept;
    if ((score == NULL) || (idx == NULL) || (n <= 0) || (k <= 0)) {
        return 0;
    }
    if (k > n) {
        k = n;
    }
    for (i = 0; i < n; i++) {
        idx[i] = i;
    }
    /* Partial selection sort for top-k: bounded O(n*k), no allocation. */
    for (i = 0; i < k; i++) {
        int32_t best = i;
        for (j = i + 1; j < n; j++) {
            /* stable: strictly greater displaces, ties keep order */
            if (score[idx[j]] > score[idx[best]]) {
                best = j;
            }
        }
        if (best != i) {
            int32_t t = idx[i];
            idx[i] = idx[best];
            idx[best] = t;
        }
    }
    kept = k;
    return kept;
}
