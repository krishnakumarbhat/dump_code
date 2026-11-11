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
 * This file has main function call, calling rdd_sil_wrapper function.
 *
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <tuple>
#include <unistd.h>
/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "af_sil_utils.hpp"
#include "binary_header.h"
#include "dyn_align_wrapper.h"
#include "psp_sil_api.hpp"
#include "rdd_sil_api.hpp"
#include "sil_wrapper_utils.hpp"
/*===========================================================================*
 * Global Definitions
 *===========================================================================*/

bool Look_data_Read_Success     = false;
bool Stream_Header_Read_Success = false;
bool Rdd_Bin_Read_Success       = false;
bool Rdd_Execute_Success        = false;
bool Vse_Bin_Read_Success       = false;
bool PSP_Input_Bin_Read_Success = false;
bool PSP_Execute_Pass           = false;

using namespace std;
#define PATH_LENGTH 200
#define LOGGING_ENABLE
#ifdef ENABLE_PROFILING
uint64_t Total_Rdd_Sil_Execution_Time_Ns;
#endif

#ifdef SRR8P
/* Update the bin path here */
char data_bin_path[PATH_LENGTH]     = "sil/rsp_sil/data_bin/srr8p/rdd_data";
char rfft_bin_path[PATH_LENGTH]     = "sil/rsp_sil/data_bin/srr8p/rfft_data";
char psp_data_bin_path[PATH_LENGTH] = "sil/rsp_sil/data_bin/srr8p/psp_data";
char vse_data_bin_path[PATH_LENGTH] = "sil/rsp_sil/data_bin/srr8p/vse_data";
#endif
#ifdef FLR8
/* Update the bin path here */
char data_bin_path[PATH_LENGTH]     = "sil/rsp_sil/data_bin/flr8/rdd_data";
char rfft_bin_path[PATH_LENGTH]     = "sil/rsp_sil/data_bin/flr8/rfft_data";
char psp_data_bin_path[PATH_LENGTH] = "sil/rsp_sil/data_bin/flr8/psp_data";
char vse_data_bin_path[PATH_LENGTH] = "sil/rsp_sil/data_bin/flr8/vse_data";
#endif
/*
 * This Function will be helpful in printing the RDD SIL outputs and thresholds,
 * in text file. The Embedded RDD Log outputs also could be printed in text file
 * and can be verfied.
 */
#ifdef LOGGING_ENABLE

void Print_Rdd_Outputs(RDD_Data_T *out_buff)
{
   uint16_t i, j;

   ofstream rdd_file(PATH_TO_BIN_FILES "/rdd_bv_sil.txt");
   ofstream rdd_out_file(PATH_TO_BIN_FILES "/rdd_out_sil.txt");
   ofstream rdd_thr_file(PATH_TO_BIN_FILES "/rdd_thr_sil.txt");

   for (i = 0; i < out_buff->rdd1_num_detect; i++)
   {
      for (j = 0; j < NUM_TX_CHANNELS; j++)
      {
         for (int32_t k = 0; k < NUM_RX_ANTENNAS; k++)
         {
            rdd_file << out_buff->rdd1_bv[i][j][k];
            rdd_file << ' ';
         }
      }
      rdd_file << endl;
   }
   rdd_file.close();
   rdd_out_file << "rdd1_num_detect ";
   rdd_out_file << out_buff->rdd1_num_detect;
   rdd_out_file << endl;
   rdd_out_file << "rindx ";
   for (i = 0; i < out_buff->rdd1_num_detect; i++)
   {
      rdd_out_file << out_buff->rdd1_rindx[i];
      rdd_out_file << ' ';
   }
   rdd_out_file << endl;
   rdd_out_file << "dindx ";
   for (i = 0; i < out_buff->rdd1_num_detect; i++)
   {
      rdd_out_file << out_buff->rdd1_dindx[i];
      rdd_out_file << ' ';
   }
   rdd_out_file << endl;

   rdd_out_file << "aindx ";
   for (i = 0; i < out_buff->rdd1_num_detect; i++)
   {
      rdd_out_file << out_buff->rdd1_aindx[i];
      rdd_out_file << ' ';
   }
   rdd_out_file << endl;

   rdd_out_file << "rdop_amp ";
   for (i = 0; i < out_buff->rdd1_num_detect; i++)
   {
      rdd_out_file << out_buff->rdd1_rdop_amp[i];
      rdd_out_file << ' ';
   }
   rdd_out_file << endl;
   rdd_out_file << "rbinest ";
   for (i = 0; i < out_buff->rdd1_num_detect; i++)
   {
      rdd_out_file << (out_buff->rdd1_rbinest[i]);
      rdd_out_file << ' ';
   }
   rdd_out_file << endl;
   rdd_out_file << "dbinest ";
   for (i = 0; i < out_buff->rdd1_num_detect; i++)
   {
      rdd_out_file << (out_buff->rdd1_dbinest[i]);
      rdd_out_file << ' ';
   }
   rdd_out_file << endl;

   rdd_out_file << "abinest ";
   for (i = 0; i < out_buff->rdd1_num_detect; i++)
   {
      rdd_out_file << (out_buff->rdd1_abinest[i]);
      rdd_out_file << ' ';
   }
   rdd_out_file << endl;

   rdd_out_file << "rdd2_num_detect ";
   rdd_out_file << out_buff->rdd2_num_detect;
   rdd_out_file << endl;

   rdd_out_file << "rdd2_range ";
   for (i = 0; i < out_buff->rdd1_num_detect; i++)
   {
      rdd_out_file << out_buff->rdd2_range[i];
      rdd_out_file << ' ';
   }
   rdd_out_file << endl;

   rdd_out_file << "rdd2_range_rate ";
   for (i = 0; i < out_buff->rdd1_num_detect; i++)
   {
      rdd_out_file << out_buff->rdd2_range_rate[i];
      rdd_out_file << ' ';
   }
   rdd_out_file << endl;

   rdd_out_file << "rdd2_snr ";
   for (i = 0; i < out_buff->rdd1_num_detect; i++)
   {
      rdd_out_file << out_buff->rdd2_snr[i];
      rdd_out_file << ' ';
   }
   rdd_out_file << endl;

   rdd_out_file << "rdd2_sp_fail_flag ";
   for (i = 0; i < out_buff->rdd1_num_detect; i++)
   {
      rdd_out_file << (uint16_t)out_buff->rdd2_sp_fail_flag[i];
      rdd_out_file << ' ';
   }
   rdd_out_file << endl;

   rdd_out_file.close();
   rdd_thr_file << "cr_resp ";
   for (i = 0; i < MAX_RANGE_BINS; i++)
   {
      rdd_thr_file << out_buff->bwdep_cr_resp[i];
      rdd_thr_file << ' ';
   }
   rdd_thr_file << endl;

   rdd_thr_file << "sens_thold ";
   for (i = 0; i < MAX_RANGE_BINS; i++)
   {
      rdd_thr_file << out_buff->bwdep_sensitivity_thold[i];
      rdd_thr_file << ' ';
   }
   rdd_thr_file << endl;

   rdd_thr_file << "bwdep_hvc_thold ";
   for (i = 0; i < MAX_RANGE_BINS; i++)
   {
      rdd_thr_file << out_buff->bwdep_hvc_thold[i];
      rdd_thr_file << ' ';
   }
   rdd_thr_file << endl;

   rdd_thr_file << "bwdep_mb_thold ";
   for (i = 0; i < MAX_RANGE_BINS; i++)
   {
      rdd_thr_file << out_buff->bwdep_mb_thold[i];
      rdd_thr_file << ' ';
   }
   rdd_thr_file << endl;

   rdd_thr_file << "max_per_range_bin ";
   for (i = 0; i < MAX_RANGE_BINS; i++)
   {
      for (j = 0; j < ANGLE_BINS_USED; j++)
      {
         rdd_thr_file << out_buff->rdd1_max_per_range_bin[i][j];
         rdd_thr_file << ' ';
      }
   }
   rdd_thr_file << endl;
   rdd_thr_file << "Sig_Thold_FP ";
   for (i = 0; i < MAX_RANGE_BINS; i++)
   {
      for (j = 0; j < ANGLE_BINS_USED; j++)
      {
         rdd_thr_file << out_buff->rdd1_signal_thold_first_pass[i][j];
         rdd_thr_file << ' ';
      }
   }
   rdd_thr_file << endl;
   rdd_thr_file << "FP_Thold ";
   for (i = 0; i < MAX_RANGE_BINS; i++)
   {
      for (j = 0; j < ANGLE_BINS_USED; j++)
      {
         rdd_thr_file << out_buff->rdd1_first_pass_thold[i][j];
         rdd_thr_file << ' ';
      }
   }
   rdd_thr_file << endl;

   rdd_thr_file << "rdd2_thold_2nd_pass ";
   for (i = 0; i < MAX_RANGE_BINS; i++)
   {
      for (j = 0; j < ANGLE_BINS_USED; j++)
      {
         rdd_thr_file << out_buff->rdd2_thold_2nd_pass[i][j];
         rdd_thr_file << ' ';
      }
   }
   rdd_thr_file << endl;
   rdd_thr_file.close();
}

