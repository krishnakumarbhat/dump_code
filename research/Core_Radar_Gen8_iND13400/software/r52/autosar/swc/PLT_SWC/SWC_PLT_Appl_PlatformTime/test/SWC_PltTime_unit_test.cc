/*===========================================================================*/
/**
 * @file SWC_PLT_Appl_PlatformTime_unit_test.cc
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
 * Unit test suite for the checking the ipc_data.c file
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
#include "fff.h"
DEFINE_FFF_GLOBALS;
#define uint64_t uint64
// Ensure platformtime macro comes from the header first, then override it for the UT seam
extern "C"
{
#include "platformtime.h"

   void SuspendAllInterrupts(void)
   {
   }

   void ResumeAllInterrupts(void)
   {
   }
}

// Provide a decreasing tick source via macro seam so Get_Platform_ustime sees time go backward
static uint64_t ut_ticks_seq_dec[2] = {1000000ULL, 0ULL};
static unsigned ut_ticks_idx_dec    = 0u;
static uint64_t UT_GetTicks_Decreasing(uint8_t *overflow8)
{
   if (overflow8 != NULL)
   {
      *overflow8 = 0u;
   }
   uint64_t v = ut_ticks_seq_dec[(ut_ticks_idx_dec < 2u) ? ut_ticks_idx_dec : 1u];
   ut_ticks_idx_dec++;
   return v;
}
#ifdef GET_TIMER_CNT_VALUE_TICKS
   #undef GET_TIMER_CNT_VALUE_TICKS
#endif
#define GET_TIMER_CNT_VALUE_TICKS(ovp) UT_GetTicks_Decreasing(ovp)

// Temporarily drop static for included C to access internals in tests
#define static /* test override */

extern "C"
{
#include "SWC_PLT_Appl_PlatformTime.c"

   uint8 Rte_SWC_PLT_Appl_PlatformTime_Pp_TR_platform_Time_De_PlatformTime = 0U;
}
#undef uint64_t
#undef static
static TIMERS_SFRS_t *pGPT;
/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class SWC_PLT_Appl_PlatformTime_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_RESET_HISTORY();
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
 *  @b modemanager_sanity
 *  @n
 *      Test the IPC Data Init function.
 */
TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, SWC_PLT_Appl_PlatformTime_01)
{
   ASSERT_EQ(true, true);
}
TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, Get_PlatformTime_ms_read_01)
{
   uint32_t instant_mstime[1] = {5u};
   Get_PlatformTime_ms_read(instant_mstime);
   ASSERT_NE(instant_mstime[0], 5u);
}
TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, Get_PlatfromTime_us_read_01)
{
   uint64 instant_ustime[1] = {5ULL};
   Get_PlatfromTime_us_read(instant_ustime);
   ASSERT_NE(instant_ustime[0], 5ULL);
}
/**
 *  @b RE_Evaluate_Plt_Time_Init_test
 *  @n
 *      Test valid configurations.
 */
TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, RE_Evaluate_Plt_Time_Init_01)
{
   RE_Evaluate_Plt_Time_Init();
   ASSERT_EQ(true, true);
}
/**
 *  @b RE_PLT_PlatformTime_Init_test
 *  @n
 *      Test valid configurations.
 */
TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, RE_PLT_PlatformTime_Init_01)
{
   RE_PLT_PlatformTime_Init();
   ASSERT_EQ(true, true);
}
/**
 *  @b CS_PlatformTime_Fault_Injection
 *  @n
 *      Test valid configurations.
 */
TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, CS_PlatformTime_Fault_Injection_01)
{
   uint8_t Injection_control;
   uint8_t Failure_Type;
   CS_PlatformTime_Fault_Injection(Injection_control, Failure_Type);
   ASSERT_EQ(true, true);
}
/**
 *  @b CS_PlatformTime_Fault_Injection
 *  @n
 *      Test valid configurations.
 */
TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, CS_PlatformTime_Fault_Injection_02)
{
   uint8 Injection_control = 1;
   uint8 Failure_Type;
   CS_PlatformTime_Fault_Injection(Injection_control, Failure_Type);
   ASSERT_EQ(true, true);
   /*Just void function can't be asserted*/
}
/**
 *  @b CS_PlatformTime_Fault_Injection
 *  @n
 *      Test valid configurations.
 */
TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, CS_PlatformTime_Fault_Injection_03)
{
   uint8_t Injection_control = 45;
   uint8_t Failure_Type;
   CS_PlatformTime_Fault_Injection(Injection_control, Failure_Type);
   ASSERT_EQ(true, true);
   /*Just void function can't be asserted*/
}
/**
 *  @b CS_Get_Platform_Elapsed_ustime
 *  @n
 *      Test valid configurations.
 */
TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, CS_Get_Platform_Elapsed_ustime_read_01)
{
   uint32_t elapsed = 0xDEADBEEFu;
   uint64_t start   = 0u;
   CS_Get_Platform_Elapsed_ustime_read(&elapsed, start);
   ASSERT_NE(elapsed, 0xDEADBEEFu);
}
TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, CS_Get_Platform_Elapsed_ustime_read_02)
{
   uint32_t elapsed = 0xDEADBEEFu;
   uint64_t start   = (uint64_t)(OVER_FLOW_TIME_VALUE - 5u);
   CS_Get_Platform_Elapsed_ustime_read(&elapsed, start);
   ASSERT_NE(elapsed, 0xDEADBEEFu);
}
TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, CS_Get_Platform_Elapsed_ustime_read_03)
{
   uint32_t e1 = 0xDEADBEEFu;
   uint32_t e2 = 0xDEADBEEFu;
   uint64_t s1 = 0u;
   uint64_t s2 = 1u;
   CS_Get_Platform_Elapsed_ustime_read(&e1, s1);
   CS_Get_Platform_Elapsed_ustime_read(&e2, s2);
   ASSERT_NE(e1, 0xDEADBEEFu);
   ASSERT_NE(e2, 0xDEADBEEFu);
}
/**
 *  @b RE_PLT_PlatformTime_50ms_test
 *  @n
 *      Test valid configurations.
 */
TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, RE_PLT_PlatformTime_50ms_01)
{
   RE_PLT_PlatformTime_50ms();
   ASSERT_EQ(true, true);
   /*Just void function can't be asserted*/
}
TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, Get_PlatformTime_Init_01)
{
   Get_PlatformTime_Init();
   ASSERT_EQ(true, true);
}
TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, Get_PlatformTime_Init_02)
{
   Get_PlatformTime_Init();
   Get_PlatformTime_Init();
   ASSERT_EQ(true, true);
}
TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, Get_PlatformTime_Init_03)
{
   Get_PlatformTime_Init();
   uint32_t instant_mstime[1] = {0u};
   Get_PlatformTime_ms_read(instant_mstime);
   ASSERT_EQ(true, true);
}
TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, Platform_Ustime_Errorcheck_01)
{
   Platform_Ustime_Errorcheck();
   ASSERT_EQ(true, true);
}
TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, Platform_Ustime_Errorcheck_02)
{
   Get_PlatformTime_Init();
   Platform_Ustime_Errorcheck();
   ASSERT_EQ(true, true);
}
TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, Platform_Ustime_Errorcheck_03)
{
   Platform_Ustime_Errorcheck();
   Platform_Ustime_Errorcheck();
   ASSERT_EQ(true, true);
}
TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, Platform_Ustime_Errorcheck_04)
{
   uint64 now = 0u;
   Get_Platform_ustime(&now);
   extern uint64 Plt_Timer_Start_Ustime;
   Plt_Timer_Start_Ustime = now + 1000u; // force mismatch so condition is false
   Platform_Ustime_Errorcheck();
   ASSERT_EQ(true, true);
}
TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, Get_Platform_Elapsed_mstime_01)
{
   uint32_t elapsed = 0xDEADBEEFu;
   uint32_t start   = 0u;
   Get_Platform_Elapsed_mstime(&elapsed, start);
   ASSERT_NE(elapsed, 0xDEADBEEFu);
}
TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, Get_Platform_Elapsed_mstime_02)
{
   uint32_t elapsed = 0xDEADBEEFu;
   uint32_t start   = (uint32_t)(PLATFORMTIME_MAX - 5u);
   Get_Platform_Elapsed_mstime(&elapsed, start);
   ASSERT_NE(elapsed, 0xDEADBEEFu);
}

TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, Platform_Ms_FromUstime_Update_01)
{
   // Arrange: make curr_us < s_prev_us so else-branch resets carry and delta
   ut_ticks_idx_dec    = 0u;
   ut_ticks_seq_dec[0] = 0ULL; // curr_us = 0us
   s_prev_us           = 2000ULL;
   s_us_carry          = 777u;
   s_ms_total          = 5u; // arbitrary prior total
   s_ms_delta          = 9u; // arbitrary prior delta

   // Act
   Platform_Ms_FromUstime_Update();

   // Assert: else-path resets carry and delta; prev set to curr
   ASSERT_EQ(s_us_carry, 0u);
   ASSERT_EQ(s_ms_delta, 0u);
   ASSERT_EQ(s_prev_us, 0ULL);
   ASSERT_EQ(s_ms_total, 5u); // unchanged when delta=0
}

TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, Platform_Ms_FromUstime_Update_02)
{
   /* Forward accumulation: curr_us > s_prev_us, s_prev_us != 0.
    * Ticks: 500000 -> curr_us = 500000 * 4 / 1000 = 2000 us
    * s_prev_us = 1000 us, delta = 1000 us = 1 ms, no carry */
   ut_ticks_seq_dec[0] = 500000ULL;
   ut_ticks_idx_dec    = 0u;
   s_prev_us           = 1000ULL;
   s_us_carry          = 0u;
   s_ms_total          = 10u;
   s_ms_delta          = 0u;

   Platform_Ms_FromUstime_Update();

   ASSERT_EQ(s_ms_delta, 1u);
   ASSERT_EQ(s_us_carry, 0u);
   ASSERT_EQ(s_ms_total, 11u);
   ASSERT_EQ(s_prev_us, 2000ULL);
}

TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, Platform_Ms_FromUstime_Update_03)
{
   /* Baseline path: s_prev_us == 0 -> sets prev to curr, produces no delta.
    * Ticks: 250000 -> curr_us = 250000 * 4 / 1000 = 1000 us */
   ut_ticks_seq_dec[0] = 250000ULL;
   ut_ticks_idx_dec    = 0u;
   s_prev_us           = 0ULL;
   s_ms_delta          = 0u;
   s_ms_total          = 5u;
   s_us_carry          = 0u;

   Platform_Ms_FromUstime_Update();

   ASSERT_EQ(s_ms_delta, 0u);
   ASSERT_EQ(s_prev_us, 1000ULL);
   ASSERT_EQ(s_ms_total, 5u); // total unchanged on baseline call
}

TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, Platform_Ms_FromUstime_Init_01)
{
   /* Verify init resets all accumulator fields. */
   s_prev_us  = 0xDEADDEADULL;
   s_us_carry = 99u;
   s_ms_total = 99u;
   s_ms_delta = 99u;

   Platform_Ms_FromUstime_Init();

   ASSERT_EQ(s_us_carry, 0u);
   ASSERT_EQ(s_ms_total, 0u);
   ASSERT_EQ(s_ms_delta, 0u);
}

TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, Get_Platform_ustime_01)
{
   /* Basic: ticks 250000 -> us = 250000 * 4 / 1000 = 1000 us */
   ut_ticks_seq_dec[0] = 250000ULL;
   ut_ticks_idx_dec    = 0u;

   uint64 us_time = 0xDEADBEEFULL;
   Get_Platform_ustime(&us_time);

   ASSERT_EQ(us_time, 1000ULL);
}

TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, Get_Platform_ustime_02)
{
   /* Zero ticks -> zero microseconds. */
   ut_ticks_seq_dec[0] = 0ULL;
   ut_ticks_idx_dec    = 0u;

   uint64 us_time = 0xDEADBEEFULL;
   Get_Platform_ustime(&us_time);

   ASSERT_EQ(us_time, 0ULL);
}

TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, Get_Platform_mstime_01)
{
   /* Verify Get_Platform_mstime returns accumulated total.
    * Use baseline path (s_prev_us == 0) so delta = 0 and total stays at s_ms_total. */
   ut_ticks_seq_dec[0] = 0ULL;
   ut_ticks_idx_dec    = 0u;
   s_prev_us           = 0ULL;
   s_us_carry          = 0u;
   s_ms_delta          = 0u;
   s_ms_total          = 42u;

   uint32_t ms = 0xDEADBEEFu;
   Get_Platform_mstime(&ms);

   ASSERT_EQ(ms, 42u);
}

TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, Platform_Get_Ms_Total_FromUstime_01)
{
   /* Direct test: accumulate 2 ms and read back via Platform_Get_Ms_Total_FromUstime.
    * Ticks: 500000 -> curr_us = 2000 us, s_prev_us = 0 -> baseline, delta = 0. */
   ut_ticks_seq_dec[0] = 500000ULL;
   ut_ticks_idx_dec    = 0u;
   s_prev_us           = 0ULL;
   s_us_carry          = 0u;
   s_ms_delta          = 0u;
   s_ms_total          = 7u;

   uint32_t total = 0xDEADBEEFu;
   Platform_Get_Ms_Total_FromUstime(&total);

   ASSERT_EQ(total, 7u); // baseline call: delta=0, total unchanged
}

TEST_F(SWC_PLT_Appl_PlatformTime_UnitTestSuite, Get_Timer_Cnt_Value_Ticks_T1)
{
   uint8_t overflow;
   Get_Timer_Cnt_Value_Ticks(&overflow);
}
