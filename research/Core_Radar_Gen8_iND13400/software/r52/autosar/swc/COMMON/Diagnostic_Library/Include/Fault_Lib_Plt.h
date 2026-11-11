#ifndef FAULT_LIB_PLT_H
#define FAULT_LIB_PLT_H

/**\file
 *
 * Brief description of the file ends at this dot. Detailed decription
 * follows here
 *
 * \b Project:              Autosar Platform \n
 * \b Application:          Fault_Lib_Plt \n
 * \b Target:               \n
 * \b Compiler:             \n
 * \b Module:               %name:Fault_Lib_Plt.h % \n
 * \b File-Revision:        %version:    5 % \n
 * \b Changeable-by-user:   Yes \n
 * \b Module-Owner:         %owner: % \n
 * \b Last-Changed-Date:    %date_modified: Fri Oct 05:33:50 2017 % \n
 * \b Classification:       CONFIDENTIAL \n
 * \Requirements
 * \reqtrace
 */

/*====================================================================================================================*\
 *
 * Copyright (C) 2021 Aptiv. All rights reserved
 * It is not allowed to reproduce or utilize parts of this document in any form
 * or by any means, including photocopying and microfilm, without permission in
 * written by Aptiv.
 *
\*====================================================================================================================*/

/*====================================================================================================================*\
 * PREPROCESSOR DIRECTIVES
\*====================================================================================================================*/
/* INCLUDE DIRECTIVES FOR STANDARD HEADERS ---------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "fixmac.h"
#include "reuse.h"
#include "string.h"

#ifndef boolean_T
typedef unsigned char boolean_T; /**< Boolean */
#endif

/* INCLUDE DIRECTIVES FOR OTHER HEADERS ------------------------------------------------------------------------------*/
/* Include of these files for the suport of Variants in the code */

/* EXPORTED DEFINE MACROS (#, ##) ------------------------------------------------------------------------------------*/
#define T_BIT                        ((bitfield8_t)TRUE)
#define F_BIT                        ((bitfield8_t)FALSE)
#define BYTE_SIZE                    (8U)
#define PLATFORM_FAULT_TABLE_SIZE    (16U)
#define MAX_NUMBER_OF_PLATFORM_TYPES (PLATFORM_FAULT_TABLE_SIZE * BYTE_SIZE)

/*
CODED_TRUE      0xAAu
CODED_FALSE     0x55u
*/

#define DIAG_ENABLE_FAULT  (0xAAu)
#define DIAG_DISABLE_FAULT (0x55u)

#define DIAG_TEST_NOT_COMPLETED (0U)

/* MACROS FOR FAULT TABLE OVERRIDE XCP */
#define PLTFORM_AUTO_MODE         (1U)
#define PLATFORM_SET_FAULT_MODE   (2U)
#define PLATFORM_CLEAR_FAULT_MODE (3U)

/* EXPORTED DEFINES FOR CONSTANTS ------------------------------------------------------------------------------------*/

