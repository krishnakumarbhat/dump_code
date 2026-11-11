/**************************************************************************************************\
* File: OLP_Wrapper.cpp
***************************************************************************************************
* Copyright 2024 Aptiv, Inc., All Rights Reserved.
* Aptiv Confidential
*-------------------------------------------------------------------------------------------------
* Created on: Feb 11, 2026
* Author: Hari Kailash M M (3dm38i)
*-------------------------------------------------------------------------------------------------
*
* Description:
* Embedded Adapter for OLP features for AL SRR8 customer.
*
\**************************************************************************************************/

/**************************************************************************************************\
* Standard Header Includes
\**************************************************************************************************/
#include <string.h>

/**************************************************************************************************\
* Project Header Includes
\**************************************************************************************************/
#include "OLP_wrapper.h"
#include "T360_Types.h"
#include "emb_tracker_wrapper.h"
#include "ipc_data.h"
#include "ipc_dsp.h"
#include "olp_calibration.h"
#include "olp_core_types.h"
#include "olp_iface.h"

/*===========================================================================*
 * Using Namespaces
 *===========================================================================*/

/*===========================================================================*
 * Static Variable Definitions
 *===========================================================================*/
#if defined(OLP_WRAPPER_USED_MEM_POOL)
static Olp_Data_T *Olp_Data_GPtr = nullptr;
#else
static Olp_Data_T Olp_Data;
static Olp_Data_T *Olp_Data_GPtr             = &Olp_Data;
static Object_List_Stream_T *object_list_log = nullptr;
#endif

/*===========================================================================*\
 * Function: OLP_Update_Customer_Cals
 *===========================================================================
 * Return Value:
 *  - Null
 *
 * Parameters:
 *  - pointer to cust cal structure(Olp_Calibration_T*)
 *
 * External References:
 *  - none
 *
 * Description:
 *    calibrations to OLP can be changed from project side if default cal is not needed
 *
\*===========================================================================*/
void OLP_Update_Customer_Cals(Olp_Calibration_T *Olp_Cals_Cust_ptr)
{
   Olp_Cals_Cust_ptr->k_vp_snail_min_host_speed                     = 0.1f;
   Olp_Cals_Cust_ptr->k_vp_snail_min_elapsed_time_s                 = 0.01f;
   Olp_Cals_Cust_ptr->k_vp_snail_max_elapsed_time_s                 = 0.1f;
   Olp_Cals_Cust_ptr->k_vp_snail_point_dist_separation              = 5.0f;
   Olp_Cals_Cust_ptr->k_vp_snail_point_heading_separation           = 0.314159265358979f;
   Olp_Cals_Cust_ptr->k_vp_host_curvature_min_speed_lowpass         = 0.1f;
   Olp_Cals_Cust_ptr->k_vp_host_curvature_distance_constant_fast    = 0.5f;
   Olp_Cals_Cust_ptr->k_vp_host_curvature_distance_constant_slow    = 3.0f;
   Olp_Cals_Cust_ptr->k_vp_host_curvature_max_delta                 = 0.0001f;
   Olp_Cals_Cust_ptr->k_ad_min_ego_speed_for_convert_to_curvi       = 0.2f;
   Olp_Cals_Cust_ptr->k_vp_snail_trail_max_dist2                    = 400.0f;
   Olp_Cals_Cust_ptr->k_vp_snail_trail_max_dist2_oldest_snail_point = 9.0f;
   Olp_Cals_Cust_ptr->k_vp_min_speed_snail_trail_heading_rate       = 3.0f;
   Olp_Cals_Cust_ptr->k_vp_host_curvature_limit_delta               = 0u;
   Olp_Cals_Cust_ptr->k_vp_enable_snail_trail                       = 1u;
}

