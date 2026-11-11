#ifndef DD_MMIC_H
#define DD_MMIC_H
/*===========================================================================*\
 * FILE: dd_mmic.h
 *===========================================================================
 * Copyright (C) 2026 Aptiv Advanced Safety and User Experience. All rights
 * reserved.
 * Confidential (C) Restricted Aptiv information. Do not disclose.
 *
 * DESCRIPTION:
 * This is the header file for MMIC interface layer
 *
 * ABBREVIATIONS:
 *   List of abbreviations used, or reference(s) to external document(s)
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *
 *   Requirements Document(s):
 *
 *   Applicable Standards (in order of precedence: highest first):
 *     ESGW_4-2_PE-SWX_00-01-A02_EN "Aptiv C Coding Standards" [30-Mar-2018]
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/
/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
// clang-format off
#include "mars_types.h"
#include "mmic_interface.h"
#include "smc_cal.h"
#include "usc_cal.h"
// #include "mars_actions.h"
#include "mmic_stream.h"
#include "debug_stream.h"
#include "radar_look_types.h"
// clang-format on

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/
#define REGULAR_MODE

#define MMIC_VAL_ZERO                      (0U)
#define TEMPERATURE_READ_DIAGS_NORMAL_MODE (6U)
#define MAX_TEMPERATURE_READ_DIAGS         (8U)
#define TEMP_DIAG_READ_QUANTITY            (14U)
#define MMIC_SENSOR_DEAD_FAULT_THRESHOLD   (6U)
#define MAF_NON_RECOVERABLE_FAULT          (5) // MCU_MSSG value = 0x5 MAF state Machine State = MAF_NonRecoverableError
#define MAF_RECOVERABLE_FAULT              (4) // MCU_MSSG value = 0x4 MAF state Machine State = MAF_RecoverableError
#define OTP_ID_DIAG_MEM_QUANTITY           (1U)
#define OPT_HW_VERSION_THRESHOLD_FOR_MDAC  (10U)
/* Temperature sensor indices */
#define TEMP_IDX_PVT             (0U)
#define TEMP_IDX_PVT_TSENSE      (1U)
#define TEMP_IDX_PA0             (2U)
#define TEMP_IDX_PA1             (3U)
#define TEMP_IDX_PA2             (4U)
#define TEMP_IDX_PA3             (5U)
#define TEMP_IDX_RX_TSENSE_GEN   (6U)
#define TEMP_IDX_QUAD_TSENSE_GEN (7U)
#define TEMP_SENSOR_COUNT        (8U)

   /*===========================================================================*
    * Exported Preprocessor #define MACROS
    *===========================================================================*/
   /* TODO : need to map once the SMC variable is available for Low Temp */
#define LOW_Temperature_Threshold_SMC  -40 //(k_mmic_temp_low_critical_SMC)
#define OVER_Temperature_Threshold_SMC 129 // k_tx_threshold_temperature_smc
/* macro for usc chip id */
#define USC_CHIP_ID_ADDRESS k_ChipID_USC
/*macro for mmic rf id*/
#define MMIC_RF_ID  ((uint8_t *)&Mars_UID.si_name_version)
#define CHIP_ID_LEN (sizeof(Mars_UID.si_name_version) + sizeof(Mars_UID.uid))

#define Put_Mmic_Bist_Calib_Trigger_Mode(value) (MMIC_XCP_BIST_Calib_Trigger = value)

/* Backward compatibility aliases for legacy MARS API naming */
#define MARS_Initialization RFE_Initialization
#define Mars_Init           RFE_Init
#define MARS_Look_Config    RFE_Look_Configure
#define MARS_Look_Trigger   RFE_Trigger
#define MARS_Look_Complete  RFE_Look_Complete

