/*===========================================================================*/
/**
 * @file af_sil_api.cpp
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2024 Aptiv. All rights reserved.
 * Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * This file contains the definition of Angle Finding SIL API.
 *
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include "fff.h"
#include <iostream>
/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "af_sil_api.hpp"
#include "angle_finding_project_interface.h"

#include "afbb_cfg.h"        // for AF_DOWNSELECTION_ENABLE_L, AF_FASCIA_COMPENSATION_ENABLE
#include "ipc_data.h"        // for XCP_Data_T, Calib_Data_T, etc.
#include "mem_pool.h"        // for Memory_Pool_Return_T
#include "radar_sw_config.h" // for max range bins/doppler fft size

/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/
#define AF_MEMORY_POOL1_ALLOCATION_BYTES (100 * 1024)
#define AF_MEMORY_POOL2_ALLOCATION_BYTES (180 * 1024)
DEFINE_FFF_GLOBALS;

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
static Mem_Pool_T Memory_Pool_instance1                    = {0};
static Mem_Pool_T Memory_Pool_instance2                    = {0};
int8_t Memory_Pool_buff1[AF_MEMORY_POOL1_ALLOCATION_BYTES] = {0};
int8_t Memory_Pool_buff2[AF_MEMORY_POOL2_ALLOCATION_BYTES] = {0};

uint16_t XCP_Range_Idx   = MAX_RANGE_BINS;
uint16_t XCP_Doppler_Idx = MAX_DOPPLER_FFT_SIZE;

/* helper function to initialize both mempools defined above */
Memory_Pool_Return_T SIL_Mempool_Setup(void)
{
   Memory_Pool_Return_T retval;
   retval = Mem_Pool_Init(&Memory_Pool_instance1, Memory_Pool_buff1, AF_MEMORY_POOL1_ALLOCATION_BYTES);
   if (MEM_POOL_SUCCESS == retval)
   {
      retval = Mem_Pool_Init(&Memory_Pool_instance2, Memory_Pool_buff2, AF_MEMORY_POOL2_ALLOCATION_BYTES);
   }
   return retval;
}

/**
 * @brief Configures and executes the Angle Finding process.
 *
 * This function sets up the necessary input data structures, initializes memory pools,
 * and executes the Angle Finding process.
 *
 * @param p_rdd_stream_data Pointer to the RDD stream data structure containing radar data and look data.
 * @param p_status_stream Pointer to the Status stream data structure containing one-time init calibration info
 * @param p_af_det_stream_data Pointer to the Detection stream data structure where the output will be stored.
 * @param p_af_det_debug_stream_data Pointer to the AF Detection Debug stream data structure where debug logging will be stored.
 * @param p_af_downselection_stream_data Pointer to Down Selection stream data where the down selected outputs will be stored.
 * @param p_vse_stream_data Pointer to the VSE stream data structure containing vehicle parameters.
 * @param p_radar_position_data Pointer to radar position data.
 *
 * @return bool Returns true if the Angle Finding process was successfully configured and executed,
 *         false otherwise.
 *
 */
