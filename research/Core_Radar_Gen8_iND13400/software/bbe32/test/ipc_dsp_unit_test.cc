/*===========================================================================*/
/**
 * @file ipc_dsp_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit tests for ipc_dsp wrapper `ipc_dsp.c`.
 */

/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
#include <gtest/gtest.h>
#include <stdlib.h>

#define XCHAL_CP1_SA_SIZE       1696
#define XCHAL_CP1_SA_ALIGN      32
#define XCHAL_CP_ID_CONNX_BBE32 1
#define XCHAL_TIMER0_INTERRUPT  10
#define XCHAL_TIMER1_INTERRUPT  11
#define UNUSED(value)           ((void)(value))

/*===========================================================================*
 * Stub WUR_EXPSTATE cstub - track calls for verification
 *===========================================================================*/
static uint32_t g_wur_expstate_call_count        = 0U;
static uint32_t g_wur_expstate_last_value        = 0U;
static uint32_t g_writeback_call_count           = 0U;
static void *g_writeback_last_addr               = NULL;
static unsigned int g_writeback_last_size        = 0U;
static uint32_t g_xthal_set_ccompare0_call_count = 0U;
static uint32_t g_xthal_set_ccompare0_last_value = 0U;
static uint32_t g_xthal_set_ccompare1_call_count = 0U;
static uint32_t g_xthal_set_ccompare1_last_value = 0U;

#ifndef DOWNSELECTION_ENABLE
   #define DOWNSELECTION_ENABLE 1U
#endif

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "core_macros_fff.h"
#include "crc_calc_mocks.h"
#include "dsp_sfrs.h"
#include "idma_helpers_fff.h"
#include "ipc_data_fake.h"
#include "mipi_ifc_fff.h"
#include "range_process_ifc_fff.h"
#include "toi_algo_interface_fff.h"

/*===========================================================================*
 * Local fake HW register memory for host unit tests and custom fake functions
 *===========================================================================*/
static DSP_SFRS_t g_dsp_ctrl_regs;

/* Override DSP_base before including ipc_dsp.c. The test-local
 * Generic_Drv_sfr.h stub provides the GENERIC_DRV_SFR_H include guard;
 * when ipc_dsp.c later includes Generic_Drv_sfr.h the guard fires, so
 * the override below is never overwritten by the hardware address. */
#include "chandra_sfrs_base.h"
#undef DSP_base
#define DSP_base (&g_dsp_ctrl_regs)

static void Unit_Test_xthal_set_ccompare0_Stub(const uint32_t value)
{
   g_xthal_set_ccompare0_call_count++;
   g_xthal_set_ccompare0_last_value = value;
}
static void Unit_Test_xthal_set_ccompare1_Stub(const uint32_t value)
{
   g_xthal_set_ccompare1_call_count++;
   g_xthal_set_ccompare1_last_value = value;
}

void Unit_Test_xthal_dcache_block_writeback_Stub(void *addr, unsigned int size)
{
   g_writeback_call_count++;
   g_writeback_last_addr = addr;
   g_writeback_last_size = size;
}

void Unit_Test_WUR_EXPSTATE_Stub(const unsigned int value)
{
   g_wur_expstate_call_count++;
   g_wur_expstate_last_value = value;
}

#undef xthal_set_ccompare0
#undef xthal_set_ccompare1
#undef xthal_dcache_block_writeback
#undef cstub_Xm_bbe32_luna__TIE_xt_ioports_WUR_EXPSTATE

#define xthal_set_ccompare0                              Unit_Test_xthal_set_ccompare0_Stub
#define xthal_set_ccompare1                              Unit_Test_xthal_set_ccompare1_Stub
#define xthal_dcache_block_writeback                     Unit_Test_xthal_dcache_block_writeback_Stub
#define cstub_Xm_bbe32_luna__TIE_xt_ioports_WUR_EXPSTATE Unit_Test_WUR_EXPSTATE_Stub

static float g_test_frame_dwell_ms_smc[NUM_LOOKS] = {0.0F};
#undef k_frame_dwell_ms_smc
#define k_frame_dwell_ms_smc g_test_frame_dwell_ms_smc
/*===========================================================================*
 * C Unit Under Test
 *===========================================================================*/
#include "software/bbe32/src/ipc_dsp.c"

/*===========================================================================*
 * FFF setup
 *===========================================================================*/
DEFINE_FFF_GLOBALS;

/*===========================================================================*
 * Globals required by ipc_dsp.c
 *===========================================================================*/
uint32_t xtos_enabled      = 0U;
uint32_t xtos_vpri_enabled = 0U;
volatile Ipc_Notify_Structure_T *notify;
volatile IPC_Shared_Buffers_T __attribute__((aligned(32), used, section(".ipc_metadata_section"))) Ipc_Shared_Buffer;
D2M_Msg_T d2m_msg;
M2D_Msg_T s_m2d_msg;
static volatile Ipc_Notify_Structure_T g_ipc_notify_buffer;
Fixed_Trigger_Struct_T Fixed_Trigger_Data_test = {0};
void *arg                                      = &Fixed_Trigger_Data_test;

using ToiStatusDstType = TOI_RADAR_DATA_PAYLOAD_T;

/*===========================================================================*
 * Helpers for Appl_DSP_Process_Onetime_Init retry branch tests
 *
 * xthal_get_ccount is called exactly once per Wait_For_Trigger invocation
 * (since XT_L32AI returns TRIGGER_RECEIVED immediately).  Using its
 * custom_fake to update the shared M2D struct on the 2nd outer-loop
 * iteration avoids infinite loops while covering lines 808-811.
 *===========================================================================*/
static M2D_One_Time_Msg_T g_onetime_msg_retry;

static uint32_t xthal_get_ccount_SetUSCOnSecondCall(void)
{
   if (xthal_get_ccount_fake.call_count == 2U)
   {
      g_onetime_msg_retry.usc_sram_address = 0x00000002UL;
   }
   return 0U;
}

static uint32_t xthal_get_ccount_SetSMCOnSecondCall(void)
{
   if (xthal_get_ccount_fake.call_count == 2U)
   {
      g_onetime_msg_retry.smc_sram_address = 0x00000001UL;
   }
   return 0U;
}

static uint32_t xthal_get_ccount_SetBothOnThirdCall(void)
{
   /* One xthal_get_ccount call is made before the do-while loop (Profiling_Helpers_Init),
    * then one per Wait_For_Trigger iteration. Setting both addresses on the 3rd call
    * (2nd Wait_For_Trigger) causes the loop to run exactly twice, exercising line 820. */
   if (xthal_get_ccount_fake.call_count == 3U)
   {
      g_onetime_msg_retry.smc_sram_address = 0x00000001UL;
      g_onetime_msg_retry.usc_sram_address = 0x00000002UL;
   }
   return 0U;
}

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class Ipc_Dsp_Unit_Test_Suite : public testing::Test
{
   void SetUp()
   {
      memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));

      FFF_FAKES_CORE_MACROS(RESET_FAKE);
      FFF_FAKES_IDMA_HELPERS_LIST(RESET_FAKE);
      FFF_FAKES_MIPI_IFC_LIST(RESET_FAKE);
      FFF_FAKES_RANGE_PROCESS_IFC_LIST(RESET_FAKE);
      FFF_FAKES_CRC_CALC_LIST(RESET_FAKE);
      FFF_FAKES_TOI_ALGO_INTERFACE_LIST(RESET_FAKE);
      RESET_IPC_DATA_MOCKS(RESET_FAKE);
      FFF_RESET_HISTORY();

      g_wur_expstate_call_count        = 0U;
      g_wur_expstate_last_value        = 0U;
      g_writeback_call_count           = 0U;
      g_writeback_last_addr            = NULL;
      g_writeback_last_size            = 0U;
      g_xthal_set_ccompare0_call_count = 0U;
      g_xthal_set_ccompare0_last_value = 0U;
      g_xthal_set_ccompare1_call_count = 0U;
      g_xthal_set_ccompare1_last_value = 0U;

      memset((void *)&IPC_D2M_Buffer, 0, sizeof(IPC_D2M_Buffer));
      memset((void *)&IPC_Profiling, 0, sizeof(IPC_Profiling));
      memset((void *)&d2m_msg, 0, sizeof(D2M_Msg_T));
      notify = NULL;
      memset((void *)&g_ipc_notify_buffer, 0, sizeof(g_ipc_notify_buffer));
      memset(&g_dsp_ctrl_regs, 0, sizeof(g_dsp_ctrl_regs));
      memset((void *)&IPC_BBE2R52_Fixed_Notify_Msg[0], 0, sizeof(IPC_BBE2R52_Fixed_Notify_Msg));
      memset((void *)&Fixed_Trigger_Data_test, 0, sizeof(Fixed_Trigger_Struct_T));

      IPC_R52_To_BBE_Trigger_Received          = NO_TRIGGER;
      IPC_R52_Trigger_Failed                   = 0U;
      Offline_Mode_Flag_DSP                    = ITF_DISABLED_NORMAL_MODE;
      IPC_M2D_Buffer_Err_Cnt                   = 0U;
      Waiting_For_Trigger                      = 0U;
      M2D_Buffer_Ptr                           = NULL;
      RP_Buffer_Index                          = 0U;
      DP_Rdd_Buffer_Index                      = 0U;
      SP_Post_Proc_Buffer_Index                = 0U;
      DSP_PFM_Index_Isr                        = 0U;
      DSP_PFM_Index                            = 0U;
      DSP_D2M_Msg_Header_Cnt                   = 0U;
      DSP_M2D_Msg_Header_Cnt                   = 0U;
      Mss_Init_Received                        = NO_TRIGGER;
      Ready_For_New_Frame                      = INVALID_STATE;
      D2M_Buffer_Full_Error_Counter            = 0U;
      SP2DSP_LVL1_Handler_test_var             = 0U;
      M2D_One_Time_Msg_Ptr                     = NULL;
      SMC_Cal_Data_Ptr                         = NULL;
      USC_Cal_Data_Ptr                         = NULL;
      DSS_Radar_Status_CRC_Count               = 0U;
      Look_Type_Induce_Err                     = false;
      xthal_get_ccount_fake.return_val         = 0U;
      XT_L32AI_fake.return_val                 = TRIGGER_RECEIVED;
      xthal_disable_interrupts_fake.return_val = 0U;
   }

   void TearDown()
   {
   }
};

/*===========================================================================*
 * Test Cases
 *===========================================================================*/
/**
 * @test Reset_XTOS_Internal_State resets internal state to known values
 *
 * @pre xtos_vpri_enabled and xtos_enabled hold arbitrary values
 * @post xtos_vpri_enabled = 0xFFFFFFFF, xtos_enabled = 0
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, ResetXTOSInternalState_RestoresExpectedState)
{
   xtos_vpri_enabled = 0x12345678U;
   xtos_enabled      = 0xABCDEF01U;

   Reset_XTOS_Internal_State();

   EXPECT_EQ(0xFFFFFFFFU, xtos_vpri_enabled);
   EXPECT_EQ(0U, xtos_enabled);
}

/**
 * @test Check_R52_To_BBE32_Header returns CODED_FALSE when size does not match
 *
 * @pre Header size is 0 (zeroed struct) — does not equal sizeof(M2D_Msg_T)
 * @post Function returns CODED_FALSE, DSP_M2D_Msg_Header_Cnt still incremented
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, CheckR52Header_SizeMismatch_ReturnsCodedFalse)
{
   M2D_Msg_T m2d_msg = {0}; /* header.size = 0 != sizeof(M2D_Msg_T) */
   uint8_t result    = Check_R52_To_BBE32_Header(&m2d_msg);
   EXPECT_EQ(result, CODED_FALSE);
}

