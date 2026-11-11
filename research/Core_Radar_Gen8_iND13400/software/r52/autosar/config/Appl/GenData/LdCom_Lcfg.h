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
 *              File: LdCom_Lcfg.h
 *   Generation Time: 2026-04-28 18:02:38
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

#if !defined (LDCOM_LCFG_H)
# define LDCOM_LCFG_H
/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "ComStack_Types.h"
# include "LdCom_Types.h"
# include "LdCom_Cfg.h"
# include "LdCom_PBcfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  LdComPCDataSwitches  LdCom Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define LDCOM_FINALMAGICNUMBER                                                                      STD_OFF  /**< the module configuration does not support flashing of data. */
#define LDCOM_IFRXINDICATIONFCTPTR                                                                  STD_ON
#define LDCOM_IFTXCONFIRMATIONFCTPTR                                                                STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define LDCOM_IFTXTRIGGERTRANSMITFCTPTR                                                             STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define LDCOM_INITDATAHASHCODE                                                                      STD_OFF  /**< the module configuration does not support flashing of data. */
#define LDCOM_INITIALIZED                                                                           STD_ON
#define LDCOM_RXTXPDUINFO                                                                           STD_ON
#define LDCOM_IFPDUOFRXTXPDUINFO                                                                    STD_ON
#define LDCOM_IFRXINDICATIONFCTPTRIDXOFRXTXPDUINFO                                                  STD_ON
#define LDCOM_IFRXINDICATIONFCTPTRUSEDOFRXTXPDUINFO                                                 STD_ON
#define LDCOM_IFTXCONFIRMATIONFCTPTRIDXOFRXTXPDUINFO                                                STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define LDCOM_IFTXCONFIRMATIONFCTPTRUSEDOFRXTXPDUINFO                                               STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define LDCOM_IFTXTRIGGERTRANSMITFCTPTRIDXOFRXTXPDUINFO                                             STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define LDCOM_IFTXTRIGGERTRANSMITFCTPTRUSEDOFRXTXPDUINFO                                            STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define LDCOM_INVALIDHNDOFRXTXPDUINFO                                                               STD_OFF  /**< the value of LdCom_InvalidHndOfRxTxPduInfo is always 'false' due to this, the array is deactivated. */
#define LDCOM_PDURTXHANDLEIDOFRXTXPDUINFO                                                           STD_ON
#define LDCOM_TPCOPYRXDATAFCTPTRIDXOFRXTXPDUINFO                                                    STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define LDCOM_TPCOPYRXDATAFCTPTRUSEDOFRXTXPDUINFO                                                   STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define LDCOM_TPCOPYTXDATAFCTPTRIDXOFRXTXPDUINFO                                                    STD_ON
#define LDCOM_TPCOPYTXDATAFCTPTRUSEDOFRXTXPDUINFO                                                   STD_ON
#define LDCOM_TPRXINDICATIONFCTPTRIDXOFRXTXPDUINFO                                                  STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define LDCOM_TPRXINDICATIONFCTPTRUSEDOFRXTXPDUINFO                                                 STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define LDCOM_TPSTARTOFRECEPTIONFCTPTRIDXOFRXTXPDUINFO                                              STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define LDCOM_TPSTARTOFRECEPTIONFCTPTRUSEDOFRXTXPDUINFO                                             STD_OFF  /**< All indirection targets are deactivated in all variants. */
#define LDCOM_TPTXCONFIRMATIONFCTPTRIDXOFRXTXPDUINFO                                                STD_ON
#define LDCOM_TPTXCONFIRMATIONFCTPTRUSEDOFRXTXPDUINFO                                               STD_ON
#define LDCOM_TXPDUOFRXTXPDUINFO                                                                    STD_ON
#define LDCOM_SIZEOFIFRXINDICATIONFCTPTR                                                            STD_ON
#define LDCOM_SIZEOFIFTXCONFIRMATIONFCTPTR                                                          STD_ON
#define LDCOM_SIZEOFIFTXTRIGGERTRANSMITFCTPTR                                                       STD_ON
#define LDCOM_SIZEOFRXTXPDUINFO                                                                     STD_ON
#define LDCOM_SIZEOFTPCOPYRXDATAFCTPTR                                                              STD_ON
#define LDCOM_SIZEOFTPCOPYTXDATAFCTPTR                                                              STD_ON
#define LDCOM_SIZEOFTPRXINDICATIONFCTPTR                                                            STD_ON
#define LDCOM_SIZEOFTPSTARTOFRECEPTIONFCTPTR                                                        STD_ON
#define LDCOM_SIZEOFTPTXCONFIRMATIONFCTPTR                                                          STD_ON
#define LDCOM_TPCOPYRXDATAFCTPTR                                                                    STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define LDCOM_TPCOPYTXDATAFCTPTR                                                                    STD_ON
#define LDCOM_TPRXINDICATIONFCTPTR                                                                  STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define LDCOM_TPSTARTOFRECEPTIONFCTPTR                                                              STD_OFF  /**< the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE */
#define LDCOM_TPTXCONFIRMATIONFCTPTR                                                                STD_ON
#define LDCOM_PCCONFIG                                                                              STD_ON
#define LDCOM_FINALMAGICNUMBEROFPCCONFIG                                                            STD_OFF  /**< the module configuration does not support flashing of data. */
#define LDCOM_IFRXINDICATIONFCTPTROFPCCONFIG                                                        STD_ON
#define LDCOM_IFTXCONFIRMATIONFCTPTROFPCCONFIG                                                      STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define LDCOM_IFTXTRIGGERTRANSMITFCTPTROFPCCONFIG                                                   STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define LDCOM_INITDATAHASHCODEOFPCCONFIG                                                            STD_OFF  /**< the module configuration does not support flashing of data. */
#define LDCOM_INITIALIZEDOFPCCONFIG                                                                 STD_ON
#define LDCOM_RXTXPDUINFOOFPCCONFIG                                                                 STD_ON
#define LDCOM_SIZEOFIFRXINDICATIONFCTPTROFPCCONFIG                                                  STD_ON
#define LDCOM_SIZEOFIFTXCONFIRMATIONFCTPTROFPCCONFIG                                                STD_ON
#define LDCOM_SIZEOFIFTXTRIGGERTRANSMITFCTPTROFPCCONFIG                                             STD_ON
#define LDCOM_SIZEOFRXTXPDUINFOOFPCCONFIG                                                           STD_ON
#define LDCOM_SIZEOFTPCOPYRXDATAFCTPTROFPCCONFIG                                                    STD_ON
#define LDCOM_SIZEOFTPCOPYTXDATAFCTPTROFPCCONFIG                                                    STD_ON
#define LDCOM_SIZEOFTPRXINDICATIONFCTPTROFPCCONFIG                                                  STD_ON
#define LDCOM_SIZEOFTPSTARTOFRECEPTIONFCTPTROFPCCONFIG                                              STD_ON
#define LDCOM_SIZEOFTPTXCONFIRMATIONFCTPTROFPCCONFIG                                                STD_ON
#define LDCOM_TPCOPYRXDATAFCTPTROFPCCONFIG                                                          STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define LDCOM_TPCOPYTXDATAFCTPTROFPCCONFIG                                                          STD_ON
#define LDCOM_TPRXINDICATIONFCTPTROFPCCONFIG                                                        STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define LDCOM_TPSTARTOFRECEPTIONFCTPTROFPCCONFIG                                                    STD_OFF  /**< the array is deactivated because all elements should be deactivated in all variants. */
#define LDCOM_TPTXCONFIRMATIONFCTPTROFPCCONFIG                                                      STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  LdComPCNoReferenceDefines  LdCom No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define LDCOM_NO_IFRXINDICATIONFCTPTRIDXOFRXTXPDUINFO                                               255u
#define LDCOM_NO_IFTXCONFIRMATIONFCTPTRIDXOFRXTXPDUINFO                                             255u
#define LDCOM_NO_IFTXTRIGGERTRANSMITFCTPTRIDXOFRXTXPDUINFO                                          255u
#define LDCOM_NO_TPCOPYRXDATAFCTPTRIDXOFRXTXPDUINFO                                                 255u
#define LDCOM_NO_TPCOPYTXDATAFCTPTRIDXOFRXTXPDUINFO                                                 255u
#define LDCOM_NO_TPRXINDICATIONFCTPTRIDXOFRXTXPDUINFO                                               255u
#define LDCOM_NO_TPSTARTOFRECEPTIONFCTPTRIDXOFRXTXPDUINFO                                           255u
#define LDCOM_NO_TPTXCONFIRMATIONFCTPTRIDXOFRXTXPDUINFO                                             255u
/** 
  \}
*/ 

