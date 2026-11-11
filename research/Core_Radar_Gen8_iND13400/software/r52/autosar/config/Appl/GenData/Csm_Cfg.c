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
 *              File: Csm_Cfg.c
 *   Generation Time: 2026-08-11 12:32:52
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
#define CSM_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Csm_Cfg.h"
#include "CryIf.h"
#include "SchM_Csm.h"



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (STATIC)
# define STATIC static
#endif

#if !defined (CSM_LOCAL)
# define CSM_LOCAL static
#endif

#if !defined (CSM_LOCAL_INLINE)
# define CSM_LOCAL_INLINE LOCAL_INLINE
#endif




/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/






/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/




/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
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
CONST(Csm_BswCallbacksType, CSM_CONST) Csm_BswCallbacks[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CallbackFunc46        Referable Keys */
  { /*     0 */ Csm_callback   }   /* [/ActiveEcuC/Csm/CsmCallbacks/CsmCallback] */
};
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
CONST(Crypto_JobInfoType, CSM_CONST) Csm_JobInfo[51] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     JobInfo        Referable Keys */
  /*     0 */ {0u, 0u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_AEAD_GCM_Decrypt] */
  /*     1 */ {1u, 0u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_AEAD_GCM_Encrypt] */
  /*     2 */ {2u, 0u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256] */
  /*     3 */ {3u, 0u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256_ASYNC_1] */
  /*     4 */ {4u, 0u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256_ASYNC_2] */
  /*     5 */ {5u, 0u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256_ASYNC_3] */
  /*     6 */ {6u, 0u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_SHE] */
  /*     7 */ {7u, 0u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CFB_128] */
  /*     8 */ {8u, 0u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CTR_256] */
  /*     9 */ {9u, 0u}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_ECB_256] */
  /*    10 */ {10u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_ECB_SHE] */
  /*    11 */ {11u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_RSA_4096_OAEP_SHA2_256] */
  /*    12 */ {12u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CBC_256] */
  /*    13 */ {13u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CBC_SHE] */
  /*    14 */ {14u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CFB_128] */
  /*    15 */ {15u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CTR_256] */
  /*    16 */ {16u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_ECB_256] */
  /*    17 */ {17u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_ECB_SHE] */
  /*    18 */ {18u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_RSA_4096_OAEP_SHA2_256] */
  /*    19 */ {19u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Hash_SHA2_256] */
  /*    20 */ {20u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Hash_SHA2_256_ASYNC_1] */
  /*    21 */ {21u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Hash_SHA2_256_ASYNC_2] */
  /*    22 */ {22u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Generate_128] */
  /*    23 */ {23u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Generate_256] */
  /*    24 */ {24u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Generate_SHE] */
  /*    25 */ {25u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Verify_128] */
  /*    26 */ {26u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Verify_256] */
  /*    27 */ {27u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Verify_SHE] */
  /*    28 */ {28u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_HMAC_SHA2_512] */
  /*    29 */ {29u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_HMAC_Verify_SHA2_512] */
  /*    30 */ {30u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_RNG] */
  /*    31 */ {31u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_RNG_DRBG] */
  /*    32 */ {32u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ECCBrainpool_256R1_SHA256] */
  /*    33 */ {33u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ECCBrainpool_256T1_SHA256] */
  /*    34 */ {34u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ECCNIST_256_SHA256] */
  /*    35 */ {35u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ED448] */
  /*    36 */ {36u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_Ed25519_256] */
  /*    37 */ {37u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_RSAPSS_1024] */
  /*    38 */ {38u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ECCBrainpool_256R1_SHA256] */
  /*    39 */ {39u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ECCBrainpool_256T1_SHA256] */
  /*    40 */ {40u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ECCNIST_256] */
  /*    41 */ {41u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ED448] */
  /*    42 */ {42u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_Ed25519_256] */
  /*    43 */ {43u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_RSAPSS_1024] */
  /*    44 */ {44u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/MKA_CMACGenerate] */
  /*    45 */ {45u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/MKA_CMACVerify] */
  /*    46 */ {46u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/MKA_Decrypt_ECB] */
  /*    47 */ {47u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/MKA_Encrypt_ECB] */
  /*    48 */ {48u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/MKA_Hash_Key_Derivation] */
  /*    49 */ {49u, 0u} ,  /* [/ActiveEcuC/Csm/CsmJobs/MKA_KeyDerivationPRF] */
  /* Index     JobInfo        Referable Keys */
  /*    50 */ {50u, 0u}    /* [/ActiveEcuC/Csm/CsmJobs/MKA_Random] */
};
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
CONST(Crypto_JobPrimitiveInfoType, CSM_CONST) Csm_JobPrimitiveInfo[48] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     JobPrimitiveInfo                                                                                               Referable Keys */
  /*     0 */ {0u, &Csm_PrimitiveInfo[10], CryIfConf_CryIfKey_CryIfKey_Crypto_AES_128, CRYPTO_PROCESSING_SYNC}          ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_AEAD_GCM_Decrypt] */
  /*     1 */ {0u, &Csm_PrimitiveInfo[9], CryIfConf_CryIfKey_CryIfKey_Crypto_AES_128, CRYPTO_PROCESSING_SYNC}           ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_AEAD_GCM_Encrypt] */
  /*     2 */ {0u, &Csm_PrimitiveInfo[12], CryIfConf_CryIfKey_CryIfKey_Crypto_AES_256, CRYPTO_PROCESSING_SYNC}          ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256] */
  /*     3 */ {0u, &Csm_PrimitiveInfo[12], CryIfConf_CryIfKey_CryIfKey_Crypto_AES_256, CRYPTO_PROCESSING_ASYNC}         ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256_ASYNC_1, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256_ASYNC_2, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256_ASYNC_3] */
  /*     4 */ {0u, &Csm_PrimitiveInfo[35], CryIfConf_CryIfKey_CryIfKey_SHE_KEY_1, CRYPTO_PROCESSING_SYNC}               ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_SHE] */
  /*     5 */ {0u, &Csm_PrimitiveInfo[8], CryIfConf_CryIfKey_CryIfKey_Crypto_AES_128, CRYPTO_PROCESSING_SYNC}           ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CFB_128] */
  /*     6 */ {0u, &Csm_PrimitiveInfo[13], CryIfConf_CryIfKey_CryIfKey_Crypto_AES_256, CRYPTO_PROCESSING_SYNC}          ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CTR_256] */
  /*     7 */ {0u, &Csm_PrimitiveInfo[14], CryIfConf_CryIfKey_CryIfKey_Crypto_AES_256, CRYPTO_PROCESSING_SYNC}          ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_ECB_256] */
  /*     8 */ {0u, &Csm_PrimitiveInfo[6], CryIfConf_CryIfKey_CryIfKey_SHE_KEY_1, CRYPTO_PROCESSING_SYNC}                ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_ECB_SHE] */
  /*     9 */ {0u, &Csm_PrimitiveInfo[26], CryIfConf_CryIfKey_CryIfKey_Crypto_RSA_4096_Key, CRYPTO_PROCESSING_SYNC}     ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_RSA_4096_OAEP_SHA2_256] */
  /*    10 */ {0u, &Csm_PrimitiveInfo[15], CryIfConf_CryIfKey_CryIfKey_Crypto_AES_256, CRYPTO_PROCESSING_SYNC}          ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CBC_256] */
  /*    11 */ {0u, &Csm_PrimitiveInfo[36], CryIfConf_CryIfKey_CryIfKey_SHE_KEY_1, CRYPTO_PROCESSING_SYNC}               ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CBC_SHE] */
  /*    12 */ {0u, &Csm_PrimitiveInfo[7], CryIfConf_CryIfKey_CryIfKey_Crypto_AES_128, CRYPTO_PROCESSING_SYNC}           ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CFB_128] */
  /*    13 */ {0u, &Csm_PrimitiveInfo[16], CryIfConf_CryIfKey_CryIfKey_Crypto_AES_256, CRYPTO_PROCESSING_SYNC}          ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CTR_256] */
  /*    14 */ {0u, &Csm_PrimitiveInfo[17], CryIfConf_CryIfKey_CryIfKey_Crypto_AES_256, CRYPTO_PROCESSING_SYNC}          ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_ECB_256] */
  /*    15 */ {0u, &Csm_PrimitiveInfo[1], CryIfConf_CryIfKey_CryIfKey_SHE_KEY_1, CRYPTO_PROCESSING_SYNC}                ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_ECB_SHE] */
  /*    16 */ {0u, &Csm_PrimitiveInfo[18], CryIfConf_CryIfKey_CryIfKey_Crypto_RSA_4096_Key, CRYPTO_PROCESSING_SYNC}     ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_RSA_4096_OAEP_SHA2_256] */
  /*    17 */ {0u, &Csm_PrimitiveInfo[2], CryIfConf_CryIfKey_CryIfKey_Crypto_Hash, CRYPTO_PROCESSING_SYNC}              ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Hash_SHA2_256] */
  /*    18 */ {0u, &Csm_PrimitiveInfo[2], CryIfConf_CryIfKey_CryIfKey_Crypto_Hash, CRYPTO_PROCESSING_ASYNC}             ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Hash_SHA2_256_ASYNC_1, /ActiveEcuC/Csm/CsmJobs/Crypto_Hash_SHA2_256_ASYNC_2] */
  /*    19 */ {0u, &Csm_PrimitiveInfo[4], CryIfConf_CryIfKey_CryIfKey_Crypto_AES_128, CRYPTO_PROCESSING_SYNC}           ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Generate_128] */
  /*    20 */ {0u, &Csm_PrimitiveInfo[22], CryIfConf_CryIfKey_CryIfKey_Crypto_AES_256, CRYPTO_PROCESSING_SYNC}          ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Generate_256] */
  /*    21 */ {0u, &Csm_PrimitiveInfo[4], CryIfConf_CryIfKey_CryIfKey_SHE_KEY_7, CRYPTO_PROCESSING_SYNC}                ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Generate_SHE] */
  /*    22 */ {0u, &Csm_PrimitiveInfo[5], CryIfConf_CryIfKey_CryIfKey_Crypto_AES_128, CRYPTO_PROCESSING_SYNC}           ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Verify_128] */
  /*    23 */ {0u, &Csm_PrimitiveInfo[23], CryIfConf_CryIfKey_CryIfKey_Crypto_AES_256, CRYPTO_PROCESSING_SYNC}          ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Verify_256] */
  /*    24 */ {0u, &Csm_PrimitiveInfo[5], CryIfConf_CryIfKey_CryIfKey_SHE_KEY_7, CRYPTO_PROCESSING_SYNC}                ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Verify_SHE] */
  /*    25 */ {0u, &Csm_PrimitiveInfo[11], CryIfConf_CryIfKey_CryIfKey_Crypto_Hash, CRYPTO_PROCESSING_SYNC}             ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_HMAC_SHA2_512] */
  /*    26 */ {0u, &Csm_PrimitiveInfo[33], CryIfConf_CryIfKey_CryIfKey_Crypto_Hash, CRYPTO_PROCESSING_SYNC}             ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_HMAC_Verify_SHA2_512] */
  /*    27 */ {0u, &Csm_PrimitiveInfo[3], CryIfConf_CryIfKey_CryIfKey_Crypto_RNG, CRYPTO_PROCESSING_SYNC}               ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_RNG] */
  /*    28 */ {0u, &Csm_PrimitiveInfo[21], CryIfConf_CryIfKey_CryIfKey_Crypto_RNG, CRYPTO_PROCESSING_SYNC}              ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_RNG_DRBG] */
  /*    29 */ {0u, &Csm_PrimitiveInfo[29], CryIfConf_CryIfKey_CryIfKey_ECC_256_Key_SigGenerate, CRYPTO_PROCESSING_SYNC} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ECCBrainpool_256R1_SHA256] */
  /*    30 */ {0u, &Csm_PrimitiveInfo[30], CryIfConf_CryIfKey_CryIfKey_ECC_256_Key_SigGenerate, CRYPTO_PROCESSING_SYNC} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ECCBrainpool_256T1_SHA256] */
  /*    31 */ {0u, &Csm_PrimitiveInfo[0], CryIfConf_CryIfKey_CryIfKey_ECC_256_Key_SigGenerate, CRYPTO_PROCESSING_SYNC}  ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ECCNIST_256_SHA256] */
  /*    32 */ {0u, &Csm_PrimitiveInfo[31], CryIfConf_CryIfKey_CryIfKey_ED448_Key_SigGenerate, CRYPTO_PROCESSING_SYNC}   ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ED448] */
  /*    33 */ {0u, &Csm_PrimitiveInfo[24], CryIfConf_CryIfKey_CryIfKey_ED25519_Key_SigGenerate, CRYPTO_PROCESSING_SYNC} ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_Ed25519_256] */
  /*    34 */ {0u, &Csm_PrimitiveInfo[27], CryIfConf_CryIfKey_CryIfKey_Crypto_RSA_1024_Key, CRYPTO_PROCESSING_SYNC}     ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_RSAPSS_1024] */
  /*    35 */ {0u, &Csm_PrimitiveInfo[20], CryIfConf_CryIfKey_CryIfKey_ECC_256_Key_SigVerify, CRYPTO_PROCESSING_SYNC}   ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ECCBrainpool_256R1_SHA256] */
  /*    36 */ {0u, &Csm_PrimitiveInfo[34], CryIfConf_CryIfKey_CryIfKey_ECC_256_Key_SigVerify, CRYPTO_PROCESSING_SYNC}   ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ECCBrainpool_256T1_SHA256] */
  /*    37 */ {0u, &Csm_PrimitiveInfo[19], CryIfConf_CryIfKey_CryIfKey_ECC_256_Key_SigVerify, CRYPTO_PROCESSING_SYNC}   ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ECCNIST_256] */
  /*    38 */ {0u, &Csm_PrimitiveInfo[32], CryIfConf_CryIfKey_CryIfKey_ED448_Key_SigVerify, CRYPTO_PROCESSING_SYNC}     ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ED448] */
  /*    39 */ {0u, &Csm_PrimitiveInfo[25], CryIfConf_CryIfKey_CryIfKey_ED25519_Key_SigVerify, CRYPTO_PROCESSING_SYNC}   ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_Ed25519_256] */
  /*    40 */ {0u, &Csm_PrimitiveInfo[28], CryIfConf_CryIfKey_CryIfKey_Crypto_RSA_1024_Key, CRYPTO_PROCESSING_SYNC}     ,  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_RSAPSS_1024] */
  /*    41 */ {0u, &Csm_PrimitiveInfo[4], CryIfConf_CryIfKey_CryIfKey_MKA_ICK, CRYPTO_PROCESSING_SYNC}                  ,  /* [/ActiveEcuC/Csm/CsmJobs/MKA_CMACGenerate] */
  /*    42 */ {0u, &Csm_PrimitiveInfo[5], CryIfConf_CryIfKey_CryIfKey_MKA_ICK, CRYPTO_PROCESSING_SYNC}                  ,  /* [/ActiveEcuC/Csm/CsmJobs/MKA_CMACVerify] */
  /*    43 */ {0u, &Csm_PrimitiveInfo[6], CryIfConf_CryIfKey_CryIfKey_MKA_KEK, CRYPTO_PROCESSING_SYNC}                  ,  /* [/ActiveEcuC/Csm/CsmJobs/MKA_Decrypt_ECB] */
  /*    44 */ {0u, &Csm_PrimitiveInfo[1], CryIfConf_CryIfKey_CryIfKey_MKA_KEK, CRYPTO_PROCESSING_SYNC}                  ,  /* [/ActiveEcuC/Csm/CsmJobs/MKA_Encrypt_ECB] */
  /*    45 */ {0u, &Csm_PrimitiveInfo[1], CryIfConf_CryIfKey_CryIfKey_MKA_SAK, CRYPTO_PROCESSING_SYNC}                  ,  /* [/ActiveEcuC/Csm/CsmJobs/MKA_Hash_Key_Derivation] */
  /*    46 */ {0u, &Csm_PrimitiveInfo[4], CryIfConf_CryIfKey_CryIfKey_MKA_MAC, CRYPTO_PROCESSING_SYNC}                  ,  /* [/ActiveEcuC/Csm/CsmJobs/MKA_KeyDerivationPRF] */
  /*    47 */ {0u, &Csm_PrimitiveInfo[3], CryIfConf_CryIfKey_CryIfKey_MKA_Random, CRYPTO_PROCESSING_SYNC}                  /* [/ActiveEcuC/Csm/CsmJobs/MKA_Random] */
};
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
CONST(Csm_JobTableType, CSM_CONST) Csm_JobTable[51] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    BswCallbacksIdx                   CsmKeyIdIdx  JobPrimitiveInfoIdx  MaskedBits  Priority  QueueInfoIdx        Referable Keys */
  { /*     0 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          2u,                  0u,      0x00u,       0u,           0u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_AEAD_GCM_Decrypt, /ActiveEcuC/Csm/CsmJobs] */
  { /*     1 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          2u,                  1u,      0x00u,       0u,           0u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_AEAD_GCM_Encrypt, /ActiveEcuC/Csm/CsmJobs] */
  { /*     2 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          3u,                  2u,      0x00u,       0u,           0u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256, /ActiveEcuC/Csm/CsmJobs] */
  { /*     3 */                               0u,          3u,                  3u,      0x02u,       0u,           1u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256_ASYNC_1, /ActiveEcuC/Csm/CsmJobs] */
  { /*     4 */                               0u,          3u,                  3u,      0x02u,       0u,           1u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256_ASYNC_2, /ActiveEcuC/Csm/CsmJobs] */
  { /*     5 */                               0u,          3u,                  3u,      0x02u,       0u,           1u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256_ASYNC_3, /ActiveEcuC/Csm/CsmJobs] */
  { /*     6 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         51u,                  4u,      0x00u,       0u,           0u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_SHE, /ActiveEcuC/Csm/CsmJobs] */
  { /*     7 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          2u,                  5u,      0x00u,       0u,           0u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CFB_128, /ActiveEcuC/Csm/CsmJobs] */
  { /*     8 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          3u,                  6u,      0x00u,       0u,           0u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CTR_256, /ActiveEcuC/Csm/CsmJobs] */
  { /*     9 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          3u,                  7u,      0x00u,       0u,           0u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_ECB_256, /ActiveEcuC/Csm/CsmJobs] */
  { /*    10 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         51u,                  8u,      0x00u,       0u,           0u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_ECB_SHE, /ActiveEcuC/Csm/CsmJobs] */
  { /*    11 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          9u,                  9u,      0x00u,       0u,           5u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_RSA_4096_OAEP_SHA2_256, /ActiveEcuC/Csm/CsmJobs] */
  { /*    12 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          3u,                 10u,      0x00u,       0u,           0u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CBC_256, /ActiveEcuC/Csm/CsmJobs] */
  { /*    13 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         51u,                 11u,      0x00u,       0u,           0u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CBC_SHE, /ActiveEcuC/Csm/CsmJobs] */
  { /*    14 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          2u,                 12u,      0x00u,       0u,           0u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CFB_128, /ActiveEcuC/Csm/CsmJobs] */
  { /*    15 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          3u,                 13u,      0x00u,       0u,           0u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CTR_256, /ActiveEcuC/Csm/CsmJobs] */
  { /*    16 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          3u,                 14u,      0x00u,       0u,           0u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_ECB_256, /ActiveEcuC/Csm/CsmJobs] */
  { /*    17 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         51u,                 15u,      0x00u,       0u,           0u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_ECB_SHE, /ActiveEcuC/Csm/CsmJobs] */
  { /*    18 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          9u,                 16u,      0x00u,       0u,           5u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_RSA_4096_OAEP_SHA2_256, /ActiveEcuC/Csm/CsmJobs] */
  { /*    19 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          4u,                 17u,      0x00u,       0u,           2u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Hash_SHA2_256, /ActiveEcuC/Csm/CsmJobs] */
  { /*    20 */                               0u,          4u,                 18u,      0x02u,       0u,           3u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Hash_SHA2_256_ASYNC_1, /ActiveEcuC/Csm/CsmJobs] */
  { /*    21 */                               0u,          4u,                 18u,      0x02u,       0u,           3u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Hash_SHA2_256_ASYNC_2, /ActiveEcuC/Csm/CsmJobs] */
  { /*    22 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          2u,                 19u,      0x00u,       0u,           0u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Generate_128, /ActiveEcuC/Csm/CsmJobs] */
  { /*    23 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          3u,                 20u,      0x00u,       0u,           0u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Generate_256, /ActiveEcuC/Csm/CsmJobs] */
  { /*    24 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         57u,                 21u,      0x00u,       0u,           0u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Generate_SHE, /ActiveEcuC/Csm/CsmJobs] */
  { /*    25 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          2u,                 22u,      0x00u,       0u,           0u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Verify_128, /ActiveEcuC/Csm/CsmJobs] */
  { /*    26 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          3u,                 23u,      0x00u,       0u,           0u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Verify_256, /ActiveEcuC/Csm/CsmJobs] */
  { /*    27 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         57u,                 24u,      0x00u,       0u,           0u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Verify_SHE, /ActiveEcuC/Csm/CsmJobs] */
  { /*    28 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          4u,                 25u,      0x00u,       0u,           2u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_HMAC_SHA2_512, /ActiveEcuC/Csm/CsmJobs] */
  { /*    29 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          4u,                 26u,      0x00u,       0u,           2u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_HMAC_Verify_SHA2_512, /ActiveEcuC/Csm/CsmJobs] */
  { /*    30 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          5u,                 27u,      0x00u,       0u,           2u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_RNG, /ActiveEcuC/Csm/CsmJobs] */
  { /*    31 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          5u,                 28u,      0x00u,       0u,           2u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_RNG_DRBG, /ActiveEcuC/Csm/CsmJobs] */
  { /*    32 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         18u,                 29u,      0x00u,       0u,           5u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ECCBrainpool_256R1_SHA256, /ActiveEcuC/Csm/CsmJobs] */
  { /*    33 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         18u,                 30u,      0x00u,       0u,           5u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ECCBrainpool_256T1_SHA256, /ActiveEcuC/Csm/CsmJobs] */
  { /*    34 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         18u,                 31u,      0x00u,       0u,           5u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ECCNIST_256_SHA256, /ActiveEcuC/Csm/CsmJobs] */
  { /*    35 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         38u,                 32u,      0x00u,       0u,           5u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ED448, /ActiveEcuC/Csm/CsmJobs] */
  { /*    36 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         40u,                 33u,      0x00u,       0u,           5u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_Ed25519_256, /ActiveEcuC/Csm/CsmJobs] */
  { /*    37 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          6u,                 34u,      0x00u,       0u,           5u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_RSAPSS_1024, /ActiveEcuC/Csm/CsmJobs] */
  { /*    38 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         19u,                 35u,      0x00u,       0u,           5u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ECCBrainpool_256R1_SHA256, /ActiveEcuC/Csm/CsmJobs] */
  { /*    39 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         19u,                 36u,      0x00u,       0u,           5u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ECCBrainpool_256T1_SHA256, /ActiveEcuC/Csm/CsmJobs] */
  { /*    40 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         19u,                 37u,      0x00u,       0u,           5u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ECCNIST_256, /ActiveEcuC/Csm/CsmJobs] */
  { /*    41 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         39u,                 38u,      0x00u,       0u,           5u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ED448, /ActiveEcuC/Csm/CsmJobs] */
  { /*    42 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         41u,                 39u,      0x00u,       0u,           5u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_Ed25519_256, /ActiveEcuC/Csm/CsmJobs] */
  { /*    43 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,          6u,                 40u,      0x00u,       0u,           5u },  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_RSAPSS_1024, /ActiveEcuC/Csm/CsmJobs] */
  { /*    44 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         43u,                 41u,      0x00u,       0u,           4u },  /* [/ActiveEcuC/Csm/CsmJobs/MKA_CMACGenerate, /ActiveEcuC/Csm/CsmJobs] */
  { /*    45 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         43u,                 42u,      0x00u,       0u,           4u },  /* [/ActiveEcuC/Csm/CsmJobs/MKA_CMACVerify, /ActiveEcuC/Csm/CsmJobs] */
  { /*    46 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         44u,                 43u,      0x00u,       0u,           4u },  /* [/ActiveEcuC/Csm/CsmJobs/MKA_Decrypt_ECB, /ActiveEcuC/Csm/CsmJobs] */
  { /*    47 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         44u,                 44u,      0x00u,       0u,           4u },  /* [/ActiveEcuC/Csm/CsmJobs/MKA_Encrypt_ECB, /ActiveEcuC/Csm/CsmJobs] */
  { /*    48 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         47u,                 45u,      0x00u,       0u,           4u },  /* [/ActiveEcuC/Csm/CsmJobs/MKA_Hash_Key_Derivation, /ActiveEcuC/Csm/CsmJobs] */
  { /*    49 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         45u,                 46u,      0x00u,       0u,           4u },  /* [/ActiveEcuC/Csm/CsmJobs/MKA_KeyDerivationPRF, /ActiveEcuC/Csm/CsmJobs] */
    /* Index    BswCallbacksIdx                   CsmKeyIdIdx  JobPrimitiveInfoIdx  MaskedBits  Priority  QueueInfoIdx        Referable Keys */
  { /*    50 */ CSM_NO_BSWCALLBACKSIDXOFJOBTABLE,         46u,                 47u,      0x00u,       0u,           4u }   /* [/ActiveEcuC/Csm/CsmJobs/MKA_Random, /ActiveEcuC/Csm/CsmJobs] */
};
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
CONST(Csm_KeyType, CSM_CONST) Csm_Key[62] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CryIfKeyId                                                  Referable Keys */
  { /*     0 */ CryIfConf_CryIfKey_CryIfKey_Boot_MAC                 },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Boot_MAC, /ActiveEcuC/Csm/CsmKeys] */
  { /*     1 */ CryIfConf_CryIfKey_CryIfKey_Boot_MAC_Key             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Boot_MAC_Key, /ActiveEcuC/Csm/CsmKeys] */
  { /*     2 */ CryIfConf_CryIfKey_CryIfKey_Crypto_AES_128           },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Crypto_AES_128, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CFB_128:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CFB_128:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Generate_128:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Verify_128:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_AEAD_GCM_Encrypt:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_AEAD_GCM_Decrypt:CsmJobKeyRef, /ActiveEcuC/Csm/Crypto_AEAD_GCM_Encrypt/CsmAEADEncrypt/Crypto_AEAD_GCM_Encrypt:CsmAEADEncryptKeyRef, /ActiveEcuC/Csm/Crypto_AEAD_GCM_Decrypt/CsmAEADDecrypt/Crypto_AEAD_GCM_Decrypt:CsmAEADDecryptKeyRef] */
  { /*     3 */ CryIfConf_CryIfKey_CryIfKey_Crypto_AES_256           },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Crypto_AES_256, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CTR_256:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CBC_256:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_ECB_256:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CTR_256:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_ECB_256:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Generate_256:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Verify_256:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256_ASYNC_1:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256_ASYNC_2:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256_ASYNC_3:CsmJobKeyRef] */
  { /*     4 */ CryIfConf_CryIfKey_CryIfKey_Crypto_Hash              },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Crypto_Hash, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/Crypto_Hash_SHA2_256:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_MAC_HMAC_SHA2_512:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_MAC_HMAC_Verify_SHA2_512:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Hash_SHA2_256_ASYNC_1:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Hash_SHA2_256_ASYNC_2:CsmJobKeyRef] */
  { /*     5 */ CryIfConf_CryIfKey_CryIfKey_Crypto_RNG               },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Crypto_RNG, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/Crypto_RNG:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_RNG_DRBG:CsmJobKeyRef] */
  { /*     6 */ CryIfConf_CryIfKey_CryIfKey_Crypto_RSA_1024_Key      },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Crypto_RSA_1024, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_RSAPSS_1024:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_RSAPSS_1024:CsmJobKeyRef] */
  { /*     7 */ CryIfConf_CryIfKey_CryIfKey_Crypto_RSA_2048_Key      },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Crypto_RSA_2048, /ActiveEcuC/Csm/CsmKeys] */
  { /*     8 */ CryIfConf_CryIfKey_CryIfKey_Crypto_RSA_3072_Key      },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Crypto_RSA_3072, /ActiveEcuC/Csm/CsmKeys] */
  { /*     9 */ CryIfConf_CryIfKey_CryIfKey_Crypto_RSA_4096_Key      },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Crypto_RSA_4096, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_RSA_4096_OAEP_SHA2_256:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_RSA_4096_OAEP_SHA2_256:CsmJobKeyRef] */
  { /*    10 */ CryIfConf_CryIfKey_CryIfKey_Custom_Operations        },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Custom_Operations, /ActiveEcuC/Csm/CsmKeys] */
  { /*    11 */ CryIfConf_CryIfKey_CryIfKey_ECC_192_Key_SigGenerate  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_192_Key_SigGenerate, /ActiveEcuC/Csm/CsmKeys] */
  { /*    12 */ CryIfConf_CryIfKey_CryIfKey_ECC_192_Key_SigVerify    },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_192_Key_SigVerify, /ActiveEcuC/Csm/CsmKeys] */
  { /*    13 */ CryIfConf_CryIfKey_CryIfKey_ECC_224_Key_SigGenerate  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_224_Key_SigGenerate, /ActiveEcuC/Csm/CsmKeys] */
  { /*    14 */ CryIfConf_CryIfKey_CryIfKey_ECC_224_Key_Exchange     },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_224_Key_Exchange, /ActiveEcuC/Csm/CsmKeys] */
  { /*    15 */ CryIfConf_CryIfKey_CryIfKey_ECC_224_Key_SigVerify    },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_224_Key_SigVerify, /ActiveEcuC/Csm/CsmKeys] */
  { /*    16 */ CryIfConf_CryIfKey_CryIfKey_ECC_256_Key_Generate     },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_256_Key_Generate, /ActiveEcuC/Csm/CsmKeys] */
  { /*    17 */ CryIfConf_CryIfKey_CryIfKey_ECC_256_Key_Generate_2   },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_256_Key_Generate_2, /ActiveEcuC/Csm/CsmKeys] */
  { /*    18 */ CryIfConf_CryIfKey_CryIfKey_ECC_256_Key_SigGenerate  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_256_Key_SigGenerate, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ECCNIST_256_SHA256:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ECCBrainpool_256R1_SHA256:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ECCBrainpool_256T1_SHA256:CsmJobKeyRef] */
  { /*    19 */ CryIfConf_CryIfKey_CryIfKey_ECC_256_Key_SigVerify    },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_256_Key_SigVerify, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ECCNIST_256:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ECCBrainpool_256T1_SHA256:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ECCBrainpool_256R1_SHA256:CsmJobKeyRef] */
  { /*    20 */ CryIfConf_CryIfKey_CryIfKey_ECC_320_Key_SigGenerate  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_320_Key_SigGenerate, /ActiveEcuC/Csm/CsmKeys] */
  { /*    21 */ CryIfConf_CryIfKey_CryIfKey_ECC_320_Key_SigVerify    },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_320_Key_SigVerify, /ActiveEcuC/Csm/CsmKeys] */
  { /*    22 */ CryIfConf_CryIfKey_CryIfKey_ECC_384_Key_SigGenerate  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_384_Key_SigGenerate, /ActiveEcuC/Csm/CsmKeys] */
  { /*    23 */ CryIfConf_CryIfKey_CryIfKey_ECC_384_Key_SigVerify    },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_384_Key_SigVerify, /ActiveEcuC/Csm/CsmKeys] */
  { /*    24 */ CryIfConf_CryIfKey_CryIfKey_ECC_512_Key_SigGenerate  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_512_Key_SigGenerate, /ActiveEcuC/Csm/CsmKeys] */
  { /*    25 */ CryIfConf_CryIfKey_CryIfKey_ECC_512_Key_SigVerify    },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_512_Key_SigVerify, /ActiveEcuC/Csm/CsmKeys] */
  { /*    26 */ CryIfConf_CryIfKey_CryIfKey_ECC_521_Key_SigGenerate  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_521_Key_SigGenerate, /ActiveEcuC/Csm/CsmKeys] */
  { /*    27 */ CryIfConf_CryIfKey_CryIfKey_ECC_521_Key_SigVerify    },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_521_Key_SigVerify, /ActiveEcuC/Csm/CsmKeys] */
  { /*    28 */ CryIfConf_CryIfKey_CryIfKey_ECDH_128_Key_SigGenerate },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECDH_128_Key_SigGenerate, /ActiveEcuC/Csm/CsmKeys] */
  { /*    29 */ CryIfConf_CryIfKey_CryIfKey_ECDH_128_Key_SigVerify   },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECDH_128_Key_SigVerify, /ActiveEcuC/Csm/CsmKeys] */
  { /*    30 */ CryIfConf_CryIfKey_CryIfKey_ECDH_224_Key_SigGenerate },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECDH_224_Key_SigGenerate, /ActiveEcuC/Csm/CsmKeys] */
  { /*    31 */ CryIfConf_CryIfKey_CryIfKey_ECDH_224_Key_SigVerify   },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECDH_224_Key_SigVerify, /ActiveEcuC/Csm/CsmKeys] */
  { /*    32 */ CryIfConf_CryIfKey_CryIfKey_ECDH_256_Key_SigGenerate },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECDH_256_Key_SigGenerate, /ActiveEcuC/Csm/CsmKeys] */
  { /*    33 */ CryIfConf_CryIfKey_CryIfKey_ECDH_256_Key_SigVerify   },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECDH_256_Key_SigVerify, /ActiveEcuC/Csm/CsmKeys] */
  { /*    34 */ CryIfConf_CryIfKey_CryIfKey_ECDH_384_Key_SigGenerate },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECDH_384_Key_SigGenerate, /ActiveEcuC/Csm/CsmKeys] */
  { /*    35 */ CryIfConf_CryIfKey_CryIfKey_ECDH_384_Key_SigVerify   },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECDH_384_Key_SigVerify, /ActiveEcuC/Csm/CsmKeys] */
  { /*    36 */ CryIfConf_CryIfKey_CryIfKey_ECDH_512_Key_SigGenerate },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECDH_512_Key_SigGenerate, /ActiveEcuC/Csm/CsmKeys] */
  { /*    37 */ CryIfConf_CryIfKey_CryIfKey_ECDH_512_Key_SigVerify   },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ECDH_512_Key_SigVerify, /ActiveEcuC/Csm/CsmKeys] */
  { /*    38 */ CryIfConf_CryIfKey_CryIfKey_ED448_Key_SigGenerate    },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ED448_Key_SigGenerate, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ED448:CsmJobKeyRef] */
  { /*    39 */ CryIfConf_CryIfKey_CryIfKey_ED448_Key_SigVerify      },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ED448_Key_SigVerify, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ED448:CsmJobKeyRef] */
  { /*    40 */ CryIfConf_CryIfKey_CryIfKey_ED25519_Key_SigGenerate  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ED25519_Key_SigGenerate, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_Ed25519_256:CsmJobKeyRef] */
  { /*    41 */ CryIfConf_CryIfKey_CryIfKey_ED25519_Key_SigVerify    },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_ED25519_Key_SigVerify, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_Ed25519_256:CsmJobKeyRef] */
  { /*    42 */ CryIfConf_CryIfKey_CryIfKey_MKA_CAK                  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_MKA_CAK, /ActiveEcuC/Csm/CsmKeys] */
  { /*    43 */ CryIfConf_CryIfKey_CryIfKey_MKA_ICK                  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_MKA_ICK, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/MKA_CMACGenerate:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/MKA_CMACVerify:CsmJobKeyRef] */
  { /*    44 */ CryIfConf_CryIfKey_CryIfKey_MKA_KEK                  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_MKA_KEK, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/MKA_Encrypt_ECB:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/MKA_Decrypt_ECB:CsmJobKeyRef] */
  { /*    45 */ CryIfConf_CryIfKey_CryIfKey_MKA_MAC                  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_MKA_MAC, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/MKA_KeyDerivationPRF:CsmJobKeyRef] */
  { /*    46 */ CryIfConf_CryIfKey_CryIfKey_MKA_Random               },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_MKA_Random, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/MKA_Random:CsmJobKeyRef] */
  { /*    47 */ CryIfConf_CryIfKey_CryIfKey_MKA_SAK                  },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_MKA_SAK, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/MKA_Hash_Key_Derivation:CsmJobKeyRef] */
  { /*    48 */ CryIfConf_CryIfKey_CryIfKey_MKA_SAK_Data             },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_MKA_SAK_Data, /ActiveEcuC/Csm/CsmKeys] */
  { /*    49 */ CryIfConf_CryIfKey_CryIfKey_Master_ECU_Key           },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Master_ECU_Key, /ActiveEcuC/Csm/CsmKeys] */
    /* Index    CryIfKeyId                                                  Referable Keys */
  { /*    50 */ CryIfConf_CryIfKey_CryIfKey_Monotonic_Counter        },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_Monotonic_Counter, /ActiveEcuC/Csm/CsmKeys] */
  { /*    51 */ CryIfConf_CryIfKey_CryIfKey_SHE_KEY_1                },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SHE_KEY_1, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_SHE:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_ECB_SHE:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CBC_SHE:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_ECB_SHE:CsmJobKeyRef] */
  { /*    52 */ CryIfConf_CryIfKey_CryIfKey_SHE_KEY_2                },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SHE_KEY_2, /ActiveEcuC/Csm/CsmKeys] */
  { /*    53 */ CryIfConf_CryIfKey_CryIfKey_SHE_KEY_3                },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SHE_KEY_3, /ActiveEcuC/Csm/CsmKeys] */
  { /*    54 */ CryIfConf_CryIfKey_CryIfKey_SHE_KEY_4                },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SHE_KEY_4, /ActiveEcuC/Csm/CsmKeys] */
  { /*    55 */ CryIfConf_CryIfKey_CryIfKey_SHE_KEY_5                },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SHE_KEY_5, /ActiveEcuC/Csm/CsmKeys] */
  { /*    56 */ CryIfConf_CryIfKey_CryIfKey_SHE_KEY_6                },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SHE_KEY_6, /ActiveEcuC/Csm/CsmKeys] */
  { /*    57 */ CryIfConf_CryIfKey_CryIfKey_SHE_KEY_7                },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SHE_KEY_7, /ActiveEcuC/Csm/CsmKeys, /ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Generate_SHE:CsmJobKeyRef, /ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Verify_SHE:CsmJobKeyRef] */
  { /*    58 */ CryIfConf_CryIfKey_CryIfKey_SHE_KEY_8                },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SHE_KEY_8, /ActiveEcuC/Csm/CsmKeys] */
  { /*    59 */ CryIfConf_CryIfKey_CryIfKey_SHE_KEY_9                },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SHE_KEY_9, /ActiveEcuC/Csm/CsmKeys] */
  { /*    60 */ CryIfConf_CryIfKey_CryIfKey_SHE_KEY_10               },  /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SHE_KEY_10, /ActiveEcuC/Csm/CsmKeys] */
  { /*    61 */ CryIfConf_CryIfKey_CryIfKey_SHE_RAM_KEY              }   /* [/ActiveEcuC/Csm/CsmKeys/CsmKey_SHE_RAM_KEY, /ActiveEcuC/Csm/CsmKeys] */
};
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
CONST(Csm_PartitionIdentifiersType, CSM_CONST) Csm_PartitionIdentifiers[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionSNV         */
  { /*     0 */ CSM_SINGLE_PARTITION }
};
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
CONST(Crypto_PrimitiveInfoType, CSM_CONST) Csm_PrimitiveInfo[37] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     PrimitiveInfo                                                                                                                                               Referable Keys */
  /*     0 */ {CRYPTO_SIGNATUREGENERATE, {CRYPTO_ALGOFAM_ECCNIST, CRYPTO_ALGOFAM_SHA2_256, 32u, 130u} /*  Mode = CRYPTO_ALGOMODE_CUSTOM_ECCNIST_P256R1  */ }         ,  /* [/ActiveEcuC/Csm/Crypto_SigGen_ECCNIST_256_SHA256/CsmSignatureGenerate/Crypto_SigGen_ECCNIST_256_SHA256] */
  /*     1 */ {CRYPTO_ENCRYPT, {CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_NOT_SET, 16u, CRYPTO_ALGOMODE_ECB}}                                                               ,  /* [/ActiveEcuC/Csm/MKA_Encrypt_ECB/CsmEncrypt/MKA_Encrypt_ECB, /ActiveEcuC/Csm/Crypto_Encrypt_AES_ECB_SHE/CsmEncrypt/Crypto_Encrypt_AES_ECB_SHE] */
  /*     2 */ {CRYPTO_HASH, {CRYPTO_ALGOFAM_SHA2_256, CRYPTO_ALGOFAM_NOT_SET, 0u, CRYPTO_ALGOMODE_NOT_SET}}                                                          ,  /* [/ActiveEcuC/Csm/Crypto_Hash_SHA2_256/CsmHash/Crypto_Hash_SHA2_256, /ActiveEcuC/Csm/Crypto_Hash_SHA2_256_ASYNC/CsmHash/Crypto_Hash_SHA2_256_ASYNC] */
  /*     3 */ {CRYPTO_RANDOMGENERATE, {CRYPTO_ALGOFAM_RNG, CRYPTO_ALGOFAM_NOT_SET, 0u, CRYPTO_ALGOMODE_NOT_SET}}                                                     ,  /* [/ActiveEcuC/Csm/MKA_Random/CsmRandomGenerate/MKA_Random, /ActiveEcuC/Csm/Crypto_RNG/CsmRandomGenerate/Crypto_RNG] */
  /*     4 */ {CRYPTO_MACGENERATE, {CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_NOT_SET, 16u, CRYPTO_ALGOMODE_CMAC}}                                                          ,  /* [/ActiveEcuC/Csm/MKA_KeyDerivationPRF/CsmMacGenerate/MKA_KeyDerivationPRF, /ActiveEcuC/Csm/MKA_CMACGenerate/CsmMacGenerate/MKA_CMACGenerate, /ActiveEcuC/Csm/Crypto_MAC_CMAC_Generate_128/CsmMacGenerate/Crypto_MAC_CMAC_Generate_128, /ActiveEcuC/Csm/Crypto_MAC_CMAC_Generate_SHE/CsmMacGenerate/Crypto_MAC_CMAC_Generate_SHE] */
  /*     5 */ {CRYPTO_MACVERIFY, {CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_NOT_SET, 16u, CRYPTO_ALGOMODE_CMAC}}                                                            ,  /* [/ActiveEcuC/Csm/MKA_CMACVerify/CsmMacVerify/MKA_CMACVerify, /ActiveEcuC/Csm/Crypto_MAC_CMAC_Verify_128/CsmMacVerify/Crypto_MAC_CMAC_Verify_128, /ActiveEcuC/Csm/Crypto_MAC_CMAC_Verify_SHE/CsmMacVerify/Crypto_MAC_CMAC_Verify_SHE] */
  /*     6 */ {CRYPTO_DECRYPT, {CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_NOT_SET, 16u, CRYPTO_ALGOMODE_ECB}}                                                               ,  /* [/ActiveEcuC/Csm/MKA_Decrypt_ECB/CsmDecrypt/MKA_Decrypt_ECB, /ActiveEcuC/Csm/Crypto_Decrypt_AES_ECB_SHE/CsmDecrypt/Crypto_Decrypt_AES_ECB_SHE] */
  /*     7 */ {CRYPTO_ENCRYPT, {CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_NOT_SET, 16u, CRYPTO_ALGOMODE_CFB}}                                                               ,  /* [/ActiveEcuC/Csm/Crypto_Encrypt_AES_CFB_128/CsmEncrypt/Crypto_Encrypt_AES_CFB_128] */
  /*     8 */ {CRYPTO_DECRYPT, {CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_NOT_SET, 16u, CRYPTO_ALGOMODE_CFB}}                                                               ,  /* [/ActiveEcuC/Csm/Crypto_Decrypt_AES_CFB_128/CsmDecrypt/Crypto_Decrypt_AES_CFB_128] */
  /*     9 */ {CRYPTO_AEADENCRYPT, {CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_NOT_SET, 16u, CRYPTO_ALGOMODE_GCM}}                                                           ,  /* [/ActiveEcuC/Csm/Crypto_AEAD_GCM_Encrypt/CsmAEADEncrypt/Crypto_AEAD_GCM_Encrypt] */
  /*    10 */ {CRYPTO_AEADDECRYPT, {CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_NOT_SET, 16u, CRYPTO_ALGOMODE_GCM}}                                                           ,  /* [/ActiveEcuC/Csm/Crypto_AEAD_GCM_Decrypt/CsmAEADDecrypt/Crypto_AEAD_GCM_Decrypt] */
  /*    11 */ {CRYPTO_MACGENERATE, {CRYPTO_ALGOFAM_SHA2_512, CRYPTO_ALGOFAM_NOT_SET, 64u, CRYPTO_ALGOMODE_HMAC}}                                                     ,  /* [/ActiveEcuC/Csm/Crypto_MAC_HMAC_SHA2_512/CsmMacGenerate/Crypto_MAC_HMAC_SHA2_512] */
  /*    12 */ {CRYPTO_DECRYPT, {CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_PADDING_PKCS7, 32u, CRYPTO_ALGOMODE_CBC}}                                                         ,  /* [/ActiveEcuC/Csm/Crypto_Decrypt_AES_CBC_256/CsmDecrypt/Crypto_Decrypt_AES_CBC_256, /ActiveEcuC/Csm/Crypto_Decrypt_AES_CBC_256_ASYNC/CsmDecrypt/Crypto_Decrypt_AES_CBC_256_ASYNC] */
  /*    13 */ {CRYPTO_DECRYPT, {CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_NOT_SET, 32u, CRYPTO_ALGOMODE_CTR}}                                                               ,  /* [/ActiveEcuC/Csm/Crypto_Decrypt_AES_CTR_256/CsmDecrypt/Crypto_Decrypt_AES_CTR_256] */
  /*    14 */ {CRYPTO_DECRYPT, {CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_PADDING_PKCS7, 32u, CRYPTO_ALGOMODE_ECB}}                                                         ,  /* [/ActiveEcuC/Csm/Crypto_Decrypt_AES_ECB_256/CsmDecrypt/Crypto_Decrypt_AES_ECB_256] */
  /*    15 */ {CRYPTO_ENCRYPT, {CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_PADDING_PKCS7, 32u, CRYPTO_ALGOMODE_CBC}}                                                         ,  /* [/ActiveEcuC/Csm/Crypto_Encrypt_AES_CBC_256/CsmEncrypt/Crypto_Encrypt_AES_CBC_256] */
  /*    16 */ {CRYPTO_ENCRYPT, {CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_NOT_SET, 32u, CRYPTO_ALGOMODE_CTR}}                                                               ,  /* [/ActiveEcuC/Csm/Crypto_Encrypt_AES_CTR_256/CsmEncrypt/Crypto_Encrypt_AES_CTR_256] */
  /*    17 */ {CRYPTO_ENCRYPT, {CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_PADDING_PKCS7, 32u, CRYPTO_ALGOMODE_ECB}}                                                         ,  /* [/ActiveEcuC/Csm/Crypto_Encrypt_AES_ECB_256/CsmEncrypt/Crypto_Encrypt_AES_ECB_256] */
  /*    18 */ {CRYPTO_ENCRYPT, {CRYPTO_ALGOFAM_RSA, CRYPTO_ALGOFAM_SHA2_256, 512u, CRYPTO_ALGOMODE_RSAES_OAEP}}                                                      ,  /* [/ActiveEcuC/Csm/Crypto_Encrypt_RSA_4096_OAEP_SHA2_256/CsmEncrypt/Crypto_Encrypt_RSA_4096_OAEP_SHA2_256] */
  /*    19 */ {CRYPTO_SIGNATUREVERIFY, {CRYPTO_ALGOFAM_ECCNIST, CRYPTO_ALGOFAM_SHA2_256, 32u, 130u} /*  Mode = CRYPTO_ALGOMODE_CUSTOM_ECCNIST_P256R1  */ }           ,  /* [/ActiveEcuC/Csm/Crypto_SigVer_ECCNIST_256_SHA256/CsmSignatureVerify/Crypto_SigVer_ECCNIST_256_SHA256] */
  /*    20 */ {CRYPTO_SIGNATUREVERIFY, {CRYPTO_ALGOFAM_BRAINPOOL, CRYPTO_ALGOFAM_SHA2_256, 32u, 135u} /*  Mode = CRYPTO_ALGOMODE_CUSTOM_ECCBRAINPOOL_P256R1  */ }    ,  /* [/ActiveEcuC/Csm/Crypto_SigVer_ECCBrainpool_256R1_SHA256/CsmSignatureVerify/Crypto_SigVer_ECCBrainpool_256R1_SHA256] */
  /*    21 */ {CRYPTO_RANDOMGENERATE, {CRYPTO_ALGOFAM_RNG, CRYPTO_ALGOFAM_NOT_SET, 0u, CRYPTO_ALGOMODE_CTRDRBG}}                                                     ,  /* [/ActiveEcuC/Csm/Crypto_RNG_DRBG/CsmRandomGenerate/Crypto_RNG_DRBG] */
  /*    22 */ {CRYPTO_MACGENERATE, {CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_NOT_SET, 32u, CRYPTO_ALGOMODE_CMAC}}                                                          ,  /* [/ActiveEcuC/Csm/Crypto_MAC_CMAC_Generate_256/CsmMacGenerate/Crypto_MAC_CMAC_Generate_256] */
  /*    23 */ {CRYPTO_MACVERIFY, {CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_NOT_SET, 32u, CRYPTO_ALGOMODE_CMAC}}                                                            ,  /* [/ActiveEcuC/Csm/Crypto_MAC_CMAC_Verify_256/CsmMacVerify/Crypto_MAC_CMAC_Verify_256] */
  /*    24 */ {CRYPTO_SIGNATUREGENERATE, {CRYPTO_ALGOFAM_ED25519, CRYPTO_ALGOFAM_NOT_SET, 32u, 147u} /*  Mode = CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519  */ }           ,  /* [/ActiveEcuC/Csm/Crypto_SigGen_Ed25519_256/CsmSignatureGenerate/Crypto_SigGen_Ed25519_256] */
  /*    25 */ {CRYPTO_SIGNATUREVERIFY, {CRYPTO_ALGOFAM_ED25519, CRYPTO_ALGOFAM_NOT_SET, 32u, 147u} /*  Mode = CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED25519  */ }             ,  /* [/ActiveEcuC/Csm/Crypto_SigVer_Ed25519_256/CsmSignatureVerify/Crypto_SigVer_Ed25519_256] */
  /*    26 */ {CRYPTO_DECRYPT, {CRYPTO_ALGOFAM_RSA, CRYPTO_ALGOFAM_SHA2_256, 512u, CRYPTO_ALGOMODE_RSAES_OAEP}}                                                      ,  /* [/ActiveEcuC/Csm/Crypto_Decrypt_RSA_4096_OAEP_SHA2_256/CsmDecrypt/Crypto_Decrypt_RSA_4096_OAEP_SHA2_256] */
  /*    27 */ {CRYPTO_SIGNATUREGENERATE, {CRYPTO_ALGOFAM_RSA, CRYPTO_ALGOFAM_SHA2_256, 128u, CRYPTO_ALGOMODE_RSASSA_PSS}}                                            ,  /* [/ActiveEcuC/Csm/Crypto_SigGen_RSAPSS_1024/CsmSignatureGenerate/Crypto_SigGen_RSAPSS_1024] */
  /*    28 */ {CRYPTO_SIGNATUREVERIFY, {CRYPTO_ALGOFAM_RSA, CRYPTO_ALGOFAM_SHA2_256, 128u, CRYPTO_ALGOMODE_RSASSA_PSS}}                                              ,  /* [/ActiveEcuC/Csm/Crypto_SigVer_RSAPSS_1024/CsmSignatureVerify/Crypto_SigVer_RSAPSS_1024] */
  /*    29 */ {CRYPTO_SIGNATUREGENERATE, {CRYPTO_ALGOFAM_BRAINPOOL, CRYPTO_ALGOFAM_SHA2_256, 32u, 135u} /*  Mode = CRYPTO_ALGOMODE_CUSTOM_ECCBRAINPOOL_P256R1  */ }  ,  /* [/ActiveEcuC/Csm/Crypto_SigGen_ECCBrainpool_256R1_SHA256/CsmSignatureGenerate/Crypto_SigGen_ECCBrainpool_256R1_SHA256] */
  /*    30 */ {CRYPTO_SIGNATUREGENERATE, {CRYPTO_ALGOFAM_BRAINPOOL, CRYPTO_ALGOFAM_SHA2_256, 32u, 141u} /*  Mode = CRYPTO_ALGOMODE_CUSTOM_ECCBRAINPOOL_P256T1  */ }  ,  /* [/ActiveEcuC/Csm/Crypto_SigGen_ECCBrainpool_256T1_SHA256/CsmSignatureGenerate/Crypto_SigGen_ECCBrainpool_256T1_SHA256] */
  /*    31 */ {CRYPTO_SIGNATUREGENERATE, {129u, CRYPTO_ALGOFAM_NOT_SET, 57u, 146u} /*  Family = CRYPTO_ALGOFAM_ED448 Mode = CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED448  */ } ,  /* [/ActiveEcuC/Csm/Crypto_SigGen_ED448/CsmSignatureGenerate/Crypto_SigGen_ED448] */
  /*    32 */ {CRYPTO_SIGNATUREVERIFY, {129u, CRYPTO_ALGOFAM_NOT_SET, 114u, 146u} /*  Family = CRYPTO_ALGOFAM_ED448 Mode = CRYPTO_ALGOMODE_CUSTOM_EDDSA_ED448  */ }  ,  /* [/ActiveEcuC/Csm/Crypto_SigVer_ED448/CsmSignatureVerify/Crypto_SigVer_ED448] */
  /*    33 */ {CRYPTO_MACVERIFY, {CRYPTO_ALGOFAM_SHA2_512, CRYPTO_ALGOFAM_NOT_SET, 64u, CRYPTO_ALGOMODE_HMAC}}                                                       ,  /* [/ActiveEcuC/Csm/Crypto_MAC_HMAC_Verify_SHA2_512/CsmMacVerify/Crypto_MAC_HMAC_Verify_SHA2_512] */
  /*    34 */ {CRYPTO_SIGNATUREVERIFY, {CRYPTO_ALGOFAM_BRAINPOOL, CRYPTO_ALGOFAM_SHA2_256, 32u, 141u} /*  Mode = CRYPTO_ALGOMODE_CUSTOM_ECCBRAINPOOL_P256T1  */ }    ,  /* [/ActiveEcuC/Csm/Crypto_SigVer_ECCBrainpool_256T1_SHA256/CsmSignatureVerify/Crypto_SigVer_ECCBrainpool_256T1_SHA256] */
  /*    35 */ {CRYPTO_DECRYPT, {CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_NOT_SET, 16u, CRYPTO_ALGOMODE_CBC}}                                                               ,  /* [/ActiveEcuC/Csm/Crypto_Decrypt_AES_CBC_SHE/CsmDecrypt/Crypto_Decrypt_AES_CBC_SHE] */
  /*    36 */ {CRYPTO_ENCRYPT, {CRYPTO_ALGOFAM_AES, CRYPTO_ALGOFAM_NOT_SET, 16u, CRYPTO_ALGOMODE_CBC}}                                                                  /* [/ActiveEcuC/Csm/Crypto_Encrypt_AES_CBC_SHE/CsmEncrypt/Crypto_Encrypt_AES_CBC_SHE] */
};
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
CONST(Csm_QueueInfoType, CSM_CONST) Csm_QueueInfo[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ChannelId                                                    JobSharing  JobObjSynchronousIdx  JobPoolPartitionIdx                              ProcessingMode           QueueEndIdx        Referable Keys */
  { /*     0 */ CryIfConf_CryIfChannel_CryIfChannel_Crypto_AESDriverObject ,       TRUE,                   1u,                  0u  /* CSM_SINGLE_PARTITION */, CRYPTO_PROCESSING_SYNC ,          2u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_AES, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CFB_128:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CFB_128:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CTR_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Generate_128:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Verify_128:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_AEAD_GCM_Encrypt:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_AEAD_GCM_Decrypt:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CBC_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_ECB_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CTR_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_ECB_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Generate_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Verify_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Generate_SHE:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Verify_SHE:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_SHE:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_ECB_SHE:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CBC_SHE:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_ECB_SHE:CsmJobQueueRef] */
  { /*     1 */ CryIfConf_CryIfChannel_CryIfChannel_Crypto_AESDriverObject ,       TRUE,                   8u,                  0u  /* CSM_SINGLE_PARTITION */, CRYPTO_PROCESSING_ASYNC,         12u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_AES_Async, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256_ASYNC_1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256_ASYNC_2:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256_ASYNC_3:CsmJobQueueRef] */
  { /*     2 */ CryIfConf_CryIfChannel_CryIfChannel_Crypto_HashDriverObject,       TRUE,                   0u,                  0u  /* CSM_SINGLE_PARTITION */, CRYPTO_PROCESSING_SYNC ,          1u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Hash, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/Crypto_Hash_SHA2_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_RNG:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_MAC_HMAC_SHA2_512:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_RNG_DRBG:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_MAC_HMAC_Verify_SHA2_512:CsmJobQueueRef] */
  { /*     3 */ CryIfConf_CryIfChannel_CryIfChannel_Crypto_HashDriverObject,       TRUE,                   4u,                  0u  /* CSM_SINGLE_PARTITION */, CRYPTO_PROCESSING_ASYNC,          7u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Hash_Async, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/Crypto_Hash_SHA2_256_ASYNC_1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Hash_SHA2_256_ASYNC_2:CsmJobQueueRef] */
  { /*     4 */ CryIfConf_CryIfChannel_CryIfChannel_MKA                    ,       TRUE,                   2u,                  0u  /* CSM_SINGLE_PARTITION */, CRYPTO_PROCESSING_SYNC ,          3u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_MKA, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/MKA_Encrypt_ECB:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/MKA_Random:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/MKA_Hash_Key_Derivation:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/MKA_KeyDerivationPRF:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/MKA_CMACGenerate:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/MKA_CMACVerify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/MKA_Decrypt_ECB:CsmJobQueueRef] */
  { /*     5 */ CryIfConf_CryIfChannel_CryIfChannel_Crypto_PublicKeyObject ,       TRUE,                   3u,                  0u  /* CSM_SINGLE_PARTITION */, CRYPTO_PROCESSING_SYNC ,          4u },  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_PublicKey, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ECCNIST_256_SHA256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_RSA_4096_OAEP_SHA2_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_RSA_4096_OAEP_SHA2_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ECCNIST_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ECCBrainpool_256T1_SHA256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_Ed25519_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_Ed25519_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_RSAPSS_1024:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_RSAPSS_1024:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ECCBrainpool_256R1_SHA256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ECCBrainpool_256T1_SHA256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ED448:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ED448:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ECCBrainpool_256R1_SHA256:CsmJobQueueRef] */
  { /*     6 */ CryIfConf_CryIfChannel_CryIfChannel_Crypto_PublicKeyObject ,       TRUE,                   7u,                  0u  /* CSM_SINGLE_PARTITION */, CRYPTO_PROCESSING_SYNC ,          8u }   /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_PublicKey_Async, /ActiveEcuC/Csm/CsmQueues] */
};
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
VAR(Crypto_JobType, CSM_VAR_NOINIT) Csm_Job[12];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [CsmQueue_Hash_AsyncPool, CsmQueue_Hash_SyncObj] */
  /*     1 */  /* [CsmQueue_AES_AsyncPool, CsmQueue_AES_SyncObj] */
  /*     2 */  /* [CsmQueue_MKA_AsyncPool, CsmQueue_MKA_SyncObj] */
  /*     3 */  /* [CsmQueue_PublicKey_AsyncPool, CsmQueue_PublicKey_SyncObj] */
  /*     4 */  /* [CsmQueue_Hash_Async_AsyncPool, CsmQueue_Hash_Async_SyncObj] */
  /*     5 */  /* [CsmQueue_Hash_Async_AsyncPool] */
  /*     6 */  /* [CsmQueue_Hash_Async_AsyncPool] */
  /*     7 */  /* [CsmQueue_PublicKey_Async_AsyncPool, CsmQueue_PublicKey_Async_SyncObj] */
  /*     8 */  /* [CsmQueue_AES_Async_AsyncPool, CsmQueue_AES_Async_SyncObj] */
  /*     9 */  /* [CsmQueue_AES_Async_AsyncPool] */
  /*   ... */  /* [CsmQueue_AES_Async_AsyncPool] */
  /*    11 */  /* [CsmQueue_AES_Async_AsyncPool] */

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
VAR(Csm_JobStateType, CSM_VAR_NOINIT) Csm_JobState[51];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_AEAD_GCM_Decrypt, /ActiveEcuC/Csm/CsmJobs] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_AEAD_GCM_Encrypt, /ActiveEcuC/Csm/CsmJobs] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256, /ActiveEcuC/Csm/CsmJobs] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256_ASYNC_1, /ActiveEcuC/Csm/CsmJobs] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256_ASYNC_2, /ActiveEcuC/Csm/CsmJobs] */
  /*     5 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256_ASYNC_3, /ActiveEcuC/Csm/CsmJobs] */
  /*     6 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_SHE, /ActiveEcuC/Csm/CsmJobs] */
  /*     7 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CFB_128, /ActiveEcuC/Csm/CsmJobs] */
  /*     8 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CTR_256, /ActiveEcuC/Csm/CsmJobs] */
  /*     9 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_ECB_256, /ActiveEcuC/Csm/CsmJobs] */
  /*    10 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_ECB_SHE, /ActiveEcuC/Csm/CsmJobs] */
  /*    11 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_RSA_4096_OAEP_SHA2_256, /ActiveEcuC/Csm/CsmJobs] */
  /*    12 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CBC_256, /ActiveEcuC/Csm/CsmJobs] */
  /*    13 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CBC_SHE, /ActiveEcuC/Csm/CsmJobs] */
  /*    14 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CFB_128, /ActiveEcuC/Csm/CsmJobs] */
  /*    15 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CTR_256, /ActiveEcuC/Csm/CsmJobs] */
  /*    16 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_ECB_256, /ActiveEcuC/Csm/CsmJobs] */
  /*    17 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_ECB_SHE, /ActiveEcuC/Csm/CsmJobs] */
  /*    18 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_RSA_4096_OAEP_SHA2_256, /ActiveEcuC/Csm/CsmJobs] */
  /*    19 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Hash_SHA2_256, /ActiveEcuC/Csm/CsmJobs] */
  /*    20 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Hash_SHA2_256_ASYNC_1, /ActiveEcuC/Csm/CsmJobs] */
  /*    21 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Hash_SHA2_256_ASYNC_2, /ActiveEcuC/Csm/CsmJobs] */
  /*    22 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Generate_128, /ActiveEcuC/Csm/CsmJobs] */
  /*    23 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Generate_256, /ActiveEcuC/Csm/CsmJobs] */
  /*    24 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Generate_SHE, /ActiveEcuC/Csm/CsmJobs] */
  /*    25 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Verify_128, /ActiveEcuC/Csm/CsmJobs] */
  /*    26 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Verify_256, /ActiveEcuC/Csm/CsmJobs] */
  /*    27 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Verify_SHE, /ActiveEcuC/Csm/CsmJobs] */
  /*    28 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_HMAC_SHA2_512, /ActiveEcuC/Csm/CsmJobs] */
  /*    29 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_HMAC_Verify_SHA2_512, /ActiveEcuC/Csm/CsmJobs] */
  /*    30 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_RNG, /ActiveEcuC/Csm/CsmJobs] */
  /*    31 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_RNG_DRBG, /ActiveEcuC/Csm/CsmJobs] */
  /*    32 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ECCBrainpool_256R1_SHA256, /ActiveEcuC/Csm/CsmJobs] */
  /*    33 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ECCBrainpool_256T1_SHA256, /ActiveEcuC/Csm/CsmJobs] */
  /*    34 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ECCNIST_256_SHA256, /ActiveEcuC/Csm/CsmJobs] */
  /*    35 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ED448, /ActiveEcuC/Csm/CsmJobs] */
  /*    36 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_Ed25519_256, /ActiveEcuC/Csm/CsmJobs] */
  /*    37 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_RSAPSS_1024, /ActiveEcuC/Csm/CsmJobs] */
  /*    38 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ECCBrainpool_256R1_SHA256, /ActiveEcuC/Csm/CsmJobs] */
  /*    39 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ECCBrainpool_256T1_SHA256, /ActiveEcuC/Csm/CsmJobs] */
  /*    40 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ECCNIST_256, /ActiveEcuC/Csm/CsmJobs] */
  /*    41 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ED448, /ActiveEcuC/Csm/CsmJobs] */
  /*    42 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_Ed25519_256, /ActiveEcuC/Csm/CsmJobs] */
  /*    43 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_RSAPSS_1024, /ActiveEcuC/Csm/CsmJobs] */
  /*    44 */  /* [/ActiveEcuC/Csm/CsmJobs/MKA_CMACGenerate, /ActiveEcuC/Csm/CsmJobs] */
  /*    45 */  /* [/ActiveEcuC/Csm/CsmJobs/MKA_CMACVerify, /ActiveEcuC/Csm/CsmJobs] */
  /*    46 */  /* [/ActiveEcuC/Csm/CsmJobs/MKA_Decrypt_ECB, /ActiveEcuC/Csm/CsmJobs] */
  /*    47 */  /* [/ActiveEcuC/Csm/CsmJobs/MKA_Encrypt_ECB, /ActiveEcuC/Csm/CsmJobs] */
  /*    48 */  /* [/ActiveEcuC/Csm/CsmJobs/MKA_Hash_Key_Derivation, /ActiveEcuC/Csm/CsmJobs] */
  /*    49 */  /* [/ActiveEcuC/Csm/CsmJobs/MKA_KeyDerivationPRF, /ActiveEcuC/Csm/CsmJobs] */
  /* Index        Referable Keys */
  /*    50 */  /* [/ActiveEcuC/Csm/CsmJobs/MKA_Random, /ActiveEcuC/Csm/CsmJobs] */

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
VAR(Csm_SizeOfJobType, CSM_VAR_NOINIT) Csm_JobToObjMap[51];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_AEAD_GCM_Decrypt, /ActiveEcuC/Csm/CsmJobs] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_AEAD_GCM_Encrypt, /ActiveEcuC/Csm/CsmJobs] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256, /ActiveEcuC/Csm/CsmJobs] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256_ASYNC_1, /ActiveEcuC/Csm/CsmJobs] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256_ASYNC_2, /ActiveEcuC/Csm/CsmJobs] */
  /*     5 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256_ASYNC_3, /ActiveEcuC/Csm/CsmJobs] */
  /*     6 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_SHE, /ActiveEcuC/Csm/CsmJobs] */
  /*     7 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CFB_128, /ActiveEcuC/Csm/CsmJobs] */
  /*     8 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CTR_256, /ActiveEcuC/Csm/CsmJobs] */
  /*     9 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_ECB_256, /ActiveEcuC/Csm/CsmJobs] */
  /*    10 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_ECB_SHE, /ActiveEcuC/Csm/CsmJobs] */
  /*    11 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_RSA_4096_OAEP_SHA2_256, /ActiveEcuC/Csm/CsmJobs] */
  /*    12 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CBC_256, /ActiveEcuC/Csm/CsmJobs] */
  /*    13 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CBC_SHE, /ActiveEcuC/Csm/CsmJobs] */
  /*    14 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CFB_128, /ActiveEcuC/Csm/CsmJobs] */
  /*    15 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CTR_256, /ActiveEcuC/Csm/CsmJobs] */
  /*    16 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_ECB_256, /ActiveEcuC/Csm/CsmJobs] */
  /*    17 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_ECB_SHE, /ActiveEcuC/Csm/CsmJobs] */
  /*    18 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_RSA_4096_OAEP_SHA2_256, /ActiveEcuC/Csm/CsmJobs] */
  /*    19 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Hash_SHA2_256, /ActiveEcuC/Csm/CsmJobs] */
  /*    20 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Hash_SHA2_256_ASYNC_1, /ActiveEcuC/Csm/CsmJobs] */
  /*    21 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_Hash_SHA2_256_ASYNC_2, /ActiveEcuC/Csm/CsmJobs] */
  /*    22 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Generate_128, /ActiveEcuC/Csm/CsmJobs] */
  /*    23 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Generate_256, /ActiveEcuC/Csm/CsmJobs] */
  /*    24 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Generate_SHE, /ActiveEcuC/Csm/CsmJobs] */
  /*    25 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Verify_128, /ActiveEcuC/Csm/CsmJobs] */
  /*    26 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Verify_256, /ActiveEcuC/Csm/CsmJobs] */
  /*    27 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Verify_SHE, /ActiveEcuC/Csm/CsmJobs] */
  /*    28 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_HMAC_SHA2_512, /ActiveEcuC/Csm/CsmJobs] */
  /*    29 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_MAC_HMAC_Verify_SHA2_512, /ActiveEcuC/Csm/CsmJobs] */
  /*    30 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_RNG, /ActiveEcuC/Csm/CsmJobs] */
  /*    31 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_RNG_DRBG, /ActiveEcuC/Csm/CsmJobs] */
  /*    32 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ECCBrainpool_256R1_SHA256, /ActiveEcuC/Csm/CsmJobs] */
  /*    33 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ECCBrainpool_256T1_SHA256, /ActiveEcuC/Csm/CsmJobs] */
  /*    34 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ECCNIST_256_SHA256, /ActiveEcuC/Csm/CsmJobs] */
  /*    35 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ED448, /ActiveEcuC/Csm/CsmJobs] */
  /*    36 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_Ed25519_256, /ActiveEcuC/Csm/CsmJobs] */
  /*    37 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_RSAPSS_1024, /ActiveEcuC/Csm/CsmJobs] */
  /*    38 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ECCBrainpool_256R1_SHA256, /ActiveEcuC/Csm/CsmJobs] */
  /*    39 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ECCBrainpool_256T1_SHA256, /ActiveEcuC/Csm/CsmJobs] */
  /*    40 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ECCNIST_256, /ActiveEcuC/Csm/CsmJobs] */
  /*    41 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ED448, /ActiveEcuC/Csm/CsmJobs] */
  /*    42 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_Ed25519_256, /ActiveEcuC/Csm/CsmJobs] */
  /*    43 */  /* [/ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_RSAPSS_1024, /ActiveEcuC/Csm/CsmJobs] */
  /*    44 */  /* [/ActiveEcuC/Csm/CsmJobs/MKA_CMACGenerate, /ActiveEcuC/Csm/CsmJobs] */
  /*    45 */  /* [/ActiveEcuC/Csm/CsmJobs/MKA_CMACVerify, /ActiveEcuC/Csm/CsmJobs] */
  /*    46 */  /* [/ActiveEcuC/Csm/CsmJobs/MKA_Decrypt_ECB, /ActiveEcuC/Csm/CsmJobs] */
  /*    47 */  /* [/ActiveEcuC/Csm/CsmJobs/MKA_Encrypt_ECB, /ActiveEcuC/Csm/CsmJobs] */
  /*    48 */  /* [/ActiveEcuC/Csm/CsmJobs/MKA_Hash_Key_Derivation, /ActiveEcuC/Csm/CsmJobs] */
  /*    49 */  /* [/ActiveEcuC/Csm/CsmJobs/MKA_KeyDerivationPRF, /ActiveEcuC/Csm/CsmJobs] */
  /* Index        Referable Keys */
  /*    50 */  /* [/ActiveEcuC/Csm/CsmJobs/MKA_Random, /ActiveEcuC/Csm/CsmJobs] */

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
VAR(Csm_PartitionDataInitializedType, CSM_VAR_ZERO_INIT) Csm_PartitionDataInitialized = 0u;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(Csm_QueueUType, CSM_VAR_NOINIT) Csm_Queue;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Hash] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_AES] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_MKA] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_PublicKey] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Hash_Async] */
  /*   ... */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Hash_Async] */
  /*     6 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Hash_Async] */
  /*     7 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_PublicKey_Async] */
  /*     8 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_AES_Async] */
  /*   ... */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_AES_Async] */
  /*    11 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_AES_Async] */

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
VAR(Csm_QueueStateType, CSM_VAR_NOINIT) Csm_QueueState[7];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_AES, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CFB_128:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CFB_128:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CTR_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Generate_128:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Verify_128:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_AEAD_GCM_Encrypt:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_AEAD_GCM_Decrypt:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CBC_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_ECB_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CTR_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_ECB_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Generate_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Verify_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Generate_SHE:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_MAC_CMAC_Verify_SHE:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_SHE:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_ECB_SHE:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_CBC_SHE:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_AES_ECB_SHE:CsmJobQueueRef] */
  /*     1 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_AES_Async, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256_ASYNC_1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256_ASYNC_2:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_AES_CBC_256_ASYNC_3:CsmJobQueueRef] */
  /*     2 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Hash, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/Crypto_Hash_SHA2_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_RNG:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_MAC_HMAC_SHA2_512:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_RNG_DRBG:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_MAC_HMAC_Verify_SHA2_512:CsmJobQueueRef] */
  /*     3 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_Hash_Async, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/Crypto_Hash_SHA2_256_ASYNC_1:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Hash_SHA2_256_ASYNC_2:CsmJobQueueRef] */
  /*     4 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_MKA, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/MKA_Encrypt_ECB:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/MKA_Random:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/MKA_Hash_Key_Derivation:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/MKA_KeyDerivationPRF:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/MKA_CMACGenerate:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/MKA_CMACVerify:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/MKA_Decrypt_ECB:CsmJobQueueRef] */
  /*     5 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_PublicKey, /ActiveEcuC/Csm/CsmQueues, /ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ECCNIST_256_SHA256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Decrypt_RSA_4096_OAEP_SHA2_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_Encrypt_RSA_4096_OAEP_SHA2_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ECCNIST_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ECCBrainpool_256T1_SHA256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_Ed25519_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_Ed25519_256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_RSAPSS_1024:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_RSAPSS_1024:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ECCBrainpool_256R1_SHA256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ECCBrainpool_256T1_SHA256:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigGen_ED448:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ED448:CsmJobQueueRef, /ActiveEcuC/Csm/CsmJobs/Crypto_SigVer_ECCBrainpool_256R1_SHA256:CsmJobQueueRef] */
  /*     6 */  /* [/ActiveEcuC/Csm/CsmQueues/CsmQueue_PublicKey_Async, /ActiveEcuC/Csm/CsmQueues] */

#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */





/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/



 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
#define CSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  Csm_InitMemory
 **********************************************************************************************************************/
FUNC(void, CSM_CODE) Csm_InitMemory(void)
{
  Csm_InitMemory_Local(Csm_PartitionIndexOfCSLForCSM_SINGLE_PARTITION); /*lint !e522 */
}

/***********************************************************************************************************************
 *  Csm_MainFunction
 **********************************************************************************************************************/
FUNC(void, CSM_CODE) Csm_MainFunction(void)
{
  Csm_MainFunction_Local(Csm_PartitionIndexOfCSLForCSM_SINGLE_PARTITION); /*lint !e522 */
}

#define CSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define CSM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
/***********************************************************************************************************************
 *  Function Group 
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Function Group MainFunctionGroup
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Function Group InitMemoryGroup
 **********************************************************************************************************************/

#define CSM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
 *  END OF FILE: Csm_Cfg.c
 *********************************************************************************************************************/
