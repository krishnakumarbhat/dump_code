/****************************************************************************
 * Copyright 2022 APTIV, All Rights Reserved
 * Calibration File for Production Code
 * File Name: psc_cal.c
 * Created: 2022-11-29_11-42-04
 * From JSON File: psc_cal_17_73_0_0.json
 * Calibration Values for Project: FLR7-A1
 * Calibrations for Module: psc_cal
 * Generator Version: v3
 *****************************************************************************/
#include "psc_cal.h"
#include "board_revision.h"

volatile u8p0_T Proj_Electrical_System =
   (u8p0_T)PROJ_ELECTRICAL_SYSTEM_CFG; /* PAA-2884 - Requirement for Voltage monioring ranges */

static Volt_Monitor_Cal_T Volt_Monitor_AL_8_32V_Cal = {
   {1U, 1U, 0U, 1U, 1U, 48U},

   /* WCCA thresholds */
   (u6p10_T)7755,  /* k_norm_vmin 7.573V */
   (u6p10_T)34284, /* k_norm_vmin 33.48V */

   (u6p10_T)7259, /* k_L0_V1max 7.089V */
   (u6p10_T)6267, /* k_L0_V1min 6.12V */
   (u6p10_T)5766, /* k_L0_V2max 5.631V */

   (u6p10_T)34847, /* k_HI_V1min 34.03V */

   (u16p0_T)38031, /* k_HI_V1max 37.14V */
   (u16p0_T)38574, /* k_HI_V2min 37.67V */

   /* AL timings converted to calibration units */
   (u16p0_T)20,  /* k_VRMtimeTolowV2       : 100ms */
   (u16p0_T)200, /* k_VRMtimeTolowV1       : 1000ms */
   (u16p0_T)20,  /* k_VRMtimelowVtempToNorm: 100ms */
   (u16p0_T)200, /* k_VRMtimelowV1ToNorm   : 1000ms */
   (u16p0_T)200, /* k_VRMtimelowV2ToNorm   : 100ms */

   (u16p0_T)20,  /* k_VRMtimeTohighV2      : 100ms */
   (u16p0_T)200, /* k_VRMtimeTohighV1      : 1000ms */
   (u16p0_T)20,  /* k_VRMtimehighVtempToNorm: 100ms */
   (u16p0_T)200, /* k_VRMtimehighV1ToNorm  : 1000ms */
   (u16p0_T)200  /* k_VRMtimehighV2ToNorm  : 100ms */
};

static Volt_Monitor_Cal_T Volt_Monitor_AL_12V_Cal = {{1U, 1U, 0U, 1U, 1U, 48U},
                                                     (u6p10_T)8192,
                                                     (u6p10_T)16384,
                                                     (u6p10_T)7680,
                                                     (u6p10_T)7168,
                                                     (u6p10_T)6656,
                                                     (u6p10_T)16896,
                                                     (u16p0_T)17920,
                                                     (u16p0_T)19456,
                                                     (u16p0_T)200,
                                                     (u16p0_T)200,
                                                     (u16p0_T)200,
                                                     (u16p0_T)200,
                                                     (u16p0_T)200,
                                                     (u16p0_T)200,
                                                     (u16p0_T)200,
                                                     (u16p0_T)200,
                                                     (u16p0_T)200,
                                                     (u16p0_T)200};

static Volt_Monitor_Cal_T Volt_Monitor_AL_24V_Cal = {{1U, 1U, 0U, 1U, 1U, 48U},
                                                     (u6p10_T)18432,
                                                     (u6p10_T)32768,
                                                     (u6p10_T)17920,
                                                     (u6p10_T)17408,
                                                     (u6p10_T)16896,
                                                     (u6p10_T)33280,
                                                     (u16p0_T)34304,
                                                     (u16p0_T)35840,
                                                     (u16p0_T)200,
                                                     (u16p0_T)200,
                                                     (u16p0_T)200,
                                                     (u16p0_T)200,
                                                     (u16p0_T)200,
                                                     (u16p0_T)200,
                                                     (u16p0_T)200,
                                                     (u16p0_T)200,
                                                     (u16p0_T)200,
                                                     (u16p0_T)200};

