/*===========================================================================*/
/**
 * @file dsp_setup_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitive Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for dsp_setup module public APIs.
 *
 */
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
#include <cstddef>
#include <cstring>
#include <gtest/gtest.h>

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "Rte_SWC_PLT_CDD_Radar_Control_fake.h"
#include "SWC_PLT_CDD_ECUSync_external_fake.h"
#include "crg_sfrs.h"
#include "dd_mmic_fake.h"
#include "debug_stream.h"
#include "dsp_sfrs.h"
#include "ipc_data_fake.h"
#include "ipc_mss_mocks.h"
#include "platformtime_fff.h"
#include "program_flow_monitor_fff.h"
#include "sh_comm.h"
#include "sh_rx_mocks.h"
#include "timers_sfrs.h"

/*===========================================================================*
 * C Header Files
 *===========================================================================*/
static DSP_SFRS_t g_dsp_ctrl_regs;
static CRG_SFRS_t g_crg_ctrl_regs;
static TIMERS_SFRS_t g_timer_ctrl_regs;
static SH_Output_T g_sh_output_data;
static volatile M2D_Msg_T g_mss_m2d_msg;

/* Include the test-local Generic_Drv_sfr.h stub first to set the
 * GENERIC_DRV_SFR_H include guard. Then override DSP_base / CRG_base
 * with pointers to the local test variables. When dsp_setup.c later
 * includes Generic_Drv_sfr.h internally the guard blocks re-processing,
 * so the overrides below survive. */
#include "chandra_sfrs_base.h"
#undef DSP_base
#define DSP_base (&g_dsp_ctrl_regs)
#undef CRG_base
#define CRG_base (&g_crg_ctrl_regs)
#undef TIMERS_base
#define TIMERS_base (&g_timer_ctrl_regs)

extern "C"
{
#include "dsp_setup.c"
}

/*===========================================================================*
 * Valid Configuration For Tests
 *===========================================================================*/
DEFINE_FFF_GLOBALS;

extern "C"
{
   bool Received_Doppler_Done                 = false;
   volatile bool Received_Doppler_Stream      = false;
   volatile DSP_Config_Type_T DSP_Cfg_Init    = DSP_CONFIG_NO_ERROR;
   volatile bool DSP_Init                     = false;
   uint32_t M2D_Buffer_Full_Error_Counter     = 0U;
   D2M_Msg_T *IPC_Dopp_RDD_Comp_Buf_Read_Addr = nullptr;
   uint16_t DSP_No_Command_Cnt                = 0U;
   uint32_t IPC_M2D_Crc_Err_Cnt               = 0U;
   IPC_M2D_Buffers_T IPC_M2D_Buffers;
   uint32_t Ping_Buf_Addr                    = 0U;
   uint32_t Pong_Buf_Addr                    = 0U;
   uint32_t PSP_Ping_Buf_Addr                = 0U;
   uint32_t PSP_Pong_Buf_Addr                = 0U;
   uint8_t IPC_Sp_Post_Proc_Buf_Read_idx     = 0U;
   D2M_Msg_T *IPC_Sp_Post_Proc_Buf_Read_Addr = nullptr;
   MMIC_Temp_Stats_T MMIC_Temperature        = {0};
}

IPC_MMIC_Radar_Data_Status_T Radar_Data_Status                     = {0};
Radar_Ctl_Data_T Radar_Ctl_Data                                    = {0};
Radar_Ctl_State_T Radar_Ctl_State                                  = RADAR_CTL_OFF;
volatile XCP_Single_Look_Type_Enable_T XCP_Single_Look_Type_Enable = RADAR_CTL_NO_FORCE_LOOK_TYPE;
volatile Radar_Look_T XCP_Single_Look_Type                         = (Radar_Look_T)0;
volatile bool XCP_Force_Radar_On                                   = false;
uint8_t RC_Skip_Look                                               = 0U;
DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_Radar_Position);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_Radar_Position);
DECLARE_FAKE_VALUE_FUNC(SH_Output_T *, Get_SH_Output_Data_Ptr);
DEFINE_FAKE_VALUE_FUNC(SH_Output_T *, Get_SH_Output_Data_Ptr);

static uint64_t g_platform_ustime_sequence[8]         = {0};
static size_t g_platform_ustime_sequence_len          = 0U;
static size_t g_platform_ustime_sequence_idx          = 0U;
static uint32_t g_platform_elapsed_ustime_sequence[8] = {0};
static size_t g_platform_elapsed_ustime_sequence_len  = 0U;
static size_t g_platform_elapsed_ustime_sequence_idx  = 0U;

static void Get_Platform_ustime_Sequence_Fake(uint64_t *out_us)
{
   if (out_us != nullptr)
   {
      if (g_platform_ustime_sequence_idx < g_platform_ustime_sequence_len)
      {
         *out_us = g_platform_ustime_sequence[g_platform_ustime_sequence_idx];
         g_platform_ustime_sequence_idx++;
      }
      else
      {
         *out_us = 0U;
      }
   }
}

static void Get_Platform_Elapsed_ustime_Sequence_Fake(uint32_t *out_us, uint64_t start_us)
{
   (void)start_us;
   if (out_us != nullptr)
   {
      if (g_platform_elapsed_ustime_sequence_idx < g_platform_elapsed_ustime_sequence_len)
      {
         *out_us = g_platform_elapsed_ustime_sequence[g_platform_elapsed_ustime_sequence_idx];
         g_platform_elapsed_ustime_sequence_idx++;
      }
      else
      {
         *out_us = 0U;
      }
   }
}

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class Dsp_Setup_Unit_Test_Suite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      memset(&g_dsp_ctrl_regs, 0, sizeof(g_dsp_ctrl_regs));
      memset(&g_crg_ctrl_regs, 0, sizeof(g_crg_ctrl_regs));
      memset(&g_timer_ctrl_regs, 0, sizeof(g_timer_ctrl_regs));

      RESET_IPC_DATA_MOCKS(RESET_FAKE);
      FFF_FAKES_RTE_SWC_PLT_CDD_RADAR_CONTROL(RESET_FAKE);
      FFF_FAKES_SWC_PLT_CDD_ECUSYNC(RESET_FAKE);
      RESET_FAKE(Get_SH_Output_Data_Ptr);
      RESET_FAKE(Get_MSS_IPC_M2D_Msg_Buffer);
      FFF_FAKES_STREAM_HANDLER_RX_LIST(RESET_FAKE);
      FFF_FAKES_PROGRAM_FLOW_MONITOR_LIST(RESET_FAKE);
      FFF_FAKES_IPC_MSS_LIST(RESET_FAKE);
      FFF_FAKES_PLATFORMTIME_LIST(RESET_FAKE);
      RESET_FAKE(Get_Radar_Position);
      RESET_FAKE(Compute_MMIC_On_Chip_Temperature);
      FFF_RESET_HISTORY();

      Init_platformtime_fff_defaults();

      Get_Received_Doppler_Done_fake.return_val         = false;
      Get_DSP_Init_Status_fake.return_val               = false;
      Get_DSP_Cfg_Init_fake.return_val                  = DSP_CONFIG_NO_ERROR;
      Get_M2D_Buffer_Full_Error_Counter_fake.return_val = 0U;

      DSP_Init                        = false;
      DSP_Cfg_Init                    = DSP_CONFIG_NO_ERROR;
      Received_Doppler_Done           = false;
      Received_Doppler_Stream         = false;
      M2D_Buffer_Full_Error_Counter   = 0U;
      M2D_DSP_Not_Ready_Counter       = 0U;
      Dsp_Cfg_Error_Counter           = 0U;
      DSP_Processing_Error_Counter    = 0U;
      DSP_Reset_Counter               = 0U;
      DSP_No_Command_Cnt              = 0U;
      R52_M2D_Buffer_Index            = 0U;
      R52_M2D_Msg_Header_Cnt          = 0U;
      DSP_Current_State               = DSP_CORE_INITIALIZE;
      IPC_Sp_Post_Proc_Buf_Read_Addr  = nullptr;
      IPC_Dopp_RDD_Comp_Buf_Read_Addr = nullptr;

      Get_Radar_Position_fake.return_val             = 1U;
      Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = &IPC_M2D_Buffers.IPC_M2D_One_Time_Init_Data;
      Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val     = &g_mss_m2d_msg;
      memset((void *)&g_mss_m2d_msg, 0, sizeof(g_mss_m2d_msg));
      memset(Frame_Time_Buffer, 0, sizeof(Frame_Time_Buffer));
      memset(&g_sh_output_data, 0, sizeof(g_sh_output_data));
      g_sh_output_data.sh_get_stream_rx_info_data_fptr = Get_Stream_Rx_Info_Data_Ptr;
      Get_SH_Output_Data_Ptr_fake.return_val           = &g_sh_output_data;
      memset(g_platform_ustime_sequence, 0, sizeof(g_platform_ustime_sequence));
      g_platform_ustime_sequence_len = 0U;
      g_platform_ustime_sequence_idx = 0U;
      memset(g_platform_elapsed_ustime_sequence, 0, sizeof(g_platform_elapsed_ustime_sequence));
      g_platform_elapsed_ustime_sequence_len = 0U;
      g_platform_elapsed_ustime_sequence_idx = 0U;
   }

   /**
    * @b Description
    * @n
    *    Method run after each individual test case.
    */
   void TearDown()
   {
   }
};

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

/* -------------------------------------------------------------------------
 * DSP_Done_Processing
 * ------------------------------------------------------------------------- */

