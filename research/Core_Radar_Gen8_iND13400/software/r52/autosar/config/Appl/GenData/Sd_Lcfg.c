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
 *            Module: Sd
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Sd_Lcfg.c
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
#define SD_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/* PRQA S 0857 MACRO_LIMIT */ /* MD_MSR_1.1_857 */
#include "Sd.h"
#include "Sd_Priv.h"
# include "Sd_Lcfg.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if defined (STATIC)
#else
# define STATIC static
#endif

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
  Sd_Client
**********************************************************************************************************************/
/** 
  \var    Sd_Client
  \brief  Configuration data of SdClientService. List is sorted by ServiceId (and HandleId if ServiceId is not unique) per SdInstance.
  \details
  Element                                  Description
  ServiceId                                Service ID
  AutoRequire                              Auto require flag
  MinorVersionWildcard                     Indicates if MinorVersion is configured to wildcard.
  ServiceGroupMember                       Specifies if service is member of a ServiceGroup.
  UdpClientMulticast                       Specifies if CEG of service use UDP ClientMulticast or UDP Unicast.
  AclIPv4CIndEndIdx                        the end index of the 0:n relation pointing to Sd_AclIPv4CInd
  AclIPv4CIndStartIdx                      the start index of the 0:n relation pointing to Sd_AclIPv4CInd
  AclIPv6CIndEndIdx                        the end index of the 0:n relation pointing to Sd_AclIPv6CInd
  AclIPv6CIndStartIdx                      the start index of the 0:n relation pointing to Sd_AclIPv6CInd
  CapabilityRecordEndIdx                   the end index of the 0:n relation pointing to Sd_CapabilityRecord
  CapabilityRecordFunctionCalloutPtrIdx    the index of the 0:1 relation pointing to Sd_CapabilityRecordFunctionCalloutPtr
  CapabilityRecordStartIdx                 the start index of the 0:n relation pointing to Sd_CapabilityRecord
  ClientTimerIdx                           the index of the 1:1 relation pointing to Sd_ClientTimer
  CommonInitialDelayIdx                    the index of the 0:1 relation pointing to Sd_CommonInitialDelay
  ConsumedEventgroupEndIdx                 the end index of the 0:n relation pointing to Sd_ConsumedEventgroup
  ConsumedEventgroupStartIdx               the start index of the 0:n relation pointing to Sd_ConsumedEventgroup
  HandleId                                 Handle ID
  InitialInstanceId                        InitialInstance ID
  InstanceIdx                              the index of the 1:1 relation pointing to Sd_Instance
  MajorVersion                             Major Version
  MethodIdx                                the index of the 0:1 relation pointing to Sd_Method
  MinorVersion                             Minor Version
  SoConGrpDynTcpIdx                        the index of the 0:1 relation pointing to Sd_SoConGrpDyn
  SoConGrpDynUdpIdx                        the index of the 0:1 relation pointing to Sd_SoConGrpDyn
  TcpSoConIdEndIdx                         the end index of the 0:n relation pointing to Sd_TcpSoConId
  TcpSoConIdStartIdx                       the start index of the 0:n relation pointing to Sd_TcpSoConId
  UdpSoConEndIdx                           the end index of the 0:n relation pointing to Sd_UdpSoCon
  UdpSoConStartIdx                         the start index of the 0:n relation pointing to Sd_UdpSoCon
  FindBehavior                             SdVersionDrivenFindBehavior
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Sd_ClientType, SD_CONST) Sd_Client[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    ServiceId  AutoRequire  MinorVersionWildcard  ServiceGroupMember  UdpClientMulticast  AclIPv4CIndEndIdx                AclIPv4CIndStartIdx                AclIPv6CIndEndIdx                AclIPv6CIndStartIdx                CapabilityRecordEndIdx                CapabilityRecordFunctionCalloutPtrIdx                CapabilityRecordStartIdx                ClientTimerIdx  CommonInitialDelayIdx                ConsumedEventgroupEndIdx  ConsumedEventgroupStartIdx  HandleId  InitialInstanceId  InstanceIdx  MajorVersion  MethodIdx                MinorVersion  SoConGrpDynTcpIdx                SoConGrpDynUdpIdx  TcpSoConIdEndIdx                TcpSoConIdStartIdx                UdpSoConEndIdx  UdpSoConStartIdx  FindBehavior                                       Referable Keys */
  { /*     0 */   0x0100u,       FALSE,                FALSE,              FALSE,              FALSE, SD_NO_ACLIPV4CINDENDIDXOFCLIENT, SD_NO_ACLIPV4CINDSTARTIDXOFCLIENT, SD_NO_ACLIPV6CINDENDIDXOFCLIENT, SD_NO_ACLIPV6CINDSTARTIDXOFCLIENT, SD_NO_CAPABILITYRECORDENDIDXOFCLIENT, SD_NO_CAPABILITYRECORDFUNCTIONCALLOUTPTRIDXOFCLIENT, SD_NO_CAPABILITYRECORDSTARTIDXOFCLIENT,             0u, SD_NO_COMMONINITIALDELAYIDXOFCLIENT,                       1u,                         0u,       0u,                1u,          0u,           1u, SD_NO_METHODIDXOFCLIENT,           0u, SD_NO_SOCONGRPDYNTCPIDXOFCLIENT,                1u, SD_NO_TCPSOCONIDENDIDXOFCLIENT, SD_NO_TCPSOCONIDSTARTIDXOFCLIENT,             2u,               1u, SD_FIND_BEHAVIOR_EXACT_OR_ANY_MINOR_VERSION }   /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/consService_RDR_1_ADAS_Vehicle_Status_2b1e055b, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d] */
};
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_ClientIdMap
**********************************************************************************************************************/
/** 
  \var    Sd_ClientIdMap
  \brief  the partition-unspecific handle ID mapping to partition-specific client IDs.
  \details
  Element                                Description
  InvalidHnd                             FALSE, if the handle of Sd_ClientIdMap is valid and can be used in the embedded code for further processing in the embedded code.
  PartitionSpecificClientIdx             the index of the 0:1 relation pointing to Sd_Client
  PartitionSpecificClientPartitionIdx    the partition index of the 0:1 relation pointing to Sd_Client
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Sd_ClientIdMapType, SD_CONST) Sd_ClientIdMap[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    InvalidHnd  PartitionSpecificClientIdx  PartitionSpecificClientPartitionIdx                                    Referable Keys */
  { /*     0 */      FALSE,                         0u,                                  0u  /* SD_NO_OS_APPL_MAPPED */ }   /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
};
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_ClientTimer
**********************************************************************************************************************/
/** 
  \var    Sd_ClientTimer
  \brief  Timer parameter for SdClientService and SdConsumedEventgroup
  \details
  Element                           Description
  InitialFindDelayMax               Maximal initial delay for FindService message
  InitialFindDelayMin               Minimal initial delay for FindService message
  InitialFindRepetitionBaseDelay    Base delay for FindService messages during initial find phase. Value is greater or equal SD_MAIN_FCT_CYCLE_TIME_MS.
  InitialFindRepetitionsMax         Amount of FindService messages transmitted during initial find phase
  RequestResponseMaxDelay           Maximal request-response delay
  RequestResponseMinDelay           Minimal request-response delay
  TTL                               Time To Live
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Sd_ClientTimerType, SD_CONST) Sd_ClientTimer[2] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    InitialFindDelayMax  InitialFindDelayMin  InitialFindRepetitionBaseDelay  InitialFindRepetitionsMax  RequestResponseMaxDelay  RequestResponseMinDelay  TTL        Referable Keys */
  { /*     0 */                 10u,                 10u,                            30u,                        3u,                     10u,                     10u,  3u },  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/consService_RDR_1_ADAS_Vehicle_Status_fb9772e0] */
  { /*     1 */                 10u,                 10u,                            30u,                        3u,                     10u,                     10u,  3u }   /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/consServiceGrp_RDR_1_ADAS_Vehicle_Status_0dbda357] */
};
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_ConsumedEventgroup
**********************************************************************************************************************/
/** 
  \var    Sd_ConsumedEventgroup
  \brief  Configuration data of SdConsumedEventgroup
  \details
  Element                           Description
  AutoRequire                       Auto require flag
  ClientIdx                         the index of the 1:1 relation pointing to Sd_Client
  ClientTimerIdx                    the index of the 1:1 relation pointing to Sd_ClientTimer
  EventGroupId                      Eventgroup ID
  HandleId                          Handle ID
  MulticastEndpointAddrIdx          the index of the 0:1 relation pointing to Sd_MulticastEndpointAddr
  MulticastSoConIdEndIdx            the end index of the 0:n relation pointing to Sd_MulticastSoConId
  MulticastSoConIdStartIdx          the start index of the 0:n relation pointing to Sd_MulticastSoConId
  RoutingGroupMulticastActRefIdx    the index of the 0:1 relation pointing to Sd_RoutingGroup
  RoutingGroupTcpActRefIdx          the index of the 0:1 relation pointing to Sd_RoutingGroup
  RoutingGroupUdpActRefIdx          the index of the 0:1 relation pointing to Sd_RoutingGroup
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Sd_ConsumedEventgroupType, SD_CONST) Sd_ConsumedEventgroup[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    AutoRequire  ClientIdx  ClientTimerIdx  EventGroupId  HandleId  MulticastEndpointAddrIdx                            MulticastSoConIdEndIdx                            MulticastSoConIdStartIdx                            RoutingGroupMulticastActRefIdx                            RoutingGroupTcpActRefIdx                            RoutingGroupUdpActRefIdx        Referable Keys */
  { /*     0 */       FALSE,        0u,             1u,           1u,       0u, SD_NO_MULTICASTENDPOINTADDRIDXOFCONSUMEDEVENTGROUP, SD_NO_MULTICASTSOCONIDENDIDXOFCONSUMEDEVENTGROUP, SD_NO_MULTICASTSOCONIDSTARTIDXOFCONSUMEDEVENTGROUP, SD_NO_ROUTINGGROUPMULTICASTACTREFIDXOFCONSUMEDEVENTGROUP, SD_NO_ROUTINGGROUPTCPACTREFIDXOFCONSUMEDEVENTGROUP,                       3u }   /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/consService_RDR_1_ADAS_Vehicle_Status_2b1e055b/consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */
};
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_ConsumedEventgroupIdMap
**********************************************************************************************************************/
/** 
  \var    Sd_ConsumedEventgroupIdMap
  \brief  the partition-unspecific handle ID mapping to partition-specific consumed eventgroup IDs.
  \details
  Element                                            Description
  InvalidHnd                                         FALSE, if the handle of Sd_ConsumedEventgroupIdMap is valid and can be used in the embedded code for further processing in the embedded code.
  PartitionSpecificConsumedEventgroupIdx             the index of the 0:1 relation pointing to Sd_ConsumedEventgroup
  PartitionSpecificConsumedEventgroupPartitionIdx    the partition index of the 0:1 relation pointing to Sd_ConsumedEventgroup
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Sd_ConsumedEventgroupIdMapType, SD_CONST) Sd_ConsumedEventgroupIdMap[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    InvalidHnd  PartitionSpecificConsumedEventgroupIdx  PartitionSpecificConsumedEventgroupPartitionIdx                                    Referable Keys */
  { /*     0 */      FALSE,                                     0u,                                              0u  /* SD_NO_OS_APPL_MAPPED */ }   /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/consService_RDR_1_ADAS_Vehicle_Status_2b1e055b/consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85] */
};
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_EventHandler
**********************************************************************************************************************/
/** 
  \var    Sd_EventHandler
  \brief  Configuration data of SdEventHandler
  \details
  Element                       Description
  ClientListEndIdx              the end index of the 1:n relation pointing to Sd_ClientList
  ClientListStartIdx            the start index of the 1:n relation pointing to Sd_ClientList
  EventGroupId                  Eventgroup ID
  EventHandlerMulticastIdx      the index of the 0:1 relation pointing to Sd_EventHandlerMulticast
  EventHandlerTcpIdx            the index of the 0:1 relation pointing to Sd_EventHandlerTcp
  EventHandlerUdpIdx            the index of the 0:1 relation pointing to Sd_EventHandlerUdp
  HandleId                      Handle ID
  MulticastThreshold            Multicast threshold
  ServerIdx                     the index of the 1:1 relation pointing to Sd_Server
  ServerTimerIdx                the index of the 1:1 relation pointing to Sd_ServerTimer
  SoConActivationMapEndIdx      the end index of the 0:n relation pointing to Sd_SoConActivationMap
  SoConActivationMapStartIdx    the start index of the 0:n relation pointing to Sd_SoConActivationMap
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Sd_EventHandlerType, SD_CONST) Sd_EventHandler[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    ClientListEndIdx  ClientListStartIdx  EventGroupId  EventHandlerMulticastIdx                      EventHandlerTcpIdx                      EventHandlerUdpIdx  HandleId  MulticastThreshold  ServerIdx  ServerTimerIdx  SoConActivationMapEndIdx  SoConActivationMapStartIdx        Referable Keys */
  { /*     0 */               1u,                 0u,           1u, SD_NO_EVENTHANDLERMULTICASTIDXOFEVENTHANDLER, SD_NO_EVENTHANDLERTCPIDXOFEVENTHANDLER,                 0u,       1u,                 0u,        2u,             3u,                       1u,                         0u },  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_SW_Info_c2745ec9/EventGroup_RDR_1_653e2581, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_SW_Info_c2745ec9, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b] */
  { /*     1 */               2u,                 1u,           1u, SD_NO_EVENTHANDLERMULTICASTIDXOFEVENTHANDLER, SD_NO_EVENTHANDLERTCPIDXOFEVENTHANDLER,                 1u,       2u,                 0u,        1u,             1u,                       2u,                         1u },  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Status_d2069d01/EventGroup_RDR_1_f7c73cae, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Status_d2069d01, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b] */
  { /*     2 */               3u,                 2u,           1u, SD_NO_EVENTHANDLERMULTICASTIDXOFEVENTHANDLER, SD_NO_EVENTHANDLERTCPIDXOFEVENTHANDLER,                 2u,       0u,                 0u,        0u,             0u,                       3u,                         2u }   /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Detections_89f78c9f/EventGroup_RDR_1_ca62382d, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Detections_89f78c9f, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b] */
};
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_EventHandlerUdp
**********************************************************************************************************************/
/** 
  \var    Sd_EventHandlerUdp
  \brief  Configuration of SdEventHandlerUdp
  \details
  Element                   Description
  RoutingGroupActRefIdx     the index of the 0:1 relation pointing to Sd_RoutingGroup
  RoutingGroupTriggerIdx    the index of the 0:1 relation pointing to Sd_RoutingGroup
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Sd_EventHandlerUdpType, SD_CONST) Sd_EventHandlerUdp[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    RoutingGroupActRefIdx  RoutingGroupTriggerIdx                               Referable Keys */
  { /*     0 */                    0u, SD_NO_ROUTINGGROUPTRIGGERIDXOFEVENTHANDLERUDP },  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_SW_Info_c2745ec9/EventGroup_RDR_1_653e2581] */
  { /*     1 */                    1u, SD_NO_ROUTINGGROUPTRIGGERIDXOFEVENTHANDLERUDP },  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Status_d2069d01/EventGroup_RDR_1_f7c73cae] */
  { /*     2 */                    2u, SD_NO_ROUTINGGROUPTRIGGERIDXOFEVENTHANDLERUDP }   /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Detections_89f78c9f/EventGroup_RDR_1_ca62382d] */
};
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_Instance
**********************************************************************************************************************/
/** 
  \var    Sd_Instance
  \brief  Configuration data for SdInstance
  \details
  Element                     Description
  MulticastRxPduId            RX PDU ID used for multicast reception
  TxPduId                     TX PDU ID used for message transmission
  UnicastRxPduId              RX PDU ID used for unicast reception
  AddressStorageEndIdx        the end index of the 1:n relation pointing to Sd_AddressStorage
  AddressStorageStartIdx      the start index of the 1:n relation pointing to Sd_AddressStorage
  CapabilityRecordEndIdx      the end index of the 0:n relation pointing to Sd_CapabilityRecord
  CapabilityRecordStartIdx    the start index of the 0:n relation pointing to Sd_CapabilityRecord
  ClientEndIdx                the end index of the 0:n relation pointing to Sd_Client
  ClientStartIdx              the start index of the 0:n relation pointing to Sd_Client
  EndpointStorageEndIdx       the end index of the 1:n relation pointing to Sd_EndpointStorage
  EndpointStorageStartIdx     the start index of the 1:n relation pointing to Sd_EndpointStorage
  EventHandlerEndIdx          the end index of the 0:n relation pointing to Sd_EventHandler
  EventHandlerStartIdx        the start index of the 0:n relation pointing to Sd_EventHandler
  LocalAddressCheckLength     Number of leading bits which shall be compared between SdEndpoint and local address to check for the same subnet.
  QueueProcessLimit           Maximum number of Rx Queue Entries which shall be processed during one MainFunction cycle.
  RetryDelay                  Delay when a not answered subscription will be retriggered.
  RetryMax                    Maximum count of subscription retries.
  RxEventEndIdx               the end index of the 0:n relation pointing to Sd_RxEvent
  RxEventStartIdx             the start index of the 0:n relation pointing to Sd_RxEvent
  SendEntryCapacity           Number of SendEntries reserved for this instance.
  SendEntryEndIdx             the end index of the 1:n relation pointing to Sd_SendEntry
  SendEntryStartIdx           the start index of the 1:n relation pointing to Sd_SendEntry
  ServerEndIdx                the end index of the 0:n relation pointing to Sd_Server
  ServerStartIdx              the start index of the 0:n relation pointing to Sd_Server
  TcpSoConIdEndIdx            the end index of the 0:n relation pointing to Sd_TcpSoConId
  TcpSoConIdStartIdx          the start index of the 0:n relation pointing to Sd_TcpSoConId
  UdpSoConEndIdx              the end index of the 0:n relation pointing to Sd_UdpSoCon
  UdpSoConStartIdx            the start index of the 0:n relation pointing to Sd_UdpSoCon
  EMalformedMsgId             DEM Event ID for malformed messages
  ENackRecvId                 DEM Event ID for received SubscribeEventgroupNack messages
  EOutOfResId                 DEM Event ID for too few available resources
  SevDuplicateOffer           IdsM Security Event ID for receiving a different Offer for a Client that is READY.
  SevFailedMethodReq          IdsM Security Event ID for failed Method Request ACL Check.
  SevFailedOffer              IdsM Security Event ID for failed Offer ACL Check.
  SevFailedSub                IdsM Security Event ID for failed Subscription ACL Check.
  MulticastRxSoConId          RX SocketConnection ID used for multicast reception
  TxSoConId                   TX SocketConnection ID used for message transmission
  UnicastRxSoConId            RX SocketConnection ID used for unicast reception
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Sd_InstanceType, SD_CONST) Sd_Instance[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    MulticastRxPduId                                          TxPduId                                               UnicastRxPduId                                        AddressStorageEndIdx  AddressStorageStartIdx  CapabilityRecordEndIdx                  CapabilityRecordStartIdx                  ClientEndIdx  ClientStartIdx  EndpointStorageEndIdx  EndpointStorageStartIdx  EventHandlerEndIdx  EventHandlerStartIdx  LocalAddressCheckLength  QueueProcessLimit  RetryDelay  RetryMax  RxEventEndIdx  RxEventStartIdx  SendEntryCapacity  SendEntryEndIdx  SendEntryStartIdx  ServerEndIdx  ServerStartIdx  TcpSoConIdEndIdx                  TcpSoConIdStartIdx                  UdpSoConEndIdx  UdpSoConStartIdx  EMalformedMsgId  ENackRecvId    EOutOfResId    SevDuplicateOffer   SevFailedMethodReq  SevFailedOffer      SevFailedSub        MulticastRxSoConId                                        TxSoConId                                                 UnicastRxSoConId                                                Referable Keys */
  { /*     0 */ SdConf_SdInstanceMulticastRxPdu_SdInstanceMulticastRxPdu, SoAdConf_SoAdPduRoute_GenerelPurposePDU3_a3a5c5ac_Tx, SdConf_SdInstanceUnicastRxPdu_SdInstanceUnicastRxPdu,                  16u,                     0u, SD_NO_CAPABILITYRECORDENDIDXOFINSTANCE, SD_NO_CAPABILITYRECORDSTARTIDXOFINSTANCE,           1u,             0u,                   32u,                      0u,                 3u,                   0u,                    255u,               96u,         0u,       0u,           96u,              0u,               96u,             96u,                0u,           3u,             0u, SD_NO_TCPSOCONIDENDIDXOFINSTANCE, SD_NO_TCPSOCONIDSTARTIDXOFINSTANCE,             2u,               0u, SD_INV_DEM_ID  , SD_INV_DEM_ID, SD_INV_DEM_ID, SD_INV_IDSM_SEV_ID, SD_INV_IDSM_SEV_ID, SD_INV_IDSM_SEV_ID, SD_INV_IDSM_SEV_ID, SoAdConf_SoAdSocketConnection_ConnectionBundle4_81a0ef65, SoAdConf_SoAdSocketConnection_ConnectionBundle2_14f4c9c7, SoAdConf_SoAdSocketConnection_ConnectionBundle2_14f4c9c7 }   /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_SW_Info_c2745ec9, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Status_d2069d01, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Detections_89f78c9f, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/consService_RDR_1_ADAS_Vehicle_Status_2b1e055b, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201/ConnectionBundle2_14f4c9c7] */
};
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    Sd_PartitionIdentifiers
  \brief  the partition context in Config
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to Sd_PCPartitionConfig
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Sd_PartitionIdentifiersType, SD_CONST) Sd_PartitionIdentifiers[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionSNV          PCPartitionConfigIdx */
  { /*     0 */ SD_NO_OS_APPL_MAPPED,                   0u }
};
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_RoutingGroup
**********************************************************************************************************************/
/** 
  \var    Sd_RoutingGroup
  \brief  SoAd RoutingGroups relevant for SD
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_RoutingGroupIdType, SD_CONST) Sd_RoutingGroup[4] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     RoutingGroup                                              Referable Keys */
  /*     0 */ SoAdConf_SoAdRoutingGroup_SoAdRoutingGroup3_c9586fb9 ,  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup3_c9586fb9] */
  /*     1 */ SoAdConf_SoAdRoutingGroup_SoAdRoutingGroup4_573cfa1a ,  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup4_573cfa1a] */
  /*     2 */ SoAdConf_SoAdRoutingGroup_SoAdRoutingGroup2_be5f5f2f ,  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup2_be5f5f2f] */
  /*     3 */ SoAdConf_SoAdRoutingGroup_SoAdRoutingGroup1_27560e95    /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup1_27560e95] */
};
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_RxPduIdMap
**********************************************************************************************************************/
/** 
  \var    Sd_RxPduIdMap
  \brief  the partition-unspecific handle ID mapping to partition-specific reception PDU IDs.
  \details
  Element                                  Description
  InvalidHnd                               FALSE, if the handle of Sd_RxPduIdMap is valid and can be used in the embedded code for further processing in the embedded code.
  PartitionSpecificInstanceIdx             the index of the 0:1 relation pointing to Sd_Instance
  PartitionSpecificInstancePartitionIdx    the partition index of the 0:1 relation pointing to Sd_Instance
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Sd_RxPduIdMapType, SD_CONST) Sd_RxPduIdMap[2] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    InvalidHnd  PartitionSpecificInstanceIdx  PartitionSpecificInstancePartitionIdx                                    Referable Keys */
  { /*     0 */      FALSE,                           0u,                                    0u  /* SD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b] */
  { /*     1 */      FALSE,                           0u,                                    0u  /* SD_NO_OS_APPL_MAPPED */ }   /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b] */
};
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_Server
**********************************************************************************************************************/
/** 
  \var    Sd_Server
  \brief  Configuration data of SdServerService. List is sorted by ServiceId (and HandleId if ServiceId is not unique) per SdInstance.
  \details
  Element                                  Description
  AutoAvailable                            Auto available flag
  ServiceGroupMember                       Specifies if service is member of a ServiceGroup.
  AclIPv4SIndEndIdx                        the end index of the 0:n relation pointing to Sd_AclIPv4SInd
  AclIPv4SIndStartIdx                      the start index of the 0:n relation pointing to Sd_AclIPv4SInd
  AclIPv6SIndEndIdx                        the end index of the 0:n relation pointing to Sd_AclIPv6SInd
  AclIPv6SIndStartIdx                      the start index of the 0:n relation pointing to Sd_AclIPv6SInd
  CapabilityRecordEndIdx                   the end index of the 0:n relation pointing to Sd_CapabilityRecord
  CapabilityRecordFunctionCalloutPtrIdx    the index of the 0:1 relation pointing to Sd_CapabilityRecordFunctionCalloutPtr
  CapabilityRecordStartIdx                 the start index of the 0:n relation pointing to Sd_CapabilityRecord
  CommonInitialDelayIdx                    the index of the 0:1 relation pointing to Sd_CommonInitialDelay
  EventHandlerEndIdx                       the end index of the 0:n relation pointing to Sd_EventHandler
  EventHandlerStartIdx                     the start index of the 0:n relation pointing to Sd_EventHandler
  HandleId                                 Handle ID
  InitialInstanceId                        Initial Instance ID
  InstanceIdx                              the index of the 1:1 relation pointing to Sd_Instance
  MajorVersion                             Major Version
  MethodIdx                                the index of the 0:1 relation pointing to Sd_Method
  MinorVersion                             Minor Version
  ServerTimerIdx                           the index of the 1:1 relation pointing to Sd_ServerTimer
  ServiceId                                Service ID
  SoConGrpDynTcpIdx                        the index of the 0:1 relation pointing to Sd_SoConGrpDyn
  SoConGrpDynUdpIdx                        the index of the 0:1 relation pointing to Sd_SoConGrpDyn
  TcpSoConIdEndIdx                         the end index of the 0:n relation pointing to Sd_TcpSoConId
  TcpSoConIdStartIdx                       the start index of the 0:n relation pointing to Sd_TcpSoConId
  UdpSoConEndIdx                           the end index of the 0:n relation pointing to Sd_UdpSoCon
  UdpSoConStartIdx                         the start index of the 0:n relation pointing to Sd_UdpSoCon
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Sd_ServerType, SD_CONST) Sd_Server[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    AutoAvailable  ServiceGroupMember  AclIPv4SIndEndIdx                AclIPv4SIndStartIdx                AclIPv6SIndEndIdx                AclIPv6SIndStartIdx                CapabilityRecordEndIdx                CapabilityRecordFunctionCalloutPtrIdx                CapabilityRecordStartIdx                CommonInitialDelayIdx                EventHandlerEndIdx  EventHandlerStartIdx  HandleId  InitialInstanceId  InstanceIdx  MajorVersion  MethodIdx                MinorVersion  ServerTimerIdx  ServiceId  SoConGrpDynTcpIdx                SoConGrpDynUdpIdx  TcpSoConIdEndIdx                TcpSoConIdStartIdx                UdpSoConEndIdx  UdpSoConStartIdx        Referable Keys */
  { /*     0 */         FALSE,              FALSE, SD_NO_ACLIPV4SINDENDIDXOFSERVER, SD_NO_ACLIPV4SINDSTARTIDXOFSERVER, SD_NO_ACLIPV6SINDENDIDXOFSERVER, SD_NO_ACLIPV6SINDSTARTIDXOFSERVER, SD_NO_CAPABILITYRECORDENDIDXOFSERVER, SD_NO_CAPABILITYRECORDFUNCTIONCALLOUTPTRIDXOFSERVER, SD_NO_CAPABILITYRECORDSTARTIDXOFSERVER, SD_NO_COMMONINITIALDELAYIDXOFSERVER,                 3u,                   2u,       0u,                1u,          0u,           1u, SD_NO_METHODIDXOFSERVER,           0u,             5u,     0x10u, SD_NO_SOCONGRPDYNTCPIDXOFSERVER,                0u, SD_NO_TCPSOCONIDENDIDXOFSERVER, SD_NO_TCPSOCONIDSTARTIDXOFSERVER,             1u,               0u },  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Detections_89f78c9f, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe] */
  { /*     1 */         FALSE,              FALSE, SD_NO_ACLIPV4SINDENDIDXOFSERVER, SD_NO_ACLIPV4SINDSTARTIDXOFSERVER, SD_NO_ACLIPV6SINDENDIDXOFSERVER, SD_NO_ACLIPV6SINDSTARTIDXOFSERVER, SD_NO_CAPABILITYRECORDENDIDXOFSERVER, SD_NO_CAPABILITYRECORDFUNCTIONCALLOUTPTRIDXOFSERVER, SD_NO_CAPABILITYRECORDSTARTIDXOFSERVER, SD_NO_COMMONINITIALDELAYIDXOFSERVER,                 2u,                   1u,       2u,                1u,          0u,           1u, SD_NO_METHODIDXOFSERVER,           0u,             4u,     0x11u, SD_NO_SOCONGRPDYNTCPIDXOFSERVER,                0u, SD_NO_TCPSOCONIDENDIDXOFSERVER, SD_NO_TCPSOCONIDSTARTIDXOFSERVER,             1u,               0u },  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Status_d2069d01, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe] */
  { /*     2 */         FALSE,              FALSE, SD_NO_ACLIPV4SINDENDIDXOFSERVER, SD_NO_ACLIPV4SINDSTARTIDXOFSERVER, SD_NO_ACLIPV6SINDENDIDXOFSERVER, SD_NO_ACLIPV6SINDSTARTIDXOFSERVER, SD_NO_CAPABILITYRECORDENDIDXOFSERVER, SD_NO_CAPABILITYRECORDFUNCTIONCALLOUTPTRIDXOFSERVER, SD_NO_CAPABILITYRECORDSTARTIDXOFSERVER, SD_NO_COMMONINITIALDELAYIDXOFSERVER,                 1u,                   0u,       1u,                1u,          0u,           1u, SD_NO_METHODIDXOFSERVER,           0u,             2u,     0x12u, SD_NO_SOCONGRPDYNTCPIDXOFSERVER,                0u, SD_NO_TCPSOCONIDENDIDXOFSERVER, SD_NO_TCPSOCONIDSTARTIDXOFSERVER,             1u,               0u }   /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_SW_Info_c2745ec9, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe] */
};
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_ServerIdMap
**********************************************************************************************************************/
/** 
  \var    Sd_ServerIdMap
  \brief  the partition-unspecific handle ID mapping to partition-specific server IDs.
  \details
  Element                                Description
  InvalidHnd                             FALSE, if the handle of Sd_ServerIdMap is valid and can be used in the embedded code for further processing in the embedded code.
  PartitionSpecificServerIdx             the index of the 0:1 relation pointing to Sd_Server
  PartitionSpecificServerPartitionIdx    the partition index of the 0:1 relation pointing to Sd_Server
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Sd_ServerIdMapType, SD_CONST) Sd_ServerIdMap[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    InvalidHnd  PartitionSpecificServerIdx  PartitionSpecificServerPartitionIdx                                    Referable Keys */
  { /*     0 */      FALSE,                         0u,                                  0u  /* SD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Detections_89f78c9f] */
  { /*     1 */      FALSE,                         2u,                                  0u  /* SD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_SW_Info_c2745ec9] */
  { /*     2 */      FALSE,                         1u,                                  0u  /* SD_NO_OS_APPL_MAPPED */ }   /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Status_d2069d01] */
};
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_ServerTimer
**********************************************************************************************************************/
/** 
  \var    Sd_ServerTimer
  \brief  Timer parameter for SdServerService and SdEventHandler
  \details
  Element                            Description
  OfferCyclicDelay                   Delay used for cyclic transmission of OfferService messages. Value is greater or equal SD_MAIN_FCT_CYCLE_TIME_MS.
  InitialOfferDelayMax               Initial maximal Offer delay
  InitialOfferDelayMin               Initial minimal Offer delay
  InitialOfferRepetitionBaseDelay    Base delay used for timing of OfferServices messages during repetition phase. Value is greater or equal SD_MAIN_FCT_CYCLE_TIME_MS.
  InitialOfferRepetitionsMax         Amount of OfferService messages transmitted during repetition phase
  RequestResponseMaxDelay            Maximal request-response delay
  RequestResponseMinDelay            Minimal request-response delay
  TTL                                Time To Live
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Sd_ServerTimerType, SD_CONST) Sd_ServerTimer[6] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    OfferCyclicDelay  InitialOfferDelayMax  InitialOfferDelayMin  InitialOfferRepetitionBaseDelay  InitialOfferRepetitionsMax  RequestResponseMaxDelay  RequestResponseMinDelay  TTL        Referable Keys */
  { /*     0 */            1000u,                  10u,                  10u,                             30u,                         3u,                     10u,                     10u,  3u },  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/EventGroup_RDR_1_0937cbe9] */
  { /*     1 */            1000u,                  10u,                  10u,                             30u,                         3u,                     10u,                     10u,  3u },  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/EventGroup_RDR_1_a30b5032] */
  { /*     2 */            1000u,                  10u,                  10u,                             30u,                         3u,                     10u,                     10u,  3u },  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_SW_Info_3b034188] */
  { /*     3 */            1000u,                  10u,                  10u,                             30u,                         3u,                     10u,                     10u,  3u },  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/EventGroup_RDR_1_92448352] */
  { /*     4 */            1000u,                  10u,                  10u,                             30u,                         3u,                     10u,                     10u,  3u },  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Status_4d7443dc] */
  { /*     5 */            1000u,                  10u,                  10u,                             30u,                         3u,                     10u,                     10u,  3u }   /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Detections_5ab771e8] */
};
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_SoConModeIdMap
**********************************************************************************************************************/
/** 
  \var    Sd_SoConModeIdMap
  \brief  the partition-unspecific handle ID mapping to partition-specific socket connection mode IDs.
  \details
  Element                                   Description
  InvalidHnd                                FALSE, if the handle of Sd_SoConModeIdMap is valid and can be used in the embedded code for further processing in the embedded code.
  PartitionSpecificSoConModeIdx             the index of the 0:1 relation pointing to Sd_SoConModeDyn
  PartitionSpecificSoConModePartitionIdx    the partition index of the 0:1 relation pointing to Sd_SoConModeDyn
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Sd_SoConModeIdMapType, SD_CONST) Sd_SoConModeIdMap[4] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    InvalidHnd  PartitionSpecificSoConModeIdx                        PartitionSpecificSoConModePartitionIdx                                                          Referable Keys */
  { /*     0 */       TRUE, SD_NO_PARTITIONSPECIFICSOCONMODEIDXOFSOCONMODEIDMAP, SD_NO_PARTITIONSPECIFICSOCONMODEPARTITIONIDXOFSOCONMODEIDMAP                             },  /* [unusedIndex0] */
  { /*     1 */       TRUE, SD_NO_PARTITIONSPECIFICSOCONMODEIDXOFSOCONMODEIDMAP, SD_NO_PARTITIONSPECIFICSOCONMODEPARTITIONIDXOFSOCONMODEIDMAP                             },  /* [unusedIndex1] */
  { /*     2 */      FALSE,                                                  1u,                                                           0u  /* SD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d/ConnectionBundle_ADAS_53ce198e] */
  { /*     3 */      FALSE,                                                  0u,                                                           0u  /* SD_NO_OS_APPL_MAPPED */ }   /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815] */
};
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_TxSoConIdMap
**********************************************************************************************************************/
/** 
  \var    Sd_TxSoConIdMap
  \brief  the partition-unspecific handle ID mapping to partition-specific Tx socket connection IDs.
  \details
  Element                                  Description
  InvalidHnd                               FALSE, if the handle of Sd_TxSoConIdMap is valid and can be used in the embedded code for further processing in the embedded code.
  PartitionSpecificInstanceIdx             the index of the 0:1 relation pointing to Sd_Instance
  PartitionSpecificInstancePartitionIdx    the partition index of the 0:1 relation pointing to Sd_Instance
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Sd_TxSoConIdMapType, SD_CONST) Sd_TxSoConIdMap[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    InvalidHnd  PartitionSpecificInstanceIdx  PartitionSpecificInstancePartitionIdx                                    Referable Keys */
  { /*     0 */      FALSE,                           0u,                                    0u  /* SD_NO_OS_APPL_MAPPED */ }   /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201/ConnectionBundle2_14f4c9c7] */
};
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_UdpSoCon
**********************************************************************************************************************/
/** 
  \var    Sd_UdpSoCon
  \brief  UDP SocketConnections sorted by SdInstance and SdServer/SdClientServices
  \details
  Element          Description
  Preconfigured    Specifies if SoCon is preconfigured with IP and Port or not
  Id               IDs of UDP SocketConnections
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Sd_UdpSoConType, SD_CONST) Sd_UdpSoCon[2] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    Preconfigured  Id                                                                   Referable Keys */
  { /*     0 */          TRUE, SoAdConf_SoAdSocketConnection_ConnectionBundle_RDR_1_94fef815 },  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe] */
  { /*     1 */          TRUE, SoAdConf_SoAdSocketConnection_ConnectionBundle_ADAS_53ce198e  }   /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d] */
};
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_AddressStorage
**********************************************************************************************************************/
/** 
  \var    Sd_AddressStorage
  \brief  State information of communication partner
  \details
  Element                  Description
  RxMulticastSessionId     RX multicast session ID
  RxUnicastSessionId       RX unicast session ID
  SessionIdCounter         TX session ID
  Flags                    TX flags
  RebootDetected           Remote reboot detection status
  RxMulticastFlags         RX multicast flags
  RxUnicastFlags           RX unicast flags
  SendEntryHeadIdx         the index of the 0:1 relation pointing to Sd_SendEntry
  SendEntryNrPendingIdx    the index of the 0:1 relation pointing to Sd_SendEntry
  SendEntryTailIdx         the index of the 0:1 relation pointing to Sd_SendEntry
  Addr                     Address of the communication partner
  TimeToSend               Time when queued SendEntries became / will become ready to be sent
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Sd_AddressStorageType, SD_VAR_NO_INIT) Sd_AddressStorage[16];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b] */
  /*   ... */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b] */
  /*    15 */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b] */

