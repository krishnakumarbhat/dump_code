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
 *            Module: CryIf
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CryIf_Cfg.h
 *   Generation Time: 2026-08-11 12:06:40
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

#if !defined (CRYIF_CFG_H)
#define CRYIF_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Crypto_GeneralTypes.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef CRYIF_USE_DUMMY_STATEMENT
#define CRYIF_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CRYIF_DUMMY_STATEMENT
#define CRYIF_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CRYIF_DUMMY_STATEMENT_CONST
#define CRYIF_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CRYIF_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CRYIF_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CRYIF_ATOMIC_VARIABLE_ACCESS
#define CRYIF_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CRYIF_PROCESSOR_IND13400
#define CRYIF_PROCESSOR_IND13400
#endif
#ifndef CRYIF_COMP_LLVMDIAB
#define CRYIF_COMP_LLVMDIAB
#endif
#ifndef CRYIF_GEN_GENERATOR_MSR
#define CRYIF_GEN_GENERATOR_MSR
#endif
#ifndef CRYIF_CPUTYPE_BITORDER_LSB2MSB
#define CRYIF_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CRYIF_CONFIGURATION_VARIANT_PRECOMPILE
#define CRYIF_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CRYIF_CONFIGURATION_VARIANT_LINKTIME
#define CRYIF_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CRYIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CRYIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CRYIF_CONFIGURATION_VARIANT
#define CRYIF_CONFIGURATION_VARIANT CRYIF_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CRYIF_POSTBUILD_VARIANT_SUPPORT
#define CRYIF_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* Module version information */
#define CRYIF_CFG_MAJOR_VERSION                                                                     9u
#define CRYIF_CFG_MINOR_VERSION                                                                     1u
#define CRYIF_CFG_PATCH_VERSION                                                                     0u
#define CRYIF_GENERATOR_MAJOR_VERSION                                                               9u
#define CRYIF_GENERATOR_MINOR_VERSION                                                               1u
#define CRYIF_GENERATOR_PATCH_VERSION                                                               0u

/* Defines for general parameters of type boolean, integer and enumeration */
#define CRYIF_VERSION_INFO_API                                                                      STD_OFF 
#define CRYIF_MAX_NUMBER_OF_KEY_ELEMENTS                                                            10u 
#define CRYIF_MAX_SIZE_OF_KEY_ELEMENT                                                               32u 
#define CRYIF_REDIRECTION                                                                           STD_OFF 

/* Symbolic Name Define Block */
#define CryIfConf_CryIfChannel_CryIfChannel_Crypto_PublicKeyObject                                  0u 
#define CryIfConf_CryIfChannel_CryIfChannel_Crypto_AESDriverObject                                  1u 
#define CryIfConf_CryIfChannel_CryIfChannel_Crypto_HashDriverObject                                 2u 
#define CryIfConf_CryIfChannel_CryIfChannel_MKA                                                     3u 
#define CryIfConf_CryIfKey_CryIfKey_Boot_MAC                                                        0u 
#define CryIfConf_CryIfKey_CryIfKey_Boot_MAC_Key                                                    1u 
#define CryIfConf_CryIfKey_CryIfKey_Crypto_AES_128                                                  2u 
#define CryIfConf_CryIfKey_CryIfKey_Crypto_AES_256                                                  3u 
#define CryIfConf_CryIfKey_CryIfKey_Crypto_Hash                                                     4u 
#define CryIfConf_CryIfKey_CryIfKey_Crypto_RNG                                                      5u 
#define CryIfConf_CryIfKey_CryIfKey_Crypto_RSA_1024_Key                                             6u 
#define CryIfConf_CryIfKey_CryIfKey_Crypto_RSA_2048_Key                                             7u 
#define CryIfConf_CryIfKey_CryIfKey_Crypto_RSA_3072_Key                                             8u 
#define CryIfConf_CryIfKey_CryIfKey_Crypto_RSA_4096_Key                                             9u 
#define CryIfConf_CryIfKey_CryIfKey_Custom_Operations                                               10u 
#define CryIfConf_CryIfKey_CryIfKey_ECC_192_Key_SigGenerate                                         11u 
#define CryIfConf_CryIfKey_CryIfKey_ECC_192_Key_SigVerify                                           12u 
#define CryIfConf_CryIfKey_CryIfKey_ECC_224_Key_SigGenerate                                         13u 
#define CryIfConf_CryIfKey_CryIfKey_ECC_224_Key_SigVerify                                           14u 
#define CryIfConf_CryIfKey_CryIfKey_ECC_224_Key_Exchange                                            15u 
#define CryIfConf_CryIfKey_CryIfKey_ECC_256_Key_Generate                                            16u 
#define CryIfConf_CryIfKey_CryIfKey_ECC_256_Key_Generate_2                                          17u 
#define CryIfConf_CryIfKey_CryIfKey_ECC_256_Key_SigGenerate                                         18u 
#define CryIfConf_CryIfKey_CryIfKey_ECC_256_Key_SigVerify                                           19u 
#define CryIfConf_CryIfKey_CryIfKey_ECC_320_Key_SigGenerate                                         20u 
#define CryIfConf_CryIfKey_CryIfKey_ECC_320_Key_SigVerify                                           21u 
#define CryIfConf_CryIfKey_CryIfKey_ECC_384_Key_SigGenerate                                         22u 
#define CryIfConf_CryIfKey_CryIfKey_ECC_384_Key_SigVerify                                           23u 
#define CryIfConf_CryIfKey_CryIfKey_ECC_512_Key_SigGenerate                                         24u 
#define CryIfConf_CryIfKey_CryIfKey_ECC_512_Key_SigVerify                                           25u 
#define CryIfConf_CryIfKey_CryIfKey_ECC_521_Key_SigGenerate                                         26u 
#define CryIfConf_CryIfKey_CryIfKey_ECC_521_Key_SigVerify                                           27u 
#define CryIfConf_CryIfKey_CryIfKey_ECDH_128_Key_SigGenerate                                        28u 
#define CryIfConf_CryIfKey_CryIfKey_ECDH_128_Key_SigVerify                                          29u 
#define CryIfConf_CryIfKey_CryIfKey_ECDH_224_Key_SigGenerate                                        30u 
#define CryIfConf_CryIfKey_CryIfKey_ECDH_224_Key_SigVerify                                          31u 
#define CryIfConf_CryIfKey_CryIfKey_ECDH_256_Key_SigGenerate                                        32u 
#define CryIfConf_CryIfKey_CryIfKey_ECDH_256_Key_SigVerify                                          33u 
#define CryIfConf_CryIfKey_CryIfKey_ECDH_384_Key_SigGenerate                                        34u 
#define CryIfConf_CryIfKey_CryIfKey_ECDH_384_Key_SigVerify                                          35u 
#define CryIfConf_CryIfKey_CryIfKey_ECDH_512_Key_SigGenerate                                        36u 
#define CryIfConf_CryIfKey_CryIfKey_ECDH_512_Key_SigVerify                                          37u 
#define CryIfConf_CryIfKey_CryIfKey_ED448_Key_SigGenerate                                           38u 
#define CryIfConf_CryIfKey_CryIfKey_ED448_Key_SigVerify                                             39u 
#define CryIfConf_CryIfKey_CryIfKey_ED25519_Key_SigGenerate                                         40u 
#define CryIfConf_CryIfKey_CryIfKey_ED25519_Key_SigVerify                                           41u 
#define CryIfConf_CryIfKey_CryIfKey_MKA_CAK                                                         42u 
#define CryIfConf_CryIfKey_CryIfKey_MKA_ICK                                                         43u 
#define CryIfConf_CryIfKey_CryIfKey_MKA_KEK                                                         44u 
#define CryIfConf_CryIfKey_CryIfKey_MKA_MAC                                                         45u 
#define CryIfConf_CryIfKey_CryIfKey_MKA_Random                                                      46u 
#define CryIfConf_CryIfKey_CryIfKey_MKA_SAK                                                         47u 
#define CryIfConf_CryIfKey_CryIfKey_MKA_SAK_Data                                                    48u 
#define CryIfConf_CryIfKey_CryIfKey_Master_ECU_Key                                                  49u 
#define CryIfConf_CryIfKey_CryIfKey_Monotonic_Counter                                               50u 
#define CryIfConf_CryIfKey_CryIfKey_SHE_KEY_1                                                       51u 
#define CryIfConf_CryIfKey_CryIfKey_SHE_KEY_2                                                       52u 
#define CryIfConf_CryIfKey_CryIfKey_SHE_KEY_3                                                       53u 
#define CryIfConf_CryIfKey_CryIfKey_SHE_KEY_4                                                       54u 
#define CryIfConf_CryIfKey_CryIfKey_SHE_KEY_5                                                       55u 
#define CryIfConf_CryIfKey_CryIfKey_SHE_KEY_6                                                       56u 
#define CryIfConf_CryIfKey_CryIfKey_SHE_KEY_7                                                       57u 
#define CryIfConf_CryIfKey_CryIfKey_SHE_KEY_8                                                       58u 
#define CryIfConf_CryIfKey_CryIfKey_SHE_KEY_9                                                       59u 
#define CryIfConf_CryIfKey_CryIfKey_SHE_KEY_10                                                      60u 
#define CryIfConf_CryIfKey_CryIfKey_SHE_RAM_KEY                                                     61u 