/**
 *  @b dsp_done_processing_01
 *  @n
 *      DSP_Done_Processing should return true when Received_Doppler_Done is true.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, DspDoneProcessing_ReceivedDopplerDoneTrue_ReturnsTrue)
{
   Get_Received_Doppler_Done_fake.return_val = true;
   EXPECT_TRUE(DSP_Done_Processing());
}

/**
 *  @b dsp_done_processing_02
 *  @n
 *      DSP_Done_Processing should return false when Received_Doppler_Done is false.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, DspDoneProcessing_ReceivedDopplerDoneFalse_ReturnsFalse)
{
   Get_Received_Doppler_Done_fake.return_val = false;
   EXPECT_FALSE(DSP_Done_Processing());
}

/* -------------------------------------------------------------------------
 * Release_BBE32_From_Stall
 * ------------------------------------------------------------------------- */

/**
 *  @b release_bbe32_from_stall_01
 *  @n
 *      Release_BBE32_From_Stall should clear the DSP RUNSTALL bit to release the core.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, ReleaseBbe32FromStall_RunstallSet_ClearsRunstallBit)
{
   Dsp_Base_Ptr->DSP_CTRL.f.RUNSTALL = 1U;

   Release_BBE32_From_Stall();

   EXPECT_EQ((uint32_t)Dsp_Base_Ptr->DSP_CTRL.f.RUNSTALL, 0U);
}

/* -------------------------------------------------------------------------
 * Perform_Chandra_Reset
 * ------------------------------------------------------------------------- */

/**
 *  @b perform_chandra_reset_01
 *  @n
 *      Perform_Chandra_Reset should set the CRG RESET_ALL bit to reset the entire Chandra subsystem.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, PerformChandraReset_ResetAllClear_SetsResetAll)
{
   Crg_Ptr->RESET_ALL = 0U;

   Perform_Chandra_Reset();

   EXPECT_EQ(Crg_Ptr->RESET_ALL, 1U);
}

/* -------------------------------------------------------------------------
 * Perform_BBE32_Reset
 * ------------------------------------------------------------------------- */

/**
 *  @b perform_bbe32_reset_01
 *  @n
 *      Perform_BBE32_Reset should stall the core, reset it, and clear DSP_Init flag.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, PerformBbe32Reset_DspInitTrue_StallsCoreResetsClearsDspInit)
{
   bool result = Perform_BBE32_Reset();

   EXPECT_TRUE(result);
   EXPECT_EQ((uint32_t)Dsp_Base_Ptr->DSP_CTRL.f.RUNSTALL, 1U);
   EXPECT_EQ(Set_DSP_Init_Status_fake.call_count, 1U);
   EXPECT_FALSE(Set_DSP_Init_Status_fake.arg0_val);
}

/* -------------------------------------------------------------------------
 * Handle_Missed_DSP_Frame
 * ------------------------------------------------------------------------- */

/**
 *  @b handle_missed_dsp_frame_01
 *  @n
 *      Handle_Missed_DSP_Frame below threshold should increment error counter but not trigger reset.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, HandleMissedDspFrame_BelowThreshold_OnlyIncrementsErrorCounter)
{
   DSP_Processing_Error_Counter     = 0U;
   DSP_Processing_Error_Counter_Max = 5U;
   DSP_Reset_Counter                = 0U;

   Handle_Missed_DSP_Frame();

   EXPECT_EQ(DSP_Processing_Error_Counter, 1U);
   EXPECT_EQ(DSP_Reset_Counter, 0U);
   EXPECT_EQ(DSP_Current_State, DSP_CORE_INITIALIZE); /* unchanged from reset by SetUp */
}

/**
 *  @b handle_missed_dsp_frame_02
 *  @n
 *      Handle_Missed_DSP_Frame at threshold but below max resets should trigger BBE reset.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, HandleMissedDspFrame_AtThresholdBelowMaxResets_TriggersBbeReset)
{
   DSP_Processing_Error_Counter_Max = 2U;
   DSP_Processing_Error_Counter     = 1U; /* next increment meets threshold */
   DSP_Reset_Counter_Max            = 5U;
   DSP_Reset_Counter                = 2U;
   DSP_Current_State                = DSP_CORE_NORMAL_OPERATION;

   Handle_Missed_DSP_Frame();

   EXPECT_EQ(DSP_Current_State, DSP_CORE_INITIALIZE);
   EXPECT_EQ(DSP_Reset_Counter, 3U);
   EXPECT_EQ(Set_DSP_Init_Status_fake.call_count, 1U);
   EXPECT_FALSE(Set_DSP_Init_Status_fake.arg0_val);
   EXPECT_EQ((uint32_t)Dsp_Base_Ptr->DSP_CTRL.f.RUNSTALL, 1U);
}

/**
 *  @b handle_missed_dsp_frame_03
 *  @n
 *      Handle_Missed_DSP_Frame at max resets should trigger Chandra reset.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, HandleMissedDspFrame_AtThresholdAndMaxResets_TriggersChandraReset)
{
   DSP_Processing_Error_Counter_Max = 2U;
   DSP_Processing_Error_Counter     = 1U;
   DSP_Reset_Counter_Max            = 3U;
   DSP_Reset_Counter                = 3U;
   Crg_Ptr->RESET_ALL               = 0U;

   Handle_Missed_DSP_Frame();

   EXPECT_EQ(DSP_Current_State, DSP_CORE_INITIALIZE);
   EXPECT_EQ(Crg_Ptr->RESET_ALL, 1U);
   EXPECT_EQ(DSP_Reset_Counter, 3U); /* unchanged — Chandra path does not increment */
}

/* -------------------------------------------------------------------------
 * DSP_Processing_Onetime_Init
 * ------------------------------------------------------------------------- */

/**
 *  @b dsp_processing_onetime_init_01
 *  @n
 *      DSP_Processing_Onetime_Init should call all initialization functions and populate calibration addresses and radar position.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, DspProcessingOnetimeInit_CallsAllInitsAndPopulatesOnetimeBuffer)
{
   static volatile M2D_One_Time_Msg_T s_onetime_msg;
   memset((void *)&s_onetime_msg, 0, sizeof(s_onetime_msg));

   Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = &s_onetime_msg;
   Get_Radar_Position_fake.return_val             = 3U;

   DSP_Processing_Onetime_Init();

   EXPECT_EQ(IPC_M2D_Buffer_Init_fake.call_count, 1U);
   EXPECT_EQ(IPC_M2D_One_Time_Buffer_Init_fake.call_count, 1U);
   EXPECT_EQ(IPC_Notify_Buffer_Init_fake.call_count, 1U);
   EXPECT_EQ(s_onetime_msg.smc_sram_address, (uint32_t)Get_SMC_Cal_Data());
   EXPECT_EQ(s_onetime_msg.usc_sram_address, (uint32_t)Get_USC_Cal_Data());
   EXPECT_EQ(s_onetime_msg.radar_position, 3U);
}

TEST_F(Dsp_Setup_Unit_Test_Suite, DspProcessingOnetimeInit_NullBuffer_OnlyCallsInitFunctions)
{
   Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = nullptr;

   DSP_Processing_Onetime_Init();

   EXPECT_EQ(IPC_M2D_Buffer_Init_fake.call_count, 1U);
   EXPECT_EQ(IPC_M2D_One_Time_Buffer_Init_fake.call_count, 1U);
   EXPECT_EQ(IPC_Notify_Buffer_Init_fake.call_count, 1U);
   EXPECT_EQ(Get_Radar_Position_fake.call_count, 0U);
}

/* -------------------------------------------------------------------------
 * DSP_Processing_Per_Look_Init — branch coverage
 * ------------------------------------------------------------------------- */

/**
 *  @b per_look_init_01 (DDR-4176)
 *  @n
 *      DSP_Processing_Per_Look_Init when the IPC notify buffer is full must:
 *        - return false
 *        - retrieve the current counter via Get_M2D_Buffer_Full_Error_Counter()
 *        - write the incremented value via Set_M2D_Buffer_Full_Error_Counter()
 *      DDR-4176 replaced the direct `M2D_Buffer_Full_Error_Counter++` with the
 *      getter/setter pair to encapsulate the variable inside ipc_mss.c.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, PerLookInit_NotifyBufferFull_ReturnsFalseIncrementsFullCounter)
{
   Is_IPC_Notify_Buffer_Full_fake.return_val         = 1U;
   Get_M2D_Buffer_Full_Error_Counter_fake.return_val = 3U; /* arbitrary non-zero seed */

   EXPECT_FALSE(DSP_Processing_Per_Look_Init());

   /* DDR-4176: Get_ must be called once to read current value */
   EXPECT_EQ(Get_M2D_Buffer_Full_Error_Counter_fake.call_count, 1U);
   /* DDR-4176: Set_ must be called once with current+1 */
   EXPECT_EQ(Set_M2D_Buffer_Full_Error_Counter_fake.call_count, 1U);
   EXPECT_EQ(Set_M2D_Buffer_Full_Error_Counter_fake.arg0_val, 4U); /* seed 3 + 1 */
}

TEST_F(Dsp_Setup_Unit_Test_Suite, OnetimeInit_RadarPositionInvalid)
{
   const volatile M2D_One_Time_Msg_T *msg = &IPC_M2D_Buffers.IPC_M2D_One_Time_Init_Data;

   /* test too large position */
   Get_Radar_Position_fake.return_val = 15U;
   DSP_Processing_Onetime_Init();

   /* Verify Fascia Compensation is Disabled */
   EXPECT_EQ(IPC_M2D_Buffers.IPC_M2D_One_Time_Init_Data.fascia_compensation_params.axis_enable,
             (FC_Enable_Flag_T)NO_SLOPE_CORRECTION);

   /* test invalid/unknown position value */
   Get_Radar_Position_fake.return_val = 0U;
   DSP_Processing_Onetime_Init();

   /* Verify Fascia Compensation is Disabled */
   EXPECT_EQ(IPC_M2D_Buffers.IPC_M2D_One_Time_Init_Data.fascia_compensation_params.axis_enable,
             (FC_Enable_Flag_T)NO_SLOPE_CORRECTION);
}