/** 
  \defgroup  LdComPCIsReducedToDefineDefines  LdCom Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define LDCOM_ISDEF_IFRXINDICATIONFCTPTR                                                            STD_OFF
#define LDCOM_ISDEF_IFTXCONFIRMATIONFCTPTR                                                          STD_OFF
#define LDCOM_ISDEF_IFTXTRIGGERTRANSMITFCTPTR                                                       STD_OFF
#define LDCOM_ISDEF_IFPDUOFRXTXPDUINFO                                                              STD_OFF
#define LDCOM_ISDEF_IFRXINDICATIONFCTPTRIDXOFRXTXPDUINFO                                            STD_OFF
#define LDCOM_ISDEF_IFRXINDICATIONFCTPTRUSEDOFRXTXPDUINFO                                           STD_OFF
#define LDCOM_ISDEF_IFTXCONFIRMATIONFCTPTRIDXOFRXTXPDUINFO                                          STD_OFF
#define LDCOM_ISDEF_IFTXCONFIRMATIONFCTPTRUSEDOFRXTXPDUINFO                                         STD_OFF
#define LDCOM_ISDEF_IFTXTRIGGERTRANSMITFCTPTRIDXOFRXTXPDUINFO                                       STD_OFF
#define LDCOM_ISDEF_IFTXTRIGGERTRANSMITFCTPTRUSEDOFRXTXPDUINFO                                      STD_OFF
#define LDCOM_ISDEF_INVALIDHNDOFRXTXPDUINFO                                                         STD_OFF
#define LDCOM_ISDEF_PDURTXHANDLEIDOFRXTXPDUINFO                                                     STD_OFF
#define LDCOM_ISDEF_TPCOPYRXDATAFCTPTRIDXOFRXTXPDUINFO                                              STD_OFF
#define LDCOM_ISDEF_TPCOPYRXDATAFCTPTRUSEDOFRXTXPDUINFO                                             STD_OFF
#define LDCOM_ISDEF_TPCOPYTXDATAFCTPTRIDXOFRXTXPDUINFO                                              STD_OFF
#define LDCOM_ISDEF_TPCOPYTXDATAFCTPTRUSEDOFRXTXPDUINFO                                             STD_OFF
#define LDCOM_ISDEF_TPRXINDICATIONFCTPTRIDXOFRXTXPDUINFO                                            STD_OFF
#define LDCOM_ISDEF_TPRXINDICATIONFCTPTRUSEDOFRXTXPDUINFO                                           STD_OFF
#define LDCOM_ISDEF_TPSTARTOFRECEPTIONFCTPTRIDXOFRXTXPDUINFO                                        STD_OFF
#define LDCOM_ISDEF_TPSTARTOFRECEPTIONFCTPTRUSEDOFRXTXPDUINFO                                       STD_OFF
#define LDCOM_ISDEF_TPTXCONFIRMATIONFCTPTRIDXOFRXTXPDUINFO                                          STD_OFF
#define LDCOM_ISDEF_TPTXCONFIRMATIONFCTPTRUSEDOFRXTXPDUINFO                                         STD_OFF
#define LDCOM_ISDEF_TXPDUOFRXTXPDUINFO                                                              STD_OFF
#define LDCOM_ISDEF_TPCOPYRXDATAFCTPTR                                                              STD_OFF
#define LDCOM_ISDEF_TPCOPYTXDATAFCTPTR                                                              STD_OFF
#define LDCOM_ISDEF_TPRXINDICATIONFCTPTR                                                            STD_OFF
#define LDCOM_ISDEF_TPSTARTOFRECEPTIONFCTPTR                                                        STD_OFF
#define LDCOM_ISDEF_TPTXCONFIRMATIONFCTPTR                                                          STD_OFF
#define LDCOM_ISDEF_IFRXINDICATIONFCTPTROFPCCONFIG                                                  STD_ON
#define LDCOM_ISDEF_IFTXCONFIRMATIONFCTPTROFPCCONFIG                                                STD_ON
#define LDCOM_ISDEF_IFTXTRIGGERTRANSMITFCTPTROFPCCONFIG                                             STD_ON
#define LDCOM_ISDEF_INITIALIZEDOFPCCONFIG                                                           STD_ON
#define LDCOM_ISDEF_RXTXPDUINFOOFPCCONFIG                                                           STD_ON
#define LDCOM_ISDEF_TPCOPYRXDATAFCTPTROFPCCONFIG                                                    STD_ON
#define LDCOM_ISDEF_TPCOPYTXDATAFCTPTROFPCCONFIG                                                    STD_ON
#define LDCOM_ISDEF_TPRXINDICATIONFCTPTROFPCCONFIG                                                  STD_ON
#define LDCOM_ISDEF_TPSTARTOFRECEPTIONFCTPTROFPCCONFIG                                              STD_ON
#define LDCOM_ISDEF_TPTXCONFIRMATIONFCTPTROFPCCONFIG                                                STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  LdComPCEqualsAlwaysToDefines  LdCom Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define LDCOM_EQ2_IFRXINDICATIONFCTPTR                                                              
#define LDCOM_EQ2_IFTXCONFIRMATIONFCTPTR                                                            
#define LDCOM_EQ2_IFTXTRIGGERTRANSMITFCTPTR                                                         
#define LDCOM_EQ2_IFPDUOFRXTXPDUINFO                                                                
#define LDCOM_EQ2_IFRXINDICATIONFCTPTRIDXOFRXTXPDUINFO                                              
#define LDCOM_EQ2_IFRXINDICATIONFCTPTRUSEDOFRXTXPDUINFO                                             
#define LDCOM_EQ2_IFTXCONFIRMATIONFCTPTRIDXOFRXTXPDUINFO                                            
#define LDCOM_EQ2_IFTXCONFIRMATIONFCTPTRUSEDOFRXTXPDUINFO                                           
#define LDCOM_EQ2_IFTXTRIGGERTRANSMITFCTPTRIDXOFRXTXPDUINFO                                         
#define LDCOM_EQ2_IFTXTRIGGERTRANSMITFCTPTRUSEDOFRXTXPDUINFO                                        
#define LDCOM_EQ2_INVALIDHNDOFRXTXPDUINFO                                                           
#define LDCOM_EQ2_PDURTXHANDLEIDOFRXTXPDUINFO                                                       
#define LDCOM_EQ2_TPCOPYRXDATAFCTPTRIDXOFRXTXPDUINFO                                                
#define LDCOM_EQ2_TPCOPYRXDATAFCTPTRUSEDOFRXTXPDUINFO                                               
#define LDCOM_EQ2_TPCOPYTXDATAFCTPTRIDXOFRXTXPDUINFO                                                
#define LDCOM_EQ2_TPCOPYTXDATAFCTPTRUSEDOFRXTXPDUINFO                                               
#define LDCOM_EQ2_TPRXINDICATIONFCTPTRIDXOFRXTXPDUINFO                                              
#define LDCOM_EQ2_TPRXINDICATIONFCTPTRUSEDOFRXTXPDUINFO                                             
#define LDCOM_EQ2_TPSTARTOFRECEPTIONFCTPTRIDXOFRXTXPDUINFO                                          
#define LDCOM_EQ2_TPSTARTOFRECEPTIONFCTPTRUSEDOFRXTXPDUINFO                                         
#define LDCOM_EQ2_TPTXCONFIRMATIONFCTPTRIDXOFRXTXPDUINFO                                            
#define LDCOM_EQ2_TPTXCONFIRMATIONFCTPTRUSEDOFRXTXPDUINFO                                           
#define LDCOM_EQ2_TXPDUOFRXTXPDUINFO                                                                
#define LDCOM_EQ2_TPCOPYRXDATAFCTPTR                                                                
#define LDCOM_EQ2_TPCOPYTXDATAFCTPTR                                                                
#define LDCOM_EQ2_TPRXINDICATIONFCTPTR                                                              
#define LDCOM_EQ2_TPSTARTOFRECEPTIONFCTPTR                                                          
#define LDCOM_EQ2_TPTXCONFIRMATIONFCTPTR                                                            
#define LDCOM_EQ2_IFRXINDICATIONFCTPTROFPCCONFIG                                                    LdCom_IfRxIndicationFctPtr
#define LDCOM_EQ2_IFTXCONFIRMATIONFCTPTROFPCCONFIG                                                  LdCom_IfTxConfirmationFctPtr
#define LDCOM_EQ2_IFTXTRIGGERTRANSMITFCTPTROFPCCONFIG                                               LdCom_IfTxTriggerTransmitFctPtr
#define LDCOM_EQ2_INITIALIZEDOFPCCONFIG                                                             (&(LdCom_Initialized))
#define LDCOM_EQ2_RXTXPDUINFOOFPCCONFIG                                                             LdCom_RxTxPduInfo
#define LDCOM_EQ2_TPCOPYRXDATAFCTPTROFPCCONFIG                                                      LdCom_TpCopyRxDataFctPtr
#define LDCOM_EQ2_TPCOPYTXDATAFCTPTROFPCCONFIG                                                      LdCom_TpCopyTxDataFctPtr
#define LDCOM_EQ2_TPRXINDICATIONFCTPTROFPCCONFIG                                                    LdCom_TpRxIndicationFctPtr
#define LDCOM_EQ2_TPSTARTOFRECEPTIONFCTPTROFPCCONFIG                                                LdCom_TpStartOfReceptionFctPtr
#define LDCOM_EQ2_TPTXCONFIRMATIONFCTPTROFPCCONFIG                                                  LdCom_TpTxConfirmationFctPtr
/** 
  \}
*/ 

