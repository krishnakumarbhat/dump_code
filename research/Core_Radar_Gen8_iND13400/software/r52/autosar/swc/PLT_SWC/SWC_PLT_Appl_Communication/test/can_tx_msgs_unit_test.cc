/*===========================================================================*/
/**
 * @file can_tx_msgs_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitive Business Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for checking the can_tx_msgs.c file
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
/ *===========================================================================*/
#include "fff.h"
#include <gtest/gtest.h>

extern "C"
{
#include "can_tx_msgs_stubs.h"
/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "can_tx_msgs.c"
}

DEFINE_FFF_GLOBALS;

/*===========================================================================*
 * File Under Test
 *===========================================================================*/

/*===========================================================================*
 * Private Mocks
 *===========================================================================*/
MMIC_Stream_T MMIC_Stream          = {0};
MMIC_Temp_Stats_T MMIC_Temperature = {0};
Radar_Ctl_Data_T Radar_Ctl_Data;
Dt_SystemOperationMode Rte_SWC_PLT_Appl_ModeManager_Pp_OperationMode_System_De_OperationMode_System;
VAR(Dt_VBattState_T, RTE_VAR_INIT) Rte_SWC_PLT_Appl_IoHwAb_Pp_Vbatt_State_De_Vbatt_State = 0U;
uint8 Rte_SWC_PLT_Appl_IoHwAb_Pp_Board_Revision_De_Board_Revision                        = 0;

static D2M_Msg_T g_d2m_buf                                     = {0};
static M2D_Msg_T g_m2d_buf                                     = {0};
static M2D_One_Time_Msg_T g_m2d_one_time_buf                   = {0};
static Dt_Alignment_Handler g_alignment_handler                = {0};
static Dt_AlignmentAuto g_alignment_auto                       = {0};
static Dt_AlignmentStatic g_alignment_static                   = {0};
static Dt_AlignmentService g_alignment_service                 = {0};
static Dt_AlignmentShortTrack g_alignment_short                = {0};
static Application_Version_T g_app_ver                         = {0};
static Bootloader_Version_T g_blr_ver                          = {0};
static volatile float32_t g_mcu_temp                           = 0.0f;
static I_SG_RadarHeader_ALPCAN g_last_radar_header_msg         = {0};
static I_SG_RadarStatus2_AL g_last_radar_status2_msg           = {0};
static I_SG_AlignmentStatus1_AL g_last_alignment_status1_msg   = {0};
static I_SG_AlignmentStatus2_AL g_last_alignment_status2_msg   = {0};
static I_SG_RadarCapability_AL g_last_radar_capability_msg     = {0};
static I_SG_Detections_001_004_AL g_last_detection_001_004_msg = {0};
static SG_TrackerObject001_impdt g_last_tracker_object001_msg  = {0};

