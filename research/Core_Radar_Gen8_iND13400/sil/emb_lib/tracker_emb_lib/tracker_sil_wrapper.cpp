#ifndef TRACKER_DISABLED
   #include "emb_tracker_wrapper.h"
   #include "emblib_ipc_data.h"
   #include "mem_pool.h"
   #include "profile_timing.h"
   #include "sil_macros_time.h"
   #include "sil_wrapper_common.h"
#endif

static bool xtrk_file_open = false;

void tracker_run(const char *xtrk_filename)
{
#ifndef TRACKER_DISABLED

   /* Start Timer */
   TIMER_START(TRACKER);

   static bool tracker_initialized = false;
   // static bool xtrk_file_open = false;
   static Mem_Pool_T Memory_Pool_Dram1 = {0};

   /* Get IPC pointers to pass to tracker wrapper */
   D2M_Msg_T *p_ipc_d2m                   = (D2M_Msg_T *)Get_IPC_D2M_Buffer();
   M2D_Msg_T *p_ipc_m2d                   = (M2D_Msg_T *)Get_IPC_M2D_Buffer();
   M2D_One_Time_Msg_T *p_ipc_m2d_one_time = (M2D_One_Time_Msg_T *)Get_IPC_M2D_One_Time_Buffer();

   #if defined(AL_TRACKER)
   if (p_ipc_m2d_one_time->radar_position == RADAR_POSITION_FRONT_LEFT)
   {
      return;
   }
   #endif

   if (p_ipc_m2d_one_time->calib_data.data_availability_status == CODED_TRUE &&
       (tracker_initialized || p_ipc_m2d->payload.veh_data.vse_output_valid))
   {
      /* Initialize tracker memory and allocate mempool usage */
      Memory_Pool_Return_T mem_pool_result = Emb_Tracker_Mem_Init(&Memory_Pool_Dram1, p_ipc_d2m);

      /* Don't run the tracker if mempool allocation failed */
      if (mem_pool_result == MEM_POOL_SUCCESS)
      {
         /* Don't re-initialize tracker unless necessary */
         if (!tracker_initialized)
         {
            /* Initialize tracker, related modules, and necessary variables */
            Init_Emb_Tracker(p_ipc_m2d_one_time, p_ipc_m2d);
            tracker_initialized = true;
         }

         /* Open xtrk file at the start of each log cycle after it was closed by save_files() */
         if (!xtrk_file_open && xtrk_filename && *xtrk_filename)
         {
            Open_F360_Tracker_Xtrk_File(xtrk_filename);
            xtrk_file_open = true;
         }

         /* Run the embedded tracker */
         Run_Emb_Tracker(p_ipc_d2m, p_ipc_m2d, p_ipc_m2d_one_time);
      }

      /* Return used mempool memory */
      Mem_Pool_Reset(&Memory_Pool_Dram1);
   }
   /* Stop Timer */
   TIMER_STOP(TRACKER);
#endif
}

void close_xtrk_file()
{
#ifndef TRACKER_DISABLED
   if (xtrk_file_open)
   {
      Close_F360_Tracker_Xtrk_File();
      xtrk_file_open = false;
   }
#endif
}