/** 
  \defgroup  LdComPCSymbolicNonDereferenciateablePointers  LdCom Symbolic Non Dereferenciateable Pointers (PRE_COMPILE)
  \brief  Symbolic non dereferenciateable pointers to be used if all values are optimized to a defined and to return a correct value for has macros in variants.
  \{
*/ 
#define LdCom_IfTxConfirmationFctPtr                                                                ((LdCom_IfTxConfirmationFctPtrPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define LdCom_IfTxTriggerTransmitFctPtr                                                             ((LdCom_IfTxTriggerTransmitFctPtrPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define LdCom_TpCopyRxDataFctPtr                                                                    ((LdCom_TpCopyRxDataFctPtrPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define LdCom_TpRxIndicationFctPtr                                                                  ((LdCom_TpRxIndicationFctPtrPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
#define LdCom_TpStartOfReceptionFctPtr                                                              ((LdCom_TpStartOfReceptionFctPtrPtrType)(NULL_PTR))  /**< Non derefenciateable valid pointer */
/** 
  \}
*/ 

/** 
  \defgroup  LdComPCSymbolicInitializationPointers  LdCom Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define LdCom_Config_Ptr                                                                            NULL_PTR  /**< symbolic identifier which shall be used to initialize 'LdCom' */
/** 
  \}
*/ 

/** 
  \defgroup  LdComPCInitializationSymbols  LdCom Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define LdCom_Config                                                                                NULL_PTR  /**< symbolic identifier which could be used to initialize 'LdCom */
/** 
  \}
*/ 

/** 
  \defgroup  LdComPCGeneral  LdCom General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define LDCOM_CHECK_INIT_POINTER                                                                    STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define LDCOM_FINAL_MAGIC_NUMBER                                                                    0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of LdCom */
#define LDCOM_INDIVIDUAL_POSTBUILD                                                                  STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'LdCom' is not configured to be postbuild capable. */
#define LDCOM_INIT_DATA                                                                             LDCOM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define LDCOM_INIT_DATA_HASH_CODE                                                                   -392515026  /**< the precompile constant to validate the initialization structure at initialization time of LdCom with a hashcode. The seed value is '0xFF1Eu' */
#define LDCOM_USE_ECUM_BSW_ERROR_HOOK                                                               STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define LDCOM_USE_INIT_POINTER                                                                      STD_OFF  /**< STD_ON if the init pointer LdCom shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  LdComLTDataSwitches  LdCom Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define LDCOM_LTCONFIG                                                                              STD_OFF  /**< the module configuration is VARIANT_PRE_COMPILE. */
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
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  LdComPCGetConstantDuplicatedRootDataMacros  LdCom Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define LdCom_GetFinalMagicNumberOfPCConfig()                                                       0xFF1Eu  /**< the FinalMagicNumber to validate the size of the initialization structure at initialization time of LdCom */
#define LdCom_GetIfRxIndicationFctPtrOfPCConfig()                                                   LdCom_IfRxIndicationFctPtr  /**< the pointer to LdCom_IfRxIndicationFctPtr */
#define LdCom_GetIfTxConfirmationFctPtrOfPCConfig()                                                 LdCom_IfTxConfirmationFctPtr  /**< the pointer to LdCom_IfTxConfirmationFctPtr */
#define LdCom_GetIfTxTriggerTransmitFctPtrOfPCConfig()                                              LdCom_IfTxTriggerTransmitFctPtr  /**< the pointer to LdCom_IfTxTriggerTransmitFctPtr */
#define LdCom_GetInitDataHashCodeOfPCConfig()                                                       -862057835  /**< the hashcode to validate the initialization structure at initialization time of LdCom */
#define LdCom_GetInitializedOfPCConfig()                                                            (&(LdCom_Initialized))  /**< the pointer to LdCom_Initialized */
#define LdCom_GetRxTxPduInfoOfPCConfig()                                                            LdCom_RxTxPduInfo  /**< the pointer to LdCom_RxTxPduInfo */
#define LdCom_GetSizeOfIfRxIndicationFctPtrOfPCConfig()                                             1u  /**< the number of accomplishable value elements in LdCom_IfRxIndicationFctPtr */
#define LdCom_GetSizeOfIfTxConfirmationFctPtrOfPCConfig()                                           0u  /**< the number of accomplishable value elements in LdCom_IfTxConfirmationFctPtr */
#define LdCom_GetSizeOfIfTxTriggerTransmitFctPtrOfPCConfig()                                        0u  /**< the number of accomplishable value elements in LdCom_IfTxTriggerTransmitFctPtr */
#define LdCom_GetSizeOfRxTxPduInfoOfPCConfig()                                                      4u  /**< the number of accomplishable value elements in LdCom_RxTxPduInfo */
#define LdCom_GetSizeOfTpCopyRxDataFctPtrOfPCConfig()                                               0u  /**< the number of accomplishable value elements in LdCom_TpCopyRxDataFctPtr */
#define LdCom_GetSizeOfTpCopyTxDataFctPtrOfPCConfig()                                               1u  /**< the number of accomplishable value elements in LdCom_TpCopyTxDataFctPtr */
#define LdCom_GetSizeOfTpRxIndicationFctPtrOfPCConfig()                                             0u  /**< the number of accomplishable value elements in LdCom_TpRxIndicationFctPtr */
#define LdCom_GetSizeOfTpStartOfReceptionFctPtrOfPCConfig()                                         0u  /**< the number of accomplishable value elements in LdCom_TpStartOfReceptionFctPtr */
#define LdCom_GetSizeOfTpTxConfirmationFctPtrOfPCConfig()                                           1u  /**< the number of accomplishable value elements in LdCom_TpTxConfirmationFctPtr */
#define LdCom_GetTpCopyRxDataFctPtrOfPCConfig()                                                     LdCom_TpCopyRxDataFctPtr  /**< the pointer to LdCom_TpCopyRxDataFctPtr */
#define LdCom_GetTpCopyTxDataFctPtrOfPCConfig()                                                     LdCom_TpCopyTxDataFctPtr  /**< the pointer to LdCom_TpCopyTxDataFctPtr */
#define LdCom_GetTpRxIndicationFctPtrOfPCConfig()                                                   LdCom_TpRxIndicationFctPtr  /**< the pointer to LdCom_TpRxIndicationFctPtr */
#define LdCom_GetTpStartOfReceptionFctPtrOfPCConfig()                                               LdCom_TpStartOfReceptionFctPtr  /**< the pointer to LdCom_TpStartOfReceptionFctPtr */
#define LdCom_GetTpTxConfirmationFctPtrOfPCConfig()                                                 LdCom_TpTxConfirmationFctPtr  /**< the pointer to LdCom_TpTxConfirmationFctPtr */
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef P2FUNC(void, LDCOM_APPL_CODE, LdCom_IfRxIndicationFctPtrType) (
                                                                     P2CONST(PduInfoType, AUTOMATIC, LDCOM_APPL_DATA));		/* PRQA S 1336 */ /* MD_LdCom_1336 */


typedef P2FUNC(void, LDCOM_APPL_CODE, LdCom_IfTxConfirmationFctPtrType) (void);

typedef P2FUNC(Std_ReturnType, LDCOM_APPL_CODE, LdCom_IfTxTriggerTransmitFctPtrType) (
                                                                     P2VAR(PduInfoType, AUTOMATIC, LDCOM_APPL_DATA));		/* PRQA S 1336 */ /* MD_LdCom_1336 */

typedef P2FUNC(BufReq_ReturnType, LDCOM_APPL_CODE, LdCom_TpStartOfReceptionFctPtrType) (
                                                                     P2CONST(PduInfoType, AUTOMATIC, LDCOM_APPL_DATA),		/* PRQA S 1336 */ /* MD_LdCom_1336 */
                                                                     PduLengthType,											/* PRQA S 1336 */ /* MD_LdCom_1336 */
                                                                     P2VAR(PduLengthType, AUTOMATIC, LDCOM_APPL_DATA));		/* PRQA S 1336 */ /* MD_LdCom_1336 */
typedef P2FUNC(BufReq_ReturnType, LDCOM_APPL_CODE, LdCom_TpCopyRxDataFctPtrType) (
                                                                     P2CONST(PduInfoType, AUTOMATIC, LDCOM_APPL_DATA),		/* PRQA S 1336 */ /* MD_LdCom_1336 */
                                                                     P2VAR(PduLengthType, AUTOMATIC, LDCOM_APPL_DATA));		/* PRQA S 1336 */ /* MD_LdCom_1336 */
typedef P2FUNC(void, LDCOM_APPL_CODE, LdCom_TpRxIndicationFctPtrType) (Std_ReturnType);		/* PRQA S 1336 */ /* MD_LdCom_1336 */

typedef P2FUNC(BufReq_ReturnType, LDCOM_APPL_CODE, LdCom_TpCopyTxDataFctPtrType) (
                                                                     P2CONST(PduInfoType, AUTOMATIC, LDCOM_APPL_DATA),		/* PRQA S 1336 */ /* MD_LdCom_1336 */
                                                                     P2VAR(RetryInfoType, AUTOMATIC, LDCOM_APPL_DATA),		/* PRQA S 1336 */ /* MD_LdCom_1336 */
                                                                     P2VAR(PduLengthType, AUTOMATIC, LDCOM_APPL_DATA));		/* PRQA S 1336 */ /* MD_LdCom_1336 */
