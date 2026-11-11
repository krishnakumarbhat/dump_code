/*===========================================================================*/
/**
 * @file cdc_packing_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for the Interface of the cdc_packing.
 *
 * @section ABBR ABBREVIATIONS:
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
#include <gtest/gtest.h>
/*===========================================================================*
 *
 * Macros needed for the Cdc_packing test
 *===========================================================================*/

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include <xtensa/tie/xt_bben.h>

/*===========================================================================*
 * C Header Files
 *===========================================================================*/
extern "C"
{
#include "cdc_packing.c"
}
#include "appl_fp_ifc_fff.h"
#include "rdd_fp_fff.h"

DEFINE_FFF_GLOBALS;

/*===========================================================================*
 * Valid Configuration For Tests
 *===========================================================================*/

uint16_t Cdc_Dbin_Array[MAX_DOPPLER_FFT_SIZE] = {0};
bool Ci_Flag_Array[MAX_DOPPLER_FFT_SIZE]      = {0};
BV_Comp_Type_T (*dfft_bv_output_buffer)[NUM_RX_CHANNELS][MAX_DOPPLER_FFT_SIZE];
volatile uint64_t Dopp_Out_Buf_SRAM[NUM_RX_CHANNELS][MAX_DOPPLER_FFT_SIZE] = {0};
CDC_Record_T enet_buffer_data                                              = {0};
CDC_Record_T *enet_buffer                                                  = &enet_buffer_data;
rdop_avg_t rdop_avg_data[NCI_CIRCULAR_BUFF_DEPTH][MAX_DOPPLER_FFT_SIZE];
rdop_avg_t *rdop_avg_data_ptr[NCI_CIRCULAR_BUFF_DEPTH] = {0};
rdop_avg_t ci_rdop_avg_data[CI_CIRCULAR_BUFF_DEPTH][MAX_DOPPLER_FFT_SIZE];
rdop_avg_t *ci_rdop_avg_data_ptr[CI_CIRCULAR_BUFF_DEPTH] = {0};
Look_Data_T look_data                                    = {0};
/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class CDC_Packing_Unit_Test_Suite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_RESET_HISTORY();
      FFF_FAKES_APPL_FP_IFC_LIST(RESET_FAKE);
      FFF_FAKES_FIRST_PASS_LIST(RESET_FAKE);
      uint16_t k;

      for (k = 0U; k < NCI_CIRCULAR_BUFF_DEPTH; k++)
      {
         rdop_avg_data_ptr[k]    = &rdop_avg_data[k][0];
         ci_rdop_avg_data_ptr[k] = &ci_rdop_avg_data[k][0];
      }
      dfft_bv_output_buffer = (BV_Comp_Type_T(*)[NUM_RX_CHANNELS][MAX_DOPPLER_FFT_SIZE]) & Dopp_Out_Buf_SRAM[0][0];
   }

   /**
    *  @b Description
    *  @n
    *      Method run after each individual test case.
    */
   void TearDown()
   {
   }
};

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

/**
 *  @b Cdc_Packing_Test_01
 *  @n
 *      Validate the API Cdc_Packing.
 */
TEST_F(CDC_Packing_Unit_Test_Suite, Cdc_Packing_Test_01)
{
   uint16_t range_idx                            = RBIN0;
   uint16_t cdc_dbin_count                       = (uint16_t)SPBB_USED_RANGE_BINS;
   Get_Cdc_Dbin_Array_Buffer_Ptr_fake.return_val = &Cdc_Dbin_Array[0];
   Get_Ci_Flag_Array_Buffer_Ptr_fake.return_val  = &Ci_Flag_Array[0];
   Cdc_Frame_Interface.cdc_enet_packet_tx_cnt    = 1U;
   Cdc_Log_Param.partial_frame_available         = 1U;
   Cdc_Log_Param.cdc_records_in_partial_frame    = 1U;
   Cdc_Log_Param.p_enet_buffer                   = &Cdc_Enet_Packets[0].CDC_Data[0];
   Cdc_Packing(&look_data, range_idx, cdc_dbin_count, dfft_bv_output_buffer);
   ASSERT_EQ(Cdc_Frame_Interface.cdc_radar_frame_reset, false);
   ASSERT_EQ(Cdc_Frame_Interface.cdc_enet_buffer_max_depth, CDC_NUM_ENET_TX_BUFFERS);
   ASSERT_EQ(Get_Ci_Flag_Array_Buffer_Ptr_fake.call_count, 1);
   ASSERT_EQ(Get_Cdc_Dbin_Array_Buffer_Ptr_fake.call_count, 1);
}

