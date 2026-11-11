/*===========================================================================*/
/**
 * @file dyn_align_wrapper.c
 *
 * Application interface mapping for Dynamic Alignment Module
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2024 Aptiv. All rights reserved.
 * Aptiv Sensitive Business ? Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Application interface mapping for Dynamic Alignment Module
 *
 * @section ABBR ABBREVIATIONS:
 *   - List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     -  Update list of design document(s).
 *   -
 *   - Requirements Document(s):
 *     -  Update list of requirements document(s)
 *   -
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     -  Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   -  List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include "dyn_align_wrapper.h"
#include <string.h>
/*===========================================================================*
 * Header Files
 *===========================================================================*/

#include "dra_initialization.h"
#include "dra_step_execution.h"
#include "ipc_data.h"
#if defined(APRISM_DA_FASTLOCK_ENABLE) && (APRISM_DA_FASTLOCK_ENABLE == 1)
#include "ghost_calib.h"
#endif
#if defined(APRISM_GHOST_INSPECT_ENABLE) && (APRISM_GHOST_INSPECT_ENABLE == 1)
#include <math.h>
#include "ghost_calib.h"
#endif
#ifndef UNIT_TEST
   #ifdef PSP_SIL_ENABLE
      #include <math.h>
   #else
      #include "radar_math.h"
   #endif
#endif
#ifdef ALIGN_STUB_SIMULATE_DET
   #include "dra_simulate_detections.h"
#endif

/*===========================================================================*
 * SWE5 Integration Testing Support
 *===========================================================================*/
#include "dsp_it_macros_test.h"

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/* ========================================================================== */
/*                           External variables                               */
/* ========================================================================== */
/* ========================================================================== */
/*                            Structures                                      */
/* ========================================================================== */
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/* ========================================================================== */
/*                            Static Variables                                */
/* ========================================================================== */

static DA_Internal_Mem_Info_T DA_Internal_Mem_Info[DA_MP_MAX_NUM_MEMORY_LOC];

static DYN_ALIGN_INPUT_T da_input_data = {0};
static DRA_Internal_Variables_T __attribute__((section(".sram0.bss"))) align_internal_vars;
static Dynamic_Alignment_Log_Stream_T __attribute__((section(".sram0.bss"))) alignment_log;
static DRA_Radar_Parameters_T __attribute__((section(".sram0.bss"))) radar_params;
static DRA_Calibrations_T __attribute__((section(".sram0.bss"))) cals_align;
static uint8_t __attribute__((section(".sram0.bss"))) Dyn_Alignment_Init_Status = 0U;
static DRA_Algo_Mode_T __attribute__((section(".sram0.bss"))) Alignment_Status_Prev;
#ifdef ALIGN_STUB_SIMULATE_DET
volatile static uint8_t __attribute__((section(".sram0.text"))) Alignment_Neg_Test_Enable = CODED_FALSE;
volatile static uint16_t __attribute__((section(".sram0.text"))) Alignment_Num_Detections = 256U;
volatile static float Neg_Test_Veh_Speed                                                  = 12.0F;
volatile static uint8_t test_align_scan_index                                             = 0;
volatile static DRA_Blockage_Status_T Alignment_Blockage_Status                           = DRA_BLOCKAGE_STATUS_OK;
volatile static DRA_Blockage_Value_T Alignent_Blockage_Value                              = DRA_BLOCKAGE_VALUE_NOT_BLOCKED;
volatile static float Alignment_Yaw_Rate                                                  = 0.0F;
#endif
static DRA_Initial_Input_T __attribute__((section(".sram0.bss"))) initial_inputs;

/* A-PRISM DA fast-lock state (Run 17). All updates guarded by
 * APRISM_DA_FASTLOCK_ENABLE; default OFF = baseline bit-identical. */
static int32_t aprism_da_scan_count = 0;
static int32_t aprism_da_hold_count = 0;
static uint8_t aprism_da_locked     = 0U;
static float aprism_da_gain         = 0.0F;
static float aprism_da_prev_kf_az   = 0.0F;
static float aprism_da_prev_kf_el   = 0.0F;
#if defined(APRISM_GHOST_INSPECT_ENABLE) && (APRISM_GHOST_INSPECT_ENABLE == 1)
static uint16_t aprism_ghost_inspected = 0U;
static uint16_t aprism_ghost_refused   = 0U;
#endif

