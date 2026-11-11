/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_SWC_PLT_CDD_XCP_Type.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application types header file for SW-C <SWC_PLT_CDD_XCP>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PLT_CDD_XCP_TYPE_H
# define RTE_SWC_PLT_CDD_XCP_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef OFF
#   define OFF (0U)
#  endif

#  ifndef AUTOALIGNMENT
#   define AUTOALIGNMENT (1U)
#  endif

#  ifndef SHORT_TRACK_ALIGNMENT
#   define SHORT_TRACK_ALIGNMENT (2U)
#  endif

#  ifndef SERVICE_ALIGNMEMT
#   define SERVICE_ALIGNMEMT (3U)
#  endif

#  ifndef STATIC_ALIGNMENT
#   define STATIC_ALIGNMENT (4U)
#  endif
#  ifndef FORCE_OFF
#   define FORCE_OFF (0U)
#  endif

#  ifndef FORCE_ON
#   define FORCE_ON (1U)
#  endif

#  ifndef NO_FORCE
#   define NO_FORCE (2U)
#  endif
#  ifndef RESERVED_01
#   define RESERVED_01 (1U)
#  endif

#  ifndef RESERVED_02
#   define RESERVED_02 (2U)
#  endif

#  ifndef RESERVED_03
#   define RESERVED_03 (3U)
#  endif

#  ifndef RESERVED_04
#   define RESERVED_04 (4U)
#  endif

#  ifndef RESERVED_05
#   define RESERVED_05 (5U)
#  endif

#  ifndef RESERVED_06
#   define RESERVED_06 (6U)
#  endif

#  ifndef RESERVED_07
#   define RESERVED_07 (7U)
#  endif

#  ifndef FEATURE_FUNCTIONS_ACSF_OUTPUT_BYPASS
#   define FEATURE_FUNCTIONS_ACSF_OUTPUT_BYPASS (8U)
#  endif

#  ifndef DSP_SIMULATE_DETECTION
#   define DSP_SIMULATE_DETECTION (9U)
#  endif

#  ifndef BLOCKAGE_WRAPPER_OUTPUT_BYPASS
#   define BLOCKAGE_WRAPPER_OUTPUT_BYPASS (10U)
#  endif

#  ifndef DOWN_SELECT_OBJECT_OUTPUT_BYPASS
#   define DOWN_SELECT_OBJECT_OUTPUT_BYPASS (11U)
#  endif

#  ifndef ALIGN_WRAPPER_OUTPUT_BYPASS
#   define ALIGN_WRAPPER_OUTPUT_BYPASS (12U)
#  endif

#  ifndef RSDS_TRACKER_ALGORITHM_BYPASS
#   define RSDS_TRACKER_ALGORITHM_BYPASS (13U)
#  endif

#  ifndef YAW_RATE_PROCESSING_OUTPUT_BYPASS
#   define YAW_RATE_PROCESSING_OUTPUT_BYPASS (14U)
#  endif

#  ifndef MNR_BLOCKAGE_OUTPUT_BYPASS
#   define MNR_BLOCKAGE_OUTPUT_BYPASS (15U)
#  endif

#  ifndef ANGLE_DETECTION_ALGORITHM_BYPASS
#   define ANGLE_DETECTION_ALGORITHM_BYPASS (16U)
#  endif

#  ifndef FEATURE_FUNCTIONS_VISOB_OUTPUT_BYPASS
#   define FEATURE_FUNCTIONS_VISOB_OUTPUT_BYPASS (17U)
#  endif

#  ifndef FEATURE_FUNCTIONS_ABA_INPUT_BYPASS
#   define FEATURE_FUNCTIONS_ABA_INPUT_BYPASS (17U)
#  endif

#  ifndef XCP_TRACKER_OUTPUT
#   define XCP_TRACKER_OUTPUT (18U)
#  endif

#  ifndef FEATURE_FUNCTIONS_ABA_OUTPUT_BYPASS
#   define FEATURE_FUNCTIONS_ABA_OUTPUT_BYPASS (19U)
#  endif

#  ifndef FEATURE_FUNCTIONS_ASW_OUTPUT_BYPASS
#   define FEATURE_FUNCTIONS_ASW_OUTPUT_BYPASS (20U)
#  endif

#  ifndef FEATURE_FUNCTIONS_FENCES_OUTPUT_BYPASS
#   define FEATURE_FUNCTIONS_FENCES_OUTPUT_BYPASS (21U)
#  endif

#  ifndef FEATURE_FUNCTIONS_RECW_OUTPUT_BYPASS
#   define FEATURE_FUNCTIONS_RECW_OUTPUT_BYPASS (22U)
#  endif

#  ifndef FEATURE_FUNCTIONS_LCDA_OUTPUT_BYPASS
#   define FEATURE_FUNCTIONS_LCDA_OUTPUT_BYPASS (23U)
#  endif

