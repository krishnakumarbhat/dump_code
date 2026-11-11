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
 *              File: Dcm_Lcfg.c
 *   Generation Time: 2026-08-13 10:24:58
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


#define DCM_LCFG_SOURCE

#ifdef __PRQA__ /* COV_DCM_PRQA_UNREACHABLE XF */
#pragma PRQA_MACRO_MESSAGES_OFF "Dcm_MsgContextGetReqData" 2985 /* MD_Dcm_Redundant_2985 */
#pragma PRQA_MACRO_MESSAGES_OFF "Dcm_MsgContextGetResData" 2985 /* MD_Dcm_Redundant_2985 */
                                                                                                                                                     /* PRQA S 1711 EOF */ /* MD_MSR_Rule5.1 */
                                                                                                                                                     /* PRQA S 2991 EOF */ /* MD_Dcm_ConstExpr */
                                                                                                                                                     /* PRQA S 2992 EOF */ /* MD_Dcm_ConstExpr */
                                                                                                                                                     /* PRQA S 2995 EOF */ /* MD_Dcm_ConstExpr */
                                                                                                                                                     /* PRQA S 2996 EOF */ /* MD_Dcm_ConstExpr */
                                                                                                                                                     /* PRQA S 3635 EOF */ /* MD_Dcm_FuncPtrWithAmpersand */
#endif
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
                                                                                                                                                     /* PRQA S 1533 EOF */ /* MD_Dcm_ObjectOnlyAccessedOnce */
#include "Dcm.h"
#include "Rte_Dcm.h"
#include "Det.h"
#include "Dcm_DataContext.h"
#include "Dcm_MsgContext.h"
#include "Dcm_Uti.h"
#include "PduR_Dcm.h"
#include "Dcm_Net.h"
#include "ComM_Dcm.h"
#include "Dcm_PagedBuffer.h"
#include "Dcm_VarMgr.h"
#include "Dcm_Svc28.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if (DCM_DIDMGR_NVM_READ_ENABLED == STD_ON) || \
    (DCM_DIDMGR_NVM_WRITE_ENABLED == STD_ON)
# if defined(NVM_VENDOR_ID)
#  if (NVM_VENDOR_ID == 30u)
/* Only Vector NvM supports this feature up to now */
#   define Dcm_GetDcmNvMBlockId(blockId)                             (uint16)(NvM_GetDcmBlockId(blockId))                                            /* PRQA S 3453 */ /* QAC 7.0:  A function could probably be used instead of this function-like macro */ /* Macro is more efficient! */
#  endif
# endif

/* Default NvM handle offset */
# if !defined(Dcm_GetDcmNvMBlockId)
#  define Dcm_GetDcmNvMBlockId(blockId)                              (uint16)(blockId)                                                               /* PRQA S 3453 */ /* QAC 7.0:  A function could probably be used instead of this function-like macro */ /* Macro is more efficient! */
# endif
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DCM_START_SEC_CALLOUT_CODE
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  Dcm_ServiceNoPostProcessor()
 ***********************************************************************************************************************/
/*! \brief         Dummy post-processor
 *  \details       This post-processor is called for diagnostic services which do not require any post processing.
 *  \param[in]     threadId  The active thread identifier
 *  \param[in]     status    The post-processing status
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(void, DCM_CALLOUT_CODE) Dcm_ServiceNoPostProcessor(
  Dcm_ThreadIdType threadId,
  Dcm_ConfirmationStatusType status
  );
/***********************************************************************************************************************
 *  Dcm_ServiceNoUpdater()
 ***********************************************************************************************************************/
/*! \brief         Realizes a dummy paged buffer updater.
 *  \details       This function is never called.
 *  \param[in]     threadId      The active thread identifier
 *  \param[in]     opStatus      The operation status
 *  \param[in,out] pDataContext  Pointer to the data context
 *  \param[out]    ErrorCode     Negative response code
 *  \return        E_NOT_OK      Operation failed. Take the NRC from ErrorCode. Do not call again
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ServiceNoUpdater(
  Dcm_ThreadIdType threadId,
  Dcm_OpStatusType opStatus,
  Dcm_DiagDataContextPtrType pDataContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_ServiceNoCancel()
 ***********************************************************************************************************************/
/*! \brief         Dummy service cancellation.
 *  \details       -
 *  \param[in]     threadId      The active thread identifier
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(void, DCM_CALLOUT_CODE) Dcm_ServiceNoCancel(
  Dcm_ThreadIdType threadId
  );
/***********************************************************************************************************************
 *  Dcm_ServiceNoPreHandler()
 ***********************************************************************************************************************/
/*! \brief         Dummy pre-handler service processing.
 *  \details       This pre-handler is called for diagnostic services which do not have a pre-handler configured.
 *  \param[in]     OpStatus                    The status of the current operation
 *  \param[in]     SID                         Contains the diagnostic service Id
 *  \param[in]     RequestData                 Points to the request data. Points behind the service Id byte
 *  \param[in]     DataSize                    Specifies the request data length (without SID byte)
 *  \param[in]     ProtocolType                Specifies the ID of the protocol on which the request was received
 *  \param[in]     SourceAddress               Contains the diagnostic client source address
 *  \param[in]     ConnectionId                Unique ID of the connection on which the request has been received
 *  \param[in]     ReqType                     Specifies the diagnostic request type:
 *                                             0 - physical request
 *                                             1 - functional request
 *  \param[out]    ErrorCode                   Negative response code - not used
 *  \return        E_OK                        Return value is always OK
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ServiceNoPreHandler(
  Dcm_OpStatusType OpStatus,
  uint8 SID,
  P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) RequestData,
  uint32 DataSize,
  Dcm_ProtocolType ProtocolType,
  uint16 SourceAddress,
  uint16 ConnectionId,
  uint8 ReqType,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_ServiceNoPostHandler()
 ***********************************************************************************************************************/
