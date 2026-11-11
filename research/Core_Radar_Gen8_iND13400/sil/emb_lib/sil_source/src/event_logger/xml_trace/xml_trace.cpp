#include "xml_trace.h"
#include "emblib_ipc_data.h"
#include "output_control.h"
#include "pugixml.hpp"
#include "sil_wrapper_common.h"
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <ctime>
#include <filesystem>
#include <numeric>
#include <optional>
#include <string>
#include <vector>

using pugi::xml_document;
namespace fs = std::filesystem;
namespace xml_trace
{
// need to be global because they are set by init and acccessed by save_XML_file
static std::optional<xml_document> input_xml_document  = std::nullopt;
static std::optional<xml_document> output_xml_document = std::nullopt;
// NOLINTEND(cppcoreguidelines-avoid-non-const-global-variables)
} // namespace xml_trace

static auto initiliaze_document(Xml_Format_T xml_format) -> pugi::xml_node;
static auto get_record_header(pugi::xml_node &data_tag) -> pugi::xml_node;
static void detection_log_data(pugi::xml_node &record_header);
static void detection_debug_stream_info(pugi::xml_node &record_header);
static void vse_info(pugi::xml_node &record_header);
static void mounting_info(pugi::xml_node &record_header);
static void mnr_blockage_info(pugi::xml_node &record_header);
static void radar_capability_info(pugi::xml_node &record_header);
static void static_alignment_log_info(pugi::xml_node &record_header);
static void dynamic_alignment_log_info(pugi::xml_node &record_header);
static void interference_det_log_info(pugi::xml_node &record_header);
static void moving_object_info(pugi::xml_node &record_header);
static void moving_isoobject_info(pugi::xml_node &record_header);
static void stationary_object_info(pugi::xml_node &record_header);
static void stationary_isoobject_info(pugi::xml_node &record_header);
static void ocg_output_info(pugi::xml_node &record_header);
static void roadmodel_info(pugi::xml_node &record_header);
static void radar_detections(pugi::xml_node &record_header);
static void object_class(pugi::xml_node &f360_objects, uint8_t object_class);
static void ocg_status(pugi::xml_node &f360_objects, uint8_t ocg_status);
static auto detections_sorted_by_range(const Detection_Stream_T &det_stream) -> std::vector<std::pair<uint16_t, float32_t>>;
static const char *truncate_float(float32_t flt);
static const char *pad_int(int integer);

/// EXPOSED FUNCTIONS
void save_XML_files()
{
   fs::path output_path = get_output_path().append("XML").append(Get_Radar_Position_Str());
   fs::create_directories(output_path);
   fs::path::string_type xml_filename_prefix = get_input_log_filename()
                                                  .substr(0, get_input_log_filename().find_last_of('.'))
                                                  .append(1, '_')
                                                  .append(Get_Radar_Position_Str().begin(), Get_Radar_Position_Str().end());
   fs::path output_path_copy = output_path;
#ifdef WIN32
   const fs::path input_file_name  = output_path.append(xml_filename_prefix + L"_SIL_XML_Input.xml");
   const fs::path output_file_name = output_path_copy.append(xml_filename_prefix + L"_SIL_XML_Output.xml");
#else
   const fs::path input_file_name  = output_path.append(xml_filename_prefix + "_SIL_XML_Input.xml");
   const fs::path output_file_name = output_path_copy.append(xml_filename_prefix + "_SIL_XML_Output.xml");
#endif
   if (xml_trace::input_xml_document.has_value())
   {
      xml_trace::input_xml_document->save_file(input_file_name.c_str());
      // in sequential mode, we want to create a new document
      xml_trace::input_xml_document = std::nullopt;
   }
   if (xml_trace::output_xml_document.has_value())
   {
      xml_trace::output_xml_document->save_file(output_file_name.c_str());
      // in sequential mode, we want to create a new document
      xml_trace::output_xml_document = std::nullopt;
   }
}

void Populate_Valid_Data_to_XML(Xml_Format_T xml_format)
{
   // initialize the document
   pugi::xml_node data_tag = initiliaze_document(xml_format);
   // create tag for current scan index
   std::string record_header_text =
      std::string(Get_Radar_Position_Str()) + "_DETECTION_LOG_DATA_" + std::to_string(Get_Current_Scan_Index());
   pugi::xml_node record_header = data_tag.append_child(record_header_text.c_str());

   // start filling info
   detection_log_data(record_header);
   if (get_output_control().Output_XML_Trace_Files.Det_Debug_Data_Info != 0U)
   {
      detection_debug_stream_info(record_header);
   }
   if (get_output_control().Output_XML_Trace_Files.VSE_Data != 0U)
   {
      vse_info(record_header);
   }
   if (get_output_control().Output_XML_Trace_Files.Mounting_Info != 0U)
   {
      mounting_info(record_header);
   }
   if (get_output_control().Output_XML_Trace_Files.MNR_blockage != 0U)
   {
      mnr_blockage_info(record_header);
   }
   if (get_output_control().Output_XML_Trace_Files.Alignment_Info != 0U)
   {
      static_alignment_log_info(record_header);
      dynamic_alignment_log_info(record_header);
   }
   if (get_output_control().Output_XML_Trace_Files.Interference_Dets != 0U)
   {
      interference_det_log_info(record_header);
   }
   if (get_output_control().Output_XML_Trace_Files.Self_Dets != 0U)
   {
      radar_detections(record_header);
   }
   if (get_output_control().Output_XML_Trace_Files.Moving_Objects != 0U)
   {
      moving_object_info(record_header);
      moving_isoobject_info(record_header);
   }
   if (get_output_control().Output_XML_Trace_Files.Static_Objects != 0U)
   {
      stationary_object_info(record_header);
      stationary_isoobject_info(record_header);
   }
   if (get_output_control().Output_XML_Trace_Files.Radar_Capability_Info != 0U)
   {
      radar_capability_info(record_header);
   }
   if (get_output_control().Output_XML_Trace_Files.OCG_info != 0U)
   {
      ocg_output_info(record_header);
   }
   if (get_output_control().Output_XML_Trace_Files.roadmodel_info != 0U)
   {
      roadmodel_info(record_header);
   }
}

/// INTERNAL FUNCTIONS
// Initializes the document if not initialized, returns the <DATA> tag
static auto initiliaze_document(Xml_Format_T xml_format) -> pugi::xml_node
{
   std::optional<xml_document> &xml =
      (xml_format == Xml_Format_T::SIL_XML_IN) ? xml_trace::input_xml_document : xml_trace::output_xml_document;
   if (xml.has_value())
   {
      return xml->find_child([](const pugi::xml_node &child) { return std::strcmp(child.name(), "DATA") == 0; });
   }
   xml                              = xml_document{};
   pugi::xml_node ver               = xml->append_child(pugi::node_declaration);
   ver.append_attribute("version")  = "1.0";
   ver.append_attribute("encoding") = "UTF-8";
   xml->append_child(pugi::node_comment).set_value("Aptiv SIL component configuration");
   pugi::xml_node data_tag     = xml->append_child("DATA");
   pugi::xml_node header       = data_tag.append_child("HEADER");
   pugi::xml_node filename_tag = header.append_child("FILENAME");
#ifdef WIN32 // windows uses `wchar_t` instead of `char` for paths
   const auto input_log_filename = get_input_log_filename();
   filename_tag.text()           = std::string(input_log_filename.cbegin(), input_log_filename.cend()).c_str();
#else
   filename_tag.text()             = get_input_log_filename().c_str();
#endif
   pugi::xml_node pc_time_tag = header.append_child("PC_TIME");
   static std::array<char, sizeof("1970-01-01T00:00:00+0000")> pc_time_str;
   const auto time = std::time(nullptr);
   std::strftime(pc_time_str.data(), pc_time_str.size(), "%FT%T%z", std::localtime(&time));
   pc_time_tag.text()               = pc_time_str.data();
   pugi::xml_node customer_name_tag = header.append_child("CUSTOMER_NAME");
   customer_name_tag.text()         = "GEN7";
   pugi::xml_node radar_pos_tag     = header.append_child("RADAR_POS");
   radar_pos_tag.text()             = Get_Radar_Position_Str().data();
   return data_tag;
}

// Returns the <position_DETECTION_LOG_DATA_scanindex> tag for the current scan index
static auto get_record_header(pugi::xml_node &data_tag) -> pugi::xml_node
{
   std::string record_header_text =
      std::string(Get_Radar_Position_Str()) + "_DETECTION_LOG_DATA_" + std::to_string(Get_Current_Scan_Index());
   pugi::xml_node record_header = data_tag.append_child(record_header_text.c_str());
   return record_header;
}

