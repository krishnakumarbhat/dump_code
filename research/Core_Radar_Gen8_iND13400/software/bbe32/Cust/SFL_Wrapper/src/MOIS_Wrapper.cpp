/**************************************************************************************************\
* File: Mois_Wrapper.cpp
***************************************************************************************************
* Copyright 2026 Aptiv, Inc., All Rights Reserved.
* Aptiv Confidential
*-------------------------------------------------------------------------------------------------
* Created on: Feb 18, 2026
* Author: Hari Kailash M M (3dm38i)
*-------------------------------------------------------------------------------------------------
*
* Description:
* Embedded Wrapper for MOIS features for AL SRR8 customer.
*
\**************************************************************************************************/

/**************************************************************************************************\
* Standard Header Includes
\**************************************************************************************************/
#include <string.h>

/**************************************************************************************************\
* Project Header Includes
\**************************************************************************************************/
#include "MOIS_Wrapper.h"
#include "SFL_Wrapper.h"
#include "ipc_dsp.h"
#include "reuse.h"
#include "smc_cal.h"

/* headers from FBK */
#include "fbk_macros.h"
#include "fbk_output.h"

/* headers from MOIS */
#include "mois_core_calibration_t.h"
#include "mois_iface.h"
#include "mois_input_t.h"
#include "mois_instance.h"
#include "mois_output_t.h"
#include "mois_types.h"

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
static Mois_Instance_T SFL_Mois_Instance;
static Mois_Input_T SFL_Mois_Input;
static Mois_Output_T SFL_Mois_Output;

/**************************************************************************************************\
* Global extern Function Prototypes
\**************************************************************************************************/

/**************************************************************************************************\
* Local Function Prototypes
\**************************************************************************************************/
static void SFL_Mois_Cal_Update_Init(Mois_Core_Calibration_T *SFL_Mois_Cal_Ptr);

Mois_Output_T *SFL_Mois_Output_Ptr(void)
{
   return &SFL_Mois_Output;
}

/*================================================================================================*\
* Function: SFL_Mois_Cal_Update_Init()
*================================================================================================
* Parameters: Mois_Calibration_T*
*
* Return Value: void
*
* Description: In this function Customer specific calibrations of MOIS are updated at init.
*
\*================================================================================================*/
static void SFL_Mois_Cal_Update_Init(Mois_Core_Calibration_T *SFL_Mois_Cal_Ptr)
{
   /* Calibration parameters (configure directly in SW) */
   /*Zone related cals*/
   if (k_gxcp_delay_smc == 1u) // cheetah
   {
      SFL_Mois_Cal_Ptr->k_mois_static_case_length_information_zone  = 1.3f;
      SFL_Mois_Cal_Ptr->k_mois_dynamic_case_length_information_zone = 1.3f;
   }
   else if (k_gxcp_delay_smc == 2u) // avatar
   {
      SFL_Mois_Cal_Ptr->k_mois_static_case_length_information_zone  = 1.71f;
      SFL_Mois_Cal_Ptr->k_mois_dynamic_case_length_information_zone = 1.71f;
   }
   else
   {
      // do nothing
   }

   SFL_Mois_Cal_Ptr->k_mois_static_case_zone_to_vehicle_front_gap_information_zone  = 0.8f;
   SFL_Mois_Cal_Ptr->k_mois_dynamic_case_zone_to_vehicle_front_gap_information_zone = 0.8f;
   SFL_Mois_Cal_Ptr->k_mois_length_warning_zone                                     = 0.8f;
   SFL_Mois_Cal_Ptr->k_mois_static_info_zone_hys                                    = 0.2f;
   SFL_Mois_Cal_Ptr->k_mois_dynamic_info_zone_hys                                   = 0.2f;
   SFL_Mois_Cal_Ptr->k_mois_warn_zone_hys                                           = 0.2f;
   SFL_Mois_Cal_Ptr->k_mois_zone_to_vehicle_front_gap_warning_zone                  = 0.8f;

   /*Speed related cals*/
   SFL_Mois_Cal_Ptr->k_mois_active_ego_speed_max               = 2.78f;
   SFL_Mois_Cal_Ptr->k_mois_active_ego_speed_max_hys           = 0.278f;
   SFL_Mois_Cal_Ptr->k_mois_ego_speed_max                      = 2.78f;
   SFL_Mois_Cal_Ptr->k_mois_ego_speed_max_hys                  = 0.278f;
   SFL_Mois_Cal_Ptr->k_mois_warning_ego_speed_min              = 0.2f;
   SFL_Mois_Cal_Ptr->k_mois_ego_static_or_dynamic_border_speed = 0.03f;
   SFL_Mois_Cal_Ptr->k_mois_static_case_object_speed_min       = 0.0f;
   SFL_Mois_Cal_Ptr->k_mois_static_case_object_speed_max       = 1.67f;
   SFL_Mois_Cal_Ptr->k_mois_dynamic_case_object_speed_max      = 2.78f;

   SFL_Mois_Cal_Ptr->k_mois_f_enable_turning_zone_reduction_factor = 0U;
   SFL_Mois_Cal_Ptr->k_mois_f_check_vru_object                     = 0U;

   /*Cals related to turning alert on for cyclist(length-width estimation issue)*/
   SFL_Mois_Cal_Ptr->k_mois_static_case_widening                   = 0.0f;
   SFL_Mois_Cal_Ptr->k_mois_f_check_obj_mov_dir_for_izone_ext_stat = 1U;
   SFL_Mois_Cal_Ptr->k_mois_lateral_obj_approaching_delay          = 1.1f;
   SFL_Mois_Cal_Ptr->k_mois_lateral_obj_approaching_ttc_min        = -3.3f;

   /*Cals related to holding for lost objects*/
   SFL_Mois_Cal_Ptr->k_mois_object_near_dist_max         = 0.8f;
   SFL_Mois_Cal_Ptr->k_mois_f_debounce_reset_alert_level = 1U;
   SFL_Mois_Cal_Ptr->k_mois_f_debounce_lost_near_objects = 1U;

   SFL_Mois_Cal_Ptr->k_mois_lost_near_object_max_counter_dyn         = 300U;
   SFL_Mois_Cal_Ptr->k_mois_lost_near_object_max_counter_stat        = 300U;
   SFL_Mois_Cal_Ptr->k_mois_lost_near_object_max_counter_level_2     = 300U;
   SFL_Mois_Cal_Ptr->k_mois_f_enable_near_object_lost_max_counter    = 1U;
   SFL_Mois_Cal_Ptr->k_mois_debounce_lost_near_object_host_speed_max = 0.5f;
}