#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_ClientDyn
**********************************************************************************************************************/
/** 
  \var    Sd_ClientDyn
  \brief  Dynamic configuration data for SdClientService
  \details
  Element                           Description
  OfferedTTL                        Offered Time To Live
  InstanceId                        Current Instance ID of client service
  AddressStorageCurrentServerIdx    the index of the 0:1 relation pointing to Sd_AddressStorage
  AddressStorageServerIdx           the index of the 0:1 relation pointing to Sd_AddressStorage
  RepetitionRun                     Repetition run counter
  RetryCounter                      Counter for subscribe eventgroup retry handling.
  ServiceGroupReqCounter            Client request counter for ServiceGroup service API
  StateMachineExecutionRequested    Flag if State machine shall be executed for this client
  CurrentState                      Current state
  EventMain                         Event processed in MainFunction.
  EventRx                           Received event
  MethodTcpSoConId                  TCP method SoConId
  MethodUdpSoConId                  UDP method SoConId
  RetryTimer                        Timer for subscribe eventgroup retry handling.
  ServerTcpEndpointAddr             Server TCP endpoint address
  ServerUdpEndpointAddr             Server UDP endpoint address
  StateMachine                      State machine
  StateSwc                          Requested state
  TimeToTriggerSend                 Time to trigger next message transmission
  TimerTTL                          Time To Live
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Sd_ClientDynType, SD_VAR_NO_INIT) Sd_ClientDyn[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/consService_RDR_1_ADAS_Vehicle_Status_2b1e055b, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d] */

