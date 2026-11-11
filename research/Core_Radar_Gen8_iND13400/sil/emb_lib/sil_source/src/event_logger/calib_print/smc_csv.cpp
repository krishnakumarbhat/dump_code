#include "calib_print.h"
#include "output_control.h"
#include "serialize_object.h"
#include "sil_wrapper_common.h"
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

void print_smc_csv(const SMC_Cal_T &SMC_Cal)
{
   fs::path output_path = get_output_path().append("CSV").append(Get_Radar_Position_Str());
   fs::create_directories(output_path);
   fs::path::string_type csv_filename_prefix = get_input_log_filename().substr(0, get_input_log_filename().find_last_of('.'));
#ifdef WIN32
   const fs::path::string_type file_path = output_path.append(csv_filename_prefix + L"_SMC.csv").wstring();
#else
   const fs::path::string_type file_path = output_path.append(csv_filename_prefix + "_SMC.csv").string();
#endif
   std::ofstream stream{file_path.data(), std::ios::out};
   print_singleton_csv(stream, SMC_Cal);
}