#ifndef CRYIF_DEV_ERROR_DETECT
#define CRYIF_DEV_ERROR_DETECT STD_ON
#endif
#ifndef CRYIF_DEV_ERROR_REPORT
#define CRYIF_DEV_ERROR_REPORT STD_ON
#endif


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CryIfPCDataSwitches  CryIf Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CRYIF_CHANNEL                                                                               STD_ON
#define CRYIF_CRYPTOFUNCTIONSIDXOFCHANNEL                                                           STD_ON
#define CRYIF_DRIVEROBJECTREFOFCHANNEL                                                              STD_ON
#define CRYIF_IDOFCHANNEL                                                                           STD_ON
#define CRYIF_CRYPTOFUNCTIONS                                                                       STD_ON
#define CRYIF_CANCELJOBOFCRYPTOFUNCTIONS                                                            STD_ON
#define CRYIF_CANCELJOBWITHINFOTYPEOFCRYPTOFUNCTIONS                                                STD_OFF  /**< Deactivateable: 'CryIf_CryptoFunctions.CancelJobWithInfoType' Reason: 'No Module with JobCancel using JobInfoType is configured' */
#define CRYIF_CERTIFICATEPARSEOFCRYPTOFUNCTIONS                                                     STD_ON
#define CRYIF_CERTIFICATEVERIFYOFCRYPTOFUNCTIONS                                                    STD_ON
#define CRYIF_CUSTOMSYNCOFCRYPTOFUNCTIONS                                                           STD_ON
#define CRYIF_KEYCOPYOFCRYPTOFUNCTIONS                                                              STD_ON
#define CRYIF_KEYDERIVEOFCRYPTOFUNCTIONS                                                            STD_ON
#define CRYIF_KEYELEMENTCOPYOFCRYPTOFUNCTIONS                                                       STD_ON
#define CRYIF_KEYELEMENTCOPYPARTIALOFCRYPTOFUNCTIONS                                                STD_ON
#define CRYIF_KEYELEMENTGETOFCRYPTOFUNCTIONS                                                        STD_ON
#define CRYIF_KEYELEMENTIDSGETOFCRYPTOFUNCTIONS                                                     STD_ON
#define CRYIF_KEYELEMENTSETOFCRYPTOFUNCTIONS                                                        STD_ON
#define CRYIF_KEYEXCHANGECALCPUBVALOFCRYPTOFUNCTIONS                                                STD_ON
#define CRYIF_KEYEXCHANGECALCSECRETOFCRYPTOFUNCTIONS                                                STD_ON
#define CRYIF_KEYGENERATEOFCRYPTOFUNCTIONS                                                          STD_ON
#define CRYIF_KEYGETSTATUSOFCRYPTOFUNCTIONS                                                         STD_ON
#define CRYIF_KEYSETINVALIDOFCRYPTOFUNCTIONS                                                        STD_ON
#define CRYIF_KEYVALIDSETOFCRYPTOFUNCTIONS                                                          STD_ON
#define CRYIF_PROCESSJOBOFCRYPTOFUNCTIONS                                                           STD_ON
#define CRYIF_RANDOMSEEDOFCRYPTOFUNCTIONS                                                           STD_ON
#define CRYIF_SUPPORTSKEYELEMENTCOPYPARTIALOFCRYPTOFUNCTIONS                                        STD_ON
#define CRYIF_EXPECTEDCOMPATIBILITYVERSION                                                          STD_OFF  /**< Deactivateable: 'CryIf_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYIF_FINALMAGICNUMBER                                                                      STD_OFF  /**< Deactivateable: 'CryIf_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CRYIF_GENERATORCOMPATIBILITYVERSION                                                         STD_OFF  /**< Deactivateable: 'CryIf_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYIF_INITDATAHASHCODE                                                                      STD_OFF  /**< Deactivateable: 'CryIf_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CRYIF_KEY                                                                                   STD_ON
#define CRYIF_CRYPTOFUNCTIONSIDXOFKEY                                                               STD_ON
#define CRYIF_REFOFKEY                                                                              STD_ON
#define CRYIF_MAXNUMBEROFKEYELEMENTSOFGENERAL                                                       STD_ON
#define CRYIF_MAXSIZEOFKEYELEMENTOFGENERAL                                                          STD_ON
#define CRYIF_REDIRECTIONOFGENERAL                                                                  STD_ON
#define CRYIF_SIZEOFCHANNEL                                                                         STD_ON
#define CRYIF_SIZEOFCRYPTOFUNCTIONS                                                                 STD_ON
#define CRYIF_SIZEOFKEY                                                                             STD_ON
#define CRYIF_VERSIONINFOAPIOFGENERAL                                                               STD_ON
#define CRYIF_PCCONFIG                                                                              STD_ON
#define CRYIF_CHANNELOFPCCONFIG                                                                     STD_ON
#define CRYIF_CRYPTOFUNCTIONSOFPCCONFIG                                                             STD_ON
#define CRYIF_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                                STD_OFF  /**< Deactivateable: 'CryIf_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYIF_FINALMAGICNUMBEROFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'CryIf_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CRYIF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                               STD_OFF  /**< Deactivateable: 'CryIf_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYIF_INITDATAHASHCODEOFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'CryIf_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CRYIF_KEYOFPCCONFIG                                                                         STD_ON
#define CRYIF_MAXNUMBEROFKEYELEMENTSOFGENERALOFPCCONFIG                                             STD_ON
#define CRYIF_MAXSIZEOFKEYELEMENTOFGENERALOFPCCONFIG                                                STD_ON
#define CRYIF_REDIRECTIONOFGENERALOFPCCONFIG                                                        STD_ON
#define CRYIF_SIZEOFCHANNELOFPCCONFIG                                                               STD_ON
#define CRYIF_SIZEOFCRYPTOFUNCTIONSOFPCCONFIG                                                       STD_ON
#define CRYIF_SIZEOFKEYOFPCCONFIG                                                                   STD_ON
#define CRYIF_VERSIONINFOAPIOFGENERALOFPCCONFIG                                                     STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CryIfPCNoReferenceDefines  CryIf No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define CRYIF_NO_EXPECTEDCOMPATIBILITYVERSION                                                       65535u
/** 
  \}
*/ 

