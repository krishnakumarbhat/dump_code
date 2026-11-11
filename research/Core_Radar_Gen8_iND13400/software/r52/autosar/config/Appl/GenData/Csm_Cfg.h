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
 *            Module: Csm
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Csm_Cfg.h
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

#if !defined (CSM_CFG_H)
#define CSM_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Csm_Types.h"
#include "Os.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef CSM_USE_DUMMY_STATEMENT
#define CSM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CSM_DUMMY_STATEMENT
#define CSM_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CSM_DUMMY_STATEMENT_CONST
#define CSM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CSM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CSM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CSM_ATOMIC_VARIABLE_ACCESS
#define CSM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CSM_PROCESSOR_IND13400
#define CSM_PROCESSOR_IND13400
#endif
#ifndef CSM_COMP_LLVMDIAB
#define CSM_COMP_LLVMDIAB
#endif
#ifndef CSM_GEN_GENERATOR_MSR
#define CSM_GEN_GENERATOR_MSR
#endif
#ifndef CSM_CPUTYPE_BITORDER_LSB2MSB
#define CSM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CSM_CONFIGURATION_VARIANT_PRECOMPILE
#define CSM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CSM_CONFIGURATION_VARIANT_LINKTIME
#define CSM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CSM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CSM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CSM_CONFIGURATION_VARIANT
#define CSM_CONFIGURATION_VARIANT CSM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CSM_POSTBUILD_VARIANT_SUPPORT
#define CSM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define CSM_ASYNC_PROCESSING                                                                        STD_ON
/* Module version information */
#define CSM_CFG_MAJOR_VERSION                                                                       9u
#define CSM_CFG_MINOR_VERSION                                                                       1u
#define CSM_CFG_PATCH_VERSION                                                                       1u
#define CSM_GENERATOR_MAJOR_VERSION                                                                 9u
#define CSM_GENERATOR_MINOR_VERSION                                                                 1u
#define CSM_GENERATOR_PATCH_VERSION                                                                 1u

/* Defines for general parameters of type boolean, integer and enumeration */
#define CSM_CALLBACKS                                                                               STD_ON 
#define CSM_ASYM_PRIVATE_KEY_MAX_LENGTH                                                             32u 
#define CSM_ASYM_PUBLIC_KEY_MAX_LENGTH                                                              1024u 
#define CSM_SYM_KEY_MAX_LENGTH                                                                      16u 
#define CSM_USE_DEPRECATED                                                                          STD_OFF 
#define CSM_VERSION_INFO_API                                                                        STD_OFF 
#define CSM_CALLBACK_START_NOTIFICATION                                                             STD_OFF 
#define CSM_CANCELATION_DURING_PROCESSING                                                           STD_OFF 
#define CSM_MULTI_PARTITION_RUNTIME_CHECKS                                                          STD_OFF 
#define CSM_SWC_USE_ERROR_CODES_CSM_PREFIX                                                          STD_OFF 
#define CSM_JOBS                                                                                    STD_ON 
#define CSM_KEYS                                                                                    STD_ON 
#define CSM_QUEUES                                                                                  STD_ON 
#define CSM_CALLOUTS                                                                                STD_OFF 
#define CSM_IN_OUT_REDIRECTIONS                                                                     STD_OFF 

/* Symbolic Name Define Block */
#define CsmConf_CsmJob_Crypto_AEAD_GCM_Decrypt                                                      0u 
#define CsmConf_CsmJob_Crypto_AEAD_GCM_Encrypt                                                      1u 
#define CsmConf_CsmJob_Crypto_Decrypt_AES_CBC_256                                                   2u 
#define CsmConf_CsmJob_Crypto_Decrypt_AES_CBC_256_ASYNC_1                                           3u 
#define CsmConf_CsmJob_Crypto_Decrypt_AES_CBC_256_ASYNC_2                                           4u 
#define CsmConf_CsmJob_Crypto_Decrypt_AES_CBC_256_ASYNC_3                                           5u 
#define CsmConf_CsmJob_Crypto_Decrypt_AES_CBC_SHE                                                   6u 
#define CsmConf_CsmJob_Crypto_Decrypt_AES_CFB_128                                                   7u 
#define CsmConf_CsmJob_Crypto_Decrypt_AES_CTR_256                                                   8u 
#define CsmConf_CsmJob_Crypto_Decrypt_AES_ECB_256                                                   9u 
#define CsmConf_CsmJob_Crypto_Decrypt_AES_ECB_SHE                                                   10u 
#define CsmConf_CsmJob_Crypto_Decrypt_RSA_4096_OAEP_SHA2_256                                        11u 
#define CsmConf_CsmJob_Crypto_Encrypt_AES_CBC_256                                                   12u 
#define CsmConf_CsmJob_Crypto_Encrypt_AES_CBC_SHE                                                   13u 
#define CsmConf_CsmJob_Crypto_Encrypt_AES_CFB_128                                                   14u 
#define CsmConf_CsmJob_Crypto_Encrypt_AES_CTR_256                                                   15u 
#define CsmConf_CsmJob_Crypto_Encrypt_AES_ECB_256                                                   16u 
#define CsmConf_CsmJob_Crypto_Encrypt_AES_ECB_SHE                                                   17u 
#define CsmConf_CsmJob_Crypto_Encrypt_RSA_4096_OAEP_SHA2_256                                        18u 
#define CsmConf_CsmJob_Crypto_Hash_SHA2_256                                                         19u 
#define CsmConf_CsmJob_Crypto_Hash_SHA2_256_ASYNC_1                                                 20u 
#define CsmConf_CsmJob_Crypto_Hash_SHA2_256_ASYNC_2                                                 21u 
#define CsmConf_CsmJob_Crypto_MAC_CMAC_Generate_128                                                 22u 
#define CsmConf_CsmJob_Crypto_MAC_CMAC_Generate_256                                                 23u 
#define CsmConf_CsmJob_Crypto_MAC_CMAC_Generate_SHE                                                 24u 
#define CsmConf_CsmJob_Crypto_MAC_CMAC_Verify_128                                                   25u 
#define CsmConf_CsmJob_Crypto_MAC_CMAC_Verify_256                                                   26u 
#define CsmConf_CsmJob_Crypto_MAC_CMAC_Verify_SHE                                                   27u 
#define CsmConf_CsmJob_Crypto_MAC_HMAC_SHA2_512                                                     28u 
#define CsmConf_CsmJob_Crypto_MAC_HMAC_Verify_SHA2_512                                              29u 
#define CsmConf_CsmJob_Crypto_RNG                                                                   30u 
#define CsmConf_CsmJob_Crypto_RNG_DRBG                                                              31u 
#define CsmConf_CsmJob_Crypto_SigGen_ECCBrainpool_256R1_SHA256                                      32u 
#define CsmConf_CsmJob_Crypto_SigGen_ECCBrainpool_256T1_SHA256                                      33u 
#define CsmConf_CsmJob_Crypto_SigGen_ECCNIST_256_SHA256                                             34u 
#define CsmConf_CsmJob_Crypto_SigGen_ED448                                                          35u 
#define CsmConf_CsmJob_Crypto_SigGen_Ed25519_256                                                    36u 
#define CsmConf_CsmJob_Crypto_SigGen_RSAPSS_1024                                                    37u 
#define CsmConf_CsmJob_Crypto_SigVer_ECCBrainpool_256R1_SHA256                                      38u 
#define CsmConf_CsmJob_Crypto_SigVer_ECCBrainpool_256T1_SHA256                                      39u 
#define CsmConf_CsmJob_Crypto_SigVer_ECCNIST_256                                                    40u 
#define CsmConf_CsmJob_Crypto_SigVer_ED448                                                          41u 
#define CsmConf_CsmJob_Crypto_SigVer_Ed25519_256                                                    42u 
#define CsmConf_CsmJob_Crypto_SigVer_RSAPSS_1024                                                    43u 
#define CsmConf_CsmJob_MKA_CMACGenerate                                                             44u 
#define CsmConf_CsmJob_MKA_CMACVerify                                                               45u 
#define CsmConf_CsmJob_MKA_Decrypt_ECB                                                              46u 
#define CsmConf_CsmJob_MKA_Encrypt_ECB                                                              47u 
#define CsmConf_CsmJob_MKA_Hash_Key_Derivation                                                      48u 
#define CsmConf_CsmJob_MKA_KeyDerivationPRF                                                         49u 
#define CsmConf_CsmJob_MKA_Random                                                                   50u 
#define CsmConf_CsmKey_CsmKey_Boot_MAC                                                              0u 
#define CsmConf_CsmKey_CsmKey_Boot_MAC_Key                                                          1u 
#define CsmConf_CsmKey_CsmKey_Crypto_AES_128                                                        2u 
#define CsmConf_CsmKey_CsmKey_Crypto_AES_256                                                        3u 
#define CsmConf_CsmKey_CsmKey_Crypto_Hash                                                           4u 
#define CsmConf_CsmKey_CsmKey_Crypto_RNG                                                            5u 
#define CsmConf_CsmKey_CsmKey_Crypto_RSA_1024                                                       6u 
#define CsmConf_CsmKey_CsmKey_Crypto_RSA_2048                                                       7u 
#define CsmConf_CsmKey_CsmKey_Crypto_RSA_3072                                                       8u 
#define CsmConf_CsmKey_CsmKey_Crypto_RSA_4096                                                       9u 
#define CsmConf_CsmKey_CsmKey_Custom_Operations                                                     10u 
#define CsmConf_CsmKey_CsmKey_ECC_192_Key_SigGenerate                                               11u 
#define CsmConf_CsmKey_CsmKey_ECC_192_Key_SigVerify                                                 12u 
#define CsmConf_CsmKey_CsmKey_ECC_224_Key_SigGenerate                                               13u 
#define CsmConf_CsmKey_CsmKey_ECC_224_Key_Exchange                                                  14u 
#define CsmConf_CsmKey_CsmKey_ECC_224_Key_SigVerify                                                 15u 
#define CsmConf_CsmKey_CsmKey_ECC_256_Key_Generate                                                  16u 
#define CsmConf_CsmKey_CsmKey_ECC_256_Key_Generate_2                                                17u 
#define CsmConf_CsmKey_CsmKey_ECC_256_Key_SigGenerate                                               18u 
#define CsmConf_CsmKey_CsmKey_ECC_256_Key_SigVerify                                                 19u 
#define CsmConf_CsmKey_CsmKey_ECC_320_Key_SigGenerate                                               20u 
#define CsmConf_CsmKey_CsmKey_ECC_320_Key_SigVerify                                                 21u 
#define CsmConf_CsmKey_CsmKey_ECC_384_Key_SigGenerate                                               22u 
#define CsmConf_CsmKey_CsmKey_ECC_384_Key_SigVerify                                                 23u 
#define CsmConf_CsmKey_CsmKey_ECC_512_Key_SigGenerate                                               24u 
#define CsmConf_CsmKey_CsmKey_ECC_512_Key_SigVerify                                                 25u 
#define CsmConf_CsmKey_CsmKey_ECC_521_Key_SigGenerate                                               26u 
#define CsmConf_CsmKey_CsmKey_ECC_521_Key_SigVerify                                                 27u 
#define CsmConf_CsmKey_CsmKey_ECDH_128_Key_SigGenerate                                              28u 
#define CsmConf_CsmKey_CsmKey_ECDH_128_Key_SigVerify                                                29u 
#define CsmConf_CsmKey_CsmKey_ECDH_224_Key_SigGenerate                                              30u 
#define CsmConf_CsmKey_CsmKey_ECDH_224_Key_SigVerify                                                31u 
#define CsmConf_CsmKey_CsmKey_ECDH_256_Key_SigGenerate                                              32u 
#define CsmConf_CsmKey_CsmKey_ECDH_256_Key_SigVerify                                                33u 
#define CsmConf_CsmKey_CsmKey_ECDH_384_Key_SigGenerate                                              34u 
#define CsmConf_CsmKey_CsmKey_ECDH_384_Key_SigVerify                                                35u 
#define CsmConf_CsmKey_CsmKey_ECDH_512_Key_SigGenerate                                              36u 
#define CsmConf_CsmKey_CsmKey_ECDH_512_Key_SigVerify                                                37u 
#define CsmConf_CsmKey_CsmKey_ED448_Key_SigGenerate                                                 38u 
#define CsmConf_CsmKey_CsmKey_ED448_Key_SigVerify                                                   39u 
#define CsmConf_CsmKey_CsmKey_ED25519_Key_SigGenerate                                               40u 
#define CsmConf_CsmKey_CsmKey_ED25519_Key_SigVerify                                                 41u 
#define CsmConf_CsmKey_CsmKey_MKA_CAK                                                               42u 
#define CsmConf_CsmKey_CsmKey_MKA_ICK                                                               43u 
#define CsmConf_CsmKey_CsmKey_MKA_KEK                                                               44u 
#define CsmConf_CsmKey_CsmKey_MKA_MAC                                                               45u 
#define CsmConf_CsmKey_CsmKey_MKA_Random                                                            46u 
#define CsmConf_CsmKey_CsmKey_MKA_SAK                                                               47u 
#define CsmConf_CsmKey_CsmKey_MKA_SAK_Data                                                          48u 
#define CsmConf_CsmKey_CsmKey_Master_ECU_Key                                                        49u 
#define CsmConf_CsmKey_CsmKey_Monotonic_Counter                                                     50u 
#define CsmConf_CsmKey_CsmKey_SHE_KEY_1                                                             51u 
#define CsmConf_CsmKey_CsmKey_SHE_KEY_2                                                             52u 
#define CsmConf_CsmKey_CsmKey_SHE_KEY_3                                                             53u 
#define CsmConf_CsmKey_CsmKey_SHE_KEY_4                                                             54u 
#define CsmConf_CsmKey_CsmKey_SHE_KEY_5                                                             55u 
#define CsmConf_CsmKey_CsmKey_SHE_KEY_6                                                             56u 
#define CsmConf_CsmKey_CsmKey_SHE_KEY_7                                                             57u 
#define CsmConf_CsmKey_CsmKey_SHE_KEY_8                                                             58u 
#define CsmConf_CsmKey_CsmKey_SHE_KEY_9                                                             59u 
#define CsmConf_CsmKey_CsmKey_SHE_KEY_10                                                            60u 
#define CsmConf_CsmKey_CsmKey_SHE_RAM_KEY                                                           61u 

#define CSM_SINGLE_PARTITION                                                                        0u
#ifndef CSM_DEV_ERROR_DETECT
#define CSM_DEV_ERROR_DETECT STD_ON
#endif
#ifndef CSM_DEV_ERROR_REPORT
#define CSM_DEV_ERROR_REPORT STD_ON
#endif
#define CSM_EXIST_AEADDECRYPT                                                                       STD_ON
#define CSM_EXIST_AEADENCRYPT                                                                       STD_ON
#define CSM_EXIST_DECRYPT                                                                           STD_ON
#define CSM_EXIST_ENCRYPT                                                                           STD_ON
#define CSM_EXIST_HASH                                                                              STD_ON
#define CSM_EXIST_MACGENERATE                                                                       STD_ON
#define CSM_EXIST_MACVERIFY                                                                         STD_ON
#define CSM_EXIST_RANDOMGENERATE                                                                    STD_ON
#define CSM_EXIST_SECURECOUNTER                                                                     STD_OFF
#define CSM_EXIST_SIGNATUREGENERATE                                                                 STD_ON
#define CSM_EXIST_SIGNATUREVERIFY                                                                   STD_ON
#define CSM_EXIST_JOBKEYSETVALID                                                                    STD_OFF
#define CSM_EXIST_JOBKEYEXCHANGECALCPUBVAL                                                          STD_OFF
#define CSM_EXIST_JOBKEYEXCHANGECALCSECRET                                                          STD_OFF
#define CSM_EXIST_JOBKEYDERIVE                                                                      STD_OFF
#define CSM_EXIST_JOBRANDOMSEED                                                                     STD_OFF
#define CSM_EXIST_JOBKEYGENERATE                                                                    STD_OFF
#define CSM_EXIST_JOBCERTIFICATEPARSE                                                               STD_OFF
#define CSM_EXIST_JOBCERTIFICATEVERIFY                                                              STD_OFF
#define CSM_EXIST_JOBKEYSETINVALID                                                                  STD_OFF
#define CSM_EXIST_JOBKEYWRAP                                                                        STD_OFF
#define CSM_EXIST_JOBKEYUNWRAP                                                                      STD_OFF
#define CSM_RTE_PORTS                                                                               STD_OFF
#define CSM_INVALID_KEYID                                                                           0xFFFFFFFFu
#define CSM_NUMBER_OF_PARTITIONS                                                                    1u
/* Extending Crypto_ProcessingType by an internally used value for Queue Processing */
#define CRYPTO_PROCESSING_MIXED                                                                     2u

