/*===========================================================================*/
/**
 * @file mipi_ifc.c
 *
 * Application interface mapping for Range Process module
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2023 Aptiv. All rights reserved.
 * Aptiv Sensitive Business Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Application interface mapping for Range Process module
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
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include <string.h>
/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "range_process_ifc.h"
/* range_process_ifc.h must be included before chandra_sfrs.h.
   ToDo : Need to update the chandra library reference to complete the inclusion
   and remove the chandra sfrs from the application repository */
#include "api/bbe_helpers.h"
#include "api/mipi_helpers.h"
#include "api/profiling_helpers.h"
#include "api/timing_helpers.h"
#include "ipc_dsp.h"
#include "mipi_ifc.h"
#include "radar_look_types.h"
#include "smc_cal.h"
#include "spbb_math.h"
#include "spbb_sort.h"
#include "spbb_typedefs.h"

#include <xtensa/config/core.h>
#include <xtensa/hal.h>
#include <xtensa/tie/xt_bbe32.h>
#include <xtensa/tie/xt_bben.h>
#include <xtensa/tie/xt_ioports.h>
#include <xtensa/xtruntime.h>

volatile MIPI_SFRS_t *const HELPERS_ATTRIBUTES MIPI_local_ptr = ((volatile MIPI_SFRS_t *const)MIPI_base);
/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
/* Hardware register offsets — base addresses are defined in helpers.h */
#define RA_CTRL_REG_OFFSET       (0x0004U)     /* RA control register offset from RA_base */
#define EXCISION_WCMEM_OFFSET    (0x1800U)     /* WCMEM area free during range processing (WCMEM_Range_Window_Size) */
#define RA_CTRL_WCMEM_AXI_ENABLE (0x00020000U) /* Bit mask to enable WCMEM AXI bus write access */

/* FDDT (Frequency Domain Digital Tapering) excision correction ratio constants */
#define FDDT_EXCISION_BASE_RATIO (2048U) /* (1U << 15U) >> 4U */
/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/
/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/
typedef struct MIPI_IFC_Internal_Data_Tag
{
   uint32_t chirp_end_timestamp[2];
   uint32_t irq_time_ns;
   uint16_t chirp_callback_cnt;
   uint16_t frame_size;
   uint32_t fddt_scaled_frame_size; /*frame size scaled for FDDT by FDDT_EXCISION_BASE_RATIO */
} MIPI_IFC_Internal_Data_T;

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
/* Using volatile as the members are used in both the main context and interrupt context. */
volatile MIPI_IFC_Internal_Data_T __attribute__((section(".sram0.bss"))) MIPI_IFC_Internal_Data = {
   .chirp_end_timestamp    = {0},
   .irq_time_ns            = 0,
   .chirp_callback_cnt     = 0,
   .frame_size             = 0,
   .fddt_scaled_frame_size = 0,
};
volatile uint16_t max_excision_count_injection = 0;
/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/
void IdmDc_Frame_Configuration_Ch0(Idm_Config_T *idm_config_ptr, Radar_Look_T look_type);
void IdmDc_Frame_Configuration_Ch1(Idm_Config_T *idm_config_ptr, Radar_Look_T look_type);
void IdmDc_Frame_Configuration_Ch2(Idm_Config_T *idm_config_ptr, Radar_Look_T look_type);
void IdmDc_Frame_Configuration_Ch3(Idm_Config_T *idm_config_ptr, Radar_Look_T look_type);

void RestoIdm_Frame_Configuration_All(Ridm_Config_T *ridm_config_ptr, Radar_Look_T look_type);

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/
/**
 *  @b Description
 *  @n
 *      Configure the IDM and DC Compensation Cores in MIPI Wrapper from SMC Ch0
 *  * @param [in] Idm_Config_T* idm_config for specific channel.
 *  * @param [in] SMC_Cal_T * Pointer to SMC struct.
 *  * @param [in] Radar_Look_T Radar look type.
 *
 *  @retval
 *      void
 */
