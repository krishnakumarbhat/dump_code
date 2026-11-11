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
 *             File:  Rte_PBCfg.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  RTE Post Build Data Set Configuration Header
 *********************************************************************************************************************/
/* double include prevention */
#ifndef RTE_PBCFG_H
# define RTE_PBCFG_H

typedef struct {
  uint8 variant;
} SchM_ConfigType;

# define RTE_START_SEC_CONST_ASIL_B_UNSPECIFIED
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(SchM_ConfigType, RTE_CONST) Rte_Config_RDR_01;

extern CONST(SchM_ConfigType, RTE_CONST) Rte_Config_RDR_02;

extern CONST(SchM_ConfigType, RTE_CONST) Rte_Config_RDR_03;

extern CONST(SchM_ConfigType, RTE_CONST) Rte_Config_RDR_04;

extern CONST(SchM_ConfigType, RTE_CONST) Rte_Config_RDR_05;

extern CONST(SchM_ConfigType, RTE_CONST) Rte_Config_RDR_06;

extern CONST(SchM_ConfigType, RTE_CONST) Rte_Config_RDR_07;

extern CONST(SchM_ConfigType, RTE_CONST) Rte_Config_RDR_08;


# define RTE_STOP_SEC_CONST_ASIL_B_UNSPECIFIED
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* RTE_PBCFG_H */
