/*===========================================================================*/
/**
 * @file Platform_Diag_Callout_unit_test.cc
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
 * Unit test suite for the checking the Platform_Diag_Callout.c file
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

extern "C"
{
#include "Platform_Diag_Callout.c"
}

DEFINE_FFF_GLOBALS;

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class platform_diag_callout_UnitTestSuite : public testing::Test
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

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

/**
 *  @b platform_diag_callout_sanity
 *  @n
 */
TEST_F(platform_diag_callout_UnitTestSuite, platform_diag_callout__Config__SANITY_CHECK_)
{
   ASSERT_EQ(true, true);
}
/**
 *  @b SmcValidationFaultTestPreconditionCheck
 *  @n
 */
TEST_F(platform_diag_callout_UnitTestSuite, SmcValidationFaultTestPreconditionCheck_T1)
{
   Supply_Voltage_Sts    = CODED_TRUE;
   Std_ReturnType result = Smc_Validation_Fault_Test_Precondition_Check();
   ASSERT_EQ(E_OK, result);
}
/**
 *  @b SmcValidationFaultTestPreconditionCheck
 *  @n
 */
TEST_F(platform_diag_callout_UnitTestSuite, SmcValidationFaultTestPreconditionCheck_T2)
{
   Supply_Voltage_Sts    = CODED_FALSE;
   Std_ReturnType result = Smc_Validation_Fault_Test_Precondition_Check();
   ASSERT_EQ(E_NOT_OK, result);
}
