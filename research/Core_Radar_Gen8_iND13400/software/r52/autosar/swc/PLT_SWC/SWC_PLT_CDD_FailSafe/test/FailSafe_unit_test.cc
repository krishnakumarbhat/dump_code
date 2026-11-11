/*===========================================================================*/
/**
 * @file FailSafe_unit_test.cc
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
#include "fff.h"
#include <cstring>
#include <gtest/gtest.h>

#include "FailSafe_fake.h"
/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/

DEFINE_FFF_GLOBALS;

volatile uint32 IRQ_RMON                         = 0U;
volatile uint32 IRQ_RMON_NOMASK                  = 0U;
volatile uint32 MCU_SAFETY_MISC0_IRQ_MASKED_STAT = 0U;
volatile uint32 CTL_RMON                         = 0U;

extern "C"
{
#include "FS_IntHndlr.c"
#include "SWC_PLT_CDD_FailSafe.c"
   EthTrcv_StateType EthTrcv_30_Rtl9010_TrcvLinkState[2];
}

Std_ReturnType Rte_Read_SWC_PLT_CDD_FailSafe_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo(
   Rte_DT_Dt_StaticRegCheckFailureInfo_0 *data)
{
   if (data != NULL)
   {
      for (uint8 i = 0; i < 35; i++)
      {
         data[i] = 0;
      }
   }
   return E_OK;
}

Std_ReturnType Rte_Write_SWC_PLT_CDD_FailSafe_Pp_ECC_Correctable_Fault_De_ECC_Correctable_Fault(
   const Dt_ECC_Correctable_Error_Counters *data)
{
   (void)data;
   return E_OK;
}

Std_ReturnType Rte_Call_SWC_PLT_CDD_FailSafe_CS_Trigger_Write_to_NVM_NvHandler_Trigger_Write_To_NVM(uint8 block_id,
                                                                                                    uint8 service_id)
{
   (void)block_id;
   (void)service_id;
   return E_OK;
}

Retention_Ram_Data_T Retention_Ram_Data;

static uint8 FailSafe_Verify_ResetReason_ReturnsTrue(uint8 *faultnum)
{
   *faultnum = MCU_FCRU_FAULT_0_UNDERVOLTAGE_VDD;
   return CODED_TRUE;
}

static uint8 FailSafe_Verify_ResetReason_ReturnsFalse(uint8 *faultnum)
{
   *faultnum = MCU_FAILSAFE_DSP_CLK_FAILURE;
   return CODED_FALSE;
}

static void ResetCommonFailSafeFakes(void)
{
   RESET_FAKE(Rte_Write_SWC_PLT_CDD_FailSafe_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason);
   RESET_FAKE(Rte_Read_SWC_PLT_CDD_FailSafe_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason);
   RESET_FAKE(Rte_Write_SWC_PLT_CDD_FailSafe_Pp_Hardware_Fault_Status_De_Hardware_Fault_Status);
   RESET_FAKE(Trigger_Write_to_NVM);
   RESET_FAKE(Fail_Safe_Read_Reset_Reason_Callout);
   RESET_FAKE(FailSafe_Check_RepetitiveResetCount);
   RESET_FAKE(Fail_Safe_Clear_Last_Cycle_Callout);
   RESET_FAKE(Fail_Safe_Store_Reset_Reason_Callout);
   RESET_FAKE(Fail_Safe_Check_NVM_Status_Callout);
   RESET_FAKE(FailSafe_Verify_ResetReason);
   RESET_FAKE(SuspendAllInterrupts);
   RESET_FAKE(WdgM_GetFirstExpiredSEID);
   RESET_FAKE(Can_SetControllerMode);
   RESET_FAKE(EthTrcv_30_Rtl9010_SetTransceiverMode);
   RESET_FAKE(Mcu_Reset);
}
/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class FailSafe_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_RESET_HISTORY();
      ResetCommonFailSafeFakes();
      std::memset(&PLT_Reset_Reason, 0, sizeof(PLT_Reset_Reason));
      std::memset(&Retention_Ram_Data, 0, sizeof(Retention_Ram_Data));
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

/* redefinition of global variables used by UUT */
/**
 *  @b FailSafe
 *  @n
 *      Test the  function.
 */
