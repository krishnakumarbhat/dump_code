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
 *              File: Com_Cfg_FilterData.h
 *   Generation Time: 2026-04-02 15:10:29
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

#if !defined (COM_CFG_FILTERDATA_H)
# define COM_CFG_FILTERDATA_H

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
COM_LOCAL_INLINE FUNC(Com_SizeOfArrayBasedFilterMaskType, COM_CODE) Com_GetSizeOfArrayBasedFilterMask(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfArrayBasedFilterValueXType, COM_CODE) Com_GetSizeOfArrayBasedFilterValueX(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfoType, COM_CODE) Com_GetSizeOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_Float32Type, COM_CODE) Com_GetSizeOfFilterInfo_Float32(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_Float64Type, COM_CODE) Com_GetSizeOfFilterInfo_Float64(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_SInt16Type, COM_CODE) Com_GetSizeOfFilterInfo_SInt16(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_SInt32Type, COM_CODE) Com_GetSizeOfFilterInfo_SInt32(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_SInt64Type, COM_CODE) Com_GetSizeOfFilterInfo_SInt64(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_SInt8Type, COM_CODE) Com_GetSizeOfFilterInfo_SInt8(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_UInt16Type, COM_CODE) Com_GetSizeOfFilterInfo_UInt16(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_UInt32Type, COM_CODE) Com_GetSizeOfFilterInfo_UInt32(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_UInt64Type, COM_CODE) Com_GetSizeOfFilterInfo_UInt64(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_UInt8Type, COM_CODE) Com_GetSizeOfFilterInfo_UInt8(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_UInt8_DynType, COM_CODE) Com_GetSizeOfFilterInfo_UInt8_Dyn(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_UInt8_NType, COM_CODE) Com_GetSizeOfFilterInfo_UInt8_N(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_ZeroBitType, COM_CODE) Com_GetSizeOfFilterInfo_ZeroBit(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfSigGrpArrayFilterInfoType, COM_CODE) Com_GetSizeOfSigGrpArrayFilterInfo(void);
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
COM_LOCAL_INLINE FUNC(Com_ArrayBasedFilterMaskType, COM_CODE) Com_GetArrayBasedFilterMask(Com_ArrayBasedFilterMaskIterType Index);
COM_LOCAL_INLINE FUNC(Com_ArrayBasedFilterValueXType, COM_CODE) Com_GetArrayBasedFilterValueX(Com_ArrayBasedFilterValueXIterType Index);
COM_LOCAL_INLINE FUNC(Com_ApplTypSpecificFilterInfoIdxOfFilterInfoType, COM_CODE) Com_GetApplTypSpecificFilterInfoIdxOfFilterInfo(Com_FilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ApplTypSpecificFilterInfoOfFilterInfoType, COM_CODE) Com_GetApplTypSpecificFilterInfoOfFilterInfo(Com_FilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterInitValueEndIdxOfFilterInfoType, COM_CODE) Com_GetFilterInitValueEndIdxOfFilterInfo(Com_FilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterInitValueLengthOfFilterInfoType, COM_CODE) Com_GetFilterInitValueLengthOfFilterInfo(Com_FilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterInitValueOfFilterInfoType, COM_CODE) Com_GetFilterInitValueOfFilterInfo(Com_FilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterInitValueStartIdxOfFilterInfoType, COM_CODE) Com_GetFilterInitValueStartIdxOfFilterInfo(Com_FilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterInitValueUsedOfFilterInfoType, COM_CODE) Com_IsFilterInitValueUsedOfFilterInfo(Com_FilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoIdxOfFilterInfoType, COM_CODE) Com_GetRxTOutInfoIdxOfFilterInfo(Com_FilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoUsedOfFilterInfoType, COM_CODE) Com_IsRxTOutInfoUsedOfFilterInfo(Com_FilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_Float32Type, COM_CODE) Com_GetFilterAlgoOfFilterInfo_Float32(Com_FilterInfo_Float32IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_Float32Type, COM_CODE) Com_GetFilterMaskOfFilterInfo_Float32(Com_FilterInfo_Float32IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_Float32Type, COM_CODE) Com_GetFilterMaxOfFilterInfo_Float32(Com_FilterInfo_Float32IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_Float32Type, COM_CODE) Com_GetFilterMinOfFilterInfo_Float32(Com_FilterInfo_Float32IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_Float32Type, COM_CODE) Com_GetFilterXOfFilterInfo_Float32(Com_FilterInfo_Float32IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_Float64Type, COM_CODE) Com_GetFilterAlgoOfFilterInfo_Float64(Com_FilterInfo_Float64IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_Float64Type, COM_CODE) Com_GetFilterMaskOfFilterInfo_Float64(Com_FilterInfo_Float64IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_Float64Type, COM_CODE) Com_GetFilterMaxOfFilterInfo_Float64(Com_FilterInfo_Float64IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_Float64Type, COM_CODE) Com_GetFilterMinOfFilterInfo_Float64(Com_FilterInfo_Float64IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_Float64Type, COM_CODE) Com_GetFilterXOfFilterInfo_Float64(Com_FilterInfo_Float64IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_SInt16Type, COM_CODE) Com_GetFilterAlgoOfFilterInfo_SInt16(Com_FilterInfo_SInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_SInt16Type, COM_CODE) Com_GetFilterMaskOfFilterInfo_SInt16(Com_FilterInfo_SInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_SInt16Type, COM_CODE) Com_GetFilterMaxOfFilterInfo_SInt16(Com_FilterInfo_SInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_SInt16Type, COM_CODE) Com_GetFilterMinOfFilterInfo_SInt16(Com_FilterInfo_SInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_SInt16Type, COM_CODE) Com_GetFilterXOfFilterInfo_SInt16(Com_FilterInfo_SInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_SInt32Type, COM_CODE) Com_GetFilterAlgoOfFilterInfo_SInt32(Com_FilterInfo_SInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_SInt32Type, COM_CODE) Com_GetFilterMaskOfFilterInfo_SInt32(Com_FilterInfo_SInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_SInt32Type, COM_CODE) Com_GetFilterMaxOfFilterInfo_SInt32(Com_FilterInfo_SInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_SInt32Type, COM_CODE) Com_GetFilterMinOfFilterInfo_SInt32(Com_FilterInfo_SInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_SInt32Type, COM_CODE) Com_GetFilterXOfFilterInfo_SInt32(Com_FilterInfo_SInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_SInt64Type, COM_CODE) Com_GetFilterAlgoOfFilterInfo_SInt64(Com_FilterInfo_SInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_SInt64Type, COM_CODE) Com_GetFilterMaskOfFilterInfo_SInt64(Com_FilterInfo_SInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_SInt64Type, COM_CODE) Com_GetFilterMaxOfFilterInfo_SInt64(Com_FilterInfo_SInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_SInt64Type, COM_CODE) Com_GetFilterMinOfFilterInfo_SInt64(Com_FilterInfo_SInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_SInt64Type, COM_CODE) Com_GetFilterXOfFilterInfo_SInt64(Com_FilterInfo_SInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_SInt8Type, COM_CODE) Com_GetFilterAlgoOfFilterInfo_SInt8(Com_FilterInfo_SInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_SInt8Type, COM_CODE) Com_GetFilterMaskOfFilterInfo_SInt8(Com_FilterInfo_SInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_SInt8Type, COM_CODE) Com_GetFilterMaxOfFilterInfo_SInt8(Com_FilterInfo_SInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_SInt8Type, COM_CODE) Com_GetFilterMinOfFilterInfo_SInt8(Com_FilterInfo_SInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_SInt8Type, COM_CODE) Com_GetFilterXOfFilterInfo_SInt8(Com_FilterInfo_SInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_UInt16Type, COM_CODE) Com_GetFilterAlgoOfFilterInfo_UInt16(Com_FilterInfo_UInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_UInt16Type, COM_CODE) Com_GetFilterMaskOfFilterInfo_UInt16(Com_FilterInfo_UInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_UInt16Type, COM_CODE) Com_GetFilterMaxOfFilterInfo_UInt16(Com_FilterInfo_UInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_UInt16Type, COM_CODE) Com_GetFilterMinOfFilterInfo_UInt16(Com_FilterInfo_UInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_UInt16Type, COM_CODE) Com_GetFilterXOfFilterInfo_UInt16(Com_FilterInfo_UInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_UInt32Type, COM_CODE) Com_GetFilterAlgoOfFilterInfo_UInt32(Com_FilterInfo_UInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_UInt32Type, COM_CODE) Com_GetFilterMaskOfFilterInfo_UInt32(Com_FilterInfo_UInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_UInt32Type, COM_CODE) Com_GetFilterMaxOfFilterInfo_UInt32(Com_FilterInfo_UInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_UInt32Type, COM_CODE) Com_GetFilterMinOfFilterInfo_UInt32(Com_FilterInfo_UInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_UInt32Type, COM_CODE) Com_GetFilterXOfFilterInfo_UInt32(Com_FilterInfo_UInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_UInt64Type, COM_CODE) Com_GetFilterAlgoOfFilterInfo_UInt64(Com_FilterInfo_UInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_UInt64Type, COM_CODE) Com_GetFilterMaskOfFilterInfo_UInt64(Com_FilterInfo_UInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_UInt64Type, COM_CODE) Com_GetFilterMaxOfFilterInfo_UInt64(Com_FilterInfo_UInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_UInt64Type, COM_CODE) Com_GetFilterMinOfFilterInfo_UInt64(Com_FilterInfo_UInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_UInt64Type, COM_CODE) Com_GetFilterXOfFilterInfo_UInt64(Com_FilterInfo_UInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_UInt8Type, COM_CODE) Com_GetFilterAlgoOfFilterInfo_UInt8(Com_FilterInfo_UInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_UInt8Type, COM_CODE) Com_GetFilterMaskOfFilterInfo_UInt8(Com_FilterInfo_UInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_UInt8Type, COM_CODE) Com_GetFilterMaxOfFilterInfo_UInt8(Com_FilterInfo_UInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_UInt8Type, COM_CODE) Com_GetFilterMinOfFilterInfo_UInt8(Com_FilterInfo_UInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_UInt8Type, COM_CODE) Com_GetFilterXOfFilterInfo_UInt8(Com_FilterInfo_UInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_UInt8_DynType, COM_CODE) Com_GetFilterAlgoOfFilterInfo_UInt8_Dyn(Com_FilterInfo_UInt8_DynIterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_UInt8_DynType, COM_CODE) Com_GetFilterMaskOfFilterInfo_UInt8_Dyn(Com_FilterInfo_UInt8_DynIterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_UInt8_DynType, COM_CODE) Com_GetFilterMaxOfFilterInfo_UInt8_Dyn(Com_FilterInfo_UInt8_DynIterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_UInt8_DynType, COM_CODE) Com_GetFilterMinOfFilterInfo_UInt8_Dyn(Com_FilterInfo_UInt8_DynIterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_UInt8_DynType, COM_CODE) Com_GetFilterXOfFilterInfo_UInt8_Dyn(Com_FilterInfo_UInt8_DynIterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_UInt8_NType, COM_CODE) Com_GetFilterAlgoOfFilterInfo_UInt8_N(Com_FilterInfo_UInt8_NIterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_UInt8_NType, COM_CODE) Com_GetFilterMaskOfFilterInfo_UInt8_N(Com_FilterInfo_UInt8_NIterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_UInt8_NType, COM_CODE) Com_GetFilterMaxOfFilterInfo_UInt8_N(Com_FilterInfo_UInt8_NIterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_UInt8_NType, COM_CODE) Com_GetFilterMinOfFilterInfo_UInt8_N(Com_FilterInfo_UInt8_NIterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_UInt8_NType, COM_CODE) Com_GetFilterXOfFilterInfo_UInt8_N(Com_FilterInfo_UInt8_NIterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_ZeroBitType, COM_CODE) Com_GetFilterAlgoOfFilterInfo_ZeroBit(Com_FilterInfo_ZeroBitIterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_ZeroBitType, COM_CODE) Com_GetFilterMaskOfFilterInfo_ZeroBit(Com_FilterInfo_ZeroBitIterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_ZeroBitType, COM_CODE) Com_GetFilterMaxOfFilterInfo_ZeroBit(Com_FilterInfo_ZeroBitIterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_ZeroBitType, COM_CODE) Com_GetFilterMinOfFilterInfo_ZeroBit(Com_FilterInfo_ZeroBitIterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_ZeroBitType, COM_CODE) Com_GetFilterXOfFilterInfo_ZeroBit(Com_FilterInfo_ZeroBitIterType Index);
COM_LOCAL_INLINE FUNC(Com_ArrayBasedFilterMaskEndIdxOfSigGrpArrayFilterInfoType, COM_CODE) Com_GetArrayBasedFilterMaskEndIdxOfSigGrpArrayFilterInfo(Com_SigGrpArrayFilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ArrayBasedFilterMaskLengthOfSigGrpArrayFilterInfoType, COM_CODE) Com_GetArrayBasedFilterMaskLengthOfSigGrpArrayFilterInfo(Com_SigGrpArrayFilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ArrayBasedFilterMaskStartIdxOfSigGrpArrayFilterInfoType, COM_CODE) Com_GetArrayBasedFilterMaskStartIdxOfSigGrpArrayFilterInfo(Com_SigGrpArrayFilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ArrayBasedFilterMaskUsedOfSigGrpArrayFilterInfoType, COM_CODE) Com_IsArrayBasedFilterMaskUsedOfSigGrpArrayFilterInfo(Com_SigGrpArrayFilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ArrayBasedFilterValueXEndIdxOfSigGrpArrayFilterInfoType, COM_CODE) Com_GetArrayBasedFilterValueXEndIdxOfSigGrpArrayFilterInfo(Com_SigGrpArrayFilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ArrayBasedFilterValueXLengthOfSigGrpArrayFilterInfoType, COM_CODE) Com_GetArrayBasedFilterValueXLengthOfSigGrpArrayFilterInfo(Com_SigGrpArrayFilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ArrayBasedFilterValueXStartIdxOfSigGrpArrayFilterInfoType, COM_CODE) Com_GetArrayBasedFilterValueXStartIdxOfSigGrpArrayFilterInfo(Com_SigGrpArrayFilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ArrayBasedFilterValueXUsedOfSigGrpArrayFilterInfoType, COM_CODE) Com_IsArrayBasedFilterValueXUsedOfSigGrpArrayFilterInfo(Com_SigGrpArrayFilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfSigGrpArrayFilterInfoType, COM_CODE) Com_GetFilterAlgoOfSigGrpArrayFilterInfo(Com_SigGrpArrayFilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_OffsetInSignalGroupOfSigGrpArrayFilterInfoType, COM_CODE) Com_GetOffsetInSignalGroupOfSigGrpArrayFilterInfo(Com_SigGrpArrayFilterInfoIterType Index);
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
COM_LOCAL_INLINE FUNC(Com_ArrayBasedFilterMaskPtrType, COM_CODE) Com_GetAddrArrayBasedFilterMask(Com_ArrayBasedFilterMaskIterType Index);
COM_LOCAL_INLINE FUNC(Com_ArrayBasedFilterValueXPtrType, COM_CODE) Com_GetAddrArrayBasedFilterValueX(Com_ArrayBasedFilterValueXIterType Index);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasArrayBasedFilterMask(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasArrayBasedFilterValueX(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasApplTypSpecificFilterInfoIdxOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasApplTypSpecificFilterInfoOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInitValueEndIdxOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInitValueLengthOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInitValueOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInitValueStartIdxOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInitValueUsedOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoIdxOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoUsedOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_Float32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_Float32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_Float32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_Float32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_Float32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_Float32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_Float64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_Float64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_Float64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_Float64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_Float64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_Float64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_SInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_SInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_SInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_SInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_SInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_SInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_SInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_SInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_SInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_SInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_SInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_SInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_SInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_SInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_SInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_SInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_SInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_SInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_SInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_SInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_SInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_SInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_SInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_SInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_UInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_UInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_UInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_UInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_UInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_UInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_UInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_UInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_UInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_UInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_UInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_UInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_UInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_UInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_UInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_UInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_UInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_UInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_UInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_UInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_UInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_UInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_UInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_UInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_UInt8_Dyn(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_UInt8_Dyn(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_UInt8_Dyn(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_UInt8_Dyn(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_UInt8_Dyn(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_UInt8_Dyn(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_UInt8_N(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_UInt8_N(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_UInt8_N(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_UInt8_N(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_UInt8_N(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_UInt8_N(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_ZeroBit(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_ZeroBit(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_ZeroBit(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_ZeroBit(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_ZeroBit(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_ZeroBit(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSigGrpArrayFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasArrayBasedFilterMaskEndIdxOfSigGrpArrayFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasArrayBasedFilterMaskLengthOfSigGrpArrayFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasArrayBasedFilterMaskStartIdxOfSigGrpArrayFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasArrayBasedFilterMaskUsedOfSigGrpArrayFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasArrayBasedFilterValueXEndIdxOfSigGrpArrayFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasArrayBasedFilterValueXLengthOfSigGrpArrayFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasArrayBasedFilterValueXStartIdxOfSigGrpArrayFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasArrayBasedFilterValueXUsedOfSigGrpArrayFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfSigGrpArrayFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasOffsetInSignalGroupOfSigGrpArrayFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfArrayBasedFilterMask(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfArrayBasedFilterValueX(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_Float32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_Float64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_SInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_SInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_SInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_SInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_UInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_UInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_UInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_UInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_UInt8_Dyn(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_UInt8_N(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_ZeroBit(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfSigGrpArrayFilterInfo(void);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_UInt8ApplTypSpecificFilterInfoOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_SInt8ApplTypSpecificFilterInfoOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_UInt16ApplTypSpecificFilterInfoOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_SInt16ApplTypSpecificFilterInfoOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_UInt32ApplTypSpecificFilterInfoOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_SInt32ApplTypSpecificFilterInfoOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_UInt64ApplTypSpecificFilterInfoOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_SInt64ApplTypSpecificFilterInfoOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_Float32ApplTypSpecificFilterInfoOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_Float64ApplTypSpecificFilterInfoOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_UInt8_NApplTypSpecificFilterInfoOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_UInt8_DynApplTypSpecificFilterInfoOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_ZeroBitApplTypSpecificFilterInfoOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsSigGrpArrayFilterInfoApplTypSpecificFilterInfoOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTxFilterInitValueUInt8FilterInitValueOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTxFilterInitValueUInt16FilterInitValueOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTxFilterInitValueUInt32FilterInitValueOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTxFilterInitValueUInt64FilterInitValueOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTxFilterInitValueSInt8FilterInitValueOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTxFilterInitValueSInt16FilterInitValueOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTxFilterInitValueSInt32FilterInitValueOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTxFilterInitValueSInt64FilterInitValueOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTxFilterInitValueFloat32FilterInitValueOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTxFilterInitValueFloat64FilterInitValueOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTxFilterInitValueArrayBasedFilterInitValueOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTxFilterInitValueSigGrpArrayAccessFilterInitValueOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNoFilterInitValueOfFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_Float32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_Float32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_Float32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_Float32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_Float32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_Float32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_Float32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_Float32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_Float64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_Float64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_Float64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_Float64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_Float64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_Float64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_Float64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_Float64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_SInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_SInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_SInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_SInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_SInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_SInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_SInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_SInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_SInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_SInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_SInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_SInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_SInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_SInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_SInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_SInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_SInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_SInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_SInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_SInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_SInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_SInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_SInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_SInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_SInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_SInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_SInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_SInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_SInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_SInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_SInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_SInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_UInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_UInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_UInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_UInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_UInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_UInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_UInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_UInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_UInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_UInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_UInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_UInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_UInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_UInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_UInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_UInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_UInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_UInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_UInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_UInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_UInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_UInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_UInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_UInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_UInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_UInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_UInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_UInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_UInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_UInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_UInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_UInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_UInt8_Dyn(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_UInt8_Dyn(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_UInt8_Dyn(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_UInt8_Dyn(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_UInt8_Dyn(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_UInt8_Dyn(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_UInt8_Dyn(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_UInt8_Dyn(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_UInt8_N(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_UInt8_N(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_UInt8_N(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_UInt8_N(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_UInt8_N(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_UInt8_N(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_UInt8_N(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_UInt8_N(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_ZeroBit(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_ZeroBit(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_ZeroBit(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_ZeroBit(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_ZeroBit(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_ZeroBit(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_ZeroBit(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_ZeroBit(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfSigGrpArrayFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfSigGrpArrayFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfSigGrpArrayFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfSigGrpArrayFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfSigGrpArrayFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfSigGrpArrayFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfSigGrpArrayFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfSigGrpArrayFilterInfo(void);
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
COM_LOCAL_INLINE FUNC(Com_SizeOfArrayBasedFilterMaskType, COM_CODE) Com_GetSizeOfArrayBasedFilterMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfArrayBasedFilterMaskType) Com_GetSizeOfArrayBasedFilterMaskOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfArrayBasedFilterValueXType, COM_CODE) Com_GetSizeOfArrayBasedFilterValueX(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfArrayBasedFilterValueXType) Com_GetSizeOfArrayBasedFilterValueXOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfoType, COM_CODE) Com_GetSizeOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfFilterInfoType) Com_GetSizeOfFilterInfoOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_Float32Type, COM_CODE) Com_GetSizeOfFilterInfo_Float32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfFilterInfo_Float32Type) Com_GetSizeOfFilterInfo_Float32OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_Float64Type, COM_CODE) Com_GetSizeOfFilterInfo_Float64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfFilterInfo_Float64Type) Com_GetSizeOfFilterInfo_Float64OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_SInt16Type, COM_CODE) Com_GetSizeOfFilterInfo_SInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfFilterInfo_SInt16Type) Com_GetSizeOfFilterInfo_SInt16OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_SInt32Type, COM_CODE) Com_GetSizeOfFilterInfo_SInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfFilterInfo_SInt32Type) Com_GetSizeOfFilterInfo_SInt32OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_SInt64Type, COM_CODE) Com_GetSizeOfFilterInfo_SInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfFilterInfo_SInt64Type) Com_GetSizeOfFilterInfo_SInt64OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_SInt8Type, COM_CODE) Com_GetSizeOfFilterInfo_SInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfFilterInfo_SInt8Type) Com_GetSizeOfFilterInfo_SInt8OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_UInt16Type, COM_CODE) Com_GetSizeOfFilterInfo_UInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfFilterInfo_UInt16Type) Com_GetSizeOfFilterInfo_UInt16OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_UInt32Type, COM_CODE) Com_GetSizeOfFilterInfo_UInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfFilterInfo_UInt32Type) Com_GetSizeOfFilterInfo_UInt32OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_UInt64Type, COM_CODE) Com_GetSizeOfFilterInfo_UInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfFilterInfo_UInt64Type) Com_GetSizeOfFilterInfo_UInt64OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_UInt8Type, COM_CODE) Com_GetSizeOfFilterInfo_UInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfFilterInfo_UInt8Type) Com_GetSizeOfFilterInfo_UInt8OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_UInt8_DynType, COM_CODE) Com_GetSizeOfFilterInfo_UInt8_Dyn(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfFilterInfo_UInt8_DynType) Com_GetSizeOfFilterInfo_UInt8_DynOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_UInt8_NType, COM_CODE) Com_GetSizeOfFilterInfo_UInt8_N(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfFilterInfo_UInt8_NType) Com_GetSizeOfFilterInfo_UInt8_NOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfFilterInfo_ZeroBitType, COM_CODE) Com_GetSizeOfFilterInfo_ZeroBit(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfFilterInfo_ZeroBitType) Com_GetSizeOfFilterInfo_ZeroBitOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfSigGrpArrayFilterInfoType, COM_CODE) Com_GetSizeOfSigGrpArrayFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfSigGrpArrayFilterInfoType) Com_GetSizeOfSigGrpArrayFilterInfoOfPCConfig();
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
COM_LOCAL_INLINE FUNC(Com_ArrayBasedFilterMaskType, COM_CODE) Com_GetArrayBasedFilterMask(Com_ArrayBasedFilterMaskIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ArrayBasedFilterMaskType) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_ArrayBasedFilterValueXType, COM_CODE) Com_GetArrayBasedFilterValueX(Com_ArrayBasedFilterValueXIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ArrayBasedFilterValueXType) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_ApplTypSpecificFilterInfoIdxOfFilterInfoType, COM_CODE) Com_GetApplTypSpecificFilterInfoIdxOfFilterInfo(Com_FilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ApplTypSpecificFilterInfoIdxOfFilterInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_ApplTypSpecificFilterInfoOfFilterInfoType, COM_CODE) Com_GetApplTypSpecificFilterInfoOfFilterInfo(Com_FilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ApplTypSpecificFilterInfoOfFilterInfoType) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_FilterInitValueEndIdxOfFilterInfoType, COM_CODE) Com_GetFilterInitValueEndIdxOfFilterInfo(Com_FilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterInitValueEndIdxOfFilterInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterInitValueLengthOfFilterInfoType, COM_CODE) Com_GetFilterInitValueLengthOfFilterInfo(Com_FilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterInitValueLengthOfFilterInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterInitValueOfFilterInfoType, COM_CODE) Com_GetFilterInitValueOfFilterInfo(Com_FilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterInitValueOfFilterInfoType) (COM_NO_FILTERINITVALUEOFFILTERINFO);
}
COM_LOCAL_INLINE FUNC(Com_FilterInitValueStartIdxOfFilterInfoType, COM_CODE) Com_GetFilterInitValueStartIdxOfFilterInfo(Com_FilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterInitValueStartIdxOfFilterInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterInitValueUsedOfFilterInfoType, COM_CODE) Com_IsFilterInitValueUsedOfFilterInfo(Com_FilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterInitValueUsedOfFilterInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoIdxOfFilterInfoType, COM_CODE) Com_GetRxTOutInfoIdxOfFilterInfo(Com_FilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxTOutInfoIdxOfFilterInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_RxTOutInfoUsedOfFilterInfoType, COM_CODE) Com_IsRxTOutInfoUsedOfFilterInfo(Com_FilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxTOutInfoUsedOfFilterInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_Float32Type, COM_CODE) Com_GetFilterAlgoOfFilterInfo_Float32(Com_FilterInfo_Float32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterAlgoOfFilterInfo_Float32Type) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_Float32Type, COM_CODE) Com_GetFilterMaskOfFilterInfo_Float32(Com_FilterInfo_Float32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaskOfFilterInfo_Float32Type) (0x00000000u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_Float32Type, COM_CODE) Com_GetFilterMaxOfFilterInfo_Float32(Com_FilterInfo_Float32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaxOfFilterInfo_Float32Type) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_Float32Type, COM_CODE) Com_GetFilterMinOfFilterInfo_Float32(Com_FilterInfo_Float32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMinOfFilterInfo_Float32Type) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_Float32Type, COM_CODE) Com_GetFilterXOfFilterInfo_Float32(Com_FilterInfo_Float32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterXOfFilterInfo_Float32Type) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_Float64Type, COM_CODE) Com_GetFilterAlgoOfFilterInfo_Float64(Com_FilterInfo_Float64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterAlgoOfFilterInfo_Float64Type) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_Float64Type, COM_CODE) Com_GetFilterMaskOfFilterInfo_Float64(Com_FilterInfo_Float64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaskOfFilterInfo_Float64Type) (0x0000000000000000uLL);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_Float64Type, COM_CODE) Com_GetFilterMaxOfFilterInfo_Float64(Com_FilterInfo_Float64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaxOfFilterInfo_Float64Type) (0uLL);
}
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_Float64Type, COM_CODE) Com_GetFilterMinOfFilterInfo_Float64(Com_FilterInfo_Float64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMinOfFilterInfo_Float64Type) (0uLL);
}
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_Float64Type, COM_CODE) Com_GetFilterXOfFilterInfo_Float64(Com_FilterInfo_Float64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterXOfFilterInfo_Float64Type) (0uLL);
}
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_SInt16Type, COM_CODE) Com_GetFilterAlgoOfFilterInfo_SInt16(Com_FilterInfo_SInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterAlgoOfFilterInfo_SInt16Type) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_SInt16Type, COM_CODE) Com_GetFilterMaskOfFilterInfo_SInt16(Com_FilterInfo_SInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaskOfFilterInfo_SInt16Type) (0x0000u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_SInt16Type, COM_CODE) Com_GetFilterMaxOfFilterInfo_SInt16(Com_FilterInfo_SInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaxOfFilterInfo_SInt16Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_SInt16Type, COM_CODE) Com_GetFilterMinOfFilterInfo_SInt16(Com_FilterInfo_SInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMinOfFilterInfo_SInt16Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_SInt16Type, COM_CODE) Com_GetFilterXOfFilterInfo_SInt16(Com_FilterInfo_SInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterXOfFilterInfo_SInt16Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_SInt32Type, COM_CODE) Com_GetFilterAlgoOfFilterInfo_SInt32(Com_FilterInfo_SInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterAlgoOfFilterInfo_SInt32Type) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_SInt32Type, COM_CODE) Com_GetFilterMaskOfFilterInfo_SInt32(Com_FilterInfo_SInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaskOfFilterInfo_SInt32Type) (0x00000000u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_SInt32Type, COM_CODE) Com_GetFilterMaxOfFilterInfo_SInt32(Com_FilterInfo_SInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaxOfFilterInfo_SInt32Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_SInt32Type, COM_CODE) Com_GetFilterMinOfFilterInfo_SInt32(Com_FilterInfo_SInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMinOfFilterInfo_SInt32Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_SInt32Type, COM_CODE) Com_GetFilterXOfFilterInfo_SInt32(Com_FilterInfo_SInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterXOfFilterInfo_SInt32Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_SInt64Type, COM_CODE) Com_GetFilterAlgoOfFilterInfo_SInt64(Com_FilterInfo_SInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterAlgoOfFilterInfo_SInt64Type) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_SInt64Type, COM_CODE) Com_GetFilterMaskOfFilterInfo_SInt64(Com_FilterInfo_SInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaskOfFilterInfo_SInt64Type) (0x0000000000000000uLL);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_SInt64Type, COM_CODE) Com_GetFilterMaxOfFilterInfo_SInt64(Com_FilterInfo_SInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaxOfFilterInfo_SInt64Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_SInt64Type, COM_CODE) Com_GetFilterMinOfFilterInfo_SInt64(Com_FilterInfo_SInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMinOfFilterInfo_SInt64Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_SInt64Type, COM_CODE) Com_GetFilterXOfFilterInfo_SInt64(Com_FilterInfo_SInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterXOfFilterInfo_SInt64Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_SInt8Type, COM_CODE) Com_GetFilterAlgoOfFilterInfo_SInt8(Com_FilterInfo_SInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterAlgoOfFilterInfo_SInt8Type) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_SInt8Type, COM_CODE) Com_GetFilterMaskOfFilterInfo_SInt8(Com_FilterInfo_SInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaskOfFilterInfo_SInt8Type) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_SInt8Type, COM_CODE) Com_GetFilterMaxOfFilterInfo_SInt8(Com_FilterInfo_SInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaxOfFilterInfo_SInt8Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_SInt8Type, COM_CODE) Com_GetFilterMinOfFilterInfo_SInt8(Com_FilterInfo_SInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMinOfFilterInfo_SInt8Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_SInt8Type, COM_CODE) Com_GetFilterXOfFilterInfo_SInt8(Com_FilterInfo_SInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterXOfFilterInfo_SInt8Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_UInt16Type, COM_CODE) Com_GetFilterAlgoOfFilterInfo_UInt16(Com_FilterInfo_UInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterAlgoOfFilterInfo_UInt16Type) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_UInt16Type, COM_CODE) Com_GetFilterMaskOfFilterInfo_UInt16(Com_FilterInfo_UInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaskOfFilterInfo_UInt16Type) (0x0000u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_UInt16Type, COM_CODE) Com_GetFilterMaxOfFilterInfo_UInt16(Com_FilterInfo_UInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaxOfFilterInfo_UInt16Type) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_UInt16Type, COM_CODE) Com_GetFilterMinOfFilterInfo_UInt16(Com_FilterInfo_UInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMinOfFilterInfo_UInt16Type) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_UInt16Type, COM_CODE) Com_GetFilterXOfFilterInfo_UInt16(Com_FilterInfo_UInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterXOfFilterInfo_UInt16Type) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_UInt32Type, COM_CODE) Com_GetFilterAlgoOfFilterInfo_UInt32(Com_FilterInfo_UInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterAlgoOfFilterInfo_UInt32Type) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_UInt32Type, COM_CODE) Com_GetFilterMaskOfFilterInfo_UInt32(Com_FilterInfo_UInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaskOfFilterInfo_UInt32Type) (0x00000000u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_UInt32Type, COM_CODE) Com_GetFilterMaxOfFilterInfo_UInt32(Com_FilterInfo_UInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaxOfFilterInfo_UInt32Type) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_UInt32Type, COM_CODE) Com_GetFilterMinOfFilterInfo_UInt32(Com_FilterInfo_UInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMinOfFilterInfo_UInt32Type) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_UInt32Type, COM_CODE) Com_GetFilterXOfFilterInfo_UInt32(Com_FilterInfo_UInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterXOfFilterInfo_UInt32Type) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_UInt64Type, COM_CODE) Com_GetFilterAlgoOfFilterInfo_UInt64(Com_FilterInfo_UInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterAlgoOfFilterInfo_UInt64Type) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_UInt64Type, COM_CODE) Com_GetFilterMaskOfFilterInfo_UInt64(Com_FilterInfo_UInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaskOfFilterInfo_UInt64Type) (0x0000000000000000uLL);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_UInt64Type, COM_CODE) Com_GetFilterMaxOfFilterInfo_UInt64(Com_FilterInfo_UInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaxOfFilterInfo_UInt64Type) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_UInt64Type, COM_CODE) Com_GetFilterMinOfFilterInfo_UInt64(Com_FilterInfo_UInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMinOfFilterInfo_UInt64Type) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_UInt64Type, COM_CODE) Com_GetFilterXOfFilterInfo_UInt64(Com_FilterInfo_UInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterXOfFilterInfo_UInt64Type) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_UInt8Type, COM_CODE) Com_GetFilterAlgoOfFilterInfo_UInt8(Com_FilterInfo_UInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterAlgoOfFilterInfo_UInt8Type) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_UInt8Type, COM_CODE) Com_GetFilterMaskOfFilterInfo_UInt8(Com_FilterInfo_UInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaskOfFilterInfo_UInt8Type) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_UInt8Type, COM_CODE) Com_GetFilterMaxOfFilterInfo_UInt8(Com_FilterInfo_UInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaxOfFilterInfo_UInt8Type) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_UInt8Type, COM_CODE) Com_GetFilterMinOfFilterInfo_UInt8(Com_FilterInfo_UInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMinOfFilterInfo_UInt8Type) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_UInt8Type, COM_CODE) Com_GetFilterXOfFilterInfo_UInt8(Com_FilterInfo_UInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterXOfFilterInfo_UInt8Type) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_UInt8_DynType, COM_CODE) Com_GetFilterAlgoOfFilterInfo_UInt8_Dyn(Com_FilterInfo_UInt8_DynIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterAlgoOfFilterInfo_UInt8_DynType) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_UInt8_DynType, COM_CODE) Com_GetFilterMaskOfFilterInfo_UInt8_Dyn(Com_FilterInfo_UInt8_DynIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaskOfFilterInfo_UInt8_DynType) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_UInt8_DynType, COM_CODE) Com_GetFilterMaxOfFilterInfo_UInt8_Dyn(Com_FilterInfo_UInt8_DynIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaxOfFilterInfo_UInt8_DynType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_UInt8_DynType, COM_CODE) Com_GetFilterMinOfFilterInfo_UInt8_Dyn(Com_FilterInfo_UInt8_DynIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMinOfFilterInfo_UInt8_DynType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_UInt8_DynType, COM_CODE) Com_GetFilterXOfFilterInfo_UInt8_Dyn(Com_FilterInfo_UInt8_DynIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterXOfFilterInfo_UInt8_DynType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_UInt8_NType, COM_CODE) Com_GetFilterAlgoOfFilterInfo_UInt8_N(Com_FilterInfo_UInt8_NIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterAlgoOfFilterInfo_UInt8_NType) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_UInt8_NType, COM_CODE) Com_GetFilterMaskOfFilterInfo_UInt8_N(Com_FilterInfo_UInt8_NIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaskOfFilterInfo_UInt8_NType) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_UInt8_NType, COM_CODE) Com_GetFilterMaxOfFilterInfo_UInt8_N(Com_FilterInfo_UInt8_NIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaxOfFilterInfo_UInt8_NType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_UInt8_NType, COM_CODE) Com_GetFilterMinOfFilterInfo_UInt8_N(Com_FilterInfo_UInt8_NIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMinOfFilterInfo_UInt8_NType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_UInt8_NType, COM_CODE) Com_GetFilterXOfFilterInfo_UInt8_N(Com_FilterInfo_UInt8_NIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterXOfFilterInfo_UInt8_NType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfFilterInfo_ZeroBitType, COM_CODE) Com_GetFilterAlgoOfFilterInfo_ZeroBit(Com_FilterInfo_ZeroBitIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterAlgoOfFilterInfo_ZeroBitType) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaskOfFilterInfo_ZeroBitType, COM_CODE) Com_GetFilterMaskOfFilterInfo_ZeroBit(Com_FilterInfo_ZeroBitIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaskOfFilterInfo_ZeroBitType) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMaxOfFilterInfo_ZeroBitType, COM_CODE) Com_GetFilterMaxOfFilterInfo_ZeroBit(Com_FilterInfo_ZeroBitIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMaxOfFilterInfo_ZeroBitType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterMinOfFilterInfo_ZeroBitType, COM_CODE) Com_GetFilterMinOfFilterInfo_ZeroBit(Com_FilterInfo_ZeroBitIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterMinOfFilterInfo_ZeroBitType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterXOfFilterInfo_ZeroBitType, COM_CODE) Com_GetFilterXOfFilterInfo_ZeroBit(Com_FilterInfo_ZeroBitIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterXOfFilterInfo_ZeroBitType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_ArrayBasedFilterMaskEndIdxOfSigGrpArrayFilterInfoType, COM_CODE) Com_GetArrayBasedFilterMaskEndIdxOfSigGrpArrayFilterInfo(Com_SigGrpArrayFilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ArrayBasedFilterMaskEndIdxOfSigGrpArrayFilterInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_ArrayBasedFilterMaskLengthOfSigGrpArrayFilterInfoType, COM_CODE) Com_GetArrayBasedFilterMaskLengthOfSigGrpArrayFilterInfo(Com_SigGrpArrayFilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ArrayBasedFilterMaskLengthOfSigGrpArrayFilterInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_ArrayBasedFilterMaskStartIdxOfSigGrpArrayFilterInfoType, COM_CODE) Com_GetArrayBasedFilterMaskStartIdxOfSigGrpArrayFilterInfo(Com_SigGrpArrayFilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ArrayBasedFilterMaskStartIdxOfSigGrpArrayFilterInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_ArrayBasedFilterMaskUsedOfSigGrpArrayFilterInfoType, COM_CODE) Com_IsArrayBasedFilterMaskUsedOfSigGrpArrayFilterInfo(Com_SigGrpArrayFilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ArrayBasedFilterMaskUsedOfSigGrpArrayFilterInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_ArrayBasedFilterValueXEndIdxOfSigGrpArrayFilterInfoType, COM_CODE) Com_GetArrayBasedFilterValueXEndIdxOfSigGrpArrayFilterInfo(Com_SigGrpArrayFilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ArrayBasedFilterValueXEndIdxOfSigGrpArrayFilterInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_ArrayBasedFilterValueXLengthOfSigGrpArrayFilterInfoType, COM_CODE) Com_GetArrayBasedFilterValueXLengthOfSigGrpArrayFilterInfo(Com_SigGrpArrayFilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ArrayBasedFilterValueXLengthOfSigGrpArrayFilterInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_ArrayBasedFilterValueXStartIdxOfSigGrpArrayFilterInfoType, COM_CODE) Com_GetArrayBasedFilterValueXStartIdxOfSigGrpArrayFilterInfo(Com_SigGrpArrayFilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ArrayBasedFilterValueXStartIdxOfSigGrpArrayFilterInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_ArrayBasedFilterValueXUsedOfSigGrpArrayFilterInfoType, COM_CODE) Com_IsArrayBasedFilterValueXUsedOfSigGrpArrayFilterInfo(Com_SigGrpArrayFilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ArrayBasedFilterValueXUsedOfSigGrpArrayFilterInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_FilterAlgoOfSigGrpArrayFilterInfoType, COM_CODE) Com_GetFilterAlgoOfSigGrpArrayFilterInfo(Com_SigGrpArrayFilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterAlgoOfSigGrpArrayFilterInfoType) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_OffsetInSignalGroupOfSigGrpArrayFilterInfoType, COM_CODE) Com_GetOffsetInSignalGroupOfSigGrpArrayFilterInfo(Com_SigGrpArrayFilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_OffsetInSignalGroupOfSigGrpArrayFilterInfoType) (0u);
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
COM_LOCAL_INLINE FUNC(Com_ArrayBasedFilterMaskPtrType, COM_CODE) Com_GetAddrArrayBasedFilterMask(Com_ArrayBasedFilterMaskIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ArrayBasedFilterMaskPtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_ArrayBasedFilterValueXPtrType, COM_CODE) Com_GetAddrArrayBasedFilterValueX(Com_ArrayBasedFilterValueXIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ArrayBasedFilterValueXPtrType) (NULL_PTR);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasArrayBasedFilterMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasArrayBasedFilterValueX(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasApplTypSpecificFilterInfoIdxOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasApplTypSpecificFilterInfoOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInitValueEndIdxOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInitValueLengthOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInitValueOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInitValueStartIdxOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInitValueUsedOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoIdxOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfoUsedOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_Float32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_Float32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_Float32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_Float32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_Float32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_Float32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_Float64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_Float64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_Float64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_Float64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_Float64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_Float64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_SInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_SInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_SInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_SInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_SInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_SInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_SInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_SInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_SInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_SInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_SInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_SInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_SInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_SInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_SInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_SInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_SInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_SInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_SInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_SInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_SInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_SInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_SInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_SInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_UInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_UInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_UInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_UInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_UInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_UInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_UInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_UInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_UInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_UInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_UInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_UInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_UInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_UInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_UInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_UInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_UInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_UInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_UInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_UInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_UInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_UInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_UInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_UInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_UInt8_Dyn(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_UInt8_Dyn(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_UInt8_Dyn(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_UInt8_Dyn(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_UInt8_Dyn(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_UInt8_Dyn(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_UInt8_N(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_UInt8_N(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_UInt8_N(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_UInt8_N(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_UInt8_N(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_UInt8_N(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfo_ZeroBit(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfFilterInfo_ZeroBit(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaskOfFilterInfo_ZeroBit(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMaxOfFilterInfo_ZeroBit(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterMinOfFilterInfo_ZeroBit(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterXOfFilterInfo_ZeroBit(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSigGrpArrayFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasArrayBasedFilterMaskEndIdxOfSigGrpArrayFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasArrayBasedFilterMaskLengthOfSigGrpArrayFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasArrayBasedFilterMaskStartIdxOfSigGrpArrayFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasArrayBasedFilterMaskUsedOfSigGrpArrayFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasArrayBasedFilterValueXEndIdxOfSigGrpArrayFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasArrayBasedFilterValueXLengthOfSigGrpArrayFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasArrayBasedFilterValueXStartIdxOfSigGrpArrayFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasArrayBasedFilterValueXUsedOfSigGrpArrayFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterAlgoOfSigGrpArrayFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasOffsetInSignalGroupOfSigGrpArrayFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfArrayBasedFilterMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfArrayBasedFilterValueX(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_Float32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_Float64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_SInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_SInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_SInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_SInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_UInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_UInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_UInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_UInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_UInt8_Dyn(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_UInt8_N(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfFilterInfo_ZeroBit(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfSigGrpArrayFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_UInt8ApplTypSpecificFilterInfoOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_SInt8ApplTypSpecificFilterInfoOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_UInt16ApplTypSpecificFilterInfoOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_SInt16ApplTypSpecificFilterInfoOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_UInt32ApplTypSpecificFilterInfoOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_SInt32ApplTypSpecificFilterInfoOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_UInt64ApplTypSpecificFilterInfoOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_SInt64ApplTypSpecificFilterInfoOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_Float32ApplTypSpecificFilterInfoOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_Float64ApplTypSpecificFilterInfoOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_UInt8_NApplTypSpecificFilterInfoOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_UInt8_DynApplTypSpecificFilterInfoOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsFilterInfo_ZeroBitApplTypSpecificFilterInfoOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsSigGrpArrayFilterInfoApplTypSpecificFilterInfoOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTxFilterInitValueUInt8FilterInitValueOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTxFilterInitValueUInt16FilterInitValueOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTxFilterInitValueUInt32FilterInitValueOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTxFilterInitValueUInt64FilterInitValueOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTxFilterInitValueSInt8FilterInitValueOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTxFilterInitValueSInt16FilterInitValueOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTxFilterInitValueSInt32FilterInitValueOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTxFilterInitValueSInt64FilterInitValueOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTxFilterInitValueFloat32FilterInitValueOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTxFilterInitValueFloat64FilterInitValueOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTxFilterInitValueArrayBasedFilterInitValueOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTxFilterInitValueSigGrpArrayAccessFilterInitValueOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNoFilterInitValueOfFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_Float32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_Float32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_Float32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_Float32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_Float32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_Float32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_Float32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_Float32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_Float64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_Float64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_Float64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_Float64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_Float64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_Float64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_Float64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_Float64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_SInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_SInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_SInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_SInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_SInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_SInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_SInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_SInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_SInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_SInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_SInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_SInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_SInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_SInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_SInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_SInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_SInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_SInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_SInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_SInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_SInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_SInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_SInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_SInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_SInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_SInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_SInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_SInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_SInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_SInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_SInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_SInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_UInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_UInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_UInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_UInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_UInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_UInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_UInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_UInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_UInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_UInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_UInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_UInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_UInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_UInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_UInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_UInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_UInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_UInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_UInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_UInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_UInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_UInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_UInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_UInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_UInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_UInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_UInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_UInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_UInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_UInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_UInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_UInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_UInt8_Dyn(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_UInt8_Dyn(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_UInt8_Dyn(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_UInt8_Dyn(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_UInt8_Dyn(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_UInt8_Dyn(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_UInt8_Dyn(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_UInt8_Dyn(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_UInt8_N(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_UInt8_N(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_UInt8_N(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_UInt8_N(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_UInt8_N(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_UInt8_N(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_UInt8_N(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_UInt8_N(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfFilterInfo_ZeroBit(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfFilterInfo_ZeroBit(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfFilterInfo_ZeroBit(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfFilterInfo_ZeroBit(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfFilterInfo_ZeroBit(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfFilterInfo_ZeroBit(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfFilterInfo_ZeroBit(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfFilterInfo_ZeroBit(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsALWAYSFilterAlgoOfSigGrpArrayFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEVERFilterAlgoOfSigGrpArrayFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_MASKED_OLDFilterAlgoOfSigGrpArrayFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_DIFFERS_XFilterAlgoOfSigGrpArrayFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsMASKED_NEW_EQUALS_XFilterAlgoOfSigGrpArrayFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_OUTSIDEFilterAlgoOfSigGrpArrayFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNEW_IS_WITHINFilterAlgoOfSigGrpArrayFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsNONEFilterAlgoOfSigGrpArrayFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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

#endif  /* COM_CFG_FILTERDATA_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cfg_FilterData.h
**********************************************************************************************************************/

