#include "csv_trace.h"
#include "boost/pfr.hpp"
#include "emblib_ipc_data.h"
#include "output_control.h"
#include "serialize_object.h"
#include "sil_wrapper_common.h"
#include <cassert>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <optional>

namespace fs = std::filesystem;

#ifdef WIN32
constexpr size_t MAX_PATH_SIZE = 260;
#elif defined(__GNUC__)
constexpr size_t MAX_PATH_SIZE = 4096;
#endif

#define SIX (6U)

enum class CsvTrace : uint8_t
{
   ALIGNMENT_DATA_INPUT,
   DYNAMIC_ALIGNMENT_DATA_INPUT,
   DEBUG_DATA_INPUT,
   DETECTIONS_DATA_INPUT,
   DOWN_SELECTION_DATA_INPUT,
   HEADER_DATA_INPUT,
   ROT_ISOOBJECT_DATA_INPUT,
   ALIGNMENT_DATA_OUTPUT,
   DYNAMIC_ALIGNMENT_DATA_OUTPUT,
   DEBUG_DATA_OUTPUT,
   DETECTIONS_DATA_OUTPUT,
   DOWN_SELECTION_DATA_OUTPUT,
   HEADER_DATA_OUTPUT,
   ROT_ISOOBJECT_DATA_OUTPUT,
   CDC_BUFFER_OUTPUT,
};
constexpr std::basic_string_view<fs::path::value_type> CsvTraceStr(CsvTrace csv_trace);
static std::ofstream open_csv_trace_file(CsvTrace csv_trace);
void print_detection_input();
void print_alignment_input();
void print_dynamic_alignment_input();
void print_debug_input();
void print_down_selection_input();
void print_header_input();
void print_rot_isoobject_input();
void print_detection_output();
void print_alignment_output();
void print_dynamic_alignment_output();
void print_debug_output();
void print_down_selection_output();
void print_header_output();
void print_rot_isoobject_output();
void print_cdc_buffer_output();

namespace csv_trace
{
// NOLINTBEGIN(cppcoreguidelines-avoid-non-const-global-variables)
std::ofstream detection_input_fstream;
std::ofstream detection_output_fstream;
std::ofstream alignment_input_fstream;
std::ofstream dynamic_alignment_input_fstream;
std::ofstream alignment_output_fstream;
std::ofstream dynamic_alignment_output_fstream;
std::ofstream debug_input_fstream;
std::ofstream debug_output_fstream;
std::ofstream down_selection_input_fstream;
std::ofstream down_selection_output_fstream;
std::ofstream header_input_fstream;
std::ofstream header_output_fstream;
std::ofstream rot_isoobject_input_fstream;
std::ofstream rot_isoobject_output_fstream;
std::ofstream cdc_buffer_output_fstream;
// NOLINTEND(cppcoreguidelines-avoid-non-const-global-variables)
} // namespace csv_trace

// EXPOSED FUNCTIONS
void print_csv_input_data()
{
   print_detection_input();
   print_alignment_input();
   print_dynamic_alignment_input();
   print_debug_input();
   print_down_selection_input();
   print_header_input();
   print_rot_isoobject_input();
}

void print_csv_output_data()
{
   print_detection_output();
   print_alignment_output();
   print_dynamic_alignment_output();
   print_debug_output();
   print_down_selection_output();
   print_header_output();
   print_rot_isoobject_output();
}

void print_csv_cdc_output_data()
{
   print_cdc_buffer_output();
}

void close_csv_trace_files()
{
   csv_trace::detection_input_fstream.close();
   csv_trace::detection_output_fstream.close();
   csv_trace::alignment_input_fstream.close();
   csv_trace::alignment_output_fstream.close();
   csv_trace::debug_input_fstream.close();
   csv_trace::debug_output_fstream.close();
   csv_trace::down_selection_input_fstream.close();
   csv_trace::down_selection_output_fstream.close();
   csv_trace::header_input_fstream.close();
   csv_trace::header_output_fstream.close();
   csv_trace::rot_isoobject_input_fstream.close();
   csv_trace::rot_isoobject_output_fstream.close();
   csv_trace::cdc_buffer_output_fstream.close();
}

// HELPERS
static std::ofstream open_csv_trace_file(CsvTrace csv_trace)
{
   fs::path output_path = get_output_path().append("CSV").append(Get_Radar_Position_Str());
   fs::create_directories(output_path);
   fs::path::string_type csv_filename_prefix = get_input_log_filename()
                                                  .substr(0, get_input_log_filename().find_last_of('.'))
                                                  .append(1, '_')
                                                  .append(Get_Radar_Position_Str().begin(), Get_Radar_Position_Str().end())
                                                  .append(CsvTraceStr(csv_trace));
#ifdef WIN32
   const fs::path::string_type file_path = output_path.append(csv_filename_prefix + L".csv").wstring();
#else
   const fs::path::string_type file_path = output_path.append(csv_filename_prefix + ".csv").string();
#endif
   return std::ofstream{file_path.data(), std::ios::out};
}

