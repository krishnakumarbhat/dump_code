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
 *            Module: SoAd
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: SoAd_Lcfg.c
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
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] SOAD01500 - BSW Module configuration error. 
 * - [Reduced Severity due to User-Defined Parameter] /ActiveEcuC/Xcp only supports /ActiveEcuC/SoAd/Xcp[0:SoAdIfTxConfirmation](value=false) set to true. [invariant data view used]
 * Erroneous configuration elements:
 * /ActiveEcuC/SoAd/Xcp[0:SoAdIfTxConfirmation](value=false) (DefRef: /MICROSAR/SoAd/SoAdBswModules/SoAdIfTxConfirmation)
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/
#define SOAD_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "SoAd.h"
#include "SoAd_Priv.h"
#include "TcpIp.h"
#include "PduR_SoAd.h" 
#include "Cdd_Cbk.h" 
#include "TcpIpXcp_Cbk.h" 
#include "Sd_Cbk.h" 

# include "SoAd_Lcfg.h"



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if defined (STATIC)
#else
# define STATIC static
#endif

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  SoAd_EventQueueIdent
**********************************************************************************************************************/
/** 
  \var    SoAd_EventQueueIdent
  \brief  the event queue identification to get the index of a specific event queue
  \details
  Element                             Description
  EventQueueFlagEndIdx                the end index of the 1:n relation pointing to SoAd_EventQueueFlag
  EventQueueFlagStartIdx              the start index of the 1:n relation pointing to SoAd_EventQueueFlag
  EventQueueIfTxRouteGrpConfigIdx     the index of the 0:1 relation pointing to SoAd_EventQueueIfTxRouteGrpConfig
  EventQueueIfUdpPduRouteConfigIdx    the index of the 0:1 relation pointing to SoAd_EventQueueIfUdpPduRouteConfig
  EventQueueStateSoConConfigIdx       the index of the 1:1 relation pointing to SoAd_EventQueueStateSoConConfig
  EventQueueTpRxSoConConfigIdx        the index of the 0:1 relation pointing to SoAd_EventQueueTpRxSoConConfig
  EventQueueTpTxSoConConfigIdx        the index of the 0:1 relation pointing to SoAd_EventQueueTpTxSoConConfig
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_EventQueueIdentType, SOAD_CONST) SoAd_EventQueueIdent[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    EventQueueFlagEndIdx  EventQueueFlagStartIdx  EventQueueIfTxRouteGrpConfigIdx                           EventQueueIfUdpPduRouteConfigIdx  EventQueueStateSoConConfigIdx  EventQueueTpRxSoConConfigIdx                           EventQueueTpTxSoConConfigIdx                                 Referable Keys */
  { /*     0 */                   9u,                     0u, SOAD_NO_EVENTQUEUEIFTXROUTEGRPCONFIGIDXOFEVENTQUEUEIDENT,                               0u,                            0u, SOAD_NO_EVENTQUEUETPRXSOCONCONFIGIDXOFEVENTQUEUEIDENT, SOAD_NO_EVENTQUEUETPTXSOCONCONFIGIDXOFEVENTQUEUEIDENT }   /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdInstance] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_EventQueueIfUdpPduRouteConfig
**********************************************************************************************************************/
/** 
  \var    SoAd_EventQueueIfUdpPduRouteConfig
  \brief  the configuration of the specific event queue
  \details
  Element                            Description
  EventQueueIfUdpPduRouteEndIdx      the end index of the 1:n relation pointing to SoAd_EventQueueIfUdpPduRoute
  EventQueueIfUdpPduRouteStartIdx    the start index of the 1:n relation pointing to SoAd_EventQueueIfUdpPduRoute
  EventQueueMgmtIdx                  the index of the 1:1 relation pointing to SoAd_EventQueueMgmt
  FlagOffset                         the relative offset per instance within the event queue flags array
  Limit                              the limit of events handled in a single main function call
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_EventQueueIfUdpPduRouteConfigType, SOAD_CONST) SoAd_EventQueueIfUdpPduRouteConfig[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    EventQueueIfUdpPduRouteEndIdx  EventQueueIfUdpPduRouteStartIdx  EventQueueMgmtIdx  FlagOffset  Limit        Referable Keys */
  { /*     0 */                            8u,                              0u,                1u,         0u,    8u }   /* [SoAdEventQueueIfUdpPduRoute_SoAdInstance] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_EventQueueStateSoConConfig
**********************************************************************************************************************/
/** 
  \var    SoAd_EventQueueStateSoConConfig
  \brief  the configuration of the specific event queue
  \details
  Element                         Description
  EventQueueMgmtIdx               the index of the 1:1 relation pointing to SoAd_EventQueueMgmt
  EventQueueStateSoConEndIdx      the end index of the 1:n relation pointing to SoAd_EventQueueStateSoCon
  EventQueueStateSoConStartIdx    the start index of the 1:n relation pointing to SoAd_EventQueueStateSoCon
  FlagOffset                      the relative offset per instance within the event queue flags array
  Limit                           the limit of events handled in a single main function call
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_EventQueueStateSoConConfigType, SOAD_CONST) SoAd_EventQueueStateSoConConfig[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    EventQueueMgmtIdx  EventQueueStateSoConEndIdx  EventQueueStateSoConStartIdx  FlagOffset  Limit        Referable Keys */
  { /*     0 */                0u,                         9u,                           0u,         0u,    9u }   /* [SoAdEventQueueStateSoCon_SoAdInstance] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_Instance
**********************************************************************************************************************/
/** 
  \var    SoAd_Instance
  \brief  contains the event queue and timeout list indexes
  \details
  Element                          Description
  BestMatchSoConIdxListEndIdx      the end index of the 1:n relation pointing to SoAd_BestMatchSoConIdxList
  BestMatchSoConIdxListStartIdx    the start index of the 1:n relation pointing to SoAd_BestMatchSoConIdxList
  EventQueueIdentIdx               the index of the 1:1 relation pointing to SoAd_EventQueueIdent
  IpFragBufConfigEndIdx            the end index of the 0:n relation pointing to SoAd_IpFragBufConfig
  IpFragBufConfigStartIdx          the start index of the 0:n relation pointing to SoAd_IpFragBufConfig
  TimeoutListIdentIdx              the index of the 1:1 relation pointing to SoAd_TimeoutListIdent
  TriggerBufConfigEndIdx           the end index of the 0:n relation pointing to SoAd_TriggerBufConfig
  TriggerBufConfigStartIdx         the start index of the 0:n relation pointing to SoAd_TriggerBufConfig
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_InstanceType, SOAD_CONST) SoAd_Instance[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    BestMatchSoConIdxListEndIdx  BestMatchSoConIdxListStartIdx  EventQueueIdentIdx  IpFragBufConfigEndIdx                    IpFragBufConfigStartIdx                    TimeoutListIdentIdx  TriggerBufConfigEndIdx                    TriggerBufConfigStartIdx                          Referable Keys */
  { /*     0 */                          2u,                            0u,                 0u, SOAD_NO_IPFRAGBUFCONFIGENDIDXOFINSTANCE, SOAD_NO_IPFRAGBUFCONFIGSTARTIDXOFINSTANCE,                  0u, SOAD_NO_TRIGGERBUFCONFIGENDIDXOFINSTANCE, SOAD_NO_TRIGGERBUFCONFIGSTARTIDXOFINSTANCE }   /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_a83a7734, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL, /ActiveEcuC/SoAd/SoAdConfig/SoAdInstance] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_InstanceMap
**********************************************************************************************************************/
/** 
  \var    SoAd_InstanceMap
  \brief  the partition-unspecific instanceMap ID mapping to partition-specific instance
  \details
  Element                                  Description
  PartitionSpecificInstanceIdx             the index of the 1:1 relation pointing to one of SoAd_Instance
  PartitionSpecificInstancePartitionIdx    the partition index of the 1:1 relation pointing to one of SoAd_Instance
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_InstanceMapType, SOAD_CONST) SoAd_InstanceMap[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    PartitionSpecificInstanceIdx  PartitionSpecificInstancePartitionIdx                                      Referable Keys */
  { /*     0 */                           0u,                                    0u  /* SOAD_NO_OS_APPL_MAPPED */ }   /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdInstance] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_LocalAddr
**********************************************************************************************************************/
/** 
  \var    SoAd_LocalAddr
  \brief  the local address configurations
  \details
  Element             Description
  SoConGrpEndIdx      the end index of the 0:n relation pointing to SoAd_SoConGrp
  SoConGrpStartIdx    the start index of the 0:n relation pointing to SoAd_SoConGrp
  TcpIpCtrlIdx        the index of the 1:1 relation pointing to SoAd_TcpIpCtrl
  Domain              the IP domain (IPv4/6)
  AddrId              the address identifier to identify the local address at TcpIp
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_LocalAddrType, SOAD_CONST) SoAd_LocalAddr[2] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    SoConGrpEndIdx  SoConGrpStartIdx  TcpIpCtrlIdx  Domain        AddrId                                                                   Referable Keys */
  { /*     0 */             6u,               0u,           0u, SOAD_AF_INET, TcpIpConf_TcpIpLocalAddr_NEP_SRR_1_RdrNet_Unicast_48476027        },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027, /ActiveEcuC/TcpIp/TcpIpConfig/cnctr_RDR_RdrNet_1bd20df5] */
  { /*     1 */             7u,               6u,           0u, SOAD_AF_INET, TcpIpConf_TcpIpLocalAddr_NEP_ADAS_RdrNet_CtrlRxMulticast_91909614 }   /* [/ActiveEcuC/TcpIp/TcpIpConfig/NEP_ADAS_RdrNet_CtrlRxMulticast_91909614] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_LocalAddrByTcpIpCtrlInd
**********************************************************************************************************************/
/** 
  \var    SoAd_LocalAddrByTcpIpCtrlInd
  \brief  the indexes of the 1:1 sorted relation pointing to SoAd_LocalAddr
*/ 
#define SOAD_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_LocalAddrByTcpIpCtrlIndType, SOAD_CONST) SoAd_LocalAddrByTcpIpCtrlInd[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     LocalAddrByTcpIpCtrlInd      Referable Keys */
  /*     0 */                       0u   /* [/ActiveEcuC/TcpIp/TcpIpConfig/cnctr_RDR_RdrNet_1bd20df5] */
};
#define SOAD_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_LocalAddrIdMap
**********************************************************************************************************************/
/** 
  \var    SoAd_LocalAddrIdMap
  \brief  the partition-unspecific LocalAddrId mapping to partition-specific LocalAddr
  \details
  Element                                   Description
  InvalidHnd                                FALSE, if the handle of SoAd_LocalAddrIdMap is valid and can be used in the embedded code for further processing in the embedded code.
  PartitionSpecificLocalAddrIdx             the index of the 0:1 relation pointing to SoAd_LocalAddr
  PartitionSpecificLocalAddrPartitionIdx    the partition index of the 0:1 relation pointing to SoAd_LocalAddr
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_LocalAddrIdMapType, SOAD_CONST) SoAd_LocalAddrIdMap[4] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    InvalidHnd  PartitionSpecificLocalAddrIdx                          PartitionSpecificLocalAddrPartitionIdx                                                              Referable Keys */
  { /*     0 */      FALSE,                                                    0u,                                                             0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027] */
  { /*     1 */      FALSE,                                                    1u,                                                             0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/NEP_ADAS_RdrNet_CtrlRxMulticast_91909614] */
  { /*     2 */      FALSE, SOAD_NO_PARTITIONSPECIFICLOCALADDRIDXOFLOCALADDRIDMAP, SOAD_NO_PARTITIONSPECIFICLOCALADDRPARTITIONIDXOFLOCALADDRIDMAP                               },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/NEP_ANY_IP_c7cdbb5a] */
  { /*     3 */      FALSE, SOAD_NO_PARTITIONSPECIFICLOCALADDRIDXOFLOCALADDRIDMAP, SOAD_NO_PARTITIONSPECIFICLOCALADDRPARTITIONIDXOFLOCALADDRIDMAP                               }   /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpV4LocalAddr_RDR_EthConnector1_fbdc15b4_Broadcast] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_LocalIpAddrAssignmentChgCbk
**********************************************************************************************************************/
/** 
  \var    SoAd_LocalIpAddrAssignmentChgCbk
  \brief  the callback Up_LocalIpAddrAssignmentChg
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_LocalIpAddrAssignmentChgCbkType, SOAD_CONST) SoAd_LocalIpAddrAssignmentChgCbk[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     LocalIpAddrAssignmentChgCbk      Referable Keys */
  /*     0 */ NULL_PTR    /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d/ConnectionBundle_ADAS_53ce198e, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201/ConnectionBundle2_14f4c9c7, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_a83a7734/ConnectionBundle4_81a0ef65] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_LocalIpAddrAssignmentChgCbkInd