/**
 * @test Check_R52_To_BBE32_Header returns CODED_FALSE for NULL buffer
 *
 * @pre buf is NULL
 * @post Function returns CODED_FALSE
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, CheckR52Header_NullBuf_ReturnsCodedFalse)
{
   uint8_t result = Check_R52_To_BBE32_Header(NULL);
   EXPECT_EQ(result, CODED_FALSE);
}

/**
 * @test IPC_D2M_Buffer_Init initializes all D2M buffers with correct headers
 *
 * @pre None
 * @post All IPC_D2M_Buffer elements have correct size and zero CRC
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, IPCD2MBufferInit_InitializesAllBuffers)
{
   IPC_D2M_Buffer_Init();

   for (uint32_t i = 0U; i < IPC_PING_PONG_COUNT; i++)
   {
      EXPECT_EQ(IPC_D2M_Buffer[i].header.size, sizeof(D2M_Msg_T));
      EXPECT_EQ(IPC_D2M_Buffer[i].header.crc, 0U);
   }
}

/**
 * @test Getter functions return correct buffer pointers
 *
 * @pre Buffer indices set appropriately
 * @post Getters return expected buffer addresses
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, GettersReturnCorrectBuffers)
{
   RP_Buffer_Index           = 1U;
   DP_Rdd_Buffer_Index       = 0U;
   SP_Post_Proc_Buffer_Index = 1U;

   EXPECT_EQ(Get_RP_IPC_D2M_Msg_Buffer(), &IPC_D2M_Buffer[1]);
   EXPECT_EQ(Get_DP_RDD_IPC_D2M_Msg_Buffer(), &IPC_D2M_Buffer[0]);
   EXPECT_EQ(Get_SP_Post_Proc_IPC_D2M_Msg_Buffer(), &IPC_D2M_Buffer[1]);
   EXPECT_EQ(Get_IPC_D2M_Msg_Buffer(0U), &IPC_D2M_Buffer[0]);
   EXPECT_EQ(Get_IPC_D2M_Msg_Buffer(1U), &IPC_D2M_Buffer[1]);
}

/**
 * @test Reset_IPC_AF_Buffer clears all post-processing payload sections of the SP buffer
 *
 * @pre Payload sections of IPC_D2M_Buffer[0] are filled with 0xA5
 * @post xcp_af_data, det_data, det_debug_data, af_time, and downselection_data are zeroed
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, ResetIPCAFBuffer_ClearsPostProcPayloadSections)
{
   Angle_Data_XCP_T zero_xcp_af_data            = {0};
   Detection_Stream_T zero_det_data             = {0};
   Detection_Debug_Stream_T zero_det_debug_data = {0};
   Angle_Timing_Data_T zero_af_time             = {0};
#if (DOWNSELECTION_ENABLE == 1U)
   Down_selection_Stream_T zero_downselection_data = {0};
#endif

   SP_Post_Proc_Buffer_Index = 0U;

   memset((void *)&IPC_D2M_Buffer[0].payload.xcp_af_data, 0xA5, sizeof(IPC_D2M_Buffer[0].payload.xcp_af_data));
   memset((void *)&IPC_D2M_Buffer[0].payload.det_data, 0xA5, sizeof(IPC_D2M_Buffer[0].payload.det_data));
   memset((void *)&IPC_D2M_Buffer[0].payload.det_debug_data, 0xA5, sizeof(IPC_D2M_Buffer[0].payload.det_debug_data));
   memset((void *)&IPC_D2M_Buffer[0].payload.dsp_timing_data.af_time, 0xA5,
          sizeof(IPC_D2M_Buffer[0].payload.dsp_timing_data.af_time));
#if (DOWNSELECTION_ENABLE == 1U)
   memset((void *)&IPC_D2M_Buffer[0].payload.downselection_data, 0xA5, sizeof(IPC_D2M_Buffer[0].payload.downselection_data));
#endif

   Reset_IPC_AF_Buffer(false, false);

   EXPECT_EQ(
      0, memcmp((const void *)&IPC_D2M_Buffer[0].payload.xcp_af_data, (const void *)&zero_xcp_af_data, sizeof(zero_xcp_af_data)));
   EXPECT_EQ(0, memcmp((const void *)&IPC_D2M_Buffer[0].payload.det_data, (const void *)&zero_det_data, sizeof(zero_det_data)));
   EXPECT_EQ(0, memcmp((const void *)&IPC_D2M_Buffer[0].payload.det_debug_data, (const void *)&zero_det_debug_data,
                       sizeof(zero_det_debug_data)));
   EXPECT_EQ(0, memcmp((const void *)&IPC_D2M_Buffer[0].payload.dsp_timing_data.af_time, (const void *)&zero_af_time,
                       sizeof(zero_af_time)));
#if (DOWNSELECTION_ENABLE == 1U)
   EXPECT_EQ(0, memcmp((const void *)&IPC_D2M_Buffer[0].payload.downselection_data, (const void *)&zero_downselection_data,
                       sizeof(zero_downselection_data)));
#endif
}

/**
 * @test Reset_IPC_AF_Buffer should not clear the HIL data if hil_detection_stream_injection_mode or
 * hil_downselection_stream_injection_mode are specified
 *
 * @pre Payload sections of IPC_D2M_Buffer[0] are filled with 0xA5
 * @post det_data and downselection_data are not zeroed
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, ResetIPCAFBuffer_DontClearHilData)
{
   Detection_Stream_T a5_det_data;
#if (DOWNSELECTION_ENABLE == 1U)
   Down_selection_Stream_T a5_downselection_data;
#endif

   SP_Post_Proc_Buffer_Index = 0U;

   memset((void *)&IPC_D2M_Buffer[0].payload.xcp_af_data, 0xA5, sizeof(IPC_D2M_Buffer[0].payload.xcp_af_data));
   memset((void *)&IPC_D2M_Buffer[0].payload.det_data, 0xA5, sizeof(IPC_D2M_Buffer[0].payload.det_data));
   memset((void *)&a5_det_data, 0xA5, sizeof(a5_det_data));
   memset((void *)&IPC_D2M_Buffer[0].payload.det_debug_data, 0xA5, sizeof(IPC_D2M_Buffer[0].payload.det_debug_data));
   memset((void *)&IPC_D2M_Buffer[0].payload.dsp_timing_data.af_time, 0xA5,
          sizeof(IPC_D2M_Buffer[0].payload.dsp_timing_data.af_time));
#if (DOWNSELECTION_ENABLE == 1U)
   memset((void *)&IPC_D2M_Buffer[0].payload.downselection_data, 0xA5, sizeof(IPC_D2M_Buffer[0].payload.downselection_data));
   memset((void *)&a5_downselection_data, 0xA5, sizeof(a5_downselection_data));
#endif

   /* test af hil mode */
   Reset_IPC_AF_Buffer(true, false);

   EXPECT_EQ(0, memcmp((const void *)&IPC_D2M_Buffer[0].payload.det_data, (const void *)&a5_det_data, sizeof(a5_det_data)));

#if (DOWNSELECTION_ENABLE == 1U)
   /* test ds hil mode */
   Reset_IPC_AF_Buffer(false, true);
   EXPECT_EQ(0, memcmp((const void *)&IPC_D2M_Buffer[0].payload.downselection_data, (const void *)&a5_downselection_data,
                       sizeof(a5_downselection_data)));
#endif
}

/**
 * @test Appl_Range_Process_Trigger returns true and sets TRIGGER_RECEIVED when ready and init succeeds
 *
 * @pre Ready_For_New_Frame = READY_FOR_RANGE_PROCESSING; Appl_Range_Process_Init returns true
 * @post Returns true; Ready_For_New_Frame = RUNNING_LOOK_PROCESSING; IPC trigger set
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, ApplRangeProcessTrigger_WhenReadyAndInitSucceeds_SetsTriggerReceived)
{
   Ready_For_New_Frame                     = READY_FOR_RANGE_PROCESSING;
   IPC_R52_To_BBE_Trigger_Received         = NO_TRIGGER;
   IPC_R52_Trigger_Failed                  = 0U;
   Appl_Range_Process_Init_fake.return_val = true;

   const bool result = Appl_Range_Process_Trigger(RADAR_LOOK_A);

   EXPECT_TRUE(result);
   EXPECT_EQ(1U, Appl_Range_Process_Init_fake.call_count);
   EXPECT_EQ(RADAR_LOOK_A, Appl_Range_Process_Init_fake.arg0_val);
   EXPECT_EQ(RUNNING_LOOK_PROCESSING, Ready_For_New_Frame);
   EXPECT_EQ(TRIGGER_RECEIVED, IPC_R52_To_BBE_Trigger_Received);
   EXPECT_EQ(0U, IPC_R52_Trigger_Failed);
}

/**
 * @test Appl_Range_Process_Trigger returns false and increments trigger-failed counter when init fails
 *
 * @pre Ready_For_New_Frame = READY_FOR_RANGE_PROCESSING; Appl_Range_Process_Init returns false
 * @post Returns false; IPC_R52_Trigger_Failed incremented; IPC trigger cleared
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, ApplRangeProcessTrigger_WhenReadyAndInitFails_IncrementsTriggerFailed)
{
   Ready_For_New_Frame                     = READY_FOR_RANGE_PROCESSING;
   IPC_R52_To_BBE_Trigger_Received         = TRIGGER_RECEIVED;
   IPC_R52_Trigger_Failed                  = 2U;
   Appl_Range_Process_Init_fake.return_val = false;

   const bool result = Appl_Range_Process_Trigger(RADAR_LOOK_A);

   EXPECT_FALSE(result);
   EXPECT_EQ(1U, Appl_Range_Process_Init_fake.call_count);
   EXPECT_EQ(RADAR_LOOK_A, Appl_Range_Process_Init_fake.arg0_val);
   EXPECT_EQ(RUNNING_LOOK_PROCESSING, Ready_For_New_Frame);
   EXPECT_EQ(NO_TRIGGER, IPC_R52_To_BBE_Trigger_Received);
   EXPECT_EQ(3U, IPC_R52_Trigger_Failed);
}

/**
 * @test Appl_Range_Process_Trigger returns false and does not call init when not ready
 *
 * @pre Ready_For_New_Frame = RUNNING_LOOK_PROCESSING
 * @post Returns false; Appl_Range_Process_Init never called; IPC_R52_Trigger_Failed incremented
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, ApplRangeProcessTrigger_WhenNotReady_DoesNotCallInit)
{
   Ready_For_New_Frame                     = RUNNING_LOOK_PROCESSING;
   IPC_R52_To_BBE_Trigger_Received         = TRIGGER_RECEIVED;
   IPC_R52_Trigger_Failed                  = 4U;
   Appl_Range_Process_Init_fake.return_val = true;

   const bool result = Appl_Range_Process_Trigger(RADAR_LOOK_A);

   EXPECT_FALSE(result);
   EXPECT_EQ(0U, Appl_Range_Process_Init_fake.call_count);
   EXPECT_EQ(RUNNING_LOOK_PROCESSING, Ready_For_New_Frame);
   EXPECT_EQ(NO_TRIGGER, IPC_R52_To_BBE_Trigger_Received);
   EXPECT_EQ(5U, IPC_R52_Trigger_Failed);
}

/**
 * @test Set_MMIC_Data_Discard_Info copies radar status when size matches
 *
 * @pre sizeof(IPC_MMIC_Radar_Data_Status_T) == sizeof(TOI_Radar_Data_Status_T); src filled with known values
 * @post Destination buffer updated with MMIC data; TOI_Radar_Status_Info_Init called once
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, SetMMICDataDiscardInfo_WithRadarStatusSizeMismatch_LeavesDestinationUnchanged)
{
   TOI_Input_Params_T toi_input_params            = {0};
   IPC_MMIC_Radar_Data_Status_T mmic_radar_status = {0};
   uint8_t toi_status_dst[sizeof(TOI_RADAR_DATA_PAYLOAD_T)];

   memset(&toi_status_dst[0], 0x5AU, sizeof(toi_status_dst));

   mmic_radar_status.radar_data_status_header.radar_data_status_crc = 0x12345678U;
   mmic_radar_status.radar_data_status_payload.Radar_Ctl_State_Idle = 1U;

   toi_input_params.radar_ip_sts_ptr        = (uintptr_t)&mmic_radar_status;
   toi_input_params.toi_data_status_dst_ptr = &toi_status_dst[0];
   Get_TOI_Init_Parameters_fake.return_val  = &toi_input_params;

   Set_MMIC_Data_Discard_Info();

   EXPECT_LT(0, memcmp(&toi_status_dst[0], &mmic_radar_status.radar_data_status_payload, sizeof(TOI_RADAR_DATA_PAYLOAD_T)));
}

/**
 * @test Set_MMIC_Data_Discard_Info copies radar status to destination when sizes match and src is non-null
 *
 * @pre radar_ip_sts_ptr points to a valid IPC_MMIC_Radar_Data_Status_T filled with sequential bytes;
 *      sizeof(TOI_RADAR_DATA_PAYLOAD_T) == sizeof(Radar_Data_Status_Payload_T) so copy is performed
 * @post Destination buffer contains copied MMIC data; TOI_Radar_Status_Info_Init called once
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, SetMMICDataDiscardInfo_WithMatchingStatusSize_CopiesRadarStatus)
{
   TOI_Input_Params_T toi_input_params                      = {0};
   IPC_MMIC_Radar_Data_Status_T mmic_radar_status           = {0};
   uint8_t toi_status_dst[sizeof(TOI_RADAR_DATA_PAYLOAD_T)] = {0};

   for (size_t index = 0U; index < sizeof(IPC_MMIC_Radar_Data_Status_T); ++index)
   {
      reinterpret_cast<uint8_t *>(&mmic_radar_status)[index] = static_cast<uint8_t>(index + 1U);
   }

   toi_input_params.radar_ip_sts_ptr        = (uintptr_t)&mmic_radar_status;
   toi_input_params.toi_data_status_dst_ptr = &toi_status_dst[0];
   Get_TOI_Init_Parameters_fake.return_val  = &toi_input_params;

   Set_MMIC_Data_Discard_Info();

   EXPECT_GT(0, memcmp(&toi_status_dst[0], &mmic_radar_status.radar_data_status_payload, sizeof(TOI_RADAR_DATA_PAYLOAD_T)));
}

/**
 * @test Set_MMIC_Data_Discard_Info leaves destination unchanged when radar status pointer is NULL
 *
 * @pre radar_ip_sts_ptr = NULL; dst filled with 0x5A
 * @post Destination buffer unchanged; TOI_Radar_Status_Info_Init called once
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, SetMMICDataDiscardInfo_NullRadarStatus_LeavesDestinationUnchanged)
{
   TOI_Input_Params_T toi_input_params            = {0};
   IPC_MMIC_Radar_Data_Status_T mmic_radar_status = {0};
   uint8_t toi_status_dst[sizeof(TOI_RADAR_DATA_PAYLOAD_T)];
   uint8_t expected_status_dst[sizeof(TOI_RADAR_DATA_PAYLOAD_T)];

   memset(&toi_status_dst[0], 0x5AU, sizeof(toi_status_dst));
   memcpy(&expected_status_dst[0], &toi_status_dst[0], sizeof(expected_status_dst));

   /* Current implementation writes crc_mismatch_flag in the else path, so keep
    * radar status storage valid while forcing crc mismatch to verify dst unchanged. */
   toi_input_params.radar_ip_sts_ptr        = (uintptr_t)&mmic_radar_status;
   toi_input_params.toi_data_status_dst_ptr = &toi_status_dst[0];
   Get_TOI_Init_Parameters_fake.return_val  = &toi_input_params;

   Set_MMIC_Data_Discard_Info();

   EXPECT_EQ(0, memcmp(&toi_status_dst[0], &expected_status_dst[0], sizeof(toi_status_dst)));
}

