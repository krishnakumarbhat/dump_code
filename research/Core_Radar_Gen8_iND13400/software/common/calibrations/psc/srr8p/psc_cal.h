#ifndef _PSC_CAL_H
#define _PSC_CAL_H

/****************************************************************************
 * Copyright 2022 APTIV, All Rights Reserved
 * Calibration File for Production Code
 * File Name: psc_cal.h
 * Created: 2022-11-29_11-42-05
 * From JSON File: psc_cal_17_73_0_0.json
 * Calibration Values for Project: FLR7-A1
 * Calibrations for Module: psc_cal
 * Generator Version: v3
 *****************************************************************************/

#include "calibration.h"
#include "fixmac.h"

#define PSC_H2_CUSTOMER              (1U)
#define PSC_H2_PTP_CAL_TYPE          (2U)
#define PSC_H2_PLATFORM              (72U)
#define PSC_H2_NO_OF_SECTIONS        (2U)
#define PSC_H2_SECTION_COMPATIBILITY (2U)
#define PSC_H2_UNUSED1               (0U)
#define PSC_H2_VERSION               (1U)
#define PSC_H2_SECTION_SIZE          (4352U)
#define PSC_H2_UNUSED3               (0U)
#define PSC_H2_UNUSED4               (0U)

#define Diag_PLT_Debouncing_Size (212)

#define PSC_H3_DIAG_PLT_DEBOUNCING_CAL_TYPE              (0U)
#define PSC_H3_DIAG_PLT_DEBOUNCING_UNUSED1               (0U)
#define PSC_H3_DIAG_PLT_DEBOUNCING_UNUSED2               (0U)
#define PSC_H3_DIAG_PLT_DEBOUNCING_SECTION_COMPATIBILITY (0U)
#define PSC_H3_DIAG_PLT_DEBOUNCING_VERSION               (0U)
#define PSC_H3_DIAG_PLT_DEBOUNCING_SECTION_SIZE          (212U)

#ifndef PC_RESIM

typedef struct Diag_PLT_Debouncing_Cal_Tag
{
   H3_Hdr_T header;
   u8p0_T battery_high_pass_limit;
   u8p0_T battery_high_fail_limit;
   u8p0_T battery_low_pass_limit;
   u8p0_T battery_low_fail_limit;
   u8p0_T smc_validtn_pass_limit;
   u8p0_T smc_validtn_fail_limit;
   u8p0_T usc_validation_pass_limit;
   u8p0_T usc_validation_fail_limit;
   u8p0_T mcu_repetitive_reset_pass_limit;
   u8p0_T mcu_repetitive_reset_fail_limit;
   u8p0_T mcu_startup_pass_limit;
   u8p0_T mcu_startup_fail_limit;
   u8p0_T platform_time_pass_limit;
   u8p0_T platform_time_fail_limit;
   u8p0_T radar_transceiver_safe_start_pass_limit;
   u8p0_T radar_transceiver_safe_start_fail_limit;
   u8p0_T radar_transceiver_temperature_pass_limit;
   u8p0_T radar_transceiver_temperature_fail_limit;
   u8p0_T transmitter_id_pass_limit;
   u8p0_T transmitter_id_fail_limit;
   u8p0_T blockage_algo_fail_limit;
   u8p0_T blockage_algo_pass_limit;
   u8p0_T damping_algo_fail_limit;
   u8p0_T damping_algo_pass_limit;
   u8p0_T external_wdg_fail_limit;
   u8p0_T external_wdg_pass_limit;
   u8p0_T no_initial_calibration_pass_limit;
   u8p0_T no_initial_calibration_fail_limit;
   u8p0_T static_calibration_pass_limit;
   u8p0_T static_calibration_fail_limit;
   u8p0_T service_calibration_pass_limit;
   u8p0_T service_calibration_fail_limit;
   u8p0_T shorttrack_calibration_pass_limit;
   u8p0_T shorttrack_calibration_fail_limit;
   u8p0_T autoalign_outof_range_pass_limit;
   u8p0_T autoalign_outof_range_fail_limit;
   u8p0_T autoalignment_algo_pass_limit;
   u8p0_T autoalignment_algo_fail_limit;
   u8p0_T rfe_under_over_voltage_fail_limit;
   u8p0_T rfe_under_over_voltage_pass_limit;
   u8p0_T rfe_tx_Rfbist_fail_limit;
   u8p0_T rfe_tx_Rfbist_pass_limit;
   u8p0_T rfe_rx_rfbist_fail_limit;
   u8p0_T rfe_rx_rfbist_pass_limit;
   u8p0_T pmic_mcu_communication_pass_limit;
   u8p0_T pmic_mcu_communication_fail_limit;
   u8p0_T core_self_test_pass_limit;
   u8p0_T core_self_test_fail_limit;
   u8p0_T safety_integrity_Pass_Limit;
   u8p0_T safety_integrity_Fail_Limit;
   u8p0_T signal_integrity_pass_limit;
   u8p0_T signal_integrity_fail_limit;
   u8p0_T mmic_error_recovery_pass_limit;
   u8p0_T mmic_error_recovery_fail_limit;
   u8p0_T bbe_to_r52_ipc_fault_pass_limit;
   u8p0_T bbe_to_r52_ipc_fault_fail_limit;
   u8p0_T r52_to_bbe_ipc_fault_pass_limit;
   u8p0_T r52_to_bbe_ipc_fault_fail_limit;
   u8p0_T autoalignment_sudden_jump_detection_pass_limit;
   u8p0_T autoalignment_sudden_jump_detection_fail_limit;
   u8p0_T detection_procession_loop_overrun_fault_pass_limit;
   u8p0_T detection_procession_loop_overrun_fault_fail_limit;
   u8p0_T first_pass_saturation_pass_limit;
   u8p0_T first_pass_saturation_fail_limit;
   u8p0_T mmic_secondary_clock_pass_limit;
   u8p0_T mmic_secondary_clock_fail_limit;
   u8p0_T mmic_secondary_mipi_pass_limit;
   u8p0_T mmic_secondary_mipi_fail_limit;
   u8p0_T mmic_secondary_register_pass_limit;
   u8p0_T mmic_secondary_register_fail_limit;
   u8p0_T mmic_secondary_mcu_pass_limit;
   u8p0_T mmic_secondary_mcu_fail_limit;
   u8p0_T Detection_Data_Integrity_Fault_Pass_Limit;
   u8p0_T Detection_Data_Integrity_Fault_Fail_Limit;
   u8p0_T dsp_internal_Pass_Limit;
   u8p0_T dsp_internal_Fail_Limit;
   u8p0_T mmic_secondary_ballbreak_pass_limit;
   u8p0_T mmic_secondary_ballbreak_fail_limit;
   u8p0_T vcan_busoff_pass_limit;
   u8p0_T vcan_busoff_fail_limit;
   u8p0_T pcan_busoff_pass_limit;
   u8p0_T pcan_busoff_fail_limit;
   u8p0_T pcan_message_timeout_pass_limit;
   u8p0_T pcan_message_timeout_fail_limit;
   u8p0_T CCVS1_message_timeout_pass_limit;
   u8p0_T CCVS1_message_timeout_fail_limit;
   u8p0_T VDC2_message_timeout_pass_limit;
   u8p0_T VDC2_message_timeout_fail_limit;
   u8p0_T ETC2_MT_Variant_message_timeout_pass_limit;
   u8p0_T ETC2_MT_Variant_message_timeout_fail_limit;
   u8p0_T ETC2_AT_AMT_Variant_message_timeout_pass_limit;
   u8p0_T ETC2_AT_AMT_Variant_message_timeout_fail_limit;
   u8p0_T ADAS_Function_Switch_message_timeout_pass_limit;
   u8p0_T ADAS_Function_Switch_message_timeout_fail_limit;
   u8p0_T CLS_Tx_16_message_timeout_pass_limit;
   u8p0_T CLS_Tx_16_message_timeout_fail_limit;
   u8p0_T CLS_TX_4_message_timeout_pass_limit;
   u8p0_T CLS_TX_4_message_timeout_fail_limit;
   u8p0_T OEL_message_timeout_pass_limit;
   u8p0_T OEL_message_timeout_fail_limit;
   u8p0_T TD_message_timeout_pass_limit;
   u8p0_T TD_message_timeout_fail_limit;
   u8p0_T VD_message_timeout_pass_limit;
   u8p0_T VD_message_timeout_fail_limit;
   u8p0_T SAS_message_timeout_pass_limit;
   u8p0_T SAS_message_timeout_fail_limit;
   u8p0_T Prj_Battery_High_fault_pass_limit;
   u8p0_T Prj_Battery_High_fault_fail_limit;
   u8p0_T Prj_Battery_Low_fault_pass_limit;
   u8p0_T Prj_Battery_Low_fault_fail_limit;
   u8p0_T Time_Synchronization_Fault_Pass_Limit;
   u8p0_T Time_Synchronization_Fault_Fail_Limit;
   u8p0_T pinposition_mismatch_fault_pass_limit;
   u8p0_T pinposition_mismatch_fault_fail_limit;
} Diag_PLT_Debouncing_Cal_T;

#else

