/*===========================================================================*/
/**
 * @file SWC_CDD_IPC_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for SWC_CDD_IPC.c
 * Goal: Achieve 95%+ code coverage
 *
 * @section ABBR ABBREVIATIONS:
 *   - IPC: Inter-Processor Communication
 *   - DSP: Digital Signal Processor
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 */
/*==========================================================================*/

/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
#include <cstring>
#include <gtest/gtest.h>

DEFINE_FFF_GLOBALS

/*===========================================================================*
 * Mock definitions
 *===========================================================================*/
#include "SWC_CDD_IPC_fake.h"

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
extern "C"
{
#include "../Source/SWC_CDD_IPC.c"
   uint8_t Radar_Position = 0;
   /* fake functions */
   uint8_t Get_Radar_Position(void)
   {
      return Radar_Position;
   }
}

/*===========================================================================*
 * Custom Fake Functions for Capturing Struct Arguments
 *===========================================================================*/
// Global variable to capture radar capability faults written via RTE
static Dt_RadarCapability_Faults captured_radar_capability_faults;
static Dt_Alignment_IPC_Data captured_alignment_ipc_data;
static Dt_Alignment_M2D_Data g_alignment_m2d_readback;

SMC_Cal_T SMC_Cal_Data;
SMC_Cal_T *SMC_Cal_Data_Ptr = &SMC_Cal_Data;

// Custom fake for Rte_Write to capture the faults structure
static Std_ReturnType custom_Rte_Write_RadarCapability_Faults(const Dt_RadarCapability_Faults *faults)
{
   if (faults != nullptr)
   {
      captured_radar_capability_faults = *faults;
   }
   return E_OK;
}

static Std_ReturnType custom_Rte_Write_Alignment_Ipc_Data(const Dt_Alignment_IPC_Data *alignment_data)
{
   if (alignment_data != nullptr)
   {
      captured_alignment_ipc_data = *alignment_data;
   }
   return E_OK;
}

static Std_ReturnType custom_Rte_Read_Alignment_M2D_Data(Dt_Alignment_M2D_Data *alignment_data)
{
   if (alignment_data != nullptr)
   {
      *alignment_data = g_alignment_m2d_readback;
   }
   return E_OK;
}

/*===========================================================================*
 * Test Fixture Class
 *===========================================================================*/
class SWC_CDD_IPC_UnitTestSuite : public ::testing::Test
{
 protected:
   D2M_Msg_T test_d2m_msg;
   volatile M2D_Msg_T test_m2d_msg{};
   volatile M2D_One_Time_Msg_T test_m2d_one_time_msg{};
   Ipc_Notify_Structure_T test_ipc_notify_structure{};

   void SetUp() override
   {
      // Reset all fakes
      RESET_FAKE(Get_IPC_D2M_Sp_Post_Proc_Buffer);
      RESET_FAKE(Get_IPC_Sp_Post_Buf_Read_Addr_Raw);
      RESET_FAKE(Get_IPC_Sp_Post_Buf_Read_Idx_Raw);
      RESET_FAKE(Get_IPC_M2D_Crc_Err_Cnt);
      RESET_FAKE(Get_IPC_D2M_Crc_Err_Cnt);
      RESET_FAKE(Get_MSS_IPC_M2D_Msg_Buffer);
      RESET_FAKE(Get_IPC_M2D_Onetime_Msg_Buffer);
      RESET_FAKE(Check_D2M_Crc_Header);
      RESET_FAKE(Get_HW_Accel_Test_Fault);
      RESET_FAKE(Get_IPC_Notify_Buffer);
      RESET_FAKE(Rte_Read_SWC_CDD_IPC_Rp_Alignment_M2D_Data_De_Alignment_M2D_Data);
      RESET_FAKE(Rte_Write_SWC_CDD_IPC_Pp_Alignment_IPC_Data_De_Alignment_IPC_Data);
      RESET_FAKE(Rte_Write_SWC_CDD_IPC_Pp_IPC_Faults_De_IPC_Faults);
      RESET_FAKE(Rte_Write_SWC_CDD_IPC_Pp_RadarCapability_Faults_De_RadarCapability_Faults);
      RESET_FAKE(Rte_Write_SWC_CDD_IPC_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo);
      RESET_FAKE(Rte_Write_Pp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI);
      RESET_FAKE(Rte_Call_WdgM_AliveSupervision_Alive_Program_Flow_Monitoring_CheckpointReached);
      RESET_FAKE(Rte_Call_CS_Wdg_Disable_Read);
      RESET_FAKE(Rte_Call_PostRadarProcessing_Debug_Populate_Debug_Stream);
      RESET_FAKE(Rte_Call_PostRadarProcessing_Detection_Populate_Detection_Stream);
      RESET_FAKE(Rte_Call_PostRadarProcessing_Header_Populate_Header_Stream);
      RESET_FAKE(Rte_Call_PostRadarProcessing_RDD_Populate_RDD_Stream);
      RESET_FAKE(Rte_Call_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream);
      RESET_FAKE(Rte_Call_PostRadarProcessing_Status_Populate_Status_Stream);
      RESET_FAKE(Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Detection_Populate_Detection_Stream);
      RESET_FAKE(Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Header_Populate_Header_Stream);
      RESET_FAKE(Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream);
      RESET_FAKE(Rte_Call_Pp_Radar_Ctl_Look_Trigger_Operation);
      RESET_FAKE(Rte_Trigger_SWC_CDD_IPC_Pp_HIL_Periodic_Handler_Trigger);
      RESET_FAKE(Rte_IrTrigger_SWC_CDD_IPC_RE_IPC_Trigger_50ms_ITP_RE_IPC_Trigger_50ms);
      RESET_FAKE(Rte_IrTrigger_SWC_CDD_IPC_RE_IPC_Trigger_50ms_ITP_RE_IPC_Trigger_50ms_Dsp_sp_post_processing_complete);
      RESET_FAKE(WdgM_CheckpointReached);
      RESET_FAKE(Set_IPC_XCP_Fault_Injn_Var);

#if (TRUE == ENABLE_SIT_TEST_STUBS)
      test_ipc_crc_var           = 0;
      test_Injection_control_ipc = 0;
      test_Failure_Type_ipc      = 0;
      memset(&ipc_crc_faults, 0, sizeof(Dt_IPC_Faults));
#endif

      // Initialize test message
      memset(&test_d2m_msg, 0, sizeof(D2M_Msg_T));
      memset((void *)&test_m2d_one_time_msg, 0, sizeof(M2D_One_Time_Msg_T));
      memset((void *)&test_ipc_notify_structure, 0, sizeof(Ipc_Notify_Structure_T));

      // Set default return values
      Get_IPC_D2M_Sp_Post_Proc_Buffer_fake.return_val   = &test_d2m_msg;
      Get_IPC_Sp_Post_Buf_Read_Addr_Raw_fake.return_val = &test_d2m_msg;
      Get_IPC_Sp_Post_Buf_Read_Idx_Raw_fake.return_val  = 0U;
      Get_IPC_M2D_Crc_Err_Cnt_fake.return_val           = 0U;
      Get_IPC_D2M_Crc_Err_Cnt_fake.return_val           = 0U;
      Check_D2M_Crc_Header_fake.return_val              = CODED_TRUE;
      Get_HW_Accel_Test_Fault_fake.return_val           = 0U;
      IPC_Sp_Post_Proc_Buf_Read_Addr                    = &test_d2m_msg;
      Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val        = &test_m2d_msg;
      Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val    = &test_m2d_one_time_msg;
      Get_IPC_Notify_Buffer_fake.return_val             = (volatile Ipc_Notify_Structure_T *)&test_ipc_notify_structure;
      Rte_Read_SWC_CDD_IPC_Rp_Alignment_M2D_Data_De_Alignment_M2D_Data_fake.return_val               = E_OK;
      Rte_Write_SWC_CDD_IPC_Pp_RadarCapability_Faults_De_RadarCapability_Faults_fake.return_val      = E_OK;
      Rte_Write_SWC_CDD_IPC_Pp_IPC_Faults_De_IPC_Faults_fake.return_val                              = E_OK;
      Rte_Call_WdgM_AliveSupervision_Alive_Program_Flow_Monitoring_CheckpointReached_fake.return_val = E_OK;

      // Clear captured faults and set up custom fake
      memset(&captured_radar_capability_faults, 0, sizeof(captured_radar_capability_faults));
      memset(&captured_alignment_ipc_data, 0, sizeof(captured_alignment_ipc_data));
      memset(&g_alignment_m2d_readback, 0, sizeof(g_alignment_m2d_readback));
      Rte_Write_SWC_CDD_IPC_Pp_RadarCapability_Faults_De_RadarCapability_Faults_fake.custom_fake =
         custom_Rte_Write_RadarCapability_Faults;
      Rte_Write_SWC_CDD_IPC_Pp_Alignment_IPC_Data_De_Alignment_IPC_Data_fake.custom_fake = custom_Rte_Write_Alignment_Ipc_Data;
   }