#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_ClientList
**********************************************************************************************************************/
/** 
  \var    Sd_ClientList
  \brief  Dynamic data of subscribed clients
  \details
  Element                  Description
  RequestedTTL             Requested TimeToLive
  RxReserved               Received reserved field
  AddressStorageIdx        the index of the 0:1 relation pointing to Sd_AddressStorage
  EndpointStorageTcpIdx    the index of the 0:1 relation pointing to Sd_EndpointStorage
  EndpointStorageUdpIdx    the index of the 0:1 relation pointing to Sd_EndpointStorage
  NrOfReferences           Number of simultaneous subscriptions
  AssignedTcpSoConId       Used TCP SocketConnection ID
  AssignedUdpSoConId       Used UDP SocketConnection ID
  ClientState              State of the client
  SubscribedUntil          Point in time till the client is subscribed
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Sd_ClientListType, SD_VAR_NO_INIT) Sd_ClientList[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_SW_Info_c2745ec9/EventGroup_RDR_1_653e2581] */
  /*     1 */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Status_d2069d01/EventGroup_RDR_1_f7c73cae] */
  /*     2 */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Detections_89f78c9f/EventGroup_RDR_1_ca62382d] */

#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_ConsumedEventgroupDyn
**********************************************************************************************************************/
/** 
  \var    Sd_ConsumedEventgroupDyn
  \brief  Dynamic configuration of SdConsumedEventgroup
  \details
  Element                Description
  AcknowledgedTTL        Acknowledge Time To Live
  RxIndicationCount      Counter to differentiate RxIndication calls.
  TriggerSubscription    Flag indicating if a subscription shall be triggered.
  CurrentState           Current state
  Event                  Received event
  MulticastSoConId       Configured multicast SocketConnection
  ServiceModeRequest     Requested state
  StateMachine           State machine
  TcpSoConId             Configured TCP SocketConnection
  TimerTTL               Time To Live
  UdpSoConId             Configured UDP SocketConnection
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Sd_ConsumedEventgroupDynType, SD_VAR_NO_INIT) Sd_ConsumedEventgroupDyn[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/consService_RDR_1_ADAS_Vehicle_Status_2b1e055b/consServiceGrp_RDR_1_ADAS_Vehicle_Status_4b79da85, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/consService_RDR_1_ADAS_Vehicle_Status_2b1e055b] */

