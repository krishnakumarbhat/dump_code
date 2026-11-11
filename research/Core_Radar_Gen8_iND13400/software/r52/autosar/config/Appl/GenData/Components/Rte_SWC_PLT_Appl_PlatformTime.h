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
 *             File:  Rte_SWC_PLT_Appl_PlatformTime.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application header file for SW-C <SWC_PLT_Appl_PlatformTime>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PLT_APPL_PLATFORMTIME_H
# define RTE_SWC_PLT_APPL_PLATFORMTIME_H

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

# include "Rte_SWC_PLT_Appl_PlatformTime_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_EcucPartition_Core0_ASIL_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_Appl_PlatformTime_Pp_TR_platform_Time_De_PlatformTime;

#  define RTE_EcucPartition_Core0_ASIL_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Pp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI (0U)
#  define Rte_InitValue_Pp_TR_platform_Time_De_PlatformTime (85U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Pp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI Rte_Write_SWC_PLT_Appl_PlatformTime_Pp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI
#  define Rte_Write_SWC_PLT_Appl_PlatformTime_Pp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI(data) (RTE_E_OK)
#  define Rte_Write_Pp_TR_platform_Time_De_PlatformTime Rte_Write_SWC_PLT_Appl_PlatformTime_Pp_TR_platform_Time_De_PlatformTime
#  define Rte_Write_SWC_PLT_Appl_PlatformTime_Pp_TR_platform_Time_De_PlatformTime(data) (Rte_SWC_PLT_Appl_PlatformTime_Pp_TR_platform_Time_De_PlatformTime = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define SWC_PLT_Appl_IoHwAb_START_SEC_CODE
#  include "SWC_PLT_Appl_IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SWC_PLT_Appl_IoHwAb_CODE) CS_Platform_register_set(uint8 fault_type); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */

#  define SWC_PLT_Appl_IoHwAb_STOP_SEC_CODE
#  include "SWC_PLT_Appl_IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CS_Platform_register_set_fault_type(arg1) (CS_Platform_register_set(arg1), ((Std_ReturnType)RTE_E_OK))

/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_PlatformTime_ExclusiveArea() SuspendAllInterrupts() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

#  define Rte_Exit_PlatformTime_ExclusiveArea() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */


# endif /* !defined(RTE_CORE) */


# define SWC_PLT_Appl_PlatformTime_START_SEC_CODE
# include "SWC_PLT_Appl_PlatformTime_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CS_Get_Platform_Elapsed_ustime_read CS_Get_Platform_Elapsed_ustime_read
#  define RTE_RUNNABLE_CS_PlatformTime_Fault_Injection CS_PlatformTime_Fault_Injection
#  define RTE_RUNNABLE_Get_PlatformTime_ms_read Get_PlatformTime_ms_read
#  define RTE_RUNNABLE_Get_PlatfromTime_us_read Get_PlatfromTime_us_read
#  define RTE_RUNNABLE_RE_Evaluate_Plt_Time_Init RE_Evaluate_Plt_Time_Init
#  define RTE_RUNNABLE_RE_PLT_PlatformTime_50ms RE_PLT_PlatformTime_50ms
#  define RTE_RUNNABLE_RE_PLT_PlatformTime_Init RE_PLT_PlatformTime_Init
# endif

FUNC(void, SWC_PLT_Appl_PlatformTime_CODE) CS_Get_Platform_Elapsed_ustime_read(P2VAR(uint32, AUTOMATIC, RTE_SWC_PLT_APPL_PLATFORMTIME_APPL_VAR) inst_us_time, uint64 start_time); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_Appl_PlatformTime_CODE) CS_PlatformTime_Fault_Injection(uint8 Injection_control, uint8 Failure_Type); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_Appl_PlatformTime_CODE) Get_PlatformTime_ms_read(P2VAR(uint32, AUTOMATIC, RTE_SWC_PLT_APPL_PLATFORMTIME_APPL_VAR) instant_mstime); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_Appl_PlatformTime_CODE) Get_PlatfromTime_us_read(P2VAR(uint64, AUTOMATIC, RTE_SWC_PLT_APPL_PLATFORMTIME_APPL_VAR) instant_ustime); /* PRQA S 0786, 3449, 3451, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_3451, MD_Rte_0624 */
FUNC(void, SWC_PLT_Appl_PlatformTime_CODE) RE_Evaluate_Plt_Time_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_PlatformTime_CODE) RE_PLT_PlatformTime_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_Appl_PlatformTime_CODE) RE_PLT_PlatformTime_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_PLT_Appl_PlatformTime_STOP_SEC_CODE
# include "SWC_PLT_Appl_PlatformTime_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PLT_APPL_PLATFORMTIME_H */

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
