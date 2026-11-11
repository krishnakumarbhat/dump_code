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
 *            Module: LdCom
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: LdCom_PBcfg.h
 *   Generation Time: 2026-04-02 15:09:58
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

#if !defined (LDCOM_PBCFG_H)
# define LDCOM_PBCFG_H
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "ComStack_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  LdComPBDataSwitches  LdCom Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define LDCOM_PBCONFIG                                                                              STD_OFF  /**< the module configuration is VARIANT_PRE_COMPILE. */
#define LDCOM_LTCONFIGIDXOFPBCONFIG                                                                 STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define LDCOM_PCCONFIGIDXOFPBCONFIG                                                                 STD_OFF  /**< the module configuration is VARIANT_PRE_COMPILE. */
/** 
  \}
*/ 

/** 
  \defgroup  LdComPBIsReducedToDefineDefines  LdCom Is Reduced To Define Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define LDCOM_ISDEF_LTCONFIGIDXOFPBCONFIG                                                           STD_OFF
#define LDCOM_ISDEF_PCCONFIGIDXOFPBCONFIG                                                           STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  LdComPBEqualsAlwaysToDefines  LdCom Equals Always To Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define LDCOM_EQ2_LTCONFIGIDXOFPBCONFIG                                                             
#define LDCOM_EQ2_PCCONFIGIDXOFPBCONFIG                                                             
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  LdComPBGetRootDataMacros  LdCom Get Root Data Macros (POST_BUILD)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define LdCom_GetLTConfigIdxOfPBConfig()                                                            0u
#define LdCom_GetPCConfigIdxOfPBConfig()                                                            0u
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  LdComPBValueTypes  LdCom Value Types (POST_BUILD)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for LdCom_LTConfigIdxOfPBConfig */
typedef uint8 LdCom_LTConfigIdxOfPBConfigType;

/**   \brief  value based type definition for LdCom_PCConfigIdxOfPBConfig */
typedef uint8 LdCom_PCConfigIdxOfPBConfigType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  LdComPBRootValueTypes  LdCom Root Value Types (POST_BUILD)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in LdCom_PBConfig */
typedef struct sLdCom_PBConfigType
{
  uint8 LdCom_PBConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} LdCom_PBConfigType;

/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/




#endif  /* LDCOM_PBCFG_H */
/**********************************************************************************************************************
 *  END OF FILE: LdCom_PBcfg.h
 *********************************************************************************************************************/