void Print_DA_Outputs(Dynamic_Alignment_Log_Stream_T *da_out_buff)
{
   ofstream da_out_file("da_out_sil.txt");

   da_out_file << "version_major :";
   da_out_file << (int)da_out_buff->dra_core_data.version_major;
   da_out_file << endl;

   da_out_file << "version_minor :";
   da_out_file << (int)da_out_buff->dra_core_data.version_minor;
   da_out_file << endl;

   da_out_file << "version_patch :";
   da_out_file << (int)da_out_buff->dra_core_data.version_patch;
   da_out_file << endl;

   da_out_file << "raw_speed :";
   da_out_file << da_out_buff->dra_core_data.raw_speed;
   da_out_file << endl;

   da_out_file << "estimated_speed :";
   da_out_file << da_out_buff->dra_core_data.estimated_speed;
   da_out_file << endl;

   da_out_file << "raw_yawrate :";
   da_out_file << da_out_buff->dra_core_data.raw_yawrate;
   da_out_file << endl;

   da_out_file << "estimated_yawrate :";
   da_out_file << da_out_buff->dra_core_data.estimated_yawrate;
   da_out_file << endl;

   da_out_file << "estimated_yaw_rate_bias :";
   da_out_file << da_out_buff->dra_core_data.estimated_yaw_rate_bias;
   da_out_file << endl;

   da_out_file << "vcs_sensor_long_posn :";
   da_out_file << da_out_buff->dra_core_data.vcs_sensor_long_posn;
   da_out_file << endl;

   da_out_file << "vcs_sensor_lat_posn :";
   da_out_file << da_out_buff->dra_core_data.vcs_sensor_lat_posn;
   da_out_file << endl;

   da_out_file << "sensor_height_over_ground :";
   da_out_file << da_out_buff->dra_core_data.sensor_height_over_ground;
   da_out_file << endl;

   da_out_file << "alignment_index :";
   da_out_file << da_out_buff->dra_core_data.alignment_index;
   da_out_file << endl;

   da_out_file << "vwrapping :";
   da_out_file << da_out_buff->dra_core_data.vwrapping;
   da_out_file << endl;

   da_out_file << "vacs_boresight_az_nominal :";
   da_out_file << da_out_buff->dra_core_data.vacs_boresight_az_nominal;
   da_out_file << endl;

   da_out_file << "vacs_boresight_az_initial :";
   da_out_file << da_out_buff->dra_core_data.vacs_boresight_az_initial;
   da_out_file << endl;

   da_out_file << "vacs_boresight_az_kf_internal :";
   da_out_file << da_out_buff->dra_core_data.vacs_boresight_az_kf_internal;
   da_out_file << endl;

   da_out_file << "vacs_boresight_az_estimated :";
   da_out_file << da_out_buff->dra_core_data.vacs_boresight_az_estimated;
   da_out_file << endl;

   da_out_file << "vacs_boresight_az_variance :";
   da_out_file << da_out_buff->dra_core_data.vacs_boresight_az_variance;

   da_out_file << endl;

   da_out_file << "vacs_boresight_el_nominal :";
   da_out_file << da_out_buff->dra_core_data.vacs_boresight_el_nominal;
   da_out_file << endl;

   da_out_file << "vacs_boresight_el_initial :";
   da_out_file << da_out_buff->dra_core_data.vacs_boresight_el_initial;
   da_out_file << endl;

   da_out_file << "vacs_boresight_el_kf_internal :";
   da_out_file << da_out_buff->dra_core_data.vacs_boresight_el_kf_internal;
   da_out_file << endl;

   da_out_file << "vacs_boresight_el_estimated :";
   da_out_file << da_out_buff->dra_core_data.vacs_boresight_el_estimated;
   da_out_file << endl;

   da_out_file << "vacs_boresight_el_variance :";
   da_out_file << da_out_buff->dra_core_data.vacs_boresight_el_variance;
   da_out_file << endl;

   da_out_file << "vacs_boresight_roll_nominal :";
   da_out_file << da_out_buff->dra_core_data.vacs_boresight_roll_nominal;
   da_out_file << endl;

   da_out_file << "speed_compensation_factor_initial :";
   da_out_file << da_out_buff->dra_core_data.speed_compensation_factor_initial;
   da_out_file << endl;

   da_out_file << "speed_compensation_factor_estimated :";
   da_out_file << da_out_buff->dra_core_data.speed_compensation_factor_estimated;
   da_out_file << endl;

   da_out_file << "avg_spd_since_start :";
   da_out_file << da_out_buff->dra_core_data.avg_spd_since_start;
   da_out_file << endl;

   da_out_file << "avg_spd_running_az_scf :";
   da_out_file << da_out_buff->dra_core_data.avg_spd_running_az_scf;
   da_out_file << endl;

   da_out_file << "avg_spd_running_el :";
   da_out_file << da_out_buff->dra_core_data.avg_spd_running_el;
   da_out_file << endl;

   da_out_file << "total_time_running_az_scf :";
   da_out_file << da_out_buff->dra_core_data.total_time_running_az_scf;
   da_out_file << endl;

   da_out_file << "total_time_running_el :";
   da_out_file << da_out_buff->dra_core_data.total_time_running_el;
   da_out_file << endl;

   da_out_file << "total_time_since_start :";
   da_out_file << da_out_buff->dra_core_data.total_time_since_start;
   da_out_file << endl;

   da_out_file << "total_distance_running_az_scf :";
   da_out_file << da_out_buff->dra_core_data.total_distance_running_az_scf;
   da_out_file << endl;

   da_out_file << "total_distance_running_el :";
   da_out_file << da_out_buff->dra_core_data.total_distance_running_el;
   da_out_file << endl;

   da_out_file << "total_distance_since_start :";
   da_out_file << da_out_buff->dra_core_data.total_distance_since_start;
   da_out_file << endl;

   da_out_file << "alignment_complete_percent_az :";
   da_out_file << da_out_buff->dra_core_data.alignment_complete_percent_az;
   da_out_file << endl;

   da_out_file << "alignment_complete_percent_el :";
   da_out_file << da_out_buff->dra_core_data.alignment_complete_percent_el;
   da_out_file << endl;

   da_out_file << "estimated_standard_deviation_az :";
   da_out_file << da_out_buff->dra_core_data.estimated_standard_deviation_az;
   da_out_file << endl;

   da_out_file << "estimated_standard_deviation_el :";
   da_out_file << da_out_buff->dra_core_data.estimated_standard_deviation_el;
   da_out_file << endl;

   da_out_file << "estimated_pos_error_bound_az :";
   da_out_file << da_out_buff->dra_core_data.estimated_pos_error_bound_az;
   da_out_file << endl;

   da_out_file << "estimated_neg_error_bound_az :";
   da_out_file << da_out_buff->dra_core_data.estimated_neg_error_bound_az;
   da_out_file << endl;

   da_out_file << "estimated_pos_error_bound_el :";
   da_out_file << da_out_buff->dra_core_data.estimated_pos_error_bound_el;
   da_out_file << endl;

   da_out_file << "estimated_neg_error_bound_el :";
   da_out_file << da_out_buff->dra_core_data.estimated_neg_error_bound_el;
   da_out_file << endl;

   da_out_file << "alignment_mode :";
   da_out_file << (int)da_out_buff->dra_core_data.alignment_mode;
   da_out_file << endl;

   da_out_file << "mounting_location :";
   da_out_file << (int)da_out_buff->dra_core_data.mounting_location;
   da_out_file << endl;

   da_out_file << "azimuth_estimation_qf :";
   da_out_file << (int)da_out_buff->dra_core_data.azimuth_estimation_qf;
   da_out_file << endl;

   da_out_file << "elevation_estimation_qf :";
   da_out_file << (int)da_out_buff->dra_core_data.elevation_estimation_qf;
   da_out_file << endl;

   da_out_file << "scf_estimation_qf :";
   da_out_file << (int)da_out_buff->dra_core_data.scf_estimation_qf;
   da_out_file << endl;

   da_out_file << "error_status_combined :";
   da_out_file << (int)da_out_buff->dra_core_data.error_status_combined;
   da_out_file << endl;

   da_out_file << "error_status_initialization :";
   da_out_file << (int)da_out_buff->dra_core_data.error_status_initialization;
   da_out_file << endl;

   da_out_file << "error_status_excessive_blockage :";
   da_out_file << (int)da_out_buff->dra_core_data.error_status_excessive_blockage;
   da_out_file << endl;

   da_out_file << "error_status_interference :";
   da_out_file << (int)da_out_buff->dra_core_data.error_status_interference;
   da_out_file << endl;

   da_out_file << "error_status_detection_input :";
   da_out_file << (int)da_out_buff->dra_core_data.error_status_detection_input;
   da_out_file << endl;

   da_out_file << "error_status_vehicle_input :";
   da_out_file << (int)da_out_buff->dra_core_data.error_status_vehicle_input;
   da_out_file << endl;

   da_out_file << "error_status_scf_out_of_bounds :";
   da_out_file << (int)da_out_buff->dra_core_data.error_status_scf_out_of_bounds;
   da_out_file << endl;

   da_out_file << "error_status_az_est_out_of_bounds :";
   da_out_file << (int)da_out_buff->dra_core_data.error_status_az_est_out_of_bounds;
   da_out_file << endl;

   da_out_file << "error_status_el_est_out_of_bounds :";
   da_out_file << (int)da_out_buff->dra_core_data.error_status_el_est_out_of_bounds;
   da_out_file << endl;

   da_out_file << "blockage_value :";
   da_out_file << (int)da_out_buff->dra_core_data.blockage_value;
   da_out_file << endl;

   da_out_file << "blockage_status :";
   da_out_file << (int)da_out_buff->dra_core_data.blockage_status;
   da_out_file << endl;

   da_out_file.close();
}

