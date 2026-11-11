/*===========================================================================*/
/**
 * @file SWC_PLT_CDD_ExternalWdg_unit_test.cc
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
 * Unit test suite for the checking the SWC_PLT_Appl_FaultMgr.c file
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
#include "SWC_PLT_CDD_ExternalWdg_fake.h"
#include "dd_pmic_mocks.h"
#include "fff.h"
#include <gtest/gtest.h>
/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/

extern "C"
{
#include "SWC_PLT_CDD_ExternalWdg.c"
}
DEFINE_FFF_GLOBALS

#if ((STD_ON == ENABLE_SQT_TEST_STUBS) || (STD_ON == ENABLE_SIT_TEST_STUBS) || (STD_ON == XCP_FAULT_INJECTION))
   #define EXTWDG_TEST_FLAGS_ENABLED (1U)
#else
   #define EXTWDG_TEST_FLAGS_ENABLED (0U)
#endif

// RTE data elements needed by the conditional compilation paths
uint8 Rte_SWC_PLT_CDD_WdgHandler_Pp_Internal_Wdg_Fail_Status_Internal_Wdg_Fail_Status                 = 0U;
uint8 Rte_SWC_PLT_CDD_WdgHandler_Pp_Wdg_Fault_Injection_Request_ExtWdg_De_Wdg_Fault_Injection_Request = 0U;
uint8 Rte_SWC_PLT_CDD_ExternalWdg_Pp_external_watchdog_init_status_de_wdginit_status                  = 0U;
uint8 Rte_SWC_PLT_CDD_ExternalWdg_Pp_externalwatchdogstatus_de_externalwatchdogstatus                 = 0U;

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class swc_plt_cdd_wdg_externalwdg_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_FAKES_PMIC_LIST(RESET_FAKE);
      FFF_RESET_HISTORY();

      // Initialize RTE data elements
      Rte_SWC_PLT_CDD_WdgHandler_Pp_Internal_Wdg_Fail_Status_Internal_Wdg_Fail_Status                 = 0U;
      Rte_SWC_PLT_CDD_WdgHandler_Pp_Wdg_Fault_Injection_Request_ExtWdg_De_Wdg_Fault_Injection_Request = 0U;
      Rte_SWC_PLT_CDD_ExternalWdg_Pp_external_watchdog_init_status_de_wdginit_status                  = 0U;
      Rte_SWC_PLT_CDD_ExternalWdg_Pp_externalwatchdogstatus_de_externalwatchdogstatus                 = 0U;

      // Initialize global variables
      ExtWatchdog_Task_Delay   = 0U;
      External_Watchdog_Status = CODED_FALSE;
#if ((STD_ON == ENABLE_SQT_TEST_STUBS) || (STD_ON == ENABLE_SIT_TEST_STUBS) || (STD_ON == XCP_FAULT_INJECTION))
      test_flag_externalwdg_fault = 0U;
      IntWDG_Fail_Status          = CODED_FALSE;
#endif
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
 *  @b SWC_PLT_CDD_ExternalWdg_sanity
 *  @n
 */
TEST_F(swc_plt_cdd_wdg_externalwdg_UnitTestSuite, swc_plt_cdd_wdg_externalwdg_Config__SANITY_CHECK_)
{
   ASSERT_EQ(true, true);
}
/**
 *  @b swc_plt_cdd_wdg_externalwdg_TestEmptyFunctions
 *  @n
 */
TEST_F(swc_plt_cdd_wdg_externalwdg_UnitTestSuite, swc_plt_cdd_wdg_externalwdg_Test_Unused_Functions)
{
   CS_Pp_ExtWdg_Disable_Operation();
   CS_Pp_ExtWdg_Enable_Operation();
   ASSERT_EQ(true, true);
}
/**
 *  @b RE_PLT_ExternalWdg_Init_Test
 *  @n
 */

TEST_F(swc_plt_cdd_wdg_externalwdg_UnitTestSuite, RE_PLT_ExternalWdg_Init_Test)
{
   RE_PLT_ExternalWdg_Init();
   ASSERT_EQ(Pmic_Watchdog_Init_fake.call_count, 1U);
   ASSERT_EQ(Pmic_Spread_Spectrum_Disable_fake.call_count, 1U);
}

/**
 *  @b RE_CDD_Ext_Wdg_50ms_Test1
 *  @n Test with PMIC returning CODED_TRUE (but overridden by conditional block)
 */

