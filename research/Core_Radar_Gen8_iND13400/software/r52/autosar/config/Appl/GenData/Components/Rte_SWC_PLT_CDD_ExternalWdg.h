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
 *             File:  Rte_SWC_PLT_CDD_ExternalWdg.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <SWC_PLT_CDD_ExternalWdg>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PLT_CDD_EXTERNALWDG_H
# define RTE_SWC_PLT_CDD_EXTERNALWDG_H

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

# include "Rte_SWC_PLT_CDD_ExternalWdg_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_ExternalWdg_Pp_Pmic_Mcu_Com_Fault_De_Pmic_Mcu_Com_Fault;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_ExternalWdg_Pp_external_watchdog_init_status_de_wdginit_status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_ExternalWdg_Pp_externalwatchdogstatus_de_externalwatchdogstatus;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_WdgHandler_Pp_Internal_Wdg_Fail_Status_Internal_Wdg_Fail_Status;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_WdgHandler_Pp_Wdg_Fault_Injection_Request_ExtWdg_De_Wdg_Fault_Injection_Request;

#  define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Pp_Pmic_Mcu_Com_Fault_De_Pmic_Mcu_Com_Fault (0U)
#  define Rte_InitValue_Pp_external_watchdog_init_status_de_wdginit_status (0U)
#  define Rte_InitValue_Pp_externalwatchdogstatus_de_externalwatchdogstatus (0U)
#  define Rte_InitValue_Rp_Internal_Wdg_Fail_Status_Internal_Wdg_Fail_Status (0U)
#  define Rte_InitValue_Rp_Wdg_Fault_Injection_Request_ExtWdg_De_Wdg_Fault_Injection_Request (0U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Rp_Internal_Wdg_Fail_Status_Internal_Wdg_Fail_Status Rte_Read_SWC_PLT_CDD_ExternalWdg_Rp_Internal_Wdg_Fail_Status_Internal_Wdg_Fail_Status
#  define Rte_Read_SWC_PLT_CDD_ExternalWdg_Rp_Internal_Wdg_Fail_Status_Internal_Wdg_Fail_Status(data) (*(data) = Rte_SWC_PLT_CDD_WdgHandler_Pp_Internal_Wdg_Fail_Status_Internal_Wdg_Fail_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_Wdg_Fault_Injection_Request_ExtWdg_De_Wdg_Fault_Injection_Request Rte_Read_SWC_PLT_CDD_ExternalWdg_Rp_Wdg_Fault_Injection_Request_ExtWdg_De_Wdg_Fault_Injection_Request
#  define Rte_Read_SWC_PLT_CDD_ExternalWdg_Rp_Wdg_Fault_Injection_Request_ExtWdg_De_Wdg_Fault_Injection_Request(data) (*(data) = Rte_SWC_PLT_CDD_WdgHandler_Pp_Wdg_Fault_Injection_Request_ExtWdg_De_Wdg_Fault_Injection_Request, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Pp_Pmic_Mcu_Com_Fault_De_Pmic_Mcu_Com_Fault Rte_Write_SWC_PLT_CDD_ExternalWdg_Pp_Pmic_Mcu_Com_Fault_De_Pmic_Mcu_Com_Fault
#  define Rte_Write_SWC_PLT_CDD_ExternalWdg_Pp_Pmic_Mcu_Com_Fault_De_Pmic_Mcu_Com_Fault(data) (Rte_SWC_PLT_CDD_ExternalWdg_Pp_Pmic_Mcu_Com_Fault_De_Pmic_Mcu_Com_Fault = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_external_watchdog_init_status_de_wdginit_status Rte_Write_SWC_PLT_CDD_ExternalWdg_Pp_external_watchdog_init_status_de_wdginit_status
#  define Rte_Write_SWC_PLT_CDD_ExternalWdg_Pp_external_watchdog_init_status_de_wdginit_status(data) (Rte_SWC_PLT_CDD_ExternalWdg_Pp_external_watchdog_init_status_de_wdginit_status = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_externalwatchdogstatus_de_externalwatchdogstatus Rte_Write_SWC_PLT_CDD_ExternalWdg_Pp_externalwatchdogstatus_de_externalwatchdogstatus
#  define Rte_Write_SWC_PLT_CDD_ExternalWdg_Pp_externalwatchdogstatus_de_externalwatchdogstatus(data) (Rte_SWC_PLT_CDD_ExternalWdg_Pp_externalwatchdogstatus_de_externalwatchdogstatus = (data), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define SWC_PLT_CDD_ExternalWdg_START_SEC_CODE
# include "SWC_PLT_CDD_ExternalWdg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CS_External_Watchdog_Fault_Injection_Read CS_External_Watchdog_Fault_Injection_Read
#  define RTE_RUNNABLE_CS_Pp_ExtWdg_Disable_Operation CS_Pp_ExtWdg_Disable_Operation
#  define RTE_RUNNABLE_CS_Pp_ExtWdg_Enable_Operation CS_Pp_ExtWdg_Enable_Operation
#  define RTE_RUNNABLE_RE_CDD_Ext_Wdg_50ms RE_CDD_Ext_Wdg_50ms
#  define RTE_RUNNABLE_RE_CDD_Ext_Wdg_5ms RE_CDD_Ext_Wdg_5ms
#  define RTE_RUNNABLE_RE_PLT_ExternalWdg_Init RE_PLT_ExternalWdg_Init
# endif

FUNC(void, SWC_PLT_CDD_ExternalWdg_CODE) CS_External_Watchdog_Fault_Injection_Read(uint8 Injection_control, uint8 Failure_Type); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_CDD_ExternalWdg_CODE) CS_Pp_ExtWdg_Disable_Operation(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_CDD_ExternalWdg_CODE) CS_Pp_ExtWdg_Enable_Operation(void); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_CDD_ExternalWdg_CODE) RE_CDD_Ext_Wdg_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_CDD_ExternalWdg_CODE) RE_CDD_Ext_Wdg_5ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_CDD_ExternalWdg_CODE) RE_PLT_ExternalWdg_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_PLT_CDD_ExternalWdg_STOP_SEC_CODE
# include "SWC_PLT_CDD_ExternalWdg_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PLT_CDD_EXTERNALWDG_H */

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
