extern "C"
{
#include "SWC_PLT_CDD_XCP.h"
#include "Xcp.h"
#include "ipc_mss.h"
}

extern "C"
{
   uint32 Ping_Buf_Addr                  = 0x50000000U;
   uint32 Pong_Buf_Addr                  = 0x50010000U;
   uint32 IPC_Dopp_RDD_Comp_Buf_Read_idx = 0U;

   uint32_t Get_D2M_Ping_Buf_Addr(void)
   {
      return Ping_Buf_Addr;
   }

   uint32_t Get_D2M_Pong_Buf_Addr(void)
   {
      return Pong_Buf_Addr;
   }

   uint32_t Get_IPC_Dopp_RDD_Comp_Buf_Read_Idx(void)
   {
      return IPC_Dopp_RDD_Comp_Buf_Read_idx;
   }

   static uint16 g_session_status = 0U;

   void Test_Set_Xcp_Session_Status(uint16 status)
   {
      g_session_status = status;
   }

   uint16 Xcp_GetSessionStatus(uint8 channel)
   {
      (void)channel;
      return g_session_status;
   }
}