/** 
  \defgroup  CryIfPCIsReducedToDefineDefines  CryIf Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CRYIF_ISDEF_CRYPTOFUNCTIONSIDXOFCHANNEL                                                     STD_OFF
#define CRYIF_ISDEF_DRIVEROBJECTREFOFCHANNEL                                                        STD_OFF
#define CRYIF_ISDEF_IDOFCHANNEL                                                                     STD_OFF
#define CRYIF_ISDEF_CANCELJOBOFCRYPTOFUNCTIONS                                                      STD_OFF
#define CRYIF_ISDEF_CANCELJOBWITHINFOTYPEOFCRYPTOFUNCTIONS                                          STD_OFF
#define CRYIF_ISDEF_CERTIFICATEPARSEOFCRYPTOFUNCTIONS                                               STD_OFF
#define CRYIF_ISDEF_CERTIFICATEVERIFYOFCRYPTOFUNCTIONS                                              STD_OFF
#define CRYIF_ISDEF_CUSTOMSYNCOFCRYPTOFUNCTIONS                                                     STD_OFF
#define CRYIF_ISDEF_KEYCOPYOFCRYPTOFUNCTIONS                                                        STD_OFF
#define CRYIF_ISDEF_KEYDERIVEOFCRYPTOFUNCTIONS                                                      STD_OFF
#define CRYIF_ISDEF_KEYELEMENTCOPYOFCRYPTOFUNCTIONS                                                 STD_OFF
#define CRYIF_ISDEF_KEYELEMENTCOPYPARTIALOFCRYPTOFUNCTIONS                                          STD_OFF
#define CRYIF_ISDEF_KEYELEMENTGETOFCRYPTOFUNCTIONS                                                  STD_OFF
#define CRYIF_ISDEF_KEYELEMENTIDSGETOFCRYPTOFUNCTIONS                                               STD_OFF
#define CRYIF_ISDEF_KEYELEMENTSETOFCRYPTOFUNCTIONS                                                  STD_OFF
#define CRYIF_ISDEF_KEYEXCHANGECALCPUBVALOFCRYPTOFUNCTIONS                                          STD_OFF
#define CRYIF_ISDEF_KEYEXCHANGECALCSECRETOFCRYPTOFUNCTIONS                                          STD_OFF
#define CRYIF_ISDEF_KEYGENERATEOFCRYPTOFUNCTIONS                                                    STD_OFF
#define CRYIF_ISDEF_KEYGETSTATUSOFCRYPTOFUNCTIONS                                                   STD_OFF
#define CRYIF_ISDEF_KEYSETINVALIDOFCRYPTOFUNCTIONS                                                  STD_OFF
#define CRYIF_ISDEF_KEYVALIDSETOFCRYPTOFUNCTIONS                                                    STD_OFF
#define CRYIF_ISDEF_PROCESSJOBOFCRYPTOFUNCTIONS                                                     STD_OFF
#define CRYIF_ISDEF_RANDOMSEEDOFCRYPTOFUNCTIONS                                                     STD_OFF
#define CRYIF_ISDEF_SUPPORTSKEYELEMENTCOPYPARTIALOFCRYPTOFUNCTIONS                                  STD_OFF
#define CRYIF_ISDEF_CRYPTOFUNCTIONSIDXOFKEY                                                         STD_OFF
#define CRYIF_ISDEF_REFOFKEY                                                                        STD_OFF
#define CRYIF_ISDEF_CHANNELOFPCCONFIG                                                               STD_ON
#define CRYIF_ISDEF_CRYPTOFUNCTIONSOFPCCONFIG                                                       STD_ON
#define CRYIF_ISDEF_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                          STD_OFF
#define CRYIF_ISDEF_FINALMAGICNUMBEROFPCCONFIG                                                      STD_OFF
#define CRYIF_ISDEF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                         STD_OFF
#define CRYIF_ISDEF_INITDATAHASHCODEOFPCCONFIG                                                      STD_OFF
#define CRYIF_ISDEF_KEYOFPCCONFIG                                                                   STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CryIfPCEqualsAlwaysToDefines  CryIf Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CRYIF_EQ2_CRYPTOFUNCTIONSIDXOFCHANNEL                                                       
#define CRYIF_EQ2_DRIVEROBJECTREFOFCHANNEL                                                          
#define CRYIF_EQ2_IDOFCHANNEL                                                                       
#define CRYIF_EQ2_CANCELJOBOFCRYPTOFUNCTIONS                                                        
#define CRYIF_EQ2_CANCELJOBWITHINFOTYPEOFCRYPTOFUNCTIONS                                            
#define CRYIF_EQ2_CERTIFICATEPARSEOFCRYPTOFUNCTIONS                                                 
#define CRYIF_EQ2_CERTIFICATEVERIFYOFCRYPTOFUNCTIONS                                                
#define CRYIF_EQ2_CUSTOMSYNCOFCRYPTOFUNCTIONS                                                       
#define CRYIF_EQ2_KEYCOPYOFCRYPTOFUNCTIONS                                                          
#define CRYIF_EQ2_KEYDERIVEOFCRYPTOFUNCTIONS                                                        
#define CRYIF_EQ2_KEYELEMENTCOPYOFCRYPTOFUNCTIONS                                                   
#define CRYIF_EQ2_KEYELEMENTCOPYPARTIALOFCRYPTOFUNCTIONS                                            
#define CRYIF_EQ2_KEYELEMENTGETOFCRYPTOFUNCTIONS                                                    
#define CRYIF_EQ2_KEYELEMENTIDSGETOFCRYPTOFUNCTIONS                                                 
#define CRYIF_EQ2_KEYELEMENTSETOFCRYPTOFUNCTIONS                                                    
#define CRYIF_EQ2_KEYEXCHANGECALCPUBVALOFCRYPTOFUNCTIONS                                            
#define CRYIF_EQ2_KEYEXCHANGECALCSECRETOFCRYPTOFUNCTIONS                                            
#define CRYIF_EQ2_KEYGENERATEOFCRYPTOFUNCTIONS                                                      
#define CRYIF_EQ2_KEYGETSTATUSOFCRYPTOFUNCTIONS                                                     
#define CRYIF_EQ2_KEYSETINVALIDOFCRYPTOFUNCTIONS                                                    
#define CRYIF_EQ2_KEYVALIDSETOFCRYPTOFUNCTIONS                                                      
#define CRYIF_EQ2_PROCESSJOBOFCRYPTOFUNCTIONS                                                       
#define CRYIF_EQ2_RANDOMSEEDOFCRYPTOFUNCTIONS                                                       
#define CRYIF_EQ2_SUPPORTSKEYELEMENTCOPYPARTIALOFCRYPTOFUNCTIONS                                    
#define CRYIF_EQ2_CRYPTOFUNCTIONSIDXOFKEY                                                           
#define CRYIF_EQ2_REFOFKEY                                                                          
#define CRYIF_EQ2_CHANNELOFPCCONFIG                                                                 CryIf_Channel
#define CRYIF_EQ2_CRYPTOFUNCTIONSOFPCCONFIG                                                         CryIf_CryptoFunctions
#define CRYIF_EQ2_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                            
#define CRYIF_EQ2_FINALMAGICNUMBEROFPCCONFIG                                                        
#define CRYIF_EQ2_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                           
#define CRYIF_EQ2_INITDATAHASHCODEOFPCCONFIG                                                        
#define CRYIF_EQ2_KEYOFPCCONFIG                                                                     CryIf_Key
/** 
  \}
*/ 