void Print_SA_Outputs(Static_Alignment_Log_Stream_T *sa_out_buff)
{
   ofstream sa_out_file("sa_out_sil.txt");

   sa_out_file << "version_major :";
   sa_out_file << (int)sa_out_buff->sra_core_data.version_major;
   sa_out_file << ' ';
   sa_out_file << endl;

   sa_out_file << "version_minor :";
   sa_out_file << (int)sa_out_buff->sra_core_data.version_minor;
   sa_out_file << ' ';
   sa_out_file << endl;

   sa_out_file << "version_patch :";
   sa_out_file << (int)sa_out_buff->sra_core_data.version_patch;
   sa_out_file << ' ';
   sa_out_file << endl;

   sa_out_file << "qf_az :";
   sa_out_file << (int)sa_out_buff->sra_core_data.azimuth_estimation_qf;
   sa_out_file << ' ';
   sa_out_file << endl;

   sa_out_file << "qf_el :";
   sa_out_file << (int)sa_out_buff->sra_core_data.elevation_estimation_qf;
   sa_out_file << ' ';
   sa_out_file << endl;

   sa_out_file << "status_vert_misalign_ang :";
   sa_out_file << (int)sa_out_buff->sra_core_data.error_status_el_est_out_of_bounds;
   sa_out_file << ' ';
   sa_out_file << endl;

   sa_out_file << "status_of_plate :";
   sa_out_file << (int)sa_out_buff->sra_core_data.algo_status;
   sa_out_file << ' ';
   sa_out_file << endl;

   sa_out_file << "vert_misalign_ang :";
   sa_out_file << sa_out_buff->sra_core_data.vacs_boresight_el_estimated - sa_out_buff->sra_core_data.vacs_boresight_el_nominal;
   sa_out_file << ' ';
   sa_out_file << endl;

   sa_out_file << "horiz_misalign_ang :";
   sa_out_file << sa_out_buff->sra_core_data.vacs_boresight_az_estimated - sa_out_buff->sra_core_data.vacs_boresight_az_nominal;
   sa_out_file << ' ';
   sa_out_file << endl;

   sa_out_file << "status_horiz_misalign_ang :";
   sa_out_file << (int)sa_out_buff->sra_core_data.error_status_az_est_out_of_bounds;
   sa_out_file << ' ';
   sa_out_file << endl;

   sa_out_file << "std_azimuth :";
   sa_out_file << sa_out_buff->sra_core_data.estimated_standard_deviation_az;
   sa_out_file << ' ';
   sa_out_file << endl;

   sa_out_file << "std_amplitude :";
   sa_out_file << sa_out_buff->sra_core_data.target_std_dev_raw_amp;
   sa_out_file << ' ';
   sa_out_file << endl;

   sa_out_file << "std_elevation :";
   sa_out_file << sa_out_buff->sra_core_data.estimated_standard_deviation_el;
   sa_out_file << ' ';
   sa_out_file << endl;

   sa_out_file << "std_range :";
   sa_out_file << sa_out_buff->sra_core_data.target_std_dev_range;
   sa_out_file << ' ';
   sa_out_file << endl;

   sa_out_file << "std_r_dot :";
   sa_out_file << sa_out_buff->sra_core_data.target_std_dev_range_rate;
   sa_out_file << ' ';
   sa_out_file << endl;

   sa_out_file << "complete_percentage :";
   sa_out_file << sa_out_buff->sra_core_data.alignment_complete_percentage;
   sa_out_file << endl;

   sa_out_file.close();
}