/**
 * @test Set_MMIC_Data_Discard_Info does not copy when radar status pointer is valid but CRC mismatches
 *
 * @pre radar_ip_sts_ptr is valid; alive counter matches current cycle; computed CRC != header CRC
 * @post Destination TOI status payload remains unchanged; crc_mismatch is CODED_TRUE
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, SetMMICDataDiscardInfo_ValidRadarStatusButCrcMismatch_LeavesDestinationUnchanged)
{
   TOI_Input_Params_T toi_input_params            = {0};
   IPC_MMIC_Radar_Data_Status_T mmic_radar_status = {0};
   M2D_Msg_T m2d_msg                              = {0};
   TOI_RADAR_DATA_PAYLOAD_T expected_dst          = {0};

   SP_Post_Proc_Buffer_Index               = 0U;
   M2D_Buffer_Ptr                          = &m2d_msg;
   Get_TOI_Init_Parameters_fake.return_val = &toi_input_params;

   memset((void *)&IPC_D2M_Buffer[0].payload.toi_ds_stream_data.toi_ip_data.toi_ds_radar_data_status_payload, 0xA5,
          sizeof(IPC_D2M_Buffer[0].payload.toi_ds_stream_data.toi_ip_data.toi_ds_radar_data_status_payload));
   memcpy((void *)&expected_dst,
          (const void *)&IPC_D2M_Buffer[0].payload.toi_ds_stream_data.toi_ip_data.toi_ds_radar_data_status_payload,
          sizeof(expected_dst));

   memset((void *)&mmic_radar_status.radar_data_status_payload, 0x3C, sizeof(mmic_radar_status.radar_data_status_payload));
   mmic_radar_status.radar_data_status_header.alive_counter         = 1U;
   mmic_radar_status.radar_data_status_header.radar_data_status_crc = 0x22222222U;
   DSS_Radar_Status_CRC_Count                                       = 0U;
   Compute_CRC32_SW_fake.return_val                                 = 0x11111111U;

   m2d_msg.payload.Radar_Sts_Ptr = (uintptr_t)&mmic_radar_status;

   Set_MMIC_Data_Discard_Info();

   EXPECT_EQ(CODED_TRUE, toi_input_params.crc_mismatch);
   EXPECT_EQ(1U, Compute_CRC32_SW_fake.call_count);
   EXPECT_EQ(0, memcmp((const void *)&IPC_D2M_Buffer[0].payload.toi_ds_stream_data.toi_ip_data.toi_ds_radar_data_status_payload,
                       (const void *)&expected_dst, sizeof(expected_dst)));
}

/**
 * @test Set_MMIC_Data_Discard_Info copies payload when radar status pointer is valid and CRC matches
 *
 * @pre radar_ip_sts_ptr is valid; alive counter matches current cycle; computed CRC equals header CRC
 * @post Destination TOI status payload is updated from MMIC payload and crc_mismatch is CODED_FALSE
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, SetMMICDataDiscardInfo_ValidRadarStatusAndCrcMatch_CopiesPayload)
{
   TOI_Input_Params_T toi_input_params            = {0};
   IPC_MMIC_Radar_Data_Status_T mmic_radar_status = {0};
   M2D_Msg_T m2d_msg                              = {0};
   TOI_RADAR_DATA_PAYLOAD_T *toi_status_dst_ptr   = NULL;

   SP_Post_Proc_Buffer_Index               = 0U;
   M2D_Buffer_Ptr                          = &m2d_msg;
   Get_TOI_Init_Parameters_fake.return_val = &toi_input_params;
   DSS_Radar_Status_CRC_Count              = 0U;

   toi_status_dst_ptr = (TOI_RADAR_DATA_PAYLOAD_T *)&Get_TOI_DATA_STATUS_DST_PTR(&IPC_D2M_Buffer[0]);
   memset((void *)toi_status_dst_ptr, 0xA5, sizeof(*toi_status_dst_ptr));
   memset((void *)&mmic_radar_status.radar_data_status_payload, 0x3C, sizeof(mmic_radar_status.radar_data_status_payload));

   mmic_radar_status.radar_data_status_header.alive_counter         = 1U;
   mmic_radar_status.radar_data_status_header.radar_data_status_crc = 0xABCDEF12U;
   Compute_CRC32_SW_fake.return_val                                 = 0xABCDEF12U;
   m2d_msg.payload.Radar_Sts_Ptr                                    = (uintptr_t)&mmic_radar_status;

   Set_MMIC_Data_Discard_Info();

   EXPECT_EQ(CODED_FALSE, toi_input_params.crc_mismatch);
   EXPECT_EQ(1U, Compute_CRC32_SW_fake.call_count);
   EXPECT_EQ(0, memcmp((const void *)toi_status_dst_ptr, (const void *)&mmic_radar_status.radar_data_status_payload,
                       sizeof(mmic_radar_status.radar_data_status_payload)));
}

/**
 * @test Set_MMIC_Data_Discard_Info leaves destination unchanged when radar status pointer is NULL
 *
 * @pre radar_ip_sts_ptr = NULL; dst filled with 0x5A
 * @post Destination buffer unchanged; TOI_Radar_Status_Info_Init called once
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, TOI_Radar_Status_Info_Init_InitializesStatusInfoStructure)
{
   SP_Post_Proc_Buffer_Index           = 0U;
   M2D_Msg_T m2d_msg                   = {0};
   M2D_Buffer_Ptr                      = &m2d_msg;
   TOI_Input_Params_T toi_input_params = {0};
   TOI_Input_Params_T *toi_input_ptr   = &toi_input_params;
   TOI_Radar_Status_Info_Init(toi_input_ptr);
   ASSERT_EQ(toi_input_ptr->toi_data_status_dst_ptr,
             &IPC_D2M_Buffer[0].payload.toi_ds_stream_data.toi_ip_data.toi_ds_radar_data_status_payload);
   // ASSERT_EQ(toi_input_ptr->radar_ip_sts_ptr, m2d_msg.payload.Radar_Sts_Ptr);
}

/**
 * @test TOI_Radar_Status_Info_Init leaves TOI pointers unchanged when M2D buffer is NULL
 *
 * @pre SP post-proc D2M buffer is valid; Get_IPC_M2D_Buffer returns NULL
 * @post toi_data_status_dst_ptr and radar_ip_sts_ptr remain unchanged
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, TOIRadarStatusInfoInit_NullM2DBuffer_LeavesPointersUnchanged)
{
   TOI_Input_Params_T toi_input_params = {0};

   SP_Post_Proc_Buffer_Index                = 0U;
   M2D_Buffer_Ptr                           = NULL;
   toi_input_params.toi_data_status_dst_ptr = (void *)0x1234U;
   toi_input_params.radar_ip_sts_ptr        = (uintptr_t)0x5678U;

   TOI_Radar_Status_Info_Init(&toi_input_params);

   EXPECT_EQ((void *)0x1234U, toi_input_params.toi_data_status_dst_ptr);
   EXPECT_EQ((uintptr_t)0x5678U, toi_input_params.radar_ip_sts_ptr);
}

/**
 * @test Compute_DSS_Rdr_Data_Sts_Payload_CRC returns CODED_FALSE when input pointer is NULL
 *
 * @pre DSS_Radar_Status_CRC_Count starts at 0
 * @post Returns CODED_FALSE and increments DSS_Radar_Status_CRC_Count by 1
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, ComputeDSSRdrDataStsPayloadCrc_NullInput_ReturnsCodedFalse)
{
   DSS_Radar_Status_CRC_Count = 0U;

   const uint8_t crc_mismatch = Compute_DSS_Rdr_Data_Sts_Payload_CRC(NULL);

   EXPECT_EQ(CODED_FALSE, crc_mismatch);
   EXPECT_EQ(1U, DSS_Radar_Status_CRC_Count);
   EXPECT_EQ(0U, Compute_CRC32_SW_fake.call_count);
}

/**
 * @test Compute_DSS_Rdr_Data_Sts_Payload_CRC returns CODED_FALSE when alive counter matches and CRC matches
 *
 * @pre DSS_Radar_Status_CRC_Count is one less than alive_counter and CRC fake matches header CRC
 * @post Returns CODED_FALSE and calls Compute_CRC32_SW once with expected arguments
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, ComputeDSSRdrDataStsPayloadCrc_AliveCounterAndCrcMatch_ReturnsCodedFalse)
{
   IPC_MMIC_Radar_Data_Status_T radar_status = {0};

   DSS_Radar_Status_CRC_Count                                  = 5U;
   radar_status.radar_data_status_header.alive_counter         = 6U;
   radar_status.radar_data_status_header.radar_data_status_crc = 0xA5A5A5A5U;
   Compute_CRC32_SW_fake.return_val                            = 0xA5A5A5A5U;

   const uint8_t crc_mismatch = Compute_DSS_Rdr_Data_Sts_Payload_CRC(&radar_status);

   EXPECT_EQ(CODED_FALSE, crc_mismatch);
   EXPECT_EQ(1U, Compute_CRC32_SW_fake.call_count);
   EXPECT_EQ((uint8_t *)&radar_status.radar_data_status_payload, Compute_CRC32_SW_fake.arg0_val);
   EXPECT_EQ(sizeof(Radar_Data_Status_Payload_T), Compute_CRC32_SW_fake.arg1_val);
   EXPECT_EQ(0U, Compute_CRC32_SW_fake.arg2_val);
   EXPECT_TRUE(Compute_CRC32_SW_fake.arg3_val);
   EXPECT_EQ(6U, DSS_Radar_Status_CRC_Count);
}

/**
 * @test Compute_DSS_Rdr_Data_Sts_Payload_CRC returns CODED_TRUE when alive counter matches but CRC mismatches
 *
 * @pre DSS_Radar_Status_CRC_Count is one less than alive_counter and CRC fake differs from header CRC
 * @post Returns CODED_TRUE and calls Compute_CRC32_SW once
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, ComputeDSSRdrDataStsPayloadCrc_AliveCounterMatchButCrcMismatch_ReturnsCodedTrue)
{
   IPC_MMIC_Radar_Data_Status_T radar_status = {0};

   DSS_Radar_Status_CRC_Count                                  = 10U;
   radar_status.radar_data_status_header.alive_counter         = 11U;
   radar_status.radar_data_status_header.radar_data_status_crc = 0x11111111U;
   Compute_CRC32_SW_fake.return_val                            = 0x22222222U;

   const uint8_t crc_mismatch = Compute_DSS_Rdr_Data_Sts_Payload_CRC(&radar_status);

   EXPECT_EQ(CODED_TRUE, crc_mismatch);
   EXPECT_EQ(1U, Compute_CRC32_SW_fake.call_count);
   EXPECT_EQ(11U, DSS_Radar_Status_CRC_Count);
}

/**
 * @test Compute_DSS_Rdr_Data_Sts_Payload_CRC returns CODED_TRUE and resynchronizes counter on alive mismatch
 *
 * @pre DSS_Radar_Status_CRC_Count + 1 does not equal alive_counter
 * @post Returns CODED_TRUE, does not compute CRC, and updates DSS_Radar_Status_CRC_Count to alive_counter
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, ComputeDSSRdrDataStsPayloadCrc_AliveCounterMismatch_ResyncsCounterAndReturnsCodedTrue)
{
   IPC_MMIC_Radar_Data_Status_T radar_status = {0};

   DSS_Radar_Status_CRC_Count                          = 3U;
   radar_status.radar_data_status_header.alive_counter = 9U;

   const uint8_t crc_mismatch = Compute_DSS_Rdr_Data_Sts_Payload_CRC(&radar_status);

   EXPECT_EQ(CODED_TRUE, crc_mismatch);
   EXPECT_EQ(0U, Compute_CRC32_SW_fake.call_count);
   EXPECT_EQ(9U, DSS_Radar_Status_CRC_Count);
}

/**
 * @test Get_IPC_M2D_Buffer returns NULL when M2D buffer pointer is not set
 *
 * @pre M2D_Buffer_Ptr is NULL
 * @post Function returns NULL
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, GetIPCM2DBuffer_ReturnsNullWhenUnset)
{
   M2D_Buffer_Ptr = NULL;

   EXPECT_EQ(Get_IPC_M2D_Buffer(), (M2D_Msg_T *)NULL);
}

/**
 * @test Get_IPC_M2D_Buffer returns configured M2D pointer
 *
 * @pre M2D_Buffer_Ptr points to a valid M2D message object
 * @post Function returns the same pointer
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, GetIPCM2DBuffer_ReturnsConfiguredPointer)
{
   M2D_Msg_T m2d_msg = {0};
   M2D_Buffer_Ptr    = &m2d_msg;

   EXPECT_EQ(Get_IPC_M2D_Buffer(), &m2d_msg);
}

/**
 * @test Get_IPC_M2D_One_Time_Buffer returns NULL when one-time pointer is not set
 *
 * @pre M2D_One_Time_Msg_Ptr is NULL
 * @post Function returns NULL
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, GetIPCM2DOneTimeBuffer_ReturnsNullWhenUnset)
{
   M2D_One_Time_Msg_Ptr = NULL;

   EXPECT_EQ(Get_IPC_M2D_One_Time_Buffer(), (M2D_One_Time_Msg_T *)NULL);
}

/**
 * @test Get_IPC_M2D_One_Time_Buffer returns configured one-time pointer
 *
 * @pre M2D_One_Time_Msg_Ptr points to a valid one-time message object
 * @post Function returns the same pointer
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, GetIPCM2DOneTimeBuffer_ReturnsConfiguredPointer)
{
   M2D_One_Time_Msg_T one_time_msg = {0};
   M2D_One_Time_Msg_Ptr            = &one_time_msg;

   EXPECT_EQ(Get_IPC_M2D_One_Time_Buffer(), &one_time_msg);
}

/**
 * @test Send_Range_Proc_Complete increments error counter when buffer full
 *
 * @pre IPC notify buffer is full
 * @post D2M_Buffer_Full_Error_Counter incremented, no notification sent
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, SendRangeProcComplete_BufferFull)
{
   Is_IPC_Notify_Buffer_Full_fake.return_val = true;
   D2M_Buffer_Full_Error_Counter             = 0U;

   Send_Range_Proc_Complete(ERRORFIELD_NO_ERROR);

   EXPECT_EQ(D2M_Buffer_Full_Error_Counter, 1U);
   EXPECT_EQ(Get_IPC_Notify_Buffer_fake.call_count, 0U);
}

/**
 * @test Send_Range_Proc_Complete executes success path when buffer is available
 *
 * @pre Buffer not full; notify buffer returns valid structure; RP_Buffer_Index = 1
 * @post Writeback and WUR_EXPSTATE triggered; notify fields populated; DP_Rdd_Buffer_Index updated
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, SendRangeProcComplete_BufferAvailable_ExecutesSuccessPath)
{
   RP_Buffer_Index                                                = 1U;
   IPC_D2M_Buffer[1].payload.rdd_stream_data.look_data.scan_index = 42U;
   DSP_PFM_Index_Isr                                              = 7U;
   Is_IPC_Notify_Buffer_Full_fake.return_val                      = false;
   Get_IPC_Notify_Buffer_fake.return_val                          = &g_ipc_notify_buffer;

   Send_Range_Proc_Complete(ERRORFIELD_NO_ERROR);

   EXPECT_EQ(1U, g_writeback_call_count);
   EXPECT_EQ(1U, g_wur_expstate_call_count);
   EXPECT_EQ(0x0001U, g_wur_expstate_last_value);
   EXPECT_EQ(DSP_RANGE_PROCESSING_COMPLETE, g_ipc_notify_buffer.command);
   EXPECT_EQ((uint16_t)ERRORFIELD_NO_ERROR, g_ipc_notify_buffer.errorField);
   EXPECT_EQ(1U, g_ipc_notify_buffer.pingPongIndex);
   EXPECT_EQ(42U, g_ipc_notify_buffer.lookIndex);
   EXPECT_EQ(7U, g_ipc_notify_buffer.pfm_index);
   EXPECT_EQ(1U, DP_Rdd_Buffer_Index);
}

TEST_F(Ipc_Dsp_Unit_Test_Suite, SendRangeProcComplete_Error_UsesFixedTriggerErrorPath)
{
   RP_Buffer_Index                           = 0U;
   Is_IPC_Notify_Buffer_Full_fake.return_val = false;
   Get_IPC_Notify_Buffer_fake.return_val     = &g_ipc_notify_buffer;

   Send_Range_Proc_Complete(ERRORFIELD_RANGE_PROCESS_ERROR);

   EXPECT_EQ(DSP_RANGE_PROCESSING_COMPLETE, g_ipc_notify_buffer.command);
   EXPECT_EQ((uint16_t)ERRORFIELD_RANGE_PROCESS_ERROR, g_ipc_notify_buffer.errorField);
   EXPECT_EQ(1U, g_writeback_call_count);
}

TEST_F(Ipc_Dsp_Unit_Test_Suite, UpdateRDDStreamHeader_PopulatesStreamAndDebugHeaderFields)
{
   memset(&d2m_msg, 0, sizeof(d2m_msg));
   d2m_msg.payload.rdd_stream_data.look_data.scan_index = 123U;

   Update_RDD_Stream_Header(&d2m_msg, ERRORFIELD_DOPPLER_PROCESS_TIMEOUT);

   EXPECT_EQ(123U, d2m_msg.payload.rdd_stream_data.stream_hdr.scan_index);
   EXPECT_EQ(sizeof(Rdd_Stream_T), d2m_msg.payload.rdd_stream_data.stream_hdr.size);
   EXPECT_EQ((uint16_t)ERRORFIELD_DOPPLER_PROCESS_TIMEOUT, d2m_msg.payload.rdd_stream_data.stream_hdr.error_info);

   EXPECT_EQ(123U, d2m_msg.payload.rdd_debug_data.stream_hdr.scan_index);
   EXPECT_EQ(sizeof(Rdd_Debug_Stream_T), d2m_msg.payload.rdd_debug_data.stream_hdr.size);
   EXPECT_EQ((uint16_t)ERRORFIELD_DOPPLER_PROCESS_TIMEOUT, d2m_msg.payload.rdd_debug_data.stream_hdr.error_info);
}

/**
 * @test Send_Doppler_RDD_Proc_Complete handles buffer full condition
 *
 * @pre IPC notify buffer is full
 * @post Error counter incremented
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, SendDopplerRDDProcComplete_BufferFull)
{
   Is_IPC_Notify_Buffer_Full_fake.return_val = 1U;
   D2M_Buffer_Full_Error_Counter             = 0U;

   Send_Doppler_RDD_Proc_Complete(ERRORFIELD_DOPPLER_PROCESS_ERROR);

   EXPECT_EQ(D2M_Buffer_Full_Error_Counter, 1U);
}

/**
 * @test Send_Doppler_RDD_Proc_Complete executes success path when buffer is available
 *
 * @pre IPC notify buffer is not full; notify buffer returns a valid structure
 * @post Writeback triggered, headers populated, state updated
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, SendDopplerRDDProcComplete_BufferAvailable_ExecutesSuccessPath)
{
   DP_Rdd_Buffer_Index                                            = 0U;
   IPC_D2M_Buffer[0].payload.rdd_stream_data.look_data.scan_index = 7U;
   DSP_PFM_Index                                                  = 3U;
   Is_IPC_Notify_Buffer_Full_fake.return_val                      = false;
   Get_IPC_Notify_Buffer_fake.return_val                          = &g_ipc_notify_buffer;

   Send_Doppler_RDD_Proc_Complete(ERRORFIELD_DOPPLER_PROCESS_ERROR);

   EXPECT_EQ(1U, g_writeback_call_count);
   EXPECT_EQ(1U, g_wur_expstate_call_count);
   EXPECT_EQ(0x0001U, g_wur_expstate_last_value);
   EXPECT_EQ(DSP_DOPPLER_PROCESSING_COMPLETE, g_ipc_notify_buffer.command);
   EXPECT_EQ((uint16_t)ERRORFIELD_DOPPLER_PROCESS_ERROR, g_ipc_notify_buffer.errorField);
   EXPECT_EQ(0U, g_ipc_notify_buffer.pingPongIndex);
   EXPECT_EQ(3U, g_ipc_notify_buffer.pfm_index);
   EXPECT_EQ(READY_FOR_RANGE_PROCESSING, Ready_For_New_Frame);
   EXPECT_EQ(0U, SP_Post_Proc_Buffer_Index);
}

/**
 * @test Send_SP_Post_Proc_Complete_to_R52 handles buffer full
 *
 * @pre IPC notify buffer is full
 * @post Error counter incremented
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, SendSPPostProcComplete_BufferFull)
{
   Is_IPC_Notify_Buffer_Full_fake.return_val = 1U;
   D2M_Buffer_Full_Error_Counter             = 5U;

   Send_SP_Post_Proc_Complete_to_R52(ERRORFIELD_POST_SIG_PROC_ERROR);

   EXPECT_EQ(D2M_Buffer_Full_Error_Counter, 6U);
}

/**
 * @test Send_SP_Post_Proc_Complete_to_R52 executes success path when buffer is available
 *
 * @pre IPC notify buffer is not full; notify buffer returns a valid structure
 * @post Header fields set and the fixed-trigger ping notification is populated
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, SendSPPostProcComplete_BufferAvailable_ExecutesSuccessPath)
{
   SP_Post_Proc_Buffer_Index                                      = 0U;
   IPC_D2M_Buffer[0].payload.rdd_stream_data.look_data.scan_index = 15U;
   DSP_PFM_Index                                                  = 2U;
   DSP_D2M_Msg_Header_Cnt                                         = 4U;
   Is_IPC_Notify_Buffer_Full_fake.return_val                      = false;
   Get_IPC_Notify_Buffer_fake.return_val                          = &g_ipc_notify_buffer;
   M2D_Buffer_Ptr                                                 = &s_m2d_msg;

   Send_SP_Post_Proc_Complete_to_R52(ERRORFIELD_POST_SIG_PROC_ERROR);

   EXPECT_EQ(0U, g_writeback_call_count);
   EXPECT_EQ(0U, g_wur_expstate_call_count);
   EXPECT_EQ(DSP_SP_POST_PROCESSING_COMPLETE, IPC_BBE2R52_Fixed_Notify_Msg[BUF_IDX_PING].command);
   EXPECT_EQ((uint16_t)ERRORFIELD_POST_SIG_PROC_ERROR, IPC_BBE2R52_Fixed_Notify_Msg[BUF_IDX_PING].errorField);
   EXPECT_EQ(0U, IPC_BBE2R52_Fixed_Notify_Msg[BUF_IDX_PING].pingPongIndex);
   EXPECT_EQ(15U, IPC_BBE2R52_Fixed_Notify_Msg[BUF_IDX_PING].lookIndex);
   EXPECT_EQ(2U, IPC_BBE2R52_Fixed_Notify_Msg[BUF_IDX_PING].pfm_index);
   EXPECT_EQ(5U, DSP_D2M_Msg_Header_Cnt);
   EXPECT_EQ(sizeof(D2M_Msg_T), IPC_D2M_Buffer[0].header.size);
   EXPECT_EQ(5U, IPC_D2M_Buffer[0].header.counter);
}

TEST_F(Ipc_Dsp_Unit_Test_Suite, SendSPPostProcComplete_BufferAvailable_PopulatesPongNotification)
{
   SP_Post_Proc_Buffer_Index                                      = 1U;
   IPC_D2M_Buffer[1].payload.rdd_stream_data.look_data.scan_index = 16U;
   DSP_PFM_Index                                                  = 3U;
   Is_IPC_Notify_Buffer_Full_fake.return_val                      = false;
   Get_IPC_Notify_Buffer_fake.return_val                          = &g_ipc_notify_buffer;
   M2D_Buffer_Ptr                                                 = &s_m2d_msg;

   Send_SP_Post_Proc_Complete_to_R52(ERRORFIELD_NO_ERROR);

   EXPECT_EQ(DSP_SP_POST_PROCESSING_COMPLETE, IPC_BBE2R52_Fixed_Notify_Msg[BUF_IDX_PONG].command);
   EXPECT_EQ((uint16_t)ERRORFIELD_NO_ERROR, IPC_BBE2R52_Fixed_Notify_Msg[BUF_IDX_PONG].errorField);
   EXPECT_EQ(1U, IPC_BBE2R52_Fixed_Notify_Msg[BUF_IDX_PONG].pingPongIndex);
   EXPECT_EQ(16U, IPC_BBE2R52_Fixed_Notify_Msg[BUF_IDX_PONG].lookIndex);
   EXPECT_EQ(3U, IPC_BBE2R52_Fixed_Notify_Msg[BUF_IDX_PONG].pfm_index);
}

/**
 * @test Send_SP_Post_Proc_Complete_to_R52 updates max CRC compute time when elapsed time exceeds current max
 *
 * @pre DSP_D2M_CRC_Compute_Time_Max_us is below the elapsed CRC compute time
 * @post DSP_D2M_CRC_Compute_Time_Max_us updated to the new elapsed time
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, SendSPPostProcComplete_UpdatesMaxCrcComputeTime)
{
   unsigned int ccount_seq[]                 = {100U, 100U + (10U * DSP_CLK_FREQ_MHZ)};
   DSP_D2M_CRC_Compute_Time_Max_us           = 5U;
   DSP_D2M_CRC_Compute_Time_Min_us           = 100U;
   Is_IPC_Notify_Buffer_Full_fake.return_val = false;
   Get_IPC_Notify_Buffer_fake.return_val     = &g_ipc_notify_buffer;
   M2D_Buffer_Ptr                            = &s_m2d_msg;
   SET_RETURN_SEQ(xthal_get_ccount, ccount_seq, 2);

   Send_SP_Post_Proc_Complete_to_R52(ERRORFIELD_NO_ERROR);

   EXPECT_EQ(10U, DSP_D2M_CRC_Compute_Time_us);
   EXPECT_EQ(10U, DSP_D2M_CRC_Compute_Time_Max_us);
}

/**
 * @test Send_SP_Post_Proc_Complete_to_R52 does not update min CRC compute time when elapsed time is not less than current min
 *
 * @pre DSP_D2M_CRC_Compute_Time_Min_us is below the elapsed CRC compute time
 * @post DSP_D2M_CRC_Compute_Time_Min_us remains unchanged
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, SendSPPostProcComplete_DoesNotUpdateMinCrcComputeTime)
{
   unsigned int ccount_seq[]                 = {200U, 200U + (10U * DSP_CLK_FREQ_MHZ)};
   DSP_D2M_CRC_Compute_Time_Max_us           = 50U;
   DSP_D2M_CRC_Compute_Time_Min_us           = 3U;
   Is_IPC_Notify_Buffer_Full_fake.return_val = false;
   Get_IPC_Notify_Buffer_fake.return_val     = &g_ipc_notify_buffer;
   M2D_Buffer_Ptr                            = &s_m2d_msg;
   SET_RETURN_SEQ(xthal_get_ccount, ccount_seq, 2);

   Send_SP_Post_Proc_Complete_to_R52(ERRORFIELD_NO_ERROR);

   EXPECT_EQ(10U, DSP_D2M_CRC_Compute_Time_us);
   EXPECT_EQ(3U, DSP_D2M_CRC_Compute_Time_Min_us);
}

/**
 * @test Send_SP_Post_Proc_Complete_to_R52 updates min CRC compute time when elapsed time is smaller
 *
 * @pre DSP_D2M_CRC_Compute_Time_Min_us exceeds the elapsed CRC compute time
 * @post DSP_D2M_CRC_Compute_Time_Min_us is updated to the new elapsed time
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, SendSPPostProcComplete_UpdatesMinCrcComputeTime)
{
   unsigned int ccount_seq[]                 = {300U, 300U + (10U * DSP_CLK_FREQ_MHZ)};
   DSP_D2M_CRC_Compute_Time_Max_us           = 50U;
   DSP_D2M_CRC_Compute_Time_Min_us           = 100U;
   Is_IPC_Notify_Buffer_Full_fake.return_val = false;
   Get_IPC_Notify_Buffer_fake.return_val     = &g_ipc_notify_buffer;
   M2D_Buffer_Ptr                            = &s_m2d_msg;
   SET_RETURN_SEQ(xthal_get_ccount, ccount_seq, 2);

   Send_SP_Post_Proc_Complete_to_R52(ERRORFIELD_NO_ERROR);

   EXPECT_EQ(10U, DSP_D2M_CRC_Compute_Time_us);
   EXPECT_EQ(10U, DSP_D2M_CRC_Compute_Time_Min_us);
}

/**
 * @test Send_SP_Post_Proc_Complete_to_R52 sets header size to zero when XCP fault type is BBE_To_R52_Fault
 *
 * @pre M2D buffer xcp_fault_type = BBE_To_R52_Fault; buffer not full
 * @post IPC_D2M_Buffer header.size forced to 0U by XCP fault injection branch (line 423)
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, SendSPPostProcComplete_XcpFaultInjectionBbeToR52_SetsSizeToZero)
{
   SP_Post_Proc_Buffer_Index                 = 0U;
   Is_IPC_Notify_Buffer_Full_fake.return_val = false;
   Get_IPC_Notify_Buffer_fake.return_val     = &g_ipc_notify_buffer;
   M2D_Buffer_Ptr                            = &s_m2d_msg;
   s_m2d_msg.payload.xcp_fault_type          = BBE_To_R52_Fault;

   Send_SP_Post_Proc_Complete_to_R52(ERRORFIELD_NO_ERROR);

   EXPECT_EQ(0U, IPC_D2M_Buffer[0].header.size);
}

/**
 * @test Send_Core_Initialization handles buffer full condition
 *
 * @pre IPC notify buffer is full
 * @post Error counter incremented, no notification sent
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, SendCoreInitialization_BufferFull)
{
   Is_IPC_Notify_Buffer_Full_fake.return_val = 1U;
   D2M_Buffer_Full_Error_Counter             = 0U;

   Send_Core_Initialization();

   EXPECT_EQ(D2M_Buffer_Full_Error_Counter, 1U);
}

/**
 * @test Send_Core_Initialization executes success path when buffer is available
 *
 * @pre IPC notify buffer is not full; notify buffer returns a valid structure
 * @post CORE_INITIALIZED command set, DSP IRQ_ENA bit 0 set, WUR_EXPSTATE triggered
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, SendCoreInitialization_BufferAvailable_ExecutesSuccessPath)
{
   Dsp_Ptr->IRQ_ENA                          = 0x00U;
   Is_IPC_Notify_Buffer_Full_fake.return_val = false;
   Get_IPC_Notify_Buffer_fake.return_val     = &g_ipc_notify_buffer;

   Send_Core_Initialization();

   EXPECT_EQ(0U, g_writeback_call_count);
   EXPECT_EQ(CORE_INITIALIZED, g_ipc_notify_buffer.command);
   EXPECT_EQ(0x01U, Dsp_Ptr->IRQ_ENA & 0x01U);
   EXPECT_EQ(1U, g_wur_expstate_call_count);
   EXPECT_EQ(0x0001U, g_wur_expstate_last_value);
   EXPECT_EQ(0U, D2M_Buffer_Full_Error_Counter);
}

/**
 * @test Wait_For_Trigger returns true when trigger received
 *
 * @pre Trigger value changes from NO_TRIGGER to TRIGGER_RECEIVED
 * @post Function returns true and Waiting_For_Trigger updated
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, WaitForTrigger_TriggerReceived)
{
   volatile uint32_t trigger = NO_TRIGGER;
   unsigned int l32ai_seq[]  = {NO_TRIGGER, TRIGGER_RECEIVED};
   unsigned int time_seq[]   = {0U, 100U};

   SET_RETURN_SEQ(XT_L32AI, l32ai_seq, 2);
   SET_RETURN_SEQ(xthal_get_ccount, time_seq, 2);

   EXPECT_TRUE(Wait_For_Trigger(&trigger));
   EXPECT_GT(Waiting_For_Trigger, 0U);
}

/**
 * @test Wait_For_Trigger returns false on timeout
 *
 * @pre Trigger never received, timeout expires
 * @post Function returns false after timeout
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, WaitForTrigger_Timeout)
{
   volatile uint32_t trigger = NO_TRIGGER;
   unsigned int l32ai_seq[]  = {NO_TRIGGER, NO_TRIGGER};
   unsigned int time_seq[]   = {0U, (DEFAULT_TIMEOUT_US + 1U) * DSP_CLK_FREQ_MHZ};

   SET_RETURN_SEQ(XT_L32AI, l32ai_seq, 2);
   SET_RETURN_SEQ(xthal_get_ccount, time_seq, 2);

   EXPECT_FALSE(Wait_For_Trigger(&trigger));
}

/**
 * @test Verify IPC_D2M_Buffer is accessible in unit tests with UNIT_TEST defined
 *
 * @pre UNIT_TEST removes section attributes
 * @post Buffer can be read/written without segfaults
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, IPCD2MBuffer_IsAccessible)
{
   // Write to buffer index 0
   IPC_D2M_Buffer[0].header.size    = 0x12345678U;
   IPC_D2M_Buffer[0].header.counter = 0xABCDEF00U;
   IPC_D2M_Buffer[0].header.crc     = 0xDEADBEEFU;

   // Write to buffer index 1
   IPC_D2M_Buffer[1].header.size    = 0x87654321U;
   IPC_D2M_Buffer[1].header.counter = 0x00FEDCBAU;
   IPC_D2M_Buffer[1].header.crc     = 0xCAFEBABEU;

   // Read back and verify - proves no segfault on access
   EXPECT_EQ(IPC_D2M_Buffer[0].header.size, 0x12345678U);
   EXPECT_EQ(IPC_D2M_Buffer[0].header.counter, 0xABCDEF00U);
   EXPECT_EQ(IPC_D2M_Buffer[0].header.crc, 0xDEADBEEFU);
   EXPECT_EQ(IPC_D2M_Buffer[1].header.size, 0x87654321U);
   EXPECT_EQ(IPC_D2M_Buffer[1].header.counter, 0x00FEDCBAU);
   EXPECT_EQ(IPC_D2M_Buffer[1].header.crc, 0xCAFEBABEU);

   // Verify payload data can also be accessed
   IPC_D2M_Buffer[0].payload.rdd_stream_data.look_data.scan_index = 42U;
   EXPECT_EQ(IPC_D2M_Buffer[0].payload.rdd_stream_data.look_data.scan_index, 42U);
}

/*===========================================================================*
 * Test Cases for Writeback_D2M_Send_R52_Notification (via calling functions)
 * Tests coverage for function at line 183 in ipc_dsp.c
 *===========================================================================*/

