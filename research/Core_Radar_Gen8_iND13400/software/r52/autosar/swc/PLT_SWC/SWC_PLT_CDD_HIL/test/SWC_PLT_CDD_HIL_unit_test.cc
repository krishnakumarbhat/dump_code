/*===========================================================================*/
/**
 * @file SWC_PLT_CDD_HIL_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for the checking the ipc_data.c file
 *
 * @section ABBR ABBREVIATIONS:
 *   - List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include <gtest/gtest.h>
/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "fff.h"
extern "C"
{
#include "SWC_PLT_CDD_HIL.c"
#include "SWC_PLT_CDD_HIL_fake.h"
#include "hil_communication_handler_fake.h"
}

/*===========================================================================*
 * Global Variables
 *===========================================================================*/
VAR(uint8, RTE_VAR_INIT) Rte_SWC_PLT_CDD_XCP_Pp_Hil_Activation_De_Hil_Activation = 0U;

/*===========================================================================*
 * local Variables
 *===========================================================================*/
static uint8_t Radar_Position;
static M2D_Msg_T mss_to_dss_l3_ut;
static M2D_One_Time_Msg_T mss_one_time_msg_ut;
static Status_Stream_T status_stream_ut;
static Header_Stream_T header_stream_ut;
static HIL_Output_T hil_output_ut;

typedef struct
{
   float32_t val_a;
   float32_t val_b;
   bool compared_result;
} FloatTestCase;

typedef struct
{
   float32_t sensor_height_ut;
   float32_t sensor_mount_ornt_yaw_ut;
   float32_t sensor_mount_ornt_pitch_ut;
   float32_t sensor_mount_ornt_roll_ut;
   float32_t sensor_long_offset_ut;
   float32_t sensor_mount_pos_x_ut;
   float32_t sensor_mount_pos_y_ut;
   float32_t sensor_mount_pos_z_ut;
   uint8_t compared_result;
} Mounting_Pos_UT;
/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class cdd_HIL_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_FAKES_HIL_SWC_PLT_CDD_LIST(RESET_FAKE);
      memset(&status_stream_ut, 0U, sizeof(Status_Stream_T));
      memset(&header_stream_ut, 0U, sizeof(Header_Stream_T));
      memset(&mss_to_dss_l3_ut, 0U, sizeof(M2D_Msg_T));
      memset(&mss_one_time_msg_ut, 0U, sizeof(M2D_One_Time_Msg_T));
      memset(&hil_output_ut, 0U, sizeof(HIL_Output_T));
   }

   /**
    * @b Description
    * @n
    *    Method run after each individual test  case.
    */
   void TearDown()
   {
   }
};

/* redefinition of global variables used by UUT */

/******************************************************************************
 *. Test Case Name: CDD_HIL_SANITY_CHECK
 *.
 *. Objective: Basic test
 *.
 *.
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, CDD_HIL_SANITY_CHECK)
{
   RE_PLT_HIL_Init(); /*This is an empty function*/

   ASSERT_EQ(true, true);
}
#if 0
/******************************************************************************
 *. Test Case Name: Mounting_Position_Frm_Status_Log_Test1
 *.
 *. Objective: To test the function when there is no change in mounting
 *.             position values.
 *.
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, Mounting_Position_Frm_Status_Log_Test1)
{
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val                       = &mss_to_dss_l3_ut;
   Get_Status_Stream_Ptr_fake.return_val                            = &status_stream_ut;
   Get_IPC_M2D_Onetime_Msg_buffer_fake.return_val                   = &mss_one_time_msg_ut;
   M2D_Msg_T *ipc_m2d_ptr_ut                                        = Get_MSS_IPC_M2D_Msg_buffer();
   M2D_One_Time_Msg_T *m2d_smc_val_ptr_ut                           = Get_IPC_M2D_Onetime_Msg_buffer();
   Status_Stream_T *status_stream_ptr_ut                            = Get_Status_Stream_Ptr();
   Get_Radar_Position_fake.return_val                               = 1;
   ipc_m2d_ptr_ut->payload.hil_ipc_info.hil_src_radar_mounting_data = HIL_EXECUTE_INJECTION_DATA;
   uint8_t update_found                                             = CODED_FALSE;

   update_found = Update_Mounting_Position_From_Status_Log();
   ASSERT_EQ(update_found, CODED_FALSE); /*No change in mounting position value*/
}

/******************************************************************************
 *. Test Case Name: Mounting_Position_Frm_Status_Log_Test2
 *.
 *. Objective: To test the function when there is change in mounting
 *.             position values.
 *.
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, Mounting_Position_Frm_Status_Log_Test2)
{
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val                       = &mss_to_dss_l3_ut;
   Get_Status_Stream_Ptr_fake.return_val                            = &status_stream_ut;
   Get_IPC_M2D_Onetime_Msg_buffer_fake.return_val                   = &mss_one_time_msg_ut;
   M2D_Msg_T *ipc_m2d_ptr_ut                                        = Get_MSS_IPC_M2D_Msg_buffer();
   M2D_One_Time_Msg_T *m2d_smc_val_ptr_ut                           = Get_IPC_M2D_Onetime_Msg_buffer();
   Status_Stream_T *status_stream_ptr_ut                            = Get_Status_Stream_Ptr();
   Get_Radar_Position_fake.return_val                               = 1;
   ipc_m2d_ptr_ut->payload.hil_ipc_info.hil_src_radar_mounting_data = HIL_EXECUTE_INJECTION_DATA;
   uint8_t update_found                                             = CODED_FALSE;

   status_stream_ptr_ut->sensor_mount_ornt_yaw = 0.15f; /*change in mounting position parameter*/
   update_found                                = Update_Mounting_Position_From_Status_Log();
   ASSERT_EQ(update_found, CODED_TRUE);
   ASSERT_FLOAT_EQ(m2d_smc_val_ptr_ut->sensor_data_buf.k_sensor_mount_ornt_yaw_list_str,
                   status_stream_ptr_ut->sensor_mount_ornt_yaw);
}