typedef P2FUNC(void, LDCOM_APPL_CODE, LdCom_TpTxConfirmationFctPtrType) (Std_ReturnType);		/* PRQA S 1336 */ /* MD_LdCom_1336 */


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/** 
  \defgroup  LdComPCSizeOfTypes  LdCom SizeOf Types (PRE_COMPILE)
  \brief  These type definitions are used for the SizeOf information.
  \{
*/ 
/**   \brief  value based type definition for LdCom_SizeOfIfRxIndicationFctPtr */
typedef uint8 LdCom_SizeOfIfRxIndicationFctPtrType;

/**   \brief  value based type definition for LdCom_SizeOfIfTxConfirmationFctPtr */
typedef uint8 LdCom_SizeOfIfTxConfirmationFctPtrType;

/**   \brief  value based type definition for LdCom_SizeOfIfTxTriggerTransmitFctPtr */
typedef uint8 LdCom_SizeOfIfTxTriggerTransmitFctPtrType;

/**   \brief  value based type definition for LdCom_SizeOfRxTxPduInfo */
typedef uint8 LdCom_SizeOfRxTxPduInfoType;

/**   \brief  value based type definition for LdCom_SizeOfTpCopyRxDataFctPtr */
typedef uint8 LdCom_SizeOfTpCopyRxDataFctPtrType;

/**   \brief  value based type definition for LdCom_SizeOfTpCopyTxDataFctPtr */
typedef uint8 LdCom_SizeOfTpCopyTxDataFctPtrType;

/**   \brief  value based type definition for LdCom_SizeOfTpRxIndicationFctPtr */
typedef uint8 LdCom_SizeOfTpRxIndicationFctPtrType;

/**   \brief  value based type definition for LdCom_SizeOfTpStartOfReceptionFctPtr */
typedef uint8 LdCom_SizeOfTpStartOfReceptionFctPtrType;

/**   \brief  value based type definition for LdCom_SizeOfTpTxConfirmationFctPtr */
typedef uint8 LdCom_SizeOfTpTxConfirmationFctPtrType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  LdComPCIterableTypes  LdCom Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate LdCom_IfRxIndicationFctPtr */
typedef uint8_least LdCom_IfRxIndicationFctPtrIterType;

/**   \brief  type used to iterate LdCom_IfTxConfirmationFctPtr */
typedef uint8_least LdCom_IfTxConfirmationFctPtrIterType;

/**   \brief  type used to iterate LdCom_IfTxTriggerTransmitFctPtr */
typedef uint8_least LdCom_IfTxTriggerTransmitFctPtrIterType;

/**   \brief  type used to iterate LdCom_RxTxPduInfo */
typedef uint8_least LdCom_RxTxPduInfoIterType;

/**   \brief  type used to iterate LdCom_TpCopyRxDataFctPtr */
typedef uint8_least LdCom_TpCopyRxDataFctPtrIterType;

/**   \brief  type used to iterate LdCom_TpCopyTxDataFctPtr */
typedef uint8_least LdCom_TpCopyTxDataFctPtrIterType;

/**   \brief  type used to iterate LdCom_TpRxIndicationFctPtr */
typedef uint8_least LdCom_TpRxIndicationFctPtrIterType;

/**   \brief  type used to iterate LdCom_TpStartOfReceptionFctPtr */
typedef uint8_least LdCom_TpStartOfReceptionFctPtrIterType;

/**   \brief  type used to iterate LdCom_TpTxConfirmationFctPtr */
typedef uint8_least LdCom_TpTxConfirmationFctPtrIterType;

/** 
  \}
*/ 

/** 
  \defgroup  LdComPCValueTypes  LdCom Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for LdCom_FinalMagicNumber */
typedef uint16 LdCom_FinalMagicNumberType;

/**   \brief  value based type definition for LdCom_InitDataHashCode */
typedef sint32 LdCom_InitDataHashCodeType;

/**   \brief  value based type definition for LdCom_Initialized */
typedef boolean LdCom_InitializedType;

/**   \brief  value based type definition for LdCom_IfPduOfRxTxPduInfo */
typedef boolean LdCom_IfPduOfRxTxPduInfoType;

/**   \brief  value based type definition for LdCom_IfRxIndicationFctPtrIdxOfRxTxPduInfo */
typedef uint8 LdCom_IfRxIndicationFctPtrIdxOfRxTxPduInfoType;

/**   \brief  value based type definition for LdCom_IfRxIndicationFctPtrUsedOfRxTxPduInfo */
typedef boolean LdCom_IfRxIndicationFctPtrUsedOfRxTxPduInfoType;

/**   \brief  value based type definition for LdCom_IfTxConfirmationFctPtrIdxOfRxTxPduInfo */
typedef uint8 LdCom_IfTxConfirmationFctPtrIdxOfRxTxPduInfoType;

/**   \brief  value based type definition for LdCom_IfTxConfirmationFctPtrUsedOfRxTxPduInfo */
typedef boolean LdCom_IfTxConfirmationFctPtrUsedOfRxTxPduInfoType;

/**   \brief  value based type definition for LdCom_IfTxTriggerTransmitFctPtrIdxOfRxTxPduInfo */
typedef uint8 LdCom_IfTxTriggerTransmitFctPtrIdxOfRxTxPduInfoType;

/**   \brief  value based type definition for LdCom_IfTxTriggerTransmitFctPtrUsedOfRxTxPduInfo */
typedef boolean LdCom_IfTxTriggerTransmitFctPtrUsedOfRxTxPduInfoType;

/**   \brief  value based type definition for LdCom_InvalidHndOfRxTxPduInfo */
typedef boolean LdCom_InvalidHndOfRxTxPduInfoType;

/**   \brief  value based type definition for LdCom_PduRTxHandleIdOfRxTxPduInfo */
typedef uint8 LdCom_PduRTxHandleIdOfRxTxPduInfoType;

/**   \brief  value based type definition for LdCom_TpCopyRxDataFctPtrIdxOfRxTxPduInfo */
typedef uint8 LdCom_TpCopyRxDataFctPtrIdxOfRxTxPduInfoType;

/**   \brief  value based type definition for LdCom_TpCopyRxDataFctPtrUsedOfRxTxPduInfo */
typedef boolean LdCom_TpCopyRxDataFctPtrUsedOfRxTxPduInfoType;

/**   \brief  value based type definition for LdCom_TpCopyTxDataFctPtrIdxOfRxTxPduInfo */
typedef uint8 LdCom_TpCopyTxDataFctPtrIdxOfRxTxPduInfoType;

/**   \brief  value based type definition for LdCom_TpCopyTxDataFctPtrUsedOfRxTxPduInfo */
typedef boolean LdCom_TpCopyTxDataFctPtrUsedOfRxTxPduInfoType;

/**   \brief  value based type definition for LdCom_TpRxIndicationFctPtrIdxOfRxTxPduInfo */
typedef uint8 LdCom_TpRxIndicationFctPtrIdxOfRxTxPduInfoType;

/**   \brief  value based type definition for LdCom_TpRxIndicationFctPtrUsedOfRxTxPduInfo */
typedef boolean LdCom_TpRxIndicationFctPtrUsedOfRxTxPduInfoType;

/**   \brief  value based type definition for LdCom_TpStartOfReceptionFctPtrIdxOfRxTxPduInfo */
typedef uint8 LdCom_TpStartOfReceptionFctPtrIdxOfRxTxPduInfoType;

/**   \brief  value based type definition for LdCom_TpStartOfReceptionFctPtrUsedOfRxTxPduInfo */
typedef boolean LdCom_TpStartOfReceptionFctPtrUsedOfRxTxPduInfoType;

/**   \brief  value based type definition for LdCom_TpTxConfirmationFctPtrIdxOfRxTxPduInfo */
typedef uint8 LdCom_TpTxConfirmationFctPtrIdxOfRxTxPduInfoType;

/**   \brief  value based type definition for LdCom_TpTxConfirmationFctPtrUsedOfRxTxPduInfo */
typedef boolean LdCom_TpTxConfirmationFctPtrUsedOfRxTxPduInfoType;

/**   \brief  value based type definition for LdCom_TxPduOfRxTxPduInfo */
typedef boolean LdCom_TxPduOfRxTxPduInfoType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  LdComPCStructTypes  LdCom Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in LdCom_RxTxPduInfo */
typedef struct sLdCom_RxTxPduInfoType
{
  LdCom_IfRxIndicationFctPtrIdxOfRxTxPduInfoType IfRxIndicationFctPtrIdxOfRxTxPduInfo;  /**< the index of the 0:1 relation pointing to LdCom_IfRxIndicationFctPtr */
  LdCom_PduRTxHandleIdOfRxTxPduInfoType PduRTxHandleIdOfRxTxPduInfo;  /**< Handle ID used to call PduR_LdComTransmit() */
  LdCom_TpCopyTxDataFctPtrIdxOfRxTxPduInfoType TpCopyTxDataFctPtrIdxOfRxTxPduInfo;  /**< the index of the 0:1 relation pointing to LdCom_TpCopyTxDataFctPtr */
  LdCom_TpTxConfirmationFctPtrIdxOfRxTxPduInfoType TpTxConfirmationFctPtrIdxOfRxTxPduInfo;  /**< the index of the 0:1 relation pointing to LdCom_TpTxConfirmationFctPtr */
} LdCom_RxTxPduInfoType;

/** 
  \}
*/ 

/** 
  \defgroup  LdComPCRootPointerTypes  LdCom Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to LdCom_IfRxIndicationFctPtr */
