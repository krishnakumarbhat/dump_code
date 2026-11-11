#include <algorithm>
#include <array>
#include <cmath>
#include <cstring>

#include "emb_tracker_project_parameters.h"
#include "emblib_ipc_data.h"
#include "sil_radar_fusion_delay.h"
#include "sil_symbol_wrapper.h"
#include "sil_symbol_wrapper_internal.h"
#include "sil_wrapper_common.h"
#include "statistical_report.h"

static bool Steering_Whl_Angle_Initialized   = false;
static float32_t Prev_Steering_Whl_Angle_Deg = 0.0F;

#define RAD_TO_DEG_F32 (57.2957795F)
/* Runnable execution period for CAN RX processing (25 ms). */
#define COMM_RX_PERIOD_SEC (0.025F)

namespace sil_symbol_wrapper_internal
{
struct Radar_Symbol_Map_T
{
   Radar_Position radar_position                                      = UNKNOWN_POSITION;
   MOUNTING_VALUES_XML_T SIL_RADAR_Input_Symbol_T::*mounting_member   = nullptr;
   Detection_Data_Input_T SIL_RADAR_Input_Symbol_T::*detection_member = nullptr;
};

Radar_Position resolve_partner_radar_position(Radar_Position self_radar_position)
{
#if defined(AL_TRACKER)
   switch (self_radar_position)
   {
      case REAR_LEFT:
         return FRONT_LEFT;
      case FRONT_LEFT:
         return REAR_LEFT;
      case REAR_RIGHT:
         return FRONT_RIGHT;
      case FRONT_RIGHT:
         return REAR_RIGHT;
      case FRONT_CENTER:
         return FRONT_CENTER;
      default:
         return UNKNOWN_POSITION;
   }
#elif defined(PLATFORM_SRR8P_2_SENSOR_FUSION)
   switch (self_radar_position)
   {
      case REAR_LEFT:
         return REAR_RIGHT;
      case REAR_RIGHT:
         return REAR_LEFT;
      case FRONT_LEFT:
         return FRONT_RIGHT;
      case FRONT_RIGHT:
         return FRONT_LEFT;
      default:
         return UNKNOWN_POSITION;
   }
#else
   (void)self_radar_position;
   return UNKNOWN_POSITION;
#endif
}

const Radar_Symbol_Map_T *find_radar_symbol_map(Radar_Position radar_position)
{
   static constexpr std::array<Radar_Symbol_Map_T, 8> k_radar_symbol_map = {{
      {REAR_LEFT, &SIL_RADAR_Input_Symbol_T::Mounting_Values_RL, &SIL_RADAR_Input_Symbol_T::detection_rl_radar},
      {REAR_RIGHT, &SIL_RADAR_Input_Symbol_T::Mounting_Values_RR, &SIL_RADAR_Input_Symbol_T::detection_rr_radar},
      {FRONT_RIGHT, &SIL_RADAR_Input_Symbol_T::Mounting_Values_FR, &SIL_RADAR_Input_Symbol_T::detection_fr_radar},
      {FRONT_LEFT, &SIL_RADAR_Input_Symbol_T::Mounting_Values_FL, &SIL_RADAR_Input_Symbol_T::detection_fl_radar},
      {FRONT_CENTER, &SIL_RADAR_Input_Symbol_T::Mounting_Values_FC, &SIL_RADAR_Input_Symbol_T::detection_fc_radar},
      {REAR_CENTER, &SIL_RADAR_Input_Symbol_T::Mounting_Values_RC, &SIL_RADAR_Input_Symbol_T::detection_rc_radar},
      {RIGHT_CENTER, &SIL_RADAR_Input_Symbol_T::Mounting_Values_BR, &SIL_RADAR_Input_Symbol_T::detection_br_radar},
      {LEFT_CENTER, &SIL_RADAR_Input_Symbol_T::Mounting_Values_BL, &SIL_RADAR_Input_Symbol_T::detection_bl_radar},
   }};

   const auto map_it =
      std::find_if(k_radar_symbol_map.cbegin(), k_radar_symbol_map.cend(),
                   [radar_position](const Radar_Symbol_Map_T &map_entry) { return map_entry.radar_position == radar_position; });

   if (map_it == k_radar_symbol_map.cend())
   {
      return nullptr;
   }

   return &(*map_it);
}

const Vehicle_Data_Input_T *get_vehicle_input(const SIL_RADAR_Input_Symbol_T *symbol_input, Radar_Position radar_position)
{
   if ((symbol_input == nullptr) || (radar_position <= UNKNOWN_POSITION) || (radar_position >= INVALID_POSITION))
   {
      return nullptr;
   }

   return &symbol_input->vehicle_inputs[static_cast<size_t>(radar_position - 1U)];
}

Radar_Symbol_Context_T resolve_radar_symbol_context(const SIL_RADAR_Input_Symbol_T *symbol_input,
                                                    Radar_Position self_radar_position)
{
   Radar_Symbol_Context_T context     = {};
   const Radar_Symbol_Map_T *self_map = find_radar_symbol_map(self_radar_position);

   context.self_radar_position = self_radar_position;
   context.vehicle_input       = get_vehicle_input(symbol_input, self_radar_position);

   if ((symbol_input == nullptr) || (self_map == nullptr))
   {
      return context;
   }

   context.partner_radar_position = resolve_partner_radar_position(self_radar_position);
   context.self_mounting          = &(symbol_input->*(self_map->mounting_member));
   context.self_detection         = &(symbol_input->*(self_map->detection_member));

   const Radar_Symbol_Map_T *partner_map = find_radar_symbol_map(context.partner_radar_position);
   if (partner_map != nullptr)
   {
      context.partner_mounting  = &(symbol_input->*(partner_map->mounting_member));
      context.partner_detection = &(symbol_input->*(partner_map->detection_member));
   }

   return context;
}

void populate_ipc_dynamic_alignment_log_stream_with_symbol_data(Dynamic_Alignment_Log_Stream_T *da_log_stream_ptr,
                                                                const MOUNTING_VALUES_XML_T *mounting_values)
{
   assert(da_log_stream_ptr != nullptr);
   assert(mounting_values != nullptr);

   da_log_stream_ptr->dra_core_data.vacs_boresight_az_estimated         = mounting_values->boresight_angle * DEG2RAD_SIL;
   da_log_stream_ptr->dra_core_data.vacs_boresight_el_estimated         = 0.0F;
   da_log_stream_ptr->dra_core_data.alignment_mode                      = 0x1;
   da_log_stream_ptr->dra_core_data.speed_compensation_factor_estimated = 1;
}

void populate_ipc_rdd_stream_with_symbol_data(Rdd_Stream_T *rdd_stream_ptr, const Detection_Data_Input_T *detection_data_input)
{
   assert(rdd_stream_ptr != nullptr);
   assert(detection_data_input != nullptr);

   rdd_stream_ptr->look_data.start_dwell_status = 1;
   rdd_stream_ptr->look_data.start_dwell_sec    = static_cast<uint32_t>(detection_data_input->dets_info.timestamp / 1000);
   rdd_stream_ptr->look_data.start_dwell_nanosec =
      static_cast<uint32_t>((static_cast<uint32_t>(detection_data_input->dets_info.timestamp) % 1000) * 1000000);
   rdd_stream_ptr->look_data.mid_dwell_status  = 1;
   rdd_stream_ptr->look_data.mid_dwell_sec     = rdd_stream_ptr->look_data.start_dwell_sec;
   rdd_stream_ptr->look_data.mid_dwell_nanosec = rdd_stream_ptr->look_data.start_dwell_nanosec;
   rdd_stream_ptr->look_data.end_dwell_status  = 1;
   rdd_stream_ptr->look_data.end_dwell_sec     = rdd_stream_ptr->look_data.start_dwell_sec;
   rdd_stream_ptr->look_data.end_dwell_nanosec = rdd_stream_ptr->look_data.start_dwell_nanosec;
   rdd_stream_ptr->look_data.look_id           = detection_data_input->dets_info.LookType;
   rdd_stream_ptr->look_data.scan_index        = detection_data_input->dets_info.ScanIndex;
   rdd_stream_ptr->look_data.look_index        = detection_data_input->dets_info.ScanIndex;
}

void populate_ipc_detection_and_ds_stream_with_symbol_data(Detection_Stream_T *det_stream, Down_selection_Stream_T *det_ds_stream,
                                                           const Detection_Data_Input_T *detection_data_input)
{
   assert(det_stream != nullptr);
   assert(det_ds_stream != nullptr);
   assert(detection_data_input != nullptr);

   const uint32_t scanindex = detection_data_input->dets_info.ScanIndex;

   /*******************************************************************\
    * Populate Detection Stream
   \*******************************************************************/
   det_stream->stream_hdr.scan_index = scanindex;

   det_stream->det_list_property.scanindex               = scanindex;
   det_stream->det_list_property.lookindex               = scanindex;
   det_stream->det_list_property.look_type               = detection_data_input->dets_info.LookType;
   det_stream->det_list_property.timestamp_status        = 1;
   det_stream->det_list_property.detection_timestamp_sec = (uint32_t)(detection_data_input->dets_info.timestamp / 1000);
   det_stream->det_list_property.detection_timestamp_ns =
      (uint32_t)((uint32_t)detection_data_input->dets_info.timestamp % 1000) * 1000000;

   det_stream->num_af_det       = std::min(detection_data_input->dets_info.Count, (uint32_t)AF_MAX_NUM_DET);
   const uint32_t max_det_index = std::min((uint32_t)det_stream->num_af_det, (uint32_t)NUMBER_OF_DETECTIONS_PER_RADAR);
   for (uint32_t index = 0; index < max_det_index; index++)
   {
      const Detections_Input_T &detection_input = detection_data_input->dets_input[index];

      det_stream->af_dets[index].theta             = detection_input.azimuth_raw;
      det_stream->af_dets[index].phi               = detection_input.elevation_raw;
      det_stream->af_dets[index].ran               = detection_input.range;
      det_stream->af_dets[index].vel               = detection_input.range_rate_raw;
      det_stream->af_dets[index].snr               = detection_input.detection_snr;
      det_stream->af_dets[index].rcs               = detection_input.amplitude;
      det_stream->af_dets[index].az_conf           = detection_input.azimuth_confidence;
      det_stream->af_dets[index].el_conf           = detection_input.elevation_confidence;
      det_stream->af_dets[index].f_superres_target = detection_input.super_res_target;
      det_stream->af_dets[index].f_bistatic        = detection_input.bistatic;
   }
   /*******************************************************************/

   /*******************************************************************\
    * Populate DownSelection Stream
   \*******************************************************************/
   det_ds_stream->stream_hdr.scan_index = scanindex;

   det_ds_stream->det_list_property.detection_timestamp_sec = det_stream->det_list_property.detection_timestamp_sec;
   det_ds_stream->det_list_property.detection_timestamp_ns  = det_stream->det_list_property.detection_timestamp_ns;
   det_ds_stream->det_list_property.scanindex               = scanindex;
   det_ds_stream->det_list_property.lookindex               = scanindex;
   det_ds_stream->det_list_property.look_type               = detection_data_input->dets_info.LookType;

   det_ds_stream->num_af_ds_det = std::min(detection_data_input->dets_info.Count, (uint32_t)MAX_TARGET_REPORTS);
   const uint32_t max_ds_index  = std::min((uint32_t)det_ds_stream->num_af_ds_det, (uint32_t)NUMBER_OF_DETECTIONS_PER_RADAR);
   for (uint32_t index = 0; index < max_ds_index; index++)
   {
      const Detections_Input_T &detection_input = detection_data_input->dets_input[index];

      det_ds_stream->af_ds_dets[index].theta             = detection_input.azimuth_raw;
      det_ds_stream->af_ds_dets[index].phi               = detection_input.elevation_raw;
      det_ds_stream->af_ds_dets[index].ran               = detection_input.range;
      det_ds_stream->af_ds_dets[index].vel               = detection_input.range_rate_raw;
      det_ds_stream->af_ds_dets[index].snr               = detection_input.detection_snr;
      det_ds_stream->af_ds_dets[index].rcs               = detection_input.amplitude;
      det_ds_stream->af_ds_dets[index].az_conf           = detection_input.azimuth_confidence;
      det_ds_stream->af_ds_dets[index].el_conf           = detection_input.elevation_confidence;
      det_ds_stream->af_ds_dets[index].f_superres_target = detection_input.super_res_target;
      det_ds_stream->af_ds_dets[index].f_bistatic        = detection_input.bistatic;
   }
   /*******************************************************************/
}

void populate_sensor_calib_data(Sensor_Calib_Data_T *sensor_calib_data_ptr, const MOUNTING_VALUES_XML_T *mounting_values,
                                const Vehicle_Data_Input_T *vehicle_input)
{
   assert(sensor_calib_data_ptr != nullptr);
   assert(mounting_values != nullptr);
   assert(vehicle_input != nullptr);

   sensor_calib_data_ptr->sensor_mount_data.k_sensor_mount_pos_x =
      mounting_values->vcs_lon_position + vehicle_input->rear_axle_position;
   sensor_calib_data_ptr->sensor_mount_data.k_sensor_mount_pos_y    = -1.0F * mounting_values->vcs_lat_position;
   sensor_calib_data_ptr->sensor_mount_data.k_sensor_mount_pos_z    = mounting_values->vcs_z_position;
   sensor_calib_data_ptr->sensor_mount_data.k_sensor_mount_ornt_yaw = -1.0F * mounting_values->boresight_angle * DEG2RAD_SIL;
   sensor_calib_data_ptr->sensor_mount_data.k_sensor_mount_ornt_roll =
      mounting_values->azimuth_polarity == -1 ? 0 : 180 * DEG2RAD_SIL;
   sensor_calib_data_ptr->sensor_mount_data.k_sensor_mount_ornt_pitch = 0.0F;
   sensor_calib_data_ptr->sensor_mount_data.k_sensor_mount_height     = mounting_values->vcs_z_position;

   for (uint8_t look_id = 0; look_id < 4; look_id++)
   {
      sensor_calib_data_ptr->k_vwrapping[look_id]           = fabsf(Fix2Float(k_vwrapping_smc[look_id], s10p21_T));
      sensor_calib_data_ptr->k_rwrapping[look_id]           = fabsf((float)(k_rwrapping_smc[look_id] / (float32_t)(1ULL << 31)));
      sensor_calib_data_ptr->k_detection_range_max[look_id] = Fix2Float(k_detection_range_max_smc[look_id], u9p7_T);
   }

   sensor_calib_data_ptr->k_rdotmin       = Fix2Float(k_rdotmin_smc, s10p21_T);
   sensor_calib_data_ptr->k_fov_hor_begin = Fix2Float(k_fov_hor_begin_smc, s2p13_T);
   sensor_calib_data_ptr->k_fov_hor_end   = Fix2Float(k_fov_hor_end_smc, s2p13_T);
   sensor_calib_data_ptr->k_fov_ver_begin = Fix2Float(k_fov_ver_begin_smc, s2p13_T);
   sensor_calib_data_ptr->k_fov_ver_end   = Fix2Float(k_fov_ver_end_smc, s2p13_T);
}

void populate_partner_sensor_calib_data(Partner_Sensor_Stream_T *partner_sensor_calib_data_ptr,
                                        Sensor_Calib_Data_T *sensor_calib_data_ptr, const MOUNTING_VALUES_XML_T *mounting_values,
                                        const Vehicle_Data_Input_T *vehicle_input)
{
   assert(sensor_calib_data_ptr != nullptr);
   assert(partner_sensor_calib_data_ptr != nullptr);
   assert(mounting_values != nullptr);
   assert(vehicle_input != nullptr);

   partner_sensor_calib_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_pos_x =
      mounting_values->vcs_lon_position + vehicle_input->rear_axle_position;
   partner_sensor_calib_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_pos_y =
      -1.0F * mounting_values->vcs_lat_position;
   partner_sensor_calib_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_pos_z = mounting_values->vcs_z_position;
   partner_sensor_calib_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_ornt_yaw =
      -1.0F * mounting_values->boresight_angle * DEG2RAD_SIL;
   partner_sensor_calib_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_ornt_roll =
      mounting_values->azimuth_polarity == -1 ? 0 : 180 * DEG2RAD_SIL;
   partner_sensor_calib_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_ornt_pitch = 0.0F;
   partner_sensor_calib_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_height     = mounting_values->vcs_z_position;

   for (uint8_t look_id = 0; look_id < 4; look_id++)
   {
      sensor_calib_data_ptr->k_vwrapping[look_id]           = fabsf(Fix2Float(k_vwrapping_smc[look_id], s10p21_T));
      sensor_calib_data_ptr->k_rwrapping[look_id]           = fabsf((float)(k_rwrapping_smc[look_id] / (float32_t)(1ULL << 31)));
      sensor_calib_data_ptr->k_detection_range_max[look_id] = Fix2Float(k_detection_range_max_smc[look_id], u9p7_T);
   }

   sensor_calib_data_ptr->k_rdotmin       = Fix2Float(k_rdotmin_smc, s10p21_T);
   sensor_calib_data_ptr->k_fov_hor_begin = Fix2Float(k_fov_hor_begin_smc, s2p13_T);
   sensor_calib_data_ptr->k_fov_hor_end   = Fix2Float(k_fov_hor_end_smc, s2p13_T);
   sensor_calib_data_ptr->k_fov_ver_begin = Fix2Float(k_fov_ver_begin_smc, s2p13_T);
   sensor_calib_data_ptr->k_fov_ver_end   = Fix2Float(k_fov_ver_end_smc, s2p13_T);
}

void populate_ipc_m2d_one_time_with_symbol_data(M2D_One_Time_Msg_T *p_ipc_m2d_one_time, const Radar_Symbol_Context_T &context)
{
   assert(p_ipc_m2d_one_time != nullptr);
   assert(context.vehicle_input != nullptr);
   assert(context.self_mounting != nullptr);

   p_ipc_m2d_one_time->radar_position = context.self_radar_position;

   Vehicle_Calib_Data_T *vehicle_calib_data_ptr                 = &p_ipc_m2d_one_time->calib_data.vehicle_calib_data;
   vehicle_calib_data_ptr->k_rear_cornering_compliance          = k_rear_cornering_complicane_smc;
   vehicle_calib_data_ptr->k_steering_gear_ratio                = k_steering_gear_ratio_smc;
   vehicle_calib_data_ptr->k_wheelbase                          = k_wheelbase_smc;
   vehicle_calib_data_ptr->k_vehicle_width                      = context.vehicle_input->host_vehicle_width;
   vehicle_calib_data_ptr->k_vehicle_length                     = context.vehicle_input->host_vehicle_length;
   vehicle_calib_data_ptr->k_distance_front_bumper_to_rear_axle = context.vehicle_input->rear_axle_position;

   populate_sensor_calib_data(&p_ipc_m2d_one_time->calib_data.sensor_calib_data, context.self_mounting, context.vehicle_input);

   p_ipc_m2d_one_time->calib_data.data_availability_status = CODED_TRUE;
}

#ifdef TRACKER_ENABLED
void populate_partner_sensor_data_with_symbol_data_Dspace(M2D_Msg_T *p_ipc_m2d, M2D_One_Time_Msg_T *p_ipc_m2d_one_time,
                                                          const Radar_Symbol_Context_T &context)
{
   assert(p_ipc_m2d != nullptr);
   assert(p_ipc_m2d_one_time != nullptr);

   p_ipc_m2d->payload.partners_data = {};

   if ((context.partner_radar_position == UNKNOWN_POSITION) || (context.partner_mounting == nullptr) ||
       (context.partner_detection == nullptr) || (context.vehicle_input == nullptr))
   {
      return;
   }

   Partner_Sensor_Stream_T *partner_sensor_data_ptr                          = &p_ipc_m2d->payload.partners_data;
   partner_sensor_data_ptr->partner_det_list_property_data[0].radar_position = context.partner_radar_position;
   partner_sensor_data_ptr->partner_det_list_property_data[0].ts_mid_dwell_sec =
      (uint32_t)(context.partner_detection->dets_info.timestamp / 1000);
   partner_sensor_data_ptr->partner_det_list_property_data[0].ts_mid_dwell_nanosec =
      (uint32_t)((uint32_t)context.partner_detection->dets_info.timestamp % 1000) * 1000000;
   partner_sensor_data_ptr->partner_det_list_property_data[0].look_index = context.partner_detection->dets_info.ScanIndex;
   partner_sensor_data_ptr->partner_det_list_property_data[0].look_type  = context.partner_detection->dets_info.LookType;
   partner_sensor_data_ptr->partner_sensor_alignment_info[0].vacs_boresight_az_estimated =
      context.partner_mounting->boresight_angle * DEG2RAD_SIL;
   partner_sensor_data_ptr->partner_sensor_alignment_info[0].vacs_boresight_el_estimated     = 0.0F;
   partner_sensor_data_ptr->partner_sensor_alignment_info[0].alignment_mode                  = 1;
   partner_sensor_data_ptr->partner_sensor_alignment_info[0].alignment_error_status_combined = 0;
   partner_sensor_data_ptr->partner_sensor_diag_data[0].det_recvd_flag                       = 1;
   partner_sensor_data_ptr->partner_sensor_diag_data[0].status_recvd_flag                    = 1;

   partner_sensor_data_ptr->partner_sensor_det_data.num_af_det =
      std::min(context.partner_detection->dets_info.Count, (uint32_t)NUMBER_OF_PARTNER_DETECTIONS_EMB);
   const uint32_t max_partner_det_index =
      std::min((uint32_t)partner_sensor_data_ptr->partner_sensor_det_data.num_af_det, (uint32_t)NUMBER_OF_DETECTIONS_PER_RADAR);

   for (uint32_t index = 0; index < max_partner_det_index; index++)
   {
      const Detections_Input_T &detection_input = context.partner_detection->dets_input[index];

      partner_sensor_data_ptr->partner_sensor_det_data.ps_dets[index].theta             = detection_input.azimuth_raw;
      partner_sensor_data_ptr->partner_sensor_det_data.ps_dets[index].phi               = detection_input.elevation_raw;
      partner_sensor_data_ptr->partner_sensor_det_data.ps_dets[index].ran               = detection_input.range;
      partner_sensor_data_ptr->partner_sensor_det_data.ps_dets[index].vel               = detection_input.range_rate_raw;
      partner_sensor_data_ptr->partner_sensor_det_data.ps_dets[index].snr               = detection_input.detection_snr;
      partner_sensor_data_ptr->partner_sensor_det_data.ps_dets[index].rcs               = detection_input.amplitude;
      partner_sensor_data_ptr->partner_sensor_det_data.ps_dets[index].az_conf           = detection_input.azimuth_confidence;
      partner_sensor_data_ptr->partner_sensor_det_data.ps_dets[index].el_conf           = detection_input.elevation_confidence;
      partner_sensor_data_ptr->partner_sensor_det_data.ps_dets[index].f_superres_target = detection_input.super_res_target;
      partner_sensor_data_ptr->partner_sensor_det_data.ps_dets[index].f_bistatic        = detection_input.bistatic;
      partner_sensor_data_ptr->partner_sensor_det_data.ps_dets[index].f_ci_det          = false;
      partner_sensor_data_ptr->partner_sensor_det_data.ps_dets[index].sensor_id         = 2U;
   }

   populate_partner_sensor_calib_data(&p_ipc_m2d->payload.partners_data, &p_ipc_m2d_one_time->calib_data.sensor_calib_data,
                                      context.partner_mounting, context.vehicle_input);

   partner_sensor_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_ornt_roll =
      p_ipc_m2d->payload.partners_data.partner_sensor_mounting_params[0].k_sensor_mount_ornt_roll;
   partner_sensor_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_ornt_pitch =
      p_ipc_m2d->payload.partners_data.partner_sensor_mounting_params[0].k_sensor_mount_ornt_pitch;
   partner_sensor_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_ornt_yaw =
      p_ipc_m2d->payload.partners_data.partner_sensor_mounting_params[0].k_sensor_mount_ornt_yaw;
   partner_sensor_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_pos_z =
      p_ipc_m2d->payload.partners_data.partner_sensor_mounting_params[0].k_sensor_mount_pos_z;
   partner_sensor_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_pos_y =
      p_ipc_m2d->payload.partners_data.partner_sensor_mounting_params[0].k_sensor_mount_pos_y;
   partner_sensor_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_pos_x =
      p_ipc_m2d->payload.partners_data.partner_sensor_mounting_params[0].k_sensor_mount_pos_x;
}
#endif

void populate_ipc_vse_stream_with_symbol_data(Vse_Stream_T *vse_stream, const Radar_Symbol_Context_T &context)
{
   const Vehicle_Data_Input_T *symbol_vehicle_input_ptr = context.vehicle_input;
   vse_stream->stream_hdr.scan_index                    = context.self_detection->dets_info.ScanIndex;
   Veh_Raw_Misc_T *veh_raw_misc_data                    = &vse_stream->veh_raw_misc;
   Veh_Params_T *veh_param_data                         = &vse_stream->veh_params;

   for (int8_t latest_raw_index = 0; latest_raw_index < 5; latest_raw_index++)
   {
      Veh_Raw_Data_T *veh_raw_data = &vse_stream->veh_raw_data[latest_raw_index];

      veh_raw_data->ego_longitudinal_accel = symbol_vehicle_input_ptr->vcs_long_acc;
      veh_raw_data->ego_lateral_accel      = symbol_vehicle_input_ptr->vcs_lat_acc;
      veh_raw_data->steering_whl_angle     = symbol_vehicle_input_ptr->steering_angle;

      const float32_t steering_whl_angle_deg = (veh_raw_data->steering_whl_angle * RAD_TO_DEG_F32);
      if (!Steering_Whl_Angle_Initialized)
      {
         veh_raw_data->steering_whl_speed_deg_per_s = 0.0F;
         Steering_Whl_Angle_Initialized             = true;
      }
      else
      {
         veh_raw_data->steering_whl_speed_deg_per_s = (steering_whl_angle_deg - Prev_Steering_Whl_Angle_Deg) / COMM_RX_PERIOD_SEC;
      }
      Prev_Steering_Whl_Angle_Deg = steering_whl_angle_deg;

      veh_raw_data->ego_yaw_rate         = symbol_vehicle_input_ptr->yawrate;
      veh_raw_data->ego_vehicle_speed    = symbol_vehicle_input_ptr->abs_speed;
      veh_raw_data->system_time_secs     = (uint32_t)(symbol_vehicle_input_ptr->vehicle_data_buff_timestamp / 1000U);
      veh_raw_data->system_time_nanosecs = (uint32_t)((symbol_vehicle_input_ptr->vehicle_data_buff_timestamp % 1000U) * 1000000U);
   }

   veh_param_data->k_steering_ratio_rack_pinion_type   = 0U;
   veh_param_data->k_front_track_width                 = 0.0F;
   veh_param_data->k_cog_y                             = 0.0F;
   veh_param_data->k_cog_x                             = 0.0F;
   veh_param_data->k_vehicle_width                     = symbol_vehicle_input_ptr->host_vehicle_width;
   veh_param_data->k_vehicle_length                    = symbol_vehicle_input_ptr->host_vehicle_length;
   veh_param_data->k_rear_cornering_compliance         = k_rear_cornering_complicane_smc;
   veh_param_data->k_understeer_coefficient            = 0.0F;
   veh_param_data->k_steering_gear_ratio               = k_steering_gear_ratio_smc;
   veh_param_data->k_lat_dist_radar_to_rear_axle       = 0.0F;
   veh_param_data->k_long_dist_radar_to_rear_axle      = 0.0F;
   veh_param_data->k_dist_rear_axle_to_vcs             = symbol_vehicle_input_ptr->rear_axle_position;
   veh_param_data->k_wheel_base                        = k_wheelbase_smc;
   veh_param_data->sensor_lat_distance_from_rear_axle  = 0.0F;
   veh_param_data->sensor_long_distance_from_rear_axle = 0.0F;

   veh_raw_misc_data->turn_signal               = symbol_vehicle_input_ptr->turn_signal;
   veh_raw_misc_data->vehspeedcompfac_ka_qf     = 3; // Not available in symbol, set to 3 (valid) or some default value
   veh_raw_misc_data->gear_pos                  = symbol_vehicle_input_ptr->prndl;
   veh_raw_misc_data->ego_longitudinal_accel_qf = 3; // Not available in symbol, set to 3 (valid) or some default value
   veh_raw_misc_data->ego_lateral_accel_qf      = 3; // Not available in symbol, set to 3 (valid) or some default value
   veh_raw_misc_data->steering_whl_angle_qf     = 3; // Not available in symbol, set to 3 (valid) or some default value
   veh_raw_misc_data->vehicle_standstill        = 0U;
   veh_raw_misc_data->ego_yaw_rate_qf           = 3;    // Not available in symbol, set to 3 (valid) or some default value
   veh_raw_misc_data->ego_vehicle_speed_qf      = 3;    // Not available in symbol, set to 3 (valid) or some default value
   veh_raw_misc_data->vehspeedcompfac_ka        = 1.0F; // Not available in symbol, set to 1.0 or some default value
}

static void populate_ipc_misc_symbol_data(const Radar_Symbol_Context_T &context)
{
   const MOUNTING_VALUES_XML_T *mounting_values         = context.self_mounting;
   const Detection_Data_Input_Tag *detection_data_input = context.self_detection;

   M2D_Msg_T *p_ipc_m2d                         = Get_IPC_M2D_Buffer();
   D2M_Msg_T *p_ipc_d2m                         = Get_IPC_D2M_Buffer();
   M2D_One_Time_Msg_T *p_ipc_m2d_one_time       = Get_IPC_M2D_One_Time_Buffer();
   Sensor_Calib_Data_T *sensor_calib_data_ptr   = &p_ipc_m2d_one_time->calib_data.sensor_calib_data;
   Vehicle_Calib_Data_T *vehicle_calib_data_ptr = &p_ipc_m2d_one_time->calib_data.vehicle_calib_data;
   Dynamic_Alignment_Data_T *da_data_ptr        = &p_ipc_m2d->payload.alignment_Info.dynamic_alignment_data;
   Static_Alignment_Data_T *sa_data_ptr         = &p_ipc_m2d->payload.alignment_Info.static_alignment_data;
   /*********************************************************************************************/
   /* Fill M2D payload */
   /*********************************************************************************************/
   p_ipc_m2d->payload.xcp_info             = {};
   p_ipc_m2d->payload.look_Info.scan_index = detection_data_input->dets_info.ScanIndex;
   p_ipc_m2d->payload.look_Info.look_type  = static_cast<Radar_Look_T>(detection_data_input->dets_info.LookType);
   p_ipc_m2d->payload.avg_mmic_onchip_temp = 57; // Not available in symbol, set to 60 or some default value
   p_ipc_m2d_one_time->radar_position      = Get_Radar_Position();
   p_ipc_m2d->payload.offline_mode_flag    = 0;

   /* Fill dynamic alignment input data */
   da_data_ptr->coordinate_system_input = DRA_DET_COORD_SYS_ISO;
   switch (Get_Radar_Position())
   {
      case REAR_LEFT:
         da_data_ptr->mount_loc = DRA_MOUNT_LOC_LEFT_REAR;
         break;
      case REAR_RIGHT:
         da_data_ptr->mount_loc = DRA_MOUNT_LOC_RIGHT_REAR;
         break;
      case FRONT_RIGHT:
         da_data_ptr->mount_loc = DRA_MOUNT_LOC_RIGHT_FORWARD;
         break;
      case FRONT_LEFT:
         da_data_ptr->mount_loc = DRA_MOUNT_LOC_LEFT_FORWARD;
         break;
      case FRONT_CENTER:
         da_data_ptr->mount_loc = DRA_MOUNT_LOC_CENTER_FORWARD;
         break;
      case REAR_CENTER:
         da_data_ptr->mount_loc = DRA_MOUNT_LOC_CENTER_REAR;
         break;
      case RIGHT_CENTER:
         da_data_ptr->mount_loc = DRA_MOUNT_LOC_RIGHT_SIDE;
         break;
      case LEFT_CENTER:
         da_data_ptr->mount_loc = DRA_MOUNT_LOC_LEFT_SIDE;
         break;
      case UNKNOWN_POSITION:
      case INVALID_POSITION:
      case MAX_SENSORS:
         assert(false);
         da_data_ptr->mount_loc = DRA_MOUNT_LOC_CENTER_FORWARD;
         break;
   }
   da_data_ptr->iso_sensor_x_posn                   = sensor_calib_data_ptr->sensor_mount_data.k_sensor_mount_pos_x;
   da_data_ptr->iso_sensor_y_posn                   = sensor_calib_data_ptr->sensor_mount_data.k_sensor_mount_pos_y;
   da_data_ptr->iso_sensor_z_posn                   = sensor_calib_data_ptr->sensor_mount_data.k_sensor_mount_pos_z;
   da_data_ptr->iso_sensor_yaw                      = sensor_calib_data_ptr->sensor_mount_data.k_sensor_mount_ornt_yaw;
   da_data_ptr->iso_sensor_pitch                    = sensor_calib_data_ptr->sensor_mount_data.k_sensor_mount_ornt_pitch;
   da_data_ptr->iso_sensor_roll                     = sensor_calib_data_ptr->sensor_mount_data.k_sensor_mount_ornt_roll;
   da_data_ptr->distance_rear_axle_to_front_bumper  = vehicle_calib_data_ptr->k_distance_front_bumper_to_rear_axle;
   da_data_ptr->max_abs_misalignment_az             = k_max_abs_misalignment_az_smc;
   da_data_ptr->max_abs_misalignment_el_sky         = k_max_abs_misalignment_el_smc;
   da_data_ptr->max_abs_misalignment_el_ground      = k_max_abs_misalignment_el_smc;
   da_data_ptr->short_track_target_height           = 0.8F;
   da_data_ptr->short_track_target_range_rate       = -11.0F;
   da_data_ptr->az_scf_kf_covariance[0]             = 0.0F;
   da_data_ptr->az_scf_kf_covariance[1]             = 0.0F;
   da_data_ptr->az_scf_kf_covariance[2]             = 0.0F;
   da_data_ptr->az_scf_kf_covariance[3]             = 0.0F;
   da_data_ptr->el_roll_kf_covariance[0]            = 0.0F;
   da_data_ptr->el_roll_kf_covariance[1]            = 0.0F;
   da_data_ptr->el_roll_kf_covariance[2]            = 0.0F;
   da_data_ptr->el_roll_kf_covariance[3]            = 0.0F;
   da_data_ptr->short_track_exit_condition          = DRA_SHORT_TRACK_EXIT_AUTO;
   da_data_ptr->initial_align_quality_factor_az     = 0;
   da_data_ptr->initial_align_quality_factor_el     = 0;
   da_data_ptr->initial_vacs_boresight_az_estimated = mounting_values->boresight_angle * DEG2RAD_SIL;
   da_data_ptr->initial_vacs_boresight_el_estimated = 0.0F;
   da_data_ptr->initial_vacs_boresight_rl_estimated = 0.0F;
   da_data_ptr->initial_speed_compensation_factor   = 1;
   da_data_ptr->initial_num_updates_az              = 0;
   da_data_ptr->initial_num_updates_el              = 0;
   da_data_ptr->initial_num_updates_rl              = 0;
   da_data_ptr->f_data_valid                        = 1U;
   da_data_ptr->operation_mode_status               = 1U;
   da_data_ptr->align_cmd                           = 1U;

   /* Fill static alignment input data */
   sa_data_ptr->yaw                 = 135.0F;
   sa_data_ptr->pitch               = 0.0F;
   sa_data_ptr->plate_distance      = 1192.0F;
   sa_data_ptr->polarity            = 1.0F;
   sa_data_ptr->horz_angle_min      = -600.0F;
   sa_data_ptr->horz_angle_max      = 600.0F;
   sa_data_ptr->vert_angle_min      = -600.0F;
   sa_data_ptr->vert_angle_max      = 600.0F;
   sa_data_ptr->plate_lat_position  = -350.0F;
   sa_data_ptr->plate_angle_deg_scs = 0.0F;
   sa_data_ptr->mount_loc           = da_data_ptr->mount_loc;
   sa_data_ptr->f_data_valid        = 1U;
   sa_data_ptr->align_cmd           = da_data_ptr->align_cmd;

   /* Fill vehicle input data */
   /* Vehicle data is already filled from stream */
   /*********************************************************************************************/

   /*********************************************************************************************/
   /* Fill D2M payload */
   /*********************************************************************************************/
   p_ipc_d2m->payload.dsp_timing_data.state_profiling[RANGE_PROCESSING].lastRuntime            = 0;
   p_ipc_d2m->payload.dsp_timing_data.state_profiling[DOPPLER_AND_RDD_PROCESSING].lastRuntime  = 0;
   p_ipc_d2m->payload.dsp_timing_data.state_profiling[ANGLE_FINDING_PROCESSING].lastRuntime    = 0;
   p_ipc_d2m->payload.dsp_timing_data.state_profiling[RADAR_CAPABILITY_PROCESSING].lastRuntime = 0;
   p_ipc_d2m->payload.dsp_timing_data.state_profiling[TOI_ALIGNMENT_PROCESSING].lastRuntime    = 0;

   p_ipc_d2m->payload.xcp_data    = {};
   p_ipc_d2m->payload.diag_data   = {};
   p_ipc_d2m->payload.xcp_af_data = {};

   /*********************************************************************************************/
}

} // namespace sil_symbol_wrapper_internal

