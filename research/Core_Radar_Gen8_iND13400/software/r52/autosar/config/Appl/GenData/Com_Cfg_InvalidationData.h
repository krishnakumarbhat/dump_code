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
 *              File: Com_Cfg_InvalidationData.h
 *   Generation Time: 2026-04-02 15:10:31
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

#if !defined (COM_CFG_INVALIDATIONDATA_H)
# define COM_CFG_INVALIDATIONDATA_H

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
COM_LOCAL_INLINE FUNC(Com_SizeOfInvValueArrayBasedType, COM_CODE) Com_GetSizeOfInvValueArrayBased(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfInvValueFloat32Type, COM_CODE) Com_GetSizeOfInvValueFloat32(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfInvValueFloat64Type, COM_CODE) Com_GetSizeOfInvValueFloat64(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfInvValueSInt16Type, COM_CODE) Com_GetSizeOfInvValueSInt16(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfInvValueSInt32Type, COM_CODE) Com_GetSizeOfInvValueSInt32(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfInvValueSInt64Type, COM_CODE) Com_GetSizeOfInvValueSInt64(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfInvValueSInt8Type, COM_CODE) Com_GetSizeOfInvValueSInt8(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfInvValueSigGrpArrayAccessType, COM_CODE) Com_GetSizeOfInvValueSigGrpArrayAccess(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfInvValueUInt16Type, COM_CODE) Com_GetSizeOfInvValueUInt16(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfInvValueUInt32Type, COM_CODE) Com_GetSizeOfInvValueUInt32(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfInvValueUInt64Type, COM_CODE) Com_GetSizeOfInvValueUInt64(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfInvValueUInt8Type, COM_CODE) Com_GetSizeOfInvValueUInt8(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxInvalidationInfoType, COM_CODE) Com_GetSizeOfRxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxInvalidationInfoType, COM_CODE) Com_GetSizeOfTxInvalidationInfo(void);
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
COM_LOCAL_INLINE FUNC(Com_InvValueArrayBasedType, COM_CODE) Com_GetInvValueArrayBased(Com_InvValueArrayBasedIterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueFloat32Type, COM_CODE) Com_GetInvValueFloat32(Com_InvValueFloat32IterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueFloat64Type, COM_CODE) Com_GetInvValueFloat64(Com_InvValueFloat64IterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueSInt16Type, COM_CODE) Com_GetInvValueSInt16(Com_InvValueSInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueSInt32Type, COM_CODE) Com_GetInvValueSInt32(Com_InvValueSInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueSInt64Type, COM_CODE) Com_GetInvValueSInt64(Com_InvValueSInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueSInt8Type, COM_CODE) Com_GetInvValueSInt8(Com_InvValueSInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueSigGrpArrayAccessType, COM_CODE) Com_GetInvValueSigGrpArrayAccess(Com_InvValueSigGrpArrayAccessIterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueUInt16Type, COM_CODE) Com_GetInvValueUInt16(Com_InvValueUInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueUInt32Type, COM_CODE) Com_GetInvValueUInt32(Com_InvValueUInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueUInt64Type, COM_CODE) Com_GetInvValueUInt64(Com_InvValueUInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueUInt8Type, COM_CODE) Com_GetInvValueUInt8(Com_InvValueUInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueEndIdxOfRxInvalidationInfoType, COM_CODE) Com_GetInvValueEndIdxOfRxInvalidationInfo(Com_RxInvalidationInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueLengthOfRxInvalidationInfoType, COM_CODE) Com_GetInvValueLengthOfRxInvalidationInfo(Com_RxInvalidationInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueOfRxInvalidationInfoType, COM_CODE) Com_GetInvValueOfRxInvalidationInfo(Com_RxInvalidationInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueStartIdxOfRxInvalidationInfoType, COM_CODE) Com_GetInvValueStartIdxOfRxInvalidationInfo(Com_RxInvalidationInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ReportingInvalidNotificationIdxOfRxInvalidationInfoType, COM_CODE) Com_GetReportingInvalidNotificationIdxOfRxInvalidationInfo(Com_RxInvalidationInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ReportingInvalidNotificationUsedOfRxInvalidationInfoType, COM_CODE) Com_IsReportingInvalidNotificationUsedOfRxInvalidationInfo(Com_RxInvalidationInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoIdxOfRxInvalidationInfoType, COM_CODE) Com_GetRxAccessInfoIdxOfRxInvalidationInfo(Com_RxInvalidationInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueEndIdxOfTxInvalidationInfoType, COM_CODE) Com_GetInvValueEndIdxOfTxInvalidationInfo(Com_TxInvalidationInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueLengthOfTxInvalidationInfoType, COM_CODE) Com_GetInvValueLengthOfTxInvalidationInfo(Com_TxInvalidationInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueOfTxInvalidationInfoType, COM_CODE) Com_GetInvValueOfTxInvalidationInfo(Com_TxInvalidationInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueStartIdxOfTxInvalidationInfoType, COM_CODE) Com_GetInvValueStartIdxOfTxInvalidationInfo(Com_TxInvalidationInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxAccessInfoIdxOfTxInvalidationInfoType, COM_CODE) Com_GetTxAccessInfoIdxOfTxInvalidationInfo(Com_TxInvalidationInfoIterType Index);
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
COM_LOCAL_INLINE FUNC(Com_InvValueArrayBasedPtrType, COM_CODE) Com_GetAddrInvValueArrayBased(Com_InvValueArrayBasedIterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueFloat32PtrType, COM_CODE) Com_GetAddrInvValueFloat32(Com_InvValueFloat32IterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueFloat64PtrType, COM_CODE) Com_GetAddrInvValueFloat64(Com_InvValueFloat64IterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueSInt16PtrType, COM_CODE) Com_GetAddrInvValueSInt16(Com_InvValueSInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueSInt32PtrType, COM_CODE) Com_GetAddrInvValueSInt32(Com_InvValueSInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueSInt64PtrType, COM_CODE) Com_GetAddrInvValueSInt64(Com_InvValueSInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueSInt8PtrType, COM_CODE) Com_GetAddrInvValueSInt8(Com_InvValueSInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueSigGrpArrayAccessPtrType, COM_CODE) Com_GetAddrInvValueSigGrpArrayAccess(Com_InvValueSigGrpArrayAccessIterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueUInt16PtrType, COM_CODE) Com_GetAddrInvValueUInt16(Com_InvValueUInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueUInt32PtrType, COM_CODE) Com_GetAddrInvValueUInt32(Com_InvValueUInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueUInt64PtrType, COM_CODE) Com_GetAddrInvValueUInt64(Com_InvValueUInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_InvValueUInt8PtrType, COM_CODE) Com_GetAddrInvValueUInt8(Com_InvValueUInt8IterType Index);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueArrayBased(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueFloat32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueFloat64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueSInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueSInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueSInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueSInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueSigGrpArrayAccess(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueUInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueUInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueUInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueUInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueEndIdxOfRxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueLengthOfRxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueOfRxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueStartIdxOfRxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingInvalidNotificationIdxOfRxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingInvalidNotificationUsedOfRxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoIdxOfRxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfInvValueArrayBased(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfInvValueFloat32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfInvValueFloat64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfInvValueSInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfInvValueSInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfInvValueSInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfInvValueSInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfInvValueSigGrpArrayAccess(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfInvValueUInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfInvValueUInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfInvValueUInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfInvValueUInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueEndIdxOfTxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueLengthOfTxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueOfTxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueStartIdxOfTxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxAccessInfoIdxOfTxInvalidationInfo(void);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueUInt8InvValueOfRxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueUInt16InvValueOfRxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueUInt32InvValueOfRxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueUInt64InvValueOfRxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueSInt8InvValueOfRxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueSInt16InvValueOfRxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueSInt32InvValueOfRxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueSInt64InvValueOfRxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueFloat32InvValueOfRxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueFloat64InvValueOfRxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueArrayBasedInvValueOfRxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueUInt8InvValueOfTxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueUInt16InvValueOfTxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueUInt32InvValueOfTxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueUInt64InvValueOfTxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueSInt8InvValueOfTxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueSInt16InvValueOfTxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueSInt32InvValueOfTxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueSInt64InvValueOfTxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueFloat32InvValueOfTxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueFloat64InvValueOfTxInvalidationInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueArrayBasedInvValueOfTxInvalidationInfo(void);
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
COM_LOCAL_INLINE FUNC(Com_SizeOfInvValueArrayBasedType, COM_CODE) Com_GetSizeOfInvValueArrayBased(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfInvValueArrayBasedType) Com_GetSizeOfInvValueArrayBasedOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfInvValueFloat32Type, COM_CODE) Com_GetSizeOfInvValueFloat32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfInvValueFloat32Type) Com_GetSizeOfInvValueFloat32OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfInvValueFloat64Type, COM_CODE) Com_GetSizeOfInvValueFloat64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfInvValueFloat64Type) Com_GetSizeOfInvValueFloat64OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfInvValueSInt16Type, COM_CODE) Com_GetSizeOfInvValueSInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfInvValueSInt16Type) Com_GetSizeOfInvValueSInt16OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfInvValueSInt32Type, COM_CODE) Com_GetSizeOfInvValueSInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfInvValueSInt32Type) Com_GetSizeOfInvValueSInt32OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfInvValueSInt64Type, COM_CODE) Com_GetSizeOfInvValueSInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfInvValueSInt64Type) Com_GetSizeOfInvValueSInt64OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfInvValueSInt8Type, COM_CODE) Com_GetSizeOfInvValueSInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfInvValueSInt8Type) Com_GetSizeOfInvValueSInt8OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfInvValueSigGrpArrayAccessType, COM_CODE) Com_GetSizeOfInvValueSigGrpArrayAccess(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfInvValueSigGrpArrayAccessType) Com_GetSizeOfInvValueSigGrpArrayAccessOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfInvValueUInt16Type, COM_CODE) Com_GetSizeOfInvValueUInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfInvValueUInt16Type) Com_GetSizeOfInvValueUInt16OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfInvValueUInt32Type, COM_CODE) Com_GetSizeOfInvValueUInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfInvValueUInt32Type) Com_GetSizeOfInvValueUInt32OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfInvValueUInt64Type, COM_CODE) Com_GetSizeOfInvValueUInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfInvValueUInt64Type) Com_GetSizeOfInvValueUInt64OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfInvValueUInt8Type, COM_CODE) Com_GetSizeOfInvValueUInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfInvValueUInt8Type) Com_GetSizeOfInvValueUInt8OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxInvalidationInfoType, COM_CODE) Com_GetSizeOfRxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxInvalidationInfoType) Com_GetSizeOfRxInvalidationInfoOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxInvalidationInfoType, COM_CODE) Com_GetSizeOfTxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxInvalidationInfoType) Com_GetSizeOfTxInvalidationInfoOfPCConfig();
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
COM_LOCAL_INLINE FUNC(Com_InvValueArrayBasedType, COM_CODE) Com_GetInvValueArrayBased(Com_InvValueArrayBasedIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueArrayBasedType) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_InvValueFloat32Type, COM_CODE) Com_GetInvValueFloat32(Com_InvValueFloat32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueFloat32Type) (0.0F);
}
COM_LOCAL_INLINE FUNC(Com_InvValueFloat64Type, COM_CODE) Com_GetInvValueFloat64(Com_InvValueFloat64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueFloat64Type) (0.0);
}
COM_LOCAL_INLINE FUNC(Com_InvValueSInt16Type, COM_CODE) Com_GetInvValueSInt16(Com_InvValueSInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueSInt16Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_InvValueSInt32Type, COM_CODE) Com_GetInvValueSInt32(Com_InvValueSInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueSInt32Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_InvValueSInt64Type, COM_CODE) Com_GetInvValueSInt64(Com_InvValueSInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueSInt64Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_InvValueSInt8Type, COM_CODE) Com_GetInvValueSInt8(Com_InvValueSInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueSInt8Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_InvValueSigGrpArrayAccessType, COM_CODE) Com_GetInvValueSigGrpArrayAccess(Com_InvValueSigGrpArrayAccessIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueSigGrpArrayAccessType) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_InvValueUInt16Type, COM_CODE) Com_GetInvValueUInt16(Com_InvValueUInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueUInt16Type) (0x0000u);
}
COM_LOCAL_INLINE FUNC(Com_InvValueUInt32Type, COM_CODE) Com_GetInvValueUInt32(Com_InvValueUInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueUInt32Type) (0x00000000u);
}
COM_LOCAL_INLINE FUNC(Com_InvValueUInt64Type, COM_CODE) Com_GetInvValueUInt64(Com_InvValueUInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueUInt64Type) (0x0000000000000000uLL);
}
COM_LOCAL_INLINE FUNC(Com_InvValueUInt8Type, COM_CODE) Com_GetInvValueUInt8(Com_InvValueUInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueUInt8Type) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_InvValueEndIdxOfRxInvalidationInfoType, COM_CODE) Com_GetInvValueEndIdxOfRxInvalidationInfo(Com_RxInvalidationInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueEndIdxOfRxInvalidationInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_InvValueLengthOfRxInvalidationInfoType, COM_CODE) Com_GetInvValueLengthOfRxInvalidationInfo(Com_RxInvalidationInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueLengthOfRxInvalidationInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_InvValueOfRxInvalidationInfoType, COM_CODE) Com_GetInvValueOfRxInvalidationInfo(Com_RxInvalidationInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueOfRxInvalidationInfoType) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_InvValueStartIdxOfRxInvalidationInfoType, COM_CODE) Com_GetInvValueStartIdxOfRxInvalidationInfo(Com_RxInvalidationInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueStartIdxOfRxInvalidationInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_ReportingInvalidNotificationIdxOfRxInvalidationInfoType, COM_CODE) Com_GetReportingInvalidNotificationIdxOfRxInvalidationInfo(Com_RxInvalidationInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ReportingInvalidNotificationIdxOfRxInvalidationInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_ReportingInvalidNotificationUsedOfRxInvalidationInfoType, COM_CODE) Com_IsReportingInvalidNotificationUsedOfRxInvalidationInfo(Com_RxInvalidationInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ReportingInvalidNotificationUsedOfRxInvalidationInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoIdxOfRxInvalidationInfoType, COM_CODE) Com_GetRxAccessInfoIdxOfRxInvalidationInfo(Com_RxInvalidationInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxAccessInfoIdxOfRxInvalidationInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_InvValueEndIdxOfTxInvalidationInfoType, COM_CODE) Com_GetInvValueEndIdxOfTxInvalidationInfo(Com_TxInvalidationInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueEndIdxOfTxInvalidationInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_InvValueLengthOfTxInvalidationInfoType, COM_CODE) Com_GetInvValueLengthOfTxInvalidationInfo(Com_TxInvalidationInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueLengthOfTxInvalidationInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_InvValueOfTxInvalidationInfoType, COM_CODE) Com_GetInvValueOfTxInvalidationInfo(Com_TxInvalidationInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueOfTxInvalidationInfoType) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_InvValueStartIdxOfTxInvalidationInfoType, COM_CODE) Com_GetInvValueStartIdxOfTxInvalidationInfo(Com_TxInvalidationInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueStartIdxOfTxInvalidationInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxAccessInfoIdxOfTxInvalidationInfoType, COM_CODE) Com_GetTxAccessInfoIdxOfTxInvalidationInfo(Com_TxInvalidationInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxAccessInfoIdxOfTxInvalidationInfoType) (0u);
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
COM_LOCAL_INLINE FUNC(Com_InvValueArrayBasedPtrType, COM_CODE) Com_GetAddrInvValueArrayBased(Com_InvValueArrayBasedIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueArrayBasedPtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_InvValueFloat32PtrType, COM_CODE) Com_GetAddrInvValueFloat32(Com_InvValueFloat32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueFloat32PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_InvValueFloat64PtrType, COM_CODE) Com_GetAddrInvValueFloat64(Com_InvValueFloat64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueFloat64PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_InvValueSInt16PtrType, COM_CODE) Com_GetAddrInvValueSInt16(Com_InvValueSInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueSInt16PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_InvValueSInt32PtrType, COM_CODE) Com_GetAddrInvValueSInt32(Com_InvValueSInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueSInt32PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_InvValueSInt64PtrType, COM_CODE) Com_GetAddrInvValueSInt64(Com_InvValueSInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueSInt64PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_InvValueSInt8PtrType, COM_CODE) Com_GetAddrInvValueSInt8(Com_InvValueSInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueSInt8PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_InvValueSigGrpArrayAccessPtrType, COM_CODE) Com_GetAddrInvValueSigGrpArrayAccess(Com_InvValueSigGrpArrayAccessIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueSigGrpArrayAccessPtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_InvValueUInt16PtrType, COM_CODE) Com_GetAddrInvValueUInt16(Com_InvValueUInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueUInt16PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_InvValueUInt32PtrType, COM_CODE) Com_GetAddrInvValueUInt32(Com_InvValueUInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueUInt32PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_InvValueUInt64PtrType, COM_CODE) Com_GetAddrInvValueUInt64(Com_InvValueUInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueUInt64PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_InvValueUInt8PtrType, COM_CODE) Com_GetAddrInvValueUInt8(Com_InvValueUInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvValueUInt8PtrType) (NULL_PTR);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueArrayBased(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueFloat32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueFloat64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueSInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueSInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueSInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueSInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueSigGrpArrayAccess(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueUInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueUInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueUInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueUInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueEndIdxOfRxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueLengthOfRxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueOfRxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueStartIdxOfRxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingInvalidNotificationIdxOfRxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingInvalidNotificationUsedOfRxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoIdxOfRxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfInvValueArrayBased(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfInvValueFloat32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfInvValueFloat64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfInvValueSInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfInvValueSInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfInvValueSInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfInvValueSInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfInvValueSigGrpArrayAccess(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfInvValueUInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfInvValueUInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfInvValueUInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfInvValueUInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueEndIdxOfTxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueLengthOfTxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueOfTxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvValueStartIdxOfTxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxAccessInfoIdxOfTxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueUInt8InvValueOfRxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueUInt16InvValueOfRxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueUInt32InvValueOfRxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueUInt64InvValueOfRxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueSInt8InvValueOfRxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueSInt16InvValueOfRxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueSInt32InvValueOfRxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueSInt64InvValueOfRxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueFloat32InvValueOfRxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueFloat64InvValueOfRxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueArrayBasedInvValueOfRxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueUInt8InvValueOfTxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueUInt16InvValueOfTxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueUInt32InvValueOfTxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueUInt64InvValueOfTxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueSInt8InvValueOfTxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueSInt16InvValueOfTxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueSInt32InvValueOfTxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueSInt64InvValueOfTxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueFloat32InvValueOfTxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueFloat64InvValueOfTxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsInvValueArrayBasedInvValueOfTxInvalidationInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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

#endif  /* COM_CFG_INVALIDATIONDATA_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cfg_InvalidationData.h
**********************************************************************************************************************/

