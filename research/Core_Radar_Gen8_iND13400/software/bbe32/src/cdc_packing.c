/*===========================================================================*/
/**
 * @file cdc_packing.c
 *
 * This module packs the CDC Beam vectors into CDC Records
 * and copies onto ENET buffer.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 *Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 *
 * @section ABBR ABBREVIATIONS:
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *
 *   - Requirements Document(s):
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/
/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include <string.h>
#if defined(APRISM_CDC_PRIO_ENABLE) && (APRISM_CDC_PRIO_ENABLE == 1)
#include <math.h>
#endif
/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "api/bbe_helpers.h"
#include "api/sysmem_helpers.h"
#include "api/timing_helpers.h"
#include "appl_fp_ifc.h"
#if defined(APRISM_CDC_PRIO_ENABLE) && (APRISM_CDC_PRIO_ENABLE == 1)
#include "cdc_priority.h"
#endif
#include "cdc_packing.h"
#include "cdc_stream.h"
#include "doppler_process_ifc.h"
#include "ipc_data.h"
#include "rdd_first_pass_prv.h"
#include "rdd_stream.h"
#include "smc_cal.h"

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
#define CDC_DBIN_MASK ((uint16_t)0x3FFF)
#define ROUND_FACTOR  (0.001F)
/*for BBE32 to R52 CDC frame sync testing purspose*/
/*#define DSP_CDC_VERIFY*/

/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/
/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/
typedef struct Cdc_Packing_Param_Tag
{
   bool partial_frame_available;
   uint8_t enet_frame_index;
   uint16_t cdc_records_in_partial_frame;
   uint16_t cdc_message_id;
   uint16_t enet_frame_buffer_depth;
   CDC_Record_T *p_enet_buffer;
   float32_t recip_cdc_num_records_per_frame;
   uint16_t cdc_enet_frame_count;
   uint16_t cdc_enet_packet_tx_cnt;
} Cdc_Packing_Param_T;
#ifdef DSP_CDC_VERIFY
static uint16_t Frame_Cnt        = 0U;
volatile uint8_t record_cnt_temp = 0; /*Due to build error fix */
#endif

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/
////////////////////////////////////////////////////////////////////////
// The variables for this is on SRAM and the pointer is acquired via IPC
/////////////////////////////////////////////////////////////////////////
/* CDC ENET Packet Buffer */
CDC_Stream_T __attribute__((aligned(32), section(".sram_streamdata_section"))) Cdc_Enet_Packets[CDC_NUM_ENET_TX_BUFFERS] = {0};
/* The base address of Cdc_Frame_Interface is sent to R52 over ipc_notify_structure */
volatile Cdc_Frame_Interface_T __attribute__((section(".sram_streamdata_section"))) Cdc_Frame_Interface = {0};

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
Cdc_Packing_Param_T Cdc_Log_Param = {false, 0U, 0U, 0U, CDC_NUM_ENET_TX_BUFFERS, NULL, 0.0F, 0U, 0U};

#if defined(APRISM_CDC_PRIO_ENABLE) && (APRISM_CDC_PRIO_ENABLE == 1)
/* A-PRISM priority-rank work buffers (static: no DSP stack pressure). */
static float aprism_cdc_score[MAX_CDC_DBIN_COUNT_PER_RBIN];
static int32_t aprism_cdc_idx[MAX_CDC_DBIN_COUNT_PER_RBIN];
static uint16_t aprism_cdc_tmp[MAX_CDC_DBIN_COUNT_PER_RBIN];
static bool aprism_cdc_tmpflag[MAX_CDC_DBIN_COUNT_PER_RBIN];
#endif

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/
inline void Cdc_Enet_Frame_Update(uint16_t scan_index, uint16_t enet_frame_buffer_depth, uint16_t records_per_frame);
/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/
static inline void Populate_Cdc_Bv(BV_Comp_Type_T (*p_beam_vector_data)[NUM_RX_CHANNELS][MAX_DOPPLER_FFT_SIZE],
                                   CDC_Record_T *p_enet_buffer_base_address, uint16_t *p_cdc_dbin_array, uint8_t *enet_frame_index,
                                   uint16_t range_idx, uint16_t start_idx, uint16_t end_idx, bool *p_ci_flag_array);
/*===========================================================================*
 * Function Definitions
 *===========================================================================*/
/* This function copies the BV for the selected CDC dbins and then copy the CDC Records into ENET buffer.
 *  The ENET header information is also updated.
 */