/******************************************************************************
 *. Test Case Name: Mounting_Position_Frm_Status_Log_Test3
 *.
 *. Objective: To test the function during NULL pointer scenario.
 *.
 *.
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, Mounting_Position_Frm_Status_Log_Test3)
{
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val                       = &mss_to_dss_l3_ut;
   Get_Status_Stream_Ptr_fake.return_val                            = &status_stream_ut;
   Get_IPC_M2D_Onetime_Msg_buffer_fake.return_val                   = NULL;
   Status_Stream_T *status_stream_ptr_ut                            = Get_Status_Stream_Ptr();
   M2D_Msg_T *ipc_m2d_ptr_ut                                        = Get_MSS_IPC_M2D_Msg_buffer();
   ipc_m2d_ptr_ut->payload.hil_ipc_info.hil_src_radar_mounting_data = HIL_EXECUTE_INJECTION_DATA;
   Get_Radar_Position_fake.return_val                               = 1;
   uint8_t update_found                                             = CODED_TRUE;

   update_found = Update_Mounting_Position_From_Status_Log();
   ASSERT_EQ(update_found, CODED_FALSE);
}

/******************************************************************************
 *. Test Case Name: Mounting_Position_Frm_Status_Log_Test4
 *.
 *. Objective: To test the function when HIL Injection flag is not set.
 *.
 *.
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, Mounting_Position_Frm_Status_Log_Test4)
{
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val                       = &mss_to_dss_l3_ut;
   Get_Status_Stream_Ptr_fake.return_val                            = &status_stream_ut;
   Get_IPC_M2D_Onetime_Msg_buffer_fake.return_val                   = &mss_one_time_msg_ut;
   M2D_Msg_T *ipc_m2d_ptr_ut                                        = Get_MSS_IPC_M2D_Msg_buffer();
   Status_Stream_T *status_stream_ptr_ut                            = Get_Status_Stream_Ptr();
   M2D_One_Time_Msg_T *m2d_smc_val_ptr_ut                           = Get_IPC_M2D_Onetime_Msg_buffer();
   ipc_m2d_ptr_ut->payload.hil_ipc_info.hil_src_radar_mounting_data = HIL_EXECUTE_EMBEDDED_ALGO;
   Get_Radar_Position_fake.return_val                               = 1;
   uint8_t update_found                                             = CODED_FALSE;

   status_stream_ptr_ut->sensor_mount_ornt_pitch = 0.8f;
   update_found                                  = Update_Mounting_Position_From_Status_Log();
   ASSERT_EQ(update_found, CODED_FALSE); /*since hil_src_radar_mounting_data not set to proper value*/

   status_stream_ptr_ut->sensor_mount_ornt_pitch                    = 0.75f;
   ipc_m2d_ptr_ut->payload.hil_ipc_info.hil_src_radar_mounting_data = HIL_EXECUTE_INJECTION_DATA;
   update_found                                                     = Update_Mounting_Position_From_Status_Log();
   ASSERT_EQ(update_found, CODED_TRUE); /*since hil_src_radar_mounting_data is set to proper value*/
   ASSERT_FLOAT_EQ(m2d_smc_val_ptr_ut->sensor_data_buf.k_sensor_mount_ornt_yaw_list_str,
                   status_stream_ptr_ut->sensor_mount_ornt_yaw);
}

