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
 *             File:  Rte_SWC_PLT_CDD_WdgHandler.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <SWC_PLT_CDD_WdgHandler>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PLT_CDD_WDGHANDLER_H
# define RTE_SWC_PLT_CDD_WDGHANDLER_H

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

# include "Rte_SWC_PLT_CDD_WdgHandler_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_WdgHandler_Pp_Internal_Wdg_Fail_Status_Internal_Wdg_Fail_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_WdgHandler_Pp_Wdg_Fault_Injection_Request_ExtWdg_De_Wdg_Fault_Injection_Request;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_WdgHandler_Pp_Wdg_Fault_Injection_Request_IntWdg_De_Wdg_Fault_Injection_Request;

#  define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Pp_Internal_Wdg_Fail_Status_Internal_Wdg_Fail_Status (0U)
#  define Rte_InitValue_Pp_Wdg_Fault_Injection_Request_IntWdg_De_Wdg_Fault_Injection_Request (0U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Pp_Internal_Wdg_Fail_Status_Internal_Wdg_Fail_Status Rte_Write_SWC_PLT_CDD_WdgHandler_Pp_Internal_Wdg_Fail_Status_Internal_Wdg_Fail_Status
#  define Rte_Write_SWC_PLT_CDD_WdgHandler_Pp_Internal_Wdg_Fail_Status_Internal_Wdg_Fail_Status(data) (Rte_SWC_PLT_CDD_WdgHandler_Pp_Internal_Wdg_Fail_Status_Internal_Wdg_Fail_Status = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_Wdg_Fault_Injection_Request_ExtWdg_De_Wdg_Fault_Injection_Request Rte_Write_SWC_PLT_CDD_WdgHandler_Pp_Wdg_Fault_Injection_Request_ExtWdg_De_Wdg_Fault_Injection_Request
#  define Rte_Write_SWC_PLT_CDD_WdgHandler_Pp_Wdg_Fault_Injection_Request_ExtWdg_De_Wdg_Fault_Injection_Request(data) (Rte_SWC_PLT_CDD_WdgHandler_Pp_Wdg_Fault_Injection_Request_ExtWdg_De_Wdg_Fault_Injection_Request = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_Wdg_Fault_Injection_Request_IntWdg_De_Wdg_Fault_Injection_Request Rte_Write_SWC_PLT_CDD_WdgHandler_Pp_Wdg_Fault_Injection_Request_IntWdg_De_Wdg_Fault_Injection_Request
#  define Rte_Write_SWC_PLT_CDD_WdgHandler_Pp_Wdg_Fault_Injection_Request_IntWdg_De_Wdg_Fault_Injection_Request(data) (Rte_SWC_PLT_CDD_WdgHandler_Pp_Wdg_Fault_Injection_Request_IntWdg_De_Wdg_Fault_Injection_Request = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define WdgM_OsCore0_ASIL_START_SEC_CODE
#  include "WdgM_OsCore0_ASIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, WdgM_OsCore0_ASIL_CODE) WdgM_SetMode(WdgM_ModeType Mode, uint16 CallerID); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define WdgM_OsCore0_ASIL_STOP_SEC_CODE
#  include "WdgM_OsCore0_ASIL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CS_WdgM_General_SetMode WdgM_SetMode

# endif /* !defined(RTE_CORE) */


# define SWC_PLT_CDD_WdgHandler_START_SEC_CODE
# include "SWC_PLT_CDD_WdgHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CS_WdgHandler_Fault_Injection_Read CS_WdgHandler_Fault_Injection_Read
#  define RTE_RUNNABLE_CS_Wdg_Disable CS_Wdg_Disable
#  define RTE_RUNNABLE_RE_PLT_WdgHandler_Init RE_PLT_WdgHandler_Init
# endif

FUNC(void, SWC_PLT_CDD_WdgHandler_CODE) CS_WdgHandler_Fault_Injection_Read(uint8 Injection_control, uint8 Failure_Type); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_CDD_WdgHandler_CODE) CS_Wdg_Disable(Dt_Wdg_Type Wdg_Type); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_CDD_WdgHandler_CODE) RE_PLT_WdgHandler_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_PLT_CDD_WdgHandler_STOP_SEC_CODE
# include "SWC_PLT_CDD_WdgHandler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_WdgM_General_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PLT_CDD_WDGHANDLER_H */

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
