#include "output_control.h"
#include "pugixml.hpp"
#include "sil_wrapper_common.h"
#include <cassert>
#include <cstdint>
#include <cstring>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

#define EMB_LIB_CONFIG_VERSION ("7.6")

namespace emblib_output_control
{
static Emb_Lib_Output_Control_T XML_Tag;
// NOLINTBEGIN(cppcoreguidelines-avoid-non-const-global-variables)
// needs to be global because it is set by set_output_path and acccessed by save_XML_file
fs::path output_path;
// needs to be global because it is set by set_output_path and acccessed by init
fs::path::string_type input_log_filename;
} // namespace emblib_output_control

uint8_t Fill_XML_Structure(const char *filepath);
Emb_Lib_Output_Control_T *Get_XML_Tag_pointer();

void set_output_path(const std::filesystem::path &input_log_path)
{
   emblib_output_control::output_path        = input_log_path.parent_path();
   emblib_output_control::input_log_filename = input_log_path.filename();
}

fs::path get_output_path()
{
   return emblib_output_control::output_path;
}

fs::path::string_type get_input_log_filename()
{
   return emblib_output_control::input_log_filename;
}

std::string get_xtrk_path()
{
   if (get_output_control().XTRK_ENABLE == "XTRK_FILES_ENABLED")
   {
      fs::path path = get_output_path().append("XTRK").append(Get_Radar_Position_Str());
      fs::create_directories(path);
      fs::path::string_type log_filename_prefix = get_input_log_filename().substr(0, get_input_log_filename().find_last_of('.'));
#ifdef WIN32
      const fs::path::string_type filename =
         log_filename_prefix + L"_" + std::wstring(Get_Radar_Position_Str().cbegin(), Get_Radar_Position_Str().cend());
      std::wstring path_wstring = path.append(filename).wstring();
      return {path_wstring.cbegin(), path_wstring.cend()};
#else
      return path.append(log_filename_prefix + "_" + std::string(Get_Radar_Position_Str())).string();
#endif
   }
   return "";
}

/*===========================================================================*\
 * Main function
\*===========================================================================*/
uint8_t fill_output_control(const char *filepath)
{
   if (std::strcmp(filepath, "NONE") != 0)
   {
      return Fill_XML_Structure(filepath);
   }

   /* Sensor config path is NONE when emb_lib is released to customers as Emb_Lib_config.xml will not be provided to the customers.
    */
   return 1;
}

const Emb_Lib_Output_Control_T &get_output_control()
{
   return emblib_output_control::XML_Tag;
}

uint8_t *Get_USC_Calibrations_Cal_DF_V_Read_from_XML()
{
   // TODO implement this
   uint8_t *temp;
   return ((uint8_t *)temp);
}

uint8_t Get_USC_Read_From_Xml_Enabled()
{
   uint8_t return_val = 0;
   if (emblib_output_control::XML_Tag.USC_XML_Control == "USC_READ_FROM_XML")
   {
      return_val = 1;
   }
   return (return_val);
}