static void detection_log_data(pugi::xml_node &record_header)
{
   const auto *det_stream      = &Get_IPC_D2M_Buffer()->payload.det_data;
   pugi::xml_node det_log_data = record_header.append_child("DETECTION_LOG_DATA");
   // stream header
   pugi::xml_node stream_hdr                     = det_log_data.append_child("STREAM_HDR");
   stream_hdr.append_attribute("checksum")       = det_stream->stream_hdr.checksum;
   stream_hdr.append_attribute("error_info")     = det_stream->stream_hdr.error_info;
   stream_hdr.append_attribute("module_time_ms") = det_stream->stream_hdr.module_time_ms;
   stream_hdr.append_attribute("scan_index")     = det_stream->stream_hdr.scan_index;
   stream_hdr.append_attribute("size")           = det_stream->stream_hdr.size;
   stream_hdr.append_attribute("version")        = det_stream->stream_hdr.version;
   // TODO(gen7v2)
   det_log_data.append_attribute("\n\t\tnum_sp_detections") = det_stream->det_list_property.num_sp_detections;
   det_log_data.append_attribute("\n\t\tnum_fp_detections") = det_stream->det_list_property.num_fp_detections;
   // det_log_data.append_attribute("\n\t\trest_count")        = det_stream->det_list_property.rest_count;
   det_log_data.append_attribute("\n\t\tdoppler_coverage") = det_stream->det_list_property.doppler_coverage;
   det_log_data.append_attribute("\n\t\trange_coverage")   = det_stream->det_list_property.range_coverage;
   det_log_data.append_attribute("\n\t\tlook_type")        = det_stream->det_list_property.look_type;
   det_log_data.append_attribute("\n\t\tscanindex")        = det_stream->det_list_property.scanindex;
   det_log_data.append_attribute("\n\t\tlookindex")        = det_stream->det_list_property.lookindex;
   pugi::xml_node af_data                                  = det_log_data.append_child("AF_DATA");
   af_data.append_attribute("num_af_det")                  = det_stream->num_af_det;
   for (int i = 0; i < AF_MAX_NUM_DET; i++)
   {
      pugi::xml_node af_data_info                     = af_data.append_child("RAN_AF_DATA");
      std::string ran_name                            = "ran[" + std::to_string(i) + "]";
      af_data_info.append_attribute(ran_name.c_str()) = truncate_float(det_stream->af_dets[i].ran);
   }
   for (int i = 0; i < AF_MAX_NUM_DET; i++)
   {
      pugi::xml_node af_data_info                     = af_data.append_child("VEL_AF_DATA");
      std::string vel_name                            = "vel[" + std::to_string(i) + "]";
      af_data_info.append_attribute(vel_name.c_str()) = truncate_float(det_stream->af_dets[i].vel);
   }
   for (int i = 0; i < AF_MAX_NUM_DET; i++)
   {
      pugi::xml_node af_data_info                     = af_data.append_child("POW_AF_DATA");
      std::string pow_name                            = "pow[" + std::to_string(i) + "]";
      af_data_info.append_attribute(pow_name.c_str()) = truncate_float(det_stream->af_dets[i].pow);
   }
   for (int i = 0; i < AF_MAX_NUM_DET; i++)
   {
      pugi::xml_node af_data_info                     = af_data.append_child("SNR_AF_DATA");
      std::string snr_name                            = "snr[" + std::to_string(i) + "]";
      af_data_info.append_attribute(snr_name.c_str()) = truncate_float(det_stream->af_dets[i].snr);
   }
   for (int i = 0; i < AF_MAX_NUM_DET; i++)
   {
      pugi::xml_node af_data_info                       = af_data.append_child("THETA_AF_DATA");
      std::string theta_name                            = "theta[" + std::to_string(i) + "]";
      af_data_info.append_attribute(theta_name.c_str()) = truncate_float(det_stream->af_dets[i].theta);
   }
   for (int i = 0; i < AF_MAX_NUM_DET; i++)
   {
      pugi::xml_node af_data_info                     = af_data.append_child("PHI_AF_DATA");
      std::string phi_name                            = "phi[" + std::to_string(i) + "]";
      af_data_info.append_attribute(phi_name.c_str()) = truncate_float(det_stream->af_dets[i].phi);
   }
   for (int i = 0; i < AF_MAX_NUM_DET; i++)
   {
      pugi::xml_node af_data_info                     = af_data.append_child("RCS_AF_DATA");
      std::string rcs_name                            = "rcs[" + std::to_string(i) + "]";
      af_data_info.append_attribute(rcs_name.c_str()) = truncate_float(det_stream->af_dets[i].rcs);
   }
   for (int i = 0; i < AF_MAX_NUM_DET; i++)
   {
      pugi::xml_node af_data_info                          = af_data.append_child("SPEC_RES_AF_DATA");
      std::string spec_res_name                            = "spec_res[" + std::to_string(i) + "]";
      af_data_info.append_attribute(spec_res_name.c_str()) = truncate_float(det_stream->af_dets[i].spec_res);
   }
   for (int i = 0; i < AF_MAX_NUM_DET; i++)
   {
      pugi::xml_node af_data_info                         = af_data.append_child("AZ_CONF_DATA");
      std::string az_conf_name                            = "az_conf[" + std::to_string(i) + "]";
      af_data_info.append_attribute(az_conf_name.c_str()) = det_stream->af_dets[i].az_conf;
   }
   for (int i = 0; i < AF_MAX_NUM_DET; i++)
   {
      pugi::xml_node af_data_info                         = af_data.append_child("EL_CONF_DATA");
      std::string el_conf_name                            = "el_conf[" + std::to_string(i) + "]";
      af_data_info.append_attribute(el_conf_name.c_str()) = det_stream->af_dets[i].el_conf;
   }
   for (int i = 0; i < AF_MAX_NUM_DET; i++)
   {
      pugi::xml_node af_data_info                                 = af_data.append_child("F_SINGLE_TARGET_DATA");
      std::string f_single_target_name                            = "f_single_target[" + std::to_string(i) + "]";
      af_data_info.append_attribute(f_single_target_name.c_str()) = det_stream->af_dets[i].f_single_target;
   }
   for (int i = 0; i < AF_MAX_NUM_DET; i++)
   {
      pugi::xml_node af_data_info                                   = af_data.append_child("F_SUPERRES_TARGET_DATA");
      std::string f_superres_target_name                            = "f_superres_target[" + std::to_string(i) + "]";
      af_data_info.append_attribute(f_superres_target_name.c_str()) = det_stream->af_dets[i].f_superres_target;
   }
   for (int i = 0; i < AF_MAX_NUM_DET; i++)
   {
      pugi::xml_node af_data_info                            = af_data.append_child("F_BISTATIC_DATA");
      std::string f_bistatic_name                            = "f_bistatic[" + std::to_string(i) + "]";
      af_data_info.append_attribute(f_bistatic_name.c_str()) = det_stream->af_dets[i].f_bistatic;
   }
}

static void detection_debug_stream_info(pugi::xml_node &record_header)
{
   const auto *det_debug_stream = &Get_IPC_D2M_Buffer()->payload.det_debug_data;
   pugi::xml_node det_log_data  = record_header.append_child("DETECTION_DEBUG_LOG_DATA");
   // stream header
   pugi::xml_node stream_hdr                     = det_log_data.append_child("STREAM_HDR");
   stream_hdr.append_attribute("checksum")       = det_debug_stream->stream_hdr.checksum;
   stream_hdr.append_attribute("error_info")     = det_debug_stream->stream_hdr.error_info;
   stream_hdr.append_attribute("module_time_ms") = det_debug_stream->stream_hdr.module_time_ms;
   stream_hdr.append_attribute("scan_index")     = det_debug_stream->stream_hdr.scan_index;
   stream_hdr.append_attribute("size")           = det_debug_stream->stream_hdr.size;
   stream_hdr.append_attribute("version")        = det_debug_stream->stream_hdr.version;

   // det_log_data.append_attribute("\n\t\tnum_af_stage_one") = det_debug_stream->af_det_debug_data.num_af_stage_one;
   // det_log_data.append_attribute("\n\t\tnum_af_stage_two") = det_debug_stream->af_det_debug_data.num_af_stage_two;
   // det_log_data.append_attribute("\n\t\tnum_af_superres")  = det_debug_stream->af_det_debug_data.num_af_superres;
   // det_log_data.append_attribute("\n\t\tnum_af_1a2el")     = det_debug_stream->af_det_debug_data.num_af_1a2el;
   // for (int i = 0; i < AF_MAX_NUM_DET; i++)
   // {
   //    std::string prob_1stazhypo_name = "\n\t\tprob_1stazhypo[" + std::to_string(i) + "]";
   //    det_log_data.append_attribute(prob_1stazhypo_name.c_str()) =
   //       truncate_float(det_debug_stream->af_det_debug_data.prob_1stazhypo[i]);
   // }
   for (int i = 0; i < NUM_TX_CHANNELS * NUM_RX_CHANNELS; i++)
   {
      std::string est_rx_tx_amp_name = "\n\t\test_rx_tx_amp[" + std::to_string(i) + "]";
      det_log_data.append_attribute(est_rx_tx_amp_name.c_str()) =
         truncate_float(det_debug_stream->af_det_debug_data.est_rx_tx_amp[i]);
   }
   // for (int i = 0; i < AF_MAX_NUM_DET; i++)
   // {
   //    std::string f_peak_det_name                            = "\n\t\tf_peak_det[" + std::to_string(i) + "]";
   //    det_log_data.append_attribute(f_peak_det_name.c_str()) = det_debug_stream->af_det_debug_data.f_peak_det[i];
   // }
   // det_log_data.append_attribute("\n\t\tbistatic_count")     = det_debug_stream->af_det_debug_data.bistatic_count;
   // det_log_data.append_attribute("\n\t\taf_xput_peak")       = truncate_float(det_debug_stream->af_det_debug_data.af_xput_peak);
   // det_log_data.append_attribute("\n\t\taf_xput_inst")       = truncate_float(det_debug_stream->af_det_debug_data.af_xput_inst);
   // det_log_data.append_attribute("\n\t\tc66_error_code")     = det_debug_stream->af_det_debug_data.c66_error_code;
   // det_log_data.append_attribute("\n\t\ttrigger_missed_cnt") = det_debug_stream->af_det_debug_data.trigger_missed_cnt;
   // det_log_data.append_attribute("\n\t\tK_Unused16_1")       = det_debug_stream->af_det_debug_data.K_Unused16_1;
   for (int i = 0; i < AF_MAX_NUM_DET; i++)
   {
      std::string f_1az2el_name                            = "\n\t\tf_1az2el[" + std::to_string(i) + "]";
      det_log_data.append_attribute(f_1az2el_name.c_str()) = det_debug_stream->af_debug_detections[i].f_1az2el;
   }
   // for (int i = 0; i < AF_MAX_NUM_DET; i++)
   // {
   //    std::string af_type_name                            = "\n\t\taf_type[" + std::to_string(i) + "]";
   //    det_log_data.append_attribute(af_type_name.c_str()) = det_debug_stream->af_det_debug_data.af_type[i];
   // }
   for (int i = 0; i < AF_MAX_NUM_DET; i++)
   {
      std::string az_af_type_name                            = "\n\t\taz_af_type[" + std::to_string(i) + "]";
      det_log_data.append_attribute(az_af_type_name.c_str()) = det_debug_stream->af_debug_detections[i].az_af_type;
   }
   for (int i = 0; i < AF_MAX_NUM_DET; i++)
   {
      std::string el_af_type_name                            = "\n\t\tel_af_type[" + std::to_string(i) + "]";
      det_log_data.append_attribute(el_af_type_name.c_str()) = det_debug_stream->af_debug_detections[i].el_af_type;
   }
   // det_log_data.append_attribute("\n\t\txcp_mode")    = det_debug_stream->af_det_debug_data.xcp_mode;
   // det_log_data.append_attribute("\n\t\tK_Unused8_1") = det_debug_stream->af_det_debug_data.K_Unused8_1;
}