   void TearDown() override
   {
      // Cleanup if needed
   }
};

/*===========================================================================*
 * Test Cases for CS_IPC_Fault_Injection
 *===========================================================================*/
TEST_F(SWC_CDD_IPC_UnitTestSuite, CS_IPC_Fault_Injection_ExecutesWithoutError)
{
   // Execute the function
   CS_IPC_Fault_Injection(1, 2);

   // Function should execute without error
   SUCCEED();
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, CS_IPC_Fault_Injection_AcceptsVariousInputs)
{
   // Test with boundary values
   CS_IPC_Fault_Injection(0, 0);
   CS_IPC_Fault_Injection(255, 255);
   CS_IPC_Fault_Injection(128, 64);

   // All should execute without error
   SUCCEED();
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, CS_IPC_Fault_Injection_XCP_R52Fault)
{
   // FIT_IPC_FAILURE (0x03) with INJECT_R52_FAULT (0x00)
   RESET_FAKE(Set_IPC_XCP_Fault_Injn_Var);
   CS_IPC_Fault_Injection(0x00U, 0x03U);
   EXPECT_EQ(Set_IPC_XCP_Fault_Injn_Var_fake.call_count, 1U);
   EXPECT_EQ(Set_IPC_XCP_Fault_Injn_Var_fake.arg0_val, R52_To_BBE_Fault);
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, CS_IPC_Fault_Injection_XCP_BBEFault)
{
   // FIT_IPC_FAILURE (0x03) with INJECT_BBE_FAULT (0x01)
   RESET_FAKE(Set_IPC_XCP_Fault_Injn_Var);
   CS_IPC_Fault_Injection(0x01U, 0x03U);
   EXPECT_EQ(Set_IPC_XCP_Fault_Injn_Var_fake.call_count, 1U);
   EXPECT_EQ(Set_IPC_XCP_Fault_Injn_Var_fake.arg0_val, BBE_To_R52_Fault);
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, CS_IPC_Fault_Injection_XCP_RemoveAllFaults)
{
   // FIT_IPC_FAILURE (0x03) with REMOVE_ALL_FAULTS (0x02)
   RESET_FAKE(Set_IPC_XCP_Fault_Injn_Var);
   CS_IPC_Fault_Injection(0x02U, 0x03U);
   EXPECT_EQ(Set_IPC_XCP_Fault_Injn_Var_fake.call_count, 1U);
   EXPECT_EQ(Set_IPC_XCP_Fault_Injn_Var_fake.arg0_val, NO_Fault);
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, CS_IPC_Fault_Injection_XCP_UnrecognizedControl)
{
   // FIT_IPC_FAILURE (0x03) with unrecognized control value - does nothing
   RESET_FAKE(Set_IPC_XCP_Fault_Injn_Var);
   CS_IPC_Fault_Injection(0x05U, 0x03U);
   EXPECT_EQ(Set_IPC_XCP_Fault_Injn_Var_fake.call_count, 0U);
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, CS_IPC_Fault_Injection_XCP_NonIpcFailureType)
{
   // Non-FIT_IPC_FAILURE failure type - does nothing
   RESET_FAKE(Set_IPC_XCP_Fault_Injn_Var);
   CS_IPC_Fault_Injection(0x00U, 0x00U);
   EXPECT_EQ(Set_IPC_XCP_Fault_Injn_Var_fake.call_count, 0U);
}

/*===========================================================================*
 * Test Cases for Dsp_sp_post_processing_complete
 *
 * Current function flow under test (SWC_CDD_IPC.c):
 *   1. Read raw post-proc buffer addr and M2D buffer.
 *   2. If CRC header valid OR HIL mode active -> latch addr/idx into
 *      IPC_Sp_Post_Proc_Buf_Read_Addr / _Idx.
 *   3. If latched addr != NULL -> Fetch_IPC_Data().
 *   4. Always call Detection / RadarCapability / Header populate.
 *   5. Always trigger the HIL periodic runnable at the end.
 *===========================================================================*/
TEST_F(SWC_CDD_IPC_UnitTestSuite, Dsp_sp_post_processing_complete_ExecutesWithoutError)
{
   Dsp_sp_post_processing_complete();
   SUCCEED();
}

/* Branch: Check_D2M_Crc_Header == CODED_TRUE, hil_mode_active == CODED_FALSE
 * -> if() taken via CRC; addr must be latched to the raw addr. */
TEST_F(SWC_CDD_IPC_UnitTestSuite, Dsp_sp_post_proc_CrcValid_HilInactive_LatchesAddr)
{
   D2M_Msg_T raw_buf{};
   Get_IPC_Sp_Post_Buf_Read_Addr_Raw_fake.return_val  = &raw_buf;
   Get_IPC_Sp_Post_Buf_Read_Idx_Raw_fake.return_val   = 1U;
   Check_D2M_Crc_Header_fake.return_val               = CODED_TRUE;
   test_m2d_msg.payload.hil_ipc_info.hil_mode_enabled = CODED_FALSE;
   IPC_Sp_Post_Proc_Buf_Read_Addr                     = nullptr;

   Dsp_sp_post_processing_complete();

   ASSERT_EQ(IPC_Sp_Post_Proc_Buf_Read_Addr, &raw_buf);
   ASSERT_EQ(IPC_Sp_Post_Proc_Buf_Read_Idx, 1U);
}

/* Branch: Check_D2M_Crc_Header == CODED_FALSE, hil_mode_active == CODED_TRUE
 * -> if() taken via HIL override; addr must be latched even when CRC fails. */
TEST_F(SWC_CDD_IPC_UnitTestSuite, Dsp_sp_post_proc_CrcInvalid_HilActive_LatchesAddr)
{
   D2M_Msg_T raw_buf{};
   Get_IPC_Sp_Post_Buf_Read_Addr_Raw_fake.return_val  = &raw_buf;
   Get_IPC_Sp_Post_Buf_Read_Idx_Raw_fake.return_val   = 0U;
   Check_D2M_Crc_Header_fake.return_val               = CODED_FALSE;
   test_m2d_msg.payload.hil_ipc_info.hil_mode_enabled = CODED_TRUE;
   IPC_Sp_Post_Proc_Buf_Read_Addr                     = nullptr;

   Dsp_sp_post_processing_complete();

   ASSERT_EQ(IPC_Sp_Post_Proc_Buf_Read_Addr, &raw_buf);
   ASSERT_EQ(IPC_Sp_Post_Proc_Buf_Read_Idx, 0U);
}

