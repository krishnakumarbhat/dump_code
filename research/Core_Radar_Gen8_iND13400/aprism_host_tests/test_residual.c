/* Host test: residual estimators (mirrors Runs 15/26 demo asserts). */
#include "aprism_test.h"
#include "residual_track_ifc.h"

#include <stdio.h>

static void tone4(float A, float phi0, float fh, float gh2, float lh3, float *x)
{
    static const float u[4] = {-1.5f, -0.5f, 0.5f, 1.5f};
    int i;
    for (i = 0; i < 4; i++) {
        float r = fh * u[i] + 0.5f * gh2 * u[i] * u[i] + (lh3 / 6.0f) * u[i] * u[i] * u[i];
        float ph = 6.2831853f * (phi0 + r);
        /* cosf/sinf below */
        x[2 * i] = A * (float)cos((double)ph);
        x[2 * i + 1] = A * (float)sin((double)ph);
    }
}

int main(void)
{
    /* 1. exact stencil */
    {
        float x[8], z[3] = {0, 0, 0}, g, l, fh;
        int32_t nm = 0;
        bool bad = false;
        tone4(1.0f, 0.3f, 0.1f, 0.02f, 0.006f, x);
        fh = ResidualCubic4(x, z, &g, &l, &nm, &bad);
        printf("[stencil] fh=%.9f gh2=%.9f lh3=%.9f mults=%d\n", fh, g, l, (int)nm);
        APRISM_CHECK(!bad && nm == 3);
        APRISM_CHECK_CLOSE(fh, 0.1, 1e-5);
        APRISM_CHECK_CLOSE(g, 0.02, 1e-5);
        APRISM_CHECK_CLOSE(l, 0.006, 1e-5);
        tone4(1.0f, 0.0f, 0.0f, 0.0f, 0.006f, x);
        fh = ResidualCubic4(x, z, &g, &l, &nm, &bad);
        APRISM_CHECK_CLOSE(fh, 0.0, 1e-5);
        APRISM_CHECK_CLOSE(g, 0.0, 1e-5);
    }
    /* 2. invalid paths */
    {
        float x[8] = {0}, z[3] = {0}, g, l;
        int32_t nm = 0;
        bool bad = false;
        ResidualCubic4(x, z, &g, &l, &nm, &bad);
        APRISM_CHECK(bad);
        tone4(1.0f, 0.0f, 0.05f, 0.0f, 0.0f, x);
        bad = false;
        ResidualCubic4(x, NULL, &g, &l, &nm, &bad);
        APRISM_CHECK(bad);
    }
    /* 3. INT8 bound: amplitude 80 */
    {
        float b = ResidualQuantAngleBound(80.0f);
        float rq0, rq1;
        int8_t qr, qi;
        printf("[fixedpt] angle bound=%.6f rad\n", b);
        APRISM_CHECK(b < 0.0089f);
        ResidualQuant8(56.0f, 56.0f, 1.0f, &qr, &qi, &rq0, &rq1);
        APRISM_CHECK(qr == 56 && qi == 56);
        APRISM_CHECK_CLOSE(rq0, 56.0, 1e-3);
    }
    /* 4. lag-1 sanity on pure tone */
    {
        float x[16], f;
        int i;
        for (i = 0; i < 8; i++) {
            float ph = 6.2831853f * (0.05f * i);
            x[2 * i] = (float)cos((double)ph);
            x[2 * i + 1] = (float)sin((double)ph);
        }
        f = ResidualLag1(x, 8, 0.0f);
        printf("[lag1] f=%.6f (expect 0.05)\n", f);
        APRISM_CHECK_CLOSE(f, 0.05, 1e-4);
    }
    APRISM_REPORT("test_residual");
}