void IdmDc_Frame_Configuration_Ch0(Idm_Config_T *idm_config_ptr, Radar_Look_T look_type)
{
   idm_config_ptr->k_idm_chX_detection_ena        = k_idm_ch0_detection_ena_smc[look_type];
   idm_config_ptr->k_idm_chX_square_accum_sel     = k_idm_ch0_square_accum_sel_smc[look_type];
   idm_config_ptr->k_idm_chX_abs_prog_shift       = k_idm_ch0_abs_prog_shift_smc[look_type];
   idm_config_ptr->k_idm_chX_abs_prog_mult        = k_idm_ch0_abs_prog_mult_smc[look_type];
   idm_config_ptr->k_idm_chX_abs_thr              = k_idm_ch0_abs_thr_smc[look_type];
   idm_config_ptr->k_idm_chX_abs_sel              = k_idm_ch0_abs_sel_smc[look_type];
   idm_config_ptr->k_idm_chX_diff_abs_prog_shift  = k_idm_ch0_diff_abs_prog_shift_smc[look_type];
   idm_config_ptr->k_idm_chX_diff_abs_prog_mult   = k_idm_ch0_diff_abs_prog_mult_smc[look_type];
   idm_config_ptr->k_idm_chX_diff_abs_thr         = k_idm_ch0_diff_abs_thr_smc[look_type];
   idm_config_ptr->k_idm_chX_diff_abs_sel         = k_idm_ch0_diff_abs_sel_smc[look_type];
   idm_config_ptr->k_idm_chX_detection_mode       = k_idm_ch0_detection_mode_smc[look_type];
   idm_config_ptr->k_idm_chX_pollution_weight[0]  = k_idm_ch0_pollution_weight_smc[look_type][0];
   idm_config_ptr->k_idm_chX_pollution_weight[1]  = k_idm_ch0_pollution_weight_smc[look_type][1];
   idm_config_ptr->k_idm_chX_pollution_weight[2]  = k_idm_ch0_pollution_weight_smc[look_type][2];
   idm_config_ptr->k_idm_chX_pollution_weight[3]  = k_idm_ch0_pollution_weight_smc[look_type][3];
   idm_config_ptr->k_idm_chX_pollution_weight[4]  = k_idm_ch0_pollution_weight_smc[look_type][4];
   idm_config_ptr->k_idm_chX_pollution_weight[5]  = k_idm_ch0_pollution_weight_smc[look_type][5];
   idm_config_ptr->k_idm_chX_pollution_weight[6]  = k_idm_ch0_pollution_weight_smc[look_type][6];
   idm_config_ptr->k_idm_chX_pollution_weight_thr = k_idm_ch0_pollution_weight_thr_smc[look_type];

   if (ITF_ADC_INJECTION_MODE != Offline_Mode_Flag_DSP)
   {
      idm_config_ptr->dc_estimation_enable = k_dc_ch0_estimation_ena_smc[look_type];
   }
   else
   {
      idm_config_ptr->dc_estimation_enable = 0U;
   }

   idm_config_ptr->dc_acc_prog_shift             = k_dc_ch0_accum_prog_shift_smc[look_type];
   idm_config_ptr->dc_acc_prog_mult              = k_dc_ch0_accum_prog_mult_smc[look_type];
   idm_config_ptr->dc_estimation_start_samples   = k_dc_ch0_estimation_start_sample_smc[look_type];
   idm_config_ptr->dc_estimation_no_of_samples   = k_dc_ch0_estimation_n_samples_smc[look_type];
   idm_config_ptr->dc_hardcoded_threshold_enable = k_dc_ch0_hardcoded_thr_ena_smc[look_type];
   idm_config_ptr->dc_compensation_control       = k_dc_ch0_compensation_byp_smc[look_type];
   idm_config_ptr->dc_hardcoded_threshold        = (uint16_t)k_dc_ch0_hardcoded_thr_smc[look_type];

   idm_config_ptr->k_idm_chX_mitigation_byp   = k_idm_ch0_mitigation_byp_smc[look_type];
   idm_config_ptr->k_idm_chX_mitigation_mode  = k_idm_ch0_mitigation_mode_smc[look_type];
   idm_config_ptr->k_idm_chX_zero_window_size = k_idm_ch0_zero_window_size_smc[look_type];
   idm_config_ptr->idm_statmem_ctrl           = k_idm_stat_mem_ctrl_ch0_smc[look_type];
}

/**
 *  @b Description
 *  @n
 *      Configure the IDM and DC Compensation Cores in MIPI Wrapper from SMC Ch0
 *  * @param [in] Idm_Config_T* idm_config for specific channel.
 *  * @param [in] SMC_Cal_T * Pointer to SMC struct.
 *  * @param [in] Radar_Look_T Radar look type.
 *
 *  @retval
 *      void
 */