**********************************************************************************************************************/
/** 
  \var    SoAd_LocalIpAddrAssignmentChgCbkInd
  \brief  the indexes of the 1:1 sorted relation pointing to SoAd_LocalIpAddrAssignmentChgCbk
*/ 
#define SOAD_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_LocalIpAddrAssignmentChgCbkIndType, SOAD_CONST) SoAd_LocalIpAddrAssignmentChgCbkInd[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     LocalIpAddrAssignmentChgCbkInd      Referable Keys */
  /*     0 */                              0u,  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201/ConnectionBundle2_14f4c9c7] */
  /*     1 */                              0u,  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815] */
  /*     2 */                              0u   /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_a83a7734/ConnectionBundle4_81a0ef65] */
};
#define SOAD_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    SoAd_PartitionIdentifiers
  \brief  the partition context in Config
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to SoAd_PCPartitionConfig
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_PartitionIdentifiersType, SOAD_CONST) SoAd_PartitionIdentifiers[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionSNV            PCPartitionConfigIdx */
  { /*     0 */ SOAD_NO_OS_APPL_MAPPED,                   0u }
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_PduRoute
**********************************************************************************************************************/
/** 
  \var    SoAd_PduRoute
  \brief  the SoAdPduRoutes configuration
  \details
  Element                      Description
  TxConfPduId                  the TxPduId used to call upper layer
  AllPduRouteDestWithPduHdr    indicates if all related SoAdPduRouteDests have a SoAdTxPduHeaderId
  IfOptimisticTransmit         indicates if IF optimistic transmit is used
  MetaDataTxEnabled            indicates if transmission on specific socket connection via meta data is enabled
  TxConfEnabled                indicates if TxConfirmation is enabled
  TxOptimized                  indicates if Tx optimized is enabled
  PduRouteDestEndIdx           the end index of the 1:n relation pointing to SoAd_PduRouteDest
  PduRouteDestStartIdx         the start index of the 1:n relation pointing to SoAd_PduRouteDest
  UpperLayerIdx                the index of the 1:1 relation pointing to SoAd_UpperLayer
  IfTriggerTransmitMode        the trigger transmit mode
  UpperLayerApi                the upper layer API type (IF/TP)
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_PduRouteType, SOAD_CONST) SoAd_PduRoute[8] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    TxConfPduId                                                                        AllPduRouteDestWithPduHdr  IfOptimisticTransmit  MetaDataTxEnabled  TxConfEnabled  TxOptimized  PduRouteDestEndIdx  PduRouteDestStartIdx  UpperLayerIdx  IfTriggerTransmitMode                UpperLayerApi         Referable Keys */
  { /*     0 */ 0u                                                                               ,                      TRUE,                FALSE,             FALSE,         FALSE,       FALSE,                 1u,                   0u,            3u, SOAD_IF_TRIGGER_TRANSMIT_MODE_NONE , SOAD_UL_API_IF },  /* [/ActiveEcuC/SoAd/SoAdConfig/GenerelPurposePDU3_a3a5c5ac_Tx] */
  { /*     1 */ 0u                                                                               ,                     FALSE,                FALSE,             FALSE,         FALSE,       FALSE,                 2u,                   1u,            2u, SOAD_IF_TRIGGER_TRANSMIT_MODE_NONE , SOAD_UL_API_IF },  /* [/ActiveEcuC/SoAd/SoAdConfig/RDR_ETH_XCP_TX] */
  { /*     2 */ 0u                                                                               ,                     FALSE,                FALSE,             FALSE,         FALSE,       FALSE,                 3u,                   2u,            1u, SOAD_IF_TRIGGER_TRANSMIT_MODE_NONE , SOAD_UL_API_IF },  /* [/ActiveEcuC/SoAd/SoAdConfig/RDR_LOGGING_TX] */
  { /*     3 */ 0u                                                                               ,                     FALSE,                FALSE,             FALSE,         FALSE,       FALSE,                 4u,                   3u,            1u, SOAD_IF_TRIGGER_TRANSMIT_MODE_NONE , SOAD_UL_API_IF },  /* [/ActiveEcuC/SoAd/SoAdConfig/RDR_LOGGING_TX_FAST] */
  { /*     4 */ 0u                                                                               ,                     FALSE,                FALSE,             FALSE,         FALSE,       FALSE,                 5u,                   4u,            1u, SOAD_IF_TRIGGER_TRANSMIT_MODE_NONE , SOAD_UL_API_IF },  /* [/ActiveEcuC/SoAd/SoAdConfig/RDR_HIL_TX] */
  { /*     5 */ PduRConf_PduRDestPdu_signalPdu_RDR_1_Detections_Transport_d322aa23_Tx_f4b7358b_Tx,                      TRUE,                 TRUE,             FALSE,          TRUE,        TRUE,                 6u,                   5u,            0u, SOAD_IF_TRIGGER_TRANSMIT_MODE_MULTI, SOAD_UL_API_IF },  /* [/ActiveEcuC/SoAd/SoAdConfig/signalPdu_RDR_1_Detections_Transport_d322aa23_Tx] */
  { /*     6 */ 0u                                                                               ,                      TRUE,                FALSE,             FALSE,         FALSE,       FALSE,                 7u,                   6u,            0u, SOAD_IF_TRIGGER_TRANSMIT_MODE_NONE , SOAD_UL_API_IF },  /* [/ActiveEcuC/SoAd/SoAdConfig/signalPdu_RDR_1_SW_Info_14232baa_Tx] */
  { /*     7 */ 0u                                                                               ,                      TRUE,                FALSE,             FALSE,         FALSE,       FALSE,                 8u,                   7u,            0u, SOAD_IF_TRIGGER_TRANSMIT_MODE_NONE , SOAD_UL_API_IF }   /* [/ActiveEcuC/SoAd/SoAdConfig/signalPdu_RDR_1_Status_67c6fd21_Tx] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_PduRouteDest
**********************************************************************************************************************/
/** 
  \var    SoAd_PduRouteDest
  \brief  the PduRouteDests configuraion
  \details
  Element                                   Description
  TxPduHdrId                                the PDU header ID
  PduRouteIdx                               the index of the 1:1 relation pointing to SoAd_PduRoute
  RouteGrpSoConByPduRouteDestIndEndIdx      the end index of the 0:n relation pointing to SoAd_RouteGrpSoConByPduRouteDestInd
  RouteGrpSoConByPduRouteDestIndStartIdx    the start index of the 0:n relation pointing to SoAd_RouteGrpSoConByPduRouteDestInd
  SoConIdx                                  the index of the 1:1 relation pointing to SoAd_SoCon
  UdpTriggerTimeout                         the PduRouteDest specific timeout to send a nPdu
  TxUdpTriggerMode                          indicates if nPdu shall be sent on transmission request always or never
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_PduRouteDestType, SOAD_CONST) SoAd_PduRouteDest[8] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    TxPduHdrId   PduRouteIdx  RouteGrpSoConByPduRouteDestIndEndIdx                        RouteGrpSoConByPduRouteDestIndStartIdx                        SoConIdx  UdpTriggerTimeout  TxUdpTriggerMode                  Referable Keys */
  { /*     0 */ 0xFFFF8100u,          0u, SOAD_NO_ROUTEGRPSOCONBYPDUROUTEDESTINDENDIDXOFPDUROUTEDEST, SOAD_NO_ROUTEGRPSOCONBYPDUROUTEDESTINDSTARTIDXOFPDUROUTEDEST,       1u,                0u, SOAD_TX_UDP_TRIGGER_ALWAYS },  /* [/ActiveEcuC/SoAd/SoAdConfig/GenerelPurposePDU3_a3a5c5ac_Tx, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201/ConnectionBundle2_14f4c9c7] */
  { /*     1 */ 0x00000000u,          1u,                                                         1u,                                                           0u,       0u,                0u, SOAD_TX_UDP_TRIGGER_ALWAYS },  /* [/ActiveEcuC/SoAd/SoAdConfig/RDR_ETH_XCP_TX, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP/SoAdSocketConnection_XCP, /ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup] */
  { /*     2 */ 0x00000000u,          2u,                                                         2u,                                                           1u,       4u,                0u, SOAD_TX_UDP_TRIGGER_ALWAYS },  /* [/ActiveEcuC/SoAd/SoAdConfig/RDR_LOGGING_TX, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/ConnectionBundle_RDR_1_94fef815_001, /ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup] */
  { /*     3 */ 0x00000000u,          3u,                                                         3u,                                                           2u,       4u,                0u, SOAD_TX_UDP_TRIGGER_ALWAYS },  /* [/ActiveEcuC/SoAd/SoAdConfig/RDR_LOGGING_TX_FAST, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/ConnectionBundle_RDR_1_94fef815_001, /ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup] */
  { /*     4 */ 0x00000000u,          4u,                                                         4u,                                                           3u,       7u,                0u, SOAD_TX_UDP_TRIGGER_ALWAYS },  /* [/ActiveEcuC/SoAd/SoAdConfig/RDR_HIL_TX, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL/SoAdSocketConnection_HIL_Tx, /ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup] */
  { /*     5 */ 0x00108001u,          5u,                                                         5u,                                                           4u,       2u,                0u, SOAD_TX_UDP_TRIGGER_ALWAYS },  /* [/ActiveEcuC/SoAd/SoAdConfig/signalPdu_RDR_1_Detections_Transport_d322aa23_Tx, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815, /ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup2_be5f5f2f] */
  { /*     6 */ 0x00128002u,          6u,                                                         6u,                                                           5u,       2u,                0u, SOAD_TX_UDP_TRIGGER_ALWAYS },  /* [/ActiveEcuC/SoAd/SoAdConfig/signalPdu_RDR_1_SW_Info_14232baa_Tx, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815, /ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup3_c9586fb9] */
  { /*     7 */ 0x00118003u,          7u,                                                         7u,                                                           6u,       2u,                0u, SOAD_TX_UDP_TRIGGER_ALWAYS }   /* [/ActiveEcuC/SoAd/SoAdConfig/signalPdu_RDR_1_Status_67c6fd21_Tx, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815, /ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup4_573cfa1a] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_PduRouteDestBySoConInd
**********************************************************************************************************************/
/** 
  \var    SoAd_PduRouteDestBySoConInd
  \brief  the indexes of the 1:1 sorted relation pointing to SoAd_PduRouteDest
*/ 
#define SOAD_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_PduRouteDestBySoConIndType, SOAD_CONST) SoAd_PduRouteDestBySoConInd[8] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     PduRouteDestBySoConInd      Referable Keys */
  /*     0 */                      1u,  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP/SoAdSocketConnection_XCP] */
  /*     1 */                      0u,  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201/ConnectionBundle2_14f4c9c7] */
  /*     2 */                      5u,  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815] */
  /*     3 */                      6u,  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815] */
  /*     4 */                      7u,  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815] */
  /*     5 */                      2u,  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/ConnectionBundle_RDR_1_94fef815_001] */
  /*     6 */                      3u,  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/ConnectionBundle_RDR_1_94fef815_001] */
  /*     7 */                      4u   /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL/SoAdSocketConnection_HIL_Tx] */
};
#define SOAD_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_PduRouteDestInd
**********************************************************************************************************************/
/** 
  \var    SoAd_PduRouteDestInd
  \brief  the indexes of the 1:1 sorted relation pointing to SoAd_PduRouteDest
*/ 
#define SOAD_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_PduRouteDestIndType, SOAD_CONST) SoAd_PduRouteDestInd[7] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     PduRouteDestInd      Referable Keys */
  /*     0 */               1u,  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup] */
  /*     1 */               2u,  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup] */
  /*     2 */               3u,  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup] */
  /*     3 */               4u,  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup] */
  /*     4 */               5u,  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup2_be5f5f2f] */
  /*     5 */               6u,  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup3_c9586fb9] */
  /*     6 */               7u   /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup4_573cfa1a] */
};
#define SOAD_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_RemAddrIpV4
**********************************************************************************************************************/
/** 
  \var    SoAd_RemAddrIpV4
  \brief  the configured IPv4 remote addresses for each IPv4 socket connection
  \details
  Element    Description
  Addr       the remote IPv4 address
  Port       the remote port
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_RemAddrIpV4Type, SOAD_CONST) SoAd_RemAddrIpV4[9] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    Addr                                              Port           Referable Keys */
  { /*     0 */ 0x00000000u /*  0.0.0.0 LITTLE_ENDIAN  */       , 0xE8FDu },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP/SoAdSocketConnection_XCP] */
  { /*     1 */ 0x00000000u /*  0.0.0.0 LITTLE_ENDIAN  */       , 0x0000u },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201/ConnectionBundle2_14f4c9c7] */
  { /*     2 */ 0x6401A8C0u /*  192.168.1.100 LITTLE_ENDIAN  */ , 0x2577u },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815] */
  { /*     3 */ 0x6401A8C0u /*  192.168.1.100 LITTLE_ENDIAN  */ , 0xC586u },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d/ConnectionBundle_ADAS_53ce198e] */
  { /*     4 */ 0x2801A8C0u /*  192.168.1.40 LITTLE_ENDIAN  */  , 0xB315u },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/ConnectionBundle_RDR_1_94fef815_001] */
  { /*     5 */ 0x00000000u /*  0.0.0.0 LITTLE_ENDIAN  */       , 0x0000u },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/SoAdSocketConnection_Veh_Rx_001] */
  { /*     6 */ 0x00000000u /*  0.0.0.0 LITTLE_ENDIAN  */       , 0x0000u },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL/SoAdSocketConnection_HIL_Rx] */
  { /*     7 */ 0x2801A8C0u /*  192.168.1.40 LITTLE_ENDIAN  */  , 0xB515u },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL/SoAdSocketConnection_HIL_Tx] */
  { /*     8 */ 0x00000000u /*  0.0.0.0 LITTLE_ENDIAN  */       , 0x0000u }   /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_a83a7734/ConnectionBundle4_81a0ef65] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_RouteGrp
**********************************************************************************************************************/
/** 
  \var    SoAd_RouteGrp
  \brief  the routing group configuration
  \details
  Element                    Description
  EnabledAtInit              indicates if RoutingGroup is initially enabled
  MultiInstanceOnGrp         indicates if RoutingGroup is used for the multi service instance use case on socket connection groups
  RxRequestEnable            indicates if RoutingGroup can be requested to be enabled on reception (via Sd_RequestRoutingGroupEnable)
  TxTriggerable              indicates if RoutingGroup can be sent
  PduRouteDestIndEndIdx      the end index of the 0:n relation pointing to SoAd_PduRouteDestInd
  PduRouteDestIndStartIdx    the start index of the 0:n relation pointing to SoAd_PduRouteDestInd
  RouteGrpId                 the Routing Group identifier used in SoAd API
  RouteGrpSoConEndIdx        the end index of the 1:n relation pointing to SoAd_RouteGrpSoCon
  RouteGrpSoConStartIdx      the start index of the 1:n relation pointing to SoAd_RouteGrpSoCon
  SocketRouteIndEndIdx       the end index of the 0:n relation pointing to SoAd_SocketRouteInd
  SocketRouteIndStartIdx     the start index of the 0:n relation pointing to SoAd_SocketRouteInd
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_RouteGrpType, SOAD_CONST) SoAd_RouteGrp[5] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    EnabledAtInit  MultiInstanceOnGrp  RxRequestEnable  TxTriggerable  PduRouteDestIndEndIdx                    PduRouteDestIndStartIdx                    RouteGrpId  RouteGrpSoConEndIdx  RouteGrpSoConStartIdx  SocketRouteIndEndIdx                    SocketRouteIndStartIdx                          Referable Keys */
  { /*     0 */          TRUE,              FALSE,           FALSE,         FALSE,                                      4u,                                        0u,         0u,                  4u,                    0u,                                     2u,                                       0u },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup] */
  { /*     1 */         FALSE,              FALSE,           FALSE,         FALSE, SOAD_NO_PDUROUTEDESTINDENDIDXOFROUTEGRP, SOAD_NO_PDUROUTEDESTINDSTARTIDXOFROUTEGRP,         1u,                  5u,                    4u,                                     3u,                                       2u },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup1_27560e95] */
  { /*     2 */         FALSE,              FALSE,           FALSE,         FALSE,                                      5u,                                        4u,         2u,                  6u,                    5u, SOAD_NO_SOCKETROUTEINDENDIDXOFROUTEGRP, SOAD_NO_SOCKETROUTEINDSTARTIDXOFROUTEGRP },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup2_be5f5f2f] */
  { /*     3 */         FALSE,              FALSE,           FALSE,         FALSE,                                      6u,                                        5u,         3u,                  7u,                    6u, SOAD_NO_SOCKETROUTEINDENDIDXOFROUTEGRP, SOAD_NO_SOCKETROUTEINDSTARTIDXOFROUTEGRP },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup3_c9586fb9] */
  { /*     4 */         FALSE,              FALSE,           FALSE,         FALSE,                                      7u,                                        6u,         4u,                  8u,                    7u, SOAD_NO_SOCKETROUTEINDENDIDXOFROUTEGRP, SOAD_NO_SOCKETROUTEINDSTARTIDXOFROUTEGRP }   /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup4_573cfa1a] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_RouteGrpIdMap
**********************************************************************************************************************/
/** 
  \var    SoAd_RouteGrpIdMap
  \brief  the partition-unspecific handle ID mapping to partition-specific SoAdRoutingGroupId
  \details
  Element                                  Description
  InvalidHnd                               FALSE, if the handle of SoAd_RouteGrpIdMap is valid and can be used in the embedded code for further processing in the embedded code.
  PartitionSpecificRouteGrpIdx             the index of the 0:1 relation pointing to SoAd_RouteGrp
  PartitionSpecificRouteGrpPartitionIdx    the partition index of the 0:1 relation pointing to SoAd_RouteGrp
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_RouteGrpIdMapType, SOAD_CONST) SoAd_RouteGrpIdMap[5] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    InvalidHnd  PartitionSpecificRouteGrpIdx  PartitionSpecificRouteGrpPartitionIdx                                      Referable Keys */
  { /*     0 */      FALSE,                           0u,                                    0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup] */
  { /*     1 */      FALSE,                           1u,                                    0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup1_27560e95] */
  { /*     2 */      FALSE,                           2u,                                    0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup2_be5f5f2f] */
  { /*     3 */      FALSE,                           3u,                                    0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup3_c9586fb9] */
  { /*     4 */      FALSE,                           4u,                                    0u  /* SOAD_NO_OS_APPL_MAPPED */ }   /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup4_573cfa1a] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_RouteGrpSoCon
**********************************************************************************************************************/
/** 
  \var    SoAd_RouteGrpSoCon
  \brief  the routing groups on the socket connections
  \details
  Element        Description
  RouteGrpIdx    the index of the 1:1 relation pointing to SoAd_RouteGrp
  SoConIdx       the index of the 1:1 relation pointing to SoAd_SoCon
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_RouteGrpSoConType, SOAD_CONST) SoAd_RouteGrpSoCon[8] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    RouteGrpIdx  SoConIdx        Referable Keys */
  { /*     0 */          0u,       0u },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketRoute_XCP_BSW/SoAdSocketRouteDest_XCP_RX_Eth>>/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP/SoAdSocketConnection_XCP, /ActiveEcuC/SoAd/SoAdConfig/RDR_ETH_XCP_TX/SoAdPduRouteDest>>/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP/SoAdSocketConnection_XCP] */
  { /*     1 */          0u,       4u },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup, /ActiveEcuC/SoAd/SoAdConfig/RDR_LOGGING_TX/SoAdPduRouteDest>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/ConnectionBundle_RDR_1_94fef815_001, /ActiveEcuC/SoAd/SoAdConfig/RDR_LOGGING_TX_FAST/SoAdPduRouteDest>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/ConnectionBundle_RDR_1_94fef815_001] */
  { /*     2 */          0u,       6u },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketRoute_HIL/SoAdSocketRouteDest_HIL>>/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL/SoAdSocketConnection_HIL_Rx] */
  { /*     3 */          0u,       7u },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup, /ActiveEcuC/SoAd/SoAdConfig/RDR_HIL_TX/SoAdPduRouteDest>>/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL/SoAdSocketConnection_HIL_Tx] */
  { /*     4 */          1u,       3u },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup1_27560e95, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_81eeb70b_Rx/ConnectionBundle_ADAS_f656ca1d>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d/ConnectionBundle_ADAS_53ce198e] */
  { /*     5 */          2u,       2u },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup2_be5f5f2f, /ActiveEcuC/SoAd/SoAdConfig/signalPdu_RDR_1_Detections_Transport_d322aa23_Tx/ConnectionBundle_RDR_1_94fef815>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815] */
  { /*     6 */          3u,       2u },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup3_c9586fb9, /ActiveEcuC/SoAd/SoAdConfig/signalPdu_RDR_1_SW_Info_14232baa_Tx/ConnectionBundle_RDR_1_94fef815>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815] */
  { /*     7 */          4u,       2u }   /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup4_573cfa1a, /ActiveEcuC/SoAd/SoAdConfig/signalPdu_RDR_1_Status_67c6fd21_Tx/ConnectionBundle_RDR_1_94fef815>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_RouteGrpSoConByPduRouteDestInd