TEST_F(FailSafe_UnitTestSuite, FailSafe)
{
   ASSERT_EQ(true, true);
}

TEST_F(FailSafe_UnitTestSuite, Log_ResetReason_T1)
{
   const uint16 exception_reset_reasons[] = {
      MCU_FAILSAFE_UNDEF_INSTRUCTION_EXCEPTION,
      MCU_FAILSAFE_ABORT_PREFETCH_EXCEPTION,
      MCU_FAILSAFE_ABORT_DATA_EXCEPTION,
      E_OS_PROTECTION_MEMORY,
      E_OS_PROTECTION_EXCEPTION,
      OS_PANICHOOK,
      MCU_FAILSAFE_SERIAL_CLK_FAILURE,
   };

   for (uint32 index = 0u; index < (sizeof(exception_reset_reasons) / sizeof(exception_reset_reasons[0])); index++)
   {
      ResetCommonFailSafeFakes();
      PLT_Reset_Reason.reset_reason_crnt_indx = 5u;

      Log_ResetReason(exception_reset_reasons[index]);

      ASSERT_EQ(PLT_Reset_Reason.reset_reason_crnt_indx, 5u);
      ASSERT_EQ(EthTrcv_30_Rtl9010_SetTransceiverMode_fake.call_count, 0u);
      ASSERT_EQ(Can_SetControllerMode_fake.call_count, 1u);
      ASSERT_EQ(Can_SetControllerMode_fake.arg0_val, 0u);
      ASSERT_EQ(Can_SetControllerMode_fake.arg1_val, CAN_CS_STOPPED);
      ASSERT_EQ(Mcu_Reset_fake.call_count, 1u);
      ASSERT_EQ(Mcu_Reset_fake.arg0_val, RESET_SW_UNINTENTIONAL);
      ASSERT_EQ(SuspendAllInterrupts_fake.call_count, 0u);
      ASSERT_EQ(Fail_Safe_Check_NVM_Status_Callout_fake.call_count, 0u);
      ASSERT_EQ(Fail_Safe_Store_Reset_Reason_Callout_fake.call_count, 0u);
   }
}

TEST_F(FailSafe_UnitTestSuite, Log_ResetReason_T2)
{
   const uint16 reset_reason = MCU_FAILSAFE_DSP_CLK_FAILURE;

   Log_ResetReason(reset_reason);

   ASSERT_EQ(PLT_Reset_Reason.last_cycle_reset, CODED_TRUE);
   ASSERT_EQ(SuspendAllInterrupts_fake.call_count, 1u);
   ASSERT_EQ(Fail_Safe_Check_NVM_Status_Callout_fake.call_count, 1u);
   ASSERT_EQ(EthTrcv_30_Rtl9010_SetTransceiverMode_fake.call_count, 0u);
   ASSERT_EQ(Can_SetControllerMode_fake.call_count, 1u);
   ASSERT_EQ(Can_SetControllerMode_fake.arg0_val, 0u);
   ASSERT_EQ(Can_SetControllerMode_fake.arg1_val, CAN_CS_STOPPED);
   ASSERT_EQ(Mcu_Reset_fake.call_count, 1u);
   ASSERT_EQ(Mcu_Reset_fake.arg0_val, RESET_SW_UNINTENTIONAL);
   ASSERT_EQ(Fail_Safe_Store_Reset_Reason_Callout_fake.call_count, 1);
}

/**
 *  @b CS_FailSafe_Fault_Injection_test
 *  @n
 *      Test valid configurations.
 */
TEST_F(FailSafe_UnitTestSuite, CS_FailSafe_Fault_Injection_T1)
{
   /*implementation is not there */
   uint8 Injection_control, Failure_Type;
   CS_FailSafe_Fault_Injection(Injection_control, Failure_Type);
   ASSERT_EQ(1, 1);
}
/**
 *  @b CS_FailSafe_Fault_Injection_test
 *  @n
 *      Test valid configurations.
 */