/* A-PRISM DA fast-lock tunables (Run-17 validated defaults). Override per
 * experiment build via -D (see CHANGES.md §11). Baseline stays clean: these
 * are defines only, consumed inside APRISM-guarded blocks. */
#ifndef APRISM_DA_K_FAST
#define APRISM_DA_K_FAST (0.05F)
#endif
#ifndef APRISM_DA_K_SLOW
#define APRISM_DA_K_SLOW (0.0025F)
#endif
#ifndef APRISM_DA_ALPHA
#define APRISM_DA_ALPHA (0.1F)
#endif
#ifndef APRISM_DA_LOCK_TOL_DEG
#define APRISM_DA_LOCK_TOL_DEG (0.05F)
#endif
#ifndef APRISM_DA_LOCK_NEED
#define APRISM_DA_LOCK_NEED (10)
#endif
#ifndef APRISM_DA_MAX_UPDATES
#define APRISM_DA_MAX_UPDATES (50U)
#endif

#ifdef ALIGN_STUB_SIMULATE_DET
volatile static uint8_t __attribute__((section(".sram0.text"))) Align_Data_Qualifier_Test = 5; /* DATA_QUALIFIER_NORMAL */
volatile static float32_t __attribute__((section(".sram0.text"))) Misalign_Yaw            = (2.0F * DRA_DEG2RAD);
volatile static float32_t __attribute__((section(".sram0.text"))) Misalign_Pitch          = (2.0F * DRA_DEG2RAD);
#endif

#ifdef PSP_SIL_ENABLE
static DRA_Detection_Input_T detection_input;
static DRA_Detection_Props_T detections_prop[DRA_NUMBER_OF_DETECTIONS];
static DRA_Detection_Input_T *p_detection_input = &detection_input;
static DRA_Detection_Props_T *p_detections_prop = &detections_prop[0];
#else
static DRA_Detection_Input_T *p_detection_input;
static DRA_Detection_Props_T *p_detections_prop;
#endif

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
static void Auto_align_Init(DYN_ALIGN_INPUT_T *da_input_data);
static void Execute_Dynamic_Alignment(DYN_ALIGN_INPUT_T *da_input_data);
static void __attribute__((noinline)) convert_detections(DYN_ALIGN_INPUT_T *da_input_data);
static void Populate_Dyn_Align_Output(Dynamic_Alignment_Log_Stream_T *da_log_int, DYN_ALIGN_INPUT_T *da_input_data);
static void da_ptr_update(D2M_Msg_T *p_d2m, M2D_Msg_T *p_m2d, M2D_One_Time_Msg_T *m2d_one_time_init_ptr,
                          DYN_ALIGN_INPUT_T *p_da_input_data);
#ifdef ALIGN_STUB_SIMULATE_DET
static void DRA_stub_test(DRA_Detection_Input_T *p_detection_input_ptr, DRA_Initial_Input_T *initial_inputs_ptr,
                          DRA_Vehicle_Data_T *vehicle_parameters_ptr, DRA_Radar_Parameters_T *radar_parameters_ptr,
                          DRA_Algo_Mode_T align_cmd, DYN_ALIGN_INPUT_T *p_da_input_data);
#endif

