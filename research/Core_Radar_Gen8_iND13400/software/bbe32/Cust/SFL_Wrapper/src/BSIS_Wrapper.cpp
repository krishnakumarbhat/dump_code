/**************************************************************************************************\
* File: Bsis_Wrapper.cpp
***************************************************************************************************
* Copyright 2026 Aptiv, Inc., All Rights Reserved.
* Aptiv Confidential
*-------------------------------------------------------------------------------------------------
* Created on: Feb 18, 2026
* Author: Hari Kailash M M (3dm38i)
*-------------------------------------------------------------------------------------------------
*
* Description:
* Embedded Wrapper for BSIS features for AL SRR8 customer.
*
\**************************************************************************************************/

/**************************************************************************************************\
* Standard Header Includes
\**************************************************************************************************/
#include <string.h>

/**************************************************************************************************\
* Project Header Includes
\**************************************************************************************************/
#include "BSIS_Wrapper.h"
#include "SFL_Wrapper.h"
#include "ipc_dsp.h"
#include "reuse.h"
#include "smc_cal.h"

/* headers from FBK */
#include "fbk_macros.h"
#include "fbk_output.h"

/* headers from BSIS */
#include "bsis_core_calibration_t.h"
#include "bsis_iface.h"
#include "bsis_input_t.h"
#include "bsis_instance_t.h"
#include "bsis_output_t.h"
#include "bsis_types.h"

#if defined(SFL_OBJ_SIM_TEST)
   /* headers from sfl object simulation test */
   #include "SFL_Object_Simulator.h"
#endif

#if defined(SFL_UT)
   /* headers from sfl ut */
   #include "SFL_Adapter_Unit_Test.h"
#endif

/**************************************************************************************************\
* Local Preprocessor Constants
\**************************************************************************************************/

/**************************************************************************************************\
* File scope Type Definitions
\**************************************************************************************************/

/**************************************************************************************************\
* File scope variable Definitions
\**************************************************************************************************/
static Bsis_Instance_T SFL_Bsis_Instance;
static Bsis_Input_T SFL_Bsis_Input;
static Bsis_Output_T SFL_Bsis_Output;

/**************************************************************************************************\
* Global extern Function Prototypes
\**************************************************************************************************/

/**************************************************************************************************\
* Local Function Prototypes
\**************************************************************************************************/
static void SFL_Bsis_Cal_Update_Init(Bsis_Core_Calibration_T *SFL_Bsis_Cal_Ptr);

Bsis_Output_T *SFL_Bsis_Output_Ptr(void)
{
   return &SFL_Bsis_Output;
}

/*================================================================================================*\
* Function: SFL_Bsis_Cal_Update_Init()
*================================================================================================
* Parameters: Bsis_Core_Calibration_T*, Fbk_Vehicle_Data_T*
*
* Return Value: void
*
* Description: In this function Customer specific calibrations of BSIS are updated at init.
*
\*================================================================================================*/
static void SFL_Bsis_Cal_Update_Init(Bsis_Core_Calibration_T *SFL_Bsis_Cal_Ptr)
{
   if (k_gxcp_delay_smc == 1u) // Cheetah
   {
      // nothing as of now
   }
   else if (k_gxcp_delay_smc == 2u) // avatar
   {
      // nothing as of now
   }
   else
   {
      // do nothing
   }

   /* Calibration parameters (configure directly in SW) */
   SFL_Bsis_Cal_Ptr->k_bsis_f_bsis_enabled = 0U;

   /*Warning zone cals*/
   SFL_Bsis_Cal_Ptr->k_bsis_warning_zone_length              = 25.0f;
   SFL_Bsis_Cal_Ptr->k_bsis_warning_zone_width               = 3.6f;
   SFL_Bsis_Cal_Ptr->k_bsis_warning_zone_gap_to_ego          = 0.9;
   SFL_Bsis_Cal_Ptr->k_bsis_zone_length_extension_tos        = 6.5f;
   SFL_Bsis_Cal_Ptr->k_bsis_zone_length_extension_sot        = 6.3f;
   SFL_Bsis_Cal_Ptr->k_bsis_warning_zone_hysteresis[0]       = 0.4f;
   SFL_Bsis_Cal_Ptr->k_bsis_warning_zone_hysteresis[1]       = 1.0f;
   SFL_Bsis_Cal_Ptr->k_bsis_critical_approach_angle_diff_min = 0.09f;

   /*Danger zone cals*/
   SFL_Bsis_Cal_Ptr->k_bsis_danger_zone_length        = 1.6f;
   SFL_Bsis_Cal_Ptr->k_bsis_danger_zone_width         = 0.65f;
   SFL_Bsis_Cal_Ptr->k_bsis_danger_zone_gap_to_ego    = 0.25f;
   SFL_Bsis_Cal_Ptr->k_bsis_danger_zone_hysteresis[2] = 0.1f;

   /*Wing zone cals*/
   SFL_Bsis_Cal_Ptr->k_bsis_wing_zone_length         = 2.0f;
   SFL_Bsis_Cal_Ptr->k_bsis_wing_zone_width          = 3.5f;
   SFL_Bsis_Cal_Ptr->k_bsis_wing_zone_lat_gap_to_ego = 0.0f;

   /*Object related cals*/
   SFL_Bsis_Cal_Ptr->k_bsis_f_coasted_objects_are_relevant = 1U;
   SFL_Bsis_Cal_Ptr->k_bsis_host_speed_max                 = 8.33f;
   SFL_Bsis_Cal_Ptr->k_bsis_host_standstill_vel_min        = 1.0f;
   SFL_Bsis_Cal_Ptr->k_bsis_object_speed_min               = 1.11f;
   SFL_Bsis_Cal_Ptr->k_bsis_object_speed_max               = 6.95f;
   SFL_Bsis_Cal_Ptr->k_bsis_object_speed_hys               = 0.5f;
   SFL_Bsis_Cal_Ptr->k_bsis_object_area_max                = 5.5f;
   SFL_Bsis_Cal_Ptr->k_bsis_alert_qualifying_cycles        = 2U;
   SFL_Bsis_Cal_Ptr->k_bsis_alert_holding_cycles           = 5U;
}

