#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <optional>
#include <string_view>
#include <type_traits>

#include "Dynamic_alignment_stream.h"
#include "Radar_SIL_Version.h"
// #include "adc_stream.h"
// #include "static_alignment_stream.h"
#include "can_sil_iface.h"
// #include "cdc_stream.h"
#include "debug_stream.h"
#include "detection_stream.h"
#include "down_selection_stream.h"
#include "emblib_ipc_data.h"
#include "enable_debugging.h"
#include "ff_sil_wrapper.h"
#include "header_stream.h"
#include "id_stream.h"
#include "mmic_stream.h"
#include "output_control.h"
#include "plp_iface.h"
#include "profile_timing.h"
// #include "radar_capability_stream.h"
#include "rdd_debug_stream.h"
#include "rdd_stream.h"
#include "statistical_report.h"
#ifdef TRACKER_ENABLED
   #include "emb_tracker_project_parameters.h"
   #include "emb_tracker_stream_interface.h"
#endif

#ifdef FEATURE_ENABLE
   #include "bsis_stream.h"
   #include "mois_stream.h"
   #include "olp_stream.h"
#endif
#include "ENET_UDP_Driver.h"
// #include "alignment_internals_data.h"
#include "rsp_sil_wrapper.h"
#include "sil_input_symbol.h"
#include "sil_macros_time.h"
#include "sil_output_symbol.h"
#include "sil_stream_wrapper.h"
#include "sil_symbol_wrapper.h"
#include "sil_version.h"
#include "sil_wrapper.h"
#include "sil_wrapper_common.h"
#include "sil_wrapper_customer.h"
// #include "someip_iface.h"
#include "status_stream.h"
#include "toi_stream.h"
#include "tracker_sil_wrapper.h"
#include "udp_sil_wrapper.h"
#include "usc_cal.h"
#include "vse_stream.h"
#include "vse_wrapper.h"

// TODO: Need to check
#define MAX_FILE_PATH_BIN_CREATION 208
#ifdef _WIN32
   #define MAX_PATH 260
#else
   #define MAX_PATH 4096
#endif

template <typename EnumType> constexpr std::underlying_type_t<EnumType> enum_cast(EnumType variant)
{
   return static_cast<std::underlying_type_t<EnumType>>(variant);
}

// NOLINTBEGIN(cppcoreguidelines-avoid-non-const-global-variables)
namespace sil_wrapper_globals
{
static Run_Mode_T run_mode = Run_Mode_T::DETECTION;
bool sil_init_success      = false;
} // namespace sil_wrapper_globals
// NOLINTEND(cppcoreguidelines-avoid-non-const-global-variables)

[[nodiscard]] static bool update_calibration_from_log(const SCalibInfo_T *calib_data);
static bool populate_ipc_data(const SIL_RADAR_Input_Data_T *Input_Data_ptr);
static void populate_radar_output_symbol();
static void populate_radar_output_data(SIL_RADAR_Output_Data_T *output_data_ptr, const uint16_t scan_index);
static void save_files();
static void write_profile_timing_durations();

SIL_Status_T SRR7_SiL_Init(const SIL_RADAR_Config_T *config)
{
   auto status = SIL_Status_T::E_SIL_INIT_ERR;

   if (fill_output_control(config->pEmb_Cfg_Filepath) == 0)
   {
      return SIL_Status_T::E_SIL_INIT_ERR;
   }
   Set_Radar_Position(static_cast<Radar_Position>(config->Radar_Position + 1));
   sil_wrapper_globals::run_mode = config->Run_Mode;

   if (Get_Radar_Position() == Radar_Position::INVALID_POSITION)
   {
      sil_wrapper_globals::sil_init_success = false;
      return SIL_Status_T::E_SIL_INIT_ERR;
   }

   std::cout << Get_Radar_Position_Str() << ": Embedded Library Version: " << EMB_LIB_MAJOR_VERSION << "." << EMB_LIB_MINOR_VERSION
             << "." << EMB_LIB_PATCH_VERSION << "\n";

   Initialize_Tx_Rx_Buffer_Size(UDP_LOGGING_BUFFER);
   RE_Logging_Init();
   sil_wrapper_globals::sil_init_success = true;
   if (config->pCalibInfo != nullptr)
   {
      if (update_calibration_from_log(config->pCalibInfo))
      {
         status = SIL_Status_T::E_SIL_RUN_OK;
      }
      else
      {
         status = SIL_Status_T::E_SIL_INIT_ERR;
      }
   }
   else
   {
      status = SIL_Status_T::E_SIL_RUN_OK;
   }
   customer_sil_init();
   return status;
}

