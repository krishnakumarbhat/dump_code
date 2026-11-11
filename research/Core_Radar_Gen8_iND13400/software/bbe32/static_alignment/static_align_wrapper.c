/*===========================================================================*/
/**
 * @file static_align_wrapper.c
 *
 * Application interface mapping for Static Alignment
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 *
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Application interface mapping for Static Alignment
 * @section File : static_align_wrapper.c
 *
 * @section purpose PURPOSE: Static alignment wrapper implementation
 *
 * @section ABBR ABBREVIATIONS:
 *   -  List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     -  Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     -  Update list of requirements document(s)
 *
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
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "ipc_data.h"
#include "rdd_stream.h"
#include "sra_initialization.h"
#include "sra_step_execution.h"
#include "static_align_wrapper.h"
#ifndef UNIT_TEST_SA
   #ifdef PSP_SIL_ENABLE
      #include <math.h>
   #else
      #include "radar_math.h"
   #endif
#endif
#ifdef ALIGN_STUB_SIMULATE_DET
   #include "sra_simulate_detections.h"
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */
#ifndef Deg2Radians
   #define Deg2Radians (0.0174532925199433F)
#endif
#ifndef Rad2Degree
   #define Rad2Degree (57.2957795130823069F)
#endif
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
static SA_Internal_Mem_Info_T SA_Internal_Mem_Info[SA_MP_MAX_NUM_MEMORY_LOC];
static SRA_Internal_Variables_T sra_align_internal_vars = {0};
#ifdef PSP_SIL_ENABLE
static SRA_Detection_Input_T sra_det_input_data;
static SRA_Detection_Input_T *sra_det_input = &sra_det_input_data;
#else
static SRA_Detection_Input_T *sra_det_input = {0};
#endif
static SRA_Vehicle_Data_T sra_veh_params         = {0};
static SRA_Radar_Parameters_T sra_radar_params   = {0};
static SRA_Target_Parameters_T sra_target_params = {0};
static SRA_Initial_Input_T sra_initial_inputs    = {0};
Static_Alignment_Log_Stream_T sra_logging        = {0};