#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_EndpointStorage
**********************************************************************************************************************/
/** 
  \var    Sd_EndpointStorage
  \brief  Received endpoint options
  \details
  Element           Description
  NrOfReferences    Number of external references
  Addr              Endpoint address
  Type              Endpoint type
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Sd_EndpointStorageType, SD_VAR_NO_INIT) Sd_EndpointStorage[32];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b] */
  /*   ... */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b] */
  /*    31 */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b] */

#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_EventHandlerDyn
**********************************************************************************************************************/
/** 
  \var    Sd_EventHandlerDyn
  \brief  Dynamic configuration of SdEventHandler
  \details
  Element         Description
  NrOfClients     Nr of subscribed clients
  RequestState    Request state
  StateMachine    State machine
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Sd_EventHandlerDynType, SD_VAR_NO_INIT) Sd_EventHandlerDyn[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_SW_Info_c2745ec9/EventGroup_RDR_1_653e2581, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_SW_Info_c2745ec9, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b] */
  /*     1 */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Status_d2069d01/EventGroup_RDR_1_f7c73cae, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Status_d2069d01, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b] */
  /*     2 */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Detections_89f78c9f/EventGroup_RDR_1_ca62382d, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Detections_89f78c9f, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b] */

#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_InstanceDyn
**********************************************************************************************************************/
/** 
  \var    Sd_InstanceDyn
  \brief  Variable data for each SdInstance
  \details
  Element                     Description
  RxEventEndIdx               the index of the 1:1 relation pointing to Sd_RxEvent
  RxEventListFull             Full flag of dynamic queue
  RxEventStartIdx             the index of the 1:1 relation pointing to Sd_RxEvent
  SendEntryFreeListHeadIdx    the index of the 1:1 relation pointing to Sd_SendEntry
  SendEntryFreeListTailIdx    the index of the 1:1 relation pointing to Sd_SendEntry
  SendEntryNrPendingIdx       the index of the 1:1 relation pointing to Sd_SendEntry
  LastFoundEndpoint           LastFoundEndpoint
  NextStateMachineRun         Time indicating next execution of state machines
  RunMode                     Communication mode
  State                       State
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Sd_InstanceDynType, SD_VAR_NO_INIT) Sd_InstanceDyn[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_SW_Info_c2745ec9, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Status_d2069d01, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Detections_89f78c9f, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/consService_RDR_1_ADAS_Vehicle_Status_2b1e055b, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201/ConnectionBundle2_14f4c9c7] */

