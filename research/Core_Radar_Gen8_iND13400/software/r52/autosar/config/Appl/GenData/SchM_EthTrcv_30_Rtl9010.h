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
 *             File:  SchM_EthTrcv_30_Rtl9010.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Header of BSW Scheduler for BSW Module <EthTrcv_30_Rtl9010>
 *********************************************************************************************************************/
#ifndef SCHM_ETHTRCV_30_RTL9010_H
# define SCHM_ETHTRCV_30_RTL9010_H

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "SchM_EthTrcv_30_Rtl9010_Type.h"

# include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_Dir1.1, MD_Rte_Os */

# define ETHTRCV_30_RTL9010_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, ETHTRCV_30_RTL9010_CODE) EthTrcv_30_Rtl9010_MainFunction(void); /* PRQA S 3451, 3449 */ /* MD_Rte_3451, MD_Rte_3449 */

# define ETHTRCV_30_RTL9010_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define SchM_Enter_EthTrcv_30_Rtl9010_ETHTRCV_30_RTL9010_EXCLUSIVE_AREA_AUTONEG() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Exit_EthTrcv_30_Rtl9010_ETHTRCV_30_RTL9010_EXCLUSIVE_AREA_AUTONEG() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Enter_EthTrcv_30_Rtl9010_ETHTRCV_30_RTL9010_EXCLUSIVE_AREA_CL45() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Exit_EthTrcv_30_Rtl9010_ETHTRCV_30_RTL9010_EXCLUSIVE_AREA_CL45() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Enter_EthTrcv_30_Rtl9010_ETHTRCV_30_RTL9010_EXCLUSIVE_AREA_DIAGNOSTICS() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Exit_EthTrcv_30_Rtl9010_ETHTRCV_30_RTL9010_EXCLUSIVE_AREA_DIAGNOSTICS() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Enter_EthTrcv_30_Rtl9010_ETHTRCV_30_RTL9010_EXCLUSIVE_AREA_HWINIT() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Exit_EthTrcv_30_Rtl9010_ETHTRCV_30_RTL9010_EXCLUSIVE_AREA_HWINIT() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Enter_EthTrcv_30_Rtl9010_ETHTRCV_30_RTL9010_EXCLUSIVE_AREA_LINK() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Exit_EthTrcv_30_Rtl9010_ETHTRCV_30_RTL9010_EXCLUSIVE_AREA_LINK() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Enter_EthTrcv_30_Rtl9010_ETHTRCV_30_RTL9010_EXCLUSIVE_AREA_MACSEC() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Exit_EthTrcv_30_Rtl9010_ETHTRCV_30_RTL9010_EXCLUSIVE_AREA_MACSEC() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Enter_EthTrcv_30_Rtl9010_ETHTRCV_30_RTL9010_EXCLUSIVE_AREA_MACSEC32() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Exit_EthTrcv_30_Rtl9010_ETHTRCV_30_RTL9010_EXCLUSIVE_AREA_MACSEC32() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Enter_EthTrcv_30_Rtl9010_ETHTRCV_30_RTL9010_EXCLUSIVE_AREA_MACSEC64() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Exit_EthTrcv_30_Rtl9010_ETHTRCV_30_RTL9010_EXCLUSIVE_AREA_MACSEC64() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Enter_EthTrcv_30_Rtl9010_ETHTRCV_30_RTL9010_EXCLUSIVE_AREA_MODE() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Exit_EthTrcv_30_Rtl9010_ETHTRCV_30_RTL9010_EXCLUSIVE_AREA_MODE() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Enter_EthTrcv_30_Rtl9010_ETHTRCV_30_RTL9010_EXCLUSIVE_AREA_WAKEUP() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Exit_EthTrcv_30_Rtl9010_ETHTRCV_30_RTL9010_EXCLUSIVE_AREA_WAKEUP() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */


# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

#endif /* SCHM_ETHTRCV_30_RTL9010_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