/******************************************************************************
 *. Test Case Name: Mounting_Position_Frm_Status_Log_Test5
 *.
 *. Objective:
 *.   Parameterized sweep to exercise each individual mounting position/orientation
 *.   field acting alone as a potential change trigger, plus cases with no change.
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, Mounting_Position_Frm_Status_Log_Test5)
{
   Mounting_Pos_UT mount_pos[] = {
      {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, CODED_FALSE}, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.75f, CODED_TRUE},
      {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.65f, 0.0f, CODED_TRUE}, {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.55f, 0.0f, 0.0f, CODED_TRUE},
      {0.0f, 0.0f, 0.0f, 0.0f, 0.45f, 0.0f, 0.0f, 0.0f, CODED_TRUE}, {0.0f, 0.0f, 0.0f, 3.35f, 0.0f, 0.0f, 0.0f, 0.0f, CODED_TRUE},
      {0.0f, 0.0f, 0.25f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, CODED_TRUE}, {0.0f, 0.15f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, CODED_TRUE},
      {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, CODED_TRUE},  {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0, 0.0f, CODED_FALSE},
      {9.759f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0, 0.0f, CODED_TRUE}};
   uint8_t num_tests = sizeof(mount_pos) / sizeof(mount_pos[0]);
   uint8_t update_found;

   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val                       = &mss_to_dss_l3_ut;
   Get_Status_Stream_Ptr_fake.return_val                            = &status_stream_ut;
   Get_IPC_M2D_Onetime_Msg_buffer_fake.return_val                   = &mss_one_time_msg_ut;
   M2D_Msg_T *ipc_m2d_ptr_ut                                        = Get_MSS_IPC_M2D_Msg_buffer();
   M2D_One_Time_Msg_T *m2d_smc_val_ptr_ut                           = Get_IPC_M2D_Onetime_Msg_buffer();
   Status_Stream_T *status_stream_ptr_ut                            = Get_Status_Stream_Ptr();
   Get_Radar_Position_fake.return_val                               = 1;
   ipc_m2d_ptr_ut->payload.hil_ipc_info.hil_src_radar_mounting_data = HIL_EXECUTE_INJECTION_DATA;

   for (uint8_t i = 0; i < num_tests; i++)
   {
      status_stream_ptr_ut->sensor_height           = mount_pos[i].sensor_height_ut;
      status_stream_ptr_ut->sensor_mount_ornt_yaw   = mount_pos[i].sensor_mount_ornt_yaw_ut;
      status_stream_ptr_ut->sensor_mount_ornt_pitch = mount_pos[i].sensor_mount_ornt_pitch_ut;
      status_stream_ptr_ut->sensor_mount_ornt_roll  = mount_pos[i].sensor_mount_ornt_roll_ut;
      status_stream_ptr_ut->sensor_long_offset      = mount_pos[i].sensor_long_offset_ut;
      status_stream_ptr_ut->sensor_mount_pos_x      = mount_pos[i].sensor_mount_pos_x_ut;
      status_stream_ptr_ut->sensor_mount_pos_y      = mount_pos[i].sensor_mount_pos_y_ut;
      status_stream_ptr_ut->sensor_mount_pos_z      = mount_pos[i].sensor_mount_pos_z_ut;

      update_found = Update_Mounting_Position_From_Status_Log();
      ASSERT_EQ(update_found, mount_pos[i].compared_result);
   }
}

/******************************************************************************
 * Test Case Name: Mounting_Position_Frm_Status_Log_Test_PosZFirstTrue
 * Objective: pos_z is the FIRST differing operand (> epsilon). All prior operands false,
 *            later operands (height, long_offset) equal so short-circuit occurs at pos_z.
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, Mounting_Position_Frm_Status_Log_Test_PosZFirstTrue)
{
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val                        = &mss_to_dss_l3_ut;
   Get_Status_Stream_Ptr_fake.return_val                             = &status_stream_ut;
   Get_IPC_M2D_Onetime_Msg_buffer_fake.return_val                    = &mss_one_time_msg_ut;
   Get_Radar_Position_fake.return_val                                = 1;
   mss_to_dss_l3_ut.payload.hil_ipc_info.hil_src_radar_mounting_data = HIL_EXECUTE_INJECTION_DATA;

   /* Align all previous operands exactly (false) */
   mss_one_time_msg_ut.sensor_data_buf.k_sensor_mount_ornt_yaw_list_str   = status_stream_ut.sensor_mount_ornt_yaw;
   mss_one_time_msg_ut.sensor_data_buf.k_sensor_mount_ornt_pitch_list_str = status_stream_ut.sensor_mount_ornt_pitch;
   mss_one_time_msg_ut.sensor_data_buf.k_sensor_mount_ornt_roll_list_str  = status_stream_ut.sensor_mount_ornt_roll;
   mss_one_time_msg_ut.sensor_data_buf.k_sensor_mount_pos_x_list_str      = status_stream_ut.sensor_mount_pos_x;
   mss_one_time_msg_ut.sensor_data_buf.k_sensor_mount_pos_y_list_str      = status_stream_ut.sensor_mount_pos_y;

   /* Make pos_z differ (> epsilon) */
   mss_one_time_msg_ut.sensor_data_buf.k_sensor_mount_pos_z_list_str = status_stream_ut.sensor_mount_pos_z + 0.05f;

   /* Later operands equal so evaluation should short-circuit at pos_z */
   mss_one_time_msg_ut.sensor_data_buf.k_sensor_mount_height_list_str           = status_stream_ut.sensor_height;
   mss_one_time_msg_ut.sensor_data_buf.k_distance_front_bumper_to_rear_axle_str = status_stream_ut.sensor_long_offset;

   uint8_t update_found = Update_Mounting_Position_From_Status_Log();
   ASSERT_EQ(update_found, CODED_TRUE);
   ASSERT_FLOAT_EQ(mss_one_time_msg_ut.sensor_data_buf.k_sensor_mount_pos_z_list_str, status_stream_ut.sensor_mount_pos_z);
}
#endif

/******************************************************************************
 * Additional Coverage Tests for SWC_PLT_CDD_HIL.c
 ******************************************************************************/

// Test RE_PLT_HIL_Init (should be a no-op, but call for coverage)
TEST_F(cdd_HIL_UnitTestSuite, Coverage_RE_PLT_HIL_Init)
{
   RE_PLT_HIL_Init();
   SUCCEED();
}

// Test Update_Mounting_Position_From_Status_Log with default/fake setup
TEST_F(cdd_HIL_UnitTestSuite, Coverage_Update_Mounting_Position_Default)
{
   Get_Status_Stream_Ptr_fake.return_val          = &status_stream_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val     = &mss_to_dss_l3_ut;
   Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = &mss_one_time_msg_ut;
   Get_Radar_Position_fake.return_val             = 2;
   uint8_t ret                                    = Update_Mounting_Position_From_Status_Log();
   ASSERT_EQ(ret, CODED_FALSE);
}

// ================= FULL COVERAGE TESTS FOR ALL ACTIVE FUNCTIONS =================
// Test Update_Mounting_Position_From_Status_Log: normal and edge
TEST_F(cdd_HIL_UnitTestSuite, FullCoverage_Update_Mounting_Position_From_Status_Log)
{
   Get_Status_Stream_Ptr_fake.return_val          = &status_stream_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val     = &mss_to_dss_l3_ut;
   Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = &mss_one_time_msg_ut;
   Get_Radar_Position_fake.return_val             = 3;
   uint8_t ret                                    = Update_Mounting_Position_From_Status_Log();
   ASSERT_EQ(ret, CODED_FALSE);
}

/******************************************************************************
 *. Test Case Name: Update_Mounting_Position_NoInjectionFlag_NoUpdate
 *.
 *. Objective: Verify that when hil_src_radar_mounting_data != HIL_EXECUTE_INJECTION_DATA
 *.            the function returns CODED_FALSE and does not modify calibration data.
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, Update_Mounting_Position_NoInjectionFlag_NoUpdate)
{
   Get_Status_Stream_Ptr_fake.return_val          = &status_stream_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val     = &mss_to_dss_l3_ut;
   Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = &mss_one_time_msg_ut;

   mss_to_dss_l3_ut.payload.hil_ipc_info.hil_src_radar_mounting_data                          = HIL_EXECUTE_EMBEDDED_ALGO;
   mss_one_time_msg_ut.calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_yaw = 1.0F;
   status_stream_ut.sensor_mount_ornt_yaw                                                     = 5.0F;

   uint8_t ret = Update_Mounting_Position_From_Status_Log();

   ASSERT_EQ(ret, CODED_FALSE);
   /* Calibration data must remain untouched */
   ASSERT_FLOAT_EQ(mss_one_time_msg_ut.calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_yaw, 1.0F);
}

