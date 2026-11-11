/*===========================================================================*/
/**
 * @file rdd_sil_interface.cpp
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
 * This file is for .
 *
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include <cstring>
#include <stdio.h>
#include <tuple>
#include <xtensa/tie/xt_bben.h>

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "af_sil_api.hpp"
extern "C"
{
#include "spbb_math.c"
}
#include "appl_sp_ifc.h"
#include "detection_stream.h"
#include "rdd_sil_api.hpp"

/**
 * @brief Configures and processes RDD till detection.
 *
 * This function takes input RDD data, processes it, and prepares it for the second pass
 * detection and AF (Application Function) configuration and execution.
 *
 * @param look_id The radar look id.
 * @param p_rdd_data_in Pointer to the input RDD stream data.
 * @param p_rdd_data_out Pointer to the output RDD stream data.
 * @param p_af_det_stream_data Pointer to the AF detection stream data.
 * @param p_vse_stream_data Pointer to the VSE stream data.
 * @param p_radar_position_data Radar position data.
 *
 * @return bool Returns true if the configuration and processing were successful, false otherwise.
 *
 * @note The function performs the following main operations:
 *       1. Copies RDD data from input to output structures.
 *       2. Initializes and executes the second pass detection.
 *       3. Configures and executes the AF module.
 */
bool RDD_to_Detection_Configuration(Radar_Look_T look_id, Rdd_Stream_T *p_rdd_data_in, Rdd_Stream_T *p_rdd_data_out,
                                    Detection_Stream_T *p_af_det_stream_data, Detection_Debug_Stream_T *p_af_det_debug_stream_data,
                                    Down_selection_Stream_T *p_af_downselection_stream_data, Vse_Stream_T *p_vse_stream_data,
                                    uint8_t *p_radar_position_data, Status_Stream_T *p_status_stream)
{
   bool ret_Value              = false;
   XCP_Data_T local_xcp_data   = {0};
   bool AF_Config_Execute_Pass = false;

   if ((NULL != p_rdd_data_in) && (NULL != p_vse_stream_data) && (NULL != p_radar_position_data))
   {
      p_rdd_data_out->rdd_data.rdd1_num_detect = p_rdd_data_in->rdd_data.rdd1_num_detect;
      memcpy(&p_rdd_data_out->rdd_data.bwdep_hvc_thold, p_rdd_data_in->rdd_data.bwdep_hvc_thold,
             sizeof(uint32_t) * MAX_RANGE_BINS);
      memcpy(&p_rdd_data_out->rdd_data.rdd1_max_per_range_bin, p_rdd_data_in->rdd_data.rdd1_max_per_range_bin,
             sizeof(uint16_t) * MAX_RANGE_BINS * ANGLE_BINS_USED);
      memcpy(&p_rdd_data_out->rdd_data.bwdep_mb_thold, p_rdd_data_in->rdd_data.bwdep_mb_thold, sizeof(uint32_t) * MAX_RANGE_BINS);
      memcpy(&p_rdd_data_out->rdd_data.cfar_nf_est, p_rdd_data_in->rdd_data.cfar_nf_est,
             sizeof(uint16_t) * MAX_RANGE_BINS * ANGLE_BINS_USED);
      memcpy(&p_rdd_data_out->rdd_data.rdd1_dbinest, p_rdd_data_in->rdd_data.rdd1_dbinest, sizeof(s10p21_T) * MAX_DETS_FIRST_PASS);
      memcpy(&p_rdd_data_out->rdd_data.rdd1_abinest, p_rdd_data_in->rdd_data.rdd1_abinest, sizeof(s10p21_T) * MAX_DETS_FIRST_PASS);
      memcpy(&p_rdd_data_out->rdd_data.rdd1_dindx, p_rdd_data_in->rdd_data.rdd1_dindx, sizeof(uint16_t) * MAX_DETS_FIRST_PASS);
      memcpy(&p_rdd_data_out->rdd_data.rdd1_aindx, p_rdd_data_in->rdd_data.rdd1_aindx, sizeof(uint16_t) * MAX_DETS_FIRST_PASS);
      memcpy(&p_rdd_data_out->rdd_data.rdd1_rbinest, p_rdd_data_in->rdd_data.rdd1_rbinest, sizeof(s10p21_T) * MAX_DETS_FIRST_PASS);
      memcpy(&p_rdd_data_out->rdd_data.rdd1_rdop_amp, p_rdd_data_in->rdd_data.rdd1_rdop_amp,
             sizeof(uint16_t) * MAX_DETS_FIRST_PASS);
      memcpy(&p_rdd_data_out->rdd_data.rdd1_rindx, p_rdd_data_in->rdd_data.rdd1_rindx, sizeof(uint16_t) * MAX_DETS_FIRST_PASS);
      memcpy(&p_rdd_data_out->rdd_data.bwdep_sensitivity_thold, p_rdd_data_in->rdd_data.bwdep_sensitivity_thold,
             sizeof(uint32_t) * MAX_RANGE_BINS);
      memcpy(&p_rdd_data_out->rdd_data.rdd1_signal_thold_first_pass, p_rdd_data_in->rdd_data.rdd1_signal_thold_first_pass,
             sizeof(uint16_t) * MAX_RANGE_BINS * ANGLE_BINS_USED);
      memcpy(&p_rdd_data_out->rdd_data.nci_bexp, p_rdd_data_in->rdd_data.nci_bexp,
             sizeof(uint16_t) * MAX_RANGE_BINS * ANGLE_BINS_USED);

      memcpy(&p_rdd_data_out->rdd_data.rdd1_first_pass_thold, p_rdd_data_in->rdd_data.rdd1_first_pass_thold,
             sizeof(uint16_t) * MAX_RANGE_BINS * ANGLE_BINS_USED);

      memcpy(&p_rdd_data_out->rdd_data.rdd1_bv, &p_rdd_data_in->rdd_data.rdd1_bv,
             (sizeof(uint16_t) * MAX_DETS_FIRST_PASS * NUM_TX_CHANNELS * NUM_RX_ANTENNAS));

      memcpy(&p_rdd_data_out->rdd_data.bwdep_cr_resp, p_rdd_data_in->rdd_data.bwdep_cr_resp, sizeof(uint32_t) * MAX_RANGE_BINS);

      memcpy(&p_rdd_data_out->rdd_data.rdd2_thold_2nd_pass, p_rdd_data_in->rdd_data.rdd2_thold_2nd_pass,
             sizeof(uint32_t) * MAX_RANGE_BINS * ANGLE_BINS_USED);

      /* Mapping other streams */
      memcpy(&p_rdd_data_out->look_data, &p_rdd_data_in->look_data, sizeof(Look_Data_T));
      memcpy(&p_rdd_data_out->stream_hdr, &p_rdd_data_in->stream_hdr, sizeof(Stream_Hdr_T));

      Appl_Second_Pass_Init(look_id);

      /* Call Application Function for Second Pass module */
      Appl_Second_Pass_Execute(&p_rdd_data_out->rdd_data);

#ifdef ENABLE_PROFILING
      end_time_ns            = timing_helpers_get_time_nsec();
      Rdd2_Execution_Time_Ns = end_time_ns - start_time_ns;
      printf("\nRdd2_Execution_Time_Ns = %lu", Rdd2_Execution_Time_Ns);
#endif

      AF_Config_Execute_Pass =
         AF_Configure_And_Execute(p_rdd_data_out, p_status_stream, p_af_det_stream_data, p_af_det_debug_stream_data,
                                  p_af_downselection_stream_data, p_vse_stream_data, p_radar_position_data);

      ret_Value = true;
   }
   return ret_Value;
}
