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
 *              File: EthTSyn_GeneratedComplexTypes.h
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
#ifndef ETHTSYN_GENERATED_COMPLEX_TYPES_H
#define ETHTSYN_GENERATED_COMPLEX_TYPES_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATIONS
 *********************************************************************************************************************/
/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "EthTSyn_GeneratedSimpleTypes.h"
#include "EthTSyn_Types.h"
#include "EthIf_Types.h"
#include "StbM_Types.h"

/**********************************************************************************************************************
 * GENERATED TYPES (NOT ComStackLib)
 *********************************************************************************************************************/
/**   \brief EthTSyn_EthBufferPtrType */
typedef P2VAR(uint8, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_EthBufferPtrType;

/**   \brief EthTSyn_EthConstBufferPtrType */
typedef P2CONST(uint8, TYPEDEF, ETHTSYN_APPL_DATA) EthTSyn_EthConstBufferPtrType;

/**   \brief EthTSyn_MsgHdrType */
typedef struct
{
  uint64 SourceClockId;
  uint64 CorrectionFieldNs; /* Only 48Bits are used. */
  uint16 CorrectionFieldSubNs;
  uint16 MessageLength;
  uint16 SourcePortNumber;
  uint16 SequenceId;
  uint8  MessageType;
  uint8  DomainNumber;
  uint8  PtpVersion;
  sint8  LogMessageInterval;
  uint8  Flags0;
  uint8  Flags1;
  uint8  TransportSpecific;
  uint8  Control;
} EthTSyn_MsgHdrType;

/**   \brief EthTSyn_GlobalTimestampType */
/*! Timestamp struct definition */
typedef struct EthTSyn_GlobalTimestampTypeStruct
{
  uint32 nanoseconds;
  uint32 seconds;
  uint16 secondsHi;
} EthTSyn_GlobalTimestampType;

/**   \brief EthTSyn_IntVltMgmtType */
typedef struct
{
  EthTSyn_IntVltType IntVlt;      /*!< The virtual local time in internal representation. */
  boolean            IntVltValid; /*!< Validity indication of IntVlt. */
} EthTSyn_IntVltMgmtType;

/**   \brief EthTSyn_TsMgmtType */
typedef struct
{
  EthTSyn_GlobalTimestampType Ts;
  boolean                     TsValid;
} EthTSyn_TsMgmtType;

/**   \brief EthTSyn_TsInfoType */
typedef struct
{
  EthTSyn_IntVltMgmtType IntVltMgmt;
/* Removed members due to disabled switch management support:
 * EthTSyn_TsMgmtType     SwtIngrTsMgmt
 * EthTSyn_TsMgmtType     SwtEgrTsMgmt
*/
} EthTSyn_TsInfoType;

/**   \brief EthTSyn_SwtMgmtRxTsInfoType */
typedef struct
{
  EthTSyn_TsMgmtType            SwtIngrTsMgmt;
  EthTSyn_TsMgmtType            SwtEgrTsMgmt;
/* Removed members due to disabled AsymSiteSyncSyncSm:
 * EthSwt_VMgmtObjectAddInfoType AddInfo
 */
} EthTSyn_SwtMgmtRxTsInfoType;

/**   \brief EthTSyn_RxTsInfoType */
typedef struct
{
  EthTSyn_TsInfoType            TsInfo;
/* Removed members due to disabled HW-Timestamping or Slave support:
 * EthTSyn_IntVltMgmtType        SyncRxStbmIntVltMgmt
 * EthTSyn_IntVltMgmtType        SyncRxEthIntVltMgmt
 */
/* Removed members due to disabled AsymSiteSyncSyncSm:
 * EthSwt_VMgmtObjectAddInfoType AddInfo
 */
} EthTSyn_RxTsInfoType;

/**   \brief EthTSyn_IngrTimingInfoType */
typedef struct
{
  EthTSyn_IntVltMgmtType IntVltMgmt;
/* Removed members due to disabled HW-Timestamping or Slave support:
 * EthTSyn_IntVltMgmtType SyncRxStbmIntVltMgmt
 * EthTSyn_IntVltMgmtType SyncRxEthIntVltMgmt
 */
} EthTSyn_IngrTimingInfoType;

/**   \brief EthTSyn_SyncRxTimeInfoType */
typedef struct
{
  boolean                   SyncRxTimeInfoValid;
  StbM_VirtualLocalTimeType SyncRxVlt;
  EthTSyn_UTimediffType     SyncReceptionDelay;
  EthTSyn_IntVltType        SyncIngrTs;
  EthTSyn_UTimediffType     SwtResTime;
/* Removed members due to disabled switch management support:
 * EthTSyn_TsMgmtType        SyncSwtIngrTsMgmt
 */
} EthTSyn_SyncRxTimeInfoType;

/**   \brief EthTSyn_SyncTxInfoType */
typedef struct
{
  EthTSyn_IntVltType SyncTxIntVlt;     /*!< Virtual local time when Sync transmission was started. */
  StbM_TimeStampType SyncTxGlobalTime; /*!< Global time and time base status when Sync transmission was started. */
  StbM_UserDataType  SyncTxUserData;   /*!< User data of the time base when Sync transmission was started. */
} EthTSyn_SyncTxInfoType;

/**   \brief EthTSyn_PdRespRespFupDataType */
typedef struct
{
  EthTSyn_TsMgmtType          PdReqEgrTsMgmt;
  EthTSyn_TsMgmtType          PdRespIngrTsMgmt;
  EthTSyn_GlobalTimestampType RequestReceiptTs;
  EthTSyn_GlobalTimestampType ResponseOriginTs;
/* Removed members due to disabled slave_pd_req time validation support:
 * uint64                      ResponderSrcClockId
 * uint16                      ResponderSrcPortNum
 */
} EthTSyn_PdRespRespFupDataType;

/**   \brief EthTSyn_SwtMgmtInfoType */
typedef struct EthTSyn_SwtMgmtInfoTypeStruct
{
  uint8                SwitchIdx; /*!< EthIf switch index */
  uint8                PortIdx;   /*!< EthSwt port index */
} EthTSyn_SwtMgmtInfoType;

/**   \brief EthTSyn_SwtMgmt_MgmtInfoMgmtStructType */
typedef struct sEthTSyn_SwtMgmt_MgmtInfoMgmtStruct
{
  EthTSyn_SwtMgmtInfoType MgmtInfo;
  boolean                 IsValid;
} EthTSyn_SwtMgmt_MgmtInfoMgmtStructType;

/* Removed type EthTSyn_SwtMgmt_EthSwtMgmtObjPtrType due to disabled switch management support. */

/**   \brief EthTSyn_SwtTimeSync_TimestampInfoStructType */
typedef struct EthTSyn_SwtTimeSync_TimestampInfoStruct
{
  EthTSyn_GlobalTimestampType  SyncIngressTimestamp;   /*!< Switch sync ingress timestamp of the sync event. */
  EthTSyn_GlobalTimestampType  PreciseOriginTimestamp; /*!< Precise origin timestamp of the sync event. */
  uint16                       SequenceId;             /*!< Sequence Id of the sync event. */
} EthTSyn_SwtTimeSync_TimestampInfoStructType;

/**   \brief EthTSyn_SiteSyncSync_GenericTlvInfoType */
typedef struct EthTSyn_SiteSyncSync_GenericTlvInfoStruct
{
  uint16  RelOfs;            /*!< Offset to the start of the optional TLV relative to the payload.
                              *   0 when the TLV is not present. */
  boolean CrcUpdateRequired; /*!< Indicating if an update of the TLV CRC is required. */
  boolean CrcValid;          /*!< Indicating if the CRC af the received TLV is valid. Only relevant and set when CrcUpdateRequired == TRUE. */
} EthTSyn_SiteSyncSync_GenericTlvInfoType;

/**   \brief EthTSyn_SiteSyncSync_TimeTlvInfoType */
typedef struct EthTSyn_SiteSyncSync_TimeTlvInfoStruct
{
  uint16 RelOfs;                  /*!< Offset to the start of the optional Time secured TLV relative to the payload.
                                   *   0 when the TLV is not present. */
  boolean CrcTime0UpdateRequired; /*!< Indicating if an update of the Time 0 CRC is required. */
  boolean CrcTime1UpdateRequired; /*!< Indicating if an update of the Time 1 CRC is required. */
  boolean CrcValid;               /*!< Indicating if the CRC af the received TLV is valid.
                                   *   Only relevant and set when CrcTime0UpdateRequired || CrcTime1UpdateRequired. */
} EthTSyn_SiteSyncSync_TimeTlvInfoType;

/* Removed type EthTSyn_SiteSyncSync_OfsTlvInfoType due to disabled transparent clock/sync timeout support. */

/**   \brief EthTSyn_SiteSyncSync_TlvInfoType */
typedef struct EthTSyn_SiteSyncSync_TlvInfoStruct
{
  EthTSyn_SiteSyncSync_TimeTlvInfoType    TimeTlvInfo;     /*!< Information about a received Time secured Sub-TLV. */
/* Removed members due to disabled transparent clock/sync timeout support:
 * EthTSyn_SiteSyncSync_OfsTlvInfoType     OfsTlvInfo;
 * EthTSyn_SiteSyncSync_GenericTlvInfoType StatusTlvInfo;
 * EthTSyn_SiteSyncSync_GenericTlvInfoType UserDataTlvInfo;
 */
} EthTSyn_SiteSyncSync_TlvInfoType;

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  EthTSynPCStructTypes  EthTSyn Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in EthTSyn_AnnounceRcvSm */
typedef struct sEthTSyn_AnnounceRcvSmType
{
  EthTSyn_ComCtrlPortIdxOfAnnounceRcvSmType ComCtrlPortIdxOfAnnounceRcvSm;  /**< the index of the 1:1 relation pointing to EthTSyn_ComCtrlPort */
  EthTSyn_MaxStepsRemovedOfAnnounceRcvSmType MaxStepsRemovedOfAnnounceRcvSm;  /**< Max steps to time master */
  EthTSyn_RxTimeoutOfAnnounceRcvSmType RxTimeoutOfAnnounceRcvSm;  /**< Allowed delay for received Announce messages in MainFunction cycles */
  EthTSyn_SlaveRxDataIdxOfAnnounceRcvSmType SlaveRxDataIdxOfAnnounceRcvSm;  /**< the index of the 1:1 relation pointing to EthTSyn_SlaveRxData */
} EthTSyn_AnnounceRcvSmType;

/**   \brief  type used in EthTSyn_AnnounceRcvSmDyn */
typedef struct sEthTSyn_AnnounceRcvSmDynType
{
  EthTSyn_RxTimeoutCounterOfAnnounceRcvSmDynType RxTimeoutCounterOfAnnounceRcvSmDyn;  /**< Announce reception timeout counter in MainFunction cycles. */
  EthTSyn_SmResetRequestedOfAnnounceRcvSmDynType SmResetRequestedOfAnnounceRcvSmDyn;  /**< Indicates if the Announce receive state machine must be reset */
  EthTSyn_StateOfAnnounceRcvSmDynType StateOfAnnounceRcvSmDyn;  /**< The state of the Announce receive state machine */
} EthTSyn_AnnounceRcvSmDynType;

/**   \brief  type used in EthTSyn_AnnounceSendSm */
typedef struct sEthTSyn_AnnounceSendSmType
{
  EthTSyn_AnnounceLogMsgIntervalOfAnnounceSendSmType AnnounceLogMsgIntervalOfAnnounceSendSm;  /**< Log message interval of the Announce message */
  EthTSyn_AnnounceTxCycleOfAnnounceSendSmType AnnounceTxCycleOfAnnounceSendSm;  /**< The Announce transmission cycle expressed in EthTSyn_MainFunction cycles. */
  EthTSyn_ComCtrlPortIdxOfAnnounceSendSmType ComCtrlPortIdxOfAnnounceSendSm;  /**< the index of the 1:1 relation pointing to EthTSyn_ComCtrlPort */
} EthTSyn_AnnounceSendSmType;

/**   \brief  type used in EthTSyn_AnnounceSendSmDyn */
typedef struct sEthTSyn_AnnounceSendSmDynType
{
  EthTSyn_AnnounceCycleTimerOfAnnounceSendSmDynType AnnounceCycleTimerOfAnnounceSendSmDyn;  /**< The Announce cycle timer */
  EthTSyn_SequenceIdOfAnnounceSendSmDynType SequenceIdOfAnnounceSendSmDyn;  /**< Sequence Id used for Announce message transmission */
  EthTSyn_ResetRequestedOfAnnounceSendSmDynType ResetRequestedOfAnnounceSendSmDyn;  /**< Indicating if a reset of the state machine shall be triggered */
  EthTSyn_StateOfAnnounceSendSmDynType StateOfAnnounceSendSmDyn;  /**< The state of the AnnounceSend state machine */
} EthTSyn_AnnounceSendSmDynType;

/**   \brief  type used in EthTSyn_BridgeTxMasterPort */
typedef struct sEthTSyn_BridgeTxMasterPortType
{
  EthTSyn_ComCtrlPortIdxOfBridgeTxMasterPortType ComCtrlPortIdxOfBridgeTxMasterPort;  /**< the index of the 1:1 relation pointing to EthTSyn_ComCtrlPort */
} EthTSyn_BridgeTxMasterPortType;

/**   \brief  type used in EthTSyn_BridgeTxMasterPortDyn */
typedef struct sEthTSyn_BridgeTxMasterPortDynType
{
  EthTSyn_SyncFwdDelayNsOfBridgeTxMasterPortDynType SyncFwdDelayNsOfBridgeTxMasterPortDyn;  /**< The delay upon Sync forwarding which needs to be compensated by update of the FollowUp correction. This includes the Pdelay on the switch slave port and the switch residence time for the Sync message */
  EthTSyn_FupFwdStateOfBridgeTxMasterPortDynType FupFwdStateOfBridgeTxMasterPortDyn;  /**< State of the FollowUp message forwarding */
} EthTSyn_BridgeTxMasterPortDynType;

/**   \brief  type used in EthTSyn_ComCtrlEthIfCtrl */
typedef struct sEthTSyn_ComCtrlEthIfCtrlType
{
  EthTSyn_ComCtrlPortIndEndIdxOfComCtrlEthIfCtrlType ComCtrlPortIndEndIdxOfComCtrlEthIfCtrl;  /**< the end index of the 1:n relation pointing to EthTSyn_ComCtrlPortInd */
  EthTSyn_ComCtrlPortIndStartIdxOfComCtrlEthIfCtrlType ComCtrlPortIndStartIdxOfComCtrlEthIfCtrl;  /**< the start index of the 1:n relation pointing to EthTSyn_ComCtrlPortInd */
  EthTSyn_DestinationMacIndEndIdxOfComCtrlEthIfCtrlType DestinationMacIndEndIdxOfComCtrlEthIfCtrl;  /**< the end index of the 1:n relation pointing to EthTSyn_DestinationMacInd */
  EthTSyn_DestinationMacIndStartIdxOfComCtrlEthIfCtrlType DestinationMacIndStartIdxOfComCtrlEthIfCtrl;  /**< the start index of the 1:n relation pointing to EthTSyn_DestinationMacInd */
  EthTSyn_EthIfCtrlIdxOfComCtrlEthIfCtrlType EthIfCtrlIdxOfComCtrlEthIfCtrl;  /**< Index of the underlying EthIf controller. */
} EthTSyn_ComCtrlEthIfCtrlType;

/**   \brief  type used in EthTSyn_ComCtrlEthIfCtrlDyn */
typedef struct sEthTSyn_ComCtrlEthIfCtrlDynType
{
  EthTSyn_ClockIdOfComCtrlEthIfCtrlDynType ClockIdOfComCtrlEthIfCtrlDyn;  /**< The PTP Clock Id of the underlying EthIfCtrl */
  EthTSyn_LinkStateActiveOfComCtrlEthIfCtrlDynType LinkStateActiveOfComCtrlEthIfCtrlDyn;  /**< Indicating if link state of the underlying EthIfCtrl is active or not. */
  EthTSyn_TxActiveOfComCtrlEthIfCtrlDynType TxActiveOfComCtrlEthIfCtrlDyn;  /**< Indicating if transmission mode is TX_ON for the underlying EthIfCtrl or not. */
} EthTSyn_ComCtrlEthIfCtrlDynType;

/**   \brief  type used in EthTSyn_ComCtrlPhysPort */
typedef struct sEthTSyn_ComCtrlPhysPortType
{
  EthTSyn_AlwaysAsCapableOfComCtrlPhysPortType AlwaysAsCapableOfComCtrlPhysPort;  /**< Indicating if the Port is always AsCapable */
  EthTSyn_UseStaticPdelayOfComCtrlPhysPortType UseStaticPdelayOfComCtrlPhysPort;  /**< Is static Pdelay value used */
  EthTSyn_DebounceTimerInitOfComCtrlPhysPortType DebounceTimerInitOfComCtrlPhysPort;  /**< Initial value of the debounce timer expressed in EthTSyn_MainFunction() cycles. */
  EthTSyn_InitialPdelayNsOfComCtrlPhysPortType InitialPdelayNsOfComCtrlPhysPort;  /**< The initially used Pdelay value (this value is also used as static value when (UseStaticPdelay == TRUE)) */
} EthTSyn_ComCtrlPhysPortType;

/**   \brief  type used in EthTSyn_ComCtrlPhysPortDyn */
typedef struct sEthTSyn_ComCtrlPhysPortDynType
{
  EthTSyn_DebounceTimerOfComCtrlPhysPortDynType DebounceTimerOfComCtrlPhysPortDyn;  /**< Current value of the debounce timer expressed in EthTSyn_MainFunction() cycles. */
  EthTSyn_AsCapableOfComCtrlPhysPortDynType AsCapableOfComCtrlPhysPortDyn;  /**< AsCapable Flag */
  EthTSyn_PdelayType PdelayValueNsOfComCtrlPhysPortDyn;  /**< Current valid Pdelay value */
} EthTSyn_ComCtrlPhysPortDynType;

/**   \brief  type used in EthTSyn_ComCtrlPort */
typedef struct sEthTSyn_ComCtrlPortType
{
  EthTSyn_AnnounceSendSmIdxOfComCtrlPortType AnnounceSendSmIdxOfComCtrlPort;  /**< the index of the 0:1 relation pointing to EthTSyn_AnnounceSendSm */
  EthTSyn_ComCtrlEthIfCtrlIdxOfComCtrlPortType ComCtrlEthIfCtrlIdxOfComCtrlPort;  /**< the index of the 1:1 relation pointing to EthTSyn_ComCtrlEthIfCtrl */
  EthTSyn_ComCtrlPhysPortIdxOfComCtrlPortType ComCtrlPhysPortIdxOfComCtrlPort;  /**< the index of the 1:1 relation pointing to EthTSyn_ComCtrlPhysPort */
  EthTSyn_ComCtrlTimeDomainIdxOfComCtrlPortType ComCtrlTimeDomainIdxOfComCtrlPort;  /**< the index of the 1:1 relation pointing to EthTSyn_ComCtrlTimeDomain */
  EthTSyn_FramePrioOfComCtrlPortType FramePrioOfComCtrlPort;  /**< Frame priority of the EthTSyn Port */
  EthTSyn_NumberOfComCtrlPortType NumberOfComCtrlPort;  /**< Number of the EthTSyn Port */
  EthTSyn_PdReqSmIdxOfComCtrlPortType PdReqSmIdxOfComCtrlPort;  /**< the index of the 0:1 relation pointing to EthTSyn_PdReqSm */
  EthTSyn_PdRespSmIdxOfComCtrlPortType PdRespSmIdxOfComCtrlPort;  /**< the index of the 0:1 relation pointing to EthTSyn_PdRespSm */
  EthTSyn_PortParamStatsDynIdxOfComCtrlPortType PortParamStatsDynIdxOfComCtrlPort;  /**< the index of the 0:1 relation pointing to EthTSyn_PortParamStatsDyn */
  EthTSyn_PortSyncSendSmIdxOfComCtrlPortType PortSyncSendSmIdxOfComCtrlPort;  /**< the index of the 0:1 relation pointing to EthTSyn_PortSyncSendSm */
  EthTSyn_SlaveRxDataHandlerIdxOfComCtrlPortType SlaveRxDataHandlerIdxOfComCtrlPort;  /**< the index of the 0:1 relation pointing to EthTSyn_SlaveRxDataHandler */
  EthTSyn_SyncSendSmIdxOfComCtrlPortType SyncSendSmIdxOfComCtrlPort;  /**< the index of the 0:1 relation pointing to EthTSyn_SyncSendSm */
} EthTSyn_ComCtrlPortType;

/**   \brief  type used in EthTSyn_ComCtrlTimeDomain */
typedef struct sEthTSyn_ComCtrlTimeDomainType
{
  EthTSyn_ComCtrlPortEndIdxOfComCtrlTimeDomainType ComCtrlPortEndIdxOfComCtrlTimeDomain;  /**< the end index of the 1:n relation pointing to EthTSyn_ComCtrlPort */
  EthTSyn_ComCtrlPortStartIdxOfComCtrlTimeDomainType ComCtrlPortStartIdxOfComCtrlTimeDomain;  /**< the start index of the 1:n relation pointing to EthTSyn_ComCtrlPort */
  EthTSyn_DestinationMacIdxOfComCtrlTimeDomainType DestinationMacIdxOfComCtrlTimeDomain;  /**< the index of the 1:1 relation pointing to EthTSyn_DestinationMac */
  EthTSyn_IdOfComCtrlTimeDomainType IdOfComCtrlTimeDomain;  /**< Time Domain Id */
  EthTSyn_OffsetTimeDomainEndIdxOfComCtrlTimeDomainType OffsetTimeDomainEndIdxOfComCtrlTimeDomain;  /**< the end index of the 0:n relation pointing to EthTSyn_OffsetTimeDomain */
  EthTSyn_OffsetTimeDomainStartIdxOfComCtrlTimeDomainType OffsetTimeDomainStartIdxOfComCtrlTimeDomain;  /**< the start index of the 0:n relation pointing to EthTSyn_OffsetTimeDomain */
  StbM_SynchronizedTimeBaseType SynchronizedTimeBaseIdOfComCtrlTimeDomain;  /**< Index of the referenced Synchronized Time Base */
} EthTSyn_ComCtrlTimeDomainType;

/**   \brief  type used in EthTSyn_CrcHndl */
typedef struct sEthTSyn_CrcHndlType
{
  EthTSyn_FupDataIdListEndIdxOfCrcHndlType FupDataIdListEndIdxOfCrcHndl;  /**< the end index of the 1:n relation pointing to EthTSyn_FupDataIdList */
  EthTSyn_FupDataIdListStartIdxOfCrcHndlType FupDataIdListStartIdxOfCrcHndl;  /**< the start index of the 1:n relation pointing to EthTSyn_FupDataIdList */
} EthTSyn_CrcHndlType;

/**   \brief  type used in EthTSyn_DestinationMac */
typedef struct sEthTSyn_DestinationMacType
{
  EthTSyn_Byte0OfDestinationMacType Byte0OfDestinationMac;  /**< First Byte (MSB) of the destination MAC-Address */
  EthTSyn_Byte1OfDestinationMacType Byte1OfDestinationMac;  /**< Second Byte of the destination MAC-Address */
  EthTSyn_Byte2OfDestinationMacType Byte2OfDestinationMac;  /**< Third Byte of the destination MAC-Address */
  EthTSyn_Byte3OfDestinationMacType Byte3OfDestinationMac;  /**< Fourth Byte of the destination MAC-Address */
  EthTSyn_Byte4OfDestinationMacType Byte4OfDestinationMac;  /**< Fifth Byte of the destination MAC-Address */
  EthTSyn_Byte5OfDestinationMacType Byte5OfDestinationMac;  /**< Sixth Byte (LSB) of the destination MAC-Address */
} EthTSyn_DestinationMacType;

/**   \brief  type used in EthTSyn_FupRxHandler */
typedef struct sEthTSyn_FupRxHandlerType
{
  EthTSyn_FupCorrFieldThresholdNsOfFupRxHandlerType FupCorrFieldThresholdNsOfFupRxHandler;  /**< Max tolerated value in nanoseconds of the correction field for a received FollowUp message */
  EthTSyn_TimeValidationEnabledOfFupRxHandlerType TimeValidationEnabledOfFupRxHandler;  /**< Indicating if time validation is enabled for the slave port */
  EthTSyn_ComCtrlPortExternalIdxOfFupRxHandlerType ComCtrlPortExternalIdxOfFupRxHandler;  /**< the index of the 1:1 relation pointing to EthTSyn_ComCtrlPort */
  EthTSyn_CrcFlagsRxValidatedOfFupRxHandlerType CrcFlagsRxValidatedOfFupRxHandler;  /**< Flags indicating which message fields should be used for Crc calculation */
  EthTSyn_CrcHndlIdxOfFupRxHandlerType CrcHndlIdxOfFupRxHandler;  /**< the index of the 0:1 relation pointing to EthTSyn_CrcHndl */
  EthTSyn_RxCrcValidatedEnumType RxCrcValidatedOfFupRxHandler;  /**< Crc method for received follow up messages */
} EthTSyn_FupRxHandlerType;

/**   \brief  type used in EthTSyn_OffsetTimeDomain */
typedef struct sEthTSyn_OffsetTimeDomainType
{
  EthTSyn_IdOfOffsetTimeDomainType IdOfOffsetTimeDomain;  /**< Id of the offset time domain */
  StbM_SynchronizedTimeBaseType SynchronizedTimeBaseIdOfOffsetTimeDomain;  /**< The synchronize time base id used for StbM API calls */
} EthTSyn_OffsetTimeDomainType;

/**   \brief  type used in EthTSyn_PdReqSm */
typedef struct sEthTSyn_PdReqSmType
{
  EthTSyn_PdThresholdOfPdReqSmType PdThresholdOfPdReqSm;  /**< Max allowed/valid value for Pdelay in nanoseconds */
  EthTSyn_TimeValidationEnabledOfPdReqSmType TimeValidationEnabledOfPdReqSm;  /**< Indicating if time validation is enabled for PdReqSm */
  EthTSyn_LogMsgIntervalOfPdReqSmType LogMsgIntervalOfPdReqSm;  /**< The Log message interval of the Pdelay request */
  EthTSyn_AverageWeightOfPdReqSmType AverageWeightOfPdReqSm;  /**< Weight factor used for weighted average calculation */
  EthTSyn_ComCtrlPortIdxOfPdReqSmType ComCtrlPortIdxOfPdReqSm;  /**< the index of the 1:1 relation pointing to EthTSyn_ComCtrlPort */
  EthTSyn_MaxLostResponsesOfPdReqSmType MaxLostResponsesOfPdReqSm;  /**< Max number of Pdelay request cycles without receiving a valid Pdelay response before AsCapable is set to FALSE */
  EthTSyn_PdReqPeriodOfPdReqSmType PdReqPeriodOfPdReqSm;  /**< Pdelay request transmission interval in MainFunction cycles */
  EthTSyn_PdRespTimeoutOfPdReqSmType PdRespTimeoutOfPdReqSm;  /**< Pdelay_Resp/Pdelay_Resp_Fup timeout in MainFunction cycles */
  EthTSyn_TxConfContextIdxOfPdReqSmType TxConfContextIdxOfPdReqSm;  /**< the index of the 1:1 relation pointing to EthTSyn_TxConfContext */
} EthTSyn_PdReqSmType;

/**   \brief  type used in EthTSyn_PdReqSmDyn */
typedef struct sEthTSyn_PdReqSmDynType
{
  EthTSyn_RespTimeoutCntOfPdReqSmDynType RespTimeoutCntOfPdReqSmDyn;  /**< Pdelay_Resp/PdelayResp_Fup timeout counter: decrement with each main function call */
  EthTSyn_TxIntervalCntOfPdReqSmDynType TxIntervalCntOfPdReqSmDyn;  /**< Pdelay_Req Tx interval counter: decrement with each main function call */
  EthTSyn_SequenceIdOfPdReqSmDynType SequenceIdOfPdReqSmDyn;  /**< Sequence id: incremented after every successful Pdelay_Req transmission */
  EthTSyn_FirstPdelayOfPdReqSmDynType FirstPdelayOfPdReqSmDyn;  /**< Indicates whether the state machine has already calculated a valid Pdelay or not */
  EthTSyn_LostResponseCntOfPdReqSmDynType LostResponseCntOfPdReqSmDyn;  /**< Counter for lost responses */
  EthTSyn_SmResetRequestedOfPdReqSmDynType SmResetRequestedOfPdReqSmDyn;  /**< Indicates if the Pdelay request state machine must be reset */
  EthTSyn_StateOfPdReqSmDynType StateOfPdReqSmDyn;  /**< State of the PdReqSm */
  StbM_TimeStampShortType RefGlobalTimeOfPdReqSmDyn;  /**< Reference global time retrieved from StbM before Pdelay_Req transmission */
  StbM_VirtualLocalTimeType RefLocalTimeOfPdReqSmDyn;  /**< Reference local time retrieved from StbM before Pdelay_Req transmission */
} EthTSyn_PdReqSmDynType;

/**   \brief  type used in EthTSyn_PdReqTrcvDyn */
typedef struct sEthTSyn_PdReqTrcvDynType
{
  EthTSyn_RespClockIdOfPdReqTrcvDynType RespClockIdOfPdReqTrcvDyn;  /**< Source clock id of Pdelay_Resp message */
  EthTSyn_RespPortNumOfPdReqTrcvDynType RespPortNumOfPdReqTrcvDyn;  /**< Source port number of Pdelay_Resp message */
  EthTSyn_PdReqEgrTsProvidedOfPdReqTrcvDynType PdReqEgrTsProvidedOfPdReqTrcvDyn;  /**< Indicating if the Pdelay_Req egress timestamp was already provided */
  EthTSyn_StateOfPdReqTrcvDynType StateOfPdReqTrcvDyn;  /**< State of the PdReqTrcv unit. */
  EthTSyn_TsMgmtType PdReqEgrTsMgmtOfPdReqTrcvDyn;  /**< Pdelay_Req egress timestamp with validity information */
  EthTSyn_TsMgmtType PdRespIngrTsMgmtOfPdReqTrcvDyn;  /**< Pdelay_Resp ingress timestamp with validity information */
  EthTSyn_GlobalTimestampType ReqReceivedTsOfPdReqTrcvDyn;  /**< Request receipt timestamp received by Pdelay_Resp */
  EthTSyn_GlobalTimestampType RespOriginTsOfPdReqTrcvDyn;  /**< Response origin timestamp received by Pdelay_Resp_Fup */
} EthTSyn_PdReqTrcvDynType;

/**   \brief  type used in EthTSyn_PdRespSm */
typedef struct sEthTSyn_PdRespSmType
{
  EthTSyn_TimeValidationEnabledOfPdRespSmType TimeValidationEnabledOfPdRespSm;  /**< Indicating if time validation is enabled for PdRespSm */
  EthTSyn_ComCtrlPortIdxOfPdRespSmType ComCtrlPortIdxOfPdRespSm;  /**< the index of the 1:1 relation pointing to EthTSyn_ComCtrlPort */
  EthTSyn_TxConfContextIdxOfPdRespSmType TxConfContextIdxOfPdRespSm;  /**< the index of the 1:1 relation pointing to EthTSyn_TxConfContext */
} EthTSyn_PdRespSmType;

/**   \brief  type used in EthTSyn_PdRespSmDyn */
typedef struct sEthTSyn_PdRespSmDynType
{
  EthTSyn_RequestorClockIdOfPdRespSmDynType RequestorClockIdOfPdRespSmDyn;  /**< Source clock identity of the last received valid Pdelay_Req */
  EthTSyn_RequestorPortNumOfPdRespSmDynType RequestorPortNumOfPdRespSmDyn;  /**< Source port number of the last received valid Pdelay_Req */
  EthTSyn_SequenceIdOfPdRespSmDynType SequenceIdOfPdRespSmDyn;  /**< SequenceId of the current ongoing Pdelay cycle */
  EthTSyn_SmResetRequestedOfPdRespSmDynType SmResetRequestedOfPdRespSmDyn;  /**< Indicates if the Pdelay request state machine must be reset */
  EthTSyn_StateOfPdRespSmDynType StateOfPdRespSmDyn;  /**< State of the PdRespSm */
  EthTSyn_GlobalTimestampType PdReqRcvdTsOfPdRespSmDyn;  /**< Ingress timestamp of the last received valid Pdelay_Req */
  EthTSyn_GlobalTimestampType PdRespOrgTsOfPdRespSmDyn;  /**< Egress timestamp of the last transmitted Pdelay_Resp */
} EthTSyn_PdRespSmDynType;

/**   \brief  type used in EthTSyn_PortParamStatsDyn */
typedef struct sEthTSyn_PortParamStatsDynType
{
  EthTSyn_PdLostRespExceededCountOfPortParamStatsDynType PdLostRespExceededCountOfPortParamStatsDyn;  /**< Number how often the allowed amount of lost responses was exceeded. */
  EthTSyn_RxAnnounceCountOfPortParamStatsDynType RxAnnounceCountOfPortParamStatsDyn;  /**< Number of received Announce messages on EthTSynPort. */
  EthTSyn_RxDiscardCountOfPortParamStatsDynType RxDiscardCountOfPortParamStatsDyn;  /**< Number of discarded PTP packets on EthTSynPort. */
  EthTSyn_RxFupCountOfPortParamStatsDynType RxFupCountOfPortParamStatsDyn;  /**< Number of received FollowUp messages on EthTSynPort. */
  EthTSyn_RxPdReqCountOfPortParamStatsDynType RxPdReqCountOfPortParamStatsDyn;  /**< Number of received PdelayReq messages on EthTSynPort. */
  EthTSyn_RxPdRespCountOfPortParamStatsDynType RxPdRespCountOfPortParamStatsDyn;  /**< Number of received PdelayResp messages on EthTSynPort. */
  EthTSyn_RxPdRespFupCountOfPortParamStatsDynType RxPdRespFupCountOfPortParamStatsDyn;  /**< Number of received PdelayRespFup messages on EthTSynPort. */
  EthTSyn_RxSyncCountOfPortParamStatsDynType RxSyncCountOfPortParamStatsDyn;  /**< Number of received Sync messages on EthTSynPort. */
  EthTSyn_TxAnnounceCountOfPortParamStatsDynType TxAnnounceCountOfPortParamStatsDyn;  /**< Number of transmitted Announce messages on EthTSynPort. */
  EthTSyn_TxFupCountOfPortParamStatsDynType TxFupCountOfPortParamStatsDyn;  /**< Number of transmitted FollowUp messages on EthTSynPort. */
  EthTSyn_TxPdReqCountOfPortParamStatsDynType TxPdReqCountOfPortParamStatsDyn;  /**< Number of transmitted PdelayReq messages on EthTSynPort. */
  EthTSyn_TxPdRespCountOfPortParamStatsDynType TxPdRespCountOfPortParamStatsDyn;  /**< Number of transmitted PdelayResp messages on EthTSynPort. */
  EthTSyn_TxPdRespFupCountOfPortParamStatsDynType TxPdRespFupCountOfPortParamStatsDyn;  /**< Number of transmitted PdelayRespFup messages on EthTSynPort. */
  EthTSyn_TxSyncCountOfPortParamStatsDynType TxSyncCountOfPortParamStatsDyn;  /**< Number of transmitted Sync messages on EthTSynPort. */
} EthTSyn_PortParamStatsDynType;

/**   \brief  type used in EthTSyn_PortSyncSendSm */
typedef struct sEthTSyn_PortSyncSendSmType
{
  EthTSyn_TimeValidationEnabledOfPortSyncSendSmType TimeValidationEnabledOfPortSyncSendSm;  /**< Indicating if time validation is enabled for the master port */
  EthTSyn_ComCtrlPortIdxOfPortSyncSendSmType ComCtrlPortIdxOfPortSyncSendSm;  /**< the index of the 1:1 relation pointing to EthTSyn_ComCtrlPort */
  EthTSyn_MsgSentCbkBufEndIdxOfPortSyncSendSmType MsgSentCbkBufEndIdxOfPortSyncSendSm;  /**< the end index of the 0:n relation pointing to EthTSyn_MsgSentCbkBuf */
  EthTSyn_MsgSentCbkBufLengthOfPortSyncSendSmType MsgSentCbkBufLengthOfPortSyncSendSm;  /**< the number of relations pointing to EthTSyn_MsgSentCbkBuf */
  EthTSyn_MsgSentCbkBufStartIdxOfPortSyncSendSmType MsgSentCbkBufStartIdxOfPortSyncSendSm;  /**< the start index of the 0:n relation pointing to EthTSyn_MsgSentCbkBuf */
  EthTSyn_TxConfContextIdxOfPortSyncSendSmType TxConfContextIdxOfPortSyncSendSm;  /**< the index of the 1:1 relation pointing to EthTSyn_TxConfContext */
  EthTSyn_FollowUpSentCbkPtrType FollowUpSentCbkPtrOfPortSyncSendSm;  /**< Callback for notification of FollowUp transmission */
  EthTSyn_SyncSentCbkPtrType SyncSentCbkPtrOfPortSyncSendSm;  /**< Callback for notification of Sync transmission */
} EthTSyn_PortSyncSendSmType;

/**   \brief  type used in EthTSyn_PortSyncSendSmDyn */
typedef struct sEthTSyn_PortSyncSendSmDynType
{
  EthTSyn_StateOfPortSyncSendSmDynType StateOfPortSyncSendSmDyn;  /**< The state of the PortSyncSend state machine */
  EthTSyn_TsInfoType EgrTsInfoOfPortSyncSendSmDyn;  /**< Egress timestamp of transmitted Sync on the Host/EndStation and switch ingress and egress timestamps if switch timestamping is enabled. */
} EthTSyn_PortSyncSendSmDynType;

/**   \brief  type used in EthTSyn_RateMeas */
typedef struct sEthTSyn_RateMeasType
{
  EthTSyn_RateRatioMaxOfRateMeasType RateRatioMaxOfRateMeas;  /**< Max allowed RateRatio */
  EthTSyn_RateRatioMinOfRateMeasType RateRatioMinOfRateMeas;  /**< Min allowed RateRatio */
  EthTSyn_UseInitialOffsetCorrectionOfRateMeasType UseInitialOffsetCorrectionOfRateMeas;  /**< Indicating if offset (time leap) correction should be used before SYNC state was established for the first time */
  EthTSyn_MaxOutOfSyncCntOfRateMeasType MaxOutOfSyncCntOfRateMeas;  /**< Max out of sync count */
  EthTSyn_NrSyncCyclesForOfsCorrOfRateMeasType NrSyncCyclesForOfsCorrOfRateMeas;  /**< Number of sync cycles used for offset correction */
  EthTSyn_OfsJumpCorrThresholdNsOfRateMeasType OfsJumpCorrThresholdNsOfRateMeas;  /**< Offset threshold to switch from rate regulator to jump correction in nanoseconds */
  EthTSyn_RateMeasBufEndIdxOfRateMeasType RateMeasBufEndIdxOfRateMeas;  /**< the end index of the 1:n relation pointing to EthTSyn_RateMeasBuf */
  EthTSyn_RateMeasBufLengthOfRateMeasType RateMeasBufLengthOfRateMeas;  /**< the number of relations pointing to EthTSyn_RateMeasBuf */
  EthTSyn_RateMeasBufStartIdxOfRateMeasType RateMeasBufStartIdxOfRateMeas;  /**< the start index of the 1:n relation pointing to EthTSyn_RateMeasBuf */
  EthTSyn_SyncPrecisionLimitNsOfRateMeasType SyncPrecisionLimitNsOfRateMeas;  /**< The sync precision limit in nanoseconds */
} EthTSyn_RateMeasType;

/**   \brief  type used in EthTSyn_RateMeasBuf */
typedef struct sEthTSyn_RateMeasBufType
{
  EthTSyn_AccumulatedMasterTimeDiffOfRateMeasBufType AccumulatedMasterTimeDiffOfRateMeasBuf;  /**< Accumulated master time diff */
  EthTSyn_AccumulatedSwtTimeDiffOfRateMeasBufType AccumulatedSwtTimeDiffOfRateMeasBuf;  /**< Accumulated switch time diff */
  EthTSyn_ActiveOfRateMeasBufType ActiveOfRateMeasBuf;  /**< Measurement is currently running */
  EthTSyn_ActiveNrOfSyncCyclesOfRateMeasBufType ActiveNrOfSyncCyclesOfRateMeasBuf;  /**< Duration of the measurement in sync cycles */
} EthTSyn_RateMeasBufType;

/**   \brief  type used in EthTSyn_RateMeasDyn */
typedef struct sEthTSyn_RateMeasDynType
{
  EthTSyn_LastCorrectedOffsetNsOfRateMeasDynType LastCorrectedOffsetNsOfRateMeasDyn;  /**< Switch offset which was corrected by time leap at the last synchronization event */
  EthTSyn_OutOfSyncCntOfRateMeasDynType OutOfSyncCntOfRateMeasDyn;  /**< Current out of sync count of the switch (cascade) */
  EthTSyn_StateOfRateMeasDynType StateOfRateMeasDyn;  /**< State of the RateMeas instance */
  EthTSyn_SyncCycleCounterOfRateMeasDynType SyncCycleCounterOfRateMeasDyn;  /**< Counts the number of sync cycles since rate regulation started */
  EthTSyn_SyncCycleCounterRestartedOfRateMeasDynType SyncCycleCounterRestartedOfRateMeasDyn;  /**< Counter was restarted since last synchronization */
  EthTSyn_WasSyncReachedOfRateMeasDynType WasSyncReachedOfRateMeasDyn;  /**< Indicating if sync state SYNC was reached at least once */
  EthTSyn_SwtTimeSync_TimestampInfoStructType CurrTsInfoOfRateMeasDyn;  /**< Switch time sync timestamp info stored at current synchronization event */
  EthTSyn_SwtTimeSync_TimestampInfoStructType PrevTsInfoOfRateMeasDyn;  /**< Switch time sync timestamp info stored at last synchronization event */
} EthTSyn_RateMeasDynType;

/**   \brief  type used in EthTSyn_SiteSyncSyncTx */
typedef struct sEthTSyn_SiteSyncSyncTxType
{
  EthTSyn_BridgeTxMasterPortEndIdxOfSiteSyncSyncTxType BridgeTxMasterPortEndIdxOfSiteSyncSyncTx;  /**< the end index of the 1:n relation pointing to EthTSyn_BridgeTxMasterPort */
  EthTSyn_BridgeTxMasterPortStartIdxOfSiteSyncSyncTxType BridgeTxMasterPortStartIdxOfSiteSyncSyncTx;  /**< the start index of the 1:n relation pointing to EthTSyn_BridgeTxMasterPort */
  EthTSyn_NumMsgFwdRetryOfSiteSyncSyncTxType NumMsgFwdRetryOfSiteSyncSyncTx;  /**< Number of message forward retries in a bridge configuration */
} EthTSyn_SiteSyncSyncTxType;

/**   \brief  type used in EthTSyn_SiteSyncSyncTxDyn */
typedef struct sEthTSyn_SiteSyncSyncTxDynType
{
  EthTSyn_FwdRetryCntOfSiteSyncSyncTxDynType FwdRetryCntOfSiteSyncSyncTxDyn;  /**< Number of transmission retries for ongoing Sync/FollowUp forwarding */
  EthTSyn_StateOfSiteSyncSyncTxDynType StateOfSiteSyncSyncTxDyn;  /**< State of the SiteSyncSyncTx unit instance */
  EthTSyn_MsgHdrType LastMsgHdrOfSiteSyncSyncTxDyn;  /**< The header of the Sync/FollowUp message which was provided for transmission last. */
  EthTSyn_TsMgmtType LastSyncRefTsMgmtOfSiteSyncSyncTxDyn;  /**< Reference timestamp management of the last Sync message. */
  EthTSyn_PdelayType SlavePdelayNsOfSiteSyncSyncTxDyn;  /**< Pdelay of the slave port upon reception of the Sync message (in nanoseconds) */
} EthTSyn_SiteSyncSyncTxDynType;

/**   \brief  type used in EthTSyn_SlaveRxData */
typedef struct sEthTSyn_SlaveRxDataType
{
  EthTSyn_AnnounceRcvSmIdxOfSlaveRxDataType AnnounceRcvSmIdxOfSlaveRxData;  /**< the index of the 0:1 relation pointing to EthTSyn_AnnounceRcvSm */
  EthTSyn_SlaveRxMasterClockIdDynIdxOfSlaveRxDataType SlaveRxMasterClockIdDynIdxOfSlaveRxData;  /**< the index of the 0:1 relation pointing to EthTSyn_SlaveRxMasterClockIdDyn */
  EthTSyn_SlaveRxSrcPortIdCheckClockIdIdxOfSlaveRxDataType SlaveRxSrcPortIdCheckClockIdIdxOfSlaveRxData;  /**< the index of the 0:1 relation pointing to EthTSyn_SlaveRxSrcPortIdCheckClockId */
  EthTSyn_SyncRcvSmIdxOfSlaveRxDataType SyncRcvSmIdxOfSlaveRxData;  /**< the index of the 1:1 relation pointing to EthTSyn_SyncRcvSm */
} EthTSyn_SlaveRxDataType;

/**   \brief  type used in EthTSyn_SlaveRxDataHandler */
typedef struct sEthTSyn_SlaveRxDataHandlerType
{
  EthTSyn_ComCtrlPortIdxOfSlaveRxDataHandlerType ComCtrlPortIdxOfSlaveRxDataHandler;  /**< the index of the 1:1 relation pointing to EthTSyn_ComCtrlPort */
  EthTSyn_SlaveRxDataExternalIdxOfSlaveRxDataHandlerType SlaveRxDataExternalIdxOfSlaveRxDataHandler;  /**< the index of the 1:1 relation pointing to EthTSyn_SlaveRxData */
} EthTSyn_SlaveRxDataHandlerType;

/**   \brief  type used in EthTSyn_SlaveRxMasterClockIdDyn */
typedef struct sEthTSyn_SlaveRxMasterClockIdDynType
{
  EthTSyn_ValidMasterClockIdOfSlaveRxMasterClockIdDynType ValidMasterClockIdOfSlaveRxMasterClockIdDyn;  /**< Clock Id of the valid master. Only valid when 'ValidMasterSet' == TRUE */
  EthTSyn_ValidMasterSetOfSlaveRxMasterClockIdDynType ValidMasterSetOfSlaveRxMasterClockIdDyn;  /**< Indicating if the valid master clock id is set */
} EthTSyn_SlaveRxMasterClockIdDynType;

/**   \brief  type used in EthTSyn_SwtTimeSyncSm */
typedef struct sEthTSyn_SwtTimeSyncSmType
{
  EthTSyn_ApplyRateRatioToSlaveSwitchesOfSwtTimeSyncSmType ApplyRateRatioToSlaveSwitchesOfSwtTimeSyncSm;  /**< Indicating if rate ratio has to be applied to slave switches separately */
  EthTSyn_EthIfSwitchIdxOfSwtTimeSyncSmType EthIfSwitchIdxOfSwtTimeSyncSm;  /**< Index of the Master switch in the context of the EthIf */
  EthTSyn_RateMeasIdxOfSwtTimeSyncSmType RateMeasIdxOfSwtTimeSyncSm;  /**< the index of the 1:1 relation pointing to EthTSyn_RateMeas */
  EthTSyn_SlaveSwitchIdxListEndIdxOfSwtTimeSyncSmType SlaveSwitchIdxListEndIdxOfSwtTimeSyncSm;  /**< the end index of the 0:n relation pointing to EthTSyn_SlaveSwitchIdxList */
  EthTSyn_SlaveSwitchIdxListStartIdxOfSwtTimeSyncSmType SlaveSwitchIdxListStartIdxOfSwtTimeSyncSm;  /**< the start index of the 0:n relation pointing to EthTSyn_SlaveSwitchIdxList */
  EthTSyn_SyncEventTimeoutOfSwtTimeSyncSmType SyncEventTimeoutOfSwtTimeSyncSm;  /**< Timeout for sync event */
  EthTSyn_SwtTimeSync_SwtSyncStateChgFctPtrType SwtSyncStateChgFctPtrOfSwtTimeSyncSm;  /**< User notification for changes of the sync state */
} EthTSyn_SwtTimeSyncSmType;

/**   \brief  type used in EthTSyn_SwtTimeSyncSmDyn */
typedef struct sEthTSyn_SwtTimeSyncSmDynType
{
  EthTSyn_SyncEventTimeoutCntOfSwtTimeSyncSmDynType SyncEventTimeoutCntOfSwtTimeSyncSmDyn;  /**< Sync event timeout counter */
  EthTSyn_StateOfSwtTimeSyncSmDynType StateOfSwtTimeSyncSmDyn;  /**< State of the switch time sync state machine */
  EthTSyn_SyncStateType SwtSyncStateOfSwtTimeSyncSmDyn;  /**< Current valid sync state of the switch (cascade) */
  EthTSyn_SwtTimeSync_TimestampInfoStructType TimeStampInfoOfSwtTimeSyncSmDyn;  /**< Switch time sync timestamp info stored at current synchronization event */
} EthTSyn_SwtTimeSyncSmDynType;

/**   \brief  type used in EthTSyn_SyncRcvSm */
typedef struct sEthTSyn_SyncRcvSmType
{
  EthTSyn_FollowUpRxTimeoutOfSyncRcvSmType FollowUpRxTimeoutOfSyncRcvSm;  /**< Allowed delay between reception of a Sync and the corresponding FollowUp message in MainFunction cycles */
  EthTSyn_FupRxHandlerIdxOfSyncRcvSmType FupRxHandlerIdxOfSyncRcvSm;  /**< the index of the 1:1 relation pointing to EthTSyn_FupRxHandler */
  EthTSyn_PortParamStatsDynIdxOfSyncRcvSmType PortParamStatsDynIdxOfSyncRcvSm;  /**< the index of the 0:1 relation pointing to EthTSyn_PortParamStatsDyn */
} EthTSyn_SyncRcvSmType;

/**   \brief  type used in EthTSyn_SyncRcvSmDyn */
typedef struct sEthTSyn_SyncRcvSmDynType
{
  EthTSyn_SyncSrcClockIdOfSyncRcvSmDynType SyncSrcClockIdOfSyncRcvSmDyn;  /**< Source clock identity of the received Sync message */
  EthTSyn_FupRxTimeoutCntOfSyncRcvSmDynType FupRxTimeoutCntOfSyncRcvSmDyn;  /**< FollowUp reception timeout counter */
  EthTSyn_SyncSequenceIdOfSyncRcvSmDynType SyncSequenceIdOfSyncRcvSmDyn;  /**< SequenceId of the received Sync message */
  EthTSyn_SyncSrcPortNumOfSyncRcvSmDynType SyncSrcPortNumOfSyncRcvSmDyn;  /**< Source port number of the received Sync message */
  EthTSyn_AnySyncReceivedOfSyncRcvSmDynType AnySyncReceivedOfSyncRcvSmDyn;  /**< Indicating if any Sync message was received by the SyncRcvSm yet */
  EthTSyn_ResetRequestedOfSyncRcvSmDynType ResetRequestedOfSyncRcvSmDyn;  /**< Indicating if a reset of the state machine shall be triggered */
  EthTSyn_StateOfSyncRcvSmDynType StateOfSyncRcvSmDyn;  /**< State of the SyncRcvSm */
  EthTSyn_SyncRxTimeInfoType SyncRxTimeInfoOfSyncRcvSmDyn;  /**< Time information of the received Sync message */
} EthTSyn_SyncRcvSmDynType;

/**   \brief  type used in EthTSyn_SyncSendSm */
typedef struct sEthTSyn_SyncSendSmType
{
  EthTSyn_ImmediateTimeSyncOfSyncSendSmType ImmediateTimeSyncOfSyncSendSm;  /**< Is immediate time sync enabled */
  EthTSyn_SyncLogMsgIntervalOfSyncSendSmType SyncLogMsgIntervalOfSyncSendSm;  /**< Log message interval of the Sync message */
  EthTSyn_CrcHndlIdxOfSyncSendSmType CrcHndlIdxOfSyncSendSm;  /**< the index of the 0:1 relation pointing to EthTSyn_CrcHndl */
  EthTSyn_CrcTimeFlagsOfSyncSendSmType CrcTimeFlagsOfSyncSendSm;  /**< Flags indicating which message fields should be used for Crc calculation */
  EthTSyn_CyclicMsgResumeCntOfSyncSendSmType CyclicMsgResumeCntOfSyncSendSm;  /**< The cyclic message resume time in MainFunction cycles */
  EthTSyn_FupTxLenOfSyncSendSmType FupTxLenOfSyncSendSm;  /**< Length of a FollowUp message transmitted by the master port */
  EthTSyn_PortSyncSendSmIdxOfSyncSendSmType PortSyncSendSmIdxOfSyncSendSm;  /**< the index of the 1:1 relation pointing to EthTSyn_PortSyncSendSm */
  EthTSyn_SyncSendIntervalOfSyncSendSmType SyncSendIntervalOfSyncSendSm;  /**< Sync transmit interval in MainFunction cycles */
  EthTSyn_TimeBaseUpdateCounterIdxOfSyncSendSmType TimeBaseUpdateCounterIdxOfSyncSendSm;  /**< the index of the 0:1 relation pointing to EthTSyn_TimeBaseUpdateCounter */
  EthTSyn_TxCrcSecuredEnumType TxCrcSecuredOfSyncSendSm;  /**< Crc method for transmitted follow up messages */
} EthTSyn_SyncSendSmType;

/**   \brief  type used in EthTSyn_SyncSendSmDyn */
typedef struct sEthTSyn_SyncSendSmDynType
{
  EthTSyn_FupCorrFieldOfSyncSendSmDynType FupCorrFieldOfSyncSendSmDyn;  /**< Value of the correction field for a FollowUp message */
  EthTSyn_TxIntervalCntOfSyncSendSmDynType TxIntervalCntOfSyncSendSmDyn;  /**< Sync Tx interval counter: decrement with each main function call */
  EthTSyn_SequenceIdOfSyncSendSmDynType SequenceIdOfSyncSendSmDyn;  /**< SequenceId */
  EthTSyn_SmResetRequestedOfSyncSendSmDynType SmResetRequestedOfSyncSendSmDyn;  /**< Indicates if the SyncSend state machine must be reset */
  EthTSyn_StateOfSyncSendSmDynType StateOfSyncSendSmDyn;  /**< The state of the SyncSend state machine */
  EthTSyn_GlobalTimestampType PreciseOriginTsOfSyncSendSmDyn;  /**< Precise origin timestamp */
  EthTSyn_SyncTxInfoType SyncTxInfoOfSyncSendSmDyn;  /**< Time information (virtual and global time, time base status and user data) when Sync transmission is started */
} EthTSyn_SyncSendSmDynType;

/**   \brief  type used in EthTSyn_TimeBaseUpdateCounter */
typedef struct sEthTSyn_TimeBaseUpdateCounterType
{
  StbM_SynchronizedTimeBaseType SynchronizedTimeBaseIdOfTimeBaseUpdateCounter;  /**< Index of the referenced Synchronized Time Base */
} EthTSyn_TimeBaseUpdateCounterType;

/**   \brief  type used in EthTSyn_TimeBaseUpdateCounterDyn */
typedef struct sEthTSyn_TimeBaseUpdateCounterDynType
{
  EthTSyn_UpdatedOfTimeBaseUpdateCounterDynType UpdatedOfTimeBaseUpdateCounterDyn;  /**< Indicating if Value changes during current Mf-cycle. */
  EthTSyn_ValueOfTimeBaseUpdateCounterDynType ValueOfTimeBaseUpdateCounterDyn;  /**< Last value of the synchronized time base update counter. */
} EthTSyn_TimeBaseUpdateCounterDynType;

/**   \brief  type used in EthTSyn_TxConfContext */
typedef struct sEthTSyn_TxConfContextType
{
  EthTSyn_ComCtrlPortIdxOfTxConfContextType ComCtrlPortIdxOfTxConfContext;  /**< the index of the 1:1 relation pointing to EthTSyn_ComCtrlPort */
  EthTSyn_TxSmOfTxConfContextType TxSmOfTxConfContext;  /**< the enum value of the according target of the 1:1 relation pointing to one of EthTSyn_PortSyncSendSm,EthTSyn_PdReqSm,EthTSyn_PdRespSm */
  EthTSyn_TxSmIdxOfTxConfContextType TxSmIdxOfTxConfContext;  /**< the index of the 1:1 relation pointing to one of EthTSyn_PortSyncSendSm,EthTSyn_PdReqSm,EthTSyn_PdRespSm */
} EthTSyn_TxConfContextType;

/**   \brief  type used in EthTSyn_TxConfContextDyn */
typedef struct sEthTSyn_TxConfContextDynType
{
  EthTSyn_ActiveOfTxConfContextDynType ActiveOfTxConfContextDyn;  /**< Indicates if Tx confirmation context is active. */
  EthTSyn_BufferIdxOfTxConfContextDynType BufferIdxOfTxConfContextDyn;  /**< Ethernet Tx buffer currently used by this Tx confirmation context. */
  EthTSyn_TxConfContextNextActiveIdxOfTxConfContextDynType TxConfContextNextActiveIdxOfTxConfContextDyn;  /**< the index of the 0:1 relation pointing to EthTSyn_TxConfContext */
  EthTSyn_TxConfContextPrevActiveIdxOfTxConfContextDynType TxConfContextPrevActiveIdxOfTxConfContextDyn;  /**< the index of the 0:1 relation pointing to EthTSyn_TxConfContext */
} EthTSyn_TxConfContextDynType;

/** 
  \}
*/ 

/** 
  \defgroup  EthTSynPCRootPointerTypes  EthTSyn Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to EthTSyn_AnnounceRcvSm */
typedef P2CONST(EthTSyn_AnnounceRcvSmType, TYPEDEF, ETHTSYN_CONST) EthTSyn_AnnounceRcvSmPtrType;

/**   \brief  type used to point to EthTSyn_AnnounceRcvSmDyn */
typedef P2VAR(EthTSyn_AnnounceRcvSmDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_AnnounceRcvSmDynPtrType;

/**   \brief  type used to point to EthTSyn_AnnounceSendSm */
typedef P2CONST(EthTSyn_AnnounceSendSmType, TYPEDEF, ETHTSYN_CONST) EthTSyn_AnnounceSendSmPtrType;

/**   \brief  type used to point to EthTSyn_AnnounceSendSmDyn */
typedef P2VAR(EthTSyn_AnnounceSendSmDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_AnnounceSendSmDynPtrType;

/**   \brief  type used to point to EthTSyn_BridgeTxMasterPort */
typedef P2CONST(EthTSyn_BridgeTxMasterPortType, TYPEDEF, ETHTSYN_CONST) EthTSyn_BridgeTxMasterPortPtrType;

/**   \brief  type used to point to EthTSyn_BridgeTxMasterPortDyn */
typedef P2VAR(EthTSyn_BridgeTxMasterPortDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_BridgeTxMasterPortDynPtrType;

/**   \brief  type used to point to EthTSyn_ComCtrlEthIfCtrl */
typedef P2CONST(EthTSyn_ComCtrlEthIfCtrlType, TYPEDEF, ETHTSYN_CONST) EthTSyn_ComCtrlEthIfCtrlPtrType;

/**   \brief  type used to point to EthTSyn_ComCtrlEthIfCtrlDyn */
typedef P2VAR(EthTSyn_ComCtrlEthIfCtrlDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_ComCtrlEthIfCtrlDynPtrType;

/**   \brief  type used to point to EthTSyn_ComCtrlPhysPort */
typedef P2CONST(EthTSyn_ComCtrlPhysPortType, TYPEDEF, ETHTSYN_CONST) EthTSyn_ComCtrlPhysPortPtrType;

/**   \brief  type used to point to EthTSyn_ComCtrlPhysPortDyn */
typedef P2VAR(EthTSyn_ComCtrlPhysPortDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_ComCtrlPhysPortDynPtrType;

/**   \brief  type used to point to EthTSyn_ComCtrlPort */
typedef P2CONST(EthTSyn_ComCtrlPortType, TYPEDEF, ETHTSYN_CONST) EthTSyn_ComCtrlPortPtrType;

/**   \brief  type used to point to EthTSyn_ComCtrlPortInd */
typedef P2CONST(EthTSyn_ComCtrlPortIndType, TYPEDEF, ETHTSYN_CONST) EthTSyn_ComCtrlPortIndPtrType;

/**   \brief  type used to point to EthTSyn_ComCtrlTimeDomain */
typedef P2CONST(EthTSyn_ComCtrlTimeDomainType, TYPEDEF, ETHTSYN_CONST) EthTSyn_ComCtrlTimeDomainPtrType;

/**   \brief  type used to point to EthTSyn_CrcHndl */
typedef P2CONST(EthTSyn_CrcHndlType, TYPEDEF, ETHTSYN_CONST) EthTSyn_CrcHndlPtrType;

/**   \brief  type used to point to EthTSyn_DestinationMac */
typedef P2CONST(EthTSyn_DestinationMacType, TYPEDEF, ETHTSYN_CONST) EthTSyn_DestinationMacPtrType;

/**   \brief  type used to point to EthTSyn_DestinationMacInd */
typedef P2CONST(EthTSyn_DestinationMacIndType, TYPEDEF, ETHTSYN_CONST) EthTSyn_DestinationMacIndPtrType;

/**   \brief  type used to point to EthTSyn_FupDataIdList */
typedef P2CONST(EthTSyn_FupDataIdListType, TYPEDEF, ETHTSYN_CONST) EthTSyn_FupDataIdListPtrType;

/**   \brief  type used to point to EthTSyn_FupRxHandler */
typedef P2CONST(EthTSyn_FupRxHandlerType, TYPEDEF, ETHTSYN_CONST) EthTSyn_FupRxHandlerPtrType;

/**   \brief  type used to point to EthTSyn_MsgSentCbkBuf */
typedef P2VAR(EthTSyn_MsgSentCbkBufType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_MsgSentCbkBufPtrType;

/**   \brief  type used to point to EthTSyn_OffsetTimeDomain */
typedef P2CONST(EthTSyn_OffsetTimeDomainType, TYPEDEF, ETHTSYN_CONST) EthTSyn_OffsetTimeDomainPtrType;

/**   \brief  type used to point to EthTSyn_PdReqSm */
typedef P2CONST(EthTSyn_PdReqSmType, TYPEDEF, ETHTSYN_CONST) EthTSyn_PdReqSmPtrType;

/**   \brief  type used to point to EthTSyn_PdReqSmDyn */
typedef P2VAR(EthTSyn_PdReqSmDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_PdReqSmDynPtrType;

/**   \brief  type used to point to EthTSyn_RefGlobalTimeOfPdReqSmDyn */
typedef P2VAR(StbM_TimeStampShortType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_RefGlobalTimeOfPdReqSmDynPtrType;

/**   \brief  type used to point to EthTSyn_RefLocalTimeOfPdReqSmDyn */
typedef P2VAR(StbM_VirtualLocalTimeType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_RefLocalTimeOfPdReqSmDynPtrType;

/**   \brief  type used to point to EthTSyn_PdReqTrcvDyn */
typedef P2VAR(EthTSyn_PdReqTrcvDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_PdReqTrcvDynPtrType;

/**   \brief  type used to point to EthTSyn_PdReqEgrTsMgmtOfPdReqTrcvDyn */
typedef P2VAR(EthTSyn_TsMgmtType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_PdReqEgrTsMgmtOfPdReqTrcvDynPtrType;

/**   \brief  type used to point to EthTSyn_PdRespIngrTsMgmtOfPdReqTrcvDyn */
typedef P2VAR(EthTSyn_TsMgmtType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_PdRespIngrTsMgmtOfPdReqTrcvDynPtrType;

/**   \brief  type used to point to EthTSyn_ReqReceivedTsOfPdReqTrcvDyn */
typedef P2VAR(EthTSyn_GlobalTimestampType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_ReqReceivedTsOfPdReqTrcvDynPtrType;

/**   \brief  type used to point to EthTSyn_RespOriginTsOfPdReqTrcvDyn */
typedef P2VAR(EthTSyn_GlobalTimestampType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_RespOriginTsOfPdReqTrcvDynPtrType;

/**   \brief  type used to point to EthTSyn_PdRespSm */
typedef P2CONST(EthTSyn_PdRespSmType, TYPEDEF, ETHTSYN_CONST) EthTSyn_PdRespSmPtrType;

/**   \brief  type used to point to EthTSyn_PdRespSmDyn */
typedef P2VAR(EthTSyn_PdRespSmDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_PdRespSmDynPtrType;

/**   \brief  type used to point to EthTSyn_PdReqRcvdTsOfPdRespSmDyn */
typedef P2VAR(EthTSyn_GlobalTimestampType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_PdReqRcvdTsOfPdRespSmDynPtrType;

/**   \brief  type used to point to EthTSyn_PdRespOrgTsOfPdRespSmDyn */
typedef P2VAR(EthTSyn_GlobalTimestampType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_PdRespOrgTsOfPdRespSmDynPtrType;

/**   \brief  type used to point to EthTSyn_PortParamStatsDyn */
typedef P2VAR(EthTSyn_PortParamStatsDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_PortParamStatsDynPtrType;

/**   \brief  type used to point to EthTSyn_PdLostRespExceededCountOfPortParamStatsDyn */
typedef P2VAR(EthTSyn_PdLostRespExceededCountOfPortParamStatsDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_PdLostRespExceededCountOfPortParamStatsDynPtrType;

/**   \brief  type used to point to EthTSyn_RxAnnounceCountOfPortParamStatsDyn */
typedef P2VAR(EthTSyn_RxAnnounceCountOfPortParamStatsDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_RxAnnounceCountOfPortParamStatsDynPtrType;

/**   \brief  type used to point to EthTSyn_RxDiscardCountOfPortParamStatsDyn */
typedef P2VAR(EthTSyn_RxDiscardCountOfPortParamStatsDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_RxDiscardCountOfPortParamStatsDynPtrType;

/**   \brief  type used to point to EthTSyn_RxFupCountOfPortParamStatsDyn */
typedef P2VAR(EthTSyn_RxFupCountOfPortParamStatsDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_RxFupCountOfPortParamStatsDynPtrType;

/**   \brief  type used to point to EthTSyn_RxPdReqCountOfPortParamStatsDyn */
typedef P2VAR(EthTSyn_RxPdReqCountOfPortParamStatsDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_RxPdReqCountOfPortParamStatsDynPtrType;

/**   \brief  type used to point to EthTSyn_RxPdRespCountOfPortParamStatsDyn */
typedef P2VAR(EthTSyn_RxPdRespCountOfPortParamStatsDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_RxPdRespCountOfPortParamStatsDynPtrType;

/**   \brief  type used to point to EthTSyn_RxPdRespFupCountOfPortParamStatsDyn */
typedef P2VAR(EthTSyn_RxPdRespFupCountOfPortParamStatsDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_RxPdRespFupCountOfPortParamStatsDynPtrType;

/**   \brief  type used to point to EthTSyn_RxSyncCountOfPortParamStatsDyn */
typedef P2VAR(EthTSyn_RxSyncCountOfPortParamStatsDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_RxSyncCountOfPortParamStatsDynPtrType;

/**   \brief  type used to point to EthTSyn_TxAnnounceCountOfPortParamStatsDyn */
typedef P2VAR(EthTSyn_TxAnnounceCountOfPortParamStatsDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_TxAnnounceCountOfPortParamStatsDynPtrType;

/**   \brief  type used to point to EthTSyn_TxFupCountOfPortParamStatsDyn */
typedef P2VAR(EthTSyn_TxFupCountOfPortParamStatsDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_TxFupCountOfPortParamStatsDynPtrType;

/**   \brief  type used to point to EthTSyn_TxPdReqCountOfPortParamStatsDyn */
typedef P2VAR(EthTSyn_TxPdReqCountOfPortParamStatsDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_TxPdReqCountOfPortParamStatsDynPtrType;

/**   \brief  type used to point to EthTSyn_TxPdRespCountOfPortParamStatsDyn */
typedef P2VAR(EthTSyn_TxPdRespCountOfPortParamStatsDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_TxPdRespCountOfPortParamStatsDynPtrType;

/**   \brief  type used to point to EthTSyn_TxPdRespFupCountOfPortParamStatsDyn */
typedef P2VAR(EthTSyn_TxPdRespFupCountOfPortParamStatsDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_TxPdRespFupCountOfPortParamStatsDynPtrType;

/**   \brief  type used to point to EthTSyn_TxSyncCountOfPortParamStatsDyn */
typedef P2VAR(EthTSyn_TxSyncCountOfPortParamStatsDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_TxSyncCountOfPortParamStatsDynPtrType;

/**   \brief  type used to point to EthTSyn_PortSyncSendSm */
typedef P2CONST(EthTSyn_PortSyncSendSmType, TYPEDEF, ETHTSYN_CONST) EthTSyn_PortSyncSendSmPtrType;

/**   \brief  type used to point to EthTSyn_PortSyncSendSmDyn */
typedef P2VAR(EthTSyn_PortSyncSendSmDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_PortSyncSendSmDynPtrType;

/**   \brief  type used to point to EthTSyn_EgrTsInfoOfPortSyncSendSmDyn */
typedef P2VAR(EthTSyn_TsInfoType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_EgrTsInfoOfPortSyncSendSmDynPtrType;

/**   \brief  type used to point to EthTSyn_RateMeas */
typedef P2CONST(EthTSyn_RateMeasType, TYPEDEF, ETHTSYN_CONST) EthTSyn_RateMeasPtrType;

/**   \brief  type used to point to EthTSyn_RateMeasBuf */
typedef P2VAR(EthTSyn_RateMeasBufType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_RateMeasBufPtrType;

/**   \brief  type used to point to EthTSyn_RateMeasDyn */
typedef P2VAR(EthTSyn_RateMeasDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_RateMeasDynPtrType;

/**   \brief  type used to point to EthTSyn_CurrTsInfoOfRateMeasDyn */
typedef P2VAR(EthTSyn_SwtTimeSync_TimestampInfoStructType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_CurrTsInfoOfRateMeasDynPtrType;

/**   \brief  type used to point to EthTSyn_PrevTsInfoOfRateMeasDyn */
typedef P2VAR(EthTSyn_SwtTimeSync_TimestampInfoStructType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_PrevTsInfoOfRateMeasDynPtrType;

/**   \brief  type used to point to EthTSyn_SiteSyncSyncTx */
typedef P2CONST(EthTSyn_SiteSyncSyncTxType, TYPEDEF, ETHTSYN_CONST) EthTSyn_SiteSyncSyncTxPtrType;

/**   \brief  type used to point to EthTSyn_SiteSyncSyncTxDyn */
typedef P2VAR(EthTSyn_SiteSyncSyncTxDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_SiteSyncSyncTxDynPtrType;

/**   \brief  type used to point to EthTSyn_LastMsgHdrOfSiteSyncSyncTxDyn */
typedef P2VAR(EthTSyn_MsgHdrType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_LastMsgHdrOfSiteSyncSyncTxDynPtrType;

/**   \brief  type used to point to EthTSyn_LastSyncRefTsMgmtOfSiteSyncSyncTxDyn */
typedef P2VAR(EthTSyn_TsMgmtType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_LastSyncRefTsMgmtOfSiteSyncSyncTxDynPtrType;

/**   \brief  type used to point to EthTSyn_SlaveRxData */
typedef P2CONST(EthTSyn_SlaveRxDataType, TYPEDEF, ETHTSYN_CONST) EthTSyn_SlaveRxDataPtrType;

/**   \brief  type used to point to EthTSyn_SlaveRxDataHandler */
typedef P2CONST(EthTSyn_SlaveRxDataHandlerType, TYPEDEF, ETHTSYN_CONST) EthTSyn_SlaveRxDataHandlerPtrType;

/**   \brief  type used to point to EthTSyn_SlaveRxMasterClockIdDyn */
typedef P2VAR(EthTSyn_SlaveRxMasterClockIdDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_SlaveRxMasterClockIdDynPtrType;

/**   \brief  type used to point to EthTSyn_SlaveRxSrcPortIdCheckClockId */
typedef P2CONST(EthTSyn_SlaveRxSrcPortIdCheckClockIdType, TYPEDEF, ETHTSYN_CONST) EthTSyn_SlaveRxSrcPortIdCheckClockIdPtrType;

/**   \brief  type used to point to EthTSyn_SlaveSwitchIdxList */
typedef P2CONST(EthTSyn_SlaveSwitchIdxListType, TYPEDEF, ETHTSYN_CONST) EthTSyn_SlaveSwitchIdxListPtrType;

/**   \brief  type used to point to EthTSyn_SwtTimeSyncSm */
typedef P2CONST(EthTSyn_SwtTimeSyncSmType, TYPEDEF, ETHTSYN_CONST) EthTSyn_SwtTimeSyncSmPtrType;

/**   \brief  type used to point to EthTSyn_SwtTimeSyncSmDyn */
typedef P2VAR(EthTSyn_SwtTimeSyncSmDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_SwtTimeSyncSmDynPtrType;

/**   \brief  type used to point to EthTSyn_SwtSyncStateOfSwtTimeSyncSmDyn */
typedef P2VAR(EthTSyn_SyncStateType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_SwtSyncStateOfSwtTimeSyncSmDynPtrType;

/**   \brief  type used to point to EthTSyn_TimeStampInfoOfSwtTimeSyncSmDyn */
typedef P2VAR(EthTSyn_SwtTimeSync_TimestampInfoStructType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_TimeStampInfoOfSwtTimeSyncSmDynPtrType;

/**   \brief  type used to point to EthTSyn_SyncRcvSm */
typedef P2CONST(EthTSyn_SyncRcvSmType, TYPEDEF, ETHTSYN_CONST) EthTSyn_SyncRcvSmPtrType;

/**   \brief  type used to point to EthTSyn_SyncRcvSmDyn */
typedef P2VAR(EthTSyn_SyncRcvSmDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_SyncRcvSmDynPtrType;

/**   \brief  type used to point to EthTSyn_SyncRxTimeInfoOfSyncRcvSmDyn */
typedef P2VAR(EthTSyn_SyncRxTimeInfoType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_SyncRxTimeInfoOfSyncRcvSmDynPtrType;

/**   \brief  type used to point to EthTSyn_SyncSendSm */
typedef P2CONST(EthTSyn_SyncSendSmType, TYPEDEF, ETHTSYN_CONST) EthTSyn_SyncSendSmPtrType;

/**   \brief  type used to point to EthTSyn_SyncSendSmDyn */
typedef P2VAR(EthTSyn_SyncSendSmDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_SyncSendSmDynPtrType;

/**   \brief  type used to point to EthTSyn_PreciseOriginTsOfSyncSendSmDyn */
typedef P2VAR(EthTSyn_GlobalTimestampType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_PreciseOriginTsOfSyncSendSmDynPtrType;

/**   \brief  type used to point to EthTSyn_SyncTxInfoOfSyncSendSmDyn */
typedef P2VAR(EthTSyn_SyncTxInfoType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_SyncTxInfoOfSyncSendSmDynPtrType;

/**   \brief  type used to point to EthTSyn_TimeBaseUpdateCounter */
typedef P2CONST(EthTSyn_TimeBaseUpdateCounterType, TYPEDEF, ETHTSYN_CONST) EthTSyn_TimeBaseUpdateCounterPtrType;

/**   \brief  type used to point to EthTSyn_TimeBaseUpdateCounterDyn */
typedef P2VAR(EthTSyn_TimeBaseUpdateCounterDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_TimeBaseUpdateCounterDynPtrType;

/**   \brief  type used to point to EthTSyn_TxConfContext */
typedef P2CONST(EthTSyn_TxConfContextType, TYPEDEF, ETHTSYN_CONST) EthTSyn_TxConfContextPtrType;

/**   \brief  type used to point to EthTSyn_TxConfContextDyn */
typedef P2VAR(EthTSyn_TxConfContextDynType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_TxConfContextDynPtrType;

/**   \brief  type used to point to EthTSyn_TxConfContextDynActiveFirstIdx */
typedef P2VAR(EthTSyn_TxConfContextDynActiveFirstIdxType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_TxConfContextDynActiveFirstIdxPtrType;

/**   \brief  type used to point to EthTSyn_TxConfContextDynActiveLastIdx */
typedef P2VAR(EthTSyn_TxConfContextDynActiveLastIdxType, TYPEDEF, ETHTSYN_VAR_NO_INIT) EthTSyn_TxConfContextDynActiveLastIdxPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  EthTSynPCRootValueTypes  EthTSyn Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in EthTSyn_PCConfig */
typedef struct sEthTSyn_PCConfigType
{
  EthTSyn_AnnounceRcvSmPtrType AnnounceRcvSmOfPCConfig;  /**< the pointer to EthTSyn_AnnounceRcvSm */
  EthTSyn_AnnounceRcvSmDynPtrType AnnounceRcvSmDynOfPCConfig;  /**< the pointer to EthTSyn_AnnounceRcvSmDyn */
  EthTSyn_AnnounceSendSmPtrType AnnounceSendSmOfPCConfig;  /**< the pointer to EthTSyn_AnnounceSendSm */
  EthTSyn_AnnounceSendSmDynPtrType AnnounceSendSmDynOfPCConfig;  /**< the pointer to EthTSyn_AnnounceSendSmDyn */
  EthTSyn_BridgeTxMasterPortPtrType BridgeTxMasterPortOfPCConfig;  /**< the pointer to EthTSyn_BridgeTxMasterPort */
  EthTSyn_BridgeTxMasterPortDynPtrType BridgeTxMasterPortDynOfPCConfig;  /**< the pointer to EthTSyn_BridgeTxMasterPortDyn */
  EthTSyn_ComCtrlEthIfCtrlPtrType ComCtrlEthIfCtrlOfPCConfig;  /**< the pointer to EthTSyn_ComCtrlEthIfCtrl */
  EthTSyn_ComCtrlEthIfCtrlDynPtrType ComCtrlEthIfCtrlDynOfPCConfig;  /**< the pointer to EthTSyn_ComCtrlEthIfCtrlDyn */
  EthTSyn_ComCtrlPhysPortPtrType ComCtrlPhysPortOfPCConfig;  /**< the pointer to EthTSyn_ComCtrlPhysPort */
  EthTSyn_ComCtrlPhysPortDynPtrType ComCtrlPhysPortDynOfPCConfig;  /**< the pointer to EthTSyn_ComCtrlPhysPortDyn */
  EthTSyn_ComCtrlPortPtrType ComCtrlPortOfPCConfig;  /**< the pointer to EthTSyn_ComCtrlPort */
  EthTSyn_ComCtrlPortIndPtrType ComCtrlPortIndOfPCConfig;  /**< the pointer to EthTSyn_ComCtrlPortInd */
  EthTSyn_ComCtrlTimeDomainPtrType ComCtrlTimeDomainOfPCConfig;  /**< the pointer to EthTSyn_ComCtrlTimeDomain */
  EthTSyn_CrcHndlPtrType CrcHndlOfPCConfig;  /**< the pointer to EthTSyn_CrcHndl */
  EthTSyn_DestinationMacPtrType DestinationMacOfPCConfig;  /**< the pointer to EthTSyn_DestinationMac */
  EthTSyn_DestinationMacIndPtrType DestinationMacIndOfPCConfig;  /**< the pointer to EthTSyn_DestinationMacInd */
  EthTSyn_FupDataIdListPtrType FupDataIdListOfPCConfig;  /**< the pointer to EthTSyn_FupDataIdList */
  EthTSyn_FupRxHandlerPtrType FupRxHandlerOfPCConfig;  /**< the pointer to EthTSyn_FupRxHandler */
  EthTSyn_MsgSentCbkBufPtrType MsgSentCbkBufOfPCConfig;  /**< the pointer to EthTSyn_MsgSentCbkBuf */
  EthTSyn_OffsetTimeDomainPtrType OffsetTimeDomainOfPCConfig;  /**< the pointer to EthTSyn_OffsetTimeDomain */
  EthTSyn_PdReqSmPtrType PdReqSmOfPCConfig;  /**< the pointer to EthTSyn_PdReqSm */
  EthTSyn_PdReqSmDynPtrType PdReqSmDynOfPCConfig;  /**< the pointer to EthTSyn_PdReqSmDyn */
  EthTSyn_PdReqTrcvDynPtrType PdReqTrcvDynOfPCConfig;  /**< the pointer to EthTSyn_PdReqTrcvDyn */
  EthTSyn_PdRespSmPtrType PdRespSmOfPCConfig;  /**< the pointer to EthTSyn_PdRespSm */
  EthTSyn_PdRespSmDynPtrType PdRespSmDynOfPCConfig;  /**< the pointer to EthTSyn_PdRespSmDyn */
  EthTSyn_PortParamStatsDynPtrType PortParamStatsDynOfPCConfig;  /**< the pointer to EthTSyn_PortParamStatsDyn */
  EthTSyn_PortSyncSendSmPtrType PortSyncSendSmOfPCConfig;  /**< the pointer to EthTSyn_PortSyncSendSm */
  EthTSyn_PortSyncSendSmDynPtrType PortSyncSendSmDynOfPCConfig;  /**< the pointer to EthTSyn_PortSyncSendSmDyn */
  EthTSyn_RateMeasPtrType RateMeasOfPCConfig;  /**< the pointer to EthTSyn_RateMeas */
  EthTSyn_RateMeasBufPtrType RateMeasBufOfPCConfig;  /**< the pointer to EthTSyn_RateMeasBuf */
  EthTSyn_RateMeasDynPtrType RateMeasDynOfPCConfig;  /**< the pointer to EthTSyn_RateMeasDyn */
  EthTSyn_SiteSyncSyncTxPtrType SiteSyncSyncTxOfPCConfig;  /**< the pointer to EthTSyn_SiteSyncSyncTx */
  EthTSyn_SiteSyncSyncTxDynPtrType SiteSyncSyncTxDynOfPCConfig;  /**< the pointer to EthTSyn_SiteSyncSyncTxDyn */
  EthTSyn_SlaveRxDataPtrType SlaveRxDataOfPCConfig;  /**< the pointer to EthTSyn_SlaveRxData */
  EthTSyn_SlaveRxDataHandlerPtrType SlaveRxDataHandlerOfPCConfig;  /**< the pointer to EthTSyn_SlaveRxDataHandler */
  EthTSyn_SlaveRxMasterClockIdDynPtrType SlaveRxMasterClockIdDynOfPCConfig;  /**< the pointer to EthTSyn_SlaveRxMasterClockIdDyn */
  EthTSyn_SlaveRxSrcPortIdCheckClockIdPtrType SlaveRxSrcPortIdCheckClockIdOfPCConfig;  /**< the pointer to EthTSyn_SlaveRxSrcPortIdCheckClockId */
  EthTSyn_SlaveSwitchIdxListPtrType SlaveSwitchIdxListOfPCConfig;  /**< the pointer to EthTSyn_SlaveSwitchIdxList */
  EthTSyn_SwtTimeSyncSmPtrType SwtTimeSyncSmOfPCConfig;  /**< the pointer to EthTSyn_SwtTimeSyncSm */
  EthTSyn_SwtTimeSyncSmDynPtrType SwtTimeSyncSmDynOfPCConfig;  /**< the pointer to EthTSyn_SwtTimeSyncSmDyn */
  EthTSyn_SyncRcvSmPtrType SyncRcvSmOfPCConfig;  /**< the pointer to EthTSyn_SyncRcvSm */
  EthTSyn_SyncRcvSmDynPtrType SyncRcvSmDynOfPCConfig;  /**< the pointer to EthTSyn_SyncRcvSmDyn */
  EthTSyn_SyncSendSmPtrType SyncSendSmOfPCConfig;  /**< the pointer to EthTSyn_SyncSendSm */
  EthTSyn_SyncSendSmDynPtrType SyncSendSmDynOfPCConfig;  /**< the pointer to EthTSyn_SyncSendSmDyn */
  EthTSyn_TimeBaseUpdateCounterPtrType TimeBaseUpdateCounterOfPCConfig;  /**< the pointer to EthTSyn_TimeBaseUpdateCounter */
  EthTSyn_TimeBaseUpdateCounterDynPtrType TimeBaseUpdateCounterDynOfPCConfig;  /**< the pointer to EthTSyn_TimeBaseUpdateCounterDyn */
  EthTSyn_TxConfContextPtrType TxConfContextOfPCConfig;  /**< the pointer to EthTSyn_TxConfContext */
  EthTSyn_TxConfContextDynPtrType TxConfContextDynOfPCConfig;  /**< the pointer to EthTSyn_TxConfContextDyn */
  EthTSyn_TxConfContextDynActiveFirstIdxPtrType TxConfContextDynActiveFirstIdxOfPCConfig;  /**< the pointer to EthTSyn_TxConfContextDynActiveFirstIdx */
  EthTSyn_TxConfContextDynActiveLastIdxPtrType TxConfContextDynActiveLastIdxOfPCConfig;  /**< the pointer to EthTSyn_TxConfContextDynActiveLastIdx */
  EthTSyn_SizeOfAnnounceRcvSmType SizeOfAnnounceRcvSmOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_AnnounceRcvSm */
  EthTSyn_SizeOfAnnounceSendSmType SizeOfAnnounceSendSmOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_AnnounceSendSm */
  EthTSyn_SizeOfBridgeTxMasterPortType SizeOfBridgeTxMasterPortOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_BridgeTxMasterPort */
  EthTSyn_SizeOfComCtrlEthIfCtrlType SizeOfComCtrlEthIfCtrlOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_ComCtrlEthIfCtrl */
  EthTSyn_SizeOfComCtrlPhysPortType SizeOfComCtrlPhysPortOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_ComCtrlPhysPort */
  EthTSyn_SizeOfComCtrlPortType SizeOfComCtrlPortOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_ComCtrlPort */
  EthTSyn_SizeOfComCtrlPortIndType SizeOfComCtrlPortIndOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_ComCtrlPortInd */
  EthTSyn_SizeOfComCtrlTimeDomainType SizeOfComCtrlTimeDomainOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_ComCtrlTimeDomain */
  EthTSyn_SizeOfCrcHndlType SizeOfCrcHndlOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_CrcHndl */
  EthTSyn_SizeOfDestinationMacType SizeOfDestinationMacOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_DestinationMac */
  EthTSyn_SizeOfDestinationMacIndType SizeOfDestinationMacIndOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_DestinationMacInd */
  EthTSyn_SizeOfFupDataIdListType SizeOfFupDataIdListOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_FupDataIdList */
  EthTSyn_SizeOfFupRxHandlerType SizeOfFupRxHandlerOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_FupRxHandler */
  EthTSyn_SizeOfMsgSentCbkBufType SizeOfMsgSentCbkBufOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_MsgSentCbkBuf */
  EthTSyn_SizeOfOffsetTimeDomainType SizeOfOffsetTimeDomainOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_OffsetTimeDomain */
  EthTSyn_SizeOfPdReqSmType SizeOfPdReqSmOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_PdReqSm */
  EthTSyn_SizeOfPdRespSmType SizeOfPdRespSmOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_PdRespSm */
  EthTSyn_SizeOfPortParamStatsDynType SizeOfPortParamStatsDynOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_PortParamStatsDyn */
  EthTSyn_SizeOfPortSyncSendSmType SizeOfPortSyncSendSmOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_PortSyncSendSm */
  EthTSyn_SizeOfRateMeasType SizeOfRateMeasOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_RateMeas */
  EthTSyn_SizeOfRateMeasBufType SizeOfRateMeasBufOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_RateMeasBuf */
  EthTSyn_SizeOfSiteSyncSyncTxType SizeOfSiteSyncSyncTxOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_SiteSyncSyncTx */
  EthTSyn_SizeOfSlaveRxDataType SizeOfSlaveRxDataOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_SlaveRxData */
  EthTSyn_SizeOfSlaveRxDataHandlerType SizeOfSlaveRxDataHandlerOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_SlaveRxDataHandler */
  EthTSyn_SizeOfSlaveRxMasterClockIdDynType SizeOfSlaveRxMasterClockIdDynOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_SlaveRxMasterClockIdDyn */
  EthTSyn_SizeOfSlaveRxSrcPortIdCheckClockIdType SizeOfSlaveRxSrcPortIdCheckClockIdOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_SlaveRxSrcPortIdCheckClockId */
  EthTSyn_SizeOfSlaveSwitchIdxListType SizeOfSlaveSwitchIdxListOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_SlaveSwitchIdxList */
  EthTSyn_SizeOfSwtTimeSyncSmType SizeOfSwtTimeSyncSmOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_SwtTimeSyncSm */
  EthTSyn_SizeOfSyncRcvSmType SizeOfSyncRcvSmOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_SyncRcvSm */
  EthTSyn_SizeOfSyncSendSmType SizeOfSyncSendSmOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_SyncSendSm */
  EthTSyn_SizeOfTimeBaseUpdateCounterType SizeOfTimeBaseUpdateCounterOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_TimeBaseUpdateCounter */
  EthTSyn_SizeOfTxConfContextType SizeOfTxConfContextOfPCConfig;  /**< the number of accomplishable value elements in EthTSyn_TxConfContext */
} EthTSyn_PCConfigType;

typedef EthTSyn_PCConfigType EthTSyn_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/**   \brief  type to access EthTSyn_PCConfig in a symbol based style. */
typedef struct sEthTSyn_PCConfigsType
{
  EthTSyn_PCConfigType Config;  /**< [Config] */
} EthTSyn_PCConfigsType;

/** 
  \}
*/ 



#endif  /* ETHTSYN_GENERATED_COMPLEX_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: EthTSyn_GeneratedComplexTypes.h
 *********************************************************************************************************************/