void IdmDc_Frame_Configuration_Ch1(Idm_Config_T *idm_config_ptr, Radar_Look_T look_type)
{
   idm_config_ptr->k_idm_chX_detection_ena        = k_idm_ch1_detection_ena_smc[look_type];
   idm_config_ptr->k_idm_chX_square_accum_sel     = k_idm_ch1_square_accum_sel_smc[look_type];
   idm_config_ptr->k_idm_chX_abs_prog_shift       = k_idm_ch1_abs_prog_shift_smc[look_type];
   idm_config_ptr->k_idm_chX_abs_prog_mult        = k_idm_ch1_abs_prog_mult_smc[look_type];
   idm_config_ptr->k_idm_chX_abs_thr              = k_idm_ch1_abs_thr_smc[look_type];
   idm_config_ptr->k_idm_chX_abs_sel              = k_idm_ch1_abs_sel_smc[look_type];
   idm_config_ptr->k_idm_chX_diff_abs_prog_shift  = k_idm_ch1_diff_abs_prog_shift_smc[look_type];
   idm_config_ptr->k_idm_chX_diff_abs_prog_mult   = k_idm_ch1_diff_abs_prog_mult_smc[look_type];
   idm_config_ptr->k_idm_chX_diff_abs_thr         = k_idm_ch1_diff_abs_thr_smc[look_type];
   idm_config_ptr->k_idm_chX_diff_abs_sel         = k_idm_ch1_diff_abs_sel_smc[look_type];
   idm_config_ptr->k_idm_chX_detection_mode       = k_idm_ch1_detection_mode_smc[look_type];
   idm_config_ptr->k_idm_chX_pollution_weight[0]  = k_idm_ch1_pollution_weight_smc[look_type][0];
   idm_config_ptr->k_idm_chX_pollution_weight[1]  = k_idm_ch1_pollution_weight_smc[look_type][1];
   idm_config_ptr->k_idm_chX_pollution_weight[2]  = k_idm_ch1_pollution_weight_smc[look_type][2];
   idm_config_ptr->k_idm_chX_pollution_weight[3]  = k_idm_ch1_pollution_weight_smc[look_type][3];
   idm_config_ptr->k_idm_chX_pollution_weight[4]  = k_idm_ch1_pollution_weight_smc[look_type][4];
   idm_config_ptr->k_idm_chX_pollution_weight[5]  = k_idm_ch1_pollution_weight_smc[look_type][5];
   idm_config_ptr->k_idm_chX_pollution_weight[6]  = k_idm_ch1_pollution_weight_smc[look_type][6];
   idm_config_ptr->k_idm_chX_pollution_weight_thr = k_idm_ch1_pollution_weight_thr_smc[look_type];

   if (ITF_ADC_INJECTION_MODE != Offline_Mode_Flag_DSP)
   {
      idm_config_ptr->dc_estimation_enable = k_dc_ch1_estimation_ena_smc[look_type];
   }
   else
   {
      idm_config_ptr->dc_estimation_enable = 0U;
   }

   idm_config_ptr->dc_acc_prog_shift             = k_dc_ch1_accum_prog_shift_smc[look_type];
   idm_config_ptr->dc_acc_prog_mult              = k_dc_ch1_accum_prog_mult_smc[look_type];
   idm_config_ptr->dc_estimation_start_samples   = k_dc_ch1_estimation_start_sample_smc[look_type];
   idm_config_ptr->dc_estimation_no_of_samples   = k_dc_ch1_estimation_n_samples_smc[look_type];
   idm_config_ptr->dc_hardcoded_threshold_enable = k_dc_ch1_hardcoded_thr_ena_smc[look_type];
   idm_config_ptr->dc_compensation_control       = k_dc_ch1_compensation_byp_smc[look_type];
   idm_config_ptr->dc_hardcoded_threshold        = (uint16_t)k_dc_ch1_hardcoded_thr_smc[look_type];

   idm_config_ptr->k_idm_chX_mitigation_byp   = k_idm_ch1_mitigation_byp_smc[look_type];
   idm_config_ptr->k_idm_chX_mitigation_mode  = k_idm_ch1_mitigation_mode_smc[look_type];
   idm_config_ptr->k_idm_chX_zero_window_size = k_idm_ch1_zero_window_size_smc[look_type];
   idm_config_ptr->idm_statmem_ctrl           = k_idm_stat_mem_ctrl_ch1_smc[look_type];
}

