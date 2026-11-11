/*===========================================================================*/
/**
 * @file appl_adaptive_cfar_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit tests for the A-PRISM adaptive CFAR layer
 * (`appl_adaptive_cfar.h/.c`: dual-loop floor + Occupancy-BLUE weights).
 * Asserts mirror `aprism_host_tests/test_adaptive_cfar.c` (clang host PASS)
 * and the Run 23 Python demo (weights 0.06872/0.00474, alpha ~13.3).
 */
#include <gtest/gtest.h>

extern "C"
{
#include "appl_adaptive_cfar.h"
}

class Appl_Adaptive_Cfar_Suite : public testing::Test
{
};

TEST_F(Appl_Adaptive_Cfar_Suite, blue_weights_match_demo)
{
    float pi[16] = {0};
    float snr[16] = {0};
    float beta[16];
    float m_sum = 0.0F;
    int i;
    pi[14] = pi[15] = 0.3F;
    snr[14] = snr[15] = 10.0F;
    Aprism_BlueWeights(pi, snr, beta, 16);
    EXPECT_NEAR(beta[0], 0.06872F, 2e-4F);
    EXPECT_NEAR(beta[14], 0.004740F, 2e-5F);
    for (i = 0; i < 16; i++) {
        m_sum += beta[i] * (1.0F + pi[i] * snr[i]);
    }
    EXPECT_NEAR(m_sum, 1.0F, 1e-5F);
}

TEST_F(Appl_Adaptive_Cfar_Suite, alpha_root_in_range)
{
    float pi[16] = {0};
    float snr[16] = {0};
    float beta[16];
    float a;
    pi[14] = pi[15] = 0.3F;
    snr[14] = snr[15] = 10.0F;
    Aprism_BlueWeights(pi, snr, beta, 16);
    a = Aprism_AlphaForPfa(beta, 16, 1e-4F);
    EXPECT_GT(a, 13.2F);
    EXPECT_LT(a, 13.4F);
    EXPECT_NEAR(Aprism_CaAlpha(16, 1e-4F), 12.45F, 0.05F);
}

TEST_F(Appl_Adaptive_Cfar_Suite, floor_holds_with_wall_masked)
{
    AprismCfarCfg_T cfg = {APRISM_CFAR_EMA_LAMBDA, APRISM_CFAR_WALL_MULT, 1e-4F, true};
    float floorv[4] = {1.0F, 1.0F, 1.0F, 1.0F};
    float scratch[64];
    AprismCfarState_T st = {&cfg, floorv, 4, 0};
    float row[8] = {1.0F, 1.1F, 0.9F, 1.0F, 25.0F, 1.2F, 0.8F, 1.0F};
    uint8_t free[8] = {1, 1, 1, 1, 0, 1, 1, 1};
    Aprism_DualLoopFloor(&st, 2, row, free, 8, scratch);
    EXPECT_GT(floorv[2], 0.99F);
    EXPECT_LT(floorv[2], 1.05F);
    EXPECT_EQ(Aprism_SelectR0(0.5F, 1.0F, 3.0F), APRISM_CFAR_R0_SMALL);
    EXPECT_EQ(Aprism_SelectR0(2.0F, 1.0F, 3.0F), APRISM_CFAR_R0_MID);
    EXPECT_EQ(Aprism_SelectR0(9.0F, 1.0F, 3.0F), APRISM_CFAR_R0_LARGE);
}
