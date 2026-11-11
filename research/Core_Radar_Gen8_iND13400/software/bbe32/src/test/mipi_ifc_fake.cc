/*===========================================================================*/
/**
 * @file mipi_ifc_fake.cc
 *
 * FFF fake definitions for mipi_ifc.c unit tests.
 */
/*==========================================================================*/
#include "mipi_ifc_fake.h"

DEFINE_FFF_GLOBALS

Offline_Mode_T Offline_Mode_Flag_DSP = 0U;

MIPI_SFRS_t g_mipi_sfr_stub       = {};
uint32_t g_ra_reg_space_stub[2]   = {0U};
uint32_t g_mipi_stat_mem_stub[64] = {0U};
uint32_t g_ra_mem_stub[1600]      = {0U};

/* SMC calibration stubs - all channels, 8 look types */
#define SMC_ARRAY_SIZE 8
uint16_t k_idm_ch0_detection_ena_smc[SMC_ARRAY_SIZE]          = {0};
uint16_t k_idm_ch0_square_accum_sel_smc[SMC_ARRAY_SIZE]       = {0};
uint16_t k_idm_ch0_abs_prog_shift_smc[SMC_ARRAY_SIZE]         = {0};
uint16_t k_idm_ch0_abs_prog_mult_smc[SMC_ARRAY_SIZE]          = {0};
uint16_t k_idm_ch0_abs_thr_smc[SMC_ARRAY_SIZE]                = {0};
uint16_t k_idm_ch0_abs_sel_smc[SMC_ARRAY_SIZE]                = {0};
uint16_t k_idm_ch0_diff_abs_prog_shift_smc[SMC_ARRAY_SIZE]    = {0};
uint16_t k_idm_ch0_diff_abs_prog_mult_smc[SMC_ARRAY_SIZE]     = {0};
uint16_t k_idm_ch0_diff_abs_thr_smc[SMC_ARRAY_SIZE]           = {0};
uint16_t k_idm_ch0_diff_abs_sel_smc[SMC_ARRAY_SIZE]           = {0};
uint16_t k_idm_ch0_detection_mode_smc[SMC_ARRAY_SIZE]         = {0};
uint16_t k_idm_ch0_pollution_weight_smc[SMC_ARRAY_SIZE][7]    = {{0}};
uint16_t k_idm_ch0_pollution_weight_thr_smc[SMC_ARRAY_SIZE]   = {0};
uint16_t k_dc_ch0_estimation_ena_smc[SMC_ARRAY_SIZE]          = {0};
uint16_t k_dc_ch0_accum_prog_shift_smc[SMC_ARRAY_SIZE]        = {0};
uint16_t k_dc_ch0_accum_prog_mult_smc[SMC_ARRAY_SIZE]         = {0};
uint16_t k_dc_ch0_estimation_start_sample_smc[SMC_ARRAY_SIZE] = {0};
uint16_t k_dc_ch0_estimation_n_samples_smc[SMC_ARRAY_SIZE]    = {0};
uint16_t k_dc_ch0_hardcoded_thr_ena_smc[SMC_ARRAY_SIZE]       = {0};
uint16_t k_dc_ch0_compensation_byp_smc[SMC_ARRAY_SIZE]        = {0};
uint32_t k_dc_ch0_hardcoded_thr_smc[SMC_ARRAY_SIZE]           = {0};
uint16_t k_idm_ch0_mitigation_byp_smc[SMC_ARRAY_SIZE]         = {0};
uint16_t k_idm_ch0_mitigation_mode_smc[SMC_ARRAY_SIZE]        = {0};
uint16_t k_idm_ch0_zero_window_size_smc[SMC_ARRAY_SIZE]       = {0};
uint16_t k_idm_stat_mem_ctrl_ch0_smc[SMC_ARRAY_SIZE]          = {0};