using namespace sil_symbol_wrapper_internal;

#ifdef FEATURE_ENABLE
extern "C" uint8_t RL_bsis_alert_level                 = 0U;
extern "C" uint8_t RL_BlindSpotDetectionState          = 0U;
extern "C" uint8_t RL_BendOffPrbablityofMstImportatObj = 0U;
extern "C" uint8_t RL_BlindSpotWarnigRelevantObjDetect = 0U;

static void Populate_Alert_Data(SIL_RADAR_Input_Symbol_T *sil_radar_input_symbol_ptr)
{
   D2M_Msg_T *p_ipc_d2m          = Get_IPC_D2M_Buffer();
   Radar_Position radar_position = Get_Radar_Position();
   switch (radar_position)
   {
      case FRONT_CENTER:
         p_ipc_d2m->payload.Bsis_IPC_Output.bsis_instance.core_output.bsis_alert_level[0] =
            sil_radar_input_symbol_ptr->BSIS_In[REAR_LEFT].bsis_alert_level[0];
         RL_bsis_alert_level                 = sil_radar_input_symbol_ptr->BSIS_In[REAR_LEFT].bsis_alert_level[0];
         RL_BlindSpotDetectionState          = sil_radar_input_symbol_ptr->BlindSpotDetectionState[REAR_LEFT];
         RL_BendOffPrbablityofMstImportatObj = sil_radar_input_symbol_ptr->BendOffPrbablityofMstImportatObj[REAR_LEFT];
         RL_BlindSpotWarnigRelevantObjDetect = sil_radar_input_symbol_ptr->BlindSpotWarnigRelevantObjDetect[REAR_LEFT];
         break;
   }
}
#endif