/**
 *  @b Cdc_Packing_Test_02
 *  @n
 *      Validate the API Cdc_Packing.
 */
TEST_F(CDC_Packing_Unit_Test_Suite, Cdc_Packing_Test_02)
{
   uint16_t range_idx                            = RBIN0;
   uint16_t cdc_dbin_count                       = (uint16_t)SPBB_USED_RANGE_BINS;
   uint32_t cdc_enet_packets_addrs               = (uintptr_t)&Cdc_Enet_Packets;
   Get_Cdc_Dbin_Array_Buffer_Ptr_fake.return_val = &Cdc_Dbin_Array[0];
   Get_Ci_Flag_Array_Buffer_Ptr_fake.return_val  = &Ci_Flag_Array[0];
   Cdc_Frame_Interface.cdc_enet_packet_tx_cnt    = 1U;
   Cdc_Log_Param.partial_frame_available         = 1U;
   Cdc_Log_Param.cdc_records_in_partial_frame    = 1U;
   Cdc_Log_Param.enet_frame_buffer_depth         = 0;
   Cdc_Log_Param.p_enet_buffer                   = &enet_buffer_data;
   Cdc_Packing(&look_data, range_idx, cdc_dbin_count, dfft_bv_output_buffer);
   ASSERT_EQ(Cdc_Frame_Interface.cdc_enet_buffer_addr, cdc_enet_packets_addrs);
   ASSERT_EQ(Cdc_Frame_Interface.cdc_radar_frame_reset, false);
   ASSERT_EQ(Cdc_Frame_Interface.cdc_enet_buffer_max_depth, CDC_NUM_ENET_TX_BUFFERS);
   ASSERT_EQ(Get_Ci_Flag_Array_Buffer_Ptr_fake.call_count, 1);
   ASSERT_EQ(Get_Cdc_Dbin_Array_Buffer_Ptr_fake.call_count, 1);
}

/**
 *  @b Cdc_Packing_Test_03
 *  @n
 *      Validate the API Cdc_Packing.
 */
TEST_F(CDC_Packing_Unit_Test_Suite, Cdc_Packing_Test_03)
{
   uint16_t range_idx                            = RBIN0;
   uint16_t cdc_dbin_count                       = 0U;
   uint32_t cdc_enet_packets_addrs               = (uintptr_t)&Cdc_Enet_Packets;
   Get_Cdc_Dbin_Array_Buffer_Ptr_fake.return_val = &Cdc_Dbin_Array[0];
   Get_Ci_Flag_Array_Buffer_Ptr_fake.return_val  = &Ci_Flag_Array[0];
   Cdc_Frame_Interface.cdc_enet_packet_tx_cnt    = 0U;
   Cdc_Log_Param.partial_frame_available         = 1U;
   Cdc_Log_Param.cdc_records_in_partial_frame    = 1U;
   Cdc_Log_Param.enet_frame_buffer_depth         = 0;
   Cdc_Log_Param.p_enet_buffer                   = &enet_buffer_data;
   Cdc_Packing(&look_data, range_idx, cdc_dbin_count, dfft_bv_output_buffer);
   ASSERT_EQ(Cdc_Frame_Interface.cdc_enet_buffer_addr, cdc_enet_packets_addrs);
   ASSERT_EQ(Cdc_Frame_Interface.cdc_radar_frame_reset, false);
   ASSERT_EQ(Cdc_Frame_Interface.cdc_enet_buffer_max_depth, CDC_NUM_ENET_TX_BUFFERS);
   ASSERT_EQ(Get_Ci_Flag_Array_Buffer_Ptr_fake.call_count, 1);
   ASSERT_EQ(Get_Cdc_Dbin_Array_Buffer_Ptr_fake.call_count, 1);
}

/**
 *  @b Cdc_Packing_Test_04
 *  @n
 *      Validate the API Cdc_Packing.
 */
