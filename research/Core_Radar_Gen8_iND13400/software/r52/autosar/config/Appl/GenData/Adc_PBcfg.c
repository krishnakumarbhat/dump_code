/*===========================================================================*//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/
 
/**
 * @Adc Post-build Cfg source
 *
 * @file 	 Adc_PBcfg.c
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
 * @ADC Adc Post-build configuration source file
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

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "Adc_Cfg.h" /* polyspace DEFECT:USELESS_INCLUDE "It is used by the module" */
#include "Adc_Types.h"
#include "Adc_PBcfg.h" /* polyspace DEFECT:USELESS_INCLUDE "It is used by the module" */
#include "Adc_UserCallouts.h" /* polyspace DEFECT:USELESS_INCLUDE "It is used bythe module" */
/*===========================================================================*
 * Local Preprocessor defined Constants
 *===========================================================================*/

/*===========================================================================*
 * Local Preprocessor defined MACROS
 *===========================================================================*/
//----[Defining literals of the numeric HW clock ]------
#define CLK_SYS ((uint8)0x00u)

//----[Defining literals of the numeric Id of the HW unit]------
#define AdcHwUnit_0 ((uint8)0x00u)

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

/*===========================================================================*
* Exported Function Prototypes
*===========================================================================*/

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/
#define ADC_START_SEC_CONFIG_DATA_POSTBUILD
#include "Adc_MemMap.h" /* polyspace MISRA-C-2023:20.1 "MemMap usage as per Autosar." */
//============[Channels definitions]========================
static Adc_ChannelConfigType AdcChannels[ADC_CONFIGURED_CHANNELS] =
{
	{
		.AdcChannelId          =  AdcConf_AdcChannel_BOARD_REV,
#if(STD_ON == ADC_ENABLE_LIMIT_CHECK)
		.AdcChannelLimitCheck  =  FALSE,
    	.AdcChannelHighLimit   =  4095u,
    	.AdcChannelLowLimit    =  0u,
    	.AdcChannelRangeSelect =  ADC_RANGE_ALWAYS,
#endif
    	.AdcChannelResolution  =  12u,
    	.AdcChannelSampTime    =  255u
	},
	{
		.AdcChannelId          =  AdcConf_AdcChannel_ADC_BATT,
#if(STD_ON == ADC_ENABLE_LIMIT_CHECK)
		.AdcChannelLimitCheck  =  FALSE,
    	.AdcChannelHighLimit   =  4095u,
    	.AdcChannelLowLimit    =  0u,
    	.AdcChannelRangeSelect =  ADC_RANGE_ALWAYS,
#endif
    	.AdcChannelResolution  =  12u,
    	.AdcChannelSampTime    =  255u
	},
	{
		.AdcChannelId          =  AdcConf_AdcChannel_ADC_POS_GND_A,
#if(STD_ON == ADC_ENABLE_LIMIT_CHECK)
		.AdcChannelLimitCheck  =  FALSE,
    	.AdcChannelHighLimit   =  4095u,
    	.AdcChannelLowLimit    =  0u,
    	.AdcChannelRangeSelect =  ADC_RANGE_ALWAYS,
#endif
    	.AdcChannelResolution  =  12u,
    	.AdcChannelSampTime    =  255u
	},
	{
		.AdcChannelId          =  AdcConf_AdcChannel_ADC_POS_GND_B,
#if(STD_ON == ADC_ENABLE_LIMIT_CHECK)
		.AdcChannelLimitCheck  =  FALSE,
    	.AdcChannelHighLimit   =  4095u,
    	.AdcChannelLowLimit    =  0u,
    	.AdcChannelRangeSelect =  ADC_RANGE_ALWAYS,
#endif
    	.AdcChannelResolution  =  12u,
    	.AdcChannelSampTime    =  255u
	},
	{
		.AdcChannelId          =  AdcConf_AdcChannel_ADC_IGN,
#if(STD_ON == ADC_ENABLE_LIMIT_CHECK)
		.AdcChannelLimitCheck  =  FALSE,
    	.AdcChannelHighLimit   =  4095u,
    	.AdcChannelLowLimit    =  0u,
    	.AdcChannelRangeSelect =  ADC_RANGE_ALWAYS,
#endif
    	.AdcChannelResolution  =  12u,
    	.AdcChannelSampTime    =  255u
	},
	{
		.AdcChannelId          =  AdcConf_AdcChannel_ADC_POS_GND_D,
#if(STD_ON == ADC_ENABLE_LIMIT_CHECK)
		.AdcChannelLimitCheck  =  FALSE,
    	.AdcChannelHighLimit   =  4095u,
    	.AdcChannelLowLimit    =  0u,
    	.AdcChannelRangeSelect =  ADC_RANGE_ALWAYS,
#endif
    	.AdcChannelResolution  =  12u,
    	.AdcChannelSampTime    =  255u
	},
	{
		.AdcChannelId          =  AdcConf_AdcChannel_ADC_BATT_I_SENSE,
#if(STD_ON == ADC_ENABLE_LIMIT_CHECK)
		.AdcChannelLimitCheck  =  FALSE,
    	.AdcChannelHighLimit   =  4095u,
    	.AdcChannelLowLimit    =  0u,
    	.AdcChannelRangeSelect =  ADC_RANGE_ALWAYS,
#endif
    	.AdcChannelResolution  =  12u,
    	.AdcChannelSampTime    =  255u
	},
	{
		.AdcChannelId          =  AdcConf_AdcChannel_ADC_RDI_DETECT,
#if(STD_ON == ADC_ENABLE_LIMIT_CHECK)
		.AdcChannelLimitCheck  =  FALSE,
    	.AdcChannelHighLimit   =  4095u,
    	.AdcChannelLowLimit    =  0u,
    	.AdcChannelRangeSelect =  ADC_RANGE_ALWAYS,
#endif
    	.AdcChannelResolution  =  12u,
    	.AdcChannelSampTime    =  255u
	},
	{
		.AdcChannelId          =  AdcConf_AdcChannel_ADC_POS_GND_C,
#if(STD_ON == ADC_ENABLE_LIMIT_CHECK)
		.AdcChannelLimitCheck  =  FALSE,
    	.AdcChannelHighLimit   =  4095u,
    	.AdcChannelLowLimit    =  0u,
    	.AdcChannelRangeSelect =  ADC_RANGE_ALWAYS,
#endif
    	.AdcChannelResolution  =  12u,
    	.AdcChannelSampTime    =  255u
	},
	{
		.AdcChannelId          =  AdcConf_AdcChannel_ADC_MCU_TEMP,
#if(STD_ON == ADC_ENABLE_LIMIT_CHECK)
		.AdcChannelLimitCheck  =  FALSE,
    	.AdcChannelHighLimit   =  4095u,
    	.AdcChannelLowLimit    =  0u,
    	.AdcChannelRangeSelect =  ADC_RANGE_ALWAYS,
#endif
    	.AdcChannelResolution  =  12u,
    	.AdcChannelSampTime    =  255u
	},
};