SIL_Status_T SRR7_SiL_Execute(const SIL_RADAR_Input_Data_T *input, SIL_RADAR_Output_Data_T *output)
{
   auto status                       = SIL_Status_T::E_SIL_RUN_OK;
   bool run_emb_lib                  = false;
   static bool calib_write_done_flag = false;

   /* Start Timer */
   TIMER_START(EXECUTE);

   Set_Sil_Radar_Input_Data_Ptr(input);
   Set_Sil_Radar_Output_Data_Ptr(output);

   Increment_Exec_Counter();

   // enable_debugging(Function_Call_T::VALIDATE_FUSION_DATA);

   /* Get data from input log/symbol and fill the variables of IPC */
   run_emb_lib = populate_ipc_data(input);

   if (run_emb_lib)
   {
      if (calib_write_done_flag == false)
      {
         enable_debugging(Function_Call_T::USC_CSV_DECODE_DATA);
         enable_debugging(Function_Call_T::USC_XML_DECODE_DATA);
         enable_debugging(Function_Call_T::SMC_CSV_DECODE_DATA);
         enable_debugging(Function_Call_T::SMC_XML_DECODE_DATA);
         calib_write_done_flag = true;
      }

      enable_debugging(Function_Call_T::POPULATE_VALID_INPUT_DATA_TO_XML);
      enable_debugging(Function_Call_T::CSV_PRINT_UDP_DATA_IN);

      // Before tracker run: Open ViGEM file
      PLP_OpenVigemFile();

      if (get_output_control().Enable_Console_Prints == 1)
      {
         /* Run the corresponding modules based on the mode */
         std::cout << "\33[2K\r MODE: " << Run_Mode_Str(sil_wrapper_globals::run_mode)
                   << ", SCANINDEX: " << Get_Current_Scan_Index() << ", RADAR: " << Get_Radar_Position_Str();
      }

      for (int i = 0; i < VSE_RUN_COUNT; ++i)
      {
         RE_IPC_VSE_Handler_10ms();
      }

      switch (sil_wrapper_globals::run_mode)
      {
         case Run_Mode_T::DSPACE:
            /* An option to run PSP algorithms on virtual detections */
            if (get_output_control().PSP_MODULES == "PSP_MODULES_ENABLED")
            {
               rsp_run(Run_Mode_T::DSPACE);
            }
            tracker_run(get_xtrk_path().c_str());
            feature_run();
            break;
         case Run_Mode_T::RDD:
            rsp_run(Run_Mode_T::RDD);
            tracker_run(get_xtrk_path().c_str());
            feature_run();
            break;
         case Run_Mode_T::AF:
            rsp_run(Run_Mode_T::AF);
            tracker_run(get_xtrk_path().c_str());
            feature_run();
            break;
         case Run_Mode_T::DETECTION:
            /* In DETECTION mode, new detections are not created hence we have a choice
               whether to use PSP_MODULE outputs from log or by re-running the algorithms */
            if (get_output_control().PSP_MODULES == "PSP_MODULES_ENABLED")
            {
               rsp_run(Run_Mode_T::DETECTION);
            }
            tracker_run(get_xtrk_path().c_str());
            feature_run();
            break;
         case Run_Mode_T::VIRTUAL_TRACKS:
         case Run_Mode_T::BIN:
         case Run_Mode_T::DECODE:
            break;
      }

      transmit_udp_data();
// transmit_someip_data(Get_Sil_Radar_Input_Symbol_Ptr()->MF4_Information.network_timeStamp[Get_Radar_Position() - 1]);
#ifdef AL_TRACKER
      transmit_can_data(Get_Sil_Radar_Input_Symbol_Ptr()->MF4_Information.network_timeStamp[Get_Radar_Position() - 1]);
#endif
      populate_radar_output_symbol();

      /* Write output to file */
      enable_debugging(Function_Call_T::POPULATE_VALID_OUTPUT_DATA_TO_XML);
      enable_debugging(Function_Call_T::CSV_PRINT_UDP_DATA_OUT);
      enable_debugging(Function_Call_T::CDC_CSV_PRINT_UDP_DATA);
   }

   /* Below function needs to be called irrespective of errors in Embedded library as SIL engine is expecting data in
      SIL_RADAR_Output_Data_T */
   populate_radar_output_data(output, Get_Current_Scan_Index());

   /* Stop Timer */
   TIMER_STOP(EXECUTE);

   /* Write timing reports to statistical report */
   write_profile_timing_durations();

   /* Reset timer objects */
   TIMER_RESET();

   return status;
}

SIL_Status_T SRR7_SiL_SetFolderPath(const char *input_log_path)
{
   static std::array<char, MAX_PATH> output_path_storage;
   const auto path_view = std::string_view(input_log_path);
   std::ranges::copy(path_view, output_path_storage.begin());

   if (sil_wrapper_globals::sil_init_success)
   {
      set_output_path(std::filesystem::path(path_view));
      save_files();
      if (path_view.size() > MAX_FILE_PATH_BIN_CREATION)
      {
         std::cout << "[WARNING]:Maximum path limit crossed by " << path_view.size() - MAX_FILE_PATH_BIN_CREATION
                   << " characters to create XML files\n";
         return SIL_Status_T::E_SIL_RUN_ERR;
      }
   }
   return SIL_Status_T::E_SIL_RUN_OK;
}