constexpr std::basic_string_view<fs::path::value_type> CsvTraceStr(CsvTrace csv_trace)
{
#ifdef WIN32
   switch (csv_trace)
   {
      case CsvTrace::ALIGNMENT_DATA_INPUT:
         return L"_ALIGNMENT_DATA_INPUT";
      case CsvTrace::DYNAMIC_ALIGNMENT_DATA_INPUT:
         return L"_DYNAMIC_ALIGNMENT_DATA_INPUT";
      case CsvTrace::DEBUG_DATA_INPUT:
         return L"_DEBUG_DATA_INPUT";
      case CsvTrace::DETECTIONS_DATA_INPUT:
         return L"_DETECTIONS_DATA_INPUT";
      case CsvTrace::DOWN_SELECTION_DATA_INPUT:
         return L"_DOWN_SELECTION_DATA_INPUT";
      case CsvTrace::HEADER_DATA_INPUT:
         return L"_HEADER_DATA_INPUT";
      case CsvTrace::ROT_ISOOBJECT_DATA_INPUT:
         return L"_ROT_ISOOBJECT_DATA_INPUT";
      case CsvTrace::ALIGNMENT_DATA_OUTPUT:
         return L"_ALIGNMENT_DATA_OUTPUT";
      case CsvTrace::DYNAMIC_ALIGNMENT_DATA_OUTPUT:
         return L"_DYNAMIC_ALIGNMENT_DATA_OUTPUT";
      case CsvTrace::DEBUG_DATA_OUTPUT:
         return L"_DEBUG_DATA_OUTPUT";
      case CsvTrace::DETECTIONS_DATA_OUTPUT:
         return L"_DETECTIONS_DATA_OUTPUT";
      case CsvTrace::DOWN_SELECTION_DATA_OUTPUT:
         return L"_DOWN_SELECTION_DATA_OUTPUT";
      case CsvTrace::HEADER_DATA_OUTPUT:
         return L"_HEADER_DATA_OUTPUT";
      case CsvTrace::ROT_ISOOBJECT_DATA_OUTPUT:
         return L"_ROT_ISOOBJECT_DATA_OUTPUT";
      case CsvTrace::CDC_BUFFER_OUTPUT:
         return L"_CDC_BUFFER_OUTPUT";
   }
#else
   switch (csv_trace)
   {
      case CsvTrace::ALIGNMENT_DATA_INPUT:
         return "_ALIGNMENT_DATA_INPUT";
      case CsvTrace::DYNAMIC_ALIGNMENT_DATA_INPUT:
         return "_DYNAMIC_ALIGNMENT_DATA_INPUT";
      case CsvTrace::DEBUG_DATA_INPUT:
         return "_DEBUG_DATA_INPUT";
      case CsvTrace::DETECTIONS_DATA_INPUT:
         return "_DETECTIONS_DATA_INPUT";
      case CsvTrace::DOWN_SELECTION_DATA_INPUT:
         return "_DOWN_SELECTION_DATA_INPUT";
      case CsvTrace::HEADER_DATA_INPUT:
         return "_HEADER_DATA_INPUT";
      case CsvTrace::ROT_ISOOBJECT_DATA_INPUT:
         return "_ROT_ISOOBJECT_DATA_INPUT";
      case CsvTrace::ALIGNMENT_DATA_OUTPUT:
         return "_ALIGNMENT_DATA_OUTPUT";
      case CsvTrace::DYNAMIC_ALIGNMENT_DATA_OUTPUT:
         return "_DYNAMIC_ALIGNMENT_DATA_OUTPUT";
      case CsvTrace::DEBUG_DATA_OUTPUT:
         return "_DEBUG_DATA_OUTPUT";
      case CsvTrace::DETECTIONS_DATA_OUTPUT:
         return "_DETECTIONS_DATA_OUTPUT";
      case CsvTrace::DOWN_SELECTION_DATA_OUTPUT:
         return "_DOWN_SELECTION_DATA_OUTPUT";
      case CsvTrace::HEADER_DATA_OUTPUT:
         return "_HEADER_DATA_OUTPUT";
      case CsvTrace::ROT_ISOOBJECT_DATA_OUTPUT:
         return "_ROT_ISOOBJECT_DATA_OUTPUT";
      case CsvTrace::CDC_BUFFER_OUTPUT:
         return "_CDC_BUFFER_OUTPUT";
   }
#endif
}

// INPUT
void print_detection_input()
{
   if (!csv_trace::detection_input_fstream.is_open())
   {
      csv_trace::detection_input_fstream = open_csv_trace_file(CsvTrace::DETECTIONS_DATA_INPUT);
      csv_trace::detection_input_fstream << "detection_scan_index,";
      // print_csv_header(csv_trace::detection_input_fstream, Get_IPC_D2M_Buffer()->payload.det_data);
   }
   csv_trace::detection_input_fstream << Get_Current_Scan_Index() << ',';
   // print_csv_data(csv_trace::detection_input_fstream, Get_IPC_D2M_Buffer()->payload.det_data);
}

void print_alignment_input()
{
   // TODO(gen7v2)
   if (!csv_trace::alignment_input_fstream.is_open())
   {
      csv_trace::alignment_input_fstream = open_csv_trace_file(CsvTrace::ALIGNMENT_DATA_INPUT);
      csv_trace::alignment_input_fstream << "detection_scan_index,";
      // print_csv_header(csv_trace::alignment_input_fstream, Get_IPC_D2M_Buffer()->payload.alignment_stream_data);
   }
   csv_trace::alignment_input_fstream << Get_Current_Scan_Index() << ',';
   // print_csv_data(csv_trace::alignment_input_fstream, Get_IPC_D2M_Buffer()->payload.alignment_stream_data);
}

void print_dynamic_alignment_input()
{
   // TODO(gen7v2)
   if (!csv_trace::dynamic_alignment_input_fstream.is_open())
   {
      csv_trace::dynamic_alignment_input_fstream = open_csv_trace_file(CsvTrace::DYNAMIC_ALIGNMENT_DATA_INPUT);
      csv_trace::dynamic_alignment_input_fstream << "detection_scan_index,";
      // print_csv_header(csv_trace::dynamic_alignment_input_fstream, Get_IPC_D2M_Buffer()->payload.dynamic_alignment_log_stream);
   }
   csv_trace::dynamic_alignment_input_fstream << Get_Current_Scan_Index() << ',';
   // print_csv_data(csv_trace::dynamic_alignment_input_fstream, Get_IPC_D2M_Buffer()->payload.dynamic_alignment_log_stream);
}