TEST_F(CDC_Packing_Unit_Test_Suite, Cdc_Packing_Test_04)
{
   uint16_t range_idx                            = SPBB_USED_RANGE_BINS - 1U;
   uint16_t cdc_dbin_count                       = (uint16_t)SPBB_USED_RANGE_BINS;
   Get_Cdc_Dbin_Array_Buffer_Ptr_fake.return_val = &Cdc_Dbin_Array[0];
   Get_Ci_Flag_Array_Buffer_Ptr_fake.return_val  = &Ci_Flag_Array[0];
   Cdc_Frame_Interface.cdc_enet_packet_tx_cnt    = 1U;
   Cdc_Log_Param.recip_cdc_num_records_per_frame = 0.049;
   Cdc_Log_Param.partial_frame_available         = 0U;
   Cdc_Log_Param.cdc_records_in_partial_frame    = cdc_dbin_count + 1U;
   Cdc_Log_Param.enet_frame_buffer_depth         = 0;
   Cdc_Log_Param.p_enet_buffer                   = &enet_buffer_data;
   Cdc_Packing(&look_data, range_idx, cdc_dbin_count, dfft_bv_output_buffer);
   ASSERT_EQ(Cdc_Frame_Interface.cdc_radar_frame_reset, true);
   ASSERT_EQ(Cdc_Frame_Interface.cdc_enet_buffer_max_depth, CDC_NUM_ENET_TX_BUFFERS);
   ASSERT_EQ(Get_Ci_Flag_Array_Buffer_Ptr_fake.call_count, 1);
   ASSERT_EQ(Get_Cdc_Dbin_Array_Buffer_Ptr_fake.call_count, 1);
   ASSERT_EQ(Cdc_Log_Param.partial_frame_available, false);
   ASSERT_EQ(Cdc_Log_Param.cdc_records_in_partial_frame, 0U);
   ASSERT_EQ(Cdc_Log_Param.enet_frame_index, 0U);
   ASSERT_EQ(Cdc_Log_Param.enet_frame_buffer_depth, CDC_NUM_ENET_TX_BUFFERS);
   ASSERT_EQ(Cdc_Log_Param.cdc_message_id, 0U);
   ASSERT_EQ(Cdc_Log_Param.cdc_enet_packet_tx_cnt, 0U);
}

/**
 *  @b Cdc_Packing_Test_05
 *  @n
 *      Validate the API Cdc_Packing.
 */
TEST_F(CDC_Packing_Unit_Test_Suite, Cdc_Packing_Test_05)
{
   uint16_t range_idx                            = SPBB_USED_RANGE_BINS - 1U;
   uint16_t cdc_dbin_count                       = (uint16_t)0U;
   Get_Cdc_Dbin_Array_Buffer_Ptr_fake.return_val = &Cdc_Dbin_Array[0];
   Get_Ci_Flag_Array_Buffer_Ptr_fake.return_val  = &Ci_Flag_Array[0];
   Cdc_Frame_Interface.cdc_enet_packet_tx_cnt    = 1U;
   Cdc_Log_Param.partial_frame_available         = 1U;
   Cdc_Log_Param.cdc_records_in_partial_frame    = cdc_dbin_count + 1U;
   Cdc_Log_Param.enet_frame_buffer_depth         = 0;
   Cdc_Log_Param.p_enet_buffer                   = &enet_buffer_data;
   Cdc_Packing(&look_data, range_idx, cdc_dbin_count, dfft_bv_output_buffer);
   ASSERT_EQ(Cdc_Frame_Interface.cdc_radar_frame_reset, true);
   ASSERT_EQ(Cdc_Frame_Interface.cdc_enet_buffer_max_depth, CDC_NUM_ENET_TX_BUFFERS);
   ASSERT_EQ(Get_Ci_Flag_Array_Buffer_Ptr_fake.call_count, 1);
   ASSERT_EQ(Get_Cdc_Dbin_Array_Buffer_Ptr_fake.call_count, 1);
   ASSERT_EQ(Cdc_Frame_Interface.cdc_radar_frame_reset, true);
   ASSERT_EQ(Cdc_Log_Param.partial_frame_available, false);
   ASSERT_EQ(Cdc_Log_Param.cdc_records_in_partial_frame, 0U);
   ASSERT_EQ(Cdc_Log_Param.enet_frame_index, 0U);
   ASSERT_EQ(Cdc_Log_Param.enet_frame_buffer_depth, CDC_NUM_ENET_TX_BUFFERS);
   ASSERT_EQ(Cdc_Log_Param.cdc_message_id, 0U);
   ASSERT_EQ(Cdc_Log_Param.cdc_enet_packet_tx_cnt, 0U);
}

/**
 *  @b Cdc_Packing_Test_06
 *  @n
 *      Validate the API Cdc_Packing.
 */