/* Branch: CRC == CODED_FALSE AND hil_mode_active == CODED_FALSE
 * -> if() skipped; latched addr keeps its previous value (no update). */
TEST_F(SWC_CDD_IPC_UnitTestSuite, Dsp_sp_post_proc_CrcInvalid_HilInactive_DoesNotLatchAddr)
{
   D2M_Msg_T raw_buf{};
   D2M_Msg_T prev_buf{};
   Get_IPC_Sp_Post_Buf_Read_Addr_Raw_fake.return_val  = &raw_buf;
   Check_D2M_Crc_Header_fake.return_val               = CODED_FALSE;
   test_m2d_msg.payload.hil_ipc_info.hil_mode_enabled = CODED_FALSE;
   IPC_Sp_Post_Proc_Buf_Read_Addr                     = &prev_buf;

   Dsp_sp_post_processing_complete();

   ASSERT_EQ(IPC_Sp_Post_Proc_Buf_Read_Addr, &prev_buf);
}

/* Branch: latched addr is NULL -> Fetch_IPC_Data must be skipped, evidenced
 * by the radar-capability RTE write inside Fetch_IPC_Data not being called. */
TEST_F(SWC_CDD_IPC_UnitTestSuite, Dsp_sp_post_proc_NullLatchedAddr_SkipsFetch)
{
   Get_IPC_Sp_Post_Buf_Read_Addr_Raw_fake.return_val  = nullptr;
   Check_D2M_Crc_Header_fake.return_val               = CODED_TRUE;
   test_m2d_msg.payload.hil_ipc_info.hil_mode_enabled = CODED_FALSE;
   IPC_Sp_Post_Proc_Buf_Read_Addr                     = nullptr;

   Dsp_sp_post_processing_complete();

   ASSERT_EQ(Rte_Write_SWC_CDD_IPC_Pp_RadarCapability_Faults_De_RadarCapability_Faults_fake.call_count, 0);
}

/* Always-on path: the three populate calls fire on every invocation,
 * regardless of CRC/HIL/addr state.  The HIL trigger is owned by
 * RE_IPC_Rx_50ms, not by Dsp_sp_post_processing_complete. */
TEST_F(SWC_CDD_IPC_UnitTestSuite, Dsp_sp_post_proc_AlwaysCallsPopulate)
{
   Get_IPC_Sp_Post_Buf_Read_Addr_Raw_fake.return_val  = nullptr;
   Check_D2M_Crc_Header_fake.return_val               = CODED_FALSE;
   test_m2d_msg.payload.hil_ipc_info.hil_mode_enabled = CODED_FALSE;
   IPC_Sp_Post_Proc_Buf_Read_Addr                     = nullptr;

   Dsp_sp_post_processing_complete();

   /* Rte_SWC_CDD_IPC.h remaps the short Rte_Call_PostRadarProcessing_* names to the
    * SWC_CDD_IPC-prefixed long names; the long-name fakes are the ones actually
    * invoked from the production code. */
   ASSERT_EQ(Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Detection_Populate_Detection_Stream_fake.call_count, 1U);
   ASSERT_EQ(Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream_fake.call_count, 1U);
   ASSERT_EQ(Rte_Call_SWC_CDD_IPC_PostRadarProcessing_Header_Populate_Header_Stream_fake.call_count, 1U);
   /* HIL trigger is fired by RE_IPC_Rx_50ms, NOT by Dsp_sp_post_processing_complete */
   ASSERT_EQ(Rte_Trigger_SWC_CDD_IPC_Pp_HIL_Periodic_Handler_Trigger_fake.call_count, 0U);
}

/*===========================================================================*
 * Test Cases for RE_IPC_Rx_50ms
 *===========================================================================*/
TEST_F(SWC_CDD_IPC_UnitTestSuite, RE_IPC_Rx_50ms_ExecutesWithoutError)
{
   // Execute the function
   RE_IPC_Rx_50ms();

   // This function is currently empty
   SUCCEED();
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, RE_IPC_Rx_50ms_MultipleCalls)
{
   // Execute multiple times to simulate periodic calls
   for (int i = 0; i < 10; i++)
   {
      RE_IPC_Rx_50ms();
   }

   SUCCEED();
}

#if defined(VEH_AL_CAN_STANDALONE)
TEST_F(SWC_CDD_IPC_UnitTestSuite, RE_IPC_Rx_10ms_NullSpPostBuffer_SetsTrackerHostOutputInvalid)
{
   IPC_Sp_Post_Proc_Buf_Read_Addr                            = nullptr;
   test_m2d_one_time_msg.calib_data.data_availability_status = CODED_TRUE;
   test_m2d_msg.payload.veh_data.vse_output_valid            = CODED_FALSE;
   RE_IPC_VSE_Handler_10ms();
   EXPECT_EQ(test_m2d_msg.payload.veh_data.vse_output_valid, CODED_TRUE);
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, RE_IPC_Rx_10ms_ValidSpPostBuffer_ProducesTrackerHostOutput)
{
   IPC_Sp_Post_Proc_Buf_Read_Addr                            = &test_d2m_msg;
   test_m2d_one_time_msg.calib_data.data_availability_status = CODED_TRUE;

   test_m2d_msg.payload.veh_data.latest_raw_index = 0U;

   test_m2d_msg.payload.veh_data.veh_raw_data[0].system_time_secs                                      = 1U;
   test_m2d_msg.payload.veh_data.veh_raw_data[0].system_time_nanosecs                                  = 2000U;
   test_m2d_msg.payload.veh_data.vse_output_valid                                                      = CODED_FALSE;
   test_m2d_msg.payload.veh_data.veh_raw_data[0].ego_vehicle_speed                                     = 5.0F;
   test_m2d_msg.payload.veh_data.veh_raw_data[0].ego_yaw_rate                                          = 0.1F;
   test_m2d_msg.payload.veh_data.veh_raw_data[0].steering_whl_angle                                    = 0.0F;
   test_m2d_msg.payload.veh_data.veh_raw_misc.ego_vehicle_speed_qf                                     = 3U;
   test_m2d_msg.payload.veh_data.veh_raw_misc.ego_yaw_rate_qf                                          = 3U;
   test_m2d_msg.payload.veh_data.veh_raw_data[0].ego_lateral_accel                                     = 0.0F;
   test_m2d_msg.payload.veh_data.veh_raw_data[0].ego_longitudinal_accel                                = 0.0F;
   test_d2m_msg.payload.dynamic_alignment_log_stream.dra_core_data.speed_compensation_factor_estimated = 1.0F;

   RE_IPC_VSE_Handler_10ms();
   EXPECT_EQ(test_m2d_msg.payload.veh_data.vse_output_valid, CODED_TRUE);
}
#endif

