/*===========================================================================*/
/**
 * @file SWC_PLT_Appl_Diag_unit_test.cc
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
 * Unit test suite for the checking the SWC_PLT_Appl_Diag.c file
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
#include "SWC_PLT_Appl_Diag_fake.h"
#include "fff.h"

extern "C"
{
#include "SWC_PLT_Appl_Diag.c"
}

DEFINE_FFF_GLOBALS;

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class swc_plt_appl_diag_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_FAKES_RADAR_STATUS_LIST(RESET_FAKE);
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

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

/**
 *  @b swc_plt_appl_diag_sanity
 *  @n
 */
TEST_F(swc_plt_appl_diag_UnitTestSuite, swc_plt_appl_diag__Config__SANITY_CHECK_)
{
   ASSERT_EQ(true, true);
}
/**
 *  @b RE_PLT_Diag_Battery_Fault_Tests_50ms
 *  @n
 */
TEST_F(swc_plt_appl_diag_UnitTestSuite, RE_PLT_Diag_Battery_Fault_Tests_50ms_test1)
{
   RE_PLT_Diag_Battery_Fault_Tests_50ms();
   ASSERT_EQ(Diag_Battery_Fault_Tests_50ms_fake.call_count, 1);
}
/**
 *  @b RE_PLT_Diag_Can_Bus_Off_Fault_Test_50ms
 *  @n
 */
TEST_F(swc_plt_appl_diag_UnitTestSuite, RE_PLT_Diag_Can_Bus_Off_Fault_Test_50ms_T1)
{
   RE_PLT_Diag_Can_Bus_Off_Fault_Test_50ms();
   ASSERT_EQ(Diag_Can_Bus_Off_Fault_Test_50ms_fake.call_count, 1);
}
/**
 *  @b RE_PLT_Diag_Host_Microcontroller_Tests_50ms
 *  @n
 */
TEST_F(swc_plt_appl_diag_UnitTestSuite, RE_PLT_Diag_Host_Microcontroller_Tests_50ms_T1)
{
   RE_PLT_Diag_Host_Microcontroller_Tests_50ms();
   ASSERT_EQ(Diag_Host_Microcontroller_Tests_50ms_fake.call_count, 1);
}
/**
 *  @b RE_PLT_Diag_Init
 *  @n
 */
TEST_F(swc_plt_appl_diag_UnitTestSuite, RE_PLT_Diag_Init_T1)
{
   RE_PLT_Diag_Init();
   ASSERT_EQ(Diag_Init_fake.call_count, 1);
}
/**
 *  @b RE_PLT_Diag_Inter_Processor_Communication_Diagnostics_50ms
 *  @n
 */
TEST_F(swc_plt_appl_diag_UnitTestSuite, RE_PLT_Diag_Inter_Processor_Communication_Diagnostics_50ms_T1)
{
   RE_PLT_Diag_Inter_Processor_Communication_Diagnostics_50ms();
   ASSERT_EQ(Diag_Inter_Processor_Communication_Diagnostics_50ms_fake.call_count, 1);
}

/**
 *  @b RE_PLT_Diag_Memory_Diagnostics_50ms
 *  @n
 */
TEST_F(swc_plt_appl_diag_UnitTestSuite, RE_PLT_Diag_Memory_Diagnostics_50ms_T1)
{
   RE_PLT_Diag_Memory_Diagnostics_50ms();
   ASSERT_EQ(Diag_Memory_Diagnostics_50ms_fake.call_count, 1);
}

/**
 *  @b RE_PLT_Diag_Radar_Blockage_Detection_Test_50ms
 *  @n
 */
TEST_F(swc_plt_appl_diag_UnitTestSuite, RE_PLT_Diag_Radar_Blockage_Detection_Test_50ms_T1)
{
   RE_PLT_Diag_Radar_Blockage_Detection_Test_50ms();
   ASSERT_EQ(Diag_Radar_Blockage_Detection_Test_50ms_fake.call_count, 1);
   ASSERT_EQ(Diag_Radar_Interference_Detection_Test_50ms_fake.call_count, 1);
}
/**
 *  @b RE_PLT_Diag_Radar_Hardware_Tests_50ms
 *  @n
 */
TEST_F(swc_plt_appl_diag_UnitTestSuite, RE_PLT_Diag_Radar_Hardware_Tests_50ms_T1)
{
   RE_PLT_Diag_Radar_Hardware_Tests_50ms();
   ASSERT_EQ(Diag_Radar_Hardware_Tests_50ms_fake.call_count, 1);
}
/**
 *  @b RE_PLT_Diag_Radar_Transceiver_Diagnostics_50ms
 *  @n
 */
TEST_F(swc_plt_appl_diag_UnitTestSuite, RE_PLT_Diag_Radar_Transceiver_Diagnostics_50ms_T1)
{
   RE_PLT_Diag_Radar_Transceiver_Diagnostics_50ms();
   ASSERT_EQ(Diag_Radar_Transceiver_Diagnostics_50ms_fake.call_count, 1);
}
/**
 *  @b RE_PLT_Diag_Microprocessor_Temp_Tests_50ms
 *  @n
 */
TEST_F(swc_plt_appl_diag_UnitTestSuite, RE_PLT_Diag_Microprocessor_Temp_Tests_50ms_T1)
{
   /* The body of this function is not enabled once its enabled we can use this test case*/
   RE_PLT_Diag_Microprocessor_Temp_Tests_50ms();
}
/**
 *  @b RE_PLT_Diag_Alignment_Diagnostics_50ms
 *  @n
 */
TEST_F(swc_plt_appl_diag_UnitTestSuite, RE_PLT_Diag_Alignment_Diagnostics_50ms_T1)
{
   RE_PLT_Diag_Alignment_Diagnostics_50ms();
   ASSERT_EQ(Diag_Alignment_Diagnostics_50ms_fake.call_count, 1);
}
/**
 *  @b RE_PLT_Diag_PlatformTime_Diagnostics_50ms
 *  @n
 */
TEST_F(swc_plt_appl_diag_UnitTestSuite, RE_PLT_Diag_PlatformTime_Diagnostics_50ms)
{
   RE_PLT_Diag_PlatformTime_50ms();
}
