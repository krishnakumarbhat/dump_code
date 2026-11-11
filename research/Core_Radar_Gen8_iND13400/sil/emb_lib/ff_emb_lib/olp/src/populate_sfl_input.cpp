#include "populate_sfl_input.h"
#include "emblib_ipc_data.h"

static SFL_IPC_T Feature_Ipc;

static void Map_f360_output_to_SFL_Input();
static void Map_vehicle_output_to_SFL_Input();

SFL_IPC_T *Get_SFL_Input_Ptr()
{
   return &Feature_Ipc;
}

void Map_f360_output_to_SFL_Input()
{
   ROT_Reduced_Objects_Log_T *ROT_Object_ptr = &Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output;
   SFL_IPC_T *Feature_Ipc_Ptr                = Get_SFL_Input_Ptr();
   for (int i = 0; i < MAX_ROT_OBJECTS; i++)
   {
      Feature_Ipc_Ptr->tracker_out[i].accuracy_length            = ROT_Object_ptr->obj[i].accuracy_length;
      Feature_Ipc_Ptr->tracker_out[i].trkID                      = ROT_Object_ptr->obj[i].trkID;
      Feature_Ipc_Ptr->tracker_out[i].reducedID                  = ROT_Object_ptr->obj[i].reducedID;
      Feature_Ipc_Ptr->tracker_out[i].unique_id                  = ROT_Object_ptr->obj[i].unique_id;
      Feature_Ipc_Ptr->tracker_out[i].vcs_xposn                  = ROT_Object_ptr->obj[i].vcs_xposn;
      Feature_Ipc_Ptr->tracker_out[i].vcs_yposn                  = ROT_Object_ptr->obj[i].vcs_yposn;
      Feature_Ipc_Ptr->tracker_out[i].vcs_xvel                   = ROT_Object_ptr->obj[i].vcs_xvel;
      Feature_Ipc_Ptr->tracker_out[i].vcs_yvel                   = ROT_Object_ptr->obj[i].vcs_yvel;
      Feature_Ipc_Ptr->tracker_out[i].vcs_xaccel                 = ROT_Object_ptr->obj[i].vcs_xaccel;
      Feature_Ipc_Ptr->tracker_out[i].vcs_yaccel                 = ROT_Object_ptr->obj[i].vcs_yaccel;
      Feature_Ipc_Ptr->tracker_out[i].vcs_heading                = ROT_Object_ptr->obj[i].vcs_heading;
      Feature_Ipc_Ptr->tracker_out[i].vcs_pointing               = ROT_Object_ptr->obj[i].vcs_pointing;
      Feature_Ipc_Ptr->tracker_out[i].speed                      = ROT_Object_ptr->obj[i].speed;
      Feature_Ipc_Ptr->tracker_out[i].curvature                  = ROT_Object_ptr->obj[i].curvature;
      Feature_Ipc_Ptr->tracker_out[i].tang_accel                 = ROT_Object_ptr->obj[i].tang_accel;
      Feature_Ipc_Ptr->tracker_out[i].existence_probability      = ROT_Object_ptr->obj[i].existence_probability;
      Feature_Ipc_Ptr->tracker_out[i].confidenceLevel            = ROT_Object_ptr->obj[i].confidenceLevel;
      Feature_Ipc_Ptr->tracker_out[i].time_since_measurement     = ROT_Object_ptr->obj[i].time_since_measurement;
      Feature_Ipc_Ptr->tracker_out[i].time_since_cluster_created = ROT_Object_ptr->obj[i].time_since_cluster_created;
      Feature_Ipc_Ptr->tracker_out[i].time_since_track_updated   = ROT_Object_ptr->obj[i].time_since_track_updated;
      Feature_Ipc_Ptr->tracker_out[i].time_since_stage_start     = ROT_Object_ptr->obj[i].time_since_stage_start;
      Feature_Ipc_Ptr->tracker_out[i].len1                       = ROT_Object_ptr->obj[i].len1;
      Feature_Ipc_Ptr->tracker_out[i].len2                       = ROT_Object_ptr->obj[i].len2;
      Feature_Ipc_Ptr->tracker_out[i].wid1                       = ROT_Object_ptr->obj[i].wid1;
      Feature_Ipc_Ptr->tracker_out[i].wid2                       = ROT_Object_ptr->obj[i].wid2;
      Feature_Ipc_Ptr->tracker_out[i].accuracy_length            = ROT_Object_ptr->obj[i].accuracy_length;
      Feature_Ipc_Ptr->tracker_out[i].accuracy_width             = ROT_Object_ptr->obj[i].accuracy_width;
      Feature_Ipc_Ptr->tracker_out[i].probability_pedestrian     = ROT_Object_ptr->obj[i].probability_pedestrian;
      Feature_Ipc_Ptr->tracker_out[i].probability_car            = ROT_Object_ptr->obj[i].probability_car;
      Feature_Ipc_Ptr->tracker_out[i].probability_motorcycle     = ROT_Object_ptr->obj[i].probability_motorcycle;
      Feature_Ipc_Ptr->tracker_out[i].probability_bicycle        = ROT_Object_ptr->obj[i].probability_bicycle;
      Feature_Ipc_Ptr->tracker_out[i].probability_truck          = ROT_Object_ptr->obj[i].probability_truck;
      Feature_Ipc_Ptr->tracker_out[i].probability_undet          = ROT_Object_ptr->obj[i].probability_undet;
      Feature_Ipc_Ptr->tracker_out[i].ndets                      = ROT_Object_ptr->obj[i].ndets;
      Feature_Ipc_Ptr->tracker_out[i].status                     = ROT_Object_ptr->obj[i].status;
      Feature_Ipc_Ptr->tracker_out[i].reducedStatus              = ROT_Object_ptr->obj[i].reducedStatus;
      Feature_Ipc_Ptr->tracker_out[i].init_scheme                = ROT_Object_ptr->obj[i].init_scheme;
      Feature_Ipc_Ptr->tracker_out[i].object_class               = ROT_Object_ptr->obj[i].object_class;
      Feature_Ipc_Ptr->tracker_out[i].f_crossing                 = ROT_Object_ptr->obj[i].f_crossing;
      Feature_Ipc_Ptr->tracker_out[i].f_moving                   = ROT_Object_ptr->obj[i].f_moving;
      Feature_Ipc_Ptr->tracker_out[i].f_moveable                 = ROT_Object_ptr->obj[i].f_moveable;
      Feature_Ipc_Ptr->tracker_out[i].f_oncoming                 = ROT_Object_ptr->obj[i].f_oncoming;
      Feature_Ipc_Ptr->tracker_out[i].f_vehicular_trk            = ROT_Object_ptr->obj[i].f_vehicular_trk;
      Feature_Ipc_Ptr->tracker_out[i].f_onguardrail              = ROT_Object_ptr->obj[i].f_onguardrail;
      Feature_Ipc_Ptr->tracker_out[i].f_fast_moving              = ROT_Object_ptr->obj[i].f_fast_moving;
      Feature_Ipc_Ptr->tracker_out[i].underdrivable_status       = ROT_Object_ptr->obj[i].underdrivable_status;
      Feature_Ipc_Ptr->tracker_out[i].trk_fltr_type              = ROT_Object_ptr->obj[i].trk_fltr_type;
   }
}

