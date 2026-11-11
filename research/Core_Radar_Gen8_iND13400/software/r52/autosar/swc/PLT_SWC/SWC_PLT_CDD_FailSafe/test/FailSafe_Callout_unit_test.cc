/*===========================================================================*/
/**
 * @file FailSafe_Callout_unit_test.cc
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
 * Unit test suite for the checking the FailSafe_Callout.c file
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
#include "FailSafe_callout_fake.h"
#include "fff.h"
#include <cstring>
#include <gtest/gtest.h>
DEFINE_FFF_GLOBALS;

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
extern "C"
{
#include "FailSafe_Callout.c"
}

VAR(uint8, RTE_VAR_NOINIT) Rte_SWC_PLT_CDD_FailSafe_Pp_Repetitive_Reset_Status_De_Repetitive_Reset_Status = 85U;

CONST(Dt_FailSafe_ResetReason_T, RTE_CONST)
Rte_C_FailSafe_ResetReason_T_Dt_FailSafe_ResetReason_T = {{0U, 0U, 0U, 0U, 0U},
                                                          0U,
                                                          0U,
                                                          0U,
                                                          0U,
                                                          0U,
                                                          {0U, 0U, 0U, FALSE, 0U, 0U},
                                                          {0U, 0U, 0U, 0U, 0U},
                                                          {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}};
Dt_FailSafe_ResetReason_T dt_failsafe_read_buffer;
Std_ReturnType Dt_FailSafe_ResetReason_T_custom_fake(Dt_FailSafe_ResetReason_T *dt_failsafe_read_buffer_ptr)
{
   dt_failsafe_read_buffer_ptr->reset_reason[0]          = dt_failsafe_read_buffer.reset_reason[0];
   dt_failsafe_read_buffer_ptr->reset_reason[1]          = dt_failsafe_read_buffer.reset_reason[1];
   dt_failsafe_read_buffer_ptr->reset_reason[2]          = dt_failsafe_read_buffer.reset_reason[2];
   dt_failsafe_read_buffer_ptr->reset_reason[3]          = dt_failsafe_read_buffer.reset_reason[3];
   dt_failsafe_read_buffer_ptr->reset_reason[4]          = dt_failsafe_read_buffer.reset_reason[4];
   dt_failsafe_read_buffer_ptr->last_cycle_reset         = dt_failsafe_read_buffer.last_cycle_reset;
   dt_failsafe_read_buffer_ptr->reset_counter            = dt_failsafe_read_buffer.reset_counter;
   dt_failsafe_read_buffer_ptr->reset_reason_crnt_indx   = dt_failsafe_read_buffer.reset_reason_crnt_indx;
   dt_failsafe_read_buffer_ptr->repetitive_reset_counter = dt_failsafe_read_buffer.repetitive_reset_counter;
   return E_OK;
}

extern FailSafe_ResetReason_T PLT_Reset_Reason;

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class FailSafe_Callout_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_FAKES_PLATFORM_RESET_LIST(RESET_FAKE);
      FFF_RESET_HISTORY();
      std::memset(&PLT_Reset_Reason, 0, sizeof(PLT_Reset_Reason));
      std::memset(&dt_failsafe_read_buffer, 0, sizeof(dt_failsafe_read_buffer));
      Rte_SWC_PLT_CDD_FailSafe_Pp_Repetitive_Reset_Status_De_Repetitive_Reset_Status = 85U;
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
FailSafe_ResetReason_T PLT_Reset_Reason = {
   {0U, 0U, 0U, 0U, 0U}, 0U, CODED_TRUE, 0U, 0U, REPETITIVE_RESET_CNTR_THRSHLD + 1, {0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U},
};
FailSafe_ResetReason_T *Get_Platform_ResetReason_Info_custom_fake(void)
{
   return &PLT_Reset_Reason;
}

/*===========================================================================*
 * Test Cases
 *===========================================================================*/
/**
 *  @b swc_plt_appl_faultmgr_sanity
 *  @n
 */
TEST_F(FailSafe_Callout_UnitTestSuite, FailSafe_Callout__Config__SANITY_CHECK_)
{
   /*Sanity Check*/
   ASSERT_EQ(true, true);
}

