/*
 * Copyright (C) 2026 Aptiv. All rights reserved.
 *
 * File:    emb_tracker_stubs.cpp
 * Purpose: Embedded tracker stub functions implementation
 * Abbrev:  List any abbreviations used in this file
 * Trace:   Traceability ID (requirement, work item, etc.)
 */

/*==========================================================================*/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "emb_tracker_stubs.h"
#include "emb_tracker_internal.h"

#include "ipc_data.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstring>
// #include <fstream>
// #include <iomanip>

using namespace f360_variant_A;

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
static D2M_Msg_T *p_stub_d2m                            = nullptr;
static M2D_Msg_T *p_stub_m2d                            = nullptr;
static volatile M2D_One_Time_Msg_T *p_stub_m2d_one_time = nullptr;

volatile Stub_Env_Mode_T stub_env_mode                                       = STUB_ENV;
static volatile Radar_Position_T stub_sensor_position[MAX_NUMBER_OF_SENSORS] = {RADAR_POSITION_FRONT_CENTER};
static bool F_Init_Complete                                                  = false;
/* Test hook: lets unit tests force invalid partner recvd_flags for validity-check branch coverage */
bool stub_force_partner_flags_valid   = true;
volatile uint8_t Simulation_Test_Case = 0;
static Simulation_Target_Params_T Feature_Target_Simulated;

typedef enum
{
   STUB_DET_DEST_MAIN,
   STUB_DET_DEST_PARTNER,
} Stub_Det_Destination_T;

/* ========================================================================== */
/*                       Local Function Declarations                          */
/* ========================================================================== */
static uint8_t RNG(void);
static const volatile Sensor_Mount_Data_T &Reinterpret_As_Sensor_Mount_Data(const volatile PS_Mounting_Data_T &sensor_mount_data);
void Generate_Detections(const volatile Sensor_Calib_Data_T &sensor, const volatile Sensor_Mount_Data_T &sensor_mount_data,
                         const float target_xpos, const float target_ypos, const float target_xvel, const float target_yvel,
                         const Stub_Det_Destination_T destination);
static void Update_Dynamic_Env(void);
static void Update_Static_Env(void);
static void Update_Env_mois();
static Stub_Sensor_Pose_T Get_Sensor_Position_Pose(Radar_Position_T position);
static void Mois_Test_Cases();
static void Bsis_Test_Cases();
uint8_t Get_Simulation_Test_Case(void);
static void Get_Sensor_Velocity_In_VCS(const volatile Sensor_Mount_Data_T &sensor, const Vse_Output_T &p_vse_output,
                                       float &sensor_vx_vcs, float &sensor_vy_vcs);
static void Get_Sensor_Relative_Target_Position(const volatile Sensor_Mount_Data_T &sensor_mount_data, const float target_xpos,
                                                const float target_ypos, float &target_rel_xpos, float &target_rel_ypos);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
/*
 * Function:    Set_Stub_IPC_Ptrs
 * Returns:     None
 * Parameters:  p_d2m - Pointer to D2M message structure
 *              p_m2d - Pointer to M2D message structure
 * Globals:     p_stub_d2m, p_stub_m2d
 * Abstract:    Sets the IPC pointers for the stub environment so that stub functions can access D2M/M2D data.
 * Reentrant:   NO
 */
void Set_Stub_IPC_Ptrs(D2M_Msg_T *p_d2m, M2D_Msg_T *p_m2d)
{
   p_stub_d2m = p_d2m;
   p_stub_m2d = p_m2d;
}

void Set_Onetime_Stub_IPC_Ptrs(volatile M2D_One_Time_Msg_T *p_ipc_m2d_one_time)
{
   p_stub_m2d_one_time = p_ipc_m2d_one_time;
}
/*
 * Function:    Get_Simulation_Test_Case
 * Returns:     Simulation test case identifier
 * Parameters:  None
 * Globals:     Simulation_Test_Case
 * Abstract:    Returns the current simulation test case identifier
 * Reentrant:   NO
 */
uint8_t Get_Simulation_Test_Case(void)
{
   return (Simulation_Test_Case);
}

/*
 * Function:    Get_Sensor_Velocity_In_VCS
 * Returns:     None
 * Parameters:  sensor - Reference to the radar sensor structure
 *              p_vse_output - Reference to the vse vehicle structure
 *              sensor_vx_vcs - Reference to store the sensor's longitudinal velocity in VCS
 *              sensor_vy_vcs - Reference to store the sensor's lateral velocity in VCS
 * Globals:     None
 * Abstract:    Calculates the sensor's velocity in the vehicle coordinate system (VCS)
 * Reentrant:   NO
 */
static void Get_Sensor_Velocity_In_VCS(const volatile Sensor_Mount_Data_T &sensor, const Vse_Output_T &p_vse_output,
                                       float &sensor_vx_vcs, float &sensor_vy_vcs)
{
   const float abs_speed = hypotf(p_vse_output.vcs_long_velocity, p_vse_output.vcs_lat_velocity);
   float temp_vcs_speed  = (0.0F > p_vse_output.vcs_long_velocity) ? (-1.0F * abs_speed) : abs_speed;

   const float sensor_xpos =
      p_stub_m2d_one_time->calib_data.vehicle_calib_data.k_distance_front_bumper_to_rear_axle +
      (sensor.k_sensor_mount_pos_x - p_stub_m2d_one_time->calib_data.vehicle_calib_data.k_distance_front_bumper_to_rear_axle);
   const float sensor_ypos   = NEG_FLOAT * sensor.k_sensor_mount_pos_y;
   const float rear_sideslip = -(p_stub_m2d_one_time->calib_data.vehicle_calib_data.k_rear_cornering_compliance) *
                               (p_vse_output.curvature_rear_axle * temp_vcs_speed * temp_vcs_speed);
   const float cos_rear_sideslip = cosf(rear_sideslip);
   const float sin_rear_sideslip = sinf(rear_sideslip);
   sensor_vx_vcs                 = (temp_vcs_speed * cos_rear_sideslip) - (p_vse_output.comp_yaw_rate_filtered * sensor_ypos);
   sensor_vy_vcs                 = (temp_vcs_speed * sin_rear_sideslip) + (p_vse_output.comp_yaw_rate_filtered * sensor_xpos);
}
/*
 * Function:    Get_Sensor_Relative_Target_Position
 * Returns:     None
 * Parameters:  sensor - Reference to the radar sensor structure
 *              target_xpos - Target's x position in VCS
 *              target_ypos - Target's y position in VCS
 *              target_rel_xpos - Reference to store the target's relative x position
 *              target_rel_ypos - Reference to store the target's relative y position
 * Globals:     None
 * Abstract:    Calculates the target's position relative to the sensor
 * Reentrant:   NO
 */
static void Get_Sensor_Relative_Target_Position(const volatile Sensor_Mount_Data_T &sensor_mount_data, const float target_xpos,
                                                const float target_ypos, float &target_rel_xpos, float &target_rel_ypos)
{
   target_rel_xpos = target_xpos - (sensor_mount_data.k_sensor_mount_pos_x -
                                    p_stub_m2d_one_time->calib_data.vehicle_calib_data.k_distance_front_bumper_to_rear_axle);
   target_rel_ypos = target_ypos - (NEG_FLOAT * sensor_mount_data.k_sensor_mount_pos_y);
}

/*
 * Function:    Get_Sensor_Position_Pose
 * Returns:     Stub_Sensor_Pose_T
 * Parameters:  Radar_Position_T position - The position of the radar sensor on the vehicle
 * Globals:     none
 * Abstract:    Returns the sensor's mounting position and orientation based on its radar position. Values are chosen to match the
 * Python f360_hil_stub_viz.py implementation for consistency. Reentrant:   NO
 */