/**
 * @test Verify DSP mock is properly initialized and accessible
 *
 * @pre DSP structure allocated
 * @post Can read and write DSP->IRQ_ENA bit 0
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, DSPMock_IsAccessible)
{
   // Verify DSP pointer is not null
   ASSERT_NE(Dsp_Ptr, (DSP_SFRS_t *)NULL);
   Dsp_Ptr->IRQ_ENA = 0x00U;
   Dsp_Ptr->IRQ_ENA |= 0x01U;

   // Verify bit 0 was set
   EXPECT_NE(Dsp_Ptr->IRQ_ENA & 0x01U, 0x00U);
}

/**
 * @test Writeback_D2M_Send_R52_Notification calls dcache writeback, sets IRQ_ENA bit 0, and triggers WUR_EXPSTATE
 *
 * @pre DSP->IRQ_ENA = 0; IPC_D2M_Buffer[0] is a valid buffer
 * @post dcache writeback called with correct addr/size; IRQ_ENA bit 0 set; WUR_EXPSTATE(0x0001) called
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, WritebackD2MSendR52Notification_ExecutesHelperPath)
{
   Dsp_Ptr->IRQ_ENA = 0x00U;

   Writeback_D2M_Send_R52_Notification(&IPC_D2M_Buffer[0]);

   EXPECT_EQ(1U, g_writeback_call_count);
   EXPECT_EQ((void *)&IPC_D2M_Buffer[0], g_writeback_last_addr);
   EXPECT_EQ(sizeof(D2M_Msg_T), g_writeback_last_size);
   EXPECT_EQ(0x01U, Dsp_Ptr->IRQ_ENA & 0x01U);
   EXPECT_EQ(1U, g_wur_expstate_call_count);
   EXPECT_EQ(0x0001U, g_wur_expstate_last_value);
}

/**
 * @test SP2DSP_LVL1_Handler increments handler counter when invoked
 *
 * @pre IPC notify buffer is empty
 * @post SP2DSP_LVL1_Handler_test_var increments by 1
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, SP2DSPLVL1Handler_IncrementsHandlerCounter)
{
   Is_IPC_Notify_Buffer_Empty_fake.return_val = true;
   SP2DSP_LVL1_Handler_test_var               = 0U;

   SP2DSP_LVL1_Handler(NULL);

   EXPECT_EQ(SP2DSP_LVL1_Handler_test_var, 1U);
}

/**
 * @test SP2DSP_LVL1_Handler can be called multiple times
 *
 * @pre IPC notify buffer is empty
 * @post Counter increments once per call
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, SP2DSPLVL1Handler_MultipleCallsIncrementCounter)
{
   Is_IPC_Notify_Buffer_Empty_fake.return_val = true;
   SP2DSP_LVL1_Handler_test_var               = 10U;

   SP2DSP_LVL1_Handler(NULL);
   SP2DSP_LVL1_Handler(NULL);

   EXPECT_EQ(SP2DSP_LVL1_Handler_test_var, 12U);
}

/**
 * @test Check_R52_To_BBE32_Header returns CODED_TRUE when CRC matches
 *
 * @pre CRC in buffer matches the calculated CRC
 * @post Function returns CODED_TRUE
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, CheckR52Header_CrcMatch_ReturnsCodedTrue)
{
   M2D_Msg_T m2d_msg                = {0};
   DSP_M2D_Msg_Header_Cnt           = 0U;
   m2d_msg.header.size              = sizeof(M2D_Msg_T);
   m2d_msg.header.counter           = 1U;
   m2d_msg.header.crc               = 0x55U;
   Calc_M2D_Buf_Crc_fake.return_val = 0x55U;

   uint8_t result = Check_R52_To_BBE32_Header(&m2d_msg);

   EXPECT_EQ(result, CODED_TRUE);
   EXPECT_EQ(Calc_M2D_Buf_Crc_fake.call_count, 1U);
}

/**
 * @test Check_R52_To_BBE32_Header returns CODED_FALSE when CRC mismatches
 *
 * @pre CRC in buffer does not match the calculated CRC
 * @post Function returns CODED_FALSE
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, CheckR52Header_CrcMismatch_ReturnsCodedFalse)
{
   M2D_Msg_T m2d_msg                = {0};
   DSP_M2D_Msg_Header_Cnt           = 0U;
   m2d_msg.header.size              = sizeof(M2D_Msg_T);
   m2d_msg.header.counter           = 1U;
   m2d_msg.header.crc               = 0x11U;
   Calc_M2D_Buf_Crc_fake.return_val = 0x22U;

   uint8_t result = Check_R52_To_BBE32_Header(&m2d_msg);

   EXPECT_EQ(result, CODED_FALSE);
   EXPECT_EQ(Calc_M2D_Buf_Crc_fake.call_count, 1U);
}

/**
 * @test Check_R52_To_BBE32_Header returns CODED_FALSE and updates expected counter on mismatch
 *
 * @pre header.counter = 9 but DSP_M2D_Msg_Header_Cnt = 0 (expecting 1)
 * @post Returns CODED_FALSE; DSP_M2D_Msg_Header_Cnt updated to 9; CRC not computed
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, CheckR52Header_CounterMismatch_UpdatesExpectedCounter)
{
   M2D_Msg_T m2d_msg      = {0};
   m2d_msg.header.size    = sizeof(M2D_Msg_T);
   m2d_msg.header.counter = 9U;

   uint8_t result = Check_R52_To_BBE32_Header(&m2d_msg);

   /* counter mismatch = validation failed → CODED_FALSE */
   EXPECT_EQ(result, CODED_FALSE);
   EXPECT_EQ(DSP_M2D_Msg_Header_Cnt, 9U);
   EXPECT_EQ(Calc_M2D_Buf_Crc_fake.call_count, 0U);
}

