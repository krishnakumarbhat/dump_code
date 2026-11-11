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
 *            Module: EthTSyn
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EthTSyn_GeneratedSimpleTypes.h
 *   Generation Time: 2026-08-27 14:12:21
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
#ifndef ETHTSYN_GENERATED_SIMPLE_TYPES_H
#define ETHTSYN_GENERATED_SIMPLE_TYPES_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATIONS
 *********************************************************************************************************************/
/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 * GENERATED TYPES (NOT ComStackLib)
 *********************************************************************************************************************/
/**   \brief EthTSyn_TxCrcSecuredEnumType */
typedef enum eEthTSyn_TxCrcSecuredEnumType
{
  ETHTSYN_TX_CRC_SECURED_CRC_NOT_SUPPORTED = 0u,
  ETHTSYN_TX_CRC_SECURED_CRC_SUPPORTED = 1u
} EthTSyn_TxCrcSecuredEnumType;

/**   \brief EthTSyn_RxCrcValidatedEnumType */
typedef enum eEthTSyn_RxCrcValidatedEnumType
{
  ETHTSYN_RX_CRC_VALIDATED_CRC_IGNORED = 0u,
  ETHTSYN_RX_CRC_VALIDATED_CRC_NOT_VALIDATED = 1u,
  ETHTSYN_RX_CRC_VALIDATED_CRC_OPTIONAL = 2u,
  ETHTSYN_RX_CRC_VALIDATED_CRC_VALIDATED = 3u
} EthTSyn_RxCrcValidatedEnumType;

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  EthTSynPCSizeOfTypes  EthTSyn SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for EthTSyn_SizeOfAnnounceRcvSm */
typedef uint8 EthTSyn_SizeOfAnnounceRcvSmType;

/**   \brief  value based type definition for EthTSyn_SizeOfAnnounceRcvSmDyn */
typedef uint8 EthTSyn_SizeOfAnnounceRcvSmDynType;

/**   \brief  value based type definition for EthTSyn_SizeOfAnnounceSendSm */
typedef uint8 EthTSyn_SizeOfAnnounceSendSmType;

/**   \brief  value based type definition for EthTSyn_SizeOfAnnounceSendSmDyn */
typedef uint8 EthTSyn_SizeOfAnnounceSendSmDynType;

/**   \brief  value based type definition for EthTSyn_SizeOfBridgeTxMasterPort */
typedef uint8 EthTSyn_SizeOfBridgeTxMasterPortType;

/**   \brief  value based type definition for EthTSyn_SizeOfBridgeTxMasterPortDyn */
typedef uint8 EthTSyn_SizeOfBridgeTxMasterPortDynType;

/**   \brief  value based type definition for EthTSyn_SizeOfComCtrlEthIfCtrl */
typedef uint8 EthTSyn_SizeOfComCtrlEthIfCtrlType;

/**   \brief  value based type definition for EthTSyn_SizeOfComCtrlEthIfCtrlDyn */
typedef uint8 EthTSyn_SizeOfComCtrlEthIfCtrlDynType;

/**   \brief  value based type definition for EthTSyn_SizeOfComCtrlPhysPort */
typedef uint8 EthTSyn_SizeOfComCtrlPhysPortType;

/**   \brief  value based type definition for EthTSyn_SizeOfComCtrlPhysPortDyn */
typedef uint8 EthTSyn_SizeOfComCtrlPhysPortDynType;

/**   \brief  value based type definition for EthTSyn_SizeOfComCtrlPort */
typedef uint8 EthTSyn_SizeOfComCtrlPortType;

/**   \brief  value based type definition for EthTSyn_SizeOfComCtrlPortInd */
typedef uint8 EthTSyn_SizeOfComCtrlPortIndType;

/**   \brief  value based type definition for EthTSyn_SizeOfComCtrlTimeDomain */
typedef uint8 EthTSyn_SizeOfComCtrlTimeDomainType;

/**   \brief  value based type definition for EthTSyn_SizeOfCrcHndl */
typedef uint8 EthTSyn_SizeOfCrcHndlType;

/**   \brief  value based type definition for EthTSyn_SizeOfDestinationMac */
typedef uint8 EthTSyn_SizeOfDestinationMacType;

/**   \brief  value based type definition for EthTSyn_SizeOfDestinationMacInd */
typedef uint8 EthTSyn_SizeOfDestinationMacIndType;

/**   \brief  value based type definition for EthTSyn_SizeOfFupDataIdList */
typedef uint8 EthTSyn_SizeOfFupDataIdListType;

/**   \brief  value based type definition for EthTSyn_SizeOfFupRxHandler */
typedef uint8 EthTSyn_SizeOfFupRxHandlerType;

/**   \brief  value based type definition for EthTSyn_SizeOfMsgSentCbkBuf */
typedef uint8 EthTSyn_SizeOfMsgSentCbkBufType;

/**   \brief  value based type definition for EthTSyn_SizeOfOffsetTimeDomain */
typedef uint8 EthTSyn_SizeOfOffsetTimeDomainType;

/**   \brief  value based type definition for EthTSyn_SizeOfPdReqSm */
typedef uint8 EthTSyn_SizeOfPdReqSmType;

/**   \brief  value based type definition for EthTSyn_SizeOfPdReqSmDyn */
typedef uint8 EthTSyn_SizeOfPdReqSmDynType;

/**   \brief  value based type definition for EthTSyn_SizeOfPdReqTrcvDyn */
typedef uint8 EthTSyn_SizeOfPdReqTrcvDynType;

/**   \brief  value based type definition for EthTSyn_SizeOfPdRespSm */
typedef uint8 EthTSyn_SizeOfPdRespSmType;

/**   \brief  value based type definition for EthTSyn_SizeOfPdRespSmDyn */
typedef uint8 EthTSyn_SizeOfPdRespSmDynType;

/**   \brief  value based type definition for EthTSyn_SizeOfPortParamStatsDyn */
typedef uint8 EthTSyn_SizeOfPortParamStatsDynType;

/**   \brief  value based type definition for EthTSyn_SizeOfPortSyncSendSm */
typedef uint8 EthTSyn_SizeOfPortSyncSendSmType;

/**   \brief  value based type definition for EthTSyn_SizeOfPortSyncSendSmDyn */
typedef uint8 EthTSyn_SizeOfPortSyncSendSmDynType;

/**   \brief  value based type definition for EthTSyn_SizeOfRateMeas */
typedef uint8 EthTSyn_SizeOfRateMeasType;

/**   \brief  value based type definition for EthTSyn_SizeOfRateMeasBuf */
typedef uint8 EthTSyn_SizeOfRateMeasBufType;

/**   \brief  value based type definition for EthTSyn_SizeOfRateMeasDyn */
typedef uint8 EthTSyn_SizeOfRateMeasDynType;

/**   \brief  value based type definition for EthTSyn_SizeOfSiteSyncSyncTx */
typedef uint8 EthTSyn_SizeOfSiteSyncSyncTxType;

/**   \brief  value based type definition for EthTSyn_SizeOfSiteSyncSyncTxDyn */
typedef uint8 EthTSyn_SizeOfSiteSyncSyncTxDynType;

/**   \brief  value based type definition for EthTSyn_SizeOfSlaveRxData */
typedef uint8 EthTSyn_SizeOfSlaveRxDataType;

/**   \brief  value based type definition for EthTSyn_SizeOfSlaveRxDataHandler */
typedef uint8 EthTSyn_SizeOfSlaveRxDataHandlerType;

/**   \brief  value based type definition for EthTSyn_SizeOfSlaveRxMasterClockIdDyn */
typedef uint8 EthTSyn_SizeOfSlaveRxMasterClockIdDynType;

/**   \brief  value based type definition for EthTSyn_SizeOfSlaveRxSrcPortIdCheckClockId */
typedef uint8 EthTSyn_SizeOfSlaveRxSrcPortIdCheckClockIdType;

/**   \brief  value based type definition for EthTSyn_SizeOfSlaveSwitchIdxList */
typedef uint8 EthTSyn_SizeOfSlaveSwitchIdxListType;

