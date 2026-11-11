#ifndef SH_INTERFACE_FFF_H
#define SH_INTERFACE_FFF_H

#include "SWC_PLT_CDD_Logging.h"
#include "fff.h"

DECLARE_FAKE_VALUE_FUNC(SH_Input_T *, Get_SH_Input_Data_Ptr);
DECLARE_FAKE_VALUE_FUNC(SH_Output_T *, Get_SH_Output_Data_Ptr);
DECLARE_FAKE_VALUE_FUNC(bool, Get_Status_Calibration_Disable_CDC_Logging);
DECLARE_FAKE_VALUE_FUNC(bool, Get_XCP_Over_ETH_Status);
DECLARE_FAKE_VOID_FUNC(DisableAllInterrupts);
DECLARE_FAKE_VOID_FUNC(EnableAllInterrupts);
DECLARE_FAKE_VOID_FUNC(Get_Platform_ustime, uint64_t *);
DECLARE_FAKE_VOID_FUNC(Get_Platform_Elapsed_ustime, uint32_t *, uint64_t);
DECLARE_FAKE_VALUE_FUNC(uint8_t, Send_Stream_Internal, uint16_t, uint8_t *, uint16_t, uint16_t);
DECLARE_FAKE_VALUE_FUNC(uint8_t *, Get_Req_En_Dis_CDC_Stream);
DECLARE_FAKE_VALUE_FUNC(uint32_t, Get_Tracker_Ref_Index);

#define FFF_FAKES_SH_INTERFACE_LIST(FAKE)                                                                                         \
   FAKE(Get_SH_Input_Data_Ptr)                                                                                                    \
   FAKE(Get_Status_Calibration_Disable_CDC_Logging)                                                                               \
   FAKE(Get_XCP_Over_ETH_Status)                                                                                                  \
   FAKE(DisableAllInterrupts)                                                                                                     \
   FAKE(EnableAllInterrupts)                                                                                                      \
   FAKE(Get_Platform_ustime)                                                                                                      \
   FAKE(Get_Platform_Elapsed_ustime)                                                                                              \
   FAKE(Send_Stream_Internal)                                                                                                     \
   FAKE(Get_Req_En_Dis_CDC_Stream)                                                                                                \
   FAKE(Get_Tracker_Ref_Index)
#endif
