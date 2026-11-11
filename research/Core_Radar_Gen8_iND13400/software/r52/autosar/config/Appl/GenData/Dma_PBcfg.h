/* VendorSpecifc File Header *//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

 
/*===========================================================================*/
/** 
 * @Dma PBCfg header file 
 *
 * @file 	 Dma_PBfg.h
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
 * @DMA DMA Post Build Configuration header file 
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

#ifndef DMA_PBCFG_H_
#define DMA_PBCFG_H_
/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "Dma_Cfg.h"
#include "Dma_Types.h"


#ifdef __cplusplus
extern "C"
{ /** Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */
/*===========================================================================*
* Exported Preprocessor #define Constants
*===========================================================================*/

/*===========================================================================*
* Exported Preprocessor functions MACROS
*===========================================================================*/

/*===========================================================================*
* Exported Type Declarations
*===========================================================================*/

/*===========================================================================*
* Exported Const Object Declarations
*===========================================================================*/
extern const Dma_ConfigType Dma_Config;

/*===========================================================================*
* Exported Function Prototypes
*===========================================================================*/
/* Function prototypes for DMA channels' callback functions */
extern void Channel1_EndNotification(void);
/*===========================================================================*
* Exported Inline Function Definitions and #define Function-Like Macros
*===========================================================================*/


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


#endif /* DMA_PBCFG_H_*/