/* Copilot generated, may need updates when preliminary implementation of SMC->IPC population function changes */
TEST_F(Dsp_Setup_Unit_Test_Suite, OnetimeInit_PopulatesOneTimeCalibPayload)
{
   const volatile M2D_One_Time_Msg_T *msg = &IPC_M2D_Buffers.IPC_M2D_One_Time_Init_Data;

   /* radar_position = 2 -> main_radar_position = 1 */
   Get_Radar_Position_fake.return_val = 2U;
   DSP_Processing_Onetime_Init();

   EXPECT_FLOAT_EQ(k_distance_front_bumper_to_rear_axle_smc,
                   msg->calib_data.vehicle_calib_data.k_distance_front_bumper_to_rear_axle);
   EXPECT_FLOAT_EQ(k_rear_cornering_complicane_smc, msg->calib_data.vehicle_calib_data.k_rear_cornering_compliance);
   EXPECT_FLOAT_EQ(k_steering_gear_ratio_smc, msg->calib_data.vehicle_calib_data.k_steering_gear_ratio);
   EXPECT_FLOAT_EQ(k_wheelbase_smc, msg->calib_data.vehicle_calib_data.k_wheelbase);
   EXPECT_FLOAT_EQ(k_vehicle_width_smc, msg->calib_data.vehicle_calib_data.k_vehicle_width);
   EXPECT_FLOAT_EQ(k_vehicle_length_smc, msg->calib_data.vehicle_calib_data.k_vehicle_length);

   EXPECT_FLOAT_EQ(k_sensor_mount_pos_x_list_smc[1], msg->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_x);
   EXPECT_FLOAT_EQ(k_sensor_mount_pos_y_list_smc[1], msg->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_y);
   EXPECT_FLOAT_EQ(k_sensor_mount_ornt_yaw_list_smc[1],
                   msg->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_yaw);
   EXPECT_FLOAT_EQ(fabsf(Fix2Float(k_vwrapping_smc[0], s10p21_T)), msg->calib_data.sensor_calib_data.k_vwrapping[0]);
   EXPECT_FLOAT_EQ(fabsf((float32_t)(k_rwrapping_smc[0] / (float32_t)(1ULL << 31))),
                   msg->calib_data.sensor_calib_data.k_rwrapping[0]);
   EXPECT_FLOAT_EQ(Fix2Float((int32_t)k_detection_range_max_smc[0], u9p7_T),
                   msg->calib_data.sensor_calib_data.k_detection_range_max[0]);

   EXPECT_EQ(CODED_TRUE, msg->calib_data.data_availability_status);
}

/* Copilot generated, may need updates when preliminary implementation of SMC->IPC population function changes */
TEST_F(Dsp_Setup_Unit_Test_Suite, OnetimeInit_RadarPositionFour_CoversMainPositionCaseThree)
{
   const volatile M2D_One_Time_Msg_T *msg = &IPC_M2D_Buffers.IPC_M2D_One_Time_Init_Data;

   /* radar_position = 3 (FRONT_RIGHT) -> partner = FRONT_LEFT(4), smc_index = 3 */
   Get_Radar_Position_fake.return_val = 3U;
   DSP_Processing_Onetime_Init();

   /* Sensor 0: main position 3, smc_index = 3-1 = 2 */
   EXPECT_FLOAT_EQ(k_sensor_mount_pos_x_list_smc[2], msg->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_x);
   EXPECT_FLOAT_EQ(k_sensor_mount_pos_y_list_smc[2], msg->calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_y);
}

/*===========================================================================*
 * Tests: Reset_IPC_M2D_Buffer — new API introduced by DDR-4176
 * IPC_M2D_Buffer_Init and Reset_IPC_M2D_Buffer are now implemented inside
 * ipc_mss.c and exposed as mocked APIs. Here we verify that
 * DSP_Processing_Onetime_Init calls IPC_M2D_Buffer_Init (and therefore
 * Reset_IPC_M2D_Buffer via that path) exactly once per call.
 *===========================================================================*/

TEST_F(Dsp_Setup_Unit_Test_Suite, OnetimeInit_CallsIpcM2DBufferInit_Once)
{
   /* DDR-4176: Reset_IPC_M2D_Buffer is a new API; IPC_M2D_Buffer_Init is now
    * the sole caller of it.  Verify that DSP_Processing_Onetime_Init triggers
    * exactly one call to IPC_M2D_Buffer_Init so the buffer ownership contract
    * is maintained. */
   DSP_Processing_Onetime_Init();

   EXPECT_EQ(IPC_M2D_Buffer_Init_fake.call_count, 1U);
}

/*===========================================================================*
 * Tests: DSP_Processing_Per_Look_Init – IPC Buffer Full path
 *===========================================================================*/

TEST_F(Dsp_Setup_Unit_Test_Suite, PerLookInit_BufferFull_ReturnsFalseAndIncrementsCounter)
{
   Is_IPC_Notify_Buffer_Full_fake.return_val         = 1U;
   Get_M2D_Buffer_Full_Error_Counter_fake.return_val = 0U;

   EXPECT_FALSE(DSP_Processing_Per_Look_Init());
   EXPECT_EQ(Get_M2D_Buffer_Full_Error_Counter_fake.call_count, 1U);
   EXPECT_EQ(Set_M2D_Buffer_Full_Error_Counter_fake.call_count, 1U);
   EXPECT_EQ(Set_M2D_Buffer_Full_Error_Counter_fake.arg0_val, 1U);
}

/**
 *  @b per_look_init_02
 *  @n
 *      DSP_Processing_Per_Look_Init returns false when Doppler is not ready; increments M2D_DSP_Not_Ready_Counter.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, PerLookInit_BufferNotFullDopplerNotReady_ReturnsFalseIncrementsNotReadyCounter)
{
   Is_IPC_Notify_Buffer_Full_fake.return_val = 0U;
   Get_Received_Doppler_Done_fake.return_val = false;
   M2D_DSP_Not_Ready_Counter                 = 0U;

   EXPECT_FALSE(DSP_Processing_Per_Look_Init());
   EXPECT_EQ(M2D_DSP_Not_Ready_Counter, 1U);
}

/**
 *  @b per_look_init_03
 *  @n
 *      DSP_Processing_Per_Look_Init returns false when R52_BBE_Trigger fails despite buffer being available.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, PerLookInit_DopplerReadyTriggerReturnsFalse_ReturnsFalse)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   memset((void *)&s_notify_msg, 0, sizeof(s_notify_msg));
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));

   Is_IPC_Notify_Buffer_Full_fake.return_val = 0U;
   Get_Received_Doppler_Done_fake.return_val = true;
   Get_IPC_Notify_Buffer_fake.return_val     = &s_notify_msg;
   Get_IPC_M2D_Msg_Buffer_fake.return_val    = &s_m2d_msg;
   R52_BBE_Trigger_fake.return_val           = false;

   EXPECT_FALSE(DSP_Processing_Per_Look_Init());
}

/**
 *  @b per_look_init_04
 *  @n
 *      DSP_Processing_Per_Look_Init returns false when configuration times out; increments Dsp_Cfg_Error_Counter.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, PerLookInit_TriggerTrueConfigTimesOut_ReturnsFalseIncrementsCfgErrorCounter)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   memset((void *)&s_notify_msg, 0, sizeof(s_notify_msg));
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));

   Is_IPC_Notify_Buffer_Full_fake.return_val = 0U;
   Get_Received_Doppler_Done_fake.return_val = true;
   Get_IPC_Notify_Buffer_fake.return_val     = &s_notify_msg;
   Get_IPC_M2D_Msg_Buffer_fake.return_val    = &s_m2d_msg;
   R52_BBE_Trigger_fake.return_val           = true;
   Get_DSP_Cfg_Init_fake.return_val          = DSP_CONFIG_WAITING_FOR_RESPONSE;
   platformtime_fff_elapsed_mstime_value     = IPC_MESSAGE_TIMEOUT_IN_MS;
   Dsp_Cfg_Error_Counter                     = 0U;

   EXPECT_FALSE(DSP_Processing_Per_Look_Init());
   EXPECT_EQ(Dsp_Cfg_Error_Counter, 1U);
}

/**
 *  @b per_look_init_05
 *  @n
 *      DSP_Processing_Per_Look_Init returns false when DSP responds with error code before timeout; increments
 * Dsp_Cfg_Error_Counter. Tests early-exit condition.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, PerLookInit_TriggerTrueConfigErrorResponse_ReturnsFalseIncrementsCfgErrorCounter)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   memset((void *)&s_notify_msg, 0, sizeof(s_notify_msg));
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));

   Is_IPC_Notify_Buffer_Full_fake.return_val = 0U;
   Get_Received_Doppler_Done_fake.return_val = true;
   Get_IPC_Notify_Buffer_fake.return_val     = &s_notify_msg;
   Get_IPC_M2D_Msg_Buffer_fake.return_val    = &s_m2d_msg;
   R52_BBE_Trigger_fake.return_val           = true;
   Get_DSP_Cfg_Init_fake.return_val          = DSP_CONFIG_ERROR;
   /* Elapsed time stays below timeout so only the DSP_Cfg_Init condition drives exit */
   platformtime_fff_elapsed_mstime_value = 0U;
   Dsp_Cfg_Error_Counter                 = 0U;

   EXPECT_FALSE(DSP_Processing_Per_Look_Init());
   EXPECT_EQ(Dsp_Cfg_Error_Counter, 1U);
}

