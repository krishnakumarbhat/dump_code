#ifndef IPC_MSS_H
#define IPC_MSS_H

#include "ipc_data.h"

#ifdef __cplusplus
extern "C"
{
#endif

   extern uint8_t IPC_Sp_Post_Proc_Buf_Read_idx;
   extern uint32_t IPC_Sp_Post_Proc_Buf_Read_Idx;
   extern uint32_t PSP_Ping_Buf_Addr;
   extern uint32_t PSP_Pong_Buf_Addr;
   extern D2M_Msg_T *IPC_Sp_Post_Proc_Buf_Read_Addr;

#ifdef __cplusplus
}
#endif

#endif /* IPC_MSS_H */