SIL_Status_T SRR7_SiL_Exit(FILE *fptr, int sensor_id)
{
   auto status = SIL_Status_T::E_SIL_RUN_OK;
   save_files();
   return status;
}

SIL_Status_T SRR7_SiL_Reset()
{
   auto status = SIL_Status_T::E_SIL_RUN_OK;
   save_files();
   return status;
}

SIL_Status_T SRR7_SiL_GetVersion(RADAR_Version_Info_T **pp_version)
{
   // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
   static RADAR_Version_Info_T version{
      .Release_Revision = SIL_MAJOR_VERSION,
      .Promote_Revision = SIL_MINOR_VERSION,
      .Field_Revision   = SIL_PATCH_VERSION,
      .hw_Version       = 0,
      .strm_version     = {},
   };
   // NOLINTEND(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::DETECTION_STREAM)] = DETECTION_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::HEADER_STREAM)]    = HEADER_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::STATUS_STREAM)]    = STATUS_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::RDD_STREAM)]       = RDD_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::VSE_STREAM)]       = VSE_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::DEBUG_STREAM)]     = DEBUG_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::CDC_GEN8_STREAM)]  = CDC_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::MMIC_STREAM)]      = MMIC_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::ALIGNMENT_STREAM)] = SRA_STREAM_VERSION;
   // version.strm_version[enum_cast(SiL_Logging_Data_Source_T::ADC_STREAM)]               = ADC_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::RADAR_CAPABILITY_STREAM)]  = RADAR_CAPABILITY_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::DOWN_SELECTION_STREAM)]    = DOWN_SELECTION_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::ID_STREAM)]                = ID_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::TOI_STREAM)]               = TOI_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::TOI_DS_STREAM)]            = TOI_DS_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::DYNAMIC_ALIGNMENT_STREAM)] = DRA_STREAM_VERSION;
   //   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::ALIGNMENT_INTERNALS_STREAM)] = DRA_INTERNALS_STREAM_VERSION;
#ifndef TRACKER_DISABLED
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::PARTNER_SENSOR_STREAM)]  = PARTNER_SENSOR_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::SYNC_INFO_STREAM)]       = SYNC_INFO_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::VEHICLE_INFO_STREAM)]    = VEHICLE_INFO_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::TRACKER_INFO_STREAM)]    = TRACKER_INFO_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::TIMING_INFO_STREAM)]     = TIMING_INFO_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::HOST_CALIBS_STREAM)]     = HOST_CALIBS_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::HOST_PROPS_STREAM)]      = HOST_PROPS_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::STATIC_ENV_POLY_STREAM)] = STATIC_ENV_POLY_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::FUNCTIONAL_SAFETY_FAULTS_STREAM)] =
      FUNCTIONAL_SAFETY_FAULTS_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::OBJECT_LIST_STREAM)]         = OBJECT_LIST_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::PROCESSED_DETECTION_STREAM)] = PROCESSED_DETECTION_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::SENSOR_CALIB_STREAM)]        = SENSOR_CALIB_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::TRAILER_DETECTOR_STREAM)]    = TRAILER_DETECTOR_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::CV_TRAILER_STREAM)]          = CV_TRAILER_STREAM_VERSION;
   #ifndef FEATURE_DISABLE
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::BSIS_STREAM)] = BSIS_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::MOIS_STREAM)] = MOIS_STREAM_VERSION;
   version.strm_version[enum_cast(SiL_Logging_Data_Source_T::OLP_STREAM)]  = OLP_STREAM_VERSION;
   #endif
#endif

   *pp_version = &version;
   return SIL_Status_T::E_SIL_RUN_OK;
}

