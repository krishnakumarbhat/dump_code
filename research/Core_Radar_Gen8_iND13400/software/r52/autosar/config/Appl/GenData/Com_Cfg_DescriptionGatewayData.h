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
 *              File: Com_Cfg_DescriptionGatewayData.h
 *   Generation Time: 2026-04-02 15:10:28
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

#if !defined (COM_CFG_DESCRIPTIONGATEWAYDATA_H)
# define COM_CFG_DESCRIPTIONGATEWAYDATA_H

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
COM_LOCAL_INLINE FUNC(Com_SizeOfGwDescriptionAccessInfoType, COM_CODE) Com_GetSizeOfGwDescriptionAccessInfo(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfGwTxPduDescriptionInfoType, COM_CODE) Com_GetSizeOfGwTxPduDescriptionInfo(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfHandleRxDeferredGwDescriptionType, COM_CODE) Com_GetSizeOfHandleRxDeferredGwDescription(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfSourceDescriptionMaskType, COM_CODE) Com_GetSizeOfSourceDescriptionMask(void);
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
COM_LOCAL_INLINE FUNC(Com_BitSizeOfGwDescriptionAccessInfoType, COM_CODE) Com_GetBitSizeOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_EndiannessOfGwDescriptionAccessInfoType, COM_CODE) Com_GetEndiannessOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwRelativeDestinationStartBitIndexOfGwDescriptionAccessInfoType, COM_CODE) Com_GetGwRelativeDestinationStartBitIndexOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ImmediateProcessingOfGwDescriptionAccessInfoType, COM_CODE) Com_IsImmediateProcessingOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_SourceStartBitIndexBasedonMinSourceStartBytePositionOfGwDescriptionAccessInfoType, COM_CODE) Com_GetSourceStartBitIndexBasedonMinSourceStartBytePositionOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoIdxOfGwDescriptionAccessInfoType, COM_CODE) Com_GetTxBufferInfoIdxOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoUbIdxAndMaskIdxOfGwDescriptionAccessInfoType, COM_CODE) Com_GetTxBufferInfoUbIdxAndMaskIdxOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoUbIdxAndMaskUsedOfGwDescriptionAccessInfoType, COM_CODE) Com_IsTxBufferInfoUbIdxAndMaskUsedOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxPduInfoIdxOfGwDescriptionAccessInfoType, COM_CODE) Com_GetTxPduInfoIdxOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TypeOfGwDescriptionAccessInfoType, COM_CODE) Com_GetTypeOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_UpdateBitInfoIdxOfGwDescriptionAccessInfoType, COM_CODE) Com_GetUpdateBitInfoIdxOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_UpdateBitInfoUsedOfGwDescriptionAccessInfoType, COM_CODE) Com_IsUpdateBitInfoUsedOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ValidDlcOfGwDescriptionAccessInfoType, COM_CODE) Com_GetValidDlcOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_CprQueueIdxOfGwTxPduDescriptionInfoType, COM_CODE) Com_GetCprQueueIdxOfGwTxPduDescriptionInfo(Com_GwTxPduDescriptionInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_CprQueueUsedOfGwTxPduDescriptionInfoType, COM_CODE) Com_IsCprQueueUsedOfGwTxPduDescriptionInfo(Com_GwTxPduDescriptionInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwDescriptionAccessInfoEndIdxOfGwTxPduDescriptionInfoType, COM_CODE) Com_GetGwDescriptionAccessInfoEndIdxOfGwTxPduDescriptionInfo(Com_GwTxPduDescriptionInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_GwDescriptionAccessInfoStartIdxOfGwTxPduDescriptionInfoType, COM_CODE) Com_GetGwDescriptionAccessInfoStartIdxOfGwTxPduDescriptionInfo(Com_GwTxPduDescriptionInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_SourceMaxLengthOfGwTxPduDescriptionInfoType, COM_CODE) Com_GetSourceMaxLengthOfGwTxPduDescriptionInfo(Com_GwTxPduDescriptionInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_SourceMinStartBytePositionOfGwTxPduDescriptionInfoType, COM_CODE) Com_GetSourceMinStartBytePositionOfGwTxPduDescriptionInfo(Com_GwTxPduDescriptionInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_HandleRxDeferredGwDescriptionType, COM_CODE) Com_GetHandleRxDeferredGwDescription(Com_HandleRxDeferredGwDescriptionIterType Index);
COM_LOCAL_INLINE FUNC(Com_SourceDescriptionMaskType, COM_CODE) Com_GetSourceDescriptionMask(Com_SourceDescriptionMaskIterType Index);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetHandleRxDeferredGwDescription(Com_HandleRxDeferredGwDescriptionIterType Index, Com_HandleRxDeferredGwDescriptionType Value);
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
COM_LOCAL_INLINE FUNC(Com_SourceDescriptionMaskPtrType, COM_CODE) Com_GetAddrSourceDescriptionMask(Com_SourceDescriptionMaskIterType Index);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwDescriptionAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasBitSizeOfGwDescriptionAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasEndiannessOfGwDescriptionAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwRelativeDestinationStartBitIndexOfGwDescriptionAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasImmediateProcessingOfGwDescriptionAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSourceStartBitIndexBasedonMinSourceStartBytePositionOfGwDescriptionAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoIdxOfGwDescriptionAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoUbIdxAndMaskIdxOfGwDescriptionAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoUbIdxAndMaskUsedOfGwDescriptionAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInfoIdxOfGwDescriptionAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTypeOfGwDescriptionAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasUpdateBitInfoIdxOfGwDescriptionAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasUpdateBitInfoUsedOfGwDescriptionAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasValidDlcOfGwDescriptionAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwTxPduDescriptionInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueIdxOfGwTxPduDescriptionInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueUsedOfGwTxPduDescriptionInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwDescriptionAccessInfoEndIdxOfGwTxPduDescriptionInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwDescriptionAccessInfoStartIdxOfGwTxPduDescriptionInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSourceMaxLengthOfGwTxPduDescriptionInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSourceMinStartBytePositionOfGwTxPduDescriptionInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasHandleRxDeferredGwDescription(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfGwDescriptionAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfGwTxPduDescriptionInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfHandleRxDeferredGwDescription(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfSourceDescriptionMask(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSourceDescriptionMask(void);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsBIG_ENDIANEndiannessOfGwDescriptionAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsLITTLE_ENDIANEndiannessOfGwDescriptionAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsPENDINGTypeOfGwDescriptionAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTRIGGEREDTypeOfGwDescriptionAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTRIGGERED_ON_CHANGETypeOfGwDescriptionAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTRIGGERED_ON_CHANGE_WITHOUT_REPETITIONTypeOfGwDescriptionAccessInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTRIGGERED_WITHOUT_REPETITIONTypeOfGwDescriptionAccessInfo(void);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncHandleRxDeferredGwDescription(Com_HandleRxDeferredGwDescriptionIterType Index);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecHandleRxDeferredGwDescription(Com_HandleRxDeferredGwDescriptionIterType Index);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddHandleRxDeferredGwDescription(Com_HandleRxDeferredGwDescriptionIterType Index, Com_HandleRxDeferredGwDescriptionType Value);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubHandleRxDeferredGwDescription(Com_HandleRxDeferredGwDescriptionIterType Index, Com_HandleRxDeferredGwDescriptionType Value);
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
COM_LOCAL_INLINE FUNC(Com_SizeOfGwDescriptionAccessInfoType, COM_CODE) Com_GetSizeOfGwDescriptionAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfGwDescriptionAccessInfoType) Com_GetSizeOfGwDescriptionAccessInfoOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfGwTxPduDescriptionInfoType, COM_CODE) Com_GetSizeOfGwTxPduDescriptionInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfGwTxPduDescriptionInfoType) Com_GetSizeOfGwTxPduDescriptionInfoOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfHandleRxDeferredGwDescriptionType, COM_CODE) Com_GetSizeOfHandleRxDeferredGwDescription(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfHandleRxDeferredGwDescriptionType) Com_GetSizeOfHandleRxDeferredGwDescriptionOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfSourceDescriptionMaskType, COM_CODE) Com_GetSizeOfSourceDescriptionMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfSourceDescriptionMaskType) Com_GetSizeOfSourceDescriptionMaskOfPCConfig();
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
COM_LOCAL_INLINE FUNC(Com_BitSizeOfGwDescriptionAccessInfoType, COM_CODE) Com_GetBitSizeOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_BitSizeOfGwDescriptionAccessInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_EndiannessOfGwDescriptionAccessInfoType, COM_CODE) Com_GetEndiannessOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_EndiannessOfGwDescriptionAccessInfoType) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_GwRelativeDestinationStartBitIndexOfGwDescriptionAccessInfoType, COM_CODE) Com_GetGwRelativeDestinationStartBitIndexOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwRelativeDestinationStartBitIndexOfGwDescriptionAccessInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_ImmediateProcessingOfGwDescriptionAccessInfoType, COM_CODE) Com_IsImmediateProcessingOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ImmediateProcessingOfGwDescriptionAccessInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_SourceStartBitIndexBasedonMinSourceStartBytePositionOfGwDescriptionAccessInfoType, COM_CODE) Com_GetSourceStartBitIndexBasedonMinSourceStartBytePositionOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_SourceStartBitIndexBasedonMinSourceStartBytePositionOfGwDescriptionAccessInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoIdxOfGwDescriptionAccessInfoType, COM_CODE) Com_GetTxBufferInfoIdxOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxBufferInfoIdxOfGwDescriptionAccessInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoUbIdxAndMaskIdxOfGwDescriptionAccessInfoType, COM_CODE) Com_GetTxBufferInfoUbIdxAndMaskIdxOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxBufferInfoUbIdxAndMaskIdxOfGwDescriptionAccessInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoUbIdxAndMaskUsedOfGwDescriptionAccessInfoType, COM_CODE) Com_IsTxBufferInfoUbIdxAndMaskUsedOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxBufferInfoUbIdxAndMaskUsedOfGwDescriptionAccessInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TxPduInfoIdxOfGwDescriptionAccessInfoType, COM_CODE) Com_GetTxPduInfoIdxOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxPduInfoIdxOfGwDescriptionAccessInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TypeOfGwDescriptionAccessInfoType, COM_CODE) Com_GetTypeOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TypeOfGwDescriptionAccessInfoType) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_UpdateBitInfoIdxOfGwDescriptionAccessInfoType, COM_CODE) Com_GetUpdateBitInfoIdxOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_UpdateBitInfoIdxOfGwDescriptionAccessInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_UpdateBitInfoUsedOfGwDescriptionAccessInfoType, COM_CODE) Com_IsUpdateBitInfoUsedOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_UpdateBitInfoUsedOfGwDescriptionAccessInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_ValidDlcOfGwDescriptionAccessInfoType, COM_CODE) Com_GetValidDlcOfGwDescriptionAccessInfo(Com_GwDescriptionAccessInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ValidDlcOfGwDescriptionAccessInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_CprQueueIdxOfGwTxPduDescriptionInfoType, COM_CODE) Com_GetCprQueueIdxOfGwTxPduDescriptionInfo(Com_GwTxPduDescriptionInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_CprQueueIdxOfGwTxPduDescriptionInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_CprQueueUsedOfGwTxPduDescriptionInfoType, COM_CODE) Com_IsCprQueueUsedOfGwTxPduDescriptionInfo(Com_GwTxPduDescriptionInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_CprQueueUsedOfGwTxPduDescriptionInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_GwDescriptionAccessInfoEndIdxOfGwTxPduDescriptionInfoType, COM_CODE) Com_GetGwDescriptionAccessInfoEndIdxOfGwTxPduDescriptionInfo(Com_GwTxPduDescriptionInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwDescriptionAccessInfoEndIdxOfGwTxPduDescriptionInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_GwDescriptionAccessInfoStartIdxOfGwTxPduDescriptionInfoType, COM_CODE) Com_GetGwDescriptionAccessInfoStartIdxOfGwTxPduDescriptionInfo(Com_GwTxPduDescriptionInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_GwDescriptionAccessInfoStartIdxOfGwTxPduDescriptionInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_SourceMaxLengthOfGwTxPduDescriptionInfoType, COM_CODE) Com_GetSourceMaxLengthOfGwTxPduDescriptionInfo(Com_GwTxPduDescriptionInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_SourceMaxLengthOfGwTxPduDescriptionInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_SourceMinStartBytePositionOfGwTxPduDescriptionInfoType, COM_CODE) Com_GetSourceMinStartBytePositionOfGwTxPduDescriptionInfo(Com_GwTxPduDescriptionInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_SourceMinStartBytePositionOfGwTxPduDescriptionInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_HandleRxDeferredGwDescriptionType, COM_CODE) Com_GetHandleRxDeferredGwDescription(Com_HandleRxDeferredGwDescriptionIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_HandleRxDeferredGwDescriptionType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_SourceDescriptionMaskType, COM_CODE) Com_GetSourceDescriptionMask(Com_SourceDescriptionMaskIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_SourceDescriptionMaskType) (0x00u);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetHandleRxDeferredGwDescription(Com_HandleRxDeferredGwDescriptionIterType Index, Com_HandleRxDeferredGwDescriptionType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(Com_SourceDescriptionMaskPtrType, COM_CODE) Com_GetAddrSourceDescriptionMask(Com_SourceDescriptionMaskIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_SourceDescriptionMaskPtrType) (NULL_PTR);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwDescriptionAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasBitSizeOfGwDescriptionAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasEndiannessOfGwDescriptionAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwRelativeDestinationStartBitIndexOfGwDescriptionAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasImmediateProcessingOfGwDescriptionAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSourceStartBitIndexBasedonMinSourceStartBytePositionOfGwDescriptionAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoIdxOfGwDescriptionAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoUbIdxAndMaskIdxOfGwDescriptionAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoUbIdxAndMaskUsedOfGwDescriptionAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInfoIdxOfGwDescriptionAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTypeOfGwDescriptionAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasUpdateBitInfoIdxOfGwDescriptionAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasUpdateBitInfoUsedOfGwDescriptionAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasValidDlcOfGwDescriptionAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwTxPduDescriptionInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueIdxOfGwTxPduDescriptionInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueUsedOfGwTxPduDescriptionInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwDescriptionAccessInfoEndIdxOfGwTxPduDescriptionInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasGwDescriptionAccessInfoStartIdxOfGwTxPduDescriptionInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSourceMaxLengthOfGwTxPduDescriptionInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSourceMinStartBytePositionOfGwTxPduDescriptionInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasHandleRxDeferredGwDescription(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfGwDescriptionAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfGwTxPduDescriptionInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfHandleRxDeferredGwDescription(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfSourceDescriptionMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSourceDescriptionMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsBIG_ENDIANEndiannessOfGwDescriptionAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsLITTLE_ENDIANEndiannessOfGwDescriptionAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsPENDINGTypeOfGwDescriptionAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTRIGGEREDTypeOfGwDescriptionAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTRIGGERED_ON_CHANGETypeOfGwDescriptionAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTRIGGERED_ON_CHANGE_WITHOUT_REPETITIONTypeOfGwDescriptionAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsTRIGGERED_WITHOUT_REPETITIONTypeOfGwDescriptionAccessInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncHandleRxDeferredGwDescription(Com_HandleRxDeferredGwDescriptionIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecHandleRxDeferredGwDescription(Com_HandleRxDeferredGwDescriptionIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddHandleRxDeferredGwDescription(Com_HandleRxDeferredGwDescriptionIterType Index, Com_HandleRxDeferredGwDescriptionType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubHandleRxDeferredGwDescription(Com_HandleRxDeferredGwDescriptionIterType Index, Com_HandleRxDeferredGwDescriptionType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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

#endif  /* COM_CFG_DESCRIPTIONGATEWAYDATA_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cfg_DescriptionGatewayData.h
**********************************************************************************************************************/