TEST_F(FailSafe_UnitTestSuite, FailSafe_Log_ResetReason_T1)
{
   /*implementation is not there */
   Dt_ECU_ResetReasonType reset_reason = MCU_FAILSAFE_DSP_CLK_FAILURE;
   FailSafe_Log_ResetReason(reset_reason);
   ASSERT_EQ(PLT_Reset_Reason.reset_reason_crnt_indx, 1);
}

/**
 *  @b CS_Get_RepetativeReset_Faultnum_Operation
 *  @n
 *      Verify a valid repetitive FCRU fault is returned unchanged.
 */
TEST_F(FailSafe_UnitTestSuite, CS_Get_RepetativeReset_Faultnum_Operation_ReturnsVerifiedFault)
{
   uint8 faultnum = NO_FCRU_REPETATIVE_RESET;

   FailSafe_Verify_ResetReason_fake.custom_fake = FailSafe_Verify_ResetReason_ReturnsTrue;

   CS_Get_RepetativeReset_Faultnum_Operation(&faultnum);

   ASSERT_EQ(FailSafe_Verify_ResetReason_fake.call_count, 1u);
   ASSERT_EQ(faultnum, MCU_FCRU_FAULT_0_UNDERVOLTAGE_VDD);
}

/**
 *  @b CS_Get_RepetativeReset_Faultnum_Operation
 *  @n
 *      Verify a non-FCRU repetitive reset is normalized to the no-fault marker.
 */
TEST_F(FailSafe_UnitTestSuite, CS_Get_RepetativeReset_Faultnum_Operation_NormalizesNonFcruFault)
{
   uint8 faultnum = 0x5Au;

   FailSafe_Verify_ResetReason_fake.custom_fake = FailSafe_Verify_ResetReason_ReturnsFalse;

   CS_Get_RepetativeReset_Faultnum_Operation(&faultnum);

   ASSERT_EQ(FailSafe_Verify_ResetReason_fake.call_count, 1u);
   ASSERT_EQ(faultnum, NO_FCRU_REPETATIVE_RESET);
}

/**
 *  @b FailSafe_Log_ResetReason
 *  @n
 *      Verify exception path triggers immediate transceiver shutdown and reset.
 */
TEST_F(FailSafe_UnitTestSuite, FailSafe_Log_ResetReason_ExceptionPath)
{
   const Dt_ECU_ResetReasonType reset_reason = MCU_FAILSAFE_UNDEF_INSTRUCTION_EXCEPTION;

   FailSafe_Log_ResetReason(reset_reason);

   ASSERT_EQ(EthTrcv_30_Rtl9010_SetTransceiverMode_fake.call_count, 0u);
   ASSERT_EQ(Can_SetControllerMode_fake.call_count, 1u);
   ASSERT_EQ(Mcu_Reset_fake.call_count, 1u);
   ASSERT_EQ(SuspendAllInterrupts_fake.call_count, 0u);
   ASSERT_EQ(Fail_Safe_Check_NVM_Status_Callout_fake.call_count, 0u);
}

/**
 *  @b FailSafe_Log_ResetReason
 *  @n
 *      Verify non-exception path logs through NVM flow before reset.
 */
TEST_F(FailSafe_UnitTestSuite, FailSafe_Log_ResetReason_NvmPath)
{
   const Dt_ECU_ResetReasonType reset_reason = MCU_FAILSAFE_DSP_CLK_FAILURE;

   FailSafe_Log_ResetReason(reset_reason);

   ASSERT_EQ(SuspendAllInterrupts_fake.call_count, 1u);
   ASSERT_EQ(Fail_Safe_Check_NVM_Status_Callout_fake.call_count, 1u);
   ASSERT_EQ(EthTrcv_30_Rtl9010_SetTransceiverMode_fake.call_count, 0u);
   ASSERT_EQ(Can_SetControllerMode_fake.call_count, 1u);
   ASSERT_EQ(Mcu_Reset_fake.call_count, 1u);
   ASSERT_EQ(PLT_Reset_Reason.last_cycle_reset, CODED_TRUE);
}
/**
 *  @b RE_PLT_FailSafe_Init_test
 *  @n
 *      Test valid configurations.
 */