static bool update_calibration_from_log(const SCalibInfo_T *calib_data)
{
   // USC
   // auto usc_cal_data_size_check = static_cast<u32p0_T>(USC_Cal_Data.Header2_Info.section_size);
   auto usc_cal_data_size_check = sizeof(USC_Cal_T);
   bool usc_status              = false;
   std::optional<int> usc_index = 0;
   if (get_output_control().USC_Calibration_Source == "LOG")
   {
      if (calib_data->f_CalibValid[enum_cast(Cal_Source_T::USC_FLASH)] != 0)
      {
         usc_index = enum_cast(Cal_Source_T::USC_FLASH);
         std::cout << "\nUSC stream available in log\n";

         if (usc_cal_data_size_check == (calib_data->which_cal[usc_index.value()]))
         {
            std::cout << "*****USC size match, starting USC fetching from log*****\r\n";
            std::memcpy(&USC_Cal_Data, calib_data->psCalib[*usc_index], sizeof(USC_Cal_Data));
            usc_status = true;
         }

         else if (usc_cal_data_size_check > (calib_data->which_cal[usc_index.value()]))
         {
            uint64_t log_usc_size = (calib_data->which_cal[usc_index.value()]);
            std::cout << "*****USC size from log is less than USC in C file, starting USC fetching from log*****\r\n";
            std::memcpy(&USC_Cal_Data, calib_data->psCalib[*usc_index], log_usc_size);
            usc_status = true;
         }

         else
         {
            std::cout << "*****USC size mismatch*****\r\n";
            std::cout << "\n USC size from log: " << calib_data->which_cal[usc_index.value()];
            std::cout << "\n USC size from c file: " << usc_cal_data_size_check << "\n\n";
            usc_status = false;
         }
      }
      else
      {
         usc_index = std::nullopt;
         std::cout << "\nUSC stream not available in log, using default USC\n";
         usc_status = true;
      }
   }
   else
   {
      std::cout << "\nUsing default USC\n";
      usc_status = true;
   }

   // SMC
   auto smc_cal_data_size_check = static_cast<u32p0_T>(SMC_Cal_Data.Header2_Info.section_size);
   bool smc_status              = false;
   std::optional<int> smc_index = 0;
   if (get_output_control().SMC_Calibration_Source == "LOG")
   {
      if (calib_data->f_CalibValid[enum_cast(Cal_Source_T::SMC_FLASH)] != 0)
      {
         smc_index = enum_cast(Cal_Source_T::SMC_FLASH);
         std::cout << "\nSMC stream available in log\n";

         if (smc_cal_data_size_check == (calib_data->which_cal[smc_index.value()]))
         {
            std::cout << "*****SMC size match, starting SMC fetching from log*****\r\n";
            std::memcpy(&SMC_Cal_Data, calib_data->psCalib[*smc_index], sizeof(SMC_Cal_Data));
            smc_status = true;
         }
         else
         {
            std::cout << "*****SMC size mismatch*****\r\n";
            std::cout << "\n SMC size from log: " << calib_data->which_cal[smc_index.value()];
            std::cout << "\n SMC size from c file: " << smc_cal_data_size_check << "\n\n";
            smc_status = false;
         }
      }
      else
      {
         smc_index = std::nullopt;
         std::cout << "\nSMC stream not available in log, using default SMC\n";
         smc_status = true;
      }
   }
   else
   {
      std::cout << "\nUsing default SMC\n";
      smc_status = true;
   }

   // PSC
   /* auto psc_cal_data_size_check = static_cast<u32p0_T>(PSC_Cal_Data.Header2_Info.section_size);
   bool psc_status              = false;
   std::optional<int> psc_index = 0;
   if (get_output_control().PSC_Calibration_Source == "LOG")
   {
      if (calib_data->f_CalibValid[enum_cast(Cal_Source_T::PSC_FLASH)] != 0)
      {
         psc_index = enum_cast(Cal_Source_T::PSC_FLASH);
         std::cout << "\nPSC stream available in log\n";

         if (psc_cal_data_size_check == (calib_data->which_cal[psc_index.value()]))
         {
            std::cout << "*****PSC size match, starting PSC fetching from log*****\r\n";
            std::memcpy(&PSC_Cal_Data, calib_data->psCalib[*psc_index], sizeof(PSC_Cal_Data));
            psc_status = true;
         }
         else
         {
            std::cout << "*****PSC size mismatch*****\r\n";
            std::cout << "\n PSC size from log: " << calib_data->which_cal[psc_index.value()];
            std::cout << "\n PSC size from c file: " << psc_cal_data_size_check << "\n\n";
            psc_status = false;
         }
      }
      else
      {
         psc_index = std::nullopt;
         std::cout << "\nPSC stream not available in log, using default PSC\n";
         psc_status = true;
      }
   }
   else
   {
      std::cout << "\nUsing default PSC\n";
      psc_status = true;
   } */

   // // Tracker Internals
   // if (get_output_control().TRACKER_INTERNALS == "TRACKER_INTERNALS_ENABLED")
   // {
   //    auto tracker_internals_data_size           = sizeof(ROT_Internals_Stream_T);
   //    bool Tracker_internals_status = false;
   //    std::optional<int> tracker_internals_index = 0;
   //    if (calib_data->f_CalibValid[enum_cast(Cal_Source_T::TRACKER_INTERNALS)] != 0)
   //    {
   //       tracker_internals_index = enum_cast(Cal_Source_T::TRACKER_INTERNALS);
   //       std::cout << "\nTracker Internals stream available from log\n";

   //       if (tracker_internals_data_size ==
   //       (calib_data->which_cal[tracker_internals_index.value()]))
   //       {
   //          std::cout << "*****Tracker Internals size match, starting Tracker
   //          Internals fetching from log*****\r\n";
   //          std::memcpy(Get_ROT_Internals_Data_Ptr(),
   //          calib_data->psCalib[*tracker_internals_index],
   //                      sizeof(ROT_Internals_Stream_T));
   //          uint64_t ts1 =
   //          Get_ROT_Internals_Data_Ptr()->internal_cluster.f360header.data_timstamp_us;
   //          uint64_t ts2 =
   //          Get_ROT_Internals_Data_Ptr()->internal_objects.f360header.data_timstamp_us;
   //          uint64_t ts3 =
   //          Get_ROT_Internals_Data_Ptr()->internal_detection_history.f360header.data_timstamp_us;
   //          uint64_t ts4 =
   //          Get_ROT_Internals_Data_Ptr()->internal_cwd.f360header.data_timstamp_us;
   //          uint64_t ts5 =
   //          Get_ROT_Internals_Data_Ptr()->internal_reflection_buffer.f360header.data_timstamp_us;

   //          Tracker_internals_status = ts1 == ts2 && ts2 == ts3 && ts3 == ts4
   //          && ts4 == ts5; if (Tracker_internals_status)
   //          {
   //             std::cout << "*****Tracker Internals Timestamp match, using
   //             Tracker internals*****\r\n";
   //          }
   //          else
   //          {
   //             std::cout << "*****Tracker Internals Timestamp mismatch, not
   //             using Tracker internals*****\r\n";
   //             std::memset(Get_ROT_Internals_Data_Ptr(), 0,
   //             sizeof(ROT_Internals_Stream_T));
   //          }
   //       }
   //       else
   //       {
   //          std::cout << "*****Tracker Internals size mismatch*****\r\n";
   //          std::cout << "\n Tracker Internals size from log: "
   //                    <<
   //                    calib_data->which_cal[enum_cast(Cal_Source_T::TRACKER_INTERNALS)];
   //          std::cout << "\n Tracker Internals size from c file: " <<
   //          tracker_internals_data_size << "\n\n";
   //       }
   //    }
   //    else
   //    {
   //       tracker_internals_index = std::nullopt;
   //       std::cout << "\nTracker Internals stream not available from log\n";
   //    }
   // }
   // else
   // {
   //    std::cout << "*****Not using Tracker Internals*****\r\n";
   // }

   // Alignment Internals
#if 0
   if (get_output_control().ALIGNMENT_INTERNALS == "ALIGNMENT_INTERNALS_ENABLED")
   {
      auto alignment_internals_data_size = sizeof(DRA_Internals_Stream_T);
      if (calib_data->f_CalibValid[enum_cast(Cal_Source_T::ALIGNMENT_INTERNALS)] != 0)
      {
         std::cout << "\nAlignment Internals stream available from SiL engine\n";
         if (alignment_internals_data_size == (calib_data->which_cal[enum_cast(Cal_Source_T::ALIGNMENT_INTERNALS)]))
         {
            std::cout << "*****Starting Alignment Internals Fetching from log*****\r\n";
            std::memcpy(Get_DRA_Internals_Data_Ptr(), calib_data->psCalib[enum_cast(Cal_Source_T::ALIGNMENT_INTERNALS)],
                        sizeof(DRA_Internals_Stream_T));
         }
         else
         {
            std::cout << "*****Alignment Internals size mismatch*****\r\n";
            std::cout << "\n Alignment Internals size from log: "
                      << calib_data->which_cal[enum_cast(Cal_Source_T::ALIGNMENT_INTERNALS)];
            std::cout << "\n Alignment Internals size in SW: " << alignment_internals_data_size << "\n\n";
         }
      }
      else
      {
         std::cout << "\nAlignment Internals stream not available from SiL engine\n";
      }
   }
#endif
   return usc_status && smc_status;
}