void Print_RC_Outputs(Radar_Capability_Stream_T *out_buff)
{
   uint16_t i, j;

   ofstream rc_out_file("rc_out_sil.txt");

   rc_out_file << "Radar Capability Outputs";
   rc_out_file << endl;
   rc_out_file << endl;
   rc_out_file << "RC_Version_Output_Stream:";
   rc_out_file << endl;
   rc_out_file << "rc_ver_major: ";
   rc_out_file << (int)out_buff->version.rc_ver_major;
   rc_out_file << endl;

   rc_out_file << "rc_ver_minor: ";
   rc_out_file << (int)out_buff->version.rc_ver_minor;
   rc_out_file << endl;
   rc_out_file << "rc_ver_patch: ";
   rc_out_file << (int)out_buff->version.rc_ver_patch;
   rc_out_file << endl;
   rc_out_file << endl;

   rc_out_file << "fault_table:";
   rc_out_file << endl;
   rc_out_file << "Blockage_Algo_Error: ";
   rc_out_file << (int)out_buff->fault_table.Blockage_Algo_Error;
   rc_out_file << endl;
   rc_out_file << "Damping_Algo_Error: ";
   rc_out_file << (int)out_buff->fault_table.Damping_Algo_Error;
   rc_out_file << endl;
   rc_out_file << "Range_Algo_Error: ";
   rc_out_file << (int)out_buff->fault_table.Range_Algo_Error;
   rc_out_file << endl;
   rc_out_file << "PBD_Monitor_Algo_Error: ";
   rc_out_file << (int)out_buff->fault_table.PBD_Monitor_Algo_Error;
   rc_out_file << endl;
   rc_out_file << endl;

   rc_out_file << "fault_injection:";
   rc_out_file << endl;
   rc_out_file << "fault_type: ";
   rc_out_file << (int)out_buff->fault_injection.fault_type;
   rc_out_file << endl;
   rc_out_file << "run_counter: ";
   rc_out_file << (int)out_buff->fault_injection.run_counter;
   rc_out_file << endl;
   rc_out_file << "f_fault_injected: ";
   rc_out_file << (int)out_buff->fault_injection.f_fault_injected;
   rc_out_file << endl;
   rc_out_file << "f_active: ";
   rc_out_file << (int)out_buff->fault_injection.f_active;
   rc_out_file << endl;
   rc_out_file << endl;

   rc_out_file << "diag:";
   rc_out_file << endl;
   rc_out_file << "elapsed_time_input_fault: ";
   rc_out_file << endl;
   rc_out_file << "total_fault_cnt: ";
   rc_out_file << (int)out_buff->diag.elapsed_time_input_fault.total_fault_cnt;
   rc_out_file << endl;
   rc_out_file << "cur_fault_cnt: ";
   rc_out_file << (int)out_buff->diag.elapsed_time_input_fault.cur_fault_cnt;
   rc_out_file << endl;
   rc_out_file << "f_status_ok: ";
   rc_out_file << (int)out_buff->diag.elapsed_time_input_fault.f_status_ok;
   rc_out_file << endl;
   rc_out_file << "det_look_index_input_fault: ";
   rc_out_file << endl;
   rc_out_file << "total_fault_cnt: ";
   rc_out_file << (int)out_buff->diag.det_look_index_input_fault.total_fault_cnt;
   rc_out_file << endl;
   rc_out_file << "cur_fault_cnt: ";
   rc_out_file << (int)out_buff->diag.det_look_index_input_fault.cur_fault_cnt;
   rc_out_file << endl;
   rc_out_file << "f_status_ok: ";
   rc_out_file << (int)out_buff->diag.det_look_index_input_fault.f_status_ok;
   rc_out_file << endl;
   rc_out_file << "rdd_look_index_input_fault: ";
   rc_out_file << endl;
   rc_out_file << "total_fault_cnt: ";
   rc_out_file << (int)out_buff->diag.rdd_look_index_input_fault.total_fault_cnt;
   rc_out_file << endl;
   rc_out_file << "cur_fault_cnt: ";
   rc_out_file << (int)out_buff->diag.rdd_look_index_input_fault.cur_fault_cnt;
   rc_out_file << endl;
   rc_out_file << "f_status_ok: ";
   rc_out_file << (int)out_buff->diag.rdd_look_index_input_fault.f_status_ok;
   rc_out_file << endl;
   rc_out_file << "veh_index_input_fault: ";
   rc_out_file << endl;
   rc_out_file << "total_fault_cnt: ";
   rc_out_file << (int)out_buff->diag.veh_index_input_fault.total_fault_cnt;
   rc_out_file << endl;
   rc_out_file << "cur_fault_cnt: ";
   rc_out_file << (int)out_buff->diag.veh_index_input_fault.cur_fault_cnt;
   rc_out_file << endl;
   rc_out_file << "f_status_ok: ";
   rc_out_file << (int)out_buff->diag.veh_index_input_fault.f_status_ok;
   rc_out_file << endl;
   rc_out_file << "id_look_index_input_fault: ";
   rc_out_file << endl;
   rc_out_file << "total_fault_cnt: ";
   rc_out_file << (int)out_buff->diag.id_look_index_input_fault.total_fault_cnt;
   rc_out_file << endl;
   rc_out_file << "cur_fault_cnt: ";
   rc_out_file << (int)out_buff->diag.id_look_index_input_fault.cur_fault_cnt;
   rc_out_file << endl;
   rc_out_file << "f_status_ok: ";
   rc_out_file << (int)out_buff->diag.id_look_index_input_fault.f_status_ok;
   rc_out_file << endl;
   rc_out_file << "smc_data_input_fault: ";
   rc_out_file << endl;
   rc_out_file << "total_fault_cnt: ";
   rc_out_file << (int)out_buff->diag.smc_data_input_fault.total_fault_cnt;
   rc_out_file << endl;
   rc_out_file << "cur_fault_cnt: ";
   rc_out_file << (int)out_buff->diag.smc_data_input_fault.cur_fault_cnt;
   rc_out_file << endl;
   rc_out_file << "f_status_ok: ";
   rc_out_file << (int)out_buff->diag.smc_data_input_fault.f_status_ok;
   rc_out_file << endl;
   rc_out_file << "usc_data_input_fault: ";
   rc_out_file << endl;
   rc_out_file << "total_fault_cnt: ";
   rc_out_file << (int)out_buff->diag.usc_data_input_fault.total_fault_cnt;
   rc_out_file << endl;
   rc_out_file << "cur_fault_cnt: ";
   rc_out_file << (int)out_buff->diag.usc_data_input_fault.cur_fault_cnt;
   rc_out_file << endl;
   rc_out_file << "f_status_ok: ";
   rc_out_file << (int)out_buff->diag.usc_data_input_fault.f_status_ok;
   rc_out_file << endl;
   rc_out_file << "mmic_temperature_input_fault: ";
   rc_out_file << endl;
   rc_out_file << "total_fault_cnt: ";
   rc_out_file << (int)out_buff->diag.mmic_temperature_input_fault.total_fault_cnt;
   rc_out_file << endl;
   rc_out_file << "cur_fault_cnt: ";
   rc_out_file << (int)out_buff->diag.mmic_temperature_input_fault.cur_fault_cnt;
   rc_out_file << endl;
   rc_out_file << "f_status_ok: ";
   rc_out_file << (int)out_buff->diag.mmic_temperature_input_fault.f_status_ok;
   rc_out_file << endl;
   rc_out_file << "dyn_align_input_fault: ";
   rc_out_file << endl;
   rc_out_file << "total_fault_cnt: ";
   rc_out_file << (int)out_buff->diag.dyn_align_input_fault.total_fault_cnt;
   rc_out_file << endl;
   rc_out_file << "cur_fault_cnt: ";
   rc_out_file << (int)out_buff->diag.dyn_align_input_fault.cur_fault_cnt;
   rc_out_file << endl;
   rc_out_file << "f_status_ok: ";
   rc_out_file << (int)out_buff->diag.dyn_align_input_fault.f_status_ok;
   rc_out_file << endl;
   rc_out_file << "rf_health_input_fault: ";
   rc_out_file << endl;
   rc_out_file << "total_fault_cnt: ";
   rc_out_file << (int)out_buff->diag.rf_health_input_fault.total_fault_cnt;
   rc_out_file << endl;
   rc_out_file << "cur_fault_cnt: ";
   rc_out_file << (int)out_buff->diag.rf_health_input_fault.cur_fault_cnt;
   rc_out_file << endl;
   rc_out_file << "f_status_ok: ";
   rc_out_file << (int)out_buff->diag.rf_health_input_fault.f_status_ok;
   rc_out_file << endl;
   rc_out_file << "det_rdd_matching_index_input_fault: ";
   rc_out_file << endl;
   rc_out_file << "total_fault_cnt: ";
   rc_out_file << (int)out_buff->diag.det_rdd_matching_index_input_fault.total_fault_cnt;
   rc_out_file << endl;
   rc_out_file << "cur_fault_cnt: ";
   rc_out_file << (int)out_buff->diag.det_rdd_matching_index_input_fault.cur_fault_cnt;
   rc_out_file << endl;
   rc_out_file << "f_status_ok: ";
   rc_out_file << (int)out_buff->diag.det_rdd_matching_index_input_fault.f_status_ok;
   rc_out_file << endl;
   rc_out_file << endl;

   rc_out_file << "Blockage: ";
   rc_out_file << endl;
   for (i = 0; i < 3; i++)
   {
      rc_out_file << "partial blockage[";
      rc_out_file << i;
      rc_out_file << "]: ";
      rc_out_file << endl;
      rc_out_file << "percentage: ";
      rc_out_file << " ";
      rc_out_file << (int)out_buff->blockage.partial_blockage[i].percentage;
      rc_out_file << endl;
      rc_out_file << "Probability: ";
      rc_out_file << " ";
      rc_out_file << (int)out_buff->blockage.partial_blockage[i].probability;
      rc_out_file << endl;
      rc_out_file << "Value: ";
      rc_out_file << " ";
      rc_out_file << (int)out_buff->blockage.partial_blockage[i].value;
      rc_out_file << endl;
   }
   rc_out_file << "blockage: ";
   rc_out_file << endl;
   rc_out_file << "percentage: ";
   rc_out_file << " ";
   rc_out_file << (int)out_buff->blockage.blockage.percentage;
   rc_out_file << endl;
   rc_out_file << "Probability: ";
   rc_out_file << " ";
   rc_out_file << (int)out_buff->blockage.blockage.probability;
   rc_out_file << endl;
   rc_out_file << "Value: ";
   rc_out_file << " ";
   rc_out_file << (int)out_buff->blockage.blockage.value;
   rc_out_file << endl;
   rc_out_file << "blockage_th: ";
   for (i = 0; i < 4; i++)
   {
      rc_out_file << (int)out_buff->blockage.blockage_th[i];
      rc_out_file << " ";
   }
   rc_out_file << endl;
   rc_out_file << "blockage_status: ";
   rc_out_file << (int)out_buff->blockage.blockage_status;
   rc_out_file << endl;
   rc_out_file << "blockage_active: ";
   rc_out_file << (int)out_buff->blockage.blockage_active;
   rc_out_file << endl;
   rc_out_file << endl;

   rc_out_file << "dm:";
   rc_out_file << endl;

   for (i = 0; i < 3; i++)
   {
      rc_out_file << "partial_Damping[";
      rc_out_file << i;
      rc_out_file << "]:";
      rc_out_file << endl;
      rc_out_file << "current_dB: ";
      rc_out_file << (int)out_buff->dm.partial_damping[i].current_dB;
      rc_out_file << " ";
      rc_out_file << endl;
      rc_out_file << "std_dB:";
      rc_out_file << (int)out_buff->dm.partial_damping[i].std_dB;
      rc_out_file << " ";
      rc_out_file << endl;
   }
   rc_out_file << "damping: ";
   rc_out_file << endl;
   rc_out_file << "current_dB: ";
   rc_out_file << (int)out_buff->dm.damping.current_dB;
   rc_out_file << endl;
   rc_out_file << "std_dB: ";
   rc_out_file << (int)out_buff->dm.damping.std_dB;
   rc_out_file << endl;
   rc_out_file << "damping_dB_meas: ";
   rc_out_file << (int)out_buff->dm.damping_dB_meas;
   rc_out_file << endl;
   rc_out_file << "dm_status: ";
   rc_out_file << (int)out_buff->dm.dm_status;
   rc_out_file << endl;
   rc_out_file << "dm_active: ";
   rc_out_file << (int)out_buff->dm.dm_active;
   rc_out_file << endl;
   rc_out_file << endl;

   rc_out_file << "fsc: ";
   rc_out_file << endl;
   rc_out_file << "det_range_hist: ";
   for (i = 0; i < 3; i++)
   {
      rc_out_file << (int)out_buff->fsc.det_range_hist[i];
      rc_out_file << " ";
   }
   rc_out_file << endl;
   rc_out_file << "traveled_time_ms: ";
   rc_out_file << (int)out_buff->fsc.traveled_time_ms;
   rc_out_file << endl;
   rc_out_file << "traveled_dist_m: ";
   rc_out_file << (int)out_buff->fsc.traveled_dist_m;
   rc_out_file << endl;
   rc_out_file << "run_status: ";
   rc_out_file << (int)out_buff->fsc.run_status;
   rc_out_file << endl;
   rc_out_file << "fault_status: ";
   rc_out_file << (int)out_buff->fsc.fault_status;
   rc_out_file << endl;
   rc_out_file << endl;

   rc_out_file << "re: ";
   rc_out_file << endl;
   rc_out_file << "max_det_range_car: ";
   for (i = 0; i < 3; i++)
   {
      rc_out_file << (int)out_buff->re.max_det_range_car[i];
      rc_out_file << " ";
   }
   rc_out_file << endl;
   rc_out_file << "max_det_range_motorbike: ";
   for (i = 0; i < 3; i++)
   {
      rc_out_file << (int)out_buff->re.max_det_range_motorbike[i];
      rc_out_file << " ";
   }
   rc_out_file << endl;
   rc_out_file << "max_det_range_pedestrian: ";
   for (i = 0; i < 3; i++)
   {
      rc_out_file << (int)out_buff->re.max_det_range_pedestrian[i];
      rc_out_file << " ";
   }
   rc_out_file << endl;
   rc_out_file << "re_status: ";
   rc_out_file << (int)out_buff->re.re_status;
   rc_out_file << endl;
   rc_out_file << "re_active: ";
   rc_out_file << (int)out_buff->re.re_active;
   rc_out_file << endl;
   rc_out_file << endl;

   rc_out_file << "se: ";
   rc_out_file << endl;
   rc_out_file << "filt_mean_mnr_region: ";
   for (i = 0; i < 3; i++)
   {
      rc_out_file << (float)out_buff->se.filt_mean_mnr_region[i];
      rc_out_file << " ";
   }
   rc_out_file << endl;
   rc_out_file << "filt_max_mnr_region: ";
   for (i = 0; i < 3; i++)
   {
      rc_out_file << (float)out_buff->se.filt_max_mnr_region[i];
      rc_out_file << " ";
   }
   rc_out_file << "filt_min_chirp_scaling: ";
   rc_out_file << (float)out_buff->se.filt_min_chirp_scaling;
   rc_out_file << endl;
   rc_out_file << "mean_mnr: ";
   for (i = 0; i < 3; i++)
   {
      rc_out_file << (float)out_buff->se.mean_mnr_region[i];
      rc_out_file << " ";
   }
   rc_out_file << endl;
   rc_out_file << "max_mnr_region: ";
   for (i = 0; i < 3; i++)
   {
      rc_out_file << (float)out_buff->se.max_mnr_region[i];
      rc_out_file << " ";
   }
   rc_out_file << endl;
   rc_out_file << "max_mnr: ";
   rc_out_file << (float)out_buff->se.max_mnr_all;
   rc_out_file << endl;
   rc_out_file << "max_range_m: ";
   rc_out_file << (float)out_buff->se.max_range_m;
   rc_out_file << endl;
   rc_out_file << "num_valid_rbins: ";
   for (i = 0; i < 3; i++)
   {
      rc_out_file << (int)out_buff->se.num_valid_rbins[i];
      rc_out_file << " ";
   }
   rc_out_file << endl;
   rc_out_file << "min_rbin_used: ";
   for (i = 0; i < 3; i++)
   {
      rc_out_file << (int)out_buff->se.min_rbin_used[i];
      rc_out_file << " ";
   }
   rc_out_file << endl;
   rc_out_file << "max_rbin_used: ";
   for (i = 0; i < 3; i++)
   {
      rc_out_file << (int)out_buff->se.max_rbin_used[i];
      rc_out_file << " ";
   }
   rc_out_file << endl;
   rc_out_file << "num_st_dets: ";
   rc_out_file << (int)out_buff->se.num_st_dets;
   rc_out_file << endl;
   rc_out_file << "invalid_input_cnt: ";
   rc_out_file << (int)out_buff->se.invalid_input_cnt;
   rc_out_file << endl;
   rc_out_file << "se_status: ";
   rc_out_file << (int)out_buff->se.se_status;
   rc_out_file << endl;
   rc_out_file << "se_active: ";
   rc_out_file << (int)out_buff->se.se_active;
   rc_out_file << endl;
   rc_out_file << "f_low_MCS: ";
   rc_out_file << (int)out_buff->se.f_low_MCS;
   rc_out_file << endl;
   rc_out_file << "f_high_MCS: ";
   rc_out_file << (int)out_buff->se.f_high_MCS;
   rc_out_file << endl;
   rc_out_file << "f_many_dets: ";
   rc_out_file << (int)out_buff->se.f_many_dets;
   rc_out_file << endl;
   rc_out_file << "f_few_dets: ";
   rc_out_file << (int)out_buff->se.f_few_dets;
   rc_out_file << endl;
   rc_out_file << "f_low_MNR_all: ";
   rc_out_file << (int)out_buff->se.f_low_MNR_all;
   rc_out_file << endl;
   rc_out_file << "f_high_MNR_all: ";
   rc_out_file << (int)out_buff->se.f_high_MNR_all;
   rc_out_file << endl;
   rc_out_file << "f_low_damping: ";
   rc_out_file << (int)out_buff->se.f_low_damping;
   rc_out_file << endl;
   rc_out_file << "f_high_damping: ";
   rc_out_file << (int)out_buff->se.f_high_damping;
   rc_out_file << endl;
   rc_out_file << endl;

   rc_out_file << "pbd: ";
   rc_out_file << endl;
   for (i = 0; i < 3; i++)
   {
      rc_out_file << "az_sector[";
      rc_out_file << i;
      rc_out_file << "]: ";
      rc_out_file << endl;
      rc_out_file << "filt_residue_hist_norm: ";
      for (j = 0; j < 6; j++)
      {
         rc_out_file << (float)out_buff->pbd.az_sector[i].filt_residue_hist_norm[j];
         rc_out_file << " ";
      }
      rc_out_file << endl;
      rc_out_file << "residue_hist: ";
      for (j = 0; j < 6; j++)
      {
         rc_out_file << (int)out_buff->pbd.az_sector[i].residue_hist[j];
         rc_out_file << " ";
      }
      rc_out_file << endl;
      rc_out_file << "num_dets: ";
      rc_out_file << (int)out_buff->pbd.az_sector[i].num_dets;
      rc_out_file << endl;
      rc_out_file << "side_lobe_level: ";
      rc_out_file << (int)out_buff->pbd.az_sector[i].side_lobe_level;
      rc_out_file << endl;
   }
   rc_out_file << "pbd_status: ";
   rc_out_file << (int)out_buff->pbd.status;
   rc_out_file << endl;
   rc_out_file << "pbd_active: ";
   rc_out_file << (int)out_buff->pbd.pbd_active;
   rc_out_file << endl;
   rc_out_file << endl;

   rc_out_file << "az_fov_begin_rad: ";
   for (i = 0; i < 3; i++)
   {
      rc_out_file << (float)out_buff->az_fov_begin_rad[i];
      rc_out_file << " ";
   }
   rc_out_file << endl;
   rc_out_file << endl;
   rc_out_file << "az_fov_end_rad: ";
   for (i = 0; i < 3; i++)
   {
      rc_out_file << (float)out_buff->az_fov_end_rad[i];
      rc_out_file << " ";
   }
   rc_out_file << endl;
   rc_out_file << endl;
   rc_out_file << "host_speed_m_s: ";
   rc_out_file << (float)out_buff->host_speed_m_s;
   rc_out_file << endl;
   rc_out_file << endl;
   rc_out_file << "host_yawrate_rad_s: ";
   rc_out_file << (float)out_buff->host_yawrate_rad_s;
   rc_out_file << endl;
   rc_out_file << endl;

   rc_out_file << "normalized_nf_dB: ";
   rc_out_file << (float)out_buff->normalized_nf_dB;
   rc_out_file << endl;
   rc_out_file << endl;
   rc_out_file << "range_coverage_m: ";
   rc_out_file << (float)out_buff->range_coverage_m;
   rc_out_file << endl;
   rc_out_file << endl;
   rc_out_file << "damping_adjustment_dB: ";
   rc_out_file << (float)out_buff->damping_adjustment_dB;
   rc_out_file << endl;
   rc_out_file << endl;
   rc_out_file << "timestamp_ms: ";
   rc_out_file << (int)out_buff->timestamp_ms;
   rc_out_file << endl;
   rc_out_file << endl;
   rc_out_file << "rc_index: ";
   rc_out_file << (int)out_buff->rc_index;
   rc_out_file << endl;
   rc_out_file << endl;
   rc_out_file << "look_index: ";
   rc_out_file << (int)out_buff->look_index;
   rc_out_file << endl;
   rc_out_file << endl;
   rc_out_file << "avg_mmic_onchip_temp: ";
   rc_out_file << (int)out_buff->avg_mmic_onchip_temp;
   rc_out_file << endl;
   rc_out_file << endl;
   rc_out_file << "look_type: ";
   rc_out_file << (int)out_buff->look_type;
   rc_out_file << endl;
   rc_out_file << endl;
   rc_out_file << "sensitivity_level: ";
   rc_out_file << (int)out_buff->sensitivity_level;
   rc_out_file << endl;
   rc_out_file << endl;
   rc_out_file << "RFHealthPercentage: ";
   rc_out_file << (int)out_buff->RFHealthPercentage;
   rc_out_file << endl;
   rc_out_file << endl;
   rc_out_file << "RFMalFunctionFlag: ";
   rc_out_file << (int)out_buff->RFMalFunctionFlag;
   rc_out_file << endl;
   rc_out_file << endl;
   rc_out_file << "RFHealth_EnableStatusFlag: ";
   rc_out_file << (int)out_buff->RFHealth_EnableStatusFlag;
   rc_out_file << endl;
   rc_out_file << endl;
   rc_out_file << "interference_data_discard: ";
   rc_out_file << (int)out_buff->interference_data_discard;
   rc_out_file << endl;
   rc_out_file << endl;
   rc_out_file << "f_ignore_fsc_status: ";
   rc_out_file << (int)out_buff->f_ignore_fsc_status;
   rc_out_file << endl;
   rc_out_file << endl;
   rc_out_file << "rc_active: ";
   rc_out_file << (int)out_buff->rc_active;
   rc_out_file << endl;
   rc_out_file << endl;

   rc_out_file.close();
}