/**
 *  @b per_look_init_06
 *  @n
 *      DSP_Processing_Per_Look_Init returns true when trigger succeeds and DSP config completes without error.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, PerLookInit_TriggerTrueConfigNoError_ReturnsTrue)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   memset((void *)&s_notify_msg, 0, sizeof(s_notify_msg));
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));

   Is_IPC_Notify_Buffer_Full_fake.return_val = 0U;
   Get_Received_Doppler_Done_fake.return_val = true;
   Get_IPC_Notify_Buffer_fake.return_val     = &s_notify_msg;
   Get_IPC_M2D_Msg_Buffer_fake.return_val    = &s_m2d_msg;
   R52_BBE_Trigger_fake.return_val           = true;
   Get_DSP_Cfg_Init_fake.return_val          = DSP_CONFIG_NO_ERROR;
   Dsp_Cfg_Error_Counter                     = 0U;

   EXPECT_TRUE(DSP_Processing_Per_Look_Init());
   EXPECT_EQ(Dsp_Cfg_Error_Counter, 0U);
}

TEST_F(Dsp_Setup_Unit_Test_Suite, PerLookInit_RecordsFrameStartTimeUsingLookIndex)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   memset((void *)&s_notify_msg, 0, sizeof(s_notify_msg));
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));

   Radar_Ctl_Data.scan_index                 = 42U;
   Is_IPC_Notify_Buffer_Full_fake.return_val = 0U;
   Get_Received_Doppler_Done_fake.return_val = true;
   Get_IPC_Notify_Buffer_fake.return_val     = &s_notify_msg;
   Get_IPC_M2D_Msg_Buffer_fake.return_val    = &s_m2d_msg;
   R52_BBE_Trigger_fake.return_val           = false;
   g_platform_ustime_sequence[0]             = 2500U;
   g_platform_ustime_sequence_len            = 1U;
   Get_Platform_ustime_fake.custom_fake      = Get_Platform_ustime_Sequence_Fake;

   EXPECT_FALSE(DSP_Processing_Per_Look_Init());
   EXPECT_EQ(Frame_Time_Buffer[0].lookindex, 42U);
   EXPECT_EQ(Frame_Time_Buffer[0].start_time_us, 2500U);
   EXPECT_EQ(Frame_Time_Buffer[0].end_time_us, 0U);
   EXPECT_EQ(Frame_Time_Buffer[0].frame_time_us, 0U);
}

TEST_F(Dsp_Setup_Unit_Test_Suite, FrameTimeTracksMatchingLookIndexAcrossOutOfOrderCompletions)
{
   g_platform_ustime_sequence[0]                = 1000U;
   g_platform_ustime_sequence[1]                = 1100U;
   g_platform_ustime_sequence[2]                = 1450U;
   g_platform_ustime_sequence[3]                = 1700U;
   g_platform_ustime_sequence_len               = 4U;
   g_platform_elapsed_ustime_sequence[0]        = 450U;
   g_platform_elapsed_ustime_sequence[1]        = 600U;
   g_platform_elapsed_ustime_sequence_len       = 2U;
   Get_Platform_ustime_fake.custom_fake         = Get_Platform_ustime_Sequence_Fake;
   Get_Platform_Elapsed_ustime_fake.custom_fake = Get_Platform_Elapsed_ustime_Sequence_Fake;

   Record_Frame_Start_Time(10U, 0U);
   Record_Frame_Start_Time(11U, 1U);

   Update_Frame_Time_For_Look(10U, 0U);
   EXPECT_EQ(Get_Frame_Time(10U), 450U);
   EXPECT_EQ(Frame_Time_Buffer[0].end_time_us, 1450U);
   EXPECT_EQ(Frame_Time_Buffer[0].frame_time_us, 450U);
   EXPECT_EQ(Frame_Time_Buffer[1].frame_time_us, 0U);
   EXPECT_EQ(Frame_Time_Buffer[1].lookindex, 11U);

   Update_Frame_Time_For_Look(11U, 1U);
   EXPECT_EQ(Get_Frame_Time(11U), 600U);
   EXPECT_EQ(Frame_Time_Buffer[1].end_time_us, 1700U);
   EXPECT_EQ(Frame_Time_Buffer[1].frame_time_us, 600U);
}

TEST_F(Dsp_Setup_Unit_Test_Suite, PerLookInit_TriggerTrueConfigWaitsThenCompletes_ReturnsTrue)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   static DSP_Config_Type_T s_cfg_init_seq[] = {
      DSP_CONFIG_WAITING_FOR_RESPONSE,
      DSP_CONFIG_NO_ERROR,
      DSP_CONFIG_NO_ERROR,
   };
   memset((void *)&s_notify_msg, 0, sizeof(s_notify_msg));
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));

   Is_IPC_Notify_Buffer_Full_fake.return_val = 0U;
   Get_Received_Doppler_Done_fake.return_val = true;
   Get_IPC_Notify_Buffer_fake.return_val     = &s_notify_msg;
   Get_IPC_M2D_Msg_Buffer_fake.return_val    = &s_m2d_msg;
   R52_BBE_Trigger_fake.return_val           = true;
   platformtime_fff_elapsed_mstime_value     = 0U;
   SET_RETURN_SEQ(Get_DSP_Cfg_Init, s_cfg_init_seq, 3);

   EXPECT_TRUE(DSP_Processing_Per_Look_Init());
   EXPECT_GE(Get_Platform_Elapsed_mstime_fake.call_count, 2U);
   EXPECT_EQ(Dsp_Cfg_Error_Counter, 0U);
}

/**
 *  @b per_look_init_07
 *  @n
 *      DSP_Processing_Per_Look_Init skips vehicle data copy when VID stream is null.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, PerLookInit_VidStreamNull_SkipsVehicleDataCopy)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));
   s_m2d_msg.payload.veh_data.veh_raw_data[0U].ego_vehicle_speed = 99.0F;

   Is_IPC_Notify_Buffer_Full_fake.return_val   = 0U;
   Get_Received_Doppler_Done_fake.return_val   = true;
   Get_IPC_Notify_Buffer_fake.return_val       = &s_notify_msg;
   Get_IPC_M2D_Msg_Buffer_fake.return_val      = &s_m2d_msg;
   Get_Stream_Rx_Info_Data_Ptr_fake.return_val = nullptr; /* no VID stream */
   R52_BBE_Trigger_fake.return_val             = false;

   DSP_Processing_Per_Look_Init();

   /* ego_vehicle_speed must be untouched when vid_stream_ptr is null */
   EXPECT_EQ(s_m2d_msg.payload.veh_data.veh_raw_data[0U].ego_vehicle_speed, 99.0F);
}