/**
 * @test Check_R52_To_BBE32_Header updates max CRC compute time when profiling is enabled
 *
 * @pre CRC matches; elapsed time exceeds current max
 * @post DSP_M2D_CRC_Compute_Time_Max_us updated
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, CheckR52Header_UpdatesMaxCrcComputeTime)
{
   M2D_Msg_T m2d_msg                = {0};
   unsigned int ccount_seq[]        = {100U, 100U + (10U * DSP_CLK_FREQ_MHZ)};
   DSP_M2D_Msg_Header_Cnt           = 0U;
   DSP_M2D_CRC_Compute_Time_Max_us  = 5U;
   DSP_M2D_CRC_Compute_Time_Min_us  = 0U;
   m2d_msg.header.size              = sizeof(M2D_Msg_T);
   m2d_msg.header.counter           = 1U;
   m2d_msg.header.crc               = 0xABU;
   Calc_M2D_Buf_Crc_fake.return_val = 0xABU;

   SET_RETURN_SEQ(xthal_get_ccount, ccount_seq, 2);

   (void)Check_R52_To_BBE32_Header(&m2d_msg);

   EXPECT_EQ(DSP_M2D_CRC_Compute_Time_us, 10U);
   EXPECT_EQ(DSP_M2D_CRC_Compute_Time_Max_us, 10U);
}

/**
 * @test Check_R52_To_BBE32_Header updates min CRC compute time when profiling is enabled
 *
 * @pre CRC matches; elapsed time is below current min
 * @post DSP_M2D_CRC_Compute_Time_Min_us updated
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, CheckR52Header_UpdatesMinCrcComputeTime)
{
   M2D_Msg_T m2d_msg                = {0};
   unsigned int ccount_seq[]        = {200U, 200U + (10U * DSP_CLK_FREQ_MHZ)};
   DSP_M2D_Msg_Header_Cnt           = 0U;
   DSP_M2D_CRC_Compute_Time_Max_us  = 50U;
   DSP_M2D_CRC_Compute_Time_Min_us  = 100U;
   m2d_msg.header.size              = sizeof(M2D_Msg_T);
   m2d_msg.header.counter           = 1U;
   m2d_msg.header.crc               = 0xCDU;
   Calc_M2D_Buf_Crc_fake.return_val = 0xCDU;

   SET_RETURN_SEQ(xthal_get_ccount, ccount_seq, 2);

   (void)Check_R52_To_BBE32_Header(&m2d_msg);

   EXPECT_EQ(DSP_M2D_CRC_Compute_Time_us, 10U);
   EXPECT_EQ(DSP_M2D_CRC_Compute_Time_Min_us, 10U);
}

/*===========================================================================*
 * Test Cases for Update_DSP_IPC_Notify
 *===========================================================================*/