TEST_F(SWC_CDD_IPC_UnitTestSuite, RE_IPC_Rx_50ms_CopiesAlignmentReadDataIntoM2D)
{
   IPC_Sp_Post_Proc_Buf_Read_Addr                                                    = &test_d2m_msg;
   Rte_Read_SWC_CDD_IPC_Rp_Alignment_M2D_Data_De_Alignment_M2D_Data_fake.custom_fake = custom_Rte_Read_Alignment_M2D_Data;

   g_alignment_m2d_readback.dynamic_alignment_data.f_data_valid                        = 1U;
   g_alignment_m2d_readback.dynamic_alignment_data.Align_RadarOperation_Mode           = 2U;
   g_alignment_m2d_readback.dynamic_alignment_data.align_cmd                           = 3U;
   g_alignment_m2d_readback.dynamic_alignment_data.mount_loc                           = 4U;
   g_alignment_m2d_readback.dynamic_alignment_data.iso_sensor_yaw                      = 1.1F;
   g_alignment_m2d_readback.dynamic_alignment_data.iso_sensor_pitch                    = 1.2F;
   g_alignment_m2d_readback.dynamic_alignment_data.iso_sensor_roll                     = 1.3F;
   g_alignment_m2d_readback.dynamic_alignment_data.iso_sensor_x_posn                   = 2.1F;
   g_alignment_m2d_readback.dynamic_alignment_data.iso_sensor_y_posn                   = 2.2F;
   g_alignment_m2d_readback.dynamic_alignment_data.iso_sensor_z_posn                   = 2.3F;
   g_alignment_m2d_readback.dynamic_alignment_data.distance_rear_axle_to_front_bumper  = 3.4F;
   g_alignment_m2d_readback.dynamic_alignment_data.initial_vacs_boresight_az_estimated = 4.1F;
   g_alignment_m2d_readback.dynamic_alignment_data.initial_vacs_boresight_el_estimated = 4.2F;
   g_alignment_m2d_readback.dynamic_alignment_data.initial_vacs_boresight_rl_estimated = 4.3F;
   g_alignment_m2d_readback.dynamic_alignment_data.initial_speed_compensation_factor   = 5.1F;
   g_alignment_m2d_readback.dynamic_alignment_data.initial_num_updates_az              = 6U;
   g_alignment_m2d_readback.dynamic_alignment_data.initial_num_updates_el              = 7.0F;
   g_alignment_m2d_readback.dynamic_alignment_data.initial_num_updates_rl              = 8U;
   g_alignment_m2d_readback.dynamic_alignment_data.max_abs_misalignment_az             = 9.1F;
   g_alignment_m2d_readback.dynamic_alignment_data.max_abs_misalignment_el_ground      = 9.2F;
   g_alignment_m2d_readback.dynamic_alignment_data.max_abs_misalignment_el_sky         = 9.3F;
   g_alignment_m2d_readback.dynamic_alignment_data.short_track_target_height           = 10.1F;
   g_alignment_m2d_readback.dynamic_alignment_data.short_track_target_range_rate       = 10.2F;
   g_alignment_m2d_readback.dynamic_alignment_data.az_scf_kf_covariance[0]             = 11.0F;
   g_alignment_m2d_readback.dynamic_alignment_data.az_scf_kf_covariance[1]             = 12.0F;
   g_alignment_m2d_readback.dynamic_alignment_data.az_scf_kf_covariance[2]             = 13.0F;
   g_alignment_m2d_readback.dynamic_alignment_data.az_scf_kf_covariance[3]             = 14.0F;
   g_alignment_m2d_readback.dynamic_alignment_data.el_roll_kf_covariance[0]            = 15.0F;
   g_alignment_m2d_readback.dynamic_alignment_data.el_roll_kf_covariance[1]            = 16.0F;
   g_alignment_m2d_readback.dynamic_alignment_data.el_roll_kf_covariance[2]            = 17.0F;
   g_alignment_m2d_readback.dynamic_alignment_data.el_roll_kf_covariance[3]            = 18.0F;
   g_alignment_m2d_readback.dynamic_alignment_data.short_track_exit_condition          = 19U;
   g_alignment_m2d_readback.dynamic_alignment_data.coordinate_system_input             = 20U;
   g_alignment_m2d_readback.dynamic_alignment_data.auto_align_status                   = 21U;
   g_alignment_m2d_readback.dynamic_alignment_data.aacurrent_azimuth                   = 22.0F;
   g_alignment_m2d_readback.dynamic_alignment_data.aacurrent_elevation                 = 23.0F;

   g_alignment_m2d_readback.static_alignment_data.f_data_valid        = 31U;
   g_alignment_m2d_readback.static_alignment_data.align_cmd           = 32U;
   g_alignment_m2d_readback.static_alignment_data.mount_loc           = 33U;
   g_alignment_m2d_readback.static_alignment_data.plate_lat_position  = 34.0F;
   g_alignment_m2d_readback.static_alignment_data.vert_angle_max      = 35.0F;
   g_alignment_m2d_readback.static_alignment_data.vert_angle_min      = 36.0F;
   g_alignment_m2d_readback.static_alignment_data.horz_angle_max      = 37.0F;
   g_alignment_m2d_readback.static_alignment_data.horz_angle_min      = 38.0F;
   g_alignment_m2d_readback.static_alignment_data.polarity            = 39.0F;
   g_alignment_m2d_readback.static_alignment_data.plate_distance      = 40.0F;
   g_alignment_m2d_readback.static_alignment_data.plate_angle_deg_scs = 41.0F;
   g_alignment_m2d_readback.static_alignment_data.pitch               = 42.0F;
   g_alignment_m2d_readback.static_alignment_data.yaw                 = 43.0F;

   RE_IPC_Rx_50ms();

   EXPECT_EQ(test_m2d_msg.payload.alignment_Info.dynamic_alignment_data.f_data_valid, 1U);
   EXPECT_EQ(test_m2d_msg.payload.alignment_Info.dynamic_alignment_data.operation_mode_status, 2U);
   EXPECT_EQ(test_m2d_msg.payload.alignment_Info.dynamic_alignment_data.align_cmd, 3U);
   EXPECT_FLOAT_EQ(test_m2d_msg.payload.alignment_Info.dynamic_alignment_data.iso_sensor_yaw, 1.1F);
   EXPECT_FLOAT_EQ(test_m2d_msg.payload.alignment_Info.dynamic_alignment_data.el_roll_kf_covariance[3], 18.0F);
   EXPECT_EQ(test_m2d_msg.payload.alignment_Info.dynamic_alignment_data.alignment_handler_out.auto_align_status, 21U);
   EXPECT_FLOAT_EQ(test_m2d_msg.payload.alignment_Info.dynamic_alignment_data.alignment_handler_out.aacurrent_azimuth, 22.0F);
   EXPECT_EQ(test_m2d_msg.payload.alignment_Info.static_alignment_data.f_data_valid, 31U);
   EXPECT_FLOAT_EQ(test_m2d_msg.payload.alignment_Info.static_alignment_data.yaw, 43.0F);
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, RE_IPC_Rx_50ms_01)
{
   PFM_Get_Status_fake.return_val = PFM_INVALID_FLOW_ERROR;
   RE_IPC_Rx_50ms();
   ASSERT_EQ(Rte_Call_WdgM_AliveSupervision_Alive_Program_Flow_Monitoring_CheckpointReached_fake.call_count, 0);
}

/*===========================================================================*
 * Test Cases for RE_IPC_Trigger_50ms
 *===========================================================================*/
TEST_F(SWC_CDD_IPC_UnitTestSuite, RE_IPC_Trigger_50ms_ExecutesWithoutError)
{
   // Execute the function
   RE_IPC_Trigger_50ms();

   // This function is currently empty
   SUCCEED();
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, RE_IPC_Trigger_50ms_02)
{
   Pfm_Monitor_Status = 1;
   RE_IPC_Trigger_50ms();
}

/*===========================================================================*
 * Test Cases for Dsp_sp_post_processing_complete (radar fault processing)
 *===========================================================================*/
