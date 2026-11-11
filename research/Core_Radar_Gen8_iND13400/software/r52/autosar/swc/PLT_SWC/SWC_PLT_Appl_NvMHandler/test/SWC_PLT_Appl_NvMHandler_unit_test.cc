#include <gtest/gtest.h>

extern "C"
{
#include "../Source/SWC_PLT_Appl_NvMHandler.c"
#include "Rte_SWC_PLT_Appl_NvMHandler.h"
#include "fixmac.h"
}

extern "C"
{
   extern uint8 g_failsafe_status;
   extern uint8 g_nvmbringup_status;
   extern uint8 g_rfe_status;
   extern uint8 g_correctable_status;
   extern uint8 g_manual_status;
   extern uint8 g_static_status;
   extern uint8 g_vse_status;
   extern Std_ReturnType g_failsafe_write_ret;
   extern Std_ReturnType g_nvmbringup_write_ret;
   extern Std_ReturnType g_rfe_write_ret;
   extern Std_ReturnType g_correctable_write_ret;
   extern uint32 g_failsafe_get_status_calls;
   extern uint32 g_failsafe_write_calls;
   extern uint32 g_nvmbringup_get_status_calls;
   extern uint32 g_nvmbringup_write_calls;
   extern uint32 g_rfe_get_status_calls;
   extern uint32 g_rfe_write_calls;
   extern uint32 g_correctable_get_status_calls;
   extern uint32 g_correctable_write_calls;
   extern uint32 g_manual_get_status_calls;
   extern uint32 g_manual_write_calls;
   extern uint32 g_static_get_status_calls;
   extern uint32 g_static_write_calls;
   extern uint32 g_vse_get_status_calls;
   extern uint32 g_vse_write_calls;
   extern uint32 g_read_failsafe_calls;
   extern uint32 g_read_alignment_calls;
   extern uint32 g_read_rfe_calls;
   extern uint32 g_read_correctable_calls;
   extern uint32 g_write_nvm_flag_status_calls;
   extern uint8 g_last_nvm_flag_status;
   extern uint32 g_write_alignment_read_record_calls;
   extern uint32 g_write_alignment_data_calls;
   extern uint32 g_write_failsafe_data_calls;
   extern uint32 g_write_rfe_data_calls;
   extern uint32 g_sensorpos_write_calls;
   extern uint32 g_nvm_main_calls;
   extern uint32 g_fee_main_calls;
   extern uint32 g_fls_main_calls;
   extern NvM_RequestResultType g_config_nvm_status;
   extern Std_ReturnType g_config_nvm_write_ret;
   extern uint32 g_config_nvm_get_status_calls;
   extern uint32 g_config_nvm_write_calls;
}

class SWCPLTApplNvMHandlerUnitFixture : public ::testing::Test
{
 protected:
   void SetUp() override
   {
      g_failsafe_status                   = NVM_REQ_OK;
      g_nvmbringup_status                 = NVM_REQ_OK;
      g_rfe_status                        = NVM_REQ_OK;
      g_correctable_status                = NVM_REQ_OK;
      g_failsafe_write_ret                = E_OK;
      g_nvmbringup_write_ret              = E_OK;
      g_rfe_write_ret                     = E_OK;
      g_correctable_write_ret             = E_OK;
      g_failsafe_get_status_calls         = 0U;
      g_failsafe_write_calls              = 0U;
      g_nvmbringup_get_status_calls       = 0U;
      g_nvmbringup_write_calls            = 0U;
      g_rfe_get_status_calls              = 0U;
      g_rfe_write_calls                   = 0U;
      g_correctable_get_status_calls      = 0U;
      g_correctable_write_calls           = 0U;
      g_manual_get_status_calls           = 0U;
      g_manual_write_calls                = 0U;
      g_static_get_status_calls           = 0U;
      g_static_write_calls                = 0U;
      g_vse_get_status_calls              = 0U;
      g_vse_write_calls                   = 0U;
      g_read_failsafe_calls               = 0U;
      g_read_alignment_calls              = 0U;
      g_read_rfe_calls                    = 0U;
      g_read_correctable_calls            = 0U;
      g_write_nvm_flag_status_calls       = 0U;
      g_last_nvm_flag_status              = CODED_FALSE;
      g_write_alignment_read_record_calls = 0U;
      g_write_alignment_data_calls        = 0U;
      g_write_failsafe_data_calls         = 0U;
      g_write_rfe_data_calls              = 0U;
      g_sensorpos_write_calls             = 0U;
      g_nvm_main_calls                    = 0U;
      g_fee_main_calls                    = 0U;
      g_fls_main_calls                    = 0U;
      g_config_nvm_status                 = NVM_REQ_NOT_OK;
      g_config_nvm_write_ret              = E_OK;
      g_config_nvm_get_status_calls       = 0U;
      g_config_nvm_write_calls            = 0U;
      ConfigID_NvM_Write_Status           = CODED_FALSE;
      configIdWriteCounter                = 10U;
      nvmWrtStatus                        = E_NOT_OK;
   }
};