static bool populate_ipc_data(const SIL_RADAR_Input_Data_T *Input_Data_ptr)
{
   /* Start timer */
   TIMER_START(POPULATE_IPC_DATA);

   bool status = false;

   /* Clearing the IPC Buffers. This should be filled with data from Logging streams or input symbol interface*/
   memset(Get_IPC_D2M_Buffer(), 0, sizeof(D2M_Msg_T));
   memset(Get_IPC_M2D_Buffer(), 0, sizeof(M2D_Msg_T));

   if (Input_Data_ptr == nullptr)
   {
      write_statistical_report(ReportKind::FAULT, "input_data_ptr is null");
      return false;
   }

   if (sil_wrapper_globals::run_mode != Run_Mode_T::DSPACE)
   {
      /* Fill stream data within IPC from logging streams */
      status = populate_ipc_with_stream_data(Input_Data_ptr->Radar_Stream);
      status = populate_ipc_with_symbol_data(Input_Data_ptr->Symbol_Record.raw_stream);
   }
   else
   {
      /* Fill stream data within IPC from symbol interface */
      status = populate_ipc_with_symbol_data(Input_Data_ptr->Symbol_Record.raw_stream);
   }

   /* Stop timer */
   TIMER_STOP(POPULATE_IPC_DATA);

   return status;
}

