/*===========================================================================*/
/**
 * @file dd_gpt_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2022 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for the checking the dd_gpt.c file
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
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/

#include <gtest/gtest.h>

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "Gpt_fake.h"
#include "fff.h"

DEFINE_FFF_GLOBALS;

extern "C"
{
   /* Define FFF fake for System_Clk_GetSysCurrentClock with C linkage */
   FAKE_VALUE_FUNC(uint32, System_Clk_GetSysCurrentClock);

#include "dd_gpt.c"
}

#define GPT_UNITTEST
#define GPT_HARDWARE_VARIANT GPT_B0_HARDWARE_VARIANT
const Gpt_ConfigType Gpt_Config = {};

/*===========================================================================*
 * Custom Fake Functions
 *===========================================================================*/

/**
 * Custom fake that returns 100 MHz (100,000,000 Hz)
 * When used with TIMERS_SRC_CLK() macro (divides by 5), yields 20 MHz timer frequency
 * When used with TIMERS_SRC_CLK_B0() macro (divides by 2), yields 50 MHz timer frequency
 */
uint32 System_Clk_GetSysCurrentClock_100MHz_fake(void)
{
   return 100000000u; /* 100 MHz */
}

/**
 * Custom fake that returns 200 MHz (200,000,000 Hz)
 * When used with TIMERS_SRC_CLK() macro (divides by 5), yields 40 MHz timer frequency
 * When used with TIMERS_SRC_CLK_B0() macro (divides by 2), yields 100 MHz timer frequency
 */
uint32 System_Clk_GetSysCurrentClock_200MHz_fake(void)
{
   return 200000000u; /* 200 MHz */
}
/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class ddGptUnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_FAKES_GPT_FUNCTION(RESET_FAKE);
      FFF_RESET_HISTORY();
      Timestamp_Seconds      = 0u;
      Timestamp_Milliseconds = 0u;
      for (uint8_t i = 0; i < GPT_CONFIGURED_CHANNEL_COUNT; i++)
      {
         GPT_Period[i]    = 0;
         GPT_Frequency[i] = 0;
      }
   }

   /**
    * @b Description
    * @n
    *    Method run after each individual test case.
    */
   void TearDown()
   {
   }
};

/* redefinition of global variables used by UUT */

/**
 *  @b ddGptUnitTestSuite
 *  @n
 *      Test the Unit Tests are functioning correctly.
 */

TEST_F(ddGptUnitTestSuite, Init1)
{
   Init_GPT_Wrapper();
   EXPECT_EQ(GPT_Period[GPT_PHY_TMR_0], (float32)(1 / GPT_Frequency[GPT_PHY_TMR_0]));

   EXPECT_EQ(Gpt_StartTimer_fake.call_count, 3u) << "Gpt_StartTimer not called 3 times.";
   EXPECT_EQ(Gpt_StartTimer_fake.arg0_history[0], GPT_PHY_TMR_2) << "GPT_PHY_TMR_2 not started.";
   EXPECT_EQ(Gpt_StartTimer_fake.arg0_history[1], GPT_PHY_TMR_3) << "GPT_PHY_TMR_3 not started.";
   EXPECT_EQ(Gpt_StartTimer_fake.arg0_history[2], GPT_PHY_TMR_4) << "GPT_PHY_TMR_4 not started.";
   EXPECT_EQ(Gpt_EnableNotification_fake.call_count, 2u) << "Gpt_EnableNotification not called 2 times.";
   EXPECT_EQ(Gpt_EnableNotification_fake.arg0_history[0], GPT_PHY_TMR_2) << "GPT_PHY_TMR_2 notification not enabled.";
   EXPECT_EQ(Gpt_EnableNotification_fake.arg0_history[1], GPT_PHY_TMR_3) << "GPT_PHY_TMR_3 notification not enabled.";
}

TEST_F(ddGptUnitTestSuite, SetTimerCntValue_ms_Init)
{
   for (uint8_t i = 0; i < GPT_CONFIGURED_CHANNEL_COUNT; i++)
   {
      Set_Timer_Cnt_Value_ms((Gpt_TimerPhysicalChannelType)i, 0);
      EXPECT_EQ(Gpt_StopTimer_fake.call_count, i + 1);
      EXPECT_EQ(Gpt_StartTimer_fake.call_count, i + 1);
      EXPECT_EQ(Gpt_StartTimer_fake.arg0_val, i);
      EXPECT_EQ(Gpt_StartTimer_fake.arg1_val, 0);
   }
}

TEST_F(ddGptUnitTestSuite, SetTimerCntValue_ms_InvalidDevice)
{
   Set_Timer_Cnt_Value_ms((Gpt_TimerPhysicalChannelType)17, 0);
   Set_Timer_Cnt_Value_ms((Gpt_TimerPhysicalChannelType)GPT_CONFIGURED_CHANNEL_COUNT, 0);
}

TEST_F(ddGptUnitTestSuite, SetTimerCntValue_ms)
{
   uint32_t ticks_val;
   float32 timer_val_us_input;
   uint32_t initial_stop_count  = Gpt_StopTimer_fake.call_count;
   uint32_t initial_start_count = Gpt_StartTimer_fake.call_count;

   timer_val_us_input = 45000;

   Set_Timer_Cnt_Value_ms(GPT_PHY_TMR_0, timer_val_us_input);
   ticks_val = (uint32_t)(timer_val_us_input * US_2_SEC * GPT_Frequency[GPT_PHY_TMR_0]);

   EXPECT_EQ(Gpt_StopTimer_fake.call_count, initial_stop_count + 1);
   EXPECT_EQ(Gpt_StopTimer_fake.arg0_val, GPT_PHY_TMR_0);
   EXPECT_EQ(Gpt_StartTimer_fake.call_count, initial_start_count + 1);
   EXPECT_EQ(Gpt_StartTimer_fake.arg0_val, GPT_PHY_TMR_0);
   EXPECT_EQ(Gpt_StartTimer_fake.arg1_val, ticks_val);
}