typedef struct Diag_PLT_Debouncing_Cal_Tag
{
   u8p0_T Time_Synchronization_Fault_Fail_Limit;
   u8p0_T Time_Synchronization_Fault_Pass_Limit;
   u8p0_T Prj_Battery_Low_fault_fail_limit;
   u8p0_T Prj_Battery_Low_fault_pass_limit;
   u8p0_T Prj_Battery_High_fault_fail_limit;
   u8p0_T Prj_Battery_High_fault_pass_limit;
   u8p0_T SAS_message_timeout_fail_limit;
   u8p0_T SAS_message_timeout_pass_limit;
   u8p0_T VD_message_timeout_fail_limit;
   u8p0_T VD_message_timeout_pass_limit;
   u8p0_T TD_message_timeout_fail_limit;
   u8p0_T TD_message_timeout_pass_limit;
   u8p0_T OEL_message_timeout_fail_limit;
   u8p0_T OEL_message_timeout_pass_limit;
   u8p0_T CLS_TX_4_message_timeout_fail_limit;
   u8p0_T CLS_TX_4_message_timeout_pass_limit;
   u8p0_T CLS_Tx_16_message_timeout_fail_limit;
   u8p0_T CLS_Tx_16_message_timeout_pass_limit;
   u8p0_T ADAS_Function_Switch_message_timeout_fail_limit;
   u8p0_T ADAS_Function_Switch_message_timeout_pass_limit;
   u8p0_T ETC2_AT_AMT_Variant_message_timeout_fail_limit;
   u8p0_T ETC2_AT_AMT_Variant_message_timeout_pass_limit;
   u8p0_T ETC2_MT_Variant_message_timeout_fail_limit;
   u8p0_T ETC2_MT_Variant_message_timeout_pass_limit;
   u8p0_T VDC2_message_timeout_fail_limit;
   u8p0_T VDC2_message_timeout_pass_limit;
   u8p0_T CCVS1_message_timeout_fail_limit;
   u8p0_T CCVS1_message_timeout_pass_limit;
   u8p0_T pcan_message_timeout_fail_limit;
   u8p0_T pcan_message_timeout_pass_limit;
   u8p0_T pinposition_mismatch_fault_fail_limit;
   u8p0_T pinposition_mismatch_fault_pass_limit;
   u8p0_T pcan_busoff_fail_limit;
   u8p0_T pcan_busoff_pass_limit;
   u8p0_T vcan_busoff_fail_limit;
   u8p0_T vcan_busoff_pass_limit;
   u8p0_T mmic_secondary_ballbreak_fail_limit;
   u8p0_T mmic_secondary_ballbreak_pass_limit;
   u8p0_T dsp_internal_Fail_Limit;
   u8p0_T dsp_internal_Pass_Limit;
   u8p0_T Detection_Data_Integrity_Fault_Fail_Limit;
   u8p0_T Detection_Data_Integrity_Fault_Pass_Limit;
   u8p0_T mmic_secondary_mcu_fail_limit;
   u8p0_T mmic_secondary_mcu_pass_limit;
   u8p0_T mmic_secondary_register_fail_limit;
   u8p0_T mmic_secondary_register_pass_limit;
   u8p0_T mmic_secondary_mipi_fail_limit;
   u8p0_T mmic_secondary_mipi_pass_limit;
   u8p0_T mmic_secondary_clock_fail_limit;
   u8p0_T mmic_secondary_clock_pass_limit;
   u8p0_T first_pass_saturation_fail_limit;
   u8p0_T first_pass_saturation_pass_limit;
   u8p0_T detection_procession_loop_overrun_fault_fail_limit;
   u8p0_T detection_procession_loop_overrun_fault_pass_limit;
   u8p0_T autoalignment_sudden_jump_detection_fail_limit;
   u8p0_T autoalignment_sudden_jump_detection_pass_limit;
   u8p0_T r52_to_bbe_ipc_fault_fail_limit;
   u8p0_T r52_to_bbe_ipc_fault_pass_limit;
   u8p0_T bbe_to_r52_ipc_fault_fail_limit;
   u8p0_T bbe_to_r52_ipc_fault_pass_limit;
   u8p0_T mmic_error_recovery_fail_limit;
   u8p0_T mmic_error_recovery_pass_limit;
   u8p0_T signal_integrity_fail_limit;
   u8p0_T signal_integrity_pass_limit;
   u8p0_T safety_integrity_Fail_Limit;
   u8p0_T safety_integrity_Pass_Limit;
   u8p0_T core_self_test_fail_limit;
   u8p0_T core_self_test_pass_limit;
   u8p0_T pmic_mcu_communication_fail_limit;
   u8p0_T pmic_mcu_communication_pass_limit;
   u8p0_T rfe_rx_rfbist_pass_limit;
   u8p0_T rfe_rx_rfbist_fail_limit;
   u8p0_T rfe_tx_Rfbist_pass_limit;
   u8p0_T rfe_tx_Rfbist_fail_limit;
   u8p0_T rfe_under_over_voltage_pass_limit;
   u8p0_T rfe_under_over_voltage_fail_limit;
   u8p0_T autoalignment_algo_fail_limit;
   u8p0_T autoalignment_algo_pass_limit;
   u8p0_T autoalign_outof_range_fail_limit;
   u8p0_T autoalign_outof_range_pass_limit;
   u8p0_T shorttrack_calibration_fail_limit;
   u8p0_T shorttrack_calibration_pass_limit;
   u8p0_T service_calibration_fail_limit;
   u8p0_T service_calibration_pass_limit;
   u8p0_T static_calibration_fail_limit;
   u8p0_T static_calibration_pass_limit;
   u8p0_T no_initial_calibration_fail_limit;
   u8p0_T no_initial_calibration_pass_limit;
   u8p0_T external_wdg_pass_limit;
   u8p0_T external_wdg_fail_limit;
   u8p0_T damping_algo_pass_limit;
   u8p0_T damping_algo_fail_limit;
   u8p0_T blockage_algo_pass_limit;
   u8p0_T blockage_algo_fail_limit;
   u8p0_T transmitter_id_fail_limit;
   u8p0_T transmitter_id_pass_limit;
   u8p0_T radar_transceiver_temperature_fail_limit;
   u8p0_T radar_transceiver_temperature_pass_limit;
   u8p0_T radar_transceiver_safe_start_fail_limit;
   u8p0_T radar_transceiver_safe_start_pass_limit;
   u8p0_T platform_time_fail_limit;
   u8p0_T platform_time_pass_limit;
   u8p0_T mcu_startup_fail_limit;
   u8p0_T mcu_startup_pass_limit;
   u8p0_T mcu_repetitive_reset_fail_limit;
   u8p0_T mcu_repetitive_reset_pass_limit;
   u8p0_T usc_validation_fail_limit;
   u8p0_T usc_validation_pass_limit;
   u8p0_T smc_validtn_fail_limit;
   u8p0_T smc_validtn_pass_limit;
   u8p0_T battery_low_fail_limit;
   u8p0_T battery_low_pass_limit;
   u8p0_T battery_high_fail_limit;
   u8p0_T battery_high_pass_limit;
   H3_Hdr_T header;
} Diag_PLT_Debouncing_Cal_T;

#endif

