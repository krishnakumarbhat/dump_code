#include "sil_stream_wrapper.h"

#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <string>
#include <type_traits>

#include "Dynamic_alignment_stream.h"
#include "debug_stream.h"
#include "detection_debug_stream.h"
#include "detection_stream.h"
#include "down_selection_stream.h"
#include "emblib_ipc_data.h"
#include "header_stream.h"
#include "id_stream.h"
#include "mmic_stream.h"
#include "radar_capability_stream.h"
#include "rdd_debug_stream.h"
#include "rdd_stream.h"
#include "sil_input_symbol.h"
#include "sil_macros_time.h"
#include "sil_wrapper_common.h"
#include "static_alignment_stream.h"
#include "statistical_report.h"
#include "status_stream.h"
#include "toi_stream.h"
#include "vse_stream.h"

#ifdef FEATURE_ENABLE
   #include "bsis_stream.h"
   #include "mois_stream.h"
   #include "olp_stream.h"
#endif

namespace
{
constexpr size_t DETECTION_DATA_SIZE = (sizeof(Detection_Stream_T) - sizeof(Stream_Hdr_T));
constexpr size_t HEADER_DATA_SIZE    = (sizeof(Header_Stream_T) - sizeof(Stream_Hdr_T));
constexpr size_t STATUS_DATA_SIZE    = (sizeof(Status_Stream_T) - sizeof(Stream_Hdr_T));
constexpr size_t RDD_DATA_SIZE       = (sizeof(RDD_Data_T) - sizeof(Stream_Hdr_T));
constexpr size_t RDD_DEBUG_DATA_SIZE = (sizeof(Rdd_Debug_Stream_T) - sizeof(Stream_Hdr_T));
constexpr size_t VSE_DATA_SIZE       = (sizeof(Vse_Stream_T) - sizeof(Stream_Hdr_T));
constexpr size_t DEBUG_DATA_SIZE     = (sizeof(Debug_Stream_T) - sizeof(Stream_Hdr_T));
constexpr size_t CDC_DATA_SIZE       = (sizeof(CDC_Stream_T) - sizeof(Stream_Hdr_T));
constexpr size_t MMIC_DATA_SIZE      = (sizeof(MMIC_Stream_T) - sizeof(Stream_Hdr_T));
constexpr size_t ALIGNMENT_DATA_SIZE = (sizeof(Static_Alignment_Log_Stream_T) - sizeof(Stream_Hdr_T));
// constexpr size_t ADC_DATA_SIZE               = (sizeof(Adc_Stream_T) - sizeof(Stream_Hdr_T));
constexpr size_t RADAR_CAPABILITY_DATA_SIZE  = (sizeof(Radar_Capability_Stream_T) - sizeof(Stream_Hdr_T));
constexpr size_t DOWN_SELECTION_DATA_SIZE    = (sizeof(Down_selection_Stream_T) - sizeof(Stream_Hdr_T));
constexpr size_t ID_DATA_SIZE                = (sizeof(ID_Stream_T) - sizeof(Stream_Hdr_T));
constexpr size_t TOI_DATA_SIZE               = (sizeof(TOI_Stream_T) - sizeof(Stream_Hdr_T));
constexpr size_t TOI_DS_DATA_SIZE            = (sizeof(TOI_DS_Stream_T) - sizeof(Stream_Hdr_T));
constexpr size_t DYNAMIC_ALIGNMENT_DATA_SIZE = (sizeof(Dynamic_Alignment_Log_Stream_T) - sizeof(Stream_Hdr_T));
#ifdef TRACKER_ENABLED
constexpr size_t PARTNER_SENSOR_DATA_SIZE           = (sizeof(Partner_Sensor_Stream_T) - sizeof(Stream_Hdr_T));
constexpr size_t SYNC_INFO_DATA_SIZE                = (sizeof(Sync_Info_Stream_T));
constexpr size_t VEHICLE_INFO_DATA_SIZE             = (sizeof(Vehicle_Info_Stream_T));
constexpr size_t TRACKER_INFO_DATA_SIZE             = (sizeof(Tracker_Info_Stream_T));
constexpr size_t TIME_INFO_DATA_SIZE                = (sizeof(Timing_Info_Stream_T));
constexpr size_t HOST_CALIB_DATA_SIZE               = (sizeof(Host_Calibs_Stream_T));
constexpr size_t HOST_PROPS_DATA_SIZE               = (sizeof(Host_Props_Stream_T));
constexpr size_t STAT_ENV_DATA_SIZE                 = (sizeof(Static_Env_Poly_Stream_T));
constexpr size_t FUNCTIONAL_SAFETY_FAULTS_DATA_SIZE = (sizeof(Functional_Safety_Faults_Stream_T));
constexpr size_t OBJECT_LIST_DATA_SIZE              = (sizeof(Object_List_Stream_T) - sizeof(F360_Log_Header_T));
constexpr size_t PROCESSED_DETECTION_DATA_SIZE      = (sizeof(Processed_Detection_Stream_T) - sizeof(F360_Log_Header_T));
constexpr size_t SENSOR_CALIB_DATA_SIZE             = (sizeof(Sensor_Calib_Stream_T) - sizeof(F360_Log_Header_T));
constexpr size_t TRAILER_DETECTOR_DATA_SIZE         = (sizeof(Trailer_Detector_Stream_T));
constexpr size_t CV_TRAILER_DATA_SIZE               = (sizeof(Cv_Trailer_Stream_T));
   #ifdef FEATURE_ENABLE
constexpr size_t BSIS_DATA_SIZE = (sizeof(Bsis_Stream_T) - sizeof(Stream_Hdr_T));
constexpr size_t MOIS_DATA_SIZE = (sizeof(Mois_Stream_T) - sizeof(Stream_Hdr_T));
constexpr size_t OLP_DATA_SIZE  = (sizeof(Olp_Stream_T) - sizeof(Stream_Hdr_T));
   #endif
#endif

template <typename EnumType> constexpr std::underlying_type_t<EnumType> enum_cast(EnumType value)
{
   return static_cast<std::underlying_type_t<EnumType>>(value);
}

[[nodiscard]] constexpr bool match_checksum(uint16_t expected_checksum, const uint8_t *ptr, size_t len)
{
   if (expected_checksum == 0)
   {
      return true;
   }

   uint16_t calculated_checksum = 0;
   for (size_t idx = 0; idx < len; ++idx)
   {
      calculated_checksum = static_cast<uint16_t>(calculated_checksum + ptr[idx]);
   }

   return calculated_checksum == expected_checksum;
}

template <typename StreamType>
void validate_and_copy_stream(const char *stream_name, const StreamType *input_ptr, StreamType *output_ptr,
                              uint16_t expected_scan_index, size_t payload_size, bool &scan_index_mismatch_check_flag,
                              bool &scan_index_is_zero_flag, bool &stream_is_null_flag)
{
   if (input_ptr == nullptr)
   {
      write_statistical_report(ReportKind::NULLPTR, std::string(stream_name) + " is a nullptr");
      stream_is_null_flag = true;
      return;
   }

   if (input_ptr->stream_hdr.scan_index == 0)
   {
      write_statistical_report(ReportKind::FAULT, std::string(stream_name) + "->stream_hdr.scan_index = 0");
      scan_index_is_zero_flag = true;
      return;
   }

   if (input_ptr->stream_hdr.scan_index != expected_scan_index)
   {
      write_statistical_report(ReportKind::FAULT, std::string(stream_name) +
                                                     "->stream_hdr.scan_index != detection_input_ptr->stream_hdr.scan_index.");
      scan_index_mismatch_check_flag = true;
      return;
   }

   if (match_checksum(input_ptr->stream_hdr.checksum, reinterpret_cast<const uint8_t *>(input_ptr) + sizeof(input_ptr->stream_hdr),
                      payload_size))
   {
      std::memcpy(output_ptr, input_ptr, sizeof(StreamType));
   }
}

#if TRACKER_ENABLED
template <typename StreamType>
void validate_and_copy_tracker_stream(const char *stream_name, const StreamType *input_ptr, StreamType *output_ptr,
                                      bool &stream_is_null_flag)
{
   if (input_ptr == nullptr)
   {
      write_statistical_report(ReportKind::NULLPTR, std::string(stream_name) + " is a nullptr");
      stream_is_null_flag = true;
      return;
   }

   std::memcpy(output_ptr, input_ptr, sizeof(StreamType));
}
#endif

void populate_ipc_m2d_one_time_with_stream_data(const Status_Stream_T *status_log_ptr)
{
   M2D_One_Time_Msg_T *m2d_one_time_init_ptr  = Get_IPC_M2D_One_Time_Buffer();
   Calib_Data_T *calib_data_ptr               = &m2d_one_time_init_ptr->calib_data;
   Sensor_Calib_Data_T *sensor_calib_data_ptr = &calib_data_ptr->sensor_calib_data;

#ifdef TRACKER_ENABLED
   M2D_Msg_T *p_ipc_m2d             = Get_IPC_M2D_Buffer();
   p_ipc_m2d->payload.partners_data = {};
#endif

   m2d_one_time_init_ptr->smc_sram_address = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(Get_SMC_Cal_Data()));
   m2d_one_time_init_ptr->usc_sram_address = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(Get_USC_Cal_Data()));
   m2d_one_time_init_ptr->radar_position   = Get_Radar_Position();

   // fill vehicle data
   calib_data_ptr->vehicle_calib_data.k_distance_front_bumper_to_rear_axle = status_log_ptr->sensor_long_offset;
   calib_data_ptr->vehicle_calib_data.k_rear_cornering_compliance          = k_rear_cornering_complicane_smc;
   calib_data_ptr->vehicle_calib_data.k_steering_gear_ratio                = k_steering_gear_ratio_smc;
   calib_data_ptr->vehicle_calib_data.k_wheelbase                          = k_wheelbase_smc;
   calib_data_ptr->vehicle_calib_data.k_vehicle_width                      = k_vehicle_width_smc;
   calib_data_ptr->vehicle_calib_data.k_vehicle_length                     = k_vehicle_length_smc;

   /* Populate self sensor mounting data from Status Stream */
   sensor_calib_data_ptr->sensor_mount_data.k_sensor_mount_pos_x      = status_log_ptr->sensor_mount_pos_x;
   sensor_calib_data_ptr->sensor_mount_data.k_sensor_mount_pos_y      = status_log_ptr->sensor_mount_pos_y;
   sensor_calib_data_ptr->sensor_mount_data.k_sensor_mount_pos_z      = status_log_ptr->sensor_mount_pos_z;
   sensor_calib_data_ptr->sensor_mount_data.k_sensor_mount_height     = status_log_ptr->sensor_mount_pos_z;
   sensor_calib_data_ptr->sensor_mount_data.k_sensor_mount_ornt_yaw   = status_log_ptr->sensor_mount_ornt_yaw;
   sensor_calib_data_ptr->sensor_mount_data.k_sensor_mount_ornt_pitch = status_log_ptr->sensor_mount_ornt_pitch;
   sensor_calib_data_ptr->sensor_mount_data.k_sensor_mount_ornt_roll  = status_log_ptr->sensor_mount_ornt_roll;

   /* Populate look specific values */
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

