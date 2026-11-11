/* VendorSpecifc File Header *//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

 
/*===========================================================================*/
/**
 * @file Crypto_182_iND13400_Cfg.h
 * Crypto Driver configurations
 *
 * @date    Generation Time:   11-08-2026 12:32:52
 *
 * @copyright (c) indie Semiconductor 2025. All rights reserved.
 * Information within this file is indie Semiconductor confidential and proprietary.
 *
 * @details
 * ### Full description
 * Configurations need by the crypto driver
 *
 * ### Traceability info
 * + **Design documents:**
 *     + AUTOSAR_SWS_CryptoDriver.pdf
 *
 * + **Requirements document:**
 *     + AUTOSAR_SWS_CryptoDriver.pdf
 *
 * + **Applicable standards:**
 *     + Autosar Release R22-11
 *
 * + **Deviations from standards:**
 *
 *
 */
/*===========================================================================*/
#if !defined (Crypto_182_iND13400_CFG_H)
# define Crypto_182_iND13400_CFG_H
/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "Std_Types.h"
/*===========================================================================*
 * Local Preprocessor defined Constants
 *===========================================================================*/
/**< CRYPTO Configuration Version*/
#define CRYPTO_182_iND13400_CFG_MAJOR_VERSION              (2U)      
#define CRYPTO_182_iND13400_CFG_MINOR_VERSION              (5U)
/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/
 typedef enum
{
    CRYPTO_RA_ALLOWED,
    CRYPTO_RA_DENIED,
    CRYPTO_RA_ENCRYPTED,
    CRYPTO_RA_INTERNAL_COPY
} CryptoKeyElementReadAccess;

typedef enum
{
    CRYPTO_WA_ALLOWED,
    CRYPTO_WA_DENIED,
    CRYPTO_WA_ENCRYPTED,
    CRYPTO_WA_INTERNAL_COPY
} CryptoKeyElementWriteAccess;

typedef enum
{
    CRYPTO_KE_FORMAT_BIN_IDENT_PRIVATEKEY_PKCS8,
    CRYPTO_KE_FORMAT_BIN_IDENT_PUBLICKEY,
    CRYPTO_KE_FORMAT_BIN_OCTET,
    CRYPTO_KE_FORMAT_BIN_RSA_PRIVATEKEY,
    CRYPTO_KE_FORMAT_BIN_RSA_PUBLICKEY,
    CRYPTO_KE_FORMAT_BIN_SHEKEYS
} CryptoKeyElementFormat;

typedef enum
{
	CRYPTO_NV_BLOCK_DEFERRED,
	CRYPTO_NV_BLOCK_IMMEDIATE
} CryptoNvBlockProcessing;

typedef struct {
CONST(uint8, CRYPTO_CODE)   KeyElementAllowPartialAccess;
CONST(uint8, CRYPTO_CODE)   KeyElementPersist;
CONST(CryptoKeyElementReadAccess, CRYPTO_CODE) KeyElementReadAcces;
CONST(CryptoKeyElementWriteAccess, CRYPTO_CODE) KeyElementWriteAcces;
}CryptoKeyElementReadWriteAccess;

typedef struct {
P2CONST(char , AUTOMATIC,CRYPTO_CODE) KeyElementShortName;
CONST(uint32, CRYPTO_CODE)   KeyElementId;
CONST(CryptoKeyElementFormat, CRYPTO_CODE) KeyElementFormat;
CONST(uint32, CRYPTO_CODE)  KeyElementMaxSize;
CONST(uint32, CRYPTO_CODE)  KeyElementInitLength;
}CryptoKeyElement;

typedef struct {
P2CONST(char , AUTOMATIC,CRYPTO_CODE) NvBlockShortName;
CONST(uint32, CRYPTO_CODE)   NvBlockIdentifier;
CONST(uint32, CRYPTO_CODE)   NvBlockFailedRetries;
CONST(uint32, CRYPTO_CODE)   NvBlockLength;
CONST(CryptoNvBlockProcessing, CRYPTO_CODE)   NvBlockProcessing;
}CryptoNvBlock;


typedef struct {
CONST(uint32, CRYPTO_CODE)	 KeyShortName;
CONST(uint32, CRYPTO_CODE)   KeyNvBlockId;
CONST(uint8, CRYPTO_CODE)    KeyType;
CONST(uint8, CRYPTO_CODE)	 KeyPersist;
} CryptoKeyConfig;

typedef enum
{
    HSM_INTERNAL_HW_ERROR_INFO_PARITY_ERROR_RESERVED = 0x00000001U, /* Bit 0: Reserved for parity error, reads 0 */
    HSM_INTERNAL_HW_ERROR_INFO_HW_PANIC             = 0x00000002U, /* Bit 1: HW panic if set */
    HSM_INTERNAL_HW_ERROR_INFO_SW_HALT              = 0x00000004U  /* Bit 2: SW halt if set */

} Hsm_InternalHwErrorInfoType_t;

