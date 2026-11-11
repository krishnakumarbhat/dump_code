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
 *             File:  Rte_SWC_PLT_Appl_ModeManager.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <SWC_PLT_Appl_ModeManager>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PLT_APPL_MODEMANAGER_H
# define RTE_SWC_PLT_APPL_MODEMANAGER_H

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

# include "Rte_SWC_PLT_Appl_ModeManager_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_ModeManager_Pp_CommandRadiate_Final_De_CommandRadiate_Final;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_ModeManager_Pp_IsRadiateForced_De_IsRadiateForced;
extern VAR(Dt_SystemOperationMode, RTE_VAR_INIT) Rte_SWC_PLT_Appl_ModeManager_Pp_OperationMode_System_De_OperationMode_System;
extern VAR(Dt_Fault_name_FHTI, RTE_VAR_INIT) Rte_SWC_PLT_Appl_ModeManager_Rp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI;
extern VAR(Dt_InitializationStatus, RTE_VAR_INIT) Rte_SWC_PLT_CDD_MCU_Safety_Pp_PlatformInitializationStatus_De_MCU_InitializationStatus;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_FailSafe_Pp_Repetitive_Reset_Status_De_Repetitive_Reset_Status;
extern VAR(Dt_VBattState_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_IoHwAb_Pp_Vbatt_State_De_Vbatt_State;
extern VAR(Dt_ForceRadiate, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_XCP_ForceRadiate_De_XCPForceRadiate;

#  define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Pp_CommandRadiate_Final_De_CommandRadiate_Final (85U)
#  define Rte_InitValue_Pp_IsRadiateForced_De_IsRadiateForced (85U)
#  define Rte_InitValue_Pp_OperationMode_System_De_OperationMode_System (0U)
#  define Rte_InitValue_Pp_ShutdownTask_De_shutdownTask (85U)
#  define Rte_InitValue_Rp_CustForceRadiate_CustForceRadiate (2U)
#  define Rte_InitValue_Rp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI (0U)
#  define Rte_InitValue_Rp_InitializationStatus_De_MCU_InitializationStatus (0U)
#  define Rte_InitValue_Rp_ModeManager_NVM_ModeManager_NVM (85U)
#  define Rte_InitValue_Rp_Repetitive_Reset_Status_De_Repetitive_Reset_Status (85U)
#  define Rte_InitValue_Rp_Vbattstate_De_Vbatt_State (0U)
#  define Rte_InitValue_Rp_XCP_ForceRadiate_De_XCPForceRadiate (2U)
# endif

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_ModeManager_Rp_CustDegradation_De_CustDegradation(P2VAR(Dt_CustDegradation, AUTOMATIC, RTE_SWC_PLT_APPL_MODEMANAGER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_ModeManager_Rp_OpModeShutdown_De_OpModeShutdown(P2VAR(Dt_OpModeShutdown, AUTOMATIC, RTE_SWC_PLT_APPL_MODEMANAGER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_ModeManager_Rp_RadarCoreStatus_De_RadarCoreStatus(P2VAR(Dt_RadarCoreStatus, AUTOMATIC, RTE_SWC_PLT_APPL_MODEMANAGER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_ModeManager_Rp_RadarDiagRequest_De_RadarDiagRequest(P2VAR(Dt_RadarDiagRequest, AUTOMATIC, RTE_SWC_PLT_APPL_MODEMANAGER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PLT_Appl_ModeManager_Rp_TR_ModeManager_De_TR_ModeManager(P2VAR(Dt_TR_ModeManager, AUTOMATIC, RTE_SWC_PLT_APPL_MODEMANAGER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

# define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Rp_CustDegradation_De_CustDegradation Rte_Read_SWC_PLT_Appl_ModeManager_Rp_CustDegradation_De_CustDegradation
#  define Rte_Read_Rp_CustForceRadiate_CustForceRadiate Rte_Read_SWC_PLT_Appl_ModeManager_Rp_CustForceRadiate_CustForceRadiate
#  define Rte_Read_SWC_PLT_Appl_ModeManager_Rp_CustForceRadiate_CustForceRadiate(data) (*(data) = 2U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI Rte_Read_SWC_PLT_Appl_ModeManager_Rp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI
#  define Rte_Read_SWC_PLT_Appl_ModeManager_Rp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI(data) (*(data) = Rte_SWC_PLT_Appl_ModeManager_Rp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_InitializationStatus_De_MCU_InitializationStatus Rte_Read_SWC_PLT_Appl_ModeManager_Rp_InitializationStatus_De_MCU_InitializationStatus
#  define Rte_Read_SWC_PLT_Appl_ModeManager_Rp_InitializationStatus_De_MCU_InitializationStatus(data) (*(data) = Rte_SWC_PLT_CDD_MCU_Safety_Pp_PlatformInitializationStatus_De_MCU_InitializationStatus, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_ModeManager_NVM_ModeManager_NVM Rte_Read_SWC_PLT_Appl_ModeManager_Rp_ModeManager_NVM_ModeManager_NVM
#  define Rte_Read_SWC_PLT_Appl_ModeManager_Rp_ModeManager_NVM_ModeManager_NVM(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_OpModeShutdown_De_OpModeShutdown Rte_Read_SWC_PLT_Appl_ModeManager_Rp_OpModeShutdown_De_OpModeShutdown
#  define Rte_Read_Rp_RadarCoreStatus_De_RadarCoreStatus Rte_Read_SWC_PLT_Appl_ModeManager_Rp_RadarCoreStatus_De_RadarCoreStatus
#  define Rte_Read_Rp_RadarDiagRequest_De_RadarDiagRequest Rte_Read_SWC_PLT_Appl_ModeManager_Rp_RadarDiagRequest_De_RadarDiagRequest
#  define Rte_Read_Rp_Repetitive_Reset_Status_De_Repetitive_Reset_Status Rte_Read_SWC_PLT_Appl_ModeManager_Rp_Repetitive_Reset_Status_De_Repetitive_Reset_Status
#  define Rte_Read_SWC_PLT_Appl_ModeManager_Rp_Repetitive_Reset_Status_De_Repetitive_Reset_Status(data) (*(data) = Rte_SWC_PLT_CDD_FailSafe_Pp_Repetitive_Reset_Status_De_Repetitive_Reset_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_TR_ModeManager_De_TR_ModeManager Rte_Read_SWC_PLT_Appl_ModeManager_Rp_TR_ModeManager_De_TR_ModeManager
#  define Rte_Read_Rp_Vbattstate_De_Vbatt_State Rte_Read_SWC_PLT_Appl_ModeManager_Rp_Vbattstate_De_Vbatt_State
#  define Rte_Read_SWC_PLT_Appl_ModeManager_Rp_Vbattstate_De_Vbatt_State(data) (*(data) = Rte_SWC_PLT_Appl_IoHwAb_Pp_Vbatt_State_De_Vbatt_State, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_XCP_ForceRadiate_De_XCPForceRadiate Rte_Read_SWC_PLT_Appl_ModeManager_Rp_XCP_ForceRadiate_De_XCPForceRadiate
#  define Rte_Read_SWC_PLT_Appl_ModeManager_Rp_XCP_ForceRadiate_De_XCPForceRadiate(data) (*(data) = Rte_SWC_PLT_CDD_XCP_Pp_XCP_ForceRadiate_De_XCPForceRadiate, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Pp_CommandRadiate_Final_De_CommandRadiate_Final Rte_Write_SWC_PLT_Appl_ModeManager_Pp_CommandRadiate_Final_De_CommandRadiate_Final
#  define Rte_Write_SWC_PLT_Appl_ModeManager_Pp_CommandRadiate_Final_De_CommandRadiate_Final(data) (Rte_SWC_PLT_Appl_ModeManager_Pp_CommandRadiate_Final_De_CommandRadiate_Final = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_IsRadiateForced_De_IsRadiateForced Rte_Write_SWC_PLT_Appl_ModeManager_Pp_IsRadiateForced_De_IsRadiateForced
#  define Rte_Write_SWC_PLT_Appl_ModeManager_Pp_IsRadiateForced_De_IsRadiateForced(data) (Rte_SWC_PLT_Appl_ModeManager_Pp_IsRadiateForced_De_IsRadiateForced = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_OperationMode_System_De_OperationMode_System Rte_Write_SWC_PLT_Appl_ModeManager_Pp_OperationMode_System_De_OperationMode_System
#  define Rte_Write_SWC_PLT_Appl_ModeManager_Pp_OperationMode_System_De_OperationMode_System(data) (Rte_SWC_PLT_Appl_ModeManager_Pp_OperationMode_System_De_OperationMode_System = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_ShutdownTask_De_shutdownTask Rte_Write_SWC_PLT_Appl_ModeManager_Pp_ShutdownTask_De_shutdownTask
#  define Rte_Write_SWC_PLT_Appl_ModeManager_Pp_ShutdownTask_De_shutdownTask(data) (RTE_E_OK)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define SWC_PLT_CDD_MCU_Safety_START_SEC_CODE
#  include "SWC_PLT_CDD_MCU_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_CDD_MCU_Safety_CODE) ECU_Soft_Reset(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_CDD_MCU_Safety_STOP_SEC_CODE
#  include "SWC_PLT_CDD_MCU_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_Rp_ECU_Reset_ECU_Soft_Reset() (ECU_Soft_Reset(), ((Std_ReturnType)RTE_E_OK))

# endif /* !defined(RTE_CORE) */


# define SWC_PLT_Appl_ModeManager_START_SEC_CODE
# include "SWC_PLT_Appl_ModeManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CS_Modemanager_Fault_Injection_Read CS_Modemanager_Fault_Injection_Read
#  define RTE_RUNNABLE_RE_PLT_Mode_Manager_Init RE_PLT_Mode_Manager_Init
#  define RTE_RUNNABLE_RE_PLT_Mode_Manager_Main_50ms RE_PLT_Mode_Manager_Main_50ms
#  define RTE_RUNNABLE_RE_PLT_Mode_Manager_StateMachine_5ms RE_PLT_Mode_Manager_StateMachine_5ms
# endif

FUNC(void, SWC_PLT_Appl_ModeManager_CODE) CS_Modemanager_Fault_Injection_Read(uint8 Injection_Control, uint8 Failure_Type); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_Appl_ModeManager_CODE) RE_PLT_Mode_Manager_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_ModeManager_CODE) RE_PLT_Mode_Manager_Main_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_ModeManager_CODE) RE_PLT_Mode_Manager_StateMachine_5ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_PLT_Appl_ModeManager_STOP_SEC_CODE
# include "SWC_PLT_Appl_ModeManager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PLT_APPL_MODEMANAGER_H */

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
