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
 *            Module: EthSM
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EthSM_Cfg.c
 *   Generation Time: 2026-08-27 14:12:13
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
#define ETHSM_CFG_SOURCE

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0779 EOF */ /* MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "EthSM_Types.h"

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  EthSM_NetIdxByComMNetwHnd
**********************************************************************************************************************/
#define ETHSM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "EthSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EthSM_NetIdxByComMNetwHndType, ETHSM_CONST) EthSM_NetIdxByComMNetwHnd[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     NetIdxByComMNetwHnd               Referable Keys */
  /*     0 */                            0u,  /* [/ActiveEcuC/ComM/ComMConfigSet/cnctr_RDR_RdrNet_5172a59b] */
  /*     1 */  ETHSM_NO_NETIDXBYCOMMNETWHND,  /* [/ActiveEcuC/ComM/ComMConfigSet/CN_PCAN_RADAR_458ff0f1] */
  /*     2 */  ETHSM_NO_NETIDXBYCOMMNETWHND   /* [/ActiveEcuC/ComM/ComMConfigSet/CN_VCAN_RADAR_489180b6] */
};
#define ETHSM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "EthSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthSM_Initialized
**********************************************************************************************************************/
#define ETHSM_START_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "EthSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthSM_InitializedType, ETHSM_VAR_CLEARED) EthSM_Initialized;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ETHSM_STOP_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "EthSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthSM_LastReportedState
**********************************************************************************************************************/
#define ETHSM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthSM_LastReportedStateUType, ETHSM_VAR_NO_INIT) EthSM_LastReportedState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/EthSM/cnctr_RDR_RdrNet_5172a59b] */

#define ETHSM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthSM_Mode
**********************************************************************************************************************/
#define ETHSM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthSM_ModeUType, ETHSM_VAR_NO_INIT) EthSM_Mode;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/EthSM/cnctr_RDR_RdrNet_5172a59b] */

#define ETHSM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthSM_RequestedMode
**********************************************************************************************************************/
#define ETHSM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthSM_RequestedModeUType, ETHSM_VAR_NO_INIT) EthSM_RequestedMode;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/EthSM/cnctr_RDR_RdrNet_5172a59b] */

#define ETHSM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthSM_State
**********************************************************************************************************************/
#define ETHSM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthSM_StateUType, ETHSM_VAR_NO_INIT) EthSM_State;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/EthSM/cnctr_RDR_RdrNet_5172a59b] */

#define ETHSM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthSM_TcpIpState
**********************************************************************************************************************/
#define ETHSM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthSM_TcpIpStateUType, ETHSM_VAR_NO_INIT) EthSM_TcpIpState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/EthSM/cnctr_RDR_RdrNet_5172a59b] */

#define ETHSM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthSM_TrcvLinkState
**********************************************************************************************************************/
#define ETHSM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EthSM_TrcvLinkStateUType, ETHSM_VAR_NO_INIT) EthSM_TrcvLinkState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/EthSM/cnctr_RDR_RdrNet_5172a59b] */

#define ETHSM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthSM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: EthSM_Cfg.c
 *********************************************************************************************************************/