/**   \brief  value based type definition for EthTSyn_SizeOfSwtTimeSyncSm */
typedef uint8 EthTSyn_SizeOfSwtTimeSyncSmType;

/**   \brief  value based type definition for EthTSyn_SizeOfSwtTimeSyncSmDyn */
typedef uint8 EthTSyn_SizeOfSwtTimeSyncSmDynType;

/**   \brief  value based type definition for EthTSyn_SizeOfSyncRcvSm */
typedef uint8 EthTSyn_SizeOfSyncRcvSmType;

/**   \brief  value based type definition for EthTSyn_SizeOfSyncRcvSmDyn */
typedef uint8 EthTSyn_SizeOfSyncRcvSmDynType;

/**   \brief  value based type definition for EthTSyn_SizeOfSyncSendSm */
typedef uint8 EthTSyn_SizeOfSyncSendSmType;

/**   \brief  value based type definition for EthTSyn_SizeOfSyncSendSmDyn */
typedef uint8 EthTSyn_SizeOfSyncSendSmDynType;

/**   \brief  value based type definition for EthTSyn_SizeOfTimeBaseUpdateCounter */
typedef uint8 EthTSyn_SizeOfTimeBaseUpdateCounterType;

/**   \brief  value based type definition for EthTSyn_SizeOfTimeBaseUpdateCounterDyn */
typedef uint8 EthTSyn_SizeOfTimeBaseUpdateCounterDynType;

/**   \brief  value based type definition for EthTSyn_SizeOfTxConfContext */
typedef uint8 EthTSyn_SizeOfTxConfContextType;

/**   \brief  value based type definition for EthTSyn_SizeOfTxConfContextDyn */
typedef uint8 EthTSyn_SizeOfTxConfContextDynType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  EthTSynPCIterableTypes  EthTSyn Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate EthTSyn_AnnounceRcvSm */
typedef uint8_least EthTSyn_AnnounceRcvSmIterType;

/**   \brief  type used to iterate EthTSyn_AnnounceSendSm */
typedef uint8_least EthTSyn_AnnounceSendSmIterType;

/**   \brief  type used to iterate EthTSyn_BridgeTxMasterPort */
typedef uint8_least EthTSyn_BridgeTxMasterPortIterType;

/**   \brief  type used to iterate EthTSyn_ComCtrlEthIfCtrl */
typedef uint8_least EthTSyn_ComCtrlEthIfCtrlIterType;

/**   \brief  type used to iterate EthTSyn_ComCtrlPhysPort */
typedef uint8_least EthTSyn_ComCtrlPhysPortIterType;

/**   \brief  type used to iterate EthTSyn_ComCtrlPort */
typedef uint8_least EthTSyn_ComCtrlPortIterType;

/**   \brief  type used to iterate EthTSyn_ComCtrlPortInd */
typedef uint8_least EthTSyn_ComCtrlPortIndIterType;

/**   \brief  type used to iterate EthTSyn_ComCtrlTimeDomain */
typedef uint8_least EthTSyn_ComCtrlTimeDomainIterType;

/**   \brief  type used to iterate EthTSyn_CrcHndl */
typedef uint8_least EthTSyn_CrcHndlIterType;

/**   \brief  type used to iterate EthTSyn_DestinationMac */
typedef uint8_least EthTSyn_DestinationMacIterType;

/**   \brief  type used to iterate EthTSyn_DestinationMacInd */
typedef uint8_least EthTSyn_DestinationMacIndIterType;

/**   \brief  type used to iterate EthTSyn_FupDataIdList */
typedef uint8_least EthTSyn_FupDataIdListIterType;

/**   \brief  type used to iterate EthTSyn_FupRxHandler */
typedef uint8_least EthTSyn_FupRxHandlerIterType;

/**   \brief  type used to iterate EthTSyn_MsgSentCbkBuf */
typedef uint8_least EthTSyn_MsgSentCbkBufIterType;

/**   \brief  type used to iterate EthTSyn_OffsetTimeDomain */
typedef uint8_least EthTSyn_OffsetTimeDomainIterType;

/**   \brief  type used to iterate EthTSyn_PdReqSm */
typedef uint8_least EthTSyn_PdReqSmIterType;

/**   \brief  type used to iterate EthTSyn_PdRespSm */
typedef uint8_least EthTSyn_PdRespSmIterType;

/**   \brief  type used to iterate EthTSyn_PortParamStatsDyn */
typedef uint8_least EthTSyn_PortParamStatsDynIterType;

/**   \brief  type used to iterate EthTSyn_PortSyncSendSm */
typedef uint8_least EthTSyn_PortSyncSendSmIterType;

/**   \brief  type used to iterate EthTSyn_RateMeas */
typedef uint8_least EthTSyn_RateMeasIterType;

/**   \brief  type used to iterate EthTSyn_RateMeasBuf */
typedef uint8_least EthTSyn_RateMeasBufIterType;

/**   \brief  type used to iterate EthTSyn_SiteSyncSyncTx */
typedef uint8_least EthTSyn_SiteSyncSyncTxIterType;

/**   \brief  type used to iterate EthTSyn_SlaveRxData */
typedef uint8_least EthTSyn_SlaveRxDataIterType;

/**   \brief  type used to iterate EthTSyn_SlaveRxDataHandler */
typedef uint8_least EthTSyn_SlaveRxDataHandlerIterType;

/**   \brief  type used to iterate EthTSyn_SlaveRxMasterClockIdDyn */
typedef uint8_least EthTSyn_SlaveRxMasterClockIdDynIterType;

/**   \brief  type used to iterate EthTSyn_SlaveRxSrcPortIdCheckClockId */
typedef uint8_least EthTSyn_SlaveRxSrcPortIdCheckClockIdIterType;

/**   \brief  type used to iterate EthTSyn_SlaveSwitchIdxList */
typedef uint8_least EthTSyn_SlaveSwitchIdxListIterType;

/**   \brief  type used to iterate EthTSyn_SwtTimeSyncSm */
typedef uint8_least EthTSyn_SwtTimeSyncSmIterType;

/**   \brief  type used to iterate EthTSyn_SyncRcvSm */
typedef uint8_least EthTSyn_SyncRcvSmIterType;

/**   \brief  type used to iterate EthTSyn_SyncSendSm */
typedef uint8_least EthTSyn_SyncSendSmIterType;

/**   \brief  type used to iterate EthTSyn_TimeBaseUpdateCounter */
typedef uint8_least EthTSyn_TimeBaseUpdateCounterIterType;

/**   \brief  type used to iterate EthTSyn_TxConfContext */
typedef uint8_least EthTSyn_TxConfContextIterType;

/** 
  \}
*/ 

/** 
  \defgroup  EthTSynPCIterableTypesWithSizeRelations  EthTSyn Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate EthTSyn_AnnounceRcvSmDyn */
typedef EthTSyn_AnnounceRcvSmIterType EthTSyn_AnnounceRcvSmDynIterType;

/**   \brief  type used to iterate EthTSyn_AnnounceSendSmDyn */
typedef EthTSyn_AnnounceSendSmIterType EthTSyn_AnnounceSendSmDynIterType;

/**   \brief  type used to iterate EthTSyn_BridgeTxMasterPortDyn */
typedef EthTSyn_BridgeTxMasterPortIterType EthTSyn_BridgeTxMasterPortDynIterType;

/**   \brief  type used to iterate EthTSyn_ComCtrlEthIfCtrlDyn */
typedef EthTSyn_ComCtrlEthIfCtrlIterType EthTSyn_ComCtrlEthIfCtrlDynIterType;

/**   \brief  type used to iterate EthTSyn_ComCtrlPhysPortDyn */
typedef EthTSyn_ComCtrlPhysPortIterType EthTSyn_ComCtrlPhysPortDynIterType;

/**   \brief  type used to iterate EthTSyn_PdReqSmDyn */
typedef EthTSyn_PdReqSmIterType EthTSyn_PdReqSmDynIterType;

