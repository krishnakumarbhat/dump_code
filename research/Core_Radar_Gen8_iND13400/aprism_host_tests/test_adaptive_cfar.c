/* Host test: adaptive CFAR layer (mirrors Run 23 demo asserts). */
#include "aprism_test.h"
#include "appl_adaptive_cfar.h"

#include <stdio.h>

static int test_blue(void)
{
    float pi[16], snr[16], beta[16];
    float m_sum = 0.0f;
    int i;
    for (i = 0; i < 14; i++) {
        pi[i] = 0.0f;
        snr[i] = 0.0f;
    }
    pi[14] = pi[15] = 0.3f;
    snr[14] = snr[15] = 10.0f;
    Aprism_BlueWeights(pi, snr, beta, 16);
    printf("[weights] clean=%.5f cont=%.6f\n", beta[0], beta[14]);
    APRISM_CHECK_CLOSE(beta[0], 0.06872, 2e-4);
    APRISM_CHECK_CLOSE(beta[14], 0.004740, 2e-5);
    for (i = 0; i < 16; i++) {
        m_sum += beta[i] * (1.0f + pi[i] * snr[i]);
    }
    APRISM_CHECK_CLOSE(m_sum, 1.0f, 1e-5f);
    {
        float a = Aprism_AlphaForPfa(beta, 16, 1e-4f);
        printf("[threshold] alpha=%.4f\n", a);
        APRISM_CHECK(a > 13.2f && a < 13.4f);
    }
    {
        float ca = Aprism_CaAlpha(16, 1e-4f);
        printf("[ca] alpha=%.4f (expect ~12.45)\n", ca);
        APRISM_CHECK_CLOSE(ca, 12.45f, 0.05f);
    }
    return aprism_fail;
}

static int test_floor_r0(void)
{
    AprismCfarCfg_T cfg = {APRISM_CFAR_EMA_LAMBDA, APRISM_CFAR_WALL_MULT, 1e-4f, true};
    float floorv[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    float scratch[64];
    AprismCfarState_T st = {&cfg, floorv, 4, 0};
    float row[8] = {1.0f, 1.1f, 0.9f, 1.0f, 25.0f, 1.2f, 0.8f, 1.0f};
    uint8_t free[8] = {1, 1, 1, 1, 0, 1, 1, 1}; /* wall cell masked */
    float med_expect = 1.0f;
    (void)med_expect;
    Aprism_DualLoopFloor(&st, 2, row, free, 8, scratch);
    printf("[floor] %.6f (wall masked, floor must barely move)\n", floorv[2]);
    APRISM_CHECK(floorv[2] > 0.99f && floorv[2] < 1.05f);
    APRISM_CHECK(Aprism_SelectR0(0.5f, 1.0f, 3.0f) == APRISM_CFAR_R0_SMALL);
    APRISM_CHECK(Aprism_SelectR0(2.0f, 1.0f, 3.0f) == APRISM_CFAR_R0_MID);
    APRISM_CHECK(Aprism_SelectR0(9.0f, 1.0f, 3.0f) == APRISM_CFAR_R0_LARGE);
    {
        float a[5] = {3.0f, 1.0f, 2.0f, 5.0f, 4.0f};
        float s[5];
        APRISM_CHECK_CLOSE(Aprism_Median(a, s, 5), 3.0f, 1e-6f);
    }
    return aprism_fail;
}

int main(void)
{
    test_blue();
    test_floor_r0();
    APRISM_REPORT("test_adaptive_cfar");
}
