/*===========================================================================*//**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/
 
 /**
 * @Adc This file contains the configuration of the AUTOSAR module Adc.
 *
 * @file     Adc_Cfg.h
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
 * @ADC Pre-compile configuration parameters for ADC module
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
/*============[Adc_ResultAlignmentType DOCUMENTATION]=============================*/
/* Implemented as macro because it is used for conditional compilation */

/**
 * @def ADC_ALIGN_LEFT
 * @requirement SWS_Adc_00525
 * @brief Type for alignment of ADC raw results in ADC result buffer - Left alignment
 */
/**
 * @def ADC_ALIGN_RIGHT
 * @requirement SWS_Adc_00525
 * @brief Type for alignment of ADC raw results in ADC result buffer - Right alignment
 */

/*============[Adc_PriorityImplementationType DOCUMENTATION]=============================*/
/* Implemented as macro because it is used for conditional compilation */

/**
 * @def ADC_PRIORITY_NONE
 * @requirement SWS_Adc_00522
 * @brief Type for configuring the prioritization mechanism -
 * Priority mechanism is not available
 */
/**
 * @def ADC_PRIORITY_HW
 * @requirement SWS_Adc_00522
 * @brief Type for configuring the prioritization mechanism -
 * Hardware priority mechanism is available only
 */
/**
 * @def ADC_PRIORITY_HW_SW
 * @requirement SWS_Adc_00522
 * @brief Type for configuring the prioritization mechanism -
 * Hardware and software priority mechanism is available
 */

/*============[AdcGeneral Container DOCUMENTATION]=============================*/
/* Description: General configuration (parameters) of the ADC Driver Software module.
 * Requirements: ECUC_Adc_00027 */

/**
 * @def ADC_DE_INIT_API
 * @brief Adds/removes the service Adc_DeInit() from the code
 * - TRUE: Adc_DeInit() can be used
 * - FALSE: Adc_DeInit() can not be used
 * @requirement ECUC_Adc_00404
 */

/**
 * @def ADC_DEV_ERROR_DETECT
 * @brief Switches the development error detection and notification on or off
 * - TRUE: detection and notification is enabled
 * - FALSE: detection and notification is disabled
 * @requirement ECUC_Adc_00405
 */

/**
 * @def ADC_ENABLE_LIMIT_CHECK
 * @brief Enables or disables limit checking feature in the ADC driver
 * @requirement ECUC_Adc_00452
 */

/**
 * @def ADC_ENABLE_QUEUING
 * @brief Determines, if the queuing mechanism is active in case of priority mechanism disabled.
 * Note: If priority mechanism is enabled, queuing mechanism is always active and the parameter
 * ADC_ENABLE_QUEUING is not evaluated
 * - TRUE: Enabled
 * - FALSE: Disabled
 * - Dependency of ADC_PRIORITY_IMPLEMENTATION. AdcEnableQueuing is only evaluated
 * for priority implementation ADC_PRIORITY_NONE
 * @requirement ECUC_Adc_00391
 */

/**
 * @def ADC_ENABLE_START_STOP_GROUP_API
 * @brief Adds / removes the services Adc_StartGroupConversion() and Adc_StopGroupConversion() from the code
 * - TRUE: Adc_StartGroupConversion() and Adc_StopGroupConversion() can be used
 * - FALSE: Adc_StartGroupConversion() and Adc_StopGroupConversion() can not be used
 * @requirement ECUC_Adc_00406
 */

/**
 * @def ADC_GRP_NOTIF_CAPABILITY
 * @brief Determines, if the group notification mechanism (the functions to enable and disable the notifications) is available at runtime
 * - TRUE: Enabled
 * - FALSE: Disabled
 * @requirement ECUC_Adc_00105
 */

/**
 * @def ADC_PRIORITY_IMPLEMENTATION
 * @brief Determines whether a priority mechanism is available for prioritization of the conversion requests and if available,
 * the type of prioritization mechanism. The selection applies for groups with trigger source software and trigger source hardware.
 * @requirement ECUC_Adc_00393
 */

