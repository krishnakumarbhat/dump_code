/*===================================================================================*\
 * FILE: rc_wrapper.c
 *====================================================================================
 * Copyright (C) 2022 Aptiv Advanced Safety and User Experience. All rights reserved.
 * Confidential - Restricted Aptiv information. Do not disclose."
 *-----------------------------------------------------------------------------------------
 * DESCRIPTION:
 * This file contains the main function for the Radar Capability Wrapper
 *
 *
 * Applicable Standards (in order of precedence: highest first):
 * ESGW_4-2_PE-SWX_00-01-A01_EN, "APTIV C++ Coding Standards"[May 26, 2019]
 * ESGW_4-2_PE-SWX_00-01-A02_EN "APTIV C Coding Standards" [12-Mar-2006]
 ***/
/*===========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/*===========================================================================*
 * Header Files
 *===========================================================================*/

#include "rc_wrapper.h"
#include "dyn_align_wrapper.h"
#include "mmic_common_types.h"
#include "radar_capability.h"
#include "rc_diagnostics.h"
#include "rc_support.h"
#include "rc_types.h"
#include "rcbb_include.h"
#include "reuse.h"

#ifdef RC_FAULT_INJECION_ENABLED
   #include "rc_fi_wrapper.h"
#endif

#ifdef PC_RESIM
   #define RC_NUM_INSTANCES (7)
#else
   #define RC_NUM_INSTANCES (1)
#endif
static RC_Memory_T __attribute__((section(".sram0.bss"))) rc_memory[RC_NUM_INSTANCES];
static uint8_t __attribute__((section(".sram0.bss"))) rc_memory_index = 0;

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
static void rc_input_init(RC_Input_T *p_rc_input);
static void mapping_det(Detection_Stream_T *const p_ipc_det, RC_Detection_Input_T *const p_rc_det, const bool f_is_FLR_sensor);
static void mapping_rdd(Rdd_Stream_T *p_ipc_rdd, RC_Rdd_Input_T *p_rc_rdd);
static void mapping_id(ID_Stream_T *ipc_id, RC_ID_Input_T *rc_id);
static void mapping_dyn(Dynamic_Alignment_Log_Stream_T *p_ipc_dyn, RC_Dynamic_Alignment_Log_Input_T *p_rc_dyn);
static void mapping_veh(Vse_Stream_T *p_ipc_vse, RC_Vse_Input_T *p_rc_vse);
static void rc_wrapper_map_input_data(RC_Input_Data_T *rc_ipc_data, RC_Input_T *const p_rc_input);
static void Mapping_ipc_to_rc_input(RC_Input_Data_T *rc_ipc_data, RC_Input_T *p_rc_input);
static void rc_ptr_update(D2M_Msg_T *p_ipc_d2m, M2D_Msg_T *p_ipc_m2d, RC_Input_Data_T *rc_ipc_data_ptr,
                          M2D_One_Time_Msg_T *m2d_one_time_init_ptr);

/* ========================================================================== */
/*                            Static Variables                                */
/* ========================================================================== */
static RC_Internal_Mem_Info_T RC_Internal_Mem_Info[RC_MP_MAX_NUM_MEMORY_LOC];
#ifdef PSP_SIL_ENABLE
static RC_Input_T rc_input_data;
static RC_Input_T *rc_input = &rc_input_data;
#else
static RC_Input_T *rc_input;
#endif

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
#ifdef BLOCKAGE_TEST
volatile float32_t Veh_speed_test_blk = 10.0F;
#endif

/*===========================================================================*
 * SWE5 Integration Testing Support
 *===========================================================================*/