static void radar_detections(pugi::xml_node &record_header)
{
   pugi::xml_node self_det_info_tag = record_header.append_child("SELF_DETECTION_INFO");
   const Detection_Stream_T &af_det = Get_IPC_D2M_Buffer()->payload.det_data;
   // TODO(chinmay): confirm valid/invalid
   self_det_info_tag.append_attribute("valid")              = af_det.num_af_det;
   self_det_info_tag.append_attribute("invalid")            = AF_MAX_NUM_DET - af_det.num_af_det;
   const std::vector<std::pair<uint16_t, float32_t>> sorted = detections_sorted_by_range(af_det);

   static_assert(AF_MAX_NUM_DET <= UINT16_MAX);
   uint16_t target_count = 0;
   for (uint16_t i = 0; i < AF_MAX_NUM_DET; i++)
   {
      const auto idx = sorted[i].first;
      if (af_det.af_dets[idx].ran > 0)
      {
         // this check is needed, otherwise there are detections where everything is zero
         std::string detection_tag_string             = "Detection_" + std::to_string(target_count);
         pugi::xml_node detection_tag                 = self_det_info_tag.append_child(detection_tag_string.data());
         detection_tag.append_attribute("range")      = truncate_float(af_det.af_dets[idx].ran);
         detection_tag.append_attribute("range_rate") = truncate_float(af_det.af_dets[idx].vel);
         detection_tag.append_attribute("azimuth")    = truncate_float(af_det.af_dets[idx].theta);
         detection_tag.append_attribute("elevation")  = truncate_float(af_det.af_dets[idx].phi);
         // TODO(gen7v2)
         // detection_tag.append_attribute("amplitude")               = truncate_float(af_det.amp[idx]);
         detection_tag.append_attribute("snr")                     = truncate_float(af_det.af_dets[idx].snr);
         detection_tag.append_attribute("power_density")           = truncate_float(af_det.af_dets[idx].pow);
         detection_tag.append_attribute("azimuth_confidence")      = truncate_float(af_det.af_dets[idx].az_conf);
         detection_tag.append_attribute("elevation_confidence")    = truncate_float(af_det.af_dets[idx].el_conf);
         detection_tag.append_attribute("radar_cross_section")     = truncate_float(af_det.af_dets[idx].rcs);
         detection_tag.append_attribute("super_resolution_target") = truncate_float(af_det.af_dets[idx].f_superres_target);
         detection_tag.append_attribute("bistatic_target")         = truncate_float(af_det.af_dets[idx].f_bistatic);
         detection_tag.append_attribute("rdd_index")               = af_det.af_dets[idx].rdd_idx;
         target_count++;
      }
   }
}

// Returns (index, range) sorted by range
static auto detections_sorted_by_range(const Detection_Stream_T &det_stream) -> std::vector<std::pair<uint16_t, float32_t>>
{
   auto sorted = std::vector<std::pair<uint16_t, float32_t>>();
   sorted.reserve(AF_MAX_NUM_DET);
   static_assert(AF_MAX_NUM_DET <= UINT16_MAX);
   for (uint16_t i = 0; i < AF_MAX_NUM_DET; i++)
   {
      sorted.emplace_back(i, det_stream.af_dets[i].ran);
   }
   std::sort(sorted.begin(), sorted.end(), [](const auto &lesser, const auto &greater) { return lesser.second < greater.second; });
   return sorted;
}

static void vse_info(pugi::xml_node &record_header)
{
   pugi::xml_node vse_log_data_tag   = record_header.append_child("VSE_LOG_DATA");
   const auto *vse_log_ptr           = &Get_IPC_M2D_Buffer()->payload.veh_data;
   const auto *veh_raw               = &vse_log_ptr->veh_raw_data[vse_log_ptr->latest_raw_index];
   const auto *veh_raw_misc          = &vse_log_ptr->veh_raw_misc;
   pugi::xml_node veh_speed          = vse_log_data_tag.append_child("veh_speed");
   veh_speed.text()                  = truncate_float(ceilf(veh_raw->ego_vehicle_speed * 100.0F) / 100.0F);
   pugi::xml_node veh_yaw            = vse_log_data_tag.append_child("veh_yaw");
   veh_yaw.text()                    = truncate_float(ceilf(veh_raw->ego_yaw_rate * 100.0F) / 100.0F);
   pugi::xml_node veh_pitch          = vse_log_data_tag.append_child("veh_pitch");
   veh_pitch.text()                  = 0.0f;
   pugi::xml_node veh_steering_angle = vse_log_data_tag.append_child("veh_steering_angle");
   veh_steering_angle.text()         = truncate_float(ceilf(veh_raw->steering_whl_angle * 100.0F) / 100.0F);
   pugi::xml_node lros_drive_reverse = vse_log_data_tag.append_child("lros_drive_reverse");
   lros_drive_reverse.text()         = pad_int(veh_raw_misc->gear_pos == 1 ? 1 : 0);
   pugi::xml_node gear_position      = vse_log_data_tag.append_child("gear_position");
   gear_position.text()              = pad_int(veh_raw_misc->gear_pos);
}

static void mounting_info(pugi::xml_node &record_header)
{
   const auto *status_stream              = Get_Status_Log_Data_Ptr();
   pugi::xml_node mounting_log_data       = record_header.append_child("MOUNTING_LOG_DATA");
   pugi::xml_node sensor_height           = mounting_log_data.append_child("sensor_height");
   sensor_height.text()                   = ceil(status_stream->sensor_height * 100.0) / 100.0;
   pugi::xml_node sensor_mount_ornt_yaw   = mounting_log_data.append_child("sensor_mount_ornt_yaw");
   sensor_mount_ornt_yaw.text()           = ceil(status_stream->sensor_mount_ornt_yaw * 100.0) / 100.0;
   pugi::xml_node sensor_mount_ornt_pitch = mounting_log_data.append_child("sensor_mount_ornt_pitch");
   sensor_mount_ornt_pitch.text()         = ceil(status_stream->sensor_mount_ornt_pitch * 100.0) / 100.0;
   pugi::xml_node sensor_mount_ornt_roll  = mounting_log_data.append_child("sensor_mount_ornt_roll");
   sensor_mount_ornt_roll.text()          = ceil(status_stream->sensor_mount_ornt_roll * 100.0) / 100.0;
   pugi::xml_node sensor_long_offset      = mounting_log_data.append_child("sensor_long_offset");
   sensor_long_offset.text()              = ceil(status_stream->sensor_long_offset * 100.0) / 100.0;
   pugi::xml_node sensor_lat_offset       = mounting_log_data.append_child("sensor_lat_offset");
   sensor_lat_offset.text()               = ceil(status_stream->sensor_lat_offset * 100.0) / 100.0;
   pugi::xml_node sensor_mount_pos_x      = mounting_log_data.append_child("sensor_mount_pos_x");
   sensor_mount_pos_x.text()              = ceil(status_stream->sensor_mount_pos_x * 100.0) / 100.0;
   pugi::xml_node sensor_mount_pos_y      = mounting_log_data.append_child("sensor_mount_pos_y");
   sensor_mount_pos_y.text()              = ceil(status_stream->sensor_mount_pos_y * 100.0) / 100.0;
   pugi::xml_node sensor_mount_pos_z      = mounting_log_data.append_child("sensor_mount_pos_z");
   sensor_mount_pos_z.text()              = ceil(status_stream->sensor_mount_pos_z * 100.0) / 100.0;
}

// TODO(chinmay): there is no MNR field in Detection_Stream_T
static void mnr_blockage_info(pugi::xml_node &record_header)
{
   // const auto *mnr_log_data = &Get_IPC_A2M_Buffer()->payload.mnr_blockage;
   // if (mnr_log_data)
   // {
   //    pugi::xml_node MNR_Blockage_data                          = record_header.append_child("MNR_BLOCKAGE_DATA");
   //    MNR_Blockage_data.append_attribute("\n\t\tV_host")        = truncate_float(mnr_log_data->V_host);
   //    MNR_Blockage_data.append_attribute("\n\t\tMaxRm_mnr_avg") = truncate_float(mnr_log_data->MaxRm_mnr_avg);
   //    MNR_Blockage_data.append_attribute("\n\t\tMaxPm_mnr_avg") = truncate_float(mnr_log_data->MaxPm_mnr_avg);
   //    MNR_Blockage_data.append_attribute("\n\t\tAvgRm_mnr_avg") = truncate_float(mnr_log_data->AvgRm_mnr_avg);
   //    MNR_Blockage_data.append_attribute("\n\t\tAvgPm_mnr_avg") = truncate_float(mnr_log_data->AvgPm_mnr_avg);
   //    MNR_Blockage_data.append_attribute("\n\t\tbeta_var")      = truncate_float(mnr_log_data->beta_var);
   //    MNR_Blockage_data.append_attribute("\n\t\tbeta_var_si")   = truncate_float(mnr_log_data->beta_var_si);
   //    MNR_Blockage_data.append_attribute("\n\t\tK_UNUSED2_2")   = mnr_log_data->K_UNUSED2_2;
   //    MNR_Blockage_data.append_attribute("\n\t\tForward_blk")   = mnr_log_data->Forward_blk;
   //    MNR_Blockage_data.append_attribute("\n\t\tBlocked")       = mnr_log_data->Blocked;
   //    MNR_Blockage_data.append_attribute("\n\t\tDegraded")      = mnr_log_data->Degraded;
   //    MNR_Blockage_data.append_attribute("\n\t\tbm_blocked")    = mnr_log_data->bm_blocked;
   //    MNR_Blockage_data.append_attribute("\n\t\tBmnr1")         = mnr_log_data->Bmnr1;
   //    MNR_Blockage_data.append_attribute("\n\t\tBmnr2")         = mnr_log_data->Bmnr2;
   //    MNR_Blockage_data.append_attribute("\n\t\tBmnr3")         = mnr_log_data->Bmnr3;
   //    MNR_Blockage_data.append_attribute("\n\t\tBmnr4")         = mnr_log_data->Bmnr4;
   //    MNR_Blockage_data.append_attribute("\n\t\tbm_Degraded")   = mnr_log_data->bm_Degraded;
   //    MNR_Blockage_data.append_attribute("\n\t\tBmodmnr1")      = mnr_log_data->Bmodmnr1;
   //    MNR_Blockage_data.append_attribute("\n\t\tBmodmnr2")      = mnr_log_data->Bmodmnr2;
   //    MNR_Blockage_data.append_attribute("\n\t\tBmodmnr3")      = mnr_log_data->Bmodmnr3;
   //    MNR_Blockage_data.append_attribute("\n\t\tBmodmnr4")      = mnr_log_data->Bmodmnr4;
   //    MNR_Blockage_data.append_attribute("\n\t\tK_UNUSED1_1")   = mnr_log_data->K_UNUSED1_1;
   // }
}