static Std_ReturnType Capture_Radar_Header_Write(P2CONST(I_SG_RadarHeader_ALPCAN, AUTOMATIC,
                                                         RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data)
{
   if (data != NULL)
   {
      g_last_radar_header_msg = *data;
   }
   return (Std_ReturnType)0;
}

static Std_ReturnType Capture_Radar_Status2_Write(P2CONST(I_SG_RadarStatus2_AL, AUTOMATIC,
                                                          RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data)
{
   if (data != NULL)
   {
      g_last_radar_status2_msg = *data;
   }
   return (Std_ReturnType)0;
}

static Std_ReturnType Capture_Alignment_Status1_Write(P2CONST(I_SG_AlignmentStatus1_AL, AUTOMATIC,
                                                              RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data)
{
   if (data != NULL)
   {
      g_last_alignment_status1_msg = *data;
   }
   return (Std_ReturnType)0;
}

static Std_ReturnType Capture_Alignment_Status2_Write(P2CONST(I_SG_AlignmentStatus2_AL, AUTOMATIC,
                                                              RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data)
{
   if (data != NULL)
   {
      g_last_alignment_status2_msg = *data;
   }
   return (Std_ReturnType)0;
}

static Std_ReturnType Capture_Radar_Capability_Write(P2CONST(I_SG_RadarCapability_AL, AUTOMATIC,
                                                             RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data)
{
   if (data != NULL)
   {
      g_last_radar_capability_msg = *data;
   }
   return (Std_ReturnType)0;
}

static Std_ReturnType Capture_Detection_001_004_Write(P2CONST(I_SG_Detections_001_004_AL, AUTOMATIC,
                                                              RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data)
{
   if (data != NULL)
   {
      g_last_detection_001_004_msg = *data;
   }
   return (Std_ReturnType)0;
}

static Std_ReturnType Capture_Tracker_Object001_Write(P2CONST(SG_TrackerObject001_impdt, AUTOMATIC,
                                                              RTE_SWC_PLT_APPL_COMMUNICATION_APPL_DATA) data)
{
   if (data != NULL)
   {
      g_last_tracker_object001_msg = *data;
   }
   return (Std_ReturnType)0;
}
/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/

class Can_Tx_Msgs_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_RESET_HISTORY();
      RESET_FAKE(Get_IPC_D2M_Sp_Post_Proc_Buffer);
      RESET_FAKE(Get_MSS_IPC_M2D_Msg_Buffer);
      RESET_FAKE(Get_IPC_M2D_Onetime_Msg_Buffer);
      RESET_FAKE(Get_AlignmentHandler);
      RESET_FAKE(Get_AlignmentAuto);
      RESET_FAKE(Get_AlignmentStatic);
      RESET_FAKE(Get_AlignmentService);
      RESET_FAKE(Get_AlignmentShortTrack);
      RESET_FAKE(Get_Application_Version);
      RESET_FAKE(Get_Bootloader_Version);
      RESET_FAKE(Get_Radar_Position);
      RESET_FAKE(Get_XCP_MCU_Temperature_Data);
      RESET_FAKE(Get_MMIC_Error_Reinit_Count);
      RESET_FAKE(Get_XCP_Over_ETH_Status);
      RESET_FAKE(FXP2FLP_Fnc);
      RESET_FAKE(Rte_Read_SWC_PLT_CDD_Logging_Rp_CPU_Load_De_CPU_Load);
      RESET_FAKE(Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_AL_Vdp_SG_RadarHeader_AL);
      RESET_FAKE(Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN);
      RESET_FAKE(Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_AL_Vdp_SG_RadarStatus1_AL);
      RESET_FAKE(Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN);
      RESET_FAKE(Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL);
      RESET_FAKE(Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL);
      RESET_FAKE(Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL);
      RESET_FAKE(Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL);
      RESET_FAKE(Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerHeader_Vdp_SG_TrackerHeader);
      RESET_FAKE(Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerStatus_Vdp_SG_TrackerStatus);
      for (uint8_t i = 1; i <= 64; i++)
      {
         RESET_FAKE(Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject001_Vdp_SG_TrackerObject001);
      }
      ts_test_stub = 0;

      g_d2m_buf                    = (D2M_Msg_T){0};
      g_m2d_buf                    = (M2D_Msg_T){0};
      g_m2d_one_time_buf           = (M2D_One_Time_Msg_T){0};
      g_alignment_handler          = (Dt_Alignment_Handler){0};
      g_alignment_auto             = (Dt_AlignmentAuto){0};
      g_alignment_static           = (Dt_AlignmentStatic){0};
      g_alignment_service          = (Dt_AlignmentService){0};
      g_alignment_short            = (Dt_AlignmentShortTrack){0};
      g_app_ver                    = (Application_Version_T){0};
      g_blr_ver                    = (Bootloader_Version_T){0};
      g_mcu_temp                   = 0.0f;
      g_last_radar_header_msg      = (I_SG_RadarHeader_ALPCAN){0};
      g_last_radar_status2_msg     = (I_SG_RadarStatus2_AL){0};
      g_last_alignment_status1_msg = (I_SG_AlignmentStatus1_AL){0};
      g_last_alignment_status2_msg = (I_SG_AlignmentStatus2_AL){0};
      g_last_radar_capability_msg  = (I_SG_RadarCapability_AL){0};
      g_last_detection_001_004_msg = (I_SG_Detections_001_004_AL){0};
      g_last_tracker_object001_msg = (SG_TrackerObject001_impdt){0};

      Get_IPC_D2M_Sp_Post_Proc_Buffer_fake.return_val = &g_d2m_buf;
      Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val      = &g_m2d_buf;
      Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val  = &g_m2d_one_time_buf;
      Get_AlignmentHandler_fake.return_val            = &g_alignment_handler;
      Get_AlignmentAuto_fake.return_val               = &g_alignment_auto;
      Get_AlignmentStatic_fake.return_val             = &g_alignment_static;
      Get_AlignmentService_fake.return_val            = &g_alignment_service;
      Get_AlignmentShortTrack_fake.return_val         = &g_alignment_short;
      Get_Application_Version_fake.return_val         = &g_app_ver;
      Get_Bootloader_Version_fake.return_val          = &g_blr_ver;
      Get_XCP_MCU_Temperature_Data_fake.return_val    = &g_mcu_temp;
      Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_fake.custom_fake =
         Capture_Radar_Header_Write;
      Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_fake.custom_fake =
         Capture_Radar_Status2_Write;
      Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_fake.custom_fake =
         Capture_Alignment_Status1_Write;
      Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_fake.custom_fake =
         Capture_Alignment_Status2_Write;
      Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_fake.custom_fake =
         Capture_Radar_Capability_Write;
      Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_001_004_AL_Vdp_SG_Detections_001_004_AL_fake.custom_fake =
         Capture_Detection_001_004_Write;
      Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject001_Vdp_SG_TrackerObject001_fake.custom_fake =
         Capture_Tracker_Object001_Write;
   }

   /**
    * @b Description
    * @n
    *    Method run after each individual test case.
    */
   void TearDown()
   {
      ts_test_stub = 0;
   }
};

/**
 *  @b ModifyStatus_Stub1_SetsStatusTo8
 *  @n
 *      Verifies that Modify Status Stub1 Sets Status To8.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, ModifyStatus_Stub1_SetsStatusTo8)
{
   ts_test_stub    = 1;
   uint32_t status = 0U;
   modify_status(&status);
   ASSERT_EQ(8U, status);
}

/**
 *  @b ModifyStatus_Stub2_SetsStatusTo9
 *  @n
 *      Verifies that Modify Status Stub2 Sets Status To9.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, ModifyStatus_Stub2_SetsStatusTo9)
{
   ts_test_stub    = 2;
   uint32_t status = 0U;
   modify_status(&status);
   ASSERT_EQ(9U, status);
}

/**
 *  @b ModifyStatus_Stub0_SetsStatusTo0
 *  @n
 *      Verifies that Modify Status Stub0 Sets Status To0.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, ModifyStatus_Stub0_SetsStatusTo0)
{
   ts_test_stub    = 0;
   uint32_t status = 0xFFFFFFFFU;
   modify_status(&status);
   ASSERT_EQ(0U, status);
}

/**
 *  @b GetOperationMode_ReturnsOpmodeMinusOffset
 *  @n
 *      Verifies that Get Operation Mode Returns Opmode Minus Offset.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, GetOperationMode_ReturnsOpmodeMinusOffset)
{
   /* OP_MODE_CAN_SIG_OFFSET == 1U */
   uint8_t result = Get_Operation_Mode((Dt_SystemOperationMode)3U);
   ASSERT_EQ(2U, result);
}

/**
 *  @b GetVehicleSupplyVtg_ValidIndex_ReturnsTableValue
 *  @n
 *      Verifies that Get Vehicle Supply Vtg Valid Index Returns Table Value.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, GetVehicleSupplyVtg_ValidIndex_ReturnsTableValue)
{
   /* vbatt=0 maps to supply_vtg_arr[0]==0 (first element) */
   uint8_t result = Get_Vehicle_Supply_Vtg((Dt_VBattState_T)0U);
   ASSERT_EQ(0U, result);
}

/**
 *  @b GetVehicleSupplyVtg_ValidIndex1_ReturnsNormV
 *  @n
 *      Verifies that Get Vehicle Supply Vtg Valid Index1 Returns Norm V.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, GetVehicleSupplyVtg_ValidIndex1_ReturnsNormV)
{
   /* vbatt=1 maps to NORM_V */
   uint8_t result = Get_Vehicle_Supply_Vtg((Dt_VBattState_T)1U);
   ASSERT_EQ((uint8_t)NORM_V, result);
}

/**
 *  @b GetVehicleSupplyVtg_OutOfRange_ReturnsZero
 *  @n
 *      Verifies that Get Vehicle Supply Vtg Out Of Range Returns Zero.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, GetVehicleSupplyVtg_OutOfRange_ReturnsZero)
{
   uint8_t result = Get_Vehicle_Supply_Vtg((Dt_VBattState_T)255U);
   ASSERT_EQ(0U, result);
}

/**
 *  @b GetRadarDetectionSignalsPtr_ReturnsNonNull
 *  @n
 *      Verifies that Get Radar Detection Signals Ptr Returns Non Null.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, GetRadarDetectionSignalsPtr_ReturnsNonNull)
{
   I_SG_Detections_001_004_AL *ptr = Get_Radar_Detection_Signals_Ptr();
   ASSERT_NE(nullptr, ptr);
}

/**
 *  @b InitRadarDetectionSignals_ZeroesArray
 *  @n
 *      Verifies that Init Radar Detection Signals Zeroes Array.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, InitRadarDetectionSignals_ZeroesArray)
{
   /* dirty a field first, then verify Init zeros it */
   I_SG_Detections_001_004_AL *ptr = Get_Radar_Detection_Signals_Ptr();
   ptr[0].DET_SNR_001              = 0xABU;
   Init_Radar_Detection_Signals();
   ASSERT_EQ(0U, ptr[0].DET_SNR_001);
}