/** 
  \defgroup  CryIfPCSymbolicInitializationPointers  CryIf Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define CryIf_Config_Ptr                                                                            NULL_PTR  /**< symbolic identifier which shall be used to initialize 'CryIf' */
/** 
  \}
*/ 

/** 
  \defgroup  CryIfPCInitializationSymbols  CryIf Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define CryIf_Config                                                                                NULL_PTR  /**< symbolic identifier which could be used to initialize 'CryIf */
/** 
  \}
*/ 

/** 
  \defgroup  CryIfPCGeneral  CryIf General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CRYIF_CHECK_INIT_POINTER                                                                    STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CRYIF_FINAL_MAGIC_NUMBER                                                                    0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of CryIf */
#define CRYIF_INDIVIDUAL_POSTBUILD                                                                  STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'CryIf' is not configured to be postbuild capable. */
#define CRYIF_INIT_DATA                                                                             CRYIF_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CRYIF_INIT_DATA_HASH_CODE                                                                   -1579120385  /**< the precompile constant to validate the initialization structure at initialization time of CryIf with a hashcode. The seed value is '0xFF1Eu' */
#define CRYIF_USE_ECUM_BSW_ERROR_HOOK                                                               STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CRYIF_USE_INIT_POINTER                                                                      STD_OFF  /**< STD_ON if the init pointer CryIf shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CryIfPBDataSwitches  CryIf Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CRYIF_PBCONFIG                                                                              STD_OFF  /**< Deactivateable: 'CryIf_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CRYIF_LTCONFIGIDXOFPBCONFIG                                                                 STD_OFF  /**< Deactivateable: 'CryIf_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CRYIF_PCCONFIGIDXOFPBCONFIG                                                                 STD_OFF  /**< Deactivateable: 'CryIf_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  CryIfPBIsReducedToDefineDefines  CryIf Is Reduced To Define Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CRYIF_ISDEF_LTCONFIGIDXOFPBCONFIG                                                           STD_OFF
#define CRYIF_ISDEF_PCCONFIGIDXOFPBCONFIG                                                           STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  CryIfPBEqualsAlwaysToDefines  CryIf Equals Always To Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CRYIF_EQ2_LTCONFIGIDXOFPBCONFIG                                                             
#define CRYIF_EQ2_PCCONFIGIDXOFPBCONFIG                                                             
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
  \defgroup  CryIfPCGetRootDataMacros  CryIf Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define CryIf_GetExpectedCompatibilityVersionOfPCConfig()                                             /**< Deactivateable: 'CryIf_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CryIf_GetFinalMagicNumberOfPCConfig()                                                         /**< Deactivateable: 'CryIf_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CryIf_GetGeneratorCompatibilityVersionOfPCConfig()                                            /**< Deactivateable: 'CryIf_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CryIf_GetInitDataHashCodeOfPCConfig()                                                         /**< Deactivateable: 'CryIf_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
/** 
  \}
*/ 

/** 
  \defgroup  CryIfPCGetConstantDuplicatedRootDataMacros  CryIf Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define CryIf_GetChannelOfPCConfig()                                                                CryIf_Channel  /**< the pointer to CryIf_Channel */
