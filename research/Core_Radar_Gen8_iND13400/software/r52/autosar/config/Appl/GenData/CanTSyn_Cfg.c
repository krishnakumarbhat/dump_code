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
 *            Module: CanTSyn
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanTSyn_Cfg.c
 *   Generation Time: 2026-05-14 15:33:04
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

#define CANTSYN_CFG_SOURCE

/**********************************************************************************************************************
 *  LOCAL MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "CanTSyn.h"
#include "StbM.h"

#include "CanIf.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
 
/* Dummy define for partition name in non multi-core/multi-partition context */
# define CANTSYN_SINGLEPARTITION                           (0u)

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
 *  LOCAL DATA
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanTSyn_ControllerInfo
**********************************************************************************************************************/
/** 
  \var    CanTSyn_ControllerInfo
  \brief  Referenced controller info.
  \details
  Element    Description
  Snv        Symbolic Name Value of the referenced controller
*/ 
#define CANTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTSyn_ControllerInfoType, CANTSYN_CONST) CanTSyn_ControllerInfo[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Snv                                                  Referable Keys */
  { /*     0 */ CanIfConf_CanIfCtrlCfg_CT_PCAN_RADAR_a3a0f56c }   /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg/CT_PCAN_RADAR_a3a0f56c] */
};
#define CANTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_DomainConfigRDR_01
**********************************************************************************************************************/
/** 
  \var    CanTSyn_DomainConfigRDR_01
  \brief  Table containing data about the time domain.
  \details
  Element                   Description
  CrcAndDomainType          Indicates if this domain supports crc if it contains a master that supports txCrc.
  DomainId                  Domain Id
  FupDataIDListEndIdx       the end index of the 0:n relation pointing to CanTSyn_FupDataIDList
  FupDataIDListStartIdx     the start index of the 0:n relation pointing to CanTSyn_FupDataIDList
  MasterConfigEndIdx        the end index of the 0:n relation pointing to CanTSyn_MasterConfig
  MasterConfigLength        the number of relations pointing to CanTSyn_MasterConfig
  MasterConfigStartIdx      the start index of the 0:n relation pointing to CanTSyn_MasterConfig
  MessageDlc                Indicates if the Extended Message Format for CAN-FD is used.
  OffsetDomain              Indicates if this domain sends offset messages.
  SlaveConfigIdx            the index of the 0:1 relation pointing to CanTSyn_SlaveConfig
  SyncDataIDListEndIdx      the end index of the 0:n relation pointing to CanTSyn_SyncDataIDList
  SyncDataIDListStartIdx    the start index of the 0:n relation pointing to CanTSyn_SyncDataIDList
  TimeBaseId                Mandatory reference to the required synchronized time-base.
*/ 
#define CANTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTSyn_DomainConfigType, CANTSYN_CONST) CanTSyn_DomainConfigRDR_01[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    CrcAndDomainType                                     DomainId  FupDataIDListEndIdx                                                     FupDataIDListStartIdx                                                     MasterConfigEndIdx                                                                              MasterConfigLength                                                     MasterConfigStartIdx                                                                              MessageDlc  OffsetDomain                                   SlaveConfigIdx                                                     SyncDataIDListEndIdx                                                     SyncDataIDListStartIdx                                                     TimeBaseId                                                                 Referable Keys */
  { /*     0 */ CANTSYN_NOT_CRC_SYNC_CRCANDDOMAINTYPEOFDOMAINCONFIG,       1u,                 16u  /* /ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain */,                    0u  /* /ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain */, CANTSYN_NO_MASTERCONFIGENDIDXOFDOMAINCONFIG  /* /ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain */,                 0u  /* /ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain */, CANTSYN_NO_MASTERCONFIGSTARTIDXOFDOMAINCONFIG  /* /ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain */,         8u, CANTSYN_NOT_OFFSET_OFFSETDOMAINOFDOMAINCONFIG,             0u  /* /ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain */,                  16u  /* /ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain */,                     0u  /* /ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain */, StbMConf_StbMSynchronizedTimeBase_StbMSynchronizedTimeBase_CanTsync }   /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
};
#define CANTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_DomainConfigRDR_05
**********************************************************************************************************************/
/** 
  \var    CanTSyn_DomainConfigRDR_05
  \brief  Table containing data about the time domain.
  \details
  Element                   Description
  CrcAndDomainType          Indicates if this domain supports crc if it contains a master that supports txCrc.
  DomainId                  Domain Id
  FupDataIDListEndIdx       the end index of the 0:n relation pointing to CanTSyn_FupDataIDList
  FupDataIDListStartIdx     the start index of the 0:n relation pointing to CanTSyn_FupDataIDList
  MasterConfigEndIdx        the end index of the 0:n relation pointing to CanTSyn_MasterConfig
  MasterConfigLength        the number of relations pointing to CanTSyn_MasterConfig
  MasterConfigStartIdx      the start index of the 0:n relation pointing to CanTSyn_MasterConfig
  MessageDlc                Indicates if the Extended Message Format for CAN-FD is used.
  OffsetDomain              Indicates if this domain sends offset messages.
  SlaveConfigIdx            the index of the 0:1 relation pointing to CanTSyn_SlaveConfig
  SyncDataIDListEndIdx      the end index of the 0:n relation pointing to CanTSyn_SyncDataIDList
  SyncDataIDListStartIdx    the start index of the 0:n relation pointing to CanTSyn_SyncDataIDList
  TimeBaseId                Mandatory reference to the required synchronized time-base.
*/ 
#define CANTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTSyn_DomainConfigType, CANTSYN_CONST) CanTSyn_DomainConfigRDR_05[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CrcAndDomainType                                 DomainId  FupDataIDListEndIdx                                                     FupDataIDListStartIdx                                                     MasterConfigEndIdx                                                     MasterConfigLength                                                     MasterConfigStartIdx                                                     MessageDlc  OffsetDomain                                   SlaveConfigIdx                                                                              SyncDataIDListEndIdx                                                     SyncDataIDListStartIdx                                                     TimeBaseId                                                                 Referable Keys */
  { /*     0 */ CANTSYN_CRC_SYNC_CRCANDDOMAINTYPEOFDOMAINCONFIG,       1u,                 16u  /* /ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain */,                    0u  /* /ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain */,                 1u  /* /ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain */,                 1u  /* /ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain */,                   0u  /* /ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain */,         8u, CANTSYN_NOT_OFFSET_OFFSETDOMAINOFDOMAINCONFIG, CANTSYN_NO_SLAVECONFIGIDXOFDOMAINCONFIG  /* /ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain */,                  16u  /* /ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain */,                     0u  /* /ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain */, StbMConf_StbMSynchronizedTimeBase_StbMSynchronizedTimeBase_CanTsync }   /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
};
#define CANTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_FupDataIDList
**********************************************************************************************************************/
/** 
  \var    CanTSyn_FupDataIDList
  \brief  Element of the DataIDList for FUP/OFNS messages ensures the identification of data elements due to CRC calculation process.
*/ 
#define CANTSYN_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTSyn_FupDataIDListType, CANTSYN_CONST) CanTSyn_FupDataIDList[16] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     FupDataIDList      Referable Keys */
  /*     0 */           149u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*     1 */           178u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*     2 */            48u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*     3 */            27u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*     4 */            29u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*     5 */           185u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*     6 */            17u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*     7 */           203u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*     8 */           148u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*     9 */            68u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*    10 */           204u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*    11 */            36u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*    12 */           101u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*    13 */           195u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*    14 */            44u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*    15 */            16u   /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
};
#define CANTSYN_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_MasterConfig
**********************************************************************************************************************/
/** 
  \var    CanTSyn_MasterConfig
  \brief  Contains configuration parameters of masters.
  \details
  Element                 Description
  ControllerInfoIdx       the index of the 1:1 relation pointing to CanTSyn_ControllerInfo
  CyclicMsgResumeTime     Defines the time where the 1st regular cycle time based message transmission takes place, after an immediate transmission before.
  DebounceTime            This represents the configuration of a Tx debounce time for SYNC, FUP, OFS and OFNS messages compared to a message before with the same PDU.
  DomainConfigIdx         the index of the 1:1 relation pointing to CanTSyn_DomainConfig
  FupMessageType          This provides information about whether or not the FUP/OFNS message is CRC secured.
  ImmediateTimeSync       Enables/Disables the cyclic polling of StbM_GetTimeBaseUpdateCounter() within CanTSyn_MainFunction().
  MasterConfHandleId      This represents the handle ID of the PDU that contains the global time information.
  MasterConfTimeout       This represents the confirmation timeout after transmission of a message.
  MessageDomainId         This contains the domain ID to which the message belongs.
  PartitionConfigIdx      the index of the 1:1 relation pointing to CanTSyn_PCPartitionConfig
  PduIdStatesIdx          the index of the 1:1 relation pointing to CanTSyn_PduIdStates
  SyncMessageType         This provides information about whether or not the SYNC/OFS message is CRC secured.
  TxCrcSecured            CRC is supported or not.
  TxDebounceCounterIdx    the index of the 0:1 relation pointing to CanTSyn_TxDebounceCounter
  TxPduId                 This represents the ID of the Pdu taken to transmit the global time information.
  TxPeriod                This represents configuration of the Tx period.
*/ 
#define CANTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTSyn_MasterConfigType, CANTSYN_CONST) CanTSyn_MasterConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ControllerInfoIdx                                                                  CyclicMsgResumeTime  DebounceTime  DomainConfigIdx                                                     FupMessageType                          ImmediateTimeSync                                      MasterConfHandleId                                                 MasterConfTimeout  MessageDomainId  PartitionConfigIdx                                 PduIdStatesIdx                                                                                                      SyncMessageType                          TxCrcSecured                                 TxDebounceCounterIdx                                                                                      TxPduId                                                        TxPeriod        Referable Keys */
  { /*     0 */                0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg/CT_PCAN_RADAR_a3a0f56c */,                  0u,           1u,              0u  /* /ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain */, CANTSYN_TIME_SYNC_MESSAGE_TYPE_FUP_CRC, CANTSYN_NOT_SUPPORTED_IMMEDIATETIMESYNCOFMASTERCONFIG, CanTSynConf_CanTSynGlobalTimeMasterPdu_CanTSynGlobalTimeMasterPdu,              100u,              1u,                 0u  /* CANTSYN_SINGLEPARTITION */,             0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/SYS_TIME_SYNC_oPCAN_RADAR_231d6bb9_Tx[0:CanIfTxPduId]{RDR_05} */, CANTSYN_TIME_SYNC_MESSAGE_TYPE_SYNC_CRC, CANTSYN_SYNC_CRC_TXCRCSECUREDOFMASTERCONFIG,                   0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/SYS_TIME_SYNC_oPCAN_RADAR_231d6bb9_Tx{RDR_05} */, CanIfConf_CanIfTxPduCfg_SYS_TIME_SYNC_oPCAN_RADAR_231d6bb9_Tx,     100u }   /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
};
#define CANTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    CanTSyn_PartitionIdentifiers
  \brief  the partition context in Config_RDR_01
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to CanTSyn_PCPartitionConfig
*/ 
#define CANTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTSyn_PartitionIdentifiersType, CANTSYN_CONST) CanTSyn_PartitionIdentifiers[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionSNV             PCPartitionConfigIdx                                */
  { /*     0 */ CANTSYN_SINGLEPARTITION,                   0u  /* CANTSYN_SINGLEPARTITION */ }
};
#define CANTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_SlaveConfig
**********************************************************************************************************************/
/** 
  \var    CanTSyn_SlaveConfig
  \brief  Contains configuration parameters of slave.
  \details
  Element                     Description
  DomainConfigIdx             the index of the 1:1 relation pointing to CanTSyn_DomainConfig
  FollowUpTimeout             Rx timeout for the follow-up message. This is only relevant for selected bus systems.
  PartitionConfigIdx          the index of the 1:1 relation pointing to CanTSyn_PCPartitionConfig
  RxCrcValidated              Validation of the CRC is supported or not
  SequenceCounterJumpWidth    The SequenceCounterJumpWidth specifies the maximum allowed gap of the sequence counter between two SYNC resp. two OFS messages.
  SlaveHandleId               This represents the handle ID of the PDU that contains the global time information.
*/ 
#define CANTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTSyn_SlaveConfigType, CANTSYN_CONST) CanTSyn_SlaveConfig[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    DomainConfigIdx                                                     FollowUpTimeout  PartitionConfigIdx                                 RxCrcValidated                                 SequenceCounterJumpWidth  SlaveHandleId                                                          Referable Keys */
  { /*     0 */              0u  /* /ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain */,            100u,                 0u  /* CANTSYN_SINGLEPARTITION */, CANTSYN_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG,                       1u, CanTSynConf_CanTSynGlobalTimeSlavePdu_CanTSynGlobalTimeSlavePdu }   /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
};
#define CANTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_SyncDataIDList
**********************************************************************************************************************/
/** 
  \var    CanTSyn_SyncDataIDList
  \brief  Element of the DataIDList for SYNC/OFS messages ensures the identification of data elements due to CRC calculation process.
*/ 
#define CANTSYN_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTSyn_SyncDataIDListType, CANTSYN_CONST) CanTSyn_SyncDataIDList[16] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     SyncDataIDList      Referable Keys */
  /*     0 */            246u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*     1 */             35u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*     2 */             39u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*     3 */             72u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*     4 */             84u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*     5 */            175u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*     6 */            138u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*     7 */            251u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*     8 */             13u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*     9 */            135u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*    10 */            106u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*    11 */             15u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*    12 */             71u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*    13 */            120u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*    14 */             49u,  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /*    15 */             79u   /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
};
#define CANTSYN_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_Initialized
**********************************************************************************************************************/
/** 
  \var    CanTSyn_Initialized
  \brief  Initialization state of the CanTSyn. TRUE, if CanTSyn_Init() has been called, else FALSE.
*/ 
#define CANTSYN_START_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanTSyn_InitializedType, CANTSYN_VAR_CLEARED) CanTSyn_Initialized;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANTSYN_STOP_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_MasterState
**********************************************************************************************************************/
/** 
  \var    CanTSyn_MasterState
  \brief  Contains variables of masters.
  \details
  Element                         Description
  CyclicMsgResumeCounter          Count of number of cyclic time bases transmissions.
  TxConfirmationTimeoutCounter    Count of confirmation timeout after each transmission.
  TxPeriodCounter                 Counter for TxPeriod.
  LastUpdateCounter               The value of the time base update counter that is retrieved from StbM can be stored in here in order to compare it to the next current update counter.
  TransmitImmediateSync           True if next Sync message is sent in immediate mode.
  TxSequenceCounter               Sequence counter for Tx messages.
  FupTimeStamp                    This represents the time stamp of follow up message from StbM.
  State                           State of the master.
  SyncTimestamp                   This represents the synchronized time stamp from StbM.
  TimeBaseStatus                  This represents the time base status value from StbM.
  UserData                        This represents the user data retrieved from StbM.
  VirtualLocalTime                This represents Virtual Local Time value from StbM.
*/ 
#define CANTSYN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanTSyn_MasterStateType, CANTSYN_VAR_NO_INIT) CanTSyn_MasterState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */

#define CANTSYN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_PduIdStates
**********************************************************************************************************************/
#define CANTSYN_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanTSyn_PduIdStatesType, CANTSYN_VAR_NO_INIT) CanTSyn_PduIdStates[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SYS_TIME_SYNC_oPCAN_RADAR_231d6bb9_Tx[0:CanIfTxPduId]{RDR_05}] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */

#define CANTSYN_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_SlaveState
**********************************************************************************************************************/
/** 
  \var    CanTSyn_SlaveState
  \details
  Element                   Description
  RxFollowUpTimeoutCount    Count of number of Rx timeouts for follow-up messages.
  RxSequenceCounter         Sequence counter for Rx messages.
  State                     State of the slave
  SyncMsg                   This represents the synchronized message type.
  VirtualLocalTime          This represents Virtual Local Time value from StbM.
*/ 
#define CANTSYN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanTSyn_SlaveStateType, CANTSYN_VAR_NO_INIT) CanTSyn_SlaveState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */  /* [/ActiveEcuC/CanTSyn/CanTSynGlobalTimeDomain] */

#define CANTSYN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_TransmissionControllerState
**********************************************************************************************************************/
/** 
  \var    CanTSyn_TransmissionControllerState
  \brief  State of the transmission. 1u = CANTSYN_TX_ON, 0u = CANTSYN_TX_OFF.
*/ 
#define CANTSYN_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanTSyn_TransmissionModeType, CANTSYN_VAR_NO_INIT) CanTSyn_TransmissionControllerState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg/CT_PCAN_RADAR_a3a0f56c] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */

#define CANTSYN_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_TxDebounceCounter
**********************************************************************************************************************/
/** 
  \var    CanTSyn_TxDebounceCounter
  \brief  Current counter value for debouncing.
*/ 
#define CANTSYN_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanTSyn_TxDebounceCounterType, CANTSYN_VAR_NO_INIT) CanTSyn_TxDebounceCounter[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RDR_01 */
  /*     0 */
  /* Index        Referable Keys   RDR_02 */
  /*     0 */
  /* Index        Referable Keys   RDR_03 */
  /*     0 */
  /* Index        Referable Keys   RDR_04 */
  /*     0 */
  /* Index        Referable Keys   RDR_05 */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/SYS_TIME_SYNC_oPCAN_RADAR_231d6bb9_Tx{RDR_05}] */
  /* Index        Referable Keys   RDR_06 */
  /*     0 */
  /* Index        Referable Keys   RDR_07 */
  /*     0 */
  /* Index        Referable Keys   RDR_08 */
  /*     0 */

#define CANTSYN_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_PCConfig
**********************************************************************************************************************/
/** 
  \var    CanTSyn_PCConfig
  \details
  Element              Description
  PCPartitionConfig    the pointer to CanTSyn_PCPartitionConfig
*/ 
#define CANTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTSyn_PCConfigsType, CANTSYN_CONST) CanTSyn_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config_RDR_01] */
      CanTSyn_PCPartitionConfigRDR_01  /**< the pointer to CanTSyn_PCPartitionConfig in Config_RDR_01 */
  },
  { /* Index: 1 Keys: [Config_RDR_02] */
      CanTSyn_PCPartitionConfigRDR_01  /**< the pointer to CanTSyn_PCPartitionConfig in Config_RDR_02 */
  },
  { /* Index: 2 Keys: [Config_RDR_03] */
      CanTSyn_PCPartitionConfigRDR_01  /**< the pointer to CanTSyn_PCPartitionConfig in Config_RDR_03 */
  },
  { /* Index: 3 Keys: [Config_RDR_04] */
      CanTSyn_PCPartitionConfigRDR_01  /**< the pointer to CanTSyn_PCPartitionConfig in Config_RDR_04 */
  },
  { /* Index: 4 Keys: [Config_RDR_05] */
      CanTSyn_PCPartitionConfigRDR_05  /**< the pointer to CanTSyn_PCPartitionConfig in Config_RDR_05 */
  },
  { /* Index: 5 Keys: [Config_RDR_06] */
      CanTSyn_PCPartitionConfigRDR_01  /**< the pointer to CanTSyn_PCPartitionConfig in Config_RDR_06 */
  },
  { /* Index: 6 Keys: [Config_RDR_07] */
      CanTSyn_PCPartitionConfigRDR_01  /**< the pointer to CanTSyn_PCPartitionConfig in Config_RDR_07 */
  },
  { /* Index: 7 Keys: [Config_RDR_08] */
      CanTSyn_PCPartitionConfigRDR_01  /**< the pointer to CanTSyn_PCPartitionConfig in Config_RDR_08 */
  }
};
#define CANTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_PCPartitionConfigRDR_01
**********************************************************************************************************************/
/** 
  \var    CanTSyn_PCPartitionConfigRDR_01
  \details
  Element                        Description
  ControllerInfo                 the pointer to CanTSyn_ControllerInfo
  DomainConfig                   the pointer to CanTSyn_DomainConfig
  MasterConfig                   the pointer to CanTSyn_MasterConfig
  PduIdStates                    the pointer to CanTSyn_PduIdStates
  SlaveConfig                    the pointer to CanTSyn_SlaveConfig
  TransmissionControllerState    the pointer to CanTSyn_TransmissionControllerState
  TxDebounceCounter              the pointer to CanTSyn_TxDebounceCounter
  SizeOfControllerInfo           the number of accomplishable value elements in CanTSyn_ControllerInfo
  SizeOfMasterConfig             the number of accomplishable value elements in CanTSyn_MasterConfig
  SizeOfPduIdStates              the number of accomplishable value elements in CanTSyn_PduIdStates
  SizeOfSlaveConfig              the number of accomplishable value elements in CanTSyn_SlaveConfig
  SizeOfTxDebounceCounter        the number of accomplishable value elements in CanTSyn_TxDebounceCounter
*/ 
#define CANTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTSyn_PCPartitionConfigType, CANTSYN_CONST) CanTSyn_PCPartitionConfigRDR_01[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [CANTSYN_SINGLEPARTITION] */
      NULL_PTR                     /**< the struct is deactivated because all elements are deactivated. */
    , CanTSyn_DomainConfigRDR_01   /**< the pointer to CanTSyn_DomainConfig in Config_RDR_01 */
    , NULL_PTR                     /**< the struct is deactivated because all elements are deactivated. */
    , NULL_PTR                     /**< the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE */
    , CanTSyn_SlaveConfig          /**< the pointer to CanTSyn_SlaveConfig in Config_RDR_01 */
    , NULL_PTR                     /**< the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE */
    , NULL_PTR                     /**< the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE */
    , 0u                           /**< the number of elements in CanTSyn_ControllerInfo in Config_RDR_01 */
    , 0u                           /**< the number of elements in CanTSyn_MasterConfig in Config_RDR_01 */
    , 0u                           /**< the number of elements in CanTSyn_PduIdStates in Config_RDR_01 */
    , 1u                           /**< the number of elements in CanTSyn_SlaveConfig in Config_RDR_01 */
    , 0u                           /**< the number of elements in CanTSyn_TxDebounceCounter in Config_RDR_01 */
  }
};
#define CANTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_PCPartitionConfigRDR_05
**********************************************************************************************************************/
/** 
  \var    CanTSyn_PCPartitionConfigRDR_05
  \details
  Element                        Description
  ControllerInfo                 the pointer to CanTSyn_ControllerInfo
  DomainConfig                   the pointer to CanTSyn_DomainConfig
  MasterConfig                   the pointer to CanTSyn_MasterConfig
  PduIdStates                    the pointer to CanTSyn_PduIdStates
  SlaveConfig                    the pointer to CanTSyn_SlaveConfig
  TransmissionControllerState    the pointer to CanTSyn_TransmissionControllerState
  TxDebounceCounter              the pointer to CanTSyn_TxDebounceCounter
  SizeOfControllerInfo           the number of accomplishable value elements in CanTSyn_ControllerInfo
  SizeOfMasterConfig             the number of accomplishable value elements in CanTSyn_MasterConfig
  SizeOfPduIdStates              the number of accomplishable value elements in CanTSyn_PduIdStates
  SizeOfSlaveConfig              the number of accomplishable value elements in CanTSyn_SlaveConfig
  SizeOfTxDebounceCounter        the number of accomplishable value elements in CanTSyn_TxDebounceCounter
*/ 
#define CANTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTSyn_PCPartitionConfigType, CANTSYN_CONST) CanTSyn_PCPartitionConfigRDR_05[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [CANTSYN_SINGLEPARTITION] */
      CanTSyn_ControllerInfo               /**< the pointer to CanTSyn_ControllerInfo in Config_RDR_05 */
    , CanTSyn_DomainConfigRDR_05           /**< the pointer to CanTSyn_DomainConfig in Config_RDR_05 */
    , CanTSyn_MasterConfig                 /**< the pointer to CanTSyn_MasterConfig in Config_RDR_05 */
    , CanTSyn_PduIdStates                  /**< the pointer to CanTSyn_PduIdStates in Config_RDR_05 */
    , NULL_PTR                             /**< the struct is deactivated because all elements are deactivated. */
    , CanTSyn_TransmissionControllerState  /**< the pointer to CanTSyn_TransmissionControllerState in Config_RDR_05 */
    , CanTSyn_TxDebounceCounter            /**< the pointer to CanTSyn_TxDebounceCounter in Config_RDR_05 */
    , 1u                                   /**< the number of elements in CanTSyn_ControllerInfo in Config_RDR_05 */
    , 1u                                   /**< the number of elements in CanTSyn_MasterConfig in Config_RDR_05 */
    , 1u                                   /**< the number of elements in CanTSyn_PduIdStates in Config_RDR_05 */
    , 0u                                   /**< the number of elements in CanTSyn_SlaveConfig in Config_RDR_05 */
    , 1u                                   /**< the number of elements in CanTSyn_TxDebounceCounter in Config_RDR_05 */
  }
};
#define CANTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



#define CANTSYN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "CanTSyn_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

VAR(boolean, CANTSYN_VAR_NO_INIT) CanTSyn_PreInitialized;

#define CANTSYN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "CanTSyn_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */


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
 *  END OF FILE: CanTSyn_Cfg.c
 *********************************************************************************************************************/
