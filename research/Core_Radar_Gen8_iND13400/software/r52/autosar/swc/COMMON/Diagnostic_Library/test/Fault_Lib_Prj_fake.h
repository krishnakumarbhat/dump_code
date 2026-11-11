/**
 * @file Fault_Lib_Prj_fake.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2022 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Mocks of the functions in Fault_Lib_Prj.c file.
 *
 * @section ABBR ABBREVIATIONS:
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
#ifndef FAULT_LIB_PRJ_FAKE_H_
#define FAULT_LIB_PRJ_FAKE_H_

#include "fff.h"

#define PLATFORM_FAULT_TABLE_SIZE     (16U)
#define MAX_NUMBER_OF_PRJ_FAULT_TYPES (256U)
#define BYTE_SIZE                     (8U)

typedef unsigned char uint8_t;
typedef uint8_t u8p0_T;
/* Bit fields */
typedef uint8_t bitfield8_t; /* 8 bit bitfields */

typedef struct
{
   /* 0.7 */
   bitfield8_t reserved_0_7:1;
   bitfield8_t reserved_0_6:1;
   bitfield8_t reserved_0_5:1;
   bitfield8_t reserved_0_4:1;
   bitfield8_t reserved_0_3:1;
   bitfield8_t reserved_0_2:1;
   bitfield8_t reserved_0_1:1;
   bitfield8_t reserved_0_0:1; /*msb*/
                               /* 1.7 */
   bitfield8_t reserved_1_7:1;
   bitfield8_t reserved_1_6:1;
   bitfield8_t reserved_1_5:1;
   bitfield8_t reserved_1_4:1;
   bitfield8_t reserved_1_3:1;
   bitfield8_t reserved_1_2:1;
   bitfield8_t reserved_1_1:1;
   bitfield8_t reserved_1_0:1;
   /* 2.7 */
   bitfield8_t reserved_2_7:1;
   bitfield8_t reserved_2_6:1;
   bitfield8_t reserved_2_5:1;
   bitfield8_t reserved_2_4:1;
   bitfield8_t reserved_2_3:1;
   bitfield8_t reserved_2_2:1;
   bitfield8_t reserved_2_1:1;
   bitfield8_t reserved_2_0:1;
   /* 3.7 */
   bitfield8_t reserved_3_7:1;
   bitfield8_t reserved_3_6:1;
   bitfield8_t reserved_3_5:1;
   bitfield8_t reserved_3_4:1;
   bitfield8_t reserved_3_3:1;
   bitfield8_t reserved_3_2:1;
   bitfield8_t reserved_3_1:1;
   bitfield8_t reserved_3_0:1;
   /* 4.7 */
   bitfield8_t reserved_4_7:1;
   bitfield8_t reserved_4_6:1;
   bitfield8_t reserved_4_5:1;
   bitfield8_t reserved_4_4:1;
   bitfield8_t reserved_4_3:1;
   bitfield8_t reserved_4_2:1;
   bitfield8_t reserved_4_1:1;
   bitfield8_t reserved_4_0:1;
   /* 5.7 */
   bitfield8_t reserved_5_7:1;
   bitfield8_t reserved_5_6:1;
   bitfield8_t reserved_5_5:1;
   bitfield8_t reserved_5_4:1;
   bitfield8_t reserved_5_3:1;
   bitfield8_t reserved_5_2:1;
   bitfield8_t reserved_5_1:1;
   bitfield8_t reserved_5_0:1;
   /* 6.7 */
   bitfield8_t reserved_6_7:1;
   bitfield8_t reserved_6_6:1;
   bitfield8_t reserved_6_5:1;
   bitfield8_t reserved_6_4:1;
   bitfield8_t reserved_6_3:1;
   bitfield8_t reserved_6_2:1;
   bitfield8_t reserved_6_1:1;
   bitfield8_t reserved_6_0:1;
   /* 7.7 */
   bitfield8_t reserved_7_7:1;
   bitfield8_t reserved_7_6:1;
   bitfield8_t reserved_7_5:1;
   bitfield8_t reserved_7_4:1;
   bitfield8_t reserved_7_3:1;
   bitfield8_t reserved_7_2:1;
   bitfield8_t reserved_7_1:1;
   bitfield8_t reserved_7_0:1;
   /* 8.7 */
   bitfield8_t reserved_8_7:1;
   bitfield8_t reserved_8_6:1;
   bitfield8_t reserved_8_5:1;
   bitfield8_t reserved_8_4:1;
   bitfield8_t reserved_8_3:1;
   bitfield8_t reserved_8_2:1;
   bitfield8_t reserved_8_1:1;
   bitfield8_t reserved_8_0:1;
   /* 9.7 */
   bitfield8_t reserved_9_7:1;
   bitfield8_t reserved_9_6:1;
   bitfield8_t reserved_9_5:1;
   bitfield8_t reserved_9_4:1;
   bitfield8_t reserved_9_3:1;
   bitfield8_t reserved_9_2:1;
   bitfield8_t reserved_9_1:1;
   bitfield8_t reserved_9_0:1;
   /* 10.7 */
   bitfield8_t reserved_10_7:1;
   bitfield8_t reserved_10_6:1;
   bitfield8_t reserved_10_5:1;
   bitfield8_t reserved_10_4:1;
   bitfield8_t reserved_10_3:1;
   bitfield8_t reserved_10_2:1;
   bitfield8_t reserved_10_1:1;
   bitfield8_t reserved_10_0:1;
   /* 11.7 */
   bitfield8_t reserved_11_7:1;
   bitfield8_t reserved_11_6:1;
   bitfield8_t reserved_11_5:1;
   bitfield8_t reserved_11_4:1;
   bitfield8_t reserved_11_3:1;
   bitfield8_t reserved_11_2:1;
   bitfield8_t reserved_11_1:1;
   bitfield8_t reserved_11_0:1;
   /* 12.7 */
   bitfield8_t reserved_12_7:1;
   bitfield8_t reserved_12_6:1;
   bitfield8_t reserved_12_5:1;
   bitfield8_t reserved_12_4:1;
   bitfield8_t reserved_12_3:1;
   bitfield8_t reserved_12_2:1;
   bitfield8_t reserved_12_1:1;
   bitfield8_t reserved_12_0:1;
   /* 13.7 */
   bitfield8_t reserved_13_7:1;
   bitfield8_t reserved_13_6:1;
   bitfield8_t reserved_13_5:1;
   bitfield8_t reserved_13_4:1;
   bitfield8_t reserved_13_3:1;
   bitfield8_t reserved_13_2:1;
   bitfield8_t reserved_13_1:1;
   bitfield8_t reserved_13_0:1;
   /* 14.7 */
   bitfield8_t reserved_14_7:1;
   bitfield8_t reserved_14_6:1;
   bitfield8_t reserved_14_5:1;
   bitfield8_t reserved_14_4:1;
   bitfield8_t reserved_14_3:1;
   bitfield8_t reserved_14_2:1;
   bitfield8_t reserved_14_1:1;
   bitfield8_t reserved_14_0:1;
   /* 15.7 */
   bitfield8_t reserved_15_7:1;
   bitfield8_t reserved_15_6:1;
   bitfield8_t reserved_15_5:1;
   bitfield8_t reserved_15_4:1;
   bitfield8_t reserved_15_3:1;
   bitfield8_t reserved_15_2:1;
   bitfield8_t reserved_15_1:1;
   bitfield8_t reserved_15_0:1;
   /* 16.0 */ /* Customer fault starts */
   bitfield8_t reserved_16_7:1;
   bitfield8_t reserved_16_6:1;
   bitfield8_t reserved_16_5:1;
   bitfield8_t reserved_16_4:1;
   bitfield8_t reserved_16_3:1;
   bitfield8_t vcan_bus_off_fault:1;
   bitfield8_t pcan_bus_off_fault:1;
   bitfield8_t reserved_16_0:1;
   /* 17.0 */
   bitfield8_t reserved_17_7:1;
   bitfield8_t reserved_17_6:1;
   bitfield8_t pcan_implausible_signal_error_fault:1;
   bitfield8_t pcan_busoff_fault:1;
   bitfield8_t pcan_message_timeout_fault:1;
   bitfield8_t sensor_position_mismatch_fault:1;
   bitfield8_t high_voltage_fault:1;
   bitfield8_t low_voltage_fault:1;
   /* 18.0 */
   bitfield8_t reserved_18_7:1;
   bitfield8_t reserved_18_6:1;
   bitfield8_t reserved_18_5:1;
   bitfield8_t reserved_18_4:1;
   bitfield8_t reserved_18_3:1;
   bitfield8_t reserved_18_2:1;
   bitfield8_t reserved_18_1:1;
   bitfield8_t reserved_18_0:1;
   /* 19.0 */
   bitfield8_t reserved_19_7:1;
   bitfield8_t reserved_19_6:1;
   bitfield8_t reserved_19_5:1;
   bitfield8_t reserved_19_4:1;
   bitfield8_t reserved_19_3:1;
   bitfield8_t reserved_19_2:1;
   bitfield8_t reserved_19_1:1;
   bitfield8_t reserved_19_0:1;
   /* 20.0 */
   bitfield8_t reserved_20_7:1;
   bitfield8_t reserved_20_6:1;
   bitfield8_t reserved_20_5:1;
   bitfield8_t reserved_20_4:1;
   bitfield8_t reserved_20_3:1;
   bitfield8_t reserved_20_2:1;
   bitfield8_t reserved_20_1:1;
   bitfield8_t reserved_20_0:1;
   /* 21.0 */
   bitfield8_t reserved_21_7:1;
   bitfield8_t reserved_21_6:1;
   bitfield8_t reserved_21_5:1;
   bitfield8_t dataset_unprogrammed_fault:1;
   bitfield8_t dataset_crc_failure_fault:1;
   bitfield8_t reserved_21_2:1;
   bitfield8_t reserved_21_1:1;
   bitfield8_t reserved_21_0:1;
   /* 22.0 */
   bitfield8_t reserved_22_7:1;
   bitfield8_t reserved_22_6:1;
   bitfield8_t reserved_22_5:1;
   bitfield8_t reserved_22_4:1;
   bitfield8_t reserved_22_3:1;
   bitfield8_t reserved_22_2:1;
   bitfield8_t reserved_22_1:1;
   bitfield8_t reserved_22_0:1;
   /* 23.0 */
   bitfield8_t reserved_23_7:1;
   bitfield8_t reserved_23_6:1;
   bitfield8_t reserved_23_5:1;
   bitfield8_t reserved_23_4:1;
   bitfield8_t reserved_23_3:1;
   bitfield8_t reserved_23_2:1;
   bitfield8_t reserved_23_1:1;
   bitfield8_t reserved_23_0:1;
   /* 24.0 */
   bitfield8_t reserved_24_7:1;
   bitfield8_t reserved_24_6:1;
   bitfield8_t reserved_24_5:1;
   bitfield8_t reserved_24_4:1;
   bitfield8_t reserved_24_3:1;
   bitfield8_t reserved_24_2:1;
   bitfield8_t reserved_24_1:1;
   bitfield8_t reserved_24_0:1;
   /* 25.0 */
   bitfield8_t reserved_25_7:1;
   bitfield8_t reserved_25_6:1;
   bitfield8_t reserved_25_5:1;
   bitfield8_t reserved_25_4:1;
   bitfield8_t reserved_25_3:1;
   bitfield8_t reserved_25_2:1;
   bitfield8_t reserved_25_1:1;
   bitfield8_t reserved_25_0:1;
   /* 26.0 */
   bitfield8_t reserved_26_7:1;
   bitfield8_t reserved_26_6:1;
   bitfield8_t reserved_26_5:1;
   bitfield8_t reserved_26_4:1;
   bitfield8_t reserved_26_3:1;
   bitfield8_t reserved_26_2:1;
   bitfield8_t reserved_26_1:1;
   bitfield8_t reserved_26_0:1;
   /* 27.0 */
   bitfield8_t reserved_27_7:1;
   bitfield8_t reserved_27_6:1;
   bitfield8_t reserved_27_5:1;
   bitfield8_t reserved_27_4:1;
   bitfield8_t reserved_27_3:1;
   bitfield8_t reserved_27_2:1;
   bitfield8_t reserved_27_1:1;
   bitfield8_t reserved_27_0:1;
   /* 28.0 */
   bitfield8_t reserved_28_7:1;
   bitfield8_t reserved_28_6:1;
   bitfield8_t reserved_28_5:1;
   bitfield8_t reserved_28_4:1;
   bitfield8_t reserved_28_3:1;
   bitfield8_t reserved_28_2:1;
   bitfield8_t reserved_28_1:1;
   bitfield8_t reserved_28_0:1;
   /* 29.0 */
   bitfield8_t reserved_29_7:1;
   bitfield8_t reserved_29_6:1;
   bitfield8_t reserved_29_5:1;
   bitfield8_t reserved_29_4:1;
   bitfield8_t reserved_29_3:1;
   bitfield8_t reserved_29_2:1;
   bitfield8_t reserved_29_1:1;
   bitfield8_t reserved_29_0:1;
   /* 30.0 */
   bitfield8_t reserved_30_7:1;
   bitfield8_t reserved_30_6:1;
   bitfield8_t reserved_30_5:1;
   bitfield8_t reserved_30_4:1;
   bitfield8_t reserved_30_3:1;
   bitfield8_t reserved_30_2:1;
   bitfield8_t reserved_30_1:1;
   bitfield8_t reserved_30_0:1;
   /* 31.0 */
   bitfield8_t reserved_31_7:1;
   bitfield8_t reserved_31_6:1;
   bitfield8_t reserved_31_5:1;
   bitfield8_t reserved_31_4:1;
   bitfield8_t reserved_31_3:1;
   bitfield8_t reserved_31_2:1;
   bitfield8_t reserved_31_1:1;
   bitfield8_t reserved_31_0:1;

} packed_Customer_Fault_bits_T;