/**
 *  @b Description
 *  @n
 *      Configure the IDM and DC Compensation Cores in MIPI Wrapper from SMC Ch0
 *  * @param [in] Idm_Config_T* idm_config for specific channel.
 *  * @param [in] SMC_Cal_T * Pointer to SMC struct.
 *  * @param [in] Radar_Look_T Radar look type.
 *
 *  @retval
 *      void
 */
void IdmDc_Frame_Configuration_Ch2(Idm_Config_T *idm_config_ptr, Radar_Look_T look_type)
{
   idm_config_ptr->k_idm_chX_detection_ena       = k_idm_ch2_detection_ena_smc[look_type];
   idm_config_ptr->k_idm_chX_square_accum_sel    = k_idm_ch2_square_accum_sel_smc[look_type];
   idm_config_ptr->k_idm_chX_abs_prog_shift      = k_idm_ch2_abs_prog_shift_smc[look_type];
   idm_config_ptr->k_idm_chX_abs_prog_mult       = k_idm_ch2_abs_prog_mult_smc[look_type];
   idm_config_ptr->k_idm_chX_abs_thr             = k_idm_ch2_abs_thr_smc[look_type];
   idm_config_ptr->k_idm_chX_abs_sel             = k_idm_ch2_abs_sel_smc[look_type];
   idm_config_ptr->k_idm_chX_diff_abs_prog_shift = k_idm_ch2_diff_abs_prog_shift_smc[look_type];
   idm_config_ptr->k_idm_chX_diff_abs_prog_mult  = k_idm_ch2_diff_abs_prog_mult_smc[look_type];
   idm_config_ptr->k_idm_chX_diff_abs_thr        = k_idm_ch2_diff_abs_thr_smc[look_type];
   idm_config_ptr->k_idm_chX_diff_abs_sel        = k_idm_ch2_diff_abs_sel_smc[look_type];
   idm_config_ptr->k_idm_chX_detection_mode      = k_idm_ch2_detection_mode_smc[look_type];

   idm_config_ptr->k_idm_chX_pollution_weight[0]  = k_idm_ch2_pollution_weight_smc[look_type][0];
   idm_config_ptr->k_idm_chX_pollution_weight[1]  = k_idm_ch2_pollution_weight_smc[look_type][1];
   idm_config_ptr->k_idm_chX_pollution_weight[2]  = k_idm_ch2_pollution_weight_smc[look_type][2];
   idm_config_ptr->k_idm_chX_pollution_weight[3]  = k_idm_ch2_pollution_weight_smc[look_type][3];
   idm_config_ptr->k_idm_chX_pollution_weight[4]  = k_idm_ch2_pollution_weight_smc[look_type][4];
   idm_config_ptr->k_idm_chX_pollution_weight[5]  = k_idm_ch2_pollution_weight_smc[look_type][5];
   idm_config_ptr->k_idm_chX_pollution_weight[6]  = k_idm_ch2_pollution_weight_smc[look_type][6];
   idm_config_ptr->k_idm_chX_pollution_weight_thr = k_idm_ch2_pollution_weight_thr_smc[look_type];

   if (ITF_ADC_INJECTION_MODE != Offline_Mode_Flag_DSP)
   {
      idm_config_ptr->dc_estimation_enable = k_dc_ch2_estimation_ena_smc[look_type];
   }
   else
   {
      idm_config_ptr->dc_estimation_enable = 0U;
   }

   idm_config_ptr->dc_acc_prog_shift             = k_dc_ch2_accum_prog_shift_smc[look_type];
   idm_config_ptr->dc_acc_prog_mult              = k_dc_ch2_accum_prog_mult_smc[look_type];
   idm_config_ptr->dc_estimation_start_samples   = k_dc_ch2_estimation_start_sample_smc[look_type];
   idm_config_ptr->dc_estimation_no_of_samples   = k_dc_ch2_estimation_n_samples_smc[look_type];
   idm_config_ptr->dc_hardcoded_threshold_enable = k_dc_ch2_hardcoded_thr_ena_smc[look_type];
   idm_config_ptr->dc_compensation_control       = k_dc_ch2_compensation_byp_smc[look_type];
   idm_config_ptr->dc_hardcoded_threshold        = (uint16_t)k_dc_ch2_hardcoded_thr_smc[look_type];

   idm_config_ptr->k_idm_chX_mitigation_byp   = k_idm_ch2_mitigation_byp_smc[look_type];
   idm_config_ptr->k_idm_chX_mitigation_mode  = k_idm_ch2_mitigation_mode_smc[look_type];
   idm_config_ptr->k_idm_chX_zero_window_size = k_idm_ch2_zero_window_size_smc[look_type];
   idm_config_ptr->idm_statmem_ctrl           = k_idm_stat_mem_ctrl_ch2_smc[look_type];
}