/*===========================================================================*\
 * Function: OLP_Update_Vehicle_Data
 *===========================================================================
 * Return Value:
 *  - Null
 *
 * Parameters:
 *  - pointer to olp data structure(Olp_Data_T*)
 *
 * External References:
 *  - none
 *
 * Description:
 *    update the olp structure with vehicle data
 *
\*===========================================================================*/
void OLP_Update_Vehicle_Data(Olp_Data_T &olp_data_ref)
{
   volatile M2D_One_Time_Msg_T *p_ipc_m2d_one_time = Get_IPC_M2D_One_Time_Buffer();
   D2M_Msg_T *p_ipc_d2m                            = (D2M_Msg_T *)Get_SP_Post_Proc_IPC_D2M_Msg_Buffer();

   if ((p_ipc_d2m != nullptr) && (p_ipc_m2d_one_time != nullptr))
   {
      olp_data_ref.veh_info_data.comp_yaw_rate_filtered = p_ipc_d2m->payload.vehicle_info_stream.filtered_yaw_rate_rad;
      olp_data_ref.veh_info_data.k_dist_rear_axle_to_vcs =
         p_ipc_m2d_one_time->calib_data.vehicle_calib_data.k_distance_front_bumper_to_rear_axle;
      olp_data_ref.veh_info_data.filt_veh_speed_over_ground = p_ipc_d2m->payload.vehicle_info_stream.speed;
      olp_data_ref.veh_info_data.vcs_sideslip               = p_ipc_d2m->payload.vehicle_info_stream.vcs_sideslip;
      olp_data_ref.veh_info_data.sideslip_rear_axle =
         0.0f; /* Not avaialble in VSE output. To be mapped when new VSE is integrated */
      olp_data_ref.veh_info_data.vcs_long_velocity = p_ipc_d2m->payload.vehicle_info_stream.vcs_speed;
      olp_data_ref.veh_info_data.vcs_lat_velocity =
         0.0f; /* Not avaialble in VSE output. To be mapped when new VSE is integrated */
   }
}

/*===========================================================================*\
 * Function: getAge
 *===========================================================================
 * Return Value:
 *  - uint8_t
 *
 * Parameters:
 *  - start time of the cluster created
 *
 * External References:
 *  - none
 *
 * Description:
 *    returns the age of the object
 *
\*===========================================================================*/
uint8_t getAge(float32_t time_since_created)
{
   int32_t NO_OF_CYCLES_PER_SEC = 20;
   float32_t age                = (time_since_created * NO_OF_CYCLES_PER_SEC);
   age                          = ((age > 255.0F) ? 255.0F : age);

   return (uint8_t)age;
}

/*===========================================================================*\
 * Function: F360_Map_Object_Status
 *===========================================================================
 * Return Value:
 *  - Olp_Obj_Status_T
 *
 * Parameters:
 *  - status of the tracker object
 *
 * External References:
 *  - none
 *
 * Description:
 *    returns the object status in olp map
 *
\*===========================================================================*/
Olp_Obj_Status_T F360_Map_Object_Status(uint8_t Status)
{
   Olp_Obj_Status_T OLP_Status;
   switch (Status)
   {
      case (uint8_t)F360_OBJ_STATUS_INVALID:
         OLP_Status = OLP_OBJ_STATUS_INVALID;
         break;

      case (uint8_t)F360_OBJ_STATUS_NEW:
         OLP_Status = OLP_OBJ_STATUS_NEW;
         break;

      case (uint8_t)F360_OBJ_STATUS_NEW_COASTED:
      case (uint8_t)F360_OBJ_STATUS_COASTED:
         OLP_Status = OLP_OBJ_STATUS_COASTED;
         break;

      case (uint8_t)F360_OBJ_STATUS_UPDATED:
      case (uint8_t)F360_OBJ_STATUS_NEW_UPDATED:
         OLP_Status = OLP_OBJ_STATUS_MATURE;
         break;

      default:
         OLP_Status = OLP_OBJ_STATUS_INVALID;
         break;
   }
   return OLP_Status;
}

