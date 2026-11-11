#ifndef FAILSAFE_FAKE_H_
#define FAILSAFE_FAKE_H_

#include "Can_GeneralTypes.h"
#include "EthTrcv_GeneralTypes.h"
#include "Rte_Type.h"
#include "Std_Types.h"

#include "fff.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "mcu_reset_wrapper.h"

   DECLARE_FAKE_VOID_FUNC(Mcu_Reset, Mcu_reset_T);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_CDD_FailSafe_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason,
                           const Dt_FailSafe_ResetReason_T *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_SWC_PLT_CDD_FailSafe_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason,
                           Dt_FailSafe_ResetReason_T *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_CDD_FailSafe_Pp_Hardware_Fault_Status_De_Hardware_Fault_Status,
                           const Dt_Hardware_Fault_Error_Status *);
   DECLARE_FAKE_VOID_FUNC(Trigger_Write_to_NVM, uint8, Dt_Nv_Caller_ID);
   DECLARE_FAKE_VOID_FUNC(Fail_Safe_Read_Reset_Reason_Callout);
   DECLARE_FAKE_VOID_FUNC(FailSafe_Check_RepetitiveResetCount);
   DECLARE_FAKE_VOID_FUNC(Fail_Safe_Clear_Last_Cycle_Callout);
   DECLARE_FAKE_VOID_FUNC(Fail_Safe_Store_Reset_Reason_Callout);
   DECLARE_FAKE_VOID_FUNC(Fail_Safe_Check_NVM_Status_Callout);
   DECLARE_FAKE_VALUE_FUNC(uint8, FailSafe_Verify_ResetReason, uint8 *);
   DECLARE_FAKE_VOID_FUNC(SuspendAllInterrupts);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, WdgM_GetFirstExpiredSEID, WdgM_SupervisedEntityIdType *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Can_SetControllerMode, uint8, Can_ControllerStateType);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, EthTrcv_30_Rtl9010_SetTransceiverMode, uint8, EthTrcv_ModeType);

#ifdef __cplusplus
}
#endif

#endif /* FAILSAFE_FAKE_H_ */