typedef enum
{
    HSM_INTERNAL_SW_ERR_INFO_ENOENT  = 2U,  /* Invalid lifecycle in OTP; fboot cannot continue */
    HSM_INTERNAL_SW_ERR_INFO_EINTR   = 4U,  /* Supervisor OS exception/trap; reboot required */
    HSM_INTERNAL_SW_ERR_INFO_EIO     = 5U,  /* Security monitor exception/trap; reboot required */
    HSM_INTERNAL_SW_ERR_INFO_ENOEXEC = 8U,  /* fboot lifecycle operation failed; reboot required */
    HSM_INTERNAL_SW_ERR_INFO_EBADF   = 9U,  /* Boot bypass failed; reboot required */
    HSM_INTERNAL_SW_ERR_INFO_EAGAIN  = 11U, /* Higher-level boot loaders failed; fallback to fboot */
    HSM_INTERNAL_SW_ERR_INFO_EFAULT  = 14U, /* Supervisor-mode fboot container runtime error */
    HSM_INTERNAL_SW_ERR_INFO_EPIPE   = 32U  /* NMI interrupt fired and system halted; reboot required */

} Hsm_InternalSwErrInfoMajorErrorCodeType_t;

typedef enum
{
    HSM_INTERNAL_SW_ERR_INFO_MINOR_EPERM   = 1U,  /* Image signature verification or permission error */
    HSM_INTERNAL_SW_ERR_INFO_MINOR_ENOENT  = 2U,  /* Next phase image/container not found */
    HSM_INTERNAL_SW_ERR_INFO_MINOR_EINTR   = 4U,  /* NMI interrupt fired and system halted */
    HSM_INTERNAL_SW_ERR_INFO_MINOR_EIO     = 5U,  /* Failed to use a core, e.g. read/write failed */
    HSM_INTERNAL_SW_ERR_INFO_MINOR_ENOEXEC = 8U,  /* Device is decommissioned */
    HSM_INTERNAL_SW_ERR_INFO_MINOR_EACCES  = 13U, /* Invalid boot bypass vector or invalid syscall parameters */
    HSM_INTERNAL_SW_ERR_INFO_MINOR_EFAULT  = 14U, /* Image format error */
    HSM_INTERNAL_SW_ERR_INFO_MINOR_EBUSY   = 16U, /* Operation cannot be executed yet */
    HSM_INTERNAL_SW_ERR_INFO_MINOR_ENODEV  = 19U, /* Failed to open a core */
    HSM_INTERNAL_SW_ERR_INFO_MINOR_EINVAL  = 22U, /* Invalid parameters or unsupported container footer values */
    HSM_INTERNAL_SW_ERR_INFO_MINOR_ENOSPC  = 28U  /* Image header missing or no room to load more containers */

} Hsm_InternalSwErrInfoMinorErrorCodeType_t;


typedef enum
{
    HSM_DEVICE_LIFECYCLE_BLANK          = 0x00000000U, /* BLANK: Not tested nor provisioned */
    HSM_DEVICE_LIFECYCLE_TESTED         = 0x00000500U, /* TESTED */
    HSM_DEVICE_LIFECYCLE_PROVISIONED    = 0x00010D01U, /* PROVISIONED */
    HSM_DEVICE_LIFECYCLE_MISSION        = 0x20010D03U, /* MISSION: Ready for deployment */
    HSM_DEVICE_LIFECYCLE_FRA            = 0x70010DA3U, /* FRA: Field return analysis */
    HSM_DEVICE_LIFECYCLE_DECOMMISSIONED = 0x7C034DA3U  /* DECOMMISSIONED: Nonfunctional */

} Hsm_DeviceLifecycleType_t;


typedef enum
{
    HSM_OTP_HW_ERROR_INFO_OMC_PARSE_DONE        = 0x00000001U, /* Bit 0: OMC finished parsing OTP memory; set to 1 in normal case */
    HSM_OTP_HW_ERROR_INFO_LIFECYCLE_PARSE_ERROR = 0x00000002U  /* Bit 1: OTP lifecycle field parsing error */

} Hsm_OtpHwErrorInfoType_t;


typedef enum
{
    /* SAFETY_DIAGNOSIS_0  */
    HSM_SAFETY_DIAG_ERROR_NONE            = 0x00000000U,

    /* System integration */
    HSM_SAFETY_DIAG_ERROR_EAC             ,
    HSM_SAFETY_DIAG_ERROR_SIC             ,

    /* Cryptographic cores */
    HSM_SAFETY_DIAG_ERROR_AES             ,
    HSM_SAFETY_DIAG_ERROR_HC              ,
    HSM_SAFETY_DIAG_ERROR_PKE             ,

    /* Memory and DMA */
    HSM_SAFETY_DIAG_ERROR_DMAC            ,
    HSM_SAFETY_DIAG_ERROR_FMC             ,

    /* Key management */
    HSM_SAFETY_DIAG_ERROR_KTC             ,
    HSM_SAFETY_DIAG_ERROR_KDC             ,

    /* Random number generation */
    HSM_SAFETY_DIAG_ERROR_TMC             ,

    /* Software KAT */
    HSM_SAFETY_DIAG_ERROR_ESW_KAT_FAILURE ,

    /* SAFETY_DIAGNOSIS_1  */
    /* Memory */
    HSM_SAFETY_DIAG_ERROR_SRAM_BUS_INTEGRITY     ,
    HSM_SAFETY_DIAG_ERROR_SRAM_FSM_INTEGRITY     ,
    HSM_SAFETY_DIAG_ERROR_SRAM_MEMORY_INTEGRITY  ,
    /* Processor */
    HSM_SAFETY_DIAG_ERROR_PLIC                   ,
    HSM_SAFETY_DIAG_ERROR_CPU                    ,
    /* Timer and wachdog */
    HSM_SAFETY_DIAG_ERROR_TIM                    ,
    /* System */
    HSM_SAFETY_DIAG_ERROR_OMC                    ,
    HSM_SAFETY_DIAG_ERROR_CC                     ,
    HSM_SAFETY_DIAG_ERROR_CLK_RST                ,
    /* External */
    HSM_SAFETY_DIAG_ERROR_EXTERNAL_SAFETY_ALARM  


} Hsm_SafetyDiagErrorType_t;