typedef P2CONST(LdCom_IfRxIndicationFctPtrType, TYPEDEF, LDCOM_CONST) LdCom_IfRxIndicationFctPtrPtrType;

/**   \brief  type used to point to LdCom_IfTxConfirmationFctPtr */
typedef P2CONST(LdCom_IfTxConfirmationFctPtrType, TYPEDEF, LDCOM_CONST) LdCom_IfTxConfirmationFctPtrPtrType;

/**   \brief  type used to point to LdCom_IfTxTriggerTransmitFctPtr */
typedef P2CONST(LdCom_IfTxTriggerTransmitFctPtrType, TYPEDEF, LDCOM_CONST) LdCom_IfTxTriggerTransmitFctPtrPtrType;

/**   \brief  type used to point to LdCom_Initialized */
typedef P2VAR(LdCom_InitializedType, TYPEDEF, LDCOM_VAR_CLEARED) LdCom_InitializedPtrType;

/**   \brief  type used to point to LdCom_RxTxPduInfo */
typedef P2CONST(LdCom_RxTxPduInfoType, TYPEDEF, LDCOM_CONST) LdCom_RxTxPduInfoPtrType;

/**   \brief  type used to point to LdCom_TpCopyRxDataFctPtr */
typedef P2CONST(LdCom_TpCopyRxDataFctPtrType, TYPEDEF, LDCOM_CONST) LdCom_TpCopyRxDataFctPtrPtrType;

/**   \brief  type used to point to LdCom_TpCopyTxDataFctPtr */
typedef P2CONST(LdCom_TpCopyTxDataFctPtrType, TYPEDEF, LDCOM_CONST) LdCom_TpCopyTxDataFctPtrPtrType;

/**   \brief  type used to point to LdCom_TpRxIndicationFctPtr */
typedef P2CONST(LdCom_TpRxIndicationFctPtrType, TYPEDEF, LDCOM_CONST) LdCom_TpRxIndicationFctPtrPtrType;

/**   \brief  type used to point to LdCom_TpStartOfReceptionFctPtr */
typedef P2CONST(LdCom_TpStartOfReceptionFctPtrType, TYPEDEF, LDCOM_CONST) LdCom_TpStartOfReceptionFctPtrPtrType;

/**   \brief  type used to point to LdCom_TpTxConfirmationFctPtr */
typedef P2CONST(LdCom_TpTxConfirmationFctPtrType, TYPEDEF, LDCOM_CONST) LdCom_TpTxConfirmationFctPtrPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  LdComPCRootValueTypes  LdCom Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in LdCom_PCConfig */
typedef struct sLdCom_PCConfigType
{
  uint8 LdCom_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} LdCom_PCConfigType;

typedef LdCom_PCConfigType LdCom_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: SIZEOF DATA TYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  LdCom_IfRxIndicationFctPtr
**********************************************************************************************************************/
/** 
  \var    LdCom_IfRxIndicationFctPtr
  \brief  Upper layer communication interface Rx indication function pointer according DefinitionRef: /MICROSAR/LdCom/LdComConfig/LdComIPdu/LdComRxIndication
*/ 
#define LDCOM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(LdCom_IfRxIndicationFctPtrType, LDCOM_CONST) LdCom_IfRxIndicationFctPtr[1];
#define LDCOM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LdCom_RxTxPduInfo
**********************************************************************************************************************/
/** 
  \var    LdCom_RxTxPduInfo
  \brief  Table containing mapping data from Input handles to PduR Tx handles/RTE callbacks.
  \details
  Element                      Description
  IfRxIndicationFctPtrIdx      the index of the 0:1 relation pointing to LdCom_IfRxIndicationFctPtr
  PduRTxHandleId               Handle ID used to call PduR_LdComTransmit()
  TpCopyTxDataFctPtrIdx        the index of the 0:1 relation pointing to LdCom_TpCopyTxDataFctPtr
  TpTxConfirmationFctPtrIdx    the index of the 0:1 relation pointing to LdCom_TpTxConfirmationFctPtr
*/ 
#define LDCOM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(LdCom_RxTxPduInfoType, LDCOM_CONST) LdCom_RxTxPduInfo[4];
#define LDCOM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LdCom_TpCopyTxDataFctPtr
**********************************************************************************************************************/
/** 
  \var    LdCom_TpCopyTxDataFctPtr
  \brief  Upper layer transport protocol CopyTxData function pointer according DefinitionRef: /MICROSAR/LdCom/LdComConfig/LdComIPdu/LdComTxCopyTxData
*/ 
#define LDCOM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(LdCom_TpCopyTxDataFctPtrType, LDCOM_CONST) LdCom_TpCopyTxDataFctPtr[1];
#define LDCOM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LdCom_TpTxConfirmationFctPtr
**********************************************************************************************************************/
/** 
  \var    LdCom_TpTxConfirmationFctPtr
  \brief  Upper layer transport protocol TpTxConfirmation function pointer according DefinitionRef: /MICROSAR/LdCom/LdComConfig/LdComIPdu/LdComTpTxConfirmation
*/ 
#define LDCOM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(LdCom_TpTxConfirmationFctPtrType, LDCOM_CONST) LdCom_TpTxConfirmationFctPtr[1];
#define LDCOM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  LdCom_Initialized
**********************************************************************************************************************/
/** 
  \var    LdCom_Initialized
  \brief  Initialization state of LdCom. TRUE, if initialized.
*/ 
#define LDCOM_START_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(LdCom_InitializedType, LDCOM_VAR_CLEARED) LdCom_Initialized;
#define LDCOM_STOP_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


# define LDCOM_START_SEC_VAR_CLEARED_UNSPECIFIED
# include "LdCom_MemMap.h"    /* PRQA S 5087 */       /* MD_MSR_MemMap */
# if (LDCOM_USE_INIT_POINTER == STD_ON)
extern P2CONST(LdCom_ConfigType, LDCOM_VAR_CLEARED, LDCOM_PBCFG) LdCom_ConfigDataPtr;
# endif
# define LDCOM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# include "LdCom_MemMap.h"    /* PRQA S 5087 */       /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIZEOF INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define LDCOM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  LdComPCSizeOfInlineFunctionPrototypes  SizeOf Inline Function Prototypes
  \brief  These inline functions are used to get SizeOf data.
  \{
*/ 
LDCOM_LOCAL_INLINE FUNC(LdCom_SizeOfIfRxIndicationFctPtrType, LDCOM_CODE) LdCom_GetSizeOfIfRxIndicationFctPtr(void);
LDCOM_LOCAL_INLINE FUNC(LdCom_SizeOfIfTxConfirmationFctPtrType, LDCOM_CODE) LdCom_GetSizeOfIfTxConfirmationFctPtr(void);
LDCOM_LOCAL_INLINE FUNC(LdCom_SizeOfIfTxTriggerTransmitFctPtrType, LDCOM_CODE) LdCom_GetSizeOfIfTxTriggerTransmitFctPtr(void);
LDCOM_LOCAL_INLINE FUNC(LdCom_SizeOfRxTxPduInfoType, LDCOM_CODE) LdCom_GetSizeOfRxTxPduInfo(void);
LDCOM_LOCAL_INLINE FUNC(LdCom_SizeOfTpCopyRxDataFctPtrType, LDCOM_CODE) LdCom_GetSizeOfTpCopyRxDataFctPtr(void);
LDCOM_LOCAL_INLINE FUNC(LdCom_SizeOfTpCopyTxDataFctPtrType, LDCOM_CODE) LdCom_GetSizeOfTpCopyTxDataFctPtr(void);
LDCOM_LOCAL_INLINE FUNC(LdCom_SizeOfTpRxIndicationFctPtrType, LDCOM_CODE) LdCom_GetSizeOfTpRxIndicationFctPtr(void);
LDCOM_LOCAL_INLINE FUNC(LdCom_SizeOfTpStartOfReceptionFctPtrType, LDCOM_CODE) LdCom_GetSizeOfTpStartOfReceptionFctPtr(void);
LDCOM_LOCAL_INLINE FUNC(LdCom_SizeOfTpTxConfirmationFctPtrType, LDCOM_CODE) LdCom_GetSizeOfTpTxConfirmationFctPtr(void);
/** 
  \}
*/ 

#define LDCOM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define LDCOM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  LdComPCGetDataInlineFunctionPrototypes  Get Data Inline Function Prototypes
  \brief  These inline functions can be used to read CONST and VAR data.
  \{
*/ 
LDCOM_LOCAL_INLINE FUNC(LdCom_IfRxIndicationFctPtrType, LDCOM_CODE) LdCom_GetIfRxIndicationFctPtr(LdCom_IfRxIndicationFctPtrIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_IfTxConfirmationFctPtrType, LDCOM_CODE) LdCom_GetIfTxConfirmationFctPtr(LdCom_IfTxConfirmationFctPtrIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_IfTxTriggerTransmitFctPtrType, LDCOM_CODE) LdCom_GetIfTxTriggerTransmitFctPtr(LdCom_IfTxTriggerTransmitFctPtrIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_InitializedType, LDCOM_CODE) LdCom_IsInitialized(void);
LDCOM_LOCAL_INLINE FUNC(LdCom_IfRxIndicationFctPtrIdxOfRxTxPduInfoType, LDCOM_CODE) LdCom_GetIfRxIndicationFctPtrIdxOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_IfTxConfirmationFctPtrIdxOfRxTxPduInfoType, LDCOM_CODE) LdCom_GetIfTxConfirmationFctPtrIdxOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_IfTxConfirmationFctPtrUsedOfRxTxPduInfoType, LDCOM_CODE) LdCom_IsIfTxConfirmationFctPtrUsedOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_IfTxTriggerTransmitFctPtrIdxOfRxTxPduInfoType, LDCOM_CODE) LdCom_GetIfTxTriggerTransmitFctPtrIdxOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_IfTxTriggerTransmitFctPtrUsedOfRxTxPduInfoType, LDCOM_CODE) LdCom_IsIfTxTriggerTransmitFctPtrUsedOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_InvalidHndOfRxTxPduInfoType, LDCOM_CODE) LdCom_IsInvalidHndOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_PduRTxHandleIdOfRxTxPduInfoType, LDCOM_CODE) LdCom_GetPduRTxHandleIdOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_TpCopyRxDataFctPtrIdxOfRxTxPduInfoType, LDCOM_CODE) LdCom_GetTpCopyRxDataFctPtrIdxOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_TpCopyRxDataFctPtrUsedOfRxTxPduInfoType, LDCOM_CODE) LdCom_IsTpCopyRxDataFctPtrUsedOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_TpCopyTxDataFctPtrIdxOfRxTxPduInfoType, LDCOM_CODE) LdCom_GetTpCopyTxDataFctPtrIdxOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_TpRxIndicationFctPtrIdxOfRxTxPduInfoType, LDCOM_CODE) LdCom_GetTpRxIndicationFctPtrIdxOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_TpRxIndicationFctPtrUsedOfRxTxPduInfoType, LDCOM_CODE) LdCom_IsTpRxIndicationFctPtrUsedOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_TpStartOfReceptionFctPtrIdxOfRxTxPduInfoType, LDCOM_CODE) LdCom_GetTpStartOfReceptionFctPtrIdxOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_TpStartOfReceptionFctPtrUsedOfRxTxPduInfoType, LDCOM_CODE) LdCom_IsTpStartOfReceptionFctPtrUsedOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_TpTxConfirmationFctPtrIdxOfRxTxPduInfoType, LDCOM_CODE) LdCom_GetTpTxConfirmationFctPtrIdxOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_TpCopyRxDataFctPtrType, LDCOM_CODE) LdCom_GetTpCopyRxDataFctPtr(LdCom_TpCopyRxDataFctPtrIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_TpCopyTxDataFctPtrType, LDCOM_CODE) LdCom_GetTpCopyTxDataFctPtr(LdCom_TpCopyTxDataFctPtrIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_TpRxIndicationFctPtrType, LDCOM_CODE) LdCom_GetTpRxIndicationFctPtr(LdCom_TpRxIndicationFctPtrIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_TpStartOfReceptionFctPtrType, LDCOM_CODE) LdCom_GetTpStartOfReceptionFctPtr(LdCom_TpStartOfReceptionFctPtrIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_TpTxConfirmationFctPtrType, LDCOM_CODE) LdCom_GetTpTxConfirmationFctPtr(LdCom_TpTxConfirmationFctPtrIterType Index);
/** 
  \}
*/ 