#ifdef ALIGN_STUB_SIMULATE_DET
volatile static float Exp_Misalign_Yaw                   = (4.0F * SRA_DEG2RAD);
volatile static float Exp_Misalign_Pitch                 = (4.0F * SRA_DEG2RAD);
volatile static uint8_t Static_Alignment_Neg_Test_Enable = CODED_FALSE;
volatile static float Static_Neg_Test_Veh_Speed          = 0.0F;
volatile static uint8_t Static_Interference_Level        = 0U;
#endif
/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
static void __attribute__((noinline)) convert_detections(SA_Input_Data_T *p_sa_ipc_data, AF_Detection_T *p_af_dets);
static void Static_align_Init(SA_Input_Data_T *p_sa_ipc_data);
static void Execute_Static_Alignment(SA_Input_Data_T *p_sa_ipc_data);
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
/*****************************************************************************
 *. Name: Get_SA_Internal_memory_pointers
 *. This function will get the memory pointer to all static alignment structures.
 *.
 *. Parameters:
 *. void
 *.
 *. Return Value: SA_Internal_Mem_Info_T
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
SA_Internal_Mem_Info_T *Get_SA_Internal_memory_pointers(void)
{
   /* Clear memory details before assign*/
   (void)memset(SA_Internal_Mem_Info, 0U, sizeof(SA_Internal_Mem_Info));

   /*Assign required memory*/
   SA_Internal_Mem_Info[0].size     = sizeof(*sra_det_input);
   SA_Internal_Mem_Info[0].addr_ptr = (void **)&sra_det_input;
   return SA_Internal_Mem_Info;
}
/*****************************************************************************
 *. Name: SA_Alignment_Handler_Memory_Init
 *. This function will allocate memory from mempool for all static alignment structures
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
Memory_Pool_Return_T SA_Alignment_Handler_Memory_Init(Mem_Pool_T *mem_pool)
{
   Memory_Pool_Return_T retVal = MEM_POOL_SUCCESS;
   uint8_t mem_loc             = 0U;

   SA_Internal_Mem_Info_T *SA_Internal_memory_ptr = Get_SA_Internal_memory_pointers();

   do
   {
      if ((NULL != SA_Internal_memory_ptr[mem_loc].addr_ptr) && (0U != SA_Internal_memory_ptr[mem_loc].size))
      {
         retVal = Mem_Pool_Alloc(mem_pool, SA_Internal_memory_ptr[mem_loc].size, SA_Internal_memory_ptr[mem_loc].addr_ptr);
      }
      mem_loc++;
   } while ((MEM_POOL_SUCCESS == retVal) && (mem_loc < SA_MP_MAX_NUM_MEMORY_LOC));

   return retVal;
}
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
/*****************************************************************************
 *. Name: sa_ptr_update
 *. This function will initialise the input and output pointers required for SA Execution.
 *.
 *. Parameters:A2M_Msg_T *p_ipc_a2m, D2M_Msg_T *p_ipc_d2m,M2D_One_Time_Msg_T *m2d_one_time_init_ptr, SA_Input_Data_T
 **p_sa_ipc_data.
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
void sa_ptr_update(M2D_Msg_T *p_m2d, D2M_Msg_T *p_d2m, M2D_One_Time_Msg_T *m2d_one_time_init_ptr, SA_Input_Data_T *p_sa_ipc_data)
{
   p_sa_ipc_data->p_sa_data                = &p_m2d->payload.alignment_Info.static_alignment_data;
   p_sa_ipc_data->p_da_data                = &p_m2d->payload.alignment_Info.dynamic_alignment_data;
   p_sa_ipc_data->p_sa_calib_data          = &m2d_one_time_init_ptr->calib_data;
   p_sa_ipc_data->p_da_one_time_init_data  = m2d_one_time_init_ptr;
   p_sa_ipc_data->p_af_det_data            = &p_d2m->payload.det_data;
   p_sa_ipc_data->p_vehicle_data           = &p_m2d->payload.veh_data;
   p_sa_ipc_data->p_stat_align_stream_data = &p_d2m->payload.alignment_stream_data;
   p_sa_ipc_data->p_ID_data                = &p_d2m->payload.interference_detection_data;
   p_sa_ipc_data->p_rdd_stream_data        = &p_d2m->payload.rdd_stream_data;
#if (DOWNSELECTION_ENABLE == 1U)
   p_sa_ipc_data->p_toi_ds_stream = &p_d2m->payload.toi_ds_stream_data;
#else
   p_sa_ipc_data->p_toi_stream                       = &p_d2m->payload.toi_stream_data;
#endif
}

static void Static_align_Init(SA_Input_Data_T *p_sa_ipc_data)
{
   Static_Alignment_Data_T *sra_data         = p_sa_ipc_data->p_sa_data;
   Sensor_Calib_Data_T *sa_sensor_calib_data = &p_sa_ipc_data->p_sa_calib_data->sensor_calib_data;
   uint8_t sensor_posn                       = p_sa_ipc_data->p_da_one_time_init_data->radar_position;

   if (sensor_posn == (uint8_t)RADAR_POSITION_FRONT_CENTER)
   {
      sra_radar_params.radar_type = (SRA_Radar_Type_T)SRA_RADAR_TYPE_FLR8;
   }
   else
   {
      sra_radar_params.radar_type = (SRA_Radar_Type_T)SRA_RADAR_TYPE_SRR8P;
   }

   /*Radar parameters Init*/
   sra_radar_params.vacs_boresight_az_nominal   = sa_sensor_calib_data->sensor_mount_data.k_sensor_mount_ornt_yaw * -1.0F;
   sra_radar_params.vacs_boresight_el_nominal   = sa_sensor_calib_data->sensor_mount_data.k_sensor_mount_ornt_pitch * -1.0F;
   sra_radar_params.vacs_boresight_roll_nominal = sa_sensor_calib_data->sensor_mount_data.k_sensor_mount_ornt_roll;
   sra_radar_params.vcs_sensor_lat_posn         = sa_sensor_calib_data->sensor_mount_data.k_sensor_mount_pos_y * -1.0F;
   sra_radar_params.vcs_sensor_long_posn        = sa_sensor_calib_data->sensor_mount_data.k_sensor_mount_pos_x -
                                           p_sa_ipc_data->p_sa_calib_data->vehicle_calib_data.k_distance_front_bumper_to_rear_axle;
   sra_radar_params.sensor_height_over_ground = sa_sensor_calib_data->sensor_mount_data.k_sensor_mount_pos_z;
   sra_radar_params.mount_loc                 = (SRA_Mounting_Location_T)sra_data->mount_loc;
   sra_target_params.target_height_over_ground =
      sa_sensor_calib_data->sensor_mount_data.k_sensor_mount_pos_z; /*Assuming Flat plate height same as Radar Height*/

   /*Target parameters Init*/
   sra_target_params.scs_target_angle_azimuth = sra_data->plate_angle_deg_scs;
   sra_target_params.scs_target_distance      = sra_data->plate_distance;
   sra_target_params.target_range_rate        = sra_data->pitch;
   sra_target_params.target_type_select       = (SRA_Target_Type_Select_T)sra_data->target_type_select;

   /*Initial input parameters Init*/
