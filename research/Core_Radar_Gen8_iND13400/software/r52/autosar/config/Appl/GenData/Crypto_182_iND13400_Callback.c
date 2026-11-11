/* VendorSpecifc File Header *//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/


/*===========================================================================*/
/**
 * @file Crypto_182_iND13400_Cfg.c
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

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "Crypto_182_iND13400.h"
#include "Crypto_182_iND13400_Private.h"
#include "Crypto_182_iND13400_IPC.h"

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/
 
 
/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
#if(CRYPTO_182_NVM_BLOCK_SUPPORT == TRUE)

extern uint8 Global_CryptoKeyVRamMirror[Crypto_182_iND13400_NUMBER_OF_NV_BLOCKS][CRYPTO_182_NVM_KEY_VAULT_BLOCKLENGTH];
extern NvMBlockReadAllStatus_t Crypto_NvMReadAllStatus[Crypto_182_iND13400_NUMBER_OF_NV_BLOCKS] ;
extern uint8 Global_uint8ErrSetNvmRamSts[Crypto_182_iND13400_NUMBER_OF_NV_BLOCKS];
extern uint8 Global_uint8ErrWriteNvmBlock[Crypto_182_iND13400_NUMBER_OF_NV_BLOCKS];
extern uint8 Global_uint8PendingNvmWrite[Crypto_182_iND13400_NUMBER_OF_NV_BLOCKS];
extern uint32 Global_uint32CryptoNvBlockFailedRetries[Crypto_182_iND13400_NUMBER_OF_NV_BLOCKS];
extern NvMBlockWriteStatus_t Global_uint32CryptoBlockWriteSts[Crypto_182_iND13400_NUMBER_OF_NV_BLOCKS];
 /*===========================================================================*
 * Local Functions
 *===========================================================================*/
 
 
 
#endif


