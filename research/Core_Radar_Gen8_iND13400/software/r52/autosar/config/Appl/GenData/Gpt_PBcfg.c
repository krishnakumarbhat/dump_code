/*===========================================================================*//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/
/*===========================================================================*/
/**
 * @Gpt PBcfg source 
 *
 * @file     Gpt_PBcfg.c
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
 * @GPT Mcal Gpt PBcfg source file
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

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "Gpt_Cfg.h"
#include "Gpt_Types.h"

/*===========================================================================*
 * External Function Declarations
 *===========================================================================*/
extern void Radar_Trigger_Timer_ISR(void);     /* polyspace MISRA-C-2023:8.5 [Not a defect:Low] "it is declared only once here" */
extern void Free_Running_Timer_Notification(void);     /* polyspace MISRA-C-2023:8.5 [Not a defect:Low] "it is declared only once here" */

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/
#define GPT_START_SEC_CONFIG_DATA_POSTBUILD
#include "Gpt_MemMap.h"


/**
 * @brief    GPT channel configuration table (Post-Build).
 * @details  One entry per configured GPT channel.
 */
STATIC CONST(Gpt_ChannelConfigurationType, GPT_CODE) Gpt_ChannelGroupCfg[GPT_CONFIGURED_CHANNEL_COUNT] =
{
    {
        .GptChannelId            = 0u,
        .GptChannelMode          = GPT_CH_MODE_CONTINUOUS,
        .GptChannelTickFrequency = (Gpt_TickFreqType)1.0E8,
        .GptChannelTickValueMax  = 4294967295u,
        .GptNotification         = NULL_PTR
    },
    {
        .GptChannelId            = 1u,
        .GptChannelMode          = GPT_CH_MODE_CONTINUOUS,
        .GptChannelTickFrequency = (Gpt_TickFreqType)1.0E8,
        .GptChannelTickValueMax  = 4294967295u,
        .GptNotification         = &Radar_Trigger_Timer_ISR
    },
    {
        .GptChannelId            = 2u,
        .GptChannelMode          = GPT_CH_MODE_CONTINUOUS,
        .GptChannelTickFrequency = (Gpt_TickFreqType)1.0E8,
        .GptChannelTickValueMax  = 4294967295u,
        .GptNotification         = &Free_Running_Timer_Notification
    },
    {
        .GptChannelId            = 3u,
        .GptChannelMode          = GPT_CH_MODE_CONTINUOUS,
        .GptChannelTickFrequency = (Gpt_TickFreqType)2.5E8,
        .GptChannelTickValueMax  = 4294967295u,
        .GptNotification         = NULL_PTR
    },
    {
        .GptChannelId            = 4u,
        .GptChannelMode          = GPT_CH_MODE_CONTINUOUS,
        .GptChannelTickFrequency = (Gpt_TickFreqType)2.5E8,
        .GptChannelTickValueMax  = 4294967295u,
        .GptNotification         = NULL_PTR
    },
};

/**
 * @brief    Top-level GPT driver Post-Build configuration.
 */
CONST(Gpt_ConfigType, GPT_CODE) Gpt_Config =        /* polyspace MISRA-C-2023:8.4 [Not a defect:Low] "The extern is already available in Gpt_PbCfg.h" */
{
    .ChannelConfigList   = Gpt_ChannelGroupCfg,
    .InitialDriverMode   = GPT_MODE_NORMAL,
    .NumberOfGptChannels = GPT_CONFIGURED_CHANNEL_COUNT
};

#define GPT_STOP_SEC_CONFIG_DATA_POSTBUILD
#include "Gpt_MemMap.h"     /* polyspace DEFECT:USELESS_INCLUDE [Not a defect:Low] "Needed for Autosar Memory mapping " */ /* polyspace MISRA-C-2023:20.1 [Not a defect:Low] "Needed for Autosar Memory mapping" */

