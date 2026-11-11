#include "statistical_report.h"
#include "output_control.h"
#include "sil_wrapper_common.h"
#include <array>
#include <cstring>
#include <iostream>

std::ofstream outFile;
fs::path created_file_path;
std::vector<std::string> statistical_report_buffer;

std::string reportkind_to_string(ReportKind kind)
{
   switch (kind)
   {
      case ReportKind::TIMING:
         return "TIMING";
      case ReportKind::FAULT:
         return "FAULT";
      case ReportKind::NULLPTR:
         return "NULLPTR";
      default:
         std::cerr << "\nUnhandled report kind: " << static_cast<int>(kind) << '\n';
         exit(1);
   }
}

void create_statistical_report_file()
{
   fs::path txt_output_path = get_output_path().append("STATISTICAL_REPORT").append(Get_Radar_Position_Str());
   fs::create_directories(txt_output_path);
   fs::path::string_type file_name_prefix = get_input_log_filename()
                                               .substr(0, get_input_log_filename().find_last_of('.'))
                                               .append(1, '_')
                                               .append(Get_Radar_Position_Str().begin(), Get_Radar_Position_Str().end())
                                               .append(1, '_');

#ifdef WIN32
   const fs::path file_name = txt_output_path.append(file_name_prefix + L"STATISTICAL_REPORT.txt");
#else
   const fs::path file_name = txt_output_path.append(file_name_prefix + "STATISTICAL_REPORT.txt");
#endif
   created_file_path = txt_output_path / file_name;
   std::ofstream outFile(created_file_path);
   open_statistical_report_file();
}

void open_statistical_report_file()
{
   outFile.open(created_file_path, std::ios::app);
}

void write_statistical_report(ReportKind kind, const std::string &message)
{
   if (get_output_control().STATISTICAL_REPORT == 1)
   {
      if (!outFile.is_open())
      {
         create_statistical_report_file();
      }

      std::string kind_string = reportkind_to_string(kind);
      kind_string += std::string(KIND_STRING_LEN - kind_string.size(), ' ');
      std::string final_message = "SCAN_INDEX: " + std::to_string(Get_Current_Scan_Index()) + "; " + kind_string + ": " + message;
      statistical_report_buffer.push_back(final_message);
      if (statistical_report_buffer.size() >= 2046)
      {
         dump_buffer();
      }
   }
}

void close_statistical_report_file()
{
   /* Dump if remaining data */
   dump_buffer();

   if (outFile.is_open())
   {
      outFile.close();
   }
}

void dump_buffer()
{
   if (!outFile.is_open() || statistical_report_buffer.empty())
   {
      return;
   }

   for (uint16_t i = 0; i < statistical_report_buffer.size(); i++)
   {
      outFile << statistical_report_buffer[i] << "\n";
   }
   statistical_report_buffer.clear();
}