/**   \brief  type used to iterate EthTSyn_PdReqTrcvDyn */
typedef EthTSyn_PdReqSmIterType EthTSyn_PdReqTrcvDynIterType;

/**   \brief  type used to iterate EthTSyn_PdRespSmDyn */
typedef EthTSyn_PdRespSmIterType EthTSyn_PdRespSmDynIterType;

/**   \brief  type used to iterate EthTSyn_PortSyncSendSmDyn */
typedef EthTSyn_PortSyncSendSmIterType EthTSyn_PortSyncSendSmDynIterType;

/**   \brief  type used to iterate EthTSyn_RateMeasDyn */
typedef EthTSyn_RateMeasIterType EthTSyn_RateMeasDynIterType;

/**   \brief  type used to iterate EthTSyn_SiteSyncSyncTxDyn */
typedef EthTSyn_SiteSyncSyncTxIterType EthTSyn_SiteSyncSyncTxDynIterType;

/**   \brief  type used to iterate EthTSyn_SwtTimeSyncSmDyn */
typedef EthTSyn_SwtTimeSyncSmIterType EthTSyn_SwtTimeSyncSmDynIterType;

/**   \brief  type used to iterate EthTSyn_SyncRcvSmDyn */
typedef EthTSyn_SyncRcvSmIterType EthTSyn_SyncRcvSmDynIterType;

/**   \brief  type used to iterate EthTSyn_SyncSendSmDyn */
typedef EthTSyn_SyncSendSmIterType EthTSyn_SyncSendSmDynIterType;

/**   \brief  type used to iterate EthTSyn_TimeBaseUpdateCounterDyn */
typedef EthTSyn_TimeBaseUpdateCounterIterType EthTSyn_TimeBaseUpdateCounterDynIterType;

/**   \brief  type used to iterate EthTSyn_TxConfContextDyn */
typedef EthTSyn_TxConfContextIterType EthTSyn_TxConfContextDynIterType;

/** 
  \}
*/ 

/** 
  \defgroup  EthTSynPCValueTypes  EthTSyn Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for EthTSyn_ComCtrlPortIdxOfAnnounceRcvSm */
typedef uint8 EthTSyn_ComCtrlPortIdxOfAnnounceRcvSmType;

/**   \brief  value based type definition for EthTSyn_MaxStepsRemovedOfAnnounceRcvSm */
typedef uint8 EthTSyn_MaxStepsRemovedOfAnnounceRcvSmType;

/**   \brief  value based type definition for EthTSyn_RxTimeoutOfAnnounceRcvSm */
typedef uint8 EthTSyn_RxTimeoutOfAnnounceRcvSmType;

/**   \brief  value based type definition for EthTSyn_SlaveRxDataIdxOfAnnounceRcvSm */
typedef uint8 EthTSyn_SlaveRxDataIdxOfAnnounceRcvSmType;

/**   \brief  value based type definition for EthTSyn_RxTimeoutCounterOfAnnounceRcvSmDyn */
typedef uint32 EthTSyn_RxTimeoutCounterOfAnnounceRcvSmDynType;

/**   \brief  value based type definition for EthTSyn_SmResetRequestedOfAnnounceRcvSmDyn */
typedef boolean EthTSyn_SmResetRequestedOfAnnounceRcvSmDynType;

/**   \brief  value based type definition for EthTSyn_StateOfAnnounceRcvSmDyn */
typedef uint8 EthTSyn_StateOfAnnounceRcvSmDynType;

/**   \brief  value based type definition for EthTSyn_AnnounceLogMsgIntervalOfAnnounceSendSm */
typedef sint8 EthTSyn_AnnounceLogMsgIntervalOfAnnounceSendSmType;

/**   \brief  value based type definition for EthTSyn_AnnounceTxCycleOfAnnounceSendSm */
typedef uint8 EthTSyn_AnnounceTxCycleOfAnnounceSendSmType;

/**   \brief  value based type definition for EthTSyn_ComCtrlPortIdxOfAnnounceSendSm */
typedef uint8 EthTSyn_ComCtrlPortIdxOfAnnounceSendSmType;

/**   \brief  value based type definition for EthTSyn_AnnounceCycleTimerOfAnnounceSendSmDyn */
typedef uint32 EthTSyn_AnnounceCycleTimerOfAnnounceSendSmDynType;

/**   \brief  value based type definition for EthTSyn_ResetRequestedOfAnnounceSendSmDyn */
typedef boolean EthTSyn_ResetRequestedOfAnnounceSendSmDynType;

/**   \brief  value based type definition for EthTSyn_SequenceIdOfAnnounceSendSmDyn */
typedef uint16 EthTSyn_SequenceIdOfAnnounceSendSmDynType;

/**   \brief  value based type definition for EthTSyn_StateOfAnnounceSendSmDyn */
typedef uint8 EthTSyn_StateOfAnnounceSendSmDynType;

/**   \brief  value based type definition for EthTSyn_ComCtrlPortIdxOfBridgeTxMasterPort */
typedef uint8 EthTSyn_ComCtrlPortIdxOfBridgeTxMasterPortType;

/**   \brief  value based type definition for EthTSyn_FupFwdStateOfBridgeTxMasterPortDyn */
typedef uint8 EthTSyn_FupFwdStateOfBridgeTxMasterPortDynType;

/**   \brief  value based type definition for EthTSyn_SyncFwdDelayNsOfBridgeTxMasterPortDyn */
typedef uint64 EthTSyn_SyncFwdDelayNsOfBridgeTxMasterPortDynType;

/**   \brief  value based type definition for EthTSyn_ComCtrlPortIndEndIdxOfComCtrlEthIfCtrl */
typedef uint8 EthTSyn_ComCtrlPortIndEndIdxOfComCtrlEthIfCtrlType;

/**   \brief  value based type definition for EthTSyn_ComCtrlPortIndStartIdxOfComCtrlEthIfCtrl */
typedef uint8 EthTSyn_ComCtrlPortIndStartIdxOfComCtrlEthIfCtrlType;

/**   \brief  value based type definition for EthTSyn_DestinationMacIndEndIdxOfComCtrlEthIfCtrl */
typedef uint8 EthTSyn_DestinationMacIndEndIdxOfComCtrlEthIfCtrlType;

/**   \brief  value based type definition for EthTSyn_DestinationMacIndStartIdxOfComCtrlEthIfCtrl */
typedef uint8 EthTSyn_DestinationMacIndStartIdxOfComCtrlEthIfCtrlType;

/**   \brief  value based type definition for EthTSyn_EthIfCtrlIdxOfComCtrlEthIfCtrl */
typedef uint8 EthTSyn_EthIfCtrlIdxOfComCtrlEthIfCtrlType;

/**   \brief  value based type definition for EthTSyn_ClockIdOfComCtrlEthIfCtrlDyn */
typedef uint64 EthTSyn_ClockIdOfComCtrlEthIfCtrlDynType;

/**   \brief  value based type definition for EthTSyn_LinkStateActiveOfComCtrlEthIfCtrlDyn */
typedef boolean EthTSyn_LinkStateActiveOfComCtrlEthIfCtrlDynType;

/**   \brief  value based type definition for EthTSyn_TxActiveOfComCtrlEthIfCtrlDyn */
typedef boolean EthTSyn_TxActiveOfComCtrlEthIfCtrlDynType;

/**   \brief  value based type definition for EthTSyn_AlwaysAsCapableOfComCtrlPhysPort */
typedef boolean EthTSyn_AlwaysAsCapableOfComCtrlPhysPortType;

/**   \brief  value based type definition for EthTSyn_DebounceTimerInitOfComCtrlPhysPort */
typedef uint8 EthTSyn_DebounceTimerInitOfComCtrlPhysPortType;

/**   \brief  value based type definition for EthTSyn_InitialPdelayNsOfComCtrlPhysPort */
typedef uint8 EthTSyn_InitialPdelayNsOfComCtrlPhysPortType;

