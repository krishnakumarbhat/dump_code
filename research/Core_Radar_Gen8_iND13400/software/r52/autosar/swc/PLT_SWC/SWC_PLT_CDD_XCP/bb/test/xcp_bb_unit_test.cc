/*===========================================================================*/
/**
 * @file xcp_bb_unit_test.cc
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
 * Unit test suite for the checking the xcp_bb.c file
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
#include "xcp_bb_fake.h"
#include "xcp_user_cmds_fake.h"

extern "C"
{
#include "xcp_bb.c"
}

DEFINE_FFF_GLOBALS;

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class xcp_core_UnitTestSuite : public testing::Test
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

// Class for xcp periodic task function

class xcp_periodic_task_UnitTestSuite : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
   }

   void TearDown()
   {
   }
};

/*===========================================================================*
 * Variable Declarations
 *===========================================================================*/
/*
static XCP_ADC_Cmd_T xcp_adc_cmd                   = {CODED_TRUE, 0, 0, 0};
static XCP_OVERRIDE_Cmd_T xcp_override_cmd         = {0, CODED_TRUE, 0};
static XCP_Checksum_Cmd_T xcp_chksm_cmd            = {CODED_TRUE, 0};
static XCP_ADC_FILTERED_Cmd_T xcp_adc_filtered_cmd = {CODED_TRUE, 0, 0, 0};
*/
static XCP_Periodic_User_Cmd_T XCP_Periodic_User_Cmd     = {NULL, CODED_FALSE, 0, 0, 0};
XCP_Periodic_User_Cmd_T *const XCP_Periodic_User_Cmd_Ptr = &XCP_Periodic_User_Cmd;
static XCP_Target_Info_T xcp_target_info                 = {
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, false},
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
XCP_BB_Input_Params_T *const l_xcp_bb_input_params = &(XCP_BB_Input_Params_Initialise);
uint8_t response[64]                               = {0};
uint8_t framelength;
/*===========================================================================*
 * Test Cases
 *===========================================================================*/

/**
 *  XCP_CORE_SANITY_CHECK
 */

TEST_F(xcp_core_UnitTestSuite, xcp_core_Config__SANITY_CHECK_)
{
   ASSERT_EQ(true, true);
}

/**
 *  XCP_BB_REFRESH_DYNAMIC_DATA
 */

TEST_F(xcp_core_UnitTestSuite, XCP_BB_Refresh_Dynamic_Data_OK)
{
   uint8_t return_value = 0;
   XCP_BB_Init_Const_Ptr();
   XCP_BB_Refresh_Dynamic_Data();
   EXPECT_EQ(
      return_value,
      l_xcp_bb_input_params->num_fault_bytes); // The input of the variable assigned is "0" so is the output in the test file
   EXPECT_EQ(return_value, l_xcp_bb_input_params->num_analog_inputs);
}

/*
 *  XCP_PERIODIC_TASK
 */

TEST_F(xcp_periodic_task_UnitTestSuite, xcp_periodic_task_TC1)
{
   uint8_t return_val;
   return_val = XCP_Periodic_Task(response, &framelength);
   EXPECT_EQ(return_val, XCP_CMD_SYNTAX_CPV);
}

TEST_F(xcp_periodic_task_UnitTestSuite, xcp_periodic_task_TC2)
{
   uint8_t return_val;
   XCP_Periodic_User_Cmd_Task_Fptr fptr              = &XCP_ADC_info_Periodic_Task;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cmnd_fptr = fptr;
   return_val                                        = XCP_Periodic_Task(response, &framelength);
}