TEST_F(FailSafe_UnitTestSuite, RE_PLT_FailSafe_Init_test)
{
   RE_PLT_FailSafe_Init();
   ASSERT_EQ(Fail_Safe_Read_Reset_Reason_Callout_fake.call_count, 1);
}
/**
 *  @b RE_PLT_FailSafe_Main_50ms
 *  @n
 *      Test valid configurations.
 */
TEST_F(FailSafe_UnitTestSuite, RE_PLT_FailSafe_Main_50ms_test1)
{
   PLT_Reset_Reason.last_cycle_reset = CODED_TRUE;
   RE_PLT_FailSafe_Main_50ms();
   ASSERT_EQ(PLT_Reset_Reason.last_cycle_reset, CODED_FALSE);
}
/**
 *  @b RE_PLT_FailSafe_Main_50ms
 *  @n
 *      Test valid configurations.
 */
TEST_F(FailSafe_UnitTestSuite, RE_PLT_FailSafe_Main_50ms_test2)
{
   PLT_Reset_Reason.last_cycle_reset = CODED_FALSE;
   RE_PLT_FailSafe_Main_50ms();
   ASSERT_EQ(PLT_Reset_Reason.last_cycle_reset, CODED_FALSE);
}
/**
 *  @b Get_Platform_ResetReason_Info
 *  @n
 *      Test valid configurations.
 */
TEST_F(FailSafe_UnitTestSuite, Get_Platform_ResetReason_Info_test)
{
   FailSafe_ResetReason_T *result = Get_Platform_ResetReason_Info();
   EXPECT_EQ(result, &PLT_Reset_Reason);
}
/**
 *  @b Log_ResetReason_Info
 *  @n
 *      Test valid configurations.
 */
TEST_F(FailSafe_UnitTestSuite, Log_ResetReason_Info_test1)
{
   uint8 reset_reason                      = 1;
   PLT_Reset_Reason.reset_reason_crnt_indx = 5;
   PLT_Reset_Reason.reset_counter          = 0;
   Log_ResetReason_Info(reset_reason);
   ASSERT_EQ(PLT_Reset_Reason.last_cycle_reset, CODED_TRUE);
}
/**
 *  @b Log_ResetReason_Info
 *  @n
 *      Test valid configurations.
 */
TEST_F(FailSafe_UnitTestSuite, Log_ResetReason_Info_test2)
{
   uint8 reset_reason             = 1;
   PLT_Reset_Reason.reset_counter = 255;
   Log_ResetReason_Info(reset_reason);
   ASSERT_EQ(PLT_Reset_Reason.reset_reason_crnt_indx, 1);
}
/**
 *  @b Log_ResetReason_Info
 *  @n
 *      Test valid configurations.
 */
TEST_F(FailSafe_UnitTestSuite, Log_ResetReason_Info_test3)
{
   uint8 reset_reason = 1;
   for (uint8 i = 0; i < 6; i++)
   {
      Log_ResetReason_Info(reset_reason);
   }
   ASSERT_EQ(PLT_Reset_Reason.last_cycle_reset, CODED_TRUE);
}

/**
 *  @b CS_Failsafe_Log_ResetReason_at_Startup
 *  @n
 *      Test valid fault.
 */
TEST_F(FailSafe_UnitTestSuite, CS_Failsafe_Log_ResetReason_at_Startup_00)
{
   PLT_Reset_Reason.last_cycle_reset = CODED_FALSE;
   CS_Failsafe_Log_ResetReason_at_Startup(100);
   ASSERT_EQ(PLT_Reset_Reason.last_cycle_reset, CODED_TRUE);
}