#define LDCOM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define LDCOM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  LdComPCGetDeduplicatedInlineFunctionPrototypes  Get Deduplicated Inline Function Prototypes
  \brief  These inline functions  can be used to read deduplicated data elements.
  \{
*/ 
LDCOM_LOCAL_INLINE FUNC(LdCom_FinalMagicNumberType, LDCOM_CODE) LdCom_GetFinalMagicNumber(void);
LDCOM_LOCAL_INLINE FUNC(LdCom_InitDataHashCodeType, LDCOM_CODE) LdCom_GetInitDataHashCode(void);
LDCOM_LOCAL_INLINE FUNC(LdCom_IfPduOfRxTxPduInfoType, LDCOM_CODE) LdCom_IsIfPduOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_IfRxIndicationFctPtrUsedOfRxTxPduInfoType, LDCOM_CODE) LdCom_IsIfRxIndicationFctPtrUsedOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_TpCopyTxDataFctPtrUsedOfRxTxPduInfoType, LDCOM_CODE) LdCom_IsTpCopyTxDataFctPtrUsedOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_TpTxConfirmationFctPtrUsedOfRxTxPduInfoType, LDCOM_CODE) LdCom_IsTpTxConfirmationFctPtrUsedOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index);
LDCOM_LOCAL_INLINE FUNC(LdCom_TxPduOfRxTxPduInfoType, LDCOM_CODE) LdCom_IsTxPduOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index);
/** 
  \}
*/ 

