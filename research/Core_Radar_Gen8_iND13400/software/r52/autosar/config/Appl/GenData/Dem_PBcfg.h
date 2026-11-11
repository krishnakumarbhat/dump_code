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
 *            Module: Dem
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Dem_PBcfg.h
 *   Generation Time: 2026-07-21 14:46:35
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

/* configuration, interrupt handling and callback headers use different names
 * for the multiple inclusion protection define, shown in this example. The
 * appropriate names for these files can be taken from this list:
 *
 * Dem_Cfg.h:                   DEM_CFG_H
 * Dem_Lcfg.h:                  DEM_LCFG_H
 * Dem_PBcfg.h:                 DEM_PBFG_H
 * Dem_AdditionalIncludeCfg.h:  DEM_ADDITIONALINCLUDECFG_H
 * Dem_Swc.h:                   DEM_SWC_H
 * Dem_Swc_Types.h:             DEM_SWC_TYPES_H
 */
#if !defined (DEM_PBCFG_H)
# define DEM_PBCFG_H

/**********************************************************************************************************************
  MISRA JUSTIFICATIONS
**********************************************************************************************************************/

/* PRQA S 0779 EOF */ /* MD_MSR_Rule5.2 */                                          /* Identifier does not differ in 32 significant characters. */


/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Dem_CfgPBDataSwitches  Dem_Cfg Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define DEM_PBCONFIG                                                                                STD_OFF  /**< the module configuration is VARIANT_PRE_COMPILE. */
#define DEM_CFG_LTCONFIGIDXOFPBCONFIG                                                               STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define DEM_CFG_PCCONFIGIDXOFPBCONFIG                                                               STD_OFF  /**< the module configuration is VARIANT_PRE_COMPILE. */
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPBIsReducedToDefineDefines  Dem_Cfg Is Reduced To Define Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define DEM_CFG_ISDEF_LTCONFIGIDXOFPBCONFIG                                                         STD_OFF
#define DEM_CFG_ISDEF_PCCONFIGIDXOFPBCONFIG                                                         STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPBEqualsAlwaysToDefines  Dem_Cfg Equals Always To Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define DEM_CFG_EQ2_LTCONFIGIDXOFPBCONFIG                                                           
#define DEM_CFG_EQ2_PCCONFIGIDXOFPBCONFIG                                                           
/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
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
  \defgroup  Dem_CfgPBGetRootDataMacros  Dem_Cfg Get Root Data Macros (POST_BUILD)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Dem_Cfg_GetLTConfigIdxOfPBConfig()                                                          0u
#define Dem_Cfg_GetPCConfigIdxOfPBConfig()                                                          0u
/** 
  \}
*/ 

/** 
  \defgroup  Dem_CfgPBHasMacros  Dem_Cfg Has Macros (POST_BUILD)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Dem_HasPBConfig()                                                                           (FALSE != FALSE)
#define Dem_Cfg_HasLTConfigIdxOfPBConfig()                                                          (FALSE != FALSE)
#define Dem_Cfg_HasPCConfigIdxOfPBConfig()                                                          (FALSE != FALSE)
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
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/* PRQA S 3453 ROOT_TYPE_0850 */ /* MD_MSR_MacroArgumentEmpty */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Dem_CfgPBValueTypes  Dem_Cfg Value Types (POST_BUILD)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Dem_Cfg_LTConfigIdxOfPBConfig */
typedef uint8 Dem_Cfg_LTConfigIdxOfPBConfigType;

/**   \brief  value based type definition for Dem_Cfg_PCConfigIdxOfPBConfig */
typedef uint8 Dem_Cfg_PCConfigIdxOfPBConfigType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Dem_CfgPBRootValueTypes  Dem_Cfg Root Value Types (POST_BUILD)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Dem_PBConfig */
typedef struct sDem_PBConfigType
{
  uint8 Dem_PBConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Dem_PBConfigType;

/** 
  \}
*/ 


/* PRQA L:ROOT_TYPE_0850 */

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  Justification of MISRA deviations
**********************************************************************************************************************/


#endif  /* DEM_PBCFG_H */
/**********************************************************************************************************************
  END OF FILE: Dem_PBcfg.h     [Vector, VARIANT-POSTBUILD-SELECTABLE, 29.03.00.234032]
**********************************************************************************************************************/