bool populate_ipc_with_symbol_data(const UDPRecord_SIL *raw_stream)
{
   if (raw_stream == nullptr)
   {
      write_statistical_report(ReportKind::FAULT, "symbol data raw_stream is null");
      return false;
   }

   const UDPRecord_Header_SIL header = raw_stream[SYM_INPUT_DATA].header;
   const bool header_check           = (header.streamNumber == SYM_INPUT_DATA) &&
                             (header.streamVersion == SIL_DEBUG_INPUT_TYPE_STRUCTURE_VERSION) &&
                             (header.streamDataLen == sizeof(SIL_RADAR_Input_Symbol_T));
   const bool payload_check = raw_stream[SYM_INPUT_DATA].payload != nullptr;

   if (!header_check)
   {
      write_statistical_report(ReportKind::FAULT, "symbol data header_check failed");
      return false;
   }

   if (!payload_check)
   {
      write_statistical_report(ReportKind::FAULT, "symbol data payload_check failed");
      return false;
   }

   SIL_RADAR_Input_Symbol_T *sil_radar_input_symbol_ptr = Get_Sil_Radar_Input_Symbol_Ptr();

   std::memcpy(sil_radar_input_symbol_ptr, raw_stream[SYM_INPUT_DATA].payload, sizeof(SIL_RADAR_Input_Symbol_T));

   D2M_Msg_T *p_ipc_d2m                              = Get_IPC_D2M_Buffer();
   M2D_Msg_T *p_ipc_m2d                              = Get_IPC_M2D_Buffer();
   M2D_One_Time_Msg_T *p_ipc_m2d_one_time            = Get_IPC_M2D_One_Time_Buffer();
   Rdd_Stream_T *rdd_stream                          = &p_ipc_d2m->payload.rdd_stream_data;
   Down_selection_Stream_T *det_ds_stream            = &p_ipc_d2m->payload.downselection_data;
   Detection_Stream_T *det_stream                    = &p_ipc_d2m->payload.det_data;
   Vse_Stream_T *vse_stream                          = &p_ipc_m2d->payload.veh_data;
   Dynamic_Alignment_Log_Stream_T *da_log_stream_ptr = &p_ipc_d2m->payload.dynamic_alignment_log_stream;
   Status_Stream_T *status_log_data_ptr              = Get_Status_Log_Data_Ptr();
   Header_Stream_T *header_stream_ptr                = Get_Header_Log_Data_Ptr();
   const Radar_Symbol_Context_T context = resolve_radar_symbol_context(sil_radar_input_symbol_ptr, Get_Radar_Position());

   if (sil_radar_input_symbol_ptr->SIL_Mode == DETECTIONS)
   {
      assert(context.vehicle_input != nullptr);
      assert(context.self_mounting != nullptr);
      assert(context.self_detection != nullptr);

      populate_ipc_m2d_one_time_with_symbol_data(p_ipc_m2d_one_time, context);
      populate_ipc_vse_stream_with_symbol_data(vse_stream, context);
      populate_ipc_dynamic_alignment_log_stream_with_symbol_data(da_log_stream_ptr, context.self_mounting);
      populate_ipc_rdd_stream_with_symbol_data(rdd_stream, context.self_detection);
      populate_ipc_detection_and_ds_stream_with_symbol_data(det_stream, det_ds_stream, context.self_detection);
#ifdef TRACKER_ENABLED
      populate_partner_sensor_data_with_symbol_data_Dspace(p_ipc_m2d, p_ipc_m2d_one_time, context);
#endif
      populate_ipc_misc_symbol_data(context);
      /* write_statistical_report() uses scan_index [remove when write_statistical_report() is used inside
       * populate_ipc_with_symbol_data()] */
      Set_Current_Scan_Index(det_stream->stream_hdr.scan_index);
   }
   else
   {
#ifdef AL_TRACKER
      Populate_Partner_Sensor_Data_With_Fusion_Delay(sil_radar_input_symbol_ptr);
      Populate_Alert_Data(sil_radar_input_symbol_ptr);
#endif
   }
   return true;
}
