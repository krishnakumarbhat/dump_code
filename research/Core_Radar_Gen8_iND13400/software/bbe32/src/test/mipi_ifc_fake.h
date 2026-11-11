/*===========================================================================*/
/**
 * @file mipi_ifc_fake.h
 *
 * Fake/stub declarations for mipi_ifc.c unit tests.
 */
/*==========================================================================*/
#pragma once

/*---------------------------------------------------------------------------*
 * Block real headers – the compiler still needs to *find* the files (via
 * BUILD deps), but the include guards cause the preprocessor to skip their
 * content.  All required types are provided below.
 *---------------------------------------------------------------------------*/
#define BBE_HELPERS_H
#define MIPI_HELPERS_H
#define PROFILING_HELPERS_H
#define _TIMING_HELPERS_H_
#define IPC_DSP_H
#define MIPI_TPGEN_IFC_H
#define RANGE_PROCESS_IFC_H
#define RADAR_LOOK_TYPES_H
#define SMC_CAL_H
#define SPBB_MATH_H
#define SPBB_SORT_H
#define SPBB_TYPEDEFS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "fff.h"

/*===========================================================================*
 * Host-side cache helper stubs
 *===========================================================================*/
#define xthal_dcache_block_writeback(addr, size)  (void)(addr)
#define xthal_dcache_block_invalidate(addr, size) (void)(addr)
#define XT_MAX(a, b)                              (((a) > (b)) ? (a) : (b))

/*===========================================================================*
 * Type stubs
 *===========================================================================*/
typedef float float32_t;
typedef int32_t s8p23_T;
typedef uint32_t Radar_Look_T;

#define RADAR_LOOK_A         (0U)
#define RADAR_LOOK_B         (1U)
#define RADAR_LOOK_C         (2U)
#define RADAR_LOOK_D         (3U)
#define MAX_RANGE_BINS       (100U)
#define MAX_RANGE_FFT_SIZE   (256U)
#define MAX_DOPPLER_FFT_SIZE (256U)
#define K_MAX                (1024U)
#define NUM_RX_CHANNELS      (4U)
#define NUM_CDM_CHANNELS     (4U)
#define SPBB_NUM_CHANNELS    (24U)
#define MAX_NUM_FF_GROUPS    (4U)

#define CODED_TRUE          (0xAAU)
#define CODED_FALSE         (0x55U)
#define DSP_CLOCK_PERIOD_US (1U)
#define MIPI_CHIRP_DONE_ISR (16U)
#define MIPI_FRAME_DONE_ISR (17U)

#ifndef UNUSED_PARAM
   #define UNUSED_PARAM(x) (void)(x)
#endif

/* Memory pool */
typedef enum
{
   MEM_POOL_SUCCESS = 0,
   MEM_POOL_FAILURE
} Memory_Pool_Return_T;
typedef struct
{
   uint8_t *base;
   uint32_t size;
   uint32_t used;
} Mem_Pool_T;

/* Offline mode flag */
typedef uint32_t Offline_Mode_T;
#define ITF_ADC_INJECTION_MODE (1U)
extern Offline_Mode_T Offline_Mode_Flag_DSP;

/* MIPI SFR stubs */
typedef struct
{
   struct
   {
      uint32_t FORWARD_INTERFERENCE_DETECTION_0;
      uint32_t FORWARD_INTERFERENCE_DETECTION_1;
      uint32_t FORWARD_INTERFERENCE_DETECTION_2;
      uint32_t FORWARD_INTERFERENCE_DETECTION_3;
   } f;
} IDM_DETECTION_CONTROL_0_T;

typedef struct
{
   struct
   {
      uint32_t STRETCHING_FACTOR_SHIFT_1;
      uint32_t STRETCHING_FACTOR_SHIFT_2;
      uint32_t MAX_POLLUTED_SAMPLES;
      uint32_t DISCARD_WHOLE_CHIRP_EN;
      uint32_t USER_DEFINED_STRETCHING_FUNCTION_EN;
      uint32_t USER_DEFINED_STRETCHING_FUNCTION;
   } f;
} FWD_IDM_CTRL_T;

