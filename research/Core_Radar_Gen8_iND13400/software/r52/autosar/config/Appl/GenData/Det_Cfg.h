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
 *            Module: Det
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Det_Cfg.h
 *   Generation Time: 2026-07-25 16:37:37
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
 
#if !defined(DET_CFG_H)
#define DET_CFG_H

#ifndef DET_USE_DUMMY_STATEMENT
#define DET_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef DET_DUMMY_STATEMENT
#define DET_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef DET_DUMMY_STATEMENT_CONST
#define DET_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef DET_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define DET_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef DET_ATOMIC_VARIABLE_ACCESS
#define DET_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef DET_PROCESSOR_IND13400
#define DET_PROCESSOR_IND13400
#endif
#ifndef DET_COMP_LLVMDIAB
#define DET_COMP_LLVMDIAB
#endif
#ifndef DET_GEN_GENERATOR_MSR
#define DET_GEN_GENERATOR_MSR
#endif
#ifndef DET_CPUTYPE_BITORDER_LSB2MSB
#define DET_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef DET_CONFIGURATION_VARIANT_PRECOMPILE
#define DET_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef DET_CONFIGURATION_VARIANT_LINKTIME
#define DET_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef DET_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define DET_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef DET_CONFIGURATION_VARIANT
#define DET_CONFIGURATION_VARIANT DET_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef DET_POSTBUILD_VARIANT_SUPPORT
#define DET_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define DET_GENERATOR_CFG5
#define DET_AUTOSARVERSION                       4U
#define DET_ENABLED                              STD_ON
#define DET_VERSION_INFO_API                     STD_OFF
#define DET_DEBUG_ENABLED                        STD_ON
#define DET_DLTFILTERSIZE                        0u
#define DET_GLOBALFILTERSIZE                     0u
#define DET_BREAKFILTERSIZE                      5u
#define DET_LOGBUFFERSIZE                        0u
#define DET_FORWARD_TO_DLT                       STD_OFF
#define DET_FORWARD_TO_DEM                       STD_OFF
#define DET_REPORT_ERROR_RECURSIONLIMIT          0u
#define DET_REPORT_RUNTIMEERROR_RECURSIONLIMIT   0u
#define DET_REPORT_TRANSIENTFAULT_RECURSIONLIMIT 0u

/*! DetModuleId symbolic name defines */


/*! Service port defines */


/*! Compatibility defines */
#define DET_RUNTIME_ERROR_CALLOUT_ENABLED        DET_RUNTIMEERRORCALLOUTTABLE
#define DET_TRANSIENT_FAULT_CALLOUT_ENABLED      DET_TRANSIENTFAULTCALLOUTTABLE
#define DET_ERROR_HOOK_ENABLED                   DET_ERRORHOOKTABLE

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DetPCDataSwitches  Det Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define DET_ERRORHOOKTABLE                                                                          STD_OFF  /**< Deactivateable: 'Det_ErrorHookTable' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define DET_FINALMAGICNUMBER                                                                        STD_OFF  /**< Deactivateable: 'Det_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define DET_INITDATAHASHCODE                                                                        STD_OFF  /**< Deactivateable: 'Det_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define DET_RUNTIMEERRORCALLOUTTABLE                                                                STD_OFF  /**< Deactivateable: 'Det_RuntimeErrorCalloutTable' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define DET_SIZEOFERRORHOOKTABLE                                                                    STD_OFF  /**< Deactivateable: 'Det_SizeOfErrorHookTable' Reason: 'Deactivateable: 'ErrorHookTable' Reason: 'Deactivateable: 'Det_ErrorHookTable' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE''' */
#define DET_SIZEOFRUNTIMEERRORCALLOUTTABLE                                                          STD_OFF  /**< Deactivateable: 'Det_SizeOfRuntimeErrorCalloutTable' Reason: 'Deactivateable: 'RuntimeErrorCalloutTable' Reason: 'Deactivateable: 'Det_RuntimeErrorCalloutTable' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE''' */
#define DET_SIZEOFTRANSIENTFAULTCALLOUTTABLE                                                        STD_OFF  /**< Deactivateable: 'Det_SizeOfTransientFaultCalloutTable' Reason: 'Deactivateable: 'TransientFaultCalloutTable' Reason: 'Deactivateable: 'Det_TransientFaultCalloutTable' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE''' */
#define DET_TRANSIENTFAULTCALLOUTTABLE                                                              STD_OFF  /**< Deactivateable: 'Det_TransientFaultCalloutTable' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define DET_PCCONFIG                                                                                STD_OFF  /**< Deactivateable: 'Det_PCConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define DET_FINALMAGICNUMBEROFPCCONFIG                                                              STD_OFF  /**< Deactivateable: 'Det_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define DET_INITDATAHASHCODEOFPCCONFIG                                                              STD_OFF  /**< Deactivateable: 'Det_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define DET_SIZEOFERRORHOOKTABLEOFPCCONFIG                                                          STD_OFF  /**< Deactivateable: 'Det_PCConfig.SizeOfErrorHookTable' Reason: 'Deactivateable: 'ErrorHookTable' Reason: 'Deactivateable: 'Det_ErrorHookTable' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE''' */
#define DET_SIZEOFRUNTIMEERRORCALLOUTTABLEOFPCCONFIG                                                STD_OFF  /**< Deactivateable: 'Det_PCConfig.SizeOfRuntimeErrorCalloutTable' Reason: 'Deactivateable: 'RuntimeErrorCalloutTable' Reason: 'Deactivateable: 'Det_RuntimeErrorCalloutTable' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE''' */
#define DET_SIZEOFTRANSIENTFAULTCALLOUTTABLEOFPCCONFIG                                              STD_OFF  /**< Deactivateable: 'Det_PCConfig.SizeOfTransientFaultCalloutTable' Reason: 'Deactivateable: 'TransientFaultCalloutTable' Reason: 'Deactivateable: 'Det_TransientFaultCalloutTable' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE''' */
/** 
  \}
*/ 

/** 
  \defgroup  DetPCSymbolicInitializationPointers  Det Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Det_Config_Ptr                                                                              NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Det' */
/** 
  \}
*/ 

/** 
  \defgroup  DetPCInitializationSymbols  Det Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Det_Config                                                                                  NULL_PTR  /**< symbolic identifier which could be used to initialize 'Det */
/** 
  \}
*/ 

/** 
  \defgroup  DetPCGeneral  Det General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define DET_CHECK_INIT_POINTER                                                                      STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define DET_FINAL_MAGIC_NUMBER                                                                      0x0F1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of Det */
#define DET_INDIVIDUAL_POSTBUILD                                                                    STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Det' is not configured to be postbuild capable. */
#define DET_INIT_DATA                                                                               DET_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define DET_INIT_DATA_HASH_CODE                                                                     1840703899  /**< the precompile constant to validate the initialization structure at initialization time of Det with a hashcode. The seed value is '0x0F1Eu' */
#define DET_USE_ECUM_BSW_ERROR_HOOK                                                                 STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define DET_USE_INIT_POINTER                                                                        STD_OFF  /**< STD_ON if the init pointer Det shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! Function pointer type for callouts */
typedef P2FUNC(Std_ReturnType, DET_CODE, Det_CalloutTableType)(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);


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
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define DET_START_SEC_CODE
#include "Det_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



#define DET_STOP_SEC_CODE
#include "Det_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */




#endif /* DET_CFG_H */
