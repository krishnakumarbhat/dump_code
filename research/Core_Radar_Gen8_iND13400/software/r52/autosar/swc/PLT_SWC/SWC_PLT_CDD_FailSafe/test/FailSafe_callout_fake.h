/*===========================================================================*/
/**
 * @file FailSafe_callout_fake.h
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
 * Mocking functions for the SWC_PLT_CDD_FailSafe FFF
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
#include "Rte_Type.h"
#include "fff.h"

/*===========================================================================*
 * C Header Files
 *===========================================================================*/
#ifdef __cplusplus
extern "C"
{
#endif
#include "SWC_PLT_CDD_FailSafe.h"
   /*===========================================================================*
    * Fake value functions - FailSafe functions
    *===========================================================================*/
   DECLARE_FAKE_VOID_FUNC(FailSafe_Log_ResetReason, Dt_ECU_ResetReasonType);
   DECLARE_FAKE_VALUE_FUNC(FailSafe_ResetReason_T *, Get_Platform_ResetReason_Info);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason, Dt_FailSafe_ResetReason_T *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_SWC_PLT_CDD_FailSafe_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason,
                           const Dt_FailSafe_ResetReason_T *);
   DECLARE_FAKE_VOID_FUNC(Trigger_Write_to_NVM, uint8, Dt_Nv_Caller_ID);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_SWC_PLT_CDD_FailSafe_CS_Trigger_Write_to_NVM_NvHandler_Trigger_Write_To_NVM,
                           uint8, Dt_Nv_Caller_ID);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_SWC_PLT_CDD_FailSafe_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason,
                           Dt_FailSafe_ResetReason_T *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_SWC_PLT_CDD_FailSafe_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo,
                           Rte_DT_Dt_StaticRegCheckFailureInfo_0 *);

#ifdef __cplusplus
}
#endif

#define FFF_FAKES_PLATFORM_RESET_LIST(FAKE)                                                                                       \
   FAKE(Get_Platform_ResetReason_Info)                                                                                            \
   FAKE(FailSafe_Log_ResetReason)                                                                                                 \
   FAKE(Rte_Read_SWC_PLT_CDD_FailSafe_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason)                                            \
   FAKE(Rte_Read_SWC_PLT_CDD_FailSafe_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo)
