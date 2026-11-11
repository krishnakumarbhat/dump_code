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
 *            Module: TcpIp
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: TcpIp_Lcfg.c
 *   Generation Time: 2026-09-01 16:41:00
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

/* PRQA S 0828 EOF */ /* MD_MSR_1.1_828 */
/* PRQA S 1257 EOF */ /* MD_CSL_Rule10.3_OldValidLib */

/*lint -e552 */

#define TCPIP_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "TcpIp_Lcfg.h"
#include "TcpIp_Cfg.h"
#include "TcpIp.h"
#include "Det.h"
#include "Appl_Rand.h" 
#include "SoAd_Cbk.h" 


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
#define TCPIP_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

TCPIP_P2C(TcpIp_ConfigType) TcpIp_ConfigDataPtr = NULL_PTR;

#define TCPIP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 0612 OBJECT_SIZE */ /* MD_TcpIp_0612_BufferSize */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  TcpIp_AddrAssignmentCfgByPrio
**********************************************************************************************************************/
/** 
  \var    TcpIp_AddrAssignmentCfgByPrio
  \brief  -
*/ 
#define TCPIP_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_AddrAssignmentCfgByPrioType, TCPIP_CONST) TcpIp_AddrAssignmentCfgByPrio[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     AddrAssignmentCfgByPrio               Referable Keys */
  /*     0 */ (TCPIP_IPADDR_ASSIGNMENT_STATIC)    /* [/ActiveEcuC/TcpIp/TcpIpConfig/cnctr_RDR_RdrNet_1bd20df5/TcpIpIpVXCtrl/TcpIpIpV4Ctrl] */
};
#define TCPIP_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_ArpConfig
**********************************************************************************************************************/
/** 
  \var    TcpIp_ArpConfig
  \details
  Element                      Description
  RetryTime                    Retry Timeout - Value of configuration parameter TcpIpArpRetryTime [MAIN_FUNCTION_CYCLES]
  RequestTimeout               Value of configuration parameter TcpIpArpRequestTimeout [MAIN_FUNCTION_CYCLES]
  RetryInterval                Retry Interval - Value of configuration parameter TcpIpArpRetryInterval [MAIN_FUNCTION_CYCLES]
  PacketQueueEnabled           Packet Queue Enabled - Value of configuration parameter TcpIpArpPacketQueueEnabled [BOOLEAN]
  EntryTimeout                 Table Entry Timeout - Value of configuration parameter TcpIpArpTableEntryTimeout [MAIN_FUNCTION_CYCLES]
  NumGratuitousArpOnStartup    Num Gratuitous ARP On Startup - Value of configuration parameter TcpIpArpNumGratuitousARPonStartup
  TableSize                    Table Size Max - Value of configuration parameter TcpIpArpTableSizeMax
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_ArpConfigType, TCPIP_CONST) TcpIp_ArpConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RetryTime  RequestTimeout  RetryInterval  PacketQueueEnabled  EntryTimeout  NumGratuitousArpOnStartup  TableSize        Referable Keys */
  { /*     0 */   120000u,           400u,          400u,               TRUE,           0u,                        0u,       10u }   /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpIpConfig/TcpIpIpV4Config/TcpIpArpConfig] */
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_DefaultMulticastAddrV4
**********************************************************************************************************************/
/** 
  \var    TcpIp_DefaultMulticastAddrV4
  \brief  -
  \details
  Element    Description
  NetAddr    -
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_DefaultMulticastAddrV4Type, TCPIP_CONST) TcpIp_DefaultMulticastAddrV4[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    NetAddr                                                   Referable Keys */
  { /*     0 */ 0xFBFFC0EFu /*  239.192.255.251 LITTLE_ENDIAN  */  },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/NEP_ADAS_RdrNet_CtrlRxMulticast_91909614] */
  { /*     1 */ IPV4_ADDR_ANY                                      }   /* [/ActiveEcuC/TcpIp/TcpIpConfig/NEP_ANY_IP_c7cdbb5a] */
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_DefaultUnicastAddrV4
**********************************************************************************************************************/
/** 
  \var    TcpIp_DefaultUnicastAddrV4
  \brief  -
  \details
  Element      Description
  DefGwAddr    -
  NetAddr      -
  NetMask      -
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_DefaultUnicastAddrV4Type, TCPIP_CONST) TcpIp_DefaultUnicastAddrV4[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DefGwAddr                                   NetAddr                                          NetMask                                                 Referable Keys */
  { /*     0 */ 0x00000000u /*  0.0.0.0 LITTLE_ENDIAN  */ , 0x4701A8C0u /*  192.168.1.71 LITTLE_ENDIAN  */ , 0x00FFFFFFu /*  255.255.255.0 LITTLE_ENDIAN  */  }   /* [/ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027] */
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_DuplicateAddrDetectionFctPtr
**********************************************************************************************************************/
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_DuplicateAddrDetectionCbkType, TCPIP_CONST) TcpIp_DuplicateAddrDetectionFctPtr = NULL_PTR;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_EthIfCtrl
**********************************************************************************************************************/
/** 
  \var    TcpIp_EthIfCtrl
  \brief  Array mapping from EthIfCtrlIdx to IpCtrlIdx
  \details
  Element        Description
  IpV4CtrlIdx    the index of the 0:1 relation pointing to TcpIp_IpV4Ctrl
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_EthIfCtrlType, TCPIP_CONST) TcpIp_EthIfCtrl[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpV4CtrlIdx */
  { /*     0 */          0u }
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_IcmpMsgHandlerCbkFctPtr
**********************************************************************************************************************/
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_IcmpMsgHandlerCbkType, TCPIP_CONST) TcpIp_IcmpMsgHandlerCbkFctPtr = NULL_PTR;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_IpV4Ctrl
**********************************************************************************************************************/
/** 
  \var    TcpIp_IpV4Ctrl
  \details
  Element                            Description
  MaxTxMsgSize                       -
  MtuTx                              Value of configuration parameter EthIfCtrlMtu
  AddrAssignmentCfgByPrioEndIdx      the end index of the 1:n relation pointing to TcpIp_AddrAssignmentCfgByPrio
  AddrAssignmentCfgByPrioStartIdx    the start index of the 1:n relation pointing to TcpIp_AddrAssignmentCfgByPrio
  AddrAssignmentPrioByType           -
  ArpConfigIdx                       the index of the 0:1 relation pointing to TcpIp_ArpConfig
  ArpTableEntryEndIdx                the end index of the 0:n relation pointing to TcpIp_ArpTableEntry
  ArpTableEntryStartIdx              the start index of the 0:n relation pointing to TcpIp_ArpTableEntry
  AutoIpConfigIdx                    the index of the 0:1 relation pointing to TcpIp_AutoIpConfig
  Buf2TxReqMapEndIdx                 the end index of the 1:n relation pointing to TcpIp_Buf2TxReqMap
  Buf2TxReqMapStartIdx               the start index of the 1:n relation pointing to TcpIp_Buf2TxReqMap
  DefaultTtl                         Default Time To Live - Value of configuration parameter TcpIpIpDefaultTtl
  DhcpConfigIdx                      the index of the 0:1 relation pointing to TcpIp_DhcpConfig
  DhcpStatusIdx                      the index of the 0:1 relation pointing to TcpIp_DhcpStatus
  DhcpUserOptionEndIdx               the end index of the 0:n relation pointing to TcpIp_DhcpUserOption
  DhcpUserOptionStartIdx             the start index of the 0:n relation pointing to TcpIp_DhcpUserOption
  EthIfCtrlIdx                       -
  FragmentationConfigIdx             the index of the 0:1 relation pointing to TcpIp_FragmentationConfig
  FramePrioDefault                   IP Frame Prio Default - Value of configuration parameter TcpIpIpFramePrioDefault
  GratuitousArpIdx                   the index of the 0:1 relation pointing to TcpIp_GratuitousArp
  LlAddrStateIdx                     the index of the 0:1 relation pointing to TcpIp_LlAddrState
  LocalAddrV4BroadcastIdx            the index of the 1:1 relation pointing to TcpIp_LocalAddrV4
  LocalAddrV4UnicastIdx              the index of the 1:1 relation pointing to TcpIp_LocalAddrV4
  MaskedBits                         contains bitcoded the boolean data of TcpIp_DisableDhcpIfTcpConnectedOfIpV4Ctrl, TcpIp_HwChecksumIcmpOfIpV4Ctrl, TcpIp_HwChecksumIpOfIpV4Ctrl, TcpIp_HwChecksumTcpOfIpV4Ctrl, TcpIp_HwChecksumUdpOfIpV4Ctrl, TcpIp_ReceiveAllMulticastsOfIpV4Ctrl
  MulticastAddrV4EndIdx              the end index of the 0:n relation pointing to TcpIp_MulticastAddrV4
  MulticastAddrV4StartIdx            the start index of the 0:n relation pointing to TcpIp_MulticastAddrV4
  StaticArpTableIdx                  the index of the 0:1 relation pointing to TcpIp_StaticArpTable
  TypeOfServiceDefault               IP Type Of Service Default - Value of configuration parameter TcpIpIpTypeOfServiceDefault
  UnicastAddrV4Idx                   the index of the 1:1 relation pointing to TcpIp_UnicastAddrV4
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_IpV4CtrlType, TCPIP_CONST) TcpIp_IpV4Ctrl[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MaxTxMsgSize  MtuTx  AddrAssignmentCfgByPrioEndIdx  AddrAssignmentCfgByPrioStartIdx  AddrAssignmentPrioByType                                          ArpConfigIdx  ArpTableEntryEndIdx  ArpTableEntryStartIdx  AutoIpConfigIdx                     Buf2TxReqMapEndIdx  Buf2TxReqMapStartIdx  DefaultTtl  DhcpConfigIdx                     DhcpStatusIdx                     DhcpUserOptionEndIdx                     DhcpUserOptionStartIdx                     EthIfCtrlIdx                                         FragmentationConfigIdx                     FramePrioDefault  GratuitousArpIdx                     LlAddrStateIdx                     LocalAddrV4BroadcastIdx  LocalAddrV4UnicastIdx  MaskedBits  MulticastAddrV4EndIdx  MulticastAddrV4StartIdx  StaticArpTableIdx                     TypeOfServiceDefault  UnicastAddrV4Idx        Referable Keys */
  { /*     0 */        1500u, 1500u,                            1u,                              0u,                    0x04u  /* DHCP(-), LINKLOCAL(-), STATIC(1) */,           0u,                 10u,                    0u, TCPIP_NO_AUTOIPCONFIGIDXOFIPV4CTRL,               100u,                   0u,       255u, TCPIP_NO_DHCPCONFIGIDXOFIPV4CTRL, TCPIP_NO_DHCPSTATUSIDXOFIPV4CTRL, TCPIP_NO_DHCPUSEROPTIONENDIDXOFIPV4CTRL, TCPIP_NO_DHCPUSEROPTIONSTARTIDXOFIPV4CTRL, EthIfConf_EthIfController_cnctr_RDR_RdrNet_5172a59b, TCPIP_NO_FRAGMENTATIONCONFIGIDXOFIPV4CTRL,               0u, TCPIP_NO_GRATUITOUSARPIDXOFIPV4CTRL, TCPIP_NO_LLADDRSTATEIDXOFIPV4CTRL,                      3u,                    0u,      0x1Eu,                    2u,                      0u, TCPIP_NO_STATICARPTABLEIDXOFIPV4CTRL,                   0u,               0u }   /* [/ActiveEcuC/TcpIp/TcpIpConfig/cnctr_RDR_RdrNet_1bd20df5] */
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_IpV4General
**********************************************************************************************************************/
/** 
  \var    TcpIp_IpV4General
  \details
  Element                   Description
  IpV4CtrlDefaultIdx        the index of the 0:1 relation pointing to TcpIp_IpV4Ctrl
  IpV4SocketDynDhcpIdx      the index of the 0:1 relation pointing to TcpIp_IpV4SocketDyn
  IpV4SocketDynIcmpIdx      the index of the 0:1 relation pointing to TcpIp_IpV4SocketDyn
  IpV4SocketDynTcpRstIdx    the index of the 0:1 relation pointing to TcpIp_IpV4SocketDyn
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_IpV4GeneralType, TCPIP_CONST) TcpIp_IpV4General[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpV4CtrlDefaultIdx                        IpV4SocketDynDhcpIdx                        IpV4SocketDynIcmpIdx                        IpV4SocketDynTcpRstIdx                       */
  { /*     0 */ TCPIP_NO_IPV4CTRLDEFAULTIDXOFIPV4GENERAL, TCPIP_NO_IPV4SOCKETDYNDHCPIDXOFIPV4GENERAL, TCPIP_NO_IPV4SOCKETDYNICMPIDXOFIPV4GENERAL, TCPIP_NO_IPV4SOCKETDYNTCPRSTIDXOFIPV4GENERAL }
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_LocalAddrV4
**********************************************************************************************************************/
/** 
  \var    TcpIp_LocalAddrV4
  \brief  -
  \details
  Element               Description
  IpV4CtrlIdx           the index of the 1:1 relation pointing to TcpIp_IpV4Ctrl
  MulticastAddrV4Idx    the index of the 0:1 relation pointing to TcpIp_MulticastAddrV4
  UnicastAddrV4Idx      the index of the 0:1 relation pointing to TcpIp_UnicastAddrV4
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_LocalAddrV4Type, TCPIP_CONST) TcpIp_LocalAddrV4[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IpV4CtrlIdx  MulticastAddrV4Idx                        UnicastAddrV4Idx                              Referable Keys */
  { /*     0 */          0u, TCPIP_NO_MULTICASTADDRV4IDXOFLOCALADDRV4,                                     0u },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027, /ActiveEcuC/TcpIp/TcpIpConfig/cnctr_RDR_RdrNet_1bd20df5/TcpIpIpVXCtrl/TcpIpIpV4Ctrl] */
  { /*     1 */          0u,                                       0u, TCPIP_NO_UNICASTADDRV4IDXOFLOCALADDRV4 },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/NEP_ADAS_RdrNet_CtrlRxMulticast_91909614, /ActiveEcuC/TcpIp/TcpIpConfig/cnctr_RDR_RdrNet_1bd20df5/TcpIpIpVXCtrl/TcpIpIpV4Ctrl] */
  { /*     2 */          0u,                                       1u, TCPIP_NO_UNICASTADDRV4IDXOFLOCALADDRV4 },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/NEP_ANY_IP_c7cdbb5a, /ActiveEcuC/TcpIp/TcpIpConfig/cnctr_RDR_RdrNet_1bd20df5/TcpIpIpVXCtrl/TcpIpIpV4Ctrl] */
  { /*     3 */          0u, TCPIP_NO_MULTICASTADDRV4IDXOFLOCALADDRV4, TCPIP_NO_UNICASTADDRV4IDXOFLOCALADDRV4 }   /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpV4LocalAddr_RDR_EthConnector1_fbdc15b4_Broadcast, /ActiveEcuC/TcpIp/TcpIpConfig/cnctr_RDR_RdrNet_1bd20df5/TcpIpIpVXCtrl/TcpIpIpV4Ctrl] */
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_MulticastAddrV4
**********************************************************************************************************************/
/** 
  \var    TcpIp_MulticastAddrV4
  \brief  Structure containing all statically configured IP address information.
  \details
  Element                      Description
  DefaultMulticastAddrV4Idx    the index of the 1:1 relation pointing to TcpIp_DefaultMulticastAddrV4
  LocalAddrV4Idx               the index of the 1:1 relation pointing to TcpIp_LocalAddrV4
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_MulticastAddrV4Type, TCPIP_CONST) TcpIp_MulticastAddrV4[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DefaultMulticastAddrV4Idx  LocalAddrV4Idx        Referable Keys */
  { /*     0 */                        0u,             1u },  /* [/ActiveEcuC/TcpIp/TcpIpConfig/NEP_ADAS_RdrNet_CtrlRxMulticast_91909614, /ActiveEcuC/TcpIp/TcpIpConfig/cnctr_RDR_RdrNet_1bd20df5] */
  { /*     1 */                        1u,             2u }   /* [/ActiveEcuC/TcpIp/TcpIpConfig/NEP_ANY_IP_c7cdbb5a, /ActiveEcuC/TcpIp/TcpIpConfig/cnctr_RDR_RdrNet_1bd20df5] */
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_RandomNumberFctPtr
**********************************************************************************************************************/
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_GetRandomNumberType, TCPIP_CONST) TcpIp_RandomNumberFctPtr = Appl_Crypto_GetRandNo;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_SocketOwnerConfig
**********************************************************************************************************************/
/** 
  \var    TcpIp_SocketOwnerConfig
  \brief  -
  \details
  Element                            Description
  CopyTxDataDynFuncPtr               [User]_CopyTxDataDyn Callback Function. (only required if socket owner uses indirect data provision in Tcp/UdpTransmit.)
  CopyTxDataFuncPtr                  [User]_CopyTxData Callback Function. (only required if socket owner uses indirect data provision in Tcp/UdpTransmit.)
  DhcpEventFuncPtr                   Callout triggered on reception and transmission of client DHCP messages.
  LocalIpAddrAssignmentChgFuncPtr    -
  RxIndicationFuncPtr                [User]_RxIndication Callback Function. (required for socket owner that receives packets.)
  TcpAcceptedFuncPtr                 [User]_TcpAccepted Callback Function. (only required if socket passively accepts TCP connections.)
  TcpConnectedFuncPtr                [User]_TcpConnected Callback Function. (only required if socket owner actively opens TCP connections.)
  TcpIpEventFuncPtr                  [User]_TcpIpEvent Callback Function. (required for every socket owner)
  TlsChangeableCipherFuncPtr         [User]_TlsChangeableCipher Callback Function.
  TlsSessionTicketUpdateFuncPtr      [User]_TlsSessionTicketUpdate Callback Function.
  TlsValidationResultFuncPtr         [User]_TlsValidationResult Callback Function.
  TxConfirmationFuncPtr              [User]_TxConfirmation Callback Function. (optional for every socket owner)
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_SocketOwnerConfigType, TCPIP_CONST) TcpIp_SocketOwnerConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CopyTxDataDynFuncPtr  CopyTxDataFuncPtr  DhcpEventFuncPtr  LocalIpAddrAssignmentChgFuncPtr  RxIndicationFuncPtr  TcpAcceptedFuncPtr  TcpConnectedFuncPtr  TcpIpEventFuncPtr  TlsChangeableCipherFuncPtr  TlsSessionTicketUpdateFuncPtr  TlsValidationResultFuncPtr  TxConfirmationFuncPtr */
  { /*     0 */ NULL_PTR            , SoAd_CopyTxData  , NULL_PTR        , SoAd_LocalIpAddrAssignmentChg  , SoAd_RxIndication  , SoAd_TcpAccepted  , SoAd_TcpConnected  , SoAd_TcpIpEvent  , NULL_PTR                  , NULL_PTR                     , NULL_PTR                  , SoAd_TxConfirmation   }
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_UdpConfig
**********************************************************************************************************************/
/** 
  \var    TcpIp_UdpConfig
  \details
  Element    Description
  PortMax    Udp Dynamic Port Max - Value of configuration parameter TcpIpUdpPortMax
  PortMin    Udp Dynamic Port Min - Value of configuration parameter TcpIpUdpPortMin
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_UdpConfigType, TCPIP_CONST) TcpIp_UdpConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PortMax  PortMin */
  { /*     0 */  65535u,  49152u }
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_UnicastAddrV4
**********************************************************************************************************************/
/** 
  \var    TcpIp_UnicastAddrV4
  \brief  Structure containing all statically configured IP address information.
  \details
  Element                            Description
  DefaultUnicastAddrV4Idx            the index of the 0:1 relation pointing to TcpIp_DefaultUnicastAddrV4
  StaticUnicastAddrV4RequestedIdx    the index of the 0:1 relation pointing to TcpIp_StaticUnicastAddrV4Requested
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_UnicastAddrV4Type, TCPIP_CONST) TcpIp_UnicastAddrV4[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DefaultUnicastAddrV4Idx  StaticUnicastAddrV4RequestedIdx        Referable Keys */
  { /*     0 */                      0u,                              0u }   /* [/ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027, /ActiveEcuC/TcpIp/TcpIpConfig/cnctr_RDR_RdrNet_1bd20df5] */
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_ArpTableEntry
**********************************************************************************************************************/
/** 
  \var    TcpIp_ArpTableEntry
  \brief  -
  \details
  Element              Description
  CreationTimeStamp    Time when this entry was created [MAIN_FUNCTION_CYCLES]
  TimeStamp            Time when this entry was marked as valid [MAIN_FUNCTION_CYCLES]
  InfinitTime          Indicate if this entry can not expire
  Status               Status of this ARP entry (INVALID, INPROGRESS, VALID, PROBE)
  NetAddr              Network (IP) address of the neighbor node
  PhysAddr             Physical (MAC) address of the neighbor node
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_ArpTableEntryType, TCPIP_VAR_NO_INIT) TcpIp_ArpTableEntry[10];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/cnctr_RDR_RdrNet_1bd20df5] */
  /*   ... */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/cnctr_RDR_RdrNet_1bd20df5] */
  /*     9 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/cnctr_RDR_RdrNet_1bd20df5] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_Buf2TxReqMap
**********************************************************************************************************************/
/** 
  \var    TcpIp_Buf2TxReqMap
  \brief  -
  \details
  Element             Description
  EthBufLen           -
  EthBufIdxNext       -
  IpV4SocketDynIdx    the index of the 0:1 relation pointing to TcpIp_IpV4SocketDyn
  UlTxReqIdx          -
  EthBufPtr           -
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_Buf2TxReqMapType, TCPIP_VAR_NO_INIT) TcpIp_Buf2TxReqMap[100];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb] */
  /*   ... */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb] */
  /*    99 */  /* [/ActiveEcuC/Eth/EthConfigSet/RDR_1_Eth_Controller_1_6addc1bb] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_EthIfCtrlDyn
**********************************************************************************************************************/
/** 
  \var    TcpIp_EthIfCtrlDyn
  \brief  -
  \details
  Element    Description
  State      State of the controller
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_EthIfCtrlDynType, TCPIP_VAR_NO_INIT) TcpIp_EthIfCtrlDyn[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_IpV4CtrlDyn
**********************************************************************************************************************/
/** 
  \var    TcpIp_IpV4CtrlDyn
  \brief  -
  \details
  Element                         Description
  ActiveAddrAssignmentMethod      -
  AddrAssignmentReadyChanged      -
  AddrAssignmentTriggeredFlags    -
  NumPendArpElem                  Number of pendling elements
  PreOnHold                       The state before state OnHold
  RequestedState                  The requested state
  State                           -
  StopDhcpTxAndRx                 Flag used to stop DHCP communication
  ActiveDefGwAddr                 -
  ActiveNetAddr                   -
  ActiveNetMask                   -
  LastBcAddr                      -
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_IpV4CtrlDynType, TCPIP_VAR_NO_INIT) TcpIp_IpV4CtrlDyn[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/cnctr_RDR_RdrNet_1bd20df5] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_IpV4SocketDyn
**********************************************************************************************************************/
/** 
  \var    TcpIp_IpV4SocketDyn
  \brief  -
  \details
  Element                 Description
  ArpTableEntryIdx        the index of the 0:1 relation pointing to TcpIp_ArpTableEntry
  EthIfFramePrio          -
  Flags                   -
  IpV4CtrlIdx             the index of the 0:1 relation pointing to TcpIp_IpV4Ctrl
  Protocol                -
  TimeToLive              -
  TxDescriptorProtocol    -
  TypeOfService           -
  LocSock             
  PhysDestAddr            -
  TransferBlock           -
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_IpV4SocketDynType, TCPIP_VAR_NO_INIT) TcpIp_IpV4SocketDyn[7];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [UDP] */
  /*   ... */  /* [UDP] */
  /*     6 */  /* [UDP] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_LocalAddr
**********************************************************************************************************************/
/** 
  \var    TcpIp_LocalAddr
  \details
  Element            Description
  AssignmentState    -
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_LocalAddrType, TCPIP_VAR_NO_INIT) TcpIp_LocalAddr[4];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027] */
  /*     1 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/NEP_ADAS_RdrNet_CtrlRxMulticast_91909614] */
  /*     2 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/NEP_ANY_IP_c7cdbb5a] */
  /*     3 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/TcpIpV4LocalAddr_RDR_EthConnector1_fbdc15b4_Broadcast] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_MulticastAddrV4Requested
**********************************************************************************************************************/
/** 
  \var    TcpIp_MulticastAddrV4Requested
  \brief  -
  \details
  Element    Description
  NetAddr    -
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_MulticastAddrV4RequestedType, TCPIP_VAR_NO_INIT) TcpIp_MulticastAddrV4Requested[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/NEP_ADAS_RdrNet_CtrlRxMulticast_91909614, /ActiveEcuC/TcpIp/TcpIpConfig/cnctr_RDR_RdrNet_1bd20df5] */
  /*     1 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/NEP_ANY_IP_c7cdbb5a, /ActiveEcuC/TcpIp/TcpIpConfig/cnctr_RDR_RdrNet_1bd20df5] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_SocketDyn
**********************************************************************************************************************/
/** 
  \var    TcpIp_SocketDyn
  \brief  Generic (TCP/UDP) socket variables
  \details
  Element                 Description
  ListenActiveConnStat    Current state of the socket
  LocalAddrBindIdx        the index of the 0:1 relation pointing to TcpIp_LocalAddr
  SocketOwnerConfigIdx    the index of the 0:1 relation pointing to TcpIp_SocketOwnerConfig
  TxBufRequested          TX buffer request semaphore
  TxIpAddrIdx             Index of local IPxV address that is used for transmission
  LocSock                 IP address and port of the local host
  RemSock                 IP address and port of the remote host
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_SocketDynType, TCPIP_VAR_NO_INIT) TcpIp_SocketDyn[7];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [UDP] */
  /*   ... */  /* [UDP] */
  /*     6 */  /* [UDP] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_SocketUdpDyn
**********************************************************************************************************************/
/** 
  \var    TcpIp_SocketUdpDyn
  \brief  UDP socket specific variables
  \details
  Element                  Description
  TxReqElemListIdx         the index of the 0:1 relation pointing to TcpIp_TxReqElemList
  TxRetrQueueMaxNum        Maximum number of TX retry queue elements for the socket.
  UdpChecksum              Indicate of the checksum is active for this socket
  IpTxRequestDescriptor    TX request descriptor required for the IP layer
  TxReqIpBufPtr            Pointer to the provided TX buffer of the IP layer
  TxRetrQueue              TX retry queue
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_SocketUdpDynType, TCPIP_VAR_NO_INIT) TcpIp_SocketUdpDyn[7];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_StaticUnicastAddrV4Requested
**********************************************************************************************************************/
/** 
  \var    TcpIp_StaticUnicastAddrV4Requested
  \brief  -
  \details
  Element      Description
  DefGwAddr    -
  NetAddr      -
  NetMask      -
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_StaticUnicastAddrV4RequestedType, TCPIP_VAR_NO_INIT) TcpIp_StaticUnicastAddrV4Requested[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/TcpIp/TcpIpConfig/NEP_SRR_1_RdrNet_Unicast_48476027] */