#ifdef TRACKER_ENABLED
   {
      Partner_Sensor_Stream_T *partner_data_ptr = &p_ipc_m2d->payload.partners_data;
      uint8_t partner_radar_position            = 0U;
      bool has_partner_sensor                   = true;

      /* Partner mapping table (main position -> partner position). */
      switch (m2d_one_time_init_ptr->radar_position)
      {
         case RADAR_POSITION_REAR_LEFT:
            partner_radar_position = RADAR_POSITION_FRONT_LEFT;
            break;
         case RADAR_POSITION_REAR_RIGHT:
            partner_radar_position = RADAR_POSITION_REAR_LEFT;
            break;
         case RADAR_POSITION_FRONT_RIGHT:
            partner_radar_position = RADAR_POSITION_FRONT_LEFT;
            break;
         case RADAR_POSITION_FRONT_CENTER:
            partner_radar_position = RADAR_POSITION_FRONT_CENTER;
            break;
         case RADAR_POSITION_FRONT_LEFT:
            /* AL FL partner (needed for one software approach) */
            *partner_data_ptr = {};
            break;
         default:
            calib_data_ptr->data_availability_status = CODED_FALSE;
            return;
      }

      if (has_partner_sensor)
      {
         const uint8_t smc_index                                            = static_cast<uint8_t>(partner_radar_position - 1U);
         partner_data_ptr->partner_det_list_property_data[0].radar_position = partner_radar_position;
         partner_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_pos_x    = k_sensor_mount_pos_x_list_smc[smc_index];
         partner_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_pos_y    = k_sensor_mount_pos_y_list_smc[smc_index];
         partner_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_pos_z    = k_sensor_mount_pos_z_list_smc[smc_index];
         partner_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_height   = k_sensor_mount_height_list_smc[smc_index];
         partner_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_ornt_yaw = k_sensor_mount_ornt_yaw_list_smc[smc_index];
         partner_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_ornt_pitch =
            k_sensor_mount_ornt_pitch_list_smc[smc_index];
         partner_data_ptr->partner_sensor_mounting_params[0].k_sensor_mount_ornt_roll =
            k_sensor_mount_ornt_roll_list_smc[smc_index];
      }
   }