/*===========================================================================*\
 * Function: F360_Map_Object_Class
 *===========================================================================
 * Return Value:
 *  - Olp_Obj_Class_T
 *
 * Parameters:
 *  - class of the tracker object
 *
 * External References:
 *  - none
 *
 * Description:
 *    returns the object class in olp map
 *
\*===========================================================================*/
Olp_Obj_Class_T F360_Map_Object_Class(uint8_t Class)
{
   Olp_Obj_Class_T OLP_Object_Class;
   switch (Class)
   {
      case (uint8_t)F360_OBJECT_CLASS_CAR:
         OLP_Object_Class = OLP_OBJ_CLASS_CAR;
         break;

      case (uint8_t)F360_OBJECT_CLASS_MOTORCYCLE:
      case (uint8_t)F360_OBJECT_CLASS_BICYCLE:
         OLP_Object_Class = OLP_OBJ_CLASS_2WHEEL;
         break;

      case (uint8_t)F360_OBJECT_CLASS_PEDESTRIAN:
         OLP_Object_Class = OLP_OBJ_CLASS_PEDESTRIAN;
         break;

      case (uint8_t)F360_OBJECT_CLASS_TRUCK:
         OLP_Object_Class = OLP_OBJ_CLASS_TRUCK;
         break;

      default:
         OLP_Object_Class = OLP_OBJ_CLASS_UNKNOWN;
         break;
   }
   return OLP_Object_Class;
}