static Stub_Sensor_Pose_T Get_Sensor_Position_Pose(Radar_Position_T position)
{
   Stub_Sensor_Pose_T pose;

   switch (position)
   {
      /*case F360_MOUNTING_LOCATION_CENTER_REAR:
         pose.x_m     = -5.0F;
         pose.y_m     = 0.0F;
         pose.yaw_rad = F360_DEG2RAD(180.0F);
         break;*/
      case RADAR_POSITION_FRONT_CENTER:
         pose.x_m      = 0.0F;
         pose.y_m      = 0.0F;
         pose.yaw_rad  = F360_DEG2RAD(0.0F);
         pose.roll_rad = F360_DEG2RAD(0.0F);
         break;
      case RADAR_POSITION_FRONT_LEFT:
         if (stub_env_mode == STUB_ENV_BSIS_AL)
         {
            pose.x_m      = -2.5F;
            pose.y_m      = -0.9F;
            pose.yaw_rad  = F360_DEG2RAD(-75.0F);
            pose.roll_rad = F360_DEG2RAD(0.0F);
         }
         else
         {
            pose.x_m      = -0.35F;
            pose.y_m      = -0.9F;
            pose.yaw_rad  = F360_DEG2RAD(-60.0F);
            pose.roll_rad = F360_DEG2RAD(0.0F);
         }
         break;
      case RADAR_POSITION_FRONT_RIGHT:
         pose.x_m      = -0.35F;
         pose.y_m      = 0.9F;
         pose.yaw_rad  = F360_DEG2RAD(60.0F);
         pose.roll_rad = F360_DEG2RAD(0.0F);
         break;
      case RADAR_POSITION_REAR_LEFT:
         if (stub_env_mode == STUB_ENV_BSIS_AL)
         {
            pose.x_m      = -2.5F;
            pose.y_m      = -0.9F;
            pose.yaw_rad  = F360_DEG2RAD(-105.0F);
            pose.roll_rad = F360_DEG2RAD(0.0F);
         }
         else
         {
            pose.x_m      = -4.5F;
            pose.y_m      = -0.9F;
            pose.yaw_rad  = F360_DEG2RAD(-120.0F);
            pose.roll_rad = F360_DEG2RAD(0.0F);
         }
         break;
      case RADAR_POSITION_REAR_RIGHT:
         pose.x_m      = -4.5F;
         pose.y_m      = 0.9F;
         pose.yaw_rad  = F360_DEG2RAD(120.0F);
         pose.roll_rad = F360_DEG2RAD(0.0F);
         break;
      default:
         pose.x_m      = -5.0F;
         pose.y_m      = 0.0F;
         pose.yaw_rad  = F360_DEG2RAD(180.0F);
         pose.roll_rad = F360_DEG2RAD(0.0F);
         break;
   }

   return pose;
}

/*
 * Function:    Populate_Ipc_Data_For_Init_Stub_Sensors
 * Returns:     void
 * Parameters:  volatile M2D_One_Time_Msg_T *p_ipc_m2d_one_time - Pointer to one-time IPC message structure
 *              M2D_Msg_T *p_ipc_m2d - Pointer to IPC message structure
 * Globals:     none
 * Abstract:    Populates IPC data for initializing stub sensors based on their positions.
 * Reentrant:   NO
 */
void Populate_Ipc_Data_For_Init_Stub_Sensors(volatile M2D_One_Time_Msg_T *p_ipc_m2d_one_time, M2D_Msg_T *p_ipc_m2d)
{
   Set_Onetime_Stub_IPC_Ptrs(p_ipc_m2d_one_time);
   p_ipc_m2d_one_time->calib_data.vehicle_calib_data.k_distance_front_bumper_to_rear_axle = 4;
   p_ipc_m2d_one_time->calib_data.vehicle_calib_data.k_rear_cornering_compliance          = 0;
   p_ipc_m2d_one_time->calib_data.vehicle_calib_data.k_steering_gear_ratio                = 1;
   p_ipc_m2d_one_time->calib_data.vehicle_calib_data.k_wheelbase                          = 2.5;

   p_ipc_m2d_one_time->calib_data.vehicle_calib_data.k_vehicle_width  = 1.8;
   p_ipc_m2d_one_time->calib_data.vehicle_calib_data.k_vehicle_length = 4.5;
   p_ipc_m2d->payload.veh_data.veh_params.k_dist_rear_axle_to_vcs =
      p_ipc_m2d_one_time->calib_data.vehicle_calib_data.k_distance_front_bumper_to_rear_axle;
   p_ipc_m2d->payload.veh_data.veh_params.k_rear_cornering_compliance =
      p_ipc_m2d_one_time->calib_data.vehicle_calib_data.k_rear_cornering_compliance;
   p_ipc_m2d->payload.veh_data.veh_params.k_steering_gear_ratio =
      p_ipc_m2d_one_time->calib_data.vehicle_calib_data.k_steering_gear_ratio;
   p_ipc_m2d->payload.veh_data.veh_params.k_wheel_base = p_ipc_m2d_one_time->calib_data.vehicle_calib_data.k_wheelbase;

   p_ipc_m2d->payload.veh_data.veh_params.k_vehicle_width  = p_ipc_m2d_one_time->calib_data.vehicle_calib_data.k_vehicle_width;
   p_ipc_m2d->payload.veh_data.veh_params.k_vehicle_length = p_ipc_m2d_one_time->calib_data.vehicle_calib_data.k_vehicle_length;
   if (MAX_NUMBER_OF_SENSORS == 2)
   {
      if (stub_env_mode == STUB_ENV_MOIS_AL)
      {
         stub_sensor_position[0] = RADAR_POSITION_FRONT_CENTER;
         stub_sensor_position[1] = RADAR_POSITION_FRONT_CENTER;
      }
      else
      {
         stub_sensor_position[0] = RADAR_POSITION_REAR_LEFT;
         stub_sensor_position[1] = RADAR_POSITION_FRONT_LEFT;
      }
   }
   for (uint8_t sensor_index = 0; sensor_index < MAX_NUMBER_OF_SENSORS; sensor_index++)
   {
      const uint8_t partner_sensor_index = (sensor_index > 0U) ? (sensor_index - 1U) : 0U;
      if (sensor_index == 0)
      {
         p_ipc_m2d_one_time->radar_position = stub_sensor_position[0];
      }
      else
      {
         p_ipc_m2d->payload.partners_data.partner_det_list_property_data[partner_sensor_index].radar_position =
            stub_sensor_position[sensor_index];
      }
      Stub_Sensor_Pose_T sensor_pose = Get_Sensor_Position_Pose(stub_sensor_position[sensor_index]);

      if (p_ipc_m2d_one_time != nullptr)
      {
         volatile Sensor_Calib_Data_T *sensor_calib_data_ptr = &p_ipc_m2d_one_time->calib_data.sensor_calib_data;
         volatile Sensor_Mount_Data_T *sensor_mount_data_ptr = reinterpret_cast<volatile Sensor_Mount_Data_T *>(
            &p_ipc_m2d->payload.partners_data.partner_sensor_mounting_params[partner_sensor_index]);

         if (sensor_index == 0)
         {
            sensor_mount_data_ptr = &p_ipc_m2d_one_time->calib_data.sensor_calib_data.sensor_mount_data;
         }

         /*need to give iso input to tracker so it will convert to sae in wrapper. stub code modunting is in sae so we will
         convert to iso*/

         sensor_mount_data_ptr->k_sensor_mount_pos_x =
            sensor_pose.x_m + p_ipc_m2d_one_time->calib_data.vehicle_calib_data.k_distance_front_bumper_to_rear_axle;
         sensor_mount_data_ptr->k_sensor_mount_pos_y      = NEG_FLOAT * sensor_pose.y_m;
         sensor_mount_data_ptr->k_sensor_mount_pos_z      = 0.4f;
         sensor_mount_data_ptr->k_sensor_mount_height     = 0.4f;
         sensor_mount_data_ptr->k_sensor_mount_ornt_yaw   = NEG_FLOAT * sensor_pose.yaw_rad;
         sensor_mount_data_ptr->k_sensor_mount_ornt_pitch = 0.0F;
         sensor_mount_data_ptr->k_sensor_mount_ornt_roll  = F360_PI - sensor_pose.roll_rad;
         sensor_calib_data_ptr->k_fov_hor_begin           = -1.3F;
         sensor_calib_data_ptr->k_fov_hor_end             = 1.3F;
         sensor_calib_data_ptr->k_fov_ver_begin           = -0.2F;
         sensor_calib_data_ptr->k_fov_ver_end             = 0.2F;
         sensor_calib_data_ptr->k_rdotmin                 = -23.0F;
         float32_t v_wrapping[4]                          = {29.75f, 25.72f, 28.81f, 24.70f};
         for (uint8_t look_id = 0U; look_id < (uint8_t)F360_DET_NUM_LOOK_ID; look_id++)
         {
            sensor_calib_data_ptr->k_detection_range_max[look_id] = 250.0F;
            sensor_calib_data_ptr->k_vwrapping[look_id]           = v_wrapping[look_id];
         }
      }
   }
}

