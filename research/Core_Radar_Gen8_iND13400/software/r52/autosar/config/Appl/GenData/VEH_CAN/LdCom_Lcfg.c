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
 *            Module: LdCom
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: LdCom_Lcfg.c
 *   Generation Time: 2026-04-28 18:02:36
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
#define LDCOM_LCFG_SOURCE

/**********************************************************************************************************************
 *  LOCAL MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "LdCom.h"
#include "LdCom_Lcfg.h"

#include "Rte_Cbk.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  LdCom_IfRxIndicationFctPtr
**********************************************************************************************************************/
/** 
  \var    LdCom_IfRxIndicationFctPtr
  \brief  Upper layer communication interface Rx indication function pointer according DefinitionRef: /MICROSAR/LdCom/LdComConfig/LdComIPdu/LdComRxIndication
*/ 
#define LDCOM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(LdCom_IfRxIndicationFctPtrType, LDCOM_CONST) LdCom_IfRxIndicationFctPtr[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     IfRxIndicationFctPtr                                                    Referable Keys */
  /*     0 */ NULL_PTR    /* [/ActiveEcuC/LdCom/LdComConfig/signalPdu_ADAS_Vehicle_Status_638dcd82_Rx[0:LdComRxIndication]] */
};
#define LDCOM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LdCom_RxTxPduInfo
**********************************************************************************************************************/
/** 
  \var    LdCom_RxTxPduInfo
  \brief  Table containing mapping data from Input handles to PduR Tx handles/RTE callbacks.
  \details
  Element                      Description
  IfRxIndicationFctPtrIdx      the index of the 0:1 relation pointing to LdCom_IfRxIndicationFctPtr
  PduRTxHandleId               Handle ID used to call PduR_LdComTransmit()
  TpCopyTxDataFctPtrIdx        the index of the 0:1 relation pointing to LdCom_TpCopyTxDataFctPtr
  TpTxConfirmationFctPtrIdx    the index of the 0:1 relation pointing to LdCom_TpTxConfirmationFctPtr
*/ 
#define LDCOM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(LdCom_RxTxPduInfoType, LDCOM_CONST) LdCom_RxTxPduInfo[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IfRxIndicationFctPtrIdx                        PduRTxHandleId                           TpCopyTxDataFctPtrIdx                        TpTxConfirmationFctPtrIdx                              Referable Keys */
  { /*     0 */                                            0u,                                      0u, LDCOM_NO_TPCOPYTXDATAFCTPTRIDXOFRXTXPDUINFO, LDCOM_NO_TPTXCONFIRMATIONFCTPTRIDXOFRXTXPDUINFO },  /* [/ActiveEcuC/LdCom/LdComConfig/signalPdu_ADAS_Vehicle_Status_638dcd82_Rx] */
  { /*     1 */ LDCOM_NO_IFRXINDICATIONFCTPTRIDXOFRXTXPDUINFO, PduRConf_PduRSrcPdu_PduRSrcPdu_7d97b0c9,                                          0u,                                              0u },  /* [/ActiveEcuC/LdCom/LdComConfig/signalPdu_RDR_1_Detections_52b391ee_Tx] */
  { /*     2 */ LDCOM_NO_IFRXINDICATIONFCTPTRIDXOFRXTXPDUINFO, PduRConf_PduRSrcPdu_PduRSrcPdu_69bb1772, LDCOM_NO_TPCOPYTXDATAFCTPTRIDXOFRXTXPDUINFO, LDCOM_NO_TPTXCONFIRMATIONFCTPTRIDXOFRXTXPDUINFO },  /* [/ActiveEcuC/LdCom/LdComConfig/signalPdu_RDR_1_SW_Info_b4e751e3_Tx] */
  { /*     3 */ LDCOM_NO_IFRXINDICATIONFCTPTRIDXOFRXTXPDUINFO, PduRConf_PduRSrcPdu_PduRSrcPdu_c2fc0504, LDCOM_NO_TPCOPYTXDATAFCTPTRIDXOFRXTXPDUINFO, LDCOM_NO_TPTXCONFIRMATIONFCTPTRIDXOFRXTXPDUINFO }   /* [/ActiveEcuC/LdCom/LdComConfig/signalPdu_RDR_1_Status_9d482741_Tx] */
};
#define LDCOM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LdCom_TpCopyTxDataFctPtr
**********************************************************************************************************************/
/** 
  \var    LdCom_TpCopyTxDataFctPtr
  \brief  Upper layer transport protocol CopyTxData function pointer according DefinitionRef: /MICROSAR/LdCom/LdComConfig/LdComIPdu/LdComTxCopyTxData
*/ 
#define LDCOM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(LdCom_TpCopyTxDataFctPtrType, LDCOM_CONST) LdCom_TpCopyTxDataFctPtr[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TpCopyTxDataFctPtr                                                 Referable Keys */
  /*     0 */ NULL_PTR    /* [/ActiveEcuC/LdCom/LdComConfig/signalPdu_RDR_1_Detections_52b391ee_Tx[0:LdComTxCopyTxData]] */
};
#define LDCOM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LdCom_TpTxConfirmationFctPtr
**********************************************************************************************************************/
/** 
  \var    LdCom_TpTxConfirmationFctPtr
  \brief  Upper layer transport protocol TpTxConfirmation function pointer according DefinitionRef: /MICROSAR/LdCom/LdComConfig/LdComIPdu/LdComTpTxConfirmation
*/ 
#define LDCOM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(LdCom_TpTxConfirmationFctPtrType, LDCOM_CONST) LdCom_TpTxConfirmationFctPtr[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TpTxConfirmationFctPtr                                                   Referable Keys */
  /*     0 */ NULL_PTR    /* [/ActiveEcuC/LdCom/LdComConfig/signalPdu_RDR_1_Detections_52b391ee_Tx[0:LdComTpTxConfirmation]] */
};
#define LDCOM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LdCom_Initialized
**********************************************************************************************************************/
/** 
  \var    LdCom_Initialized
  \brief  Initialization state of LdCom. TRUE, if initialized.
*/ 
#define LDCOM_START_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(LdCom_InitializedType, LDCOM_VAR_CLEARED) LdCom_Initialized;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define LDCOM_STOP_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


#define LDCOM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "LdCom_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */
#if (LDCOM_USE_INIT_POINTER == STD_ON)
P2CONST(LdCom_ConfigType, LDCOM_VAR_CLEARED, LDCOM_PBCFG) LdCom_ConfigDataPtr = NULL_PTR;     /* PRQA S 1504 */ /* MD_MSR_Rule8.7 */
#endif
#define LDCOM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "LdCom_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: LdCom_Lcfg.c
 *********************************************************************************************************************/