/*****************************************************************************
 *. Name: Get_DA_Internal_memory_pointers
 *. This function will get the memory pointer to all dynamic alignment structures
 *.
 *. Parameters:
 *. void
 *.
 *. Return Value: DA_Internal_Mem_Info_T
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
DA_Internal_Mem_Info_T *Get_DA_Internal_memory_pointers(void)
{
   /* Clear memory details before assign*/
   (void)memset(DA_Internal_Mem_Info, 0U, sizeof(DA_Internal_Mem_Info));

   /*Assign required memory*/
   DA_Internal_Mem_Info[0].size     = sizeof(*p_detection_input);
   DA_Internal_Mem_Info[0].addr_ptr = (void **)&p_detection_input;
   DA_Internal_Mem_Info[1].size     = sizeof(*p_detections_prop) * DRA_NUMBER_OF_DETECTIONS;
   DA_Internal_Mem_Info[1].addr_ptr = (void **)&p_detections_prop;
   return &DA_Internal_Mem_Info[0];
}
/*****************************************************************************
 *. Name: Alignment_Handler_Memory_Init
 *. This function will allocate memory from mempool for all dynamic alignment structures
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
Memory_Pool_Return_T Alignment_Handler_Memory_Init(Mem_Pool_T *mem_pool)
{
   Memory_Pool_Return_T retVal = MEM_POOL_SUCCESS;
   uint8_t mem_loc             = 0U;

   DA_Internal_Mem_Info_T *DA_Internal_memory_ptr = Get_DA_Internal_memory_pointers();

   do
   {
      if ((NULL != DA_Internal_memory_ptr[mem_loc].addr_ptr) && (0U != DA_Internal_memory_ptr[mem_loc].size))
      {
         retVal = Mem_Pool_Alloc(mem_pool, DA_Internal_memory_ptr[mem_loc].size, DA_Internal_memory_ptr[mem_loc].addr_ptr);
      }
      mem_loc++;
   } while ((MEM_POOL_SUCCESS == retVal) && (mem_loc < (uint8_t)DA_MP_MAX_NUM_MEMORY_LOC));

   return retVal;
}

/*****************************************************************************
 *. Name: da_ptr_update
 *. This function will initialise the input and output pointers required for DA Execution.
 *.
 *. Parameters:D2M_Msg_T *p_d2m, A2M_Msg_T *p_a2m, DYN_ALIGN_INPUT_T *p_da_input_data
 *.
 *.
 *. Return Value: None
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
static void da_ptr_update(D2M_Msg_T *p_d2m, M2D_Msg_T *p_m2d, M2D_One_Time_Msg_T *m2d_one_time_init_ptr,
                          DYN_ALIGN_INPUT_T *p_da_input_data)
{
   p_da_input_data->p_m2d_alignment_config  = &p_m2d->payload.alignment_Info.dynamic_alignment_data;
   p_da_input_data->p_da_one_time_init_data = m2d_one_time_init_ptr;
   p_da_input_data->p_hil_info_in           = &p_m2d->payload.hil_ipc_info;
   p_da_input_data->p_det_stream            = &p_d2m->payload.det_data;
   p_da_input_data->p_rdd_stream            = &p_d2m->payload.rdd_stream_data;
   p_da_input_data->p_vse_stream            = &p_m2d->payload.veh_data;
   p_da_input_data->p_rc_stream             = &p_d2m->payload.radar_capability_data;
   p_da_input_data->p_da_log_stream         = &p_d2m->payload.dynamic_alignment_log_stream;
#if (DOWNSELECTION_ENABLE == 1U)
   p_da_input_data->p_toi_ds_stream = &p_d2m->payload.toi_ds_stream_data;
#else
   p_da_input_data->p_toi_stream                 = &p_d2m->payload.toi_stream_data;
#endif
}
/*****************************************************************************
 *. Name: Get_Prev_Dyn_Align_Output
 *. This function will get the pointer to dynamic alignment algo output
 *.
 *. Parameters:
 *. void
 *.
 *. Return Value: Dynamic_Alignment_Log_Stream_T*
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
Dynamic_Alignment_Log_Stream_T *Get_Prev_Dyn_Align_Output(void)
{
   return &alignment_log;
}

#ifdef ALIGN_STUB_SIMULATE_DET
/**
 *  @b Description : Funtion to inject Stub detections and Required Configs for Alignment
 *  @n
 *      DRA_stub_test
 *
 *  @retval void
 */
static void DRA_stub_test(DRA_Detection_Input_T *p_detection_input_ptr, DRA_Initial_Input_T *p_initial_inputs,
                          DRA_Vehicle_Data_T *p_vehicle_parameters, DRA_Radar_Parameters_T *p_radar_parameters,
                          DRA_Algo_Mode_T align_cmd, DYN_ALIGN_INPUT_T *p_da_input_data)
{
   (void)p_da_input_data; /* Silences the unused parameter warning */
   if (align_cmd != DRA_ALGO_MODE_OFF)
   {
      DRA_Simulate_Detections(p_detection_input_ptr, p_initial_inputs, p_vehicle_parameters, p_radar_parameters, align_cmd,
                              Misalign_Yaw, Misalign_Pitch);
   }
   else
   {
      /***** Do nothing *****/
   }
   /*Test code to Overwrite Stubbed values for Negative Test case testing */
   if (CODED_TRUE == Alignment_Neg_Test_Enable)
   {
      p_detection_input_ptr->number_of_detections = Alignment_Num_Detections;
      p_detection_input_ptr->blockage_status      = (DRA_Blockage_Status_T)Alignment_Blockage_Status;
      p_detection_input_ptr->blockage_value       = (DRA_Blockage_Value_T)Alignent_Blockage_Value;
      p_vehicle_parameters->speed                 = Neg_Test_Veh_Speed;
      p_vehicle_parameters->yawrate               = Alignment_Yaw_Rate;
   }
}
#endif
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
/**
 *  @b Description
 *  @n
 *
 *
 */