void Print_ID_Outputs(ID_Stream_T *out_buff)
{
   ofstream id_out_file("id_out_sil.txt");

   id_out_file << "Version Major ";
   id_out_file << (uint8_t)out_buff->id_version_major;
   id_out_file << endl;

   id_out_file << "Version Minor ";
   id_out_file << (uint8_t)out_buff->id_version_minor;
   id_out_file << endl;

   id_out_file << "nf_min_db_value ";
   id_out_file << out_buff->nf_min_db_value[0];
   id_out_file << endl;

   id_out_file << "nf_max_db_value ";
   id_out_file << out_buff->nf_max_db_value[0];
   id_out_file << endl;

   id_out_file << "nf_mean_db_value ";
   id_out_file << out_buff->nf_mean_db_value[0];
   id_out_file << endl;

   id_out_file << "normalised_nf ";
   id_out_file << out_buff->normalised_nf;
   id_out_file << endl;

   id_out_file << "interference_health ";
   id_out_file << out_buff->interference_health;
   id_out_file << endl;

   id_out_file << "interference_level ";
   id_out_file << (int)out_buff->interference_level;
   id_out_file << endl;

   id_out_file << "interference_detected ";
   id_out_file << (int)out_buff->interference_detected;
   id_out_file << endl;

   id_out_file << "interference_data_discard ";
   id_out_file << out_buff->interference_data_discard;
   id_out_file << endl;

   id_out_file.close();
}
#endif