/**   \brief  value based type definition for EthTSyn_UseStaticPdelayOfComCtrlPhysPort */
typedef boolean EthTSyn_UseStaticPdelayOfComCtrlPhysPortType;

/**   \brief  value based type definition for EthTSyn_AsCapableOfComCtrlPhysPortDyn */
typedef boolean EthTSyn_AsCapableOfComCtrlPhysPortDynType;

/**   \brief  value based type definition for EthTSyn_DebounceTimerOfComCtrlPhysPortDyn */
typedef uint32 EthTSyn_DebounceTimerOfComCtrlPhysPortDynType;

/**   \brief  value based type definition for EthTSyn_AnnounceSendSmIdxOfComCtrlPort */
typedef uint8 EthTSyn_AnnounceSendSmIdxOfComCtrlPortType;

/**   \brief  value based type definition for EthTSyn_AnnounceSendSmUsedOfComCtrlPort */
typedef boolean EthTSyn_AnnounceSendSmUsedOfComCtrlPortType;

/**   \brief  value based type definition for EthTSyn_ComCtrlEthIfCtrlIdxOfComCtrlPort */
typedef uint8 EthTSyn_ComCtrlEthIfCtrlIdxOfComCtrlPortType;

/**   \brief  value based type definition for EthTSyn_ComCtrlPhysPortIdxOfComCtrlPort */
typedef uint8 EthTSyn_ComCtrlPhysPortIdxOfComCtrlPortType;

/**   \brief  value based type definition for EthTSyn_ComCtrlTimeDomainIdxOfComCtrlPort */
typedef uint8 EthTSyn_ComCtrlTimeDomainIdxOfComCtrlPortType;

/**   \brief  value based type definition for EthTSyn_FramePrioOfComCtrlPort */
typedef uint8 EthTSyn_FramePrioOfComCtrlPortType;

/**   \brief  value based type definition for EthTSyn_NumberOfComCtrlPort */
typedef uint8 EthTSyn_NumberOfComCtrlPortType;

/**   \brief  value based type definition for EthTSyn_PdReqSmIdxOfComCtrlPort */
typedef uint8 EthTSyn_PdReqSmIdxOfComCtrlPortType;

/**   \brief  value based type definition for EthTSyn_PdReqSmUsedOfComCtrlPort */
typedef boolean EthTSyn_PdReqSmUsedOfComCtrlPortType;

/**   \brief  value based type definition for EthTSyn_PdRespSmIdxOfComCtrlPort */
typedef uint8 EthTSyn_PdRespSmIdxOfComCtrlPortType;

/**   \brief  value based type definition for EthTSyn_PdRespSmUsedOfComCtrlPort */
typedef boolean EthTSyn_PdRespSmUsedOfComCtrlPortType;

/**   \brief  value based type definition for EthTSyn_PortParamStatsDynIdxOfComCtrlPort */
typedef uint8 EthTSyn_PortParamStatsDynIdxOfComCtrlPortType;

/**   \brief  value based type definition for EthTSyn_PortParamStatsDynUsedOfComCtrlPort */
typedef boolean EthTSyn_PortParamStatsDynUsedOfComCtrlPortType;

/**   \brief  value based type definition for EthTSyn_PortSyncSendSmIdxOfComCtrlPort */
typedef uint8 EthTSyn_PortSyncSendSmIdxOfComCtrlPortType;

/**   \brief  value based type definition for EthTSyn_PortSyncSendSmUsedOfComCtrlPort */
typedef boolean EthTSyn_PortSyncSendSmUsedOfComCtrlPortType;

/**   \brief  value based type definition for EthTSyn_SlaveRxDataHandlerIdxOfComCtrlPort */
typedef uint8 EthTSyn_SlaveRxDataHandlerIdxOfComCtrlPortType;

/**   \brief  value based type definition for EthTSyn_SlaveRxDataHandlerUsedOfComCtrlPort */
typedef boolean EthTSyn_SlaveRxDataHandlerUsedOfComCtrlPortType;

/**   \brief  value based type definition for EthTSyn_SyncSendSmIdxOfComCtrlPort */
typedef uint8 EthTSyn_SyncSendSmIdxOfComCtrlPortType;

/**   \brief  value based type definition for EthTSyn_SyncSendSmUsedOfComCtrlPort */
typedef boolean EthTSyn_SyncSendSmUsedOfComCtrlPortType;

/**   \brief  value based type definition for EthTSyn_ComCtrlPortInd */
typedef uint8 EthTSyn_ComCtrlPortIndType;

/**   \brief  value based type definition for EthTSyn_ComCtrlPortEndIdxOfComCtrlTimeDomain */
typedef uint8 EthTSyn_ComCtrlPortEndIdxOfComCtrlTimeDomainType;

/**   \brief  value based type definition for EthTSyn_ComCtrlPortStartIdxOfComCtrlTimeDomain */
typedef uint8 EthTSyn_ComCtrlPortStartIdxOfComCtrlTimeDomainType;

/**   \brief  value based type definition for EthTSyn_DestinationMacIdxOfComCtrlTimeDomain */
typedef uint8 EthTSyn_DestinationMacIdxOfComCtrlTimeDomainType;

/**   \brief  value based type definition for EthTSyn_IdOfComCtrlTimeDomain */
typedef uint8 EthTSyn_IdOfComCtrlTimeDomainType;

/**   \brief  value based type definition for EthTSyn_OffsetTimeDomainEndIdxOfComCtrlTimeDomain */
typedef uint8 EthTSyn_OffsetTimeDomainEndIdxOfComCtrlTimeDomainType;

/**   \brief  value based type definition for EthTSyn_OffsetTimeDomainStartIdxOfComCtrlTimeDomain */
typedef uint8 EthTSyn_OffsetTimeDomainStartIdxOfComCtrlTimeDomainType;

/**   \brief  value based type definition for EthTSyn_OffsetTimeDomainUsedOfComCtrlTimeDomain */
typedef boolean EthTSyn_OffsetTimeDomainUsedOfComCtrlTimeDomainType;

/**   \brief  value based type definition for EthTSyn_FupDataIdListEndIdxOfCrcHndl */
typedef uint8 EthTSyn_FupDataIdListEndIdxOfCrcHndlType;

/**   \brief  value based type definition for EthTSyn_FupDataIdListStartIdxOfCrcHndl */
typedef uint8 EthTSyn_FupDataIdListStartIdxOfCrcHndlType;

/**   \brief  value based type definition for EthTSyn_Byte0OfDestinationMac */
typedef uint8 EthTSyn_Byte0OfDestinationMacType;

/**   \brief  value based type definition for EthTSyn_Byte1OfDestinationMac */
typedef uint8 EthTSyn_Byte1OfDestinationMacType;

/**   \brief  value based type definition for EthTSyn_Byte2OfDestinationMac */
typedef uint8 EthTSyn_Byte2OfDestinationMacType;

/**   \brief  value based type definition for EthTSyn_Byte3OfDestinationMac */
typedef uint8 EthTSyn_Byte3OfDestinationMacType;

/**   \brief  value based type definition for EthTSyn_Byte4OfDestinationMac */
typedef uint8 EthTSyn_Byte4OfDestinationMacType;

/**   \brief  value based type definition for EthTSyn_Byte5OfDestinationMac */
typedef uint8 EthTSyn_Byte5OfDestinationMacType;

/**   \brief  value based type definition for EthTSyn_DestinationMacInd */
typedef uint8 EthTSyn_DestinationMacIndType;

/**   \brief  value based type definition for EthTSyn_FupDataIdList */
typedef uint8 EthTSyn_FupDataIdListType;

/**   \brief  value based type definition for EthTSyn_ComCtrlPortExternalIdxOfFupRxHandler */
typedef uint8 EthTSyn_ComCtrlPortExternalIdxOfFupRxHandlerType;

/**   \brief  value based type definition for EthTSyn_CrcFlagsRxValidatedOfFupRxHandler */
typedef uint8 EthTSyn_CrcFlagsRxValidatedOfFupRxHandlerType;