#define Get_Mmic_Temp_Tx0()    (MMIC_Temperature.temperature_data.tmp_tx0_sens)
#define Get_Mmic_Temp_Tx1()    (MMIC_Temperature.temperature_data.tmp_tx1_sens)
#define Get_Mmic_Temp_Tx2()    (MMIC_Temperature.temperature_data.tmp_tx2_sens)
#define Get_Mmic_Temp_Tx3()    (MMIC_Temperature.temperature_data.tmp_tx3_sens)
#define Get_Mmic_Temp_Rx0()    (MMIC_Temperature.temperature_data.tmp_rx0_sens)
#define Get_Mmic_Temp_PVT()    (MMIC_Temperature.temperature_data.tmp_pvt_sens)
#define Get_Mmic_Temp_PVT_TS() (MMIC_Temperature.temperature_data.tmp_pvt_tsens)
#define Get_Mmic_Temp_Quad()   (MMIC_Temperature.temperature_data.tmp_quad_sens)
   /*===========================================================================*
    * Exported Type Declarations
    *===========================================================================*/
   typedef enum
   {
      NORM_MODE         = 0,
      CW_MODE           = 1,
      DONT_KNOW_MODE    = 2,
      TEST_PATTERN_MODE = 3
   } MARS_Start_Config_T;

   typedef enum
   {
      MMIC_Secondary_Clock_Fault     = 0,
      MMIC_Secondary_MCU_Fault       = 1,
      MMIC_Secondary_Register_Fault  = 2,
      MMIC_Secondary_TX_RFBIST_Fault = 3,
      MMIC_Secondary_RX_RFBIST_Fault = 4
   } MMIC_Secondary_Fault_T;
   typedef struct MMIC_Individual_Profiling_Times_Tag
   {
      uint32_t current_time;
      uint32_t avg_time;
      uint32_t max_time;
      uint32_t min_time;
   } MMIC_Individual_Profiling_Times_T;

   typedef struct MMIC_Profiling_Times_Tag
   {
      uint32_t api_initialisation_time;
      uint32_t api_firmware_upload_time;
      uint32_t api_firmware_activate_time;
      MMIC_Individual_Profiling_Times_T api_config_time;
      MMIC_Individual_Profiling_Times_T spec_config_time;
      MMIC_Individual_Profiling_Times_T table_write_total_time;
      MMIC_Individual_Profiling_Times_T table_read_total_time;
      MMIC_Individual_Profiling_Times_T driver_status_poll_time;
      MMIC_Individual_Profiling_Times_T look_complete_time;
      MMIC_Individual_Profiling_Times_T look_trigger_time;
      uint32_t loop_count;
   } MMIC_Profiling_Times_T;

   typedef struct Mars_Sft_Status_Tag
   {
      bitfield32_t bor_power_error:2;
      bitfield32_t reference_pll_lock:2;
      bitfield32_t mcu_error:2;
      bitfield32_t synthesizer_error:2;
      bitfield32_t rx_adc:2;
      bitfield32_t frame_unit_error:2;
      bitfield32_t async_unit_error:2;
      bitfield32_t profiler_unit_error:2;
      bitfield32_t enable_unit_error:2;
      bitfield32_t adc_sys_pll_lock:2;
      bitfield32_t mcu_subsystem_error:2;
      bitfield32_t mipi_error:2;
      bitfield32_t ssi_error:2;
      bitfield32_t reference_pll:2;
      bitfield32_t safety_unit:2;
      bitfield32_t safety_error:2;
   } Mars_Sft_Status_T;

   typedef union Mars_Rfe_Mon_Status_Tag
   {
      Mars_Sft_Status_T bit_field;
      uint32_t register_value;
   } Mars_Rfe_Mon_Status_T;

   typedef struct MIPI_FuSa_IRQ0_Status_Tag
   {
      bitfield32_t csr_err_symbols_chirp_not_correct_flag:1;
      bitfield32_t csr_err_chirp_frame_not_correct_flag:1;
      bitfield32_t csi2_fifo_overflow_err_flag:1;
      bitfield32_t csi2_unsupported_data_type_flag:1;
      bitfield32_t csi2_exit_hs_err_flag:1;
      bitfield32_t csi2_ecc_one_bit_err_flag:1;
      bitfield32_t csi2_ecc_two_bit_err_flag:1;
      bitfield32_t csi2_crc_err_flag:1;
      bitfield32_t csi2_parity_err_flag:1;
      bitfield32_t csi2_bist_err_flag:1;
      bitfield32_t csi2_internal_err_flag:1;
      bitfield32_t csi2_watchdog_err_flag:1;
      bitfield32_t csi2_ip_parity_err_flag:1;
      bitfield32_t csi2_cmd_ecc_rcvd_flag_0:1;
      bitfield32_t csi2_cmd_ecc_rcvd_flag_1:1;
      bitfield32_t csi2_cmd_ecc_rcvd_flag_2:1;
      bitfield32_t csi2_cmd_ecc_rcvd_flag_3:1;
      bitfield32_t csi2_cmd_ecc_rcvd_flag_4:1;
      bitfield32_t csi2_cmd_ecc_rcvd_flag_5:1;
      bitfield32_t csi2_ulps_clk_active_flag:1;
      bitfield32_t csi2_ulps_clk_mark_active_flag:1;
      bitfield32_t un_used_1:1;
      bitfield32_t csi2_ulps_active_flag_0:1;
      bitfield32_t csi2_ulps_active_flag_1:1;
      bitfield32_t csi2_ulps_active_flag_2:1;
      bitfield32_t csi2_ulps_active_flag_3:1;
      bitfield32_t csi2_ulps_mark_active_flag_0:1;
      bitfield32_t csi2_ulps_mark_active_flag_1:1;
      bitfield32_t csi2_ulps_mark_active_flag_2:1;
      bitfield32_t csi2_ulps_mark_active_flag_3:1;
      bitfield32_t un_used_2:2;
   } MIPI_FuSa_IRQ0_Status_T;
   typedef union
   {
      MIPI_FuSa_IRQ0_Status_T bit_field;
      uint32_t register_value;
   } MIPI_FuSa_IRQ0_Faults_Union_t;

   typedef struct MIPI_FuSa_IRQ1_Status_Tag
   {
      bitfield32_t csi2_skewcal_active_flag_0:1;
      bitfield32_t csi2_skewcal_active_flag_1:1;
      bitfield32_t csi2_skewcal_active_flag_2:1;
      bitfield32_t csi2_skewcal_active_flag_3:1;
      bitfield32_t csi2_altcal_active_flag_0:1;
      bitfield32_t csi2_altcal_active_flag_1:1;
      bitfield32_t csi2_altcal_active_flag_2:1;
      bitfield32_t csi2_altcal_active_flag_3:1;
      bitfield32_t csi2_ppi_stopstate_ln0_flag:1;
      bitfield32_t csi2_ppi_stopstate_ln1_flag:1;
      bitfield32_t csi2_ppi_stopstate_ln2_flag:1;
      bitfield32_t csi2_ppi_stopstate_ln3_flag:1;
      bitfield32_t csi2_device_configured_flag:1;
      bitfield32_t csi2_irq_out_flag:1;
      bitfield32_t csr_meta_read_err_flag:1;
      bitfield32_t csr_meta_fifo_empty_flag:1;
      bitfield32_t csr_meta_fifo_full_flag:1;
      bitfield32_t csr_meta_fifo_overflow_flag:1;
      bitfield32_t csr_meta_fifo_watermark_exceeded_flag:1;
      bitfield32_t csr_meta_fifo_watermark_below_flag:1;
      bitfield32_t csr_end_of_frame_non_seen_before_start_flag:1;
      bitfield32_t csr_frame_end_asserted_at_wrong_time_flag:1;
      bitfield32_t csr_frame_cnt_incorrect_flag:1;
      bitfield32_t un_used_1:1;
      bitfield32_t csr_sram_overflow_flag:4;
      bitfield32_t csr_sram_underflow_flag:4;
   } MIPI_FuSa_IRQ1_Status_T;

   typedef union
   {
      MIPI_FuSa_IRQ1_Status_T bit_field;
      uint32_t register_value;
   } MIPI_FuSa_IRQ1_Faults_Union_t;

   typedef struct MIPI_FuSa_IRQ2_Status_Tag
   {
      bitfield32_t csr_sts_cnt_exceeded_flag_0:1;
      bitfield32_t csr_sts_cnt_exceeded_flag_1:1;
      bitfield32_t csr_sts_cnt_exceeded_flag_2:1;
      bitfield32_t csr_sts_cnt_exceeded_flag_3:1;
      bitfield32_t csr_sts_ded_flag_0:1;
      bitfield32_t csr_sts_ded_flag_1:1;
      bitfield32_t csr_sts_ded_flag_2:1;
      bitfield32_t csr_sts_ded_flag_3:1;
      bitfield32_t csr_sts_parity_err_flag_0:1;
      bitfield32_t csr_sts_parity_err_flag_1:1;
      bitfield32_t csr_sts_parity_err_flag_2:1;
      bitfield32_t csr_sts_parity_err_flag_3:1;
      bitfield32_t ping_pong_overflow_flag:1;
      bitfield32_t ping_pong_underflow_flag:1;
      bitfield32_t ping_pong_ecc_sec_cnt_exceeded_flag:1;
      bitfield32_t ping_pong_ecc_ded_flag:1;
      bitfield32_t idm_stat_mem_ecc_sec_cnt_exceeded_flag:1;
      bitfield32_t idm_stat_mem_ecc_ded_flag:1;
      bitfield32_t ocp_address_parity_err_flag:1;
      bitfield32_t ocp_cmd_parity_err_flag:1;
      bitfield32_t ocp_data_parity_err_flag:1;
      bitfield32_t ocp_byteen_parity_err_flag:1;
      bitfield32_t apb_pwdata_parity_err_flag:1;
      bitfield32_t apb_paddr_parity_err_flag:1;
      bitfield32_t apb_pctrl_parity_err_flag:1;
      bitfield32_t apb_penable_parity_err_flag:1;
      bitfield32_t apb_psel_parity_err_flag:1;
      bitfield32_t apb_pstrb_parity_err_flag:1;
      bitfield32_t un_used_1:4;
   } MIPI_FuSa_IRQ2_Status_T;

   typedef union
   {
      MIPI_FuSa_IRQ2_Status_T bit_field;
      uint32_t register_value;
   } MIPI_FuSa_IRQ2_Faults_Union_t;