/**
 *  @b SendRadarHeaderMessages_CallsRteWrite
 *  @n
 *      Verifies that Send Radar Header Messages Calls Rte Write.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, SendRadarHeaderMessages_CallsRteWrite)
{
   Send_Radar_Header_Messages();
   ASSERT_EQ(1U, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_fake.call_count);
}

/**
 *  @b SendRadarHeaderMessages_TimeSyncBranches_Covered
 *  @n
 *      Verifies that Send Radar Header Messages Time Sync Branches Covered.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, SendRadarHeaderMessages_TimeSyncBranches_Covered)
{
   g_d2m_buf.payload.rdd_stream_data.look_data.look_id = 0U;
   uint32_t before = Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_fake.call_count;

   ts_test_stub = 1;
   Send_Radar_Header_Messages();

   ts_test_stub = 2;
   Send_Radar_Header_Messages();

   ts_test_stub = 0;
   Send_Radar_Header_Messages();

   ASSERT_EQ(before + 3U, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarHeader_ALPCAN_Vdp_SG_RadarHeader_ALPCAN_fake.call_count);
}

/**
 *  @b SendRadarHeaderMessages_LookTypeElseBranch_Covered
 *  @n
 *      Verifies that Send Radar Header Messages Look Type Else Branch Covered.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, SendRadarHeaderMessages_LookTypeElseBranch_Covered)
{
   g_d2m_buf.payload.rdd_stream_data.look_data.look_id = RADAR_LOOK_D;
   ts_test_stub                                        = 1;

   Send_Radar_Header_Messages();
   ASSERT_EQ((uint32_t)RADAR_LOOK_D, (uint32_t)g_last_radar_header_msg.HED_LOOK_ID);
   ASSERT_EQ(0U, (uint32_t)g_last_radar_header_msg.HED_DET_RANGE_MAX);
   ASSERT_EQ(0U, (uint32_t)g_last_radar_header_msg.HED_DET_RANGE_MIN);
}

/**
 *  @b SendRadarHeaderMessages_FactoryAlignTrueFalse_Covered
 *  @n
 *      Verifies that Send Radar Header Messages Factory Align True False Covered.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, SendRadarHeaderMessages_FactoryAlignTrueFalse_Covered)
{
   g_d2m_buf.payload.rdd_stream_data.look_data.look_id                                        = 0U;
   g_d2m_buf.payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_el_kf_internal = 11;
   g_d2m_buf.payload.dynamic_alignment_log_stream.dra_core_data.vacs_boresight_az_kf_internal = 22;
   ts_test_stub                                                                               = 1;

   FactoryAlignRunning = true;
   Send_Radar_Header_Messages();
   uint32_t align_true_ver_ref = g_last_radar_header_msg.HED_ALIGN_VER_REF;

   FactoryAlignRunning = false;
   Send_Radar_Header_Messages();
   uint32_t align_false_ver_ref = g_last_radar_header_msg.HED_ALIGN_VER_REF;

   FactoryAlignRunning = true;
   ASSERT_NE(align_true_ver_ref, align_false_ver_ref);
}

/**
 *  @b SendRadarStatus001Messages_CallsRteWrite
 *  @n
 *      Verifies that Send Radar Status001 Messages Calls Rte Write.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, SendRadarStatus001Messages_CallsRteWrite)
{
   Send_Radar_Status_001_Messages();
   ASSERT_EQ(1U, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_fake.call_count);
}

/**
 *  @b SendRadarStatus002Messages_XcpEthFalse_CallsRteWrite
 *  @n
 *      Verifies that Send Radar Status002 Messages Xcp Eth False Calls Rte Write.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, SendRadarStatus002Messages_XcpEthFalse_CallsRteWrite)
{
   Get_XCP_Over_ETH_Status_fake.return_val = false;
   Send_Radar_Status_002_Messages();
   ASSERT_EQ(1U, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_fake.call_count);
}

/**
 *  @b SendRadarStatus002Messages_XcpEthTrue_CallsRteWrite
 *  @n
 *      Verifies that Send Radar Status002 Messages Xcp Eth True Calls Rte Write.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, SendRadarStatus002Messages_XcpEthTrue_CallsRteWrite)
{
   Get_XCP_Over_ETH_Status_fake.return_val = true;
   RESET_FAKE(Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL);
   Send_Radar_Status_002_Messages();
   ASSERT_EQ(1U, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_fake.call_count);
}

/**
 *  @b SendAlignmentStatus001Messages_CallsRteWrite
 *  @n
 *      Verifies that Send Alignment Status001 Messages Calls Rte Write.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, SendAlignmentStatus001Messages_CallsRteWrite)
{
   g_alignment_handler.AlignmentError                  = 3U;
   g_alignment_handler.Alignment_modeIn                = 5U;
   g_alignment_handler.AlignmentModeOut                = 7U;
   g_alignment_handler.CalDisplay                      = true;
   g_alignment_handler.ProgressPercent                 = 55U;
   g_alignment_handler.InitialAlignmentResultAzUpdates = 9U;
   g_alignment_handler.InitialAlignmentResultElUpdates = 11U;

   Send_Alignment_Status_001_Messages();
   ASSERT_EQ(1U, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_fake.call_count);
   ASSERT_EQ((uint32_t)g_alignment_handler.AlignmentError, (uint32_t)g_last_alignment_status1_msg.STS_AlignmentError);
   ASSERT_EQ((uint32_t)g_alignment_handler.Alignment_modeIn, (uint32_t)g_last_alignment_status1_msg.STS_AlignmentModeIn);
   ASSERT_EQ((uint32_t)g_alignment_handler.AlignmentModeOut, (uint32_t)g_last_alignment_status1_msg.STS_AlignmentModeOut);
   ASSERT_EQ((uint32_t)g_alignment_handler.ProgressPercent, (uint32_t)g_last_alignment_status1_msg.STS_ProgressPercent);
   ASSERT_EQ((uint32_t)g_alignment_handler.InitialAlignmentResultAzUpdates,
             (uint32_t)g_last_alignment_status1_msg.STS_InitAlignResultAzimuthUpdate);
   ASSERT_EQ((uint32_t)g_alignment_handler.InitialAlignmentResultElUpdates,
             (uint32_t)g_last_alignment_status1_msg.STS_InitAlignRsltElevationUpdate);
}

/**
 *  @b SendAlignmentStatus002Messages_CallsRteWrite
 *  @n
 *      Verifies that Send Alignment Status002 Messages Calls Rte Write.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, SendAlignmentStatus002Messages_CallsRteWrite)
{
   g_alignment_static.AlignmentStaticStatus = 2U;
   g_alignment_static.ImpactByInterference  = 1U;
   g_alignment_service.AlignmentServiceSt   = 4U;
   g_alignment_service.AvgNumOfDet          = 23.0F;
   g_alignment_service.VehicleCondition     = 6U;
   g_alignment_short.AlignShortTrackSt      = 8U;

   Send_Alignment_Status_002_Messages();
   ASSERT_EQ(1U, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_fake.call_count);
   ASSERT_EQ((uint32_t)g_alignment_static.AlignmentStaticStatus, (uint32_t)g_last_alignment_status2_msg.STS_AlignmentStaticStatus);
   ASSERT_EQ((uint32_t)g_alignment_static.ImpactByInterference, (uint32_t)g_last_alignment_status2_msg.STS_ImpactByInterference);
   ASSERT_EQ((uint32_t)g_alignment_service.AlignmentServiceSt, (uint32_t)g_last_alignment_status2_msg.STS_AlignmentServiceStatus);
   ASSERT_EQ((uint32_t)g_alignment_service.VehicleCondition, (uint32_t)g_last_alignment_status2_msg.STS_VehicleCondition);
   ASSERT_EQ((uint32_t)g_alignment_short.AlignShortTrackSt, (uint32_t)g_last_alignment_status2_msg.STS_AlignmentShortTrackStatus);
}

/**
 *  @b SendRadarCapabilityMessages_CallsRteWrite
 *  @n
 *      Verifies that Send Radar Capability Messages Calls Rte Write.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, SendRadarCapabilityMessages_CallsRteWrite)
{
   g_d2m_buf.payload.radar_capability_data.blockage.blockage_active         = 1U;
   g_d2m_buf.payload.radar_capability_data.blockage.blockage.probability    = 33U;
   g_d2m_buf.payload.radar_capability_data.sensitivity_level                = 2U;
   g_d2m_buf.payload.radar_capability_data.blockage.blockage_status         = 4U;
   g_d2m_buf.payload.radar_capability_data.blockage.blockage.value          = 55U;
   g_d2m_buf.payload.radar_capability_data.fsc.run_status                   = 1U;
   g_d2m_buf.payload.radar_capability_data.fsc.fault_status                 = 3U;
   g_d2m_buf.payload.radar_capability_data.dm.dm_active                     = 1U;
   g_d2m_buf.payload.radar_capability_data.dm.dm_status                     = 2U;
   g_d2m_buf.payload.radar_capability_data.re.re_active                     = 1U;
   g_d2m_buf.payload.radar_capability_data.re.re_status                     = 2U;
   g_d2m_buf.payload.radar_capability_data.pbd.az_sector[0].side_lobe_level = 9U;
   g_d2m_buf.payload.radar_capability_data.pbd.pbd_active                   = 1U;
   g_d2m_buf.payload.radar_capability_data.pbd.status                       = 6U;

   Send_Radar_Capability_Messages();
   ASSERT_EQ(1U, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_fake.call_count);
   ASSERT_EQ((uint32_t)g_d2m_buf.payload.radar_capability_data.blockage.blockage_active,
             (uint32_t)g_last_radar_capability_msg.CAP_BlockageActive);
   ASSERT_EQ((uint32_t)g_d2m_buf.payload.radar_capability_data.blockage.blockage.probability,
             (uint32_t)g_last_radar_capability_msg.CAP_BlockageProbability);
   ASSERT_EQ((uint32_t)g_d2m_buf.payload.radar_capability_data.sensitivity_level,
             (uint32_t)g_last_radar_capability_msg.CAP_BlockageSensitivity);
   ASSERT_EQ((uint32_t)g_d2m_buf.payload.radar_capability_data.blockage.blockage_status,
             (uint32_t)g_last_radar_capability_msg.CAP_BlockageStatus);
   ASSERT_EQ((uint32_t)g_d2m_buf.payload.radar_capability_data.blockage.blockage.value,
             (uint32_t)g_last_radar_capability_msg.CAP_BlockageValue);
   ASSERT_EQ((uint32_t)g_d2m_buf.payload.radar_capability_data.fsc.run_status,
             (uint32_t)g_last_radar_capability_msg.CAP_FreeSightCheckActive);
   ASSERT_EQ((uint32_t)g_d2m_buf.payload.radar_capability_data.fsc.fault_status,
             (uint32_t)g_last_radar_capability_msg.CAP_FreeSightCheckStatus);
   ASSERT_EQ((uint32_t)g_d2m_buf.payload.radar_capability_data.dm.dm_active,
             (uint32_t)g_last_radar_capability_msg.CAP_DampingActive);
   ASSERT_EQ((uint32_t)g_d2m_buf.payload.radar_capability_data.dm.dm_status,
             (uint32_t)g_last_radar_capability_msg.CAP_DampingStatus);
   ASSERT_EQ((uint32_t)g_d2m_buf.payload.radar_capability_data.re.re_active,
             (uint32_t)g_last_radar_capability_msg.CAP_RangeEstimationActive);
   ASSERT_EQ((uint32_t)g_d2m_buf.payload.radar_capability_data.re.re_status,
             (uint32_t)g_last_radar_capability_msg.CAP_RangeEstimationStatus);
   ASSERT_EQ((uint32_t)g_d2m_buf.payload.radar_capability_data.pbd.az_sector[0].side_lobe_level,
             (uint32_t)g_last_radar_capability_msg.CAP_SideLobeLevelBeamformer);
   ASSERT_EQ((uint32_t)g_d2m_buf.payload.radar_capability_data.pbd.pbd_active,
             (uint32_t)g_last_radar_capability_msg.CAP_SLLMonitoringActive);
   ASSERT_EQ((uint32_t)g_d2m_buf.payload.radar_capability_data.pbd.status,
             (uint32_t)g_last_radar_capability_msg.CAP_SLLMonitoringStatus);
}

/**
 *  @b SendRadarDetectionMessages_Executes
 *  @n
 *      Verifies that Send Radar Detection Messages Executes.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, SendRadarDetectionMessages_Executes)
{
   TARGET_REPORT_T *af_target_report_ptr     = GET_TARGET_REPORT_PTR(g_d2m_buf.payload);
   af_target_report_ptr[0].f_bistatic        = 1U;
   af_target_report_ptr[0].az_conf           = 2U;
   af_target_report_ptr[0].el_conf           = 3U;
   af_target_report_ptr[0].f_superres_target = 1U;

   Send_Radar_Detection_Messages();
   /* Detection messages rely on IPC buffer; verify IPC getter was called */
   ASSERT_GE(Get_IPC_D2M_Sp_Post_Proc_Buffer_fake.call_count, 1U);
   ASSERT_EQ(1U, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_001_004_AL_Vdp_SG_Detections_001_004_AL_fake.call_count);
   ASSERT_EQ((uint32_t)af_target_report_ptr[0].f_bistatic, (uint32_t)g_last_detection_001_004_msg.DET_BI_STATIC_FLAG_001);
   ASSERT_EQ((uint32_t)af_target_report_ptr[0].az_conf, (uint32_t)g_last_detection_001_004_msg.DET_CONFD_AZIMUTH_001);
   ASSERT_EQ((uint32_t)af_target_report_ptr[0].el_conf, (uint32_t)g_last_detection_001_004_msg.DET_CONFD_ELEVATION_001);
   ASSERT_EQ((uint32_t)af_target_report_ptr[0].f_superres_target, (uint32_t)g_last_detection_001_004_msg.DET_SUPER_RES_TARGET_001);
}

