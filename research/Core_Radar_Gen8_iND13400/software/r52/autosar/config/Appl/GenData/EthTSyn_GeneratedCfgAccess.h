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
 *              File: EthTSyn_GeneratedCfgAccess.h
 *   Generation Time: 2026-08-27 14:12:20
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
#ifndef ETHTSYN_GENERATED_CFG_ACCESS_H
#define ETHTSYN_GENERATED_CFG_ACCESS_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATIONS
 *********************************************************************************************************************/
/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "EthTSyn_Lcfg.h" 

/**********************************************************************************************************************
 * GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined(ETHTSYN_LOCAL)
# define ETHTSYN_LOCAL static
#endif

#if !defined(ETHTSYN_LOCAL_INLINE)
# define ETHTSYN_LOCAL_INLINE LOCAL_INLINE
#endif

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  EthTSynPCGetRootDataMacros  EthTSyn Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define EthTSyn_GetAnnounceRcvSmDynOfPCConfig()                                                     EthTSyn_ConfigDataPtr->AnnounceRcvSmDynOfPCConfig
#define EthTSyn_GetAnnounceRcvSmOfPCConfig()                                                        EthTSyn_ConfigDataPtr->AnnounceRcvSmOfPCConfig
#define EthTSyn_GetAnnounceSendSmDynOfPCConfig()                                                    EthTSyn_ConfigDataPtr->AnnounceSendSmDynOfPCConfig
#define EthTSyn_GetAnnounceSendSmOfPCConfig()                                                       EthTSyn_ConfigDataPtr->AnnounceSendSmOfPCConfig
#define EthTSyn_GetBridgeTxMasterPortDynOfPCConfig()                                                EthTSyn_ConfigDataPtr->BridgeTxMasterPortDynOfPCConfig
#define EthTSyn_GetBridgeTxMasterPortOfPCConfig()                                                   EthTSyn_ConfigDataPtr->BridgeTxMasterPortOfPCConfig
#define EthTSyn_GetComCtrlEthIfCtrlDynOfPCConfig()                                                  EthTSyn_ConfigDataPtr->ComCtrlEthIfCtrlDynOfPCConfig
#define EthTSyn_GetComCtrlEthIfCtrlOfPCConfig()                                                     EthTSyn_ConfigDataPtr->ComCtrlEthIfCtrlOfPCConfig
#define EthTSyn_GetComCtrlPhysPortDynOfPCConfig()                                                   EthTSyn_ConfigDataPtr->ComCtrlPhysPortDynOfPCConfig
#define EthTSyn_GetComCtrlPhysPortOfPCConfig()                                                      EthTSyn_ConfigDataPtr->ComCtrlPhysPortOfPCConfig
#define EthTSyn_GetComCtrlPortIndOfPCConfig()                                                       EthTSyn_ConfigDataPtr->ComCtrlPortIndOfPCConfig
#define EthTSyn_GetComCtrlPortOfPCConfig()                                                          EthTSyn_ConfigDataPtr->ComCtrlPortOfPCConfig
#define EthTSyn_GetComCtrlTimeDomainOfPCConfig()                                                    EthTSyn_ConfigDataPtr->ComCtrlTimeDomainOfPCConfig
#define EthTSyn_GetCrcHndlOfPCConfig()                                                              EthTSyn_ConfigDataPtr->CrcHndlOfPCConfig
#define EthTSyn_GetDestinationMacIndOfPCConfig()                                                    EthTSyn_ConfigDataPtr->DestinationMacIndOfPCConfig
#define EthTSyn_GetDestinationMacOfPCConfig()                                                       EthTSyn_ConfigDataPtr->DestinationMacOfPCConfig
#define EthTSyn_GetFupDataIdListOfPCConfig()                                                        EthTSyn_ConfigDataPtr->FupDataIdListOfPCConfig
#define EthTSyn_GetFupRxHandlerOfPCConfig()                                                         EthTSyn_ConfigDataPtr->FupRxHandlerOfPCConfig
#define EthTSyn_GetMsgSentCbkBufOfPCConfig()                                                        EthTSyn_ConfigDataPtr->MsgSentCbkBufOfPCConfig
#define EthTSyn_GetOffsetTimeDomainOfPCConfig()                                                     EthTSyn_ConfigDataPtr->OffsetTimeDomainOfPCConfig
#define EthTSyn_GetPdReqSmDynOfPCConfig()                                                           EthTSyn_ConfigDataPtr->PdReqSmDynOfPCConfig
#define EthTSyn_GetPdReqSmOfPCConfig()                                                              EthTSyn_ConfigDataPtr->PdReqSmOfPCConfig
#define EthTSyn_GetPdReqTrcvDynOfPCConfig()                                                         EthTSyn_ConfigDataPtr->PdReqTrcvDynOfPCConfig
#define EthTSyn_GetPdRespSmDynOfPCConfig()                                                          EthTSyn_ConfigDataPtr->PdRespSmDynOfPCConfig
#define EthTSyn_GetPdRespSmOfPCConfig()                                                             EthTSyn_ConfigDataPtr->PdRespSmOfPCConfig
#define EthTSyn_GetPortParamStatsDynOfPCConfig()                                                    EthTSyn_ConfigDataPtr->PortParamStatsDynOfPCConfig
#define EthTSyn_GetPortSyncSendSmDynOfPCConfig()                                                    EthTSyn_ConfigDataPtr->PortSyncSendSmDynOfPCConfig
#define EthTSyn_GetPortSyncSendSmOfPCConfig()                                                       EthTSyn_ConfigDataPtr->PortSyncSendSmOfPCConfig
#define EthTSyn_GetRateMeasBufOfPCConfig()                                                          EthTSyn_ConfigDataPtr->RateMeasBufOfPCConfig
#define EthTSyn_GetRateMeasDynOfPCConfig()                                                          EthTSyn_ConfigDataPtr->RateMeasDynOfPCConfig
#define EthTSyn_GetRateMeasOfPCConfig()                                                             EthTSyn_ConfigDataPtr->RateMeasOfPCConfig
#define EthTSyn_GetSiteSyncSyncTxDynOfPCConfig()                                                    EthTSyn_ConfigDataPtr->SiteSyncSyncTxDynOfPCConfig
#define EthTSyn_GetSiteSyncSyncTxOfPCConfig()                                                       EthTSyn_ConfigDataPtr->SiteSyncSyncTxOfPCConfig
#define EthTSyn_GetSizeOfAnnounceRcvSmOfPCConfig()                                                  EthTSyn_ConfigDataPtr->SizeOfAnnounceRcvSmOfPCConfig
#define EthTSyn_GetSizeOfAnnounceSendSmOfPCConfig()                                                 EthTSyn_ConfigDataPtr->SizeOfAnnounceSendSmOfPCConfig
#define EthTSyn_GetSizeOfBridgeTxMasterPortOfPCConfig()                                             EthTSyn_ConfigDataPtr->SizeOfBridgeTxMasterPortOfPCConfig
#define EthTSyn_GetSizeOfComCtrlEthIfCtrlOfPCConfig()                                               EthTSyn_ConfigDataPtr->SizeOfComCtrlEthIfCtrlOfPCConfig
#define EthTSyn_GetSizeOfComCtrlPhysPortOfPCConfig()                                                EthTSyn_ConfigDataPtr->SizeOfComCtrlPhysPortOfPCConfig
#define EthTSyn_GetSizeOfComCtrlPortIndOfPCConfig()                                                 EthTSyn_ConfigDataPtr->SizeOfComCtrlPortIndOfPCConfig
#define EthTSyn_GetSizeOfComCtrlPortOfPCConfig()                                                    EthTSyn_ConfigDataPtr->SizeOfComCtrlPortOfPCConfig
#define EthTSyn_GetSizeOfComCtrlTimeDomainOfPCConfig()                                              EthTSyn_ConfigDataPtr->SizeOfComCtrlTimeDomainOfPCConfig
#define EthTSyn_GetSizeOfCrcHndlOfPCConfig()                                                        EthTSyn_ConfigDataPtr->SizeOfCrcHndlOfPCConfig
#define EthTSyn_GetSizeOfDestinationMacIndOfPCConfig()                                              EthTSyn_ConfigDataPtr->SizeOfDestinationMacIndOfPCConfig
#define EthTSyn_GetSizeOfDestinationMacOfPCConfig()                                                 EthTSyn_ConfigDataPtr->SizeOfDestinationMacOfPCConfig
#define EthTSyn_GetSizeOfFupDataIdListOfPCConfig()                                                  EthTSyn_ConfigDataPtr->SizeOfFupDataIdListOfPCConfig
#define EthTSyn_GetSizeOfFupRxHandlerOfPCConfig()                                                   EthTSyn_ConfigDataPtr->SizeOfFupRxHandlerOfPCConfig
#define EthTSyn_GetSizeOfMsgSentCbkBufOfPCConfig()                                                  EthTSyn_ConfigDataPtr->SizeOfMsgSentCbkBufOfPCConfig
#define EthTSyn_GetSizeOfOffsetTimeDomainOfPCConfig()                                               EthTSyn_ConfigDataPtr->SizeOfOffsetTimeDomainOfPCConfig
#define EthTSyn_GetSizeOfPdReqSmOfPCConfig()                                                        EthTSyn_ConfigDataPtr->SizeOfPdReqSmOfPCConfig
#define EthTSyn_GetSizeOfPdRespSmOfPCConfig()                                                       EthTSyn_ConfigDataPtr->SizeOfPdRespSmOfPCConfig
#define EthTSyn_GetSizeOfPortParamStatsDynOfPCConfig()                                              EthTSyn_ConfigDataPtr->SizeOfPortParamStatsDynOfPCConfig
#define EthTSyn_GetSizeOfPortSyncSendSmOfPCConfig()                                                 EthTSyn_ConfigDataPtr->SizeOfPortSyncSendSmOfPCConfig
#define EthTSyn_GetSizeOfRateMeasBufOfPCConfig()                                                    EthTSyn_ConfigDataPtr->SizeOfRateMeasBufOfPCConfig
#define EthTSyn_GetSizeOfRateMeasOfPCConfig()                                                       EthTSyn_ConfigDataPtr->SizeOfRateMeasOfPCConfig
#define EthTSyn_GetSizeOfSiteSyncSyncTxOfPCConfig()                                                 EthTSyn_ConfigDataPtr->SizeOfSiteSyncSyncTxOfPCConfig
#define EthTSyn_GetSizeOfSlaveRxDataHandlerOfPCConfig()                                             EthTSyn_ConfigDataPtr->SizeOfSlaveRxDataHandlerOfPCConfig
#define EthTSyn_GetSizeOfSlaveRxDataOfPCConfig()                                                    EthTSyn_ConfigDataPtr->SizeOfSlaveRxDataOfPCConfig
#define EthTSyn_GetSizeOfSlaveRxMasterClockIdDynOfPCConfig()                                        EthTSyn_ConfigDataPtr->SizeOfSlaveRxMasterClockIdDynOfPCConfig
#define EthTSyn_GetSizeOfSlaveRxSrcPortIdCheckClockIdOfPCConfig()                                   EthTSyn_ConfigDataPtr->SizeOfSlaveRxSrcPortIdCheckClockIdOfPCConfig
#define EthTSyn_GetSizeOfSlaveSwitchIdxListOfPCConfig()                                             EthTSyn_ConfigDataPtr->SizeOfSlaveSwitchIdxListOfPCConfig
#define EthTSyn_GetSizeOfSwtTimeSyncSmOfPCConfig()                                                  EthTSyn_ConfigDataPtr->SizeOfSwtTimeSyncSmOfPCConfig
#define EthTSyn_GetSizeOfSyncRcvSmOfPCConfig()                                                      EthTSyn_ConfigDataPtr->SizeOfSyncRcvSmOfPCConfig
#define EthTSyn_GetSizeOfSyncSendSmOfPCConfig()                                                     EthTSyn_ConfigDataPtr->SizeOfSyncSendSmOfPCConfig
#define EthTSyn_GetSizeOfTimeBaseUpdateCounterOfPCConfig()                                          EthTSyn_ConfigDataPtr->SizeOfTimeBaseUpdateCounterOfPCConfig
#define EthTSyn_GetSizeOfTxConfContextOfPCConfig()                                                  EthTSyn_ConfigDataPtr->SizeOfTxConfContextOfPCConfig
#define EthTSyn_GetSlaveRxDataHandlerOfPCConfig()                                                   EthTSyn_ConfigDataPtr->SlaveRxDataHandlerOfPCConfig
#define EthTSyn_GetSlaveRxDataOfPCConfig()                                                          EthTSyn_ConfigDataPtr->SlaveRxDataOfPCConfig
#define EthTSyn_GetSlaveRxMasterClockIdDynOfPCConfig()                                              EthTSyn_ConfigDataPtr->SlaveRxMasterClockIdDynOfPCConfig
#define EthTSyn_GetSlaveRxSrcPortIdCheckClockIdOfPCConfig()                                         EthTSyn_ConfigDataPtr->SlaveRxSrcPortIdCheckClockIdOfPCConfig
#define EthTSyn_GetSlaveSwitchIdxListOfPCConfig()                                                   EthTSyn_ConfigDataPtr->SlaveSwitchIdxListOfPCConfig
#define EthTSyn_GetSwtTimeSyncSmDynOfPCConfig()                                                     EthTSyn_ConfigDataPtr->SwtTimeSyncSmDynOfPCConfig
#define EthTSyn_GetSwtTimeSyncSmOfPCConfig()                                                        EthTSyn_ConfigDataPtr->SwtTimeSyncSmOfPCConfig
#define EthTSyn_GetSyncRcvSmDynOfPCConfig()                                                         EthTSyn_ConfigDataPtr->SyncRcvSmDynOfPCConfig
#define EthTSyn_GetSyncRcvSmOfPCConfig()                                                            EthTSyn_ConfigDataPtr->SyncRcvSmOfPCConfig
#define EthTSyn_GetSyncSendSmDynOfPCConfig()                                                        EthTSyn_ConfigDataPtr->SyncSendSmDynOfPCConfig
#define EthTSyn_GetSyncSendSmOfPCConfig()                                                           EthTSyn_ConfigDataPtr->SyncSendSmOfPCConfig
#define EthTSyn_GetTimeBaseUpdateCounterDynOfPCConfig()                                             EthTSyn_ConfigDataPtr->TimeBaseUpdateCounterDynOfPCConfig
#define EthTSyn_GetTimeBaseUpdateCounterOfPCConfig()                                                EthTSyn_ConfigDataPtr->TimeBaseUpdateCounterOfPCConfig
#define EthTSyn_GetTxConfContextDynActiveFirstIdxOfPCConfig()                                       EthTSyn_ConfigDataPtr->TxConfContextDynActiveFirstIdxOfPCConfig
#define EthTSyn_GetTxConfContextDynActiveLastIdxOfPCConfig()                                        EthTSyn_ConfigDataPtr->TxConfContextDynActiveLastIdxOfPCConfig
#define EthTSyn_GetTxConfContextDynOfPCConfig()                                                     EthTSyn_ConfigDataPtr->TxConfContextDynOfPCConfig
#define EthTSyn_GetTxConfContextOfPCConfig()                                                        EthTSyn_ConfigDataPtr->TxConfContextOfPCConfig
/** 
  \}
*/ 

/** 
  \defgroup  EthTSynPCGetDuplicatedRootDataMacros  EthTSyn Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define EthTSyn_GetSizeOfAnnounceRcvSmDynOfPCConfig()                                               EthTSyn_GetSizeOfAnnounceRcvSmOfPCConfig()  /**< the number of accomplishable value elements in EthTSyn_AnnounceRcvSmDyn */
#define EthTSyn_GetSizeOfAnnounceSendSmDynOfPCConfig()                                              EthTSyn_GetSizeOfAnnounceSendSmOfPCConfig()  /**< the number of accomplishable value elements in EthTSyn_AnnounceSendSmDyn */
#define EthTSyn_GetSizeOfBridgeTxMasterPortDynOfPCConfig()                                          EthTSyn_GetSizeOfBridgeTxMasterPortOfPCConfig()  /**< the number of accomplishable value elements in EthTSyn_BridgeTxMasterPortDyn */
#define EthTSyn_GetSizeOfComCtrlEthIfCtrlDynOfPCConfig()                                            EthTSyn_GetSizeOfComCtrlEthIfCtrlOfPCConfig()  /**< the number of accomplishable value elements in EthTSyn_ComCtrlEthIfCtrlDyn */
#define EthTSyn_GetSizeOfComCtrlPhysPortDynOfPCConfig()                                             EthTSyn_GetSizeOfComCtrlPhysPortOfPCConfig()  /**< the number of accomplishable value elements in EthTSyn_ComCtrlPhysPortDyn */
#define EthTSyn_GetSizeOfPdReqSmDynOfPCConfig()                                                     EthTSyn_GetSizeOfPdReqSmOfPCConfig()  /**< the number of accomplishable value elements in EthTSyn_PdReqSmDyn */
#define EthTSyn_GetSizeOfPdReqTrcvDynOfPCConfig()                                                   EthTSyn_GetSizeOfPdReqSmOfPCConfig()  /**< the number of accomplishable value elements in EthTSyn_PdReqTrcvDyn */
#define EthTSyn_GetSizeOfPdRespSmDynOfPCConfig()                                                    EthTSyn_GetSizeOfPdRespSmOfPCConfig()  /**< the number of accomplishable value elements in EthTSyn_PdRespSmDyn */
#define EthTSyn_GetSizeOfPortSyncSendSmDynOfPCConfig()                                              EthTSyn_GetSizeOfPortSyncSendSmOfPCConfig()  /**< the number of accomplishable value elements in EthTSyn_PortSyncSendSmDyn */
#define EthTSyn_GetSizeOfRateMeasDynOfPCConfig()                                                    EthTSyn_GetSizeOfRateMeasOfPCConfig()  /**< the number of accomplishable value elements in EthTSyn_RateMeasDyn */
#define EthTSyn_GetSizeOfSiteSyncSyncTxDynOfPCConfig()                                              EthTSyn_GetSizeOfSiteSyncSyncTxOfPCConfig()  /**< the number of accomplishable value elements in EthTSyn_SiteSyncSyncTxDyn */
#define EthTSyn_GetSizeOfSwtTimeSyncSmDynOfPCConfig()                                               EthTSyn_GetSizeOfSwtTimeSyncSmOfPCConfig()  /**< the number of accomplishable value elements in EthTSyn_SwtTimeSyncSmDyn */
#define EthTSyn_GetSizeOfSyncRcvSmDynOfPCConfig()                                                   EthTSyn_GetSizeOfSyncRcvSmOfPCConfig()  /**< the number of accomplishable value elements in EthTSyn_SyncRcvSmDyn */
#define EthTSyn_GetSizeOfSyncSendSmDynOfPCConfig()                                                  EthTSyn_GetSizeOfSyncSendSmOfPCConfig()  /**< the number of accomplishable value elements in EthTSyn_SyncSendSmDyn */
#define EthTSyn_GetSizeOfTimeBaseUpdateCounterDynOfPCConfig()                                       EthTSyn_GetSizeOfTimeBaseUpdateCounterOfPCConfig()  /**< the number of accomplishable value elements in EthTSyn_TimeBaseUpdateCounterDyn */
#define EthTSyn_GetSizeOfTxConfContextDynOfPCConfig()                                               EthTSyn_GetSizeOfTxConfContextOfPCConfig()  /**< the number of accomplishable value elements in EthTSyn_TxConfContextDyn */
/** 
  \}
*/ 

