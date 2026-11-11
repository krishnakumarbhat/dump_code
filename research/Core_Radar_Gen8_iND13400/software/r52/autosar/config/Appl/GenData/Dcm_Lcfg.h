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
 *            Module: Dcm
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Dcm_Lcfg.h
 *   Generation Time: 2026-08-05 12:44:48
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


#if !defined(DCM_LCFG_H)
# define DCM_LCFG_H

# ifdef __PRQA__ /* COV_DCM_PRQA_UNREACHABLE XF */
                                                                                                                                                     /* PRQA S 1711 EOF */ /* MD_MSR_Rule5.1 */
                                                                                                                                                     /* PRQA S 1753 EOF */ /* MD_Dcm_Callout */
# endif
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Dem.h"
# include "Dem_Dcm.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/*! Implementation version */
# define DCM_LCFG_MAJOR_VERSION                                                23u
# define DCM_LCFG_MINOR_VERSION                                                 9u
# define DCM_LCFG_PATCH_VERSION                                                 0u

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# if (DCM_AUTHMGR_SUPPORT_ENABLED == STD_ON)
/*! Session timer defines */
#define DCM_AUTHMGR_NUM_DELAY_TIMERS                                 DCM_AUTHMGR_NUM_AUTH_CONNECTIONS /* Have as many soft timers as there are connections */

/*! Authentication white list support */
#if (DCM_AUTHMGR_WHITELIST_SERVICES_ENABLED == STD_ON) ||\
    (DCM_AUTHMGR_WHITELIST_DID_ENABLED == STD_ON) ||\
    (DCM_AUTHMGR_WHITELIST_RID_ENABLED == STD_ON) ||\
    (DCM_AUTHMGR_WHITELIST_MEM_ENABLED == STD_ON)
# define DCM_AUTHMGR_WHITELISTS_ENABLED                              STD_ON
#else
# define DCM_AUTHMGR_WHITELISTS_ENABLED                              STD_OFF
#endif
# endif /* (DCM_AUTHMGR_SUPPORT_ENABLED == STD_ON) */

/*! Direct variant access */
# define Dcm_CfgConfig_RDR_01                                                  (Dcm_CfgConfigsRoot.Config_RDR_01)
/*! Direct variant access */
# define Dcm_CfgConfig_RDR_02                                                  (Dcm_CfgConfigsRoot.Config_RDR_01)
/*! Direct variant access */
# define Dcm_CfgConfig_RDR_03                                                  (Dcm_CfgConfigsRoot.Config_RDR_01)
/*! Direct variant access */
# define Dcm_CfgConfig_RDR_04                                                  (Dcm_CfgConfigsRoot.Config_RDR_01)
/*! Direct variant access */
# define Dcm_CfgConfig_RDR_05                                                  (Dcm_CfgConfigsRoot.Config_RDR_01)
/*! Direct variant access */
# define Dcm_CfgConfig_RDR_06                                                  (Dcm_CfgConfigsRoot.Config_RDR_01)
/*! Direct variant access */
# define Dcm_CfgConfig_RDR_07                                                  (Dcm_CfgConfigsRoot.Config_RDR_01)
/*! Direct variant access */
# define Dcm_CfgConfig_RDR_08                                                  (Dcm_CfgConfigsRoot.Config_RDR_01)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
# define Dcm_CfgWrapStatePreconditions(index)                                  (&Dcm_CfgStatePreconditions[(index)])                                 /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define Dcm_CfgWrapStateSessionInfo(index)                                    (&Dcm_CfgStateSessionInfo[(index)])                                   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define Dcm_CfgWrapStateSecurityInfo(index)                                   (&Dcm_CfgStateSecurityInfo[(index)])                                  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define Dcm_CfgWrapDidMgrDidLookUpTable(index)                                (Dcm_CfgDidMgrDidLookUpTable[(index)])                                /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define Dcm_CfgWrapDidMgrDidInfo(index)                                       (&Dcm_CfgDidMgrDidInfo[(index)])                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define Dcm_CfgWrapDidMgrDidOpInfo(index)                                     (&Dcm_CfgDidMgrDidOpInfo[(index)])                                    /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define Dcm_CfgWrapDidMgrDidOpClassInfo(index)                                (&Dcm_CfgDidMgrDidOpClassInfo[(index)])                               /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define Dcm_CfgWrapDidMgrSignalOpClassInfo(index)                             (&Dcm_CfgDidMgrSignalOpClassInfo[(index)])                            /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define Dcm_CfgWrapRidMgrRidLookUpTable(index)                                (Dcm_CfgRidMgrRidLookUpTable[(index)])                                /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define Dcm_CfgWrapRidMgrRidInfo(index)                                       (Dcm_CfgRidMgrRidInfo[(index)])                                       /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define Dcm_CfgWrapRidMgrOpInfo(index)                                        (Dcm_CfgRidMgrOpInfo[(index)])                                        /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define Dcm_CfgWrapDiagServiceInfo(index)                                     (&Dcm_CfgDiagServiceInfo[(index)])                                    /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define Dcm_CfgWrapDiagSvcIdExecPrecondTable(index)                           (Dcm_CfgDiagSvcIdExecPrecondTable[(index)])                           /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define Dcm_CfgWrapSvc10SubFuncLookUpTable(index)                             (Dcm_CfgSvc10SubFuncLookUpTable[(index)])                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define Dcm_CfgWrapSvc10SubFuncInfo(index)                                    (&Dcm_CfgSvc10SubFuncInfo[(index)])                                   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define Dcm_CfgWrapSvc11SubFuncInfo(index)                                    (&Dcm_CfgSvc11SubFuncInfo[(index)])                                   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define Dcm_CfgWrapSvc19SubFuncInfo(index)                                    (&Dcm_CfgSvc19SubFuncInfo[(index)])                                   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define Dcm_CfgWrapSvc28SubFuncInfo(index)                                    (&Dcm_CfgSvc28SubFuncInfo[(index)])                                   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define Dcm_CfgWrapSvc28SubNetIdMap(index)                                    (Dcm_CfgSvc28SubNetIdMap[(index)])                                    /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define Dcm_CfgWrapSvc85SubFuncInfo(index)                                    (&Dcm_CfgSvc85SubFuncInfo[(index)])                                   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*! Mode-rule handler function prototype */
typedef P2FUNC(boolean, DCM_CODE, Dcm_ModeRuleFuncType) (Dcm_NegativeResponseCodePtrType errorCode /* OUT: The result NRC */);

/*! Depends on the largest configured buffer size */
typedef uint8 Dcm_CfgNetBufferSizeMemType;
/*! Depends on the largest configured buffer size */
typedef uint8_least Dcm_CfgNetBufferSizeOptType;
/*! Zero based reference to an authentication info entry */
typedef uint8 Dcm_CfgNetAuthInfoRefMemType;
/*! Zero based reference to an authentication info entry */
typedef uint8_least Dcm_CfgNetAuthInfoRefOptType;
#if (DCM_NET_PROTOCOL_NOTIFICATION_ENABLED == STD_ON)
/*! Function pointer prototype for a protocol activation notification */
# if (DCM_DCM_AR_VERSION >= DCM_DCM_AR_VERSION_450)
typedef P2FUNC(Std_ReturnType, DCM_CODE, Dcm_NetProtocolIndicationFuncType) (Dcm_ProtocolType newProtocol /* IN: new ProtocolId */
                                                                            ,uint16 connectionId /* IN: Unique connection identifier */
                                                                            ,uint16 srcAddr /* IN: Tester SourceAddress */);
# else
typedef P2FUNC(Std_ReturnType, DCM_CODE, Dcm_NetProtocolIndicationFuncType) (Dcm_ProtocolType newProtocol); /* IN: new ProtocolId */
# endif

/*! Diagnostic protocol related notification functions */
struct DCM_CFGNETPROTOCOLNOTIFICATIONINFOTYPE_TAG
{
  Dcm_NetProtocolIndicationFuncType    StartFunc;  /*!< Pointer to a function of kind Xxx_StartProtocol() */
};
typedef struct DCM_CFGNETPROTOCOLNOTIFICATIONINFOTYPE_TAG Dcm_CfgNetProtocolNotificationInfoType;
#endif
/*! Zero based reference to a USDT buffer configuration entry (0..31) */
typedef uint8        Dcm_CfgNetBufferRefMemType;
typedef uint8_least  Dcm_CfgNetBufferRefOptType;

/*! Zero based reference to a ComM channel map entry (0..255) */
typedef uint8        Dcm_CfgNetNetIdRefMemType;
typedef uint8_least  Dcm_CfgNetNetIdRefOptType;

/*! Zero based reference to a UUDT message transport object (0..255) */
typedef uint8        Dcm_CfgNetPTxObjHandleMemType;
typedef uint8_least  Dcm_CfgNetPTxObjHandleOptType;

/*! Diagnostic protocol priority (0..255) */
typedef uint8        Dcm_CfgNetProtPrioType;

/*! Diagnostic protocol maximum length (0..65535) */
typedef uint16       Dcm_CfgNetProtLengthType;

/*! Zero based reference to a UUDT message DcmTxPduId configuration entry (0..255) */
typedef uint8        Dcm_CfgNetPerTxPduIdRefMemType;
typedef uint8_least  Dcm_CfgNetPerTxPduIdRefOptType;

/*! Diagnostic client connection properties (Valid values: DCM_NET_CONN_PROP_*) */
typedef uint8        Dcm_CfgNetConnPropertiesType;

/*! Diagnostic client connection UUDT frame size (0..4294967295) */
typedef PduLengthType Dcm_UudtFrameSizeType;

/*! Configuration of a USDT buffer */
struct DCM_CFGNETBUFFERINFOTYPE_TAG
{
  Dcm_PbConstMsgType            BufferPtr;  /*!< Pointer to a USDT buffer */
  Dcm_CfgNetBufferSizeMemType   Size;       /*!< Size of this specific USDT buffer */
};
typedef struct DCM_CFGNETBUFFERINFOTYPE_TAG Dcm_CfgNetBufferInfoType;
typedef P2CONST(Dcm_CfgNetBufferInfoType, TYPEDEF, DCM_CONST_PBCFG) Dcm_PbCfgNetBufferInfoPtrType;

/*! Configuration of a DcmRxPduId */
struct DCM_CFGNETRXPDUINFOTYPE_TAG
{
  boolean                   IsFuncReq;  /*!< Functional request message: FALSE = physical, TRUE = functional */
  Dcm_NetConnRefMemType     ConnRef;    /*!< Reference to Dcm_CfgNetConnectionInfo[] entry */
};
typedef struct DCM_CFGNETRXPDUINFOTYPE_TAG Dcm_CfgNetRxPduInfoType;

/*! Configuration of a diagnostic client connection */
struct DCM_CFGNETCONNECTIONTYPE_TAG
{
  uint16                          ConnectionId;           /*!< Unique identifier of the tester which uses this connection */
  uint16                          ClientSrcAddr;          /*!< Diagnostic client's unique source address (identifier) */
#if (DCM_NET_PERIODIC_TX_ENABLED == STD_ON)
  Dcm_TmrTimerCntrMemType         PeriodicTxConfTimeout;  /*!< Diagnostic client specific periodic message transmission confirmation timeout (0 - if no periodic message used) */
  Dcm_UudtFrameSizeType           UudtFrameSize;          /*!< Diagnostic client specific UUDT frame size */
#endif
  PduIdType                       TxPduIdMain;            /*!< PduR's PduId of the main diagnostic response */
  Dcm_CfgNetNetIdRefMemType       NetworkIdRef;           /*!< Reference to Dcm_CfgNetConnComMChannelMap[] entry */
  Dcm_NetProtRefMemType           ProtRef;                /*!< Reference to Dcm_PbCfgNetProtocolInfo[] entry */
#if (DCM_NET_PERIODIC_TX_ENABLED == STD_ON)
  Dcm_CfgNetPerTxPduIdRefMemType  PeriodicTxRef;          /*!< Reference to Dcm_PbCfgNetPerTxPduIdInfo[] entry */
  Dcm_CfgNetPTxObjHandleMemType   NumPeriodicTxPduIds;    /*!< Number of periodic messages of the diagnostic client (0 = none) */
#endif
  uint16                          EcuAddress;             /*!< ECU network address */
  Dcm_CfgNetConnPropertiesType    Properties;             /*!< Diagnostic client specific properties (Any combination of DCM_NET_CONN_PROP_*) */
  uint8                           MetaDataLength;         /*!< Meta Data length. Has a value of 4 for generic connections and 0 for specific connections. */
#if (DCM_STATE_AUTHENTICATION_ENABLED == STD_ON)
  Dcm_CfgNetAuthInfoRefMemType    AuthInfoRef;            /*!< Unique handle of an authenticatable connection and reference to Dcm_CfgAuthMgrNetConnInfo[] if available */
#endif
};
typedef struct DCM_CFGNETCONNECTIONTYPE_TAG Dcm_CfgNetConnectionInfoType;
typedef P2CONST(Dcm_CfgNetConnectionInfoType, TYPEDEF, DCM_VAR_NOINIT) Dcm_CfgNetConnectionInfoConstPtrType;

/*! Configuration of a diagnostic client protocol */
struct DCM_CFGNETPROTOCOLTYPE_TAG
{
  Dcm_DiagP2TimingsType       SrvAdjTime;         /*!< The P2 times to be used for all diagnostic clients associated with this diagnostic protocol */
  Dcm_CfgNetProtLengthType    MaxLength;          /*!< Maximum allowed request/response length for all connections within this diagnostic protocol */
  Dcm_ProtocolType            Id;                 /*!< The diagnostic protocol name (e.g. UDS_ON_CAN) */
  Dcm_CfgNetProtPrioType      Priority;           /*!< The priority of all connections associated with this diagnostic protocol (0 - highest, 255 - lowest) */
  boolean                     HasRespPendOnBoot;  /*!< Specifies whether RCR-RP shall be sent prior jump to the boot-loader (TRUE - do send RCR-RP prior jump to FBL, FALSE - do not send) */
  Dcm_CfgNetBufferRefMemType  RxTxBufferRef;      /*!< Reference to Dcm_PbCfgNetBufferInfo[] entry */
  uint8                       DemClientId;        /*!< The DEM client ID */
  uint8                       ThreadId;           /*!< The active Thread ID */
#if (DCM_STATE_PROTOCOL_ENABLED == STD_ON)
  uint8                       NetStateRef;        /*!< The bit position in the exec precond mask for protocols */
#endif
};
typedef struct DCM_CFGNETPROTOCOLTYPE_TAG Dcm_CfgNetProtocolInfoType;
typedef P2CONST(Dcm_CfgNetProtocolInfoType, TYPEDEF, DCM_VAR_NOINIT) Dcm_CfgNetProtocolInfoConstPtrType;
typedef uint8   Dcm_NetTransportObjectStateType;
typedef uint16  Dcm_NetTransportObjectFlagType;
typedef uint8   Dcm_NetResponseType;
typedef uint8   Dcm_NetComMStateType;
typedef boolean Dcm_NetComMAvailabilityType;

/*! Transport object control data */
struct DCM_NETTRANSPORTOBJECTTYPE_TAG
{
  Dcm_ReadOnlyMsgType             RxData;                                  /*!< Pointer to the buffer to store the request data (can be the main buffer or an additional buffer) */
  Dcm_NetTransportObjectFlagType  Flags;                                   /*!< Control flags of a transport object (Multiple combination of DCM_NET_TOBJ_FLAG_*) */
  Dcm_CfgNetBufferSizeMemType     RxLength;                                /*!< The diagnostic request length */
  Dcm_CfgNetBufferSizeMemType     BuffPos;                                 /*!< Keeps track of where to copy the next received diagnostic message data portion */
  PduIdType                       RxPduId;                                 /*!< DcmRxPduId used to allocate the transport object */
  Dcm_NetResponseType             ResType;                                 /*!< The diagnostic response type (e.g. RCR-RP, final (not-)paged etc.) */
  Dcm_NetConnRefMemType           ConnHdl;                                 /*!< Reference to Dcm_PbCfgNetConnectionInfo[] entry */
  Dcm_CfgNetBufferRefMemType      BufferHdl;                               /*!< Reference to Dcm_PbRamNetBufferContext[] entry */
  volatile Dcm_NetTransportObjectStateType State;                          /*!< State of the transport object (Valid values: DCM_NET_TOBJ_STATE_*) */
  Dcm_MsgItemType                 AddBuffer[DCM_NET_TOBJ_ADDBUFFER_SIZE];  /*!< Temporary buffer for NRC 0x78 and 0x21 responses and 0x3E 0x80 functional requests (optional specific cause code) */
  PduInfoType                     BuffInfo;                                /*!< PduR transmission data information exchange */
  uint16                          ClientSrcAddr;                           /*!< Client source address, static or according to meta data */
};
typedef struct DCM_NETTRANSPORTOBJECTTYPE_TAG Dcm_NetTransportObjectType;
typedef P2VAR(Dcm_NetTransportObjectType, TYPEDEF, DCM_VAR_NOINIT) Dcm_NetTransportObjectPtrType;
typedef P2CONST(Dcm_NetTransportObjectType, TYPEDEF, DCM_VAR_NOINIT) Dcm_NetTransportObjectConstPtrType;

/*! ComM channel related control information */
struct DCM_NETCOMMCONTEXT_TAG
{
  NetworkHandleType                    Channel;             /*!< The corresponding ComM channel of this context */
  volatile Dcm_NetComMStateType        ComState;            /*!< The current state of the ComM channel (FullCom/SilentCom/NoCom) */
  volatile Dcm_NetComMAvailabilityType ComAvailability;     /*!< The current availability of the ComM channel (Ready/NotReady) */
  volatile Dcm_NetConnRefMemType       RegisteredNetworks;  /*!< Number of active USDT diagnostic client connections on certain ComM channel */
};
typedef struct DCM_NETCOMMCONTEXT_TAG Dcm_NetComMContextType;
typedef P2VAR(Dcm_NetComMContextType, TYPEDEF, DCM_VAR_NOINIT) Dcm_NetComMContextPtrType;
typedef P2CONST(Dcm_NetComMContextType, TYPEDEF, DCM_VAR_NOINIT) Dcm_NetComMContextConstPtrType;

/*! List of ComM channel related control information */
struct DCM_NETCOMMCONTEXTLIST_TAG
{
  Dcm_NetComMContextConstPtrType ComMContext;
  NetworkHandleType              Size;
};
typedef struct DCM_NETCOMMCONTEXTLIST_TAG Dcm_NetComMContextListType;