/**   \brief  value based type definition for EthTSyn_CrcHndlIdxOfFupRxHandler */
typedef uint8 EthTSyn_CrcHndlIdxOfFupRxHandlerType;

/**   \brief  value based type definition for EthTSyn_CrcHndlUsedOfFupRxHandler */
typedef boolean EthTSyn_CrcHndlUsedOfFupRxHandlerType;

/**   \brief  value based type definition for EthTSyn_FupCorrFieldThresholdNsOfFupRxHandler */
typedef uint64 EthTSyn_FupCorrFieldThresholdNsOfFupRxHandlerType;

/**   \brief  value based type definition for EthTSyn_TimeValidationEnabledOfFupRxHandler */
typedef boolean EthTSyn_TimeValidationEnabledOfFupRxHandlerType;

/**   \brief  value based type definition for EthTSyn_MsgSentCbkBuf */
typedef uint8 EthTSyn_MsgSentCbkBufType;

/**   \brief  value based type definition for EthTSyn_IdOfOffsetTimeDomain */
typedef uint8 EthTSyn_IdOfOffsetTimeDomainType;

/**   \brief  value based type definition for EthTSyn_AverageWeightOfPdReqSm */
typedef uint8 EthTSyn_AverageWeightOfPdReqSmType;

/**   \brief  value based type definition for EthTSyn_ComCtrlPortIdxOfPdReqSm */
typedef uint8 EthTSyn_ComCtrlPortIdxOfPdReqSmType;

/**   \brief  value based type definition for EthTSyn_LogMsgIntervalOfPdReqSm */
typedef sint8 EthTSyn_LogMsgIntervalOfPdReqSmType;

/**   \brief  value based type definition for EthTSyn_MaxLostResponsesOfPdReqSm */
typedef uint8 EthTSyn_MaxLostResponsesOfPdReqSmType;

/**   \brief  value based type definition for EthTSyn_PdReqPeriodOfPdReqSm */
typedef uint8 EthTSyn_PdReqPeriodOfPdReqSmType;

/**   \brief  value based type definition for EthTSyn_PdRespTimeoutOfPdReqSm */
typedef uint8 EthTSyn_PdRespTimeoutOfPdReqSmType;

/**   \brief  value based type definition for EthTSyn_PdThresholdOfPdReqSm */
typedef uint32 EthTSyn_PdThresholdOfPdReqSmType;

/**   \brief  value based type definition for EthTSyn_TimeValidationEnabledOfPdReqSm */
typedef boolean EthTSyn_TimeValidationEnabledOfPdReqSmType;

/**   \brief  value based type definition for EthTSyn_TxConfContextIdxOfPdReqSm */
typedef uint8 EthTSyn_TxConfContextIdxOfPdReqSmType;

/**   \brief  value based type definition for EthTSyn_FirstPdelayOfPdReqSmDyn */
typedef boolean EthTSyn_FirstPdelayOfPdReqSmDynType;

/**   \brief  value based type definition for EthTSyn_LostResponseCntOfPdReqSmDyn */
typedef uint8 EthTSyn_LostResponseCntOfPdReqSmDynType;

/**   \brief  value based type definition for EthTSyn_RespTimeoutCntOfPdReqSmDyn */
typedef uint32 EthTSyn_RespTimeoutCntOfPdReqSmDynType;

/**   \brief  value based type definition for EthTSyn_SequenceIdOfPdReqSmDyn */
typedef uint16 EthTSyn_SequenceIdOfPdReqSmDynType;

/**   \brief  value based type definition for EthTSyn_SmResetRequestedOfPdReqSmDyn */
typedef boolean EthTSyn_SmResetRequestedOfPdReqSmDynType;

/**   \brief  value based type definition for EthTSyn_StateOfPdReqSmDyn */
typedef uint8 EthTSyn_StateOfPdReqSmDynType;

/**   \brief  value based type definition for EthTSyn_TxIntervalCntOfPdReqSmDyn */
typedef uint32 EthTSyn_TxIntervalCntOfPdReqSmDynType;

/**   \brief  value based type definition for EthTSyn_PdReqEgrTsProvidedOfPdReqTrcvDyn */
typedef boolean EthTSyn_PdReqEgrTsProvidedOfPdReqTrcvDynType;

/**   \brief  value based type definition for EthTSyn_RespClockIdOfPdReqTrcvDyn */
typedef uint64 EthTSyn_RespClockIdOfPdReqTrcvDynType;

/**   \brief  value based type definition for EthTSyn_RespPortNumOfPdReqTrcvDyn */
typedef uint16 EthTSyn_RespPortNumOfPdReqTrcvDynType;

/**   \brief  value based type definition for EthTSyn_StateOfPdReqTrcvDyn */
typedef uint8 EthTSyn_StateOfPdReqTrcvDynType;

/**   \brief  value based type definition for EthTSyn_ComCtrlPortIdxOfPdRespSm */
typedef uint8 EthTSyn_ComCtrlPortIdxOfPdRespSmType;

/**   \brief  value based type definition for EthTSyn_TimeValidationEnabledOfPdRespSm */
typedef boolean EthTSyn_TimeValidationEnabledOfPdRespSmType;

/**   \brief  value based type definition for EthTSyn_TxConfContextIdxOfPdRespSm */
typedef uint8 EthTSyn_TxConfContextIdxOfPdRespSmType;

/**   \brief  value based type definition for EthTSyn_RequestorClockIdOfPdRespSmDyn */
typedef uint64 EthTSyn_RequestorClockIdOfPdRespSmDynType;

/**   \brief  value based type definition for EthTSyn_RequestorPortNumOfPdRespSmDyn */
typedef uint16 EthTSyn_RequestorPortNumOfPdRespSmDynType;

/**   \brief  value based type definition for EthTSyn_SequenceIdOfPdRespSmDyn */
typedef uint16 EthTSyn_SequenceIdOfPdRespSmDynType;

/**   \brief  value based type definition for EthTSyn_SmResetRequestedOfPdRespSmDyn */
typedef boolean EthTSyn_SmResetRequestedOfPdRespSmDynType;

/**   \brief  value based type definition for EthTSyn_StateOfPdRespSmDyn */
typedef uint8 EthTSyn_StateOfPdRespSmDynType;

/**   \brief  value based type definition for EthTSyn_PdLostRespExceededCountOfPortParamStatsDyn */
typedef uint32 EthTSyn_PdLostRespExceededCountOfPortParamStatsDynType;

/**   \brief  value based type definition for EthTSyn_RxAnnounceCountOfPortParamStatsDyn */
typedef uint32 EthTSyn_RxAnnounceCountOfPortParamStatsDynType;

/**   \brief  value based type definition for EthTSyn_RxDiscardCountOfPortParamStatsDyn */
typedef uint32 EthTSyn_RxDiscardCountOfPortParamStatsDynType;

/**   \brief  value based type definition for EthTSyn_RxFupCountOfPortParamStatsDyn */
typedef uint32 EthTSyn_RxFupCountOfPortParamStatsDynType;

/**   \brief  value based type definition for EthTSyn_RxPdReqCountOfPortParamStatsDyn */
typedef uint32 EthTSyn_RxPdReqCountOfPortParamStatsDynType;

/**   \brief  value based type definition for EthTSyn_RxPdRespCountOfPortParamStatsDyn */
typedef uint32 EthTSyn_RxPdRespCountOfPortParamStatsDynType;

/**   \brief  value based type definition for EthTSyn_RxPdRespFupCountOfPortParamStatsDyn */
typedef uint32 EthTSyn_RxPdRespFupCountOfPortParamStatsDynType;

/**   \brief  value based type definition for EthTSyn_RxSyncCountOfPortParamStatsDyn */
typedef uint32 EthTSyn_RxSyncCountOfPortParamStatsDynType;

/**   \brief  value based type definition for EthTSyn_TxAnnounceCountOfPortParamStatsDyn */
typedef uint32 EthTSyn_TxAnnounceCountOfPortParamStatsDynType;

/**   \brief  value based type definition for EthTSyn_TxFupCountOfPortParamStatsDyn */
typedef uint32 EthTSyn_TxFupCountOfPortParamStatsDynType;

