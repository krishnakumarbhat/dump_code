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
 *            Module: Com
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Com_Cfg_ReceptionProcessingData.h
 *   Generation Time: 2026-08-11 15:50:27
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

#if !defined (COM_CFG_RECEPTIONPROCESSINGDATA_H)
# define COM_CFG_RECEPTIONPROCESSINGDATA_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "Com_Lcfg.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/* VCA Disable RCH-21 : VCA_COM_FUNCTION_NOT_USED_AND_NO_ANALYSIS_ENTRY */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIZEOF INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define COM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComPCSizeOfInlineFunctionPrototypes  SizeOf Inline Function Prototypes
  \brief  These inline functions are used to get SizeOf data.
  \{
*/ 
COM_LOCAL_INLINE FUNC(Com_SizeOfIPduGroupInfoOfRxPduInfoIndType, COM_CODE) Com_GetSizeOfIPduGroupInfoOfRxPduInfoInd(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxAccessInfoType, COM_CODE) Com_GetSizeOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxAccessInfoGrpSigIndType, COM_CODE) Com_GetSizeOfRxAccessInfoGrpSigInd(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxAccessInfoIndType, COM_CODE) Com_GetSizeOfRxAccessInfoInd(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxInvalidationInfoIndType, COM_CODE) Com_GetSizeOfRxInvalidationInfoInd(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxPduInfoType, COM_CODE) Com_GetSizeOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigGrpInfoType, COM_CODE) Com_GetSizeOfRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigGrpInfoIndType, COM_CODE) Com_GetSizeOfRxSigGrpInfoInd(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigInfoType, COM_CODE) Com_GetSizeOfRxSigInfo(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxTOutInfoIndType, COM_CODE) Com_GetSizeOfRxTOutInfoInd(void);
/** 
  \}
*/ 