static void radar_capability_info(pugi::xml_node &record_header)
{
   // TODO(gen7v2)
   const auto *rc_log_data = &Get_IPC_D2M_Buffer()->payload.radar_capability_data;
   if (rc_log_data != nullptr)
   {
      pugi::xml_node Radar_Capability_Log_data = record_header.append_child("RADAR_CAPABILITY_LOG_DATA");

      // Radar_Capability_Stream_Tag
      Radar_Capability_Log_data.append_attribute("\n\t\t\thost_speed_m_s")     = rc_log_data->host_speed_m_s;
      Radar_Capability_Log_data.append_attribute("\n\t\t\thost_yawrate_rad_s") = rc_log_data->host_yawrate_rad_s;
      // Radar_Capability_Log_data.append_attribute("\n\t\t\tmis_align_angle_el_rad")    = rc_log_data->mis_align_angle_el_rad;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tnormalized_nf_dB")          = rc_log_data->normalized_nf_dB;
      Radar_Capability_Log_data.append_attribute("\n\t\t\trange_coverage_m")          = rc_log_data->range_coverage_m;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tdamping_adjustment_dB")     = rc_log_data->damping_adjustment_dB;
      Radar_Capability_Log_data.append_attribute("\n\t\t\ttimestamp_ms")              = rc_log_data->timestamp_ms;
      Radar_Capability_Log_data.append_attribute("\n\t\t\trc_index")                  = rc_log_data->rc_index;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tvehicle_index")             = rc_log_data->vehicle_index;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tlook_index")                = rc_log_data->look_index;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tavg_mmic_onchip_temp")      = rc_log_data->avg_mmic_onchip_temp;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tlook_type")                 = rc_log_data->look_type;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tsensitivity_level")         = rc_log_data->sensitivity_level;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tRFHealthPercentage")        = rc_log_data->RFHealthPercentage;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tRFMalFunctionFlag")         = rc_log_data->RFMalFunctionFlag;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tRFHealth_EnableStatusFlag") = rc_log_data->RFHealth_EnableStatusFlag;
      // Radar_Capability_Log_data.append_attribute("\n\t\t\tmis_align_angle_el_valid")  = rc_log_data->mis_align_angle_el_valid;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tinterference_data_discard") = rc_log_data->interference_data_discard;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tf_ignore_fsc_status")       = rc_log_data->f_ignore_fsc_status;
      Radar_Capability_Log_data.append_attribute("\n\t\t\trc_active")                 = rc_log_data->rc_active;

      // Emblib_Blockage_Output_Stream_Tag
      Radar_Capability_Log_data.append_attribute("\n\t\t\trange_check_blockage") = rc_log_data->blockage.range_check_blockage;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tblockage_status")      = rc_log_data->blockage.blockage_status;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tblockage_active")      = rc_log_data->blockage.blockage_active;

      // Emblib_Blockage_Output_Stream_Tag.Emblib_Blockage_Data_Stream_Tag
      Radar_Capability_Log_data.append_attribute("\n\t\t\tpercentage")  = rc_log_data->blockage.blockage.percentage;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tprobability") = rc_log_data->blockage.blockage.probability;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tvalue")       = rc_log_data->blockage.blockage.value;

      // Emblib_Range_Estimation_Output_Stream_Tag
      Radar_Capability_Log_data.append_attribute("\n\t\t\tre_active") = rc_log_data->re.re_active;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tre_status") = rc_log_data->re.re_status;

      // Emblib_Partial_Blockage_Detector_Output_Stream_Tag
      Radar_Capability_Log_data.append_attribute("\n\t\t\tstatus")     = rc_log_data->pbd.status;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tpbd_active") = rc_log_data->pbd.pbd_active;

      // Emblib_RC_Fault_Table_Output_Stream_Tag
      Radar_Capability_Log_data.append_attribute("\n\t\t\tBlockage_Algo_Error") = rc_log_data->fault_table.Blockage_Algo_Error;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tDamping_Algo_Error")  = rc_log_data->fault_table.Damping_Algo_Error;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tRange_Algo_Error")    = rc_log_data->fault_table.Range_Algo_Error;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tPBD_Monitor_Algo_Error") =
         rc_log_data->fault_table.PBD_Monitor_Algo_Error;

      // Emblib_RC_Version_Output_Stream_Tag
      Radar_Capability_Log_data.append_attribute("\n\t\t\trc_ver_major") = rc_log_data->version.rc_ver_major;
      Radar_Capability_Log_data.append_attribute("\n\t\t\trc_ver_minor") = rc_log_data->version.rc_ver_minor;
      Radar_Capability_Log_data.append_attribute("\n\t\t\trc_ver_patch") = rc_log_data->version.rc_ver_patch;

      // Emblib_RC_Fault_Injection_Output_Stream_Tag
      Radar_Capability_Log_data.append_attribute("\n\t\t\tf_active")         = rc_log_data->fault_injection.f_active;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tf_fault_injected") = rc_log_data->fault_injection.f_fault_injected;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tfault_type")       = rc_log_data->fault_injection.fault_type;
      Radar_Capability_Log_data.append_attribute("\n\t\t\trun_counter")      = rc_log_data->fault_injection.run_counter;

      // Emblib_Damping_Monitor_Output_Stream_Tag
      Radar_Capability_Log_data.append_attribute("\n\t\t\tdm_active")       = rc_log_data->dm.dm_active;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tdm_status")       = rc_log_data->dm.dm_status;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tdamping_dB_meas") = rc_log_data->dm.damping_dB_meas;

      // Emblib_Damping_Monitor_Output_Stream_Tag.Emblib_Damping_Data_Stream_Tag
      Radar_Capability_Log_data.append_attribute("\n\t\t\tcurrent_dB") = rc_log_data->dm.damping.current_dB;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tstd_dB")     = rc_log_data->dm.damping.std_dB;

      // Emblib_Free_Sight_Check_Output_Stream_Tag
      Radar_Capability_Log_data.append_attribute("\n\t\t\ttraveled_dist_m")  = rc_log_data->fsc.traveled_dist_m;
      Radar_Capability_Log_data.append_attribute("\n\t\t\ttraveled_time_ms") = rc_log_data->fsc.traveled_time_ms;
      Radar_Capability_Log_data.append_attribute("\n\t\t\trun_status")       = rc_log_data->fsc.run_status;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tfault_status")     = rc_log_data->fsc.fault_status;

      // Emblib_Scene_Estimation_Output_Stream_Tag
      Radar_Capability_Log_data.append_attribute("\n\t\t\tf_few_dets") = rc_log_data->se.f_few_dets;
      // Radar_Capability_Log_data.append_attribute("\n\t\t\tfilt_mean_mnr_all")       = rc_log_data->se.filt_mean_mnr_all;
      // Radar_Capability_Log_data.append_attribute("\n\t\t\tfilt_mean_mnr_close")     = rc_log_data->se.filt_mean_mnr_close;
      // Radar_Capability_Log_data.append_attribute("\n\t\t\filt_mean_mnr_very_close") = rc_log_data->se.filt_mean_mnr_very_close;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tmax_range_m")            = rc_log_data->se.max_range_m;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tfilt_min_chirp_scaling") = rc_log_data->se.filt_min_chirp_scaling;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tmax_mnr_all")            = rc_log_data->se.max_mnr_all;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tmax_range_m")            = rc_log_data->se.max_range_m;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tnum_st_dets")            = rc_log_data->se.num_st_dets;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tinvalid_input_cnt")      = rc_log_data->se.invalid_input_cnt;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tproblematic_data_reset_cnt") =
         rc_log_data->se.problematic_data_reset_cnt;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tse_status")           = rc_log_data->se.se_status;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tse_active")           = rc_log_data->se.se_active;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tf_low_MCS")           = rc_log_data->se.f_low_MCS;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tf_high_MCS")          = rc_log_data->se.f_high_MCS;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tf_med_low_MCS")       = rc_log_data->se.f_med_low_MCS;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tf_med_high_MCS")      = rc_log_data->se.f_med_high_MCS;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tf_many_dets")         = rc_log_data->se.f_many_dets;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tf_few_dets")          = rc_log_data->se.f_few_dets;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tf_low_MNR_all")       = rc_log_data->se.f_low_MNR_all;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tf_high_MNR_all")      = rc_log_data->se.f_high_MNR_all;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tf_very_low_MNR_all")  = rc_log_data->se.f_very_low_MNR_all;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tf_very_high_MNR_all") = rc_log_data->se.f_very_high_MNR_all;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tf_low_damping")       = rc_log_data->se.f_low_damping;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tf_high_damping")      = rc_log_data->se.f_high_damping;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tf_very_close_target_high_MN") =
         rc_log_data->se.f_very_close_target_high_MNR;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tf_very_close_target_strongest") =
         rc_log_data->se.f_very_close_target_strongest;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tf_very_close_target_issue") = rc_log_data->se.f_very_close_target_issue;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tf_close_target_high_MNR")   = rc_log_data->se.f_close_target_high_MNR;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tf_close_target_issue")      = rc_log_data->se.f_close_target_issue;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tf_many_dets_high_MCS")      = rc_log_data->se.f_many_dets_high_MCS;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tf_problematic_data")        = rc_log_data->se.f_problematic_data;

      // Emblib_RC_Diagnostics_Output_Stream_Tag.elapsed_time_input_fault
      Radar_Capability_Log_data.append_attribute("\n\t\t\telapsed_time_input_fault.cur_fault_cnt") =
         rc_log_data->diag.elapsed_time_input_fault.cur_fault_cnt;
      Radar_Capability_Log_data.append_attribute("\n\t\t\telapsed_time_input_fault.f_status_ok") =
         rc_log_data->diag.elapsed_time_input_fault.f_status_ok;
      Radar_Capability_Log_data.append_attribute("\n\t\t\telapsed_time_input_fault.total_fault_cnt") =
         rc_log_data->diag.elapsed_time_input_fault.total_fault_cnt;

      // Emblib_RC_Diagnostics_Output_Stream_Tag.det_look_index_input_fault
      Radar_Capability_Log_data.append_attribute("\n\t\t\tdet_look_index_input_fault.cur_fault_cnt") =
         rc_log_data->diag.det_look_index_input_fault.cur_fault_cnt;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tdet_look_index_input_fault.f_status_ok") =
         rc_log_data->diag.det_look_index_input_fault.f_status_ok;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tdet_look_index_input_fault.total_fault_cnt") =
         rc_log_data->diag.det_look_index_input_fault.total_fault_cnt;

      // Emblib_RC_Diagnostics_Output_Stream_Tag.rdd_look_index_input_fault
      Radar_Capability_Log_data.append_attribute("\n\t\t\trdd_look_index_input_fault.cur_fault_cnt") =
         rc_log_data->diag.rdd_look_index_input_fault.cur_fault_cnt;
      Radar_Capability_Log_data.append_attribute("\n\t\t\trdd_look_index_input_fault.f_status_ok") =
         rc_log_data->diag.rdd_look_index_input_fault.f_status_ok;
      Radar_Capability_Log_data.append_attribute("\n\t\t\trdd_look_index_input_fault.total_fault_cnt") =
         rc_log_data->diag.rdd_look_index_input_fault.total_fault_cnt;

      // Emblib_RC_Diagnostics_Output_Stream_Tag.veh_index_input_fault
      Radar_Capability_Log_data.append_attribute("\n\t\t\tveh_index_input_fault.cur_fault_cnt") =
         rc_log_data->diag.veh_index_input_fault.cur_fault_cnt;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tveh_index_input_fault.f_status_ok") =
         rc_log_data->diag.veh_index_input_fault.f_status_ok;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tveh_index_input_fault.total_fault_cnt") =
         rc_log_data->diag.veh_index_input_fault.total_fault_cnt;

      // Emblib_RC_Diagnostics_Output_Stream_Tag.id_look_index_input_fault
      Radar_Capability_Log_data.append_attribute("\n\t\t\tid_look_index_input_fault.cur_fault_cnt") =
         rc_log_data->diag.id_look_index_input_fault.cur_fault_cnt;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tid_look_index_input_fault.f_status_ok") =
         rc_log_data->diag.id_look_index_input_fault.f_status_ok;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tid_look_index_input_fault.total_fault_cnt") =
         rc_log_data->diag.id_look_index_input_fault.total_fault_cnt;

      // Emblib_RC_Diagnostics_Output_Stream_Tag.smc_data_input_fault
      Radar_Capability_Log_data.append_attribute("\n\t\t\tsmc_data_input_fault.cur_fault_cnt") =
         rc_log_data->diag.smc_data_input_fault.cur_fault_cnt;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tsmc_data_input_fault.f_status_ok") =
         rc_log_data->diag.smc_data_input_fault.f_status_ok;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tsmc_data_input_fault.total_fault_cnt") =
         rc_log_data->diag.smc_data_input_fault.total_fault_cnt;

      // Emblib_RC_Diagnostics_Output_Stream_Tag.usc_data_input_fault
      Radar_Capability_Log_data.append_attribute("\n\t\t\tusc_data_input_fault.cur_fault_cnt") =
         rc_log_data->diag.usc_data_input_fault.cur_fault_cnt;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tusc_data_input_fault.f_status_ok") =
         rc_log_data->diag.usc_data_input_fault.f_status_ok;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tusc_data_input_fault.total_fault_cnt") =
         rc_log_data->diag.usc_data_input_fault.total_fault_cnt;

      // Emblib_RC_Diagnostics_Output_Stream_Tag.mmic_temperature_input_fault
      Radar_Capability_Log_data.append_attribute("\n\t\t\tmmic_temperature_input_fault.cur_fault_cnt") =
         rc_log_data->diag.mmic_temperature_input_fault.cur_fault_cnt;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tmmic_temperature_input_fault.f_status_ok") =
         rc_log_data->diag.mmic_temperature_input_fault.f_status_ok;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tmmic_temperature_input_fault.total_fault_cnt") =
         rc_log_data->diag.mmic_temperature_input_fault.total_fault_cnt;

      // Emblib_RC_Diagnostics_Output_Stream_Tag.dyn_align_input_fault
      Radar_Capability_Log_data.append_attribute("\n\t\t\tdyn_align_input_fault.cur_fault_cnt") =
         rc_log_data->diag.dyn_align_input_fault.cur_fault_cnt;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tdyn_align_input_fault.f_status_ok") =
         rc_log_data->diag.dyn_align_input_fault.f_status_ok;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tdyn_align_input_fault.total_fault_cnt") =
         rc_log_data->diag.dyn_align_input_fault.total_fault_cnt;

      // Emblib_RC_Diagnostics_Output_Stream_Tag.rf_health_input_fault
      Radar_Capability_Log_data.append_attribute("\n\t\t\trf_health_input_fault.cur_fault_cnt") =
         rc_log_data->diag.rf_health_input_fault.cur_fault_cnt;
      Radar_Capability_Log_data.append_attribute("\n\t\t\trf_health_input_fault.f_status_ok") =
         rc_log_data->diag.rf_health_input_fault.f_status_ok;
      Radar_Capability_Log_data.append_attribute("\n\t\t\trf_health_input_fault.total_fault_cnt") =
         rc_log_data->diag.rf_health_input_fault.total_fault_cnt;

      // Emblib_RC_Diagnostics_Output_Stream_Tag.det_rdd_matching_index_input_fault
      Radar_Capability_Log_data.append_attribute("\n\t\t\tdet_rdd_matching_index_input_fault.cur_fault_cnt") =
         rc_log_data->diag.det_rdd_matching_index_input_fault.cur_fault_cnt;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tdet_rdd_matching_index_input_fault.f_status_ok") =
         rc_log_data->diag.det_rdd_matching_index_input_fault.f_status_ok;
      Radar_Capability_Log_data.append_attribute("\n\t\t\tdet_rdd_matching_index_input_fault.total_fault_cnt") =
         rc_log_data->diag.det_rdd_matching_index_input_fault.total_fault_cnt;
   }
}