typedef struct
{
   FWD_IDM_CTRL_T FORWARD_INTERFERENCE_DETECTION_CONTROL;
   IDM_DETECTION_CONTROL_0_T IDM_DETECTION_CONTROL_0_CH0;
   uint32_t IDM_DETECTION_CONTROL_3_CH0;
   IDM_DETECTION_CONTROL_0_T IDM_DETECTION_CONTROL_0_CH1;
   uint32_t IDM_DETECTION_CONTROL_3_CH1;
   IDM_DETECTION_CONTROL_0_T IDM_DETECTION_CONTROL_0_CH2;
   uint32_t IDM_DETECTION_CONTROL_3_CH2;
   IDM_DETECTION_CONTROL_0_T IDM_DETECTION_CONTROL_0_CH3;
   uint32_t IDM_DETECTION_CONTROL_3_CH3;
} MIPI_SFRS_t;

extern MIPI_SFRS_t g_mipi_sfr_stub;
#define MIPI_base (&g_mipi_sfr_stub)
#define HELPERS_ATTRIBUTES

extern uint32_t g_ra_reg_space_stub[2];
extern uint32_t g_mipi_stat_mem_stub[64];
extern uint32_t g_ra_mem_stub[1600];

#define RA_base            ((uintptr_t)g_ra_reg_space_stub)
#define MIPI_STAT_MEM_base ((uintptr_t)g_mipi_stat_mem_stub)
#define RA_MEM_base        ((uintptr_t)g_ra_mem_stub)

/* IDM Config type */
typedef struct
{
   uint16_t k_idm_chX_detection_ena;
   uint16_t k_idm_chX_square_accum_sel;
   uint16_t k_idm_chX_abs_prog_shift;
   uint16_t k_idm_chX_abs_prog_mult;
   uint16_t k_idm_chX_abs_thr;
   uint16_t k_idm_chX_abs_sel;
   uint16_t k_idm_chX_diff_abs_prog_shift;
   uint16_t k_idm_chX_diff_abs_prog_mult;
   uint16_t k_idm_chX_diff_abs_thr;
   uint16_t k_idm_chX_diff_abs_sel;
   uint16_t k_idm_chX_detection_mode;
   uint16_t k_idm_chX_pollution_weight[7];
   uint16_t k_idm_chX_pollution_weight_thr;
   uint16_t dc_estimation_enable;
   uint16_t dc_acc_prog_shift;
   uint16_t dc_acc_prog_mult;
   uint16_t dc_estimation_start_samples;
   uint16_t dc_estimation_no_of_samples;
   uint16_t dc_hardcoded_threshold_enable;
   uint16_t dc_compensation_control;
   uint16_t dc_hardcoded_threshold;
   uint16_t k_idm_chX_mitigation_byp;
   uint16_t k_idm_chX_mitigation_mode;
   uint16_t k_idm_chX_zero_window_size;
   uint16_t idm_statmem_ctrl;
} Idm_Config_T;

/* RIDM config type */
typedef struct
{
   uint16_t stretching_factor1;
   uint16_t stretching_factor2;
   uint16_t max_polluted_samples;
   uint8_t discard_whole_chirp_en;
   uint16_t user_defined_stretching_function_en;
   uint16_t user_defined_stretching_function;
   float32_t dynamicStretchFactor;
   uint8_t forward_idm_detection_ch0;
   uint16_t segment_size_ch0;
   int8_t forward_idm_detection_ch1;
   uint16_t segment_size_ch1;
   uint8_t forward_idm_detection_ch2;
   uint16_t segment_size_ch2;
   uint8_t forward_idm_detection_ch3;
   uint16_t segment_size_ch3;
} Ridm_Config_T;

/* Mipi stats debug */
typedef struct
{
   uint8_t data[256];
} Mipi_Stats_Debug_T;

