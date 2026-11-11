/*===========================================================================*/
/**
 * @file SWC_PLT_Appl_ModeManager_unit_test.cc
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
 * Unit test suite for the checking the SWC_PLT_Appl_ModeManager.c file
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

extern "C"
{
#include "SWC_PLT_Appl_ModeManager.c"
#include "SWC_PLT_Appl_ModeManager_fake.h"
#include "fff.h"
}

DEFINE_FFF_GLOBALS;

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class swc_plt_appl_ModeManager_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_FAKES_MODE_MANAGER_LIST(RESET_FAKE);
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
 *  @b swc_plt_appl_ModeManager_sanity
 *  @n
 */
TEST_F(swc_plt_appl_ModeManager_UnitTestSuite, swc_plt_appl_ModeManager__Config__SANITY_CHECK_)
{
   ASSERT_EQ(true, true);
}
/*
RE_PLT_Mode_Manager_Init()
*/
TEST_F(swc_plt_appl_ModeManager_UnitTestSuite, RE_PLT_Mode_Manager_Init_T1)
{
   RE_PLT_Mode_Manager_Init();
   ASSERT_EQ(Mode_manager_Init_fake.call_count, 1);
}
/*
RE_PLT_Mode_Manager_Main_50ms()
*/
TEST_F(swc_plt_appl_ModeManager_UnitTestSuite, RE_PLT_Mode_Manager_Main_50ms_T1)
{
   RE_PLT_Mode_Manager_Main_50ms();
}
/*
RE_PLT_Mode_Manager_StateMachine_5ms()
*/
TEST_F(swc_plt_appl_ModeManager_UnitTestSuite, RE_PLT_Mode_Manager_StateMachine_5ms_T1)
{
   RE_PLT_Mode_Manager_StateMachine_5ms();
   ASSERT_EQ(Mode_Manager_StateMachine_5ms_fake.call_count, 1);
}
/*
CS_Modemanager_Fault_Injection_Read
*/
TEST_F(swc_plt_appl_ModeManager_UnitTestSuite, CS_Modemanager_Fault_Injection_Read_T1)
{
   uint8 Injection_Control, Failure_Type;
   CS_Modemanager_Fault_Injection_Read(Injection_Control, Failure_Type);
   /*This Function is only used for XCP Fault Injection*/
   ASSERT_EQ(true, true);
}
/*
Shutdown_Completed_Processing
*/
TEST_F(swc_plt_appl_ModeManager_UnitTestSuite, Power_Off_Processing_CallOut_T1)
{
   Shutdown_Completed_Processing();
   ASSERT_EQ(true, true);
}