#endif

   calib_data_ptr->data_availability_status = CODED_TRUE;
}

static void populate_ipc_misc_stream_data()
{
   M2D_Msg_T *p_ipc_m2d                              = Get_IPC_M2D_Buffer();
   D2M_Msg_T *p_ipc_d2m                              = Get_IPC_D2M_Buffer();
   M2D_One_Time_Msg_T *p_ipc_m2d_one_time            = Get_IPC_M2D_One_Time_Buffer();
   Dynamic_Alignment_Data_T *da_data_ptr             = &p_ipc_m2d->payload.alignment_Info.dynamic_alignment_data;
   Static_Alignment_Data_T *sa_data_ptr              = &p_ipc_m2d->payload.alignment_Info.static_alignment_data;
   Detection_Stream_T *det_stream_ptr                = &p_ipc_d2m->payload.det_data;
   Radar_Capability_Stream_T *rc_stream_ptr          = &p_ipc_d2m->payload.radar_capability_data;
   Dynamic_Alignment_Log_Stream_T *da_log_stream_ptr = &p_ipc_d2m->payload.dynamic_alignment_log_stream;
   Static_Alignment_Log_Stream_T *sa_stream_ptr      = &p_ipc_d2m->payload.alignment_stream_data;
   MMIC_Stream_T *mmic_stream_ptr                    = Get_MMIC_Log_Data_Ptr();
   Header_Stream_T *header_stream_ptr                = Get_Header_Log_Data_Ptr();

   /*********************************************************************************************/
   /* Fill M2D payload */
   /*********************************************************************************************/
   p_ipc_m2d->payload.xcp_info             = {};
   p_ipc_m2d->payload.look_Info.scan_index = det_stream_ptr->det_list_property.scanindex;
   p_ipc_m2d->payload.look_Info.look_type  = static_cast<Radar_Look_T>(det_stream_ptr->det_list_property.look_type);
   p_ipc_m2d->payload.avg_mmic_onchip_temp = rc_stream_ptr->avg_mmic_onchip_temp;
   p_ipc_m2d_one_time->radar_position      = Get_Radar_Position();
   p_ipc_m2d->payload.offline_mode_flag    = 0;

   /* Fill dynamic alignment input data */
   da_data_ptr->coordinate_system_input = DRA_DET_COORD_SYS_ISO;
   da_data_ptr->mount_loc               = header_stream_ptr->alignment_data.dynamic_alignment_data.mount_loc;
   da_data_ptr->iso_sensor_x_posn       = header_stream_ptr->alignment_data.dynamic_alignment_data.iso_sensor_x_posn;
   da_data_ptr->iso_sensor_y_posn       = header_stream_ptr->alignment_data.dynamic_alignment_data.iso_sensor_y_posn;
   da_data_ptr->iso_sensor_z_posn       = header_stream_ptr->alignment_data.dynamic_alignment_data.iso_sensor_z_posn;
   da_data_ptr->iso_sensor_yaw          = header_stream_ptr->alignment_data.dynamic_alignment_data.iso_sensor_yaw;
   da_data_ptr->iso_sensor_pitch        = header_stream_ptr->alignment_data.dynamic_alignment_data.iso_sensor_pitch;
   da_data_ptr->iso_sensor_roll         = header_stream_ptr->alignment_data.dynamic_alignment_data.iso_sensor_roll;
   da_data_ptr->distance_rear_axle_to_front_bumper =
      header_stream_ptr->alignment_data.dynamic_alignment_data.distance_rear_axle_to_front_bumper;
   da_data_ptr->max_abs_misalignment_az     = header_stream_ptr->alignment_data.dynamic_alignment_data.max_abs_misalignment_az;
   da_data_ptr->max_abs_misalignment_el_sky = header_stream_ptr->alignment_data.dynamic_alignment_data.max_abs_misalignment_el_sky;
   da_data_ptr->max_abs_misalignment_el_ground =
      header_stream_ptr->alignment_data.dynamic_alignment_data.max_abs_misalignment_el_ground;
   da_data_ptr->short_track_target_height = header_stream_ptr->alignment_data.dynamic_alignment_data.short_track_target_height;
   da_data_ptr->short_track_target_range_rate =
      header_stream_ptr->alignment_data.dynamic_alignment_data.short_track_target_range_rate;
   da_data_ptr->az_scf_kf_covariance[0]    = header_stream_ptr->alignment_data.dynamic_alignment_data.az_scf_kf_covariance[0];
   da_data_ptr->az_scf_kf_covariance[1]    = header_stream_ptr->alignment_data.dynamic_alignment_data.az_scf_kf_covariance[1];
   da_data_ptr->az_scf_kf_covariance[2]    = header_stream_ptr->alignment_data.dynamic_alignment_data.az_scf_kf_covariance[2];
   da_data_ptr->az_scf_kf_covariance[3]    = header_stream_ptr->alignment_data.dynamic_alignment_data.az_scf_kf_covariance[3];
   da_data_ptr->el_roll_kf_covariance[0]   = header_stream_ptr->alignment_data.dynamic_alignment_data.el_roll_kf_covariance[0];
   da_data_ptr->el_roll_kf_covariance[1]   = header_stream_ptr->alignment_data.dynamic_alignment_data.el_roll_kf_covariance[1];
   da_data_ptr->el_roll_kf_covariance[2]   = header_stream_ptr->alignment_data.dynamic_alignment_data.el_roll_kf_covariance[2];
   da_data_ptr->el_roll_kf_covariance[3]   = header_stream_ptr->alignment_data.dynamic_alignment_data.el_roll_kf_covariance[3];
   da_data_ptr->short_track_exit_condition = header_stream_ptr->alignment_data.dynamic_alignment_data.short_track_exit_condition;
   da_data_ptr->initial_align_quality_factor_az =
      header_stream_ptr->alignment_data.dynamic_alignment_data.initial_align_quality_factor_az;
   da_data_ptr->initial_align_quality_factor_el =
      header_stream_ptr->alignment_data.dynamic_alignment_data.initial_align_quality_factor_el;
   da_data_ptr->initial_vacs_boresight_az_estimated =
      header_stream_ptr->alignment_data.dynamic_alignment_data.initial_vacs_boresight_az_estimated;
   da_data_ptr->initial_vacs_boresight_el_estimated =
      header_stream_ptr->alignment_data.dynamic_alignment_data.initial_vacs_boresight_el_estimated;
   da_data_ptr->initial_vacs_boresight_rl_estimated =
      header_stream_ptr->alignment_data.dynamic_alignment_data.initial_vacs_boresight_rl_estimated;
   da_data_ptr->initial_speed_compensation_factor =
      header_stream_ptr->alignment_data.dynamic_alignment_data.initial_speed_compensation_factor;
   da_data_ptr->initial_num_updates_az = header_stream_ptr->alignment_data.dynamic_alignment_data.initial_num_updates_az;
   da_data_ptr->initial_num_updates_el = header_stream_ptr->alignment_data.dynamic_alignment_data.initial_num_updates_el;
   da_data_ptr->initial_num_updates_rl = header_stream_ptr->alignment_data.dynamic_alignment_data.initial_num_updates_rl;
   da_data_ptr->f_data_valid           = header_stream_ptr->alignment_data.dynamic_alignment_data.f_data_valid;
   da_data_ptr->operation_mode_status  = header_stream_ptr->alignment_data.dynamic_alignment_data.operation_mode_status;
   da_data_ptr->align_cmd              = header_stream_ptr->alignment_data.dynamic_alignment_data.align_cmd;

   /* Fill static alignment input data */
   sa_data_ptr->yaw                 = header_stream_ptr->alignment_data.static_alignment_data.yaw;
   sa_data_ptr->pitch               = header_stream_ptr->alignment_data.static_alignment_data.pitch;
   sa_data_ptr->plate_distance      = header_stream_ptr->alignment_data.static_alignment_data.plate_distance;
   sa_data_ptr->polarity            = header_stream_ptr->alignment_data.static_alignment_data.polarity;
   sa_data_ptr->horz_angle_min      = header_stream_ptr->alignment_data.static_alignment_data.horz_angle_min;
   sa_data_ptr->horz_angle_max      = header_stream_ptr->alignment_data.static_alignment_data.horz_angle_max;
   sa_data_ptr->vert_angle_min      = header_stream_ptr->alignment_data.static_alignment_data.vert_angle_min;
   sa_data_ptr->vert_angle_max      = header_stream_ptr->alignment_data.static_alignment_data.vert_angle_max;
   sa_data_ptr->plate_lat_position  = header_stream_ptr->alignment_data.static_alignment_data.plate_lat_position;
   sa_data_ptr->plate_angle_deg_scs = header_stream_ptr->alignment_data.static_alignment_data.plate_angle_deg_scs;
   sa_data_ptr->mount_loc           = header_stream_ptr->alignment_data.static_alignment_data.mount_loc;
   sa_data_ptr->f_data_valid        = header_stream_ptr->alignment_data.static_alignment_data.f_data_valid;
   sa_data_ptr->align_cmd           = header_stream_ptr->alignment_data.static_alignment_data.align_cmd;

   /* Fill vehicle input data */
   /* Vehicle data is already filled from stream */
   /*********************************************************************************************/

   /*********************************************************************************************/
   /* Fill D2M payload */
   /*********************************************************************************************/
   // memcpy(&p_ipc_d2m->payload.ipc_m2d_payload, &p_ipc_m2d->payload, sizeof(M2D_Payload_T));

   p_ipc_d2m->payload.dsp_timing_data.state_profiling[RANGE_PROCESSING].lastRuntime =
      static_cast<uint32_t>(header_stream_ptr->xput_info.RFFT_xput_inst) * MILLISECONDS_2_MICROSECONDS;
   p_ipc_d2m->payload.dsp_timing_data.state_profiling[DOPPLER_AND_RDD_PROCESSING].lastRuntime =
      static_cast<uint32_t>(header_stream_ptr->xput_info.RDD_xput_inst) * MILLISECONDS_2_MICROSECONDS;
   p_ipc_d2m->payload.dsp_timing_data.state_profiling[ANGLE_FINDING_PROCESSING].lastRuntime =
      static_cast<uint32_t>(header_stream_ptr->xput_info.af_xput_inst) * MILLISECONDS_2_MICROSECONDS;
   p_ipc_d2m->payload.dsp_timing_data.state_profiling[INTERFERENCE_DETECTION_PROCESSING].lastRuntime =
      static_cast<uint32_t>(header_stream_ptr->xput_info.id_xput_inst) * MILLISECONDS_2_MICROSECONDS;
   p_ipc_d2m->payload.dsp_timing_data.state_profiling[RADAR_CAPABILITY_PROCESSING].lastRuntime =
      static_cast<uint32_t>(header_stream_ptr->xput_info.rc_xput_inst) * MILLISECONDS_2_MICROSECONDS;
   p_ipc_d2m->payload.dsp_timing_data.state_profiling[TOI_ALIGNMENT_PROCESSING].lastRuntime =
      static_cast<uint32_t>(header_stream_ptr->xput_info.alignment_xput_inst) * MILLISECONDS_2_MICROSECONDS;
   p_ipc_d2m->payload.dsp_timing_data.state_profiling[TRACKER_PROCESSING].lastRuntime =
      static_cast<uint32_t>(header_stream_ptr->xput_info.tracker_xput_inst) * MILLISECONDS_2_MICROSECONDS;
   p_ipc_d2m->payload.dsp_timing_data.state_profiling[FEATURE_PROCESSING].lastRuntime =
      static_cast<uint32_t>(header_stream_ptr->xput_info.feature_xput_inst) * MILLISECONDS_2_MICROSECONDS;
   // p_ipc_d2m->payload.psp_total_xput_us = static_cast<uint32_t>(header_stream_ptr->psp_xput_inst) * MILLISECONDS_2_MICROSECONDS;
   p_ipc_d2m->payload.xcp_data    = {};
   p_ipc_d2m->payload.diag_data   = {};
   p_ipc_d2m->payload.xcp_af_data = {};
   /*********************************************************************************************/
}

} // namespace