/*
 * Function:    Populate_Ipc_Data_For_Stub_Host
 * Returns:     void
 * Parameters:  D2M_Msg_T *p_ipc_d2m - Pointer to D2M IPC message structure
 *              M2D_Msg_T *p_ipc_m2d - Pointer to M2D IPC message structure
 * Globals:     none
 * Abstract:    Populates IPC data for initializing stub host based on their positions.
 * Reentrant:   NO
 */
void Populate_Ipc_Data_For_Stub_Host(D2M_Msg_T *p_ipc_d2m, M2D_Msg_T *p_ipc_m2d)
{
   uint32_t static look_index_inc = 0;
   static uint8_t stub_look_type  = 0;
   Set_Stub_IPC_Ptrs(p_ipc_d2m, p_ipc_m2d);
   /* Only the detection data is regenerated per cycle, the partner mounting data is populated once at init. */
   memset(&p_stub_m2d->payload.partners_data.partner_sensor_det_data, 0, sizeof(PS_Det_T));
   if (stub_force_partner_flags_valid)
   {
      p_stub_m2d->payload.partners_data.partner_sensor_diag_data[0].status_recvd_flag = 1U;
      p_stub_m2d->payload.partners_data.partner_sensor_diag_data[0].det_recvd_flag    = 1U;
   }
   memset(&p_stub_d2m->payload.downselection_data.af_ds_dets, 0, sizeof(p_stub_d2m->payload.downselection_data.af_ds_dets));
   memset(&p_stub_d2m->payload.det_data.af_dets, 0, sizeof(p_stub_d2m->payload.det_data.af_dets));
   memset(&p_stub_m2d->payload.veh_data, 0, sizeof(p_stub_m2d->payload.veh_data));
   p_stub_d2m->payload.downselection_data.num_af_ds_det                                   = 0;
   p_stub_d2m->payload.downselection_data.stream_hdr.scan_index                           = core_info.cnt_loops;
   p_stub_d2m->payload.dynamic_alignment_log_stream.dra_core_data.alignment_mode          = 0;
   p_stub_d2m->payload.dynamic_alignment_log_stream.dra_core_data.error_status_combined   = 1;
   p_stub_d2m->payload.dynamic_alignment_log_stream.dra_core_data.azimuth_estimation_qf   = 0;
   p_stub_d2m->payload.dynamic_alignment_log_stream.dra_core_data.elevation_estimation_qf = 0;
   stub_look_type                                                     = stub_look_type < 3 ? stub_look_type + 1 : 0;
   p_stub_d2m->payload.downselection_data.det_list_property.look_type = (F360_Det_Look_ID_T)stub_look_type;
   p_stub_d2m->payload.downselection_data.det_list_property.lookindex = look_index_inc;
   look_index_inc++;
   if (MAX_NUMBER_OF_SENSORS == 2)
   {
      p_stub_m2d->payload.partners_data.partner_det_list_property_data[0].look_index =
         p_stub_d2m->payload.downselection_data.det_list_property.lookindex;
      p_stub_m2d->payload.partners_data.partner_det_list_property_data[0].look_type =
         (F360_Det_Look_ID_T)p_stub_d2m->payload.downselection_data.det_list_property.look_type;
   }

   Vse_Stream_T *p_vse_stream = &p_stub_m2d->payload.veh_data;
   const float stub_speed     = (stub_env_mode == STUB_ENV_MOIS_AL) ? 0.0F : 10.0F;

   p_vse_stream->vse_output.timestamp_secs                    = (uint32_t)((core_info.time_us - 50000U) / 1000000U);
   p_vse_stream->vse_output.timestamp_nanosecs                = (uint32_t)(((core_info.time_us - 50000U) % 1000000U) * 1000U);
   p_vse_stream->vse_output.veh_index                         = look_index_inc;
   p_vse_stream->vse_output.signed_filt_veh_speed_over_ground = stub_speed;
   p_vse_stream->vse_output.vcs_long_velocity                 = stub_speed;
   p_vse_stream->vse_output.vcs_lat_velocity                  = 0.0F;
   p_vse_stream->vse_output.vcs_lat_accel                     = 0.0F;
   p_vse_stream->vse_output.vcs_long_accel                    = 0.0F;
   p_vse_stream->vse_output.comp_yaw_rate_filtered            = 0.0F;
   p_vse_stream->vse_output.vcs_sideslip                      = 0.0F;
   p_vse_stream->vse_output.curvature_rear_axle               = 0.0F;
   p_vse_stream->vse_output.speed_compensation_factor         = 1.0F;
   p_vse_stream->vse_output.raw_speed_mps                     = stub_speed;
   p_vse_stream->vse_output.raw_yaw_rate_rps                  = 0.0F;
   p_vse_stream->vse_output.filt_veh_speed_over_ground_qf     = 3U;
   p_vse_stream->vse_output.comp_yaw_rate_qf                  = 3U;
   p_vse_stream->vse_output.vcs_lat_accel_qf                  = 3U;
   p_vse_stream->vse_output.vcs_long_accel_qf                 = 3U;
   p_vse_stream->vse_output_valid                             = CODED_TRUE;
}

/*
 * Function:    Populate_Ipc_Data_For_Stub_Dets
 * Returns:     void
 * Parameters:  none
 * Globals:     none
 * Abstract:    Populates IPC data for initializing stub detections based on their positions.
 * Reentrant:   NO
 */

void Populate_Ipc_Data_For_Stub_Dets()
{
   if (core_info.cnt_loops > 1)
   {
      static Stub_Env_Mode_T prev_stub_env_mode = stub_env_mode;
      if (prev_stub_env_mode != stub_env_mode)
      {
         F_Init_Complete    = false;
         prev_stub_env_mode = stub_env_mode;
         memset(&Feature_Target_Simulated, 0, sizeof(Feature_Target_Simulated));
      }

      switch (stub_env_mode)
      {
         case STUB_ENV_MOIS_AL:
            Mois_Test_Cases();
            break;
         case STUB_ENV_BSIS_AL:
            Bsis_Test_Cases();
            break;
         default:
            Update_Dynamic_Env();
            break;
      }
      if (Get_Simulation_Test_Case() == 0)
      {
         Update_Static_Env();
      }
   }
}
/*
 * Function:    RNG
 * Returns:     uint8_t[0 to 255]
 * Parameters:  none
 * Globals:     none
 * Abstract:    Generates a pseudo-random value for stub scenario variation.
 * Reentrant:   NO
 */
uint8_t RNG(void)
{
   static uint32_t seed = 1;
   seed                 = seed * 1103515245U + 12345U;
   uint8_t output       = seed % UINT8_MAX;
   return output;
}

static const volatile Sensor_Mount_Data_T &Reinterpret_As_Sensor_Mount_Data(const volatile PS_Mounting_Data_T &sensor_mount_data)
{
   return reinterpret_cast<const volatile Sensor_Mount_Data_T &>(sensor_mount_data);
}

// static void Write_Generate_Detections_Debug_Row(const volatile Sensor_Calib_Data_T &sensor,
//                                               const volatile Sensor_Mount_Data_T &sensor_mount_data,
//                                               const float target_xpos, const float target_ypos,
//                                               const float target_xvel, const float target_yvel,
//                                               const Stub_Det_Destination_T destination,
//                                               const float target_rel_xpos, const float target_rel_ypos,
//                                               const float az_vcs, const float az_sensor, const bool inside_fov,
//                                               const bool f_moving, const int32_t thresh, const int32_t ndet,
//                                               const int32_t max_dets, const float range, const float inv_range,
//                                               const float sensor_vx_vcs, const float sensor_vy_vcs,
//                                               const float target_rel_vx, const float target_rel_vy,
//                                               const float az, const float range_rate)
// {
//    static std::ofstream debug_file("emb_tracker_debug.csv", std::ios::app);
//    static bool header_written = false;

//    if (!header_written)
//    {
//       debug_file << "time_us,destination,target_xpos,target_ypos,target_xvel,target_yvel,"
//                    "sensor_mount_pos_x,sensor_mount_pos_y,sensor_mount_ornt_yaw,"
//                    "k_fov_hor_begin,k_fov_hor_end,k_rdotmin,k_vwrapping,lookid,target_rel_xpos,target_rel_ypos,"
//                    "az_vcs,az_sensor,inside_fov,f_moving,thresh,ndet,max_dets,range,inv_range,"
//                    "sensor_vx_vcs,sensor_vy_vcs,target_rel_vx,target_rel_vy,az,range_rate\n";
//       header_written = true;
//    }