#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_OptionIndex
**********************************************************************************************************************/
/** 
  \var    Sd_OptionIndex
  \brief  Payload offset of options
*/ 
#define SD_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Sd_OptionIndexType, SD_VAR_NO_INIT) Sd_OptionIndex[10];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define SD_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_PartitionDataDyn
**********************************************************************************************************************/
/** 
  \var    Sd_PartitionDataDyn
  \brief  Partition specific dynamic data.
  \details
  Element                       Description
  NrOfOptions                   Number of options saved in the OptionIndex.
  RxIndicationCount             Counter for calls of RxIndication.
  TriggerTransmitDynEndIdx      the index of the 1:1 relation pointing to Sd_TriggerTransmitDyn
  TriggerTransmitDynStartIdx    the index of the 1:1 relation pointing to Sd_TriggerTransmitDyn
  TriggerTransmitFull           Indication whether trigger transmit ring buffer is full.
  TxPathLocked                  Indication if transmission path is locked.
  Initialized                   initialized state of the partition
  TimeMsSinceStart              Time since start of the component.
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Sd_PartitionDataDynType, SD_VAR_NO_INIT) Sd_PartitionDataDyn[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_Payload
**********************************************************************************************************************/
/** 
  \var    Sd_Payload
  \brief  Buffer used for message transmission
*/ 
#define SD_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Sd_PayloadType, SD_VAR_NO_INIT) Sd_Payload[1464];  /* PRQA S 1514, 1533, 0612, 0613 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_BigStructure, MD_CSL_BigStructure */
#define SD_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_RoutingGroupDyn
**********************************************************************************************************************/
/** 
  \var    Sd_RoutingGroupDyn
  \brief  Dynamic data of SoAd RoutingGroups relevant for SD
  \details
  Element    Description
  Status     Status (disabled/enabled/unknown) of RoutingGroup
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Sd_RoutingGroupDynType, SD_VAR_NO_INIT) Sd_RoutingGroupDyn[4];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup3_c9586fb9] */
  /*     1 */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup4_573cfa1a] */
  /*     2 */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup2_be5f5f2f] */
  /*     3 */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup1_27560e95] */