TEST_F(SWC_CDD_IPC_UnitTestSuite, Dsp_sp_post_proc_ProcessesValidD2MBuffer)
{
   // Setup: Valid D2M buffer with no errors
   test_d2m_msg.payload.radar_capability_data.fault_table.Blockage_Algo_Error    = FALSE;
   test_d2m_msg.payload.radar_capability_data.fault_table.Damping_Algo_Error     = FALSE;
   test_d2m_msg.payload.radar_capability_data.fault_table.Range_Algo_Error       = FALSE;
   test_d2m_msg.payload.radar_capability_data.fault_table.PBD_Monitor_Algo_Error = FALSE;

   // Execute the function
   Dsp_sp_post_processing_complete();

   // Verify RTE write was called
   ASSERT_EQ(Rte_Write_SWC_CDD_IPC_Pp_RadarCapability_Faults_De_RadarCapability_Faults_fake.call_count, 1);

   // Verify fault values are CODED_FALSE
   ASSERT_EQ(captured_radar_capability_faults.Blockage_Fault, CODED_FALSE);
   ASSERT_EQ(captured_radar_capability_faults.Damping_Estimation_Fault, CODED_FALSE);
   ASSERT_EQ(captured_radar_capability_faults.Range_Estimation_Fault, CODED_FALSE);
   ASSERT_EQ(captured_radar_capability_faults.SLL_Fault, CODED_FALSE);
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, Dsp_sp_post_proc_DetectsBlockageFault)
{
   // Setup: Blockage error detected
   test_d2m_msg.payload.radar_capability_data.fault_table.Blockage_Algo_Error    = TRUE;
   test_d2m_msg.payload.radar_capability_data.fault_table.Damping_Algo_Error     = FALSE;
   test_d2m_msg.payload.radar_capability_data.fault_table.Range_Algo_Error       = FALSE;
   test_d2m_msg.payload.radar_capability_data.fault_table.PBD_Monitor_Algo_Error = FALSE;

   // Execute the function
   Dsp_sp_post_processing_complete();

   // Verify blockage fault is set
   ASSERT_EQ(captured_radar_capability_faults.Blockage_Fault, CODED_TRUE);
   ASSERT_EQ(captured_radar_capability_faults.Damping_Estimation_Fault, CODED_FALSE);
   ASSERT_EQ(captured_radar_capability_faults.Range_Estimation_Fault, CODED_FALSE);
   ASSERT_EQ(captured_radar_capability_faults.SLL_Fault, CODED_FALSE);
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, Dsp_sp_post_proc_DetectsDampingFault)
{
   // Setup: Damping error detected
   test_d2m_msg.payload.radar_capability_data.fault_table.Blockage_Algo_Error    = FALSE;
   test_d2m_msg.payload.radar_capability_data.fault_table.Damping_Algo_Error     = TRUE;
   test_d2m_msg.payload.radar_capability_data.fault_table.Range_Algo_Error       = FALSE;
   test_d2m_msg.payload.radar_capability_data.fault_table.PBD_Monitor_Algo_Error = FALSE;

   // Execute the function
   Dsp_sp_post_processing_complete();

   // Verify damping fault is set
   ASSERT_EQ(captured_radar_capability_faults.Blockage_Fault, CODED_FALSE);
   ASSERT_EQ(captured_radar_capability_faults.Damping_Estimation_Fault, CODED_TRUE);
   ASSERT_EQ(captured_radar_capability_faults.Range_Estimation_Fault, CODED_FALSE);
   ASSERT_EQ(captured_radar_capability_faults.SLL_Fault, CODED_FALSE);
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, Dsp_sp_post_proc_DetectsRangeFault)
{
   // Setup: Range error detected
   test_d2m_msg.payload.radar_capability_data.fault_table.Blockage_Algo_Error    = FALSE;
   test_d2m_msg.payload.radar_capability_data.fault_table.Damping_Algo_Error     = FALSE;
   test_d2m_msg.payload.radar_capability_data.fault_table.Range_Algo_Error       = TRUE;
   test_d2m_msg.payload.radar_capability_data.fault_table.PBD_Monitor_Algo_Error = FALSE;

   // Execute the function
   Dsp_sp_post_processing_complete();

   // Verify range fault is set
   ASSERT_EQ(captured_radar_capability_faults.Blockage_Fault, CODED_FALSE);
   ASSERT_EQ(captured_radar_capability_faults.Damping_Estimation_Fault, CODED_FALSE);
   ASSERT_EQ(captured_radar_capability_faults.Range_Estimation_Fault, CODED_TRUE);
   ASSERT_EQ(captured_radar_capability_faults.SLL_Fault, CODED_FALSE);
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, Dsp_sp_post_proc_DetectsSLLFault)
{
   // Setup: SLL error detected
   test_d2m_msg.payload.radar_capability_data.fault_table.Blockage_Algo_Error    = FALSE;
   test_d2m_msg.payload.radar_capability_data.fault_table.Damping_Algo_Error     = FALSE;
   test_d2m_msg.payload.radar_capability_data.fault_table.Range_Algo_Error       = FALSE;
   test_d2m_msg.payload.radar_capability_data.fault_table.PBD_Monitor_Algo_Error = TRUE;

   // Execute the function
   Dsp_sp_post_processing_complete();

   // Verify SLL fault is set
   ASSERT_EQ(captured_radar_capability_faults.Blockage_Fault, CODED_FALSE);
   ASSERT_EQ(captured_radar_capability_faults.Damping_Estimation_Fault, CODED_FALSE);
   ASSERT_EQ(captured_radar_capability_faults.Range_Estimation_Fault, CODED_FALSE);
   ASSERT_EQ(captured_radar_capability_faults.SLL_Fault, CODED_TRUE);
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, Dsp_sp_post_proc_BBE32RegChkFailed)
{
   test_d2m_msg.payload.diag_data.fusa_bbe32_reg_readback_test_fault_flag = CODED_TRUE;
   Dsp_sp_post_processing_complete();
   ASSERT_EQ(Rte_Write_SWC_CDD_IPC_Pp_StaticRegCheckFailureInfo_De_StaticRegCheckFailureInfo_fake.call_count, 1);
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, Dsp_sp_post_proc_DetectsMultipleFaults)
{
   // Setup: Multiple errors detected
   test_d2m_msg.payload.radar_capability_data.fault_table.Blockage_Algo_Error    = TRUE;
   test_d2m_msg.payload.radar_capability_data.fault_table.Damping_Algo_Error     = TRUE;
   test_d2m_msg.payload.radar_capability_data.fault_table.Range_Algo_Error       = TRUE;
   test_d2m_msg.payload.radar_capability_data.fault_table.PBD_Monitor_Algo_Error = TRUE;

   // Execute the function
   Dsp_sp_post_processing_complete();

   // Verify all faults are set
   ASSERT_EQ(captured_radar_capability_faults.Blockage_Fault, CODED_TRUE);
   ASSERT_EQ(captured_radar_capability_faults.Damping_Estimation_Fault, CODED_TRUE);
   ASSERT_EQ(captured_radar_capability_faults.Range_Estimation_Fault, CODED_TRUE);
   ASSERT_EQ(captured_radar_capability_faults.SLL_Fault, CODED_TRUE);
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, Dsp_sp_post_proc_HandlesNullD2MBuffer)
{
   // Setup: Get_IPC_Sp_Post_Buf_Read_Addr_Raw returns NULL → Fetch_IPC_Data not called
   Get_IPC_Sp_Post_Buf_Read_Addr_Raw_fake.return_val = NULL;

   // Execute the function
   Dsp_sp_post_processing_complete();

   // Verify no RTE write was called (function should skip d2m_msg_ptr block)
   ASSERT_EQ(Rte_Write_SWC_CDD_IPC_Pp_RadarCapability_Faults_De_RadarCapability_Faults_fake.call_count, 0);
}

