/*===========================================================================*//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

/**
 * @Adc Header file Adc_UserCallouts.h
 *
 * @file 	 Adc_UserCallouts.h
 * @Date     Generation Time:   2026-08-30 22:07:33
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
 * @ADC Provides constants, variable declarations and function prototypes for Adc_PBcfg.c
 *
 * @section TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @Specification of ADC Driver AUTOSAR CP Release 4.4.0
 *
 *   - Requirements Document(s):
 *     - @Requirements of ADC Driver AUTOSAR CP Release 4.4.0
 *
 *   - Applicable Standards:
 *     - @Autosar Classic Platform 4.4.0
 *
 * @section DEVIATIONS FROM STANDARDS:
 *   - @List of deviations from standards in this file, or "None".
 *
 */
/*===========================================================================*/
#ifndef ADC_USER_CALLOUTS_H_
#define ADC_USER_CALLOUTS_H_

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "Std_Types.h"

#ifdef __cplusplus
extern "C"
{      /** Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */
/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/
#define ADC_FUSA_CTRL_ERR_STORAGE       (0x01U)
#define ADC_FUSA_CTRL_ERR_ACCESS        (0x02U)
#define ADC_FUSA_CTRL_ERR_SWIF          (0x04U)
#define ADC_FUSA_CTRL_ERR_CTRL          (0x10U)

#define ADC_AHB_PARITY_ERROR            (0x08U)
#define ADC_AHB_ERROR_GENERAL           (0x20U)
#define ADC_AHB_ERROR_RETRY             (0x40U)
#define ADC_AHB_ERROR_SPLIT             (0x80U)
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

#endif /* ADC_USER_CALLOUTS_H_*/
