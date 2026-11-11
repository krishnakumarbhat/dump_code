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
 *              File: EcuM_Init_Cfg.h
 *   Generation Time: 2026-08-27 14:12:14
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
#if !defined (ECUM_INIT_CFG_H)
# define ECUM_INIT_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

 

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_Init_Includes>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
#include "BswM.h" 
#include "CanIf.h" 
#include "CanTSyn.h" 
#include "CanTp.h" 
#include "Com.h" 
#include "Dcm.h" 
#include "Dem.h" 
#include "EcuM.h" 
#include "EthIf.h" 
#include "Fls.h" 
#include "J1939Tp.h" 
#include "PduR.h" 
#include "Pwm.h" 
#include "StbM.h" 

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* In the following is the generated EcuM_GlobalConfigType. It contains supported BSW modules which
 * have configuration variant post-build-loadable. 
 */

#if (ECUM_USE_GENERATED_GLOBAL_CONFIG == STD_ON)

typedef struct
{
  CONSTP2CONST(BswM_ConfigType, TYPEDEF, BSWM_INIT_DATA) CfgPtr_BswM_Init;
  CONSTP2CONST(BswM_ConfigType, TYPEDEF, BSWM_INIT_DATA) CfgPtr_BswM_PreInit;
  CONSTP2CONST(CanIf_ConfigType, TYPEDEF, CANIF_INIT_DATA) CfgPtr_CanIf_Init;
  CONSTP2CONST(CanTSyn_ConfigType, TYPEDEF, CANTSYN_INIT_DATA) CfgPtr_CanTSyn_Init;
  CONSTP2CONST(CanTSyn_ConfigType, TYPEDEF, CANTSYN_INIT_DATA) CfgPtr_CanTSyn_PreInit;
  CONSTP2CONST(CanTp_PBConfigType, TYPEDEF, CANTP_INIT_DATA) CfgPtr_CanTp_Init;
  CONSTP2CONST(CanTp_PBConfigType, TYPEDEF, CANTP_INIT_DATA) CfgPtr_CanTp_PreInit;
  CONSTP2CONST(Com_ConfigType, TYPEDEF, COM_INIT_DATA) CfgPtr_Com_Init;
  CONSTP2CONST(Dcm_ConfigType, TYPEDEF, DCM_CONST) CfgPtr_Dcm_Init;
  CONSTP2CONST(Dem_ConfigType, TYPEDEF, DEM_INIT_DATA) CfgPtr_Dem_Init;
  CONSTP2CONST(Dem_ConfigType, TYPEDEF, DEM_INIT_DATA) CfgPtr_Dem_PreInit;
  CONSTP2CONST(EcuM_PbConfigType, TYPEDEF, ECUM_INIT_DATA) CfgPtr_EcuM_Init;
  CONSTP2CONST(EthIf_ConfigType, TYPEDEF, ETHIF_INIT_DATA) CfgPtr_EthIf_Init;
  CONSTP2CONST(J1939Tp_ConfigType, TYPEDEF, J1939TP_INIT_DATA) CfgPtr_J1939Tp_Init;
  CONSTP2CONST(PduR_PBConfigType, TYPEDEF, PDUR_INIT_DATA) CfgPtr_PduR_Init;
  CONSTP2CONST(PduR_PBConfigType, TYPEDEF, PDUR_INIT_DATA) CfgPtr_PduR_PreInit;
  CONSTP2CONST(StbM_ConfigType, TYPEDEF, STBM_INIT_DATA) CfgPtr_StbM_Init;
  CONSTP2CONST(StbM_ConfigType, TYPEDEF, STBM_INIT_DATA) CfgPtr_StbM_PreInit;
} EcuM_GlobalPCConfigType;


typedef EcuM_GlobalPCConfigType EcuM_GlobalConfigType;

typedef P2CONST(EcuM_GlobalConfigType, AUTOMATIC, ECUM_CONST) EcuM_GlobalConfigRefType;

typedef struct
{
  EcuM_GlobalConfigType RDR_01;
  EcuM_GlobalConfigType RDR_02;
  EcuM_GlobalConfigType RDR_03;
  EcuM_GlobalConfigType RDR_04;
  EcuM_GlobalConfigType RDR_05;
  EcuM_GlobalConfigType RDR_06;
  EcuM_GlobalConfigType RDR_07;
  EcuM_GlobalConfigType RDR_08;
} EcuM_GlobalConfigRootType;


#endif


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_GlobalConfigType>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* In this section a custom EcuM_GlobalConfigType can be defined. Use generated EcuM_GlobalConfigType as template.
 *
 * Caution: EcuM must be always in variant post-build if one of the BSW module is in variant post-build.
 *          Do not change the name of the member EcuM. If the BswM is in variant post-build 
 *          it is also not allowed to change the name of the struct member. This two modules 
 *          are accessed during initialization via this names.
 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define ECUM_START_SEC_VAR_CLEARED_ASIL_D_GLOBAL_PTR
#include "EcuM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Global pointer to access the global variant data, do not remove and do not change the name */
 
extern P2CONST(EcuM_GlobalConfigType, ECUM_VAR_CLEARED, ECUM_CONST) EcuM_GlobalPCConfig_Ptr;

#define ECUM_STOP_SEC_VAR_CLEARED_ASIL_D_GLOBAL_PTR
#include "EcuM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define ECUM_START_SEC_CONST_ASIL_D
#include "EcuM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 

extern CONST(EcuM_GlobalConfigRootType, ECUM_CONST) EcuM_GlobalConfigRoot; 

#define ECUM_STOP_SEC_CONST_ASIL_D
#include "EcuM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 







#endif
/**********************************************************************************************************************
 *  END OF FILE: ECUM_INIT_PBCFG.H
 *********************************************************************************************************************/