#pragma pack(push, 4)
   typedef struct
   {
      uint32 address;
      uint32 data;
   } mars_meta_diag_data_t;

   typedef struct
   {
      uint16 frame_counter;      /*!< Frame counter */
      uint16 meta_data_register; /*!< Meta Data register */
      uint64 timestamp;          /*!< Timestamp Data */
      uint32 startup_time;
      uint32 radar_status; /*!< Radar Status */
      uint32 reserved[2];
      mars_meta_diag_data_t diag_data[16];
      uint32 crc;
   } mars_meta_data_t;
#pragma pack(pop)
   /* @brief MARS temperature structure for Tx1,TX2, Tx3,TX0, Rx0 PVT and QUAD */
   typedef struct MARS_Temparature_Data_Tag
   {
      int16_t tmp_tx0_sens;
      int16_t tmp_tx1_sens;
      int16_t tmp_tx2_sens;
      int16_t tmp_tx3_sens;
      int16_t tmp_rx0_sens;
      int16_t tmp_pvt_sens;
      int16_t tmp_pvt_tsens;
      int16_t tmp_quad_sens;

   } MARS_Temparature_Data_T;
   typedef struct MMIC_Temp_Stats_Tag
   {
      MARS_Temparature_Data_T temperature_data;

   } MMIC_Temp_Stats_T;

   typedef enum RFBIST_Calibration_Status_Tag
   {
      RFBIST_CALIBRATION_INVALID = 0,
      RFBIST_CALIBRATION_SUCCESSFUL,
      RFBIST_CALIBRATION_IN_PROGRESS,
      RFBIST_CALIBRATION_FAILED,
      RFBIST_CALIBRATION_NOT_STARTED
   } RFBIST_Calibration_Status_T;
   /* @brief fault injection test cases for all the possible scenarios of fault injection tests*/
   typedef enum XCP_MMIC_FIT_Enable_Tag
   {
      XCP_MMIC_NO_FIT_TEST = 0U,
      XCP_MMIC_ID_FIT_POS_TEST,
      XCP_MMIC_ID_FIT_NEG_TEST,
      XCP_MMIC_OT_DEGRADED_FIT_TEST,
      XCP_MMIC_OT_IDLE_FIT_TEST,
      XCP_MMIC_OT_FAULTED_FIT_TEST,
      XCP_MMIC_HIGH_TEMP_FIT_TEST,
      XCP_MMIC_CHIRP_PLL_UNLOCK_FIT_TEST,
      XCP_MMIC_LOW_TEMP_FIT_TEST,
      XCP_MMIC_BALL_BREAK_FIT_TEST,
      XCP_MMIC_TX_BIST_FIT_TEST,
      XCP_MMIC_RX_BIST_FIT_TEST,
      XCP_MMIC_CPU_FIT_TEST,
      XCP_MMIC_PLD_FIT_TEST,
      XCP_MMIC_FREQ_MON_FIT_TEST,
      XCP_MMIC_LOCK_STEP_FIT_TEST,
      XCP_MMIC_SUPPLY_VOLATGE_FIT_TEST,
      XCP_MMIC_DAQ_MIN_TIME_FIT_TEST,
      XCP_MMIC_DAQ_MAX_TIME_FIT_TEST,
      XCP_MMIC_FUNCTION_CONFIG_FIT_TEST,
      XCP_MMIC_FCCU_FAULT_FIT_TEST,
      XCP_MMIC_SAFE_STARTUP_FIT_TEST,
      XCP_MMIC_MIPI_FAILURE_FIT_TEST,
      XCP_MMIC_SFT_RECOVERABLE_ERROR_FIT_TEST,
      XCP_MMIC_SFT_NON_RECOVERABLE_ERROR_FIT_TEST,
      XCP_MMIC_SFT_NON_RECOVERABLE_SECONDARY_CLOCK_FAULT_FIT_TEST,
      XCP_MMIC_SFT_NON_RECOVERABLE_SECONDARY_MCU_FAULT_FIT_TEST,
      XCP_MMIC_SFT_NON_RECOVERABLE_SECONDARY_REGISTER_FAULT_FIT_TEST,
      XCP_MMIC_API_LOOK_TRIGGER_FIT_TEST,
      XCP_MMIC_API_LOOK_COMPLETE_FIT_TEST,
      XCP_MMIC_SOURCE_LEVEL_BIST_CONFIG_FIT_TEST,
      XCP_MMIC_TIME_LOOK_SYNC_FIT_TEST,
      XCP_MMIC_MAX_NUMBER_OF_FIT_TEST
   } XCP_MMIC_FIT_Enable_T;

   typedef struct MMIC_FuSa_Faults_Tag
   {
      /* Byte 0 */
      uint8_t sm_001_mcu_cpu_dcls:1; /*LSB*/
      uint8_t sm_002_deprecated:1;
      uint8_t sm_003_mcu_ahb_parity:1;
      uint8_t sm_004_mcu_ahb_timeout:1;
      uint8_t sm_005_mcu_ahb_cdcmon:1;
      uint8_t sm_006_mcu_mailbox_overflow:1;
      uint8_t sm_007_mcu_mailbox_underflow:1;
      uint8_t sm_008_mcu_mailbox_parity:1; /*MSB*/

      /* Byte 1 */
      uint8_t sm_009_mcu_ssi_wcrc:1;
      uint8_t sm_010_mcu_ssi_rcrc:1;
      uint8_t sm_011_mcu_maf_crc:1;
      uint8_t sm_012_mcu_dma_red:1;
      uint8_t sm_013_mcu_frame_monitor:1;
      uint8_t sm_014_regs_data_parity:1;
      uint8_t sm_015_regs_data_readback:1;
      uint8_t sm_016_regs_ctrl_redundancy:1;

      /* Byte 2 */
      uint8_t sm_017_dram_ecc:1;
      uint8_t sm_018_iram_ecc:1;
      uint8_t sm_019_irom_ecc:1;
      uint8_t sm_020_pram_ecc:1;
      uint8_t sm_021_otpm_parity:1;
      uint8_t sm_022_otpm_crc:1;
      uint8_t sm_023_buff_overflow:1;
      uint8_t sm_024_buff_underflow:1;

      /* Byte 3 */
      uint8_t sm_025_fsm_mon:1;
      uint8_t sm_026_cpll_lock:1;
      uint8_t sm_027_syth_lock:1;
      uint8_t sm_028_spll_lock:1;
      uint8_t sm_029_clkcore_comp:1;
      uint8_t sm_030_clksys_comp:1;
      uint8_t sm_031_pmu_bor:1;
      uint8_t sm_032_vddxx_vmonov:1;

      /* Byte 4 */
      uint8_t sm_033_vddxx_vmonuv:1;
      uint8_t sm_034_chirp_linchecker:1;
      uint8_t sm_035_currref_imon:1;
      uint8_t sm_036_thermal_mon:1;
      uint8_t sm_037_pvt_plausibility:1;
      uint8_t sm_038_sadcpvt_parity:1;
      uint8_t sm_039_vco_powermon:1;
      uint8_t sm_040_quadrupler_powermon:1;

      /* Byte 5 */
      uint8_t sm_041_ctrlsig_redundant:1;
      uint8_t sm_042_frame_timermon:1;
      uint8_t sm_043_profiler_shadowregs_parity:1;
      uint8_t sm_044_profiler_bus_readback:1;
      uint8_t sm_045_profiler_bus_parity:1;
      uint8_t sm_046_profiler_fifo_emptychk:1;
      uint8_t sm_047_profiler_fifo_overflowchk:1;
      uint8_t sm_048_enable_lut_phaseparity:1;

      /* Byte 6 */
      uint8_t sm_049_enable_lut_indexchecker:1;
      uint8_t sm_050_enable_lut_readback:1;
      uint8_t sm_051_enable_scheduler_redundant:1;
      uint8_t sm_052_async_pixel_counterchk:1;
      uint8_t sm_053_async_ram_overflow:1;
      uint8_t sm_054_async_ram_metadatacrc:1;
      uint8_t sm_055_rxadc_datavalid_checker:1;
      uint8_t sm_056_rxadc_samples_prbs:1;

      /* Byte 7 */
      uint8_t sm_057_rxadc_samples_overrange:1;
      uint8_t sm_058_rxadc_samples_parity:1;
      uint8_t sm_059_mipi_csi_typeerror:1;
      uint8_t sm_060_mipi_csi_laneserror:1;
      uint8_t sm_061_mipi_csi_ppitimeout:1;
      uint8_t sm_062_mipi_csi_pixelparity:1;
      uint8_t sm_063_mipi_csi_csrparity:1;
      uint8_t sm_064_mipi_csi_interror:1;

      /* Byte 8 */
      uint8_t sm_065_mipi_csi_ufifoerror:1;
      uint8_t sm_066_mipi_csi_headerecc:1;
      uint8_t sm_067_mipi_csi_wdt:1;
      uint8_t sm_068_mipi_csi_bist:1;
      uint8_t sm_069_mipi_csi_ecc:1;
      uint8_t sm_070_mipi_csi_crc:1;
      uint8_t sm_071_dphy_plldd:1;
      uint8_t sm_072_rx_ampmon:1;

      /* Byte 9 */
      uint8_t sm_073_rx_pissa_mon:1;
      uint8_t sm_074_rx_noisemon:1;
      uint8_t sm_075_rx_relampmon:1;
      uint8_t sm_076_rx_relphasemon:1;
      uint8_t sm_077_rx_ifvga_freqmon:1;
      uint8_t sm_080_tx_phaserot_rfgainbalmon:1;
      uint8_t sm_081_tx_phaserot_digitalmon:1;
      uint8_t sm_082_tx_relphasemon:1;

      /* Byte 10 */
      uint8_t sm_083_tx_relampmon:1;
      uint8_t sm_085_tx_inc_powermon:1;
      uint8_t sm_086_tx_recphasemon:1;
      uint8_t sm_087_dft_lbist:1;
      uint8_t sm_088_async_cmdfifo_parity:1;
      uint8_t sm_090_mcu_mailbox_indexparity:1;
      uint8_t sm_091_dft_mbist:1;
      uint8_t sm_092_enable_fifo_ouflow:1;

      /* Byte 11 */
      uint8_t sm_093_frame_timer_redundancy:1;
      uint8_t sm_094_ssi_cmd_parity:1;
      uint8_t sm_096_dft_lbist_mon:1;
      uint8_t sm_097_mcu_irq_cdcmon:1;
      uint8_t sm_099_mcu_cpu_exception:1;
      uint8_t sm_100_chirpgen_mmd_fifo_ouflow:1;
      uint8_t sm_101_mcu_ssi_inter:1;
      uint8_t k_unused_bits1:1;
   } MMIC_FuSa_Faults_T;

   /*FuSa Faults*/
   typedef union FuSa_Faults_Union_Tag
   {
      MMIC_FuSa_Faults_T fusa_fault_bits;

      uint8_t arr_val[RFE_FUSA_FAULTS_MAX];

   } FuSa_Faults_Union_T;
   typedef struct RFE_SFT_Err_Mon_Tag
   {
      uint8_t bor_power_error:2;
      uint8_t reference_pll_lock:2;
      uint8_t mcu_error:2;
      uint8_t synthesizer_error:2;
      uint8_t rx_adc:2;
      uint8_t frame_unit_error:2;
      uint8_t async_unit_error:2;
      uint8_t profiler_unit_error:2;
      uint8_t enable_unit_error:2;
      uint8_t adc_sys_pll_lock:2;
      uint8_t mcu_subsystem_error:2;
      uint8_t mipi_error:2;
      uint8_t ssi_error:2;
      uint8_t synthesizer_lock:2;
      uint8_t safety_unit:2;
      uint8_t safety_error:2;

   } RFE_SFT_Err_Mon_T;
   typedef union RFE_SFT_Err_Mon_Union_Tag
   {
      RFE_SFT_Err_Mon_T bit_field;
      uint32_t register_value;
   } RFE_SFT_Err_Mon_Union_T;

