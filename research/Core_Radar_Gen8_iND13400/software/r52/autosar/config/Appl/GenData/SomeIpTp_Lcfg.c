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
 *            Module: SomeIpTp
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: SomeIpTp_Lcfg.c
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
	
#define SOMEIPTP_LCFG_SOURCE

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "SomeIpTp_Lcfg.h"
#include "SomeIpTp_Cfg.h"

#include "PduR_SomeIpTp.h"


/**********************************************************************************************************************
 *  LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  SomeIpTp_TXNSdu
**********************************************************************************************************************/
/** 
  \var    SomeIpTp_TXNSdu
  \brief  List of TX NSDUs
  \details
  Element         Description
  LowerLayerId    SNV to the PDU referenced by the lower layer
  UpperLayerId    SNV to the PDU referenced by the upper layer
*/ 
#define SOMEIPTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SomeIpTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SomeIpTp_TXNSduType, SOMEIPTP_CONST) SomeIpTp_TXNSdu[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LowerLayerId                             UpperLayerId                                                */
  { /*     0 */ PduRConf_PduRSrcPdu_PduRSrcPdu_f4b7358b, PduRConf_PduRDestPdu_signalPdu_RDR_1_Detections_52b391ee_Tx }
};
#define SOMEIPTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SomeIpTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SomeIpTp_TxQueueElement
**********************************************************************************************************************/
#define SOMEIPTP_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "SomeIpTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SomeIpTp_TxQueueElementType, SOMEIPTP_VAR_NO_INIT) SomeIpTp_TxQueueElement[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define SOMEIPTP_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "SomeIpTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SomeIpTp_TxShortHeaders
**********************************************************************************************************************/
#define SOMEIPTP_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SomeIpTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SomeIpTp_TxShortHeadersUType, SOMEIPTP_VAR_NO_INIT) SomeIpTp_TxShortHeaders;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SomeIpTp/signalPdu_RDR_1_Detections_52b391ee/PDUTriggering14_Detections_RDR1_to_ADAS_de104d9b/PDUTriggering14_Detections_RDR1_to_ADAS_Transport_3817dced] */
  /*   ... */  /* [/ActiveEcuC/SomeIpTp/signalPdu_RDR_1_Detections_52b391ee/PDUTriggering14_Detections_RDR1_to_ADAS_de104d9b/PDUTriggering14_Detections_RDR1_to_ADAS_Transport_3817dced] */
  /*     7 */  /* [/ActiveEcuC/SomeIpTp/signalPdu_RDR_1_Detections_52b391ee/PDUTriggering14_Detections_RDR1_to_ADAS_de104d9b/PDUTriggering14_Detections_RDR1_to_ADAS_Transport_3817dced] */

#define SOMEIPTP_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "SomeIpTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SomeIpTp_TxState
**********************************************************************************************************************/
/** 
  \var    SomeIpTp_TxState
  \brief  TX NSDU Info
  \details
  Element          Description
  Offset           Offset of the previous segment transmitted
  DataIndex        Index within the message
  DataLength       Length of the complete frame
  Metadata         Metadata of the active transmission.
  NextSegmentDL    size of the next segmented PDU
  Timer            Separation time/Tx confirmation timeout timer of the SDU
  Segmented        Flag indicating if the active transmission is segmented.
  Status           State of the SDU
*/ 
#define SOMEIPTP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SomeIpTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SomeIpTp_TxStateUType, SOMEIPTP_VAR_NO_INIT) SomeIpTp_TxState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [PDUTriggering14_Detections_RDR1_to_ADAS_Transport_3817dced] */

#define SOMEIPTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SomeIpTp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 * FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/


/**********************************************************************************************************************
  END OF FILE: SomeIpTp_Lcfg.c
**********************************************************************************************************************/