static void static_alignment_log_info(pugi::xml_node &record_header)
{
   // TODO(gen7v2)
   const auto *sa_log_data = &Get_IPC_D2M_Buffer()->payload.alignment_stream_data;
   if (sa_log_data != nullptr)
   {
      pugi::xml_node Static_Alignment_Log_data = record_header.append_child("STATIC_ALIGNMENT_LOG_DATA");

      // Emblib_ALIGNMENT_FLAT_PLATE_INTERNALS_T;
      // Static_Alignment_Log_data.append_attribute("\n\t\t\tmeas_plate_az")    = sa_log_data->static_align_internal.meas_plate_az;
      // Static_Alignment_Log_data.append_attribute("\n\t\t\tmeas_plate_el")    = sa_log_data->static_align_internal.meas_plate_el;
      // Static_Alignment_Log_data.append_attribute("\n\t\t\tmeas_plate_r_dot") =
      // sa_log_data->static_align_internal.meas_plate_r_dot;
      // Static_Alignment_Log_data.append_attribute("\n\t\t\tmeas_plate_range") =
      // sa_log_data->static_align_internal.meas_plate_range; Static_Alignment_Log_data.append_attribute("\n\t\t\tmeas_plate_rcs")
      // = sa_log_data->static_align_internal.meas_plate_rcs; Static_Alignment_Log_data.append_attribute("\n\t\t\tplate_az_angle")
      // = sa_log_data->static_align_internal.plate_az_angle;

      // Emblib_ALIGNMENT_FLAT_PLATE_OUTPUT_T;
      Static_Alignment_Log_data.append_attribute("\n\t\t\talignment_complete_percentage") =
         sa_log_data->sra_core_data.alignment_complete_percentage;
      // Static_Alignment_Log_data.append_attribute("\n\t\t\thoriz_misalign_ang") =
      //    sa_log_data->sra_core_data.horiz_misalign_ang;
      Static_Alignment_Log_data.append_attribute("\n\t\t\tazimuth_estimation_qf") =
         sa_log_data->sra_core_data.azimuth_estimation_qf;
      Static_Alignment_Log_data.append_attribute("\n\t\t\t\elevation_estimation_qf") =
         sa_log_data->sra_core_data.elevation_estimation_qf;
      // Static_Alignment_Log_data.append_attribute("\n\t\t\tstatus_horiz_misalign_ang") =
      //    sa_log_data->sra_core_data.status_horiz_misalign_ang;
      // Static_Alignment_Log_data.append_attribute("\n\t\t\tstatus_of_plate") = sa_log_data->sra_core_data.status_of_plate;
      // Static_Alignment_Log_data.append_attribute("\n\t\t\tstatus_vert_misalign_ang") =
      //    sa_log_data->sra_core_data.status_vert_misalign_ang;
      Static_Alignment_Log_data.append_attribute("\n\t\t\ttarget_std_dev_raw_amp") =
         sa_log_data->sra_core_data.target_std_dev_raw_amp;
      Static_Alignment_Log_data.append_attribute("\n\t\t\ttarget_std_dev_azimuth_raw") =
         sa_log_data->sra_core_data.target_std_dev_azimuth_raw;
      Static_Alignment_Log_data.append_attribute("\n\t\t\ttarget_std_dev_elevation_raw") =
         sa_log_data->sra_core_data.target_std_dev_elevation_raw;
      // Static_Alignment_Log_data.append_attribute("\n\t\t\tstd_r_dot")         = sa_log_data->sra_core_data.std_r_dot;
      Static_Alignment_Log_data.append_attribute("\n\t\t\ttarget_std_dev_range") = sa_log_data->sra_core_data.target_std_dev_range;
      // Static_Alignment_Log_data.append_attribute("\n\t\t\tvert_misalign_ang") = sa_log_data->sra_core_data.vert_misalign_ang;

      // Emblib_STATIC_ALIGNMENT_STREAM_LOGGING_T;
      Static_Alignment_Log_data.append_attribute("\n\t\t\tvacs_boresight_az_nominal") =
         sa_log_data->sra_core_data.vacs_boresight_az_nominal;
      Static_Alignment_Log_data.append_attribute("\n\t\t\tvacs_boresight_az_estimated") =
         sa_log_data->sra_core_data.vacs_boresight_az_estimated;
      Static_Alignment_Log_data.append_attribute("\n\t\t\tvacs_boresight_el_nominal") =
         sa_log_data->sra_core_data.vacs_boresight_el_nominal;
      Static_Alignment_Log_data.append_attribute("\n\t\t\tvacs_boresight_el_estimated") =
         sa_log_data->sra_core_data.vacs_boresight_el_estimated;
      // Static_Alignment_Log_data.append_attribute("\n\t\t\tstd_amplitude") = sa_log_data->sra_core_data.std_amplitude;
      // Static_Alignment_Log_data.append_attribute("\n\t\t\tstd_range")     = sa_log_data->sra_core_data.std_range;
      // Static_Alignment_Log_data.append_attribute("\n\t\t\tstd_r_dot")     = sa_log_data->sra_core_data.std_r_dot;
      // Static_Alignment_Log_data.append_attribute("\n\t\t\tradar_to_plate_distance") =
      // sa_log_data->sra_core_data.radar_to_plate_distance;
      // Static_Alignment_Log_data.append_attribute("\n\t\t\tplate_angle_scs") =
      //    sa_log_data->sra_core_data.plate_angle_scs;
      // Static_Alignment_Log_data.append_attribute("\n\t\t\tvehicle_speed") = sa_log_data->sra_core_data.vehicle_speed;
      // Static_Alignment_Log_data.append_attribute("\n\t\t\tvehicle_yawrate") =
      //    sa_log_data->sra_core_data.vehicle_yawrate;
      Static_Alignment_Log_data.append_attribute("\n\t\t\tvacs_boresight_az_nominal") =
         sa_log_data->sra_core_data.vacs_boresight_az_nominal;
      // Static_Alignment_Log_data.append_attribute("\n\t\t\tvacs_boresight_az_max") =
      //    sa_log_data->sra_core_data.vacs_boresight_az_max;
      Static_Alignment_Log_data.append_attribute("\n\t\t\tvacs_boresight_el_nominal") =
         sa_log_data->sra_core_data.vacs_boresight_el_nominal;
      // Static_Alignment_Log_data.append_attribute("\n\t\t\tvacs_boresight_el_max") =
      //    sa_log_data->sra_core_data.vacs_boresight_el_max;
      // Static_Alignment_Log_data.append_attribute("\n\t\t\tstatus_of_plate") =
      //    sa_log_data->sra_core_data.status_of_plate;
      // Static_Alignment_Log_data.append_attribute("\n\t\t\tvcs_polarity") = sa_log_data->sra_core_data.vcs_polarity;
      // Static_Alignment_Log_data.append_attribute("\n\t\t\tmount_loc")    = sa_log_data->sra_core_data.mount_loc;
      Static_Alignment_Log_data.append_attribute("\n\t\t\talignment_mode") = sa_log_data->sra_core_data.alignment_mode;
      Static_Alignment_Log_data.append_attribute("\n\t\t\tversion_major")  = sa_log_data->sra_core_data.version_major;
      Static_Alignment_Log_data.append_attribute("\n\t\t\tversion_minor")  = sa_log_data->sra_core_data.version_minor;
      Static_Alignment_Log_data.append_attribute("\n\t\t\tversion_patch")  = sa_log_data->sra_core_data.version_patch;
   }
}