TEST_F(SWCPLTApplNvMHandlerUnitFixture, UpdateConfigIdDecrementsCounterWithoutWriting)
{
   configIdWriteCounter = 2U;

   updateConfigId();

   ASSERT_EQ(g_config_nvm_get_status_calls, 1U);
   ASSERT_EQ(configIdWriteCounter, 1U);
   ASSERT_EQ(g_config_nvm_write_calls, 0U);
}

TEST_F(SWCPLTApplNvMHandlerUnitFixture, UpdateConfigIdStartsWriteWhenCountdownExpires)
{
   configIdWriteCounter   = 1U;
   g_config_nvm_write_ret = E_OK;

   updateConfigId();

   ASSERT_EQ(g_config_nvm_write_calls, 1U);
   ASSERT_EQ(nvmWrtStatus, E_OK);
   ASSERT_EQ(configIdWriteCounter, 1000U);
}

TEST_F(SWCPLTApplNvMHandlerUnitFixture, UpdateConfigIdSchedulesRetryWhenWriteFails)
{
   configIdWriteCounter   = 1U;
   g_config_nvm_write_ret = E_NOT_OK;

   updateConfigId();

   ASSERT_EQ(g_config_nvm_write_calls, 1U);
   ASSERT_EQ(nvmWrtStatus, E_NOT_OK);
   ASSERT_EQ(configIdWriteCounter, 5000U);
}

TEST_F(SWCPLTApplNvMHandlerUnitFixture, UpdateConfigIdMarksCompletedWriteSuccessful)
{
   g_config_nvm_status = NVM_REQ_OK;

   updateConfigId();

   ASSERT_EQ(ConfigID_NvM_Write_Status, CODED_TRUE);
   ASSERT_EQ(configIdWriteCounter, 0xFFU);
   ASSERT_EQ(g_config_nvm_write_calls, 0U);
}

TEST_F(SWCPLTApplNvMHandlerUnitFixture, UpdateConfigIdDoesNothingWhileRequestPending)
{
   g_config_nvm_status  = NVM_REQ_PENDING;
   configIdWriteCounter = 4U;

   updateConfigId();

   ASSERT_EQ(ConfigID_NvM_Write_Status, CODED_FALSE);
   ASSERT_EQ(configIdWriteCounter, 4U);
   ASSERT_EQ(g_config_nvm_write_calls, 0U);
}

TEST_F(SWCPLTApplNvMHandlerUnitFixture, UpdateConfigIdDoesNothingWhenCountdownAlreadyExpired)
{
   configIdWriteCounter = 0U;

   updateConfigId();

   ASSERT_EQ(ConfigID_NvM_Write_Status, CODED_FALSE);
   ASSERT_EQ(configIdWriteCounter, 0U);
   ASSERT_EQ(g_config_nvm_write_calls, 0U);
}

TEST_F(SWCPLTApplNvMHandlerUnitFixture, InitRunnableExecutes)
{
   SWC_PLT_Appl_NvMHandler_Init();
   ASSERT_GE(g_write_alignment_data_calls, 1U);
   ASSERT_GE(g_write_failsafe_data_calls, 1U);
   ASSERT_GE(g_write_rfe_data_calls, 1U);
}

TEST_F(SWCPLTApplNvMHandlerUnitFixture, Main50msRunnableExecutes)
{
   RE_PLT_Appl_NvMHandler_50ms();
   ASSERT_GE(g_write_nvm_flag_status_calls, 1U);
   ASSERT_GE(g_write_alignment_read_record_calls, 1U);
}

TEST_F(SWCPLTApplNvMHandlerUnitFixture, TriggerWriteRunnableExecutes)
{
   Trigger_Write_to_NVM(CODED_FALSE, CDD_ALIGNMENT);
   ASSERT_GE(g_read_alignment_calls, 1U);
   ASSERT_GE(g_nvmbringup_write_calls, 1U);
}