/**
 *  @b per_look_init_07b
 *  @n
 *      DSP_Processing_Per_Look_Init skips vehicle data copy when HIL mode is enabled
 *      and hil_src_vehicle_data does not request vehicle-com data.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, PerLookInit_HilEnabledNonExecuteSource_SkipsVehicleDataCopy)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   static Vid_Stream_T s_vid_stream;
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));
   memset(&s_vid_stream, 0, sizeof(s_vid_stream));

   s_vid_stream.veh_params.veh_speed = 44.4F;
   s_vid_stream.veh_params.veh_yaw   = 0.44F;

   s_m2d_msg.payload.hil_ipc_info.hil_mode_enabled     = CODED_TRUE;
   s_m2d_msg.payload.hil_ipc_info.hil_src_vehicle_data = HIL_EXECUTE_INJECTION_DATA;

   Is_IPC_Notify_Buffer_Full_fake.return_val   = 0U;
   Get_Received_Doppler_Done_fake.return_val   = true;
   Get_IPC_Notify_Buffer_fake.return_val       = &s_notify_msg;
   Get_IPC_M2D_Msg_Buffer_fake.return_val      = &s_m2d_msg;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val  = &s_m2d_msg;
   Get_Stream_Rx_Info_Data_Ptr_fake.return_val = (uint8_t *)&s_vid_stream;
   R52_BBE_Trigger_fake.return_val             = false;

   DSP_Processing_Per_Look_Init();

   EXPECT_EQ(s_m2d_msg.payload.veh_data.veh_raw_data[0U].ego_vehicle_speed, 0.0F);
   EXPECT_EQ(s_m2d_msg.payload.veh_data.veh_raw_data[0U].ego_yaw_rate, 0.0F);
}

/**
 *  @b per_look_init_08
 *  @n
 *      DSP_Processing_Per_Look_Init copies vehicle speed and yaw data when VID stream is available.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, PerLookInit_VidStreamPresent_CopiesVehicleData)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   static Vid_Stream_T s_vid_stream;
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));
   memset(&s_vid_stream, 0, sizeof(s_vid_stream));
   s_vid_stream.veh_params.veh_speed = 33.5F;
   s_vid_stream.veh_params.veh_yaw   = 0.1F;

   Is_IPC_Notify_Buffer_Full_fake.return_val   = 0U;
   Get_Received_Doppler_Done_fake.return_val   = true;
   Get_IPC_Notify_Buffer_fake.return_val       = &s_notify_msg;
   Get_IPC_M2D_Msg_Buffer_fake.return_val      = &s_m2d_msg;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val  = &s_m2d_msg;
   Get_Stream_Rx_Info_Data_Ptr_fake.return_val = (uint8_t *)&s_vid_stream;
   R52_BBE_Trigger_fake.return_val             = false;

   DSP_Processing_Per_Look_Init();

   bool vehicle_data_copied = false;
   for (uint8_t raw_index = 0U; raw_index < VSE_STREAM_RAW_INSTANCES; ++raw_index)
   {
      if ((s_m2d_msg.payload.veh_data.veh_raw_data[raw_index].ego_vehicle_speed == 33.5F) &&
          (s_m2d_msg.payload.veh_data.veh_raw_data[raw_index].ego_yaw_rate == 0.1F))
      {
         vehicle_data_copied = true;
         break;
      }
   }

   EXPECT_TRUE(vehicle_data_copied);
}

/**
 *  @b per_look_init_08b
 *  @n
 *      DSP_Processing_Per_Look_Init updates the DRA-based speed compensation only when
 *      alignment_mode is enabled.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, PerLookInit_DraAlignmentModeZero_LeavesSpeedCompDefault)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   static Vid_Stream_T s_vid_stream;
   static D2M_Msg_T s_d2m_msg;
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));
   memset(&s_vid_stream, 0, sizeof(s_vid_stream));
   memset(&s_d2m_msg, 0, sizeof(s_d2m_msg));

   s_vid_stream.veh_params.veh_speed                                                                = 12.0F;
   s_vid_stream.veh_params.veh_yaw                                                                  = 0.12F;
   s_d2m_msg.payload.dynamic_alignment_log_stream.dra_core_data.alignment_mode                      = 0U;
   s_d2m_msg.payload.dynamic_alignment_log_stream.dra_core_data.speed_compensation_factor_estimated = 7.5F;
   s_d2m_msg.payload.dynamic_alignment_log_stream.dra_core_data.scf_estimation_qf                   = 9U;

   Is_IPC_Notify_Buffer_Full_fake.return_val       = 0U;
   Get_Received_Doppler_Done_fake.return_val       = true;
   Get_IPC_Notify_Buffer_fake.return_val           = &s_notify_msg;
   Get_IPC_M2D_Msg_Buffer_fake.return_val          = &s_m2d_msg;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val      = &s_m2d_msg;
   Get_IPC_D2M_Sp_Post_Proc_Buffer_fake.return_val = &s_d2m_msg;
   Get_Stream_Rx_Info_Data_Ptr_fake.return_val     = (uint8_t *)&s_vid_stream;
   R52_BBE_Trigger_fake.return_val                 = false;

   DSP_Processing_Per_Look_Init();

   EXPECT_EQ(s_m2d_msg.payload.veh_data.veh_raw_misc.vehspeedcompfac_ka, 1.0F);
   EXPECT_EQ(s_m2d_msg.payload.veh_data.veh_raw_misc.vehspeedcompfac_ka_qf, 3U);
}

/**
 *  @b per_look_init_08c
 *  @n
 *      DSP_Processing_Per_Look_Init updates the DRA-based speed compensation when
 *      alignment_mode is enabled.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, PerLookInit_DraAlignmentModeEnabled_UpdatesSpeedComp)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   static Vid_Stream_T s_vid_stream;
   static D2M_Msg_T s_d2m_msg;
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));
   memset(&s_vid_stream, 0, sizeof(s_vid_stream));
   memset(&s_d2m_msg, 0, sizeof(s_d2m_msg));

   s_vid_stream.veh_params.veh_speed                                                                = 12.0F;
   s_vid_stream.veh_params.veh_yaw                                                                  = 0.12F;
   s_d2m_msg.payload.dynamic_alignment_log_stream.dra_core_data.alignment_mode                      = 1U;
   s_d2m_msg.payload.dynamic_alignment_log_stream.dra_core_data.speed_compensation_factor_estimated = 7.5F;
   s_d2m_msg.payload.dynamic_alignment_log_stream.dra_core_data.scf_estimation_qf                   = 9U;

   Is_IPC_Notify_Buffer_Full_fake.return_val       = 0U;
   Get_Received_Doppler_Done_fake.return_val       = true;
   Get_IPC_Notify_Buffer_fake.return_val           = &s_notify_msg;
   Get_IPC_M2D_Msg_Buffer_fake.return_val          = &s_m2d_msg;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val      = &s_m2d_msg;
   Get_IPC_D2M_Sp_Post_Proc_Buffer_fake.return_val = &s_d2m_msg;
   Get_Stream_Rx_Info_Data_Ptr_fake.return_val     = (uint8_t *)&s_vid_stream;
   R52_BBE_Trigger_fake.return_val                 = false;

   DSP_Processing_Per_Look_Init();

   EXPECT_EQ(s_m2d_msg.payload.veh_data.veh_raw_misc.vehspeedcompfac_ka, 7.5F);
   EXPECT_EQ(s_m2d_msg.payload.veh_data.veh_raw_misc.vehspeedcompfac_ka_qf, 9U);
}

/**
 *  @b per_look_init_08d
 *  @n
 *      DSP_Processing_Per_Look_Init uses the steering-angle warm-up branch on the
 *      first call and the delta-speed branch on the second call.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, PerLookInit_SteeringAngleWarmupThenDeltaBranch)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   static Vid_Stream_T s_vid_stream;
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));
   memset(&s_vid_stream, 0, sizeof(s_vid_stream));

   Is_IPC_Notify_Buffer_Full_fake.return_val   = 0U;
   Get_Received_Doppler_Done_fake.return_val   = true;
   Get_IPC_Notify_Buffer_fake.return_val       = &s_notify_msg;
   Get_IPC_M2D_Msg_Buffer_fake.return_val      = &s_m2d_msg;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val  = &s_m2d_msg;
   Get_Stream_Rx_Info_Data_Ptr_fake.return_val = (uint8_t *)&s_vid_stream;
   R52_BBE_Trigger_fake.return_val             = false;

   s_vid_stream.veh_params.veh_speed = 5.0F;
   s_vid_stream.veh_params.veh_yaw   = 0.1F;
   DSP_Processing_Per_Look_Init();

   s_vid_stream.veh_params.veh_speed = 6.0F;
   s_vid_stream.veh_params.veh_yaw   = 0.2F;
   DSP_Processing_Per_Look_Init();
}

/**
 *  @b per_look_init_08e
 *  @n
 *      DSP_Processing_Per_Look_Init takes the timeout path when BBE trigger succeeds
 *      but DSP config never reaches NO_ERROR.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, PerLookInit_BbeTriggerTimesOut_IncrementsCfgErrorCounter)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   static Vid_Stream_T s_vid_stream;
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));
   memset(&s_vid_stream, 0, sizeof(s_vid_stream));

   s_vid_stream.veh_params.veh_speed = 10.0F;
   s_vid_stream.veh_params.veh_yaw   = 0.1F;

   Is_IPC_Notify_Buffer_Full_fake.return_val   = 0U;
   Get_Received_Doppler_Done_fake.return_val   = true;
   Get_IPC_Notify_Buffer_fake.return_val       = &s_notify_msg;
   Get_IPC_M2D_Msg_Buffer_fake.return_val      = &s_m2d_msg;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val  = &s_m2d_msg;
   Get_Stream_Rx_Info_Data_Ptr_fake.return_val = (uint8_t *)&s_vid_stream;
   R52_BBE_Trigger_fake.return_val             = true;
   Get_DSP_Cfg_Init_fake.return_val            = DSP_CONFIG_WAITING_FOR_RESPONSE;
   platformtime_fff_elapsed_mstime_value       = IPC_MESSAGE_TIMEOUT_IN_MS;
   Dsp_Cfg_Error_Counter                       = 0U;

   EXPECT_FALSE(DSP_Processing_Per_Look_Init());
   EXPECT_EQ(Dsp_Cfg_Error_Counter, 1U);
}

/**
 *  @b per_look_init_09
 *  @n
 *      DSP_Processing_Per_Look_Init toggles the ping-pong buffer index on each call to alternate between ping and pong buffers.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, PerLookInit_PingPongIndexToggles_OnSuccessfulTriggerPath)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));

   R52_M2D_Buffer_Index                      = 0U;
   Is_IPC_Notify_Buffer_Full_fake.return_val = 0U;
   Get_Received_Doppler_Done_fake.return_val = true;
   Get_IPC_Notify_Buffer_fake.return_val     = &s_notify_msg;
   Get_IPC_M2D_Msg_Buffer_fake.return_val    = &s_m2d_msg;
   R52_BBE_Trigger_fake.return_val           = false;

   DSP_Processing_Per_Look_Init();

   /* index toggles ping(0)→pong(1) */
   EXPECT_EQ(R52_M2D_Buffer_Index, 1U);
}

/**
 *  @b get_fetch_m2d_buffer_idx_hil_injection_01
 *  @n
 *      Get_Fetch_M2D_Buffer_Idx_HIL_Injection must return the buffer index
 *      that was latched by DSP_Processing_Per_Look_Init() on the last
 *      successful trigger (ping = 0).
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, GetFetchM2DBufferIdxHilInjection_AfterPingTrigger_ReturnsPingIndex)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));

   R52_M2D_Buffer_Index                      = 0U;
   Is_IPC_Notify_Buffer_Full_fake.return_val = 0U;
   Get_Received_Doppler_Done_fake.return_val = true;
   Get_IPC_Notify_Buffer_fake.return_val     = &s_notify_msg;
   Get_IPC_M2D_Msg_Buffer_fake.return_val    = &s_m2d_msg;
   R52_BBE_Trigger_fake.return_val           = false;

   DSP_Processing_Per_Look_Init();

   /* Buffer index latched for HIL injection must reflect the index used for
    * THIS trigger (0), even though R52_M2D_Buffer_Index has already toggled
    * to 1 for the next call. */
   EXPECT_EQ(Get_Fetch_M2D_Buffer_Idx_HIL_Injection(), 0U);
}

