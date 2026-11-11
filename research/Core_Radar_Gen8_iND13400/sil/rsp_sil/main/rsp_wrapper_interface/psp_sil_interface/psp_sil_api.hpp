extern "C"
{
#include "dyn_align_wrapper.h"
#include "ipc_data.h"
#include "rc_wrapper.h"
#include "static_align_wrapper.h"
}
/* ========================================================================== */
/*                 Structure Definitions                                      */
/* ========================================================================== */

typedef struct Dynamic_Align_Param_Tag
{
   uint8_t elevation_estimation_qf;
   uint8_t error_status_el_est_out_of_bounds;
   float32_t vacs_boresight_el_nominal;
   float32_t vacs_boresight_el_estimated;
} Dynamic_Align_Param_T;

/* ========================================================================== */
/*                 Internal Function Declarations.                             */
/* ========================================================================== */

bool Psp_Sil_Wrapper(Vse_Stream_T *inp_vse_buff, Rdd_Stream_T *out_buff, Detection_Stream_T *out_af_det_buff,
                     Detection_Debug_Stream_T *det_dubug_buff, D2M_Msg_T *p_d2m_data, M2D_Msg_T *p_m2d_data,
                     M2D_One_Time_Msg_T *m2d_one_time_init_ptr);

void PSP_Ipc_Sil_init_Bin(Vse_Stream_T *inp_vse_buff, Rdd_Stream_T *out_buff, Detection_Stream_T *out_af_det_buff,
                          Detection_Debug_Stream_T *det_dubug_buff, D2M_Msg_T *p_d2m_data, M2D_Msg_T *p_m2d_data);