/*===========================================================================*\
 * Function: OLP_Update_Object_Data
 *===========================================================================
 * Return Value:
 *  - void
 *
 * Parameters:
 *  - F360 object IPC output and OLP data
 *
 * External References:
 *  - none
 *
 * Description:
 *    update the OLP structure with object data
 *
\*===========================================================================*/
void OLP_Update_Object_Data(Object_List_Stream_T &f360_Obj, Olp_Data_T &olp_data_ref)
{
   uint8_t no_of_objects = 0u;

   memset(&olp_data_ref, 0, sizeof(Olp_Data_T));

#ifndef UNIT_TEST
   for (uint32_t i = 0u; i < OLP_NUMBER_OF_OBJECTS; i++)
   {
#endif
#ifdef UNIT_TEST
      int32_t i = 0;
#endif
      if ((0u != f360_Obj.object[i].reducedID))
      {
         olp_data_ref.olp_inout_obj_data[no_of_objects].id        = (uint8_t)f360_Obj.object[i].reducedID;
         olp_data_ref.olp_inout_obj_data[no_of_objects].unique_id = f360_Obj.object[i].unique_id;
         olp_data_ref.olp_inout_obj_data[no_of_objects].index     = no_of_objects;
         /*  map object status from f360 enum to olp enum in F360_Map_Object_Status*/
         olp_data_ref.olp_inout_obj_data[no_of_objects].status = F360_Map_Object_Status(f360_Obj.object[i].status);
         /* If age is not available from f360 then it can be calculated from time using getAge function*/
         olp_data_ref.olp_inout_obj_data[no_of_objects].age       = getAge(f360_Obj.object[i].time_since_initialization);
         olp_data_ref.olp_inout_obj_data[no_of_objects].stage_age = getAge(f360_Obj.object[i].time_since_stage_start);
         olp_data_ref.olp_inout_obj_data[no_of_objects].existence_probability = f360_Obj.object[i].existence_probability;
         olp_data_ref.olp_inout_obj_data[no_of_objects].speed                 = f360_Obj.object[i].speed;
         olp_data_ref.olp_inout_obj_data[no_of_objects].vcs_pos     = {f360_Obj.object[i].xposn, f360_Obj.object[i].yposn};
         olp_data_ref.olp_inout_obj_data[no_of_objects].vcs_vel     = {f360_Obj.object[i].xvel, f360_Obj.object[i].yvel};
         olp_data_ref.olp_inout_obj_data[no_of_objects].vcs_vel_rel = {
            f360_Obj.object[i].xvel - olp_data_ref.veh_info_data.vcs_long_velocity,
            f360_Obj.object[i].yvel - olp_data_ref.veh_info_data.vcs_lat_velocity};
         olp_data_ref.olp_inout_obj_data[no_of_objects].vcs_accel   = {f360_Obj.object[i].xaccel, f360_Obj.object[i].yaccel};
         olp_data_ref.olp_inout_obj_data[no_of_objects].vcs_heading = f360_Obj.object[i].heading;
         olp_data_ref.olp_inout_obj_data[no_of_objects].length      = f360_Obj.object[i].length;
         olp_data_ref.olp_inout_obj_data[no_of_objects].width       = f360_Obj.object[i].width;
         olp_data_ref.olp_inout_obj_data[no_of_objects].curvature   = f360_Obj.object[i].curvature;
         /* map object class from f360 enum to olp enum in F360_Map_Object_Status*/
         olp_data_ref.olp_inout_obj_data[no_of_objects].obj_class = F360_Map_Object_Class(f360_Obj.object[i].object_class);
         olp_data_ref.olp_inout_obj_data[no_of_objects].class_prob_pedestrian =
            static_cast<float32_t>(f360_Obj.object[i].probability_pedestrian) / 100.0f;
         olp_data_ref.olp_inout_obj_data[no_of_objects].class_prob_2wheel =
            static_cast<float32_t>(f360_Obj.object[i].probability_motorcycle + f360_Obj.object[i].probability_bicycle) / 100.0f;
         olp_data_ref.olp_inout_obj_data[no_of_objects].class_prob_car =
            static_cast<float32_t>(f360_Obj.object[i].probability_car) / 100.0f;
         olp_data_ref.olp_inout_obj_data[no_of_objects].class_prob_truck =
            static_cast<float32_t>(f360_Obj.object[i].probability_truck) / 100.0f;
         olp_data_ref.olp_inout_obj_data[no_of_objects].f_moveable = f360_Obj.object[i].f_moveable;

         /* Following signals are used in atleaseone of the feature function. So populate the acceptable value if not available
          * from F360*/
         olp_data_ref.olp_inout_obj_data[no_of_objects].f_is_in_fl_sensor_fov = 1;
         olp_data_ref.olp_inout_obj_data[no_of_objects].f_is_in_fr_sensor_fov = 1;
         olp_data_ref.olp_inout_obj_data[no_of_objects].f_is_in_rl_sensor_fov = 1;
         olp_data_ref.olp_inout_obj_data[no_of_objects].f_is_in_rr_sensor_fov = 1;

         /*  Following signals are not used in feature function. So zero can be populated if not available from F360*/
         olp_data_ref.olp_inout_obj_data[no_of_objects].heading_rate          = 0.0f;
         olp_data_ref.olp_inout_obj_data[no_of_objects].f_stationary_clutter  = 0u;
         olp_data_ref.olp_inout_obj_data[no_of_objects].f_is_fl_origin_sensor = 0u;
         olp_data_ref.olp_inout_obj_data[no_of_objects].f_is_fr_origin_sensor = 0u;
         olp_data_ref.olp_inout_obj_data[no_of_objects].f_is_rl_origin_sensor = 0u;
         olp_data_ref.olp_inout_obj_data[no_of_objects].f_is_rr_origin_sensor = 0u;

         /* Following signals extended data of object, which is required for OLP work as expected*/
#ifdef OLP_OBJ_SOURCE_F360
         olp_data_ref.olp_extnd_obj_data[no_of_objects].tang_accel   = f360_Obj.object[i].tang_accel;
         olp_data_ref.olp_extnd_obj_data[no_of_objects].vcs_pointing = f360_Obj.object[i].orientation;
         Len_Wid_Segments segments{};
         Map_Ref_Point_To_Len_Wid_Segments(f360_Obj.object[i].reference_point, f360_Obj.object[i].length, f360_Obj.object[i].width,
                                           &segments);
         olp_data_ref.olp_extnd_obj_data[no_of_objects].len1 = segments.len1;
         olp_data_ref.olp_extnd_obj_data[no_of_objects].len2 = segments.len2;
         olp_data_ref.olp_extnd_obj_data[no_of_objects].wid1 = segments.wid1;
         olp_data_ref.olp_extnd_obj_data[no_of_objects].wid2 = segments.wid2;
#endif
         no_of_objects++;
      }
#ifndef UNIT_TEST
   }
#endif
   olp_data_ref.no_of_valid_objects = no_of_objects;
}