#ifdef MARS_RESET_MECHANISM_ENABLED
   typedef struct MARS_Reset_Info_Tag
   {
      uint32_t total_reset_counter;
      uint32_t mars_init_fail_reset_counter;
      Mars_ReturnType mars_init_fail_reset_reason;
      uint32_t look_config_fail_reset_counter;
      Mars_ReturnType look_config_fail_reset_reason;
      uint32_t look_trigger_fail_reset_counter;
      Mars_ReturnType look_trigger_fail_reset_reason;
      uint32_t look_complete_fail_reset_counter;
      Mars_ReturnType look_complete_fail_reset_reason;
      uint32_t PLL_Unlock_Set_Count;
      uint32_t bist_non_recoverable_fault_count;
   } MARS_Reset_Info_T;
#endif
   extern MMIC_Stream_T MMIC_Stream;
   extern bool MMIC_Frame_Force_Reconfig_MMIC;
   extern volatile uint8_t MMIC_High_Temp_Fault;
   extern volatile uint8_t MMIC_Low_Temp_Fault;
   extern mars_instance_t Mars_Self_Layer2_InstanceDriver0;
   /*XCP variable which is updated with appropriate value(from enum) to inject the respective fault*/
   extern volatile XCP_MMIC_FIT_Enable_T XCP_MMIC_FIT_Enable;