#define COM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define COM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComPCGetDataInlineFunctionPrototypes  Get Data Inline Function Prototypes
  \brief  These inline functions can be used to read CONST and VAR data.
  \{
*/ 
COM_LOCAL_INLINE FUNC(Com_IPduGroupInfoOfRxPduInfoIndType, COM_CODE) Com_GetIPduGroupInfoOfRxPduInfoInd(Com_IPduGroupInfoOfRxPduInfoIndIterType Index);
COM_LOCAL_INLINE FUNC(Com_ApplTypeOfRxAccessInfoType, COM_CODE) Com_GetApplTypeOfRxAccessInfo(Com_RxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_DeserializerInfoIdxOfRxAccessInfoType, COM_CODE) Com_GetDeserializerInfoIdxOfRxAccessInfo(Com_RxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterInfoIdxOfRxAccessInfoType, COM_CODE) Com_GetFilterInfoIdxOfRxAccessInfo(Com_RxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterInfoUsedOfRxAccessInfoType, COM_CODE) Com_IsFilterInfoUsedOfRxAccessInfo(Com_RxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwInfoIdxOfRxAccessInfoType, COM_CODE) Com_GetGwInfoIdxOfRxAccessInfo(Com_RxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwInfoUsedOfRxAccessInfoType, COM_CODE) Com_IsGwInfoUsedOfRxAccessInfo(Com_RxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_InvalidHndOfRxAccessInfoType, COM_CODE) Com_IsInvalidHndOfRxAccessInfo(Com_RxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxBufferInfoIdxOfRxAccessInfoType, COM_CODE) Com_GetRxBufferInfoIdxOfRxAccessInfo(Com_RxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxBufferInfoMinProcGwBufferIdxOfRxAccessInfoType, COM_CODE) Com_GetRxBufferInfoMinProcGwBufferIdxOfRxAccessInfo(Com_RxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxBufferInfoMinProcGwBufferUsedOfRxAccessInfoType, COM_CODE) Com_IsRxBufferInfoMinProcGwBufferUsedOfRxAccessInfo(Com_RxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxBufferInfoShdwBufferIdxOfRxAccessInfoType, COM_CODE) Com_GetRxBufferInfoShdwBufferIdxOfRxAccessInfo(Com_RxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxDynSignalLengthIdxOfRxAccessInfoType, COM_CODE) Com_GetRxDynSignalLengthIdxOfRxAccessInfo(Com_RxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxDynSignalLengthUsedOfRxAccessInfoType, COM_CODE) Com_IsRxDynSignalLengthUsedOfRxAccessInfo(Com_RxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxDynSignalTmpLengthForSignalGroupsIdxOfRxAccessInfoType, COM_CODE) Com_GetRxDynSignalTmpLengthForSignalGroupsIdxOfRxAccessInfo(Com_RxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxDynSignalTmpLengthForSignalGroupsUsedOfRxAccessInfoType, COM_CODE) Com_IsRxDynSignalTmpLengthForSignalGroupsUsedOfRxAccessInfo(Com_RxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxPduInfoIdxOfRxAccessInfoType, COM_CODE) Com_GetRxPduInfoIdxOfRxAccessInfo(Com_RxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoIdxOfRxAccessInfoType, COM_CODE) Com_GetRxTOutInfoIdxOfRxAccessInfo(Com_RxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_SignalLengthInByteOfRxAccessInfoType, COM_CODE) Com_GetSignalLengthInByteOfRxAccessInfo(Com_RxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_StartByteInPduPositionOfRxAccessInfoType, COM_CODE) Com_GetStartByteInPduPositionOfRxAccessInfo(Com_RxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoIndType, COM_CODE) Com_GetRxAccessInfoInd(Com_RxAccessInfoIndIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxInvalidationInfoIndType, COM_CODE) Com_GetRxInvalidationInfoInd(Com_RxInvalidationInfoIndIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwInfoEndIdxOfRxPduInfoType, COM_CODE) Com_GetGwInfoEndIdxOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwInfoStartIdxOfRxPduInfoType, COM_CODE) Com_GetGwInfoStartIdxOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwInfoUsedOfRxPduInfoType, COM_CODE) Com_IsGwInfoUsedOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwTxPduDescriptionInfoEndIdxOfRxPduInfoType, COM_CODE) Com_GetGwTxPduDescriptionInfoEndIdxOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwTxPduDescriptionInfoStartIdxOfRxPduInfoType, COM_CODE) Com_GetGwTxPduDescriptionInfoStartIdxOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwTxPduDescriptionInfoUsedOfRxPduInfoType, COM_CODE) Com_IsGwTxPduDescriptionInfoUsedOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_HandleRxDeferredGwDescriptionIdxOfRxPduInfoType, COM_CODE) Com_GetHandleRxDeferredGwDescriptionIdxOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_HandleRxDeferredGwDescriptionUsedOfRxPduInfoType, COM_CODE) Com_IsHandleRxDeferredGwDescriptionUsedOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_HandleRxPduDeferredIdxOfRxPduInfoType, COM_CODE) Com_GetHandleRxPduDeferredIdxOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_IPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfoType, COM_CODE) Com_GetIPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_InvalidHndOfRxPduInfoType, COM_CODE) Com_IsInvalidHndOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_MainFunctionRouteSignalsStructIdxOfRxPduInfoType, COM_CODE) Com_GetMainFunctionRouteSignalsStructIdxOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_MainFunctionRouteSignalsStructUsedOfRxPduInfoType, COM_CODE) Com_IsMainFunctionRouteSignalsStructUsedOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_MainFunctionRxStructIdxOfRxPduInfoType, COM_CODE) Com_GetMainFunctionRxStructIdxOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ReportingRxIPduCalloutIdxOfRxPduInfoType, COM_CODE) Com_GetReportingRxIPduCalloutIdxOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ReportingRxIPduCalloutUsedOfRxPduInfoType, COM_CODE) Com_IsReportingRxIPduCalloutUsedOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoIndEndIdxOfRxPduInfoType, COM_CODE) Com_GetRxAccessInfoIndEndIdxOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoIndStartIdxOfRxPduInfoType, COM_CODE) Com_GetRxAccessInfoIndStartIdxOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxDefPduBufferEndIdxOfRxPduInfoType, COM_CODE) Com_GetRxDefPduBufferEndIdxOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxDefPduBufferStartIdxOfRxPduInfoType, COM_CODE) Com_GetRxDefPduBufferStartIdxOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxMetaDataBufferInfoIdxOfRxPduInfoType, COM_CODE) Com_GetRxMetaDataBufferInfoIdxOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxMetaDataBufferInfoUsedOfRxPduInfoType, COM_CODE) Com_IsRxMetaDataBufferInfoUsedOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigGrpInfoIndStartIdxOfRxPduInfoType, COM_CODE) Com_GetRxSigGrpInfoIndStartIdxOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigInfoEndIdxOfRxPduInfoType, COM_CODE) Com_GetRxSigInfoEndIdxOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigInfoStartIdxOfRxPduInfoType, COM_CODE) Com_GetRxSigInfoStartIdxOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigInfoUsedOfRxPduInfoType, COM_CODE) Com_IsRxSigInfoUsedOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoIdxOfRxPduInfoType, COM_CODE) Com_GetRxTOutInfoIdxOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoIndEndIdxOfRxPduInfoType, COM_CODE) Com_GetRxTOutInfoIndEndIdxOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoIndStartIdxOfRxPduInfoType, COM_CODE) Com_GetRxTOutInfoIndStartIdxOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxTpInfoIdxOfRxPduInfoType, COM_CODE) Com_GetRxTpInfoIdxOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxTpInfoUsedOfRxPduInfoType, COM_CODE) Com_IsRxTpInfoUsedOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterEventOfRxSigGrpInfoType, COM_CODE) Com_IsFilterEventOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwInfoIdxOfRxSigGrpInfoType, COM_CODE) Com_GetGwInfoIdxOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwInfoUsedOfRxSigGrpInfoType, COM_CODE) Com_IsGwInfoUsedOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_InvalidHndOfRxSigGrpInfoType, COM_CODE) Com_IsInvalidHndOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ReportingIndicationNotificationIdxOfRxSigGrpInfoType, COM_CODE) Com_GetReportingIndicationNotificationIdxOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoGrpSigIndEndIdxOfRxSigGrpInfoType, COM_CODE) Com_GetRxAccessInfoGrpSigIndEndIdxOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoGrpSigIndStartIdxOfRxSigGrpInfoType, COM_CODE) Com_GetRxAccessInfoGrpSigIndStartIdxOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxBufferInfoIdxOfRxSigGrpInfoType, COM_CODE) Com_GetRxBufferInfoIdxOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxInvalidationInfoIndEndIdxOfRxSigGrpInfoType, COM_CODE) Com_GetRxInvalidationInfoIndEndIdxOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxInvalidationInfoIndStartIdxOfRxSigGrpInfoType, COM_CODE) Com_GetRxInvalidationInfoIndStartIdxOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxInvalidationInfoIndUsedOfRxSigGrpInfoType, COM_CODE) Com_IsRxInvalidationInfoIndUsedOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxPduInfoIdxOfRxSigGrpInfoType, COM_CODE) Com_GetRxPduInfoIdxOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoIdxOfRxSigGrpInfoType, COM_CODE) Com_GetRxTOutInfoIdxOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ShdBufferRequiredOfRxSigGrpInfoType, COM_CODE) Com_IsShdBufferRequiredOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_StartBytePositionOfRxSigGrpInfoType, COM_CODE) Com_GetStartBytePositionOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_UpdateBitInfoIdxOfRxSigGrpInfoType, COM_CODE) Com_GetUpdateBitInfoIdxOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_UpdateBitInfoUsedOfRxSigGrpInfoType, COM_CODE) Com_IsUpdateBitInfoUsedOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ValidDlcOfRxSigGrpInfoType, COM_CODE) Com_GetValidDlcOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigGrpInfoIndType, COM_CODE) Com_GetRxSigGrpInfoInd(Com_RxSigGrpInfoIndIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwInfoIdxOfRxSigInfoType, COM_CODE) Com_GetGwInfoIdxOfRxSigInfo(Com_RxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwInfoUsedOfRxSigInfoType, COM_CODE) Com_IsGwInfoUsedOfRxSigInfo(Com_RxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ReportingIndicationNotificationIdxOfRxSigInfoType, COM_CODE) Com_GetReportingIndicationNotificationIdxOfRxSigInfo(Com_RxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ReportingIndicationNotificationUsedOfRxSigInfoType, COM_CODE) Com_IsReportingIndicationNotificationUsedOfRxSigInfo(Com_RxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoIdxOfRxSigInfoType, COM_CODE) Com_GetRxAccessInfoIdxOfRxSigInfo(Com_RxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxInvalidationInfoIdxOfRxSigInfoType, COM_CODE) Com_GetRxInvalidationInfoIdxOfRxSigInfo(Com_RxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxInvalidationInfoUsedOfRxSigInfoType, COM_CODE) Com_IsRxInvalidationInfoUsedOfRxSigInfo(Com_RxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoIdxOfRxSigInfoType, COM_CODE) Com_GetRxTOutInfoIdxOfRxSigInfo(Com_RxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoUsedOfRxSigInfoType, COM_CODE) Com_IsRxTOutInfoUsedOfRxSigInfo(Com_RxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_UpdateBitInfoIdxOfRxSigInfoType, COM_CODE) Com_GetUpdateBitInfoIdxOfRxSigInfo(Com_RxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_UpdateBitInfoUsedOfRxSigInfoType, COM_CODE) Com_IsUpdateBitInfoUsedOfRxSigInfo(Com_RxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ValidDlcOfRxSigInfoType, COM_CODE) Com_GetValidDlcOfRxSigInfo(Com_RxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoIndType, COM_CODE) Com_GetRxTOutInfoInd(Com_RxTOutInfoIndIterType Index);
/** 
  \}
*/ 

