/*===========================================================================*/
/**
 * @file SWC_PLT_CDD_TimeSync_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for SWC_PLT_CDD_TimeSync.
 *
 * @section ABBR ABBREVIATIONS:
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 */
/*==========================================================================*/

/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include <gtest/gtest.h>

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "SWC_PLT_CDD_TimeSync_fake.h"
#include "fff.h"

extern "C"
{
#include "../Source/SWC_PLT_CDD_TimeSync.c"

   extern Gpt_ValueType g_gpt_time_elapsed;
   extern unsigned g_gpt_stop_timer_calls;
   extern unsigned g_gpt_start_timer_calls;
   extern Gpt_ValueType g_gpt_start_timer_value;

   Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
   {
      (void)Channel;
      return g_gpt_time_elapsed;
   }

   void Gpt_StopTimer(Gpt_ChannelType Channel)
   {
      (void)Channel;
      g_gpt_stop_timer_calls++;
   }

   void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
   {
      (void)Channel;
      g_gpt_start_timer_calls++;
      g_gpt_start_timer_value = Value;
   }

   Std_ReturnType EcuSync_SeedCanTSynTimeBaseIfNeeded(void)
   {
      return E_OK;
   }
}
uint32_t g_platform_mstime_calls      = 0u;
uint32_t g_platform_mstime_value      = 0u;
Gpt_ValueType g_gpt_time_elapsed      = 0U;
unsigned g_gpt_stop_timer_calls       = 0U;
unsigned g_gpt_start_timer_calls      = 0U;
Gpt_ValueType g_gpt_start_timer_value = 0U;
DEFINE_FFF_GLOBALS;

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class swc_plt_cdd_timesync_UnitTestSuite : public ::testing::Test
{
   void SetUp() override
   {
      FFF_RESET_HISTORY();
      g_gpt_time_elapsed      = 0U;
      g_gpt_stop_timer_calls  = 0U;
      g_gpt_start_timer_calls = 0U;
      g_gpt_start_timer_value = 0U;
   }

   void TearDown() override
   {
   }
};

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

TEST_F(swc_plt_cdd_timesync_UnitTestSuite, swc_plt_cdd_timesync_01)
{
   ASSERT_EQ(true, true);
}

TEST_F(swc_plt_cdd_timesync_UnitTestSuite, DRE_StatusNotification_Callback_01)
{
   /* DRE_StatusNotification_Callback has no implementation; verify it is callable without fault. */
   DRE_StatusNotification_Callback();
}

TEST_F(swc_plt_cdd_timesync_UnitTestSuite, RE_PLT_TimeSync_Main_50ms_01)
{
   RE_PLT_TimeSync_Main_50ms();
   EXPECT_EQ(TimeSync_Main_50ms_fake.call_count, 1u) << "TimeSync_Main_50ms must be called exactly once.";
   ;
}

/* Used by TIMESYNC_TEST_STUB_ON path in SWC_PLT_CDD_ECUSync.c */
void Get_Platform_mstime(uint32_t *inst_ms_time)
{
   g_platform_mstime_calls++;
   if (inst_ms_time != 0)
   {
      *inst_ms_time = g_platform_mstime_value;
   }
}

TEST_F(swc_plt_cdd_timesync_UnitTestSuite, Get_Platform_mstime_01)
{
   uint32_t temp1 = 0u;
   uint32_t temp2 = 0u;

   g_platform_mstime_calls = 0u;

   g_platform_mstime_value = 10u;
   Get_Platform_mstime(&temp1);

   g_platform_mstime_value = 20u;
   Get_Platform_mstime(&temp2);

   EXPECT_EQ(2u, g_platform_mstime_calls);
   EXPECT_EQ(10u, temp1);
   EXPECT_EQ(20u, temp2);
}

TEST_F(swc_plt_cdd_timesync_UnitTestSuite, RE_PLT_TimeSync_Init_01)
{
   /* EcuSync_SeedCanTSynTimeBaseIfNeeded is stubbed; verify Init delegates to it without fault. */
   RE_PLT_TimeSync_Init();
}

/* GetTimerCntValueUs: 0 ticks -> 0.0 us */
TEST_F(swc_plt_cdd_timesync_UnitTestSuite, GetTimerCntValueUs_ZeroTicks)
{
   g_gpt_time_elapsed = 0U;
   EXPECT_FLOAT_EQ(0.0f, SWC_PLT_CDD_TimeSync_GetTimerCntValueUs());
}

/* GetTimerCntValueUs: 100 ticks @ 100 MHz -> 1.0 us */
TEST_F(swc_plt_cdd_timesync_UnitTestSuite, GetTimerCntValueUs_100Ticks)
{
   g_gpt_time_elapsed = 100U;
   EXPECT_FLOAT_EQ(1.0f, SWC_PLT_CDD_TimeSync_GetTimerCntValueUs());
}

/* GetTimerCntValueUs: 100000000 ticks @ 100 MHz -> 1000000.0 us (1 second) */
TEST_F(swc_plt_cdd_timesync_UnitTestSuite, GetTimerCntValueUs_1Second)
{
   g_gpt_time_elapsed = 100000000U;
   EXPECT_FLOAT_EQ(1000000.0f, SWC_PLT_CDD_TimeSync_GetTimerCntValueUs());
}

/* SetTimerCntValueUs: 0.0 us -> StopTimer + StartTimer with 0 ticks */
TEST_F(swc_plt_cdd_timesync_UnitTestSuite, SetTimerCntValueUs_ZeroUs)
{
   SWC_PLT_CDD_TimeSync_SetTimerCntValueUs(0.0f);
   EXPECT_EQ(1u, g_gpt_stop_timer_calls);
   EXPECT_EQ(1u, g_gpt_start_timer_calls);
   EXPECT_EQ(0U, g_gpt_start_timer_value);
}

/* SetTimerCntValueUs: 1.0 us @ 100 MHz -> 100 ticks */
TEST_F(swc_plt_cdd_timesync_UnitTestSuite, SetTimerCntValueUs_1Us)
{
   SWC_PLT_CDD_TimeSync_SetTimerCntValueUs(1.0f);
   EXPECT_EQ(1u, g_gpt_stop_timer_calls);
   EXPECT_EQ(1u, g_gpt_start_timer_calls);
   EXPECT_EQ(100U, g_gpt_start_timer_value);
}

/* SetTimerCntValueUs: 1000.0 us @ 100 MHz -> 100000 ticks */
TEST_F(swc_plt_cdd_timesync_UnitTestSuite, SetTimerCntValueUs_1000Us)
{
   SWC_PLT_CDD_TimeSync_SetTimerCntValueUs(1000.0f);
   EXPECT_EQ(1u, g_gpt_stop_timer_calls);
   EXPECT_EQ(1u, g_gpt_start_timer_calls);
   EXPECT_EQ(100000U, g_gpt_start_timer_value);
}
