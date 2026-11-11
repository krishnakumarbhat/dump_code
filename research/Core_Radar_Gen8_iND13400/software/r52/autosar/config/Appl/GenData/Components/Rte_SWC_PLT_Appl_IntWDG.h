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
 *             File:  Rte_SWC_PLT_Appl_IntWDG.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <SWC_PLT_Appl_IntWDG>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PLT_APPL_INTWDG_H
# define RTE_SWC_PLT_APPL_INTWDG_H

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

# include "Rte_SWC_PLT_Appl_IntWDG_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_WdgHandler_Pp_Wdg_Fault_Injection_Request_IntWdg_De_Wdg_Fault_Injection_Request;

#  define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Rp_Wdg_Fault_Injection_Request_IntWdg_De_Wdg_Fault_Injection_Request (0U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Rp_Wdg_Fault_Injection_Request_IntWdg_De_Wdg_Fault_Injection_Request Rte_Read_SWC_PLT_Appl_IntWDG_Rp_Wdg_Fault_Injection_Request_IntWdg_De_Wdg_Fault_Injection_Request
#  define Rte_Read_SWC_PLT_Appl_IntWDG_Rp_Wdg_Fault_Injection_Request_IntWdg_De_Wdg_Fault_Injection_Request(data) (*(data) = Rte_SWC_PLT_CDD_WdgHandler_Pp_Wdg_Fault_Injection_Request_IntWdg_De_Wdg_Fault_Injection_Request, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define SWC_PLT_CDD_WdgHandler_START_SEC_CODE
#  include "SWC_PLT_CDD_WdgHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_CDD_WdgHandler_CODE) CS_Wdg_Disable(Dt_Wdg_Type Wdg_Type); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_CDD_WdgHandler_STOP_SEC_CODE
#  include "SWC_PLT_CDD_WdgHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define WdgM_OsCore0_ASIL_START_SEC_CODE
#  include "WdgM_OsCore0_ASIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, WdgM_OsCore0_ASIL_CODE) WdgM_CheckpointReached(WdgM_SupervisedEntityIdType parg0, WdgM_CheckpointIdType CPID); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define WdgM_OsCore0_ASIL_STOP_SEC_CODE
#  include "WdgM_OsCore0_ASIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define WdgM_OsCore0_ASIL_START_SEC_CODE
#  include "WdgM_OsCore0_ASIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, WdgM_OsCore0_ASIL_CODE) WdgM_ActivateSupervisionEntity(WdgM_SupervisedEntityIdType SEID); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define WdgM_OsCore0_ASIL_STOP_SEC_CODE
#  include "WdgM_OsCore0_ASIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define WdgM_OsCore0_ASIL_START_SEC_CODE
#  include "WdgM_OsCore0_ASIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, WdgM_OsCore0_ASIL_CODE) WdgM_DeactivateSupervisionEntity(WdgM_SupervisedEntityIdType SEID); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define WdgM_OsCore0_ASIL_STOP_SEC_CODE
#  include "WdgM_OsCore0_ASIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define WdgM_OsCore0_ASIL_START_SEC_CODE
#  include "WdgM_OsCore0_ASIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, WdgM_OsCore0_ASIL_CODE) WdgM_GetFirstExpiredSEID(P2VAR(WdgM_SupervisedEntityIdType, AUTOMATIC, RTE_WDGM_OSCORE0_ASIL_APPL_VAR) SEID); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define WdgM_OsCore0_ASIL_STOP_SEC_CODE
#  include "WdgM_OsCore0_ASIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define WdgM_OsCore0_ASIL_START_SEC_CODE
#  include "WdgM_OsCore0_ASIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, WdgM_OsCore0_ASIL_CODE) WdgM_GetGlobalStatus(P2VAR(WdgM_GlobalStatusType, AUTOMATIC, RTE_WDGM_OSCORE0_ASIL_APPL_VAR) Status); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define WdgM_OsCore0_ASIL_STOP_SEC_CODE
#  include "WdgM_OsCore0_ASIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define WdgM_OsCore0_ASIL_START_SEC_CODE
#  include "WdgM_OsCore0_ASIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, WdgM_OsCore0_ASIL_CODE) WdgM_GetLocalStatus(WdgM_SupervisedEntityIdType SEID, P2VAR(WdgM_LocalStatusType, AUTOMATIC, RTE_WDGM_OSCORE0_ASIL_APPL_VAR) Status); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define WdgM_OsCore0_ASIL_STOP_SEC_CODE
#  include "WdgM_OsCore0_ASIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define WdgM_OsCore0_ASIL_START_SEC_CODE
#  include "WdgM_OsCore0_ASIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, WdgM_OsCore0_ASIL_CODE) WdgM_GetMode(P2VAR(WdgM_ModeType, AUTOMATIC, RTE_WDGM_OSCORE0_ASIL_APPL_VAR) Mode); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define WdgM_OsCore0_ASIL_STOP_SEC_CODE
#  include "WdgM_OsCore0_ASIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define WdgM_OsCore0_ASIL_START_SEC_CODE
#  include "WdgM_OsCore0_ASIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, WdgM_OsCore0_ASIL_CODE) WdgM_PerformReset(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define WdgM_OsCore0_ASIL_STOP_SEC_CODE
#  include "WdgM_OsCore0_ASIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define WdgM_OsCore0_ASIL_START_SEC_CODE
#  include "WdgM_OsCore0_ASIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, WdgM_OsCore0_ASIL_CODE) WdgM_SetMode(WdgM_ModeType Mode, uint16 CallerID); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define WdgM_OsCore0_ASIL_STOP_SEC_CODE
#  include "WdgM_OsCore0_ASIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_CheckpointReached(arg1) (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)1, arg1))
#  define Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_Appl_IPC_Task_CheckpointReached(arg1) (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)3, arg1))
#  define Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_Appl_Task_Communication_CheckpointReached(arg1) (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)5, arg1))
#  define Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_Appl_Task_Radar_Control_CheckpointReached(arg1) (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)6, arg1))
#  define Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_BSW_Task_CheckpointReached(arg1) (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)7, arg1))
#  define Rte_Call_CS_WdgM_AliveSupervision_Internal_Wdg_PLT_Appl_Task_CheckpointReached(arg1) (WdgM_CheckpointReached((WdgM_SupervisedEntityIdType)4, arg1))
#  define Rte_Call_CS_WdgM_General_ActivateSupervisionEntity WdgM_ActivateSupervisionEntity
#  define Rte_Call_CS_WdgM_General_DeactivateSupervisionEntity WdgM_DeactivateSupervisionEntity
#  define Rte_Call_CS_WdgM_General_GetFirstExpiredSEID WdgM_GetFirstExpiredSEID
#  define Rte_Call_CS_WdgM_General_GetGlobalStatus WdgM_GetGlobalStatus
#  define Rte_Call_CS_WdgM_General_GetLocalStatus WdgM_GetLocalStatus
#  define Rte_Call_CS_WdgM_General_GetMode WdgM_GetMode
#  define Rte_Call_CS_WdgM_General_PerformReset WdgM_PerformReset
#  define Rte_Call_CS_WdgM_General_SetMode WdgM_SetMode
#  define Rte_Call_CS_Wdg_Disable_Read(arg1) (CS_Wdg_Disable(arg1), ((Std_ReturnType)RTE_E_OK))