bool populate_ipc_with_stream_data(void *const radar_stream[MAX_RADAR_LOGGING_SOURCE])
{
   bool scan_index_mismatch_check_flag = false;
   bool scan_index_is_zero_flag        = false;
   bool stream_is_null_flag            = false;
   bool det_scan_index_is_zero_flag    = false;
   bool no_det_data_flag               = false;
   bool cdc_saturated_flag             = false;
   bool rIdx_dIdx_out_of_range_flag    = false;
   const Radar_Position radar_position = Get_Radar_Position();

   Detection_Stream_T *det_log_ptr             = &Get_IPC_D2M_Buffer()->payload.det_data;
   Detection_Debug_Stream_T *det_debug_log_ptr = &Get_IPC_D2M_Buffer()->payload.det_debug_data;
#ifdef TRACKER_ENABLED
   Partner_Sensor_Stream_T *partner_sensor_log_ptr = &Get_IPC_M2D_Buffer()->payload.partners_data;
   Sync_Info_Stream_T *sync_info_log_ptr           = &Get_IPC_D2M_Buffer()->payload.sync_info_stream;
   Vehicle_Info_Stream_T *veh_info_log_ptr         = &Get_IPC_D2M_Buffer()->payload.vehicle_info_stream;
   Tracker_Info_Stream_T *trk_info_log_ptr         = &Get_IPC_D2M_Buffer()->payload.tracker_info_stream;
   Timing_Info_Stream_T *time_info_log_ptr         = &Get_IPC_D2M_Buffer()->payload.timing_info_stream;
   Host_Calibs_Stream_T *host_calibs_log_ptr       = &Get_IPC_D2M_Buffer()->payload.host_calibs_stream;
   Host_Props_Stream_T *host_props_log_ptr         = &Get_IPC_D2M_Buffer()->payload.host_props_stream;
   Static_Env_Poly_Stream_T *stat_env_log_ptr      = &Get_IPC_D2M_Buffer()->payload.static_env_poly_stream;
   Functional_Safety_Faults_Stream_T *functional_safety_faults_log_ptr =
      &Get_IPC_D2M_Buffer()->payload.functional_safety_faults_stream;
   Object_List_Stream_T *object_list_log_ptr                 = &Get_IPC_D2M_Buffer()->payload.object_list_stream;
   Processed_Detection_Stream_T *processed_detection_log_ptr = &Get_IPC_D2M_Buffer()->payload.processed_detection_stream;
   Sensor_Calib_Stream_T *sensor_calib_log_ptr               = &Get_IPC_D2M_Buffer()->payload.sensor_calib_stream;
   Trailer_Detector_Stream_T *trailer_detector_log_ptr       = &Get_IPC_D2M_Buffer()->payload.trailer_detector_stream;
   Cv_Trailer_Stream_T *cv_trailer_log_ptr                   = &Get_IPC_D2M_Buffer()->payload.cv_trailer_stream;
   #ifdef FEATURE_ENABLE
   Olp_Stream_T *olp_log_ptr   = &Get_IPC_D2M_Buffer()->payload.Olp_Object_Data;
   Bsis_Stream_T *bsis_log_ptr = &Get_IPC_D2M_Buffer()->payload.Bsis_IPC_Output;
   Mois_Stream_T *mois_log_ptr = &Get_IPC_D2M_Buffer()->payload.Mois_IPC_Output;
   #endif
#endif
   Static_Alignment_Log_Stream_T *alignment_log_ptr = &Get_IPC_D2M_Buffer()->payload.alignment_stream_data;
   Dynamic_Alignment_Log_Stream_T *da_log_ptr       = &Get_IPC_D2M_Buffer()->payload.dynamic_alignment_log_stream;
   Rdd_Stream_T *rdd_log_ptr                        = &Get_IPC_D2M_Buffer()->payload.rdd_stream_data;
   Rdd_Debug_Stream_T *rdd_debug_log_ptr            = &Get_IPC_D2M_Buffer()->payload.rdd_debug_data;
   ID_Stream_T *id_log_ptr                          = &Get_IPC_D2M_Buffer()->payload.interference_detection_data;
   Radar_Capability_Stream_T *rc_log_ptr            = &Get_IPC_D2M_Buffer()->payload.radar_capability_data;
   Vse_Stream_T *vse_log_ptr                        = &Get_IPC_M2D_Buffer()->payload.veh_data;
#if (DOWNSELECTION_ENABLE)
   Down_selection_Stream_T *ds_log_ptr = &Get_IPC_D2M_Buffer()->payload.downselection_data;
   TOI_DS_Stream_T *toi_ds_log_ptr     = &Get_IPC_D2M_Buffer()->payload.toi_ds_stream_data;
#else
   TOI_Stream_T *toi_log_ptr = &Get_IPC_D2M_Buffer()->payload.toi_stream_data;
#endif
   Header_Stream_T *header_log_ptr             = Get_Header_Log_Data_Ptr();
   MMIC_Stream_T *mmic_log_ptr                 = Get_MMIC_Log_Data_Ptr();
   Status_Stream_T *status_log_ptr             = Get_Status_Log_Data_Ptr();
   CDC_Stream_Combined_T *cdc_log_combined_ptr = Get_CDC_Combined_Log_Data_Ptr();
   Debug_Stream_T *debug_log_ptr               = Get_Debug_Log_Data_Ptr();

   std::memset(cdc_log_combined_ptr, 0, sizeof(CDC_Stream_Combined_T));

   const auto *detection_input_ptr =
      static_cast<const Detection_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::DETECTION_STREAM)]);
   const auto *header_input_ptr =
      static_cast<const Header_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::HEADER_STREAM)]);
   const auto *status_input_ptr =
      static_cast<const Status_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::STATUS_STREAM)]);
   const auto *rdd_input_ptr = static_cast<const Rdd_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::RDD_STREAM)]);
   const auto *vse_input_ptr = static_cast<const Vse_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::VSE_STREAM)]);
   const auto *debug_input_ptr =
      static_cast<const Debug_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::DEBUG_STREAM)]);
   const auto *cdc_input_combined_ptr =
      static_cast<const CDC_Stream_Combined_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::CDC_GEN8_STREAM)]);
   const auto *mmic_input_ptr =
      static_cast<const MMIC_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::MMIC_STREAM)]);
   const auto *alignment_input_ptr =
      static_cast<const Static_Alignment_Log_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::ALIGNMENT_STREAM)]);
   const auto *rc_input_ptr =
      static_cast<const Radar_Capability_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::RADAR_CAPABILITY_STREAM)]);