bool AF_Configure_And_Execute(Rdd_Stream_T *p_rdd_stream_data, Status_Stream_T *p_status_stream,
                              Detection_Stream_T *p_af_det_stream_data, Detection_Debug_Stream_T *p_af_det_debug_stream_data,
                              Down_selection_Stream_T *p_af_downselection_stream_data, Vse_Stream_T *p_vse_stream_data,
                              uint8_t *p_radar_position_data)
{
   Memory_Pool_Return_T mem_pool_result = MEM_POOL_FAILURE;
   AF_Retval_T af_proc_return           = AF_E_UNKNOWN;
   bool retval                          = false;

   /* define top-level inputs/outputs */
   AF_Appl_Input_T af_appl_input   = {0};
   AF_Appl_Output_T af_appl_output = {0};

   /* define local dummy structures */
   XCP_Data_T local_appl_XCP_data             = {0};
   XCP_Info_T local_appl_XCP_info_data        = {0};
   Angle_Data_XCP_T local_appl_XCP_output     = {0};
   Angle_Timing_Data_T local_appl_timing_data = {0};
   Calib_Data_T local_calib_data              = {0};

   /* Configure input data structures*/
   af_appl_input.appl_rdd_data_ptr       = &(p_rdd_stream_data->rdd_data);
   af_appl_input.appl_look_data_ptr      = &(p_rdd_stream_data->look_data);
   af_appl_input.appl_veh_speed_ptr      = (float32_t *)&(p_vse_stream_data->vse_output.signed_filt_veh_speed_over_ground);
   af_appl_input.calib_data_ptr          = &local_calib_data;
   af_appl_input.appl_veh_speed_ptr      = (float32_t *)&(p_vse_stream_data->vse_output.signed_filt_veh_speed_over_ground);
   af_appl_input.appl_radar_position_ptr = p_radar_position_data;

   /* Stubbing with local dummy structures that aren't relevant to SIL */
   af_appl_input.appl_xcp_data_ptr        = &local_appl_XCP_data;
   af_appl_input.appl_xcp_info_data_ptr   = &local_appl_XCP_info_data;
   af_appl_output.appl_af_xcp_data_ptr    = &local_appl_XCP_output;
   af_appl_output.appl_af_timing_data_ptr = &local_appl_timing_data;

   af_appl_input.appl_xcp_info_data_ptr->xcp_range_idx   = XCP_Range_Idx;
   af_appl_input.appl_xcp_info_data_ptr->xcp_doppler_idx = XCP_Doppler_Idx;

   local_calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_x      = p_status_stream->sensor_mount_pos_x;
   local_calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_y      = p_status_stream->sensor_mount_pos_y;
   local_calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_z      = p_status_stream->sensor_mount_pos_z;
   local_calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_roll  = p_status_stream->sensor_mount_ornt_roll;
   local_calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_pitch = p_status_stream->sensor_mount_ornt_pitch;
   local_calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_yaw   = p_status_stream->sensor_mount_ornt_yaw;

   /* Configure output data structures*/
   af_appl_output.appl_detection_stream_data_ptr = p_af_det_stream_data;
   af_appl_output.appl_detection_debug_data_ptr  = p_af_det_debug_stream_data;

#if (AF_DOWNSELECTION_ENABLE_L == 1U)
   af_appl_output.appl_down_selection_stream_data_ptr = p_af_downselection_stream_data;
#endif

   if (MEM_POOL_SUCCESS == SIL_Mempool_Setup())
   {
      mem_pool_result = Anglefinding_Memory_Init(&Memory_Pool_instance1, &Memory_Pool_instance2);
      if (mem_pool_result == MEM_POOL_SUCCESS)
      {
         std::cerr << "AF_Configure_And_Execute: mempool1 size needed: " << Memory_Pool_instance1.size << std::endl;
         std::cerr << "AF_Configure_And_Execute: mempool2 size needed: " << Memory_Pool_instance2.size << std::endl;

         af_proc_return = Appl_Angle_Finding_Process(&af_appl_input, &af_appl_output);
#ifdef AF_CFG_SIL_BUILD
         std::cerr << "AF_Configure_And_Execute: AF internal mempool size needed: " << g_af_used_af_mempool_size << " ("
                   << (g_af_used_af_mempool_size / sizeof(creal32_T)) << " / " << g_af_max_af_mempool_size << ")" << std::endl;
#else
   #warning Please add --@afbb//module/_common:sil_config_enable=True to your command line when running AF SIL
#endif
         if (AF_E_OK != af_proc_return)
         {
            std::cerr << "AF_Configure_And_Execute: AF SIL execution Failed: " << af_proc_return << std::endl;
            retval = false;
         }
         else
         {
            int i, n;
            int minidx       = 0;
            int maxidx       = 0;
            float32_t maxran = 0.0F;
            float32_t minran = 1.0E6F;

            std::cerr << "AF_Configure_And_Execute: AF SIL execution Success!" << std::endl;
            n = p_af_det_stream_data->num_af_det;
            std::cout << "Anglefinding Summary --" << std::endl;
            std::cout << "Overall num output detections: " << n << std::endl;
            std::cout << "    Stage 1 output detections: "
                      << p_af_det_debug_stream_data->af_det_debug_data.target_selected_post_stage_1 << std::endl;
            std::cout << "    Stage 2 output detections: "
                      << p_af_det_debug_stream_data->af_det_debug_data.target_selected_post_stage_2 << std::endl;
            std::cout << "    Stage 3 output detections: "
                      << p_af_det_debug_stream_data->af_det_debug_data.target_selected_post_stage_3 << std::endl;
            std::cout << "    Stage 4 output detections: "
                      << p_af_det_debug_stream_data->af_det_debug_data.target_selected_post_stage_4 << std::endl;
            std::cout << "    Stage 5 output detections: "
                      << p_af_det_debug_stream_data->af_det_debug_data.target_selected_post_stage_5 << std::endl;
            std::cout << " Num Stage 1 input detections: " << local_appl_timing_data.num_af_stage1 << std::endl;
            std::cout << " Num Stage 2 input detections: " << local_appl_timing_data.num_af_stage2 << std::endl;
            std::cout << " Num Stage 3 input detections: " << local_appl_timing_data.num_af_stage3 << std::endl;
            std::cout << " Num Stage 4 input detections: " << local_appl_timing_data.num_af_stage4 << std::endl;
            std::cout << " Num Stage 5 input detections: " << local_appl_timing_data.num_af_stage5 << std::endl;
            for (i = 0; i < n; i++)
            {
               if (p_af_det_stream_data->af_dets[i].ran > maxran)
               {
                  maxran = p_af_det_stream_data->af_dets[i].ran;
                  maxidx = i;
               }
               if (p_af_det_stream_data->af_dets[i].ran < minran)
               {
                  minran = p_af_det_stream_data->af_dets[i].ran;
                  minidx = i;
               }
            }
            std::cout << "                    Max range: " << maxran << " (@idx " << maxidx << ")" << std::endl;
            std::cout << "                    Min range: " << minran << " (@idx " << minidx << ")" << std::endl;
            retval = true;
         }
      }
      else
      {
         std::cerr << "AF_Configure_And_Execute: Angle Finding memory init failed: " << mem_pool_result << std::endl;
         retval = false;
      }
      Mem_Pool_Reset(&Memory_Pool_instance1);
      Mem_Pool_Reset(&Memory_Pool_instance2);
   }
   else
   {
      std::cerr << "AF_Configure_And_Execute: Memory Pool Setup failed" << std::endl;
      retval = false;
   }

#if (AF_FASCIA_COMPENSATION_ENABLE == 1U)
   if (retval)
   {
      /* TODO: read compensation parameters from status stream input */
      Fascia_Comp_Data_T fc_compensation_params;
      memset(&fc_compensation_params, 0, sizeof(fc_compensation_params));

      mem_pool_result = Fascia_Compensation_Memory_Init(&Memory_Pool_instance1);
      if (mem_pool_result == MEM_POOL_SUCCESS)
      {
         /* Execute Fascia Compensation */
         Appl_Execute_Fascia_Compensation(&fc_compensation_params, &af_appl_output);
         if (af_appl_output.appl_detection_stream_data_ptr->det_list_property.slope_correction_status != FS_NO_SLOPE_CORRECTION)
         {
            std::cerr << "Fascia Compensation successfully applied" << std::endl;
         }
         else
         {
            std::cerr << "Fascia Compensation NOT applied" << std::endl;
         }
      }
      else
      {
         std::cerr << "AF_Configure_And_Execute: Fascia Compensation memory init failed: " << mem_pool_result << std::endl;
         retval = false;
      }
      Mem_Pool_Reset(&Memory_Pool_instance1);
      Mem_Pool_Reset(&Memory_Pool_instance2);
   }
   else
   {
      std::cerr << "Fascia Compensation skipped due to earlier error" << std::endl;
   }
#endif

#if (AF_DOWNSELECTION_ENABLE_L == 1U)
   if (retval)
   {
      mem_pool_result = DownSelection_Memory_Init(&Memory_Pool_instance1);
      if (mem_pool_result == MEM_POOL_SUCCESS)
      {
         std::cerr << "AF_Configure_And_Execute: DS mempool size needed: " << Memory_Pool_instance1.size << std::endl;
         af_proc_return = Appl_Down_Selection_Process(&af_appl_input, &af_appl_output);
         if (AF_E_OK != af_proc_return)
         {
            std::cerr << "AF_Configure_And_Execute: DS SIL execution Failed: " << af_proc_return << std::endl;
            retval = false;
         }
         else
         {
            int i, n;
            int minidx       = 0;
            int maxidx       = 0;
            float32_t maxran = 0.0F;
            float32_t minran = 1.0E6F;

            std::cerr << "AF_Configure_And_Execute: DS SIL execution Success!" << std::endl;
            n = p_af_downselection_stream_data->num_af_ds_det;
            for (i = 0; i < n; i++)
            {
               if (p_af_downselection_stream_data->af_ds_dets[i].ran > maxran)
               {
                  maxran = p_af_downselection_stream_data->af_ds_dets[i].ran;
                  maxidx = i;
               }
               if (p_af_downselection_stream_data->af_ds_dets[i].ran < minran)
               {
                  minran = p_af_downselection_stream_data->af_ds_dets[i].ran;
                  minidx = i;
               }
            }
            std::cout << "Downselection Summary --" << std::endl;
            std::cout << "Overall num output detections: " << n << std::endl;
            std::cout << "                    Max range: " << maxran << " (@idx " << maxidx << ")" << std::endl;
            std::cout << "                    Min range: " << minran << " (@idx " << minidx << ")" << std::endl;
            retval = true;
         }
      }
      else
      {
         std::cerr << "AF_Configure_And_Execute: Down Selection memory init failed: " << mem_pool_result << std::endl;
         retval = false;
      }
      Mem_Pool_Reset(&Memory_Pool_instance1);
      Mem_Pool_Reset(&Memory_Pool_instance2);
   }
#endif

   return retval;
}
