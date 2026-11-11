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
 *             File:  Rte_SWC_PRJ_Appl_Power_Manager.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <SWC_PRJ_Appl_Power_Manager>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PRJ_APPL_POWER_MANAGER_H
# define RTE_SWC_PRJ_APPL_POWER_MANAGER_H

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

# include "Rte_SWC_PRJ_Appl_Power_Manager_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(BswM_ESH_RunRequest, RTE_VAR_INIT) Rte_SWC_PRJ_Appl_Power_Manager_Request_ESH_PostRunRequest_0_requestedMode;
extern VAR(Dt_SystemOperationMode, RTE_VAR_INIT) Rte_SWC_PLT_Appl_ModeManager_Pp_OperationMode_System_De_OperationMode_System;

#  define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Rp_OperationMode_System_De_OperationMode_System (0U)
# endif

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PRJ_Appl_Power_Manager_Rp_PhysicalAdcData_De_PhysicalAdcData(P2VAR(Dt_AdcData_T, AUTOMATIC, RTE_SWC_PRJ_APPL_POWER_MANAGER_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PRJ_Appl_Power_Manager_Pp_CustDegradation_De_CustDegradation(P2CONST(Dt_CustDegradation, AUTOMATIC, RTE_SWC_PRJ_APPL_POWER_MANAGER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_PRJ_Appl_Power_Manager_Pp_OpModeShutdown_De_OpModeShutdown(P2CONST(Dt_OpModeShutdown, AUTOMATIC, RTE_SWC_PRJ_APPL_POWER_MANAGER_APPL_DATA) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

# define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Rp_OperationMode_System_De_OperationMode_System Rte_Read_SWC_PRJ_Appl_Power_Manager_Rp_OperationMode_System_De_OperationMode_System
#  define Rte_Read_SWC_PRJ_Appl_Power_Manager_Rp_OperationMode_System_De_OperationMode_System(data) (*(data) = Rte_SWC_PLT_Appl_ModeManager_Pp_OperationMode_System_De_OperationMode_System, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_PhysicalAdcData_De_PhysicalAdcData Rte_Read_SWC_PRJ_Appl_Power_Manager_Rp_PhysicalAdcData_De_PhysicalAdcData


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Pp_CustDegradation_De_CustDegradation Rte_Write_SWC_PRJ_Appl_Power_Manager_Pp_CustDegradation_De_CustDegradation
#  define Rte_Write_Pp_OpModeShutdown_De_OpModeShutdown Rte_Write_SWC_PRJ_Appl_Power_Manager_Pp_OpModeShutdown_De_OpModeShutdown
#  define Rte_Write_Request_ESH_PostRunRequest_0_requestedMode Rte_Write_SWC_PRJ_Appl_Power_Manager_Request_ESH_PostRunRequest_0_requestedMode
#  define Rte_Write_SWC_PRJ_Appl_Power_Manager_Request_ESH_PostRunRequest_0_requestedMode(data) (Rte_SWC_PRJ_Appl_Power_Manager_Request_ESH_PostRunRequest_0_requestedMode = (data), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define SWC_PRJ_Appl_Power_Manager_START_SEC_CODE
# include "SWC_PRJ_Appl_Power_Manager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_RE_Power_Manager_5ms RE_Power_Manager_5ms
#  define RTE_RUNNABLE_RE_Power_Manager_Init RE_Power_Manager_Init
# endif

FUNC(void, SWC_PRJ_Appl_Power_Manager_CODE) RE_Power_Manager_5ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PRJ_Appl_Power_Manager_CODE) RE_Power_Manager_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_PRJ_Appl_Power_Manager_STOP_SEC_CODE
# include "SWC_PRJ_Appl_Power_Manager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PRJ_APPL_POWER_MANAGER_H */

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
