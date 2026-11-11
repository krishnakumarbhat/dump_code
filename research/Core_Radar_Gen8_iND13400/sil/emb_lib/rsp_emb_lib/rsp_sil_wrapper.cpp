#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>

#if defined(SIL_MODE_RDD)
   #include "rdd_sil_api.hpp"
#endif

#if defined(SIL_MODE_RDD) or defined(SIL_MODE_AF)
   #include "af_sil_api.hpp"
#endif

#if defined(SIL_MODE_RDD) or defined(SIL_MODE_AF) or defined(SIL_MODE_DETECT)
   #include "dyn_align_wrapper.h"
   #include "interference_detection_algo_interface.h"
   #include "rc_wrapper.h"
   #include "static_align_wrapper.h"
#endif

#if (DOWNSELECTION_ENABLE == 1U)
   #define Get_TOI_DATA_STATUS_DST_PTR(x) ((x)->payload.toi_ds_stream_data.toi_ip_data.toi_ds_radar_data_status_payload)
   #define TOI_RADAR_DATA_PAYLOAD_T       TOI_Radar_Data_Status_Payload_DS_T
#else
   #define Get_TOI_DATA_STATUS_DST_PTR(x) ((x)->payload.toi_stream_data.toi_ip_data.toi_radar_data_status_payload)
   #define TOI_RADAR_DATA_PAYLOAD_T       TOI_Radar_Data_Status_Payload_T
#endif

#include "emblib_ipc_data.h"
#include "profile_timing.h"
#include "rsp_sil_wrapper.h"
#include "sil_wrapper_common.h"
extern "C"
{
#include "radar_data_quality.h"
}

void clear_module_output_buffers(Run_Mode_T mode)
{
   D2M_Payload_T *p_ipc_d2m_payload = &Get_IPC_D2M_Buffer()->payload;

   if (mode == Run_Mode_T::AF or mode == Run_Mode_T::RDD /*or mode == Run_Mode_T::CDC*/)
   {
      std::memset(&p_ipc_d2m_payload->det_data, 0, sizeof(Detection_Stream_T));
      std::memset(&p_ipc_d2m_payload->det_debug_data, 0, sizeof(Detection_Debug_Stream_T));
#if (DOWNSELECTION_ENABLE == 1U)
      std::memset(&p_ipc_d2m_payload->downselection_data, 0, sizeof(Down_selection_Stream_T));
#endif
   }

   if (mode == Run_Mode_T::DETECTION or mode == Run_Mode_T::AF or mode == Run_Mode_T::RDD /*or mode == Run_Mode_T::CDC*/)
   {
#if (DOWNSELECTION_ENABLE == 1U)
      std::memset(&p_ipc_d2m_payload->toi_ds_stream_data, 0, sizeof(TOI_DS_Stream_T));
#else
      std::memset(&p_ipc_d2m_payload->toi_stream_data, 0, sizeof(TOI_Stream_T));
#endif
      std::memset(&p_ipc_d2m_payload->radar_capability_data, 0, sizeof(Radar_Capability_Stream_T));
      std::memset(&p_ipc_d2m_payload->interference_detection_data, 0, sizeof(ID_Stream_T));
      std::memset(&p_ipc_d2m_payload->dynamic_alignment_log_stream, 0, sizeof(Dynamic_Alignment_Log_Stream_T));
      std::memset(&p_ipc_d2m_payload->alignment_stream_data, 0, sizeof(Static_Alignment_Log_Stream_T));
   }
}

void TOI_Radar_Status_Info_Init(TOI_Input_Params_T *toi_input_ptr)
{
   D2M_Msg_T *d2m_ptr = (D2M_Msg_T *)Get_IPC_D2M_Buffer();
   M2D_Msg_T *m2d_ptr = (M2D_Msg_T *)Get_IPC_M2D_Buffer();

   if ((NULL != d2m_ptr) && (NULL != m2d_ptr))
   {
      toi_input_ptr->toi_data_status_dst_ptr = &Get_TOI_DATA_STATUS_DST_PTR(d2m_ptr);
      toi_input_ptr->radar_ip_sts_ptr        = m2d_ptr->payload.Radar_Sts_Ptr;
   }
}