#include "dsp_it_macros_test.h"

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
/*****************************************************************************
 *. Name: Get_RC_Internal_memory_pointers
 *. This function will get the memory pointer to all Capability structures
 *.
 *. Parameters:
 *. void
 *.
 *. Return Value: RC_Internal_Mem_Info_T
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
RC_Internal_Mem_Info_T *Get_RC_Internal_memory_pointers(void)
{
   /* Clear memory details before assign*/
   (void)memset(RC_Internal_Mem_Info, 0U, sizeof(RC_Internal_Mem_Info));

   /*Assign required memory*/
   RC_Internal_Mem_Info[0].size     = sizeof(*rc_input);
   RC_Internal_Mem_Info[0].addr_ptr = (void **)&rc_input;
   return &RC_Internal_Mem_Info[0];
}
/*****************************************************************************
 *. Name: Capability_Handler_Memory_Init
 *. This function will allocate memory from mempool for all Capability structures
 *.
 *. Parameters:
 *. Mem_Pool_T *
 *.
 *. Return Value: Memory_Pool_Return_T
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 ******************************************************************************/
Memory_Pool_Return_T Capability_Handler_Memory_Init(Mem_Pool_T *mem_pool)
{
   Memory_Pool_Return_T retVal = MEM_POOL_SUCCESS;
   uint8_t mem_loc             = 0U;

   RC_Internal_Mem_Info_T *RC_Internal_memory_ptr = Get_RC_Internal_memory_pointers();

   do
   {
      if ((NULL != RC_Internal_memory_ptr[mem_loc].addr_ptr) && (0U != RC_Internal_memory_ptr[mem_loc].size))
      {
         retVal = Mem_Pool_Alloc(mem_pool, RC_Internal_memory_ptr[mem_loc].size, RC_Internal_memory_ptr[mem_loc].addr_ptr);
      }
      mem_loc++;
   } while ((MEM_POOL_SUCCESS == retVal) && (mem_loc < (uint8_t)RC_MP_MAX_NUM_MEMORY_LOC));

   return retVal;
}

uint8_t rc_get_ver_major(void)
{
   return (uint8_t)(RC_VER_MAJOR);
}

uint8_t rc_get_ver_minor(void)
{
   return (uint8_t)(RC_VER_MINOR);
}

uint8_t rc_get_ver_patch(void)
{
   return (uint8_t)(RC_VER_PATCH);
}

#ifdef PC_RESIM
bool rc_wrapper_update_memory_instance(const uint8_t rc_new_memory_index)
{
   bool f_updated_ok = false;
   if (rc_new_memory_index < RC_NUM_INSTANCES)
   {
      rc_memory_index = rc_new_memory_index;
      f_updated_ok    = true;
   }
   return f_updated_ok;
}
#endif

void rc_wrapper_reset(void)
{
   // Update memory
   rc_reset(&rc_memory[rc_memory_index]);

#ifdef RC_FAULT_INJECION_ENABLED
   rc_fiw_reset();
#endif
}