/*
Fail_Safe_Store_Reset_Reason_Callout() Test 1
*/
TEST_F(FailSafe_Callout_UnitTestSuite, Fail_Safe_Store_Reset_Reason_Callout_T1)
{
   Get_Platform_ResetReason_Info_fake.custom_fake = Get_Platform_ResetReason_Info_custom_fake;
   Fail_Safe_Store_Reset_Reason_Callout();
   ASSERT_EQ(Get_Platform_ResetReason_Info_fake.call_count, 1);
}

/*
Fail_Safe_Check_NVM_Status_Callout
*/
TEST_F(FailSafe_Callout_UnitTestSuite, Fail_Safe_Check_NVM_Status_Callout_T1)
{
   /*implementation is not there */
   Fail_Safe_Check_NVM_Status_Callout();
   ASSERT_EQ(1, 1);
}

/*
   FailSafe_Check_RepetitiveResetCount
*/
TEST_F(FailSafe_Callout_UnitTestSuite, FailSafe_Check_RepetitiveResetCount_T1)
{
   Get_Platform_ResetReason_Info_fake.custom_fake = Get_Platform_ResetReason_Info_custom_fake;
   PLT_Reset_Reason.last_cycle_reset              = CODED_TRUE;
   PLT_Reset_Reason.repetitive_reset_counter      = REPETITIVE_RESET_CNTR_THRSHLD;
   FailSafe_Check_RepetitiveResetCount();
   ASSERT_EQ(Get_Platform_ResetReason_Info_fake.call_count, 1);
   ASSERT_EQ(Rte_SWC_PLT_CDD_FailSafe_Pp_Repetitive_Reset_Status_De_Repetitive_Reset_Status, CODED_TRUE);
}

/*
   FailSafe_Check_RepetitiveResetCount
*/
TEST_F(FailSafe_Callout_UnitTestSuite, FailSafe_Check_RepetitiveResetCount_T2)
{
   Get_Platform_ResetReason_Info_fake.custom_fake = Get_Platform_ResetReason_Info_custom_fake;
   PLT_Reset_Reason.last_cycle_reset              = CODED_FALSE;
   FailSafe_Check_RepetitiveResetCount();
   ASSERT_EQ(Get_Platform_ResetReason_Info_fake.call_count, 1);
   ASSERT_EQ(Rte_SWC_PLT_CDD_FailSafe_Pp_Repetitive_Reset_Status_De_Repetitive_Reset_Status, 85U);
}
/*
   FailSafe_Check_RepetitiveResetCount
*/
TEST_F(FailSafe_Callout_UnitTestSuite, FailSafe_Check_RepetitiveResetCount_T3)
{
   Get_Platform_ResetReason_Info_fake.custom_fake = Get_Platform_ResetReason_Info_custom_fake;
   PLT_Reset_Reason.last_cycle_reset              = CODED_TRUE;
   PLT_Reset_Reason.repetitive_reset_counter      = REPETITIVE_RESET_CNTR_THRSHLD - 1U;
   FailSafe_Check_RepetitiveResetCount();
   ASSERT_EQ(Get_Platform_ResetReason_Info_fake.call_count, 1);
   ASSERT_EQ(Rte_SWC_PLT_CDD_FailSafe_Pp_Repetitive_Reset_Status_De_Repetitive_Reset_Status, 85U);
}

/*
Fail_Safe_Read_Reset_Reason_Callout() Test 1
*/
TEST_F(FailSafe_Callout_UnitTestSuite, Fail_Safe_Read_Reset_Reason_Callout_T1)
{
   dt_failsafe_read_buffer = {{0U, 0U, 0U, 0U, 0U}, 0U, 170U, 0U, 2U, 2U};
   Rte_Read_SWC_PLT_CDD_FailSafe_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason_fake.custom_fake =
      Dt_FailSafe_ResetReason_T_custom_fake;
   Get_Platform_ResetReason_Info_fake.custom_fake = Get_Platform_ResetReason_Info_custom_fake;
   Fail_Safe_Read_Reset_Reason_Callout();
   ASSERT_EQ(Get_Platform_ResetReason_Info_fake.call_count, 1);
}