typedef struct
{
    Hsm_InternalHwErrorInfoType_t HsmInternalHwError;
    Hsm_InternalSwErrInfoMajorErrorCodeType_t HsmInternalSwMajorError;
    Hsm_InternalSwErrInfoMinorErrorCodeType_t HsmInternalSwMinorError;
    Hsm_DeviceLifecycleType_t HsmDeviceLifeCycle;
    Hsm_OtpHwErrorInfoType_t  HsmOtpHwError;
    Hsm_SafetyDiagErrorType_t HsmSafetyDiagError;
    boolean SupervisorRunnning;
    boolean ContainerRunning;
    boolean ReadyToRunContainer;
    boolean MwIsReady;

}FusaAlarmRecord_t;
/*===========================================================================*
 * Global Preprocessor defined MACROS
 *===========================================================================*/
#define     Crypto_182_iND13400_DEV_ERROR_REPORT                   STD_ON
#define     Crypto_182_iND13400_DRIVER_OBJECTS_COUNT               2
#define     Crypto_182_iND13400_NUMBER_OF_KEYS                     62
#define     CRYPTO_182_NVM_BLOCK_SUPPORT							STD_OFF
#define 	CRYPTO_182_NVM_KEY_VAULT_BLOCKLENGTH 					(0U)


/* list of macros changed for removing SHE key from the struct sent to HSM filtered keys*/
#define     Crypto_182_iND13400_NUMBER_OF_KEYS_FILTERED                     48
#define     Crypto_182_iND13400_START_IDX_OF_FILTERED_KEY_ELEMENTS          35
#define Crypto_182_iND13400_NUMBER_OF_KEY_ELEMENTS_FILTERED    143

#ifndef CRYPTO_KEYSTRUCT_DEFAULT_VALUE
	# define        CRYPTO_KEYSTRUCT_DEFAULT_VALUE                 0u
#endif
#define CryptoConf_CryptoDriverObject_Crypto_182_iND13400_SymmetricDriverObject         0
#define CryptoConf_CryptoDriverObject_Crypto_182_iND13400_AsymmetricDriverObject        1

#define  CryptoConf_CryptoKey_Hash_Key        (                15U)
#define  CryptoConf_CryptoKey_AES_128_Key        (             16U)
#define  CryptoConf_CryptoKey_MKA_CAK_Key        (             17U)
#define  CryptoConf_CryptoKey_MKA_Random_Key        (          18U)
#define  CryptoConf_CryptoKey_MKA_ICK_Key        (             19U)
#define  CryptoConf_CryptoKey_RNG_Key        (                 20U)
#define  CryptoConf_CryptoKey_MKA_KEK_Key        (             21U)
#define  CryptoConf_CryptoKey_MKA_SAK_Key        (             22U)
#define  CryptoConf_CryptoKey_MKA_MAC_Key        (             23U)
#define  CryptoConf_CryptoKey_MKA_SAK_Data_Key        (        24U)
#define  CryptoConf_CryptoKey_AES_256_Key        (             27U)
#define  CryptoConf_CryptoKey_RSA_1024_Key        (            28U)
#define  CryptoConf_CryptoKey_RSA_2048_Key        (            29U)
#define  CryptoConf_CryptoKey_RSA_3072_Key        (            30U)
#define  CryptoConf_CryptoKey_RSA_4096_Key        (            31U)
#define  CryptoConf_CryptoKey_ECC_192_Key_SigGenerate        ( 32U)
#define  CryptoConf_CryptoKey_ECC_224_Key_SigGenerate        ( 33U)
#define  CryptoConf_CryptoKey_ECC_256_Key_SigGenerate        ( 34U)
#define  CryptoConf_CryptoKey_ECC_384_Key_SigGenerate        ( 35U)
#define  CryptoConf_CryptoKey_ECC_512_Key_SigGenerate        ( 38U)
#define  CryptoConf_CryptoKey_ECC_521_Key_SigGenerate        ( 36U)
#define  CryptoConf_CryptoKey_ECC_320_Key_SigGenerate        ( 37U)
#define  CryptoConf_CryptoKey_Custom_Operations        (       25U)
#define  CryptoConf_CryptoKey_ECDH_128_Key_SigGenerate        (39U)
#define  CryptoConf_CryptoKey_ECDH_224_Key_SigGenerate        (40U)
#define  CryptoConf_CryptoKey_ECDH_256_Key_SigGenerate        (41U)
#define  CryptoConf_CryptoKey_ECDH_384_Key_SigGenerate        (42U)
#define  CryptoConf_CryptoKey_ECDH_512_Key_SigGenerate        (43U)
#define  CryptoConf_CryptoKey_Monotonic_Counter        (       26U)
#define  CryptoConf_CryptoKey_ED448_Key_SigGenerate        (   44U)
#define  CryptoConf_CryptoKey_ECC_256_Key_Generate        (    45U)
#define  CryptoConf_CryptoKey_Boot_MAC        (                3U)
#define  CryptoConf_CryptoKey_Boot_MAC_Key        (            2U)
#define  CryptoConf_CryptoKey_Master_ECU_Key        (          1U)
#define  CryptoConf_CryptoKey_SHE_KEY_1        (               4U)
#define  CryptoConf_CryptoKey_SHE_KEY_2        (               5U)
#define  CryptoConf_CryptoKey_SHE_KEY_3        (               6U)
#define  CryptoConf_CryptoKey_SHE_KEY_4        (               7U)
#define  CryptoConf_CryptoKey_SHE_KEY_5        (               8U)
#define  CryptoConf_CryptoKey_SHE_KEY_6        (               9U)
#define  CryptoConf_CryptoKey_SHE_KEY_7        (               10U)
#define  CryptoConf_CryptoKey_SHE_KEY_8        (               11U)
#define  CryptoConf_CryptoKey_SHE_KEY_9        (               12U)
#define  CryptoConf_CryptoKey_SHE_KEY_10        (              13U)
#define  CryptoConf_CryptoKey_SHE_RAM_KEY        (             14U)
#define  CryptoConf_CryptoKey_ED25519_Key_SigGenerate        ( 46U)
#define  CryptoConf_CryptoKey_ECC_192_Key_SigVerify        (   47U)
#define  CryptoConf_CryptoKey_ECC_224_Key_SigVerify        (   48U)
#define  CryptoConf_CryptoKey_ECC_256_Key_SigVerify        (   49U)
#define  CryptoConf_CryptoKey_ECC_320_Key_SigVerify        (   50U)
#define  CryptoConf_CryptoKey_ECC_384_Key_SigVerify        (   51U)
#define  CryptoConf_CryptoKey_ECC_512_Key_SigVerify        (   52U)
#define  CryptoConf_CryptoKey_ECC_521_Key_SigVerify        (   53U)
#define  CryptoConf_CryptoKey_ECDH_128_Key_SigVerify        (  54U)
#define  CryptoConf_CryptoKey_ECDH_224_Key_SigVerify        (  55U)
#define  CryptoConf_CryptoKey_ECDH_256_Key_SigVerify        (  56U)
#define  CryptoConf_CryptoKey_ECDH_384_Key_SigVerify        (  57U)
#define  CryptoConf_CryptoKey_ECDH_512_Key_SigVerify        (  58U)
#define  CryptoConf_CryptoKey_ED448_Key_SigVerify        (     59U)
#define  CryptoConf_CryptoKey_ED25519_Key_SigVerify        (   60U)
#define  CryptoConf_CryptoKey_ECC_256_Key_Generate_2        (  61U)
#define  CryptoConf_CryptoKey_ECC_224_Key_Exchange        (    62U)
 