#ifdef PSP_SIL_ENABLE
   sra_initial_inputs.max_abs_misalignment_az        = fabsf((sra_data->horz_angle_max * SRA_DEG2RAD));
   sra_initial_inputs.max_abs_misalignment_el_sky    = fabsf((sra_data->vert_angle_max * SRA_DEG2RAD));
   sra_initial_inputs.max_abs_misalignment_el_ground = fabsf((sra_data->vert_angle_max * SRA_DEG2RAD));
#else
   sra_initial_inputs.max_abs_misalignment_az        = rm_fabsf((sra_data->horz_angle_max * SRA_DEG2RAD));
   sra_initial_inputs.max_abs_misalignment_el_sky    = rm_fabsf((sra_data->vert_angle_max * SRA_DEG2RAD));
   sra_initial_inputs.max_abs_misalignment_el_ground = rm_fabsf((sra_data->vert_angle_max * SRA_DEG2RAD));
#endif
   sra_initial_inputs.k_num_valid_scan_needed = sra_data->k_num_valid_scan_needed;
   // sra_initial_inputs.k_max_number_of_scans_allowed = SRA_MAX_NUM_QUALIFIED_DETS;
   sra_initial_inputs.k_max_number_of_scans_allowed = sra_data->k_max_number_of_scans_allowed;
   SRA_Initialization(&sra_align_internal_vars, &sra_initial_inputs, &sra_target_params, &sra_radar_params);
}

/**
 *  @b Description
 *  @n
 *
 *
 */
static void __attribute__((noinline)) convert_detections(SA_Input_Data_T *p_sa_ipc_data, AF_Detection_T *p_af_dets)
{
   uint8_t i                                   = 0;
   uint8_t id_level                            = p_sa_ipc_data->p_ID_data->interference_level;
   Dynamic_Alignment_Data_T *p_da_data         = p_sa_ipc_data->p_da_data;
   sra_det_input->interference_detection_level = SRA_NO_DEGRADATION;

   if (id_level == 4)
   {
      sra_det_input->interference_detection_level = SRA_DEGRADATION_HIGH;
   }

   sra_det_input->detection_coordinate_system = SRA_DET_COORD_SYS_ISO; /*p_sa_ipc_data->p_sa_data->coordinate_system_input;*/
   sra_det_input->look_index                  = p_sa_ipc_data->p_af_det_data->det_list_property.lookindex;
   /*Max Allowed Detections for EOL is SRA_NUMBER_OF_DETECTIONS*/
   sra_det_input->number_of_detections =
      (uint16_t)MIN(((uint16_t)p_sa_ipc_data->p_af_det_data->num_af_det), SRA_NUMBER_OF_DETECTIONS);
#if (DOWNSELECTION_ENABLE == 1U)
   sra_det_input->data_qualifier =
      ((SRA_Data_Qualifier_T)((uint8_t)p_sa_ipc_data->p_toi_ds_stream->toi_op_data.data_qualifier - 1));
#else
   sra_det_input->data_qualifier = (SRA_Data_Qualifier_T)((uint8_t)p_sa_ipc_data->p_toi_stream->toi_op_data.data_qualifier - 1);
#endif

   /*Vehicle parameters Init*/
   sra_veh_params.speed   = p_sa_ipc_data->p_vehicle_data->vse_output.raw_speed_mps;
   sra_veh_params.yawrate = p_sa_ipc_data->p_vehicle_data->vse_output.raw_yaw_rate_rps;
   sra_radar_params.operation_mode =
      (SRA_Operation_Mode_T)(p_da_data->operation_mode_status -
                             1U); /*offset -1 is added here since Enum used to define Operation mode
                                                in            SRA is differnet from what is been used in rte core0 */

   for (i = 0; i < SRA_NUMBER_OF_DETECTIONS; i++)
   {
      sra_det_input->detections[i].azimuth_raw    = p_af_dets[i].theta;
      sra_det_input->detections[i].elevation_raw  = p_af_dets[i].phi;
      sra_det_input->detections[i].range          = p_af_dets[i].ran;
      sra_det_input->detections[i].range_rate_raw = p_af_dets[i].vel;

      sra_det_input->detections[i].snr   = p_af_dets[i].snr;
      sra_det_input->detections[i].power = p_af_dets[i].pow;

      sra_det_input->detections[i].f_super_res_target = (bool)p_af_dets[i].f_superres_target;
      sra_det_input->detections[i].f_valid_level      = 1u;

      sra_det_input->detections[i].raw_amplitude = p_af_dets[i].rcs;
   }
}