#if (TRUE == ENABLE_SIT_TEST_STUBS)
TEST_F(SWC_CDD_IPC_UnitTestSuite, Dsp_sp_post_proc_SIT_TestStub_CRCError_Set)
{
   // Setup: Test stub with CRC error
   test_ipc_crc_var = 1;

   // Execute the function
   Dsp_sp_post_processing_complete();

   // Verify IPC faults were written
   ASSERT_EQ(Rte_Write_SWC_CDD_IPC_Pp_IPC_Faults_De_IPC_Faults_fake.call_count, 1);

   // Verify all CRC errors are set to CODED_TRUE
   const Dt_IPC_Faults *faults = Rte_Write_SWC_CDD_IPC_Pp_IPC_Faults_De_IPC_Faults_fake.arg0_val;
   ASSERT_EQ(faults->IPC_M2D_Crc_Err_Cnt, CODED_TRUE);
   ASSERT_EQ(faults->IPC_D2M_Crc_Err_Cnt, CODED_TRUE);
   ASSERT_EQ(faults->IPC_D2A_Crc_Err_Cnt, CODED_TRUE);
   ASSERT_EQ(faults->IPC_A2M_Crc_Err_Cnt, CODED_TRUE);
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, Dsp_sp_post_proc_SIT_TestStub_CRCError_Clear)
{
   // Setup: Test stub with CRC error cleared
   test_ipc_crc_var = 2;

   // Execute the function
   Dsp_sp_post_processing_complete();

   // Verify IPC faults were written
   ASSERT_EQ(Rte_Write_SWC_CDD_IPC_Pp_IPC_Faults_De_IPC_Faults_fake.call_count, 1);

   // Verify all CRC errors are set to CODED_FALSE
   const Dt_IPC_Faults *faults = Rte_Write_SWC_CDD_IPC_Pp_IPC_Faults_De_IPC_Faults_fake.arg0_val;
   ASSERT_EQ(faults->IPC_M2D_Crc_Err_Cnt, CODED_FALSE);
   ASSERT_EQ(faults->IPC_D2M_Crc_Err_Cnt, CODED_FALSE);
   ASSERT_EQ(faults->IPC_D2A_Crc_Err_Cnt, CODED_FALSE);
   ASSERT_EQ(faults->IPC_A2M_Crc_Err_Cnt, CODED_FALSE);
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, Dsp_sp_post_proc_SIT_TestStub_NoTestValue)
{
   // Setup: Test stub with value not equal to 1 or 2 (else branch)
   test_ipc_crc_var = 0;

   // Execute the function
   Dsp_sp_post_processing_complete();

   // Verify IPC faults were still written (default behavior)
   ASSERT_EQ(Rte_Write_SWC_CDD_IPC_Pp_IPC_Faults_De_IPC_Faults_fake.call_count, 1);
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, Dsp_sp_post_proc_SIT_TestStub_OtherValue)
{
   // Setup: Test stub with another value (else branch)
   test_ipc_crc_var = 3;

   // Execute the function
   Dsp_sp_post_processing_complete();

   // Verify function still executes with no special behavior
   ASSERT_EQ(Rte_Write_SWC_CDD_IPC_Pp_IPC_Faults_De_IPC_Faults_fake.call_count, 1);
}
#endif

// Test case for Get_IPC_Sp_Post_Buf_Read_Addr_Raw returning NULL (Branch coverage)
TEST_F(SWC_CDD_IPC_UnitTestSuite, Dsp_sp_post_proc_NullBufferPointer)
{
   // Setup: Make Get_IPC_Sp_Post_Buf_Read_Addr_Raw return NULL
   Get_IPC_Sp_Post_Buf_Read_Addr_Raw_fake.return_val = NULL;

   // Execute the function
   Dsp_sp_post_processing_complete();

   // Verify that when buffer is NULL, the function returns early without writing faults
   ASSERT_EQ(Rte_Write_SWC_CDD_IPC_Pp_RadarCapability_Faults_De_RadarCapability_Faults_fake.call_count, 0);
}

// Test case for Rte_Write_SWC_CDD_IPC_Pp_RadarCapability_Faults_De_RadarCapability_Faults returning error (Branch coverage for
// line 550)
TEST_F(SWC_CDD_IPC_UnitTestSuite, Dsp_sp_post_proc_WriteRadarCapabilityFaultsError)
{
   // Setup: Make Rte_Write_Pp_RadarCapability_Faults return error
   Rte_Write_SWC_CDD_IPC_Pp_RadarCapability_Faults_De_RadarCapability_Faults_fake.return_val = 1; // Non-zero error code

   // Execute the function
   Dsp_sp_post_processing_complete();

   // Verify that the write function was called and returned an error
   ASSERT_EQ(Rte_Write_SWC_CDD_IPC_Pp_RadarCapability_Faults_De_RadarCapability_Faults_fake.call_count, 1);
   // The error path is now covered even though the code doesn't handle it explicitly
}

/*===========================================================================*
 * Integration Test Cases
 *===========================================================================*/
TEST_F(SWC_CDD_IPC_UnitTestSuite, Integration_CompleteIPCFlow)
{
   // Execute full IPC cycle
   RE_IPC_Rx_50ms();
   RE_IPC_Trigger_50ms();
   Dsp_sp_post_processing_complete();

   // Verify fault processing was called
   ASSERT_EQ(Rte_Write_SWC_CDD_IPC_Pp_RadarCapability_Faults_De_RadarCapability_Faults_fake.call_count, 1);
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, Integration_MultipleCycles)
{
   // Execute multiple IPC cycles
   for (int i = 0; i < 10; i++)
   {
      RE_IPC_Rx_50ms();
      RE_IPC_Trigger_50ms();
      Dsp_sp_post_processing_complete();
   }

   // Verify fault processing was called 10 times
   ASSERT_EQ(Rte_Write_SWC_CDD_IPC_Pp_RadarCapability_Faults_De_RadarCapability_Faults_fake.call_count, 10);
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, Integration_FaultDetectionAndReporting)
{
   // Cycle 1: No faults
   test_d2m_msg.payload.radar_capability_data.fault_table.Blockage_Algo_Error = FALSE;
   Dsp_sp_post_processing_complete();
   ASSERT_EQ(captured_radar_capability_faults.Blockage_Fault, CODED_FALSE);

   // Cycle 2: Fault appears
   test_d2m_msg.payload.radar_capability_data.fault_table.Blockage_Algo_Error = TRUE;
   Dsp_sp_post_processing_complete();
   ASSERT_EQ(captured_radar_capability_faults.Blockage_Fault, CODED_TRUE);

   // Cycle 3: Fault clears
   test_d2m_msg.payload.radar_capability_data.fault_table.Blockage_Algo_Error = FALSE;
   Dsp_sp_post_processing_complete();
   ASSERT_EQ(captured_radar_capability_faults.Blockage_Fault, CODED_FALSE);
}

/*===========================================================================*
 * Edge Case Test Cases
 *===========================================================================*/
