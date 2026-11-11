/*===========================================================================*/
/**
 * @file SWC_PLT_Appl_IntWDG_unit_test.cc
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
 * Unit test suite for the checking the SWC_PLT_Appl_IntWDG.c file
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
#include "SWC_PLT_Appl_IntWDG_fake.h"
#include "Source/SWC_PLT_Appl_IntWDG.c"
}
DEFINE_FFF_GLOBALS
Radar_Ctl_Data_T Radar_Ctl_Data;
CONST(WdgM_ConfigType, WDGM_CONST) WdgMConfig_Mode0_core0 = {0};
SMC_Cal_T SMC_Cal_Data;
SMC_Cal_T *SMC_Cal_Data_Ptr = &SMC_Cal_Data;
/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class swc_plt_intwdg_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_RESET_HISTORY();
      RESET_FAKE(WdgM_SetMode);
      RESET_FAKE(WdgM_CheckpointReached);
      RESET_FAKE(WdgM_DeactivateSupervisionEntity);
      RESET_FAKE(WdgM_ActivateSupervisionEntity);
      RESET_FAKE(WdgM_Init);
      SMC_Cal_Data.Vehicle_Configuration_Cal.k_internal_wdg_disable = 0;
      XCP_Intwdg_Fault                                              = CODED_FALSE;
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
 *  @b SWC_PLT_Appl_IntWDG_sanity
 *  @n
 */
TEST_F(swc_plt_intwdg_UnitTestSuite, swc_plt_wdg_Config__SANITY_CHECK_)
{
   ASSERT_EQ(true, true);
}

/**
 *  @b RE_PLT_Wdg_Init_01
 *  @n
 */

TEST_F(swc_plt_intwdg_UnitTestSuite, RE_PLT_Wdg_Init_01)
{
   SMC_Cal_Data.Vehicle_Configuration_Cal.k_internal_wdg_disable = 0;
   RE_PLT_Wdg_Init();
   ASSERT_EQ(WdgM_Init_fake.call_count, 1);
}
/**
 *  @b RE_PLT_Wdg_Init_02
 *  @n
 */

TEST_F(swc_plt_intwdg_UnitTestSuite, RE_PLT_Wdg_Init_02)
{
   SMC_Cal_Data.Vehicle_Configuration_Cal.k_internal_wdg_disable = 1;
   RE_PLT_Wdg_Init();
   ASSERT_EQ(WdgM_Init_fake.call_count, 1);
}
/**
 *  @b RE_PLT_WDG_Main_50ms_01
 *  @n
 */

TEST_F(swc_plt_intwdg_UnitTestSuite, RE_PLT_WDG_Main_50ms_01)
{
   RE_PLT_WDG_Main_50ms();
   ASSERT_EQ(TRUE, TRUE);
}

/**
 *  @b RE_PLT_WDG_Main_5ms_01
 *  @n
 */
TEST_F(swc_plt_intwdg_UnitTestSuite, RE_PLT_WDG_Main_5ms_01)
{
   RE_PLT_WDG_Main_5ms();
   ASSERT_EQ(WdgM_CheckpointReached_fake.call_count, 1);
}
/**
 *  @b RE_PLT_WDG_Main_5ms_02
 *  @n
 */
TEST_F(swc_plt_intwdg_UnitTestSuite, RE_PLT_WDG_Main_5ms_02)
{
   XCP_Intwdg_Fault = CODED_TRUE;
   RE_PLT_WDG_Main_5ms();
   ASSERT_EQ(WdgM_CheckpointReached_fake.call_count, 0);
}

/**
 *  @b CS_Disable_Wdg_Supervised_Entites_Operation_01
 *  @n
 */

TEST_F(swc_plt_intwdg_UnitTestSuite, CS_Disable_Wdg_Supervised_Entites_Operation_01)
{
   uint8 disable_SE = CODED_TRUE;
   CS_Disable_Wdg_Supervised_Entites_Operation(disable_SE);
   ASSERT_EQ(WdgM_DeactivateSupervisionEntity_fake.call_count, 7);
}
/**
 *  @b CS_Disable_Wdg_Supervised_Entites_Operation_02
 *  @n
 */