/**
 *  @b Description
 *  @n
 *      Configure the IDM and DC Compensation Cores in MIPI Wrapper from SMC Ch0
 *  * @param [in] Idm_Config_T* idm_config for specific channel.
 *  * @param [in] SMC_Cal_T * Pointer to SMC struct.
 *  * @param [in] Radar_Look_T Radar look type.
 *
 *  @retval
 *      void
 */
void IdmDc_Frame_Configuration_Ch3(Idm_Config_T *idm_config_ptr, Radar_Look_T look_type)
{
   idm_config_ptr->k_idm_chX_detection_ena       = k_idm_ch3_detection_ena_smc[look_type];
   idm_config_ptr->k_idm_chX_square_accum_sel    = k_idm_ch3_square_accum_sel_smc[look_type];
   idm_config_ptr->k_idm_chX_abs_prog_shift      = k_idm_ch3_abs_prog_shift_smc[look_type];
   idm_config_ptr->k_idm_chX_abs_prog_mult       = k_idm_ch3_abs_prog_mult_smc[look_type];
   idm_config_ptr->k_idm_chX_abs_thr             = k_idm_ch3_abs_thr_smc[look_type];
   idm_config_ptr->k_idm_chX_abs_sel             = k_idm_ch3_abs_sel_smc[look_type];
   idm_config_ptr->k_idm_chX_diff_abs_prog_shift = k_idm_ch3_diff_abs_prog_shift_smc[look_type];
   idm_config_ptr->k_idm_chX_diff_abs_prog_mult  = k_idm_ch3_diff_abs_prog_mult_smc[look_type];
   idm_config_ptr->k_idm_chX_diff_abs_thr        = k_idm_ch3_diff_abs_thr_smc[look_type];
   idm_config_ptr->k_idm_chX_diff_abs_sel        = k_idm_ch3_diff_abs_sel_smc[look_type];
   idm_config_ptr->k_idm_chX_detection_mode      = k_idm_ch3_detection_mode_smc[look_type];

   idm_config_ptr->k_idm_chX_pollution_weight[0]  = k_idm_ch3_pollution_weight_smc[look_type][0];
   idm_config_ptr->k_idm_chX_pollution_weight[1]  = k_idm_ch3_pollution_weight_smc[look_type][1];
   idm_config_ptr->k_idm_chX_pollution_weight[2]  = k_idm_ch3_pollution_weight_smc[look_type][2];
   idm_config_ptr->k_idm_chX_pollution_weight[3]  = k_idm_ch3_pollution_weight_smc[look_type][3];
   idm_config_ptr->k_idm_chX_pollution_weight[4]  = k_idm_ch3_pollution_weight_smc[look_type][4];
   idm_config_ptr->k_idm_chX_pollution_weight[5]  = k_idm_ch3_pollution_weight_smc[look_type][5];
   idm_config_ptr->k_idm_chX_pollution_weight[6]  = k_idm_ch3_pollution_weight_smc[look_type][6];
   idm_config_ptr->k_idm_chX_pollution_weight_thr = k_idm_ch3_pollution_weight_thr_smc[look_type];

   if (ITF_ADC_INJECTION_MODE != Offline_Mode_Flag_DSP)
   {
      idm_config_ptr->dc_estimation_enable = k_dc_ch3_estimation_ena_smc[look_type];
   }
   else
   {
      idm_config_ptr->dc_estimation_enable = 0U;
   }

   idm_config_ptr->dc_acc_prog_shift             = k_dc_ch3_accum_prog_shift_smc[look_type];
   idm_config_ptr->dc_acc_prog_mult              = k_dc_ch3_accum_prog_mult_smc[look_type];
   idm_config_ptr->dc_estimation_start_samples   = k_dc_ch3_estimation_start_sample_smc[look_type];
   idm_config_ptr->dc_estimation_no_of_samples   = k_dc_ch3_estimation_n_samples_smc[look_type];
   idm_config_ptr->dc_hardcoded_threshold_enable = k_dc_ch3_hardcoded_thr_ena_smc[look_type];
   idm_config_ptr->dc_compensation_control       = k_dc_ch3_compensation_byp_smc[look_type];
   idm_config_ptr->dc_hardcoded_threshold        = (uint16_t)k_dc_ch3_hardcoded_thr_smc[look_type];

   idm_config_ptr->k_idm_chX_mitigation_byp   = k_idm_ch3_mitigation_byp_smc[look_type];
   idm_config_ptr->k_idm_chX_mitigation_mode  = k_idm_ch3_mitigation_mode_smc[look_type];
   idm_config_ptr->k_idm_chX_zero_window_size = k_idm_ch3_zero_window_size_smc[look_type];
   idm_config_ptr->idm_statmem_ctrl           = k_idm_stat_mem_ctrl_ch3_smc[look_type];
}
/** TODO Remove these as they are present in B0Plus when moving to RIDM SPBB
 * @brief  Specfic configuration related to Resorative IDM
 * @param [in] Ridm_Config_T * configuration related to Resorative IDM
 * @param [in] Radar_Look_T look_type Look type for configuration
 * @return void
 */