#ifdef RC_FAULT_INJECION_ENABLED
void rc_wrapper_set_injected_fault_num(const uint8_t fault_num)
{
   rc_fiw_set_fault_num(fault_num);
}
#endif
static void rc_input_init(RC_Input_T *p_rc_input)
{
   // calib
   p_rc_input->rc_cals.smc_platform = (uint8_t)RC_PLATFORM_Invalid;
   p_rc_input->rc_cals.usc_platform = (uint8_t)RC_PLATFORM_Invalid;

   // time
   p_rc_input->p_middle_of_dwell_ts.ts_nanosecs = 0;
   p_rc_input->p_middle_of_dwell_ts.ts_secs     = 0;
   p_rc_input->p_middle_of_dwell_ts.ts_status   = 0;

   // det
   uint32_t i;
   memset(&p_rc_input->p_det_data, 0, sizeof(p_rc_input->p_det_data));
   p_rc_input->p_det_data.det_list_property.look_type = RC_NUM_LOOK_TYPES;
   for (i = 0; i < RC_AF_MAX_NUM_DET; i++)
   {
      p_rc_input->p_det_data.af_data[i].stage       = 1;
      p_rc_input->p_det_data.af_data[i].spacingtype = 1;
   }

   // rdd
   p_rc_input->p_rdd_stream_data.look_data.look_id        = RC_NUM_LOOK_TYPES;
   p_rc_input->p_rdd_stream_data.look_data.scan_index     = 0;
   p_rc_input->p_rdd_stream_data.look_data.range_coverage = 0.0F;
   p_rc_input->p_rdd_stream_data.look_data.vua            = 0.0F;

   p_rc_input->p_rdd_stream_data.rdd_data.cfar_nf_est            = NULL;
   p_rc_input->p_rdd_stream_data.rdd_data.rdd1_max_per_range_bin = NULL;

   p_rc_input->p_rdd_stream_data.rfft_data.interfered_samples_per_frame = 0U;

   // veh
   p_rc_input->p_veh_data.scan_index = 0;
   p_rc_input->p_veh_data.veh_speed  = RC_INVALID_SPEED;
   p_rc_input->p_veh_data.veh_yaw    = RC_INVALID_YAW;

   // Id
   p_rc_input->p_id_data.scan_index    = 0;
   p_rc_input->p_id_data.normalised_nf = RC_INVALID_NF;

   // mimic
   p_rc_input->avg_mmic_onchip_temp = RC_INVALID_MMIC_TEMPERATURE;
   p_rc_input->f_eco_mode_enabled   = false;

   // dyn align
   p_rc_input->p_dyn_align_data.vacs_boresight_el_nominal   = 0;
   p_rc_input->p_dyn_align_data.vacs_boresight_el_estimated = RC_INVALID_EL;

   // fault injection
   p_rc_input->fault_inject_cmd.failure_type   = RC_FAULT_INJECT_Invalid;
   p_rc_input->fault_inject_cmd.inject_control = RC_FAULT_INJECT_CONTROL_Invalid;
}

static void mapping_det(Detection_Stream_T *const p_ipc_det, RC_Detection_Input_T *const p_rc_det, const bool f_is_FLR_sensor)
{
   uint32_t i;
   uint32_t n = MIN(RC_AF_MAX_NUM_DET, (uint32_t)p_ipc_det->num_af_det);
   UNUSED_PARAM(f_is_FLR_sensor);

   p_rc_det->det_list_property.lookindex = p_ipc_det->det_list_property.lookindex;
   p_rc_det->det_list_property.look_type = p_ipc_det->det_list_property.look_type;

   p_rc_det->af_data[0].num_af_det = (int32_t)n;
   for (i = 0; i < n; i++)
   {
      p_rc_det->af_data[i].ran             = p_ipc_det->af_dets[i].ran;
      p_rc_det->af_data[i].vel             = p_ipc_det->af_dets[i].vel;
      p_rc_det->af_data[i].az_conf         = p_ipc_det->af_dets[i].az_conf;
      p_rc_det->af_data[i].el_conf         = p_ipc_det->af_dets[i].el_conf;
      p_rc_det->af_data[i].f_single_target = p_ipc_det->af_dets[i].f_single_target;
      p_rc_det->af_data[i].theta           = p_ipc_det->af_dets[i].theta;
      p_rc_det->af_data[i].phi             = p_ipc_det->af_dets[i].phi;
      p_rc_det->af_data[i].spec_res        = p_ipc_det->af_dets[i].spec_res;
      p_rc_det->af_data[i].snr             = p_ipc_det->af_dets[i].snr;
      p_rc_det->af_data[i].fft_pow         = p_ipc_det->af_dets[i].pow;
   }
   for (i = 0; i < RC_CH_CH_NUM_TX_ANTENNAS; i++)
   {
      p_rc_det->ch_ch_degradation_data.ch_ch_degradation_tx[i] = p_ipc_det->ch_ch_degradation_data.ch_ch_degradation_tx[i];
   }
   for (i = 0; i < RC_CH_CH_NUM_RX_ANTENNAS; i++)
   {
      p_rc_det->ch_ch_degradation_data.ch_ch_degradation_rx[i] = p_ipc_det->ch_ch_degradation_data.ch_ch_degradation_rx[i];
   }
   p_rc_det->ch_ch_degradation_data.ch_ch_degradation_conf = 1.0F;
}