TEST_F(SWCPLTApplNvMHandlerUnitFixture, TriggerImmediateFailSafeWritesAndRunsMainFunctions)
{
   Trigger_Write_to_NVM(CODED_TRUE, CDD_FAIL_SAFE);
   ASSERT_GE(g_read_failsafe_calls, 1U);
   ASSERT_GE(g_read_rfe_calls, 1U);
   ASSERT_EQ(g_read_correctable_calls, 0U);
   ASSERT_GE(g_failsafe_get_status_calls, 1U);
   ASSERT_GE(g_rfe_get_status_calls, 1U);
   ASSERT_EQ(g_correctable_get_status_calls, 0U);
   ASSERT_GE(g_failsafe_write_calls, 1U);
   ASSERT_GE(g_rfe_write_calls, 1U);
   ASSERT_EQ(g_correctable_write_calls, 0U);
   ASSERT_GE(g_nvm_main_calls, 1U);
   ASSERT_GE(g_fee_main_calls, 1U);
   ASSERT_GE(g_fls_main_calls, 1U);
}

TEST_F(SWCPLTApplNvMHandlerUnitFixture, TriggerImmediateRfeWritesAndRunsMainFunctions)
{
   Trigger_Write_to_NVM(CODED_TRUE, RFE_R1R2_FAULT);
   ASSERT_GE(g_read_failsafe_calls, 1U);
   ASSERT_GE(g_read_rfe_calls, 1U);
   ASSERT_GE(g_failsafe_get_status_calls, 1U);
   ASSERT_GE(g_rfe_get_status_calls, 1U);
   ASSERT_GE(g_failsafe_write_calls, 1U);
   ASSERT_GE(g_rfe_write_calls, 1U);
   ASSERT_GE(g_nvm_main_calls, 1U);
   ASSERT_GE(g_fee_main_calls, 1U);
   ASSERT_GE(g_fls_main_calls, 1U);
}
TEST_F(SWCPLTApplNvMHandlerUnitFixture, TriggerImmediateCorrectableSelectsImmediateWriteBranch)
{
   Trigger_Write_to_NVM(CODED_TRUE, CDD_FAILSAFE_ECC);
   ASSERT_GE(g_read_failsafe_calls, 1U);
   ASSERT_GE(g_read_rfe_calls, 1U);
   ASSERT_GE(g_failsafe_get_status_calls, 1U);
   ASSERT_GE(g_rfe_get_status_calls, 1U);
   ASSERT_GE(g_failsafe_write_calls, 1U);
   ASSERT_GE(g_rfe_write_calls, 1U);
   ASSERT_GE(g_nvm_main_calls, 1U);
   ASSERT_GE(g_fee_main_calls, 1U);
   ASSERT_GE(g_fls_main_calls, 1U);
}
TEST_F(SWCPLTApplNvMHandlerUnitFixture, TriggerNonImmediateRfePendingThenMain50msCompletesWrite)
{
   g_rfe_status = NVM_REQ_PENDING;
   Trigger_Write_to_NVM(CODED_FALSE, RFE_R1R2_FAULT);
   RE_PLT_Appl_NvMHandler_50ms();
   ASSERT_EQ(g_rfe_write_calls, 0U);

   g_rfe_status = NVM_REQ_OK;
   RE_PLT_Appl_NvMHandler_50ms();
   ASSERT_GE(g_rfe_write_calls, 1U);
}

TEST_F(SWCPLTApplNvMHandlerUnitFixture, TriggerNonImmediateCorrectablePendingThenMain50msCompletesWrite)
{
   g_correctable_status = NVM_REQ_PENDING;
   Trigger_Write_to_NVM(CODED_FALSE, CDD_FAILSAFE_ECC);
   RE_PLT_Appl_NvMHandler_50ms();
   ASSERT_EQ(g_correctable_write_calls, 0U);

   g_correctable_status = NVM_REQ_OK;
   RE_PLT_Appl_NvMHandler_50ms();
   ASSERT_GE(g_correctable_write_calls, 1U);
}

TEST_F(SWCPLTApplNvMHandlerUnitFixture, CorrectableFaultHandlerWritesAndClearsPendingWhenStatusNotPending)
{
   g_correctable_status               = NVM_REQ_OK;
   u8_nvblock_write_pending_corrfault = CODED_TRUE;

   NVM_REQ_correctablefaultHandler();

   ASSERT_GE(g_read_correctable_calls, 1U);
   ASSERT_EQ(g_correctable_get_status_calls, 1U);
   ASSERT_EQ(g_correctable_write_calls, 1U);
   ASSERT_EQ(u8_nvblock_write_pending_corrfault, CODED_FALSE);
}