#if (DCM_NET_PERIODIC_TX_ENABLED == STD_ON)
typedef uint8       Dcm_NetPerTxObjStateMemType;
typedef uint8_least Dcm_NetPerTxObjStateOptType;

/*! Periodic message (UUDT) transport object control data */
struct DCM_NETPERIODICTXOBJECTTYPE_TAG
{
  PduInfoType                          TxPduInfo;                               /*!< PduR transmission data information exchange */
  volatile Dcm_TmrTimerCntrMemType     Timer;                                   /*!< Message transmission deadline monitor (can be changed within an ISR) */
  Dcm_MsgItemType                      TxBuffer[DCM_NET_PERIODIC_BUFFER_SIZE];  /*!< Periodic message data buffer */
  volatile Dcm_NetPerTxObjStateMemType State;                                   /*!< Periodic message state (Free, Reserved, Queued, Sent) */
  uint16                               Did;                                     /*!< The periodic Did assigned with the message */
};
typedef struct DCM_NETPERIODICTXOBJECTTYPE_TAG Dcm_NetPeriodicTxObjectType;
typedef P2VAR(Dcm_NetPeriodicTxObjectType, TYPEDEF, DCM_RAM_PBCFG) Dcm_NetPeriodicTxObjectPtrType;

/*! List of periodic message (UUDT) transport object control data */
struct DCM_NETPERIODICTXOBJECTLISTTYPE_TAG
{
  Dcm_NetPeriodicTxObjectPtrType PeriodicTxObj;
  Dcm_CfgNetPTxObjHandleMemType  Size;
};
typedef struct DCM_NETPERIODICTXOBJECTLISTTYPE_TAG Dcm_NetPeriodicTxObjectListType;
#endif
#if (DCM_VARMGR_MULTI_COM_ENABLED == STD_ON)
/*! Network sub-component post-build-variant (selectable/loadable) related configuration data */
struct DCM_NETVARIANTINFOTYPE_TAG
{
  P2CONST(Dcm_CfgNetRxPduInfoType, AUTOMATIC, DCM_PBCFG)       RxPduIdTable;              /*!< Pointer to the DcmRxPdus' configuration */
  P2CONST(Dcm_CfgNetConnectionInfoType, AUTOMATIC, DCM_PBCFG)  ConnectionTable;           /*!< Pointer to the diagnostic clients' connections */
  P2CONST(Dcm_CfgNetProtocolInfoType, AUTOMATIC, DCM_PBCFG)    ProtocolTable;             /*!< Pointer to the diagnostic protocols' configuration */
  P2CONST(Dcm_CfgNetNetIdRefMemType, AUTOMATIC, DCM_PBCFG)     NetConnComMChannelMap;     /*!< Pointer to the diagnostic client related ComM channel map */
  P2CONST(NetworkHandleType, AUTOMATIC, DCM_PBCFG)             NetworkHandleLookUpTable;  /*!< Pointer to the ComM channel look-up table */
  P2CONST(NetworkHandleType, AUTOMATIC, DCM_PBCFG)             NetAllComMChannelMap;      /*!< Pointer to the map of all related to DCM ComM channels */
# if (DCM_NET_COMCTRL_ALLNET_SUPPORT_ENABLED == STD_ON)
  P2CONST(NetworkHandleType, AUTOMATIC, DCM_PBCFG)             ComCtrlChannelListAll;     /*!< Pointer to the list of all ComM channels to be used for SID 0x28 with SubNetType=AllChannels */
# endif

  P2CONST(Dcm_NetConnRefMemType, AUTOMATIC, DCM_PBCFG)         TxPduIdMap;                /*!< Pointer to the USDT DcmTxPduId to client connection map */
  P2CONST(Dcm_CfgNetPTxObjHandleMemType, AUTOMATIC, DCM_PBCFG) PerTxPduIdMap;             /*!< Pointer to the UUDT DcmTxPduId to periodic message transport object map */
  P2CONST(PduIdType, AUTOMATIC, DCM_PBCFG)                     PerTxPduIdTable;           /*!< Pointer to the list of all UUDT DcmTxPduIds */
# if (DCM_NET_MONITOR_FOREIGN_N_TA_ENABLED == STD_ON)
  P2CONST(PduIdType, AUTOMATIC, DCM_PBCFG)                     CanTp2DcmRxPduIdMap;       /*!< Pointer to the CanTpRxPduId to DcmRxPduId map */
# endif

  PduIdType                     NumRxPduIds;         /*!< Number of DcmRxPduIds */
  PduIdType                     NumTxPduIds;         /*!< Number of DcmTxPduIds */
# if (DCM_NET_MONITOR_FOREIGN_N_TA_ENABLED == STD_ON)
  PduIdType                     CanTpRxPduIdMin;     /*!< Lowest CanTpRxPduId */
  PduIdType                     CanTpRxPduIdMax;     /*!< Highest CanTpRxPduId */
  PduIdType                     NumCanTpRxPduIds;    /*!< Number of used CanTpRcPduIds (0 - none are used, >0 - at least one used) */
# endif
  NetworkHandleType             NumComMChannels;     /*!< Number of all ComM channels related to diagnostic clients */
  NetworkHandleType             NumAllComMChannels;  /*!< Number of all ComM channels managed by DCM */
  Dcm_CfgNetPTxObjHandleMemType NumPerTxObjects;     /*!< Maximum number of periodic message transport objects over all diagnostic client connections */
  Dcm_NetConnRefMemType         NumConnections;      /*!< Number of diagnostic client connections */
  Dcm_NetProtRefMemType         NumProtocols;        /*!< Number of diagnostic protocols */
  Dcm_CfgNetBufferRefMemType    NumBuffers;          /*!< Number of USDT buffers */
};
typedef struct DCM_NETVARIANTINFOTYPE_TAG Dcm_CfgNetVariantInfoType;
#endif

#if (DCM_VARMGR_MODE_POSTBUILD_LOAD_ENABLED == STD_ON)
/*! Network sub-component post-build-loadable reallocatable shared RAM data */
struct DCM_NETRAMVARIANTINFOTYPE_TAG
{
# if (DCM_NET_PERIODIC_TX_ENABLED == STD_ON)
  P2VAR(Dcm_NetPeriodicTxObjectType, AUTOMATIC, DCM_RAM_PBCFG) PeriodicTxObjects;  /*!< Pointer to the pool of periodic (UUDT) message transport objects */
# endif
  P2VAR(Dcm_NetComMContextType, AUTOMATIC, DCM_RAM_PBCFG)      ComMContexts;       /*!< Pointer to the pool of ComM channels' control states */
  P2VAR(Dcm_NetTransportObjectType, AUTOMATIC, DCM_RAM_PBCFG)  TranspObjects;      /*!< Pointer to the pool of USDT message transport objects */
  P2VAR(Dcm_NetBufferContextType, AUTOMATIC, DCM_RAM_PBCFG)    BufferContexts;     /*!< Pointer to the pool of USDT message buffers' control states */
# if (DCM_MODE_COMMCTRL_ENABLED == STD_ON)
  P2VAR(Dcm_CommunicationModeType, AUTOMATIC, DCM_RAM_PBCFG)   ComCtrlChannels;    /*!< Pointer to the pool of ComM channels' communication state */
# endif
};
typedef struct DCM_NETRAMVARIANTINFOTYPE_TAG Dcm_CfgNetRamVariantInfoType;

/*! Network sub-component post-build-loadable reallocatable shared configuration data */
struct DCM_NETROMVARIANTINFOTYPE_TAG
{
  P2CONST(Dcm_CfgNetBufferInfoType, AUTOMATIC, DCM_PBCFG)  BufferInfo;  /*!< Pointer to the USDT buffer configuration */
};
typedef struct DCM_NETROMVARIANTINFOTYPE_TAG Dcm_CfgNetRomVariantInfoType;
#endif
/*! Depends on the mode rule table size */
typedef uint8 Dcm_CfgModeMgrRuleRefMemType;
/*! Depends on the mode rule table size */
typedef uint8_least Dcm_CfgModeMgrRuleRefOptType;
/*! Depends on the state group with largest number of states */
typedef uint8 Dcm_CfgStateGroupMemType;
/*! Depends on the state group with largest number of states */
typedef uint8_least Dcm_CfgStateGroupOptType;
/*! Depends on the total number of protocol states */
typedef uint8 Dcm_CfgStateProtocolMemType;
/*! Depends on the total number of protocol states */
typedef uint8_least Dcm_CfgStateProtocolOptType;
/*! Depends on the total number of diagnostic service state/mode filters */
typedef uint8 Dcm_CfgStateRefMemType;
/*! Depends on the total number of diagnostic service state/mode filters */
typedef uint8_least Dcm_CfgStateRefOptType;
/*! Depends on the total number of security fixed byte values in non-default security levels */
typedef uint8 Dcm_CfgStateSecurityFixedByteRefMemType;
/*! Depends on the total number of security fixed byte values in non-default security levels */
typedef uint8_least Dcm_CfgStateSecurityFixedByteRefOptType;
/*! Depends on the how many Fixed byte sets are configured per a security level */
typedef uint8 Dcm_CfgStateVsgSecurityFixedByteInfoRefMemType;
/*! Depends on the how many Fixed byte sets are configured per a security level */
typedef uint8_least Dcm_CfgStateVsgSecurityFixedByteInfoRefOptType;
/*! A diagnostic entity diagnostic state related execution pre-conditions package */
struct DCM_CFGSTATEPRECONDITIONTYPE_TAG
{
  Dcm_CfgStateGroupMemType Session;   /*!< Diagnostic session pre-condition(s) (Bitmap) */
#if (DCM_STATE_SECURITY_ENABLED == STD_ON)
  Dcm_CfgStateGroupMemType Security;  /*!< Security access pre-condition(s) (Bitmap) */
#endif
#if (DCM_STATE_AUTHENTICATION_ENABLED == STD_ON)
  Dcm_CfgStateGroupMemType AuthRole;  /*!< Authentication role pre-condition(s) (Bitmap) */
#endif
};
typedef struct DCM_CFGSTATEPRECONDITIONTYPE_TAG Dcm_CfgStateDiagStateInfoType;

/*! A diagnostic entity complete execution pre-conditions package */
struct DCM_CFGSTATEPRECONDITIONINFOTYPE_TAG
{
#if (DCM_STATE_PROTOCOL_ENABLED == STD_ON)
  Dcm_CfgStateProtocolMemType          ProtocolStates;  /*!< A protocol related pre-condition(s) (Bitmap) */
#endif
#if (DCM_MODEMGR_CHECK_SUPPORT_ENABLED == STD_ON)
  Dcm_CfgModeMgrRuleRefMemType         ModeRuleRef;     /*!< Reference to Dcm_CfgModeMgrRules[] entry */
#endif
  Dcm_CfgStateDiagStateInfoType        States;          /*!< A diagnostic state related pre-condition package */
};
typedef struct DCM_CFGSTATEPRECONDITIONINFOTYPE_TAG Dcm_CfgStatePreconditionInfoType;

/*! Diagnostic session configuration package */
struct DCM_CFGSTATESESSIONINFOTYPE_TAG
{
  Dcm_DiagP2TimingsType                     P2ServerTime;   /*!< Diagnostic session specific P2 timings */
  Rte_ModeType_DcmDiagnosticSessionControl  Mode;           /*!< The diagnostic session state related mode of the mode declaration group DcmDiagnosticSession */
  uint8                                     Value;          /*!< The diagnostic session state ID (i.e. the sub-function of SID 0x10) */
};
typedef struct DCM_CFGSTATESESSIONINFOTYPE_TAG Dcm_CfgStateSessionInfoType;

/*! Security access level configuration package */
struct DCM_CFGSTATESECURITYINFOTYPE_TAG
{
  Dcm_TmrTimerCntrMemType          DelayTimeInvKey;    /*!< The delay time in case of received invalid key (always >0: specific time) */
#if (DCM_STATE_SEC_DELAY_ON_BOOT_ENABLED == STD_ON)
  Dcm_TmrTimerCntrMemType          DelayTimeOnBoot;    /*!< The delay time each time the ECU (re-)starts (i.e. after reset or power down) */
#endif
  Dcm_TmrTimerCntrMemType          ReloadTime;         /*!< The delay time to be used when a Xxx_GetAttemptCounter API fails to report the stored attempt counter value (0: infinity/no delay (see ReloadOnZeroDelay), >0: specific time) */
  boolean                          ReloadOnZeroDelay;  /*!< Determines the meaning of the "ReloadTime == 0": TRUE - the delay time is infinity, FALSE - no delay time required */
  uint8                            NumAttempts;        /*!< The maximum number of attempts to send a valid key */
  uint8                            Value;              /*!< The security access level state ID (i.e. equals to "(seed/key sub-function ID + 1) / 2" */
#if (DCM_MODE_SECURITY_ACCESS_ENABLED == STD_ON)
  Rte_ModeType_DcmSecurityAccess   Mode;               /*!< The security access level state related mode of the mode declaration group DcmSecurityAccess */
#endif
};
typedef struct DCM_CFGSTATESECURITYINFOTYPE_TAG Dcm_CfgStateSecurityInfoType;

#if (DCM_STATE_SESSION_NOTIFICATION_ENABLED == STD_ON) ||\
    (DCM_STATE_SECURITY_NOTIFICATION_ENABLED == STD_ON)
/*! Function pointer prototype for a diagnostic state transition notification */
typedef P2FUNC(void, DCM_CALLOUT_CODE, Dcm_StateChangeIndicationFuncType)(uint8 formerStateId /* IN: former state ID */
                                                                         ,uint8 newStateId /* IN: new state ID */);

/*! Diagnostic state transition notification item configuration package */
struct DCM_CFGSTATENOTIFICATIONINFOTYPE_TAG
{
  Dcm_StateChangeIndicationFuncType      OnChgFunc; /*!< Pointer to a function of kind <UserDefined function per ECUC>() */
};
typedef struct DCM_CFGSTATENOTIFICATIONINFOTYPE_TAG Dcm_CfgStateNotificationInfoType;
typedef P2CONST(Dcm_CfgStateNotificationInfoType, TYPEDEF, DCM_CONST) Dcm_CfgStateNotificationInfoPtrType;
#endif
/*! Depends on the size of Dcm_CfgDidMgrDidOpInfo table */
typedef uint8 Dcm_CfgDidMgrOpHandleMemType;
/*! Depends on the size of Dcm_CfgDidMgrDidOpInfo table */
typedef uint8_least Dcm_CfgDidMgrOpHandleOptType;
/*! Depends on the size of Dcm_CfgDidMgrDidOpClassInfo table */
typedef uint8 Dcm_CfgDidMgrDidOpClassHandleMemType;
/*! Depends on the size of Dcm_CfgDidMgrDidOpClassInfo table */
typedef uint8_least Dcm_CfgDidMgrDidOpClassHandleOptType;
/*! Depends on the size of Dcm_CfgDidMgrDidInfo table */
typedef uint8 Dcm_CfgDidMgrDidInfoRefType;
/*! Depends on the size of Dcm_CfgDidMgrDidOpInfo table */
typedef uint8 Dcm_CfgDidMgrAbstractOpRefType;
/*! Depends on the size of the table Dcm_CfgDidMgrOpInfoIoControl */
typedef uint8 Dcm_CfgDidMgrCombinedOpRefType;
/*! Depends on the number of the defined dynamic DIDs */
typedef uint8 Dcm_CfgDidMgrDynDidHandleMemType;
/*! Depends on the number of the defined dynamic DIDs */
typedef uint8_least Dcm_CfgDidMgrDynDidHandleOptType;
/*! Depends on the summation of max number of elements (static DIDs) of all defined dynamic DIDs */
typedef uint8 Dcm_CfgDidMgrDynDidSrcItemIdxMemType;
/*! Depends on the summation of max number of elements (static DIDs) of all defined dynamic DIDs */
typedef uint8_least Dcm_CfgDidMgrDynDidSrcItemIdxOptType;
/*! Depends on the number of IO DIDs */
typedef uint8 Dcm_CfgDidMgrIoDidHandleMemType;
/*! Depends on the number of IO DIDs */
typedef uint8_least Dcm_CfgDidMgrIoDidHandleOptType;
/*! Depends on the size of Dcm_CfgDidMgrSignalOpClassInfo table */
typedef uint8 Dcm_CfgDidMgrSignalOpClassRefMemType;
/*! Depends on the size of Dcm_CfgDidMgrSignalOpClassInfo table */
typedef uint8_least Dcm_CfgDidMgrSignalOpClassRefOptType;
/*! Depends on the maximum number of signals register to a DID */
typedef uint8 Dcm_CfgDidMgrSignalIterMemType;
/*! Depends on the maximum number of signals register to a DID */
typedef uint8_least Dcm_CfgDidMgrSignalIterOptType;
/*! Depends on the size in bytes of the largest control enable mask record either internally or externally */
typedef uint8 Dcm_CfgDidMgrIoDidCemrLengthMemType;
/*! Depends on the size in bytes of the largest control enable mask record either internally or externally */
typedef uint8_least Dcm_CfgDidMgrIoDidCemrLengthOptType;
/*! Depends on the size of DcmCfg_SupportedDIDInfoPool table */
typedef uint8 Dcm_CfgDidMgrSupportedDIDRefType;
/*! Always generated as uint16 */
typedef uint16 Dcm_DidMgrDidLengthType;
/*! Always generated as uint16 */
typedef uint16 Dcm_CfgDidMgrSignalLengthType;
/*! If any paged DID is enabled, it shall be mapped to Dcm_DidMgrDidLengthType. Otherwise, it shall be mapped to Dcm_CfgNetBufferSizeMemType */
typedef Dcm_CfgNetBufferSizeMemType Dcm_CfgDidMgrOptimizedDidLengthType;
/*! depends on the number of IO DIDs with S/R Interface */
typedef uint8 Dcm_CfgDidMgrIoCtrlSRHandlersRefMemType;
/*! depends on the number of IO DIDs with S/R Interface */
typedef uint8_least Dcm_CfgDidMgrIoCtrlSRHandlersRefOptType;
# if (DCM_DIDMGR_SUPPORT_ENABLED == STD_ON)
typedef Dcm_DidOpType     Dcm_DidMgrOpMemType;
typedef Dcm_DidOpOptType  Dcm_DidMgrOpOptType;
typedef uint8             Dcm_DidMgrOpCallMemType;
typedef uint8_least       Dcm_DidMgrOpCallOptType;
typedef uint16            Dcm_DidMgrOpClassType;
typedef uint8             Dcm_DidMgrRoEEventIdType;