#if (DOWNSELECTION_ENABLE)
   const auto *ds_input_ptr =
      static_cast<const Down_selection_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::DOWN_SELECTION_STREAM)]);
   const auto *toi_ds_input_ptr =
      static_cast<const TOI_DS_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::TOI_DS_STREAM)]);
#else
   const auto *toi_input_ptr = static_cast<const TOI_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::TOI_STREAM)]);
#endif
   const auto *id_input_ptr = static_cast<const ID_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::ID_STREAM)]);
   const auto *da_input_ptr = static_cast<const Dynamic_Alignment_Log_Stream_T *>(
      radar_stream[enum_cast(SiL_Logging_Data_Source_T::DYNAMIC_ALIGNMENT_STREAM)]);

#ifdef TRACKER_ENABLED
   const auto *partner_sensor_input_ptr =
      static_cast<const Partner_Sensor_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::PARTNER_SENSOR_STREAM)]);
   const auto *sync_info_input_ptr =
      static_cast<const Sync_Info_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::SYNC_INFO_STREAM)]);
   const auto *veh_info_input_ptr =
      static_cast<const Vehicle_Info_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::VEHICLE_INFO_STREAM)]);
   const auto *trk_info_input_ptr =
      static_cast<const Tracker_Info_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::TRACKER_INFO_STREAM)]);
   const auto *time_info_input_ptr =
      static_cast<const Timing_Info_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::TIMING_INFO_STREAM)]);
   const auto *host_calib_input_ptr =
      static_cast<const Host_Calibs_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::HOST_CALIBS_STREAM)]);
   const auto *host_props_input_ptr =
      static_cast<const Host_Props_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::HOST_PROPS_STREAM)]);
   const auto *stat_env_input_ptr =
      static_cast<const Static_Env_Poly_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::STATIC_ENV_POLY_STREAM)]);
   const auto *fs_faults_input_ptr = static_cast<const Functional_Safety_Faults_Stream_T *>(
      radar_stream[enum_cast(SiL_Logging_Data_Source_T::FUNCTIONAL_SAFETY_FAULTS_STREAM)]);
   const auto *obj_list_input_ptr =
      static_cast<const Object_List_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::OBJECT_LIST_STREAM)]);
   const auto *processed_det_input_ptr = static_cast<const Processed_Detection_Stream_T *>(
      radar_stream[enum_cast(SiL_Logging_Data_Source_T::PROCESSED_DETECTION_STREAM)]);
   const auto *sensor_calib_input_ptr =
      static_cast<const Sensor_Calib_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::SENSOR_CALIB_STREAM)]);
   const auto *trailer_det_input_ptr =
      static_cast<const Trailer_Detector_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::TRAILER_DETECTOR_STREAM)]);
   const auto *cv_trailer_input_ptr =
      static_cast<const Cv_Trailer_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::CV_TRAILER_STREAM)]);
   #ifdef FEATURE_ENABLE
   const auto *olp_input_ptr = static_cast<const Olp_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::OLP_STREAM)]);
   const auto *bsis_input_ptr =
      static_cast<const Bsis_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::BSIS_STREAM)]);
   const auto *mois_input_ptr =
      static_cast<const Mois_Stream_T *>(radar_stream[enum_cast(SiL_Logging_Data_Source_T::MOIS_STREAM)]);
   #endif