// NOLINTBEGIN(bugprone-easily-swappable-parameters)
static void populate_radar_output_symbol()
{
   SIL_RADAR_Output_Symbol_T *output_symbol_ptr = Get_Sil_Radar_Output_Symbol_Ptr();
   /* Start Timer */
   TIMER_START(POPULATE_RADAR_OUTPUT_SYMBOL);

   /* NOTE: below parameters will be used by Tracker running in DC
   so has to be in vcs format and not iso, please make sure when you populate
   any variables here convert to vcs */

   /*Fill vehicle info*/
   Veh_Raw_Data_T *VehicleInfo =
      &Get_IPC_M2D_Buffer()->payload.veh_data.veh_raw_data[Get_IPC_M2D_Buffer()->payload.veh_data.latest_raw_index];
   Stream_Hdr_T *VehicleInfoHeader                              = &Get_IPC_M2D_Buffer()->payload.veh_data.stream_hdr;
   output_symbol_ptr->Vehicle_Info_Out.abs_speed                = VehicleInfo->ego_vehicle_speed;
   output_symbol_ptr->Vehicle_Info_Out.yawrate                  = VehicleInfo->ego_yaw_rate;
   output_symbol_ptr->Vehicle_Info_Out.steering_angle           = VehicleInfo->steering_whl_angle;
   output_symbol_ptr->Vehicle_Info_Out.rear_axle_steering_angle = 0.0f; // no matching mapping found
   if (k_distance_front_bumper_to_rear_axle_smc > 0)
   {
      output_symbol_ptr->Vehicle_Info_Out.rear_axle_position = k_distance_front_bumper_to_rear_axle_smc;
   }
   else
   {
      output_symbol_ptr->Vehicle_Info_Out.rear_axle_position = 3.5f; // no matching mapping found
   }
   if (k_vehicle_length_smc > 0)
   {
      output_symbol_ptr->Vehicle_Info_Out.host_vehicle_length = k_vehicle_length_smc;
   }
   else
   {
      output_symbol_ptr->Vehicle_Info_Out.host_vehicle_length = 4.86f; // no matching mapping found
   }
   if (k_vehicle_width_smc > 0)
   {
      output_symbol_ptr->Vehicle_Info_Out.host_vehicle_width = k_vehicle_width_smc;
   }
   else
   {
      output_symbol_ptr->Vehicle_Info_Out.host_vehicle_width = 1.80f; // no matching mapping found
   }
   output_symbol_ptr->Vehicle_Info_Out.host_vehicle_height         = 1.0f; // no matching mapping found
   output_symbol_ptr->Vehicle_Info_Out.lane_width_external         = 0.0f; // no matching mapping found
   output_symbol_ptr->Vehicle_Info_Out.lane_center_offset_external = 0.0f; // no matching mapping found
   output_symbol_ptr->Vehicle_Info_Out.curve_radius                = 0.0f; // no matching mapping found
   output_symbol_ptr->Vehicle_Info_Out.vcs_long_acc                = 0.0f; // no matching mapping found
   output_symbol_ptr->Vehicle_Info_Out.vcs_lat_acc                 = 0.0f; // no matching mapping found
   output_symbol_ptr->Vehicle_Info_Out.bb_center_to_rear_x         = 1.8f; // no matching mapping found
   output_symbol_ptr->Vehicle_Info_Out.bb_center_to_rear_y         = 0.0f; // no matching mapping found
   output_symbol_ptr->Vehicle_Info_Out.bb_center_to_rear_z         = 0.5f; // no matching mapping found
   output_symbol_ptr->Vehicle_Info_Out.vehicle_data_buff_timestamp = VehicleInfoHeader->module_time_ms;
   if (VehicleInfo->ego_vehicle_speed < 0.0f)
   {
      output_symbol_ptr->Vehicle_Info_Out.prndl          = 1;
      output_symbol_ptr->Vehicle_Info_Out.f_reverse_gear = 1;
   }
   else
   {
      output_symbol_ptr->Vehicle_Info_Out.prndl          = 3;
      output_symbol_ptr->Vehicle_Info_Out.f_reverse_gear = 0;
   }
   output_symbol_ptr->Vehicle_Info_Out.turn_signal       = 0;
   output_symbol_ptr->Vehicle_Info_Out.f_trailer_present = 0;
   output_symbol_ptr->Vehicle_Info_Out.f_traffic_side    = 0;

   /*Fill mounting position*/
   auto radar_position = Get_Radar_Position();

   Status_Stream_T *status_stream_ptr = Get_Status_Log_Data_Ptr();

   if (status_stream_ptr->sensor_mount_ornt_roll > 0)
   {
      output_symbol_ptr->Mounting_Out.sensor_azimuth_polarity = -1;
   }
   else
   {
      output_symbol_ptr->Mounting_Out.sensor_azimuth_polarity = 1;
   }
   output_symbol_ptr->Mounting_Out.sensor_boresight_angle = status_stream_ptr->sensor_mount_ornt_yaw * RAD2DEG_SIL;
   output_symbol_ptr->Mounting_Out.sensor_vcs_lat_posn    = status_stream_ptr->sensor_mount_pos_y;
   output_symbol_ptr->Mounting_Out.sensor_vcs_long_posn   = status_stream_ptr->sensor_mount_pos_x;
   output_symbol_ptr->Mounting_Out.veh_width              = output_symbol_ptr->Vehicle_Info_Out.host_vehicle_width;
   output_symbol_ptr->Mounting_Out.veh_length             = output_symbol_ptr->Vehicle_Info_Out.host_vehicle_length;
   output_symbol_ptr->Mounting_Out.vcs_offset_lat         = status_stream_ptr->sensor_lat_offset;
   output_symbol_ptr->Mounting_Out.vcs_offset_long        = status_stream_ptr->sensor_long_offset;
   output_symbol_ptr->Mounting_Out.rear_axle_position     = status_stream_ptr->sensor_long_offset;

#if defined(FEATURE_ENABLE)
   /*alert to be filled*/
   Bsis_Core_Output_Stream_T *BsisLogData = &Get_IPC_D2M_Buffer()->payload.Bsis_IPC_Output.bsis_instance.core_output;

   if (radar_position == Radar_Position::REAR_LEFT)
   {
      output_symbol_ptr->BSIS_Out.bsis_alert_level[0] = BsisLogData->bsis_alert_level[0];

      output_symbol_ptr->BlindSpotDetectionState          = RL_BlindSpotDetectionState;
      output_symbol_ptr->BendOffPrbabltyofMstImportatObj  = RL_BendOffPrbablityofMstImportatObj;
      output_symbol_ptr->BlindSpotWarnigRelevantObjDetect = RL_BlindSpotWarnigRelevantObjDetect;
   }
#endif

   /*Fill detection info*/
   Detection_Stream_T *DetectionLogData                   = &Get_IPC_D2M_Buffer()->payload.det_data;
   Dynamic_Alignment_Log_Stream_T *Dynamic_Alignment_data = &Get_IPC_D2M_Buffer()->payload.dynamic_alignment_log_stream;
   Radar_Capability_Stream_T *Radar_Capability_data       = &Get_IPC_D2M_Buffer()->payload.radar_capability_data;
   output_symbol_ptr->Detection_Out.dets_info.ScanIndex   = DetectionLogData->det_list_property.scanindex;
   output_symbol_ptr->Detection_Out.dets_info.LookID      = DetectionLogData->det_list_property.lookindex;
   output_symbol_ptr->Detection_Out.dets_info.LookType    = DetectionLogData->det_list_property.look_type;
   output_symbol_ptr->Detection_Out.dets_info.timestamp =
      (((float)DetectionLogData->det_list_property.detection_timestamp_sec * SECONDS_2_MILLISECONDS) +
       ((float)DetectionLogData->det_list_property.detection_timestamp_ns / MILLISECONDS_2_NANOSECONDS));
   output_symbol_ptr->Detection_Out.dets_info.AutoAlignAzimuth = Dynamic_Alignment_data->dra_core_data.vacs_boresight_az_estimated;
   output_symbol_ptr->Detection_Out.dets_info.AutoAlignElevation =
      Dynamic_Alignment_data->dra_core_data.vacs_boresight_el_estimated;
   output_symbol_ptr->Detection_Out.dets_info.alignment_mode =
      0; // need to check with alignment module (Dynamic_Alignment_data->dra_core_data.alignment_mode);
   output_symbol_ptr->Detection_Out.dets_info.blockage_value =
      Radar_Capability_data->blockage.blockage.value; // need to check with blockage module
   output_symbol_ptr->Detection_Out.dets_info.blockage_status =
      Radar_Capability_data->blockage.blockage_status; // need to check with blockage module

   if (get_output_control().Output_Symbol_Source == 1)
   {
      output_symbol_ptr->Detection_Out.dets_info.Count = DetectionLogData->num_af_det;

      for (int i = 0; i < std::min(AF_MAX_NUM_DET, (uint32_t)NUMBER_OF_DETECTIONS_PER_RADAR); ++i)
      {
         output_symbol_ptr->Detection_Out.dets_input[i].amplitude            = DetectionLogData->af_dets[i].rcs;
         output_symbol_ptr->Detection_Out.dets_input[i].azimuth_confidence   = DetectionLogData->af_dets[i].az_conf;
         output_symbol_ptr->Detection_Out.dets_input[i].azimuth_raw          = DetectionLogData->af_dets[i].theta;
         output_symbol_ptr->Detection_Out.dets_input[i].elevation_raw        = DetectionLogData->af_dets[i].phi;
         output_symbol_ptr->Detection_Out.dets_input[i].range                = DetectionLogData->af_dets[i].ran;
         output_symbol_ptr->Detection_Out.dets_input[i].range_rate_raw       = DetectionLogData->af_dets[i].vel;
         output_symbol_ptr->Detection_Out.dets_input[i].detection_snr        = DetectionLogData->af_dets[i].snr;
         output_symbol_ptr->Detection_Out.dets_input[i].valid_level          = 1;
         output_symbol_ptr->Detection_Out.dets_input[i].elevation_confidence = DetectionLogData->af_dets[i].el_conf;
         output_symbol_ptr->Detection_Out.dets_input[i].super_res_target     = DetectionLogData->af_dets[i].spec_res;
         output_symbol_ptr->Detection_Out.dets_input[i].bistatic             = DetectionLogData->af_dets[i].f_bistatic;
      }
   }
   else
   {
      Down_selection_Stream_T *DownSelected_Data       = &Get_IPC_D2M_Buffer()->payload.downselection_data;
      output_symbol_ptr->Detection_Out.dets_info.Count = DownSelected_Data->num_af_ds_det;

      for (int i = 0; i < std::min(MAX_TARGET_REPORTS, (uint32_t)NUMBER_OF_DETECTIONS_PER_RADAR); ++i)
      {
         output_symbol_ptr->Detection_Out.dets_input[i].amplitude            = DownSelected_Data->af_ds_dets[i].rcs;
         output_symbol_ptr->Detection_Out.dets_input[i].azimuth_confidence   = DownSelected_Data->af_ds_dets[i].az_conf;
         output_symbol_ptr->Detection_Out.dets_input[i].azimuth_raw          = DownSelected_Data->af_ds_dets[i].theta;
         output_symbol_ptr->Detection_Out.dets_input[i].elevation_raw        = DownSelected_Data->af_ds_dets[i].phi;
         output_symbol_ptr->Detection_Out.dets_input[i].range                = DownSelected_Data->af_ds_dets[i].ran;
         output_symbol_ptr->Detection_Out.dets_input[i].range_rate_raw       = DownSelected_Data->af_ds_dets[i].vel;
         output_symbol_ptr->Detection_Out.dets_input[i].detection_snr        = DownSelected_Data->af_ds_dets[i].snr;
         output_symbol_ptr->Detection_Out.dets_input[i].valid_level          = 1;
         output_symbol_ptr->Detection_Out.dets_input[i].elevation_confidence = DownSelected_Data->af_ds_dets[i].el_conf;
         output_symbol_ptr->Detection_Out.dets_input[i].super_res_target     = DownSelected_Data->af_ds_dets[i].spec_res;
         output_symbol_ptr->Detection_Out.dets_input[i].bistatic             = DownSelected_Data->af_ds_dets[i].f_bistatic;
      }
   }

   /* Stop Timer */
   TIMER_STOP(POPULATE_RADAR_OUTPUT_SYMBOL);
}
// NOLINTEND(bugprone-easily-swappable-parameters)

