/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: EcuM
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EcuM_Init_Cfg.c
 *   Generation Time: 2026-08-27 16:48:47
 *           Project: Gen8_iND13400 - Version 1.0
 *          Delivery: PAI19494
 *      Tool Version: DaVinci Configurator Classic (beta) 5.31.55 SP5
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Classic and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

#define ECUM_INIT_CFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "EcuM_Init_PBcfg.h" 
 

 

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_Init_Includes>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/* In the following is the generated EcuM_GlobalConfigRoot. It contains supported BSW modules which
 * have configuration variant post-build-loadable. 
 */

#if (ECUM_USE_GENERATED_GLOBAL_CONFIG == STD_ON)

#define ECUM_START_SEC_CONST_ASIL_D
#include "EcuM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(EcuM_GlobalConfigRootType, ECUM_CONST) EcuM_GlobalConfigRoot = /* PRQA S 1533 *//* MD_EcuM_1533 */
{
  {
    BswM_Config_RDR_01_Ptr, 
    BswM_Config_RDR_01_Ptr, 
    CanIf_Config_RDR_01_Ptr, 
    CanTSyn_Config_RDR_01_Ptr, 
    CanTSyn_Config_RDR_01_Ptr, 
    CanTp_Config_RDR_01_Ptr, 
    CanTp_Config_RDR_01_Ptr, 
    Com_Config_RDR_01_Ptr, 
    &Dcm_CfgConfig_RDR_01, 
    Dem_Config_RDR_01_Ptr, 
    Dem_Config_RDR_01_Ptr, 
    EcuM_Config_RDR_01_Ptr, 
    EthIf_Config_RDR_01_Ptr, 
    J1939Tp_Config_RDR_01_Ptr, 
    PduR_Config_RDR_01_Ptr, 
    PduR_Config_RDR_01_Ptr, 
    StbM_Config_RDR_01_Ptr, 
    StbM_Config_RDR_01_Ptr
  }, 
  {
    BswM_Config_RDR_02_Ptr, 
    BswM_Config_RDR_02_Ptr, 
    CanIf_Config_RDR_02_Ptr, 
    CanTSyn_Config_RDR_02_Ptr, 
    CanTSyn_Config_RDR_02_Ptr, 
    CanTp_Config_RDR_02_Ptr, 
    CanTp_Config_RDR_02_Ptr, 
    Com_Config_RDR_02_Ptr, 
    &Dcm_CfgConfig_RDR_02, 
    Dem_Config_RDR_02_Ptr, 
    Dem_Config_RDR_02_Ptr, 
    EcuM_Config_RDR_02_Ptr, 
    EthIf_Config_RDR_02_Ptr, 
    J1939Tp_Config_RDR_02_Ptr, 
    PduR_Config_RDR_02_Ptr, 
    PduR_Config_RDR_02_Ptr, 
    StbM_Config_RDR_02_Ptr, 
    StbM_Config_RDR_02_Ptr
  }, 
  {
    BswM_Config_RDR_03_Ptr, 
    BswM_Config_RDR_03_Ptr, 
    CanIf_Config_RDR_03_Ptr, 
    CanTSyn_Config_RDR_03_Ptr, 
    CanTSyn_Config_RDR_03_Ptr, 
    CanTp_Config_RDR_03_Ptr, 
    CanTp_Config_RDR_03_Ptr, 
    Com_Config_RDR_03_Ptr, 
    &Dcm_CfgConfig_RDR_03, 
    Dem_Config_RDR_03_Ptr, 
    Dem_Config_RDR_03_Ptr, 
    EcuM_Config_RDR_03_Ptr, 
    EthIf_Config_RDR_03_Ptr, 
    J1939Tp_Config_RDR_03_Ptr, 
    PduR_Config_RDR_03_Ptr, 
    PduR_Config_RDR_03_Ptr, 
    StbM_Config_RDR_03_Ptr, 
    StbM_Config_RDR_03_Ptr
  }, 
  {
    BswM_Config_RDR_04_Ptr, 
    BswM_Config_RDR_04_Ptr, 
    CanIf_Config_RDR_04_Ptr, 
    CanTSyn_Config_RDR_04_Ptr, 
    CanTSyn_Config_RDR_04_Ptr, 
    CanTp_Config_RDR_04_Ptr, 
    CanTp_Config_RDR_04_Ptr, 
    Com_Config_RDR_04_Ptr, 
    &Dcm_CfgConfig_RDR_04, 
    Dem_Config_RDR_04_Ptr, 
    Dem_Config_RDR_04_Ptr, 
    EcuM_Config_RDR_04_Ptr, 
    EthIf_Config_RDR_04_Ptr, 
    J1939Tp_Config_RDR_04_Ptr, 
    PduR_Config_RDR_04_Ptr, 
    PduR_Config_RDR_04_Ptr, 
    StbM_Config_RDR_04_Ptr, 
    StbM_Config_RDR_04_Ptr
  }, 
  {
    BswM_Config_RDR_05_Ptr, 
    BswM_Config_RDR_05_Ptr, 
    CanIf_Config_RDR_05_Ptr, 
    CanTSyn_Config_RDR_05_Ptr, 
    CanTSyn_Config_RDR_05_Ptr, 
    CanTp_Config_RDR_05_Ptr, 
    CanTp_Config_RDR_05_Ptr, 
    Com_Config_RDR_05_Ptr, 
    &Dcm_CfgConfig_RDR_05, 
    Dem_Config_RDR_05_Ptr, 
    Dem_Config_RDR_05_Ptr, 
    EcuM_Config_RDR_05_Ptr, 
    EthIf_Config_RDR_05_Ptr, 
    J1939Tp_Config_RDR_05_Ptr, 
    PduR_Config_RDR_05_Ptr, 
    PduR_Config_RDR_05_Ptr, 
    StbM_Config_RDR_05_Ptr, 
    StbM_Config_RDR_05_Ptr
  }, 
  {
    BswM_Config_RDR_06_Ptr, 
    BswM_Config_RDR_06_Ptr, 
    CanIf_Config_RDR_06_Ptr, 
    CanTSyn_Config_RDR_06_Ptr, 
    CanTSyn_Config_RDR_06_Ptr, 
    CanTp_Config_RDR_06_Ptr, 
    CanTp_Config_RDR_06_Ptr, 
    Com_Config_RDR_06_Ptr, 
    &Dcm_CfgConfig_RDR_06, 
    Dem_Config_RDR_06_Ptr, 
    Dem_Config_RDR_06_Ptr, 
    EcuM_Config_RDR_06_Ptr, 
    EthIf_Config_RDR_06_Ptr, 
    J1939Tp_Config_RDR_06_Ptr, 
    PduR_Config_RDR_06_Ptr, 
    PduR_Config_RDR_06_Ptr, 
    StbM_Config_RDR_06_Ptr, 
    StbM_Config_RDR_06_Ptr
  }, 
  {
    BswM_Config_RDR_07_Ptr, 
    BswM_Config_RDR_07_Ptr, 
    CanIf_Config_RDR_07_Ptr, 
    CanTSyn_Config_RDR_07_Ptr, 
    CanTSyn_Config_RDR_07_Ptr, 
    CanTp_Config_RDR_07_Ptr, 
    CanTp_Config_RDR_07_Ptr, 
    Com_Config_RDR_07_Ptr, 
    &Dcm_CfgConfig_RDR_07, 
    Dem_Config_RDR_07_Ptr, 
    Dem_Config_RDR_07_Ptr, 
    EcuM_Config_RDR_07_Ptr, 
    EthIf_Config_RDR_07_Ptr, 
    J1939Tp_Config_RDR_07_Ptr, 
    PduR_Config_RDR_07_Ptr, 
    PduR_Config_RDR_07_Ptr, 
    StbM_Config_RDR_07_Ptr, 
    StbM_Config_RDR_07_Ptr
  }, 
  {
    BswM_Config_RDR_08_Ptr, 
    BswM_Config_RDR_08_Ptr, 
    CanIf_Config_RDR_08_Ptr, 
    CanTSyn_Config_RDR_08_Ptr, 
    CanTSyn_Config_RDR_08_Ptr, 
    CanTp_Config_RDR_08_Ptr, 
    CanTp_Config_RDR_08_Ptr, 
    Com_Config_RDR_08_Ptr, 
    &Dcm_CfgConfig_RDR_08, 
    Dem_Config_RDR_08_Ptr, 
    Dem_Config_RDR_08_Ptr, 
    EcuM_Config_RDR_08_Ptr, 
    EthIf_Config_RDR_08_Ptr, 
    J1939Tp_Config_RDR_08_Ptr, 
    PduR_Config_RDR_08_Ptr, 
    PduR_Config_RDR_08_Ptr, 
    StbM_Config_RDR_08_Ptr, 
    StbM_Config_RDR_08_Ptr
  }
};

#define ECUM_STOP_SEC_CONST_ASIL_D
#include "EcuM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif

#define ECUM_START_SEC_CONST_ASIL_D
#include "EcuM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_GlobalPcConfigRoot>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* In this section a custom EcuM_GlobalConfigRoot can be defined. Use generated EcuM_GlobalConfigRoot as template.
 *
 * Caution: If a custom EcuM_GlobalConfigRoot is used, the EcuM_GlobalConfigType must be adapted in EcuM_Init_PBcfg.h!
 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#define ECUM_STOP_SEC_CONST_ASIL_D
#include "EcuM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

 



/**********************************************************************************************************************
 *  END OF FILE: ECUM_INIT_PBCFG_SOURCE.C
 *********************************************************************************************************************/
 

