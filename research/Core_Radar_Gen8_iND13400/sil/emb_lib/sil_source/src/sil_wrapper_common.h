#ifndef SIL_WRAPPER_COMMON
#define SIL_WRAPPER_COMMON
#include "Radar_SIL_Input_Data.h"
#include "Radar_SIL_Output_Data.h"
//#include "adc_stream.h"
#include "calib_stream.h"
#include "cdc_stream.h"
#include "cdc_stream_combined.h"
#include "debug_stream.h"
#include "header_stream.h"
#include "mmic_stream.h"
#include "radar_position.h"
#include "sil_input_symbol.h"
#include "sil_output_symbol.h"
#include "status_stream.h"
#include <array>
#include <cstdint>
#include <string_view>

#ifndef DEG2RAD_SIL
   #define DEG2RAD_SIL ((float)0.0174532925199433)
   #define RAD2DEG_SIL ((float)1 / DEG2RAD_SIL)
#endif

#define VSE_RUN_COUNT 5

Radar_Position Get_Radar_Position();
std::string_view Get_Radar_Position_Str();
void Set_Radar_Position(Radar_Position position);
uint8_t Get_Current_Exec_Counter();
void Increment_Exec_Counter();
uint16_t Get_Current_Scan_Index();
void Set_Current_Scan_Index(uint16_t scan_index);
uint16_t Get_Previous_Scan_Index();
void Set_Previous_Scan_Index(uint16_t scan_index);
uint16_t Previous_Scan_Index_Plus_One();
SIL_RADAR_Output_Data_T *Get_Sil_Radar_Output_Data_Ptr();
void Set_Sil_Radar_Output_Data_Ptr(SIL_RADAR_Output_Data_T *output);
const SIL_RADAR_Input_Data_T *Get_Sil_Radar_Input_Data_Ptr();
void Set_Sil_Radar_Input_Data_Ptr(const SIL_RADAR_Input_Data_T *input);

Status_Stream_T *Get_Status_Log_Data_Ptr();
Header_Stream_T *Get_Header_Log_Data_Ptr();
MMIC_Stream_T *Get_MMIC_Log_Data_Ptr();
CDC_Stream_Combined_T *Get_CDC_Combined_Log_Data_Ptr();
Debug_Stream_T *Get_Debug_Log_Data_Ptr();
SIL_RADAR_Input_Symbol_T *Get_Sil_Radar_Input_Symbol_Ptr();
SIL_RADAR_Output_Symbol_T *Get_Sil_Radar_Output_Symbol_Ptr();
const std::array<SIL_RADAR_Output_Symbol_T, MAX_SENSORS> &Get_Sil_Radar_Fusion_Data();

#endif // SIL_WRAPPER_COMMON