typedef uint8 Dcm_DidMgrIoDidCemrHandlingType;

typedef P2VAR(Dcm_DidMgrDidLengthType,TYPEDEF,DCM_VAR_NOINIT) Dcm_DidMgrDidLengthPtrType;

typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_DidMgrOpFuncType) (void);

/*! Information about a DID */
struct DCM_DIDMGRDIDINFOTYPE_TAG
{
  Dcm_CfgDidMgrOptimizedDidLengthType  MinLength;      /*!< Minimum length (concrete length for static DIDs) */
  Dcm_CfgDidMgrOptimizedDidLengthType  MaxLength;      /*!< Maximum length (concrete length for static DIDs) */
  Dcm_CfgDidMgrOptimizedDidLengthType  ReservedLength; /*!< Required buffer space to read the DID if needed - otherwise set to 0 */
  Dcm_CfgDidMgrOpHandleMemType         OpBaseIdx;      /*!< Base index of the associated operations */
  Dcm_CfgDidMgrAbstractOpRefType       OpRef;          /*!< Reference to operation information table */
  Dcm_DidMgrOpMemType                  Operations;     /*!< Bitmap of allowed operations */
};
typedef struct DCM_DIDMGRDIDINFOTYPE_TAG Dcm_CfgDidMgrDidInfoType;
typedef P2CONST(Dcm_CfgDidMgrDidInfoType, TYPEDEF, DCM_CONST) Dcm_CfgDidMgrDidInfoPtrType;
typedef CONSTP2CONST(Dcm_CfgDidMgrDidInfoType, TYPEDEF, DCM_CONST) Dcm_CfgDidMgrDidInfoConstPtrType;

#if (DCM_DIDMGR_SR_IO_CONTROL_ENABLED == STD_ON)
typedef P2FUNC(Std_ReturnType, DCM_CODE, Dcm_DidMgrIoCtrlReqCtrlStateWriteFuncType)(Dcm_ReadOnlyMsgType reqData);
typedef P2FUNC(Std_ReturnType, DCM_CODE, Dcm_DidMgrIoCtrlReqUnderCtrlReadFuncType)(P2VAR(uint32, AUTOMATIC, DCM_VAR_NOINIT) underControl);
typedef P2FUNC(Std_ReturnType, DCM_CODE, Dcm_DidMgrIoCtrlReqUnderCtrlWriteFuncType)(uint32 underControl);
typedef P2FUNC(Std_ReturnType, DCM_CODE, Dcm_DidMgrIoCtrlReqIoOpReqWriteFuncType)(uint8 ioOperation
                                                                                 ,uint32 cemr);
typedef P2FUNC(boolean, DCM_CODE, Dcm_DidMgrIoCtrlResIsUpdatedFuncType)(void);
typedef P2FUNC(Std_ReturnType, DCM_CODE, Dcm_DidMgrIoCtrlResReadFuncType)(P2VAR(Dcm_IOOperationResponseType, AUTOMATIC, DCM_VAR_NOINIT) ioResponse);

/*! Struct of SR IO-Control handlers */
struct DCM_DIDMGRIOCTRLSRHANDLERSTYPE
{
  Dcm_DidMgrIoCtrlReqCtrlStateWriteFuncType  IoCtrlReqCtrlStateWrite;    /*!< Handler to transfer data for short term adjustment */
  Dcm_DidMgrIoCtrlReqUnderCtrlReadFuncType   IoCtrlReqUnderControlRead;  /*!< Handler to read underControl parameter */
  Dcm_DidMgrIoCtrlReqUnderCtrlWriteFuncType  IoCtrlReqUnderControlWrite; /*!< Handler to write underControl parameter */
  Dcm_DidMgrIoCtrlReqIoOpReqWriteFuncType    IoCtrlReqIoOpReqWrite;      /*!< Handler to transfer new IO operation and CEMR */
  Dcm_DidMgrIoCtrlResIsUpdatedFuncType       IoCtrlResIsUpdated;         /*!< Handler to check if isUpdate flag for response is set */
  Dcm_DidMgrIoCtrlResReadFuncType            IoCtrlResRead;              /*!< Handler to read response data and clear isUpdate flag */
};
typedef struct DCM_DIDMGRIOCTRLSRHANDLERSTYPE Dcm_DidMgrIoCtrlSRHandlersType;
typedef P2CONST(Dcm_DidMgrIoCtrlSRHandlersType, TYPEDEF, DCM_CONST) Dcm_DidMgrIoCtrlSRHandlersPtrType;
typedef CONSTP2CONST(Dcm_DidMgrIoCtrlSRHandlersType, TYPEDEF, DCM_CONST) Dcm_DidMgrIoCtrlSRHandlersConstPtrType;
#endif

/*! Information about a DID operation */
struct DCM_DIDMGRDIDOPINFOTYPE_TAG
{
  Dcm_CfgStateRefMemType                 ExecCondRef;   /*!< Reference to execution conditions */
  Dcm_CfgDidMgrDidOpClassHandleMemType   OpTypeBaseIdx; /*!< Base index for operation types */
  Dcm_DidMgrOpCallMemType                CallTypes;     /*!< Bitmap of supported operation types */
};
typedef struct DCM_DIDMGRDIDOPINFOTYPE_TAG Dcm_CfgDidMgrDidOpInfoType;

/*! Information about a DID operation class */
struct DCM_CFGDIDMGRDIDOPCLASSINFOTYPE_TAG
{
  Dcm_CfgDidMgrSignalOpClassRefMemType  OpClassRef; /*!< Reference to a signal operation class information */
};
typedef struct DCM_CFGDIDMGRDIDOPCLASSINFOTYPE_TAG Dcm_CfgDidMgrDidOpClassInfoType;
typedef P2CONST(Dcm_CfgDidMgrDidOpClassInfoType, TYPEDEF, DCM_CONST) Dcm_CfgDidMgrDidOpClassInfoPtrType;

/*! Information about a signal operation class */
struct DCM_CFGDIDMGRSIGNALOPCLASSINFOTYPE_TAG
{
  Dcm_DidMgrOpFuncType           OpFunc;    /*!< Generic operation function pointer that will be casted to the concrete operation at run-time */
  Dcm_CfgDidMgrSignalLengthType  MinLength; /*!< Minimum length of the signal */
  Dcm_CfgDidMgrSignalLengthType  MaxLength; /*!< Maximum length of the signal */
  Dcm_DidMgrOpClassType          FuncClass; /*!< Operation function class */
};
typedef struct DCM_CFGDIDMGRSIGNALOPCLASSINFOTYPE_TAG Dcm_CfgDidMgrSignalOpClassInfoType;
typedef P2CONST(Dcm_CfgDidMgrSignalOpClassInfoType, TYPEDEF, DCM_CONST) Dcm_CfgDidMgrSignalOpClassInfoPtrType;

/*! Information about an IO control operation */
struct DCM_CFGDIDMGRIOCONTROLINFOTYPE_TAG
{
#if (DCM_DIDMGR_OPTYPE_IO_RETCTRL2ECU_ENABLED == STD_ON)
  Dcm_CfgDidMgrDidOpClassHandleMemType  RetCtrlToEcuOpRef;    /*!< Reference to ReturnControlToECU operation */
#endif
  Dcm_CfgStateRefMemType                CtrlExecCondRef;      /*!< Reference to execution conditions */
  Dcm_CfgDidMgrIoDidCemrLengthMemType   CtrlEnblMaskLength;   /*!< Length of the CEMR */
  Dcm_DidMgrIoDidCemrHandlingType       CtrlEnblMaskHandling; /*!< The type of an IO DID control enable mask record handling */
};
typedef struct DCM_CFGDIDMGRIOCONTROLINFOTYPE_TAG Dcm_CfgDidMgrOpInfoIoControlType;

#if (DCM_DIDMGR_OP_INFO_DEFINE_ENABLED == STD_ON)
/*! Operation information for definition of DynDID */
struct DCM_CFGDIDMGRDYNDEFINEINFOTYPE_TAG
{
# if (DCM_DIDMGR_PERIODICDYNDID_ENABLED == STD_ON)
  uint16                                  Did;             /*!< DID number */
# endif
# if (DCM_DIDMGR_DYNDID_CLR_ON_STATE_CHG_ENABLED == STD_ON)
  Dcm_CfgStateRefMemType                  ReadExecCondRef; /*!< Reference to execution conditions */
# endif
  Dcm_CfgDidMgrDynDidSrcItemIdxMemType    SrcItemRef;      /*!< Reference to the first source item */
  uint8                                   NumItems;        /*!< Total number of source items */
};
typedef struct DCM_CFGDIDMGRDYNDEFINEINFOTYPE_TAG Dcm_CfgDidMgrOpInfoDefineType;
#endif

/*! Combined operation information for IO control and response on event */
struct DCM_CFGDIDMGROPINFOCOMBINEDTYPE_TAG
{
  Dcm_CfgDidMgrCombinedOpRefType OpRefIoControl; /*!< Reference to IO control operation information */
  Dcm_CfgDidMgrCombinedOpRefType OpRefRoE;       /*!< Reference to response on event operation information */
};
typedef struct DCM_CFGDIDMGROPINFOCOMBINEDTYPE_TAG Dcm_CfgDidMgrOpInfoCombinedType;

typedef Dcm_UtiU16RangeType Dcm_CfgDidMgrDidRangeType;

#if (DCM_DIDMGR_OP_INFO_ROE_ENABLED == STD_ON)
/*! Operation info for response on event */
struct DCM_CFGDIDMGROPROETYPE_TAG
{
  Dcm_DidMgrRoEEventIdType EventId; /*!< The event ID */
};
typedef struct DCM_CFGDIDMGROPROETYPE_TAG Dcm_CfgDidMgrOpInfoRoEType;
#endif

/*! Shared Did manager descriptor data type */
struct DCM_DIDMGRDIDDESCRIPTORTYPE_TAG
{
  Dcm_CfgDidMgrDidInfoRefType           DidInfoIdx;         /*!< Reference to Dcm_CfgDidMgrDidInfo[] entry */
  Dcm_CfgDidMgrOpHandleMemType          DidOpInfoIdx;       /*!< Reference to Dcm_CfgDidMgrDidOpInfo[] entry */
  Dcm_CfgDidMgrDidOpClassHandleMemType  DidOpClassInfoIdx;  /*!< Reference to Dcm_CfgDidMgrDidOpClassInfo[] entry */
};
typedef struct DCM_DIDMGRDIDDESCRIPTORTYPE_TAG Dcm_DidMgrDidDescriptorType;

/*! Context information of the DID */
struct DCM_DIDMGRDIDINFOCONTEXTTYPE_TAG
{
  Dcm_DidMgrDidDescriptorType  Descriptor;      /*!< Descriptor of the Did */
  uint16                       Did;             /*!< Identifier value of the Did */
  Dcm_DidMgrDidLengthType      DidLength;       /*!< Length of the Did */
  Dcm_DidMgrDidLengthType      ReservedLength;  /*!< Buffer size which has to be reserved to be able to read the Did */
};
typedef struct DCM_DIDMGRDIDINFOCONTEXTTYPE_TAG Dcm_DidMgrDidInfoContextType;
typedef P2VAR(Dcm_DidMgrDidInfoContextType, TYPEDEF, DCM_VAR_NOINIT) Dcm_DidMgrDidInfoContextPtrType;
# endif /* (DCM_DIDMGR_SUPPORT_ENABLED == STD_ON) */
typedef uint8 Dcm_CfgRidMgrOpHandleMemType;
typedef uint8_least Dcm_CfgRidMgrOpHandleOptType;
typedef uint8 Dcm_CfgRidMgrRoutineInfoByteMemType;
typedef uint8 Dcm_CfgRidMgrInfoHandleMemType;
typedef uint8_least Dcm_CfgRidMgrInfoHandleOptType;
# if (DCM_RIDMGR_SUPPORT_ENABLED == STD_ON)
typedef uint8   Dcm_RidMgrOpType;
typedef uint8   Dcm_RidMgrOpCallType;
typedef uint8   Dcm_RidMgrParamIntegrityType;
/*! Dedicated RID data length data type: all service ports do use 16bit length parameter */
typedef uint16  Dcm_RidMgrRidLengthType;
typedef P2VAR(Dcm_RidMgrRidLengthType, TYPEDEF, DCM_VAR_NOINIT) Dcm_RidMgrRidLengthPtrType;

/*!
 * Generic routine operation function prototype
 * \return DCM_E_OK             - Operation finished with success. Do not call again
 * \return DCM_E_NOT_OK         - Operation failed. Take the NRC from ErrorCode. Do not call again
 * \return DCM_E_PENDING        - Requested job not yet finished, call again.
 * \return DCM_E_FORCE_RCRRP    - Send immediately a RCR-RP response. Call again once transmission confirmed (with or without success)
 */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_RidMgrOpFuncType)(void);

/*! Routine identifier related configuration package */
struct DCM_RIDMGRRIDINFOTYPE_TAG
{
  Dcm_CfgRidMgrOpHandleMemType         OpBaseIdx;          /*!< Reference to Dcm_CfgRidMgrOpInfo[] entry */
  Dcm_CfgStateRefMemType               ExecCondRef;        /*!< Execution pre-condition reference */
  Dcm_RidMgrOpType                     Operations;         /*!< Supported RID operations (Valid values: any combination of DCM_RIDMGR_OP_) */
  Dcm_CfgRidMgrRoutineInfoByteMemType  RoutineInfoByte;    /*!< The routine info byte if supported */
};
typedef struct DCM_RIDMGRRIDINFOTYPE_TAG Dcm_CfgRidMgrRidInfoType;

/*! Routine identifier operation related configuration package */
struct DCM_RIDMGROPINFOTYPE_TAG
{
  Dcm_RidMgrOpFuncType          OpFunc;          /*!< Pointer to the function implementation */
  Dcm_RidMgrRidLengthType       ReqMinLength;    /*!< Minimum request length without the only possible last dynamic length signal (does not include RID + SF) */
  Dcm_RidMgrRidLengthType       ReqMaxLength;    /*!< Maximum request length with the only possible last dynamic length signal (does not include RID + SF) */
  Dcm_RidMgrRidLengthType       ResMinLength;    /*!< Minimum response length without the only possible last dynamic length signal (does not include RID + SF) */
  Dcm_RidMgrRidLengthType       ResMaxLength;    /*!< Maximum response length with the only possible last dynamic length signal (does not include RID + SF) */
  Dcm_RidMgrOpCallType          OpType;          /*!< Function prototype descriptor (Valid values: one of DCM_RIDMGR_OPTYPE_ but not DCM_RIDMGR_OPTYPE_NONE) */
  Dcm_RidMgrParamIntegrityType  ParamIntegrity;  /*!< Storage of the routine operation parameters (0: None, 1: IN, 2: OUT) */
};
typedef struct DCM_RIDMGROPINFOTYPE_TAG Dcm_CfgRidMgrOpInfoType;
typedef P2CONST(Dcm_CfgRidMgrOpInfoType, TYPEDEF, DCM_CONST) Dcm_RidMgrOpInfoPtrType;
# endif /* (DCM_RIDMGR_SUPPORT_ENABLED == STD_ON) */
typedef uint8 Dcm_CfgMemMgrMemAddrType;
typedef uint32 Dcm_CfgMemMgrReqAddrType;
typedef uint32 Dcm_CfgMemMgrReqSizeType;
typedef uint8 Dcm_CfgMemMgrStateRefType;
typedef uint8 Dcm_CfgMemMgrMemMapIdxMemType;
typedef uint8_least Dcm_CfgMemMgrMemMapIdxOptType;
# if (DCM_MEMMGR_SUPPORT_ENABLED == STD_ON)
/*! Memory manager related configuration package, describes a memory block and the characteristic of the memory block */
struct DCM_CFGMEMMGRMEMMAPINFOTYPE_TAG
{
  Dcm_CfgMemMgrStateRefType    ExecCondRefs[DCM_MEMMGR_NUM_MEMORY_OPERATIONS]; /*!< Reference to the Dcm_CfgStatePreconditions[] entry */
  Dcm_CfgMemMgrMemAddrType     StartAddr;                                      /*!< Start address of the memory block */
  Dcm_CfgMemMgrMemAddrType     EndAddr;                                        /*!< End address of the memory block */
};
typedef struct DCM_CFGMEMMGRMEMMAPINFOTYPE_TAG Dcm_CfgMemMgrMemMapInfoType;
typedef P2CONST(Dcm_CfgMemMgrMemMapInfoType, TYPEDEF, DCM_CONST) Dcm_CfgMemMgrMemMapInfoPtrType;

/*! MID related configuration package */
struct DCM_CFGMEMMGRMEMIDINFOTYPE_TAG
{
  Dcm_CfgMemMgrMemMapInfoPtrType MemMapTable;  /*!< Pointer to the memory map table */
  Dcm_CfgMemMgrMemMapIdxMemType  Size;         /*!< Size of the memory map table */
};
typedef struct DCM_CFGMEMMGRMEMIDINFOTYPE_TAG Dcm_CfgMemMgrMemIdInfoType;
typedef P2VAR(Dcm_CfgMemMgrMemIdInfoType, TYPEDEF, AUTOMATIC)   Dcm_CfgMemMgrMemIdInfoPtrType;
typedef P2CONST(Dcm_CfgMemMgrMemIdInfoType, TYPEDEF, AUTOMATIC) Dcm_CfgMemMgrMemIdInfoConstPtrType;