#define PLATFORM_LATCH_ENABLE_TABLE_SET_VALUES                                                                                    \
   {                                                                                                                              \
      T_BIT, /* 0.7 */     /*usc_validation_fault,                                     */                                         \
         F_BIT, /* 0.6 */  /*smc_validtn_flt,                                          */                                         \
         F_BIT, /* 0.5 */  /*reserved_0_5,                                             */                                         \
         F_BIT, /* 0.4 */  /*reserved_0_4,                                             */                                         \
         F_BIT, /* 0.3 */  /*MMIC_A_ID_Flt,mmic_transmitter_id_fault                   */                                         \
         F_BIT, /* 0.2 */  /*reserved_0_2,                                             */                                         \
         F_BIT, /* 0.1 */  /*core_self_test_fault,                                     */                                         \
         F_BIT, /* 0.0 */  /*reserved_0_0,                                             */                                         \
         F_BIT, /* 1.7 */  /*reserved_1_7,                                             */                                         \
         F_BIT, /* 1.6 */  /*reserved_1_6,                                             */                                         \
         F_BIT, /* 1.5 */  /*reserved_1_5,                                             */                                         \
         F_BIT, /* 1.4 */  /*reserved_1_4,                                             */                                         \
         F_BIT, /* 1.3 */  /*reserved_1_3,                                             */                                         \
         F_BIT, /* 1.2 */  /*reserved_1_2,                                             */                                         \
         F_BIT, /* 1.1 */  /*reserved_1_1,                                             */                                         \
         F_BIT, /* 1.0 */  /*reserved_1_0,                                             */                                         \
         F_BIT, /* 2.7 */  /*mcu_startup_fault,                                        */                                         \
         F_BIT, /* 2.6 */  /*reserved_2_6,                                             */                                         \
         F_BIT, /* 2.5 */  /*reserved_2_5,                                             */                                         \
         F_BIT, /* 2.4 */  /*reserved_2_4,                                             */                                         \
         F_BIT, /* 2.3 */  /*reserved_2_3,                                             */                                         \
         F_BIT, /* 2.2 */  /*external_watchdog_fault,                                  */                                         \
         T_BIT, /* 2.1 */  /*mcu_repetitive_reset_fault,                               */                                         \
         F_BIT, /* 2.0 */  /*PMIC_MCU_Communication_Fault,                             */                                         \
         F_BIT, /* 3.7 */  /*reserved_3_7,                                             */                                         \
         F_BIT, /* 3.6 */  /*reserved_3_6,                                             */                                         \
         F_BIT, /* 3.5 */  /*reserved_3_5,                                             */                                         \
         F_BIT, /* 3.4 */  /*reserved_3_4,                                             */                                         \
         F_BIT, /* 3.3 */  /*reserved_3_3,                                             */                                         \
         F_BIT, /* 3.2 */  /*reserved_3_2,                                             */                                         \
         F_BIT, /* 3.1 */  /*reserved_3_1,                                             */                                         \
         F_BIT, /* 3.0 */  /*reserved_3_0,                                             */                                         \
         F_BIT, /* 4.7 */  /*reserved_4_7,                                             */                                         \
         F_BIT, /* 4.6 */  /*reserved_4_6,                                             */                                         \
         F_BIT, /* 4.5 */  /*reserved_4_5,                                             */                                         \
         F_BIT, /* 4.4 */  /*reserved_4_4,                                             */                                         \
         F_BIT, /* 4.3 */  /*reserved_4_3,                                             */                                         \
         F_BIT, /* 4.2 */  /*reserved_4_2,                                             */                                         \
         F_BIT, /* 4.1 */  /*reserved_4_1,                                             */                                         \
         F_BIT, /* 4.0 */  /*reserved_4_0,                                             */                                         \
         F_BIT, /* 5.7 */  /*bbe_to_r52_ipc_fault,                                     */                                         \
         F_BIT, /* 5.6 */  /*r52_to_bbe_ipc_fault,                                     */                                         \
         F_BIT, /* 5.5 */  /*reserved_5_5,                                             */                                         \
         F_BIT, /* 5.4 */  /*reserved_5_4,                                             */                                         \
         F_BIT, /* 5.3 */  /*reserved_5_3,                                             */                                         \
         F_BIT, /* 5.2 */  /*reserved_5_2,                                             */                                         \
         F_BIT, /* 5.1 */  /*reserved_5_1,                                             */                                         \
         F_BIT, /* 5.0 */  /*reserved_5_0,                                             */                                         \
         F_BIT, /* 6.7 */  /*reserved_6_7,                                             */                                         \
         F_BIT, /* 6.6 */  /*reserved_6_6,                                             */                                         \
         F_BIT, /* 6.5 */  /*reserved_6_5,                                             */                                         \
         F_BIT, /* 6.4 */  /*reserved_6_4,                                             */                                         \
         F_BIT, /* 6.3 */  /*reserved_6_3,                                             */                                         \
         F_BIT, /* 6.2 */  /*reserved_6_2,                                             */                                         \
         F_BIT, /* 6.1 */  /*reserved_6_1,                                             */                                         \
         F_BIT, /* 6.0 */  /*reserved_6_0,                                             */                                         \
         F_BIT, /* 7.7 */  /*reserved_7_7,                                             */                                         \
         F_BIT, /* 7.6 */  /*reserved_7_6,                                             */                                         \
         F_BIT, /* 7.5 */  /*battery_low_fault,                                        */                                         \
         F_BIT, /* 7.4 */  /*battery_high_fault,                                       */                                         \
         F_BIT, /* 7.3 */  /*reserved_7_3,                                             */                                         \
         F_BIT, /* 7.2 */  /*reserved_7_2,                                             */                                         \
         F_BIT, /* 7.1 */  /*reserved_7_1,                                             */                                         \
         F_BIT, /* 7.0 */  /*mmic_temperature_high_fault,                              */                                         \
         F_BIT, /* 8.7 */  /*reserved_8_7,                                             */                                         \
         T_BIT, /* 8.6 */  /*mmic_a_sensor_dead_fault,                                 */                                         \
         F_BIT, /* 8.5 */  /*reserved_8_5,                                             */                                         \
         F_BIT, /* 8.4 */  /*mmic_safe_start_fault,                                    */                                         \
         F_BIT, /* 8.3 */  /*api_look_config_fault,                                    */                                         \
         F_BIT, /* 8.2 */  /*api_look_trigger_fault,                                   */                                         \
         F_BIT, /* 8.1 */  /*api_look_complete_fault,                                  */                                         \
         F_BIT, /* 8.0 */  /*mmic_temperature_low_fault,                               */                                         \
         F_BIT, /* 9.7 */  /*detection_processing_loop_overrun_fault,                  */                                         \
         F_BIT, /* 9.6 */  /*mmic_repetitive_reset_fault,                              */                                         \
         F_BIT, /* 9.5 */  /*acquisition_overflow_fault,                               */                                         \
         F_BIT, /* 9.4 */  /*reserved_9_4,                                             */                                         \
         F_BIT, /* 9.3 */  /*dsp_internal_fault,                                       */                                         \
         F_BIT, /* 9.2 */  /*reserved_9_2,                                             */                                         \
         F_BIT, /* 9.1 */  /*MMIC_Secondary_BallBreak_Fault,                           */                                         \
         F_BIT, /* 9.0 */  /*reserved_9_0,                                             */                                         \
         F_BIT, /* 10.7 */ /*reserved_10_7,                                            */                                         \
         F_BIT, /* 10.6 */ /*signal_integrity_fault,                                   */                                         \
         F_BIT, /* 10.5 */ /*reserved_10_5,                                            */                                         \
         F_BIT, /* 10.4 */ /*reserved_10_4,                                            */                                         \
         F_BIT, /* 10.3 */ /*mmic_secondary_mipi_fault,                                */                                         \
         F_BIT, /* 10.2 */ /*mmic_secondary_clock_fault,                               */                                         \
         F_BIT, /* 10.1 */ /*mmic_secondary_register_fault,                            */                                         \
         F_BIT, /* 10.0 */ /*Detection_data_integrity_fault,                           */                                         \
         F_BIT, /* 11.7 */ /*reserved_11_7,                                            */                                         \
         F_BIT, /* 11.6 */ /*MMIC Secondary Tx RFBIST Failure,                         */                                         \
         F_BIT, /* 11.5 */ /*MMIC Secondary RX RFBIST Failure,                         */                                         \
         F_BIT, /* 11.4 */ /*rfe_under_over_voltage_fault,                             */                                         \
         F_BIT, /* 11.3 */ /*mmic_secondary_mcu_fault,                                 */                                         \
         F_BIT, /* 11.2 */ /*reserved_11_2,                                            */                                         \
         F_BIT, /* 11.1 */ /*reserved_11_1,                                            */                                         \
         F_BIT, /* 11.0 */ /*reserved_11_0,                                            */                                         \
         F_BIT, /* 12.7 */ /*reserved_12_7,                                            */                                         \
         F_BIT, /* 12.6 */ /*reserved_12_6,                                            */                                         \
         F_BIT, /* 12.5 */ /*reserved_12_5,                                            */                                         \
         F_BIT, /* 12.4 */ /*reserved_12_4,                                            */                                         \
         F_BIT, /* 12.3 */ /*alignment_autoalignment_critical_misalignment_fault,      */                                         \
         F_BIT, /* 12.2 */ /*alignment_autoalignment_sudden_jump_detection_fault,      */                                         \
         F_BIT, /* 12.1 */ /*reserved_12_1,                                            */                                         \
         F_BIT, /* 12.0 */ /*Firstpass_Saturation_Fault,1st_Pass_Detection_Overflow    */                                         \
         F_BIT, /* 13.7 */ /*reserved_13_7,                                            */                                         \
         F_BIT, /* 13.6 */ /*alignment_no_initial_calibration_error_fault,             */                                         \
         F_BIT, /* 13.5 */ /*alignment_static_calibration_error_fault,                 */                                         \
         F_BIT, /* 13.4 */ /*alignment_service_calibration_error_fault,                */                                         \
         F_BIT, /* 13.3 */ /*alignment_shorttrack_calibration_error_fault,             */                                         \
         F_BIT, /* 13.2 */ /*alignment_autoalignment_out_of_range_fault,               */                                         \
         F_BIT, /* 13.1 */ /*alignment_autoalignment_algo_error_fault,                 */                                         \
         F_BIT, /* 13.0 */ /*reserved_13_0,                                            */                                         \
         F_BIT, /* 14.7 */ /*reserved_14_7,                                            */                                         \
         F_BIT, /* 14.6 */ /*sll_monitoring_algo_error,                                */                                         \
         F_BIT, /* 14.5 */ /*reserved_14_5,                                            */                                         \
         F_BIT, /* 14.4 */ /*blockage_algo_error_fault,                                */                                         \
         F_BIT, /* 14.3 */ /*reserved_14_3,                                            */                                         \
         F_BIT, /* 14.2 */ /*reserved_14_2,                                            */                                         \
         F_BIT, /* 14.1 */ /*reserved_14_1,                                            */                                         \
         F_BIT, /* 14.0 */ /*reserved_14_0,                                            */                                         \
         F_BIT, /* 15.7 */ /*damping_algo_error_fault,                                 */                                         \
         F_BIT, /* 15.6 */ /*reserved_15_6,                                            */                                         \
         F_BIT, /* 15.5 */ /*range_algo_error_fault,                                   */                                         \
         F_BIT, /* 15.4 */ /*reserved_15_4,                                            */                                         \
         F_BIT, /* 15.3 */ /*reserved_15_3,                                            */                                         \
         F_BIT, /* 15.2 */ /*reserved_15_2,                                            */                                         \
         F_BIT, /* 15.1 */ /*reserved_15_1,                                            */                                         \
         F_BIT, /* 15.0 */ /*reserved_15_0,                                            */                                         \
   }