void Map_vehicle_output_to_SFL_Input()
{
   ROT_Vehicle_Info_Log_T *ROT_Vehicle_ptr         = &Get_IPC_D2M_Buffer()->payload.vehicle_data.vehicle_info;
   SFL_IPC_T *Feature_Ipc_Ptr                      = Get_SFL_Input_Ptr();
   Feature_Ipc_Ptr->vehicle_out.acceleration       = ROT_Vehicle_ptr->acceleration;
   Feature_Ipc_Ptr->vehicle_out.global_time_sync_s = ROT_Vehicle_ptr->global_time_sync_s;
   Feature_Ipc_Ptr->vehicle_out.timestamp_s        = ROT_Vehicle_ptr->timestamp_s;
   for (int sensor = 0; sensor < ROT_NUM_TOTAL_RADAR_SENSORS; sensor++)
   {
      Feature_Ipc_Ptr->vehicle_out.align_angle_az_rad[sensor] = ROT_Vehicle_ptr->align_angle_az_rad[sensor];
      Feature_Ipc_Ptr->vehicle_out.align_angle_el_rad[sensor] = ROT_Vehicle_ptr->align_angle_el_rad[sensor];
   }
   Feature_Ipc_Ptr->vehicle_out.world_x                   = ROT_Vehicle_ptr->world_x;
   Feature_Ipc_Ptr->vehicle_out.world_y                   = ROT_Vehicle_ptr->world_y;
   Feature_Ipc_Ptr->vehicle_out.rear_cornering_compliance = ROT_Vehicle_ptr->rear_cornering_compliance;
   Feature_Ipc_Ptr->vehicle_out.raw_speed                 = ROT_Vehicle_ptr->raw_speed;
   Feature_Ipc_Ptr->vehicle_out.steering_angle_rad        = ROT_Vehicle_ptr->steering_angle_rad;
   Feature_Ipc_Ptr->vehicle_out.raw_yaw_rate_rad          = ROT_Vehicle_ptr->raw_yaw_rate_rad;
   Feature_Ipc_Ptr->vehicle_out.dist_rear_axle_to_vcs_m   = ROT_Vehicle_ptr->dist_rear_axle_to_vcs_m;
   Feature_Ipc_Ptr->vehicle_out.speed_correction_factor   = ROT_Vehicle_ptr->speed_correction_factor;
   Feature_Ipc_Ptr->vehicle_out.speed                     = ROT_Vehicle_ptr->speed;
   Feature_Ipc_Ptr->vehicle_out.acceleration              = ROT_Vehicle_ptr->acceleration;
   Feature_Ipc_Ptr->vehicle_out.vcs_speed                 = ROT_Vehicle_ptr->vcs_speed;
   Feature_Ipc_Ptr->vehicle_out.vcs_lat_acceleration      = ROT_Vehicle_ptr->vcs_lat_acceleration;
   Feature_Ipc_Ptr->vehicle_out.vcs_long_acceleration     = ROT_Vehicle_ptr->vcs_long_acceleration;
   Feature_Ipc_Ptr->vehicle_out.heading                   = ROT_Vehicle_ptr->heading;
   Feature_Ipc_Ptr->vehicle_out.delta_pointing            = ROT_Vehicle_ptr->delta_pointing;
   Feature_Ipc_Ptr->vehicle_out.delta_position_x          = ROT_Vehicle_ptr->delta_position_x;
   Feature_Ipc_Ptr->vehicle_out.delta_position_y          = ROT_Vehicle_ptr->delta_position_y;
   Feature_Ipc_Ptr->vehicle_out.vcs_sideslip              = ROT_Vehicle_ptr->vcs_sideslip;
   Feature_Ipc_Ptr->vehicle_out.curvature_rear            = ROT_Vehicle_ptr->curvature_rear;
   Feature_Ipc_Ptr->vehicle_out.vehicle_index             = ROT_Vehicle_ptr->vehicle_index;
   Feature_Ipc_Ptr->vehicle_out.prndl                     = ROT_Vehicle_ptr->prndl;
   Feature_Ipc_Ptr->vehicle_out.f_reverse_gear            = ROT_Vehicle_ptr->f_reverse_gear;
   Feature_Ipc_Ptr->vehicle_out.f_trailer_present         = ROT_Vehicle_ptr->f_trailer_present;
}

void Populate_SFL_Input()
{
   Map_f360_output_to_SFL_Input();
   Map_vehicle_output_to_SFL_Input();
}