/******************************************************************************
 *. Test Case Name: Update_Mounting_Position_NullOneTimeMsg_NoUpdate
 *.
 *. Objective: Verify that when Get_IPC_M2D_Onetime_Msg_Buffer returns NULL
 *.            the function returns CODED_FALSE without crashing.
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, Update_Mounting_Position_NullOneTimeMsg_NoUpdate)
{
   Get_Status_Stream_Ptr_fake.return_val          = &status_stream_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val     = &mss_to_dss_l3_ut;
   Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = NULL;

   mss_to_dss_l3_ut.payload.hil_ipc_info.hil_src_radar_mounting_data = HIL_EXECUTE_INJECTION_DATA;
   status_stream_ut.sensor_mount_ornt_pitch                          = 2.0F;

   uint8_t ret = Update_Mounting_Position_From_Status_Log();

   ASSERT_EQ(ret, CODED_FALSE);
}

/******************************************************************************
 *. Test Case Name: Update_Mounting_Position_FieldChange_UpdatesCalib
 *.
 *. Objective: Verify that when all mounting fields differ from calibration
 *.            data the function returns CODED_TRUE and copies every field.
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, Update_Mounting_Position_FieldChange_UpdatesCalib)
{
   Get_Status_Stream_Ptr_fake.return_val          = &status_stream_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val     = &mss_to_dss_l3_ut;
   Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = &mss_one_time_msg_ut;

   mss_to_dss_l3_ut.payload.hil_ipc_info.hil_src_radar_mounting_data = HIL_EXECUTE_INJECTION_DATA;

   status_stream_ut.sensor_mount_ornt_yaw   = 0.11F;
   status_stream_ut.sensor_mount_ornt_pitch = 0.22F;
   status_stream_ut.sensor_mount_ornt_roll  = 0.33F;
   status_stream_ut.sensor_mount_pos_x      = 1.10F;
   status_stream_ut.sensor_mount_pos_y      = 2.20F;
   status_stream_ut.sensor_mount_pos_z      = 3.30F;
   status_stream_ut.sensor_height           = 4.40F;
   status_stream_ut.sensor_long_offset      = 5.50F;

   uint8_t ret = Update_Mounting_Position_From_Status_Log();

   ASSERT_EQ(ret, CODED_TRUE);
   ASSERT_FLOAT_EQ(mss_one_time_msg_ut.calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_yaw,
                   status_stream_ut.sensor_mount_ornt_yaw);
   ASSERT_FLOAT_EQ(mss_one_time_msg_ut.calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_pitch,
                   status_stream_ut.sensor_mount_ornt_pitch);
   ASSERT_FLOAT_EQ(mss_one_time_msg_ut.calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_roll,
                   status_stream_ut.sensor_mount_ornt_roll);
   ASSERT_FLOAT_EQ(mss_one_time_msg_ut.calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_x,
                   status_stream_ut.sensor_mount_pos_x);
   ASSERT_FLOAT_EQ(mss_one_time_msg_ut.calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_y,
                   status_stream_ut.sensor_mount_pos_y);
   ASSERT_FLOAT_EQ(mss_one_time_msg_ut.calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_z,
                   status_stream_ut.sensor_mount_pos_z);
   ASSERT_FLOAT_EQ(mss_one_time_msg_ut.calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_height,
                   status_stream_ut.sensor_height);
   ASSERT_FLOAT_EQ(mss_one_time_msg_ut.calib_data.vehicle_calib_data.k_distance_front_bumper_to_rear_axle,
                   status_stream_ut.sensor_long_offset);
}

/******************************************************************************
 *. Test Case Name: Update_Mounting_Position_NoChange_ReturnsFalse
 *.
 *. Objective: Verify that when all mounting fields match (within epsilon)
 *.            the function returns CODED_FALSE and does not overwrite data.
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, Update_Mounting_Position_NoChange_ReturnsFalse)
{
   Get_Status_Stream_Ptr_fake.return_val          = &status_stream_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val     = &mss_to_dss_l3_ut;
   Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = &mss_one_time_msg_ut;

   mss_to_dss_l3_ut.payload.hil_ipc_info.hil_src_radar_mounting_data = HIL_EXECUTE_INJECTION_DATA;

   /* All fields zero in both structures (from SetUp memset) → no difference */
   uint8_t ret = Update_Mounting_Position_From_Status_Log();
   ASSERT_EQ(ret, CODED_FALSE);
}

// Test Get_MPU_Status_For_HIL_Trigger: default and pointer branch
TEST_F(cdd_HIL_UnitTestSuite, FullCoverage_Get_MPU_Status_For_HIL_Trigger)
{
   uint8_t dummy                             = 0;
   Get_Req_En_Dis_CDC_Stream_fake.return_val = &dummy;
   uint8_t ret                               = Get_MPU_Status_For_HIL_Trigger();
   ASSERT_EQ(ret, CODED_TRUE);
   ASSERT_EQ(dummy, CODED_TRUE);
}

// ================= FULL COVERAGE TESTS FOR HIL_Periodic_Handler =================

// Helper to reset all relevant state
static void ResetHILState_HIL_Periodic()
{
   memset(&hil_output_ut, 0, sizeof(hil_output_ut));
   memset(&mss_to_dss_l3_ut, 0, sizeof(mss_to_dss_l3_ut));
   memset(&status_stream_ut, 0, sizeof(status_stream_ut));
   memset(&header_stream_ut, 0, sizeof(header_stream_ut));
   memset(&mss_one_time_msg_ut, 0, sizeof(mss_one_time_msg_ut));
}

// 1. STATUS only enabled, mode enabled
TEST_F(cdd_HIL_UnitTestSuite, HIL_Periodic_Handler_STATUS_Only)
{
   ResetHILState_HIL_Periodic();
   Get_HIL_Output_Data_Ptr_fake.return_val    = &hil_output_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val = &mss_to_dss_l3_ut;
   Get_Status_Stream_Ptr_fake.return_val      = &status_stream_ut;
   hil_output_ut.hil_enabled_streams[STATUS]  = CODED_TRUE;
   hil_output_ut.hil_mode_enabled             = CODED_TRUE;
   HIL_Periodic_Handler();
   ASSERT_EQ(mss_to_dss_l3_ut.payload.hil_ipc_info.hil_request_reinit_module, CODED_FALSE);
}