/*================================================================================================*\
* Function: SFL_Mois_Init()
*================================================================================================
* Parameters: Mois_Instance_T*
*
* Return Value: void
*
* Description: This function implements the initialization of Mois Feature.
*
\*================================================================================================*/
void SFL_Mois_Init(void)
{
   Mois_Instance_T *SFL_Mois_Instance_Ptr = &SFL_Mois_Instance;

   if (nullptr != SFL_Mois_Instance_Ptr)
   {
      (void)Mois_Init_Platform(SFL_Mois_Instance_Ptr);

      (void)SFL_Mois_Cal_Update_Init(&SFL_Mois_Instance_Ptr->calibration);
   }
}

/*================================================================================================*\
* Function: SFL_Mois_Main()
*================================================================================================
* Parameters: Mois_Instance_T*, Mois_Input_T, const Fbk_Output_T*, Mois_Output_T *
*
* Return Value: void
*
* Description: This function implements the periodic execution of MOIS Feature.
*
\*================================================================================================*/
void SFL_Mois_Main(const Fbk_Output_T *SFL_Fbk_Output_Ptr, MM_SFLCore_T *p_MM_SFLCore)
{
   Mois_Instance_T *SFL_Mois_Instance_Ptr        = &SFL_Mois_Instance;
   Mois_Input_T *SFL_Mois_Input_Ptr              = &SFL_Mois_Input;
   Mois_Output_T *SFL_Mois_Output_Ptr            = &SFL_Mois_Output;
   volatile HIL_Ipc_Info_T *m2d_hil_ipc_info_ptr = &(Get_IPC_M2D_Buffer()->payload.hil_ipc_info);

   if ((nullptr != SFL_Mois_Instance_Ptr) && (nullptr != SFL_Mois_Input_Ptr) && (nullptr != SFL_Fbk_Output_Ptr) &&
       (nullptr != SFL_Mois_Output_Ptr))
   {
      SFL_Mois_Input_Ptr->f_mois_enable = p_MM_SFLCore->f_mois_enable;

      if (m2d_hil_ipc_info_ptr->hil_mode_enabled == CODED_TRUE)
      {
         SFL_Mois_Input_Ptr->f_mois_enable = FBK_TRUE;
      }

      (void)Mois_Run_Platform(SFL_Mois_Instance_Ptr, SFL_Mois_Input_Ptr, SFL_Fbk_Output_Ptr, SFL_Mois_Output_Ptr);
   }
}