#define COM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComPCGetDeduplicatedInlineFunctionPrototypes  Get Deduplicated Inline Function Prototypes
  \brief  These inline functions  can be used to read deduplicated data elements.
  \{
*/ 
COM_LOCAL_INLINE FUNC(Com_DeserializerInfoUsedOfRxAccessInfoType, COM_CODE) Com_IsDeserializerInfoUsedOfRxAccessInfo(Com_RxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxBufferInfoShdwBufferUsedOfRxAccessInfoType, COM_CODE) Com_IsRxBufferInfoShdwBufferUsedOfRxAccessInfo(Com_RxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxBufferInfoUsedOfRxAccessInfoType, COM_CODE) Com_IsRxBufferInfoUsedOfRxAccessInfo(Com_RxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoUsedOfRxAccessInfoType, COM_CODE) Com_IsRxTOutInfoUsedOfRxAccessInfo(Com_RxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoGrpSigIndType, COM_CODE) Com_GetRxAccessInfoGrpSigInd(Com_RxAccessInfoGrpSigIndIterType Index);
COM_LOCAL_INLINE FUNC(Com_HandleRxPduDeferredUsedOfRxPduInfoType, COM_CODE) Com_IsHandleRxPduDeferredUsedOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_IPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfoType, COM_CODE) Com_GetIPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfoType, COM_CODE) Com_IsIPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_MainFunctionRxStructUsedOfRxPduInfoType, COM_CODE) Com_IsMainFunctionRxStructUsedOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_MetaDataLengthOfRxPduInfoType, COM_CODE) Com_GetMetaDataLengthOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_PartitionsRxStructIdxOfRxPduInfoType, COM_CODE) Com_GetPartitionsRxStructIdxOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoIndUsedOfRxPduInfoType, COM_CODE) Com_IsRxAccessInfoIndUsedOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxDefPduBufferLengthOfRxPduInfoType, COM_CODE) Com_GetRxDefPduBufferLengthOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxDefPduBufferUsedOfRxPduInfoType, COM_CODE) Com_IsRxDefPduBufferUsedOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigGrpInfoIndEndIdxOfRxPduInfoType, COM_CODE) Com_GetRxSigGrpInfoIndEndIdxOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigGrpInfoIndUsedOfRxPduInfoType, COM_CODE) Com_IsRxSigGrpInfoIndUsedOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoIndUsedOfRxPduInfoType, COM_CODE) Com_IsRxTOutInfoIndUsedOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoUsedOfRxPduInfoType, COM_CODE) Com_IsRxTOutInfoUsedOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_SignalProcessingOfRxPduInfoType, COM_CODE) Com_GetSignalProcessingOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TypeOfRxPduInfoType, COM_CODE) Com_GetTypeOfRxPduInfo(Com_RxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ArrayAccessUsedOfRxSigGrpInfoType, COM_CODE) Com_IsArrayAccessUsedOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ReportingIndicationNotificationUsedOfRxSigGrpInfoType, COM_CODE) Com_IsReportingIndicationNotificationUsedOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoGrpSigIndUsedOfRxSigGrpInfoType, COM_CODE) Com_IsRxAccessInfoGrpSigIndUsedOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxBufferInfoUsedOfRxSigGrpInfoType, COM_CODE) Com_IsRxBufferInfoUsedOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoUsedOfRxSigGrpInfoType, COM_CODE) Com_IsRxTOutInfoUsedOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index);
/** 
  \}
*/ 

#define COM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComPCHasInlineFunctionPrototypes  Has Inline Function Prototypes
  \brief  These inline functions can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasIPduGroupInfoOfRxPduInfoInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasApplTypeOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasDeserializerInfoIdxOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasDeserializerInfoUsedOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfoIdxOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfoUsedOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwInfoIdxOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwInfoUsedOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvalidHndOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxBufferInfoIdxOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxBufferInfoMinProcGwBufferIdxOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxBufferInfoMinProcGwBufferUsedOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxBufferInfoShdwBufferIdxOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxBufferInfoShdwBufferUsedOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxBufferInfoUsedOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDynSignalLengthIdxOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDynSignalLengthUsedOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDynSignalTmpLengthForSignalGroupsIdxOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDynSignalTmpLengthForSignalGroupsUsedOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxPduInfoIdxOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoIdxOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoUsedOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSignalLengthInByteOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasStartByteInPduPositionOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoGrpSigInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxInvalidationInfoInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwInfoEndIdxOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwInfoStartIdxOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwInfoUsedOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwTxPduDescriptionInfoEndIdxOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwTxPduDescriptionInfoStartIdxOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwTxPduDescriptionInfoUsedOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasHandleRxDeferredGwDescriptionIdxOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasHandleRxDeferredGwDescriptionUsedOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasHandleRxPduDeferredIdxOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasHandleRxPduDeferredUsedOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasIPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasIPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasIPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvalidHndOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMainFunctionRouteSignalsStructIdxOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMainFunctionRouteSignalsStructUsedOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMainFunctionRxStructIdxOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMainFunctionRxStructUsedOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataLengthOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasPartitionsRxStructIdxOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingRxIPduCalloutIdxOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingRxIPduCalloutUsedOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoIndEndIdxOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoIndStartIdxOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoIndUsedOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDefPduBufferEndIdxOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDefPduBufferLengthOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDefPduBufferStartIdxOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDefPduBufferUsedOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxMetaDataBufferInfoIdxOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxMetaDataBufferInfoUsedOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigGrpInfoIndEndIdxOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigGrpInfoIndStartIdxOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigGrpInfoIndUsedOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigInfoEndIdxOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigInfoStartIdxOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigInfoUsedOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoIdxOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoIndEndIdxOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoIndStartIdxOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoIndUsedOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoUsedOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTpInfoIdxOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTpInfoUsedOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSignalProcessingOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTypeOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasArrayAccessUsedOfRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterEventOfRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwInfoIdxOfRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwInfoUsedOfRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvalidHndOfRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingIndicationNotificationIdxOfRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingIndicationNotificationUsedOfRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoGrpSigIndEndIdxOfRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoGrpSigIndStartIdxOfRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoGrpSigIndUsedOfRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxBufferInfoIdxOfRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxBufferInfoUsedOfRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxInvalidationInfoIndEndIdxOfRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxInvalidationInfoIndStartIdxOfRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxInvalidationInfoIndUsedOfRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxPduInfoIdxOfRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoIdxOfRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoUsedOfRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasShdBufferRequiredOfRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasStartBytePositionOfRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasUpdateBitInfoIdxOfRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasUpdateBitInfoUsedOfRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasValidDlcOfRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigGrpInfoInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwInfoIdxOfRxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwInfoUsedOfRxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingIndicationNotificationIdxOfRxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingIndicationNotificationUsedOfRxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoIdxOfRxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxInvalidationInfoIdxOfRxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxInvalidationInfoUsedOfRxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoIdxOfRxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoUsedOfRxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasUpdateBitInfoIdxOfRxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasUpdateBitInfoUsedOfRxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasValidDlcOfRxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfIPduGroupInfoOfRxPduInfoInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxAccessInfoGrpSigInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxAccessInfoInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxInvalidationInfoInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigGrpInfoInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxTOutInfoInd(void);
/** 
  \}
*/ 

#define COM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComPCEsistsEnumInlineFunctionPrototypes  Esists Enum Inline Function Prototypes
  \brief  These inilne functions can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsUINT8ApplTypeOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsSINT8ApplTypeOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsUINT16ApplTypeOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsSINT16ApplTypeOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsUINT32ApplTypeOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsSINT32ApplTypeOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsUINT64ApplTypeOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsSINT64ApplTypeOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsUINT8_NApplTypeOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsUINT8_DYNApplTypeOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsZEROBITApplTypeOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFLOAT32ApplTypeOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFLOAT64ApplTypeOfRxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsDEFERREDSignalProcessingOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsIMMEDIATESignalProcessingOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNORMALTypeOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTPTypeOfRxPduInfo(void);
/** 
  \}
*/ 

#define COM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */





/**********************************************************************************************************************
  GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/
#define COM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComPCSizeOfInlineFunctions  Com SizeOf Inline Functions (PRE_COMPILE)
  \brief  These inline functions are used to get SizeOf data.
  \{
*/ 
COM_LOCAL_INLINE FUNC(Com_SizeOfIPduGroupInfoOfRxPduInfoIndType, COM_CODE) Com_GetSizeOfIPduGroupInfoOfRxPduInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfIPduGroupInfoOfRxPduInfoIndType) Com_GetSizeOfIPduGroupInfoOfRxPduInfoIndOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxAccessInfoType, COM_CODE) Com_GetSizeOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxAccessInfoType) Com_GetSizeOfRxAccessInfoOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxAccessInfoGrpSigIndType, COM_CODE) Com_GetSizeOfRxAccessInfoGrpSigInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxAccessInfoGrpSigIndType) Com_GetSizeOfRxAccessInfoGrpSigIndOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxAccessInfoIndType, COM_CODE) Com_GetSizeOfRxAccessInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxAccessInfoIndType) Com_GetSizeOfRxAccessInfoIndOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxInvalidationInfoIndType, COM_CODE) Com_GetSizeOfRxInvalidationInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxInvalidationInfoIndType) Com_GetSizeOfRxInvalidationInfoIndOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxPduInfoType, COM_CODE) Com_GetSizeOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxPduInfoType) Com_GetSizeOfRxPduInfoOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigGrpInfoType, COM_CODE) Com_GetSizeOfRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigGrpInfoType) Com_GetSizeOfRxSigGrpInfoOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigGrpInfoIndType, COM_CODE) Com_GetSizeOfRxSigGrpInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigGrpInfoIndType) Com_GetSizeOfRxSigGrpInfoIndOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigInfoType, COM_CODE) Com_GetSizeOfRxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigInfoType) Com_GetSizeOfRxSigInfoOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxTOutInfoIndType, COM_CODE) Com_GetSizeOfRxTOutInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxTOutInfoIndType) Com_GetSizeOfRxTOutInfoIndOfPCConfig();
}
/** 
  \}
*/ 