#define     Crypto_182_iND13400_NUMPER_OF_IPC_CHANNEL           2u
#define     Crypto_182_iND13400_USE_POLLING                     STD_ON
#define     Crypto_182_iND13400_USE_FUSA_CALLBACK_FUNCTION                     STD_OFF
#define		CRYPTO_182_NV_CUSTOM_CALLOUT_SUPPORT				STD_OFF


/* Key Elements [SWS_Csm_01022] */
#if !defined (CRYPTO_KE_RSA_PUB_EXPONENT) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_RSA_PUB_EXPONENT                   161
#endif
#if !defined (CRYPTO_KE_RSA_SALT) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_RSA_SALT                           163
#endif
#if !defined (CRYPTO_KE_RSA_SALT_LENGTH) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_RSA_SALT_LENGTH                    164
#endif
#if !defined (CRYPTO_KE_RSA_LABEL) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_RSA_LABEL                          3058
#endif
#if !defined (Hash_KeyElement) /* COV_CSM_USER_DEFINES */
#define  Hash_KeyElement                              1
#endif
#if !defined (MKA_KE_CAK_KEY_CUSTOM) /* COV_CSM_USER_DEFINES */
#define  MKA_KE_CAK_KEY_CUSTOM                        1
#endif
#if !defined (MKA_KE_CAK_CKN) /* COV_CSM_USER_DEFINES */
#define  MKA_KE_CAK_CKN                               2
#endif
#if !defined (MKA_Random_KeyElement) /* COV_CSM_USER_DEFINES */
#define  MKA_Random_KeyElement                        1
#endif
#if !defined (MKA_ICK_KeyElement) /* COV_CSM_USER_DEFINES */
#define  MKA_ICK_KeyElement                           1
#endif
#if !defined (MKA_KEK_KeyElement) /* COV_CSM_USER_DEFINES */
#define  MKA_KEK_KeyElement                           1
#endif
#if !defined (MKA_MAC_KeyElement) /* COV_CSM_USER_DEFINES */
#define  MKA_MAC_KeyElement                           1
#endif
#if !defined (MKA_SAK_Data_KeyElement) /* COV_CSM_USER_DEFINES */
#define  MKA_SAK_Data_KeyElement                      1
#endif
#if !defined (CRYPTO_KE_KEYGENERATE_SEED) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_KEYGENERATE_SEED                   16
#endif
#if !defined (CRYPTO_KE_MAC_PROOF) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_MAC_PROOF                          2
#endif
#if !defined (CRYPTO_KE_SIGNATURE_CURVETYPE) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_SIGNATURE_CURVETYPE                29
#endif
#if !defined (CRYPTO_KE_RANDOM_SEED_STATE) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_RANDOM_SEED_STATE                  3
#endif
#if !defined (CRYPTO_KE_RANDOM_ALGORITHM) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_RANDOM_ALGORITHM                   4
#endif
#if !defined (CRYPTO_KE_CIPHER_KEY) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_CIPHER_KEY                         1
#endif
#if !defined (CRYPTO_KE_CIPHER_PROOF) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_CIPHER_PROOF                       2
#endif
#if !defined (CRYPTO_KE_CIPHER_IV) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_CIPHER_IV                          5
#endif
#if !defined (CRYPTO_KE_CIPHER_2NDKEY) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_CIPHER_2NDKEY                      7
#endif
#if !defined (CRYPTO_KE_KEYEXCHANGE_BASE) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_KEYEXCHANGE_BASE                   8
#endif
#if !defined (CRYPTO_KE_KEYEXCHANGE_PRIVKEY) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_KEYEXCHANGE_PRIVKEY                9
#endif
#if !defined (CRYPTO_KE_KEYEXCHANGE_OWNPUBKEY) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_KEYEXCHANGE_OWNPUBKEY              10
#endif
#if !defined (CRYPTO_KE_KEYEXCHANGE_SHAREDVALUE) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_KEYEXCHANGE_SHAREDVALUE            1
#endif
#if !defined (CRYPTO_KE_KEYEXCHANGE_ALGORITHM) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_KEYEXCHANGE_ALGORITHM              12
#endif
#if !defined (CRYPTO_KE_KEYEXCHANGE_CURVETYPE) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_KEYEXCHANGE_CURVETYPE              29
#endif
#if !defined (CRYPTO_KE_KEYGENERATE_ALGORITHM) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_KEYGENERATE_ALGORITHM              17
#endif
#if !defined (CRYPTO_KE_KEYGENERATE_CURVETYPE) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_KEYGENERATE_CURVETYPE              29
#endif
#if !defined (CUSTOM_KE_KDF) /* COV_CSM_USER_DEFINES */
#define  CUSTOM_KE_KDF                                1000
#endif
#if !defined (CUSTOM_KE_KUW) /* COV_CSM_USER_DEFINES */
#define  CUSTOM_KE_KUW                                1001
#endif
#if !defined (CUSTOM_KE_VER) /* COV_CSM_USER_DEFINES */
#define  CUSTOM_KE_VER                                1011
#endif
#if !defined (CUSTOM_KE_DUAL_BOOT_BOOT_STATUS) /* COV_CSM_USER_DEFINES */
#define  CUSTOM_KE_DUAL_BOOT_BOOT_STATUS              1002
#endif
#if !defined (CUSTOM_KE_DUAL_BOOT_RESET_STATUS) /* COV_CSM_USER_DEFINES */
#define  CUSTOM_KE_DUAL_BOOT_RESET_STATUS             1003
#endif
#if !defined (MC_KE_COUNTER1) /* COV_CSM_USER_DEFINES */
#define  MC_KE_COUNTER1                               1000
#endif
#if !defined (MC_KE_COUNTER2) /* COV_CSM_USER_DEFINES */
#define  MC_KE_COUNTER2                               1001
#endif
#if !defined (MC_KE_COUNTER3) /* COV_CSM_USER_DEFINES */
#define  MC_KE_COUNTER3                               1002
#endif
#if !defined (MC_KE_COUNTER4) /* COV_CSM_USER_DEFINES */
#define  MC_KE_COUNTER4                               1003
#endif
#if !defined (MC_KE_COUNTER5) /* COV_CSM_USER_DEFINES */
#define  MC_KE_COUNTER5                               1004
#endif
#if !defined (MC_KE_COUNTER6) /* COV_CSM_USER_DEFINES */
#define  MC_KE_COUNTER6                               1005
#endif
#if !defined (MC_KE_COUNTER7) /* COV_CSM_USER_DEFINES */
#define  MC_KE_COUNTER7                               1006
#endif
#if !defined (MC_KE_COUNTER8) /* COV_CSM_USER_DEFINES */
#define  MC_KE_COUNTER8                               1007
#endif
#if !defined (MC_KE_COUNTER9) /* COV_CSM_USER_DEFINES */
#define  MC_KE_COUNTER9                               1008
#endif
#if !defined (MC_KE_COUNTER10) /* COV_CSM_USER_DEFINES */
#define  MC_KE_COUNTER10                              1009
#endif
#if !defined (MC_KE_COUNTER11) /* COV_CSM_USER_DEFINES */
#define  MC_KE_COUNTER11                              1010
#endif
#if !defined (MC_KE_COUNTER12) /* COV_CSM_USER_DEFINES */
#define  MC_KE_COUNTER12                              1011
#endif
#if !defined (CUSTOM_KE_SWD_UNLOCK) /* COV_CSM_USER_DEFINES */
#define  CUSTOM_KE_SWD_UNLOCK                         1004
#endif
#if !defined (CUSTOM_KE_SWD_LOCK) /* COV_CSM_USER_DEFINES */
#define  CUSTOM_KE_SWD_LOCK                           1005
#endif
#if !defined (CRYPTO_KE_KEYGENERATE_ECC_PUBLIC_KEY) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_KEYGENERATE_ECC_PUBLIC_KEY         10
#endif
#if !defined (CRYPTO_KE_KEYGENERATE_ECC_PRIVATE_KEY) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_KEYGENERATE_ECC_PRIVATE_KEY        9
#endif
#if !defined (CRYPTO_KE_CIPHER_KEY_AES_128) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_CIPHER_KEY_AES_128                 1
#endif
#if !defined (CRYPTO_KE_CIPHER_KEY_AES_256) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_CIPHER_KEY_AES_256                 1
#endif
#if !defined (CRYPTO_KE_RSA_MODULUS_1024) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_RSA_MODULUS_1024                   160
#endif
#if !defined (CRYPTO_KE_RSA_MODULUS_2048) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_RSA_MODULUS_2048                   160
#endif
#if !defined (CRYPTO_KE_RSA_MODULUS_3072) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_RSA_MODULUS_3072                   160
#endif
#if !defined (CRYPTO_KE_RSA_MODULUS_4096) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_RSA_MODULUS_4096                   160
#endif
#if !defined (CRYPTO_KE_RSA_PRIV_EXPONENT_1024) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_RSA_PRIV_EXPONENT_1024             162
#endif
#if !defined (CRYPTO_KE_RSA_PRIV_EXPONENT_2048) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_RSA_PRIV_EXPONENT_2048             162
#endif
#if !defined (CRYPTO_KE_RSA_PRIV_EXPONENT_3072) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_RSA_PRIV_EXPONENT_3072             162
#endif
#if !defined (CRYPTO_KE_RSA_PRIV_EXPONENT_4096) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_RSA_PRIV_EXPONENT_4096             162
#endif
#if !defined (MC_KE_COUNTER13) /* COV_CSM_USER_DEFINES */
#define  MC_KE_COUNTER13                              1012
#endif
#if !defined (MC_KE_COUNTER14) /* COV_CSM_USER_DEFINES */
#define  MC_KE_COUNTER14                              1013
#endif
#if !defined (MC_KE_COUNTER15) /* COV_CSM_USER_DEFINES */
#define  MC_KE_COUNTER15                              1014
#endif
#if !defined (MC_KE_COUNTER16) /* COV_CSM_USER_DEFINES */
#define  MC_KE_COUNTER16                              1015
#endif
#if !defined (CUSTOM_KE_ADVANCE_LIFE_CYCLE) /* COV_CSM_USER_DEFINES */
#define  CUSTOM_KE_ADVANCE_LIFE_CYCLE                 1007
#endif
#if !defined (CUSTOM_KE_DEVICE_ID) /* COV_CSM_USER_DEFINES */
#define  CUSTOM_KE_DEVICE_ID                          1006
#endif
#if !defined (CRYPTO_KE_CIPHER_SHE_KEY) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_CIPHER_SHE_KEY                     1
#endif
#if !defined (CRYPTO_KE_MAC_SHE) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_MAC_SHE                            1
#endif
#if !defined (CRYPTO_KE_SHE_BOOT_MAC) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_SHE_BOOT_MAC                       1
#endif
#if !defined (CRYPTO_KE_SHE_BOOT_MAC_KEY) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_SHE_BOOT_MAC_KEY                   1
#endif
#if !defined (CRYPTO_KE_SHE_MASTER_ECU) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_SHE_MASTER_ECU                     1
#endif
#if !defined (CRYPTO_KE_SIGNATURE_KEY_ECC_192) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_SIGNATURE_KEY_ECC_192              1
#endif
#if !defined (CRYPTO_KE_SIGNATURE_KEY_ECC_224) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_SIGNATURE_KEY_ECC_224              1
#endif
#if !defined (CRYPTO_KE_SIGNATURE_KEY_ECC_256) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_SIGNATURE_KEY_ECC_256              1
#endif
#if !defined (CRYPTO_KE_SIGNATURE_KEY_ECC_320) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_SIGNATURE_KEY_ECC_320              1
#endif
#if !defined (CRYPTO_KE_SIGNATURE_KEY_ECC_384) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_SIGNATURE_KEY_ECC_384              1
#endif
#if !defined (CRYPTO_KE_SIGNATURE_KEY_ECC_512) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_SIGNATURE_KEY_ECC_512              1
#endif
#if !defined (CRYPTO_KE_SIGNATURE_KEY_ECC_521) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_SIGNATURE_KEY_ECC_521              1
#endif
#if !defined (CRYPTO_KE_SIGNATURE_KEY_ECDH_128) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_SIGNATURE_KEY_ECDH_128             1
#endif
#if !defined (CRYPTO_KE_SIGNATURE_KEY_ECDH_224) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_SIGNATURE_KEY_ECDH_224             1
#endif
#if !defined (CRYPTO_KE_SIGNATURE_KEY_ECDH_256) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_SIGNATURE_KEY_ECDH_256             1
#endif
#if !defined (CRYPTO_KE_SIGNATURE_KEY_ECDH_384) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_SIGNATURE_KEY_ECDH_384             1
#endif
#if !defined (CRYPTO_KE_SIGNATURE_KEY_ECDH_512) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_SIGNATURE_KEY_ECDH_512             1
#endif
#if !defined (CRYPTO_KE_SIGNATURE_KEY_ED_448) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_SIGNATURE_KEY_ED_448               1
#endif
#if !defined (CRYPTO_KE_SIGNATURE_KEY_ED_25519) /* COV_CSM_USER_DEFINES */
#define  CRYPTO_KE_SIGNATURE_KEY_ED_25519             1
#endif