TEST_F(CDC_Packing_Unit_Test_Suite, Cdc_Packing_Test_06)
{
   uint16_t range_idx                            = RBIN0;
   uint16_t cdc_dbin_count                       = (uint16_t)2U;
   Get_Cdc_Dbin_Array_Buffer_Ptr_fake.return_val = &Cdc_Dbin_Array[0];
   Get_Ci_Flag_Array_Buffer_Ptr_fake.return_val  = &Ci_Flag_Array[0];
   Cdc_Frame_Interface.cdc_enet_packet_tx_cnt    = 1U;
   Cdc_Log_Param.partial_frame_available         = 1U;
   Cdc_Log_Param.cdc_records_in_partial_frame    = 1U;
   Cdc_Log_Param.p_enet_buffer                   = &Cdc_Enet_Packets[0].CDC_Data[0];
   Cdc_Packing(&look_data, range_idx, cdc_dbin_count, dfft_bv_output_buffer);
   ASSERT_EQ(Cdc_Frame_Interface.cdc_radar_frame_reset, false);
   ASSERT_EQ(Cdc_Frame_Interface.cdc_enet_buffer_max_depth, CDC_NUM_ENET_TX_BUFFERS);
   ASSERT_EQ(Get_Ci_Flag_Array_Buffer_Ptr_fake.call_count, 1);
   ASSERT_EQ(Get_Cdc_Dbin_Array_Buffer_Ptr_fake.call_count, 1);
}

/**
 *  @b Cdc_Packing_Test_07
 *  @n
 *      Validate the API Cdc_Packing.
 */
TEST_F(CDC_Packing_Unit_Test_Suite, Cdc_Packing_Test_07)
{
   uint16_t uint16_max_val                       = 0XFFFF;
   uint16_t range_idx                            = RBIN1;
   uint16_t cdc_dbin_count                       = 21;
   Get_Cdc_Dbin_Array_Buffer_Ptr_fake.return_val = &Cdc_Dbin_Array[0];
   Get_Ci_Flag_Array_Buffer_Ptr_fake.return_val  = &Ci_Flag_Array[0];
   Cdc_Frame_Interface.cdc_enet_packet_tx_cnt    = 1U;
   Cdc_Log_Param.partial_frame_available         = 1U;
   Cdc_Log_Param.cdc_records_in_partial_frame    = 1U;
   Cdc_Log_Param.p_enet_buffer                   = &Cdc_Enet_Packets[0].CDC_Data[0];
   Cdc_Log_Param.recip_cdc_num_records_per_frame = 1.0 / 20.0;
   Cdc_Packing(&look_data, range_idx, cdc_dbin_count, dfft_bv_output_buffer);
   ASSERT_EQ(Cdc_Frame_Interface.cdc_radar_frame_reset, false);
   ASSERT_EQ(Cdc_Frame_Interface.cdc_enet_buffer_max_depth, CDC_NUM_ENET_TX_BUFFERS);
   ASSERT_EQ(Get_Cdc_Dbin_Array_Buffer_Ptr_fake.call_count, 1);
   ASSERT_EQ(Get_Ci_Flag_Array_Buffer_Ptr_fake.call_count, 1);
}

/**
 *  @b Populate_Bv_Test
 *  @n
 *      Validate the API Cdc_Enet_Frame_Update.
 */
TEST_F(CDC_Packing_Unit_Test_Suite, Populate_Bv_Test)
{
   uint16_t range_idx                       = RBIN0;
   uint16_t start_idx                       = 0U;
   uint16_t end_idx                         = 1U;
   uint8_t enet_frame_index                 = 0U;
   CDC_Record_T *p_enet_buffer_base_address = &Cdc_Enet_Packets[0].CDC_Data[0];
   Populate_Cdc_Bv(dfft_bv_output_buffer, p_enet_buffer_base_address, &Cdc_Dbin_Array[0], &enet_frame_index, range_idx, start_idx,
                   end_idx, &Ci_Flag_Array[0]);
   ASSERT_EQ(Extract_Beamvectors_fake.call_count, 1);
   ASSERT_EQ(enet_frame_index, 1);
}

/**
 *  @b Cdc_Enet_Frame_Update_Test
 *  @n
 *      Validate the API Cdc_Enet_Frame_Update.
 */
TEST_F(CDC_Packing_Unit_Test_Suite, Cdc_Enet_Frame_Update_Test)
{
   uint8_t enet_frame_index         = 0U;
   uint16_t enet_frame_buffer_depth = CDC_NUM_ENET_TX_BUFFERS - 1;
   Cdc_Enet_Frame_Update(look_data.scan_index, enet_frame_buffer_depth, enet_frame_index);
   ASSERT_EQ(Cdc_Enet_Packets[enet_frame_buffer_depth].dyn_hdr.scan_index, RADAR_LOOK_A);
   ASSERT_EQ(Cdc_Enet_Packets[enet_frame_buffer_depth].dyn_hdr.records_cnt, enet_frame_index);
}