#define COM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComPCGetDataInlineFunctions  Com Get Data Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to read CONST and VAR data.
  \{
*/ 
COM_LOCAL_INLINE FUNC(Com_IPduGroupInfoOfRxPduInfoIndType, COM_CODE) Com_GetIPduGroupInfoOfRxPduInfoInd(Com_IPduGroupInfoOfRxPduInfoIndIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_IPduGroupInfoOfRxPduInfoIndType) (Com_GetIPduGroupInfoOfRxPduInfoIndOfPCConfig()[(Index)]);
}
COM_LOCAL_INLINE FUNC(Com_ApplTypeOfRxAccessInfoType, COM_CODE) Com_GetApplTypeOfRxAccessInfo(Com_RxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ApplTypeOfRxAccessInfoType) (Com_GetRxAccessInfoOfPCConfig()[(Index)].ApplTypeOfRxAccessInfo);
}
COM_LOCAL_INLINE FUNC(Com_DeserializerInfoIdxOfRxAccessInfoType, COM_CODE) Com_GetDeserializerInfoIdxOfRxAccessInfo(Com_RxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_DeserializerInfoIdxOfRxAccessInfoType) (Com_GetRxAccessInfoOfPCConfig()[(Index)].DeserializerInfoIdxOfRxAccessInfo);
}
COM_LOCAL_INLINE FUNC(Com_FilterInfoIdxOfRxAccessInfoType, COM_CODE) Com_GetFilterInfoIdxOfRxAccessInfo(Com_RxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterInfoIdxOfRxAccessInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterInfoUsedOfRxAccessInfoType, COM_CODE) Com_IsFilterInfoUsedOfRxAccessInfo(Com_RxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterInfoUsedOfRxAccessInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_GwInfoIdxOfRxAccessInfoType, COM_CODE) Com_GetGwInfoIdxOfRxAccessInfo(Com_RxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwInfoIdxOfRxAccessInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_GwInfoUsedOfRxAccessInfoType, COM_CODE) Com_IsGwInfoUsedOfRxAccessInfo(Com_RxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwInfoUsedOfRxAccessInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_InvalidHndOfRxAccessInfoType, COM_CODE) Com_IsInvalidHndOfRxAccessInfo(Com_RxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvalidHndOfRxAccessInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxBufferInfoIdxOfRxAccessInfoType, COM_CODE) Com_GetRxBufferInfoIdxOfRxAccessInfo(Com_RxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxBufferInfoIdxOfRxAccessInfoType) (Com_GetRxAccessInfoOfPCConfig()[(Index)].RxBufferInfoIdxOfRxAccessInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxBufferInfoMinProcGwBufferIdxOfRxAccessInfoType, COM_CODE) Com_GetRxBufferInfoMinProcGwBufferIdxOfRxAccessInfo(Com_RxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxBufferInfoMinProcGwBufferIdxOfRxAccessInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_RxBufferInfoMinProcGwBufferUsedOfRxAccessInfoType, COM_CODE) Com_IsRxBufferInfoMinProcGwBufferUsedOfRxAccessInfo(Com_RxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxBufferInfoMinProcGwBufferUsedOfRxAccessInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxBufferInfoShdwBufferIdxOfRxAccessInfoType, COM_CODE) Com_GetRxBufferInfoShdwBufferIdxOfRxAccessInfo(Com_RxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxBufferInfoShdwBufferIdxOfRxAccessInfoType) (Com_GetRxAccessInfoOfPCConfig()[(Index)].RxBufferInfoShdwBufferIdxOfRxAccessInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxDynSignalLengthIdxOfRxAccessInfoType, COM_CODE) Com_GetRxDynSignalLengthIdxOfRxAccessInfo(Com_RxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxDynSignalLengthIdxOfRxAccessInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_RxDynSignalLengthUsedOfRxAccessInfoType, COM_CODE) Com_IsRxDynSignalLengthUsedOfRxAccessInfo(Com_RxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxDynSignalLengthUsedOfRxAccessInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxDynSignalTmpLengthForSignalGroupsIdxOfRxAccessInfoType, COM_CODE) Com_GetRxDynSignalTmpLengthForSignalGroupsIdxOfRxAccessInfo(Com_RxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxDynSignalTmpLengthForSignalGroupsIdxOfRxAccessInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_RxDynSignalTmpLengthForSignalGroupsUsedOfRxAccessInfoType, COM_CODE) Com_IsRxDynSignalTmpLengthForSignalGroupsUsedOfRxAccessInfo(Com_RxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxDynSignalTmpLengthForSignalGroupsUsedOfRxAccessInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxPduInfoIdxOfRxAccessInfoType, COM_CODE) Com_GetRxPduInfoIdxOfRxAccessInfo(Com_RxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxPduInfoIdxOfRxAccessInfoType) (Com_GetRxAccessInfoOfPCConfig()[(Index)].RxPduInfoIdxOfRxAccessInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoIdxOfRxAccessInfoType, COM_CODE) Com_GetRxTOutInfoIdxOfRxAccessInfo(Com_RxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxTOutInfoIdxOfRxAccessInfoType) (Com_GetRxAccessInfoOfPCConfig()[(Index)].RxTOutInfoIdxOfRxAccessInfo);
}
COM_LOCAL_INLINE FUNC(Com_SignalLengthInByteOfRxAccessInfoType, COM_CODE) Com_GetSignalLengthInByteOfRxAccessInfo(Com_RxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_SignalLengthInByteOfRxAccessInfoType) (Com_GetRxAccessInfoOfPCConfig()[(Index)].SignalLengthInByteOfRxAccessInfo);
}
COM_LOCAL_INLINE FUNC(Com_StartByteInPduPositionOfRxAccessInfoType, COM_CODE) Com_GetStartByteInPduPositionOfRxAccessInfo(Com_RxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_StartByteInPduPositionOfRxAccessInfoType) (Com_GetRxAccessInfoOfPCConfig()[(Index)].StartByteInPduPositionOfRxAccessInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoIndType, COM_CODE) Com_GetRxAccessInfoInd(Com_RxAccessInfoIndIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxAccessInfoIndType) (Com_GetRxAccessInfoIndOfPCConfig()[(Index)]);
}
COM_LOCAL_INLINE FUNC(Com_RxInvalidationInfoIndType, COM_CODE) Com_GetRxInvalidationInfoInd(Com_RxInvalidationInfoIndIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxInvalidationInfoIndType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_GwInfoEndIdxOfRxPduInfoType, COM_CODE) Com_GetGwInfoEndIdxOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwInfoEndIdxOfRxPduInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_GwInfoStartIdxOfRxPduInfoType, COM_CODE) Com_GetGwInfoStartIdxOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwInfoStartIdxOfRxPduInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_GwInfoUsedOfRxPduInfoType, COM_CODE) Com_IsGwInfoUsedOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwInfoUsedOfRxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_GwTxPduDescriptionInfoEndIdxOfRxPduInfoType, COM_CODE) Com_GetGwTxPduDescriptionInfoEndIdxOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwTxPduDescriptionInfoEndIdxOfRxPduInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_GwTxPduDescriptionInfoStartIdxOfRxPduInfoType, COM_CODE) Com_GetGwTxPduDescriptionInfoStartIdxOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwTxPduDescriptionInfoStartIdxOfRxPduInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_GwTxPduDescriptionInfoUsedOfRxPduInfoType, COM_CODE) Com_IsGwTxPduDescriptionInfoUsedOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwTxPduDescriptionInfoUsedOfRxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_HandleRxDeferredGwDescriptionIdxOfRxPduInfoType, COM_CODE) Com_GetHandleRxDeferredGwDescriptionIdxOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_HandleRxDeferredGwDescriptionIdxOfRxPduInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_HandleRxDeferredGwDescriptionUsedOfRxPduInfoType, COM_CODE) Com_IsHandleRxDeferredGwDescriptionUsedOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_HandleRxDeferredGwDescriptionUsedOfRxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_HandleRxPduDeferredIdxOfRxPduInfoType, COM_CODE) Com_GetHandleRxPduDeferredIdxOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_HandleRxPduDeferredIdxOfRxPduInfoType) (Com_GetRxPduInfoOfPCConfig()[(Index)].HandleRxPduDeferredIdxOfRxPduInfo);
}
COM_LOCAL_INLINE FUNC(Com_IPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfoType, COM_CODE) Com_GetIPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_IPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfoType) (Com_GetRxPduInfoOfPCConfig()[(Index)].IPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfo);
}
COM_LOCAL_INLINE FUNC(Com_InvalidHndOfRxPduInfoType, COM_CODE) Com_IsInvalidHndOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvalidHndOfRxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_MainFunctionRouteSignalsStructIdxOfRxPduInfoType, COM_CODE) Com_GetMainFunctionRouteSignalsStructIdxOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_MainFunctionRouteSignalsStructIdxOfRxPduInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_MainFunctionRouteSignalsStructUsedOfRxPduInfoType, COM_CODE) Com_IsMainFunctionRouteSignalsStructUsedOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_MainFunctionRouteSignalsStructUsedOfRxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_MainFunctionRxStructIdxOfRxPduInfoType, COM_CODE) Com_GetMainFunctionRxStructIdxOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_MainFunctionRxStructIdxOfRxPduInfoType) (Com_GetRxPduInfoOfPCConfig()[(Index)].MainFunctionRxStructIdxOfRxPduInfo);
}
COM_LOCAL_INLINE FUNC(Com_ReportingRxIPduCalloutIdxOfRxPduInfoType, COM_CODE) Com_GetReportingRxIPduCalloutIdxOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ReportingRxIPduCalloutIdxOfRxPduInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_ReportingRxIPduCalloutUsedOfRxPduInfoType, COM_CODE) Com_IsReportingRxIPduCalloutUsedOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ReportingRxIPduCalloutUsedOfRxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoIndEndIdxOfRxPduInfoType, COM_CODE) Com_GetRxAccessInfoIndEndIdxOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxAccessInfoIndEndIdxOfRxPduInfoType) (Com_GetRxPduInfoOfPCConfig()[(Index)].RxAccessInfoIndEndIdxOfRxPduInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoIndStartIdxOfRxPduInfoType, COM_CODE) Com_GetRxAccessInfoIndStartIdxOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxAccessInfoIndStartIdxOfRxPduInfoType) (Com_GetRxPduInfoOfPCConfig()[(Index)].RxAccessInfoIndStartIdxOfRxPduInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxDefPduBufferEndIdxOfRxPduInfoType, COM_CODE) Com_GetRxDefPduBufferEndIdxOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxDefPduBufferEndIdxOfRxPduInfoType) (Com_GetRxPduInfoOfPCConfig()[(Index)].RxDefPduBufferEndIdxOfRxPduInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxDefPduBufferStartIdxOfRxPduInfoType, COM_CODE) Com_GetRxDefPduBufferStartIdxOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxDefPduBufferStartIdxOfRxPduInfoType) (Com_GetRxPduInfoOfPCConfig()[(Index)].RxDefPduBufferStartIdxOfRxPduInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxMetaDataBufferInfoIdxOfRxPduInfoType, COM_CODE) Com_GetRxMetaDataBufferInfoIdxOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxMetaDataBufferInfoIdxOfRxPduInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_RxMetaDataBufferInfoUsedOfRxPduInfoType, COM_CODE) Com_IsRxMetaDataBufferInfoUsedOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxMetaDataBufferInfoUsedOfRxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxSigGrpInfoIndStartIdxOfRxPduInfoType, COM_CODE) Com_GetRxSigGrpInfoIndStartIdxOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigGrpInfoIndStartIdxOfRxPduInfoType) (Com_GetRxPduInfoOfPCConfig()[(Index)].RxSigGrpInfoIndStartIdxOfRxPduInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxSigInfoEndIdxOfRxPduInfoType, COM_CODE) Com_GetRxSigInfoEndIdxOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigInfoEndIdxOfRxPduInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_RxSigInfoStartIdxOfRxPduInfoType, COM_CODE) Com_GetRxSigInfoStartIdxOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigInfoStartIdxOfRxPduInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_RxSigInfoUsedOfRxPduInfoType, COM_CODE) Com_IsRxSigInfoUsedOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigInfoUsedOfRxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoIdxOfRxPduInfoType, COM_CODE) Com_GetRxTOutInfoIdxOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxTOutInfoIdxOfRxPduInfoType) (Com_GetRxPduInfoOfPCConfig()[(Index)].RxTOutInfoIdxOfRxPduInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoIndEndIdxOfRxPduInfoType, COM_CODE) Com_GetRxTOutInfoIndEndIdxOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxTOutInfoIndEndIdxOfRxPduInfoType) (Com_GetRxPduInfoOfPCConfig()[(Index)].RxTOutInfoIndEndIdxOfRxPduInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoIndStartIdxOfRxPduInfoType, COM_CODE) Com_GetRxTOutInfoIndStartIdxOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxTOutInfoIndStartIdxOfRxPduInfoType) (Com_GetRxPduInfoOfPCConfig()[(Index)].RxTOutInfoIndStartIdxOfRxPduInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxTpInfoIdxOfRxPduInfoType, COM_CODE) Com_GetRxTpInfoIdxOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxTpInfoIdxOfRxPduInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_RxTpInfoUsedOfRxPduInfoType, COM_CODE) Com_IsRxTpInfoUsedOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxTpInfoUsedOfRxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_FilterEventOfRxSigGrpInfoType, COM_CODE) Com_IsFilterEventOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterEventOfRxSigGrpInfoType) ((Com_GetRxSigGrpInfoOfPCConfig()[(Index)].FilterEventOfRxSigGrpInfo) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_GwInfoIdxOfRxSigGrpInfoType, COM_CODE) Com_GetGwInfoIdxOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwInfoIdxOfRxSigGrpInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_GwInfoUsedOfRxSigGrpInfoType, COM_CODE) Com_IsGwInfoUsedOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwInfoUsedOfRxSigGrpInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_InvalidHndOfRxSigGrpInfoType, COM_CODE) Com_IsInvalidHndOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvalidHndOfRxSigGrpInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_ReportingIndicationNotificationIdxOfRxSigGrpInfoType, COM_CODE) Com_GetReportingIndicationNotificationIdxOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ReportingIndicationNotificationIdxOfRxSigGrpInfoType) (Com_GetRxSigGrpInfoOfPCConfig()[(Index)].ReportingIndicationNotificationIdxOfRxSigGrpInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoGrpSigIndEndIdxOfRxSigGrpInfoType, COM_CODE) Com_GetRxAccessInfoGrpSigIndEndIdxOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxAccessInfoGrpSigIndEndIdxOfRxSigGrpInfoType) (Com_GetRxSigGrpInfoOfPCConfig()[(Index)].RxAccessInfoGrpSigIndEndIdxOfRxSigGrpInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoGrpSigIndStartIdxOfRxSigGrpInfoType, COM_CODE) Com_GetRxAccessInfoGrpSigIndStartIdxOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxAccessInfoGrpSigIndStartIdxOfRxSigGrpInfoType) (Com_GetRxSigGrpInfoOfPCConfig()[(Index)].RxAccessInfoGrpSigIndStartIdxOfRxSigGrpInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxBufferInfoIdxOfRxSigGrpInfoType, COM_CODE) Com_GetRxBufferInfoIdxOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxBufferInfoIdxOfRxSigGrpInfoType) (Com_GetRxSigGrpInfoOfPCConfig()[(Index)].RxBufferInfoIdxOfRxSigGrpInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxInvalidationInfoIndEndIdxOfRxSigGrpInfoType, COM_CODE) Com_GetRxInvalidationInfoIndEndIdxOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxInvalidationInfoIndEndIdxOfRxSigGrpInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_RxInvalidationInfoIndStartIdxOfRxSigGrpInfoType, COM_CODE) Com_GetRxInvalidationInfoIndStartIdxOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxInvalidationInfoIndStartIdxOfRxSigGrpInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_RxInvalidationInfoIndUsedOfRxSigGrpInfoType, COM_CODE) Com_IsRxInvalidationInfoIndUsedOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxInvalidationInfoIndUsedOfRxSigGrpInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxPduInfoIdxOfRxSigGrpInfoType, COM_CODE) Com_GetRxPduInfoIdxOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxPduInfoIdxOfRxSigGrpInfoType) (Com_GetRxSigGrpInfoOfPCConfig()[(Index)].RxPduInfoIdxOfRxSigGrpInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoIdxOfRxSigGrpInfoType, COM_CODE) Com_GetRxTOutInfoIdxOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxTOutInfoIdxOfRxSigGrpInfoType) (Com_GetRxSigGrpInfoOfPCConfig()[(Index)].RxTOutInfoIdxOfRxSigGrpInfo);
}
COM_LOCAL_INLINE FUNC(Com_ShdBufferRequiredOfRxSigGrpInfoType, COM_CODE) Com_IsShdBufferRequiredOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ShdBufferRequiredOfRxSigGrpInfoType) ((Com_GetRxSigGrpInfoOfPCConfig()[(Index)].ShdBufferRequiredOfRxSigGrpInfo) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_StartBytePositionOfRxSigGrpInfoType, COM_CODE) Com_GetStartBytePositionOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_StartBytePositionOfRxSigGrpInfoType) (Com_GetRxSigGrpInfoOfPCConfig()[(Index)].StartBytePositionOfRxSigGrpInfo);
}
COM_LOCAL_INLINE FUNC(Com_UpdateBitInfoIdxOfRxSigGrpInfoType, COM_CODE) Com_GetUpdateBitInfoIdxOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_UpdateBitInfoIdxOfRxSigGrpInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_UpdateBitInfoUsedOfRxSigGrpInfoType, COM_CODE) Com_IsUpdateBitInfoUsedOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_UpdateBitInfoUsedOfRxSigGrpInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_ValidDlcOfRxSigGrpInfoType, COM_CODE) Com_GetValidDlcOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ValidDlcOfRxSigGrpInfoType) (Com_GetRxSigGrpInfoOfPCConfig()[(Index)].ValidDlcOfRxSigGrpInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxSigGrpInfoIndType, COM_CODE) Com_GetRxSigGrpInfoInd(Com_RxSigGrpInfoIndIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigGrpInfoIndType) (Com_GetRxSigGrpInfoIndOfPCConfig()[(Index)]);
}
COM_LOCAL_INLINE FUNC(Com_GwInfoIdxOfRxSigInfoType, COM_CODE) Com_GetGwInfoIdxOfRxSigInfo(Com_RxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwInfoIdxOfRxSigInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_GwInfoUsedOfRxSigInfoType, COM_CODE) Com_IsGwInfoUsedOfRxSigInfo(Com_RxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwInfoUsedOfRxSigInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_ReportingIndicationNotificationIdxOfRxSigInfoType, COM_CODE) Com_GetReportingIndicationNotificationIdxOfRxSigInfo(Com_RxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ReportingIndicationNotificationIdxOfRxSigInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_ReportingIndicationNotificationUsedOfRxSigInfoType, COM_CODE) Com_IsReportingIndicationNotificationUsedOfRxSigInfo(Com_RxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ReportingIndicationNotificationUsedOfRxSigInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoIdxOfRxSigInfoType, COM_CODE) Com_GetRxAccessInfoIdxOfRxSigInfo(Com_RxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxAccessInfoIdxOfRxSigInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_RxInvalidationInfoIdxOfRxSigInfoType, COM_CODE) Com_GetRxInvalidationInfoIdxOfRxSigInfo(Com_RxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxInvalidationInfoIdxOfRxSigInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_RxInvalidationInfoUsedOfRxSigInfoType, COM_CODE) Com_IsRxInvalidationInfoUsedOfRxSigInfo(Com_RxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxInvalidationInfoUsedOfRxSigInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoIdxOfRxSigInfoType, COM_CODE) Com_GetRxTOutInfoIdxOfRxSigInfo(Com_RxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxTOutInfoIdxOfRxSigInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoUsedOfRxSigInfoType, COM_CODE) Com_IsRxTOutInfoUsedOfRxSigInfo(Com_RxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxTOutInfoUsedOfRxSigInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_UpdateBitInfoIdxOfRxSigInfoType, COM_CODE) Com_GetUpdateBitInfoIdxOfRxSigInfo(Com_RxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_UpdateBitInfoIdxOfRxSigInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_UpdateBitInfoUsedOfRxSigInfoType, COM_CODE) Com_IsUpdateBitInfoUsedOfRxSigInfo(Com_RxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_UpdateBitInfoUsedOfRxSigInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_ValidDlcOfRxSigInfoType, COM_CODE) Com_GetValidDlcOfRxSigInfo(Com_RxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ValidDlcOfRxSigInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoIndType, COM_CODE) Com_GetRxTOutInfoInd(Com_RxTOutInfoIndIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxTOutInfoIndType) (Com_GetRxTOutInfoIndOfPCConfig()[(Index)]);
}
/** 
  \}
*/ 