/**
 * @brief Wrapper function for RDD SIL processing
 *
 * This function performs the following tasks:
 * 1. Initializes necessary data structures and buffers
 * 2. Reads Look data, Stream Header data, and RDD data from binary files
 * 3. Executes the RDD to Detection Configuration process
 *
 * @details The function uses global boolean flags to track the success of various operations:
 * - Look_data_Read_Success
 * - Stream_Header_Read_Success
 * - Rdd_Bin_Read_Success
 * - Rdd_Execute_Success
 *
 * @note This function assumes the existence of several global variables and functions:
 * - data_bin_path: Path to the binary data files
 * - p_af_det_output: Pointer to AF detection output (type not specified in the given code)
 * - p_vse_stream_data: Pointer to VSE stream data (type not specified in the given code)
 * - p_radar_position_data: Pointer to radar position data (type not specified in the given code)
 *
 * @return void This function does not return a value
 */
void rdd_sil_wrapper()
{
#ifdef ENABLE_PROFILING
   uint64_t start_time_ns, end_time_ns;
#endif

   Radar_Look_T look_id                            = RADAR_LOOK_B;
   uint8_t radar_position_data                     = 0;
   Detection_Stream_T *out_af_det_buff             = new Detection_Stream_T();
   Vse_Stream_T *inp_vse_buff                      = new Vse_Stream_T();
   Detection_Debug_Stream_T *out_af_Det_debug_buff = new Detection_Debug_Stream_T();
   Down_selection_Stream_T *out_af_ds_det_buff     = new Down_selection_Stream_T();
   Status_Stream_T *p_in_status_stream             = new Status_Stream_T();

   /* PSP modules read data from IPC buffers. */
   /* RSP_SIL - d2m,a2m buffer declared here will be used. */
   /* Emb_Lib - d2m,a2m buffer declared inside emb_lib will be used */
   D2M_Msg_T *inp_d2m_buff                   = new D2M_Msg_T();
   M2D_Msg_T *inp_a2m_buff                   = new M2D_Msg_T();
   M2D_One_Time_Msg_T *inp_m2d_one_time_buff = new M2D_One_Time_Msg_T();

   Rdd_Stream_T *p_rdd_stream_in  = new Rdd_Stream_T;
   Rdd_Stream_T *p_rdd_stream_out = new Rdd_Stream_T;
   memset(p_rdd_stream_in, 0, sizeof(Rdd_Stream_T));
   memset(p_rdd_stream_out, 0, sizeof(Rdd_Stream_T));
   memset(inp_vse_buff, 0, sizeof(Vse_Stream_T));
   memset(out_af_det_buff, 0, sizeof(Detection_Stream_T));
   memset(out_af_Det_debug_buff, 0, sizeof(Detection_Debug_Stream_T));
   memset(out_af_ds_det_buff, 0, sizeof(Down_selection_Stream_T));
   memset(p_in_status_stream, 0, sizeof(Status_Stream_T));

#ifdef ENABLE_PROFILING
   start_time_ns = timing_helpers_get_time_nsec();
#endif

   /* Read Look data bin file */
   Look_data_Read_Success = Read_Look_Data_Bin(data_bin_path, &p_rdd_stream_in->look_data);
   if (Look_data_Read_Success != true)
   {
      printf("\n Look Data Reading Failed !\n");
      printf(" MUST RUN from BAZEL WORKSPACE root directory \n");
   }

   /* Read Stream Header data bin file */
   Stream_Header_Read_Success = Stream_Header_Data_Bin(data_bin_path, &p_rdd_stream_in->stream_hdr);
   if (Stream_Header_Read_Success != true)
   {
      printf("\n Stream Header Reading Failed! \n");
      printf(" MUST RUN from BAZEL WORKSPACE root directory \n");
   }

   /* Read Rdd bin file*/
   Rdd_Bin_Read_Success = Read_Rdd_Data_Bin(data_bin_path, &p_rdd_stream_in->rdd_data);
   if (Rdd_Bin_Read_Success != true)
   {
      printf("\n RDD Data Reading Failed \n");
      printf(" MUST RUN from BAZEL WORKSPACE root directory \n");
   }

   /* Read Vse_Stream bin file to get veh_speed */
   Vse_Bin_Read_Success = Read_Vse_Stream_Data_Bin(vse_data_bin_path, inp_vse_buff);
   if (Vse_Bin_Read_Success != true)
   {
      printf("\n Vse Data Reading Failed !\n");
      printf(" MUST RUN from BAZEL WORKSPACE root directory \n");
   }

   /* Read PSP input bin file */
   PSP_Input_Bin_Read_Success = Read_Psp_Input_bin(psp_data_bin_path, inp_d2m_buff, inp_a2m_buff);
   if (PSP_Input_Bin_Read_Success != true)
   {
      printf("\n PSP input Data Reading Failed !\n");
   }

   /*TODO read Status Stream bin file
   Status_Bin_Read_Success = Read_Status_Stream_Data_Bin(status_data_bin_path, p_in_status_stream);
   if (Status_Bin_Read_Success != true)
   {
      printf("\n Status Data Reading Failed !\n");
      printf(" MUST RUN from BAZEL WORKING DIRECTORY root directory \n");
   }
   */

   /* Call the Rdd API*/
   Rdd_Execute_Success = RDD_to_Detection_Configuration(
      (Radar_Look_T)p_rdd_stream_in->look_data.look_id, p_rdd_stream_in, p_rdd_stream_out, out_af_det_buff, out_af_Det_debug_buff,
      out_af_ds_det_buff, inp_vse_buff, &radar_position_data, p_in_status_stream);
   PSP_Execute_Pass = Psp_Sil_Wrapper(inp_vse_buff, p_rdd_stream_out, out_af_det_buff, out_af_Det_debug_buff, inp_d2m_buff,
                                      inp_a2m_buff, inp_m2d_one_time_buff);
#ifdef ENABLE_PROFILING
   end_time_ns                     = timing_helpers_get_time_nsec();
   Total_Rdd_Sil_Execution_Time_Ns = end_time_ns - start_time_ns;
   printf("\nTotal_RDD_Sil_Execution_Time_Ns = %lu\n", Total_Rdd_Sil_Execution_Time_Ns);
#endif

#ifdef LOGGING_ENABLE
   Print_Rdd_Outputs(&p_rdd_stream_out->rdd_data);
   Print_AF_Det_Outputs(out_af_det_buff, out_af_Det_debug_buff);

   #if (DOWNSELECTION_ENABLE == 1U)
   Print_AF_DS_Det_Outputs(out_af_ds_det_buff);
   #endif /* (DOWNSELECTION_ENABLE == 1U)*/
   Print_RC_Outputs(&inp_d2m_buff->payload.radar_capability_data);
   Print_SA_Outputs(&inp_d2m_buff->payload.alignment_stream_data);
   Print_DA_Outputs(&inp_d2m_buff->payload.dynamic_alignment_log_stream);
   Print_ID_Outputs(&inp_d2m_buff->payload.interference_detection_data);
#endif /* LOGGING_ENABLE*/
}

/**
 * @brief Main entry point of the program
 *
 * This function serves as the entry point for the program. It performs the following tasks:
 * 1. Handles Bazel build environment by changing the working directory if necessary
 * 2. Calls the rdd_sil_wrapper function to execute the main logic of the program
 *
 * @input : void - This function takes no parameters
 *
 * @return int Returns 0 to indicate successful program execution
 *
 * @details
 * - The function checks for the "BUILD_WORKING_DIRECTORY" environment variable,
 *   which is set by Bazel during builds. If present, it changes the current
 *   working directory to this path to ensure correct file access.
 * - It calls rdd_sil_wrapper(),
 */
int main(void)
{
   char *bazel_cwd = getenv("BUILD_WORKING_DIRECTORY");
   if (NULL != bazel_cwd)
   {
      chdir(bazel_cwd);
   }

   rdd_sil_wrapper();

   return 0;
}