#define CryIf_GetCryptoFunctionsOfPCConfig()                                                        CryIf_CryptoFunctions  /**< the pointer to CryIf_CryptoFunctions */
#define CryIf_GetKeyOfPCConfig()                                                                    CryIf_Key  /**< the pointer to CryIf_Key */
#define CryIf_GetMaxNumberOfKeyElementsOfGeneralOfPCConfig()                                        10u
#define CryIf_GetMaxSizeOfKeyElementOfGeneralOfPCConfig()                                           32u
#define CryIf_IsRedirectionOfGeneralOfPCConfig()                                                    (((FALSE)) != FALSE)
#define CryIf_GetSizeOfChannelOfPCConfig()                                                          4u  /**< the number of accomplishable value elements in CryIf_Channel */
#define CryIf_GetSizeOfCryptoFunctionsOfPCConfig()                                                  1u  /**< the number of accomplishable value elements in CryIf_CryptoFunctions */
#define CryIf_GetSizeOfKeyOfPCConfig()                                                              62u  /**< the number of accomplishable value elements in CryIf_Key */
#define CryIf_IsVersionInfoApiOfGeneralOfPCConfig()                                                 (((FALSE)) != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  CryIfPCGetDataMacros  CryIf Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define CryIf_GetCryptoFunctionsIdxOfChannel(Index)                                                 (CryIf_GetChannelOfPCConfig()[(Index)].CryptoFunctionsIdxOfChannel)
#define CryIf_GetDriverObjectRefOfChannel(Index)                                                    (CryIf_GetChannelOfPCConfig()[(Index)].DriverObjectRefOfChannel)
#define CryIf_GetIdOfChannel(Index)                                                                 (CryIf_GetChannelOfPCConfig()[(Index)].IdOfChannel)
#define CryIf_GetCancelJobOfCryptoFunctions(Index)                                                  (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].CancelJobOfCryptoFunctions)
#define CryIf_GetCancelJobWithInfoTypeOfCryptoFunctions(Index)                                        /**< Deactivateable: 'CryIf_CryptoFunctions.CancelJobWithInfoType' Reason: 'No Module with JobCancel using JobInfoType is configured' */
#define CryIf_GetCertificateParseOfCryptoFunctions(Index)                                           (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].CertificateParseOfCryptoFunctions)
#define CryIf_GetCertificateVerifyOfCryptoFunctions(Index)                                          (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].CertificateVerifyOfCryptoFunctions)
#define CryIf_GetCustomSyncOfCryptoFunctions(Index)                                                 (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].CustomSyncOfCryptoFunctions)
#define CryIf_GetKeyCopyOfCryptoFunctions(Index)                                                    (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].KeyCopyOfCryptoFunctions)
#define CryIf_GetKeyDeriveOfCryptoFunctions(Index)                                                  (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].KeyDeriveOfCryptoFunctions)
#define CryIf_GetKeyElementCopyOfCryptoFunctions(Index)                                             (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].KeyElementCopyOfCryptoFunctions)
#define CryIf_GetKeyElementCopyPartialOfCryptoFunctions(Index)                                      (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].KeyElementCopyPartialOfCryptoFunctions)
#define CryIf_GetKeyElementGetOfCryptoFunctions(Index)                                              (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].KeyElementGetOfCryptoFunctions)
#define CryIf_GetKeyElementIdsGetOfCryptoFunctions(Index)                                           (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].KeyElementIdsGetOfCryptoFunctions)
#define CryIf_GetKeyElementSetOfCryptoFunctions(Index)                                              (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].KeyElementSetOfCryptoFunctions)
#define CryIf_GetKeyExchangeCalcPubValOfCryptoFunctions(Index)                                      (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].KeyExchangeCalcPubValOfCryptoFunctions)
#define CryIf_GetKeyExchangeCalcSecretOfCryptoFunctions(Index)                                      (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].KeyExchangeCalcSecretOfCryptoFunctions)
#define CryIf_GetKeyGenerateOfCryptoFunctions(Index)                                                (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].KeyGenerateOfCryptoFunctions)
#define CryIf_GetKeyGetStatusOfCryptoFunctions(Index)                                               (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].KeyGetStatusOfCryptoFunctions)
#define CryIf_GetKeySetInvalidOfCryptoFunctions(Index)                                              (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].KeySetInvalidOfCryptoFunctions)
#define CryIf_GetKeyValidSetOfCryptoFunctions(Index)                                                (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].KeyValidSetOfCryptoFunctions)
#define CryIf_GetProcessJobOfCryptoFunctions(Index)                                                 (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].ProcessJobOfCryptoFunctions)
#define CryIf_GetRandomSeedOfCryptoFunctions(Index)                                                 (CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].RandomSeedOfCryptoFunctions)
#define CryIf_IsSupportsKeyElementCopyPartialOfCryptoFunctions(Index)                               ((CryIf_GetCryptoFunctionsOfPCConfig()[(Index)].SupportsKeyElementCopyPartialOfCryptoFunctions) != FALSE)
#define CryIf_GetCryptoFunctionsIdxOfKey(Index)                                                     (CryIf_GetKeyOfPCConfig()[(Index)].CryptoFunctionsIdxOfKey)
#define CryIf_GetRefOfKey(Index)                                                                    (CryIf_GetKeyOfPCConfig()[(Index)].RefOfKey)
/** 
  \}
*/ 