/** 
  \defgroup  EthTSynPCGetDataMacros  EthTSyn Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define EthTSyn_GetComCtrlPortIdxOfAnnounceRcvSm(Index)                                             (EthTSyn_GetAnnounceRcvSmOfPCConfig()[(Index)].ComCtrlPortIdxOfAnnounceRcvSm)
#define EthTSyn_GetMaxStepsRemovedOfAnnounceRcvSm(Index)                                            (EthTSyn_GetAnnounceRcvSmOfPCConfig()[(Index)].MaxStepsRemovedOfAnnounceRcvSm)
#define EthTSyn_GetRxTimeoutOfAnnounceRcvSm(Index)                                                  (EthTSyn_GetAnnounceRcvSmOfPCConfig()[(Index)].RxTimeoutOfAnnounceRcvSm)
#define EthTSyn_GetSlaveRxDataIdxOfAnnounceRcvSm(Index)                                             (EthTSyn_GetAnnounceRcvSmOfPCConfig()[(Index)].SlaveRxDataIdxOfAnnounceRcvSm)
#define EthTSyn_GetRxTimeoutCounterOfAnnounceRcvSmDyn(Index)                                        (EthTSyn_GetAnnounceRcvSmDynOfPCConfig()[(Index)].RxTimeoutCounterOfAnnounceRcvSmDyn)
#define EthTSyn_IsSmResetRequestedOfAnnounceRcvSmDyn(Index)                                         ((EthTSyn_GetAnnounceRcvSmDynOfPCConfig()[(Index)].SmResetRequestedOfAnnounceRcvSmDyn) != FALSE)
#define EthTSyn_GetStateOfAnnounceRcvSmDyn(Index)                                                   (EthTSyn_GetAnnounceRcvSmDynOfPCConfig()[(Index)].StateOfAnnounceRcvSmDyn)
#define EthTSyn_GetAnnounceLogMsgIntervalOfAnnounceSendSm(Index)                                    (EthTSyn_GetAnnounceSendSmOfPCConfig()[(Index)].AnnounceLogMsgIntervalOfAnnounceSendSm)
#define EthTSyn_GetAnnounceTxCycleOfAnnounceSendSm(Index)                                           (EthTSyn_GetAnnounceSendSmOfPCConfig()[(Index)].AnnounceTxCycleOfAnnounceSendSm)
#define EthTSyn_GetComCtrlPortIdxOfAnnounceSendSm(Index)                                            (EthTSyn_GetAnnounceSendSmOfPCConfig()[(Index)].ComCtrlPortIdxOfAnnounceSendSm)
#define EthTSyn_GetAnnounceCycleTimerOfAnnounceSendSmDyn(Index)                                     (EthTSyn_GetAnnounceSendSmDynOfPCConfig()[(Index)].AnnounceCycleTimerOfAnnounceSendSmDyn)
#define EthTSyn_IsResetRequestedOfAnnounceSendSmDyn(Index)                                          ((EthTSyn_GetAnnounceSendSmDynOfPCConfig()[(Index)].ResetRequestedOfAnnounceSendSmDyn) != FALSE)
#define EthTSyn_GetSequenceIdOfAnnounceSendSmDyn(Index)                                             (EthTSyn_GetAnnounceSendSmDynOfPCConfig()[(Index)].SequenceIdOfAnnounceSendSmDyn)
#define EthTSyn_GetStateOfAnnounceSendSmDyn(Index)                                                  (EthTSyn_GetAnnounceSendSmDynOfPCConfig()[(Index)].StateOfAnnounceSendSmDyn)
#define EthTSyn_GetComCtrlPortIdxOfBridgeTxMasterPort(Index)                                        (EthTSyn_GetBridgeTxMasterPortOfPCConfig()[(Index)].ComCtrlPortIdxOfBridgeTxMasterPort)
#define EthTSyn_GetFupFwdStateOfBridgeTxMasterPortDyn(Index)                                        (EthTSyn_GetBridgeTxMasterPortDynOfPCConfig()[(Index)].FupFwdStateOfBridgeTxMasterPortDyn)
#define EthTSyn_GetSyncFwdDelayNsOfBridgeTxMasterPortDyn(Index)                                     (EthTSyn_GetBridgeTxMasterPortDynOfPCConfig()[(Index)].SyncFwdDelayNsOfBridgeTxMasterPortDyn)
#define EthTSyn_GetComCtrlPortIndEndIdxOfComCtrlEthIfCtrl(Index)                                    (EthTSyn_GetComCtrlEthIfCtrlOfPCConfig()[(Index)].ComCtrlPortIndEndIdxOfComCtrlEthIfCtrl)
#define EthTSyn_GetComCtrlPortIndStartIdxOfComCtrlEthIfCtrl(Index)                                  (EthTSyn_GetComCtrlEthIfCtrlOfPCConfig()[(Index)].ComCtrlPortIndStartIdxOfComCtrlEthIfCtrl)
#define EthTSyn_GetDestinationMacIndEndIdxOfComCtrlEthIfCtrl(Index)                                 (EthTSyn_GetComCtrlEthIfCtrlOfPCConfig()[(Index)].DestinationMacIndEndIdxOfComCtrlEthIfCtrl)
#define EthTSyn_GetDestinationMacIndStartIdxOfComCtrlEthIfCtrl(Index)                               (EthTSyn_GetComCtrlEthIfCtrlOfPCConfig()[(Index)].DestinationMacIndStartIdxOfComCtrlEthIfCtrl)
#define EthTSyn_GetEthIfCtrlIdxOfComCtrlEthIfCtrl(Index)                                            (EthTSyn_GetComCtrlEthIfCtrlOfPCConfig()[(Index)].EthIfCtrlIdxOfComCtrlEthIfCtrl)
#define EthTSyn_GetClockIdOfComCtrlEthIfCtrlDyn(Index)                                              (EthTSyn_GetComCtrlEthIfCtrlDynOfPCConfig()[(Index)].ClockIdOfComCtrlEthIfCtrlDyn)
#define EthTSyn_IsLinkStateActiveOfComCtrlEthIfCtrlDyn(Index)                                       ((EthTSyn_GetComCtrlEthIfCtrlDynOfPCConfig()[(Index)].LinkStateActiveOfComCtrlEthIfCtrlDyn) != FALSE)
#define EthTSyn_IsTxActiveOfComCtrlEthIfCtrlDyn(Index)                                              ((EthTSyn_GetComCtrlEthIfCtrlDynOfPCConfig()[(Index)].TxActiveOfComCtrlEthIfCtrlDyn) != FALSE)
#define EthTSyn_IsAlwaysAsCapableOfComCtrlPhysPort(Index)                                           ((EthTSyn_GetComCtrlPhysPortOfPCConfig()[(Index)].AlwaysAsCapableOfComCtrlPhysPort) != FALSE)
#define EthTSyn_GetDebounceTimerInitOfComCtrlPhysPort(Index)                                        (EthTSyn_GetComCtrlPhysPortOfPCConfig()[(Index)].DebounceTimerInitOfComCtrlPhysPort)
#define EthTSyn_GetInitialPdelayNsOfComCtrlPhysPort(Index)                                          (EthTSyn_GetComCtrlPhysPortOfPCConfig()[(Index)].InitialPdelayNsOfComCtrlPhysPort)
#define EthTSyn_IsUseStaticPdelayOfComCtrlPhysPort(Index)                                           ((EthTSyn_GetComCtrlPhysPortOfPCConfig()[(Index)].UseStaticPdelayOfComCtrlPhysPort) != FALSE)
#define EthTSyn_IsAsCapableOfComCtrlPhysPortDyn(Index)                                              ((EthTSyn_GetComCtrlPhysPortDynOfPCConfig()[(Index)].AsCapableOfComCtrlPhysPortDyn) != FALSE)
#define EthTSyn_GetDebounceTimerOfComCtrlPhysPortDyn(Index)                                         (EthTSyn_GetComCtrlPhysPortDynOfPCConfig()[(Index)].DebounceTimerOfComCtrlPhysPortDyn)
#define EthTSyn_GetPdelayValueNsOfComCtrlPhysPortDyn(Index)                                         (EthTSyn_GetComCtrlPhysPortDynOfPCConfig()[(Index)].PdelayValueNsOfComCtrlPhysPortDyn)
#define EthTSyn_GetAnnounceSendSmIdxOfComCtrlPort(Index)                                            (EthTSyn_GetComCtrlPortOfPCConfig()[(Index)].AnnounceSendSmIdxOfComCtrlPort)
#define EthTSyn_GetComCtrlEthIfCtrlIdxOfComCtrlPort(Index)                                          (EthTSyn_GetComCtrlPortOfPCConfig()[(Index)].ComCtrlEthIfCtrlIdxOfComCtrlPort)
#define EthTSyn_GetComCtrlPhysPortIdxOfComCtrlPort(Index)                                           (EthTSyn_GetComCtrlPortOfPCConfig()[(Index)].ComCtrlPhysPortIdxOfComCtrlPort)
#define EthTSyn_GetComCtrlTimeDomainIdxOfComCtrlPort(Index)                                         (EthTSyn_GetComCtrlPortOfPCConfig()[(Index)].ComCtrlTimeDomainIdxOfComCtrlPort)
#define EthTSyn_GetFramePrioOfComCtrlPort(Index)                                                    (EthTSyn_GetComCtrlPortOfPCConfig()[(Index)].FramePrioOfComCtrlPort)
#define EthTSyn_GetNumberOfComCtrlPort(Index)                                                       (EthTSyn_GetComCtrlPortOfPCConfig()[(Index)].NumberOfComCtrlPort)
#define EthTSyn_GetPdReqSmIdxOfComCtrlPort(Index)                                                   (EthTSyn_GetComCtrlPortOfPCConfig()[(Index)].PdReqSmIdxOfComCtrlPort)
#define EthTSyn_GetPdRespSmIdxOfComCtrlPort(Index)                                                  (EthTSyn_GetComCtrlPortOfPCConfig()[(Index)].PdRespSmIdxOfComCtrlPort)
#define EthTSyn_GetPortParamStatsDynIdxOfComCtrlPort(Index)                                         (EthTSyn_GetComCtrlPortOfPCConfig()[(Index)].PortParamStatsDynIdxOfComCtrlPort)
#define EthTSyn_GetPortSyncSendSmIdxOfComCtrlPort(Index)                                            (EthTSyn_GetComCtrlPortOfPCConfig()[(Index)].PortSyncSendSmIdxOfComCtrlPort)
#define EthTSyn_GetSlaveRxDataHandlerIdxOfComCtrlPort(Index)                                        (EthTSyn_GetComCtrlPortOfPCConfig()[(Index)].SlaveRxDataHandlerIdxOfComCtrlPort)
#define EthTSyn_GetSyncSendSmIdxOfComCtrlPort(Index)                                                (EthTSyn_GetComCtrlPortOfPCConfig()[(Index)].SyncSendSmIdxOfComCtrlPort)
#define EthTSyn_GetComCtrlPortInd(Index)                                                            (EthTSyn_GetComCtrlPortIndOfPCConfig()[(Index)])
#define EthTSyn_GetComCtrlPortEndIdxOfComCtrlTimeDomain(Index)                                      (EthTSyn_GetComCtrlTimeDomainOfPCConfig()[(Index)].ComCtrlPortEndIdxOfComCtrlTimeDomain)
#define EthTSyn_GetComCtrlPortStartIdxOfComCtrlTimeDomain(Index)                                    (EthTSyn_GetComCtrlTimeDomainOfPCConfig()[(Index)].ComCtrlPortStartIdxOfComCtrlTimeDomain)
#define EthTSyn_GetDestinationMacIdxOfComCtrlTimeDomain(Index)                                      (EthTSyn_GetComCtrlTimeDomainOfPCConfig()[(Index)].DestinationMacIdxOfComCtrlTimeDomain)
#define EthTSyn_GetIdOfComCtrlTimeDomain(Index)                                                     (EthTSyn_GetComCtrlTimeDomainOfPCConfig()[(Index)].IdOfComCtrlTimeDomain)
#define EthTSyn_GetOffsetTimeDomainEndIdxOfComCtrlTimeDomain(Index)                                 (EthTSyn_GetComCtrlTimeDomainOfPCConfig()[(Index)].OffsetTimeDomainEndIdxOfComCtrlTimeDomain)
#define EthTSyn_GetOffsetTimeDomainStartIdxOfComCtrlTimeDomain(Index)                               (EthTSyn_GetComCtrlTimeDomainOfPCConfig()[(Index)].OffsetTimeDomainStartIdxOfComCtrlTimeDomain)
#define EthTSyn_GetSynchronizedTimeBaseIdOfComCtrlTimeDomain(Index)                                 (EthTSyn_GetComCtrlTimeDomainOfPCConfig()[(Index)].SynchronizedTimeBaseIdOfComCtrlTimeDomain)
#define EthTSyn_GetFupDataIdListEndIdxOfCrcHndl(Index)                                              (EthTSyn_GetCrcHndlOfPCConfig()[(Index)].FupDataIdListEndIdxOfCrcHndl)
#define EthTSyn_GetFupDataIdListStartIdxOfCrcHndl(Index)                                            (EthTSyn_GetCrcHndlOfPCConfig()[(Index)].FupDataIdListStartIdxOfCrcHndl)
#define EthTSyn_GetByte0OfDestinationMac(Index)                                                     (EthTSyn_GetDestinationMacOfPCConfig()[(Index)].Byte0OfDestinationMac)
#define EthTSyn_GetByte1OfDestinationMac(Index)                                                     (EthTSyn_GetDestinationMacOfPCConfig()[(Index)].Byte1OfDestinationMac)
#define EthTSyn_GetByte2OfDestinationMac(Index)                                                     (EthTSyn_GetDestinationMacOfPCConfig()[(Index)].Byte2OfDestinationMac)
#define EthTSyn_GetByte3OfDestinationMac(Index)                                                     (EthTSyn_GetDestinationMacOfPCConfig()[(Index)].Byte3OfDestinationMac)
#define EthTSyn_GetByte4OfDestinationMac(Index)                                                     (EthTSyn_GetDestinationMacOfPCConfig()[(Index)].Byte4OfDestinationMac)
#define EthTSyn_GetByte5OfDestinationMac(Index)                                                     (EthTSyn_GetDestinationMacOfPCConfig()[(Index)].Byte5OfDestinationMac)
#define EthTSyn_GetDestinationMacInd(Index)                                                         (EthTSyn_GetDestinationMacIndOfPCConfig()[(Index)])
#define EthTSyn_GetFupDataIdList(Index)                                                             (EthTSyn_GetFupDataIdListOfPCConfig()[(Index)])
#define EthTSyn_GetComCtrlPortExternalIdxOfFupRxHandler(Index)                                      (EthTSyn_GetFupRxHandlerOfPCConfig()[(Index)].ComCtrlPortExternalIdxOfFupRxHandler)
#define EthTSyn_GetCrcFlagsRxValidatedOfFupRxHandler(Index)                                         (EthTSyn_GetFupRxHandlerOfPCConfig()[(Index)].CrcFlagsRxValidatedOfFupRxHandler)
#define EthTSyn_GetCrcHndlIdxOfFupRxHandler(Index)                                                  (EthTSyn_GetFupRxHandlerOfPCConfig()[(Index)].CrcHndlIdxOfFupRxHandler)
#define EthTSyn_GetFupCorrFieldThresholdNsOfFupRxHandler(Index)                                     (EthTSyn_GetFupRxHandlerOfPCConfig()[(Index)].FupCorrFieldThresholdNsOfFupRxHandler)
#define EthTSyn_GetRxCrcValidatedOfFupRxHandler(Index)                                              (EthTSyn_GetFupRxHandlerOfPCConfig()[(Index)].RxCrcValidatedOfFupRxHandler)
#define EthTSyn_IsTimeValidationEnabledOfFupRxHandler(Index)                                        ((EthTSyn_GetFupRxHandlerOfPCConfig()[(Index)].TimeValidationEnabledOfFupRxHandler) != FALSE)
#define EthTSyn_GetMsgSentCbkBuf(Index)                                                             (EthTSyn_GetMsgSentCbkBufOfPCConfig()[(Index)])
#define EthTSyn_GetIdOfOffsetTimeDomain(Index)                                                      (EthTSyn_GetOffsetTimeDomainOfPCConfig()[(Index)].IdOfOffsetTimeDomain)
#define EthTSyn_GetSynchronizedTimeBaseIdOfOffsetTimeDomain(Index)                                  (EthTSyn_GetOffsetTimeDomainOfPCConfig()[(Index)].SynchronizedTimeBaseIdOfOffsetTimeDomain)
#define EthTSyn_GetAverageWeightOfPdReqSm(Index)                                                    (EthTSyn_GetPdReqSmOfPCConfig()[(Index)].AverageWeightOfPdReqSm)
#define EthTSyn_GetComCtrlPortIdxOfPdReqSm(Index)                                                   (EthTSyn_GetPdReqSmOfPCConfig()[(Index)].ComCtrlPortIdxOfPdReqSm)
#define EthTSyn_GetLogMsgIntervalOfPdReqSm(Index)                                                   (EthTSyn_GetPdReqSmOfPCConfig()[(Index)].LogMsgIntervalOfPdReqSm)
#define EthTSyn_GetMaxLostResponsesOfPdReqSm(Index)                                                 (EthTSyn_GetPdReqSmOfPCConfig()[(Index)].MaxLostResponsesOfPdReqSm)
#define EthTSyn_GetPdReqPeriodOfPdReqSm(Index)                                                      (EthTSyn_GetPdReqSmOfPCConfig()[(Index)].PdReqPeriodOfPdReqSm)
#define EthTSyn_GetPdRespTimeoutOfPdReqSm(Index)                                                    (EthTSyn_GetPdReqSmOfPCConfig()[(Index)].PdRespTimeoutOfPdReqSm)
#define EthTSyn_GetPdThresholdOfPdReqSm(Index)                                                      (EthTSyn_GetPdReqSmOfPCConfig()[(Index)].PdThresholdOfPdReqSm)
#define EthTSyn_IsTimeValidationEnabledOfPdReqSm(Index)                                             ((EthTSyn_GetPdReqSmOfPCConfig()[(Index)].TimeValidationEnabledOfPdReqSm) != FALSE)
#define EthTSyn_GetTxConfContextIdxOfPdReqSm(Index)                                                 (EthTSyn_GetPdReqSmOfPCConfig()[(Index)].TxConfContextIdxOfPdReqSm)
#define EthTSyn_IsFirstPdelayOfPdReqSmDyn(Index)                                                    ((EthTSyn_GetPdReqSmDynOfPCConfig()[(Index)].FirstPdelayOfPdReqSmDyn) != FALSE)
#define EthTSyn_GetLostResponseCntOfPdReqSmDyn(Index)                                               (EthTSyn_GetPdReqSmDynOfPCConfig()[(Index)].LostResponseCntOfPdReqSmDyn)
#define EthTSyn_GetRefGlobalTimeOfPdReqSmDyn(Index)                                                 (EthTSyn_GetPdReqSmDynOfPCConfig()[(Index)].RefGlobalTimeOfPdReqSmDyn)
#define EthTSyn_GetRefLocalTimeOfPdReqSmDyn(Index)                                                  (EthTSyn_GetPdReqSmDynOfPCConfig()[(Index)].RefLocalTimeOfPdReqSmDyn)
#define EthTSyn_GetRespTimeoutCntOfPdReqSmDyn(Index)                                                (EthTSyn_GetPdReqSmDynOfPCConfig()[(Index)].RespTimeoutCntOfPdReqSmDyn)
#define EthTSyn_GetSequenceIdOfPdReqSmDyn(Index)                                                    (EthTSyn_GetPdReqSmDynOfPCConfig()[(Index)].SequenceIdOfPdReqSmDyn)
#define EthTSyn_IsSmResetRequestedOfPdReqSmDyn(Index)                                               ((EthTSyn_GetPdReqSmDynOfPCConfig()[(Index)].SmResetRequestedOfPdReqSmDyn) != FALSE)
#define EthTSyn_GetStateOfPdReqSmDyn(Index)                                                         (EthTSyn_GetPdReqSmDynOfPCConfig()[(Index)].StateOfPdReqSmDyn)
#define EthTSyn_GetTxIntervalCntOfPdReqSmDyn(Index)                                                 (EthTSyn_GetPdReqSmDynOfPCConfig()[(Index)].TxIntervalCntOfPdReqSmDyn)
#define EthTSyn_GetPdReqEgrTsMgmtOfPdReqTrcvDyn(Index)                                              (EthTSyn_GetPdReqTrcvDynOfPCConfig()[(Index)].PdReqEgrTsMgmtOfPdReqTrcvDyn)
#define EthTSyn_IsPdReqEgrTsProvidedOfPdReqTrcvDyn(Index)                                           ((EthTSyn_GetPdReqTrcvDynOfPCConfig()[(Index)].PdReqEgrTsProvidedOfPdReqTrcvDyn) != FALSE)
#define EthTSyn_GetPdRespIngrTsMgmtOfPdReqTrcvDyn(Index)                                            (EthTSyn_GetPdReqTrcvDynOfPCConfig()[(Index)].PdRespIngrTsMgmtOfPdReqTrcvDyn)
#define EthTSyn_GetReqReceivedTsOfPdReqTrcvDyn(Index)                                               (EthTSyn_GetPdReqTrcvDynOfPCConfig()[(Index)].ReqReceivedTsOfPdReqTrcvDyn)
#define EthTSyn_GetRespClockIdOfPdReqTrcvDyn(Index)                                                 (EthTSyn_GetPdReqTrcvDynOfPCConfig()[(Index)].RespClockIdOfPdReqTrcvDyn)
#define EthTSyn_GetRespOriginTsOfPdReqTrcvDyn(Index)                                                (EthTSyn_GetPdReqTrcvDynOfPCConfig()[(Index)].RespOriginTsOfPdReqTrcvDyn)
#define EthTSyn_GetRespPortNumOfPdReqTrcvDyn(Index)                                                 (EthTSyn_GetPdReqTrcvDynOfPCConfig()[(Index)].RespPortNumOfPdReqTrcvDyn)
#define EthTSyn_GetStateOfPdReqTrcvDyn(Index)                                                       (EthTSyn_GetPdReqTrcvDynOfPCConfig()[(Index)].StateOfPdReqTrcvDyn)
#define EthTSyn_GetComCtrlPortIdxOfPdRespSm(Index)                                                  (EthTSyn_GetPdRespSmOfPCConfig()[(Index)].ComCtrlPortIdxOfPdRespSm)
#define EthTSyn_IsTimeValidationEnabledOfPdRespSm(Index)                                            ((EthTSyn_GetPdRespSmOfPCConfig()[(Index)].TimeValidationEnabledOfPdRespSm) != FALSE)
#define EthTSyn_GetTxConfContextIdxOfPdRespSm(Index)                                                (EthTSyn_GetPdRespSmOfPCConfig()[(Index)].TxConfContextIdxOfPdRespSm)
#define EthTSyn_GetPdReqRcvdTsOfPdRespSmDyn(Index)                                                  (EthTSyn_GetPdRespSmDynOfPCConfig()[(Index)].PdReqRcvdTsOfPdRespSmDyn)
#define EthTSyn_GetPdRespOrgTsOfPdRespSmDyn(Index)                                                  (EthTSyn_GetPdRespSmDynOfPCConfig()[(Index)].PdRespOrgTsOfPdRespSmDyn)
#define EthTSyn_GetRequestorClockIdOfPdRespSmDyn(Index)                                             (EthTSyn_GetPdRespSmDynOfPCConfig()[(Index)].RequestorClockIdOfPdRespSmDyn)
#define EthTSyn_GetRequestorPortNumOfPdRespSmDyn(Index)                                             (EthTSyn_GetPdRespSmDynOfPCConfig()[(Index)].RequestorPortNumOfPdRespSmDyn)
#define EthTSyn_GetSequenceIdOfPdRespSmDyn(Index)                                                   (EthTSyn_GetPdRespSmDynOfPCConfig()[(Index)].SequenceIdOfPdRespSmDyn)
#define EthTSyn_IsSmResetRequestedOfPdRespSmDyn(Index)                                              ((EthTSyn_GetPdRespSmDynOfPCConfig()[(Index)].SmResetRequestedOfPdRespSmDyn) != FALSE)
#define EthTSyn_GetStateOfPdRespSmDyn(Index)                                                        (EthTSyn_GetPdRespSmDynOfPCConfig()[(Index)].StateOfPdRespSmDyn)
#define EthTSyn_GetPdLostRespExceededCountOfPortParamStatsDyn(Index)                                (EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].PdLostRespExceededCountOfPortParamStatsDyn)
#define EthTSyn_GetRxAnnounceCountOfPortParamStatsDyn(Index)                                        (EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].RxAnnounceCountOfPortParamStatsDyn)
#define EthTSyn_GetRxDiscardCountOfPortParamStatsDyn(Index)                                         (EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].RxDiscardCountOfPortParamStatsDyn)
#define EthTSyn_GetRxFupCountOfPortParamStatsDyn(Index)                                             (EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].RxFupCountOfPortParamStatsDyn)
#define EthTSyn_GetRxPdReqCountOfPortParamStatsDyn(Index)                                           (EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].RxPdReqCountOfPortParamStatsDyn)
#define EthTSyn_GetRxPdRespCountOfPortParamStatsDyn(Index)                                          (EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].RxPdRespCountOfPortParamStatsDyn)
#define EthTSyn_GetRxPdRespFupCountOfPortParamStatsDyn(Index)                                       (EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].RxPdRespFupCountOfPortParamStatsDyn)
#define EthTSyn_GetRxSyncCountOfPortParamStatsDyn(Index)                                            (EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].RxSyncCountOfPortParamStatsDyn)
#define EthTSyn_GetTxAnnounceCountOfPortParamStatsDyn(Index)                                        (EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].TxAnnounceCountOfPortParamStatsDyn)
#define EthTSyn_GetTxFupCountOfPortParamStatsDyn(Index)                                             (EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].TxFupCountOfPortParamStatsDyn)
#define EthTSyn_GetTxPdReqCountOfPortParamStatsDyn(Index)                                           (EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].TxPdReqCountOfPortParamStatsDyn)
#define EthTSyn_GetTxPdRespCountOfPortParamStatsDyn(Index)                                          (EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].TxPdRespCountOfPortParamStatsDyn)
#define EthTSyn_GetTxPdRespFupCountOfPortParamStatsDyn(Index)                                       (EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].TxPdRespFupCountOfPortParamStatsDyn)
#define EthTSyn_GetTxSyncCountOfPortParamStatsDyn(Index)                                            (EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].TxSyncCountOfPortParamStatsDyn)
#define EthTSyn_GetComCtrlPortIdxOfPortSyncSendSm(Index)                                            (EthTSyn_GetPortSyncSendSmOfPCConfig()[(Index)].ComCtrlPortIdxOfPortSyncSendSm)
#define EthTSyn_GetFollowUpSentCbkPtrOfPortSyncSendSm(Index)                                        (EthTSyn_GetPortSyncSendSmOfPCConfig()[(Index)].FollowUpSentCbkPtrOfPortSyncSendSm)
#define EthTSyn_GetMsgSentCbkBufEndIdxOfPortSyncSendSm(Index)                                       (EthTSyn_GetPortSyncSendSmOfPCConfig()[(Index)].MsgSentCbkBufEndIdxOfPortSyncSendSm)
#define EthTSyn_GetMsgSentCbkBufLengthOfPortSyncSendSm(Index)                                       (EthTSyn_GetPortSyncSendSmOfPCConfig()[(Index)].MsgSentCbkBufLengthOfPortSyncSendSm)
#define EthTSyn_GetMsgSentCbkBufStartIdxOfPortSyncSendSm(Index)                                     (EthTSyn_GetPortSyncSendSmOfPCConfig()[(Index)].MsgSentCbkBufStartIdxOfPortSyncSendSm)
#define EthTSyn_GetSyncSentCbkPtrOfPortSyncSendSm(Index)                                            (EthTSyn_GetPortSyncSendSmOfPCConfig()[(Index)].SyncSentCbkPtrOfPortSyncSendSm)
#define EthTSyn_IsTimeValidationEnabledOfPortSyncSendSm(Index)                                      ((EthTSyn_GetPortSyncSendSmOfPCConfig()[(Index)].TimeValidationEnabledOfPortSyncSendSm) != FALSE)
#define EthTSyn_GetTxConfContextIdxOfPortSyncSendSm(Index)                                          (EthTSyn_GetPortSyncSendSmOfPCConfig()[(Index)].TxConfContextIdxOfPortSyncSendSm)
#define EthTSyn_GetEgrTsInfoOfPortSyncSendSmDyn(Index)                                              (EthTSyn_GetPortSyncSendSmDynOfPCConfig()[(Index)].EgrTsInfoOfPortSyncSendSmDyn)
#define EthTSyn_GetStateOfPortSyncSendSmDyn(Index)                                                  (EthTSyn_GetPortSyncSendSmDynOfPCConfig()[(Index)].StateOfPortSyncSendSmDyn)
#define EthTSyn_GetMaxOutOfSyncCntOfRateMeas(Index)                                                 (EthTSyn_GetRateMeasOfPCConfig()[(Index)].MaxOutOfSyncCntOfRateMeas)
#define EthTSyn_GetNrSyncCyclesForOfsCorrOfRateMeas(Index)                                          (EthTSyn_GetRateMeasOfPCConfig()[(Index)].NrSyncCyclesForOfsCorrOfRateMeas)
#define EthTSyn_GetOfsJumpCorrThresholdNsOfRateMeas(Index)                                          (EthTSyn_GetRateMeasOfPCConfig()[(Index)].OfsJumpCorrThresholdNsOfRateMeas)
#define EthTSyn_GetRateMeasBufEndIdxOfRateMeas(Index)                                               (EthTSyn_GetRateMeasOfPCConfig()[(Index)].RateMeasBufEndIdxOfRateMeas)
#define EthTSyn_GetRateMeasBufLengthOfRateMeas(Index)                                               (EthTSyn_GetRateMeasOfPCConfig()[(Index)].RateMeasBufLengthOfRateMeas)
#define EthTSyn_GetRateMeasBufStartIdxOfRateMeas(Index)                                             (EthTSyn_GetRateMeasOfPCConfig()[(Index)].RateMeasBufStartIdxOfRateMeas)
#define EthTSyn_GetRateRatioMaxOfRateMeas(Index)                                                    (EthTSyn_GetRateMeasOfPCConfig()[(Index)].RateRatioMaxOfRateMeas)
#define EthTSyn_GetRateRatioMinOfRateMeas(Index)                                                    (EthTSyn_GetRateMeasOfPCConfig()[(Index)].RateRatioMinOfRateMeas)
#define EthTSyn_GetSyncPrecisionLimitNsOfRateMeas(Index)                                            (EthTSyn_GetRateMeasOfPCConfig()[(Index)].SyncPrecisionLimitNsOfRateMeas)
#define EthTSyn_IsUseInitialOffsetCorrectionOfRateMeas(Index)                                       ((EthTSyn_GetRateMeasOfPCConfig()[(Index)].UseInitialOffsetCorrectionOfRateMeas) != FALSE)
#define EthTSyn_GetAccumulatedMasterTimeDiffOfRateMeasBuf(Index)                                    (EthTSyn_GetRateMeasBufOfPCConfig()[(Index)].AccumulatedMasterTimeDiffOfRateMeasBuf)
#define EthTSyn_GetAccumulatedSwtTimeDiffOfRateMeasBuf(Index)                                       (EthTSyn_GetRateMeasBufOfPCConfig()[(Index)].AccumulatedSwtTimeDiffOfRateMeasBuf)
#define EthTSyn_GetActiveNrOfSyncCyclesOfRateMeasBuf(Index)                                         (EthTSyn_GetRateMeasBufOfPCConfig()[(Index)].ActiveNrOfSyncCyclesOfRateMeasBuf)
#define EthTSyn_IsActiveOfRateMeasBuf(Index)                                                        ((EthTSyn_GetRateMeasBufOfPCConfig()[(Index)].ActiveOfRateMeasBuf) != FALSE)
#define EthTSyn_GetCurrTsInfoOfRateMeasDyn(Index)                                                   (EthTSyn_GetRateMeasDynOfPCConfig()[(Index)].CurrTsInfoOfRateMeasDyn)
#define EthTSyn_GetLastCorrectedOffsetNsOfRateMeasDyn(Index)                                        (EthTSyn_GetRateMeasDynOfPCConfig()[(Index)].LastCorrectedOffsetNsOfRateMeasDyn)
#define EthTSyn_GetOutOfSyncCntOfRateMeasDyn(Index)                                                 (EthTSyn_GetRateMeasDynOfPCConfig()[(Index)].OutOfSyncCntOfRateMeasDyn)
#define EthTSyn_GetPrevTsInfoOfRateMeasDyn(Index)                                                   (EthTSyn_GetRateMeasDynOfPCConfig()[(Index)].PrevTsInfoOfRateMeasDyn)
#define EthTSyn_GetStateOfRateMeasDyn(Index)                                                        (EthTSyn_GetRateMeasDynOfPCConfig()[(Index)].StateOfRateMeasDyn)
#define EthTSyn_GetSyncCycleCounterOfRateMeasDyn(Index)                                             (EthTSyn_GetRateMeasDynOfPCConfig()[(Index)].SyncCycleCounterOfRateMeasDyn)
#define EthTSyn_IsSyncCycleCounterRestartedOfRateMeasDyn(Index)                                     ((EthTSyn_GetRateMeasDynOfPCConfig()[(Index)].SyncCycleCounterRestartedOfRateMeasDyn) != FALSE)
#define EthTSyn_IsWasSyncReachedOfRateMeasDyn(Index)                                                ((EthTSyn_GetRateMeasDynOfPCConfig()[(Index)].WasSyncReachedOfRateMeasDyn) != FALSE)
#define EthTSyn_GetBridgeTxMasterPortEndIdxOfSiteSyncSyncTx(Index)                                  (EthTSyn_GetSiteSyncSyncTxOfPCConfig()[(Index)].BridgeTxMasterPortEndIdxOfSiteSyncSyncTx)
#define EthTSyn_GetBridgeTxMasterPortStartIdxOfSiteSyncSyncTx(Index)                                (EthTSyn_GetSiteSyncSyncTxOfPCConfig()[(Index)].BridgeTxMasterPortStartIdxOfSiteSyncSyncTx)
#define EthTSyn_GetNumMsgFwdRetryOfSiteSyncSyncTx(Index)                                            (EthTSyn_GetSiteSyncSyncTxOfPCConfig()[(Index)].NumMsgFwdRetryOfSiteSyncSyncTx)
#define EthTSyn_GetFwdRetryCntOfSiteSyncSyncTxDyn(Index)                                            (EthTSyn_GetSiteSyncSyncTxDynOfPCConfig()[(Index)].FwdRetryCntOfSiteSyncSyncTxDyn)
#define EthTSyn_GetLastMsgHdrOfSiteSyncSyncTxDyn(Index)                                             (EthTSyn_GetSiteSyncSyncTxDynOfPCConfig()[(Index)].LastMsgHdrOfSiteSyncSyncTxDyn)
#define EthTSyn_GetLastSyncRefTsMgmtOfSiteSyncSyncTxDyn(Index)                                      (EthTSyn_GetSiteSyncSyncTxDynOfPCConfig()[(Index)].LastSyncRefTsMgmtOfSiteSyncSyncTxDyn)
#define EthTSyn_GetSlavePdelayNsOfSiteSyncSyncTxDyn(Index)                                          (EthTSyn_GetSiteSyncSyncTxDynOfPCConfig()[(Index)].SlavePdelayNsOfSiteSyncSyncTxDyn)
#define EthTSyn_GetStateOfSiteSyncSyncTxDyn(Index)                                                  (EthTSyn_GetSiteSyncSyncTxDynOfPCConfig()[(Index)].StateOfSiteSyncSyncTxDyn)
#define EthTSyn_GetAnnounceRcvSmIdxOfSlaveRxData(Index)                                             (EthTSyn_GetSlaveRxDataOfPCConfig()[(Index)].AnnounceRcvSmIdxOfSlaveRxData)
#define EthTSyn_GetSlaveRxMasterClockIdDynIdxOfSlaveRxData(Index)                                   (EthTSyn_GetSlaveRxDataOfPCConfig()[(Index)].SlaveRxMasterClockIdDynIdxOfSlaveRxData)
#define EthTSyn_GetSlaveRxSrcPortIdCheckClockIdIdxOfSlaveRxData(Index)                              (EthTSyn_GetSlaveRxDataOfPCConfig()[(Index)].SlaveRxSrcPortIdCheckClockIdIdxOfSlaveRxData)
#define EthTSyn_GetSyncRcvSmIdxOfSlaveRxData(Index)                                                 (EthTSyn_GetSlaveRxDataOfPCConfig()[(Index)].SyncRcvSmIdxOfSlaveRxData)
#define EthTSyn_GetComCtrlPortIdxOfSlaveRxDataHandler(Index)                                        (EthTSyn_GetSlaveRxDataHandlerOfPCConfig()[(Index)].ComCtrlPortIdxOfSlaveRxDataHandler)
#define EthTSyn_GetSlaveRxDataExternalIdxOfSlaveRxDataHandler(Index)                                (EthTSyn_GetSlaveRxDataHandlerOfPCConfig()[(Index)].SlaveRxDataExternalIdxOfSlaveRxDataHandler)
#define EthTSyn_GetValidMasterClockIdOfSlaveRxMasterClockIdDyn(Index)                               (EthTSyn_GetSlaveRxMasterClockIdDynOfPCConfig()[(Index)].ValidMasterClockIdOfSlaveRxMasterClockIdDyn)
#define EthTSyn_IsValidMasterSetOfSlaveRxMasterClockIdDyn(Index)                                    ((EthTSyn_GetSlaveRxMasterClockIdDynOfPCConfig()[(Index)].ValidMasterSetOfSlaveRxMasterClockIdDyn) != FALSE)
#define EthTSyn_GetSlaveRxSrcPortIdCheckClockId(Index)                                              (EthTSyn_GetSlaveRxSrcPortIdCheckClockIdOfPCConfig()[(Index)])
#define EthTSyn_GetSlaveSwitchIdxList(Index)                                                        (EthTSyn_GetSlaveSwitchIdxListOfPCConfig()[(Index)])
#define EthTSyn_IsApplyRateRatioToSlaveSwitchesOfSwtTimeSyncSm(Index)                               ((EthTSyn_GetSwtTimeSyncSmOfPCConfig()[(Index)].ApplyRateRatioToSlaveSwitchesOfSwtTimeSyncSm) != FALSE)
#define EthTSyn_GetEthIfSwitchIdxOfSwtTimeSyncSm(Index)                                             (EthTSyn_GetSwtTimeSyncSmOfPCConfig()[(Index)].EthIfSwitchIdxOfSwtTimeSyncSm)
#define EthTSyn_GetRateMeasIdxOfSwtTimeSyncSm(Index)                                                (EthTSyn_GetSwtTimeSyncSmOfPCConfig()[(Index)].RateMeasIdxOfSwtTimeSyncSm)
#define EthTSyn_GetSlaveSwitchIdxListEndIdxOfSwtTimeSyncSm(Index)                                   (EthTSyn_GetSwtTimeSyncSmOfPCConfig()[(Index)].SlaveSwitchIdxListEndIdxOfSwtTimeSyncSm)
#define EthTSyn_GetSlaveSwitchIdxListStartIdxOfSwtTimeSyncSm(Index)                                 (EthTSyn_GetSwtTimeSyncSmOfPCConfig()[(Index)].SlaveSwitchIdxListStartIdxOfSwtTimeSyncSm)
#define EthTSyn_GetSwtSyncStateChgFctPtrOfSwtTimeSyncSm(Index)                                      (EthTSyn_GetSwtTimeSyncSmOfPCConfig()[(Index)].SwtSyncStateChgFctPtrOfSwtTimeSyncSm)
#define EthTSyn_GetSyncEventTimeoutOfSwtTimeSyncSm(Index)                                           (EthTSyn_GetSwtTimeSyncSmOfPCConfig()[(Index)].SyncEventTimeoutOfSwtTimeSyncSm)
#define EthTSyn_GetStateOfSwtTimeSyncSmDyn(Index)                                                   (EthTSyn_GetSwtTimeSyncSmDynOfPCConfig()[(Index)].StateOfSwtTimeSyncSmDyn)
#define EthTSyn_GetSwtSyncStateOfSwtTimeSyncSmDyn(Index)                                            (EthTSyn_GetSwtTimeSyncSmDynOfPCConfig()[(Index)].SwtSyncStateOfSwtTimeSyncSmDyn)
#define EthTSyn_GetSyncEventTimeoutCntOfSwtTimeSyncSmDyn(Index)                                     (EthTSyn_GetSwtTimeSyncSmDynOfPCConfig()[(Index)].SyncEventTimeoutCntOfSwtTimeSyncSmDyn)
#define EthTSyn_GetTimeStampInfoOfSwtTimeSyncSmDyn(Index)                                           (EthTSyn_GetSwtTimeSyncSmDynOfPCConfig()[(Index)].TimeStampInfoOfSwtTimeSyncSmDyn)
#define EthTSyn_GetFollowUpRxTimeoutOfSyncRcvSm(Index)                                              (EthTSyn_GetSyncRcvSmOfPCConfig()[(Index)].FollowUpRxTimeoutOfSyncRcvSm)
#define EthTSyn_GetFupRxHandlerIdxOfSyncRcvSm(Index)                                                (EthTSyn_GetSyncRcvSmOfPCConfig()[(Index)].FupRxHandlerIdxOfSyncRcvSm)
#define EthTSyn_GetPortParamStatsDynIdxOfSyncRcvSm(Index)                                           (EthTSyn_GetSyncRcvSmOfPCConfig()[(Index)].PortParamStatsDynIdxOfSyncRcvSm)
#define EthTSyn_IsAnySyncReceivedOfSyncRcvSmDyn(Index)                                              ((EthTSyn_GetSyncRcvSmDynOfPCConfig()[(Index)].AnySyncReceivedOfSyncRcvSmDyn) != FALSE)
#define EthTSyn_GetFupRxTimeoutCntOfSyncRcvSmDyn(Index)                                             (EthTSyn_GetSyncRcvSmDynOfPCConfig()[(Index)].FupRxTimeoutCntOfSyncRcvSmDyn)
#define EthTSyn_IsResetRequestedOfSyncRcvSmDyn(Index)                                               ((EthTSyn_GetSyncRcvSmDynOfPCConfig()[(Index)].ResetRequestedOfSyncRcvSmDyn) != FALSE)
#define EthTSyn_GetStateOfSyncRcvSmDyn(Index)                                                       (EthTSyn_GetSyncRcvSmDynOfPCConfig()[(Index)].StateOfSyncRcvSmDyn)
#define EthTSyn_GetSyncRxTimeInfoOfSyncRcvSmDyn(Index)                                              (EthTSyn_GetSyncRcvSmDynOfPCConfig()[(Index)].SyncRxTimeInfoOfSyncRcvSmDyn)
#define EthTSyn_GetSyncSequenceIdOfSyncRcvSmDyn(Index)                                              (EthTSyn_GetSyncRcvSmDynOfPCConfig()[(Index)].SyncSequenceIdOfSyncRcvSmDyn)
#define EthTSyn_GetSyncSrcClockIdOfSyncRcvSmDyn(Index)                                              (EthTSyn_GetSyncRcvSmDynOfPCConfig()[(Index)].SyncSrcClockIdOfSyncRcvSmDyn)
#define EthTSyn_GetSyncSrcPortNumOfSyncRcvSmDyn(Index)                                              (EthTSyn_GetSyncRcvSmDynOfPCConfig()[(Index)].SyncSrcPortNumOfSyncRcvSmDyn)
#define EthTSyn_GetCrcHndlIdxOfSyncSendSm(Index)                                                    (EthTSyn_GetSyncSendSmOfPCConfig()[(Index)].CrcHndlIdxOfSyncSendSm)
#define EthTSyn_GetCrcTimeFlagsOfSyncSendSm(Index)                                                  (EthTSyn_GetSyncSendSmOfPCConfig()[(Index)].CrcTimeFlagsOfSyncSendSm)
#define EthTSyn_GetCyclicMsgResumeCntOfSyncSendSm(Index)                                            (EthTSyn_GetSyncSendSmOfPCConfig()[(Index)].CyclicMsgResumeCntOfSyncSendSm)
#define EthTSyn_GetFupTxLenOfSyncSendSm(Index)                                                      (EthTSyn_GetSyncSendSmOfPCConfig()[(Index)].FupTxLenOfSyncSendSm)
#define EthTSyn_IsImmediateTimeSyncOfSyncSendSm(Index)                                              ((EthTSyn_GetSyncSendSmOfPCConfig()[(Index)].ImmediateTimeSyncOfSyncSendSm) != FALSE)
#define EthTSyn_GetPortSyncSendSmIdxOfSyncSendSm(Index)                                             (EthTSyn_GetSyncSendSmOfPCConfig()[(Index)].PortSyncSendSmIdxOfSyncSendSm)
#define EthTSyn_GetSyncLogMsgIntervalOfSyncSendSm(Index)                                            (EthTSyn_GetSyncSendSmOfPCConfig()[(Index)].SyncLogMsgIntervalOfSyncSendSm)
#define EthTSyn_GetSyncSendIntervalOfSyncSendSm(Index)                                              (EthTSyn_GetSyncSendSmOfPCConfig()[(Index)].SyncSendIntervalOfSyncSendSm)
#define EthTSyn_GetTimeBaseUpdateCounterIdxOfSyncSendSm(Index)                                      (EthTSyn_GetSyncSendSmOfPCConfig()[(Index)].TimeBaseUpdateCounterIdxOfSyncSendSm)
#define EthTSyn_GetTxCrcSecuredOfSyncSendSm(Index)                                                  (EthTSyn_GetSyncSendSmOfPCConfig()[(Index)].TxCrcSecuredOfSyncSendSm)
#define EthTSyn_GetFupCorrFieldOfSyncSendSmDyn(Index)                                               (EthTSyn_GetSyncSendSmDynOfPCConfig()[(Index)].FupCorrFieldOfSyncSendSmDyn)
#define EthTSyn_GetPreciseOriginTsOfSyncSendSmDyn(Index)                                            (EthTSyn_GetSyncSendSmDynOfPCConfig()[(Index)].PreciseOriginTsOfSyncSendSmDyn)
#define EthTSyn_GetSequenceIdOfSyncSendSmDyn(Index)                                                 (EthTSyn_GetSyncSendSmDynOfPCConfig()[(Index)].SequenceIdOfSyncSendSmDyn)
#define EthTSyn_IsSmResetRequestedOfSyncSendSmDyn(Index)                                            ((EthTSyn_GetSyncSendSmDynOfPCConfig()[(Index)].SmResetRequestedOfSyncSendSmDyn) != FALSE)
#define EthTSyn_GetStateOfSyncSendSmDyn(Index)                                                      (EthTSyn_GetSyncSendSmDynOfPCConfig()[(Index)].StateOfSyncSendSmDyn)
#define EthTSyn_GetSyncTxInfoOfSyncSendSmDyn(Index)                                                 (EthTSyn_GetSyncSendSmDynOfPCConfig()[(Index)].SyncTxInfoOfSyncSendSmDyn)
#define EthTSyn_GetTxIntervalCntOfSyncSendSmDyn(Index)                                              (EthTSyn_GetSyncSendSmDynOfPCConfig()[(Index)].TxIntervalCntOfSyncSendSmDyn)
#define EthTSyn_GetSynchronizedTimeBaseIdOfTimeBaseUpdateCounter(Index)                             (EthTSyn_GetTimeBaseUpdateCounterOfPCConfig()[(Index)].SynchronizedTimeBaseIdOfTimeBaseUpdateCounter)
#define EthTSyn_IsUpdatedOfTimeBaseUpdateCounterDyn(Index)                                          ((EthTSyn_GetTimeBaseUpdateCounterDynOfPCConfig()[(Index)].UpdatedOfTimeBaseUpdateCounterDyn) != FALSE)
#define EthTSyn_GetValueOfTimeBaseUpdateCounterDyn(Index)                                           (EthTSyn_GetTimeBaseUpdateCounterDynOfPCConfig()[(Index)].ValueOfTimeBaseUpdateCounterDyn)
#define EthTSyn_GetComCtrlPortIdxOfTxConfContext(Index)                                             (EthTSyn_GetTxConfContextOfPCConfig()[(Index)].ComCtrlPortIdxOfTxConfContext)
#define EthTSyn_GetTxSmIdxOfTxConfContext(Index)                                                    (EthTSyn_GetTxConfContextOfPCConfig()[(Index)].TxSmIdxOfTxConfContext)
#define EthTSyn_GetTxSmOfTxConfContext(Index)                                                       (EthTSyn_GetTxConfContextOfPCConfig()[(Index)].TxSmOfTxConfContext)
#define EthTSyn_IsActiveOfTxConfContextDyn(Index)                                                   ((EthTSyn_GetTxConfContextDynOfPCConfig()[(Index)].ActiveOfTxConfContextDyn) != FALSE)
#define EthTSyn_GetBufferIdxOfTxConfContextDyn(Index)                                               (EthTSyn_GetTxConfContextDynOfPCConfig()[(Index)].BufferIdxOfTxConfContextDyn)
#define EthTSyn_GetTxConfContextNextActiveIdxOfTxConfContextDyn(Index)                              (EthTSyn_GetTxConfContextDynOfPCConfig()[(Index)].TxConfContextNextActiveIdxOfTxConfContextDyn)
#define EthTSyn_GetTxConfContextPrevActiveIdxOfTxConfContextDyn(Index)                              (EthTSyn_GetTxConfContextDynOfPCConfig()[(Index)].TxConfContextPrevActiveIdxOfTxConfContextDyn)
#define EthTSyn_GetTxConfContextDynActiveFirstIdx()                                                 ((*(EthTSyn_GetTxConfContextDynActiveFirstIdxOfPCConfig())))
#define EthTSyn_GetTxConfContextDynActiveLastIdx()                                                  ((*(EthTSyn_GetTxConfContextDynActiveLastIdxOfPCConfig())))
/** 
  \}
*/ 