/**   \brief  value based type definition for EthTSyn_TxPdReqCountOfPortParamStatsDyn */
typedef uint32 EthTSyn_TxPdReqCountOfPortParamStatsDynType;

/**   \brief  value based type definition for EthTSyn_TxPdRespCountOfPortParamStatsDyn */
typedef uint32 EthTSyn_TxPdRespCountOfPortParamStatsDynType;

/**   \brief  value based type definition for EthTSyn_TxPdRespFupCountOfPortParamStatsDyn */
typedef uint32 EthTSyn_TxPdRespFupCountOfPortParamStatsDynType;

/**   \brief  value based type definition for EthTSyn_TxSyncCountOfPortParamStatsDyn */
typedef uint32 EthTSyn_TxSyncCountOfPortParamStatsDynType;

/**   \brief  value based type definition for EthTSyn_ComCtrlPortIdxOfPortSyncSendSm */
typedef uint8 EthTSyn_ComCtrlPortIdxOfPortSyncSendSmType;

/**   \brief  value based type definition for EthTSyn_MsgSentCbkBufEndIdxOfPortSyncSendSm */
typedef uint8 EthTSyn_MsgSentCbkBufEndIdxOfPortSyncSendSmType;

/**   \brief  value based type definition for EthTSyn_MsgSentCbkBufLengthOfPortSyncSendSm */
typedef uint8 EthTSyn_MsgSentCbkBufLengthOfPortSyncSendSmType;

/**   \brief  value based type definition for EthTSyn_MsgSentCbkBufStartIdxOfPortSyncSendSm */
typedef uint8 EthTSyn_MsgSentCbkBufStartIdxOfPortSyncSendSmType;

/**   \brief  value based type definition for EthTSyn_MsgSentCbkBufUsedOfPortSyncSendSm */
typedef boolean EthTSyn_MsgSentCbkBufUsedOfPortSyncSendSmType;

/**   \brief  value based type definition for EthTSyn_TimeValidationEnabledOfPortSyncSendSm */
typedef boolean EthTSyn_TimeValidationEnabledOfPortSyncSendSmType;

/**   \brief  value based type definition for EthTSyn_TxConfContextIdxOfPortSyncSendSm */
typedef uint8 EthTSyn_TxConfContextIdxOfPortSyncSendSmType;

/**   \brief  value based type definition for EthTSyn_StateOfPortSyncSendSmDyn */
typedef uint8 EthTSyn_StateOfPortSyncSendSmDynType;

/**   \brief  value based type definition for EthTSyn_MaxOutOfSyncCntOfRateMeas */
typedef uint8 EthTSyn_MaxOutOfSyncCntOfRateMeasType;

/**   \brief  value based type definition for EthTSyn_NrSyncCyclesForOfsCorrOfRateMeas */
typedef uint8 EthTSyn_NrSyncCyclesForOfsCorrOfRateMeasType;

/**   \brief  value based type definition for EthTSyn_OfsJumpCorrThresholdNsOfRateMeas */
typedef uint8 EthTSyn_OfsJumpCorrThresholdNsOfRateMeasType;

/**   \brief  value based type definition for EthTSyn_RateMeasBufEndIdxOfRateMeas */
typedef uint8 EthTSyn_RateMeasBufEndIdxOfRateMeasType;

/**   \brief  value based type definition for EthTSyn_RateMeasBufLengthOfRateMeas */
typedef uint8 EthTSyn_RateMeasBufLengthOfRateMeasType;

/**   \brief  value based type definition for EthTSyn_RateMeasBufStartIdxOfRateMeas */
typedef uint8 EthTSyn_RateMeasBufStartIdxOfRateMeasType;

/**   \brief  value based type definition for EthTSyn_RateRatioMaxOfRateMeas */
typedef float64 EthTSyn_RateRatioMaxOfRateMeasType;

/**   \brief  value based type definition for EthTSyn_RateRatioMinOfRateMeas */
typedef float64 EthTSyn_RateRatioMinOfRateMeasType;

/**   \brief  value based type definition for EthTSyn_SyncPrecisionLimitNsOfRateMeas */
typedef uint8 EthTSyn_SyncPrecisionLimitNsOfRateMeasType;

/**   \brief  value based type definition for EthTSyn_UseInitialOffsetCorrectionOfRateMeas */
typedef boolean EthTSyn_UseInitialOffsetCorrectionOfRateMeasType;

/**   \brief  value based type definition for EthTSyn_AccumulatedMasterTimeDiffOfRateMeasBuf */
typedef float64 EthTSyn_AccumulatedMasterTimeDiffOfRateMeasBufType;

/**   \brief  value based type definition for EthTSyn_AccumulatedSwtTimeDiffOfRateMeasBuf */
typedef float64 EthTSyn_AccumulatedSwtTimeDiffOfRateMeasBufType;

/**   \brief  value based type definition for EthTSyn_ActiveNrOfSyncCyclesOfRateMeasBuf */
typedef uint8 EthTSyn_ActiveNrOfSyncCyclesOfRateMeasBufType;

/**   \brief  value based type definition for EthTSyn_ActiveOfRateMeasBuf */
typedef boolean EthTSyn_ActiveOfRateMeasBufType;

/**   \brief  value based type definition for EthTSyn_LastCorrectedOffsetNsOfRateMeasDyn */
typedef sint64 EthTSyn_LastCorrectedOffsetNsOfRateMeasDynType;

/**   \brief  value based type definition for EthTSyn_OutOfSyncCntOfRateMeasDyn */
typedef uint8 EthTSyn_OutOfSyncCntOfRateMeasDynType;

/**   \brief  value based type definition for EthTSyn_StateOfRateMeasDyn */
typedef uint8 EthTSyn_StateOfRateMeasDynType;

/**   \brief  value based type definition for EthTSyn_SyncCycleCounterOfRateMeasDyn */
typedef uint8 EthTSyn_SyncCycleCounterOfRateMeasDynType;

/**   \brief  value based type definition for EthTSyn_SyncCycleCounterRestartedOfRateMeasDyn */
typedef boolean EthTSyn_SyncCycleCounterRestartedOfRateMeasDynType;

/**   \brief  value based type definition for EthTSyn_WasSyncReachedOfRateMeasDyn */
typedef boolean EthTSyn_WasSyncReachedOfRateMeasDynType;

/**   \brief  value based type definition for EthTSyn_BridgeTxMasterPortEndIdxOfSiteSyncSyncTx */
typedef uint8 EthTSyn_BridgeTxMasterPortEndIdxOfSiteSyncSyncTxType;

/**   \brief  value based type definition for EthTSyn_BridgeTxMasterPortStartIdxOfSiteSyncSyncTx */
typedef uint8 EthTSyn_BridgeTxMasterPortStartIdxOfSiteSyncSyncTxType;

/**   \brief  value based type definition for EthTSyn_NumMsgFwdRetryOfSiteSyncSyncTx */
typedef uint8 EthTSyn_NumMsgFwdRetryOfSiteSyncSyncTxType;

/**   \brief  value based type definition for EthTSyn_FwdRetryCntOfSiteSyncSyncTxDyn */
typedef uint8 EthTSyn_FwdRetryCntOfSiteSyncSyncTxDynType;

/**   \brief  value based type definition for EthTSyn_StateOfSiteSyncSyncTxDyn */
typedef uint8 EthTSyn_StateOfSiteSyncSyncTxDynType;

/**   \brief  value based type definition for EthTSyn_AnnounceRcvSmIdxOfSlaveRxData */
typedef uint8 EthTSyn_AnnounceRcvSmIdxOfSlaveRxDataType;

/**   \brief  value based type definition for EthTSyn_AnnounceRcvSmUsedOfSlaveRxData */
typedef boolean EthTSyn_AnnounceRcvSmUsedOfSlaveRxDataType;

/**   \brief  value based type definition for EthTSyn_SlaveRxMasterClockIdDynIdxOfSlaveRxData */
typedef uint8 EthTSyn_SlaveRxMasterClockIdDynIdxOfSlaveRxDataType;

