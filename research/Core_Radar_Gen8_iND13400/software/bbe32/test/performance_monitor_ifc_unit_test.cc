/*===========================================================================*/
/**
 * @file performance_monitor_ifc_unit_test.cc
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
 * Unit tests for performance monitor wrapper `performance_monitor_ifc.c`.
 */

/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
#include <cstring>
#include <gtest/gtest.h>

/*===========================================================================*
 * FFF setup
 *===========================================================================*/
DEFINE_FFF_GLOBALS;

/*===========================================================================*
 * Fake external register storage for host unit tests
 *===========================================================================*/
static uint32_t g_perf_regs[512U] = {0U};

#undef XT_RER
#undef XT_WER
#define XT_RER(addr)      (g_perf_regs[((uint32_t)(addr)-0x00101000U) >> 2U])
#define XT_WER(val, addr) (g_perf_regs[((uint32_t)(addr)-0x00101000U) >> 2U] = (uint32_t)(val))

/*===========================================================================*
 * Unit Under Test
 *===========================================================================*/
extern "C"
{
#include "perfmon_helpers.c"
#include "software/bbe32/src/performance_monitor_ifc.c"
}

/*===========================================================================*
 * Fake-register index helpers
 *===========================================================================*/
#define PMG_IDX (0x0000U >> 2U)
#define PM0_IDX (0x0080U >> 2U)
#define PM1_IDX ((0x0080U + 4U * 1U) >> 2U)
#define PM2_IDX ((0x0080U + 4U * 2U) >> 2U)
#define PM3_IDX ((0x0080U + 4U * 3U) >> 2U)
#define PM4_IDX ((0x0080U + 4U * 4U) >> 2U)
#define PM5_IDX ((0x0080U + 4U * 5U) >> 2U)

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class Performance_Monitor_Ifc_Unit_Test_Suite : public testing::Test
{
   void SetUp()
   {
      memset(g_perf_regs, 0, sizeof(g_perf_regs));
      memset(&D_Cache_Counters, 0, sizeof(D_Cache_Counters));
      memset(&I_Cache_Counters, 0, sizeof(I_Cache_Counters));
   }

   void TearDown()
   {
   }
};

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

TEST_F(Performance_Monitor_Ifc_Unit_Test_Suite, InitializePerfmonInfo_ResetsCountersAndInitializesHelpers)
{
   D_Cache_Counters.cache_hit_count       = 9U;
   D_Cache_Counters.cache_miss_count_max  = 8U;
   D_Cache_Counters.cache_hit_count_prev  = 7U;
   I_Cache_Counters.cache_miss_count      = 6U;
   I_Cache_Counters.cache_hit_count_max   = 5U;
   I_Cache_Counters.cache_miss_count_prev = 4U;

   g_perf_regs[PM0_IDX] = 11U;
   g_perf_regs[PM1_IDX] = 12U;
   g_perf_regs[PM2_IDX] = 13U;
   g_perf_regs[PM3_IDX] = 14U;
   g_perf_regs[PM4_IDX] = 15U;
   g_perf_regs[PM5_IDX] = 16U;

   Initialize_Perfmon_Info();

   EXPECT_EQ(D_Cache_Counters.cache_hit_count, 0U);
   EXPECT_EQ(D_Cache_Counters.cache_miss_count_max, 0U);
   EXPECT_EQ(D_Cache_Counters.cache_hit_count_prev, 0U);
   EXPECT_EQ(I_Cache_Counters.cache_miss_count, 0U);
   EXPECT_EQ(I_Cache_Counters.cache_hit_count_max, 0U);
   EXPECT_EQ(I_Cache_Counters.cache_miss_count_prev, 0U);

   EXPECT_EQ(g_perf_regs[PM0_IDX], 0U);
   EXPECT_EQ(g_perf_regs[PM1_IDX], 0U);
   EXPECT_EQ(g_perf_regs[PM2_IDX], 0U);
   EXPECT_EQ(g_perf_regs[PM3_IDX], 0U);
   EXPECT_EQ(g_perf_regs[PM4_IDX], 0U);
   EXPECT_EQ(g_perf_regs[PM5_IDX], 0U);
   EXPECT_EQ(g_perf_regs[PMG_IDX], 1U);
}

TEST_F(Performance_Monitor_Ifc_Unit_Test_Suite, UpdateIPCPerfmonInfo_DoesNothingWhenPointerIsNull)
{
   BBE_Cache_Info_T icache_info = {0U};
   BBE_Cache_Info_T dcache_info = {0U};

   D_Cache_Counters.cache_hit_count  = 17U;
   I_Cache_Counters.cache_miss_count = 19U;

   Update_IPC_Perfmon_Info(NULL, &icache_info);

   EXPECT_EQ(D_Cache_Counters.cache_hit_count, 17U);
   EXPECT_EQ(I_Cache_Counters.cache_miss_count, 19U);
   EXPECT_EQ(icache_info.cache_hit_count, 0U);
   EXPECT_EQ(icache_info.cache_miss_count, 0U);

   Update_IPC_Perfmon_Info(&dcache_info, NULL);

   EXPECT_EQ(D_Cache_Counters.cache_hit_count, 17U);
   EXPECT_EQ(I_Cache_Counters.cache_miss_count, 19U);
   EXPECT_EQ(dcache_info.cache_hit_count, 0U);
   EXPECT_EQ(dcache_info.cache_miss_count, 0U);
}

