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
 *             File:  Rte_SWC_Appl_Project.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <SWC_Appl_Project>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_APPL_PROJECT_H
# define RTE_SWC_APPL_PROJECT_H

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

# include "Rte_SWC_Appl_Project_Type.h"
# include "Rte_DataHandleType.h"

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

# define RTE_EcucPartition_Core0_ASIL_START_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_Appl_Project_Rp_XCP_Set_Output_State_De_XCP_Set_Output(P2VAR(Dt_XCP_Set_Output, AUTOMATIC, RTE_SWC_APPL_PROJECT_APPL_VAR) data); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

# define RTE_EcucPartition_Core0_ASIL_STOP_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Rp_Time_Stamp_De_StbM_TimeStampType Rte_Read_SWC_Appl_Project_Rp_Time_Stamp_De_StbM_TimeStampType
#  define Rte_Read_SWC_Appl_Project_Rp_Time_Stamp_De_StbM_TimeStampType(data) (*(data) = Rte_C_StbM_TimeStampType_1B1E9F570D8098D4CEDA8C1F0C53F421, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_Rp_XCP_Set_Output_State_De_XCP_Set_Output Rte_Read_SWC_Appl_Project_Rp_XCP_Set_Output_State_De_XCP_Set_Output


# endif /* !defined(RTE_CORE) */


# define SWC_Appl_Project_START_SEC_CODE
# include "SWC_Appl_Project_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CS_Signal_Integrity_Fault_Injection_Read CS_Signal_Integrity_Fault_Injection_Read
#  define RTE_RUNNABLE_RE_Appl_Project_Main_50ms RE_Appl_Project_Main_50ms
# endif

FUNC(void, SWC_Appl_Project_CODE) CS_Signal_Integrity_Fault_Injection_Read(uint8 Injection_Control, uint8 Failure_Type); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_Appl_Project_CODE) RE_Appl_Project_Main_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_Appl_Project_STOP_SEC_CODE
# include "SWC_Appl_Project_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_APPL_PROJECT_H */

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