/** 
  \defgroup  CryIfPCGetDeduplicatedDataMacros  CryIf Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define CryIf_GetExpectedCompatibilityVersion()                                                       /**< Deactivateable: 'CryIf_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CryIf_GetFinalMagicNumber()                                                                   /**< Deactivateable: 'CryIf_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CryIf_GetGeneratorCompatibilityVersion()                                                      /**< Deactivateable: 'CryIf_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CryIf_GetInitDataHashCode()                                                                   /**< Deactivateable: 'CryIf_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CryIf_GetMaxNumberOfKeyElementsOfGeneral()                                                  CryIf_GetMaxNumberOfKeyElementsOfGeneralOfPCConfig()
#define CryIf_GetMaxSizeOfKeyElementOfGeneral()                                                     CryIf_GetMaxSizeOfKeyElementOfGeneralOfPCConfig()
#define CryIf_IsRedirectionOfGeneral()                                                              CryIf_IsRedirectionOfGeneralOfPCConfig()
#define CryIf_GetSizeOfChannel()                                                                    CryIf_GetSizeOfChannelOfPCConfig()
#define CryIf_GetSizeOfCryptoFunctions()                                                            CryIf_GetSizeOfCryptoFunctionsOfPCConfig()
#define CryIf_GetSizeOfKey()                                                                        CryIf_GetSizeOfKeyOfPCConfig()
#define CryIf_IsVersionInfoApiOfGeneral()                                                           CryIf_IsVersionInfoApiOfGeneralOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  CryIfPCHasMacros  CryIf Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define CryIf_HasChannel()                                                                          (TRUE != FALSE)
#define CryIf_HasCryptoFunctionsIdxOfChannel()                                                      (TRUE != FALSE)
#define CryIf_HasDriverObjectRefOfChannel()                                                         (TRUE != FALSE)
#define CryIf_HasIdOfChannel()                                                                      (TRUE != FALSE)
#define CryIf_HasCryptoFunctions()                                                                  (TRUE != FALSE)
#define CryIf_HasCancelJobOfCryptoFunctions()                                                       (TRUE != FALSE)
#define CryIf_HasCancelJobWithInfoTypeOfCryptoFunctions()                                             /**< Deactivateable: 'CryIf_CryptoFunctions.CancelJobWithInfoType' Reason: 'No Module with JobCancel using JobInfoType is configured' */
#define CryIf_HasCertificateParseOfCryptoFunctions()                                                (TRUE != FALSE)
#define CryIf_HasCertificateVerifyOfCryptoFunctions()                                               (TRUE != FALSE)
#define CryIf_HasCustomSyncOfCryptoFunctions()                                                      (TRUE != FALSE)
#define CryIf_HasKeyCopyOfCryptoFunctions()                                                         (TRUE != FALSE)
#define CryIf_HasKeyDeriveOfCryptoFunctions()                                                       (TRUE != FALSE)
#define CryIf_HasKeyElementCopyOfCryptoFunctions()                                                  (TRUE != FALSE)
#define CryIf_HasKeyElementCopyPartialOfCryptoFunctions()                                           (TRUE != FALSE)
#define CryIf_HasKeyElementGetOfCryptoFunctions()                                                   (TRUE != FALSE)
#define CryIf_HasKeyElementIdsGetOfCryptoFunctions()                                                (TRUE != FALSE)
#define CryIf_HasKeyElementSetOfCryptoFunctions()                                                   (TRUE != FALSE)
#define CryIf_HasKeyExchangeCalcPubValOfCryptoFunctions()                                           (TRUE != FALSE)
#define CryIf_HasKeyExchangeCalcSecretOfCryptoFunctions()                                           (TRUE != FALSE)
#define CryIf_HasKeyGenerateOfCryptoFunctions()                                                     (TRUE != FALSE)
#define CryIf_HasKeyGetStatusOfCryptoFunctions()                                                    (TRUE != FALSE)
#define CryIf_HasKeySetInvalidOfCryptoFunctions()                                                   (TRUE != FALSE)
#define CryIf_HasKeyValidSetOfCryptoFunctions()                                                     (TRUE != FALSE)
#define CryIf_HasProcessJobOfCryptoFunctions()                                                      (TRUE != FALSE)
#define CryIf_HasRandomSeedOfCryptoFunctions()                                                      (TRUE != FALSE)
#define CryIf_HasSupportsKeyElementCopyPartialOfCryptoFunctions()                                   (TRUE != FALSE)
#define CryIf_HasExpectedCompatibilityVersion()                                                       /**< Deactivateable: 'CryIf_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CryIf_HasFinalMagicNumber()                                                                   /**< Deactivateable: 'CryIf_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CryIf_HasGeneratorCompatibilityVersion()                                                      /**< Deactivateable: 'CryIf_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CryIf_HasInitDataHashCode()                                                                   /**< Deactivateable: 'CryIf_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CryIf_HasKey()                                                                              (TRUE != FALSE)
#define CryIf_HasCryptoFunctionsIdxOfKey()                                                          (TRUE != FALSE)
#define CryIf_HasRefOfKey()                                                                         (TRUE != FALSE)
#define CryIf_HasMaxNumberOfKeyElementsOfGeneral()                                                  (TRUE != FALSE)
#define CryIf_HasMaxSizeOfKeyElementOfGeneral()                                                     (TRUE != FALSE)
#define CryIf_HasRedirectionOfGeneral()                                                             (TRUE != FALSE)
#define CryIf_HasSizeOfChannel()                                                                    (TRUE != FALSE)
#define CryIf_HasSizeOfCryptoFunctions()                                                            (TRUE != FALSE)
#define CryIf_HasSizeOfKey()                                                                        (TRUE != FALSE)
#define CryIf_HasVersionInfoApiOfGeneral()                                                          (TRUE != FALSE)
#define CryIf_HasPCConfig()                                                                         (TRUE != FALSE)
#define CryIf_HasChannelOfPCConfig()                                                                (TRUE != FALSE)
#define CryIf_HasCryptoFunctionsOfPCConfig()                                                        (TRUE != FALSE)
#define CryIf_HasExpectedCompatibilityVersionOfPCConfig()                                             /**< Deactivateable: 'CryIf_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CryIf_HasFinalMagicNumberOfPCConfig()                                                         /**< Deactivateable: 'CryIf_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CryIf_HasGeneratorCompatibilityVersionOfPCConfig()                                            /**< Deactivateable: 'CryIf_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CryIf_HasInitDataHashCodeOfPCConfig()                                                         /**< Deactivateable: 'CryIf_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CryIf_HasKeyOfPCConfig()                                                                    (TRUE != FALSE)
#define CryIf_HasMaxNumberOfKeyElementsOfGeneralOfPCConfig()                                        (TRUE != FALSE)
#define CryIf_HasMaxSizeOfKeyElementOfGeneralOfPCConfig()                                           (TRUE != FALSE)
#define CryIf_HasRedirectionOfGeneralOfPCConfig()                                                   (TRUE != FALSE)
#define CryIf_HasSizeOfChannelOfPCConfig()                                                          (TRUE != FALSE)
#define CryIf_HasSizeOfCryptoFunctionsOfPCConfig()                                                  (TRUE != FALSE)
#define CryIf_HasSizeOfKeyOfPCConfig()                                                              (TRUE != FALSE)
#define CryIf_HasVersionInfoApiOfGeneralOfPCConfig()                                                (TRUE != FALSE)
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
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CryIfPBGetRootDataMacros  CryIf Get Root Data Macros (POST_BUILD)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define CryIf_GetLTConfigIdxOfPBConfig()                                                              /**< Deactivateable: 'CryIf_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CryIf_GetPCConfigIdxOfPBConfig()                                                              /**< Deactivateable: 'CryIf_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  CryIfPBHasMacros  CryIf Has Macros (POST_BUILD)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define CryIf_HasPBConfig()                                                                           /**< Deactivateable: 'CryIf_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CryIf_HasLTConfigIdxOfPBConfig()                                                              /**< Deactivateable: 'CryIf_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CryIf_HasPCConfigIdxOfPBConfig()                                                              /**< Deactivateable: 'CryIf_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
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
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_ProcessJobFuncType)(uint32 objectId, Crypto_JobType* job);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_KeyElementSetFuncType)(uint32 cryptoKeyId, uint32 keyElementId, const uint8* keyPtr, uint32 keyLength);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_KeyValidSetFuncType)(uint32 cryptoKeyId);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_KeySetInvalidFuncType)(uint32 cryptoKeyId);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_KeyGetStatusFuncType)(uint32 cryptoKeyId, Crypto_KeyStatusType* keyStatusPtr);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_KeyElementGetFuncType)(uint32 cryptoKeyId, uint32 keyElementId, uint8* resultPtr, uint32* resultLengthPtr);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_KeyElementCopyFuncType)(uint32 cryptoKeyId, uint32 keyElementId, uint32 targetCryptoKeyId, uint32 targetKeyElementId);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_KeyElementCopyPartialFuncType)(uint32 cryptoKeyId, uint32 keyElementId, uint32 keyElementSourceOffset, uint32 keyElementTargetOffset, uint32 keyElementCopyLength, uint32 targetCryptoKeyId, uint32 targetKeyElementId);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_KeyElementIdsGetFuncType)(uint32 cryptoKeyId, uint32* keyElementIdsPtr, uint32* keyElementIdsLengthPtr);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_KeyCopyFuncType)(uint32 cryptoKeyId, uint32 targetCryptoKeyId);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_RandomSeedFuncType)(uint32 cryptoKeyId, const uint8* entropyPtr, uint32 entropyLength);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_KeyGenerateFuncType)(uint32 cryptoKeyId);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_KeyDeriveFuncType)(uint32 cryptoKeyId, uint32 targetCryptoKeyId);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_KeyExchangeCalcPubValFuncType)(uint32 cryptoKeyId, uint8* publicValuePtr, uint32* publicValueLengthPtr);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_KeyExchangeCalcSecretFuncType)(uint32 cryptoKeyId, const uint8* partnerPublicValuePtr, uint32 partnerPublicValueLength);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_CertificateParseFuncType)(uint32 cryptoKeyId);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_CertificateVerifyFuncType)(uint32 cryptoKeyId, uint32 verifyCryptoKeyId, Crypto_VerifyResultType* verifyPtr);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_CancelJobFuncType)(uint32 objectId, Crypto_JobType* job);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_CancelJobFuncWithInfoType)(uint32 objectId, Crypto_JobInfoType* job);
typedef P2FUNC (Std_ReturnType, CRYIF_CODE, CryIf_CustomSyncFuncType)(uint32 dispatchId, uint32 keyId, uint32 keyElementId, uint32 targetKeyId, uint32 targetKeyElementId, const uint8* inputPtr, uint32 inputLength, uint8* outputPtr, uint32* outputLengthPtr, uint8* secondaryOutputPtr, uint32* secondaryOutputLengthPtr);


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CryIfPCIterableTypes  CryIf Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate CryIf_Channel */
/*! \spec strong type invariant () { self < CryIf_GetSizeOfChannel() } \endspec */ 
typedef uint8_least CryIf_ChannelIterType;

