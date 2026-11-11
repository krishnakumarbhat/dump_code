/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_SWC_PLT_CDD_FailSafe.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <SWC_PLT_CDD_FailSafe>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PLT_CDD_FAILSAFE_H
# define RTE_SWC_PLT_CDD_FAILSAFE_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_SWC_PLT_CDD_FailSafe_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Dt_Fault_name_FHTI, RTE_VAR_INIT) Rte_SWC_PLT_Appl_ModeManager_Rp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_FailSafe_Pp_RFE_Repetitive_Reset_Status_De_RFE_Repetitive_Reset_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_FailSafe_Pp_Repetitive_Reset_Status_De_Repetitive_Reset_Status;

#  define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Pp_FailSafe_Verify_ResetReason_FailSafe_Verify_ResetReason (0U)
#  define Rte_InitValue_Pp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI (0U)
#  define Rte_InitValue_Pp_RFE_Repetitive_Reset_Status_De_RFE_Repetitive_Reset_Status (0U)
#  define Rte_InitValue_Pp_Repetitive_Reset_Status_De_Repetitive_Reset_Status (85U)
# endif

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_FailSafe_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason(P2VAR(Dt_FailSafe_ResetReason_T, AUTOMATIC, RTE_SWC_PLT_CDD_FAILSAFE_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_FailSafe_Rp_MemExceptionInfo_De_MemExceptionInfo(P2VAR(Dt_Memory_Exception_Info_T, AUTOMATIC, RTE_SWC_PLT_CDD_FAILSAFE_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_FailSafe_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo(P2VAR(Rte_DT_Dt_StaticRegCheckFailureInfo_0, AUTOMATIC, RTE_SWC_PLT_CDD_FAILSAFE_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_FailSafe_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo(P2VAR(Dt_StaticRegCheckFailureInfo, AUTOMATIC, RTE_SWC_PLT_CDD_FAILSAFE_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_FailSafe_Pp_ECC_Correctable_Fault_De_ECC_Correctable_Fault(P2CONST(Dt_ECC_Correctable_Error_Counters, AUTOMATIC, RTE_SWC_PLT_CDD_FAILSAFE_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_FailSafe_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason(P2CONST(Dt_FailSafe_ResetReason_T, AUTOMATIC, RTE_SWC_PLT_CDD_FAILSAFE_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_FailSafe_Pp_Hardware_Fault_Status_De_Hardware_Fault_Status(P2CONST(Dt_Hardware_Fault_Error_Status, AUTOMATIC, RTE_SWC_PLT_CDD_FAILSAFE_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

# define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason Rte_Read_SWC_PLT_CDD_FailSafe_Rp_FailSafe_ResetReason_De_FailSafe_ResetReason
#  define Rte_Read_Rp_MemExceptionInfo_De_MemExceptionInfo Rte_Read_SWC_PLT_CDD_FailSafe_Rp_MemExceptionInfo_De_MemExceptionInfo
#  define Rte_Read_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo Rte_Read_SWC_PLT_CDD_FailSafe_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Pp_ECC_Correctable_Fault_De_ECC_Correctable_Fault Rte_Write_SWC_PLT_CDD_FailSafe_Pp_ECC_Correctable_Fault_De_ECC_Correctable_Fault
#  define Rte_Write_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason Rte_Write_SWC_PLT_CDD_FailSafe_Pp_FailSafe_ResetReason_De_FailSafe_ResetReason
#  define Rte_Write_Pp_FailSafe_Verify_ResetReason_FailSafe_Verify_ResetReason Rte_Write_SWC_PLT_CDD_FailSafe_Pp_FailSafe_Verify_ResetReason_FailSafe_Verify_ResetReason
#  define Rte_Write_SWC_PLT_CDD_FailSafe_Pp_FailSafe_Verify_ResetReason_FailSafe_Verify_ResetReason(data) (RTE_E_OK)
#  define Rte_Write_Pp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI Rte_Write_SWC_PLT_CDD_FailSafe_Pp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI
#  define Rte_Write_SWC_PLT_CDD_FailSafe_Pp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI(data) (Rte_SWC_PLT_Appl_ModeManager_Rp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_Hardware_Fault_Status_De_Hardware_Fault_Status Rte_Write_SWC_PLT_CDD_FailSafe_Pp_Hardware_Fault_Status_De_Hardware_Fault_Status
#  define Rte_Write_Pp_RFE_Repetitive_Reset_Status_De_RFE_Repetitive_Reset_Status Rte_Write_SWC_PLT_CDD_FailSafe_Pp_RFE_Repetitive_Reset_Status_De_RFE_Repetitive_Reset_Status
#  define Rte_Write_SWC_PLT_CDD_FailSafe_Pp_RFE_Repetitive_Reset_Status_De_RFE_Repetitive_Reset_Status(data) (Rte_SWC_PLT_CDD_FailSafe_Pp_RFE_Repetitive_Reset_Status_De_RFE_Repetitive_Reset_Status = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_Repetitive_Reset_Status_De_Repetitive_Reset_Status Rte_Write_SWC_PLT_CDD_FailSafe_Pp_Repetitive_Reset_Status_De_Repetitive_Reset_Status
#  define Rte_Write_SWC_PLT_CDD_FailSafe_Pp_Repetitive_Reset_Status_De_Repetitive_Reset_Status(data) (Rte_SWC_PLT_CDD_FailSafe_Pp_Repetitive_Reset_Status_De_Repetitive_Reset_Status = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define SWC_PLT_Appl_NvMHandler_START_SEC_CODE
#  include "SWC_PLT_Appl_NvMHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_Appl_NvMHandler_CODE) Trigger_Write_to_NVM(uint8 u8_ImmidieteWrite, Dt_Nv_Caller_ID dt_Nv_Caller_Id); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_Appl_NvMHandler_STOP_SEC_CODE
#  include "SWC_PLT_Appl_NvMHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define WdgM_OsCore0_ASIL_START_SEC_CODE
#  include "WdgM_OsCore0_ASIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, WdgM_OsCore0_ASIL_CODE) WdgM_GetFirstExpiredSEID(P2VAR(WdgM_SupervisedEntityIdType, AUTOMATIC, RTE_WDGM_OSCORE0_ASIL_APPL_VAR) SEID); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define WdgM_OsCore0_ASIL_STOP_SEC_CODE
#  include "WdgM_OsCore0_ASIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CS_Trigger_Write_to_NVM_NvHandler_Trigger_Write_To_NVM(arg1, arg2) (Trigger_Write_to_NVM(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_CS_WdgM_General_GetFirstExpiredSEID WdgM_GetFirstExpiredSEID
#  define Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ExceptiontReason_GetErrorStatus(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ExceptiontReason_WriteBlock(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_GetErrorStatus(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_ReadBlock(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_Rp_SWC_PLT_CDD_FailSafe_ResetReason_WriteBlock(arg1) (RTE_E_UNCONNECTED)

/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(Dt_FailSafe_ExceptionReason_T, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_CDD_FailSafe_ExceptionReason_DefaultValue;
extern CONST(Dt_FailSafe_ResetReason_T, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PLT_CDD_FailSafe_ResetReason_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  define Rte_CData_ExceptionReason_DefaultValue() (&Rte_SWC_PLT_CDD_FailSafe_ExceptionReason_DefaultValue)

#  define Rte_CData_ResetReason_DefaultValue() (&Rte_SWC_PLT_CDD_FailSafe_ResetReason_DefaultValue)

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_CLEARED_DEFAULT_RTE_PIM_GROUP_ASIL_B_LOCAL_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Dt_FailSafe_ExceptionReason_T, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_SWC_PLT_CDD_FailSafe_ExceptionReason_PIM;

#   define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_CLEARED_DEFAULT_RTE_PIM_GROUP_ASIL_B_LOCAL_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_ExceptionReason_PIM() \
          (&Rte_SWC_PLT_CDD_FailSafe_ExceptionReason_PIM)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define SWC_PLT_CDD_FailSafe_START_SEC_CODE
# include "SWC_PLT_CDD_FailSafe_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CS_FailSafe_Fault_Injection CS_FailSafe_Fault_Injection
#  define RTE_RUNNABLE_CS_Failsafe_Log_ResetReason_at_Startup CS_Failsafe_Log_ResetReason_at_Startup
#  define RTE_RUNNABLE_CS_Get_RepetativeReset_Faultnum_Operation CS_Get_RepetativeReset_Faultnum_Operation
#  define RTE_RUNNABLE_FailSafe_Log_ResetReason FailSafe_Log_ResetReason
#  define RTE_RUNNABLE_RE_PLT_FailSafe_Init RE_PLT_FailSafe_Init
#  define RTE_RUNNABLE_RE_PLT_FailSafe_Main_50ms RE_PLT_FailSafe_Main_50ms
# endif

FUNC(void, SWC_PLT_CDD_FailSafe_CODE) CS_FailSafe_Fault_Injection(uint8 Injection_control, uint8 Failure_Type); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_CDD_FailSafe_CODE) CS_Failsafe_Log_ResetReason_at_Startup(uint8 reset_reason); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_CDD_FailSafe_CODE) CS_Get_RepetativeReset_Faultnum_Operation(P2VAR(uint8, AUTOMATIC, RTE_SWC_PLT_CDD_FAILSAFE_APPL_VAR) faultnum); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_CDD_FailSafe_CODE) FailSafe_Log_ResetReason(Dt_ECU_ResetReasonType reset_reason); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_CDD_FailSafe_CODE) RE_PLT_FailSafe_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_CDD_FailSafe_CODE) RE_PLT_FailSafe_Main_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_PLT_CDD_FailSafe_STOP_SEC_CODE
# include "SWC_PLT_CDD_FailSafe_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK (1U)

#  define RTE_E_WdgM_General_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PLT_CDD_FAILSAFE_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