#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_UdpTxRetryQueueElementChain
**********************************************************************************************************************/
/** 
  \var    TcpIp_UdpTxRetryQueueElementChain
  \brief  UDP TX retry queue element chain
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_DListNodeType, TCPIP_VAR_NO_INIT) TcpIp_UdpTxRetryQueueElementChain[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_UdpTxRetryQueueElements
**********************************************************************************************************************/
/** 
  \var    TcpIp_UdpTxRetryQueueElements
  \brief  UDP TX retry queue elements
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_Udp_RetryQueueElementType, TCPIP_VAR_NO_INIT) TcpIp_UdpTxRetryQueueElements[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_UdpTxRetryQueuePoolDesc
**********************************************************************************************************************/
/** 
  \var    TcpIp_UdpTxRetryQueuePoolDesc
  \brief  UDP TX retry queue element pool
*/ 
#define TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(TcpIp_DListDescType, TCPIP_VAR_NO_INIT) TcpIp_UdpTxRetryQueuePoolDesc[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  TcpIp_PCConfig
**********************************************************************************************************************/
/** 
  \var    TcpIp_PCConfig
  \details
  Element                               Description
  ArpConfig                             the pointer to TcpIp_ArpConfig
  ArpTableEntry                         the pointer to TcpIp_ArpTableEntry
  AutoIpConfig                          the pointer to TcpIp_AutoIpConfig
  DefaultMulticastAddrV4                the pointer to TcpIp_DefaultMulticastAddrV4
  DefaultUnicastAddrV4                  the pointer to TcpIp_DefaultUnicastAddrV4
  DhcpUserOption                        the pointer to TcpIp_DhcpUserOption
  DhcpUserOptionBuffer                  the pointer to TcpIp_DhcpUserOptionBuffer
  DhcpUserOptionDyn                     the pointer to TcpIp_DhcpUserOptionDyn
  DhcpV4ServerHostname                  the pointer to TcpIp_DhcpV4ServerHostname
  FragmentationConfig                   the pointer to TcpIp_FragmentationConfig
  GratuitousArp                         the pointer to TcpIp_GratuitousArp
  LlAddrState                           the pointer to TcpIp_LlAddrState
  MulticastAddrV4                       the pointer to TcpIp_MulticastAddrV4
  MulticastAddrV4Requested              the pointer to TcpIp_MulticastAddrV4Requested
  PhysAddrConfig                        the pointer to TcpIp_PhysAddrConfig
  ReassemblyBuffer                      the pointer to TcpIp_ReassemblyBuffer
  ReassemblyBufferDesc                  the pointer to TcpIp_ReassemblyBufferDesc
  ReassemblyBufferDescDyn               the pointer to TcpIp_ReassemblyBufferDescDyn
  StaticArpEntry                        the pointer to TcpIp_StaticArpEntry
  StaticArpTable                        the pointer to TcpIp_StaticArpTable
  StaticUnicastAddrV4Requested          the pointer to TcpIp_StaticUnicastAddrV4Requested
  TxReqElem                             the pointer to TcpIp_TxReqElem
  TxReqElemList                         the pointer to TcpIp_TxReqElemList
  TxReqElemListDyn                      the pointer to TcpIp_TxReqElemListDyn
  UdpTxRetryQueueElementChain           the pointer to TcpIp_UdpTxRetryQueueElementChain
  UdpTxRetryQueueElements               the pointer to TcpIp_UdpTxRetryQueueElements
  UdpTxRetryQueuePoolDesc               the pointer to TcpIp_UdpTxRetryQueuePoolDesc
  UnicastAddrV4                         the pointer to TcpIp_UnicastAddrV4
  SizeOfArpConfig                       the number of accomplishable value elements in TcpIp_ArpConfig
  SizeOfArpTableEntry                   the number of accomplishable value elements in TcpIp_ArpTableEntry
  SizeOfAutoIpConfig                    the number of accomplishable value elements in TcpIp_AutoIpConfig
  SizeOfDefaultMulticastAddrV4          the number of accomplishable value elements in TcpIp_DefaultMulticastAddrV4
  SizeOfDefaultUnicastAddrV4            the number of accomplishable value elements in TcpIp_DefaultUnicastAddrV4
  SizeOfDhcpUserOption                  the number of accomplishable value elements in TcpIp_DhcpUserOption
  SizeOfDhcpUserOptionBuffer            the number of accomplishable value elements in TcpIp_DhcpUserOptionBuffer
  SizeOfDhcpV4ServerHostname            the number of accomplishable value elements in TcpIp_DhcpV4ServerHostname
  SizeOfFragmentationConfig             the number of accomplishable value elements in TcpIp_FragmentationConfig
  SizeOfGratuitousArp                   the number of accomplishable value elements in TcpIp_GratuitousArp
  SizeOfLlAddrState                     the number of accomplishable value elements in TcpIp_LlAddrState
  SizeOfMulticastAddrV4                 the number of accomplishable value elements in TcpIp_MulticastAddrV4
  SizeOfPhysAddrConfig                  the number of accomplishable value elements in TcpIp_PhysAddrConfig
  SizeOfReassemblyBuffer                the number of accomplishable value elements in TcpIp_ReassemblyBuffer
  SizeOfReassemblyBufferDesc            the number of accomplishable value elements in TcpIp_ReassemblyBufferDesc
  SizeOfStaticArpEntry                  the number of accomplishable value elements in TcpIp_StaticArpEntry
  SizeOfStaticArpTable                  the number of accomplishable value elements in TcpIp_StaticArpTable
  SizeOfStaticUnicastAddrV4Requested    the number of accomplishable value elements in TcpIp_StaticUnicastAddrV4Requested
  SizeOfTxReqElem                       the number of accomplishable value elements in TcpIp_TxReqElem
  SizeOfTxReqElemList                   the number of accomplishable value elements in TcpIp_TxReqElemList
  SizeOfUdpTxRetryQueueElementChain     the number of accomplishable value elements in TcpIp_UdpTxRetryQueueElementChain
  SizeOfUdpTxRetryQueueElements         the number of accomplishable value elements in TcpIp_UdpTxRetryQueueElements
  SizeOfUdpTxRetryQueuePoolDesc         the number of accomplishable value elements in TcpIp_UdpTxRetryQueuePoolDesc
  SizeOfUnicastAddrV4                   the number of accomplishable value elements in TcpIp_UnicastAddrV4
*/ 
#define TCPIP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(TcpIp_PCConfigsType, TCPIP_CONST) TcpIp_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config] */
      TcpIp_ArpConfig                     /**< the pointer to TcpIp_ArpConfig */
    , TcpIp_ArpTableEntry                 /**< the pointer to TcpIp_ArpTableEntry */
    , NULL_PTR                            /**< the pointer to TcpIp_AutoIpConfig */
    , TcpIp_DefaultMulticastAddrV4        /**< the pointer to TcpIp_DefaultMulticastAddrV4 */
    , TcpIp_DefaultUnicastAddrV4          /**< the pointer to TcpIp_DefaultUnicastAddrV4 */
    , NULL_PTR                            /**< the pointer to TcpIp_DhcpUserOption */
    , NULL_PTR                            /**< the pointer to TcpIp_DhcpUserOptionBuffer */
    , NULL_PTR                            /**< the pointer to TcpIp_DhcpUserOptionDyn */
    , NULL_PTR                            /**< the pointer to TcpIp_DhcpV4ServerHostname */
    , NULL_PTR                            /**< the pointer to TcpIp_FragmentationConfig */
    , NULL_PTR                            /**< the pointer to TcpIp_GratuitousArp */
    , NULL_PTR                            /**< the pointer to TcpIp_LlAddrState */
    , TcpIp_MulticastAddrV4               /**< the pointer to TcpIp_MulticastAddrV4 */
    , TcpIp_MulticastAddrV4Requested      /**< the pointer to TcpIp_MulticastAddrV4Requested */
    , NULL_PTR                            /**< the pointer to TcpIp_PhysAddrConfig */
    , NULL_PTR                            /**< the pointer to TcpIp_ReassemblyBuffer */
    , NULL_PTR                            /**< the pointer to TcpIp_ReassemblyBufferDesc */
    , NULL_PTR                            /**< the pointer to TcpIp_ReassemblyBufferDescDyn */
    , NULL_PTR                            /**< the pointer to TcpIp_StaticArpEntry */
    , NULL_PTR                            /**< the pointer to TcpIp_StaticArpTable */
    , TcpIp_StaticUnicastAddrV4Requested  /**< the pointer to TcpIp_StaticUnicastAddrV4Requested */
    , NULL_PTR                            /**< the pointer to TcpIp_TxReqElem */
    , NULL_PTR                            /**< the pointer to TcpIp_TxReqElemList */
    , NULL_PTR                            /**< the pointer to TcpIp_TxReqElemListDyn */
    , TcpIp_UdpTxRetryQueueElementChain   /**< the pointer to TcpIp_UdpTxRetryQueueElementChain */
    , TcpIp_UdpTxRetryQueueElements       /**< the pointer to TcpIp_UdpTxRetryQueueElements */
    , TcpIp_UdpTxRetryQueuePoolDesc       /**< the pointer to TcpIp_UdpTxRetryQueuePoolDesc */
    , TcpIp_UnicastAddrV4                 /**< the pointer to TcpIp_UnicastAddrV4 */
    , 1u                                  /**< the number of elements in TcpIp_ArpConfig */
    , 10u                                 /**< the number of elements in TcpIp_ArpTableEntry */
    , 0u                                  /**< the number of elements in TcpIp_AutoIpConfig */
    , 2u                                  /**< the number of elements in TcpIp_DefaultMulticastAddrV4 */
    , 1u                                  /**< the number of elements in TcpIp_DefaultUnicastAddrV4 */
    , 0u                                  /**< the number of elements in TcpIp_DhcpUserOption */
    , 0u                                  /**< the number of elements in TcpIp_DhcpUserOptionBuffer */
    , 0u                                  /**< the number of elements in TcpIp_DhcpV4ServerHostname */
    , 0u                                  /**< the number of elements in TcpIp_FragmentationConfig */
    , 0u                                  /**< the number of elements in TcpIp_GratuitousArp */
    , 0u                                  /**< the number of elements in TcpIp_LlAddrState */
    , 2u                                  /**< the number of elements in TcpIp_MulticastAddrV4 */
    , 0u                                  /**< the number of elements in TcpIp_PhysAddrConfig */
    , 0u                                  /**< the number of elements in TcpIp_ReassemblyBuffer */
    , 0u                                  /**< the number of elements in TcpIp_ReassemblyBufferDesc */
    , 0u                                  /**< the number of elements in TcpIp_StaticArpEntry */
    , 0u                                  /**< the number of elements in TcpIp_StaticArpTable */
    , 1u                                  /**< the number of elements in TcpIp_StaticUnicastAddrV4Requested */
    , 0u                                  /**< the number of elements in TcpIp_TxReqElem */
    , 0u                                  /**< the number of elements in TcpIp_TxReqElemList */
    , 1u                                  /**< the number of elements in TcpIp_UdpTxRetryQueueElementChain */
    , 1u                                  /**< the number of elements in TcpIp_UdpTxRetryQueueElements */
    , 1u                                  /**< the number of elements in TcpIp_UdpTxRetryQueuePoolDesc */
    , 1u                                  /**< the number of elements in TcpIp_UnicastAddrV4 */
  }
};
#define TCPIP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/* PRQA L:OBJECT_SIZE */

