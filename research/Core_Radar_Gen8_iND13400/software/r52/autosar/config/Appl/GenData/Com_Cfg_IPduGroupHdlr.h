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
 *              File: Com_Cfg_IPduGroupHdlr.h
 *   Generation Time: 2026-08-05 12:38:56
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

#if !defined (COM_CFG_IPDUGROUPHDLR_H)
# define COM_CFG_IPDUGROUPHDLR_H

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
COM_LOCAL_INLINE FUNC(Com_SizeOfActiveOfRxPduInfoType, COM_CODE) Com_GetSizeOfActiveOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfActiveOfTxPduInfoType, COM_CODE) Com_GetSizeOfActiveOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfAlwaysActiveRxComIPdusType, COM_CODE) Com_GetSizeOfAlwaysActiveRxComIPdus(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfAlwaysActiveTxComIPdusType, COM_CODE) Com_GetSizeOfAlwaysActiveTxComIPdus(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfIPduGroupInfoType, COM_CODE) Com_GetSizeOfIPduGroupInfo(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxPduInfoIndType, COM_CODE) Com_GetSizeOfRxPduInfoInd(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfStateOfIPduGroupInfoType, COM_CODE) Com_GetSizeOfStateOfIPduGroupInfo(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxPduInfoIndType, COM_CODE) Com_GetSizeOfTxPduInfoInd(void);
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
COM_LOCAL_INLINE FUNC(Com_ActiveOfRxPduInfoType, COM_CODE) Com_IsActiveOfRxPduInfo(Com_ActiveOfRxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ActiveOfTxPduInfoType, COM_CODE) Com_IsActiveOfTxPduInfo(Com_ActiveOfTxPduInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxPduInfoIdxOfAlwaysActiveRxComIPdusType, COM_CODE) Com_GetRxPduInfoIdxOfAlwaysActiveRxComIPdus(Com_AlwaysActiveRxComIPdusIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxPduInfoIdxOfAlwaysActiveTxComIPdusType, COM_CODE) Com_GetTxPduInfoIdxOfAlwaysActiveTxComIPdus(Com_AlwaysActiveTxComIPdusIterType Index);
COM_LOCAL_INLINE FUNC(Com_InvalidHndOfIPduGroupInfoType, COM_CODE) Com_IsInvalidHndOfIPduGroupInfo(Com_IPduGroupInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_PartitionsRxStructIdxOfIPduGroupInfoType, COM_CODE) Com_GetPartitionsRxStructIdxOfIPduGroupInfo(Com_IPduGroupInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_PartitionsTxStructIdxOfIPduGroupInfoType, COM_CODE) Com_GetPartitionsTxStructIdxOfIPduGroupInfo(Com_IPduGroupInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxPduInfoIndEndIdxOfIPduGroupInfoType, COM_CODE) Com_GetRxPduInfoIndEndIdxOfIPduGroupInfo(Com_IPduGroupInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxPduInfoIndStartIdxOfIPduGroupInfoType, COM_CODE) Com_GetRxPduInfoIndStartIdxOfIPduGroupInfo(Com_IPduGroupInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxPduInfoIndEndIdxOfIPduGroupInfoType, COM_CODE) Com_GetTxPduInfoIndEndIdxOfIPduGroupInfo(Com_IPduGroupInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxPduInfoIndStartIdxOfIPduGroupInfoType, COM_CODE) Com_GetTxPduInfoIndStartIdxOfIPduGroupInfo(Com_IPduGroupInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxPduInfoIndType, COM_CODE) Com_GetRxPduInfoInd(Com_RxPduInfoIndIterType Index);
COM_LOCAL_INLINE FUNC(Com_StateOfIPduGroupInfoType, COM_CODE) Com_GetStateOfIPduGroupInfo(Com_StateOfIPduGroupInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxPduInfoIndType, COM_CODE) Com_GetTxPduInfoInd(Com_TxPduInfoIndIterType Index);
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
COM_LOCAL_INLINE FUNC(Com_PartitionsRxStructUsedOfIPduGroupInfoType, COM_CODE) Com_IsPartitionsRxStructUsedOfIPduGroupInfo(Com_IPduGroupInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_PartitionsTxStructUsedOfIPduGroupInfoType, COM_CODE) Com_IsPartitionsTxStructUsedOfIPduGroupInfo(Com_IPduGroupInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxPduInfoIndUsedOfIPduGroupInfoType, COM_CODE) Com_IsRxPduInfoIndUsedOfIPduGroupInfo(Com_IPduGroupInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxPduInfoIndUsedOfIPduGroupInfoType, COM_CODE) Com_IsTxPduInfoIndUsedOfIPduGroupInfo(Com_IPduGroupInfoIterType Index);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetActiveOfRxPduInfo(Com_ActiveOfRxPduInfoIterType Index, Com_ActiveOfRxPduInfoType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetActiveOfTxPduInfo(Com_ActiveOfTxPduInfoIterType Index, Com_ActiveOfTxPduInfoType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetStateOfIPduGroupInfo(Com_StateOfIPduGroupInfoIterType Index, Com_StateOfIPduGroupInfoType Value);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasActiveOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasActiveOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasAlwaysActiveRxComIPdus(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxPduInfoIdxOfAlwaysActiveRxComIPdus(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasAlwaysActiveTxComIPdus(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInfoIdxOfAlwaysActiveTxComIPdus(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasIPduGroupInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvalidHndOfIPduGroupInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasPartitionsRxStructIdxOfIPduGroupInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasPartitionsRxStructUsedOfIPduGroupInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasPartitionsTxStructIdxOfIPduGroupInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasPartitionsTxStructUsedOfIPduGroupInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxPduInfoIndEndIdxOfIPduGroupInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxPduInfoIndStartIdxOfIPduGroupInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxPduInfoIndUsedOfIPduGroupInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInfoIndEndIdxOfIPduGroupInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInfoIndStartIdxOfIPduGroupInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInfoIndUsedOfIPduGroupInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxPduInfoInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfActiveOfRxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfActiveOfTxPduInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfAlwaysActiveRxComIPdus(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfAlwaysActiveTxComIPdus(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfIPduGroupInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxPduInfoInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfStateOfIPduGroupInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxPduInfoInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasStateOfIPduGroupInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInfoInd(void);
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
COM_LOCAL_INLINE FUNC(Com_SizeOfActiveOfRxPduInfoType, COM_CODE) Com_GetSizeOfActiveOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfActiveOfRxPduInfoType) Com_GetSizeOfActiveOfRxPduInfoOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfActiveOfTxPduInfoType, COM_CODE) Com_GetSizeOfActiveOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfActiveOfTxPduInfoType) Com_GetSizeOfActiveOfTxPduInfoOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfAlwaysActiveRxComIPdusType, COM_CODE) Com_GetSizeOfAlwaysActiveRxComIPdus(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfAlwaysActiveRxComIPdusType) Com_GetSizeOfAlwaysActiveRxComIPdusOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfAlwaysActiveTxComIPdusType, COM_CODE) Com_GetSizeOfAlwaysActiveTxComIPdus(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfAlwaysActiveTxComIPdusType) Com_GetSizeOfAlwaysActiveTxComIPdusOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfIPduGroupInfoType, COM_CODE) Com_GetSizeOfIPduGroupInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfIPduGroupInfoType) Com_GetSizeOfIPduGroupInfoOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxPduInfoIndType, COM_CODE) Com_GetSizeOfRxPduInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxPduInfoIndType) Com_GetSizeOfRxPduInfoIndOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfStateOfIPduGroupInfoType, COM_CODE) Com_GetSizeOfStateOfIPduGroupInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfStateOfIPduGroupInfoType) Com_GetSizeOfStateOfIPduGroupInfoOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxPduInfoIndType, COM_CODE) Com_GetSizeOfTxPduInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxPduInfoIndType) Com_GetSizeOfTxPduInfoIndOfPCConfig();
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
COM_LOCAL_INLINE FUNC(Com_ActiveOfRxPduInfoType, COM_CODE) Com_IsActiveOfRxPduInfo(Com_ActiveOfRxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ActiveOfRxPduInfoType) ((Com_GetActiveOfRxPduInfoOfPCConfig()[(Index)]) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_ActiveOfTxPduInfoType, COM_CODE) Com_IsActiveOfTxPduInfo(Com_ActiveOfTxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ActiveOfTxPduInfoType) ((Com_GetActiveOfTxPduInfoOfPCConfig()[(Index)]) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxPduInfoIdxOfAlwaysActiveRxComIPdusType, COM_CODE) Com_GetRxPduInfoIdxOfAlwaysActiveRxComIPdus(Com_AlwaysActiveRxComIPdusIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxPduInfoIdxOfAlwaysActiveRxComIPdusType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxPduInfoIdxOfAlwaysActiveTxComIPdusType, COM_CODE) Com_GetTxPduInfoIdxOfAlwaysActiveTxComIPdus(Com_AlwaysActiveTxComIPdusIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxPduInfoIdxOfAlwaysActiveTxComIPdusType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_InvalidHndOfIPduGroupInfoType, COM_CODE) Com_IsInvalidHndOfIPduGroupInfo(Com_IPduGroupInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_InvalidHndOfIPduGroupInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_PartitionsRxStructIdxOfIPduGroupInfoType, COM_CODE) Com_GetPartitionsRxStructIdxOfIPduGroupInfo(Com_IPduGroupInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_PartitionsRxStructIdxOfIPduGroupInfoType) (Com_GetIPduGroupInfoOfPCConfig()[(Index)].PartitionsRxStructIdxOfIPduGroupInfo);
}
COM_LOCAL_INLINE FUNC(Com_PartitionsTxStructIdxOfIPduGroupInfoType, COM_CODE) Com_GetPartitionsTxStructIdxOfIPduGroupInfo(Com_IPduGroupInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_PartitionsTxStructIdxOfIPduGroupInfoType) (Com_GetIPduGroupInfoOfPCConfig()[(Index)].PartitionsTxStructIdxOfIPduGroupInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxPduInfoIndEndIdxOfIPduGroupInfoType, COM_CODE) Com_GetRxPduInfoIndEndIdxOfIPduGroupInfo(Com_IPduGroupInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxPduInfoIndEndIdxOfIPduGroupInfoType) (Com_GetIPduGroupInfoOfPCConfig()[(Index)].RxPduInfoIndEndIdxOfIPduGroupInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxPduInfoIndStartIdxOfIPduGroupInfoType, COM_CODE) Com_GetRxPduInfoIndStartIdxOfIPduGroupInfo(Com_IPduGroupInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxPduInfoIndStartIdxOfIPduGroupInfoType) (Com_GetIPduGroupInfoOfPCConfig()[(Index)].RxPduInfoIndStartIdxOfIPduGroupInfo);
}
COM_LOCAL_INLINE FUNC(Com_TxPduInfoIndEndIdxOfIPduGroupInfoType, COM_CODE) Com_GetTxPduInfoIndEndIdxOfIPduGroupInfo(Com_IPduGroupInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxPduInfoIndEndIdxOfIPduGroupInfoType) (Com_GetIPduGroupInfoOfPCConfig()[(Index)].TxPduInfoIndEndIdxOfIPduGroupInfo);
}
COM_LOCAL_INLINE FUNC(Com_TxPduInfoIndStartIdxOfIPduGroupInfoType, COM_CODE) Com_GetTxPduInfoIndStartIdxOfIPduGroupInfo(Com_IPduGroupInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxPduInfoIndStartIdxOfIPduGroupInfoType) (Com_GetIPduGroupInfoOfPCConfig()[(Index)].TxPduInfoIndStartIdxOfIPduGroupInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxPduInfoIndType, COM_CODE) Com_GetRxPduInfoInd(Com_RxPduInfoIndIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxPduInfoIndType) (Com_GetRxPduInfoIndOfPCConfig()[(Index)]);
}
COM_LOCAL_INLINE FUNC(Com_StateOfIPduGroupInfoType, COM_CODE) Com_GetStateOfIPduGroupInfo(Com_StateOfIPduGroupInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_StateOfIPduGroupInfoType) (Com_GetStateOfIPduGroupInfoOfPCConfig()[(Index)]);
}
COM_LOCAL_INLINE FUNC(Com_TxPduInfoIndType, COM_CODE) Com_GetTxPduInfoInd(Com_TxPduInfoIndIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxPduInfoIndType) (Com_GetTxPduInfoIndOfPCConfig()[(Index)]);
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
COM_LOCAL_INLINE FUNC(Com_PartitionsRxStructUsedOfIPduGroupInfoType, COM_CODE) Com_IsPartitionsRxStructUsedOfIPduGroupInfo(Com_IPduGroupInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_PartitionsRxStructUsedOfIPduGroupInfoType) (((boolean)(Com_GetPartitionsRxStructIdxOfIPduGroupInfo(Index) != COM_NO_PARTITIONSRXSTRUCTIDXOFIPDUGROUPINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_PartitionsTxStructUsedOfIPduGroupInfoType, COM_CODE) Com_IsPartitionsTxStructUsedOfIPduGroupInfo(Com_IPduGroupInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_PartitionsTxStructUsedOfIPduGroupInfoType) (((boolean)(Com_GetPartitionsTxStructIdxOfIPduGroupInfo(Index) != COM_NO_PARTITIONSTXSTRUCTIDXOFIPDUGROUPINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxPduInfoIndUsedOfIPduGroupInfoType, COM_CODE) Com_IsRxPduInfoIndUsedOfIPduGroupInfo(Com_IPduGroupInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxPduInfoIndUsedOfIPduGroupInfoType) (((boolean)(Com_GetRxPduInfoIndStartIdxOfIPduGroupInfo(Index) != COM_NO_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TxPduInfoIndUsedOfIPduGroupInfoType, COM_CODE) Com_IsTxPduInfoIndUsedOfIPduGroupInfo(Com_IPduGroupInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxPduInfoIndUsedOfIPduGroupInfoType) (((boolean)(Com_GetTxPduInfoIndStartIdxOfIPduGroupInfo(Index) != COM_NO_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetActiveOfRxPduInfo(Com_ActiveOfRxPduInfoIterType Index, Com_ActiveOfRxPduInfoType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetActiveOfRxPduInfoOfPCConfig()[(Index)] = (Value);
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetActiveOfTxPduInfo(Com_ActiveOfTxPduInfoIterType Index, Com_ActiveOfTxPduInfoType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetActiveOfTxPduInfoOfPCConfig()[(Index)] = (Value);
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetStateOfIPduGroupInfo(Com_StateOfIPduGroupInfoIterType Index, Com_StateOfIPduGroupInfoType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetStateOfIPduGroupInfoOfPCConfig()[(Index)] = (Value);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasActiveOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasActiveOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasAlwaysActiveRxComIPdus(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxPduInfoIdxOfAlwaysActiveRxComIPdus(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasAlwaysActiveTxComIPdus(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInfoIdxOfAlwaysActiveTxComIPdus(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasIPduGroupInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasInvalidHndOfIPduGroupInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasPartitionsRxStructIdxOfIPduGroupInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasPartitionsRxStructUsedOfIPduGroupInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasPartitionsTxStructIdxOfIPduGroupInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasPartitionsTxStructUsedOfIPduGroupInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxPduInfoIndEndIdxOfIPduGroupInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxPduInfoIndStartIdxOfIPduGroupInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxPduInfoIndUsedOfIPduGroupInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInfoIndEndIdxOfIPduGroupInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInfoIndStartIdxOfIPduGroupInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInfoIndUsedOfIPduGroupInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxPduInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfActiveOfRxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfActiveOfTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfAlwaysActiveRxComIPdus(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfAlwaysActiveTxComIPdus(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfIPduGroupInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxPduInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfStateOfIPduGroupInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxPduInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasStateOfIPduGroupInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxPduInfoInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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





/* VCA Enable : VCA_COM_FUNCTION_NOT_USED_AND_NO_ANALYSIS_ENTRY */

#endif  /* COM_CFG_IPDUGROUPHDLR_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cfg_IPduGroupHdlr.h
**********************************************************************************************************************/

