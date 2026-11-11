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
 *            Module: J1939Tp
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: J1939Tp_Cfg.c
 *   Generation Time: 2026-08-05 12:38:43
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

/**********************************************************************************************************************
  MISRA JUSTIFICATION
**********************************************************************************************************************/

/* PRQA S 0779 EOF */ /* MD_MSR_5.1_777 */


/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/

#define J1939TP_CFG_SOURCE

#include "J1939Tp_Cfg.h"

/* include headers with symbolic name values */
#include "CanIf.h"
#include "PduR_J1939Tp.h"


/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


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
  J1939Tp_MetaDataGetterCAN_ID_32
**********************************************************************************************************************/
#define J1939TP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(J1939Tp_MetaDataGetterCAN_ID_32FctPtrType, J1939TP_CONST) J1939Tp_MetaDataGetterCAN_ID_32[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     MetaDataGetterCAN_ID_32                  Referable Keys */
  /*     0 */ J1939Tp_Mdt_Get_CAN_ID_32_CAN_ID_32    /* [CAN_ID_32] */
};
#define J1939TP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  J1939Tp_MetaDataGetterTARGET_ADDRESS_16
**********************************************************************************************************************/
#define J1939TP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(J1939Tp_MetaDataGetterTARGET_ADDRESS_16FctPtrType, J1939TP_CONST) J1939Tp_MetaDataGetterTARGET_ADDRESS_16[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     MetaDataGetterTARGET_ADDRESS_16                          Referable Keys */
  /*     0 */ J1939Tp_Mdt_Get_TARGET_ADDRESS_16_TARGET_ADDRESS_16    /* [TARGET_ADDRESS_16] */
};
#define J1939TP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  J1939Tp_MetaDataSetterCAN_ID_32
**********************************************************************************************************************/
#define J1939TP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(J1939Tp_MetaDataSetterCAN_ID_32FctPtrType, J1939TP_CONST) J1939Tp_MetaDataSetterCAN_ID_32[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     MetaDataSetterCAN_ID_32                  Referable Keys */
  /*     0 */ J1939Tp_Mdt_Set_CAN_ID_32_CAN_ID_32    /* [CAN_ID_32] */
};
#define J1939TP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  J1939Tp_MetaDataSetterTARGET_ADDRESS_16
**********************************************************************************************************************/
#define J1939TP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(J1939Tp_MetaDataSetterTARGET_ADDRESS_16FctPtrType, J1939TP_CONST) J1939Tp_MetaDataSetterTARGET_ADDRESS_16[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     MetaDataSetterTARGET_ADDRESS_16                          Referable Keys */
  /*     0 */ J1939Tp_Mdt_Set_TARGET_ADDRESS_16_TARGET_ADDRESS_16    /* [TARGET_ADDRESS_16] */
};
#define J1939TP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  J1939Tp_TxChannel
**********************************************************************************************************************/
/** 
  \var    J1939Tp_TxChannel
  \brief  DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel
  \details
  Element                                  Description
  ComMChannel                              DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel/J1939TpTxChannelComMNetworkHandleRef
  TxVarPri                                 DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel/J1939TpTxUseNonDefaultTpPriority
  TxBamInterframeTime                      DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel/J1939TpTxBamInterframeTime
  TxChannelTxNSduTxNSduTableIndEndIdx      the end index of the 0:n relation pointing to J1939Tp_TxChannelTxNSduTxNSduTableInd
  TxChannelTxNSduTxNSduTableIndStartIdx    the start index of the 0:n relation pointing to J1939Tp_TxChannelTxNSduTxNSduTableInd
  TxDa                                     DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel/J1939TpTxDa
  TxMaxPacketsPerBlock                     DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel/J1939TpTxMaxPacketsPerBlock
  TxPduTxCmNPduIdx                         the index of the 0:1 relation pointing to J1939Tp_TxPdu
  TxPduTxDtNPduIdx                         the index of the 0:1 relation pointing to J1939Tp_TxPdu
  TxPri                                    DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel/J1939TpTxPriority
  TxProtocolType                           DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel/J1939TpTxProtocolType
  TxSa                                     DefinitionRef: /MICROSAR/J1939Tp/J1939TpConfiguration/J1939TpTxChannel/J1939TpTxSa
*/ 
#define J1939TP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(J1939Tp_TxChannelType, J1939TP_CONST) J1939Tp_TxChannel[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ComMChannel  TxVarPri  TxBamInterframeTime  TxChannelTxNSduTxNSduTableIndEndIdx  TxChannelTxNSduTxNSduTableIndStartIdx  TxDa   TxMaxPacketsPerBlock  TxPduTxCmNPduIdx  TxPduTxDtNPduIdx  TxPri  TxProtocolType                                     TxSa         Referable Keys */
  { /*     0 */          2u,     TRUE,                  5u,                                  1u,                                    0u, 0xFEu,                 255u,               0u,               1u, 0x06u, J1939TP_PROTOCOL_UNUSED_TXPROTOCOLTYPEOFTXCHANNEL, 0xD0u }   /* [/ActiveEcuC/J1939Tp/J1939TpConfiguration/VCAN_RADAR_J1939_3cea4416] */
};
#define J1939TP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  J1939Tp_TxChannelTxNSdu
**********************************************************************************************************************/
/** 
  \var    J1939Tp_TxChannelTxNSdu
  \details
  Element           Description
  TxSduTxNSduIdx    the index of the 1:1 relation pointing to J1939Tp_TxSdu
*/ 
#define J1939TP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(J1939Tp_TxChannelTxNSduType, J1939TP_CONST) J1939Tp_TxChannelTxNSdu[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxSduTxNSduIdx        Referable Keys */
  { /*     0 */             0u }   /* [/ActiveEcuC/J1939Tp/J1939TpConfiguration/VCAN_RADAR_J1939_3cea4416] */
};
#define J1939TP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  J1939Tp_TxChannelTxNSduTxNSduTableInd
**********************************************************************************************************************/
/** 
  \var    J1939Tp_TxChannelTxNSduTxNSduTableInd
  \brief  the indexes of the 1:1 sorted relation pointing to J1939Tp_TxChannelTxNSdu
*/ 
#define J1939TP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(J1939Tp_TxChannelTxNSduTxNSduTableIndType, J1939TP_CONST) J1939Tp_TxChannelTxNSduTxNSduTableInd[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxChannelTxNSduTxNSduTableInd      Referable Keys */
  /*     0 */                             0u   /* [/ActiveEcuC/J1939Tp/J1939TpConfiguration/VCAN_RADAR_J1939_3cea4416] */
};
#define J1939TP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  J1939Tp_TxPdu
**********************************************************************************************************************/
/** 
  \var    J1939Tp_TxPdu
  \brief  List of transmitted PDUs
  \details
  Element                                    Description
  HasMetaData                                MetaData
  MetaDataGetterCAN_ID_32Idx                 the index of the 0:1 relation pointing to J1939Tp_MetaDataGetterCAN_ID_32
  MetaDataSetterCAN_ID_32Idx                 the index of the 0:1 relation pointing to J1939Tp_MetaDataSetterCAN_ID_32
  PduId                                      PDU ID
  PduType                                    PDU Type
  TxPduStateIdx                              the index of the 1:1 relation pointing to J1939Tp_TxPduState
  TxPduTxChannelTxChannelTableIndEndIdx      the end index of the 0:n relation pointing to J1939Tp_TxPduTxChannelTxChannelTableInd
  TxPduTxChannelTxChannelTableIndStartIdx    the start index of the 0:n relation pointing to J1939Tp_TxPduTxChannelTxChannelTableInd
*/ 
#define J1939TP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(J1939Tp_TxPduType, J1939TP_CONST) J1939Tp_TxPdu[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    HasMetaData  MetaDataGetterCAN_ID_32Idx  MetaDataSetterCAN_ID_32Idx  PduId                                                                                       PduType                        TxPduStateIdx  TxPduTxChannelTxChannelTableIndEndIdx  TxPduTxChannelTxChannelTableIndStartIdx        Referable Keys */
  { /*     0 */        TRUE,                         0u,                         0u,                                    CanIfConf_CanIfTxPduCfg_TPCM_Tp_oVCAN_RADAR_229e257c_Tx,   J1939TP_TPCM_PDUTYPEOFTXPDU,            0u,                                    1u,                                      0u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPCM_Tp_oVCAN_RADAR_a235016c_Tx] */
  { /*     1 */        TRUE,                         0u,                         0u,                                    CanIfConf_CanIfTxPduCfg_TPDT_Tp_oVCAN_RADAR_95c1c45e_Tx,   J1939TP_TPDT_PDUTYPEOFTXPDU,            1u,                                    2u,                                      1u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPDT_Tp_oVCAN_RADAR_92966f54_Tx] */
  { /*     2 */        TRUE,                         0u,                         0u, CanIfConf_CanIfTxPduCfg_TpDirectNPdu_DM1_D0_oVCAN_RADAR_51899be1_VCAN_RADAR_J1939_bd37ae49, J1939TP_DIRECT_PDUTYPEOFTXPDU,            2u,                                    3u,                                      2u }   /* [/ActiveEcuC/EcuC/EcucPduCollection/TPCM_DirectTp_oVCAN_RADAR_a235016c_Tx] */
};
#define J1939TP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  J1939Tp_TxPduTxChannel
**********************************************************************************************************************/
/** 
  \var    J1939Tp_TxPduTxChannel
  \details
  Element                  Description
  TxChannelTxChannelIdx    the index of the 1:1 relation pointing to J1939Tp_TxChannel
*/ 
#define J1939TP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(J1939Tp_TxPduTxChannelType, J1939TP_CONST) J1939Tp_TxPduTxChannel[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxChannelTxChannelIdx        Referable Keys */
  { /*     0 */                    0u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPCM_Tp_oVCAN_RADAR_a235016c_Tx] */
  { /*     1 */                    0u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPDT_Tp_oVCAN_RADAR_92966f54_Tx] */
  { /*     2 */                    0u }   /* [/ActiveEcuC/EcuC/EcucPduCollection/TPCM_DirectTp_oVCAN_RADAR_a235016c_Tx] */
};
#define J1939TP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  J1939Tp_TxPduTxChannelTxChannelTableInd
**********************************************************************************************************************/
/** 
  \var    J1939Tp_TxPduTxChannelTxChannelTableInd
  \brief  the indexes of the 1:1 sorted relation pointing to J1939Tp_TxPduTxChannel
*/ 
#define J1939TP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(J1939Tp_TxPduTxChannelTxChannelTableIndType, J1939TP_CONST) J1939Tp_TxPduTxChannelTxChannelTableInd[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxPduTxChannelTxChannelTableInd      Referable Keys */
  /*     0 */                               0u,  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPCM_Tp_oVCAN_RADAR_a235016c_Tx] */
  /*     1 */                               1u,  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPDT_Tp_oVCAN_RADAR_92966f54_Tx] */
  /*     2 */                               2u   /* [/ActiveEcuC/EcuC/EcucPduCollection/TPCM_DirectTp_oVCAN_RADAR_a235016c_Tx] */
};
#define J1939TP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  J1939Tp_TxSdu
**********************************************************************************************************************/
/** 
  \var    J1939Tp_TxSdu
  \brief  List of transmitted SDUs
  \details
  Element                               Description
  PGN                                   PGN
  HasMetaData                           MetaData
  HasMetaDataDa                         MetaData DA
  IsDirectPrioConfigured                Is DirectPriority configured
  IsVariable                            Variable Length
  DirectPriority                        Priority of a direct frame.
  MetaDataGetterTARGET_ADDRESS_16Idx    the index of the 0:1 relation pointing to J1939Tp_MetaDataGetterTARGET_ADDRESS_16
  MetaDataSetterTARGET_ADDRESS_16Idx    the index of the 0:1 relation pointing to J1939Tp_MetaDataSetterTARGET_ADDRESS_16
  PduFormat                             PDU format
  PduLength                             PDU Length
  SduId                                 SDU ID
  TxChannelChannelIdx                   the index of the 0:1 relation pointing to J1939Tp_TxChannel
  TxPduDirectNPduIdx                    the index of the 0:1 relation pointing to J1939Tp_TxPdu
  TxSduStateIdx                         the index of the 1:1 relation pointing to J1939Tp_TxSduState
*/ 
#define J1939TP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(J1939Tp_TxSduType, J1939TP_CONST) J1939Tp_TxSdu[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PGN      HasMetaData  HasMetaDataDa  IsDirectPrioConfigured  IsVariable  DirectPriority  MetaDataGetterTARGET_ADDRESS_16Idx  MetaDataSetterTARGET_ADDRESS_16Idx  PduFormat                      PduLength  SduId                                                TxChannelChannelIdx  TxPduDirectNPduIdx  TxSduStateIdx        Referable Keys */
  { /*     0 */ 0xFECAu,        TRUE,          TRUE,                   TRUE,       TRUE,             6u,                                 0u,                                 0u, J1939TP_PDU2_PDUFORMATOFTXSDU,       22u, PduRConf_PduRDestPdu_DM1_D0_oVCAN_RADAR_ce78d82a_Tx,                  0u,                 2u,            0u }   /* [/ActiveEcuC/EcuC/EcucPduCollection/DM1_D0_oVCAN_RADAR_ce78d82a_Tx] */
};
#define J1939TP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  J1939Tp_TxPduState
**********************************************************************************************************************/
/** 
  \var    J1939Tp_TxPduState
  \brief  State of J1939Tp Tx PDU
*/ 
#define J1939TP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(J1939Tp_TxPduStateUType, J1939TP_VAR_NO_INIT) J1939Tp_TxPduState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPCM_Tp_oVCAN_RADAR_a235016c_Tx] */
  /*     1 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPDT_Tp_oVCAN_RADAR_92966f54_Tx] */
  /*     2 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPCM_DirectTp_oVCAN_RADAR_a235016c_Tx] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPCM_Tp_oVCAN_RADAR_a235016c_Tx] */
  /*     1 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPDT_Tp_oVCAN_RADAR_92966f54_Tx] */
  /*     2 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPCM_DirectTp_oVCAN_RADAR_a235016c_Tx] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPCM_Tp_oVCAN_RADAR_a235016c_Tx] */
  /*     1 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPDT_Tp_oVCAN_RADAR_92966f54_Tx] */
  /*     2 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPCM_DirectTp_oVCAN_RADAR_a235016c_Tx] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPCM_Tp_oVCAN_RADAR_a235016c_Tx] */
  /*     1 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPDT_Tp_oVCAN_RADAR_92966f54_Tx] */
  /*     2 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPCM_DirectTp_oVCAN_RADAR_a235016c_Tx] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPCM_Tp_oVCAN_RADAR_a235016c_Tx] */
  /*     1 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPDT_Tp_oVCAN_RADAR_92966f54_Tx] */
  /*     2 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPCM_DirectTp_oVCAN_RADAR_a235016c_Tx] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPCM_Tp_oVCAN_RADAR_a235016c_Tx] */
  /*     1 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPDT_Tp_oVCAN_RADAR_92966f54_Tx] */
  /*     2 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPCM_DirectTp_oVCAN_RADAR_a235016c_Tx] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPCM_Tp_oVCAN_RADAR_a235016c_Tx] */
  /*     1 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPDT_Tp_oVCAN_RADAR_92966f54_Tx] */
  /*     2 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPCM_DirectTp_oVCAN_RADAR_a235016c_Tx] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPCM_Tp_oVCAN_RADAR_a235016c_Tx] */
  /*     1 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPDT_Tp_oVCAN_RADAR_92966f54_Tx] */
  /*     2 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TPCM_DirectTp_oVCAN_RADAR_a235016c_Tx] */