/**   \brief  value based type definition for EthTSyn_SlaveRxMasterClockIdDynUsedOfSlaveRxData */
typedef boolean EthTSyn_SlaveRxMasterClockIdDynUsedOfSlaveRxDataType;

/**   \brief  value based type definition for EthTSyn_SlaveRxSrcPortIdCheckClockIdIdxOfSlaveRxData */
typedef uint8 EthTSyn_SlaveRxSrcPortIdCheckClockIdIdxOfSlaveRxDataType;

/**   \brief  value based type definition for EthTSyn_SlaveRxSrcPortIdCheckClockIdUsedOfSlaveRxData */
typedef boolean EthTSyn_SlaveRxSrcPortIdCheckClockIdUsedOfSlaveRxDataType;

/**   \brief  value based type definition for EthTSyn_SyncRcvSmIdxOfSlaveRxData */
typedef uint8 EthTSyn_SyncRcvSmIdxOfSlaveRxDataType;

/**   \brief  value based type definition for EthTSyn_ComCtrlPortIdxOfSlaveRxDataHandler */
typedef uint8 EthTSyn_ComCtrlPortIdxOfSlaveRxDataHandlerType;

/**   \brief  value based type definition for EthTSyn_SlaveRxDataExternalIdxOfSlaveRxDataHandler */
typedef uint8 EthTSyn_SlaveRxDataExternalIdxOfSlaveRxDataHandlerType;

/**   \brief  value based type definition for EthTSyn_ValidMasterClockIdOfSlaveRxMasterClockIdDyn */
typedef uint64 EthTSyn_ValidMasterClockIdOfSlaveRxMasterClockIdDynType;

/**   \brief  value based type definition for EthTSyn_ValidMasterSetOfSlaveRxMasterClockIdDyn */
typedef boolean EthTSyn_ValidMasterSetOfSlaveRxMasterClockIdDynType;

/**   \brief  value based type definition for EthTSyn_SlaveRxSrcPortIdCheckClockId */
typedef uint8 EthTSyn_SlaveRxSrcPortIdCheckClockIdType;

/**   \brief  value based type definition for EthTSyn_SlaveSwitchIdxList */
typedef uint8 EthTSyn_SlaveSwitchIdxListType;

/**   \brief  value based type definition for EthTSyn_ApplyRateRatioToSlaveSwitchesOfSwtTimeSyncSm */
typedef boolean EthTSyn_ApplyRateRatioToSlaveSwitchesOfSwtTimeSyncSmType;

/**   \brief  value based type definition for EthTSyn_EthIfSwitchIdxOfSwtTimeSyncSm */
typedef uint8 EthTSyn_EthIfSwitchIdxOfSwtTimeSyncSmType;

/**   \brief  value based type definition for EthTSyn_RateMeasIdxOfSwtTimeSyncSm */
typedef uint8 EthTSyn_RateMeasIdxOfSwtTimeSyncSmType;

/**   \brief  value based type definition for EthTSyn_SlaveSwitchIdxListEndIdxOfSwtTimeSyncSm */
typedef uint8 EthTSyn_SlaveSwitchIdxListEndIdxOfSwtTimeSyncSmType;

/**   \brief  value based type definition for EthTSyn_SlaveSwitchIdxListStartIdxOfSwtTimeSyncSm */
typedef uint8 EthTSyn_SlaveSwitchIdxListStartIdxOfSwtTimeSyncSmType;

/**   \brief  value based type definition for EthTSyn_SlaveSwitchIdxListUsedOfSwtTimeSyncSm */
typedef boolean EthTSyn_SlaveSwitchIdxListUsedOfSwtTimeSyncSmType;

/**   \brief  value based type definition for EthTSyn_SyncEventTimeoutOfSwtTimeSyncSm */
typedef uint8 EthTSyn_SyncEventTimeoutOfSwtTimeSyncSmType;

/**   \brief  value based type definition for EthTSyn_StateOfSwtTimeSyncSmDyn */
typedef uint8 EthTSyn_StateOfSwtTimeSyncSmDynType;

/**   \brief  value based type definition for EthTSyn_SyncEventTimeoutCntOfSwtTimeSyncSmDyn */
typedef uint32 EthTSyn_SyncEventTimeoutCntOfSwtTimeSyncSmDynType;

/**   \brief  value based type definition for EthTSyn_FollowUpRxTimeoutOfSyncRcvSm */
typedef uint8 EthTSyn_FollowUpRxTimeoutOfSyncRcvSmType;

/**   \brief  value based type definition for EthTSyn_FupRxHandlerIdxOfSyncRcvSm */
typedef uint8 EthTSyn_FupRxHandlerIdxOfSyncRcvSmType;

/**   \brief  value based type definition for EthTSyn_PortParamStatsDynIdxOfSyncRcvSm */
typedef uint8 EthTSyn_PortParamStatsDynIdxOfSyncRcvSmType;

/**   \brief  value based type definition for EthTSyn_PortParamStatsDynUsedOfSyncRcvSm */
typedef boolean EthTSyn_PortParamStatsDynUsedOfSyncRcvSmType;

/**   \brief  value based type definition for EthTSyn_AnySyncReceivedOfSyncRcvSmDyn */
typedef boolean EthTSyn_AnySyncReceivedOfSyncRcvSmDynType;

/**   \brief  value based type definition for EthTSyn_FupRxTimeoutCntOfSyncRcvSmDyn */
typedef uint32 EthTSyn_FupRxTimeoutCntOfSyncRcvSmDynType;

/**   \brief  value based type definition for EthTSyn_ResetRequestedOfSyncRcvSmDyn */
typedef boolean EthTSyn_ResetRequestedOfSyncRcvSmDynType;

/**   \brief  value based type definition for EthTSyn_StateOfSyncRcvSmDyn */
typedef uint8 EthTSyn_StateOfSyncRcvSmDynType;

/**   \brief  value based type definition for EthTSyn_SyncSequenceIdOfSyncRcvSmDyn */
typedef uint16 EthTSyn_SyncSequenceIdOfSyncRcvSmDynType;

/**   \brief  value based type definition for EthTSyn_SyncSrcClockIdOfSyncRcvSmDyn */
typedef uint64 EthTSyn_SyncSrcClockIdOfSyncRcvSmDynType;

/**   \brief  value based type definition for EthTSyn_SyncSrcPortNumOfSyncRcvSmDyn */
typedef uint16 EthTSyn_SyncSrcPortNumOfSyncRcvSmDynType;

/**   \brief  value based type definition for EthTSyn_CrcHndlIdxOfSyncSendSm */
typedef uint8 EthTSyn_CrcHndlIdxOfSyncSendSmType;

/**   \brief  value based type definition for EthTSyn_CrcHndlUsedOfSyncSendSm */
typedef boolean EthTSyn_CrcHndlUsedOfSyncSendSmType;

/**   \brief  value based type definition for EthTSyn_CrcTimeFlagsOfSyncSendSm */
typedef uint8 EthTSyn_CrcTimeFlagsOfSyncSendSmType;

/**   \brief  value based type definition for EthTSyn_CyclicMsgResumeCntOfSyncSendSm */
typedef uint8 EthTSyn_CyclicMsgResumeCntOfSyncSendSmType;

/**   \brief  value based type definition for EthTSyn_FupTxLenOfSyncSendSm */
typedef uint8 EthTSyn_FupTxLenOfSyncSendSmType;

/**   \brief  value based type definition for EthTSyn_ImmediateTimeSyncOfSyncSendSm */
typedef boolean EthTSyn_ImmediateTimeSyncOfSyncSendSmType;

/**   \brief  value based type definition for EthTSyn_PortSyncSendSmIdxOfSyncSendSm */
typedef uint8 EthTSyn_PortSyncSendSmIdxOfSyncSendSmType;

/**   \brief  value based type definition for EthTSyn_SyncLogMsgIntervalOfSyncSendSm */
typedef sint8 EthTSyn_SyncLogMsgIntervalOfSyncSendSmType;