#ifdef MARS_RESET_MECHANISM_ENABLED
   extern MARS_Reset_Info_T MARS_Reset_Counters;
#endif
   extern MIPI_FuSa_IRQ0_Faults_Union_t MIPI_FuSa_IRQ0_Mon_Status;
   extern MIPI_FuSa_IRQ1_Faults_Union_t MIPI_FuSa_IRQ1_Mon_Status;
   extern MIPI_FuSa_IRQ2_Faults_Union_t MIPI_FuSa_IRQ2_Mon_Status;
   extern MMIC_Temp_Stats_T MMIC_Temperature;

   extern bool Is_Triggered_Once;
   /*API Fault status array*/
   extern volatile uint8_t MMIC_API_Failure_Status[MAX_API_FAULT_TYPE];
   extern volatile bool MMIC_XCP_BIST_Calib_Trigger;

   extern uint32 Measurement_debug_timer_ms;
   extern uint8_t MIPI_CSI2_Data_Error;
   extern mars_uid_t Mars_UID;

   /*===========================================================================*
    * Exported Function Prototypes
    *===========================================================================*/
   Mars_ReturnType RFE_Initialization(void);
   Mars_ReturnType MARS_Log_Static_Parameters(void);
   Mars_ReturnType MARS_Startup_Config(void);
   Mars_ReturnType MARS_ZHB_Initialization(void);
   void MARS_DEBUG_Check_Phase_LUT(uint16_t *Mars_Phase_LUT, uint16_t *lut_values);
   Mars_ReturnType MARS_Start_CW_Mode(void);
   Mars_ReturnType MARS_Stop_CW_Mode(void);
   Mars_ReturnType MARS_Start_Test_Pattern_Mode(void);
   Mars_ReturnType MARS_Stop_Test_Pattern_Mode(void);
   Mars_ReturnType MARS_Config(uint64_t look_id, uint16 frame_counter);
   // Mars_ReturnType MARS_Monitor(void);
   // void MARS_DEBUG_Check_Sys_Status(uint32 Static_Params_sys_status_sft_error, uint32 Static_Params_sys_status_mcu_status,
   //                                  uint32 Static_Params_sys_status_ctrl_status, uint8_t MMIC_State);

   MMIC_Result_T RFE_Init(void);
   MMIC_Result_T RFE_Look_Configure(void);
   MMIC_Result_T RFE_Trigger(void);
   uint32_t compute_crc32(const uint32_t *data_words, size_t num_words, uint32_t polynomial, uint8_t reflect_input,
                          uint8_t reflect_output, uint8_t endianness, uint32_t crc_seed, uint8_t use_xor, uint32_t final_xor);
   uint32_t reflect_bits(uint32_t data, uint8_t width);
   void generate_crc32_table(uint32_t polynomial, uint8_t reflect_input, uint32_t table[256]);
   void MMIC_Update_Profiling_Spec_Config_Time(volatile MMIC_Individual_Profiling_Times_T *profiling_time_ptr,
                                               bool *first_time_measurement_ptr);
   void Get_MMIC_Temp_Report(void);
   volatile MARS_Temparature_Data_T *Get_MARS_Temp_Report(void);
   MMIC_Result_T RFE_Look_Complete(void);

   void Populate_MMIC_Stream(void);
