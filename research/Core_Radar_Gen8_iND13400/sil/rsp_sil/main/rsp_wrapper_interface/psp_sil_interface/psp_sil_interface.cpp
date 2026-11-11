/* ========================================================================== */
/*                            Header Files                                */
/* ========================================================================== */
#include <stdio.h>
#include <stdlib.h>

#include "dyn_align_wrapper.h"
#include "interference_detection_algo_interface.h"
#include "psp_sil_api.hpp"
#include "static_align_wrapper.h"
/* ========================================================================== */
/*                            Macro definitions                               */
/* ========================================================================== */
#define UINT_TEST 0

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

void PSP_Ipc_Sil_init_Bin(Vse_Stream_T *inp_vse_buff, Rdd_Stream_T *out_buff, Detection_Stream_T *out_af_det_buff,
                          Detection_Debug_Stream_T *det_dubug_buff, D2M_Msg_T *p_d2m_data, M2D_Msg_T *p_m2d_data)
{
   /* Fill detection stream data into D2M IPC payload */
   memcpy(&p_d2m_data->payload.det_data, out_af_det_buff, sizeof(Detection_Stream_T));

   /* Fill detection debug stream data into D2M IPC payload */
   memcpy(&p_d2m_data->payload.det_debug_data, det_dubug_buff, sizeof(Detection_Debug_Stream_T));

   /* Fill RDD stream data into D2M IPC payload */
   memcpy(&p_d2m_data->payload.rdd_stream_data, out_buff, sizeof(Rdd_Stream_T));

   /* Fill vehicle stream data into M2D IPC payload */
   memcpy(&p_m2d_data->payload.veh_data, inp_vse_buff, sizeof(Vse_Stream_T));
}

bool Psp_Sil_Wrapper(Vse_Stream_T *inp_vse_buff, Rdd_Stream_T *out_buff, Detection_Stream_T *out_af_det_buff,
                     Detection_Debug_Stream_T *det_dubug_buff, D2M_Msg_T *p_d2m_data, M2D_Msg_T *p_m2d_data,
                     M2D_One_Time_Msg_T *p_m2d_one_time_data)
{
   bool ret_val = false;

#ifdef ALIGN_STUB_SIMULATE_DET
   p_m2d_data->payload.alignment_Info.dynamic_alignment_data.f_data_valid = 1U;
   p_m2d_data->payload.alignment_Info.dynamic_alignment_data.align_cmd =
      2U; // change the value based on test requirement [enum]  0: off, 1: auto, 2: short_track, 3: service.
#endif

#ifndef PC_RESIM
   PSP_Ipc_Sil_init_Bin(inp_vse_buff, out_buff, out_af_det_buff, det_dubug_buff, p_d2m_data, p_m2d_data);
#endif
   /*Initialize ID SIL*/
   interference_detection_wrapper(p_m2d_data, p_d2m_data);

   /*Initialize RC SIL*/
   rc_wrapper(p_d2m_data, p_m2d_data, p_m2d_one_time_data);

   /*Initialize DA_SIL*/
   dyn_align_wrapper(p_d2m_data, p_m2d_data, p_m2d_one_time_data);

   /*Initialize SA_SIL*/
   static_align_wrapper(p_d2m_data, p_m2d_data, p_m2d_one_time_data);

   ret_val = true;

   return ret_val;
}