#define J1939TP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  J1939Tp_TxSduState
**********************************************************************************************************************/
/** 
  \var    J1939Tp_TxSduState
  \brief  State of J1939Tp Tx SDU
*/ 
#define J1939TP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(J1939Tp_TxSduStateUType, J1939TP_VAR_NO_INIT) J1939Tp_TxSduState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/DM1_D0_oVCAN_RADAR_ce78d82a_Tx] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/DM1_D0_oVCAN_RADAR_ce78d82a_Tx] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/DM1_D0_oVCAN_RADAR_ce78d82a_Tx] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/DM1_D0_oVCAN_RADAR_ce78d82a_Tx] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/DM1_D0_oVCAN_RADAR_ce78d82a_Tx] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/DM1_D0_oVCAN_RADAR_ce78d82a_Tx] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/DM1_D0_oVCAN_RADAR_ce78d82a_Tx] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/DM1_D0_oVCAN_RADAR_ce78d82a_Tx] */

#define J1939TP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/
#define J1939TP_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
FUNC(uint32, J1939TP_CODE) J1939Tp_Mdt_Get_CAN_ID_32_CAN_ID_32( P2CONST(uint8, AUTOMATIC, J1939TP_APPL_DATA) metaDataPtr )
{
  uint32 metaDataValue = *(P2CONST(uint32, AUTOMATIC, J1939TP_APPL_DATA))(&metaDataPtr[0]);  /* PRQA S 0310, 3305 */  /* MD_CSL_MetaDataPointerCast */ 
  return (metaDataValue);
}