/*================================================================================================*\
* Function: SFL_Mois_Reset_Cust_IPC()
*================================================================================================
* Parameters: Mois_Stream_T*, Mois_Instance_Stream_T,
*
* Return Value: void
*
* Description: This function implements the reseting of the IPC
*
\*================================================================================================*/
void SFL_Mois_Reset_Cust_IPC(Mois_Stream_T *ipc_mois_cust_stream_p, Mois_Instance_Stream_T *ipc_mois_cust_instance_p)
{
   /*Mode Manager Ouput of the feature*/
   ipc_mois_cust_stream_p->mois_cust_mm_output.MOIS_Alert             = FBK_ZERO_UINT;
   ipc_mois_cust_stream_p->mois_cust_mm_output.MOIS_Systemsts         = FBK_ZERO_UINT;
   ipc_mois_cust_stream_p->mois_cust_mm_output.MOIS_OnOff_Setting_FBK = FBK_ZERO_UINT;
   ipc_mois_cust_stream_p->mois_cust_mm_output.MOIS_FailSts           = FBK_ZERO_UINT;
   ipc_mois_cust_stream_p->mois_cust_mm_output.MOIS_Blind             = FBK_ZERO_UINT;

   /*Customer Output of the feature*/
   ipc_mois_cust_stream_p->mois_cust_output.f_mois_enable                   = FBK_ZERO_UINT;
   ipc_mois_cust_stream_p->mois_cust_output.mois_alert_level                = FBK_ZERO_UINT;
   ipc_mois_cust_stream_p->mois_cust_output.mois_number_of_relevant_objects = FBK_ZERO_UINT;
   ipc_mois_cust_stream_p->mois_cust_output.mois_vru_confidence             = FBK_ZERO_UINT;

   for (uint8_t i = 0U; i < MOIS_MAX_NUMBER_OF_RELEVANT_OBJECTS; i++)
   {
      ipc_mois_cust_stream_p->mois_cust_output.mois_relevant_objects[i].vcs_pos_m.x       = FBK_ZERO_F;
      ipc_mois_cust_stream_p->mois_cust_output.mois_relevant_objects[i].vcs_pos_m.y       = FBK_ZERO_F;
      ipc_mois_cust_stream_p->mois_cust_output.mois_relevant_objects[i].speed_mps         = FBK_ZERO_F;
      ipc_mois_cust_stream_p->mois_cust_output.mois_relevant_objects[i].vcs_vel_rel_mps.x = FBK_ZERO_F;
      ipc_mois_cust_stream_p->mois_cust_output.mois_relevant_objects[i].vcs_vel_rel_mps.y = FBK_ZERO_F;
      ipc_mois_cust_stream_p->mois_cust_output.mois_relevant_objects[i].vcs_heading_rad   = FBK_ZERO_F;
      ipc_mois_cust_stream_p->mois_cust_output.mois_relevant_objects[i].length_m          = FBK_ZERO_F;
      ipc_mois_cust_stream_p->mois_cust_output.mois_relevant_objects[i].width_m           = FBK_ZERO_F;
      ipc_mois_cust_stream_p->mois_cust_output.mois_relevant_objects[i].object_distance_m = FBK_ZERO_F;
      ipc_mois_cust_stream_p->mois_cust_output.mois_relevant_objects[i].object_id         = FBK_ZERO_UINT;
      ipc_mois_cust_stream_p->mois_cust_output.mois_relevant_objects[i].status            = FBK_ZERO_UINT;
      ipc_mois_cust_stream_p->mois_cust_output.mois_relevant_objects[i].object_class      = FBK_ZERO_UINT;

      /* Persistent signals of the feature in instance*/
      ipc_mois_cust_instance_p->persistent.mois_relevant_object_id[i] = FBK_ZERO_UINT;

      /* Core Output signals of the feature in instance*/
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].type                                 = FBK_ZERO_UINT;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.area                      = FBK_ZERO_F;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.ttc_lat                   = FBK_ZERO_F;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.ttp_info_zone             = FBK_ZERO_F;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.ttp_warning_zone          = FBK_ZERO_F;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.closest_distance          = FBK_ZERO_F;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.zone_reduction_factor     = FBK_ZERO_F;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.direction                 = FBK_ZERO_UINT;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.object_alert_level        = FBK_ZERO_UINT;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.use_case                  = FBK_ZERO_UINT;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.f_alert_prev_cycle        = FBK_ZERO_UINT;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.f_obj_in_information_zone = FBK_ZERO_UINT;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.f_obj_in_warning_zone     = FBK_ZERO_UINT;

      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.information_zone.size = FBK_ZERO_UINT;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.warning_zone.size     = FBK_ZERO_UINT;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.object_zone.size      = FBK_ZERO_UINT;

      for (uint8_t j = 0U; j < FBK_MAX_SIZE_OF_FOI; j++)
      {
         ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.information_zone.points[j].x = FBK_ZERO_F;
         ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.information_zone.points[j].y = FBK_ZERO_F;
         ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.warning_zone.points[j].x     = FBK_ZERO_F;
         ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.warning_zone.points[j].y     = FBK_ZERO_F;
         ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.object_zone.points[j].x      = FBK_ZERO_F;
         ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.object_zone.points[j].y      = FBK_ZERO_F;
      }
   }

   /*Customer Input of the feature*/
   ipc_mois_cust_stream_p->mois_cust_input.f_mois_enable = FBK_ZERO_UINT;

   /* Persistent signals of the feature in instance*/
   ipc_mois_cust_instance_p->persistent.mois_near_object_lost_counter      = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->persistent.f_was_mois_enabled                 = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->persistent.f_mois_object_near_hold_logic_uc   = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->persistent.f_mois_object_near                 = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->persistent.f_mois_object_near_prev_cycl_index = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->persistent.f_mois_object_near_prev_cycle      = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->persistent.f_mois_near_object_lost            = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->persistent.f_mois_skip_alert_holding          = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->persistent.f_crit_obj_out_of_zone             = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->persistent.f_dynamic_scenario                 = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->persistent.mois_number_of_relevant_objects    = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->persistent.mois_alert_qualifying_counter      = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->persistent.mois_alert_holding_counter         = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->persistent.mois_holding_counter_extension     = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->persistent.mois_alert_prev_cycle              = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->persistent.mois_id_prev_cycle                 = FBK_ZERO_UINT;

   /* Core Output signals of the feature in instance*/
   ipc_mois_cust_instance_p->core_output.mois_alert_level                = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->core_output.mois_id                         = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->core_output.mois_id_prev_cycle              = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->core_output.mois_number_of_relevant_objects = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->core_output.f_mois_enabled                  = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->core_output.f_mois_hold_alert_active        = FBK_ZERO_UINT;

   /* Core Output signals of the feature in instance*/
   ipc_mois_cust_instance_p->core_input.f_mois_enable               = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->core_input.number_of_freespace_objects = FBK_ZERO_UINT;

   /* Calibration signals of the feature in instance*/
   ipc_mois_cust_instance_p->calibration.k_mois_oncoming_speed_threshold                                = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_area_intersection_valid_ratio                           = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_relevant_moving_away_if_near_dropped_min_speed          = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_ego_near_hold_speed_min                                 = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_object_oncoming_rel_speed_max                           = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_ford_dynamic_min_speed_conf_high                        = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_ford_static_min_speed_conf_high                         = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_active_ego_speed_max_hys                                = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_active_ego_speed_max                                    = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_debounce_lost_near_object_host_speed_max                = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_object_area_max                                         = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_dynamic_case_object_speed_max_hys                       = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_dynamic_case_object_speed_max                           = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_static_case_object_speed_max_hys                        = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_static_case_object_speed_max                            = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_static_case_object_speed_min                            = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_ego_static_or_dynamic_border_speed                      = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_ego_speed_max_hys                                       = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_ego_speed_max                                           = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_object_near_dist_max                                    = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_object_direction_check_speed_min                        = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_warning_ego_speed_min_hys                               = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_warning_ego_speed_min                                   = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_lateral_obj_approaching_ttc_min                         = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_lateral_obj_approaching_delay                           = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_warn_zone_hys                                           = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_dynamic_info_zone_hys                                   = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_static_info_zone_hys                                    = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_static_case_widening                                    = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_dynamic_case_lengthening                                = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_zone_to_vehicle_front_gap_warning_zone                  = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_lateral_margin_warning_zone                             = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_length_warning_zone                                     = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_dynamic_case_zone_to_vehicle_front_gap_information_zone = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_static_case_zone_to_vehicle_front_gap_information_zone  = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_lateral_margin_information_zone                         = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_dynamic_case_length_information_zone                    = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_static_case_length_information_zone                     = FBK_ZERO_F;
   ipc_mois_cust_instance_p->calibration.k_mois_lost_near_object_max_counter_level_2                    = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_lost_near_object_max_counter_dyn                        = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_lost_near_object_max_counter_stat                       = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_min_age                                                 = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_f_debounce_reset_alert_level                            = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_holding_counter_extension_max                           = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_alert_holding_cycles                                    = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_alert_qualifying_cycles                                 = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_f_filter_far_static_obj                                 = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_f_enable_oncoming_speed_threshold                       = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_ford_f_bypass_object_state_check                        = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_f_enable_relevant_moving_away_if_near_dropped           = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_f_enable_keep_relevant_if_alert                         = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_f_allow_freespace_obj_for_intersection_area_check       = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_f_enable_including_class_change_from_vru_to_non_vru     = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_disable_holding_for_low_speed                           = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_f_disable_age_filter_on_alert                           = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_f_enable_near_objects_static_case                       = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_f_enable_turning_zone_reduction_factor                  = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_f_reduced_hold_counter_in_case_object_not_lost          = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_f_use_bb_overlap_for_lateral_warning                    = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_f_calulate_freespace_distance                           = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_f_debounce_lost_near_objects                            = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_f_filter_coasted_obj                                    = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_f_filter_stat_clutter                                   = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_f_check_minimal_object_size                             = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_f_check_obj_mov_dir_for_izone_ext_stat                  = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_f_check_use_case                                        = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_f_enable_near_object_lost_max_counter                   = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_f_skip_alert_holding                                    = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_f_check_vru_object                                      = FBK_ZERO_UINT;
   ipc_mois_cust_instance_p->calibration.k_mois_f_mois_enabled                                          = FBK_ZERO_UINT;

   for (uint8_t i = 0; i < MOIS_K_MOIS_ROAD_WHEEL_ANGLE_FACTOR_TABLE_ARRAY_SIZE_DIM0; i++)
   {
      ipc_mois_cust_instance_p->calibration.k_mois_road_wheel_angle_factor_table[i] = FBK_ZERO_F;
      ipc_mois_cust_instance_p->calibration.k_mois_road_wheel_angle_table[i]        = FBK_ZERO_F;
   }

   for (uint8_t j = 0; j < MOIS_K_MOIS_F_ENABLE_INTERSECTION_AREA_CHECK_ARRAY_SIZE_DIM0; j++)
   {
      ipc_mois_cust_instance_p->calibration.k_mois_f_enable_intersection_area_check[j] = FBK_ZERO_UINT;
   }
}