/**
 *  @b CS_Failsafe_Log_ResetReason_at_Startup
 *  @n
 *      Test Invalid fault.
 */
TEST_F(FailSafe_UnitTestSuite, CS_Failsafe_Log_ResetReason_at_Startup_01)
{
   PLT_Reset_Reason.last_cycle_reset = CODED_FALSE;
   CS_Failsafe_Log_ResetReason_at_Startup(164);
   ASSERT_EQ(PLT_Reset_Reason.last_cycle_reset, CODED_FALSE);
}

/**
 *  @b CS_Failsafe_Log_ResetReason_at_Startup
 *  @n
 *      Test Invalid fault.
 */
TEST_F(FailSafe_UnitTestSuite, CS_Failsafe_Log_ResetReason_at_Startup_02)
{
   PLT_Reset_Reason.last_cycle_reset = CODED_FALSE;
   CS_Failsafe_Log_ResetReason_at_Startup(99);
   ASSERT_EQ(PLT_Reset_Reason.last_cycle_reset, CODED_FALSE);
}

/**
 *  @b Log_ResetReason_Info
 *  @n
 *      Test valid configurations.
 */
TEST_F(FailSafe_UnitTestSuite, Log_ResetReason_Info_test4)
{
   uint8 reset_reason = 28;
   Log_ResetReason_Info(reset_reason);
   ASSERT_EQ(WdgM_GetFirstExpiredSEID_fake.call_count, 1);
}
/**
 *  @b Log_ResetReason_Info
 *  @n
 *      Test valid configurations.
 */
TEST_F(FailSafe_UnitTestSuite, Log_ResetReason_Info_test5)
{
   uint8 reset_reason = 34;
   Log_ResetReason_Info(reset_reason);

   reset_reason = 36;
   Log_ResetReason_Info(reset_reason);

   reset_reason = 14;
   Log_ResetReason_Info(reset_reason);

   reset_reason = 18;
   Log_ResetReason_Info(reset_reason);
}

/**
 *  @b Failsafe_WriteToNvMAndPerformReset
 *  @n
 *      Verify transceivers are shut down before MCU reset.
 */
TEST_F(FailSafe_UnitTestSuite, Failsafe_WriteToNvMAndPerformReset_test1)
{
   RESET_FAKE(SuspendAllInterrupts);
   RESET_FAKE(Fail_Safe_Check_NVM_Status_Callout);
   RESET_FAKE(EthTrcv_30_Rtl9010_SetTransceiverMode);
   RESET_FAKE(Can_SetControllerMode);
   RESET_FAKE(Mcu_Reset);

   Failsafe_WriteToNvMAndPerformReset(100u);

   ASSERT_EQ(SuspendAllInterrupts_fake.call_count, 1);
   ASSERT_EQ(Fail_Safe_Check_NVM_Status_Callout_fake.call_count, 1);
   ASSERT_EQ(EthTrcv_30_Rtl9010_SetTransceiverMode_fake.call_count, 0);
   ASSERT_EQ(Can_SetControllerMode_fake.call_count, 1);
   ASSERT_EQ(Mcu_Reset_fake.call_count, 1);
}
/**
 *  @b Log_ExceptionReason_Info
 *  @n
 *      Test valid configurations.
 */
TEST_F(FailSafe_UnitTestSuite, Log_ExceptionReason_Info_test1)
{
   Dt_Memory_Exception_Info_T *Exception_Context;
   uint16 Resnum;
   Log_ExceptionReason_Info(Exception_Context, Resnum);
   ASSERT_EQ(CODED_TRUE, CODED_TRUE);
}
/**
 *  @b Failsafe_clear_Exception_SharedData
 *  @n
 *      Test valid configurations.
 */
TEST_F(FailSafe_UnitTestSuite, Failsafe_clear_Exception_SharedData_test1)
{
   Failsafe_clear_Exception_SharedData();
   ASSERT_EQ(CODED_TRUE, CODED_TRUE);
}
