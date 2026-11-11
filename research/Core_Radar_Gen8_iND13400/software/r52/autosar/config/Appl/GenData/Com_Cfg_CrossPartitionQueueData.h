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
 *              File: Com_Cfg_CrossPartitionQueueData.h
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

#if !defined (COM_CFG_CROSSPARTITIONQUEUEDATA_H)
# define COM_CFG_CROSSPARTITIONQUEUEDATA_H

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
COM_LOCAL_INLINE FUNC(Com_SizeOfCCprQueueType, COM_CODE) Com_GetSizeOfCCprQueue(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfCprQueueBufferType, COM_CODE) Com_GetSizeOfCprQueueBuffer(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpTxSigBufferBufferArrayBasedType, COM_CODE) Com_GetSizeOfTmpTxSigBufferBufferArrayBased(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpTxSigBufferBufferFloat32Type, COM_CODE) Com_GetSizeOfTmpTxSigBufferBufferFloat32(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpTxSigBufferBufferFloat64Type, COM_CODE) Com_GetSizeOfTmpTxSigBufferBufferFloat64(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpTxSigBufferBufferSInt16Type, COM_CODE) Com_GetSizeOfTmpTxSigBufferBufferSInt16(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpTxSigBufferBufferSInt32Type, COM_CODE) Com_GetSizeOfTmpTxSigBufferBufferSInt32(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpTxSigBufferBufferSInt64Type, COM_CODE) Com_GetSizeOfTmpTxSigBufferBufferSInt64(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpTxSigBufferBufferSInt8Type, COM_CODE) Com_GetSizeOfTmpTxSigBufferBufferSInt8(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpTxSigBufferBufferUInt16Type, COM_CODE) Com_GetSizeOfTmpTxSigBufferBufferUInt16(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpTxSigBufferBufferUInt32Type, COM_CODE) Com_GetSizeOfTmpTxSigBufferBufferUInt32(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpTxSigBufferBufferUInt64Type, COM_CODE) Com_GetSizeOfTmpTxSigBufferBufferUInt64(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpTxSigBufferBufferUInt8Type, COM_CODE) Com_GetSizeOfTmpTxSigBufferBufferUInt8(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfVCprQueueType, COM_CODE) Com_GetSizeOfVCprQueue(void);
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
COM_LOCAL_INLINE FUNC(Com_CprQueueBufferEndIdxOfCprQueueType, COM_CODE) Com_GetCprQueueBufferEndIdxOfCprQueue(Com_CCprQueueIterType Index);
COM_LOCAL_INLINE FUNC(Com_CprQueueBufferLengthOfCprQueueType, COM_CODE) Com_GetCprQueueBufferLengthOfCprQueue(Com_CCprQueueIterType Index);
COM_LOCAL_INLINE FUNC(Com_CprQueueBufferStartIdxOfCprQueueType, COM_CODE) Com_GetCprQueueBufferStartIdxOfCprQueue(Com_CCprQueueIterType Index);
COM_LOCAL_INLINE FUNC(Com_CprQueueBufferType, COM_CODE) Com_GetCprQueueBuffer(Com_CprQueueBufferIterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferArrayBasedType, COM_CODE) Com_GetTmpTxSigBufferBufferArrayBased(Com_TmpTxSigBufferBufferArrayBasedIterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferFloat32Type, COM_CODE) Com_GetTmpTxSigBufferBufferFloat32(Com_TmpTxSigBufferBufferFloat32IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferFloat64Type, COM_CODE) Com_GetTmpTxSigBufferBufferFloat64(Com_TmpTxSigBufferBufferFloat64IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferSInt16Type, COM_CODE) Com_GetTmpTxSigBufferBufferSInt16(Com_TmpTxSigBufferBufferSInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferSInt32Type, COM_CODE) Com_GetTmpTxSigBufferBufferSInt32(Com_TmpTxSigBufferBufferSInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferSInt64Type, COM_CODE) Com_GetTmpTxSigBufferBufferSInt64(Com_TmpTxSigBufferBufferSInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferSInt8Type, COM_CODE) Com_GetTmpTxSigBufferBufferSInt8(Com_TmpTxSigBufferBufferSInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferUInt16Type, COM_CODE) Com_GetTmpTxSigBufferBufferUInt16(Com_TmpTxSigBufferBufferUInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferUInt32Type, COM_CODE) Com_GetTmpTxSigBufferBufferUInt32(Com_TmpTxSigBufferBufferUInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferUInt64Type, COM_CODE) Com_GetTmpTxSigBufferBufferUInt64(Com_TmpTxSigBufferBufferUInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferUInt8Type, COM_CODE) Com_GetTmpTxSigBufferBufferUInt8(Com_TmpTxSigBufferBufferUInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_CprQueueBufferNumberOfBytesReadIdxOfCprQueueType, COM_CODE) Com_GetCprQueueBufferNumberOfBytesReadIdxOfCprQueue(Com_VCprQueueIterType Index);
COM_LOCAL_INLINE FUNC(Com_CprQueueBufferPendingReadIdxOfCprQueueType, COM_CODE) Com_GetCprQueueBufferPendingReadIdxOfCprQueue(Com_VCprQueueIterType Index);
COM_LOCAL_INLINE FUNC(Com_CprQueueBufferPendingWriteIdxOfCprQueueType, COM_CODE) Com_GetCprQueueBufferPendingWriteIdxOfCprQueue(Com_VCprQueueIterType Index);
COM_LOCAL_INLINE FUNC(Com_CprQueueBufferReadIdxOfCprQueueType, COM_CODE) Com_GetCprQueueBufferReadIdxOfCprQueue(Com_VCprQueueIterType Index);
COM_LOCAL_INLINE FUNC(Com_CprQueueBufferWriteIdxOfCprQueueType, COM_CODE) Com_GetCprQueueBufferWriteIdxOfCprQueue(Com_VCprQueueIterType Index);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetCprQueueBuffer(Com_CprQueueBufferIterType Index, Com_CprQueueBufferType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpTxSigBufferBufferArrayBased(Com_TmpTxSigBufferBufferArrayBasedIterType Index, Com_TmpTxSigBufferBufferArrayBasedType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpTxSigBufferBufferFloat32(Com_TmpTxSigBufferBufferFloat32IterType Index, Com_TmpTxSigBufferBufferFloat32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpTxSigBufferBufferFloat64(Com_TmpTxSigBufferBufferFloat64IterType Index, Com_TmpTxSigBufferBufferFloat64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpTxSigBufferBufferSInt16(Com_TmpTxSigBufferBufferSInt16IterType Index, Com_TmpTxSigBufferBufferSInt16Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpTxSigBufferBufferSInt32(Com_TmpTxSigBufferBufferSInt32IterType Index, Com_TmpTxSigBufferBufferSInt32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpTxSigBufferBufferSInt64(Com_TmpTxSigBufferBufferSInt64IterType Index, Com_TmpTxSigBufferBufferSInt64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpTxSigBufferBufferSInt8(Com_TmpTxSigBufferBufferSInt8IterType Index, Com_TmpTxSigBufferBufferSInt8Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpTxSigBufferBufferUInt16(Com_TmpTxSigBufferBufferUInt16IterType Index, Com_TmpTxSigBufferBufferUInt16Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpTxSigBufferBufferUInt32(Com_TmpTxSigBufferBufferUInt32IterType Index, Com_TmpTxSigBufferBufferUInt32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpTxSigBufferBufferUInt64(Com_TmpTxSigBufferBufferUInt64IterType Index, Com_TmpTxSigBufferBufferUInt64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpTxSigBufferBufferUInt8(Com_TmpTxSigBufferBufferUInt8IterType Index, Com_TmpTxSigBufferBufferUInt8Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetCprQueueBufferNumberOfBytesReadIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferNumberOfBytesReadIdxOfCprQueueType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetCprQueueBufferPendingReadIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferPendingReadIdxOfCprQueueType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetCprQueueBufferPendingWriteIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferPendingWriteIdxOfCprQueueType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetCprQueueBufferReadIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferReadIdxOfCprQueueType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetCprQueueBufferWriteIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferWriteIdxOfCprQueueType Value);
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
COM_LOCAL_INLINE FUNC(Com_CprQueueBufferPtrType, COM_CODE) Com_GetAddrCprQueueBuffer(Com_CprQueueBufferIterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferArrayBasedPtrType, COM_CODE) Com_GetAddrTmpTxSigBufferBufferArrayBased(Com_TmpTxSigBufferBufferArrayBasedIterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferFloat32PtrType, COM_CODE) Com_GetAddrTmpTxSigBufferBufferFloat32(Com_TmpTxSigBufferBufferFloat32IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferFloat64PtrType, COM_CODE) Com_GetAddrTmpTxSigBufferBufferFloat64(Com_TmpTxSigBufferBufferFloat64IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferSInt16PtrType, COM_CODE) Com_GetAddrTmpTxSigBufferBufferSInt16(Com_TmpTxSigBufferBufferSInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferSInt32PtrType, COM_CODE) Com_GetAddrTmpTxSigBufferBufferSInt32(Com_TmpTxSigBufferBufferSInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferSInt64PtrType, COM_CODE) Com_GetAddrTmpTxSigBufferBufferSInt64(Com_TmpTxSigBufferBufferSInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferSInt8PtrType, COM_CODE) Com_GetAddrTmpTxSigBufferBufferSInt8(Com_TmpTxSigBufferBufferSInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferUInt16PtrType, COM_CODE) Com_GetAddrTmpTxSigBufferBufferUInt16(Com_TmpTxSigBufferBufferUInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferUInt32PtrType, COM_CODE) Com_GetAddrTmpTxSigBufferBufferUInt32(Com_TmpTxSigBufferBufferUInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferUInt64PtrType, COM_CODE) Com_GetAddrTmpTxSigBufferBufferUInt64(Com_TmpTxSigBufferBufferUInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferUInt8PtrType, COM_CODE) Com_GetAddrTmpTxSigBufferBufferUInt8(Com_TmpTxSigBufferBufferUInt8IterType Index);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCCprQueue(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueBufferEndIdxOfCprQueue(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueBufferLengthOfCprQueue(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueBufferStartIdxOfCprQueue(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueBuffer(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfCCprQueue(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfCprQueueBuffer(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpTxSigBufferBufferArrayBased(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpTxSigBufferBufferFloat32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpTxSigBufferBufferFloat64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpTxSigBufferBufferSInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpTxSigBufferBufferSInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpTxSigBufferBufferSInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpTxSigBufferBufferSInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpTxSigBufferBufferUInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpTxSigBufferBufferUInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpTxSigBufferBufferUInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpTxSigBufferBufferUInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfVCprQueue(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferBufferArrayBased(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferBufferFloat32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferBufferFloat64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferBufferSInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferBufferSInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferBufferSInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferBufferSInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferBufferUInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferBufferUInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferBufferUInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferBufferUInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasVCprQueue(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueBufferNumberOfBytesReadIdxOfCprQueue(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueBufferPendingReadIdxOfCprQueue(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueBufferPendingWriteIdxOfCprQueue(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueBufferReadIdxOfCprQueue(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueBufferWriteIdxOfCprQueue(void);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncCprQueueBuffer(Com_CprQueueBufferIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpTxSigBufferBufferArrayBased(Com_TmpTxSigBufferBufferArrayBasedIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpTxSigBufferBufferSInt16(Com_TmpTxSigBufferBufferSInt16IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpTxSigBufferBufferSInt32(Com_TmpTxSigBufferBufferSInt32IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpTxSigBufferBufferSInt64(Com_TmpTxSigBufferBufferSInt64IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpTxSigBufferBufferSInt8(Com_TmpTxSigBufferBufferSInt8IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpTxSigBufferBufferUInt16(Com_TmpTxSigBufferBufferUInt16IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpTxSigBufferBufferUInt32(Com_TmpTxSigBufferBufferUInt32IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpTxSigBufferBufferUInt64(Com_TmpTxSigBufferBufferUInt64IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpTxSigBufferBufferUInt8(Com_TmpTxSigBufferBufferUInt8IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncCprQueueBufferNumberOfBytesReadIdxOfCprQueue(Com_VCprQueueIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncCprQueueBufferPendingReadIdxOfCprQueue(Com_VCprQueueIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncCprQueueBufferPendingWriteIdxOfCprQueue(Com_VCprQueueIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncCprQueueBufferReadIdxOfCprQueue(Com_VCprQueueIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncCprQueueBufferWriteIdxOfCprQueue(Com_VCprQueueIterType Index);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecCprQueueBuffer(Com_CprQueueBufferIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpTxSigBufferBufferArrayBased(Com_TmpTxSigBufferBufferArrayBasedIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpTxSigBufferBufferSInt16(Com_TmpTxSigBufferBufferSInt16IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpTxSigBufferBufferSInt32(Com_TmpTxSigBufferBufferSInt32IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpTxSigBufferBufferSInt64(Com_TmpTxSigBufferBufferSInt64IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpTxSigBufferBufferSInt8(Com_TmpTxSigBufferBufferSInt8IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpTxSigBufferBufferUInt16(Com_TmpTxSigBufferBufferUInt16IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpTxSigBufferBufferUInt32(Com_TmpTxSigBufferBufferUInt32IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpTxSigBufferBufferUInt64(Com_TmpTxSigBufferBufferUInt64IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpTxSigBufferBufferUInt8(Com_TmpTxSigBufferBufferUInt8IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecCprQueueBufferNumberOfBytesReadIdxOfCprQueue(Com_VCprQueueIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecCprQueueBufferPendingReadIdxOfCprQueue(Com_VCprQueueIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecCprQueueBufferPendingWriteIdxOfCprQueue(Com_VCprQueueIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecCprQueueBufferReadIdxOfCprQueue(Com_VCprQueueIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecCprQueueBufferWriteIdxOfCprQueue(Com_VCprQueueIterType Index);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddCprQueueBuffer(Com_CprQueueBufferIterType Index, Com_CprQueueBufferType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpTxSigBufferBufferArrayBased(Com_TmpTxSigBufferBufferArrayBasedIterType Index, Com_TmpTxSigBufferBufferArrayBasedType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpTxSigBufferBufferSInt16(Com_TmpTxSigBufferBufferSInt16IterType Index, Com_TmpTxSigBufferBufferSInt16Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpTxSigBufferBufferSInt32(Com_TmpTxSigBufferBufferSInt32IterType Index, Com_TmpTxSigBufferBufferSInt32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpTxSigBufferBufferSInt64(Com_TmpTxSigBufferBufferSInt64IterType Index, Com_TmpTxSigBufferBufferSInt64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpTxSigBufferBufferSInt8(Com_TmpTxSigBufferBufferSInt8IterType Index, Com_TmpTxSigBufferBufferSInt8Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpTxSigBufferBufferUInt16(Com_TmpTxSigBufferBufferUInt16IterType Index, Com_TmpTxSigBufferBufferUInt16Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpTxSigBufferBufferUInt32(Com_TmpTxSigBufferBufferUInt32IterType Index, Com_TmpTxSigBufferBufferUInt32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpTxSigBufferBufferUInt64(Com_TmpTxSigBufferBufferUInt64IterType Index, Com_TmpTxSigBufferBufferUInt64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpTxSigBufferBufferUInt8(Com_TmpTxSigBufferBufferUInt8IterType Index, Com_TmpTxSigBufferBufferUInt8Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddCprQueueBufferNumberOfBytesReadIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferNumberOfBytesReadIdxOfCprQueueType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddCprQueueBufferPendingReadIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferPendingReadIdxOfCprQueueType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddCprQueueBufferPendingWriteIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferPendingWriteIdxOfCprQueueType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddCprQueueBufferReadIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferReadIdxOfCprQueueType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddCprQueueBufferWriteIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferWriteIdxOfCprQueueType Value);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubCprQueueBuffer(Com_CprQueueBufferIterType Index, Com_CprQueueBufferType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpTxSigBufferBufferArrayBased(Com_TmpTxSigBufferBufferArrayBasedIterType Index, Com_TmpTxSigBufferBufferArrayBasedType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpTxSigBufferBufferSInt16(Com_TmpTxSigBufferBufferSInt16IterType Index, Com_TmpTxSigBufferBufferSInt16Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpTxSigBufferBufferSInt32(Com_TmpTxSigBufferBufferSInt32IterType Index, Com_TmpTxSigBufferBufferSInt32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpTxSigBufferBufferSInt64(Com_TmpTxSigBufferBufferSInt64IterType Index, Com_TmpTxSigBufferBufferSInt64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpTxSigBufferBufferSInt8(Com_TmpTxSigBufferBufferSInt8IterType Index, Com_TmpTxSigBufferBufferSInt8Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpTxSigBufferBufferUInt16(Com_TmpTxSigBufferBufferUInt16IterType Index, Com_TmpTxSigBufferBufferUInt16Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpTxSigBufferBufferUInt32(Com_TmpTxSigBufferBufferUInt32IterType Index, Com_TmpTxSigBufferBufferUInt32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpTxSigBufferBufferUInt64(Com_TmpTxSigBufferBufferUInt64IterType Index, Com_TmpTxSigBufferBufferUInt64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpTxSigBufferBufferUInt8(Com_TmpTxSigBufferBufferUInt8IterType Index, Com_TmpTxSigBufferBufferUInt8Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubCprQueueBufferNumberOfBytesReadIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferNumberOfBytesReadIdxOfCprQueueType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubCprQueueBufferPendingReadIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferPendingReadIdxOfCprQueueType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubCprQueueBufferPendingWriteIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferPendingWriteIdxOfCprQueueType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubCprQueueBufferReadIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferReadIdxOfCprQueueType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubCprQueueBufferWriteIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferWriteIdxOfCprQueueType Value);
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
COM_LOCAL_INLINE FUNC(Com_SizeOfCCprQueueType, COM_CODE) Com_GetSizeOfCCprQueue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfCCprQueueType) Com_GetSizeOfCCprQueueOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfCprQueueBufferType, COM_CODE) Com_GetSizeOfCprQueueBuffer(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfCprQueueBufferType) Com_GetSizeOfCprQueueBufferOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpTxSigBufferBufferArrayBasedType, COM_CODE) Com_GetSizeOfTmpTxSigBufferBufferArrayBased(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTmpTxSigBufferBufferArrayBasedType) Com_GetSizeOfTmpTxSigBufferBufferArrayBasedOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpTxSigBufferBufferFloat32Type, COM_CODE) Com_GetSizeOfTmpTxSigBufferBufferFloat32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTmpTxSigBufferBufferFloat32Type) Com_GetSizeOfTmpTxSigBufferBufferFloat32OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpTxSigBufferBufferFloat64Type, COM_CODE) Com_GetSizeOfTmpTxSigBufferBufferFloat64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTmpTxSigBufferBufferFloat64Type) Com_GetSizeOfTmpTxSigBufferBufferFloat64OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpTxSigBufferBufferSInt16Type, COM_CODE) Com_GetSizeOfTmpTxSigBufferBufferSInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTmpTxSigBufferBufferSInt16Type) Com_GetSizeOfTmpTxSigBufferBufferSInt16OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpTxSigBufferBufferSInt32Type, COM_CODE) Com_GetSizeOfTmpTxSigBufferBufferSInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTmpTxSigBufferBufferSInt32Type) Com_GetSizeOfTmpTxSigBufferBufferSInt32OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpTxSigBufferBufferSInt64Type, COM_CODE) Com_GetSizeOfTmpTxSigBufferBufferSInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTmpTxSigBufferBufferSInt64Type) Com_GetSizeOfTmpTxSigBufferBufferSInt64OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpTxSigBufferBufferSInt8Type, COM_CODE) Com_GetSizeOfTmpTxSigBufferBufferSInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTmpTxSigBufferBufferSInt8Type) Com_GetSizeOfTmpTxSigBufferBufferSInt8OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpTxSigBufferBufferUInt16Type, COM_CODE) Com_GetSizeOfTmpTxSigBufferBufferUInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTmpTxSigBufferBufferUInt16Type) Com_GetSizeOfTmpTxSigBufferBufferUInt16OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpTxSigBufferBufferUInt32Type, COM_CODE) Com_GetSizeOfTmpTxSigBufferBufferUInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTmpTxSigBufferBufferUInt32Type) Com_GetSizeOfTmpTxSigBufferBufferUInt32OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpTxSigBufferBufferUInt64Type, COM_CODE) Com_GetSizeOfTmpTxSigBufferBufferUInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTmpTxSigBufferBufferUInt64Type) Com_GetSizeOfTmpTxSigBufferBufferUInt64OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTmpTxSigBufferBufferUInt8Type, COM_CODE) Com_GetSizeOfTmpTxSigBufferBufferUInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTmpTxSigBufferBufferUInt8Type) Com_GetSizeOfTmpTxSigBufferBufferUInt8OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfVCprQueueType, COM_CODE) Com_GetSizeOfVCprQueue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfVCprQueueType) Com_GetSizeOfVCprQueueOfPCConfig();
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
COM_LOCAL_INLINE FUNC(Com_CprQueueBufferEndIdxOfCprQueueType, COM_CODE) Com_GetCprQueueBufferEndIdxOfCprQueue(Com_CCprQueueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_CprQueueBufferEndIdxOfCprQueueType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_CprQueueBufferLengthOfCprQueueType, COM_CODE) Com_GetCprQueueBufferLengthOfCprQueue(Com_CCprQueueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_CprQueueBufferLengthOfCprQueueType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_CprQueueBufferStartIdxOfCprQueueType, COM_CODE) Com_GetCprQueueBufferStartIdxOfCprQueue(Com_CCprQueueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_CprQueueBufferStartIdxOfCprQueueType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_CprQueueBufferType, COM_CODE) Com_GetCprQueueBuffer(Com_CprQueueBufferIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_CprQueueBufferType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferArrayBasedType, COM_CODE) Com_GetTmpTxSigBufferBufferArrayBased(Com_TmpTxSigBufferBufferArrayBasedIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferBufferArrayBasedType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferFloat32Type, COM_CODE) Com_GetTmpTxSigBufferBufferFloat32(Com_TmpTxSigBufferBufferFloat32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferBufferFloat32Type) (0.0F);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferFloat64Type, COM_CODE) Com_GetTmpTxSigBufferBufferFloat64(Com_TmpTxSigBufferBufferFloat64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferBufferFloat64Type) (0.0);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferSInt16Type, COM_CODE) Com_GetTmpTxSigBufferBufferSInt16(Com_TmpTxSigBufferBufferSInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferBufferSInt16Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferSInt32Type, COM_CODE) Com_GetTmpTxSigBufferBufferSInt32(Com_TmpTxSigBufferBufferSInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferBufferSInt32Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferSInt64Type, COM_CODE) Com_GetTmpTxSigBufferBufferSInt64(Com_TmpTxSigBufferBufferSInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferBufferSInt64Type) (0LL);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferSInt8Type, COM_CODE) Com_GetTmpTxSigBufferBufferSInt8(Com_TmpTxSigBufferBufferSInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferBufferSInt8Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferUInt16Type, COM_CODE) Com_GetTmpTxSigBufferBufferUInt16(Com_TmpTxSigBufferBufferUInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferBufferUInt16Type) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferUInt32Type, COM_CODE) Com_GetTmpTxSigBufferBufferUInt32(Com_TmpTxSigBufferBufferUInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferBufferUInt32Type) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferUInt64Type, COM_CODE) Com_GetTmpTxSigBufferBufferUInt64(Com_TmpTxSigBufferBufferUInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferBufferUInt64Type) (0uLL);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferUInt8Type, COM_CODE) Com_GetTmpTxSigBufferBufferUInt8(Com_TmpTxSigBufferBufferUInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferBufferUInt8Type) (0u);
}
COM_LOCAL_INLINE FUNC(Com_CprQueueBufferNumberOfBytesReadIdxOfCprQueueType, COM_CODE) Com_GetCprQueueBufferNumberOfBytesReadIdxOfCprQueue(Com_VCprQueueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_CprQueueBufferNumberOfBytesReadIdxOfCprQueueType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_CprQueueBufferPendingReadIdxOfCprQueueType, COM_CODE) Com_GetCprQueueBufferPendingReadIdxOfCprQueue(Com_VCprQueueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_CprQueueBufferPendingReadIdxOfCprQueueType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_CprQueueBufferPendingWriteIdxOfCprQueueType, COM_CODE) Com_GetCprQueueBufferPendingWriteIdxOfCprQueue(Com_VCprQueueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_CprQueueBufferPendingWriteIdxOfCprQueueType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_CprQueueBufferReadIdxOfCprQueueType, COM_CODE) Com_GetCprQueueBufferReadIdxOfCprQueue(Com_VCprQueueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_CprQueueBufferReadIdxOfCprQueueType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_CprQueueBufferWriteIdxOfCprQueueType, COM_CODE) Com_GetCprQueueBufferWriteIdxOfCprQueue(Com_VCprQueueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_CprQueueBufferWriteIdxOfCprQueueType) (0u);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetCprQueueBuffer(Com_CprQueueBufferIterType Index, Com_CprQueueBufferType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpTxSigBufferBufferArrayBased(Com_TmpTxSigBufferBufferArrayBasedIterType Index, Com_TmpTxSigBufferBufferArrayBasedType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpTxSigBufferBufferFloat32(Com_TmpTxSigBufferBufferFloat32IterType Index, Com_TmpTxSigBufferBufferFloat32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpTxSigBufferBufferFloat64(Com_TmpTxSigBufferBufferFloat64IterType Index, Com_TmpTxSigBufferBufferFloat64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpTxSigBufferBufferSInt16(Com_TmpTxSigBufferBufferSInt16IterType Index, Com_TmpTxSigBufferBufferSInt16Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpTxSigBufferBufferSInt32(Com_TmpTxSigBufferBufferSInt32IterType Index, Com_TmpTxSigBufferBufferSInt32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpTxSigBufferBufferSInt64(Com_TmpTxSigBufferBufferSInt64IterType Index, Com_TmpTxSigBufferBufferSInt64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpTxSigBufferBufferSInt8(Com_TmpTxSigBufferBufferSInt8IterType Index, Com_TmpTxSigBufferBufferSInt8Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpTxSigBufferBufferUInt16(Com_TmpTxSigBufferBufferUInt16IterType Index, Com_TmpTxSigBufferBufferUInt16Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpTxSigBufferBufferUInt32(Com_TmpTxSigBufferBufferUInt32IterType Index, Com_TmpTxSigBufferBufferUInt32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpTxSigBufferBufferUInt64(Com_TmpTxSigBufferBufferUInt64IterType Index, Com_TmpTxSigBufferBufferUInt64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTmpTxSigBufferBufferUInt8(Com_TmpTxSigBufferBufferUInt8IterType Index, Com_TmpTxSigBufferBufferUInt8Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetCprQueueBufferNumberOfBytesReadIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferNumberOfBytesReadIdxOfCprQueueType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetCprQueueBufferPendingReadIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferPendingReadIdxOfCprQueueType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetCprQueueBufferPendingWriteIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferPendingWriteIdxOfCprQueueType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetCprQueueBufferReadIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferReadIdxOfCprQueueType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetCprQueueBufferWriteIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferWriteIdxOfCprQueueType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(Com_CprQueueBufferPtrType, COM_CODE) Com_GetAddrCprQueueBuffer(Com_CprQueueBufferIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_CprQueueBufferPtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferArrayBasedPtrType, COM_CODE) Com_GetAddrTmpTxSigBufferBufferArrayBased(Com_TmpTxSigBufferBufferArrayBasedIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferBufferArrayBasedPtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferFloat32PtrType, COM_CODE) Com_GetAddrTmpTxSigBufferBufferFloat32(Com_TmpTxSigBufferBufferFloat32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferBufferFloat32PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferFloat64PtrType, COM_CODE) Com_GetAddrTmpTxSigBufferBufferFloat64(Com_TmpTxSigBufferBufferFloat64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferBufferFloat64PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferSInt16PtrType, COM_CODE) Com_GetAddrTmpTxSigBufferBufferSInt16(Com_TmpTxSigBufferBufferSInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferBufferSInt16PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferSInt32PtrType, COM_CODE) Com_GetAddrTmpTxSigBufferBufferSInt32(Com_TmpTxSigBufferBufferSInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferBufferSInt32PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferSInt64PtrType, COM_CODE) Com_GetAddrTmpTxSigBufferBufferSInt64(Com_TmpTxSigBufferBufferSInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferBufferSInt64PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferSInt8PtrType, COM_CODE) Com_GetAddrTmpTxSigBufferBufferSInt8(Com_TmpTxSigBufferBufferSInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferBufferSInt8PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferUInt16PtrType, COM_CODE) Com_GetAddrTmpTxSigBufferBufferUInt16(Com_TmpTxSigBufferBufferUInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferBufferUInt16PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferUInt32PtrType, COM_CODE) Com_GetAddrTmpTxSigBufferBufferUInt32(Com_TmpTxSigBufferBufferUInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferBufferUInt32PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferUInt64PtrType, COM_CODE) Com_GetAddrTmpTxSigBufferBufferUInt64(Com_TmpTxSigBufferBufferUInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferBufferUInt64PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TmpTxSigBufferBufferUInt8PtrType, COM_CODE) Com_GetAddrTmpTxSigBufferBufferUInt8(Com_TmpTxSigBufferBufferUInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TmpTxSigBufferBufferUInt8PtrType) (NULL_PTR);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCCprQueue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueBufferEndIdxOfCprQueue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueBufferLengthOfCprQueue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueBufferStartIdxOfCprQueue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueBuffer(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfCCprQueue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfCprQueueBuffer(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpTxSigBufferBufferArrayBased(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpTxSigBufferBufferFloat32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpTxSigBufferBufferFloat64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpTxSigBufferBufferSInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpTxSigBufferBufferSInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpTxSigBufferBufferSInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpTxSigBufferBufferSInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpTxSigBufferBufferUInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpTxSigBufferBufferUInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpTxSigBufferBufferUInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTmpTxSigBufferBufferUInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfVCprQueue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferBufferArrayBased(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferBufferFloat32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferBufferFloat64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferBufferSInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferBufferSInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferBufferSInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferBufferSInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferBufferUInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferBufferUInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferBufferUInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTmpTxSigBufferBufferUInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasVCprQueue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueBufferNumberOfBytesReadIdxOfCprQueue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueBufferPendingReadIdxOfCprQueue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueBufferPendingWriteIdxOfCprQueue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueBufferReadIdxOfCprQueue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCprQueueBufferWriteIdxOfCprQueue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncCprQueueBuffer(Com_CprQueueBufferIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpTxSigBufferBufferArrayBased(Com_TmpTxSigBufferBufferArrayBasedIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpTxSigBufferBufferSInt16(Com_TmpTxSigBufferBufferSInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpTxSigBufferBufferSInt32(Com_TmpTxSigBufferBufferSInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpTxSigBufferBufferSInt64(Com_TmpTxSigBufferBufferSInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpTxSigBufferBufferSInt8(Com_TmpTxSigBufferBufferSInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpTxSigBufferBufferUInt16(Com_TmpTxSigBufferBufferUInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpTxSigBufferBufferUInt32(Com_TmpTxSigBufferBufferUInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpTxSigBufferBufferUInt64(Com_TmpTxSigBufferBufferUInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTmpTxSigBufferBufferUInt8(Com_TmpTxSigBufferBufferUInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncCprQueueBufferNumberOfBytesReadIdxOfCprQueue(Com_VCprQueueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncCprQueueBufferPendingReadIdxOfCprQueue(Com_VCprQueueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncCprQueueBufferPendingWriteIdxOfCprQueue(Com_VCprQueueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncCprQueueBufferReadIdxOfCprQueue(Com_VCprQueueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncCprQueueBufferWriteIdxOfCprQueue(Com_VCprQueueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecCprQueueBuffer(Com_CprQueueBufferIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpTxSigBufferBufferArrayBased(Com_TmpTxSigBufferBufferArrayBasedIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpTxSigBufferBufferSInt16(Com_TmpTxSigBufferBufferSInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpTxSigBufferBufferSInt32(Com_TmpTxSigBufferBufferSInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpTxSigBufferBufferSInt64(Com_TmpTxSigBufferBufferSInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpTxSigBufferBufferSInt8(Com_TmpTxSigBufferBufferSInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpTxSigBufferBufferUInt16(Com_TmpTxSigBufferBufferUInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpTxSigBufferBufferUInt32(Com_TmpTxSigBufferBufferUInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpTxSigBufferBufferUInt64(Com_TmpTxSigBufferBufferUInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTmpTxSigBufferBufferUInt8(Com_TmpTxSigBufferBufferUInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecCprQueueBufferNumberOfBytesReadIdxOfCprQueue(Com_VCprQueueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecCprQueueBufferPendingReadIdxOfCprQueue(Com_VCprQueueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecCprQueueBufferPendingWriteIdxOfCprQueue(Com_VCprQueueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecCprQueueBufferReadIdxOfCprQueue(Com_VCprQueueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecCprQueueBufferWriteIdxOfCprQueue(Com_VCprQueueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddCprQueueBuffer(Com_CprQueueBufferIterType Index, Com_CprQueueBufferType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpTxSigBufferBufferArrayBased(Com_TmpTxSigBufferBufferArrayBasedIterType Index, Com_TmpTxSigBufferBufferArrayBasedType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpTxSigBufferBufferSInt16(Com_TmpTxSigBufferBufferSInt16IterType Index, Com_TmpTxSigBufferBufferSInt16Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpTxSigBufferBufferSInt32(Com_TmpTxSigBufferBufferSInt32IterType Index, Com_TmpTxSigBufferBufferSInt32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpTxSigBufferBufferSInt64(Com_TmpTxSigBufferBufferSInt64IterType Index, Com_TmpTxSigBufferBufferSInt64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpTxSigBufferBufferSInt8(Com_TmpTxSigBufferBufferSInt8IterType Index, Com_TmpTxSigBufferBufferSInt8Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpTxSigBufferBufferUInt16(Com_TmpTxSigBufferBufferUInt16IterType Index, Com_TmpTxSigBufferBufferUInt16Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpTxSigBufferBufferUInt32(Com_TmpTxSigBufferBufferUInt32IterType Index, Com_TmpTxSigBufferBufferUInt32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpTxSigBufferBufferUInt64(Com_TmpTxSigBufferBufferUInt64IterType Index, Com_TmpTxSigBufferBufferUInt64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTmpTxSigBufferBufferUInt8(Com_TmpTxSigBufferBufferUInt8IterType Index, Com_TmpTxSigBufferBufferUInt8Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddCprQueueBufferNumberOfBytesReadIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferNumberOfBytesReadIdxOfCprQueueType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddCprQueueBufferPendingReadIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferPendingReadIdxOfCprQueueType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddCprQueueBufferPendingWriteIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferPendingWriteIdxOfCprQueueType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddCprQueueBufferReadIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferReadIdxOfCprQueueType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddCprQueueBufferWriteIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferWriteIdxOfCprQueueType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubCprQueueBuffer(Com_CprQueueBufferIterType Index, Com_CprQueueBufferType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpTxSigBufferBufferArrayBased(Com_TmpTxSigBufferBufferArrayBasedIterType Index, Com_TmpTxSigBufferBufferArrayBasedType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpTxSigBufferBufferSInt16(Com_TmpTxSigBufferBufferSInt16IterType Index, Com_TmpTxSigBufferBufferSInt16Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpTxSigBufferBufferSInt32(Com_TmpTxSigBufferBufferSInt32IterType Index, Com_TmpTxSigBufferBufferSInt32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpTxSigBufferBufferSInt64(Com_TmpTxSigBufferBufferSInt64IterType Index, Com_TmpTxSigBufferBufferSInt64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpTxSigBufferBufferSInt8(Com_TmpTxSigBufferBufferSInt8IterType Index, Com_TmpTxSigBufferBufferSInt8Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpTxSigBufferBufferUInt16(Com_TmpTxSigBufferBufferUInt16IterType Index, Com_TmpTxSigBufferBufferUInt16Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpTxSigBufferBufferUInt32(Com_TmpTxSigBufferBufferUInt32IterType Index, Com_TmpTxSigBufferBufferUInt32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpTxSigBufferBufferUInt64(Com_TmpTxSigBufferBufferUInt64IterType Index, Com_TmpTxSigBufferBufferUInt64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTmpTxSigBufferBufferUInt8(Com_TmpTxSigBufferBufferUInt8IterType Index, Com_TmpTxSigBufferBufferUInt8Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubCprQueueBufferNumberOfBytesReadIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferNumberOfBytesReadIdxOfCprQueueType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubCprQueueBufferPendingReadIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferPendingReadIdxOfCprQueueType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubCprQueueBufferPendingWriteIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferPendingWriteIdxOfCprQueueType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubCprQueueBufferReadIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferReadIdxOfCprQueueType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubCprQueueBufferWriteIdxOfCprQueue(Com_VCprQueueIterType Index, Com_CprQueueBufferWriteIdxOfCprQueueType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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

#endif  /* COM_CFG_CROSSPARTITIONQUEUEDATA_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cfg_CrossPartitionQueueData.h
**********************************************************************************************************************/