/*! Shared memory block descriptor data type for other service processors (e.g. 0x2C) */
struct DCM_MEMMGRMEMBLOCKTYPE_TAG
{
  Dcm_CfgMemMgrReqAddrType  Address;  /*!< The address to access */
  Dcm_CfgMemMgrReqSizeType  Length;   /*!< The number of bytes requested */
  uint8                     Mid;      /*!< The memory identifier */
};
typedef struct DCM_MEMMGRMEMBLOCKTYPE_TAG Dcm_MemMgrMemBlockType;
typedef P2VAR(Dcm_MemMgrMemBlockType, TYPEDEF, DCM_VAR_NOINIT)   Dcm_MemMgrMemBlockPtrType;
typedef P2CONST(Dcm_MemMgrMemBlockType, TYPEDEF, DCM_VAR_NOINIT) Dcm_MemMgrMemBlockConstPtrType;
# endif /* (DCM_MEMMGR_SUPPORT_ENABLED == STD_ON) */
# if (DCM_OBDUDSIDMGR_SUPPORT_ENABLED == STD_ON)
typedef uint8       Dcm_ObdIdMgrHandleMemType;
typedef uint8_least Dcm_ObdIdMgrHandleOptType;
# endif /* (DCM_OBDUDSIDMGR_SUPPORT_ENABLED == STD_ON) */
/*! Diagnostic request indication notification function handler pointer type (for all Xxx_Indication()) */
#if (DCM_DCM_AR_VERSION >= DCM_DCM_AR_VERSION_450)
typedef P2FUNC(Std_ReturnType, DCM_CODE, Dcm_DiagIndicationFuncType) (Dcm_MsgItemType                 SID          /* IN: SID */
                                                                     ,Dcm_ReadOnlyMsgType             ReqData      /* IN: Request data (behind SID byte) */
                                                                     ,uint32                          ReqDataLen   /* IN: Request data length */
                                                                     ,uint8                           ReqType      /* IN: Request type (0 - physical, 1- functional) */
                                                                     ,uint16                          ConnectionId /* IN: Unique connection identifier */
                                                                     ,Dcm_NegativeResponseCodePtrType ErrorCode    /* OUT: ErrorCode */
                                                                     ,Dcm_ProtocolType                ProtocolType /* IN: Type of protocol to be indicated */
                                                                     ,uint16                          SrcAddr      /* IN: Tester SourceAddress */);
#else
typedef P2FUNC(Std_ReturnType, DCM_CODE, Dcm_DiagIndicationFuncType) (Dcm_MsgItemType                 SID        /* IN: SID */
                                                                     ,Dcm_ReadOnlyMsgType             ReqData    /* IN: Request data (behind SID byte) */
                                                                     ,uint16                          ReqDataLen /* IN: Request data length */
                                                                     ,uint8                           ReqType    /* IN: Request type (0 - physical, 1- functional) */
                                                                     ,uint16                          SrcAddr    /* IN: Tester SourceAddress */
                                                                     ,Dcm_NegativeResponseCodePtrType ErrorCode  /* OUT: ErrorCode */);
#endif

/*! Diagnostic response confirmation notification function handler pointer type (for all Xxx_Confirmation()) */
#if (DCM_DCM_AR_VERSION >= DCM_DCM_AR_VERSION_450)
typedef P2FUNC(Std_ReturnType, DCM_CODE, Dcm_DiagConfirmationFuncType) (Dcm_MsgItemType            SID           /* IN: SID */
                                                                       ,uint8                      ReqType       /* IN: Request type (0 - physical, 1- functional) */
                                                                       ,uint16                     ConnectionId  /* IN: Unique connection identifier */
                                                                       ,Dcm_ConfirmationStatusType ConfStatus    /* IN: Confirmation status */
                                                                       ,Dcm_ProtocolType           ProtocolType  /* IN: Type of protocol to be indicated */
                                                                       ,uint16                     SrcAddr       /* IN: Tester SourceAddress */);
#else
typedef P2FUNC(Std_ReturnType, DCM_CODE, Dcm_DiagConfirmationFuncType) (Dcm_MsgItemType            SID        /* IN: SID */
                                                                       ,uint8                      ReqType    /* IN: Request type (0 - physical, 1- functional) */
                                                                       ,uint16                     SrcAddr    /* IN: Tester SourceAddress */
                                                                       ,Dcm_ConfirmationStatusType ConfStatus /* IN: Confirmation status */);
#endif

/*
 * Diagnostic service handler "class" members:
 */

/*! Constructor (initialization) function prototype */
typedef P2FUNC(void, DCM_CODE, Dcm_DiagSvcInitFuncType) (void);
/*!
 * Processor function prototype
 * \return DCM_E_OK             - Operation finished with success. Do not call again
 * \return DCM_E_NOT_OK         - Operation failed. Take the NRC from ErrorCode. Do not call again
 * \return DCM_E_PENDING        - Requested job not yet finished, call again.
 * \return DCM_E_FORCE_RCRRP    - Send immediately a RCR-RP response. Call again once transmission confirmed (with or without success)
 * \return DCM_E_STOP_REPEATER  - Do not call again.
 * \return DCM_E_PROCESSINGDONE - Deprecated return value, equivalent to DCM_E_OK. Shall not be used by any application service processor!
 */
typedef P2FUNC(Std_ReturnType, DCM_CALLOUT_CODE, Dcm_DiagSvcProcessorFuncType) (Dcm_ThreadIdType                threadId    /* IN: Active thread */
                                                                               ,Dcm_OpStatusType                OpStatus    /* IN: OpStatus */
                                                                               ,Dcm_MsgContextPtrType           pMsgContext /* IN,OUT: pMsgContext */
                                                                               ,Dcm_NegativeResponseCodePtrType ErrorCode   /* OUT: ErrorCode */);
/*! Post-Processor (fast and normal types) function prototype */
typedef P2FUNC(void, DCM_CALLOUT_CODE, Dcm_DiagSvcConfirmationFuncType) (Dcm_ThreadIdType           threadId   /* IN: Active thread */
                                                                        ,Dcm_ConfirmationStatusType ConfStatus /* IN: Confirmation status */);

/*!
 * Paged-data provider function prototype
 * \return DCM_E_OK                 - Operation finished with success. Do not call again
 * \return DCM_E_NOT_OK             - Operation failed. Take the NRC from ErrorCode. Do not call again
 * \return DCM_E_PENDING            - Some data written/committed. Call again to fill in more data
 * \return DCM_E_BUFFERTOOLOW       - Maximum available space used but was not enough. Call again when some additional free space available
 * \return DCM_E_DATA_READY_PADDING - No more data to be provided. Do not call again. If needed, switch to padding-byte data provider
 */
typedef P2FUNC(Std_ReturnType, DCM_CALLOUT_CODE, Dcm_DiagSvcUpdateFuncType) (Dcm_ThreadIdType                threadId      /* IN: Active thread */
                                                                            ,Dcm_OpStatusType                OpStatus      /* IN: OpStatus */
                                                                            ,Dcm_DiagDataContextPtrType      pDataContext  /* IN,OUT: paged-data descriptor */
                                                                            ,Dcm_NegativeResponseCodePtrType ErrorCode     /* OUT: ErrorCode */);
/*! Paged-data job cancellation notification function prototype */
typedef P2FUNC(void, DCM_CALLOUT_CODE, Dcm_DiagSvcCancelFuncType) (Dcm_ThreadIdType threadId /* IN: Active thread */);

/*!
 * Pre-handler function prototype
 * \return DCM_E_OK                 - Pre-handler finished with success. Do not call again
 * \return DCM_E_NOT_OK             - Pre-handler failed. Take the NRC from ErrorCode. Do not call again
 * \return DCM_E_PENDING            - Requested pre-handler not yet finished, call again
 */
typedef P2FUNC(Std_ReturnType, DCM_CALLOUT_CODE, Dcm_DiagSvcPreHandlerFuncType) (Dcm_OpStatusType                OpStatus     /* IN: OpStatus */
                                                                                ,Dcm_MsgItemType                 SID          /* IN: SID */
                                                                                ,Dcm_ReadOnlyMsgType             ReqData      /* IN: Request data (without SID byte) */
                                                                                ,uint32                          ReqDataLen   /* IN: Request data length */
                                                                                ,Dcm_ProtocolType                ProtocolType /* IN: Type of protocol to be indicated */
                                                                                ,uint16                          SrcAddr      /* IN: Tester SourceAddress */
                                                                                ,uint16                          ConnectionId /* IN: Unique connection identifier */
                                                                                ,uint8                           ReqType      /* IN: Request type (0 - physical, 1- functional) */
                                                                                ,Dcm_NegativeResponseCodePtrType ErrorCode    /* OUT: ErrorCode */);

/*!
 * Post-handler function prototype
 * \return DCM_E_OK                 - Post-handler finished with success. Do not call again
 * \return DCM_E_NOT_OK             - Post-handler failed. Take the NRC from ErrorCode. Do not call again
 * \return DCM_E_PENDING            - Requested post-handler not yet finished, call again
 */
typedef P2FUNC(Std_ReturnType, DCM_CALLOUT_CODE, Dcm_DiagSvcPostHandlerFuncType) (Dcm_OpStatusType                OpStatus     /* IN: OpStatus */
                                                                                 ,Dcm_MsgItemType                 SID          /* IN: SID */
                                                                                 ,Dcm_ReadOnlyMsgType             ResData      /* IN: Response data (without SID byte) */
                                                                                 ,uint32                          ResDataLen   /* IN: Response data length */
                                                                                 ,Dcm_ProtocolType                ProtocolType /* IN: Type of protocol to be indicated */
                                                                                 ,uint16                          SrcAddr      /* IN: Tester SourceAddress */
                                                                                 ,uint16                          ConnectionId /* IN: Unique connection identifier */
                                                                                 ,uint8                           ReqType      /* IN: Request type (0 - physical, 1- functional) */
                                                                                 ,Dcm_NegativeResponseCodePtrType ErrorCode    /* OUT: ErrorCode */);

/*! Diagnostic service properties container in bitmap form (Valid values: DCM_DIAG_SVC_CFG_PROP_*) */
typedef uint8 DcmCfg_DiagServicePropertiesType;

/*! Configuration of a diagnostic service handler */
struct DCM_CFGDIAGSERVICEINFOTYPE_TAG
{
  Dcm_DiagSvcProcessorFuncType      ProcFunc;           /*!< Pointer to the processor function (e.g. Dcm_Service10Processor() or any application specific function name) */
#if (DCM_DIAG_SERVICE_DISPATCHER_ENABLED == STD_ON)
  Dcm_DiagSvcProcessorFuncType      AltProcFunc;        /*!< Pointer to the alternative processor function */
#endif
  DcmCfg_DiagServicePropertiesType  Props;              /*!< Diagnostic service properties (Any combination of DCM_DIAG_SVC_CFG_PROP_*) */
  uint8                             MinLength;          /*!< Minimum request length (excluding the SID byte) to be verified prior calling the service processor (0 - no restrictions, >0 - particular minimum length) */
  uint8                             ConfFuncRef;        /*!< Reference to the Dcm_CfgDiagSvcPostProcessors[] entry */
  uint8                             FastConfFuncRef;    /*!< Reference to the Dcm_CfgDiagSvcPostProcessors[] entry (if exist, fast post-processors are located right behind the normal post-processor) */
#if (DCM_PAGED_BUFFER_ENABLED == STD_ON)
  uint8                             UpdateFuncRef;      /*!< Reference to the Dcm_CfgDiagSvcUpdaters[] entry */
#endif
  uint8                             CancelFuncRef;      /*!< Reference to the Dcm_CfgDiagSvcCancellers[] entry */
  uint8                             PreHandlerFuncRef;  /*!< Reference to the Dcm_CfgDiagSvcPreHandlers[] entry */
  uint8                             PostHandlerFuncRef; /*!< Reference to the Dcm_CfgDiagSvcPostHandlers[] entry */
};
typedef struct DCM_CFGDIAGSERVICEINFOTYPE_TAG Dcm_CfgDiagServiceInfoType;
typedef P2CONST(Dcm_CfgDiagServiceInfoType, TYPEDEF, DCM_CONST) Dcm_CfgDiagServiceInfoPtrType;

/*! Configuration of diagnostic request notification handlers */
struct DCM_CFGDIAGSERVICENOFICATIONINFOTYPE_TAG
{
  Dcm_DiagIndicationFuncType      IndFunc;  /*!< Points to a Xxx_Indication() callout */
  Dcm_DiagConfirmationFuncType    ConfFunc; /*!< Points to a Xxx_Confirmation) callout */
};
typedef struct DCM_CFGDIAGSERVICENOFICATIONINFOTYPE_TAG Dcm_CfgDiagNotificationInfoType;
typedef P2CONST(Dcm_CfgDiagNotificationInfoType, TYPEDEF, DCM_CONST) Dcm_CfgDiagNotificationInfoPtrType;
/*! Depends on the total number of protocols */
typedef uint8 Dcm_CfgDiagSvc2ProtMapMemType;
/*! Depends on the total number of protocols */
typedef uint8_least Dcm_CfgDiagSvc2ProtMapOptType;
/*! Depends on the total number of configuration variants */
typedef uint8 Dcm_CfgVarMgrDiagVariantIdMemType;
/*! Depends on the total number of configuration variants */
typedef uint8_least Dcm_CfgVarMgrDiagVariantIdOptType;
/*! Depends on the total number of diagnostic variants */
typedef uint8 Dcm_CfgVarMgrBitSetBaseType;
/*! A set of variants */
typedef Dcm_CfgVarMgrBitSetBaseType Dcm_CfgVarMgrBitSetType[1];
#if (DCM_VARMGR_MULTI_COM_ENABLED == STD_ON)
/* Pointer to a particular network configuration variant */
typedef P2CONST(Dcm_CfgNetVariantInfoType, TYPEDEF, DCM_CONST_PBCFG) Dcm_CfgVarMgrComVariantType;
#endif

/*! Configuration of the common variant data between network and diagnostic services variant information */
struct DCM_CFGVARMGRBRIDGEVARIANTTYPE_TAG
{
  P2CONST(Dcm_CfgDiagSvc2ProtMapMemType, AUTOMATIC, DCM_CONST_PBCFG) Svc2ProtocolMap; /*!< Points to the "diagnostic service to protocol map" for a particular DCM variant (criterion): Dcm_CfgDiagSvcId2ProtMap[] */
};
typedef struct DCM_CFGVARMGRBRIDGEVARIANTTYPE_TAG Dcm_CfgVarMgrBridgeVariantType;

/*! Diagnostic post-build-variant (selectable) related configuration data */
#if (DCM_VARMGR_MULTI_SVC_ANY_ENABLED == STD_ON) || (DCM_SVC_27_PB_ENABLED == STD_ON)
struct DCM_CFGDIAGVARIANTINFOTYPE_TAG
{
# if (DCM_SVC_27_PB_ENABLED == STD_ON)
  P2CONST(uint8, AUTOMATIC, DCM_CONST) Svc27IndirectionTable;  /*!< Pointer to the service 0x27 related indirection table */
# endif
# if (DCM_VARMGR_MULTI_SVC_ANY_ENABLED == STD_ON)
  Dcm_CfgVarMgrDiagVariantIdMemType    Id;                     /*!< Identifier for the precondition variant */
# endif
};
typedef struct DCM_CFGDIAGVARIANTINFOTYPE_TAG Dcm_CfgDiagVariantInfoType;
typedef P2CONST(Dcm_CfgDiagVariantInfoType, TYPEDEF, DCM_CONST) Dcm_CfgVarMgrDiagVariantType;
#endif

#if (DCM_VARMGR_MODE_POSTBUILD_LOAD_ENABLED == STD_ON)
/*! Configuration of the common for all PBL variants RAM area */
struct DCM_CFGVARMGRRAMVARIANTTYPE_TAG
{
  Dcm_CfgNetRamVariantInfoType  NetworkRam; /*!< Relocatable RAM for the network sub-component */
};
typedef struct DCM_CFGVARMGRRAMVARIANTTYPE_TAG Dcm_CfgVarMgrRamVariantType;
typedef P2CONST(Dcm_CfgVarMgrRamVariantType, TYPEDEF, DCM_CONST_PBCFG) Dcm_CfgVarMgrRamVariantPtrType;
# if (DCM_VARMGR_MODE_POSTBUILD_LOAD_ENABLED == STD_ON)
/*! Diagnostic sub-component post-build-loadable reallocatable shared configuration data */
struct DCM_DIAGROMVARIANTINFOTYPE_TAG
{
  P2CONST(Dcm_CfgVarMgrBitSetType, AUTOMATIC, DCM_CONST_PBCFG) VariantFilter; /*!< Bitset for enabled variants */
};
typedef struct DCM_DIAGROMVARIANTINFOTYPE_TAG Dcm_CfgDiagRomVariantInfoType;
# endif

/*! Configuration of the common ROM (CONST) area for all PBL variants */
struct DCM_CFGVARMGRROMVARIANTTYPE_TAG
{
  Dcm_CfgNetRomVariantInfoType  NetworkRom; /*!< Relocatable ROM for the network sub-component */
# if (DCM_VARMGR_MULTI_SVC_ANY_ENABLED == STD_ON)
  Dcm_CfgDiagRomVariantInfoType DiagRom;    /*!< Relocatable ROM for the diagnostic sub-component */
# endif
};
typedef struct DCM_CFGVARMGRROMVARIANTTYPE_TAG Dcm_CfgVarMgrRomVariantType;
typedef P2CONST(Dcm_CfgVarMgrRomVariantType, TYPEDEF, DCM_CONST_PBCFG) Dcm_CfgVarMgrRomVariantPtrType;
#endif
/*! Container for all PBS/PBL (PBX) variant configuration parameters (a single criterion package): (network-, diagnostic- and common-(bridge)-variant data) */
struct DCM_CONFIGTYPE_TAG
{
#if (DCM_VARMGR_SUPPORT_ENABLED == STD_ON)
# if (DCM_VARMGR_MULTI_COM_ENABLED == STD_ON)
  Dcm_CfgVarMgrComVariantType       ComVariant;       /*!< Contains all network sub-component related variant information (called COM-criteria) */
# endif
  Dcm_CfgVarMgrBridgeVariantType    BridgeVariant;    /*!< Contains all common/shared data (bridge) between COM and CFG variants */
# if (DCM_VARMGR_MULTI_SVC_ANY_ENABLED == STD_ON) || (DCM_SVC_27_PB_ENABLED == STD_ON)
  Dcm_CfgDiagVariantInfoType        DiagVariant;      /*!< Contains all diagnostic related variant information */
# endif
# if (DCM_VARMGR_MODE_POSTBUILD_LOAD_ENABLED == STD_ON)
  Dcm_CfgVarMgrRamVariantPtrType    RamVariant;       /*!< Relocatable PB RAM */
  Dcm_CfgVarMgrRomVariantPtrType    RomVariant;       /*!< Relocatable PB ROM */
# endif
  /* Generally required elements */
# if (DCM_VARMGR_MODE_POSTBUILD_LOAD_ENABLED == STD_ON)
  uint16                            GenOutputType;    /*!< Generator Output Compatibility Version */
  uint16                            FinalMagicNumber; /*!< Configuration structure magic number   */
# endif
#else
  uint8 NoConfig;                                     /*!< In case of PBS with single variant (DCM optimizes the code for pre-compile variant), still a configuration struct is expected by the software environment */
#endif
};
typedef struct DCM_CONFIGTYPE_TAG Dcm_ConfigType;
typedef P2CONST(Dcm_ConfigType, TYPEDEF, DCM_CONST_PBCFG) Dcm_ConfigPtrType;
typedef struct DCM_CONFIGSTYPE_TAG
{
  Dcm_ConfigType Config_RDR_01;
} Dcm_ConfigsType;
# if (DCM_AUTHMGR_SUPPORT_ENABLED == STD_ON)
/*! White list element sizes */
#define DCM_AUTHMGR_ELEMENT_SERVICE_SIZE                             4u
#define DCM_AUTHMGR_ELEMENT_DID_SIZE                                 3u
#define DCM_AUTHMGR_ELEMENT_RID_SIZE                                 3u
#define DCM_AUTHMGR_ELEMENT_MEM_SIZE                                 1u

