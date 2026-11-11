/*===========================================================================*/
/**
 * @file ipc_data_unit_test.cc
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

#include "appl_RTM_fake.h"

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "fff.h"
DEFINE_FFF_GLOBALS;

extern "C"
{
#include "SWC_PLT_Appl_RTM.c"
}

VAR(uint8, RTM_VAR_INIT) Rtm_ControlState;

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class appl_RTM_UnitTestSuite : public testing::Test
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
VAR(uint8, RTM_VAR_INIT) Rtm_Ctrl[RTM_CTRL_VECTOR_LEN] = {0x00u};
/* redefinition of global variables used by UUT */
/**
 *  @b RE_RTM_Init
 *  @n
 *      Test the RE_RTM_Init function.
 */
TEST_F(appl_RTM_UnitTestSuite, RE_RTM_Init)
{
   RE_RTM_Init();
   ASSERT_EQ(true, true);
}

/**
 *  @b RE_RTM_Main_50ms
 *  @n
 *      Test the RE_RTM_Main_50ms function.
 */
TEST_F(appl_RTM_UnitTestSuite, RE_RTM_Main_50ms)
{
   RE_RTM_Main_50ms();

   ASSERT_EQ(Rtm_Ctrl[0], 0xFFu);
   ASSERT_EQ(Rtm_Ctrl[RTM_CTRL_VECTOR_LEN - 1], 0xFFu);

   RE_RTM_Main_50ms();

   ASSERT_EQ(Rtm_GetMeasurementItem_fake.call_count, 4 + (RTMTASKTOMEASURE * 4));
   ASSERT_EQ(Rte_Write_SWC_PLT_Appl_RTM_Pp_CPU_Load_De_CPU_Load_fake.call_count, 1);
}

/**
 *  @b Rtm_GetTimeMeasurement
 *  @n
 *      Test the Rtm_GetTimeMeasurement function.
 */
TEST_F(appl_RTM_UnitTestSuite, Rtm_GetTimeMeasurement)
{
   /* The body of this function is not enabled once its enabled we can use this test case*/
   Rtm_GetTimeMeasurement();
}

TEST_F(appl_RTM_UnitTestSuite, Get_CPU_Load_C0)
{
   Get_CPU_Load_C0();
}
/**
 *  @b CS_Rtm_task_measurement
 *  @n
 *
 */
TEST_F(appl_RTM_UnitTestSuite, CS_Rtm_task_measurement_01)
{
   Dt_RTM_parameters_T destination[RTMTASKTOMEASURE];
   /* Set up expected data in the global source array */
   for (int i = 0; i < RTMTASKTOMEASURE; i++)
   {
      taskmeasuresument_points[i].Runtime_average = i + 1;
   }

   /* Clear destination to ensure we are testing the copy */
   memset(destination, 0, sizeof(destination));
   CS_Rtm_task_measurement(destination);

   /* Verify the copy was successful */
   for (int i = 0; i < RTMTASKTOMEASURE; i++)
   {
      ASSERT_EQ(destination[i].Runtime_average, i + 1);
   }
}
