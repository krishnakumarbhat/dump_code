/*===========================================================================*//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

/**
 * @PWM PWM PBcfg source file
 *
 * @file 	 Pwm_PBcfg.c
 * @Date     Generation Time:   2026-08-26 22:51:47
 * @Project  Project:   Gen8_iND13400 - Version 1.0
 *
 * @section DESCRIPTION:
 *
 * @Pwm configuration source file
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
 * @PWM Abstraction Layer Post Build Configuration PWM source file
 *
 * @section TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @Specification of PWM Driver AUTOSAR CP Release 4.4.0
 *
 *   - Requirements Document(s):
 *     - @Specification of PWM Driver AUTOSAR CP Release 4.4.0
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

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "Pwm_Cfg.h" 
#include "Pwm_Types.h" 
#include "Pwm_PBcfg.h" /* polyspace DEFECT:USELESS_INCLUDE "It is used by the module" */

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/
#define PWM_START_SEC_CONFIG_DATA_POSTBUILD
#include "Pwm_MemMap.h"

/**< Channels Configuration */
static const PWM_DDS_ChannelConfigType PwmDDSChannelConfig[PWM_NUMBER_CONF_DDS_CHANNELS] =
{
	{
		.DDSDutycycle = 0x1000u,
        .DDSDitherStep = 0x0200u,
        .DDSDitherUpdateInterval = 0x0200u,
        .RampUpdateTimerEnable = STD_ON,
        .Ramp0StartFrequency = 0x0010u,
        .Ramp0Step = 0x0001,
        .Ramp0UpdateInterval = 0x0200u,
        .Ramp0MaxStepCount = 0x0200u,
        .Ramp1StartFrequency = 0x00F0u,
        .Ramp1Step = 0x0001,
        .Ramp1UpdateInterval = 0x0200u,
        .Ramp1MaxStepCount = 0x0200u,
        .DDSEocExternalTriggerEnable = STD_OFF,
        .DDSEocExternalSource = PWM_EOC_SOURCE_MIPI,
        .DDSEocLIM = 0x01u,
        .DDSEofExternalTriggerEnable = STD_OFF,
        .DDSEofExternalSource = PWM_EOF_SOURCE_MIPI,
        .DDSEofLIM = 0x01u,
        .Prescaler = PWM_PRESCALER_DIV_1,
	},
	{
		.DDSDutycycle = 0xFFFFu,
        .DDSDitherStep = 0x0000u,
        .DDSDitherUpdateInterval = 0x0000u,
        .RampUpdateTimerEnable = STD_ON,
        .Ramp0StartFrequency = 0x0010u,
        .Ramp0Step = 0x0001,
        .Ramp0UpdateInterval = 0x0200u,
        .Ramp0MaxStepCount = 0x000Au,
        .Ramp1StartFrequency = 0x00F0u,
        .Ramp1Step = 0x0001,
        .Ramp1UpdateInterval = 0x0200u,
        .Ramp1MaxStepCount = 0x000Au,
        .DDSEocExternalTriggerEnable = STD_OFF,
        .DDSEocExternalSource = PWM_EOC_SOURCE_MIPI,
        .DDSEocLIM = 0x01u,
        .DDSEofExternalTriggerEnable = STD_OFF,
        .DDSEofExternalSource = PWM_EOF_SOURCE_MIPI,
        .DDSEofLIM = 0x01u,
        .Prescaler = PWM_PRESCALER_DIV_1,
	},
};

static const PWM_AR_ChannelConfigType PwmARChannelConfig[PWM_NUMBER_CONF_AR_CHANNELS] =
{
	{
		.DutycycleDefault = 0x4000u,
        .PeriodDefault = 0x0C35u,
        .IdleState = PWM_LOW,
        .Polarity = PWM_HIGH,
        .SlopeStep = 0x00FFu,
        .SlopeMinPeriod = 0x00001000u,
        .SlopeMaxPeriod = 0x00008000u,
        .DitherEnable = STD_OFF,
        .DitherStep = 0x0Fu,
        .StaircaseEocEnable = STD_OFF,
        .StaircaseEocCount = 0x0Fu,
        .StaircaseEocMask = PWM_EOC_MASKED_BLOCKS_EXT_TRIGGER,
        .StaircaseEofMask = PWM_EOF_MASKED_BLOCKS_EXT_TRIGGER,
        .StaircaseEocExternalSource = PWM_EOC_SOURCE_MIPI,
        .StaircaseEocLIM = 0x01u,
        .StaircaseEofExternalSource = PWM_EOF_SOURCE_MIPI,
        .StaircaseEofLIM = 0x01u,
	},
	{
		.DutycycleDefault = 0x4000u,
        .PeriodDefault = 0x0BB8u,
        .IdleState = PWM_LOW,
        .Polarity = PWM_HIGH,
        .SlopeStep = 0x0064u,
        .SlopeMinPeriod = 0x000005DCu,
        .SlopeMaxPeriod = 0x00000BB8u,
        .DitherEnable = STD_OFF,
        .DitherStep = 0x00u,
        .StaircaseEocEnable = STD_OFF,
        .StaircaseEocCount = 0x00u,
        .StaircaseEocMask = PWM_EOC_MASKED_BLOCKS_EXT_TRIGGER,
        .StaircaseEofMask = PWM_EOF_MASKED_BLOCKS_EXT_TRIGGER,
        .StaircaseEocExternalSource = PWM_EOC_SOURCE_MIPI,
        .StaircaseEocLIM = 0x01u,
        .StaircaseEofExternalSource = PWM_EOF_SOURCE_MIPI,
        .StaircaseEofLIM = 0x01u,
	},
};

static const Pwm_ChannelConfigType PwmChannelConfig[PWM_NUMBER_CONF_CHANNEL] =
{
    {
        .ChannelClass = PWM_DDS_MODE,
        .ChannelId = 0x00u,
        .ChannelPrescaler = PWM_PRESCALER_DIV_1,
        .ChannelARConfig = NULL_PTR,
        .ChannelDDSConfig = &PwmDDSChannelConfig[0],
    },
    {
        .ChannelClass = PWM_DDS_MODE,
        .ChannelId = 0x01u,
        .ChannelPrescaler = PWM_PRESCALER_DIV_1,
        .ChannelARConfig = NULL_PTR,
        .ChannelDDSConfig = &PwmDDSChannelConfig[1],
    },
	{
		.ChannelClass = PWM_FIXED_PERIOD,
        .ChannelId = 0x02u,
        .ChannelPrescaler = PWM_PRESCALER_DIV_8,
        .ChannelARConfig = &PwmARChannelConfig[0],
        .ChannelDDSConfig = NULL_PTR,
	},
	{
		.ChannelClass = PWM_CONTINUOUS_MODE,
        .ChannelId = 0x03u,
        .ChannelPrescaler = PWM_PRESCALER_DIV_1,
        .ChannelARConfig = &PwmARChannelConfig[1],
        .ChannelDDSConfig = NULL_PTR,
	},
};

const Pwm_ConfigType Pwm_Config = {PwmChannelConfig};


#define PWM_STOP_SEC_CONFIG_DATA_POSTBUILD
#include "Pwm_MemMap.h" /* polyspace MISRA-C-2023:20.1 "Memmap header usage as per Autosar." */  /* polyspace DEFECT:USELESS_INCLUDE "MemMap usage as per Autosar." */