/**********************************************************************/
/***************** Macros for Max size of calibration *****************/
/**********************************************************************/
#define MAX_SUPPLY_5V_OUT_OF_RANGE_PASS_LIMIT                    (256)
#define MAX_SUPPLY_5V_OUT_OF_RANGE_FAIL_LIMIT                    (256)
#define MAX_SUPPLY_2_3V_OUT_OF_RANGE_PASS_LIMIT                  (256)
#define MAX_SUPPLY_2_3V_OUT_OF_RANGE_FAIL_LIMIT                  (256)
#define MAX_SUPPLY_1_8V_OUT_OF_RANGE_PASS_LIMIT                  (256)
#define MAX_SUPPLY_1_8V_OUT_OF_RANGE_FAIL_LIMIT                  (256)
#define MAX_SUPPLY_1_2_5V_OUT_OF_RANGE_PASS_LIMIT                (256)
#define MAX_SUPPLY_1_2_5V_OUT_OF_RANGE_FAIL_LIMIT                (256)
#define MAX_SUPPLY_1_1V_OUT_OF_RANGE_PASS_LIMIT                  (256)
#define MAX_SUPPLY_1_1V_OUT_OF_RANGE_FAIL_LIMIT                  (256)
#define MAX_SUPPLY_3_3V_TO_MMIC_PASS_LIMIT                       (256)
#define MAX_SUPPLY_3_3V_TO_MMIC_FAIL_LIMIT                       (256)
#define MAX_SUPPLY_0_9V_SUPPLY_OUT_OF_RANGE_PASS_LIMIT           (256)
#define MAX_SUPPLY_0_9V_SUPPLY_OUT_OF_RANGE_FAIL_LIMIT           (256)
#define MAX_SUPPLY_0_8V_OUT_OF_RANGE_PASS_LIMIT                  (256)
#define MAX_SUPPLY_0_8V_OUT_OF_RANGE_FAIL_LIMIT                  (256)
#define MAX_BANDGAP_REFERENCE_VOLTAGE_PASS_LIMIT                 (256)
#define MAX_BANDGAP_REFERENCE_VOLTAGE_FAIL_LIMIT                 (256)
#define MAX_BATTERY_HIGH_PASS_LIMIT                              (256)
#define MAX_BATTERY_HIGH_FAIL_LIMIT                              (256)
#define MAX_BATTERY_LOW_PASS_LIMIT                               (256)
#define MAX_BATTERY_LOW_FAIL_LIMIT                               (256)
#define MAX_APPLICATION_FLASH_CHECKSUM_PASS_LIMIT                (256)
#define MAX_APPLICATION_FLASH_CHECKSUM_FAIL_LIMIT                (256)
#define MAX_SMC_VALIDTN_PASS_LIMIT                               (256)
#define MAX_SMC_VALIDTN_FAIL_LIMIT                               (256)
#define MAX_USC_VALIDATION_PASS_LIMIT                            (256)
#define MAX_USC_VALIDATION_FAIL_LIMIT                            (256)
#define MAX_RAM_MEMORY_TEST_PASS_LIMIT                           (256)
#define MAX_RAM_MEMORY_TEST_FAIL_LIMIT                           (256)
#define MAX_CORE2_CALIBRATION_FLASH_CHECKSUM_PASS_LIMIT          (256)
#define MAX_CORE2_CALIBRATION_FLASH_CHECKSUM_FAIL_LIMIT          (256)
#define MAX_CAN_CONTROLLER_RAM_PASS_LIMIT                        (256)
#define MAX_CAN_CONTROLLER_RAM_FAIL_LIMIT                        (256)
#define MAX_CORE2_TO_CORE0_CRC_PASS_LIMIT                        (256)
#define MAX_CORE2_TO_CORE0_CRC_FAIL_LIMIT                        (256)
#define MAX_CORE0_TO_CORE2_CRC_PASS_LIMIT                        (256)
#define MAX_CORE0_TO_CORE2_CRC_FAIL_LIMIT                        (256)
#define MAX_CORE1_TO_CORE2_CRC_PASS_LIMIT                        (256)
#define MAX_CORE1_TO_CORE2_CRC_FAIL_LIMIT                        (256)
#define MAX_CORE2_TO_CORE1_CRC_PASS_LIMIT                        (256)
#define MAX_CORE2_TO_CORE1_CRC_FAIL_LIMIT                        (256)
#define MAX_CORE0_TO_CORE1_CRC_PASS_LIMIT                        (256)
#define MAX_CORE0_TO_CORE1_CRC_FAIL_LIMIT                        (256)
#define MAX_CORE1_TO_CORE0_CRC_PASS_LIMIT                        (256)
#define MAX_CORE1_TO_CORE0_CRC_FAIL_LIMIT                        (256)
#define MAX_THERMISTOR_OUT_OF_RANGE_PASS_LIMIT                   (256)
#define MAX_THERMISTOR_OUT_OF_RANGE_FAIL_LIMIT                   (256)
#define MAX_MICROPROCESSOR_TEMP_HIGH_PASS_LIMIT                  (256)
#define MAX_MICROPROCESSOR_TEMP_HIGH_FAIL_LIMIT                  (256)
#define MAX_ECU_TEMPERATURE_HIGH_PASS_LIMIT                      (256)
#define MAX_ECU_TEMPERATURE_HIGH_FAIL_LIMIT                      (256)
#define MAX_MICROPROCESSOR_TEMP_LOW_PASS_LIMIT                   (256)
#define MAX_MICROPROCESSOR_TEMP_LOW_FAIL_LIMIT                   (256)
#define MAX_PLL_LOCK_PASS_LIMIT                                  (256)
#define MAX_PLL_LOCK_FAIL_LIMIT                                  (256)
#define MAX_INSTRUCTION_SET_CHECK_PASS_LIMIT                     (256)
#define MAX_INSTRUCTION_SET_CHECK_FAIL_LIMIT                     (256)
#define MAX_STACK_OVERFLOW_PASS_LIMIT                            (256)
#define MAX_STACK_OVERFLOW_FAIL_LIMIT                            (256)
#define MAX_DSP_LOOP_OVERRUN_PASS_LIMIT                          (256)
#define MAX_DSP_LOOP_OVERRUN_FAIL_LIMIT                          (256)
#define MAX_CORE2_LOOP_OVERRUN_PASS_LIMIT                        (256)
#define MAX_CORE2_LOOP_OVERRUN_FAIL_LIMIT                        (256)
#define MAX_RRU_CORE_PASS_LIMIT                                  (256)
#define MAX_RRU_CORE_FAIL_LIMIT                                  (256)
#define MAX_MCU_REPETITIVE_RESET_PASS_LIMIT                      (256)
#define MAX_MCU_REPETITIVE_RESET_FAIL_LIMIT                      (256)
#define MAX_SW_EXCEPTION_RESET_REASON_PASS_LIMIT                 (256)
#define MAX_SW_EXCEPTION_RESET_REASON_FAIL_LIMIT                 (256)
#define MAX_MCU_STARTUP_PASS_LIMIT                               (256)
#define MAX_MCU_STARTUP_FAIL_LIMIT                               (256)
#define MAX_PLATFORM_TIME_PASS_LIMIT                             (256)
#define MAX_PLATFORM_TIME_FAIL_LIMIT                             (256)
#define MAX_INTERNAL_WATCHDOG_PASS_LIMIT                         (256)
#define MAX_INTERNAL_WATCHDOG_FAIL_LIMIT                         (256)
#define MAX_SPT_WATCHDOG_PASS_LIMIT                              (256)
#define MAX_SPT_WATCHDOG_FAIL_LIMIT                              (256)
#define MAX_CORE1_AND_CORE2_SW_WATCHDOG_PASS_LIMIT               (256)
#define MAX_CORE1_AND_CORE2_SW_WATCHDOG_FAIL_LIMIT               (256)
#define MAX_CORE1_AND_CORE2_PROGRAM_FLOW_ERROR_PASS_LIMIT        (256)
#define MAX_CORE1_AND_CORE2_PROGRAM_FLOW_ERROR_FAIL_LIMIT        (256)
#define MAX_MMIC_1_8_SUPPLY_PASS_LIMIT                           (256)
#define MAX_MMIC_1_8_SUPPLY_FAIL_LIMIT                           (256)
#define MAX_MMIC_1_1V_SUPPLY_PASS_LIMIT                          (256)
#define MAX_MMIC_1_1V_SUPPLY_FAIL_LIMIT                          (256)
#define MAX_DOLPHIN_TIMEOUT_PASS_LIMIT                           (256)
#define MAX_DOLPHIN_TIMEOUT_FAIL_LIMIT                           (256)
#define MAX_RADAR_TRANSCEIVER_SPI_PASS_LIMIT                     (256)
#define MAX_RADAR_TRANSCEIVER_SPI_FAIL_LIMIT                     (256)
#define MAX_RADAR_TRANSCEIVER_CHIRP_PLL_PASS_LIMIT               (256)
#define MAX_RADAR_TRANSCEIVER_CHIRP_PLL_FAIL_LIMIT               (256)
#define MAX_RADAR_TRANSCEIVER_RF_BALL_BREAK_PASS_LIMIT           (256)
#define MAX_RADAR_TRANSCEIVER_RF_BALL_BREAK_FAIL_LIMIT           (256)
#define MAX_HWA_SATRTUP_PASS_LIMIT                               (256)
#define MAX_HWA_SATRTUP_FAIL_LIMIT                               (256)
#define MIN_DAMPING_ALGO_PASS_LIMIT                              (256)
#define MAX_DAMPING_ALGO_FAIL_LIMIT                              (256)
#define MAX_BLOACKAGE_ALGO_PASS_LIMIT                            (256)
#define MIN_BLOACKAGE_ALGO_FAIL_LIMIT                            (256)
#define MAX_RANGE_ESTIMATION_PASS_LIMIT                          (256)
#define MIN_RANGE_ESTIMATION_PASS_LIMIT                          (256)
#define MAX_RADAR_TRANSCEIVER_MIPI_ADC_PASS_LIMIT                (256)
#define MAX_RADAR_TRANSCEIVER_MIPI_ADC_FAIL_LIMIT                (256)
#define MAX_RADAR_TRANSCEIVER_SAFE_START_PASS_LIMIT              (256)
#define MAX_RADAR_TRANSCEIVER_SAFE_START_FAIL_LIMIT              (256)
#define MAX_RADAR_TRANSCEIVER_SAFETY_INTEGTRITY_CHECK_PASS_LIMIT (256)
#define MAX_RADAR_TRANSCEIVER_SAFETY_INTEGTRITY_CHECK_FAIL_LIMIT (256)
#define MAX_RADAR_TRANSCEIVER_SENSOR_DEAD_PASS_LIMIT             (256)
#define MAX_RADAR_TRANSCEIVER_SENSOR_DEAD_FAIL_LIMIT             (256)
#define MAX_MNR_BLOCKAGE_PASS_LIMIT                              (256)
#define MAX_MNR_BLOCKAGE_FAIL_LIMIT                              (256)
#define MAX_TD_BLOCKAGE_PASS_LIMIT                               (256)
#define MAX_TD_BLOCKAGE_FAIL_LIMIT                               (256)
#define MAX_SIDELOBE_BLOCKAGE_PASS_LIMIT                         (256)
#define MAX_SIDELOBE_BLOCKAGE_FAIL_LIMIT                         (256)
#define MAX_SPT_INTERNAL_PASS_LIMIT                              (256)
#define MAX_SPT_INTERNAL_FAIL_LIMIT                              (256)
#define MAX_CROSS_TRIGGER_ENGINE_CHECKSUM_ERROR_PASS_LIMIT       (256)
#define MAX_CROSS_TRIGGER_ENGINE_CHECKSUM_ERROR_FAIL_LIMIT       (256)
#define MAX_ACQUISITION_OVERFLOW_PASS_LIMIT                      (256)
#define MAX_ACQUISITION_OVERFLOW_FAIL_LIMIT                      (256)
#define MAX_FIRST_PASS_DETECTION_OVERFLOW_PASS_LIMIT             (256)
#define MAX_FIRST_PASS_DETECTION_OVERFLOW_FAIL_LIMIT             (256)
#define MAX_ANGLEFINDING_DOWN_SELECTION_OVERFLOW_PASS_LIMIT      (256)
#define MAX_ANGLEFINDING_DOWN_SELECTION_OVERFLOW_FAIL_LIMIT      (256)
#define MAX_DETECTION_LIST_OVERFLOW_PASS_LIMIT                   (256)
#define MAX_DETECTION_LIST_OVERFLOW_FAIL_LIMIT                   (256)
#define MAX_INTERNAL_TRACKER_ERROR_PASS_LIMIT                    (256)
#define MAX_INTERNAL_TRACKER_ERROR_FAIL_LIMIT                    (256)
#define MAX_LOOK_ID_SEQUENCE_PASS_LIMIT                          (256)
#define MAX_LOOK_ID_SEQUENCE_FAIL_LIMIT                          (256)
#define MAX_SCT_LOCAL_MONITORING_PASS_LIMIT                      (256)
#define MAX_SCT_LOCAL_MONITORING_FAIL_LIMIT                      (256)
#define MAX_INCOMPATIBLE_TIME_STAMP_PASS_LIMIT                   (256)
#define MAX_INCOMPATIBLE_TIME_STAMP_FAIL_LIMIT                   (256)
#define MAX_INTERFERENCE_DETECTION_PASS_LIMIT                    (256)
#define MAX_INTERFERENCE_DETECTION_FAIL_LIMIT                    (256)
#define MAX_C1_CMPU_CONF_PASS_LIMIT                              (256)
#define MAX_C1_CMPU_CONF_FAIL_LIMIT                              (256)
#define MAX_C1_RADAR_POSITION_INVALIDVALUE_PASS_LIMIT            (256)
#define MAX_C1_RADAR_POSITION_INVALIDVALUE_FAIL_LIMIT            (256)
#define MAX_C2_CMPU_CONF_PASS_LIMIT                              (256)
#define MAX_C2_CMPU_CONF_FAIL_LIMIT                              (256)
#define MAX_C2_RADAR_POSITION_INVALIDVALUE_PASS_LIMIT            (256)
#define MAX_C2_RADAR_POSITION_INVALIDVALUE_FAIL_LIMIT            (256)
#define MAX_TRACK_STATUS_MSG_TIMEOUT_PASS_LIMIT                  (256)
#define MAX_TRACK_STATUS_MSG_TIMEOUT_FAIL_LIMIT                  (256)
#define MAX_PCAN_MESSAGE_CORRUPTED_PASS_LIMIT                    (256)
#define MAX_PCAN_MESSAGE_CORRUPTED_FAIL_LIMIT                    (256)
#define MAX_GATEWAY_MSG_CORRUPTION_PCAN_PASS_LIMIT               (256)
#define MAX_GATEWAY_MSG_CORRUPTION_PCAN_FAIL_LIMIT               (256)
#define MAX_OPPOSITE_DETECTION_CORRUPTION_PCAN_PASS_LIMIT        (256)
#define MAX_OPPOSITE_DETECTION_CORRUPTION_PCAN_FAIL_LIMIT        (256)
#define MAX_PCAN_BUS_OFF_PASS_LIMIT                              (256)
#define MAX_PCAN_BUS_OFF_FAIL_LIMIT                              (256)
#define MAX_PCAN_MISSING_MESSAGE_PASS_LIMIT                      (256)
#define MAX_PCAN_MISSING_MESSAGE_FAIL_LIMIT                      (256)
#define MAX_SENSOR_NOT_ALIGNED_PASS_LIMIT                        (256)
#define MAX_SENSOR_NOT_ALIGNED_FAIL_LIMIT                        (256)
#define MAX_HORIZONTAL_ALIGNMENT_OUT_OF_RANGE_PASS_LIMIT         (256)
#define MAX_HORIZONTAL_ALIGNMENT_OUT_OF_RANGE_FAIL_LIMIT         (256)
#define MAX_VERTICAL_ALIGNMENT_OUT_OF_RANGE_PASS_LIMIT           (256)
#define MAX_VERTICAL_ALIGNMENT_OUT_OF_RANGE_FAIL_LIMIT           (256)
#define MAX_ALIGNMENT_ROUTINE_FAILED_PASS_LIMIT                  (256)
#define MAX_ALIGNMENT_ROUTINE_FAILED_FAIL_LIMIT                  (256)
#define MAX_TRANSMITTER_ID_FAULT_PASS_LIMIT                      (256)
#define MAX_TRANSMITTER_ID_FAULT_FAIL_LIMIT                      (256)
#define MAX_FEATURE_FUNCTION_CALIBRATION_CHECKSUM_PASS_LIMIT     (256)
#define MAX_FEATURE_FUNCTION_CALIBRATION_CHECKSUM_FAIL_LIMIT     (256)
#define MAX_TRACKER_CALIBRATION_CHECKSUM_PASS_LIMIT              (256)
#define MAX_TRACKER_CALIBRATION_CHECKSUM_FAIL_LIMIT              (256)
#define MAX_RADAR_TRANSCEIVER_TEMPERATURE_PASS_LIMIT             (256)
#define MAX_RADAR_TRANSCEIVER_TEMPERATURE_FAIL_LIMIT             (256)
#define MAX_TRANSMITTER_ID_PASS_LIMIT                            (256)
#define MAX_TRANSMITTER_ID_FAIL_LIMIT                            (256)
#define MAX_KEEP_ALIVE_CHECKSUM_PASS_LIMIT                       (256)
#define MAX_KEEP_ALIVE_CHECKSUM_FAIL_LIMIT                       (256)
#define MAX_MMIC_A_TIMEOUT_FAIL_LIMIT                            (256)
#define MAX_MMIC_A_TIMEOUT_PASS_LIMIT                            (256)
#define MAX_MMIC_A_SAFETY_INTEGTRITY_RFBIST_FAIL_LIMIT           (256)
#define MAX_MMIC_A_SAFETY_INTEGTRITY_RFBIST_PASS_LIMIT           (256)
#define MAX_MMIC_B_TRANSMITTER_ID_FAIL_LIMIT                     (256)
#define MAX_MMIC_B_TRANSMITTER_ID_PASS_LIMIT                     (256)
#define MAX_MMIC_B_MIPI_ADC_FAIL_LIMIT                           (256)
#define MAX_MMIC_B_MIPI_ADC_PASS_LIMIT                           (256)
#define MAX_MMIC_B_TIMEOUT_FAIL_LIMIT                            (256)
#define MAX_MMIC_B_TIMEOUT_PASS_LIMIT                            (256)
#define MAX_MMIC_B_SAFETY_INTEGTRITY_PFBIST_FAIL_LIMIT           (256)
#define MAX_MMIC_B_SAFETY_INTEGTRITY_PFBIST_PASS_LIMIT           (256)
#define MAX_MMIC_B_SAFE_STRT_FAIL_LIMIT                          (256)
#define MAX_MMIC_B_SAFE_STRT_PASS_LIMIT                          (256)
#define MAX_MMIC_B_SAFETYINT_CHECK_FAIL_LIMIT                    (256)
#define MAX_MMIC_B_SAFETYINT_CHECK_PASS_LIMIT                    (256)
#define MAX_MMIC_B_SENSORDEAD_FAIL_LIMIT                         (256)
#define MAX_MMIC_B_SENSORDEAD_PASS_LIMIT                         (256)
#define MAX_MMIC_B_SPI_TRANSFER_FAIL_LIMIT                       (256)
#define MAX_MMIC_B_SPI_TRANSFER_PASS_LIMIT                       (256)
#define MAX_CM7_TO_DSP_IPC_PASS_LIMIT                            (256)
#define MAX_CM7_TO_DSP_IPC_FAIL_LIMIT                            (256)
#define MAX_DSP_TO_A53_IPC_PASS_LIMIT                            (256)
#define MAX_DSP_TO_A53_IPC_FAIL_LIMIT                            (256)
#define MAX_A53_TO_CM7_IPC_PASS_LIMIT                            (256)
#define MAX_A53_TO_CM7_IPC_FAIL_LIMIT                            (256)
#define MAX_DSP_TO_CM7_IPC_PASS_LIMIT                            (256)
#define MAX_DSP_TO_CM7_IPC_FAIL_LIMIT                            (256)
#define MAX_A53_LOOP_OVERRUN_PASS_LIMIT                          (256)
#define MAX_A53_LOOP_OVERRUN_FAIL_LIMIT                          (256)
#define MAX_A53_TO_M7_IPC_FAULT_FAIL_LIMIT                       (256)
#define MAX_A53_TO_M7_IPC_FAULT_PASS_LIMIT                       (256)
#define MAX_M7_TO_BBE_IPC_FAULT_FAIL_LIMIT                       (256)
#define MAX_M7_TO_BBE_IPC_FAULT_PASS_LIMIT                       (256)
#define MAX_BBE_TO_A53_IPC_FAULT_FAIL_LIMIT                      (256)
#define MAX_BBE_TO_A53_IPC_FAULT_PASS_LIMIT                      (256)
#define MAX_BBE_TO_M7_IPC_FAULT_FAIL_LIMIT                       (256)
#define MAX_BBE_TO_M7_IPC_FAULT_PASS_LIMIT                       (256)
#define MAX_PMIC_MCU_COMMUNICATION_FAIL_LIMIT                    (256)
#define MAX_PMIC_MCU_COMMUNICATION_PASS_LIMIT                    (256)
/**********************************************************************/
/***************** Macros for Min size of calibration *****************/
/**********************************************************************/
#define MIN_SUPPLY_5V_OUT_OF_RANGE_PASS_LIMIT                    (0)
#define MIN_SUPPLY_5V_OUT_OF_RANGE_FAIL_LIMIT                    (0)
#define MIN_SUPPLY_2_3V_OUT_OF_RANGE_PASS_LIMIT                  (0)
#define MIN_SUPPLY_2_3V_OUT_OF_RANGE_FAIL_LIMIT                  (0)
#define MIN_SUPPLY_1_8V_OUT_OF_RANGE_PASS_LIMIT                  (0)
#define MIN_SUPPLY_1_8V_OUT_OF_RANGE_FAIL_LIMIT                  (0)
#define MIN_SUPPLY_1_2_5V_OUT_OF_RANGE_PASS_LIMIT                (0)
#define MIN_SUPPLY_1_2_5V_OUT_OF_RANGE_FAIL_LIMIT                (0)
#define MIN_SUPPLY_1_1V_OUT_OF_RANGE_PASS_LIMIT                  (0)
#define MIN_SUPPLY_1_1V_OUT_OF_RANGE_FAIL_LIMIT                  (0)
#define MIN_SUPPLY_3_3V_TO_MMIC_PASS_LIMIT                       (0)
#define MIN_SUPPLY_3_3V_TO_MMIC_FAIL_LIMIT                       (0)
#define MIN_SUPPLY_0_9V_SUPPLY_OUT_OF_RANGE_PASS_LIMIT           (0)
#define MIN_SUPPLY_0_9V_SUPPLY_OUT_OF_RANGE_FAIL_LIMIT           (0)
#define MIN_SUPPLY_0_8V_OUT_OF_RANGE_PASS_LIMIT                  (0)
#define MIN_SUPPLY_0_8V_OUT_OF_RANGE_FAIL_LIMIT                  (0)
#define MIN_BANDGAP_REFERENCE_VOLTAGE_PASS_LIMIT                 (0)
#define MIN_BANDGAP_REFERENCE_VOLTAGE_FAIL_LIMIT                 (0)
#define MIN_BATTERY_HIGH_PASS_LIMIT                              (0)
#define MIN_BATTERY_HIGH_FAIL_LIMIT                              (0)
#define MIN_BATTERY_LOW_PASS_LIMIT                               (0)
#define MIN_BATTERY_LOW_FAIL_LIMIT                               (0)
#define MIN_APPLICATION_FLASH_CHECKSUM_PASS_LIMIT                (0)
#define MIN_APPLICATION_FLASH_CHECKSUM_FAIL_LIMIT                (0)
#define MIN_SMC_VALIDTN_PASS_LIMIT                               (0)
#define MIN_SMC_VALIDTN_FAIL_LIMIT                               (0)
#define MIN_USC_VALIDATION_PASS_LIMIT                            (0)
#define MIN_USC_VALIDATION_FAIL_LIMIT                            (0)
#define MIN_RAM_MEMORY_TEST_PASS_LIMIT                           (0)
#define MIN_RAM_MEMORY_TEST_FAIL_LIMIT                           (0)
#define MIN_CORE2_CALIBRATION_FLASH_CHECKSUM_PASS_LIMIT          (0)
#define MIN_CORE2_CALIBRATION_FLASH_CHECKSUM_FAIL_LIMIT          (0)
#define MIN_CAN_CONTROLLER_RAM_PASS_LIMIT                        (0)
#define MIN_CAN_CONTROLLER_RAM_FAIL_LIMIT                        (0)
#define MIN_CORE2_TO_CORE0_CRC_PASS_LIMIT                        (0)
#define MIN_CORE2_TO_CORE0_CRC_FAIL_LIMIT                        (0)
#define MIN_CORE0_TO_CORE2_CRC_PASS_LIMIT                        (0)
#define MIN_CORE0_TO_CORE2_CRC_FAIL_LIMIT                        (0)
#define MIN_CORE1_TO_CORE2_CRC_PASS_LIMIT                        (0)
#define MIN_CORE1_TO_CORE2_CRC_FAIL_LIMIT                        (0)
#define MIN_CORE2_TO_CORE1_CRC_PASS_LIMIT                        (0)
#define MIN_CORE2_TO_CORE1_CRC_FAIL_LIMIT                        (0)
#define MIN_CORE0_TO_CORE1_CRC_PASS_LIMIT                        (0)
#define MIN_CORE0_TO_CORE1_CRC_FAIL_LIMIT                        (0)
#define MIN_CORE1_TO_CORE0_CRC_PASS_LIMIT                        (0)
#define MIN_CORE1_TO_CORE0_CRC_FAIL_LIMIT                        (0)
#define MIN_THERMISTOR_OUT_OF_RANGE_PASS_LIMIT                   (0)
#define MIN_THERMISTOR_OUT_OF_RANGE_FAIL_LIMIT                   (0)
#define MIN_MICROPROCESSOR_TEMP_HIGH_PASS_LIMIT                  (0)
#define MIN_MICROPROCESSOR_TEMP_HIGH_FAIL_LIMIT                  (0)
#define MIN_ECU_TEMPERATURE_HIGH_PASS_LIMIT                      (0)
#define MIN_ECU_TEMPERATURE_HIGH_FAIL_LIMIT                      (0)
#define MIN_MICROPROCESSOR_TEMP_LOW_PASS_LIMIT                   (0)
#define MIN_MICROPROCESSOR_TEMP_LOW_FAIL_LIMIT                   (0)
#define MIN_PLL_LOCK_PASS_LIMIT                                  (0)
#define MIN_PLL_LOCK_FAIL_LIMIT                                  (0)
#define MIN_INSTRUCTION_SET_CHECK_PASS_LIMIT                     (0)
#define MIN_INSTRUCTION_SET_CHECK_FAIL_LIMIT                     (0)
#define MIN_STACK_OVERFLOW_PASS_LIMIT                            (0)
#define MIN_STACK_OVERFLOW_FAIL_LIMIT                            (0)
#define MIN_DSP_LOOP_OVERRUN_PASS_LIMIT                          (0)
#define MIN_DSP_LOOP_OVERRUN_FAIL_LIMIT                          (0)
#define MIN_CORE2_LOOP_OVERRUN_PASS_LIMIT                        (0)
#define MIN_CORE2_LOOP_OVERRUN_FAIL_LIMIT                        (0)
#define MIN_RRU_CORE_PASS_LIMIT                                  (0)
#define MIN_RRU_CORE_FAIL_LIMIT                                  (0)
#define MIN_MCU_REPETITIVE_RESET_PASS_LIMIT                      (0)
#define MIN_MCU_REPETITIVE_RESET_FAIL_LIMIT                      (0)
#define MIN_SW_EXCEPTION_RESET_REASON_PASS_LIMIT                 (0)
#define MIN_SW_EXCEPTION_RESET_REASON_FAIL_LIMIT                 (0)
#define MIN_MCU_STARTUP_PASS_LIMIT                               (0)
#define MIN_MCU_STARTUP_FAIL_LIMIT                               (0)
#define MIN_PLATFORM_TIME_PASS_LIMIT                             (0)
#define MIN_PLATFORM_TIME_FAIL_LIMIT                             (0)
#define MIN_INTERNAL_WATCHDOG_PASS_LIMIT                         (0)
#define MIN_INTERNAL_WATCHDOG_FAIL_LIMIT                         (0)
#define MIN_SPT_WATCHDOG_PASS_LIMIT                              (0)
#define MIN_SPT_WATCHDOG_FAIL_LIMIT                              (0)
#define MIN_CORE1_AND_CORE2_SW_WATCHDOG_PASS_LIMIT               (0)
#define MIN_CORE1_AND_CORE2_SW_WATCHDOG_FAIL_LIMIT               (0)
#define MIN_CORE1_AND_CORE2_PROGRAM_FLOW_ERROR_PASS_LIMIT        (0)
#define MIN_CORE1_AND_CORE2_PROGRAM_FLOW_ERROR_FAIL_LIMIT        (0)
#define MIN_MMIC_1_8_SUPPLY_PASS_LIMIT                           (0)
#define MIN_MMIC_1_8_SUPPLY_FAIL_LIMIT                           (0)
#define MIN_MMIC_1_1V_SUPPLY_PASS_LIMIT                          (0)
#define MIN_MMIC_1_1V_SUPPLY_FAIL_LIMIT                          (0)
#define MIN_DOLPHIN_TIMEOUT_PASS_LIMIT                           (0)
#define MIN_DOLPHIN_TIMEOUT_FAIL_LIMIT                           (0)
#define MIN_RADAR_TRANSCEIVER_SPI_PASS_LIMIT                     (0)
#define MIN_RADAR_TRANSCEIVER_SPI_FAIL_LIMIT                     (0)
#define MIN_RADAR_TRANSCEIVER_CHIRP_PLL_PASS_LIMIT               (0)
#define MIN_RADAR_TRANSCEIVER_CHIRP_PLL_FAIL_LIMIT               (0)
#define MIN_RADAR_TRANSCEIVER_RF_BALL_BREAK_PASS_LIMIT           (0)
#define MIN_RADAR_TRANSCEIVER_RF_BALL_BREAK_FAIL_LIMIT           (0)
#define MIN_HWA_SATRTUP_PASS_LIMIT                               (0)
#define MIN_HWA_SATRTUP_FAIL_LIMIT                               (0)
#define MIN_RADAR_TRANSCEIVER_MIPI_ADC_PASS_LIMIT                (0)
#define MIN_RADAR_TRANSCEIVER_MIPI_ADC_FAIL_LIMIT                (0)
#define MIN_RADAR_TRANSCEIVER_SAFE_START_PASS_LIMIT              (0)
#define MIN_RADAR_TRANSCEIVER_SAFE_START_FAIL_LIMIT              (0)
#define MIN_RADAR_TRANSCEIVER_SAFETY_INTEGTRITY_CHECK_PASS_LIMIT (0)
#define MIN_RADAR_TRANSCEIVER_SAFETY_INTEGTRITY_CHECK_FAIL_LIMIT (0)
#define MIN_RADAR_TRANSCEIVER_SENSOR_DEAD_PASS_LIMIT             (0)
#define MIN_RADAR_TRANSCEIVER_SENSOR_DEAD_FAIL_LIMIT             (0)
#define MIN_MNR_BLOCKAGE_PASS_LIMIT                              (0)
#define MIN_MNR_BLOCKAGE_FAIL_LIMIT                              (0)
#define MIN_TD_BLOCKAGE_PASS_LIMIT                               (0)
#define MIN_TD_BLOCKAGE_FAIL_LIMIT                               (0)
#define MIN_SIDELOBE_BLOCKAGE_PASS_LIMIT                         (0)
#define MIN_SIDELOBE_BLOCKAGE_FAIL_LIMIT                         (0)
#define MIN_SPT_INTERNAL_PASS_LIMIT                              (0)
#define MIN_SPT_INTERNAL_FAIL_LIMIT                              (0)
#define MIN_CROSS_TRIGGER_ENGINE_CHECKSUM_ERROR_PASS_LIMIT       (0)
#define MIN_CROSS_TRIGGER_ENGINE_CHECKSUM_ERROR_FAIL_LIMIT       (0)
#define MIN_ACQUISITION_OVERFLOW_PASS_LIMIT                      (0)
#define MIN_ACQUISITION_OVERFLOW_FAIL_LIMIT                      (0)
#define MIN_FIRST_PASS_DETECTION_OVERFLOW_PASS_LIMIT             (0)
#define MIN_FIRST_PASS_DETECTION_OVERFLOW_FAIL_LIMIT             (0)
#define MIN_ANGLEFINDING_DOWN_SELECTION_OVERFLOW_PASS_LIMIT      (0)
#define MIN_ANGLEFINDING_DOWN_SELECTION_OVERFLOW_FAIL_LIMIT      (0)
#define MIN_DETECTION_LIST_OVERFLOW_PASS_LIMIT                   (0)
#define MIN_DETECTION_LIST_OVERFLOW_FAIL_LIMIT                   (0)
#define MIN_INTERNAL_TRACKER_ERROR_PASS_LIMIT                    (0)
#define MIN_INTERNAL_TRACKER_ERROR_FAIL_LIMIT                    (0)
#define MIN_LOOK_ID_SEQUENCE_PASS_LIMIT                          (0)
#define MIN_LOOK_ID_SEQUENCE_FAIL_LIMIT                          (0)
#define MIN_SCT_LOCAL_MONITORING_PASS_LIMIT                      (0)
#define MIN_SCT_LOCAL_MONITORING_FAIL_LIMIT                      (0)
#define MIN_INCOMPATIBLE_TIME_STAMP_PASS_LIMIT                   (0)
#define MIN_INCOMPATIBLE_TIME_STAMP_FAIL_LIMIT                   (0)
#define MIN_INTERFERENCE_DETECTION_PASS_LIMIT                    (0)
#define MIN_INTERFERENCE_DETECTION_FAIL_LIMIT                    (0)
#define MIN_C1_CMPU_CONF_PASS_LIMIT                              (0)
#define MIN_C1_CMPU_CONF_FAIL_LIMIT                              (0)
#define MIN_C1_RADAR_POSITION_INVALIDVALUE_PASS_LIMIT            (0)
#define MIN_C1_RADAR_POSITION_INVALIDVALUE_FAIL_LIMIT            (0)
#define MIN_C2_CMPU_CONF_PASS_LIMIT                              (0)
#define MIN_C2_CMPU_CONF_FAIL_LIMIT                              (0)
#define MIN_C2_RADAR_POSITION_INVALIDVALUE_PASS_LIMIT            (0)
#define MIN_C2_RADAR_POSITION_INVALIDVALUE_FAIL_LIMIT            (0)
#define MIN_TRACK_STATUS_MSG_TIMEOUT_PASS_LIMIT                  (0)
#define MIN_TRACK_STATUS_MSG_TIMEOUT_FAIL_LIMIT                  (0)
#define MIN_PCAN_MESSAGE_CORRUPTED_PASS_LIMIT                    (0)
#define MIN_PCAN_MESSAGE_CORRUPTED_FAIL_LIMIT                    (0)
#define MIN_GATEWAY_MSG_CORRUPTION_PCAN_PASS_LIMIT               (0)
#define MIN_GATEWAY_MSG_CORRUPTION_PCAN_FAIL_LIMIT               (0)
#define MIN_OPPOSITE_DETECTION_CORRUPTION_PCAN_PASS_LIMIT        (0)
#define MIN_OPPOSITE_DETECTION_CORRUPTION_PCAN_FAIL_LIMIT        (0)
#define MIN_PCAN_BUS_OFF_PASS_LIMIT                              (0)
#define MIN_PCAN_BUS_OFF_FAIL_LIMIT                              (0)
#define MIN_PCAN_MISSING_MESSAGE_PASS_LIMIT                      (0)
#define MIN_PCAN_MISSING_MESSAGE_FAIL_LIMIT                      (0)
#define MIN_SENSOR_NOT_ALIGNED_PASS_LIMIT                        (0)
#define MIN_SENSOR_NOT_ALIGNED_FAIL_LIMIT                        (0)
#define MIN_HORIZONTAL_ALIGNMENT_OUT_OF_RANGE_PASS_LIMIT         (0)
#define MIN_HORIZONTAL_ALIGNMENT_OUT_OF_RANGE_FAIL_LIMIT         (0)
#define MIN_VERTICAL_ALIGNMENT_OUT_OF_RANGE_PASS_LIMIT           (0)
#define MIN_VERTICAL_ALIGNMENT_OUT_OF_RANGE_FAIL_LIMIT           (0)
#define MIN_ALIGNMENT_ROUTINE_FAILED_PASS_LIMIT                  (0)
#define MIN_ALIGNMENT_ROUTINE_FAILED_FAIL_LIMIT                  (0)
#define MIN_TRANSMITTER_ID_FAULT_PASS_LIMIT                      (0)
#define MIN_TRANSMITTER_ID_FAULT_FAIL_LIMIT                      (0)
#define MIN_FEATURE_FUNCTION_CALIBRATION_CHECKSUM_PASS_LIMIT     (0)
#define MIN_FEATURE_FUNCTION_CALIBRATION_CHECKSUM_FAIL_LIMIT     (0)
#define MIN_TRACKER_CALIBRATION_CHECKSUM_PASS_LIMIT              (0)
#define MIN_TRACKER_CALIBRATION_CHECKSUM_FAIL_LIMIT              (0)
#define MIN_RADAR_TRANSCEIVER_TEMPERATURE_PASS_LIMIT             (0)
#define MIN_RADAR_TRANSCEIVER_TEMPERATURE_FAIL_LIMIT             (0)
#define MIN_TRANSMITTER_ID_PASS_LIMIT                            (0)
#define MIN_TRANSMITTER_ID_FAIL_LIMIT                            (0)
#define MIN_KEEP_ALIVE_CHECKSUM_PASS_LIMIT                       (0)
#define MIN_KEEP_ALIVE_CHECKSUM_FAIL_LIMIT                       (0)
#define MIN_MMIC_A_TIMEOUT_FAIL_LIMIT                            (0)
#define MIN_MMIC_A_TIMEOUT_PASS_LIMIT                            (0)
#define MIN_MMIC_A_SAFETY_INTEGTRITY_RFBIST_FAIL_LIMIT           (0)
#define MIN_MMIC_A_SAFETY_INTEGTRITY_RFBIST_PASS_LIMIT           (0)
#define MIN_MMIC_B_TRANSMITTER_ID_FAIL_LIMIT                     (0)
#define MIN_MMIC_B_TRANSMITTER_ID_PASS_LIMIT                     (0)
#define MIN_MMIC_B_MIPI_ADC_FAIL_LIMIT                           (0)
#define MIN_MMIC_B_MIPI_ADC_PASS_LIMIT                           (0)
#define MIN_MMIC_B_TIMEOUT_FAIL_LIMIT                            (0)
#define MIN_MMIC_B_TIMEOUT_PASS_LIMIT                            (0)
#define MIN_MMIC_B_SAFETY_INTEGTRITY_PFBIST_FAIL_LIMIT           (0)
#define MIN_MMIC_B_SAFETY_INTEGTRITY_PFBIST_PASS_LIMIT           (0)
#define MIN_MMIC_B_SAFE_STRT_FAIL_LIMIT                          (0)
#define MIN_MMIC_B_SAFE_STRT_PASS_LIMIT                          (0)
#define MIN_MMIC_B_SAFETYINT_CHECK_FAIL_LIMIT                    (0)
#define MIN_MMIC_B_SAFETYINT_CHECK_PASS_LIMIT                    (0)
#define MIN_MMIC_B_SENSORDEAD_FAIL_LIMIT                         (0)
#define MIN_MMIC_B_SENSORDEAD_PASS_LIMIT                         (0)
#define MIN_MMIC_B_SPI_TRANSFER_FAIL_LIMIT                       (0)
#define MIN_MMIC_B_SPI_TRANSFER_PASS_LIMIT                       (0)
#define MIN_CM7_TO_DSP_IPC_PASS_LIMIT                            (0)
#define MIN_CM7_TO_DSP_IPC_FAIL_LIMIT                            (0)
#define MIN_DSP_TO_A53_IPC_PASS_LIMIT                            (0)
#define MIN_DSP_TO_A53_IPC_FAIL_LIMIT                            (0)
#define MIN_A53_TO_CM7_IPC_PASS_LIMIT                            (0)
#define MIN_A53_TO_CM7_IPC_FAIL_LIMIT                            (0)
#define MIN_DSP_TO_CM7_IPC_PASS_LIMIT                            (0)
#define MIN_DSP_TO_CM7_IPC_FAIL_LIMIT                            (0)
#define MIN_A53_LOOP_OVERRUN_PASS_LIMIT                          (0)
#define MIN_A53_LOOP_OVERRUN_FAIL_LIMIT                          (0)
#define MIN_A53_TO_M7_IPC_FAULT_FAIL_LIMIT                       (0)
#define MIN_A53_TO_M7_IPC_FAULT_PASS_LIMIT                       (0)
#define MIN_M7_TO_BBE_IPC_FAULT_FAIL_LIMIT                       (0)
#define MIN_M7_TO_BBE_IPC_FAULT_PASS_LIMIT                       (0)
#define MIN_BBE_TO_A53_IPC_FAULT_FAIL_LIMIT                      (0)
#define MIN_BBE_TO_A53_IPC_FAULT_PASS_LIMIT                      (0)
#define MIN_BBE_TO_M7_IPC_FAULT_FAIL_LIMIT                       (0)
#define MIN_BBE_TO_M7_IPC_FAULT_PASS_LIMIT                       (0)
#define MIN_PMIC_MCU_COMMUNICATION_FAIL_LIMIT                    (0)
#define MIN_PMIC_MCU_COMMUNICATION_PASS_LIMIT                    (0)

