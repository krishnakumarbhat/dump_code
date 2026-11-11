#include "SWC_PLT_CDD_HIL_fake.h"

DEFINE_FFF_GLOBALS;

/*===========================================================================*
 * FAKE FUNCTIONS for SWC_PLT_CDD_HIL dependencies
 *===========================================================================*/
DEFINE_FAKE_VALUE_FUNC(Header_Stream_T *, Get_Header_Stream_Ptr);
DEFINE_FAKE_VALUE_FUNC(Status_Stream_T *, Get_Status_Stream_Ptr);
DEFINE_FAKE_VALUE_FUNC(uint8_t *, Get_Req_En_Dis_CDC_Stream);
DEFINE_FAKE_VOID_FUNC(HIL_Injection_Request);
DEFINE_FAKE_VOID_FUNC(Update_HIL_Input_Interface);

/*===========================================================================*
 * FAKE VALUE FUNCTIONS for sensor position
 *===========================================================================*/
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_Radar_Position);

/*===========================================================================*
 * FAKE VALUE FUNCTIONS for IPC mocks
 *===========================================================================*/
DEFINE_FAKE_VALUE_FUNC(volatile M2D_Msg_T *, Get_MSS_IPC_M2D_Msg_Buffer);
DEFINE_FAKE_VALUE_FUNC(volatile M2D_One_Time_Msg_T *, Get_IPC_M2D_Onetime_Msg_Buffer);