#define PLATFORM_FAULT_ENABLE_TABLE_VALUES                                                                                        \
   {                                                                                                                              \
      T_BIT, /* 0.7 */     /*usc_validation_fault,                                     */                                         \
         T_BIT, /* 0.6 */  /*smc_validtn_flt,                                          */                                         \
         F_BIT, /* 0.5 */  /*reserved_0_5,                                             */                                         \
         F_BIT, /* 0.4 */  /*reserved_0_4,                                             */                                         \
         T_BIT, /* 0.3 */  /*MMIC_A_ID_Flt,                                            */                                         \
         F_BIT, /* 0.2 */  /*reserved_0_2,                                             */                                         \
         T_BIT, /* 0.1 */  /*core_self_test_fault,                                     */                                         \
         F_BIT, /* 0.0 */  /*reserved_0_0,                                             */                                         \
         F_BIT, /* 1.7 */  /*reserved_1_7,                                             */                                         \
         F_BIT, /* 1.6 */  /*reserved_1_6,                                             */                                         \
         F_BIT, /* 1.5 */  /*reserved_1_5,                                             */                                         \
         F_BIT, /* 1.4 */  /*reserved_1_4,                                             */                                         \
         F_BIT, /* 1.3 */  /*reserved_1_3,                                             */                                         \
         F_BIT, /* 1.2 */  /*reserved_1_2,                                             */                                         \
         F_BIT, /* 1.1 */  /*reserved_1_1,                                             */                                         \
         F_BIT, /* 1.0 */  /*reserved_1_0,                                             */                                         \
         T_BIT, /* 2.7 */  /*mcu_startup_fault,                                        */                                         \
         T_BIT, /* 2.6 */  /*platform_time_fault,                                      */                                         \
         F_BIT, /* 2.5 */  /*reserved_2_5,                                             */                                         \
         F_BIT, /* 2.4 */  /*reserved_2_4,                                             */                                         \
         F_BIT, /* 2.3 */  /*reserved_2_3,                                             */                                         \
         T_BIT, /* 2.2 */  /*external_watchdog_fault,                                  */                                         \
         T_BIT, /* 2.1 */  /*mcu_repetitive_reset_fault,                               */                                         \
         T_BIT, /* 2.0 */  /*PMIC_MCU_Communication_Fault,                             */                                         \
         F_BIT, /* 3.7 */  /*reserved_3_7,                                             */                                         \
         F_BIT, /* 3.6 */  /*reserved_3_6,                                             */                                         \
         F_BIT, /* 3.5 */  /*reserved_3_5,                                             */                                         \
         F_BIT, /* 3.4 */  /*reserved_3_4,                                             */                                         \
         F_BIT, /* 3.3 */  /*reserved_3_3,                                             */                                         \
         F_BIT, /* 3.2 */  /*reserved_3_2,                                             */                                         \
         F_BIT, /* 3.1 */  /*reserved_3_1,                                             */                                         \
         F_BIT, /* 3.0 */  /*reserved_3_0,                                             */                                         \
         F_BIT, /* 4.7 */  /*reserved_4_7,                                             */                                         \
         F_BIT, /* 4.6 */  /*reserved_4_6,                                             */                                         \
         F_BIT, /* 4.5 */  /*reserved_4_5,                                             */                                         \
         F_BIT, /* 4.4 */  /*reserved_4_4,                                             */                                         \
         F_BIT, /* 4.3 */  /*reserved_4_3,                                             */                                         \
         F_BIT, /* 4.2 */  /*reserved_4_2,                                             */                                         \
         F_BIT, /* 4.1 */  /*reserved_4_1,                                             */                                         \
         F_BIT, /* 4.0 */  /*reserved_4_0,                                             */                                         \
         T_BIT, /* 5.7 */  /*bbe_to_r52_ipc_fault,                                     */                                         \
         T_BIT, /* 5.6 */  /*r52_to_bbe_ipc_fault,                                     */                                         \
         F_BIT, /* 5.5 */  /*reserved_5_5,                                             */                                         \
         F_BIT, /* 5.4 */  /*reserved_5_4,                                             */                                         \
         F_BIT, /* 5.3 */  /*reserved_5_3,                                             */                                         \
         F_BIT, /* 5.2 */  /*reserved_5_2,                                             */                                         \
         F_BIT, /* 5.1 */  /*reserved_5_1,                                             */                                         \
         F_BIT, /* 5.0 */  /*reserved_5_0,                                             */                                         \
         F_BIT, /* 6.7 */  /*reserved_6_7,                                             */                                         \
         F_BIT, /* 6.6 */  /*reserved_6_6,                                             */                                         \
         F_BIT, /* 6.5 */  /*reserved_6_5,                                             */                                         \
         F_BIT, /* 6.4 */  /*reserved_6_4,                                             */                                         \
         F_BIT, /* 6.3 */  /*reserved_6_3,                                             */                                         \
         F_BIT, /* 6.2 */  /*reserved_6_2,                                             */                                         \
         F_BIT, /* 6.1 */  /*reserved_6_1,                                             */                                         \
         F_BIT, /* 6.0 */  /*reserved_6_0,                                             */                                         \
         F_BIT, /* 7.7 */  /*reserved_7_7,                                             */                                         \
         F_BIT, /* 7.6 */  /*reserved_7_6,                                             */                                         \
         T_BIT, /* 7.5 */  /*battery_low_fault,                                        */                                         \
         T_BIT, /* 7.4 */  /*battery_high_fault,                                       */                                         \
         F_BIT, /* 7.3 */  /*reserved_7_3,                                             */                                         \
         F_BIT, /* 7.2 */  /*reserved_7_2,                                             */                                         \
         F_BIT, /* 7.1 */  /*reserved_7_1,                                             */                                         \
         T_BIT, /* 7.0 */  /*mmic_temperature_high_fault,                              */                                         \
         F_BIT, /* 8.7 */  /*reserved_8_7,                                             */                                         \
         T_BIT, /* 8.6 */  /*mmic_a_sensor_dead_fault,                                 */                                         \
         F_BIT, /* 8.5 */  /*reserved_8_5,                                             */                                         \
         T_BIT, /* 8.4 */  /*mmic_safe_start_fault,                                    */                                         \
         T_BIT, /* 8.3 */  /*api_look_config_fault,                                    */                                         \
         T_BIT, /* 8.2 */  /*api_look_trigger_fault,                                   */                                         \
         T_BIT, /* 8.1 */  /*api_look_complete_fault,                                  */                                         \
         T_BIT, /* 8.0 */  /*mmic_temperature_low_fault,                               */                                         \
         T_BIT, /* 9.7 */  /*detection_processing_loop_overrun_fault,                  */                                         \
         T_BIT, /* 9.6 */  /*mmic_repetitive_reset_fault,                              */                                         \
         T_BIT, /* 9.5 */  /*acquisition_overflow_fault,                               */                                         \
         T_BIT, /* 9.4 */  /*safety_integrity_fault,                                   */                                         \
         T_BIT, /* 9.3 */  /*dsp_internal_fault,                                       */                                         \
         F_BIT, /* 9.2 */  /*reserved_9_2,                                             */                                         \
         T_BIT, /* 9.1 */  /*MMIC_Secondary_BallBreak_Fault,                           */                                         \
         F_BIT, /* 9.0 */  /*reserved_9_0,                                             */                                         \
         F_BIT, /* 10.7 */ /*reserved_10_7,                                            */                                         \
         T_BIT, /* 10.6 */ /*signal_integrity_fault,                                   */                                         \
         F_BIT, /* 10.5 */ /*reserved_10_5,                                            */                                         \
         F_BIT, /* 10.4 */ /*reserved_10_4,                                            */                                         \
         T_BIT, /* 10.3 */ /*mmic_secondary_mipi_fault,                                */                                         \
         T_BIT, /* 10.2 */ /*mmic_secondary_clock_fault,                               */                                         \
         T_BIT, /* 10.1 */ /*mmic_secondary_register_fault,                            */                                         \
         T_BIT, /* 10.0 */ /*detection_data_integrity_fault,                           */                                         \
         F_BIT, /* 11.7 */ /*reserved_11_7,                                            */                                         \
         T_BIT, /* 11.6 */ /*MMIC Secondary Tx RFBIST Failure,                         */                                         \
         T_BIT, /* 11.5 */ /*MMIC Secondary RX RFBIST Failure,                         */                                         \
         F_BIT, /* 11.4 */ /*rfe_under_over_voltage_fault,                             */                                         \
         T_BIT, /* 11.3 */ /*mmic_secondary_mcu_fault                                  */                                         \
         F_BIT, /* 11.2 */ /*reserved_11_2,                                            */                                         \
         F_BIT, /* 11.1 */ /*reserved_11_1,                                            */                                         \
         F_BIT, /* 11.0 */ /*reserved_11_0,                                            */                                         \
         F_BIT, /* 12.7 */ /*reserved_12_7,                                            */                                         \
         F_BIT, /* 12.6 */ /*reserved_12_6,                                            */                                         \
         F_BIT, /* 12.5 */ /*reserved_12_5,                                            */                                         \
         F_BIT, /* 12.4 */ /*reserved_12_4,                                            */                                         \
         T_BIT, /* 12.3 */ /*alignment_autoalignment_critical_misalignment_fault,      */                                         \
         T_BIT, /* 12.2 */ /*alignment_autoalignment_sudden_jump_detection_fault,      */                                         \
         F_BIT, /* 12.1 */ /*reserved_12_1,                                            */                                         \
         T_BIT, /* 12.0 */ /*Firstpass_Saturation_Fault,1st_Pass_Detection_Overflow    */                                         \
         F_BIT, /* 13.7 */ /*reserved_13_7,                                            */                                         \
         T_BIT, /* 13.6 */ /*alignment_no_initial_calibration_error_fault,             */                                         \
         T_BIT, /* 13.5 */ /*alignment_static_calibration_error_fault,                 */                                         \
         T_BIT, /* 13.4 */ /*alignment_service_calibration_error_fault,                */                                         \
         T_BIT, /* 13.3 */ /*alignment_shorttrack_calibration_error_fault,             */                                         \
         T_BIT, /* 13.2 */ /*alignment_autoalignment_out_of_range_fault,               */                                         \
         T_BIT, /* 13.1 */ /*alignment_autoalignment_algo_error_fault,                 */                                         \
         F_BIT, /* 13.0 */ /*reserved_13_0,                                            */                                         \
         F_BIT, /* 14.7 */ /*reserved_14_7,                                            */                                         \
         T_BIT, /* 14.6 */ /*sll_monitoring_algo_error,                                */                                         \
         F_BIT, /* 14.5 */ /*reserved_14_5,                                            */                                         \
         T_BIT, /* 14.4 */ /*blockage_algo_error_fault,                                */                                         \
         F_BIT, /* 14.3 */ /*reserved_14_3,                                            */                                         \
         F_BIT, /* 14.2 */ /*reserved_14_2,                                            */                                         \
         F_BIT, /* 14.1 */ /*reserved_14_1,                                            */                                         \
         F_BIT, /* 14.0 */ /*reserved_14_0,                                            */                                         \
         T_BIT, /* 15.7 */ /*damping_algo_error_fault,                                 */                                         \
         F_BIT, /* 15.6 */ /*reserved_15_6,                                            */                                         \
         T_BIT, /* 15.5 */ /*range_algo_error_fault,                                   */                                         \
         F_BIT, /* 15.4 */ /*reserved_15_4,                                            */                                         \
         F_BIT, /* 15.3 */ /*reserved_15_3,                                            */                                         \
         F_BIT, /* 15.2 */ /*reserved_15_2,                                            */                                         \
         F_BIT, /* 15.1 */ /*reserved_15_1,                                            */                                         \
         F_BIT, /* 15.0 */ /*reserved_15_0,                                            */                                         \
   }