void RestoIdm_Frame_Configuration_All(Ridm_Config_T *ridm_config_ptr, Radar_Look_T look_type)
{
   ridm_config_ptr->stretching_factor1     = k_forward_interference_det_control_stretch_factor_shift_1_smc[look_type];
   ridm_config_ptr->stretching_factor2     = k_forward_interference_det_control_stretch_factor_shift_2_smc[look_type];
   ridm_config_ptr->max_polluted_samples   = k_forward_interference_detection_control_max_polluted_samples_smc[look_type];
   ridm_config_ptr->discard_whole_chirp_en = k_forward_interference_detection_control_discard_whole_chirp_en_smc[look_type];
   ridm_config_ptr->user_defined_stretching_function_en =
      k_forward_interference_det_control_user_def_stretch_fun_en_smc[look_type];
   ridm_config_ptr->user_defined_stretching_function = k_forward_interference_det_control_user_def_stretch_fun_smc[look_type];
   ridm_config_ptr->dynamicStretchFactor             = 0.0f;
   ridm_config_ptr->forward_idm_detection_ch0        = k_idm_ch0_forward_interference_detection_smc[look_type];
   ridm_config_ptr->segment_size_ch0                 = k_idm_ch0_segment_size_smc[look_type];
   ridm_config_ptr->forward_idm_detection_ch1        = (int8_t)k_idm_ch1_forward_interference_detection_smc[look_type];
   ridm_config_ptr->segment_size_ch1                 = k_idm_ch1_segment_size_smc[look_type];
   ridm_config_ptr->forward_idm_detection_ch2        = k_idm_ch2_forward_interference_detection_smc[look_type];
   ridm_config_ptr->segment_size_ch2                 = k_idm_ch2_segment_size_smc[look_type];
   ridm_config_ptr->forward_idm_detection_ch3        = k_idm_ch3_forward_interference_detection_smc[look_type];
   ridm_config_ptr->segment_size_ch3                 = k_idm_ch3_segment_size_smc[look_type];
}

/*===========================================================================*
 * Public API functions
 *===========================================================================*/
/**
 *  @b Description
 *  @n
 *      Writes the Configuration from SMC to the MIPI SFRs
 *  @param [in] Radar_Look_T Radar look type.
 *  @retval
 *      void
 */