/**
  \defgroup  CsmCompatibilityDefines  Csm Compatibility Defines (PRE_COMPILE)
  \brief  These defines are used to differentiate the BSW API versions between users of the Csm.
  \{
*/
#if defined (CSM_SOURCE) || defined (CSM_RTE_SOURCE)
# define CSM_JOB_KEY_API_VERSION CSM_ASR_VERSION_R21_11
#else
# define CSM_JOB_KEY_API_VERSION CSM_ASR_VERSION_4_04
#endif
/**
  \}
*/



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CsmPCDataSwitches  Csm Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CSM_ASYMPRIVATEKEYMAXLENGTHOFGENERAL                                                        STD_ON
#define CSM_ASYMPUBLICKEYMAXLENGTHOFGENERAL                                                         STD_ON
#define CSM_BSWCALLBACKS                                                                            STD_ON
#define CSM_CALLBACKFUNC43OFBSWCALLBACKS                                                            STD_OFF  /**< Deactivateable: 'Csm_BswCallbacks.CallbackFunc43' Reason: 'No Callback according to ASR 4.3 is configured' */
#define CSM_CALLBACKFUNC44OFBSWCALLBACKS                                                            STD_OFF  /**< Deactivateable: 'Csm_BswCallbacks.CallbackFunc44' Reason: 'No Callback according to ASR 4.4 is configured' */
#define CSM_CALLBACKFUNC45OFBSWCALLBACKS                                                            STD_OFF  /**< Deactivateable: 'Csm_BswCallbacks.CallbackFunc45' Reason: 'No Callback according to ASR R19-11/4.5 is configured' */
#define CSM_CALLBACKFUNC46OFBSWCALLBACKS                                                            STD_ON
#define CSM_CALLBACKSTARTNOTIFICATIONOFGENERAL                                                      STD_ON
#define CSM_CALLOUT                                                                                 STD_OFF  /**< Deactivateable: 'Csm_Callout' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CSM_POSTJOBCALLOUTFUNCOFCALLOUT                                                             STD_OFF  /**< Deactivateable: 'Csm_Callout.PostJobCalloutFunc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CSM_PREJOBCALLOUTFUNCOFCALLOUT                                                              STD_OFF  /**< Deactivateable: 'Csm_Callout.PreJobCalloutFunc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CSM_CALLOUTINFO                                                                             STD_OFF  /**< Deactivateable: 'Csm_CalloutInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CSM_CALLOUTIDXOFCALLOUTINFO                                                                 STD_OFF  /**< Deactivateable: 'Csm_CalloutInfo.CalloutIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CSM_JOBTABLEIDXOFCALLOUTINFO                                                                STD_OFF  /**< Deactivateable: 'Csm_CalloutInfo.JobTableIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CSM_CALLOUTSTATE                                                                            STD_OFF  /**< Deactivateable: 'Csm_CalloutState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define CSM_CALLOUTSTATEOFCALLOUTSTATE                                                              STD_OFF  /**< Deactivateable: 'Csm_CalloutState.CalloutState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define CSM_CANCELATIONDURINGPROCESSINGOFGENERAL                                                    STD_ON
#define CSM_EXPECTEDCOMPATIBILITYVERSION                                                            STD_OFF  /**< Deactivateable: 'Csm_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CSM_FINALMAGICNUMBER                                                                        STD_OFF  /**< Deactivateable: 'Csm_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CSM_GENERATORCOMPATIBILITYVERSION                                                           STD_OFF  /**< Deactivateable: 'Csm_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CSM_INOUTJOBREDIRECTIONTABLE                                                                STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable' Reason: 'Not enabled for any job' */
#define CSM_INPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                             STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.InputKeyElementId' Reason: 'Not enabled for any job' */
#define CSM_INPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                                    STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.InputKeyId' Reason: 'Not enabled for any job' */
#define CSM_OUTPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                            STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.OutputKeyElementId' Reason: 'Not enabled for any job' */
#define CSM_OUTPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                                   STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.OutputKeyId' Reason: 'Not enabled for any job' */
#define CSM_REDIRECTIONCONFIGVALUEOFINOUTJOBREDIRECTIONTABLE                                        STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.RedirectionConfigValue' Reason: 'Not enabled for any job' */
#define CSM_SECONDARYINPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                    STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryInputKeyElementId' Reason: 'Not enabled for any job' */
#define CSM_SECONDARYINPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                           STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryInputKeyId' Reason: 'Not enabled for any job' */
#define CSM_SECONDARYOUTPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                   STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryOutputKeyElementId' Reason: 'Not enabled for any job' */
#define CSM_SECONDARYOUTPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                          STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryOutputKeyId' Reason: 'Not enabled for any job' */
#define CSM_TERTIARYINPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                     STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.TertiaryInputKeyElementId' Reason: 'Not enabled for any job' */
#define CSM_TERTIARYINPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                            STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.TertiaryInputKeyId' Reason: 'Not enabled for any job' */
#define CSM_INOUTREDIRECTION                                                                        STD_OFF  /**< Deactivateable: 'Csm_InOutRedirection' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CSM_INOUTREDIRECTIONMAP                                                                     STD_OFF  /**< Deactivateable: 'Csm_InOutRedirectionMap' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CSM_INOUTJOBREDIRECTIONTABLEIDXOFINOUTREDIRECTIONMAP                                        STD_OFF  /**< Deactivateable: 'Csm_InOutRedirectionMap.InOutJobRedirectionTableIdx' Reason: 'Not enabled for any job' */
#define CSM_INVALIDHNDOFINOUTREDIRECTIONMAP                                                         STD_OFF  /**< Deactivateable: 'Csm_InOutRedirectionMap.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'Csm_InOutRedirectionMap.InvalidHnd' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CSM_INITDATAHASHCODE                                                                        STD_OFF  /**< Deactivateable: 'Csm_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CSM_JOB                                                                                     STD_ON
#define CSM_JOBINFO                                                                                 STD_ON
#define CSM_JOBPRIMITIVEINFO                                                                        STD_ON
#define CSM_JOBSTATE                                                                                STD_ON
#define CSM_JOBTABLE                                                                                STD_ON
#define CSM_ASYNCHRONOUSOFJOBTABLE                                                                  STD_ON
#define CSM_BSWCALLBACKSIDXOFJOBTABLE                                                               STD_ON
#define CSM_BSWCALLBACKSUSEDOFJOBTABLE                                                              STD_ON
#define CSM_CALLOUTINFOIDXOFJOBTABLE                                                                STD_OFF  /**< Deactivateable: 'Csm_JobTable.CalloutInfoIdx' Reason: 'the optional indirection is deactivated because CalloutInfoUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CSM_CALLOUTINFOUSEDOFJOBTABLE                                                               STD_OFF  /**< Deactivateable: 'Csm_JobTable.CalloutInfoUsed' Reason: 'the optional indirection is deactivated because CalloutInfoUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CSM_CSMKEYIDIDXOFJOBTABLE                                                                   STD_ON
#define CSM_INOUTREDIRECTIONMAPIDXOFJOBTABLE                                                        STD_OFF  /**< Deactivateable: 'Csm_JobTable.InOutRedirectionMapIdx' Reason: 'the optional indirection is deactivated because InOutRedirectionMapUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CSM_INOUTREDIRECTIONMAPUSEDOFJOBTABLE                                                       STD_OFF  /**< Deactivateable: 'Csm_JobTable.InOutRedirectionMapUsed' Reason: 'the optional indirection is deactivated because InOutRedirectionMapUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CSM_JOBIDXOFJOBTABLE                                                                        STD_OFF  /**< Deactivateable: 'Csm_JobTable.JobIdx' Reason: 'the optional indirection is deactivated because JobUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CSM_JOBINFOIDXOFJOBTABLE                                                                    STD_ON
#define CSM_JOBPARTITIONIDXOFJOBTABLE                                                               STD_ON
#define CSM_JOBPRIMITIVEINFOIDXOFJOBTABLE                                                           STD_ON
#define CSM_JOBUSEDOFJOBTABLE                                                                       STD_OFF  /**< Deactivateable: 'Csm_JobTable.JobUsed' Reason: 'the optional indirection is deactivated because JobUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CSM_MASKEDBITSOFJOBTABLE                                                                    STD_ON
#define CSM_PRIMITIVECALLBACKUPDATENOTIFICATIONOFJOBTABLE                                           STD_ON
#define CSM_PRIORITYOFJOBTABLE                                                                      STD_ON
#define CSM_QUEUEINFOIDXOFJOBTABLE                                                                  STD_ON
#define CSM_RTECALLBACKIDXOFJOBTABLE                                                                STD_OFF  /**< Deactivateable: 'Csm_JobTable.RteCallbackIdx' Reason: 'No RTE Callback is configured' */
#define CSM_RTECALLBACKPARTITIONIDXOFJOBTABLE                                                       STD_ON
#define CSM_RTECALLBACKUSEDOFJOBTABLE                                                               STD_OFF  /**< Deactivateable: 'Csm_JobTable.RteCallbackUsed' Reason: 'No RTE Callback is configured' */
#define CSM_JOBTOOBJMAP                                                                             STD_ON
#define CSM_KEY                                                                                     STD_ON
#define CSM_CRYIFKEYIDOFKEY                                                                         STD_ON
#define CSM_MULTIPARTITIONRUNTIMECHECKSOFGENERAL                                                    STD_ON
#define CSM_PARTITIONDATAINITIALIZED                                                                STD_ON
#define CSM_PARTITIONIDENTIFIERS                                                                    STD_ON
#define CSM_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                              STD_ON
#define CSM_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                      STD_ON
#define CSM_PRIMITIVEINFO                                                                           STD_ON
#define CSM_QUEUE                                                                                   STD_ON
#define CSM_QUEUEINFO                                                                               STD_ON
#define CSM_CHANNELIDOFQUEUEINFO                                                                    STD_ON
#define CSM_JOBOBJSYNCHRONOUSIDXOFQUEUEINFO                                                         STD_ON
#define CSM_JOBOBJSYNCHRONOUSPARTITIONIDXOFQUEUEINFO                                                STD_ON
#define CSM_JOBOBJSYNCHRONOUSUSEDOFQUEUEINFO                                                        STD_ON
#define CSM_JOBPOOLENDIDXOFQUEUEINFO                                                                STD_ON
#define CSM_JOBPOOLPARTITIONIDXOFQUEUEINFO                                                          STD_ON
#define CSM_JOBPOOLSTARTIDXOFQUEUEINFO                                                              STD_ON
#define CSM_JOBPOOLUSEDOFQUEUEINFO                                                                  STD_ON
#define CSM_JOBSHARINGOFQUEUEINFO                                                                   STD_ON
#define CSM_OPERATIONMODELIMITATIONOFQUEUEINFO                                                      STD_OFF  /**< Deactivateable: 'Csm_QueueInfo.OperationModeLimitation' Reason: 'the value of Csm_OperationModeLimitationOfQueueInfo is always 'false' due to this, the array is deactivated.' */
#define CSM_PARTITIONCONFIGIDXOFQUEUEINFO                                                           STD_ON
#define CSM_PROCESSINGMODEOFQUEUEINFO                                                               STD_ON
#define CSM_QUEUEENDIDXOFQUEUEINFO                                                                  STD_ON
#define CSM_QUEUESTARTIDXOFQUEUEINFO                                                                STD_ON
#define CSM_TRIGGERASYNCHJOBSINCALLBACKOFQUEUEINFO                                                  STD_OFF  /**< Deactivateable: 'Csm_QueueInfo.TriggerAsynchJobsInCallback' Reason: 'Not enabled for any of the queues.' */
#define CSM_QUEUESTATE                                                                              STD_ON
#define CSM_LOCKOFQUEUESTATE                                                                        STD_ON
#define CSM_QUEUEIDXOFQUEUESTATE                                                                    STD_ON
#define CSM_RETRIGGERINGOFQUEUESTATE                                                                STD_OFF  /**< Deactivateable: 'Csm_QueueState.Retriggering' Reason: 'Not enabled for any of the queues.' */
#define CSM_RTECALLBACK                                                                             STD_OFF  /**< Deactivateable: 'Csm_RteCallback' Reason: 'No RTE Callback is configured' */
#define CSM_RTECALLBACKOCCURRED                                                                     STD_OFF  /**< Deactivateable: 'Csm_RteCallbackOccurred' Reason: 'No RTE Callback is configured' */
#define CSM_RTERESULT                                                                               STD_OFF  /**< Deactivateable: 'Csm_RteResult' Reason: 'No RTE Callback is configured' */
#define CSM_SIZEOFBSWCALLBACKS                                                                      STD_ON
#define CSM_SIZEOFJOB                                                                               STD_ON
#define CSM_SIZEOFJOBINFO                                                                           STD_ON
#define CSM_SIZEOFJOBPRIMITIVEINFO                                                                  STD_ON
#define CSM_SIZEOFJOBSTATE                                                                          STD_ON
#define CSM_SIZEOFJOBTABLE                                                                          STD_ON
#define CSM_SIZEOFJOBTOOBJMAP                                                                       STD_ON
#define CSM_SIZEOFKEY                                                                               STD_ON
#define CSM_SIZEOFPARTITIONIDENTIFIERS                                                              STD_ON
#define CSM_SIZEOFPRIMITIVEINFO                                                                     STD_ON
#define CSM_SIZEOFQUEUE                                                                             STD_ON
#define CSM_SIZEOFQUEUEINFO                                                                         STD_ON
#define CSM_SIZEOFQUEUESTATE                                                                        STD_ON
#define CSM_SWCUSEERRORCODESPREFIXOFGENERAL                                                         STD_OFF  /**< Deactivateable: 'Csm_SwcUseErrorCodesPrefixOfGeneral' Reason: 'Parameter is not configured!' */
#define CSM_SYMKEYMAXLENGTHOFGENERAL                                                                STD_ON
#define CSM_USEDEPRECATEDOFGENERAL                                                                  STD_ON
#define CSM_VERSIONINFOAPIOFGENERAL                                                                 STD_ON
#define CSM_PCCONFIG                                                                                STD_ON
#define CSM_FINALMAGICNUMBEROFPCCONFIG                                                              STD_OFF  /**< Deactivateable: 'Csm_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CSM_INITDATAHASHCODEOFPCCONFIG                                                              STD_OFF  /**< Deactivateable: 'Csm_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CSM_PCPARTITIONCONFIGOFPCCONFIG                                                             STD_ON
#define CSM_PARTITIONIDENTIFIERSOFPCCONFIG                                                          STD_ON
#define CSM_SIZEOFPARTITIONIDENTIFIERSOFPCCONFIG                                                    STD_ON
#define CSM_PCPARTITIONCONFIG                                                                       STD_ON
#define CSM_ASYMPRIVATEKEYMAXLENGTHOFGENERALOFPCPARTITIONCONFIG                                     STD_ON
#define CSM_ASYMPUBLICKEYMAXLENGTHOFGENERALOFPCPARTITIONCONFIG                                      STD_ON
#define CSM_BSWCALLBACKSOFPCPARTITIONCONFIG                                                         STD_ON
#define CSM_CALLBACKSTARTNOTIFICATIONOFGENERALOFPCPARTITIONCONFIG                                   STD_ON
#define CSM_CANCELATIONDURINGPROCESSINGOFGENERALOFPCPARTITIONCONFIG                                 STD_ON
#define CSM_EXPECTEDCOMPATIBILITYVERSIONOFPCPARTITIONCONFIG                                         STD_OFF  /**< Deactivateable: 'Csm_PCPartitionConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CSM_GENERATORCOMPATIBILITYVERSIONOFPCPARTITIONCONFIG                                        STD_OFF  /**< Deactivateable: 'Csm_PCPartitionConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CSM_JOBINFOOFPCPARTITIONCONFIG                                                              STD_ON
#define CSM_JOBOFPCPARTITIONCONFIG                                                                  STD_ON
#define CSM_JOBPRIMITIVEINFOOFPCPARTITIONCONFIG                                                     STD_ON
#define CSM_JOBSTATEOFPCPARTITIONCONFIG                                                             STD_ON
#define CSM_JOBTABLEOFPCPARTITIONCONFIG                                                             STD_ON
#define CSM_JOBTOOBJMAPOFPCPARTITIONCONFIG                                                          STD_ON
#define CSM_KEYOFPCPARTITIONCONFIG                                                                  STD_ON
#define CSM_MULTIPARTITIONRUNTIMECHECKSOFGENERALOFPCPARTITIONCONFIG                                 STD_ON
#define CSM_PARTITIONDATAINITIALIZEDOFPCPARTITIONCONFIG                                             STD_ON
#define CSM_PRIMITIVEINFOOFPCPARTITIONCONFIG                                                        STD_ON
#define CSM_QUEUEINFOOFPCPARTITIONCONFIG                                                            STD_ON
#define CSM_QUEUEOFPCPARTITIONCONFIG                                                                STD_ON
#define CSM_QUEUESTATEOFPCPARTITIONCONFIG                                                           STD_ON
#define CSM_SIZEOFBSWCALLBACKSOFPCPARTITIONCONFIG                                                   STD_ON
#define CSM_SIZEOFJOBINFOOFPCPARTITIONCONFIG                                                        STD_ON
#define CSM_SIZEOFJOBOFPCPARTITIONCONFIG                                                            STD_ON
#define CSM_SIZEOFJOBPRIMITIVEINFOOFPCPARTITIONCONFIG                                               STD_ON
#define CSM_SIZEOFJOBSTATEOFPCPARTITIONCONFIG                                                       STD_ON
#define CSM_SIZEOFJOBTABLEOFPCPARTITIONCONFIG                                                       STD_ON
#define CSM_SIZEOFJOBTOOBJMAPOFPCPARTITIONCONFIG                                                    STD_ON
#define CSM_SIZEOFKEYOFPCPARTITIONCONFIG                                                            STD_ON
#define CSM_SIZEOFPRIMITIVEINFOOFPCPARTITIONCONFIG                                                  STD_ON
#define CSM_SIZEOFQUEUEINFOOFPCPARTITIONCONFIG                                                      STD_ON
#define CSM_SIZEOFQUEUEOFPCPARTITIONCONFIG                                                          STD_ON
#define CSM_SIZEOFQUEUESTATEOFPCPARTITIONCONFIG                                                     STD_ON
#define CSM_SWCUSEERRORCODESPREFIXOFGENERALOFPCPARTITIONCONFIG                                      STD_OFF  /**< Deactivateable: 'Csm_PCPartitionConfig.SwcUseErrorCodesPrefixOfGeneral' Reason: 'Parameter is not configured!' */
#define CSM_SYMKEYMAXLENGTHOFGENERALOFPCPARTITIONCONFIG                                             STD_ON
#define CSM_USEDEPRECATEDOFGENERALOFPCPARTITIONCONFIG                                               STD_ON
#define CSM_VERSIONINFOAPIOFGENERALOFPCPARTITIONCONFIG                                              STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCMinNumericValueDefines  Csm Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define CSM_MIN_CALLOUTSTATEOFCALLOUTSTATE                                                          0u
#define CSM_MIN_JOBSTATE                                                                            0u
#define CSM_MIN_PARTITIONDATAINITIALIZED                                                            0u
#define CSM_MIN_LOCKOFQUEUESTATE                                                                    0u
#define CSM_MIN_QUEUEIDXOFQUEUESTATE                                                                0u
#define CSM_MIN_RETRIGGERINGOFQUEUESTATE                                                            0u
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCMaxNumericValueDefines  Csm Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define CSM_MAX_CALLOUTSTATEOFCALLOUTSTATE                                                          255u
#define CSM_MAX_JOBSTATE                                                                            255u
#define CSM_MAX_PARTITIONDATAINITIALIZED                                                            255u
#define CSM_MAX_LOCKOFQUEUESTATE                                                                    65535u
#define CSM_MAX_QUEUEIDXOFQUEUESTATE                                                                255u
#define CSM_MAX_RETRIGGERINGOFQUEUESTATE                                                            255u
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCNoReferenceDefines  Csm No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define CSM_NO_BSWCALLBACKSIDXOFJOBTABLE                                                            255u
#define CSM_NO_CALLOUTINFOIDXOFJOBTABLE                                                             255u
#define CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE                                                     255u
#define CSM_NO_JOBIDXOFJOBTABLE                                                                     255u
#define CSM_NO_JOBPARTITIONIDXOFJOBTABLE                                                            255u
#define CSM_NO_RTECALLBACKIDXOFJOBTABLE                                                             255u
#define CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE                                                    255u
#define CSM_NO_JOBOBJSYNCHRONOUSIDXOFQUEUEINFO                                                      255u
#define CSM_NO_JOBOBJSYNCHRONOUSPARTITIONIDXOFQUEUEINFO                                             255u
#define CSM_NO_JOBPOOLENDIDXOFQUEUEINFO                                                             255u
#define CSM_NO_JOBPOOLPARTITIONIDXOFQUEUEINFO                                                       255u
#define CSM_NO_JOBPOOLSTARTIDXOFQUEUEINFO                                                           255u
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCMaskedBitDefines  Csm Masked Bit Defines (PRE_COMPILE)
  \brief  These defines are masks to extract packed boolean data.
  \{
*/ 
#define CSM_ASYNCHRONOUSOFJOBTABLE_MASK                                                             0x02u
#define CSM_PRIMITIVECALLBACKUPDATENOTIFICATIONOFJOBTABLE_MASK                                      0x01u
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCIsReducedToDefineDefines  Csm Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CSM_ISDEF_CALLBACKFUNC43OFBSWCALLBACKS                                                      STD_OFF
#define CSM_ISDEF_CALLBACKFUNC44OFBSWCALLBACKS                                                      STD_OFF
#define CSM_ISDEF_CALLBACKFUNC45OFBSWCALLBACKS                                                      STD_OFF
#define CSM_ISDEF_CALLBACKFUNC46OFBSWCALLBACKS                                                      STD_OFF
#define CSM_ISDEF_POSTJOBCALLOUTFUNCOFCALLOUT                                                       STD_OFF
#define CSM_ISDEF_PREJOBCALLOUTFUNCOFCALLOUT                                                        STD_OFF
#define CSM_ISDEF_CALLOUTIDXOFCALLOUTINFO                                                           STD_OFF
#define CSM_ISDEF_JOBTABLEIDXOFCALLOUTINFO                                                          STD_OFF
#define CSM_ISDEF_INPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                       STD_OFF
#define CSM_ISDEF_INPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                              STD_OFF
#define CSM_ISDEF_OUTPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                      STD_OFF
#define CSM_ISDEF_OUTPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                             STD_OFF
#define CSM_ISDEF_REDIRECTIONCONFIGVALUEOFINOUTJOBREDIRECTIONTABLE                                  STD_OFF
#define CSM_ISDEF_SECONDARYINPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                              STD_OFF
#define CSM_ISDEF_SECONDARYINPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                     STD_OFF
#define CSM_ISDEF_SECONDARYOUTPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                             STD_OFF
#define CSM_ISDEF_SECONDARYOUTPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                    STD_OFF
#define CSM_ISDEF_TERTIARYINPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                               STD_OFF
#define CSM_ISDEF_TERTIARYINPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                      STD_OFF
#define CSM_ISDEF_INOUTJOBREDIRECTIONTABLEIDXOFINOUTREDIRECTIONMAP                                  STD_OFF
#define CSM_ISDEF_INVALIDHNDOFINOUTREDIRECTIONMAP                                                   STD_OFF
#define CSM_ISDEF_JOBINFO                                                                           STD_OFF
#define CSM_ISDEF_JOBPRIMITIVEINFO                                                                  STD_OFF
#define CSM_ISDEF_ASYNCHRONOUSOFJOBTABLE                                                            STD_OFF
#define CSM_ISDEF_BSWCALLBACKSIDXOFJOBTABLE                                                         STD_OFF
#define CSM_ISDEF_BSWCALLBACKSUSEDOFJOBTABLE                                                        STD_OFF
#define CSM_ISDEF_CALLOUTINFOIDXOFJOBTABLE                                                          STD_OFF
#define CSM_ISDEF_CALLOUTINFOUSEDOFJOBTABLE                                                         STD_OFF
#define CSM_ISDEF_CSMKEYIDIDXOFJOBTABLE                                                             STD_OFF
#define CSM_ISDEF_INOUTREDIRECTIONMAPIDXOFJOBTABLE                                                  STD_OFF
#define CSM_ISDEF_INOUTREDIRECTIONMAPUSEDOFJOBTABLE                                                 STD_OFF
#define CSM_ISDEF_JOBIDXOFJOBTABLE                                                                  STD_OFF
#define CSM_ISDEF_JOBINFOIDXOFJOBTABLE                                                              STD_OFF
#define CSM_ISDEF_JOBPARTITIONIDXOFJOBTABLE                                                         STD_OFF
#define CSM_ISDEF_JOBPRIMITIVEINFOIDXOFJOBTABLE                                                     STD_OFF
#define CSM_ISDEF_JOBUSEDOFJOBTABLE                                                                 STD_OFF
#define CSM_ISDEF_MASKEDBITSOFJOBTABLE                                                              STD_OFF
#define CSM_ISDEF_PRIMITIVECALLBACKUPDATENOTIFICATIONOFJOBTABLE                                     STD_OFF
#define CSM_ISDEF_PRIORITYOFJOBTABLE                                                                STD_OFF
#define CSM_ISDEF_QUEUEINFOIDXOFJOBTABLE                                                            STD_OFF
#define CSM_ISDEF_RTECALLBACKIDXOFJOBTABLE                                                          STD_OFF
#define CSM_ISDEF_RTECALLBACKPARTITIONIDXOFJOBTABLE                                                 STD_OFF
#define CSM_ISDEF_RTECALLBACKUSEDOFJOBTABLE                                                         STD_OFF
#define CSM_ISDEF_CRYIFKEYIDOFKEY                                                                   STD_OFF
#define CSM_ISDEF_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                        STD_OFF
#define CSM_ISDEF_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                STD_OFF
#define CSM_ISDEF_PRIMITIVEINFO                                                                     STD_OFF
#define CSM_ISDEF_CHANNELIDOFQUEUEINFO                                                              STD_OFF
#define CSM_ISDEF_JOBOBJSYNCHRONOUSIDXOFQUEUEINFO                                                   STD_OFF
#define CSM_ISDEF_JOBOBJSYNCHRONOUSPARTITIONIDXOFQUEUEINFO                                          STD_OFF
#define CSM_ISDEF_JOBOBJSYNCHRONOUSUSEDOFQUEUEINFO                                                  STD_OFF
#define CSM_ISDEF_JOBPOOLENDIDXOFQUEUEINFO                                                          STD_OFF
#define CSM_ISDEF_JOBPOOLPARTITIONIDXOFQUEUEINFO                                                    STD_OFF
#define CSM_ISDEF_JOBPOOLSTARTIDXOFQUEUEINFO                                                        STD_OFF
#define CSM_ISDEF_JOBPOOLUSEDOFQUEUEINFO                                                            STD_OFF
#define CSM_ISDEF_JOBSHARINGOFQUEUEINFO                                                             STD_OFF
#define CSM_ISDEF_OPERATIONMODELIMITATIONOFQUEUEINFO                                                STD_OFF
#define CSM_ISDEF_PARTITIONCONFIGIDXOFQUEUEINFO                                                     STD_OFF
#define CSM_ISDEF_PROCESSINGMODEOFQUEUEINFO                                                         STD_OFF
#define CSM_ISDEF_QUEUEENDIDXOFQUEUEINFO                                                            STD_OFF
#define CSM_ISDEF_QUEUESTARTIDXOFQUEUEINFO                                                          STD_OFF
#define CSM_ISDEF_TRIGGERASYNCHJOBSINCALLBACKOFQUEUEINFO                                            STD_OFF
#define CSM_ISDEF_RTECALLBACK                                                                       STD_OFF
#define CSM_ISDEF_FINALMAGICNUMBEROFPCCONFIG                                                        STD_OFF
#define CSM_ISDEF_INITDATAHASHCODEOFPCCONFIG                                                        STD_OFF
#define CSM_ISDEF_PCPARTITIONCONFIGOFPCCONFIG                                                       STD_ON
#define CSM_ISDEF_PARTITIONIDENTIFIERSOFPCCONFIG                                                    STD_ON
#define CSM_ISDEF_BSWCALLBACKSOFPCPARTITIONCONFIG                                                   STD_ON
#define CSM_ISDEF_EXPECTEDCOMPATIBILITYVERSIONOFPCPARTITIONCONFIG                                   STD_OFF
#define CSM_ISDEF_GENERATORCOMPATIBILITYVERSIONOFPCPARTITIONCONFIG                                  STD_OFF
#define CSM_ISDEF_JOBINFOOFPCPARTITIONCONFIG                                                        STD_ON
#define CSM_ISDEF_JOBOFPCPARTITIONCONFIG                                                            STD_ON
#define CSM_ISDEF_JOBPRIMITIVEINFOOFPCPARTITIONCONFIG                                               STD_ON
#define CSM_ISDEF_JOBSTATEOFPCPARTITIONCONFIG                                                       STD_ON
#define CSM_ISDEF_JOBTABLEOFPCPARTITIONCONFIG                                                       STD_ON
#define CSM_ISDEF_JOBTOOBJMAPOFPCPARTITIONCONFIG                                                    STD_ON
#define CSM_ISDEF_KEYOFPCPARTITIONCONFIG                                                            STD_ON
#define CSM_ISDEF_PARTITIONDATAINITIALIZEDOFPCPARTITIONCONFIG                                       STD_ON
#define CSM_ISDEF_PRIMITIVEINFOOFPCPARTITIONCONFIG                                                  STD_ON
#define CSM_ISDEF_QUEUEINFOOFPCPARTITIONCONFIG                                                      STD_ON
#define CSM_ISDEF_QUEUEOFPCPARTITIONCONFIG                                                          STD_ON
#define CSM_ISDEF_QUEUESTATEOFPCPARTITIONCONFIG                                                     STD_ON
#define CSM_ISDEF_SWCUSEERRORCODESPREFIXOFGENERALOFPCPARTITIONCONFIG                                STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCEqualsAlwaysToDefines  Csm Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CSM_EQ2_CALLBACKFUNC43OFBSWCALLBACKS                                                        
#define CSM_EQ2_CALLBACKFUNC44OFBSWCALLBACKS                                                        
#define CSM_EQ2_CALLBACKFUNC45OFBSWCALLBACKS                                                        
#define CSM_EQ2_CALLBACKFUNC46OFBSWCALLBACKS                                                        
#define CSM_EQ2_POSTJOBCALLOUTFUNCOFCALLOUT                                                         
#define CSM_EQ2_PREJOBCALLOUTFUNCOFCALLOUT                                                          
#define CSM_EQ2_CALLOUTIDXOFCALLOUTINFO                                                             
#define CSM_EQ2_JOBTABLEIDXOFCALLOUTINFO                                                            
#define CSM_EQ2_INPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                         
#define CSM_EQ2_INPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                                
#define CSM_EQ2_OUTPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                        
#define CSM_EQ2_OUTPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                               
#define CSM_EQ2_REDIRECTIONCONFIGVALUEOFINOUTJOBREDIRECTIONTABLE                                    
#define CSM_EQ2_SECONDARYINPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                
#define CSM_EQ2_SECONDARYINPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                       
#define CSM_EQ2_SECONDARYOUTPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                               
#define CSM_EQ2_SECONDARYOUTPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                      
#define CSM_EQ2_TERTIARYINPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                 
#define CSM_EQ2_TERTIARYINPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                        
#define CSM_EQ2_INOUTJOBREDIRECTIONTABLEIDXOFINOUTREDIRECTIONMAP                                    
#define CSM_EQ2_INVALIDHNDOFINOUTREDIRECTIONMAP                                                     
#define CSM_EQ2_JOBINFO                                                                             
#define CSM_EQ2_JOBPRIMITIVEINFO                                                                    
#define CSM_EQ2_ASYNCHRONOUSOFJOBTABLE                                                              
#define CSM_EQ2_BSWCALLBACKSIDXOFJOBTABLE                                                           
#define CSM_EQ2_BSWCALLBACKSUSEDOFJOBTABLE                                                          
#define CSM_EQ2_CALLOUTINFOIDXOFJOBTABLE                                                            
#define CSM_EQ2_CALLOUTINFOUSEDOFJOBTABLE                                                           
#define CSM_EQ2_CSMKEYIDIDXOFJOBTABLE                                                               
#define CSM_EQ2_INOUTREDIRECTIONMAPIDXOFJOBTABLE                                                    
#define CSM_EQ2_INOUTREDIRECTIONMAPUSEDOFJOBTABLE                                                   
#define CSM_EQ2_JOBIDXOFJOBTABLE                                                                    
#define CSM_EQ2_JOBINFOIDXOFJOBTABLE                                                                
#define CSM_EQ2_JOBPARTITIONIDXOFJOBTABLE                                                           
#define CSM_EQ2_JOBPRIMITIVEINFOIDXOFJOBTABLE                                                       
#define CSM_EQ2_JOBUSEDOFJOBTABLE                                                                   
#define CSM_EQ2_MASKEDBITSOFJOBTABLE                                                                
#define CSM_EQ2_PRIMITIVECALLBACKUPDATENOTIFICATIONOFJOBTABLE                                       
#define CSM_EQ2_PRIORITYOFJOBTABLE                                                                  
#define CSM_EQ2_QUEUEINFOIDXOFJOBTABLE                                                              
#define CSM_EQ2_RTECALLBACKIDXOFJOBTABLE                                                            
#define CSM_EQ2_RTECALLBACKPARTITIONIDXOFJOBTABLE                                                   
#define CSM_EQ2_RTECALLBACKUSEDOFJOBTABLE                                                           
#define CSM_EQ2_CRYIFKEYIDOFKEY                                                                     
#define CSM_EQ2_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                          
#define CSM_EQ2_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                  
#define CSM_EQ2_PRIMITIVEINFO                                                                       
#define CSM_EQ2_CHANNELIDOFQUEUEINFO                                                                
#define CSM_EQ2_JOBOBJSYNCHRONOUSIDXOFQUEUEINFO                                                     
#define CSM_EQ2_JOBOBJSYNCHRONOUSPARTITIONIDXOFQUEUEINFO                                            
#define CSM_EQ2_JOBOBJSYNCHRONOUSUSEDOFQUEUEINFO                                                    
#define CSM_EQ2_JOBPOOLENDIDXOFQUEUEINFO                                                            
#define CSM_EQ2_JOBPOOLPARTITIONIDXOFQUEUEINFO                                                      
#define CSM_EQ2_JOBPOOLSTARTIDXOFQUEUEINFO                                                          
#define CSM_EQ2_JOBPOOLUSEDOFQUEUEINFO                                                              
#define CSM_EQ2_JOBSHARINGOFQUEUEINFO                                                               
#define CSM_EQ2_OPERATIONMODELIMITATIONOFQUEUEINFO                                                  
#define CSM_EQ2_PARTITIONCONFIGIDXOFQUEUEINFO                                                       
#define CSM_EQ2_PROCESSINGMODEOFQUEUEINFO                                                           
#define CSM_EQ2_QUEUEENDIDXOFQUEUEINFO                                                              
#define CSM_EQ2_QUEUESTARTIDXOFQUEUEINFO                                                            
#define CSM_EQ2_TRIGGERASYNCHJOBSINCALLBACKOFQUEUEINFO                                              
#define CSM_EQ2_RTECALLBACK                                                                         
#define CSM_EQ2_FINALMAGICNUMBEROFPCCONFIG                                                          
#define CSM_EQ2_INITDATAHASHCODEOFPCCONFIG                                                          
#define CSM_EQ2_PCPARTITIONCONFIGOFPCCONFIG                                                         Csm_PCPartitionConfig
#define CSM_EQ2_PARTITIONIDENTIFIERSOFPCCONFIG                                                      Csm_PartitionIdentifiers
#define CSM_EQ2_BSWCALLBACKSOFPCPARTITIONCONFIG                                                     Csm_BswCallbacks
#define CSM_EQ2_EXPECTEDCOMPATIBILITYVERSIONOFPCPARTITIONCONFIG                                     
#define CSM_EQ2_GENERATORCOMPATIBILITYVERSIONOFPCPARTITIONCONFIG                                    
#define CSM_EQ2_JOBINFOOFPCPARTITIONCONFIG                                                          Csm_JobInfo
#define CSM_EQ2_JOBOFPCPARTITIONCONFIG                                                              Csm_Job
#define CSM_EQ2_JOBPRIMITIVEINFOOFPCPARTITIONCONFIG                                                 Csm_JobPrimitiveInfo
#define CSM_EQ2_JOBSTATEOFPCPARTITIONCONFIG                                                         Csm_JobState
#define CSM_EQ2_JOBTABLEOFPCPARTITIONCONFIG                                                         Csm_JobTable
#define CSM_EQ2_JOBTOOBJMAPOFPCPARTITIONCONFIG                                                      Csm_JobToObjMap
#define CSM_EQ2_KEYOFPCPARTITIONCONFIG                                                              Csm_Key
#define CSM_EQ2_PARTITIONDATAINITIALIZEDOFPCPARTITIONCONFIG                                         (&(Csm_PartitionDataInitialized))
#define CSM_EQ2_PRIMITIVEINFOOFPCPARTITIONCONFIG                                                    Csm_PrimitiveInfo
#define CSM_EQ2_QUEUEINFOOFPCPARTITIONCONFIG                                                        Csm_QueueInfo
#define CSM_EQ2_QUEUEOFPCPARTITIONCONFIG                                                            Csm_Queue.raw
#define CSM_EQ2_QUEUESTATEOFPCPARTITIONCONFIG                                                       Csm_QueueState
#define CSM_EQ2_SWCUSEERRORCODESPREFIXOFGENERALOFPCPARTITIONCONFIG                                  
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCSymbolicInitializationPointers  Csm Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Csm_Config_Ptr                                                                              NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Csm' */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCInitializationSymbols  Csm Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Csm_Config                                                                                  NULL_PTR  /**< symbolic identifier which could be used to initialize 'Csm */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCGeneral  Csm General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CSM_CHECK_INIT_POINTER                                                                      STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CSM_FINAL_MAGIC_NUMBER                                                                      0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of Csm */
#define CSM_INDIVIDUAL_POSTBUILD                                                                    STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Csm' is not configured to be postbuild capable. */
#define CSM_INIT_DATA                                                                               CSM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CSM_INIT_DATA_HASH_CODE                                                                     842809845  /**< the precompile constant to validate the initialization structure at initialization time of Csm with a hashcode. The seed value is '0xFF1Eu' */
#define CSM_USE_ECUM_BSW_ERROR_HOOK                                                                 STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CSM_USE_INIT_POINTER                                                                        STD_OFF  /**< STD_ON if the init pointer Csm shall be used. */
#define Csm_PartitionIndexOfCSLForCSM_SINGLE_PARTITION                                              0u  /**< internal partition index of the ComStackLib for the partition CSM_SINGLE_PARTITION */
/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CsmPBDataSwitches  Csm Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CSM_PBCONFIG                                                                                STD_OFF  /**< Deactivateable: 'Csm_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CSM_LTCONFIGIDXOFPBCONFIG                                                                   STD_OFF  /**< Deactivateable: 'Csm_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CSM_PBPARTITIONCONFIGOFPBCONFIG                                                             STD_OFF  /**< Deactivateable: 'Csm_PBConfig.PBPartitionConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CSM_PCCONFIGIDXOFPBCONFIG                                                                   STD_OFF  /**< Deactivateable: 'Csm_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CSM_PBPARTITIONCONFIG                                                                       STD_OFF  /**< Deactivateable: 'Csm_PBPartitionConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPBIsReducedToDefineDefines  Csm Is Reduced To Define Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CSM_ISDEF_LTCONFIGIDXOFPBCONFIG                                                             STD_OFF
#define CSM_ISDEF_PBPARTITIONCONFIGOFPBCONFIG                                                       STD_OFF
#define CSM_ISDEF_PCCONFIGIDXOFPBCONFIG                                                             STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  CsmPBEqualsAlwaysToDefines  Csm Equals Always To Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CSM_EQ2_LTCONFIGIDXOFPBCONFIG                                                               
#define CSM_EQ2_PBPARTITIONCONFIGOFPBCONFIG                                                         
#define CSM_EQ2_PCCONFIGIDXOFPBCONFIG                                                               
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
  \defgroup  CsmPCGetRootDataMacros  Csm Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Csm_GetFinalMagicNumberOfPCConfig()                                                           /**< Deactivateable: 'Csm_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Csm_GetInitDataHashCodeOfPCConfig()                                                           /**< Deactivateable: 'Csm_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Csm_GetExpectedCompatibilityVersionOfPCPartitionConfig(partitionIndex)                        /**< Deactivateable: 'Csm_PCPartitionConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Csm_GetGeneratorCompatibilityVersionOfPCPartitionConfig(partitionIndex)                       /**< Deactivateable: 'Csm_PCPartitionConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Csm_IsSwcUseErrorCodesPrefixOfGeneralOfPCPartitionConfig(partitionIndex)                      /**< Deactivateable: 'Csm_PCPartitionConfig.SwcUseErrorCodesPrefixOfGeneral' Reason: 'Parameter is not configured!' */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCGetConstantDuplicatedRootDataMacros  Csm Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Csm_GetPCPartitionConfigOfPCConfig()                                                          /**< PartitionConfig is empty */
#define Csm_GetPartitionIdentifiersOfPCConfig()                                                     Csm_PartitionIdentifiers  /**< the pointer to Csm_PartitionIdentifiers */
#define Csm_GetSizeOfPartitionIdentifiersOfPCConfig()                                               1u  /**< the number of accomplishable value elements in Csm_PartitionIdentifiers */
#define Csm_GetAsymPrivateKeyMaxLengthOfGeneralOfPCPartitionConfig(partitionIndex)                  32u
#define Csm_GetAsymPublicKeyMaxLengthOfGeneralOfPCPartitionConfig(partitionIndex)                   1024u
#define Csm_GetBswCallbacksOfPCPartitionConfig()                                                    Csm_BswCallbacks  /**< the pointer to Csm_BswCallbacks */
#define Csm_IsCallbackStartNotificationOfGeneralOfPCPartitionConfig(partitionIndex)                 (((FALSE)) != FALSE)
#define Csm_IsCancelationDuringProcessingOfGeneralOfPCPartitionConfig(partitionIndex)               (((FALSE)) != FALSE)
#define Csm_GetJobInfoOfPCPartitionConfig()                                                         Csm_JobInfo  /**< the pointer to Csm_JobInfo */
#define Csm_GetJobOfPCPartitionConfig(partitionIndex)                                               Csm_Job  /**< the pointer to Csm_Job */
#define Csm_GetJobPrimitiveInfoOfPCPartitionConfig()                                                Csm_JobPrimitiveInfo  /**< the pointer to Csm_JobPrimitiveInfo */
#define Csm_GetJobStateOfPCPartitionConfig(partitionIndex)                                          Csm_JobState  /**< the pointer to Csm_JobState */
#define Csm_GetJobTableOfPCPartitionConfig()                                                        Csm_JobTable  /**< the pointer to Csm_JobTable */
#define Csm_GetJobToObjMapOfPCPartitionConfig(partitionIndex)                                       Csm_JobToObjMap  /**< the pointer to Csm_JobToObjMap */
#define Csm_GetKeyOfPCPartitionConfig()                                                             Csm_Key  /**< the pointer to Csm_Key */
#define Csm_IsMultiPartitionRuntimeChecksOfGeneralOfPCPartitionConfig(partitionIndex)               (((FALSE)) != FALSE)
#define Csm_GetPartitionDataInitializedOfPCPartitionConfig(partitionIndex)                          (&(Csm_PartitionDataInitialized))  /**< the pointer to Csm_PartitionDataInitialized */
#define Csm_GetPrimitiveInfoOfPCPartitionConfig()                                                   Csm_PrimitiveInfo  /**< the pointer to Csm_PrimitiveInfo */
#define Csm_GetQueueInfoOfPCPartitionConfig()                                                       Csm_QueueInfo  /**< the pointer to Csm_QueueInfo */
#define Csm_GetQueueOfPCPartitionConfig(partitionIndex)                                             Csm_Queue.raw  /**< the pointer to Csm_Queue */
#define Csm_GetQueueStateOfPCPartitionConfig(partitionIndex)                                        Csm_QueueState  /**< the pointer to Csm_QueueState */
#define Csm_GetSizeOfBswCallbacksOfPCPartitionConfig()                                              1u  /**< the number of accomplishable value elements in Csm_BswCallbacks */
#define Csm_GetSizeOfJobInfoOfPCPartitionConfig()                                                   51u  /**< the number of accomplishable value elements in Csm_JobInfo */
#define Csm_GetSizeOfJobOfPCPartitionConfig(partitionIndex)                                         12u  /**< the number of accomplishable value elements in Csm_Job */
#define Csm_GetSizeOfJobPrimitiveInfoOfPCPartitionConfig()                                          48u  /**< the number of accomplishable value elements in Csm_JobPrimitiveInfo */
#define Csm_GetSizeOfJobTableOfPCPartitionConfig()                                                  51u  /**< the number of accomplishable value elements in Csm_JobTable */
#define Csm_GetSizeOfKeyOfPCPartitionConfig()                                                       62u  /**< the number of accomplishable value elements in Csm_Key */
#define Csm_GetSizeOfPrimitiveInfoOfPCPartitionConfig()                                             37u  /**< the number of accomplishable value elements in Csm_PrimitiveInfo */
#define Csm_GetSizeOfQueueInfoOfPCPartitionConfig()                                                 7u  /**< the number of accomplishable value elements in Csm_QueueInfo */
#define Csm_GetSizeOfQueueOfPCPartitionConfig(partitionIndex)                                       12u  /**< the number of accomplishable value elements in Csm_Queue */
#define Csm_GetSymKeyMaxLengthOfGeneralOfPCPartitionConfig(partitionIndex)                          16u
#define Csm_IsUseDeprecatedOfGeneralOfPCPartitionConfig(partitionIndex)                             (((FALSE)) != FALSE)
#define Csm_IsVersionInfoApiOfGeneralOfPCPartitionConfig(partitionIndex)                            (((FALSE)) != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCGetDuplicatedRootDataMacros  Csm Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define Csm_GetSizeOfJobStateOfPCPartitionConfig(partitionIndex)                                    Csm_GetSizeOfJobTableOfPCPartitionConfig()  /**< the number of accomplishable value elements in Csm_JobState */
#define Csm_GetSizeOfJobToObjMapOfPCPartitionConfig(partitionIndex)                                 Csm_GetSizeOfJobTableOfPCPartitionConfig()  /**< the number of accomplishable value elements in Csm_JobToObjMap */
#define Csm_GetSizeOfQueueStateOfPCPartitionConfig(partitionIndex)                                  Csm_GetSizeOfQueueInfoOfPCPartitionConfig()  /**< the number of accomplishable value elements in Csm_QueueState */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCGetDataMacros  Csm Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Csm_GetCallbackFunc43OfBswCallbacks(Index)                                                    /**< Deactivateable: 'Csm_BswCallbacks.CallbackFunc43' Reason: 'No Callback according to ASR 4.3 is configured' */
#define Csm_GetCallbackFunc44OfBswCallbacks(Index)                                                    /**< Deactivateable: 'Csm_BswCallbacks.CallbackFunc44' Reason: 'No Callback according to ASR 4.4 is configured' */
#define Csm_GetCallbackFunc45OfBswCallbacks(Index)                                                    /**< Deactivateable: 'Csm_BswCallbacks.CallbackFunc45' Reason: 'No Callback according to ASR R19-11/4.5 is configured' */
#define Csm_GetCallbackFunc46OfBswCallbacks(Index)                                                  (Csm_GetBswCallbacksOfPCPartitionConfig()[(Index)].CallbackFunc46OfBswCallbacks)
#define Csm_GetPostJobCalloutFuncOfCallout(Index)                                                     /**< Deactivateable: 'Csm_Callout.PostJobCalloutFunc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_GetPreJobCalloutFuncOfCallout(Index)                                                      /**< Deactivateable: 'Csm_Callout.PreJobCalloutFunc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_GetCalloutIdxOfCalloutInfo(Index)                                                         /**< Deactivateable: 'Csm_CalloutInfo.CalloutIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_GetJobTableIdxOfCalloutInfo(Index)                                                        /**< Deactivateable: 'Csm_CalloutInfo.JobTableIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_GetCalloutStateOfCalloutState(Index, partitionIndex)                                      /**< Deactivateable: 'Csm_CalloutState.CalloutState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define Csm_GetInputKeyElementIdOfInOutJobRedirectionTable(Index)                                     /**< Deactivateable: 'Csm_InOutJobRedirectionTable.InputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_GetInputKeyIdOfInOutJobRedirectionTable(Index)                                            /**< Deactivateable: 'Csm_InOutJobRedirectionTable.InputKeyId' Reason: 'Not enabled for any job' */
#define Csm_GetOutputKeyElementIdOfInOutJobRedirectionTable(Index)                                    /**< Deactivateable: 'Csm_InOutJobRedirectionTable.OutputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_GetOutputKeyIdOfInOutJobRedirectionTable(Index)                                           /**< Deactivateable: 'Csm_InOutJobRedirectionTable.OutputKeyId' Reason: 'Not enabled for any job' */
#define Csm_GetRedirectionConfigValueOfInOutJobRedirectionTable(Index)                                /**< Deactivateable: 'Csm_InOutJobRedirectionTable.RedirectionConfigValue' Reason: 'Not enabled for any job' */
#define Csm_GetSecondaryInputKeyElementIdOfInOutJobRedirectionTable(Index)                            /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryInputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_GetSecondaryInputKeyIdOfInOutJobRedirectionTable(Index)                                   /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryInputKeyId' Reason: 'Not enabled for any job' */
#define Csm_GetSecondaryOutputKeyElementIdOfInOutJobRedirectionTable(Index)                           /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryOutputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_GetSecondaryOutputKeyIdOfInOutJobRedirectionTable(Index)                                  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryOutputKeyId' Reason: 'Not enabled for any job' */
#define Csm_GetTertiaryInputKeyElementIdOfInOutJobRedirectionTable(Index)                             /**< Deactivateable: 'Csm_InOutJobRedirectionTable.TertiaryInputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_GetTertiaryInputKeyIdOfInOutJobRedirectionTable(Index)                                    /**< Deactivateable: 'Csm_InOutJobRedirectionTable.TertiaryInputKeyId' Reason: 'Not enabled for any job' */
#define Csm_GetInOutRedirection(Index, partitionIndex)                                                /**< Deactivateable: 'Csm_InOutRedirection' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_GetInOutJobRedirectionTableIdxOfInOutRedirectionMap(Index, partitionIndex)                /**< Deactivateable: 'Csm_InOutRedirectionMap.InOutJobRedirectionTableIdx' Reason: 'Not enabled for any job' */
#define Csm_IsInvalidHndOfInOutRedirectionMap(Index, partitionIndex)                                  /**< Deactivateable: 'Csm_InOutRedirectionMap.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'Csm_InOutRedirectionMap.InvalidHnd' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Csm_GetJob(Index, partitionIndex)                                                           (Csm_GetJobOfPCPartitionConfig(partitionIndex)[(Index)])
#define Csm_GetJobInfo(Index)                                                                       (Csm_GetJobInfoOfPCPartitionConfig()[(Index)])
#define Csm_GetJobPrimitiveInfo(Index)                                                              (Csm_GetJobPrimitiveInfoOfPCPartitionConfig()[(Index)])
#define Csm_GetJobState(Index, partitionIndex)                                                      (Csm_GetJobStateOfPCPartitionConfig(partitionIndex)[(Index)])
#define Csm_GetBswCallbacksIdxOfJobTable(Index)                                                     (Csm_GetJobTableOfPCPartitionConfig()[(Index)].BswCallbacksIdxOfJobTable)
#define Csm_GetCalloutInfoIdxOfJobTable(Index)                                                        /**< Deactivateable: 'Csm_JobTable.CalloutInfoIdx' Reason: 'the optional indirection is deactivated because CalloutInfoUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_IsCalloutInfoUsedOfJobTable(Index)                                                        /**< Deactivateable: 'Csm_JobTable.CalloutInfoUsed' Reason: 'the optional indirection is deactivated because CalloutInfoUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_GetCsmKeyIdIdxOfJobTable(Index)                                                         (Csm_GetJobTableOfPCPartitionConfig()[(Index)].CsmKeyIdIdxOfJobTable)
#define Csm_GetInOutRedirectionMapIdxOfJobTable(Index)                                                /**< Deactivateable: 'Csm_JobTable.InOutRedirectionMapIdx' Reason: 'the optional indirection is deactivated because InOutRedirectionMapUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_IsInOutRedirectionMapUsedOfJobTable(Index)                                                /**< Deactivateable: 'Csm_JobTable.InOutRedirectionMapUsed' Reason: 'the optional indirection is deactivated because InOutRedirectionMapUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_GetJobIdxOfJobTable(Index)                                                                /**< Deactivateable: 'Csm_JobTable.JobIdx' Reason: 'the optional indirection is deactivated because JobUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_GetJobPrimitiveInfoIdxOfJobTable(Index)                                                 (Csm_GetJobTableOfPCPartitionConfig()[(Index)].JobPrimitiveInfoIdxOfJobTable)
#define Csm_IsJobUsedOfJobTable(Index)                                                                /**< Deactivateable: 'Csm_JobTable.JobUsed' Reason: 'the optional indirection is deactivated because JobUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_GetMaskedBitsOfJobTable(Index)                                                          (Csm_GetJobTableOfPCPartitionConfig()[(Index)].MaskedBitsOfJobTable)
#define Csm_GetPriorityOfJobTable(Index)                                                            (Csm_GetJobTableOfPCPartitionConfig()[(Index)].PriorityOfJobTable)
#define Csm_GetQueueInfoIdxOfJobTable(Index)                                                        (Csm_GetJobTableOfPCPartitionConfig()[(Index)].QueueInfoIdxOfJobTable)
#define Csm_GetRteCallbackIdxOfJobTable(Index)                                                        /**< Deactivateable: 'Csm_JobTable.RteCallbackIdx' Reason: 'No RTE Callback is configured' */
#define Csm_IsRteCallbackUsedOfJobTable(Index)                                                        /**< Deactivateable: 'Csm_JobTable.RteCallbackUsed' Reason: 'No RTE Callback is configured' */
#define Csm_GetJobToObjMap(Index, partitionIndex)                                                   (Csm_GetJobToObjMapOfPCPartitionConfig(partitionIndex)[(Index)])
#define Csm_GetCryIfKeyIdOfKey(Index)                                                               (Csm_GetKeyOfPCPartitionConfig()[(Index)].CryIfKeyIdOfKey)
#define Csm_GetPartitionDataInitialized(partitionIndex)                                             ((*(Csm_GetPartitionDataInitializedOfPCPartitionConfig(partitionIndex))))
#define Csm_GetPartitionSNVOfPartitionIdentifiers(Index)                                            (Csm_GetPartitionIdentifiersOfPCConfig()[(Index)].PartitionSNVOfPartitionIdentifiers)
#define Csm_GetPrimitiveInfo(Index)                                                                 (Csm_GetPrimitiveInfoOfPCPartitionConfig()[(Index)])
#define Csm_GetQueue(Index, partitionIndex)                                                         (Csm_GetQueueOfPCPartitionConfig(partitionIndex)[(Index)])
#define Csm_GetChannelIdOfQueueInfo(Index)                                                          (Csm_GetQueueInfoOfPCPartitionConfig()[(Index)].ChannelIdOfQueueInfo)
#define Csm_GetJobObjSynchronousIdxOfQueueInfo(Index)                                               (Csm_GetQueueInfoOfPCPartitionConfig()[(Index)].JobObjSynchronousIdxOfQueueInfo)
#define Csm_GetJobPoolPartitionIdxOfQueueInfo(Index)                                                (Csm_GetQueueInfoOfPCPartitionConfig()[(Index)].JobPoolPartitionIdxOfQueueInfo)
#define Csm_IsJobSharingOfQueueInfo(Index)                                                          ((Csm_GetQueueInfoOfPCPartitionConfig()[(Index)].JobSharingOfQueueInfo) != FALSE)
#define Csm_IsOperationModeLimitationOfQueueInfo(Index)                                               /**< Deactivateable: 'Csm_QueueInfo.OperationModeLimitation' Reason: 'the value of Csm_OperationModeLimitationOfQueueInfo is always 'false' due to this, the array is deactivated.' */
#define Csm_GetProcessingModeOfQueueInfo(Index)                                                     (Csm_GetQueueInfoOfPCPartitionConfig()[(Index)].ProcessingModeOfQueueInfo)
#define Csm_GetQueueEndIdxOfQueueInfo(Index)                                                        (Csm_GetQueueInfoOfPCPartitionConfig()[(Index)].QueueEndIdxOfQueueInfo)
#define Csm_IsTriggerAsynchJobsInCallbackOfQueueInfo(Index)                                           /**< Deactivateable: 'Csm_QueueInfo.TriggerAsynchJobsInCallback' Reason: 'Not enabled for any of the queues.' */
#define Csm_GetLockOfQueueState(Index, partitionIndex)                                              (Csm_GetQueueStateOfPCPartitionConfig(partitionIndex)[(Index)].LockOfQueueState)
#define Csm_GetQueueIdxOfQueueState(Index, partitionIndex)                                          (Csm_GetQueueStateOfPCPartitionConfig(partitionIndex)[(Index)].QueueIdxOfQueueState)
#define Csm_GetRetriggeringOfQueueState(Index, partitionIndex)                                        /**< Deactivateable: 'Csm_QueueState.Retriggering' Reason: 'Not enabled for any of the queues.' */
#define Csm_GetRteCallback(Index, partitionIndex)                                                     /**< Deactivateable: 'Csm_RteCallback' Reason: 'No RTE Callback is configured' */
#define Csm_IsRteCallbackOccurred(partitionIndex)                                                     /**< Deactivateable: 'Csm_RteCallbackOccurred' Reason: 'No RTE Callback is configured' */
#define Csm_GetRteResult(Index, partitionIndex)                                                       /**< Deactivateable: 'Csm_RteResult' Reason: 'No RTE Callback is configured' */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCGetBitDataMacros  Csm Get Bit Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read bitcoded data elements.
  \{
*/ 
#define Csm_IsAsynchronousOfJobTable(Index)                                                         (CSM_ASYNCHRONOUSOFJOBTABLE_MASK == (Csm_GetMaskedBitsOfJobTable(Index) & CSM_ASYNCHRONOUSOFJOBTABLE_MASK))
#define Csm_IsPrimitiveCallbackUpdateNotificationOfJobTable(Index)                                  (CSM_PRIMITIVECALLBACKUPDATENOTIFICATIONOFJOBTABLE_MASK == (Csm_GetMaskedBitsOfJobTable(Index) & CSM_PRIMITIVECALLBACKUPDATENOTIFICATIONOFJOBTABLE_MASK))  /**< Contains values of DefinitionRef: /MICROSAR/Csm/CsmJobs/CsmJob/CsmJobPrimitiveCallbackUpdateNotification. */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCGetDeduplicatedDataMacros  Csm Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Csm_GetAsymPrivateKeyMaxLengthOfGeneral(partitionIndex)                                     Csm_GetAsymPrivateKeyMaxLengthOfGeneralOfPCPartitionConfig(partitionIndex)
#define Csm_GetAsymPublicKeyMaxLengthOfGeneral(partitionIndex)                                      Csm_GetAsymPublicKeyMaxLengthOfGeneralOfPCPartitionConfig(partitionIndex)
#define Csm_IsCallbackStartNotificationOfGeneral(partitionIndex)                                    Csm_IsCallbackStartNotificationOfGeneralOfPCPartitionConfig(partitionIndex)
#define Csm_IsCancelationDuringProcessingOfGeneral(partitionIndex)                                  Csm_IsCancelationDuringProcessingOfGeneralOfPCPartitionConfig(partitionIndex)
#define Csm_GetExpectedCompatibilityVersion(partitionIndex)                                           /**< Deactivateable: 'Csm_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Csm_GetFinalMagicNumber()                                                                     /**< Deactivateable: 'Csm_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Csm_GetGeneratorCompatibilityVersion(partitionIndex)                                          /**< Deactivateable: 'Csm_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Csm_GetInitDataHashCode()                                                                     /**< Deactivateable: 'Csm_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Csm_IsBswCallbacksUsedOfJobTable(Index)                                                     (((boolean)(Csm_GetBswCallbacksIdxOfJobTable(Index) != CSM_NO_BSWCALLBACKSIDXOFJOBTABLE)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Csm_BswCallbacks */
#define Csm_GetJobInfoIdxOfJobTable(Index)                                                          ((Csm_JobInfoIdxOfJobTableType)((Index)))  /**< the index of the 1:1 relation pointing to Csm_JobInfo */
#define Csm_GetJobPartitionIdxOfJobTable(Index)                                                     ((Csm_JobPartitionIdxOfJobTableType)((Csm_GetPriorityOfJobTable(Index) + CSM_NO_JOBPARTITIONIDXOFJOBTABLE)))
#define Csm_GetRteCallbackPartitionIdxOfJobTable(Index)                                             ((Csm_RteCallbackPartitionIdxOfJobTableType)((Csm_GetPriorityOfJobTable(Index) + CSM_NO_RTECALLBACKPARTITIONIDXOFJOBTABLE)))
#define Csm_IsMultiPartitionRuntimeChecksOfGeneral(partitionIndex)                                  Csm_IsMultiPartitionRuntimeChecksOfGeneralOfPCPartitionConfig(partitionIndex)
#define Csm_GetPCPartitionConfigIdxOfPartitionIdentifiers(Index)                                    ((Csm_PCPartitionConfigIdxOfPartitionIdentifiersType)((Index)))  /**< the index of the 1:1 relation pointing to Csm_PCPartitionConfig */
#define Csm_GetJobObjSynchronousPartitionIdxOfQueueInfo(Index)                                      Csm_GetJobPoolPartitionIdxOfQueueInfo(Index)
#define Csm_IsJobObjSynchronousUsedOfQueueInfo(Index)                                               (((boolean)(Csm_GetJobObjSynchronousIdxOfQueueInfo(Index) != CSM_NO_JOBOBJSYNCHRONOUSIDXOFQUEUEINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Csm_Job */
#define Csm_GetJobPoolEndIdxOfQueueInfo(Index)                                                      Csm_GetQueueEndIdxOfQueueInfo(Index)  /**< the end index of the 0:n relation pointing to one of Csm_Job */
#define Csm_GetJobPoolStartIdxOfQueueInfo(Index)                                                    Csm_GetJobObjSynchronousIdxOfQueueInfo(Index)  /**< the start index of the 0:n relation pointing to one of Csm_Job */
#define Csm_IsJobPoolUsedOfQueueInfo(Index)                                                         Csm_IsJobSharingOfQueueInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to one of Csm_Job */
#define Csm_GetPartitionConfigIdxOfQueueInfo(Index)                                                 Csm_GetJobPoolPartitionIdxOfQueueInfo(Index)  /**< the index of the 1:1 relation pointing to Csm_PCPartitionConfig */
#define Csm_GetQueueStartIdxOfQueueInfo(Index)                                                      Csm_GetJobObjSynchronousIdxOfQueueInfo(Index)  /**< the start index of the 1:n relation pointing to Csm_Queue */
#define Csm_GetSizeOfBswCallbacks()                                                                 Csm_GetSizeOfBswCallbacksOfPCPartitionConfig()
#define Csm_GetSizeOfJob(partitionIndex)                                                            Csm_GetSizeOfJobOfPCPartitionConfig(partitionIndex)
#define Csm_GetSizeOfJobInfo()                                                                      Csm_GetSizeOfJobInfoOfPCPartitionConfig()
#define Csm_GetSizeOfJobPrimitiveInfo()                                                             Csm_GetSizeOfJobPrimitiveInfoOfPCPartitionConfig()
#define Csm_GetSizeOfJobState(partitionIndex)                                                       Csm_GetSizeOfJobStateOfPCPartitionConfig(partitionIndex)
#define Csm_GetSizeOfJobTable()                                                                     Csm_GetSizeOfJobTableOfPCPartitionConfig()
#define Csm_GetSizeOfJobToObjMap(partitionIndex)                                                    Csm_GetSizeOfJobToObjMapOfPCPartitionConfig(partitionIndex)
#define Csm_GetSizeOfKey()                                                                          Csm_GetSizeOfKeyOfPCPartitionConfig()
#define Csm_GetSizeOfPartitionIdentifiers()                                                         Csm_GetSizeOfPartitionIdentifiersOfPCConfig()
#define Csm_GetSizeOfPrimitiveInfo()                                                                Csm_GetSizeOfPrimitiveInfoOfPCPartitionConfig()
#define Csm_GetSizeOfQueue(partitionIndex)                                                          Csm_GetSizeOfQueueOfPCPartitionConfig(partitionIndex)
#define Csm_GetSizeOfQueueInfo()                                                                    Csm_GetSizeOfQueueInfoOfPCPartitionConfig()
#define Csm_GetSizeOfQueueState(partitionIndex)                                                     Csm_GetSizeOfQueueStateOfPCPartitionConfig(partitionIndex)
#define Csm_IsSwcUseErrorCodesPrefixOfGeneral(partitionIndex)                                         /**< Deactivateable: 'Csm_SwcUseErrorCodesPrefixOfGeneral' Reason: 'Parameter is not configured!' */
#define Csm_GetSymKeyMaxLengthOfGeneral(partitionIndex)                                             Csm_GetSymKeyMaxLengthOfGeneralOfPCPartitionConfig(partitionIndex)
#define Csm_IsUseDeprecatedOfGeneral(partitionIndex)                                                Csm_IsUseDeprecatedOfGeneralOfPCPartitionConfig(partitionIndex)
#define Csm_IsVersionInfoApiOfGeneral(partitionIndex)                                               Csm_IsVersionInfoApiOfGeneralOfPCPartitionConfig(partitionIndex)
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCSetDataMacros  Csm Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define Csm_SetCalloutStateOfCalloutState(Index, Value, partitionIndex)                               /**< Deactivateable: 'Csm_CalloutState.CalloutState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define Csm_SetInOutRedirection(Index, Value, partitionIndex)                                         /**< Deactivateable: 'Csm_InOutRedirection' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_SetJob(Index, Value, partitionIndex)                                                    Csm_GetJobOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define Csm_SetJobState(Index, Value, partitionIndex)                                               Csm_GetJobStateOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define Csm_SetJobToObjMap(Index, Value, partitionIndex)                                            Csm_GetJobToObjMapOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define Csm_SetPartitionDataInitialized(Value, partitionIndex)                                      (*(Csm_GetPartitionDataInitializedOfPCPartitionConfig(partitionIndex))) = (Value)
#define Csm_SetQueue(Index, Value, partitionIndex)                                                  Csm_GetQueueOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define Csm_SetLockOfQueueState(Index, Value, partitionIndex)                                       Csm_GetQueueStateOfPCPartitionConfig(partitionIndex)[(Index)].LockOfQueueState = (Value)
#define Csm_SetQueueIdxOfQueueState(Index, Value, partitionIndex)                                   Csm_GetQueueStateOfPCPartitionConfig(partitionIndex)[(Index)].QueueIdxOfQueueState = (Value)
#define Csm_SetRetriggeringOfQueueState(Index, Value, partitionIndex)                                 /**< Deactivateable: 'Csm_QueueState.Retriggering' Reason: 'Not enabled for any of the queues.' */
#define Csm_SetRteCallbackOccurred(Value, partitionIndex)                                             /**< Deactivateable: 'Csm_RteCallbackOccurred' Reason: 'No RTE Callback is configured' */
#define Csm_SetRteResult(Index, Value, partitionIndex)                                                /**< Deactivateable: 'Csm_RteResult' Reason: 'No RTE Callback is configured' */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCGetAddressOfDataMacros  Csm Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define Csm_GetAddrInOutRedirection(Index, partitionIndex)                                            /**< Deactivateable: 'Csm_InOutRedirection' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_GetAddrJob(Index, partitionIndex)                                                       (&Csm_GetJob(((Index)), (partitionIndex)))
#define Csm_GetAddrJobInfo(Index)                                                                   (&Csm_GetJobInfo(Index))
#define Csm_GetAddrJobPrimitiveInfo(Index)                                                          (&Csm_GetJobPrimitiveInfo(Index))
#define Csm_GetAddrPrimitiveInfo(Index)                                                             (&Csm_GetPrimitiveInfo(Index))
#define Csm_GetAddrQueue(Index, partitionIndex)                                                     (&Csm_GetQueue(((Index)), (partitionIndex)))
#define Csm_GetAddrRteResult(Index, partitionIndex)                                                   /**< Deactivateable: 'Csm_RteResult' Reason: 'No RTE Callback is configured' */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCHasMacros  Csm Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Csm_HasAsymPrivateKeyMaxLengthOfGeneral(partitionIndex)                                     (TRUE != FALSE)
#define Csm_HasAsymPublicKeyMaxLengthOfGeneral(partitionIndex)                                      (TRUE != FALSE)
#define Csm_HasBswCallbacks()                                                                       (TRUE != FALSE)
#define Csm_HasCallbackFunc43OfBswCallbacks()                                                         /**< Deactivateable: 'Csm_BswCallbacks.CallbackFunc43' Reason: 'No Callback according to ASR 4.3 is configured' */
#define Csm_HasCallbackFunc44OfBswCallbacks()                                                         /**< Deactivateable: 'Csm_BswCallbacks.CallbackFunc44' Reason: 'No Callback according to ASR 4.4 is configured' */
#define Csm_HasCallbackFunc45OfBswCallbacks()                                                         /**< Deactivateable: 'Csm_BswCallbacks.CallbackFunc45' Reason: 'No Callback according to ASR R19-11/4.5 is configured' */
#define Csm_HasCallbackFunc46OfBswCallbacks()                                                       (TRUE != FALSE)
#define Csm_HasCallbackStartNotificationOfGeneral(partitionIndex)                                   (TRUE != FALSE)
#define Csm_HasCallout()                                                                              /**< Deactivateable: 'Csm_Callout' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Csm_HasPostJobCalloutFuncOfCallout()                                                          /**< Deactivateable: 'Csm_Callout.PostJobCalloutFunc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_HasPreJobCalloutFuncOfCallout()                                                           /**< Deactivateable: 'Csm_Callout.PreJobCalloutFunc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_HasCalloutInfo()                                                                          /**< Deactivateable: 'Csm_CalloutInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Csm_HasCalloutIdxOfCalloutInfo()                                                              /**< Deactivateable: 'Csm_CalloutInfo.CalloutIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_HasJobTableIdxOfCalloutInfo()                                                             /**< Deactivateable: 'Csm_CalloutInfo.JobTableIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_HasCalloutState(partitionIndex)                                                           /**< Deactivateable: 'Csm_CalloutState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define Csm_HasCalloutStateOfCalloutState(partitionIndex)                                             /**< Deactivateable: 'Csm_CalloutState.CalloutState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define Csm_HasCancelationDuringProcessingOfGeneral(partitionIndex)                                 (TRUE != FALSE)
#define Csm_HasExpectedCompatibilityVersion(partitionIndex)                                           /**< Deactivateable: 'Csm_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Csm_HasFinalMagicNumber()                                                                     /**< Deactivateable: 'Csm_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Csm_HasGeneratorCompatibilityVersion(partitionIndex)                                          /**< Deactivateable: 'Csm_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Csm_HasInOutJobRedirectionTable()                                                             /**< Deactivateable: 'Csm_InOutJobRedirectionTable' Reason: 'Not enabled for any job' */
#define Csm_HasInputKeyElementIdOfInOutJobRedirectionTable()                                          /**< Deactivateable: 'Csm_InOutJobRedirectionTable.InputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_HasInputKeyIdOfInOutJobRedirectionTable()                                                 /**< Deactivateable: 'Csm_InOutJobRedirectionTable.InputKeyId' Reason: 'Not enabled for any job' */
#define Csm_HasOutputKeyElementIdOfInOutJobRedirectionTable()                                         /**< Deactivateable: 'Csm_InOutJobRedirectionTable.OutputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_HasOutputKeyIdOfInOutJobRedirectionTable()                                                /**< Deactivateable: 'Csm_InOutJobRedirectionTable.OutputKeyId' Reason: 'Not enabled for any job' */
#define Csm_HasRedirectionConfigValueOfInOutJobRedirectionTable()                                     /**< Deactivateable: 'Csm_InOutJobRedirectionTable.RedirectionConfigValue' Reason: 'Not enabled for any job' */
#define Csm_HasSecondaryInputKeyElementIdOfInOutJobRedirectionTable()                                 /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryInputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_HasSecondaryInputKeyIdOfInOutJobRedirectionTable()                                        /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryInputKeyId' Reason: 'Not enabled for any job' */
#define Csm_HasSecondaryOutputKeyElementIdOfInOutJobRedirectionTable()                                /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryOutputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_HasSecondaryOutputKeyIdOfInOutJobRedirectionTable()                                       /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryOutputKeyId' Reason: 'Not enabled for any job' */
#define Csm_HasTertiaryInputKeyElementIdOfInOutJobRedirectionTable()                                  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.TertiaryInputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_HasTertiaryInputKeyIdOfInOutJobRedirectionTable()                                         /**< Deactivateable: 'Csm_InOutJobRedirectionTable.TertiaryInputKeyId' Reason: 'Not enabled for any job' */
#define Csm_HasInOutRedirection(partitionIndex)                                                       /**< Deactivateable: 'Csm_InOutRedirection' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_HasInOutRedirectionMap(partitionIndex)                                                    /**< Deactivateable: 'Csm_InOutRedirectionMap' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Csm_HasInOutJobRedirectionTableIdxOfInOutRedirectionMap(partitionIndex)                       /**< Deactivateable: 'Csm_InOutRedirectionMap.InOutJobRedirectionTableIdx' Reason: 'Not enabled for any job' */
#define Csm_HasInvalidHndOfInOutRedirectionMap(partitionIndex)                                        /**< Deactivateable: 'Csm_InOutRedirectionMap.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'Csm_InOutRedirectionMap.InvalidHnd' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Csm_HasInitDataHashCode()                                                                     /**< Deactivateable: 'Csm_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Csm_HasJob(partitionIndex)                                                                  (TRUE != FALSE)
#define Csm_HasJobInfo()                                                                            (TRUE != FALSE)
#define Csm_HasJobPrimitiveInfo()                                                                   (TRUE != FALSE)
#define Csm_HasJobState(partitionIndex)                                                             (TRUE != FALSE)
#define Csm_HasJobTable()                                                                           (TRUE != FALSE)
#define Csm_HasAsynchronousOfJobTable()                                                             (TRUE != FALSE)
#define Csm_HasBswCallbacksIdxOfJobTable()                                                          (TRUE != FALSE)
#define Csm_HasBswCallbacksUsedOfJobTable()                                                         (TRUE != FALSE)
#define Csm_HasCalloutInfoIdxOfJobTable()                                                             /**< Deactivateable: 'Csm_JobTable.CalloutInfoIdx' Reason: 'the optional indirection is deactivated because CalloutInfoUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_HasCalloutInfoUsedOfJobTable()                                                            /**< Deactivateable: 'Csm_JobTable.CalloutInfoUsed' Reason: 'the optional indirection is deactivated because CalloutInfoUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_HasCsmKeyIdIdxOfJobTable()                                                              (TRUE != FALSE)
#define Csm_HasInOutRedirectionMapIdxOfJobTable()                                                     /**< Deactivateable: 'Csm_JobTable.InOutRedirectionMapIdx' Reason: 'the optional indirection is deactivated because InOutRedirectionMapUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_HasInOutRedirectionMapUsedOfJobTable()                                                    /**< Deactivateable: 'Csm_JobTable.InOutRedirectionMapUsed' Reason: 'the optional indirection is deactivated because InOutRedirectionMapUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_HasJobIdxOfJobTable()                                                                     /**< Deactivateable: 'Csm_JobTable.JobIdx' Reason: 'the optional indirection is deactivated because JobUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_HasJobInfoIdxOfJobTable()                                                               (TRUE != FALSE)
#define Csm_HasJobPartitionIdxOfJobTable()                                                          (TRUE != FALSE)
#define Csm_HasJobPrimitiveInfoIdxOfJobTable()                                                      (TRUE != FALSE)
#define Csm_HasJobUsedOfJobTable()                                                                    /**< Deactivateable: 'Csm_JobTable.JobUsed' Reason: 'the optional indirection is deactivated because JobUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_HasMaskedBitsOfJobTable()                                                               (TRUE != FALSE)
#define Csm_HasPrimitiveCallbackUpdateNotificationOfJobTable()                                      (TRUE != FALSE)
#define Csm_HasPriorityOfJobTable()                                                                 (TRUE != FALSE)
#define Csm_HasQueueInfoIdxOfJobTable()                                                             (TRUE != FALSE)
#define Csm_HasRteCallbackIdxOfJobTable()                                                             /**< Deactivateable: 'Csm_JobTable.RteCallbackIdx' Reason: 'No RTE Callback is configured' */
#define Csm_HasRteCallbackPartitionIdxOfJobTable()                                                  (TRUE != FALSE)
#define Csm_HasRteCallbackUsedOfJobTable()                                                            /**< Deactivateable: 'Csm_JobTable.RteCallbackUsed' Reason: 'No RTE Callback is configured' */
#define Csm_HasJobToObjMap(partitionIndex)                                                          (TRUE != FALSE)
#define Csm_HasKey()                                                                                (TRUE != FALSE)
#define Csm_HasCryIfKeyIdOfKey()                                                                    (TRUE != FALSE)
#define Csm_HasMultiPartitionRuntimeChecksOfGeneral(partitionIndex)                                 (TRUE != FALSE)
#define Csm_HasPartitionDataInitialized(partitionIndex)                                             (TRUE != FALSE)
#define Csm_HasPartitionIdentifiers()                                                               (TRUE != FALSE)
#define Csm_HasPCPartitionConfigIdxOfPartitionIdentifiers()                                         (TRUE != FALSE)
#define Csm_HasPartitionSNVOfPartitionIdentifiers()                                                 (TRUE != FALSE)
#define Csm_HasPrimitiveInfo()                                                                      (TRUE != FALSE)
#define Csm_HasQueue(partitionIndex)                                                                (TRUE != FALSE)
#define Csm_HasQueueInfo()                                                                          (TRUE != FALSE)
#define Csm_HasChannelIdOfQueueInfo()                                                               (TRUE != FALSE)
#define Csm_HasJobObjSynchronousIdxOfQueueInfo()                                                    (TRUE != FALSE)
#define Csm_HasJobObjSynchronousPartitionIdxOfQueueInfo()                                           (TRUE != FALSE)
#define Csm_HasJobObjSynchronousUsedOfQueueInfo()                                                   (TRUE != FALSE)
#define Csm_HasJobPoolEndIdxOfQueueInfo()                                                           (TRUE != FALSE)
#define Csm_HasJobPoolPartitionIdxOfQueueInfo()                                                     (TRUE != FALSE)
#define Csm_HasJobPoolStartIdxOfQueueInfo()                                                         (TRUE != FALSE)
#define Csm_HasJobPoolUsedOfQueueInfo()                                                             (TRUE != FALSE)
#define Csm_HasJobSharingOfQueueInfo()                                                              (TRUE != FALSE)
#define Csm_HasOperationModeLimitationOfQueueInfo()                                                   /**< Deactivateable: 'Csm_QueueInfo.OperationModeLimitation' Reason: 'the value of Csm_OperationModeLimitationOfQueueInfo is always 'false' due to this, the array is deactivated.' */
#define Csm_HasPartitionConfigIdxOfQueueInfo()                                                      (TRUE != FALSE)
#define Csm_HasProcessingModeOfQueueInfo()                                                          (TRUE != FALSE)
#define Csm_HasQueueEndIdxOfQueueInfo()                                                             (TRUE != FALSE)
#define Csm_HasQueueStartIdxOfQueueInfo()                                                           (TRUE != FALSE)
#define Csm_HasTriggerAsynchJobsInCallbackOfQueueInfo()                                               /**< Deactivateable: 'Csm_QueueInfo.TriggerAsynchJobsInCallback' Reason: 'Not enabled for any of the queues.' */
#define Csm_HasQueueState(partitionIndex)                                                           (TRUE != FALSE)
#define Csm_HasLockOfQueueState(partitionIndex)                                                     (TRUE != FALSE)
#define Csm_HasQueueIdxOfQueueState(partitionIndex)                                                 (TRUE != FALSE)
#define Csm_HasRetriggeringOfQueueState(partitionIndex)                                               /**< Deactivateable: 'Csm_QueueState.Retriggering' Reason: 'Not enabled for any of the queues.' */
#define Csm_HasRteCallback(partitionIndex)                                                            /**< Deactivateable: 'Csm_RteCallback' Reason: 'No RTE Callback is configured' */
#define Csm_HasRteCallbackOccurred(partitionIndex)                                                    /**< Deactivateable: 'Csm_RteCallbackOccurred' Reason: 'No RTE Callback is configured' */
#define Csm_HasRteResult(partitionIndex)                                                              /**< Deactivateable: 'Csm_RteResult' Reason: 'No RTE Callback is configured' */
#define Csm_HasSizeOfBswCallbacks()                                                                 (TRUE != FALSE)
#define Csm_HasSizeOfJob(partitionIndex)                                                            (TRUE != FALSE)
#define Csm_HasSizeOfJobInfo()                                                                      (TRUE != FALSE)
#define Csm_HasSizeOfJobPrimitiveInfo()                                                             (TRUE != FALSE)
#define Csm_HasSizeOfJobState(partitionIndex)                                                       (TRUE != FALSE)
#define Csm_HasSizeOfJobTable()                                                                     (TRUE != FALSE)
#define Csm_HasSizeOfJobToObjMap(partitionIndex)                                                    (TRUE != FALSE)
#define Csm_HasSizeOfKey()                                                                          (TRUE != FALSE)
#define Csm_HasSizeOfPartitionIdentifiers()                                                         (TRUE != FALSE)
#define Csm_HasSizeOfPrimitiveInfo()                                                                (TRUE != FALSE)
#define Csm_HasSizeOfQueue(partitionIndex)                                                          (TRUE != FALSE)
#define Csm_HasSizeOfQueueInfo()                                                                    (TRUE != FALSE)
#define Csm_HasSizeOfQueueState(partitionIndex)                                                     (TRUE != FALSE)
#define Csm_HasSwcUseErrorCodesPrefixOfGeneral(partitionIndex)                                        /**< Deactivateable: 'Csm_SwcUseErrorCodesPrefixOfGeneral' Reason: 'Parameter is not configured!' */
#define Csm_HasSymKeyMaxLengthOfGeneral(partitionIndex)                                             (TRUE != FALSE)
#define Csm_HasUseDeprecatedOfGeneral(partitionIndex)                                               (TRUE != FALSE)
#define Csm_HasVersionInfoApiOfGeneral(partitionIndex)                                              (TRUE != FALSE)
#define Csm_HasPCConfig()                                                                           (TRUE != FALSE)
#define Csm_HasFinalMagicNumberOfPCConfig()                                                           /**< Deactivateable: 'Csm_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Csm_HasInitDataHashCodeOfPCConfig()                                                           /**< Deactivateable: 'Csm_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Csm_HasPCPartitionConfigOfPCConfig()                                                        (TRUE != FALSE)
#define Csm_HasPartitionIdentifiersOfPCConfig()                                                     (TRUE != FALSE)
#define Csm_HasSizeOfPartitionIdentifiersOfPCConfig()                                               (TRUE != FALSE)
#define Csm_HasPCPartitionConfig()                                                                  (TRUE != FALSE)
#define Csm_HasAsymPrivateKeyMaxLengthOfGeneralOfPCPartitionConfig(partitionIndex)                  (TRUE != FALSE)
#define Csm_HasAsymPublicKeyMaxLengthOfGeneralOfPCPartitionConfig(partitionIndex)                   (TRUE != FALSE)
#define Csm_HasBswCallbacksOfPCPartitionConfig()                                                    (TRUE != FALSE)
#define Csm_HasCallbackStartNotificationOfGeneralOfPCPartitionConfig(partitionIndex)                (TRUE != FALSE)
#define Csm_HasCancelationDuringProcessingOfGeneralOfPCPartitionConfig(partitionIndex)              (TRUE != FALSE)
#define Csm_HasExpectedCompatibilityVersionOfPCPartitionConfig(partitionIndex)                        /**< Deactivateable: 'Csm_PCPartitionConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Csm_HasGeneratorCompatibilityVersionOfPCPartitionConfig(partitionIndex)                       /**< Deactivateable: 'Csm_PCPartitionConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Csm_HasJobInfoOfPCPartitionConfig()                                                         (TRUE != FALSE)
#define Csm_HasJobOfPCPartitionConfig(partitionIndex)                                               (TRUE != FALSE)
#define Csm_HasJobPrimitiveInfoOfPCPartitionConfig()                                                (TRUE != FALSE)
#define Csm_HasJobStateOfPCPartitionConfig(partitionIndex)                                          (TRUE != FALSE)
#define Csm_HasJobTableOfPCPartitionConfig()                                                        (TRUE != FALSE)
#define Csm_HasJobToObjMapOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define Csm_HasKeyOfPCPartitionConfig()                                                             (TRUE != FALSE)
#define Csm_HasMultiPartitionRuntimeChecksOfGeneralOfPCPartitionConfig(partitionIndex)              (TRUE != FALSE)
#define Csm_HasPartitionDataInitializedOfPCPartitionConfig(partitionIndex)                          (TRUE != FALSE)
#define Csm_HasPrimitiveInfoOfPCPartitionConfig()                                                   (TRUE != FALSE)
#define Csm_HasQueueInfoOfPCPartitionConfig()                                                       (TRUE != FALSE)
#define Csm_HasQueueOfPCPartitionConfig(partitionIndex)                                             (TRUE != FALSE)
#define Csm_HasQueueStateOfPCPartitionConfig(partitionIndex)                                        (TRUE != FALSE)
#define Csm_HasSizeOfBswCallbacksOfPCPartitionConfig()                                              (TRUE != FALSE)
#define Csm_HasSizeOfJobInfoOfPCPartitionConfig()                                                   (TRUE != FALSE)
#define Csm_HasSizeOfJobOfPCPartitionConfig(partitionIndex)                                         (TRUE != FALSE)
#define Csm_HasSizeOfJobPrimitiveInfoOfPCPartitionConfig()                                          (TRUE != FALSE)
#define Csm_HasSizeOfJobStateOfPCPartitionConfig(partitionIndex)                                    (TRUE != FALSE)
#define Csm_HasSizeOfJobTableOfPCPartitionConfig()                                                  (TRUE != FALSE)
#define Csm_HasSizeOfJobToObjMapOfPCPartitionConfig(partitionIndex)                                 (TRUE != FALSE)
#define Csm_HasSizeOfKeyOfPCPartitionConfig()                                                       (TRUE != FALSE)
#define Csm_HasSizeOfPrimitiveInfoOfPCPartitionConfig()                                             (TRUE != FALSE)
#define Csm_HasSizeOfQueueInfoOfPCPartitionConfig()                                                 (TRUE != FALSE)
#define Csm_HasSizeOfQueueOfPCPartitionConfig(partitionIndex)                                       (TRUE != FALSE)
#define Csm_HasSizeOfQueueStateOfPCPartitionConfig(partitionIndex)                                  (TRUE != FALSE)
#define Csm_HasSwcUseErrorCodesPrefixOfGeneralOfPCPartitionConfig(partitionIndex)                     /**< Deactivateable: 'Csm_PCPartitionConfig.SwcUseErrorCodesPrefixOfGeneral' Reason: 'Parameter is not configured!' */
#define Csm_HasSymKeyMaxLengthOfGeneralOfPCPartitionConfig(partitionIndex)                          (TRUE != FALSE)
#define Csm_HasUseDeprecatedOfGeneralOfPCPartitionConfig(partitionIndex)                            (TRUE != FALSE)
#define Csm_HasVersionInfoApiOfGeneralOfPCPartitionConfig(partitionIndex)                           (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCIncrementDataMacros  Csm Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define Csm_IncCalloutStateOfCalloutState(Index, partitionIndex)                                      /**< Deactivateable: 'Csm_CalloutState.CalloutState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define Csm_IncInOutRedirection(Index, partitionIndex)                                                /**< Deactivateable: 'Csm_InOutRedirection' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_IncJob(Index, partitionIndex)                                                           Csm_GetJob(((Index)), (partitionIndex))++
#define Csm_IncJobState(Index, partitionIndex)                                                      Csm_GetJobState(((Index)), (partitionIndex))++
#define Csm_IncPartitionDataInitialized(partitionIndex)                                             Csm_GetPartitionDataInitialized(partitionIndex)++
#define Csm_IncQueue(Index, partitionIndex)                                                         Csm_GetQueue(((Index)), (partitionIndex))++
#define Csm_IncLockOfQueueState(Index, partitionIndex)                                              Csm_GetLockOfQueueState(((Index)), (partitionIndex))++
#define Csm_IncQueueIdxOfQueueState(Index, partitionIndex)                                          Csm_GetQueueIdxOfQueueState(((Index)), (partitionIndex))++
#define Csm_IncRetriggeringOfQueueState(Index, partitionIndex)                                        /**< Deactivateable: 'Csm_QueueState.Retriggering' Reason: 'Not enabled for any of the queues.' */
#define Csm_IncRteResult(Index, partitionIndex)                                                       /**< Deactivateable: 'Csm_RteResult' Reason: 'No RTE Callback is configured' */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCDecrementDataMacros  Csm Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define Csm_DecCalloutStateOfCalloutState(Index, partitionIndex)                                      /**< Deactivateable: 'Csm_CalloutState.CalloutState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define Csm_DecInOutRedirection(Index, partitionIndex)                                                /**< Deactivateable: 'Csm_InOutRedirection' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_DecJob(Index, partitionIndex)                                                           Csm_GetJob(((Index)), (partitionIndex))--
#define Csm_DecJobState(Index, partitionIndex)                                                      Csm_GetJobState(((Index)), (partitionIndex))--
#define Csm_DecPartitionDataInitialized(partitionIndex)                                             Csm_GetPartitionDataInitialized(partitionIndex)--
#define Csm_DecQueue(Index, partitionIndex)                                                         Csm_GetQueue(((Index)), (partitionIndex))--
#define Csm_DecLockOfQueueState(Index, partitionIndex)                                              Csm_GetLockOfQueueState(((Index)), (partitionIndex))--
#define Csm_DecQueueIdxOfQueueState(Index, partitionIndex)                                          Csm_GetQueueIdxOfQueueState(((Index)), (partitionIndex))--
#define Csm_DecRetriggeringOfQueueState(Index, partitionIndex)                                        /**< Deactivateable: 'Csm_QueueState.Retriggering' Reason: 'Not enabled for any of the queues.' */
#define Csm_DecRteResult(Index, partitionIndex)                                                       /**< Deactivateable: 'Csm_RteResult' Reason: 'No RTE Callback is configured' */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCAddDataMacros  Csm Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define Csm_AddCalloutStateOfCalloutState(Index, Value, partitionIndex)                               /**< Deactivateable: 'Csm_CalloutState.CalloutState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define Csm_AddInOutRedirection(Index, Value, partitionIndex)                                         /**< Deactivateable: 'Csm_InOutRedirection' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_AddJob(Index, Value, partitionIndex)                                                    Csm_SetJob(Index, (Csm_GetJob(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Csm_AddJobState(Index, Value, partitionIndex)                                               Csm_SetJobState(Index, (Csm_GetJobState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Csm_AddPartitionDataInitialized(Value, partitionIndex)                                      Csm_SetPartitionDataInitialized((Csm_GetPartitionDataInitialized(partitionIndex) + Value), partitionIndex)
#define Csm_AddQueue(Index, Value, partitionIndex)                                                  Csm_SetQueue(Index, (Csm_GetQueue(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Csm_AddLockOfQueueState(Index, Value, partitionIndex)                                       Csm_SetLockOfQueueState(Index, (Csm_GetLockOfQueueState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Csm_AddQueueIdxOfQueueState(Index, Value, partitionIndex)                                   Csm_SetQueueIdxOfQueueState(Index, (Csm_GetQueueIdxOfQueueState(((Index)), (partitionIndex)) + Value), partitionIndex)
#define Csm_AddRetriggeringOfQueueState(Index, Value, partitionIndex)                                 /**< Deactivateable: 'Csm_QueueState.Retriggering' Reason: 'Not enabled for any of the queues.' */
#define Csm_AddRteResult(Index, Value, partitionIndex)                                                /**< Deactivateable: 'Csm_RteResult' Reason: 'No RTE Callback is configured' */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCSubstractDataMacros  Csm Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define Csm_SubCalloutStateOfCalloutState(Index, Value, partitionIndex)                               /**< Deactivateable: 'Csm_CalloutState.CalloutState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define Csm_SubInOutRedirection(Index, Value, partitionIndex)                                         /**< Deactivateable: 'Csm_InOutRedirection' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_SubJob(Index, Value, partitionIndex)                                                    Csm_SetJob(Index, (Csm_GetJob(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Csm_SubJobState(Index, Value, partitionIndex)                                               Csm_SetJobState(Index, (Csm_GetJobState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Csm_SubPartitionDataInitialized(Value, partitionIndex)                                      Csm_SetPartitionDataInitialized((Csm_GetPartitionDataInitialized(partitionIndex) - Value), partitionIndex)
#define Csm_SubQueue(Index, Value, partitionIndex)                                                  Csm_SetQueue(Index, (Csm_GetQueue(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Csm_SubLockOfQueueState(Index, Value, partitionIndex)                                       Csm_SetLockOfQueueState(Index, (Csm_GetLockOfQueueState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Csm_SubQueueIdxOfQueueState(Index, Value, partitionIndex)                                   Csm_SetQueueIdxOfQueueState(Index, (Csm_GetQueueIdxOfQueueState(((Index)), (partitionIndex)) - Value), partitionIndex)
#define Csm_SubRetriggeringOfQueueState(Index, Value, partitionIndex)                                 /**< Deactivateable: 'Csm_QueueState.Retriggering' Reason: 'Not enabled for any of the queues.' */
#define Csm_SubRteResult(Index, Value, partitionIndex)                                                /**< Deactivateable: 'Csm_RteResult' Reason: 'No RTE Callback is configured' */
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
  \defgroup  CsmPBGetRootDataMacros  Csm Get Root Data Macros (POST_BUILD)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Csm_GetLTConfigIdxOfPBConfig()                                                                /**< Deactivateable: 'Csm_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Csm_GetPBPartitionConfigOfPBConfig()                                                          /**< Deactivateable: 'Csm_PBConfig.PBPartitionConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Csm_GetPCConfigIdxOfPBConfig()                                                                /**< Deactivateable: 'Csm_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPBHasMacros  Csm Has Macros (POST_BUILD)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Csm_HasPBConfig()                                                                             /**< Deactivateable: 'Csm_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Csm_HasLTConfigIdxOfPBConfig(partitionIndex)                                                  /**< Deactivateable: 'Csm_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Csm_HasPBPartitionConfigOfPBConfig()                                                          /**< Deactivateable: 'Csm_PBConfig.PBPartitionConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Csm_HasPCConfigIdxOfPBConfig(partitionIndex)                                                  /**< Deactivateable: 'Csm_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Csm_HasPBPartitionConfig()                                                                    /**< Deactivateable: 'Csm_PBPartitionConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
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


#define CSM_MAINFUNCTION_LOCAL STD_OFF 
#define CSM_INITMEMORY_LOCAL   STD_OFF 
#define CSM_INITMEMORY         STD_ON 




/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef P2VAR(Crypto_JobType, AUTOMATIC, CSM_VAR_NOINIT) Csm_QueueElementType;
typedef P2FUNC (void, CSM_CODE, Csm_CallbackFunc43Type)(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Std_ReturnType result);
typedef P2FUNC (void, CSM_CODE, Csm_CallbackFunc44Type)(const uint32 jobID, Csm_ResultType result);
typedef P2FUNC (void, CSM_CODE, Csm_CallbackFunc45Type)(P2CONST(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Crypto_ResultType result);
typedef P2FUNC (void, CSM_CODE, Csm_CallbackFunc46Type)(uint32 jobId, Crypto_ResultType result);
typedef P2FUNC (Std_ReturnType, CSM_CODE, Csm_PreJobCalloutFunc)(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Csm_JobCalloutStateType state);
typedef P2FUNC (Std_ReturnType, CSM_CODE, Csm_PostJobCalloutFunc)(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Csm_JobCalloutStateType state, P2VAR(Std_ReturnType, AUTOMATIC, CSM_APPL_VAR) jobReturnValue);


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CsmPCIterableTypes  Csm Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate Csm_BswCallbacks */
typedef uint8_least Csm_BswCallbacksIterType;

/**   \brief  type used to iterate Csm_Job */
typedef uint8_least Csm_JobIterType;

/**   \brief  type used to iterate Csm_JobInfo */
typedef uint8_least Csm_JobInfoIterType;

/**   \brief  type used to iterate Csm_JobPrimitiveInfo */
typedef uint8_least Csm_JobPrimitiveInfoIterType;

/**   \brief  type used to iterate Csm_JobTable */
typedef uint8_least Csm_JobTableIterType;

/**   \brief  type used to iterate Csm_Key */
typedef uint8_least Csm_KeyIterType;

/**   \brief  type used to iterate Csm_PartitionIdentifiers */
typedef uint8_least Csm_PartitionIdentifiersIterType;

/**   \brief  type used to iterate Csm_PrimitiveInfo */
typedef uint8_least Csm_PrimitiveInfoIterType;

/**   \brief  type used to iterate Csm_Queue */
typedef uint8_least Csm_QueueIterType;

/**   \brief  type used to iterate Csm_QueueInfo */
typedef uint8_least Csm_QueueInfoIterType;

/**   \brief  type used to iterate Csm_PCPartitionConfig */
typedef uint8_least Csm_PCPartitionConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CsmPCIterableTypesWithSizeRelations  Csm Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate Csm_JobState */
typedef Csm_JobTableIterType Csm_JobStateIterType;

/**   \brief  type used to iterate Csm_JobToObjMap */
typedef Csm_JobTableIterType Csm_JobToObjMapIterType;

/**   \brief  type used to iterate Csm_QueueState */
typedef Csm_QueueInfoIterType Csm_QueueStateIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CsmPCValueTypes  Csm Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Csm_AsymPrivateKeyMaxLengthOfGeneral */
typedef uint8 Csm_AsymPrivateKeyMaxLengthOfGeneralType;

/**   \brief  value based type definition for Csm_AsymPublicKeyMaxLengthOfGeneral */
typedef uint16 Csm_AsymPublicKeyMaxLengthOfGeneralType;

/**   \brief  value based type definition for Csm_CallbackStartNotificationOfGeneral */
typedef boolean Csm_CallbackStartNotificationOfGeneralType;

/**   \brief  value based type definition for Csm_CancelationDuringProcessingOfGeneral */
typedef boolean Csm_CancelationDuringProcessingOfGeneralType;

/**   \brief  value based type definition for Csm_JobState */
typedef uint8 Csm_JobStateType;

/**   \brief  value based type definition for Csm_AsynchronousOfJobTable */
typedef boolean Csm_AsynchronousOfJobTableType;

/**   \brief  value based type definition for Csm_BswCallbacksIdxOfJobTable */
typedef uint8 Csm_BswCallbacksIdxOfJobTableType;

/**   \brief  value based type definition for Csm_BswCallbacksUsedOfJobTable */
typedef boolean Csm_BswCallbacksUsedOfJobTableType;

/**   \brief  value based type definition for Csm_CsmKeyIdIdxOfJobTable */
typedef uint8 Csm_CsmKeyIdIdxOfJobTableType;

/**   \brief  value based type definition for Csm_JobInfoIdxOfJobTable */
typedef uint8 Csm_JobInfoIdxOfJobTableType;

/**   \brief  value based type definition for Csm_JobPartitionIdxOfJobTable */
typedef uint8 Csm_JobPartitionIdxOfJobTableType;

/**   \brief  value based type definition for Csm_JobPrimitiveInfoIdxOfJobTable */
typedef uint8 Csm_JobPrimitiveInfoIdxOfJobTableType;

/**   \brief  value based type definition for Csm_MaskedBitsOfJobTable */
typedef uint8 Csm_MaskedBitsOfJobTableType;

/**   \brief  value based type definition for Csm_PrimitiveCallbackUpdateNotificationOfJobTable */
typedef boolean Csm_PrimitiveCallbackUpdateNotificationOfJobTableType;

/**   \brief  value based type definition for Csm_PriorityOfJobTable */
typedef uint8 Csm_PriorityOfJobTableType;

/**   \brief  value based type definition for Csm_QueueInfoIdxOfJobTable */
typedef uint8 Csm_QueueInfoIdxOfJobTableType;

/**   \brief  value based type definition for Csm_RteCallbackPartitionIdxOfJobTable */
typedef uint8 Csm_RteCallbackPartitionIdxOfJobTableType;

/**   \brief  value based type definition for Csm_CryIfKeyIdOfKey */
typedef uint32 Csm_CryIfKeyIdOfKeyType;

/**   \brief  value based type definition for Csm_MultiPartitionRuntimeChecksOfGeneral */
typedef boolean Csm_MultiPartitionRuntimeChecksOfGeneralType;

/**   \brief  value based type definition for Csm_PartitionDataInitialized */
typedef uint8 Csm_PartitionDataInitializedType;

/**   \brief  value based type definition for Csm_PCPartitionConfigIdxOfPartitionIdentifiers */
typedef uint8 Csm_PCPartitionConfigIdxOfPartitionIdentifiersType;

/**   \brief  value based type definition for Csm_PartitionSNVOfPartitionIdentifiers */
typedef uint32 Csm_PartitionSNVOfPartitionIdentifiersType;

/**   \brief  value based type definition for Csm_ChannelIdOfQueueInfo */
typedef uint32 Csm_ChannelIdOfQueueInfoType;

/**   \brief  value based type definition for Csm_JobObjSynchronousIdxOfQueueInfo */
typedef uint8 Csm_JobObjSynchronousIdxOfQueueInfoType;

/**   \brief  value based type definition for Csm_JobObjSynchronousPartitionIdxOfQueueInfo */
typedef uint8 Csm_JobObjSynchronousPartitionIdxOfQueueInfoType;

/**   \brief  value based type definition for Csm_JobObjSynchronousUsedOfQueueInfo */
typedef boolean Csm_JobObjSynchronousUsedOfQueueInfoType;

/**   \brief  value based type definition for Csm_JobPoolEndIdxOfQueueInfo */
typedef uint8 Csm_JobPoolEndIdxOfQueueInfoType;

/**   \brief  value based type definition for Csm_JobPoolPartitionIdxOfQueueInfo */
typedef uint8 Csm_JobPoolPartitionIdxOfQueueInfoType;

/**   \brief  value based type definition for Csm_JobPoolStartIdxOfQueueInfo */
typedef uint8 Csm_JobPoolStartIdxOfQueueInfoType;

/**   \brief  value based type definition for Csm_JobPoolUsedOfQueueInfo */
typedef boolean Csm_JobPoolUsedOfQueueInfoType;

/**   \brief  value based type definition for Csm_JobSharingOfQueueInfo */
typedef boolean Csm_JobSharingOfQueueInfoType;

/**   \brief  value based type definition for Csm_PartitionConfigIdxOfQueueInfo */
typedef uint8 Csm_PartitionConfigIdxOfQueueInfoType;

/**   \brief  value based type definition for Csm_ProcessingModeOfQueueInfo */
typedef uint8 Csm_ProcessingModeOfQueueInfoType;

/**   \brief  value based type definition for Csm_QueueEndIdxOfQueueInfo */
typedef uint8 Csm_QueueEndIdxOfQueueInfoType;

/**   \brief  value based type definition for Csm_QueueStartIdxOfQueueInfo */
typedef uint8 Csm_QueueStartIdxOfQueueInfoType;

/**   \brief  value based type definition for Csm_LockOfQueueState */
typedef uint16 Csm_LockOfQueueStateType;

/**   \brief  value based type definition for Csm_QueueIdxOfQueueState */
typedef uint8 Csm_QueueIdxOfQueueStateType;

/**   \brief  value based type definition for Csm_SizeOfBswCallbacks */
typedef uint8 Csm_SizeOfBswCallbacksType;

/**   \brief  value based type definition for Csm_SizeOfJob */
typedef uint8 Csm_SizeOfJobType;

/**   \brief  value based type definition for Csm_SizeOfJobInfo */
typedef uint8 Csm_SizeOfJobInfoType;

/**   \brief  value based type definition for Csm_SizeOfJobPrimitiveInfo */
typedef uint8 Csm_SizeOfJobPrimitiveInfoType;

/**   \brief  value based type definition for Csm_SizeOfJobState */
typedef uint8 Csm_SizeOfJobStateType;

/**   \brief  value based type definition for Csm_SizeOfJobTable */
typedef uint8 Csm_SizeOfJobTableType;

/**   \brief  value based type definition for Csm_SizeOfJobToObjMap */
typedef uint8 Csm_SizeOfJobToObjMapType;

/**   \brief  value based type definition for Csm_SizeOfKey */
typedef uint8 Csm_SizeOfKeyType;

/**   \brief  value based type definition for Csm_SizeOfPartitionIdentifiers */
typedef uint8 Csm_SizeOfPartitionIdentifiersType;

/**   \brief  value based type definition for Csm_SizeOfPrimitiveInfo */
typedef uint8 Csm_SizeOfPrimitiveInfoType;

/**   \brief  value based type definition for Csm_SizeOfQueue */
typedef uint8 Csm_SizeOfQueueType;

/**   \brief  value based type definition for Csm_SizeOfQueueInfo */
typedef uint8 Csm_SizeOfQueueInfoType;

/**   \brief  value based type definition for Csm_SizeOfQueueState */
typedef uint8 Csm_SizeOfQueueStateType;

/**   \brief  value based type definition for Csm_SymKeyMaxLengthOfGeneral */
typedef uint8 Csm_SymKeyMaxLengthOfGeneralType;

/**   \brief  value based type definition for Csm_UseDeprecatedOfGeneral */
typedef boolean Csm_UseDeprecatedOfGeneralType;

/**   \brief  value based type definition for Csm_VersionInfoApiOfGeneral */
typedef boolean Csm_VersionInfoApiOfGeneralType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CsmPCStructTypes  Csm Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in Csm_BswCallbacks */
typedef struct sCsm_BswCallbacksType
{
  Csm_CallbackFunc46Type CallbackFunc46OfBswCallbacks;
} Csm_BswCallbacksType;

/**   \brief  type used in Csm_JobTable */
typedef struct sCsm_JobTableType
{
  Csm_BswCallbacksIdxOfJobTableType BswCallbacksIdxOfJobTable;  /**< the index of the 0:1 relation pointing to Csm_BswCallbacks */
  Csm_CsmKeyIdIdxOfJobTableType CsmKeyIdIdxOfJobTable;  /**< the index of the 1:1 relation pointing to Csm_Key */
  Csm_JobPrimitiveInfoIdxOfJobTableType JobPrimitiveInfoIdxOfJobTable;  /**< the index of the 1:1 relation pointing to Csm_JobPrimitiveInfo */
  Csm_MaskedBitsOfJobTableType MaskedBitsOfJobTable;  /**< contains bitcoded the boolean data of Csm_AsynchronousOfJobTable, Csm_PrimitiveCallbackUpdateNotificationOfJobTable */
  Csm_PriorityOfJobTableType PriorityOfJobTable;  /**< Contains values of DefinitionRef: /MICROSAR/Csm/CsmJobs/CsmJob/CsmJobPriority. */
  Csm_QueueInfoIdxOfJobTableType QueueInfoIdxOfJobTable;  /**< the index of the 1:1 relation pointing to Csm_QueueInfo */
} Csm_JobTableType;

/**   \brief  type used in Csm_Key */
typedef struct sCsm_KeyType
{
  Csm_CryIfKeyIdOfKeyType CryIfKeyIdOfKey;  /**< Contains values of DefinitionRef: /MICROSAR/Csm/CsmKeys/CsmKey/CsmKeyRef. */
} Csm_KeyType;

/**   \brief  type used in Csm_PartitionIdentifiers */
typedef struct sCsm_PartitionIdentifiersType
{
  Csm_PartitionSNVOfPartitionIdentifiersType PartitionSNVOfPartitionIdentifiers;
} Csm_PartitionIdentifiersType;

/**   \brief  type used in Csm_QueueInfo */
typedef struct sCsm_QueueInfoType
{
  Csm_ChannelIdOfQueueInfoType ChannelIdOfQueueInfo;  /**< Contains values of DefinitionRef: /MICROSAR/Csm/CsmQueues/CsmQueue/CsmChannelRef. */
  Csm_JobSharingOfQueueInfoType JobSharingOfQueueInfo;  /**< Contains values of DefinitionRef: /MICROSAR/Csm/CsmQueues/CsmQueue/CsmJobSharing. */
  Csm_JobObjSynchronousIdxOfQueueInfoType JobObjSynchronousIdxOfQueueInfo;  /**< the index of the 0:1 relation pointing to Csm_Job */
  Csm_JobPoolPartitionIdxOfQueueInfoType JobPoolPartitionIdxOfQueueInfo;
  Csm_ProcessingModeOfQueueInfoType ProcessingModeOfQueueInfo;
  Csm_QueueEndIdxOfQueueInfoType QueueEndIdxOfQueueInfo;  /**< the end index of the 1:n relation pointing to Csm_Queue */
} Csm_QueueInfoType;

/**   \brief  type used in Csm_QueueState */
typedef struct sCsm_QueueStateType
{
  Csm_LockOfQueueStateType LockOfQueueState;
  Csm_QueueIdxOfQueueStateType QueueIdxOfQueueState;  /**< the index of the 1:1 relation pointing to Csm_Queue */
} Csm_QueueStateType;

/** 
  \}
*/ 

/** 
  \defgroup  CsmPCSymbolicStructTypes  Csm Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to Csm_Queue in the partition context  */
typedef struct Csm_QueueStructSTag
{
  Csm_QueueElementType CsmQueue_Hash;
  Csm_QueueElementType CsmQueue_AES;
  Csm_QueueElementType CsmQueue_MKA;
  Csm_QueueElementType CsmQueue_PublicKey;
  Csm_QueueElementType CsmQueue_Hash_Async[3];
  Csm_QueueElementType CsmQueue_PublicKey_Async;
  Csm_QueueElementType CsmQueue_AES_Async[4];
} Csm_QueueStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  CsmPCUnionIndexAndSymbolTypes  Csm Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access Csm_Queue in an index and symbol based style. */
typedef union Csm_QueueUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Csm_QueueElementType raw[12];
  Csm_QueueStructSType str;
} Csm_QueueUType;

/** 
  \}
*/ 

/** 
  \defgroup  CsmPCRootPointerTypes  Csm Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to Csm_BswCallbacks */
typedef P2CONST(Csm_BswCallbacksType, TYPEDEF, CSM_CONST) Csm_BswCallbacksPtrType;

/**   \brief  type used to point to Csm_Job */
typedef P2VAR(Crypto_JobType, TYPEDEF, CSM_VAR_NOINIT) Csm_JobPtrType;

/**   \brief  type used to point to Csm_JobInfo */
typedef P2CONST(Crypto_JobInfoType, TYPEDEF, CSM_CONST) Csm_JobInfoPtrType;

/**   \brief  type used to point to Csm_JobPrimitiveInfo */
typedef P2CONST(Crypto_JobPrimitiveInfoType, TYPEDEF, CSM_CONST) Csm_JobPrimitiveInfoPtrType;

/**   \brief  type used to point to Csm_JobState */
typedef P2VAR(Csm_JobStateType, TYPEDEF, CSM_VAR_NOINIT) Csm_JobStatePtrType;

/**   \brief  type used to point to Csm_JobTable */
typedef P2CONST(Csm_JobTableType, TYPEDEF, CSM_CONST) Csm_JobTablePtrType;

/**   \brief  type used to point to Csm_JobToObjMap */
typedef P2VAR(Csm_SizeOfJobType, TYPEDEF, CSM_VAR_NOINIT) Csm_JobToObjMapPtrType;

/**   \brief  type used to point to Csm_Key */
typedef P2CONST(Csm_KeyType, TYPEDEF, CSM_CONST) Csm_KeyPtrType;

/**   \brief  type used to point to Csm_PartitionDataInitialized */
typedef P2VAR(Csm_PartitionDataInitializedType, TYPEDEF, CSM_VAR_ZERO_INIT) Csm_PartitionDataInitializedPtrType;

/**   \brief  type used to point to Csm_PartitionIdentifiers */
typedef P2CONST(Csm_PartitionIdentifiersType, TYPEDEF, CSM_CONST) Csm_PartitionIdentifiersPtrType;

/**   \brief  type used to point to Csm_PrimitiveInfo */
typedef P2CONST(Crypto_PrimitiveInfoType, TYPEDEF, CSM_CONST) Csm_PrimitiveInfoPtrType;

/**   \brief  type used to point to Csm_Queue */
typedef P2VAR(Csm_QueueElementType, TYPEDEF, CSM_VAR_NOINIT) Csm_QueuePtrType;

/**   \brief  type used to point to Csm_QueueInfo */
typedef P2CONST(Csm_QueueInfoType, TYPEDEF, CSM_CONST) Csm_QueueInfoPtrType;

/**   \brief  type used to point to Csm_QueueState */
typedef P2VAR(Csm_QueueStateType, TYPEDEF, CSM_VAR_NOINIT) Csm_QueueStatePtrType;

/** 
  \}
*/ 

/** 
  \defgroup  CsmPCPartitionRootPointer  Csm Partition Root Pointer (PRE_COMPILE)
  \brief  This type definitions are used for partition specific instance.
  \{
*/ 
/**   \brief  type used in Csm_PCPartitionConfig */
typedef struct sCsm_PCPartitionConfigType
{
  uint8 Csm_PCPartitionConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Csm_PCPartitionConfigType;

/**   \brief  type used to point to Csm_PCPartitionConfig */
typedef P2CONST(Csm_PCPartitionConfigType, TYPEDEF, CSM_CONST) Csm_PCPartitionConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  CsmPCRootValueTypes  Csm Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Csm_PCConfig */
typedef struct sCsm_PCConfigType
{
  uint8 Csm_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Csm_PCConfigType;

typedef Csm_PCConfigType Csm_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CsmPBIterableTypes  Csm Iterable Types (POST_BUILD)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/** 
  \}
*/ 

/** 
  \defgroup  CsmPBValueTypes  Csm Value Types (POST_BUILD)
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
  \defgroup  CsmPBPartitionRootPointer  Csm Partition Root Pointer (POST_BUILD)
  \brief  This type definitions are used for partition specific instance.
  \{
*/ 
/** 
  \}
*/ 

/** 
  \defgroup  CsmPBRootValueTypes  Csm Root Value Types (POST_BUILD)
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
  Csm_BswCallbacks
**********************************************************************************************************************/
/** 
  \var    Csm_BswCallbacks
  \details
  Element           Description
  CallbackFunc46
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Csm_BswCallbacksType, CSM_CONST) Csm_BswCallbacks[1];
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobInfo
**********************************************************************************************************************/
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_JobInfoType, CSM_CONST) Csm_JobInfo[51];
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobPrimitiveInfo
**********************************************************************************************************************/
/** 
  \var    Csm_JobPrimitiveInfo
  \brief  const uint32 callbackId; const Crypto_PrimitiveInfoType* primitiveInfo; const uint32 cryIfKeyId; const Crypto_ProcessingType processingType;
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_JobPrimitiveInfoType, CSM_CONST) Csm_JobPrimitiveInfo[48];
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobTable
**********************************************************************************************************************/
/** 
  \var    Csm_JobTable
  \brief  Contains parameters of /MICROSAR/Csm/CsmJobs/CsmJob.
  \details
  Element                Description
  BswCallbacksIdx        the index of the 0:1 relation pointing to Csm_BswCallbacks
  CsmKeyIdIdx            the index of the 1:1 relation pointing to Csm_Key
  JobPrimitiveInfoIdx    the index of the 1:1 relation pointing to Csm_JobPrimitiveInfo
  MaskedBits             contains bitcoded the boolean data of Csm_AsynchronousOfJobTable, Csm_PrimitiveCallbackUpdateNotificationOfJobTable
  Priority               Contains values of DefinitionRef: /MICROSAR/Csm/CsmJobs/CsmJob/CsmJobPriority.
  QueueInfoIdx           the index of the 1:1 relation pointing to Csm_QueueInfo
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Csm_JobTableType, CSM_CONST) Csm_JobTable[51];
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_Key
**********************************************************************************************************************/
/** 
  \var    Csm_Key
  \brief  Contains parameters of /AUTOSAR/EcucDefs/Csm/CsmKeys/CsmKey.
  \details
  Element       Description
  CryIfKeyId    Contains values of DefinitionRef: /MICROSAR/Csm/CsmKeys/CsmKey/CsmKeyRef.
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Csm_KeyType, CSM_CONST) Csm_Key[62];
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    Csm_PartitionIdentifiers
  \brief  the partition context in Config
  \details
  Element         Description
  PartitionSNV
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Csm_PartitionIdentifiersType, CSM_CONST) Csm_PartitionIdentifiers[1];
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_PrimitiveInfo
**********************************************************************************************************************/
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_PrimitiveInfoType, CSM_CONST) Csm_PrimitiveInfo[37];
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_QueueInfo
**********************************************************************************************************************/
/** 
  \var    Csm_QueueInfo
  \brief  Contains parameters of /AUTOSAR/EcucDefs/Csm/CsmQueues/CsmQueue.
  \details
  Element                 Description
  ChannelId               Contains values of DefinitionRef: /MICROSAR/Csm/CsmQueues/CsmQueue/CsmChannelRef.
  JobSharing              Contains values of DefinitionRef: /MICROSAR/Csm/CsmQueues/CsmQueue/CsmJobSharing.
  JobObjSynchronousIdx    the index of the 0:1 relation pointing to Csm_Job
  JobPoolPartitionIdx 
  ProcessingMode      
  QueueEndIdx             the end index of the 1:n relation pointing to Csm_Queue
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Csm_QueueInfoType, CSM_CONST) Csm_QueueInfo[7];
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_Job
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_JobType, CSM_VAR_NOINIT) Csm_Job[12];
#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobState
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Csm_JobStateType, CSM_VAR_NOINIT) Csm_JobState[51];
#define CSM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobToObjMap
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Csm_SizeOfJobType, CSM_VAR_NOINIT) Csm_JobToObjMap[51];
#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_PartitionDataInitialized
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Csm_PartitionDataInitializedType, CSM_VAR_ZERO_INIT) Csm_PartitionDataInitialized;
#define CSM_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_Queue
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Csm_QueueUType, CSM_VAR_NOINIT) Csm_Queue;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_QueueState
**********************************************************************************************************************/
/** 
  \var    Csm_QueueState
  \brief  Stores state of the asynchronous job queue.
  \details
  Element     Description
  Lock    
  QueueIdx    the index of the 1:1 relation pointing to Csm_Queue
*/ 
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Csm_QueueStateType, CSM_VAR_NOINIT) Csm_QueueState[7];
#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
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


