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
 *              File: Com_Cfg_TxModeHdlr.h
 *   Generation Time: 2026-08-20 19:19:50
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

#if !defined (COM_CFG_TXMODEHDLR_H)
# define COM_CFG_TXMODEHDLR_H

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
COM_LOCAL_INLINE FUNC(Com_SizeOfCurrentTxModeType, COM_CODE) Com_GetSizeOfCurrentTxMode(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxModeFalseType, COM_CODE) Com_GetSizeOfTxModeFalse(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfTxModeTrueType, COM_CODE) Com_GetSizeOfTxModeTrue(void);
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
COM_LOCAL_INLINE FUNC(Com_CurrentTxModeType, COM_CODE) Com_IsCurrentTxMode(Com_CurrentTxModeIterType Index);
COM_LOCAL_INLINE FUNC(Com_DirectOfTxModeFalseType, COM_CODE) Com_IsDirectOfTxModeFalse(Com_TxModeFalseIterType Index);
COM_LOCAL_INLINE FUNC(Com_TimeOffsetOfTxModeFalseType, COM_CODE) Com_GetTimeOffsetOfTxModeFalse(Com_TxModeFalseIterType Index);
COM_LOCAL_INLINE FUNC(Com_TimePeriodOfTxModeFalseType, COM_CODE) Com_GetTimePeriodOfTxModeFalse(Com_TxModeFalseIterType Index);
COM_LOCAL_INLINE FUNC(Com_PeriodicOfTxModeTrueType, COM_CODE) Com_IsPeriodicOfTxModeTrue(Com_TxModeTrueIterType Index);
COM_LOCAL_INLINE FUNC(Com_TimeOffsetOfTxModeTrueType, COM_CODE) Com_GetTimeOffsetOfTxModeTrue(Com_TxModeTrueIterType Index);
COM_LOCAL_INLINE FUNC(Com_TimePeriodOfTxModeTrueType, COM_CODE) Com_GetTimePeriodOfTxModeTrue(Com_TxModeTrueIterType Index);
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
COM_LOCAL_INLINE FUNC(Com_PeriodicOfTxModeFalseType, COM_CODE) Com_IsPeriodicOfTxModeFalse(Com_TxModeFalseIterType Index);
COM_LOCAL_INLINE FUNC(Com_DirectOfTxModeTrueType, COM_CODE) Com_IsDirectOfTxModeTrue(Com_TxModeTrueIterType Index);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetCurrentTxMode(Com_CurrentTxModeIterType Index, Com_CurrentTxModeType Value);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCurrentTxMode(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfCurrentTxMode(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxModeFalse(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxModeTrue(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxModeFalse(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasDirectOfTxModeFalse(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasPeriodicOfTxModeFalse(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTimeOffsetOfTxModeFalse(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTimePeriodOfTxModeFalse(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxModeTrue(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasDirectOfTxModeTrue(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasPeriodicOfTxModeTrue(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTimeOffsetOfTxModeTrue(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTimePeriodOfTxModeTrue(void);
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
COM_LOCAL_INLINE FUNC(Com_SizeOfCurrentTxModeType, COM_CODE) Com_GetSizeOfCurrentTxMode(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfCurrentTxModeType) Com_GetSizeOfCurrentTxModeOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxModeFalseType, COM_CODE) Com_GetSizeOfTxModeFalse(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxModeFalseType) Com_GetSizeOfTxModeFalseOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfTxModeTrueType, COM_CODE) Com_GetSizeOfTxModeTrue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfTxModeTrueType) Com_GetSizeOfTxModeTrueOfPCConfig();
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
COM_LOCAL_INLINE FUNC(Com_CurrentTxModeType, COM_CODE) Com_IsCurrentTxMode(Com_CurrentTxModeIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_CurrentTxModeType) ((Com_GetCurrentTxModeOfPCConfig()[(Index)]) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_DirectOfTxModeFalseType, COM_CODE) Com_IsDirectOfTxModeFalse(Com_TxModeFalseIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_DirectOfTxModeFalseType) ((Com_GetTxModeFalseOfPCConfig()[(Index)].DirectOfTxModeFalse) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TimeOffsetOfTxModeFalseType, COM_CODE) Com_GetTimeOffsetOfTxModeFalse(Com_TxModeFalseIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TimeOffsetOfTxModeFalseType) (Com_GetTxModeFalseOfPCConfig()[(Index)].TimeOffsetOfTxModeFalse);
}
COM_LOCAL_INLINE FUNC(Com_TimePeriodOfTxModeFalseType, COM_CODE) Com_GetTimePeriodOfTxModeFalse(Com_TxModeFalseIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TimePeriodOfTxModeFalseType) (Com_GetTxModeFalseOfPCConfig()[(Index)].TimePeriodOfTxModeFalse);
}
COM_LOCAL_INLINE FUNC(Com_PeriodicOfTxModeTrueType, COM_CODE) Com_IsPeriodicOfTxModeTrue(Com_TxModeTrueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_PeriodicOfTxModeTrueType) ((Com_GetTxModeTrueOfPCConfig()[(Index)].PeriodicOfTxModeTrue) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_TimeOffsetOfTxModeTrueType, COM_CODE) Com_GetTimeOffsetOfTxModeTrue(Com_TxModeTrueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TimeOffsetOfTxModeTrueType) (Com_GetTxModeTrueOfPCConfig()[(Index)].TimeOffsetOfTxModeTrue);
}
COM_LOCAL_INLINE FUNC(Com_TimePeriodOfTxModeTrueType, COM_CODE) Com_GetTimePeriodOfTxModeTrue(Com_TxModeTrueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TimePeriodOfTxModeTrueType) (Com_GetTxModeTrueOfPCConfig()[(Index)].TimePeriodOfTxModeTrue);
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
COM_LOCAL_INLINE FUNC(Com_PeriodicOfTxModeFalseType, COM_CODE) Com_IsPeriodicOfTxModeFalse(Com_TxModeFalseIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_PeriodicOfTxModeFalseType) (((boolean)(Com_GetTimePeriodOfTxModeFalse(Index) == 40u)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_DirectOfTxModeTrueType, COM_CODE) Com_IsDirectOfTxModeTrue(Com_TxModeTrueIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_DirectOfTxModeTrueType) (((!(Com_IsPeriodicOfTxModeTrue(Index)))) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetCurrentTxMode(Com_CurrentTxModeIterType Index, Com_CurrentTxModeType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetCurrentTxModeOfPCConfig()[(Index)] = (Value);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasCurrentTxMode(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfCurrentTxMode(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxModeFalse(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfTxModeTrue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxModeFalse(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasDirectOfTxModeFalse(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasPeriodicOfTxModeFalse(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTimeOffsetOfTxModeFalse(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTimePeriodOfTxModeFalse(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxModeTrue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasDirectOfTxModeTrue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasPeriodicOfTxModeTrue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTimeOffsetOfTxModeTrue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTimePeriodOfTxModeTrue(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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

#endif  /* COM_CFG_TXMODEHDLR_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cfg_TxModeHdlr.h
**********************************************************************************************************************/