#define TCPIP_START_SEC_CODE
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  TcpIp_MainFunction()
 *********************************************************************************************************************/
/*! \brief          The TcpIp_MainFunction handles the module internal state handling.
 *                  The TcpIp_MultiPartitionMainFunction will be called with the TCPIP_SINGLECORE_APPLID.
 *                  Calls all TcpIp-internal MainFunction functions.
 *                  This function has to be called cyclically.
 *  \details        This API is only available if multicore is not enabled.
 *  \pre            Init has to be called before.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, TCPIP_CODE) TcpIp_MainFunction(void)
{
  TcpIp_MultiPartitionMainFunction(TCPIP_SINGLECORE_APPLID);
}



/**********************************************************************************************************************
 *  USER FUNCTIONS
 *********************************************************************************************************************/
/* TcpIp_<Up>GetSocket ----------------------------------------------------- */
/* VCA NL RCH-21: VCA_TCPIP_INTERFACE_OF_EXTERNAL_MODULE_NOT_CALLED */ 
FUNC(Std_ReturnType, TCPIP_CODE) TcpIp_SoAdGetSocket(
    TcpIp_DomainType                                      Domain,
    TcpIp_ProtocolType                                    Protocol,
    P2VAR(TcpIp_SocketIdType, AUTOMATIC, TCPIP_APPL_DATA) SocketIdPtr)
{
    return TcpIp_GetSocketForUser(Domain, Protocol, SocketIdPtr, TcpIpConf_TcpIpSocketOwner_SoAd);  /* SBSW_TCPIP_NonNullPtrParameter */
}
 

