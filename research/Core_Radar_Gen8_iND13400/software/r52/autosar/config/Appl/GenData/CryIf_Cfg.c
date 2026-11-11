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
 *              File: CryIf_Cfg.c
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
#define CRYIF_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "CryIf_Cfg.h"
#include "CryIf.h"
#include "CryIf_Private.h"
#include "Crypto_182_iND13400.h"



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (STATIC)
# define STATIC static
#endif

#if !defined (CRYIF_LOCAL)
# define CRYIF_LOCAL static
#endif

#if !defined (CRYIF_LOCAL_INLINE)
# define CRYIF_LOCAL_INLINE LOCAL_INLINE
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
CONST(CryIf_ChannelType, CRYIF_CONST) CryIf_Channel[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DriverObjectRef                                                           CryptoFunctionsIdx  Id        Referable Keys */
  { /*     0 */ CryptoConf_CryptoDriverObject_Crypto_182_iND13400_AsymmetricDriverObject,                 0u, 0u },  /* [/ActiveEcuC/CryIf/CryIfChannel_Crypto_PublicKeyObject, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_PublicKey:CsmChannelRef, /ActiveEcuC/Csm/CsmQueues/CsmQueue_PublicKey_Async:CsmChannelRef] */
  { /*     1 */ CryptoConf_CryptoDriverObject_Crypto_182_iND13400_SymmetricDriverObject ,                 0u, 1u },  /* [/ActiveEcuC/CryIf/CryIfChannel_Crypto_AESDriverObject, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_AES:CsmChannelRef, /ActiveEcuC/Csm/CsmQueues/CsmQueue_AES_Async:CsmChannelRef] */
  { /*     2 */ CryptoConf_CryptoDriverObject_Crypto_182_iND13400_AsymmetricDriverObject,                 0u, 2u },  /* [/ActiveEcuC/CryIf/CryIfChannel_Crypto_HashDriverObject, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_Hash:CsmChannelRef, /ActiveEcuC/Csm/CsmQueues/CsmQueue_Hash_Async:CsmChannelRef] */
  { /*     3 */ CryptoConf_CryptoDriverObject_Crypto_182_iND13400_SymmetricDriverObject ,                 0u, 3u }   /* [/ActiveEcuC/CryIf/CryIfChannel_MKA, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmQueues/CsmQueue_MKA:CsmChannelRef] */
};
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
CONST(CryIf_CryptoFunctionsType, CRYIF_CONST) CryIf_CryptoFunctions[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    SupportsKeyElementCopyPartial  CancelJob                      CertificateParse             CertificateVerify             CustomSync             KeyCopy                      KeyDerive                      KeyElementCopy                      KeyElementCopyPartial                      KeyElementGet                      KeyElementIdsGet                      KeyElementSet                      KeyExchangeCalcPubVal                      KeyExchangeCalcSecret                      KeyGenerate                      KeyGetStatus                      KeySetInvalid                      KeyValidSet                      ProcessJob                      RandomSeed                            Referable Keys */
  { /*     0 */                          TRUE, Crypto_182_iND13400_CancelJob, CryIf_CertificateParse_Stub, CryIf_CertificateVerify_Stub, CryIf_CustomSync_Stub, Crypto_182_iND13400_KeyCopy, Crypto_182_iND13400_KeyDerive, Crypto_182_iND13400_KeyElementCopy, Crypto_182_iND13400_KeyElementCopyPartial, Crypto_182_iND13400_KeyElementGet, Crypto_182_iND13400_KeyElementIdsGet, Crypto_182_iND13400_KeyElementSet, Crypto_182_iND13400_KeyExchangeCalcPubVal, Crypto_182_iND13400_KeyExchangeCalcSecret, Crypto_182_iND13400_KeyGenerate, Crypto_182_iND13400_KeyGetStatus, Crypto_182_iND13400_KeySetInvalid, Crypto_182_iND13400_KeySetValid, Crypto_182_iND13400_ProcessJob, Crypto_182_iND13400_RandomSeed }   /* [/ActiveEcuC/Crypto] */
};
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
CONST(CryIf_KeyType, CRYIF_CONST) CryIf_Key[62] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Ref                                            CryptoFunctionsIdx        Referable Keys */
  { /*     0 */ CryptoConf_CryptoKey_Boot_MAC                ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Boot_MAC, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Boot_MAC:CsmKeyRef] */
  { /*     1 */ CryptoConf_CryptoKey_Boot_MAC_Key            ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Boot_MAC_Key, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Boot_MAC_Key:CsmKeyRef] */
  { /*     2 */ CryptoConf_CryptoKey_AES_128_Key             ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Crypto_AES_128, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Crypto_AES_128:CsmKeyRef] */
  { /*     3 */ CryptoConf_CryptoKey_AES_256_Key             ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Crypto_AES_256, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Crypto_AES_256:CsmKeyRef] */
  { /*     4 */ CryptoConf_CryptoKey_Hash_Key                ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Crypto_Hash, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Crypto_Hash:CsmKeyRef] */
  { /*     5 */ CryptoConf_CryptoKey_RNG_Key                 ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Crypto_RNG, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Crypto_RNG:CsmKeyRef] */
  { /*     6 */ CryptoConf_CryptoKey_RSA_1024_Key            ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Crypto_RSA_1024_Key, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Crypto_RSA_1024:CsmKeyRef] */
  { /*     7 */ CryptoConf_CryptoKey_RSA_2048_Key            ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Crypto_RSA_2048_Key, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Crypto_RSA_2048:CsmKeyRef] */
  { /*     8 */ CryptoConf_CryptoKey_RSA_3072_Key            ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Crypto_RSA_3072_Key, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Crypto_RSA_3072:CsmKeyRef] */
  { /*     9 */ CryptoConf_CryptoKey_RSA_4096_Key            ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Crypto_RSA_4096_Key, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Crypto_RSA_4096:CsmKeyRef] */
  { /*    10 */ CryptoConf_CryptoKey_Custom_Operations       ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Custom_Operations, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Custom_Operations:CsmKeyRef] */
  { /*    11 */ CryptoConf_CryptoKey_ECC_192_Key_SigGenerate ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECC_192_Key_SigGenerate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_192_Key_SigGenerate:CsmKeyRef] */
  { /*    12 */ CryptoConf_CryptoKey_ECC_192_Key_SigVerify   ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECC_192_Key_SigVerify, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_192_Key_SigVerify:CsmKeyRef] */
  { /*    13 */ CryptoConf_CryptoKey_ECC_224_Key_SigGenerate ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECC_224_Key_SigGenerate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_224_Key_SigGenerate:CsmKeyRef] */
  { /*    14 */ CryptoConf_CryptoKey_ECC_224_Key_SigVerify   ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECC_224_Key_SigVerify, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_224_Key_SigVerify:CsmKeyRef] */
  { /*    15 */ CryptoConf_CryptoKey_ECC_224_Key_Exchange    ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECC_224_Key_Exchange, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_224_Key_Exchange:CsmKeyRef] */
  { /*    16 */ CryptoConf_CryptoKey_ECC_256_Key_Generate    ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECC_256_Key_Generate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_256_Key_Generate:CsmKeyRef] */
  { /*    17 */ CryptoConf_CryptoKey_ECC_256_Key_Generate    ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECC_256_Key_Generate_2, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_256_Key_Generate_2:CsmKeyRef] */
  { /*    18 */ CryptoConf_CryptoKey_ECC_256_Key_SigGenerate ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECC_256_Key_SigGenerate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_256_Key_SigGenerate:CsmKeyRef] */
  { /*    19 */ CryptoConf_CryptoKey_ECC_256_Key_SigVerify   ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECC_256_Key_SigVerify, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_256_Key_SigVerify:CsmKeyRef] */
  { /*    20 */ CryptoConf_CryptoKey_ECC_320_Key_SigGenerate ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECC_320_Key_SigGenerate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_320_Key_SigGenerate:CsmKeyRef] */
  { /*    21 */ CryptoConf_CryptoKey_ECC_320_Key_SigVerify   ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECC_320_Key_SigVerify, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_320_Key_SigVerify:CsmKeyRef] */
  { /*    22 */ CryptoConf_CryptoKey_ECC_384_Key_SigGenerate ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECC_384_Key_SigGenerate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_384_Key_SigGenerate:CsmKeyRef] */
  { /*    23 */ CryptoConf_CryptoKey_ECC_384_Key_SigVerify   ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECC_384_Key_SigVerify, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_384_Key_SigVerify:CsmKeyRef] */
  { /*    24 */ CryptoConf_CryptoKey_ECC_512_Key_SigGenerate ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECC_512_Key_SigGenerate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_512_Key_SigGenerate:CsmKeyRef] */
  { /*    25 */ CryptoConf_CryptoKey_ECC_512_Key_SigVerify   ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECC_512_Key_SigVerify, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_512_Key_SigVerify:CsmKeyRef] */
  { /*    26 */ CryptoConf_CryptoKey_ECC_521_Key_SigGenerate ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECC_521_Key_SigGenerate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_521_Key_SigGenerate:CsmKeyRef] */
  { /*    27 */ CryptoConf_CryptoKey_ECC_521_Key_SigVerify   ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECC_521_Key_SigVerify, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECC_521_Key_SigVerify:CsmKeyRef] */
  { /*    28 */ CryptoConf_CryptoKey_ECDH_128_Key_SigGenerate,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECDH_128_Key_SigGenerate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECDH_128_Key_SigGenerate:CsmKeyRef] */
  { /*    29 */ CryptoConf_CryptoKey_ECDH_128_Key_SigVerify  ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECDH_128_Key_SigVerify, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECDH_128_Key_SigVerify:CsmKeyRef] */
  { /*    30 */ CryptoConf_CryptoKey_ECDH_224_Key_SigGenerate,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECDH_224_Key_SigGenerate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECDH_224_Key_SigGenerate:CsmKeyRef] */
  { /*    31 */ CryptoConf_CryptoKey_ECDH_224_Key_SigVerify  ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECDH_224_Key_SigVerify, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECDH_224_Key_SigVerify:CsmKeyRef] */
  { /*    32 */ CryptoConf_CryptoKey_ECDH_256_Key_SigGenerate,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECDH_256_Key_SigGenerate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECDH_256_Key_SigGenerate:CsmKeyRef] */
  { /*    33 */ CryptoConf_CryptoKey_ECDH_256_Key_SigVerify  ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECDH_256_Key_SigVerify, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECDH_256_Key_SigVerify:CsmKeyRef] */
  { /*    34 */ CryptoConf_CryptoKey_ECDH_384_Key_SigGenerate,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECDH_384_Key_SigGenerate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECDH_384_Key_SigGenerate:CsmKeyRef] */
  { /*    35 */ CryptoConf_CryptoKey_ECDH_384_Key_SigVerify  ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECDH_384_Key_SigVerify, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECDH_384_Key_SigVerify:CsmKeyRef] */
  { /*    36 */ CryptoConf_CryptoKey_ECDH_512_Key_SigGenerate,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECDH_512_Key_SigGenerate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECDH_512_Key_SigGenerate:CsmKeyRef] */
  { /*    37 */ CryptoConf_CryptoKey_ECDH_512_Key_SigVerify  ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ECDH_512_Key_SigVerify, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ECDH_512_Key_SigVerify:CsmKeyRef] */
  { /*    38 */ CryptoConf_CryptoKey_ED448_Key_SigGenerate   ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ED448_Key_SigGenerate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ED448_Key_SigGenerate:CsmKeyRef] */
  { /*    39 */ CryptoConf_CryptoKey_ED448_Key_SigVerify     ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ED448_Key_SigVerify, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ED448_Key_SigVerify:CsmKeyRef] */
  { /*    40 */ CryptoConf_CryptoKey_ED25519_Key_SigGenerate ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ED25519_Key_SigGenerate, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ED25519_Key_SigGenerate:CsmKeyRef] */
  { /*    41 */ CryptoConf_CryptoKey_ED25519_Key_SigVerify   ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_ED25519_Key_SigVerify, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_ED25519_Key_SigVerify:CsmKeyRef] */
  { /*    42 */ CryptoConf_CryptoKey_MKA_CAK_Key             ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_MKA_CAK, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_MKA_CAK:CsmKeyRef] */
  { /*    43 */ CryptoConf_CryptoKey_MKA_ICK_Key             ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_MKA_ICK, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_MKA_ICK:CsmKeyRef] */
  { /*    44 */ CryptoConf_CryptoKey_MKA_KEK_Key             ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_MKA_KEK, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_MKA_KEK:CsmKeyRef] */
  { /*    45 */ CryptoConf_CryptoKey_MKA_MAC_Key             ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_MKA_MAC, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_MKA_MAC:CsmKeyRef] */
  { /*    46 */ CryptoConf_CryptoKey_MKA_Random_Key          ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_MKA_Random, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_MKA_Random:CsmKeyRef] */
  { /*    47 */ CryptoConf_CryptoKey_MKA_SAK_Key             ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_MKA_SAK, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_MKA_SAK:CsmKeyRef] */
  { /*    48 */ CryptoConf_CryptoKey_MKA_SAK_Data_Key        ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_MKA_SAK_Data, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_MKA_SAK_Data:CsmKeyRef] */
  { /*    49 */ CryptoConf_CryptoKey_Master_ECU_Key          ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Master_ECU_Key, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Master_ECU_Key:CsmKeyRef] */
    /* Index    Ref                                            CryptoFunctionsIdx        Referable Keys */
  { /*    50 */ CryptoConf_CryptoKey_Monotonic_Counter       ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_Monotonic_Counter, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_Monotonic_Counter:CsmKeyRef] */
  { /*    51 */ CryptoConf_CryptoKey_SHE_KEY_1               ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_SHE_KEY_1, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SHE_KEY_1:CsmKeyRef] */
  { /*    52 */ CryptoConf_CryptoKey_SHE_KEY_2               ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_SHE_KEY_2, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SHE_KEY_2:CsmKeyRef] */
  { /*    53 */ CryptoConf_CryptoKey_SHE_KEY_3               ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_SHE_KEY_3, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SHE_KEY_3:CsmKeyRef] */
  { /*    54 */ CryptoConf_CryptoKey_SHE_KEY_4               ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_SHE_KEY_4, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SHE_KEY_4:CsmKeyRef] */
  { /*    55 */ CryptoConf_CryptoKey_SHE_KEY_5               ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_SHE_KEY_5, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SHE_KEY_5:CsmKeyRef] */
  { /*    56 */ CryptoConf_CryptoKey_SHE_KEY_6               ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_SHE_KEY_6, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SHE_KEY_6:CsmKeyRef] */
  { /*    57 */ CryptoConf_CryptoKey_SHE_KEY_7               ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_SHE_KEY_7, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SHE_KEY_7:CsmKeyRef] */
  { /*    58 */ CryptoConf_CryptoKey_SHE_KEY_8               ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_SHE_KEY_8, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SHE_KEY_8:CsmKeyRef] */
  { /*    59 */ CryptoConf_CryptoKey_SHE_KEY_9               ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_SHE_KEY_9, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SHE_KEY_9:CsmKeyRef] */
  { /*    60 */ CryptoConf_CryptoKey_SHE_KEY_10              ,                 0u },  /* [/ActiveEcuC/CryIf/CryIfKey_SHE_KEY_10, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SHE_KEY_10:CsmKeyRef] */
  { /*    61 */ CryptoConf_CryptoKey_SHE_RAM_KEY             ,                 0u }   /* [/ActiveEcuC/CryIf/CryIfKey_SHE_RAM_KEY, /ActiveEcuC/CryIf, /ActiveEcuC/Csm/CsmKeys/CsmKey_SHE_RAM_KEY:CsmKeyRef] */
};
#define CRYIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CryIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */





/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/



 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  END OF FILE: CryIf_Cfg.c
 *********************************************************************************************************************/