/**   \brief  type used to iterate CryIf_CryptoFunctions */
/*! \spec strong type invariant () { self < CryIf_GetSizeOfCryptoFunctions() } \endspec */ 
typedef uint8_least CryIf_CryptoFunctionsIterType;

/**   \brief  type used to iterate CryIf_Key */
/*! \spec strong type invariant () { self < CryIf_GetSizeOfKey() } \endspec */ 
typedef uint8_least CryIf_KeyIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CryIfPCValueTypes  CryIf Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for CryIf_CryptoFunctionsIdxOfChannel */
/*! \spec strong type invariant () { self < CryIf_GetSizeOfCryptoFunctions() } \endspec */ 
typedef uint8 CryIf_CryptoFunctionsIdxOfChannelType;

/**   \brief  value based type definition for CryIf_DriverObjectRefOfChannel */
typedef uint32 CryIf_DriverObjectRefOfChannelType;

/**   \brief  value based type definition for CryIf_IdOfChannel */
typedef uint8 CryIf_IdOfChannelType;

/**   \brief  value based type definition for CryIf_SupportsKeyElementCopyPartialOfCryptoFunctions */
typedef boolean CryIf_SupportsKeyElementCopyPartialOfCryptoFunctionsType;

/**   \brief  value based type definition for CryIf_CryptoFunctionsIdxOfKey */
/*! \spec strong type invariant () { self < CryIf_GetSizeOfCryptoFunctions() } \endspec */ 
typedef uint8 CryIf_CryptoFunctionsIdxOfKeyType;

/**   \brief  value based type definition for CryIf_RefOfKey */
typedef uint32 CryIf_RefOfKeyType;

/**   \brief  value based type definition for CryIf_MaxNumberOfKeyElementsOfGeneral */
typedef uint8 CryIf_MaxNumberOfKeyElementsOfGeneralType;

/**   \brief  value based type definition for CryIf_MaxSizeOfKeyElementOfGeneral */
typedef uint8 CryIf_MaxSizeOfKeyElementOfGeneralType;

/**   \brief  value based type definition for CryIf_RedirectionOfGeneral */
typedef boolean CryIf_RedirectionOfGeneralType;

/**   \brief  value based type definition for CryIf_SizeOfChannel */
typedef uint8 CryIf_SizeOfChannelType;

/**   \brief  value based type definition for CryIf_SizeOfCryptoFunctions */
typedef uint8 CryIf_SizeOfCryptoFunctionsType;

/**   \brief  value based type definition for CryIf_SizeOfKey */
typedef uint8 CryIf_SizeOfKeyType;

/**   \brief  value based type definition for CryIf_VersionInfoApiOfGeneral */
typedef boolean CryIf_VersionInfoApiOfGeneralType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CryIfPCStructTypes  CryIf Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in CryIf_Channel */
/*! 
 * \spec strong type invariant () { 
 *   (self.CryptoFunctionsIdxOfChannel < CryIf_GetSizeOfCryptoFunctions())
 * }
 * \endspec 
 */ 
typedef struct sCryIf_ChannelType
{
  CryIf_DriverObjectRefOfChannelType DriverObjectRefOfChannel;  /**< Contains values of DefinitionRef: /MICROSAR/CryIf/CryIfChannel/CryIfDriverObjectRef. */
  CryIf_CryptoFunctionsIdxOfChannelType CryptoFunctionsIdxOfChannel;  /**< the index of the 1:1 relation pointing to CryIf_CryptoFunctions */
  CryIf_IdOfChannelType IdOfChannel;  /**< Contains values of DefinitionRef: /MICROSAR/CryIf/CryIfChannel/CryIfChannelId. */
} CryIf_ChannelType;