/* Repeat for ch1 */
uint16_t k_idm_ch1_detection_ena_smc[SMC_ARRAY_SIZE]          = {0};
uint16_t k_idm_ch1_square_accum_sel_smc[SMC_ARRAY_SIZE]       = {0};
uint16_t k_idm_ch1_abs_prog_shift_smc[SMC_ARRAY_SIZE]         = {0};
uint16_t k_idm_ch1_abs_prog_mult_smc[SMC_ARRAY_SIZE]          = {0};
uint16_t k_idm_ch1_abs_thr_smc[SMC_ARRAY_SIZE]                = {0};
uint16_t k_idm_ch1_abs_sel_smc[SMC_ARRAY_SIZE]                = {0};
uint16_t k_idm_ch1_diff_abs_prog_shift_smc[SMC_ARRAY_SIZE]    = {0};
uint16_t k_idm_ch1_diff_abs_prog_mult_smc[SMC_ARRAY_SIZE]     = {0};
uint16_t k_idm_ch1_diff_abs_thr_smc[SMC_ARRAY_SIZE]           = {0};
uint16_t k_idm_ch1_diff_abs_sel_smc[SMC_ARRAY_SIZE]           = {0};
uint16_t k_idm_ch1_detection_mode_smc[SMC_ARRAY_SIZE]         = {0};
uint16_t k_idm_ch1_pollution_weight_smc[SMC_ARRAY_SIZE][7]    = {{0}};
uint16_t k_idm_ch1_pollution_weight_thr_smc[SMC_ARRAY_SIZE]   = {0};
uint16_t k_dc_ch1_estimation_ena_smc[SMC_ARRAY_SIZE]          = {0};
uint16_t k_dc_ch1_accum_prog_shift_smc[SMC_ARRAY_SIZE]        = {0};
uint16_t k_dc_ch1_accum_prog_mult_smc[SMC_ARRAY_SIZE]         = {0};
uint16_t k_dc_ch1_estimation_start_sample_smc[SMC_ARRAY_SIZE] = {0};
uint16_t k_dc_ch1_estimation_n_samples_smc[SMC_ARRAY_SIZE]    = {0};
uint16_t k_dc_ch1_hardcoded_thr_ena_smc[SMC_ARRAY_SIZE]       = {0};
uint16_t k_dc_ch1_compensation_byp_smc[SMC_ARRAY_SIZE]        = {0};
uint32_t k_dc_ch1_hardcoded_thr_smc[SMC_ARRAY_SIZE]           = {0};
uint16_t k_idm_ch1_mitigation_byp_smc[SMC_ARRAY_SIZE]         = {0};
uint16_t k_idm_ch1_mitigation_mode_smc[SMC_ARRAY_SIZE]        = {0};
uint16_t k_idm_ch1_zero_window_size_smc[SMC_ARRAY_SIZE]       = {0};
uint16_t k_idm_stat_mem_ctrl_ch1_smc[SMC_ARRAY_SIZE]          = {0};

/* Repeat for ch2 */
uint16_t k_idm_ch2_detection_ena_smc[SMC_ARRAY_SIZE]          = {0};
uint16_t k_idm_ch2_square_accum_sel_smc[SMC_ARRAY_SIZE]       = {0};
uint16_t k_idm_ch2_abs_prog_shift_smc[SMC_ARRAY_SIZE]         = {0};
uint16_t k_idm_ch2_abs_prog_mult_smc[SMC_ARRAY_SIZE]          = {0};
uint16_t k_idm_ch2_abs_thr_smc[SMC_ARRAY_SIZE]                = {0};
uint16_t k_idm_ch2_abs_sel_smc[SMC_ARRAY_SIZE]                = {0};
uint16_t k_idm_ch2_diff_abs_prog_shift_smc[SMC_ARRAY_SIZE]    = {0};
uint16_t k_idm_ch2_diff_abs_prog_mult_smc[SMC_ARRAY_SIZE]     = {0};
uint16_t k_idm_ch2_diff_abs_thr_smc[SMC_ARRAY_SIZE]           = {0};
uint16_t k_idm_ch2_diff_abs_sel_smc[SMC_ARRAY_SIZE]           = {0};
uint16_t k_idm_ch2_detection_mode_smc[SMC_ARRAY_SIZE]         = {0};
uint16_t k_idm_ch2_pollution_weight_smc[SMC_ARRAY_SIZE][7]    = {{0}};
uint16_t k_idm_ch2_pollution_weight_thr_smc[SMC_ARRAY_SIZE]   = {0};
uint16_t k_dc_ch2_estimation_ena_smc[SMC_ARRAY_SIZE]          = {0};
uint16_t k_dc_ch2_accum_prog_shift_smc[SMC_ARRAY_SIZE]        = {0};
uint16_t k_dc_ch2_accum_prog_mult_smc[SMC_ARRAY_SIZE]         = {0};
uint16_t k_dc_ch2_estimation_start_sample_smc[SMC_ARRAY_SIZE] = {0};
uint16_t k_dc_ch2_estimation_n_samples_smc[SMC_ARRAY_SIZE]    = {0};
uint16_t k_dc_ch2_hardcoded_thr_ena_smc[SMC_ARRAY_SIZE]       = {0};
uint16_t k_dc_ch2_compensation_byp_smc[SMC_ARRAY_SIZE]        = {0};
uint32_t k_dc_ch2_hardcoded_thr_smc[SMC_ARRAY_SIZE]           = {0};
uint16_t k_idm_ch2_mitigation_byp_smc[SMC_ARRAY_SIZE]         = {0};
uint16_t k_idm_ch2_mitigation_mode_smc[SMC_ARRAY_SIZE]        = {0};
uint16_t k_idm_ch2_zero_window_size_smc[SMC_ARRAY_SIZE]       = {0};
uint16_t k_idm_stat_mem_ctrl_ch2_smc[SMC_ARRAY_SIZE]          = {0};