//    debug_file << std::fixed << std::setprecision(9) << core_info.time_us << ","
//               << static_cast<int32_t>(destination) << "," << target_xpos << "," << target_ypos << "," << target_xvel
//               << "," << target_yvel << "," << sensor_mount_data.k_sensor_mount_pos_x << ","
//               << sensor_mount_data.k_sensor_mount_pos_y << "," << sensor_mount_data.k_sensor_mount_ornt_yaw << ","
//               << sensor.k_fov_hor_begin << "," << sensor.k_fov_hor_end << "," << sensor.k_rdotmin << ","
//               << sensor.k_vwrapping[(uint8_t)p_stub_d2m->payload.downselection_data.det_list_property.look_type] << ","
//               << static_cast<int32_t>((F360_Det_Look_ID_T)p_stub_d2m->payload.downselection_data.det_list_property.look_type
//               ) << "," << target_rel_xpos << "," << target_rel_ypos << "," << az_vcs << "," << az_sensor << ","
//               << (inside_fov ? 1 : 0) << "," << (f_moving ? 1 : 0) << "," << thresh << "," << ndet << ","
//               << max_dets << "," << range << "," << inv_range << "," << sensor_vx_vcs << "," << sensor_vy_vcs
//               << "," << target_rel_vx << "," << target_rel_vy << "," << az << "," << range_rate << "\n";
//    debug_file.flush();
// }

/*
 * Function:    Get_Partner_Mount_Data
 * Returns:     Reference to the mounting data of the requested partner sensor
 * Parameters:  sensor_index - Sensor index, where index 0 is the main sensor
 * Globals:     p_stub_m2d
 * Abstract:    Returns the partner mounting data, converting the sensor index into a partner index.
 * Reentrant:   NO
 */
static const volatile Sensor_Mount_Data_T &Get_Partner_Mount_Data(const uint8_t sensor_index)
{
   const uint8_t partner_sensor_index = static_cast<uint8_t>(sensor_index - 1U);
   const volatile PS_Mounting_Data_T &partner_mount_data =
      p_stub_m2d->payload.partners_data.partner_sensor_mounting_params[partner_sensor_index];
   return Reinterpret_As_Sensor_Mount_Data(partner_mount_data);
}

/*
 * Function:    Generate_Detections
 * Returns:     void
 * Parameters:  sensor - Reference to the radar sensor structure
 *              target_xpos - Target's x position in VCS
 *              target_ypos - Target's y position in VCS
 *              target_xvel - Target's x velocity in VCS
 *              target_yvel - Target's y velocity in VCS
 *              destination - Destination for the generated detections
 * Globals:     none
 * Abstract:    Generates detections for one synthetic target.
 * Reentrant:   NO
 */
void Generate_Detections(const volatile Sensor_Calib_Data_T &sensor, const volatile Sensor_Mount_Data_T &sensor_mount_data,
                         const float target_xpos, const float target_ypos, const float target_xvel, const float target_yvel,
                         const Stub_Det_Destination_T destination)
{
   float target_rel_xpos;
   float target_rel_ypos;
   Get_Sensor_Relative_Target_Position(sensor_mount_data, target_xpos, target_ypos, target_rel_xpos, target_rel_ypos);
   const F360_Det_Look_ID_T lookid = (F360_Det_Look_ID_T)p_stub_d2m->payload.downselection_data.det_list_property.look_type;
   const float az_vcs              = atan2f(target_rel_ypos, target_rel_xpos);
   const float az_sensor =
      fmodf((az_vcs - (NEG_FLOAT * sensor_mount_data.k_sensor_mount_ornt_yaw)) + 3.0F * F360_PI, 2.0F * F360_PI) - F360_PI;

   const float fov_min   = sensor.k_fov_hor_begin;
   const float fov_max   = sensor.k_fov_hor_end;
   const bool inside_fov = (fov_min <= fov_max) ? ((az_sensor >= fov_min) && (az_sensor <= fov_max)) :
                                                  ((az_sensor >= fov_min) || (az_sensor <= fov_max));
   bool f_moving         = !(target_xvel == 0.0F && target_yvel == 0.0F);

   if (inside_fov)
   {
      const bool write_partner = (destination == STUB_DET_DEST_PARTNER);
      int32_t thresh           = f_moving ? 220 : 170;
      int32_t &ndet            = write_partner ? p_stub_m2d->payload.partners_data.partner_sensor_det_data.num_af_det :
                                                 p_stub_d2m->payload.downselection_data.num_af_ds_det;
      const int32_t max_dets   = (write_partner) ? NUMBER_OF_PARTNER_DETECTIONS_EMB : NUMBER_OF_MAIN_DETECTIONS_EMB;
      float min_rr             = sensor.k_rdotmin;

      while ((RNG() < thresh) && (ndet < max_dets))
      {
         float range           = hypotf(target_rel_xpos, target_rel_ypos);
         const float inv_range = (range > 1.0e-6F) ? (1.0F / range) : 0.0F;
         float sensor_vx_vcs;
         float sensor_vy_vcs;
         Get_Sensor_Velocity_In_VCS(sensor_mount_data, p_stub_m2d->payload.veh_data.vse_output, sensor_vx_vcs, sensor_vy_vcs);
         const float target_rel_vx = target_xvel - sensor_vx_vcs;
         const float target_rel_vy = target_yvel - sensor_vy_vcs;
         float az                  = az_sensor;
         float range_rate          = ((target_rel_xpos * target_rel_vx) + (target_rel_ypos * target_rel_vy)) * inv_range;
         range_rate = fmodf(range_rate - min_rr + sensor.k_vwrapping[lookid] * 3.0F, sensor.k_vwrapping[lookid]) + min_rr;

         // Write_Generate_Detections_Debug_Row(sensor, sensor_mount_data, target_xpos, target_ypos, target_xvel, target_yvel,
         //                                    destination, target_rel_xpos, target_rel_ypos, az_vcs, az_sensor, inside_fov,
         //                                    f_moving, thresh, ndet, max_dets, range, inv_range, sensor_vx_vcs,
         //                                    sensor_vy_vcs, target_rel_vx, target_rel_vy, az, range_rate);

         if (stub_env_mode != STUB_ENV_MOIS_AL)
         {
            float az_noise         = static_cast<float>(RNG() % 70 - 35) / 4000.0F;
            float range_noise      = static_cast<float>(255 - thresh) / 100.0F;
            float range_rate_noise = static_cast<float>(RNG() - 128) / 5000.0F;
            az += az_noise;
            range += range_noise;
            range_rate += range_rate_noise;

            if (RNG() < 2)
            {
               /* angle jump 19.47 deg*/
               az += static_cast<float>(RNG() % 7 - 3) * (19.47F * DEG2RADF);
            }
         }
         if (write_partner)
         {
            p_stub_m2d->payload.partners_data.partner_sensor_det_data.ps_dets[ndet].ran   = range;
            p_stub_m2d->payload.partners_data.partner_sensor_det_data.ps_dets[ndet].vel   = range_rate;
            p_stub_m2d->payload.partners_data.partner_sensor_det_data.ps_dets[ndet].snr   = 8 + RNG() % 16;
            p_stub_m2d->payload.partners_data.partner_sensor_det_data.ps_dets[ndet].theta = az;
            p_stub_m2d->payload.partners_data.partner_sensor_det_data.ps_dets[ndet].rcs   = -5 + std::max(RNG() % 20, RNG() % 20);
            p_stub_m2d->payload.partners_data.partner_sensor_det_data.ps_dets[ndet].az_conf   = (RNG() < 5) ? 3 : 0;
            p_stub_m2d->payload.partners_data.partner_sensor_det_data.ps_dets[ndet].sensor_id = 2;
         }

         if (!write_partner)
         {
            p_stub_d2m->payload.downselection_data.af_ds_dets[ndet].ran     = range;
            p_stub_d2m->payload.downselection_data.af_ds_dets[ndet].vel     = range_rate;
            p_stub_d2m->payload.downselection_data.af_ds_dets[ndet].snr     = 8 + RNG() % 16;
            p_stub_d2m->payload.downselection_data.af_ds_dets[ndet].theta   = az;
            p_stub_d2m->payload.downselection_data.af_ds_dets[ndet].rcs     = -5 + std::max(RNG() % 20, RNG() % 20);
            p_stub_d2m->payload.downselection_data.af_ds_dets[ndet].az_conf = (RNG() < 5) ? 3 : 0;

            p_stub_d2m->payload.det_data.af_dets[ndet].ran     = p_stub_d2m->payload.downselection_data.af_ds_dets[ndet].ran;
            p_stub_d2m->payload.det_data.af_dets[ndet].vel     = p_stub_d2m->payload.downselection_data.af_ds_dets[ndet].vel;
            p_stub_d2m->payload.det_data.af_dets[ndet].snr     = p_stub_d2m->payload.downselection_data.af_ds_dets[ndet].snr;
            p_stub_d2m->payload.det_data.af_dets[ndet].theta   = p_stub_d2m->payload.downselection_data.af_ds_dets[ndet].theta;
            p_stub_d2m->payload.det_data.af_dets[ndet].rcs     = p_stub_d2m->payload.downselection_data.af_ds_dets[ndet].rcs;
            p_stub_d2m->payload.det_data.af_dets[ndet].az_conf = p_stub_d2m->payload.downselection_data.af_ds_dets[ndet].az_conf;
         }
         ndet++;

         /* update thresh*/
         if (f_moving)
         {
            thresh -= 50;
         }
         else
         {
            int32_t dist = static_cast<int32_t>(range);
            thresh       = (thresh == 255) ? (255 - dist) : 0;
         }
         thresh = std::max(thresh, 0);
      }

      if (!write_partner)
      {
         p_stub_d2m->payload.det_data.num_af_det = p_stub_d2m->payload.downselection_data.num_af_ds_det;
      }
   }
}

