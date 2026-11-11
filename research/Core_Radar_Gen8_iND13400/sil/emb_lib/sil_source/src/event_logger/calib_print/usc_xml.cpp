#include "calib_print.h"
#include "output_control.h"
#include "serialize_object.h"
#include "sil_wrapper_common.h"
#include "usc_cal.h"
#include <filesystem>

namespace fs = std::filesystem;

void print_usc_xml(const USC_Cal_T &USC_Cal)
{
   fs::path output_path = get_output_path().append("XML").append(Get_Radar_Position_Str());
   fs::create_directories(output_path);
   fs::path::string_type xml_filename_prefix = get_input_log_filename().substr(0, get_input_log_filename().find_last_of('.'));
#ifdef WIN32
   const fs::path::string_type file_path = output_path.append(xml_filename_prefix + L"_USC.xml").wstring();
#else
   const fs::path::string_type file_path = output_path.append(xml_filename_prefix + "_USC.xml").string();
#endif

   pugi::xml_document xml{};
   pugi::xml_node ver               = xml.append_child(pugi::node_declaration);
   ver.append_attribute("version")  = "1.0";
   ver.append_attribute("encoding") = "UTF-8";
   xml_node top_level               = xml.append_child("USC_Cal");
   save_singleton_xml(top_level, USC_Cal);
   xml.save_file(file_path.c_str());
}