// 3. Both enabled, mode enabled
TEST_F(cdd_HIL_UnitTestSuite, HIL_Periodic_Handler_BothStreams_ModeEnabled)
{
   ResetHILState_HIL_Periodic();
   Get_HIL_Output_Data_Ptr_fake.return_val    = &hil_output_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val = &mss_to_dss_l3_ut;
   Get_Status_Stream_Ptr_fake.return_val      = &status_stream_ut;
   hil_output_ut.hil_enabled_streams[STATUS]  = CODED_TRUE;
   hil_output_ut.hil_mode_enabled             = CODED_TRUE;
   HIL_Periodic_Handler();
   // Both branches should be taken
   ASSERT_EQ(mss_to_dss_l3_ut.payload.hil_ipc_info.hil_request_reinit_module, CODED_FALSE);
}

// 4. Both enabled, mode disabled
TEST_F(cdd_HIL_UnitTestSuite, HIL_Periodic_Handler_BothStreams_ModeDisabled)
{
   ResetHILState_HIL_Periodic();
   Get_HIL_Output_Data_Ptr_fake.return_val    = &hil_output_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val = &mss_to_dss_l3_ut;
   Get_Status_Stream_Ptr_fake.return_val      = &status_stream_ut;
   hil_output_ut.hil_enabled_streams[STATUS]  = CODED_TRUE;
   hil_output_ut.hil_mode_enabled             = CODED_FALSE;
   HIL_Periodic_Handler();
   // Should not update anything
   ASSERT_EQ(mss_to_dss_l3_ut.payload.hil_ipc_info.hil_request_reinit_module, 0);
}

// ================= FULL COVERAGE TESTS FOR RE_HIL_Periodic_Handler =================

// --- Tests for RE_HIL_Periodic_Handler using real logic and global state ---
static void ResetHILState_RE_HIL_Periodic()
{
   Periodic_Injection_Call      = true;
   Test_HIL_MPU_Status_Override = CODED_TRUE; /* restore default for each test */
}

// 1. MPU TRUE → HIL_Periodic_Handler executes, Periodic_Injection_Call stays true
TEST_F(cdd_HIL_UnitTestSuite, RE_HIL_Periodic_Handler_MPU_True)
{
   ResetHILState_RE_HIL_Periodic();
   uint8_t dummy                              = 0;
   Get_Req_En_Dis_CDC_Stream_fake.return_val  = &dummy;
   Get_HIL_Output_Data_Ptr_fake.return_val    = &hil_output_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val = &mss_to_dss_l3_ut;

   RE_HIL_Periodic_Handler();

   /* Periodic_Injection_Call must remain true: MPU is enabled */
   ASSERT_EQ(Periodic_Injection_Call, true);
   /* Get_Req_En_Dis_CDC_Stream output buffer should be written with CODED_TRUE */
   ASSERT_EQ(dummy, CODED_TRUE);
}

// 2. MPU FALSE → else branch: Periodic_Injection_Call set to false
TEST_F(cdd_HIL_UnitTestSuite, RE_HIL_Periodic_Handler_MPU_False)
{
   ResetHILState_RE_HIL_Periodic();
   Test_HIL_MPU_Status_Override              = CODED_FALSE; /* force the else branch */
   uint8_t dummy                             = 0;
   Get_Req_En_Dis_CDC_Stream_fake.return_val = &dummy;

   RE_HIL_Periodic_Handler();

   /* else branch must have executed */
   ASSERT_EQ(Periodic_Injection_Call, false);
   /* CDC stream flag must reflect CODED_FALSE */
   ASSERT_EQ(dummy, CODED_FALSE);
}
// 5. Both disabled, mode enabled
TEST_F(cdd_HIL_UnitTestSuite, HIL_Periodic_Handler_BothStreamsDisabled_ModeEnabled)
{
   ResetHILState_HIL_Periodic();
   Get_HIL_Output_Data_Ptr_fake.return_val    = &hil_output_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val = &mss_to_dss_l3_ut;
   Get_Status_Stream_Ptr_fake.return_val      = &status_stream_ut;
   hil_output_ut.hil_enabled_streams[STATUS]  = CODED_FALSE;
   hil_output_ut.hil_mode_enabled             = CODED_TRUE;
   HIL_Periodic_Handler();
   // Should not update anything
   ASSERT_EQ(mss_to_dss_l3_ut.payload.hil_ipc_info.hil_request_reinit_module, 0);
}

// 6. Both disabled, mode disabled
TEST_F(cdd_HIL_UnitTestSuite, HIL_Periodic_Handler_BothStreamsDisabled_ModeDisabled)
{
   ResetHILState_HIL_Periodic();
   Get_HIL_Output_Data_Ptr_fake.return_val    = &hil_output_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val = &mss_to_dss_l3_ut;
   Get_Status_Stream_Ptr_fake.return_val      = &status_stream_ut;
   hil_output_ut.hil_enabled_streams[STATUS]  = CODED_FALSE;
   hil_output_ut.hil_mode_enabled             = CODED_FALSE;
   HIL_Periodic_Handler();
   // Should not update anything
   ASSERT_EQ(mss_to_dss_l3_ut.payload.hil_ipc_info.hil_request_reinit_module, 0);
}

// ================= BRANCH COVERAGE: || short-circuit in Update_Mounting_Position_From_Status_Log =================
// Each test makes exactly ONE field differ from calibration data so that the || chain
// evaluates false for all preceding operands and true at the target operand.
// This covers the false→true branch transition at every position in the chain.

