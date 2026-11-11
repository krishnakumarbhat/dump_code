#include "FailSafe_fake.h"
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_CDD_FailSafe_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason,
                       const Dt_FailSafe_ResetReason_T *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_CDD_FailSafe_Pp_Hardware_Fault_Status_De_Hardware_Fault_Status,
                       const Dt_Hardware_Fault_Error_Status *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_SWC_PLT_CDD_FailSafe_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason,
                       Dt_FailSafe_ResetReason_T *);
DEFINE_FAKE_VOID_FUNC(Trigger_Write_to_NVM, uint8, Dt_Nv_Caller_ID);
DEFINE_FAKE_VOID_FUNC(Fail_Safe_Read_Reset_Reason_Callout);
DEFINE_FAKE_VOID_FUNC(FailSafe_Check_RepetitiveResetCount);
DEFINE_FAKE_VOID_FUNC(Fail_Safe_Clear_Last_Cycle_Callout);
DEFINE_FAKE_VOID_FUNC(Fail_Safe_Store_Reset_Reason_Callout);
DEFINE_FAKE_VOID_FUNC(Fail_Safe_Check_NVM_Status_Callout);
DEFINE_FAKE_VALUE_FUNC(uint8, FailSafe_Verify_ResetReason, uint8 *);
DEFINE_FAKE_VOID_FUNC(SuspendAllInterrupts);
DEFINE_FAKE_VOID_FUNC(Mcu_Reset, Mcu_reset_T);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, WdgM_GetFirstExpiredSEID, WdgM_SupervisedEntityIdType *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Can_SetControllerMode, uint8, Can_ControllerStateType);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, EthTrcv_30_Rtl9010_SetTransceiverMode, uint8, EthTrcv_ModeType);