void print_debug_input()
{
   if (!csv_trace::debug_input_fstream.is_open())
   {
      csv_trace::debug_input_fstream = open_csv_trace_file(CsvTrace::DEBUG_DATA_INPUT);
      csv_trace::debug_input_fstream << "detection_scan_index,";
      // print_csv_header(csv_trace::debug_input_fstream, *Get_Debug_Log_Data_Ptr());
   }
   csv_trace::debug_input_fstream << Get_Current_Scan_Index() << ',';
   // print_csv_data(csv_trace::debug_input_fstream, *Get_Debug_Log_Data_Ptr());
}

void print_down_selection_input()
{
#if (DOWNSELECTION_ENABLE)
   if (!csv_trace::down_selection_input_fstream.is_open())
   {
      csv_trace::down_selection_input_fstream = open_csv_trace_file(CsvTrace::DOWN_SELECTION_DATA_INPUT);
      csv_trace::down_selection_input_fstream << "detection_scan_index,";
      // print_csv_header(csv_trace::down_selection_input_fstream, Get_IPC_D2M_Buffer()->payload.downselection_data);
   }
   csv_trace::down_selection_input_fstream << Get_Current_Scan_Index() << ',';
   // print_csv_data(csv_trace::down_selection_input_fstream, Get_IPC_D2M_Buffer()->payload.downselection_data);
#endif
}

void print_header_input()
{
   if (!csv_trace::header_input_fstream.is_open())
   {
      csv_trace::header_input_fstream = open_csv_trace_file(CsvTrace::HEADER_DATA_INPUT);
      csv_trace::header_input_fstream << "detection_scan_index,";
      // print_csv_header(csv_trace::header_input_fstream, *Get_Header_Log_Data_Ptr());
   }
   csv_trace::header_input_fstream << Get_Current_Scan_Index() << ',';
   // print_csv_data(csv_trace::header_input_fstream, *Get_Header_Log_Data_Ptr());
}