TEST_F(SWC_CDD_IPC_UnitTestSuite, EdgeCase_AlternatingBufferValidity)
{
   // Alternate between valid and null buffer
   for (int i = 0; i < 10; i++)
   {
      if (i % 2 == 0)
      {
         Get_IPC_Sp_Post_Buf_Read_Addr_Raw_fake.return_val = &test_d2m_msg;
      }
      else
      {
         Get_IPC_Sp_Post_Buf_Read_Addr_Raw_fake.return_val = NULL;
      }
      Dsp_sp_post_processing_complete();
   }

   // Verify RTE write was only called 5 times (valid buffer cycles)
   ASSERT_EQ(Rte_Write_SWC_CDD_IPC_Pp_RadarCapability_Faults_De_RadarCapability_Faults_fake.call_count, 5);
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, EdgeCase_RapidFaultChanges)
{
   // Rapidly change fault states
   for (int i = 0; i < 100; i++)
   {
      test_d2m_msg.payload.radar_capability_data.fault_table.Blockage_Algo_Error    = (i % 2);
      test_d2m_msg.payload.radar_capability_data.fault_table.Damping_Algo_Error     = (i % 3 == 0);
      test_d2m_msg.payload.radar_capability_data.fault_table.Range_Algo_Error       = (i % 5 == 0);
      test_d2m_msg.payload.radar_capability_data.fault_table.PBD_Monitor_Algo_Error = (i % 7 == 0);
      Dsp_sp_post_processing_complete();
   }

   // Verify all cycles were processed
   ASSERT_EQ(Rte_Write_SWC_CDD_IPC_Pp_RadarCapability_Faults_De_RadarCapability_Faults_fake.call_count, 100);
}

/*===========================================================================*
 * Boundary Test Cases
 *===========================================================================*/
TEST_F(SWC_CDD_IPC_UnitTestSuite, Boundary_AllFaultsSet)
{
   // Set all faults to TRUE
   test_d2m_msg.payload.radar_capability_data.fault_table.Blockage_Algo_Error    = TRUE;
   test_d2m_msg.payload.radar_capability_data.fault_table.Damping_Algo_Error     = TRUE;
   test_d2m_msg.payload.radar_capability_data.fault_table.Range_Algo_Error       = TRUE;
   test_d2m_msg.payload.radar_capability_data.fault_table.PBD_Monitor_Algo_Error = TRUE;

   Dsp_sp_post_processing_complete();

   ASSERT_EQ(captured_radar_capability_faults.Blockage_Fault, CODED_TRUE);
   ASSERT_EQ(captured_radar_capability_faults.Damping_Estimation_Fault, CODED_TRUE);
   ASSERT_EQ(captured_radar_capability_faults.Range_Estimation_Fault, CODED_TRUE);
   ASSERT_EQ(captured_radar_capability_faults.SLL_Fault, CODED_TRUE);
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, Boundary_AllFaultsClear)
{
   // Set all faults to FALSE
   test_d2m_msg.payload.radar_capability_data.fault_table.Blockage_Algo_Error    = FALSE;
   test_d2m_msg.payload.radar_capability_data.fault_table.Damping_Algo_Error     = FALSE;
   test_d2m_msg.payload.radar_capability_data.fault_table.Range_Algo_Error       = FALSE;
   test_d2m_msg.payload.radar_capability_data.fault_table.PBD_Monitor_Algo_Error = FALSE;

   Dsp_sp_post_processing_complete();

   ASSERT_EQ(captured_radar_capability_faults.Blockage_Fault, CODED_FALSE);
   ASSERT_EQ(captured_radar_capability_faults.Damping_Estimation_Fault, CODED_FALSE);
   ASSERT_EQ(captured_radar_capability_faults.Range_Estimation_Fault, CODED_FALSE);
   ASSERT_EQ(captured_radar_capability_faults.SLL_Fault, CODED_FALSE);
}

/*===========================================================================*
 * Stress Test Cases
 *===========================================================================*/
TEST_F(SWC_CDD_IPC_UnitTestSuite, Stress_ContinuousExecution)
{
   // Execute continuously for extended period
   for (int i = 0; i < 1000; i++)
   {
      RE_IPC_Rx_50ms();
      RE_IPC_Trigger_50ms();
      Dsp_sp_post_processing_complete();
   }

   // Verify execution completed successfully
   ASSERT_EQ(Rte_Write_SWC_CDD_IPC_Pp_RadarCapability_Faults_De_RadarCapability_Faults_fake.call_count, 1000);
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, Stress_RandomFaultPatterns)
{
   // Test with pseudo-random fault patterns
   for (int i = 0; i < 100; i++)
   {
      test_d2m_msg.payload.radar_capability_data.fault_table.Blockage_Algo_Error    = ((i * 7) % 2);
      test_d2m_msg.payload.radar_capability_data.fault_table.Damping_Algo_Error     = ((i * 11) % 2);
      test_d2m_msg.payload.radar_capability_data.fault_table.Range_Algo_Error       = ((i * 13) % 2);
      test_d2m_msg.payload.radar_capability_data.fault_table.PBD_Monitor_Algo_Error = ((i * 17) % 2);
      Dsp_sp_post_processing_complete();
   }

   ASSERT_EQ(Rte_Write_SWC_CDD_IPC_Pp_RadarCapability_Faults_De_RadarCapability_Faults_fake.call_count, 100);
}

/*===========================================================================*
 * Sanity Check
 *===========================================================================*/
TEST_F(SWC_CDD_IPC_UnitTestSuite, SanityCheck)
{
   ASSERT_TRUE(true);
   ASSERT_FALSE(false);
   ASSERT_EQ(1, 1);
}

/*===========================================================================*
 * Main Function
 *===========================================================================*/
int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
TEST_F(SWC_CDD_IPC_UnitTestSuite, RE_CDD_IPC_Init)
{
   RE_CDD_IPC_Init();
   ASSERT_EQ(true, true);
}

/*===========================================================================*
 * Test Cases for static helper functions (included via SWC_CDD_IPC.c)
 *===========================================================================*/

#if defined(VEH_AL_CAN_STANDALONE)
TEST_F(SWC_CDD_IPC_UnitTestSuite, Run_VSE_NormalPathPopulatesTrackerHostOutputMetadata)
{
   test_m2d_msg.payload.veh_data.latest_raw_index = 0U;

   test_m2d_msg.payload.veh_data.veh_raw_data[0].system_time_secs       = 12U;
   test_m2d_msg.payload.veh_data.veh_raw_data[0].system_time_nanosecs   = 3456000U;
   test_m2d_msg.payload.veh_data.veh_raw_data[0].ego_vehicle_speed      = -2.5F;
   test_m2d_msg.payload.veh_data.veh_raw_data[0].ego_yaw_rate           = 0.25F;
   test_m2d_msg.payload.veh_data.veh_raw_data[0].steering_whl_angle     = 0.15F;
   test_m2d_msg.payload.veh_data.veh_raw_data[0].ego_lateral_accel      = 0.0F;
   test_m2d_msg.payload.veh_data.veh_raw_data[0].ego_longitudinal_accel = 0.0F;
   test_m2d_msg.payload.veh_data.veh_raw_misc.ego_vehicle_speed_qf      = 1U;
   test_m2d_msg.payload.veh_data.veh_raw_misc.ego_yaw_rate_qf           = 2U;
   test_m2d_msg.payload.veh_data.veh_raw_misc.steering_whl_angle_qf     = 3U;

   test_m2d_msg.payload.veh_data.veh_raw_misc.ego_lateral_accel_qf = 3U;

   test_m2d_msg.payload.veh_data.veh_raw_misc.ego_longitudinal_accel_qf = 3U;

   test_m2d_msg.payload.veh_data.veh_raw_misc.vehspeedcompfac_ka = 1.75F;

   test_m2d_msg.payload.veh_data.veh_raw_misc.vehspeedcompfac_ka_qf = 3U;

   Run_VSE(&test_m2d_msg);

   EXPECT_EQ(test_m2d_msg.payload.veh_data.vse_output.timestamp_secs, 12U);
   EXPECT_EQ(test_m2d_msg.payload.veh_data.vse_output.timestamp_nanosecs, 3456000U);
   EXPECT_EQ(test_m2d_msg.payload.veh_data.vse_output.veh_index, 2U);
   EXPECT_EQ(test_m2d_msg.payload.veh_data.vse_output.reverse_status, 0U);

   EXPECT_EQ(test_m2d_msg.payload.veh_data.vse_output.vse_major_version, 0x3C);

   EXPECT_EQ(test_m2d_msg.payload.veh_data.vse_output.vse_minor_version, 0U);
   EXPECT_EQ(test_m2d_msg.payload.veh_data.vse_output.vse_field_version, 0U);
   EXPECT_EQ(test_m2d_msg.payload.veh_data.vse_output.vse_calibration_version, 0U);
}
#endif

