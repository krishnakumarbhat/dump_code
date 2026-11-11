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
 *             File:  Rte_SWC_PLT_CDD_MCU_Safety.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <SWC_PLT_CDD_MCU_Safety>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PLT_CDD_MCU_SAFETY_H
# define RTE_SWC_PLT_CDD_MCU_SAFETY_H

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

# include "Rte_SWC_PLT_CDD_MCU_Safety_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Dt_Fault_name_FHTI, RTE_VAR_INIT) Rte_SWC_PLT_Appl_ModeManager_Rp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_MCU_Safety_Pp_MPU_lock_sts_De_MPU_lock_sts;
extern VAR(Dt_InitializationStatus, RTE_VAR_INIT) Rte_SWC_PLT_CDD_MCU_Safety_Pp_PlatformInitializationStatus_De_MCU_InitializationStatus;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_MCU_Safety_Pp_TR_initMCU_Fail_De_TR_InitMCU_fail;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_MPU_lock_request_De_MPU_lock_sts;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_FCRU_Pp_PMU_FaultB_PinIntegrity_De_PMU_FaultB_PinIntegrityStat;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_FailSafe_Pp_Repetitive_Reset_Status_De_Repetitive_Reset_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_PlatformTime_Pp_TR_platform_Time_De_PlatformTime;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_ExternalWdg_Pp_external_watchdog_init_status_de_wdginit_status;