**********************************************************************************************************************/
/** 
  \var    SoAd_RouteGrpSoConByPduRouteDestInd
  \brief  the indexes of the 1:1 sorted relation pointing to SoAd_RouteGrpSoCon
*/ 
#define SOAD_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_RouteGrpSoConByPduRouteDestIndType, SOAD_CONST) SoAd_RouteGrpSoConByPduRouteDestInd[7] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     RouteGrpSoConByPduRouteDestInd      Referable Keys */
  /*     0 */                              0u,  /* [/ActiveEcuC/SoAd/SoAdConfig/RDR_ETH_XCP_TX/SoAdPduRouteDest>>/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP/SoAdSocketConnection_XCP] */
  /*     1 */                              1u,  /* [/ActiveEcuC/SoAd/SoAdConfig/RDR_LOGGING_TX/SoAdPduRouteDest>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/ConnectionBundle_RDR_1_94fef815_001] */
  /*     2 */                              1u,  /* [/ActiveEcuC/SoAd/SoAdConfig/RDR_LOGGING_TX_FAST/SoAdPduRouteDest>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/ConnectionBundle_RDR_1_94fef815_001] */
  /*     3 */                              3u,  /* [/ActiveEcuC/SoAd/SoAdConfig/RDR_HIL_TX/SoAdPduRouteDest>>/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL/SoAdSocketConnection_HIL_Tx] */
  /*     4 */                              5u,  /* [/ActiveEcuC/SoAd/SoAdConfig/signalPdu_RDR_1_Detections_Transport_d322aa23_Tx/ConnectionBundle_RDR_1_94fef815>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815] */
  /*     5 */                              6u,  /* [/ActiveEcuC/SoAd/SoAdConfig/signalPdu_RDR_1_SW_Info_14232baa_Tx/ConnectionBundle_RDR_1_94fef815>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815] */
  /*     6 */                              7u   /* [/ActiveEcuC/SoAd/SoAdConfig/signalPdu_RDR_1_Status_67c6fd21_Tx/ConnectionBundle_RDR_1_94fef815>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815] */
};
#define SOAD_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_RouteGrpSoConBySocketRouteDestInd
**********************************************************************************************************************/
/** 
  \var    SoAd_RouteGrpSoConBySocketRouteDestInd
  \brief  the indexes of the 1:1 sorted relation pointing to SoAd_RouteGrpSoCon
*/ 
#define SOAD_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_RouteGrpSoConBySocketRouteDestIndType, SOAD_CONST) SoAd_RouteGrpSoConBySocketRouteDestInd[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     RouteGrpSoConBySocketRouteDestInd      Referable Keys */
  /*     0 */                                 0u,  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketRoute_XCP_BSW/SoAdSocketRouteDest_XCP_RX_Eth>>/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP/SoAdSocketConnection_XCP] */
  /*     1 */                                 4u,  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_81eeb70b_Rx/ConnectionBundle_ADAS_f656ca1d>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d/ConnectionBundle_ADAS_53ce198e] */
  /*     2 */                                 2u   /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketRoute_HIL/SoAdSocketRouteDest_HIL>>/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL/SoAdSocketConnection_HIL_Rx] */
};
#define SOAD_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_RxPduIdIdMap
**********************************************************************************************************************/
/** 
  \var    SoAd_RxPduIdIdMap
  \brief  the partition-unspecific handle ID mapping to partition-specific RxPduId
  \details
  Element                                         Description
  InvalidHnd                                      FALSE, if the handle of SoAd_RxPduIdIdMap is valid and can be used in the embedded code for further processing in the embedded code.
  PartitionSpecificSocketRouteDestIdx             the index of the 1:1 relation pointing to one of SoAd_SocketRouteDest
  PartitionSpecificSocketRouteDestPartitionIdx    the partition index of the 1:1 relation pointing to one of SoAd_SocketRouteDest
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_RxPduIdIdMapType, SOAD_CONST) SoAd_RxPduIdIdMap[6] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    InvalidHnd  PartitionSpecificSocketRouteDestIdx  PartitionSpecificSocketRouteDestPartitionIdx                                      Referable Keys */
  { /*     0 */      FALSE,                                  1u,                                           0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_44e6ad83_Rx] */
  { /*     1 */      FALSE,                                  5u,                                           0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_91e79f8a_Rx] */
  { /*     2 */      FALSE,                                  2u,                                           0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_81eeb70b_Rx] */
  { /*     3 */      FALSE,                                  4u,                                           0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketRoute_HIL] */
  { /*     4 */      FALSE,                                  3u,                                           0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketRoute_VEH_UDP_RX] */
  { /*     5 */      FALSE,                                  0u,                                           0u  /* SOAD_NO_OS_APPL_MAPPED */ }   /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketRoute_XCP_BSW] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_SoCon
**********************************************************************************************************************/
/** 
  \var    SoAd_SoCon
  \brief  the socket connection configuration
  \details
  Element                                   Description
  IpFragMgtIdx                              the index of the 0:1 relation pointing to SoAd_IpFragMgt
  LocalIpAddrAssignmentChgCbkIndEndIdx      the end index of the 0:n relation pointing to SoAd_LocalIpAddrAssignmentChgCbkInd
  LocalIpAddrAssignmentChgCbkIndStartIdx    the start index of the 0:n relation pointing to SoAd_LocalIpAddrAssignmentChgCbkInd
  NPduUdpTxIdx                              the index of the 0:1 relation pointing to SoAd_NPduUdpTx
  PduRouteDestBySoConIndEndIdx              the end index of the 0:n relation pointing to SoAd_PduRouteDestBySoConInd
  PduRouteDestBySoConIndStartIdx            the start index of the 0:n relation pointing to SoAd_PduRouteDestBySoConInd
  RemAddrIpV4Idx                            the index of the 0:1 relation pointing to SoAd_RemAddrIpV4
  RemAddrIpV6Idx                            the index of the 0:1 relation pointing to SoAd_RemAddrIpV6
  RemAddrRcvIdx                             the index of the 0:1 relation pointing to SoAd_RemAddrRcv
  RxBufStructMgtIdx                         the index of the 0:1 relation pointing to SoAd_RxBufStructMgt
  RxBufStructSegEndIdx                      the end index of the 0:n relation pointing to SoAd_RxBufStructSeg
  RxBufStructSegStartIdx                    the start index of the 0:n relation pointing to SoAd_RxBufStructSeg
  RxBufferConfigIdx                         the index of the 0:1 relation pointing to SoAd_RxBufferConfig
  RxMgtIdx                                  the index of the 0:1 relation pointing to SoAd_RxMgt
  SoConGrpIdx                               the index of the 1:1 relation pointing to SoAd_SoConGrp
  SoConId                                   the SocketConnection identifier used in SoAd API
  SoConModeChgCbkIndEndIdx                  the end index of the 0:n relation pointing to SoAd_SoConModeChgCbkInd
  SoConModeChgCbkIndStartIdx                the start index of the 0:n relation pointing to SoAd_SoConModeChgCbkInd
  SocketIdx                                 the index of the 1:1 relation pointing to SoAd_Socket
  SocketRouteEndIdx                         the end index of the 0:n relation pointing to SoAd_SocketRoute
  SocketRouteStartIdx                       the start index of the 0:n relation pointing to SoAd_SocketRoute
  TcpTxQueueIdx                             the index of the 0:1 relation pointing to SoAd_TcpTxQueue
  TpTxBufferConfigIdx                       the index of the 0:1 relation pointing to SoAd_TpTxBufferConfig
  TxMgtIdx                                  the index of the 0:1 relation pointing to SoAd_TxMgt
  RemAddrCfgState                           the configured remote address state
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_SoConType, SOAD_CONST) SoAd_SoCon[9] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    IpFragMgtIdx                 LocalIpAddrAssignmentChgCbkIndEndIdx                 LocalIpAddrAssignmentChgCbkIndStartIdx                 NPduUdpTxIdx                 PduRouteDestBySoConIndEndIdx                 PduRouteDestBySoConIndStartIdx                 RemAddrIpV4Idx  RemAddrIpV6Idx                 RemAddrRcvIdx                 RxBufStructMgtIdx                 RxBufStructSegEndIdx                 RxBufStructSegStartIdx                 RxBufferConfigIdx                 RxMgtIdx                 SoConGrpIdx  SoConId  SoConModeChgCbkIndEndIdx                 SoConModeChgCbkIndStartIdx                 SocketIdx  SocketRouteEndIdx                 SocketRouteStartIdx                 TcpTxQueueIdx                 TpTxBufferConfigIdx                 TxMgtIdx                 RemAddrCfgState                   Referable Keys */
  { /*     0 */ SOAD_NO_IPFRAGMGTIDXOFSOCON, SOAD_NO_LOCALIPADDRASSIGNMENTCHGCBKINDENDIDXOFSOCON, SOAD_NO_LOCALIPADDRASSIGNMENTCHGCBKINDSTARTIDXOFSOCON, SOAD_NO_NPDUUDPTXIDXOFSOCON,                                          1u,                                            0u,             0u, SOAD_NO_REMADDRIPV6IDXOFSOCON, SOAD_NO_REMADDRRCVIDXOFSOCON, SOAD_NO_RXBUFSTRUCTMGTIDXOFSOCON, SOAD_NO_RXBUFSTRUCTSEGENDIDXOFSOCON, SOAD_NO_RXBUFSTRUCTSEGSTARTIDXOFSOCON, SOAD_NO_RXBUFFERCONFIGIDXOFSOCON,                      0u,          0u,      8u,                                      1u,                                        0u,        0u,                               1u,                                 0u, SOAD_NO_TCPTXQUEUEIDXOFSOCON, SOAD_NO_TPTXBUFFERCONFIGIDXOFSOCON,                      0u, SOAD_SOCON_IP_ANY_PORT_SET },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP/SoAdSocketConnection_XCP, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP] */
  { /*     1 */ SOAD_NO_IPFRAGMGTIDXOFSOCON,                                                  1u,                                                    0u, SOAD_NO_NPDUUDPTXIDXOFSOCON,                                          2u,                                            1u,             1u, SOAD_NO_REMADDRIPV6IDXOFSOCON,                           0u, SOAD_NO_RXBUFSTRUCTMGTIDXOFSOCON, SOAD_NO_RXBUFSTRUCTSEGENDIDXOFSOCON, SOAD_NO_RXBUFSTRUCTSEGSTARTIDXOFSOCON, SOAD_NO_RXBUFFERCONFIGIDXOFSOCON,                      1u,          1u,      0u,                                      2u,                                        1u,        1u,                               2u,                                 1u, SOAD_NO_TCPTXQUEUEIDXOFSOCON, SOAD_NO_TPTXBUFFERCONFIGIDXOFSOCON,                      1u, SOAD_SOCON_IP_ANY_PORT_ANY },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201/ConnectionBundle2_14f4c9c7, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201] */
  { /*     2 */ SOAD_NO_IPFRAGMGTIDXOFSOCON,                                                  2u,                                                    1u, SOAD_NO_NPDUUDPTXIDXOFSOCON,                                          5u,                                            2u,             2u, SOAD_NO_REMADDRIPV6IDXOFSOCON, SOAD_NO_REMADDRRCVIDXOFSOCON, SOAD_NO_RXBUFSTRUCTMGTIDXOFSOCON, SOAD_NO_RXBUFSTRUCTSEGENDIDXOFSOCON, SOAD_NO_RXBUFSTRUCTSEGSTARTIDXOFSOCON, SOAD_NO_RXBUFFERCONFIGIDXOFSOCON, SOAD_NO_RXMGTIDXOFSOCON,          2u,      3u,                                      3u,                                        2u,        2u, SOAD_NO_SOCKETROUTEENDIDXOFSOCON, SOAD_NO_SOCKETROUTESTARTIDXOFSOCON, SOAD_NO_TCPTXQUEUEIDXOFSOCON, SOAD_NO_TPTXBUFFERCONFIGIDXOFSOCON,                      2u, SOAD_SOCON_IP_SET_PORT_SET },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe] */
  { /*     3 */ SOAD_NO_IPFRAGMGTIDXOFSOCON, SOAD_NO_LOCALIPADDRASSIGNMENTCHGCBKINDENDIDXOFSOCON, SOAD_NO_LOCALIPADDRASSIGNMENTCHGCBKINDSTARTIDXOFSOCON, SOAD_NO_NPDUUDPTXIDXOFSOCON, SOAD_NO_PDUROUTEDESTBYSOCONINDENDIDXOFSOCON, SOAD_NO_PDUROUTEDESTBYSOCONINDSTARTIDXOFSOCON,             3u, SOAD_NO_REMADDRIPV6IDXOFSOCON, SOAD_NO_REMADDRRCVIDXOFSOCON, SOAD_NO_RXBUFSTRUCTMGTIDXOFSOCON, SOAD_NO_RXBUFSTRUCTSEGENDIDXOFSOCON, SOAD_NO_RXBUFSTRUCTSEGSTARTIDXOFSOCON, SOAD_NO_RXBUFFERCONFIGIDXOFSOCON,                      2u,          3u,      2u,                                      4u,                                        3u,        4u,                               3u,                                 2u, SOAD_NO_TCPTXQUEUEIDXOFSOCON, SOAD_NO_TPTXBUFFERCONFIGIDXOFSOCON, SOAD_NO_TXMGTIDXOFSOCON, SOAD_SOCON_IP_SET_PORT_SET },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d/ConnectionBundle_ADAS_53ce198e, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d] */
  { /*     4 */ SOAD_NO_IPFRAGMGTIDXOFSOCON, SOAD_NO_LOCALIPADDRASSIGNMENTCHGCBKINDENDIDXOFSOCON, SOAD_NO_LOCALIPADDRASSIGNMENTCHGCBKINDSTARTIDXOFSOCON, SOAD_NO_NPDUUDPTXIDXOFSOCON,                                          7u,                                            5u,             4u, SOAD_NO_REMADDRIPV6IDXOFSOCON, SOAD_NO_REMADDRRCVIDXOFSOCON, SOAD_NO_RXBUFSTRUCTMGTIDXOFSOCON, SOAD_NO_RXBUFSTRUCTSEGENDIDXOFSOCON, SOAD_NO_RXBUFSTRUCTSEGSTARTIDXOFSOCON, SOAD_NO_RXBUFFERCONFIGIDXOFSOCON, SOAD_NO_RXMGTIDXOFSOCON,          4u,      4u, SOAD_NO_SOCONMODECHGCBKINDENDIDXOFSOCON, SOAD_NO_SOCONMODECHGCBKINDSTARTIDXOFSOCON,        5u, SOAD_NO_SOCKETROUTEENDIDXOFSOCON, SOAD_NO_SOCKETROUTESTARTIDXOFSOCON, SOAD_NO_TCPTXQUEUEIDXOFSOCON, SOAD_NO_TPTXBUFFERCONFIGIDXOFSOCON,                      3u, SOAD_SOCON_IP_SET_PORT_SET },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/ConnectionBundle_RDR_1_94fef815_001, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging] */
  { /*     5 */ SOAD_NO_IPFRAGMGTIDXOFSOCON, SOAD_NO_LOCALIPADDRASSIGNMENTCHGCBKINDENDIDXOFSOCON, SOAD_NO_LOCALIPADDRASSIGNMENTCHGCBKINDSTARTIDXOFSOCON, SOAD_NO_NPDUUDPTXIDXOFSOCON, SOAD_NO_PDUROUTEDESTBYSOCONINDENDIDXOFSOCON, SOAD_NO_PDUROUTEDESTBYSOCONINDSTARTIDXOFSOCON,             5u, SOAD_NO_REMADDRIPV6IDXOFSOCON, SOAD_NO_REMADDRRCVIDXOFSOCON, SOAD_NO_RXBUFSTRUCTMGTIDXOFSOCON, SOAD_NO_RXBUFSTRUCTSEGENDIDXOFSOCON, SOAD_NO_RXBUFSTRUCTSEGSTARTIDXOFSOCON, SOAD_NO_RXBUFFERCONFIGIDXOFSOCON,                      3u,          4u,      5u, SOAD_NO_SOCONMODECHGCBKINDENDIDXOFSOCON, SOAD_NO_SOCONMODECHGCBKINDSTARTIDXOFSOCON,        5u,                               4u,                                 3u, SOAD_NO_TCPTXQUEUEIDXOFSOCON, SOAD_NO_TPTXBUFFERCONFIGIDXOFSOCON, SOAD_NO_TXMGTIDXOFSOCON, SOAD_SOCON_IP_ANY_PORT_ANY },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/SoAdSocketConnection_Veh_Rx_001, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging] */
  { /*     6 */ SOAD_NO_IPFRAGMGTIDXOFSOCON, SOAD_NO_LOCALIPADDRASSIGNMENTCHGCBKINDENDIDXOFSOCON, SOAD_NO_LOCALIPADDRASSIGNMENTCHGCBKINDSTARTIDXOFSOCON, SOAD_NO_NPDUUDPTXIDXOFSOCON, SOAD_NO_PDUROUTEDESTBYSOCONINDENDIDXOFSOCON, SOAD_NO_PDUROUTEDESTBYSOCONINDSTARTIDXOFSOCON,             6u, SOAD_NO_REMADDRIPV6IDXOFSOCON, SOAD_NO_REMADDRRCVIDXOFSOCON, SOAD_NO_RXBUFSTRUCTMGTIDXOFSOCON, SOAD_NO_RXBUFSTRUCTSEGENDIDXOFSOCON, SOAD_NO_RXBUFSTRUCTSEGSTARTIDXOFSOCON, SOAD_NO_RXBUFFERCONFIGIDXOFSOCON,                      4u,          5u,      7u, SOAD_NO_SOCONMODECHGCBKINDENDIDXOFSOCON, SOAD_NO_SOCONMODECHGCBKINDSTARTIDXOFSOCON,        6u,                               5u,                                 4u, SOAD_NO_TCPTXQUEUEIDXOFSOCON, SOAD_NO_TPTXBUFFERCONFIGIDXOFSOCON, SOAD_NO_TXMGTIDXOFSOCON, SOAD_SOCON_IP_ANY_PORT_ANY },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL/SoAdSocketConnection_HIL_Rx, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL] */
  { /*     7 */ SOAD_NO_IPFRAGMGTIDXOFSOCON, SOAD_NO_LOCALIPADDRASSIGNMENTCHGCBKINDENDIDXOFSOCON, SOAD_NO_LOCALIPADDRASSIGNMENTCHGCBKINDSTARTIDXOFSOCON, SOAD_NO_NPDUUDPTXIDXOFSOCON,                                          8u,                                            7u,             7u, SOAD_NO_REMADDRIPV6IDXOFSOCON, SOAD_NO_REMADDRRCVIDXOFSOCON, SOAD_NO_RXBUFSTRUCTMGTIDXOFSOCON, SOAD_NO_RXBUFSTRUCTSEGENDIDXOFSOCON, SOAD_NO_RXBUFSTRUCTSEGSTARTIDXOFSOCON, SOAD_NO_RXBUFFERCONFIGIDXOFSOCON, SOAD_NO_RXMGTIDXOFSOCON,          5u,      6u, SOAD_NO_SOCONMODECHGCBKINDENDIDXOFSOCON, SOAD_NO_SOCONMODECHGCBKINDSTARTIDXOFSOCON,        6u, SOAD_NO_SOCKETROUTEENDIDXOFSOCON, SOAD_NO_SOCKETROUTESTARTIDXOFSOCON, SOAD_NO_TCPTXQUEUEIDXOFSOCON, SOAD_NO_TPTXBUFFERCONFIGIDXOFSOCON,                      4u, SOAD_SOCON_IP_SET_PORT_SET },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL/SoAdSocketConnection_HIL_Tx, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL] */
  { /*     8 */ SOAD_NO_IPFRAGMGTIDXOFSOCON,                                                  3u,                                                    2u, SOAD_NO_NPDUUDPTXIDXOFSOCON, SOAD_NO_PDUROUTEDESTBYSOCONINDENDIDXOFSOCON, SOAD_NO_PDUROUTEDESTBYSOCONINDSTARTIDXOFSOCON,             8u, SOAD_NO_REMADDRIPV6IDXOFSOCON,                           1u, SOAD_NO_RXBUFSTRUCTMGTIDXOFSOCON, SOAD_NO_RXBUFSTRUCTSEGENDIDXOFSOCON, SOAD_NO_RXBUFSTRUCTSEGSTARTIDXOFSOCON, SOAD_NO_RXBUFFERCONFIGIDXOFSOCON,                      5u,          6u,      1u,                                      5u,                                        4u,        3u,                               6u,                                 5u, SOAD_NO_TCPTXQUEUEIDXOFSOCON, SOAD_NO_TPTXBUFFERCONFIGIDXOFSOCON, SOAD_NO_TXMGTIDXOFSOCON, SOAD_SOCON_IP_ANY_PORT_ANY }   /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_a83a7734/ConnectionBundle4_81a0ef65, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_a83a7734] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_SoConGrp
