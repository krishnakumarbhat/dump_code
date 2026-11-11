/*===========================================================================*//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

/**
 * @Adc Header file of Adc_PBcfg.c
 *
 * @file 	 Adc_PBcfg.h
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
#ifndef ADC_PBCFG_H_
#define ADC_PBCFG_H_

/*===========================================================================*
 * Header Files
 *===========================================================================*/


#ifdef __cplusplus
extern "C"
{      /** Inclusion of header files should NOT be inside the extern "C" block */
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
 /* ADC Configuration struct declaration */
extern const Adc_ConfigType Adc_Config; /**< This container contains the configuration parameters and sub containers of the AUTOSAR Adc module*/
extern Adc_GroupStateType AdcGroupsState[ADC_CONFIGURED_GROUPS];


/*===========================================================================*
 * Exported Function Prototypes
 *===========================================================================*/
extern void IoHwAb_AdcNotification(void);
/*===========================================================================*
 * Exported Inline Function Definitions and #define Function-Like Macros
 *===========================================================================*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* ADC_PBCFG_H_*/