#ifdef MARS_RESET_MECHANISM_ENABLED
   MMIC_Result_T MARS_Reset(void);
#endif
   uint32_t Mars_MAF_GetSize(void);
   mars_si_name_version_t *Get_Chip_Id_Information_Ptr(void);
   // void Mars_Register_Write_Custom(void);
   Mars_ReturnType Mars_Register_Write_Custom_Post_Activation(void);
   Mars_ReturnType Mars_Register_Write_MetaData_Packet_Type(void);
   void MARS_Metadata_Read(void);
   void MMIC_Helper_Function(void);
   void MIPI_FuSa_Fault_Processing(void);
   /* Data Acq Over Flow Fault */
   uint8_t Get_MMIC_Daq_Over_Flow_Err(void);
   uint8_t Get_MMIC_Daq_Over_Flow_Fault(void);
   uint64_t *Get_Acq_End_Time_FE_Ptr(void);
   uint64_t *Get_Acq_Start_Time_FS_Ptr(void);
   int16_t Compute_MMIC_On_Chip_Temperature(void);

   /*Function Declarations for API faults*/
   uint8_t Get_MMIC_API_Fault(uint8_t fault_index);

   void Update_Usc_Mmic_Id(uint8_t *usc_mmic_id_ptr, const uint8_t *mmic_id_ptr, const uint8_t id_len);
   /* function prototype for Verify_Mmic_Id */
   int32_t Verify_Mmic_Id(MMIC_ID_Status_T *mmic_id_status_ptr, const uint8_t *usc_mmic_id_ptr, const uint8_t *mmic_id_ptr,
                          const uint8_t id_len);
   /* funcion prototype for Get_Mmic_Id_Ptr */
   MMIC_ID_Status_T *Get_Mmic_Id_Ptr(void);
   /* function prototype for Get_Tx_Id_Fault */
   uint8_t Get_Tx_Id_Fault(void);
   /* function prototype for Get_MMIC_Secondary_Fault */
   uint8_t Get_MMIC_Secondary_Fault(MMIC_Secondary_Fault_T SM_Error_flag);
