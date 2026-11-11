/*===========================================================================*//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/
/*===========================================================================*/
/** 
 * @Gpt Cfg header
 *
 * @file     Gpt_Cfg.h
 * @Date     Generation Time:   2026-08-27 18:10:19
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
 * @GPT Mcal Gpt Cfg header file 
 *
 * @section TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @Specification of GPT Driver AUTOSAR CP Release 4.4.0
 *
 *   - Requirements Document(s):
 *     - @Requirements of GPT Driver AUTOSAR CP Release 4.4.0
 *
 *   - Applicable Standards:
 *     - @Autosar Classic Platform 4.4.0
 *
 * @section DEVIATIONS FROM STANDARDS:
 *   - @List of deviations from standards in this file, or "None".
 *
 */
/*===========================================================================*/
#ifndef GPT_CFG_H
#define GPT_CFG_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/

/* Configuration version information */
#define GPT_CFG_MAJOR_VERSION                   (6U)
#define GPT_CFG_MINOR_VERSION                   (2U)

/* Driver instance identifier */
#define GPT_INSTANCE_ID                         (0x00U)

/* Pre-compile time configurable API options */
#define GPT_DEV_ERROR_DETECT                    STD_OFF
#define GPT_VERSION_INFO_API                    STD_OFF
#define GPT_DEINIT_API                          STD_ON
#define GPT_TIME_ELAPSED_API                    STD_ON
#define GPT_TIME_REMAINING_API                  STD_ON
#define GPT_ENABLE_DISABLE_NOTIFICATION_API     STD_ON

/* Initialization check and channel count */
#define GPT_ENABLE_INIT_CHECK                   (STD_ON)
#define GPT_CONFIGURED_CHANNEL_COUNT            (5U)

/* Number of OS applications allowed to access GPT */
#define GPT_ACCESSIBLE_APPS_NUM                 (0U)

/*===========================================================================*
 * Symbolic Name Definitions
 *===========================================================================*/

/* Logical GPT channel indices (0 .. N-1) */
#define GptConf_GptChannelConfiguration_StbM_Local_Timer_Ch    (0U)
#define GptConf_GptChannelConfiguration_Radar_Trigger_Timer_Ch    (1U)
#define GptConf_GptChannelConfiguration_Free_Running_Timer_Ch    (2U)
#define GptConf_GptChannelConfiguration_PlatformTimer    (3U)
#define GptConf_GptChannelConfiguration_RTM_Timer_Ch    (4U)

/* Hardware timer channel aliases */
#define GPT_CHANNEL_00                         GptConf_GptChannelConfiguration_StbM_Local_Timer_Ch
#define GPT_CHANNEL_01                         GptConf_GptChannelConfiguration_Radar_Trigger_Timer_Ch
#define GPT_CHANNEL_02                         GptConf_GptChannelConfiguration_Free_Running_Timer_Ch
#define GPT_CHANNEL_03                         GptConf_GptChannelConfiguration_PlatformTimer
#define GPT_CHANNEL_04                         GptConf_GptChannelConfiguration_RTM_Timer_Ch

/* OS interrupt categories */
#define GPT_OS_ISR_CATEGORY_1                  (1U)
#define GPT_OS_ISR_CATEGORY_2                  (2U)

/* Per-channel OS interrupt configuration */
#define GPT_CHANNEL_00_OS_ISR_CATEGORY         (GPT_OS_ISR_CATEGORY_2)
#define GPT_CHANNEL_00_OS_ISR_SPECIAL_FUNCTION_NAME  TIMER1_Handler
#define GPT_CHANNEL_01_OS_ISR_CATEGORY         (GPT_OS_ISR_CATEGORY_2)
#define GPT_CHANNEL_01_OS_ISR_SPECIAL_FUNCTION_NAME  TIMER2_Handler
#define GPT_CHANNEL_02_OS_ISR_CATEGORY         (GPT_OS_ISR_CATEGORY_2)
#define GPT_CHANNEL_02_OS_ISR_SPECIAL_FUNCTION_NAME  TIMER3_Handler
#define GPT_CHANNEL_03_OS_ISR_CATEGORY         (GPT_OS_ISR_CATEGORY_2)
#define GPT_CHANNEL_03_OS_ISR_SPECIAL_FUNCTION_NAME  TIMER4_Handler
#define GPT_CHANNEL_04_OS_ISR_CATEGORY         (GPT_OS_ISR_CATEGORY_2)
#define GPT_CHANNEL_04_OS_ISR_SPECIAL_FUNCTION_NAME  TIMER5_Handler

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* GPT_CFG_H */

/*===========================================================================*
 * END OF FILE: Gpt_Cfg.h
 *===========================================================================*/