static void mapping_rdd(Rdd_Stream_T *p_ipc_rdd, RC_Rdd_Input_T *p_rc_rdd)
{
   p_rc_rdd->look_data.scan_index            = p_ipc_rdd->look_data.scan_index;
   p_rc_rdd->look_data.look_id               = p_ipc_rdd->look_data.look_id;
   p_rc_rdd->look_data.vua                   = 24.0F;  // TODO :  p_ipc_rdd->look_data.vua * SCALE_P21_TO_FLOAT;
   p_rc_rdd->look_data.range_coverage        = 200.0F; // TODO : p_ipc_rdd->look_data.range_coverage * SCALE_P7_TO_FLOAT;
   p_rc_rdd->rdd_data.min_chirp_scaling      = p_ipc_rdd->rdd_data.min_chirp_scaling;
   p_rc_rdd->rdd_data.cfar_nf_est            = &p_ipc_rdd->rdd_data.cfar_nf_est[0][0];
   p_rc_rdd->rdd_data.rdd1_max_per_range_bin = &p_ipc_rdd->rdd_data.rdd1_max_per_range_bin[0][0];
   /* Passing size of cfar_nf_est to avoid dependency of structure size in Gen8 and Gen7 Platforms */
   p_rc_rdd->rdd_data.cfar_array_size = (sizeof(p_ipc_rdd->rdd_data.cfar_nf_est) / sizeof(p_ipc_rdd->rdd_data.cfar_nf_est[0][0]));
   p_rc_rdd->rdd_data.rdd1_num_detect = p_ipc_rdd->rdd_data.rdd1_num_detect;

   p_rc_rdd->rfft_data.interfered_samples_per_frame = 0; // p_ipc_rdd->rfft_data.interfered_samples_per_frame;
}

static void mapping_id(ID_Stream_T *ipc_id, RC_ID_Input_T *rc_id)
{
   rc_id->scan_index                = ipc_id->stream_hdr.scan_index;
   rc_id->normalised_nf             = ipc_id->normalised_nf;
   rc_id->interference_data_discard = ipc_id->interference_data_discard;
}

static void mapping_dyn(Dynamic_Alignment_Log_Stream_T *p_ipc_dyn, RC_Dynamic_Alignment_Log_Input_T *p_rc_dyn)
{
   p_rc_dyn->azimuth_estimation_qf             = p_ipc_dyn->dra_core_data.azimuth_estimation_qf;
   p_rc_dyn->error_status_az_est_out_of_bounds = p_ipc_dyn->dra_core_data.error_status_az_est_out_of_bounds;
   p_rc_dyn->vacs_boresight_az_nominal         = p_ipc_dyn->dra_core_data.vacs_boresight_az_nominal;
   p_rc_dyn->vacs_boresight_az_estimated       = p_ipc_dyn->dra_core_data.vacs_boresight_az_estimated;
   p_rc_dyn->vacs_boresight_roll_nominal       = p_ipc_dyn->dra_core_data.vacs_boresight_roll_nominal;
   p_rc_dyn->elevation_estimation_qf           = p_ipc_dyn->dra_core_data.elevation_estimation_qf;
   p_rc_dyn->error_status_el_est_out_of_bounds = p_ipc_dyn->dra_core_data.error_status_el_est_out_of_bounds;
   p_rc_dyn->vacs_boresight_el_nominal         = p_ipc_dyn->dra_core_data.vacs_boresight_el_nominal;
   p_rc_dyn->vacs_boresight_el_estimated       = p_ipc_dyn->dra_core_data.vacs_boresight_el_estimated;
   p_rc_dyn->mounting_location                 = p_ipc_dyn->dra_core_data.mounting_location;
}