#define LDCOM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define LDCOM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  LdComPCSetDataInlineFunctionPrototypes  Set Data Inline Function Prototypes
  \brief  These inline functions can be used to write data.
  \{
*/ 
LDCOM_LOCAL_INLINE FUNC(void, LDCOM_CODE) LdCom_SetInitialized(LdCom_InitializedType Value);
/** 
  \}
*/ 

#define LDCOM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define LDCOM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  LdComPCHasInlineFunctionPrototypes  Has Inline Function Prototypes
  \brief  These inline functions can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasFinalMagicNumber(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfRxIndicationFctPtr(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfTxConfirmationFctPtr(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfTxTriggerTransmitFctPtr(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasInitDataHashCode(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasInitialized(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasRxTxPduInfo(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfPduOfRxTxPduInfo(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfRxIndicationFctPtrIdxOfRxTxPduInfo(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfRxIndicationFctPtrUsedOfRxTxPduInfo(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfTxConfirmationFctPtrIdxOfRxTxPduInfo(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfTxConfirmationFctPtrUsedOfRxTxPduInfo(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfTxTriggerTransmitFctPtrIdxOfRxTxPduInfo(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfTxTriggerTransmitFctPtrUsedOfRxTxPduInfo(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasInvalidHndOfRxTxPduInfo(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasPduRTxHandleIdOfRxTxPduInfo(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpCopyRxDataFctPtrIdxOfRxTxPduInfo(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpCopyRxDataFctPtrUsedOfRxTxPduInfo(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpCopyTxDataFctPtrIdxOfRxTxPduInfo(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpCopyTxDataFctPtrUsedOfRxTxPduInfo(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpRxIndicationFctPtrIdxOfRxTxPduInfo(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpRxIndicationFctPtrUsedOfRxTxPduInfo(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpStartOfReceptionFctPtrIdxOfRxTxPduInfo(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpStartOfReceptionFctPtrUsedOfRxTxPduInfo(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpTxConfirmationFctPtrIdxOfRxTxPduInfo(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpTxConfirmationFctPtrUsedOfRxTxPduInfo(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTxPduOfRxTxPduInfo(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfIfRxIndicationFctPtr(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfIfTxConfirmationFctPtr(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfIfTxTriggerTransmitFctPtr(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfRxTxPduInfo(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfTpCopyRxDataFctPtr(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfTpCopyTxDataFctPtr(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfTpRxIndicationFctPtr(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfTpStartOfReceptionFctPtr(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfTpTxConfirmationFctPtr(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpCopyRxDataFctPtr(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpCopyTxDataFctPtr(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpRxIndicationFctPtr(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpStartOfReceptionFctPtr(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpTxConfirmationFctPtr(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasPCConfig(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasFinalMagicNumberOfPCConfig(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfRxIndicationFctPtrOfPCConfig(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfTxConfirmationFctPtrOfPCConfig(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfTxTriggerTransmitFctPtrOfPCConfig(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasInitDataHashCodeOfPCConfig(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasInitializedOfPCConfig(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasRxTxPduInfoOfPCConfig(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfIfRxIndicationFctPtrOfPCConfig(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfIfTxConfirmationFctPtrOfPCConfig(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfIfTxTriggerTransmitFctPtrOfPCConfig(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfRxTxPduInfoOfPCConfig(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfTpCopyRxDataFctPtrOfPCConfig(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfTpCopyTxDataFctPtrOfPCConfig(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfTpRxIndicationFctPtrOfPCConfig(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfTpStartOfReceptionFctPtrOfPCConfig(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfTpTxConfirmationFctPtrOfPCConfig(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpCopyRxDataFctPtrOfPCConfig(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpCopyTxDataFctPtrOfPCConfig(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpRxIndicationFctPtrOfPCConfig(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpStartOfReceptionFctPtrOfPCConfig(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpTxConfirmationFctPtrOfPCConfig(void);
/** 
  \}
*/ 

#define LDCOM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL SIZEOF INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define LDCOM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  LdComLTHasInlineFunctionPrototypes  Has Inline Function Prototypes
  \brief  These inline functions can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasLTConfig(void);
/** 
  \}
*/ 

#define LDCOM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIZEOF INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define LDCOM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  LdComPBHasInlineFunctionPrototypes  Has Inline Function Prototypes
  \brief  These inline functions can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasPBConfig(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasLTConfigIdxOfPBConfig(void);
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasPCConfigIdxOfPBConfig(void);
/** 
  \}
*/ 

#define LDCOM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/
#define LDCOM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  LdComPCSizeOfInlineFunctions  LdCom SizeOf Inline Functions (PRE_COMPILE)
  \brief  These inline functions are used to get SizeOf data.
  \{
*/ 
LDCOM_LOCAL_INLINE FUNC(LdCom_SizeOfIfRxIndicationFctPtrType, LDCOM_CODE) LdCom_GetSizeOfIfRxIndicationFctPtr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (LdCom_SizeOfIfRxIndicationFctPtrType) LdCom_GetSizeOfIfRxIndicationFctPtrOfPCConfig();
}
LDCOM_LOCAL_INLINE FUNC(LdCom_SizeOfIfTxConfirmationFctPtrType, LDCOM_CODE) LdCom_GetSizeOfIfTxConfirmationFctPtr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (LdCom_SizeOfIfTxConfirmationFctPtrType) LdCom_GetSizeOfIfTxConfirmationFctPtrOfPCConfig();
}
LDCOM_LOCAL_INLINE FUNC(LdCom_SizeOfIfTxTriggerTransmitFctPtrType, LDCOM_CODE) LdCom_GetSizeOfIfTxTriggerTransmitFctPtr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (LdCom_SizeOfIfTxTriggerTransmitFctPtrType) LdCom_GetSizeOfIfTxTriggerTransmitFctPtrOfPCConfig();
}
LDCOM_LOCAL_INLINE FUNC(LdCom_SizeOfRxTxPduInfoType, LDCOM_CODE) LdCom_GetSizeOfRxTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (LdCom_SizeOfRxTxPduInfoType) LdCom_GetSizeOfRxTxPduInfoOfPCConfig();
}
LDCOM_LOCAL_INLINE FUNC(LdCom_SizeOfTpCopyRxDataFctPtrType, LDCOM_CODE) LdCom_GetSizeOfTpCopyRxDataFctPtr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (LdCom_SizeOfTpCopyRxDataFctPtrType) LdCom_GetSizeOfTpCopyRxDataFctPtrOfPCConfig();
}
LDCOM_LOCAL_INLINE FUNC(LdCom_SizeOfTpCopyTxDataFctPtrType, LDCOM_CODE) LdCom_GetSizeOfTpCopyTxDataFctPtr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (LdCom_SizeOfTpCopyTxDataFctPtrType) LdCom_GetSizeOfTpCopyTxDataFctPtrOfPCConfig();
}
LDCOM_LOCAL_INLINE FUNC(LdCom_SizeOfTpRxIndicationFctPtrType, LDCOM_CODE) LdCom_GetSizeOfTpRxIndicationFctPtr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (LdCom_SizeOfTpRxIndicationFctPtrType) LdCom_GetSizeOfTpRxIndicationFctPtrOfPCConfig();
}
LDCOM_LOCAL_INLINE FUNC(LdCom_SizeOfTpStartOfReceptionFctPtrType, LDCOM_CODE) LdCom_GetSizeOfTpStartOfReceptionFctPtr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (LdCom_SizeOfTpStartOfReceptionFctPtrType) LdCom_GetSizeOfTpStartOfReceptionFctPtrOfPCConfig();
}
LDCOM_LOCAL_INLINE FUNC(LdCom_SizeOfTpTxConfirmationFctPtrType, LDCOM_CODE) LdCom_GetSizeOfTpTxConfirmationFctPtr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (LdCom_SizeOfTpTxConfirmationFctPtrType) LdCom_GetSizeOfTpTxConfirmationFctPtrOfPCConfig();
}
/** 
  \}
*/ 

#define LDCOM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define LDCOM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  LdComPCGetDataInlineFunctions  LdCom Get Data Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to read CONST and VAR data.
  \{
*/ 
LDCOM_LOCAL_INLINE FUNC(LdCom_IfRxIndicationFctPtrType, LDCOM_CODE) LdCom_GetIfRxIndicationFctPtr(LdCom_IfRxIndicationFctPtrIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_IfRxIndicationFctPtrType) (LdCom_GetIfRxIndicationFctPtrOfPCConfig()[(Index)]);
}
LDCOM_LOCAL_INLINE FUNC(LdCom_IfTxConfirmationFctPtrType, LDCOM_CODE) LdCom_GetIfTxConfirmationFctPtr(LdCom_IfTxConfirmationFctPtrIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_IfTxConfirmationFctPtrType) (NULL_PTR);
}
LDCOM_LOCAL_INLINE FUNC(LdCom_IfTxTriggerTransmitFctPtrType, LDCOM_CODE) LdCom_GetIfTxTriggerTransmitFctPtr(LdCom_IfTxTriggerTransmitFctPtrIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_IfTxTriggerTransmitFctPtrType) (NULL_PTR);
}
LDCOM_LOCAL_INLINE FUNC(LdCom_InitializedType, LDCOM_CODE) LdCom_IsInitialized(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (LdCom_InitializedType) (((*(LdCom_GetInitializedOfPCConfig()))) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(LdCom_IfRxIndicationFctPtrIdxOfRxTxPduInfoType, LDCOM_CODE) LdCom_GetIfRxIndicationFctPtrIdxOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_IfRxIndicationFctPtrIdxOfRxTxPduInfoType) (LdCom_GetRxTxPduInfoOfPCConfig()[(Index)].IfRxIndicationFctPtrIdxOfRxTxPduInfo);
}
LDCOM_LOCAL_INLINE FUNC(LdCom_IfTxConfirmationFctPtrIdxOfRxTxPduInfoType, LDCOM_CODE) LdCom_GetIfTxConfirmationFctPtrIdxOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_IfTxConfirmationFctPtrIdxOfRxTxPduInfoType) (0u);
}
LDCOM_LOCAL_INLINE FUNC(LdCom_IfTxConfirmationFctPtrUsedOfRxTxPduInfoType, LDCOM_CODE) LdCom_IsIfTxConfirmationFctPtrUsedOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_IfTxConfirmationFctPtrUsedOfRxTxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(LdCom_IfTxTriggerTransmitFctPtrIdxOfRxTxPduInfoType, LDCOM_CODE) LdCom_GetIfTxTriggerTransmitFctPtrIdxOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_IfTxTriggerTransmitFctPtrIdxOfRxTxPduInfoType) (0u);
}
LDCOM_LOCAL_INLINE FUNC(LdCom_IfTxTriggerTransmitFctPtrUsedOfRxTxPduInfoType, LDCOM_CODE) LdCom_IsIfTxTriggerTransmitFctPtrUsedOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_IfTxTriggerTransmitFctPtrUsedOfRxTxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(LdCom_InvalidHndOfRxTxPduInfoType, LDCOM_CODE) LdCom_IsInvalidHndOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_InvalidHndOfRxTxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(LdCom_PduRTxHandleIdOfRxTxPduInfoType, LDCOM_CODE) LdCom_GetPduRTxHandleIdOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_PduRTxHandleIdOfRxTxPduInfoType) (LdCom_GetRxTxPduInfoOfPCConfig()[(Index)].PduRTxHandleIdOfRxTxPduInfo);
}
LDCOM_LOCAL_INLINE FUNC(LdCom_TpCopyRxDataFctPtrIdxOfRxTxPduInfoType, LDCOM_CODE) LdCom_GetTpCopyRxDataFctPtrIdxOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_TpCopyRxDataFctPtrIdxOfRxTxPduInfoType) (0u);
}
LDCOM_LOCAL_INLINE FUNC(LdCom_TpCopyRxDataFctPtrUsedOfRxTxPduInfoType, LDCOM_CODE) LdCom_IsTpCopyRxDataFctPtrUsedOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_TpCopyRxDataFctPtrUsedOfRxTxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(LdCom_TpCopyTxDataFctPtrIdxOfRxTxPduInfoType, LDCOM_CODE) LdCom_GetTpCopyTxDataFctPtrIdxOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_TpCopyTxDataFctPtrIdxOfRxTxPduInfoType) (LdCom_GetRxTxPduInfoOfPCConfig()[(Index)].TpCopyTxDataFctPtrIdxOfRxTxPduInfo);
}
LDCOM_LOCAL_INLINE FUNC(LdCom_TpRxIndicationFctPtrIdxOfRxTxPduInfoType, LDCOM_CODE) LdCom_GetTpRxIndicationFctPtrIdxOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_TpRxIndicationFctPtrIdxOfRxTxPduInfoType) (0u);
}
LDCOM_LOCAL_INLINE FUNC(LdCom_TpRxIndicationFctPtrUsedOfRxTxPduInfoType, LDCOM_CODE) LdCom_IsTpRxIndicationFctPtrUsedOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_TpRxIndicationFctPtrUsedOfRxTxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(LdCom_TpStartOfReceptionFctPtrIdxOfRxTxPduInfoType, LDCOM_CODE) LdCom_GetTpStartOfReceptionFctPtrIdxOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_TpStartOfReceptionFctPtrIdxOfRxTxPduInfoType) (0u);
}
LDCOM_LOCAL_INLINE FUNC(LdCom_TpStartOfReceptionFctPtrUsedOfRxTxPduInfoType, LDCOM_CODE) LdCom_IsTpStartOfReceptionFctPtrUsedOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_TpStartOfReceptionFctPtrUsedOfRxTxPduInfoType) ((FALSE) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(LdCom_TpTxConfirmationFctPtrIdxOfRxTxPduInfoType, LDCOM_CODE) LdCom_GetTpTxConfirmationFctPtrIdxOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_TpTxConfirmationFctPtrIdxOfRxTxPduInfoType) (LdCom_GetRxTxPduInfoOfPCConfig()[(Index)].TpTxConfirmationFctPtrIdxOfRxTxPduInfo);
}
LDCOM_LOCAL_INLINE FUNC(LdCom_TpCopyRxDataFctPtrType, LDCOM_CODE) LdCom_GetTpCopyRxDataFctPtr(LdCom_TpCopyRxDataFctPtrIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_TpCopyRxDataFctPtrType) (NULL_PTR);
}
LDCOM_LOCAL_INLINE FUNC(LdCom_TpCopyTxDataFctPtrType, LDCOM_CODE) LdCom_GetTpCopyTxDataFctPtr(LdCom_TpCopyTxDataFctPtrIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_TpCopyTxDataFctPtrType) (LdCom_GetTpCopyTxDataFctPtrOfPCConfig()[(Index)]);
}
LDCOM_LOCAL_INLINE FUNC(LdCom_TpRxIndicationFctPtrType, LDCOM_CODE) LdCom_GetTpRxIndicationFctPtr(LdCom_TpRxIndicationFctPtrIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_TpRxIndicationFctPtrType) (NULL_PTR);
}
LDCOM_LOCAL_INLINE FUNC(LdCom_TpStartOfReceptionFctPtrType, LDCOM_CODE) LdCom_GetTpStartOfReceptionFctPtr(LdCom_TpStartOfReceptionFctPtrIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_TpStartOfReceptionFctPtrType) (NULL_PTR);
}
LDCOM_LOCAL_INLINE FUNC(LdCom_TpTxConfirmationFctPtrType, LDCOM_CODE) LdCom_GetTpTxConfirmationFctPtr(LdCom_TpTxConfirmationFctPtrIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_TpTxConfirmationFctPtrType) (LdCom_GetTpTxConfirmationFctPtrOfPCConfig()[(Index)]);
}
/** 
  \}
*/ 

#define LDCOM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define LDCOM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  LdComPCGetDeduplicatedInlineFunctions  LdCom Get Deduplicated Inline Functions (PRE_COMPILE)
  \brief  These inline functions  can be used to read deduplicated data elements.
  \{
*/ 
LDCOM_LOCAL_INLINE FUNC(LdCom_FinalMagicNumberType, LDCOM_CODE) LdCom_GetFinalMagicNumber(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (LdCom_FinalMagicNumberType) LdCom_GetFinalMagicNumberOfPCConfig();
}
LDCOM_LOCAL_INLINE FUNC(LdCom_InitDataHashCodeType, LDCOM_CODE) LdCom_GetInitDataHashCode(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (LdCom_InitDataHashCodeType) LdCom_GetInitDataHashCodeOfPCConfig();
}
LDCOM_LOCAL_INLINE FUNC(LdCom_IfPduOfRxTxPduInfoType, LDCOM_CODE) LdCom_IsIfPduOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_IfPduOfRxTxPduInfoType) (((boolean)(LdCom_GetTpCopyTxDataFctPtrIdxOfRxTxPduInfo(Index) > 0u)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(LdCom_IfRxIndicationFctPtrUsedOfRxTxPduInfoType, LDCOM_CODE) LdCom_IsIfRxIndicationFctPtrUsedOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_IfRxIndicationFctPtrUsedOfRxTxPduInfoType) (((boolean)(LdCom_GetIfRxIndicationFctPtrIdxOfRxTxPduInfo(Index) != LDCOM_NO_IFRXINDICATIONFCTPTRIDXOFRXTXPDUINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(LdCom_TpCopyTxDataFctPtrUsedOfRxTxPduInfoType, LDCOM_CODE) LdCom_IsTpCopyTxDataFctPtrUsedOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_TpCopyTxDataFctPtrUsedOfRxTxPduInfoType) (((boolean)(LdCom_GetTpCopyTxDataFctPtrIdxOfRxTxPduInfo(Index) != LDCOM_NO_TPCOPYTXDATAFCTPTRIDXOFRXTXPDUINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(LdCom_TpTxConfirmationFctPtrUsedOfRxTxPduInfoType, LDCOM_CODE) LdCom_IsTpTxConfirmationFctPtrUsedOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_TpTxConfirmationFctPtrUsedOfRxTxPduInfoType) (((boolean)(LdCom_GetTpTxConfirmationFctPtrIdxOfRxTxPduInfo(Index) != LDCOM_NO_TPTXCONFIRMATIONFCTPTRIDXOFRXTXPDUINFO)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(LdCom_TxPduOfRxTxPduInfoType, LDCOM_CODE) LdCom_IsTxPduOfRxTxPduInfo(LdCom_RxTxPduInfoIterType Index)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  LDCOM_DUMMY_STATEMENT(Index);  /* PRQA S 3112, 1338, 2983 */  /* MD_MSR_DummyStmt */       /* lint -e{438} */
  return (LdCom_TxPduOfRxTxPduInfoType) (((boolean)(LdCom_GetPduRTxHandleIdOfRxTxPduInfo(Index) != 0u)) != FALSE);  /* PRQA S 2995, 2996 */  /* MD_MSR_ConstantCondition */
}
/** 
  \}
*/ 

#define LDCOM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define LDCOM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  LdComPCSetDataInlineFunctions  LdCom Set Data Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to write data.
  \{
*/ 
LDCOM_LOCAL_INLINE FUNC(void, LDCOM_CODE) LdCom_SetInitialized(LdCom_InitializedType Value)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  (*(LdCom_GetInitializedOfPCConfig())) = (Value);
}
/** 
  \}
*/ 

#define LDCOM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

#define LDCOM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  LdComPCHasInlineFunctions  LdCom Has Inline Functions (PRE_COMPILE)
  \brief  These inline functions can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasFinalMagicNumber(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfRxIndicationFctPtr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfTxConfirmationFctPtr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfTxTriggerTransmitFctPtr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasInitDataHashCode(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasInitialized(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasRxTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfPduOfRxTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfRxIndicationFctPtrIdxOfRxTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfRxIndicationFctPtrUsedOfRxTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfTxConfirmationFctPtrIdxOfRxTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfTxConfirmationFctPtrUsedOfRxTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfTxTriggerTransmitFctPtrIdxOfRxTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfTxTriggerTransmitFctPtrUsedOfRxTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasInvalidHndOfRxTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasPduRTxHandleIdOfRxTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpCopyRxDataFctPtrIdxOfRxTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpCopyRxDataFctPtrUsedOfRxTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpCopyTxDataFctPtrIdxOfRxTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpCopyTxDataFctPtrUsedOfRxTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpRxIndicationFctPtrIdxOfRxTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpRxIndicationFctPtrUsedOfRxTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpStartOfReceptionFctPtrIdxOfRxTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpStartOfReceptionFctPtrUsedOfRxTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpTxConfirmationFctPtrIdxOfRxTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpTxConfirmationFctPtrUsedOfRxTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTxPduOfRxTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfIfRxIndicationFctPtr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfIfTxConfirmationFctPtr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfIfTxTriggerTransmitFctPtr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfRxTxPduInfo(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfTpCopyRxDataFctPtr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfTpCopyTxDataFctPtr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfTpRxIndicationFctPtr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfTpStartOfReceptionFctPtr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfTpTxConfirmationFctPtr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpCopyRxDataFctPtr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpCopyTxDataFctPtr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpRxIndicationFctPtr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpStartOfReceptionFctPtr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpTxConfirmationFctPtr(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasFinalMagicNumberOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfRxIndicationFctPtrOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfTxConfirmationFctPtrOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasIfTxTriggerTransmitFctPtrOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasInitDataHashCodeOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasInitializedOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasRxTxPduInfoOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfIfRxIndicationFctPtrOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfIfTxConfirmationFctPtrOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfIfTxTriggerTransmitFctPtrOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfRxTxPduInfoOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfTpCopyRxDataFctPtrOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfTpCopyTxDataFctPtrOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfTpRxIndicationFctPtrOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfTpStartOfReceptionFctPtrOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasSizeOfTpTxConfirmationFctPtrOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpCopyRxDataFctPtrOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpCopyTxDataFctPtrOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpRxIndicationFctPtrOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpStartOfReceptionFctPtrOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasTpTxConfirmationFctPtrOfPCConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (TRUE != FALSE);   /* PRQA S 2995 */  /* MD_MSR_ConstantCondition */
}
/** 
  \}
*/ 

#define LDCOM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/
#define LDCOM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  LdComLTHasInlineFunctions  LdCom Has Inline Functions (LINK)
  \brief  These inline functions can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasLTConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
/** 
  \}
*/ 

#define LDCOM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/
#define LDCOM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/** 
  \defgroup  LdComPBHasInlineFunctions  LdCom Has Inline Functions (POST_BUILD)
  \brief  These inline functions can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasPBConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasLTConfigIdxOfPBConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
LDCOM_LOCAL_INLINE FUNC(boolean, LDCOM_CODE) LdCom_HasPCConfigIdxOfPBConfig(void)  /* PRQA S 3219 */  /* MD_MSR_Unreachable */
{
  return (boolean) (FALSE != FALSE);   /* PRQA S 2996 */  /* MD_MSR_ConstantCondition */
}
/** 
  \}
*/ 

#define LDCOM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "LdCom_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */




#endif  /* LDCOM_LCFG_H */
/**********************************************************************************************************************
 *  END OF FILE: LdCom_Lcfg.h
 *********************************************************************************************************************/