/**   \brief  value based type definition for EthTSyn_SyncSendIntervalOfSyncSendSm */
typedef uint8 EthTSyn_SyncSendIntervalOfSyncSendSmType;

/**   \brief  value based type definition for EthTSyn_TimeBaseUpdateCounterIdxOfSyncSendSm */
typedef uint8 EthTSyn_TimeBaseUpdateCounterIdxOfSyncSendSmType;

/**   \brief  value based type definition for EthTSyn_TimeBaseUpdateCounterUsedOfSyncSendSm */
typedef boolean EthTSyn_TimeBaseUpdateCounterUsedOfSyncSendSmType;

/**   \brief  value based type definition for EthTSyn_FupCorrFieldOfSyncSendSmDyn */
typedef uint64 EthTSyn_FupCorrFieldOfSyncSendSmDynType;

/**   \brief  value based type definition for EthTSyn_SequenceIdOfSyncSendSmDyn */
typedef uint16 EthTSyn_SequenceIdOfSyncSendSmDynType;

/**   \brief  value based type definition for EthTSyn_SmResetRequestedOfSyncSendSmDyn */
typedef boolean EthTSyn_SmResetRequestedOfSyncSendSmDynType;

/**   \brief  value based type definition for EthTSyn_StateOfSyncSendSmDyn */
typedef uint8 EthTSyn_StateOfSyncSendSmDynType;

/**   \brief  value based type definition for EthTSyn_TxIntervalCntOfSyncSendSmDyn */
typedef uint32 EthTSyn_TxIntervalCntOfSyncSendSmDynType;

/**   \brief  value based type definition for EthTSyn_UpdatedOfTimeBaseUpdateCounterDyn */
typedef boolean EthTSyn_UpdatedOfTimeBaseUpdateCounterDynType;

/**   \brief  value based type definition for EthTSyn_ValueOfTimeBaseUpdateCounterDyn */
typedef uint8 EthTSyn_ValueOfTimeBaseUpdateCounterDynType;

/**   \brief  value based type definition for EthTSyn_ComCtrlPortIdxOfTxConfContext */
typedef uint8 EthTSyn_ComCtrlPortIdxOfTxConfContextType;

/**   \brief  value based type definition for EthTSyn_TxSmIdxOfTxConfContext */
typedef uint8 EthTSyn_TxSmIdxOfTxConfContextType;

/**   \brief  value based type definition for EthTSyn_TxSmOfTxConfContext */
typedef uint8 EthTSyn_TxSmOfTxConfContextType;

/**   \brief  value based type definition for EthTSyn_ActiveOfTxConfContextDyn */
typedef boolean EthTSyn_ActiveOfTxConfContextDynType;

/**   \brief  value based type definition for EthTSyn_BufferIdxOfTxConfContextDyn */
typedef uint8 EthTSyn_BufferIdxOfTxConfContextDynType;

/**   \brief  value based type definition for EthTSyn_TxConfContextNextActiveIdxOfTxConfContextDyn */
typedef uint8 EthTSyn_TxConfContextNextActiveIdxOfTxConfContextDynType;

/**   \brief  value based type definition for EthTSyn_TxConfContextPrevActiveIdxOfTxConfContextDyn */
typedef uint8 EthTSyn_TxConfContextPrevActiveIdxOfTxConfContextDynType;

/**   \brief  value based type definition for EthTSyn_TxConfContextDynActiveFirstIdx */
typedef uint8 EthTSyn_TxConfContextDynActiveFirstIdxType;

/**   \brief  value based type definition for EthTSyn_TxConfContextDynActiveLastIdx */
typedef uint8 EthTSyn_TxConfContextDynActiveLastIdxType;

/** 
  \}
*/ 



/**********************************************************************************************************************
 * GENERATED CFG RELATED TYPES (NOT ComStackLib)
 *********************************************************************************************************************/
typedef uint64 EthTSyn_IntVltType;
typedef uint32 EthTSyn_PdelayType;
typedef uint64 EthTSyn_UTimediffType;

/* ----- Types of the ComCtrl unit ---- */
typedef EthTSyn_SizeOfComCtrlTimeDomainType EthTSyn_ComCtrl_TimeDomainIdxType;
typedef EthTSyn_SizeOfComCtrlPortType EthTSyn_ComCtrl_PortIdxType;
typedef EthTSyn_SizeOfComCtrlEthIfCtrlType EthTSyn_ComCtrl_EthIfCtrlIdxType;

/* ----- Types of the PortParamStats unit ---- */
typedef EthTSyn_SizeOfPortParamStatsDynType EthTSyn_PortParamStats_IdxType;

/* ----- Types of the SyncSendSm unit ----- */
typedef EthTSyn_SizeOfSyncSendSmType EthTSyn_SyncSendSm_SmIdxType;

/* ----- Types of the PortSyncSendSm unit ----- */
typedef EthTSyn_SizeOfPortSyncSendSmType EthTSyn_PortSyncSendSm_SmIdxType;

/* ----- Types of the AnnounceSendSm unit ----- */
typedef EthTSyn_SizeOfAnnounceSendSmType EthTSyn_AnnounceSendSm_SmIdxType;

/* ----- Types of the SlaveRx unit ----- */
typedef EthTSyn_SizeOfSlaveRxDataHandlerType EthTSyn_SlaveRx_DataHandlerIdxType;
typedef EthTSyn_SizeOfSlaveRxDataType EthTSyn_SlaveRx_DataIdxType;

/* ----- Types of the SyncRcvSm unit ----- */
typedef EthTSyn_SizeOfSyncRcvSmType EthTSyn_SyncRcvSm_SmIdxType;

/* ----- Types of the AnnounceRcvSm unit ----- */
typedef EthTSyn_SizeOfAnnounceRcvSmType EthTSyn_AnnounceRcvSm_SmIdxType;

/* ----- Types of the PdReqSm unit ----- */
typedef EthTSyn_SizeOfPdReqSmType EthTSyn_PdReqSm_SmIdxType;

/* ----- Types of the PdReqTrcv unit ----- */
/* Hint: PdReqTrcv has a size relation to the PdReqSm */
typedef EthTSyn_SizeOfPdReqTrcvDynType EthTSyn_PdReqTrcv_IdxType;

/* ----- Types of the PdRespSm unit ----- */
typedef EthTSyn_SizeOfPdRespSmType EthTSyn_PdRespSm_SmIdxType;

/* ----- Types of the CrcHndl unit ----- */
typedef EthTSyn_SizeOfCrcHndlType EthTSyn_CrcHndl_IdxType;

/* ----- Types of the FupRxHandler unit ----- */
typedef EthTSyn_SizeOfFupRxHandlerType EthTSyn_FupRxHandler_IdxType;

/* Removed types due to disabled switch management support:
 * EthTSyn_SwtMgmtQ_IdxType
 * EthTSyn_SwtMgmtQ_BufIdxType
 * EthTSyn_SwtMgmtQ_BufUserIdxType
 * EthTSyn_SwtMgmtQ_BufUserType
 * EthTSyn_SwtMgmtRx_IdxType
 * EthTSyn_SwtMgmtTx_IdxType
 */

/* ----- Types of the SiteSyncSyncTx unit ----- */
typedef uint8 EthTSyn_SiteSyncSyncTx_IdxType;

/* ----- Types of the SiteSyncSyncSm unit ----- */
typedef uint8 EthTSyn_SiteSyncSyncSm_SmIdxType;

/* ----- Types of the AsymSiteSyncSyncSm unit ----- */
typedef uint8 EthTSyn_AsymSiteSyncSyncSm_SmIdxType;

/* Removed types due to disabled switch time sync support:
 * EthTSyn_SwtTimeSyncSm_SmIdxType
 * EthTSyn_RateMeas_IdxType
 */

#endif  /* ETHTSYN_GENERATED_SIMPLE_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: EthTSyn_GeneratedSimpleTypes.h
 *********************************************************************************************************************/