/**
 *  @b SendTrackerHeaderMessages_CallsRteWrite
 *  @n
 *      Verifies that Send Tracker Header Messages Calls Rte Write.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, SendTrackerHeaderMessages_CallsRteWrite)
{
   Send_Tracker_Header_Messages();
   ASSERT_EQ(1U, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerHeader_Vdp_SG_TrackerHeader_fake.call_count);
}

/**
 *  @b SendTrackerStatusMessages_CallsRteWrite
 *  @n
 *      Verifies that Send Tracker Status Messages Calls Rte Write.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, SendTrackerStatusMessages_CallsRteWrite)
{
   Send_Tracker_Status_Messages();
   ASSERT_EQ(1U, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerStatus_Vdp_SG_TrackerStatus_fake.call_count);
}

/**
 *  @b SendTrackerObjectsOnCAN_Executes
 *  @n
 *      Verifies that Send Tracker Objects On CAN Executes.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, SendTrackerObjectsOnCAN_Executes)
{
   Send_Tracker_Objects_On_CAN();
   /* At minimum IPC buffer should have been accessed */
   ASSERT_GE(Get_IPC_D2M_Sp_Post_Proc_Buffer_fake.call_count, 1U);
}

/**
 *  @b SendRadarStatus001Messages_CounterElsePath_Covered
 *  @n
 *      Verifies that Send Radar Status001 Messages Counter Else Path Covered.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, SendRadarStatus001Messages_CounterElsePath_Covered)
{
   uint32_t before = Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_fake.call_count;
   uint32_t guard  = 0U;
   while ((Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_fake.call_count == before) &&
          (guard < 300U))
   {
      Send_Radar_Status_001_Messages();
      guard++;
   }

   ASSERT_GT(Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_fake.call_count, before);

   uint32_t after_taken =
      Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_fake.call_count;
   Send_Radar_Status_001_Messages();
   ASSERT_EQ(after_taken,
             Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_fake.call_count);
}

/**
 *  @b SendRadarStatus002Messages_TimeSyncTrueAndReverseCovered
 *  @n
 *      Verifies that Send Radar Status002 Messages Time Sync True And Reverse Covered.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, SendRadarStatus002Messages_TimeSyncTrueAndReverseCovered)
{
   g_d2m_buf.payload.det_data.det_list_property.timestamp_status = 8U;
   g_m2d_buf.payload.veh_data.vse_output.reverse_status          = 1U;
   Send_Radar_Status_002_Messages();

   ASSERT_EQ(1U, (uint32_t)g_last_radar_status2_msg.STS_NO_TSYN_ERROR);
   ASSERT_EQ(1U, (uint32_t)g_last_radar_status2_msg.STS_VEH_SPEED_DIRECTION);
}

/**
 *  @b SendRadarStatus002Messages_NullD2MPathCovered
 *  @n
 *      Verifies that Send Radar Status002 Messages Null D2 MPath Covered.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, SendRadarStatus002Messages_NullD2MPathCovered)
{
   Get_IPC_D2M_Sp_Post_Proc_Buffer_fake.return_val = NULL;
   Send_Radar_Status_002_Messages();

   ASSERT_EQ((uint32_t)CAN_SIG_NOT_IMPLEMENTED, (uint32_t)g_last_radar_status2_msg.STS_AF_CORE_THROUGHPUT);
}

/**
 *  @b SendRadarCapabilityMessages_NullD2MPathCovered
 *  @n
 *      Verifies that Send Radar Capability Messages Null D2 MPath Covered.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, SendRadarCapabilityMessages_NullD2MPathCovered)
{
   Get_IPC_D2M_Sp_Post_Proc_Buffer_fake.return_val = NULL;
   uint32_t before = Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_fake.call_count;
   Send_Radar_Capability_Messages();
   ASSERT_EQ(before + 1U, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_fake.call_count);
}

/**
 *  @b SendRadarDetectionMessages_NullD2MSkipsWrites
 *  @n
 *      Verifies that Send Radar Detection Messages Null D2 MSkips Writes.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, SendRadarDetectionMessages_NullD2MSkipsWrites)
{
   Get_IPC_D2M_Sp_Post_Proc_Buffer_fake.return_val = NULL;
   uint32_t before = Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_001_004_AL_Vdp_SG_Detections_001_004_AL_fake.call_count;
   Send_Radar_Detection_Messages();
   ASSERT_EQ(before,
             Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_001_004_AL_Vdp_SG_Detections_001_004_AL_fake.call_count);
}

/**
 *  @b SendTrackerStatusMessages_NullD2MFallbackCovered
 *  @n
 *      Verifies that Send Tracker Status Messages Null D2 MFallback Covered.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, SendTrackerStatusMessages_NullD2MFallbackCovered)
{
   Get_IPC_D2M_Sp_Post_Proc_Buffer_fake.return_val = NULL;
   uint32_t before = Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerStatus_Vdp_SG_TrackerStatus_fake.call_count;
   Send_Tracker_Status_Messages();
   ASSERT_EQ(before + 1U, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerStatus_Vdp_SG_TrackerStatus_fake.call_count);
}

/**
 *  @b SendTrackerObjectsOnCAN_NonZeroReducedIdElsePathCovered
 *  @n
 *      Verifies that Send Tracker Objects On CAN Non Zero Reduced Id Else Path Covered.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, SendTrackerObjectsOnCAN_NonZeroReducedIdElsePathCovered)
{
   g_d2m_buf.payload.object_list_stream.object[0].reducedID                              = 1U;
   g_d2m_buf.payload.object_list_stream.object[0].xposn                                  = 5.0F;
   g_d2m_buf.payload.object_list_stream.object[0].yposn                                  = 2.0F;
   g_d2m_buf.payload.object_list_stream.object[0].xvel                                   = 3.0F;
   g_d2m_buf.payload.object_list_stream.object[0].yvel                                   = 4.0F;
   g_d2m_buf.payload.object_list_stream.object[0].orientation                            = 6.0F;
   g_d2m_buf.payload.object_list_stream.object[0].status                                 = 7U;
   g_d2m_buf.payload.object_list_stream.object[0].unique_id                              = 9U;
   g_m2d_one_time_buf.calib_data.vehicle_calib_data.k_distance_front_bumper_to_rear_axle = 2.0F;

   uint32_t before = Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject001_Vdp_SG_TrackerObject001_fake.call_count;
   Send_Tracker_Objects_On_CAN();

   decltype(g_last_tracker_object001_msg.OBJ_POS_LONG_001) exp_pos_long      = 0;
   decltype(g_last_tracker_object001_msg.OBJ_POS_LAT_001) exp_pos_lat        = 0;
   decltype(g_last_tracker_object001_msg.OBJ_VELOCITY_LONG_001) exp_vel_long = 0;
   decltype(g_last_tracker_object001_msg.OBJ_VELOCITY_LAT_001) exp_vel_lat   = 0;
   decltype(g_last_tracker_object001_msg.OBJ_YAW_ANGLE_001) exp_yaw          = 0;

   exp_pos_long = g_d2m_buf.payload.object_list_stream.object[0].xposn +
                  g_m2d_one_time_buf.calib_data.vehicle_calib_data.k_distance_front_bumper_to_rear_axle;
   exp_pos_lat  = NEG_FLOAT * g_d2m_buf.payload.object_list_stream.object[0].yposn;
   exp_vel_long = g_d2m_buf.payload.object_list_stream.object[0].xvel;
   exp_vel_lat  = NEG_FLOAT * g_d2m_buf.payload.object_list_stream.object[0].yvel;
   exp_yaw      = NEG_FLOAT * g_d2m_buf.payload.object_list_stream.object[0].orientation;

   ASSERT_EQ(before + 1U, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject001_Vdp_SG_TrackerObject001_fake.call_count);
   ASSERT_EQ(1U, (uint32_t)g_last_tracker_object001_msg.OBJ_ID_001);
   ASSERT_EQ(7U, (uint32_t)g_last_tracker_object001_msg.OBJ_MEASUREMENT_STATUS_001);
   ASSERT_EQ(9U, (uint32_t)g_last_tracker_object001_msg.OBJ_GROUP_ID_001);
   ASSERT_EQ(exp_pos_long, g_last_tracker_object001_msg.OBJ_POS_LONG_001);
   ASSERT_EQ(exp_pos_lat, g_last_tracker_object001_msg.OBJ_POS_LAT_001);
   ASSERT_EQ(exp_vel_long, g_last_tracker_object001_msg.OBJ_VELOCITY_LONG_001);
   ASSERT_EQ(exp_vel_lat, g_last_tracker_object001_msg.OBJ_VELOCITY_LAT_001);
   ASSERT_EQ(exp_yaw, g_last_tracker_object001_msg.OBJ_YAW_ANGLE_001);
}

/**
 *  @b SendTrackerObjectsOnCAN_NullD2MPathCovered
 *  @n
 *      Verifies that Send Tracker Objects On CAN Null D2 MPath Covered.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, SendTrackerObjectsOnCAN_NullD2MPathCovered)
{
   Get_IPC_D2M_Sp_Post_Proc_Buffer_fake.return_val = NULL;
   uint32_t before = Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject001_Vdp_SG_TrackerObject001_fake.call_count;
   Send_Tracker_Objects_On_CAN();
   ASSERT_EQ(before, Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_TrackerObject001_Vdp_SG_TrackerObject001_fake.call_count);
}

/**
 *  @b ExtremeLowInputs_ImproveBranchAndCallCoverage
 *  @n
 *      Verifies that Extreme Low Inputs Improve Branch And Call Coverage.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, ExtremeLowInputs_ImproveBranchAndCallCoverage)
{
   uint32_t status1_before =
      Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_fake.call_count;
   uint32_t status1_2nd_before = Get_Application_Version_fake.call_count;
   uint32_t status2_before     = Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_fake.call_count;
   uint32_t align1_before =
      Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_fake.call_count;
   uint32_t align2_before =
      Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_fake.call_count;
   uint32_t cap_before = Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_fake.call_count;
   ts_test_stub        = 1;
   g_d2m_buf.payload.rdd_stream_data.look_data.look_id                    = 0U;
   g_d2m_buf.payload.dsp_timing_data.af_time.af_xput_inst                 = -1.0e9F;
   g_d2m_buf.payload.det_data.det_list_property.timestamp_status          = 8U;
   g_d2m_buf.payload.radar_capability_data.dm.damping.current_dB          = -1.0e9F;
   g_d2m_buf.payload.radar_capability_data.dm.damping.std_dB              = -1.0e9F;
   g_d2m_buf.payload.radar_capability_data.az_fov_end_rad[0]              = -1.0e9F;
   g_d2m_buf.payload.radar_capability_data.az_fov_begin_rad[0]            = -1.0e9F;
   g_d2m_buf.payload.radar_capability_data.re.max_det_range_car[0]        = -1.0e9F;
   g_d2m_buf.payload.radar_capability_data.re.max_det_range_car[1]        = -1.0e9F;
   g_d2m_buf.payload.radar_capability_data.re.max_det_range_car[2]        = -1.0e9F;
   g_d2m_buf.payload.radar_capability_data.re.max_det_range_motorbike[0]  = -1.0e9F;
   g_d2m_buf.payload.radar_capability_data.re.max_det_range_motorbike[1]  = -1.0e9F;
   g_d2m_buf.payload.radar_capability_data.re.max_det_range_motorbike[2]  = -1.0e9F;
   g_d2m_buf.payload.radar_capability_data.re.max_det_range_pedestrian[0] = -1.0e9F;
   g_d2m_buf.payload.radar_capability_data.re.max_det_range_pedestrian[1] = -1.0e9F;
   g_d2m_buf.payload.radar_capability_data.re.max_det_range_pedestrian[2] = -1.0e9F;

   for (uint32_t i = 0U; i < 4U; i++)
   {
      g_d2m_buf.payload.det_data.af_dets[i].ran   = -1.0e9F;
      g_d2m_buf.payload.det_data.af_dets[i].vel   = -1.0e9F;
      g_d2m_buf.payload.det_data.af_dets[i].theta = -1.0e9F;
      g_d2m_buf.payload.det_data.af_dets[i].phi   = -1.0e9F;
      g_d2m_buf.payload.det_data.af_dets[i].rcs   = -1.0e9F;
      g_d2m_buf.payload.det_data.af_dets[i].snr   = -1.0e9F;
      TOI_DET_STD((&g_d2m_buf)).std_ran[i]        = -1.0e9F;
      TOI_DET_STD((&g_d2m_buf)).std_vel[i]        = -1.0e9F;
      TOI_DET_STD((&g_d2m_buf)).std_theta[i]      = -1.0e9F;
      TOI_DET_STD((&g_d2m_buf)).std_phi[i]        = -1.0e9F;
      TOI_DET_STD((&g_d2m_buf)).existence_prob[i] = -1.0e9F;
   }
   g_mcu_temp = -1.0e9F;

   g_alignment_handler.AlignmentAzimuth              = -1.0e9F;
   g_alignment_handler.AlignmentElevation            = -1.0e9F;
   g_alignment_handler.AzimuthStd                    = -1.0e9F;
   g_alignment_handler.ElevationStd                  = -1.0e9F;
   g_alignment_handler.InitialAlignmentResultHostSCF = -1.0e9F;
   g_alignment_handler.calTime                       = -1.0e9F;
   g_alignment_handler.InitialAlignmentResultAz      = -1.0e9F;
   g_alignment_handler.InitialAlignmentResultEl      = -1.0e9F;

   g_alignment_auto.AACurrentAzimuth   = -1.0e9F;
   g_alignment_auto.AACurrentElevation = -1.0e9F;
   g_alignment_auto.AAElevationStd     = -1.0e9F;
   g_alignment_auto.AAAzimuthStd       = -1.0e9F;
   g_alignment_auto.Az_Err_negative    = -1.0e9F;
   g_alignment_auto.Az_Err_positive    = -1.0e9F;
   g_alignment_auto.El_Err_negative    = -1.0e9F;
   g_alignment_auto.El_Err_positive    = -1.0e9F;
   g_alignment_auto.HostScf            = -1.0e9F;
   g_alignment_auto.RollError_positive = -1.0e9F;
   g_alignment_auto.StartAzimuth       = -1.0e9F;
   g_alignment_auto.StartElevation     = -1.0e9F;

   g_alignment_static.MeasuredRange        = -1.0e9F;
   g_alignment_static.MeasuredRangeStd     = -1.0e9F;
   g_alignment_static.MeasuredRangeRate    = -1.0e9F;
   g_alignment_static.MeasuredRangeRateStd = -1.0e9F;
   g_alignment_static.MeasuredAmplitude    = -1.0e9F;
   g_alignment_static.MeasuredAmpStd       = -1.0e9F;

   g_alignment_service.AverageSpeed      = -1.0e9F;
   g_alignment_service.DistanceAbsolute  = 0U;
   g_alignment_service.DistanceEffective = 0U;
   g_alignment_service.DurationAbsolute  = 0U;
   g_alignment_service.DurationEffective = 0U;

   Send_Radar_Header_Messages();
   uint32_t guard = 0U;
   while ((Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_fake.call_count ==
           status1_before) &&
          (guard < 300U))
   {
      Send_Radar_Status_001_Messages();
      guard++;
   }
   Send_Radar_Status_002_Messages();
   Send_Alignment_Status_001_Messages();
   Send_Alignment_Status_002_Messages();
   Send_Radar_Capability_Messages();
   Send_Radar_Detection_Messages();
   ASSERT_EQ(status1_before + 1U,
             Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_fake.call_count);
   ASSERT_GT(Get_Application_Version_fake.call_count, status1_2nd_before);
   ASSERT_EQ(status2_before + 1U,
             Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_fake.call_count);
   ASSERT_EQ(align1_before + 1U,
             Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_fake.call_count);
   ASSERT_EQ(align2_before + 1U,
             Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_fake.call_count);
   ASSERT_EQ(cap_before + 1U,
             Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_fake.call_count);
   ASSERT_EQ(1U, (uint32_t)g_last_radar_status2_msg.STS_NO_TSYN_ERROR);
   ASSERT_EQ(0U, (uint32_t)g_last_radar_status2_msg.STS_VEH_SPEED_DIRECTION);
}

/**
 *  @b ExtremeHighInputs_ImproveBranchAndCallCoverage
 *  @n
 *      Verifies that Extreme High Inputs Improve Branch And Call Coverage.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, ExtremeHighInputs_ImproveBranchAndCallCoverage)
{
   uint32_t status1_before =
      Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_fake.call_count;
   uint32_t status1_2nd_before = Get_Application_Version_fake.call_count;
   uint32_t status2_before     = Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_fake.call_count;
   uint32_t align1_before =
      Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_fake.call_count;
   uint32_t align2_before =
      Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_fake.call_count;
   uint32_t cap_before = Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_fake.call_count;
   ts_test_stub        = 2;
   g_d2m_buf.payload.rdd_stream_data.look_data.look_id                    = RADAR_LOOK_D;
   g_d2m_buf.payload.dsp_timing_data.af_time.af_xput_inst                 = 1.0e9F;
   g_d2m_buf.payload.det_data.det_list_property.timestamp_status          = 9U;
   g_d2m_buf.payload.radar_capability_data.dm.damping.current_dB          = 1.0e9F;
   g_d2m_buf.payload.radar_capability_data.dm.damping.std_dB              = 1.0e9F;
   g_d2m_buf.payload.radar_capability_data.az_fov_end_rad[0]              = 1.0e9F;
   g_d2m_buf.payload.radar_capability_data.az_fov_begin_rad[0]            = 1.0e9F;
   g_d2m_buf.payload.radar_capability_data.re.max_det_range_car[0]        = 1.0e9F;
   g_d2m_buf.payload.radar_capability_data.re.max_det_range_car[1]        = 1.0e9F;
   g_d2m_buf.payload.radar_capability_data.re.max_det_range_car[2]        = 1.0e9F;
   g_d2m_buf.payload.radar_capability_data.re.max_det_range_motorbike[0]  = 1.0e9F;
   g_d2m_buf.payload.radar_capability_data.re.max_det_range_motorbike[1]  = 1.0e9F;
   g_d2m_buf.payload.radar_capability_data.re.max_det_range_motorbike[2]  = 1.0e9F;
   g_d2m_buf.payload.radar_capability_data.re.max_det_range_pedestrian[0] = 1.0e9F;
   g_d2m_buf.payload.radar_capability_data.re.max_det_range_pedestrian[1] = 1.0e9F;
   g_d2m_buf.payload.radar_capability_data.re.max_det_range_pedestrian[2] = 1.0e9F;

   for (uint32_t i = 0U; i < 4U; i++)
   {
      g_d2m_buf.payload.det_data.af_dets[i].ran   = 1.0e9F;
      g_d2m_buf.payload.det_data.af_dets[i].vel   = 1.0e9F;
      g_d2m_buf.payload.det_data.af_dets[i].theta = 1.0e9F;
      g_d2m_buf.payload.det_data.af_dets[i].phi   = 1.0e9F;
      g_d2m_buf.payload.det_data.af_dets[i].rcs   = 1.0e9F;
      g_d2m_buf.payload.det_data.af_dets[i].snr   = 1.0e9F;
      TOI_DET_STD((&g_d2m_buf)).std_ran[i]        = 1.0e9F;
      TOI_DET_STD((&g_d2m_buf)).std_vel[i]        = 1.0e9F;
      TOI_DET_STD((&g_d2m_buf)).std_theta[i]      = 1.0e9F;
      TOI_DET_STD((&g_d2m_buf)).std_phi[i]        = 1.0e9F;
      TOI_DET_STD((&g_d2m_buf)).existence_prob[i] = 1.0e9F;
   }

   g_mcu_temp = 1.0e9F;

   g_alignment_handler.AlignmentAzimuth              = 1.0e9F;
   g_alignment_handler.AlignmentElevation            = 1.0e9F;
   g_alignment_handler.AzimuthStd                    = 1.0e9F;
   g_alignment_handler.ElevationStd                  = 1.0e9F;
   g_alignment_handler.InitialAlignmentResultHostSCF = 1.0e9F;
   g_alignment_handler.calTime                       = 1.0e9F;
   g_alignment_handler.InitialAlignmentResultAz      = 1.0e9F;
   g_alignment_handler.InitialAlignmentResultEl      = 1.0e9F;

   g_alignment_auto.AACurrentAzimuth   = 1.0e9F;
   g_alignment_auto.AACurrentElevation = 1.0e9F;
   g_alignment_auto.AAElevationStd     = 1.0e9F;
   g_alignment_auto.AAAzimuthStd       = 1.0e9F;
   g_alignment_auto.Az_Err_negative    = 1.0e9F;
   g_alignment_auto.Az_Err_positive    = 1.0e9F;
   g_alignment_auto.El_Err_negative    = 1.0e9F;
   g_alignment_auto.El_Err_positive    = 1.0e9F;
   g_alignment_auto.HostScf            = 1.0e9F;
   g_alignment_auto.RollError_positive = 1.0e9F;
   g_alignment_auto.StartAzimuth       = 1.0e9F;
   g_alignment_auto.StartElevation     = 1.0e9F;

   g_alignment_static.MeasuredRange        = 1.0e9F;
   g_alignment_static.MeasuredRangeStd     = 1.0e9F;
   g_alignment_static.MeasuredRangeRate    = 1.0e9F;
   g_alignment_static.MeasuredRangeRateStd = 1.0e9F;
   g_alignment_static.MeasuredAmplitude    = 1.0e9F;
   g_alignment_static.MeasuredAmpStd       = 1.0e9F;

   g_alignment_service.AverageSpeed                     = 1.0e9F;
   g_alignment_service.DistanceAbsolute                 = 1.0e9F;
   g_alignment_service.DistanceEffective                = 1.0e9F;
   g_alignment_service.DurationAbsolute                 = 1.0e9F;
   g_alignment_service.DurationEffective                = 1.0e9F;
   g_m2d_buf.payload.veh_data.vse_output.reverse_status = 1U;

   Send_Radar_Header_Messages();
   uint32_t guard = 0U;
   while ((Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_fake.call_count ==
           status1_before) &&
          (guard < 300U))
   {
      Send_Radar_Status_001_Messages();
      guard++;
   }
   Send_Radar_Status_002_Messages();
   Send_Alignment_Status_001_Messages();
   Send_Alignment_Status_002_Messages();
   Send_Radar_Capability_Messages();
   Send_Radar_Detection_Messages();
   ASSERT_EQ(status1_before + 1U,
             Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus1_ALPCAN_Vdp_SG_RadarStatus1_ALPCAN_fake.call_count);
   ASSERT_GT(Get_Application_Version_fake.call_count, status1_2nd_before);
   ASSERT_EQ(status2_before + 1U,
             Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarStatus2_AL_Vdp_SG_RadarStatus2_AL_fake.call_count);
   ASSERT_EQ(align1_before + 1U,
             Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus1_AL_Vdp_SG_AlignmentStatus1_AL_fake.call_count);
   ASSERT_EQ(align2_before + 1U,
             Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_AlignmentStatus2_AL_Vdp_SG_AlignmentStatus2_AL_fake.call_count);
   ASSERT_EQ(cap_before + 1U,
             Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_RadarCapability_AL_Vdp_SG_RadarCapability_AL_fake.call_count);
   ASSERT_EQ(0U, (uint32_t)g_last_radar_status2_msg.STS_NO_TSYN_ERROR);
   ASSERT_EQ(1U, (uint32_t)g_last_radar_status2_msg.STS_VEH_SPEED_DIRECTION);
}

/**
 *  @b SendRadarDetectionMessages_D2MSet_M2DNull_PathCovered
 *  @n
 *      Verifies that Send Radar Detection Messages D2 MSet M2 DNull Path Covered.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, SendRadarDetectionMessages_D2MSet_M2DNull_PathCovered)
{
   Get_IPC_D2M_Sp_Post_Proc_Buffer_fake.return_val = &g_d2m_buf;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val      = NULL;
   uint32_t before = Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_001_004_AL_Vdp_SG_Detections_001_004_AL_fake.call_count;
   Send_Radar_Detection_Messages();
   ASSERT_EQ(before,
             Rte_Write_SWC_PLT_Appl_Communication_Pp_SG_Detections_001_004_AL_Vdp_SG_Detections_001_004_AL_fake.call_count);
}

/**
 *  @b BCD_To_Decimal_test
 *  @n
 *      Verifies that BCD to Decimal conversion works correctly.
 */
TEST_F(Can_Tx_Msgs_UnitTestSuite, BCD_To_Decimal_test)
{
   BCD_To_Decimal(10U);
   ASSERT_EQ(BCD_To_Decimal(0x10U), 10U);
}