#define Diag_PLT_Fault_Threshold_Size (56)

#define PSC_H3_DIAG_PLT_FAULT_THRESHOLD_CAL_TYPE              (0U)
#define PSC_H3_DIAG_PLT_FAULT_THRESHOLD_UNUSED1               (0U)
#define PSC_H3_DIAG_PLT_FAULT_THRESHOLD_UNUSED2               (0U)
#define PSC_H3_DIAG_PLT_FAULT_THRESHOLD_SECTION_COMPATIBILITY (0U)
#define PSC_H3_DIAG_PLT_FAULT_THRESHOLD_VERSION               (0U)
#define PSC_H3_DIAG_PLT_FAULT_THRESHOLD_SECTION_SIZE          (56U)

#ifndef PC_RESIM

typedef struct Diag_PLT_Fault_Threshold_Cal_Tag
{
   H3_Hdr_T Header;
   s8p7_T k_MicroTemp_Low;
   s8p7_T k_MicroTemp_High;
   s8p7_T k_MicroTemp_recovery_offset;
   u16p0_T k_onboardThermistorValid_max;
   u16p0_T k_onboardThermistorValid_min;
   s8p7_T k_ECUTemp_High;
   s8p7_T k_ECUTemp_recovery_offset;
   u6p10_T k_5V_High;
   u6p10_T k_5V_Low;
   u6p10_T k_1_8V_High;
   u6p10_T k_1_8V_Low;
   u6p10_T k_2_3V_High;
   u6p10_T k_2_3V_Low;
   u6p10_T k_1_2_5V_High;
   u6p10_T k_1_2_5V_Low;
   u6p10_T k_1_1V_High;
   u6p10_T k_1_1V_Low;
   u6p10_T k_0_8V_High;
   u6p10_T k_0_8V_Low;
   u6p10_T k_3_3V_High;
   u6p10_T k_3_3V_Low;
} Diag_PLT_Fault_Threshold_Cal_T;