/*! \brief         Dummy post-handler service processing.
 *  \details       This post-handler is called for diagnostic services which do not have a post-handler configured.
 *  \param[in]     OpStatus                    The status of the current operation
 *  \param[in]     SID                         Contains the diagnostic service Id
 *  \param[in]     ResponseData                Points to the response data. Points behind the service Id byte
 *  \param[in]     DataSize                    Specifies the response data length (without SID byte)
 *  \param[in]     ProtocolType                Specifies the ID of the protocol on which the request was received
 *  \param[in]     SourceAddress               Contains the diagnostic client source address
 *  \param[in]     ConnectionId                Unique ID of the connection on which the request has been received
 *  \param[in]     ReqType                     Specifies the diagnostic request type:
 *                                             0 - physical request
 *                                             1 - functional request
 *  \param[out]    ErrorCode                   Negative response code - not used
 *  \return        E_OK                        Return value is always OK
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE)Dcm_ServiceNoPostHandler(
  Dcm_OpStatusType OpStatus,
  uint8 SID,
  P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) ResponseData,
  uint32 DataSize,
  Dcm_ProtocolType ProtocolType,
  uint16 SourceAddress,
  uint16 ConnectionId,
  uint8 ReqType,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode
  );
#define DCM_STOP_SEC_CALLOUT_CODE
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL DATA DECLARATIONS
 *********************************************************************************************************************/