**********************************************************************************************************************/
/** 
  \var    SoAd_SoConGrp
  \brief  the socket connection group configuration
  \details
  Element                          Description
  BestMatchWithPduHeaderEnabled    indicates if best match algorithm considers PDU Header ID
  BestMatchWithSockRouteEnabled    indicates if best match algorithm considers socket route availability
  MsgAcceptFilterEnabled           indicates if message acceptance filter is enabled
  PduHdrEnabled                    indicates if PDU header is enabled
  SockAutoSoConSetup               indicates if automatic socket connection setup is enabled
  SockAutoSoConSetupKeepOnline     indicates if it is enabled that socket connection stays online after transmission
  FramePriority                    the frame priority (VLAN)
  InstanceIdx                      the index of the 1:1 relation pointing to SoAd_Instance
  LocalAddrIdx                     the index of the 0:1 relation pointing to SoAd_LocalAddr
  SoConEndIdx                      the end index of the 1:n relation pointing to SoAd_SoCon
  SoConStartIdx                    the start index of the 1:n relation pointing to SoAd_SoCon
  SocketIdx                        the index of the 0:1 relation pointing to SoAd_Socket
  SocketTcpIdx                     the index of the 0:1 relation pointing to SoAd_SocketTcp
  SocketUdpIdx                     the index of the 0:1 relation pointing to SoAd_SocketUdp
  LocalPort                        the local port
  MeasurementDataSomeIpSdType      indicates if SOME/IP SD data is measured
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_SoConGrpType, SOAD_CONST) SoAd_SoConGrp[7] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    BestMatchWithPduHeaderEnabled  BestMatchWithSockRouteEnabled  MsgAcceptFilterEnabled  PduHdrEnabled  SockAutoSoConSetup  SockAutoSoConSetupKeepOnline  FramePriority                    InstanceIdx  LocalAddrIdx  SoConEndIdx  SoConStartIdx  SocketIdx  SocketTcpIdx                    SocketUdpIdx  LocalPort  MeasurementDataSomeIpSdType        Referable Keys */
  { /*     0 */                         FALSE,                          TRUE,                   TRUE,         FALSE,               TRUE,                         TRUE, SOAD_NO_FRAMEPRIORITYOFSOCONGRP,          0u,           0u,          1u,            0u,        0u, SOAD_NO_SOCKETTCPIDXOFSOCONGRP,           0u, 0xB515U  , SOAD_SOME_IP_MEAS_NONE      },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP, /ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP/SoAdSocketConnection_XCP] */
  { /*     1 */                          TRUE,                          TRUE,                  FALSE,          TRUE,              FALSE,                        FALSE, SOAD_NO_FRAMEPRIORITYOFSOCONGRP,          0u,           0u,          2u,            1u,        1u, SOAD_NO_SOCKETTCPIDXOFSOCONGRP,           1u, 0x1A77U  , SOAD_SOME_IP_MEAS_NONE      },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201, /ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201/ConnectionBundle2_14f4c9c7] */
  { /*     2 */                         FALSE,                         FALSE,                   TRUE,          TRUE,              FALSE,                        FALSE, SOAD_NO_FRAMEPRIORITYOFSOCONGRP,          0u,           0u,          3u,            2u,        2u, SOAD_NO_SOCKETTCPIDXOFSOCONGRP,           2u, 0xC586U  , SOAD_SOME_IP_MEAS_NONE      },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe, /ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815] */
  { /*     3 */                         FALSE,                          TRUE,                   TRUE,          TRUE,              FALSE,                        FALSE, SOAD_NO_FRAMEPRIORITYOFSOCONGRP,          0u,           0u,          4u,            3u,        4u, SOAD_NO_SOCKETTCPIDXOFSOCONGRP,           3u, 0x2577U  , SOAD_SOME_IP_MEAS_NONE      },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d, /ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d/ConnectionBundle_ADAS_53ce198e] */
  { /*     4 */                         FALSE,                          TRUE,                   TRUE,         FALSE,              FALSE,                        FALSE, SOAD_NO_FRAMEPRIORITYOFSOCONGRP,          0u,           0u,          6u,            4u,        5u, SOAD_NO_SOCKETTCPIDXOFSOCONGRP,           4u, 0xBA13U  , SOAD_SOME_IP_MEAS_NONE      },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging, /ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/ConnectionBundle_RDR_1_94fef815_001, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/SoAdSocketConnection_Veh_Rx_001] */
  { /*     5 */                         FALSE,                         FALSE,                   TRUE,         FALSE,               TRUE,                         TRUE, SOAD_NO_FRAMEPRIORITYOFSOCONGRP,          0u,           0u,          8u,            6u,        6u, SOAD_NO_SOCKETTCPIDXOFSOCONGRP,           5u, 0xB415U  , SOAD_SOME_IP_MEAS_NONE      },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL, /ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL/SoAdSocketConnection_HIL_Rx, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL/SoAdSocketConnection_HIL_Tx] */
  { /*     6 */                          TRUE,                          TRUE,                  FALSE,          TRUE,              FALSE,                        FALSE, SOAD_NO_FRAMEPRIORITYOFSOCONGRP,          0u,           1u,          9u,            8u,        3u, SOAD_NO_SOCKETTCPIDXOFSOCONGRP,           6u, 0x1A77U  , SOAD_SOME_IP_MEAS_NONE      }   /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_a83a7734, /ActiveEcuC/TcpIp/TcpIpConfig/NEP_ADAS_RdrNet_CtrlRxMulticast_91909614, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_a83a7734/ConnectionBundle4_81a0ef65] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_SoConMap
**********************************************************************************************************************/
/** 
  \var    SoAd_SoConMap
  \brief  the partition-unspecific handle ID mapping to partition-specific SoAdSocketId
  \details
  Element                               Description
  InvalidHnd                            FALSE, if the handle of SoAd_SoConMap is valid and can be used in the embedded code for further processing in the embedded code.
  PartitionSpecificSoConIdx             the index of the 1:1 relation pointing to one of SoAd_SoCon
  PartitionSpecificSoConPartitionIdx    the partition index of the 1:1 relation pointing to one of SoAd_SoCon
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_SoConMapType, SOAD_CONST) SoAd_SoConMap[9] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    InvalidHnd  PartitionSpecificSoConIdx  PartitionSpecificSoConPartitionIdx                                      Referable Keys */
  { /*     0 */      FALSE,                        1u,                                 0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201/ConnectionBundle2_14f4c9c7] */
  { /*     1 */      FALSE,                        8u,                                 0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_a83a7734/ConnectionBundle4_81a0ef65] */
  { /*     2 */      FALSE,                        3u,                                 0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d/ConnectionBundle_ADAS_53ce198e] */
  { /*     3 */      FALSE,                        2u,                                 0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815] */
  { /*     4 */      FALSE,                        4u,                                 0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/ConnectionBundle_RDR_1_94fef815_001] */
  { /*     5 */      FALSE,                        5u,                                 0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/SoAdSocketConnection_Veh_Rx_001] */
  { /*     6 */      FALSE,                        7u,                                 0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL/SoAdSocketConnection_HIL_Tx] */
  { /*     7 */      FALSE,                        6u,                                 0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL/SoAdSocketConnection_HIL_Rx] */
  { /*     8 */      FALSE,                        0u,                                 0u  /* SOAD_NO_OS_APPL_MAPPED */ }   /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP/SoAdSocketConnection_XCP] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_SoConModeChgCbk
**********************************************************************************************************************/
/** 
  \var    SoAd_SoConModeChgCbk
  \brief  the callback Up_SoConModeChg
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_SoConModeChgCbkType, SOAD_CONST) SoAd_SoConModeChgCbk[2] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     SoConModeChgCbk       Referable Keys */
  /*     0 */ Xcp_SoConModeChg ,  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP/SoAdSocketConnection_XCP] */
  /*     1 */ NULL_PTR     /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d/ConnectionBundle_ADAS_53ce198e, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201/ConnectionBundle2_14f4c9c7, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_a83a7734/ConnectionBundle4_81a0ef65] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_SoConModeChgCbkInd
**********************************************************************************************************************/
/** 
  \var    SoAd_SoConModeChgCbkInd
  \brief  the indexes of the 1:1 sorted relation pointing to SoAd_SoConModeChgCbk
*/ 
#define SOAD_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_SoConModeChgCbkIndType, SOAD_CONST) SoAd_SoConModeChgCbkInd[5] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     SoConModeChgCbkInd      Referable Keys */
  /*     0 */                  0u,  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP/SoAdSocketConnection_XCP] */
  /*     1 */                  1u,  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201/ConnectionBundle2_14f4c9c7] */
  /*     2 */                  1u,  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815] */
  /*     3 */                  1u,  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d/ConnectionBundle_ADAS_53ce198e] */
  /*     4 */                  1u   /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_a83a7734/ConnectionBundle4_81a0ef65] */
};
#define SOAD_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_Socket
**********************************************************************************************************************/
/** 
  \var    SoAd_Socket
  \brief  the socket configuration
  \details
  Element          Description
  SoConEndIdx      the end index of the 1:n relation pointing to SoAd_SoCon
  SoConStartIdx    the start index of the 1:n relation pointing to SoAd_SoCon
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_SocketType, SOAD_CONST) SoAd_Socket[7] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    SoConEndIdx  SoConStartIdx        Referable Keys */
  { /*     0 */          1u,            0u },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP, /ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027] */
  { /*     1 */          2u,            1u },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201, /ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027] */
  { /*     2 */          3u,            2u },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe, /ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027] */
  { /*     3 */          9u,            8u },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_a83a7734, /ActiveEcuC/TcpIp/TcpIpConfig/NEP_ADAS_RdrNet_CtrlRxMulticast_91909614] */
  { /*     4 */          4u,            3u },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d, /ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027] */
  { /*     5 */          6u,            4u },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging, /ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027] */
  { /*     6 */          8u,            6u }   /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL, /ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_SocketRoute
**********************************************************************************************************************/
/** 
  \var    SoAd_SocketRoute
  \brief  the socket route configuration
  \details
  Element                    Description
  RxPduHdrMethodId           the PDU header Method ID
  RxPduHdrServiceId          the PDU header Service ID
  MetaDataRxEnabled          indicates if SoConId is forwarded as meta data on reception
  SoConIdx                   the index of the 1:1 relation pointing to SoAd_SoCon
  SocketRouteDestEndIdx      the end index of the 1:n relation pointing to SoAd_SocketRouteDest
  SocketRouteDestStartIdx    the start index of the 1:n relation pointing to SoAd_SocketRouteDest
  UpperLayerApi              the upper layer API type (IF/TP)
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_SocketRouteType, SOAD_CONST) SoAd_SocketRoute[6] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    RxPduHdrMethodId  RxPduHdrServiceId  MetaDataRxEnabled  SoConIdx  SocketRouteDestEndIdx  SocketRouteDestStartIdx  UpperLayerApi         Referable Keys */
  { /*     0 */          0x0000u,           0x0000u,             FALSE,       0u,                    1u,                      0u, SOAD_UL_API_IF },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP/SoAdSocketConnection_XCP, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketRoute_XCP_BSW, /ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketRoute_XCP_BSW>>/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP/SoAdSocketConnection_XCP] */
  { /*     1 */          0x8100u,           0xFFFFu,             FALSE,       1u,                    2u,                      1u, SOAD_UL_API_IF },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201/ConnectionBundle2_14f4c9c7, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_44e6ad83_Rx, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_44e6ad83_Rx>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201/ConnectionBundle2_14f4c9c7] */
  { /*     2 */          0x8001u,           0x0100u,             FALSE,       3u,                    3u,                      2u, SOAD_UL_API_IF },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d/ConnectionBundle_ADAS_53ce198e, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_81eeb70b_Rx, /ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup1_27560e95, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_81eeb70b_Rx>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d/ConnectionBundle_ADAS_53ce198e] */
  { /*     3 */          0x0000u,           0x0000u,             FALSE,       5u,                    4u,                      3u, SOAD_UL_API_IF },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/SoAdSocketConnection_Veh_Rx_001, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketRoute_VEH_UDP_RX, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketRoute_VEH_UDP_RX>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/SoAdSocketConnection_Veh_Rx_001] */
  { /*     4 */          0x0000u,           0x0000u,             FALSE,       6u,                    5u,                      4u, SOAD_UL_API_IF },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL/SoAdSocketConnection_HIL_Rx, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketRoute_HIL, /ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketRoute_HIL>>/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL/SoAdSocketConnection_HIL_Rx] */
  { /*     5 */          0x8100u,           0xFFFFu,             FALSE,       8u,                    6u,                      5u, SOAD_UL_API_IF }   /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_a83a7734/ConnectionBundle4_81a0ef65, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_91e79f8a_Rx, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_91e79f8a_Rx>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_a83a7734/ConnectionBundle4_81a0ef65] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_SocketRouteDest