void rsp_run(Run_Mode_T mode)
{
   /* Start Timer */
   TIMER_START(RSP_RUN);

   /* clear ipc buffers */
   clear_module_output_buffers(mode);

   switch (mode)
   {
      case Run_Mode_T::RDD:
      {
#if defined(SIL_MODE_RDD)
         bool status = RDD_to_Detection_Configuration(
            static_cast<Radar_Look_T>(Get_IPC_D2M_Buffer()->payload.rdd_stream_data.look_data.look_id),
            &Get_IPC_D2M_Buffer()->payload.rdd_stream_data, &Get_IPC_D2M_Buffer()->payload.rdd_stream_data,
            &Get_IPC_D2M_Buffer()->payload.det_data, &Get_IPC_D2M_Buffer()->payload.det_debug_data,
            &Get_IPC_D2M_Buffer()->payload.downselection_data, &Get_IPC_M2D_Buffer()->payload.veh_data,
            &Get_IPC_M2D_One_Time_Buffer()->radar_position, Get_Status_Log_Data_Ptr());
         assert(status);

         interference_detection_wrapper(Get_IPC_M2D_Buffer(), Get_IPC_D2M_Buffer());

         rc_wrapper(Get_IPC_D2M_Buffer(), Get_IPC_M2D_Buffer(), Get_IPC_M2D_One_Time_Buffer());

         TOI_Radar_Status_Info_Init(Get_TOI_Init_Parameters());
         TOI_Parameters_Init();
         Determine_Data_Quality(Get_TOI_Init_Parameters(), Get_TOI_Output_Parameters());

         dyn_align_wrapper(Get_IPC_D2M_Buffer(), Get_IPC_M2D_Buffer(), Get_IPC_M2D_One_Time_Buffer());

         static_align_wrapper(Get_IPC_D2M_Buffer(), Get_IPC_M2D_Buffer(), Get_IPC_M2D_One_Time_Buffer());
#endif
         break;
      }
      case Run_Mode_T::AF:
      {
#if defined(SIL_MODE_AF)
         bool status = AF_Configure_And_Execute(
            &Get_IPC_D2M_Buffer()->payload.rdd_stream_data, Get_Status_Log_Data_Ptr(), &Get_IPC_D2M_Buffer()->payload.det_data,
            &Get_IPC_D2M_Buffer()->payload.det_debug_data, &Get_IPC_D2M_Buffer()->payload.downselection_data,
            &Get_IPC_M2D_Buffer()->payload.veh_data, &Get_IPC_M2D_One_Time_Buffer()->radar_position);
         assert(status);

         interference_detection_wrapper(Get_IPC_M2D_Buffer(), Get_IPC_D2M_Buffer());

         rc_wrapper(Get_IPC_D2M_Buffer(), Get_IPC_M2D_Buffer(), Get_IPC_M2D_One_Time_Buffer());

         TOI_Radar_Status_Info_Init(Get_TOI_Init_Parameters());
         TOI_Parameters_Init();
         Determine_Data_Quality(Get_TOI_Init_Parameters(), Get_TOI_Output_Parameters());

         dyn_align_wrapper(Get_IPC_D2M_Buffer(), Get_IPC_M2D_Buffer(), Get_IPC_M2D_One_Time_Buffer());

         static_align_wrapper(Get_IPC_D2M_Buffer(), Get_IPC_M2D_Buffer(), Get_IPC_M2D_One_Time_Buffer());
#endif
         break;
      }
      case Run_Mode_T::DSPACE:
      case Run_Mode_T::DETECTION:
      {
#if defined(SIL_MODE_DETECT)
         // TODO: Integrate ID algo after rc_wrapper
         interference_detection_wrapper(Get_IPC_M2D_Buffer(), Get_IPC_D2M_Buffer());

         rc_wrapper(Get_IPC_D2M_Buffer(), Get_IPC_M2D_Buffer(), Get_IPC_M2D_One_Time_Buffer());

         TOI_Radar_Status_Info_Init(Get_TOI_Init_Parameters());
         TOI_Parameters_Init();
         Determine_Data_Quality(Get_TOI_Init_Parameters(), Get_TOI_Output_Parameters());

         dyn_align_wrapper(Get_IPC_D2M_Buffer(), Get_IPC_M2D_Buffer(), Get_IPC_M2D_One_Time_Buffer());

         static_align_wrapper(Get_IPC_D2M_Buffer(), Get_IPC_M2D_Buffer(), Get_IPC_M2D_One_Time_Buffer());
#endif
         break;
      }
      default:
         assert(false);
         break;
   }

#ifdef ENABLE_PROFILING
   std::cout << "[RSP][RUN][PROFILING]" << std::endl;
#endif

   /* Stop Timer */
   TIMER_STOP(RSP_RUN);
}