#  ifndef FEATURE_FUNCTIONS_CTA_OUTPUT_BYPASS
#   define FEATURE_FUNCTIONS_CTA_OUTPUT_BYPASS (24U)
#  endif

#  ifndef FEATURE_FUNCTIONS_OH_OUTPUT_BYPASS
#   define FEATURE_FUNCTIONS_OH_OUTPUT_BYPASS (25U)
#  endif

#  ifndef FEATURE_FUNCTIONS_TRACKER_OUTPUT_BYPASS
#   define FEATURE_FUNCTIONS_TRACKER_OUTPUT_BYPASS (26U)
#  endif

#  ifndef IGNORE_D2A_IPC_DATA
#   define IGNORE_D2A_IPC_DATA (27U)
#  endif

#  ifndef IGNORE_H2A_IPC_DATA
#   define IGNORE_H2A_IPC_DATA (28U)
#  endif

#  ifndef A2D_TO_IPC_BUFFER_BYPASS
#   define A2D_TO_IPC_BUFFER_BYPASS (28U)
#  endif

#  ifndef A2H_TO_IPC_BUFFER_BYPASS
#   define A2H_TO_IPC_BUFFER_BYPASS (29U)
#  endif
#  ifndef Enable
#   define Enable (170U)
#  endif

#  ifndef Disable
#   define Disable (85U)
#  endif
#  ifndef IMMEDIATE_TEMPERATURES_KELVIN
#   define IMMEDIATE_TEMPERATURES_KELVIN (0U)
#  endif

#  ifndef AVERAGE_TEMPERATURES_KELVIN
#   define AVERAGE_TEMPERATURES_KELVIN (1U)
#  endif

#  ifndef IMMEDIATE_TEMPERATURES_CELCIUS
#   define IMMEDIATE_TEMPERATURES_CELCIUS (2U)
#  endif

#  ifndef AVERAGE_TEMPERATURES_CELCIUS
#   define AVERAGE_TEMPERATURES_CELCIUS (3U)
#  endif

#  ifndef IMMEDIATE_TEMPERATURES_FAHRENHEIT
#   define IMMEDIATE_TEMPERATURES_FAHRENHEIT (4U)
#  endif

#  ifndef AVERAGE_TEMPERATURES_FAHRENHEIT
#   define AVERAGE_TEMPERATURES_FAHRENHEIT (5U)
#  endif
#  ifndef XCP_ERASE_KAM
#   define XCP_ERASE_KAM (1U)
#  endif

#  ifndef XCP_SET_KAM_DEFAULT
#   define XCP_SET_KAM_DEFAULT (2U)
#  endif

#  ifndef XCP_ERASE_kAM_AND_SET_KAM_DEFAULT
#   define XCP_ERASE_kAM_AND_SET_KAM_DEFAULT (3U)
#  endif

#  ifndef XCP_SAVE_RAM_TO_KAM
#   define XCP_SAVE_RAM_TO_KAM (4U)
#  endif

#  ifndef XCP_VERIFY_KAM_STATUS
#   define XCP_VERIFY_KAM_STATUS (5U)
#  endif

#  ifndef XCP_ERASE_KAM_BLOCKS
#   define XCP_ERASE_KAM_BLOCKS (6U)
#  endif
#  ifndef XCP_DI_SIM
#   define XCP_DI_SIM (1U)
#  endif

#  ifndef XCP_EN_SIM
#   define XCP_EN_SIM (2U)
#  endif

#  ifndef XCP_EN_ITV_SIM_MAX_MODE
#   define XCP_EN_ITV_SIM_MAX_MODE (3U)
#  endif

#  ifndef XCP_EN_ITV_SIM_MIN_MODE
#   define XCP_EN_ITV_SIM_MIN_MODE (4U)
#  endif
#  ifndef XCP_NVM_STATUS_PENDING
#   define XCP_NVM_STATUS_PENDING (1U)
#  endif

#  ifndef XCP_NVM_STATUS_SUCCESS
#   define XCP_NVM_STATUS_SUCCESS (2U)
#  endif

#  ifndef XCP_NVM_STATUS_FAIL
#   define XCP_NVM_STATUS_FAIL (3U)
#  endif
#  ifndef XCP_OP_MODE_NORMAL
#   define XCP_OP_MODE_NORMAL (1U)
#  endif

#  ifndef XCP_OP_MODE_MANF
#   define XCP_OP_MODE_MANF (2U)
#  endif
#  ifndef OFF
#   define OFF (0U)
#  endif

#  ifndef ACTIVE
#   define ACTIVE (1U)
#  endif

#  ifndef PAUSED
#   define PAUSED (2U)
#  endif

#  ifndef FAILED
#   define FAILED (3U)
#  endif
#  ifndef INVALID_INPUT
#   define INVALID_INPUT (0U)
#  endif