#else

typedef struct Diag_PLT_Fault_Threshold_Cal_Tag
{
   u6p10_T k_3_3V_Low;
   u6p10_T k_3_3V_High;
   u6p10_T k_0_8V_Low;
   u6p10_T k_0_8V_High;
   u6p10_T k_1_1V_Low;
   u6p10_T k_1_1V_High;
   u6p10_T k_1_2_5V_Low;
   u6p10_T k_1_2_5V_High;
   u6p10_T k_2_3V_Low;
   u6p10_T k_2_3V_High;
   u6p10_T k_1_8V_Low;
   u6p10_T k_1_8V_High;
   u6p10_T k_5V_Low;
   u6p10_T k_5V_High;
   s8p7_T k_ECUTemp_recovery_offset;
   s8p7_T k_ECUTemp_High;
   u16p0_T k_onboardThermistorValid_min;
   u16p0_T k_onboardThermistorValid_max;
   s8p7_T k_MicroTemp_recovery_offset;
   s8p7_T k_MicroTemp_High;
   s8p7_T k_MicroTemp_Low;
   H3_Hdr_T Header;
} Diag_PLT_Fault_Threshold_Cal_T;

#endif
/**********************************************************************/
/***************** Macros for Max size of calibration *****************/
/**********************************************************************/
#define MAX_K_MICROTEMP_LOW              1
#define MAX_K_MICROTEMP_HIGH             1
#define MAX_K_MICROTEMP_RECOVERY_OFFSET  1
#define MAX_K_ONBOARDTHERMISTORVALID_MAX 1
#define MAX_K_ONBOARDTHERMISTORVALID_MIN 1
#define MAX_K_ECUTEMP_HIGH               1
#define MAX_K_ECUTEMP_RECOVERY_OFFSET    1
#define MAX_K_5V_HIGH                    1
#define MAX_K_5V_LOW                     1
#define MAX_K_1_8V_HIGH                  1
#define MAX_K_1_8V_LOW                   1
#define MAX_K_2_3V_HIGH                  1
#define MAX_K_2_3V_LOW                   1
#define MAX_K_1_2_5V_HIGH                1
#define MAX_K_1_2_5V_LOW                 1
#define MAX_K_1_1V_HIGH                  1
#define MAX_K_1_1V_LOW                   1
#define MAX_K_0_8V_HIGH                  1
#define MAX_K_0_8V_LOW                   1
#define MAX_K_3_3V_HIGH                  1
#define MAX_K_3_3V_LOW                   1