void Appl_Mipi_Idm_Config(Radar_Look_T look_type)
{
   Idm_Config_T idm_config_ch0 = {0};
   Idm_Config_T idm_config_ch1 = {0};
   Idm_Config_T idm_config_ch2 = {0};
   Idm_Config_T idm_config_ch3 = {0};
   Ridm_Config_T ridm_config   = {0};

   IdmDc_Frame_Configuration_Ch0(&idm_config_ch0, look_type);
   IdmDc_Frame_Configuration_Ch1(&idm_config_ch1, look_type);
   IdmDc_Frame_Configuration_Ch2(&idm_config_ch2, look_type);
   IdmDc_Frame_Configuration_Ch3(&idm_config_ch3, look_type);
   RestoIdm_Frame_Configuration_All(&ridm_config, look_type);

   Mipi_Helpers_Idm_Config_Ch0(&idm_config_ch0);
   Mipi_Helpers_Idm_Config_Ch1(&idm_config_ch1);
   Mipi_Helpers_Idm_Config_Ch2(&idm_config_ch2);
   Mipi_Helpers_Idm_Config_Ch3(&idm_config_ch3);

   Mipi_Helpers_Resto_Idm_CommongCfg(&ridm_config);
   Mipi_Helpers_Resto_Idm_Config_Ch0(&ridm_config);
   Mipi_Helpers_Resto_Idm_Config_Ch1(&ridm_config);
   Mipi_Helpers_Resto_Idm_Config_Ch2(&ridm_config);
   Mipi_Helpers_Resto_Idm_Config_Ch3(&ridm_config);
   Mipi_Helpers_Transposer_Bypass_Config(true);

   Mipi_Clear_Idm_Stats();
   Mipi_Helpers_Clear_Chirp_End_Flag();
   Mipi_Helpers_Chirp_End_IRQ_Enable(true);
   xtos_interrupt_clear(MIPI_CHIRP_DONE_ISR);

   MIPI_IFC_Internal_Data.chirp_callback_cnt     = 0;
   MIPI_IFC_Internal_Data.frame_size             = M_FRAME[look_type];
   MIPI_IFC_Internal_Data.fddt_scaled_frame_size = MIPI_IFC_Internal_Data.frame_size * FDDT_EXCISION_BASE_RATIO;

   xtos_interrupt_enable(MIPI_CHIRP_DONE_ISR);
}

/**
 *  @b Description
 *  @n
 *      Reads out the IDM and DC Comp Statistics from designation memory in MIPI.
 *      *NOTE* Caller must call Appl_IDM_Stat_Init first before calling this method.
 *
 *  @param [in] look_type - Look type to select the parameters from the SMC.
 *  *
 *  @retval
 *      bool
 */
void Appl_IDM_Stat_Process(Radar_Look_T look_type)
{
   (void)look_type;
   volatile Rdd_Debug_Stream_T *rdd_debug_data_ptr = &Get_RP_IPC_D2M_Msg_Buffer()->payload.rdd_debug_data;
   Mipi_Stats_Debug_T *idm_stats_ptr               = (Mipi_Stats_Debug_T *)(uintptr_t)rdd_debug_data_ptr->idm_stat_data;

   xtos_interrupt_disable(MIPI_CHIRP_DONE_ISR);
   xtos_interrupt_clear(MIPI_CHIRP_DONE_ISR);
   Mipi_Helpers_Chirp_End_IRQ_Enable(false);
   Mipi_Helpers_Clear_Chirp_End_Flag();

   // The internal MIPI statistics are cleared during range initialization
   // Here, always copy out the maximum number of statistics.
   Mipi_Read_Idm_Stats(idm_stats_ptr, K_MAX);

   xthal_dcache_block_writeback((void *)idm_stats_ptr, sizeof(rdd_debug_data_ptr->idm_stat_data)); /*Cache writeback*/
}

/**
 *  @b Description
 *  @n
 *      Callback for chirp end interrupt.
 *      Sets a timestamp for the chirp end that can be used in the range process callback for RA_Cmd_Done to enable timing the RA
 * processing per chirp. If the feed forward mode is enabled, the MIPI settings are updated based on the chirp group and selected
 * RX for logging and "live" threshold usage.
 *
 *  @param [in] arg - Pointer from interrupt handler. Currently unused.
 *  *
 *  @retval N/A
 */