typedef struct
{
   /* 0.7 */
   bitfield8_t usc_validation_fault:1; /* lsb */
   bitfield8_t smc_validtn_fault:1;
   bitfield8_t reserved_0_5:1;
   bitfield8_t reserved_0_4:1;
   bitfield8_t mmic_transmitter_id_fault:1;
   bitfield8_t reserved_0_2:1;
   bitfield8_t reserved_0_1:1;
   bitfield8_t reserved_0_0:1; /*msb*/
                               /* 1.7 */
   bitfield8_t reserved_1_7:1;
   bitfield8_t reserved_1_6:1;
   bitfield8_t reserved_1_5:1;
   bitfield8_t reserved_1_4:1;
   bitfield8_t reserved_1_3:1;
   bitfield8_t reserved_1_2:1;
   bitfield8_t reserved_1_1:1;
   bitfield8_t reserved_1_0:1;
   /* 2.7 */
   bitfield8_t mcu_startup_fault:1;
   bitfield8_t reserved_2_6:1;
   bitfield8_t reserved_2_5:1;
   bitfield8_t reserved_2_4:1;
   bitfield8_t reserved_2_3:1;
   bitfield8_t reserved_2_2:1;
   bitfield8_t mcu_repetitive_reset_fault:1;
   bitfield8_t reserved_2_0:1;
   /* 3.7 */
   bitfield8_t reserved_3_7:1;
   bitfield8_t reserved_3_6:1;
   bitfield8_t reserved_3_5:1;
   bitfield8_t reserved_3_4:1;
   bitfield8_t reserved_3_3:1;
   bitfield8_t reserved_3_2:1;
   bitfield8_t reserved_3_1:1;
   bitfield8_t reserved_3_0:1;
   /* 4.7 */
   bitfield8_t reserved_4_7:1;
   bitfield8_t reserved_4_6:1;
   bitfield8_t reserved_4_5:1;
   bitfield8_t reserved_4_4:1;
   bitfield8_t reserved_4_3:1;
   bitfield8_t reserved_4_2:1;
   bitfield8_t reserved_4_1:1;
   bitfield8_t reserved_4_0:1;
   /* 5.7 */
   bitfield8_t bbe_to_r52_ipc_fault:1;
   bitfield8_t r52_to_bbe_ipc_fault:1;
   bitfield8_t reserved_5_5:1;
   bitfield8_t reserved_5_4:1;
   bitfield8_t reserved_5_3:1;
   bitfield8_t reserved_5_2:1;
   bitfield8_t reserved_5_1:1;
   bitfield8_t reserved_5_0:1;
   /* 6.7 */
   bitfield8_t reserved_6_7:1;
   bitfield8_t reserved_6_6:1;
   bitfield8_t reserved_6_5:1;
   bitfield8_t reserved_6_4:1;
   bitfield8_t reserved_6_3:1;
   bitfield8_t reserved_6_2:1;
   bitfield8_t reserved_6_1:1;
   bitfield8_t reserved_6_0:1;
   /* 7.7 */
   bitfield8_t reserved_7_7:1;
   bitfield8_t reserved_7_6:1;
   bitfield8_t battery_low_fault:1;
   bitfield8_t battery_high_fault:1;
   bitfield8_t reserved_7_3:1;
   bitfield8_t reserved_7_2:1;
   bitfield8_t reserved_7_1:1;
   bitfield8_t mmic_temperature_high_fault:1;
   /* 8.7 */
   bitfield8_t reserved_8_7:1;
   bitfield8_t mmic_a_sensor_dead_fault:1;
   bitfield8_t reserved_8_5:1;
   bitfield8_t mmic_safe_start_fault:1;
   bitfield8_t api_look_config_fault:1;
   bitfield8_t api_look_trigger_fault:1;
   bitfield8_t api_look_complete_fault:1;
   bitfield8_t mmic_temperature_low_fault:1;
   /* 9.7 */
   bitfield8_t reserved_9_7:1;
   bitfield8_t reserved_9_6:1;
   bitfield8_t acquisition_overflow_fault:1;
   bitfield8_t reserved_9_4:1;
   bitfield8_t reserved_9_3:1;
   bitfield8_t reserved_9_2:1;
   bitfield8_t reserved_9_1:1;
   bitfield8_t reserved_9_0:1;
   /* 10.7 */
   bitfield8_t reserved_10_7:1;
   bitfield8_t signal_integrity_fault:1;
   bitfield8_t reserved_10_5:1;
   bitfield8_t reserved_10_4:1;
   bitfield8_t reserved_10_3:1;
   bitfield8_t reserved_10_2:1;
   bitfield8_t reserved_10_1:1;
   bitfield8_t reserved_10_0:1;
   /* 11.7 */
   bitfield8_t reserved_11_7:1;
   bitfield8_t reserved_11_6:1;
   bitfield8_t reserved_11_5:1;
   bitfield8_t rfe_under_over_voltage_fault:1;
   bitfield8_t reserved_11_3:1;
   bitfield8_t reserved_11_2:1;
   bitfield8_t reserved_11_1:1;
   bitfield8_t reserved_11_0:1;
   /* 12.7 */
   bitfield8_t mmic_error_recovery_failure_fault:1;
   bitfield8_t reserved_12_6:1;
   bitfield8_t reserved_12_5:1;
   bitfield8_t reserved_12_4:1;
   bitfield8_t autoalignment_critical_misalignment_fault:1;
   bitfield8_t alignment_autoalignment_sudden_jump_detection_fault:1;
   bitfield8_t reserved_12_1:1;
   bitfield8_t reserved_12_0:1;
   /* 13.7 */
   bitfield8_t reserved_13_7:1;
   bitfield8_t alignment_no_initial_calibration_error_fault:1;
   bitfield8_t alignment_static_calibration_error_fault:1;
   bitfield8_t alignment_service_calibration_error_fault:1;
   bitfield8_t alignment_shorttrack_calibration_error_fault:1;
   bitfield8_t alignment_autoalignment_out_of_range_fault:1;
   bitfield8_t alignment_autoalignment_algo_error_fault:1;
   bitfield8_t reserved_13_0:1;
   /* 14.7 */
   bitfield8_t reserved_14_7:1;
   bitfield8_t sll_monitoring_algo_error:1;
   bitfield8_t reserved_14_5:1;
   bitfield8_t blockage_algo_error_fault:1;
   bitfield8_t reserved_14_3:1;
   bitfield8_t reserved_14_2:1;
   bitfield8_t reserved_14_1:1;
   bitfield8_t reserved_14_0:1;
   /* 15.7 */
   bitfield8_t damping_algo_error_fault:1;
   bitfield8_t reserved_15_6:1;
   bitfield8_t range_algo_error_fault:1;
   bitfield8_t reserved_15_4:1;
   bitfield8_t reserved_15_3:1;
   bitfield8_t reserved_15_2:1;
   bitfield8_t reserved_15_1:1;
   bitfield8_t reserved_15_0:1;

} Packed_Platform_Fault_bits_T;

typedef union
{
   Packed_Platform_Fault_bits_T Platform_Bits;
   u8p0_T Platform_byte[PLATFORM_FAULT_TABLE_SIZE];
   packed_Customer_Fault_bits_T Customer_Bits;
   u8p0_T Customer_byte[MAX_NUMBER_OF_PRJ_FAULT_TYPES / BYTE_SIZE];
} Customer_fault_T;

#ifdef __cplusplus
extern "C"
{
#endif
   DECLARE_FAKE_VOID_FUNC(Platform_Active_Fault_Table);
   DECLARE_FAKE_VOID_FUNC(Platform_Fault_Enable_Table);

#ifdef __cplusplus
}
#endif

#endif
