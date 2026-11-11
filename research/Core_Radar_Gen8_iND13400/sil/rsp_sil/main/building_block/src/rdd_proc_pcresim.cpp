#include "appl_rdd_prv.h"
#include "ipc_data.h"
#include <xtensa/tie/xt_bben.h>
extern "C"
{
   RDD_Internal_Buff_T RDD_Internal_Buffer_Instance = {0};
   RDD_Internal_Buff_T *p_rdd_int_buff              = &RDD_Internal_Buffer_Instance;
   D2M_Msg_T d2m                                    = {0};
#include "appl_sp_ifc.c"
}

D2M_Msg_T *Get_DP_RDD_IPC_D2M_Msg_Buffer(void)
{
   return &d2m;
}