#define COM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComPCGetDeduplicatedInlineFunctions  Com Get Deduplicated Inline Functions (PRE_COMPILE)
  \brief  These inline functions  can be used to read deduplicated data elements.
  \{
*/ 
COM_LOCAL_INLINE FUNC(Com_DeserializerInfoUsedOfRxAccessInfoType, COM_CODE) Com_IsDeserializerInfoUsedOfRxAccessInfo(Com_RxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_DeserializerInfoUsedOfRxAccessInfoType) (((boolean)(Com_GetDeserializerInfoIdxOfRxAccessInfo(Index) != COM_NO_DESERIALIZERINFOIDXOFRXACCESSINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxBufferInfoShdwBufferUsedOfRxAccessInfoType, COM_CODE) Com_IsRxBufferInfoShdwBufferUsedOfRxAccessInfo(Com_RxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxBufferInfoShdwBufferUsedOfRxAccessInfoType) (((boolean)(Com_GetRxBufferInfoShdwBufferIdxOfRxAccessInfo(Index) != COM_NO_RXBUFFERINFOSHDWBUFFERIDXOFRXACCESSINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxBufferInfoUsedOfRxAccessInfoType, COM_CODE) Com_IsRxBufferInfoUsedOfRxAccessInfo(Com_RxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxBufferInfoUsedOfRxAccessInfoType) (((boolean)(Com_GetRxBufferInfoIdxOfRxAccessInfo(Index) != COM_NO_RXBUFFERINFOIDXOFRXACCESSINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoUsedOfRxAccessInfoType, COM_CODE) Com_IsRxTOutInfoUsedOfRxAccessInfo(Com_RxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxTOutInfoUsedOfRxAccessInfoType) (((boolean)(Com_GetRxTOutInfoIdxOfRxAccessInfo(Index) != COM_NO_RXTOUTINFOIDXOFRXACCESSINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoGrpSigIndType, COM_CODE) Com_GetRxAccessInfoGrpSigInd(Com_RxAccessInfoGrpSigIndIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxAccessInfoGrpSigIndType) ((Com_RxAccessInfoGrpSigIndType)((Index)));
}
COM_LOCAL_INLINE FUNC(Com_HandleRxPduDeferredUsedOfRxPduInfoType, COM_CODE) Com_IsHandleRxPduDeferredUsedOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_HandleRxPduDeferredUsedOfRxPduInfoType) (((boolean)(Com_GetHandleRxPduDeferredIdxOfRxPduInfo(Index) != COM_NO_HANDLERXPDUDEFERREDIDXOFRXPDUINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_IPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfoType, COM_CODE) Com_GetIPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_IPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfoType) ((Com_IPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfoType)((((Com_IPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfoType)(Index)) + 1u)));
}
COM_LOCAL_INLINE FUNC(Com_IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfoType, COM_CODE) Com_IsIPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfoType) (((boolean)(Com_GetIPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfo(Index) != COM_NO_IPDUGROUPINFOOFRXPDUINFOINDSTARTIDXOFRXPDUINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_MainFunctionRxStructUsedOfRxPduInfoType, COM_CODE) Com_IsMainFunctionRxStructUsedOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_MainFunctionRxStructUsedOfRxPduInfoType) (((boolean)(Com_GetMainFunctionRxStructIdxOfRxPduInfo(Index) != COM_NO_MAINFUNCTIONRXSTRUCTIDXOFRXPDUINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_MetaDataLengthOfRxPduInfoType, COM_CODE) Com_GetMetaDataLengthOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_MetaDataLengthOfRxPduInfoType) Com_GetMainFunctionRxStructIdxOfRxPduInfo(Index);
}
COM_LOCAL_INLINE FUNC(Com_PartitionsRxStructIdxOfRxPduInfoType, COM_CODE) Com_GetPartitionsRxStructIdxOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_PartitionsRxStructIdxOfRxPduInfoType) Com_GetMainFunctionRxStructIdxOfRxPduInfo(Index);
}
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoIndUsedOfRxPduInfoType, COM_CODE) Com_IsRxAccessInfoIndUsedOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxAccessInfoIndUsedOfRxPduInfoType) (((boolean)(Com_GetRxAccessInfoIndStartIdxOfRxPduInfo(Index) != COM_NO_RXACCESSINFOINDSTARTIDXOFRXPDUINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxDefPduBufferLengthOfRxPduInfoType, COM_CODE) Com_GetRxDefPduBufferLengthOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxDefPduBufferLengthOfRxPduInfoType) ((Com_RxDefPduBufferLengthOfRxPduInfoType)((Com_GetRxDefPduBufferEndIdxOfRxPduInfo(Index) - Com_GetRxDefPduBufferStartIdxOfRxPduInfo(Index))));
}
COM_LOCAL_INLINE FUNC(Com_RxDefPduBufferUsedOfRxPduInfoType, COM_CODE) Com_IsRxDefPduBufferUsedOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxDefPduBufferUsedOfRxPduInfoType) (((boolean)(Com_GetRxDefPduBufferLengthOfRxPduInfo(Index) != 0u)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxSigGrpInfoIndEndIdxOfRxPduInfoType, COM_CODE) Com_GetRxSigGrpInfoIndEndIdxOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigGrpInfoIndEndIdxOfRxPduInfoType) ((Com_RxSigGrpInfoIndEndIdxOfRxPduInfoType)((((Com_RxSigGrpInfoIndEndIdxOfRxPduInfoType)(Index)) + 1u)));
}
COM_LOCAL_INLINE FUNC(Com_RxSigGrpInfoIndUsedOfRxPduInfoType, COM_CODE) Com_IsRxSigGrpInfoIndUsedOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigGrpInfoIndUsedOfRxPduInfoType) (((boolean)(Com_GetRxSigGrpInfoIndStartIdxOfRxPduInfo(Index) != COM_NO_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoIndUsedOfRxPduInfoType, COM_CODE) Com_IsRxTOutInfoIndUsedOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxTOutInfoIndUsedOfRxPduInfoType) (((boolean)(Com_GetRxTOutInfoIndStartIdxOfRxPduInfo(Index) != COM_NO_RXTOUTINFOINDSTARTIDXOFRXPDUINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoUsedOfRxPduInfoType, COM_CODE) Com_IsRxTOutInfoUsedOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxTOutInfoUsedOfRxPduInfoType) (((boolean)(Com_GetRxTOutInfoIdxOfRxPduInfo(Index) != COM_NO_RXTOUTINFOIDXOFRXPDUINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_SignalProcessingOfRxPduInfoType, COM_CODE) Com_GetSignalProcessingOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_SignalProcessingOfRxPduInfoType) Com_GetMainFunctionRxStructIdxOfRxPduInfo(Index);
}
COM_LOCAL_INLINE FUNC(Com_TypeOfRxPduInfoType, COM_CODE) Com_GetTypeOfRxPduInfo(Com_RxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TypeOfRxPduInfoType) Com_GetMainFunctionRxStructIdxOfRxPduInfo(Index);
}
COM_LOCAL_INLINE FUNC(Com_ArrayAccessUsedOfRxSigGrpInfoType, COM_CODE) Com_IsArrayAccessUsedOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ArrayAccessUsedOfRxSigGrpInfoType) (((!(Com_IsShdBufferRequiredOfRxSigGrpInfo(Index)))) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_ReportingIndicationNotificationUsedOfRxSigGrpInfoType, COM_CODE) Com_IsReportingIndicationNotificationUsedOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ReportingIndicationNotificationUsedOfRxSigGrpInfoType) (((boolean)(Com_GetReportingIndicationNotificationIdxOfRxSigGrpInfo(Index) != COM_NO_REPORTINGINDICATIONNOTIFICATIONIDXOFRXSIGGRPINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoGrpSigIndUsedOfRxSigGrpInfoType, COM_CODE) Com_IsRxAccessInfoGrpSigIndUsedOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxAccessInfoGrpSigIndUsedOfRxSigGrpInfoType) (((boolean)(Com_GetRxAccessInfoGrpSigIndStartIdxOfRxSigGrpInfo(Index) != COM_NO_RXACCESSINFOGRPSIGINDSTARTIDXOFRXSIGGRPINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxBufferInfoUsedOfRxSigGrpInfoType, COM_CODE) Com_IsRxBufferInfoUsedOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxBufferInfoUsedOfRxSigGrpInfoType) (((boolean)(Com_GetRxBufferInfoIdxOfRxSigGrpInfo(Index) != COM_NO_RXBUFFERINFOIDXOFRXSIGGRPINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoUsedOfRxSigGrpInfoType, COM_CODE) Com_IsRxTOutInfoUsedOfRxSigGrpInfo(Com_RxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxTOutInfoUsedOfRxSigGrpInfoType) (((boolean)(Com_GetRxTOutInfoIdxOfRxSigGrpInfo(Index) != COM_NO_RXTOUTINFOIDXOFRXSIGGRPINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
/** 
  \}
*/ 

#define COM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComPCHasInlineFunctions  Com Has Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasIPduGroupInfoOfRxPduInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasApplTypeOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasDeserializerInfoIdxOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasDeserializerInfoUsedOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfoIdxOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfoUsedOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwInfoIdxOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwInfoUsedOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvalidHndOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxBufferInfoIdxOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxBufferInfoMinProcGwBufferIdxOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxBufferInfoMinProcGwBufferUsedOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxBufferInfoShdwBufferIdxOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxBufferInfoShdwBufferUsedOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxBufferInfoUsedOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDynSignalLengthIdxOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDynSignalLengthUsedOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDynSignalTmpLengthForSignalGroupsIdxOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDynSignalTmpLengthForSignalGroupsUsedOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxPduInfoIdxOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoIdxOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoUsedOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSignalLengthInByteOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasStartByteInPduPositionOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoGrpSigInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxInvalidationInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwInfoEndIdxOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwInfoStartIdxOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwInfoUsedOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwTxPduDescriptionInfoEndIdxOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwTxPduDescriptionInfoStartIdxOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwTxPduDescriptionInfoUsedOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasHandleRxDeferredGwDescriptionIdxOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasHandleRxDeferredGwDescriptionUsedOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasHandleRxPduDeferredIdxOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasHandleRxPduDeferredUsedOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasIPduGroupInfoOfRxPduInfoIndEndIdxOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasIPduGroupInfoOfRxPduInfoIndStartIdxOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasIPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvalidHndOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMainFunctionRouteSignalsStructIdxOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMainFunctionRouteSignalsStructUsedOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMainFunctionRxStructIdxOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMainFunctionRxStructUsedOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataLengthOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasPartitionsRxStructIdxOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingRxIPduCalloutIdxOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingRxIPduCalloutUsedOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoIndEndIdxOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoIndStartIdxOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoIndUsedOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDefPduBufferEndIdxOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDefPduBufferLengthOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDefPduBufferStartIdxOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDefPduBufferUsedOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxMetaDataBufferInfoIdxOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxMetaDataBufferInfoUsedOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigGrpInfoIndEndIdxOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigGrpInfoIndStartIdxOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigGrpInfoIndUsedOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigInfoEndIdxOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigInfoStartIdxOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigInfoUsedOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoIdxOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoIndEndIdxOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoIndStartIdxOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoIndUsedOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoUsedOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTpInfoIdxOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTpInfoUsedOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSignalProcessingOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTypeOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasArrayAccessUsedOfRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterEventOfRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwInfoIdxOfRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwInfoUsedOfRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvalidHndOfRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingIndicationNotificationIdxOfRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingIndicationNotificationUsedOfRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoGrpSigIndEndIdxOfRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoGrpSigIndStartIdxOfRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoGrpSigIndUsedOfRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxBufferInfoIdxOfRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxBufferInfoUsedOfRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxInvalidationInfoIndEndIdxOfRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxInvalidationInfoIndStartIdxOfRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxInvalidationInfoIndUsedOfRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxPduInfoIdxOfRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoIdxOfRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoUsedOfRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasShdBufferRequiredOfRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasStartBytePositionOfRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasUpdateBitInfoIdxOfRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasUpdateBitInfoUsedOfRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasValidDlcOfRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigGrpInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwInfoIdxOfRxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwInfoUsedOfRxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingIndicationNotificationIdxOfRxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingIndicationNotificationUsedOfRxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoIdxOfRxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxInvalidationInfoIdxOfRxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxInvalidationInfoUsedOfRxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoIdxOfRxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoUsedOfRxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasUpdateBitInfoIdxOfRxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasUpdateBitInfoUsedOfRxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasValidDlcOfRxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfIPduGroupInfoOfRxPduInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxAccessInfoGrpSigInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxAccessInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxInvalidationInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigGrpInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxTOutInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
/** 
  \}
*/ 

#define COM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define COM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComPCEsistsEnumInlineFunctions  Com Esists Enum Inline Functions (PRE_COMPILE)
  \brief  These inilne functions can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsUINT8ApplTypeOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsSINT8ApplTypeOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsUINT16ApplTypeOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsSINT16ApplTypeOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsUINT32ApplTypeOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsSINT32ApplTypeOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsUINT64ApplTypeOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsSINT64ApplTypeOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsUINT8_NApplTypeOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsUINT8_DYNApplTypeOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsZEROBITApplTypeOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFLOAT32ApplTypeOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFLOAT64ApplTypeOfRxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsDEFERREDSignalProcessingOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsIMMEDIATESignalProcessingOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNORMALTypeOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTPTypeOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
/** 
  \}
*/ 

#define COM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */





/* VCA Enable : VCA_COM_FUNCTION_NOT_USED_AND_NO_ANALYSIS_ENTRY */

#endif  /* COM_CFG_RECEPTIONPROCESSINGDATA_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cfg_ReceptionProcessingData.h
**********************************************************************************************************************/