void print_rot_isoobject_input()
{
#if 0
   #ifndef TRACKER_DISABLED
   // TODO(gen7v2)
   auto &fstr = csv_trace::rot_isoobject_input_fstream;
   if (!csv_trace::rot_isoobject_input_fstream.is_open())
   {
      csv_trace::rot_isoobject_input_fstream = open_csv_trace_file(CsvTrace::ROT_ISOOBJECT_DATA_INPUT);
      csv_trace::rot_isoobject_input_fstream << "detection_scan_index,";
      fstr << "size,version,checksum,scan_index,error_info,module_time_ms,";
      fstr << "rot_object_list_timestamp,tracker_start_timestamp,";
      for (int i = 0; i < ROT_NUMBER_OF_REDUCED_OBJECT_TRACKS; i++)
      {
         fstr << "vcs_x_posn_" << i << ",";
         fstr << "vcs_y_posn_" << i << ",";
         fstr << "vcs_x_vel_" << i << ",";
         fstr << "vcs_y_vel_" << i << ",";
         fstr << "vcs_x_acc_" << i << ",";
         fstr << "vcs_y_acc_" << i << ",";
         fstr << "vcs_heading_" << i << ",";
         fstr << "vcs_pointing_" << i << ",";
         for (int j = 0; j < SIX; j++)
         {
            fstr << "vcs_state_variance_" << i << "_" << j << ",";
         }
         for (int j = 0; j < THREE; j++)
         {
            fstr << "vcs_supplemental_state_covariance_" << i << "_" << j << ",";
         }
         fstr << "vcs_curvature_" << i << ",";
         fstr << "iso_x_posn_" << i << ",";
         fstr << "iso_y_posn_" << i << ",";
         fstr << "iso_x_vel_" << i << ",";
         fstr << "iso_y_vel_" << i << ",";
         fstr << "iso_x_acc_" << i << ",";
         fstr << "iso_y_acc_" << i << ",";
         fstr << "iso_orientation_" << i << ",";
         fstr << "iso_orientation_var_" << i << ",";
         fstr << "iso_orientation_rate_" << i << ",";
         fstr << "iso_orientation_rate_var_" << i << ",";
         fstr << "iso_x_posn_var_" << i << ",";
         fstr << "iso_y_posn_var_" << i << ",";
         fstr << "iso_xy_posn_cov_" << i << ",";
         fstr << "iso_x_vel_var_" << i << ",";
         fstr << "iso_y_vel_var_" << i << ",";
         fstr << "iso_xy_vel_cov_" << i << ",";
         fstr << "iso_x_acc_var_" << i << ",";
         fstr << "iso_y_acc_var_" << i << ",";
         fstr << "iso_xy_acc_cov_" << i << ",";
         fstr << "speed_" << i << ",";
         fstr << "tang_accel_" << i << ",";
         fstr << "length_" << i << ",";
         fstr << "length_var_" << i << ",";
         fstr << "width_" << i << ",";
         fstr << "width_var_" << i << ",";
         fstr << "time_since_created_" << i << ",";
         fstr << "time_since_published_" << i << ",";
         fstr << "time_since_stage_start_" << i << ",";
         fstr << "existence_probability_" << i << ",";
         fstr << "mirror_prob_" << i << ",";
         fstr << "radar_cross_section_" << i << ",";
         fstr << "otg_height_" << i << ",";
         fstr << "confidence_level_" << i << ",";
         fstr << "probability_pedestrian_" << i << ",";
         fstr << "probability_car_" << i << ",";
         fstr << "probability_motorcycle_" << i << ",";
         fstr << "probability_bicycle_" << i << ",";
         fstr << "probability_truck_" << i << ",";
         fstr << "probability_undet_" << i << ",";
         fstr << "probability_underdrivable_" << i << ",";
         fstr << "movable_prob_" << i << ",";
         fstr << "id_" << i << ",";
         fstr << "unique_id_" << i << ",";
         fstr << "ndets_" << i << ",";
         fstr << "num_dets_used_in_rr_msmt_update_" << i << ",";
         fstr << "sensor_src_" << i << ",";
         fstr << "K_Unused16_1_" << i << ",";
         fstr << "reference_point_" << i << ",";
         fstr << "object_status_" << i << ",";
         fstr << "object_class_" << i << ",";
         fstr << "movement_status_" << i << ",";
         fstr << "occlusion_status_" << i << ",";
         fstr << "underdrivable_status_" << i << ",";
         fstr << "f_onguardrail_" << i << ",";
         fstr << "trk_fltr_type_" << i << ",";
      }
      fstr << "tracker_elapsed_time, tracker_index, K_Unused32_1, K_Unused32_2, number_of_objects, K_Unused16_2,";
      fstr << "K_Unused8_1, overall_fault_status, K_Unused16_1, K_Unused32_1,object_faults_unused, f_track_accelerations_faulty,";
      fstr << "f_track_velocities_faulty, f_track_positions_faulty, K_Unused8_1,K_Unused16_1, K_Unused32_1,";
      for (int i = 0; i < ROT_NUM_TOTAL_RADAR_SENSORS; i++)
      {
         fstr << "radar_sensor_calib_faults_unused_" << i << ",";
         fstr << "radar_sensor_calib_faults_f_track_accelerations_faulty_" << i << ",";
         fstr << "radar_sensor_calib_faults_f_track_velocities_faulty_" << i << ",";
         fstr << "radar_sensor_calib_faults_K_Unused8_1_" << i << ",";
         fstr << "radar_sensor_calib_faults_K_Unused16_1_" << i << ",";
         fstr << "radar_sensor_calib_faults_K_Unused32_1_" << i << ",";
      }
      for (int i = 0; i < ROT_NUM_TOTAL_RADAR_SENSORS; i++)
      {
         fstr << "radar_sensor_faults_K_Unused32_1_" << i << ",";
         fstr << "radar_sensor_faults_K_Unused16_1_" << i << ",";
         fstr << "radar_sensor_faults_K_Unused8_1_" << i << ",";
         fstr << "radar_sensor_faults_look_index_no_increase_" << i << ",";
         fstr << "radar_sensor_faults_sensor_vs_tracker_timestamp_divergence_" << i << ",";
         fstr << "radar_sensor_faults_unused_" << i << ",";
      }
      fstr << "K_Unused32_1, K_Unused16_1, K_Unused8_1,vehicle_index_no_increase, host_speed_invalid, host_yawrate_invalid,";
      fstr << "host_longitudinal_acceleration_invalid, host_lateral_acceleration_invalid, ununsed,";
      fstr
         << "K_Unused32_1, K_Unused16_1, K_Unused8_1,time_us_no_increase, cnt_loops_no_increase, elapsed_time_below_lower_limit,";
      fstr << "elapsed_time_above_upper_limit, ununsed";
      fstr << "\n";
   }
   csv_trace::rot_isoobject_input_fstream << Get_Current_Scan_Index() << ',';
   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.stream_hdr.size << ",";
   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.stream_hdr.version << ",";
   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.stream_hdr.checksum << ",";
   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.stream_hdr.scan_index << ",";
   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.stream_hdr.error_info << ",";
   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.stream_hdr.module_time_ms << ",";

   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list_timestamp_lsb << ",";
   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.tracker_start_timestamp_lsb << ",";

   for (int i = 0; i < ROT_NUMBER_OF_REDUCED_OBJECT_TRACKS; i++)
   {
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].vcs_x_posn << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].vcs_y_posn << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].vcs_x_vel << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].vcs_y_vel << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].vcs_x_acc << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].vcs_y_acc << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].vcs_heading << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].vcs_pointing << ",";
      for (int j = 0; j < SIX; j++)
      {
         fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].vcs_state_variance[j] << ",";
      }
      for (int j = 0; j < THREE; j++)
      {
         fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].vcs_supplemental_state_covariance[j]
              << ",";
      }
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].vcs_curvature << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_x_posn << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_y_posn << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_x_vel << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_y_vel << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_x_acc << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_y_acc << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_orientation << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_orientation_var << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_orientation_rate << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_orientation_rate_var << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_x_posn_var << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_y_posn_var << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_xy_posn_cov << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_x_vel_var << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_y_vel_var << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_xy_vel_cov << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_x_acc_var << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_y_acc_var << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_xy_acc_cov << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].speed << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].tang_accel << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].length << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].length_var << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].width << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].width_var << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].time_since_created << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].time_since_published << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].time_since_stage_start << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].existence_probability << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].mirror_prob << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].radar_cross_section << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].otg_height << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].confidence_level << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].probability_pedestrian << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].probability_car << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].probability_motorcycle << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].probability_bicycle << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].probability_truck << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].probability_undet << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].probability_underdrivable_ocg << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].movable_prob << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].id << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].unique_id << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].ndets << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].num_dets_used_in_rr_msmt_update << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].sensor_src << ",";
      // fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].K_Unused16_1 << ",";
      fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].reference_point)
           << ",";
      fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].object_status)
           << ",";
      fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].object_class)
           << ",";
      fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].movement_status)
           << ",";
      fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].occlusion_status)
           << ",";
      fstr << static_cast<int16_t>(
                 Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].underdrivable_status_ocg)
           << ",";
      fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].f_onguardrail)
           << ",";
      fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].trk_fltr_type)
           << ",";
   }

   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.tracker_elapsed_time << ",";
   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.tracker_index << ",";
   // fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.K_Unused32_1 << ",";
   // fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.K_Unused32_2 << ",";
   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.number_of_objects << ",";
   // fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.K_Unused16_2 << ",";
   fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.K_Unused8_1) << ",";
   fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.overall_fault_status)
        << ",";
   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.K_Unused8_1 << ",";
   // fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.K_Unused32_1 << ",";
   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.object_faults.K_Unused16_1 << ",";
   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.object_faults.K_Unused8_1 << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.object_faults.f_track_positions_faulty)
   //      << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.object_faults.f_track_velocities_faulty)
   //      << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.object_faults.f_track_accelerations_faulty)
   //      << ",";
   // fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.object_faults.unused)
   //      << ",";
   // for (int i = 0; i < ROT_NUM_TOTAL_RADAR_SENSORS; i++)
   // {
      // fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_calib_faults[i].K_Unused32_1
      //      << ",";
      // fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_calib_faults[i].K_Unused16_1
      //      << ",";
      // fstr << static_cast<int16_t>(
      //            Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_calib_faults[i].K_Unused8_1)
      //      << ",";
      // fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()
      //                                 ->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_calib_faults[i]
      //                                 .mounting_pos_is_invalid)
      //      << ",";
      // fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()
      //                                 ->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_calib_faults[i]
      //                                 .polarity_is_invalid)
      //      << ",";
      // fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()
      //                                 ->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_calib_faults[i]
      //                                 .boresight_angle_is_invalid)
      //      << ",";
      // fstr << static_cast<int16_t>(
      //            Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_calib_faults[i].unused)
      //      << ",";
   // }
   // for (int i = 0; i < ROT_NUM_TOTAL_RADAR_SENSORS; i++)
   // {
   //    fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_faults[i].K_Unused32_1 << ",";
   //    fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_faults[i].K_Unused16_1 << ",";
   //    fstr << static_cast<int16_t>(
   //               Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_faults[i].K_Unused8_1)
   //         << ",";
   //    fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()
   //                                    ->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_faults[i]
   //                                    .look_index_no_increase)
   //         << ",";
   //    fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()
   //                                    ->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_faults[i]
   //                                    .sensor_vs_tracker_timestamp_divergence)
   //         << ",";
   //    fstr << static_cast<int16_t>(
   //               Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_faults[i].unused)
   //         << ",";
   // }
   // fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.host_info_faults.K_Unused32_1 << ",";
   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.host_info_faults.K_Unused16_1 << ",";
   fstr << static_cast<int16_t>(
              Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.host_info_faults.K_Unused8_1)
        << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.host_info_faults.vehicle_index_no_increase)
   //      << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.host_info_faults.host_speed_invalid)
   //      << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.host_info_faults.host_yawrate_invalid)
   //      << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()
   //               ->payload.rot_object_data.rot_output.all_scl_faults.host_info_faults.host_longitudinal_acceleration_invalid)
   //      << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()
   //               ->payload.rot_object_data.rot_output.all_scl_faults.host_info_faults.host_lateral_acceleration_invalid)
   //      << ",";
   // fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.host_info_faults.ununsed)
   //      << ",";

   // fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.core_info_faults.K_Unused32_1 << ",";
   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.core_info_faults.K_Unused16_1 << ",";
   fstr << static_cast<int16_t>(
              Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.core_info_faults.K_Unused8_1)
        << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.core_info_faults.time_us_no_increase)
   //      << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.core_info_faults.cnt_loops_no_increase)
   //      << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()
   //               ->payload.rot_object_data.rot_output.all_scl_faults.core_info_faults.elapsed_time_below_lower_limit)
   //      << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()
   //               ->payload.rot_object_data.rot_output.all_scl_faults.core_info_faults.elapsed_time_above_upper_limit)
   //      << ",";
   // fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.core_info_faults.ununsed);
   fstr << "\n";
   #endif