#  ifndef SENSOR_FACING_UPWARDS
#   define SENSOR_FACING_UPWARDS (1U)
#  endif

#  ifndef SENSOR_FACING_DOWNWARDS
#   define SENSOR_FACING_DOWNWARDS (2U)
#  endif

#  ifndef SENSOR_FACING_RIGHT
#   define SENSOR_FACING_RIGHT (3U)
#  endif

#  ifndef SENSOR_FACING_LEFT
#   define SENSOR_FACING_LEFT (4U)
#  endif

#  ifndef VELOCITY_TOO_LOW
#   define VELOCITY_TOO_LOW (5U)
#  endif

#  ifndef YAW_RATE_TOO_HIGH
#   define YAW_RATE_TOO_HIGH (6U)
#  endif

#  ifndef VEHICLE_IN_RESERVE
#   define VEHICLE_IN_RESERVE (7U)
#  endif

#  ifndef INVALID_VEHICLE_SIGNAL
#   define INVALID_VEHICLE_SIGNAL (8U)
#  endif

#  ifndef TARGETS_TOO_LOW
#   define TARGETS_TOO_LOW (9U)
#  endif

#  ifndef QUALITY_TOO_LOW
#   define QUALITY_TOO_LOW (10U)
#  endif

#  ifndef ALIGNMENT_BLOCKAGE
#   define ALIGNMENT_BLOCKAGE (11U)
#  endif

#  ifndef NONE
#   define NONE (255U)
#  endif
#  ifndef Idt_XCP_LED_STATE_AUTO
#   define Idt_XCP_LED_STATE_AUTO (1U)
#  endif

#  ifndef Idt_XCP_LED_STATE_FORCED_OFF
#   define Idt_XCP_LED_STATE_FORCED_OFF (16U)
#  endif

#  ifndef Idt_XCP_LED_STATE_FORCED_ON
#   define Idt_XCP_LED_STATE_FORCED_ON (17U)
#  endif

#  ifndef Idt_XCP_LED_STATE_FORCED_5_PWM
#   define Idt_XCP_LED_STATE_FORCED_5_PWM (160U)
#  endif

#  ifndef Idt_XCP_LED_STATE_FORCED_50_PWM
#   define Idt_XCP_LED_STATE_FORCED_50_PWM (161U)
#  endif

#  ifndef Idt_XCP_LED_STATE_FORCED_95_PWM
#   define Idt_XCP_LED_STATE_FORCED_95_PWM (162U)
#  endif
#  ifndef Idt_XCP_LED_SELECT_SOURCE_PULL
#   define Idt_XCP_LED_SELECT_SOURCE_PULL (1U)
#  endif

#  ifndef Idt_XCP_LED_SELECT_SOURCE_EN
#   define Idt_XCP_LED_SELECT_SOURCE_EN (2U)
#  endif
#  ifndef FAULT_OVERRIDE_AUTO_MODE
#   define FAULT_OVERRIDE_AUTO_MODE (1U)
#  endif

#  ifndef FAULT_OVERRIDE_SET_FAULT_MODE
#   define FAULT_OVERRIDE_SET_FAULT_MODE (2U)
#  endif

#  ifndef FAULT_OVERRIDE_CLEAR_FAULT_MODE
#   define FAULT_OVERRIDE_CLEAR_FAULT_MODE (3U)
#  endif
#  ifndef Idt_XCP_LED_SELECT_SOURCE_PULL
#   define Idt_XCP_LED_SELECT_SOURCE_PULL (1U)
#  endif

#  ifndef Idt_XCP_LED_SELECT_SOURCE_EN
#   define Idt_XCP_LED_SELECT_SOURCE_EN (2U)
#  endif
#  ifndef Idt_XCP_LED_STATE_AUTO
#   define Idt_XCP_LED_STATE_AUTO (1U)
#  endif

#  ifndef Idt_XCP_LED_STATE_FORCED_OFF
#   define Idt_XCP_LED_STATE_FORCED_OFF (16U)
#  endif

#  ifndef Idt_XCP_LED_STATE_FORCED_ON
#   define Idt_XCP_LED_STATE_FORCED_ON (17U)
#  endif

#  ifndef Idt_XCP_LED_STATE_FORCED_5_PWM
#   define Idt_XCP_LED_STATE_FORCED_5_PWM (160U)
#  endif

#  ifndef Idt_XCP_LED_STATE_FORCED_50_PWM
#   define Idt_XCP_LED_STATE_FORCED_50_PWM (161U)
#  endif

#  ifndef Idt_XCP_LED_STATE_FORCED_95_PWM
#   define Idt_XCP_LED_STATE_FORCED_95_PWM (162U)
#  endif
#  ifndef XCP_DISABLE
#   define XCP_DISABLE (0U)
#  endif

#  ifndef XCP_ENABLE
#   define XCP_ENABLE (1U)
#  endif
# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PLT_CDD_XCP_TYPE_H */