#define Crypto_182_iND13400_KEY_ELEMENT_BOUNDARIES {\
{0 , 2},\
{2 , 4},\
{4 , 6},\
{6 , 9},\
{9 , 12},\
{12 , 15},\
{15 , 18},\
{18 , 21},\
{21 , 24},\
{24 , 26},\
{26 , 28},\
{28 , 30},\
{30 , 32},\
{32 , 35},\
{35 , 36},\
{36 , 40},\
{40 , 42},\
{42 , 43},\
{43 , 44},\
{44 , 46},\
{46 , 47},\
{47 , 51},\
{51 , 52},\
{52 , 53},\
{53 , 62},\
{62 , 78},\
{78 , 82},\
{82 , 88},\
{88 , 94},\
{94 , 100},\
{100 , 106},\
{106 , 108},\
{108 , 110},\
{110 , 112},\
{112 , 114},\
{114 , 116},\
{116 , 118},\
{118 , 120},\
{120 , 122},\
{122 , 124},\
{124 , 126},\
{126 , 128},\
{128 , 130},\
{130 , 132},\
{132 , 137},\
{137 , 139},\
{139 , 141},\
{141 , 143},\
{143 , 145},\
{145 , 147},\
{147 , 149},\
{149 , 151},\
{151 , 153},\
{153 , 155},\
{155 , 157},\
{157 , 159},\
{159 , 161},\
{161 , 163},\
{163 , 165},\
{165 , 167},\
{167 , 172},\
{172 , 178}\
} 