/* Repeat for ch3 */
uint16_t k_idm_ch3_detection_ena_smc[SMC_ARRAY_SIZE]                                         = {0};
uint16_t k_idm_ch3_square_accum_sel_smc[SMC_ARRAY_SIZE]                                      = {0};
uint16_t k_idm_ch3_abs_prog_shift_smc[SMC_ARRAY_SIZE]                                        = {0};
uint16_t k_idm_ch3_abs_prog_mult_smc[SMC_ARRAY_SIZE]                                         = {0};
uint16_t k_idm_ch3_abs_thr_smc[SMC_ARRAY_SIZE]                                               = {0};
uint16_t k_idm_ch3_abs_sel_smc[SMC_ARRAY_SIZE]                                               = {0};
uint16_t k_idm_ch3_diff_abs_prog_shift_smc[SMC_ARRAY_SIZE]                                   = {0};
uint16_t k_idm_ch3_diff_abs_prog_mult_smc[SMC_ARRAY_SIZE]                                    = {0};
uint16_t k_idm_ch3_diff_abs_thr_smc[SMC_ARRAY_SIZE]                                          = {0};
uint16_t k_idm_ch3_diff_abs_sel_smc[SMC_ARRAY_SIZE]                                          = {0};
uint16_t k_idm_ch3_detection_mode_smc[SMC_ARRAY_SIZE]                                        = {0};
uint16_t k_idm_ch3_pollution_weight_smc[SMC_ARRAY_SIZE][7]                                   = {{0}};
uint16_t k_idm_ch3_pollution_weight_thr_smc[SMC_ARRAY_SIZE]                                  = {0};
uint16_t k_dc_ch3_estimation_ena_smc[SMC_ARRAY_SIZE]                                         = {0};
uint16_t k_dc_ch3_accum_prog_shift_smc[SMC_ARRAY_SIZE]                                       = {0};
uint16_t k_dc_ch3_accum_prog_mult_smc[SMC_ARRAY_SIZE]                                        = {0};
uint16_t k_dc_ch3_estimation_start_sample_smc[SMC_ARRAY_SIZE]                                = {0};
uint16_t k_dc_ch3_estimation_n_samples_smc[SMC_ARRAY_SIZE]                                   = {0};
uint16_t k_dc_ch3_hardcoded_thr_ena_smc[SMC_ARRAY_SIZE]                                      = {0};
uint16_t k_dc_ch3_compensation_byp_smc[SMC_ARRAY_SIZE]                                       = {0};
uint32_t k_dc_ch3_hardcoded_thr_smc[SMC_ARRAY_SIZE]                                          = {0};
uint16_t k_idm_ch3_mitigation_byp_smc[SMC_ARRAY_SIZE]                                        = {0};
uint16_t k_idm_ch3_mitigation_mode_smc[SMC_ARRAY_SIZE]                                       = {0};
uint16_t k_idm_ch3_zero_window_size_smc[SMC_ARRAY_SIZE]                                      = {0};
uint16_t k_idm_stat_mem_ctrl_ch3_smc[SMC_ARRAY_SIZE]                                         = {0};
uint16_t k_forward_interference_det_control_stretch_factor_shift_1_smc[SMC_ARRAY_SIZE]       = {0};
uint16_t k_forward_interference_det_control_stretch_factor_shift_2_smc[SMC_ARRAY_SIZE]       = {0};
uint16_t k_forward_interference_detection_control_max_polluted_samples_smc[SMC_ARRAY_SIZE]   = {0};
uint16_t k_forward_interference_detection_control_discard_whole_chirp_en_smc[SMC_ARRAY_SIZE] = {0};
uint16_t k_forward_interference_det_control_user_def_stretch_fun_en_smc[SMC_ARRAY_SIZE]      = {0};
uint16_t k_forward_interference_det_control_user_def_stretch_fun_smc[SMC_ARRAY_SIZE]         = {0};
uint16_t k_idm_ch0_forward_interference_detection_smc[SMC_ARRAY_SIZE]                        = {0};
uint16_t k_idm_ch0_segment_size_smc[SMC_ARRAY_SIZE]                                          = {0};
uint16_t k_idm_ch1_forward_interference_detection_smc[SMC_ARRAY_SIZE]                        = {0};
uint16_t k_idm_ch1_segment_size_smc[SMC_ARRAY_SIZE]                                          = {0};
uint16_t k_idm_ch2_forward_interference_detection_smc[SMC_ARRAY_SIZE]                        = {0};
uint16_t k_idm_ch2_segment_size_smc[SMC_ARRAY_SIZE]                                          = {0};
uint16_t k_idm_ch3_forward_interference_detection_smc[SMC_ARRAY_SIZE]                        = {0};
uint16_t k_idm_ch3_segment_size_smc[SMC_ARRAY_SIZE]                                          = {0};

