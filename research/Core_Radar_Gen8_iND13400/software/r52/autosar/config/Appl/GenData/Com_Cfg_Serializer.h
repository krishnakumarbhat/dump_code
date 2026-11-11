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
 *              File: Com_Cfg_Serializer.h
 *   Generation Time: 2026-08-28 14:56:00
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

#if !defined (COM_CFG_SERIALIZER_H)
# define COM_CFG_SERIALIZER_H

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
COM_LOCAL_INLINE FUNC(Com_SizeOfSerializerInfoType, COM_CODE) Com_GetSizeOfSerializerInfo(void);
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
COM_LOCAL_INLINE FUNC(Com_BitLengthOfSerializerInfoType, COM_CODE) Com_GetBitLengthOfSerializerInfo(Com_SerializerInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_ConfiguredBitPositionOfSerializerInfoType, COM_CODE) Com_GetConfiguredBitPositionOfSerializerInfo(Com_SerializerInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_SignalEndiannessOfSerializerInfoType, COM_CODE) Com_GetSignalEndiannessOfSerializerInfo(Com_SerializerInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_SrcBitOffsetOfSerializerInfoType, COM_CODE) Com_GetSrcBitOffsetOfSerializerInfo(Com_SerializerInfoIterType Index);
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoIdxOfSerializerInfoType, COM_CODE) Com_GetTxBufferInfoIdxOfSerializerInfo(Com_SerializerInfoIterType Index);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSerializerInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasBitLengthOfSerializerInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasConfiguredBitPositionOfSerializerInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSignalEndiannessOfSerializerInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSrcBitOffsetOfSerializerInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoIdxOfSerializerInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfSerializerInfo(void);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsBIG_ENDIANSignalEndiannessOfSerializerInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsLITTLE_ENDIANSignalEndiannessOfSerializerInfo(void);
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsOPAQUESignalEndiannessOfSerializerInfo(void);
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
COM_LOCAL_INLINE FUNC(Com_SizeOfSerializerInfoType, COM_CODE) Com_GetSizeOfSerializerInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (Com_SizeOfSerializerInfoType) Com_GetSizeOfSerializerInfoOfPCConfig();
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
COM_LOCAL_INLINE FUNC(Com_BitLengthOfSerializerInfoType, COM_CODE) Com_GetBitLengthOfSerializerInfo(Com_SerializerInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_BitLengthOfSerializerInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_ConfiguredBitPositionOfSerializerInfoType, COM_CODE) Com_GetConfiguredBitPositionOfSerializerInfo(Com_SerializerInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_ConfiguredBitPositionOfSerializerInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_SignalEndiannessOfSerializerInfoType, COM_CODE) Com_GetSignalEndiannessOfSerializerInfo(Com_SerializerInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_SignalEndiannessOfSerializerInfoType) (0x00u);
}
COM_LOCAL_INLINE FUNC(Com_SrcBitOffsetOfSerializerInfoType, COM_CODE) Com_GetSrcBitOffsetOfSerializerInfo(Com_SerializerInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_SrcBitOffsetOfSerializerInfoType) (0u);
}
COM_LOCAL_INLINE FUNC(Com_TxBufferInfoIdxOfSerializerInfoType, COM_CODE) Com_GetTxBufferInfoIdxOfSerializerInfo(Com_SerializerInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  COM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (Com_TxBufferInfoIdxOfSerializerInfoType) (0u);
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSerializerInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasBitLengthOfSerializerInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasConfiguredBitPositionOfSerializerInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSignalEndiannessOfSerializerInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSrcBitOffsetOfSerializerInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasTxBufferInfoIdxOfSerializerInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_HasSizeOfSerializerInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsBIG_ENDIANSignalEndiannessOfSerializerInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsLITTLE_ENDIANSignalEndiannessOfSerializerInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
COM_LOCAL_INLINE FUNC(boolean, COM_CODE) Com_ExistsOPAQUESignalEndiannessOfSerializerInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
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

#endif  /* COM_CFG_SERIALIZER_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cfg_Serializer.h
**********************************************************************************************************************/