**********************************************************************************************************************/
/** 
  \var    SoAd_SocketRouteDest
  \brief  the socket route destination configuration
  \details
  Element                                      Description
  RxPduId                                      the RxPduId used to call the upper layer
  RouteGrpSoConBySocketRouteDestIndEndIdx      the end index of the 0:n relation pointing to SoAd_RouteGrpSoConBySocketRouteDestInd
  RouteGrpSoConBySocketRouteDestIndStartIdx    the start index of the 0:n relation pointing to SoAd_RouteGrpSoConBySocketRouteDestInd
  SocketRouteIdx                               the index of the 1:1 relation pointing to SoAd_SocketRoute
  UpperLayerIdx                                the index of the 1:1 relation pointing to SoAd_UpperLayer
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_SocketRouteDestType, SOAD_CONST) SoAd_SocketRouteDest[6] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    RxPduId                                                   RouteGrpSoConBySocketRouteDestIndEndIdx                           RouteGrpSoConBySocketRouteDestIndStartIdx                           SocketRouteIdx  UpperLayerIdx        Referable Keys */
  { /*     0 */ XcpConf_XcpRxPdu_XcpRxPdu                               ,                                                               1u,                                                                 0u,             0u,            2u },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketRoute_XCP_BSW>>/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP/SoAdSocketConnection_XCP, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketRoute_XCP_BSW/SoAdSocketRouteDest_XCP_RX_Eth>>/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP/SoAdSocketConnection_XCP] */
  { /*     1 */ SdConf_SdInstanceUnicastRxPdu_SdInstanceUnicastRxPdu    , SOAD_NO_ROUTEGRPSOCONBYSOCKETROUTEDESTINDENDIDXOFSOCKETROUTEDEST, SOAD_NO_ROUTEGRPSOCONBYSOCKETROUTEDESTINDSTARTIDXOFSOCKETROUTEDEST,             1u,            3u },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_44e6ad83_Rx>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201/ConnectionBundle2_14f4c9c7, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_44e6ad83_Rx/ConnectionBundle2_5528fe66>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201/ConnectionBundle2_14f4c9c7] */
  { /*     2 */ PduRConf_PduRSrcPdu_PduRSrcPdu_18053073                 ,                                                               2u,                                                                 1u,             2u,            0u },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_81eeb70b_Rx>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d/ConnectionBundle_ADAS_53ce198e, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_81eeb70b_Rx/ConnectionBundle_ADAS_f656ca1d>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d/ConnectionBundle_ADAS_53ce198e] */
  { /*     3 */ CddConf_CddSoAdUpperLayerRxPdu_RDR_VEH_UDP_STREAM_RX    , SOAD_NO_ROUTEGRPSOCONBYSOCKETROUTEDESTINDENDIDXOFSOCKETROUTEDEST, SOAD_NO_ROUTEGRPSOCONBYSOCKETROUTEDESTINDSTARTIDXOFSOCKETROUTEDEST,             3u,            1u },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketRoute_VEH_UDP_RX>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/SoAdSocketConnection_Veh_Rx_001, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketRoute_VEH_UDP_RX/SoAdSocketRouteDest_Veh_UDP_Rx>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/SoAdSocketConnection_Veh_Rx_001] */
  { /*     4 */ CddConf_CddSoAdUpperLayerRxPdu_RDR_HIL_Req_RX           ,                                                               3u,                                                                 2u,             4u,            1u },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketRoute_HIL>>/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL/SoAdSocketConnection_HIL_Rx, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketRoute_HIL/SoAdSocketRouteDest_HIL>>/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL/SoAdSocketConnection_HIL_Rx] */
  { /*     5 */ SdConf_SdInstanceMulticastRxPdu_SdInstanceMulticastRxPdu, SOAD_NO_ROUTEGRPSOCONBYSOCKETROUTEDESTINDENDIDXOFSOCKETROUTEDEST, SOAD_NO_ROUTEGRPSOCONBYSOCKETROUTEDESTINDSTARTIDXOFSOCKETROUTEDEST,             5u,            3u }   /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_91e79f8a_Rx>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_a83a7734/ConnectionBundle4_81a0ef65, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_91e79f8a_Rx/ConnectionBundle4_f5688455>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_a83a7734/ConnectionBundle4_81a0ef65] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_SocketRouteInd
**********************************************************************************************************************/
/** 
  \var    SoAd_SocketRouteInd
  \brief  the indexes of the 1:1 sorted relation pointing to SoAd_SocketRoute
*/ 
#define SOAD_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_SocketRouteIndType, SOAD_CONST) SoAd_SocketRouteInd[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     SocketRouteInd      Referable Keys */
  /*     0 */              0u,  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup] */
  /*     1 */              4u,  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup] */
  /*     2 */              2u   /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup1_27560e95] */
};
#define SOAD_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_SocketUdp
**********************************************************************************************************************/
/** 
  \var    SoAd_SocketUdp
  \brief  the UDP socket configuration
  \details
  Element                        Description
  AliveTimeoutMaxCnt             the time a connection remains online after the last reception
  ChecksumChangeEnabled          indicates if UDP checksum calculation setting shall be changed
  ChecksumEnabled                indicates if UDP checksum calculation shall be enabled
  ImmedIfTxConf                  indicates if immediate TxConfirmation is used
  UdpListenOnly                  indicates if the socket is used for reception only
  UdpStrictHdrLenCheckEnabled    indicates if UDP messages shall be dropped dependent on header length check
  ImmedIfTxConfListSize          the list size to handle UDP transmissions with immediate TxConfirmation
  NPduUdpTxBufferMin             the amount of data in bytes that SoAd is able to buffer
  NPduUdpTxQueueSize             the size of the management queue
  RetryQueueLimit                the limitation of maximum used UDP transmission retry queue elements for this socket
  UdpTriggerTimeout              the time to wait for a PDU with TriggerMode = TRIGGER_ALWAYS before nPduUdpTxBuffer is transmitted
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_SocketUdpType, SOAD_CONST) SoAd_SocketUdp[7] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    AliveTimeoutMaxCnt  ChecksumChangeEnabled  ChecksumEnabled  ImmedIfTxConf  UdpListenOnly  UdpStrictHdrLenCheckEnabled  ImmedIfTxConfListSize  NPduUdpTxBufferMin  NPduUdpTxQueueSize  RetryQueueLimit  UdpTriggerTimeout        Referable Keys */
  { /*     0 */              1000u,                 FALSE,           FALSE,         FALSE,         FALSE,                       FALSE,                    0u,                 0u,                 0u,              1u,                0u },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP] */
  { /*     1 */                 0u,                 FALSE,            TRUE,         FALSE,         FALSE,                       FALSE,                    0u,                 0u,                 0u,              1u,                0u },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201] */
  { /*     2 */               200u,                 FALSE,            TRUE,         FALSE,         FALSE,                       FALSE,                    0u,                 0u,                 0u,              1u,                0u },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe] */
  { /*     3 */               200u,                 FALSE,            TRUE,         FALSE,         FALSE,                       FALSE,                    0u,                 0u,                 0u,              1u,                0u },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d] */
  { /*     4 */                 0u,                 FALSE,            TRUE,         FALSE,         FALSE,                       FALSE,                    0u,                 0u,                 0u,              0u,                0u },  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging] */
  { /*     5 */              1000u,                 FALSE,           FALSE,         FALSE,         FALSE,                       FALSE,                    0u,                 0u,                 0u,              1u,                0u },  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL] */
  { /*     6 */                 0u,                 FALSE,            TRUE,         FALSE,         FALSE,                       FALSE,                    0u,                 0u,                 0u,              1u,                0u }   /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_a83a7734] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_TcpIpCtrl
**********************************************************************************************************************/
/** 
  \var    SoAd_TcpIpCtrl
  \brief  the TcpIp controller/interface
  \details
  Element                            Description
  RetryEnabled                       indicates if transmission retry is available on controller/interface
  LocalAddrByTcpIpCtrlIndEndIdx      the end index of the 0:n relation pointing to SoAd_LocalAddrByTcpIpCtrlInd
  LocalAddrByTcpIpCtrlIndStartIdx    the start index of the 0:n relation pointing to SoAd_LocalAddrByTcpIpCtrlInd
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_TcpIpCtrlType, SOAD_CONST) SoAd_TcpIpCtrl[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    RetryEnabled  LocalAddrByTcpIpCtrlIndEndIdx  LocalAddrByTcpIpCtrlIndStartIdx        Referable Keys */
  { /*     0 */         TRUE,                            1u,                              0u }   /* [/ActiveEcuC/TcpIp/TcpIpConfig/cnctr_RDR_RdrNet_1bd20df5] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_TcpKeepAliveGloballyEnabled
**********************************************************************************************************************/
/** 
  \var    SoAd_TcpKeepAliveGloballyEnabled
  \brief  indicates if TCP keep alive is enabled at all
*/ 
#define SOAD_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_TcpKeepAliveGloballyEnabledType, SOAD_CONST) SoAd_TcpKeepAliveGloballyEnabled[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     TcpKeepAliveGloballyEnabled  */
  /*     0 */                        FALSE
};
#define SOAD_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_TimeoutListIdent
**********************************************************************************************************************/
/** 
  \var    SoAd_TimeoutListIdent
  \brief  the timeout list identification to get the index of a specific timeout list
  \details
  Element                               Description
  TimeoutListNPduUdpTxConfigIdx         the index of the 0:1 relation pointing to SoAd_TimeoutListNPduUdpTxConfig
  TimeoutListTcpAutoConnectConfigIdx    the index of the 0:1 relation pointing to SoAd_TimeoutListTcpAutoConnectConfig
  TimeoutListUdpAliveConfigIdx          the index of the 0:1 relation pointing to SoAd_TimeoutListUdpAliveConfig
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_TimeoutListIdentType, SOAD_CONST) SoAd_TimeoutListIdent[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    TimeoutListNPduUdpTxConfigIdx                            TimeoutListTcpAutoConnectConfigIdx                            TimeoutListUdpAliveConfigIdx        Referable Keys */
  { /*     0 */ SOAD_NO_TIMEOUTLISTNPDUUDPTXCONFIGIDXOFTIMEOUTLISTIDENT, SOAD_NO_TIMEOUTLISTTCPAUTOCONNECTCONFIGIDXOFTIMEOUTLISTIDENT,                           0u }   /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdInstance] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_TimeoutListUdpAliveConfig
**********************************************************************************************************************/
/** 
  \var    SoAd_TimeoutListUdpAliveConfig
  \brief  the configuration of the specific timeout list
  \details
  Element                        Description
  TimeoutListMgmtIdx             the index of the 1:1 relation pointing to SoAd_TimeoutListMgmt
  TimeoutListUdpAliveEndIdx      the end index of the 1:n relation pointing to SoAd_TimeoutListUdpAlive
  TimeoutListUdpAliveStartIdx    the start index of the 1:n relation pointing to SoAd_TimeoutListUdpAlive
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_TimeoutListUdpAliveConfigType, SOAD_CONST) SoAd_TimeoutListUdpAliveConfig[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    TimeoutListMgmtIdx  TimeoutListUdpAliveEndIdx  TimeoutListUdpAliveStartIdx        Referable Keys */
  { /*     0 */                 0u,                        3u,                          0u }   /* [SoAdTimeoutListUdpAlive_SoAdInstance] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_TxPduIdMap
**********************************************************************************************************************/
/** 
  \var    SoAd_TxPduIdMap
  \brief  the partition-unspecific handle ID mapping to partition-specific TxPduId
  \details
  Element                                  Description
  InvalidHnd                               FALSE, if the handle of SoAd_TxPduIdMap is valid and can be used in the embedded code for further processing in the embedded code.
  PartitionSpecificPduRouteIdx             the index of the 1:1 relation pointing to one of SoAd_PduRoute
  PartitionSpecificPduRoutePartitionIdx    the partition index of the 1:1 relation pointing to one of SoAd_PduRoute
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_TxPduIdMapType, SOAD_CONST) SoAd_TxPduIdMap[8] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    InvalidHnd  PartitionSpecificPduRouteIdx  PartitionSpecificPduRoutePartitionIdx                                      Referable Keys */
  { /*     0 */      FALSE,                           0u,                                    0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/SoAd/SoAdConfig/GenerelPurposePDU3_a3a5c5ac_Tx] */
  { /*     1 */      FALSE,                           1u,                                    0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/SoAd/SoAdConfig/RDR_ETH_XCP_TX] */
  { /*     2 */      FALSE,                           2u,                                    0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/SoAd/SoAdConfig/RDR_LOGGING_TX] */
  { /*     3 */      FALSE,                           3u,                                    0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/SoAd/SoAdConfig/RDR_LOGGING_TX_FAST] */
  { /*     4 */      FALSE,                           4u,                                    0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/SoAd/SoAdConfig/RDR_HIL_TX] */
  { /*     5 */      FALSE,                           5u,                                    0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/SoAd/SoAdConfig/signalPdu_RDR_1_Detections_Transport_d322aa23_Tx] */
  { /*     6 */      FALSE,                           6u,                                    0u  /* SOAD_NO_OS_APPL_MAPPED */ },  /* [/ActiveEcuC/SoAd/SoAdConfig/signalPdu_RDR_1_SW_Info_14232baa_Tx] */
  { /*     7 */      FALSE,                           7u,                                    0u  /* SOAD_NO_OS_APPL_MAPPED */ }   /* [/ActiveEcuC/SoAd/SoAdConfig/signalPdu_RDR_1_Status_67c6fd21_Tx] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_UpperLayer
**********************************************************************************************************************/
/** 
  \var    SoAd_UpperLayer
  \brief  the upper layer configuration
  \details
  Element                       Description
  IfRxIndicationCbk             the callback Up_[SoAd][If]RxIndication
  IfTriggerTransmitCbk          the callback Up_[SoAd][If]TriggerTransmit
  IfTxConfirmationCbk           the callback Up_[SoAd][If]TxConfirmation
  TpCopyRxDataCbk               the callback Up_[SoAd][Tp]CopyRxData
  TpCopyRxDataConstCbk          the callback Up_[SoAd][Tp]CopyRxData with const data pointer
  TpCopyTxDataCbk               the callback Up_[SoAd][Tp]CopyTxData
  TpCopyTxDataConstCbk          the callback Up_[SoAd][Tp]CopyTxData with const data pointer
  TpRxIndicationCbk             the callback Up_[SoAd][Tp]RxIndication
  TpStartOfReceptionCbk         the callback Up_[SoAd][Tp]StartOfReception
  TpStartOfReceptionConstCbk    the callback Up_[SoAd][Tp]StartOfReception with const data pointer
  TpTxConfirmationCbk           the callback Up_[SoAd][Tp]TxConfirmation
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_UpperLayerType, SOAD_CONST) SoAd_UpperLayer[4] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    IfRxIndicationCbk        IfTriggerTransmitCbk        IfTxConfirmationCbk        TpCopyRxDataCbk  TpCopyRxDataConstCbk  TpCopyTxDataCbk  TpCopyTxDataConstCbk  TpRxIndicationCbk  TpStartOfReceptionCbk  TpStartOfReceptionConstCbk  TpTxConfirmationCbk        Referable Keys */
  { /*     0 */ PduR_SoAdIfRxIndication, PduR_SoAdIfTriggerTransmit, PduR_SoAdIfTxConfirmation, NULL_PTR       , NULL_PTR            , NULL_PTR       , NULL_PTR            , NULL_PTR         , NULL_PTR             , NULL_PTR                  , NULL_PTR            },  /* [/ActiveEcuC/SoAd/PduR] */
  { /*     1 */ Cdd_SoAdIfRxIndication , NULL_PTR                  , NULL_PTR                 , NULL_PTR       , NULL_PTR            , NULL_PTR       , NULL_PTR            , NULL_PTR         , NULL_PTR             , NULL_PTR                  , NULL_PTR            },  /* [/ActiveEcuC/SoAd/Cdd] */
  { /*     2 */ Xcp_SoAdRxIndication   , NULL_PTR                  , NULL_PTR                 , NULL_PTR       , NULL_PTR            , NULL_PTR       , NULL_PTR            , NULL_PTR         , NULL_PTR             , NULL_PTR                  , NULL_PTR            },  /* [/ActiveEcuC/SoAd/Xcp] */
  { /*     3 */ NULL_PTR        , NULL_PTR                  , NULL_PTR                 , NULL_PTR       , NULL_PTR            , NULL_PTR       , NULL_PTR            , NULL_PTR         , NULL_PTR             , NULL_PTR                  , NULL_PTR            }   /* [/ActiveEcuC/SoAd/Sd] */
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_BestMatchSoConIdxList
**********************************************************************************************************************/
/** 
  \var    SoAd_BestMatchSoConIdxList
  \brief  the global list to store all matching socket connections if best match alogorithm is used
  \details
  Element     Description
  SoConIdx    the index of the 1:1 relation pointing to SoAd_SoCon
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SoAd_BestMatchSoConIdxListType, SOAD_VAR_NO_INIT) SoAd_BestMatchSoConIdxList[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdInstance] */
  /*     1 */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdInstance] */