#endif

   if (detection_input_ptr == nullptr)
   {
      write_statistical_report(ReportKind::FAULT, "Unknown scan : No det data. The mentioned scan is previous scan");
      no_det_data_flag = true;
      return false;
   }

   Set_Current_Scan_Index(detection_input_ptr->stream_hdr.scan_index);

   if (Previous_Scan_Index_Plus_One() <= detection_input_ptr->stream_hdr.scan_index)
   {
      if ((Previous_Scan_Index_Plus_One() != detection_input_ptr->stream_hdr.scan_index) && (Get_Previous_Scan_Index() != 0))
      {
         write_statistical_report(ReportKind::FAULT, "Jump in scan index");
      }

      if (detection_input_ptr->stream_hdr.scan_index == 0)
      {
         write_statistical_report(ReportKind::FAULT, "detection_input_ptr->stream_hdr.scan_index = 0");
         det_scan_index_is_zero_flag = true;
         return false;
      }

      if (match_checksum(detection_input_ptr->stream_hdr.checksum,
                         reinterpret_cast<const uint8_t *>(detection_input_ptr) + sizeof(detection_input_ptr->stream_hdr),
                         DETECTION_DATA_SIZE))
      {
         std::memcpy(det_log_ptr, detection_input_ptr, sizeof(Detection_Stream_T));
      }

      const uint16_t expected_scan_index = detection_input_ptr->stream_hdr.scan_index;
#if 0 // is NULL
      validate_and_copy_stream(
         "detection_debug_input_ptr", detection_debug_input_ptr, det_debug_log_ptr, expected_scan_index, DETECTION_DEBUG_DATA_SIZE, scan_index_mismatch_check_flag,
         scan_index_is_zero_flag, stream_is_null_flag);
#endif
      validate_and_copy_stream("header_input_ptr", header_input_ptr, header_log_ptr, expected_scan_index, HEADER_DATA_SIZE,
                               scan_index_mismatch_check_flag, scan_index_is_zero_flag, stream_is_null_flag);
      validate_and_copy_stream("status_input_ptr", status_input_ptr, status_log_ptr, expected_scan_index, STATUS_DATA_SIZE,
                               scan_index_mismatch_check_flag, scan_index_is_zero_flag, stream_is_null_flag);
      validate_and_copy_stream("rdd_input_ptr", rdd_input_ptr, rdd_log_ptr, expected_scan_index, RDD_DATA_SIZE,
                               scan_index_mismatch_check_flag, scan_index_is_zero_flag, stream_is_null_flag);

#if 0 // is NULL
      validate_and_copy_stream(
         "rdd_debug_input_ptr", rdd_debug_input_ptr, rdd_debug_log_ptr, expected_scan_index, RDD_DEBUG_DATA_SIZE, scan_index_mismatch_check_flag,
         scan_index_is_zero_flag, stream_is_null_flag);
#endif
      validate_and_copy_stream("vse_input_ptr", vse_input_ptr, vse_log_ptr, expected_scan_index, VSE_DATA_SIZE,
                               scan_index_mismatch_check_flag, scan_index_is_zero_flag, stream_is_null_flag);
#if 0 // is NULL
      validate_and_copy_stream(
         "debug_input_ptr", debug_input_ptr, debug_log_ptr, expected_scan_index, DEBUG_DATA_SIZE, scan_index_mismatch_check_flag,
         scan_index_is_zero_flag, stream_is_null_flag);
#endif
      validate_and_copy_stream("mmic_input_ptr", mmic_input_ptr, mmic_log_ptr, expected_scan_index, MMIC_DATA_SIZE,
                               scan_index_mismatch_check_flag, scan_index_is_zero_flag, stream_is_null_flag);
      validate_and_copy_stream("alignment_input_ptr", alignment_input_ptr, alignment_log_ptr, expected_scan_index,
                               ALIGNMENT_DATA_SIZE, scan_index_mismatch_check_flag, scan_index_is_zero_flag, stream_is_null_flag);
      validate_and_copy_stream("rc_input_ptr", rc_input_ptr, rc_log_ptr, expected_scan_index, RADAR_CAPABILITY_DATA_SIZE,
                               scan_index_mismatch_check_flag, scan_index_is_zero_flag, stream_is_null_flag);
#if (DOWNSELECTION_ENABLE)
      validate_and_copy_stream("ds_input_ptr", ds_input_ptr, ds_log_ptr, expected_scan_index, DOWN_SELECTION_DATA_SIZE,
                               scan_index_mismatch_check_flag, scan_index_is_zero_flag, stream_is_null_flag);
      validate_and_copy_stream("toi_ds_input_ptr", toi_ds_input_ptr, toi_ds_log_ptr, expected_scan_index, TOI_DS_DATA_SIZE,
                               scan_index_mismatch_check_flag, scan_index_is_zero_flag, stream_is_null_flag);
#else
      validate_and_copy_stream("toi_input_ptr", toi_input_ptr, toi_log_ptr, expected_scan_index, TOI_DATA_SIZE,
                               scan_index_mismatch_check_flag, scan_index_is_zero_flag, stream_is_null_flag);
#endif
      validate_and_copy_stream("id_input_ptr", id_input_ptr, id_log_ptr, expected_scan_index, ID_DATA_SIZE,
                               scan_index_mismatch_check_flag, scan_index_is_zero_flag, stream_is_null_flag);

      validate_and_copy_stream("da_input_ptr", da_input_ptr, da_log_ptr, expected_scan_index, DYNAMIC_ALIGNMENT_DATA_SIZE,
                               scan_index_mismatch_check_flag, scan_index_is_zero_flag, stream_is_null_flag);

#ifdef TRACKER_ENABLED
   #ifdef AL_TRACKER
      validate_and_copy_tracker_stream("partner_sensor_input_ptr", partner_sensor_input_ptr, partner_sensor_log_ptr,
                                       stream_is_null_flag);
   #endif
      if ((radar_position == REAR_LEFT) || (radar_position == FRONT_CENTER))
      {
         validate_and_copy_tracker_stream("sync_info_input_ptr", sync_info_input_ptr, sync_info_log_ptr, stream_is_null_flag);
         validate_and_copy_tracker_stream("veh_info_input_ptr", veh_info_input_ptr, veh_info_log_ptr, stream_is_null_flag);
         validate_and_copy_tracker_stream("trk_info_input_ptr", trk_info_input_ptr, trk_info_log_ptr, stream_is_null_flag);
         validate_and_copy_tracker_stream("time_info_input_ptr", time_info_input_ptr, time_info_log_ptr, stream_is_null_flag);
         validate_and_copy_tracker_stream("host_calib_input_ptr", host_calib_input_ptr, host_calibs_log_ptr, stream_is_null_flag);
         validate_and_copy_tracker_stream("host_props_input_ptr", host_props_input_ptr, host_props_log_ptr, stream_is_null_flag);
         validate_and_copy_tracker_stream("stat_env_input_ptr", stat_env_input_ptr, stat_env_log_ptr, stream_is_null_flag);
         validate_and_copy_tracker_stream("fs_faults_input_ptr", fs_faults_input_ptr, functional_safety_faults_log_ptr,
                                          stream_is_null_flag);
         validate_and_copy_tracker_stream("obj_list_input_ptr", obj_list_input_ptr, object_list_log_ptr, stream_is_null_flag);
         validate_and_copy_tracker_stream("processed_det_input_ptr", processed_det_input_ptr, processed_detection_log_ptr,
                                          stream_is_null_flag);
         validate_and_copy_tracker_stream("sensor_calib_input_ptr", sensor_calib_input_ptr, sensor_calib_log_ptr,
                                          stream_is_null_flag);
         validate_and_copy_tracker_stream("trailer_det_input_ptr", trailer_det_input_ptr, trailer_detector_log_ptr,
                                          stream_is_null_flag);
         validate_and_copy_tracker_stream("cv_trailer_input_ptr", cv_trailer_input_ptr, cv_trailer_log_ptr, stream_is_null_flag);
      }
   #ifdef FEATURE_ENABLE
      if (radar_position == REAR_LEFT)
      {
         validate_and_copy_stream("olp_input_ptr", olp_input_ptr, olp_log_ptr, expected_scan_index, OLP_DATA_SIZE,
                                  scan_index_mismatch_check_flag, scan_index_is_zero_flag, stream_is_null_flag);
      #if 0
         validate_and_copy_stream("bsis_input_ptr", bsis_input_ptr, bsis_log_ptr, expected_scan_index, BSIS_DATA_SIZE,
                                  scan_index_mismatch_check_flag, scan_index_is_zero_flag, stream_is_null_flag);
      #endif
      }
      if (radar_position == FRONT_CENTER)
      {
         validate_and_copy_stream("olp_input_ptr", olp_input_ptr, olp_log_ptr, expected_scan_index, OLP_DATA_SIZE,
                                  scan_index_mismatch_check_flag, scan_index_is_zero_flag, stream_is_null_flag);
         validate_and_copy_stream("mois_input_ptr", mois_input_ptr, mois_log_ptr, expected_scan_index, MOIS_DATA_SIZE,
                                  scan_index_mismatch_check_flag, scan_index_is_zero_flag, stream_is_null_flag);
      }
   #endif
#endif

#if 0
      // CDC stream handling with unique checks for bounds and saturation due to its nature of having no checksum and being a combined stream.
      if (cdc_input_combined_ptr != nullptr)
      {
         uint16_t num_of_cdc_records               = 0;
         uint16_t rIdx                             = 0;
         uint16_t dIdx                             = 0;
         static uint64_t out_of_bound_ridx_counter = 0;
         static uint64_t out_of_bound_didx_counter = 0;

         std::memcpy(cdc_log_combined_ptr, cdc_input_combined_ptr, sizeof(CDC_Stream_Combined_T));

         for (uint8_t i = 0; i < MAX_NO_CDC_CHUNKS; i++)
         {
            num_of_cdc_records += cdc_log_combined_ptr->cdc_stream[i].dyn_hdr.records_cnt;
            for (int j = 0; j < TOTAL_CDC_RECORDS_PER_FRAME; j++)
            {
               rIdx = cdc_log_combined_ptr->cdc_stream[i].CDC_Data[j].rng_dopp_idx.rng_idx;
               dIdx = cdc_log_combined_ptr->cdc_stream[i].CDC_Data[j].rng_dopp_idx.dopp_idx;
               dIdx = dIdx & CDC_DBIN_MASK;
               if (rIdx < 0 || rIdx >= SPBB_MAX_RANGE_BINS)
               {
                  write_statistical_report(ReportKind::FAULT, "rng_idx out of range : " + std::to_string(dIdx));
                  out_of_bound_ridx_counter++;
                  rIdx_dIdx_out_of_range_flag = true;
               }
               if (dIdx < 0 || dIdx >= SPBB_MAX_DOPPLER_FFT_SIZE)
               {
                  write_statistical_report(ReportKind::FAULT, "dopp_idx out of range : " + std::to_string(dIdx));
                  out_of_bound_didx_counter++;
                  rIdx_dIdx_out_of_range_flag = true;
               }
            }
         }

         if (get_output_control().CDC_SATURATION_CHECK != 0 && num_of_cdc_records >= SPBB_MAX_CDC_DBIN_COUNT_PER_FRAME)
         {
            write_statistical_report(ReportKind::FAULT, "CDC saturation.");
            cdc_saturated_flag = true;
         }
      }
      else
      {
         write_statistical_report(ReportKind::NULLPTR, "cdc_input_combined_ptr is a nullptr");
         stream_is_null_flag = true;
      }
#endif

      populate_ipc_m2d_one_time_with_stream_data(status_log_ptr);
      populate_ipc_misc_stream_data();
   }
   else
   {
      write_statistical_report(ReportKind::FAULT, "No new data");
   }

   Set_Previous_Scan_Index(detection_input_ptr->stream_hdr.scan_index);

   return !(scan_index_mismatch_check_flag || no_det_data_flag || cdc_saturated_flag || rIdx_dIdx_out_of_range_flag ||
            scan_index_is_zero_flag || stream_is_null_flag || det_scan_index_is_zero_flag);
}