/**
 *  @b get_fetch_m2d_buffer_idx_hil_injection_02
 *  @n
 *      A second successful trigger (pong = 1) must update the latched index
 *      returned by Get_Fetch_M2D_Buffer_Idx_HIL_Injection accordingly.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, GetFetchM2DBufferIdxHilInjection_AfterPongTrigger_ReturnsPongIndex)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));

   R52_M2D_Buffer_Index                      = 1U;
   Is_IPC_Notify_Buffer_Full_fake.return_val = 0U;
   Get_Received_Doppler_Done_fake.return_val = true;
   Get_IPC_Notify_Buffer_fake.return_val     = &s_notify_msg;
   Get_IPC_M2D_Msg_Buffer_fake.return_val    = &s_m2d_msg;
   R52_BBE_Trigger_fake.return_val           = false;

   DSP_Processing_Per_Look_Init();

   EXPECT_EQ(Get_Fetch_M2D_Buffer_Idx_HIL_Injection(), 1U);
}

/**
 *  @b per_look_init_10
 *  @n
 *      DSP_Processing_Per_Look_Init copies the current TIMER1 tick value into
 *      payload.r52_ticks_for_sync for BBE-side timestamp synchronization.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, PerLookInit_CopiesTimerTicksIntoPayload)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   constexpr uint32_t kTimerTickValue = 0x1234ABCDU;

   memset((void *)&s_notify_msg, 0, sizeof(s_notify_msg));
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));

   Is_IPC_Notify_Buffer_Full_fake.return_val = 0U;
   Get_Received_Doppler_Done_fake.return_val = true;
   Get_IPC_Notify_Buffer_fake.return_val     = &s_notify_msg;
   Get_IPC_M2D_Msg_Buffer_fake.return_val    = &s_m2d_msg;
   R52_BBE_Trigger_fake.return_val           = false;
   g_timer_ctrl_regs.TIMER1CURRENTVAL        = kTimerTickValue;

   DSP_Processing_Per_Look_Init();

   EXPECT_EQ(s_m2d_msg.payload.r52_ticks_for_sync, kTimerTickValue);
}

/* -------------------------------------------------------------------------
 * Run_DSP_Interaction_State_Machine — state coverage
 * ------------------------------------------------------------------------- */

/**
 *  @b state_machine_01
 *  @n
 *      State machine in INITIALIZE state should call onetime init, release stall bit, and transition to INITIALIZING state.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, StateMachine_InitializeState_OnetimeInitReleasesStallTransitionsToInitializing)
{
   static volatile M2D_One_Time_Msg_T s_onetime_msg;
   memset((void *)&s_onetime_msg, 0, sizeof(s_onetime_msg));

   Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = &s_onetime_msg;
   DSP_Current_State                              = DSP_CORE_INITIALIZE;
   Dsp_Base_Ptr->DSP_CTRL.f.RUNSTALL              = 1U;

   bool ret = Run_DSP_Interaction_State_Machine();

   EXPECT_FALSE(ret);
   EXPECT_EQ(DSP_Current_State, DSP_CORE_INITIALIZING);
   EXPECT_EQ((uint32_t)Dsp_Base_Ptr->DSP_CTRL.f.RUNSTALL, 0U);
   EXPECT_EQ(IPC_M2D_Buffer_Init_fake.call_count, 1U);
}

/**
 *  @b state_machine_02
 *  @n
 *      State machine in INITIALIZING state without DSP_Init should handle missed frame and stay in INITIALIZING state.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, StateMachine_InitializingNoDspInit_HandlesMissedFrame)
{
   DSP_Current_State                   = DSP_CORE_INITIALIZING;
   Get_DSP_Init_Status_fake.return_val = false;
   DSP_Processing_Error_Counter        = 0U;
   DSP_Processing_Error_Counter_Max    = 5U;

   bool ret = Run_DSP_Interaction_State_Machine();

   EXPECT_FALSE(ret);
   EXPECT_EQ(DSP_Current_State, DSP_CORE_INITIALIZING);
   EXPECT_EQ(DSP_Processing_Error_Counter, 1U);
}

/**
 *  @b state_machine_03
 *  @n
 *      State machine in INITIALIZING state with DSP_Init true should transition to NORMAL_OPERATION and set Received_Doppler_Done
 * flag.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, StateMachine_InitializingWithDspInit_TransitionsToNormalAndSetsDopplerDone)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));

   DSP_Current_State                         = DSP_CORE_INITIALIZING;
   Get_DSP_Init_Status_fake.return_val       = true;
   Is_IPC_Notify_Buffer_Full_fake.return_val = 1U; /* per-look-init returns false — that's OK here */

   bool ret = Run_DSP_Interaction_State_Machine();

   EXPECT_FALSE(ret);
   EXPECT_EQ(DSP_Current_State, DSP_CORE_NORMAL_OPERATION);
   EXPECT_EQ(Set_Received_Doppler_Done_fake.call_count, 1U);
   EXPECT_TRUE(Set_Received_Doppler_Done_fake.arg0_val);
}

/**
 *  @b state_machine_04
 *  @n
 *      State machine in NORMAL_OPERATION should increment error counter when per-look-init fails.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, StateMachine_NormalOperationPerLookFails_IncrementsErrorCounter)
{
   DSP_Current_State                         = DSP_CORE_NORMAL_OPERATION;
   DSP_Processing_Error_Counter              = 0U;
   DSP_Processing_Error_Counter_Max          = 5U;
   Is_IPC_Notify_Buffer_Full_fake.return_val = 1U; /* per-look returns false */

   bool ret = Run_DSP_Interaction_State_Machine();

   EXPECT_FALSE(ret);
   EXPECT_EQ(DSP_Processing_Error_Counter, 1U);
}

/**
 *  @b state_machine_05
 *  @n
 *      State machine in NORMAL_OPERATION should reset error and reset counters when per-look-init succeeds; maintains
 * NORMAL_OPERATION state.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, StateMachine_NormalOperationPerLookSucceeds_ResetsErrorAndResetCounters)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));

   DSP_Current_State                         = DSP_CORE_NORMAL_OPERATION;
   Get_Received_Doppler_Done_fake.return_val = true;
   DSP_Processing_Error_Counter              = 3U;
   DSP_Reset_Counter                         = 2U;
   Is_IPC_Notify_Buffer_Full_fake.return_val = 0U;
   Get_IPC_Notify_Buffer_fake.return_val     = &s_notify_msg;
   Get_IPC_M2D_Msg_Buffer_fake.return_val    = &s_m2d_msg;
   R52_BBE_Trigger_fake.return_val           = true;
   Get_DSP_Cfg_Init_fake.return_val          = DSP_CONFIG_NO_ERROR;

   bool ret = Run_DSP_Interaction_State_Machine();

   EXPECT_TRUE(ret);
   EXPECT_EQ(DSP_Processing_Error_Counter, 0U);
   EXPECT_EQ(DSP_Reset_Counter, 0U);
}
/*===========================================================================*
 * DDR-4176 — Getter / Setter API integration tests
 *
 * DDR-4176 replaced every direct read/write of the shared variables
 * (Received_Doppler_Done, DSP_Init, DSP_Cfg_Init, M2D_Buffer_Full_Error_Counter)
 * with the corresponding ipc_mss getter/setter functions, and replaced
 * Get_Timestamp_Milliseconds / Get_Elapsed_Time_Milliseconds with
 * Get_Platform_mstime / Get_Platform_Elapsed_mstime.
 *
 * The tests below use raw FFF fake call_count / arg inspection (delegates are
 * temporarily cleared) to assert that each changed call-site invokes the
 * correct new API exactly the expected number of times.
 *===========================================================================*/

/* -------------------------------------------------------------------------
 * DSP_Done_Processing — was: return Received_Doppler_Done
 *                        now: return Get_Received_Doppler_Done()
 * ------------------------------------------------------------------------- */

/**
 *  @b ddr4176_dsp_done_processing_uses_getter_true
 *  @n
 *      DSP_Done_Processing must call Get_Received_Doppler_Done() (not read the
 *      global directly) and propagate its return value as true.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, Ddr4176_DspDoneProcessing_UsesGetReceivedDopplerDone_True)
{
   Get_Received_Doppler_Done_fake.return_val = true;

   EXPECT_TRUE(DSP_Done_Processing());
   EXPECT_EQ(Get_Received_Doppler_Done_fake.call_count, 1U);
}

/**
 *  @b ddr4176_dsp_done_processing_uses_getter_false
 *  @n
 *      DSP_Done_Processing must propagate false from Get_Received_Doppler_Done().
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, Ddr4176_DspDoneProcessing_UsesGetReceivedDopplerDone_False)
{
   Get_Received_Doppler_Done_fake.return_val = false;

   EXPECT_FALSE(DSP_Done_Processing());
   EXPECT_EQ(Get_Received_Doppler_Done_fake.call_count, 1U);
}

/* -------------------------------------------------------------------------
 * Perform_BBE32_Reset — was: DSP_Init = false
 *                        now: Set_DSP_Init_Status(false)
 * ------------------------------------------------------------------------- */

/**
 *  @b ddr4176_perform_bbe32_reset_calls_set_dsp_init_status
 *  @n
 *      Perform_BBE32_Reset must call Set_DSP_Init_Status(false) via the
 *      ipc_mss setter rather than writing DSP_Init directly.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, Ddr4176_PerformBbe32Reset_CallsSetDspInitStatus_False)
{
   DSP_Init = true; /* pre-condition: was initialised */

   Perform_BBE32_Reset();

   EXPECT_EQ(Set_DSP_Init_Status_fake.call_count, 1U);
   EXPECT_FALSE(Set_DSP_Init_Status_fake.arg0_val);
}