FUNC(uint16, J1939TP_CODE) J1939Tp_Mdt_Get_TARGET_ADDRESS_16_TARGET_ADDRESS_16( P2CONST(uint8, AUTOMATIC, J1939TP_APPL_DATA) metaDataPtr )
{
  uint16 metaDataValue = *(P2CONST(uint16, AUTOMATIC, J1939TP_APPL_DATA))(&metaDataPtr[0]);  /* PRQA S 0310, 3305 */  /* MD_CSL_MetaDataPointerCast */ 
  return (metaDataValue);
}

FUNC(void, J1939TP_CODE) J1939Tp_Mdt_Set_CAN_ID_32_CAN_ID_32( P2VAR(uint8, AUTOMATIC, J1939TP_APPL_DATA) metaDataPtr, uint32 item )
{
  *(P2VAR(uint32, AUTOMATIC, J1939TP_APPL_DATA))(&metaDataPtr[0]) = item;  /* PRQA S 0310, 3305 */  /* MD_CSL_MetaDataPointerCast */ 
  return;
}

FUNC(void, J1939TP_CODE) J1939Tp_Mdt_Set_TARGET_ADDRESS_16_TARGET_ADDRESS_16( P2VAR(uint8, AUTOMATIC, J1939TP_APPL_DATA) metaDataPtr, uint16 item )
{
  *(P2VAR(uint16, AUTOMATIC, J1939TP_APPL_DATA))(&metaDataPtr[0]) = item;  /* PRQA S 0310, 3305 */  /* MD_CSL_MetaDataPointerCast */ 
  return;
}

#define J1939TP_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "J1939Tp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/


/**********************************************************************************************************************
  END OF FILE: J1939Tp_Cfg.c
**********************************************************************************************************************/