# endif /* !defined(RTE_CORE) */


# define SWC_PLT_Appl_IntWDG_START_SEC_CODE
# include "SWC_PLT_Appl_IntWDG_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CS_Disable_Wdg_Supervised_Entites_Operation CS_Disable_Wdg_Supervised_Entites_Operation
#  define RTE_RUNNABLE_RE_PLT_WDG_INTERNAL_WDG_Appl_IPC_Task RE_PLT_WDG_INTERNAL_WDG_Appl_IPC_Task
#  define RTE_RUNNABLE_RE_PLT_WDG_INTERNAL_WDG_Appl_Task_Communication RE_PLT_WDG_INTERNAL_WDG_Appl_Task_Communication
#  define RTE_RUNNABLE_RE_PLT_WDG_INTERNAL_WDG_Appl_Task_Radar_Control RE_PLT_WDG_INTERNAL_WDG_Appl_Task_Radar_Control
#  define RTE_RUNNABLE_RE_PLT_WDG_INTERNAL_WDG_BSW_Task RE_PLT_WDG_INTERNAL_WDG_BSW_Task
#  define RTE_RUNNABLE_RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task
#  define RTE_RUNNABLE_RE_PLT_WDG_Main_50ms RE_PLT_WDG_Main_50ms
#  define RTE_RUNNABLE_RE_PLT_WDG_Main_5ms RE_PLT_WDG_Main_5ms
#  define RTE_RUNNABLE_RE_PLT_Wdg_Init RE_PLT_Wdg_Init
# endif

FUNC(void, SWC_PLT_Appl_IntWDG_CODE) CS_Disable_Wdg_Supervised_Entites_Operation(uint8 disable_SE_Flag); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_Appl_IntWDG_CODE) RE_PLT_WDG_INTERNAL_WDG_Appl_IPC_Task(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_IntWDG_CODE) RE_PLT_WDG_INTERNAL_WDG_Appl_Task_Communication(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_IntWDG_CODE) RE_PLT_WDG_INTERNAL_WDG_Appl_Task_Radar_Control(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_IntWDG_CODE) RE_PLT_WDG_INTERNAL_WDG_BSW_Task(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_IntWDG_CODE) RE_PLT_WDG_INTERNAL_WDG_PLT_Appl_Task(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_IntWDG_CODE) RE_PLT_WDG_Main_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_IntWDG_CODE) RE_PLT_WDG_Main_5ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_IntWDG_CODE) RE_PLT_Wdg_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_PLT_Appl_IntWDG_STOP_SEC_CODE
# include "SWC_PLT_Appl_IntWDG_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_WdgM_AliveSupervision_E_NOT_OK (1U)

#  define RTE_E_WdgM_General_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PLT_APPL_INTWDG_H */

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