/*
 * Dynamic selector is required to support A3P0 board with multiple
 * electrical-system variants (8-32V / 12V / 24V). This cannot be handled
 * by a static field access macro alone.
 */
Volt_Monitor_Cal_T *Get_Volt_Monitor_Cal_Impl(void)
{
   if ((Get_Board_Revision() == BOARD_REV_A3P0) || (Get_Board_Revision() == BOARD_REV_B0CVAL) ||
       (Get_Board_Revision() == BOARD_REV_B0CVAL_ETH))
   {
      switch ((Proj_Electrical_System_T)Proj_Electrical_System)
      {
         case PROJ_ELECTRICAL_SYSTEM_8_32V:
            return &Volt_Monitor_AL_8_32V_Cal;
         case PROJ_ELECTRICAL_SYSTEM_12V:
            return &Volt_Monitor_AL_12V_Cal;
         case PROJ_ELECTRICAL_SYSTEM_24V:
            return &Volt_Monitor_AL_24V_Cal;
         default:
            return &Volt_Monitor_AL_8_32V_Cal;
      }
   }

   return &Volt_Monitor_AL_12V_Cal;
}

#define PSC_CAL_H3_INFO(id, name)                                                                                                 \
   {PSC_H3_##id##_CAL_TYPE,                                                                                                       \
    PSC_H3_##id##_UNUSED1,                                                                                                        \
    PSC_H3_##id##_UNUSED2,                                                                                                        \
    PSC_H3_##id##_SECTION_COMPATIBILITY,                                                                                          \
    PSC_H3_##id##_VERSION,                                                                                                        \
    PSC_H3_##id##_SECTION_SIZE,                                                                                                   \
    (uint8_t *)(&PSC_Cal_Data.name##_Cal)},

__attribute__((aligned(16))) PSC_Cal_T PSC_Cal_Data = {
   /* H2_Hdr_T */
   {
      /* Customer */ (u8p0_T)1,
      /* ptp_cal_type */ (u8p0_T)2,
      /* platform */ (u8p0_T)72,
      /* no_of_sections */ (u8p0_T)2,
      /* Section_Compatibility */ (u8p0_T)2,
      /* Unused1 */ (u8p0_T)0,
      /* version */ (u16p0_T)1,
      /* Section_Size */ (u32p0_T)4352,
      /* Unused3 */ (u32p0_T)0,
      /* Unused4 */ (u32p0_T)0,
   },
   /*Diag_PLT_Debouncing_Cal_T Diag_PLT_Debouncing_Cal = */
   {

      /* H3_Hdr_T */
      {
         /* Cal_Type*/ (u8p0_T)0,
         /* Chk_sum_Version*/ (u8p0_T)0,
         /* Cal_Chk_Sum*/ (u16p0_T)0,
         /* Section_Compatibility*/ (u16p0_T)0,
         /* version*/ (u16p0_T)0,
         /* Section_Size*/ (u32p0_T)212,
      },
      /* battery_high_pass_limit*/ (u8p0_T)2,
      /* battery_high_fail_limit*/ (u8p0_T)2,
      /* battery_low_pass_limit*/ (u8p0_T)2,
      /* battery_low_fail_limit*/ (u8p0_T)2,
      /* smc_validtn_pass_limit*/ (u8p0_T)2,
      /* smc_validtn_fail_limit*/ (u8p0_T)2,
      /* usc_validation_pass_limit*/ (u8p0_T)2,
      /* usc_validation_fail_limit*/ (u8p0_T)2,
      /* mcu_repetitive_reset_pass_limit*/ (u8p0_T)1,
      /* mcu_repetitive_reset_fail_limit*/ (u8p0_T)1,
      /* mcu_startup_pass_limit*/ (u8p0_T)2,
      /* mcu_startup_fail_limit*/ (u8p0_T)2,
      /* platform_time_pass_limit*/ (u8p0_T)3,
      /* platform_time_fail_limit*/ (u8p0_T)3,
      /* radar_transceiver_safe_start_pass_limit*/ (u8p0_T)1,
      /* radar_transceiver_safe_start_fail_limit*/ (u8p0_T)1,
      /* radar_transceiver_temperature_pass_limit*/ (u8p0_T)1,
      /* radar_transceiver_temperature_fail_limit*/ (u8p0_T)1,
      /* transmitter_id_pass_limit*/ (u8p0_T)1,
      /* transmitter_id_fail_limit*/ (u8p0_T)1,
      /*blockage_algo_fail_limit*/ (u8p0_T)1,
      /*blockage_algo_pass_limit*/ (u8p0_T)1,
      /*damping_algo_fail_limit*/ (u8p0_T)1,
      /*damping_algo_pass_limit*/ (u8p0_T)1,
      /*external_wdg_fail_limit*/ (u8p0_T)1,
      /*external_wdg_pass_limit*/ (u8p0_T)1,
      /* no_initial_calibration_pass_limit*/ (u8p0_T)1,
      /* no_initial_calibration_fail_limit*/ (u8p0_T)1,
      /* static_calibration_pass_limit*/ (u8p0_T)1,
      /* static_calibration_fail_limit*/ (u8p0_T)1,
      /* service_calibration_pass_limit*/ (u8p0_T)1,
      /* service_calibration_fail_limit*/ (u8p0_T)1,
      /* shorttrack_calibration_pass_limit*/ (u8p0_T)1,
      /* shorttrack_calibration_fail_limit*/ (u8p0_T)1,
      /* autoalign_outof_range_pass_limit*/ (u8p0_T)1,
      /* autoalign_outof_range_fail_limit*/ (u8p0_T)1,
      /* autoalignment_algo_pass_limit*/ (u8p0_T)1,
      /* autoalignment_algo_fail_limit*/ (u8p0_T)1,
      /* rfe_under_over_voltage_fail_limit */ (u8p0_T)1,
      /* rfe_under_over_voltage_pass_limit */ (u8p0_T)1,
      /* rfe_tx_Rfbist_fail_limit */ (u8p0_T)1,
      /* rfe_tx_Rfbist_pass_limit */ (u8p0_T)1,
      /* rfe_rx_rfbist_fail_limit */ (u8p0_T)1,
      /* rfe_rx_rfbist_pass_limit */ (u8p0_T)1,
      /* pmic_mcu_communication_pass_limit*/ (u8p0_T)1,
      /* pmic_mcu_communication_fail_limit*/ (u8p0_T)1,
      /* core_self_test_pass_limit*/ (u8p0_T)1,
      /* core_self_test_fail_limit*/ (u8p0_T)1,
      /* safety_integrity_Pass_Limit */ (u8p0_T)3,
      /* safety_integrity_Fail_Limit */ (u8p0_T)3,
      /* signal_integrity_pass_limit*/ (u8p0_T)1,
      /* signal_integrity_fail_limit*/ (u8p0_T)1,
      /* mmic_error_recovery_pass_limit*/ (u8p0_T)2,
      /* mmic_error_recovery_fail_limit*/ (u8p0_T)2,
      /*bbe_to_r52_ipc_fault_pass_limit*/ (u8p0_T)3,
      /*bbe_to_r52_ipc_fault_fail_limit*/ (u8p0_T)3,
      /*r52_to_bbe_ipc_fault_pass_limit*/ (u8p0_T)3,
      /*r52_to_bbe_ipc_fault_fail_limit*/ (u8p0_T)3,
      /* autoalignment_sudden_jump_detection_pass_limit*/ (u8p0_T)1,
      /* autoalignment_sudden_jump_detection_fail_limit*/ (u8p0_T)1,
      /* detection_procession_loop_overrun_fault_pass_limit*/ (u8p0_T)1,
      /* detection_procession_loop_overrun_fault_fail_limit*/ (u8p0_T)1,
      /* first_pass_saturation_pass_limit*/ (u8p0_T)1,
      /* first_pass_saturation_fail_limit*/ (u8p0_T)1,
      /* mmic_secondary_clock_pass_limit*/ (u8p0_T)1,
      /* mmic_secondary_clock_fail_limit*/ (u8p0_T)1,
      /* mmic_secondary_mipi_pass_limit*/ (u8p0_T)3,
      /* mmic_secondary_mipi_fail_limit*/ (u8p0_T)3,
      /* mmic_secondary_register_pass_limit*/ (u8p0_T)3,
      /* mmic_secondary_register_fail_limit*/ (u8p0_T)3,
      /* mmic_secondary_mcu_pass_limit*/ (u8p0_T)3,
      /* mmic_secondary_mcu_fail_limit*/ (u8p0_T)3,
      /* Detection_Data_Integrity_Fault_Pass_Limit*/ (u8p0_T)3,
      /* Detection_Data_Integrity_Fault_Fail_Limit*/ (u8p0_T)3,
      /* dsp_internal_Pass_Limit*/ (u8p0_T)3,
      /* dsp_internal_Fail_Limit*/ (u8p0_T)3,
      /* mmic_secondary_ballbreak_pass_limit*/ (u8p0_T)1,
      /* mmic_secondary_ballbreak_fail_limit*/ (u8p0_T)1,
      /* vcan_busoff_pass_limit*/ (u8p0_T)1,
      /* vcan_busoff_fail_limit*/ (u8p0_T)1,
      /* pcan_busoff_pass_limit*/ (u8p0_T)1,
      /* pcan_busoff_fail_limit*/ (u8p0_T)1,
      /* pcan_message_timeout_pass_limit*/ (u8p0_T)1,
      /* pcan_message_timeout_fail_limit*/ (u8p0_T)1,
      /* Vcan_CCVS1_message_timeout_pass_limit*/ (u8p0_T)1,
      /* Vcan_CCVS1_message_timeout_fail_limit*/ (u8p0_T)1,
      /* VDC2_message_timeout_pass_limit*/ (u8p0_T)1,
      /* VDC2_message_timeout_fail_limit*/ (u8p0_T)1,
      /* ETC2_MT_Variant_message_timeout_pass_limit*/ (u8p0_T)1,
      /* ETC2_MT_Variant_message_timeout_fail_limit*/ (u8p0_T)1,
      /* ETC2_AT_AMT_Variant_message_timeout_pass_limit*/ (u8p0_T)1,
      /* ETC2_AT_AMT_Variant_message_timeout_fail_limit*/ (u8p0_T)1,
      /* ADAS_Function_Switch_message_timeout_pass_limit*/ (u8p0_T)1,
      /* ADAS_Function_Switch_message_timeout_fail_limit*/ (u8p0_T)1,
      /* CLS_Tx_16_message_timeout_pass_limit*/ (u8p0_T)1,
      /* CLS_Tx_16_message_timeout_fail_limit*/ (u8p0_T)1,
      /* CLS_TX_4_message_timeout_pass_limit*/ (u8p0_T)1,
      /* CLS_TX_4_message_timeout_fail_limit*/ (u8p0_T)1,
      /* OEL_message_timeout_pass_limit*/ (u8p0_T)1,
      /* OEL_message_timeout_fail_limit*/ (u8p0_T)1,
      /* TD_message_timeout_pass_limit*/ (u8p0_T)1,
      /* TD_message_timeout_fail_limit*/ (u8p0_T)1,
      /* VD_message_timeout_pass_limit*/ (u8p0_T)1,
      /* VD_message_timeout_fail_limit*/ (u8p0_T)1,
      /* SAS_message_timeout_pass_limit*/ (u8p0_T)1,
      /* SAS_message_timeout_fail_limit*/ (u8p0_T)1,
      /* Prj_Battery_High_fault_pass_limit*/ (u8p0_T)1,
      /* Prj_Battery_High_fault_fail_limit*/ (u8p0_T)1,
      /* Prj_Battery_Low_fault_pass_limit*/ (u8p0_T)1,
      /* Prj_Battery_Low_fault_fail_limit*/ (u8p0_T)1,
      /* Time_Synchronization_Fault_Pass_Limit*/ (u8p0_T)1,
      /* Time_Synchronization_Fault_Fail_Limit*/ (u8p0_T)1,
   },
   /*  Diag_PLT_Fault_Threshold_Cal_T Diag_PLT_Fault_Threshold_Cal = */
   {

      /* H3_Hdr_T */
      {
         /* Cal_Type*/ (u8p0_T)0,
         /* Chk_sum_Version*/ (u8p0_T)0,
         /* Cal_Chk_Sum*/ (u16p0_T)0,
         /* Section_Compatibility*/ (u16p0_T)0,
         /* version*/ (u16p0_T)0,
         /* Section_Size*/ (u32p0_T)56,
      },
      /* k_MicroTemp_Low*/ (s8p7_T)-5632,
      /* k_MicroTemp_High*/ (s8p7_T)17664,
      /* k_MicroTemp_recovery_offset*/ (s8p7_T)1280,
      /* k_onboardThermistorValid_max*/ (u16p0_T)3915,
      /* k_onboardThermistorValid_min*/ (u16p0_T)178,
      /* k_ECUTemp_High*/ (s8p7_T)16000,
      /* k_ECUTemp_recovery_offset*/ (s8p7_T)1280,
      /* k_5V_High*/ (u6p10_T)5581,
      /* k_5V_Low*/ (u6p10_T)4690,
      /* k_1_8V_High*/ (u6p10_T)2028,
      /* k_1_8V_Low*/ (u6p10_T)1751,
      /* k_2_3V_High*/ (u6p10_T)2499,
      /* k_2_3V_Low*/ (u6p10_T)2222,
      /* k_1_2_5V_High*/ (u6p10_T)1361,
      /* k_1_2_5V_Low*/ (u6p10_T)1207,
      /* k_1_1V_High*/ (u6p10_T)1239,
      /* k_1_1V_Low*/ (u6p10_T)1070,
      /* k_0_8V_High*/ (u6p10_T)1002,
      /* k_0_8V_Low*/ (u6p10_T)746,
      /* k_3_3V_High*/ (u6p10_T)3681,
      /* k_3_3V_Low*/ (u6p10_T)3241,
   },
   /* Diag_Cust_Debouncing_Cal_T Diag_Cust_Debouncing_Cal = */
   {
      /* H3_Hdr_T */
      {
         /* Cal_Type*/ (u8p0_T)0,
         /* Chk_sum_Version*/ (u8p0_T)0,
         /* Cal_Chk_Sum*/ (u16p0_T)0,
         /* Section_Compatibility*/ (u16p0_T)0,
         /* version*/ (u16p0_T)0,
         /* Section_Size*/ (u32p0_T)16,
      },
      /* Dummy_pass_limit*/ (u8p0_T)4,

   },
   /*  Diag_Cust_Fault_Threshold_Cal_T Diag_Cust_Fault_Threshold_Cal = */
   {

      /* H3_Hdr_T */
      {
         /* Cal_Type*/ (u8p0_T)0,
         /* Chk_sum_Version*/ (u8p0_T)0,
         /* Cal_Chk_Sum*/ (u16p0_T)0,
         /* Section_Compatibility*/ (u16p0_T)0,
         /* version*/ (u16p0_T)0,
         /* Section_Size*/ (u32p0_T)16,
      },
      /* Dummy_Threshold*/ (u8p0_T)4,
   },
};

PSC_Cal_T *PSC_Cal_Data_Ptr = &PSC_Cal_Data;

Cal_Section_Def_T PSC_Cal_Sec_Def[MAX_NUM_PSC_CALS] = {PSC_CAL_TABLE(PSC_CAL_H3_INFO)};

/*
 *     _   ___ _____ _____   __
 *    /_\ | _ \_   _|_ _\ \ / /
 *   / _ \|  _/ | |  | | \ V /
 *  /_/ \_\_|   |_| |___| \_/
 *
 */
