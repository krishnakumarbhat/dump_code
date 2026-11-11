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
 *              File: EthTSyn_Lcfg.h
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
#ifndef ETHTSYN_LCFG_H
# define ETHTSYN_LCFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATIONS
 *********************************************************************************************************************/
/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "EthTSyn_GeneratedComplexTypes.h"

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  EthTSyn_ComCtrlEthIfCtrl
**********************************************************************************************************************/
/** 
  \var    EthTSyn_ComCtrlEthIfCtrl
  \brief  Static data related to the underlying EthIf controller.
  \details
  Element                      Description
  ComCtrlPortIndEndIdx         the end index of the 1:n relation pointing to EthTSyn_ComCtrlPortInd
  ComCtrlPortIndStartIdx       the start index of the 1:n relation pointing to EthTSyn_ComCtrlPortInd
  DestinationMacIndEndIdx      the end index of the 1:n relation pointing to EthTSyn_DestinationMacInd
  DestinationMacIndStartIdx    the start index of the 1:n relation pointing to EthTSyn_DestinationMacInd
  EthIfCtrlIdx                 Index of the underlying EthIf controller.
*/ 
#define ETHTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTSyn_ComCtrlEthIfCtrlType, ETHTSYN_CONST) EthTSyn_ComCtrlEthIfCtrl[1];
#define ETHTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTSyn_ComCtrlPhysPort
**********************************************************************************************************************/
/** 
  \var    EthTSyn_ComCtrlPhysPort
  \brief  Configuration of the physical port.
  \details
  Element              Description
  AlwaysAsCapable      Indicating if the Port is always AsCapable
  UseStaticPdelay      Is static Pdelay value used
  DebounceTimerInit    Initial value of the debounce timer expressed in EthTSyn_MainFunction() cycles.
  InitialPdelayNs      The initially used Pdelay value (this value is also used as static value when (UseStaticPdelay == TRUE))
*/ 
#define ETHTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTSyn_ComCtrlPhysPortType, ETHTSYN_CONST) EthTSyn_ComCtrlPhysPort[1];
#define ETHTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTSyn_ComCtrlPort
**********************************************************************************************************************/
/** 
  \var    EthTSyn_ComCtrlPort
  \brief  Configuration of an EthTSyn Port.
  \details
  Element                  Description
  AnnounceSendSmIdx        the index of the 0:1 relation pointing to EthTSyn_AnnounceSendSm
  ComCtrlEthIfCtrlIdx      the index of the 1:1 relation pointing to EthTSyn_ComCtrlEthIfCtrl
  ComCtrlPhysPortIdx       the index of the 1:1 relation pointing to EthTSyn_ComCtrlPhysPort
  ComCtrlTimeDomainIdx     the index of the 1:1 relation pointing to EthTSyn_ComCtrlTimeDomain
  FramePrio                Frame priority of the EthTSyn Port
  Number                   Number of the EthTSyn Port
  PdReqSmIdx               the index of the 0:1 relation pointing to EthTSyn_PdReqSm
  PdRespSmIdx              the index of the 0:1 relation pointing to EthTSyn_PdRespSm
  PortParamStatsDynIdx     the index of the 0:1 relation pointing to EthTSyn_PortParamStatsDyn
  PortSyncSendSmIdx        the index of the 0:1 relation pointing to EthTSyn_PortSyncSendSm
  SlaveRxDataHandlerIdx    the index of the 0:1 relation pointing to EthTSyn_SlaveRxDataHandler
  SyncSendSmIdx            the index of the 0:1 relation pointing to EthTSyn_SyncSendSm
*/ 
#define ETHTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTSyn_ComCtrlPortType, ETHTSYN_CONST) EthTSyn_ComCtrlPort[1];
#define ETHTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTSyn_ComCtrlPortInd
**********************************************************************************************************************/
/** 
  \var    EthTSyn_ComCtrlPortInd
  \brief  the indexes of the 1:1 sorted relation pointing to EthTSyn_ComCtrlPort
*/ 
#define ETHTSYN_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTSyn_ComCtrlPortIndType, ETHTSYN_CONST) EthTSyn_ComCtrlPortInd[1];
#define ETHTSYN_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTSyn_ComCtrlTimeDomain
**********************************************************************************************************************/
/** 
  \var    EthTSyn_ComCtrlTimeDomain
  \brief  Configuration of a Time Domain.
  \details
  Element                     Description
  ComCtrlPortEndIdx           the end index of the 1:n relation pointing to EthTSyn_ComCtrlPort
  ComCtrlPortStartIdx         the start index of the 1:n relation pointing to EthTSyn_ComCtrlPort
  DestinationMacIdx           the index of the 1:1 relation pointing to EthTSyn_DestinationMac
  Id                          Time Domain Id
  OffsetTimeDomainEndIdx      the end index of the 0:n relation pointing to EthTSyn_OffsetTimeDomain
  OffsetTimeDomainStartIdx    the start index of the 0:n relation pointing to EthTSyn_OffsetTimeDomain
  SynchronizedTimeBaseId      Index of the referenced Synchronized Time Base
*/ 
#define ETHTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTSyn_ComCtrlTimeDomainType, ETHTSYN_CONST) EthTSyn_ComCtrlTimeDomain[1];
#define ETHTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTSyn_DestinationMac
**********************************************************************************************************************/
/** 
  \var    EthTSyn_DestinationMac
  \brief  Destination MAC-Address used for the EthTSyn communication
  \details
  Element    Description
  Byte0      First Byte (MSB) of the destination MAC-Address
  Byte1      Second Byte of the destination MAC-Address
  Byte2      Third Byte of the destination MAC-Address
  Byte3      Fourth Byte of the destination MAC-Address
  Byte4      Fifth Byte of the destination MAC-Address
  Byte5      Sixth Byte (LSB) of the destination MAC-Address
*/ 
#define ETHTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTSyn_DestinationMacType, ETHTSYN_CONST) EthTSyn_DestinationMac[1];
#define ETHTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTSyn_DestinationMacInd
**********************************************************************************************************************/
/** 
  \var    EthTSyn_DestinationMacInd
  \brief  the indexes of the 1:1 sorted relation pointing to EthTSyn_DestinationMac
*/ 
#define ETHTSYN_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTSyn_DestinationMacIndType, ETHTSYN_CONST) EthTSyn_DestinationMacInd[1];
#define ETHTSYN_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTSyn_FupRxHandler
**********************************************************************************************************************/
/** 
  \var    EthTSyn_FupRxHandler
  \brief  Configuration of the FupRxHandler unit
  \details
  Element                    Description
  FupCorrFieldThresholdNs    Max tolerated value in nanoseconds of the correction field for a received FollowUp message
  TimeValidationEnabled      Indicating if time validation is enabled for the slave port
  ComCtrlPortExternalIdx     the index of the 1:1 relation pointing to EthTSyn_ComCtrlPort
  CrcFlagsRxValidated        Flags indicating which message fields should be used for Crc calculation
  CrcHndlIdx                 the index of the 0:1 relation pointing to EthTSyn_CrcHndl
  RxCrcValidated             Crc method for received follow up messages
*/ 
#define ETHTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTSyn_FupRxHandlerType, ETHTSYN_CONST) EthTSyn_FupRxHandler[1];
#define ETHTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTSyn_PdReqSm
**********************************************************************************************************************/
/** 
  \var    EthTSyn_PdReqSm
  \brief  Configuration of the Pdelay request state machine
  \details
  Element                  Description
  PdThreshold              Max allowed/valid value for Pdelay in nanoseconds
  TimeValidationEnabled    Indicating if time validation is enabled for PdReqSm
  LogMsgInterval           The Log message interval of the Pdelay request
  AverageWeight            Weight factor used for weighted average calculation
  ComCtrlPortIdx           the index of the 1:1 relation pointing to EthTSyn_ComCtrlPort
  MaxLostResponses         Max number of Pdelay request cycles without receiving a valid Pdelay response before AsCapable is set to FALSE
  PdReqPeriod              Pdelay request transmission interval in MainFunction cycles
  PdRespTimeout            Pdelay_Resp/Pdelay_Resp_Fup timeout in MainFunction cycles
  TxConfContextIdx         the index of the 1:1 relation pointing to EthTSyn_TxConfContext
*/ 
#define ETHTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTSyn_PdReqSmType, ETHTSYN_CONST) EthTSyn_PdReqSm[1];
#define ETHTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTSyn_PdRespSm
**********************************************************************************************************************/
/** 
  \var    EthTSyn_PdRespSm
  \brief  Configuration of the Pdelay response state machine
  \details
  Element                  Description
  TimeValidationEnabled    Indicating if time validation is enabled for PdRespSm
  ComCtrlPortIdx           the index of the 1:1 relation pointing to EthTSyn_ComCtrlPort
  TxConfContextIdx         the index of the 1:1 relation pointing to EthTSyn_TxConfContext
*/ 
#define ETHTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTSyn_PdRespSmType, ETHTSYN_CONST) EthTSyn_PdRespSm[1];
#define ETHTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTSyn_SlaveRxData
**********************************************************************************************************************/
/** 
  \var    EthTSyn_SlaveRxData
  \brief  Configuration data for the SlaveRx unit
  \details
  Element                            Description
  AnnounceRcvSmIdx                   the index of the 0:1 relation pointing to EthTSyn_AnnounceRcvSm
  SlaveRxMasterClockIdDynIdx         the index of the 0:1 relation pointing to EthTSyn_SlaveRxMasterClockIdDyn
  SlaveRxSrcPortIdCheckClockIdIdx    the index of the 0:1 relation pointing to EthTSyn_SlaveRxSrcPortIdCheckClockId
  SyncRcvSmIdx                       the index of the 1:1 relation pointing to EthTSyn_SyncRcvSm
*/ 
#define ETHTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTSyn_SlaveRxDataType, ETHTSYN_CONST) EthTSyn_SlaveRxData[1];
#define ETHTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTSyn_SlaveRxDataHandler
**********************************************************************************************************************/
/** 
  \var    EthTSyn_SlaveRxDataHandler
  \brief  Handler for the slave rx data of the SlaveRx unit
  \details
  Element                   Description
  ComCtrlPortIdx            the index of the 1:1 relation pointing to EthTSyn_ComCtrlPort
  SlaveRxDataExternalIdx    the index of the 1:1 relation pointing to EthTSyn_SlaveRxData
*/ 
#define ETHTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTSyn_SlaveRxDataHandlerType, ETHTSYN_CONST) EthTSyn_SlaveRxDataHandler[1];
#define ETHTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTSyn_SyncRcvSm
**********************************************************************************************************************/
/** 
  \var    EthTSyn_SyncRcvSm
  \brief  Configuration of the SyncRcvSm
  \details
  Element                 Description
  FollowUpRxTimeout       Allowed delay between reception of a Sync and the corresponding FollowUp message in MainFunction cycles
  FupRxHandlerIdx         the index of the 1:1 relation pointing to EthTSyn_FupRxHandler
  PortParamStatsDynIdx    the index of the 0:1 relation pointing to EthTSyn_PortParamStatsDyn
*/ 
#define ETHTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTSyn_SyncRcvSmType, ETHTSYN_CONST) EthTSyn_SyncRcvSm[1];
#define ETHTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTSyn_TxConfContext
**********************************************************************************************************************/
/** 
  \var    EthTSyn_TxConfContext
  \brief  Configuration of an Tx confirmation context.
  \details
  Element           Description
  ComCtrlPortIdx    the index of the 1:1 relation pointing to EthTSyn_ComCtrlPort
  TxSm              the enum value of the according target of the 1:1 relation pointing to one of EthTSyn_PortSyncSendSm,EthTSyn_PdReqSm,EthTSyn_PdRespSm
  TxSmIdx           the index of the 1:1 relation pointing to one of EthTSyn_PortSyncSendSm,EthTSyn_PdReqSm,EthTSyn_PdRespSm
*/ 
#define ETHTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTSyn_TxConfContextType, ETHTSYN_CONST) EthTSyn_TxConfContext[2];
#define ETHTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTSyn_ComCtrlEthIfCtrlDyn
**********************************************************************************************************************/
/** 
  \var    EthTSyn_ComCtrlEthIfCtrlDyn
  \brief  Variable data related to the underlying EthIf controller. (Size Relation to constant Data: EthTSyn_ComCtrlEthIfCtrl)
  \details
  Element            Description
  ClockId            The PTP Clock Id of the underlying EthIfCtrl
  LinkStateActive    Indicating if link state of the underlying EthIfCtrl is active or not.
  TxActive           Indicating if transmission mode is TX_ON for the underlying EthIfCtrl or not.
*/ 
#define ETHTSYN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTSyn_ComCtrlEthIfCtrlDynType, ETHTSYN_VAR_NO_INIT) EthTSyn_ComCtrlEthIfCtrlDyn[1];
#define ETHTSYN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTSyn_ComCtrlPhysPortDyn
**********************************************************************************************************************/
/** 
  \var    EthTSyn_ComCtrlPhysPortDyn
  \brief  Variable data related to the physical port. (Size Relation to constant Data: EthTSyn_ComCtrlPhysPort)
  \details
  Element          Description
  DebounceTimer    Current value of the debounce timer expressed in EthTSyn_MainFunction() cycles.
  AsCapable        AsCapable Flag
  PdelayValueNs    Current valid Pdelay value
*/ 
#define ETHTSYN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTSyn_ComCtrlPhysPortDynType, ETHTSYN_VAR_NO_INIT) EthTSyn_ComCtrlPhysPortDyn[1];
#define ETHTSYN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTSyn_PdReqSmDyn
**********************************************************************************************************************/
/** 
  \var    EthTSyn_PdReqSmDyn
  \brief  Dynamic data of the Pdelay request state machine (Size Relation to constant Data: EthTSyn_PdReqSm)
  \details
  Element             Description
  RespTimeoutCnt      Pdelay_Resp/PdelayResp_Fup timeout counter: decrement with each main function call
  TxIntervalCnt       Pdelay_Req Tx interval counter: decrement with each main function call
  SequenceId          Sequence id: incremented after every successful Pdelay_Req transmission
  FirstPdelay         Indicates whether the state machine has already calculated a valid Pdelay or not
  LostResponseCnt     Counter for lost responses
  SmResetRequested    Indicates if the Pdelay request state machine must be reset
  State               State of the PdReqSm
  RefGlobalTime       Reference global time retrieved from StbM before Pdelay_Req transmission
  RefLocalTime        Reference local time retrieved from StbM before Pdelay_Req transmission
*/ 
#define ETHTSYN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTSyn_PdReqSmDynType, ETHTSYN_VAR_NO_INIT) EthTSyn_PdReqSmDyn[1];
#define ETHTSYN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTSyn_PdReqTrcvDyn
**********************************************************************************************************************/
/** 
  \var    EthTSyn_PdReqTrcvDyn
  \brief  Dynamic data of the Pdelay request transceiver unit (Size Relation to constant Data: EthTSyn_PdReqSm)
  \details
  Element               Description
  RespClockId           Source clock id of Pdelay_Resp message
  RespPortNum           Source port number of Pdelay_Resp message
  PdReqEgrTsProvided    Indicating if the Pdelay_Req egress timestamp was already provided
  State                 State of the PdReqTrcv unit.
  PdReqEgrTsMgmt        Pdelay_Req egress timestamp with validity information
  PdRespIngrTsMgmt      Pdelay_Resp ingress timestamp with validity information
  ReqReceivedTs         Request receipt timestamp received by Pdelay_Resp
  RespOriginTs          Response origin timestamp received by Pdelay_Resp_Fup
*/ 
#define ETHTSYN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTSyn_PdReqTrcvDynType, ETHTSYN_VAR_NO_INIT) EthTSyn_PdReqTrcvDyn[1];
#define ETHTSYN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTSyn_PdRespSmDyn
**********************************************************************************************************************/
/** 
  \var    EthTSyn_PdRespSmDyn
  \brief  Dynamic data of the Pdelay response state machine (Size Relation to constant Data: EthTSyn_PdRespSm)
  \details
  Element             Description
  RequestorClockId    Source clock identity of the last received valid Pdelay_Req
  RequestorPortNum    Source port number of the last received valid Pdelay_Req
  SequenceId          SequenceId of the current ongoing Pdelay cycle
  SmResetRequested    Indicates if the Pdelay request state machine must be reset
  State               State of the PdRespSm
  PdReqRcvdTs         Ingress timestamp of the last received valid Pdelay_Req
  PdRespOrgTs         Egress timestamp of the last transmitted Pdelay_Resp
*/ 
#define ETHTSYN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTSyn_PdRespSmDynType, ETHTSYN_VAR_NO_INIT) EthTSyn_PdRespSmDyn[1];
#define ETHTSYN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTSyn_SyncRcvSmDyn
**********************************************************************************************************************/
/** 
  \var    EthTSyn_SyncRcvSmDyn
  \brief  Dynamic data of the SyncRcvSm (Size Relation to constant Data: EthTSyn_SyncRcvSm)
  \details
  Element            Description
  SyncSrcClockId     Source clock identity of the received Sync message
  FupRxTimeoutCnt    FollowUp reception timeout counter
  SyncSequenceId     SequenceId of the received Sync message
  SyncSrcPortNum     Source port number of the received Sync message
  AnySyncReceived    Indicating if any Sync message was received by the SyncRcvSm yet
  ResetRequested     Indicating if a reset of the state machine shall be triggered
  State              State of the SyncRcvSm
  SyncRxTimeInfo     Time information of the received Sync message
*/ 
#define ETHTSYN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTSyn_SyncRcvSmDynType, ETHTSYN_VAR_NO_INIT) EthTSyn_SyncRcvSmDyn[1];
#define ETHTSYN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTSyn_TxConfContextDyn
**********************************************************************************************************************/
/** 
  \var    EthTSyn_TxConfContextDyn
  \brief  Variable data related to the Tx confirmation context. (Size Relation to constant Data: EthTSyn_TxConfContext)
  \details
  Element                       Description
  Active                        Indicates if Tx confirmation context is active.
  BufferIdx                     Ethernet Tx buffer currently used by this Tx confirmation context.
  TxConfContextNextActiveIdx    the index of the 0:1 relation pointing to EthTSyn_TxConfContext
  TxConfContextPrevActiveIdx    the index of the 0:1 relation pointing to EthTSyn_TxConfContext
*/ 
#define ETHTSYN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTSyn_TxConfContextDynType, ETHTSYN_VAR_NO_INIT) EthTSyn_TxConfContextDyn[2];
#define ETHTSYN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTSyn_TxConfContextDynActiveFirstIdx
**********************************************************************************************************************/
/** 
  \var    EthTSyn_TxConfContextDynActiveFirstIdx
  \brief  the index of the 0:1 relation pointing to EthTSyn_TxConfContextDyn
*/ 
#define ETHTSYN_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTSyn_TxConfContextDynActiveFirstIdxType, ETHTSYN_VAR_NO_INIT) EthTSyn_TxConfContextDynActiveFirstIdx;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTSYN_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTSyn_TxConfContextDynActiveLastIdx
**********************************************************************************************************************/
/** 
  \var    EthTSyn_TxConfContextDynActiveLastIdx
  \brief  the index of the 0:1 relation pointing to EthTSyn_TxConfContextDyn
*/ 
#define ETHTSYN_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EthTSyn_TxConfContextDynActiveLastIdxType, ETHTSYN_VAR_NO_INIT) EthTSyn_TxConfContextDynActiveLastIdx;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define ETHTSYN_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EthTSyn_PCConfig
**********************************************************************************************************************/
/** 
  \var    EthTSyn_PCConfig
  \details
  Element                               Description
  AnnounceRcvSm                         the pointer to EthTSyn_AnnounceRcvSm
  AnnounceRcvSmDyn                      the pointer to EthTSyn_AnnounceRcvSmDyn
  AnnounceSendSm                        the pointer to EthTSyn_AnnounceSendSm
  AnnounceSendSmDyn                     the pointer to EthTSyn_AnnounceSendSmDyn
  BridgeTxMasterPort                    the pointer to EthTSyn_BridgeTxMasterPort
  BridgeTxMasterPortDyn                 the pointer to EthTSyn_BridgeTxMasterPortDyn
  ComCtrlEthIfCtrl                      the pointer to EthTSyn_ComCtrlEthIfCtrl
  ComCtrlEthIfCtrlDyn                   the pointer to EthTSyn_ComCtrlEthIfCtrlDyn
  ComCtrlPhysPort                       the pointer to EthTSyn_ComCtrlPhysPort
  ComCtrlPhysPortDyn                    the pointer to EthTSyn_ComCtrlPhysPortDyn
  ComCtrlPort                           the pointer to EthTSyn_ComCtrlPort
  ComCtrlPortInd                        the pointer to EthTSyn_ComCtrlPortInd
  ComCtrlTimeDomain                     the pointer to EthTSyn_ComCtrlTimeDomain
  CrcHndl                               the pointer to EthTSyn_CrcHndl
  DestinationMac                        the pointer to EthTSyn_DestinationMac
  DestinationMacInd                     the pointer to EthTSyn_DestinationMacInd
  FupDataIdList                         the pointer to EthTSyn_FupDataIdList
  FupRxHandler                          the pointer to EthTSyn_FupRxHandler
  MsgSentCbkBuf                         the pointer to EthTSyn_MsgSentCbkBuf
  OffsetTimeDomain                      the pointer to EthTSyn_OffsetTimeDomain
  PdReqSm                               the pointer to EthTSyn_PdReqSm
  PdReqSmDyn                            the pointer to EthTSyn_PdReqSmDyn
  PdReqTrcvDyn                          the pointer to EthTSyn_PdReqTrcvDyn
  PdRespSm                              the pointer to EthTSyn_PdRespSm
  PdRespSmDyn                           the pointer to EthTSyn_PdRespSmDyn
  PortParamStatsDyn                     the pointer to EthTSyn_PortParamStatsDyn
  PortSyncSendSm                        the pointer to EthTSyn_PortSyncSendSm
  PortSyncSendSmDyn                     the pointer to EthTSyn_PortSyncSendSmDyn
  RateMeas                              the pointer to EthTSyn_RateMeas
  RateMeasBuf                           the pointer to EthTSyn_RateMeasBuf
  RateMeasDyn                           the pointer to EthTSyn_RateMeasDyn
  SiteSyncSyncTx                        the pointer to EthTSyn_SiteSyncSyncTx
  SiteSyncSyncTxDyn                     the pointer to EthTSyn_SiteSyncSyncTxDyn
  SlaveRxData                           the pointer to EthTSyn_SlaveRxData
  SlaveRxDataHandler                    the pointer to EthTSyn_SlaveRxDataHandler
  SlaveRxMasterClockIdDyn               the pointer to EthTSyn_SlaveRxMasterClockIdDyn
  SlaveRxSrcPortIdCheckClockId          the pointer to EthTSyn_SlaveRxSrcPortIdCheckClockId
  SlaveSwitchIdxList                    the pointer to EthTSyn_SlaveSwitchIdxList
  SwtTimeSyncSm                         the pointer to EthTSyn_SwtTimeSyncSm
  SwtTimeSyncSmDyn                      the pointer to EthTSyn_SwtTimeSyncSmDyn
  SyncRcvSm                             the pointer to EthTSyn_SyncRcvSm
  SyncRcvSmDyn                          the pointer to EthTSyn_SyncRcvSmDyn
  SyncSendSm                            the pointer to EthTSyn_SyncSendSm
  SyncSendSmDyn                         the pointer to EthTSyn_SyncSendSmDyn
  TimeBaseUpdateCounter                 the pointer to EthTSyn_TimeBaseUpdateCounter
  TimeBaseUpdateCounterDyn              the pointer to EthTSyn_TimeBaseUpdateCounterDyn
  TxConfContext                         the pointer to EthTSyn_TxConfContext
  TxConfContextDyn                      the pointer to EthTSyn_TxConfContextDyn
  TxConfContextDynActiveFirstIdx        the pointer to EthTSyn_TxConfContextDynActiveFirstIdx
  TxConfContextDynActiveLastIdx         the pointer to EthTSyn_TxConfContextDynActiveLastIdx
  SizeOfAnnounceRcvSm                   the number of accomplishable value elements in EthTSyn_AnnounceRcvSm
  SizeOfAnnounceSendSm                  the number of accomplishable value elements in EthTSyn_AnnounceSendSm
  SizeOfBridgeTxMasterPort              the number of accomplishable value elements in EthTSyn_BridgeTxMasterPort
  SizeOfComCtrlEthIfCtrl                the number of accomplishable value elements in EthTSyn_ComCtrlEthIfCtrl
  SizeOfComCtrlPhysPort                 the number of accomplishable value elements in EthTSyn_ComCtrlPhysPort
  SizeOfComCtrlPort                     the number of accomplishable value elements in EthTSyn_ComCtrlPort
  SizeOfComCtrlPortInd                  the number of accomplishable value elements in EthTSyn_ComCtrlPortInd
  SizeOfComCtrlTimeDomain               the number of accomplishable value elements in EthTSyn_ComCtrlTimeDomain
  SizeOfCrcHndl                         the number of accomplishable value elements in EthTSyn_CrcHndl
  SizeOfDestinationMac                  the number of accomplishable value elements in EthTSyn_DestinationMac
  SizeOfDestinationMacInd               the number of accomplishable value elements in EthTSyn_DestinationMacInd
  SizeOfFupDataIdList                   the number of accomplishable value elements in EthTSyn_FupDataIdList
  SizeOfFupRxHandler                    the number of accomplishable value elements in EthTSyn_FupRxHandler
  SizeOfMsgSentCbkBuf                   the number of accomplishable value elements in EthTSyn_MsgSentCbkBuf
  SizeOfOffsetTimeDomain                the number of accomplishable value elements in EthTSyn_OffsetTimeDomain
  SizeOfPdReqSm                         the number of accomplishable value elements in EthTSyn_PdReqSm
  SizeOfPdRespSm                        the number of accomplishable value elements in EthTSyn_PdRespSm
  SizeOfPortParamStatsDyn               the number of accomplishable value elements in EthTSyn_PortParamStatsDyn
  SizeOfPortSyncSendSm                  the number of accomplishable value elements in EthTSyn_PortSyncSendSm
  SizeOfRateMeas                        the number of accomplishable value elements in EthTSyn_RateMeas
  SizeOfRateMeasBuf                     the number of accomplishable value elements in EthTSyn_RateMeasBuf
  SizeOfSiteSyncSyncTx                  the number of accomplishable value elements in EthTSyn_SiteSyncSyncTx
  SizeOfSlaveRxData                     the number of accomplishable value elements in EthTSyn_SlaveRxData
  SizeOfSlaveRxDataHandler              the number of accomplishable value elements in EthTSyn_SlaveRxDataHandler
  SizeOfSlaveRxMasterClockIdDyn         the number of accomplishable value elements in EthTSyn_SlaveRxMasterClockIdDyn
  SizeOfSlaveRxSrcPortIdCheckClockId    the number of accomplishable value elements in EthTSyn_SlaveRxSrcPortIdCheckClockId
  SizeOfSlaveSwitchIdxList              the number of accomplishable value elements in EthTSyn_SlaveSwitchIdxList
  SizeOfSwtTimeSyncSm                   the number of accomplishable value elements in EthTSyn_SwtTimeSyncSm
  SizeOfSyncRcvSm                       the number of accomplishable value elements in EthTSyn_SyncRcvSm
  SizeOfSyncSendSm                      the number of accomplishable value elements in EthTSyn_SyncSendSm
  SizeOfTimeBaseUpdateCounter           the number of accomplishable value elements in EthTSyn_TimeBaseUpdateCounter
  SizeOfTxConfContext                   the number of accomplishable value elements in EthTSyn_TxConfContext
*/ 
#define ETHTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EthTSyn_PCConfigsType, ETHTSYN_CONST) EthTSyn_PCConfig;
#define ETHTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES (NOT COMSTACKLIB GENERATED)
**********************************************************************************************************************/
/**********************************************************************************************************************
  EthTSyn_ConfigDataPtr
**********************************************************************************************************************/
/** 
  \var    EthTSyn_ConfigDataPtr
  \brief  Points to the currently active configuration for EthTSyn
  \details
  Pointer is intialized during EthTSyn_Init() and holds the active configuration for EthTSyn were all configuration data
  is retrieved from during runtime.
*/ 
#define ETHTSYN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
/*!
 * \spec strong invariant EthTSyn_ConfigDataPtr == &EthTSyn_PCConfig.Config;
 * \endspec
 */
extern P2CONST(EthTSyn_ConfigType, ETHTSYN_VAR_NO_INIT, ETHTSYN_INIT_DATA) EthTSyn_ConfigDataPtr;
#define ETHTSYN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EthTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#endif  /* ETHTSYN_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: EthTSyn_Lcfg.h
 *********************************************************************************************************************/