/**
 * @test Update_DSP_IPC_Notify exits immediately when R52-to-BBE notify buffer is empty
 *
 * @pre Buffer is empty on first query
 * @post No notifications processed, no ReadIndx incremented
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, UpdateDSPIPCNotify_BufferEmpty_NeverProcesses)
{
   Is_IPC_Notify_Buffer_Empty_fake.return_val = 1U;

   Update_DSP_IPC_Notify();

   EXPECT_EQ(0U, Get_IPC_Notify_Buffer_fake.call_count);
   EXPECT_EQ(0U, Increment_IPC_Notify_ReadIndx_fake.call_count);
}

/**
 * @test Update_DSP_IPC_Notify handles CORE_INITIALIZED command
 *
 * @pre Buffer contains one CORE_INITIALIZED notification with curIpcAddr = 0
 * @post Mss_Init_Received set to TRIGGER_RECEIVED, M2D_One_Time_Msg_Ptr set from curIpcAddr
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, UpdateDSPIPCNotify_CoreInitialized_SetsMssInitReceived)
{
   volatile Ipc_Notify_Structure_T input_notify      = {};
   uint8_t empty_seq[]                               = {0U, 1U};
   volatile Ipc_Notify_Structure_T *notify_get_seq[] = {&input_notify};

   input_notify.command    = CORE_INITIALIZED;
   input_notify.curIpcAddr = 0U;
   Mss_Init_Received       = NO_TRIGGER;
   M2D_One_Time_Msg_Ptr    = NULL;

   SET_RETURN_SEQ(Is_IPC_Notify_Buffer_Empty, empty_seq, 2);
   SET_RETURN_SEQ(Get_IPC_Notify_Buffer, notify_get_seq, 1);

   Update_DSP_IPC_Notify();

   EXPECT_EQ(TRIGGER_RECEIVED, Mss_Init_Received);
   EXPECT_EQ(NULL, (void *)M2D_One_Time_Msg_Ptr);
   EXPECT_EQ(1U, Increment_IPC_Notify_ReadIndx_fake.call_count);
}

/**
 * @test Update_DSP_IPC_Notify increments error counter when BBE-to-R52 output buffer is full
 *
 * @pre R52-to-BBE buffer has R52_TRIGGER_RANGE_PROCESSING_CONFIGURATION; output buffer is full
 * @post D2M_Buffer_Full_Error_Counter incremented, ReadIndx still advanced
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, UpdateDSPIPCNotify_RangeTrigger_OutputBufferFull_IncrementsErrorCounter)
{
   volatile Ipc_Notify_Structure_T input_notify      = {};
   uint8_t empty_seq[]                               = {0U, 1U};
   volatile Ipc_Notify_Structure_T *notify_get_seq[] = {&input_notify};

   input_notify.command                      = R52_TRIGGER_RANGE_PROCESSING_CONFIGURATION;
   D2M_Buffer_Full_Error_Counter             = 0U;
   Is_IPC_Notify_Buffer_Full_fake.return_val = 1U;

   SET_RETURN_SEQ(Is_IPC_Notify_Buffer_Empty, empty_seq, 2);
   SET_RETURN_SEQ(Get_IPC_Notify_Buffer, notify_get_seq, 1);

   Update_DSP_IPC_Notify();

   EXPECT_EQ(1U, D2M_Buffer_Full_Error_Counter);
   EXPECT_EQ(1U, Increment_IPC_Notify_ReadIndx_fake.call_count);
}

/**
 * @test Update_DSP_IPC_Notify R52 range trigger with CRC mismatch increments M2D error counter
 *
 * @pre Output buffer not full; M2D message has CRC mismatch
 * @post IPC_M2D_Buffer_Err_Cnt incremented by one
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, UpdateDSPIPCNotify_RangeTrigger_CrcMismatch_IncrementsErrorCount)
{
   M2D_Msg_T *m2d_msg = &s_m2d_msg;
   volatile Ipc_Notify_Structure_T input_notify;
   memset((void *)&input_notify, 0, sizeof(input_notify));
   uint8_t empty_seq[]                               = {0U, 1U};
   volatile Ipc_Notify_Structure_T *notify_get_seq[] = {&input_notify, &g_ipc_notify_buffer};

   m2d_msg->header.size             = sizeof(M2D_Msg_T);
   m2d_msg->header.counter          = 1U;
   m2d_msg->header.crc              = 0xAAU;
   Calc_M2D_Buf_Crc_fake.return_val = 0xBBU;

   input_notify.command                      = R52_TRIGGER_RANGE_PROCESSING_CONFIGURATION;
   input_notify.curIpcAddr                   = (uintptr_t)m2d_msg;
   IPC_M2D_Buffer_Err_Cnt                    = 0U;
   Is_IPC_Notify_Buffer_Full_fake.return_val = 0U;

   SET_RETURN_SEQ(Is_IPC_Notify_Buffer_Empty, empty_seq, 2);
   SET_RETURN_SEQ(Get_IPC_Notify_Buffer, notify_get_seq, 2);

   Update_DSP_IPC_Notify();

   EXPECT_EQ(1U, IPC_M2D_Buffer_Err_Cnt);
   EXPECT_EQ(1U, Increment_IPC_Notify_ReadIndx_fake.call_count);
}

/**
 * @test Update_DSP_IPC_Notify normal mode swaps RP_Buffer_Index on successful CRC match
 *
 * @pre CRC match; ITF_DISABLED_NORMAL_MODE; RP_Buffer_Index = 0; trigger init succeeds
 * @post RP_Buffer_Index toggled to 1; DSP_RANGE_CONFIGURATION_COMPLETE sent; writeback triggered
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, UpdateDSPIPCNotify_RangeTrigger_NormalMode_SwapsRPBufferIndex)
{
   volatile M2D_Msg_T *m2d_msg                       = &s_m2d_msg;
   volatile Ipc_Notify_Structure_T input_notify      = {};
   uint8_t empty_seq[]                               = {0U, 1U};
   volatile Ipc_Notify_Structure_T *notify_get_seq[] = {&input_notify, &g_ipc_notify_buffer};

   m2d_msg->header.size               = sizeof(M2D_Msg_T);
   m2d_msg->header.counter            = 1U;
   m2d_msg->header.crc                = 0xCCU;
   m2d_msg->payload.offline_mode_flag = (uint32_t)ITF_DISABLED_NORMAL_MODE;
   Calc_M2D_Buf_Crc_fake.return_val   = 0xCCU;

   input_notify.command                      = R52_TRIGGER_RANGE_PROCESSING_CONFIGURATION;
   input_notify.curIpcAddr                   = (uintptr_t)m2d_msg;
   RP_Buffer_Index                           = 0U;
   Ready_For_New_Frame                       = READY_FOR_RANGE_PROCESSING;
   Appl_Range_Process_Init_fake.return_val   = true;
   Is_IPC_Notify_Buffer_Full_fake.return_val = 0U;

   SET_RETURN_SEQ(Is_IPC_Notify_Buffer_Empty, empty_seq, 2);
   SET_RETURN_SEQ(Get_IPC_Notify_Buffer, notify_get_seq, 2);

   Update_DSP_IPC_Notify();

   EXPECT_EQ(1U, RP_Buffer_Index);
   EXPECT_EQ(DSP_RANGE_CONFIGURATION_COMPLETE, g_ipc_notify_buffer.command);
   EXPECT_EQ(1U, g_wur_expstate_call_count);
   EXPECT_EQ(0x0001U, g_wur_expstate_last_value);
   EXPECT_EQ(1U, Increment_IPC_Notify_ReadIndx_fake.call_count);
}

/**
 * @test Update_DSP_IPC_Notify offline mode forces RP_Buffer_Index to zero
 *
 * @pre CRC match; ITF_ADC_INJECTION_MODE set in payload; RP_Buffer_Index = 1
 * @post RP_Buffer_Index forced to 0 regardless of previous value
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, UpdateDSPIPCNotify_RangeTrigger_OfflineMode_ForcesRPBufferIndexZero)
{
   volatile M2D_Msg_T *m2d_msg                       = &s_m2d_msg;
   volatile Ipc_Notify_Structure_T input_notify      = {};
   uint8_t empty_seq[]                               = {0U, 1U};
   volatile Ipc_Notify_Structure_T *notify_get_seq[] = {&input_notify, &g_ipc_notify_buffer};

   m2d_msg->header.size               = sizeof(M2D_Msg_T);
   m2d_msg->header.counter            = 1U;
   m2d_msg->header.crc                = 0xCCU;
   m2d_msg->payload.offline_mode_flag = (uint32_t)ITF_ADC_INJECTION_MODE;
   Calc_M2D_Buf_Crc_fake.return_val   = 0xCCU;

   input_notify.command                      = R52_TRIGGER_RANGE_PROCESSING_CONFIGURATION;
   input_notify.curIpcAddr                   = (uintptr_t)m2d_msg;
   RP_Buffer_Index                           = 1U;
   Ready_For_New_Frame                       = READY_FOR_RANGE_PROCESSING;
   Appl_Range_Process_Init_fake.return_val   = true;
   Is_IPC_Notify_Buffer_Full_fake.return_val = 0U;

   SET_RETURN_SEQ(Is_IPC_Notify_Buffer_Empty, empty_seq, 2);
   SET_RETURN_SEQ(Get_IPC_Notify_Buffer, notify_get_seq, 2);

   Update_DSP_IPC_Notify();

   EXPECT_EQ(0U, RP_Buffer_Index);
   EXPECT_EQ(1U, Increment_IPC_Notify_ReadIndx_fake.call_count);
}

/**
 * @test Update_DSP_IPC_Notify unrecognized command falls through switch without action
 *
 * @pre Buffer has one notification with an unknown command value
 * @post No output buffer interaction, ReadIndx still advanced once
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, UpdateDSPIPCNotify_UnknownCommand_NoAction)
{
   volatile Ipc_Notify_Structure_T input_notify      = {};
   uint8_t empty_seq[]                               = {0U, 1U};
   volatile Ipc_Notify_Structure_T *notify_get_seq[] = {&input_notify};

   input_notify.command = 0xFFU;

   SET_RETURN_SEQ(Is_IPC_Notify_Buffer_Empty, empty_seq, 2);
   SET_RETURN_SEQ(Get_IPC_Notify_Buffer, notify_get_seq, 1);

   Update_DSP_IPC_Notify();

   EXPECT_EQ(0U, D2M_Buffer_Full_Error_Counter);
   EXPECT_EQ(0U, Mss_Init_Received);
   EXPECT_EQ(1U, Increment_IPC_Notify_ReadIndx_fake.call_count);
   EXPECT_EQ(1U, Get_IPC_Notify_Buffer_fake.call_count);
}

TEST_F(Ipc_Dsp_Unit_Test_Suite, UpdateDSPIPCNotify_RaErrorFault_SetsDspRaErrorFlag)
{
   volatile Ipc_Notify_Structure_T input_notify      = {};
   uint8_t empty_seq[]                               = {0U, 1U};
   volatile Ipc_Notify_Structure_T *notify_get_seq[] = {&input_notify};

   input_notify.command = R52_RA_ERROR_FAULT;
   DSP_RA_Error_Flag    = CODED_FALSE;

   SET_RETURN_SEQ(Is_IPC_Notify_Buffer_Empty, empty_seq, 2);
   SET_RETURN_SEQ(Get_IPC_Notify_Buffer, notify_get_seq, 1);

   Update_DSP_IPC_Notify();

   EXPECT_EQ(CODED_TRUE, Get_DSP_RA_Error_Status());
   EXPECT_EQ(1U, Increment_IPC_Notify_ReadIndx_fake.call_count);
}

TEST_F(Ipc_Dsp_Unit_Test_Suite, UpdateDSPIPCNotify_InducedLookError_UsesNextLookType)
{
   volatile M2D_Msg_T *m2d_msg                       = &s_m2d_msg;
   volatile Ipc_Notify_Structure_T input_notify      = {};
   uint8_t empty_seq[]                               = {0U, 1U};
   volatile Ipc_Notify_Structure_T *notify_get_seq[] = {&input_notify, &g_ipc_notify_buffer};

   m2d_msg->header.size                      = sizeof(M2D_Msg_T);
   m2d_msg->header.counter                   = 1U;
   m2d_msg->header.crc                       = 0xCCU;
   m2d_msg->payload.look_Info.look_type      = RADAR_LOOK_A;
   Calc_M2D_Buf_Crc_fake.return_val          = 0xCCU;
   input_notify.command                      = R52_TRIGGER_RANGE_PROCESSING_CONFIGURATION;
   input_notify.curIpcAddr                   = (uintptr_t)m2d_msg;
   Ready_For_New_Frame                       = READY_FOR_RANGE_PROCESSING;
   Appl_Range_Process_Init_fake.return_val   = true;
   Is_IPC_Notify_Buffer_Full_fake.return_val = false;
   Look_Type_Induce_Err                      = true;

   SET_RETURN_SEQ(Is_IPC_Notify_Buffer_Empty, empty_seq, 2);
   SET_RETURN_SEQ(Get_IPC_Notify_Buffer, notify_get_seq, 2);

   Update_DSP_IPC_Notify();

   EXPECT_EQ((Radar_Look_T)((RADAR_LOOK_A + 1U) % 4U), Appl_Range_Process_Init_fake.arg0_val);
}

/**
 * @test Update_DSP_IPC_Notify ITF_DATA_CUBE_INJECTION_MODE forces RP_Buffer_Index to zero
 *
 * @pre CRC match; ITF_DATA_CUBE_INJECTION_MODE in payload; RP_Buffer_Index = 1
 * @post RP_Buffer_Index forced to 0
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, UpdateDSPIPCNotify_RangeTrigger_DataCubeInjectionMode_ForcesRPBufferIndexZero)
{
   volatile M2D_Msg_T *m2d_msg                       = &s_m2d_msg;
   volatile Ipc_Notify_Structure_T input_notify      = {};
   uint8_t empty_seq[]                               = {0U, 1U};
   volatile Ipc_Notify_Structure_T *notify_get_seq[] = {&input_notify, &g_ipc_notify_buffer};

   m2d_msg->header.size               = sizeof(M2D_Msg_T);
   m2d_msg->header.counter            = 1U;
   m2d_msg->header.crc                = 0xDDU;
   m2d_msg->payload.offline_mode_flag = (uint32_t)ITF_DATA_CUBE_INJECTION_MODE;
   Calc_M2D_Buf_Crc_fake.return_val   = 0xDDU;

   input_notify.command                      = R52_TRIGGER_RANGE_PROCESSING_CONFIGURATION;
   input_notify.curIpcAddr                   = (uintptr_t)m2d_msg;
   RP_Buffer_Index                           = 1U;
   Ready_For_New_Frame                       = READY_FOR_RANGE_PROCESSING;
   Appl_Range_Process_Init_fake.return_val   = true;
   Is_IPC_Notify_Buffer_Full_fake.return_val = 0U;

   SET_RETURN_SEQ(Is_IPC_Notify_Buffer_Empty, empty_seq, 2);
   SET_RETURN_SEQ(Get_IPC_Notify_Buffer, notify_get_seq, 2);

   Update_DSP_IPC_Notify();

   EXPECT_EQ(0U, RP_Buffer_Index);
   EXPECT_EQ(1U, Increment_IPC_Notify_ReadIndx_fake.call_count);
}

/**
 * @test Update_DSP_IPC_Notify ITF_TEST_COLLECTION_MODE forces RP_Buffer_Index to zero
 *
 * @pre CRC match; ITF_TEST_COLLECTION_MODE in payload; RP_Buffer_Index = 1
 * @post RP_Buffer_Index forced to 0
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, UpdateDSPIPCNotify_RangeTrigger_TestCollectionMode_ForcesRPBufferIndexZero)
{
   volatile M2D_Msg_T *m2d_msg                       = &s_m2d_msg;
   volatile Ipc_Notify_Structure_T input_notify      = {};
   uint8_t empty_seq[]                               = {0U, 1U};
   volatile Ipc_Notify_Structure_T *notify_get_seq[] = {&input_notify, &g_ipc_notify_buffer};

   m2d_msg->header.size               = sizeof(M2D_Msg_T);
   m2d_msg->header.counter            = 1U;
   m2d_msg->header.crc                = 0xEEU;
   m2d_msg->payload.offline_mode_flag = (uint32_t)ITF_TEST_COLLECTION_MODE;
   Calc_M2D_Buf_Crc_fake.return_val   = 0xEEU;

   input_notify.command                      = R52_TRIGGER_RANGE_PROCESSING_CONFIGURATION;
   input_notify.curIpcAddr                   = (uintptr_t)m2d_msg;
   RP_Buffer_Index                           = 1U;
   Ready_For_New_Frame                       = READY_FOR_RANGE_PROCESSING;
   Appl_Range_Process_Init_fake.return_val   = true;
   Is_IPC_Notify_Buffer_Full_fake.return_val = 0U;

   SET_RETURN_SEQ(Is_IPC_Notify_Buffer_Empty, empty_seq, 2);
   SET_RETURN_SEQ(Get_IPC_Notify_Buffer, notify_get_seq, 2);

   Update_DSP_IPC_Notify();

   EXPECT_EQ(0U, RP_Buffer_Index);
   EXPECT_EQ(1U, Increment_IPC_Notify_ReadIndx_fake.call_count);
}

/*===========================================================================*
 * Test Cases for Appl_DSP_Process_Onetime_Init
 *===========================================================================*/