/*================================================================================================*\
* Function: SFL_Mois_Set_Cust_IPC()
*================================================================================================
* Parameters: Mois_Stream_T*, Mois_Instance_Stream_T,
*
* Return Value: void
*
* Description: This function implements the seting of the IPC
*
\*================================================================================================*/
void SFL_Mois_Set_Cust_IPC(Mois_Stream_T *ipc_mois_cust_stream_p, Mois_Instance_Stream_T *ipc_mois_cust_instance_p)
{
   /*Customer Output of the feature*/
   ipc_mois_cust_stream_p->mois_cust_output.f_mois_enable    = (uint8_t)SFL_Mois_Output.f_mois_enable;
   ipc_mois_cust_stream_p->mois_cust_output.mois_alert_level = (uint8_t)SFL_Mois_Output.mois_alert_level;
   ipc_mois_cust_stream_p->mois_cust_output.mois_number_of_relevant_objects =
      (uint8_t)SFL_Mois_Output.mois_number_of_relevant_objects;
   ipc_mois_cust_stream_p->mois_cust_output.mois_vru_confidence = (uint8_t)SFL_Mois_Output.mois_vru_confidence;

   for (uint8_t i = 0U; i < MOIS_MAX_NUMBER_OF_RELEVANT_OBJECTS; i++)
   {
      ipc_mois_cust_stream_p->mois_cust_output.mois_relevant_objects[i].vcs_pos_m.x =
         (float32_T)SFL_Mois_Output.mois_relevant_objects[i].vcs_pos_m.x;
      ipc_mois_cust_stream_p->mois_cust_output.mois_relevant_objects[i].vcs_pos_m.y =
         (float32_T)SFL_Mois_Output.mois_relevant_objects[i].vcs_pos_m.y;
      ipc_mois_cust_stream_p->mois_cust_output.mois_relevant_objects[i].speed_mps =
         (float32_T)SFL_Mois_Output.mois_relevant_objects[i].speed_mps;
      ipc_mois_cust_stream_p->mois_cust_output.mois_relevant_objects[i].vcs_vel_rel_mps.x =
         (float32_T)SFL_Mois_Output.mois_relevant_objects[i].vcs_vel_rel_mps.x;
      ipc_mois_cust_stream_p->mois_cust_output.mois_relevant_objects[i].vcs_vel_rel_mps.y =
         (float32_T)SFL_Mois_Output.mois_relevant_objects[i].vcs_vel_rel_mps.y;
      ipc_mois_cust_stream_p->mois_cust_output.mois_relevant_objects[i].vcs_heading_rad =
         (float32_T)SFL_Mois_Output.mois_relevant_objects[i].vcs_heading_rad;
      ipc_mois_cust_stream_p->mois_cust_output.mois_relevant_objects[i].length_m =
         (float32_T)SFL_Mois_Output.mois_relevant_objects[i].length_m;
      ipc_mois_cust_stream_p->mois_cust_output.mois_relevant_objects[i].width_m =
         (float32_T)SFL_Mois_Output.mois_relevant_objects[i].width_m;
      ipc_mois_cust_stream_p->mois_cust_output.mois_relevant_objects[i].object_distance_m =
         (float32_T)SFL_Mois_Output.mois_relevant_objects[i].object_distance_m;
      ipc_mois_cust_stream_p->mois_cust_output.mois_relevant_objects[i].object_id =
         (uint8_t)SFL_Mois_Output.mois_relevant_objects[i].object_id;
      ipc_mois_cust_stream_p->mois_cust_output.mois_relevant_objects[i].status =
         (uint8_t)SFL_Mois_Output.mois_relevant_objects[i].status;
      ipc_mois_cust_stream_p->mois_cust_output.mois_relevant_objects[i].object_class =
         (uint8_t)SFL_Mois_Output.mois_relevant_objects[i].object_class;

      /* Persistent signals of the feature in instance*/
      ipc_mois_cust_instance_p->persistent.mois_relevant_object_id[i] =
         (uint8_t)SFL_Mois_Instance.persistent.mois_relevant_object_id[i];

      /* Core Output signals of the feature in instance*/
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].type =
         (uint8_t)SFL_Mois_Instance.core_output.mois_relevant_objects[i].type;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.area =
         (float32_T)SFL_Mois_Instance.core_output.mois_relevant_objects[i].attributes.area;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.ttc_lat =
         (float32_T)SFL_Mois_Instance.core_output.mois_relevant_objects[i].attributes.ttc_lat;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.ttp_info_zone =
         (float32_T)SFL_Mois_Instance.core_output.mois_relevant_objects[i].attributes.ttp_info_zone;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.ttp_warning_zone =
         (float32_T)SFL_Mois_Instance.core_output.mois_relevant_objects[i].attributes.ttp_warning_zone;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.closest_distance =
         (float32_T)SFL_Mois_Instance.core_output.mois_relevant_objects[i].attributes.ttp_warning_zone;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.zone_reduction_factor =
         (float32_T)SFL_Mois_Instance.core_output.mois_relevant_objects[i].attributes.ttp_warning_zone;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.direction =
         (uint8_t)SFL_Mois_Instance.core_output.mois_relevant_objects[i].attributes.direction;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.object_alert_level =
         (uint8_t)SFL_Mois_Instance.core_output.mois_relevant_objects[i].attributes.object_alert_level;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.use_case =
         (uint8_t)SFL_Mois_Instance.core_output.mois_relevant_objects[i].attributes.use_case;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.f_alert_prev_cycle =
         (uint8_t)SFL_Mois_Instance.core_output.mois_relevant_objects[i].attributes.f_alert_prev_cycle;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.f_obj_in_information_zone =
         (uint8_t)SFL_Mois_Instance.core_output.mois_relevant_objects[i].attributes.f_obj_in_information_zone;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.f_obj_in_warning_zone =
         (uint8_t)SFL_Mois_Instance.core_output.mois_relevant_objects[i].attributes.f_obj_in_warning_zone;

      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.information_zone.size =
         (uint8_t)SFL_Mois_Instance.core_output.mois_relevant_objects[i].attributes.information_zone.size;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.warning_zone.size =
         (uint8_t)SFL_Mois_Instance.core_output.mois_relevant_objects[i].attributes.information_zone.size;
      ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.object_zone.size =
         (uint8_t)SFL_Mois_Instance.core_output.mois_relevant_objects[i].attributes.information_zone.size;

      for (uint8_t j = 0U; j < FBK_MAX_SIZE_OF_FOI; j++)
      {
         ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.information_zone.points[j].x =
            (float32_T)SFL_Mois_Instance.core_output.mois_relevant_objects[i].attributes.information_zone.points[j].x;
         ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.information_zone.points[j].y =
            (float32_T)SFL_Mois_Instance.core_output.mois_relevant_objects[i].attributes.information_zone.points[j].y;
         ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.warning_zone.points[j].x =
            (float32_T)SFL_Mois_Instance.core_output.mois_relevant_objects[i].attributes.warning_zone.points[j].x;
         ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.warning_zone.points[j].y =
            (float32_T)SFL_Mois_Instance.core_output.mois_relevant_objects[i].attributes.warning_zone.points[j].y;
         ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.object_zone.points[j].x =
            (float32_T)SFL_Mois_Instance.core_output.mois_relevant_objects[i].attributes.object_zone.points[j].x;
         ipc_mois_cust_instance_p->core_output.mois_relevant_objects[i].attributes.object_zone.points[j].y =
            (float32_T)SFL_Mois_Instance.core_output.mois_relevant_objects[i].attributes.object_zone.points[j].y;
      }
   }

   /*Customer Input of the feature*/
   ipc_mois_cust_stream_p->mois_cust_input.f_mois_enable = (uint8_t)SFL_Mois_Input.f_mois_enable;

   /* Persistent signals of the feature in instance*/
   ipc_mois_cust_instance_p->persistent.mois_near_object_lost_counter =
      (uint8_t)SFL_Mois_Instance.persistent.mois_near_object_lost_counter;
   ipc_mois_cust_instance_p->persistent.f_was_mois_enabled = (uint8_t)SFL_Mois_Instance.persistent.f_was_mois_enabled;
   ipc_mois_cust_instance_p->persistent.f_mois_object_near_hold_logic_uc =
      (uint8_t)SFL_Mois_Instance.persistent.f_mois_object_near_hold_logic_uc;
   ipc_mois_cust_instance_p->persistent.f_mois_object_near = (uint8_t)SFL_Mois_Instance.persistent.f_mois_object_near;
   ipc_mois_cust_instance_p->persistent.f_mois_object_near_prev_cycl_index =
      (uint8_t)SFL_Mois_Instance.persistent.f_mois_object_near_prev_cycl_index;
   ipc_mois_cust_instance_p->persistent.f_mois_object_near_prev_cycle =
      (uint8_t)SFL_Mois_Instance.persistent.f_mois_object_near_prev_cycle;
   ipc_mois_cust_instance_p->persistent.f_mois_near_object_lost = (uint8_t)SFL_Mois_Instance.persistent.f_mois_near_object_lost;
   ipc_mois_cust_instance_p->persistent.f_mois_skip_alert_holding =
      (uint8_t)SFL_Mois_Instance.persistent.f_mois_skip_alert_holding;
   ipc_mois_cust_instance_p->persistent.f_crit_obj_out_of_zone = (uint8_t)SFL_Mois_Instance.persistent.f_crit_obj_out_of_zone;
   ipc_mois_cust_instance_p->persistent.f_dynamic_scenario     = (uint8_t)SFL_Mois_Instance.persistent.f_dynamic_scenario;
   ipc_mois_cust_instance_p->persistent.mois_number_of_relevant_objects =
      (uint8_t)SFL_Mois_Instance.persistent.mois_number_of_relevant_objects;
   ipc_mois_cust_instance_p->persistent.mois_alert_qualifying_counter =
      (uint8_t)SFL_Mois_Instance.persistent.mois_alert_qualifying_counter;
   ipc_mois_cust_instance_p->persistent.mois_alert_holding_counter =
      (uint8_t)SFL_Mois_Instance.persistent.mois_alert_holding_counter;
   ipc_mois_cust_instance_p->persistent.mois_holding_counter_extension =
      (uint8_t)SFL_Mois_Instance.persistent.mois_holding_counter_extension;
   ipc_mois_cust_instance_p->persistent.mois_alert_prev_cycle = (uint8_t)SFL_Mois_Instance.persistent.mois_alert_prev_cycle;
   ipc_mois_cust_instance_p->persistent.mois_id_prev_cycle    = (uint8_t)SFL_Mois_Instance.persistent.mois_id_prev_cycle;

   /* Core Output signals of the feature in instance*/
   ipc_mois_cust_instance_p->core_output.mois_alert_level   = (uint8_t)SFL_Mois_Instance.core_output.mois_alert_level;
   ipc_mois_cust_instance_p->core_output.mois_id            = (uint8_t)SFL_Mois_Instance.core_output.mois_id;
   ipc_mois_cust_instance_p->core_output.mois_id_prev_cycle = (uint8_t)SFL_Mois_Instance.core_output.mois_id_prev_cycle;
   ipc_mois_cust_instance_p->core_output.mois_number_of_relevant_objects =
      (uint8_t)SFL_Mois_Instance.core_output.mois_number_of_relevant_objects;
   ipc_mois_cust_instance_p->core_output.f_mois_enabled = (uint8_t)SFL_Mois_Instance.core_output.f_mois_enabled;
   ipc_mois_cust_instance_p->core_output.f_mois_hold_alert_active =
      (uint8_t)SFL_Mois_Instance.core_output.f_mois_hold_alert_active;

   /* Core Output signals of the feature in instance*/
   ipc_mois_cust_instance_p->core_input.f_mois_enable = (uint8_t)SFL_Mois_Instance.core_input.f_mois_enable;
   ipc_mois_cust_instance_p->core_input.number_of_freespace_objects =
      (uint8_t)SFL_Mois_Instance.core_input.number_of_freespace_objects;

   /* Calibration signals of the feature in instance*/
   ipc_mois_cust_instance_p->calibration.k_mois_oncoming_speed_threshold =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_oncoming_speed_threshold;
   ipc_mois_cust_instance_p->calibration.k_mois_area_intersection_valid_ratio =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_area_intersection_valid_ratio;
   ipc_mois_cust_instance_p->calibration.k_mois_relevant_moving_away_if_near_dropped_min_speed =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_relevant_moving_away_if_near_dropped_min_speed;
   ipc_mois_cust_instance_p->calibration.k_mois_ego_near_hold_speed_min =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_ego_near_hold_speed_min;
   ipc_mois_cust_instance_p->calibration.k_mois_object_oncoming_rel_speed_max =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_object_oncoming_rel_speed_max;
   ipc_mois_cust_instance_p->calibration.k_mois_ford_dynamic_min_speed_conf_high =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_ford_dynamic_min_speed_conf_high;
   ipc_mois_cust_instance_p->calibration.k_mois_ford_static_min_speed_conf_high =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_ford_static_min_speed_conf_high;
   ipc_mois_cust_instance_p->calibration.k_mois_active_ego_speed_max_hys =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_active_ego_speed_max_hys;
   ipc_mois_cust_instance_p->calibration.k_mois_active_ego_speed_max =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_active_ego_speed_max;
   ipc_mois_cust_instance_p->calibration.k_mois_debounce_lost_near_object_host_speed_max =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_debounce_lost_near_object_host_speed_max;
   ipc_mois_cust_instance_p->calibration.k_mois_object_area_max = (float32_T)SFL_Mois_Instance.calibration.k_mois_object_area_max;
   ipc_mois_cust_instance_p->calibration.k_mois_dynamic_case_object_speed_max_hys =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_dynamic_case_object_speed_max_hys;
   ipc_mois_cust_instance_p->calibration.k_mois_dynamic_case_object_speed_max =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_dynamic_case_object_speed_max;
   ipc_mois_cust_instance_p->calibration.k_mois_static_case_object_speed_max_hys =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_static_case_object_speed_max_hys;
   ipc_mois_cust_instance_p->calibration.k_mois_static_case_object_speed_max =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_static_case_object_speed_max;
   ipc_mois_cust_instance_p->calibration.k_mois_static_case_object_speed_min =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_static_case_object_speed_min;
   ipc_mois_cust_instance_p->calibration.k_mois_ego_static_or_dynamic_border_speed =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_ego_static_or_dynamic_border_speed;
   ipc_mois_cust_instance_p->calibration.k_mois_ego_speed_max_hys =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_ego_speed_max_hys;
   ipc_mois_cust_instance_p->calibration.k_mois_ego_speed_max = (float32_T)SFL_Mois_Instance.calibration.k_mois_ego_speed_max;
   ipc_mois_cust_instance_p->calibration.k_mois_object_near_dist_max =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_object_near_dist_max;
   ipc_mois_cust_instance_p->calibration.k_mois_object_direction_check_speed_min =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_object_direction_check_speed_min;
   ipc_mois_cust_instance_p->calibration.k_mois_warning_ego_speed_min_hys =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_warning_ego_speed_min_hys;
   ipc_mois_cust_instance_p->calibration.k_mois_warning_ego_speed_min =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_warning_ego_speed_min;
   ipc_mois_cust_instance_p->calibration.k_mois_lateral_obj_approaching_ttc_min =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_lateral_obj_approaching_ttc_min;
   ipc_mois_cust_instance_p->calibration.k_mois_lateral_obj_approaching_delay =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_lateral_obj_approaching_delay;
   ipc_mois_cust_instance_p->calibration.k_mois_warn_zone_hys = (float32_T)SFL_Mois_Instance.calibration.k_mois_warn_zone_hys;
   ipc_mois_cust_instance_p->calibration.k_mois_dynamic_info_zone_hys =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_dynamic_info_zone_hys;
   ipc_mois_cust_instance_p->calibration.k_mois_static_info_zone_hys =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_static_info_zone_hys;
   ipc_mois_cust_instance_p->calibration.k_mois_static_case_widening =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_static_case_widening;
   ipc_mois_cust_instance_p->calibration.k_mois_dynamic_case_lengthening =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_dynamic_case_lengthening;
   ipc_mois_cust_instance_p->calibration.k_mois_zone_to_vehicle_front_gap_warning_zone =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_zone_to_vehicle_front_gap_warning_zone;
   ipc_mois_cust_instance_p->calibration.k_mois_lateral_margin_warning_zone =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_lateral_margin_warning_zone;
   ipc_mois_cust_instance_p->calibration.k_mois_length_warning_zone =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_length_warning_zone;
   ipc_mois_cust_instance_p->calibration.k_mois_dynamic_case_zone_to_vehicle_front_gap_information_zone =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_dynamic_case_zone_to_vehicle_front_gap_information_zone;
   ipc_mois_cust_instance_p->calibration.k_mois_static_case_zone_to_vehicle_front_gap_information_zone =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_static_case_zone_to_vehicle_front_gap_information_zone;
   ipc_mois_cust_instance_p->calibration.k_mois_lateral_margin_information_zone =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_lateral_margin_information_zone;
   ipc_mois_cust_instance_p->calibration.k_mois_dynamic_case_length_information_zone =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_dynamic_case_length_information_zone;
   ipc_mois_cust_instance_p->calibration.k_mois_static_case_length_information_zone =
      (float32_T)SFL_Mois_Instance.calibration.k_mois_static_case_length_information_zone;
   ipc_mois_cust_instance_p->calibration.k_mois_lost_near_object_max_counter_level_2 =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_lost_near_object_max_counter_level_2;
   ipc_mois_cust_instance_p->calibration.k_mois_lost_near_object_max_counter_dyn =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_lost_near_object_max_counter_dyn;
   ipc_mois_cust_instance_p->calibration.k_mois_lost_near_object_max_counter_stat =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_lost_near_object_max_counter_stat;
   ipc_mois_cust_instance_p->calibration.k_mois_min_age = (uint8_t)SFL_Mois_Instance.calibration.k_mois_min_age;
   ipc_mois_cust_instance_p->calibration.k_mois_f_debounce_reset_alert_level =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_f_debounce_reset_alert_level;
   ipc_mois_cust_instance_p->calibration.k_mois_holding_counter_extension_max =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_holding_counter_extension_max;
   ipc_mois_cust_instance_p->calibration.k_mois_alert_holding_cycles =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_alert_holding_cycles;
   ipc_mois_cust_instance_p->calibration.k_mois_alert_qualifying_cycles =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_alert_qualifying_cycles;
   ipc_mois_cust_instance_p->calibration.k_mois_f_filter_far_static_obj =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_f_filter_far_static_obj;
   ipc_mois_cust_instance_p->calibration.k_mois_f_enable_oncoming_speed_threshold =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_f_enable_oncoming_speed_threshold;
   ipc_mois_cust_instance_p->calibration.k_mois_ford_f_bypass_object_state_check =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_ford_f_bypass_object_state_check;
   ipc_mois_cust_instance_p->calibration.k_mois_f_enable_relevant_moving_away_if_near_dropped =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_f_enable_relevant_moving_away_if_near_dropped;
   ipc_mois_cust_instance_p->calibration.k_mois_f_enable_keep_relevant_if_alert =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_f_enable_keep_relevant_if_alert;
   ipc_mois_cust_instance_p->calibration.k_mois_f_allow_freespace_obj_for_intersection_area_check =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_f_allow_freespace_obj_for_intersection_area_check;
   ipc_mois_cust_instance_p->calibration.k_mois_f_enable_including_class_change_from_vru_to_non_vru =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_f_enable_including_class_change_from_vru_to_non_vru;
   ipc_mois_cust_instance_p->calibration.k_mois_disable_holding_for_low_speed =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_disable_holding_for_low_speed;
   ipc_mois_cust_instance_p->calibration.k_mois_f_disable_age_filter_on_alert =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_f_disable_age_filter_on_alert;
   ipc_mois_cust_instance_p->calibration.k_mois_f_enable_near_objects_static_case =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_f_enable_near_objects_static_case;
   ipc_mois_cust_instance_p->calibration.k_mois_f_enable_turning_zone_reduction_factor =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_f_enable_turning_zone_reduction_factor;
   ipc_mois_cust_instance_p->calibration.k_mois_f_reduced_hold_counter_in_case_object_not_lost =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_f_reduced_hold_counter_in_case_object_not_lost;
   ipc_mois_cust_instance_p->calibration.k_mois_f_use_bb_overlap_for_lateral_warning =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_f_use_bb_overlap_for_lateral_warning;
   ipc_mois_cust_instance_p->calibration.k_mois_f_calulate_freespace_distance =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_f_calulate_freespace_distance;
   ipc_mois_cust_instance_p->calibration.k_mois_f_debounce_lost_near_objects =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_f_debounce_lost_near_objects;
   ipc_mois_cust_instance_p->calibration.k_mois_f_filter_coasted_obj =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_f_filter_coasted_obj;
   ipc_mois_cust_instance_p->calibration.k_mois_f_filter_stat_clutter =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_f_filter_stat_clutter;
   ipc_mois_cust_instance_p->calibration.k_mois_f_check_minimal_object_size =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_f_check_minimal_object_size;
   ipc_mois_cust_instance_p->calibration.k_mois_f_check_obj_mov_dir_for_izone_ext_stat =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_f_check_obj_mov_dir_for_izone_ext_stat;
   ipc_mois_cust_instance_p->calibration.k_mois_f_check_use_case = (uint8_t)SFL_Mois_Instance.calibration.k_mois_f_check_use_case;
   ipc_mois_cust_instance_p->calibration.k_mois_f_enable_near_object_lost_max_counter =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_f_enable_near_object_lost_max_counter;
   ipc_mois_cust_instance_p->calibration.k_mois_f_skip_alert_holding =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_f_skip_alert_holding;
   ipc_mois_cust_instance_p->calibration.k_mois_f_check_vru_object =
      (uint8_t)SFL_Mois_Instance.calibration.k_mois_f_check_vru_object;
   ipc_mois_cust_instance_p->calibration.k_mois_f_mois_enabled = (uint8_t)SFL_Mois_Instance.calibration.k_mois_f_mois_enabled;

   for (uint8_t k = 0; k < MOIS_K_MOIS_ROAD_WHEEL_ANGLE_FACTOR_TABLE_ARRAY_SIZE_DIM0; k++)
   {
      ipc_mois_cust_instance_p->calibration.k_mois_road_wheel_angle_table[k] =
         (float32_T)SFL_Mois_Instance.calibration.k_mois_road_wheel_angle_table[k];
      ipc_mois_cust_instance_p->calibration.k_mois_road_wheel_angle_factor_table[k] =
         (float32_T)SFL_Mois_Instance.calibration.k_mois_road_wheel_angle_factor_table[k];
   }

   for (uint8_t l = 0; l < MOIS_K_MOIS_F_ENABLE_INTERSECTION_AREA_CHECK_ARRAY_SIZE_DIM0; l++)
   {
      ipc_mois_cust_instance_p->calibration.k_mois_f_enable_intersection_area_check[l] =
         (uint8_t)SFL_Mois_Instance.calibration.k_mois_f_enable_intersection_area_check[l];
   }
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
* 18/02/2026 Hari Kailash M M           MOIS Wrapper
\*================================================================================================*/
