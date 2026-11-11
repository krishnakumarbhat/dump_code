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
 *              File: Com_Cfg_TxSignalFiltering.h
 *   Generation Time: 2026-04-02 15:10:38
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

#if !defined (COM_CFG_TXSIGNALFILTERING_H)
# define COM_CFG_TXSIGNALFILTERING_H

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
COM_LOCAL_INLINE FUNC(Com_SizeOfTransferPropertyFilterInfoType, COM_CODE) Com_GetSizeOfTransferPropertyFilterInfo(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTransferPropertyFilterInfoIndType, COM_CODE) Com_GetSizeOfTransferPropertyFilterInfoInd(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTransmissionModeFilterInfoType, COM_CODE) Com_GetSizeOfTransmissionModeFilterInfo(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTransmissionModeFilterInfoIndType, COM_CODE) Com_GetSizeOfTransmissionModeFilterInfoInd(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterInitValueArrayBasedType, COM_CODE) Com_GetSizeOfTxFilterInitValueArrayBased(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterInitValueFloat32Type, COM_CODE) Com_GetSizeOfTxFilterInitValueFloat32(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterInitValueFloat64Type, COM_CODE) Com_GetSizeOfTxFilterInitValueFloat64(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterInitValueSInt16Type, COM_CODE) Com_GetSizeOfTxFilterInitValueSInt16(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterInitValueSInt32Type, COM_CODE) Com_GetSizeOfTxFilterInitValueSInt32(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterInitValueSInt64Type, COM_CODE) Com_GetSizeOfTxFilterInitValueSInt64(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterInitValueSInt8Type, COM_CODE) Com_GetSizeOfTxFilterInitValueSInt8(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterInitValueSigGrpArrayAccessType, COM_CODE) Com_GetSizeOfTxFilterInitValueSigGrpArrayAccess(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterInitValueUInt16Type, COM_CODE) Com_GetSizeOfTxFilterInitValueUInt16(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterInitValueUInt32Type, COM_CODE) Com_GetSizeOfTxFilterInitValueUInt32(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterInitValueUInt64Type, COM_CODE) Com_GetSizeOfTxFilterInitValueUInt64(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterInitValueUInt8Type, COM_CODE) Com_GetSizeOfTxFilterInitValueUInt8(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterOldValueArrayBasedType, COM_CODE) Com_GetSizeOfTxFilterOldValueArrayBased(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterOldValueFloat32Type, COM_CODE) Com_GetSizeOfTxFilterOldValueFloat32(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterOldValueFloat64Type, COM_CODE) Com_GetSizeOfTxFilterOldValueFloat64(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterOldValueSInt16Type, COM_CODE) Com_GetSizeOfTxFilterOldValueSInt16(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterOldValueSInt32Type, COM_CODE) Com_GetSizeOfTxFilterOldValueSInt32(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterOldValueSInt64Type, COM_CODE) Com_GetSizeOfTxFilterOldValueSInt64(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterOldValueSInt8Type, COM_CODE) Com_GetSizeOfTxFilterOldValueSInt8(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterOldValueUInt16Type, COM_CODE) Com_GetSizeOfTxFilterOldValueUInt16(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterOldValueUInt32Type, COM_CODE) Com_GetSizeOfTxFilterOldValueUInt32(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterOldValueUInt64Type, COM_CODE) Com_GetSizeOfTxFilterOldValueUInt64(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterOldValueUInt8Type, COM_CODE) Com_GetSizeOfTxFilterOldValueUInt8(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterStateType, COM_CODE) Com_GetSizeOfTxFilterState(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxPduFilterInfoType, COM_CODE) Com_GetSizeOfTxPduFilterInfo(void);
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
COM_LOCAL_INLINE FUNC(Com_FilterInfoIdxOfTransferPropertyFilterInfoType, COM_CODE) Com_GetFilterInfoIdxOfTransferPropertyFilterInfo(Com_TransferPropertyFilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TransferPropertyFilterInfoIndType, COM_CODE) Com_GetTransferPropertyFilterInfoInd(Com_TransferPropertyFilterInfoIndIterType Index);
COM_LOCAL_INLINE FUNC(Com_FilterInfoIdxOfTransmissionModeFilterInfoType, COM_CODE) Com_GetFilterInfoIdxOfTransmissionModeFilterInfo(Com_TransmissionModeFilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterInitStateOfTransmissionModeFilterInfoType, COM_CODE) Com_IsTxFilterInitStateOfTransmissionModeFilterInfo(Com_TransmissionModeFilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TransmissionModeFilterInfoIndType, COM_CODE) Com_GetTransmissionModeFilterInfoInd(Com_TransmissionModeFilterInfoIndIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueArrayBasedType, COM_CODE) Com_GetTxFilterInitValueArrayBased(Com_TxFilterInitValueArrayBasedIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueFloat32Type, COM_CODE) Com_GetTxFilterInitValueFloat32(Com_TxFilterInitValueFloat32IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueFloat64Type, COM_CODE) Com_GetTxFilterInitValueFloat64(Com_TxFilterInitValueFloat64IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueSInt16Type, COM_CODE) Com_GetTxFilterInitValueSInt16(Com_TxFilterInitValueSInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueSInt32Type, COM_CODE) Com_GetTxFilterInitValueSInt32(Com_TxFilterInitValueSInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueSInt64Type, COM_CODE) Com_GetTxFilterInitValueSInt64(Com_TxFilterInitValueSInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueSInt8Type, COM_CODE) Com_GetTxFilterInitValueSInt8(Com_TxFilterInitValueSInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueSigGrpArrayAccessType, COM_CODE) Com_GetTxFilterInitValueSigGrpArrayAccess(Com_TxFilterInitValueSigGrpArrayAccessIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueUInt16Type, COM_CODE) Com_GetTxFilterInitValueUInt16(Com_TxFilterInitValueUInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueUInt32Type, COM_CODE) Com_GetTxFilterInitValueUInt32(Com_TxFilterInitValueUInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueUInt64Type, COM_CODE) Com_GetTxFilterInitValueUInt64(Com_TxFilterInitValueUInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueUInt8Type, COM_CODE) Com_GetTxFilterInitValueUInt8(Com_TxFilterInitValueUInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueArrayBasedType, COM_CODE) Com_GetTxFilterOldValueArrayBased(Com_TxFilterOldValueArrayBasedIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueFloat32Type, COM_CODE) Com_GetTxFilterOldValueFloat32(Com_TxFilterOldValueFloat32IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueFloat64Type, COM_CODE) Com_GetTxFilterOldValueFloat64(Com_TxFilterOldValueFloat64IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueSInt16Type, COM_CODE) Com_GetTxFilterOldValueSInt16(Com_TxFilterOldValueSInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueSInt32Type, COM_CODE) Com_GetTxFilterOldValueSInt32(Com_TxFilterOldValueSInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueSInt64Type, COM_CODE) Com_GetTxFilterOldValueSInt64(Com_TxFilterOldValueSInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueSInt8Type, COM_CODE) Com_GetTxFilterOldValueSInt8(Com_TxFilterOldValueSInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueUInt16Type, COM_CODE) Com_GetTxFilterOldValueUInt16(Com_TxFilterOldValueUInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueUInt32Type, COM_CODE) Com_GetTxFilterOldValueUInt32(Com_TxFilterOldValueUInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueUInt64Type, COM_CODE) Com_GetTxFilterOldValueUInt64(Com_TxFilterOldValueUInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueUInt8Type, COM_CODE) Com_GetTxFilterOldValueUInt8(Com_TxFilterOldValueUInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterStateType, COM_CODE) Com_IsTxFilterState(Com_TxFilterStateIterType Index);
COM_LOCAL_INLINE FUNC(Com_TransferPropertyFilterInfoIndEndIdxOfTxPduFilterInfoType, COM_CODE) Com_GetTransferPropertyFilterInfoIndEndIdxOfTxPduFilterInfo(Com_TxPduFilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TransferPropertyFilterInfoIndStartIdxOfTxPduFilterInfoType, COM_CODE) Com_GetTransferPropertyFilterInfoIndStartIdxOfTxPduFilterInfo(Com_TxPduFilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TransferPropertyFilterInfoIndUsedOfTxPduFilterInfoType, COM_CODE) Com_IsTransferPropertyFilterInfoIndUsedOfTxPduFilterInfo(Com_TxPduFilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TransmissionModeFilterInfoIndEndIdxOfTxPduFilterInfoType, COM_CODE) Com_GetTransmissionModeFilterInfoIndEndIdxOfTxPduFilterInfo(Com_TxPduFilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TransmissionModeFilterInfoIndStartIdxOfTxPduFilterInfoType, COM_CODE) Com_GetTransmissionModeFilterInfoIndStartIdxOfTxPduFilterInfo(Com_TxPduFilterInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TransmissionModeFilterInfoIndUsedOfTxPduFilterInfoType, COM_CODE) Com_IsTransmissionModeFilterInfoIndUsedOfTxPduFilterInfo(Com_TxPduFilterInfoIterType Index);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxFilterOldValueArrayBased(Com_TxFilterOldValueArrayBasedIterType Index, Com_TxFilterOldValueArrayBasedType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxFilterOldValueFloat32(Com_TxFilterOldValueFloat32IterType Index, Com_TxFilterOldValueFloat32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxFilterOldValueFloat64(Com_TxFilterOldValueFloat64IterType Index, Com_TxFilterOldValueFloat64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxFilterOldValueSInt16(Com_TxFilterOldValueSInt16IterType Index, Com_TxFilterOldValueSInt16Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxFilterOldValueSInt32(Com_TxFilterOldValueSInt32IterType Index, Com_TxFilterOldValueSInt32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxFilterOldValueSInt64(Com_TxFilterOldValueSInt64IterType Index, Com_TxFilterOldValueSInt64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxFilterOldValueSInt8(Com_TxFilterOldValueSInt8IterType Index, Com_TxFilterOldValueSInt8Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxFilterOldValueUInt16(Com_TxFilterOldValueUInt16IterType Index, Com_TxFilterOldValueUInt16Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxFilterOldValueUInt32(Com_TxFilterOldValueUInt32IterType Index, Com_TxFilterOldValueUInt32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxFilterOldValueUInt64(Com_TxFilterOldValueUInt64IterType Index, Com_TxFilterOldValueUInt64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxFilterOldValueUInt8(Com_TxFilterOldValueUInt8IterType Index, Com_TxFilterOldValueUInt8Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxFilterState(Com_TxFilterStateIterType Index, Com_TxFilterStateType Value);
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
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueArrayBasedPtrType, COM_CODE) Com_GetAddrTxFilterInitValueArrayBased(Com_TxFilterInitValueArrayBasedIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueFloat32PtrType, COM_CODE) Com_GetAddrTxFilterInitValueFloat32(Com_TxFilterInitValueFloat32IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueFloat64PtrType, COM_CODE) Com_GetAddrTxFilterInitValueFloat64(Com_TxFilterInitValueFloat64IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueSInt16PtrType, COM_CODE) Com_GetAddrTxFilterInitValueSInt16(Com_TxFilterInitValueSInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueSInt32PtrType, COM_CODE) Com_GetAddrTxFilterInitValueSInt32(Com_TxFilterInitValueSInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueSInt64PtrType, COM_CODE) Com_GetAddrTxFilterInitValueSInt64(Com_TxFilterInitValueSInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueSInt8PtrType, COM_CODE) Com_GetAddrTxFilterInitValueSInt8(Com_TxFilterInitValueSInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueSigGrpArrayAccessPtrType, COM_CODE) Com_GetAddrTxFilterInitValueSigGrpArrayAccess(Com_TxFilterInitValueSigGrpArrayAccessIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueUInt16PtrType, COM_CODE) Com_GetAddrTxFilterInitValueUInt16(Com_TxFilterInitValueUInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueUInt32PtrType, COM_CODE) Com_GetAddrTxFilterInitValueUInt32(Com_TxFilterInitValueUInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueUInt64PtrType, COM_CODE) Com_GetAddrTxFilterInitValueUInt64(Com_TxFilterInitValueUInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueUInt8PtrType, COM_CODE) Com_GetAddrTxFilterInitValueUInt8(Com_TxFilterInitValueUInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueArrayBasedPtrType, COM_CODE) Com_GetAddrTxFilterOldValueArrayBased(Com_TxFilterOldValueArrayBasedIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueFloat32PtrType, COM_CODE) Com_GetAddrTxFilterOldValueFloat32(Com_TxFilterOldValueFloat32IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueFloat64PtrType, COM_CODE) Com_GetAddrTxFilterOldValueFloat64(Com_TxFilterOldValueFloat64IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueSInt16PtrType, COM_CODE) Com_GetAddrTxFilterOldValueSInt16(Com_TxFilterOldValueSInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueSInt32PtrType, COM_CODE) Com_GetAddrTxFilterOldValueSInt32(Com_TxFilterOldValueSInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueSInt64PtrType, COM_CODE) Com_GetAddrTxFilterOldValueSInt64(Com_TxFilterOldValueSInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueSInt8PtrType, COM_CODE) Com_GetAddrTxFilterOldValueSInt8(Com_TxFilterOldValueSInt8IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueUInt16PtrType, COM_CODE) Com_GetAddrTxFilterOldValueUInt16(Com_TxFilterOldValueUInt16IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueUInt32PtrType, COM_CODE) Com_GetAddrTxFilterOldValueUInt32(Com_TxFilterOldValueUInt32IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueUInt64PtrType, COM_CODE) Com_GetAddrTxFilterOldValueUInt64(Com_TxFilterOldValueUInt64IterType Index);
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueUInt8PtrType, COM_CODE) Com_GetAddrTxFilterOldValueUInt8(Com_TxFilterOldValueUInt8IterType Index);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTransferPropertyFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTransferPropertyFilterInfoInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTransmissionModeFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTransmissionModeFilterInfoInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterInitValueArrayBased(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterInitValueFloat32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterInitValueFloat64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterInitValueSInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterInitValueSInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterInitValueSInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterInitValueSInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterInitValueSigGrpArrayAccess(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterInitValueUInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterInitValueUInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterInitValueUInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterInitValueUInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterOldValueArrayBased(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterOldValueFloat32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterOldValueFloat64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterOldValueSInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterOldValueSInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterOldValueSInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterOldValueSInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterOldValueUInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterOldValueUInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterOldValueUInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterOldValueUInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterState(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxPduFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransferPropertyFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfoIdxOfTransferPropertyFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransferPropertyFilterInfoInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransmissionModeFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfoIdxOfTransmissionModeFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitStateOfTransmissionModeFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransmissionModeFilterInfoInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitValueArrayBased(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitValueFloat32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitValueFloat64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitValueSInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitValueSInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitValueSInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitValueSInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitValueSigGrpArrayAccess(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitValueUInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitValueUInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitValueUInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitValueUInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterOldValueArrayBased(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterOldValueFloat32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterOldValueFloat64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterOldValueSInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterOldValueSInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterOldValueSInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterOldValueSInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterOldValueUInt16(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterOldValueUInt32(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterOldValueUInt64(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterOldValueUInt8(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterState(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransferPropertyFilterInfoIndEndIdxOfTxPduFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransferPropertyFilterInfoIndStartIdxOfTxPduFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransferPropertyFilterInfoIndUsedOfTxPduFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransmissionModeFilterInfoIndEndIdxOfTxPduFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransmissionModeFilterInfoIndStartIdxOfTxPduFilterInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransmissionModeFilterInfoIndUsedOfTxPduFilterInfo(void);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTxFilterOldValueArrayBased(Com_TxFilterOldValueArrayBasedIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTxFilterOldValueSInt16(Com_TxFilterOldValueSInt16IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTxFilterOldValueSInt32(Com_TxFilterOldValueSInt32IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTxFilterOldValueSInt64(Com_TxFilterOldValueSInt64IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTxFilterOldValueSInt8(Com_TxFilterOldValueSInt8IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTxFilterOldValueUInt16(Com_TxFilterOldValueUInt16IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTxFilterOldValueUInt32(Com_TxFilterOldValueUInt32IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTxFilterOldValueUInt64(Com_TxFilterOldValueUInt64IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTxFilterOldValueUInt8(Com_TxFilterOldValueUInt8IterType Index);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTxFilterOldValueArrayBased(Com_TxFilterOldValueArrayBasedIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTxFilterOldValueSInt16(Com_TxFilterOldValueSInt16IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTxFilterOldValueSInt32(Com_TxFilterOldValueSInt32IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTxFilterOldValueSInt64(Com_TxFilterOldValueSInt64IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTxFilterOldValueSInt8(Com_TxFilterOldValueSInt8IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTxFilterOldValueUInt16(Com_TxFilterOldValueUInt16IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTxFilterOldValueUInt32(Com_TxFilterOldValueUInt32IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTxFilterOldValueUInt64(Com_TxFilterOldValueUInt64IterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTxFilterOldValueUInt8(Com_TxFilterOldValueUInt8IterType Index);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTxFilterOldValueArrayBased(Com_TxFilterOldValueArrayBasedIterType Index, Com_TxFilterOldValueArrayBasedType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTxFilterOldValueSInt16(Com_TxFilterOldValueSInt16IterType Index, Com_TxFilterOldValueSInt16Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTxFilterOldValueSInt32(Com_TxFilterOldValueSInt32IterType Index, Com_TxFilterOldValueSInt32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTxFilterOldValueSInt64(Com_TxFilterOldValueSInt64IterType Index, Com_TxFilterOldValueSInt64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTxFilterOldValueSInt8(Com_TxFilterOldValueSInt8IterType Index, Com_TxFilterOldValueSInt8Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTxFilterOldValueUInt16(Com_TxFilterOldValueUInt16IterType Index, Com_TxFilterOldValueUInt16Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTxFilterOldValueUInt32(Com_TxFilterOldValueUInt32IterType Index, Com_TxFilterOldValueUInt32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTxFilterOldValueUInt64(Com_TxFilterOldValueUInt64IterType Index, Com_TxFilterOldValueUInt64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTxFilterOldValueUInt8(Com_TxFilterOldValueUInt8IterType Index, Com_TxFilterOldValueUInt8Type Value);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTxFilterOldValueArrayBased(Com_TxFilterOldValueArrayBasedIterType Index, Com_TxFilterOldValueArrayBasedType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTxFilterOldValueSInt16(Com_TxFilterOldValueSInt16IterType Index, Com_TxFilterOldValueSInt16Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTxFilterOldValueSInt32(Com_TxFilterOldValueSInt32IterType Index, Com_TxFilterOldValueSInt32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTxFilterOldValueSInt64(Com_TxFilterOldValueSInt64IterType Index, Com_TxFilterOldValueSInt64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTxFilterOldValueSInt8(Com_TxFilterOldValueSInt8IterType Index, Com_TxFilterOldValueSInt8Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTxFilterOldValueUInt16(Com_TxFilterOldValueUInt16IterType Index, Com_TxFilterOldValueUInt16Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTxFilterOldValueUInt32(Com_TxFilterOldValueUInt32IterType Index, Com_TxFilterOldValueUInt32Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTxFilterOldValueUInt64(Com_TxFilterOldValueUInt64IterType Index, Com_TxFilterOldValueUInt64Type Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTxFilterOldValueUInt8(Com_TxFilterOldValueUInt8IterType Index, Com_TxFilterOldValueUInt8Type Value);
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
COM_LOCAL_INLINE FUNC(Com_SizeOfTransferPropertyFilterInfoType, COM_CODE) Com_GetSizeOfTransferPropertyFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTransferPropertyFilterInfoType) Com_GetSizeOfTransferPropertyFilterInfoOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTransferPropertyFilterInfoIndType, COM_CODE) Com_GetSizeOfTransferPropertyFilterInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTransferPropertyFilterInfoIndType) Com_GetSizeOfTransferPropertyFilterInfoIndOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTransmissionModeFilterInfoType, COM_CODE) Com_GetSizeOfTransmissionModeFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTransmissionModeFilterInfoType) Com_GetSizeOfTransmissionModeFilterInfoOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTransmissionModeFilterInfoIndType, COM_CODE) Com_GetSizeOfTransmissionModeFilterInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTransmissionModeFilterInfoIndType) Com_GetSizeOfTransmissionModeFilterInfoIndOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterInitValueArrayBasedType, COM_CODE) Com_GetSizeOfTxFilterInitValueArrayBased(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxFilterInitValueArrayBasedType) Com_GetSizeOfTxFilterInitValueArrayBasedOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterInitValueFloat32Type, COM_CODE) Com_GetSizeOfTxFilterInitValueFloat32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxFilterInitValueFloat32Type) Com_GetSizeOfTxFilterInitValueFloat32OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterInitValueFloat64Type, COM_CODE) Com_GetSizeOfTxFilterInitValueFloat64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxFilterInitValueFloat64Type) Com_GetSizeOfTxFilterInitValueFloat64OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterInitValueSInt16Type, COM_CODE) Com_GetSizeOfTxFilterInitValueSInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxFilterInitValueSInt16Type) Com_GetSizeOfTxFilterInitValueSInt16OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterInitValueSInt32Type, COM_CODE) Com_GetSizeOfTxFilterInitValueSInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxFilterInitValueSInt32Type) Com_GetSizeOfTxFilterInitValueSInt32OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterInitValueSInt64Type, COM_CODE) Com_GetSizeOfTxFilterInitValueSInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxFilterInitValueSInt64Type) Com_GetSizeOfTxFilterInitValueSInt64OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterInitValueSInt8Type, COM_CODE) Com_GetSizeOfTxFilterInitValueSInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxFilterInitValueSInt8Type) Com_GetSizeOfTxFilterInitValueSInt8OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterInitValueSigGrpArrayAccessType, COM_CODE) Com_GetSizeOfTxFilterInitValueSigGrpArrayAccess(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxFilterInitValueSigGrpArrayAccessType) Com_GetSizeOfTxFilterInitValueSigGrpArrayAccessOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterInitValueUInt16Type, COM_CODE) Com_GetSizeOfTxFilterInitValueUInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxFilterInitValueUInt16Type) Com_GetSizeOfTxFilterInitValueUInt16OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterInitValueUInt32Type, COM_CODE) Com_GetSizeOfTxFilterInitValueUInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxFilterInitValueUInt32Type) Com_GetSizeOfTxFilterInitValueUInt32OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterInitValueUInt64Type, COM_CODE) Com_GetSizeOfTxFilterInitValueUInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxFilterInitValueUInt64Type) Com_GetSizeOfTxFilterInitValueUInt64OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterInitValueUInt8Type, COM_CODE) Com_GetSizeOfTxFilterInitValueUInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxFilterInitValueUInt8Type) Com_GetSizeOfTxFilterInitValueUInt8OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterOldValueArrayBasedType, COM_CODE) Com_GetSizeOfTxFilterOldValueArrayBased(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxFilterOldValueArrayBasedType) Com_GetSizeOfTxFilterOldValueArrayBasedOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterOldValueFloat32Type, COM_CODE) Com_GetSizeOfTxFilterOldValueFloat32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxFilterOldValueFloat32Type) Com_GetSizeOfTxFilterOldValueFloat32OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterOldValueFloat64Type, COM_CODE) Com_GetSizeOfTxFilterOldValueFloat64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxFilterOldValueFloat64Type) Com_GetSizeOfTxFilterOldValueFloat64OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterOldValueSInt16Type, COM_CODE) Com_GetSizeOfTxFilterOldValueSInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxFilterOldValueSInt16Type) Com_GetSizeOfTxFilterOldValueSInt16OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterOldValueSInt32Type, COM_CODE) Com_GetSizeOfTxFilterOldValueSInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxFilterOldValueSInt32Type) Com_GetSizeOfTxFilterOldValueSInt32OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterOldValueSInt64Type, COM_CODE) Com_GetSizeOfTxFilterOldValueSInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxFilterOldValueSInt64Type) Com_GetSizeOfTxFilterOldValueSInt64OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterOldValueSInt8Type, COM_CODE) Com_GetSizeOfTxFilterOldValueSInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxFilterOldValueSInt8Type) Com_GetSizeOfTxFilterOldValueSInt8OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterOldValueUInt16Type, COM_CODE) Com_GetSizeOfTxFilterOldValueUInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxFilterOldValueUInt16Type) Com_GetSizeOfTxFilterOldValueUInt16OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterOldValueUInt32Type, COM_CODE) Com_GetSizeOfTxFilterOldValueUInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxFilterOldValueUInt32Type) Com_GetSizeOfTxFilterOldValueUInt32OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterOldValueUInt64Type, COM_CODE) Com_GetSizeOfTxFilterOldValueUInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxFilterOldValueUInt64Type) Com_GetSizeOfTxFilterOldValueUInt64OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterOldValueUInt8Type, COM_CODE) Com_GetSizeOfTxFilterOldValueUInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxFilterOldValueUInt8Type) Com_GetSizeOfTxFilterOldValueUInt8OfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxFilterStateType, COM_CODE) Com_GetSizeOfTxFilterState(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxFilterStateType) Com_GetSizeOfTxFilterStateOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxPduFilterInfoType, COM_CODE) Com_GetSizeOfTxPduFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxPduFilterInfoType) Com_GetSizeOfTxPduFilterInfoOfPCConfig();
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
COM_LOCAL_INLINE FUNC(Com_FilterInfoIdxOfTransferPropertyFilterInfoType, COM_CODE) Com_GetFilterInfoIdxOfTransferPropertyFilterInfo(Com_TransferPropertyFilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterInfoIdxOfTransferPropertyFilterInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TransferPropertyFilterInfoIndType, COM_CODE) Com_GetTransferPropertyFilterInfoInd(Com_TransferPropertyFilterInfoIndIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TransferPropertyFilterInfoIndType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_FilterInfoIdxOfTransmissionModeFilterInfoType, COM_CODE) Com_GetFilterInfoIdxOfTransmissionModeFilterInfo(Com_TransmissionModeFilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_FilterInfoIdxOfTransmissionModeFilterInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterInitStateOfTransmissionModeFilterInfoType, COM_CODE) Com_IsTxFilterInitStateOfTransmissionModeFilterInfo(Com_TransmissionModeFilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterInitStateOfTransmissionModeFilterInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TransmissionModeFilterInfoIndType, COM_CODE) Com_GetTransmissionModeFilterInfoInd(Com_TransmissionModeFilterInfoIndIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TransmissionModeFilterInfoIndType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueArrayBasedType, COM_CODE) Com_GetTxFilterInitValueArrayBased(Com_TxFilterInitValueArrayBasedIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterInitValueArrayBasedType) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueFloat32Type, COM_CODE) Com_GetTxFilterInitValueFloat32(Com_TxFilterInitValueFloat32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterInitValueFloat32Type) (0.0F);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueFloat64Type, COM_CODE) Com_GetTxFilterInitValueFloat64(Com_TxFilterInitValueFloat64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterInitValueFloat64Type) (0.0);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueSInt16Type, COM_CODE) Com_GetTxFilterInitValueSInt16(Com_TxFilterInitValueSInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterInitValueSInt16Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueSInt32Type, COM_CODE) Com_GetTxFilterInitValueSInt32(Com_TxFilterInitValueSInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterInitValueSInt32Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueSInt64Type, COM_CODE) Com_GetTxFilterInitValueSInt64(Com_TxFilterInitValueSInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterInitValueSInt64Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueSInt8Type, COM_CODE) Com_GetTxFilterInitValueSInt8(Com_TxFilterInitValueSInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterInitValueSInt8Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueSigGrpArrayAccessType, COM_CODE) Com_GetTxFilterInitValueSigGrpArrayAccess(Com_TxFilterInitValueSigGrpArrayAccessIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterInitValueSigGrpArrayAccessType) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueUInt16Type, COM_CODE) Com_GetTxFilterInitValueUInt16(Com_TxFilterInitValueUInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterInitValueUInt16Type) (0x0000u);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueUInt32Type, COM_CODE) Com_GetTxFilterInitValueUInt32(Com_TxFilterInitValueUInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterInitValueUInt32Type) (0x00000000u);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueUInt64Type, COM_CODE) Com_GetTxFilterInitValueUInt64(Com_TxFilterInitValueUInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterInitValueUInt64Type) (0x0000000000000000uLL);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueUInt8Type, COM_CODE) Com_GetTxFilterInitValueUInt8(Com_TxFilterInitValueUInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterInitValueUInt8Type) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueArrayBasedType, COM_CODE) Com_GetTxFilterOldValueArrayBased(Com_TxFilterOldValueArrayBasedIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterOldValueArrayBasedType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueFloat32Type, COM_CODE) Com_GetTxFilterOldValueFloat32(Com_TxFilterOldValueFloat32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterOldValueFloat32Type) (0.0F);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueFloat64Type, COM_CODE) Com_GetTxFilterOldValueFloat64(Com_TxFilterOldValueFloat64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterOldValueFloat64Type) (0.0);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueSInt16Type, COM_CODE) Com_GetTxFilterOldValueSInt16(Com_TxFilterOldValueSInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterOldValueSInt16Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueSInt32Type, COM_CODE) Com_GetTxFilterOldValueSInt32(Com_TxFilterOldValueSInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterOldValueSInt32Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueSInt64Type, COM_CODE) Com_GetTxFilterOldValueSInt64(Com_TxFilterOldValueSInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterOldValueSInt64Type) (0LL);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueSInt8Type, COM_CODE) Com_GetTxFilterOldValueSInt8(Com_TxFilterOldValueSInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterOldValueSInt8Type) (0);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueUInt16Type, COM_CODE) Com_GetTxFilterOldValueUInt16(Com_TxFilterOldValueUInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterOldValueUInt16Type) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueUInt32Type, COM_CODE) Com_GetTxFilterOldValueUInt32(Com_TxFilterOldValueUInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterOldValueUInt32Type) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueUInt64Type, COM_CODE) Com_GetTxFilterOldValueUInt64(Com_TxFilterOldValueUInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterOldValueUInt64Type) (0uLL);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueUInt8Type, COM_CODE) Com_GetTxFilterOldValueUInt8(Com_TxFilterOldValueUInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterOldValueUInt8Type) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterStateType, COM_CODE) Com_IsTxFilterState(Com_TxFilterStateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterStateType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TransferPropertyFilterInfoIndEndIdxOfTxPduFilterInfoType, COM_CODE) Com_GetTransferPropertyFilterInfoIndEndIdxOfTxPduFilterInfo(Com_TxPduFilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TransferPropertyFilterInfoIndEndIdxOfTxPduFilterInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TransferPropertyFilterInfoIndStartIdxOfTxPduFilterInfoType, COM_CODE) Com_GetTransferPropertyFilterInfoIndStartIdxOfTxPduFilterInfo(Com_TxPduFilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TransferPropertyFilterInfoIndStartIdxOfTxPduFilterInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TransferPropertyFilterInfoIndUsedOfTxPduFilterInfoType, COM_CODE) Com_IsTransferPropertyFilterInfoIndUsedOfTxPduFilterInfo(Com_TxPduFilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TransferPropertyFilterInfoIndUsedOfTxPduFilterInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TransmissionModeFilterInfoIndEndIdxOfTxPduFilterInfoType, COM_CODE) Com_GetTransmissionModeFilterInfoIndEndIdxOfTxPduFilterInfo(Com_TxPduFilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TransmissionModeFilterInfoIndEndIdxOfTxPduFilterInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TransmissionModeFilterInfoIndStartIdxOfTxPduFilterInfoType, COM_CODE) Com_GetTransmissionModeFilterInfoIndStartIdxOfTxPduFilterInfo(Com_TxPduFilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TransmissionModeFilterInfoIndStartIdxOfTxPduFilterInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TransmissionModeFilterInfoIndUsedOfTxPduFilterInfoType, COM_CODE) Com_IsTransmissionModeFilterInfoIndUsedOfTxPduFilterInfo(Com_TxPduFilterInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TransmissionModeFilterInfoIndUsedOfTxPduFilterInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxFilterOldValueArrayBased(Com_TxFilterOldValueArrayBasedIterType Index, Com_TxFilterOldValueArrayBasedType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxFilterOldValueFloat32(Com_TxFilterOldValueFloat32IterType Index, Com_TxFilterOldValueFloat32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxFilterOldValueFloat64(Com_TxFilterOldValueFloat64IterType Index, Com_TxFilterOldValueFloat64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxFilterOldValueSInt16(Com_TxFilterOldValueSInt16IterType Index, Com_TxFilterOldValueSInt16Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxFilterOldValueSInt32(Com_TxFilterOldValueSInt32IterType Index, Com_TxFilterOldValueSInt32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxFilterOldValueSInt64(Com_TxFilterOldValueSInt64IterType Index, Com_TxFilterOldValueSInt64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxFilterOldValueSInt8(Com_TxFilterOldValueSInt8IterType Index, Com_TxFilterOldValueSInt8Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxFilterOldValueUInt16(Com_TxFilterOldValueUInt16IterType Index, Com_TxFilterOldValueUInt16Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxFilterOldValueUInt32(Com_TxFilterOldValueUInt32IterType Index, Com_TxFilterOldValueUInt32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxFilterOldValueUInt64(Com_TxFilterOldValueUInt64IterType Index, Com_TxFilterOldValueUInt64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxFilterOldValueUInt8(Com_TxFilterOldValueUInt8IterType Index, Com_TxFilterOldValueUInt8Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetTxFilterState(Com_TxFilterStateIterType Index, Com_TxFilterStateType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueArrayBasedPtrType, COM_CODE) Com_GetAddrTxFilterInitValueArrayBased(Com_TxFilterInitValueArrayBasedIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterInitValueArrayBasedPtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueFloat32PtrType, COM_CODE) Com_GetAddrTxFilterInitValueFloat32(Com_TxFilterInitValueFloat32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterInitValueFloat32PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueFloat64PtrType, COM_CODE) Com_GetAddrTxFilterInitValueFloat64(Com_TxFilterInitValueFloat64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterInitValueFloat64PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueSInt16PtrType, COM_CODE) Com_GetAddrTxFilterInitValueSInt16(Com_TxFilterInitValueSInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterInitValueSInt16PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueSInt32PtrType, COM_CODE) Com_GetAddrTxFilterInitValueSInt32(Com_TxFilterInitValueSInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterInitValueSInt32PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueSInt64PtrType, COM_CODE) Com_GetAddrTxFilterInitValueSInt64(Com_TxFilterInitValueSInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterInitValueSInt64PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueSInt8PtrType, COM_CODE) Com_GetAddrTxFilterInitValueSInt8(Com_TxFilterInitValueSInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterInitValueSInt8PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueSigGrpArrayAccessPtrType, COM_CODE) Com_GetAddrTxFilterInitValueSigGrpArrayAccess(Com_TxFilterInitValueSigGrpArrayAccessIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterInitValueSigGrpArrayAccessPtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueUInt16PtrType, COM_CODE) Com_GetAddrTxFilterInitValueUInt16(Com_TxFilterInitValueUInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterInitValueUInt16PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueUInt32PtrType, COM_CODE) Com_GetAddrTxFilterInitValueUInt32(Com_TxFilterInitValueUInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterInitValueUInt32PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueUInt64PtrType, COM_CODE) Com_GetAddrTxFilterInitValueUInt64(Com_TxFilterInitValueUInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterInitValueUInt64PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterInitValueUInt8PtrType, COM_CODE) Com_GetAddrTxFilterInitValueUInt8(Com_TxFilterInitValueUInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterInitValueUInt8PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueArrayBasedPtrType, COM_CODE) Com_GetAddrTxFilterOldValueArrayBased(Com_TxFilterOldValueArrayBasedIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterOldValueArrayBasedPtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueFloat32PtrType, COM_CODE) Com_GetAddrTxFilterOldValueFloat32(Com_TxFilterOldValueFloat32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterOldValueFloat32PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueFloat64PtrType, COM_CODE) Com_GetAddrTxFilterOldValueFloat64(Com_TxFilterOldValueFloat64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterOldValueFloat64PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueSInt16PtrType, COM_CODE) Com_GetAddrTxFilterOldValueSInt16(Com_TxFilterOldValueSInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterOldValueSInt16PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueSInt32PtrType, COM_CODE) Com_GetAddrTxFilterOldValueSInt32(Com_TxFilterOldValueSInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterOldValueSInt32PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueSInt64PtrType, COM_CODE) Com_GetAddrTxFilterOldValueSInt64(Com_TxFilterOldValueSInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterOldValueSInt64PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueSInt8PtrType, COM_CODE) Com_GetAddrTxFilterOldValueSInt8(Com_TxFilterOldValueSInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterOldValueSInt8PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueUInt16PtrType, COM_CODE) Com_GetAddrTxFilterOldValueUInt16(Com_TxFilterOldValueUInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterOldValueUInt16PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueUInt32PtrType, COM_CODE) Com_GetAddrTxFilterOldValueUInt32(Com_TxFilterOldValueUInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterOldValueUInt32PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueUInt64PtrType, COM_CODE) Com_GetAddrTxFilterOldValueUInt64(Com_TxFilterOldValueUInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterOldValueUInt64PtrType) (NULL_PTR);
}
COM_LOCAL_INLINE FUNC(Com_TxFilterOldValueUInt8PtrType, COM_CODE) Com_GetAddrTxFilterOldValueUInt8(Com_TxFilterOldValueUInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxFilterOldValueUInt8PtrType) (NULL_PTR);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTransferPropertyFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTransferPropertyFilterInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTransmissionModeFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTransmissionModeFilterInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterInitValueArrayBased(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterInitValueFloat32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterInitValueFloat64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterInitValueSInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterInitValueSInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterInitValueSInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterInitValueSInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterInitValueSigGrpArrayAccess(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterInitValueUInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterInitValueUInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterInitValueUInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterInitValueUInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterOldValueArrayBased(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterOldValueFloat32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterOldValueFloat64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterOldValueSInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterOldValueSInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterOldValueSInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterOldValueSInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterOldValueUInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterOldValueUInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterOldValueUInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterOldValueUInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxFilterState(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxPduFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransferPropertyFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfoIdxOfTransferPropertyFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransferPropertyFilterInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransmissionModeFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasFilterInfoIdxOfTransmissionModeFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitStateOfTransmissionModeFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransmissionModeFilterInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitValueArrayBased(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitValueFloat32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitValueFloat64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitValueSInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitValueSInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitValueSInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitValueSInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitValueSigGrpArrayAccess(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitValueUInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitValueUInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitValueUInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterInitValueUInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterOldValueArrayBased(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterOldValueFloat32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterOldValueFloat64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterOldValueSInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterOldValueSInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterOldValueSInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterOldValueSInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterOldValueUInt16(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterOldValueUInt32(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterOldValueUInt64(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterOldValueUInt8(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxFilterState(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransferPropertyFilterInfoIndEndIdxOfTxPduFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransferPropertyFilterInfoIndStartIdxOfTxPduFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransferPropertyFilterInfoIndUsedOfTxPduFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransmissionModeFilterInfoIndEndIdxOfTxPduFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransmissionModeFilterInfoIndStartIdxOfTxPduFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTransmissionModeFilterInfoIndUsedOfTxPduFilterInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTxFilterOldValueArrayBased(Com_TxFilterOldValueArrayBasedIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTxFilterOldValueSInt16(Com_TxFilterOldValueSInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTxFilterOldValueSInt32(Com_TxFilterOldValueSInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTxFilterOldValueSInt64(Com_TxFilterOldValueSInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTxFilterOldValueSInt8(Com_TxFilterOldValueSInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTxFilterOldValueUInt16(Com_TxFilterOldValueUInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTxFilterOldValueUInt32(Com_TxFilterOldValueUInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTxFilterOldValueUInt64(Com_TxFilterOldValueUInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncTxFilterOldValueUInt8(Com_TxFilterOldValueUInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTxFilterOldValueArrayBased(Com_TxFilterOldValueArrayBasedIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTxFilterOldValueSInt16(Com_TxFilterOldValueSInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTxFilterOldValueSInt32(Com_TxFilterOldValueSInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTxFilterOldValueSInt64(Com_TxFilterOldValueSInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTxFilterOldValueSInt8(Com_TxFilterOldValueSInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTxFilterOldValueUInt16(Com_TxFilterOldValueUInt16IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTxFilterOldValueUInt32(Com_TxFilterOldValueUInt32IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTxFilterOldValueUInt64(Com_TxFilterOldValueUInt64IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecTxFilterOldValueUInt8(Com_TxFilterOldValueUInt8IterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTxFilterOldValueArrayBased(Com_TxFilterOldValueArrayBasedIterType Index, Com_TxFilterOldValueArrayBasedType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTxFilterOldValueSInt16(Com_TxFilterOldValueSInt16IterType Index, Com_TxFilterOldValueSInt16Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTxFilterOldValueSInt32(Com_TxFilterOldValueSInt32IterType Index, Com_TxFilterOldValueSInt32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTxFilterOldValueSInt64(Com_TxFilterOldValueSInt64IterType Index, Com_TxFilterOldValueSInt64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTxFilterOldValueSInt8(Com_TxFilterOldValueSInt8IterType Index, Com_TxFilterOldValueSInt8Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTxFilterOldValueUInt16(Com_TxFilterOldValueUInt16IterType Index, Com_TxFilterOldValueUInt16Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTxFilterOldValueUInt32(Com_TxFilterOldValueUInt32IterType Index, Com_TxFilterOldValueUInt32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTxFilterOldValueUInt64(Com_TxFilterOldValueUInt64IterType Index, Com_TxFilterOldValueUInt64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddTxFilterOldValueUInt8(Com_TxFilterOldValueUInt8IterType Index, Com_TxFilterOldValueUInt8Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTxFilterOldValueArrayBased(Com_TxFilterOldValueArrayBasedIterType Index, Com_TxFilterOldValueArrayBasedType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTxFilterOldValueSInt16(Com_TxFilterOldValueSInt16IterType Index, Com_TxFilterOldValueSInt16Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTxFilterOldValueSInt32(Com_TxFilterOldValueSInt32IterType Index, Com_TxFilterOldValueSInt32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTxFilterOldValueSInt64(Com_TxFilterOldValueSInt64IterType Index, Com_TxFilterOldValueSInt64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTxFilterOldValueSInt8(Com_TxFilterOldValueSInt8IterType Index, Com_TxFilterOldValueSInt8Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTxFilterOldValueUInt16(Com_TxFilterOldValueUInt16IterType Index, Com_TxFilterOldValueUInt16Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTxFilterOldValueUInt32(Com_TxFilterOldValueUInt32IterType Index, Com_TxFilterOldValueUInt32Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTxFilterOldValueUInt64(Com_TxFilterOldValueUInt64IterType Index, Com_TxFilterOldValueUInt64Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  COM_DUMMY_STATEMENT(Value);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubTxFilterOldValueUInt8(Com_TxFilterOldValueUInt8IterType Index, Com_TxFilterOldValueUInt8Type Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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

#endif  /* COM_CFG_TXSIGNALFILTERING_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cfg_TxSignalFiltering.h
**********************************************************************************************************************/