TEST_F(swc_plt_cdd_wdg_externalwdg_UnitTestSuite, RE_CDD_Ext_Wdg_50ms_Test1)
{
   Pmic_Check_Wdg_Dis_Status_fake.return_val = CODED_TRUE;
   External_Watchdog_Status                  = CODED_FALSE;
#if (EXTWDG_TEST_FLAGS_ENABLED == 1U)
   test_flag_externalwdg_fault = CODED_FALSE;
#endif

   RE_CDD_Ext_Wdg_50ms();

   ASSERT_EQ(Pmic_Check_Wdg_Dis_Status_fake.call_count, 1U);
   // With conditional compilation enabled, test_flag_externalwdg_fault=FALSE overrides PMIC value.
#if (EXTWDG_TEST_FLAGS_ENABLED == 1U)
   ASSERT_EQ(External_Watchdog_Status, CODED_FALSE);
   ASSERT_EQ(Rte_SWC_PLT_CDD_ExternalWdg_Pp_externalwatchdogstatus_de_externalwatchdogstatus, CODED_FALSE);
#else
   ASSERT_EQ(External_Watchdog_Status, CODED_TRUE);
   ASSERT_EQ(Rte_SWC_PLT_CDD_ExternalWdg_Pp_externalwatchdogstatus_de_externalwatchdogstatus, CODED_TRUE);
#endif
}

/**
 *  @b RE_CDD_Ext_Wdg_50ms_Test2
 *  @n
 */
TEST_F(swc_plt_cdd_wdg_externalwdg_UnitTestSuite, RE_CDD_Ext_Wdg_50ms_Test2)
{
   Pmic_Check_Wdg_Dis_Status_fake.return_val = CODED_FALSE;
   External_Watchdog_Status                  = CODED_TRUE;

   RE_CDD_Ext_Wdg_50ms();

   ASSERT_EQ(Pmic_Check_Wdg_Dis_Status_fake.call_count, 1U);
   ASSERT_EQ(Pmic_Watchdog_Service_fake.call_count, 0U);
   ASSERT_EQ(External_Watchdog_Status, CODED_FALSE);
   ASSERT_EQ(Rte_SWC_PLT_CDD_ExternalWdg_Pp_externalwatchdogstatus_de_externalwatchdogstatus, CODED_FALSE);
}

/**
 *  @b RE_CDD_Ext_Wdg_5ms_test1
 *  @n
 */
TEST_F(swc_plt_cdd_wdg_externalwdg_UnitTestSuite, RE_CDD_Ext_Wdg_5ms_test1)
{
   ExtWatchdog_Task_Delay = 0U;
   RE_CDD_Ext_Wdg_5ms();
   ASSERT_EQ(ExtWatchdog_Task_Delay, 1U);
   ASSERT_EQ(Pmic_Watchdog_Service_fake.call_count, 0U);
}

/**
 *  @b RE_CDD_Ext_Wdg_5ms_test2
 *  @n
 */
TEST_F(swc_plt_cdd_wdg_externalwdg_UnitTestSuite, RE_CDD_Ext_Wdg_5ms_test2)
{
   ExtWatchdog_Task_Delay = TASK_DELAY_30_MS;
   RE_CDD_Ext_Wdg_5ms();
   ASSERT_EQ(ExtWatchdog_Task_Delay, 0U);
   ASSERT_EQ(Pmic_Watchdog_Service_fake.call_count, 1U);
}

/**
 *  @b CS_External_Watchdog_Fault_Injection_Read_DefaultParams
 *  @n Test with default parameters (no fault injection active)
 */
TEST_F(swc_plt_cdd_wdg_externalwdg_UnitTestSuite, CS_External_Watchdog_Fault_Injection_Read_DefaultParams)
{
   uint8 Injection_control = 0U;
   uint8 Failure_Type      = 0U;
   CS_External_Watchdog_Fault_Injection_Read(Injection_control, Failure_Type);
   // Function completes successfully (no crash)
   ASSERT_EQ(true, true);
}

#if (STD_ON == XCP_FAULT_INJECTION)
/**
 *  @b CS_External_Watchdog_Fault_Injection_Read_InjectFault
 *  @n Test injecting external watchdog fault
 */
TEST_F(swc_plt_cdd_wdg_externalwdg_UnitTestSuite, CS_External_Watchdog_Fault_Injection_Read_InjectFault)
{
   test_flag_externalwdg_fault = 0U;

   CS_External_Watchdog_Fault_Injection_Read(IC_INJECT_FAULT, FT_EXT_WDT_FAILURE);

   ASSERT_EQ(test_flag_externalwdg_fault, CODED_TRUE);
}

/**
 *  @b CS_External_Watchdog_Fault_Injection_Read_RemoveFault
 *  @n Test removing external watchdog fault
 */