/*================================================================================================*\
* Function: SFL_Bsis_Init()
*================================================================================================
* Parameters:
*
* Return Value: void
*
* Description: This function implements the initialization of Bsis Feature.
*
\*================================================================================================*/
void SFL_Bsis_Init(void)
{
   Bsis_Instance_T *SFL_Bsis_Instance_Ptr = &SFL_Bsis_Instance;

   if (nullptr != SFL_Bsis_Instance_Ptr)
   {
      (void)Bsis_Init_Platform(SFL_Bsis_Instance_Ptr);

      (void)SFL_Bsis_Cal_Update_Init(&SFL_Bsis_Instance_Ptr->calibration);
   }
}

/*================================================================================================*\
* Function: SFL_Bsis_Main()
*================================================================================================
* Parameters: Bsis_Instance_T*, Bsis_Input_T, const Fbk_Output_T*, Bsis_Output_T *
*
* Return Value: void
*
* Description: This function implements the periodic execution of BSIS Feature.
*
\*================================================================================================*/
void SFL_Bsis_Main(const Fbk_Output_T *SFL_Fbk_Output_Ptr, MM_SFLCore_T *p_MM_SFLCore)
{
   Bsis_Instance_T *SFL_Bsis_Instance_Ptr        = &SFL_Bsis_Instance;
   Bsis_Input_T *SFL_Bsis_Input_Ptr              = &SFL_Bsis_Input;
   Bsis_Output_T *SFL_Bsis_Output_Ptr            = &SFL_Bsis_Output;
   volatile HIL_Ipc_Info_T *m2d_hil_ipc_info_ptr = &(Get_IPC_M2D_Buffer()->payload.hil_ipc_info);

   if ((nullptr != SFL_Bsis_Instance_Ptr) && (nullptr != SFL_Bsis_Input_Ptr) && (nullptr != SFL_Fbk_Output_Ptr) &&
       (nullptr != SFL_Bsis_Output_Ptr))
   {
      SFL_Bsis_Input_Ptr->f_bsis_enable = p_MM_SFLCore->f_bsis_enable;

      if (m2d_hil_ipc_info_ptr->hil_mode_enabled == CODED_TRUE)
      {
         SFL_Bsis_Input_Ptr->f_bsis_enable = FBK_TRUE;
      }

      (void)Bsis_Run_Platform(SFL_Bsis_Instance_Ptr, SFL_Bsis_Input_Ptr, SFL_Fbk_Output_Ptr, SFL_Bsis_Output_Ptr);
   }
}

