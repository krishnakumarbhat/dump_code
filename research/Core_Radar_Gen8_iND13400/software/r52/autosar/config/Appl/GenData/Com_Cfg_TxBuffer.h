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
 *              File: Com_Cfg_TxBuffer.h
 *   Generation Time: 2026-04-02 15:10:37
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

#if !defined (COM_CFG_TXBUFFER_H)
# define COM_CFG_TXBUFFER_H

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
COM_LOCAL_INLINE FUNC(Com_SizeOfTxBufferType, COM_CODE) Com_GetSizeOfTxBuffer(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxBufferInfoType, COM_CODE) Com_GetSizeOfTxBufferInfo(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxPduInitValueType, COM_CODE) Com_GetSizeOfTxPduInitValue(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxSigGrpMaskType, COM_CODE) Com_GetSizeOfTxSigGrpMask(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfUbMaskType, COM_CODE) Com_GetSizeOfUbMask(void);
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
COM_LOCAL_INLINE FUNC(Com_TxBufferType, COM_CODE) Com_GetTxBuffer(Com_TxBufferIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxBufferEndIdxOfTxBufferInfoType, COM_CODE) Com_GetTxBufferEndIdxOfTxBufferInfo(Com_TxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxBufferStartIdxOfTxBufferInfoType, COM_CODE) Com_GetTxBufferStartIdxOfTxBufferInfo(Com_TxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxPduInitValueEndIdxOfTxBufferInfoType, COM_CODE) Com_GetTxPduInitValueEndIdxOfTxBufferInfo(Com_TxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxPduInitValueStartIdxOfTxBufferInfoType, COM_CODE) Com_GetTxPduInitValueStartIdxOfTxBufferInfo(Com_TxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxSigGrpMaskEndIdxOfTxBufferInfoType, COM_CODE) Com_GetTxSigGrpMaskEndIdxOfTxBufferInfo(Com_TxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxSigGrpMaskStartIdxOfTxBufferInfoType, COM_CODE) Com_GetTxSigGrpMaskStartIdxOfTxBufferInfo(Com_TxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_UbMaskEndIdxOfTxBufferInfoType, COM_CODE) Com_GetUbMaskEndIdxOfTxBufferInfo(Com_TxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_UbMaskStartIdxOfTxBufferInfoType, COM_CODE) Com_GetUbMaskStartIdxOfTxBufferInfo(Com_TxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_UbMaskUsedOfTxBufferInfoType, COM_CODE) Com_IsUbMaskUsedOfTxBufferInfo(Com_TxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxPduInitValueType, COM_CODE) Com_GetTxPduInitValue(Com_TxPduInitValueIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxSigGrpMaskType, COM_CODE) Com_GetTxSigGrpMask(Com_TxSigGrpMaskIterType Index);
COM_LOCAL_INLINE FUNC(Com_UbMaskType, COM_CODE) Com_GetUbMask(Com_UbMaskIterType Index);
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
COM_LOCAL_INLINE FUNC(Com_TxBufferLengthOfTxBufferInfoType, COM_CODE) Com_GetTxBufferLengthOfTxBufferInfo(Com_TxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxPduInitValueLengthOfTxBufferInfoType, COM_CODE) Com_GetTxPduInitValueLengthOfTxBufferInfo(Com_TxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxPduInitValueUsedOfTxBufferInfoType, COM_CODE) Com_IsTxPduInitValueUsedOfTxBufferInfo(Com_TxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxSigGrpMaskLengthOfTxBufferInfoType, COM_CODE) Com_GetTxSigGrpMaskLengthOfTxBufferInfo(Com_TxBufferInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxSigGrpMaskUsedOfTxBufferInfoType, COM_CODE) Com_IsTxSigGrpMaskUsedOfTxBufferInfo(Com_TxBufferInfoIterType Index);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxBuffer(Com_TxBufferIterType Index, Com_TxBufferType Value);
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
COM_LOCAL_INLINE FUNC(Com_TxBufferPtrType, COM_CODE) Com_GetAddrTxBuffer(Com_TxBufferIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxPduInitValuePtrType, COM_CODE) Com_GetAddrTxPduInitValue(Com_TxPduInitValueIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxSigGrpMaskPtrType, COM_CODE) Com_GetAddrTxSigGrpMask(Com_TxSigGrpMaskIterType Index);
COM_LOCAL_INLINE FUNC(Com_UbMaskPtrType, COM_CODE) Com_GetAddrUbMask(Com_UbMaskIterType Index);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxBuffer(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxPduInitValue(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxSigGrpMask(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfUbMask(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBuffer(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferEndIdxOfTxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferLengthOfTxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferStartIdxOfTxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInitValueEndIdxOfTxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInitValueLengthOfTxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInitValueStartIdxOfTxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInitValueUsedOfTxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpMaskEndIdxOfTxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpMaskLengthOfTxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpMaskStartIdxOfTxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpMaskUsedOfTxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasUbMaskEndIdxOfTxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasUbMaskStartIdxOfTxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasUbMaskUsedOfTxBufferInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInitValue(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpMask(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasUbMask(void);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTxBuffer(Com_TxBufferIterType Index);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTxBuffer(Com_TxBufferIterType Index);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTxBuffer(Com_TxBufferIterType Index, Com_TxBufferType Value);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTxBuffer(Com_TxBufferIterType Index, Com_TxBufferType Value);
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
COM_LOCAL_INLINE FUNC(Com_SizeOfTxBufferType, COM_CODE) Com_GetSizeOfTxBuffer(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxBufferType) Com_GetSizeOfTxBufferOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxBufferInfoType, COM_CODE) Com_GetSizeOfTxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxBufferInfoType) Com_GetSizeOfTxBufferInfoOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxPduInitValueType, COM_CODE) Com_GetSizeOfTxPduInitValue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxPduInitValueType) Com_GetSizeOfTxPduInitValueOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxSigGrpMaskType, COM_CODE) Com_GetSizeOfTxSigGrpMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxSigGrpMaskType) Com_GetSizeOfTxSigGrpMaskOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfUbMaskType, COM_CODE) Com_GetSizeOfUbMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfUbMaskType) Com_GetSizeOfUbMaskOfPCConfig();
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
COM_LOCAL_INLINE FUNC(Com_TxBufferType, COM_CODE) Com_GetTxBuffer(Com_TxBufferIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxBufferType) (Com_GetTxBufferOfPCConfig()[(Index)]);
}
COM_LOCAL_INLINE FUNC(Com_TxBufferEndIdxOfTxBufferInfoType, COM_CODE) Com_GetTxBufferEndIdxOfTxBufferInfo(Com_TxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxBufferEndIdxOfTxBufferInfoType) (Com_GetTxBufferInfoOfPCConfig()[(Index)].TxBufferEndIdxOfTxBufferInfo);
}
COM_LOCAL_INLINE FUNC(Com_TxBufferStartIdxOfTxBufferInfoType, COM_CODE) Com_GetTxBufferStartIdxOfTxBufferInfo(Com_TxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxBufferStartIdxOfTxBufferInfoType) (Com_GetTxBufferInfoOfPCConfig()[(Index)].TxBufferStartIdxOfTxBufferInfo);
}
COM_LOCAL_INLINE FUNC(Com_TxPduInitValueEndIdxOfTxBufferInfoType, COM_CODE) Com_GetTxPduInitValueEndIdxOfTxBufferInfo(Com_TxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxPduInitValueEndIdxOfTxBufferInfoType) (Com_GetTxBufferInfoOfPCConfig()[(Index)].TxPduInitValueEndIdxOfTxBufferInfo);
}
COM_LOCAL_INLINE FUNC(Com_TxPduInitValueStartIdxOfTxBufferInfoType, COM_CODE) Com_GetTxPduInitValueStartIdxOfTxBufferInfo(Com_TxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxPduInitValueStartIdxOfTxBufferInfoType) (Com_GetTxBufferInfoOfPCConfig()[(Index)].TxPduInitValueStartIdxOfTxBufferInfo);
}
COM_LOCAL_INLINE FUNC(Com_TxSigGrpMaskEndIdxOfTxBufferInfoType, COM_CODE) Com_GetTxSigGrpMaskEndIdxOfTxBufferInfo(Com_TxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxSigGrpMaskEndIdxOfTxBufferInfoType) (Com_GetTxBufferInfoOfPCConfig()[(Index)].TxSigGrpMaskEndIdxOfTxBufferInfo);
}
COM_LOCAL_INLINE FUNC(Com_TxSigGrpMaskStartIdxOfTxBufferInfoType, COM_CODE) Com_GetTxSigGrpMaskStartIdxOfTxBufferInfo(Com_TxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxSigGrpMaskStartIdxOfTxBufferInfoType) (Com_GetTxBufferInfoOfPCConfig()[(Index)].TxSigGrpMaskStartIdxOfTxBufferInfo);
}
COM_LOCAL_INLINE FUNC(Com_UbMaskEndIdxOfTxBufferInfoType, COM_CODE) Com_GetUbMaskEndIdxOfTxBufferInfo(Com_TxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_UbMaskEndIdxOfTxBufferInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_UbMaskStartIdxOfTxBufferInfoType, COM_CODE) Com_GetUbMaskStartIdxOfTxBufferInfo(Com_TxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_UbMaskStartIdxOfTxBufferInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_UbMaskUsedOfTxBufferInfoType, COM_CODE) Com_IsUbMaskUsedOfTxBufferInfo(Com_TxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_UbMaskUsedOfTxBufferInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TxPduInitValueType, COM_CODE) Com_GetTxPduInitValue(Com_TxPduInitValueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxPduInitValueType) (Com_GetTxPduInitValueOfPCConfig()[(Index)]);
}
COM_LOCAL_INLINE FUNC(Com_TxSigGrpMaskType, COM_CODE) Com_GetTxSigGrpMask(Com_TxSigGrpMaskIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxSigGrpMaskType) (Com_GetTxSigGrpMaskOfPCConfig()[(Index)]);
}
COM_LOCAL_INLINE FUNC(Com_UbMaskType, COM_CODE) Com_GetUbMask(Com_UbMaskIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_UbMaskType) (0x00u);
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
COM_LOCAL_INLINE FUNC(Com_TxBufferLengthOfTxBufferInfoType, COM_CODE) Com_GetTxBufferLengthOfTxBufferInfo(Com_TxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxBufferLengthOfTxBufferInfoType) ((Com_TxBufferLengthOfTxBufferInfoType)((Com_GetTxBufferEndIdxOfTxBufferInfo(Index) - Com_GetTxBufferStartIdxOfTxBufferInfo(Index))));
}
COM_LOCAL_INLINE FUNC(Com_TxPduInitValueLengthOfTxBufferInfoType, COM_CODE) Com_GetTxPduInitValueLengthOfTxBufferInfo(Com_TxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxPduInitValueLengthOfTxBufferInfoType) ((Com_TxPduInitValueLengthOfTxBufferInfoType)((Com_GetTxPduInitValueEndIdxOfTxBufferInfo(Index) - Com_GetTxPduInitValueStartIdxOfTxBufferInfo(Index))));
}
COM_LOCAL_INLINE FUNC(Com_TxPduInitValueUsedOfTxBufferInfoType, COM_CODE) Com_IsTxPduInitValueUsedOfTxBufferInfo(Com_TxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxPduInitValueUsedOfTxBufferInfoType) (((boolean)(Com_GetTxPduInitValueLengthOfTxBufferInfo(Index) != 0u)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TxSigGrpMaskLengthOfTxBufferInfoType, COM_CODE) Com_GetTxSigGrpMaskLengthOfTxBufferInfo(Com_TxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxSigGrpMaskLengthOfTxBufferInfoType) ((Com_TxSigGrpMaskLengthOfTxBufferInfoType)((Com_GetTxSigGrpMaskEndIdxOfTxBufferInfo(Index) - Com_GetTxSigGrpMaskStartIdxOfTxBufferInfo(Index))));
}
COM_LOCAL_INLINE FUNC(Com_TxSigGrpMaskUsedOfTxBufferInfoType, COM_CODE) Com_IsTxSigGrpMaskUsedOfTxBufferInfo(Com_TxBufferInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxSigGrpMaskUsedOfTxBufferInfoType) (((boolean)(Com_GetTxSigGrpMaskLengthOfTxBufferInfo(Index) != 0u)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxBuffer(Com_TxBufferIterType Index, Com_TxBufferType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetTxBufferOfPCConfig()[(Index)] = (Value);
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
COM_LOCAL_INLINE FUNC(Com_TxBufferPtrType, COM_CODE) Com_GetAddrTxBuffer(Com_TxBufferIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_TxBufferPtrType) (&(Com_GetTxBufferOfPCConfig()[(Index)]));
}
COM_LOCAL_INLINE FUNC(Com_TxPduInitValuePtrType, COM_CODE) Com_GetAddrTxPduInitValue(Com_TxPduInitValueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_TxPduInitValuePtrType) (&(Com_GetTxPduInitValueOfPCConfig()[(Index)]));
}
COM_LOCAL_INLINE FUNC(Com_TxSigGrpMaskPtrType, COM_CODE) Com_GetAddrTxSigGrpMask(Com_TxSigGrpMaskIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_TxSigGrpMaskPtrType) (&(Com_GetTxSigGrpMaskOfPCConfig()[(Index)]));
}
COM_LOCAL_INLINE FUNC(Com_UbMaskPtrType, COM_CODE) Com_GetAddrUbMask(Com_UbMaskIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_UbMaskPtrType) (NULL_PTR);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxBuffer(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxPduInitValue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxSigGrpMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfUbMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBuffer(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferEndIdxOfTxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferLengthOfTxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferStartIdxOfTxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInitValueEndIdxOfTxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInitValueLengthOfTxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInitValueStartIdxOfTxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInitValueUsedOfTxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpMaskEndIdxOfTxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpMaskLengthOfTxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpMaskStartIdxOfTxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpMaskUsedOfTxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasUbMaskEndIdxOfTxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasUbMaskStartIdxOfTxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasUbMaskUsedOfTxBufferInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInitValue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxSigGrpMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasUbMask(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTxBuffer(Com_TxBufferIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetTxBufferOfPCConfig()[(Index)]++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTxBuffer(Com_TxBufferIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetTxBufferOfPCConfig()[(Index)]--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTxBuffer(Com_TxBufferIterType Index, Com_TxBufferType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_SetTxBuffer(Index, (Com_GetTxBufferOfPCConfig()[(Index)] + Value));
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTxBuffer(Com_TxBufferIterType Index, Com_TxBufferType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_SetTxBuffer(Index, (Com_GetTxBufferOfPCConfig()[(Index)] - Value));
}
/** 
  \}
*/ 

#define COM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */





/* VCA Enable : VCA_COM_FUNCTION_NOT_USED_AND_NO_ANALYSIS_ENTRY */

#endif  /* COM_CFG_TXBUFFER_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cfg_TxBuffer.h
**********************************************************************************************************************/