void Mipi_Chirp_End_IRQ_Handler(void *arg)
{
   (void)arg;
   const uint32_t chirp_end_timestamp          = Timing_Helpers_Get_Timestamp();
   volatile uint32_t *const l_ra_ctrl_reg_addr = (volatile uint32_t *)(RA_base + RA_CTRL_REG_OFFSET);
   volatile uint32_t *const l_idm_stats_mem    = (volatile uint32_t *)MIPI_STAT_MEM_base;
   uint32_t *const l_excision_wcmem            = (uint32_t *)(RA_MEM_base + EXCISION_WCMEM_OFFSET);
   const uint32_t l_stat_base_idx              = MIPI_IFC_Internal_Data.chirp_callback_cnt * 8U;
   uint32_t l_ra_ctrl_reg_orig;
   uint32_t l_max_excision;
   uint32_t l_excision_ratio;
   uint16_t wcmem_index;
   uint32_t l_excision_ratio_truncated;
   /* Memory barrier before reading IDM stats from hardware memory */
   XT_MEMW();
   XT_EXTW();

   /* Read per-chirp excision counts for all four channels and determine the maximum */
   {
      const uint32_t l_excision_chA = l_idm_stats_mem[l_stat_base_idx + 0U];
      const uint32_t l_excision_chB = l_idm_stats_mem[l_stat_base_idx + 2U];
      const uint32_t l_excision_chC = l_idm_stats_mem[l_stat_base_idx + 4U];
      const uint32_t l_excision_chD = l_idm_stats_mem[l_stat_base_idx + 6U];
      l_max_excision                = XT_MAX(XT_MAX(l_excision_chA, l_excision_chB), XT_MAX(l_excision_chC, l_excision_chD));
   }

   if (ITF_ADC_INJECTION_MODE == Offline_Mode_Flag_DSP)
   {
      l_max_excision = (uint32_t)max_excision_count_injection;
   }

   const uint16_t denominator = (MIPI_IFC_Internal_Data.frame_size - l_max_excision);
   if (denominator == 0U)
   {
      l_excision_ratio = UINT16_MAX;
   }
   else
   {
      l_excision_ratio_truncated = MIPI_IFC_Internal_Data.fddt_scaled_frame_size / denominator;
      if (l_excision_ratio_truncated >= UINT16_MAX)
      {
         l_excision_ratio = UINT16_MAX;
      }
      else
      {
         l_excision_ratio = l_excision_ratio_truncated;
      }
   }
   /* Pack the 16-bit ratio into both halves of a 32-bit WCMEM word */
   l_excision_ratio = l_excision_ratio | (l_excision_ratio << 16U);

   /* Enable WCMEM AXI bus write access, fill excision coefficients, then restore RA control */
   l_ra_ctrl_reg_orig  = *l_ra_ctrl_reg_addr;
   *l_ra_ctrl_reg_addr = l_ra_ctrl_reg_orig | RA_CTRL_WCMEM_AXI_ENABLE;

   /* FFT output = MAX_RANGE_FFT_SIZE bins; symmetric excision window = MAX_RANGE_FFT_SIZE/2 coefficients;
      each 32-bit WCMEM word holds two 16-bit coefficients => iteration count = MAX_RANGE_FFT_SIZE / 4 */
   for (wcmem_index = 0U; wcmem_index < (MAX_RANGE_FFT_SIZE >> 2U); wcmem_index++)
   {
      l_excision_wcmem[wcmem_index] = l_excision_ratio;
   }

   *l_ra_ctrl_reg_addr = l_ra_ctrl_reg_orig; /* Restore RA control: disable WCMEM AXI access and re-enable RA */
   MIPI_IFC_Internal_Data.chirp_end_timestamp[MIPI_IFC_Internal_Data.chirp_callback_cnt & 0x1] = Timing_Helpers_Get_Timestamp();

   Appl_Range_Process_Push_Ra_Commands(); // Pushing the RA commands into the CMD Queue

   MIPI_IFC_Internal_Data.chirp_callback_cnt++;

   Mipi_Helpers_Clear_Chirp_End_Flag();
   xtos_interrupt_clear(MIPI_CHIRP_DONE_ISR);

   MIPI_IFC_Internal_Data.irq_time_ns = Timing_Helpers_Get_Time_Nanosec(Timing_Helpers_Get_Timestamp() - chirp_end_timestamp);
}

/**
 *  @b Description
 *  @n
 *      One time initialization for the MIPI functionality.
 *      Enables the chirp end interrupt and assigns the @ref Mipi_Chirp_End_IRQ_Handler as the callback.
 *      Clears the feed forward mag diff and mag thresholds to the maximum values.
 *
 *  @retval N/A
 */
void Appl_MIPI_One_Time_Init(void)
{
   xtos_set_interrupt_handler(MIPI_CHIRP_DONE_ISR, (xtos_handler)Mipi_Chirp_End_IRQ_Handler, NULL, NULL);
}

/**
 *  @b Description
 *  @n
 *      Get the chirp end timestamp.
 *  @param [in] chirp_idx - Index of the chirp to get the end timestamp for.
 *  @retval uint32_t - Chirp end timestamp
 */
uint32_t Get_MIPI_Chirp_End_Timestamp(uint32_t chirp_idx)
{
   return MIPI_IFC_Internal_Data.chirp_end_timestamp[chirp_idx & 0x1];
}

/**
 *  @b Description
 *  @n
 *      Get the chirp count.
 *
 *  @retval N/A
 */
uint32_t Get_MIPI_Chirp_Count(void)
{
   return MIPI_IFC_Internal_Data.chirp_callback_cnt;
}