static void mapping_veh(Vse_Stream_T *p_ipc_vse, RC_Vse_Input_T *p_rc_vse)
{
   p_rc_vse->scan_index = p_ipc_vse->stream_hdr.scan_index;
#ifndef BLOCKAGE_TEST
   p_rc_vse->veh_speed = p_ipc_vse->vse_output.signed_filt_veh_speed_over_ground;
#else
   p_rc_vse->veh_speed                   = Veh_speed_test_blk;
#endif
   p_rc_vse->veh_yaw = p_ipc_vse->vse_output.comp_yaw_rate_filtered;
}

static void rc_ptr_update(D2M_Msg_T *p_ipc_d2m, M2D_Msg_T *p_ipc_m2d, RC_Input_Data_T *rc_ipc_data_ptr,
                          M2D_One_Time_Msg_T *m2d_one_time_init_ptr)
{
   (void)m2d_one_time_init_ptr;
   rc_ipc_data_ptr->f_initialized = CODED_TRUE;
   if (NULL != p_ipc_m2d)
   {
      /*Veh Data*/
      rc_ipc_data_ptr->vse_data = &p_ipc_m2d->payload.veh_data;

      rc_ipc_data_ptr->ipc_avg_mmic_onchip_temp = p_ipc_m2d->payload.avg_mmic_onchip_temp;
   }
   else
   {
      rc_ipc_data_ptr->f_initialized            = CODED_FALSE;
      rc_ipc_data_ptr->vse_data                 = NULL;
      rc_ipc_data_ptr->ipc_avg_mmic_onchip_temp = RC_INVALID_MMIC_TEMPERATURE;
#ifdef RC_RESIM_FORCE_INFO_FROM_LOG
      rc_ipc_data_ptr->rc_output = NULL;
#endif
   }
   if (NULL != p_ipc_d2m)
   {
      /* Detection Data*/
      rc_ipc_data_ptr->af_ipc_data   = &p_ipc_d2m->payload.det_data;
      rc_ipc_data_ptr->af_debug_data = &p_ipc_d2m->payload.det_debug_data;

      rc_ipc_data_ptr->p_middle_of_dwell_ts_ipc.ts_nanosecs = p_ipc_d2m->payload.rdd_stream_data.look_data.mid_dwell_nanosec;
      rc_ipc_data_ptr->p_middle_of_dwell_ts_ipc.ts_secs     = p_ipc_d2m->payload.rdd_stream_data.look_data.mid_dwell_sec;
      rc_ipc_data_ptr->p_middle_of_dwell_ts_ipc.ts_status   = p_ipc_d2m->payload.rdd_stream_data.look_data.mid_dwell_status;

      /*RDD Data*/
      rc_ipc_data_ptr->rdd_ipc_data = &p_ipc_d2m->payload.rdd_stream_data;

      rc_ipc_data_ptr->rc_output = &p_ipc_d2m->payload.radar_capability_data;

      /*ID Data*/
      rc_ipc_data_ptr->id_data = &p_ipc_d2m->payload.interference_detection_data;
   }
   else
   {
      rc_ipc_data_ptr->af_ipc_data   = NULL;
      rc_ipc_data_ptr->af_debug_data = NULL;
      rc_ipc_data_ptr->rdd_ipc_data  = NULL;
      rc_ipc_data_ptr->rc_output     = NULL;
      rc_ipc_data_ptr->id_data       = NULL;
      rc_ipc_data_ptr->f_initialized = CODED_FALSE;
   }

   /*DA Data*/
   rc_ipc_data_ptr->dyn_data = Get_Prev_Dyn_Align_Output();
}