//============[Groups definitions]========================
static const Adc_ChannelConfigType *const AdcGroup0Channels[ADC_GROUP_0_NUMBER_OF_CHANNELS] =
{
    &AdcChannels[0],
    &AdcChannels[1],
    &AdcChannels[2],
    &AdcChannels[3],
    &AdcChannels[4],
    &AdcChannels[5],
    &AdcChannels[6],
    &AdcChannels[7],
    &AdcChannels[8],
    &AdcChannels[9],
};    

Adc_GroupStateType AdcGroupsState[ADC_CONFIGURED_GROUPS] =
{
	// parameters used to keep tracking of runtime information
	{
#if(STD_ON == ADC_ENABLE_LIMIT_CHECK)   
    	.Adc_GroupLimitCheck = ADC_GROUP_LIMIT_CHECK_UNDEFINED,
#endif
	    .Adc_NCompleted_ConversionRounds = 0u,
	    .Adc_NCompleted_ChannelsPerConversion = 0U,
	    .HighestChannelId = 0u,
	    .GroupStatus = ADC_IDLE,
	    .GroupBufferStatus = ADC_BUFFER_UNINITIALIZED,
	    .GroupBufferPtr = NULL_PTR,
	    .GroupNotificationStatus = ADC_NOTIFICATION_OFF,
	},
};

static Adc_GroupConfigType AdcGroups[ADC_CONFIGURED_GROUPS] =
{
	{
		.AdcGroupId             =  AdcConf_AdcGroup_AdcGroup,
    	.AdcGroupTriggSrc       =  ADC_TRIGG_SRC_SW,
    	.AdcGroupConversionMode =  ADC_CONV_MODE_CONTINUOUS,
    	.AdcGroupAccessMode     =  ADC_ACCESS_MODE_SINGLE,
    	.AdcStreamingBufferMode =  ADC_STREAM_BUFFER_LINEAR,
    	.AdcStreamingNumSamples =  1u,
    	.AdcGroupDefinition     = AdcGroup0Channels,
#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
	    .AdcNotification = &IoHwAb_AdcNotification,
#endif
        .Adc_Group_NChannels = ADC_GROUP_0_NUMBER_OF_CHANNELS,
	},
};
//============[HwUnits definitions]========================
static Adc_HwUnitType AdcHwUnitConfig [ADC_CONFIGURED_HW_UNITS] =
{
	{
	    .AdcHwUnitId = AdcHwUnit_0,
	    .AdcClockSource = CLK_SYS,
	    .AdcPrescale = 2u,
#if ((STD_ON == ADC_AHB_SAFETY_ENABLE) || (STD_ON == ADC_FUSA_SAFETY_ENABLE))
	    .AdcSafetyUserCallOut = NULL_PTR,
#endif
	    .AdcChannels = AdcChannels,
    	.AdcGroups = AdcGroups
   }
};

//============[Adc_Config definition]========================
const Adc_ConfigType Adc_Config = {
    .AdcHwUnits = AdcHwUnitConfig
};


#define ADC_STOP_SEC_CONFIG_DATA_POSTBUILD
#include "Adc_MemMap.h" /* polyspace MISRA-C-2023:20.1 "MemMap usage as per Autosar." */ /* polyspace DEFECT:USELESS_INCLUDE "MemmMap usage as per AUTOSAR" */