static void dynamic_alignment_log_info(pugi::xml_node &record_header)
{
   // TODO(gen7v2)
   const auto *da_log_data = &Get_IPC_D2M_Buffer()->payload.dynamic_alignment_log_stream;
   if (da_log_data != nullptr)
   {
      pugi::xml_node Dynamic_Alignment_Log_data = record_header.append_child("DYNAMIC_ALIGNMENT_LOG_DATA");
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\talignment_index") = da_log_data->dra_core_data.alignment_index;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tlook_index")      = da_log_data->dra_core_data.look_index;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\terror_status_stage_age") =
         da_log_data->dra_core_data.error_status_stage_age;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tn_updates_azimuth_initial") =
         da_log_data->dra_core_data.n_updates_azimuth_initial;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tn_updates_elevation_initial") =
         da_log_data->dra_core_data.n_updates_elevation_initial;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tn_updates_azimuth")   = da_log_data->dra_core_data.n_updates_azimuth;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tn_updates_elevation") = da_log_data->dra_core_data.n_updates_elevation;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tn_updates_yawrate_bias_est") =
         da_log_data->dra_core_data.n_updates_yawrate_bias_est;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\traw_speed")         = da_log_data->dra_core_data.raw_speed;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\testimated_speed")   = da_log_data->dra_core_data.estimated_speed;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\traw_yawrate")       = da_log_data->dra_core_data.raw_yawrate;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\testimated_yawrate") = da_log_data->dra_core_data.estimated_yawrate;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\testimated_yaw_rate_bias") =
         da_log_data->dra_core_data.estimated_yaw_rate_bias;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tvcs_sensor_long_posn") =
         da_log_data->dra_core_data.vcs_sensor_long_posn;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tvcs_sensor_lat_posn") = da_log_data->dra_core_data.vcs_sensor_lat_posn;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tsensor_height_over_ground") =
         da_log_data->dra_core_data.sensor_height_over_ground;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tvwrapping") = da_log_data->dra_core_data.vwrapping;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tvacs_boresight_az_nominal") =
         da_log_data->dra_core_data.vacs_boresight_az_nominal;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tvacs_boresight_az_initial") =
         da_log_data->dra_core_data.vacs_boresight_az_initial;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tvacs_boresight_az_kf_internal") =
         da_log_data->dra_core_data.vacs_boresight_az_kf_internal;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tvacs_boresight_az_estimated") =
         da_log_data->dra_core_data.vacs_boresight_az_estimated;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tvacs_boresight_az_variance") =
         da_log_data->dra_core_data.vacs_boresight_az_variance;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tvacs_boresight_el_nominal") =
         da_log_data->dra_core_data.vacs_boresight_el_nominal;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tvacs_boresight_el_initial") =
         da_log_data->dra_core_data.vacs_boresight_el_initial;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tvacs_boresight_el_kf_internal") =
         da_log_data->dra_core_data.vacs_boresight_el_kf_internal;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tvacs_boresight_el_estimated") =
         da_log_data->dra_core_data.vacs_boresight_el_estimated;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tvacs_boresight_el_variance") =
         da_log_data->dra_core_data.vacs_boresight_el_variance;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tvacs_boresight_roll_nominal") =
         da_log_data->dra_core_data.vacs_boresight_roll_nominal;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tspeed_compensation_factor_initial") =
         da_log_data->dra_core_data.speed_compensation_factor_initial;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tspeed_compensation_factor_estimated") =
         da_log_data->dra_core_data.speed_compensation_factor_estimated;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\taz_scf_kf_covariance[4]") =
         da_log_data->dra_core_data.az_scf_kf_covariance[4];
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tavg_spd_since_start") = da_log_data->dra_core_data.avg_spd_since_start;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tavg_spd_running_az_scf") =
         da_log_data->dra_core_data.avg_spd_running_az_scf;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tavg_spd_running_el") = da_log_data->dra_core_data.avg_spd_running_el;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\ttotal_time_running_az_scf") =
         da_log_data->dra_core_data.total_time_running_az_scf;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\ttotal_time_running_el") =
         da_log_data->dra_core_data.total_time_running_el;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\ttotal_time_since_start") =
         da_log_data->dra_core_data.total_time_since_start;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\ttotal_distance_running_az_scf") =
         da_log_data->dra_core_data.total_distance_running_az_scf;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\ttotal_distance_running_el") =
         da_log_data->dra_core_data.total_distance_running_el;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\ttotal_distance_since_start") =
         da_log_data->dra_core_data.total_distance_since_start;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\talignment_complete_percent_az") =
         da_log_data->dra_core_data.alignment_complete_percent_az;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\talignment_complete_percent_el") =
         da_log_data->dra_core_data.alignment_complete_percent_el;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\testimated_standard_deviation_az") =
         da_log_data->dra_core_data.estimated_standard_deviation_az;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\testimated_standard_deviation_el") =
         da_log_data->dra_core_data.estimated_standard_deviation_el;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\testimated_pos_error_bound_az") =
         da_log_data->dra_core_data.estimated_pos_error_bound_az;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\testimated_neg_error_bound_az") =
         da_log_data->dra_core_data.estimated_neg_error_bound_az;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\testimated_pos_error_bound_el") =
         da_log_data->dra_core_data.estimated_pos_error_bound_el;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\testimated_neg_error_bound_el") =
         da_log_data->dra_core_data.estimated_neg_error_bound_el;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\talignment_mode")    = da_log_data->dra_core_data.alignment_mode;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tmounting_location") = da_log_data->dra_core_data.mounting_location;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tazimuth_estimation_qf") =
         da_log_data->dra_core_data.azimuth_estimation_qf;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\televation_estimation_qf") =
         da_log_data->dra_core_data.elevation_estimation_qf;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tscf_estimation_qf") = da_log_data->dra_core_data.scf_estimation_qf;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\terror_status_combined") =
         da_log_data->dra_core_data.error_status_combined;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\terror_status_initialization") =
         da_log_data->dra_core_data.error_status_initialization;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\terror_status_excessive_blockage") =
         da_log_data->dra_core_data.error_status_excessive_blockage;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\terror_status_interference") =
         da_log_data->dra_core_data.error_status_interference;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\terror_status_detection_input") =
         da_log_data->dra_core_data.error_status_detection_input;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\terror_status_vehicle_input") =
         da_log_data->dra_core_data.error_status_vehicle_input;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\terror_status_scf_out_of_bounds") =
         da_log_data->dra_core_data.error_status_scf_out_of_bounds;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\terror_status_az_est_out_of_bounds") =
         da_log_data->dra_core_data.error_status_az_est_out_of_bounds;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\terror_status_el_est_out_of_bounds") =
         da_log_data->dra_core_data.error_status_el_est_out_of_bounds;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tblockage_value")  = da_log_data->dra_core_data.blockage_value;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tblockage_status") = da_log_data->dra_core_data.blockage_status;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tdetection_coordinate_system") =
         da_log_data->dra_core_data.detection_coordinate_system;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tversion_major") = da_log_data->dra_core_data.version_major;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tversion_minor") = da_log_data->dra_core_data.version_minor;
      Dynamic_Alignment_Log_data.append_attribute("\n\t\t\tversion_patch") = da_log_data->dra_core_data.version_patch;
   }
}