static void Auto_align_Init(DYN_ALIGN_INPUT_T *p_da_input_data)
{
   Dynamic_Alignment_Data_T *dra_data          = p_da_input_data->p_m2d_alignment_config;
   Sensor_Calib_Data_T *da_sensor_calib_data   = &p_da_input_data->p_da_one_time_init_data->calib_data.sensor_calib_data;
   Vehicle_Calib_Data_T *da_vehicle_calib_data = &p_da_input_data->p_da_one_time_init_data->calib_data.vehicle_calib_data;
   uint8_t sensor_posn                         = p_da_input_data->p_da_one_time_init_data->radar_position;

   if (sensor_posn == (uint8_t)RADAR_POSITION_FRONT_CENTER)
   {
      radar_params.radar_type = (DRA_Radar_Type_T)DRA_RADAR_TYPE_FLR8;
   }
   else
   {
      radar_params.radar_type = (DRA_Radar_Type_T)DRA_RADAR_TYPE_SRR8P;
   }

   radar_params.vacs_boresight_az_nominal =
      da_sensor_calib_data->sensor_mount_data.k_sensor_mount_ornt_yaw * -1.0F; /*Angle conversion to SAE*/
   radar_params.vacs_boresight_el_nominal =
      da_sensor_calib_data->sensor_mount_data.k_sensor_mount_ornt_pitch * -1.0F; /*Angle conversion to SAE*/
   radar_params.vacs_boresight_roll_nominal = da_sensor_calib_data->sensor_mount_data.k_sensor_mount_ornt_roll;

   radar_params.vcs_sensor_lat_posn = da_sensor_calib_data->sensor_mount_data.k_sensor_mount_pos_y * -1.0F;
   radar_params.vcs_sensor_long_posn =
      da_sensor_calib_data->sensor_mount_data.k_sensor_mount_pos_x - da_vehicle_calib_data->k_distance_front_bumper_to_rear_axle;
   radar_params.sensor_height_over_ground = da_sensor_calib_data->sensor_mount_data.k_sensor_mount_pos_z;

   initial_inputs.vacs_boresight_az_estimated = dra_data->initial_vacs_boresight_az_estimated;
   initial_inputs.vacs_boresight_el_estimated = dra_data->initial_vacs_boresight_el_estimated;
   initial_inputs.vacs_boresight_rl_estimated = dra_data->initial_vacs_boresight_rl_estimated;

   initial_inputs.speed_compensation_factor = dra_data->initial_speed_compensation_factor;

   initial_inputs.max_abs_misalignment_az = dra_data->max_abs_misalignment_az;

#ifdef PSP_SIL_ENABLE
   initial_inputs.max_abs_misalignment_el_sky    = fabsf(dra_data->max_abs_misalignment_el_sky);
   initial_inputs.max_abs_misalignment_el_ground = fabsf(dra_data->max_abs_misalignment_el_ground);
#else
   initial_inputs.max_abs_misalignment_el_sky    = rm_fabsf(dra_data->max_abs_misalignment_el_sky);
   initial_inputs.max_abs_misalignment_el_ground = rm_fabsf(dra_data->max_abs_misalignment_el_ground);
#endif
   initial_inputs.align_cmd = (DRA_Algo_Mode_T)dra_data->align_cmd;

   initial_inputs.num_updates_az = dra_data->initial_num_updates_az;
   initial_inputs.num_updates_el = dra_data->initial_num_updates_el;
   initial_inputs.num_updates_rl = dra_data->initial_num_updates_rl;

   radar_params.mount_loc = (DRA_Mounting_Location_T)dra_data->mount_loc;

   initial_inputs.short_track_exit_condition = (DRA_Short_Track_Exit_Condition_T)dra_data->short_track_exit_condition;

   initial_inputs.short_track_target_height     = dra_data->short_track_target_height;
   initial_inputs.short_track_target_range_rate = dra_data->short_track_target_range_rate;
   initial_inputs.az_scf_kf_covariance[0]       = dra_data->az_scf_kf_covariance[0];
   initial_inputs.az_scf_kf_covariance[1]       = dra_data->az_scf_kf_covariance[1];
   initial_inputs.az_scf_kf_covariance[2]       = dra_data->az_scf_kf_covariance[2];
   initial_inputs.az_scf_kf_covariance[3]       = dra_data->az_scf_kf_covariance[3];
   initial_inputs.el_roll_kf_covariance[0]      = dra_data->el_roll_kf_covariance[0];
   initial_inputs.el_roll_kf_covariance[1]      = dra_data->el_roll_kf_covariance[1];
   initial_inputs.el_roll_kf_covariance[2]      = dra_data->el_roll_kf_covariance[2];
   initial_inputs.el_roll_kf_covariance[3]      = dra_data->el_roll_kf_covariance[3];

#if defined(APRISM_DA_FASTLOCK_ENABLE) && (APRISM_DA_FASTLOCK_ENABLE == 1)
   /* A-PRISM fast-lock preflight (Run 17): cap the conservative startup
    * deadband so lock can complete in ~46 frames instead of ~400. Only
    * lowers over-conservative counts; never raises an already-fast config.
    * Compare-safe: OFF = original M2D values verbatim. */
   if (initial_inputs.num_updates_az > APRISM_DA_MAX_UPDATES)
   {
      initial_inputs.num_updates_az = APRISM_DA_MAX_UPDATES;
   }
   if (initial_inputs.num_updates_el > APRISM_DA_MAX_UPDATES)
   {
      initial_inputs.num_updates_el = APRISM_DA_MAX_UPDATES;
   }
   if (initial_inputs.num_updates_rl > APRISM_DA_MAX_UPDATES)
   {
      initial_inputs.num_updates_rl = APRISM_DA_MAX_UPDATES;
   }
   aprism_da_scan_count = 0;
   aprism_da_hold_count = 0;
   aprism_da_locked     = 0U;
   aprism_da_gain       = 0.0F;
#endif

   DRA_Initialization(&align_internal_vars, &cals_align, &initial_inputs, &radar_params);

#ifdef PSP_SIL_ENABLE
   /* Initialized to match SIL and embedded starting point */
   align_internal_vars.vacs_boresight_kf_az = p_da_input_data->vacs_boresight_kf_az;
   align_internal_vars.vacs_boresight_kf_el = p_da_input_data->vacs_boresight_kf_el;

   align_internal_vars.az_scf_covariance[0][0]  = dra_data->az_scf_kf_covariance[0];
   align_internal_vars.az_scf_covariance[0][1]  = dra_data->az_scf_kf_covariance[1];
   align_internal_vars.az_scf_covariance[1][0]  = dra_data->az_scf_kf_covariance[2];
   align_internal_vars.az_scf_covariance[1][1]  = dra_data->az_scf_kf_covariance[3];
   align_internal_vars.el_roll_covariance[0][0] = dra_data->el_roll_kf_covariance[0];
   align_internal_vars.el_roll_covariance[0][1] = dra_data->el_roll_kf_covariance[1];
   align_internal_vars.el_roll_covariance[1][0] = dra_data->el_roll_kf_covariance[2];
   align_internal_vars.el_roll_covariance[1][1] = dra_data->el_roll_kf_covariance[3];
#endif

   memset(&alignment_log, 0, sizeof(Dynamic_Alignment_Log_Stream_T));
}