/** 
  \defgroup  EthTSynPCGetDeduplicatedDataMacros  EthTSyn Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define EthTSyn_IsAnnounceSendSmUsedOfComCtrlPort(Index)                                            (((boolean)(EthTSyn_GetAnnounceSendSmIdxOfComCtrlPort(Index) != ETHTSYN_NO_ANNOUNCESENDSMIDXOFCOMCTRLPORT)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthTSyn_AnnounceSendSm */
#define EthTSyn_IsPdReqSmUsedOfComCtrlPort(Index)                                                   (((boolean)(EthTSyn_GetPdReqSmIdxOfComCtrlPort(Index) != ETHTSYN_NO_PDREQSMIDXOFCOMCTRLPORT)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthTSyn_PdReqSm */
#define EthTSyn_IsPdRespSmUsedOfComCtrlPort(Index)                                                  (((boolean)(EthTSyn_GetPdRespSmIdxOfComCtrlPort(Index) != ETHTSYN_NO_PDRESPSMIDXOFCOMCTRLPORT)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthTSyn_PdRespSm */
#define EthTSyn_IsPortParamStatsDynUsedOfComCtrlPort(Index)                                         (((boolean)(EthTSyn_GetPortParamStatsDynIdxOfComCtrlPort(Index) != ETHTSYN_NO_PORTPARAMSTATSDYNIDXOFCOMCTRLPORT)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthTSyn_PortParamStatsDyn */
#define EthTSyn_IsPortSyncSendSmUsedOfComCtrlPort(Index)                                            (((boolean)(EthTSyn_GetPortSyncSendSmIdxOfComCtrlPort(Index) != ETHTSYN_NO_PORTSYNCSENDSMIDXOFCOMCTRLPORT)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthTSyn_PortSyncSendSm */
#define EthTSyn_IsSlaveRxDataHandlerUsedOfComCtrlPort(Index)                                        (((boolean)(EthTSyn_GetSlaveRxDataHandlerIdxOfComCtrlPort(Index) != ETHTSYN_NO_SLAVERXDATAHANDLERIDXOFCOMCTRLPORT)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthTSyn_SlaveRxDataHandler */
#define EthTSyn_IsSyncSendSmUsedOfComCtrlPort(Index)                                                (((boolean)(EthTSyn_GetSyncSendSmIdxOfComCtrlPort(Index) != ETHTSYN_NO_SYNCSENDSMIDXOFCOMCTRLPORT)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthTSyn_SyncSendSm */
#define EthTSyn_IsOffsetTimeDomainUsedOfComCtrlTimeDomain(Index)                                    (((boolean)(EthTSyn_GetOffsetTimeDomainStartIdxOfComCtrlTimeDomain(Index) != ETHTSYN_NO_OFFSETTIMEDOMAINSTARTIDXOFCOMCTRLTIMEDOMAIN)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthTSyn_OffsetTimeDomain */
#define EthTSyn_IsCrcHndlUsedOfFupRxHandler(Index)                                                  (((boolean)(EthTSyn_GetCrcHndlIdxOfFupRxHandler(Index) != ETHTSYN_NO_CRCHNDLIDXOFFUPRXHANDLER)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthTSyn_CrcHndl */
#define EthTSyn_IsMsgSentCbkBufUsedOfPortSyncSendSm(Index)                                          (((boolean)(EthTSyn_GetMsgSentCbkBufLengthOfPortSyncSendSm(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthTSyn_MsgSentCbkBuf */
#define EthTSyn_GetSizeOfAnnounceRcvSm()                                                            EthTSyn_GetSizeOfAnnounceRcvSmOfPCConfig()
#define EthTSyn_GetSizeOfAnnounceRcvSmDyn()                                                         EthTSyn_GetSizeOfAnnounceRcvSmDynOfPCConfig()
#define EthTSyn_GetSizeOfAnnounceSendSm()                                                           EthTSyn_GetSizeOfAnnounceSendSmOfPCConfig()
#define EthTSyn_GetSizeOfAnnounceSendSmDyn()                                                        EthTSyn_GetSizeOfAnnounceSendSmDynOfPCConfig()
#define EthTSyn_GetSizeOfBridgeTxMasterPort()                                                       EthTSyn_GetSizeOfBridgeTxMasterPortOfPCConfig()
#define EthTSyn_GetSizeOfBridgeTxMasterPortDyn()                                                    EthTSyn_GetSizeOfBridgeTxMasterPortDynOfPCConfig()
#define EthTSyn_GetSizeOfComCtrlEthIfCtrl()                                                         EthTSyn_GetSizeOfComCtrlEthIfCtrlOfPCConfig()
#define EthTSyn_GetSizeOfComCtrlEthIfCtrlDyn()                                                      EthTSyn_GetSizeOfComCtrlEthIfCtrlDynOfPCConfig()
#define EthTSyn_GetSizeOfComCtrlPhysPort()                                                          EthTSyn_GetSizeOfComCtrlPhysPortOfPCConfig()
#define EthTSyn_GetSizeOfComCtrlPhysPortDyn()                                                       EthTSyn_GetSizeOfComCtrlPhysPortDynOfPCConfig()
#define EthTSyn_GetSizeOfComCtrlPort()                                                              EthTSyn_GetSizeOfComCtrlPortOfPCConfig()
#define EthTSyn_GetSizeOfComCtrlPortInd()                                                           EthTSyn_GetSizeOfComCtrlPortIndOfPCConfig()
#define EthTSyn_GetSizeOfComCtrlTimeDomain()                                                        EthTSyn_GetSizeOfComCtrlTimeDomainOfPCConfig()
#define EthTSyn_GetSizeOfCrcHndl()                                                                  EthTSyn_GetSizeOfCrcHndlOfPCConfig()
#define EthTSyn_GetSizeOfDestinationMac()                                                           EthTSyn_GetSizeOfDestinationMacOfPCConfig()
#define EthTSyn_GetSizeOfDestinationMacInd()                                                        EthTSyn_GetSizeOfDestinationMacIndOfPCConfig()
#define EthTSyn_GetSizeOfFupDataIdList()                                                            EthTSyn_GetSizeOfFupDataIdListOfPCConfig()
#define EthTSyn_GetSizeOfFupRxHandler()                                                             EthTSyn_GetSizeOfFupRxHandlerOfPCConfig()
#define EthTSyn_GetSizeOfMsgSentCbkBuf()                                                            EthTSyn_GetSizeOfMsgSentCbkBufOfPCConfig()
#define EthTSyn_GetSizeOfOffsetTimeDomain()                                                         EthTSyn_GetSizeOfOffsetTimeDomainOfPCConfig()
#define EthTSyn_GetSizeOfPdReqSm()                                                                  EthTSyn_GetSizeOfPdReqSmOfPCConfig()
#define EthTSyn_GetSizeOfPdReqSmDyn()                                                               EthTSyn_GetSizeOfPdReqSmDynOfPCConfig()
#define EthTSyn_GetSizeOfPdReqTrcvDyn()                                                             EthTSyn_GetSizeOfPdReqTrcvDynOfPCConfig()
#define EthTSyn_GetSizeOfPdRespSm()                                                                 EthTSyn_GetSizeOfPdRespSmOfPCConfig()
#define EthTSyn_GetSizeOfPdRespSmDyn()                                                              EthTSyn_GetSizeOfPdRespSmDynOfPCConfig()
#define EthTSyn_GetSizeOfPortParamStatsDyn()                                                        EthTSyn_GetSizeOfPortParamStatsDynOfPCConfig()
#define EthTSyn_GetSizeOfPortSyncSendSm()                                                           EthTSyn_GetSizeOfPortSyncSendSmOfPCConfig()
#define EthTSyn_GetSizeOfPortSyncSendSmDyn()                                                        EthTSyn_GetSizeOfPortSyncSendSmDynOfPCConfig()
#define EthTSyn_GetSizeOfRateMeas()                                                                 EthTSyn_GetSizeOfRateMeasOfPCConfig()
#define EthTSyn_GetSizeOfRateMeasBuf()                                                              EthTSyn_GetSizeOfRateMeasBufOfPCConfig()
#define EthTSyn_GetSizeOfRateMeasDyn()                                                              EthTSyn_GetSizeOfRateMeasDynOfPCConfig()
#define EthTSyn_GetSizeOfSiteSyncSyncTx()                                                           EthTSyn_GetSizeOfSiteSyncSyncTxOfPCConfig()
#define EthTSyn_GetSizeOfSiteSyncSyncTxDyn()                                                        EthTSyn_GetSizeOfSiteSyncSyncTxDynOfPCConfig()
#define EthTSyn_GetSizeOfSlaveRxData()                                                              EthTSyn_GetSizeOfSlaveRxDataOfPCConfig()
#define EthTSyn_GetSizeOfSlaveRxDataHandler()                                                       EthTSyn_GetSizeOfSlaveRxDataHandlerOfPCConfig()
#define EthTSyn_GetSizeOfSlaveRxMasterClockIdDyn()                                                  EthTSyn_GetSizeOfSlaveRxMasterClockIdDynOfPCConfig()
#define EthTSyn_GetSizeOfSlaveRxSrcPortIdCheckClockId()                                             EthTSyn_GetSizeOfSlaveRxSrcPortIdCheckClockIdOfPCConfig()
#define EthTSyn_GetSizeOfSlaveSwitchIdxList()                                                       EthTSyn_GetSizeOfSlaveSwitchIdxListOfPCConfig()
#define EthTSyn_GetSizeOfSwtTimeSyncSm()                                                            EthTSyn_GetSizeOfSwtTimeSyncSmOfPCConfig()
#define EthTSyn_GetSizeOfSwtTimeSyncSmDyn()                                                         EthTSyn_GetSizeOfSwtTimeSyncSmDynOfPCConfig()
#define EthTSyn_GetSizeOfSyncRcvSm()                                                                EthTSyn_GetSizeOfSyncRcvSmOfPCConfig()
#define EthTSyn_GetSizeOfSyncRcvSmDyn()                                                             EthTSyn_GetSizeOfSyncRcvSmDynOfPCConfig()
#define EthTSyn_GetSizeOfSyncSendSm()                                                               EthTSyn_GetSizeOfSyncSendSmOfPCConfig()
#define EthTSyn_GetSizeOfSyncSendSmDyn()                                                            EthTSyn_GetSizeOfSyncSendSmDynOfPCConfig()
#define EthTSyn_GetSizeOfTimeBaseUpdateCounter()                                                    EthTSyn_GetSizeOfTimeBaseUpdateCounterOfPCConfig()
#define EthTSyn_GetSizeOfTimeBaseUpdateCounterDyn()                                                 EthTSyn_GetSizeOfTimeBaseUpdateCounterDynOfPCConfig()
#define EthTSyn_GetSizeOfTxConfContext()                                                            EthTSyn_GetSizeOfTxConfContextOfPCConfig()
#define EthTSyn_GetSizeOfTxConfContextDyn()                                                         EthTSyn_GetSizeOfTxConfContextDynOfPCConfig()
#define EthTSyn_IsAnnounceRcvSmUsedOfSlaveRxData(Index)                                             (((boolean)(EthTSyn_GetAnnounceRcvSmIdxOfSlaveRxData(Index) != ETHTSYN_NO_ANNOUNCERCVSMIDXOFSLAVERXDATA)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthTSyn_AnnounceRcvSm */
#define EthTSyn_IsSlaveRxMasterClockIdDynUsedOfSlaveRxData(Index)                                   (((boolean)(EthTSyn_GetSlaveRxMasterClockIdDynIdxOfSlaveRxData(Index) != ETHTSYN_NO_SLAVERXMASTERCLOCKIDDYNIDXOFSLAVERXDATA)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthTSyn_SlaveRxMasterClockIdDyn */
#define EthTSyn_IsSlaveRxSrcPortIdCheckClockIdUsedOfSlaveRxData(Index)                              (((boolean)(EthTSyn_GetSlaveRxSrcPortIdCheckClockIdIdxOfSlaveRxData(Index) != ETHTSYN_NO_SLAVERXSRCPORTIDCHECKCLOCKIDIDXOFSLAVERXDATA)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthTSyn_SlaveRxSrcPortIdCheckClockId */
#define EthTSyn_IsSlaveSwitchIdxListUsedOfSwtTimeSyncSm(Index)                                      (((boolean)(EthTSyn_GetSlaveSwitchIdxListStartIdxOfSwtTimeSyncSm(Index) != ETHTSYN_NO_SLAVESWITCHIDXLISTSTARTIDXOFSWTTIMESYNCSM)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to EthTSyn_SlaveSwitchIdxList */
#define EthTSyn_IsPortParamStatsDynUsedOfSyncRcvSm(Index)                                           (((boolean)(EthTSyn_GetPortParamStatsDynIdxOfSyncRcvSm(Index) != ETHTSYN_NO_PORTPARAMSTATSDYNIDXOFSYNCRCVSM)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthTSyn_PortParamStatsDyn */
#define EthTSyn_IsCrcHndlUsedOfSyncSendSm(Index)                                                    (((boolean)(EthTSyn_GetCrcHndlIdxOfSyncSendSm(Index) != ETHTSYN_NO_CRCHNDLIDXOFSYNCSENDSM)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthTSyn_CrcHndl */
#define EthTSyn_IsTimeBaseUpdateCounterUsedOfSyncSendSm(Index)                                      (((boolean)(EthTSyn_GetTimeBaseUpdateCounterIdxOfSyncSendSm(Index) != ETHTSYN_NO_TIMEBASEUPDATECOUNTERIDXOFSYNCSENDSM)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to EthTSyn_TimeBaseUpdateCounter */
/** 
  \}
*/ 