/* -------------------------------------------------------------------------
 * Run_DSP_Interaction_State_Machine (INITIALIZING state)
 *   was: if (DSP_Init)              now: if (Get_DSP_Init_Status())
 *   was: Received_Doppler_Done = true  now: Set_Received_Doppler_Done(true)
 * ------------------------------------------------------------------------- */

/**
 *  @b ddr4176_state_machine_initializing_calls_get_dsp_init_status
 *  @n
 *      In DSP_CORE_INITIALIZING state the state machine must call
 *      Get_DSP_Init_Status() to test whether the DSP has initialised.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, Ddr4176_StateMachine_InitializingState_CallsGetDspInitStatus)
{
   DSP_Current_State                   = DSP_CORE_INITIALIZING;
   Get_DSP_Init_Status_fake.return_val = false; /* DSP not yet ready */
   DSP_Processing_Error_Counter        = 0U;
   DSP_Processing_Error_Counter_Max    = 5U;

   Run_DSP_Interaction_State_Machine();

   EXPECT_GE(Get_DSP_Init_Status_fake.call_count, 1U);
}

/**
 *  @b ddr4176_state_machine_initializing_calls_set_received_doppler_done
 *  @n
 *      When DSP_Init becomes true the state machine must call
 *      Set_Received_Doppler_Done(true) instead of writing the global directly.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, Ddr4176_StateMachine_InitializingWithDspInit_CallsSetReceivedDopplerDoneTrue)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));

   DSP_Current_State                         = DSP_CORE_INITIALIZING;
   Get_DSP_Init_Status_fake.return_val       = true; /* DSP ready */
   Is_IPC_Notify_Buffer_Full_fake.return_val = 1U;   /* per-look returns early */

   Run_DSP_Interaction_State_Machine();

   EXPECT_GE(Set_Received_Doppler_Done_fake.call_count, 1U);
   EXPECT_TRUE(Set_Received_Doppler_Done_fake.arg0_val);
}

/* -------------------------------------------------------------------------
 * DSP_Processing_Per_Look_Init (Doppler-ready check)
 *   was: if (Received_Doppler_Done)
 *   now: if (Get_Received_Doppler_Done())
 * ------------------------------------------------------------------------- */

/**
 *  @b ddr4176_per_look_init_doppler_check_uses_getter
 *  @n
 *      The Doppler-ready branch inside DSP_Processing_Per_Look_Init must
 *      call Get_Received_Doppler_Done() rather than reading the global.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, Ddr4176_PerLookInit_DopplerCheck_CallsGetReceivedDopplerDone)
{
   Is_IPC_Notify_Buffer_Full_fake.return_val = 0U;
   Get_Received_Doppler_Done_fake.return_val = false; /* doppler not ready */
   M2D_DSP_Not_Ready_Counter                 = 0U;

   EXPECT_FALSE(DSP_Processing_Per_Look_Init());
   EXPECT_GE(Get_Received_Doppler_Done_fake.call_count, 1U);
}

/* -------------------------------------------------------------------------
 * DSP_Processing_Per_Look_Init (trigger path)
 *   was: DSP_Cfg_Init = DSP_CONFIG_WAITING_FOR_RESPONSE
 *        Received_Doppler_Done = false
 *        start_time = Get_Timestamp_Milliseconds()
 *        elapsed_time = Get_Elapsed_Time_Milliseconds(start_time)
 *        while (DSP_Cfg_Init == ...)
 *        if (DSP_Cfg_Init != DSP_CONFIG_NO_ERROR)
 *   now: Set_DSP_Cfg_Init(DSP_CONFIG_WAITING_FOR_RESPONSE)
 *        Set_Received_Doppler_Done(false)
 *        Get_Platform_mstime(&start_time)
 *        Get_Platform_Elapsed_mstime(&elapsed_time, start_time)
 *        while (Get_DSP_Cfg_Init() == ...)
 *        if (Get_DSP_Cfg_Init() != DSP_CONFIG_NO_ERROR)
 * ------------------------------------------------------------------------- */

/**
 *  @b ddr4176_per_look_init_trigger_path_calls_set_dsp_cfg_init_and_set_received_doppler_done
 *  @n
 *      When the trigger path is entered the function must:
 *        1. Call Set_DSP_Cfg_Init(DSP_CONFIG_WAITING_FOR_RESPONSE)
 *        2. Call Set_Received_Doppler_Done(false)
 *      before firing R52_BBE_Trigger().
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, Ddr4176_PerLookInit_TriggerPath_CallsSetDspCfgInitAndSetReceivedDopplerDoneFalse)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   memset((void *)&s_notify_msg, 0, sizeof(s_notify_msg));
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));

   Is_IPC_Notify_Buffer_Full_fake.return_val = 0U;
   Get_Received_Doppler_Done_fake.return_val = true;
   Get_IPC_Notify_Buffer_fake.return_val     = &s_notify_msg;
   Get_IPC_M2D_Msg_Buffer_fake.return_val    = &s_m2d_msg;
   R52_BBE_Trigger_fake.return_val           = false; /* don't enter spin-wait */

   DSP_Processing_Per_Look_Init();

   /* DDR-4176: Set_DSP_Cfg_Init replaces DSP_Cfg_Init = WAITING */
   EXPECT_GE(Set_DSP_Cfg_Init_fake.call_count, 1U);
   EXPECT_EQ((DSP_Config_Type_T)Set_DSP_Cfg_Init_fake.arg0_val, DSP_CONFIG_WAITING_FOR_RESPONSE);
   /* DDR-4176: Set_Received_Doppler_Done replaces Received_Doppler_Done = false */
   EXPECT_GE(Set_Received_Doppler_Done_fake.call_count, 1U);
   EXPECT_FALSE(Set_Received_Doppler_Done_fake.arg0_val);
}

/**
 *  @b ddr4176_per_look_init_trigger_path_calls_platform_time_apis
 *  @n
 *      When R52_BBE_Trigger() succeeds the spin-wait must call:
 *        - Get_Platform_mstime()  (replaces Get_Timestamp_Milliseconds)
 *        - Get_Platform_Elapsed_mstime()  (replaces Get_Elapsed_Time_Milliseconds)
 *      and must use Get_DSP_Cfg_Init() in the loop condition.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, Ddr4176_PerLookInit_TriggerSucceeds_CallsPlatformTimeApis)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   memset((void *)&s_notify_msg, 0, sizeof(s_notify_msg));
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));

   Is_IPC_Notify_Buffer_Full_fake.return_val = 0U;
   Get_Received_Doppler_Done_fake.return_val = true;
   Get_IPC_Notify_Buffer_fake.return_val     = &s_notify_msg;
   Get_IPC_M2D_Msg_Buffer_fake.return_val    = &s_m2d_msg;
   R52_BBE_Trigger_fake.return_val           = true;
   Get_DSP_Cfg_Init_fake.return_val          = DSP_CONFIG_NO_ERROR;
   /* elapsed returns 0 → loop exits on DSP_Cfg_Init condition, not timeout */
   platformtime_fff_elapsed_mstime_value = 0U;

   DSP_Processing_Per_Look_Init();

   /* DDR-4176: Get_Platform_mstime replaces Get_Timestamp_Milliseconds */
   EXPECT_EQ(Get_Platform_mstime_fake.call_count, 1U);
   /* DDR-4176: Get_Platform_Elapsed_mstime replaces Get_Elapsed_Time_Milliseconds */
   EXPECT_GE(Get_Platform_Elapsed_mstime_fake.call_count, 1U);
}

/**
 *  @b ddr4176_per_look_init_trigger_path_calls_get_dsp_cfg_init_in_loop
 *  @n
 *      The do-while condition must call Get_DSP_Cfg_Init() to check the
 *      config state rather than reading DSP_Cfg_Init directly.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, Ddr4176_PerLookInit_SpinWait_CallsGetDspCfgInit)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   memset((void *)&s_notify_msg, 0, sizeof(s_notify_msg));
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));

   Is_IPC_Notify_Buffer_Full_fake.return_val = 0U;
   Get_Received_Doppler_Done_fake.return_val = true;
   Get_IPC_Notify_Buffer_fake.return_val     = &s_notify_msg;
   Get_IPC_M2D_Msg_Buffer_fake.return_val    = &s_m2d_msg;
   R52_BBE_Trigger_fake.return_val           = true;
   /* Return NO_ERROR immediately so the loop body executes exactly once */
   Get_DSP_Cfg_Init_fake.return_val      = DSP_CONFIG_NO_ERROR;
   platformtime_fff_elapsed_mstime_value = 0U;

   DSP_Processing_Per_Look_Init();

   /* DDR-4176: Get_DSP_Cfg_Init replaces direct DSP_Cfg_Init reads; must be
    * called at least once for the loop condition and once for the post-loop check */
   EXPECT_GE(Get_DSP_Cfg_Init_fake.call_count, 2U);
}

/* -------------------------------------------------------------------------
 * HIL Mode Vehicle Data Update Logic
 * Tests for: hil_mode_enabled and hil_veh_data_src conditions
 * ------------------------------------------------------------------------- */