static void interference_det_log_info(pugi::xml_node &record_header)
{
   // // TODO(gen7v2)
   // const auto *id_log_data = &Get_IPC_A2M_Buffer()->payload.interference_detection_data;
   // if (id_log_data != nullptr)
   // {
   //    pugi::xml_node Interference_Det_Log_data = record_header.append_child("INTERFERENCE_DET_LOG_DATA");

   //    Interference_Det_Log_data.append_attribute("\n\t\tnf_min_db_value")              = id_log_data->nf_min_db_value;
   //    Interference_Det_Log_data.append_attribute("\n\t\tnf_max_db_value")              = id_log_data->nf_max_db_value;
   //    Interference_Det_Log_data.append_attribute("\n\t\tnf_mean_db_value")             = id_log_data->nf_mean_db_value;
   //    Interference_Det_Log_data.append_attribute("\n\t\tnormalised_nf")                = id_log_data->normalised_nf;
   //    Interference_Det_Log_data.append_attribute("\n\t\tinterference_health")          = id_log_data->interference_health;
   //    Interference_Det_Log_data.append_attribute("\n\t\tinterference_level")           = id_log_data->interference_level;
   //    Interference_Det_Log_data.append_attribute("\n\t\tid_version_major")             = id_log_data->id_version_major;
   //    Interference_Det_Log_data.append_attribute("\n\t\tid_version_minor")             = id_log_data->id_version_minor;
   //    Interference_Det_Log_data.append_attribute("\n\t\tid_version_branch_identifier") =
   //    id_log_data->id_version_branch_identifier; Interference_Det_Log_data.append_attribute("\n\t\tinterference_detected") =
   //    id_log_data->interference_detected; Interference_Det_Log_data.append_attribute("\n\t\tinterference_data_discard")    =
   //    id_log_data->interference_data_discard; Interference_Det_Log_data.append_attribute("\n\t\tidm_excision_flag")            =
   //    id_log_data->idm_excision_flag; Interference_Det_Log_data.append_attribute("\n\t\trange_check_interference")     =
   //    id_log_data->range_check_interference;
   //    Interference_Det_Log_data.append_attribute("\n\t\tweighted_samples_removed_percentage") =
   //       id_log_data->weighted_samples_removed_percentage;
   // }
}

static void moving_object_info(pugi::xml_node &record_header)
{
#if 0
   #ifndef TRACKER_DISABLED
   const auto *rot_object_stream_ptr = &Get_IPC_A2M_Buffer()->payload.rot_sae_objects;
   if (rot_object_stream_ptr != nullptr)
   {
      static_assert(UINT8_MAX >= MAX_ROT_OBJECTS);
      std::array<uint8_t, MAX_ROT_OBJECTS> index{};
      std::iota(index.begin(), index.end(), 0);
      std::ranges::sort(index,
                        [&rot_object_stream_ptr](const auto &lesser, const auto &greater)
                        {
                           return rot_object_stream_ptr->sae_objects.object[lesser].vcs_xposn <
                                  rot_object_stream_ptr->sae_objects.object[greater].vcs_xposn;
                        });
      uint8_t moving_objects = 0;
      for (const auto &obj_iterator : rot_object_stream_ptr->sae_objects.object)
      {
         if (obj_iterator.f_moving == 1)
         {
            moving_objects++;
         }
      }
      pugi::xml_node f360_moving_objects_info = record_header.append_child("F360_MOVING_OBJECTS_INFO");
      f360_moving_objects_info.append_attribute("number_of_moving_objects") = moving_objects;
      // Below loop to iterate in all objects to print track data from valid data
      for (int obj_iterator = 0; obj_iterator < MAX_ROT_OBJECTS; obj_iterator++)
      {
         const uint8_t idx  = index[obj_iterator];
         const auto &object = rot_object_stream_ptr->sae_objects.object[idx];
         if (object.f_moving == 1)
         {
            pugi::xml_node f360_moving_objects                    = f360_moving_objects_info.append_child("F360_MOVING_OBJECTS");
            f360_moving_objects.append_attribute("vcs_long_posn") = truncate_float(object.vcs_xposn);
            f360_moving_objects.append_attribute("vcs_lat_posn")  = truncate_float(object.vcs_yposn);
            f360_moving_objects.append_attribute("vcs_long_vel")  = truncate_float(object.vcs_xvel);
            f360_moving_objects.append_attribute("vcs_lat_vel")   = truncate_float(object.vcs_yvel);
            f360_moving_objects.append_attribute("vcs_long_acc")  = truncate_float(object.vcs_xaccel);
            f360_moving_objects.append_attribute("vcs_lat_acc")   = truncate_float(object.vcs_yaccel);
            f360_moving_objects.append_attribute("heading")       = truncate_float(object.vcs_heading);
            f360_moving_objects.append_attribute("pointing")      = truncate_float(object.vcs_pointing);
            f360_moving_objects.append_attribute("speed")         = truncate_float(object.speed);
            f360_moving_objects.append_attribute("curvature")     = truncate_float(object.curvature);
            f360_moving_objects.append_attribute("length")        = truncate_float((object.len1 + object.len2));
            f360_moving_objects.append_attribute("width")         = truncate_float((object.wid1 + object.wid2));
            object_class(f360_moving_objects, object.object_class);
            ocg_status(f360_moving_objects, object.underdrivable_status);
         }
      }
   }
   #endif
#endif
}

static void moving_isoobject_info(pugi::xml_node &record_header)
{
#if 0
   #ifndef TRACKER_DISABLED
   const auto *rot_isoobject_stream_ptr = &Get_IPC_A2M_Buffer()->payload.rot_iso_objects;
   if (rot_isoobject_stream_ptr != nullptr)
   {
      static_assert(UINT8_MAX >= MAX_ROT_OBJECTS);
      std::array<uint8_t, MAX_ROT_OBJECTS> index{};
      std::iota(index.begin(), index.end(), 0);
      std::sort(index.begin(), index.end(),
                [&rot_isoobject_stream_ptr](const auto &lesser, const auto &greater)
                {
                   return rot_isoobject_stream_ptr->iso_objects.rot_object_list[lesser].vcs_x_posn <
                          rot_isoobject_stream_ptr->iso_objects.rot_object_list[greater].vcs_x_posn;
                });
      uint8_t moving_isoobjects = 0;
      for (const auto &obj_iterator : rot_isoobject_stream_ptr->iso_objects.rot_object_list)
      {
         if (obj_iterator.movement_status == 3)
         {
            moving_isoobjects++;
         }
      }
      pugi::xml_node f360_moving_iso_objects_info = record_header.append_child("F360_MOVING_ISO_OBJECTS_INFO");
      f360_moving_iso_objects_info.append_attribute("number_of_moving_objects") = moving_isoobjects;
      // Below loop to iterate in all objects to print track data from valid data
      for (int obj_iterator = 0; obj_iterator < MAX_ROT_OBJECTS; obj_iterator++)
      {
         const uint8_t idx  = index[obj_iterator];
         const auto &object = rot_isoobject_stream_ptr->iso_objects.rot_object_list[idx];
         if (object.movement_status == 3)
         {
            pugi::xml_node f360_moving_iso_objects = f360_moving_iso_objects_info.append_child("F360_MOVING_ISO_OBJECTS");
            f360_moving_iso_objects.append_attribute("iso_x_posn") = truncate_float(object.iso_x_posn);
            f360_moving_iso_objects.append_attribute("iso_y_posn") = truncate_float(object.iso_y_posn);
            f360_moving_iso_objects.append_attribute("iso_x_vel")  = truncate_float(object.iso_x_vel);
            f360_moving_iso_objects.append_attribute("iso_y_vel")  = truncate_float(object.iso_y_vel);
            f360_moving_iso_objects.append_attribute("iso_x_acc")  = truncate_float(object.iso_x_acc);
            f360_moving_iso_objects.append_attribute("iso_y_acc")  = truncate_float(object.iso_y_acc);
            f360_moving_iso_objects.append_attribute("length")     = truncate_float(object.length);
            f360_moving_iso_objects.append_attribute("width")      = truncate_float(object.width);
            object_class(f360_moving_iso_objects, object.object_class);
         }
      }
   }
   #endif
#endif
}