#if defined(MARS_HW_REV_A0)
   Mars_ReturnType MARS_Log_Critical_Regs(void);
#endif
   void Populate_Mars_Temperatures(mars_diag_t diag_values[TEMP_DIAG_READ_QUANTITY]);
   uint8_t Get_MMIC_Sensor_Dead_Fault(void);
   void Populate_Fusa_Faults_In_Debug_Stream(Debug_Stream_T *debug_stream_ptr);
   MMIC_Analog_Bist_Status_T *Get_RF_Inject_RX_Diag_Raw_Value_Ptr(void);
   MMIC_Analog_Bist_Status_T *Get_RX_Noise_Info_Diag_Raw_Value_Ptr(void);
   MMIC_Analog_Bist_Status_T *Get_IFVGA_Diag_Raw_Value_Ptr(void);
   MMIC_Analog_Bist_Status_T *Get_Loopback_Diag_Raw_Value_Ptr(void);
   FuSa_Faults_Union_T *Get_Mmic_Fusa_Active_Fault_Ptr(void);
   FuSa_Faults_Union_T *Get_Mmic_Fusa_Backup_Fault_Ptr(void);
#if RESI_MODE_ENABLE
   void MMIC_Resi_Helper_Function(void);
#endif

   extern void MMIC_Fault_Injection(XCP_MMIC_FIT_Enable_T fit_enable, Radar_Look_T look_id);
   /*===========================================================================*
    * Exported Inline Function Definitions and #define Function-Like Macros
    *===========================================================================*/

   /*===========================================================================*\
   * File Revision History (top to bottom: first revision to last revision)
   *===========================================================================
   *
   * Date           userid      (Description on following lines: SCR #, etc.)
   * ----------- --------    ----------------------------------------------------
   * 17-Jun-2024    ftoobg          Initial version for Spec v1
   * 22-Apr-2025    djdgwr          EPB-3706: [Gen8] [MMIC][SWE1_SWE3][R2.0] - added enum for Low Temp FIT.
   * 28-Jun-2025    ftoobg          EPB-3947: Safety critical register framework
   * 23-Jul-2025    ftoobg          EPB-3903: [Gen8][SWE3][R3.0] Use Case: Request Safe Start up: Transceiver and peripheral
   initialization and failure
   * 22-Jul-2025    jjrfgz          EPB-3984: TICS Coding Standard Improvement
   * 07-Oct-2025    ftoobg          EPB-4123: Bring changes for Debug Logging and ADC unit fixes into dev
   * 11-Oct-2025    njsfs0          EPB-4224: [Gen8] MMIC DAQ Over Flow Fault Implementation
   * 24-Sep-2025    ftoobg          EPB-3939: [Gen8][SWE3][R3.0] Use Case: Analog safety monitors and it's linkage to sensor dead
   fault
   * 18-Dec-2025    BC              EPB-4291: merge Gen8_A2HW_Bringup to dev for A2.3.0 HW ChandraB0 MarsA0/B1
   *                                          Some adaptations needed as diagnostic approach has changed with MAF v10.2.2.1 and MAF
   v10.2.1.2
   *                                          TODO_CHANDRA_B0: Ex: mmic_analog_bist_status, sft_mon, temp and other diag
   * 14-Jan-2026    ftoobg          EPB-4312: [Gen8][SWE3] Log all the diagnostic memories into the mmic stream
   * 27-Jan-2026    ftoobg          EPB-4327: [Gen8][SWE3] Fix for stale temperature readings in MMIC stream
   * 06-Feb-2026    njsfs0          EPB-4320: [GEN8] Temperature data over XCP.
   * 10-Feb-2026    ftoobg          EPB-4374: [Gen8][SWE3] MAF 10.3.0.2 and API 2.0.0 Integration
    * 23-Feb-2026 ftoobg  EPB-4410 [Gen8][SWE6] Mars Safety: MMIC Safety Critical Errors Handling
   * 05-Feb-2026    djdgwr          EPB-4463: [GEN8][SWE3][R5.0]Implementation- Handling Sft_Mon_Reg and ERROR PIN
   *                                          added MAF_NON_RECOVERABLE_FAULT and MAF_RECOVERABLE_FAULT macros
   * 09-Mar-2026   djdgwr      EPB-4391: [Gen8][SWE3_Implementation] Common function for fault injection (added LOW_TEMP_SMC).
   * 16-Mar-2026  ftoobg   EPB-4434: [Gen8]Function names as per v2 in Gen8
   * 14-May-2026  ftoobg   EPB-4419 [Gen8] [SWE3] Use Case: Monitor and report RFE MCU related faults
   * 12-May-2026  ftoobg   EPB-4685 [Gen8][SWE3][R6.0]update average temperature similar to GEN7_V2
   * 16-June-2026  jjrfgz   EPB-4692 Get Functions for BIST Fault Mapping Added
   * 16-June-2026  jjrfgz  EPB-4614 (F1 99) BIST Parametric data get function updates
   *  12-June-2026 ftoobg   EPB-4705 [Gen8][SWE3][R7]Safety Mechanism implementation in the code as per v6.0
   *  19-Jun-2026  ftoobg  EPB-4722:[Gen8][SWE1] Update of Register based on OTP value for Gen8 and above
   *  09-Jul-2026  ftoobg  EPB-4770 [Gen8] [R7][SWE3] Use Case: Thermal management and Fault Handling- New strategy (MARS)
    * 18-Aug-2026  njsfs0 EPB-4834 Mapping Fusa faults to NVM
   *  25-Aug-2026 ftoobg  EPB-4779 [Gen8]Implement Generic MARS Register Read/Write Logic Within Look Trigger
   \*===========================================================================*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* DD_MMIC_H */