/*
Fail_Safe_Clear_Last_Cycle_Callout() Test 1
*/
TEST_F(FailSafe_Callout_UnitTestSuite, Fail_Safe_Clear_Last_Cycle_Callout_T1)
{
   Get_Platform_ResetReason_Info_fake.custom_fake = Get_Platform_ResetReason_Info_custom_fake;
   Fail_Safe_Clear_Last_Cycle_Callout();
   ASSERT_EQ(Get_Platform_ResetReason_Info_fake.call_count, 1);
}

/*
FailSafe_Verify_ResetReason()
*/
TEST_F(FailSafe_Callout_UnitTestSuite, FailSafe_Verify_ResetReason_T1)
{
   uint8_t fault_channel                          = 0xA5U;
   Get_Platform_ResetReason_Info_fake.custom_fake = Get_Platform_ResetReason_Info_custom_fake;
   PLT_Reset_Reason.last_cycle_reset              = CODED_FALSE;
   ASSERT_EQ(FailSafe_Verify_ResetReason(&fault_channel), CODED_FALSE);
   ASSERT_EQ(Get_Platform_ResetReason_Info_fake.call_count, 1);
   ASSERT_EQ(fault_channel, 0xA5U);
}
/*
FailSafe_Verify_ResetReason()
*/
TEST_F(FailSafe_Callout_UnitTestSuite, FailSafe_Verify_ResetReason_T2)
{
   uint8_t fault_channel                          = 0xA5U;
   PLT_Reset_Reason.last_cycle_reset              = CODED_TRUE;
   PLT_Reset_Reason.repetitive_reset_counter      = REPETITIVE_RESET_CNTR_THRSHLD - 1;
   PLT_Reset_Reason.reset_reason_crnt_indx        = 1U;
   PLT_Reset_Reason.reset_reason_info[0]          = MCU_FCRU_FAULT_0_UNDERVOLTAGE_VDD;
   Get_Platform_ResetReason_Info_fake.custom_fake = Get_Platform_ResetReason_Info_custom_fake;
   ASSERT_EQ(FailSafe_Verify_ResetReason(&fault_channel), CODED_FALSE);
   ASSERT_EQ(Get_Platform_ResetReason_Info_fake.call_count, 1);
   ASSERT_EQ(fault_channel, 0xA5U);
}
/*
FailSafe_Verify_ResetReason()
*/
TEST_F(FailSafe_Callout_UnitTestSuite, FailSafe_Verify_ResetReason_T3)
{
   uint8_t fault_channel                          = 0xA5U;
   PLT_Reset_Reason.last_cycle_reset              = CODED_TRUE;
   PLT_Reset_Reason.repetitive_reset_counter      = REPETITIVE_RESET_CNTR_THRSHLD + 1;
   PLT_Reset_Reason.reset_reason_crnt_indx        = 1U;
   PLT_Reset_Reason.reset_reason_info[0]          = MCU_FCRU_FAULT_0_UNDERVOLTAGE_VDD;
   Get_Platform_ResetReason_Info_fake.custom_fake = Get_Platform_ResetReason_Info_custom_fake;
   ASSERT_EQ(FailSafe_Verify_ResetReason(&fault_channel), CODED_TRUE);
   ASSERT_EQ(Get_Platform_ResetReason_Info_fake.call_count, 1);
   ASSERT_EQ(fault_channel, MCU_FCRU_FAULT_0_UNDERVOLTAGE_VDD);
}