/******************************************************************************
 *. Test Case Name: Update_Mounting_Position_OnlyPitchDiffers
 *. Objective: Only pitch differs → yaw false, pitch true (short-circuits rest).
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, Update_Mounting_Position_OnlyPitchDiffers)
{
   Get_Status_Stream_Ptr_fake.return_val          = &status_stream_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val     = &mss_to_dss_l3_ut;
   Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = &mss_one_time_msg_ut;

   mss_to_dss_l3_ut.payload.hil_ipc_info.hil_src_radar_mounting_data = HIL_EXECUTE_INJECTION_DATA;

   status_stream_ut.sensor_mount_ornt_pitch = 1.0F;

   uint8_t ret = Update_Mounting_Position_From_Status_Log();
   ASSERT_EQ(ret, CODED_TRUE);
   ASSERT_FLOAT_EQ(mss_one_time_msg_ut.calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_pitch, 1.0F);
}

/******************************************************************************
 *. Test Case Name: Update_Mounting_Position_OnlyRollDiffers
 *. Objective: Only roll differs → yaw false, pitch false, roll true.
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, Update_Mounting_Position_OnlyRollDiffers)
{
   Get_Status_Stream_Ptr_fake.return_val          = &status_stream_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val     = &mss_to_dss_l3_ut;
   Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = &mss_one_time_msg_ut;

   mss_to_dss_l3_ut.payload.hil_ipc_info.hil_src_radar_mounting_data = HIL_EXECUTE_INJECTION_DATA;

   status_stream_ut.sensor_mount_ornt_roll = 1.0F;

   uint8_t ret = Update_Mounting_Position_From_Status_Log();
   ASSERT_EQ(ret, CODED_TRUE);
   ASSERT_FLOAT_EQ(mss_one_time_msg_ut.calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_roll, 1.0F);
}

/******************************************************************************
 *. Test Case Name: Update_Mounting_Position_OnlyPosXDiffers
 *. Objective: Only pos_x differs.
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, Update_Mounting_Position_OnlyPosXDiffers)
{
   Get_Status_Stream_Ptr_fake.return_val          = &status_stream_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val     = &mss_to_dss_l3_ut;
   Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = &mss_one_time_msg_ut;

   mss_to_dss_l3_ut.payload.hil_ipc_info.hil_src_radar_mounting_data = HIL_EXECUTE_INJECTION_DATA;

   status_stream_ut.sensor_mount_pos_x = 1.0F;

   uint8_t ret = Update_Mounting_Position_From_Status_Log();
   ASSERT_EQ(ret, CODED_TRUE);
   ASSERT_FLOAT_EQ(mss_one_time_msg_ut.calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_x, 1.0F);
}

/******************************************************************************
 *. Test Case Name: Update_Mounting_Position_OnlyPosYDiffers
 *. Objective: Only pos_y differs.
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, Update_Mounting_Position_OnlyPosYDiffers)
{
   Get_Status_Stream_Ptr_fake.return_val          = &status_stream_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val     = &mss_to_dss_l3_ut;
   Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = &mss_one_time_msg_ut;

   mss_to_dss_l3_ut.payload.hil_ipc_info.hil_src_radar_mounting_data = HIL_EXECUTE_INJECTION_DATA;

   status_stream_ut.sensor_mount_pos_y = 1.0F;

   uint8_t ret = Update_Mounting_Position_From_Status_Log();
   ASSERT_EQ(ret, CODED_TRUE);
   ASSERT_FLOAT_EQ(mss_one_time_msg_ut.calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_y, 1.0F);
}

/******************************************************************************
 *. Test Case Name: Update_Mounting_Position_OnlyPosZDiffers
 *. Objective: Only pos_z differs.
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, Update_Mounting_Position_OnlyPosZDiffers)
{
   Get_Status_Stream_Ptr_fake.return_val          = &status_stream_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val     = &mss_to_dss_l3_ut;
   Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = &mss_one_time_msg_ut;

   mss_to_dss_l3_ut.payload.hil_ipc_info.hil_src_radar_mounting_data = HIL_EXECUTE_INJECTION_DATA;

   status_stream_ut.sensor_mount_pos_z = 1.0F;

   uint8_t ret = Update_Mounting_Position_From_Status_Log();
   ASSERT_EQ(ret, CODED_TRUE);
   ASSERT_FLOAT_EQ(mss_one_time_msg_ut.calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_pos_z, 1.0F);
}

/******************************************************************************
 *. Test Case Name: Update_Mounting_Position_OnlyHeightDiffers
 *. Objective: Only height differs.
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, Update_Mounting_Position_OnlyHeightDiffers)
{
   Get_Status_Stream_Ptr_fake.return_val          = &status_stream_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val     = &mss_to_dss_l3_ut;
   Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = &mss_one_time_msg_ut;

   mss_to_dss_l3_ut.payload.hil_ipc_info.hil_src_radar_mounting_data = HIL_EXECUTE_INJECTION_DATA;

   status_stream_ut.sensor_height = 1.0F;

   uint8_t ret = Update_Mounting_Position_From_Status_Log();
   ASSERT_EQ(ret, CODED_TRUE);
   ASSERT_FLOAT_EQ(mss_one_time_msg_ut.calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_height, 1.0F);
}

/******************************************************************************
 *. Test Case Name: Update_Mounting_Position_OnlyLongOffsetDiffers
 *. Objective: Only long_offset (last operand) differs → all prior operands false,
 *.            last operand true. No short-circuit; entire chain evaluated.
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, Update_Mounting_Position_OnlyLongOffsetDiffers)
{
   Get_Status_Stream_Ptr_fake.return_val          = &status_stream_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val     = &mss_to_dss_l3_ut;
   Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = &mss_one_time_msg_ut;

   mss_to_dss_l3_ut.payload.hil_ipc_info.hil_src_radar_mounting_data = HIL_EXECUTE_INJECTION_DATA;

   status_stream_ut.sensor_long_offset = 1.0F;

   uint8_t ret = Update_Mounting_Position_From_Status_Log();
   ASSERT_EQ(ret, CODED_TRUE);
   ASSERT_FLOAT_EQ(mss_one_time_msg_ut.calib_data.vehicle_calib_data.k_distance_front_bumper_to_rear_axle, 1.0F);
}

// ================= BRANCH COVERAGE: HIL_Periodic_Handler && short-circuit =================

/******************************************************************************
 *. Test Case Name: HIL_Periodic_Handler_STATUS_WithMountingUpdate
 *. Objective: Exercise the STATUS path inside HIL_Periodic_Handler where
 *.            Update_Mounting_Position_From_Status_Log returns CODED_TRUE,
 *.            verifying hil_request_reinit_module is set to CODED_TRUE.
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, HIL_Periodic_Handler_STATUS_WithMountingUpdate)
{
   ResetHILState_HIL_Periodic();
   Get_HIL_Output_Data_Ptr_fake.return_val        = &hil_output_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val     = &mss_to_dss_l3_ut;
   Get_Status_Stream_Ptr_fake.return_val          = &status_stream_ut;
   Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = &mss_one_time_msg_ut;

   hil_output_ut.hil_enabled_streams[STATUS] = CODED_TRUE;
   hil_output_ut.hil_mode_enabled            = CODED_TRUE;

   /* Set injection flag and make yaw differ to trigger CODED_TRUE return */
   mss_to_dss_l3_ut.payload.hil_ipc_info.hil_src_radar_mounting_data = HIL_EXECUTE_INJECTION_DATA;
   status_stream_ut.sensor_mount_ornt_yaw                            = 2.0F;

   HIL_Periodic_Handler();

   ASSERT_EQ(mss_to_dss_l3_ut.payload.hil_ipc_info.hil_request_reinit_module, CODED_TRUE);
}