static void Populate_Sra_Align_Output(Static_Alignment_Log_Stream_T *sa_log_int, SA_Input_Data_T *p_sa_ipc_data)
{
   Static_Alignment_Log_Stream_T *sa_ipc_loc = p_sa_ipc_data->p_stat_align_stream_data;
   memcpy(sa_ipc_loc, sa_log_int, sizeof(Static_Alignment_Log_Stream_T));

   /*Update scan_index for Alignment_Stream*/
   p_sa_ipc_data->p_stat_align_stream_data->stream_hdr.scan_index = p_sa_ipc_data->p_rdd_stream_data->look_data.scan_index;
}

/**
 *  @b Description
 *  @n
 *
 *
 */
static void Execute_Static_Alignment(SA_Input_Data_T *p_sa_ipc_data)
{
   AF_Detection_T *p_af_dets = (AF_Detection_T *)p_sa_ipc_data->p_af_det_data->af_dets;

   convert_detections(p_sa_ipc_data, p_af_dets);

#ifdef ALIGN_STUB_SIMULATE_DET
   SRA_Simulate_Detections(sra_det_input, &sra_veh_params, &sra_radar_params, &sra_target_params, Exp_Misalign_Yaw,
                           Exp_Misalign_Pitch);
   if (CODED_TRUE == Static_Alignment_Neg_Test_Enable)
   {
      sra_veh_params.speed   = Static_Neg_Test_Veh_Speed;
      sra_veh_params.yawrate = p_sa_ipc_data->p_vehicle_data->vse_output.raw_yaw_rate_rps;
   }
   sra_det_input->interference_detection_level = Static_Interference_Level;
#endif
   /* Decision for static Alignment Type */
   SRA_Step_Execution(&sra_logging, &sra_align_internal_vars, sra_det_input, &sra_veh_params, &sra_radar_params,
                      &sra_target_params);
}

/**
 *  @b Description
 *  @n
 *      Static alignment Wrapper
 *
 */
void static_align_wrapper(D2M_Msg_T *p_d2m, M2D_Msg_T *p_m2d, M2D_One_Time_Msg_T *m2d_one_time_init_ptr)
{
   static uint8_t Static_Alignment_Init_Status = 0U;
   /*Enabled once ipc dependencies are fixed*/
   static uint8_t prev_align_cmd = 0U;
   SA_Input_Data_T sa_ipc_data   = {0};
   sa_ptr_update(p_m2d, p_d2m, m2d_one_time_init_ptr, &sa_ipc_data);
   Static_Alignment_Data_T *sra_data = sa_ipc_data.p_sa_data;
   if (sra_data != NULL)
   {
      if (((sra_data->f_data_valid > 0U) && (0U == Static_Alignment_Init_Status)) || (sra_data->align_cmd != prev_align_cmd))
      {
         Static_align_Init(&sa_ipc_data); // Init call
         Static_Alignment_Init_Status      = 1U;
         sra_align_internal_vars.align_cmd = (SRA_Algo_Mode_T)sra_data->align_cmd;
      }

      prev_align_cmd = sra_data->align_cmd;

      /*Execute Static Alignment only if Static Alignment is triggered. Added "alignment_mode" check to ensure responce is updated
       * after Off is Requested*/
      if ((1U == Static_Alignment_Init_Status) || ((uint8_t)SRA_ALGO_MODE_ACTIVE == sra_data->align_cmd) ||
          (1U == sra_logging.sra_core_data.alignment_mode))
      {
         Static_Alignment_Init_Status = 2U;
         Execute_Static_Alignment(&sa_ipc_data);
      }
      Populate_Sra_Align_Output(&sra_logging, &sa_ipc_data);
   }
   else
   {
      /* sra_data is NULL, no static alignment data available. */
   }
}