/*================================================================================================*\
* Function: SFL_Bsis_Reset_Cust_IPC()
*================================================================================================
* Parameters: Bsis_Stream_T*, Bsis_Instance_Stream_T,
*
* Return Value: void
*
* Description: This function implements the reseting of the IPC
*
\*================================================================================================*/
void SFL_Bsis_Reset_Cust_IPC(Bsis_Stream_T *ipc_bsis_cust_stream_p, Bsis_Instance_Stream_T *ipc_bsis_cust_instance_p)
{
   /*Mode Manager Output of the feature*/
   ipc_bsis_cust_stream_p->bsis_cust_mm_output.BSIS_Alert             = FBK_ZERO_UINT;
   ipc_bsis_cust_stream_p->bsis_cust_mm_output.BSIS_Systemsts         = FBK_ZERO_UINT;
   ipc_bsis_cust_stream_p->bsis_cust_mm_output.BSIS_OnOff_Setting_FBK = FBK_ZERO_UINT;
   ipc_bsis_cust_stream_p->bsis_cust_mm_output.BSIS_FailSts           = FBK_ZERO_UINT;
   ipc_bsis_cust_stream_p->bsis_cust_mm_output.BSIS_Blind             = FBK_ZERO_UINT;

   /*Customer Output of the feature*/
   ipc_bsis_cust_stream_p->bsis_cust_output.bsis_alert_left  = FBK_ZERO_UINT;
   ipc_bsis_cust_stream_p->bsis_cust_output.bsis_alert_right = FBK_ZERO_UINT;
   ipc_bsis_cust_stream_p->bsis_cust_output.bsis_id_left     = FBK_ZERO_UINT;
   ipc_bsis_cust_stream_p->bsis_cust_output.bsis_id_right    = FBK_ZERO_UINT;

   /*Customer Input of the feature*/
   ipc_bsis_cust_stream_p->bsis_cust_input.f_bsis_enable = FBK_ZERO_UINT;

   for (uint8_t i = 0; i < FBK_NUMBER_OF_SIDES; i++)
   {
      /* Persistent signals of the feature in instance*/
      ipc_bsis_cust_instance_p->persistent.bsis_alert_qualifying_counter[i]  = FBK_ZERO_UINT;
      ipc_bsis_cust_instance_p->persistent.bsis_alert_holding_counter[i]     = FBK_ZERO_UINT;
      ipc_bsis_cust_instance_p->persistent.bsis_holding_counter_extension[i] = FBK_ZERO_UINT;
      ipc_bsis_cust_instance_p->persistent.bsis_number_of_alert_cycles[i]    = FBK_ZERO_UINT;
      ipc_bsis_cust_instance_p->persistent.bsis_alert_prev_cycle[i]          = FBK_ZERO_UINT;
      ipc_bsis_cust_instance_p->persistent.bsis_id_prev_cycle[i]             = FBK_ZERO_UINT;

      /* Core Output signals of the feature in instance*/
      ipc_bsis_cust_instance_p->core_output.bsis_alert_level[i] = FBK_ZERO_UINT;
      ipc_bsis_cust_instance_p->core_output.bsis_id[i]          = FBK_ZERO_UINT;
      ipc_bsis_cust_instance_p->core_output.bsis_index[i]       = FBK_ZERO_UINT;
      ipc_bsis_cust_instance_p->core_output.bsis_ttc_predict[i] = FBK_ZERO_F;
   }

   /* ego_traj_predictor_instance signals of the feature in instance*/
   ipc_bsis_cust_instance_p->ego_traj_predictor_instance.Host_Circles_Props.offsets.offset_front_x  = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->ego_traj_predictor_instance.Host_Circles_Props.offsets.offset_middle_x = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->ego_traj_predictor_instance.Host_Circles_Props.offsets.offset_rear_x   = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->ego_traj_predictor_instance.Host_Circles_Props.radius                  = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->ego_traj_predictor_instance.Host_Curve_Radius                          = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->ego_traj_predictor_instance.Integral_Predicted_Velocity                = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->ego_traj_predictor_instance.Integral_Predicted_Arc_Length              = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->ego_traj_predictor_instance.F_Host_Circle_Props_Initialized            = FBK_ZERO_UINT;

   /* Core Output signals of the feature in instance*/
   ipc_bsis_cust_instance_p->core_input.f_bsis_enable = FBK_ZERO_UINT;

   /* Calibration signals of the feature in instance*/
   /* float32_T calibrations */
   ipc_bsis_cust_instance_p->calibration.k_bsis_host_speed_max                      = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_host_standstill_vel_min             = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_object_speed_min                    = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_object_speed_max                    = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_object_speed_hys                    = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_object_abs_heading_diff_max         = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_object_area_max                     = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_warning_zone_length                 = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_warning_zone_width                  = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_warning_zone_gap_to_ego             = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_zone_length_extension_sot           = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_zone_length_extension_tos           = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_area_intersection_valid_ratio       = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ego_acceleration_weight             = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ego_shape_gain_fixed                = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ego_circle_offset                   = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ego_circle_host_length_factor       = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ego_max_pred_yaw_angle              = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ego_shape_gain_per_pred_step        = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_obj_pred_speed_min                  = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_obj_shape_gain_per_pred_step        = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_obj_shape_gain_fixed                = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_critical_approach_angle_diff_min    = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_critical_approach_min_safe_distance = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ttc_predict_thresh_min              = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ttc_predict_thresh_max              = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ttc_predict_thresh_hys              = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ttc_reference_long_thresh           = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ttc_reference_lat_thresh            = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ttc_reference_long_thresh_hys       = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ttc_reference_lat_thresh_hys        = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_danger_zone_length                  = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_danger_zone_width                   = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_danger_zone_gap_to_ego              = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_wing_zone_length                    = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_wing_zone_width                     = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_wing_zone_lat_gap_to_ego            = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_wing_zone_long_gap_to_ego           = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_obj_wing_abs_heading_min            = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_obj_wing_abs_heading_max            = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_obj_wing_abs_heading_hysteresis     = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ego_braking_reaction_time           = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ego_braking_deceleration            = FBK_ZERO_F;

   /* warning_zone_hysteresis[4] */
   ipc_bsis_cust_instance_p->calibration.k_bsis_warning_zone_hysteresis_0 = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_warning_zone_hysteresis_1 = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_warning_zone_hysteresis_2 = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_warning_zone_hysteresis_3 = FBK_ZERO_F;

   /* danger_zone_hysteresis[4] */
   ipc_bsis_cust_instance_p->calibration.k_bsis_danger_zone_hysteresis_0 = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_danger_zone_hysteresis_1 = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_danger_zone_hysteresis_2 = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_danger_zone_hysteresis_3 = FBK_ZERO_F;

   /* wing_zone_hysteresis[4] */
   ipc_bsis_cust_instance_p->calibration.k_bsis_wing_zone_hysteresis_0 = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_wing_zone_hysteresis_1 = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_wing_zone_hysteresis_2 = FBK_ZERO_F;
   ipc_bsis_cust_instance_p->calibration.k_bsis_wing_zone_hysteresis_3 = FBK_ZERO_F;

   /* boolean_T calibrations */
   ipc_bsis_cust_instance_p->calibration.k_bsis_f_bsis_enabled                        = FBK_ZERO_UINT;
   ipc_bsis_cust_instance_p->calibration.k_bsis_f_coasted_objects_are_relevant        = FBK_ZERO_UINT;
   ipc_bsis_cust_instance_p->calibration.k_bsis_f_enable_ref_point_shift_for_ttp_calc = FBK_ZERO_UINT;
   ipc_bsis_cust_instance_p->calibration.k_bsis_f_enable_intersection_area_check      = FBK_ZERO_UINT;
   ipc_bsis_cust_instance_p->calibration.k_bsis_stop_holding_while_speed_out_of_range = FBK_ZERO_UINT;
   ipc_bsis_cust_instance_p->calibration.k_bsis_f_enable_alert_lvl_2                  = FBK_ZERO_UINT;
   ipc_bsis_cust_instance_p->calibration.k_bsis_f_enable_danger_zone_ttc_check        = FBK_ZERO_UINT;
   ipc_bsis_cust_instance_p->calibration.k_bsis_f_enable_dynamic_predict_ttc_thresh   = FBK_ZERO_UINT;

   /* alert_lvl_1_zone_lookup_table[3] */
   ipc_bsis_cust_instance_p->calibration.k_bsis_alert_lvl_1_zone_lookup_table_0 = FBK_ZERO_UINT;
   ipc_bsis_cust_instance_p->calibration.k_bsis_alert_lvl_1_zone_lookup_table_1 = FBK_ZERO_UINT;
   ipc_bsis_cust_instance_p->calibration.k_bsis_alert_lvl_1_zone_lookup_table_2 = FBK_ZERO_UINT;

   /* alert_lvl_2_zone_lookup_table[3] */
   ipc_bsis_cust_instance_p->calibration.k_bsis_alert_lvl_2_zone_lookup_table_0 = FBK_ZERO_UINT;
   ipc_bsis_cust_instance_p->calibration.k_bsis_alert_lvl_2_zone_lookup_table_1 = FBK_ZERO_UINT;
   ipc_bsis_cust_instance_p->calibration.k_bsis_alert_lvl_2_zone_lookup_table_2 = FBK_ZERO_UINT;

   /* uint8_t calibrations */
   ipc_bsis_cust_instance_p->calibration.k_bsis_alert_qualifying_cycles                = FBK_ZERO_UINT;
   ipc_bsis_cust_instance_p->calibration.k_bsis_alert_holding_cycles                   = FBK_ZERO_UINT;
   ipc_bsis_cust_instance_p->calibration.k_bsis_holding_counter_extension_max          = FBK_ZERO_UINT;
   ipc_bsis_cust_instance_p->calibration.k_bsis_minimum_number_of_alert_cycles         = FBK_ZERO_UINT;
   ipc_bsis_cust_instance_p->calibration.k_bsis_object_skip_qualification_age_min      = FBK_ZERO_UINT;
   ipc_bsis_cust_instance_p->calibration.k_bsis_prediction_steps_max                   = FBK_ZERO_UINT;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ego_pred_const_velocity_pred_steps_min = FBK_ZERO_UINT;

   /* critical_approach_check_ego_circles[3] */
   ipc_bsis_cust_instance_p->calibration.k_bsis_critical_approach_check_ego_circles_0 = FBK_ZERO_UINT;
   ipc_bsis_cust_instance_p->calibration.k_bsis_critical_approach_check_ego_circles_1 = FBK_ZERO_UINT;
   ipc_bsis_cust_instance_p->calibration.k_bsis_critical_approach_check_ego_circles_2 = FBK_ZERO_UINT;
}