#endif
}

// OUTPUT
void print_detection_output()
{
   if (!csv_trace::detection_output_fstream.is_open())
   {
      csv_trace::detection_output_fstream = open_csv_trace_file(CsvTrace::DETECTIONS_DATA_OUTPUT);
      csv_trace::detection_output_fstream << "detection_scan_index,";
      // print_csv_header(csv_trace::detection_output_fstream, Get_IPC_D2M_Buffer()->payload.det_data);
   }
   csv_trace::detection_output_fstream << Get_Current_Scan_Index() << ',';
   // print_csv_data(csv_trace::detection_output_fstream, Get_IPC_D2M_Buffer()->payload.det_data);
}

void print_alignment_output()
{
   // TODO(gen7v2)
   if (!csv_trace::alignment_output_fstream.is_open())
   {
      csv_trace::alignment_output_fstream = open_csv_trace_file(CsvTrace::ALIGNMENT_DATA_OUTPUT);
      csv_trace::alignment_output_fstream << "detection_scan_index,";
      // print_csv_header(csv_trace::alignment_output_fstream, Get_IPC_D2M_Buffer()->payload.alignment_stream_data);
   }
   csv_trace::alignment_output_fstream << Get_Current_Scan_Index() << ',';
   // print_csv_data(csv_trace::alignment_output_fstream, Get_IPC_D2M_Buffer()->payload.alignment_stream_data);
}

void print_dynamic_alignment_output()
{
   // TODO(gen7v2)
   if (!csv_trace::dynamic_alignment_output_fstream.is_open())
   {
      csv_trace::dynamic_alignment_output_fstream = open_csv_trace_file(CsvTrace::DYNAMIC_ALIGNMENT_DATA_OUTPUT);
      csv_trace::dynamic_alignment_output_fstream << "detection_scan_index,";
      // print_csv_header(csv_trace::dynamic_alignment_output_fstream, Get_IPC_D2M_Buffer()->payload.dynamic_alignment_log_stream);
   }
   csv_trace::dynamic_alignment_output_fstream << Get_Current_Scan_Index() << ',';
   // print_csv_data(csv_trace::dynamic_alignment_output_fstream, Get_IPC_D2M_Buffer()->payload.dynamic_alignment_log_stream);
}

void print_debug_output()
{
   if (!csv_trace::debug_output_fstream.is_open())
   {
      csv_trace::debug_output_fstream = open_csv_trace_file(CsvTrace::DEBUG_DATA_OUTPUT);
      csv_trace::debug_output_fstream << "detection_scan_index,";
      // print_csv_header(csv_trace::debug_output_fstream, *Get_Debug_Log_Data_Ptr());
   }
   csv_trace::debug_output_fstream << Get_Current_Scan_Index() << ',';
   // print_csv_data(csv_trace::debug_output_fstream, *Get_Debug_Log_Data_Ptr());
}