TEST_F(SWCPLTApplNvMHandlerUnitFixture, CorrectableFaultHandlerDoesNotWriteWhenStatusPending)
{
   g_correctable_status               = NVM_REQ_PENDING;
   u8_nvblock_write_pending_corrfault = CODED_TRUE;

   NVM_REQ_correctablefaultHandler();

   ASSERT_GE(g_read_correctable_calls, 1U);
   ASSERT_EQ(g_correctable_get_status_calls, 1U);
   ASSERT_EQ(g_correctable_write_calls, 0U);
   ASSERT_EQ(u8_nvblock_write_pending_corrfault, CODED_TRUE);
}

TEST_F(SWCPLTApplNvMHandlerUnitFixture, TriggerNonImmediateAlignmentPendingThenMain50msCompletesWrite)
{
   g_nvmbringup_status = NVM_REQ_PENDING;
   Trigger_Write_to_NVM(CODED_FALSE, CDD_ALIGNMENT);
   ASSERT_EQ(g_nvmbringup_write_calls, 0U);

   g_nvmbringup_status = NVM_REQ_OK;
   RE_PLT_Appl_NvMHandler_50ms();
   ASSERT_GE(g_nvmbringup_write_calls, 1U);
   ASSERT_EQ(g_last_nvm_flag_status, CODED_TRUE);
}
TEST_F(SWCPLTApplNvMHandlerUnitFixture, TriggerSensorPosThenMain50msCompletesWrite)
{
   Trigger_Write_to_NVM(CODED_FALSE, CDD_SENSORPOS);
   ASSERT_EQ(g_sensorpos_write_calls, 0U);
   RE_PLT_Appl_NvMHandler_50ms();
   ASSERT_EQ(g_sensorpos_write_calls, 1U);
}

TEST_F(SWCPLTApplNvMHandlerUnitFixture, TriggerNonImmediateFailSafePendingThenMain50msCompletesWrite)
{
   g_failsafe_status = NVM_REQ_PENDING;
   Trigger_Write_to_NVM(CODED_FALSE, CDD_FAIL_SAFE);
   RE_PLT_Appl_NvMHandler_50ms();
   ASSERT_EQ(g_failsafe_write_calls, 0U);

   g_failsafe_status = NVM_REQ_OK;
   RE_PLT_Appl_NvMHandler_50ms();
   ASSERT_GE(g_failsafe_write_calls, 1U);
}

TEST_F(SWCPLTApplNvMHandlerUnitFixture, TriggerNonImmediateStaticAlignmentPendingThenMain50msCompletesWrite)
{
   g_static_status = NVM_REQ_PENDING;
   Trigger_Write_to_NVM(CODED_FALSE, UDS_STATIC_ALIGNMENT);
   RE_PLT_Appl_NvMHandler_50ms();
   ASSERT_EQ(g_static_write_calls, 0U);

   g_static_status = NVM_REQ_OK;
   RE_PLT_Appl_NvMHandler_50ms();
   ASSERT_GE(g_static_write_calls, 1U);
}

TEST_F(SWCPLTApplNvMHandlerUnitFixture, TriggerNonImmediateManualAlignmentPendingThenMain50msCompletesWrite)
{
   g_manual_status = NVM_REQ_PENDING;
   Trigger_Write_to_NVM(CODED_FALSE, UDS_MANUAL_ALIGNMENT);
   RE_PLT_Appl_NvMHandler_50ms();
   ASSERT_EQ(g_manual_write_calls, 0U);

   g_manual_status = NVM_REQ_OK;
   RE_PLT_Appl_NvMHandler_50ms();
   ASSERT_GE(g_manual_write_calls, 1U);
}

TEST_F(SWCPLTApplNvMHandlerUnitFixture, TriggerVseParamsPendingThenMain50msCompletesWrite)
{
   g_vse_status                       = NVM_REQ_PENDING;
   u8_nvblock_write_pending_vseparams = CODED_TRUE;
   RE_PLT_Appl_NvMHandler_50ms();
   ASSERT_EQ(g_vse_write_calls, 0U);

   g_vse_status = NVM_REQ_OK;
   RE_PLT_Appl_NvMHandler_50ms();
   ASSERT_GE(g_vse_write_calls, 1U);
}