/**
 *  @b Description
 *  @n
 *      Dynamic Alignemt Data Logging.
 *
 */
static void Populate_Dyn_Align_Output(Dynamic_Alignment_Log_Stream_T *da_log_int, DYN_ALIGN_INPUT_T *p_da_input_data)
{
   Dynamic_Alignment_Log_Stream_T *da_str_op = p_da_input_data->p_da_log_stream;

   memcpy(da_str_op, da_log_int, sizeof(Dynamic_Alignment_Log_Stream_T));

   /*Overwrite DRA Stream QF values during INIT*/
   /*During DRA_QF_INIT, Pass QF from NVM*/
   if ((da_str_op->dra_core_data.azimuth_estimation_qf == DRA_QF_INIT) &&
       (p_da_input_data->p_m2d_alignment_config->azimuth_estimation_qf != DRA_QF_INIT))
   {
      da_str_op->dra_core_data.azimuth_estimation_qf = (uint8_t)p_da_input_data->p_m2d_alignment_config->azimuth_estimation_qf;
   }
   if ((da_str_op->dra_core_data.elevation_estimation_qf == DRA_QF_INIT) &&
       (p_da_input_data->p_m2d_alignment_config->elevation_estimation_qf != DRA_QF_INIT))
   {
      da_str_op->dra_core_data.elevation_estimation_qf = (uint8_t)p_da_input_data->p_m2d_alignment_config->elevation_estimation_qf;
   }
   if ((da_str_op->dra_core_data.scf_estimation_qf == DRA_QF_INIT) &&
       (p_da_input_data->p_m2d_alignment_config->scf_estimation_qf != DRA_QF_INIT))
   {
      da_str_op->dra_core_data.scf_estimation_qf = (uint8_t)p_da_input_data->p_m2d_alignment_config->scf_estimation_qf;
   }
}