static void populate_radar_output_data(SIL_RADAR_Output_Data_T *output_data_ptr, const uint16_t scan_index)
{
   if (output_data_ptr != nullptr)
   {
      output_data_ptr->Symbol_Record.raw_stream[SYM_INPUT_DATA].header.streamRefIndex = scan_index;
      output_data_ptr->Symbol_Record.raw_stream[SYM_INPUT_DATA].header.sourceTxTime   = 0;
      output_data_ptr->Symbol_Record.raw_stream[SYM_INPUT_DATA].header.Radar_Position = Get_Radar_Position();
      output_data_ptr->Symbol_Record.raw_stream[SYM_INPUT_DATA].header.streamNumber   = SYM_INPUT_DATA;
      output_data_ptr->Symbol_Record.raw_stream[SYM_INPUT_DATA].header.streamVersion  = SIL_DEBUG_INPUT_TYPE_STRUCTURE_VERSION;
      output_data_ptr->Symbol_Record.raw_stream[SYM_INPUT_DATA].header.customerId     = SIL_Customer_T::enCUST_PLATFORM_GEN8;
      output_data_ptr->Symbol_Record.raw_stream[SYM_INPUT_DATA].header.streamDataLen  = sizeof(SIL_RADAR_Output_Symbol_T);
      output_data_ptr->Symbol_Record.raw_stream[SYM_INPUT_DATA].payload               = Get_Sil_Radar_Output_Symbol_Ptr();

      output_data_ptr->Output_Data_Header.sym_Size    = static_cast<uint16_t>(sizeof(SIL_RADAR_Output_Data_T));
      output_data_ptr->Output_Data_Header.sym_version = OUTPUT_DATA_STRUCTURE_VERSION;
      output_data_ptr->f_dvsu_buff_valid              = true;
   }
}

static void save_files()
{
   enable_debugging(Function_Call_T::CLOSE_XML_FILES);
   enable_debugging(Function_Call_T::CLOSE_CSV_FILES);
   enable_debugging(Function_Call_T::CLOSE_XTRK_FILES);
   enable_debugging(Function_Call_T::CLOSE_HDF_FILES);
   enable_debugging(Function_Call_T::CLOSE_STATISTICAL_REPORT_FILES);
}

// /* Writes profile timing duration to statistical report */
static void write_profile_timing_durations()
{
   const auto &profile = Get_Profile();

   for (size_t idx = 0U; idx < Profile::kTimingModuleCount; ++idx)
   {
      TimingModule mod   = static_cast<TimingModule>(idx);
      const char *name   = profile.Get_TimingModule_Name(mod);
      long long duration = profile.Get_Timing_Duration(mod);

      if ((duration > 0) && (name[0] != '\0'))
      {
         write_statistical_report(ReportKind::TIMING, std::string(name) + " " + std::to_string(duration));
      }
   }
}