/*================================================================================================*\
* Function: SFL_Bsis_Set_Cust_IPC()
*================================================================================================
* Parameters: Bsis_Stream_T*, Bsis_Instance_Stream_T,
*
* Return Value: void
*
* Description: This function implements the setting of the IPC
*
\*================================================================================================*/
void SFL_Bsis_Set_Cust_IPC(Bsis_Stream_T *ipc_bsis_cust_stream_p, Bsis_Instance_Stream_T *ipc_bsis_cust_instance_p)
{
   /*Customer Output of the feature*/
   ipc_bsis_cust_stream_p->bsis_cust_output.bsis_alert_left  = (uint8_t)SFL_Bsis_Output.bsis_alert_left;
   ipc_bsis_cust_stream_p->bsis_cust_output.bsis_alert_right = (uint8_t)SFL_Bsis_Output.bsis_alert_right;
   ipc_bsis_cust_stream_p->bsis_cust_output.bsis_id_left     = (uint8_t)SFL_Bsis_Output.bsis_id_left;
   ipc_bsis_cust_stream_p->bsis_cust_output.bsis_id_right    = (uint8_t)SFL_Bsis_Output.bsis_id_right;

   /*Customer Input of the feature*/
   ipc_bsis_cust_stream_p->bsis_cust_input.f_bsis_enable = (uint8_t)SFL_Bsis_Input.f_bsis_enable;

   for (uint8_t i = 0; i < FBK_NUMBER_OF_SIDES; i++)
   {
      /* Persistent signals of the feature in instance*/
      ipc_bsis_cust_instance_p->persistent.bsis_alert_qualifying_counter[i] =
         (uint8_t)SFL_Bsis_Instance.persistent.bsis_alert_qualifying_counter[i];
      ipc_bsis_cust_instance_p->persistent.bsis_alert_holding_counter[i] =
         (uint8_t)SFL_Bsis_Instance.persistent.bsis_alert_holding_counter[i];
      ipc_bsis_cust_instance_p->persistent.bsis_holding_counter_extension[i] =
         (uint8_t)SFL_Bsis_Instance.persistent.bsis_holding_counter_extension[i];
      ipc_bsis_cust_instance_p->persistent.bsis_number_of_alert_cycles[i] =
         (uint8_t)SFL_Bsis_Instance.persistent.bsis_number_of_alert_cycles[i];
      ipc_bsis_cust_instance_p->persistent.bsis_alert_prev_cycle[i] =
         (uint8_t)SFL_Bsis_Instance.persistent.bsis_alert_prev_cycle[i];
      ipc_bsis_cust_instance_p->persistent.bsis_id_prev_cycle[i] = (uint8_t)SFL_Bsis_Instance.persistent.bsis_id_prev_cycle[i];

      /* Core Output signals of the feature in instance*/
      ipc_bsis_cust_instance_p->core_output.bsis_alert_level[i] = (uint8_t)SFL_Bsis_Instance.core_output.bsis_alert_level[i];
      ipc_bsis_cust_instance_p->core_output.bsis_id[i]          = (uint8_t)SFL_Bsis_Instance.core_output.bsis_id[i];
      ipc_bsis_cust_instance_p->core_output.bsis_index[i]       = (uint8_t)SFL_Bsis_Instance.core_output.bsis_index[i];
      ipc_bsis_cust_instance_p->core_output.bsis_ttc_predict[i] = (float32_T)SFL_Bsis_Instance.core_output.bsis_ttc_predict[i];
   }

   /* ego_traj_predictor_instance signals of the feature in instance*/
   ipc_bsis_cust_instance_p->ego_traj_predictor_instance.Host_Circles_Props.offsets.offset_front_x =
      SFL_Bsis_Instance.ego_traj_predictor_instance.Host_Circles_Props.offsets.offset_front_x;
   ipc_bsis_cust_instance_p->ego_traj_predictor_instance.Host_Circles_Props.offsets.offset_middle_x =
      SFL_Bsis_Instance.ego_traj_predictor_instance.Host_Circles_Props.offsets.offset_middle_x;
   ipc_bsis_cust_instance_p->ego_traj_predictor_instance.Host_Circles_Props.offsets.offset_rear_x =
      SFL_Bsis_Instance.ego_traj_predictor_instance.Host_Circles_Props.offsets.offset_rear_x;
   ipc_bsis_cust_instance_p->ego_traj_predictor_instance.Host_Circles_Props.radius =
      SFL_Bsis_Instance.ego_traj_predictor_instance.Host_Circles_Props.radius;
   ipc_bsis_cust_instance_p->ego_traj_predictor_instance.Host_Curve_Radius =
      SFL_Bsis_Instance.ego_traj_predictor_instance.Host_Curve_Radius;
   ipc_bsis_cust_instance_p->ego_traj_predictor_instance.Integral_Predicted_Velocity =
      SFL_Bsis_Instance.ego_traj_predictor_instance.Integral_Predicted_Velocity;
   ipc_bsis_cust_instance_p->ego_traj_predictor_instance.Integral_Predicted_Arc_Length =
      SFL_Bsis_Instance.ego_traj_predictor_instance.Integral_Predicted_Arc_Length;
   ipc_bsis_cust_instance_p->ego_traj_predictor_instance.F_Host_Circle_Props_Initialized =
      SFL_Bsis_Instance.ego_traj_predictor_instance.F_Host_Circle_Props_Initialized;

   /* Core Output signals of the feature in instance*/
   ipc_bsis_cust_instance_p->core_input.f_bsis_enable = (uint8_t)SFL_Bsis_Instance.core_input.f_bsis_enable;

   /* Calibration signals of the feature in instance*/
   /* float32_T calibrations */
   ipc_bsis_cust_instance_p->calibration.k_bsis_host_speed_max = (float32_T)SFL_Bsis_Instance.calibration.k_bsis_host_speed_max;
   ipc_bsis_cust_instance_p->calibration.k_bsis_host_standstill_vel_min =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_host_standstill_vel_min;
   ipc_bsis_cust_instance_p->calibration.k_bsis_object_speed_min =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_object_speed_min;
   ipc_bsis_cust_instance_p->calibration.k_bsis_object_speed_max =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_object_speed_max;
   ipc_bsis_cust_instance_p->calibration.k_bsis_object_speed_hys =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_object_speed_hys;
   ipc_bsis_cust_instance_p->calibration.k_bsis_object_abs_heading_diff_max =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_object_abs_heading_diff_max;
   ipc_bsis_cust_instance_p->calibration.k_bsis_object_area_max = (float32_T)SFL_Bsis_Instance.calibration.k_bsis_object_area_max;
   ipc_bsis_cust_instance_p->calibration.k_bsis_warning_zone_length =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_warning_zone_length;
   ipc_bsis_cust_instance_p->calibration.k_bsis_warning_zone_width =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_warning_zone_width;
   ipc_bsis_cust_instance_p->calibration.k_bsis_warning_zone_gap_to_ego =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_warning_zone_gap_to_ego;
   ipc_bsis_cust_instance_p->calibration.k_bsis_zone_length_extension_sot =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_zone_length_extension_sot;
   ipc_bsis_cust_instance_p->calibration.k_bsis_zone_length_extension_tos =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_zone_length_extension_tos;
   ipc_bsis_cust_instance_p->calibration.k_bsis_area_intersection_valid_ratio =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_area_intersection_valid_ratio;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ego_acceleration_weight =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_ego_acceleration_weight;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ego_shape_gain_fixed =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_ego_shape_gain_fixed;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ego_circle_offset =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_ego_circle_offset;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ego_circle_host_length_factor =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_ego_circle_host_length_factor;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ego_max_pred_yaw_angle =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_ego_max_pred_yaw_angle;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ego_shape_gain_per_pred_step =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_ego_shape_gain_per_pred_step;
   ipc_bsis_cust_instance_p->calibration.k_bsis_obj_pred_speed_min =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_obj_pred_speed_min;
   ipc_bsis_cust_instance_p->calibration.k_bsis_obj_shape_gain_per_pred_step =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_obj_shape_gain_per_pred_step;
   ipc_bsis_cust_instance_p->calibration.k_bsis_obj_shape_gain_fixed =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_obj_shape_gain_fixed;
   ipc_bsis_cust_instance_p->calibration.k_bsis_critical_approach_angle_diff_min =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_critical_approach_angle_diff_min;
   ipc_bsis_cust_instance_p->calibration.k_bsis_critical_approach_min_safe_distance =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_critical_approach_min_safe_distance;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ttc_predict_thresh_min =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_ttc_predict_thresh_min;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ttc_predict_thresh_max =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_ttc_predict_thresh_max;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ttc_predict_thresh_hys =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_ttc_predict_thresh_hys;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ttc_reference_long_thresh =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_ttc_reference_long_thresh;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ttc_reference_lat_thresh =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_ttc_reference_lat_thresh;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ttc_reference_long_thresh_hys =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_ttc_reference_long_thresh_hys;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ttc_reference_lat_thresh_hys =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_ttc_reference_lat_thresh_hys;
   ipc_bsis_cust_instance_p->calibration.k_bsis_danger_zone_length =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_danger_zone_length;
   ipc_bsis_cust_instance_p->calibration.k_bsis_danger_zone_width =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_danger_zone_width;
   ipc_bsis_cust_instance_p->calibration.k_bsis_danger_zone_gap_to_ego =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_danger_zone_gap_to_ego;
   ipc_bsis_cust_instance_p->calibration.k_bsis_wing_zone_length =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_wing_zone_length;
   ipc_bsis_cust_instance_p->calibration.k_bsis_wing_zone_width = (float32_T)SFL_Bsis_Instance.calibration.k_bsis_wing_zone_width;
   ipc_bsis_cust_instance_p->calibration.k_bsis_wing_zone_lat_gap_to_ego =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_wing_zone_lat_gap_to_ego;
   ipc_bsis_cust_instance_p->calibration.k_bsis_wing_zone_long_gap_to_ego =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_wing_zone_long_gap_to_ego;
   ipc_bsis_cust_instance_p->calibration.k_bsis_obj_wing_abs_heading_min =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_obj_wing_abs_heading_min;
   ipc_bsis_cust_instance_p->calibration.k_bsis_obj_wing_abs_heading_max =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_obj_wing_abs_heading_max;
   ipc_bsis_cust_instance_p->calibration.k_bsis_obj_wing_abs_heading_hysteresis =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_obj_wing_abs_heading_hysteresis;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ego_braking_reaction_time =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_ego_braking_reaction_time;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ego_braking_deceleration =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_ego_braking_deceleration;

   /* warning_zone_hysteresis[4] */
   ipc_bsis_cust_instance_p->calibration.k_bsis_warning_zone_hysteresis_0 =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_warning_zone_hysteresis[0];
   ipc_bsis_cust_instance_p->calibration.k_bsis_warning_zone_hysteresis_1 =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_warning_zone_hysteresis[1];
   ipc_bsis_cust_instance_p->calibration.k_bsis_warning_zone_hysteresis_2 =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_warning_zone_hysteresis[2];
   ipc_bsis_cust_instance_p->calibration.k_bsis_warning_zone_hysteresis_3 =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_warning_zone_hysteresis[3];

   /* danger_zone_hysteresis[4] */
   ipc_bsis_cust_instance_p->calibration.k_bsis_danger_zone_hysteresis_0 =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_danger_zone_hysteresis[0];
   ipc_bsis_cust_instance_p->calibration.k_bsis_danger_zone_hysteresis_1 =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_danger_zone_hysteresis[1];
   ipc_bsis_cust_instance_p->calibration.k_bsis_danger_zone_hysteresis_2 =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_danger_zone_hysteresis[2];
   ipc_bsis_cust_instance_p->calibration.k_bsis_danger_zone_hysteresis_3 =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_danger_zone_hysteresis[3];

   /* wing_zone_hysteresis[4] */
   ipc_bsis_cust_instance_p->calibration.k_bsis_wing_zone_hysteresis_0 =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_wing_zone_hysteresis[0];
   ipc_bsis_cust_instance_p->calibration.k_bsis_wing_zone_hysteresis_1 =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_wing_zone_hysteresis[1];
   ipc_bsis_cust_instance_p->calibration.k_bsis_wing_zone_hysteresis_2 =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_wing_zone_hysteresis[2];
   ipc_bsis_cust_instance_p->calibration.k_bsis_wing_zone_hysteresis_3 =
      (float32_T)SFL_Bsis_Instance.calibration.k_bsis_wing_zone_hysteresis[3];

   /* boolean_T */
   ipc_bsis_cust_instance_p->calibration.k_bsis_f_bsis_enabled = (uint8_t)SFL_Bsis_Instance.calibration.k_bsis_f_bsis_enabled;
   ipc_bsis_cust_instance_p->calibration.k_bsis_f_coasted_objects_are_relevant =
      (uint8_t)SFL_Bsis_Instance.calibration.k_bsis_f_coasted_objects_are_relevant;
   ipc_bsis_cust_instance_p->calibration.k_bsis_f_enable_ref_point_shift_for_ttp_calc =
      (uint8_t)SFL_Bsis_Instance.calibration.k_bsis_f_enable_ref_point_shift_for_ttp_calc;
   ipc_bsis_cust_instance_p->calibration.k_bsis_f_enable_intersection_area_check =
      (uint8_t)SFL_Bsis_Instance.calibration.k_bsis_f_enable_intersection_area_check;
   ipc_bsis_cust_instance_p->calibration.k_bsis_stop_holding_while_speed_out_of_range =
      (uint8_t)SFL_Bsis_Instance.calibration.k_bsis_stop_holding_while_speed_out_of_range;
   ipc_bsis_cust_instance_p->calibration.k_bsis_f_enable_alert_lvl_2 =
      (uint8_t)SFL_Bsis_Instance.calibration.k_bsis_f_enable_alert_lvl_2;
   ipc_bsis_cust_instance_p->calibration.k_bsis_f_enable_danger_zone_ttc_check =
      (uint8_t)SFL_Bsis_Instance.calibration.k_bsis_f_enable_danger_zone_ttc_check;
   ipc_bsis_cust_instance_p->calibration.k_bsis_f_enable_dynamic_predict_ttc_thresh =
      (uint8_t)SFL_Bsis_Instance.calibration.k_bsis_f_enable_dynamic_predict_ttc_thresh;

   /* alert_lvl_1_zone_lookup_table[3] */
   ipc_bsis_cust_instance_p->calibration.k_bsis_alert_lvl_1_zone_lookup_table_0 =
      (uint8_t)SFL_Bsis_Instance.calibration.k_bsis_alert_lvl_1_zone_lookup_table[0];
   ipc_bsis_cust_instance_p->calibration.k_bsis_alert_lvl_1_zone_lookup_table_1 =
      (uint8_t)SFL_Bsis_Instance.calibration.k_bsis_alert_lvl_1_zone_lookup_table[1];
   ipc_bsis_cust_instance_p->calibration.k_bsis_alert_lvl_1_zone_lookup_table_2 =
      (uint8_t)SFL_Bsis_Instance.calibration.k_bsis_alert_lvl_1_zone_lookup_table[2];

   /* alert_lvl_2_zone_lookup_table[3] */
   ipc_bsis_cust_instance_p->calibration.k_bsis_alert_lvl_2_zone_lookup_table_0 =
      (uint8_t)SFL_Bsis_Instance.calibration.k_bsis_alert_lvl_2_zone_lookup_table[0];
   ipc_bsis_cust_instance_p->calibration.k_bsis_alert_lvl_2_zone_lookup_table_1 =
      (uint8_t)SFL_Bsis_Instance.calibration.k_bsis_alert_lvl_2_zone_lookup_table[1];
   ipc_bsis_cust_instance_p->calibration.k_bsis_alert_lvl_2_zone_lookup_table_2 =
      (uint8_t)SFL_Bsis_Instance.calibration.k_bsis_alert_lvl_2_zone_lookup_table[2];

   /* uint8_t */
   ipc_bsis_cust_instance_p->calibration.k_bsis_alert_qualifying_cycles =
      (uint8_t)SFL_Bsis_Instance.calibration.k_bsis_alert_qualifying_cycles;
   ipc_bsis_cust_instance_p->calibration.k_bsis_alert_holding_cycles =
      (uint8_t)SFL_Bsis_Instance.calibration.k_bsis_alert_holding_cycles;
   ipc_bsis_cust_instance_p->calibration.k_bsis_holding_counter_extension_max =
      (uint8_t)SFL_Bsis_Instance.calibration.k_bsis_holding_counter_extension_max;
   ipc_bsis_cust_instance_p->calibration.k_bsis_minimum_number_of_alert_cycles =
      (uint8_t)SFL_Bsis_Instance.calibration.k_bsis_minimum_number_of_alert_cycles;
   ipc_bsis_cust_instance_p->calibration.k_bsis_object_skip_qualification_age_min =
      (uint8_t)SFL_Bsis_Instance.calibration.k_bsis_object_skip_qualification_age_min;
   ipc_bsis_cust_instance_p->calibration.k_bsis_prediction_steps_max =
      (uint8_t)SFL_Bsis_Instance.calibration.k_bsis_prediction_steps_max;
   ipc_bsis_cust_instance_p->calibration.k_bsis_ego_pred_const_velocity_pred_steps_min =
      (uint8_t)SFL_Bsis_Instance.calibration.k_bsis_ego_pred_const_velocity_pred_steps_min;

   /* critical_approach_check_ego_circles[3] */
   ipc_bsis_cust_instance_p->calibration.k_bsis_critical_approach_check_ego_circles_0 =
      (uint8_t)SFL_Bsis_Instance.calibration.k_bsis_critical_approach_check_ego_circles[0];
   ipc_bsis_cust_instance_p->calibration.k_bsis_critical_approach_check_ego_circles_1 =
      (uint8_t)SFL_Bsis_Instance.calibration.k_bsis_critical_approach_check_ego_circles[1];
   ipc_bsis_cust_instance_p->calibration.k_bsis_critical_approach_check_ego_circles_2 =
      (uint8_t)SFL_Bsis_Instance.calibration.k_bsis_critical_approach_check_ego_circles[2];
}
/**************************************************************************************************\
* Start of Global Scope Function Definitions
\**************************************************************************************************/

/**************************************************************************************************\
* End of Global Scope Function Definitions
\**************************************************************************************************/

/*================================================================================================*\
* Revision History
*================================================================================================
*    Date          By                     Description
* MM/DD/YYYY  Name/Initials            JIRA AAA-#### Explanation of changes
* ----------  -------------            ----------------------------------------------------------
* 18/02/2026 Hari Kailash M M           BSIS Wrapper
\*================================================================================================*/
