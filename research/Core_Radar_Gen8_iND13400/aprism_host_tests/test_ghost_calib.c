/* Host test: ghost calibration kernels (mirrors Runs 24/28 fixtures). */
#include "aprism_test.h"
#include "ghost_calib.h"

#include <stdio.h>

#define DEG_C (0.017453292519943295)

int main(void)
{
    /* 1. exact yaw scene: s=(+-2,0), beta=+/-1deg, plane y=6 */
    {
        /* 4 records: p(t)=(8+2t, 2+0.5t), p*=(x, 12-y), t=0..0.15 */
        float s1[2] = {-2.0f, 0.0f}, s2[2] = {2.0f, 0.0f};
        float b1 = (float)(1.0 * DEG_C), b2 = (float)(-1.0 * DEG_C);
        float zd1[8], zg1[8], zd2[8], zg2[8];
        int k;
        GhostYawResult_T e;
        for (k = 0; k < 4; k++) {
            float t = 0.05f * (float)k;
            float px = 8.0f + 2.0f * t, py = 2.0f + 0.5f * t;
            float gx = px, gy = 12.0f - py;
            float c1 = (float)cos((double)b1), s_1 = (float)sin((double)b1);
            float c2 = (float)cos((double)b2), s_2 = (float)sin((double)b2);
            /* local = R(-b) * (world - s) */
            float d1x = px + 2.0f, d1y = py, g1x = gx + 2.0f, g1y = gy;
            float d2x = px - 2.0f, d2y = py, g2x = gx - 2.0f, g2y = gy;
            zd1[2 * k] = c1 * d1x + s_1 * d1y;
            zd1[2 * k + 1] = -s_1 * d1x + c1 * d1y;
            zg1[2 * k] = c1 * g1x + s_1 * g1y;
            zg1[2 * k + 1] = -s_1 * g1x + c1 * g1y;
            zd2[2 * k] = c2 * d2x + s_2 * d2y;
            zd2[2 * k + 1] = -s_2 * d2x + c2 * d2y;
            zg2[2 * k] = c2 * g2x + s_2 * g2y;
            zg2[2 * k + 1] = -s_2 * g2x + c2 * g2y;
        }
        e = GhostEstimateYaw(zd1, zg1, zd2, zg2, 4, s1, s2);
        printf("[yaw] valid=%d delta=%.6fdeg b1=%.6fdeg\n",
               (int)e.valid, e.delta / (float)DEG_C, e.beta_i / (float)DEG_C);
        APRISM_CHECK(e.valid);
        APRISM_CHECK_CLOSE(e.delta, -2.0 * DEG_C, 1e-4);
        APRISM_CHECK_CLOSE(e.beta_i, b1, 1e-4);
        APRISM_CHECK(e.lmin > 7.0f);
        {
            float er, ei, ej;
            bool ok = GhostCertify(5e-4f, e.lmin, e.cmax, 4.0f, &er, &ei, &ej);
            printf("[cert] ok=%d e_j=%.4fdeg\n", (int)ok, ej);
            APRISM_CHECK(ok && ej < 0.1f);
        }
    }
    /* 2. contact fixture: s=(0,0) p=(6,0) u=(.6,.8) l=10 */
    {
        float s[2] = {0, 0}, p[2] = {6.0f, 0.0f}, u[2] = {0.6f, 0.8f};
        GhostContact_T c = GhostInverseContact(s, p, u, 10.0f);
        printf("[contact] valid=%d t=%.6f q=(%.4f,%.4f) n=(%.4f,%.4f)\n",
               (int)c.valid, c.t, c.q[0], c.q[1], c.n[0], c.n[1]);
        APRISM_CHECK(c.valid);
        APRISM_CHECK_CLOSE(c.t, 5.0, 1e-4);
        APRISM_CHECK_CLOSE(c.q[0], 3.0, 1e-4);
        APRISM_CHECK_CLOSE(c.q[1], 4.0, 1e-4);
        APRISM_CHECK_CLOSE(c.n[1], -1.0, 1e-4);
    }
    /* 3. Hermite recovers cubic */
    {
        /* rail c=(-4,.02,1.5e-3,-8e-6): contacts x=8 (y=-3.592,slope?) x=40 */
        float xs[2] = {8.0f, 40.0f};
        float ys[2] = {-4.0f + 0.02f * 8.0f + 0.0015f * 64.0f - 0.000008f * 512.0f,
                       -4.0f + 0.02f * 40.0f + 0.0015f * 1600.0f - 0.000008f * 64000.0f};
        float sl[2] = {0.02f + 2 * 0.0015f * 8.0f - 3 * 0.000008f * 64.0f,
                       0.02f + 2 * 0.0015f * 40.0f - 3 * 0.000008f * 1600.0f};
        float c[4];
        float det = HermiteSolve2(xs, ys, sl, c);
        printf("[hermite] det=%.3f c=[%.6f %.6f %.6f %.9f]\n", det, c[0], c[1], c[2], c[3]);
        APRISM_CHECK(det > 1e5f);
        APRISM_CHECK_CLOSE(c[0], -4.0, 1e-2);
        APRISM_CHECK_CLOSE(c[1], 0.02, 1e-4);
        APRISM_CHECK_CLOSE(c[2], 0.0015, 1e-5);
        APRISM_CHECK_CLOSE(c[3], -0.000008, 1e-7);
    }
    /* 4. clock fixtures */
    {
        float d[2] = {10.0f, 4.0f}, v[2] = {5.0f, -2.0f};
        float x[2] = {10.1f, 3.96f};
        float r = 10.1f * 10.1f + 3.96f * 3.96f;
        float w;
        float tau;
        r = (float)sqrt((double)r);
        w = (x[0] * v[0] + x[1] * v[1]) / r;
        tau = ClockTau1(d, v, r, w);
        printf("[clock] tau=%.9f\n", tau);
        APRISM_CHECK_CLOSE(tau, 0.02, 1e-5);
        {
            float t2, b2;
            /* y1=1.5,y2=4,a1=25,r1=10,a2=100,r2=20,D=-500 */
            bool ok = ClockTauBias2(25.0f, 10.0f, 1.5f, 100.0f, 20.0f, 4.0f, &t2, &b2);
            APRISM_CHECK(ok);
            APRISM_CHECK_CLOSE(t2, 0.02, 1e-5);
            APRISM_CHECK_CLOSE(b2, 0.1, 1e-4);
        }
    }
    /* 5. DA gain + lock */
    {
        float g0 = DaDualHorizonGain(1.0f, 0.1f, 0.05f, 0);
        float g46 = DaDualHorizonGain(1.0f, 0.1f, 0.05f, 46);
        int32_t hold = 0;
        int i;
        printf("[da] gain(0)=%.4f gain(46)=%.4f\n", g0, g46);
        APRISM_CHECK_CLOSE(g0, 1.1f, 1e-4f);
        APRISM_CHECK(g46 < 0.3f && g46 > 0.1f);
        for (i = 0; i < 10; i++) {
            if (DaLockDetect(0.05f, 0.1f, &hold, 5)) {
                break;
            }
        }
        APRISM_CHECK(hold >= 5);
    }
    /* 6. refusal paths */
    {
        float s1[2] = {0, 0}, s2[2] = {0, 0}, z[2] = {1.0f, 0.0f};
        GhostYawResult_T e = GhostEstimateYaw(z, z, z, z, 1, s1, s2);
        APRISM_CHECK(!e.valid); /* zero baseline */
        {
            /* eps=2m makes rho>1: degenerate input refused. eps=0.2m is
             * valid-but-huge (~30deg bound), correctly NOT refused. */
            float er, ei, ej;
            APRISM_CHECK(!GhostCertify(2.0f, 7.0f, 10.0f, 4.0f, &er, &ei, &ej));
            APRISM_CHECK(GhostCertify(0.2f, 7.0f, 10.0f, 4.0f, &er, &ei, &ej));
            APRISM_CHECK(ej > 0.1f);
        }
    }
    APRISM_REPORT("test_ghost_calib");
}
