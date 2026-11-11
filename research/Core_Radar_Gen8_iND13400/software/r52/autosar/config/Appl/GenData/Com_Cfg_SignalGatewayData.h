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
 *              File: Com_Cfg_SignalGatewayData.h
 *   Generation Time: 2026-04-02 15:10:35
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

#if !defined (COM_CFG_SIGNALGATEWAYDATA_H)
# define COM_CFG_SIGNALGATEWAYDATA_H

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
COM_LOCAL_INLINE FUNC(Com_SizeOfGwEventType, COM_CODE) Com_GetSizeOfGwEvent(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfGwGrpSigMappingType, COM_CODE) Com_GetSizeOfGwGrpSigMapping(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfGwInfoType, COM_CODE) Com_GetSizeOfGwInfo(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfGwSigGrpMappingType, COM_CODE) Com_GetSizeOfGwSigGrpMapping(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfGwSigMappingType, COM_CODE) Com_GetSizeOfGwSigMapping(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfGwSigOrGrpSigTmpBufferInfoType, COM_CODE) Com_GetSizeOfGwSigOrGrpSigTmpBufferInfo(void);
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
COM_LOCAL_INLINE FUNC(Com_GwEventType, COM_CODE) Com_IsGwEvent(Com_GwEventIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwSigOrGrpSigTmpBufferInfoIdxOfGwGrpSigMappingType, COM_CODE) Com_GetGwSigOrGrpSigTmpBufferInfoIdxOfGwGrpSigMapping(Com_GwGrpSigMappingIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwSigOrGrpSigTmpBufferInfoUsedOfGwGrpSigMappingType, COM_CODE) Com_IsGwSigOrGrpSigTmpBufferInfoUsedOfGwGrpSigMapping(Com_GwGrpSigMappingIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoIdxOfGwGrpSigMappingType, COM_CODE) Com_GetRxAccessInfoIdxOfGwGrpSigMapping(Com_GwGrpSigMappingIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxGrpSigInfoIdxOfGwGrpSigMappingType, COM_CODE) Com_GetTxGrpSigInfoIdxOfGwGrpSigMapping(Com_GwGrpSigMappingIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwSigGrpMappingEndIdxOfGwInfoType, COM_CODE) Com_GetGwSigGrpMappingEndIdxOfGwInfo(Com_GwInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwSigGrpMappingStartIdxOfGwInfoType, COM_CODE) Com_GetGwSigGrpMappingStartIdxOfGwInfo(Com_GwInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwSigGrpMappingUsedOfGwInfoType, COM_CODE) Com_IsGwSigGrpMappingUsedOfGwInfo(Com_GwInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwSigMappingEndIdxOfGwInfoType, COM_CODE) Com_GetGwSigMappingEndIdxOfGwInfo(Com_GwInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwSigMappingStartIdxOfGwInfoType, COM_CODE) Com_GetGwSigMappingStartIdxOfGwInfo(Com_GwInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwSigMappingUsedOfGwInfoType, COM_CODE) Com_IsGwSigMappingUsedOfGwInfo(Com_GwInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_CprQueueIdxOfGwSigGrpMappingType, COM_CODE) Com_GetCprQueueIdxOfGwSigGrpMapping(Com_GwSigGrpMappingIterType Index);
COM_LOCAL_INLINE FUNC(Com_CprQueueUsedOfGwSigGrpMappingType, COM_CODE) Com_IsCprQueueUsedOfGwSigGrpMapping(Com_GwSigGrpMappingIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwGrpSigMappingEndIdxOfGwSigGrpMappingType, COM_CODE) Com_GetGwGrpSigMappingEndIdxOfGwSigGrpMapping(Com_GwSigGrpMappingIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwGrpSigMappingStartIdxOfGwSigGrpMappingType, COM_CODE) Com_GetGwGrpSigMappingStartIdxOfGwSigGrpMapping(Com_GwSigGrpMappingIterType Index);
COM_LOCAL_INLINE FUNC(Com_SignalGroupLengthInByteOfGwSigGrpMappingType, COM_CODE) Com_GetSignalGroupLengthInByteOfGwSigGrpMapping(Com_GwSigGrpMappingIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxSigGrpInfoIdxOfGwSigGrpMappingType, COM_CODE) Com_GetTxSigGrpInfoIdxOfGwSigGrpMapping(Com_GwSigGrpMappingIterType Index);
COM_LOCAL_INLINE FUNC(Com_CprQueueIdxOfGwSigMappingType, COM_CODE) Com_GetCprQueueIdxOfGwSigMapping(Com_GwSigMappingIterType Index);
COM_LOCAL_INLINE FUNC(Com_CprQueueUsedOfGwSigMappingType, COM_CODE) Com_IsCprQueueUsedOfGwSigMapping(Com_GwSigMappingIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwSigOrGrpSigTmpBufferInfoIdxOfGwSigMappingType, COM_CODE) Com_GetGwSigOrGrpSigTmpBufferInfoIdxOfGwSigMapping(Com_GwSigMappingIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwSigOrGrpSigTmpBufferInfoUsedOfGwSigMappingType, COM_CODE) Com_IsGwSigOrGrpSigTmpBufferInfoUsedOfGwSigMapping(Com_GwSigMappingIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoIdxOfGwSigMappingType, COM_CODE) Com_GetRxAccessInfoIdxOfGwSigMapping(Com_GwSigMappingIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxSigInfoIdxOfGwSigMappingType, COM_CODE) Com_GetTxSigInfoIdxOfGwSigMapping(Com_GwSigMappingIterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferEndIdxOfGwSigOrGrpSigTmpBufferInfoType, COM_CODE) Com_GetTmpTxSigBufferEndIdxOfGwSigOrGrpSigTmpBufferInfo(Com_GwSigOrGrpSigTmpBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferLengthOfGwSigOrGrpSigTmpBufferInfoType, COM_CODE) Com_GetTmpTxSigBufferLengthOfGwSigOrGrpSigTmpBufferInfo(Com_GwSigOrGrpSigTmpBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfoType, COM_CODE) Com_GetTmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(Com_GwSigOrGrpSigTmpBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferStartIdxOfGwSigOrGrpSigTmpBufferInfoType, COM_CODE) Com_GetTmpTxSigBufferStartIdxOfGwSigOrGrpSigTmpBufferInfo(Com_GwSigOrGrpSigTmpBufferInfoIterType Index);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetGwEvent(Com_GwEventIterType Index, Com_GwEventType Value);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwEvent(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwGrpSigMapping(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigOrGrpSigTmpBufferInfoIdxOfGwGrpSigMapping(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigOrGrpSigTmpBufferInfoUsedOfGwGrpSigMapping(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoIdxOfGwGrpSigMapping(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxGrpSigInfoIdxOfGwGrpSigMapping(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigGrpMappingEndIdxOfGwInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigGrpMappingStartIdxOfGwInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigGrpMappingUsedOfGwInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigMappingEndIdxOfGwInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigMappingStartIdxOfGwInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigMappingUsedOfGwInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigGrpMapping(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueIdxOfGwSigGrpMapping(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueUsedOfGwSigGrpMapping(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwGrpSigMappingEndIdxOfGwSigGrpMapping(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwGrpSigMappingStartIdxOfGwSigGrpMapping(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSignalGroupLengthInByteOfGwSigGrpMapping(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpInfoIdxOfGwSigGrpMapping(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigMapping(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueIdxOfGwSigMapping(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueUsedOfGwSigMapping(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigOrGrpSigTmpBufferInfoIdxOfGwSigMapping(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigOrGrpSigTmpBufferInfoUsedOfGwSigMapping(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoIdxOfGwSigMapping(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigInfoIdxOfGwSigMapping(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigOrGrpSigTmpBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferEndIdxOfGwSigOrGrpSigTmpBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferLengthOfGwSigOrGrpSigTmpBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferStartIdxOfGwSigOrGrpSigTmpBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfGwEvent(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfGwGrpSigMapping(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfGwInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfGwSigGrpMapping(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfGwSigMapping(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfGwSigOrGrpSigTmpBufferInfo(void);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpTxSigBufferBufferUInt8TmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpTxSigBufferBufferUInt16TmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpTxSigBufferBufferUInt32TmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpTxSigBufferBufferUInt64TmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpTxSigBufferBufferSInt8TmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpTxSigBufferBufferSInt16TmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpTxSigBufferBufferSInt32TmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpTxSigBufferBufferSInt64TmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpTxSigBufferBufferFloat32TmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpTxSigBufferBufferFloat64TmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpTxSigBufferBufferArrayBasedTmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(void);
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
COM_LOCAL_INLINE FUNC(Com_SizeOfGwEventType, COM_CODE) Com_GetSizeOfGwEvent(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfGwEventType) Com_GetSizeOfGwEventOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfGwGrpSigMappingType, COM_CODE) Com_GetSizeOfGwGrpSigMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfGwGrpSigMappingType) Com_GetSizeOfGwGrpSigMappingOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfGwInfoType, COM_CODE) Com_GetSizeOfGwInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfGwInfoType) Com_GetSizeOfGwInfoOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfGwSigGrpMappingType, COM_CODE) Com_GetSizeOfGwSigGrpMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfGwSigGrpMappingType) Com_GetSizeOfGwSigGrpMappingOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfGwSigMappingType, COM_CODE) Com_GetSizeOfGwSigMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfGwSigMappingType) Com_GetSizeOfGwSigMappingOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfGwSigOrGrpSigTmpBufferInfoType, COM_CODE) Com_GetSizeOfGwSigOrGrpSigTmpBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfGwSigOrGrpSigTmpBufferInfoType) Com_GetSizeOfGwSigOrGrpSigTmpBufferInfoOfPCConfig();
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
COM_LOCAL_INLINE FUNC(Com_GwEventType, COM_CODE) Com_IsGwEvent(Com_GwEventIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwEventType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_GwSigOrGrpSigTmpBufferInfoIdxOfGwGrpSigMappingType, COM_CODE) Com_GetGwSigOrGrpSigTmpBufferInfoIdxOfGwGrpSigMapping(Com_GwGrpSigMappingIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwSigOrGrpSigTmpBufferInfoIdxOfGwGrpSigMappingType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_GwSigOrGrpSigTmpBufferInfoUsedOfGwGrpSigMappingType, COM_CODE) Com_IsGwSigOrGrpSigTmpBufferInfoUsedOfGwGrpSigMapping(Com_GwGrpSigMappingIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwSigOrGrpSigTmpBufferInfoUsedOfGwGrpSigMappingType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoIdxOfGwGrpSigMappingType, COM_CODE) Com_GetRxAccessInfoIdxOfGwGrpSigMapping(Com_GwGrpSigMappingIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxAccessInfoIdxOfGwGrpSigMappingType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxGrpSigInfoIdxOfGwGrpSigMappingType, COM_CODE) Com_GetTxGrpSigInfoIdxOfGwGrpSigMapping(Com_GwGrpSigMappingIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxGrpSigInfoIdxOfGwGrpSigMappingType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_GwSigGrpMappingEndIdxOfGwInfoType, COM_CODE) Com_GetGwSigGrpMappingEndIdxOfGwInfo(Com_GwInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwSigGrpMappingEndIdxOfGwInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_GwSigGrpMappingStartIdxOfGwInfoType, COM_CODE) Com_GetGwSigGrpMappingStartIdxOfGwInfo(Com_GwInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwSigGrpMappingStartIdxOfGwInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_GwSigGrpMappingUsedOfGwInfoType, COM_CODE) Com_IsGwSigGrpMappingUsedOfGwInfo(Com_GwInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwSigGrpMappingUsedOfGwInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_GwSigMappingEndIdxOfGwInfoType, COM_CODE) Com_GetGwSigMappingEndIdxOfGwInfo(Com_GwInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwSigMappingEndIdxOfGwInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_GwSigMappingStartIdxOfGwInfoType, COM_CODE) Com_GetGwSigMappingStartIdxOfGwInfo(Com_GwInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwSigMappingStartIdxOfGwInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_GwSigMappingUsedOfGwInfoType, COM_CODE) Com_IsGwSigMappingUsedOfGwInfo(Com_GwInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwSigMappingUsedOfGwInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_CprQueueIdxOfGwSigGrpMappingType, COM_CODE) Com_GetCprQueueIdxOfGwSigGrpMapping(Com_GwSigGrpMappingIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_CprQueueIdxOfGwSigGrpMappingType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_CprQueueUsedOfGwSigGrpMappingType, COM_CODE) Com_IsCprQueueUsedOfGwSigGrpMapping(Com_GwSigGrpMappingIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_CprQueueUsedOfGwSigGrpMappingType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_GwGrpSigMappingEndIdxOfGwSigGrpMappingType, COM_CODE) Com_GetGwGrpSigMappingEndIdxOfGwSigGrpMapping(Com_GwSigGrpMappingIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwGrpSigMappingEndIdxOfGwSigGrpMappingType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_GwGrpSigMappingStartIdxOfGwSigGrpMappingType, COM_CODE) Com_GetGwGrpSigMappingStartIdxOfGwSigGrpMapping(Com_GwSigGrpMappingIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwGrpSigMappingStartIdxOfGwSigGrpMappingType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_SignalGroupLengthInByteOfGwSigGrpMappingType, COM_CODE) Com_GetSignalGroupLengthInByteOfGwSigGrpMapping(Com_GwSigGrpMappingIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_SignalGroupLengthInByteOfGwSigGrpMappingType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxSigGrpInfoIdxOfGwSigGrpMappingType, COM_CODE) Com_GetTxSigGrpInfoIdxOfGwSigGrpMapping(Com_GwSigGrpMappingIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxSigGrpInfoIdxOfGwSigGrpMappingType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_CprQueueIdxOfGwSigMappingType, COM_CODE) Com_GetCprQueueIdxOfGwSigMapping(Com_GwSigMappingIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_CprQueueIdxOfGwSigMappingType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_CprQueueUsedOfGwSigMappingType, COM_CODE) Com_IsCprQueueUsedOfGwSigMapping(Com_GwSigMappingIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_CprQueueUsedOfGwSigMappingType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_GwSigOrGrpSigTmpBufferInfoIdxOfGwSigMappingType, COM_CODE) Com_GetGwSigOrGrpSigTmpBufferInfoIdxOfGwSigMapping(Com_GwSigMappingIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwSigOrGrpSigTmpBufferInfoIdxOfGwSigMappingType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_GwSigOrGrpSigTmpBufferInfoUsedOfGwSigMappingType, COM_CODE) Com_IsGwSigOrGrpSigTmpBufferInfoUsedOfGwSigMapping(Com_GwSigMappingIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwSigOrGrpSigTmpBufferInfoUsedOfGwSigMappingType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoIdxOfGwSigMappingType, COM_CODE) Com_GetRxAccessInfoIdxOfGwSigMapping(Com_GwSigMappingIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxAccessInfoIdxOfGwSigMappingType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxSigInfoIdxOfGwSigMappingType, COM_CODE) Com_GetTxSigInfoIdxOfGwSigMapping(Com_GwSigMappingIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxSigInfoIdxOfGwSigMappingType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferEndIdxOfGwSigOrGrpSigTmpBufferInfoType, COM_CODE) Com_GetTmpTxSigBufferEndIdxOfGwSigOrGrpSigTmpBufferInfo(Com_GwSigOrGrpSigTmpBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferEndIdxOfGwSigOrGrpSigTmpBufferInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferLengthOfGwSigOrGrpSigTmpBufferInfoType, COM_CODE) Com_GetTmpTxSigBufferLengthOfGwSigOrGrpSigTmpBufferInfo(Com_GwSigOrGrpSigTmpBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferLengthOfGwSigOrGrpSigTmpBufferInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfoType, COM_CODE) Com_GetTmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(Com_GwSigOrGrpSigTmpBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfoType) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferStartIdxOfGwSigOrGrpSigTmpBufferInfoType, COM_CODE) Com_GetTmpTxSigBufferStartIdxOfGwSigOrGrpSigTmpBufferInfo(Com_GwSigOrGrpSigTmpBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferStartIdxOfGwSigOrGrpSigTmpBufferInfoType) (0u);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetGwEvent(Com_GwEventIterType Index, Com_GwEventType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
  \defgroup  ComPCHasInlineFunctions  Com Has Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwEvent(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwGrpSigMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigOrGrpSigTmpBufferInfoIdxOfGwGrpSigMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigOrGrpSigTmpBufferInfoUsedOfGwGrpSigMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoIdxOfGwGrpSigMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxGrpSigInfoIdxOfGwGrpSigMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigGrpMappingEndIdxOfGwInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigGrpMappingStartIdxOfGwInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigGrpMappingUsedOfGwInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigMappingEndIdxOfGwInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigMappingStartIdxOfGwInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigMappingUsedOfGwInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigGrpMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueIdxOfGwSigGrpMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueUsedOfGwSigGrpMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwGrpSigMappingEndIdxOfGwSigGrpMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwGrpSigMappingStartIdxOfGwSigGrpMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSignalGroupLengthInByteOfGwSigGrpMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpInfoIdxOfGwSigGrpMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueIdxOfGwSigMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueUsedOfGwSigMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigOrGrpSigTmpBufferInfoIdxOfGwSigMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigOrGrpSigTmpBufferInfoUsedOfGwSigMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoIdxOfGwSigMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigInfoIdxOfGwSigMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwSigOrGrpSigTmpBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferEndIdxOfGwSigOrGrpSigTmpBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferLengthOfGwSigOrGrpSigTmpBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferStartIdxOfGwSigOrGrpSigTmpBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfGwEvent(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfGwGrpSigMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfGwInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfGwSigGrpMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfGwSigMapping(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfGwSigOrGrpSigTmpBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpTxSigBufferBufferUInt8TmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpTxSigBufferBufferUInt16TmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpTxSigBufferBufferUInt32TmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpTxSigBufferBufferUInt64TmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpTxSigBufferBufferSInt8TmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpTxSigBufferBufferSInt16TmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpTxSigBufferBufferSInt32TmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpTxSigBufferBufferSInt64TmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpTxSigBufferBufferFloat32TmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpTxSigBufferBufferFloat64TmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTmpTxSigBufferBufferArrayBasedTmpTxSigBufferOfGwSigOrGrpSigTmpBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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

#endif  /* COM_CFG_SIGNALGATEWAYDATA_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cfg_SignalGatewayData.h
**********************************************************************************************************************/

