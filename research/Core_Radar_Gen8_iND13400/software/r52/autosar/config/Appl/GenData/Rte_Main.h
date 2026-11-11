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
 *             File:  Rte_Main.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Lifecycle Header File
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_MAIN_H
# define RTE_MAIN_H

# include "Rte.h"

# define RTE_Lifecycle_START_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* BSW Scheduler Life-Cycle API */
FUNC(void, RTE_CODE) SchM_Init(P2CONST(SchM_ConfigType, AUTOMATIC, RTE_CONST) ConfigPtr);
FUNC(void, RTE_CODE) SchM_Start(void);
FUNC(void, RTE_CODE) SchM_StartTiming(void);
FUNC(void, RTE_CODE) SchM_Deinit(void);

/* RTE Life-Cycle API */
FUNC(Std_ReturnType, RTE_CODE) Rte_Start(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Stop(void);

/* Extended Life-Cycle API */
FUNC(void, RTE_CODE) Rte_InitMemory(void);
FUNC(void, RTE_CODE) Rte_InitMemory_OsCore0_ASIL(void);
FUNC(void, RTE_CODE) Rte_InitMemory_OsCore_Qm(void);

# define RTE_Lifecycle_STOP_SEC_CODE_ASIL_B
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* RTE_MAIN_H */