#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_RxEvent
**********************************************************************************************************************/
/** 
  \var    Sd_RxEvent
  \brief  Saves received server events
  \details
  Element            Description
  ClientListIdx      the index of the 0:1 relation pointing to Sd_ClientList
  EventHandlerIdx    the index of the 0:1 relation pointing to Sd_EventHandler
  Event              Received event
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Sd_RxEventType, SD_VAR_NO_INIT) Sd_RxEvent[96];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b] */
  /*   ... */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b] */
  /*    95 */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b] */

#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_SendEntry
**********************************************************************************************************************/
/** 
  \var    Sd_SendEntry
  \brief  Saves messages which shall be transmitted
  \details
  Element                  Description
  EventHandlerId           EventHandler ID
  InstanceId               Instance ID
  ReservedField            Reserved Field
  ServiceId                Service ID
  ClientIdx                the index of the 0:1 relation pointing to Sd_Client
  ClientListIdx            the index of the 0:1 relation pointing to Sd_ClientList
  ConsumedEventgroupIdx    the index of the 0:1 relation pointing to Sd_ConsumedEventgroup
  EventHandlerIdx          the index of the 0:1 relation pointing to Sd_EventHandler
  InstanceIdx              the index of the 0:1 relation pointing to Sd_Instance
  MajorVersion             Major Version
  SendEntryNextIdx         the index of the 0:1 relation pointing to Sd_SendEntry
  SendEntryPrevIdx         the index of the 0:1 relation pointing to Sd_SendEntry
  ServerIdx                the index of the 0:1 relation pointing to Sd_Server
  EntryType                Type of entry
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Sd_SendEntryType, SD_VAR_NO_INIT) Sd_SendEntry[96];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b] */
  /*   ... */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b] */
  /*    95 */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b] */

#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_ServerDyn
**********************************************************************************************************************/
/** 
  \var    Sd_ServerDyn
  \brief  Dynamic configuration data of SdServerService
  \details
  Element                           Description
  InstanceId                        Current Instance ID of server service
  InitialOfferRepetitionRun         Counting the number of repetition runs
  ServiceGroupReqCounter            Server availability counter for ServiceGroup service API
  StateMachineExecutionRequested    Flag if State machine shall be executed for this server
  StateMachine                      State machine
  StateSwc                          Requested state
  TimeToTriggerSend                 Point in time the next message will be transmitted
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Sd_ServerDynType, SD_VAR_NO_INIT) Sd_ServerDyn[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Detections_89f78c9f, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe] */
  /*     1 */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Status_d2069d01, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe] */
  /*     2 */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b, /ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_SW_Info_c2745ec9, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe] */

#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_SoConActivationMap
**********************************************************************************************************************/
/** 
  \var    Sd_SoConActivationMap
  \brief  Configuration data of SocketConnections
  \details
  Element            Description
  NrOfActivations    Nr of activations
  SoConId            SocketConnection ID
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Sd_SoConActivationMapType, SD_VAR_NO_INIT) Sd_SoConActivationMap[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_SW_Info_c2745ec9/EventGroup_RDR_1_653e2581] */
  /*     1 */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Status_d2069d01/EventGroup_RDR_1_f7c73cae] */
  /*     2 */  /* [/ActiveEcuC/Sd/SdConfig/cnctr_RDR_RdrNet_5172a59b/provService_RDR_1_Detections_89f78c9f/EventGroup_RDR_1_ca62382d] */

#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_SoConGrpDyn
**********************************************************************************************************************/
/** 
  \var    Sd_SoConGrpDyn
  \brief  Dynamic data of used SoAd Socket Connection Groups
  \details
  Element      Description
  LocalPort    Local Port of the SoCon Group
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Sd_SoConGrpDynType, SD_VAR_NO_INIT) Sd_SoConGrpDyn[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe] */
  /*     1 */  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d] */

#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_SoConModeDyn
**********************************************************************************************************************/
/** 
  \var    Sd_SoConModeDyn
  \brief  Saves the current SocketConnection mode of a SoCon which has been returned by Sd_SoConModeChg().
*/ 
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Sd_SoConModeType, SD_VAR_NO_INIT) Sd_SoConModeDyn[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815] */
  /*     1 */  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d/ConnectionBundle_ADAS_53ce198e] */