/**
 *  @b per_look_init_hil_disabled_copies_vehicle_data_01
 *  @n
 *      DSP_Processing_Per_Look_Init should copy vehicle data when HIL mode is DISABLED
 *      (hil_mode_enabled = CODED_FALSE).
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, PerLookInit_HilModeDisabled_CopiesVehicleData)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   static Vid_Stream_T s_vid_stream;
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));
   memset(&s_vid_stream, 0, sizeof(s_vid_stream));

   /* Setup VID stream with test values */
   s_vid_stream.veh_params.veh_speed           = 42.5F;
   s_vid_stream.veh_params.veh_yaw             = 0.25F;
   s_vid_stream.veh_params.veh_steering_angle  = 15.0F;
   s_vid_stream.veh_params.veh_speed_qf        = 0x03U;
   s_vid_stream.veh_params.veh_yaw_qf          = 0x02U;
   s_vid_stream.veh_params.lros_drive_reverse  = 0x00U;
   s_vid_stream.veh_params.lros_drive_dir      = 0x01U;
   s_vid_stream.veh_params.gear_position       = 0x02U;
   s_vid_stream.veh_params.yaw_rate_bias       = 0x05U;
   s_vid_stream.veh_params.veh_spd_comp_factor = 10;

   /* Setup M2D message with HIL mode DISABLED */
   s_m2d_msg.payload.hil_ipc_info.hil_mode_enabled     = CODED_FALSE;
   s_m2d_msg.payload.hil_ipc_info.hil_src_vehicle_data = 0xFF; /* Don't care when HIL disabled */

   Is_IPC_Notify_Buffer_Full_fake.return_val   = 0U;
   Get_Received_Doppler_Done_fake.return_val   = true;
   Get_IPC_Notify_Buffer_fake.return_val       = &s_notify_msg;
   Get_IPC_M2D_Msg_Buffer_fake.return_val      = &s_m2d_msg;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val  = &s_m2d_msg;
   Get_Stream_Rx_Info_Data_Ptr_fake.return_val = (uint8_t *)&s_vid_stream;
   R52_BBE_Trigger_fake.return_val             = false;

   DSP_Processing_Per_Look_Init();

   bool vehicle_data_copied = false;
   for (uint8_t raw_index = 0U; raw_index < VSE_STREAM_RAW_INSTANCES; ++raw_index)
   {
      if ((s_m2d_msg.payload.veh_data.veh_raw_data[raw_index].ego_vehicle_speed == 42.5F) &&
          (s_m2d_msg.payload.veh_data.veh_raw_data[raw_index].ego_yaw_rate == 0.25F) &&
          (s_m2d_msg.payload.veh_data.veh_raw_data[raw_index].steering_whl_angle == 15.0F))
      {
         vehicle_data_copied = true;
         break;
      }
   }

   EXPECT_TRUE(vehicle_data_copied);
   EXPECT_EQ(s_m2d_msg.payload.veh_data.veh_raw_misc.ego_vehicle_speed_qf, 0x03U);
   EXPECT_EQ(s_m2d_msg.payload.veh_data.veh_raw_misc.ego_yaw_rate_qf, 0x02U);
   EXPECT_EQ(s_m2d_msg.payload.veh_data.veh_raw_misc.vehicle_standstill, 0x00U);
}

/**
 *  @b per_look_init_hil_enabled_with_execute_vehicle_com_copies_vehicle_data_02
 *  @n
 *      DSP_Processing_Per_Look_Init should copy vehicle data when HIL mode is ENABLED
 *      AND hil_src_vehicle_data is HIL_EXECUTE_VEHICLE_COM_DATA (bypass condition met).
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, PerLookInit_HilEnabledWithExecuteVehicleCom_CopiesVehicleData)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   static Vid_Stream_T s_vid_stream;
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));
   memset(&s_vid_stream, 0, sizeof(s_vid_stream));

   /* Setup VID stream with test values */
   s_vid_stream.veh_params.veh_speed = 55.5F;
   s_vid_stream.veh_params.veh_yaw   = 0.5F;

   /* Setup M2D message with HIL mode ENABLED + EXECUTE_VEHICLE_COM_DATA */
   s_m2d_msg.payload.hil_ipc_info.hil_mode_enabled     = CODED_TRUE;
   s_m2d_msg.payload.hil_ipc_info.hil_src_vehicle_data = HIL_EXECUTE_VEHICLE_COM_DATA;

   Is_IPC_Notify_Buffer_Full_fake.return_val   = 0U;
   Get_Received_Doppler_Done_fake.return_val   = true;
   Get_IPC_Notify_Buffer_fake.return_val       = &s_notify_msg;
   Get_IPC_M2D_Msg_Buffer_fake.return_val      = &s_m2d_msg;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val  = &s_m2d_msg;
   Get_Stream_Rx_Info_Data_Ptr_fake.return_val = (uint8_t *)&s_vid_stream;
   R52_BBE_Trigger_fake.return_val             = false;

   DSP_Processing_Per_Look_Init();

   /* Verify vehicle data is copied when using EXECUTE_VEHICLE_COM_DATA */
   bool vehicle_data_copied = false;
   for (uint8_t raw_index = 0U; raw_index < VSE_STREAM_RAW_INSTANCES; ++raw_index)
   {
      if ((s_m2d_msg.payload.veh_data.veh_raw_data[raw_index].ego_vehicle_speed == 55.5F) &&
          (s_m2d_msg.payload.veh_data.veh_raw_data[raw_index].ego_yaw_rate == 0.5F))
      {
         vehicle_data_copied = true;
         break;
      }
   }

   EXPECT_TRUE(vehicle_data_copied);
}

/**
 *  @b per_look_init_hil_enabled_with_other_source_skips_vehicle_data_03
 *  @n
 *      DSP_Processing_Per_Look_Init should NOT copy vehicle data when HIL mode is ENABLED
 *      AND hil_src_vehicle_data is NOT HIL_EXECUTE_VEHICLE_COM_DATA (bypass condition not met).
 *      This bypasses vehicle data when HIL is providing simulated data.
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, PerLookInit_HilEnabledWithNonExecuteSource_SkipsVehicleDataCopy)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   static Vid_Stream_T s_vid_stream;
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));
   memset(&s_vid_stream, 0, sizeof(s_vid_stream));

   /* Store original values that should NOT be overwritten */
   const float32_t original_speed                                = 77.7F;
   const float32_t original_yaw                                  = 0.77F;
   s_m2d_msg.payload.veh_data.veh_raw_data[0U].ego_vehicle_speed = original_speed;
   s_m2d_msg.payload.veh_data.veh_raw_data[0U].ego_yaw_rate      = original_yaw;

   /* Setup VID stream with different values */
   s_vid_stream.veh_params.veh_speed = 99.9F;
   s_vid_stream.veh_params.veh_yaw   = 0.99F;

   /* Setup M2D message with HIL mode ENABLED + different source (not EXECUTE_VEHICLE_COM_DATA) */
   s_m2d_msg.payload.hil_ipc_info.hil_mode_enabled = CODED_TRUE;
   s_m2d_msg.payload.hil_ipc_info.hil_src_vehicle_data =
      HIL_EXECUTE_INJECTION_DATA; /* or any value != HIL_EXECUTE_VEHICLE_COM_DATA */

   Is_IPC_Notify_Buffer_Full_fake.return_val   = 0U;
   Get_Received_Doppler_Done_fake.return_val   = true;
   Get_IPC_Notify_Buffer_fake.return_val       = &s_notify_msg;
   Get_IPC_M2D_Msg_Buffer_fake.return_val      = &s_m2d_msg;
   Get_Stream_Rx_Info_Data_Ptr_fake.return_val = (uint8_t *)&s_vid_stream;
   R52_BBE_Trigger_fake.return_val             = false;

   DSP_Processing_Per_Look_Init();

   /* Verify vehicle data was NOT copied (original values retained) */
   EXPECT_EQ(s_m2d_msg.payload.veh_data.veh_raw_data[0U].ego_vehicle_speed, original_speed);
   EXPECT_EQ(s_m2d_msg.payload.veh_data.veh_raw_data[0U].ego_yaw_rate, original_yaw);
}

/**
 *  @b per_look_init_hil_enabled_with_zero_source_skips_vehicle_data_04
 *  @n
 *      DSP_Processing_Per_Look_Init should NOT copy vehicle data when HIL mode is ENABLED
 *      AND hil_src_vehicle_data is 0 (treated as a different/invalid source value).
 */
TEST_F(Dsp_Setup_Unit_Test_Suite, PerLookInit_HilEnabledWithZeroSource_SkipsVehicleDataCopy)
{
   static Ipc_Notify_Structure_T s_notify_msg;
   static volatile M2D_Msg_T s_m2d_msg;
   static Vid_Stream_T s_vid_stream;
   memset((void *)&s_m2d_msg, 0, sizeof(s_m2d_msg));
   memset(&s_vid_stream, 0, sizeof(s_vid_stream));

   /* Store original values that should NOT be overwritten */
   const float32_t original_speed                                = 11.1F;
   s_m2d_msg.payload.veh_data.veh_raw_data[0U].ego_vehicle_speed = original_speed;

   /* Setup VID stream with different value */
   s_vid_stream.veh_params.veh_speed = 22.2F;

   /* Setup M2D message with HIL mode ENABLED + source value = 0 */
   s_m2d_msg.payload.hil_ipc_info.hil_mode_enabled     = CODED_TRUE;
   s_m2d_msg.payload.hil_ipc_info.hil_src_vehicle_data = 0U; /* Not HIL_EXECUTE_VEHICLE_COM_DATA */

   Is_IPC_Notify_Buffer_Full_fake.return_val   = 0U;
   Get_Received_Doppler_Done_fake.return_val   = true;
   Get_IPC_Notify_Buffer_fake.return_val       = &s_notify_msg;
   Get_IPC_M2D_Msg_Buffer_fake.return_val      = &s_m2d_msg;
   Get_Stream_Rx_Info_Data_Ptr_fake.return_val = (uint8_t *)&s_vid_stream;
   R52_BBE_Trigger_fake.return_val             = false;

   DSP_Processing_Per_Look_Init();

   /* Verify vehicle data was NOT copied */
   EXPECT_EQ(s_m2d_msg.payload.veh_data.veh_raw_data[0U].ego_vehicle_speed, original_speed);
}
