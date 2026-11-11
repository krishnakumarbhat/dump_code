#include "sil_wrapper_common.h"
#include <array>
#include <cassert>
#include <cstring>

// NOLINTBEGIN(cppcoreguidelines-avoid-non-const-global-variables)
uint16_t sil_scan_index;
uint16_t sil_prev_scan_index = 0;
uint8_t sil_execute_counter  = 0;
SIL_RADAR_Output_Data_T *sil_radar_output_data_ptr;
const SIL_RADAR_Input_Data_T *sil_radar_input_data_ptr;
static SIL_RADAR_Input_Symbol_T sil_radar_input_symbol;
static SIL_RADAR_Output_Symbol_T sil_radar_output_symbol;
static Radar_Position radar_position;
static CDC_Stream_Combined_T CDC_Stream_Combined_Obj;
static Debug_Stream_T Debug_Stream_Obj;
static Header_Stream_T Header_Stream_Obj;
static Status_Stream_T Status_Stream_Obj;
static MMIC_Stream_T MMIC_Stream_Obj;

// static Calib_Stream_T Calib_Stream_Obj;

// NOLINTEND(cppcoreguidelines-avoid-non-const-global-variables)

uint16_t Get_Current_Scan_Index()
{
   return sil_scan_index;
}

void Set_Current_Scan_Index(uint16_t scan_index)
{
   sil_scan_index = scan_index;
}

uint16_t Get_Previous_Scan_Index()
{
   return sil_prev_scan_index;
}

void Set_Previous_Scan_Index(uint16_t scan_index)
{
   sil_prev_scan_index = scan_index;
}

uint16_t Previous_Scan_Index_Plus_One()
{
   if (sil_prev_scan_index == ~(uint16_t)0)
   {
      return 0;
   }
   else
   {
      /* Do not use Increment operator as we do not want to update the variable */
      return sil_prev_scan_index + 1;
   }
}

uint8_t Get_Current_Exec_Counter()
{
   return sil_execute_counter;
}

void Increment_Exec_Counter()
{
   sil_execute_counter++;
}

const SIL_RADAR_Input_Data_T *Get_Sil_Radar_Input_Data_Ptr()
{
   return sil_radar_input_data_ptr;
}

void Set_Sil_Radar_Input_Data_Ptr(const SIL_RADAR_Input_Data_T *input)
{
   sil_radar_input_data_ptr = input;
}

SIL_RADAR_Output_Data_T *Get_Sil_Radar_Output_Data_Ptr()
{
   return sil_radar_output_data_ptr;
}

void Set_Sil_Radar_Output_Data_Ptr(SIL_RADAR_Output_Data_T *output)
{
   sil_radar_output_data_ptr = output;
}

SIL_RADAR_Input_Symbol_T *Get_Sil_Radar_Input_Symbol_Ptr()
{
   return &sil_radar_input_symbol;
}

SIL_RADAR_Output_Symbol_T *Get_Sil_Radar_Output_Symbol_Ptr()
{
   return &sil_radar_output_symbol;
}

Radar_Position Get_Radar_Position()
{
   return radar_position;
}

void Set_Radar_Position(Radar_Position position)
{
   radar_position = position;
}

const std::array<SIL_RADAR_Output_Symbol_T, MAX_SENSORS> &Get_Sil_Radar_Fusion_Data()
{
   return *static_cast<std::array<SIL_RADAR_Output_Symbol_T, MAX_SENSORS> *>(
      Get_Sil_Radar_Input_Data_Ptr()->Symbol_Record.raw_stream[SYM_RADAR_OUT].payload);
}

std::string_view Get_Radar_Position_Str()
{
   switch (radar_position)
   {
      case Radar_Position::UNKNOWN_POSITION:
         return "UNKNOWN_POSITION";
      case Radar_Position::REAR_LEFT:
         return "REAR_LEFT";
      case Radar_Position::REAR_RIGHT:
         return "REAR_RIGHT";
      case Radar_Position::FRONT_RIGHT:
         return "FRONT_RIGHT";
      case Radar_Position::FRONT_LEFT:
         return "FRONT_LEFT";
      case Radar_Position::REAR_CENTER:
         return "REAR_CENTER";
      case Radar_Position::FRONT_CENTER:
         return "FRONT_CENTER";
      case Radar_Position::RIGHT_CENTER:
         return "RIGHT_CENTER";
      case Radar_Position::LEFT_CENTER:
         return "LEFT_CENTER";
      case Radar_Position::INVALID_POSITION:
         return "INVALID_POSITION";
   }
   assert(false);
}

Status_Stream_T *Get_Status_Log_Data_Ptr()
{
   return &Status_Stream_Obj;
}

Header_Stream_T *Get_Header_Log_Data_Ptr()
{
   return &Header_Stream_Obj;
}

MMIC_Stream_T *Get_MMIC_Log_Data_Ptr()
{
   return &MMIC_Stream_Obj;
}

CDC_Stream_Combined_T *Get_CDC_Combined_Log_Data_Ptr()
{
   return &CDC_Stream_Combined_Obj;
}

Debug_Stream_T *Get_Debug_Log_Data_Ptr()
{
   return &Debug_Stream_Obj;
}

#if 0
Calib_Stream_T *Get_Calib_Log_Data_Ptr()
{
   return &Calib_Stream_Obj;
}
#endif