/**
 * @def ADC_READ_GROUP_API
 * @brief Adds / removes the service Adc_ReadGroup() from the code
 * - TRUE: Adc_ReadGroup() can be used
 * - FALSE: Adc_ReadGroup() can not be used
 * @requirement ECUC_Adc_00394
 */

/**
 * @def ADC_RESULT_ALIGNMENT
 * @brief Alignment of ADC raw results in ADC buffer (left/right alignment)
 * @requirement ECUC_Adc_00444
 */

/**
 * @def ADC_VERSION_INFO_API
 * @brief Adds / removes the service Adc_GetVersionInfo() from the code
 * - TRUE: Adc_GetVersionInfo() can be used
 * - FALSE: Adc_GetVersionInfo() can not be used
 * @requirement ECUC_Adc_00409
 */

/*============[PUBLISHED INFORMATION DOCUMENTATION]=============================*/
/**
 * @def ADC_CHANNEL_VALUE_SIGNED
 * @brief Information whether the result value of the ADC driver
 * has sign information (TRUE) or not (FALSE). If the result shall be interpreted
 * as signed value ot shall apply to C-language rules
 * @requirement ECUC_Adc_00410
 */

/**
 * @def ADC_GROUP_FIRST_CHANNEL_FIXED
 * @brief Information whether the first channel of an ADC channel group can be
 * configured (FALSE) or is fixed (TRUE) to a value determined by the ADC HW Unit
 * @requirement ECUC_Adc_00411
 */

/**
 * @def ADC_MAX_CHANNEL_RESOLUTION
 * @brief Maximum Channel resolution in bits (does not specify accuracy)
 * @requirement ECUC_Adc_00412
 */

/* ======================[AUTOGENERATED]===============================*/
#ifndef ADC_CFG_H_
#define ADC_CFG_H_

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "Std_Types.h" /* Requirement SWS_Adc_00364*/ /* polyspace DEFECT:USELESS_INCLUDE "It is used by the module" */