#if (DCM_AUTHMGR_EXT_SETTER_ENABLED == STD_ON)
/*! Authentication state type */
typedef uint8 Dcm_AuthenticationStateType;
#endif

/*! Service whitelist element context */
#if (DCM_AUTHMGR_WHITELIST_SERVICES_ENABLED == STD_ON)
struct DCM_WHITELISTSERVICEELEMENTCONTEXTTYPE_TAG
{
  uint8 WhiteListData[DCM_AUTHMGR_ELEMENT_SERVICE_SIZE]; /*! Service white list element data storage */
  uint8 WhiteListEntryLength;                            /*! Service white list element length */
};
typedef struct DCM_WHITELISTSERVICEELEMENTCONTEXTTYPE_TAG Dcm_WhiteListServiceElementContextType;

struct DCM_WHITELISTSERVICECONTEXTTYPE_TAG
{
  uint16                                 NumServiceWhiteListElements;                                  /*!< Number of white list elements */
  Dcm_WhiteListServiceElementContextType WhiteListServiceElement[DCM_AUTHMGR_NUM_SERVICE_WL_ELEMENTS]; /*!< Storage for Service white list elements */
};
typedef struct DCM_WHITELISTSERVICECONTEXTTYPE_TAG Dcm_WhiteListServiceContextType;
typedef P2VAR(Dcm_WhiteListServiceContextType, TYPEDEF, DCM_VAR_NOINIT) Dcm_WhiteListServiceContextPtrType;
#endif

/*! DID whitelist element context */
#if (DCM_AUTHMGR_WHITELIST_DID_ENABLED == STD_ON)
struct DCM_WHITELISTDIDELEMENTCONTEXTTYPE_TAG
{
  uint16 DidNumber;     /*! DID white list element DID identifier */
  uint8  DidAccessMask; /*! DID white list element operation access mask */
};
typedef struct DCM_WHITELISTDIDELEMENTCONTEXTTYPE_TAG Dcm_WhiteListDidElementContextType;

struct DCM_WHITELISTDIDCONTEXTTYPE_TAG
{
  uint16                             NumDidWhiteListElements;                              /*!< Number of white list elements */
  Dcm_WhiteListDidElementContextType WhiteListDidElement[DCM_AUTHMGR_NUM_DID_WL_ELEMENTS]; /*!< Storage for DID white list elements */
};
typedef struct DCM_WHITELISTDIDCONTEXTTYPE_TAG Dcm_WhiteListDidContextType;
typedef P2VAR(Dcm_WhiteListDidContextType, TYPEDEF, DCM_VAR_NOINIT) Dcm_WhiteListDidContextPtrType;
#endif

/*! RID whitelist element context */
#if (DCM_AUTHMGR_WHITELIST_RID_ENABLED == STD_ON)
struct DCM_WHITELISTRIDELEMENTCONTEXTTYPE_TAG
{
  uint16 RidNumber;     /*! RID white list element RID identifier */
  uint8  RidAccessMask; /*! RID white list element operation access mask */
};
typedef struct DCM_WHITELISTRIDELEMENTCONTEXTTYPE_TAG Dcm_WhiteListRidElementContextType;

struct DCM_WHITELISTRIDCONTEXTTYPE_TAG
{
  uint16                             NumRidWhiteListElements;                              /*!< Number of white list elements */
  Dcm_WhiteListRidElementContextType WhiteListRidElement[DCM_AUTHMGR_NUM_RID_WL_ELEMENTS]; /*!< Storage for RID white list elements */
};
typedef struct DCM_WHITELISTRIDCONTEXTTYPE_TAG Dcm_WhiteListRidContextType;
typedef P2VAR(Dcm_WhiteListRidContextType, TYPEDEF, DCM_VAR_NOINIT) Dcm_WhiteListRidContextPtrType;
#endif

/*! MEM whitelist element context */
#if (DCM_AUTHMGR_WHITELIST_MEM_ENABLED == STD_ON)
struct DCM_WHITELISTMEMELEMENTCONTEXTTYPE_TAG
{
  uint8 MemNumber; /*! MEM white list element Memory Selection identifier */
};
typedef struct DCM_WHITELISTMEMELEMENTCONTEXTTYPE_TAG Dcm_WhiteListMemElementContextType;

struct DCM_WHITELISTMEMCONTEXTTYPE_TAG
{
  uint16                             NumMemWhiteListElements;                              /*!< Number of white list elements. */
  Dcm_WhiteListMemElementContextType WhiteListMemElement[DCM_AUTHMGR_NUM_MEM_WL_ELEMENTS]; /*!< Storage for MEM white list elements */
};
typedef struct DCM_WHITELISTMEMCONTEXTTYPE_TAG Dcm_WhiteListMemContextType;
typedef P2VAR(Dcm_WhiteListMemContextType, TYPEDEF, DCM_VAR_NOINIT) Dcm_WhiteListMemContextPtrType;
#endif

/*! Authentication manager white lists context */
#if(DCM_AUTHMGR_WHITELISTS_ENABLED == STD_ON)
struct DCM_WHITELISTCONTEXTTYPE_TAG
{
# if (DCM_AUTHMGR_WHITELIST_SERVICES_ENABLED == STD_ON)
  Dcm_WhiteListServiceContextType WhiteListServiceContext; /*!< Storage for Service white list elements */
# endif
# if (DCM_AUTHMGR_WHITELIST_DID_ENABLED == STD_ON)
  Dcm_WhiteListDidContextType     WhiteListDidContext;     /*!< Storage for DID white list elements */
# endif
# if (DCM_AUTHMGR_WHITELIST_RID_ENABLED == STD_ON)
  Dcm_WhiteListRidContextType     WhiteListRidContext;     /*!< Storage for RID white list elements */
# endif
# if (DCM_AUTHMGR_WHITELIST_MEM_ENABLED == STD_ON)
  Dcm_WhiteListMemContextType     WhiteListMemContext;     /*!< Storage for MEM white list elements */
# endif
};
typedef struct DCM_WHITELISTCONTEXTTYPE_TAG Dcm_WhiteListContextType;
typedef P2VAR(Dcm_WhiteListContextType, TYPEDEF, DCM_VAR_NOINIT) Dcm_WhiteListContextPtrType;
typedef P2CONST(Dcm_WhiteListContextType, TYPEDEF, DCM_VAR_NOINIT) Dcm_ReadOnlyWhiteListContextPtrType;
#endif

#if (DCM_AUTHMGR_EXT_SETTER_ENABLED == STD_ON)
struct DCM_AUTHENTICATIONINFOTYPE_TAG
{
  Dcm_CfgStateGroupMemType AuthRole;
# if(DCM_AUTHMGR_WHITELISTS_ENABLED == STD_ON)
  Dcm_WhiteListContextType WhiteLists;
# endif
};
typedef struct DCM_AUTHENTICATIONINFOTYPE_TAG Dcm_AuthenticationInfoType;
#endif

#if (DCM_STATE_AUTHENTICATION_ENABLED == STD_ON)
struct DCM_AUTHMGRCONNCONTEXTTYPE_TAG
{
# if(DCM_AUTHMGR_WHITELISTS_ENABLED == STD_ON)
  Dcm_WhiteListContextType    WhiteListContext; /*!< Storage for white lists */
# endif
  Dcm_CfgStateGroupMemType    ActiveRole;       /*!< Storage for active roles */
  Dcm_AuthenticationStateType AuthState;        /*!< Storage for authentication states */
};
typedef struct DCM_AUTHMGRCONNCONTEXTTYPE_TAG Dcm_AuthMgrConnContextType;
typedef P2VAR(Dcm_AuthMgrConnContextType, TYPEDEF, DCM_VAR_NOINIT) Dcm_AuthMgrConnContextPtrType;
#endif

#if (DCM_STATE_AUTHENTICATION_ENABLED == STD_ON)
/*! NvM data for authentication manager */
struct DCM_AUTHMGRNVMDATATYPE_TAG
{
  Dcm_AuthMgrConnContextType  ConnContext[DCM_AUTHMGR_NUM_AUTH_CONNECTIONS];  /*!< Connection specific contexts */
};
typedef struct DCM_AUTHMGRNVMDATATYPE_TAG Dcm_AuthMgrNvMDataType;
#endif

#if (DCM_AUTHMGR_ANTI_BRUTE_FORCE_SUPPORT_ENABLED == STD_ON)
struct DCM_AUTHMGRCONNABFCONTEXTTYPE_TAG
{
  uint16 InvokingDelayTime; /*!< Delay time invoking (reload) value in ticks */
  uint8  AttemptCounter;    /*!< Number of attempts since last authentication */
};
typedef struct DCM_AUTHMGRCONNABFCONTEXTTYPE_TAG Dcm_AuthMgrAbfConnContextType;
typedef P2VAR(Dcm_AuthMgrAbfConnContextType, TYPEDEF, DCM_VAR_NOINIT) Dcm_AuthMgrAbfConnContextPtrType;
typedef P2CONST(Dcm_AuthMgrAbfConnContextType, TYPEDEF, DCM_VAR_NOINIT) Dcm_AuthMgrAbfConnContextConstPtrType;

/*! NvM data for authentication manager anti brute force prevention */
struct DCM_AUTHMGRABFNVMDATATYPE_TAG
{
  Dcm_AuthMgrAbfConnContextType AbfConnContext[DCM_AUTHMGR_NUM_AUTH_CONNECTIONS];  /*!< Connection specific anti brute force contexts */
  uint16                        MagicNumber;                                       /*!< Magic number for configuration verification */
};
typedef struct DCM_AUTHMGRABFNVMDATATYPE_TAG Dcm_AuthMgrAbfNvMDataType;
#endif

/*! Pointer to  ModeSwitchInterface DcmAuthenticationState_<DcmDslMainConnection> */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_ModeAuthStateModeSwitchOpFuncType) (uint8 nextMode);

# if (DCM_SVC_29_01_SUPPORT_ENABLED == STD_ON) || \
     (DCM_SVC_29_02_SUPPORT_ENABLED == STD_ON) || \
     (DCM_SVC_29_04_SUPPORT_ENABLED == STD_ON)
/*! Specifies whether a static certificate ID or a dynamic one across a certificate group should be used  */
struct DCM_AUTHMGRCERTGROUPINFO_TAG
{
  KeyM_CertificateIdType      CertId;       /*!< The static certificate ID in case a certificate group is not used */
#  if (DCM_AUTHMGR_CERT_GROUPS_ENABLED == STD_ON)
  KeyM_CertificateGroupIdType GroupId;      /*!< The certificate group ID to derive a dynamic certificate ID */
  boolean                     GroupIdUsed;  /*!< Whether a certificate group is used or a static certificate ID */
#  endif
};
typedef struct DCM_AUTHMGRCERTGROUPINFO_TAG Dcm_AuthMgrCertGroupInfoType;
typedef P2CONST(Dcm_AuthMgrCertGroupInfoType, TYPEDEF, DCM_CONST) Dcm_AuthMgrCertGroupInfoPtrType;
# endif

# if (DCM_SVC_29_01_SUPPORT_ENABLED == STD_ON) || \
     (DCM_SVC_29_02_SUPPORT_ENABLED == STD_ON)
/*! Connection specific authentication info */
struct DCM_CFGAUTHMGRNETCONNINFOTYPE_TAG
{
  Dcm_ModeAuthStateModeSwitchOpFuncType AuthStateModeSwitchOpFunc;  /*!< ModeSwitch DcmAuthenticationState_<DcmDslMainConnection> */
# if (DCM_AUTHMGR_EPHEMERAL_KEY_SUPPORT_ENABLED == STD_ON)
  uint32                                EpkPublicJobId;             /*!< The CSM job id for the calculation of the public part of the EPK */
  uint32                                EpkSecretJobId;             /*!< The CSM job id for the storage of the secret part of the EPK */
  uint32                                EpkServerLength;            /*!< The ephemeral key length for this connection - implies whether the EPK is used or not*/
# endif
# if (DCM_SVC_29_02_SUPPORT_ENABLED == STD_ON)
  uint32                                SignClientChallengeJobId;   /*!< The CSM job ID for the signing the client challenge */
  uint16                                EcuCertificateId;           /*!< The KEYM ID for the ECU certificate */
# endif
  Dcm_AuthMgrCertGroupInfoType          CertGroupInfo;              /*!< Whether a static or dynamic certificate ID is used */
};
typedef struct DCM_CFGAUTHMGRNETCONNINFOTYPE_TAG Dcm_CfgAuthMgrNetConnInfoType;
typedef P2CONST(Dcm_CfgAuthMgrNetConnInfoType, TYPEDEF, DCM_CONST) Dcm_CfgAuthMgrNetConnInfoPtrType;
#endif

# if (DCM_SVC_29_01_SUPPORT_ENABLED == STD_ON) || \
     (DCM_SVC_29_02_SUPPORT_ENABLED == STD_ON)
/*! Authentication certificate specific info */
struct DCM_CFGAUTHMGRCERTINFOTYPE_TAG
{
  uint32                 EcuChallengeLength;                        /*!< Length of the ECU challenge */
# if (DCM_SVC_29_CUSTOM_CHALLENGE_SERVER_ENABLED == STD_OFF)
  uint32                 RandomJobId;                               /*!< The CSM job ID for the random generator */
# endif
# if (DCM_SVC_29_CUSTOM_POWN_ENABLED == STD_OFF)
  uint32                 ProofOfOwnershipJobId;                     /*!< The CSM job ID for the proof of ownership */
# endif
  KeyM_CertificateIdType CertId;                                    /*!< The KEYM Certificate ID */
  uint16                 CertRoleId;                                /*!< The KEYM ID for the role certificate element */
# if (DCM_AUTHMGR_WHITELIST_SERVICES_ENABLED == STD_ON)
  uint16                 CertWLServicesId;                          /*!< The KEYM ID for the services white list certificate element */
# endif
# if (DCM_AUTHMGR_WHITELIST_DID_ENABLED == STD_ON)
  uint16                 CertWLDidId;                               /*!< The KEYM ID for the DID white list certificate element */
# endif
# if (DCM_AUTHMGR_WHITELIST_RID_ENABLED == STD_ON)
  uint16                 CertWLRidId;                               /*!< The KEYM ID for the RID white list certificate element */
# endif
# if (DCM_AUTHMGR_WHITELIST_MEM_ENABLED == STD_ON)
  uint16                 CertWLMemId;                               /*!< The KEYM ID for the memory selection white list certificate element */
# endif
};
typedef struct DCM_CFGAUTHMGRCERTINFOTYPE_TAG Dcm_CfgAuthMgrCertInfoType;
typedef P2CONST(Dcm_CfgAuthMgrCertInfoType, TYPEDEF, DCM_CONST) Dcm_CfgAuthMgrCertInfoPtrType;
#endif

#if (DCM_SVC_29_04_SUPPORT_ENABLED == STD_ON)
typedef uint8 Dcm_AuthMgrCertFunctionType;

/*! Transmit certificate specific info*/
struct DCM_CFGAUTHMGRTRANSMITCERTIFICATEINFOTYPE_TAG
{
  Dcm_AuthMgrCertGroupInfoType  CertGroupInfo;  /*!< Whether a static or dynamic certificate ID is used */
  Dcm_AuthMgrCertFunctionType   Function;       /*!< The Certificate function type can be of type Secure Coding or OTHER */
};
typedef struct DCM_CFGAUTHMGRTRANSMITCERTIFICATEINFOTYPE_TAG Dcm_CfgAuthMgrTransmitCertificateInfoType;
typedef P2CONST(Dcm_CfgAuthMgrTransmitCertificateInfoType, TYPEDEF, DCM_CONST) Dcm_CfgAuthMgrTransmitCertificateInfoPtrType;
#endif
# endif /* (DCM_AUTHMGR_SUPPORT_ENABLED == STD_ON) */
# if (DCM_SVC_01_SUPPORT_ENABLED == STD_ON)
/*! Function pointer prototype for a PID handler */
typedef P2FUNC(Std_ReturnType, DCM_CODE, Dcm_Svc01OpFuncType)(Dcm_MsgType Data);

/*! Diagnostic service 0x01 configuration data */
struct DCM_CFGSVC01DATAINFOTYPE_TAG
{
  Dcm_Svc01OpFuncType  OpFunc;    /*!< Pointer to the PID handler */
  uint16               ResLength; /*!< Response data length without PID */
};
typedef struct DCM_CFGSVC01DATAINFOTYPE_TAG Dcm_CfgSvc01ServiceInfoType;
typedef P2CONST(Dcm_CfgSvc01ServiceInfoType, TYPEDEF, DCM_CONST) Dcm_CfgSvc01ServiceInfoPtrType;
# endif /* (DCM_SVC_01_SUPPORT_ENABLED == STD_ON) */
typedef uint8 Dcm_CfgSvc06Mid2TidRefMemType;
typedef uint8_least Dcm_CfgSvc06Mid2TidRefOptType;
# if (DCM_SVC_06_SUPPORT_ENABLED == STD_ON) && (DCM_OBDIDMGR_OBDMID_SUPPORT_BY_DCM_ENABLED == STD_ON)
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_Svc06MidTidOpFuncType) (Dcm_OpStatusType opStatus          /* opStatus */
                                                                         ,Dcm_Uint16VarDataPtrType testValue /* testValue */
                                                                         ,Dcm_Uint16VarDataPtrType minValue  /* minValue */
                                                                         ,Dcm_Uint16VarDataPtrType maxValue  /* maxValue */
                                                                         ,Dcm_Uint8VarDataPtrType status     /* status */);

