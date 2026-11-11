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
 *              File: Com_Cfg_TransmissionProcessingData.h
 *   Generation Time: 2026-08-28 14:56:00
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

#if !defined (COM_CFG_TRANSMISSIONPROCESSINGDATA_H)
# define COM_CFG_TRANSMISSIONPROCESSINGDATA_H

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
COM_LOCAL_INLINE FUNC(Com_SizeOfCallDeferredConfirmationNotificationType, COM_CODE) Com_GetSizeOfCallDeferredConfirmationNotification(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfDynamicInitialLengthType, COM_CODE) Com_GetSizeOfDynamicInitialLength(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfIPduGroupInfoOfTxPduInfoIndType, COM_CODE) Com_GetSizeOfIPduGroupInfoOfTxPduInfoInd(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfReportingConfirmationNotificationIndType, COM_CODE) Com_GetSizeOfReportingConfirmationNotificationInd(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfReportingErrorNotificationIndType, COM_CODE) Com_GetSizeOfReportingErrorNotificationInd(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfSigGrpEventFlagType, COM_CODE) Com_GetSizeOfSigGrpEventFlag(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxAccessInfoType, COM_CODE) Com_GetSizeOfTxAccessInfo(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxGrpSigInfoType, COM_CODE) Com_GetSizeOfTxGrpSigInfo(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxInvalidationInfoIndType, COM_CODE) Com_GetSizeOfTxInvalidationInfoInd(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxPduInfoType, COM_CODE) Com_GetSizeOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxProcessingPdusType, COM_CODE) Com_GetSizeOfTxProcessingPdus(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxSduLengthType, COM_CODE) Com_GetSizeOfTxSduLength(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxSigGrpInfoType, COM_CODE) Com_GetSizeOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxSigGrpInfoIndType, COM_CODE) Com_GetSizeOfTxSigGrpInfoInd(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxSigGrpOnChangeMaskType, COM_CODE) Com_GetSizeOfTxSigGrpOnChangeMask(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxSigInfoType, COM_CODE) Com_GetSizeOfTxSigInfo(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxTmpPduLengthType, COM_CODE) Com_GetSizeOfTxTmpPduLength(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfWaitingForConfirmationType, COM_CODE) Com_GetSizeOfWaitingForConfirmation(void);
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
COM_LOCAL_INLINE FUNC(Com_CallDeferredConfirmationNotificationType, COM_CODE) Com_IsCallDeferredConfirmationNotification(Com_CallDeferredConfirmationNotificationIterType Index);
COM_LOCAL_INLINE FUNC(Com_DynamicInitialLengthType, COM_CODE) Com_GetDynamicInitialLength(Com_DynamicInitialLengthIterType Index);
COM_LOCAL_INLINE FUNC(Com_IPduGroupInfoOfTxPduInfoIndType, COM_CODE) Com_GetIPduGroupInfoOfTxPduInfoInd(Com_IPduGroupInfoOfTxPduInfoIndIterType Index);
COM_LOCAL_INLINE FUNC(Com_ReportingConfirmationNotificationIndType, COM_CODE) Com_GetReportingConfirmationNotificationInd(Com_ReportingConfirmationNotificationIndIterType Index);
COM_LOCAL_INLINE FUNC(Com_ReportingErrorNotificationIndType, COM_CODE) Com_GetReportingErrorNotificationInd(Com_ReportingErrorNotificationIndIterType Index);
COM_LOCAL_INLINE FUNC(Com_SigGrpEventFlagType, COM_CODE) Com_GetSigGrpEventFlag(Com_SigGrpEventFlagIterType Index);
COM_LOCAL_INLINE FUNC(Com_DynamicInitialLengthIdxOfTxAccessInfoType, COM_CODE) Com_GetDynamicInitialLengthIdxOfTxAccessInfo(Com_TxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_DynamicInitialLengthUsedOfTxAccessInfoType, COM_CODE) Com_IsDynamicInitialLengthUsedOfTxAccessInfo(Com_TxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_InvalidHndOfTxAccessInfoType, COM_CODE) Com_IsInvalidHndOfTxAccessInfo(Com_TxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxGrpSigInfoIdxOfTxAccessInfoType, COM_CODE) Com_GetTxGrpSigInfoIdxOfTxAccessInfo(Com_TxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxInvalidationInfoIdxOfTxAccessInfoType, COM_CODE) Com_GetTxInvalidationInfoIdxOfTxAccessInfo(Com_TxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxInvalidationInfoUsedOfTxAccessInfoType, COM_CODE) Com_IsTxInvalidationInfoUsedOfTxAccessInfo(Com_TxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxPduInfoIdxOfTxAccessInfoType, COM_CODE) Com_GetTxPduInfoIdxOfTxAccessInfo(Com_TxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxSigInfoIdxOfTxAccessInfoType, COM_CODE) Com_GetTxSigInfoIdxOfTxAccessInfo(Com_TxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxSigInfoUsedOfTxAccessInfoType, COM_CODE) Com_IsTxSigInfoUsedOfTxAccessInfo(Com_TxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ByteLengthOfTxGrpSigInfoType, COM_CODE) Com_GetByteLengthOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_SerializerInfoIdxOfTxGrpSigInfoType, COM_CODE) Com_GetSerializerInfoIdxOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_SerializerInfoUsedOfTxGrpSigInfoType, COM_CODE) Com_IsSerializerInfoUsedOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_StartByteInPduPositionOfTxGrpSigInfoType, COM_CODE) Com_GetStartByteInPduPositionOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TransferPropertyFilterInfoIdxOfTxGrpSigInfoType, COM_CODE) Com_GetTransferPropertyFilterInfoIdxOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TransferPropertyFilterInfoUsedOfTxGrpSigInfoType, COM_CODE) Com_IsTransferPropertyFilterInfoUsedOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TransmissionModeFilterInfoIdxOfTxGrpSigInfoType, COM_CODE) Com_GetTransmissionModeFilterInfoIdxOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TransmissionModeFilterInfoUsedOfTxGrpSigInfoType, COM_CODE) Com_IsTransmissionModeFilterInfoUsedOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TriggeredOfTxGrpSigInfoType, COM_CODE) Com_IsTriggeredOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxPduInfoIdxOfTxGrpSigInfoType, COM_CODE) Com_GetTxPduInfoIdxOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxSigGrpInfoIdxOfTxGrpSigInfoType, COM_CODE) Com_GetTxSigGrpInfoIdxOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxTmpPduLengthIdxOfTxGrpSigInfoType, COM_CODE) Com_GetTxTmpPduLengthIdxOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxTmpPduLengthUsedOfTxGrpSigInfoType, COM_CODE) Com_IsTxTmpPduLengthUsedOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_WithoutRepOfTxGrpSigInfoType, COM_CODE) Com_IsWithoutRepOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxInvalidationInfoIndType, COM_CODE) Com_GetTxInvalidationInfoInd(Com_TxInvalidationInfoIndIterType Index);
COM_LOCAL_INLINE FUNC(Com_ComTimerInfoMDTTimerIdxOfTxPduInfoType, COM_CODE) Com_GetComTimerInfoMDTTimerIdxOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ComTimerInfoMDTTimerUsedOfTxPduInfoType, COM_CODE) Com_IsComTimerInfoMDTTimerUsedOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ExternalIdOfTxPduInfoType, COM_CODE) Com_GetExternalIdOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwTimeoutInfoIdxOfTxPduInfoType, COM_CODE) Com_GetGwTimeoutInfoIdxOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwTimeoutInfoUsedOfTxPduInfoType, COM_CODE) Com_IsGwTimeoutInfoUsedOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_IPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfoType, COM_CODE) Com_GetIPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_InitModeOfTxPduInfoType, COM_CODE) Com_IsInitModeOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_InvalidHndOfTxPduInfoType, COM_CODE) Com_IsInvalidHndOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_MainFunctionTxStructIdxOfTxPduInfoType, COM_CODE) Com_GetMainFunctionTxStructIdxOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_PartitionsTxStructIdxOfTxPduInfoType, COM_CODE) Com_GetPartitionsTxStructIdxOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RepetitionInfoIdxOfTxPduInfoType, COM_CODE) Com_GetRepetitionInfoIdxOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RepetitionInfoUsedOfTxPduInfoType, COM_CODE) Com_IsRepetitionInfoUsedOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ReportingConfirmationNotificationIndEndIdxOfTxPduInfoType, COM_CODE) Com_GetReportingConfirmationNotificationIndEndIdxOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ReportingConfirmationNotificationIndStartIdxOfTxPduInfoType, COM_CODE) Com_GetReportingConfirmationNotificationIndStartIdxOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ReportingConfirmationNotificationIndUsedOfTxPduInfoType, COM_CODE) Com_IsReportingConfirmationNotificationIndUsedOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ReportingErrorNotificationIndEndIdxOfTxPduInfoType, COM_CODE) Com_GetReportingErrorNotificationIndEndIdxOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ReportingErrorNotificationIndStartIdxOfTxPduInfoType, COM_CODE) Com_GetReportingErrorNotificationIndStartIdxOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ReportingErrorNotificationIndUsedOfTxPduInfoType, COM_CODE) Com_IsReportingErrorNotificationIndUsedOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ReportingIPduTriggerTransmitCalloutIdxOfTxPduInfoType, COM_CODE) Com_GetReportingIPduTriggerTransmitCalloutIdxOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ReportingIPduTriggerTransmitCalloutUsedOfTxPduInfoType, COM_CODE) Com_IsReportingIPduTriggerTransmitCalloutUsedOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ReportingTxIPduCalloutIdxOfTxPduInfoType, COM_CODE) Com_GetReportingTxIPduCalloutIdxOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ReportingTxIPduCalloutUsedOfTxPduInfoType, COM_CODE) Com_IsReportingTxIPduCalloutUsedOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxAccessInfoDynSigIdxOfTxPduInfoType, COM_CODE) Com_GetTxAccessInfoDynSigIdxOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxAccessInfoDynSigUsedOfTxPduInfoType, COM_CODE) Com_IsTxAccessInfoDynSigUsedOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoIdxOfTxPduInfoType, COM_CODE) Com_GetTxBufferInfoIdxOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxMetaDataBufferInfoIdxOfTxPduInfoType, COM_CODE) Com_GetTxMetaDataBufferInfoIdxOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxMetaDataBufferInfoUsedOfTxPduInfoType, COM_CODE) Com_IsTxMetaDataBufferInfoUsedOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxModeFalseIdxOfTxPduInfoType, COM_CODE) Com_GetTxModeFalseIdxOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxModeTrueIdxOfTxPduInfoType, COM_CODE) Com_GetTxModeTrueIdxOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxPduFilterInfoIdxOfTxPduInfoType, COM_CODE) Com_GetTxPduFilterInfoIdxOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxSigGrpInfoIndStartIdxOfTxPduInfoType, COM_CODE) Com_GetTxSigGrpInfoIndStartIdxOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxTOutInfoIdxOfTxPduInfoType, COM_CODE) Com_GetTxTOutInfoIdxOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxTOutInfoUsedOfTxPduInfoType, COM_CODE) Com_IsTxTOutInfoUsedOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxTpInfoIdxOfTxPduInfoType, COM_CODE) Com_GetTxTpInfoIdxOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxTpInfoUsedOfTxPduInfoType, COM_CODE) Com_IsTxTpInfoUsedOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxPduInfoIdxOfTxProcessingPdusType, COM_CODE) Com_GetTxPduInfoIdxOfTxProcessingPdus(Com_TxProcessingPdusIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxSduLengthType, COM_CODE) Com_GetTxSduLength(Com_TxSduLengthIterType Index);
COM_LOCAL_INLINE FUNC(Com_ArrayAccessUsedOfTxSigGrpInfoType, COM_CODE) Com_IsArrayAccessUsedOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_InvalidHndOfTxSigGrpInfoType, COM_CODE) Com_IsInvalidHndOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_SigGroupOnChangeStartPositionOfTxSigGrpInfoType, COM_CODE) Com_GetSigGroupOnChangeStartPositionOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TransferPropertyOfTxSigGrpInfoType, COM_CODE) Com_GetTransferPropertyOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TransmissionModeFilterInfoEndIdxOfTxSigGrpInfoType, COM_CODE) Com_GetTransmissionModeFilterInfoEndIdxOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TransmissionModeFilterInfoStartIdxOfTxSigGrpInfoType, COM_CODE) Com_GetTransmissionModeFilterInfoStartIdxOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TransmissionModeFilterInfoUsedOfTxSigGrpInfoType, COM_CODE) Com_IsTransmissionModeFilterInfoUsedOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoIdxOfTxSigGrpInfoType, COM_CODE) Com_GetTxBufferInfoIdxOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoSigGrpInTxIPDUIdxOfTxSigGrpInfoType, COM_CODE) Com_GetTxBufferInfoSigGrpInTxIPDUIdxOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoUbIdxAndMaskIdxOfTxSigGrpInfoType, COM_CODE) Com_GetTxBufferInfoUbIdxAndMaskIdxOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoUbIdxAndMaskUsedOfTxSigGrpInfoType, COM_CODE) Com_IsTxBufferInfoUbIdxAndMaskUsedOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoUsedOfTxSigGrpInfoType, COM_CODE) Com_IsTxBufferInfoUsedOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxInvalidationInfoIndEndIdxOfTxSigGrpInfoType, COM_CODE) Com_GetTxInvalidationInfoIndEndIdxOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxInvalidationInfoIndStartIdxOfTxSigGrpInfoType, COM_CODE) Com_GetTxInvalidationInfoIndStartIdxOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxInvalidationInfoIndUsedOfTxSigGrpInfoType, COM_CODE) Com_IsTxInvalidationInfoIndUsedOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxPduInfoIdxOfTxSigGrpInfoType, COM_CODE) Com_GetTxPduInfoIdxOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxSigGrpOnChangeMaskOnChangeEndIdxOfTxSigGrpInfoType, COM_CODE) Com_GetTxSigGrpOnChangeMaskOnChangeEndIdxOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxSigGrpOnChangeMaskOnChangeStartIdxOfTxSigGrpInfoType, COM_CODE) Com_GetTxSigGrpOnChangeMaskOnChangeStartIdxOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxSigGrpOnChangeMaskOnChangeUsedOfTxSigGrpInfoType, COM_CODE) Com_IsTxSigGrpOnChangeMaskOnChangeUsedOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxSigGrpOnChangeMaskOnChangeWithoutRepEndIdxOfTxSigGrpInfoType, COM_CODE) Com_GetTxSigGrpOnChangeMaskOnChangeWithoutRepEndIdxOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxSigGrpOnChangeMaskOnChangeWithoutRepStartIdxOfTxSigGrpInfoType, COM_CODE) Com_GetTxSigGrpOnChangeMaskOnChangeWithoutRepStartIdxOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxSigGrpOnChangeMaskOnChangeWithoutRepUsedOfTxSigGrpInfoType, COM_CODE) Com_IsTxSigGrpOnChangeMaskOnChangeWithoutRepUsedOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxSigGrpInfoIndType, COM_CODE) Com_GetTxSigGrpInfoInd(Com_TxSigGrpInfoIndIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxSigGrpOnChangeMaskType, COM_CODE) Com_GetTxSigGrpOnChangeMask(Com_TxSigGrpOnChangeMaskIterType Index);
COM_LOCAL_INLINE FUNC(Com_ByteLengthOfTxSigInfoType, COM_CODE) Com_GetByteLengthOfTxSigInfo(Com_TxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_SerializerInfoIdxOfTxSigInfoType, COM_CODE) Com_GetSerializerInfoIdxOfTxSigInfo(Com_TxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_SerializerInfoUsedOfTxSigInfoType, COM_CODE) Com_IsSerializerInfoUsedOfTxSigInfo(Com_TxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_StartByteInPduPositionOfTxSigInfoType, COM_CODE) Com_GetStartByteInPduPositionOfTxSigInfo(Com_TxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TransferPropertyFilterInfoIdxOfTxSigInfoType, COM_CODE) Com_GetTransferPropertyFilterInfoIdxOfTxSigInfo(Com_TxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TransferPropertyFilterInfoUsedOfTxSigInfoType, COM_CODE) Com_IsTransferPropertyFilterInfoUsedOfTxSigInfo(Com_TxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TransmissionModeFilterInfoIdxOfTxSigInfoType, COM_CODE) Com_GetTransmissionModeFilterInfoIdxOfTxSigInfo(Com_TxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TransmissionModeFilterInfoUsedOfTxSigInfoType, COM_CODE) Com_IsTransmissionModeFilterInfoUsedOfTxSigInfo(Com_TxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TriggeredOfTxSigInfoType, COM_CODE) Com_IsTriggeredOfTxSigInfo(Com_TxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxAccessInfoIdxOfTxSigInfoType, COM_CODE) Com_GetTxAccessInfoIdxOfTxSigInfo(Com_TxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoUbIdxAndMaskIdxOfTxSigInfoType, COM_CODE) Com_GetTxBufferInfoUbIdxAndMaskIdxOfTxSigInfo(Com_TxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoUbIdxAndMaskUsedOfTxSigInfoType, COM_CODE) Com_IsTxBufferInfoUbIdxAndMaskUsedOfTxSigInfo(Com_TxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxPduInfoIdxOfTxSigInfoType, COM_CODE) Com_GetTxPduInfoIdxOfTxSigInfo(Com_TxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_WithoutRepOfTxSigInfoType, COM_CODE) Com_IsWithoutRepOfTxSigInfo(Com_TxSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxTmpPduLengthType, COM_CODE) Com_GetTxTmpPduLength(Com_TxTmpPduLengthIterType Index);
COM_LOCAL_INLINE FUNC(Com_WaitingForConfirmationType, COM_CODE) Com_IsWaitingForConfirmation(Com_WaitingForConfirmationIterType Index);
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
COM_LOCAL_INLINE FUNC(Com_TxGrpSigInfoUsedOfTxAccessInfoType, COM_CODE) Com_IsTxGrpSigInfoUsedOfTxAccessInfo(Com_TxAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxAccessInfoIdxOfTxGrpSigInfoType, COM_CODE) Com_GetTxAccessInfoIdxOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_CancellationSupportOfTxPduInfoType, COM_CODE) Com_IsCancellationSupportOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ClrUbOfTxPduInfoType, COM_CODE) Com_GetClrUbOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_IPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfoType, COM_CODE) Com_GetIPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_IPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfoType, COM_CODE) Com_IsIPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_MetaDataLengthOfTxPduInfoType, COM_CODE) Com_GetMetaDataLengthOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_SignalProcessingOfTxPduInfoType, COM_CODE) Com_GetSignalProcessingOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoUsedOfTxPduInfoType, COM_CODE) Com_IsTxBufferInfoUsedOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxSigGrpInfoIndEndIdxOfTxPduInfoType, COM_CODE) Com_GetTxSigGrpInfoIndEndIdxOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxSigGrpInfoIndUsedOfTxPduInfoType, COM_CODE) Com_IsTxSigGrpInfoIndUsedOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TypeOfTxPduInfoType, COM_CODE) Com_GetTypeOfTxPduInfo(Com_TxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_SigGroupOnChangeOffsetOfTxSigGrpInfoType, COM_CODE) Com_GetSigGroupOnChangeOffsetOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_SigGroupOnChangeWithoutRepOffsetOfTxSigGrpInfoType, COM_CODE) Com_GetSigGroupOnChangeWithoutRepOffsetOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_SigGroupOnChangeWithoutRepStartPositionOfTxSigGrpInfoType, COM_CODE) Com_GetSigGroupOnChangeWithoutRepStartPositionOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoSigGrpInTxIPDUUsedOfTxSigGrpInfoType, COM_CODE) Com_IsTxBufferInfoSigGrpInTxIPDUUsedOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxSigGrpOnChangeMaskOnChangeLengthOfTxSigGrpInfoType, COM_CODE) Com_GetTxSigGrpOnChangeMaskOnChangeLengthOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxSigGrpOnChangeMaskOnChangeWithoutRepLengthOfTxSigGrpInfoType, COM_CODE) Com_GetTxSigGrpOnChangeMaskOnChangeWithoutRepLengthOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index);
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
  \defgroup  ComPCSetDataInlineFunctionPrototypes  Set Data Inline Function Prototypes
  \brief  These inline functions can be used to write data.
  \{
*/ 
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetCallDeferredConfirmationNotification(Com_CallDeferredConfirmationNotificationIterType Index, Com_CallDeferredConfirmationNotificationType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetSigGrpEventFlag(Com_SigGrpEventFlagIterType Index, Com_SigGrpEventFlagType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxSduLength(Com_TxSduLengthIterType Index, Com_TxSduLengthType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxTmpPduLength(Com_TxTmpPduLengthIterType Index, Com_TxTmpPduLengthType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetWaitingForConfirmation(Com_WaitingForConfirmationIterType Index, Com_WaitingForConfirmationType Value);
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
  \defgroup  ComPCGetAddressOfDataInlineFunctionPrototypes  Get Address Of Data Inline Function Prototypes
  \brief  These inline functions can be used to get the data by the address operator.
  \{
*/ 
COM_LOCAL_INLINE FUNC(Com_TxSigGrpOnChangeMaskPtrType, COM_CODE) Com_GetAddrTxSigGrpOnChangeMask(Com_TxSigGrpOnChangeMaskIterType Index);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCallDeferredConfirmationNotification(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasDynamicInitialLength(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasIPduGroupInfoOfTxPduInfoInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingConfirmationNotificationInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingErrorNotificationInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSigGrpEventFlag(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfCallDeferredConfirmationNotification(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfDynamicInitialLength(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfIPduGroupInfoOfTxPduInfoInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfReportingConfirmationNotificationInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfReportingErrorNotificationInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfSigGrpEventFlag(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxGrpSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxInvalidationInfoInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxProcessingPdus(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxSduLength(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxSigGrpInfoInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxSigGrpOnChangeMask(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxTmpPduLength(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfWaitingForConfirmation(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasDynamicInitialLengthIdxOfTxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasDynamicInitialLengthUsedOfTxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvalidHndOfTxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxGrpSigInfoIdxOfTxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxGrpSigInfoUsedOfTxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxInvalidationInfoIdxOfTxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxInvalidationInfoUsedOfTxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInfoIdxOfTxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigInfoIdxOfTxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigInfoUsedOfTxAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxGrpSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasByteLengthOfTxGrpSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSerializerInfoIdxOfTxGrpSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSerializerInfoUsedOfTxGrpSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasStartByteInPduPositionOfTxGrpSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransferPropertyFilterInfoIdxOfTxGrpSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransferPropertyFilterInfoUsedOfTxGrpSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransmissionModeFilterInfoIdxOfTxGrpSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransmissionModeFilterInfoUsedOfTxGrpSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTriggeredOfTxGrpSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxAccessInfoIdxOfTxGrpSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInfoIdxOfTxGrpSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpInfoIdxOfTxGrpSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxTmpPduLengthIdxOfTxGrpSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxTmpPduLengthUsedOfTxGrpSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasWithoutRepOfTxGrpSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxInvalidationInfoInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCancellationSupportOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasClrUbOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasComTimerInfoMDTTimerIdxOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasComTimerInfoMDTTimerUsedOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasExternalIdOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwTimeoutInfoIdxOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwTimeoutInfoUsedOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasIPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasIPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasIPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInitModeOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvalidHndOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMainFunctionTxStructIdxOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataLengthOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasPartitionsTxStructIdxOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRepetitionInfoIdxOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRepetitionInfoUsedOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingConfirmationNotificationIndEndIdxOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingConfirmationNotificationIndStartIdxOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingConfirmationNotificationIndUsedOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingErrorNotificationIndEndIdxOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingErrorNotificationIndStartIdxOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingErrorNotificationIndUsedOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingIPduTriggerTransmitCalloutIdxOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingIPduTriggerTransmitCalloutUsedOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingTxIPduCalloutIdxOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingTxIPduCalloutUsedOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSignalProcessingOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxAccessInfoDynSigIdxOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxAccessInfoDynSigUsedOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoIdxOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoUsedOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxMetaDataBufferInfoIdxOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxMetaDataBufferInfoUsedOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxModeFalseIdxOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxModeTrueIdxOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduFilterInfoIdxOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpInfoIndEndIdxOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpInfoIndStartIdxOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpInfoIndUsedOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxTOutInfoIdxOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxTOutInfoUsedOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxTpInfoIdxOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxTpInfoUsedOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTypeOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxProcessingPdus(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInfoIdxOfTxProcessingPdus(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSduLength(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasArrayAccessUsedOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvalidHndOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSigGroupOnChangeOffsetOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSigGroupOnChangeStartPositionOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSigGroupOnChangeWithoutRepOffsetOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSigGroupOnChangeWithoutRepStartPositionOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransferPropertyOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransmissionModeFilterInfoEndIdxOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransmissionModeFilterInfoStartIdxOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransmissionModeFilterInfoUsedOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoIdxOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoSigGrpInTxIPDUIdxOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoSigGrpInTxIPDUUsedOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoUbIdxAndMaskIdxOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoUbIdxAndMaskUsedOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoUsedOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxInvalidationInfoIndEndIdxOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxInvalidationInfoIndStartIdxOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxInvalidationInfoIndUsedOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInfoIdxOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpOnChangeMaskOnChangeEndIdxOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpOnChangeMaskOnChangeLengthOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpOnChangeMaskOnChangeStartIdxOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpOnChangeMaskOnChangeUsedOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpOnChangeMaskOnChangeWithoutRepEndIdxOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpOnChangeMaskOnChangeWithoutRepLengthOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpOnChangeMaskOnChangeWithoutRepStartIdxOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpOnChangeMaskOnChangeWithoutRepUsedOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpInfoInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpOnChangeMask(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasByteLengthOfTxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSerializerInfoIdxOfTxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSerializerInfoUsedOfTxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasStartByteInPduPositionOfTxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransferPropertyFilterInfoIdxOfTxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransferPropertyFilterInfoUsedOfTxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransmissionModeFilterInfoIdxOfTxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransmissionModeFilterInfoUsedOfTxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTriggeredOfTxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxAccessInfoIdxOfTxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoUbIdxAndMaskIdxOfTxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoUbIdxAndMaskUsedOfTxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInfoIdxOfTxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasWithoutRepOfTxSigInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxTmpPduLength(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasWaitingForConfirmation(void);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTRANSMITClrUbOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTRIGGER_TRANSMITClrUbOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNOT_USEDClrUbOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsCONFIRMATIONClrUbOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsDEFERREDSignalProcessingOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsIMMEDIATESignalProcessingOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNORMALTypeOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTPTypeOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsPENDINGTransferPropertyOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTRIGGEREDTransferPropertyOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTRIGGERED_WITHOUT_REPETITIONTransferPropertyOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTRIGGERED_ON_CHANGETransferPropertyOfTxSigGrpInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTRIGGERED_ON_CHANGE_WITHOUT_REPETITIONTransferPropertyOfTxSigGrpInfo(void);
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
  \defgroup  ComPCIncrementInlineFunctionPrototypes  Increment Inline Function Prototypes
  \brief  These inline functions can be used to increment VAR data with numerical nature.
  \{
*/ 
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTxSduLength(Com_TxSduLengthIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTxTmpPduLength(Com_TxTmpPduLengthIterType Index);
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
  \defgroup  ComPCDecrementInlineFunctionPrototypes  Decrement Inline Function Prototypes
  \brief  These inline functions can be used to decrement VAR data with numerical nature.
  \{
*/ 
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTxSduLength(Com_TxSduLengthIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTxTmpPduLength(Com_TxTmpPduLengthIterType Index);
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
  \defgroup  ComPCAddInlineFunctionPrototypes  Add Inline Function Prototypes
  \brief  These inline functions can be used to add VAR data with numerical nature.
  \{
*/ 
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTxSduLength(Com_TxSduLengthIterType Index, Com_TxSduLengthType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTxTmpPduLength(Com_TxTmpPduLengthIterType Index, Com_TxTmpPduLengthType Value);
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
  \defgroup  ComPCSubstractInlineFunctionPrototypes  Substract Inline Function Prototypes
  \brief  These inline functions can be used to substract VAR data with numerical nature.
  \{
*/ 
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTxSduLength(Com_TxSduLengthIterType Index, Com_TxSduLengthType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTxTmpPduLength(Com_TxTmpPduLengthIterType Index, Com_TxTmpPduLengthType Value);
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
COM_LOCAL_INLINE FUNC(Com_SizeOfCallDeferredConfirmationNotificationType, COM_CODE) Com_GetSizeOfCallDeferredConfirmationNotification(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfCallDeferredConfirmationNotificationType) Com_GetSizeOfCallDeferredConfirmationNotificationOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfDynamicInitialLengthType, COM_CODE) Com_GetSizeOfDynamicInitialLength(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfDynamicInitialLengthType) Com_GetSizeOfDynamicInitialLengthOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfIPduGroupInfoOfTxPduInfoIndType, COM_CODE) Com_GetSizeOfIPduGroupInfoOfTxPduInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfIPduGroupInfoOfTxPduInfoIndType) Com_GetSizeOfIPduGroupInfoOfTxPduInfoIndOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfReportingConfirmationNotificationIndType, COM_CODE) Com_GetSizeOfReportingConfirmationNotificationInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfReportingConfirmationNotificationIndType) Com_GetSizeOfReportingConfirmationNotificationIndOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfReportingErrorNotificationIndType, COM_CODE) Com_GetSizeOfReportingErrorNotificationInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfReportingErrorNotificationIndType) Com_GetSizeOfReportingErrorNotificationIndOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfSigGrpEventFlagType, COM_CODE) Com_GetSizeOfSigGrpEventFlag(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfSigGrpEventFlagType) Com_GetSizeOfSigGrpEventFlagOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxAccessInfoType, COM_CODE) Com_GetSizeOfTxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxAccessInfoType) Com_GetSizeOfTxAccessInfoOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxGrpSigInfoType, COM_CODE) Com_GetSizeOfTxGrpSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxGrpSigInfoType) Com_GetSizeOfTxGrpSigInfoOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxInvalidationInfoIndType, COM_CODE) Com_GetSizeOfTxInvalidationInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxInvalidationInfoIndType) Com_GetSizeOfTxInvalidationInfoIndOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxPduInfoType, COM_CODE) Com_GetSizeOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxPduInfoType) Com_GetSizeOfTxPduInfoOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxProcessingPdusType, COM_CODE) Com_GetSizeOfTxProcessingPdus(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxProcessingPdusType) Com_GetSizeOfTxProcessingPdusOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxSduLengthType, COM_CODE) Com_GetSizeOfTxSduLength(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxSduLengthType) Com_GetSizeOfTxSduLengthOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxSigGrpInfoType, COM_CODE) Com_GetSizeOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxSigGrpInfoType) Com_GetSizeOfTxSigGrpInfoOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxSigGrpInfoIndType, COM_CODE) Com_GetSizeOfTxSigGrpInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxSigGrpInfoIndType) Com_GetSizeOfTxSigGrpInfoIndOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxSigGrpOnChangeMaskType, COM_CODE) Com_GetSizeOfTxSigGrpOnChangeMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxSigGrpOnChangeMaskType) Com_GetSizeOfTxSigGrpOnChangeMaskOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxSigInfoType, COM_CODE) Com_GetSizeOfTxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxSigInfoType) Com_GetSizeOfTxSigInfoOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxTmpPduLengthType, COM_CODE) Com_GetSizeOfTxTmpPduLength(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxTmpPduLengthType) Com_GetSizeOfTxTmpPduLengthOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfWaitingForConfirmationType, COM_CODE) Com_GetSizeOfWaitingForConfirmation(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfWaitingForConfirmationType) Com_GetSizeOfWaitingForConfirmationOfPCConfig();
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
COM_LOCAL_INLINE FUNC(Com_CallDeferredConfirmationNotificationType, COM_CODE) Com_IsCallDeferredConfirmationNotification(Com_CallDeferredConfirmationNotificationIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_CallDeferredConfirmationNotificationType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_DynamicInitialLengthType, COM_CODE) Com_GetDynamicInitialLength(Com_DynamicInitialLengthIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_DynamicInitialLengthType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_IPduGroupInfoOfTxPduInfoIndType, COM_CODE) Com_GetIPduGroupInfoOfTxPduInfoInd(Com_IPduGroupInfoOfTxPduInfoIndIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_IPduGroupInfoOfTxPduInfoIndType) (Com_GetIPduGroupInfoOfTxPduInfoIndOfPCConfig()[(Index)]);
}
COM_LOCAL_INLINE FUNC(Com_ReportingConfirmationNotificationIndType, COM_CODE) Com_GetReportingConfirmationNotificationInd(Com_ReportingConfirmationNotificationIndIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ReportingConfirmationNotificationIndType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_ReportingErrorNotificationIndType, COM_CODE) Com_GetReportingErrorNotificationInd(Com_ReportingErrorNotificationIndIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ReportingErrorNotificationIndType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_SigGrpEventFlagType, COM_CODE) Com_GetSigGrpEventFlag(Com_SigGrpEventFlagIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_SigGrpEventFlagType) (Com_GetSigGrpEventFlagOfPCConfig()[(Index)]);
}
COM_LOCAL_INLINE FUNC(Com_DynamicInitialLengthIdxOfTxAccessInfoType, COM_CODE) Com_GetDynamicInitialLengthIdxOfTxAccessInfo(Com_TxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_DynamicInitialLengthIdxOfTxAccessInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_DynamicInitialLengthUsedOfTxAccessInfoType, COM_CODE) Com_IsDynamicInitialLengthUsedOfTxAccessInfo(Com_TxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_DynamicInitialLengthUsedOfTxAccessInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_InvalidHndOfTxAccessInfoType, COM_CODE) Com_IsInvalidHndOfTxAccessInfo(Com_TxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvalidHndOfTxAccessInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TxGrpSigInfoIdxOfTxAccessInfoType, COM_CODE) Com_GetTxGrpSigInfoIdxOfTxAccessInfo(Com_TxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxGrpSigInfoIdxOfTxAccessInfoType) (Com_GetTxAccessInfoOfPCConfig()[(Index)].TxGrpSigInfoIdxOfTxAccessInfo);
}
COM_LOCAL_INLINE FUNC(Com_TxInvalidationInfoIdxOfTxAccessInfoType, COM_CODE) Com_GetTxInvalidationInfoIdxOfTxAccessInfo(Com_TxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxInvalidationInfoIdxOfTxAccessInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxInvalidationInfoUsedOfTxAccessInfoType, COM_CODE) Com_IsTxInvalidationInfoUsedOfTxAccessInfo(Com_TxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxInvalidationInfoUsedOfTxAccessInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TxPduInfoIdxOfTxAccessInfoType, COM_CODE) Com_GetTxPduInfoIdxOfTxAccessInfo(Com_TxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxPduInfoIdxOfTxAccessInfoType) (Com_GetTxAccessInfoOfPCConfig()[(Index)].TxPduInfoIdxOfTxAccessInfo);
}
COM_LOCAL_INLINE FUNC(Com_TxSigInfoIdxOfTxAccessInfoType, COM_CODE) Com_GetTxSigInfoIdxOfTxAccessInfo(Com_TxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxSigInfoIdxOfTxAccessInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxSigInfoUsedOfTxAccessInfoType, COM_CODE) Com_IsTxSigInfoUsedOfTxAccessInfo(Com_TxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxSigInfoUsedOfTxAccessInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_ByteLengthOfTxGrpSigInfoType, COM_CODE) Com_GetByteLengthOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ByteLengthOfTxGrpSigInfoType) (Com_GetTxGrpSigInfoOfPCConfig()[(Index)].ByteLengthOfTxGrpSigInfo);
}
COM_LOCAL_INLINE FUNC(Com_SerializerInfoIdxOfTxGrpSigInfoType, COM_CODE) Com_GetSerializerInfoIdxOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_SerializerInfoIdxOfTxGrpSigInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_SerializerInfoUsedOfTxGrpSigInfoType, COM_CODE) Com_IsSerializerInfoUsedOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_SerializerInfoUsedOfTxGrpSigInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_StartByteInPduPositionOfTxGrpSigInfoType, COM_CODE) Com_GetStartByteInPduPositionOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_StartByteInPduPositionOfTxGrpSigInfoType) (Com_GetTxGrpSigInfoOfPCConfig()[(Index)].StartByteInPduPositionOfTxGrpSigInfo);
}
COM_LOCAL_INLINE FUNC(Com_TransferPropertyFilterInfoIdxOfTxGrpSigInfoType, COM_CODE) Com_GetTransferPropertyFilterInfoIdxOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TransferPropertyFilterInfoIdxOfTxGrpSigInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TransferPropertyFilterInfoUsedOfTxGrpSigInfoType, COM_CODE) Com_IsTransferPropertyFilterInfoUsedOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TransferPropertyFilterInfoUsedOfTxGrpSigInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TransmissionModeFilterInfoIdxOfTxGrpSigInfoType, COM_CODE) Com_GetTransmissionModeFilterInfoIdxOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TransmissionModeFilterInfoIdxOfTxGrpSigInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TransmissionModeFilterInfoUsedOfTxGrpSigInfoType, COM_CODE) Com_IsTransmissionModeFilterInfoUsedOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TransmissionModeFilterInfoUsedOfTxGrpSigInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TriggeredOfTxGrpSigInfoType, COM_CODE) Com_IsTriggeredOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TriggeredOfTxGrpSigInfoType) ((Com_GetTxGrpSigInfoOfPCConfig()[(Index)].TriggeredOfTxGrpSigInfo) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TxPduInfoIdxOfTxGrpSigInfoType, COM_CODE) Com_GetTxPduInfoIdxOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxPduInfoIdxOfTxGrpSigInfoType) (Com_GetTxGrpSigInfoOfPCConfig()[(Index)].TxPduInfoIdxOfTxGrpSigInfo);
}
COM_LOCAL_INLINE FUNC(Com_TxSigGrpInfoIdxOfTxGrpSigInfoType, COM_CODE) Com_GetTxSigGrpInfoIdxOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxSigGrpInfoIdxOfTxGrpSigInfoType) (Com_GetTxGrpSigInfoOfPCConfig()[(Index)].TxSigGrpInfoIdxOfTxGrpSigInfo);
}
COM_LOCAL_INLINE FUNC(Com_TxTmpPduLengthIdxOfTxGrpSigInfoType, COM_CODE) Com_GetTxTmpPduLengthIdxOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxTmpPduLengthIdxOfTxGrpSigInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxTmpPduLengthUsedOfTxGrpSigInfoType, COM_CODE) Com_IsTxTmpPduLengthUsedOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxTmpPduLengthUsedOfTxGrpSigInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_WithoutRepOfTxGrpSigInfoType, COM_CODE) Com_IsWithoutRepOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_WithoutRepOfTxGrpSigInfoType) ((Com_GetTxGrpSigInfoOfPCConfig()[(Index)].WithoutRepOfTxGrpSigInfo) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TxInvalidationInfoIndType, COM_CODE) Com_GetTxInvalidationInfoInd(Com_TxInvalidationInfoIndIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxInvalidationInfoIndType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_ComTimerInfoMDTTimerIdxOfTxPduInfoType, COM_CODE) Com_GetComTimerInfoMDTTimerIdxOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ComTimerInfoMDTTimerIdxOfTxPduInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_ComTimerInfoMDTTimerUsedOfTxPduInfoType, COM_CODE) Com_IsComTimerInfoMDTTimerUsedOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ComTimerInfoMDTTimerUsedOfTxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_ExternalIdOfTxPduInfoType, COM_CODE) Com_GetExternalIdOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ExternalIdOfTxPduInfoType) (Com_GetTxPduInfoOfPCConfig()[(Index)].ExternalIdOfTxPduInfo);
}
COM_LOCAL_INLINE FUNC(Com_GwTimeoutInfoIdxOfTxPduInfoType, COM_CODE) Com_GetGwTimeoutInfoIdxOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwTimeoutInfoIdxOfTxPduInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_GwTimeoutInfoUsedOfTxPduInfoType, COM_CODE) Com_IsGwTimeoutInfoUsedOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwTimeoutInfoUsedOfTxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_IPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfoType, COM_CODE) Com_GetIPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_IPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfoType) (Com_GetTxPduInfoOfPCConfig()[(Index)].IPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfo);
}
COM_LOCAL_INLINE FUNC(Com_InitModeOfTxPduInfoType, COM_CODE) Com_IsInitModeOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InitModeOfTxPduInfoType) ((Com_GetTxPduInfoOfPCConfig()[(Index)].InitModeOfTxPduInfo) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_InvalidHndOfTxPduInfoType, COM_CODE) Com_IsInvalidHndOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvalidHndOfTxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_MainFunctionTxStructIdxOfTxPduInfoType, COM_CODE) Com_GetMainFunctionTxStructIdxOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_MainFunctionTxStructIdxOfTxPduInfoType) (Com_GetTxPduInfoOfPCConfig()[(Index)].MainFunctionTxStructIdxOfTxPduInfo);
}
COM_LOCAL_INLINE FUNC(Com_PartitionsTxStructIdxOfTxPduInfoType, COM_CODE) Com_GetPartitionsTxStructIdxOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_PartitionsTxStructIdxOfTxPduInfoType) (Com_GetTxPduInfoOfPCConfig()[(Index)].PartitionsTxStructIdxOfTxPduInfo);
}
COM_LOCAL_INLINE FUNC(Com_RepetitionInfoIdxOfTxPduInfoType, COM_CODE) Com_GetRepetitionInfoIdxOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RepetitionInfoIdxOfTxPduInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_RepetitionInfoUsedOfTxPduInfoType, COM_CODE) Com_IsRepetitionInfoUsedOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RepetitionInfoUsedOfTxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_ReportingConfirmationNotificationIndEndIdxOfTxPduInfoType, COM_CODE) Com_GetReportingConfirmationNotificationIndEndIdxOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ReportingConfirmationNotificationIndEndIdxOfTxPduInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_ReportingConfirmationNotificationIndStartIdxOfTxPduInfoType, COM_CODE) Com_GetReportingConfirmationNotificationIndStartIdxOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ReportingConfirmationNotificationIndStartIdxOfTxPduInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_ReportingConfirmationNotificationIndUsedOfTxPduInfoType, COM_CODE) Com_IsReportingConfirmationNotificationIndUsedOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ReportingConfirmationNotificationIndUsedOfTxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_ReportingErrorNotificationIndEndIdxOfTxPduInfoType, COM_CODE) Com_GetReportingErrorNotificationIndEndIdxOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ReportingErrorNotificationIndEndIdxOfTxPduInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_ReportingErrorNotificationIndStartIdxOfTxPduInfoType, COM_CODE) Com_GetReportingErrorNotificationIndStartIdxOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ReportingErrorNotificationIndStartIdxOfTxPduInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_ReportingErrorNotificationIndUsedOfTxPduInfoType, COM_CODE) Com_IsReportingErrorNotificationIndUsedOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ReportingErrorNotificationIndUsedOfTxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_ReportingIPduTriggerTransmitCalloutIdxOfTxPduInfoType, COM_CODE) Com_GetReportingIPduTriggerTransmitCalloutIdxOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ReportingIPduTriggerTransmitCalloutIdxOfTxPduInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_ReportingIPduTriggerTransmitCalloutUsedOfTxPduInfoType, COM_CODE) Com_IsReportingIPduTriggerTransmitCalloutUsedOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ReportingIPduTriggerTransmitCalloutUsedOfTxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_ReportingTxIPduCalloutIdxOfTxPduInfoType, COM_CODE) Com_GetReportingTxIPduCalloutIdxOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ReportingTxIPduCalloutIdxOfTxPduInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_ReportingTxIPduCalloutUsedOfTxPduInfoType, COM_CODE) Com_IsReportingTxIPduCalloutUsedOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ReportingTxIPduCalloutUsedOfTxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TxAccessInfoDynSigIdxOfTxPduInfoType, COM_CODE) Com_GetTxAccessInfoDynSigIdxOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxAccessInfoDynSigIdxOfTxPduInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxAccessInfoDynSigUsedOfTxPduInfoType, COM_CODE) Com_IsTxAccessInfoDynSigUsedOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxAccessInfoDynSigUsedOfTxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoIdxOfTxPduInfoType, COM_CODE) Com_GetTxBufferInfoIdxOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxBufferInfoIdxOfTxPduInfoType) (Com_GetTxPduInfoOfPCConfig()[(Index)].TxBufferInfoIdxOfTxPduInfo);
}
COM_LOCAL_INLINE FUNC(Com_TxMetaDataBufferInfoIdxOfTxPduInfoType, COM_CODE) Com_GetTxMetaDataBufferInfoIdxOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxMetaDataBufferInfoIdxOfTxPduInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxMetaDataBufferInfoUsedOfTxPduInfoType, COM_CODE) Com_IsTxMetaDataBufferInfoUsedOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxMetaDataBufferInfoUsedOfTxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TxModeFalseIdxOfTxPduInfoType, COM_CODE) Com_GetTxModeFalseIdxOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxModeFalseIdxOfTxPduInfoType) (Com_GetTxPduInfoOfPCConfig()[(Index)].TxModeFalseIdxOfTxPduInfo);
}
COM_LOCAL_INLINE FUNC(Com_TxModeTrueIdxOfTxPduInfoType, COM_CODE) Com_GetTxModeTrueIdxOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxModeTrueIdxOfTxPduInfoType) (Com_GetTxPduInfoOfPCConfig()[(Index)].TxModeTrueIdxOfTxPduInfo);
}
COM_LOCAL_INLINE FUNC(Com_TxPduFilterInfoIdxOfTxPduInfoType, COM_CODE) Com_GetTxPduFilterInfoIdxOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxPduFilterInfoIdxOfTxPduInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxSigGrpInfoIndStartIdxOfTxPduInfoType, COM_CODE) Com_GetTxSigGrpInfoIndStartIdxOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxSigGrpInfoIndStartIdxOfTxPduInfoType) (Com_GetTxPduInfoOfPCConfig()[(Index)].TxSigGrpInfoIndStartIdxOfTxPduInfo);
}
COM_LOCAL_INLINE FUNC(Com_TxTOutInfoIdxOfTxPduInfoType, COM_CODE) Com_GetTxTOutInfoIdxOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxTOutInfoIdxOfTxPduInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxTOutInfoUsedOfTxPduInfoType, COM_CODE) Com_IsTxTOutInfoUsedOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxTOutInfoUsedOfTxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TxTpInfoIdxOfTxPduInfoType, COM_CODE) Com_GetTxTpInfoIdxOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxTpInfoIdxOfTxPduInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxTpInfoUsedOfTxPduInfoType, COM_CODE) Com_IsTxTpInfoUsedOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxTpInfoUsedOfTxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TxPduInfoIdxOfTxProcessingPdusType, COM_CODE) Com_GetTxPduInfoIdxOfTxProcessingPdus(Com_TxProcessingPdusIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxPduInfoIdxOfTxProcessingPdusType) (Com_GetTxProcessingPdusOfPCConfig()[(Index)].TxPduInfoIdxOfTxProcessingPdus);
}
COM_LOCAL_INLINE FUNC(Com_TxSduLengthType, COM_CODE) Com_GetTxSduLength(Com_TxSduLengthIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxSduLengthType) (Com_GetTxSduLengthOfPCConfig()[(Index)]);
}
COM_LOCAL_INLINE FUNC(Com_ArrayAccessUsedOfTxSigGrpInfoType, COM_CODE) Com_IsArrayAccessUsedOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ArrayAccessUsedOfTxSigGrpInfoType) ((Com_GetTxSigGrpInfoOfPCConfig()[(Index)].ArrayAccessUsedOfTxSigGrpInfo) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_InvalidHndOfTxSigGrpInfoType, COM_CODE) Com_IsInvalidHndOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvalidHndOfTxSigGrpInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_SigGroupOnChangeStartPositionOfTxSigGrpInfoType, COM_CODE) Com_GetSigGroupOnChangeStartPositionOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_SigGroupOnChangeStartPositionOfTxSigGrpInfoType) (Com_GetTxSigGrpInfoOfPCConfig()[(Index)].SigGroupOnChangeStartPositionOfTxSigGrpInfo);
}
COM_LOCAL_INLINE FUNC(Com_TransferPropertyOfTxSigGrpInfoType, COM_CODE) Com_GetTransferPropertyOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TransferPropertyOfTxSigGrpInfoType) (Com_GetTxSigGrpInfoOfPCConfig()[(Index)].TransferPropertyOfTxSigGrpInfo);
}
COM_LOCAL_INLINE FUNC(Com_TransmissionModeFilterInfoEndIdxOfTxSigGrpInfoType, COM_CODE) Com_GetTransmissionModeFilterInfoEndIdxOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TransmissionModeFilterInfoEndIdxOfTxSigGrpInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TransmissionModeFilterInfoStartIdxOfTxSigGrpInfoType, COM_CODE) Com_GetTransmissionModeFilterInfoStartIdxOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TransmissionModeFilterInfoStartIdxOfTxSigGrpInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TransmissionModeFilterInfoUsedOfTxSigGrpInfoType, COM_CODE) Com_IsTransmissionModeFilterInfoUsedOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TransmissionModeFilterInfoUsedOfTxSigGrpInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoIdxOfTxSigGrpInfoType, COM_CODE) Com_GetTxBufferInfoIdxOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxBufferInfoIdxOfTxSigGrpInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoSigGrpInTxIPDUIdxOfTxSigGrpInfoType, COM_CODE) Com_GetTxBufferInfoSigGrpInTxIPDUIdxOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxBufferInfoSigGrpInTxIPDUIdxOfTxSigGrpInfoType) (Com_GetTxSigGrpInfoOfPCConfig()[(Index)].TxBufferInfoSigGrpInTxIPDUIdxOfTxSigGrpInfo);
}
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoUbIdxAndMaskIdxOfTxSigGrpInfoType, COM_CODE) Com_GetTxBufferInfoUbIdxAndMaskIdxOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxBufferInfoUbIdxAndMaskIdxOfTxSigGrpInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoUbIdxAndMaskUsedOfTxSigGrpInfoType, COM_CODE) Com_IsTxBufferInfoUbIdxAndMaskUsedOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxBufferInfoUbIdxAndMaskUsedOfTxSigGrpInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoUsedOfTxSigGrpInfoType, COM_CODE) Com_IsTxBufferInfoUsedOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxBufferInfoUsedOfTxSigGrpInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TxInvalidationInfoIndEndIdxOfTxSigGrpInfoType, COM_CODE) Com_GetTxInvalidationInfoIndEndIdxOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxInvalidationInfoIndEndIdxOfTxSigGrpInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxInvalidationInfoIndStartIdxOfTxSigGrpInfoType, COM_CODE) Com_GetTxInvalidationInfoIndStartIdxOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxInvalidationInfoIndStartIdxOfTxSigGrpInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxInvalidationInfoIndUsedOfTxSigGrpInfoType, COM_CODE) Com_IsTxInvalidationInfoIndUsedOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxInvalidationInfoIndUsedOfTxSigGrpInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TxPduInfoIdxOfTxSigGrpInfoType, COM_CODE) Com_GetTxPduInfoIdxOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxPduInfoIdxOfTxSigGrpInfoType) (Com_GetTxSigGrpInfoOfPCConfig()[(Index)].TxPduInfoIdxOfTxSigGrpInfo);
}
COM_LOCAL_INLINE FUNC(Com_TxSigGrpOnChangeMaskOnChangeEndIdxOfTxSigGrpInfoType, COM_CODE) Com_GetTxSigGrpOnChangeMaskOnChangeEndIdxOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxSigGrpOnChangeMaskOnChangeEndIdxOfTxSigGrpInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxSigGrpOnChangeMaskOnChangeStartIdxOfTxSigGrpInfoType, COM_CODE) Com_GetTxSigGrpOnChangeMaskOnChangeStartIdxOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxSigGrpOnChangeMaskOnChangeStartIdxOfTxSigGrpInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxSigGrpOnChangeMaskOnChangeUsedOfTxSigGrpInfoType, COM_CODE) Com_IsTxSigGrpOnChangeMaskOnChangeUsedOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxSigGrpOnChangeMaskOnChangeUsedOfTxSigGrpInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TxSigGrpOnChangeMaskOnChangeWithoutRepEndIdxOfTxSigGrpInfoType, COM_CODE) Com_GetTxSigGrpOnChangeMaskOnChangeWithoutRepEndIdxOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxSigGrpOnChangeMaskOnChangeWithoutRepEndIdxOfTxSigGrpInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxSigGrpOnChangeMaskOnChangeWithoutRepStartIdxOfTxSigGrpInfoType, COM_CODE) Com_GetTxSigGrpOnChangeMaskOnChangeWithoutRepStartIdxOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxSigGrpOnChangeMaskOnChangeWithoutRepStartIdxOfTxSigGrpInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxSigGrpOnChangeMaskOnChangeWithoutRepUsedOfTxSigGrpInfoType, COM_CODE) Com_IsTxSigGrpOnChangeMaskOnChangeWithoutRepUsedOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxSigGrpOnChangeMaskOnChangeWithoutRepUsedOfTxSigGrpInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TxSigGrpInfoIndType, COM_CODE) Com_GetTxSigGrpInfoInd(Com_TxSigGrpInfoIndIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxSigGrpInfoIndType) (Com_GetTxSigGrpInfoIndOfPCConfig()[(Index)]);
}
COM_LOCAL_INLINE FUNC(Com_TxSigGrpOnChangeMaskType, COM_CODE) Com_GetTxSigGrpOnChangeMask(Com_TxSigGrpOnChangeMaskIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxSigGrpOnChangeMaskType) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_ByteLengthOfTxSigInfoType, COM_CODE) Com_GetByteLengthOfTxSigInfo(Com_TxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ByteLengthOfTxSigInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_SerializerInfoIdxOfTxSigInfoType, COM_CODE) Com_GetSerializerInfoIdxOfTxSigInfo(Com_TxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_SerializerInfoIdxOfTxSigInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_SerializerInfoUsedOfTxSigInfoType, COM_CODE) Com_IsSerializerInfoUsedOfTxSigInfo(Com_TxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_SerializerInfoUsedOfTxSigInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_StartByteInPduPositionOfTxSigInfoType, COM_CODE) Com_GetStartByteInPduPositionOfTxSigInfo(Com_TxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_StartByteInPduPositionOfTxSigInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TransferPropertyFilterInfoIdxOfTxSigInfoType, COM_CODE) Com_GetTransferPropertyFilterInfoIdxOfTxSigInfo(Com_TxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TransferPropertyFilterInfoIdxOfTxSigInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TransferPropertyFilterInfoUsedOfTxSigInfoType, COM_CODE) Com_IsTransferPropertyFilterInfoUsedOfTxSigInfo(Com_TxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TransferPropertyFilterInfoUsedOfTxSigInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TransmissionModeFilterInfoIdxOfTxSigInfoType, COM_CODE) Com_GetTransmissionModeFilterInfoIdxOfTxSigInfo(Com_TxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TransmissionModeFilterInfoIdxOfTxSigInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TransmissionModeFilterInfoUsedOfTxSigInfoType, COM_CODE) Com_IsTransmissionModeFilterInfoUsedOfTxSigInfo(Com_TxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TransmissionModeFilterInfoUsedOfTxSigInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TriggeredOfTxSigInfoType, COM_CODE) Com_IsTriggeredOfTxSigInfo(Com_TxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TriggeredOfTxSigInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TxAccessInfoIdxOfTxSigInfoType, COM_CODE) Com_GetTxAccessInfoIdxOfTxSigInfo(Com_TxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxAccessInfoIdxOfTxSigInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoUbIdxAndMaskIdxOfTxSigInfoType, COM_CODE) Com_GetTxBufferInfoUbIdxAndMaskIdxOfTxSigInfo(Com_TxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxBufferInfoUbIdxAndMaskIdxOfTxSigInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoUbIdxAndMaskUsedOfTxSigInfoType, COM_CODE) Com_IsTxBufferInfoUbIdxAndMaskUsedOfTxSigInfo(Com_TxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxBufferInfoUbIdxAndMaskUsedOfTxSigInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TxPduInfoIdxOfTxSigInfoType, COM_CODE) Com_GetTxPduInfoIdxOfTxSigInfo(Com_TxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxPduInfoIdxOfTxSigInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_WithoutRepOfTxSigInfoType, COM_CODE) Com_IsWithoutRepOfTxSigInfo(Com_TxSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_WithoutRepOfTxSigInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TxTmpPduLengthType, COM_CODE) Com_GetTxTmpPduLength(Com_TxTmpPduLengthIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxTmpPduLengthType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_WaitingForConfirmationType, COM_CODE) Com_IsWaitingForConfirmation(Com_WaitingForConfirmationIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_WaitingForConfirmationType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
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
COM_LOCAL_INLINE FUNC(Com_TxGrpSigInfoUsedOfTxAccessInfoType, COM_CODE) Com_IsTxGrpSigInfoUsedOfTxAccessInfo(Com_TxAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxGrpSigInfoUsedOfTxAccessInfoType) (((boolean)(Com_GetTxGrpSigInfoIdxOfTxAccessInfo(Index) != COM_NO_TXGRPSIGINFOIDXOFTXACCESSINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TxAccessInfoIdxOfTxGrpSigInfoType, COM_CODE) Com_GetTxAccessInfoIdxOfTxGrpSigInfo(Com_TxGrpSigInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxAccessInfoIdxOfTxGrpSigInfoType) ((Com_TxAccessInfoIdxOfTxGrpSigInfoType)((Index)));
}
COM_LOCAL_INLINE FUNC(Com_CancellationSupportOfTxPduInfoType, COM_CODE) Com_IsCancellationSupportOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_CancellationSupportOfTxPduInfoType) (((!(Com_IsInitModeOfTxPduInfo(Index)))) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_ClrUbOfTxPduInfoType, COM_CODE) Com_GetClrUbOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ClrUbOfTxPduInfoType) ((Com_ClrUbOfTxPduInfoType)((Com_GetPartitionsTxStructIdxOfTxPduInfo(Index) + 2u)));
}
COM_LOCAL_INLINE FUNC(Com_IPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfoType, COM_CODE) Com_GetIPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_IPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfoType) ((Com_IPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfoType)((((Com_IPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfoType)(Index)) + 1u)));
}
COM_LOCAL_INLINE FUNC(Com_IPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfoType, COM_CODE) Com_IsIPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_IPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfoType) (((boolean)(Com_GetIPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfo(Index) != COM_NO_IPDUGROUPINFOOFTXPDUINFOINDSTARTIDXOFTXPDUINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_MetaDataLengthOfTxPduInfoType, COM_CODE) Com_GetMetaDataLengthOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_MetaDataLengthOfTxPduInfoType) Com_GetPartitionsTxStructIdxOfTxPduInfo(Index);
}
COM_LOCAL_INLINE FUNC(Com_SignalProcessingOfTxPduInfoType, COM_CODE) Com_GetSignalProcessingOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_SignalProcessingOfTxPduInfoType) Com_GetPartitionsTxStructIdxOfTxPduInfo(Index);
}
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoUsedOfTxPduInfoType, COM_CODE) Com_IsTxBufferInfoUsedOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxBufferInfoUsedOfTxPduInfoType) (((boolean)(Com_GetTxBufferInfoIdxOfTxPduInfo(Index) != COM_NO_TXBUFFERINFOIDXOFTXPDUINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TxSigGrpInfoIndEndIdxOfTxPduInfoType, COM_CODE) Com_GetTxSigGrpInfoIndEndIdxOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxSigGrpInfoIndEndIdxOfTxPduInfoType) ((Com_TxSigGrpInfoIndEndIdxOfTxPduInfoType)((((Com_TxSigGrpInfoIndEndIdxOfTxPduInfoType)(Index)) + 1u)));
}
COM_LOCAL_INLINE FUNC(Com_TxSigGrpInfoIndUsedOfTxPduInfoType, COM_CODE) Com_IsTxSigGrpInfoIndUsedOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxSigGrpInfoIndUsedOfTxPduInfoType) (((boolean)(Com_GetTxSigGrpInfoIndStartIdxOfTxPduInfo(Index) != COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TypeOfTxPduInfoType, COM_CODE) Com_GetTypeOfTxPduInfo(Com_TxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TypeOfTxPduInfoType) Com_GetPartitionsTxStructIdxOfTxPduInfo(Index);
}
COM_LOCAL_INLINE FUNC(Com_SigGroupOnChangeOffsetOfTxSigGrpInfoType, COM_CODE) Com_GetSigGroupOnChangeOffsetOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_SigGroupOnChangeOffsetOfTxSigGrpInfoType) Com_GetSigGroupOnChangeStartPositionOfTxSigGrpInfo(Index);
}
COM_LOCAL_INLINE FUNC(Com_SigGroupOnChangeWithoutRepOffsetOfTxSigGrpInfoType, COM_CODE) Com_GetSigGroupOnChangeWithoutRepOffsetOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_SigGroupOnChangeWithoutRepOffsetOfTxSigGrpInfoType) Com_GetSigGroupOnChangeStartPositionOfTxSigGrpInfo(Index);
}
COM_LOCAL_INLINE FUNC(Com_SigGroupOnChangeWithoutRepStartPositionOfTxSigGrpInfoType, COM_CODE) Com_GetSigGroupOnChangeWithoutRepStartPositionOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_SigGroupOnChangeWithoutRepStartPositionOfTxSigGrpInfoType) Com_GetSigGroupOnChangeStartPositionOfTxSigGrpInfo(Index);
}
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoSigGrpInTxIPDUUsedOfTxSigGrpInfoType, COM_CODE) Com_IsTxBufferInfoSigGrpInTxIPDUUsedOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxBufferInfoSigGrpInTxIPDUUsedOfTxSigGrpInfoType) (((boolean)(Com_GetTxBufferInfoSigGrpInTxIPDUIdxOfTxSigGrpInfo(Index) != COM_NO_TXBUFFERINFOSIGGRPINTXIPDUIDXOFTXSIGGRPINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TxSigGrpOnChangeMaskOnChangeLengthOfTxSigGrpInfoType, COM_CODE) Com_GetTxSigGrpOnChangeMaskOnChangeLengthOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxSigGrpOnChangeMaskOnChangeLengthOfTxSigGrpInfoType) ((Com_TxSigGrpOnChangeMaskOnChangeLengthOfTxSigGrpInfoType)((Com_GetTxSigGrpOnChangeMaskOnChangeEndIdxOfTxSigGrpInfo(Index) - Com_GetTxSigGrpOnChangeMaskOnChangeStartIdxOfTxSigGrpInfo(Index))));
}
COM_LOCAL_INLINE FUNC(Com_TxSigGrpOnChangeMaskOnChangeWithoutRepLengthOfTxSigGrpInfoType, COM_CODE) Com_GetTxSigGrpOnChangeMaskOnChangeWithoutRepLengthOfTxSigGrpInfo(Com_TxSigGrpInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxSigGrpOnChangeMaskOnChangeWithoutRepLengthOfTxSigGrpInfoType) ((Com_TxSigGrpOnChangeMaskOnChangeWithoutRepLengthOfTxSigGrpInfoType)((Com_GetTxSigGrpOnChangeMaskOnChangeWithoutRepEndIdxOfTxSigGrpInfo(Index) - Com_GetTxSigGrpOnChangeMaskOnChangeWithoutRepStartIdxOfTxSigGrpInfo(Index))));
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
  \defgroup  ComPCSetDataInlineFunctions  Com Set Data Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to write data.
  \{
*/ 
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetCallDeferredConfirmationNotification(Com_CallDeferredConfirmationNotificationIterType Index, Com_CallDeferredConfirmationNotificationType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetSigGrpEventFlag(Com_SigGrpEventFlagIterType Index, Com_SigGrpEventFlagType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetSigGrpEventFlagOfPCConfig()[(Index)] = (Value);
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxSduLength(Com_TxSduLengthIterType Index, Com_TxSduLengthType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetTxSduLengthOfPCConfig()[(Index)] = (Value);
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxTmpPduLength(Com_TxTmpPduLengthIterType Index, Com_TxTmpPduLengthType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetWaitingForConfirmation(Com_WaitingForConfirmationIterType Index, Com_WaitingForConfirmationType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
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
  \defgroup  ComPCGetAddressOfDataInlineFunctions  Com Get Address Of Data Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to get the data by the address operator.
  \{
*/ 
COM_LOCAL_INLINE FUNC(Com_TxSigGrpOnChangeMaskPtrType, COM_CODE) Com_GetAddrTxSigGrpOnChangeMask(Com_TxSigGrpOnChangeMaskIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxSigGrpOnChangeMaskPtrType) (NULL_PTR);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCallDeferredConfirmationNotification(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasDynamicInitialLength(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasIPduGroupInfoOfTxPduInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingConfirmationNotificationInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingErrorNotificationInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSigGrpEventFlag(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfCallDeferredConfirmationNotification(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfDynamicInitialLength(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfIPduGroupInfoOfTxPduInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfReportingConfirmationNotificationInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfReportingErrorNotificationInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfSigGrpEventFlag(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxGrpSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxInvalidationInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxProcessingPdus(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxSduLength(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxSigGrpInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxSigGrpOnChangeMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxTmpPduLength(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfWaitingForConfirmation(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasDynamicInitialLengthIdxOfTxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasDynamicInitialLengthUsedOfTxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvalidHndOfTxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxGrpSigInfoIdxOfTxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxGrpSigInfoUsedOfTxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxInvalidationInfoIdxOfTxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxInvalidationInfoUsedOfTxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInfoIdxOfTxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigInfoIdxOfTxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigInfoUsedOfTxAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxGrpSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasByteLengthOfTxGrpSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSerializerInfoIdxOfTxGrpSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSerializerInfoUsedOfTxGrpSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasStartByteInPduPositionOfTxGrpSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransferPropertyFilterInfoIdxOfTxGrpSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransferPropertyFilterInfoUsedOfTxGrpSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransmissionModeFilterInfoIdxOfTxGrpSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransmissionModeFilterInfoUsedOfTxGrpSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTriggeredOfTxGrpSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxAccessInfoIdxOfTxGrpSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInfoIdxOfTxGrpSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpInfoIdxOfTxGrpSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxTmpPduLengthIdxOfTxGrpSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxTmpPduLengthUsedOfTxGrpSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasWithoutRepOfTxGrpSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxInvalidationInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCancellationSupportOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasClrUbOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasComTimerInfoMDTTimerIdxOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasComTimerInfoMDTTimerUsedOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasExternalIdOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwTimeoutInfoIdxOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwTimeoutInfoUsedOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasIPduGroupInfoOfTxPduInfoIndEndIdxOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasIPduGroupInfoOfTxPduInfoIndStartIdxOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasIPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInitModeOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvalidHndOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMainFunctionTxStructIdxOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataLengthOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasPartitionsTxStructIdxOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRepetitionInfoIdxOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRepetitionInfoUsedOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingConfirmationNotificationIndEndIdxOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingConfirmationNotificationIndStartIdxOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingConfirmationNotificationIndUsedOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingErrorNotificationIndEndIdxOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingErrorNotificationIndStartIdxOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingErrorNotificationIndUsedOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingIPduTriggerTransmitCalloutIdxOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingIPduTriggerTransmitCalloutUsedOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingTxIPduCalloutIdxOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingTxIPduCalloutUsedOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSignalProcessingOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxAccessInfoDynSigIdxOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxAccessInfoDynSigUsedOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoIdxOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoUsedOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxMetaDataBufferInfoIdxOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxMetaDataBufferInfoUsedOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxModeFalseIdxOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxModeTrueIdxOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduFilterInfoIdxOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpInfoIndEndIdxOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpInfoIndStartIdxOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpInfoIndUsedOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxTOutInfoIdxOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxTOutInfoUsedOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxTpInfoIdxOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxTpInfoUsedOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTypeOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxProcessingPdus(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInfoIdxOfTxProcessingPdus(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSduLength(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasArrayAccessUsedOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvalidHndOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSigGroupOnChangeOffsetOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSigGroupOnChangeStartPositionOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSigGroupOnChangeWithoutRepOffsetOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSigGroupOnChangeWithoutRepStartPositionOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransferPropertyOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransmissionModeFilterInfoEndIdxOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransmissionModeFilterInfoStartIdxOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransmissionModeFilterInfoUsedOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoIdxOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoSigGrpInTxIPDUIdxOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoSigGrpInTxIPDUUsedOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoUbIdxAndMaskIdxOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoUbIdxAndMaskUsedOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoUsedOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxInvalidationInfoIndEndIdxOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxInvalidationInfoIndStartIdxOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxInvalidationInfoIndUsedOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInfoIdxOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpOnChangeMaskOnChangeEndIdxOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpOnChangeMaskOnChangeLengthOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpOnChangeMaskOnChangeStartIdxOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpOnChangeMaskOnChangeUsedOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpOnChangeMaskOnChangeWithoutRepEndIdxOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpOnChangeMaskOnChangeWithoutRepLengthOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpOnChangeMaskOnChangeWithoutRepStartIdxOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpOnChangeMaskOnChangeWithoutRepUsedOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpOnChangeMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasByteLengthOfTxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSerializerInfoIdxOfTxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSerializerInfoUsedOfTxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasStartByteInPduPositionOfTxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransferPropertyFilterInfoIdxOfTxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransferPropertyFilterInfoUsedOfTxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransmissionModeFilterInfoIdxOfTxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransmissionModeFilterInfoUsedOfTxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTriggeredOfTxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxAccessInfoIdxOfTxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoUbIdxAndMaskIdxOfTxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoUbIdxAndMaskUsedOfTxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInfoIdxOfTxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasWithoutRepOfTxSigInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxTmpPduLength(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasWaitingForConfirmation(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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

#define COM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComPCEsistsEnumInlineFunctions  Com Esists Enum Inline Functions (PRE_COMPILE)
  \brief  These inilne functions can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTRANSMITClrUbOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTRIGGER_TRANSMITClrUbOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNOT_USEDClrUbOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsCONFIRMATIONClrUbOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsDEFERREDSignalProcessingOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsIMMEDIATESignalProcessingOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNORMALTypeOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTPTypeOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsPENDINGTransferPropertyOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTRIGGEREDTransferPropertyOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTRIGGERED_WITHOUT_REPETITIONTransferPropertyOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTRIGGERED_ON_CHANGETransferPropertyOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTRIGGERED_ON_CHANGE_WITHOUT_REPETITIONTransferPropertyOfTxSigGrpInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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

#define COM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  ComPCIncrementInlineFunctions  Com Increment Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to increment VAR data with numerical nature.
  \{
*/ 
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTxSduLength(Com_TxSduLengthIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetTxSduLengthOfPCConfig()[(Index)]++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTxTmpPduLength(Com_TxTmpPduLengthIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
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
  \defgroup  ComPCDecrementInlineFunctions  Com Decrement Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to decrement VAR data with numerical nature.
  \{
*/ 
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTxSduLength(Com_TxSduLengthIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetTxSduLengthOfPCConfig()[(Index)]--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTxTmpPduLength(Com_TxTmpPduLengthIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
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
  \defgroup  ComPCAddInlineFunctions  Com Add Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to add VAR data with numerical nature.
  \{
*/ 
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTxSduLength(Com_TxSduLengthIterType Index, Com_TxSduLengthType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_SetTxSduLength(Index, (Com_GetTxSduLengthOfPCConfig()[(Index)] + Value));
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTxTmpPduLength(Com_TxTmpPduLengthIterType Index, Com_TxTmpPduLengthType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
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
  \defgroup  ComPCSubstractInlineFunctions  Com Substract Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to substract VAR data with numerical nature.
  \{
*/ 
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTxSduLength(Com_TxSduLengthIterType Index, Com_TxSduLengthType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_SetTxSduLength(Index, (Com_GetTxSduLengthOfPCConfig()[(Index)] - Value));
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTxTmpPduLength(Com_TxTmpPduLengthIterType Index, Com_TxTmpPduLengthType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
/** 
  \}
*/ 

#define COM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */





/* VCA Enable : VCA_COM_FUNCTION_NOT_USED_AND_NO_ANALYSIS_ENTRY */

#endif  /* COM_CFG_TRANSMISSIONPROCESSINGDATA_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cfg_TransmissionProcessingData.h
**********************************************************************************************************************/