void print_down_selection_output()
{
#if (DOWNSELECTION_ENABLE)
   if (!csv_trace::down_selection_output_fstream.is_open())
   {
      csv_trace::down_selection_output_fstream = open_csv_trace_file(CsvTrace::DOWN_SELECTION_DATA_OUTPUT);
      csv_trace::down_selection_output_fstream << "detection_scan_index,";
      // print_csv_header(csv_trace::down_selection_output_fstream, Get_IPC_D2M_Buffer()->payload.downselection_data);
   }
   csv_trace::down_selection_output_fstream << Get_Current_Scan_Index() << ',';
   // print_csv_data(csv_trace::down_selection_output_fstream, Get_IPC_D2M_Buffer()->payload.downselection_data);
#endif
}

void print_header_output()
{
   if (!csv_trace::header_output_fstream.is_open())
   {
      csv_trace::header_output_fstream = open_csv_trace_file(CsvTrace::HEADER_DATA_OUTPUT);
      csv_trace::header_output_fstream << "detection_scan_index,";
      // print_csv_header(csv_trace::header_output_fstream, *Get_Header_Log_Data_Ptr());
   }
   csv_trace::header_output_fstream << Get_Current_Scan_Index() << ',';
   // print_csv_data(csv_trace::header_output_fstream, *Get_Header_Log_Data_Ptr());
}

