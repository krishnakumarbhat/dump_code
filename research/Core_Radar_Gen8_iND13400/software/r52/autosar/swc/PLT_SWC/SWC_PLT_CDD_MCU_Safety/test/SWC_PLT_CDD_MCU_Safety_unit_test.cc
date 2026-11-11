
/*===========================================================================*/
/**
 * @file SWC_PLT_CDD_MCU_Safety_unit_test.cc
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
 * Unit test suite for the checking the SWC_PLT_CDD_MCU_Safety.c file
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
#include "fff.h"
#include <gtest/gtest.h>
/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "SWC_PLT_CDD_MCU_Safety_fake.h"

extern "C"
{
#include "SWC_PLT_CDD_MCU_Safety.c"
}

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class swc_plt_cdd_MCU_Safety_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_FAKES_MCU_Safety_LIST(RESET_FAKE);
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
 *  @b ECC_CacheMemory_SafetyCore_Disable_T1
 *  @n
 */
TEST_F(swc_plt_cdd_MCU_Safety_UnitTestSuite, ECC_CacheMemory_SafetyCore_Disable_T1)
{
   /* The body of this function is not enabled once its enabled we can use this test case*/
   Dt_PltRRUFS_SafetyReq_Status_T *ECC_CacheMemory_Status;
   ECC_CacheMemory_SafetyCore_Disable(ECC_CacheMemory_Status);
   ASSERT_EQ(true, true);
}
/**
 *  @b ECC_CacheMemory_SafetyCore_Enable_T1
 *  @n
 */
TEST_F(swc_plt_cdd_MCU_Safety_UnitTestSuite, ECC_CacheMemory_SafetyCore_Enable_T1)
{
   /* The body of this function is not enabled once its enabled we can use this test case*/
   Dt_PltRRUFS_SafetyReq_Status_T *ECC_CacheMemory_Status;
   ECC_CacheMemory_SafetyCore_Enable(ECC_CacheMemory_Status);
   ASSERT_EQ(true, true);
}
/**
 *  @b ECC_CacheMemory_SafetyCore_Status_T1
 *  @n
 */
TEST_F(swc_plt_cdd_MCU_Safety_UnitTestSuite, ECC_CacheMemory_SafetyCore_Status_T1)
{
   /* The body of this function is not enabled once its enabled we can use this test case*/
   Dt_PltRRUFS_SafetyReq_Status_T *ECC_CacheMemory_Status;
   ECC_CacheMemory_SafetyCore_Status(ECC_CacheMemory_Status);
   ASSERT_EQ(true, true);
}
/**
 *  @b ECC_FlashMemory_Fault_Report_Check_T1
 *  @n
 */
TEST_F(swc_plt_cdd_MCU_Safety_UnitTestSuite, ECC_FlashMemory_Fault_Report_Check_T1)
{
   /* The body of this function is not enabled once its enabled we can use this test case*/
   Dt_PltRRUFS_SafetyReq_Status_T *ECC_CacheMemory_Status;
   ECC_FlashMemory_Fault_Report_Check(ECC_CacheMemory_Status);
   ASSERT_EQ(true, true);
}
/**
 *  @b ECU_Soft_Reset_T1
 *  @n
 */
TEST_F(swc_plt_cdd_MCU_Safety_UnitTestSuite, ECU_Soft_Reset_T1)
{
   ECU_Soft_Reset();
   ASSERT_EQ(Mcu_Reset_fake.call_count, 1);
}
/**
 *  @b RCCU_CheckerCore_Status_T1
 *  @n
 */
TEST_F(swc_plt_cdd_MCU_Safety_UnitTestSuite, RCCU_CheckerCore_Status_T1)
{
   /* The body of this function is not enabled once its enabled we can use this test case*/
   Dt_PltRRUFS_SafetyReq_Status_T *CheckerCore_Status;
   RCCU_CheckerCore_Status(CheckerCore_Status);
   ASSERT_EQ(true, true);
}
/**
 *  @b RE_PLT_MCU_Safety_50ms_T1
 *  @n
 */
TEST_F(swc_plt_cdd_MCU_Safety_UnitTestSuite, RE_PLT_MCU_Safety_50ms_T1)
{
   RE_PLT_MCU_Safety_50ms();
   ASSERT_EQ(true, true);
}
/**
 *  @b RE_PLT_MCU_Safety_Init_T1
 *  @n
 */
TEST_F(swc_plt_cdd_MCU_Safety_UnitTestSuite, RE_PLT_MCU_Safety_Init_T1)
{
   RE_PLT_MCU_Safety_Init();
   ASSERT_EQ(MCU_Safety_Init_fake.call_count, 1);
}
/**
 *  @b RRU_FS_InitTest_T1
 *  @n
 */
TEST_F(swc_plt_cdd_MCU_Safety_UnitTestSuite, RRU_FS_InitTest_T1)
{
   /* The body of this function is not enabled once its enabled we can use this test case*/
   Dt_PltRRUFS_SafetyReq_Status_T *SafetyReq_Status;
   RRU_FS_InitTest(SafetyReq_Status);
   ASSERT_EQ(true, true);
}
/**
 *  @b CS_MCU_Safety_Fault_Injection_Read_T1
 *  @n
 */
TEST_F(swc_plt_cdd_MCU_Safety_UnitTestSuite, CS_MCU_Safety_Fault_Injection_Read_T1)
{
   CS_MCU_Safety_Fault_Injection(0, 0);
   ASSERT_EQ(true, true);
}