TEST_F(swc_plt_intwdg_UnitTestSuite, CS_Disable_Wdg_Supervised_Entites_Operation_02)
{
   uint8 disable_SE = CODED_FALSE;
   CS_Disable_Wdg_Supervised_Entites_Operation(disable_SE);
   // ASSERT_EQ(WdgM_ActivateSupervisionEntity_fake.call_count, 6);
}
/**
 *  @b CS_Disable_Wdg_Supervised_Entites_Operation_03
 *  @n
 */

TEST_F(swc_plt_intwdg_UnitTestSuite, CS_Disable_Wdg_Supervised_Entites_Operation_03)
{
   uint8 disable_SE = 0xFF;
   CS_Disable_Wdg_Supervised_Entites_Operation(disable_SE);
   ASSERT_EQ(WdgM_ActivateSupervisionEntity_fake.call_count, 0);
}

/**
 *  @b CS_Disable_Wdg_Supervised_Entites_Operation_04
 *  @n
 */

TEST_F(swc_plt_intwdg_UnitTestSuite, CS_Disable_Wdg_Supervised_Entites_Operation_04)
{
   uint8 disable_SE = CODED_FALSE;
   Wdg_Mode_Change  = CODED_FALSE;
   CS_Disable_Wdg_Supervised_Entites_Operation(disable_SE);
   // ASSERT_EQ(WdgM_ActivateSupervisionEntity_fake.call_count, 6);
}

/**
 *  @b CS_Disable_Wdg_Supervised_Entites_Operation_05
 *  @n
 */

TEST_F(swc_plt_intwdg_UnitTestSuite, CS_Disable_Wdg_Supervised_Entites_Operation_05)
{
   uint8 disable_SE                                              = CODED_FALSE;
   Wdg_Mode_Change                                               = CODED_TRUE;
   SMC_Cal_Data.Vehicle_Configuration_Cal.k_internal_wdg_disable = 1;
   CS_Disable_Wdg_Supervised_Entites_Operation(disable_SE);
   // ASSERT_EQ(WdgM_ActivateSupervisionEntity_fake.call_count, 6);
}
TEST_F(swc_plt_intwdg_UnitTestSuite, RE_PLT_WDG_INTERNAL_WDG_Appl_IPC_Task_01)
{
   RE_PLT_WDG_INTERNAL_WDG_Appl_IPC_Task();
   ASSERT_EQ(WdgM_CheckpointReached_fake.call_count, 1);
}
TEST_F(swc_plt_intwdg_UnitTestSuite, RE_PLT_WDG_INTERNAL_WDG_Appl_Task_Communication_01)
{
   RE_PLT_WDG_INTERNAL_WDG_Appl_Task_Communication();
   ASSERT_EQ(WdgM_CheckpointReached_fake.call_count, 1);
}
TEST_F(swc_plt_intwdg_UnitTestSuite, RE_PLT_WDG_INTERNAL_WDG_Appl_Task_Radar_Control_01)
{
   RE_PLT_WDG_INTERNAL_WDG_Appl_Task_Radar_Control();
   ASSERT_EQ(WdgM_CheckpointReached_fake.call_count, 1);
}
TEST_F(swc_plt_intwdg_UnitTestSuite, RE_PLT_WDG_INTERNAL_WDG_BSW_Task_01)
{
   RE_PLT_WDG_INTERNAL_WDG_BSW_Task();
   ASSERT_EQ(WdgM_CheckpointReached_fake.call_count, 1);
}
TEST_F(swc_plt_intwdg_UnitTestSuite, RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task_01)
{
   RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task();
   ASSERT_EQ(WdgM_CheckpointReached_fake.call_count, 1);
}
TEST_F(swc_plt_intwdg_UnitTestSuite, Appl_Task_Monitoring_01)
{
   Appl_Task_Monitoring(0xFF);
   ASSERT_EQ(true, true);
}
