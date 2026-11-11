#ifndef IPC_MSS_H
#define IPC_MSS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

   /* Backing test globals (defined in SWC_PLT_CDD_XCP_xcp_logging_fake.cc) */
   extern uint32_t Ping_Buf_Addr;
   extern uint32_t Pong_Buf_Addr;
   extern uint32_t IPC_Dopp_RDD_Comp_Buf_Read_idx;

   uint32_t Get_D2M_Ping_Buf_Addr(void);
   uint32_t Get_D2M_Pong_Buf_Addr(void);
   uint32_t Get_IPC_Dopp_RDD_Comp_Buf_Read_Idx(void);

#ifdef __cplusplus
}
#endif

#endif /* IPC_MSS_H */