/*---------------------------------------------------------------------------*
 * Typedef for pointer-to-array types that FFF macros cannot handle directly.
 * FFF appends the variable name after the type, but (*)[N][M] needs the name
 * inside the parentheses: type (*name)[N][M].  Using a typedef sidesteps this.
 *---------------------------------------------------------------------------*/
typedef volatile uint16_t (*ff_threshold_buf_t)[MAX_NUM_FF_GROUPS][NUM_RX_CHANNELS];

/* Stream types for D2M */
typedef struct
{
   uint32_t scan_index;
   uint32_t size;
} Stream_Hdr_T;
typedef struct
{
   uint32_t scan_index;
   uint32_t look_id;
} Look_Data_T;
typedef struct
{
   Stream_Hdr_T stream_hdr;
   uint8_t idm_stat_data[256];
} Rdd_Debug_Stream_T;
typedef struct
{
   Stream_Hdr_T stream_hdr;
   Look_Data_T look_data;
} Rdd_Stream_T;
typedef struct
{
   Rdd_Stream_T rdd_stream_data;
   Rdd_Debug_Stream_T rdd_debug_data;
} D2M_Payload_T;
typedef struct
{
   uint32_t size;
} D2M_Header_T;
typedef struct
{
   D2M_Header_T header;
   D2M_Payload_T payload;
} D2M_Msg_T;

/* SMC calibration arrays */
extern uint16_t k_idm_ch0_detection_ena_smc[];
extern uint16_t k_idm_ch0_square_accum_sel_smc[];
extern uint16_t k_idm_ch0_abs_prog_shift_smc[];
extern uint16_t k_idm_ch0_abs_prog_mult_smc[];
extern uint16_t k_idm_ch0_abs_thr_smc[];
extern uint16_t k_idm_ch0_abs_sel_smc[];
extern uint16_t k_idm_ch0_diff_abs_prog_shift_smc[];
extern uint16_t k_idm_ch0_diff_abs_prog_mult_smc[];
extern uint16_t k_idm_ch0_diff_abs_thr_smc[];
extern uint16_t k_idm_ch0_diff_abs_sel_smc[];
extern uint16_t k_idm_ch0_detection_mode_smc[];
extern uint16_t k_idm_ch0_pollution_weight_smc[][7];
extern uint16_t k_idm_ch0_pollution_weight_thr_smc[];
extern uint16_t k_dc_ch0_estimation_ena_smc[];
extern uint16_t k_dc_ch0_accum_prog_shift_smc[];
extern uint16_t k_dc_ch0_accum_prog_mult_smc[];
extern uint16_t k_dc_ch0_estimation_start_sample_smc[];
extern uint16_t k_dc_ch0_estimation_n_samples_smc[];
extern uint16_t k_dc_ch0_hardcoded_thr_ena_smc[];
extern uint16_t k_dc_ch0_compensation_byp_smc[];
extern uint32_t k_dc_ch0_hardcoded_thr_smc[];
extern uint16_t k_idm_ch0_mitigation_byp_smc[];
extern uint16_t k_idm_ch0_mitigation_mode_smc[];
extern uint16_t k_idm_ch0_zero_window_size_smc[];
extern uint16_t k_idm_stat_mem_ctrl_ch0_smc[];