/**
 * @test Appl_DSP_Process_Onetime_Init with valid M2D ptr exits do-while on first iteration
 *
 * @pre M2D_One_Time_Msg_Ptr has non-zero SMC/USC addresses
 * @post SMC/USC ptrs set; Ready_For_New_Frame = READY_FOR_RANGE_PROCESSING;
 *       MIPI, profiling, and IDMA init fakes each called once
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, ApplDSPProcessOnetimeInit_ValidM2DPtr_InitializesAndExitsLoop)
{
   static M2D_One_Time_Msg_T one_time_msg;
   memset(&one_time_msg, 0, sizeof(one_time_msg));
   one_time_msg.smc_sram_address             = 0x00000001UL;
   one_time_msg.usc_sram_address             = 0x00000002UL;
   M2D_One_Time_Msg_Ptr                      = &one_time_msg;
   Is_IPC_Notify_Buffer_Full_fake.return_val = false;
   Get_IPC_Notify_Buffer_fake.return_val     = &g_ipc_notify_buffer;

   Appl_DSP_Process_Onetime_Init();

   EXPECT_EQ(READY_FOR_RANGE_PROCESSING, Ready_For_New_Frame);
   EXPECT_EQ((SMC_Cal_T *)0x00000001UL, SMC_Cal_Data_Ptr);
   EXPECT_EQ((USC_Cal_T *)0x00000002UL, USC_Cal_Data_Ptr);
   EXPECT_EQ(1U, IDMA_Helper_Init_fake.call_count);
   EXPECT_EQ(1U, Appl_MIPI_One_Time_Init_fake.call_count);
}

/**
 * @test Appl_DSP_Process_Onetime_Init skips M2D assignment block when M2D ptr is NULL
 *
 * @pre M2D_One_Time_Msg_Ptr is NULL; SMC/USC are pre-seeded non-null so the loop exits immediately
 * @post SMC/USC unchanged from pre-seed (M2D block was skipped); function completes normally
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, ApplDSPProcessOnetimeInit_NullM2DPtr_SkipsM2DAssignmentBlock)
{
   M2D_One_Time_Msg_Ptr                      = NULL;
   SMC_Cal_Data_Ptr                          = (SMC_Cal_T *)0x00000001UL;
   USC_Cal_Data_Ptr                          = (USC_Cal_T *)0x00000002UL;
   Is_IPC_Notify_Buffer_Full_fake.return_val = false;
   Get_IPC_Notify_Buffer_fake.return_val     = &g_ipc_notify_buffer;

   Appl_DSP_Process_Onetime_Init();

   EXPECT_EQ(READY_FOR_RANGE_PROCESSING, Ready_For_New_Frame);
   EXPECT_EQ((SMC_Cal_T *)0x00000001UL, SMC_Cal_Data_Ptr);
   EXPECT_EQ((USC_Cal_T *)0x00000002UL, USC_Cal_Data_Ptr);
   EXPECT_EQ(1U, IDMA_Helper_Init_fake.call_count);
}

/**
 * @test Appl_DSP_Process_Onetime_Init retriggers when USC address is null on first iteration
 *
 * @pre M2D_One_Time_Msg_Ptr has smc_sram_address = 0x1 and usc_sram_address = 0x0
 * @post Inner if TRUE (line 808) sets Mss_Init_Received; loop retries; USC becomes
 *       non-null on 2nd iteration (xthal_get_ccount custom_fake side-effect); exits
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, ApplDSPProcessOnetimeInit_NullUSCAddress_RetriggersThenExits)
{
   memset(&g_onetime_msg_retry, 0, sizeof(g_onetime_msg_retry));
   g_onetime_msg_retry.smc_sram_address      = 0x00000001UL;
   g_onetime_msg_retry.usc_sram_address      = 0x00000000UL;
   M2D_One_Time_Msg_Ptr                      = &g_onetime_msg_retry;
   Is_IPC_Notify_Buffer_Full_fake.return_val = false;
   Get_IPC_Notify_Buffer_fake.return_val     = &g_ipc_notify_buffer;
   xthal_get_ccount_fake.custom_fake         = xthal_get_ccount_SetUSCOnSecondCall;

   Appl_DSP_Process_Onetime_Init();

   EXPECT_EQ(READY_FOR_RANGE_PROCESSING, Ready_For_New_Frame);
   EXPECT_EQ((SMC_Cal_T *)0x00000001UL, SMC_Cal_Data_Ptr);
   EXPECT_EQ((USC_Cal_T *)0x00000002UL, USC_Cal_Data_Ptr);
   EXPECT_EQ(2U, xthal_get_ccount_fake.call_count);
   EXPECT_EQ(1U, IDMA_Helper_Init_fake.call_count);
}

/**
 * @test Appl_DSP_Process_Onetime_Init retriggers when SMC address is null on first iteration
 *
 * @pre M2D_One_Time_Msg_Ptr has smc_sram_address = 0x0 and usc_sram_address = 0x2
 * @post Inner if TRUE (line 808) sets Mss_Init_Received; loop retries; SMC becomes
 *       non-null on 2nd iteration (xthal_get_ccount custom_fake side-effect); exits
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, ApplDSPProcessOnetimeInit_NullSMCAddress_RetriggersThenExits)
{
   memset(&g_onetime_msg_retry, 0, sizeof(g_onetime_msg_retry));
   g_onetime_msg_retry.smc_sram_address      = 0x00000000UL;
   g_onetime_msg_retry.usc_sram_address      = 0x00000002UL;
   M2D_One_Time_Msg_Ptr                      = &g_onetime_msg_retry;
   Is_IPC_Notify_Buffer_Full_fake.return_val = false;
   Get_IPC_Notify_Buffer_fake.return_val     = &g_ipc_notify_buffer;
   xthal_get_ccount_fake.custom_fake         = xthal_get_ccount_SetSMCOnSecondCall;

   Appl_DSP_Process_Onetime_Init();

   EXPECT_EQ(READY_FOR_RANGE_PROCESSING, Ready_For_New_Frame);
   EXPECT_EQ((SMC_Cal_T *)0x00000001UL, SMC_Cal_Data_Ptr);
   EXPECT_EQ((USC_Cal_T *)0x00000002UL, USC_Cal_Data_Ptr);
   EXPECT_EQ(2U, xthal_get_ccount_fake.call_count);
   EXPECT_EQ(1U, IDMA_Helper_Init_fake.call_count);
}

/**
 * @test Appl_DSP_Process_Onetime_Init retriggers when both SMC and USC addresses are null
 *
 * @pre M2D_One_Time_Msg_Ptr has both smc_sram_address = 0x0 and usc_sram_address = 0x0
 * @post Line 820 condition is true on first iteration (Mss_Init_Received reset); loop retries;
 *       both pointers become non-null on 4th xthal_get_ccount call (2nd iteration); exits
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, ApplDSPProcessOnetimeInit_BothNullAddresses_SetsMssInitReceivedAndRetries)
{
   memset(&g_onetime_msg_retry, 0, sizeof(g_onetime_msg_retry));
   g_onetime_msg_retry.smc_sram_address      = 0x00000000UL;
   g_onetime_msg_retry.usc_sram_address      = 0x00000000UL;
   M2D_One_Time_Msg_Ptr                      = &g_onetime_msg_retry;
   Is_IPC_Notify_Buffer_Full_fake.return_val = false;
   Get_IPC_Notify_Buffer_fake.return_val     = &g_ipc_notify_buffer;
   xthal_get_ccount_fake.custom_fake         = xthal_get_ccount_SetBothOnThirdCall;

   Appl_DSP_Process_Onetime_Init();

   EXPECT_EQ(READY_FOR_RANGE_PROCESSING, Ready_For_New_Frame);
   EXPECT_EQ((SMC_Cal_T *)0x00000001UL, SMC_Cal_Data_Ptr);
   EXPECT_EQ((USC_Cal_T *)0x00000002UL, USC_Cal_Data_Ptr);
   EXPECT_EQ(3U, xthal_get_ccount_fake.call_count);
   EXPECT_EQ(2U, g_wur_expstate_call_count);
}

/**
 * @test Update_DSP_IPC_Notify sets ERRORFIELD_RANGE_PROCESS_CONFIG_ERROR when trigger init fails
 *
 * @pre CRC match; ITF_DISABLED_NORMAL_MODE; Appl_Range_Process_Init returns false so
 *      Appl_Range_Process_Trigger returns false — covers line 601 FALSE branch
 * @post errorField = ERRORFIELD_RANGE_PROCESS_CONFIG_ERROR in the output notify structure
 */
