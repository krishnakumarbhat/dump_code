#include "emblib_ipc_data.h"

// NOLINTBEGIN(cppcoreguidelines-avoid-non-const-global-variables)
static D2M_Msg_T ipc_d2m_buf;
// static A2M_Msg_T ipc_a2m_buf;
static M2D_Msg_T ipc_m2d_buf;
static M2D_One_Time_Msg_T ipc_m2d_one_time_buf;
// NOLINTEND(cppcoreguidelines-avoid-non-const-global-variables)

D2M_Msg_T *Get_IPC_D2M_Buffer()
{
   return &ipc_d2m_buf;
}

M2D_Msg_T *Get_IPC_M2D_Buffer()
{
   return &ipc_m2d_buf;
}

// A2M_Msg_T *Get_IPC_A2M_Buffer()
// {
//    return &ipc_a2m_buf;
// }

M2D_One_Time_Msg_T *Get_IPC_M2D_One_Time_Buffer()
{
   return &ipc_m2d_one_time_buf;
}

D2M_Msg_T *Get_SP_Post_Proc_IPC_D2M_Msg_Buffer()
{
   return &ipc_d2m_buf;
}

// TODO: Below function and object temporarily added here because toi algo is expecting it from ipc_dsp_lib
static volatile uint8_t DSP_RA_Error_Flag = CODED_FALSE;
uint8_t Get_DSP_RA_Error_Status(void)
{
   return DSP_RA_Error_Flag;
}