/**
 *  @b Description
 *  @n
 *
 *
 */
static void convert_detections(DYN_ALIGN_INPUT_T *p_da_input_data)
{
   uint16_t i                    = 0;
   Look_Data_T *p_look_data      = &p_da_input_data->p_rdd_stream->look_data;
   AF_Str_Detection_T *p_af_dets = &p_da_input_data->p_det_stream->af_dets[0];

#if defined(APRISM_GHOST_INSPECT_ENABLE) && (APRISM_GHOST_INSPECT_ENABLE == 1)
   aprism_ghost_inspected = 0U;
   aprism_ghost_refused   = 0U;
#endif

#ifdef FLR8
   if (FLR8_Flag_ISO_compliant_angle_format_smc == 1U)
#else
   if (SRR8p_Flag_ISO_compliant_angle_format_smc == 1U)
#endif
   {
      p_detection_input->detection_coordinate_system = DRA_DET_COORD_SYS_ISO;
   }
   else
   {
      p_detection_input->detection_coordinate_system = DRA_DET_COORD_SYS_SAE;
   }
   /*vwrapping descalled in One time buffer so could be directly read*/
   p_detection_input->doppler_interval =
      (float)(p_da_input_data->p_da_one_time_init_data->calib_data.sensor_calib_data.k_vwrapping[p_look_data->look_id]);
   p_detection_input->look_index = p_da_input_data->p_det_stream->det_list_property.lookindex;
   p_detection_input->number_of_detections =
      (uint16_t)MIN(((uint16_t)p_da_input_data->p_det_stream->num_af_det), DRA_NUMBER_OF_DETECTIONS);
   p_detection_input->blockage_value  = (DRA_Blockage_Value_T)p_da_input_data->p_rc_stream->blockage.blockage.value;
   p_detection_input->blockage_status = (DRA_Blockage_Status_T)p_da_input_data->p_rc_stream->blockage.blockage_status;

#ifndef ALIGN_STUB_SIMULATE_DET
   #if (DOWNSELECTION_ENABLE)
   /*offset -1 is added below since Enum used to define Operation mode in DRA is differnet from what is been used in toi */
   p_detection_input->data_qualifier = (DRA_Data_Qualifier_T)(p_da_input_data->p_toi_ds_stream->toi_op_data.data_qualifier - 1U);
   #else
   p_detection_input->data_qualifier = (DRA_Data_Qualifier_T)(p_da_input_data->p_toi_stream->toi_op_data.data_qualifier - 1U);
   #endif
#else
   #if (DOWNSELECTION_ENABLE)
   /*offset -1 is added below since Enum used to define Operation mode in DRA is differnet from what is been used in toi */
   p_da_input_data->p_toi_ds_stream->toi_op_data.data_qualifier = Align_Data_Qualifier_Test;
   p_detection_input->data_qualifier  = (DRA_Data_Qualifier_T)(p_da_input_data->p_toi_ds_stream->toi_op_data.data_qualifier - 1U);
   #else
   p_da_input_data->p_toi_stream->toi_op_data.data_qualifier = Align_Data_Qualifier_Test;
   p_detection_input->data_qualifier = (DRA_Data_Qualifier_T)(p_da_input_data->p_toi_stream->toi_op_data.data_qualifier - 1U);
   #endif
#endif

   for (i = 0; i < p_detection_input->number_of_detections; i++)
   {
      p_detection_input->detections[i].azimuth_raw        = p_af_dets[i].theta;
      p_detection_input->detections[i].elevation_raw      = p_af_dets[i].phi;
      p_detection_input->detections[i].range              = p_af_dets[i].ran;
      p_detection_input->detections[i].range_rate_raw     = p_af_dets[i].vel;
      p_detection_input->detections[i].amplitude          = p_af_dets[i].rcs;
      p_detection_input->detections[i].azimuth_confidence = (uint8_t)p_af_dets[i].az_conf;
      p_detection_input->detections[i].f_valid_level      = (bool)1;
      p_detection_input->detections[i].f_super_res_target = (bool)p_af_dets[i].f_superres_target;
      p_detection_input->detections[i].snr                = p_af_dets[i].snr;
      /* f_ci_det not implemented yet in af_data, hence hardcoding*/
      p_detection_input->detections[i].f_ci_detection       = false; //(bool)p_af_dets[i].f_ci_det;
      p_detection_input->detections[i].elevation_confidence = (uint8_t)p_af_dets[i].el_conf;
      p_detection_input->detections[i].f_bistatic           = (bool)p_af_dets[i].f_bistatic;
#if defined(APRISM_GHOST_INSPECT_ENABLE) && (APRISM_GHOST_INSPECT_ENABLE == 1)
      /* A-PRISM ghost-contact inspection (N26): real signature, real fields.
       * Sensor-local frame (sensor at origin); detection Cartesian from
       * (ran, theta, phi) with az about boresight, el above the az plane.
       * ponytail: confirm the SAE/ISO angle convention with the AF owner and
       * validate ell = 2*ran (return leg ~= direct distance) against labeled
       * multipath with the OT/DABB owner. Refusal-only effect: a bistatic
       * detection whose geometry is inconsistent is dropped from the DABB
       * input and counted; every other detection passes through untouched. */
      if (p_detection_input->detections[i].f_bistatic)
      {
         float gs[2]  = {0.0F, 0.0F};
         float gp[2];
         float gu[2];
         float grad   = p_af_dets[i].ran;
         float gcosel = cosf(p_af_dets[i].phi);
         float gdlen;
         gp[0] = grad * gcosel * cosf(p_af_dets[i].theta);
         gp[1] = grad * gcosel * sinf(p_af_dets[i].theta);
         gdlen = sqrtf(gp[0] * gp[0] + gp[1] * gp[1]);
         aprism_ghost_inspected++;
         if (gdlen < 1e-6F)
         {
            p_detection_input->detections[i].f_valid_level = false;
            aprism_ghost_refused++;
         }
         else
         {
            GhostContact_T gct;
            gu[0] = gp[0] / gdlen;
            gu[1] = gp[1] / gdlen;
            gct   = GhostInverseContact(gs, gp, gu, 2.0F * grad);
            if (!gct.valid)
            {
               p_detection_input->detections[i].f_valid_level = false;
               aprism_ghost_refused++;
            }
         }
      }
#endif
   }
}