/*! Information type for MIDs and TIDs */
struct DCM_CFGSVC06SERVICEINFOTYPE_TAG
{
  Dcm_Svc06MidTidOpFuncType  OpFunc; /*!< Pointer to the Mid Tid handler */
  uint8                      Uasid;  /*!< Unit and scaling identifier to be put on the tester response */
  uint8                      Tid;    /*!< Tester identifier to be put on the tester response */
};
typedef struct DCM_CFGSVC06SERVICEINFOTYPE_TAG Dcm_CfgSvc06MidTidInfoType;
typedef P2CONST(Dcm_CfgSvc06MidTidInfoType, TYPEDEF, DCM_CONST) Dcm_CfgSvc06MidTidInfoPtrType;
# endif /* (DCM_SVC_06_SUPPORT_ENABLED == STD_ON) && (DCM_OBDIDMGR_OBDMID_SUPPORT_BY_DCM_ENABLED == STD_ON) */
# if (DCM_SVC_08_SUPPORT_ENABLED == STD_ON)
/*! Function pointer prototype for a Request-Control handler */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_Svc08OpFuncType) (Dcm_MsgType resData, Dcm_ReadOnlyMsgType reqData);

/*! Diagnostic service 0x08 configuration data */
struct DCM_CFGSVC08SERVICEINFOTYPE_TAG
{
  Dcm_Svc08OpFuncType OpFunc;     /*!< Pointer to the Request-Control handler */
  uint16              ReqLength;  /*!< Request data length without TID */
  uint16              ResLength;  /*!< Response data length without TID */
};
typedef struct DCM_CFGSVC08SERVICEINFOTYPE_TAG Dcm_CfgSvc08ServiceInfoType;
typedef P2CONST(Dcm_CfgSvc08ServiceInfoType, TYPEDEF, DCM_CONST)  Dcm_CfgSvc08ServiceInfoPtrType;
# endif /* (DCM_SVC_08_SUPPORT_ENABLED == STD_ON) */
# if (DCM_SVC_09_SUPPORT_ENABLED == STD_ON)
/*! Function pointer prototype for a VID handler */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_Svc09OpFuncType) (Dcm_OpStatusType opStatus
                                                                   ,Dcm_MsgType DataValueBuffer
#if (DCM_DCM_AR_VERSION >= DCM_DCM_AR_VERSION_422)
                                                                   ,Dcm_Uint8VarDataPtrType DataValueBufferSize
#endif
                                                                   );

/*! Diagnostic service 0x09 configuration data */
struct DCM_CFGSVC09SERVICEINFOTYPE_TAG
{
  Dcm_Svc09OpFuncType OpFunc;     /*!< Pointer to the VID handler */
  uint8               ResLength;  /*!< Response data length without VID */
};
typedef struct DCM_CFGSVC09SERVICEINFOTYPE_TAG Dcm_CfgSvc09ServiceInfoType;
typedef P2CONST(Dcm_CfgSvc09ServiceInfoType, TYPEDEF, DCM_CONST) Dcm_CfgSvc09ServiceInfoPtrType;
# endif /* (DCM_SVC_09_SUPPORT_ENABLED == STD_ON) */
/*! Diagnostic service 0x10 sub-function (diagnostic session) configuration data */
struct DCM_CFGSVC10SUBFUNCINFOTYPE_TAG
{
  Dcm_Svc10P2TimingsType   ResponseTime;    /*!< P2 timings to be reported in the positive response */
#if (DCM_SVC_10_JMP2BOOT_ENABLED == STD_ON)
  Dcm_Svc10SessionBootType BootType;        /*!< Bootloader interaction type (Valid values: DCM_SVC10_BOOT_TYPE_*) */
#endif
};
typedef struct DCM_CFGSVC10SUBFUNCINFOTYPE_TAG Dcm_CfgSvc10SubFuncInfoType;
# if (DCM_SVC_11_SUPPORT_ENABLED == STD_ON)
typedef uint8 Dcm_Svc11ResponseType;

/*! Diagnostic service 0x11 sub-function information */
struct DCM_CFGSVC11SUBFUNCINFOTYPE_TAG
{
  Dcm_DiagSvcProcessorFuncType      SubSvcFunc;   /*!< The sub-function processor */
#if (DCM_SVC_11_RST2BOOT_HIS_ENABLED == STD_ON)
  Dcm_Svc11ResponseType             ResponseType; /*!< The sub-function response type */
#endif
};
typedef struct DCM_CFGSVC11SUBFUNCINFOTYPE_TAG Dcm_CfgSvc11SubFuncInfoType;
typedef P2CONST(Dcm_CfgSvc11SubFuncInfoType, TYPEDEF, DCM_CONST) Dcm_CfgSvc11SubFuncInfoPtrType;
# endif /* (DCM_SVC_11_SUPPORT_ENABLED == STD_ON) */
# if (DCM_SVC_19_SUPPORT_ENABLED == STD_ON)
/*! Diagnostic service 0x19 sub-function configuration data */
struct DCM_CFGSVC19SUBFUNCINFOTYPE_TAG
{
  Dcm_DiagSvcProcessorFuncType      SubSvcFunc; /*!< Pointer to the sub-function handler */
  uint8                             ReqLength;  /*!< Diagnostic service request length (sub-function and data): 0 - dynamic length, !=0 - concrete length (no ISO 14229-1 SF is longer than 255 bytes) */
};
typedef struct DCM_CFGSVC19SUBFUNCINFOTYPE_TAG Dcm_CfgSvc19SubFuncInfoType;
typedef P2CONST(Dcm_CfgSvc19SubFuncInfoType, TYPEDEF, DCM_CONST) Dcm_CfgSvc19SubFuncInfoPtrType;
# endif /* (DCM_SVC_19_SUPPORT_ENABLED == STD_ON) */
# if (DCM_SVC_27_SUPPORT_ENABLED == STD_ON)
typedef uint8 Dcm_Svc27OpClassType;

/*! Generic function pointer prototype for a Get-Seed handler */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_Svc27GetSeedFuncType)(void);

/*! Function pointer prototype for a Compare-Key handler */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_Svc27CompareKeyFuncType)(Dcm_ReadOnlyMsgType reqData
                                                                          ,Dcm_OpStatusType opStatus
                                                                          ,Dcm_NegativeResponseCodePtrType nrc);

#if (DCM_STATE_SEC_ATT_CNTR_EXT_STORAGE_ENABLED == STD_ON)
/*! Function pointer prototype for a Get-Security-Attempt-Counter handler */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_Svc27GetAttemptCntrFuncType)(Dcm_OpStatusType opStatus
                                                                              ,P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) attemptCount);

/*! Function pointer prototype for a Set-Security-Attempt-Counter handler */
typedef P2FUNC(Std_ReturnType, DCM_APPL_CODE, Dcm_Svc27SetAttemptCntrFuncType)(Dcm_OpStatusType opStatus
                                                                              ,uint8 attemptCount);
#endif

/*! Security level specific configuration data */
struct DCM_CFGSVC27SECLEVELINFOTYPE_TAG
{
  Dcm_Svc27GetSeedFuncType         GetSeedFunc;         /*!< Pointer to the Get-Seed handler */
  Dcm_Svc27CompareKeyFuncType      CompareKeyFunc;      /*!< Pointer to the Compare-Key handler */
#if (DCM_STATE_SEC_ATT_CNTR_EXT_STORAGE_ENABLED == STD_ON)
  Dcm_Svc27GetAttemptCntrFuncType  GetAttemptCntrFunc;  /*!< Pointer to the Get-Security-Attempt-Counter handler */
  Dcm_Svc27SetAttemptCntrFuncType  SetAttemptCntrFunc;  /*!< Pointer to the Set-Security-Attempt-Counter handler */
#endif
  Dcm_CfgNetBufferSizeMemType      SeedLength;          /*!< Seed response length */
  Dcm_CfgNetBufferSizeMemType      KeyLength;           /*!< Key length */
  Dcm_CfgNetBufferSizeMemType      AdrLength;           /*!< ADR length */
  Dcm_Svc27OpClassType             GetSeedFuncClass;    /*!< Get-Seed function prototype descriptor */
};
typedef struct DCM_CFGSVC27SECLEVELINFOTYPE_TAG Dcm_CfgSvc27SecLevelInfoType;
typedef P2CONST(Dcm_CfgSvc27SecLevelInfoType, TYPEDEF, DCM_CONST)  Dcm_CfgSvc27SecLevelInfoPtrType;
# endif /* (DCM_SVC_27_SUPPORT_ENABLED == STD_ON) */
# if (DCM_SVC_28_SUPPORT_ENABLED == STD_ON)
/*! Diagnostic service 0x28 sub-function configuration data */
struct DCM_CFGSVC28SUBFUNCINFOTYPE_TAG
{
  Dcm_DiagSvcProcessorFuncType      SubSvcFunc; /*!< Pointer to the sub-function handler */
  uint8                             ReqLength;  /*!< Diagnostic service request length (sub-function and data): 0 - dynamic length, !=0 - concrete length (no ISO 14229-1 SF is longer than 255 bytes) */
};
typedef struct DCM_CFGSVC28SUBFUNCINFOTYPE_TAG Dcm_CfgSvc28SubFuncInfoType;
typedef P2CONST(Dcm_CfgSvc28SubFuncInfoType, TYPEDEF, DCM_CONST) Dcm_CfgSvc28SubFuncInfoPtrType;
# endif /* (DCM_SVC_28_SUPPORT_ENABLED == STD_ON) */
# if (DCM_SVC_2C_SUPPORT_ENABLED == STD_ON)
/* Define by DID properties */
#if (DCM_SVC_2C_01_SUPPORT_ENABLED == STD_ON)
typedef uint8 Dcm_Svc2CSrcDidOffsetType;
typedef uint8 Dcm_Svc2CSrcDidSizeType;
#endif
typedef Dcm_UtiBitSetBaseType Dcm_Svc2CSrcClassType;

/*! Information about a DynDID */
struct DCM_SVC2CDYNDIDITEMTYPE_TAG
{
  Dcm_DidMgrDidLengthType         Length; /*!< Total length of the DynDID */
  uint8                           Count;  /*!< Number of source items */
};
typedef struct DCM_SVC2CDYNDIDITEMTYPE_TAG Dcm_Svc2CDynDidItemType;

typedef P2VAR(Dcm_Svc2CDynDidItemType, TYPEDEF, DCM_VAR_NOINIT) Dcm_Svc2CDynDidItemPtrType;
typedef P2CONST(Dcm_Svc2CDynDidItemType, TYPEDEF, DCM_VAR_NOINIT) Dcm_Svc2CDynDidItemConstPtrType;

/*! Diagnostic service 0x2C sub-function configuration data */
struct DCM_CFGSVC2CSUBFUNCINFOTYPE_TAG
{
  Dcm_DiagSvcProcessorFuncType SubSvcFunc;   /*!< The sub-function processor */
  Dcm_CfgNetBufferSizeMemType  MinReqLength; /*!< Minimum length of a request */
};
typedef struct DCM_CFGSVC2CSUBFUNCINFOTYPE_TAG Dcm_CfgSvc2CSubFuncInfoType;
typedef P2CONST(Dcm_CfgSvc2CSubFuncInfoType, TYPEDEF, DCM_CONST) Dcm_CfgSvc2CSubFuncInfoPtrType;

#if (DCM_SVC_2C_01_SUPPORT_ENABLED == STD_ON)
/*! Information about source DID of a DynDID */
struct DCM_SVC2CSRCDIDITEMINFOTYPE_TAG
{
  uint16                       SrcDid;     /*!< The requested source DID */
  Dcm_Svc2CSrcDidOffsetType    Offset;     /*!< Configured offset in DID data */
  Dcm_Svc2CSrcDidSizeType      Size;       /*!< Configured size of DID data */
};
typedef struct DCM_SVC2CSRCDIDITEMINFOTYPE_TAG Dcm_Svc2CSrcDidItemInfoType;
#endif

#if (DCM_SVC_2C_02_SUPPORT_ENABLED == STD_ON)
/*! Information about source memory item of a DynDID */
struct DCM_SVC2CSRCMEMITEMINFOTYPE_TAG
{
  Dcm_MemMgrMemBlockType MemBlock; /*!< Memory block information */
};
typedef struct DCM_SVC2CSRCMEMITEMINFOTYPE_TAG Dcm_Svc2CSrcMemItemInfoType;
#endif

/*! Information about a DynDID source */
union DCM_SVC2CDYNDIDSRCITEMTYPE_TAG
{                                                                                                                                                    /* PRQA S 0750 */ /* MD_Dcm_Rule19.2 */
#if (DCM_SVC_2C_01_SUPPORT_ENABLED == STD_ON)
  Dcm_Svc2CSrcDidItemInfoType      DidDescriptor; /*!< Descriptor for DID items */
#endif
#if (DCM_SVC_2C_02_SUPPORT_ENABLED == STD_ON)
  Dcm_Svc2CSrcMemItemInfoType      MemDescriptor; /*!< Descriptor for Memory items */
#endif
};
typedef union DCM_SVC2CDYNDIDSRCITEMTYPE_TAG Dcm_Svc2CDynDidSrcItemType;

typedef P2VAR(Dcm_Svc2CDynDidSrcItemType, TYPEDEF, DCM_VAR_NOINIT) Dcm_Svc2CDynDidSrcItemPtrType;
typedef P2CONST(Dcm_Svc2CDynDidSrcItemType, TYPEDEF, DCM_VAR_NOINIT) Dcm_Svc2CDynDidSrcItemConstPtrType;

/*! Information about the needed persisting elements of a DynDid */
struct DCM_SVC2CDYNDIDNVMDATATYPE_TAG
{
  Dcm_Svc2CDynDidSrcItemType         SrcItems[DCM_NUM_DYNDID_ITEMS];                                /*!< List of source items */
  Dcm_Svc2CSrcClassType              Sequencer[Dcm_UtiGenericBitSetCalcSize(DCM_NUM_DYNDID_ITEMS)]; /*!< BitMask of enabled source items */          /* PRQA S 1039 */ /* MD_Dcm_Rule1.2_1039 */
  Dcm_Svc2CDynDidItemType            Items[DCM_NUM_DYNDIDS];                                        /*!< List of DIDs */
#if (DCM_SVC_2C_NVRAM_SUPPORT_ENABLED == STD_ON)
  uint16                             MagicNumber;                                                   /*!< Magic number for configuration verification */
# if (DCM_VARMGR_MULTI_SVC_EXCLUSIVE_ENABLED == STD_ON)
  Dcm_CfgVarMgrDiagVariantIdMemType  CfgVariantId;                                                  /*!< Contains the CFG-criteria ID */
# endif
#endif
};
typedef struct DCM_SVC2CDYNDIDNVMDATATYPE_TAG Dcm_Svc2CDynDidNvMDataType;
# endif /* (DCM_SVC_2C_SUPPORT_ENABLED == STD_ON) */
# if (DCM_SVC_85_SUPPORT_ENABLED == STD_ON)
#if (DCM_DEMIF_421_ENABLED == STD_ON)
typedef P2FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE, Dcm_DemControlDtcSettingFuncType) (Dem_DTCGroupType DTCGroup, Dem_DTCKindType DTCKind);
#else
typedef P2FUNC(Std_ReturnType, DEM_CODE, Dcm_DemControlDtcSettingFuncType) (uint8 ClientId);
#endif

/*! Diagnostic service 0x85 sub-function configuration data */
struct DCM_CFGSVC85SUBFUNCINFOTYPE_TAG
{
  Dcm_DemControlDtcSettingFuncType  DemFunc;  /*!< Pointer to the corresponding DTCsetting state Dem API (e.g. Dem_DcmDisableDTCSetting) */
  Rte_ModeType_DcmControlDtcSetting Mode;     /*!< The corresponding mode of the DTCsetting state (Valid values: RTE_MODE_DcmControlDtcSetting_*) */
};
typedef struct DCM_CFGSVC85SUBFUNCINFOTYPE_TAG Dcm_CfgSvc85SubFuncInfoType;
typedef P2CONST(Dcm_CfgSvc85SubFuncInfoType, TYPEDEF, DCM_CONST) Dcm_CfgSvc85SubFuncInfoPtrType;
# endif /* (DCM_SVC_85_SUPPORT_ENABLED == STD_ON) */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION DECLARATIONS
 *********************************************************************************************************************/
# define DCM_START_SEC_CODE
# include "Dcm_MemMap.h"                                                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */
# if (DCM_DIDMGR_SUPPORT_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Dcm_DidMgrDidNoOp()
 *********************************************************************************************************************/
/*! \brief          Does nothing.
 *  \details        Placeholder for a signal operation which requires no action.
 *  \param[out]     data        Response data buffer
 *  \return         DCM_E_OK
 *  \context        TASK
 *  \reentrant      TRUE
 *  \pre            -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgrDidNoOp(Dcm_MsgType data);

#if (DCM_DIDMGR_NVM_READ_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Dcm_DidMgrReadNvMSignal()
 *********************************************************************************************************************/
/*! \brief          Handler to read out a NvRam Block.
 *  \details        -
 *  \param[in]      opStatus    The operation status
 *  \param[out]     data        Response data buffer
 *  \param[in]      blockId     Id of the NvRam block
 *  \return         Operation result
 *  \context        TASK
 *  \reentrant      FALSE
 *  \pre            -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgrNvMReadSignal(Dcm_OpStatusType opStatus
                                                      ,Dcm_MsgType      data
                                                      ,uint16           blockId);
#endif

#if (DCM_DIDMGR_NVM_WRITE_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Dcm_DidMgrNvMWriteSignal()
 *********************************************************************************************************************/
/*! \brief          Handler to write a NvRam block.
 *  \details        -
 *  \param[in]      data         Request data buffer
 *  \param[in]      opStatus     The operation status
 *  \param[out]     errorCode    The NRC
 *  \param[in]      blockId      Id of the NvRam block
 *  \return         Operation result
 *  \context        TASK
 *  \reentrant      FALSE
 *  \pre            -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgrNvMWriteSignal(Dcm_ReadOnlyMsgType             data
                                                       ,Dcm_OpStatusType                opStatus
                                                       ,Dcm_NegativeResponseCodePtrType errorCode
                                                       ,uint16                          blockId);
#endif

#if (DCM_DIDMGR_SR_IO_CONTROL_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Dcm_DidMgrIoCtrlSRHandler_Control()
 *********************************************************************************************************************/