/*
 * Function:    Update_Dynamic_Env
 * Returns:     void
 * Parameters:  none
 * Globals:     none
 * Abstract:    Updates dynamic target states and emits detections for each target.
 * Reentrant:   NO
 */
void Update_Dynamic_Env(void)
{
   const int16_t num_targets_stationkeeping = 6;
   const int16_t num_targets_overtaking     = 10;
   const float max_longpos                  = 200.0F;
   const float min_longpos                  = -200.0F;
   const float range_longpos                = max_longpos - min_longpos;
   const float tgt_spacing_stationkeeping   = 40.0F;
   const float tgt_spacing_overtaking       = range_longpos / static_cast<float>(num_targets_overtaking);

   static float sk_xvel;
   static float ot_xvel;
   static float sk_cumul;
   static float ot_cumul;

   if (!F_Init_Complete)
   {
      F_Init_Complete = true;
      sk_xvel         = p_stub_m2d->payload.veh_data.vse_output.signed_filt_veh_speed_over_ground;
      ot_xvel         = p_stub_m2d->payload.veh_data.vse_output.signed_filt_veh_speed_over_ground + 3.0F;
      sk_cumul        = 0.0F;
      ot_cumul        = 0.0F;
   }

   sk_cumul += 0.05F * (sk_xvel - p_stub_m2d->payload.veh_data.vse_output.signed_filt_veh_speed_over_ground);
   sk_cumul += (sk_cumul < min_longpos) ? range_longpos : 0.0F;
   sk_cumul += (sk_cumul > max_longpos) ? -range_longpos : 0.0F;
   ot_cumul += 0.05F * (ot_xvel - p_stub_m2d->payload.veh_data.vse_output.signed_filt_veh_speed_over_ground);
   ot_cumul += (ot_cumul < min_longpos) ? range_longpos : 0.0F;
   ot_cumul += (ot_cumul > max_longpos) ? -range_longpos : 0.0F;
   for (uint8_t sensor_index = 0; sensor_index < MAX_NUMBER_OF_SENSORS; sensor_index++)
   {
      const Stub_Det_Destination_T destination = (sensor_index == 0) ? STUB_DET_DEST_MAIN : STUB_DET_DEST_PARTNER;

      for (int16_t i = 0; i < num_targets_stationkeeping / 2; i++)
      {
         const float tgt_longpos = tgt_spacing_stationkeeping * static_cast<float>(i + 1);
         float pos_p             = tgt_longpos + sk_cumul;
         pos_p += (pos_p < min_longpos) ? range_longpos : 0.0F;
         pos_p += (pos_p > max_longpos) ? -range_longpos : 0.0F;
         float pos_n = -tgt_longpos + sk_cumul;
         pos_n += (pos_n < min_longpos) ? range_longpos : 0.0F;
         pos_n += (pos_n > max_longpos) ? -range_longpos : 0.0F;

         if (destination == STUB_DET_DEST_PARTNER)
         {
            Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data, Get_Partner_Mount_Data(sensor_index), pos_p,
                                0.0F, sk_xvel, 0.0F, destination);
            Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data, Get_Partner_Mount_Data(sensor_index), pos_n,
                                0.0F, sk_xvel, 0.0F, destination);
         }
         else
         {
            Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data,
                                p_stub_m2d_one_time->calib_data.sensor_calib_data.sensor_mount_data, pos_p, 0.0F, sk_xvel, 0.0F,
                                destination);
            Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data,
                                p_stub_m2d_one_time->calib_data.sensor_calib_data.sensor_mount_data, pos_n, 0.0F, sk_xvel, 0.0F,
                                destination);
         }
      }
   }
   for (uint8_t sensor_index = 0; sensor_index < MAX_NUMBER_OF_SENSORS; sensor_index++)
   {
      const Stub_Det_Destination_T destination = (sensor_index == 0) ? STUB_DET_DEST_MAIN : STUB_DET_DEST_PARTNER;

      for (int16_t i = 0; i < num_targets_overtaking; i++)
      {
         const float init_pos = max_longpos - tgt_spacing_overtaking * static_cast<float>(i);
         float pos            = init_pos + ot_cumul;
         pos += (pos < min_longpos) ? range_longpos : 0.0F;
         pos += (pos > max_longpos) ? -range_longpos : 0.0F;

         if (destination == STUB_DET_DEST_PARTNER)
         {
            Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data, Get_Partner_Mount_Data(sensor_index), pos,
                                -3.0F, ot_xvel, 0.0F, destination);
         }
         else
         {
            Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data,
                                p_stub_m2d_one_time->calib_data.sensor_calib_data.sensor_mount_data, pos, -3.0F, ot_xvel, 0.0F,
                                destination);
         }
      }
   }
}

/*
 * Function:    Update_Env_mois
 * Returns:     void
 * Parameters:  none
 * Globals:     none
 * Abstract:    Updates target states and emits detections for MOIS-specific test cases.
 * Reentrant:   NO
 */
static void Update_Env_mois()
{
   const int16_t num_targets = 2;
   static float target_xpos[num_targets];
   static float target_ypos[num_targets];
   static float target_xvel[num_targets];
   static float target_yvel[num_targets];
   const float max_latpos = 1.5F;
   const float min_latpos = -1.5F;

   if (!F_Init_Complete)
   {
      F_Init_Complete         = true;
      const float tgt_spacing = (max_latpos - min_latpos) / static_cast<float>(num_targets / 2);
      for (int16_t i = 0; i < num_targets / 2; i++)
      {
         const int16_t tgt1     = i * 2;
         const int16_t tgt2     = i * 2 + 1;
         const float tgt_latpos = max_latpos - tgt_spacing * static_cast<float>(i);
         target_xpos[tgt1]      = 1.0;
         target_xpos[tgt2]      = 1.0;
         target_ypos[tgt1]      = tgt_latpos;
         target_ypos[tgt2]      = tgt_latpos - 0.01;
         target_xvel[tgt1]      = 0.0;
         target_yvel[tgt1]      = 0.9f;
         target_xvel[tgt2]      = 0.0;
         target_yvel[tgt2]      = 0.9f;
      }
   }

   for (int16_t i = 0; i < num_targets; i++)
   {
      const float dy = 0.05F * target_yvel[i];
      target_ypos[i] += dy;

      if (target_ypos[i] > max_latpos)
      {
         target_ypos[i] -= (max_latpos - min_latpos);
      }
      if (target_ypos[i] < min_latpos)
      {
         target_ypos[i] += (max_latpos - min_latpos);
      }
   }

   for (int16_t i = 0; i < num_targets; i++)
   {
      Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data,
                          p_stub_m2d_one_time->calib_data.sensor_calib_data.sensor_mount_data, target_xpos[i], target_ypos[i],
                          target_xvel[i], target_yvel[i], STUB_DET_DEST_MAIN);
   }
}

/*
 * Function:    Update_Static_Env
 * Returns:     void
 * Parameters:  none
 * Globals:     none
 * Abstract:    Updates target states and emits detections for static test cases.
 * Reentrant:   NO
 */