uint8_t Fill_XML_Structure(const char *path)
{
   pugi::xml_document doc;
   pugi::xml_parse_result result = doc.load_file(path);
   pugi::xml_node output_control = doc.child("Embedded_Library_Output_Control");

   memset(&emblib_output_control::XML_Tag, 0, sizeof(Emb_Lib_Output_Control_T));

   emblib_output_control::XML_Tag.SIL_Embedded_Library_Output_Control_XML_Version =
      output_control.child_value("SIL_Embedded_Library_Output_Control_XML_Version");
   if (emblib_output_control::XML_Tag.SIL_Embedded_Library_Output_Control_XML_Version != EMB_LIB_CONFIG_VERSION)
   {
      std::cout << "\n[ERROR]: SIL Embedded Library config file version mismatch. Expected is " << EMB_LIB_CONFIG_VERSION << "\n";
      return 0;
   }
   emblib_output_control::XML_Tag.CUSTOMER_NAME          = output_control.child_value("CUSTOMER_NAME");
   emblib_output_control::XML_Tag.STATISTICAL_REPORT     = std::atoi(output_control.child_value("STATISTICAL_REPORT"));
   emblib_output_control::XML_Tag.CDC_SATURATION_CHECK   = std::atoi(output_control.child_value("CDC_SATURATION_CHECK"));
   emblib_output_control::XML_Tag.CAN_TRANSMISSION       = output_control.child_value("CAN_TRANSMISSION");
   emblib_output_control::XML_Tag.Veh_Data_CSV_Path      = output_control.child_value("Veh_Data_CSV_Path");
   emblib_output_control::XML_Tag.TRACKER_INTERNALS      = output_control.child_value("TRACKER_INTERNALS");
   emblib_output_control::XML_Tag.ALIGNMENT_INTERNALS    = output_control.child_value("ALIGNMENT_INTERNALS");
   emblib_output_control::XML_Tag.PSP_MODULES            = output_control.child_value("PSP_MODULES");
   emblib_output_control::XML_Tag.UDP_TRANSMISSION       = output_control.child_value("UDP_TRANSMISSION");
   emblib_output_control::XML_Tag.XML_Trace_Files        = output_control.child_value("XML_Trace_Files");
   emblib_output_control::XML_Tag.LOAD_TRACKER_INTERNALS = output_control.child_value("LOAD_TRACKER_INTERNALS");
   emblib_output_control::XML_Tag.LOAD_ANERMA_ERROR      = output_control.child_value("LOAD_ANERMA_ERROR");
   emblib_output_control::XML_Tag.USC_XML_Control        = output_control.child_value("USC_XML_Control");
   emblib_output_control::XML_Tag.Suppress_Usc_Csv_log   = output_control.child_value("Suppress_Usc_Csv_log");
   emblib_output_control::XML_Tag.Suppress_Usc_Xml_log   = output_control.child_value("Suppress_Usc_Xml_log");
   emblib_output_control::XML_Tag.SMC_XML_Control        = output_control.child_value("SMC_XML_Control");
   emblib_output_control::XML_Tag.Suppress_Smc_Xml_log   = output_control.child_value("Suppress_Smc_Xml_log");
   emblib_output_control::XML_Tag.Suppress_Smc_Csv_log   = output_control.child_value("Suppress_Smc_Csv_log");
   emblib_output_control::XML_Tag.USC_Calibration_Source = output_control.child_value("USC_Calibration_Source");
   emblib_output_control::XML_Tag.SMC_Calibration_Source = output_control.child_value("SMC_Calibration_Source");
   emblib_output_control::XML_Tag.PSC_Calibration_Source = output_control.child_value("PSC_Calibration_Source");
   emblib_output_control::XML_Tag.Enable_Console_Prints  = std::atoi(output_control.child_value("Enable_Console_Prints"));
   emblib_output_control::XML_Tag.Output_Symbol_Source   = std::atoi(output_control.child_value("Output_Symbol_Source"));

   // PLP SYNC
   pugi::xml_node plp_control                    = output_control.child("PLP_Resim");
   emblib_output_control::XML_Tag.plp_algorithms = std::atoi(plp_control.child_value("plp_algorithms"));
   emblib_output_control::XML_Tag.plp_analysis   = std::atoi(plp_control.child_value("plp_analysis"));

   // XML Prints
   // NOLINTBEGIN(cppcoreguidelines-narrowing-conversions, bugprone-narrowing-conversions)
   pugi::xml_node xml_prints                                              = output_control.child("XML_Prints");
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.Vehicle_Info     = std::atoi(xml_prints.child_value("Vehicle_Info"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.Mounting_Info    = std::atoi(xml_prints.child_value("Mounting_Info"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.MNR_blockage     = std::atoi(xml_prints.child_value("MNR_blockage"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.TD_blockage      = std::atoi(xml_prints.child_value("TD_blockage"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.Self_Dets        = std::atoi(xml_prints.child_value("Self_Dets"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.Opp_Dets         = std::atoi(xml_prints.child_value("Opp_Dets"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.scan_prints      = std::atoi(xml_prints.child_value("scan_prints"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.Cal_Error_Files  = std::atoi(xml_prints.child_value("Cal_Error_Files"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.Active_Faults    = std::atoi(xml_prints.child_value("Active_Faults"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.UDP_Datas        = std::atoi(xml_prints.child_value("UDP_Datas"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.Curvi_Tracks     = std::atoi(xml_prints.child_value("Curvi_Tracks"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.Alignment_Info   = std::atoi(xml_prints.child_value("Alignment_Info"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.Z4_Z7B_Cust_Data = std::atoi(xml_prints.child_value("Z4_Z7B_Cust_Data"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.ADC_Physical_Data =
      std::atoi(xml_prints.child_value("ADC_Physical_Data"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.Algo_Z7B_core = std::atoi(xml_prints.child_value("Algo_Z7B_core"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.Algo_Z7A_core = std::atoi(xml_prints.child_value("Algo_Z7A_core"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.Algo_Z4_core  = std::atoi(xml_prints.child_value("Algo_Z4_core"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.PATH_Tracking_Info =
      std::atoi(xml_prints.child_value("PATH_Tracking_Info"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.LCDA_Info       = std::atoi(xml_prints.child_value("LCDA_Info"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.CTA_Info        = std::atoi(xml_prints.child_value("CTA_Info"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.RECW_Info       = std::atoi(xml_prints.child_value("RECW_Info"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.ASW_Info        = std::atoi(xml_prints.child_value("ASW_Info"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.ABA_Info        = std::atoi(xml_prints.child_value("ABA_Info"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.CDC_Errors_Info = std::atoi(xml_prints.child_value("CDC_Errors_Info"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.IPC_Error_Infor = std::atoi(xml_prints.child_value("IPC_Error_Infor"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.PCAN_Error_Info = std::atoi(xml_prints.child_value("PCAN_Error_Info"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.ENET_Frame_Error_Info =
      std::atoi(xml_prints.child_value("ENET_Frame_Error_Info"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.HIL_BB_Erors_Info =
      std::atoi(xml_prints.child_value("HIL_BB_Erors_Info"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.OCG_info       = std::atoi(xml_prints.child_value("OCG_info"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.roadmodel_info = std::atoi(xml_prints.child_value("roadmodel_info"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.Static_Objects = std::atoi(xml_prints.child_value("Static_Objects"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.Moving_Objects = std::atoi(xml_prints.child_value("Moving_Objects"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.VSE_Data       = std::atoi(xml_prints.child_value("VSE_Data"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.Interference_Dets =
      std::atoi(xml_prints.child_value("Interference_Dets"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.Radar_Capability_Info =
      std::atoi(xml_prints.child_value("Radar_Capability_Info"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.Det_Data_Info = std::atoi(xml_prints.child_value("Det_Data_Info"));
   emblib_output_control::XML_Tag.Output_XML_Trace_Files.Det_Debug_Data_Info =
      std::atoi(xml_prints.child_value("Det_Debug_Data_Info"));
   emblib_output_control::XML_Tag.UDP_Log_Data_CSV       = std::atoi(output_control.child_value("UDP_Log_Data_CSV"));
   emblib_output_control::XML_Tag.CDC_Log_Data_CSV       = std::atoi(output_control.child_value("CDC_Log_Data_CSV"));
   emblib_output_control::XML_Tag.PCAN_DECODER_XML       = std::atoi(output_control.child_value("PCAN_DECODER_XML"));
   emblib_output_control::XML_Tag.UDP_Log_Data_XML_TRACE = std::atoi(output_control.child_value("UDP_Log_Data_XML_TRACE"));
   emblib_output_control::XML_Tag.BIN_FILES              = output_control.child_value("BIN_FILES");
   emblib_output_control::XML_Tag.XTRK_ENABLE            = output_control.child_value("XTRK_ENABLE");
   emblib_output_control::XML_Tag.HDF_FILES              = output_control.child_value("HDF_FILES");
   emblib_output_control::XML_Tag.CONSOLE_PRINTS         = output_control.child_value("CONSOLE_PRINTS");
   emblib_output_control::XML_Tag.Auto_Align_Option      = output_control.child_value("Auto_Align_Option");

   // Auto align
   // NOLINTBEGIN(cppcoreguidelines-narrowing-conversions, bugprone-narrowing-conversions)
   pugi::xml_node auto_align = output_control.child("Align_Angle_Quality_Values");
   emblib_output_control::XML_Tag.Auto_Align_Hard_Coded_Values.Front_Left_AA =
      std::atof(auto_align.child_value("Front_Left_Align_Angle"));
   emblib_output_control::XML_Tag.Auto_Align_Hard_Coded_Values.Front_Left_AQF =
      std::atoi(auto_align.child_value("Front_Left_Align_QF"));
   emblib_output_control::XML_Tag.Auto_Align_Hard_Coded_Values.Front_Right_AA =
      std::atof(auto_align.child_value("Front_Right_Align_Angle"));
   emblib_output_control::XML_Tag.Auto_Align_Hard_Coded_Values.Front_Right_AQF =
      std::atoi(auto_align.child_value("Front_Right_Align_QF"));
   emblib_output_control::XML_Tag.Auto_Align_Hard_Coded_Values.Left_Center_AA =
      std::atof(auto_align.child_value("Left_Center_Align_Angle"));
   emblib_output_control::XML_Tag.Auto_Align_Hard_Coded_Values.Left_Center_AQF =
      std::atoi(auto_align.child_value("Left_Center_Align_QF"));
   emblib_output_control::XML_Tag.Auto_Align_Hard_Coded_Values.Rear_Left_AA =
      std::atof(auto_align.child_value("Rear_Left_Align_Angle"));
   emblib_output_control::XML_Tag.Auto_Align_Hard_Coded_Values.Rear_Left_AQF =
      std::atoi(auto_align.child_value("Rear_Left_Align_QF"));
   emblib_output_control::XML_Tag.Auto_Align_Hard_Coded_Values.Rear_Right_AA =
      std::atof(auto_align.child_value("Rear_Right_Align_Angle"));
   emblib_output_control::XML_Tag.Auto_Align_Hard_Coded_Values.Rear_Left_AQF =
      std::atoi(auto_align.child_value("Rear_Right_Align_QF"));
   emblib_output_control::XML_Tag.Auto_Align_Hard_Coded_Values.Right_Center_AA =
      std::atof(auto_align.child_value("Right_Center_Align_Angle"));
   emblib_output_control::XML_Tag.Auto_Align_Hard_Coded_Values.Right_Center_AQF =
      std::atoi(auto_align.child_value("Right_Center_Align_QF"));

   emblib_output_control::XML_Tag.Speed_Compensation_Factor = output_control.child_value("Speed_Compensation_Factor");
   // Speed compensation factor
   pugi::xml_node speed_compensation = output_control.child("Speed_Compensation_Factor_Sensors_Values");
   emblib_output_control::XML_Tag.speed_compensation_fctr_values.Front_Left_Speed_Compensation_Factor =
      std::atof(speed_compensation.child_value("Front_Left_Speed_Compensation_Factor"));
   emblib_output_control::XML_Tag.speed_compensation_fctr_values.Front_Right_Speed_Compensation_Factor =
      std::atof(speed_compensation.child_value("Front_Right_Speed_Compensation_Factor"));
   emblib_output_control::XML_Tag.speed_compensation_fctr_values.Rear_Left_Speed_Compensation_Factor =
      std::atof(speed_compensation.child_value("Rear_Left_Speed_Compensation_Factor"));
   emblib_output_control::XML_Tag.speed_compensation_fctr_values.Rear_Right_Speed_Compensation_Factor =
      std::atof(speed_compensation.child_value("Rear_Right_Speed_Compensation_Factor"));
   // NOLINTEND(cppcoreguidelines-narrowing-conversions, bugprone-narrowing-conversions)
   return 1;
}