static void rc_wrapper_map_input_data(RC_Input_Data_T *rc_ipc_data_ptr, RC_Input_T *const p_rc_input)
{
   const RC_Platform_Variant platform_variant = (RC_Platform_Variant)p_rc_input->rc_cals.smc_platform;
   const bool f_is_FLR_sensor                 = rc_is_flr_sensor(platform_variant);

   mapping_det(rc_ipc_data_ptr->af_ipc_data, &p_rc_input->p_det_data, f_is_FLR_sensor);
   mapping_rdd(rc_ipc_data_ptr->rdd_ipc_data, &p_rc_input->p_rdd_stream_data);
   mapping_id(rc_ipc_data_ptr->id_data, &p_rc_input->p_id_data);
   mapping_dyn(rc_ipc_data_ptr->dyn_data, &p_rc_input->p_dyn_align_data);
   /* TO DO : Map the values once mid dwell integrated to IPC*/
   p_rc_input->p_middle_of_dwell_ts.ts_nanosecs = rc_ipc_data_ptr->p_middle_of_dwell_ts_ipc.ts_nanosecs;
   p_rc_input->p_middle_of_dwell_ts.ts_secs     = rc_ipc_data_ptr->p_middle_of_dwell_ts_ipc.ts_secs;
   p_rc_input->p_middle_of_dwell_ts.ts_status   = rc_ipc_data_ptr->p_middle_of_dwell_ts_ipc.ts_status;
#ifdef RC_RESIM_FORCE_INFO_FROM_LOG
   p_rc_input->p_rc_data = rc_ipc_data_ptr->rc_output;
#endif

   mapping_veh(rc_ipc_data_ptr->vse_data, &p_rc_input->p_veh_data);

   p_rc_input->avg_mmic_onchip_temp = rc_ipc_data_ptr->ipc_avg_mmic_onchip_temp;
   p_rc_input->f_eco_mode_enabled   = false; /* Eco mode is not available in Gen8 . Hence disabled*/
}

static void Mapping_ipc_to_rc_input(RC_Input_Data_T *rc_ipc_data_ptr, RC_Input_T *p_rc_input)
{
   // Map calibration input
   SMC_Cal_T *p_smc_cal = Get_SMC_Cal_Data();
   USC_Cal_T *p_usc_cal = Get_USC_Cal_Data();
   RC_Cal_T *p_rc_cals  = &p_rc_input->rc_cals;

   p_rc_cals->smc_platform = p_smc_cal->Header2_Info.platform;
   p_rc_cals->usc_platform = p_usc_cal->Header2_Info.platform;

   p_rc_cals->k_rc_sensitivity_level_str = k_rc_sensitivity_level_smc;
#ifdef BLOCKAGE_TEST
   p_rc_cals->k_rc_ignore_fsc_status_str = 1;
#else
   #ifdef k_rc_ignore_fsc_status_smc
   p_rc_cals->k_rc_ignore_fsc_status_str = k_rc_ignore_fsc_status_smc;
   #else
   p_rc_cals->k_rc_ignore_fsc_status_str = 0;
   #endif
#endif
   p_rc_cals->k_rc_damping_adjustment_str = k_rc_damping_adjustment_smc * SCALE_P2_TO_FLOAT;

   p_rc_cals->k_rc_ran_loss_straddling_str = k_rc_ran_loss_straddling_smc;
   p_rc_cals->k_rc_ran_loss_fascia_str     = k_rc_ran_loss_fascia_smc;
   p_rc_cals->k_rc_ran_snr_drop_hot_str    = k_rc_ran_snr_drop_hot_smc;
   p_rc_cals->k_rc_ran_temp_hot_str        = k_rc_ran_temp_hot_smc;
   p_rc_cals->k_rc_ran_temp_norm_str       = k_rc_ran_temp_norm_smc;
   p_rc_cals->k_rc_ran_snr_min_str         = k_rc_ran_snr_min_smc;
   p_rc_cals->k_rc_ran_nci_gain_str        = k_rc_ran_nci_gain_smc;
   p_rc_cals->k_rc_ran_target_car_rcs_str  = k_rc_ran_target_car_rcs_smc;
   p_rc_cals->k_rc_ran_target_ped_rcs_str  = k_rc_ran_target_ped_rcs_smc;
   p_rc_cals->k_rc_ran_target_mot_rcs_str  = k_rc_ran_target_mot_rcs_smc;

   p_rc_cals->k_Gain_Rolloff_Az_Reciprocal_str = k_Gain_Rolloff_Az_Reciprocal_USC;
   p_rc_cals->k_Gain_Rolloff_EL_Reciprocal_str = k_Gain_Rolloff_EL_Reciprocal_USC;
   p_rc_cals->k_Mfg_Cal_Target_Range_str       = k_Mfg_Cal_Target_Range_USC * SCALE_P10_TO_FLOAT;
   p_rc_cals->k_Mfg_Cal_Target_RCS_str         = k_Mfg_Cal_Target_RCS_USC * SCALE_P10_TO_FLOAT;
   p_rc_cals->k_Boresight_SNR_str              = k_Boresight_SNR_USC * SCALE_P9_TO_FLOAT;
   p_rc_cals->k_Peak_SNR_str                   = k_Peak_SNR_USC * SCALE_P9_TO_FLOAT;
   p_rc_cals->k_Peak_SNR_Az_str                = k_Peak_SNR_Az_USC * SCALE_P9_TO_FLOAT;
   p_rc_cals->k_Peak_SNR_El_str                = k_Peak_SNR_El_USC * SCALE_P9_TO_FLOAT;

   // Map input
   rc_wrapper_map_input_data(rc_ipc_data_ptr, p_rc_input);
}