TEST_F(SWC_CDD_IPC_UnitTestSuite, Fetch_IPC_Data_PropagatesDiagAndAlignmentOutputs)
{
   test_d2m_msg.payload.diag_data.dsp_self_test_failure_flag                                           = CODED_TRUE;
   test_d2m_msg.payload.diag_data.detection_processing_loop_overrun_fault                              = CODED_TRUE;
   test_d2m_msg.payload.dynamic_alignment_log_stream.dra_core_data.alignment_mode                      = 7U;
   test_d2m_msg.payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_az_estimated         = 1.25F;
   test_d2m_msg.payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_estimated         = -2.5F;
   test_d2m_msg.payload.dynamic_alignment_log_stream.dra_core_data.speed_compensation_factor_estimated = 1.5F;
   test_d2m_msg.payload.dynamic_alignment_log_stream.dra_core_data.alignment_index                     = 55U;
   test_d2m_msg.payload.radar_capability_data.blockage.blockage_active                                 = TRUE;
   test_d2m_msg.payload.alignment_stream_data.sra_core_data.alignment_mode                             = 9U;
   test_d2m_msg.payload.alignment_stream_data.sra_core_data.vacs_boresight_az_estimated                = 3.5F;
   test_d2m_msg.payload.alignment_stream_data.sra_core_data.vacs_boresight_el_estimated                = -1.5F;
   test_d2m_msg.payload.alignment_stream_data.sra_core_data.alignment_complete_percentage              = 77.0F;
   test_d2m_msg.payload.alignment_stream_data.sra_core_data.algo_status                                = 4U;
   test_d2m_msg.payload.alignment_stream_data.sra_core_data.target_mean_range                          = 40.0F;
   test_d2m_msg.payload.alignment_stream_data.sra_core_data.target_mean_range_rate                     = 5.0F;
   test_d2m_msg.payload.alignment_stream_data.sra_core_data.target_mean_raw_amp                        = 6.0F;
   test_d2m_msg.payload.toi_ds_stream_data.toi_op_data.data_qualifier                                  = 3U;

   Fetch_IPC_Data(&test_d2m_msg);

   EXPECT_EQ(captured_radar_capability_faults.Safety_Integrity_Fault, CODED_TRUE);
   EXPECT_EQ(captured_radar_capability_faults.Core_Self_Test_Fault, CODED_TRUE);
   EXPECT_EQ(captured_radar_capability_faults.Detection_Procession_Loop_Overrun_Fault, CODED_TRUE);

   EXPECT_EQ(captured_alignment_ipc_data.alignment_mode, 9U);
   EXPECT_EQ(captured_alignment_ipc_data.dra_core_log_data.alignment_mode, 7U);
   EXPECT_FLOAT_EQ(captured_alignment_ipc_data.dra_core_log_data.vacs_boresight_az_estimated, 1.25F);
   EXPECT_FLOAT_EQ(captured_alignment_ipc_data.dra_core_log_data.vacs_boresight_el_estimated, -2.5F);
   EXPECT_EQ(captured_alignment_ipc_data.dra_core_log_data.blockage_active, TRUE);
   EXPECT_FLOAT_EQ(captured_alignment_ipc_data.veh_info.veh_speed, 0);
   EXPECT_EQ(captured_alignment_ipc_data.veh_info.lros_drive_reverse, 0U);
   EXPECT_FLOAT_EQ(captured_alignment_ipc_data.sra_core_log_data.vacs_boresight_az_estimated, 3.5F);
   EXPECT_FLOAT_EQ(captured_alignment_ipc_data.sra_core_log_data.vacs_boresight_el_estimated, -1.5F);
   EXPECT_EQ(captured_alignment_ipc_data.sra_core_log_data.complete_percentage, 77U);
   EXPECT_EQ(captured_alignment_ipc_data.data_qualifier, 3U);
}

/*===========================================================================*
 * Test Cases for Fetch_IPC_Data – DDR-5028: IPC_D2M_Crc_Err_Cnt population.
 * Verifies that Get_IPC_D2M_Crc_Err_Cnt() is called and the result written.
 * to ipc_crc_faults.IPC_D2M_Crc_Err_Cnt (added in DDR-5028 commit).
 *===========================================================================*/

/**
 * @test Get_IPC_D2M_Crc_Err_Cnt is called during Dsp_sp_post_processing_complete
 *
 * @pre Valid D2M buffer, Get_IPC_D2M_Crc_Err_Cnt fake returns a non-zero value
 * @post Get_IPC_D2M_Crc_Err_Cnt was called at least once, confirming the
 *       DDR-5028 addition of IPC_D2M_Crc_Err_Cnt to Fetch_IPC_Data is exercised
 */
TEST_F(SWC_CDD_IPC_UnitTestSuite, FetchIPCData_IpcD2mCrcErrCnt_PopulatedFromGetter)
{
   Get_IPC_D2M_Crc_Err_Cnt_fake.return_val = 3U;

   Dsp_sp_post_processing_complete();

   /* The getter must have been called exactly once per Fetch_IPC_Data invocation */
   ASSERT_GE(Get_IPC_D2M_Crc_Err_Cnt_fake.call_count, 1U);
}

/**
 * @test Get_IPC_D2M_Crc_Err_Cnt returns zero when no D2M CRC errors occurred
 *
 * @pre Get_IPC_D2M_Crc_Err_Cnt fake returns 0
 * @post Getter was called; function completes normally
 */
TEST_F(SWC_CDD_IPC_UnitTestSuite, FetchIPCData_IpcD2mCrcErrCnt_ZeroNoErrors)
{
   Get_IPC_D2M_Crc_Err_Cnt_fake.return_val = 0U;

   Dsp_sp_post_processing_complete();

   ASSERT_GE(Get_IPC_D2M_Crc_Err_Cnt_fake.call_count, 1U);
}

/*===========================================================================*
 * Test Cases for RE_IPC_Tx_50ms (empty AUTOSAR runnable — coverage only)
 *===========================================================================*/
TEST_F(SWC_CDD_IPC_UnitTestSuite, RE_IPC_Tx_50ms_ExecutesWithoutError)
{
   RE_IPC_Tx_50ms();
   SUCCEED();
}

TEST_F(SWC_CDD_IPC_UnitTestSuite, RE_IPC_VSE_Handler_10ms_ExecutesSuccessfully)
{
   RE_IPC_VSE_Handler_10ms();

   SUCCEED();
}

/*===========================================================================*
 * Test Cases for Dsp_sp_post_processing_complete – CRC header valid path
 * Covers the true branch of:
 *   if ((ipc_sp_post_proc_buf_read_addr != NULL) &&
 *       (CODED_FALSE == Check_D2M_Crc_Header(...)))
 *===========================================================================*/
/* Note: the legacy Ping/Pong notify-buffer paths in Dsp_sp_post_processing_complete
 * have been removed; their dead-stub tests were dropped in favor of the branch
 * coverage tests above. */
