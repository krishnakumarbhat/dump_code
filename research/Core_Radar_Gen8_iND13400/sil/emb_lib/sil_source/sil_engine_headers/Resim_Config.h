#ifndef RESIM_CONFIG_H
#define RESIM_CONFIG_H
#include "Radar_SIL_Input_Data.h"
#include "Radar_SIL_Output_Data.h"
#include <cassert>
#include <string_view>

#define MAX_SIL_RECORD 4
/* Switch for Binary Debug Control - Please ADD/ENABLE/DISABLE Binary Outputs Here */
#define BINARY_DEBUG_OUT             true // Parent Control For Bin Debug
#define WRITE_DETECTIONS             true
#define WRITE_FENCES                 true
#define WRITE_OH_OBJECT              true
#define WRITE_TRACKER_OUT            true
#define WRITE_RADAR_PARAM            true
#define WRITE_VEHICLE_DATA           true
#define WRITE_FEATURE                true
#define WRITE_CTA                    false
#define WRITE_LCDA                   false
#define WRITE_RECW                   false
#define WRITE_ABA                    false
#define WRITE_ASW                    false
#define WRITE_GROUPED_TRACKLETS      true
#define WRITE_OH_LOGGED              false
#define WRITE_DEBUG_OH_OBJECTS       false
#define WRITE_DEBUG_DETECTION_GROUPS false
/* Switch for TRACE Debug(.csv) Control - Please ADD/ENABLE/DISABLE Trace Debug Here */
#define TRACE_DEBUG true // Parent Control for TRACE Debug
#define CAL_LOG     true // calibration update by log

#pragma pack(push, 2)
/*******************************************************************************/
// This enum is to get the init status error conditions from the emb lib on init call.
enum class RADARSilInitStatusEnum_t
{
   e_INIT_UNKNOWN_ERR = -1, // unspecified error
   e_INIT_NO_ERR      = 0,  // emb init successful
   e_INIT_RADAR_POS_ERR,    // emb init received wrong radar/ecu position
   e_INIT_CAL_BUFFER_ERR,   // emb init received an empty/null calibration buffers
   e_INIT_GDSR_BUFFER_ERR,  // emb init received an empty GDSR buffer
   e_INIT_F360_BUFFER_ERR,  // emb init received an empty F360 buffer
   e_INIT_CHKSM_ERR         // emb init checksum error.
};
struct SCalibInfo_T
{
   static const int MAX_CALIB          = 150;
   static const int MAX_CALIB_BUF_SIZE = 50000;
   unsigned char *psCalib[MAX_CALIB];
   unsigned char f_CalibValid[MAX_CALIB];
   unsigned int which_cal[MAX_CALIB];
};
/* Enumeration to choose the Mode for Algorithm Execution */
enum class Run_Mode_T : int
{
   DETECTION      = 1,
   CDC            = 2,
   VIRTUAL_TRACKS = 3,
   DSPACE         = 4,
   AF,
   RDD,
   BIN,
   DECODE = 99
};

constexpr std::string_view Run_Mode_Str(Run_Mode_T run_mode)
{
   switch (run_mode)
   {
      case Run_Mode_T::DETECTION:
         return "DETECTION";
      case Run_Mode_T::CDC:
         return "CDC";
      case Run_Mode_T::VIRTUAL_TRACKS:
         return "VIRTUAL_TRACKS";
      case Run_Mode_T::DSPACE:
         return "DSPACE";
      case Run_Mode_T::AF:
         return "AF";
      case Run_Mode_T::RDD:
         return "RDD";
      case Run_Mode_T::BIN:
         return "BIN";
      case Run_Mode_T::DECODE:
         return "DECODE";
   }
   assert(false);
}

enum class Xml_Format_T
{
   SIL_XML_IN = 0,
   SIL_XML_OUT,
   SCAN_XML_OUT,
   OPP_DETS_XML_IN,
   OPP_DETS_XML_OUT,
   TEST_VECTOR_INPUT,
   TEST_VECTOR_OUTPUT,
};

enum class enSiLRadarMode
{
   SINGLE = 1,
   FULL   = 4
};
struct SIL_RADAR_Config_T
{
   Run_Mode_T Run_Mode{Run_Mode_T::DETECTION};
   unsigned char Radar_Position{};
   SCalibInfo_T *pCalibInfo{};
   char *pEmb_Cfg_Filepath{};
   char *pCustomerName{};
   RADARSilInitStatusEnum_t InitStatus{RADARSilInitStatusEnum_t::e_INIT_NO_ERR};
   SIL_RADAR_Config_T() = default;
};
struct Resim_Record_T
{
   SIL_RADAR_Input_Data_T input_frame;
   SIL_RADAR_Output_Data_T output_frame;
   unsigned char f_input_frame_valid;
   unsigned char f_output_frame_valid;
   unsigned char f_cdc_data_valid;
};
struct RR_ADAS_SIL_Record_T
{
   Resim_Record_T sil_rec[MAX_SIL_RECORD];
   unsigned int reference_idx[MAX_SIL_RECORD];
};
#pragma pack(pop)
#endif