void Update_Static_Env(void)
{
   const int16_t num_pairs   = 400;
   const float max_longpos   = 250.0F;
   const float min_longpos   = -250.0F;
   const float range_longpos = max_longpos - min_longpos;
   const float tgt_spacing   = range_longpos / static_cast<float>(num_pairs / 2);

   static float x_cumul;
   static bool F_Init_Complete = false;

   if (!F_Init_Complete)
   {
      F_Init_Complete = true;
      x_cumul         = 0.0F;
   }

   x_cumul += 0.05F * -p_stub_m2d->payload.veh_data.vse_output.signed_filt_veh_speed_over_ground;
   x_cumul += (x_cumul < min_longpos) ? range_longpos : 0.0F;
   x_cumul += (x_cumul > max_longpos) ? -range_longpos : 0.0F;
   for (uint8_t sensor_index = 0; sensor_index < MAX_NUMBER_OF_SENSORS; sensor_index++)
   {
      const Stub_Det_Destination_T destination = (sensor_index == 0) ? STUB_DET_DEST_MAIN : STUB_DET_DEST_PARTNER;

      for (int16_t i = 0; i < num_pairs; i++)
      {
         const float tgt_longpos =
            ((i == 0) ? 0.0F : (((i % 2) != 0) ? static_cast<float>((i + 1) / 2) : -static_cast<float>(i / 2))) * tgt_spacing;
         float xpos = tgt_longpos + x_cumul;
         xpos += (xpos < min_longpos) ? range_longpos : 0.0F;
         xpos += (xpos > max_longpos) ? -range_longpos : 0.0F;

         if (destination == STUB_DET_DEST_PARTNER)
         {
            Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data, Get_Partner_Mount_Data(sensor_index), xpos,
                                -6.0F, 0.0F, 0.0F, destination);
            Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data, Get_Partner_Mount_Data(sensor_index), xpos,
                                2.0F, 0.0F, 0.0F, destination);
         }
         else
         {
            Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data,
                                p_stub_m2d_one_time->calib_data.sensor_calib_data.sensor_mount_data, xpos, -6.0F, 0.0F, 0.0F,
                                destination);
            Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data,
                                p_stub_m2d_one_time->calib_data.sensor_calib_data.sensor_mount_data, xpos, 2.0F, 0.0F, 0.0F,
                                destination);
         }
      }
   }
}

/*
 * Function:    Mois_Test_Cases
 * Returns:     void
 * Parameters:  none
 * Globals:     none
 * Abstract:    Updates target states and emits detections for MOIS-specific test cases based on the selected test case in the
 * simulation environment. Reentrant:   NO
 */
static void Mois_Test_Cases()
{
   static Mois_Test_Case_Selection_T test_case_state = static_cast<Mois_Test_Case_Selection_T>(DEFAULT_TRACKER_TEST_CASE);

   if (test_case_state != static_cast<Mois_Test_Case_Selection_T>(Get_Simulation_Test_Case()))
   {
      F_Init_Complete = false;
      test_case_state = static_cast<Mois_Test_Case_Selection_T>(Get_Simulation_Test_Case());
   }

   switch (Get_Simulation_Test_Case())
   {
      case DEFAULT_TRACKER_TEST_CASE:
         Update_Env_mois();
         break;
      case MOIS_CLOSE_PROXI_TP_L_TO_R_TEST_CASE:
         Mois_Close_Proxi_TP_L_to_R_Test_Case();
         break;

      case MOIS_CLOSE_PROXI_TP_R_TO_L_TEST_CASE:
         Mois_Close_Proxi_TP_R_to_L_Test_Case();
         break;

      case MOIS_NORMAL_PROXI_TP_L_TO_R_TEST_CASE:
         Mois_Normal_Proxi_TP_L_to_R_Test_Case();
         break;

      case MOIS_NORMAL_PROXI_TP_R_TO_L_TEST_CASE:
         Mois_Normal_Proxi_TP_R_to_L_Test_Case();
         break;

      case MOIS_FAR_PROXI_TN_L_TO_R_TEST_CASE:
         Mois_Far_Proxi_TN_L_to_R_Test_Case();
         break;

      case MOIS_FAR_PROXI_TN_R_TO_L_TEST_CASE:
         Mois_Far_Proxi_TN_R_to_L_Test_Case();
         break;

      case MOIS_OBJECT_DRIVE_FRONT:
         Mois_Object_Drive_Front();
         break;

      default:
         Update_Env_mois();
         break;
   }

   if ((Feature_Target_Simulated.tgt_ypos > 5.0f) || (Feature_Target_Simulated.tgt_ypos < -5.0f))
   {
      F_Init_Complete = false;
   }
}
/*
 * Function:    Bsis_Test_Cases
 * Returns:     void
 * Parameters:  none
 * Globals:     none
 * Abstract:    Updates target states and emits detections for BSIS-specific test cases based on the selected test case in the
 * simulation environment. Reentrant:   NO
 */
static void Bsis_Test_Cases()
{
   static Bsis_Test_Case_Selection_T test_case_state = static_cast<Bsis_Test_Case_Selection_T>(DEFAULT_TRACKER_TEST_CASE);

   if (test_case_state != static_cast<Bsis_Test_Case_Selection_T>(Get_Simulation_Test_Case()))
   {
      F_Init_Complete = false;
      test_case_state = static_cast<Bsis_Test_Case_Selection_T>(Get_Simulation_Test_Case());
   }

   switch (Get_Simulation_Test_Case())
   {
      case DEFAULT_TRACKER_TEST_CASE:

         Update_Dynamic_Env();
         break;

      case BSIS_TOS_TP_TEST_CASE:
         Bsis_Tos_TP_Test_Case();
         break;

      case BSIS_SOT_TP_TEST_CASE:
         Bsis_Sot_TP_Test_Case();
         break;

      case BSIS_TOS_TN_TEST_CASE:
         Bsis_Tos_TN_Test_Case();
         break;

      case BSIS_SOT_TN_TEST_CASE:
         Bsis_Sot_TN_Test_Case();
         break;

      case BSIS_OBJECT_ENTERS_AND_STAY_IN_ZONE:
         Bsis_Object_Enters_And_Stay_In_Zone();
         break;

      default:
         Update_Dynamic_Env();
         break;
   }

   if ((Feature_Target_Simulated.tgt_xpos > 50.0f) || (Feature_Target_Simulated.tgt_xpos < -50.0f))
   {
      F_Init_Complete = false;
   }
}
/*
 * Function:    Bsis_Tos_TP_Test_Case
 * Returns:     void
 * Parameters:  none
 * Globals:     none
 * Abstract:    Updates target states and emits detections for BSIS-specific test cases based on the selected test case in the
 * simulation environment. Reentrant:   NO
 */
void Bsis_Tos_TP_Test_Case()
{
   if (!F_Init_Complete)
   {
      F_Init_Complete                   = true;
      Feature_Target_Simulated.tgt_xpos = -50.0f;
      Feature_Target_Simulated.tgt_ypos = -3.0f;
      Feature_Target_Simulated.tgt_xvel = 2.78f + p_stub_m2d->payload.veh_data.vse_output.signed_filt_veh_speed_over_ground;
      Feature_Target_Simulated.tgt_yvel = 0.0f;
   }

   Feature_Target_Simulated.tgt_xpos +=
      0.05F * (Feature_Target_Simulated.tgt_xvel - p_stub_m2d->payload.veh_data.vse_output.signed_filt_veh_speed_over_ground);

   for (uint8_t sensor_index = 0; sensor_index < MAX_NUMBER_OF_SENSORS; sensor_index++)
   {
      const Stub_Det_Destination_T destination = (sensor_index == 0) ? STUB_DET_DEST_MAIN : STUB_DET_DEST_PARTNER;

      if (destination == STUB_DET_DEST_PARTNER)
      {
         Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data, Get_Partner_Mount_Data(sensor_index),
                             Feature_Target_Simulated.tgt_xpos, Feature_Target_Simulated.tgt_ypos,
                             Feature_Target_Simulated.tgt_xvel, Feature_Target_Simulated.tgt_yvel, destination);
      }
      else
      {
         Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data,
                             p_stub_m2d_one_time->calib_data.sensor_calib_data.sensor_mount_data,
                             Feature_Target_Simulated.tgt_xpos, Feature_Target_Simulated.tgt_ypos,
                             Feature_Target_Simulated.tgt_xvel, Feature_Target_Simulated.tgt_yvel, destination);
      }
   }
}
/*
 * Function:    Bsis_Sot_TP_Test_Case
 * Returns:     void
 * Parameters:  none
 * Globals:     none
 * Abstract:    Updates target states and emits detections for BSIS-specific test cases based on the selected test case in the
 * simulation environment. Reentrant:   NO
 */
