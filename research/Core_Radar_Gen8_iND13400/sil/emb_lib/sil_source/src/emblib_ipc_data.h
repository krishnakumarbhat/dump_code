#ifndef EMBLIB_IPC_DATA_H
#define EMBLIB_IPC_DATA_H

#include "ipc_data.h"

#ifdef __cplusplus
extern "C"
{      /* ! Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */
   M2D_Msg_T *Get_IPC_M2D_Buffer();
   D2M_Msg_T *Get_IPC_D2M_Buffer();
   //   A2M_Msg_T *Get_IPC_A2M_Buffer();
   M2D_One_Time_Msg_T *Get_IPC_M2D_One_Time_Buffer();
   D2M_Msg_T *Get_SP_Post_Proc_IPC_D2M_Msg_Buffer();
   uint8_t Get_DSP_RA_Error_Status(void); // TODO: Added temporarily
#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/** @} doxygen end group */
#endif /* EMBLIB_IPC_DATA_H */
