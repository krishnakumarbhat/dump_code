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
 *              File: Com_Cfg_RxSignalBufferData.h
 *   Generation Time: 2026-05-11 17:41:36
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

#if !defined (COM_CFG_RXSIGNALBUFFERDATA_H)
# define COM_CFG_RXSIGNALBUFFERDATA_H

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
COM_LOCAL_INLINE FUNC(Com_SizeOfRxBufferInfoType, COM_CODE) Com_GetSizeOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxDynSignalLengthType, COM_CODE) Com_GetSizeOfRxDynSignalLength(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxDynSignalTmpLengthForSignalGroupsType, COM_CODE) Com_GetSizeOfRxDynSignalTmpLengthForSignalGroups(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigArrayAccessSigGrpBufferType, COM_CODE) Com_GetSizeOfRxSigArrayAccessSigGrpBuffer(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferArrayBasedType, COM_CODE) Com_GetSizeOfRxSigBufferArrayBased(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferFloat32Type, COM_CODE) Com_GetSizeOfRxSigBufferFloat32(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferFloat64Type, COM_CODE) Com_GetSizeOfRxSigBufferFloat64(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSInt16Type, COM_CODE) Com_GetSizeOfRxSigBufferSInt16(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSInt32Type, COM_CODE) Com_GetSizeOfRxSigBufferSInt32(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSInt64Type, COM_CODE) Com_GetSizeOfRxSigBufferSInt64(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSInt8Type, COM_CODE) Com_GetSizeOfRxSigBufferSInt8(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSubValuesArrayBasedType, COM_CODE) Com_GetSizeOfRxSigBufferSubValuesArrayBased(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSubValuesFloat32Type, COM_CODE) Com_GetSizeOfRxSigBufferSubValuesFloat32(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSubValuesFloat64Type, COM_CODE) Com_GetSizeOfRxSigBufferSubValuesFloat64(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSubValuesSInt16Type, COM_CODE) Com_GetSizeOfRxSigBufferSubValuesSInt16(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSubValuesSInt32Type, COM_CODE) Com_GetSizeOfRxSigBufferSubValuesSInt32(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSubValuesSInt64Type, COM_CODE) Com_GetSizeOfRxSigBufferSubValuesSInt64(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSubValuesSInt8Type, COM_CODE) Com_GetSizeOfRxSigBufferSubValuesSInt8(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSubValuesSigGrpArrayAccessType, COM_CODE) Com_GetSizeOfRxSigBufferSubValuesSigGrpArrayAccess(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSubValuesUInt16Type, COM_CODE) Com_GetSizeOfRxSigBufferSubValuesUInt16(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSubValuesUInt32Type, COM_CODE) Com_GetSizeOfRxSigBufferSubValuesUInt32(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSubValuesUInt64Type, COM_CODE) Com_GetSizeOfRxSigBufferSubValuesUInt64(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSubValuesUInt8Type, COM_CODE) Com_GetSizeOfRxSigBufferSubValuesUInt8(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferUInt16Type, COM_CODE) Com_GetSizeOfRxSigBufferUInt16(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferUInt32Type, COM_CODE) Com_GetSizeOfRxSigBufferUInt32(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferUInt64Type, COM_CODE) Com_GetSizeOfRxSigBufferUInt64(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferUInt8Type, COM_CODE) Com_GetSizeOfRxSigBufferUInt8(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpRxSigBufferArrayBasedType, COM_CODE) Com_GetSizeOfTmpRxSigBufferArrayBased(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpRxSigBufferFloat32Type, COM_CODE) Com_GetSizeOfTmpRxSigBufferFloat32(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpRxSigBufferFloat64Type, COM_CODE) Com_GetSizeOfTmpRxSigBufferFloat64(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpRxSigBufferSInt16Type, COM_CODE) Com_GetSizeOfTmpRxSigBufferSInt16(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpRxSigBufferSInt32Type, COM_CODE) Com_GetSizeOfTmpRxSigBufferSInt32(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpRxSigBufferSInt64Type, COM_CODE) Com_GetSizeOfTmpRxSigBufferSInt64(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpRxSigBufferSInt8Type, COM_CODE) Com_GetSizeOfTmpRxSigBufferSInt8(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpRxSigBufferUInt16Type, COM_CODE) Com_GetSizeOfTmpRxSigBufferUInt16(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpRxSigBufferUInt32Type, COM_CODE) Com_GetSizeOfTmpRxSigBufferUInt32(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpRxSigBufferUInt64Type, COM_CODE) Com_GetSizeOfTmpRxSigBufferUInt64(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpRxSigBufferUInt8Type, COM_CODE) Com_GetSizeOfTmpRxSigBufferUInt8(void);
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
COM_LOCAL_INLINE FUNC(Com_InitValueEndIdxOfRxBufferInfoType, COM_CODE) Com_GetInitValueEndIdxOfRxBufferInfo(Com_RxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_InitValueLengthOfRxBufferInfoType, COM_CODE) Com_GetInitValueLengthOfRxBufferInfo(Com_RxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_InitValueStartIdxOfRxBufferInfoType, COM_CODE) Com_GetInitValueStartIdxOfRxBufferInfo(Com_RxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxDataTimeoutSubstitutionValueEndIdxOfRxBufferInfoType, COM_CODE) Com_GetRxDataTimeoutSubstitutionValueEndIdxOfRxBufferInfo(Com_RxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxDataTimeoutSubstitutionValueLengthOfRxBufferInfoType, COM_CODE) Com_GetRxDataTimeoutSubstitutionValueLengthOfRxBufferInfo(Com_RxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxDataTimeoutSubstitutionValueOfRxBufferInfoType, COM_CODE) Com_GetRxDataTimeoutSubstitutionValueOfRxBufferInfo(Com_RxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxDataTimeoutSubstitutionValueStartIdxOfRxBufferInfoType, COM_CODE) Com_GetRxDataTimeoutSubstitutionValueStartIdxOfRxBufferInfo(Com_RxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxDataTimeoutSubstitutionValueUsedOfRxBufferInfoType, COM_CODE) Com_IsRxDataTimeoutSubstitutionValueUsedOfRxBufferInfo(Com_RxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferEndIdxOfRxBufferInfoType, COM_CODE) Com_GetRxSigBufferEndIdxOfRxBufferInfo(Com_RxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferOfRxBufferInfoType, COM_CODE) Com_GetRxSigBufferOfRxBufferInfo(Com_RxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferStartIdxOfRxBufferInfoType, COM_CODE) Com_GetRxSigBufferStartIdxOfRxBufferInfo(Com_RxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpSigBufferEndIdxOfRxBufferInfoType, COM_CODE) Com_GetTmpSigBufferEndIdxOfRxBufferInfo(Com_RxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpSigBufferLengthOfRxBufferInfoType, COM_CODE) Com_GetTmpSigBufferLengthOfRxBufferInfo(Com_RxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpSigBufferOfRxBufferInfoType, COM_CODE) Com_GetTmpSigBufferOfRxBufferInfo(Com_RxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpSigBufferStartIdxOfRxBufferInfoType, COM_CODE) Com_GetTmpSigBufferStartIdxOfRxBufferInfo(Com_RxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxDynSignalLengthType, COM_CODE) Com_GetRxDynSignalLength(Com_RxDynSignalLengthIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxDynSignalTmpLengthForSignalGroupsType, COM_CODE) Com_GetRxDynSignalTmpLengthForSignalGroups(Com_RxDynSignalTmpLengthForSignalGroupsIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigArrayAccessSigGrpBufferType, COM_CODE) Com_GetRxSigArrayAccessSigGrpBuffer(Com_RxSigArrayAccessSigGrpBufferIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferArrayBasedType, COM_CODE) Com_GetRxSigBufferArrayBased(Com_RxSigBufferArrayBasedIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferFloat32Type, COM_CODE) Com_GetRxSigBufferFloat32(Com_RxSigBufferFloat32IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferFloat64Type, COM_CODE) Com_GetRxSigBufferFloat64(Com_RxSigBufferFloat64IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSInt16Type, COM_CODE) Com_GetRxSigBufferSInt16(Com_RxSigBufferSInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSInt32Type, COM_CODE) Com_GetRxSigBufferSInt32(Com_RxSigBufferSInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSInt64Type, COM_CODE) Com_GetRxSigBufferSInt64(Com_RxSigBufferSInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSInt8Type, COM_CODE) Com_GetRxSigBufferSInt8(Com_RxSigBufferSInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesArrayBasedType, COM_CODE) Com_GetRxSigBufferSubValuesArrayBased(Com_RxSigBufferSubValuesArrayBasedIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesFloat32Type, COM_CODE) Com_GetRxSigBufferSubValuesFloat32(Com_RxSigBufferSubValuesFloat32IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesFloat64Type, COM_CODE) Com_GetRxSigBufferSubValuesFloat64(Com_RxSigBufferSubValuesFloat64IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesSInt16Type, COM_CODE) Com_GetRxSigBufferSubValuesSInt16(Com_RxSigBufferSubValuesSInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesSInt32Type, COM_CODE) Com_GetRxSigBufferSubValuesSInt32(Com_RxSigBufferSubValuesSInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesSInt64Type, COM_CODE) Com_GetRxSigBufferSubValuesSInt64(Com_RxSigBufferSubValuesSInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesSInt8Type, COM_CODE) Com_GetRxSigBufferSubValuesSInt8(Com_RxSigBufferSubValuesSInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesSigGrpArrayAccessType, COM_CODE) Com_GetRxSigBufferSubValuesSigGrpArrayAccess(Com_RxSigBufferSubValuesSigGrpArrayAccessIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesUInt16Type, COM_CODE) Com_GetRxSigBufferSubValuesUInt16(Com_RxSigBufferSubValuesUInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesUInt32Type, COM_CODE) Com_GetRxSigBufferSubValuesUInt32(Com_RxSigBufferSubValuesUInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesUInt64Type, COM_CODE) Com_GetRxSigBufferSubValuesUInt64(Com_RxSigBufferSubValuesUInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesUInt8Type, COM_CODE) Com_GetRxSigBufferSubValuesUInt8(Com_RxSigBufferSubValuesUInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferUInt16Type, COM_CODE) Com_GetRxSigBufferUInt16(Com_RxSigBufferUInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferUInt32Type, COM_CODE) Com_GetRxSigBufferUInt32(Com_RxSigBufferUInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferUInt64Type, COM_CODE) Com_GetRxSigBufferUInt64(Com_RxSigBufferUInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferUInt8Type, COM_CODE) Com_GetRxSigBufferUInt8(Com_RxSigBufferUInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferArrayBasedType, COM_CODE) Com_GetTmpRxSigBufferArrayBased(Com_TmpRxSigBufferArrayBasedIterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferFloat32Type, COM_CODE) Com_GetTmpRxSigBufferFloat32(Com_TmpRxSigBufferFloat32IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferFloat64Type, COM_CODE) Com_GetTmpRxSigBufferFloat64(Com_TmpRxSigBufferFloat64IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferSInt16Type, COM_CODE) Com_GetTmpRxSigBufferSInt16(Com_TmpRxSigBufferSInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferSInt32Type, COM_CODE) Com_GetTmpRxSigBufferSInt32(Com_TmpRxSigBufferSInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferSInt64Type, COM_CODE) Com_GetTmpRxSigBufferSInt64(Com_TmpRxSigBufferSInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferSInt8Type, COM_CODE) Com_GetTmpRxSigBufferSInt8(Com_TmpRxSigBufferSInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferUInt16Type, COM_CODE) Com_GetTmpRxSigBufferUInt16(Com_TmpRxSigBufferUInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferUInt32Type, COM_CODE) Com_GetTmpRxSigBufferUInt32(Com_TmpRxSigBufferUInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferUInt64Type, COM_CODE) Com_GetTmpRxSigBufferUInt64(Com_TmpRxSigBufferUInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferUInt8Type, COM_CODE) Com_GetTmpRxSigBufferUInt8(Com_TmpRxSigBufferUInt8IterType Index);
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
COM_LOCAL_INLINE FUNC(Com_InitValueOfRxBufferInfoType, COM_CODE) Com_GetInitValueOfRxBufferInfo(Com_RxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_InitValueUsedOfRxBufferInfoType, COM_CODE) Com_IsInitValueUsedOfRxBufferInfo(Com_RxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferLengthOfRxBufferInfoType, COM_CODE) Com_GetRxSigBufferLengthOfRxBufferInfo(Com_RxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpSigBufferUsedOfRxBufferInfoType, COM_CODE) Com_IsTmpSigBufferUsedOfRxBufferInfo(Com_RxBufferInfoIterType Index);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxDynSignalLength(Com_RxDynSignalLengthIterType Index, Com_RxDynSignalLengthType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxDynSignalTmpLengthForSignalGroups(Com_RxDynSignalTmpLengthForSignalGroupsIterType Index, Com_RxDynSignalTmpLengthForSignalGroupsType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxSigArrayAccessSigGrpBuffer(Com_RxSigArrayAccessSigGrpBufferIterType Index, Com_RxSigArrayAccessSigGrpBufferType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxSigBufferArrayBased(Com_RxSigBufferArrayBasedIterType Index, Com_RxSigBufferArrayBasedType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxSigBufferFloat32(Com_RxSigBufferFloat32IterType Index, Com_RxSigBufferFloat32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxSigBufferFloat64(Com_RxSigBufferFloat64IterType Index, Com_RxSigBufferFloat64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxSigBufferSInt16(Com_RxSigBufferSInt16IterType Index, Com_RxSigBufferSInt16Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxSigBufferSInt32(Com_RxSigBufferSInt32IterType Index, Com_RxSigBufferSInt32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxSigBufferSInt64(Com_RxSigBufferSInt64IterType Index, Com_RxSigBufferSInt64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxSigBufferSInt8(Com_RxSigBufferSInt8IterType Index, Com_RxSigBufferSInt8Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxSigBufferUInt16(Com_RxSigBufferUInt16IterType Index, Com_RxSigBufferUInt16Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxSigBufferUInt32(Com_RxSigBufferUInt32IterType Index, Com_RxSigBufferUInt32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxSigBufferUInt64(Com_RxSigBufferUInt64IterType Index, Com_RxSigBufferUInt64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxSigBufferUInt8(Com_RxSigBufferUInt8IterType Index, Com_RxSigBufferUInt8Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpRxSigBufferArrayBased(Com_TmpRxSigBufferArrayBasedIterType Index, Com_TmpRxSigBufferArrayBasedType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpRxSigBufferFloat32(Com_TmpRxSigBufferFloat32IterType Index, Com_TmpRxSigBufferFloat32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpRxSigBufferFloat64(Com_TmpRxSigBufferFloat64IterType Index, Com_TmpRxSigBufferFloat64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpRxSigBufferSInt16(Com_TmpRxSigBufferSInt16IterType Index, Com_TmpRxSigBufferSInt16Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpRxSigBufferSInt32(Com_TmpRxSigBufferSInt32IterType Index, Com_TmpRxSigBufferSInt32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpRxSigBufferSInt64(Com_TmpRxSigBufferSInt64IterType Index, Com_TmpRxSigBufferSInt64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpRxSigBufferSInt8(Com_TmpRxSigBufferSInt8IterType Index, Com_TmpRxSigBufferSInt8Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpRxSigBufferUInt16(Com_TmpRxSigBufferUInt16IterType Index, Com_TmpRxSigBufferUInt16Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpRxSigBufferUInt32(Com_TmpRxSigBufferUInt32IterType Index, Com_TmpRxSigBufferUInt32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpRxSigBufferUInt64(Com_TmpRxSigBufferUInt64IterType Index, Com_TmpRxSigBufferUInt64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpRxSigBufferUInt8(Com_TmpRxSigBufferUInt8IterType Index, Com_TmpRxSigBufferUInt8Type Value);
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
COM_LOCAL_INLINE FUNC(Com_RxSigArrayAccessSigGrpBufferPtrType, COM_CODE) Com_GetAddrRxSigArrayAccessSigGrpBuffer(Com_RxSigArrayAccessSigGrpBufferIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferArrayBasedPtrType, COM_CODE) Com_GetAddrRxSigBufferArrayBased(Com_RxSigBufferArrayBasedIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferFloat32PtrType, COM_CODE) Com_GetAddrRxSigBufferFloat32(Com_RxSigBufferFloat32IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferFloat64PtrType, COM_CODE) Com_GetAddrRxSigBufferFloat64(Com_RxSigBufferFloat64IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSInt16PtrType, COM_CODE) Com_GetAddrRxSigBufferSInt16(Com_RxSigBufferSInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSInt32PtrType, COM_CODE) Com_GetAddrRxSigBufferSInt32(Com_RxSigBufferSInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSInt64PtrType, COM_CODE) Com_GetAddrRxSigBufferSInt64(Com_RxSigBufferSInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSInt8PtrType, COM_CODE) Com_GetAddrRxSigBufferSInt8(Com_RxSigBufferSInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesArrayBasedPtrType, COM_CODE) Com_GetAddrRxSigBufferSubValuesArrayBased(Com_RxSigBufferSubValuesArrayBasedIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesFloat32PtrType, COM_CODE) Com_GetAddrRxSigBufferSubValuesFloat32(Com_RxSigBufferSubValuesFloat32IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesFloat64PtrType, COM_CODE) Com_GetAddrRxSigBufferSubValuesFloat64(Com_RxSigBufferSubValuesFloat64IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesSInt16PtrType, COM_CODE) Com_GetAddrRxSigBufferSubValuesSInt16(Com_RxSigBufferSubValuesSInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesSInt32PtrType, COM_CODE) Com_GetAddrRxSigBufferSubValuesSInt32(Com_RxSigBufferSubValuesSInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesSInt64PtrType, COM_CODE) Com_GetAddrRxSigBufferSubValuesSInt64(Com_RxSigBufferSubValuesSInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesSInt8PtrType, COM_CODE) Com_GetAddrRxSigBufferSubValuesSInt8(Com_RxSigBufferSubValuesSInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesSigGrpArrayAccessPtrType, COM_CODE) Com_GetAddrRxSigBufferSubValuesSigGrpArrayAccess(Com_RxSigBufferSubValuesSigGrpArrayAccessIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesUInt16PtrType, COM_CODE) Com_GetAddrRxSigBufferSubValuesUInt16(Com_RxSigBufferSubValuesUInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesUInt32PtrType, COM_CODE) Com_GetAddrRxSigBufferSubValuesUInt32(Com_RxSigBufferSubValuesUInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesUInt64PtrType, COM_CODE) Com_GetAddrRxSigBufferSubValuesUInt64(Com_RxSigBufferSubValuesUInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesUInt8PtrType, COM_CODE) Com_GetAddrRxSigBufferSubValuesUInt8(Com_RxSigBufferSubValuesUInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferUInt16PtrType, COM_CODE) Com_GetAddrRxSigBufferUInt16(Com_RxSigBufferUInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferUInt32PtrType, COM_CODE) Com_GetAddrRxSigBufferUInt32(Com_RxSigBufferUInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferUInt64PtrType, COM_CODE) Com_GetAddrRxSigBufferUInt64(Com_RxSigBufferUInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_RxSigBufferUInt8PtrType, COM_CODE) Com_GetAddrRxSigBufferUInt8(Com_RxSigBufferUInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferArrayBasedPtrType, COM_CODE) Com_GetAddrTmpRxSigBufferArrayBased(Com_TmpRxSigBufferArrayBasedIterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferFloat32PtrType, COM_CODE) Com_GetAddrTmpRxSigBufferFloat32(Com_TmpRxSigBufferFloat32IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferFloat64PtrType, COM_CODE) Com_GetAddrTmpRxSigBufferFloat64(Com_TmpRxSigBufferFloat64IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferSInt16PtrType, COM_CODE) Com_GetAddrTmpRxSigBufferSInt16(Com_TmpRxSigBufferSInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferSInt32PtrType, COM_CODE) Com_GetAddrTmpRxSigBufferSInt32(Com_TmpRxSigBufferSInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferSInt64PtrType, COM_CODE) Com_GetAddrTmpRxSigBufferSInt64(Com_TmpRxSigBufferSInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferSInt8PtrType, COM_CODE) Com_GetAddrTmpRxSigBufferSInt8(Com_TmpRxSigBufferSInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferUInt16PtrType, COM_CODE) Com_GetAddrTmpRxSigBufferUInt16(Com_TmpRxSigBufferUInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferUInt32PtrType, COM_CODE) Com_GetAddrTmpRxSigBufferUInt32(Com_TmpRxSigBufferUInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferUInt64PtrType, COM_CODE) Com_GetAddrTmpRxSigBufferUInt64(Com_TmpRxSigBufferUInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferUInt8PtrType, COM_CODE) Com_GetAddrTmpRxSigBufferUInt8(Com_TmpRxSigBufferUInt8IterType Index);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInitValueEndIdxOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInitValueLengthOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInitValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInitValueStartIdxOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInitValueUsedOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDataTimeoutSubstitutionValueEndIdxOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDataTimeoutSubstitutionValueLengthOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDataTimeoutSubstitutionValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDataTimeoutSubstitutionValueStartIdxOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDataTimeoutSubstitutionValueUsedOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferEndIdxOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferLengthOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferStartIdxOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpSigBufferEndIdxOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpSigBufferLengthOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpSigBufferOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpSigBufferStartIdxOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpSigBufferUsedOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDynSignalLength(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDynSignalTmpLengthForSignalGroups(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigArrayAccessSigGrpBuffer(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferArrayBased(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferFloat32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferFloat64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSubValuesArrayBased(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSubValuesFloat32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSubValuesFloat64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSubValuesSInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSubValuesSInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSubValuesSInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSubValuesSInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSubValuesSigGrpArrayAccess(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSubValuesUInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSubValuesUInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSubValuesUInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSubValuesUInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferUInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferUInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferUInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferUInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxDynSignalLength(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxDynSignalTmpLengthForSignalGroups(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigArrayAccessSigGrpBuffer(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferArrayBased(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferFloat32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferFloat64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSubValuesArrayBased(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSubValuesFloat32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSubValuesFloat64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSubValuesSInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSubValuesSInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSubValuesSInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSubValuesSInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSubValuesSigGrpArrayAccess(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSubValuesUInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSubValuesUInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSubValuesUInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSubValuesUInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferUInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferUInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferUInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferUInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpRxSigBufferArrayBased(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpRxSigBufferFloat32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpRxSigBufferFloat64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpRxSigBufferSInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpRxSigBufferSInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpRxSigBufferSInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpRxSigBufferSInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpRxSigBufferUInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpRxSigBufferUInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpRxSigBufferUInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpRxSigBufferUInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpRxSigBufferArrayBased(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpRxSigBufferFloat32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpRxSigBufferFloat64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpRxSigBufferSInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpRxSigBufferSInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpRxSigBufferSInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpRxSigBufferSInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpRxSigBufferUInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpRxSigBufferUInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpRxSigBufferUInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpRxSigBufferUInt8(void);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesUInt8InitValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesUInt16InitValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesUInt32InitValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesUInt64InitValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesSInt8InitValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesSInt16InitValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesSInt32InitValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesSInt64InitValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesFloat32InitValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesFloat64InitValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesArrayBasedInitValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesSigGrpArrayAccessInitValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNoInitValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesUInt8RxDataTimeoutSubstitutionValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesUInt16RxDataTimeoutSubstitutionValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesUInt32RxDataTimeoutSubstitutionValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesUInt64RxDataTimeoutSubstitutionValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesSInt8RxDataTimeoutSubstitutionValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesSInt16RxDataTimeoutSubstitutionValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesSInt32RxDataTimeoutSubstitutionValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesSInt64RxDataTimeoutSubstitutionValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesFloat32RxDataTimeoutSubstitutionValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesFloat64RxDataTimeoutSubstitutionValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesArrayBasedRxDataTimeoutSubstitutionValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesSigGrpArrayAccessRxDataTimeoutSubstitutionValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNoRxDataTimeoutSubstitutionValueOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferUInt8RxSigBufferOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferUInt16RxSigBufferOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferUInt32RxSigBufferOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferUInt64RxSigBufferOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSInt8RxSigBufferOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSInt16RxSigBufferOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSInt32RxSigBufferOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSInt64RxSigBufferOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferFloat32RxSigBufferOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferFloat64RxSigBufferOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferArrayBasedRxSigBufferOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigArrayAccessSigGrpBufferRxSigBufferOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpRxSigBufferUInt8TmpSigBufferOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpRxSigBufferUInt16TmpSigBufferOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpRxSigBufferUInt32TmpSigBufferOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpRxSigBufferUInt64TmpSigBufferOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpRxSigBufferSInt8TmpSigBufferOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpRxSigBufferSInt16TmpSigBufferOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpRxSigBufferSInt32TmpSigBufferOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpRxSigBufferSInt64TmpSigBufferOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpRxSigBufferFloat32TmpSigBufferOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpRxSigBufferFloat64TmpSigBufferOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpRxSigBufferArrayBasedTmpSigBufferOfRxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNoTmpSigBufferOfRxBufferInfo(void);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxDynSignalLength(Com_RxDynSignalLengthIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxDynSignalTmpLengthForSignalGroups(Com_RxDynSignalTmpLengthForSignalGroupsIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxSigArrayAccessSigGrpBuffer(Com_RxSigArrayAccessSigGrpBufferIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxSigBufferArrayBased(Com_RxSigBufferArrayBasedIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxSigBufferSInt16(Com_RxSigBufferSInt16IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxSigBufferSInt32(Com_RxSigBufferSInt32IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxSigBufferSInt64(Com_RxSigBufferSInt64IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxSigBufferSInt8(Com_RxSigBufferSInt8IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxSigBufferUInt16(Com_RxSigBufferUInt16IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxSigBufferUInt32(Com_RxSigBufferUInt32IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxSigBufferUInt64(Com_RxSigBufferUInt64IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxSigBufferUInt8(Com_RxSigBufferUInt8IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpRxSigBufferArrayBased(Com_TmpRxSigBufferArrayBasedIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpRxSigBufferSInt16(Com_TmpRxSigBufferSInt16IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpRxSigBufferSInt32(Com_TmpRxSigBufferSInt32IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpRxSigBufferSInt64(Com_TmpRxSigBufferSInt64IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpRxSigBufferSInt8(Com_TmpRxSigBufferSInt8IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpRxSigBufferUInt16(Com_TmpRxSigBufferUInt16IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpRxSigBufferUInt32(Com_TmpRxSigBufferUInt32IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpRxSigBufferUInt64(Com_TmpRxSigBufferUInt64IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpRxSigBufferUInt8(Com_TmpRxSigBufferUInt8IterType Index);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxDynSignalLength(Com_RxDynSignalLengthIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxDynSignalTmpLengthForSignalGroups(Com_RxDynSignalTmpLengthForSignalGroupsIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxSigArrayAccessSigGrpBuffer(Com_RxSigArrayAccessSigGrpBufferIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxSigBufferArrayBased(Com_RxSigBufferArrayBasedIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxSigBufferSInt16(Com_RxSigBufferSInt16IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxSigBufferSInt32(Com_RxSigBufferSInt32IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxSigBufferSInt64(Com_RxSigBufferSInt64IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxSigBufferSInt8(Com_RxSigBufferSInt8IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxSigBufferUInt16(Com_RxSigBufferUInt16IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxSigBufferUInt32(Com_RxSigBufferUInt32IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxSigBufferUInt64(Com_RxSigBufferUInt64IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxSigBufferUInt8(Com_RxSigBufferUInt8IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpRxSigBufferArrayBased(Com_TmpRxSigBufferArrayBasedIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpRxSigBufferSInt16(Com_TmpRxSigBufferSInt16IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpRxSigBufferSInt32(Com_TmpRxSigBufferSInt32IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpRxSigBufferSInt64(Com_TmpRxSigBufferSInt64IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpRxSigBufferSInt8(Com_TmpRxSigBufferSInt8IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpRxSigBufferUInt16(Com_TmpRxSigBufferUInt16IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpRxSigBufferUInt32(Com_TmpRxSigBufferUInt32IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpRxSigBufferUInt64(Com_TmpRxSigBufferUInt64IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpRxSigBufferUInt8(Com_TmpRxSigBufferUInt8IterType Index);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxDynSignalLength(Com_RxDynSignalLengthIterType Index, Com_RxDynSignalLengthType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxDynSignalTmpLengthForSignalGroups(Com_RxDynSignalTmpLengthForSignalGroupsIterType Index, Com_RxDynSignalTmpLengthForSignalGroupsType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxSigArrayAccessSigGrpBuffer(Com_RxSigArrayAccessSigGrpBufferIterType Index, Com_RxSigArrayAccessSigGrpBufferType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxSigBufferArrayBased(Com_RxSigBufferArrayBasedIterType Index, Com_RxSigBufferArrayBasedType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxSigBufferSInt16(Com_RxSigBufferSInt16IterType Index, Com_RxSigBufferSInt16Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxSigBufferSInt32(Com_RxSigBufferSInt32IterType Index, Com_RxSigBufferSInt32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxSigBufferSInt64(Com_RxSigBufferSInt64IterType Index, Com_RxSigBufferSInt64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxSigBufferSInt8(Com_RxSigBufferSInt8IterType Index, Com_RxSigBufferSInt8Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxSigBufferUInt16(Com_RxSigBufferUInt16IterType Index, Com_RxSigBufferUInt16Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxSigBufferUInt32(Com_RxSigBufferUInt32IterType Index, Com_RxSigBufferUInt32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxSigBufferUInt64(Com_RxSigBufferUInt64IterType Index, Com_RxSigBufferUInt64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxSigBufferUInt8(Com_RxSigBufferUInt8IterType Index, Com_RxSigBufferUInt8Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpRxSigBufferArrayBased(Com_TmpRxSigBufferArrayBasedIterType Index, Com_TmpRxSigBufferArrayBasedType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpRxSigBufferSInt16(Com_TmpRxSigBufferSInt16IterType Index, Com_TmpRxSigBufferSInt16Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpRxSigBufferSInt32(Com_TmpRxSigBufferSInt32IterType Index, Com_TmpRxSigBufferSInt32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpRxSigBufferSInt64(Com_TmpRxSigBufferSInt64IterType Index, Com_TmpRxSigBufferSInt64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpRxSigBufferSInt8(Com_TmpRxSigBufferSInt8IterType Index, Com_TmpRxSigBufferSInt8Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpRxSigBufferUInt16(Com_TmpRxSigBufferUInt16IterType Index, Com_TmpRxSigBufferUInt16Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpRxSigBufferUInt32(Com_TmpRxSigBufferUInt32IterType Index, Com_TmpRxSigBufferUInt32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpRxSigBufferUInt64(Com_TmpRxSigBufferUInt64IterType Index, Com_TmpRxSigBufferUInt64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpRxSigBufferUInt8(Com_TmpRxSigBufferUInt8IterType Index, Com_TmpRxSigBufferUInt8Type Value);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxDynSignalLength(Com_RxDynSignalLengthIterType Index, Com_RxDynSignalLengthType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxDynSignalTmpLengthForSignalGroups(Com_RxDynSignalTmpLengthForSignalGroupsIterType Index, Com_RxDynSignalTmpLengthForSignalGroupsType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxSigArrayAccessSigGrpBuffer(Com_RxSigArrayAccessSigGrpBufferIterType Index, Com_RxSigArrayAccessSigGrpBufferType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxSigBufferArrayBased(Com_RxSigBufferArrayBasedIterType Index, Com_RxSigBufferArrayBasedType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxSigBufferSInt16(Com_RxSigBufferSInt16IterType Index, Com_RxSigBufferSInt16Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxSigBufferSInt32(Com_RxSigBufferSInt32IterType Index, Com_RxSigBufferSInt32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxSigBufferSInt64(Com_RxSigBufferSInt64IterType Index, Com_RxSigBufferSInt64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxSigBufferSInt8(Com_RxSigBufferSInt8IterType Index, Com_RxSigBufferSInt8Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxSigBufferUInt16(Com_RxSigBufferUInt16IterType Index, Com_RxSigBufferUInt16Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxSigBufferUInt32(Com_RxSigBufferUInt32IterType Index, Com_RxSigBufferUInt32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxSigBufferUInt64(Com_RxSigBufferUInt64IterType Index, Com_RxSigBufferUInt64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxSigBufferUInt8(Com_RxSigBufferUInt8IterType Index, Com_RxSigBufferUInt8Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpRxSigBufferArrayBased(Com_TmpRxSigBufferArrayBasedIterType Index, Com_TmpRxSigBufferArrayBasedType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpRxSigBufferSInt16(Com_TmpRxSigBufferSInt16IterType Index, Com_TmpRxSigBufferSInt16Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpRxSigBufferSInt32(Com_TmpRxSigBufferSInt32IterType Index, Com_TmpRxSigBufferSInt32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpRxSigBufferSInt64(Com_TmpRxSigBufferSInt64IterType Index, Com_TmpRxSigBufferSInt64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpRxSigBufferSInt8(Com_TmpRxSigBufferSInt8IterType Index, Com_TmpRxSigBufferSInt8Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpRxSigBufferUInt16(Com_TmpRxSigBufferUInt16IterType Index, Com_TmpRxSigBufferUInt16Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpRxSigBufferUInt32(Com_TmpRxSigBufferUInt32IterType Index, Com_TmpRxSigBufferUInt32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpRxSigBufferUInt64(Com_TmpRxSigBufferUInt64IterType Index, Com_TmpRxSigBufferUInt64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpRxSigBufferUInt8(Com_TmpRxSigBufferUInt8IterType Index, Com_TmpRxSigBufferUInt8Type Value);
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
COM_LOCAL_INLINE FUNC(Com_SizeOfRxBufferInfoType, COM_CODE) Com_GetSizeOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxBufferInfoType) Com_GetSizeOfRxBufferInfoOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxDynSignalLengthType, COM_CODE) Com_GetSizeOfRxDynSignalLength(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxDynSignalLengthType) Com_GetSizeOfRxDynSignalLengthOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxDynSignalTmpLengthForSignalGroupsType, COM_CODE) Com_GetSizeOfRxDynSignalTmpLengthForSignalGroups(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxDynSignalTmpLengthForSignalGroupsType) Com_GetSizeOfRxDynSignalTmpLengthForSignalGroupsOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigArrayAccessSigGrpBufferType, COM_CODE) Com_GetSizeOfRxSigArrayAccessSigGrpBuffer(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigArrayAccessSigGrpBufferType) Com_GetSizeOfRxSigArrayAccessSigGrpBufferOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferArrayBasedType, COM_CODE) Com_GetSizeOfRxSigBufferArrayBased(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigBufferArrayBasedType) Com_GetSizeOfRxSigBufferArrayBasedOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferFloat32Type, COM_CODE) Com_GetSizeOfRxSigBufferFloat32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigBufferFloat32Type) Com_GetSizeOfRxSigBufferFloat32OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferFloat64Type, COM_CODE) Com_GetSizeOfRxSigBufferFloat64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigBufferFloat64Type) Com_GetSizeOfRxSigBufferFloat64OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSInt16Type, COM_CODE) Com_GetSizeOfRxSigBufferSInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigBufferSInt16Type) Com_GetSizeOfRxSigBufferSInt16OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSInt32Type, COM_CODE) Com_GetSizeOfRxSigBufferSInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigBufferSInt32Type) Com_GetSizeOfRxSigBufferSInt32OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSInt64Type, COM_CODE) Com_GetSizeOfRxSigBufferSInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigBufferSInt64Type) Com_GetSizeOfRxSigBufferSInt64OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSInt8Type, COM_CODE) Com_GetSizeOfRxSigBufferSInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigBufferSInt8Type) Com_GetSizeOfRxSigBufferSInt8OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSubValuesArrayBasedType, COM_CODE) Com_GetSizeOfRxSigBufferSubValuesArrayBased(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigBufferSubValuesArrayBasedType) Com_GetSizeOfRxSigBufferSubValuesArrayBasedOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSubValuesFloat32Type, COM_CODE) Com_GetSizeOfRxSigBufferSubValuesFloat32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigBufferSubValuesFloat32Type) Com_GetSizeOfRxSigBufferSubValuesFloat32OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSubValuesFloat64Type, COM_CODE) Com_GetSizeOfRxSigBufferSubValuesFloat64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigBufferSubValuesFloat64Type) Com_GetSizeOfRxSigBufferSubValuesFloat64OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSubValuesSInt16Type, COM_CODE) Com_GetSizeOfRxSigBufferSubValuesSInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigBufferSubValuesSInt16Type) Com_GetSizeOfRxSigBufferSubValuesSInt16OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSubValuesSInt32Type, COM_CODE) Com_GetSizeOfRxSigBufferSubValuesSInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigBufferSubValuesSInt32Type) Com_GetSizeOfRxSigBufferSubValuesSInt32OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSubValuesSInt64Type, COM_CODE) Com_GetSizeOfRxSigBufferSubValuesSInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigBufferSubValuesSInt64Type) Com_GetSizeOfRxSigBufferSubValuesSInt64OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSubValuesSInt8Type, COM_CODE) Com_GetSizeOfRxSigBufferSubValuesSInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigBufferSubValuesSInt8Type) Com_GetSizeOfRxSigBufferSubValuesSInt8OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSubValuesSigGrpArrayAccessType, COM_CODE) Com_GetSizeOfRxSigBufferSubValuesSigGrpArrayAccess(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigBufferSubValuesSigGrpArrayAccessType) Com_GetSizeOfRxSigBufferSubValuesSigGrpArrayAccessOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSubValuesUInt16Type, COM_CODE) Com_GetSizeOfRxSigBufferSubValuesUInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigBufferSubValuesUInt16Type) Com_GetSizeOfRxSigBufferSubValuesUInt16OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSubValuesUInt32Type, COM_CODE) Com_GetSizeOfRxSigBufferSubValuesUInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigBufferSubValuesUInt32Type) Com_GetSizeOfRxSigBufferSubValuesUInt32OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSubValuesUInt64Type, COM_CODE) Com_GetSizeOfRxSigBufferSubValuesUInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigBufferSubValuesUInt64Type) Com_GetSizeOfRxSigBufferSubValuesUInt64OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferSubValuesUInt8Type, COM_CODE) Com_GetSizeOfRxSigBufferSubValuesUInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigBufferSubValuesUInt8Type) Com_GetSizeOfRxSigBufferSubValuesUInt8OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferUInt16Type, COM_CODE) Com_GetSizeOfRxSigBufferUInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigBufferUInt16Type) Com_GetSizeOfRxSigBufferUInt16OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferUInt32Type, COM_CODE) Com_GetSizeOfRxSigBufferUInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigBufferUInt32Type) Com_GetSizeOfRxSigBufferUInt32OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferUInt64Type, COM_CODE) Com_GetSizeOfRxSigBufferUInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigBufferUInt64Type) Com_GetSizeOfRxSigBufferUInt64OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxSigBufferUInt8Type, COM_CODE) Com_GetSizeOfRxSigBufferUInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxSigBufferUInt8Type) Com_GetSizeOfRxSigBufferUInt8OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpRxSigBufferArrayBasedType, COM_CODE) Com_GetSizeOfTmpRxSigBufferArrayBased(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTmpRxSigBufferArrayBasedType) Com_GetSizeOfTmpRxSigBufferArrayBasedOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpRxSigBufferFloat32Type, COM_CODE) Com_GetSizeOfTmpRxSigBufferFloat32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTmpRxSigBufferFloat32Type) Com_GetSizeOfTmpRxSigBufferFloat32OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpRxSigBufferFloat64Type, COM_CODE) Com_GetSizeOfTmpRxSigBufferFloat64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTmpRxSigBufferFloat64Type) Com_GetSizeOfTmpRxSigBufferFloat64OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpRxSigBufferSInt16Type, COM_CODE) Com_GetSizeOfTmpRxSigBufferSInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTmpRxSigBufferSInt16Type) Com_GetSizeOfTmpRxSigBufferSInt16OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpRxSigBufferSInt32Type, COM_CODE) Com_GetSizeOfTmpRxSigBufferSInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTmpRxSigBufferSInt32Type) Com_GetSizeOfTmpRxSigBufferSInt32OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpRxSigBufferSInt64Type, COM_CODE) Com_GetSizeOfTmpRxSigBufferSInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTmpRxSigBufferSInt64Type) Com_GetSizeOfTmpRxSigBufferSInt64OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpRxSigBufferSInt8Type, COM_CODE) Com_GetSizeOfTmpRxSigBufferSInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTmpRxSigBufferSInt8Type) Com_GetSizeOfTmpRxSigBufferSInt8OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpRxSigBufferUInt16Type, COM_CODE) Com_GetSizeOfTmpRxSigBufferUInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTmpRxSigBufferUInt16Type) Com_GetSizeOfTmpRxSigBufferUInt16OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpRxSigBufferUInt32Type, COM_CODE) Com_GetSizeOfTmpRxSigBufferUInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTmpRxSigBufferUInt32Type) Com_GetSizeOfTmpRxSigBufferUInt32OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpRxSigBufferUInt64Type, COM_CODE) Com_GetSizeOfTmpRxSigBufferUInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTmpRxSigBufferUInt64Type) Com_GetSizeOfTmpRxSigBufferUInt64OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpRxSigBufferUInt8Type, COM_CODE) Com_GetSizeOfTmpRxSigBufferUInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTmpRxSigBufferUInt8Type) Com_GetSizeOfTmpRxSigBufferUInt8OfPCConfig();
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
COM_LOCAL_INLINE FUNC(Com_InitValueEndIdxOfRxBufferInfoType, COM_CODE) Com_GetInitValueEndIdxOfRxBufferInfo(Com_RxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InitValueEndIdxOfRxBufferInfoType) (Com_GetRxBufferInfoOfPCConfig()[(Index)].InitValueEndIdxOfRxBufferInfo);
}
COM_LOCAL_INLINE FUNC(Com_InitValueLengthOfRxBufferInfoType, COM_CODE) Com_GetInitValueLengthOfRxBufferInfo(Com_RxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InitValueLengthOfRxBufferInfoType) (Com_GetRxBufferInfoOfPCConfig()[(Index)].InitValueLengthOfRxBufferInfo);
}
COM_LOCAL_INLINE FUNC(Com_InitValueStartIdxOfRxBufferInfoType, COM_CODE) Com_GetInitValueStartIdxOfRxBufferInfo(Com_RxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InitValueStartIdxOfRxBufferInfoType) (Com_GetRxBufferInfoOfPCConfig()[(Index)].InitValueStartIdxOfRxBufferInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxDataTimeoutSubstitutionValueEndIdxOfRxBufferInfoType, COM_CODE) Com_GetRxDataTimeoutSubstitutionValueEndIdxOfRxBufferInfo(Com_RxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxDataTimeoutSubstitutionValueEndIdxOfRxBufferInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_RxDataTimeoutSubstitutionValueLengthOfRxBufferInfoType, COM_CODE) Com_GetRxDataTimeoutSubstitutionValueLengthOfRxBufferInfo(Com_RxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxDataTimeoutSubstitutionValueLengthOfRxBufferInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_RxDataTimeoutSubstitutionValueOfRxBufferInfoType, COM_CODE) Com_GetRxDataTimeoutSubstitutionValueOfRxBufferInfo(Com_RxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxDataTimeoutSubstitutionValueOfRxBufferInfoType) (COM_NO_RXDATATIMEOUTSUBSTITUTIONVALUEOFRXBUFFERINFO);
}
COM_LOCAL_INLINE FUNC(Com_RxDataTimeoutSubstitutionValueStartIdxOfRxBufferInfoType, COM_CODE) Com_GetRxDataTimeoutSubstitutionValueStartIdxOfRxBufferInfo(Com_RxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxDataTimeoutSubstitutionValueStartIdxOfRxBufferInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_RxDataTimeoutSubstitutionValueUsedOfRxBufferInfoType, COM_CODE) Com_IsRxDataTimeoutSubstitutionValueUsedOfRxBufferInfo(Com_RxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxDataTimeoutSubstitutionValueUsedOfRxBufferInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferEndIdxOfRxBufferInfoType, COM_CODE) Com_GetRxSigBufferEndIdxOfRxBufferInfo(Com_RxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferEndIdxOfRxBufferInfoType) (Com_GetRxBufferInfoOfPCConfig()[(Index)].RxSigBufferEndIdxOfRxBufferInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferOfRxBufferInfoType, COM_CODE) Com_GetRxSigBufferOfRxBufferInfo(Com_RxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferOfRxBufferInfoType) (Com_GetRxBufferInfoOfPCConfig()[(Index)].RxSigBufferOfRxBufferInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferStartIdxOfRxBufferInfoType, COM_CODE) Com_GetRxSigBufferStartIdxOfRxBufferInfo(Com_RxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferStartIdxOfRxBufferInfoType) (Com_GetRxBufferInfoOfPCConfig()[(Index)].RxSigBufferStartIdxOfRxBufferInfo);
}
COM_LOCAL_INLINE FUNC(Com_TmpSigBufferEndIdxOfRxBufferInfoType, COM_CODE) Com_GetTmpSigBufferEndIdxOfRxBufferInfo(Com_RxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpSigBufferEndIdxOfRxBufferInfoType) (Com_GetRxBufferInfoOfPCConfig()[(Index)].TmpSigBufferEndIdxOfRxBufferInfo);
}
COM_LOCAL_INLINE FUNC(Com_TmpSigBufferLengthOfRxBufferInfoType, COM_CODE) Com_GetTmpSigBufferLengthOfRxBufferInfo(Com_RxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpSigBufferLengthOfRxBufferInfoType) (Com_GetRxBufferInfoOfPCConfig()[(Index)].TmpSigBufferLengthOfRxBufferInfo);
}
COM_LOCAL_INLINE FUNC(Com_TmpSigBufferOfRxBufferInfoType, COM_CODE) Com_GetTmpSigBufferOfRxBufferInfo(Com_RxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpSigBufferOfRxBufferInfoType) (Com_GetRxBufferInfoOfPCConfig()[(Index)].TmpSigBufferOfRxBufferInfo);
}
COM_LOCAL_INLINE FUNC(Com_TmpSigBufferStartIdxOfRxBufferInfoType, COM_CODE) Com_GetTmpSigBufferStartIdxOfRxBufferInfo(Com_RxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpSigBufferStartIdxOfRxBufferInfoType) (Com_GetRxBufferInfoOfPCConfig()[(Index)].TmpSigBufferStartIdxOfRxBufferInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxDynSignalLengthType, COM_CODE) Com_GetRxDynSignalLength(Com_RxDynSignalLengthIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxDynSignalLengthType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_RxDynSignalTmpLengthForSignalGroupsType, COM_CODE) Com_GetRxDynSignalTmpLengthForSignalGroups(Com_RxDynSignalTmpLengthForSignalGroupsIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxDynSignalTmpLengthForSignalGroupsType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_RxSigArrayAccessSigGrpBufferType, COM_CODE) Com_GetRxSigArrayAccessSigGrpBuffer(Com_RxSigArrayAccessSigGrpBufferIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigArrayAccessSigGrpBufferType) (Com_GetRxSigArrayAccessSigGrpBufferOfPCConfig()[(Index)]);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferArrayBasedType, COM_CODE) Com_GetRxSigBufferArrayBased(Com_RxSigBufferArrayBasedIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferArrayBasedType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferFloat32Type, COM_CODE) Com_GetRxSigBufferFloat32(Com_RxSigBufferFloat32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferFloat32Type) (0.0F);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferFloat64Type, COM_CODE) Com_GetRxSigBufferFloat64(Com_RxSigBufferFloat64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferFloat64Type) (0.0);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSInt16Type, COM_CODE) Com_GetRxSigBufferSInt16(Com_RxSigBufferSInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSInt16Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSInt32Type, COM_CODE) Com_GetRxSigBufferSInt32(Com_RxSigBufferSInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSInt32Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSInt64Type, COM_CODE) Com_GetRxSigBufferSInt64(Com_RxSigBufferSInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSInt64Type) (0LL);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSInt8Type, COM_CODE) Com_GetRxSigBufferSInt8(Com_RxSigBufferSInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSInt8Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesArrayBasedType, COM_CODE) Com_GetRxSigBufferSubValuesArrayBased(Com_RxSigBufferSubValuesArrayBasedIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSubValuesArrayBasedType) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesFloat32Type, COM_CODE) Com_GetRxSigBufferSubValuesFloat32(Com_RxSigBufferSubValuesFloat32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSubValuesFloat32Type) (0.0F);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesFloat64Type, COM_CODE) Com_GetRxSigBufferSubValuesFloat64(Com_RxSigBufferSubValuesFloat64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSubValuesFloat64Type) (0.0);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesSInt16Type, COM_CODE) Com_GetRxSigBufferSubValuesSInt16(Com_RxSigBufferSubValuesSInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSubValuesSInt16Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesSInt32Type, COM_CODE) Com_GetRxSigBufferSubValuesSInt32(Com_RxSigBufferSubValuesSInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSubValuesSInt32Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesSInt64Type, COM_CODE) Com_GetRxSigBufferSubValuesSInt64(Com_RxSigBufferSubValuesSInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSubValuesSInt64Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesSInt8Type, COM_CODE) Com_GetRxSigBufferSubValuesSInt8(Com_RxSigBufferSubValuesSInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSubValuesSInt8Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesSigGrpArrayAccessType, COM_CODE) Com_GetRxSigBufferSubValuesSigGrpArrayAccess(Com_RxSigBufferSubValuesSigGrpArrayAccessIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSubValuesSigGrpArrayAccessType) (Com_GetRxSigBufferSubValuesSigGrpArrayAccessOfPCConfig()[(Index)]);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesUInt16Type, COM_CODE) Com_GetRxSigBufferSubValuesUInt16(Com_RxSigBufferSubValuesUInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSubValuesUInt16Type) (Com_GetRxSigBufferSubValuesUInt16OfPCConfig()[(Index)]);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesUInt32Type, COM_CODE) Com_GetRxSigBufferSubValuesUInt32(Com_RxSigBufferSubValuesUInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSubValuesUInt32Type) (Com_GetRxSigBufferSubValuesUInt32OfPCConfig()[(Index)]);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesUInt64Type, COM_CODE) Com_GetRxSigBufferSubValuesUInt64(Com_RxSigBufferSubValuesUInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSubValuesUInt64Type) (0x0000000000000000uLL);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesUInt8Type, COM_CODE) Com_GetRxSigBufferSubValuesUInt8(Com_RxSigBufferSubValuesUInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSubValuesUInt8Type) (Com_GetRxSigBufferSubValuesUInt8OfPCConfig()[(Index)]);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferUInt16Type, COM_CODE) Com_GetRxSigBufferUInt16(Com_RxSigBufferUInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferUInt16Type) (Com_GetRxSigBufferUInt16OfPCConfig()[(Index)]);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferUInt32Type, COM_CODE) Com_GetRxSigBufferUInt32(Com_RxSigBufferUInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferUInt32Type) (Com_GetRxSigBufferUInt32OfPCConfig()[(Index)]);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferUInt64Type, COM_CODE) Com_GetRxSigBufferUInt64(Com_RxSigBufferUInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferUInt64Type) (0uLL);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferUInt8Type, COM_CODE) Com_GetRxSigBufferUInt8(Com_RxSigBufferUInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferUInt8Type) (Com_GetRxSigBufferUInt8OfPCConfig()[(Index)]);
}
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferArrayBasedType, COM_CODE) Com_GetTmpRxSigBufferArrayBased(Com_TmpRxSigBufferArrayBasedIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpRxSigBufferArrayBasedType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferFloat32Type, COM_CODE) Com_GetTmpRxSigBufferFloat32(Com_TmpRxSigBufferFloat32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpRxSigBufferFloat32Type) (0.0F);
}
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferFloat64Type, COM_CODE) Com_GetTmpRxSigBufferFloat64(Com_TmpRxSigBufferFloat64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpRxSigBufferFloat64Type) (0.0);
}
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferSInt16Type, COM_CODE) Com_GetTmpRxSigBufferSInt16(Com_TmpRxSigBufferSInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpRxSigBufferSInt16Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferSInt32Type, COM_CODE) Com_GetTmpRxSigBufferSInt32(Com_TmpRxSigBufferSInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpRxSigBufferSInt32Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferSInt64Type, COM_CODE) Com_GetTmpRxSigBufferSInt64(Com_TmpRxSigBufferSInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpRxSigBufferSInt64Type) (0LL);
}
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferSInt8Type, COM_CODE) Com_GetTmpRxSigBufferSInt8(Com_TmpRxSigBufferSInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpRxSigBufferSInt8Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferUInt16Type, COM_CODE) Com_GetTmpRxSigBufferUInt16(Com_TmpRxSigBufferUInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpRxSigBufferUInt16Type) (Com_GetTmpRxSigBufferUInt16OfPCConfig()[(Index)]);
}
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferUInt32Type, COM_CODE) Com_GetTmpRxSigBufferUInt32(Com_TmpRxSigBufferUInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpRxSigBufferUInt32Type) (Com_GetTmpRxSigBufferUInt32OfPCConfig()[(Index)]);
}
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferUInt64Type, COM_CODE) Com_GetTmpRxSigBufferUInt64(Com_TmpRxSigBufferUInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpRxSigBufferUInt64Type) (0uLL);
}
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferUInt8Type, COM_CODE) Com_GetTmpRxSigBufferUInt8(Com_TmpRxSigBufferUInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpRxSigBufferUInt8Type) (Com_GetTmpRxSigBufferUInt8OfPCConfig()[(Index)]);
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
COM_LOCAL_INLINE FUNC(Com_InitValueOfRxBufferInfoType, COM_CODE) Com_GetInitValueOfRxBufferInfo(Com_RxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InitValueOfRxBufferInfoType) Com_GetRxSigBufferOfRxBufferInfo(Index);
}
COM_LOCAL_INLINE FUNC(Com_InitValueUsedOfRxBufferInfoType, COM_CODE) Com_IsInitValueUsedOfRxBufferInfo(Com_RxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InitValueUsedOfRxBufferInfoType) (((boolean)(Com_GetInitValueLengthOfRxBufferInfo(Index) != 0u)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferLengthOfRxBufferInfoType, COM_CODE) Com_GetRxSigBufferLengthOfRxBufferInfo(Com_RxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferLengthOfRxBufferInfoType) Com_GetInitValueLengthOfRxBufferInfo(Index);
}
COM_LOCAL_INLINE FUNC(Com_TmpSigBufferUsedOfRxBufferInfoType, COM_CODE) Com_IsTmpSigBufferUsedOfRxBufferInfo(Com_RxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpSigBufferUsedOfRxBufferInfoType) (((boolean)(Com_GetTmpSigBufferLengthOfRxBufferInfo(Index) != 0u)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxDynSignalLength(Com_RxDynSignalLengthIterType Index, Com_RxDynSignalLengthType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxDynSignalTmpLengthForSignalGroups(Com_RxDynSignalTmpLengthForSignalGroupsIterType Index, Com_RxDynSignalTmpLengthForSignalGroupsType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxSigArrayAccessSigGrpBuffer(Com_RxSigArrayAccessSigGrpBufferIterType Index, Com_RxSigArrayAccessSigGrpBufferType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetRxSigArrayAccessSigGrpBufferOfPCConfig()[(Index)] = (Value);
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxSigBufferArrayBased(Com_RxSigBufferArrayBasedIterType Index, Com_RxSigBufferArrayBasedType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxSigBufferFloat32(Com_RxSigBufferFloat32IterType Index, Com_RxSigBufferFloat32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxSigBufferFloat64(Com_RxSigBufferFloat64IterType Index, Com_RxSigBufferFloat64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxSigBufferSInt16(Com_RxSigBufferSInt16IterType Index, Com_RxSigBufferSInt16Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxSigBufferSInt32(Com_RxSigBufferSInt32IterType Index, Com_RxSigBufferSInt32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxSigBufferSInt64(Com_RxSigBufferSInt64IterType Index, Com_RxSigBufferSInt64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxSigBufferSInt8(Com_RxSigBufferSInt8IterType Index, Com_RxSigBufferSInt8Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxSigBufferUInt16(Com_RxSigBufferUInt16IterType Index, Com_RxSigBufferUInt16Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetRxSigBufferUInt16OfPCConfig()[(Index)] = (Value);
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxSigBufferUInt32(Com_RxSigBufferUInt32IterType Index, Com_RxSigBufferUInt32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetRxSigBufferUInt32OfPCConfig()[(Index)] = (Value);
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxSigBufferUInt64(Com_RxSigBufferUInt64IterType Index, Com_RxSigBufferUInt64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxSigBufferUInt8(Com_RxSigBufferUInt8IterType Index, Com_RxSigBufferUInt8Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetRxSigBufferUInt8OfPCConfig()[(Index)] = (Value);
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpRxSigBufferArrayBased(Com_TmpRxSigBufferArrayBasedIterType Index, Com_TmpRxSigBufferArrayBasedType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpRxSigBufferFloat32(Com_TmpRxSigBufferFloat32IterType Index, Com_TmpRxSigBufferFloat32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpRxSigBufferFloat64(Com_TmpRxSigBufferFloat64IterType Index, Com_TmpRxSigBufferFloat64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpRxSigBufferSInt16(Com_TmpRxSigBufferSInt16IterType Index, Com_TmpRxSigBufferSInt16Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpRxSigBufferSInt32(Com_TmpRxSigBufferSInt32IterType Index, Com_TmpRxSigBufferSInt32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpRxSigBufferSInt64(Com_TmpRxSigBufferSInt64IterType Index, Com_TmpRxSigBufferSInt64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpRxSigBufferSInt8(Com_TmpRxSigBufferSInt8IterType Index, Com_TmpRxSigBufferSInt8Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpRxSigBufferUInt16(Com_TmpRxSigBufferUInt16IterType Index, Com_TmpRxSigBufferUInt16Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetTmpRxSigBufferUInt16OfPCConfig()[(Index)] = (Value);
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpRxSigBufferUInt32(Com_TmpRxSigBufferUInt32IterType Index, Com_TmpRxSigBufferUInt32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetTmpRxSigBufferUInt32OfPCConfig()[(Index)] = (Value);
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpRxSigBufferUInt64(Com_TmpRxSigBufferUInt64IterType Index, Com_TmpRxSigBufferUInt64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpRxSigBufferUInt8(Com_TmpRxSigBufferUInt8IterType Index, Com_TmpRxSigBufferUInt8Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetTmpRxSigBufferUInt8OfPCConfig()[(Index)] = (Value);
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
COM_LOCAL_INLINE FUNC(Com_RxSigArrayAccessSigGrpBufferPtrType, COM_CODE) Com_GetAddrRxSigArrayAccessSigGrpBuffer(Com_RxSigArrayAccessSigGrpBufferIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_RxSigArrayAccessSigGrpBufferPtrType) (&(Com_GetRxSigArrayAccessSigGrpBufferOfPCConfig()[(Index)]));
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferArrayBasedPtrType, COM_CODE) Com_GetAddrRxSigBufferArrayBased(Com_RxSigBufferArrayBasedIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferArrayBasedPtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferFloat32PtrType, COM_CODE) Com_GetAddrRxSigBufferFloat32(Com_RxSigBufferFloat32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferFloat32PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferFloat64PtrType, COM_CODE) Com_GetAddrRxSigBufferFloat64(Com_RxSigBufferFloat64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferFloat64PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSInt16PtrType, COM_CODE) Com_GetAddrRxSigBufferSInt16(Com_RxSigBufferSInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSInt16PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSInt32PtrType, COM_CODE) Com_GetAddrRxSigBufferSInt32(Com_RxSigBufferSInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSInt32PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSInt64PtrType, COM_CODE) Com_GetAddrRxSigBufferSInt64(Com_RxSigBufferSInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSInt64PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSInt8PtrType, COM_CODE) Com_GetAddrRxSigBufferSInt8(Com_RxSigBufferSInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSInt8PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesArrayBasedPtrType, COM_CODE) Com_GetAddrRxSigBufferSubValuesArrayBased(Com_RxSigBufferSubValuesArrayBasedIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSubValuesArrayBasedPtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesFloat32PtrType, COM_CODE) Com_GetAddrRxSigBufferSubValuesFloat32(Com_RxSigBufferSubValuesFloat32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSubValuesFloat32PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesFloat64PtrType, COM_CODE) Com_GetAddrRxSigBufferSubValuesFloat64(Com_RxSigBufferSubValuesFloat64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSubValuesFloat64PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesSInt16PtrType, COM_CODE) Com_GetAddrRxSigBufferSubValuesSInt16(Com_RxSigBufferSubValuesSInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSubValuesSInt16PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesSInt32PtrType, COM_CODE) Com_GetAddrRxSigBufferSubValuesSInt32(Com_RxSigBufferSubValuesSInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSubValuesSInt32PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesSInt64PtrType, COM_CODE) Com_GetAddrRxSigBufferSubValuesSInt64(Com_RxSigBufferSubValuesSInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSubValuesSInt64PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesSInt8PtrType, COM_CODE) Com_GetAddrRxSigBufferSubValuesSInt8(Com_RxSigBufferSubValuesSInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSubValuesSInt8PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesSigGrpArrayAccessPtrType, COM_CODE) Com_GetAddrRxSigBufferSubValuesSigGrpArrayAccess(Com_RxSigBufferSubValuesSigGrpArrayAccessIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_RxSigBufferSubValuesSigGrpArrayAccessPtrType) (&(Com_GetRxSigBufferSubValuesSigGrpArrayAccessOfPCConfig()[(Index)]));
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesUInt16PtrType, COM_CODE) Com_GetAddrRxSigBufferSubValuesUInt16(Com_RxSigBufferSubValuesUInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_RxSigBufferSubValuesUInt16PtrType) (&(Com_GetRxSigBufferSubValuesUInt16OfPCConfig()[(Index)]));
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesUInt32PtrType, COM_CODE) Com_GetAddrRxSigBufferSubValuesUInt32(Com_RxSigBufferSubValuesUInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_RxSigBufferSubValuesUInt32PtrType) (&(Com_GetRxSigBufferSubValuesUInt32OfPCConfig()[(Index)]));
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesUInt64PtrType, COM_CODE) Com_GetAddrRxSigBufferSubValuesUInt64(Com_RxSigBufferSubValuesUInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferSubValuesUInt64PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferSubValuesUInt8PtrType, COM_CODE) Com_GetAddrRxSigBufferSubValuesUInt8(Com_RxSigBufferSubValuesUInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_RxSigBufferSubValuesUInt8PtrType) (&(Com_GetRxSigBufferSubValuesUInt8OfPCConfig()[(Index)]));
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferUInt16PtrType, COM_CODE) Com_GetAddrRxSigBufferUInt16(Com_RxSigBufferUInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_RxSigBufferUInt16PtrType) (&(Com_GetRxSigBufferUInt16OfPCConfig()[(Index)]));
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferUInt32PtrType, COM_CODE) Com_GetAddrRxSigBufferUInt32(Com_RxSigBufferUInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_RxSigBufferUInt32PtrType) (&(Com_GetRxSigBufferUInt32OfPCConfig()[(Index)]));
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferUInt64PtrType, COM_CODE) Com_GetAddrRxSigBufferUInt64(Com_RxSigBufferUInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxSigBufferUInt64PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_RxSigBufferUInt8PtrType, COM_CODE) Com_GetAddrRxSigBufferUInt8(Com_RxSigBufferUInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_RxSigBufferUInt8PtrType) (&(Com_GetRxSigBufferUInt8OfPCConfig()[(Index)]));
}
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferArrayBasedPtrType, COM_CODE) Com_GetAddrTmpRxSigBufferArrayBased(Com_TmpRxSigBufferArrayBasedIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpRxSigBufferArrayBasedPtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferFloat32PtrType, COM_CODE) Com_GetAddrTmpRxSigBufferFloat32(Com_TmpRxSigBufferFloat32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpRxSigBufferFloat32PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferFloat64PtrType, COM_CODE) Com_GetAddrTmpRxSigBufferFloat64(Com_TmpRxSigBufferFloat64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpRxSigBufferFloat64PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferSInt16PtrType, COM_CODE) Com_GetAddrTmpRxSigBufferSInt16(Com_TmpRxSigBufferSInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpRxSigBufferSInt16PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferSInt32PtrType, COM_CODE) Com_GetAddrTmpRxSigBufferSInt32(Com_TmpRxSigBufferSInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpRxSigBufferSInt32PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferSInt64PtrType, COM_CODE) Com_GetAddrTmpRxSigBufferSInt64(Com_TmpRxSigBufferSInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpRxSigBufferSInt64PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferSInt8PtrType, COM_CODE) Com_GetAddrTmpRxSigBufferSInt8(Com_TmpRxSigBufferSInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpRxSigBufferSInt8PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferUInt16PtrType, COM_CODE) Com_GetAddrTmpRxSigBufferUInt16(Com_TmpRxSigBufferUInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_TmpRxSigBufferUInt16PtrType) (&(Com_GetTmpRxSigBufferUInt16OfPCConfig()[(Index)]));
}
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferUInt32PtrType, COM_CODE) Com_GetAddrTmpRxSigBufferUInt32(Com_TmpRxSigBufferUInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_TmpRxSigBufferUInt32PtrType) (&(Com_GetTmpRxSigBufferUInt32OfPCConfig()[(Index)]));
}
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferUInt64PtrType, COM_CODE) Com_GetAddrTmpRxSigBufferUInt64(Com_TmpRxSigBufferUInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpRxSigBufferUInt64PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TmpRxSigBufferUInt8PtrType, COM_CODE) Com_GetAddrTmpRxSigBufferUInt8(Com_TmpRxSigBufferUInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_TmpRxSigBufferUInt8PtrType) (&(Com_GetTmpRxSigBufferUInt8OfPCConfig()[(Index)]));
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInitValueEndIdxOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInitValueLengthOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInitValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInitValueStartIdxOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInitValueUsedOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDataTimeoutSubstitutionValueEndIdxOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDataTimeoutSubstitutionValueLengthOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDataTimeoutSubstitutionValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDataTimeoutSubstitutionValueStartIdxOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDataTimeoutSubstitutionValueUsedOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferEndIdxOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferLengthOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferStartIdxOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpSigBufferEndIdxOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpSigBufferLengthOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpSigBufferStartIdxOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpSigBufferUsedOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDynSignalLength(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDynSignalTmpLengthForSignalGroups(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigArrayAccessSigGrpBuffer(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferArrayBased(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferFloat32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferFloat64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSubValuesArrayBased(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSubValuesFloat32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSubValuesFloat64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSubValuesSInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSubValuesSInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSubValuesSInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSubValuesSInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSubValuesSigGrpArrayAccess(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSubValuesUInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSubValuesUInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSubValuesUInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferSubValuesUInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferUInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferUInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferUInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxSigBufferUInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxDynSignalLength(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxDynSignalTmpLengthForSignalGroups(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigArrayAccessSigGrpBuffer(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferArrayBased(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferFloat32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferFloat64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSubValuesArrayBased(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSubValuesFloat32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSubValuesFloat64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSubValuesSInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSubValuesSInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSubValuesSInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSubValuesSInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSubValuesSigGrpArrayAccess(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSubValuesUInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSubValuesUInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSubValuesUInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferSubValuesUInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferUInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferUInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferUInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxSigBufferUInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpRxSigBufferArrayBased(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpRxSigBufferFloat32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpRxSigBufferFloat64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpRxSigBufferSInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpRxSigBufferSInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpRxSigBufferSInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpRxSigBufferSInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpRxSigBufferUInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpRxSigBufferUInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpRxSigBufferUInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpRxSigBufferUInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpRxSigBufferArrayBased(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpRxSigBufferFloat32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpRxSigBufferFloat64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpRxSigBufferSInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpRxSigBufferSInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpRxSigBufferSInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpRxSigBufferSInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpRxSigBufferUInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpRxSigBufferUInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpRxSigBufferUInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpRxSigBufferUInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesUInt8InitValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesUInt16InitValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesUInt32InitValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesUInt64InitValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesSInt8InitValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesSInt16InitValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesSInt32InitValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesSInt64InitValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesFloat32InitValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesFloat64InitValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesArrayBasedInitValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesSigGrpArrayAccessInitValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNoInitValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesUInt8RxDataTimeoutSubstitutionValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesUInt16RxDataTimeoutSubstitutionValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesUInt32RxDataTimeoutSubstitutionValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesUInt64RxDataTimeoutSubstitutionValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesSInt8RxDataTimeoutSubstitutionValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesSInt16RxDataTimeoutSubstitutionValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesSInt32RxDataTimeoutSubstitutionValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesSInt64RxDataTimeoutSubstitutionValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesFloat32RxDataTimeoutSubstitutionValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesFloat64RxDataTimeoutSubstitutionValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesArrayBasedRxDataTimeoutSubstitutionValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSubValuesSigGrpArrayAccessRxDataTimeoutSubstitutionValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNoRxDataTimeoutSubstitutionValueOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferUInt8RxSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferUInt16RxSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferUInt32RxSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferUInt64RxSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSInt8RxSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSInt16RxSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSInt32RxSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferSInt64RxSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferFloat32RxSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferFloat64RxSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigBufferArrayBasedRxSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsRxSigArrayAccessSigGrpBufferRxSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpRxSigBufferUInt8TmpSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpRxSigBufferUInt16TmpSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpRxSigBufferUInt32TmpSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpRxSigBufferUInt64TmpSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpRxSigBufferSInt8TmpSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpRxSigBufferSInt16TmpSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpRxSigBufferSInt32TmpSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpRxSigBufferSInt64TmpSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpRxSigBufferFloat32TmpSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpRxSigBufferFloat64TmpSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpRxSigBufferArrayBasedTmpSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNoTmpSigBufferOfRxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
  \defgroup  ComPCIncrementInlineFunctions  Com Increment Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to increment VAR data with numerical nature.
  \{
*/ 
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxDynSignalLength(Com_RxDynSignalLengthIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxDynSignalTmpLengthForSignalGroups(Com_RxDynSignalTmpLengthForSignalGroupsIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxSigArrayAccessSigGrpBuffer(Com_RxSigArrayAccessSigGrpBufferIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetRxSigArrayAccessSigGrpBufferOfPCConfig()[(Index)]++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxSigBufferArrayBased(Com_RxSigBufferArrayBasedIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxSigBufferSInt16(Com_RxSigBufferSInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxSigBufferSInt32(Com_RxSigBufferSInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxSigBufferSInt64(Com_RxSigBufferSInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxSigBufferSInt8(Com_RxSigBufferSInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxSigBufferUInt16(Com_RxSigBufferUInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetRxSigBufferUInt16OfPCConfig()[(Index)]++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxSigBufferUInt32(Com_RxSigBufferUInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetRxSigBufferUInt32OfPCConfig()[(Index)]++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxSigBufferUInt64(Com_RxSigBufferUInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxSigBufferUInt8(Com_RxSigBufferUInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetRxSigBufferUInt8OfPCConfig()[(Index)]++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpRxSigBufferArrayBased(Com_TmpRxSigBufferArrayBasedIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpRxSigBufferSInt16(Com_TmpRxSigBufferSInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpRxSigBufferSInt32(Com_TmpRxSigBufferSInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpRxSigBufferSInt64(Com_TmpRxSigBufferSInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpRxSigBufferSInt8(Com_TmpRxSigBufferSInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpRxSigBufferUInt16(Com_TmpRxSigBufferUInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetTmpRxSigBufferUInt16OfPCConfig()[(Index)]++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpRxSigBufferUInt32(Com_TmpRxSigBufferUInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetTmpRxSigBufferUInt32OfPCConfig()[(Index)]++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpRxSigBufferUInt64(Com_TmpRxSigBufferUInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpRxSigBufferUInt8(Com_TmpRxSigBufferUInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetTmpRxSigBufferUInt8OfPCConfig()[(Index)]++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxDynSignalLength(Com_RxDynSignalLengthIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxDynSignalTmpLengthForSignalGroups(Com_RxDynSignalTmpLengthForSignalGroupsIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxSigArrayAccessSigGrpBuffer(Com_RxSigArrayAccessSigGrpBufferIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetRxSigArrayAccessSigGrpBufferOfPCConfig()[(Index)]--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxSigBufferArrayBased(Com_RxSigBufferArrayBasedIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxSigBufferSInt16(Com_RxSigBufferSInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxSigBufferSInt32(Com_RxSigBufferSInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxSigBufferSInt64(Com_RxSigBufferSInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxSigBufferSInt8(Com_RxSigBufferSInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxSigBufferUInt16(Com_RxSigBufferUInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetRxSigBufferUInt16OfPCConfig()[(Index)]--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxSigBufferUInt32(Com_RxSigBufferUInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetRxSigBufferUInt32OfPCConfig()[(Index)]--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxSigBufferUInt64(Com_RxSigBufferUInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxSigBufferUInt8(Com_RxSigBufferUInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetRxSigBufferUInt8OfPCConfig()[(Index)]--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpRxSigBufferArrayBased(Com_TmpRxSigBufferArrayBasedIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpRxSigBufferSInt16(Com_TmpRxSigBufferSInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpRxSigBufferSInt32(Com_TmpRxSigBufferSInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpRxSigBufferSInt64(Com_TmpRxSigBufferSInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpRxSigBufferSInt8(Com_TmpRxSigBufferSInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpRxSigBufferUInt16(Com_TmpRxSigBufferUInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetTmpRxSigBufferUInt16OfPCConfig()[(Index)]--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpRxSigBufferUInt32(Com_TmpRxSigBufferUInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetTmpRxSigBufferUInt32OfPCConfig()[(Index)]--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpRxSigBufferUInt64(Com_TmpRxSigBufferUInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpRxSigBufferUInt8(Com_TmpRxSigBufferUInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetTmpRxSigBufferUInt8OfPCConfig()[(Index)]--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxDynSignalLength(Com_RxDynSignalLengthIterType Index, Com_RxDynSignalLengthType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxDynSignalTmpLengthForSignalGroups(Com_RxDynSignalTmpLengthForSignalGroupsIterType Index, Com_RxDynSignalTmpLengthForSignalGroupsType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxSigArrayAccessSigGrpBuffer(Com_RxSigArrayAccessSigGrpBufferIterType Index, Com_RxSigArrayAccessSigGrpBufferType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_SetRxSigArrayAccessSigGrpBuffer(Index, (Com_GetRxSigArrayAccessSigGrpBufferOfPCConfig()[(Index)] + Value));
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxSigBufferArrayBased(Com_RxSigBufferArrayBasedIterType Index, Com_RxSigBufferArrayBasedType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxSigBufferSInt16(Com_RxSigBufferSInt16IterType Index, Com_RxSigBufferSInt16Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxSigBufferSInt32(Com_RxSigBufferSInt32IterType Index, Com_RxSigBufferSInt32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxSigBufferSInt64(Com_RxSigBufferSInt64IterType Index, Com_RxSigBufferSInt64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxSigBufferSInt8(Com_RxSigBufferSInt8IterType Index, Com_RxSigBufferSInt8Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxSigBufferUInt16(Com_RxSigBufferUInt16IterType Index, Com_RxSigBufferUInt16Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_SetRxSigBufferUInt16(Index, (Com_GetRxSigBufferUInt16OfPCConfig()[(Index)] + Value));
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxSigBufferUInt32(Com_RxSigBufferUInt32IterType Index, Com_RxSigBufferUInt32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_SetRxSigBufferUInt32(Index, (Com_GetRxSigBufferUInt32OfPCConfig()[(Index)] + Value));
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxSigBufferUInt64(Com_RxSigBufferUInt64IterType Index, Com_RxSigBufferUInt64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxSigBufferUInt8(Com_RxSigBufferUInt8IterType Index, Com_RxSigBufferUInt8Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_SetRxSigBufferUInt8(Index, (Com_GetRxSigBufferUInt8OfPCConfig()[(Index)] + Value));
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpRxSigBufferArrayBased(Com_TmpRxSigBufferArrayBasedIterType Index, Com_TmpRxSigBufferArrayBasedType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpRxSigBufferSInt16(Com_TmpRxSigBufferSInt16IterType Index, Com_TmpRxSigBufferSInt16Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpRxSigBufferSInt32(Com_TmpRxSigBufferSInt32IterType Index, Com_TmpRxSigBufferSInt32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpRxSigBufferSInt64(Com_TmpRxSigBufferSInt64IterType Index, Com_TmpRxSigBufferSInt64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpRxSigBufferSInt8(Com_TmpRxSigBufferSInt8IterType Index, Com_TmpRxSigBufferSInt8Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpRxSigBufferUInt16(Com_TmpRxSigBufferUInt16IterType Index, Com_TmpRxSigBufferUInt16Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_SetTmpRxSigBufferUInt16(Index, (Com_GetTmpRxSigBufferUInt16OfPCConfig()[(Index)] + Value));
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpRxSigBufferUInt32(Com_TmpRxSigBufferUInt32IterType Index, Com_TmpRxSigBufferUInt32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_SetTmpRxSigBufferUInt32(Index, (Com_GetTmpRxSigBufferUInt32OfPCConfig()[(Index)] + Value));
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpRxSigBufferUInt64(Com_TmpRxSigBufferUInt64IterType Index, Com_TmpRxSigBufferUInt64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpRxSigBufferUInt8(Com_TmpRxSigBufferUInt8IterType Index, Com_TmpRxSigBufferUInt8Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_SetTmpRxSigBufferUInt8(Index, (Com_GetTmpRxSigBufferUInt8OfPCConfig()[(Index)] + Value));
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxDynSignalLength(Com_RxDynSignalLengthIterType Index, Com_RxDynSignalLengthType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxDynSignalTmpLengthForSignalGroups(Com_RxDynSignalTmpLengthForSignalGroupsIterType Index, Com_RxDynSignalTmpLengthForSignalGroupsType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxSigArrayAccessSigGrpBuffer(Com_RxSigArrayAccessSigGrpBufferIterType Index, Com_RxSigArrayAccessSigGrpBufferType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_SetRxSigArrayAccessSigGrpBuffer(Index, (Com_GetRxSigArrayAccessSigGrpBufferOfPCConfig()[(Index)] - Value));
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxSigBufferArrayBased(Com_RxSigBufferArrayBasedIterType Index, Com_RxSigBufferArrayBasedType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxSigBufferSInt16(Com_RxSigBufferSInt16IterType Index, Com_RxSigBufferSInt16Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxSigBufferSInt32(Com_RxSigBufferSInt32IterType Index, Com_RxSigBufferSInt32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxSigBufferSInt64(Com_RxSigBufferSInt64IterType Index, Com_RxSigBufferSInt64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxSigBufferSInt8(Com_RxSigBufferSInt8IterType Index, Com_RxSigBufferSInt8Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxSigBufferUInt16(Com_RxSigBufferUInt16IterType Index, Com_RxSigBufferUInt16Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_SetRxSigBufferUInt16(Index, (Com_GetRxSigBufferUInt16OfPCConfig()[(Index)] - Value));
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxSigBufferUInt32(Com_RxSigBufferUInt32IterType Index, Com_RxSigBufferUInt32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_SetRxSigBufferUInt32(Index, (Com_GetRxSigBufferUInt32OfPCConfig()[(Index)] - Value));
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxSigBufferUInt64(Com_RxSigBufferUInt64IterType Index, Com_RxSigBufferUInt64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxSigBufferUInt8(Com_RxSigBufferUInt8IterType Index, Com_RxSigBufferUInt8Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_SetRxSigBufferUInt8(Index, (Com_GetRxSigBufferUInt8OfPCConfig()[(Index)] - Value));
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpRxSigBufferArrayBased(Com_TmpRxSigBufferArrayBasedIterType Index, Com_TmpRxSigBufferArrayBasedType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpRxSigBufferSInt16(Com_TmpRxSigBufferSInt16IterType Index, Com_TmpRxSigBufferSInt16Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpRxSigBufferSInt32(Com_TmpRxSigBufferSInt32IterType Index, Com_TmpRxSigBufferSInt32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpRxSigBufferSInt64(Com_TmpRxSigBufferSInt64IterType Index, Com_TmpRxSigBufferSInt64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpRxSigBufferSInt8(Com_TmpRxSigBufferSInt8IterType Index, Com_TmpRxSigBufferSInt8Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpRxSigBufferUInt16(Com_TmpRxSigBufferUInt16IterType Index, Com_TmpRxSigBufferUInt16Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_SetTmpRxSigBufferUInt16(Index, (Com_GetTmpRxSigBufferUInt16OfPCConfig()[(Index)] - Value));
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpRxSigBufferUInt32(Com_TmpRxSigBufferUInt32IterType Index, Com_TmpRxSigBufferUInt32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_SetTmpRxSigBufferUInt32(Index, (Com_GetTmpRxSigBufferUInt32OfPCConfig()[(Index)] - Value));
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpRxSigBufferUInt64(Com_TmpRxSigBufferUInt64IterType Index, Com_TmpRxSigBufferUInt64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpRxSigBufferUInt8(Com_TmpRxSigBufferUInt8IterType Index, Com_TmpRxSigBufferUInt8Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_SetTmpRxSigBufferUInt8(Index, (Com_GetTmpRxSigBufferUInt8OfPCConfig()[(Index)] - Value));
}
/** 
  \}
*/ 

#define COM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */





/* VCA Enable : VCA_COM_FUNCTION_NOT_USED_AND_NO_ANALYSIS_ENTRY */

#endif  /* COM_CFG_RXSIGNALBUFFERDATA_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cfg_RxSignalBufferData.h
**********************************************************************************************************************/