/* Ch1-3 externs (repeat for ch1, ch2, ch3) */
extern uint16_t k_idm_ch1_detection_ena_smc[], k_idm_ch2_detection_ena_smc[], k_idm_ch3_detection_ena_smc[];
extern uint16_t k_idm_ch1_square_accum_sel_smc[], k_idm_ch2_square_accum_sel_smc[], k_idm_ch3_square_accum_sel_smc[];
extern uint16_t k_idm_ch1_abs_prog_shift_smc[], k_idm_ch2_abs_prog_shift_smc[], k_idm_ch3_abs_prog_shift_smc[];
extern uint16_t k_idm_ch1_abs_prog_mult_smc[], k_idm_ch2_abs_prog_mult_smc[], k_idm_ch3_abs_prog_mult_smc[];
extern uint16_t k_idm_ch1_abs_thr_smc[], k_idm_ch2_abs_thr_smc[], k_idm_ch3_abs_thr_smc[];
extern uint16_t k_idm_ch1_abs_sel_smc[], k_idm_ch2_abs_sel_smc[], k_idm_ch3_abs_sel_smc[];
extern uint16_t k_idm_ch1_diff_abs_prog_shift_smc[], k_idm_ch2_diff_abs_prog_shift_smc[], k_idm_ch3_diff_abs_prog_shift_smc[];
extern uint16_t k_idm_ch1_diff_abs_prog_mult_smc[], k_idm_ch2_diff_abs_prog_mult_smc[], k_idm_ch3_diff_abs_prog_mult_smc[];
extern uint16_t k_idm_ch1_diff_abs_thr_smc[], k_idm_ch2_diff_abs_thr_smc[], k_idm_ch3_diff_abs_thr_smc[];
extern uint16_t k_idm_ch1_diff_abs_sel_smc[], k_idm_ch2_diff_abs_sel_smc[], k_idm_ch3_diff_abs_sel_smc[];
extern uint16_t k_idm_ch1_detection_mode_smc[], k_idm_ch2_detection_mode_smc[], k_idm_ch3_detection_mode_smc[];
extern uint16_t k_idm_ch1_pollution_weight_smc[][7], k_idm_ch2_pollution_weight_smc[][7], k_idm_ch3_pollution_weight_smc[][7];
extern uint16_t k_idm_ch1_pollution_weight_thr_smc[], k_idm_ch2_pollution_weight_thr_smc[], k_idm_ch3_pollution_weight_thr_smc[];
extern uint16_t k_dc_ch1_estimation_ena_smc[], k_dc_ch2_estimation_ena_smc[], k_dc_ch3_estimation_ena_smc[];
extern uint16_t k_dc_ch1_accum_prog_shift_smc[], k_dc_ch2_accum_prog_shift_smc[], k_dc_ch3_accum_prog_shift_smc[];
extern uint16_t k_dc_ch1_accum_prog_mult_smc[], k_dc_ch2_accum_prog_mult_smc[], k_dc_ch3_accum_prog_mult_smc[];
extern uint16_t k_dc_ch1_estimation_start_sample_smc[], k_dc_ch2_estimation_start_sample_smc[],
   k_dc_ch3_estimation_start_sample_smc[];
extern uint16_t k_dc_ch1_estimation_n_samples_smc[], k_dc_ch2_estimation_n_samples_smc[], k_dc_ch3_estimation_n_samples_smc[];
extern uint16_t k_dc_ch1_hardcoded_thr_ena_smc[], k_dc_ch2_hardcoded_thr_ena_smc[], k_dc_ch3_hardcoded_thr_ena_smc[];
extern uint16_t k_dc_ch1_compensation_byp_smc[], k_dc_ch2_compensation_byp_smc[], k_dc_ch3_compensation_byp_smc[];
extern uint32_t k_dc_ch1_hardcoded_thr_smc[], k_dc_ch2_hardcoded_thr_smc[], k_dc_ch3_hardcoded_thr_smc[];
extern uint16_t k_idm_ch1_mitigation_byp_smc[], k_idm_ch2_mitigation_byp_smc[], k_idm_ch3_mitigation_byp_smc[];
extern uint16_t k_idm_ch1_mitigation_mode_smc[], k_idm_ch2_mitigation_mode_smc[], k_idm_ch3_mitigation_mode_smc[];
extern uint16_t k_idm_ch1_zero_window_size_smc[], k_idm_ch2_zero_window_size_smc[], k_idm_ch3_zero_window_size_smc[];
extern uint16_t k_idm_stat_mem_ctrl_ch1_smc[], k_idm_stat_mem_ctrl_ch2_smc[], k_idm_stat_mem_ctrl_ch3_smc[];
extern uint16_t k_forward_interference_det_control_stretch_factor_shift_1_smc[];
extern uint16_t k_forward_interference_det_control_stretch_factor_shift_2_smc[];
extern uint16_t k_forward_interference_detection_control_max_polluted_samples_smc[];
extern uint16_t k_forward_interference_detection_control_discard_whole_chirp_en_smc[];
extern uint16_t k_forward_interference_det_control_user_def_stretch_fun_en_smc[];
extern uint16_t k_forward_interference_det_control_user_def_stretch_fun_smc[];
extern uint16_t k_idm_ch0_forward_interference_detection_smc[];
extern uint16_t k_idm_ch0_segment_size_smc[];
extern uint16_t k_idm_ch1_forward_interference_detection_smc[];
extern uint16_t k_idm_ch1_segment_size_smc[];
extern uint16_t k_idm_ch2_forward_interference_detection_smc[];
extern uint16_t k_idm_ch2_segment_size_smc[];
extern uint16_t k_idm_ch3_forward_interference_detection_smc[];
extern uint16_t k_idm_ch3_segment_size_smc[];