static void stationary_object_info(pugi::xml_node &record_header)
{
#if 0
   #ifndef TRACKER_DISABLED
   const auto *rot_object_stream_ptr = &Get_IPC_A2M_Buffer()->payload.rot_sae_objects;
   if (rot_object_stream_ptr != nullptr)
   {
      static_assert(UINT8_MAX >= MAX_ROT_OBJECTS);
      std::array<uint8_t, MAX_ROT_OBJECTS> index{};
      std::iota(index.begin(), index.end(), 0);
      std::sort(index.begin(), index.end(),
                [&rot_object_stream_ptr](const auto &lesser, const auto &greater)
                {
                   return rot_object_stream_ptr->sae_objects.object[lesser].vcs_xposn <
                          rot_object_stream_ptr->sae_objects.object[greater].vcs_xposn;
                });
      uint8_t stationary_objects = 0;
      for (const auto &obj_iterator : rot_object_stream_ptr->sae_objects.object)
      {
         if (obj_iterator.f_moving == 0)
         {
            stationary_objects++;
         }
      }
      pugi::xml_node f360_stationary_objects_info = record_header.append_child("F360_STATIONARY_OBJECTS_INFO");
      f360_stationary_objects_info.append_attribute("number_of_stationary_objects") = stationary_objects;
      // Below loop to iterate in all objects to print track data from valid data
      for (int obj_iterator = 0; obj_iterator < MAX_ROT_OBJECTS; obj_iterator++)
      {
         const uint8_t idx  = index[obj_iterator];
         const auto &object = rot_object_stream_ptr->sae_objects.object[idx];
         if (object.f_moving == 0)
         {
            pugi::xml_node f360_stationary_objects = f360_stationary_objects_info.append_child("F360_STATIONARY_OBJECTS");
            f360_stationary_objects.append_attribute("vcs_long_posn") = truncate_float(object.vcs_xposn);
            f360_stationary_objects.append_attribute("vcs_lat_posn")  = truncate_float(object.vcs_yposn);
            f360_stationary_objects.append_attribute("vcs_long_vel")  = truncate_float(object.vcs_xvel);
            f360_stationary_objects.append_attribute("vcs_lat_vel")   = truncate_float(object.vcs_yvel);
            f360_stationary_objects.append_attribute("vcs_long_acc")  = truncate_float(object.vcs_xaccel);
            f360_stationary_objects.append_attribute("vcs_lat_acc")   = truncate_float(object.vcs_yaccel);
            f360_stationary_objects.append_attribute("heading")       = truncate_float(object.vcs_heading);
            f360_stationary_objects.append_attribute("pointing")      = truncate_float(object.vcs_pointing);
            f360_stationary_objects.append_attribute("speed")         = truncate_float(object.speed);
            f360_stationary_objects.append_attribute("curvature")     = truncate_float(object.curvature);
            f360_stationary_objects.append_attribute("length")        = truncate_float((object.len1 + object.len2));
            f360_stationary_objects.append_attribute("width")         = truncate_float((object.wid1 + object.wid2));
            object_class(f360_stationary_objects, object.object_class);
            ocg_status(f360_stationary_objects, object.underdrivable_status);
         }
      }
   }
   #endif
#endif
}

static void stationary_isoobject_info(pugi::xml_node &record_header)
{
#if 0
   #ifndef TRACKER_DISABLED
   const auto *rot_isoobject_stream_ptr = &Get_IPC_A2M_Buffer()->payload.rot_iso_objects;
   if (rot_isoobject_stream_ptr != nullptr)
   {
      static_assert(UINT8_MAX >= MAX_ROT_OBJECTS);
      std::array<uint8_t, MAX_ROT_OBJECTS> index{};
      std::iota(index.begin(), index.end(), 0);
      std::sort(index.begin(), index.end(),
                [&rot_isoobject_stream_ptr](const auto &lesser, const auto &greater)
                {
                   return rot_isoobject_stream_ptr->iso_objects.rot_object_list[lesser].vcs_x_posn <
                          rot_isoobject_stream_ptr->iso_objects.rot_object_list[greater].vcs_x_posn;
                });
      uint8_t stationary_isoobjects = 0;
      for (const auto &obj_iterator : rot_isoobject_stream_ptr->iso_objects.rot_object_list)
      {
         if (obj_iterator.movement_status == 1)
         {
            stationary_isoobjects++;
         }
      }
      pugi::xml_node f360_stationary_iso_objects_info = record_header.append_child("F360_STATIONARY_ISO_OBJECTS_INFO");
      f360_stationary_iso_objects_info.append_attribute("number_of_stationary_objects") = stationary_isoobjects;
      // Below loop to iterate in all objects to print track data from valid data
      for (int obj_iterator = 0; obj_iterator < MAX_ROT_OBJECTS; obj_iterator++)
      {
         const uint8_t idx  = index[obj_iterator];
         const auto &object = rot_isoobject_stream_ptr->iso_objects.rot_object_list[idx];
         if (object.movement_status == 1)
         {
            pugi::xml_node f360_stationary_iso_objects =
               f360_stationary_iso_objects_info.append_child("F360_STATIONARY_ISO_OBJECTS");
            f360_stationary_iso_objects.append_attribute("iso_x_posn") = truncate_float(object.iso_x_posn);
            f360_stationary_iso_objects.append_attribute("iso_y_posn") = truncate_float(object.iso_y_posn);
            f360_stationary_iso_objects.append_attribute("iso_x_vel")  = truncate_float(object.iso_x_vel);
            f360_stationary_iso_objects.append_attribute("iso_y_vel")  = truncate_float(object.iso_y_vel);
            f360_stationary_iso_objects.append_attribute("iso_x_acc")  = truncate_float(object.iso_x_acc);
            f360_stationary_iso_objects.append_attribute("iso_y_acc")  = truncate_float(object.iso_y_acc);
            f360_stationary_iso_objects.append_attribute("length")     = truncate_float(object.length);
            f360_stationary_iso_objects.append_attribute("width")      = truncate_float(object.width);
            object_class(f360_stationary_iso_objects, object.object_class);
         }
      }
   }
   #endif
#endif
}

// TODO(chinmay): we don't have Get_Tracker_Log_Data_Ptr()
static void ocg_output_info(pugi::xml_node &record_header)
{
}

// TODO(chinmay): we don't have Get_Tracker_Log_Data_Ptr()
static void roadmodel_info(pugi::xml_node &record_header)
{
}

static void ocg_status(pugi::xml_node &f360_objects, uint8_t ocg_status)
{
   switch (ocg_status)
   {
      case 0:
         f360_objects.append_attribute("underdrivable_status") = "UNDERDRIVABLE_STATUS_CAN_NOT_PASS_UNDER";
         break;
      case 1:
         f360_objects.append_attribute("underdrivable_status") = "UNDERDRIVABLE_STATUS_IS_LIKELY_TO_PASS_UNDER";
         break;
      case 2:
         f360_objects.append_attribute("underdrivable_status") = "UNDERDRIVABLE_STATUS_CAN_PASS_UNDER";
         break;
      case 3:
         f360_objects.append_attribute("underdrivable_status") = "UNDERDRIVABLE_STATUS_NOT_TO_CONSIDER";
         break;
      default:
         assert(false);
   }
}

static void object_class(pugi::xml_node &f360_objects, uint8_t object_class)
{
   switch (object_class)
   {
      case 0:
         f360_objects.append_attribute("object_class") = "UNDETERMINED";
         break;
      case 1:
         f360_objects.append_attribute("object_class") = "CAR";
         break;
      case 2:
         f360_objects.append_attribute("object_class") = "MOTORCYCLE";
         break;
      case 3:
         f360_objects.append_attribute("object_class") = "TRUCK";
         break;
      case 4:
         f360_objects.append_attribute("object_class") = "PEDESTRIAN";
         break;
      case 5:
         f360_objects.append_attribute("object_class") = "POLE";
         break;
      case 6:
         f360_objects.append_attribute("object_class") = "TREE";
         break;
      case 7:
         f360_objects.append_attribute("object_class") = "ANIMAL";
         break;
      case 8:
         f360_objects.append_attribute("object_class") = "GOD";
         break;
      case 9:
         f360_objects.append_attribute("object_class") = "BICYCLE";
         break;
      case 10:
         f360_objects.append_attribute("object_class") = "UNIDENTIFIED_VEHICLE";
         break;
      default:
         assert(false);
   }
}

// NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers, cppcoreguidelines-narrowing-conversions,
// bugprone-narrowing-conversions, cppcoreguidelines-pro-type-vararg)
static const char *truncate_float(float32_t flt)
{
   const float32_t flt_abs = (flt >= 0) ? flt : (-flt);
   static std::array<char, 20> buf;
   buf.fill(0);
   auto flt_floor = static_cast<uint32_t>(floor(flt_abs));
   auto remainder = static_cast<uint32_t>(floor((flt_abs - flt_floor) * 1000)) % 1000;
   if (flt >= 0)
   {
      sprintf(buf.data(), "%d.%03d", flt_floor, remainder);
   }
   else
   {
      sprintf(buf.data(), "-%d.%03d", flt_floor, remainder);
   }
   return buf.cbegin();
}

static const char *pad_int(int integer)
{
   static std::array<char, 10> buf;
   buf.fill(0);
   sprintf(buf.data(), "%03d", integer);
   return buf.cbegin();
}
// NOLINTEND(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers, cppcoreguidelines-narrowing-conversions,
// bugprone-narrowing-conversions, cppcoreguidelines-pro-type-vararg)