void print_rot_isoobject_output()
{
#if 0
   #ifndef TRACKER_DISABLED
   // TODO(gen7v2)
   auto &fstr = csv_trace::rot_isoobject_output_fstream;
   if (!csv_trace::rot_isoobject_output_fstream.is_open())
   {
      csv_trace::rot_isoobject_output_fstream = open_csv_trace_file(CsvTrace::ROT_ISOOBJECT_DATA_OUTPUT);
      csv_trace::rot_isoobject_output_fstream << "detection_scan_index,";
      fstr << "size,version,checksum,scan_index,error_info,module_time_ms,";
      fstr << "rot_object_list_timestamp,tracker_start_timestamp,";
      for (int i = 0; i < ROT_NUMBER_OF_REDUCED_OBJECT_TRACKS; i++)
      {
         fstr << "vcs_x_posn_" << i << ",";
         fstr << "vcs_y_posn_" << i << ",";
         fstr << "vcs_x_vel_" << i << ",";
         fstr << "vcs_y_vel_" << i << ",";
         fstr << "vcs_x_acc_" << i << ",";
         fstr << "vcs_y_acc_" << i << ",";
         fstr << "vcs_heading_" << i << ",";
         fstr << "vcs_pointing_" << i << ",";
         for (int j = 0; j < SIX; j++)
         {
            fstr << "vcs_state_variance_" << i << "_" << j << ",";
         }
         for (int j = 0; j < THREE; j++)
         {
            fstr << "vcs_supplemental_state_covariance_" << i << "_" << j << ",";
         }
         fstr << "vcs_curvature_" << i << ",";
         fstr << "iso_x_posn_" << i << ",";
         fstr << "iso_y_posn_" << i << ",";
         fstr << "iso_x_vel_" << i << ",";
         fstr << "iso_y_vel_" << i << ",";
         fstr << "iso_x_acc_" << i << ",";
         fstr << "iso_y_acc_" << i << ",";
         fstr << "iso_orientation_" << i << ",";
         fstr << "iso_orientation_var_" << i << ",";
         fstr << "iso_orientation_rate_" << i << ",";
         fstr << "iso_orientation_rate_var_" << i << ",";
         fstr << "iso_x_posn_var_" << i << ",";
         fstr << "iso_y_posn_var_" << i << ",";
         fstr << "iso_xy_posn_cov_" << i << ",";
         fstr << "iso_x_vel_var_" << i << ",";
         fstr << "iso_y_vel_var_" << i << ",";
         fstr << "iso_xy_vel_cov_" << i << ",";
         fstr << "iso_x_acc_var_" << i << ",";
         fstr << "iso_y_acc_var_" << i << ",";
         fstr << "iso_xy_acc_cov_" << i << ",";
         fstr << "speed_" << i << ",";
         fstr << "tang_accel_" << i << ",";
         fstr << "length_" << i << ",";
         fstr << "length_var_" << i << ",";
         fstr << "width_" << i << ",";
         fstr << "width_var_" << i << ",";
         fstr << "time_since_created_" << i << ",";
         fstr << "time_since_published_" << i << ",";
         fstr << "time_since_stage_start_" << i << ",";
         fstr << "existence_probability_" << i << ",";
         fstr << "mirror_prob_" << i << ",";
         fstr << "radar_cross_section_" << i << ",";
         fstr << "otg_height_" << i << ",";
         fstr << "confidence_level_" << i << ",";
         fstr << "probability_pedestrian_" << i << ",";
         fstr << "probability_car_" << i << ",";
         fstr << "probability_motorcycle_" << i << ",";
         fstr << "probability_bicycle_" << i << ",";
         fstr << "probability_truck_" << i << ",";
         fstr << "probability_undet_" << i << ",";
         fstr << "probability_underdrivable_" << i << ",";
         fstr << "movable_prob_" << i << ",";
         fstr << "id_" << i << ",";
         fstr << "unique_id_" << i << ",";
         fstr << "ndets_" << i << ",";
         fstr << "num_dets_used_in_rr_msmt_update_" << i << ",";
         fstr << "sensor_src_" << i << ",";
         fstr << "K_Unused16_1_" << i << ",";
         fstr << "reference_point_" << i << ",";
         fstr << "object_status_" << i << ",";
         fstr << "object_class_" << i << ",";
         fstr << "movement_status_" << i << ",";
         fstr << "occlusion_status_" << i << ",";
         fstr << "underdrivable_status_" << i << ",";
         fstr << "f_onguardrail_" << i << ",";
         fstr << "trk_fltr_type_" << i << ",";
      }
      fstr << "tracker_elapsed_time, tracker_index, K_Unused32_1, K_Unused32_2, number_of_objects, K_Unused16_2,";
      fstr << "K_Unused8_1, overall_fault_status, K_Unused16_1, K_Unused32_1,object_faults_unused, f_track_accelerations_faulty,";
      fstr << "f_track_velocities_faulty, f_track_positions_faulty, K_Unused8_1,K_Unused16_1, K_Unused32_1,";
      for (int i = 0; i < ROT_NUM_TOTAL_RADAR_SENSORS; i++)
      {
         fstr << "radar_sensor_calib_faults_unused_" << i << ",";
         fstr << "radar_sensor_calib_faults_f_track_accelerations_faulty_" << i << ",";
         fstr << "radar_sensor_calib_faults_f_track_velocities_faulty_" << i << ",";
         fstr << "radar_sensor_calib_faults_K_Unused8_1_" << i << ",";
         fstr << "radar_sensor_calib_faults_K_Unused16_1_" << i << ",";
         fstr << "radar_sensor_calib_faults_K_Unused32_1_" << i << ",";
      }
      for (int i = 0; i < ROT_NUM_TOTAL_RADAR_SENSORS; i++)
      {
         fstr << "radar_sensor_faults_K_Unused32_1_" << i << ",";
         fstr << "radar_sensor_faults_K_Unused16_1_" << i << ",";
         fstr << "radar_sensor_faults_K_Unused8_1_" << i << ",";
         fstr << "radar_sensor_faults_look_index_no_increase_" << i << ",";
         fstr << "radar_sensor_faults_sensor_vs_tracker_timestamp_divergence_" << i << ",";
         fstr << "radar_sensor_faults_unused_" << i << ",";
      }
      fstr << "K_Unused32_1, K_Unused16_1, K_Unused8_1,vehicle_index_no_increase, host_speed_invalid, host_yawrate_invalid,";
      fstr << "host_longitudinal_acceleration_invalid, host_lateral_acceleration_invalid, ununsed,";
      fstr
         << "K_Unused32_1, K_Unused16_1, K_Unused8_1,time_us_no_increase, cnt_loops_no_increase, elapsed_time_below_lower_limit,";
      fstr << "elapsed_time_above_upper_limit, ununsed";
      fstr << "\n";
   }
   csv_trace::rot_isoobject_output_fstream << Get_Current_Scan_Index() << ',';
   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.stream_hdr.size << ",";
   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.stream_hdr.version << ",";
   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.stream_hdr.checksum << ",";
   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.stream_hdr.scan_index << ",";
   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.stream_hdr.error_info << ",";
   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.stream_hdr.module_time_ms << ",";

   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list_timestamp_lsb << ",";
   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.tracker_start_timestamp_lsb << ",";

   for (int i = 0; i < ROT_NUMBER_OF_REDUCED_OBJECT_TRACKS; i++)
   {
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].vcs_x_posn << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].vcs_y_posn << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].vcs_x_vel << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].vcs_y_vel << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].vcs_x_acc << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].vcs_y_acc << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].vcs_heading << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].vcs_pointing << ",";
      for (int j = 0; j < SIX; j++)
      {
         fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].vcs_state_variance[j] << ",";
      }
      for (int j = 0; j < THREE; j++)
      {
         fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].vcs_supplemental_state_covariance[j]
              << ",";
      }
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].vcs_curvature << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_x_posn << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_y_posn << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_x_vel << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_y_vel << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_x_acc << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_y_acc << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_orientation << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_orientation_var << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_orientation_rate << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_orientation_rate_var << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_x_posn_var << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_y_posn_var << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_xy_posn_cov << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_x_vel_var << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_y_vel_var << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_xy_vel_cov << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_x_acc_var << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_y_acc_var << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].iso_xy_acc_cov << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].speed << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].tang_accel << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].length << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].length_var << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].width << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].width_var << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].time_since_created << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].time_since_published << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].time_since_stage_start << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].existence_probability << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].mirror_prob << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].radar_cross_section << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].otg_height << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].confidence_level << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].probability_pedestrian << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].probability_car << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].probability_motorcycle << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].probability_bicycle << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].probability_truck << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].probability_undet << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].probability_underdrivable_ocg << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].movable_prob << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].id << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].unique_id << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].ndets << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].num_dets_used_in_rr_msmt_update << ",";
      fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].sensor_src << ",";
      // fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].K_Unused16_1 << ",";
      fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].reference_point)
           << ",";
      fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].object_status)
           << ",";
      fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].object_class)
           << ",";
      fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].movement_status)
           << ",";
      fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].occlusion_status)
           << ",";
      fstr << static_cast<int16_t>(
                 Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].underdrivable_status_ocg)
           << ",";
      fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].f_onguardrail)
           << ",";
      fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.rot_object_list[i].trk_fltr_type)
           << ",";
   }

   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.tracker_elapsed_time << ",";
   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.tracker_index << ",";
   // fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.K_Unused32_1 << ",";
   // fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.K_Unused32_2 << ",";
   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.number_of_objects << ",";
   // fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.K_Unused16_2 << ",";
   fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.K_Unused8_1) << ",";
   fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.overall_fault_status)
        << ",";
   // fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.K_Unused16_1 << ",";
   // fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.K_Unused32_1 << ",";
   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.object_faults.K_Unused16_1 << ",";
   fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.object_faults.K_Unused8_1 << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.object_faults.f_track_positions_faulty)
   //      << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.object_faults.f_track_velocities_faulty)
   //      << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.object_faults.f_track_accelerations_faulty)
   //      << ",";
   // fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.object_faults.unused)
   //      << ",";
   // for (int i = 0; i < ROT_NUM_TOTAL_RADAR_SENSORS; i++)
   // {
   //    fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_calib_faults[i].K_Unused32_1
   //         << ",";
   //    fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_calib_faults[i].K_Unused16_1
   //         << ",";
   //    fstr << static_cast<int16_t>(
   //               Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_calib_faults[i].K_Unused8_1)
   //         << ",";
   //    fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()
   //                                    ->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_calib_faults[i]
   //                                    .mounting_pos_is_invalid)
   //         << ",";
   //    fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()
   //                                    ->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_calib_faults[i]
   //                                    .polarity_is_invalid)
   //         << ",";
   //    fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()
   //                                    ->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_calib_faults[i]
   //                                    .boresight_angle_is_invalid)
   //         << ",";
   //    fstr << static_cast<int16_t>(
   // Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_calib_faults[i].unused)
   //         << ",";
   // }
   // for (int i = 0; i < ROT_NUM_TOTAL_RADAR_SENSORS; i++)
   // {
   //    fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_faults[i].K_Unused32_1 << ",";
   //    fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_faults[i].K_Unused16_1 << ",";
   //    fstr << static_cast<int16_t>(
   //               Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_faults[i].K_Unused8_1)
   //         << ",";
   //    fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()
   //                                    ->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_faults[i]
   //                                    .look_index_no_increase)
   //         << ",";
   //    fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()
   //                                    ->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_faults[i]
   //                                    .sensor_vs_tracker_timestamp_divergence)
   //         << ",";
   //    fstr << static_cast<int16_t>(
   //               Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.radar_sensor_faults[i].unused)
   //         << ",";
   // }
   // fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.host_info_faults.K_Unused32_1 << ",";
   // fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.host_info_faults.K_Unused16_1 << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.host_info_faults.K_Unused8_1)
   //      << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.host_info_faults.vehicle_index_no_increase)
   //      << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.host_info_faults.host_speed_invalid)
   //      << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.host_info_faults.host_yawrate_invalid)
   //      << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()
   //               ->payload.rot_object_data.rot_output.all_scl_faults.host_info_faults.host_longitudinal_acceleration_invalid)
   //      << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()
   //               ->payload.rot_object_data.rot_output.all_scl_faults.host_info_faults.host_lateral_acceleration_invalid)
   //      << ",";
   // fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.host_info_faults.ununsed)
   //      << ",";

   // fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.core_info_faults.K_Unused32_1 << ",";
   // fstr << Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.core_info_faults.K_Unused16_1 << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.core_info_faults.K_Unused8_1)
   //      << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.core_info_faults.time_us_no_increase)
   //      << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.core_info_faults.cnt_loops_no_increase)
   //      << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()
   //               ->payload.rot_object_data.rot_output.all_scl_faults.core_info_faults.elapsed_time_below_lower_limit)
   //      << ",";
   // fstr << static_cast<int16_t>(
   //            Get_IPC_D2M_Buffer()
   //               ->payload.rot_object_data.rot_output.all_scl_faults.core_info_faults.elapsed_time_above_upper_limit)
   //      << ",";
   // fstr << static_cast<int16_t>(Get_IPC_D2M_Buffer()->payload.rot_object_data.rot_output.all_scl_faults.core_info_faults.ununsed);
   fstr << "\n";
   #endif