/**
 *  @b Description
 *  @n
 *
 *
 */
static void Execute_Dynamic_Alignment(DYN_ALIGN_INPUT_T *p_da_input_data)
{
   DRA_Vehicle_Data_T vehicle_input;

   DRA_Algo_Mode_T align_cmd = (DRA_Algo_Mode_T)p_da_input_data->p_m2d_alignment_config->align_cmd;

   if (align_cmd != Alignment_Status_Prev)
   {
      Auto_align_Init(p_da_input_data);
   }
   Alignment_Status_Prev = align_cmd;

   /*DA vehicle data */
   Vse_Output_T *vse_output_input = &p_da_input_data->p_vse_stream->vse_output;
   Veh_Raw_Misc_T *veh_misc_input = &p_da_input_data->p_vse_stream->veh_raw_misc;
   vehicle_input.speed            = vse_output_input->raw_speed_mps;
   vehicle_input.yawrate          = vse_output_input->raw_yaw_rate_rps;
#ifdef ALIGN_STUB_SIMULATE_DET
   vehicle_input.speed_quality_factor   = DRA_VEH_QF_ACCURATE;
   vehicle_input.yawrate_quality_factor = DRA_VEH_QF_ACCURATE;
#else
   vehicle_input.speed_quality_factor = (DRA_Vehicle_QF_T)veh_misc_input->ego_vehicle_speed_qf;
   vehicle_input.yawrate_quality_factor = (DRA_Vehicle_QF_T)veh_misc_input->ego_yaw_rate_qf;
#endif
   vehicle_input.f_reverse           = (veh_misc_input->gear_pos == 1U);
   vehicle_input.f_trailer_connected = false;

   /* Operation mode data */
   radar_params.operation_mode = (DRA_Operation_Mode_T)(p_da_input_data->p_m2d_alignment_config->operation_mode_status -
                                                        1U); /*offset -1 is added here since Enum used to define Operation mode in
                                                                DRA is differnet from what is been used in rte core0 */

   convert_detections(p_da_input_data);

#ifdef ALIGN_STUB_SIMULATE_DET
   DRA_stub_test(p_detection_input, &initial_inputs, &vehicle_input, &radar_params, align_cmd, p_da_input_data);
#endif

   if (p_da_input_data->p_m2d_alignment_config->short_track_exit_condition == (uint8_t)DRA_SHORT_TRACK_EXIT_MANUAL)
   {
      align_internal_vars.short_track_exit_condition = DRA_SHORT_TRACK_EXIT_MANUAL;
      (void)DRA_Signal_Short_Track_Exit(&align_internal_vars);
   }

#ifdef ALIGN_STUB_SIMULATE_DET
   if (test_align_scan_index == 1)
   {
      p_detection_input->look_index = 100;
   }
   else if (test_align_scan_index == 2)
   {
      p_detection_input->look_index = 65535;
      test_align_scan_index         = 3;
   }
#endif

   DRA_Step_Execution(&alignment_log, &align_internal_vars, p_detections_prop, p_detection_input, &vehicle_input, &radar_params,
                      &cals_align);

#if defined(APRISM_DA_FASTLOCK_ENABLE) && (APRISM_DA_FASTLOCK_ENABLE == 1)
   /* A-PRISM fast-lock tracker (Run 17): reference dual-horizon schedule +
    * KF-delta lock detector. The gain readout documents the schedule the
    * @dabb owner adopts internally (a Gen8 wrapper cannot rewrite the buried
    * recursion); the num_updates cap above is the active Gen8-side effect.
   * KF field names follow this file's own PSP_SIL block (same @dabb struct).
   * Lock = boresight delta below APRISM_DA_LOCK_TOL_DEG for APRISM_DA_LOCK_NEED
   * consecutive scans (tunables above; defaults = Run-17 profile). */
   aprism_da_gain = DaDualHorizonGain(APRISM_DA_K_FAST, APRISM_DA_K_SLOW, APRISM_DA_ALPHA, aprism_da_scan_count);
   aprism_da_scan_count++;
   {
      float kf_err_deg =
         (rm_fabsf(align_internal_vars.vacs_boresight_kf_az - aprism_da_prev_kf_az) +
          rm_fabsf(align_internal_vars.vacs_boresight_kf_el - aprism_da_prev_kf_el)) *
         57.29578F;
      if (DaLockDetect(kf_err_deg, APRISM_DA_LOCK_TOL_DEG, &aprism_da_hold_count, APRISM_DA_LOCK_NEED))
      {
         aprism_da_locked = 1U;
      }
      aprism_da_prev_kf_az = align_internal_vars.vacs_boresight_kf_az;
      aprism_da_prev_kf_el = align_internal_vars.vacs_boresight_kf_el;
   }
#endif

   /* logging DA Output */
   Populate_Dyn_Align_Output(&alignment_log, p_da_input_data);

   /* Provides alignment_log parameter details to verify Integration Testing.
    * This section executes only when the Integration_Testing macro is enabled.
    */
   SIT_ALIGNMENT_LOG_DATA(&alignment_log);
}

