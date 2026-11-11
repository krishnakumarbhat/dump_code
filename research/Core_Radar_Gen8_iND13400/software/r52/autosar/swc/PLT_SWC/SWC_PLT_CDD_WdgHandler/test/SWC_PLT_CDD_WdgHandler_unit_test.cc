/*===========================================================================*/
/**
 * @file SWC_PLT_CDD_WdgHandler_unit_test.cc
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
 * Unit test suite for the checking the SWC_PLT_CDD_WdgHandler.c file
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
//#include "fff.h"
#include "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe/test/FailSafe_callout_fake.h"

extern "C"
{
#include "SWC_PLT_CDD_WdgHandler.c"
#include "SWC_PLT_CDD_WdgHandler_Test.c"
#include "SWC_PLT_CDD_WdgHandler_fake.h"

   uint8 Rte_SWC_PLT_CDD_WdgHandler_Pp_Internal_Wdg_Fail_Status_Internal_Wdg_Fail_Status = 0U;
}
DEFINE_FFF_GLOBALS

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class swc_plt_wdghandler_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_RESET_HISTORY();
      Rte_SWC_PLT_CDD_WdgHandler_Pp_Internal_Wdg_Fail_Status_Internal_Wdg_Fail_Status = 0U;
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
 *  @b SWC_PLT_Appl_Wdg_sanity
 *  @n
 */
TEST_F(swc_plt_wdghandler_UnitTestSuite, swc_plt_wdg_Config__SANITY_CHECK_)
{
   ASSERT_EQ(true, true);
}

/**
 *  @b RE_PLT_WdgHandler_Init_test
 *  @n
 */

TEST_F(swc_plt_wdghandler_UnitTestSuite, RE_PLT_WdgHandler_Init_test)
{
   /* The body of this function is not enabled once its enabled we can use this test case*/
   RE_PLT_WdgHandler_Init();
   ASSERT_EQ(true, true);
}

/**
 *  @b CS_Wdg_Disable_test_IntWdg_Fail
 *  @n
 */

TEST_F(swc_plt_wdghandler_UnitTestSuite, CS_Wdg_Disable_test_IntWdg_Fail)
{
   /* The body of this function is not enabled once its enabled we can use this test case*/
   CS_Wdg_Disable(0);
   ASSERT_EQ(true, true);
}

/**
 *  @b CS_WdgHandler_Fault_Injection_Read
 *  @n
 */

TEST_F(swc_plt_wdghandler_UnitTestSuite, CS_WdgHandler_Fault_Injection_Read)
{
   /* The body of this function is not enabled once its enabled we can use this test case*/
   CS_WdgHandler_Fault_Injection_Read(0, 0);
   ASSERT_EQ(true, true);
}

/**
 *  @b Internal_Wdg_Instance_SetTriggerCondition
 *  @n
 */

TEST_F(swc_plt_wdghandler_UnitTestSuite, Internal_Wdg_Instance_SetTriggerCondition)
{
   Internal_Wdg_Instance_SetTriggerCondition(15);
   ASSERT_EQ(Appl_Internal_Wdg_Instance_SetTriggerCondition_fake.call_count, 1);
}

/**
 *  @b Internal_Wdg_Instance_SetMode
 *  @n
 */

TEST_F(swc_plt_wdghandler_UnitTestSuite, Internal_Wdg_Instance_SetMode)
{
   Internal_Wdg_Instance_SetMode(WDGIF_FAST_MODE);
   ASSERT_EQ(Appl_Internal_Wdg_Instance_SetMode_fake.return_val, E_OK);
}

TEST_F(swc_plt_wdghandler_UnitTestSuite, WdghandlerIntegrationTest_WritesFailStatusWhenEnabled)
{
   Test_Intwdg_Fail_Status = 1U;
   Wdghandler_Integration_Test();
   ASSERT_EQ(Rte_SWC_PLT_CDD_WdgHandler_Pp_Internal_Wdg_Fail_Status_Internal_Wdg_Fail_Status, CODED_TRUE);
}

/**
 *  @b WdgTriggerLocation_WdgGeneral
 *  @n
 */

TEST_F(swc_plt_wdghandler_UnitTestSuite, WdgTriggerLocation_WdgGeneral_01)
{
   WdgTriggerLocation_WdgGeneral();
   ASSERT_EQ(true, true);
}