void Cdc_Packing(Look_Data_T *p_look_data, uint16_t range_idx, uint16_t cdc_dbin_count,
                 BV_Comp_Type_T (*dfft_bv_buffer)[NUM_RX_CHANNELS][MAX_DOPPLER_FFT_SIZE])
{
   uint16_t total_cdc_records_to_be_logged;
   uint16_t *restrict p_cdc_array;
   bool *restrict p_ci_flag_array;
   BV_Comp_Type_T(*p_beam_vector_data)[NUM_RX_CHANNELS][MAX_DOPPLER_FFT_SIZE];
   bool partial_frame_available;
   uint16_t cdc_records_in_partial_frame;
   uint16_t num_records_remaining;
   CDC_Record_T *restrict p_enet_buffer_base_address;
   uint8_t enet_frame_index;
   uint16_t records_to_be_logged_in_full_frame = 0U;
   uint16_t records_to_be_logged_in_partial_frame;
   bool records_to_be_logged_in_partial_frame_enable;
   uint8_t enet_frame_loop_idx;
   uint16_t enet_frame_buffer_depth;
   uint16_t prev_enet_buffer_depth = 0U;
   uint16_t local_frame_buffer_depth;
   uint16_t loop_count;
   bool cdc_last_rbin;
   uint16_t cdc_enet_frame_count;
   uint16_t cdc_message_id;
   float32_t recip_cdc_num_rec_per_frame;
   uint16_t start_idx;
   uint16_t end_idx;
   uint16_t cdc_enet_packet_tx_cnt;
   uint16_t scan_index = p_look_data->scan_index;

   total_cdc_records_to_be_logged = cdc_dbin_count;
   p_cdc_array                    = Get_Cdc_Dbin_Array_Buffer_Ptr();
   p_ci_flag_array                = Get_Ci_Flag_Array_Buffer_Ptr();

#if defined(APRISM_CDC_PRIO_ENABLE) && (APRISM_CDC_PRIO_ENABLE == 1)
   /* A-PRISM priority-ranked CDC packing (F5): real reorder, default OFF.
    * Reorder-only (count unchanged) so ENET frame accounting is untouched.
    * ponytail: range is ordinal here — per-call order is SNR-driven since r
    * is constant within one range bin; use range_idx*range_res_m when the FP
    * owner confirms the resolution macro. SNR feed mirrors this module's own
    * packed amplitude (NCI/CI row, same per-record selection as below). */
   if ((cdc_dbin_count > 1U) && (cdc_dbin_count <= (uint16_t)MAX_CDC_DBIN_COUNT_PER_RBIN))
   {
      uint16_t pi;
      int32_t kept;
      float rng_m = (float)range_idx + 1.0F;
      for (pi = 0U; pi < cdc_dbin_count; pi++)
      {
         uint16_t dop = (uint16_t)(p_cdc_array[pi] & CDC_DBIN_MASK);
         uint16_t amp = rdop_avg_data_ptr[NCI_CURRENT_BUFFER_DEPTH][dop];
         float snr_db;
         if (p_ci_flag_array[pi])
         {
            amp = ci_rdop_avg_data_ptr[CI_CURRENT_BUFFER_DEPTH][dop];
         }
         /* log10(x) = ln(x)/ln(10); logf follows this repo's DSP float usage. */
         snr_db                 = 10.0F * logf(1.0F + (float)amp) * 0.43429448F;
         aprism_cdc_score[pi]   = CdcPriorityScore(snr_db, rng_m);
         aprism_cdc_idx[pi]     = (int32_t)pi;
      }
      kept = CdcSelectTopK(aprism_cdc_score, (int32_t)cdc_dbin_count, (int32_t)cdc_dbin_count, aprism_cdc_idx);
      if (kept == (int32_t)cdc_dbin_count)
      {
         for (pi = 0U; pi < cdc_dbin_count; pi++)
         {
            aprism_cdc_tmp[pi]     = p_cdc_array[(uint16_t)aprism_cdc_idx[pi]];
            aprism_cdc_tmpflag[pi] = p_ci_flag_array[(uint16_t)aprism_cdc_idx[pi]];
         }
         for (pi = 0U; pi < cdc_dbin_count; pi++)
         {
            p_cdc_array[pi]     = aprism_cdc_tmp[pi];
            p_ci_flag_array[pi] = aprism_cdc_tmpflag[pi];
         }
      }
   }
#endif

   p_beam_vector_data = (BV_Comp_Type_T(*)[NUM_RX_CHANNELS][MAX_DOPPLER_FFT_SIZE])(dfft_bv_buffer);

   partial_frame_available      = Cdc_Log_Param.partial_frame_available;
   cdc_records_in_partial_frame = Cdc_Log_Param.cdc_records_in_partial_frame;
   enet_frame_index             = Cdc_Log_Param.enet_frame_index;
   enet_frame_buffer_depth      = Cdc_Log_Param.enet_frame_buffer_depth;
   p_enet_buffer_base_address   = (CDC_Record_T *)Cdc_Log_Param.p_enet_buffer;
   cdc_enet_frame_count         = Cdc_Log_Param.cdc_enet_frame_count;
   cdc_message_id               = Cdc_Log_Param.cdc_message_id;
   cdc_last_rbin                = (range_idx == (uint16_t)(SPBB_USED_RANGE_BINS - 1)) ? true : false;
   /* Resetting the MSS-DSS Interface buffer */
   if (0U == range_idx)
   {
      /**
       * cdc_radar_frame_reset must be made false at the top before
       * resetting other interface parameters.
       */
      Cdc_Frame_Interface.cdc_radar_frame_reset    = false;
      Cdc_Frame_Interface.cdc_enet_packet_index    = 0U;
      Cdc_Frame_Interface.cdc_enet_frame_end_index = 0U;
      /** cdc_last_avail_cycle_total_frame_cnt holds the total cdc frame count of the last cdc available radar cycle*/
      if (0U < Cdc_Frame_Interface.cdc_enet_packet_tx_cnt)
      {
         Cdc_Frame_Interface.cdc_last_avail_cycle_total_frame_cnt = Cdc_Frame_Interface.cdc_enet_packet_tx_cnt;
      }
      else
      {
         ; /* Nothing */
      }
      /** cdc_prev_cycle_total_frame_cnt holds the total cdc frame count of the previous radar cycle*/
      Cdc_Frame_Interface.cdc_prev_cycle_total_frame_cnt = Cdc_Frame_Interface.cdc_enet_packet_tx_cnt;
      Cdc_Frame_Interface.cdc_enet_packet_tx_cnt         = 0U;
      Cdc_Frame_Interface.cdc_enet_buffer_max_depth      = CDC_NUM_ENET_TX_BUFFERS;
      Cdc_Frame_Interface.cdc_enet_buffer_addr           = (uintptr_t)&Cdc_Enet_Packets;
      Cdc_Frame_Interface.cdc_frame_interface_index++;
      /* Compute the reciprocal of CDC_NUM_RECORDS_PER_FRAME */
      recip_cdc_num_rec_per_frame = (float32_t)CDC_NUM_RECORDS_PER_FRAME;
      RADAR_RECIP(recip_cdc_num_rec_per_frame, Cdc_Log_Param.recip_cdc_num_records_per_frame);
   }
   else
   {
      ; /* Nothing */
   }
   recip_cdc_num_rec_per_frame = Cdc_Log_Param.recip_cdc_num_records_per_frame;
   cdc_enet_packet_tx_cnt      = Cdc_Log_Param.cdc_enet_packet_tx_cnt;
   num_records_remaining       = 0U;
   /* Fill the partially available in ENET Frame */
   if (partial_frame_available)
   {
      if (cdc_records_in_partial_frame <= total_cdc_records_to_be_logged)
      {
         num_records_remaining        = cdc_records_in_partial_frame;
         partial_frame_available      = false;
         cdc_records_in_partial_frame = 0U;
      }
      else
      {
         num_records_remaining = total_cdc_records_to_be_logged;
         cdc_records_in_partial_frame -= num_records_remaining;
      }

      Populate_Cdc_Bv(p_beam_vector_data, p_enet_buffer_base_address, p_cdc_array, &enet_frame_index, range_idx, 0U,
                      num_records_remaining, p_ci_flag_array);

      total_cdc_records_to_be_logged -= num_records_remaining;
      /* Update the Frame Header */
      if ((!partial_frame_available) || (cdc_last_rbin))
      {
         if (cdc_last_rbin)
         {
            vector_clear((p_enet_buffer_base_address + enet_frame_index),
                         ((CDC_NUM_RECORDS_PER_FRAME - enet_frame_index) * CDC_NUM_BYTES_PER_CDC_DATA_RECORD));
         }
         Cdc_Enet_Frame_Update(scan_index, enet_frame_buffer_depth, enet_frame_index);
         cdc_enet_frame_count++;
         cdc_message_id++;
         /* Writing back cache after frame update and before Cdc_Frame_Interface update to MSS*/
         xthal_dcache_block_writeback(((unsigned int *)(&Cdc_Enet_Packets[enet_frame_buffer_depth])), sizeof(CDC_Stream_T));

         /* Update DSS-MSS interface structure. */
         /* Increment the ENET packet-ready-for-tx count  */
         cdc_enet_packet_tx_cnt++;
         Cdc_Frame_Interface.cdc_enet_packet_index  = enet_frame_buffer_depth + 1U;
         Cdc_Frame_Interface.cdc_enet_packet_tx_cnt = cdc_enet_packet_tx_cnt;
      }
   }

   if (0U < total_cdc_records_to_be_logged)
   {
      records_to_be_logged_in_full_frame = (uint16_t)((float32_t)total_cdc_records_to_be_logged * recip_cdc_num_rec_per_frame +
                                                      ROUND_FACTOR); /* total_cdc_records_to_be_logged / CDC_NUM_RECORDS_PER_FRAME
                                                                        and ROUND_FACTOR(0.001F) is added to round-off */
      records_to_be_logged_in_partial_frame =
         total_cdc_records_to_be_logged -
         (records_to_be_logged_in_full_frame *
          CDC_NUM_RECORDS_PER_FRAME); /* total_cdc_records_to_be_logged % CDC_NUM_RECORDS_PER_FRAME */
      records_to_be_logged_in_partial_frame_enable = 0U < records_to_be_logged_in_partial_frame ? true : false;
      loop_count                                   = records_to_be_logged_in_full_frame;
      if (enet_frame_buffer_depth < CDC_NUM_ENET_TX_BUFFERS)
      {
         prev_enet_buffer_depth = enet_frame_buffer_depth + 1U;
      }
      if (CDC_NUM_ENET_TX_BUFFERS == enet_frame_buffer_depth)
      {
         prev_enet_buffer_depth = 0U;
      }
      for (enet_frame_loop_idx = 0U; enet_frame_loop_idx < loop_count; enet_frame_loop_idx++)
      {
         if (enet_frame_buffer_depth < CDC_NUM_ENET_TX_BUFFERS)
         {
            enet_frame_buffer_depth += 1U;
         }
         if (CDC_NUM_ENET_TX_BUFFERS == enet_frame_buffer_depth)
         {
            enet_frame_buffer_depth = 0U;
         }
         enet_frame_index           = 0U;
         p_enet_buffer_base_address = (CDC_Record_T *)(&Cdc_Enet_Packets[enet_frame_buffer_depth].CDC_Data[0]);
         start_idx                  = num_records_remaining + enet_frame_loop_idx * CDC_NUM_RECORDS_PER_FRAME;
         end_idx                    = num_records_remaining + CDC_NUM_RECORDS_PER_FRAME * (enet_frame_loop_idx + 1U);

         /* Perform BV Compression and copy the CDC Record to ENET buffer */
         Populate_Cdc_Bv(p_beam_vector_data, p_enet_buffer_base_address, p_cdc_array, &enet_frame_index, range_idx, start_idx,
                         end_idx, p_ci_flag_array);
      }
      /* Fill the remaining CDC Record in Fully available ENET Frame  */
      if (records_to_be_logged_in_partial_frame_enable)
      {
         cdc_records_in_partial_frame = CDC_NUM_RECORDS_PER_FRAME - records_to_be_logged_in_partial_frame;
         partial_frame_available      = true;
         if (enet_frame_buffer_depth < CDC_NUM_ENET_TX_BUFFERS)
         {
            enet_frame_buffer_depth += 1U;
         }
         if (CDC_NUM_ENET_TX_BUFFERS == enet_frame_buffer_depth)
         {
            enet_frame_buffer_depth = 0U;
         }
         enet_frame_index           = 0U;
         p_enet_buffer_base_address = (CDC_Record_T *)(&Cdc_Enet_Packets[enet_frame_buffer_depth].CDC_Data[0]);
         start_idx                  = num_records_remaining + (records_to_be_logged_in_full_frame * CDC_NUM_RECORDS_PER_FRAME);
         end_idx                    = num_records_remaining + (records_to_be_logged_in_full_frame * CDC_NUM_RECORDS_PER_FRAME) +
                   records_to_be_logged_in_partial_frame;

         Populate_Cdc_Bv(p_beam_vector_data, p_enet_buffer_base_address, p_cdc_array, &enet_frame_index, range_idx, start_idx,
                         end_idx, p_ci_flag_array);

         if (cdc_last_rbin)
         {
            vector_clear((p_enet_buffer_base_address + enet_frame_index),
                         ((CDC_NUM_RECORDS_PER_FRAME - enet_frame_index) * CDC_NUM_BYTES_PER_CDC_DATA_RECORD));
         }
      }

      /* Update the Frame Header */
      loop_count = prev_enet_buffer_depth + records_to_be_logged_in_full_frame + (uint16_t)cdc_last_rbin;
      for (enet_frame_loop_idx = prev_enet_buffer_depth; enet_frame_loop_idx < loop_count; enet_frame_loop_idx++)
      {
         local_frame_buffer_depth = enet_frame_loop_idx % CDC_NUM_ENET_TX_BUFFERS;
         Cdc_Enet_Frame_Update(scan_index, local_frame_buffer_depth, CDC_NUM_RECORDS_PER_FRAME);
         cdc_enet_frame_count++;
         cdc_message_id++;
         /* Writing back cache after frame update and before Cdc_Frame_Interface update to MSS*/
         xthal_dcache_block_writeback(((unsigned int *)(&Cdc_Enet_Packets[local_frame_buffer_depth])), sizeof(CDC_Stream_T));

         /* Update DSS-MSS interface structure. */
         /* Increment the ENET packet-ready-for-tx count  */
         cdc_enet_packet_tx_cnt++;
         Cdc_Frame_Interface.cdc_enet_packet_index  = local_frame_buffer_depth + 1U;
         Cdc_Frame_Interface.cdc_enet_packet_tx_cnt = cdc_enet_packet_tx_cnt;
      }
   }

   /*last CDC frame indicator in current radar cycle as per APTIV Header version 6.4*/
   /*fill the last chunk with dummy CDC buffer with 0 values when atleast one frame available for current radar cycle/look*/
   if (cdc_last_rbin && (1U <= Cdc_Frame_Interface.cdc_enet_packet_tx_cnt))
   {
      if (enet_frame_buffer_depth < CDC_NUM_ENET_TX_BUFFERS)
      {
         enet_frame_buffer_depth += 1U;
      }
      if (CDC_NUM_ENET_TX_BUFFERS == enet_frame_buffer_depth)
      {
         enet_frame_buffer_depth = 0U;
      }
      p_enet_buffer_base_address = (CDC_Record_T *)(&Cdc_Enet_Packets[enet_frame_buffer_depth].CDC_Data[0]);
      /*reset data to 0U value*/
      vector_clear(p_enet_buffer_base_address, (CDC_NUM_RECORDS_PER_FRAME * CDC_NUM_BYTES_PER_CDC_DATA_RECORD));
      Cdc_Enet_Frame_Update(scan_index, enet_frame_buffer_depth, 0U); /* record cnt should be 0U*/
      cdc_enet_frame_count++;
      cdc_message_id++;
      /* Writing back cache after frame update and before Cdc_Enet_Packets update to MSS*/
      xthal_dcache_block_writeback(((unsigned int *)(&Cdc_Enet_Packets[enet_frame_buffer_depth])), sizeof(CDC_Stream_T));

      /* Update DSS-MSS interface structure. */
      /* Increment the ENET packet-ready-for-tx count  */
      cdc_enet_packet_tx_cnt++;
      Cdc_Frame_Interface.cdc_enet_packet_index  = enet_frame_buffer_depth + 1U;
      Cdc_Frame_Interface.cdc_enet_packet_tx_cnt = cdc_enet_packet_tx_cnt;
   }
   Cdc_Log_Param.partial_frame_available      = partial_frame_available;
   Cdc_Log_Param.cdc_records_in_partial_frame = cdc_records_in_partial_frame;
   Cdc_Log_Param.enet_frame_index             = enet_frame_index;
   Cdc_Log_Param.enet_frame_buffer_depth      = enet_frame_buffer_depth;
   Cdc_Log_Param.p_enet_buffer                = p_enet_buffer_base_address;
   Cdc_Log_Param.cdc_enet_frame_count         = cdc_enet_frame_count;
   Cdc_Log_Param.cdc_message_id               = cdc_message_id;
   Cdc_Log_Param.cdc_enet_packet_tx_cnt       = cdc_enet_packet_tx_cnt;

   if (cdc_last_rbin)
   {
      Cdc_Frame_Interface.cdc_radar_frame_reset    = true;
      Cdc_Frame_Interface.cdc_enet_frame_end_index = enet_frame_buffer_depth;

      Cdc_Log_Param.partial_frame_available      = false;
      Cdc_Log_Param.cdc_records_in_partial_frame = 0U;
      Cdc_Log_Param.enet_frame_index             = 0U;
      Cdc_Log_Param.enet_frame_buffer_depth      = CDC_NUM_ENET_TX_BUFFERS;
      Cdc_Log_Param.p_enet_buffer                = NULL;
      Cdc_Log_Param.cdc_message_id               = 0U;
      Cdc_Log_Param.cdc_enet_packet_tx_cnt       = 0U;
   }
   /* Writing back cache after frame update and before Cdc_Frame_Interface update to MSS*/
   xthal_dcache_block_writeback(((unsigned int *)(&Cdc_Frame_Interface)), sizeof(Cdc_Frame_Interface));
}