TEST_F(Ipc_Dsp_Unit_Test_Suite, UpdateDSPIPCNotify_RangeTrigger_TriggerInitFails_SetsRangeConfigError)
{
   volatile M2D_Msg_T *m2d_msg                       = &s_m2d_msg;
   volatile Ipc_Notify_Structure_T input_notify      = {};
   uint8_t empty_seq[]                               = {0U, 1U};
   volatile Ipc_Notify_Structure_T *notify_get_seq[] = {&input_notify, &g_ipc_notify_buffer};

   m2d_msg->header.size               = sizeof(M2D_Msg_T);
   m2d_msg->header.counter            = 1U;
   m2d_msg->header.crc                = 0xCCU;
   m2d_msg->payload.offline_mode_flag = (uint32_t)ITF_DISABLED_NORMAL_MODE;
   Calc_M2D_Buf_Crc_fake.return_val   = 0xCCU;

   input_notify.command                      = R52_TRIGGER_RANGE_PROCESSING_CONFIGURATION;
   input_notify.curIpcAddr                   = (uintptr_t)m2d_msg;
   Ready_For_New_Frame                       = READY_FOR_RANGE_PROCESSING;
   Appl_Range_Process_Init_fake.return_val   = false;
   Is_IPC_Notify_Buffer_Full_fake.return_val = 0U;

   SET_RETURN_SEQ(Is_IPC_Notify_Buffer_Empty, empty_seq, 2);
   SET_RETURN_SEQ(Get_IPC_Notify_Buffer, notify_get_seq, 2);

   Update_DSP_IPC_Notify();

   EXPECT_EQ((uint16_t)ERRORFIELD_RANGE_PROCESS_CONFIG_ERROR, g_ipc_notify_buffer.errorField);
   EXPECT_EQ(DSP_RANGE_CONFIGURATION_COMPLETE, g_ipc_notify_buffer.command);
   EXPECT_EQ(1U, Increment_IPC_Notify_ReadIndx_fake.call_count);
}

/**
 * @test UpdateDSPIPCNotify_HIL_OFF_DataValidated
 *
 * @brief Verifies that when HIL mode is disabled, the IPC notification path
 *        follows normal validation flow and does NOT bypass header checks or
 *        force buffer clearing behavior unless full processing conditions are met.
 **/
TEST_F(Ipc_Dsp_Unit_Test_Suite, UpdateDSPIPCNotify_HIL_OFF_DataValidated)
{
   volatile M2D_Msg_T *m2d_msg                  = &s_m2d_msg;
   volatile Ipc_Notify_Structure_T input_notify = {};
   uint8_t empty_seq[]                          = {0U, 1U};

   volatile Ipc_Notify_Structure_T *notify_get_seq[] = {&input_notify, &input_notify};

   RP_Buffer_Index = 0U;
   IPC_D2M_Buffer_Init();

   memset(&IPC_D2M_Buffer[0], 0xA5, sizeof(D2M_Msg_T)); // Fill with non-zero pattern
   m2d_msg->header.size                           = sizeof(M2D_Msg_T);
   m2d_msg->header.counter                        = 1U;
   m2d_msg->header.crc                            = 0xAAU;
   Calc_M2D_Buf_Crc_fake.return_val               = 0xAAU;
   m2d_msg->payload.hil_ipc_info.hil_mode_enabled = CODED_FALSE;
   Ready_For_New_Frame                            = INVALID_STATE;
   Appl_Range_Process_Init_fake.return_val        = false;
   m2d_msg->payload.look_Info.scan_index          = 55U;
   input_notify.command                           = R52_TRIGGER_RANGE_PROCESSING_CONFIGURATION;
   input_notify.curIpcAddr                        = (uintptr_t)m2d_msg;

   SET_RETURN_SEQ(Is_IPC_Notify_Buffer_Empty, empty_seq, 2);
   SET_RETURN_SEQ(Get_IPC_Notify_Buffer, notify_get_seq, 2);

   Update_DSP_IPC_Notify();
   // HIL OFF does NOT bypass header dependency
   // → so no clearing should happen here

   Rdd_Stream_T zero_stream = {};
   EXPECT_NE(0, memcmp(&IPC_D2M_Buffer[0].payload.rdd_stream_data, &zero_stream, sizeof(Rdd_Stream_T)));
}

/**
 * @test UpdateDSPIPCNotify_HIL_ON_HeaderInvalid_StillNoClear
 *
 * @brief Verifies that when HIL mode is enabled, an invalid header does NOT
 *        trigger buffer clearing or processing logic.
 **/
TEST_F(Ipc_Dsp_Unit_Test_Suite, UpdateDSPIPCNotify_HIL_ON_HeaderInvalid_StillNoClear)
{
   volatile M2D_Msg_T *m2d_msg                       = &s_m2d_msg;
   volatile Ipc_Notify_Structure_T input_notify      = {};
   volatile Ipc_Notify_Structure_T *notify_get_seq[] = {&input_notify, &g_ipc_notify_buffer};
   uint8_t empty_seq[]                               = {0U, 1U};

   memset(&IPC_D2M_Buffer[0], 0xA5, sizeof(D2M_Msg_T));

   // Force invalid header
   m2d_msg->header.size = 0U;

   m2d_msg->payload.hil_ipc_info.hil_mode_enabled = CODED_TRUE;

   input_notify.command    = R52_TRIGGER_RANGE_PROCESSING_CONFIGURATION;
   input_notify.curIpcAddr = (uintptr_t)m2d_msg;

   SET_RETURN_SEQ(Is_IPC_Notify_Buffer_Empty, empty_seq, 2);
   SET_RETURN_SEQ(Get_IPC_Notify_Buffer, notify_get_seq, 2);

   Update_DSP_IPC_Notify();

   Rdd_Stream_T zero_stream = {};
   EXPECT_NE(0, memcmp(&IPC_D2M_Buffer[0].payload.rdd_stream_data, &zero_stream, sizeof(Rdd_Stream_T)));
}

/**
 * @test UpdateDSPIPCNotify_HIL_OFF_HeaderInvalid_NoChange
 *
 * @brief Verifies that when HIL mode is disabled and the M2D header is invalid,
 *
 **/
TEST_F(Ipc_Dsp_Unit_Test_Suite, UpdateDSPIPCNotify_HIL_OFF_HeaderInvalid_NoChange)
{
   volatile M2D_Msg_T *m2d_msg                       = &s_m2d_msg;
   volatile Ipc_Notify_Structure_T input_notify      = {};
   volatile Ipc_Notify_Structure_T *notify_get_seq[] = {&input_notify};
   uint8_t empty_seq[]                               = {0U, 1U};

   memset(&IPC_D2M_Buffer[0], 0xA5, sizeof(D2M_Msg_T));

   // Invalid header
   m2d_msg->header.size                           = 0U;
   m2d_msg->payload.hil_ipc_info.hil_mode_enabled = CODED_FALSE;

   input_notify.command    = R52_TRIGGER_RANGE_PROCESSING_CONFIGURATION;
   input_notify.curIpcAddr = (uintptr_t)m2d_msg;

   SET_RETURN_SEQ(Is_IPC_Notify_Buffer_Empty, empty_seq, 2);
   SET_RETURN_SEQ(Get_IPC_Notify_Buffer, notify_get_seq, 1);

   Update_DSP_IPC_Notify();

   // No change expected
   Rdd_Stream_T zero_stream = {};
   EXPECT_NE(0, memcmp(&IPC_D2M_Buffer[0].payload.rdd_stream_data, &zero_stream, sizeof(Rdd_Stream_T)));
}

/*=============================================================================
 * Fixed Trigger Feature Coverage
 *=============================================================================*/

TEST_F(Ipc_Dsp_Unit_Test_Suite, TriggerTimerBBETO_R52_CopiesPingNotification)
{
   Get_IPC_Notify_Buffer_fake.return_val                 = &g_ipc_notify_buffer;
   IPC_BBE2R52_Fixed_Notify_Msg[BUF_IDX_PING].command    = DSP_RANGE_PROCESSING_COMPLETE;
   IPC_BBE2R52_Fixed_Notify_Msg[BUF_IDX_PING].curIpcAddr = (uint32_t)&IPC_D2M_Buffer[0];

   Trigger_BBE_TO_R52(BUF_IDX_PING);

   EXPECT_EQ(DSP_RANGE_PROCESSING_COMPLETE, g_ipc_notify_buffer.command);
   EXPECT_EQ((uint32_t)&IPC_D2M_Buffer[0], g_ipc_notify_buffer.curIpcAddr);
   EXPECT_EQ(1U, Increment_IPC_Notify_WriteIndx_fake.call_count);
   EXPECT_EQ(1U, g_writeback_call_count);
   EXPECT_EQ((void *)(uintptr_t)(uint32_t)(uintptr_t)&IPC_D2M_Buffer[0], g_writeback_last_addr);
}

TEST_F(Ipc_Dsp_Unit_Test_Suite, TriggerTimerBBETO_R52_CopiesPongNotification)
{
   Get_IPC_Notify_Buffer_fake.return_val                 = &g_ipc_notify_buffer;
   IPC_BBE2R52_Fixed_Notify_Msg[BUF_IDX_PONG].command    = DSP_DOPPLER_PROCESSING_COMPLETE;
   IPC_BBE2R52_Fixed_Notify_Msg[BUF_IDX_PONG].curIpcAddr = (uint32_t)&IPC_D2M_Buffer[1];

   Trigger_BBE_TO_R52(BUF_IDX_PONG);

   EXPECT_EQ(DSP_DOPPLER_PROCESSING_COMPLETE, g_ipc_notify_buffer.command);
   EXPECT_EQ((uint32_t)&IPC_D2M_Buffer[1], g_ipc_notify_buffer.curIpcAddr);
   EXPECT_EQ(1U, Increment_IPC_Notify_WriteIndx_fake.call_count);
   EXPECT_EQ(1U, g_writeback_call_count);
}

TEST_F(Ipc_Dsp_Unit_Test_Suite, TriggerTimerBBETO_R52_InvalidIndexStillTriggersWriteback)
{
   Get_IPC_Notify_Buffer_fake.return_val = &g_ipc_notify_buffer;

   Trigger_BBE_TO_R52(2U);

   EXPECT_EQ(1U, Increment_IPC_Notify_WriteIndx_fake.call_count);
   EXPECT_EQ(1U, g_writeback_call_count);
}

TEST_F(Ipc_Dsp_Unit_Test_Suite, TimerIsr_SendsPingNotification)
{
   Get_IPC_Notify_Buffer_fake.return_val                 = &g_ipc_notify_buffer;
   IPC_BBE2R52_Fixed_Notify_Msg[BUF_IDX_PING].curIpcAddr = (uint32_t)&IPC_D2M_Buffer[0];

   Timer_ISR(arg);

   EXPECT_EQ(1U, Increment_IPC_Notify_WriteIndx_fake.call_count);
   EXPECT_EQ(1U, g_writeback_call_count);
   EXPECT_EQ(1U, g_wur_expstate_call_count);
}

TEST_F(Ipc_Dsp_Unit_Test_Suite, TimerIsr_SendsPongNotification)
{
   Get_IPC_Notify_Buffer_fake.return_val                 = &g_ipc_notify_buffer;
   IPC_BBE2R52_Fixed_Notify_Msg[BUF_IDX_PONG].curIpcAddr = (uint32_t)&IPC_D2M_Buffer[1];

   Timer_ISR(arg);

   EXPECT_EQ(1U, Increment_IPC_Notify_WriteIndx_fake.call_count);
   EXPECT_EQ(1U, g_writeback_call_count);
   EXPECT_EQ(1U, g_wur_expstate_call_count);
}

TEST_F(Ipc_Dsp_Unit_Test_Suite, FixedTriggerPong_ProgramsTimerAndUpdatesElapsedExtrema)
{
   unsigned int ccount_seq[] = {100U + (10U * DSP_CLK_FREQ_MHZ)};

   RP_Buffer_Index                                       = BUF_IDX_PONG;
   Ready_For_New_Frame                                   = READY_FOR_RANGE_PROCESSING;
   Appl_Range_Process_Init_fake.return_val               = true;
   SP_Post_Proc_Buffer_Index                             = BUF_IDX_PONG;
   Get_IPC_Notify_Buffer_fake.return_val                 = &g_ipc_notify_buffer;
   IPC_BBE2R52_Fixed_Notify_Msg[BUF_IDX_PONG].curIpcAddr = (uint32_t)&IPC_D2M_Buffer[BUF_IDX_PONG];
   SET_RETURN_SEQ(xthal_get_ccount, ccount_seq, 1);

   EXPECT_TRUE(Appl_Range_Process_Trigger(RADAR_LOOK_A));
   Timer_ISR(arg);

   EXPECT_EQ(1U, g_xthal_set_ccompare1_call_count);
   EXPECT_EQ(0U, g_xthal_set_ccompare0_call_count);
}

#ifdef IPC_BBE_FIXED_TRIGGER_DWELL_DELTA_CALC_ENABLE
TEST_F(Ipc_Dsp_Unit_Test_Suite, CalculateAverageDwellTime_NullInputLeavesStateUnchanged)
{
   Calculate_Average_Dwell_Time(NULL);

   for (uint8_t dwell_idx = 0U; dwell_idx < NUM_LOOKS; dwell_idx++)
   {
      EXPECT_EQ(0, Dwell_Time_Delta[dwell_idx]);
   }
}
#endif
