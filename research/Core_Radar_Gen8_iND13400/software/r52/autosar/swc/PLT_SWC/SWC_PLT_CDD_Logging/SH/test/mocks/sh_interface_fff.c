#include "sh_interface_fff.h"

DEFINE_FAKE_VALUE_FUNC(SH_Input_T *, Get_SH_Input_Data_Ptr);
DEFINE_FAKE_VALUE_FUNC(SH_Output_T *, Get_SH_Output_Data_Ptr);
DEFINE_FAKE_VALUE_FUNC(bool, Get_Status_Calibration_Disable_CDC_Logging);
DEFINE_FAKE_VALUE_FUNC(bool, Get_XCP_Over_ETH_Status);
DEFINE_FAKE_VOID_FUNC(DisableAllInterrupts);
DEFINE_FAKE_VOID_FUNC(EnableAllInterrupts);
DEFINE_FAKE_VOID_FUNC(Get_Platform_ustime, uint64_t *);
DEFINE_FAKE_VOID_FUNC(Get_Platform_Elapsed_ustime, uint32_t *, uint64_t);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Send_Stream_Internal, uint16_t, uint8_t *, uint16_t, uint16_t);
DEFINE_FAKE_VALUE_FUNC(uint8_t *, Get_Req_En_Dis_CDC_Stream);
DEFINE_FAKE_VALUE_FUNC(uint32_t, Get_Tracker_Ref_Index);