/**********************************************************************/
/***************** Macros for Min size of calibration *****************/
/**********************************************************************/
#define MIN_K_MICROTEMP_LOW              0
#define MIN_K_MICROTEMP_HIGH             0
#define MIN_K_MICROTEMP_RECOVERY_OFFSET  0
#define MIN_K_ONBOARDTHERMISTORVALID_MAX 0
#define MIN_K_ONBOARDTHERMISTORVALID_MIN -1.3089
#define MIN_K_ECUTEMP_HIGH               0
#define MIN_K_ECUTEMP_RECOVERY_OFFSET    0
#define MIN_K_5V_HIGH                    0
#define MIN_K_5V_LOW                     0
#define MIN_K_1_8V_HIGH                  0
#define MIN_K_1_8V_LOW                   0
#define MIN_K_2_3V_HIGH                  0
#define MIN_K_2_3V_LOW                   0
#define MIN_K_1_2_5V_HIGH                0
#define MIN_K_1_2_5V_LOW                 0
#define MIN_K_1_1V_HIGH                  0
#define MIN_K_1_1V_LOW                   0
#define MIN_K_0_8V_HIGH                  0
#define MIN_K_0_8V_LOW                   0
#define MIN_K_3_3V_HIGH                  0
#define MIN_K_3_3V_LOW                   0