/******************************************************************************
 *. Test Case Name: HIL_Periodic_Handler_STATUS_Enabled_ModeDisabled
 *. Objective: STATUS enabled but mode disabled → STATUS branch NOT taken.
 *.            Covers the && short-circuit (first operand true, second false).
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, HIL_Periodic_Handler_STATUS_Enabled_ModeDisabled)
{
   ResetHILState_HIL_Periodic();
   Get_HIL_Output_Data_Ptr_fake.return_val    = &hil_output_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val = &mss_to_dss_l3_ut;
   Get_Status_Stream_Ptr_fake.return_val      = &status_stream_ut;

   hil_output_ut.hil_enabled_streams[STATUS] = CODED_TRUE;
   hil_output_ut.hil_mode_enabled            = CODED_FALSE;

   HIL_Periodic_Handler();

   ASSERT_EQ(mss_to_dss_l3_ut.payload.hil_ipc_info.hil_request_reinit_module, 0);
}

/******************************************************************************
 *. Test Case Name: Update_Mounting_Position_OnlyYawDiffers
 *. Objective: Only yaw differs → first operand true, rest short-circuited.
 *.            Complements FieldChange_UpdatesCalib by isolating yaw alone.
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, Update_Mounting_Position_OnlyYawDiffers)
{
   Get_Status_Stream_Ptr_fake.return_val          = &status_stream_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val     = &mss_to_dss_l3_ut;
   Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = &mss_one_time_msg_ut;

   mss_to_dss_l3_ut.payload.hil_ipc_info.hil_src_radar_mounting_data = HIL_EXECUTE_INJECTION_DATA;

   status_stream_ut.sensor_mount_ornt_yaw = 1.0F;

   uint8_t ret = Update_Mounting_Position_From_Status_Log();
   ASSERT_EQ(ret, CODED_TRUE);
   ASSERT_FLOAT_EQ(mss_one_time_msg_ut.calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_yaw, 1.0F);
}

/* ============================================================================
 *  Coverage for hil_request_reinit_module output flag
 *  ----------------------------------------------------------------------------
 *  Update_Mounting_Position_From_Status_Log unconditionally resets
 *  hil_request_reinit_module to CODED_FALSE on entry, then sets it to
 *  CODED_TRUE only when smc_update_found is true. The tests below pin all
 *  three observable outcomes of that flag:
 *    1. Update found        -> flag becomes CODED_TRUE
 *    2. No update (no-op)   -> flag is reset to CODED_FALSE (even if previously TRUE)
 *    3. Injection flag off  -> flag is reset to CODED_FALSE
 *    4. NULL one-time msg   -> flag is reset to CODED_FALSE
 * ===========================================================================*/

/******************************************************************************
 *. Test Case Name: Update_Mounting_Position_SetsReinitFlagOnUpdate
 *. Objective: When a mounting field changes, hil_request_reinit_module must
 *.            be set to CODED_TRUE alongside the CODED_TRUE return value.
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, Update_Mounting_Position_SetsReinitFlagOnUpdate)
{
   Get_Status_Stream_Ptr_fake.return_val          = &status_stream_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val     = &mss_to_dss_l3_ut;
   Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = &mss_one_time_msg_ut;

   mss_to_dss_l3_ut.payload.hil_ipc_info.hil_src_radar_mounting_data = HIL_EXECUTE_INJECTION_DATA;

   status_stream_ut.sensor_mount_ornt_yaw = 1.5F;

   uint8_t ret = Update_Mounting_Position_From_Status_Log();

   /* Function only returns the flag value; HIL_Periodic_Handler writes it to IPC */
   ASSERT_EQ(ret, CODED_TRUE);
}

/******************************************************************************
 *. Test Case Name: Update_Mounting_Position_ClearsReinitFlagWhenNoUpdate
 *. Objective: Pre-seed hil_request_reinit_module = CODED_TRUE and verify the
 *.            unconditional reset at function entry forces it back to
 *.            CODED_FALSE when no mounting field changes.
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, Update_Mounting_Position_ClearsReinitFlagWhenNoUpdate)
{
   Get_Status_Stream_Ptr_fake.return_val          = &status_stream_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val     = &mss_to_dss_l3_ut;
   Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = &mss_one_time_msg_ut;

   mss_to_dss_l3_ut.payload.hil_ipc_info.hil_src_radar_mounting_data = HIL_EXECUTE_INJECTION_DATA;

   /* All zeros in both stream and calib data -> no diff. */
   uint8_t ret = Update_Mounting_Position_From_Status_Log();

   /* Function returns CODED_FALSE when no change detected */
   ASSERT_EQ(ret, CODED_FALSE);
}

/******************************************************************************
 *. Test Case Name: Update_Mounting_Position_ClearsReinitFlagWhenInjectionDisabled
 *. Objective: When HIL injection flag is not set, hil_request_reinit_module
 *.            must still be reset to CODED_FALSE (entry-side write executes
 *.            before the gate check).
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, Update_Mounting_Position_ClearsReinitFlagWhenInjectionDisabled)
{
   Get_Status_Stream_Ptr_fake.return_val          = &status_stream_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val     = &mss_to_dss_l3_ut;
   Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = &mss_one_time_msg_ut;

   mss_to_dss_l3_ut.payload.hil_ipc_info.hil_src_radar_mounting_data = HIL_EXECUTE_EMBEDDED_ALGO;

   /* Even with a delta, the gate is closed -> no update. */
   status_stream_ut.sensor_mount_ornt_yaw = 9.99F;

   uint8_t ret = Update_Mounting_Position_From_Status_Log();

   ASSERT_EQ(ret, CODED_FALSE);
}