/**
 *  @b Description
 *  @n
 *      Dynamic alignment Wrapper
 *
 *  @retval void
 */
void dyn_align_wrapper(D2M_Msg_T *p_d2m, M2D_Msg_T *p_m2d, M2D_One_Time_Msg_T *m2d_one_time_init_ptr)
{
   da_ptr_update(p_d2m, p_m2d, m2d_one_time_init_ptr, &da_input_data);
   Dynamic_Alignment_Data_T *dra_data = da_input_data.p_m2d_alignment_config;

   if ((dra_data->f_data_valid > 0U) && (0U == Dyn_Alignment_Init_Status))
   {
      Auto_align_Init(&da_input_data);
      Dyn_Alignment_Init_Status = 1U;
   }

   if (1U == Dyn_Alignment_Init_Status)
   {
      Execute_Dynamic_Alignment(&da_input_data);
   }
}

/* A-PRISM SiL/compare readouts (always compiled, zero baseline impact). */
float Aprism_Da_GetGain(void)
{
   return aprism_da_gain;
}

uint8_t Aprism_Da_IsLocked(void)
{
   return aprism_da_locked;
}

#if defined(APRISM_GHOST_INSPECT_ENABLE) && (APRISM_GHOST_INSPECT_ENABLE == 1)
uint16_t Aprism_Ghost_Inspected(void)
{
   return aprism_ghost_inspected;
}

uint16_t Aprism_Ghost_Refused(void)
{
   return aprism_ghost_refused;
}
#endif