#define TCPIP_STOP_SEC_CODE
#include "TcpIp_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA L:MACRO_LIMIT */

/* Justification for module-specific MISRA deviations:

   MD_TEST_Rule5.5_Wrapper: Identifier '%s' is also used as a macro name.
     Reason:     Redefinition allows execution of foreign code.
     Risk:       Code is more difficult to read and to debug.
     Prevention: Code is only present in test environment and not in productive builds.

   MD_CSL_Rule10.3_OldValidLib: The value of an expression shall not be assigned to an object with a narrower essential
                                type or of a different essential type category.
     Reason:     Other Autosar modules generates narrow datatypes for the symbolic name values.
     Risk:       None.
     Prevention: Other modules need to change their SNV generation

   MD_TCPIP_CERT-DCL40-C_0789: Identifier matches other identifier(s) (e.g. '%s') in first 63 characters.
     Reason:     The rule 0789 checks if all internal identifiers are different within the first 63 characters.
     Risk:       A compiler might not correctly pre-process the software what might result in incorrect code.
     Prevention: Each delivery is integrated and tested on the real target system. In addition, preprocessors and
                 compilers used in current MICROSAR projects are not expected to suffer from this (historic) limitation.
                 Compiler selection and validation is done by ECU supplier.

   MD_TCPIP_CERT-ARR30-C_2842: Apparent: Dereference of an invalid pointer value.
     Reason:     A function parameter is used to access an array element. The parameter is passed by an internal TcpIp
                 function that ensures that the parameter is in a valid range. This is ensured by SafeBSW measures.
                 The parameter cannot be written by other BSW module or the application.
     Risk:       None.
     Prevention: Covered by code review.
 
*/
/**********************************************************************************************************************
 *  END OF FILE: TcpIp_Lcfg.c
 *********************************************************************************************************************/
