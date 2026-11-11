/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

/**
 * @PWM Header file Pwm_UserCallouts.h
 *
 * @file 	 Pwm_UserCallouts.h
 * @Date     Generation Time:   2026-08-26 22:51:47
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
 * @PWM Include declaration of user callout functions triggered by PWM safety events
 *
 * @section TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @Specification of PWM Driver AUTOSAR CP Release 4.4.0
 *
 *   - Requirements Document(s):
 *     - @Requirements of PWM Driver AUTOSAR CP Release 4.4.0
 *
 *   - Applicable Standards:
 *     - @Autosar Classic Platform 4.4.0
 *
 * @section DEVIATIONS FROM STANDARDS:
 *   - @List of deviations from standards in this file, or "None".
 *
 * @section Maybe Changed By the User: NO
 */
/*===========================================================================*/
#ifndef PWM_USER_CALLOUTS_H_
#define PWM_USER_CALLOUTS_H_

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
 * PWM FUSA Error Bit Definitions (per channel)
 *===========================================================================*/
/**
 * @brief Individual error flags inside each 8-bit channel error mask
 *
 * These flags indicate specific fault conditions detected by the PWM FUSA logic.
 * Multiple bits can be set simultaneously.
 */
#define PWM_FUSA_CTRL_ERR_STORAGE           (1U << 0U)
#define PWM_FUSA_CTRL_ERR_ACCESS            (1U << 1U)
#define PWM_FUSA_CTRL_ERR_SWIF              (1U << 2U)
#define PWM_FUSA_CTRL_ERR_CTRL              (1U << 4U)

/*===========================================================================*
 * Exported Function Prototypes
 *===========================================================================*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* PWM_USER_CALLOUTS_H_*/