#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_PCConfig
**********************************************************************************************************************/
/** 
  \var    Sd_PCConfig
  \details
  Element                       Description
  PCPartitionConfig             the pointer to Sd_PCPartitionConfig
  PartitionIdentifiers          the pointer to Sd_PartitionIdentifiers
  SizeOfPartitionIdentifiers    the number of accomplishable value elements in Sd_PartitionIdentifiers
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Sd_PCConfigsType, SD_CONST) Sd_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config] */
      Sd_PCPartitionConfig        /**< the pointer to Sd_PCPartitionConfig */
    , Sd_PartitionIdentifiers     /**< the pointer to Sd_PartitionIdentifiers */
    , 1u                          /**< the number of elements in Sd_PartitionIdentifiers */
  }
};
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Sd_PCPartitionConfig
**********************************************************************************************************************/
/** 
  \var    Sd_PCPartitionConfig
  \details
  Element                                     Description
  AclIPv4                                     the pointer to Sd_AclIPv4
  AclIPv4CInd                                 the pointer to Sd_AclIPv4CInd
  AclIPv4SInd                                 the pointer to Sd_AclIPv4SInd
  AclIPv6                                     the pointer to Sd_AclIPv6
  AclIPv6CInd                                 the pointer to Sd_AclIPv6CInd
  AclIPv6SInd                                 the pointer to Sd_AclIPv6SInd
  AddressStorage                              the pointer to Sd_AddressStorage
  CapabilityRecord                            the pointer to Sd_CapabilityRecord
  CapabilityRecordFunctionCalloutPtr          the pointer to Sd_CapabilityRecordFunctionCalloutPtr
  Client                                      the pointer to Sd_Client
  ClientDyn                                   the pointer to Sd_ClientDyn
  ClientIdMap                                 the pointer to Sd_ClientIdMap
  ClientList                                  the pointer to Sd_ClientList
  ClientTimer                                 the pointer to Sd_ClientTimer
  CommonInitialDelay                          the pointer to Sd_CommonInitialDelay
  ConsumedEventgroup                          the pointer to Sd_ConsumedEventgroup
  ConsumedEventgroupDyn                       the pointer to Sd_ConsumedEventgroupDyn
  ConsumedEventgroupIdMap                     the pointer to Sd_ConsumedEventgroupIdMap
  EndpointStorage                             the pointer to Sd_EndpointStorage
  EventHandler                                the pointer to Sd_EventHandler
  EventHandlerDyn                             the pointer to Sd_EventHandlerDyn
  EventHandlerMulticast                       the pointer to Sd_EventHandlerMulticast
  EventHandlerTcp                             the pointer to Sd_EventHandlerTcp
  EventHandlerUdp                             the pointer to Sd_EventHandlerUdp
  Instance                                    the pointer to Sd_Instance
  InstanceDyn                                 the pointer to Sd_InstanceDyn
  IpAddrRequest                               the pointer to Sd_IpAddrRequest
  Method                                      the pointer to Sd_Method
  MulticastEndpointAddr                       the pointer to Sd_MulticastEndpointAddr
  MulticastSoConId                            the pointer to Sd_MulticastSoConId
  OptionIndex                                 the pointer to Sd_OptionIndex
  PartitionDataDyn                            the pointer to Sd_PartitionDataDyn
  Payload                                     the pointer to Sd_Payload
  PortSet                                     the pointer to Sd_PortSet
  RequestCnt                                  the pointer to Sd_RequestCnt
  RoutingGroup                                the pointer to Sd_RoutingGroup
  RoutingGroupDyn                             the pointer to Sd_RoutingGroupDyn
  RoutingGroupIdMap                           the pointer to Sd_RoutingGroupIdMap
  RxEvent                                     the pointer to Sd_RxEvent
  RxPduIdMap                                  the pointer to Sd_RxPduIdMap
  SendEntry                                   the pointer to Sd_SendEntry
  Server                                      the pointer to Sd_Server
  ServerDyn                                   the pointer to Sd_ServerDyn
  ServerIdMap                                 the pointer to Sd_ServerIdMap
  ServerTimer                                 the pointer to Sd_ServerTimer
  ServiceGroup                                the pointer to Sd_ServiceGroup
  ServiceGroupIdMap                           the pointer to Sd_ServiceGroupIdMap
  ServiceGroupMember                          the pointer to Sd_ServiceGroupMember
  SoConActivationMap                          the pointer to Sd_SoConActivationMap
  SoConGrpDyn                                 the pointer to Sd_SoConGrpDyn
  SoConModeDyn                                the pointer to Sd_SoConModeDyn
  SoConModeIdMap                              the pointer to Sd_SoConModeIdMap
  TcpSoConId                                  the pointer to Sd_TcpSoConId
  TriggerTransmitDyn                          the pointer to Sd_TriggerTransmitDyn
  TxSoConIdMap                                the pointer to Sd_TxSoConIdMap
  UdpSoCon                                    the pointer to Sd_UdpSoCon
  SizeOfPayload                               the number of accomplishable value elements in Sd_Payload
  SizeOfAclIPv4                               the number of accomplishable value elements in Sd_AclIPv4
  SizeOfAclIPv4CInd                           the number of accomplishable value elements in Sd_AclIPv4CInd
  SizeOfAclIPv4SInd                           the number of accomplishable value elements in Sd_AclIPv4SInd
  SizeOfAclIPv6                               the number of accomplishable value elements in Sd_AclIPv6
  SizeOfAclIPv6CInd                           the number of accomplishable value elements in Sd_AclIPv6CInd
  SizeOfAclIPv6SInd                           the number of accomplishable value elements in Sd_AclIPv6SInd
  SizeOfAddressStorage                        the number of accomplishable value elements in Sd_AddressStorage
  SizeOfCapabilityRecord                      the number of accomplishable value elements in Sd_CapabilityRecord
  SizeOfCapabilityRecordFunctionCalloutPtr    the number of accomplishable value elements in Sd_CapabilityRecordFunctionCalloutPtr
  SizeOfClient                                the number of accomplishable value elements in Sd_Client
  SizeOfClientIdMap                           the number of accomplishable value elements in Sd_ClientIdMap
  SizeOfClientList                            the number of accomplishable value elements in Sd_ClientList
  SizeOfClientTimer                           the number of accomplishable value elements in Sd_ClientTimer
  SizeOfCommonInitialDelay                    the number of accomplishable value elements in Sd_CommonInitialDelay
  SizeOfConsumedEventgroup                    the number of accomplishable value elements in Sd_ConsumedEventgroup
  SizeOfConsumedEventgroupIdMap               the number of accomplishable value elements in Sd_ConsumedEventgroupIdMap
  SizeOfEndpointStorage                       the number of accomplishable value elements in Sd_EndpointStorage
  SizeOfEventHandler                          the number of accomplishable value elements in Sd_EventHandler
  SizeOfEventHandlerMulticast                 the number of accomplishable value elements in Sd_EventHandlerMulticast
  SizeOfEventHandlerTcp                       the number of accomplishable value elements in Sd_EventHandlerTcp
  SizeOfEventHandlerUdp                       the number of accomplishable value elements in Sd_EventHandlerUdp
  SizeOfInstance                              the number of accomplishable value elements in Sd_Instance
  SizeOfIpAddrRequest                         the number of accomplishable value elements in Sd_IpAddrRequest
  SizeOfMethod                                the number of accomplishable value elements in Sd_Method
  SizeOfMulticastEndpointAddr                 the number of accomplishable value elements in Sd_MulticastEndpointAddr
  SizeOfMulticastSoConId                      the number of accomplishable value elements in Sd_MulticastSoConId
  SizeOfOptionIndex                           the number of accomplishable value elements in Sd_OptionIndex
  SizeOfPartitionDataDyn                      the number of accomplishable value elements in Sd_PartitionDataDyn
  SizeOfPortSet                               the number of accomplishable value elements in Sd_PortSet
  SizeOfRequestCnt                            the number of accomplishable value elements in Sd_RequestCnt
  SizeOfRoutingGroup                          the number of accomplishable value elements in Sd_RoutingGroup
  SizeOfRoutingGroupIdMap                     the number of accomplishable value elements in Sd_RoutingGroupIdMap
  SizeOfRxEvent                               the number of accomplishable value elements in Sd_RxEvent
  SizeOfRxPduIdMap                            the number of accomplishable value elements in Sd_RxPduIdMap
  SizeOfSendEntry                             the number of accomplishable value elements in Sd_SendEntry
  SizeOfServer                                the number of accomplishable value elements in Sd_Server
  SizeOfServerIdMap                           the number of accomplishable value elements in Sd_ServerIdMap
  SizeOfServerTimer                           the number of accomplishable value elements in Sd_ServerTimer
  SizeOfServiceGroup                          the number of accomplishable value elements in Sd_ServiceGroup
  SizeOfServiceGroupIdMap                     the number of accomplishable value elements in Sd_ServiceGroupIdMap
  SizeOfServiceGroupMember                    the number of accomplishable value elements in Sd_ServiceGroupMember
  SizeOfSoConActivationMap                    the number of accomplishable value elements in Sd_SoConActivationMap
  SizeOfSoConGrpDyn                           the number of accomplishable value elements in Sd_SoConGrpDyn
  SizeOfSoConModeDyn                          the number of accomplishable value elements in Sd_SoConModeDyn
  SizeOfSoConModeIdMap                        the number of accomplishable value elements in Sd_SoConModeIdMap
  SizeOfTcpSoConId                            the number of accomplishable value elements in Sd_TcpSoConId
  SizeOfTriggerTransmitDyn                    the number of accomplishable value elements in Sd_TriggerTransmitDyn
  SizeOfTxSoConIdMap                          the number of accomplishable value elements in Sd_TxSoConIdMap
  SizeOfUdpSoCon                              the number of accomplishable value elements in Sd_UdpSoCon
*/ 
#define SD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Sd_PCPartitionConfigType, SD_CONST) Sd_PCPartitionConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [SD_NO_OS_APPL_MAPPED] */
      NULL_PTR                                  /**< the pointer to Sd_AclIPv4 */
    , NULL_PTR                                  /**< the pointer to Sd_AclIPv4CInd */
    , NULL_PTR                                  /**< the pointer to Sd_AclIPv4SInd */
    , NULL_PTR                                  /**< the pointer to Sd_AclIPv6 */
    , NULL_PTR                                  /**< the pointer to Sd_AclIPv6CInd */
    , NULL_PTR                                  /**< the pointer to Sd_AclIPv6SInd */
    , Sd_AddressStorage                         /**< the pointer to Sd_AddressStorage */
    , NULL_PTR                                  /**< the pointer to Sd_CapabilityRecord */
    , NULL_PTR                                  /**< the pointer to Sd_CapabilityRecordFunctionCalloutPtr */
    , Sd_Client                                 /**< the pointer to Sd_Client */
    , Sd_ClientDyn                              /**< the pointer to Sd_ClientDyn */
    , Sd_ClientIdMap                            /**< the pointer to Sd_ClientIdMap */
    , Sd_ClientList                             /**< the pointer to Sd_ClientList */
    , Sd_ClientTimer                            /**< the pointer to Sd_ClientTimer */
    , NULL_PTR                                  /**< the pointer to Sd_CommonInitialDelay */
    , Sd_ConsumedEventgroup                     /**< the pointer to Sd_ConsumedEventgroup */
    , Sd_ConsumedEventgroupDyn                  /**< the pointer to Sd_ConsumedEventgroupDyn */
    , Sd_ConsumedEventgroupIdMap                /**< the pointer to Sd_ConsumedEventgroupIdMap */
    , Sd_EndpointStorage                        /**< the pointer to Sd_EndpointStorage */
    , Sd_EventHandler                           /**< the pointer to Sd_EventHandler */
    , Sd_EventHandlerDyn                        /**< the pointer to Sd_EventHandlerDyn */
    , NULL_PTR                                  /**< the pointer to Sd_EventHandlerMulticast */
    , NULL_PTR                                  /**< the pointer to Sd_EventHandlerTcp */
    , Sd_EventHandlerUdp                        /**< the pointer to Sd_EventHandlerUdp */
    , Sd_Instance                               /**< the pointer to Sd_Instance */
    , Sd_InstanceDyn                            /**< the pointer to Sd_InstanceDyn */
    , NULL_PTR                                  /**< the pointer to Sd_IpAddrRequest */
    , NULL_PTR                                  /**< the pointer to Sd_Method */
    , NULL_PTR                                  /**< the pointer to Sd_MulticastEndpointAddr */
    , NULL_PTR                                  /**< the pointer to Sd_MulticastSoConId */
    , Sd_OptionIndex                            /**< the pointer to Sd_OptionIndex */
    , Sd_PartitionDataDyn                       /**< the pointer to Sd_PartitionDataDyn */
    , Sd_Payload                                /**< the pointer to Sd_Payload */
    , NULL_PTR                                  /**< the pointer to Sd_PortSet */
    , NULL_PTR                                  /**< the pointer to Sd_RequestCnt */
    , Sd_RoutingGroup                           /**< the pointer to Sd_RoutingGroup */
    , Sd_RoutingGroupDyn                        /**< the pointer to Sd_RoutingGroupDyn */
    , NULL_PTR                                  /**< the pointer to Sd_RoutingGroupIdMap */
    , Sd_RxEvent                                /**< the pointer to Sd_RxEvent */
    , Sd_RxPduIdMap                             /**< the pointer to Sd_RxPduIdMap */
    , Sd_SendEntry                              /**< the pointer to Sd_SendEntry */
    , Sd_Server                                 /**< the pointer to Sd_Server */
    , Sd_ServerDyn                              /**< the pointer to Sd_ServerDyn */
    , Sd_ServerIdMap                            /**< the pointer to Sd_ServerIdMap */
    , Sd_ServerTimer                            /**< the pointer to Sd_ServerTimer */
    , NULL_PTR                                  /**< the pointer to Sd_ServiceGroup */
    , NULL_PTR                                  /**< the pointer to Sd_ServiceGroupIdMap */
    , NULL_PTR                                  /**< the pointer to Sd_ServiceGroupMember */
    , Sd_SoConActivationMap                     /**< the pointer to Sd_SoConActivationMap */
    , Sd_SoConGrpDyn                            /**< the pointer to Sd_SoConGrpDyn */
    , Sd_SoConModeDyn                           /**< the pointer to Sd_SoConModeDyn */
    , Sd_SoConModeIdMap                         /**< the pointer to Sd_SoConModeIdMap */
    , NULL_PTR                                  /**< the pointer to Sd_TcpSoConId */
    , NULL_PTR                                  /**< the pointer to Sd_TriggerTransmitDyn */
    , Sd_TxSoConIdMap                           /**< the pointer to Sd_TxSoConIdMap */
    , Sd_UdpSoCon                               /**< the pointer to Sd_UdpSoCon */
    , 1464u                                     /**< the number of elements in Sd_Payload */
    , 0u                                        /**< the number of elements in Sd_AclIPv4 */
    , 0u                                        /**< the number of elements in Sd_AclIPv4CInd */
    , 0u                                        /**< the number of elements in Sd_AclIPv4SInd */
    , 0u                                        /**< the number of elements in Sd_AclIPv6 */
    , 0u                                        /**< the number of elements in Sd_AclIPv6CInd */
    , 0u                                        /**< the number of elements in Sd_AclIPv6SInd */
    , 16u                                       /**< the number of elements in Sd_AddressStorage */
    , 0u                                        /**< the number of elements in Sd_CapabilityRecord */
    , 0u                                        /**< the number of elements in Sd_CapabilityRecordFunctionCalloutPtr */
    , 1u                                        /**< the number of elements in Sd_Client */
    , 1u                                        /**< the number of elements in Sd_ClientIdMap */
    , 3u                                        /**< the number of elements in Sd_ClientList */
    , 2u                                        /**< the number of elements in Sd_ClientTimer */
    , 0u                                        /**< the number of elements in Sd_CommonInitialDelay */
    , 1u                                        /**< the number of elements in Sd_ConsumedEventgroup */
    , 1u                                        /**< the number of elements in Sd_ConsumedEventgroupIdMap */
    , 32u                                       /**< the number of elements in Sd_EndpointStorage */
    , 3u                                        /**< the number of elements in Sd_EventHandler */
    , 0u                                        /**< the number of elements in Sd_EventHandlerMulticast */
    , 0u                                        /**< the number of elements in Sd_EventHandlerTcp */
    , 3u                                        /**< the number of elements in Sd_EventHandlerUdp */
    , 1u                                        /**< the number of elements in Sd_Instance */
    , 0u                                        /**< the number of elements in Sd_IpAddrRequest */
    , 0u                                        /**< the number of elements in Sd_Method */
    , 0u                                        /**< the number of elements in Sd_MulticastEndpointAddr */
    , 0u                                        /**< the number of elements in Sd_MulticastSoConId */
    , 10u                                       /**< the number of elements in Sd_OptionIndex */
    , 1u                                        /**< the number of elements in Sd_PartitionDataDyn */
    , 0u                                        /**< the number of elements in Sd_PortSet */
    , 0u                                        /**< the number of elements in Sd_RequestCnt */
    , 4u                                        /**< the number of elements in Sd_RoutingGroup */
    , 0u                                        /**< the number of elements in Sd_RoutingGroupIdMap */
    , 96u                                       /**< the number of elements in Sd_RxEvent */
    , 2u                                        /**< the number of elements in Sd_RxPduIdMap */
    , 96u                                       /**< the number of elements in Sd_SendEntry */
    , 3u                                        /**< the number of elements in Sd_Server */
    , 3u                                        /**< the number of elements in Sd_ServerIdMap */
    , 6u                                        /**< the number of elements in Sd_ServerTimer */
    , 0u                                        /**< the number of elements in Sd_ServiceGroup */
    , 0u                                        /**< the number of elements in Sd_ServiceGroupIdMap */
    , 0u                                        /**< the number of elements in Sd_ServiceGroupMember */
    , 3u                                        /**< the number of elements in Sd_SoConActivationMap */
    , 2u                                        /**< the number of elements in Sd_SoConGrpDyn */
    , 2u                                        /**< the number of elements in Sd_SoConModeDyn */
    , 4u                                        /**< the number of elements in Sd_SoConModeIdMap */
    , 0u                                        /**< the number of elements in Sd_TcpSoConId */
    , 0u                                        /**< the number of elements in Sd_TriggerTransmitDyn */
    , 1u                                        /**< the number of elements in Sd_TxSoConIdMap */
    , 2u                                        /**< the number of elements in Sd_UdpSoCon */
  }
};
#define SD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define SD_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

FUNC(void, SD_CODE) Sd_MainFunction(void)
{
  Sd_MainFunctionPartition(0u);
}



#define SD_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Sd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/* PRQA L:MACRO_LIMIT */

/**********************************************************************************************************************
 *  END OF FILE: Sd_Lcfg.c
 *********************************************************************************************************************/