#define DCM_START_SEC_VAR_NO_INIT_8
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*! DCM protocol descriptor */
DCM_LOCAL VAR(Dcm_MsgItemType, DCM_VAR_NOINIT) Dcm_CfgNetBuffer_000[96];
#define DCM_STOP_SEC_VAR_NO_INIT_8
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*! TxPduId to DCM connection map */
CONST(Dcm_NetConnRefMemType, DCM_CONST) Dcm_CfgNetTxPduInfo[12]=
{
    2u
  , 0u
  , 7u
  , 5u
  , 1u
  ,10u
  , 4u
  , 8u
  ,11u
  , 3u
  , 9u
  , 6u
};
/*! Map of DCM relevant network handles */
CONST(Dcm_CfgNetNetIdRefMemType, DCM_CONST) Dcm_CfgNetConnComMChannelMap[2]=
{
    0u
  , 1u
};
/*! Look up table of all supported transfer ALFIDs */
CONST(uint8, DCM_CONST) Dcm_CfgFblMgrTransferAlfidLookUpTable[17]=
{
   16u
  ,0x11u
  ,0x12u
  ,0x13u
  ,0x14u
  ,0x21u
  ,0x22u
  ,0x23u
  ,0x24u
  ,0x31u
  ,0x32u
  ,0x33u
  ,0x34u
  ,0x41u
  ,0x42u
  ,0x43u
  ,0x44u
};
/*! Look up table of all supported transfer MIDs */
CONST(uint8, DCM_CONST) Dcm_CfgFblMgrTransferMidLookUpTable[1]=
{
   0u
};
/*! Look up table of DCM service identifiers */
CONST(uint8, DCM_CONST) Dcm_CfgDiagSvcIdLookUpTable[15]=
{
   14u
  ,0x10u
  ,0x11u
  ,0x14u
  ,0x19u
  ,0x22u
  ,0x27u
  ,0x28u
  ,0x2Eu
  ,0x31u
  ,0x34u
  ,0x36u
  ,0x37u
  ,0x3Eu
  ,0x85u
};
/*! Service 0x10 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc10SubFuncLookUpTable[4]=
{
   3u
  ,0x01u
  ,0x02u
  ,0x03u
};
/*! Service 0x11 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc11SubFuncLookUpTable[3]=
{
   2u
  ,0x01u
  ,0x03u
};
/*! Service 0x19 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc19SubFuncLookUpTable[4]=
{
   3u
  ,0x02u
  ,0x04u
  ,0x06u
};
/*! Service 0x27 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc27SubFuncLookUpTable[3]=
{
   2u
  ,0x11u
  ,0x12u
};
/*! Service 0x28 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc28SubFuncLookUpTable[5]=
{
   4u
  ,0x00u
  ,0x01u
  ,0x02u
  ,0x03u
};
/*! Service 0x28 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc28MessageTypeLookUpTable[4]=
{
   3u
  ,0x01u
  ,0x02u
  ,0x03u
};
/*! Service 0x28 network ID lookup */
CONST(uint8, DCM_CONST) Dcm_CfgSvc28SubNetIdLookUp[2]=
{
   1u
  ,0x0Fu
};
/*! Service 0x3E look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc3ESubFuncLookUpTable[2]=
{
   1u
  ,0x00u
};
/*! Look up table of service 0x85 */
CONST(uint8, DCM_CONST) Dcm_CfgSvc85SubFuncLookUpTable[3]=
{
   2u
  ,0x01u
  ,0x02u
};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define DCM_START_SEC_CONST_16
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*! DID look up table  */
CONST(uint16, DCM_CONST) Dcm_CfgDidMgrDidLookUpTable[32]=
{
   31u
  ,0x1111u
  ,0x1112u
  ,0x1116u
  ,0x1117u
  ,0xA000u
  ,0xA001u
  ,0xA002u
  ,0xA003u
  ,0xA004u
  ,0xF010u
  ,0xF011u
  ,0xF012u
  ,0xF013u
  ,0xF014u
  ,0xF015u
  ,0xF016u
  ,0xF017u
  ,0xF01Bu
  ,0xF01Cu
  ,0xF150u
  ,0xF15Au
  ,0xF16Au
  ,0xF180u
  ,0xF186u
  ,0xF189u
  ,0xF18Bu
  ,0xF190u
  ,0xF191u
  ,0xF19Du
  ,0xF19Eu
  ,0xFDA3u
};
/*! RID look up table  */
CONST(uint16, DCM_CONST) Dcm_CfgRidMgrRidLookUpTable[9]=
{
   8u
  ,0x0200u
  ,0x020Eu
  ,0x7000u
  ,0x7003u
  ,0x7004u
  ,0x7005u
  ,0xFF00u
  ,0xFF01u
};
#define DCM_STOP_SEC_CONST_16
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*! DCM buffer descriptor */
CONST(Dcm_CfgNetBufferInfoType, DCM_CONST) Dcm_CfgNetBufferInfo[1]=
{
   { Dcm_CfgNetBuffer_000,  96u}
};
/*! RxPduId map */
CONST(Dcm_CfgNetRxPduInfoType, DCM_CONST) Dcm_CfgNetRxPduInfo[24]=
{
   { TRUE, 2u}
  ,{ FALSE, 2u}
  ,{ TRUE, 0u}
  ,{ FALSE, 0u}
  ,{ TRUE, 7u}
  ,{ FALSE, 7u}
  ,{ TRUE, 5u}
  ,{ FALSE, 5u}
  ,{ TRUE, 1u}
  ,{ FALSE, 1u}
  ,{ TRUE,10u}
  ,{ FALSE,10u}
  ,{ TRUE, 4u}
  ,{ FALSE, 4u}
  ,{ TRUE, 8u}
  ,{ FALSE, 8u}
  ,{ TRUE,11u}
  ,{ FALSE,11u}
  ,{ TRUE, 3u}
  ,{ FALSE, 3u}
  ,{ TRUE, 9u}
  ,{ FALSE, 9u}
  ,{ TRUE, 6u}
  ,{ FALSE, 6u}
};
/*! DCM connection descriptor */
CONST(Dcm_CfgNetConnectionInfoType, DCM_CONST) Dcm_CfgNetConnectionInfo[12]=
{
   {    0u,0x00F0u,PduRConf_PduRSrcPdu_PduRSrcPdu_5a38c029, 0u,0u,0x0000u,0x00u, 0u}
  ,{    3u,0x00F1u,PduRConf_PduRSrcPdu_PduRSrcPdu_d30572be, 0u,0u,0x0000u,0x00u, 0u}
  ,{    1u,0x00F0u,PduRConf_PduRSrcPdu_PduRSrcPdu_6149f4ac, 0u,0u,0x0000u,0x00u, 0u}
  ,{    9u,0x00F5u,PduRConf_PduRSrcPdu_PduRSrcPdu_657fa4c9, 0u,0u,0x0000u,0x00u, 0u}
  ,{    6u,0x00F4u,PduRConf_PduRSrcPdu_PduRSrcPdu_b7e0bf39, 0u,0u,0x0000u,0x00u, 0u}
  ,{    4u,0x00F1u,PduRConf_PduRSrcPdu_PduRSrcPdu_eb36a6cb, 0u,0u,0x0000u,0x00u, 0u}
  ,{   11u,0x00F5u,PduRConf_PduRSrcPdu_PduRSrcPdu_0cacdbaf, 1u,0u,0x0000u,0x00u, 0u}
  ,{    2u,0x00F0u,PduRConf_PduRSrcPdu_PduRSrcPdu_39695c5b, 1u,0u,0x0000u,0x00u, 0u}
  ,{    7u,0x00F4u,PduRConf_PduRSrcPdu_PduRSrcPdu_c06d99da, 0u,0u,0x0000u,0x00u, 0u}
  ,{   10u,0x00F5u,PduRConf_PduRSrcPdu_PduRSrcPdu_5b4521ce, 0u,0u,0x0000u,0x00u, 0u}
  ,{    5u,0x00F1u,PduRConf_PduRSrcPdu_PduRSrcPdu_dffb8b0e, 1u,0u,0x0000u,0x00u, 0u}
  ,{    8u,0x00F4u,PduRConf_PduRSrcPdu_PduRSrcPdu_b88278da, 1u,0u,0x0000u,0x00u, 0u}
};
/*! DCM protocol descriptor */
CONST(Dcm_CfgNetProtocolInfoType, DCM_CONST) Dcm_CfgNetProtocolInfo[1]=
{
   { {        1u,     100u},4095u, 3u, 0u,TRUE,0u,DemConf_DemClient_DemClient, 0u}
};
/*! Map of all relevant for DCM network handles */
CONST(NetworkHandleType, DCM_CONST) Dcm_CfgNetAllComMChannelMap[2]=
{
   ComMConf_ComMChannel_CN_PCAN_RADAR_458ff0f1
  ,ComMConf_ComMChannel_CN_VCAN_RADAR_489180b6
};
/*! Look up table of DCM relevant network handles */
CONST(NetworkHandleType, DCM_CONST) Dcm_CfgNetNetworkHandleLookUpTable[3]=
{
   2u
  ,ComMConf_ComMChannel_CN_PCAN_RADAR_458ff0f1
  ,ComMConf_ComMChannel_CN_VCAN_RADAR_489180b6
};
/*! Diagnostic service execution conditions */
CONST(Dcm_CfgStatePreconditionInfoType, DCM_CONST) Dcm_CfgStatePreconditions[8]=
{
   { { 0x07u,0x03u}}
  ,{ { 0x06u,0x02u}}
  ,{ { 0x05u,0x03u}}
  ,{ { 0x06u,0x03u}}
  ,{ { 0x04u,0x02u}}
  ,{ { 0x02u,0x03u}}
  ,{ { 0x02u,0x02u}}
  ,{ { 0x04u,0x03u}}
};
/*! Session state properties */
CONST(Dcm_CfgStateSessionInfoType, DCM_CONST) Dcm_CfgStateSessionInfo[3]=
{
   { {        5u,     195u},RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION,0x01u}
  ,{ {        5u,     195u},RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION,0x02u}
  ,{ {        5u,     195u},RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION,0x03u}
};
/*! Security Access state properties */
CONST(Dcm_CfgStateSecurityInfoType, DCM_CONST) Dcm_CfgStateSecurityInfo[1]=
{
   {    0u,   0u,FALSE, 5u,0x09u} /* SecLvl: UnlockedL1 */
};
/*! DID ranges look up */
CONST(Dcm_CfgDidMgrDidRangeType, DCM_CONST) Dcm_CfgDidMgrDidRanges[1]=
{
   {    0u,   0u}
};
/*! DID ranges to DID info map */
CONST(Dcm_CfgDidMgrDidInfoRefType, DCM_CONST) Dcm_CfgDidMgrRangeDidInfoRefs[1]=
{
   0u /* dummy initializer */
};
/*! DID properties */
CONST(Dcm_CfgDidMgrDidInfoType, DCM_CONST) Dcm_CfgDidMgrDidInfo[31]=
{
   {    2u,   2u,   2u,   0u,   0u,0x01u} /* DID: 0x1111 */
  ,{    2u,   2u,   2u,   1u,   0u,0x01u} /* DID: 0x1112 */
  ,{    7u,   7u,   7u,   2u,   0u,0x01u} /* DID: 0x1116 */
  ,{    1u,   1u,   1u,   3u,   0u,0x01u} /* DID: 0x1117 */
  ,{   16u,  16u,  16u,   4u,   0u,0x01u} /* DID: 0xA000 */
  ,{   14u,  14u,  14u,   5u,   0u,0x01u} /* DID: 0xA001 */
  ,{   12u,  12u,  12u,   6u,   0u,0x01u} /* DID: 0xA002 */
  ,{   12u,  12u,  12u,   7u,   0u,0x01u} /* DID: 0xA003 */
  ,{    1u,   1u,   1u,   8u,   0u,0x01u} /* DID: 0xA004 */
  ,{    1u,   1u,   1u,   9u,   0u,0x01u} /* DID: 0xF010 */
  ,{   42u,  42u,  42u,  10u,   0u,0x01u} /* DID: 0xF011 */
  ,{   22u,  22u,  22u,  11u,   0u,0x01u} /* DID: 0xF012 */
  ,{    6u,   6u,   6u,  12u,   0u,0x02u} /* DID: 0xF013 */
  ,{   14u,  14u,  14u,  13u,   0u,0x01u} /* DID: 0xF014 */
  ,{   87u,  87u,  87u,  14u,   0u,0x01u} /* DID: 0xF015 */
  ,{   93u,  93u,  93u,  15u,   0u,0x01u} /* DID: 0xF016 */
  ,{    2u,   2u,   2u,  16u,   0u,0x01u} /* DID: 0xF017 */
  ,{   10u,  10u,  10u,  17u,   0u,0x03u} /* DID: 0xF01B */
  ,{   55u,  55u,  55u,  19u,   0u,0x01u} /* DID: 0xF01C */
  ,{    5u,   5u,   5u,  20u,   0u,0x01u} /* DID: 0xF150 */
  ,{    4u,   4u,   4u,  21u,   0u,0x03u} /* DID: 0xF15A */
  ,{    1u,   1u,   1u,  23u,   0u,0x01u} /* DID: 0xF16A */
  ,{   12u,  12u,  12u,  24u,   0u,0x01u} /* DID: 0xF180 */
  ,{    1u,   1u,   1u,  25u,   0u,0x01u} /* DID: 0xF186 */
  ,{    7u,   7u,   7u,  26u,   0u,0x01u} /* DID: 0xF189 */
  ,{    4u,   4u,   4u,  27u,   0u,0x01u} /* DID: 0xF18B */
  ,{   17u,  17u,  17u,  28u,   0u,0x03u} /* DID: 0xF190 */
  ,{   13u,  13u,  13u,  30u,   0u,0x01u} /* DID: 0xF191 */
  ,{    2u,   2u,   2u,  31u,   0u,0x01u} /* DID: 0xF19D */
  ,{    2u,   2u,   2u,  32u,   0u,0x01u} /* DID: 0xF19E */
  ,{   22u,  22u,  22u,  33u,   0u,0x01u} /* DID: 0xFDA3 */
};
/*! DID operation properties */
CONST(Dcm_CfgDidMgrDidOpInfoType, DCM_CONST) Dcm_CfgDidMgrDidOpInfo[34]=
{
   {    2u,   0u,0x05u} /* DID: 0x1111 */
  ,{    2u,   2u,0x05u} /* DID: 0x1112 */
  ,{    2u,   4u,0x05u} /* DID: 0x1116 */
  ,{    2u,   6u,0x05u} /* DID: 0x1117 */
  ,{    0u,   8u,0x05u} /* DID: 0xA000 */
  ,{    2u,  10u,0x05u} /* DID: 0xA001 */
  ,{    0u,  12u,0x05u} /* DID: 0xA002 */
  ,{    0u,  14u,0x05u} /* DID: 0xA003 */
  ,{    2u,  16u,0x05u} /* DID: 0xA004 */
  ,{    2u,  18u,0x05u} /* DID: 0xF010 */
  ,{    2u,  20u,0x05u} /* DID: 0xF011 */
  ,{    2u,  22u,0x05u} /* DID: 0xF012 */
  ,{    4u,  24u,0x01u} /* DID: 0xF013 */
  ,{    2u,  25u,0x05u} /* DID: 0xF014 */
  ,{    2u,  27u,0x05u} /* DID: 0xF015 */
  ,{    2u,  29u,0x05u} /* DID: 0xF016 */
  ,{    2u,  31u,0x05u} /* DID: 0xF017 */
  ,{    2u,  33u,0x05u} /* DID: 0xF01B */
  ,{    4u,  35u,0x01u} /* DID: 0xF01B */
  ,{    2u,  36u,0x05u} /* DID: 0xF01C */
  ,{    0u,  38u,0x05u} /* DID: 0xF150 */
  ,{    0u,  40u,0x05u} /* DID: 0xF15A */
  ,{    6u,  42u,0x01u} /* DID: 0xF15A */
  ,{    0u,  43u,0x05u} /* DID: 0xF16A */
  ,{    0u,  45u,0x05u} /* DID: 0xF180 */
  ,{    0u,  47u,0x05u} /* DID: 0xF186 */
  ,{    0u,  49u,0x05u} /* DID: 0xF189 */
  ,{    2u,  51u,0x05u} /* DID: 0xF18B */
  ,{    2u,  53u,0x05u} /* DID: 0xF190 */
  ,{    4u,  55u,0x01u} /* DID: 0xF190 */
  ,{    0u,  56u,0x05u} /* DID: 0xF191 */
  ,{    2u,  58u,0x05u} /* DID: 0xF19D */
  ,{    2u,  60u,0x05u} /* DID: 0xF19E */
  ,{    2u,  62u,0x05u} /* DID: 0xFDA3 */
};
/*! DID operation classes */
CONST(Dcm_CfgDidMgrDidOpClassInfoType, DCM_CONST) Dcm_CfgDidMgrDidOpClassInfo[65]=
{
   {  0u}
  ,{  1u}
  ,{  2u}
  ,{  3u}
  ,{  4u}
  ,{  5u}
  ,{  6u}
  ,{  7u}
  ,{  8u}
  ,{  9u}
  ,{ 10u}
  ,{ 11u}
  ,{ 12u}
  ,{ 13u}
  ,{ 14u}
  ,{ 15u}
  ,{ 16u}
  ,{ 17u}
  ,{ 18u}
  ,{ 19u}
  ,{ 20u}
  ,{ 21u}
  ,{ 22u}
  ,{ 23u}
  ,{ 24u}
  ,{ 25u}
  ,{ 26u}
  ,{ 27u}
  ,{ 28u}
  ,{ 29u}
  ,{ 30u}
  ,{ 31u}
  ,{ 32u}
  ,{ 33u}
  ,{ 34u}
  ,{ 35u}
  ,{ 36u}
  ,{ 37u}
  ,{ 38u}
  ,{ 39u}
  ,{ 40u}
  ,{ 41u}
  ,{ 42u}
  ,{ 43u}
  ,{ 44u}
  ,{ 45u}
  ,{ 46u}
  ,{ 47u}
  ,{ 48u}
  ,{ 49u}
  ,{ 50u}
  ,{ 51u}
  ,{ 52u}
  ,{ 53u}
  ,{ 54u}
  ,{ 55u}
  ,{ 56u}
  ,{ 57u}
  ,{ 58u}
  ,{ 59u}
  ,{ 60u}
  ,{ 61u}
  ,{ 62u}
  ,{ 63u}
  ,{ 64u}
};
/*! DID signal operation classes */
CONST(Dcm_CfgDidMgrSignalOpClassInfoType, DCM_CONST) Dcm_CfgDidMgrSignalOpClassInfo[64]=
{
   { ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_ECUVoltage_Read_ReadData)),   2u,   2u,0x0002u} /* DID: 0x1111 */                            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_ECUVoltage_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x1111 */                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_VehicleSpeed_Read_ReadData)),   2u,   2u,0x0002u} /* DID: 0x1112 */                          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_VehicleSpeed_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x1112 */                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_DateandTime_Read_ReadData)),   7u,   7u,0x0002u} /* DID: 0x1116 */                           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_DateandTime_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x1116 */                 /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Sensor_Availability_Flag_Read_ReadData)),   1u,   1u,0x0002u} /* DID: 0x1117 */              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Sensor_Availability_Flag_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x1117 */    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_SerialNumber_Read_ReadData)),  16u,  16u,0x0002u} /* DID: 0xA000 */                          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_SerialNumber_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xA000 */                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_SoftwareNumber_Read_ReadData)),  14u,  14u,0x0002u} /* DID: 0xA001 */                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_SoftwareNumber_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xA001 */              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Dataset_Part_No_and_Revision_Read_ReadData)),  12u,  12u,0x0002u} /* DID: 0xA002 */          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Dataset_Part_No_and_Revision_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xA002 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_SMC_Part_No_and_Revision_Read_ReadData)),  12u,  12u,0x0002u} /* DID: 0xA003 */              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_SMC_Part_No_and_Revision_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xA003 */    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Ego_Acceleration_Read_ReadData)),   1u,   1u,0x0002u} /* DID: 0xA004 */                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Ego_Acceleration_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xA004 */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Vehicle_Variant_Read_ReadData)),   1u,   1u,0x0002u} /* DID: 0xF010 */                       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Vehicle_Variant_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF010 */             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Static_Alignment_Engineering_Non_Configuration_Parameters_Read_ReadData)),  42u,  42u,0x0002u} /* DID: 0xF011 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Static_Alignment_Engineering_Non_Configuration_Parameters_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF011 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Static_Alignment_Engineering_Read_Parameters_Read_ReadData)),  22u,  22u,0x0002u} /* DID: 0xF012 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Static_Alignment_Engineering_Read_Parameters_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF012 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Static_Alignment_Engineering_Write_Configuration_Parameter_Write_WriteData)),   6u,   6u,0x1002u} /* DID: 0xF013 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Service_Alignment_Engineering_Non_Configuration_Parameters_Read_ReadData)),  14u,  14u,0x0002u} /* DID: 0xF014 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Service_Alignment_Engineering_Non_Configuration_Parameters_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF014 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Service_Alignment_Result_Parameters_Read_ReadData)),  87u,  87u,0x0002u} /* DID: 0xF015 */   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Service_Alignment_Result_Parameters_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF015 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Auto_Alignment_Status_Information_Read_ReadData)),  93u,  93u,0x0002u} /* DID: 0xF016 */     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Auto_Alignment_Status_Information_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF016 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Pin_Position_Status_Read_ReadData)),   2u,   2u,0x0002u} /* DID: 0xF017 */                   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Pin_Position_Status_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF017 */         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Manual_Alignment_Execution_Read_ReadData)),  10u,  10u,0x0002u} /* DID: 0xF01B */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Manual_Alignment_Execution_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF01B */  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Manual_Alignment_Execution_Read_WriteData)),  10u,  10u,0x1002u} /* DID: 0xF01B */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Static_Alignment_Result_Parameters_Read_ReadData)),  55u,  55u,0x0002u} /* DID: 0xF01C */    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Static_Alignment_Result_Parameters_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF01C */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Hardware_Version_number_Read_ReadData)),   5u,   5u,0x0002u} /* DID: 0xF150 */               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Hardware_Version_number_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF150 */     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Software_Fingerprint_Read_ReadData)),   4u,   4u,0x0002u} /* DID: 0xF15A */                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Software_Fingerprint_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF15A */        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Software_Fingerprint_Read_WriteData)),   4u,   4u,0x1002u} /* DID: 0xF15A */                 /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Boot_App_Identification_DID_Read_ReadData)),   1u,   1u,0x0002u} /* DID: 0xF16A */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Boot_App_Identification_DID_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF16A */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_BootloaderNumber_Read_ReadData)),  12u,  12u,0x0002u} /* DID: 0xF180 */                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_BootloaderNumber_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF180 */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_ActiveDiagnosticSessionDataIdentifier_Read_ReadData)),   1u,   1u,0x0002u} /* DID: 0xF186 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_ActiveDiagnosticSessionDataIdentifier_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF186 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Base_Software_Version_number_Read_ReadData)),   7u,   7u,0x0002u} /* DID: 0xF189 */          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Base_Software_Version_number_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF189 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_ECUBuildDate_Read_ReadData)),   4u,   4u,0x0002u} /* DID: 0xF18B */                          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_ECUBuildDate_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF18B */                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_VIN_Read_ReadData)),  17u,  17u,0x0002u} /* DID: 0xF190 */                                   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_VIN_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF190 */                         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_VIN_Read_WriteData)),  17u,  17u,0x1002u} /* DID: 0xF190 */                                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_HardwareNumber_Read_ReadData)),  13u,  13u,0x0002u} /* DID: 0xF191 */                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_HardwareNumber_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF191 */              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_CANDBMatrixVer_Read_ReadData)),   2u,   2u,0x0002u} /* DID: 0xF19D */                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_CANDBMatrixVer_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF19D */              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_PCAN_DBC_Version_Read_ReadData)),   2u,   2u,0x0002u} /* DID: 0xF19E */                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_PCAN_DBC_Version_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF19E */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Read_Active_Fault_Table_Read_ReadData)),  22u,  22u,0x0002u} /* DID: 0xFDA3 */               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Data_Read_Active_Fault_Table_Read_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xFDA3 */     /* PRQA S 0313 */ /* MD_Dcm_0313 */
};
/*! RID properties */
CONST(Dcm_CfgRidMgrRidInfoType, DCM_CONST) Dcm_CfgRidMgrRidInfo[8]=
{
   {    0u,   7u,0x01u, 0u} /* RID: 0x0200 */
  ,{    1u,   6u,0x01u, 0u} /* RID: 0x020E */
  ,{    2u,   4u,0x07u, 0u} /* RID: 0x7000 */
  ,{    5u,   4u,0x07u, 0u} /* RID: 0x7003 */
  ,{    8u,   4u,0x05u, 0u} /* RID: 0x7004 */
  ,{   10u,   4u,0x05u, 0u} /* RID: 0x7005 */
  ,{   12u,   6u,0x01u, 0u} /* RID: 0xFF00 */
  ,{   13u,   6u,0x01u, 0u} /* RID: 0xFF01 */
};
/*! RID operation properties */
CONST(Dcm_CfgRidMgrOpInfoType, DCM_CONST) Dcm_CfgRidMgrOpInfo[14]=
{
   { ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_CheckProgPreCond_Start_Start)),   0u,   0u,   2u,   2u, 3u, 0u} /* RID: 0x0200 */      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_CheckSig_Start_Start)),   0u,   0u,   1u,   1u, 3u, 0u} /* RID: 0x020E */              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_Static_Alignment_Execution_Start_Start)),   0u,   0u,   0u,   0u, 0u, 0u} /* RID: 0x7000 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_Static_Alignment_Execution_Start_Stop)),   0u,   0u,   0u,   0u, 0u, 0u} /* RID: 0x7000 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_Static_Alignment_Execution_Start_RequestResults)),   0u,   0u,   3u,   3u, 3u, 0u} /* RID: 0x7000 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_Service_Alignment_Execution_Start_Start)),   0u,   0u,   0u,   0u, 0u, 0u} /* RID: 0x7003 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_Service_Alignment_Execution_Start_Stop)),   0u,   0u,   0u,   0u, 0u, 0u} /* RID: 0x7003 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_Service_Alignment_Execution_Start_RequestResults)),   0u,   0u,  28u,  28u, 3u, 0u} /* RID: 0x7003 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_Pin_Position_Lock_Start_Start)),   1u,   1u,   1u,   1u, 2u, 0u} /* RID: 0x7004 */     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_Pin_Position_Lock_Start_RequestResults)),   0u,   0u,   1u,   1u, 3u, 0u} /* RID: 0x7004 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_Pin_Position_Unlock_Start_Start)),   1u,   1u,   1u,   1u, 2u, 0u} /* RID: 0x7005 */   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_Pin_Position_Unlock_Start_RequestResults)),   0u,   0u,   1u,   1u, 3u, 0u} /* RID: 0x7005 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_EraseMem_Start_Start)),   9u,   9u,   1u,   1u, 2u, 0u} /* RID: 0xFF00 */              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_CheckProgDep_Start_Start)),   0u,   0u,   1u,   1u, 3u, 0u} /* RID: 0xFF01 */          /* PRQA S 0313 */ /* MD_Dcm_0313 */
};
/*! DCM service initializers */
CONST(Dcm_DiagSvcInitFuncType, DCM_CONST) Dcm_CfgDiagSvcInitializers[1]=
{
   Dcm_Service27Init
};
/*! DCM service properties */
CONST(Dcm_CfgDiagServiceInfoType, DCM_CONST) Dcm_CfgDiagServiceInfo[15]=
{
   { Dcm_Service10Processor,0x01u, 1u,   1u,   2u, 0u, 0u, 0u, 0u} /* SID: 0x10 */
  ,{ Dcm_Service11Processor,0x01u, 1u,   3u,   4u, 0u, 0u, 0u, 0u} /* SID: 0x11 */
  ,{ Dcm_Service14Processor,0x00u, 3u,   0u,   0u, 0u, 1u, 0u, 0u} /* SID: 0x14 */
  ,{ Dcm_Service19Processor,0x01u, 1u,   5u,   0u, 2u, 2u, 0u, 0u} /* SID: 0x19 */
  ,{ Dcm_Service22Processor,0x00u, 2u,   6u,   0u, 0u, 3u, 0u, 0u} /* SID: 0x22 */
  ,{ Dcm_Service27Processor,0x03u, 1u,   7u,   0u, 0u, 0u, 0u, 0u} /* SID: 0x27 */
  ,{ Dcm_Service28Processor,0x01u, 1u,   8u,   0u, 0u, 0u, 0u, 0u} /* SID: 0x28 */
  ,{ Dcm_Service2EProcessor,0x00u, 3u,   0u,   0u, 0u, 0u, 0u, 0u} /* SID: 0x2E */
  ,{ Dcm_Service31Processor,0x01u, 3u,   0u,   0u, 0u, 0u, 0u, 0u} /* SID: 0x31 */
  ,{ Dcm_Service34Processor,0x00u, 4u,   0u,   0u, 0u, 0u, 0u, 0u} /* SID: 0x34 */
  ,{ Dcm_Service36Processor,0x00u, 1u,   0u,   0u, 0u, 0u, 0u, 0u} /* SID: 0x36 */
  ,{ Dcm_Service37Processor,0x00u, 0u,   0u,   0u, 0u, 0u, 0u, 0u} /* SID: 0x37 */
  ,{ Dcm_Service3EProcessor,0x01u, 1u,   0u,   0u, 0u, 0u, 0u, 0u} /* SID: 0x3E */
  ,{ Dcm_Service85Processor,0x01u, 1u,   9u,   0u, 0u, 4u, 0u, 0u} /* SID: 0x85 */
  ,{ Dcm_RepeaterDeadEnd,0x00u, 0u,   0u,   0u, 0u, 0u, 0u, 0u} /* Dcm_RepeaterDeadEnd */
};
/*! Indirection from diag service info to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgDiagSvcIdExecPrecondTable[14]=
{
      0u /* SID: 0x10 */
  ,   0u /* SID: 0x11 */
  ,   2u /* SID: 0x14 */
  ,   2u /* SID: 0x19 */
  ,   0u /* SID: 0x22 */
  ,   3u /* SID: 0x27 */
  ,   4u /* SID: 0x28 */
  ,   1u /* SID: 0x2E */
  ,   3u /* SID: 0x31 */
  ,   5u /* SID: 0x34 */
  ,   5u /* SID: 0x36 */
  ,   5u /* SID: 0x37 */
  ,   0u /* SID: 0x3E */
  ,   4u /* SID: 0x85 */
};
/*! DCM service post processors */
CONST(Dcm_DiagSvcConfirmationFuncType, DCM_CONST) Dcm_CfgDiagSvcPostProcessors[10]=
{
   Dcm_ServiceNoPostProcessor
  ,Dcm_Service10PostProcessor
  ,Dcm_Service10FastPostProcessor
  ,Dcm_Service11PostProcessor
  ,Dcm_Service11FastPostProcessor
  ,Dcm_Service19PostProcessor
  ,Dcm_Service22PostProcessor
  ,Dcm_Service27PostProcessor
  ,Dcm_Service28PostProcessor
  ,Dcm_Service85PostProcessor
};
/*! DCM service paged buffer updater */
CONST(Dcm_DiagSvcUpdateFuncType, DCM_CONST) Dcm_CfgDiagSvcUpdaters[3]=
{
   Dcm_ServiceNoUpdater
  ,Dcm_PagedBufferDataPadding
  ,Dcm_Service19Updater
};
/*! DCM service paged buffer canceller */
CONST(Dcm_DiagSvcCancelFuncType, DCM_CONST) Dcm_CfgDiagSvcCancellers[5]=
{
   Dcm_ServiceNoCancel
  ,Dcm_Service14Cancel
  ,Dcm_Service19Cancel
  ,Dcm_Service22Cancel
  ,Dcm_Service85Cancel
};
/*! DCM service pre handler */
CONST(Dcm_DiagSvcPreHandlerFuncType, DCM_CONST) Dcm_CfgDiagSvcPreHandlers[1]=
{
   Dcm_ServiceNoPreHandler
};
/*! DCM service post handler */
CONST(Dcm_DiagSvcPostHandlerFuncType, DCM_CONST) Dcm_CfgDiagSvcPostHandlers[1]=
{
   Dcm_ServiceNoPostHandler
};
/*! System supplier notification functions */
CONST(Dcm_CfgDiagNotificationInfoType, DCM_CONST) Dcm_CfgDiagSysNotificationInfo[1]=
{
   { Rte_Call_ServiceRequestSupplierNotification_DcmDslServiceRequestSupplierNotification_Indication,Rte_Call_ServiceRequestSupplierNotification_DcmDslServiceRequestSupplierNotification_Confirmation}
};
/*! DCM service to protocol map */
CONST(Dcm_CfgDiagSvc2ProtMapMemType, DCM_CONST) Dcm_CfgDiagSvcId2ProtMap[14]=
{
   0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
};
/*! Dcm all variant root */
CONST(Dcm_ConfigsType, DCM_CONST) Dcm_CfgConfigsRoot=
{
   
  {
      0u
  }
};
/*! Service 0x10 sub-service properties table  */
CONST(Dcm_CfgSvc10SubFuncInfoType, DCM_CONST) Dcm_CfgSvc10SubFuncInfo[3]=
{
   { { 50u, 195u}} /* Session ID: 0x01 */
  ,{ { 50u, 195u}} /* Session ID: 0x02 */
  ,{ { 50u, 195u}} /* Session ID: 0x03 */
};
/*! Indirection from service 0x10 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc10SubFuncExecPrecondTable[3]=
{
      0u /* Session ID: 0x01 */
  ,   1u /* Session ID: 0x02 */
  ,   2u /* Session ID: 0x03 */
};
/*! Service 0x11 sub-service properties table  */
CONST(Dcm_CfgSvc11SubFuncInfoType, DCM_CONST) Dcm_CfgSvc11SubFuncInfo[2]=
{
   { Dcm_Service11_01Processor} /* SF: 0x01 */
  ,{ Dcm_Service11_03Processor} /* SF: 0x03 */
};
/*! Indirection from service 0x11 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc11SubFuncExecPrecondTable[2]=
{
      0u /* SF: 0x01 */
  ,   0u /* SF: 0x03 */
};
/*! Service 0x19 sub-service properties table  */
CONST(Dcm_CfgSvc19SubFuncInfoType, DCM_CONST) Dcm_CfgSvc19SubFuncInfo[3]=
{
   { Dcm_Service19_02Processor, 2u} /* SF: 0x02 */
  ,{ Dcm_Service19_04Processor, 5u} /* SF: 0x04 */
  ,{ Dcm_Service19_06Processor, 5u} /* SF: 0x06 */
};
/*! Indirection from service 0x19 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc19SubFuncExecPrecondTable[3]=
{
      2u /* SF: 0x02 */
  ,   2u /* SF: 0x04 */
  ,   2u /* SF: 0x06 */
};
/*! Service 0x27 security level properties table  */
CONST(Dcm_CfgSvc27SecLevelInfoType, DCM_CONST) Dcm_CfgSvc27SecLevelInfo[1]=
{
   { ((Dcm_Svc27GetSeedFuncType)(Rte_Call_SecurityAccess_UnlockedL1_GetSeed)),Rte_Call_SecurityAccess_UnlockedL1_CompareKey,Rte_Call_SecurityAccess_UnlockedL1_GetSecurityAttemptCounter,Rte_Call_SecurityAccess_UnlockedL1_SetSecurityAttemptCounter,  16u,  16u,   0u, 0u} /* SecLvl: UnlockedL1 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
};
/*! Indirection from service 0x27 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc27SubFuncExecPrecondTable[2]=
{
      3u /* SF: 0x11 */
  ,   3u /* SF: 0x12 */
};
/*! Service 0x28 sub-service properties table  */
CONST(Dcm_CfgSvc28SubFuncInfoType, DCM_CONST) Dcm_CfgSvc28SubFuncInfo[4]=
{
   { Dcm_Service28_XXProcessor, 2u} /* SF: 0x00 */
  ,{ Dcm_Service28_XXProcessor, 2u} /* SF: 0x01 */
  ,{ Dcm_Service28_XXProcessor, 2u} /* SF: 0x02 */
  ,{ Dcm_Service28_XXProcessor, 2u} /* SF: 0x03 */
};
/*! Indirection from service 0x28 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc28SubFuncExecPrecondTable[4]=
{
      4u /* SF: 0x00 */
  ,   4u /* SF: 0x01 */
  ,   4u /* SF: 0x02 */
  ,   4u /* SF: 0x03 */
};
/*! Service 0x28 network ID to ComM channel map */
CONST(NetworkHandleType, DCM_CONST) Dcm_CfgSvc28SubNetIdMap[1]=
{
   DCM_SVC_28_NETWORK_CURRENT
};
/*! Indirection from service 0x3E sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc3ESubFuncExecPrecondTable[1]=
{
      0u /* SF: 0x00 */
};
/*! Indirection from service 0x85 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc85SubFuncExecPrecondTable[2]=
{
      4u /* SF: 0x01 */
  ,   4u /* SF: 0x02 */
};
/*! DCM service 0x85 properties */
CONST(Dcm_CfgSvc85SubFuncInfoType, DCM_CONST) Dcm_CfgSvc85SubFuncInfo[2]=
{
   { Dem_EnableDTCSetting,RTE_MODE_DcmControlDtcSetting_ENABLEDTCSETTING} /* SF: 0x01 */
  ,{ Dem_DisableDTCSetting,RTE_MODE_DcmControlDtcSetting_DISABLEDTCSETTING} /* SF: 0x02 */
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
#define DCM_START_SEC_CALLOUT_CODE
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  Dcm_ModeOnComControlModeChange()
***********************************************************************************************************************/
/* Implements CDD Dcm_ModeOnComControlModeChange() */
FUNC(void, DCM_CODE) Dcm_ModeOnComControlModeChange(NetworkHandleType channelId, Dcm_CommunicationModeType mode)
{
  switch(channelId)
  {
    case ComMConf_ComMChannel_CN_PCAN_RADAR_458ff0f1:
      ((void)(Rte_Switch_DcmCommunicationControl_ComMConf_ComMChannel_CN_PCAN_RADAR_458ff0f1_DcmCommunicationControl_ComMConf_ComMChannel_CN_PCAN_RADAR_458ff0f1(mode)));
      break;
    case ComMConf_ComMChannel_CN_VCAN_RADAR_489180b6:
      ((void)(Rte_Switch_DcmCommunicationControl_ComMConf_ComMChannel_CN_VCAN_RADAR_489180b6_DcmCommunicationControl_ComMConf_ComMChannel_CN_VCAN_RADAR_489180b6(mode)));
      break;
    default: /* Just exit the switch case */
      break;
  }
}

/***********************************************************************************************************************
 *  Dcm_ServiceNoPostProcessor()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_ServiceNoPostProcessor() */
DCM_LOCAL FUNC(void, DCM_CALLOUT_CODE) Dcm_ServiceNoPostProcessor(
  Dcm_ThreadIdType threadId,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_ConfirmationStatusType status
  )
{
  DCM_IGNORE_UNREF_PARAM(threadId);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(status);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
}
/***********************************************************************************************************************
 *  Dcm_ServiceNoUpdater()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_ServiceNoUpdater() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ServiceNoUpdater(
  Dcm_ThreadIdType threadId,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_OpStatusType opStatus,
  Dcm_DiagDataContextPtrType pDataContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  DCM_IGNORE_UNREF_PARAM(threadId);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(opStatus);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(pDataContext);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(ErrorCode);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
}
/***********************************************************************************************************************
 *  Dcm_ServiceNoCancel()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_ServiceNoCancel() */
DCM_LOCAL FUNC(void, DCM_CALLOUT_CODE) Dcm_ServiceNoCancel(
  Dcm_ThreadIdType threadId  /* PRQA S 3673 */ /* MD_Dcm_Design_3673 */
  )
{
  DCM_IGNORE_UNREF_PARAM(threadId);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  /* nothing to do */
}
/***********************************************************************************************************************
 *  Dcm_ServiceNoPreHandler()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_ServiceNoPreHandler() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ServiceNoPreHandler(  /* PRQA S 6060 */ /* MD_MSR_STPAR */
  Dcm_OpStatusType OpStatus,
  uint8 SID,
  P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) RequestData,
  uint32 DataSize,
  Dcm_ProtocolType ProtocolType,
  uint16 SourceAddress,
  uint16 ConnectionId,
  uint8 ReqType,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  DCM_IGNORE_UNREF_PARAM(OpStatus);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(SID);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(RequestData);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(DataSize);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(ProtocolType);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(SourceAddress);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(ConnectionId);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(ReqType);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(ErrorCode);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}
/***********************************************************************************************************************
 *  Dcm_ServiceNoPostHandler()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_ServiceNoPostHandler() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ServiceNoPostHandler(  /* PRQA S 6060 */ /* MD_MSR_STPAR */
  Dcm_OpStatusType OpStatus,
  uint8 SID,
  P2CONST(uint8, AUTOMATIC, DCM_VAR_NOINIT) ResponseData,
  uint32 DataSize,
  Dcm_ProtocolType ProtocolType,
  uint16 SourceAddress,
  uint16 ConnectionId,
  uint8 ReqType,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR_NOINIT) ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  DCM_IGNORE_UNREF_PARAM(OpStatus);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(SID);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(ResponseData);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(DataSize);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(ProtocolType);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(SourceAddress);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(ConnectionId);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(ReqType);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(ErrorCode);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  return E_OK;
}
#define DCM_STOP_SEC_CALLOUT_CODE
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Dcm_Lcfg.c
 *********************************************************************************************************************/