#endif
}

void print_cdc_buffer_output()
{
   if (!csv_trace::cdc_buffer_output_fstream.is_open())
   {
      csv_trace::cdc_buffer_output_fstream = open_csv_trace_file(CsvTrace::CDC_BUFFER_OUTPUT);
      // HEADER
      csv_trace::cdc_buffer_output_fstream << "scan_index,";
      csv_trace::cdc_buffer_output_fstream << "rng_idx,";
      csv_trace::cdc_buffer_output_fstream << "dopp_idx,";
      csv_trace::cdc_buffer_output_fstream << "nci_data,";
      for (uint8_t bvIdx = 0; bvIdx < BV_COMPRESSED_WORD_COUNT; bvIdx++)
      {
         csv_trace::cdc_buffer_output_fstream << "cdc_out_bv_" << std::to_string(bvIdx) << "_Data,";
      }
      csv_trace::cdc_buffer_output_fstream << "\n";
   }
   // DATA
   for (uint8_t i = 0; i < MAX_NO_CDC_CHUNKS; i++)
   {
      for (uint16_t j = 0; j < Get_CDC_Combined_Log_Data_Ptr()->cdc_stream[i].dyn_hdr.records_cnt; j++)
      {
         csv_trace::cdc_buffer_output_fstream << Get_CDC_Combined_Log_Data_Ptr()->cdc_stream[i].dyn_hdr.scan_index << ",";
         csv_trace::cdc_buffer_output_fstream << Get_CDC_Combined_Log_Data_Ptr()->cdc_stream[i].CDC_Data[j].rng_dopp_idx.rng_idx
                                              << ",";
         csv_trace::cdc_buffer_output_fstream
            << (Get_CDC_Combined_Log_Data_Ptr()->cdc_stream[i].CDC_Data[j].rng_dopp_idx.dopp_idx & 0x3FFF) << ",";
         csv_trace::cdc_buffer_output_fstream << Get_CDC_Combined_Log_Data_Ptr()->cdc_stream[i].CDC_Data[j].rng_dopp_idx.nci_data
                                              << ",";
         for (uint8_t k = 0; k < BV_COMPRESSED_WORD_COUNT; k++)
         {
            csv_trace::cdc_buffer_output_fstream
               << static_cast<unsigned int>(Get_CDC_Combined_Log_Data_Ptr()->cdc_stream[i].CDC_Data[j].cdc_out_bv[k]) << ",";
         }
         csv_trace::cdc_buffer_output_fstream << "\n";
      }
   }
}