#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_EventQueueFlag
**********************************************************************************************************************/
/** 
  \var    SoAd_EventQueueFlag
  \brief  stores a flag for each handle index and event queue type to indicate if handle is in event queue (i.e. event active for handle)
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SoAd_EventQueueFlagType, SOAD_VAR_NO_INIT) SoAd_EventQueueFlag[9];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdInstance] */
  /*   ... */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdInstance] */
  /*     8 */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdInstance] */

#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_EventQueueIfUdpPduRoute
**********************************************************************************************************************/
/** 
  \var    SoAd_EventQueueIfUdpPduRoute
  \brief  indicates if a IF confirmation is pending on a UDP socket connection
  \details
  Element        Description
  PduRouteIdx    the index of the 0:1 relation pointing to SoAd_PduRoute
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SoAd_EventQueueIfUdpPduRouteType, SOAD_VAR_NO_INIT) SoAd_EventQueueIfUdpPduRoute[8];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [SoAdEventQueueIfUdpPduRoute_SoAdInstance] */
  /*   ... */  /* [SoAdEventQueueIfUdpPduRoute_SoAdInstance] */
  /*     7 */  /* [SoAdEventQueueIfUdpPduRoute_SoAdInstance] */

#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_EventQueueMgmt
**********************************************************************************************************************/
/** 
  \var    SoAd_EventQueueMgmt
  \brief  the management struct of all event queues
  \details
  Element    Description
  Idx        the index of oldest pending event.
  Lvl        the level of pending events
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SoAd_EventQueueMgmtType, SOAD_VAR_NO_INIT) SoAd_EventQueueMgmt[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [SoAdEventQueueStateSoCon_SoAdInstance] */
  /*     1 */  /* [SoAdEventQueueIfUdpPduRoute_SoAdInstance] */

#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_EventQueueStateSoCon
**********************************************************************************************************************/
/** 
  \var    SoAd_EventQueueStateSoCon
  \brief  indicates if an event is active for socket connection state
  \details
  Element     Description
  SoConIdx    the index of the 0:1 relation pointing to SoAd_SoCon
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SoAd_EventQueueStateSoConType, SOAD_VAR_NO_INIT) SoAd_EventQueueStateSoCon[9];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [SoAdEventQueueStateSoCon_SoAdInstance] */
  /*   ... */  /* [SoAdEventQueueStateSoCon_SoAdInstance] */
  /*     8 */  /* [SoAdEventQueueStateSoCon_SoAdInstance] */

#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_InstanceDyn
**********************************************************************************************************************/
/** 
  \var    SoAd_InstanceDyn
  \brief  contains the instance-specific counter variables (main function cycles, open sockets and measurement data)
  \details
  Element              Description
  Counter              counts the main function cycles (with wrap around) to handle timeouts for the timeout lists
  BestMatchListSize    the number of valid socket connections saved in the best match list
  OpenSocks            the number of open sockets
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SoAd_InstanceDynType, SOAD_VAR_NO_INIT) SoAd_InstanceDyn[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_a83a7734, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL, /ActiveEcuC/SoAd/SoAdConfig/SoAdInstance] */

#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_LocalAddrDyn
**********************************************************************************************************************/
/** 
  \var    SoAd_LocalAddrDyn
  \details
  Element        Description
  IpAddrState    the local IP address assignment state
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SoAd_LocalAddrDynType, SOAD_VAR_NO_INIT) SoAd_LocalAddrDyn[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027, /ActiveEcuC/TcpIp/TcpIpConfig/cnctr_RDR_RdrNet_1bd20df5] */
  /*     1 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/NEP_ADAS_RdrNet_CtrlRxMulticast_91909614] */

#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_PartitionDyn
**********************************************************************************************************************/
/** 
  \var    SoAd_PartitionDyn
  \brief  contains the partition-specific init status
  \details
  Element        Description
  Initialized    initialized state of the partition
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SoAd_PartitionDynType, SOAD_VAR_NO_INIT) SoAd_PartitionDyn[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_PduRouteDyn
**********************************************************************************************************************/
/** 
  \var    SoAd_PduRouteDyn
  \brief  the SoAdPduRoute management structs
  \details
  Element              Description
  PendingTxConfMain    indicates if transmission confirmation in main function context is pending
  PendingTxConfNum     the number of pending transmission confirmation
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SoAd_PduRouteDynType, SOAD_VAR_NO_INIT) SoAd_PduRouteDyn[8];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SoAd/SoAdConfig/GenerelPurposePDU3_a3a5c5ac_Tx] */
  /*     1 */  /* [/ActiveEcuC/SoAd/SoAdConfig/RDR_ETH_XCP_TX] */
  /*     2 */  /* [/ActiveEcuC/SoAd/SoAdConfig/RDR_LOGGING_TX] */
  /*     3 */  /* [/ActiveEcuC/SoAd/SoAdConfig/RDR_LOGGING_TX_FAST] */
  /*     4 */  /* [/ActiveEcuC/SoAd/SoAdConfig/RDR_HIL_TX] */
  /*     5 */  /* [/ActiveEcuC/SoAd/SoAdConfig/signalPdu_RDR_1_Detections_Transport_d322aa23_Tx] */
  /*     6 */  /* [/ActiveEcuC/SoAd/SoAdConfig/signalPdu_RDR_1_SW_Info_14232baa_Tx] */
  /*     7 */  /* [/ActiveEcuC/SoAd/SoAdConfig/signalPdu_RDR_1_Status_67c6fd21_Tx] */

#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_RemAddrRcv
**********************************************************************************************************************/
/** 
  \var    SoAd_RemAddrRcv
  \brief  stores remote address on reception
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SoAd_SockAddrInetXType, SOAD_VAR_NO_INIT) SoAd_RemAddrRcv[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201/ConnectionBundle2_14f4c9c7] */
  /*     1 */  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_a83a7734/ConnectionBundle4_81a0ef65] */

#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_RouteGrpSoConDyn
**********************************************************************************************************************/
/** 
  \var    SoAd_RouteGrpSoConDyn
  \brief  the routing groups on the socket connections management struct
  \details
  Element    Description
  Enabled    the routing group state on the socket connection
  Flags      the current state of routing group transmission for socket connection: flag 0 = Tx active, flag 1 = Tx processed
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SoAd_RouteGrpSoConDynType, SOAD_VAR_NO_INIT) SoAd_RouteGrpSoConDyn[8];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketRoute_XCP_BSW/SoAdSocketRouteDest_XCP_RX_Eth>>/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP/SoAdSocketConnection_XCP, /ActiveEcuC/SoAd/SoAdConfig/RDR_ETH_XCP_TX/SoAdPduRouteDest>>/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP/SoAdSocketConnection_XCP] */
  /*     1 */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup, /ActiveEcuC/SoAd/SoAdConfig/RDR_LOGGING_TX/SoAdPduRouteDest>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/ConnectionBundle_RDR_1_94fef815_001, /ActiveEcuC/SoAd/SoAdConfig/RDR_LOGGING_TX_FAST/SoAdPduRouteDest>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/ConnectionBundle_RDR_1_94fef815_001] */
  /*     2 */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketRoute_HIL/SoAdSocketRouteDest_HIL>>/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL/SoAdSocketConnection_HIL_Rx] */
  /*     3 */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup, /ActiveEcuC/SoAd/SoAdConfig/RDR_HIL_TX/SoAdPduRouteDest>>/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL/SoAdSocketConnection_HIL_Tx] */
  /*     4 */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup1_27560e95, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_81eeb70b_Rx/ConnectionBundle_ADAS_f656ca1d>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d/ConnectionBundle_ADAS_53ce198e] */
  /*     5 */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup2_be5f5f2f, /ActiveEcuC/SoAd/SoAdConfig/signalPdu_RDR_1_Detections_Transport_d322aa23_Tx/ConnectionBundle_RDR_1_94fef815>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815] */
  /*     6 */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup3_c9586fb9, /ActiveEcuC/SoAd/SoAdConfig/signalPdu_RDR_1_SW_Info_14232baa_Tx/ConnectionBundle_RDR_1_94fef815>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815] */
  /*     7 */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdRoutingGroup4_573cfa1a, /ActiveEcuC/SoAd/SoAdConfig/signalPdu_RDR_1_Status_67c6fd21_Tx/ConnectionBundle_RDR_1_94fef815>>/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815] */

#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_RxMgt
**********************************************************************************************************************/
/** 
  \var    SoAd_RxMgt
  \brief  the Rx management structs
  \details
  Element               Description
  RxBytesPending        the length of pending data to be received
  CancelRequested       indicates if reception cancellation is requested
  SocketRouteDestIdx    the index of the 1:1 relation pointing to SoAd_SocketRouteDest
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SoAd_RxMgtType, SOAD_VAR_NO_INIT) SoAd_RxMgt[6];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP/SoAdSocketConnection_XCP] */
  /*     1 */  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201/ConnectionBundle2_14f4c9c7] */
  /*     2 */  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d/ConnectionBundle_ADAS_53ce198e] */
  /*     3 */  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/SoAdSocketConnection_Veh_Rx_001] */
  /*     4 */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL/SoAdSocketConnection_HIL_Rx] */
  /*     5 */  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_a83a7734/ConnectionBundle4_81a0ef65] */

#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_SoConDyn
**********************************************************************************************************************/
/** 
  \var    SoAd_SoConDyn
  \brief  the socket connection managment structs
  \details
  Element             Description
  OpenCloseCounter    the open and close sequence counter
  Abort               indicates if abort is requested
  RxActive            indicates if reception is active on any SocketRoute of the socket connection
  TimeoutOccurred     indicates if timeout occurred while trying to open the socket connection
  TxActive            indicates if transmission is active on any PduRoute of the socket connection
  CloseMode           the mode of socket connection
  Mode                the mode of socket connection
  RemAddrDyn          the remote address for each socket connection
  RemAddrRelease      indicates if release of remote address is requested
  RemAddrStateDyn     the remote address state on socket connection
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SoAd_SoConDynType, SOAD_VAR_NO_INIT) SoAd_SoConDyn[9];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP/SoAdSocketConnection_XCP, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP] */
  /*     1 */  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201/ConnectionBundle2_14f4c9c7, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201] */
  /*     2 */  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe] */
  /*     3 */  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d/ConnectionBundle_ADAS_53ce198e, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d] */
  /*     4 */  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/ConnectionBundle_RDR_1_94fef815_001, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging] */
  /*     5 */  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/SoAdSocketConnection_Veh_Rx_001, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging] */
  /*     6 */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL/SoAdSocketConnection_HIL_Rx, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL] */
  /*     7 */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL/SoAdSocketConnection_HIL_Tx, /ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL] */
  /*     8 */  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_a83a7734/ConnectionBundle4_81a0ef65, /ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_a83a7734] */

#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_SocketDyn
**********************************************************************************************************************/
/** 
  \var    SoAd_SocketDyn
  \brief  the socket management structs
  \details
  Element             Description
  SkipBytes           the number of bytes to be skipped
  SoConTxActiveIdx    the index of the 0:1 relation pointing to SoAd_SoCon
  LocalPort           the local port
  SocketId            the socket identifier
  State               the socket state
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SoAd_SocketDynType, SOAD_VAR_NO_INIT) SoAd_SocketDyn[7];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP, /ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027] */
  /*     1 */  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201, /ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027] */
  /*     2 */  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe, /ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027] */
  /*     3 */  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle4_a83a7734, /ActiveEcuC/TcpIp/TcpIpConfig/NEP_ADAS_RdrNet_CtrlRxMulticast_91909614] */
  /*     4 */  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_ADAS_6b786f6d, /ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027] */
  /*     5 */  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging, /ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027] */
  /*     6 */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL, /ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027] */

#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_TimeoutListMgmt
**********************************************************************************************************************/
/** 
  \var    SoAd_TimeoutListMgmt
  \brief  the management struct of all timeout lists
  \details
  Element    Description
  Lvl        the level of pending timeouts
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SoAd_TimeoutListMgmtType, SOAD_VAR_NO_INIT) SoAd_TimeoutListMgmt[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [SoAdTimeoutListUdpAlive_SoAdInstance] */

#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_TimeoutListUdpAlive
**********************************************************************************************************************/
/** 
  \var    SoAd_TimeoutListUdpAlive
  \brief  the timeout list for UDP Alive supervision timeout
  \details
  Element     Description
  Timeout     the timeout value
  SoConIdx    the index of the 0:1 relation pointing to SoAd_SoCon
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SoAd_TimeoutListUdpAliveType, SOAD_VAR_NO_INIT) SoAd_TimeoutListUdpAlive[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [SoAdTimeoutListUdpAlive_SoAdInstance] */
  /*   ... */  /* [SoAdTimeoutListUdpAlive_SoAdInstance] */
  /*     2 */  /* [SoAdTimeoutListUdpAlive_SoAdInstance] */

#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_TimeoutListUdpAliveMap
**********************************************************************************************************************/
/** 
  \var    SoAd_TimeoutListUdpAliveMap
  \brief  maps all socket connections to the timeout list index for UDP Alive supervision timeout if timeout is running
  \details
  Element                   Description
  TimeoutListUdpAliveIdx    the index of the 0:1 relation pointing to SoAd_TimeoutListUdpAlive
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SoAd_TimeoutListUdpAliveMapType, SOAD_VAR_NO_INIT) SoAd_TimeoutListUdpAliveMap[9];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SoAd] */
  /*   ... */  /* [/ActiveEcuC/SoAd] */
  /*     8 */  /* [/ActiveEcuC/SoAd] */

#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_TxMgt
**********************************************************************************************************************/
/** 
  \var    SoAd_TxMgt
  \brief  the Tx management structs
  \details
  Element            Description
  TxBytesLen         the length of data to be transmitted
  TxBytesPending     the length of pending data to be transmitted
  CancelRequested    indicates if transmission cancellation is requested
  PduRouteDestIdx    the index of the 1:1 relation pointing to SoAd_PduRouteDest
  TxBufPtr           the pointer to transmission data buffer
*/ 
#define SOAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(SoAd_TxMgtType, SOAD_VAR_NO_INIT) SoAd_TxMgt[5];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_XCP/SoAdSocketConnection_XCP] */
  /*     1 */  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle2_4159d201/ConnectionBundle2_14f4c9c7] */
  /*     2 */  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_1_1c1a30fe/ConnectionBundle_RDR_1_94fef815] */
  /*     3 */  /* [/ActiveEcuC/SoAd/SoAdConfig/ConnectionBundle_RDR_Logging/ConnectionBundle_RDR_1_94fef815_001] */
  /*     4 */  /* [/ActiveEcuC/SoAd/SoAdConfig/SoAdSocketConnectionGroup_HIL/SoAdSocketConnection_HIL_Tx] */

