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
 *              File: Com_Cfg_MetaDataBuffer.h
 *   Generation Time: 2026-04-02 15:10:32
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

#if !defined (COM_CFG_METADATABUFFER_H)
# define COM_CFG_METADATABUFFER_H

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
COM_LOCAL_INLINE FUNC(Com_SizeOfMetaDataBufferType, COM_CODE) Com_GetSizeOfMetaDataBuffer(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfMetaDataInitValueType, COM_CODE) Com_GetSizeOfMetaDataInitValue(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxMetaDataBufferInfoType, COM_CODE) Com_GetSizeOfRxMetaDataBufferInfo(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxMetaDataBufferInfoType, COM_CODE) Com_GetSizeOfTxMetaDataBufferInfo(void);
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
COM_LOCAL_INLINE FUNC(Com_MetaDataBufferType, COM_CODE) Com_GetMetaDataBuffer(Com_MetaDataBufferIterType Index);
COM_LOCAL_INLINE FUNC(Com_MetaDataInitValueType, COM_CODE) Com_GetMetaDataInitValue(Com_MetaDataInitValueIterType Index);
COM_LOCAL_INLINE FUNC(Com_MetaDataBufferEndIdxOfRxMetaDataBufferInfoType, COM_CODE) Com_GetMetaDataBufferEndIdxOfRxMetaDataBufferInfo(Com_RxMetaDataBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_MetaDataBufferLengthOfRxMetaDataBufferInfoType, COM_CODE) Com_GetMetaDataBufferLengthOfRxMetaDataBufferInfo(Com_RxMetaDataBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_MetaDataBufferStartIdxOfRxMetaDataBufferInfoType, COM_CODE) Com_GetMetaDataBufferStartIdxOfRxMetaDataBufferInfo(Com_RxMetaDataBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_MetaDataBufferEndIdxOfTxMetaDataBufferInfoType, COM_CODE) Com_GetMetaDataBufferEndIdxOfTxMetaDataBufferInfo(Com_TxMetaDataBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_MetaDataBufferLengthOfTxMetaDataBufferInfoType, COM_CODE) Com_GetMetaDataBufferLengthOfTxMetaDataBufferInfo(Com_TxMetaDataBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_MetaDataBufferShadowEndIdxOfTxMetaDataBufferInfoType, COM_CODE) Com_GetMetaDataBufferShadowEndIdxOfTxMetaDataBufferInfo(Com_TxMetaDataBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_MetaDataBufferShadowLengthOfTxMetaDataBufferInfoType, COM_CODE) Com_GetMetaDataBufferShadowLengthOfTxMetaDataBufferInfo(Com_TxMetaDataBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_MetaDataBufferShadowStartIdxOfTxMetaDataBufferInfoType, COM_CODE) Com_GetMetaDataBufferShadowStartIdxOfTxMetaDataBufferInfo(Com_TxMetaDataBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_MetaDataBufferStartIdxOfTxMetaDataBufferInfoType, COM_CODE) Com_GetMetaDataBufferStartIdxOfTxMetaDataBufferInfo(Com_TxMetaDataBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_MetaDataInitValueEndIdxOfTxMetaDataBufferInfoType, COM_CODE) Com_GetMetaDataInitValueEndIdxOfTxMetaDataBufferInfo(Com_TxMetaDataBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_MetaDataInitValueLengthOfTxMetaDataBufferInfoType, COM_CODE) Com_GetMetaDataInitValueLengthOfTxMetaDataBufferInfo(Com_TxMetaDataBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_MetaDataInitValueStartIdxOfTxMetaDataBufferInfoType, COM_CODE) Com_GetMetaDataInitValueStartIdxOfTxMetaDataBufferInfo(Com_TxMetaDataBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_MetaDataInitValueUsedOfTxMetaDataBufferInfoType, COM_CODE) Com_IsMetaDataInitValueUsedOfTxMetaDataBufferInfo(Com_TxMetaDataBufferInfoIterType Index);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetMetaDataBuffer(Com_MetaDataBufferIterType Index, Com_MetaDataBufferType Value);
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
COM_LOCAL_INLINE FUNC(Com_MetaDataBufferPtrType, COM_CODE) Com_GetAddrMetaDataBuffer(Com_MetaDataBufferIterType Index);
COM_LOCAL_INLINE FUNC(Com_MetaDataInitValuePtrType, COM_CODE) Com_GetAddrMetaDataInitValue(Com_MetaDataInitValueIterType Index);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataBuffer(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataInitValue(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxMetaDataBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataBufferEndIdxOfRxMetaDataBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataBufferLengthOfRxMetaDataBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataBufferStartIdxOfRxMetaDataBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfMetaDataBuffer(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfMetaDataInitValue(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxMetaDataBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxMetaDataBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxMetaDataBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataBufferEndIdxOfTxMetaDataBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataBufferLengthOfTxMetaDataBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataBufferShadowEndIdxOfTxMetaDataBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataBufferShadowLengthOfTxMetaDataBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataBufferShadowStartIdxOfTxMetaDataBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataBufferStartIdxOfTxMetaDataBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataInitValueEndIdxOfTxMetaDataBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataInitValueLengthOfTxMetaDataBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataInitValueStartIdxOfTxMetaDataBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataInitValueUsedOfTxMetaDataBufferInfo(void);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncMetaDataBuffer(Com_MetaDataBufferIterType Index);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecMetaDataBuffer(Com_MetaDataBufferIterType Index);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddMetaDataBuffer(Com_MetaDataBufferIterType Index, Com_MetaDataBufferType Value);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubMetaDataBuffer(Com_MetaDataBufferIterType Index, Com_MetaDataBufferType Value);
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
COM_LOCAL_INLINE FUNC(Com_SizeOfMetaDataBufferType, COM_CODE) Com_GetSizeOfMetaDataBuffer(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfMetaDataBufferType) Com_GetSizeOfMetaDataBufferOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfMetaDataInitValueType, COM_CODE) Com_GetSizeOfMetaDataInitValue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfMetaDataInitValueType) Com_GetSizeOfMetaDataInitValueOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxMetaDataBufferInfoType, COM_CODE) Com_GetSizeOfRxMetaDataBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxMetaDataBufferInfoType) Com_GetSizeOfRxMetaDataBufferInfoOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxMetaDataBufferInfoType, COM_CODE) Com_GetSizeOfTxMetaDataBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxMetaDataBufferInfoType) Com_GetSizeOfTxMetaDataBufferInfoOfPCConfig();
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
COM_LOCAL_INLINE FUNC(Com_MetaDataBufferType, COM_CODE) Com_GetMetaDataBuffer(Com_MetaDataBufferIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_MetaDataBufferType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_MetaDataInitValueType, COM_CODE) Com_GetMetaDataInitValue(Com_MetaDataInitValueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_MetaDataInitValueType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_MetaDataBufferEndIdxOfRxMetaDataBufferInfoType, COM_CODE) Com_GetMetaDataBufferEndIdxOfRxMetaDataBufferInfo(Com_RxMetaDataBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_MetaDataBufferEndIdxOfRxMetaDataBufferInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_MetaDataBufferLengthOfRxMetaDataBufferInfoType, COM_CODE) Com_GetMetaDataBufferLengthOfRxMetaDataBufferInfo(Com_RxMetaDataBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_MetaDataBufferLengthOfRxMetaDataBufferInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_MetaDataBufferStartIdxOfRxMetaDataBufferInfoType, COM_CODE) Com_GetMetaDataBufferStartIdxOfRxMetaDataBufferInfo(Com_RxMetaDataBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_MetaDataBufferStartIdxOfRxMetaDataBufferInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_MetaDataBufferEndIdxOfTxMetaDataBufferInfoType, COM_CODE) Com_GetMetaDataBufferEndIdxOfTxMetaDataBufferInfo(Com_TxMetaDataBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_MetaDataBufferEndIdxOfTxMetaDataBufferInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_MetaDataBufferLengthOfTxMetaDataBufferInfoType, COM_CODE) Com_GetMetaDataBufferLengthOfTxMetaDataBufferInfo(Com_TxMetaDataBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_MetaDataBufferLengthOfTxMetaDataBufferInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_MetaDataBufferShadowEndIdxOfTxMetaDataBufferInfoType, COM_CODE) Com_GetMetaDataBufferShadowEndIdxOfTxMetaDataBufferInfo(Com_TxMetaDataBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_MetaDataBufferShadowEndIdxOfTxMetaDataBufferInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_MetaDataBufferShadowLengthOfTxMetaDataBufferInfoType, COM_CODE) Com_GetMetaDataBufferShadowLengthOfTxMetaDataBufferInfo(Com_TxMetaDataBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_MetaDataBufferShadowLengthOfTxMetaDataBufferInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_MetaDataBufferShadowStartIdxOfTxMetaDataBufferInfoType, COM_CODE) Com_GetMetaDataBufferShadowStartIdxOfTxMetaDataBufferInfo(Com_TxMetaDataBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_MetaDataBufferShadowStartIdxOfTxMetaDataBufferInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_MetaDataBufferStartIdxOfTxMetaDataBufferInfoType, COM_CODE) Com_GetMetaDataBufferStartIdxOfTxMetaDataBufferInfo(Com_TxMetaDataBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_MetaDataBufferStartIdxOfTxMetaDataBufferInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_MetaDataInitValueEndIdxOfTxMetaDataBufferInfoType, COM_CODE) Com_GetMetaDataInitValueEndIdxOfTxMetaDataBufferInfo(Com_TxMetaDataBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_MetaDataInitValueEndIdxOfTxMetaDataBufferInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_MetaDataInitValueLengthOfTxMetaDataBufferInfoType, COM_CODE) Com_GetMetaDataInitValueLengthOfTxMetaDataBufferInfo(Com_TxMetaDataBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_MetaDataInitValueLengthOfTxMetaDataBufferInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_MetaDataInitValueStartIdxOfTxMetaDataBufferInfoType, COM_CODE) Com_GetMetaDataInitValueStartIdxOfTxMetaDataBufferInfo(Com_TxMetaDataBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_MetaDataInitValueStartIdxOfTxMetaDataBufferInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_MetaDataInitValueUsedOfTxMetaDataBufferInfoType, COM_CODE) Com_IsMetaDataInitValueUsedOfTxMetaDataBufferInfo(Com_TxMetaDataBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_MetaDataInitValueUsedOfTxMetaDataBufferInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetMetaDataBuffer(Com_MetaDataBufferIterType Index, Com_MetaDataBufferType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(Com_MetaDataBufferPtrType, COM_CODE) Com_GetAddrMetaDataBuffer(Com_MetaDataBufferIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_MetaDataBufferPtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_MetaDataInitValuePtrType, COM_CODE) Com_GetAddrMetaDataInitValue(Com_MetaDataInitValueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_MetaDataInitValuePtrType) (NULL_PTR);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataBuffer(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataInitValue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxMetaDataBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataBufferEndIdxOfRxMetaDataBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataBufferLengthOfRxMetaDataBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataBufferStartIdxOfRxMetaDataBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfMetaDataBuffer(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfMetaDataInitValue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxMetaDataBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxMetaDataBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxMetaDataBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataBufferEndIdxOfTxMetaDataBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataBufferLengthOfTxMetaDataBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataBufferShadowEndIdxOfTxMetaDataBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataBufferShadowLengthOfTxMetaDataBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataBufferShadowStartIdxOfTxMetaDataBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataBufferStartIdxOfTxMetaDataBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataInitValueEndIdxOfTxMetaDataBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataInitValueLengthOfTxMetaDataBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataInitValueStartIdxOfTxMetaDataBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMetaDataInitValueUsedOfTxMetaDataBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncMetaDataBuffer(Com_MetaDataBufferIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecMetaDataBuffer(Com_MetaDataBufferIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddMetaDataBuffer(Com_MetaDataBufferIterType Index, Com_MetaDataBufferType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubMetaDataBuffer(Com_MetaDataBufferIterType Index, Com_MetaDataBufferType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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

#endif  /* COM_CFG_METADATABUFFER_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cfg_MetaDataBuffer.h
**********************************************************************************************************************/