/** 
  \defgroup  EthTSynPCSetDataMacros  EthTSyn Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define EthTSyn_SetRxTimeoutCounterOfAnnounceRcvSmDyn(Index, Value)                                 EthTSyn_GetAnnounceRcvSmDynOfPCConfig()[(Index)].RxTimeoutCounterOfAnnounceRcvSmDyn = (Value)
#define EthTSyn_SetSmResetRequestedOfAnnounceRcvSmDyn(Index, Value)                                 EthTSyn_GetAnnounceRcvSmDynOfPCConfig()[(Index)].SmResetRequestedOfAnnounceRcvSmDyn = (Value)
#define EthTSyn_SetStateOfAnnounceRcvSmDyn(Index, Value)                                            EthTSyn_GetAnnounceRcvSmDynOfPCConfig()[(Index)].StateOfAnnounceRcvSmDyn = (Value)
#define EthTSyn_SetAnnounceCycleTimerOfAnnounceSendSmDyn(Index, Value)                              EthTSyn_GetAnnounceSendSmDynOfPCConfig()[(Index)].AnnounceCycleTimerOfAnnounceSendSmDyn = (Value)
#define EthTSyn_SetResetRequestedOfAnnounceSendSmDyn(Index, Value)                                  EthTSyn_GetAnnounceSendSmDynOfPCConfig()[(Index)].ResetRequestedOfAnnounceSendSmDyn = (Value)
#define EthTSyn_SetSequenceIdOfAnnounceSendSmDyn(Index, Value)                                      EthTSyn_GetAnnounceSendSmDynOfPCConfig()[(Index)].SequenceIdOfAnnounceSendSmDyn = (Value)
#define EthTSyn_SetStateOfAnnounceSendSmDyn(Index, Value)                                           EthTSyn_GetAnnounceSendSmDynOfPCConfig()[(Index)].StateOfAnnounceSendSmDyn = (Value)
#define EthTSyn_SetFupFwdStateOfBridgeTxMasterPortDyn(Index, Value)                                 EthTSyn_GetBridgeTxMasterPortDynOfPCConfig()[(Index)].FupFwdStateOfBridgeTxMasterPortDyn = (Value)
#define EthTSyn_SetSyncFwdDelayNsOfBridgeTxMasterPortDyn(Index, Value)                              EthTSyn_GetBridgeTxMasterPortDynOfPCConfig()[(Index)].SyncFwdDelayNsOfBridgeTxMasterPortDyn = (Value)
#define EthTSyn_SetClockIdOfComCtrlEthIfCtrlDyn(Index, Value)                                       EthTSyn_GetComCtrlEthIfCtrlDynOfPCConfig()[(Index)].ClockIdOfComCtrlEthIfCtrlDyn = (Value)
#define EthTSyn_SetLinkStateActiveOfComCtrlEthIfCtrlDyn(Index, Value)                               EthTSyn_GetComCtrlEthIfCtrlDynOfPCConfig()[(Index)].LinkStateActiveOfComCtrlEthIfCtrlDyn = (Value)
#define EthTSyn_SetTxActiveOfComCtrlEthIfCtrlDyn(Index, Value)                                      EthTSyn_GetComCtrlEthIfCtrlDynOfPCConfig()[(Index)].TxActiveOfComCtrlEthIfCtrlDyn = (Value)
#define EthTSyn_SetAsCapableOfComCtrlPhysPortDyn(Index, Value)                                      EthTSyn_GetComCtrlPhysPortDynOfPCConfig()[(Index)].AsCapableOfComCtrlPhysPortDyn = (Value)
#define EthTSyn_SetDebounceTimerOfComCtrlPhysPortDyn(Index, Value)                                  EthTSyn_GetComCtrlPhysPortDynOfPCConfig()[(Index)].DebounceTimerOfComCtrlPhysPortDyn = (Value)
#define EthTSyn_SetPdelayValueNsOfComCtrlPhysPortDyn(Index, Value)                                  EthTSyn_GetComCtrlPhysPortDynOfPCConfig()[(Index)].PdelayValueNsOfComCtrlPhysPortDyn = (Value)
#define EthTSyn_SetMsgSentCbkBuf(Index, Value)                                                      EthTSyn_GetMsgSentCbkBufOfPCConfig()[(Index)] = (Value)
#define EthTSyn_SetFirstPdelayOfPdReqSmDyn(Index, Value)                                            EthTSyn_GetPdReqSmDynOfPCConfig()[(Index)].FirstPdelayOfPdReqSmDyn = (Value)
#define EthTSyn_SetLostResponseCntOfPdReqSmDyn(Index, Value)                                        EthTSyn_GetPdReqSmDynOfPCConfig()[(Index)].LostResponseCntOfPdReqSmDyn = (Value)
#define EthTSyn_SetRefGlobalTimeOfPdReqSmDyn(Index, Value)                                          EthTSyn_GetPdReqSmDynOfPCConfig()[(Index)].RefGlobalTimeOfPdReqSmDyn = (Value)
#define EthTSyn_SetRefLocalTimeOfPdReqSmDyn(Index, Value)                                           EthTSyn_GetPdReqSmDynOfPCConfig()[(Index)].RefLocalTimeOfPdReqSmDyn = (Value)
#define EthTSyn_SetRespTimeoutCntOfPdReqSmDyn(Index, Value)                                         EthTSyn_GetPdReqSmDynOfPCConfig()[(Index)].RespTimeoutCntOfPdReqSmDyn = (Value)
#define EthTSyn_SetSequenceIdOfPdReqSmDyn(Index, Value)                                             EthTSyn_GetPdReqSmDynOfPCConfig()[(Index)].SequenceIdOfPdReqSmDyn = (Value)
#define EthTSyn_SetSmResetRequestedOfPdReqSmDyn(Index, Value)                                       EthTSyn_GetPdReqSmDynOfPCConfig()[(Index)].SmResetRequestedOfPdReqSmDyn = (Value)
#define EthTSyn_SetStateOfPdReqSmDyn(Index, Value)                                                  EthTSyn_GetPdReqSmDynOfPCConfig()[(Index)].StateOfPdReqSmDyn = (Value)
#define EthTSyn_SetTxIntervalCntOfPdReqSmDyn(Index, Value)                                          EthTSyn_GetPdReqSmDynOfPCConfig()[(Index)].TxIntervalCntOfPdReqSmDyn = (Value)
#define EthTSyn_SetPdReqEgrTsMgmtOfPdReqTrcvDyn(Index, Value)                                       EthTSyn_GetPdReqTrcvDynOfPCConfig()[(Index)].PdReqEgrTsMgmtOfPdReqTrcvDyn = (Value)
#define EthTSyn_SetPdReqEgrTsProvidedOfPdReqTrcvDyn(Index, Value)                                   EthTSyn_GetPdReqTrcvDynOfPCConfig()[(Index)].PdReqEgrTsProvidedOfPdReqTrcvDyn = (Value)
#define EthTSyn_SetPdRespIngrTsMgmtOfPdReqTrcvDyn(Index, Value)                                     EthTSyn_GetPdReqTrcvDynOfPCConfig()[(Index)].PdRespIngrTsMgmtOfPdReqTrcvDyn = (Value)
#define EthTSyn_SetReqReceivedTsOfPdReqTrcvDyn(Index, Value)                                        EthTSyn_GetPdReqTrcvDynOfPCConfig()[(Index)].ReqReceivedTsOfPdReqTrcvDyn = (Value)
#define EthTSyn_SetRespClockIdOfPdReqTrcvDyn(Index, Value)                                          EthTSyn_GetPdReqTrcvDynOfPCConfig()[(Index)].RespClockIdOfPdReqTrcvDyn = (Value)
#define EthTSyn_SetRespOriginTsOfPdReqTrcvDyn(Index, Value)                                         EthTSyn_GetPdReqTrcvDynOfPCConfig()[(Index)].RespOriginTsOfPdReqTrcvDyn = (Value)
#define EthTSyn_SetRespPortNumOfPdReqTrcvDyn(Index, Value)                                          EthTSyn_GetPdReqTrcvDynOfPCConfig()[(Index)].RespPortNumOfPdReqTrcvDyn = (Value)
#define EthTSyn_SetStateOfPdReqTrcvDyn(Index, Value)                                                EthTSyn_GetPdReqTrcvDynOfPCConfig()[(Index)].StateOfPdReqTrcvDyn = (Value)
#define EthTSyn_SetPdReqRcvdTsOfPdRespSmDyn(Index, Value)                                           EthTSyn_GetPdRespSmDynOfPCConfig()[(Index)].PdReqRcvdTsOfPdRespSmDyn = (Value)
#define EthTSyn_SetPdRespOrgTsOfPdRespSmDyn(Index, Value)                                           EthTSyn_GetPdRespSmDynOfPCConfig()[(Index)].PdRespOrgTsOfPdRespSmDyn = (Value)
#define EthTSyn_SetRequestorClockIdOfPdRespSmDyn(Index, Value)                                      EthTSyn_GetPdRespSmDynOfPCConfig()[(Index)].RequestorClockIdOfPdRespSmDyn = (Value)
#define EthTSyn_SetRequestorPortNumOfPdRespSmDyn(Index, Value)                                      EthTSyn_GetPdRespSmDynOfPCConfig()[(Index)].RequestorPortNumOfPdRespSmDyn = (Value)
#define EthTSyn_SetSequenceIdOfPdRespSmDyn(Index, Value)                                            EthTSyn_GetPdRespSmDynOfPCConfig()[(Index)].SequenceIdOfPdRespSmDyn = (Value)
#define EthTSyn_SetSmResetRequestedOfPdRespSmDyn(Index, Value)                                      EthTSyn_GetPdRespSmDynOfPCConfig()[(Index)].SmResetRequestedOfPdRespSmDyn = (Value)
#define EthTSyn_SetStateOfPdRespSmDyn(Index, Value)                                                 EthTSyn_GetPdRespSmDynOfPCConfig()[(Index)].StateOfPdRespSmDyn = (Value)
#define EthTSyn_SetPdLostRespExceededCountOfPortParamStatsDyn(Index, Value)                         EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].PdLostRespExceededCountOfPortParamStatsDyn = (Value)
#define EthTSyn_SetRxAnnounceCountOfPortParamStatsDyn(Index, Value)                                 EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].RxAnnounceCountOfPortParamStatsDyn = (Value)
#define EthTSyn_SetRxDiscardCountOfPortParamStatsDyn(Index, Value)                                  EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].RxDiscardCountOfPortParamStatsDyn = (Value)
#define EthTSyn_SetRxFupCountOfPortParamStatsDyn(Index, Value)                                      EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].RxFupCountOfPortParamStatsDyn = (Value)
#define EthTSyn_SetRxPdReqCountOfPortParamStatsDyn(Index, Value)                                    EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].RxPdReqCountOfPortParamStatsDyn = (Value)
#define EthTSyn_SetRxPdRespCountOfPortParamStatsDyn(Index, Value)                                   EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].RxPdRespCountOfPortParamStatsDyn = (Value)
#define EthTSyn_SetRxPdRespFupCountOfPortParamStatsDyn(Index, Value)                                EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].RxPdRespFupCountOfPortParamStatsDyn = (Value)
#define EthTSyn_SetRxSyncCountOfPortParamStatsDyn(Index, Value)                                     EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].RxSyncCountOfPortParamStatsDyn = (Value)
#define EthTSyn_SetTxAnnounceCountOfPortParamStatsDyn(Index, Value)                                 EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].TxAnnounceCountOfPortParamStatsDyn = (Value)
#define EthTSyn_SetTxFupCountOfPortParamStatsDyn(Index, Value)                                      EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].TxFupCountOfPortParamStatsDyn = (Value)
#define EthTSyn_SetTxPdReqCountOfPortParamStatsDyn(Index, Value)                                    EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].TxPdReqCountOfPortParamStatsDyn = (Value)
#define EthTSyn_SetTxPdRespCountOfPortParamStatsDyn(Index, Value)                                   EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].TxPdRespCountOfPortParamStatsDyn = (Value)
#define EthTSyn_SetTxPdRespFupCountOfPortParamStatsDyn(Index, Value)                                EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].TxPdRespFupCountOfPortParamStatsDyn = (Value)
#define EthTSyn_SetTxSyncCountOfPortParamStatsDyn(Index, Value)                                     EthTSyn_GetPortParamStatsDynOfPCConfig()[(Index)].TxSyncCountOfPortParamStatsDyn = (Value)
#define EthTSyn_SetEgrTsInfoOfPortSyncSendSmDyn(Index, Value)                                       EthTSyn_GetPortSyncSendSmDynOfPCConfig()[(Index)].EgrTsInfoOfPortSyncSendSmDyn = (Value)
#define EthTSyn_SetStateOfPortSyncSendSmDyn(Index, Value)                                           EthTSyn_GetPortSyncSendSmDynOfPCConfig()[(Index)].StateOfPortSyncSendSmDyn = (Value)
#define EthTSyn_SetAccumulatedMasterTimeDiffOfRateMeasBuf(Index, Value)                             EthTSyn_GetRateMeasBufOfPCConfig()[(Index)].AccumulatedMasterTimeDiffOfRateMeasBuf = (Value)
#define EthTSyn_SetAccumulatedSwtTimeDiffOfRateMeasBuf(Index, Value)                                EthTSyn_GetRateMeasBufOfPCConfig()[(Index)].AccumulatedSwtTimeDiffOfRateMeasBuf = (Value)
#define EthTSyn_SetActiveNrOfSyncCyclesOfRateMeasBuf(Index, Value)                                  EthTSyn_GetRateMeasBufOfPCConfig()[(Index)].ActiveNrOfSyncCyclesOfRateMeasBuf = (Value)
#define EthTSyn_SetActiveOfRateMeasBuf(Index, Value)                                                EthTSyn_GetRateMeasBufOfPCConfig()[(Index)].ActiveOfRateMeasBuf = (Value)
#define EthTSyn_SetCurrTsInfoOfRateMeasDyn(Index, Value)                                            EthTSyn_GetRateMeasDynOfPCConfig()[(Index)].CurrTsInfoOfRateMeasDyn = (Value)
#define EthTSyn_SetLastCorrectedOffsetNsOfRateMeasDyn(Index, Value)                                 EthTSyn_GetRateMeasDynOfPCConfig()[(Index)].LastCorrectedOffsetNsOfRateMeasDyn = (Value)
#define EthTSyn_SetOutOfSyncCntOfRateMeasDyn(Index, Value)                                          EthTSyn_GetRateMeasDynOfPCConfig()[(Index)].OutOfSyncCntOfRateMeasDyn = (Value)
#define EthTSyn_SetPrevTsInfoOfRateMeasDyn(Index, Value)                                            EthTSyn_GetRateMeasDynOfPCConfig()[(Index)].PrevTsInfoOfRateMeasDyn = (Value)
#define EthTSyn_SetStateOfRateMeasDyn(Index, Value)                                                 EthTSyn_GetRateMeasDynOfPCConfig()[(Index)].StateOfRateMeasDyn = (Value)
#define EthTSyn_SetSyncCycleCounterOfRateMeasDyn(Index, Value)                                      EthTSyn_GetRateMeasDynOfPCConfig()[(Index)].SyncCycleCounterOfRateMeasDyn = (Value)
#define EthTSyn_SetSyncCycleCounterRestartedOfRateMeasDyn(Index, Value)                             EthTSyn_GetRateMeasDynOfPCConfig()[(Index)].SyncCycleCounterRestartedOfRateMeasDyn = (Value)
#define EthTSyn_SetWasSyncReachedOfRateMeasDyn(Index, Value)                                        EthTSyn_GetRateMeasDynOfPCConfig()[(Index)].WasSyncReachedOfRateMeasDyn = (Value)
#define EthTSyn_SetFwdRetryCntOfSiteSyncSyncTxDyn(Index, Value)                                     EthTSyn_GetSiteSyncSyncTxDynOfPCConfig()[(Index)].FwdRetryCntOfSiteSyncSyncTxDyn = (Value)
#define EthTSyn_SetLastMsgHdrOfSiteSyncSyncTxDyn(Index, Value)                                      EthTSyn_GetSiteSyncSyncTxDynOfPCConfig()[(Index)].LastMsgHdrOfSiteSyncSyncTxDyn = (Value)
#define EthTSyn_SetLastSyncRefTsMgmtOfSiteSyncSyncTxDyn(Index, Value)                               EthTSyn_GetSiteSyncSyncTxDynOfPCConfig()[(Index)].LastSyncRefTsMgmtOfSiteSyncSyncTxDyn = (Value)
#define EthTSyn_SetSlavePdelayNsOfSiteSyncSyncTxDyn(Index, Value)                                   EthTSyn_GetSiteSyncSyncTxDynOfPCConfig()[(Index)].SlavePdelayNsOfSiteSyncSyncTxDyn = (Value)
#define EthTSyn_SetStateOfSiteSyncSyncTxDyn(Index, Value)                                           EthTSyn_GetSiteSyncSyncTxDynOfPCConfig()[(Index)].StateOfSiteSyncSyncTxDyn = (Value)
#define EthTSyn_SetValidMasterClockIdOfSlaveRxMasterClockIdDyn(Index, Value)                        EthTSyn_GetSlaveRxMasterClockIdDynOfPCConfig()[(Index)].ValidMasterClockIdOfSlaveRxMasterClockIdDyn = (Value)
#define EthTSyn_SetValidMasterSetOfSlaveRxMasterClockIdDyn(Index, Value)                            EthTSyn_GetSlaveRxMasterClockIdDynOfPCConfig()[(Index)].ValidMasterSetOfSlaveRxMasterClockIdDyn = (Value)
#define EthTSyn_SetStateOfSwtTimeSyncSmDyn(Index, Value)                                            EthTSyn_GetSwtTimeSyncSmDynOfPCConfig()[(Index)].StateOfSwtTimeSyncSmDyn = (Value)
#define EthTSyn_SetSwtSyncStateOfSwtTimeSyncSmDyn(Index, Value)                                     EthTSyn_GetSwtTimeSyncSmDynOfPCConfig()[(Index)].SwtSyncStateOfSwtTimeSyncSmDyn = (Value)
#define EthTSyn_SetSyncEventTimeoutCntOfSwtTimeSyncSmDyn(Index, Value)                              EthTSyn_GetSwtTimeSyncSmDynOfPCConfig()[(Index)].SyncEventTimeoutCntOfSwtTimeSyncSmDyn = (Value)
#define EthTSyn_SetTimeStampInfoOfSwtTimeSyncSmDyn(Index, Value)                                    EthTSyn_GetSwtTimeSyncSmDynOfPCConfig()[(Index)].TimeStampInfoOfSwtTimeSyncSmDyn = (Value)
#define EthTSyn_SetAnySyncReceivedOfSyncRcvSmDyn(Index, Value)                                      EthTSyn_GetSyncRcvSmDynOfPCConfig()[(Index)].AnySyncReceivedOfSyncRcvSmDyn = (Value)
#define EthTSyn_SetFupRxTimeoutCntOfSyncRcvSmDyn(Index, Value)                                      EthTSyn_GetSyncRcvSmDynOfPCConfig()[(Index)].FupRxTimeoutCntOfSyncRcvSmDyn = (Value)
#define EthTSyn_SetResetRequestedOfSyncRcvSmDyn(Index, Value)                                       EthTSyn_GetSyncRcvSmDynOfPCConfig()[(Index)].ResetRequestedOfSyncRcvSmDyn = (Value)
#define EthTSyn_SetStateOfSyncRcvSmDyn(Index, Value)                                                EthTSyn_GetSyncRcvSmDynOfPCConfig()[(Index)].StateOfSyncRcvSmDyn = (Value)
#define EthTSyn_SetSyncRxTimeInfoOfSyncRcvSmDyn(Index, Value)                                       EthTSyn_GetSyncRcvSmDynOfPCConfig()[(Index)].SyncRxTimeInfoOfSyncRcvSmDyn = (Value)
#define EthTSyn_SetSyncSequenceIdOfSyncRcvSmDyn(Index, Value)                                       EthTSyn_GetSyncRcvSmDynOfPCConfig()[(Index)].SyncSequenceIdOfSyncRcvSmDyn = (Value)
#define EthTSyn_SetSyncSrcClockIdOfSyncRcvSmDyn(Index, Value)                                       EthTSyn_GetSyncRcvSmDynOfPCConfig()[(Index)].SyncSrcClockIdOfSyncRcvSmDyn = (Value)
#define EthTSyn_SetSyncSrcPortNumOfSyncRcvSmDyn(Index, Value)                                       EthTSyn_GetSyncRcvSmDynOfPCConfig()[(Index)].SyncSrcPortNumOfSyncRcvSmDyn = (Value)
#define EthTSyn_SetFupCorrFieldOfSyncSendSmDyn(Index, Value)                                        EthTSyn_GetSyncSendSmDynOfPCConfig()[(Index)].FupCorrFieldOfSyncSendSmDyn = (Value)
#define EthTSyn_SetPreciseOriginTsOfSyncSendSmDyn(Index, Value)                                     EthTSyn_GetSyncSendSmDynOfPCConfig()[(Index)].PreciseOriginTsOfSyncSendSmDyn = (Value)
#define EthTSyn_SetSequenceIdOfSyncSendSmDyn(Index, Value)                                          EthTSyn_GetSyncSendSmDynOfPCConfig()[(Index)].SequenceIdOfSyncSendSmDyn = (Value)
#define EthTSyn_SetSmResetRequestedOfSyncSendSmDyn(Index, Value)                                    EthTSyn_GetSyncSendSmDynOfPCConfig()[(Index)].SmResetRequestedOfSyncSendSmDyn = (Value)
#define EthTSyn_SetStateOfSyncSendSmDyn(Index, Value)                                               EthTSyn_GetSyncSendSmDynOfPCConfig()[(Index)].StateOfSyncSendSmDyn = (Value)
#define EthTSyn_SetSyncTxInfoOfSyncSendSmDyn(Index, Value)                                          EthTSyn_GetSyncSendSmDynOfPCConfig()[(Index)].SyncTxInfoOfSyncSendSmDyn = (Value)
#define EthTSyn_SetTxIntervalCntOfSyncSendSmDyn(Index, Value)                                       EthTSyn_GetSyncSendSmDynOfPCConfig()[(Index)].TxIntervalCntOfSyncSendSmDyn = (Value)
#define EthTSyn_SetUpdatedOfTimeBaseUpdateCounterDyn(Index, Value)                                  EthTSyn_GetTimeBaseUpdateCounterDynOfPCConfig()[(Index)].UpdatedOfTimeBaseUpdateCounterDyn = (Value)
#define EthTSyn_SetValueOfTimeBaseUpdateCounterDyn(Index, Value)                                    EthTSyn_GetTimeBaseUpdateCounterDynOfPCConfig()[(Index)].ValueOfTimeBaseUpdateCounterDyn = (Value)
#define EthTSyn_SetActiveOfTxConfContextDyn(Index, Value)                                           EthTSyn_GetTxConfContextDynOfPCConfig()[(Index)].ActiveOfTxConfContextDyn = (Value)
#define EthTSyn_SetBufferIdxOfTxConfContextDyn(Index, Value)                                        EthTSyn_GetTxConfContextDynOfPCConfig()[(Index)].BufferIdxOfTxConfContextDyn = (Value)
#define EthTSyn_SetTxConfContextNextActiveIdxOfTxConfContextDyn(Index, Value)                       EthTSyn_GetTxConfContextDynOfPCConfig()[(Index)].TxConfContextNextActiveIdxOfTxConfContextDyn = (Value)
#define EthTSyn_SetTxConfContextPrevActiveIdxOfTxConfContextDyn(Index, Value)                       EthTSyn_GetTxConfContextDynOfPCConfig()[(Index)].TxConfContextPrevActiveIdxOfTxConfContextDyn = (Value)
#define EthTSyn_SetTxConfContextDynActiveFirstIdx(Value)                                            (*(EthTSyn_GetTxConfContextDynActiveFirstIdxOfPCConfig())) = (Value)
#define EthTSyn_SetTxConfContextDynActiveLastIdx(Value)                                             (*(EthTSyn_GetTxConfContextDynActiveLastIdxOfPCConfig())) = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  EthTSynPCGetAddressOfDataMacros  EthTSyn Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define EthTSyn_GetAddrMsgSentCbkBuf(Index)                                                         (&EthTSyn_GetMsgSentCbkBuf(Index))
#define EthTSyn_GetAddrRefGlobalTimeOfPdReqSmDyn(Index)                                             (&EthTSyn_GetRefGlobalTimeOfPdReqSmDyn(Index))
#define EthTSyn_GetAddrRefLocalTimeOfPdReqSmDyn(Index)                                              (&EthTSyn_GetRefLocalTimeOfPdReqSmDyn(Index))
#define EthTSyn_GetAddrPdReqEgrTsMgmtOfPdReqTrcvDyn(Index)                                          (&EthTSyn_GetPdReqEgrTsMgmtOfPdReqTrcvDyn(Index))
#define EthTSyn_GetAddrPdRespIngrTsMgmtOfPdReqTrcvDyn(Index)                                        (&EthTSyn_GetPdRespIngrTsMgmtOfPdReqTrcvDyn(Index))
#define EthTSyn_GetAddrReqReceivedTsOfPdReqTrcvDyn(Index)                                           (&EthTSyn_GetReqReceivedTsOfPdReqTrcvDyn(Index))
#define EthTSyn_GetAddrRespOriginTsOfPdReqTrcvDyn(Index)                                            (&EthTSyn_GetRespOriginTsOfPdReqTrcvDyn(Index))
#define EthTSyn_GetAddrPdReqRcvdTsOfPdRespSmDyn(Index)                                              (&EthTSyn_GetPdReqRcvdTsOfPdRespSmDyn(Index))
#define EthTSyn_GetAddrPdRespOrgTsOfPdRespSmDyn(Index)                                              (&EthTSyn_GetPdRespOrgTsOfPdRespSmDyn(Index))
#define EthTSyn_GetAddrPdLostRespExceededCountOfPortParamStatsDyn(Index)                            (&EthTSyn_GetPdLostRespExceededCountOfPortParamStatsDyn(Index))
#define EthTSyn_GetAddrRxAnnounceCountOfPortParamStatsDyn(Index)                                    (&EthTSyn_GetRxAnnounceCountOfPortParamStatsDyn(Index))
#define EthTSyn_GetAddrRxDiscardCountOfPortParamStatsDyn(Index)                                     (&EthTSyn_GetRxDiscardCountOfPortParamStatsDyn(Index))
#define EthTSyn_GetAddrRxFupCountOfPortParamStatsDyn(Index)                                         (&EthTSyn_GetRxFupCountOfPortParamStatsDyn(Index))
#define EthTSyn_GetAddrRxPdReqCountOfPortParamStatsDyn(Index)                                       (&EthTSyn_GetRxPdReqCountOfPortParamStatsDyn(Index))
#define EthTSyn_GetAddrRxPdRespCountOfPortParamStatsDyn(Index)                                      (&EthTSyn_GetRxPdRespCountOfPortParamStatsDyn(Index))
#define EthTSyn_GetAddrRxPdRespFupCountOfPortParamStatsDyn(Index)                                   (&EthTSyn_GetRxPdRespFupCountOfPortParamStatsDyn(Index))
#define EthTSyn_GetAddrRxSyncCountOfPortParamStatsDyn(Index)                                        (&EthTSyn_GetRxSyncCountOfPortParamStatsDyn(Index))
#define EthTSyn_GetAddrTxAnnounceCountOfPortParamStatsDyn(Index)                                    (&EthTSyn_GetTxAnnounceCountOfPortParamStatsDyn(Index))
#define EthTSyn_GetAddrTxFupCountOfPortParamStatsDyn(Index)                                         (&EthTSyn_GetTxFupCountOfPortParamStatsDyn(Index))
#define EthTSyn_GetAddrTxPdReqCountOfPortParamStatsDyn(Index)                                       (&EthTSyn_GetTxPdReqCountOfPortParamStatsDyn(Index))
#define EthTSyn_GetAddrTxPdRespCountOfPortParamStatsDyn(Index)                                      (&EthTSyn_GetTxPdRespCountOfPortParamStatsDyn(Index))
#define EthTSyn_GetAddrTxPdRespFupCountOfPortParamStatsDyn(Index)                                   (&EthTSyn_GetTxPdRespFupCountOfPortParamStatsDyn(Index))
#define EthTSyn_GetAddrTxSyncCountOfPortParamStatsDyn(Index)                                        (&EthTSyn_GetTxSyncCountOfPortParamStatsDyn(Index))
#define EthTSyn_GetAddrEgrTsInfoOfPortSyncSendSmDyn(Index)                                          (&EthTSyn_GetEgrTsInfoOfPortSyncSendSmDyn(Index))
#define EthTSyn_GetAddrCurrTsInfoOfRateMeasDyn(Index)                                               (&EthTSyn_GetCurrTsInfoOfRateMeasDyn(Index))
#define EthTSyn_GetAddrPrevTsInfoOfRateMeasDyn(Index)                                               (&EthTSyn_GetPrevTsInfoOfRateMeasDyn(Index))
#define EthTSyn_GetAddrLastMsgHdrOfSiteSyncSyncTxDyn(Index)                                         (&EthTSyn_GetLastMsgHdrOfSiteSyncSyncTxDyn(Index))
#define EthTSyn_GetAddrLastSyncRefTsMgmtOfSiteSyncSyncTxDyn(Index)                                  (&EthTSyn_GetLastSyncRefTsMgmtOfSiteSyncSyncTxDyn(Index))
#define EthTSyn_GetAddrSwtSyncStateOfSwtTimeSyncSmDyn(Index)                                        (&EthTSyn_GetSwtSyncStateOfSwtTimeSyncSmDyn(Index))
#define EthTSyn_GetAddrTimeStampInfoOfSwtTimeSyncSmDyn(Index)                                       (&EthTSyn_GetTimeStampInfoOfSwtTimeSyncSmDyn(Index))
#define EthTSyn_GetAddrSyncRxTimeInfoOfSyncRcvSmDyn(Index)                                          (&EthTSyn_GetSyncRxTimeInfoOfSyncRcvSmDyn(Index))
#define EthTSyn_GetAddrPreciseOriginTsOfSyncSendSmDyn(Index)                                        (&EthTSyn_GetPreciseOriginTsOfSyncSendSmDyn(Index))
#define EthTSyn_GetAddrSyncTxInfoOfSyncSendSmDyn(Index)                                             (&EthTSyn_GetSyncTxInfoOfSyncSendSmDyn(Index))
/** 
  \}
*/ 