TEST_F(ddGptUnitTestSuite, SetTrigger_Time)
{
   uint32_t trigger_time_ms;
   uint32_t timer_val;

   trigger_time_ms = 1000;

   Set_Trigger_GPT_Time(trigger_time_ms);
   timer_val = COUNTS2MS(trigger_time_ms);
}

TEST_F(ddGptUnitTestSuite, SetTrigger_Time_HWB0)
{
   uint32_t trigger_time_ms;
   uint32_t ret_val;
   uint32_t exp_val;

   trigger_time_ms = 10U;
   ret_val         = Set_Trigger_HWB0_GPT_Time(trigger_time_ms);
   exp_val         = COUNTS2MS_B0(trigger_time_ms);

   EXPECT_EQ(ret_val, exp_val) << "B0 trigger conversion mismatch.";
}

TEST_F(ddGptUnitTestSuite, Free_Running_Timer_Notification)
{
   Free_Running_Timer_Notification();
   Free_Running_Timer_Notification();
   Free_Running_Timer_Notification();
   ASSERT_EQ(Timestamp_Milliseconds, 3) << "Timestamp_Milliseconds not incremented correctly.";

   cnt_ms = 999;
   Free_Running_Timer_Notification();
   ASSERT_EQ(cnt_ms, 0) << "Timestamp_Milliseconds not incremented correctly.";
   ASSERT_EQ(Timestamp_Seconds, 1) << "Timestamp_Milliseconds not incremented correctly.";
}

TEST_F(ddGptUnitTestSuite, Start_Ecu_Sync_Timer)
{
   Start_EcuSync_Timer();

   EXPECT_EQ(Gpt_StartTimer_fake.call_count, 1u) << "Gpt_StartTimer not called.";
   EXPECT_EQ(Gpt_StartTimer_fake.arg0_history[0], GPT_PHY_TMR_1) << "GPT_PHY_TMR_1 not started.";
   EXPECT_EQ(Gpt_EnableNotification_fake.arg0_history[0], GPT_PHY_TMR_1) << "GPT_PHY_TMR_1 notification not enabled.";
}

TEST_F(ddGptUnitTestSuite, GetTimestampMillisecondsInitState)
{
   /* Timestamp_Milliseconds is zeroed in SetUp; verify function returns 0. */
   EXPECT_EQ(Get_Timestamp_Milliseconds(), 0u) << "Get_Timestamp_Milliseconds() should return 0 in init state.";
}

TEST_F(ddGptUnitTestSuite, GetTimestampMillisecondsReturnsValue)
{
   Timestamp_Milliseconds = 12345u;
   EXPECT_EQ(Get_Timestamp_Milliseconds(), 12345u) << "Get_Timestamp_Milliseconds() did not return the expected value.";
}

TEST_F(ddGptUnitTestSuite, GetElapsedTimeMillisecondsZeroElapsed)
{
   Timestamp_Milliseconds   = 500u;
   uint32_t start_timestamp = 500u;
   EXPECT_EQ(Get_Elapsed_Time_Milliseconds(start_timestamp), 0u)
      << "Get_Elapsed_Time_Milliseconds() should return 0 when start equals current.";
}

TEST_F(ddGptUnitTestSuite, GetElapsedTimeMillisecondsSimple)
{
   Timestamp_Milliseconds   = 1000u;
   uint32_t start_timestamp = 400u;
   EXPECT_EQ(Get_Elapsed_Time_Milliseconds(start_timestamp), 600u)
      << "Get_Elapsed_Time_Milliseconds() did not compute correct elapsed time.";
}

TEST_F(ddGptUnitTestSuite, GetElapsedTimeMillisecondsRollover)
{
   /* Simulate uint32_t rollover: current < start due to wrap-around. */
   Timestamp_Milliseconds    = 100u;
   uint32_t start_timestamp  = UINT32_MAX - 99u; /* e.g. 0xFFFFFF9C */
   uint32_t expected_elapsed = 100u + (UINT32_MAX - start_timestamp) + 1u;
   EXPECT_EQ(Get_Elapsed_Time_Milliseconds(start_timestamp), expected_elapsed)
      << "Get_Elapsed_Time_Milliseconds() rollover case calculated incorrectly.";
}

TEST_F(ddGptUnitTestSuite, Init_With100MHz)
{
   /* Set the custom fake to return 100 MHz */
   System_Clk_GetSysCurrentClock_fake.custom_fake = System_Clk_GetSysCurrentClock_100MHz_fake;

   Init_GPT_Wrapper();

   /* Expected timer frequency = 100MHz / 5 = 20 MHz for first set */
   EXPECT_FLOAT_EQ(GPT_Frequency[GPT_PHY_TMR_0], 20000000.0f);
}

TEST_F(ddGptUnitTestSuite, Init_With200MHz)
{
   /* Set the custom fake to return 200 MHz */
   System_Clk_GetSysCurrentClock_fake.custom_fake = System_Clk_GetSysCurrentClock_200MHz_fake;

   Init_GPT_Wrapper();

   /* Expected timer frequency = 200MHz / 5 = 40 MHz for first set */
   EXPECT_FLOAT_EQ(GPT_Frequency[GPT_PHY_TMR_0], 40000000.0f);
}