/*! \brief          Handler for IO Dids with S/R Interface.
 *  \details        Handler for IO Dids with S/R Interface and operation type resetToDefault (0x01), freezeCurrentState(0x02)
 *                  or shortTermAdjustment (0x03)
 *  \param[in]      srEntryIndex    Index to table with corresponding RTE S/R callouts
 *  \param[in]      ioOperation     IO Operation type (InputOutputControlParameter of Service 0x02F)
 *  \param[in]      reqData         Request data containing the controlState in case of IO Operation shortTermAdjustment (0x03)
 *  \param[in]      opStatus        The operation status
 *  \param[in]      cemr            Control Enable Mask Record
 *  \param[out]     errorCode       The NRC
 *  \return         Operation result
 *  \context        TASK
 *  \reentrant      FALSE
 *  \pre            -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgrIoCtrlSRHandler_Control(Dcm_CfgDidMgrIoCtrlSRHandlersRefOptType srEntryIndex
                                                                ,uint8                                   ioOperation
                                                                ,Dcm_ReadOnlyMsgType                     reqData
                                                                ,Dcm_OpStatusType                        opStatus
                                                                ,uint32                                  cemr
                                                                ,Dcm_NegativeResponseCodePtrType         errorCode);
#endif

#if (DCM_DIDMGR_SR_IO_CONTROL_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Dcm_DidMgrIoCtrlSRHandler_Reset()
 *********************************************************************************************************************/
/*! \brief          Handler for IO Dids with S/R Interface.
 *  \details        Handler for IO Dids with S/R Interface and operation type returnControlToEcu (0x00)
 *  \param[in]      srEntryIndex    Index to table with corresponding RTE S/R callouts
 *  \param[in]      cemr            Control Enable Mask Record
 *  \param[out]     errorCode       The NRC
 *  \return         Operation result
 *  \context        TASK
 *  \reentrant      FALSE
 *  \pre            -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) Dcm_DidMgrIoCtrlSRHandler_Reset(Dcm_CfgDidMgrIoCtrlSRHandlersRefOptType srEntryIndex
                                                              ,uint32                                  cemr
                                                              ,Dcm_NegativeResponseCodePtrType         errorCode);
#endif
# endif /* (DCM_DIDMGR_SUPPORT_ENABLED == STD_ON) */
# if (DCM_RIDMGR_SUPPORT_ENABLED == STD_ON)
#if (DCM_RIDMGR_SECURE_CODING_ENABLED == STD_ON)
/***********************************************************************************************************************
 *  Dcm_RidMgr_SecureCodingValidation_Start()
 ***********************************************************************************************************************/