#define Crypto_182_iND13400_KEY_ELEMENTS {\
CRYPTO_KE_SHE_MASTER_ECU , \
CRYPTO_KE_CIPHER_PROOF , \
CRYPTO_KE_SHE_BOOT_MAC_KEY , \
CRYPTO_KE_CIPHER_PROOF , \
CRYPTO_KE_SHE_BOOT_MAC , \
CRYPTO_KE_CIPHER_PROOF , \
CRYPTO_KE_CIPHER_SHE_KEY , \
CRYPTO_KE_CIPHER_PROOF , \
CRYPTO_KE_CIPHER_IV , \
CRYPTO_KE_CIPHER_SHE_KEY , \
CRYPTO_KE_CIPHER_PROOF , \
CRYPTO_KE_CIPHER_IV , \
CRYPTO_KE_CIPHER_SHE_KEY , \
CRYPTO_KE_CIPHER_PROOF , \
CRYPTO_KE_CIPHER_IV , \
CRYPTO_KE_CIPHER_SHE_KEY , \
CRYPTO_KE_CIPHER_PROOF , \
CRYPTO_KE_CIPHER_IV , \
CRYPTO_KE_CIPHER_SHE_KEY , \
CRYPTO_KE_CIPHER_PROOF , \
CRYPTO_KE_CIPHER_IV , \
CRYPTO_KE_CIPHER_SHE_KEY , \
CRYPTO_KE_CIPHER_PROOF , \
CRYPTO_KE_CIPHER_IV , \
CRYPTO_KE_MAC_SHE , \
CRYPTO_KE_MAC_PROOF , \
CRYPTO_KE_MAC_SHE , \
CRYPTO_KE_MAC_PROOF , \
CRYPTO_KE_MAC_SHE , \
CRYPTO_KE_MAC_PROOF , \
CRYPTO_KE_MAC_SHE , \
CRYPTO_KE_MAC_PROOF , \
CRYPTO_KE_CIPHER_SHE_KEY , \
CRYPTO_KE_CIPHER_PROOF , \
CRYPTO_KE_CIPHER_IV , \
Hash_KeyElement , \
CRYPTO_KE_CIPHER_KEY_AES_128 , \
CRYPTO_KE_CIPHER_IV , \
CRYPTO_KE_CIPHER_2NDKEY , \
CRYPTO_KE_CIPHER_PROOF , \
MKA_KE_CAK_CKN , \
MKA_KE_CAK_KEY_CUSTOM , \
MKA_Random_KeyElement , \
MKA_ICK_KeyElement , \
CRYPTO_KE_RANDOM_ALGORITHM , \
CRYPTO_KE_RANDOM_SEED_STATE , \
MKA_KEK_KeyElement , \
CRYPTO_KE_CIPHER_2NDKEY , \
CRYPTO_KE_CIPHER_IV , \
CRYPTO_KE_CIPHER_KEY , \
CRYPTO_KE_CIPHER_PROOF , \
MKA_MAC_KeyElement , \
MKA_SAK_Data_KeyElement , \
CUSTOM_KE_KDF , \
CUSTOM_KE_KUW , \
CUSTOM_KE_VER , \
CUSTOM_KE_DUAL_BOOT_BOOT_STATUS , \
CUSTOM_KE_DUAL_BOOT_RESET_STATUS , \
CUSTOM_KE_SWD_UNLOCK , \
CUSTOM_KE_SWD_LOCK , \
CUSTOM_KE_ADVANCE_LIFE_CYCLE , \
CUSTOM_KE_DEVICE_ID , \
MC_KE_COUNTER1 , \
MC_KE_COUNTER2 , \
MC_KE_COUNTER3 , \
MC_KE_COUNTER4 , \
MC_KE_COUNTER5 , \
MC_KE_COUNTER6 , \
MC_KE_COUNTER7 , \
MC_KE_COUNTER8 , \
MC_KE_COUNTER9 , \
MC_KE_COUNTER10 , \
MC_KE_COUNTER11 , \
MC_KE_COUNTER12 , \
MC_KE_COUNTER13 , \
MC_KE_COUNTER14 , \
MC_KE_COUNTER15 , \
MC_KE_COUNTER16 , \
CRYPTO_KE_CIPHER_KEY_AES_256 , \
CRYPTO_KE_CIPHER_IV , \
CRYPTO_KE_CIPHER_2NDKEY , \
CRYPTO_KE_CIPHER_PROOF , \
CRYPTO_KE_RSA_LABEL , \
CRYPTO_KE_RSA_MODULUS_1024 , \
CRYPTO_KE_RSA_PRIV_EXPONENT_1024 , \
CRYPTO_KE_RSA_PUB_EXPONENT , \
CRYPTO_KE_RSA_SALT , \
CRYPTO_KE_RSA_SALT_LENGTH , \
CRYPTO_KE_RSA_LABEL , \
CRYPTO_KE_RSA_MODULUS_2048 , \
CRYPTO_KE_RSA_PRIV_EXPONENT_2048 , \
CRYPTO_KE_RSA_PUB_EXPONENT , \
CRYPTO_KE_RSA_SALT , \
CRYPTO_KE_RSA_SALT_LENGTH , \
CRYPTO_KE_RSA_LABEL , \
CRYPTO_KE_RSA_MODULUS_3072 , \
CRYPTO_KE_RSA_PRIV_EXPONENT_3072 , \
CRYPTO_KE_RSA_PUB_EXPONENT , \
CRYPTO_KE_RSA_SALT , \
CRYPTO_KE_RSA_SALT_LENGTH , \
CRYPTO_KE_RSA_LABEL , \
CRYPTO_KE_RSA_MODULUS_4096 , \
CRYPTO_KE_RSA_PRIV_EXPONENT_4096 , \
CRYPTO_KE_RSA_PUB_EXPONENT , \
CRYPTO_KE_RSA_SALT , \
CRYPTO_KE_RSA_SALT_LENGTH , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ECC_192 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ECC_224 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ECC_256 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ECC_384 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ECC_521 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ECC_320 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ECC_512 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ECDH_128 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ECDH_224 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ECDH_256 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ECDH_384 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ECDH_512 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ED_448 , \
CRYPTO_KE_KEYGENERATE_ALGORITHM , \
CRYPTO_KE_KEYGENERATE_CURVETYPE , \
CRYPTO_KE_KEYGENERATE_SEED , \
CRYPTO_KE_KEYGENERATE_ECC_PRIVATE_KEY , \
CRYPTO_KE_KEYGENERATE_ECC_PUBLIC_KEY , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ED_25519 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ECC_192 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ECC_224 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ECC_256 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ECC_320 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ECC_384 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ECC_512 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ECC_521 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ECDH_128 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ECDH_224 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ECDH_256 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ECDH_384 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ECDH_512 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ED_448 , \
CRYPTO_KE_SIGNATURE_CURVETYPE , \
CRYPTO_KE_SIGNATURE_KEY_ED_25519 , \
CRYPTO_KE_KEYGENERATE_ALGORITHM , \
CRYPTO_KE_KEYGENERATE_CURVETYPE , \
CRYPTO_KE_KEYGENERATE_SEED , \
CRYPTO_KE_KEYGENERATE_ECC_PRIVATE_KEY , \
CRYPTO_KE_KEYGENERATE_ECC_PUBLIC_KEY , \
CRYPTO_KE_KEYEXCHANGE_ALGORITHM , \
CRYPTO_KE_KEYEXCHANGE_BASE , \
CRYPTO_KE_KEYEXCHANGE_CURVETYPE , \
CRYPTO_KE_KEYEXCHANGE_OWNPUBKEY , \
CRYPTO_KE_KEYEXCHANGE_PRIVKEY , \
CRYPTO_KE_KEYEXCHANGE_SHAREDVALUE  \
}