void rc_wrapper(D2M_Msg_T *p_d2m, M2D_Msg_T *p_m2d, M2D_One_Time_Msg_T *m2d_one_time_init_ptr)
{
   RC_Input_Data_T rc_ipc_data         = {0};
   Radar_Capability_Stream_T *p_rc_out = NULL;

   (void)m2d_one_time_init_ptr;

   rc_ptr_update(p_d2m, p_m2d, &rc_ipc_data, m2d_one_time_init_ptr);

   // Init input struct
   rc_input_init(rc_input);

   // Mapping from ipc to rc input
   Mapping_ipc_to_rc_input(&rc_ipc_data, rc_input);

   /* Provides rc_input parameter details to verify Integration Testing.
    * This section executes only when the Integration_Testing macro is enabled.
    */
   SIT_DYNAMIC_ALIGN_DATA(rc_input);

   /* Provides avg MMIC on-chip temperature data to verify Integration Testing.
    * This section executes only when the Integration_Testing macro is enabled.
    */
   SIT_AVG_MMIC_ONCHIP_TEMP_DATA(rc_input);

   // Mapping from ipc to rc output
   p_rc_out = rc_ipc_data.rc_output;

   // rc main function
   if (NULL != p_rc_out)
   {
#ifdef RC_FAULT_INJECION_ENABLED
      // Check if we should inject a fault
      static uint8_t prev_fault_num = 0U;
      uint8_t cur_fault_num         = 0U; // TODO: Read this value from IPC when implemented
      if (prev_fault_num != cur_fault_num)
      {
         rc_fiw_set_fault_num(cur_fault_num);
         prev_fault_num = cur_fault_num;
      }

      // Inject input fault
      rc_fiw_inject_input_fault(rc_input);
#endif

      // Run RC Main
      rc_main(rc_input, p_rc_out, &rc_memory[rc_memory_index]);

#ifdef RC_FAULT_INJECION_ENABLED
      // Revert injected input fault
      rc_fiw_fill_output_data(&p_rc_out->fault_injection);
      rc_fiw_revert_input_fault();
#endif
   }
}