/*===========================================================================*\
 * Function: OLP_Log_Object_Data
 *===========================================================================
 * Return Value:
 *  - void
 *
 * Parameters:
 *  - logging pointer and olp data
 *
 * External References:
 *  - none
 *
 * Description:
 *    logg the olp output data
 *
\*===========================================================================*/
void OLP_Log_Object_Data(Olp_Data_T &olp_data_ref)
{
   D2M_Msg_T *p_ipc_d2m_msg          = (D2M_Msg_T *)Get_SP_Post_Proc_IPC_D2M_Msg_Buffer();
   Olp_Stream_T *olp_objects_log_ptr = &(p_ipc_d2m_msg->payload.Olp_Object_Data);

   olp_objects_log_ptr->stream_hdr.size       = sizeof(Olp_Stream_T);
   olp_objects_log_ptr->stream_hdr.scan_index = p_ipc_d2m_msg->payload.det_data.det_list_property.scanindex;

   for (uint32_t i = 0u; i < MAX_OLP_LOG_OBJECTS; i++)
   {
      olp_objects_log_ptr->id[i]                            = olp_data_ref.olp_inout_obj_data[i].id;
      olp_objects_log_ptr->unique_id[i]                     = olp_data_ref.olp_inout_obj_data[i].unique_id;
      olp_objects_log_ptr->index[i]                         = olp_data_ref.olp_inout_obj_data[i].index;
      olp_objects_log_ptr->status[i]                        = olp_data_ref.olp_inout_obj_data[i].status;
      olp_objects_log_ptr->age[i]                           = olp_data_ref.olp_inout_obj_data[i].age;
      olp_objects_log_ptr->stage_age[i]                     = olp_data_ref.olp_inout_obj_data[i].stage_age;
      olp_objects_log_ptr->existence_probability[i]         = olp_data_ref.olp_inout_obj_data[i].existence_probability;
      olp_objects_log_ptr->speed[i]                         = olp_data_ref.olp_inout_obj_data[i].speed;
      olp_objects_log_ptr->vcs_pos_x[i]                     = olp_data_ref.olp_inout_obj_data[i].vcs_pos.x;
      olp_objects_log_ptr->vcs_pos_y[i]                     = olp_data_ref.olp_inout_obj_data[i].vcs_pos.y;
      olp_objects_log_ptr->vcs_vel_x[i]                     = olp_data_ref.olp_inout_obj_data[i].vcs_vel.x;
      olp_objects_log_ptr->vcs_vel_y[i]                     = olp_data_ref.olp_inout_obj_data[i].vcs_vel.y;
      olp_objects_log_ptr->vcs_vel_rel_x[i]                 = olp_data_ref.olp_inout_obj_data[i].vcs_vel_rel.x;
      olp_objects_log_ptr->vcs_vel_rel_y[i]                 = olp_data_ref.olp_inout_obj_data[i].vcs_vel_rel.y;
      olp_objects_log_ptr->vcs_acc_x[i]                     = olp_data_ref.olp_inout_obj_data[i].vcs_accel.x;
      olp_objects_log_ptr->vcs_acc_y[i]                     = olp_data_ref.olp_inout_obj_data[i].vcs_accel.y;
      olp_objects_log_ptr->vcs_heading[i]                   = olp_data_ref.olp_inout_obj_data[i].vcs_heading;
      olp_objects_log_ptr->curvi_pos_x[i]                   = olp_data_ref.olp_inout_obj_data[i].curvi_pos.x;
      olp_objects_log_ptr->curvi_pos_y[i]                   = olp_data_ref.olp_inout_obj_data[i].curvi_pos.y;
      olp_objects_log_ptr->curvi_vel_x[i]                   = olp_data_ref.olp_inout_obj_data[i].curvi_vel.x;
      olp_objects_log_ptr->curvi_vel_y[i]                   = olp_data_ref.olp_inout_obj_data[i].curvi_vel.y;
      olp_objects_log_ptr->curvi_vel_rel_x[i]               = olp_data_ref.olp_inout_obj_data[i].curvi_vel_rel.x;
      olp_objects_log_ptr->curvi_vel_rel_y[i]               = olp_data_ref.olp_inout_obj_data[i].curvi_vel_rel.y;
      olp_objects_log_ptr->curvi_heading[i]                 = olp_data_ref.olp_inout_obj_data[i].curvi_heading;
      olp_objects_log_ptr->curvi_coordinates_calc_method[i] = olp_data_ref.olp_inout_obj_data[i].curvi_coordinates_calc_method;
      olp_objects_log_ptr->length[i]                        = olp_data_ref.olp_inout_obj_data[i].length;
      olp_objects_log_ptr->width[i]                         = olp_data_ref.olp_inout_obj_data[i].width;
      olp_objects_log_ptr->obj_class[i]                     = olp_data_ref.olp_inout_obj_data[i].obj_class;
      olp_objects_log_ptr->class_prob_pedestrian[i]         = olp_data_ref.olp_inout_obj_data[i].class_prob_pedestrian;
      olp_objects_log_ptr->class_prob_2wheel[i]             = olp_data_ref.olp_inout_obj_data[i].class_prob_2wheel;
      olp_objects_log_ptr->class_prob_car[i]                = olp_data_ref.olp_inout_obj_data[i].class_prob_car;
      olp_objects_log_ptr->class_prob_truck[i]              = olp_data_ref.olp_inout_obj_data[i].class_prob_truck;
      olp_objects_log_ptr->f_moveable[i]                    = olp_data_ref.olp_inout_obj_data[i].f_moveable;
   }
}