/* STRUCTS -----------------------------------------------------------------------------------------------------------*/
/* Packed_Platform_Fault_bits_T */
typedef struct
{
   /* 0.7 */
   bitfield8_t usc_validation_fault:1; /* lsb */
   bitfield8_t smc_validtn_fault:1;
   bitfield8_t reserved_0_5:1;
   bitfield8_t reserved_0_4:1;
   bitfield8_t mmic_transmitter_id_fault:1;
   bitfield8_t reserved_0_2:1;
   bitfield8_t core_self_test_fault:1;
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
   bitfield8_t platform_time_fault:1;
   bitfield8_t reserved_2_5:1;
   bitfield8_t reserved_2_4:1;
   bitfield8_t reserved_2_3:1;
   bitfield8_t external_watchdog_fault:1;
   bitfield8_t mcu_repetitive_reset_fault:1;
   bitfield8_t pmic_mcu_communication_fault:1;
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
   bitfield8_t detection_processing_loop_overrun_fault:1;
   bitfield8_t mmic_repetitive_reset_fault:1;
   bitfield8_t acquisition_overflow_fault:1;
   bitfield8_t safety_integrity_fault:1;
   bitfield8_t dsp_internal_fault:1;
   bitfield8_t reserved_9_2:1;
   bitfield8_t mmic_secondary_ballbreak_fault:1;
   bitfield8_t reserved_9_0:1;
   /* 10.7 */
   bitfield8_t reserved_10_7:1;
   bitfield8_t signal_integrity_fault:1;
   bitfield8_t reserved_10_5:1;
   bitfield8_t reserved_10_4:1;
   bitfield8_t mmic_secondary_mipi_fault:1;
   bitfield8_t mmic_secondary_clock_fault:1;
   bitfield8_t mmic_secondary_register_fault:1;
   bitfield8_t detection_data_integrity_fault:1;
   /* 11.7 */
   bitfield8_t reserved_11_7:1;
   bitfield8_t rfe_tx_rfbist_err:1;
   bitfield8_t rfe_rx_rfbist_err:1;
   bitfield8_t rfe_under_over_voltage_fault:1;
   bitfield8_t mmic_secondary_mcu_fault:1;
   bitfield8_t reserved_11_2:1;
   bitfield8_t reserved_11_1:1;
   bitfield8_t reserved_11_0:1;
   /* 12.7 */
   bitfield8_t reserved_12_7:1;
   bitfield8_t reserved_12_6:1;
   bitfield8_t reserved_12_5:1;
   bitfield8_t reserved_12_4:1;
   bitfield8_t autoalignment_critical_misalignment_fault:1;
   bitfield8_t alignment_autoalignment_sudden_jump_detection_fault:1;
   bitfield8_t reserved_12_1:1;
   bitfield8_t first_pass_detection_overflow_fault:1;
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

/*====================================================================================================================*\
 * EXPORTED TYPEDEF DECLARATIONS
\*====================================================================================================================*/

/* ENUMS -------------------------------------------------------------------------------------------------------------*/
/* Enum type for the index of the PASS/FAIL Counters */
typedef enum
{
   /* 0 */
   SMC_VALIDTN_COUNT,
   USC_VALIDATION_COUNT,
   MCU_REPETITIVE_RESET_COUNT,
   PLATFORM_TIME_COUNT,
   MCU_STARTUP_COUNT,
   /* 5 */
   RESERVED_21_0,
   DSP_TO_A53_IPC_COUNT,
   RESERVED_21_2,
   MMIC_TEMP_HIGH_COUNT,
   ECU_TEMPERATURE_HIGH_COUNT,
   /* 10 */
   BATTERY_HIGH_COUNT,
   BATTERY_LOW_COUNT,
   MMIC_SAFE_START_COUNT,
   MMIC_A_SENSOR_DEAD_COUNT,
   MMIC_A_SPI_COUNT,
   /* 15 */
   MMIC_CHIRP_PLL_UNLOCK_COUNT,
   MMIC_RF_BALL_BREAK_COUNT,
   FIRST_PASS_DETECTION_OVERFLOW_COUNT,
   MMIC_TRANSMITTER_ID_COUNT,
   MMIC_TX0_BALL_BREAK_COUNT,
   /* 20 */
   MMIC_TX1_BALL_BREAK_COUNT,
   MMIC_TX2_BALl_BREAK_COUNT,
   MMIC_TX3_BALl_BREAK_COUNT,
   HORIZONTAL_ALIGNMENT_OUT_OF_RANGE_COUNT,
   VERTICAL_ALIGNMENT_OUT_OF_RANGE_COUNT,
   /* 25 */
   ALIGNMENT_ROUTINE_FAILED_COUNT,
   CORE1_AND_CORE2_SW_WATCHDOG_COUNT,
   CORE1_AND_CORE2_PROGRAM_FLOW_COUNT,
   PCAN_MISSING_MESSAGE_COUNT,
   GATEWAY_MSG_CORRUPTION_PCAN_COUNT,
   /* 30 */
   BLOCKAGE_ALGO_ERROR_COUNT,
   SIDELOBE_BLOCKAGE_COUNT,
   ANGLEFINDING_DOWN_SELECTION_OVERFLOW_COUNT,
   ALIGNMENT_AUTOALIGN_OUTOF_RANGE_COUNT,
   ALIGNMENT_SHORTTRACK_CALIBRATION_COUNT,
   /* 35 */
   ALIGNMENT_SERVICE_CALIBRATION_COUNT,
   ALIGNMENT_STATIC_CALIBRATION_COUNT,
   ALIGNMENT_NO_INITIAL_CALIBRATION_COUNT,
   RANGE_ESTIMATION_COUNT,
   DAMPING_ALGO_ERROR_COUNT,
   /* 40 */
   SAFE_STARTUP_HWA_FAULT_COUNT,
   M7_TO_BBE_IPC_FAULT_COUNT,
   BBE_TO_M7_IPC_FAULT_COUNT,
   BBE_TO_A53_IPC_FAULT_COUNT,
   A53_TO_M7_IPC_FAULT_COUNT,
   /* 45 */
   MMIC_LOOP_BACK_TEST_COUNT,
   EXTERNAL_WDG_COUNT,
   ALIGNMENT_AUTOALIGN_ALGO_COUNT,
   PMIC_MCU_COMMUNICATION_FAULT_COUNT,
   ACQUISITION_OVERFLOW_FAULT_COUNT,
   /* 50 */
   RFE_FREQUENCY_MONITOR_COUNT,
   RFE_POWER_LEVEL_DETECTOR_COUNT,
   RFE_LOCK_STEP_COUNT,
   RFE_CPU_COUNT,
   RFE_UNDER_OVER_VOLTAGE_COUNT,
   /* 55 */
   RFE_TX_RFBIST_COUNT,
   RFE_RX_RFBIST_COUNT,
   SAFETY_INTEGTRITY_COUNT,
   RFE_REPETITIVE_RESET_COUNT,
   CORE_SELF_TEST_COUNT,
   /* 60 */
   SIGNAL_INTEGRITY_COUNT,
   FUNCTIONAL_CONFIGURATION_COUNT,
   USC_MMIC_A_UNPROGRAMMED_COUNT,
   MMIC_ERROR_RECOVERY_FAILURE_COUNT,
   BBE_TO_R52_IPC_FAULT_COUNT,

   /* 65 */
   R52_TO_BBE_IPC_FAULT_COUNT,
   API_LOOK_CONFIG_FAULT_COUNT,
   API_LOOK_TRIGGER_FAULT_COUNT,
   API_LOOK_COMPLETE_FAULT_COUNT,
   AUTOALIGN_SUDDEN_JUMP_DETECTION_COUNT,
   /* 70 */
   AUTOALIGN_CRITICAL_MISALIGN_COUNT,
   DETECTION_PROCESSING_LOOP_OVERRUN_COUNT,
   FIRST_PASS_SATURATION_COUNT,
   MMIC_SECONDARY_CLOCK_COUNT,
   MMIC_SECONDARY_MIPI_COUNT,

   /* 75 */
   MMIC_SECONDARY_REGISTER_COUNT,
   MMIC_SECONDARY_MCU_COUNT,
   DETECTION_DATA_INTEGRITY_FAULT_COUNT,
   DSP_INTERNAL_COUNT,
   MMIC_SECONDARY_BALLBREAK_COUNT,

   /*76*/
   MAX_NUMBER_OF_PLT_DEBOUNCE_COUNT

} Platform_Debounce_Index_T;

/* fault_name_T */
typedef enum
{
   /* 0.0 */
   RESERVED_0_0,
   CORE_SELF_TEST_FAULT,
   RESERVED_0_2,
   MMIC_TRANSMITTER_ID_FAULT,
   RESERVED_0_4,
   RESERVED_0_5,
   SMC_VALIDTN_FAULT,
   USC_VALIDATION_FAULT,

   /* 1.0 */
   RESERVED_1_0,
   RESERVED_1_1,
   RESERVED_1_2,
   RESERVED_1_3,
   RESERVED_1_4,
   RESERVED_1_5,
   RESERVED_1_6,
   RESERVED_1_7,

   /* 2.0 */
   PMIC_MCU_COMMUNICATION_FAULT,
   MCU_REPETITIVE_RESET_FAULT,
   EXTERNAL_WATCHDOG_FAULT,
   RESERVED_2_3,
   RESERVED_2_4,
   RESERVED_2_5,
   PLATFORM_TIME_FAULT,
   MCU_STARTUP_FAULT,

   /* 3.0 */
   RESERVED_3_0,
   RESERVED_3_1,
   RESERVED_3_2,
   RESERVED_3_3,
   RESERVED_3_4,
   RESERVED_3_5,
   RESERVED_3_6,
   RESERVED_3_7,

   /* 4.0 */
   RESERVED_4_0,
   RESERVED_4_1,
   RESERVED_4_2,
   RESERVED_4_3,
   RESERVED_4_4,
   RESERVED_4_5,
   RESERVED_4_6,
   RESERVED_4_7,

   /* 5.0 */
   RESERVED_5_0,
   RESERVED_5_1,
   RESERVED_5_2,
   RESERVED_5_3,
   RESERVED_5_4,
   RESERVED_5_5,
   R52_TO_BBE_IPC_FAULT,
   BBE_TO_R52_IPC_FAULT,

   /* 6.0 */
   RESERVED_6_0,
   RESERVED_6_1,
   RESERVED_6_2,
   RESERVED_6_3,
   RESERVED_6_4,
   RESERVED_6_5,
   RESERVED_6_6,
   RESERVED_6_7,

   /* 7.0 */
   MMIC_TEMPERATURE_HIGH_FAULT,
   RESERVED_7_1,
   RESERVED_7_2,
   RESERVED_7_3,
   BATTERY_HIGH_FAULT,
   BATTERY_LOW_FAULT,
   RESERVED_7_6,
   RESERVED_7_7,

   /* 8.0 */
   MMIC_TEMPERATURE_LOW_FAULT,
   API_LOOK_COMPLETE_FAULT,
   API_LOOK_TRIGGER_FAULT,
   API_LOOK_CONFIG_FAULT,
   MMIC_SAFE_START_FAULT,
   RESERVED_8_5,
   MMIC_A_SENSOR_DEAD_FAULT,
   RESERVED_8_7,

   /* 9.0 */
   RESERVED_9_0,
   MMIC_SECONDARY_BALLBREAK_FAULT,
   RESERVED_9_2,
   DSP_INTERNAL_FAULT,
   SAFETY_INTEGRITY_FAULT,
   ACQUISITION_OVERFLOW_FAULT,
   MMIC_ERROR_RECOVERY_FAILURE_FAULT,
   DETECTION_PROCESSING_LOOP_OVERRUN_FAULT,

   /* 10.0 */
   DETECTION_DATA_INTEGRITY_FAULT,
   MMIC_SECONDARY_REGISTER_FAULT,
   MMIC_SECONDARY_CLOCK_FAULT,
   MMIC_SECONDARY_MIPI_FAULT,
   RESERVED_10_4,
   RESERVED_10_5,
   SIGNAL_INTEGRITY_FAULT,
   RESERVED_10_7,

   /* 11.0 */
   RESERVED_11_0,
   RESERVED_11_1,
   RESERVED_11_2,
   MMIC_SECONDARY_MCU_FAULT,
   RFE_UNDER_OVER_VOLTAGE_FAULT,
   RFE_RX_RFBIST_FAULT,
   RFE_TX_RFBIST_FAULT,
   RESERVED_11_7,

   /*12.0*/
   FIRST_PASS_SATURATION_FAULT,
   RESERVED_12_1,
   AUTOALIGNMENT_SUDDEN_JUMP_DETECTION_FAULT,
   AUTOALIGNMENT_CRITICAL_MISALIGNMENT_FAULT,
   RESERVED_12_4,
   RESERVED_12_5,
   RESERVED_12_6,
   RESERVED_12_7,

   /*13.0*/
   RESERVED_13_0,
   ALIGNMENT_AUTOALIGN_ALGO_FAULT,
   ALIGNMENT_AUTOALIGN_OUTOF_RANGE_FAULT,
   ALIGNMENT_SHORTTRACK_CALIBRATION_FAULT,
   ALIGNMENT_SERVICE_CALIBRATION_FAULT,
   ALIGNMENT_STATIC_CALIBRATION_FAULT,
   ALIGNMENT_NO_INITIAL_CALIBRATION_FAULT,
   RESERVED_13_7,

   /*14.0*/
   RESERVED_14_0,
   RESERVED_14_1,
   RESERVED_14_2,
   RESERVED_14_3,
   BLOCKAGE_ALGO_ERROR_FAULT,
   RESERVED_14_5,
   SLL_MONITORING_ALGO_ERROR_FAULT,
   RESERVED_14_7,

   /*15.0*/
   RESERVED_15_0,
   RESERVED_15_1,
   RESERVED_15_2,
   RESERVED_15_3,
   RESERVED_15_4,
   RANGE_ALGO_ERROR_FAULT,
   RESERVED_15_6,
   DAMPING_ALGO_ERROR_FAULT,

   MAX_NUMBER_OF_FAULT_TYPES /* equals number of faults */
} fault_name_T;

/* UNIONS ------------------------------------------------------------------------------------------------------------*/

/* fault_T */
typedef union
{
   Packed_Platform_Fault_bits_T Platform_Bits;
   u8p0_T Platform_byte[PLATFORM_FAULT_TABLE_SIZE];
} Platform_fault_T;

/* OTHER TYPEDEFS ----------------------------------------------------------------------------------------------------*/

/* Plt_XCP_Fault_Override_T */
typedef struct Plt_XCP_Fault_Override
{
   uint8 action;
   uint8_t byte_pos;
   uint8_t bit_pos;
} Plt_XCP_Fault_Override_T;

/*====================================================================================================================*\
 * EXPORTED OBJECT DECLARATIONS
\*====================================================================================================================*/
extern Platform_fault_T Platform_Active_Fault_Table;
extern Platform_fault_T Platform_Fault_Test_Completed;
extern const Platform_fault_T Platform_Latch_Enable_Table;
extern Platform_fault_T Platform_Fault_Enable_Table;
extern uint8 Plt_Fault_Table_Freeze;
/* Global variables for handling the PASS/FAULT Count */
extern uint16 Fail_Count_Debounce[MAX_NUMBER_OF_PLT_DEBOUNCE_COUNT];
extern uint16 Pass_Count_Debounce[MAX_NUMBER_OF_PLT_DEBOUNCE_COUNT];

/*====================================================================================================================*\
 * EXPORTED FUNCTIONS PROTOTYPES
\*====================================================================================================================*/
extern void Platform_memory_Copy(void *destination, void *source, uint8 num);

/*====================================================================================================================*/

extern void Platform_Diagnostics_Filter_Test(uint8 test_status, uint16 fault_name, uint16 fault_fail_limit,
                                             uint16 fault_pass_limit, uint16 *fail_counter_ptr, uint16 *pass_counter_ptr);

extern void Platform_Clear_Fault_If_Enabled_and_Not_Latched(uint16 fault_name);

extern void Platform_Set_Fault_If_Enabled(uint16 fault_name);

extern void Platform_Set_Test_Completed_If_Enabled(uint16 fault_name);

extern void Platform_Diag_No_Filter_Test(uint8 test_status, uint16 fault_name);

extern uint8 Platform_Get_Fault_Status(uint16 fault_name);

extern void Clear_Platform_Fault_Arrays(void);

extern void Clear_Platform_Fault_Information(uint16 fault_name);

extern boolean Platform_Check_Fault_If_Enabled(fault_name_T fault_name);

extern boolean Platform_Fault_Enabled_Disable(fault_name_T fault_name, uint8 enable_status);

extern void Clear_Debounce_Fault_Counters(void);

extern uint8 Platform_Fault_Table_Override_XCP(Plt_XCP_Fault_Override_T *Plt_XCP_Fault_Override);
/* FUNCTIONS FOR HANDLING FAULT TABLE */
extern Platform_fault_T *Get_Platform_Active_Fault_Table(void);
extern Platform_fault_T *Get_Platform_Fault_Test_Completed_Table(void);
extern Platform_fault_T *Get_Platform_Fault_Enable_Table(void);
extern Platform_fault_T *Get_Platform_Active_Fault_Latch_Table(void);

/*====================================================================================================================*/

/*====================================================================================================================*\
 * EXPORTED FUNCTION-LIKE-MACROS and INLINE FUNCTIONS
\*====================================================================================================================*/

/*====================================================================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *======================================================================================================================
 *
 * Date(dd-mm-yyyy)        userid                (Description on following lines: SCR #, etc.)
 *
 * 14-04-2021              gjy4d3(Vijayendra)              Initial version
 * 25-05-2021              gjy4d3(Vijayendra)              EEG-367: Implementation ticket for RNA SRR6 DV faults
 * 31-05-2021              gjy4d3(Vijayendra)              EEG-384: Implementation ticket for Nissan SRR6 DV faults (Mcu Temp Low
 fault)
 * 28-09-2021              gjy4d3(Vijayendra)              EEG-590: Clearing of the debouncing filters on the request of the
 customer domain[SRR6/FLR4/FLR4+]
 * 05-10-2021              gjy4d3(Vijayendra)              Updated for SRR6P build errors
 * 29-03-2022              djjx8v(Sristi)                  EEG-891: Bring FLR4p IPC fault implementation to Platform building block
 \*===================================================================================================================*/
#endif /* End FAULT_LIB_PLT_H */