TEST_F(Performance_Monitor_Ifc_Unit_Test_Suite, UpdateIPCPerfmonInfo_PopulatesCacheInfoFromCounters)
{
   BBE_Cache_Info_T dcache_info = {0U};
   BBE_Cache_Info_T icache_info = {0U};

   Initialize_Perfmon_Info();

   g_perf_regs[PM0_IDX] = 4U;
   g_perf_regs[PM1_IDX] = 9U;
   g_perf_regs[PM2_IDX] = 30U;
   g_perf_regs[PM3_IDX] = 15U;
   g_perf_regs[PM4_IDX] = 20U;
   g_perf_regs[PM5_IDX] = 25U;

   Update_IPC_Perfmon_Info(&dcache_info, &icache_info);

   EXPECT_EQ(dcache_info.cache_hit_count, 40U);
   EXPECT_EQ(dcache_info.cache_miss_count, 50U);
   EXPECT_EQ(dcache_info.cache_hit_count_max, 40U);
   EXPECT_EQ(dcache_info.cache_miss_count_max, 50U);

   EXPECT_EQ(icache_info.cache_hit_count, 9U);
   EXPECT_EQ(icache_info.cache_miss_count, 4U);
   EXPECT_EQ(icache_info.cache_hit_count_max, 9U);
   EXPECT_EQ(icache_info.cache_miss_count_max, 4U);
}

TEST_F(Performance_Monitor_Ifc_Unit_Test_Suite, UpdateIPCPerfmonInfo_TracksDeltasAndMaximaAcrossCalls)
{
   BBE_Cache_Info_T dcache_info = {0U};
   BBE_Cache_Info_T icache_info = {0U};

   Initialize_Perfmon_Info();

   g_perf_regs[PM0_IDX] = 4U;
   g_perf_regs[PM1_IDX] = 9U;
   g_perf_regs[PM2_IDX] = 30U;
   g_perf_regs[PM3_IDX] = 15U;
   g_perf_regs[PM4_IDX] = 20U;
   g_perf_regs[PM5_IDX] = 25U;
   Update_IPC_Perfmon_Info(&dcache_info, &icache_info);

   g_perf_regs[PM0_IDX] = 14U;
   g_perf_regs[PM1_IDX] = 20U;
   g_perf_regs[PM2_IDX] = 30U;
   g_perf_regs[PM3_IDX] = 60U;
   g_perf_regs[PM4_IDX] = 40U;
   g_perf_regs[PM5_IDX] = 35U;
   Update_IPC_Perfmon_Info(&dcache_info, &icache_info);

   EXPECT_EQ(dcache_info.cache_hit_count, 55U);
   EXPECT_EQ(dcache_info.cache_miss_count, 20U);
   EXPECT_EQ(dcache_info.cache_hit_count_max, 55U);
   EXPECT_EQ(dcache_info.cache_miss_count_max, 50U);

   EXPECT_EQ(icache_info.cache_hit_count, 11U);
   EXPECT_EQ(icache_info.cache_miss_count, 10U);
   EXPECT_EQ(icache_info.cache_hit_count_max, 11U);
   EXPECT_EQ(icache_info.cache_miss_count_max, 10U);
}

/**
 * @test Update_Cache_Counters cache_hit_count_max is not updated when current count is below existing max
 *
 * @pre First call establishes cache_hit_count_max = 100 (PM3+PM5 = 60+40).
 *      Second call produces a DCache hit delta of 10 (110 - 100), which is below the max.
 * @post cache_hit_count_max remains 100 (FALSE branch of MAX at line 93);
 *       cache_miss_count_max is updated to 15 as a positive reference that line 94 TRUE branch still fires
 */
TEST_F(Performance_Monitor_Ifc_Unit_Test_Suite, UpdateIPCPerfmonInfo_WhenHitCountBelowMax_HitMaxNotUpdated)
{
   BBE_Cache_Info_T dcache_info = {0U};
   BBE_Cache_Info_T icache_info = {0U};

   Initialize_Perfmon_Info();

   /* Call 1: DCache hit = PM3+PM5 = 60+40 = 100; DCache miss = PM2+PM4 = 5+5 = 10 */
   g_perf_regs[PM3_IDX] = 60U;
   g_perf_regs[PM5_IDX] = 40U;
   g_perf_regs[PM2_IDX] = 5U;
   g_perf_regs[PM4_IDX] = 5U;
   Update_IPC_Perfmon_Info(&dcache_info, &icache_info);

   EXPECT_EQ(dcache_info.cache_hit_count_max, 100U);
   EXPECT_EQ(dcache_info.cache_miss_count_max, 10U);

   /* Call 2: totals move to hit=110, miss=25 → deltas: hit=10 < max(100), miss=15 > max(10) */
   g_perf_regs[PM3_IDX] = 65U;
   g_perf_regs[PM5_IDX] = 45U;
   g_perf_regs[PM2_IDX] = 13U;
   g_perf_regs[PM4_IDX] = 12U;
   Update_IPC_Perfmon_Info(&dcache_info, &icache_info);

   EXPECT_EQ(dcache_info.cache_hit_count, 10U);
   EXPECT_EQ(dcache_info.cache_hit_count_max, 100U); /* FALSE branch: max not updated */
   EXPECT_EQ(dcache_info.cache_miss_count, 15U);
   EXPECT_EQ(dcache_info.cache_miss_count_max, 15U); /* TRUE branch: max updated */
}