TEST_F(SWCPLTApplNvMHandlerUnitFixture, HandleFailSafeWriteReturnsNotOkWhenStatusPending)
{
   g_failsafe_status = NVM_REQ_PENDING;

   const Std_ReturnType ret = Handle_FailSafeWrite();

   ASSERT_EQ(ret, E_NOT_OK);
   ASSERT_EQ(g_read_failsafe_calls, 1U);
   ASSERT_EQ(g_failsafe_get_status_calls, 1U);
   ASSERT_EQ(g_failsafe_write_calls, 0U);
}

TEST_F(SWCPLTApplNvMHandlerUnitFixture, HandleFailSafeWriteReturnsNotOkWhenWriteBlockFails)
{
   g_failsafe_status    = NVM_REQ_OK;
   g_failsafe_write_ret = E_NOT_OK;

   const Std_ReturnType ret = Handle_FailSafeWrite();

   ASSERT_EQ(ret, E_NOT_OK);
   ASSERT_EQ(g_read_failsafe_calls, 1U);
   ASSERT_EQ(g_failsafe_get_status_calls, 1U);
   ASSERT_EQ(g_failsafe_write_calls, 1U);
}

TEST_F(SWCPLTApplNvMHandlerUnitFixture, HandleRfeFaultWriteReturnsNotOkWhenStatusPending)
{
   g_rfe_status = NVM_REQ_PENDING;

   const Std_ReturnType ret = Handle_Rfe_FaultWrite();

   ASSERT_EQ(ret, E_NOT_OK);
   ASSERT_EQ(g_read_rfe_calls, 1U);
   ASSERT_EQ(g_rfe_get_status_calls, 1U);
   ASSERT_EQ(g_rfe_write_calls, 0U);
}

TEST_F(SWCPLTApplNvMHandlerUnitFixture, HandleRfeFaultWriteReturnsNotOkWhenWriteBlockFails)
{
   g_rfe_status    = NVM_REQ_OK;
   g_rfe_write_ret = E_NOT_OK;

   const Std_ReturnType ret = Handle_Rfe_FaultWrite();

   ASSERT_EQ(ret, E_NOT_OK);
   ASSERT_EQ(g_read_rfe_calls, 1U);
   ASSERT_EQ(g_rfe_get_status_calls, 1U);
   ASSERT_EQ(g_rfe_write_calls, 1U);
}

TEST_F(SWCPLTApplNvMHandlerUnitFixture, TriggerUnknownCallerDoesNotPerformWrites)
{
   Trigger_Write_to_NVM(CODED_FALSE, (Dt_Nv_Caller_ID)0xFFU);
   ASSERT_EQ(g_nvmbringup_write_calls, 0U);
   ASSERT_EQ(g_failsafe_write_calls, 0U);
}

TEST_F(SWCPLTApplNvMHandlerUnitFixture, CS_GetError_Status_Operation_ExecutesSuccessfully)
{
   uint8 nvMErrorStatus = 0U;

   CS_GetError_Status_Operation(&nvMErrorStatus);

   SUCCEED();
}

TEST_F(SWCPLTApplNvMHandlerUnitFixture, CS_ReadNvM_Value_Operation_CopiesSensorPositionWhenPointerIsValid)
{
   Dt_SensorPosition_Status_T sensorPosReadRecord = {};
   Dt_SensorPosition_Data_T expectedRecord        = {};

   expectedRecord.SensorPosition_Data.SensorPos_Value       = 0x12U;
   expectedRecord.SensorPosition_Data.SensorPos_Lock_Status = 0x34U;
   expectedRecord.SensorPos_CRC                             = 0x55667788U;
   *Rte_Pim_Sensorpos_PIM_UDS()                             = expectedRecord;
   CS_ReadNvM_Value_Operation(&sensorPosReadRecord);

   ASSERT_EQ(sensorPosReadRecord.SensorPos_Value, expectedRecord.SensorPosition_Data.SensorPos_Value);
   ASSERT_EQ(sensorPosReadRecord.SensorPos_Lock_Status, expectedRecord.SensorPosition_Data.SensorPos_Lock_Status);
}
TEST_F(SWCPLTApplNvMHandlerUnitFixture, CS_ReadNvM_Value_Operation_DoesNothingWhenPointerIsNull)
{
   *Rte_Pim_Sensorpos_PIM_UDS() = {};
   CS_ReadNvM_Value_Operation(nullptr);
   SUCCEED();
}