#  define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Pp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI (0U)
#  define Rte_InitValue_Pp_MCU_Ram_Fault_Test_Status_De_MCU_Ram_Fault_Test_Status (0U)
#  define Rte_InitValue_Pp_MPU_lock_sts_De_MPU_lock_sts (0U)
#  define Rte_InitValue_Pp_PlatformInitializationStatus_De_MCU_InitializationStatus (0U)
#  define Rte_InitValue_Rp_FCCU_Config_State_FCCU_Config_State (0U)
#  define Rte_InitValue_Rp_FCCU_Init_Status_De_Init_Status (0U)
#  define Rte_InitValue_Rp_MPU_lock_request_De_MPU_lock_sts (0U)
#  define Rte_InitValue_Rp_PMU_FaultB_PinIntegrity_De_PMU_FaultB_PinIntegrityStat (0U)
#  define Rte_InitValue_Rp_Repetitive_Reset_Status_De_Repetitive_Reset_Status (85U)
#  define Rte_InitValue_Rp_TR_PlatformTime_De_PlatformTime (85U)
#  define Rte_InitValue_Rp_external_watchdog_init_status_de_wdginit_status (0U)
# endif

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo(P2VAR(Rte_DT_Dt_StaticRegCheckFailureInfo_0, AUTOMATIC, RTE_SWC_PLT_CDD_MCU_SAFETY_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo(P2VAR(Dt_StaticRegCheckFailureInfo, AUTOMATIC, RTE_SWC_PLT_CDD_MCU_SAFETY_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_MCU_Safety_Pp_ID_data_De_ID_data(P2CONST(Dt_ID_data, AUTOMATIC, RTE_SWC_PLT_CDD_MCU_SAFETY_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_MCU_Safety_Pp_MemExceptionInfo_De_MemExceptionInfo(P2CONST(Dt_Memory_Exception_Info_T, AUTOMATIC, RTE_SWC_PLT_CDD_MCU_SAFETY_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_MCU_Safety_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo(P2CONST(Rte_DT_Dt_StaticRegCheckFailureInfo_0, AUTOMATIC, RTE_SWC_PLT_CDD_MCU_SAFETY_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PLT_CDD_MCU_Safety_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo(P2CONST(Dt_StaticRegCheckFailureInfo, AUTOMATIC, RTE_SWC_PLT_CDD_MCU_SAFETY_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
# endif

# define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Rp_FCCU_Config_State_FCCU_Config_State Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_FCCU_Config_State_FCCU_Config_State
#  define Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_FCCU_Config_State_FCCU_Config_State(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_FCCU_Init_Status_De_Init_Status Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_FCCU_Init_Status_De_Init_Status
#  define Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_FCCU_Init_Status_De_Init_Status(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_MPU_lock_request_De_MPU_lock_sts Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_MPU_lock_request_De_MPU_lock_sts
#  define Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_MPU_lock_request_De_MPU_lock_sts(data) (*(data) = Rte_SWC_PLT_CDD_XCP_Pp_MPU_lock_request_De_MPU_lock_sts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_PMU_FaultB_PinIntegrity_De_PMU_FaultB_PinIntegrityStat Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_PMU_FaultB_PinIntegrity_De_PMU_FaultB_PinIntegrityStat
#  define Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_PMU_FaultB_PinIntegrity_De_PMU_FaultB_PinIntegrityStat(data) (*(data) = Rte_SWC_PLT_CDD_FCRU_Pp_PMU_FaultB_PinIntegrity_De_PMU_FaultB_PinIntegrityStat, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_Repetitive_Reset_Status_De_Repetitive_Reset_Status Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_Repetitive_Reset_Status_De_Repetitive_Reset_Status
#  define Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_Repetitive_Reset_Status_De_Repetitive_Reset_Status(data) (*(data) = Rte_SWC_PLT_CDD_FailSafe_Pp_Repetitive_Reset_Status_De_Repetitive_Reset_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo
#  define Rte_Read_Rp_TR_PlatformTime_De_PlatformTime Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_TR_PlatformTime_De_PlatformTime
#  define Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_TR_PlatformTime_De_PlatformTime(data) (*(data) = Rte_SWC_PLT_Appl_PlatformTime_Pp_TR_platform_Time_De_PlatformTime, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_external_watchdog_init_status_de_wdginit_status Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_external_watchdog_init_status_de_wdginit_status
#  define Rte_Read_SWC_PLT_CDD_MCU_Safety_Rp_external_watchdog_init_status_de_wdginit_status(data) (*(data) = Rte_SWC_PLT_CDD_ExternalWdg_Pp_external_watchdog_init_status_de_wdginit_status, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Pp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI Rte_Write_SWC_PLT_CDD_MCU_Safety_Pp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI
#  define Rte_Write_SWC_PLT_CDD_MCU_Safety_Pp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI(data) (Rte_SWC_PLT_Appl_ModeManager_Rp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_ID_data_De_ID_data Rte_Write_SWC_PLT_CDD_MCU_Safety_Pp_ID_data_De_ID_data
#  define Rte_Write_Pp_MCU_Ram_Fault_Test_Status_De_MCU_Ram_Fault_Test_Status Rte_Write_SWC_PLT_CDD_MCU_Safety_Pp_MCU_Ram_Fault_Test_Status_De_MCU_Ram_Fault_Test_Status
#  define Rte_Write_SWC_PLT_CDD_MCU_Safety_Pp_MCU_Ram_Fault_Test_Status_De_MCU_Ram_Fault_Test_Status(data) (RTE_E_OK)
#  define Rte_Write_Pp_MPU_lock_sts_De_MPU_lock_sts Rte_Write_SWC_PLT_CDD_MCU_Safety_Pp_MPU_lock_sts_De_MPU_lock_sts
#  define Rte_Write_SWC_PLT_CDD_MCU_Safety_Pp_MPU_lock_sts_De_MPU_lock_sts(data) (Rte_SWC_PLT_CDD_MCU_Safety_Pp_MPU_lock_sts_De_MPU_lock_sts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_MemExceptionInfo_De_MemExceptionInfo Rte_Write_SWC_PLT_CDD_MCU_Safety_Pp_MemExceptionInfo_De_MemExceptionInfo
#  define Rte_Write_Pp_PlatformInitializationStatus_De_MCU_InitializationStatus Rte_Write_SWC_PLT_CDD_MCU_Safety_Pp_PlatformInitializationStatus_De_MCU_InitializationStatus
#  define Rte_Write_SWC_PLT_CDD_MCU_Safety_Pp_PlatformInitializationStatus_De_MCU_InitializationStatus(data) (Rte_SWC_PLT_CDD_MCU_Safety_Pp_PlatformInitializationStatus_De_MCU_InitializationStatus = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo Rte_Write_SWC_PLT_CDD_MCU_Safety_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo
#  define Rte_Write_Pp_TR_initMCU_Fail_De_TR_InitMCU_fail Rte_Write_SWC_PLT_CDD_MCU_Safety_Pp_TR_initMCU_Fail_De_TR_InitMCU_fail
#  define Rte_Write_SWC_PLT_CDD_MCU_Safety_Pp_TR_initMCU_Fail_De_TR_InitMCU_fail(data) (Rte_SWC_PLT_CDD_MCU_Safety_Pp_TR_initMCU_Fail_De_TR_InitMCU_fail = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define SWC_PLT_CDD_FailSafe_START_SEC_CODE
#  include "SWC_PLT_CDD_FailSafe_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_CDD_FailSafe_CODE) FailSafe_Log_ResetReason(Dt_ECU_ResetReasonType reset_reason); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_CDD_FailSafe_STOP_SEC_CODE
#  include "SWC_PLT_CDD_FailSafe_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CS_MCU_Safety_FailSafe_ResetReason_FailSafe_Log_ResetReason(arg1) (FailSafe_Log_ResetReason(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_Rp_PltFCCU_TestFlashMemECCPath_FCCU_TestFlashMemECCPath(arg1) (RTE_E_UNCONNECTED)

# endif /* !defined(RTE_CORE) */


# define SWC_PLT_CDD_MCU_Safety_START_SEC_CODE
# include "SWC_PLT_CDD_MCU_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CS_MCU_Safety_Fault_Injection CS_MCU_Safety_Fault_Injection
#  define RTE_RUNNABLE_ECC_CacheMemory_SafetyCore_Disable ECC_CacheMemory_SafetyCore_Disable
#  define RTE_RUNNABLE_ECC_CacheMemory_SafetyCore_Enable ECC_CacheMemory_SafetyCore_Enable
#  define RTE_RUNNABLE_ECC_CacheMemory_SafetyCore_Status ECC_CacheMemory_SafetyCore_Status
#  define RTE_RUNNABLE_ECC_FlashMemory_Fault_Report_Check ECC_FlashMemory_Fault_Report_Check
#  define RTE_RUNNABLE_ECU_Soft_Reset ECU_Soft_Reset
#  define RTE_RUNNABLE_RCCU_CheckerCore_Status RCCU_CheckerCore_Status
#  define RTE_RUNNABLE_RE_PLT_MCU_Safety_50ms RE_PLT_MCU_Safety_50ms
#  define RTE_RUNNABLE_RE_PLT_MCU_Safety_Init RE_PLT_MCU_Safety_Init
#  define RTE_RUNNABLE_RRU_FS_InitTest RRU_FS_InitTest
# endif

FUNC(void, SWC_PLT_CDD_MCU_Safety_CODE) CS_MCU_Safety_Fault_Injection(uint8 Injection_control, uint8 Failure_Type); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_CDD_MCU_Safety_CODE) ECC_CacheMemory_SafetyCore_Disable(P2VAR(Dt_PltRRUFS_SafetyReq_Status_T, AUTOMATIC, RTE_SWC_PLT_CDD_MCU_SAFETY_APPL_VAR) ECC_CacheMemory_Status); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_CDD_MCU_Safety_CODE) ECC_CacheMemory_SafetyCore_Enable(P2VAR(Dt_PltRRUFS_SafetyReq_Status_T, AUTOMATIC, RTE_SWC_PLT_CDD_MCU_SAFETY_APPL_VAR) ECC_CacheMemory_Status); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_CDD_MCU_Safety_CODE) ECC_CacheMemory_SafetyCore_Status(P2VAR(Dt_PltRRUFS_SafetyReq_Status_T, AUTOMATIC, RTE_SWC_PLT_CDD_MCU_SAFETY_APPL_VAR) ECC_CacheMemory_Status); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_CDD_MCU_Safety_CODE) ECC_FlashMemory_Fault_Report_Check(P2VAR(Dt_PltRRUFS_SafetyReq_Status_T, AUTOMATIC, RTE_SWC_PLT_CDD_MCU_SAFETY_APPL_VAR) ECC_FlashMemory_Status); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_CDD_MCU_Safety_CODE) ECU_Soft_Reset(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_CDD_MCU_Safety_CODE) RCCU_CheckerCore_Status(P2VAR(Dt_PltRRUFS_SafetyReq_Status_T, AUTOMATIC, RTE_SWC_PLT_CDD_MCU_SAFETY_APPL_VAR) CheckerCore_Status); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_CDD_MCU_Safety_CODE) RE_PLT_MCU_Safety_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_CDD_MCU_Safety_CODE) RE_PLT_MCU_Safety_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_CDD_MCU_Safety_CODE) RRU_FS_InitTest(P2VAR(Dt_PltRRUFS_SafetyReq_Status_T, AUTOMATIC, RTE_SWC_PLT_CDD_MCU_SAFETY_APPL_VAR) SafetyReq_Status); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

# define SWC_PLT_CDD_MCU_Safety_STOP_SEC_CODE
# include "SWC_PLT_CDD_MCU_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PLT_CDD_MCU_SAFETY_H */

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