/**
 *  @b Description
 *  @n
 *    Copy CDC beam vectors to enet buffer.
 *
 * @param[in] p_beam_vector_data Pointer to input beam vectors data
 * @param[in] p_enet_buffer_base_address Pointer enet buffer base
 *
 * @return Returns the number of bytes copied.
 */
static inline void Populate_Cdc_Bv(BV_Comp_Type_T (*p_beam_vector_data)[NUM_RX_CHANNELS][MAX_DOPPLER_FFT_SIZE],
                                   CDC_Record_T *p_enet_buffer_base_address, uint16_t *p_cdc_dbin_array, uint8_t *enet_frame_index,
                                   uint16_t range_idx, uint16_t start_idx, uint16_t end_idx, bool *p_ci_flag_array)
{
   CDC_Record_T *restrict p_enet_buffer;
   uint16_t cdc_rec_loop_idx, doppler_idx;
   uint64_t *p_compress_bv;
   uint16_t amp_data;
   /* Perform BV Compression and copy the CDC Record to ENET buffer */
   for (cdc_rec_loop_idx = start_idx; cdc_rec_loop_idx < end_idx; cdc_rec_loop_idx++)
   {
      p_enet_buffer                        = p_enet_buffer_base_address + *enet_frame_index;
      doppler_idx                          = p_cdc_dbin_array[cdc_rec_loop_idx] & CDC_DBIN_MASK;
      p_enet_buffer->rng_dopp_idx.rng_idx  = range_idx;
      p_enet_buffer->rng_dopp_idx.dopp_idx = p_cdc_dbin_array[cdc_rec_loop_idx];
      p_enet_buffer->rng_dopp_idx.ci_flag  = p_ci_flag_array[cdc_rec_loop_idx];

      /* Based on ci flag, ci_rdop_amp or nci_rdop_amp is assigned to the enet buffer*/
      amp_data = rdop_avg_data_ptr[NCI_CURRENT_BUFFER_DEPTH][doppler_idx];
      XT_MOVT(amp_data, ci_rdop_avg_data_ptr[CI_CURRENT_BUFFER_DEPTH][doppler_idx], p_ci_flag_array[cdc_rec_loop_idx]);
      p_enet_buffer->rng_dopp_idx.nci_data = (uint16_t)amp_data;
      p_compress_bv                        = (uint64_t *)p_enet_buffer->cdc_out_bv;
      /*Populating BV*/
      Extract_Beamvectors(p_compress_bv, p_beam_vector_data, doppler_idx);
      *enet_frame_index += 1U;
   }
}

/* This function updates the CDC ENET Frame */
inline void Cdc_Enet_Frame_Update(uint16_t scan_index, uint16_t enet_frame_buffer_depth, uint16_t records_per_frame)
{
   Dyn_Hdr_T *restrict txbuffer_rec_hdr_ptr;
   CDC_Stream_T *restrict cdc_ent_packer_ptr = &Cdc_Enet_Packets[0];

   txbuffer_rec_hdr_ptr = &(cdc_ent_packer_ptr[enet_frame_buffer_depth].dyn_hdr);

   txbuffer_rec_hdr_ptr->scan_index = scan_index;

#ifdef DSP_CDC_VERIFY
   txbuffer_rec_hdr_ptr->records_cnt = Frame_Cnt++;
   record_cnt_temp                   = records_per_frame; /*Due to build error fix */
#else
   txbuffer_rec_hdr_ptr->records_cnt = records_per_frame;
#endif
}