#define CSM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/***********************************************************************************************************************
 *  
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Csm_MainFunction_Local
 **********************************************************************************************************************/
/*!
 * \brief       API to be called cyclically per partition to process the requested jobs.
 * \details     The function shall check the partition dependent queues for jobs and pass them to the underlying CRYIF.
 * \param[in]   partition  Id of the current active partition.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function shall only be called by Csm itself.
 **********************************************************************************************************************/
extern FUNC(void, CSM_CODE) Csm_MainFunction_Local(Csm_SizeOfPartitionIdentifiersType partition);
/***********************************************************************************************************************
 *  Csm_InitMemory_Local
 **********************************************************************************************************************/
/*!
 * \brief       Power-up memory initialization.
 * \details     Initialize component variables at power up for specific partition.
 * \param[in]   partition  Id of the current active partition.
 * \pre         Module is uninitialized.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        This function shall only be called by Csm itself.
 **********************************************************************************************************************/
extern FUNC(void, CSM_CODE) Csm_InitMemory_Local(Csm_SizeOfPartitionIdentifiersType partition);

/***********************************************************************************************************************
 *  MainFunctionGroup
 **********************************************************************************************************************/
/*!
 * \fn          Csm_MainFunction
 * \brief       Partition specific main function
 * \details     Calls Csm_MainFunction_Local with dedicated partition.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  InitMemoryGroup
 **********************************************************************************************************************/
/*!
 * \fn          Csm_InitMemory
 * \brief       Power-up memory initialization.
 * \details     Initialize component variables at power up for specific partition.
 * \pre         Module is uninitialized.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Use this function in case these variables are not initialized by the startup code.
 **********************************************************************************************************************/
extern FUNC(void, CSM_CODE) Csm_InitMemory(void);
#define CSM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/* PRQA S 3449, 3451 CALLBACKFUNCTIONS_3449_3451 */ /* MD_CSM_CALLBACK_DECLARATIONS */
/* Callback Notification Prototypes */
extern FUNC(void, CSM_APPL_CODE) Csm_callback(uint32 jobId, Crypto_ResultType result);
/* PRQA L:CALLBACKFUNCTIONS_3449_3451 */


#if !defined (CSM_NOUNIT_CSLUNIT)
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/

#endif



#endif /* CSM_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Csm_Cfg.h
 *********************************************************************************************************************/

