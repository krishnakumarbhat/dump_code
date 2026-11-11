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
 *            Module: J1939Tp
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: J1939Tp_PBcfg.h
 *   Generation Time: 2026-05-11 17:41:14
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

#if !defined (J1939TP_PBCFG_H)
# define J1939TP_PBCFG_H

/**********************************************************************************************************************
  MISRA JUSTIFICATION
**********************************************************************************************************************/

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/

# include "J1939Tp_Cfg.h"
# include "J1939Tp_Types.h"


/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  J1939TpPBDataSwitches  J1939Tp Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define J1939TP_PBCONFIG                                                                            STD_OFF  /**< the module configuration is VARIANT_PRE_COMPILE. */
#define J1939TP_LTCONFIGIDXOFPBCONFIG                                                               STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define J1939TP_PCCONFIGIDXOFPBCONFIG                                                               STD_OFF  /**< the module configuration is VARIANT_PRE_COMPILE. */
/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPBIsReducedToDefineDefines  J1939Tp Is Reduced To Define Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define J1939TP_ISDEF_LTCONFIGIDXOFPBCONFIG                                                         STD_OFF
#define J1939TP_ISDEF_PCCONFIGIDXOFPBCONFIG                                                         STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPBEqualsAlwaysToDefines  J1939Tp Equals Always To Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define J1939TP_EQ2_LTCONFIGIDXOFPBCONFIG                                                           
#define J1939TP_EQ2_PCCONFIGIDXOFPBCONFIG                                                           
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
  \defgroup  J1939TpPBGetRootDataMacros  J1939Tp Get Root Data Macros (POST_BUILD)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define J1939Tp_GetLTConfigIdxOfPBConfig()                                                          0u
#define J1939Tp_GetPCConfigIdxOfPBConfig()                                                          0u
/** 
  \}
*/ 

/** 
  \defgroup  J1939TpPBHasMacros  J1939Tp Has Macros (POST_BUILD)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define J1939Tp_HasPBConfig()                                                                       (FALSE != FALSE)
#define J1939Tp_HasLTConfigIdxOfPBConfig()                                                          (FALSE != FALSE)
#define J1939Tp_HasPCConfigIdxOfPBConfig()                                                          (FALSE != FALSE)
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


/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


#endif  /* J1939TP_PBCFG_H */

/**********************************************************************************************************************
  END OF FILE: J1939Tp_PBcfg.h
**********************************************************************************************************************/

