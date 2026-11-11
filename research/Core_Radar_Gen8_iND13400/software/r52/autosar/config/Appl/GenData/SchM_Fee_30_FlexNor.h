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
 *             File:  SchM_Fee_30_FlexNor.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Header of BSW Scheduler for BSW Module <Fee_30_FlexNor>
 *********************************************************************************************************************/
#ifndef SCHM_FEE_30_FLEXNOR_H
# define SCHM_FEE_30_FLEXNOR_H

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "SchM_Fee_30_FlexNor_Type.h"

# define FEE_30_FLEXNOR_START_SEC_CODE
# include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, FEE_30_FLEXNOR_CODE) Fee_30_FlexNor_MainFunction(void); /* PRQA S 3451, 3449 */ /* MD_Rte_3451, MD_Rte_3449 */

# define FEE_30_FLEXNOR_STOP_SEC_CODE
# include "Fee_30_FlexNor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

#endif /* SCHM_FEE_30_FLEXNOR_H */

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

*/
