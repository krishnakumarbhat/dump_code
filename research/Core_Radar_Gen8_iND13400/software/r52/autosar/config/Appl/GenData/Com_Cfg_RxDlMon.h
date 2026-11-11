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
 *              File: Com_Cfg_RxDlMon.h
 *   Generation Time: 2026-08-11 15:50:27
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

#if !defined (COM_CFG_RXDLMON_H)
# define COM_CFG_RXDLMON_H

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
COM_LOCAL_INLINE FUNC(Com_SizeOfReportingRxTimeoutNotificationIndType, COM_CODE) Com_GetSizeOfReportingRxTimeoutNotificationInd(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxAccessInfoReplaceSigIndType, COM_CODE) Com_GetSizeOfRxAccessInfoReplaceSigInd(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxPduDmStateType, COM_CODE) Com_GetSizeOfRxPduDmState(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxTOutInfoType, COM_CODE) Com_GetSizeOfRxTOutInfo(void);
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
COM_LOCAL_INLINE FUNC(Com_ReportingRxTimeoutNotificationIndType, COM_CODE) Com_GetReportingRxTimeoutNotificationInd(Com_ReportingRxTimeoutNotificationIndIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoReplaceSigIndType, COM_CODE) Com_GetRxAccessInfoReplaceSigInd(Com_RxAccessInfoReplaceSigIndIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxPduDmStateType, COM_CODE) Com_GetRxPduDmState(Com_RxPduDmStateIterType Index);
COM_LOCAL_INLINE FUNC(Com_ComTimerInfoIdxOfRxTOutInfoType, COM_CODE) Com_GetComTimerInfoIdxOfRxTOutInfo(Com_RxTOutInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_MainFunctionRxStructIdxOfRxTOutInfoType, COM_CODE) Com_GetMainFunctionRxStructIdxOfRxTOutInfo(Com_RxTOutInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ReportingRxTimeoutNotificationIndStartIdxOfRxTOutInfoType, COM_CODE) Com_GetReportingRxTimeoutNotificationIndStartIdxOfRxTOutInfo(Com_RxTOutInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoReplaceSigIndEndIdxOfRxTOutInfoType, COM_CODE) Com_GetRxAccessInfoReplaceSigIndEndIdxOfRxTOutInfo(Com_RxTOutInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoReplaceSigIndStartIdxOfRxTOutInfoType, COM_CODE) Com_GetRxAccessInfoReplaceSigIndStartIdxOfRxTOutInfo(Com_RxTOutInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoReplaceSigIndUsedOfRxTOutInfoType, COM_CODE) Com_IsRxAccessInfoReplaceSigIndUsedOfRxTOutInfo(Com_RxTOutInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxPduInfoIdxOfRxTOutInfoType, COM_CODE) Com_GetRxPduInfoIdxOfRxTOutInfo(Com_RxTOutInfoIterType Index);
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
COM_LOCAL_INLINE FUNC(Com_ReportingRxTimeoutNotificationIndEndIdxOfRxTOutInfoType, COM_CODE) Com_GetReportingRxTimeoutNotificationIndEndIdxOfRxTOutInfo(Com_RxTOutInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ReportingRxTimeoutNotificationIndUsedOfRxTOutInfoType, COM_CODE) Com_IsReportingRxTimeoutNotificationIndUsedOfRxTOutInfo(Com_RxTOutInfoIterType Index);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxPduDmState(Com_RxPduDmStateIterType Index, Com_RxPduDmStateType Value);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingRxTimeoutNotificationInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoReplaceSigInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxPduDmState(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasComTimerInfoIdxOfRxTOutInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMainFunctionRxStructIdxOfRxTOutInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingRxTimeoutNotificationIndEndIdxOfRxTOutInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingRxTimeoutNotificationIndStartIdxOfRxTOutInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingRxTimeoutNotificationIndUsedOfRxTOutInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoReplaceSigIndEndIdxOfRxTOutInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoReplaceSigIndStartIdxOfRxTOutInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoReplaceSigIndUsedOfRxTOutInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxPduInfoIdxOfRxTOutInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfReportingRxTimeoutNotificationInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxAccessInfoReplaceSigInd(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxPduDmState(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxTOutInfo(void);
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
COM_LOCAL_INLINE FUNC(Com_SizeOfReportingRxTimeoutNotificationIndType, COM_CODE) Com_GetSizeOfReportingRxTimeoutNotificationInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfReportingRxTimeoutNotificationIndType) Com_GetSizeOfReportingRxTimeoutNotificationIndOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxAccessInfoReplaceSigIndType, COM_CODE) Com_GetSizeOfRxAccessInfoReplaceSigInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxAccessInfoReplaceSigIndType) Com_GetSizeOfRxAccessInfoReplaceSigIndOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxPduDmStateType, COM_CODE) Com_GetSizeOfRxPduDmState(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxPduDmStateType) Com_GetSizeOfRxPduDmStateOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxTOutInfoType, COM_CODE) Com_GetSizeOfRxTOutInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxTOutInfoType) Com_GetSizeOfRxTOutInfoOfPCConfig();
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
COM_LOCAL_INLINE FUNC(Com_ReportingRxTimeoutNotificationIndType, COM_CODE) Com_GetReportingRxTimeoutNotificationInd(Com_ReportingRxTimeoutNotificationIndIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ReportingRxTimeoutNotificationIndType) (Com_GetReportingRxTimeoutNotificationIndOfPCConfig()[(Index)]);
}
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoReplaceSigIndType, COM_CODE) Com_GetRxAccessInfoReplaceSigInd(Com_RxAccessInfoReplaceSigIndIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxAccessInfoReplaceSigIndType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_RxPduDmStateType, COM_CODE) Com_GetRxPduDmState(Com_RxPduDmStateIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxPduDmStateType) (Com_GetRxPduDmStateOfPCConfig()[(Index)]);
}
COM_LOCAL_INLINE FUNC(Com_ComTimerInfoIdxOfRxTOutInfoType, COM_CODE) Com_GetComTimerInfoIdxOfRxTOutInfo(Com_RxTOutInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ComTimerInfoIdxOfRxTOutInfoType) (Com_GetRxTOutInfoOfPCConfig()[(Index)].ComTimerInfoIdxOfRxTOutInfo);
}
COM_LOCAL_INLINE FUNC(Com_MainFunctionRxStructIdxOfRxTOutInfoType, COM_CODE) Com_GetMainFunctionRxStructIdxOfRxTOutInfo(Com_RxTOutInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_MainFunctionRxStructIdxOfRxTOutInfoType) (Com_GetRxTOutInfoOfPCConfig()[(Index)].MainFunctionRxStructIdxOfRxTOutInfo);
}
COM_LOCAL_INLINE FUNC(Com_ReportingRxTimeoutNotificationIndStartIdxOfRxTOutInfoType, COM_CODE) Com_GetReportingRxTimeoutNotificationIndStartIdxOfRxTOutInfo(Com_RxTOutInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ReportingRxTimeoutNotificationIndStartIdxOfRxTOutInfoType) (Com_GetRxTOutInfoOfPCConfig()[(Index)].ReportingRxTimeoutNotificationIndStartIdxOfRxTOutInfo);
}
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoReplaceSigIndEndIdxOfRxTOutInfoType, COM_CODE) Com_GetRxAccessInfoReplaceSigIndEndIdxOfRxTOutInfo(Com_RxTOutInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxAccessInfoReplaceSigIndEndIdxOfRxTOutInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoReplaceSigIndStartIdxOfRxTOutInfoType, COM_CODE) Com_GetRxAccessInfoReplaceSigIndStartIdxOfRxTOutInfo(Com_RxTOutInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxAccessInfoReplaceSigIndStartIdxOfRxTOutInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_RxAccessInfoReplaceSigIndUsedOfRxTOutInfoType, COM_CODE) Com_IsRxAccessInfoReplaceSigIndUsedOfRxTOutInfo(Com_RxTOutInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxAccessInfoReplaceSigIndUsedOfRxTOutInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(Com_RxPduInfoIdxOfRxTOutInfoType, COM_CODE) Com_GetRxPduInfoIdxOfRxTOutInfo(Com_RxTOutInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxPduInfoIdxOfRxTOutInfoType) (Com_GetRxTOutInfoOfPCConfig()[(Index)].RxPduInfoIdxOfRxTOutInfo);
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
COM_LOCAL_INLINE FUNC(Com_ReportingRxTimeoutNotificationIndEndIdxOfRxTOutInfoType, COM_CODE) Com_GetReportingRxTimeoutNotificationIndEndIdxOfRxTOutInfo(Com_RxTOutInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ReportingRxTimeoutNotificationIndEndIdxOfRxTOutInfoType) ((Com_ReportingRxTimeoutNotificationIndEndIdxOfRxTOutInfoType)((((Com_ReportingRxTimeoutNotificationIndEndIdxOfRxTOutInfoType)(Index)) + 1u)));
}
COM_LOCAL_INLINE FUNC(Com_ReportingRxTimeoutNotificationIndUsedOfRxTOutInfoType, COM_CODE) Com_IsReportingRxTimeoutNotificationIndUsedOfRxTOutInfo(Com_RxTOutInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ReportingRxTimeoutNotificationIndUsedOfRxTOutInfoType) (((boolean)(Com_GetReportingRxTimeoutNotificationIndStartIdxOfRxTOutInfo(Index) != COM_NO_REPORTINGRXTIMEOUTNOTIFICATIONINDSTARTIDXOFRXTOUTINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxPduDmState(Com_RxPduDmStateIterType Index, Com_RxPduDmStateType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetRxPduDmStateOfPCConfig()[(Index)] = (Value);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingRxTimeoutNotificationInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoReplaceSigInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxPduDmState(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxTOutInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasComTimerInfoIdxOfRxTOutInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasMainFunctionRxStructIdxOfRxTOutInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingRxTimeoutNotificationIndEndIdxOfRxTOutInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingRxTimeoutNotificationIndStartIdxOfRxTOutInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasReportingRxTimeoutNotificationIndUsedOfRxTOutInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoReplaceSigIndEndIdxOfRxTOutInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoReplaceSigIndStartIdxOfRxTOutInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxAccessInfoReplaceSigIndUsedOfRxTOutInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxPduInfoIdxOfRxTOutInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfReportingRxTimeoutNotificationInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxAccessInfoReplaceSigInd(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxPduDmState(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxTOutInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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

#endif  /* COM_CFG_RXDLMON_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cfg_RxDlMon.h
**********************************************************************************************************************/