void Bsis_Sot_TP_Test_Case()
{
   if (!F_Init_Complete)
   {
      F_Init_Complete                   = true;
      Feature_Target_Simulated.tgt_xpos = 4.0f;
      Feature_Target_Simulated.tgt_ypos = -3.0f;
      Feature_Target_Simulated.tgt_xvel = 1.5f;
      Feature_Target_Simulated.tgt_yvel = 0.0f;
   }

   Feature_Target_Simulated.tgt_xpos += 0.05F * (-1.0f * Feature_Target_Simulated.tgt_xvel);

   for (uint8_t sensor_index = 0; sensor_index < MAX_NUMBER_OF_SENSORS; sensor_index++)
   {
      const Stub_Det_Destination_T destination = (sensor_index == 0) ? STUB_DET_DEST_MAIN : STUB_DET_DEST_PARTNER;

      if (destination == STUB_DET_DEST_PARTNER)
      {
         Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data, Get_Partner_Mount_Data(sensor_index),
                             Feature_Target_Simulated.tgt_xpos, Feature_Target_Simulated.tgt_ypos,
                             Feature_Target_Simulated.tgt_xvel, Feature_Target_Simulated.tgt_yvel, destination);
      }
      else
      {
         Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data,
                             p_stub_m2d_one_time->calib_data.sensor_calib_data.sensor_mount_data,
                             Feature_Target_Simulated.tgt_xpos, Feature_Target_Simulated.tgt_ypos,
                             Feature_Target_Simulated.tgt_xvel, Feature_Target_Simulated.tgt_yvel, destination);
      }
   }
}
/*
 * Function:    Bsis_Tos_TN_Test_Case
 * Returns:     void
 * Parameters:  none
 * Globals:     none
 * Abstract:    Updates target states and emits detections for BSIS-specific test cases based on the selected test case in the
 * simulation environment. Reentrant:   NO
 */
void Bsis_Tos_TN_Test_Case()
{
   if (!F_Init_Complete)
   {
      F_Init_Complete                   = true;
      Feature_Target_Simulated.tgt_xpos = -50.0f;
      Feature_Target_Simulated.tgt_ypos = -8.0f;
      Feature_Target_Simulated.tgt_xvel = 2.78f + p_stub_m2d->payload.veh_data.vse_output.signed_filt_veh_speed_over_ground;
      Feature_Target_Simulated.tgt_yvel = 0.0f;
   }

   Feature_Target_Simulated.tgt_xpos +=
      0.05F * (Feature_Target_Simulated.tgt_xvel - p_stub_m2d->payload.veh_data.vse_output.signed_filt_veh_speed_over_ground);

   for (uint8_t sensor_index = 0; sensor_index < MAX_NUMBER_OF_SENSORS; sensor_index++)
   {
      const Stub_Det_Destination_T destination = (sensor_index == 0) ? STUB_DET_DEST_MAIN : STUB_DET_DEST_PARTNER;

      if (destination == STUB_DET_DEST_PARTNER)
      {
         Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data, Get_Partner_Mount_Data(sensor_index),
                             Feature_Target_Simulated.tgt_xpos, Feature_Target_Simulated.tgt_ypos,
                             Feature_Target_Simulated.tgt_xvel, Feature_Target_Simulated.tgt_yvel, destination);
      }
      else
      {
         Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data,
                             p_stub_m2d_one_time->calib_data.sensor_calib_data.sensor_mount_data,
                             Feature_Target_Simulated.tgt_xpos, Feature_Target_Simulated.tgt_ypos,
                             Feature_Target_Simulated.tgt_xvel, Feature_Target_Simulated.tgt_yvel, destination);
      }
   }
}
/*
 * Function:    Bsis_Sot_TN_Test_Case
 * Returns:     void
 * Parameters:  none
 * Globals:     none
 * Abstract:    Updates target states and emits detections for BSIS-specific test cases based on the selected test case in the
 * simulation environment. Reentrant:   NO
 */
void Bsis_Sot_TN_Test_Case()
{
   if (!F_Init_Complete)
   {
      F_Init_Complete                   = true;
      Feature_Target_Simulated.tgt_xpos = 4.0f;
      Feature_Target_Simulated.tgt_ypos = -8.0f;
      Feature_Target_Simulated.tgt_xvel = 1.5f;
      Feature_Target_Simulated.tgt_yvel = 0.0f;
   }

   Feature_Target_Simulated.tgt_xpos += 0.05F * (-1.0f * Feature_Target_Simulated.tgt_xvel);

   for (uint8_t sensor_index = 0; sensor_index < MAX_NUMBER_OF_SENSORS; sensor_index++)
   {
      const Stub_Det_Destination_T destination = (sensor_index == 0) ? STUB_DET_DEST_MAIN : STUB_DET_DEST_PARTNER;

      if (destination == STUB_DET_DEST_PARTNER)
      {
         Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data, Get_Partner_Mount_Data(sensor_index),
                             Feature_Target_Simulated.tgt_xpos, Feature_Target_Simulated.tgt_ypos,
                             Feature_Target_Simulated.tgt_xvel, Feature_Target_Simulated.tgt_yvel, destination);
      }
      else
      {
         Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data,
                             p_stub_m2d_one_time->calib_data.sensor_calib_data.sensor_mount_data,
                             Feature_Target_Simulated.tgt_xpos, Feature_Target_Simulated.tgt_ypos,
                             Feature_Target_Simulated.tgt_xvel, Feature_Target_Simulated.tgt_yvel, destination);
      }
   }
}
/*
 * Function:    Bsis_Object_Enters_And_Stay_In_Zone
 * Returns:     void
 * Parameters:  none
 * Globals:     none
 * Abstract:    Updates target states and emits detections for BSIS-specific test cases based on the selected test case in the
 * simulation environment. Reentrant:   NO
 */
void Bsis_Object_Enters_And_Stay_In_Zone()
{
   if (!F_Init_Complete)
   {
      F_Init_Complete                   = true;
      Feature_Target_Simulated.tgt_xpos = -50.0f;
      Feature_Target_Simulated.tgt_ypos = -3.0f;
      Feature_Target_Simulated.tgt_xvel = 2.78f + p_stub_m2d->payload.veh_data.vse_output.signed_filt_veh_speed_over_ground;
      Feature_Target_Simulated.tgt_yvel = 0.0f;
   }

   if (Feature_Target_Simulated.tgt_xpos > -6.0f)
   {
      Feature_Target_Simulated.tgt_xvel = p_stub_m2d->payload.veh_data.vse_output.signed_filt_veh_speed_over_ground + 0.01f;
      Feature_Target_Simulated.tgt_xpos +=
         0.05F * (Feature_Target_Simulated.tgt_xvel - p_stub_m2d->payload.veh_data.vse_output.signed_filt_veh_speed_over_ground);
   }
   else
   {
      Feature_Target_Simulated.tgt_xpos +=
         0.05F * (Feature_Target_Simulated.tgt_xvel - p_stub_m2d->payload.veh_data.vse_output.signed_filt_veh_speed_over_ground);
   }

   for (uint8_t sensor_index = 0; sensor_index < MAX_NUMBER_OF_SENSORS; sensor_index++)
   {
      const Stub_Det_Destination_T destination = (sensor_index == 0) ? STUB_DET_DEST_MAIN : STUB_DET_DEST_PARTNER;

      if (destination == STUB_DET_DEST_PARTNER)
      {
         Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data, Get_Partner_Mount_Data(sensor_index),
                             Feature_Target_Simulated.tgt_xpos, Feature_Target_Simulated.tgt_ypos,
                             Feature_Target_Simulated.tgt_xvel, Feature_Target_Simulated.tgt_yvel, destination);
      }
      else
      {
         Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data,
                             p_stub_m2d_one_time->calib_data.sensor_calib_data.sensor_mount_data,
                             Feature_Target_Simulated.tgt_xpos, Feature_Target_Simulated.tgt_ypos,
                             Feature_Target_Simulated.tgt_xvel, Feature_Target_Simulated.tgt_yvel, destination);
      }
   }
}
/*
 * Function:    Mois_Close_Proxi_TP_L_to_R_Test_Case
 * Returns:     void
 * Parameters:  none
 * Globals:     none
 * Abstract:    Updates target states and emits detections for BSIS-specific test cases based on the selected test case in the
 * simulation environment. Reentrant:   NO
 */