#define Diag_Cust_Debouncing_Size (16)

#define PSC_H3_DIAG_CUST_DEBOUNCING_CAL_TYPE              (0U)
#define PSC_H3_DIAG_CUST_DEBOUNCING_UNUSED1               (0U)
#define PSC_H3_DIAG_CUST_DEBOUNCING_UNUSED2               (0U)
#define PSC_H3_DIAG_CUST_DEBOUNCING_SECTION_COMPATIBILITY (0U)
#define PSC_H3_DIAG_CUST_DEBOUNCING_VERSION               (0U)
#define PSC_H3_DIAG_CUST_DEBOUNCING_SECTION_SIZE          (16U)

#ifndef PC_RESIM

typedef struct Diag_Cust_Debouncing_Cal_Tag
{
   H3_Hdr_T header;
   u8p0_T dummy_pass_limit;
} Diag_Cust_Debouncing_Cal_T;

#else

typedef struct Diag_Cust_Debouncing_Cal_Tag
{
   u8p0_T dummy_pass_limit;
   H3_Hdr_T Header;
} Diag_Cust_Debouncing_Cal_T;

#endif

/**********************************************************************/
/***************** Macros for Max size of calibration *****************/
/**********************************************************************/
#define MAX_DUMMY_PASS_LIMIT                  (256)
#define MAX_SUPPLY_5V_OUT_OF_RANGE_FAIL_LIMIT (256)

/**********************************************************************/
/***************** Macros for Min size of calibration *****************/
/**********************************************************************/
#define MIN_DUMMY_PASS_LIMIT                  (0)
#define MIN_SUPPLY_5V_OUT_OF_RANGE_FAIL_LIMIT (0)

#define Diag_Cust_Fault_Threshold_Size (16)

#define PSC_H3_DIAG_CUST_FAULT_THRESHOLD_CAL_TYPE              (0U)
#define PSC_H3_DIAG_CUST_FAULT_THRESHOLD_UNUSED1               (0U)
#define PSC_H3_DIAG_CUST_FAULT_THRESHOLD_UNUSED2               (0U)
#define PSC_H3_DIAG_CUST_FAULT_THRESHOLD_SECTION_COMPATIBILITY (0U)
#define PSC_H3_DIAG_CUST_FAULT_THRESHOLD_VERSION               (0U)
#define PSC_H3_DIAG_CUST_FAULT_THRESHOLD_SECTION_SIZE          (16U)

#ifndef PC_RESIM

typedef struct Diag_Cust_Fault_Threshold_Cal_Tag
{
   H3_Hdr_T header;
   u8p0_T dummy_threshold;
} Diag_Cust_Fault_Threshold_Cal_T;

#else

typedef struct Diag_Cust_Fault_Threshold_Cal_Tag
{
   u8p0_T dummy_threshold;
   H3_Hdr_T header;
} Diag_Cust_Fault_Threshold_Cal_T;

#endif

/**********************************************************************/
/***************** Macros for Max size of calibration *****************/
/**********************************************************************/
#define MAX_DUMMY_THRESHOLD (256)

/**********************************************************************/
/***************** Macros for Min size of calibration *****************/
/**********************************************************************/
#define MIN_DUMMY_THRESHOLD (0)

#define Volt_Monitor_Size (48)

#ifndef PC_RESIM

typedef struct Volt_Monitor_Cal_Tag
{
   H3_Hdr_T header;
   u6p10_T k_norm_vmin;
   u6p10_T k_norm_vmax;
   u6p10_T k_L0_V1max;
   u6p10_T k_L0_V1min;
   u6p10_T k_L0_V2max;
   u6p10_T k_HI_V1min;
   u16p0_T k_HI_V1max;
   u16p0_T k_HI_V2min;
   u16p0_T k_VRMtimeTolowV2;
   u16p0_T k_VRMtimeTolowV1;
   u16p0_T k_VRMtimelowVtempToNorm;
   u16p0_T k_VRMtimelowV1ToNorm;
   u16p0_T k_VRMtimelowV2ToNorm;
   u16p0_T k_VRMtimeTohighV2;
   u16p0_T k_VRMtimeTohighV1;
   u16p0_T k_VRMtimehighVtempToNorm;
   u16p0_T k_VRMtimehighV1ToNorm;
   u16p0_T k_VRMtimehighV2ToNorm;
} Volt_Monitor_Cal_T;

#else

