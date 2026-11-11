/*===========================================================================*/
/**
 * @file main.cpp
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2024-2025 Aptiv. All rights reserved.
 * Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * This file has the example app for calling Angle Finding SIL API.
 *
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include <cstring>
#include <fstream>
#include <iostream>
#include <tuple>
#include <unistd.h>

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "af_sil_api.hpp"
#include "af_sil_utils.hpp"
#include "afbb_cfg.h"            /* added for accessing AF_TESTING, AF_DOWNSELECTION_ENABLE_L */
#include "sil_wrapper_utils.hpp" /* added for accessing rdd, vse read bin utilities */

#define PATH_LENGTH 200

/*===========================================================================*
 * Global Definitions
 *===========================================================================*/

#ifdef SRR8P
char rdd_stream_data_bin_path[PATH_LENGTH] = "sil/rsp_sil/data_bin/af_data/srr8p/rdd_data";
char vse_stream_data_bin_path[PATH_LENGTH] = "sil/rsp_sil/data_bin/af_data/srr8p/vse_data";
#elif FLR8
char rdd_stream_data_bin_path[PATH_LENGTH] = "sil/rsp_sil/data_bin/af_data/flr8/rdd_data";
char vse_stream_data_bin_path[PATH_LENGTH] = "sil/rsp_sil/data_bin/af_data/flr8/vse_data";
#endif

#ifndef AF_TESTING
bool Rdd_Stream_Bin_Read_Success = false;
bool Vse_Stream_Bin_Read_Success = false;
#endif /* AF_TESTING*/

/**
 * @brief Wrapper function for executing the Angle Finding (AF) SIL (Software-in-the-Loop) API
 *
 * This function performs the following tasks:
 * 1. Initializes input and output buffers for the AF SIL API
 * 2. Calls the AF_Configure_And_Execute function to run the AF SIL API
 * 3. Handles the execution result and outputs
 *
 * @details
 * The function creates and initializes three buffer objects:
 * - inp_rdd_stream_buff: Input buffer for RDD (Raw Detected Data) stream
 * - out_af_det_stream_buff: Output buffer for AF detection stream
 * - vse_stream_buff: Buffer for VSE (Vehicle State Estimation) stream
 *
 * After initialization, it calls the AF_Configure_And_Execute function with these buffers.
 * Based on the execution result, it either reports a failure or writes the AF detection
 * outputs to a CSV file and reports success.
 *
 * @return int Process exit code (suitable for returning from main), 0 indicates success
 */
int af_sil_wrapper(void)
{
   Status_Stream_T in_status_stream_buff                 = {0};
   Rdd_Stream_T in_rdd_stream_buff                       = {0};
   Detection_Stream_T out_af_det_stream_buff             = {0};
   Detection_Debug_Stream_T out_af_det_debug_stream_buff = {0};
   Vse_Stream_T in_vse_stream_buff                       = {0};
   Down_selection_Stream_T out_downselection_stream_buff = {0};

   /* "appl_radar_position" is set 1 by default for this example.
      while integrating  AF_Configure_And_Execute, developer
      should map this from appropriate source (vehicle log data)*/
   uint8_t appl_radar_position = 1;

/* Read from input binaries for the AF API, this will ensure the interface is tested.
   If its AF_TESTING mode the input data is stubbed from AFBB, which will by pass interface.
*/
#ifndef AF_TESTING

   // TODO read one time init logging from status stream

   // TODO read compensation parameters from status stream

   // Read Read_Rdd_Stream bin file to get rdd data , look data
   Rdd_Stream_Bin_Read_Success = Read_Rdd_Stream_Data_Bin(rdd_stream_data_bin_path, &in_rdd_stream_buff);

   // Read Read_Vse_Stream bin file to get veh_speed, veh_yaw
   Vse_Stream_Bin_Read_Success = Read_Vse_Stream_Data_Bin(vse_stream_data_bin_path, &in_vse_stream_buff);

   if (((Rdd_Stream_Bin_Read_Success) || (Vse_Stream_Bin_Read_Success)) != true)
   {
      std::cerr << std::endl << "INPUT Data Reading Failed !" << std::endl;
      return 1;
   }

#endif /*AF_TESTING*/

   /* Calls the AF SIL API */
   if (AF_Configure_And_Execute(&in_rdd_stream_buff, &in_status_stream_buff, &out_af_det_stream_buff,
                                &out_af_det_debug_stream_buff, &out_downselection_stream_buff, &in_vse_stream_buff,
                                &appl_radar_position))
   {
      Write_AF_Outputs(&out_af_det_stream_buff, &out_af_det_debug_stream_buff, &out_downselection_stream_buff);

      return 0;
   }

   return 1;
}

int main(void)
{
   char *bazel_cwd = getenv("BUILD_WORKING_DIRECTORY");
   if (NULL != bazel_cwd)
   {
      chdir(bazel_cwd);
   }

   return af_sil_wrapper();
}