#ifdef __cplusplus
extern "C"
{      /** Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */
/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/

/**< ADC Driver Post-build Configuration Version Info */
#define ADC_CFG_MAJOR_VERSION (0x0Eu) /**< Adc Driver Configuration Major Version */
#define ADC_CFG_MINOR_VERSION (0x00u) /**< Adc Driver Configuration Minor Version */

#define ADC_ALIGN_LEFT (0x00u)
#define ADC_ALIGN_RIGHT (0x01u)

#define ADC_PRIORITY_NONE (0x00u)
#define ADC_PRIORITY_HW (0x01u)
#define ADC_PRIORITY_HW_SW (0x02u)

#define ADC_DE_INIT_API                                 (STD_ON)
#define ADC_DEV_ERROR_DETECT                            (STD_OFF)
#define ADC_ENABLE_LIMIT_CHECK                          (STD_ON)      
#define ADC_PRIORITY_IMPLEMENTATION						(ADC_PRIORITY_NONE)

#if (ADC_PRIORITY_NONE == ADC_PRIORITY_IMPLEMENTATION) 
#define ADC_ENABLE_QUEUING 								(STD_OFF) 
#else
#define ADC_ENABLE_QUEUING								(STD_ON)                  
#endif

#define ADC_ENABLE_START_STOP_GROUP_API                  (STD_ON)
#define ADC_GRP_NOTIF_CAPABILITY                         (STD_ON)
#define ADC_READ_GROUP_API                               (STD_ON)
#define ADC_RESULT_ALIGNMENT                             (ADC_ALIGN_RIGHT)       
#define ADC_VERSION_INFO_API                             (STD_ON)

/*===========================================================================*
 * ADC HW Buffer Configuration
 *===========================================================================*/

/* 
 * Offset (in bytes) inside the selected HW memory region where the ADC buffer starts.
 */
#define ADC_HW_BUFFER_OFFSET                             (0x00000000u)

/*
 * ADC HW buffer base address:
 * The buffer is located in a selected hardware memory region.
 * The final address is computed as:
 *
 *   Base address of selected memory (AdcHwMemoryAllocation) + configured offset (AdcHwMemoryOffset)
 *
 */
#define ADC_HW_BUFFER_BASE_ADDRESS                      (ARTIE_MEM_base + ADC_HW_BUFFER_OFFSET) /* polyspace MISRA-C-2023:2.2 "Used in Adc driver implementation" */


#define ADC_BUILT_IN_TEST_API                 			 (STD_ON)
#define ADC_BUILT_IN_TEST_INIT_ENABLE                 	 (STD_OFF)
#define ADC_OFFSET_CORRECTION_SEQUENCE_ENABLE            (STD_ON)
#define ADC_FUSA_SAFETY_ENABLE							 (STD_OFF)
#define ADC_AHB_SAFETY_ENABLE							 (STD_OFF)


#define ADC_ACCESSIBLE_APPS_NUM             (0U) /** Specifies the number of authorized OS applications */

/*===========================================================================*
 * ADC OS ISR Configuration
 *===========================================================================*/
/**
 * @def   ADC_OS_ISR_CATEGORY_1
 * @brief OS Category 1 ISR selector.
 */
#define ADC_OS_ISR_CATEGORY_1                    (1U)

/**
 * @def   ADC_OS_ISR_CATEGORY_2
 * @brief OS Category 2 ISR selector.
 */
#define ADC_OS_ISR_CATEGORY_2                    (2U)

/**
 * @def   ADC_GPADC_OS_ISR_CATEGORY
 * @brief Configured OS ISR category for the GP-ADC conversion interrupt.
 */
#define ADC_GPADC_OS_ISR_CATEGORY                (ADC_OS_ISR_CATEGORY_2)

/**
 * @def   ADC_GPADC_OS_ISR_SPECIAL_FUNCTION_NAME
 * @brief OS ISR special function name configured for the GP-ADC conversion interrupt.
 */
#define ADC_GPADC_OS_ISR_SPECIAL_FUNCTION_NAME   GPADC_Handler

/**
 * @def   ADC_FUSA_OS_ISR_CATEGORY
 * @brief Configured OS ISR category for the ADC Control FuSa error interrupt.
 */
#define ADC_FUSA_OS_ISR_CATEGORY                 (ADC_OS_ISR_CATEGORY_2)

/**
 * @def   ADC_FUSA_OS_ISR_SPECIAL_FUNCTION_NAME
 * @brief OS ISR special function name configured for the ADC Control FuSa error interrupt.
 */
#define ADC_FUSA_OS_ISR_SPECIAL_FUNCTION_NAME    ADC_CTRL_ERR_FUSA_Handler

/*---------------[published information]-----------------*/
#define ADC_CHANNEL_VALUE_SIGNED                         (STD_OFF)
#define ADC_GROUP_FIRST_CHANNEL_FIXED                    (STD_OFF)
#define ADC_MAX_CHANNEL_RESOLUTION                       (12u)

/*---------------------[Symbolic names of the groups]------------------------*/
/*-----------------[These names will be used by the API]---------------------*/

//definition derived from the shortName of the group ECUC_Adc_00398.
#define AdcConf_AdcGroup_AdcGroup (0u)

// Symbolic name for the ADC channel
#define AdcConf_AdcChannel_BOARD_REV (0u)
#define AdcConf_AdcChannel_ADC_BATT (1u)
#define AdcConf_AdcChannel_ADC_POS_GND_A (2u)
#define AdcConf_AdcChannel_ADC_POS_GND_B (3u)
#define AdcConf_AdcChannel_ADC_IGN (4u)
#define AdcConf_AdcChannel_ADC_POS_GND_D (5u)
#define AdcConf_AdcChannel_ADC_BATT_I_SENSE (6u)
#define AdcConf_AdcChannel_ADC_RDI_DETECT (7u)
#define AdcConf_AdcChannel_ADC_POS_GND_C (8u)
#define AdcConf_AdcChannel_ADC_MCU_TEMP (9u)

/*---------------------[Info needed by the post build configurations]------------------------*/

#define ADC_CONFIGURED_GROUPS    1u
#define ADC_CONFIGURED_CHANNELS  10u
#define ADC_CONFIGURED_HW_UNITS  1u
#define ADC_GROUP_0_NUMBER_OF_CHANNELS  10u

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* ADC_CFG_H_*/