#define Crypto_182_iND13400_KEY_ELEMENTS_READ_WRITE_ACCESS_INIT {\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ENCRYPTED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ENCRYPTED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ENCRYPTED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)TRUE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ENCRYPTED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)TRUE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ENCRYPTED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)TRUE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ENCRYPTED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)TRUE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ENCRYPTED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)TRUE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ENCRYPTED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)TRUE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ENCRYPTED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ENCRYPTED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ENCRYPTED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ENCRYPTED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ENCRYPTED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)TRUE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ENCRYPTED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)TRUE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)TRUE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ENCRYPTED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)FALSE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED},\
    {(uint8)TRUE,		(uint8)FALSE,		(uint8)CRYPTO_WA_ALLOWED,		(uint8)CRYPTO_RA_ALLOWED}\
}

#define Crypto_182_iND13400_NUMBER_OF_KEY_ELEMENTS    178
#define Crypto_182_iND13400_ACCESSIBLE_APPS_NUM       0


/*===========================================================================*
* Exported Const Object Definitions
*===========================================================================*/
extern const CryptoKeyElement CryptoKeyElementList[Crypto_182_iND13400_NUMBER_OF_KEY_ELEMENTS];
extern const uint8 CryptoKeyElementsInitValues[];
extern const uint32 CryptoKeyElementsSize;


extern const CryptoKeyConfig KeyConfig[Crypto_182_iND13400_NUMBER_OF_KEYS_FILTERED]; 
/*===========================================================================*
* GLOBAL FUNCTIONS
*===========================================================================*/

#endif /* CRYPTO_CFG_H */

/*===========================================================================*
 *  Revision History
 *===========================================================================*/
/**
 *  ---------------------------------------------------------------------------
 *  Version   Date        Author          Description
 *  ---------------------------------------------------------------------------
 * 
**/

/*===========================================================================*
 *  END OF FILE: Crypto_182_iND13400_Cfg.h
 *===========================================================================*/
 