TEST_F(swc_plt_cdd_wdg_externalwdg_UnitTestSuite, CS_External_Watchdog_Fault_Injection_Read_RemoveFault)
{
   test_flag_externalwdg_fault = CODED_TRUE;

   CS_External_Watchdog_Fault_Injection_Read(IC_REMOVE_FAULT, FT_EXT_WDT_FAILURE);

   ASSERT_EQ(test_flag_externalwdg_fault, CODED_FALSE);
}

/**
 *  @b CS_External_Watchdog_Fault_Injection_Read_InvalidInjectionControl
 *  @n Test with invalid injection control value - should do nothing
 */
TEST_F(swc_plt_cdd_wdg_externalwdg_UnitTestSuite, CS_External_Watchdog_Fault_Injection_Read_InvalidInjectionControl)
{
   const uint8 INVALID_CONTROL = 0x99U;

   test_flag_externalwdg_fault = 0U;
   uint8 initial_value         = test_flag_externalwdg_fault;

   CS_External_Watchdog_Fault_Injection_Read(INVALID_CONTROL, FT_EXT_WDT_FAILURE);

   // Value should remain unchanged
   ASSERT_EQ(test_flag_externalwdg_fault, initial_value);
}

/**
 *  @b CS_External_Watchdog_Fault_Injection_Read_WrongFailureType
 *  @n Test with wrong failure type - should do nothing
 */
TEST_F(swc_plt_cdd_wdg_externalwdg_UnitTestSuite, CS_External_Watchdog_Fault_Injection_Read_WrongFailureType)
{
   const uint8 INVALID_FAILURE_TYPE = 0x99U;

   test_flag_externalwdg_fault = 0U;
   uint8 initial_value         = test_flag_externalwdg_fault;

   CS_External_Watchdog_Fault_Injection_Read(IC_INJECT_FAULT, INVALID_FAILURE_TYPE);

   // Value should remain unchanged because failure type doesn't match
   ASSERT_EQ(test_flag_externalwdg_fault, initial_value);
}
/**
 *  @b CS_External_Watchdog_Fault_Injection_Read_PMIC_InvalidInjectionControl
 *  @n Test PMIC fault injection with invalid control value - should do nothing
 */
TEST_F(swc_plt_cdd_wdg_externalwdg_UnitTestSuite, CS_External_Watchdog_Fault_Injection_Read_PMIC_InvalidInjectionControl)
{
   const uint8 INVALID_CONTROL = 0x99U;

   PMIC_MCU_Comm_Fault     = CODED_FALSE;
   uint8 initial_pmic_flag = PMIC_MCU_Comm_Fault;

   CS_External_Watchdog_Fault_Injection_Read(INVALID_CONTROL, FT_PMIC_MCU_COMM_FAILURE);

   // Value should remain unchanged
   ASSERT_EQ(PMIC_MCU_Comm_Fault, initial_pmic_flag);
}
#endif

#if (EXTWDG_TEST_FLAGS_ENABLED == 1U)
/**
 *  @b RE_CDD_Ext_Wdg_50ms_Test_ConditionalBlock_FaultInjected
 *  @n Test conditional compilation path when fault is injected
 */
TEST_F(swc_plt_cdd_wdg_externalwdg_UnitTestSuite, RE_CDD_Ext_Wdg_50ms_Test_ConditionalBlock_FaultInjected)
{
   Pmic_Check_Wdg_Dis_Status_fake.return_val = CODED_FALSE;
   test_flag_externalwdg_fault               = CODED_TRUE;
   External_Watchdog_Status                  = CODED_FALSE;

   RE_CDD_Ext_Wdg_50ms();

   // When test_flag_externalwdg_fault is TRUE, External_Watchdog_Status should be set to CODED_TRUE
   ASSERT_EQ(External_Watchdog_Status, CODED_TRUE);
   ASSERT_EQ(Pmic_Check_Wdg_Dis_Status_fake.call_count, 1U);
}

/**
 *  @b RE_CDD_Ext_Wdg_50ms_Test_ConditionalBlock_FaultNotInjected
 *  @n Test conditional compilation path when fault is not injected
 */
TEST_F(swc_plt_cdd_wdg_externalwdg_UnitTestSuite, RE_CDD_Ext_Wdg_50ms_Test_ConditionalBlock_FaultNotInjected)
{
   Pmic_Check_Wdg_Dis_Status_fake.return_val = CODED_TRUE;
   test_flag_externalwdg_fault               = CODED_FALSE;
   External_Watchdog_Status                  = CODED_TRUE;

   RE_CDD_Ext_Wdg_50ms();

   // When test_flag_externalwdg_fault is FALSE, External_Watchdog_Status should be set to CODED_FALSE
   ASSERT_EQ(External_Watchdog_Status, CODED_FALSE);
   ASSERT_EQ(Pmic_Check_Wdg_Dis_Status_fake.call_count, 1U);
}
#endif
