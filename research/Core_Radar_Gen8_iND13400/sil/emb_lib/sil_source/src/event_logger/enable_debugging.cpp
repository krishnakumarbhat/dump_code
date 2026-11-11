#include "enable_debugging.h"
#include "calib_print.h"
// #include "can_sil_iface.h"
#include "csv_trace.h"
#include "output_control.h"
#include "sil_output_symbol.h"
#include "sil_wrapper_common.h"
#include "statistical_report.h"
#include "tracker_sil_wrapper.h"
#include "xml_trace.h"
#include <array>
#include <cstring>

void enable_debugging(Function_Call_T function_call)
{
   static bool usc_csv_decoded_data_flag = false;
   static bool usc_xml_decoded_data_flag = false;
   static bool smc_csv_decoded_data_flag = false;
   static bool smc_xml_decoded_data_flag = false;
   switch (function_call)
   {
      case Function_Call_T::POPULATE_VALID_INPUT_DATA_TO_XML:
         if (get_output_control().XML_Trace_Files == "XML_TRACE_ENABLED")
         {
            Populate_Valid_Data_to_XML(Xml_Format_T::SIL_XML_IN);
         }
         break;
      case Function_Call_T::POPULATE_VALID_OUTPUT_DATA_TO_XML:
         if (get_output_control().XML_Trace_Files == "XML_TRACE_ENABLED")
         {
            Populate_Valid_Data_to_XML(Xml_Format_T::SIL_XML_OUT);
         }
         break;
      case Function_Call_T::CLOSE_XML_FILES:
         if (get_output_control().XML_Trace_Files == "XML_TRACE_ENABLED")
         {
            save_XML_files();
         }
         break;
      case Function_Call_T::USC_XML_DECODE_DATA:
      {
         if (!usc_xml_decoded_data_flag)
         {
            if (get_output_control().Suppress_Usc_Xml_log == "ENABLE_USC_XML_MODE")
            {
               print_usc_xml(USC_Cal_Data);
            }
         }
         usc_xml_decoded_data_flag = true;
         break;
      }
      case Function_Call_T::USC_CSV_DECODE_DATA:
      {
         if (!usc_csv_decoded_data_flag)
         {
            if (get_output_control().Suppress_Usc_Csv_log == "ENABLE_USC_CSV_MODE")
            {
               print_usc_csv(USC_Cal_Data);
            }
         }
         usc_csv_decoded_data_flag = true;
         break;
      }
      case Function_Call_T::CSV_PRINT_UDP_DATA_IN:
         if (get_output_control().UDP_Log_Data_CSV != 0)
         {
            print_csv_input_data();
         }
         break;
      case Function_Call_T::CSV_PRINT_UDP_DATA_OUT:
         if (get_output_control().UDP_Log_Data_CSV != 0)
         {
            print_csv_output_data();
         }
         break;
      case Function_Call_T::CDC_CSV_PRINT_UDP_DATA:
         if (get_output_control().CDC_Log_Data_CSV != 0)
         {
            print_csv_cdc_output_data();
         }
         break;
      case Function_Call_T::CLOSE_CSV_FILES:
         if (get_output_control().UDP_Log_Data_CSV != 0)
         {
            close_csv_trace_files();
         }
         break;
      case Function_Call_T::SMC_XML_DECODE_DATA:
      {
         if (!smc_xml_decoded_data_flag)
         {
            if (get_output_control().Suppress_Smc_Xml_log == "ENABLE_SMC_XML_MODE")
            {
               print_smc_xml(SMC_Cal_Data);
            }
         }
         smc_xml_decoded_data_flag = true;
         break;
      }
      case Function_Call_T::SMC_CSV_DECODE_DATA:
      {
         if (!smc_csv_decoded_data_flag)
         {
            if (get_output_control().Suppress_Smc_Csv_log == "ENABLE_SMC_CSV_MODE")
            {
               print_smc_csv(SMC_Cal_Data);
            }
         }
         smc_csv_decoded_data_flag = true;
         break;
      }
      case Function_Call_T::CLOSE_XTRK_FILES:
      {
         if (get_output_control().XTRK_ENABLE == "XTRK_FILES_ENABLED")
         {
            close_xtrk_file();
         }
         break;
      }
      case Function_Call_T::CLOSE_HDF_FILES:
      {
         if (get_output_control().HDF_FILES == "HDF_FILES_ENABLED")
         {
            // close_hdf_file();
         }
         break;
      }
      case Function_Call_T::CLOSE_STATISTICAL_REPORT_FILES:
      {
         if (get_output_control().STATISTICAL_REPORT == 1)
         {
            close_statistical_report_file();
         }
         break;
      }
      case Function_Call_T::VALIDATE_FUSION_DATA:
      {
         if (Get_Current_Exec_Counter() != 1)
         {
            const RADAR_Detection_Out_T &radar_det_out = Get_Sil_Radar_Output_Symbol_Ptr()->Detection_Out;
            const RADAR_Detection_Out_T &received_radar_det_out =
               Get_Sil_Radar_Fusion_Data()[Get_Radar_Position() - 1].Detection_Out;
            if (received_radar_det_out.dets_info.Count == 0)
            {
               write_statistical_report(ReportKind::FAULT, "did not receive previous cycle detections from FW");
            }
            // NOLINTBEGIN(bugprone-suspicious-memory-comparison)
            // this comparison is fine because it was memcpy'd, we can rely on the representation being the same
            if (memcmp(&received_radar_det_out, &radar_det_out, sizeof(RADAR_Detection_Out_T)) != 0)
            // NOLINTEND(bugprone-suspicious-memory-comparison)
            {
               write_statistical_report(ReportKind::FAULT,
                                        "previous cycle detections received from fw not equal to saved previous cycle detections");
            }
            // we haven't run anything at this point, so the "previous" scan index should match the (unupdated)
            // value of Get_Current_Scan_Index
            if (received_radar_det_out.dets_info.ScanIndex != Get_Current_Scan_Index())
            {
               write_statistical_report(ReportKind::FAULT,
                                        "previous cycle scan index is not 1 less than current cycle scan index");
            }
         }
         break;
      }
   }
}