//#if defined (OLP_WRAPPER_USED_MEM_POOL)
///*===========================================================================*\
// * Function: Feature_Handler_OLP_Wrapper_Memory_Init
// *===========================================================================
// * Return Value:
// *  - boolean value indicating buffer allocation completed
// *
// * Parameters:
// *  - pointer to memory pool which can be used(Mem_Pool_T*)
// *
// * External References:
// *  - none
// *
// * Description:
// *    allocates the static variables to the memory pool buffer for olp object list
// *
//\*===========================================================================*/
// bool  Feature_Handler_OLP_Wrapper_Memory_Init(Mem_Pool_T *mem_pool)
//{
//   bool mem_alloc_success = false;
//
//   mem_alloc_success = mem_pool_alloc(mem_pool, sizeof(*Olp_Data_GPtr), (void **)&Olp_Data_GPtr);
//
//   if (mem_alloc_success)
//   {
//      /* Reset mempool area pionted by olp object list data pointers*/
//      (void *)memset(Olp_Data_GPtr, 0, sizeof(*Olp_Data_GPtr));
//   }
//
//   return mem_alloc_success;
//}
//#endif

/*===========================================================================*\
 * Function: Olp_Init
 *===========================================================================
 * Return Value:
 *  - void
 *
 * Parameters:
 *  - none
 *
 * External References:
 *  - none
 *
 * Description:
 *    initiate the OLP module
 *
\*===========================================================================*/
void Olp_Init(void)
{
   OLP_Init();
}

/*===========================================================================*\
 * Function: Olp_Main
 *===========================================================================
 * Return Value:
 *  - void
 *
 * Parameters:
 *  - none
 *
 * External References:
 *  - none
 *
 * Description:
 *    run the OLP module
 *
\*===========================================================================*/
void Olp_Main(void)
{
   D2M_Msg_T *p_ipc_d2m                 = (D2M_Msg_T *)Get_SP_Post_Proc_IPC_D2M_Msg_Buffer();
   object_list_log                      = &(p_ipc_d2m->payload.object_list_stream);
   Olp_Calibration_T *Olp_Cals_Cust_ptr = Olp_Get_Cal_Ptr();

   if (0u)
   {
      OLP_Update_Customer_Cals(Olp_Cals_Cust_ptr);
   }

   OLP_Update_Vehicle_Data(*Olp_Data_GPtr);

   OLP_Update_Object_Data(*object_list_log, *Olp_Data_GPtr);

   OLP_Main_Run_50ms(Olp_Data_GPtr);

   OLP_Log_Object_Data(*Olp_Data_GPtr);
}

/*===========================================================================*\
 * Function: Get_Olp_Objects_Data
 *===========================================================================
 * Return Value:
 *  - Olp_Data_T
 *
 * Parameters:
 *  - none
 *
 * External References:
 *  - none
 *
 * Description:
 *    return the olp module output
 *
\*===========================================================================*/
Olp_Data_T *Get_Olp_Objects_Data(void)
{
   return (Olp_Data_GPtr);
}

/*================================================================================================*\
* Revision History
*================================================================================================
*    Date          By                     Description
* MM/DD/YYYY  Name/Initials            JIRA AAA-#### Explanation of changes
* ----------  -------------            ----------------------------------------------------------
* 12/02/2024  Renjith T S               HEE-2287    SW3 OLP wrapper update.
* 25/03/2026 Hari Kailash M M           IUC-955

\*======================================================================*/