TEST_F(FailSafe_Callout_UnitTestSuite, FailSafe_Verify_ResetReason_T4)
{
   uint8_t fault_channel                          = 0xA5U;
   PLT_Reset_Reason.last_cycle_reset              = CODED_TRUE;
   PLT_Reset_Reason.repetitive_reset_counter      = REPETITIVE_RESET_CNTR_THRSHLD + 1U;
   PLT_Reset_Reason.reset_reason_crnt_indx        = 1U;
   PLT_Reset_Reason.reset_reason_info[0]          = MCU_FCRU_FAULT_63_TOP_RESET_FAULT;
   Get_Platform_ResetReason_Info_fake.custom_fake = Get_Platform_ResetReason_Info_custom_fake;
   ASSERT_EQ(FailSafe_Verify_ResetReason(&fault_channel), CODED_TRUE);
   ASSERT_EQ(Get_Platform_ResetReason_Info_fake.call_count, 1);
   ASSERT_EQ(fault_channel, MCU_FCRU_FAULT_63_TOP_RESET_FAULT);
}
TEST_F(FailSafe_Callout_UnitTestSuite, FailSafe_Verify_ResetReason_T5)
{
   uint8_t fault_channel                          = 0xA5U;
   PLT_Reset_Reason.last_cycle_reset              = CODED_TRUE;
   PLT_Reset_Reason.repetitive_reset_counter      = REPETITIVE_RESET_CNTR_THRSHLD + 1U;
   PLT_Reset_Reason.reset_reason_crnt_indx        = 1U;
   PLT_Reset_Reason.reset_reason_info[0]          = OS_ACCESS;
   Get_Platform_ResetReason_Info_fake.custom_fake = Get_Platform_ResetReason_Info_custom_fake;
   ASSERT_EQ(FailSafe_Verify_ResetReason(&fault_channel), CODED_FALSE);
   ASSERT_EQ(Get_Platform_ResetReason_Info_fake.call_count, 1);
   ASSERT_EQ(fault_channel, OS_ACCESS);
}

TEST_F(FailSafe_Callout_UnitTestSuite, FailSafe_Verify_ResetReason_T6)
{
   uint8_t fault_channel                          = 0xA5U;
   PLT_Reset_Reason.last_cycle_reset              = CODED_TRUE;
   PLT_Reset_Reason.repetitive_reset_counter      = REPETITIVE_RESET_CNTR_THRSHLD + 1U;
   PLT_Reset_Reason.reset_reason_crnt_indx        = 1U;
   PLT_Reset_Reason.reset_reason_info[0]          = DEFAULT_RESET_REASON;
   Get_Platform_ResetReason_Info_fake.custom_fake = Get_Platform_ResetReason_Info_custom_fake;
   ASSERT_EQ(FailSafe_Verify_ResetReason(&fault_channel), CODED_FALSE);
   ASSERT_EQ(Get_Platform_ResetReason_Info_fake.call_count, 1);
   ASSERT_EQ(fault_channel, 0xA5U);
}
/*
FailSafe_Repetative_ResetReason() Test 1
*/
TEST_F(FailSafe_Callout_UnitTestSuite, FailSafe_Repetative_ResetReason_T1)
{
   dt_failsafe_read_buffer = {{0U, 0U, 0U, 0U, 0U}, 0U, 170U, 0U, 2U};
   Rte_Read_SWC_PLT_CDD_FailSafe_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason_fake.custom_fake =
      Dt_FailSafe_ResetReason_T_custom_fake;
   uint8_t ResetReason = CODED_TRUE;
   FailSafe_Repetative_ResetReason(&ResetReason);
   ASSERT_EQ(Rte_Read_SWC_PLT_CDD_FailSafe_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason_fake.call_count, 1);
}

TEST_F(FailSafe_Callout_UnitTestSuite, FailSafe_Repetative_ResetReason_T2)
{
   dt_failsafe_read_buffer = {{0U, 0U, 0U, 0U, 0U}, 170U, 170U, 0U, 1U};
   Rte_Read_SWC_PLT_CDD_FailSafe_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason_fake.custom_fake =
      Dt_FailSafe_ResetReason_T_custom_fake;
   uint8_t ResetReason = CODED_TRUE;
   FailSafe_Repetative_ResetReason(&ResetReason);
   ASSERT_EQ(Rte_Read_SWC_PLT_CDD_FailSafe_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason_fake.call_count, 1);
}
TEST_F(FailSafe_Callout_UnitTestSuite, FailSafe_Repetative_ResetReason_T3)
{
   dt_failsafe_read_buffer = {{0U, 0U, 0U, 0U, 0U}, 170U, 0U, 0U, 5U};
   Rte_Read_SWC_PLT_CDD_FailSafe_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason_fake.custom_fake =
      Dt_FailSafe_ResetReason_T_custom_fake;
   uint8_t ResetReason = CODED_TRUE;
   FailSafe_Repetative_ResetReason(&ResetReason);

   ASSERT_EQ(Rte_Read_SWC_PLT_CDD_FailSafe_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason_fake.call_count, 1);
}