/* Feed forward calibrations */
uint8_t k_idm_feedforward_chirp_group_smc[SMC_ARRAY_SIZE][K_MAX] = {{0}};
uint32_t M_FRAME[SMC_ARRAY_SIZE]                                 = {256, 256, 256, 256, 256, 256, 256, 256};

/* IPC */
DEFINE_FAKE_VALUE_FUNC(volatile D2M_Msg_T *, Get_RP_IPC_D2M_Msg_Buffer);

/* MIPI helpers */
DEFINE_FAKE_VOID_FUNC(Mipi_Helpers_Idm_Config_Ch0, Idm_Config_T *);
DEFINE_FAKE_VOID_FUNC(Mipi_Helpers_Idm_Config_Ch1, Idm_Config_T *);
DEFINE_FAKE_VOID_FUNC(Mipi_Helpers_Idm_Config_Ch2, Idm_Config_T *);
DEFINE_FAKE_VOID_FUNC(Mipi_Helpers_Idm_Config_Ch3, Idm_Config_T *);
DEFINE_FAKE_VOID_FUNC(Mipi_Clear_Idm_Stats);
DEFINE_FAKE_VOID_FUNC(Mipi_Helpers_Clear_Chirp_End_Flag);
DEFINE_FAKE_VOID_FUNC(Mipi_Helpers_Chirp_End_IRQ_Enable, bool);
DEFINE_FAKE_VOID_FUNC(Mipi_Helpers_Transposer_Bypass_Config, bool);
DEFINE_FAKE_VOID_FUNC(Mipi_Read_Idm_Stats, Mipi_Stats_Debug_T *, uint32_t);
DEFINE_FAKE_VOID_FUNC(Mipi_Helpers_Resto_Idm_CommongCfg, Ridm_Config_T *);
DEFINE_FAKE_VOID_FUNC(Mipi_Helpers_Resto_Idm_Config_Ch0, Ridm_Config_T *);
DEFINE_FAKE_VOID_FUNC(Mipi_Helpers_Resto_Idm_Config_Ch1, Ridm_Config_T *);
DEFINE_FAKE_VOID_FUNC(Mipi_Helpers_Resto_Idm_Config_Ch2, Ridm_Config_T *);
DEFINE_FAKE_VOID_FUNC(Mipi_Helpers_Resto_Idm_Config_Ch3, Ridm_Config_T *);

/* Range process */
DEFINE_FAKE_VOID_FUNC(Appl_Range_Process_Push_Ra_Commands);

/* Timing */
DEFINE_FAKE_VALUE_FUNC(uint32_t, Timing_Helpers_Get_Timestamp);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Timing_Helpers_Get_Time_Nanosec, uint32_t);

/* vector_copy */
DEFINE_FAKE_VOID_FUNC(vector_copy_unaligned, void *, void *, uint32_t);