void Mois_Close_Proxi_TP_L_to_R_Test_Case()
{
   if (!F_Init_Complete)
   {
      F_Init_Complete                   = true;
      Feature_Target_Simulated.tgt_xpos = 0.8f;
      Feature_Target_Simulated.tgt_ypos = -5.0f;
      Feature_Target_Simulated.tgt_xvel = 0.0f;
      Feature_Target_Simulated.tgt_yvel = 0.5f;
   }

   Feature_Target_Simulated.tgt_ypos += 0.05F * (Feature_Target_Simulated.tgt_yvel);

   Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data,
                       p_stub_m2d_one_time->calib_data.sensor_calib_data.sensor_mount_data, Feature_Target_Simulated.tgt_xpos,
                       Feature_Target_Simulated.tgt_ypos, Feature_Target_Simulated.tgt_xvel, Feature_Target_Simulated.tgt_yvel,
                       STUB_DET_DEST_MAIN);
}
/*
 * Function:    Mois_Close_Proxi_TP_R_to_L_Test_Case
 * Returns:     void
 * Parameters:  none
 * Globals:     none
 * Abstract:    Updates target states and emits detections for BSIS-specific test cases based on the selected test case in the
 * simulation environment. Reentrant:   NO
 */
void Mois_Close_Proxi_TP_R_to_L_Test_Case()
{
   if (!F_Init_Complete)
   {
      F_Init_Complete                   = true;
      Feature_Target_Simulated.tgt_xpos = 0.8f;
      Feature_Target_Simulated.tgt_ypos = 5.0f;
      Feature_Target_Simulated.tgt_xvel = 0.0f;
      Feature_Target_Simulated.tgt_yvel = -0.5f;
   }

   Feature_Target_Simulated.tgt_ypos += 0.05F * (Feature_Target_Simulated.tgt_yvel);

   Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data,
                       p_stub_m2d_one_time->calib_data.sensor_calib_data.sensor_mount_data, Feature_Target_Simulated.tgt_xpos,
                       Feature_Target_Simulated.tgt_ypos, Feature_Target_Simulated.tgt_xvel, Feature_Target_Simulated.tgt_yvel,
                       STUB_DET_DEST_MAIN);
}
/*
 * Function:    Mois_Normal_Proxi_TP_L_to_R_Test_Case
 * Returns:     void
 * Parameters:  none
 * Globals:     none
 * Abstract:    Updates target states and emits detections for BSIS-specific test cases based on the selected test case in the
 * simulation environment. Reentrant:   NO
 */
void Mois_Normal_Proxi_TP_L_to_R_Test_Case()
{
   if (!F_Init_Complete)
   {
      F_Init_Complete                   = true;
      Feature_Target_Simulated.tgt_xpos = 3.0f;
      Feature_Target_Simulated.tgt_ypos = -5.0f;
      Feature_Target_Simulated.tgt_xvel = 0.0f;
      Feature_Target_Simulated.tgt_yvel = 0.5f;
   }

   Feature_Target_Simulated.tgt_ypos += 0.05F * (Feature_Target_Simulated.tgt_yvel);

   Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data,
                       p_stub_m2d_one_time->calib_data.sensor_calib_data.sensor_mount_data, Feature_Target_Simulated.tgt_xpos,
                       Feature_Target_Simulated.tgt_ypos, Feature_Target_Simulated.tgt_xvel, Feature_Target_Simulated.tgt_yvel,
                       STUB_DET_DEST_MAIN);
}
/*
 * Function:    Mois_Normal_Proxi_TP_R_to_L_Test_Case
 * Returns:     void
 * Parameters:  none
 * Globals:     none
 * Abstract:    Updates target states and emits detections for BSIS-specific test cases based on the selected test case in the
 * simulation environment. Reentrant:   NO
 */
void Mois_Normal_Proxi_TP_R_to_L_Test_Case()
{
   if (!F_Init_Complete)
   {
      F_Init_Complete                   = true;
      Feature_Target_Simulated.tgt_xpos = 3.0f;
      Feature_Target_Simulated.tgt_ypos = 5.0f;
      Feature_Target_Simulated.tgt_xvel = 0.0f;
      Feature_Target_Simulated.tgt_yvel = -0.5f;
   }

   Feature_Target_Simulated.tgt_ypos += 0.05F * (Feature_Target_Simulated.tgt_yvel);

   Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data,
                       p_stub_m2d_one_time->calib_data.sensor_calib_data.sensor_mount_data, Feature_Target_Simulated.tgt_xpos,
                       Feature_Target_Simulated.tgt_ypos, Feature_Target_Simulated.tgt_xvel, Feature_Target_Simulated.tgt_yvel,
                       STUB_DET_DEST_MAIN);
}
/*
 * Function:    Mois_Far_Proxi_TN_L_to_R_Test_Case
 * Returns:     void
 * Parameters:  none
 * Globals:     none
 * Abstract:    Updates target states and emits detections for BSIS-specific test cases based on the selected test case in the
 * simulation environment. Reentrant:   NO
 */
void Mois_Far_Proxi_TN_L_to_R_Test_Case()
{
   if (!F_Init_Complete)
   {
      F_Init_Complete                   = true;
      Feature_Target_Simulated.tgt_xpos = 5.0f;
      Feature_Target_Simulated.tgt_ypos = -5.0f;
      Feature_Target_Simulated.tgt_xvel = 0.0f;
      Feature_Target_Simulated.tgt_yvel = 0.5f;
   }
   Feature_Target_Simulated.tgt_ypos += 0.05F * (Feature_Target_Simulated.tgt_yvel);

   Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data,
                       p_stub_m2d_one_time->calib_data.sensor_calib_data.sensor_mount_data, Feature_Target_Simulated.tgt_xpos,
                       Feature_Target_Simulated.tgt_ypos, Feature_Target_Simulated.tgt_xvel, Feature_Target_Simulated.tgt_yvel,
                       STUB_DET_DEST_MAIN);
}
/*
 * Function:    Mois_Far_Proxi_TN_R_to_L_Test_Case
 * Returns:     void
 * Parameters:  none
 * Globals:     none
 * Abstract:    Updates target states and emits detections for BSIS-specific test cases based on the selected test case in the
 * simulation environment. Reentrant:   NO
 */
void Mois_Far_Proxi_TN_R_to_L_Test_Case()
{
   if (!F_Init_Complete)
   {
      F_Init_Complete                   = true;
      Feature_Target_Simulated.tgt_xpos = 5.0f;
      Feature_Target_Simulated.tgt_ypos = 5.0f;
      Feature_Target_Simulated.tgt_xvel = 0.0f;
      Feature_Target_Simulated.tgt_yvel = -0.5f;
   }

   Feature_Target_Simulated.tgt_ypos += 0.05F * (Feature_Target_Simulated.tgt_yvel);

   Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data,
                       p_stub_m2d_one_time->calib_data.sensor_calib_data.sensor_mount_data, Feature_Target_Simulated.tgt_xpos,
                       Feature_Target_Simulated.tgt_ypos, Feature_Target_Simulated.tgt_xvel, Feature_Target_Simulated.tgt_yvel,
                       STUB_DET_DEST_MAIN);
}
/*
 * Function:    Mois_Object_Drive_Front
 * Returns:     void
 * Parameters:  none
 * Globals:     none
 * Abstract:    Updates target states and emits detections for BSIS-specific test cases based on the selected test case in the
 * simulation environment. Reentrant:   NO
 */
void Mois_Object_Drive_Front()
{
   if (!F_Init_Complete)
   {
      F_Init_Complete                   = true;
      Feature_Target_Simulated.tgt_xpos = 3.0f;
      Feature_Target_Simulated.tgt_ypos = 0.0f;
      Feature_Target_Simulated.tgt_xvel = p_stub_m2d->payload.veh_data.vse_output.signed_filt_veh_speed_over_ground + 0.01f;
      Feature_Target_Simulated.tgt_yvel = 0.0f;
   }

   Feature_Target_Simulated.tgt_xpos +=
      0.05F * (Feature_Target_Simulated.tgt_xvel - p_stub_m2d->payload.veh_data.vse_output.signed_filt_veh_speed_over_ground);

   Generate_Detections(p_stub_m2d_one_time->calib_data.sensor_calib_data,
                       p_stub_m2d_one_time->calib_data.sensor_calib_data.sensor_mount_data, Feature_Target_Simulated.tgt_xpos,
                       Feature_Target_Simulated.tgt_ypos, Feature_Target_Simulated.tgt_xvel, Feature_Target_Simulated.tgt_yvel,
                       STUB_DET_DEST_MAIN);
}