/** 
  \defgroup  EthTSynPCHasMacros  EthTSyn Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define EthTSyn_HasAnnounceRcvSm()                                                                  (EthTSyn_GetAnnounceRcvSmOfPCConfig() != NULL_PTR)
#define EthTSyn_HasComCtrlPortIdxOfAnnounceRcvSm()                                                  (TRUE != FALSE)
#define EthTSyn_HasMaxStepsRemovedOfAnnounceRcvSm()                                                 (TRUE != FALSE)
#define EthTSyn_HasRxTimeoutOfAnnounceRcvSm()                                                       (TRUE != FALSE)
#define EthTSyn_HasSlaveRxDataIdxOfAnnounceRcvSm()                                                  (TRUE != FALSE)
#define EthTSyn_HasAnnounceRcvSmDyn()                                                               (EthTSyn_GetAnnounceRcvSmDynOfPCConfig() != NULL_PTR)
#define EthTSyn_HasRxTimeoutCounterOfAnnounceRcvSmDyn()                                             (TRUE != FALSE)
#define EthTSyn_HasSmResetRequestedOfAnnounceRcvSmDyn()                                             (TRUE != FALSE)
#define EthTSyn_HasStateOfAnnounceRcvSmDyn()                                                        (TRUE != FALSE)
#define EthTSyn_HasAnnounceSendSm()                                                                 (EthTSyn_GetAnnounceSendSmOfPCConfig() != NULL_PTR)
#define EthTSyn_HasAnnounceLogMsgIntervalOfAnnounceSendSm()                                         (TRUE != FALSE)
#define EthTSyn_HasAnnounceTxCycleOfAnnounceSendSm()                                                (TRUE != FALSE)
#define EthTSyn_HasComCtrlPortIdxOfAnnounceSendSm()                                                 (TRUE != FALSE)
#define EthTSyn_HasAnnounceSendSmDyn()                                                              (EthTSyn_GetAnnounceSendSmDynOfPCConfig() != NULL_PTR)
#define EthTSyn_HasAnnounceCycleTimerOfAnnounceSendSmDyn()                                          (TRUE != FALSE)
#define EthTSyn_HasResetRequestedOfAnnounceSendSmDyn()                                              (TRUE != FALSE)
#define EthTSyn_HasSequenceIdOfAnnounceSendSmDyn()                                                  (TRUE != FALSE)
#define EthTSyn_HasStateOfAnnounceSendSmDyn()                                                       (TRUE != FALSE)
#define EthTSyn_HasBridgeTxMasterPort()                                                             (EthTSyn_GetBridgeTxMasterPortOfPCConfig() != NULL_PTR)
#define EthTSyn_HasComCtrlPortIdxOfBridgeTxMasterPort()                                             (TRUE != FALSE)
#define EthTSyn_HasBridgeTxMasterPortDyn()                                                          (EthTSyn_GetBridgeTxMasterPortDynOfPCConfig() != NULL_PTR)
#define EthTSyn_HasFupFwdStateOfBridgeTxMasterPortDyn()                                             (TRUE != FALSE)
#define EthTSyn_HasSyncFwdDelayNsOfBridgeTxMasterPortDyn()                                          (TRUE != FALSE)
#define EthTSyn_HasComCtrlEthIfCtrl()                                                               (EthTSyn_GetComCtrlEthIfCtrlOfPCConfig() != NULL_PTR)
#define EthTSyn_HasComCtrlPortIndEndIdxOfComCtrlEthIfCtrl()                                         (TRUE != FALSE)
#define EthTSyn_HasComCtrlPortIndStartIdxOfComCtrlEthIfCtrl()                                       (TRUE != FALSE)
#define EthTSyn_HasDestinationMacIndEndIdxOfComCtrlEthIfCtrl()                                      (TRUE != FALSE)
#define EthTSyn_HasDestinationMacIndStartIdxOfComCtrlEthIfCtrl()                                    (TRUE != FALSE)
#define EthTSyn_HasEthIfCtrlIdxOfComCtrlEthIfCtrl()                                                 (TRUE != FALSE)
#define EthTSyn_HasComCtrlEthIfCtrlDyn()                                                            (EthTSyn_GetComCtrlEthIfCtrlDynOfPCConfig() != NULL_PTR)
#define EthTSyn_HasClockIdOfComCtrlEthIfCtrlDyn()                                                   (TRUE != FALSE)
#define EthTSyn_HasLinkStateActiveOfComCtrlEthIfCtrlDyn()                                           (TRUE != FALSE)
#define EthTSyn_HasTxActiveOfComCtrlEthIfCtrlDyn()                                                  (TRUE != FALSE)
#define EthTSyn_HasComCtrlPhysPort()                                                                (EthTSyn_GetComCtrlPhysPortOfPCConfig() != NULL_PTR)
#define EthTSyn_HasAlwaysAsCapableOfComCtrlPhysPort()                                               (TRUE != FALSE)
#define EthTSyn_HasDebounceTimerInitOfComCtrlPhysPort()                                             (TRUE != FALSE)
#define EthTSyn_HasInitialPdelayNsOfComCtrlPhysPort()                                               (TRUE != FALSE)
#define EthTSyn_HasUseStaticPdelayOfComCtrlPhysPort()                                               (TRUE != FALSE)
#define EthTSyn_HasComCtrlPhysPortDyn()                                                             (EthTSyn_GetComCtrlPhysPortDynOfPCConfig() != NULL_PTR)
#define EthTSyn_HasAsCapableOfComCtrlPhysPortDyn()                                                  (TRUE != FALSE)
#define EthTSyn_HasDebounceTimerOfComCtrlPhysPortDyn()                                              (TRUE != FALSE)
#define EthTSyn_HasPdelayValueNsOfComCtrlPhysPortDyn()                                              (TRUE != FALSE)
#define EthTSyn_HasComCtrlPort()                                                                    (EthTSyn_GetComCtrlPortOfPCConfig() != NULL_PTR)
#define EthTSyn_HasAnnounceSendSmIdxOfComCtrlPort()                                                 (TRUE != FALSE)
#define EthTSyn_HasAnnounceSendSmUsedOfComCtrlPort()                                                (TRUE != FALSE)
#define EthTSyn_HasComCtrlEthIfCtrlIdxOfComCtrlPort()                                               (TRUE != FALSE)
#define EthTSyn_HasComCtrlPhysPortIdxOfComCtrlPort()                                                (TRUE != FALSE)
#define EthTSyn_HasComCtrlTimeDomainIdxOfComCtrlPort()                                              (TRUE != FALSE)
#define EthTSyn_HasFramePrioOfComCtrlPort()                                                         (TRUE != FALSE)
#define EthTSyn_HasNumberOfComCtrlPort()                                                            (TRUE != FALSE)
#define EthTSyn_HasPdReqSmIdxOfComCtrlPort()                                                        (TRUE != FALSE)
#define EthTSyn_HasPdReqSmUsedOfComCtrlPort()                                                       (TRUE != FALSE)
#define EthTSyn_HasPdRespSmIdxOfComCtrlPort()                                                       (TRUE != FALSE)
#define EthTSyn_HasPdRespSmUsedOfComCtrlPort()                                                      (TRUE != FALSE)
#define EthTSyn_HasPortParamStatsDynIdxOfComCtrlPort()                                              (TRUE != FALSE)
#define EthTSyn_HasPortParamStatsDynUsedOfComCtrlPort()                                             (TRUE != FALSE)
#define EthTSyn_HasPortSyncSendSmIdxOfComCtrlPort()                                                 (TRUE != FALSE)
#define EthTSyn_HasPortSyncSendSmUsedOfComCtrlPort()                                                (TRUE != FALSE)
#define EthTSyn_HasSlaveRxDataHandlerIdxOfComCtrlPort()                                             (TRUE != FALSE)
#define EthTSyn_HasSlaveRxDataHandlerUsedOfComCtrlPort()                                            (TRUE != FALSE)
#define EthTSyn_HasSyncSendSmIdxOfComCtrlPort()                                                     (TRUE != FALSE)
#define EthTSyn_HasSyncSendSmUsedOfComCtrlPort()                                                    (TRUE != FALSE)
#define EthTSyn_HasComCtrlPortInd()                                                                 (EthTSyn_GetComCtrlPortIndOfPCConfig() != NULL_PTR)
#define EthTSyn_HasComCtrlTimeDomain()                                                              (EthTSyn_GetComCtrlTimeDomainOfPCConfig() != NULL_PTR)
#define EthTSyn_HasComCtrlPortEndIdxOfComCtrlTimeDomain()                                           (TRUE != FALSE)
#define EthTSyn_HasComCtrlPortStartIdxOfComCtrlTimeDomain()                                         (TRUE != FALSE)
#define EthTSyn_HasDestinationMacIdxOfComCtrlTimeDomain()                                           (TRUE != FALSE)
#define EthTSyn_HasIdOfComCtrlTimeDomain()                                                          (TRUE != FALSE)
#define EthTSyn_HasOffsetTimeDomainEndIdxOfComCtrlTimeDomain()                                      (TRUE != FALSE)
#define EthTSyn_HasOffsetTimeDomainStartIdxOfComCtrlTimeDomain()                                    (TRUE != FALSE)
#define EthTSyn_HasOffsetTimeDomainUsedOfComCtrlTimeDomain()                                        (TRUE != FALSE)
#define EthTSyn_HasSynchronizedTimeBaseIdOfComCtrlTimeDomain()                                      (TRUE != FALSE)
#define EthTSyn_HasCrcHndl()                                                                        (EthTSyn_GetCrcHndlOfPCConfig() != NULL_PTR)
#define EthTSyn_HasFupDataIdListEndIdxOfCrcHndl()                                                   (TRUE != FALSE)
#define EthTSyn_HasFupDataIdListStartIdxOfCrcHndl()                                                 (TRUE != FALSE)
#define EthTSyn_HasDestinationMac()                                                                 (EthTSyn_GetDestinationMacOfPCConfig() != NULL_PTR)
#define EthTSyn_HasByte0OfDestinationMac()                                                          (TRUE != FALSE)
#define EthTSyn_HasByte1OfDestinationMac()                                                          (TRUE != FALSE)
#define EthTSyn_HasByte2OfDestinationMac()                                                          (TRUE != FALSE)
#define EthTSyn_HasByte3OfDestinationMac()                                                          (TRUE != FALSE)
#define EthTSyn_HasByte4OfDestinationMac()                                                          (TRUE != FALSE)
#define EthTSyn_HasByte5OfDestinationMac()                                                          (TRUE != FALSE)
#define EthTSyn_HasDestinationMacInd()                                                              (EthTSyn_GetDestinationMacIndOfPCConfig() != NULL_PTR)
#define EthTSyn_HasFupDataIdList()                                                                  (EthTSyn_GetFupDataIdListOfPCConfig() != NULL_PTR)
#define EthTSyn_HasFupRxHandler()                                                                   (EthTSyn_GetFupRxHandlerOfPCConfig() != NULL_PTR)
#define EthTSyn_HasComCtrlPortExternalIdxOfFupRxHandler()                                           (TRUE != FALSE)
#define EthTSyn_HasCrcFlagsRxValidatedOfFupRxHandler()                                              (TRUE != FALSE)
#define EthTSyn_HasCrcHndlIdxOfFupRxHandler()                                                       (TRUE != FALSE)
#define EthTSyn_HasCrcHndlUsedOfFupRxHandler()                                                      (TRUE != FALSE)
#define EthTSyn_HasFupCorrFieldThresholdNsOfFupRxHandler()                                          (TRUE != FALSE)
#define EthTSyn_HasRxCrcValidatedOfFupRxHandler()                                                   (TRUE != FALSE)
#define EthTSyn_HasTimeValidationEnabledOfFupRxHandler()                                            (TRUE != FALSE)
#define EthTSyn_HasMsgSentCbkBuf()                                                                  (EthTSyn_GetMsgSentCbkBufOfPCConfig() != NULL_PTR)
#define EthTSyn_HasOffsetTimeDomain()                                                               (EthTSyn_GetOffsetTimeDomainOfPCConfig() != NULL_PTR)
#define EthTSyn_HasIdOfOffsetTimeDomain()                                                           (TRUE != FALSE)
#define EthTSyn_HasSynchronizedTimeBaseIdOfOffsetTimeDomain()                                       (TRUE != FALSE)
#define EthTSyn_HasPdReqSm()                                                                        (EthTSyn_GetPdReqSmOfPCConfig() != NULL_PTR)
#define EthTSyn_HasAverageWeightOfPdReqSm()                                                         (TRUE != FALSE)
#define EthTSyn_HasComCtrlPortIdxOfPdReqSm()                                                        (TRUE != FALSE)
#define EthTSyn_HasLogMsgIntervalOfPdReqSm()                                                        (TRUE != FALSE)
#define EthTSyn_HasMaxLostResponsesOfPdReqSm()                                                      (TRUE != FALSE)
#define EthTSyn_HasPdReqPeriodOfPdReqSm()                                                           (TRUE != FALSE)
#define EthTSyn_HasPdRespTimeoutOfPdReqSm()                                                         (TRUE != FALSE)
#define EthTSyn_HasPdThresholdOfPdReqSm()                                                           (TRUE != FALSE)
#define EthTSyn_HasTimeValidationEnabledOfPdReqSm()                                                 (TRUE != FALSE)
#define EthTSyn_HasTxConfContextIdxOfPdReqSm()                                                      (TRUE != FALSE)
#define EthTSyn_HasPdReqSmDyn()                                                                     (EthTSyn_GetPdReqSmDynOfPCConfig() != NULL_PTR)
#define EthTSyn_HasFirstPdelayOfPdReqSmDyn()                                                        (TRUE != FALSE)
#define EthTSyn_HasLostResponseCntOfPdReqSmDyn()                                                    (TRUE != FALSE)
#define EthTSyn_HasRefGlobalTimeOfPdReqSmDyn()                                                      (TRUE != FALSE)
#define EthTSyn_HasRefLocalTimeOfPdReqSmDyn()                                                       (TRUE != FALSE)
#define EthTSyn_HasRespTimeoutCntOfPdReqSmDyn()                                                     (TRUE != FALSE)
#define EthTSyn_HasSequenceIdOfPdReqSmDyn()                                                         (TRUE != FALSE)
#define EthTSyn_HasSmResetRequestedOfPdReqSmDyn()                                                   (TRUE != FALSE)
#define EthTSyn_HasStateOfPdReqSmDyn()                                                              (TRUE != FALSE)
#define EthTSyn_HasTxIntervalCntOfPdReqSmDyn()                                                      (TRUE != FALSE)
#define EthTSyn_HasPdReqTrcvDyn()                                                                   (EthTSyn_GetPdReqTrcvDynOfPCConfig() != NULL_PTR)
#define EthTSyn_HasPdReqEgrTsMgmtOfPdReqTrcvDyn()                                                   (TRUE != FALSE)
#define EthTSyn_HasPdReqEgrTsProvidedOfPdReqTrcvDyn()                                               (TRUE != FALSE)
#define EthTSyn_HasPdRespIngrTsMgmtOfPdReqTrcvDyn()                                                 (TRUE != FALSE)
#define EthTSyn_HasReqReceivedTsOfPdReqTrcvDyn()                                                    (TRUE != FALSE)
#define EthTSyn_HasRespClockIdOfPdReqTrcvDyn()                                                      (TRUE != FALSE)
#define EthTSyn_HasRespOriginTsOfPdReqTrcvDyn()                                                     (TRUE != FALSE)
#define EthTSyn_HasRespPortNumOfPdReqTrcvDyn()                                                      (TRUE != FALSE)
#define EthTSyn_HasStateOfPdReqTrcvDyn()                                                            (TRUE != FALSE)
#define EthTSyn_HasPdRespSm()                                                                       (EthTSyn_GetPdRespSmOfPCConfig() != NULL_PTR)
#define EthTSyn_HasComCtrlPortIdxOfPdRespSm()                                                       (TRUE != FALSE)
#define EthTSyn_HasTimeValidationEnabledOfPdRespSm()                                                (TRUE != FALSE)
#define EthTSyn_HasTxConfContextIdxOfPdRespSm()                                                     (TRUE != FALSE)
#define EthTSyn_HasPdRespSmDyn()                                                                    (EthTSyn_GetPdRespSmDynOfPCConfig() != NULL_PTR)
#define EthTSyn_HasPdReqRcvdTsOfPdRespSmDyn()                                                       (TRUE != FALSE)
#define EthTSyn_HasPdRespOrgTsOfPdRespSmDyn()                                                       (TRUE != FALSE)
#define EthTSyn_HasRequestorClockIdOfPdRespSmDyn()                                                  (TRUE != FALSE)
#define EthTSyn_HasRequestorPortNumOfPdRespSmDyn()                                                  (TRUE != FALSE)
#define EthTSyn_HasSequenceIdOfPdRespSmDyn()                                                        (TRUE != FALSE)
#define EthTSyn_HasSmResetRequestedOfPdRespSmDyn()                                                  (TRUE != FALSE)
#define EthTSyn_HasStateOfPdRespSmDyn()                                                             (TRUE != FALSE)
#define EthTSyn_HasPortParamStatsDyn()                                                              (EthTSyn_GetPortParamStatsDynOfPCConfig() != NULL_PTR)
#define EthTSyn_HasPdLostRespExceededCountOfPortParamStatsDyn()                                     (TRUE != FALSE)
#define EthTSyn_HasRxAnnounceCountOfPortParamStatsDyn()                                             (TRUE != FALSE)
#define EthTSyn_HasRxDiscardCountOfPortParamStatsDyn()                                              (TRUE != FALSE)
#define EthTSyn_HasRxFupCountOfPortParamStatsDyn()                                                  (TRUE != FALSE)
#define EthTSyn_HasRxPdReqCountOfPortParamStatsDyn()                                                (TRUE != FALSE)
#define EthTSyn_HasRxPdRespCountOfPortParamStatsDyn()                                               (TRUE != FALSE)
#define EthTSyn_HasRxPdRespFupCountOfPortParamStatsDyn()                                            (TRUE != FALSE)
#define EthTSyn_HasRxSyncCountOfPortParamStatsDyn()                                                 (TRUE != FALSE)
#define EthTSyn_HasTxAnnounceCountOfPortParamStatsDyn()                                             (TRUE != FALSE)
#define EthTSyn_HasTxFupCountOfPortParamStatsDyn()                                                  (TRUE != FALSE)
#define EthTSyn_HasTxPdReqCountOfPortParamStatsDyn()                                                (TRUE != FALSE)
#define EthTSyn_HasTxPdRespCountOfPortParamStatsDyn()                                               (TRUE != FALSE)
#define EthTSyn_HasTxPdRespFupCountOfPortParamStatsDyn()                                            (TRUE != FALSE)
#define EthTSyn_HasTxSyncCountOfPortParamStatsDyn()                                                 (TRUE != FALSE)
#define EthTSyn_HasPortSyncSendSm()                                                                 (EthTSyn_GetPortSyncSendSmOfPCConfig() != NULL_PTR)
#define EthTSyn_HasComCtrlPortIdxOfPortSyncSendSm()                                                 (TRUE != FALSE)
#define EthTSyn_HasFollowUpSentCbkPtrOfPortSyncSendSm()                                             (TRUE != FALSE)
#define EthTSyn_HasMsgSentCbkBufEndIdxOfPortSyncSendSm()                                            (TRUE != FALSE)
#define EthTSyn_HasMsgSentCbkBufLengthOfPortSyncSendSm()                                            (TRUE != FALSE)
#define EthTSyn_HasMsgSentCbkBufStartIdxOfPortSyncSendSm()                                          (TRUE != FALSE)
#define EthTSyn_HasMsgSentCbkBufUsedOfPortSyncSendSm()                                              (TRUE != FALSE)
#define EthTSyn_HasSyncSentCbkPtrOfPortSyncSendSm()                                                 (TRUE != FALSE)
#define EthTSyn_HasTimeValidationEnabledOfPortSyncSendSm()                                          (TRUE != FALSE)
#define EthTSyn_HasTxConfContextIdxOfPortSyncSendSm()                                               (TRUE != FALSE)
#define EthTSyn_HasPortSyncSendSmDyn()                                                              (EthTSyn_GetPortSyncSendSmDynOfPCConfig() != NULL_PTR)
#define EthTSyn_HasEgrTsInfoOfPortSyncSendSmDyn()                                                   (TRUE != FALSE)
#define EthTSyn_HasStateOfPortSyncSendSmDyn()                                                       (TRUE != FALSE)
#define EthTSyn_HasRateMeas()                                                                       (EthTSyn_GetRateMeasOfPCConfig() != NULL_PTR)
#define EthTSyn_HasMaxOutOfSyncCntOfRateMeas()                                                      (TRUE != FALSE)
#define EthTSyn_HasNrSyncCyclesForOfsCorrOfRateMeas()                                               (TRUE != FALSE)
#define EthTSyn_HasOfsJumpCorrThresholdNsOfRateMeas()                                               (TRUE != FALSE)
#define EthTSyn_HasRateMeasBufEndIdxOfRateMeas()                                                    (TRUE != FALSE)
#define EthTSyn_HasRateMeasBufLengthOfRateMeas()                                                    (TRUE != FALSE)
#define EthTSyn_HasRateMeasBufStartIdxOfRateMeas()                                                  (TRUE != FALSE)
#define EthTSyn_HasRateRatioMaxOfRateMeas()                                                         (TRUE != FALSE)
#define EthTSyn_HasRateRatioMinOfRateMeas()                                                         (TRUE != FALSE)
#define EthTSyn_HasSyncPrecisionLimitNsOfRateMeas()                                                 (TRUE != FALSE)
#define EthTSyn_HasUseInitialOffsetCorrectionOfRateMeas()                                           (TRUE != FALSE)
#define EthTSyn_HasRateMeasBuf()                                                                    (EthTSyn_GetRateMeasBufOfPCConfig() != NULL_PTR)
#define EthTSyn_HasAccumulatedMasterTimeDiffOfRateMeasBuf()                                         (TRUE != FALSE)
#define EthTSyn_HasAccumulatedSwtTimeDiffOfRateMeasBuf()                                            (TRUE != FALSE)
#define EthTSyn_HasActiveNrOfSyncCyclesOfRateMeasBuf()                                              (TRUE != FALSE)
#define EthTSyn_HasActiveOfRateMeasBuf()                                                            (TRUE != FALSE)
#define EthTSyn_HasRateMeasDyn()                                                                    (EthTSyn_GetRateMeasDynOfPCConfig() != NULL_PTR)
#define EthTSyn_HasCurrTsInfoOfRateMeasDyn()                                                        (TRUE != FALSE)
#define EthTSyn_HasLastCorrectedOffsetNsOfRateMeasDyn()                                             (TRUE != FALSE)
#define EthTSyn_HasOutOfSyncCntOfRateMeasDyn()                                                      (TRUE != FALSE)
#define EthTSyn_HasPrevTsInfoOfRateMeasDyn()                                                        (TRUE != FALSE)
#define EthTSyn_HasStateOfRateMeasDyn()                                                             (TRUE != FALSE)
#define EthTSyn_HasSyncCycleCounterOfRateMeasDyn()                                                  (TRUE != FALSE)
#define EthTSyn_HasSyncCycleCounterRestartedOfRateMeasDyn()                                         (TRUE != FALSE)
#define EthTSyn_HasWasSyncReachedOfRateMeasDyn()                                                    (TRUE != FALSE)
#define EthTSyn_HasSiteSyncSyncTx()                                                                 (EthTSyn_GetSiteSyncSyncTxOfPCConfig() != NULL_PTR)
#define EthTSyn_HasBridgeTxMasterPortEndIdxOfSiteSyncSyncTx()                                       (TRUE != FALSE)
#define EthTSyn_HasBridgeTxMasterPortStartIdxOfSiteSyncSyncTx()                                     (TRUE != FALSE)
#define EthTSyn_HasNumMsgFwdRetryOfSiteSyncSyncTx()                                                 (TRUE != FALSE)
#define EthTSyn_HasSiteSyncSyncTxDyn()                                                              (EthTSyn_GetSiteSyncSyncTxDynOfPCConfig() != NULL_PTR)
#define EthTSyn_HasFwdRetryCntOfSiteSyncSyncTxDyn()                                                 (TRUE != FALSE)
#define EthTSyn_HasLastMsgHdrOfSiteSyncSyncTxDyn()                                                  (TRUE != FALSE)
#define EthTSyn_HasLastSyncRefTsMgmtOfSiteSyncSyncTxDyn()                                           (TRUE != FALSE)
#define EthTSyn_HasSlavePdelayNsOfSiteSyncSyncTxDyn()                                               (TRUE != FALSE)
#define EthTSyn_HasStateOfSiteSyncSyncTxDyn()                                                       (TRUE != FALSE)
#define EthTSyn_HasSizeOfAnnounceRcvSm()                                                            (TRUE != FALSE)
#define EthTSyn_HasSizeOfAnnounceRcvSmDyn()                                                         (TRUE != FALSE)
#define EthTSyn_HasSizeOfAnnounceSendSm()                                                           (TRUE != FALSE)
#define EthTSyn_HasSizeOfAnnounceSendSmDyn()                                                        (TRUE != FALSE)
#define EthTSyn_HasSizeOfBridgeTxMasterPort()                                                       (TRUE != FALSE)
#define EthTSyn_HasSizeOfBridgeTxMasterPortDyn()                                                    (TRUE != FALSE)
#define EthTSyn_HasSizeOfComCtrlEthIfCtrl()                                                         (TRUE != FALSE)
#define EthTSyn_HasSizeOfComCtrlEthIfCtrlDyn()                                                      (TRUE != FALSE)
#define EthTSyn_HasSizeOfComCtrlPhysPort()                                                          (TRUE != FALSE)
#define EthTSyn_HasSizeOfComCtrlPhysPortDyn()                                                       (TRUE != FALSE)
#define EthTSyn_HasSizeOfComCtrlPort()                                                              (TRUE != FALSE)
#define EthTSyn_HasSizeOfComCtrlPortInd()                                                           (TRUE != FALSE)
#define EthTSyn_HasSizeOfComCtrlTimeDomain()                                                        (TRUE != FALSE)
#define EthTSyn_HasSizeOfCrcHndl()                                                                  (TRUE != FALSE)
#define EthTSyn_HasSizeOfDestinationMac()                                                           (TRUE != FALSE)
#define EthTSyn_HasSizeOfDestinationMacInd()                                                        (TRUE != FALSE)
#define EthTSyn_HasSizeOfFupDataIdList()                                                            (TRUE != FALSE)
#define EthTSyn_HasSizeOfFupRxHandler()                                                             (TRUE != FALSE)
#define EthTSyn_HasSizeOfMsgSentCbkBuf()                                                            (TRUE != FALSE)
#define EthTSyn_HasSizeOfOffsetTimeDomain()                                                         (TRUE != FALSE)
#define EthTSyn_HasSizeOfPdReqSm()                                                                  (TRUE != FALSE)
#define EthTSyn_HasSizeOfPdReqSmDyn()                                                               (TRUE != FALSE)
#define EthTSyn_HasSizeOfPdReqTrcvDyn()                                                             (TRUE != FALSE)
#define EthTSyn_HasSizeOfPdRespSm()                                                                 (TRUE != FALSE)
#define EthTSyn_HasSizeOfPdRespSmDyn()                                                              (TRUE != FALSE)
#define EthTSyn_HasSizeOfPortParamStatsDyn()                                                        (TRUE != FALSE)
#define EthTSyn_HasSizeOfPortSyncSendSm()                                                           (TRUE != FALSE)
#define EthTSyn_HasSizeOfPortSyncSendSmDyn()                                                        (TRUE != FALSE)
#define EthTSyn_HasSizeOfRateMeas()                                                                 (TRUE != FALSE)
#define EthTSyn_HasSizeOfRateMeasBuf()                                                              (TRUE != FALSE)
#define EthTSyn_HasSizeOfRateMeasDyn()                                                              (TRUE != FALSE)
#define EthTSyn_HasSizeOfSiteSyncSyncTx()                                                           (TRUE != FALSE)
#define EthTSyn_HasSizeOfSiteSyncSyncTxDyn()                                                        (TRUE != FALSE)
#define EthTSyn_HasSizeOfSlaveRxData()                                                              (TRUE != FALSE)
#define EthTSyn_HasSizeOfSlaveRxDataHandler()                                                       (TRUE != FALSE)
#define EthTSyn_HasSizeOfSlaveRxMasterClockIdDyn()                                                  (TRUE != FALSE)
#define EthTSyn_HasSizeOfSlaveRxSrcPortIdCheckClockId()                                             (TRUE != FALSE)
#define EthTSyn_HasSizeOfSlaveSwitchIdxList()                                                       (TRUE != FALSE)
#define EthTSyn_HasSizeOfSwtTimeSyncSm()                                                            (TRUE != FALSE)
#define EthTSyn_HasSizeOfSwtTimeSyncSmDyn()                                                         (TRUE != FALSE)
#define EthTSyn_HasSizeOfSyncRcvSm()                                                                (TRUE != FALSE)
#define EthTSyn_HasSizeOfSyncRcvSmDyn()                                                             (TRUE != FALSE)
#define EthTSyn_HasSizeOfSyncSendSm()                                                               (TRUE != FALSE)
#define EthTSyn_HasSizeOfSyncSendSmDyn()                                                            (TRUE != FALSE)
#define EthTSyn_HasSizeOfTimeBaseUpdateCounter()                                                    (TRUE != FALSE)
#define EthTSyn_HasSizeOfTimeBaseUpdateCounterDyn()                                                 (TRUE != FALSE)
#define EthTSyn_HasSizeOfTxConfContext()                                                            (TRUE != FALSE)
#define EthTSyn_HasSizeOfTxConfContextDyn()                                                         (TRUE != FALSE)
#define EthTSyn_HasSlaveRxData()                                                                    (EthTSyn_GetSlaveRxDataOfPCConfig() != NULL_PTR)
#define EthTSyn_HasAnnounceRcvSmIdxOfSlaveRxData()                                                  (TRUE != FALSE)
#define EthTSyn_HasAnnounceRcvSmUsedOfSlaveRxData()                                                 (TRUE != FALSE)
#define EthTSyn_HasSlaveRxMasterClockIdDynIdxOfSlaveRxData()                                        (TRUE != FALSE)
#define EthTSyn_HasSlaveRxMasterClockIdDynUsedOfSlaveRxData()                                       (TRUE != FALSE)
#define EthTSyn_HasSlaveRxSrcPortIdCheckClockIdIdxOfSlaveRxData()                                   (TRUE != FALSE)
#define EthTSyn_HasSlaveRxSrcPortIdCheckClockIdUsedOfSlaveRxData()                                  (TRUE != FALSE)
#define EthTSyn_HasSyncRcvSmIdxOfSlaveRxData()                                                      (TRUE != FALSE)
#define EthTSyn_HasSlaveRxDataHandler()                                                             (EthTSyn_GetSlaveRxDataHandlerOfPCConfig() != NULL_PTR)
#define EthTSyn_HasComCtrlPortIdxOfSlaveRxDataHandler()                                             (TRUE != FALSE)
#define EthTSyn_HasSlaveRxDataExternalIdxOfSlaveRxDataHandler()                                     (TRUE != FALSE)
#define EthTSyn_HasSlaveRxMasterClockIdDyn()                                                        (EthTSyn_GetSlaveRxMasterClockIdDynOfPCConfig() != NULL_PTR)
#define EthTSyn_HasValidMasterClockIdOfSlaveRxMasterClockIdDyn()                                    (TRUE != FALSE)
#define EthTSyn_HasValidMasterSetOfSlaveRxMasterClockIdDyn()                                        (TRUE != FALSE)
#define EthTSyn_HasSlaveRxSrcPortIdCheckClockId()                                                   (EthTSyn_GetSlaveRxSrcPortIdCheckClockIdOfPCConfig() != NULL_PTR)
#define EthTSyn_HasSlaveSwitchIdxList()                                                             (EthTSyn_GetSlaveSwitchIdxListOfPCConfig() != NULL_PTR)
#define EthTSyn_HasSwtTimeSyncSm()                                                                  (EthTSyn_GetSwtTimeSyncSmOfPCConfig() != NULL_PTR)
#define EthTSyn_HasApplyRateRatioToSlaveSwitchesOfSwtTimeSyncSm()                                   (TRUE != FALSE)
#define EthTSyn_HasEthIfSwitchIdxOfSwtTimeSyncSm()                                                  (TRUE != FALSE)
#define EthTSyn_HasRateMeasIdxOfSwtTimeSyncSm()                                                     (TRUE != FALSE)
#define EthTSyn_HasSlaveSwitchIdxListEndIdxOfSwtTimeSyncSm()                                        (TRUE != FALSE)
#define EthTSyn_HasSlaveSwitchIdxListStartIdxOfSwtTimeSyncSm()                                      (TRUE != FALSE)
#define EthTSyn_HasSlaveSwitchIdxListUsedOfSwtTimeSyncSm()                                          (TRUE != FALSE)
#define EthTSyn_HasSwtSyncStateChgFctPtrOfSwtTimeSyncSm()                                           (TRUE != FALSE)
#define EthTSyn_HasSyncEventTimeoutOfSwtTimeSyncSm()                                                (TRUE != FALSE)
#define EthTSyn_HasSwtTimeSyncSmDyn()                                                               (EthTSyn_GetSwtTimeSyncSmDynOfPCConfig() != NULL_PTR)
#define EthTSyn_HasStateOfSwtTimeSyncSmDyn()                                                        (TRUE != FALSE)
#define EthTSyn_HasSwtSyncStateOfSwtTimeSyncSmDyn()                                                 (TRUE != FALSE)
#define EthTSyn_HasSyncEventTimeoutCntOfSwtTimeSyncSmDyn()                                          (TRUE != FALSE)
#define EthTSyn_HasTimeStampInfoOfSwtTimeSyncSmDyn()                                                (TRUE != FALSE)
#define EthTSyn_HasSyncRcvSm()                                                                      (EthTSyn_GetSyncRcvSmOfPCConfig() != NULL_PTR)
#define EthTSyn_HasFollowUpRxTimeoutOfSyncRcvSm()                                                   (TRUE != FALSE)
#define EthTSyn_HasFupRxHandlerIdxOfSyncRcvSm()                                                     (TRUE != FALSE)
#define EthTSyn_HasPortParamStatsDynIdxOfSyncRcvSm()                                                (TRUE != FALSE)
#define EthTSyn_HasPortParamStatsDynUsedOfSyncRcvSm()                                               (TRUE != FALSE)
#define EthTSyn_HasSyncRcvSmDyn()                                                                   (EthTSyn_GetSyncRcvSmDynOfPCConfig() != NULL_PTR)
#define EthTSyn_HasAnySyncReceivedOfSyncRcvSmDyn()                                                  (TRUE != FALSE)
#define EthTSyn_HasFupRxTimeoutCntOfSyncRcvSmDyn()                                                  (TRUE != FALSE)
#define EthTSyn_HasResetRequestedOfSyncRcvSmDyn()                                                   (TRUE != FALSE)
#define EthTSyn_HasStateOfSyncRcvSmDyn()                                                            (TRUE != FALSE)
#define EthTSyn_HasSyncRxTimeInfoOfSyncRcvSmDyn()                                                   (TRUE != FALSE)
#define EthTSyn_HasSyncSequenceIdOfSyncRcvSmDyn()                                                   (TRUE != FALSE)
#define EthTSyn_HasSyncSrcClockIdOfSyncRcvSmDyn()                                                   (TRUE != FALSE)
#define EthTSyn_HasSyncSrcPortNumOfSyncRcvSmDyn()                                                   (TRUE != FALSE)
#define EthTSyn_HasSyncSendSm()                                                                     (EthTSyn_GetSyncSendSmOfPCConfig() != NULL_PTR)
#define EthTSyn_HasCrcHndlIdxOfSyncSendSm()                                                         (TRUE != FALSE)
#define EthTSyn_HasCrcHndlUsedOfSyncSendSm()                                                        (TRUE != FALSE)
#define EthTSyn_HasCrcTimeFlagsOfSyncSendSm()                                                       (TRUE != FALSE)
#define EthTSyn_HasCyclicMsgResumeCntOfSyncSendSm()                                                 (TRUE != FALSE)
#define EthTSyn_HasFupTxLenOfSyncSendSm()                                                           (TRUE != FALSE)
#define EthTSyn_HasImmediateTimeSyncOfSyncSendSm()                                                  (TRUE != FALSE)
#define EthTSyn_HasPortSyncSendSmIdxOfSyncSendSm()                                                  (TRUE != FALSE)
#define EthTSyn_HasSyncLogMsgIntervalOfSyncSendSm()                                                 (TRUE != FALSE)
#define EthTSyn_HasSyncSendIntervalOfSyncSendSm()                                                   (TRUE != FALSE)
#define EthTSyn_HasTimeBaseUpdateCounterIdxOfSyncSendSm()                                           (TRUE != FALSE)
#define EthTSyn_HasTimeBaseUpdateCounterUsedOfSyncSendSm()                                          (TRUE != FALSE)
#define EthTSyn_HasTxCrcSecuredOfSyncSendSm()                                                       (TRUE != FALSE)
#define EthTSyn_HasSyncSendSmDyn()                                                                  (EthTSyn_GetSyncSendSmDynOfPCConfig() != NULL_PTR)
#define EthTSyn_HasFupCorrFieldOfSyncSendSmDyn()                                                    (TRUE != FALSE)
#define EthTSyn_HasPreciseOriginTsOfSyncSendSmDyn()                                                 (TRUE != FALSE)
#define EthTSyn_HasSequenceIdOfSyncSendSmDyn()                                                      (TRUE != FALSE)
#define EthTSyn_HasSmResetRequestedOfSyncSendSmDyn()                                                (TRUE != FALSE)
#define EthTSyn_HasStateOfSyncSendSmDyn()                                                           (TRUE != FALSE)
#define EthTSyn_HasSyncTxInfoOfSyncSendSmDyn()                                                      (TRUE != FALSE)
#define EthTSyn_HasTxIntervalCntOfSyncSendSmDyn()                                                   (TRUE != FALSE)
#define EthTSyn_HasTimeBaseUpdateCounter()                                                          (EthTSyn_GetTimeBaseUpdateCounterOfPCConfig() != NULL_PTR)
#define EthTSyn_HasSynchronizedTimeBaseIdOfTimeBaseUpdateCounter()                                  (TRUE != FALSE)
#define EthTSyn_HasTimeBaseUpdateCounterDyn()                                                       (EthTSyn_GetTimeBaseUpdateCounterDynOfPCConfig() != NULL_PTR)
#define EthTSyn_HasUpdatedOfTimeBaseUpdateCounterDyn()                                              (TRUE != FALSE)
#define EthTSyn_HasValueOfTimeBaseUpdateCounterDyn()                                                (TRUE != FALSE)
#define EthTSyn_HasTxConfContext()                                                                  (EthTSyn_GetTxConfContextOfPCConfig() != NULL_PTR)
#define EthTSyn_HasComCtrlPortIdxOfTxConfContext()                                                  (TRUE != FALSE)
#define EthTSyn_HasTxSmIdxOfTxConfContext()                                                         (TRUE != FALSE)
#define EthTSyn_HasTxSmOfTxConfContext()                                                            (TRUE != FALSE)
#define EthTSyn_HasTxConfContextDyn()                                                               (EthTSyn_GetTxConfContextDynOfPCConfig() != NULL_PTR)
#define EthTSyn_HasActiveOfTxConfContextDyn()                                                       (TRUE != FALSE)
#define EthTSyn_HasBufferIdxOfTxConfContextDyn()                                                    (TRUE != FALSE)
#define EthTSyn_HasTxConfContextNextActiveIdxOfTxConfContextDyn()                                   (TRUE != FALSE)
#define EthTSyn_HasTxConfContextPrevActiveIdxOfTxConfContextDyn()                                   (TRUE != FALSE)
#define EthTSyn_HasTxConfContextDynActiveFirstIdx()                                                 (EthTSyn_GetTxConfContextDynActiveFirstIdxOfPCConfig() != NULL_PTR)
#define EthTSyn_HasTxConfContextDynActiveLastIdx()                                                  (EthTSyn_GetTxConfContextDynActiveLastIdxOfPCConfig() != NULL_PTR)
#define EthTSyn_HasPCConfig()                                                                       (TRUE != FALSE)
#define EthTSyn_HasAnnounceRcvSmDynOfPCConfig()                                                     (TRUE != FALSE)
#define EthTSyn_HasAnnounceRcvSmOfPCConfig()                                                        (TRUE != FALSE)
#define EthTSyn_HasAnnounceSendSmDynOfPCConfig()                                                    (TRUE != FALSE)
#define EthTSyn_HasAnnounceSendSmOfPCConfig()                                                       (TRUE != FALSE)
#define EthTSyn_HasBridgeTxMasterPortDynOfPCConfig()                                                (TRUE != FALSE)
#define EthTSyn_HasBridgeTxMasterPortOfPCConfig()                                                   (TRUE != FALSE)
#define EthTSyn_HasComCtrlEthIfCtrlDynOfPCConfig()                                                  (TRUE != FALSE)
#define EthTSyn_HasComCtrlEthIfCtrlOfPCConfig()                                                     (TRUE != FALSE)
#define EthTSyn_HasComCtrlPhysPortDynOfPCConfig()                                                   (TRUE != FALSE)
#define EthTSyn_HasComCtrlPhysPortOfPCConfig()                                                      (TRUE != FALSE)
#define EthTSyn_HasComCtrlPortIndOfPCConfig()                                                       (TRUE != FALSE)
#define EthTSyn_HasComCtrlPortOfPCConfig()                                                          (TRUE != FALSE)
#define EthTSyn_HasComCtrlTimeDomainOfPCConfig()                                                    (TRUE != FALSE)
#define EthTSyn_HasCrcHndlOfPCConfig()                                                              (TRUE != FALSE)
#define EthTSyn_HasDestinationMacIndOfPCConfig()                                                    (TRUE != FALSE)
#define EthTSyn_HasDestinationMacOfPCConfig()                                                       (TRUE != FALSE)
#define EthTSyn_HasFupDataIdListOfPCConfig()                                                        (TRUE != FALSE)
#define EthTSyn_HasFupRxHandlerOfPCConfig()                                                         (TRUE != FALSE)
#define EthTSyn_HasMsgSentCbkBufOfPCConfig()                                                        (TRUE != FALSE)
#define EthTSyn_HasOffsetTimeDomainOfPCConfig()                                                     (TRUE != FALSE)
#define EthTSyn_HasPdReqSmDynOfPCConfig()                                                           (TRUE != FALSE)
#define EthTSyn_HasPdReqSmOfPCConfig()                                                              (TRUE != FALSE)
#define EthTSyn_HasPdReqTrcvDynOfPCConfig()                                                         (TRUE != FALSE)
#define EthTSyn_HasPdRespSmDynOfPCConfig()                                                          (TRUE != FALSE)
#define EthTSyn_HasPdRespSmOfPCConfig()                                                             (TRUE != FALSE)
#define EthTSyn_HasPortParamStatsDynOfPCConfig()                                                    (TRUE != FALSE)
#define EthTSyn_HasPortSyncSendSmDynOfPCConfig()                                                    (TRUE != FALSE)
#define EthTSyn_HasPortSyncSendSmOfPCConfig()                                                       (TRUE != FALSE)
#define EthTSyn_HasRateMeasBufOfPCConfig()                                                          (TRUE != FALSE)
#define EthTSyn_HasRateMeasDynOfPCConfig()                                                          (TRUE != FALSE)
#define EthTSyn_HasRateMeasOfPCConfig()                                                             (TRUE != FALSE)
#define EthTSyn_HasSiteSyncSyncTxDynOfPCConfig()                                                    (TRUE != FALSE)
#define EthTSyn_HasSiteSyncSyncTxOfPCConfig()                                                       (TRUE != FALSE)
#define EthTSyn_HasSizeOfAnnounceRcvSmDynOfPCConfig()                                               (TRUE != FALSE)
#define EthTSyn_HasSizeOfAnnounceRcvSmOfPCConfig()                                                  (TRUE != FALSE)
#define EthTSyn_HasSizeOfAnnounceSendSmDynOfPCConfig()                                              (TRUE != FALSE)
#define EthTSyn_HasSizeOfAnnounceSendSmOfPCConfig()                                                 (TRUE != FALSE)
#define EthTSyn_HasSizeOfBridgeTxMasterPortDynOfPCConfig()                                          (TRUE != FALSE)
#define EthTSyn_HasSizeOfBridgeTxMasterPortOfPCConfig()                                             (TRUE != FALSE)
#define EthTSyn_HasSizeOfComCtrlEthIfCtrlDynOfPCConfig()                                            (TRUE != FALSE)
#define EthTSyn_HasSizeOfComCtrlEthIfCtrlOfPCConfig()                                               (TRUE != FALSE)
#define EthTSyn_HasSizeOfComCtrlPhysPortDynOfPCConfig()                                             (TRUE != FALSE)
#define EthTSyn_HasSizeOfComCtrlPhysPortOfPCConfig()                                                (TRUE != FALSE)
#define EthTSyn_HasSizeOfComCtrlPortIndOfPCConfig()                                                 (TRUE != FALSE)
#define EthTSyn_HasSizeOfComCtrlPortOfPCConfig()                                                    (TRUE != FALSE)
#define EthTSyn_HasSizeOfComCtrlTimeDomainOfPCConfig()                                              (TRUE != FALSE)
#define EthTSyn_HasSizeOfCrcHndlOfPCConfig()                                                        (TRUE != FALSE)
#define EthTSyn_HasSizeOfDestinationMacIndOfPCConfig()                                              (TRUE != FALSE)
#define EthTSyn_HasSizeOfDestinationMacOfPCConfig()                                                 (TRUE != FALSE)
#define EthTSyn_HasSizeOfFupDataIdListOfPCConfig()                                                  (TRUE != FALSE)
#define EthTSyn_HasSizeOfFupRxHandlerOfPCConfig()                                                   (TRUE != FALSE)
#define EthTSyn_HasSizeOfMsgSentCbkBufOfPCConfig()                                                  (TRUE != FALSE)
#define EthTSyn_HasSizeOfOffsetTimeDomainOfPCConfig()                                               (TRUE != FALSE)
#define EthTSyn_HasSizeOfPdReqSmDynOfPCConfig()                                                     (TRUE != FALSE)
#define EthTSyn_HasSizeOfPdReqSmOfPCConfig()                                                        (TRUE != FALSE)
#define EthTSyn_HasSizeOfPdReqTrcvDynOfPCConfig()                                                   (TRUE != FALSE)
#define EthTSyn_HasSizeOfPdRespSmDynOfPCConfig()                                                    (TRUE != FALSE)
#define EthTSyn_HasSizeOfPdRespSmOfPCConfig()                                                       (TRUE != FALSE)
#define EthTSyn_HasSizeOfPortParamStatsDynOfPCConfig()                                              (TRUE != FALSE)
#define EthTSyn_HasSizeOfPortSyncSendSmDynOfPCConfig()                                              (TRUE != FALSE)
#define EthTSyn_HasSizeOfPortSyncSendSmOfPCConfig()                                                 (TRUE != FALSE)
#define EthTSyn_HasSizeOfRateMeasBufOfPCConfig()                                                    (TRUE != FALSE)
#define EthTSyn_HasSizeOfRateMeasDynOfPCConfig()                                                    (TRUE != FALSE)
#define EthTSyn_HasSizeOfRateMeasOfPCConfig()                                                       (TRUE != FALSE)
#define EthTSyn_HasSizeOfSiteSyncSyncTxDynOfPCConfig()                                              (TRUE != FALSE)
#define EthTSyn_HasSizeOfSiteSyncSyncTxOfPCConfig()                                                 (TRUE != FALSE)
#define EthTSyn_HasSizeOfSlaveRxDataHandlerOfPCConfig()                                             (TRUE != FALSE)
#define EthTSyn_HasSizeOfSlaveRxDataOfPCConfig()                                                    (TRUE != FALSE)
#define EthTSyn_HasSizeOfSlaveRxMasterClockIdDynOfPCConfig()                                        (TRUE != FALSE)
#define EthTSyn_HasSizeOfSlaveRxSrcPortIdCheckClockIdOfPCConfig()                                   (TRUE != FALSE)
#define EthTSyn_HasSizeOfSlaveSwitchIdxListOfPCConfig()                                             (TRUE != FALSE)
#define EthTSyn_HasSizeOfSwtTimeSyncSmDynOfPCConfig()                                               (TRUE != FALSE)
#define EthTSyn_HasSizeOfSwtTimeSyncSmOfPCConfig()                                                  (TRUE != FALSE)
#define EthTSyn_HasSizeOfSyncRcvSmDynOfPCConfig()                                                   (TRUE != FALSE)
#define EthTSyn_HasSizeOfSyncRcvSmOfPCConfig()                                                      (TRUE != FALSE)
#define EthTSyn_HasSizeOfSyncSendSmDynOfPCConfig()                                                  (TRUE != FALSE)
#define EthTSyn_HasSizeOfSyncSendSmOfPCConfig()                                                     (TRUE != FALSE)
#define EthTSyn_HasSizeOfTimeBaseUpdateCounterDynOfPCConfig()                                       (TRUE != FALSE)
#define EthTSyn_HasSizeOfTimeBaseUpdateCounterOfPCConfig()                                          (TRUE != FALSE)
#define EthTSyn_HasSizeOfTxConfContextDynOfPCConfig()                                               (TRUE != FALSE)
#define EthTSyn_HasSizeOfTxConfContextOfPCConfig()                                                  (TRUE != FALSE)
#define EthTSyn_HasSlaveRxDataHandlerOfPCConfig()                                                   (TRUE != FALSE)
#define EthTSyn_HasSlaveRxDataOfPCConfig()                                                          (TRUE != FALSE)
#define EthTSyn_HasSlaveRxMasterClockIdDynOfPCConfig()                                              (TRUE != FALSE)
#define EthTSyn_HasSlaveRxSrcPortIdCheckClockIdOfPCConfig()                                         (TRUE != FALSE)
#define EthTSyn_HasSlaveSwitchIdxListOfPCConfig()                                                   (TRUE != FALSE)
#define EthTSyn_HasSwtTimeSyncSmDynOfPCConfig()                                                     (TRUE != FALSE)
#define EthTSyn_HasSwtTimeSyncSmOfPCConfig()                                                        (TRUE != FALSE)
#define EthTSyn_HasSyncRcvSmDynOfPCConfig()                                                         (TRUE != FALSE)
#define EthTSyn_HasSyncRcvSmOfPCConfig()                                                            (TRUE != FALSE)
#define EthTSyn_HasSyncSendSmDynOfPCConfig()                                                        (TRUE != FALSE)
#define EthTSyn_HasSyncSendSmOfPCConfig()                                                           (TRUE != FALSE)
#define EthTSyn_HasTimeBaseUpdateCounterDynOfPCConfig()                                             (TRUE != FALSE)
#define EthTSyn_HasTimeBaseUpdateCounterOfPCConfig()                                                (TRUE != FALSE)
#define EthTSyn_HasTxConfContextDynActiveFirstIdxOfPCConfig()                                       (TRUE != FALSE)
#define EthTSyn_HasTxConfContextDynActiveLastIdxOfPCConfig()                                        (TRUE != FALSE)
#define EthTSyn_HasTxConfContextDynOfPCConfig()                                                     (TRUE != FALSE)
#define EthTSyn_HasTxConfContextOfPCConfig()                                                        (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  EthTSynPCIncrementDataMacros  EthTSyn Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define EthTSyn_IncRxTimeoutCounterOfAnnounceRcvSmDyn(Index)                                        EthTSyn_GetRxTimeoutCounterOfAnnounceRcvSmDyn(Index)++
#define EthTSyn_IncAnnounceCycleTimerOfAnnounceSendSmDyn(Index)                                     EthTSyn_GetAnnounceCycleTimerOfAnnounceSendSmDyn(Index)++
#define EthTSyn_IncSequenceIdOfAnnounceSendSmDyn(Index)                                             EthTSyn_GetSequenceIdOfAnnounceSendSmDyn(Index)++
#define EthTSyn_IncSyncFwdDelayNsOfBridgeTxMasterPortDyn(Index)                                     EthTSyn_GetSyncFwdDelayNsOfBridgeTxMasterPortDyn(Index)++
#define EthTSyn_IncClockIdOfComCtrlEthIfCtrlDyn(Index)                                              EthTSyn_GetClockIdOfComCtrlEthIfCtrlDyn(Index)++
#define EthTSyn_IncDebounceTimerOfComCtrlPhysPortDyn(Index)                                         EthTSyn_GetDebounceTimerOfComCtrlPhysPortDyn(Index)++
#define EthTSyn_IncPdelayValueNsOfComCtrlPhysPortDyn(Index)                                         EthTSyn_GetPdelayValueNsOfComCtrlPhysPortDyn(Index)++
#define EthTSyn_IncMsgSentCbkBuf(Index)                                                             EthTSyn_GetMsgSentCbkBuf(Index)++
#define EthTSyn_IncLostResponseCntOfPdReqSmDyn(Index)                                               EthTSyn_GetLostResponseCntOfPdReqSmDyn(Index)++
#define EthTSyn_IncRespTimeoutCntOfPdReqSmDyn(Index)                                                EthTSyn_GetRespTimeoutCntOfPdReqSmDyn(Index)++
#define EthTSyn_IncSequenceIdOfPdReqSmDyn(Index)                                                    EthTSyn_GetSequenceIdOfPdReqSmDyn(Index)++
#define EthTSyn_IncTxIntervalCntOfPdReqSmDyn(Index)                                                 EthTSyn_GetTxIntervalCntOfPdReqSmDyn(Index)++
#define EthTSyn_IncRespClockIdOfPdReqTrcvDyn(Index)                                                 EthTSyn_GetRespClockIdOfPdReqTrcvDyn(Index)++
#define EthTSyn_IncRespPortNumOfPdReqTrcvDyn(Index)                                                 EthTSyn_GetRespPortNumOfPdReqTrcvDyn(Index)++
#define EthTSyn_IncRequestorClockIdOfPdRespSmDyn(Index)                                             EthTSyn_GetRequestorClockIdOfPdRespSmDyn(Index)++
#define EthTSyn_IncRequestorPortNumOfPdRespSmDyn(Index)                                             EthTSyn_GetRequestorPortNumOfPdRespSmDyn(Index)++
#define EthTSyn_IncSequenceIdOfPdRespSmDyn(Index)                                                   EthTSyn_GetSequenceIdOfPdRespSmDyn(Index)++
#define EthTSyn_IncPdLostRespExceededCountOfPortParamStatsDyn(Index)                                EthTSyn_GetPdLostRespExceededCountOfPortParamStatsDyn(Index)++
#define EthTSyn_IncRxAnnounceCountOfPortParamStatsDyn(Index)                                        EthTSyn_GetRxAnnounceCountOfPortParamStatsDyn(Index)++
#define EthTSyn_IncRxDiscardCountOfPortParamStatsDyn(Index)                                         EthTSyn_GetRxDiscardCountOfPortParamStatsDyn(Index)++
#define EthTSyn_IncRxFupCountOfPortParamStatsDyn(Index)                                             EthTSyn_GetRxFupCountOfPortParamStatsDyn(Index)++
#define EthTSyn_IncRxPdReqCountOfPortParamStatsDyn(Index)                                           EthTSyn_GetRxPdReqCountOfPortParamStatsDyn(Index)++
#define EthTSyn_IncRxPdRespCountOfPortParamStatsDyn(Index)                                          EthTSyn_GetRxPdRespCountOfPortParamStatsDyn(Index)++
#define EthTSyn_IncRxPdRespFupCountOfPortParamStatsDyn(Index)                                       EthTSyn_GetRxPdRespFupCountOfPortParamStatsDyn(Index)++
#define EthTSyn_IncRxSyncCountOfPortParamStatsDyn(Index)                                            EthTSyn_GetRxSyncCountOfPortParamStatsDyn(Index)++
#define EthTSyn_IncTxAnnounceCountOfPortParamStatsDyn(Index)                                        EthTSyn_GetTxAnnounceCountOfPortParamStatsDyn(Index)++
#define EthTSyn_IncTxFupCountOfPortParamStatsDyn(Index)                                             EthTSyn_GetTxFupCountOfPortParamStatsDyn(Index)++
#define EthTSyn_IncTxPdReqCountOfPortParamStatsDyn(Index)                                           EthTSyn_GetTxPdReqCountOfPortParamStatsDyn(Index)++
#define EthTSyn_IncTxPdRespCountOfPortParamStatsDyn(Index)                                          EthTSyn_GetTxPdRespCountOfPortParamStatsDyn(Index)++
#define EthTSyn_IncTxPdRespFupCountOfPortParamStatsDyn(Index)                                       EthTSyn_GetTxPdRespFupCountOfPortParamStatsDyn(Index)++
#define EthTSyn_IncTxSyncCountOfPortParamStatsDyn(Index)                                            EthTSyn_GetTxSyncCountOfPortParamStatsDyn(Index)++
#define EthTSyn_IncActiveNrOfSyncCyclesOfRateMeasBuf(Index)                                         EthTSyn_GetActiveNrOfSyncCyclesOfRateMeasBuf(Index)++
#define EthTSyn_IncLastCorrectedOffsetNsOfRateMeasDyn(Index)                                        EthTSyn_GetLastCorrectedOffsetNsOfRateMeasDyn(Index)++
#define EthTSyn_IncOutOfSyncCntOfRateMeasDyn(Index)                                                 EthTSyn_GetOutOfSyncCntOfRateMeasDyn(Index)++
#define EthTSyn_IncSyncCycleCounterOfRateMeasDyn(Index)                                             EthTSyn_GetSyncCycleCounterOfRateMeasDyn(Index)++
#define EthTSyn_IncFwdRetryCntOfSiteSyncSyncTxDyn(Index)                                            EthTSyn_GetFwdRetryCntOfSiteSyncSyncTxDyn(Index)++
#define EthTSyn_IncSlavePdelayNsOfSiteSyncSyncTxDyn(Index)                                          EthTSyn_GetSlavePdelayNsOfSiteSyncSyncTxDyn(Index)++
#define EthTSyn_IncValidMasterClockIdOfSlaveRxMasterClockIdDyn(Index)                               EthTSyn_GetValidMasterClockIdOfSlaveRxMasterClockIdDyn(Index)++
#define EthTSyn_IncSyncEventTimeoutCntOfSwtTimeSyncSmDyn(Index)                                     EthTSyn_GetSyncEventTimeoutCntOfSwtTimeSyncSmDyn(Index)++
#define EthTSyn_IncFupRxTimeoutCntOfSyncRcvSmDyn(Index)                                             EthTSyn_GetFupRxTimeoutCntOfSyncRcvSmDyn(Index)++
#define EthTSyn_IncSyncSequenceIdOfSyncRcvSmDyn(Index)                                              EthTSyn_GetSyncSequenceIdOfSyncRcvSmDyn(Index)++
#define EthTSyn_IncSyncSrcClockIdOfSyncRcvSmDyn(Index)                                              EthTSyn_GetSyncSrcClockIdOfSyncRcvSmDyn(Index)++
#define EthTSyn_IncSyncSrcPortNumOfSyncRcvSmDyn(Index)                                              EthTSyn_GetSyncSrcPortNumOfSyncRcvSmDyn(Index)++
#define EthTSyn_IncFupCorrFieldOfSyncSendSmDyn(Index)                                               EthTSyn_GetFupCorrFieldOfSyncSendSmDyn(Index)++
#define EthTSyn_IncSequenceIdOfSyncSendSmDyn(Index)                                                 EthTSyn_GetSequenceIdOfSyncSendSmDyn(Index)++
#define EthTSyn_IncTxIntervalCntOfSyncSendSmDyn(Index)                                              EthTSyn_GetTxIntervalCntOfSyncSendSmDyn(Index)++
#define EthTSyn_IncValueOfTimeBaseUpdateCounterDyn(Index)                                           EthTSyn_GetValueOfTimeBaseUpdateCounterDyn(Index)++
#define EthTSyn_IncBufferIdxOfTxConfContextDyn(Index)                                               EthTSyn_GetBufferIdxOfTxConfContextDyn(Index)++
#define EthTSyn_IncTxConfContextNextActiveIdxOfTxConfContextDyn(Index)                              EthTSyn_GetTxConfContextNextActiveIdxOfTxConfContextDyn(Index)++
#define EthTSyn_IncTxConfContextPrevActiveIdxOfTxConfContextDyn(Index)                              EthTSyn_GetTxConfContextPrevActiveIdxOfTxConfContextDyn(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  EthTSynPCDecrementDataMacros  EthTSyn Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define EthTSyn_DecRxTimeoutCounterOfAnnounceRcvSmDyn(Index)                                        EthTSyn_GetRxTimeoutCounterOfAnnounceRcvSmDyn(Index)--
#define EthTSyn_DecAnnounceCycleTimerOfAnnounceSendSmDyn(Index)                                     EthTSyn_GetAnnounceCycleTimerOfAnnounceSendSmDyn(Index)--
#define EthTSyn_DecSequenceIdOfAnnounceSendSmDyn(Index)                                             EthTSyn_GetSequenceIdOfAnnounceSendSmDyn(Index)--
#define EthTSyn_DecSyncFwdDelayNsOfBridgeTxMasterPortDyn(Index)                                     EthTSyn_GetSyncFwdDelayNsOfBridgeTxMasterPortDyn(Index)--
#define EthTSyn_DecClockIdOfComCtrlEthIfCtrlDyn(Index)                                              EthTSyn_GetClockIdOfComCtrlEthIfCtrlDyn(Index)--
#define EthTSyn_DecDebounceTimerOfComCtrlPhysPortDyn(Index)                                         EthTSyn_GetDebounceTimerOfComCtrlPhysPortDyn(Index)--
#define EthTSyn_DecPdelayValueNsOfComCtrlPhysPortDyn(Index)                                         EthTSyn_GetPdelayValueNsOfComCtrlPhysPortDyn(Index)--
#define EthTSyn_DecMsgSentCbkBuf(Index)                                                             EthTSyn_GetMsgSentCbkBuf(Index)--
#define EthTSyn_DecLostResponseCntOfPdReqSmDyn(Index)                                               EthTSyn_GetLostResponseCntOfPdReqSmDyn(Index)--
#define EthTSyn_DecRespTimeoutCntOfPdReqSmDyn(Index)                                                EthTSyn_GetRespTimeoutCntOfPdReqSmDyn(Index)--
#define EthTSyn_DecSequenceIdOfPdReqSmDyn(Index)                                                    EthTSyn_GetSequenceIdOfPdReqSmDyn(Index)--
#define EthTSyn_DecTxIntervalCntOfPdReqSmDyn(Index)                                                 EthTSyn_GetTxIntervalCntOfPdReqSmDyn(Index)--
#define EthTSyn_DecRespClockIdOfPdReqTrcvDyn(Index)                                                 EthTSyn_GetRespClockIdOfPdReqTrcvDyn(Index)--
#define EthTSyn_DecRespPortNumOfPdReqTrcvDyn(Index)                                                 EthTSyn_GetRespPortNumOfPdReqTrcvDyn(Index)--
#define EthTSyn_DecRequestorClockIdOfPdRespSmDyn(Index)                                             EthTSyn_GetRequestorClockIdOfPdRespSmDyn(Index)--
#define EthTSyn_DecRequestorPortNumOfPdRespSmDyn(Index)                                             EthTSyn_GetRequestorPortNumOfPdRespSmDyn(Index)--
#define EthTSyn_DecSequenceIdOfPdRespSmDyn(Index)                                                   EthTSyn_GetSequenceIdOfPdRespSmDyn(Index)--
#define EthTSyn_DecPdLostRespExceededCountOfPortParamStatsDyn(Index)                                EthTSyn_GetPdLostRespExceededCountOfPortParamStatsDyn(Index)--
#define EthTSyn_DecRxAnnounceCountOfPortParamStatsDyn(Index)                                        EthTSyn_GetRxAnnounceCountOfPortParamStatsDyn(Index)--
#define EthTSyn_DecRxDiscardCountOfPortParamStatsDyn(Index)                                         EthTSyn_GetRxDiscardCountOfPortParamStatsDyn(Index)--
#define EthTSyn_DecRxFupCountOfPortParamStatsDyn(Index)                                             EthTSyn_GetRxFupCountOfPortParamStatsDyn(Index)--
#define EthTSyn_DecRxPdReqCountOfPortParamStatsDyn(Index)                                           EthTSyn_GetRxPdReqCountOfPortParamStatsDyn(Index)--
#define EthTSyn_DecRxPdRespCountOfPortParamStatsDyn(Index)                                          EthTSyn_GetRxPdRespCountOfPortParamStatsDyn(Index)--
#define EthTSyn_DecRxPdRespFupCountOfPortParamStatsDyn(Index)                                       EthTSyn_GetRxPdRespFupCountOfPortParamStatsDyn(Index)--
#define EthTSyn_DecRxSyncCountOfPortParamStatsDyn(Index)                                            EthTSyn_GetRxSyncCountOfPortParamStatsDyn(Index)--
#define EthTSyn_DecTxAnnounceCountOfPortParamStatsDyn(Index)                                        EthTSyn_GetTxAnnounceCountOfPortParamStatsDyn(Index)--
#define EthTSyn_DecTxFupCountOfPortParamStatsDyn(Index)                                             EthTSyn_GetTxFupCountOfPortParamStatsDyn(Index)--
#define EthTSyn_DecTxPdReqCountOfPortParamStatsDyn(Index)                                           EthTSyn_GetTxPdReqCountOfPortParamStatsDyn(Index)--
#define EthTSyn_DecTxPdRespCountOfPortParamStatsDyn(Index)                                          EthTSyn_GetTxPdRespCountOfPortParamStatsDyn(Index)--
#define EthTSyn_DecTxPdRespFupCountOfPortParamStatsDyn(Index)                                       EthTSyn_GetTxPdRespFupCountOfPortParamStatsDyn(Index)--
#define EthTSyn_DecTxSyncCountOfPortParamStatsDyn(Index)                                            EthTSyn_GetTxSyncCountOfPortParamStatsDyn(Index)--
#define EthTSyn_DecActiveNrOfSyncCyclesOfRateMeasBuf(Index)                                         EthTSyn_GetActiveNrOfSyncCyclesOfRateMeasBuf(Index)--
#define EthTSyn_DecLastCorrectedOffsetNsOfRateMeasDyn(Index)                                        EthTSyn_GetLastCorrectedOffsetNsOfRateMeasDyn(Index)--
#define EthTSyn_DecOutOfSyncCntOfRateMeasDyn(Index)                                                 EthTSyn_GetOutOfSyncCntOfRateMeasDyn(Index)--
#define EthTSyn_DecSyncCycleCounterOfRateMeasDyn(Index)                                             EthTSyn_GetSyncCycleCounterOfRateMeasDyn(Index)--
#define EthTSyn_DecFwdRetryCntOfSiteSyncSyncTxDyn(Index)                                            EthTSyn_GetFwdRetryCntOfSiteSyncSyncTxDyn(Index)--
#define EthTSyn_DecSlavePdelayNsOfSiteSyncSyncTxDyn(Index)                                          EthTSyn_GetSlavePdelayNsOfSiteSyncSyncTxDyn(Index)--
#define EthTSyn_DecValidMasterClockIdOfSlaveRxMasterClockIdDyn(Index)                               EthTSyn_GetValidMasterClockIdOfSlaveRxMasterClockIdDyn(Index)--
#define EthTSyn_DecSyncEventTimeoutCntOfSwtTimeSyncSmDyn(Index)                                     EthTSyn_GetSyncEventTimeoutCntOfSwtTimeSyncSmDyn(Index)--
#define EthTSyn_DecFupRxTimeoutCntOfSyncRcvSmDyn(Index)                                             EthTSyn_GetFupRxTimeoutCntOfSyncRcvSmDyn(Index)--
#define EthTSyn_DecSyncSequenceIdOfSyncRcvSmDyn(Index)                                              EthTSyn_GetSyncSequenceIdOfSyncRcvSmDyn(Index)--
#define EthTSyn_DecSyncSrcClockIdOfSyncRcvSmDyn(Index)                                              EthTSyn_GetSyncSrcClockIdOfSyncRcvSmDyn(Index)--
#define EthTSyn_DecSyncSrcPortNumOfSyncRcvSmDyn(Index)                                              EthTSyn_GetSyncSrcPortNumOfSyncRcvSmDyn(Index)--
#define EthTSyn_DecFupCorrFieldOfSyncSendSmDyn(Index)                                               EthTSyn_GetFupCorrFieldOfSyncSendSmDyn(Index)--
#define EthTSyn_DecSequenceIdOfSyncSendSmDyn(Index)                                                 EthTSyn_GetSequenceIdOfSyncSendSmDyn(Index)--
#define EthTSyn_DecTxIntervalCntOfSyncSendSmDyn(Index)                                              EthTSyn_GetTxIntervalCntOfSyncSendSmDyn(Index)--
#define EthTSyn_DecValueOfTimeBaseUpdateCounterDyn(Index)                                           EthTSyn_GetValueOfTimeBaseUpdateCounterDyn(Index)--
#define EthTSyn_DecBufferIdxOfTxConfContextDyn(Index)                                               EthTSyn_GetBufferIdxOfTxConfContextDyn(Index)--
#define EthTSyn_DecTxConfContextNextActiveIdxOfTxConfContextDyn(Index)                              EthTSyn_GetTxConfContextNextActiveIdxOfTxConfContextDyn(Index)--
#define EthTSyn_DecTxConfContextPrevActiveIdxOfTxConfContextDyn(Index)                              EthTSyn_GetTxConfContextPrevActiveIdxOfTxConfContextDyn(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  EthTSynPCAddDataMacros  EthTSyn Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define EthTSyn_AddRxTimeoutCounterOfAnnounceRcvSmDyn(Index, Value)                                 EthTSyn_SetRxTimeoutCounterOfAnnounceRcvSmDyn(Index, (EthTSyn_GetRxTimeoutCounterOfAnnounceRcvSmDyn(Index) + Value))
#define EthTSyn_AddAnnounceCycleTimerOfAnnounceSendSmDyn(Index, Value)                              EthTSyn_SetAnnounceCycleTimerOfAnnounceSendSmDyn(Index, (EthTSyn_GetAnnounceCycleTimerOfAnnounceSendSmDyn(Index) + Value))
#define EthTSyn_AddSequenceIdOfAnnounceSendSmDyn(Index, Value)                                      EthTSyn_SetSequenceIdOfAnnounceSendSmDyn(Index, (EthTSyn_GetSequenceIdOfAnnounceSendSmDyn(Index) + Value))
#define EthTSyn_AddSyncFwdDelayNsOfBridgeTxMasterPortDyn(Index, Value)                              EthTSyn_SetSyncFwdDelayNsOfBridgeTxMasterPortDyn(Index, (EthTSyn_GetSyncFwdDelayNsOfBridgeTxMasterPortDyn(Index) + Value))
#define EthTSyn_AddClockIdOfComCtrlEthIfCtrlDyn(Index, Value)                                       EthTSyn_SetClockIdOfComCtrlEthIfCtrlDyn(Index, (EthTSyn_GetClockIdOfComCtrlEthIfCtrlDyn(Index) + Value))
#define EthTSyn_AddDebounceTimerOfComCtrlPhysPortDyn(Index, Value)                                  EthTSyn_SetDebounceTimerOfComCtrlPhysPortDyn(Index, (EthTSyn_GetDebounceTimerOfComCtrlPhysPortDyn(Index) + Value))
#define EthTSyn_AddPdelayValueNsOfComCtrlPhysPortDyn(Index, Value)                                  EthTSyn_SetPdelayValueNsOfComCtrlPhysPortDyn(Index, (EthTSyn_GetPdelayValueNsOfComCtrlPhysPortDyn(Index) + Value))
#define EthTSyn_AddMsgSentCbkBuf(Index, Value)                                                      EthTSyn_SetMsgSentCbkBuf(Index, (EthTSyn_GetMsgSentCbkBuf(Index) + Value))
#define EthTSyn_AddLostResponseCntOfPdReqSmDyn(Index, Value)                                        EthTSyn_SetLostResponseCntOfPdReqSmDyn(Index, (EthTSyn_GetLostResponseCntOfPdReqSmDyn(Index) + Value))
#define EthTSyn_AddRespTimeoutCntOfPdReqSmDyn(Index, Value)                                         EthTSyn_SetRespTimeoutCntOfPdReqSmDyn(Index, (EthTSyn_GetRespTimeoutCntOfPdReqSmDyn(Index) + Value))
#define EthTSyn_AddSequenceIdOfPdReqSmDyn(Index, Value)                                             EthTSyn_SetSequenceIdOfPdReqSmDyn(Index, (EthTSyn_GetSequenceIdOfPdReqSmDyn(Index) + Value))
#define EthTSyn_AddTxIntervalCntOfPdReqSmDyn(Index, Value)                                          EthTSyn_SetTxIntervalCntOfPdReqSmDyn(Index, (EthTSyn_GetTxIntervalCntOfPdReqSmDyn(Index) + Value))
#define EthTSyn_AddRespClockIdOfPdReqTrcvDyn(Index, Value)                                          EthTSyn_SetRespClockIdOfPdReqTrcvDyn(Index, (EthTSyn_GetRespClockIdOfPdReqTrcvDyn(Index) + Value))
#define EthTSyn_AddRespPortNumOfPdReqTrcvDyn(Index, Value)                                          EthTSyn_SetRespPortNumOfPdReqTrcvDyn(Index, (EthTSyn_GetRespPortNumOfPdReqTrcvDyn(Index) + Value))
#define EthTSyn_AddRequestorClockIdOfPdRespSmDyn(Index, Value)                                      EthTSyn_SetRequestorClockIdOfPdRespSmDyn(Index, (EthTSyn_GetRequestorClockIdOfPdRespSmDyn(Index) + Value))
#define EthTSyn_AddRequestorPortNumOfPdRespSmDyn(Index, Value)                                      EthTSyn_SetRequestorPortNumOfPdRespSmDyn(Index, (EthTSyn_GetRequestorPortNumOfPdRespSmDyn(Index) + Value))
#define EthTSyn_AddSequenceIdOfPdRespSmDyn(Index, Value)                                            EthTSyn_SetSequenceIdOfPdRespSmDyn(Index, (EthTSyn_GetSequenceIdOfPdRespSmDyn(Index) + Value))
#define EthTSyn_AddPdLostRespExceededCountOfPortParamStatsDyn(Index, Value)                         EthTSyn_SetPdLostRespExceededCountOfPortParamStatsDyn(Index, (EthTSyn_GetPdLostRespExceededCountOfPortParamStatsDyn(Index) + Value))
#define EthTSyn_AddRxAnnounceCountOfPortParamStatsDyn(Index, Value)                                 EthTSyn_SetRxAnnounceCountOfPortParamStatsDyn(Index, (EthTSyn_GetRxAnnounceCountOfPortParamStatsDyn(Index) + Value))
#define EthTSyn_AddRxDiscardCountOfPortParamStatsDyn(Index, Value)                                  EthTSyn_SetRxDiscardCountOfPortParamStatsDyn(Index, (EthTSyn_GetRxDiscardCountOfPortParamStatsDyn(Index) + Value))
#define EthTSyn_AddRxFupCountOfPortParamStatsDyn(Index, Value)                                      EthTSyn_SetRxFupCountOfPortParamStatsDyn(Index, (EthTSyn_GetRxFupCountOfPortParamStatsDyn(Index) + Value))
#define EthTSyn_AddRxPdReqCountOfPortParamStatsDyn(Index, Value)                                    EthTSyn_SetRxPdReqCountOfPortParamStatsDyn(Index, (EthTSyn_GetRxPdReqCountOfPortParamStatsDyn(Index) + Value))
#define EthTSyn_AddRxPdRespCountOfPortParamStatsDyn(Index, Value)                                   EthTSyn_SetRxPdRespCountOfPortParamStatsDyn(Index, (EthTSyn_GetRxPdRespCountOfPortParamStatsDyn(Index) + Value))
#define EthTSyn_AddRxPdRespFupCountOfPortParamStatsDyn(Index, Value)                                EthTSyn_SetRxPdRespFupCountOfPortParamStatsDyn(Index, (EthTSyn_GetRxPdRespFupCountOfPortParamStatsDyn(Index) + Value))
#define EthTSyn_AddRxSyncCountOfPortParamStatsDyn(Index, Value)                                     EthTSyn_SetRxSyncCountOfPortParamStatsDyn(Index, (EthTSyn_GetRxSyncCountOfPortParamStatsDyn(Index) + Value))
#define EthTSyn_AddTxAnnounceCountOfPortParamStatsDyn(Index, Value)                                 EthTSyn_SetTxAnnounceCountOfPortParamStatsDyn(Index, (EthTSyn_GetTxAnnounceCountOfPortParamStatsDyn(Index) + Value))
#define EthTSyn_AddTxFupCountOfPortParamStatsDyn(Index, Value)                                      EthTSyn_SetTxFupCountOfPortParamStatsDyn(Index, (EthTSyn_GetTxFupCountOfPortParamStatsDyn(Index) + Value))
#define EthTSyn_AddTxPdReqCountOfPortParamStatsDyn(Index, Value)                                    EthTSyn_SetTxPdReqCountOfPortParamStatsDyn(Index, (EthTSyn_GetTxPdReqCountOfPortParamStatsDyn(Index) + Value))
#define EthTSyn_AddTxPdRespCountOfPortParamStatsDyn(Index, Value)                                   EthTSyn_SetTxPdRespCountOfPortParamStatsDyn(Index, (EthTSyn_GetTxPdRespCountOfPortParamStatsDyn(Index) + Value))
#define EthTSyn_AddTxPdRespFupCountOfPortParamStatsDyn(Index, Value)                                EthTSyn_SetTxPdRespFupCountOfPortParamStatsDyn(Index, (EthTSyn_GetTxPdRespFupCountOfPortParamStatsDyn(Index) + Value))
#define EthTSyn_AddTxSyncCountOfPortParamStatsDyn(Index, Value)                                     EthTSyn_SetTxSyncCountOfPortParamStatsDyn(Index, (EthTSyn_GetTxSyncCountOfPortParamStatsDyn(Index) + Value))
#define EthTSyn_AddActiveNrOfSyncCyclesOfRateMeasBuf(Index, Value)                                  EthTSyn_SetActiveNrOfSyncCyclesOfRateMeasBuf(Index, (EthTSyn_GetActiveNrOfSyncCyclesOfRateMeasBuf(Index) + Value))
#define EthTSyn_AddLastCorrectedOffsetNsOfRateMeasDyn(Index, Value)                                 EthTSyn_SetLastCorrectedOffsetNsOfRateMeasDyn(Index, (EthTSyn_GetLastCorrectedOffsetNsOfRateMeasDyn(Index) + Value))
#define EthTSyn_AddOutOfSyncCntOfRateMeasDyn(Index, Value)                                          EthTSyn_SetOutOfSyncCntOfRateMeasDyn(Index, (EthTSyn_GetOutOfSyncCntOfRateMeasDyn(Index) + Value))
#define EthTSyn_AddSyncCycleCounterOfRateMeasDyn(Index, Value)                                      EthTSyn_SetSyncCycleCounterOfRateMeasDyn(Index, (EthTSyn_GetSyncCycleCounterOfRateMeasDyn(Index) + Value))
#define EthTSyn_AddFwdRetryCntOfSiteSyncSyncTxDyn(Index, Value)                                     EthTSyn_SetFwdRetryCntOfSiteSyncSyncTxDyn(Index, (EthTSyn_GetFwdRetryCntOfSiteSyncSyncTxDyn(Index) + Value))
#define EthTSyn_AddSlavePdelayNsOfSiteSyncSyncTxDyn(Index, Value)                                   EthTSyn_SetSlavePdelayNsOfSiteSyncSyncTxDyn(Index, (EthTSyn_GetSlavePdelayNsOfSiteSyncSyncTxDyn(Index) + Value))
#define EthTSyn_AddValidMasterClockIdOfSlaveRxMasterClockIdDyn(Index, Value)                        EthTSyn_SetValidMasterClockIdOfSlaveRxMasterClockIdDyn(Index, (EthTSyn_GetValidMasterClockIdOfSlaveRxMasterClockIdDyn(Index) + Value))
#define EthTSyn_AddSyncEventTimeoutCntOfSwtTimeSyncSmDyn(Index, Value)                              EthTSyn_SetSyncEventTimeoutCntOfSwtTimeSyncSmDyn(Index, (EthTSyn_GetSyncEventTimeoutCntOfSwtTimeSyncSmDyn(Index) + Value))
#define EthTSyn_AddFupRxTimeoutCntOfSyncRcvSmDyn(Index, Value)                                      EthTSyn_SetFupRxTimeoutCntOfSyncRcvSmDyn(Index, (EthTSyn_GetFupRxTimeoutCntOfSyncRcvSmDyn(Index) + Value))
#define EthTSyn_AddSyncSequenceIdOfSyncRcvSmDyn(Index, Value)                                       EthTSyn_SetSyncSequenceIdOfSyncRcvSmDyn(Index, (EthTSyn_GetSyncSequenceIdOfSyncRcvSmDyn(Index) + Value))
#define EthTSyn_AddSyncSrcClockIdOfSyncRcvSmDyn(Index, Value)                                       EthTSyn_SetSyncSrcClockIdOfSyncRcvSmDyn(Index, (EthTSyn_GetSyncSrcClockIdOfSyncRcvSmDyn(Index) + Value))
#define EthTSyn_AddSyncSrcPortNumOfSyncRcvSmDyn(Index, Value)                                       EthTSyn_SetSyncSrcPortNumOfSyncRcvSmDyn(Index, (EthTSyn_GetSyncSrcPortNumOfSyncRcvSmDyn(Index) + Value))
#define EthTSyn_AddFupCorrFieldOfSyncSendSmDyn(Index, Value)                                        EthTSyn_SetFupCorrFieldOfSyncSendSmDyn(Index, (EthTSyn_GetFupCorrFieldOfSyncSendSmDyn(Index) + Value))
#define EthTSyn_AddSequenceIdOfSyncSendSmDyn(Index, Value)                                          EthTSyn_SetSequenceIdOfSyncSendSmDyn(Index, (EthTSyn_GetSequenceIdOfSyncSendSmDyn(Index) + Value))
#define EthTSyn_AddTxIntervalCntOfSyncSendSmDyn(Index, Value)                                       EthTSyn_SetTxIntervalCntOfSyncSendSmDyn(Index, (EthTSyn_GetTxIntervalCntOfSyncSendSmDyn(Index) + Value))
#define EthTSyn_AddValueOfTimeBaseUpdateCounterDyn(Index, Value)                                    EthTSyn_SetValueOfTimeBaseUpdateCounterDyn(Index, (EthTSyn_GetValueOfTimeBaseUpdateCounterDyn(Index) + Value))
#define EthTSyn_AddBufferIdxOfTxConfContextDyn(Index, Value)                                        EthTSyn_SetBufferIdxOfTxConfContextDyn(Index, (EthTSyn_GetBufferIdxOfTxConfContextDyn(Index) + Value))
#define EthTSyn_AddTxConfContextNextActiveIdxOfTxConfContextDyn(Index, Value)                       EthTSyn_SetTxConfContextNextActiveIdxOfTxConfContextDyn(Index, (EthTSyn_GetTxConfContextNextActiveIdxOfTxConfContextDyn(Index) + Value))
#define EthTSyn_AddTxConfContextPrevActiveIdxOfTxConfContextDyn(Index, Value)                       EthTSyn_SetTxConfContextPrevActiveIdxOfTxConfContextDyn(Index, (EthTSyn_GetTxConfContextPrevActiveIdxOfTxConfContextDyn(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  EthTSynPCSubstractDataMacros  EthTSyn Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define EthTSyn_SubRxTimeoutCounterOfAnnounceRcvSmDyn(Index, Value)                                 EthTSyn_SetRxTimeoutCounterOfAnnounceRcvSmDyn(Index, (EthTSyn_GetRxTimeoutCounterOfAnnounceRcvSmDyn(Index) - Value))
#define EthTSyn_SubAnnounceCycleTimerOfAnnounceSendSmDyn(Index, Value)                              EthTSyn_SetAnnounceCycleTimerOfAnnounceSendSmDyn(Index, (EthTSyn_GetAnnounceCycleTimerOfAnnounceSendSmDyn(Index) - Value))
#define EthTSyn_SubSequenceIdOfAnnounceSendSmDyn(Index, Value)                                      EthTSyn_SetSequenceIdOfAnnounceSendSmDyn(Index, (EthTSyn_GetSequenceIdOfAnnounceSendSmDyn(Index) - Value))
#define EthTSyn_SubSyncFwdDelayNsOfBridgeTxMasterPortDyn(Index, Value)                              EthTSyn_SetSyncFwdDelayNsOfBridgeTxMasterPortDyn(Index, (EthTSyn_GetSyncFwdDelayNsOfBridgeTxMasterPortDyn(Index) - Value))
#define EthTSyn_SubClockIdOfComCtrlEthIfCtrlDyn(Index, Value)                                       EthTSyn_SetClockIdOfComCtrlEthIfCtrlDyn(Index, (EthTSyn_GetClockIdOfComCtrlEthIfCtrlDyn(Index) - Value))
#define EthTSyn_SubDebounceTimerOfComCtrlPhysPortDyn(Index, Value)                                  EthTSyn_SetDebounceTimerOfComCtrlPhysPortDyn(Index, (EthTSyn_GetDebounceTimerOfComCtrlPhysPortDyn(Index) - Value))
#define EthTSyn_SubPdelayValueNsOfComCtrlPhysPortDyn(Index, Value)                                  EthTSyn_SetPdelayValueNsOfComCtrlPhysPortDyn(Index, (EthTSyn_GetPdelayValueNsOfComCtrlPhysPortDyn(Index) - Value))
#define EthTSyn_SubMsgSentCbkBuf(Index, Value)                                                      EthTSyn_SetMsgSentCbkBuf(Index, (EthTSyn_GetMsgSentCbkBuf(Index) - Value))
#define EthTSyn_SubLostResponseCntOfPdReqSmDyn(Index, Value)                                        EthTSyn_SetLostResponseCntOfPdReqSmDyn(Index, (EthTSyn_GetLostResponseCntOfPdReqSmDyn(Index) - Value))
#define EthTSyn_SubRespTimeoutCntOfPdReqSmDyn(Index, Value)                                         EthTSyn_SetRespTimeoutCntOfPdReqSmDyn(Index, (EthTSyn_GetRespTimeoutCntOfPdReqSmDyn(Index) - Value))
#define EthTSyn_SubSequenceIdOfPdReqSmDyn(Index, Value)                                             EthTSyn_SetSequenceIdOfPdReqSmDyn(Index, (EthTSyn_GetSequenceIdOfPdReqSmDyn(Index) - Value))
#define EthTSyn_SubTxIntervalCntOfPdReqSmDyn(Index, Value)                                          EthTSyn_SetTxIntervalCntOfPdReqSmDyn(Index, (EthTSyn_GetTxIntervalCntOfPdReqSmDyn(Index) - Value))
#define EthTSyn_SubRespClockIdOfPdReqTrcvDyn(Index, Value)                                          EthTSyn_SetRespClockIdOfPdReqTrcvDyn(Index, (EthTSyn_GetRespClockIdOfPdReqTrcvDyn(Index) - Value))
#define EthTSyn_SubRespPortNumOfPdReqTrcvDyn(Index, Value)                                          EthTSyn_SetRespPortNumOfPdReqTrcvDyn(Index, (EthTSyn_GetRespPortNumOfPdReqTrcvDyn(Index) - Value))
#define EthTSyn_SubRequestorClockIdOfPdRespSmDyn(Index, Value)                                      EthTSyn_SetRequestorClockIdOfPdRespSmDyn(Index, (EthTSyn_GetRequestorClockIdOfPdRespSmDyn(Index) - Value))
#define EthTSyn_SubRequestorPortNumOfPdRespSmDyn(Index, Value)                                      EthTSyn_SetRequestorPortNumOfPdRespSmDyn(Index, (EthTSyn_GetRequestorPortNumOfPdRespSmDyn(Index) - Value))
#define EthTSyn_SubSequenceIdOfPdRespSmDyn(Index, Value)                                            EthTSyn_SetSequenceIdOfPdRespSmDyn(Index, (EthTSyn_GetSequenceIdOfPdRespSmDyn(Index) - Value))
#define EthTSyn_SubPdLostRespExceededCountOfPortParamStatsDyn(Index, Value)                         EthTSyn_SetPdLostRespExceededCountOfPortParamStatsDyn(Index, (EthTSyn_GetPdLostRespExceededCountOfPortParamStatsDyn(Index) - Value))
#define EthTSyn_SubRxAnnounceCountOfPortParamStatsDyn(Index, Value)                                 EthTSyn_SetRxAnnounceCountOfPortParamStatsDyn(Index, (EthTSyn_GetRxAnnounceCountOfPortParamStatsDyn(Index) - Value))
#define EthTSyn_SubRxDiscardCountOfPortParamStatsDyn(Index, Value)                                  EthTSyn_SetRxDiscardCountOfPortParamStatsDyn(Index, (EthTSyn_GetRxDiscardCountOfPortParamStatsDyn(Index) - Value))
#define EthTSyn_SubRxFupCountOfPortParamStatsDyn(Index, Value)                                      EthTSyn_SetRxFupCountOfPortParamStatsDyn(Index, (EthTSyn_GetRxFupCountOfPortParamStatsDyn(Index) - Value))
#define EthTSyn_SubRxPdReqCountOfPortParamStatsDyn(Index, Value)                                    EthTSyn_SetRxPdReqCountOfPortParamStatsDyn(Index, (EthTSyn_GetRxPdReqCountOfPortParamStatsDyn(Index) - Value))
#define EthTSyn_SubRxPdRespCountOfPortParamStatsDyn(Index, Value)                                   EthTSyn_SetRxPdRespCountOfPortParamStatsDyn(Index, (EthTSyn_GetRxPdRespCountOfPortParamStatsDyn(Index) - Value))
#define EthTSyn_SubRxPdRespFupCountOfPortParamStatsDyn(Index, Value)                                EthTSyn_SetRxPdRespFupCountOfPortParamStatsDyn(Index, (EthTSyn_GetRxPdRespFupCountOfPortParamStatsDyn(Index) - Value))
#define EthTSyn_SubRxSyncCountOfPortParamStatsDyn(Index, Value)                                     EthTSyn_SetRxSyncCountOfPortParamStatsDyn(Index, (EthTSyn_GetRxSyncCountOfPortParamStatsDyn(Index) - Value))
#define EthTSyn_SubTxAnnounceCountOfPortParamStatsDyn(Index, Value)                                 EthTSyn_SetTxAnnounceCountOfPortParamStatsDyn(Index, (EthTSyn_GetTxAnnounceCountOfPortParamStatsDyn(Index) - Value))
#define EthTSyn_SubTxFupCountOfPortParamStatsDyn(Index, Value)                                      EthTSyn_SetTxFupCountOfPortParamStatsDyn(Index, (EthTSyn_GetTxFupCountOfPortParamStatsDyn(Index) - Value))
#define EthTSyn_SubTxPdReqCountOfPortParamStatsDyn(Index, Value)                                    EthTSyn_SetTxPdReqCountOfPortParamStatsDyn(Index, (EthTSyn_GetTxPdReqCountOfPortParamStatsDyn(Index) - Value))
#define EthTSyn_SubTxPdRespCountOfPortParamStatsDyn(Index, Value)                                   EthTSyn_SetTxPdRespCountOfPortParamStatsDyn(Index, (EthTSyn_GetTxPdRespCountOfPortParamStatsDyn(Index) - Value))
#define EthTSyn_SubTxPdRespFupCountOfPortParamStatsDyn(Index, Value)                                EthTSyn_SetTxPdRespFupCountOfPortParamStatsDyn(Index, (EthTSyn_GetTxPdRespFupCountOfPortParamStatsDyn(Index) - Value))
#define EthTSyn_SubTxSyncCountOfPortParamStatsDyn(Index, Value)                                     EthTSyn_SetTxSyncCountOfPortParamStatsDyn(Index, (EthTSyn_GetTxSyncCountOfPortParamStatsDyn(Index) - Value))
#define EthTSyn_SubActiveNrOfSyncCyclesOfRateMeasBuf(Index, Value)                                  EthTSyn_SetActiveNrOfSyncCyclesOfRateMeasBuf(Index, (EthTSyn_GetActiveNrOfSyncCyclesOfRateMeasBuf(Index) - Value))
#define EthTSyn_SubLastCorrectedOffsetNsOfRateMeasDyn(Index, Value)                                 EthTSyn_SetLastCorrectedOffsetNsOfRateMeasDyn(Index, (EthTSyn_GetLastCorrectedOffsetNsOfRateMeasDyn(Index) - Value))
#define EthTSyn_SubOutOfSyncCntOfRateMeasDyn(Index, Value)                                          EthTSyn_SetOutOfSyncCntOfRateMeasDyn(Index, (EthTSyn_GetOutOfSyncCntOfRateMeasDyn(Index) - Value))
#define EthTSyn_SubSyncCycleCounterOfRateMeasDyn(Index, Value)                                      EthTSyn_SetSyncCycleCounterOfRateMeasDyn(Index, (EthTSyn_GetSyncCycleCounterOfRateMeasDyn(Index) - Value))
#define EthTSyn_SubFwdRetryCntOfSiteSyncSyncTxDyn(Index, Value)                                     EthTSyn_SetFwdRetryCntOfSiteSyncSyncTxDyn(Index, (EthTSyn_GetFwdRetryCntOfSiteSyncSyncTxDyn(Index) - Value))
#define EthTSyn_SubSlavePdelayNsOfSiteSyncSyncTxDyn(Index, Value)                                   EthTSyn_SetSlavePdelayNsOfSiteSyncSyncTxDyn(Index, (EthTSyn_GetSlavePdelayNsOfSiteSyncSyncTxDyn(Index) - Value))
#define EthTSyn_SubValidMasterClockIdOfSlaveRxMasterClockIdDyn(Index, Value)                        EthTSyn_SetValidMasterClockIdOfSlaveRxMasterClockIdDyn(Index, (EthTSyn_GetValidMasterClockIdOfSlaveRxMasterClockIdDyn(Index) - Value))
#define EthTSyn_SubSyncEventTimeoutCntOfSwtTimeSyncSmDyn(Index, Value)                              EthTSyn_SetSyncEventTimeoutCntOfSwtTimeSyncSmDyn(Index, (EthTSyn_GetSyncEventTimeoutCntOfSwtTimeSyncSmDyn(Index) - Value))
#define EthTSyn_SubFupRxTimeoutCntOfSyncRcvSmDyn(Index, Value)                                      EthTSyn_SetFupRxTimeoutCntOfSyncRcvSmDyn(Index, (EthTSyn_GetFupRxTimeoutCntOfSyncRcvSmDyn(Index) - Value))
#define EthTSyn_SubSyncSequenceIdOfSyncRcvSmDyn(Index, Value)                                       EthTSyn_SetSyncSequenceIdOfSyncRcvSmDyn(Index, (EthTSyn_GetSyncSequenceIdOfSyncRcvSmDyn(Index) - Value))
#define EthTSyn_SubSyncSrcClockIdOfSyncRcvSmDyn(Index, Value)                                       EthTSyn_SetSyncSrcClockIdOfSyncRcvSmDyn(Index, (EthTSyn_GetSyncSrcClockIdOfSyncRcvSmDyn(Index) - Value))
#define EthTSyn_SubSyncSrcPortNumOfSyncRcvSmDyn(Index, Value)                                       EthTSyn_SetSyncSrcPortNumOfSyncRcvSmDyn(Index, (EthTSyn_GetSyncSrcPortNumOfSyncRcvSmDyn(Index) - Value))
#define EthTSyn_SubFupCorrFieldOfSyncSendSmDyn(Index, Value)                                        EthTSyn_SetFupCorrFieldOfSyncSendSmDyn(Index, (EthTSyn_GetFupCorrFieldOfSyncSendSmDyn(Index) - Value))
#define EthTSyn_SubSequenceIdOfSyncSendSmDyn(Index, Value)                                          EthTSyn_SetSequenceIdOfSyncSendSmDyn(Index, (EthTSyn_GetSequenceIdOfSyncSendSmDyn(Index) - Value))
#define EthTSyn_SubTxIntervalCntOfSyncSendSmDyn(Index, Value)                                       EthTSyn_SetTxIntervalCntOfSyncSendSmDyn(Index, (EthTSyn_GetTxIntervalCntOfSyncSendSmDyn(Index) - Value))
#define EthTSyn_SubValueOfTimeBaseUpdateCounterDyn(Index, Value)                                    EthTSyn_SetValueOfTimeBaseUpdateCounterDyn(Index, (EthTSyn_GetValueOfTimeBaseUpdateCounterDyn(Index) - Value))
#define EthTSyn_SubBufferIdxOfTxConfContextDyn(Index, Value)                                        EthTSyn_SetBufferIdxOfTxConfContextDyn(Index, (EthTSyn_GetBufferIdxOfTxConfContextDyn(Index) - Value))
#define EthTSyn_SubTxConfContextNextActiveIdxOfTxConfContextDyn(Index, Value)                       EthTSyn_SetTxConfContextNextActiveIdxOfTxConfContextDyn(Index, (EthTSyn_GetTxConfContextNextActiveIdxOfTxConfContextDyn(Index) - Value))
#define EthTSyn_SubTxConfContextPrevActiveIdxOfTxConfContextDyn(Index, Value)                       EthTSyn_SetTxConfContextPrevActiveIdxOfTxConfContextDyn(Index, (EthTSyn_GetTxConfContextPrevActiveIdxOfTxConfContextDyn(Index) - Value))
/** 
  \}
*/ 


/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/* PRQA S 0779 IDENTIFIERS_0779 */ /* MD_EthTSyn_0779_CslAccessName */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIZEOF INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/

# if !defined(ETHTSYN_UNIT_TEST) /* COV_ETHTSYN_TESTSUITE_INSTRUMENTATION */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/

# endif /* !defined(ETHTSYN_UNIT_TEST) */
/* PRQA L: IDENTIFIERS_0779 */
#endif  /* ETHTSYN_GENERATED_CFG_ACCESS_H */

/**********************************************************************************************************************
 *  END OF FILE: EthTSyn_GeneratedCfgAccess.h
 *********************************************************************************************************************/