#define SOAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_PCConfig
**********************************************************************************************************************/
/** 
  \var    SoAd_PCConfig
  \details
  Element                       Description
  PCPartitionConfig             the pointer to SoAd_PCPartitionConfig
  PartitionIdentifiers          the pointer to SoAd_PartitionIdentifiers
  SizeOfPartitionIdentifiers    the number of accomplishable value elements in SoAd_PartitionIdentifiers
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_PCConfigsType, SOAD_CONST) SoAd_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config] */
      SoAd_PCPartitionConfig      /**< the pointer to SoAd_PCPartitionConfig */
    , SoAd_PartitionIdentifiers   /**< the pointer to SoAd_PartitionIdentifiers */
    , 1u                          /**< the number of elements in SoAd_PartitionIdentifiers */
  }
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  SoAd_PCPartitionConfig
**********************************************************************************************************************/
/** 
  \var    SoAd_PCPartitionConfig
  \details
  Element                                    Description
  BestMatchSoConIdxList                      the pointer to SoAd_BestMatchSoConIdxList
  DhcpEventCbk                               the pointer to SoAd_DhcpEventCbk
  EventQueueFlag                             the pointer to SoAd_EventQueueFlag
  EventQueueIdent                            the pointer to SoAd_EventQueueIdent
  EventQueueIfTxRouteGrp                     the pointer to SoAd_EventQueueIfTxRouteGrp
  EventQueueIfTxRouteGrpConfig               the pointer to SoAd_EventQueueIfTxRouteGrpConfig
  EventQueueIfUdpPduRoute                    the pointer to SoAd_EventQueueIfUdpPduRoute
  EventQueueIfUdpPduRouteConfig              the pointer to SoAd_EventQueueIfUdpPduRouteConfig
  EventQueueMgmt                             the pointer to SoAd_EventQueueMgmt
  EventQueueStateSoCon                       the pointer to SoAd_EventQueueStateSoCon
  EventQueueStateSoConConfig                 the pointer to SoAd_EventQueueStateSoConConfig
  EventQueueTpRxSoCon                        the pointer to SoAd_EventQueueTpRxSoCon
  EventQueueTpRxSoConConfig                  the pointer to SoAd_EventQueueTpRxSoConConfig
  EventQueueTpTxSoCon                        the pointer to SoAd_EventQueueTpTxSoCon
  EventQueueTpTxSoConConfig                  the pointer to SoAd_EventQueueTpTxSoConConfig
  IfRxBuffer                                 the pointer to SoAd_IfRxBuffer
  Instance                                   the pointer to SoAd_Instance
  InstanceDyn                                the pointer to SoAd_InstanceDyn
  InstanceMap                                the pointer to SoAd_InstanceMap
  IpFragBuf                                  the pointer to SoAd_IpFragBuf
  IpFragBufConfig                            the pointer to SoAd_IpFragBufConfig
  IpFragBufConfigDyn                         the pointer to SoAd_IpFragBufConfigDyn
  IpFragMgt                                  the pointer to SoAd_IpFragMgt
  LocalAddr                                  the pointer to SoAd_LocalAddr
  LocalAddrByTcpIpCtrlInd                    the pointer to SoAd_LocalAddrByTcpIpCtrlInd
  LocalAddrDyn                               the pointer to SoAd_LocalAddrDyn
  LocalAddrIdMap                             the pointer to SoAd_LocalAddrIdMap
  LocalIpAddrAssignmentChgCbk                the pointer to SoAd_LocalIpAddrAssignmentChgCbk
  LocalIpAddrAssignmentChgCbkInd             the pointer to SoAd_LocalIpAddrAssignmentChgCbkInd
  MetaDataRxBuffer                           the pointer to SoAd_MetaDataRxBuffer
  NPduUdpTx                                  the pointer to SoAd_NPduUdpTx
  NPduUdpTxBuffer                            the pointer to SoAd_NPduUdpTxBuffer
  NPduUdpTxDyn                               the pointer to SoAd_NPduUdpTxDyn
  NPduUdpTxQueue                             the pointer to SoAd_NPduUdpTxQueue
  PartitionDyn                               the pointer to SoAd_PartitionDyn
  PduRoute                                   the pointer to SoAd_PduRoute
  PduRouteDest                               the pointer to SoAd_PduRouteDest
  PduRouteDestBySoConInd                     the pointer to SoAd_PduRouteDestBySoConInd
  PduRouteDestInd                            the pointer to SoAd_PduRouteDestInd
  PduRouteDyn                                the pointer to SoAd_PduRouteDyn
  RemAddrIpV4                                the pointer to SoAd_RemAddrIpV4
  RemAddrIpV6                                the pointer to SoAd_RemAddrIpV6
  RemAddrRcv                                 the pointer to SoAd_RemAddrRcv
  RouteGrp                                   the pointer to SoAd_RouteGrp
  RouteGrpIdMap                              the pointer to SoAd_RouteGrpIdMap
  RouteGrpSoCon                              the pointer to SoAd_RouteGrpSoCon
  RouteGrpSoConByPduRouteDestInd             the pointer to SoAd_RouteGrpSoConByPduRouteDestInd
  RouteGrpSoConBySocketRouteDestInd          the pointer to SoAd_RouteGrpSoConBySocketRouteDestInd
  RouteGrpSoConDyn                           the pointer to SoAd_RouteGrpSoConDyn
  RxBufStructMgt                             the pointer to SoAd_RxBufStructMgt
  RxBufStructSeg                             the pointer to SoAd_RxBufStructSeg
  RxBufferConfig                             the pointer to SoAd_RxBufferConfig
  RxBufferConfigDyn                          the pointer to SoAd_RxBufferConfigDyn
  RxMgt                                      the pointer to SoAd_RxMgt
  RxPduIdIdMap                               the pointer to SoAd_RxPduIdIdMap
  ShutdownFinishedCbk                        the pointer to SoAd_ShutdownFinishedCbk
  SoCon                                      the pointer to SoAd_SoCon
  SoConDyn                                   the pointer to SoAd_SoConDyn
  SoConGrp                                   the pointer to SoAd_SoConGrp
  SoConMap                                   the pointer to SoAd_SoConMap
  SoConModeChgCbk                            the pointer to SoAd_SoConModeChgCbk
  SoConModeChgCbkInd                         the pointer to SoAd_SoConModeChgCbkInd
  Socket                                     the pointer to SoAd_Socket
  SocketDyn                                  the pointer to SoAd_SocketDyn
  SocketRoute                                the pointer to SoAd_SocketRoute
  SocketRouteDest                            the pointer to SoAd_SocketRouteDest
  SocketRouteInd                             the pointer to SoAd_SocketRouteInd
  SocketTcp                                  the pointer to SoAd_SocketTcp
  SocketUdp                                  the pointer to SoAd_SocketUdp
  TcpIpCtrl                                  the pointer to SoAd_TcpIpCtrl
  TcpKeepAliveGloballyEnabled                the pointer to SoAd_TcpKeepAliveGloballyEnabled
  TcpTxQueue                                 the pointer to SoAd_TcpTxQueue
  TcpTxQueueData                             the pointer to SoAd_TcpTxQueueData
  TcpTxQueueMgt                              the pointer to SoAd_TcpTxQueueMgt
  TimeoutListIdent                           the pointer to SoAd_TimeoutListIdent
  TimeoutListMgmt                            the pointer to SoAd_TimeoutListMgmt
  TimeoutListNPduUdpTx                       the pointer to SoAd_TimeoutListNPduUdpTx
  TimeoutListNPduUdpTxConfig                 the pointer to SoAd_TimeoutListNPduUdpTxConfig
  TimeoutListNPduUdpTxMap                    the pointer to SoAd_TimeoutListNPduUdpTxMap
  TimeoutListTcpAutoConnectConfig            the pointer to SoAd_TimeoutListTcpAutoConnectConfig
  TimeoutListUdpAlive                        the pointer to SoAd_TimeoutListUdpAlive
  TimeoutListUdpAliveConfig                  the pointer to SoAd_TimeoutListUdpAliveConfig
  TimeoutListUdpAliveMap                     the pointer to SoAd_TimeoutListUdpAliveMap
  TpRxBuffer                                 the pointer to SoAd_TpRxBuffer
  TpTxBuffer                                 the pointer to SoAd_TpTxBuffer
  TpTxBufferConfig                           the pointer to SoAd_TpTxBufferConfig
  TpTxBufferConfigDyn                        the pointer to SoAd_TpTxBufferConfigDyn
  TriggerBuf                                 the pointer to SoAd_TriggerBuf
  TriggerBufConfig                           the pointer to SoAd_TriggerBufConfig
  TriggerBufConfigDyn                        the pointer to SoAd_TriggerBufConfigDyn
  TxMgt                                      the pointer to SoAd_TxMgt
  TxPduIdMap                                 the pointer to SoAd_TxPduIdMap
  UpperLayer                                 the pointer to SoAd_UpperLayer
  MaxIfRouteGrpTransmitPduSize               the maximum length of all PDUs which can be sent via routing group transmit
  SizeOfBestMatchSoConIdxList                the number of accomplishable value elements in SoAd_BestMatchSoConIdxList
  SizeOfDhcpEventCbk                         the number of accomplishable value elements in SoAd_DhcpEventCbk
  SizeOfEventQueueFlag                       the number of accomplishable value elements in SoAd_EventQueueFlag
  SizeOfEventQueueIdent                      the number of accomplishable value elements in SoAd_EventQueueIdent
  SizeOfEventQueueIfTxRouteGrp               the number of accomplishable value elements in SoAd_EventQueueIfTxRouteGrp
  SizeOfEventQueueIfTxRouteGrpConfig         the number of accomplishable value elements in SoAd_EventQueueIfTxRouteGrpConfig
  SizeOfEventQueueIfUdpPduRoute              the number of accomplishable value elements in SoAd_EventQueueIfUdpPduRoute
  SizeOfEventQueueIfUdpPduRouteConfig        the number of accomplishable value elements in SoAd_EventQueueIfUdpPduRouteConfig
  SizeOfEventQueueMgmt                       the number of accomplishable value elements in SoAd_EventQueueMgmt
  SizeOfEventQueueStateSoCon                 the number of accomplishable value elements in SoAd_EventQueueStateSoCon
  SizeOfEventQueueStateSoConConfig           the number of accomplishable value elements in SoAd_EventQueueStateSoConConfig
  SizeOfEventQueueTpRxSoCon                  the number of accomplishable value elements in SoAd_EventQueueTpRxSoCon
  SizeOfEventQueueTpRxSoConConfig            the number of accomplishable value elements in SoAd_EventQueueTpRxSoConConfig
  SizeOfEventQueueTpTxSoCon                  the number of accomplishable value elements in SoAd_EventQueueTpTxSoCon
  SizeOfEventQueueTpTxSoConConfig            the number of accomplishable value elements in SoAd_EventQueueTpTxSoConConfig
  SizeOfIfRxBuffer                           the number of accomplishable value elements in SoAd_IfRxBuffer
  SizeOfInstance                             the number of accomplishable value elements in SoAd_Instance
  SizeOfInstanceMap                          the number of accomplishable value elements in SoAd_InstanceMap
  SizeOfIpFragBuf                            the number of accomplishable value elements in SoAd_IpFragBuf
  SizeOfIpFragBufConfig                      the number of accomplishable value elements in SoAd_IpFragBufConfig
  SizeOfIpFragMgt                            the number of accomplishable value elements in SoAd_IpFragMgt
  SizeOfLocalAddr                            the number of accomplishable value elements in SoAd_LocalAddr
  SizeOfLocalAddrByTcpIpCtrlInd              the number of accomplishable value elements in SoAd_LocalAddrByTcpIpCtrlInd
  SizeOfLocalAddrIdMap                       the number of accomplishable value elements in SoAd_LocalAddrIdMap
  SizeOfLocalIpAddrAssignmentChgCbk          the number of accomplishable value elements in SoAd_LocalIpAddrAssignmentChgCbk
  SizeOfLocalIpAddrAssignmentChgCbkInd       the number of accomplishable value elements in SoAd_LocalIpAddrAssignmentChgCbkInd
  SizeOfMetaDataRxBuffer                     the number of accomplishable value elements in SoAd_MetaDataRxBuffer
  SizeOfNPduUdpTx                            the number of accomplishable value elements in SoAd_NPduUdpTx
  SizeOfNPduUdpTxBuffer                      the number of accomplishable value elements in SoAd_NPduUdpTxBuffer
  SizeOfNPduUdpTxQueue                       the number of accomplishable value elements in SoAd_NPduUdpTxQueue
  SizeOfPartitionDyn                         the number of accomplishable value elements in SoAd_PartitionDyn
  SizeOfPduRoute                             the number of accomplishable value elements in SoAd_PduRoute
  SizeOfPduRouteDest                         the number of accomplishable value elements in SoAd_PduRouteDest
  SizeOfPduRouteDestBySoConInd               the number of accomplishable value elements in SoAd_PduRouteDestBySoConInd
  SizeOfPduRouteDestInd                      the number of accomplishable value elements in SoAd_PduRouteDestInd
  SizeOfRemAddrIpV4                          the number of accomplishable value elements in SoAd_RemAddrIpV4
  SizeOfRemAddrIpV6                          the number of accomplishable value elements in SoAd_RemAddrIpV6
  SizeOfRemAddrRcv                           the number of accomplishable value elements in SoAd_RemAddrRcv
  SizeOfRouteGrp                             the number of accomplishable value elements in SoAd_RouteGrp
  SizeOfRouteGrpIdMap                        the number of accomplishable value elements in SoAd_RouteGrpIdMap
  SizeOfRouteGrpSoCon                        the number of accomplishable value elements in SoAd_RouteGrpSoCon
  SizeOfRouteGrpSoConByPduRouteDestInd       the number of accomplishable value elements in SoAd_RouteGrpSoConByPduRouteDestInd
  SizeOfRouteGrpSoConBySocketRouteDestInd    the number of accomplishable value elements in SoAd_RouteGrpSoConBySocketRouteDestInd
  SizeOfRxBufStructMgt                       the number of accomplishable value elements in SoAd_RxBufStructMgt
  SizeOfRxBufStructSeg                       the number of accomplishable value elements in SoAd_RxBufStructSeg
  SizeOfRxBufferConfig                       the number of accomplishable value elements in SoAd_RxBufferConfig
  SizeOfRxMgt                                the number of accomplishable value elements in SoAd_RxMgt
  SizeOfRxPduIdIdMap                         the number of accomplishable value elements in SoAd_RxPduIdIdMap
  SizeOfShutdownFinishedCbk                  the number of accomplishable value elements in SoAd_ShutdownFinishedCbk
  SizeOfSoCon                                the number of accomplishable value elements in SoAd_SoCon
  SizeOfSoConGrp                             the number of accomplishable value elements in SoAd_SoConGrp
  SizeOfSoConMap                             the number of accomplishable value elements in SoAd_SoConMap
  SizeOfSoConModeChgCbk                      the number of accomplishable value elements in SoAd_SoConModeChgCbk
  SizeOfSoConModeChgCbkInd                   the number of accomplishable value elements in SoAd_SoConModeChgCbkInd
  SizeOfSocket                               the number of accomplishable value elements in SoAd_Socket
  SizeOfSocketRoute                          the number of accomplishable value elements in SoAd_SocketRoute
  SizeOfSocketRouteDest                      the number of accomplishable value elements in SoAd_SocketRouteDest
  SizeOfSocketRouteInd                       the number of accomplishable value elements in SoAd_SocketRouteInd
  SizeOfSocketTcp                            the number of accomplishable value elements in SoAd_SocketTcp
  SizeOfSocketUdp                            the number of accomplishable value elements in SoAd_SocketUdp
  SizeOfTcpIpCtrl                            the number of accomplishable value elements in SoAd_TcpIpCtrl
  SizeOfTcpKeepAliveGloballyEnabled          the number of accomplishable value elements in SoAd_TcpKeepAliveGloballyEnabled
  SizeOfTcpTxQueue                           the number of accomplishable value elements in SoAd_TcpTxQueue
  SizeOfTcpTxQueueData                       the number of accomplishable value elements in SoAd_TcpTxQueueData
  SizeOfTimeoutListIdent                     the number of accomplishable value elements in SoAd_TimeoutListIdent
  SizeOfTimeoutListMgmt                      the number of accomplishable value elements in SoAd_TimeoutListMgmt
  SizeOfTimeoutListNPduUdpTx                 the number of accomplishable value elements in SoAd_TimeoutListNPduUdpTx
  SizeOfTimeoutListNPduUdpTxConfig           the number of accomplishable value elements in SoAd_TimeoutListNPduUdpTxConfig
  SizeOfTimeoutListNPduUdpTxMap              the number of accomplishable value elements in SoAd_TimeoutListNPduUdpTxMap
  SizeOfTimeoutListTcpAutoConnectConfig      the number of accomplishable value elements in SoAd_TimeoutListTcpAutoConnectConfig
  SizeOfTimeoutListUdpAlive                  the number of accomplishable value elements in SoAd_TimeoutListUdpAlive
  SizeOfTimeoutListUdpAliveConfig            the number of accomplishable value elements in SoAd_TimeoutListUdpAliveConfig
  SizeOfTimeoutListUdpAliveMap               the number of accomplishable value elements in SoAd_TimeoutListUdpAliveMap
  SizeOfTpRxBuffer                           the number of accomplishable value elements in SoAd_TpRxBuffer
  SizeOfTpTxBuffer                           the number of accomplishable value elements in SoAd_TpTxBuffer
  SizeOfTpTxBufferConfig                     the number of accomplishable value elements in SoAd_TpTxBufferConfig
  SizeOfTriggerBuf                           the number of accomplishable value elements in SoAd_TriggerBuf
  SizeOfTriggerBufConfig                     the number of accomplishable value elements in SoAd_TriggerBufConfig
  SizeOfTxMgt                                the number of accomplishable value elements in SoAd_TxMgt
  SizeOfTxPduIdMap                           the number of accomplishable value elements in SoAd_TxPduIdMap
  SizeOfUpperLayer                           the number of accomplishable value elements in SoAd_UpperLayer
*/ 
#define SOAD_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(SoAd_PCPartitionConfigType, SOAD_CONST) SoAd_PCPartitionConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [SOAD_NO_OS_APPL_MAPPED] */
      SoAd_BestMatchSoConIdxList               /**< the pointer to SoAd_BestMatchSoConIdxList */
    , NULL_PTR                                 /**< the pointer to SoAd_DhcpEventCbk */
    , SoAd_EventQueueFlag                      /**< the pointer to SoAd_EventQueueFlag */
    , SoAd_EventQueueIdent                     /**< the pointer to SoAd_EventQueueIdent */
    , NULL_PTR                                 /**< the pointer to SoAd_EventQueueIfTxRouteGrp */
    , NULL_PTR                                 /**< the pointer to SoAd_EventQueueIfTxRouteGrpConfig */
    , SoAd_EventQueueIfUdpPduRoute             /**< the pointer to SoAd_EventQueueIfUdpPduRoute */
    , SoAd_EventQueueIfUdpPduRouteConfig       /**< the pointer to SoAd_EventQueueIfUdpPduRouteConfig */
    , SoAd_EventQueueMgmt                      /**< the pointer to SoAd_EventQueueMgmt */
    , SoAd_EventQueueStateSoCon                /**< the pointer to SoAd_EventQueueStateSoCon */
    , SoAd_EventQueueStateSoConConfig          /**< the pointer to SoAd_EventQueueStateSoConConfig */
    , NULL_PTR                                 /**< the pointer to SoAd_EventQueueTpRxSoCon */
    , NULL_PTR                                 /**< the pointer to SoAd_EventQueueTpRxSoConConfig */
    , NULL_PTR                                 /**< the pointer to SoAd_EventQueueTpTxSoCon */
    , NULL_PTR                                 /**< the pointer to SoAd_EventQueueTpTxSoConConfig */
    , NULL_PTR                                 /**< the pointer to SoAd_IfRxBuffer */
    , SoAd_Instance                            /**< the pointer to SoAd_Instance */
    , SoAd_InstanceDyn                         /**< the pointer to SoAd_InstanceDyn */
    , SoAd_InstanceMap                         /**< the pointer to SoAd_InstanceMap */
    , NULL_PTR                                 /**< the pointer to SoAd_IpFragBuf */
    , NULL_PTR                                 /**< the pointer to SoAd_IpFragBufConfig */
    , NULL_PTR                                 /**< the pointer to SoAd_IpFragBufConfigDyn */
    , NULL_PTR                                 /**< the pointer to SoAd_IpFragMgt */
    , SoAd_LocalAddr                           /**< the pointer to SoAd_LocalAddr */
    , SoAd_LocalAddrByTcpIpCtrlInd             /**< the pointer to SoAd_LocalAddrByTcpIpCtrlInd */
    , SoAd_LocalAddrDyn                        /**< the pointer to SoAd_LocalAddrDyn */
    , SoAd_LocalAddrIdMap                      /**< the pointer to SoAd_LocalAddrIdMap */
    , SoAd_LocalIpAddrAssignmentChgCbk         /**< the pointer to SoAd_LocalIpAddrAssignmentChgCbk */
    , SoAd_LocalIpAddrAssignmentChgCbkInd      /**< the pointer to SoAd_LocalIpAddrAssignmentChgCbkInd */
    , NULL_PTR                                 /**< the pointer to SoAd_MetaDataRxBuffer */
    , NULL_PTR                                 /**< the pointer to SoAd_NPduUdpTx */
    , NULL_PTR                                 /**< the pointer to SoAd_NPduUdpTxBuffer */
    , NULL_PTR                                 /**< the pointer to SoAd_NPduUdpTxDyn */
    , NULL_PTR                                 /**< the pointer to SoAd_NPduUdpTxQueue */
    , SoAd_PartitionDyn                        /**< the pointer to SoAd_PartitionDyn */
    , SoAd_PduRoute                            /**< the pointer to SoAd_PduRoute */
    , SoAd_PduRouteDest                        /**< the pointer to SoAd_PduRouteDest */
    , SoAd_PduRouteDestBySoConInd              /**< the pointer to SoAd_PduRouteDestBySoConInd */
    , SoAd_PduRouteDestInd                     /**< the pointer to SoAd_PduRouteDestInd */
    , SoAd_PduRouteDyn                         /**< the pointer to SoAd_PduRouteDyn */
    , SoAd_RemAddrIpV4                         /**< the pointer to SoAd_RemAddrIpV4 */
    , NULL_PTR                                 /**< the pointer to SoAd_RemAddrIpV6 */
    , SoAd_RemAddrRcv                          /**< the pointer to SoAd_RemAddrRcv */
    , SoAd_RouteGrp                            /**< the pointer to SoAd_RouteGrp */
    , SoAd_RouteGrpIdMap                       /**< the pointer to SoAd_RouteGrpIdMap */
    , SoAd_RouteGrpSoCon                       /**< the pointer to SoAd_RouteGrpSoCon */
    , SoAd_RouteGrpSoConByPduRouteDestInd      /**< the pointer to SoAd_RouteGrpSoConByPduRouteDestInd */
    , SoAd_RouteGrpSoConBySocketRouteDestInd   /**< the pointer to SoAd_RouteGrpSoConBySocketRouteDestInd */
    , SoAd_RouteGrpSoConDyn                    /**< the pointer to SoAd_RouteGrpSoConDyn */
    , NULL_PTR                                 /**< the pointer to SoAd_RxBufStructMgt */
    , NULL_PTR                                 /**< the pointer to SoAd_RxBufStructSeg */
    , NULL_PTR                                 /**< the pointer to SoAd_RxBufferConfig */
    , NULL_PTR                                 /**< the pointer to SoAd_RxBufferConfigDyn */
    , SoAd_RxMgt                               /**< the pointer to SoAd_RxMgt */
    , SoAd_RxPduIdIdMap                        /**< the pointer to SoAd_RxPduIdIdMap */
    , NULL_PTR                                 /**< the pointer to SoAd_ShutdownFinishedCbk */
    , SoAd_SoCon                               /**< the pointer to SoAd_SoCon */
    , SoAd_SoConDyn                            /**< the pointer to SoAd_SoConDyn */
    , SoAd_SoConGrp                            /**< the pointer to SoAd_SoConGrp */
    , SoAd_SoConMap                            /**< the pointer to SoAd_SoConMap */
    , SoAd_SoConModeChgCbk                     /**< the pointer to SoAd_SoConModeChgCbk */
    , SoAd_SoConModeChgCbkInd                  /**< the pointer to SoAd_SoConModeChgCbkInd */
    , SoAd_Socket                              /**< the pointer to SoAd_Socket */
    , SoAd_SocketDyn                           /**< the pointer to SoAd_SocketDyn */
    , SoAd_SocketRoute                         /**< the pointer to SoAd_SocketRoute */
    , SoAd_SocketRouteDest                     /**< the pointer to SoAd_SocketRouteDest */
    , SoAd_SocketRouteInd                      /**< the pointer to SoAd_SocketRouteInd */
    , NULL_PTR                                 /**< the pointer to SoAd_SocketTcp */
    , SoAd_SocketUdp                           /**< the pointer to SoAd_SocketUdp */
    , SoAd_TcpIpCtrl                           /**< the pointer to SoAd_TcpIpCtrl */
    , SoAd_TcpKeepAliveGloballyEnabled         /**< the pointer to SoAd_TcpKeepAliveGloballyEnabled */
    , NULL_PTR                                 /**< the pointer to SoAd_TcpTxQueue */
    , NULL_PTR                                 /**< the pointer to SoAd_TcpTxQueueData */
    , NULL_PTR                                 /**< the pointer to SoAd_TcpTxQueueMgt */
    , SoAd_TimeoutListIdent                    /**< the pointer to SoAd_TimeoutListIdent */
    , SoAd_TimeoutListMgmt                     /**< the pointer to SoAd_TimeoutListMgmt */
    , NULL_PTR                                 /**< the pointer to SoAd_TimeoutListNPduUdpTx */
    , NULL_PTR                                 /**< the pointer to SoAd_TimeoutListNPduUdpTxConfig */
    , NULL_PTR                                 /**< the pointer to SoAd_TimeoutListNPduUdpTxMap */
    , NULL_PTR                                 /**< the pointer to SoAd_TimeoutListTcpAutoConnectConfig */
    , SoAd_TimeoutListUdpAlive                 /**< the pointer to SoAd_TimeoutListUdpAlive */
    , SoAd_TimeoutListUdpAliveConfig           /**< the pointer to SoAd_TimeoutListUdpAliveConfig */
    , SoAd_TimeoutListUdpAliveMap              /**< the pointer to SoAd_TimeoutListUdpAliveMap */
    , NULL_PTR                                 /**< the pointer to SoAd_TpRxBuffer */
    , NULL_PTR                                 /**< the pointer to SoAd_TpTxBuffer */
    , NULL_PTR                                 /**< the pointer to SoAd_TpTxBufferConfig */
    , NULL_PTR                                 /**< the pointer to SoAd_TpTxBufferConfigDyn */
    , NULL_PTR                                 /**< the pointer to SoAd_TriggerBuf */
    , NULL_PTR                                 /**< the pointer to SoAd_TriggerBufConfig */
    , NULL_PTR                                 /**< the pointer to SoAd_TriggerBufConfigDyn */
    , SoAd_TxMgt                               /**< the pointer to SoAd_TxMgt */
    , SoAd_TxPduIdMap                          /**< the pointer to SoAd_TxPduIdMap */
    , SoAd_UpperLayer                          /**< the pointer to SoAd_UpperLayer */
    , 0u
    , 2u                                       /**< the number of elements in SoAd_BestMatchSoConIdxList */
    , 0u                                       /**< the number of elements in SoAd_DhcpEventCbk */
    , 9u                                       /**< the number of elements in SoAd_EventQueueFlag */
    , 1u                                       /**< the number of elements in SoAd_EventQueueIdent */
    , 0u                                       /**< the number of elements in SoAd_EventQueueIfTxRouteGrp */
    , 0u                                       /**< the number of elements in SoAd_EventQueueIfTxRouteGrpConfig */
    , 8u                                       /**< the number of elements in SoAd_EventQueueIfUdpPduRoute */
    , 1u                                       /**< the number of elements in SoAd_EventQueueIfUdpPduRouteConfig */
    , 2u                                       /**< the number of elements in SoAd_EventQueueMgmt */
    , 9u                                       /**< the number of elements in SoAd_EventQueueStateSoCon */
    , 1u                                       /**< the number of elements in SoAd_EventQueueStateSoConConfig */
    , 0u                                       /**< the number of elements in SoAd_EventQueueTpRxSoCon */
    , 0u                                       /**< the number of elements in SoAd_EventQueueTpRxSoConConfig */
    , 0u                                       /**< the number of elements in SoAd_EventQueueTpTxSoCon */
    , 0u                                       /**< the number of elements in SoAd_EventQueueTpTxSoConConfig */
    , 0u                                       /**< the number of elements in SoAd_IfRxBuffer */
    , 1u                                       /**< the number of elements in SoAd_Instance */
    , 1u                                       /**< the number of elements in SoAd_InstanceMap */
    , 0u                                       /**< the number of elements in SoAd_IpFragBuf */
    , 0u                                       /**< the number of elements in SoAd_IpFragBufConfig */
    , 0u                                       /**< the number of elements in SoAd_IpFragMgt */
    , 2u                                       /**< the number of elements in SoAd_LocalAddr */
    , 1u                                       /**< the number of elements in SoAd_LocalAddrByTcpIpCtrlInd */
    , 4u                                       /**< the number of elements in SoAd_LocalAddrIdMap */
    , 1u                                       /**< the number of elements in SoAd_LocalIpAddrAssignmentChgCbk */
    , 3u                                       /**< the number of elements in SoAd_LocalIpAddrAssignmentChgCbkInd */
    , 0u                                       /**< the number of elements in SoAd_MetaDataRxBuffer */
    , 0u                                       /**< the number of elements in SoAd_NPduUdpTx */
    , 0u                                       /**< the number of elements in SoAd_NPduUdpTxBuffer */
    , 0u                                       /**< the number of elements in SoAd_NPduUdpTxQueue */
    , 1u                                       /**< the number of elements in SoAd_PartitionDyn */
    , 8u                                       /**< the number of elements in SoAd_PduRoute */
    , 8u                                       /**< the number of elements in SoAd_PduRouteDest */
    , 8u                                       /**< the number of elements in SoAd_PduRouteDestBySoConInd */
    , 7u                                       /**< the number of elements in SoAd_PduRouteDestInd */
    , 9u                                       /**< the number of elements in SoAd_RemAddrIpV4 */
    , 0u                                       /**< the number of elements in SoAd_RemAddrIpV6 */
    , 2u                                       /**< the number of elements in SoAd_RemAddrRcv */
    , 5u                                       /**< the number of elements in SoAd_RouteGrp */
    , 5u                                       /**< the number of elements in SoAd_RouteGrpIdMap */
    , 8u                                       /**< the number of elements in SoAd_RouteGrpSoCon */
    , 7u                                       /**< the number of elements in SoAd_RouteGrpSoConByPduRouteDestInd */
    , 3u                                       /**< the number of elements in SoAd_RouteGrpSoConBySocketRouteDestInd */
    , 0u                                       /**< the number of elements in SoAd_RxBufStructMgt */
    , 0u                                       /**< the number of elements in SoAd_RxBufStructSeg */
    , 0u                                       /**< the number of elements in SoAd_RxBufferConfig */
    , 6u                                       /**< the number of elements in SoAd_RxMgt */
    , 6u                                       /**< the number of elements in SoAd_RxPduIdIdMap */
    , 0u                                       /**< the number of elements in SoAd_ShutdownFinishedCbk */
    , 9u                                       /**< the number of elements in SoAd_SoCon */
    , 7u                                       /**< the number of elements in SoAd_SoConGrp */
    , 9u                                       /**< the number of elements in SoAd_SoConMap */
    , 2u                                       /**< the number of elements in SoAd_SoConModeChgCbk */
    , 5u                                       /**< the number of elements in SoAd_SoConModeChgCbkInd */
    , 7u                                       /**< the number of elements in SoAd_Socket */
    , 6u                                       /**< the number of elements in SoAd_SocketRoute */
    , 6u                                       /**< the number of elements in SoAd_SocketRouteDest */
    , 3u                                       /**< the number of elements in SoAd_SocketRouteInd */
    , 0u                                       /**< the number of elements in SoAd_SocketTcp */
    , 7u                                       /**< the number of elements in SoAd_SocketUdp */
    , 1u                                       /**< the number of elements in SoAd_TcpIpCtrl */
    , 1u                                       /**< the number of elements in SoAd_TcpKeepAliveGloballyEnabled */
    , 0u                                       /**< the number of elements in SoAd_TcpTxQueue */
    , 0u                                       /**< the number of elements in SoAd_TcpTxQueueData */
    , 1u                                       /**< the number of elements in SoAd_TimeoutListIdent */
    , 1u                                       /**< the number of elements in SoAd_TimeoutListMgmt */
    , 0u                                       /**< the number of elements in SoAd_TimeoutListNPduUdpTx */
    , 0u                                       /**< the number of elements in SoAd_TimeoutListNPduUdpTxConfig */
    , 0u                                       /**< the number of elements in SoAd_TimeoutListNPduUdpTxMap */
    , 0u                                       /**< the number of elements in SoAd_TimeoutListTcpAutoConnectConfig */
    , 3u                                       /**< the number of elements in SoAd_TimeoutListUdpAlive */
    , 1u                                       /**< the number of elements in SoAd_TimeoutListUdpAliveConfig */
    , 9u                                       /**< the number of elements in SoAd_TimeoutListUdpAliveMap */
    , 0u                                       /**< the number of elements in SoAd_TpRxBuffer */
    , 0u                                       /**< the number of elements in SoAd_TpTxBuffer */
    , 0u                                       /**< the number of elements in SoAd_TpTxBufferConfig */
    , 0u                                       /**< the number of elements in SoAd_TriggerBuf */
    , 0u                                       /**< the number of elements in SoAd_TriggerBufConfig */
    , 5u                                       /**< the number of elements in SoAd_TxMgt */
    , 8u                                       /**< the number of elements in SoAd_TxPduIdMap */
    , 4u                                       /**< the number of elements in SoAd_UpperLayer */
  }
};
#define SOAD_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define SOAD_START_SEC_VAR_CLEARED_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/*! Pointer to the post-build configuration. */
P2CONST(SoAd_ConfigType, SOAD_VAR_CLEARED, SOAD_PBCFG) SoAd_ConfigDataPtr = NULL_PTR;

#define SOAD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define SOAD_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

FUNC(void, SOAD_CODE) SoAd_MainFunction(void)
{
  SoAd_MainFunctionInstance(0u);
}



#define SOAD_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "SoAd_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
 *  END OF FILE: SoAd_Lcfg.c
 *********************************************************************************************************************/