extern uint8_t k_idm_feedforward_chirp_group_smc[][K_MAX];
extern uint32_t M_FRAME[];

/*===========================================================================*
 * FFF mocks
 *===========================================================================*/
DECLARE_FAKE_VALUE_FUNC(volatile D2M_Msg_T *, Get_RP_IPC_D2M_Msg_Buffer);

/* MIPI helpers */
DECLARE_FAKE_VOID_FUNC(Mipi_Helpers_Idm_Config_Ch0, Idm_Config_T *);
DECLARE_FAKE_VOID_FUNC(Mipi_Helpers_Idm_Config_Ch1, Idm_Config_T *);
DECLARE_FAKE_VOID_FUNC(Mipi_Helpers_Idm_Config_Ch2, Idm_Config_T *);
DECLARE_FAKE_VOID_FUNC(Mipi_Helpers_Idm_Config_Ch3, Idm_Config_T *);
DECLARE_FAKE_VOID_FUNC(Mipi_Clear_Idm_Stats);
DECLARE_FAKE_VOID_FUNC(Mipi_Helpers_Clear_Chirp_End_Flag);
DECLARE_FAKE_VOID_FUNC(Mipi_Helpers_Chirp_End_IRQ_Enable, bool);
DECLARE_FAKE_VOID_FUNC(Mipi_Helpers_Transposer_Bypass_Config, bool);
DECLARE_FAKE_VOID_FUNC(Mipi_Read_Idm_Stats, Mipi_Stats_Debug_T *, uint32_t);
DECLARE_FAKE_VOID_FUNC(Mipi_Helpers_Resto_Idm_CommongCfg, Ridm_Config_T *);
DECLARE_FAKE_VOID_FUNC(Mipi_Helpers_Resto_Idm_Config_Ch0, Ridm_Config_T *);
DECLARE_FAKE_VOID_FUNC(Mipi_Helpers_Resto_Idm_Config_Ch1, Ridm_Config_T *);
DECLARE_FAKE_VOID_FUNC(Mipi_Helpers_Resto_Idm_Config_Ch2, Ridm_Config_T *);
DECLARE_FAKE_VOID_FUNC(Mipi_Helpers_Resto_Idm_Config_Ch3, Ridm_Config_T *);

/* Range process */
DECLARE_FAKE_VOID_FUNC(Appl_Range_Process_Push_Ra_Commands);

/* Timing */
DECLARE_FAKE_VALUE_FUNC(uint32_t, Timing_Helpers_Get_Timestamp);
DECLARE_FAKE_VALUE_FUNC(uint32_t, Timing_Helpers_Get_Time_Nanosec, uint32_t);

/* vector_copy_unaligned */
DECLARE_FAKE_VOID_FUNC(vector_copy_unaligned, void *, void *, uint32_t);

static inline float32_t get_recip(float32_t val)
{
   return (val != 0.0f) ? (1.0f / val) : 0.0f;
}
