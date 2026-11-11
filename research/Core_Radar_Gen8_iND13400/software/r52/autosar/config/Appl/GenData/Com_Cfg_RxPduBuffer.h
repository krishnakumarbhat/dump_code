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
 *              File: Com_Cfg_RxPduBuffer.h
 *   Generation Time: 2026-04-02 15:10:34
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

#if !defined (COM_CFG_RXPDUBUFFER_H)
# define COM_CFG_RXPDUBUFFER_H

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
COM_LOCAL_INLINE FUNC(Com_SizeOfHandleRxPduDeferredType, COM_CODE) Com_GetSizeOfHandleRxPduDeferred(void);
COM_LOCAL_INLINE FUNC(Com_SizeOfRxDefPduBufferType, COM_CODE) Com_GetSizeOfRxDefPduBuffer(void);
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
COM_LOCAL_INLINE FUNC(Com_HandleRxPduDeferredType, COM_CODE) Com_GetHandleRxPduDeferred(Com_HandleRxPduDeferredIterType Index);
COM_LOCAL_INLINE FUNC(Com_RxDefPduBufferType, COM_CODE) Com_GetRxDefPduBuffer(Com_RxDefPduBufferIterType Index);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetHandleRxPduDeferred(Com_HandleRxPduDeferredIterType Index, Com_HandleRxPduDeferredType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxDefPduBuffer(Com_RxDefPduBufferIterType Index, Com_RxDefPduBufferType Value);
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
COM_LOCAL_INLINE FUNC(Com_RxDefPduBufferPtrType, COM_CODE) Com_GetAddrRxDefPduBuffer(Com_RxDefPduBufferIterType Index);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasHandleRxPduDeferred(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDefPduBuffer(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfHandleRxPduDeferred(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxDefPduBuffer(void);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncHandleRxPduDeferred(Com_HandleRxPduDeferredIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxDefPduBuffer(Com_RxDefPduBufferIterType Index);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecHandleRxPduDeferred(Com_HandleRxPduDeferredIterType Index);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxDefPduBuffer(Com_RxDefPduBufferIterType Index);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddHandleRxPduDeferred(Com_HandleRxPduDeferredIterType Index, Com_HandleRxPduDeferredType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxDefPduBuffer(Com_RxDefPduBufferIterType Index, Com_RxDefPduBufferType Value);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubHandleRxPduDeferred(Com_HandleRxPduDeferredIterType Index, Com_HandleRxPduDeferredType Value);
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxDefPduBuffer(Com_RxDefPduBufferIterType Index, Com_RxDefPduBufferType Value);
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
COM_LOCAL_INLINE FUNC(Com_SizeOfHandleRxPduDeferredType, COM_CODE) Com_GetSizeOfHandleRxPduDeferred(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfHandleRxPduDeferredType) Com_GetSizeOfHandleRxPduDeferredOfPCConfig();
}
COM_LOCAL_INLINE FUNC(Com_SizeOfRxDefPduBufferType, COM_CODE) Com_GetSizeOfRxDefPduBuffer(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfRxDefPduBufferType) Com_GetSizeOfRxDefPduBufferOfPCConfig();
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
COM_LOCAL_INLINE FUNC(Com_HandleRxPduDeferredType, COM_CODE) Com_GetHandleRxPduDeferred(Com_HandleRxPduDeferredIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_HandleRxPduDeferredType) (Com_GetHandleRxPduDeferredOfPCConfig()[(Index)]);
}
COM_LOCAL_INLINE FUNC(Com_RxDefPduBufferType, COM_CODE) Com_GetRxDefPduBuffer(Com_RxDefPduBufferIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_RxDefPduBufferType) (Com_GetRxDefPduBufferOfPCConfig()[(Index)]);
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetHandleRxPduDeferred(Com_HandleRxPduDeferredIterType Index, Com_HandleRxPduDeferredType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetHandleRxPduDeferredOfPCConfig()[(Index)] = (Value);
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SetRxDefPduBuffer(Com_RxDefPduBufferIterType Index, Com_RxDefPduBufferType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetRxDefPduBufferOfPCConfig()[(Index)] = (Value);
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
COM_LOCAL_INLINE FUNC(Com_RxDefPduBufferPtrType, COM_CODE) Com_GetAddrRxDefPduBuffer(Com_RxDefPduBufferIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_RxDefPduBufferPtrType) (&(Com_GetRxDefPduBufferOfPCConfig()[(Index)]));
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasHandleRxPduDeferred(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasRxDefPduBuffer(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfHandleRxPduDeferred(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfRxDefPduBuffer(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
  \defgroup  ComPCIncrementInlineFunctions  Com Increment Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to increment VAR data with numerical nature.
  \{
*/ 
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncHandleRxPduDeferred(Com_HandleRxPduDeferredIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetHandleRxPduDeferredOfPCConfig()[(Index)]++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_IncRxDefPduBuffer(Com_RxDefPduBufferIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetRxDefPduBufferOfPCConfig()[(Index)]++;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecHandleRxPduDeferred(Com_HandleRxPduDeferredIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetHandleRxPduDeferredOfPCConfig()[(Index)]--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_DecRxDefPduBuffer(Com_RxDefPduBufferIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_GetRxDefPduBufferOfPCConfig()[(Index)]--;  /* PRQA S 3387 */  /* MD_CSL_InlineFunction_IncrementDecrement */
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddHandleRxPduDeferred(Com_HandleRxPduDeferredIterType Index, Com_HandleRxPduDeferredType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_SetHandleRxPduDeferred(Index, (Com_GetHandleRxPduDeferredOfPCConfig()[(Index)] + Value));
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_AddRxDefPduBuffer(Com_RxDefPduBufferIterType Index, Com_RxDefPduBufferType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_SetRxDefPduBuffer(Index, (Com_GetRxDefPduBufferOfPCConfig()[(Index)] + Value));
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
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubHandleRxPduDeferred(Com_HandleRxPduDeferredIterType Index, Com_HandleRxPduDeferredType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_SetHandleRxPduDeferred(Index, (Com_GetHandleRxPduDeferredOfPCConfig()[(Index)] - Value));
}
COM_LOCAL_INLINE FUNC(void, COM_CODE) Com_SubRxDefPduBuffer(Com_RxDefPduBufferIterType Index, Com_RxDefPduBufferType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  Com_SetRxDefPduBuffer(Index, (Com_GetRxDefPduBufferOfPCConfig()[(Index)] - Value));
}
/** 
  \}
*/ 

#define COM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Com_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */





/* VCA Enable : VCA_COM_FUNCTION_NOT_USED_AND_NO_ANALYSIS_ENTRY */

#endif  /* COM_CFG_RXPDUBUFFER_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cfg_RxPduBuffer.h
**********************************************************************************************************************/