typedef struct Volt_Monitor_Cal_Tag
{
   u16p0_T k_VRMtimehighV2ToNorm;
   u16p0_T k_VRMtimehighV1ToNorm;
   u16p0_T k_VRMtimehighVtempToNorm;
   u16p0_T k_VRMtimeTohighV1;
   u16p0_T k_VRMtimeTohighV2;
   u16p0_T k_VRMtimelowV2ToNorm;
   u16p0_T k_VRMtimelowV1ToNorm;
   u16p0_T k_VRMtimelowVtempToNorm;
   u16p0_T k_VRMtimeTolowV1;
   u16p0_T k_VRMtimeTolowV2;
   u16p0_T k_HI_V2min;
   u16p0_T k_HI_V1max;
   u6p10_T k_HI_V1min;
   u6p10_T k_L0_V2max;
   u6p10_T k_L0_V1min;
   u6p10_T k_L0_V1max;
   u6p10_T k_norm_vmax;
   u6p10_T k_norm_vmin;
   H3_Hdr_T header;
} Volt_Monitor_Cal_T;

#endif

/**********************************************************************/
/***************** Macros for Max size of calibration *****************/
/**********************************************************************/
#define MAX_K_NORM_VMIN
#define MAX_K_NORM_VMAX
#define MAX_K_L0_V1MAX
#define MAX_K_L0_V1MIN
#define MAX_K_L0_V2MAX
#define MAX_K_HI_V1MIN
#define MAX_K_HI_V1MAX
#define MAX_K_HI_V2MIN
#define MAX_K_VRMTIMETOLOWV2
#define MAX_K_VRMTIMETOLOWV1
#define MAX_K_VRMTIMELOWVTEMPTONORM
#define MAX_K_VRMTIMELOWV1TONORM
#define MAX_K_VRMTIMELOWV2TONORM
#define MAX_K_VRMTIMETOHIGHV2
#define MAX_K_VRMTIMETOHIGHV1
#define MAX_K_VRMTIMEHIGHVTEMPTONORM
#define MAX_K_VRMTIMEHIGHV1TONORM
#define MAX_K_VRMTIMEHIGHV2TONORM

/**********************************************************************/
/***************** Macros for Min size of calibration *****************/
/**********************************************************************/
#define MIN_K_NORM_VMIN
#define MIN_K_NORM_VMAX
#define MIN_K_L0_V1MAX
#define MIN_K_L0_V1MIN
#define MIN_K_L0_V2MAX
#define MIN_K_HI_V1MIN
#define MIN_K_HI_V1MAX
#define MIN_K_HI_V2MIN
#define MIN_K_VRMTIMETOLOWV2
#define MIN_K_VRMTIMETOLOWV1
#define MIN_K_VRMTIMELOWVTEMPTONORM
#define MIN_K_VRMTIMELOWV1TONORM
#define MIN_K_VRMTIMELOWV2TONORM
#define MIN_K_VRMTIMETOHIGHV2
#define MIN_K_VRMTIMETOHIGHV1
#define MIN_K_VRMTIMEHIGHVTEMPTONORM
#define MIN_K_VRMTIMEHIGHV1TONORM
#define MIN_K_VRMTIMEHIGHV2TONORM

#define k_norm_vmin_V              Get_Volt_Monitor_Cal()->k_norm_vmin
#define k_norm_vmax_V              Get_Volt_Monitor_Cal()->k_norm_vmax
#define k_L0_V1max_V               Get_Volt_Monitor_Cal()->k_L0_V1max
#define k_L0_V1min_V               Get_Volt_Monitor_Cal()->k_L0_V1min
#define k_L0_V2max_V               Get_Volt_Monitor_Cal()->k_L0_V2max
#define k_HI_V1min_V               Get_Volt_Monitor_Cal()->k_HI_V1min
#define k_HI_V1max_V               Get_Volt_Monitor_Cal()->k_HI_V1max
#define k_HI_V2min_V               Get_Volt_Monitor_Cal()->k_HI_V2min
#define k_VRMtimeTolowV2_V         Get_Volt_Monitor_Cal()->k_VRMtimeTolowV2
#define k_VRMtimeTolowV1_V         Get_Volt_Monitor_Cal()->k_VRMtimeTolowV1
#define k_VRMtimelowVtempToNorm_V  Get_Volt_Monitor_Cal()->k_VRMtimelowVtempToNorm
#define k_VRMtimelowV1ToNorm_V     Get_Volt_Monitor_Cal()->k_VRMtimelowV1ToNorm
#define k_VRMtimelowV2ToNorm_V     Get_Volt_Monitor_Cal()->k_VRMtimelowV2ToNorm
#define k_VRMtimeTohighV2_V        Get_Volt_Monitor_Cal()->k_VRMtimeTohighV2
#define k_VRMtimeTohighV1_V        Get_Volt_Monitor_Cal()->k_VRMtimeTohighV1
#define k_VRMtimehighVtempToNorm_V Get_Volt_Monitor_Cal()->k_VRMtimehighVtempToNorm
#define k_VRMtimehighV1ToNorm_V    Get_Volt_Monitor_Cal()->k_VRMtimehighV1ToNorm
#define k_VRMtimehighV2ToNorm_V    Get_Volt_Monitor_Cal()->k_VRMtimehighV2ToNorm

#ifndef PC_RESIM

typedef struct PSC_Cal_Tag
{
   H2_Hdr_T Header2_Info;
   Diag_PLT_Debouncing_Cal_T Diag_PLT_Debouncing_Cal;
   Diag_PLT_Fault_Threshold_Cal_T Diag_PLT_Fault_Threshold_Cal;
   Diag_Cust_Debouncing_Cal_T Diag_Cust_Debouncing_Cal;
   Diag_Cust_Fault_Threshold_Cal_T Diag_Cust_Fault_Threshold_Cal;
} PSC_Cal_T;

#else

typedef struct PSC_Cal_Tag
{
   Diag_Cust_Fault_Threshold_Cal_T Diag_Cust_Fault_Threshold_Cal;
   Diag_Cust_Debouncing_Cal_T Diag_Cust_Debouncing_Cal;
   Diag_PLT_Fault_Threshold_Cal_T Diag_PLT_Fault_Threshold_Cal;
   Diag_PLT_Debouncing_Cal_T Diag_PLT_Debouncing_Cal;
   H2_Hdr_T Header2_Info;
} PSC_Cal_T;

#endif

/* Eumeration ID sub-calibration name */
#define PSC_CAL_TABLE(DCS_X)                                                                                                      \
   DCS_X(DIAG_PLT_DEBOUNCING, Diag_PLT_Debouncing)                                                                                \
   DCS_X(DIAG_PLT_FAULT_THRESHOLD, Diag_PLT_Fault_Threshold)                                                                      \
   DCS_X(DIAG_CUST_DEBOUNCING, Diag_Cust_Debouncing)                                                                              \
   DCS_X(DIAG_CUST_FAULT_THRESHOLD, Diag_Cust_Fault_Threshold)

#define PSC_CAL_ID_ENUM(id, name) id,

typedef enum PSC_Cal_Idx_Tag
{
   PSC_CAL_TABLE(PSC_CAL_ID_ENUM) MAX_NUM_PSC_CALS
} PSC_Cal_Idx_T;

typedef enum Proj_Electrical_System_Tag
{
   PROJ_ELECTRICAL_SYSTEM_8_32V = 0U,
   PROJ_ELECTRICAL_SYSTEM_12V   = 1U,
   PROJ_ELECTRICAL_SYSTEM_24V   = 2U
} Proj_Electrical_System_T;

#ifndef PROJ_ELECTRICAL_SYSTEM_CFG
   #define PROJ_ELECTRICAL_SYSTEM_CFG PROJ_ELECTRICAL_SYSTEM_8_32V
#endif

#ifdef __cplusplus
extern "C"
{
#endif

   extern volatile u8p0_T Proj_Electrical_System;
   /* Returns board/variant-specific voltage monitor calibration at runtime. */
   extern Volt_Monitor_Cal_T *Get_Volt_Monitor_Cal_Impl(void);

#ifdef __cplusplus
}
#endif

#define Get_PSC_Cal_Sec_Def() (&PSC_Cal_Sec_Def[0])

#define Get_PSC_Cal_Data() (PSC_Cal_Data_Ptr)

#define Get_Diag_PLT_Debouncing_Cal()       (&PSC_Cal_Data_Ptr->Diag_PLT_Debouncing_Cal)
#define Get_Diag_PLT_Fault_Threshold_Cal()  (&PSC_Cal_Data_Ptr->Diag_PLT_Fault_Threshold_Cal)
#define Get_Diag_Cust_Debouncing_Cal()      (&PSC_Cal_Data_Ptr->Diag_Cust_Debouncing_Cal)
#define Get_Diag_Cust_Fault_Threshold_Cal() (&PSC_Cal_Data_Ptr->Diag_Cust_Fault_Threshold_Cal)

#define Get_Volt_Monitor_Cal() (Get_Volt_Monitor_Cal_Impl())

/* version info */
#define Get_PSC_Cal_Major()    (PSC_Cal_Data_Ptr->Header2_Info.section_compatibility)
#define Get_PSC_Cal_Minor()    (PSC_Cal_Data_Ptr->Header2_Info.customer)
#define Get_PSC_Cal_Platform() (PSC_Cal_Data_Ptr->Header2_Info.platform)
#define Get_PSC_Cal_Patch()    (PSC_Cal_Data_Ptr->Header2_Info.version)

extern PSC_Cal_T PSC_Cal_Data;
extern PSC_Cal_T *PSC_Cal_Data_Ptr;

extern Cal_Section_Def_T PSC_Cal_Sec_Def[MAX_NUM_PSC_CALS];

/*
 *     _   ___ _____ _____   __
 *    /_\ | _ \_   _|_ _\ \ / /
 *   / _ \|  _/ | |  | | \ V /
 *  /_/ \_\_|   |_| |___| \_/
 *
 */
#endif /* _PSC_CAL_H */