/*! \brief         Processes the Secure Coding Validation routine
 *  \details       Writes all the Secure Coding DIDs which are written previously by service 0x2E into the Secure
 *                 Coding buffer.
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    DataLength         The length of the output data - not used
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_LOOP         Repeat immediately
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) Dcm_RidMgr_SecureCodingValidation_Start(
  Dcm_OpStatusType opStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
#endif
# endif /* (DCM_RIDMGR_SUPPORT_ENABLED == STD_ON) */
# if (DCM_OBDUDSIDMGR_SUPPORT_ENABLED == STD_ON)
#if (DCM_VARMGR_MULTI_SVC_ANY_ENABLED == STD_ON) && \
    (DCM_DIDMGR_SUPPORT_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Dcm_ObdIdMgrGetDidAvailabilityMask()
 *********************************************************************************************************************/
/*! \brief          OBD availability DID (AID) mask value provider.
 *  \details        Calculates the 32bit mask value for PBS/PBL/CALIBRATABLE_OBD and pre-compile
 *  \param[in]      DidLookUpRefStart    The index of the first element in the DID look-up table the AID shall report.
 *  \param[in]      DidLookUpRefEnd      The index of the last element in the DID look-up table the AID shall report.
 *  \param[in]      maskValue            The offline generated/calibratable mask value
 *  \return         The 32 bit bitmap value
 *  \context        ISR1|ISR2|TASK
 *  \reentrant      TRUE
 *  \pre            -
 *********************************************************************************************************************/
FUNC(uint32, DCM_CODE) Dcm_ObdIdMgrGetDidAvailabilityMask(uint16 DidLookUpRefStart
                                                         ,uint16 DidLookUpRefEnd
                                                         ,Dcm_ObdIdMgrMaskValueTableType maskValue);
#else
/* Just return the offline calculated/calibrated mask */
# define Dcm_ObdIdMgrGetDidAvailabilityMask(DidLookUpRefStart, DidLookUpRefEnd, maskValue) (maskValue)                                               /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

#if (DCM_VARMGR_MULTI_SVC_ANY_ENABLED == STD_ON) && \
    (DCM_RIDMGR_SUPPORT_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Dcm_ObdIdMgrGetRidAvailabilityMask()
 *********************************************************************************************************************/
/*! \brief          OBD availability RID (AID) mask value provider.
 *  \details        Calculates the 32bit mask value for PBS/PBL/CALIBRATABLE_OBD and pre-compile
 *  \param[in]      RidLookUpRefStart    The index of the first element in the RID look-up table the AID shall report.
 *  \param[in]      RidLookUpRefEnd      The index of the last element in the RID look-up table the AID shall report.
 *  \param[in]      maskValue            The offline generated/calibratable mask value
 *  \return         The 32 bit bitmap value
 *  \context        ISR1|ISR2|TASK
 *  \reentrant      TRUE
 *  \pre            -
 *********************************************************************************************************************/
FUNC(uint32, DCM_CODE) Dcm_ObdIdMgrGetRidAvailabilityMask(uint16 RidLookUpRefStart
                                                         ,uint16 RidLookUpRefEnd
                                                         ,Dcm_ObdIdMgrMaskValueTableType maskValue);
#else
/* Just return the offline calculated/calibrated mask */
# define Dcm_ObdIdMgrGetRidAvailabilityMask(RidLookUpRefStart, RidLookUpRefEnd, maskValue) (maskValue)                                               /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

#if (DCM_OBDUDSIDMGR_UDSMID_SUPPORT_BY_DCM_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Dcm_ObdIdMgrReadUdsMid()
 *********************************************************************************************************************/
/*! \brief          OBD Service "supported ID" reader.
 *  \details        -
 *  \param[in]      handle      The handle
 *  \param[in]      opStatus    The operation status
 *  \param[in]      pDataContext Pointer to the data context
 *  \return         Operation result
 *  \context        TASK
 *  \reentrant      TRUE
 *  \pre            -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) Dcm_ObdIdMgrReadUdsMid(Dcm_ObdIdMgrHandleMemType handle
                                                     ,Dcm_OpStatusType opStatus
                                                     ,Dcm_DiagDataContextPtrType pDataContext);
#endif
# endif /* (DCM_OBDUDSIDMGR_SUPPORT_ENABLED == STD_ON) */
# if (DCM_SVC_2C_SUPPORT_ENABLED == STD_ON)
#if (DCM_DIDMGR_DYNDID_SRCITEM_CHECK_COND_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  Dcm_Svc2CDefMgrConditionCheckRead()
 *********************************************************************************************************************/
/*! \brief          Common DynDID check read condition operation.
 *  \details        -
 *  \param[in]      dynDidHandle    DynDID reference to be read
 *  \param[in]      opStatus        Current operation status
 *  \param[out]     errorCode       Returns an error if any
 *  \return         Next action to perform
 *  \context        TASK
 *  \reentrant      FALSE
 *  \pre            -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) Dcm_Svc2CDefMgrConditionCheckRead(Dcm_CfgDidMgrDynDidHandleMemType dynDidHandle
                                                                ,Dcm_OpStatusType opStatus
                                                                ,Dcm_NegativeResponseCodePtrType errorCode);
#endif
/**********************************************************************************************************************
 *  Dcm_Svc2CDefMgrRead()
 *********************************************************************************************************************/
/*! \brief          Common DynDID reader operation.
 *  \details        -
 *  \param[in]      dynDidHandle    DynDID reference to be read
 *  \param[in]      opStatus        Current operation status
 *  \param[in,out]  pDataContext    Pointer to the data context
 *  \return         Next action to perform
 *  \context        TASK
 *  \reentrant      FALSE
 *  \pre            -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) Dcm_Svc2CDefMgrRead(Dcm_CfgDidMgrDynDidHandleMemType dynDidHandle
                                                  ,Dcm_OpStatusType opStatus
                                                  ,Dcm_DiagDataContextPtrType pDataContext);

/**********************************************************************************************************************
 *  Dcm_Svc2CDefMgrReadDataLength()
 *********************************************************************************************************************/
/*! \brief          Common DynDID reader operation.
 *  \details        -
 *  \param[in]      dynDidHandle    DynDID reference to be read
 *  \param[out]     dataLength      Returns the current DynDID length
 *  \return         Next action to perform
 *  \context        TASK
 *  \reentrant      FALSE
 *  \pre            -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CODE) Dcm_Svc2CDefMgrReadDataLength(Dcm_CfgDidMgrDynDidHandleMemType dynDidHandle
                                                            ,Dcm_DidMgrDidLengthPtrType dataLength);
# endif /* (DCM_SVC_2C_SUPPORT_ENABLED == STD_ON) */
# define DCM_STOP_SEC_CODE
# include "Dcm_MemMap.h"                                                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define DCM_START_SEC_CALLOUT_CODE
# include "Dcm_MemMap.h"                                                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  Dcm_ModeOnComControlModeChange()
***********************************************************************************************************************/
/*! \brief         Notifies the SW-C(s) for a CommunicationControl state transition on the ComMChannel.
 *  \details       Uses the mode declaration group values e.g.
 *                 RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NM.
 *  \param[in]     channelId  The channel identifier
 *  \param[in]     mode       The mode transited to
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
***********************************************************************************************************************/
FUNC(void, DCM_CODE) Dcm_ModeOnComControlModeChange(NetworkHandleType channelId, Dcm_CommunicationModeType mode);

/***********************************************************************************************************************
 *  Dcm_Service10Processor()
 ***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     threadId           The active thread identifier
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service10Processor(
  Dcm_ThreadIdType threadId,
  Dcm_OpStatusType opStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_Service11Processor()
 ***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     threadId           The active thread identifier
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service11Processor(
  Dcm_ThreadIdType threadId,
  Dcm_OpStatusType opStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_Service14Processor()
 ***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     threadId           The active thread identifier
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service14Processor(
  Dcm_ThreadIdType threadId,
  Dcm_OpStatusType opStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_Service19Processor()
 ***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     threadId           The active thread identifier
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service19Processor(
  Dcm_ThreadIdType threadId,
  Dcm_OpStatusType opStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_Service22Processor()
 ***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     threadId           The active thread identifier
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service22Processor(
  Dcm_ThreadIdType threadId,
  Dcm_OpStatusType opStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_Service27Init()
 ***********************************************************************************************************************/
/*! \brief         Initializes service 0x27 processing.
 *  \details       -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(void, DCM_CODE) Dcm_Service27Init(void);
/***********************************************************************************************************************
 *  Dcm_Service27Processor()
 ***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     threadId           The active thread identifier
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service27Processor(
  Dcm_ThreadIdType threadId,
  Dcm_OpStatusType opStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_Service28Processor()
 ***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     threadId           The active thread identifier
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service28Processor(
  Dcm_ThreadIdType threadId,
  Dcm_OpStatusType opStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_Service2EProcessor()
 ***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     threadId           The active thread identifier
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service2EProcessor(
  Dcm_ThreadIdType threadId,
  Dcm_OpStatusType opStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_Service31Processor()
 ***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     threadId           The active thread identifier
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service31Processor(
  Dcm_ThreadIdType threadId,
  Dcm_OpStatusType opStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_Service34Processor()
 ***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     threadId           The active thread identifier
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service34Processor(
  Dcm_ThreadIdType threadId,
  Dcm_OpStatusType opStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_Service36Processor()
 ***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     threadId           The active thread identifier
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service36Processor(
  Dcm_ThreadIdType threadId,
  Dcm_OpStatusType opStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_Service37Processor()
 ***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     threadId           The active thread identifier
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service37Processor(
  Dcm_ThreadIdType threadId,
  Dcm_OpStatusType opStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_Service3EProcessor()
 ***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     threadId           The active thread identifier
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service3EProcessor(
  Dcm_ThreadIdType threadId,
  Dcm_OpStatusType opStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_Service85Processor()
 ***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic service, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc.
 *  \param[in]     threadId           The active thread identifier
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *                                    The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  (Vendor extension) Forces a RCR-RP response.
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service85Processor(
  Dcm_ThreadIdType threadId,
  Dcm_OpStatusType opStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_Service10PostProcessor()
 ***********************************************************************************************************************/
/*! \brief         Finalizes the service processing.
 *  \details       Triggers a mode switch, performs a state transition or executes other actions depending on the
 *                 concrete diagnostic service.
 *  \param[in]     threadId  The active thread identifier
 *  \param[in]     status    The post-processing status
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) Dcm_Service10PostProcessor(
  Dcm_ThreadIdType threadId,
  Dcm_ConfirmationStatusType status
  );
/***********************************************************************************************************************
 *  Dcm_Service10FastPostProcessor()
 ***********************************************************************************************************************/
/*! \brief         Finalizes the service processing.
 *  \details       Processes time critical diagnostic service specific operations immediately after confirmation of
 *                 service processing.
 *  \param[in]     threadId  The active thread identifier
 *  \param[in]     status    The post-processing status
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) Dcm_Service10FastPostProcessor(
  Dcm_ThreadIdType threadId,
  Dcm_ConfirmationStatusType status
  );
/***********************************************************************************************************************
 *  Dcm_Service11PostProcessor()
 ***********************************************************************************************************************/
/*! \brief         Finalizes the service processing.
 *  \details       Triggers a mode switch, performs a state transition or executes other actions depending on the
 *                 concrete diagnostic service.
 *  \param[in]     threadId  The active thread identifier
 *  \param[in]     status    The post-processing status
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) Dcm_Service11PostProcessor(
  Dcm_ThreadIdType threadId,
  Dcm_ConfirmationStatusType status
  );
/***********************************************************************************************************************
 *  Dcm_Service11FastPostProcessor()
 ***********************************************************************************************************************/
/*! \brief         Finalizes the service processing.
 *  \details       Processes time critical diagnostic service specific operations immediately after confirmation of
 *                 service processing.
 *  \param[in]     threadId  The active thread identifier
 *  \param[in]     status    The post-processing status
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) Dcm_Service11FastPostProcessor(
  Dcm_ThreadIdType threadId,
  Dcm_ConfirmationStatusType status
  );
/***********************************************************************************************************************
 *  Dcm_Service19PostProcessor()
 ***********************************************************************************************************************/
/*! \brief         Finalizes the service processing.
 *  \details       Triggers a mode switch, performs a state transition or executes other actions depending on the
 *                 concrete diagnostic service.
 *  \param[in]     threadId  The active thread identifier
 *  \param[in]     status    The post-processing status
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) Dcm_Service19PostProcessor(
  Dcm_ThreadIdType threadId,
  Dcm_ConfirmationStatusType status
  );
/***********************************************************************************************************************
 *  Dcm_Service22PostProcessor()
 ***********************************************************************************************************************/
/*! \brief         Finalizes the service processing.
 *  \details       Triggers a mode switch, performs a state transition or executes other actions depending on the
 *                 concrete diagnostic service.
 *  \param[in]     threadId  The active thread identifier
 *  \param[in]     status    The post-processing status
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) Dcm_Service22PostProcessor(
  Dcm_ThreadIdType threadId,
  Dcm_ConfirmationStatusType status
  );
/***********************************************************************************************************************
 *  Dcm_Service27PostProcessor()
 ***********************************************************************************************************************/
/*! \brief         Finalizes the service processing.
 *  \details       Triggers a mode switch, performs a state transition or executes other actions depending on the
 *                 concrete diagnostic service.
 *  \param[in]     threadId  The active thread identifier
 *  \param[in]     status    The post-processing status
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) Dcm_Service27PostProcessor(
  Dcm_ThreadIdType threadId,
  Dcm_ConfirmationStatusType status
  );
/***********************************************************************************************************************
 *  Dcm_Service28PostProcessor()
 ***********************************************************************************************************************/
/*! \brief         Finalizes the service processing.
 *  \details       Triggers a mode switch, performs a state transition or executes other actions depending on the
 *                 concrete diagnostic service.
 *  \param[in]     threadId  The active thread identifier
 *  \param[in]     status    The post-processing status
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) Dcm_Service28PostProcessor(
  Dcm_ThreadIdType threadId,
  Dcm_ConfirmationStatusType status
  );
/***********************************************************************************************************************
 *  Dcm_Service85PostProcessor()
 ***********************************************************************************************************************/
/*! \brief         Finalizes the service processing.
 *  \details       Triggers a mode switch, performs a state transition or executes other actions depending on the
 *                 concrete diagnostic service.
 *  \param[in]     threadId  The active thread identifier
 *  \param[in]     status    The post-processing status
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) Dcm_Service85PostProcessor(
  Dcm_ThreadIdType threadId,
  Dcm_ConfirmationStatusType status
  );
/***********************************************************************************************************************
 *  Dcm_Service19Updater()
 ***********************************************************************************************************************/
/*! \brief         Provides service specific data to the paged buffer.
 *  \details       -
 *  \param[in]     threadId                  The active thread identifier
 *  \param[in]     opStatus                  The operation status
 *  \param[in,out] pDataContext              Pointer to the data context
 *  \param[out]    ErrorCode                 Negative response code
 *  \return        DCM_E_OK                  Operation finished with success. Do not call again
 *  \return        DCM_E_NOT_OK              Operation failed. Take the NRC from ErrorCode. Do not call again
 *  \return        DCM_E_PENDING             Some data written/committed. Call again to fill in more data
 *  \return        DCM_E_BUFFERTOOLOW        Maximum available space used but was not enough.
 *                                           Call again when some additional free space available
 *  \return        DCM_E_DATA_READY_PADDING  No more data to be provided.
 *                                           Do not call again. If needed, switch to padding-byte data provider
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service19Updater(
  Dcm_ThreadIdType threadId,
  Dcm_OpStatusType opStatus,
  Dcm_DiagDataContextPtrType pDataContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_Service14Cancel()
 ***********************************************************************************************************************/
/*! \brief         Cancels an ongoing service processing.
 *  \details       -
 *  \param[in]     threadId      The active thread identifier
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) Dcm_Service14Cancel(
  Dcm_ThreadIdType threadId
  );
/***********************************************************************************************************************
 *  Dcm_Service19Cancel()
 ***********************************************************************************************************************/
/*! \brief         Cancels an ongoing service processing.
 *  \details       -
 *  \param[in]     threadId      The active thread identifier
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) Dcm_Service19Cancel(
  Dcm_ThreadIdType threadId
  );
/***********************************************************************************************************************
 *  Dcm_Service22Cancel()
 ***********************************************************************************************************************/
/*! \brief         Cancels an ongoing service processing.
 *  \details       -
 *  \param[in]     threadId      The active thread identifier
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) Dcm_Service22Cancel(
  Dcm_ThreadIdType threadId
  );
/***********************************************************************************************************************
 *  Dcm_Service85Cancel()
 ***********************************************************************************************************************/
/*! \brief         Cancels an ongoing service processing.
 *  \details       -
 *  \param[in]     threadId      The active thread identifier
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(void, DCM_CALLOUT_CODE) Dcm_Service85Cancel(
  Dcm_ThreadIdType threadId
  );
/***********************************************************************************************************************
 *  Dcm_RepeaterDeadEnd()
 ***********************************************************************************************************************/
/*! \brief         Dummy repeater proxy.
 *  \details       -
 *  \param[in]     threadId             The active thread identifier
 *  \param[in]     opStatus             The operation status
 *  \param[in,out] pMsgContext          Message-related information for one diagnostic protocol identifier
 *  \param[out]    ErrorCode            Negative response code
 *  \return        DCM_E_STOP_REPEATER  Stops the repeater proxy
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RepeaterDeadEnd(
  Dcm_ThreadIdType threadId,
  Dcm_OpStatusType opStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_Service11_01Processor()
 ***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic sub-service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic sub-service, configured to be
 *                 handled by a CDD, is received. All of the relevant diagnostic request parameter information is
 *                 forwarded by DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSubService/DcmDsdSubServiceFnc.
 *  \param[in]     threadId             The active thread identifier
 *  \param[in]     opStatus             The operation status
 *  \param[in,out] pMsgContext          Message-related information for one diagnostic protocol identifier
 *                                      The pointers in pMsgContext points behind the sub-function.
 *  \param[out]    ErrorCode            Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK             Job processing finished, send positive response
 *  \return        DCM_E_PENDING        Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP    (Vendor extension) Forces a RCR-RP response.
 *                                      The call out will called again once the response is sent. The OpStatus parameter
 *                                      will contain the transmission result
 *  \return        DCM_E_STOP_REPEATER  Stops the repeater proxy
 *  \return        DCM_E_NOT_OK         Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service11_01Processor(
  Dcm_ThreadIdType threadId,
  Dcm_OpStatusType opStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_Service11_03Processor()
 ***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic sub-service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic sub-service, configured to be
 *                 handled by a CDD, is received. All of the relevant diagnostic request parameter information is
 *                 forwarded by DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSubService/DcmDsdSubServiceFnc.
 *  \param[in]     threadId             The active thread identifier
 *  \param[in]     opStatus             The operation status
 *  \param[in,out] pMsgContext          Message-related information for one diagnostic protocol identifier
 *                                      The pointers in pMsgContext points behind the sub-function.
 *  \param[out]    ErrorCode            Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK             Job processing finished, send positive response
 *  \return        DCM_E_PENDING        Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP    (Vendor extension) Forces a RCR-RP response.
 *                                      The call out will called again once the response is sent. The OpStatus parameter
 *                                      will contain the transmission result
 *  \return        DCM_E_STOP_REPEATER  Stops the repeater proxy
 *  \return        DCM_E_NOT_OK         Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service11_03Processor(
  Dcm_ThreadIdType threadId,
  Dcm_OpStatusType opStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_Service19_02Processor()
 ***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic sub-service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic sub-service, configured to be
 *                 handled by a CDD, is received. All of the relevant diagnostic request parameter information is
 *                 forwarded by DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSubService/DcmDsdSubServiceFnc.
 *  \param[in]     threadId             The active thread identifier
 *  \param[in]     opStatus             The operation status
 *  \param[in,out] pMsgContext          Message-related information for one diagnostic protocol identifier
 *                                      The pointers in pMsgContext points behind the sub-function.
 *  \param[out]    ErrorCode            Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK             Job processing finished, send positive response
 *  \return        DCM_E_PENDING        Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP    (Vendor extension) Forces a RCR-RP response.
 *                                      The call out will called again once the response is sent. The OpStatus parameter
 *                                      will contain the transmission result
 *  \return        DCM_E_STOP_REPEATER  Stops the repeater proxy
 *  \return        DCM_E_NOT_OK         Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service19_02Processor(
  Dcm_ThreadIdType threadId,
  Dcm_OpStatusType opStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_Service19_04Processor()
 ***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic sub-service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic sub-service, configured to be
 *                 handled by a CDD, is received. All of the relevant diagnostic request parameter information is
 *                 forwarded by DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSubService/DcmDsdSubServiceFnc.
 *  \param[in]     threadId             The active thread identifier
 *  \param[in]     opStatus             The operation status
 *  \param[in,out] pMsgContext          Message-related information for one diagnostic protocol identifier
 *                                      The pointers in pMsgContext points behind the sub-function.
 *  \param[out]    ErrorCode            Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK             Job processing finished, send positive response
 *  \return        DCM_E_PENDING        Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP    (Vendor extension) Forces a RCR-RP response.
 *                                      The call out will called again once the response is sent. The OpStatus parameter
 *                                      will contain the transmission result
 *  \return        DCM_E_STOP_REPEATER  Stops the repeater proxy
 *  \return        DCM_E_NOT_OK         Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service19_04Processor(
  Dcm_ThreadIdType threadId,
  Dcm_OpStatusType opStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_Service19_06Processor()
 ***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic sub-service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic sub-service, configured to be
 *                 handled by a CDD, is received. All of the relevant diagnostic request parameter information is
 *                 forwarded by DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSubService/DcmDsdSubServiceFnc.
 *  \param[in]     threadId             The active thread identifier
 *  \param[in]     opStatus             The operation status
 *  \param[in,out] pMsgContext          Message-related information for one diagnostic protocol identifier
 *                                      The pointers in pMsgContext points behind the sub-function.
 *  \param[out]    ErrorCode            Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK             Job processing finished, send positive response
 *  \return        DCM_E_PENDING        Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP    (Vendor extension) Forces a RCR-RP response.
 *                                      The call out will called again once the response is sent. The OpStatus parameter
 *                                      will contain the transmission result
 *  \return        DCM_E_STOP_REPEATER  Stops the repeater proxy
 *  \return        DCM_E_NOT_OK         Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service19_06Processor(
  Dcm_ThreadIdType threadId,
  Dcm_OpStatusType opStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_Service28_XXProcessor()
 ***********************************************************************************************************************/
/*! \brief         Processes a received diagnostic sub-service request.
 *  \details       DCM calls a function of this kind as soon as a supported diagnostic sub-service, configured to be
 *                 handled by a CDD, is received. All of the relevant diagnostic request parameter information is
 *                 forwarded by DCM through the pMsgContext function parameter.
 *                 The concrete name of the callout is defined by the configuration
 *                 parameter/Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSubService/DcmDsdSubServiceFnc.
 *  \param[in]     threadId             The active thread identifier
 *  \param[in]     opStatus             The operation status
 *  \param[in,out] pMsgContext          Message-related information for one diagnostic protocol identifier
 *                                      The pointers in pMsgContext points behind the sub-function.
 *  \param[out]    ErrorCode            Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK             Job processing finished, send positive response
 *  \return        DCM_E_PENDING        Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP    (Vendor extension) Forces a RCR-RP response.
 *                                      The call out will called again once the response is sent. The OpStatus parameter
 *                                      will contain the transmission result
 *  \return        DCM_E_STOP_REPEATER  Stops the repeater proxy
 *  \return        DCM_E_NOT_OK         Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_Service28_XXProcessor(
  Dcm_ThreadIdType threadId,
  Dcm_OpStatusType opStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
# define DCM_STOP_SEC_CALLOUT_CODE
# include "Dcm_MemMap.h"                                                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA DECLARATIONS
 *********************************************************************************************************************/
# define DCM_START_SEC_CONST_8
# include "Dcm_MemMap.h"                                                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*! TxPduId to DCM connection map */
extern CONST(Dcm_NetConnRefMemType, DCM_CONST) Dcm_CfgNetTxPduInfo[12];
/*! Map of DCM relevant network handles */
extern CONST(Dcm_CfgNetNetIdRefMemType, DCM_CONST) Dcm_CfgNetConnComMChannelMap[2];
/*! Look up table of all supported transfer ALFIDs */
extern CONST(uint8, DCM_CONST) Dcm_CfgFblMgrTransferAlfidLookUpTable[17];
/*! Look up table of all supported transfer MIDs */
extern CONST(uint8, DCM_CONST) Dcm_CfgFblMgrTransferMidLookUpTable[1];
/*! Look up table of DCM service identifiers */
extern CONST(uint8, DCM_CONST) Dcm_CfgDiagSvcIdLookUpTable[15];
/*! Service 0x10 look up table  */
extern CONST(uint8, DCM_CONST) Dcm_CfgSvc10SubFuncLookUpTable[4];
/*! Service 0x11 look up table  */
extern CONST(uint8, DCM_CONST) Dcm_CfgSvc11SubFuncLookUpTable[3];
/*! Service 0x19 look up table  */
extern CONST(uint8, DCM_CONST) Dcm_CfgSvc19SubFuncLookUpTable[4];
/*! Service 0x27 look up table  */
extern CONST(uint8, DCM_CONST) Dcm_CfgSvc27SubFuncLookUpTable[3];
/*! Service 0x28 look up table  */
extern CONST(uint8, DCM_CONST) Dcm_CfgSvc28SubFuncLookUpTable[5];
/*! Service 0x28 look up table  */
extern CONST(uint8, DCM_CONST) Dcm_CfgSvc28MessageTypeLookUpTable[4];
/*! Service 0x28 network ID lookup */
extern CONST(uint8, DCM_CONST) Dcm_CfgSvc28SubNetIdLookUp[2];
/*! Service 0x3E look up table  */
extern CONST(uint8, DCM_CONST) Dcm_CfgSvc3ESubFuncLookUpTable[2];
/*! Look up table of service 0x85 */
extern CONST(uint8, DCM_CONST) Dcm_CfgSvc85SubFuncLookUpTable[3];
# define DCM_STOP_SEC_CONST_8
# include "Dcm_MemMap.h"                                                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define DCM_START_SEC_CONST_16
# include "Dcm_MemMap.h"                                                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*! DID look up table  */
extern CONST(uint16, DCM_CONST) Dcm_CfgDidMgrDidLookUpTable[32];
/*! RID look up table  */
extern CONST(uint16, DCM_CONST) Dcm_CfgRidMgrRidLookUpTable[9];
# define DCM_STOP_SEC_CONST_16
# include "Dcm_MemMap.h"                                                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define DCM_START_SEC_CONST_UNSPECIFIED
# include "Dcm_MemMap.h"                                                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*! DCM buffer descriptor */
extern CONST(Dcm_CfgNetBufferInfoType, DCM_CONST) Dcm_CfgNetBufferInfo[1];
/*! RxPduId map */
extern CONST(Dcm_CfgNetRxPduInfoType, DCM_CONST) Dcm_CfgNetRxPduInfo[24];
/*! DCM connection descriptor */
extern CONST(Dcm_CfgNetConnectionInfoType, DCM_CONST) Dcm_CfgNetConnectionInfo[12];
/*! DCM protocol descriptor */
extern CONST(Dcm_CfgNetProtocolInfoType, DCM_CONST) Dcm_CfgNetProtocolInfo[1];
/*! Map of all relevant for DCM network handles */
extern CONST(NetworkHandleType, DCM_CONST) Dcm_CfgNetAllComMChannelMap[2];
/*! Look up table of DCM relevant network handles */
extern CONST(NetworkHandleType, DCM_CONST) Dcm_CfgNetNetworkHandleLookUpTable[3];
/*! Diagnostic service execution conditions */
extern CONST(Dcm_CfgStatePreconditionInfoType, DCM_CONST) Dcm_CfgStatePreconditions[8];
/*! Session state properties */
extern CONST(Dcm_CfgStateSessionInfoType, DCM_CONST) Dcm_CfgStateSessionInfo[3];
/*! Security Access state properties */
extern CONST(Dcm_CfgStateSecurityInfoType, DCM_CONST) Dcm_CfgStateSecurityInfo[1];
/*! DID ranges look up */
extern CONST(Dcm_CfgDidMgrDidRangeType, DCM_CONST) Dcm_CfgDidMgrDidRanges[1];
/*! DID ranges to DID info map */
extern CONST(Dcm_CfgDidMgrDidInfoRefType, DCM_CONST) Dcm_CfgDidMgrRangeDidInfoRefs[1];
/*! DID properties */
extern CONST(Dcm_CfgDidMgrDidInfoType, DCM_CONST) Dcm_CfgDidMgrDidInfo[31];
/*! DID operation properties */
extern CONST(Dcm_CfgDidMgrDidOpInfoType, DCM_CONST) Dcm_CfgDidMgrDidOpInfo[34];
/*! DID operation classes */
extern CONST(Dcm_CfgDidMgrDidOpClassInfoType, DCM_CONST) Dcm_CfgDidMgrDidOpClassInfo[65];
/*! DID signal operation classes */
extern CONST(Dcm_CfgDidMgrSignalOpClassInfoType, DCM_CONST) Dcm_CfgDidMgrSignalOpClassInfo[64];
/*! RID properties */
extern CONST(Dcm_CfgRidMgrRidInfoType, DCM_CONST) Dcm_CfgRidMgrRidInfo[8];
/*! RID operation properties */
extern CONST(Dcm_CfgRidMgrOpInfoType, DCM_CONST) Dcm_CfgRidMgrOpInfo[14];
/*! DCM service initializers */
extern CONST(Dcm_DiagSvcInitFuncType, DCM_CONST) Dcm_CfgDiagSvcInitializers[1];
/*! DCM service properties */
extern CONST(Dcm_CfgDiagServiceInfoType, DCM_CONST) Dcm_CfgDiagServiceInfo[15];
/*! Indirection from diag service info to execution pre conditions */
extern CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgDiagSvcIdExecPrecondTable[14];
/*! DCM service post processors */
extern CONST(Dcm_DiagSvcConfirmationFuncType, DCM_CONST) Dcm_CfgDiagSvcPostProcessors[10];
/*! DCM service paged buffer updater */
extern CONST(Dcm_DiagSvcUpdateFuncType, DCM_CONST) Dcm_CfgDiagSvcUpdaters[3];
/*! DCM service paged buffer canceller */
extern CONST(Dcm_DiagSvcCancelFuncType, DCM_CONST) Dcm_CfgDiagSvcCancellers[5];
/*! DCM service pre handler */
extern CONST(Dcm_DiagSvcPreHandlerFuncType, DCM_CONST) Dcm_CfgDiagSvcPreHandlers[1];
/*! DCM service post handler */
extern CONST(Dcm_DiagSvcPostHandlerFuncType, DCM_CONST) Dcm_CfgDiagSvcPostHandlers[1];
/*! System supplier notification functions */
extern CONST(Dcm_CfgDiagNotificationInfoType, DCM_CONST) Dcm_CfgDiagSysNotificationInfo[1];
/*! DCM service to protocol map */
extern CONST(Dcm_CfgDiagSvc2ProtMapMemType, DCM_CONST) Dcm_CfgDiagSvcId2ProtMap[14];
/*! Dcm all variant root */
extern CONST(Dcm_ConfigsType, DCM_CONST) Dcm_CfgConfigsRoot;
/*! Service 0x10 sub-service properties table  */
extern CONST(Dcm_CfgSvc10SubFuncInfoType, DCM_CONST) Dcm_CfgSvc10SubFuncInfo[3];
/*! Indirection from service 0x10 sub functions to execution pre conditions */
extern CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc10SubFuncExecPrecondTable[3];
/*! Service 0x11 sub-service properties table  */
extern CONST(Dcm_CfgSvc11SubFuncInfoType, DCM_CONST) Dcm_CfgSvc11SubFuncInfo[2];
/*! Indirection from service 0x11 sub functions to execution pre conditions */
extern CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc11SubFuncExecPrecondTable[2];
/*! Service 0x19 sub-service properties table  */
extern CONST(Dcm_CfgSvc19SubFuncInfoType, DCM_CONST) Dcm_CfgSvc19SubFuncInfo[3];
/*! Indirection from service 0x19 sub functions to execution pre conditions */
extern CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc19SubFuncExecPrecondTable[3];
/*! Service 0x27 security level properties table  */
extern CONST(Dcm_CfgSvc27SecLevelInfoType, DCM_CONST) Dcm_CfgSvc27SecLevelInfo[1];
/*! Indirection from service 0x27 sub functions to execution pre conditions */
extern CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc27SubFuncExecPrecondTable[2];
/*! Service 0x28 sub-service properties table  */
extern CONST(Dcm_CfgSvc28SubFuncInfoType, DCM_CONST) Dcm_CfgSvc28SubFuncInfo[4];
/*! Indirection from service 0x28 sub functions to execution pre conditions */
extern CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc28SubFuncExecPrecondTable[4];
/*! Service 0x28 network ID to ComM channel map */
extern CONST(NetworkHandleType, DCM_CONST) Dcm_CfgSvc28SubNetIdMap[1];
/*! Indirection from service 0x3E sub functions to execution pre conditions */
extern CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc3ESubFuncExecPrecondTable[1];
/*! Indirection from service 0x85 sub functions to execution pre conditions */
extern CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc85SubFuncExecPrecondTable[2];
/*! DCM service 0x85 properties */
extern CONST(Dcm_CfgSvc85SubFuncInfoType, DCM_CONST) Dcm_CfgSvc85SubFuncInfo[2];
# define DCM_STOP_SEC_CONST_UNSPECIFIED
# include "Dcm_MemMap.h"                                                                                                                             /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#endif /* !defined(DCM_LCFG_H) */

/**********************************************************************************************************************
 *  END OF FILE: Dcm_Lcfg.h
 *********************************************************************************************************************/