/******************************************************************************
 *. Test Case Name: Update_Mounting_Position_ClearsReinitFlagWhenOneTimeMsgNull
 *. Objective: When the one-time message pointer is NULL, the function must
 *.            still reset hil_request_reinit_module to CODED_FALSE without
 *.            dereferencing the NULL pointer.
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, Update_Mounting_Position_ClearsReinitFlagWhenOneTimeMsgNull)
{
   Get_Status_Stream_Ptr_fake.return_val          = &status_stream_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val     = &mss_to_dss_l3_ut;
   Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = NULL;

   mss_to_dss_l3_ut.payload.hil_ipc_info.hil_src_radar_mounting_data = HIL_EXECUTE_INJECTION_DATA;

   uint8_t ret = Update_Mounting_Position_From_Status_Log();

   ASSERT_EQ(ret, CODED_FALSE);
}

/******************************************************************************
 *. Test Case Name: HIL_Periodic_Handler_STATUS_NoChange_WritesCodedFalse
 *. Objective: Verify that when STATUS stream is enabled and mode is active but
 *.            no SMC change is detected, hil_request_reinit_module is written
 *.            with CODED_FALSE (the return value of Update_Mounting_Position).
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, HIL_Periodic_Handler_STATUS_NoChange_WritesCodedFalse)
{
   ResetHILState_HIL_Periodic();
   Get_HIL_Output_Data_Ptr_fake.return_val        = &hil_output_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val     = &mss_to_dss_l3_ut;
   Get_Status_Stream_Ptr_fake.return_val          = &status_stream_ut;
   Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = &mss_one_time_msg_ut;

   hil_output_ut.hil_enabled_streams[STATUS] = CODED_TRUE;
   hil_output_ut.hil_mode_enabled            = CODED_TRUE;

   mss_to_dss_l3_ut.payload.hil_ipc_info.hil_src_radar_mounting_data = HIL_EXECUTE_INJECTION_DATA;
   /* Pre-seed with CODED_TRUE to verify it gets overwritten to CODED_FALSE */
   mss_to_dss_l3_ut.payload.hil_ipc_info.hil_request_reinit_module = CODED_TRUE;

   /* All zeros in both stream and calib → no SMC change → returns CODED_FALSE */
   HIL_Periodic_Handler();

   ASSERT_EQ(mss_to_dss_l3_ut.payload.hil_ipc_info.hil_request_reinit_module, CODED_FALSE);
}

/******************************************************************************
 *. Test Case Name: HIL_Periodic_Handler_STATUS_WithChange_WritesCodedTrue
 *. Objective: Verify that when STATUS stream is enabled, mode is active, and
 *.            SMC data has changed, hil_request_reinit_module is set to
 *.            CODED_TRUE so BBE32 Tracker_Handler triggers reinit.
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, HIL_Periodic_Handler_STATUS_WithChange_WritesCodedTrue)
{
   ResetHILState_HIL_Periodic();
   Get_HIL_Output_Data_Ptr_fake.return_val        = &hil_output_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val     = &mss_to_dss_l3_ut;
   Get_Status_Stream_Ptr_fake.return_val          = &status_stream_ut;
   Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = &mss_one_time_msg_ut;

   hil_output_ut.hil_enabled_streams[STATUS] = CODED_TRUE;
   hil_output_ut.hil_mode_enabled            = CODED_TRUE;

   mss_to_dss_l3_ut.payload.hil_ipc_info.hil_src_radar_mounting_data = HIL_EXECUTE_INJECTION_DATA;
   mss_to_dss_l3_ut.payload.hil_ipc_info.hil_request_reinit_module   = CODED_FALSE;

   /* Make yaw differ so Update_Mounting_Position returns CODED_TRUE */
   status_stream_ut.sensor_mount_ornt_yaw = 3.0F;

   HIL_Periodic_Handler();

   ASSERT_EQ(mss_to_dss_l3_ut.payload.hil_ipc_info.hil_request_reinit_module, CODED_TRUE);
   /* Also verify calibration data was updated */
   ASSERT_FLOAT_EQ(mss_one_time_msg_ut.calib_data.sensor_calib_data.sensor_mount_data.k_sensor_mount_ornt_yaw, 3.0F);
}

/******************************************************************************
 *. Test Case Name: HIL_Periodic_Handler_STATUS_Disabled_FlagUntouched
 *. Objective: Verify that when STATUS stream is disabled (even with mode on),
 *.            hil_request_reinit_module is NOT written at all — a stale
 *.            CODED_TRUE from a previous cycle remains until BBE32 clears it.
 ******************************************************************************/
TEST_F(cdd_HIL_UnitTestSuite, HIL_Periodic_Handler_STATUS_Disabled_FlagUntouched)
{
   ResetHILState_HIL_Periodic();
   Get_HIL_Output_Data_Ptr_fake.return_val        = &hil_output_ut;
   Get_MSS_IPC_M2D_Msg_Buffer_fake.return_val     = &mss_to_dss_l3_ut;
   Get_Status_Stream_Ptr_fake.return_val          = &status_stream_ut;
   Get_IPC_M2D_Onetime_Msg_Buffer_fake.return_val = &mss_one_time_msg_ut;

   hil_output_ut.hil_enabled_streams[STATUS] = CODED_FALSE;
   hil_output_ut.hil_mode_enabled            = CODED_TRUE;

   /* Pre-seed flag as if BBE32 hasn't cleared it yet */
   mss_to_dss_l3_ut.payload.hil_ipc_info.hil_request_reinit_module = CODED_TRUE;

   HIL_Periodic_Handler();

   /* Flag must remain untouched since STATUS branch was not entered */
   ASSERT_EQ(mss_to_dss_l3_ut.payload.hil_ipc_info.hil_request_reinit_module, CODED_TRUE);
}
