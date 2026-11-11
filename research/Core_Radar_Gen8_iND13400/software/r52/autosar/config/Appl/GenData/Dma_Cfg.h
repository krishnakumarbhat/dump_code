/* VendorSpecifc File Header *//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

 
/*===========================================================================*/
/**
 * @DMA Configuration Header File 
 *
 * @file 	 Dma_Cfg.h
 * @Date     Generation Time:   2026-08-26 20:55:48
 * @Project  Project:   Gen8_iND13400 - Version 1.0
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (c) indie Semiconductor 2025. All rights reserved.
 *
 * Information within this file is indie Semiconductor confidential and proprietary. 
 * 
 *------------------------------------------------------------------------------
 *
 * @section FULL DESCRIPTION:
 *
 * @DMA Configuration file for the Microcontroller Abstraction Layer (MCAL) for DMA (Direct Memory Access).
 *
 * @section TRACEABILITY INFO:
 *   - Design Document(s):
 *     - 
 *
 *   - Requirements Document(s):
 *     -
 *
 *   - Applicable Standards:
 *     -
 *
 * @section DEVIATIONS FROM STANDARDS:
 *   - @List of deviations from standards in this file, or "None".
 *
 */
/*===========================================================================*/
#ifndef DMA_CFG_H_
#define DMA_CFG_H_

/*===========================================================================*
 * Header Files
 *===========================================================================*/

#ifdef __cplusplus
extern "C"
{ /** Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */
/*===========================================================================*
* Exported Preprocessor #define Constants
*===========================================================================*/

/**< DMA Configuration Version*/
#define DMA_CFG_MAJOR_VERSION              	(5U)      
#define DMA_CFG_MINOR_VERSION              	(1U)

/**< DMA MAX channels configured*/
#define CHANNEL_CONFIGURED_NUM_MAX           1

#define DMA_DEV_ERROR_DETECT                 STD_OFF
#define DMA_DEM_ERROR_REPORT                 STD_OFF
#define DMA_RETRANSFER_ON_FAILURE            STD_ON

#define DMA_VERSION_INFO_API                 STD_ON 
#define DMA_CH_TRANSFER_SUSPEND_API          STD_ON 
#define DMA_CH_TRANSFER_ABORT_API            STD_ON

/**
 * @def             DMA_OS_ISR_CATEGORY_1
 * @requirements    None
 * @brief           OS Category 1 ISR selector.
 */
#define DMA_OS_ISR_CATEGORY_1                  (1U)

/**
 * @def             DMA_OS_ISR_CATEGORY_2
 * @requirements    None
 * @brief           OS Category 2 ISR selector.
 */
#define DMA_OS_ISR_CATEGORY_2                  (2U)

/**
 * @def             DMA_OS_ISR_CATEGORY
 * @requirements    None
 * @brief           Configured OS ISR category for the DMA interrupt.
 */
#define DMA_OS_ISR_CATEGORY                    (DMA_OS_ISR_CATEGORY_2)

/**
 * @def             DMA_OS_ISR_SPECIAL_FUNCTION_NAME
 * @requirements    None
 * @brief           OS ISR special function name configured for the DMA interrupt.
 */
#define DMA_OS_ISR_SPECIAL_FUNCTION_NAME       MCDMA_Handler

/*===========================================================================*
* Exported Preprocessor functions MACROS
*===========================================================================*/

/*===========================================================================*
* Exported Type Declarations
*===========================================================================*/

/*===========================================================================*
* Exported Const Object Declarations
*===========================================================================*/

/*===========================================================================*
* Exported Function Prototypes
*===========================================================================*/

/*===========================================================================*
* Exported Inline Function Definitions and #define Function-Like Macros
*===========================================================================*/


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


#endif /* DMA_CFG_H_*/