/**   \brief  type used in CryIf_CryptoFunctions */
typedef struct sCryIf_CryptoFunctionsType
{
  CryIf_SupportsKeyElementCopyPartialOfCryptoFunctionsType SupportsKeyElementCopyPartialOfCryptoFunctions;
  CryIf_CancelJobFuncType CancelJobOfCryptoFunctions;
  CryIf_CertificateParseFuncType CertificateParseOfCryptoFunctions;
  CryIf_CertificateVerifyFuncType CertificateVerifyOfCryptoFunctions;
  CryIf_CustomSyncFuncType CustomSyncOfCryptoFunctions;
  CryIf_KeyCopyFuncType KeyCopyOfCryptoFunctions;
  CryIf_KeyDeriveFuncType KeyDeriveOfCryptoFunctions;
  CryIf_KeyElementCopyFuncType KeyElementCopyOfCryptoFunctions;
  CryIf_KeyElementCopyPartialFuncType KeyElementCopyPartialOfCryptoFunctions;
  CryIf_KeyElementGetFuncType KeyElementGetOfCryptoFunctions;
  CryIf_KeyElementIdsGetFuncType KeyElementIdsGetOfCryptoFunctions;
  CryIf_KeyElementSetFuncType KeyElementSetOfCryptoFunctions;
  CryIf_KeyExchangeCalcPubValFuncType KeyExchangeCalcPubValOfCryptoFunctions;
  CryIf_KeyExchangeCalcSecretFuncType KeyExchangeCalcSecretOfCryptoFunctions;
  CryIf_KeyGenerateFuncType KeyGenerateOfCryptoFunctions;
  CryIf_KeyGetStatusFuncType KeyGetStatusOfCryptoFunctions;
  CryIf_KeySetInvalidFuncType KeySetInvalidOfCryptoFunctions;
  CryIf_KeyValidSetFuncType KeyValidSetOfCryptoFunctions;
  CryIf_ProcessJobFuncType ProcessJobOfCryptoFunctions;
  CryIf_RandomSeedFuncType RandomSeedOfCryptoFunctions;
} CryIf_CryptoFunctionsType;

/**   \brief  type used in CryIf_Key */
/*! 
 * \spec strong type invariant () { 
 *   (self.CryptoFunctionsIdxOfKey < CryIf_GetSizeOfCryptoFunctions())
 * }
 * \endspec 
 */ 
typedef struct sCryIf_KeyType
{
  CryIf_RefOfKeyType RefOfKey;  /**< Contains values of DefinitionRef: /MICROSAR/CryIf/CryIfKey/CryIfKeyRef. */
  CryIf_CryptoFunctionsIdxOfKeyType CryptoFunctionsIdxOfKey;  /**< the index of the 1:1 relation pointing to CryIf_CryptoFunctions */
} CryIf_KeyType;

/** 
  \}
*/ 

/** 
  \defgroup  CryIfPCRootPointerTypes  CryIf Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to CryIf_Channel */
typedef P2CONST(CryIf_ChannelType, TYPEDEF, CRYIF_CONST) CryIf_ChannelPtrType;

/**   \brief  type used to point to CryIf_CryptoFunctions */
typedef P2CONST(CryIf_CryptoFunctionsType, TYPEDEF, CRYIF_CONST) CryIf_CryptoFunctionsPtrType;

/**   \brief  type used to point to CryIf_Key */
typedef P2CONST(CryIf_KeyType, TYPEDEF, CRYIF_CONST) CryIf_KeyPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  CryIfPCRootValueTypes  CryIf Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in CryIf_PCConfig */
typedef struct sCryIf_PCConfigType
{
  uint8 CryIf_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} CryIf_PCConfigType;

typedef CryIf_PCConfigType CryIf_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CryIfPBValueTypes  CryIf Value Types (POST_BUILD)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CryIfPBRootValueTypes  CryIf Root Value Types (POST_BUILD)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CryIf_Channel
**********************************************************************************************************************/
/** 
  \var    CryIf_Channel
  \brief  Contains parameters of /MICROSAR/CryIf/CryIfChannel.
  \details
  Element               Description
  DriverObjectRef       Contains values of DefinitionRef: /MICROSAR/CryIf/CryIfChannel/CryIfDriverObjectRef.
  CryptoFunctionsIdx    the index of the 1:1 relation pointing to CryIf_CryptoFunctions
  Id                    Contains values of DefinitionRef: /MICROSAR/CryIf/CryIfChannel/CryIfChannelId.
*/ 
#define CRYIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CryIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CryIf_ChannelType, CRYIF_CONST) CryIf_Channel[4];
#define CRYIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CryIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CryIf_CryptoFunctions
**********************************************************************************************************************/
/** 
  \var    CryIf_CryptoFunctions
  \details
  Element                          Description
  SupportsKeyElementCopyPartial
  CancelJob                    
  CertificateParse             
  CertificateVerify            
  CustomSync                   
  KeyCopy                      
  KeyDerive                    
  KeyElementCopy               
  KeyElementCopyPartial        
  KeyElementGet                
  KeyElementIdsGet             
  KeyElementSet                
  KeyExchangeCalcPubVal        
  KeyExchangeCalcSecret        
  KeyGenerate                  
  KeyGetStatus                 
  KeySetInvalid                
  KeyValidSet                  
  ProcessJob                   
  RandomSeed                   
*/ 
#define CRYIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CryIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CryIf_CryptoFunctionsType, CRYIF_CONST) CryIf_CryptoFunctions[1];
#define CRYIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CryIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CryIf_Key
**********************************************************************************************************************/
/** 
  \var    CryIf_Key
  \brief  Contains parameters of /MICROSAR/CryIf/CryIfKey.
  \details
  Element               Description
  Ref                   Contains values of DefinitionRef: /MICROSAR/CryIf/CryIfKey/CryIfKeyRef.
  CryptoFunctionsIdx    the index of the 1:1 relation pointing to CryIf_CryptoFunctions
*/ 
#define CRYIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CryIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CryIf_KeyType, CRYIF_CONST) CryIf_Key[62];
#define CRYIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CryIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/




/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/

 
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/






#if !defined (CRYIF_NOUNIT_CSLUNIT)
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/

#endif



#endif /* CRYIF_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: CryIf_Cfg.h
 *********************************************************************************************************************/

