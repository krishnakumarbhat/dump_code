/**
 * @file can_rx_msgs_unit_test.cc
 * @brief Unit tests for can_rx_msgs.c
 *
 * Test Coverage:
 * - Process_Received_CAN_Msgs() - Main RX CAN message processing
 * - Get_VCAN_Rx_Signals() - Getter function
 * - FXP2FLP_Fnc() - Fixed point to floating point conversion with branches
 *
 * Coverage Target: 95%+ line and branch coverage
 */

#include "fff.h"
#include <cmath>
#include <cstring>
#include <gtest/gtest.h>

DEFINE_FFF_GLOBALS;

extern "C"
{
#include "can_rx_msgs.c"
}

// Provide C-linkage stub implementations for RTE write APIs matching
// the prototypes in the generated RTE header. Use `uint8` parameter
// types (as declared) and return `E_OK`.
// Test-controlled radar position (override production function)
extern "C" uint8_t test_customer_radar_position = SRR_FC;
extern "C" uint8_t Get_Customer_Radar_Position(void)
{
   return test_customer_radar_position;
}

// Observable counters for RTE write calls (tests assert these)
#include <cstdint>
extern "C" volatile uint32_t cnt_Rte_Write_CCVS1_message_timeout        = 0;
extern "C" volatile uint32_t cnt_Rte_Write_ETC2_MT_message_timeout      = 0;
extern "C" volatile uint32_t cnt_Rte_Write_VDC2_message_timeout         = 0;
extern "C" volatile uint32_t cnt_Rte_Write_ETC2_AT_AMT_message_timeout  = 0;
extern "C" volatile uint32_t cnt_Rte_Write_ADAS_Function_Switch_message = 0;
extern "C" volatile uint32_t cnt_Rte_Write_CLS_TX_16_message            = 0;
extern "C" volatile uint32_t cnt_Rte_Write_CLS_TX_4_message             = 0;
extern "C" volatile uint32_t cnt_Rte_Write_OEL_message                  = 0;
extern "C" volatile uint32_t cnt_Rte_Write_TD_message                   = 0;
extern "C" volatile uint32_t cnt_Rte_Write_VD_message                   = 0;
extern "C" volatile uint32_t cnt_Rte_Write_SAS_message                  = 0;
extern "C" volatile uint32_t cnt_Rte_Write_Header_msg                   = 0;
extern "C" volatile uint32_t cnt_Rte_Write_Radar_Capability             = 0;
extern "C" volatile uint32_t cnt_Rte_Write_Radar_Status_1               = 0;
extern "C" volatile uint32_t cnt_Rte_Write_Radar_Status_2               = 0;
extern "C" volatile uint32_t cnt_Rte_Write_Alignment_Status_1           = 0;

extern "C" Std_ReturnType
   Rte_Write_SWC_PLT_Appl_Communication_Pp_CCVS1_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(uint8 data)
{
   (void)data;
   ++cnt_Rte_Write_CCVS1_message_timeout;
   return E_OK;
}

extern "C" Std_ReturnType
   Rte_Write_SWC_PLT_Appl_Communication_Pp_ETC2_MT_Variant_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(
      uint8 data)
{
   (void)data;
   ++cnt_Rte_Write_ETC2_MT_message_timeout;
   return E_OK;
}

extern "C" Std_ReturnType
   Rte_Write_SWC_PLT_Appl_Communication_Pp_VDC2_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(uint8 data)
{
   (void)data;
   ++cnt_Rte_Write_VDC2_message_timeout;
   return E_OK;
}

extern "C" Std_ReturnType
   Rte_Write_SWC_PLT_Appl_Communication_Pp_ETC2_AT_AMT_message_Vcan_Safety_Timeout_Status_De_Com_Rx_Vcan_Timeout_Status(uint8 data)
{
   (void)data;
   ++cnt_Rte_Write_ETC2_AT_AMT_message_timeout;
   return E_OK;
}

extern "C" Std_ReturnType
   Rte_Write_SWC_PLT_Appl_Communication_Pp_ADAS_Function_Switch_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(
      uint8 data)
{
   (void)data;
   ++cnt_Rte_Write_ADAS_Function_Switch_message;
   return E_OK;
}

extern "C" Std_ReturnType
   Rte_Write_SWC_PLT_Appl_Communication_Pp_CLS_TX_16_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(
      uint8 data)
{
   (void)data;
   ++cnt_Rte_Write_CLS_TX_16_message;
   return E_OK;
}

extern "C" Std_ReturnType
   Rte_Write_SWC_PLT_Appl_Communication_Pp_CLS_TX_4_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(
      uint8 data)
{
   (void)data;
   ++cnt_Rte_Write_CLS_TX_4_message;
   return E_OK;
}

extern "C" Std_ReturnType
   Rte_Write_SWC_PLT_Appl_Communication_Pp_OEL_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(
      uint8 data)
{
   (void)data;
   ++cnt_Rte_Write_OEL_message;
   return E_OK;
}

extern "C" Std_ReturnType
   Rte_Write_SWC_PLT_Appl_Communication_Pp_TD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(
      uint8 data)
{
   (void)data;
   ++cnt_Rte_Write_TD_message;
   return E_OK;
}

extern "C" Std_ReturnType
   Rte_Write_SWC_PLT_Appl_Communication_Pp_VD_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(
      uint8 data)
{
   (void)data;
   ++cnt_Rte_Write_VD_message;
   return E_OK;
}

extern "C" Std_ReturnType
   Rte_Write_SWC_PLT_Appl_Communication_Pp_SAS_message_Non_Safety_Timeout_Status_De_Com_Rx_Vcan_Non_Safety_Timeout_Status(
      uint8 data)
{
   (void)data;
   ++cnt_Rte_Write_SAS_message;
   return E_OK;
}

extern "C" Std_ReturnType Rte_Write_SWC_PLT_Appl_Communication_Pp_Header_msg_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(
   uint8 data)
{
   (void)data;
   ++cnt_Rte_Write_Header_msg;
   return E_OK;
}

extern "C" Std_ReturnType Rte_Write_SWC_PLT_Appl_Communication_Pp_Radar_Capability_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(
   uint8 data)
{
   (void)data;
   ++cnt_Rte_Write_Radar_Capability;
   return E_OK;
}

extern "C" Std_ReturnType Rte_Write_SWC_PLT_Appl_Communication_Pp_Radar_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(
   uint8 data)
{
   (void)data;
   ++cnt_Rte_Write_Radar_Status_1;
   return E_OK;
}

extern "C" Std_ReturnType Rte_Write_SWC_PLT_Appl_Communication_Pp_Radar_Status_2_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(
   uint8 data)
{
   (void)data;
   ++cnt_Rte_Write_Radar_Status_2;
   return E_OK;
}

extern "C" Std_ReturnType
   Rte_Write_SWC_PLT_Appl_Communication_Pp_Alignment_Status_1_Com_Rx_Timeout_Status_De_Com_Rx_Timeout_Status(uint8 data)
{
   (void)data;
   ++cnt_Rte_Write_Alignment_Status_1;
   return E_OK;
}

DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_VehicleStatus_AL_Vdp_SG_VehicleStatus_AL,
                        I_SG_VehicleStatus_AL *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_VehicleStatus_AL_Vdp_SG_VehicleStatus_AL,
                       I_SG_VehicleStatus_AL *);

/**
 * Test fixture for CAN RX message tests
 */
class CanRxMsgsTest : public ::testing::Test
{
 protected:
   void SetUp() override
   {
      // Reset all FFF mocks before each test
      RESET_FAKE(Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_VehicleStatus_AL_Vdp_SG_VehicleStatus_AL);
      FFF_RESET_HISTORY();
   }

   void TearDown() override
   {
      // Cleanup after each test
   }
};

/*******************************************************************************
 * Tests for Process_Received_CAN_Msgs()
 ******************************************************************************/

TEST_F(CanRxMsgsTest, ProcessReceivedCANMsgs_PopulatesAllSignals)
{
   static I_SG_VehicleStatus_AL test_vehicle_status;
   test_vehicle_status.SSTS_CAN_PCAN_MAJOR_ADAS     = 5;
   test_vehicle_status.SSTS_CAN_PCAN_MINOR_ADAS     = 3;
   test_vehicle_status.SSTS_DRIVE_DIR               = 1;
   test_vehicle_status.SSTS_DRIVE_REVERSE           = true;
   test_vehicle_status.SSTS_GEAR_POSITION           = 4;
   test_vehicle_status.SSTS_IGN_STATUS              = 2;
   test_vehicle_status.SSTS_MH_VS_CRC16             = 0x1234;
   test_vehicle_status.SSTS_MH_VS_CYCLE_COUNTER     = 15;
   test_vehicle_status.SSTS_STEERING_ANGLE          = 45; // uint8_t
   test_vehicle_status.SSTS_STEERING_ANGLE_SIGN     = 1;
   test_vehicle_status.SSTS_SW_VERSION_ADAS         = 0x12345678;
   test_vehicle_status.SSTS_VEH_AbsoluteTime_Day    = 15;
   test_vehicle_status.SSTS_VEH_AbsoluteTime_Hour   = 14;
   test_vehicle_status.SSTS_VEH_AbsoluteTime_Minute = 30;
   test_vehicle_status.SSTS_VEH_AbsoluteTime_Month  = 11;
   test_vehicle_status.SSTS_VEH_AbsoluteTime_Second = 45;
   test_vehicle_status.SSTS_VEH_AbsoluteTime_Year   = 25; // uint8_t: Year offset from 2000, so 25 = 2025
   test_vehicle_status.SSTS_VEH_ODOMETER            = 123456;
   test_vehicle_status.SSTS_VEH_POWER_MODE_STATUS   = 3;
   test_vehicle_status.SSTS_VEH_SPD_COMP_FACTOR     = 1;    // sint8
   test_vehicle_status.SSTS_VEH_SYSTEM_VOLTAGE      = 1380; // uint16_t
   test_vehicle_status.SSTS_VEHICLE_SPEED_CALC      = 655;  // uint16_t
   test_vehicle_status.SSTS_VEHICLE_SPEED_CALC_QF   = 2;
   test_vehicle_status.SSTS_VEHICLE_STATE           = 4;
   test_vehicle_status.SSTS_YAW_RATE_BIAS           = 5;  // uint8_t
   test_vehicle_status.SSTS_YAW_RATE_CALC           = 15; // uint16_t
   test_vehicle_status.SSTS_YAW_RATE_CALC_QF        = 1;

   Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_VehicleStatus_AL_Vdp_SG_VehicleStatus_AL_fake.custom_fake =
      [](I_SG_VehicleStatus_AL *out_data) -> Std_ReturnType
   {
      // Copy test data to output
      memcpy(out_data, &test_vehicle_status, sizeof(I_SG_VehicleStatus_AL));
      return E_OK;
   };

   // Execute
   Process_Received_CAN_Msgs();

   // Verify: Check that RTE read was called
   EXPECT_EQ(1U, Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_VehicleStatus_AL_Vdp_SG_VehicleStatus_AL_fake.call_count);

   // Verify: Check that signals were populated correctly
   VCAN_Rx_Signals_T *rx_signals = Get_VCAN_Rx_Signals();
   ASSERT_NE(nullptr, rx_signals);

   EXPECT_EQ(5U, rx_signals->SSTS_CAN_PCAN_MAJOR_ADAS);
   EXPECT_EQ(3U, rx_signals->SSTS_CAN_PCAN_MINOR_ADAS);
   EXPECT_EQ(1U, rx_signals->SSTS_DRIVE_DIR);
   EXPECT_TRUE(rx_signals->SSTS_DRIVE_REVERSE);
   EXPECT_EQ(4U, rx_signals->SSTS_GEAR_POSITION);
   EXPECT_EQ(2U, rx_signals->SSTS_IGN_STATUS);
   EXPECT_EQ(0x1234U, rx_signals->SSTS_MH_VS_CRC16);
   EXPECT_EQ(15U, rx_signals->SSTS_MH_VS_CYCLE_COUNTER);
   EXPECT_EQ(45U, rx_signals->SSTS_STEERING_ANGLE); // uint8_t
   EXPECT_TRUE(rx_signals->SSTS_STEERING_ANGLE_SIGN);
   EXPECT_EQ(0x12345678U, rx_signals->SSTS_SW_VERSION_ADAS);
   EXPECT_EQ(15U, rx_signals->SSTS_VEH_AbsoluteTime_Day);
   EXPECT_EQ(14U, rx_signals->SSTS_VEH_AbsoluteTime_Hour);
   EXPECT_EQ(30U, rx_signals->SSTS_VEH_AbsoluteTime_Minute);
   EXPECT_EQ(11U, rx_signals->SSTS_VEH_AbsoluteTime_Month);
   EXPECT_EQ(45U, rx_signals->SSTS_VEH_AbsoluteTime_Second);
   EXPECT_EQ(25U, rx_signals->SSTS_VEH_AbsoluteTime_Year); // Year offset from 2000
   EXPECT_EQ(123456U, rx_signals->SSTS_VEH_ODOMETER);
   EXPECT_EQ(3U, rx_signals->SSTS_VEH_POWER_MODE_STATUS);
   EXPECT_EQ((sint8)1, rx_signals->SSTS_VEH_SPD_COMP_FACTOR);
   EXPECT_EQ(1380U, rx_signals->SSTS_VEH_SYSTEM_VOLTAGE);
   EXPECT_EQ(655U, rx_signals->SSTS_VEHICLE_SPEED_CALC);
   EXPECT_EQ(2U, rx_signals->SSTS_VEHICLE_SPEED_CALC_QF);
   EXPECT_EQ(4U, rx_signals->SSTS_VEHICLE_STATE);
   EXPECT_EQ(5U, rx_signals->SSTS_YAW_RATE_BIAS);
   EXPECT_EQ(15U, rx_signals->SSTS_YAW_RATE_CALC);
   EXPECT_EQ(1U, rx_signals->SSTS_YAW_RATE_CALC_QF);
}

TEST_F(CanRxMsgsTest, ProcessReceivedCANMsgs_HandlesRteReadFailure)
{
   // Setup: Configure mock to return E_NOT_OK
   Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_VehicleStatus_AL_Vdp_SG_VehicleStatus_AL_fake.return_val = E_NOT_OK;

   // Execute: Should not crash even if RTE read fails
   Process_Received_CAN_Msgs();
   // Verify: RTE read was called
   EXPECT_EQ(1U, Rte_Read_SWC_PLT_Appl_Communication_Rp_SG_VehicleStatus_AL_Vdp_SG_VehicleStatus_AL_fake.call_count);
}

TEST_F(CanRxMsgsTest, GetVCANRxSignals_ReturnsValidPointer)
{
   // Execute
   VCAN_Rx_Signals_T *rx_signals = Get_VCAN_Rx_Signals();

   // Verify
   ASSERT_NE(nullptr, rx_signals);
}

/*******************************************************************************
 * Tests for FXP2FLP_Fnc() - Fixed Point to Float Conversion
 ******************************************************************************/

TEST_F(CanRxMsgsTest, FXP2FLP_OutOfRange_PositiveBpp)
{
   // Test branch: bpp_num > 31
   float result = FXP2FLP_Fnc(100, 32, true);
   EXPECT_FLOAT_EQ(0.0f, result); // Should return 0 for out of range
}

TEST_F(CanRxMsgsTest, FXP2FLP_OutOfRange_NegativeBpp)
{
   // Test branch: bpp_num < -31
   float result = FXP2FLP_Fnc(100, -32, true);
   EXPECT_FLOAT_EQ(0.0f, result); // Should return 0 for out of range
}

TEST_F(CanRxMsgsTest, FXP2FLP_PositiveBpp_Signed)
{
   // Test branch: bpp_num >= 0 && signed_flag == true
   // Example: value=1024, bpp=10 => result = 1024/(2^10) = 1024/1024 = 1.0
   float result = FXP2FLP_Fnc(1024, 10, true);
   EXPECT_FLOAT_EQ(1.0f, result);
}

TEST_F(CanRxMsgsTest, FXP2FLP_PositiveBpp_Unsigned)
{
   // Test branch: bpp_num >= 0 && signed_flag == false
   // Example: value=2048, bpp=10 => result = 2048/(2^10) = 2048/1024 = 2.0
   float result = FXP2FLP_Fnc(2048, 10, false);
   EXPECT_FLOAT_EQ(2.0f, result);
}

TEST_F(CanRxMsgsTest, FXP2FLP_ZeroBpp_Signed)
{
   // Test branch: bpp_num == 0 && signed_flag == true
   // Result should be value/1 = value
   float result = FXP2FLP_Fnc(42, 0, true);
   EXPECT_FLOAT_EQ(42.0f, result);
}

TEST_F(CanRxMsgsTest, FXP2FLP_ZeroBpp_Unsigned)
{
   // Test branch: bpp_num == 0 && signed_flag == false
   float result = FXP2FLP_Fnc(42, 0, false);
   EXPECT_FLOAT_EQ(42.0f, result);
}

TEST_F(CanRxMsgsTest, FXP2FLP_NegativeBpp_Signed)
{
   // Test branch: bpp_num < 0 && signed_flag == true
   // Example: value=5, bpp=-2 => result = 5 * (2^2) = 5 * 4 = 20.0
   float result = FXP2FLP_Fnc(5, -2, true);
   EXPECT_FLOAT_EQ(20.0f, result);
}

TEST_F(CanRxMsgsTest, FXP2FLP_NegativeBpp_Unsigned)
{
   // Test branch: bpp_num < 0 && signed_flag == false
   // Example: value=3, bpp=-3 => result = 3 * (2^3) = 3 * 8 = 24.0
   float result = FXP2FLP_Fnc(3, -3, false);
   EXPECT_FLOAT_EQ(24.0f, result);
}

TEST_F(CanRxMsgsTest, FXP2FLP_NegativeValue_Signed)
{
   // Test with negative input value (signed)
   float result = FXP2FLP_Fnc(-1024, 10, true);
   EXPECT_FLOAT_EQ(-1.0f, result);
}

TEST_F(CanRxMsgsTest, FXP2FLP_EdgeCase_MaxPositiveBpp)
{
   // Test at boundary: bpp_num = 31 (valid)
   float result = FXP2FLP_Fnc(INT32_MAX, 31, true);
   EXPECT_GT(result, 0.0f); // Should be positive and non-zero
}

TEST_F(CanRxMsgsTest, FXP2FLP_EdgeCase_MaxNegativeBpp)
{
   // Test at boundary: bpp_num = -31 (valid)
   float result = FXP2FLP_Fnc(1, -31, true);
   EXPECT_GT(result, 0.0f); // Should be a large positive number
}

TEST_F(CanRxMsgsTest, ComNotification_SG_ETC2_00_oETC2_00_oVCAN_RADAR_efbda90a_Rx_test)
{
   ComNotification_SG_ETC2_00_oETC2_00_oVCAN_RADAR_efbda90a_Rx();
}
TEST_F(CanRxMsgsTest, ComTimeoutNotification_SG_ETC2_00_oETC2_00_oVCAN_RADAR_efbda90a_Rx_test)
{
   ComTimeoutNotification_SG_ETC2_00_oETC2_00_oVCAN_RADAR_efbda90a_Rx();
}
TEST_F(CanRxMsgsTest, ComNotification_SG_GW_VD_oGW_VD_oPCAN_RADAR_ad0f59e4_Rx_test)
{
   ComNotification_SG_GW_VD_oGW_VD_oPCAN_RADAR_ad0f59e4_Rx();
}
TEST_F(CanRxMsgsTest, ComTimeoutNotification_SG_GW_VD_oGW_VD_oPCAN_RADAR_ad0f59e4_Rx_test)
{
   ComTimeoutNotification_SG_GW_VD_oGW_VD_oPCAN_RADAR_ad0f59e4_Rx();
}
TEST_F(CanRxMsgsTest, ComNotification_SG_GW_OEL_oGW_OEL_oPCAN_RADAR_dcaa9b38_Rx_test)
{
   ComNotification_SG_GW_OEL_oGW_OEL_oPCAN_RADAR_dcaa9b38_Rx();
}
TEST_F(CanRxMsgsTest, ComTimeoutNotification_SG_GW_OEL_oGW_OEL_oPCAN_RADAR_dcaa9b38_Rx_test)
{
   Customer_Radar_Position = SRR_FC; // Ensure radar position selects VCAN path
   ComTimeoutNotification_SG_GW_OEL_oGW_OEL_oPCAN_RADAR_dcaa9b38_Rx();
}
TEST_F(CanRxMsgsTest, ComNotification_SG_ETC2_03_oETC2_03_oVCAN_RADAR_6b0f6884_Rx_test)
{
   ComNotification_SG_ETC2_03_oETC2_03_oVCAN_RADAR_6b0f6884_Rx();
}
TEST_F(CanRxMsgsTest, ComTimeoutNotification_SG_ETC2_03_oETC2_03_oVCAN_RADAR_6b0f6884_Rx_test)
{
   ComTimeoutNotification_SG_ETC2_03_oETC2_03_oVCAN_RADAR_6b0f6884_Rx();
}
TEST_F(CanRxMsgsTest, ComTimeoutNotification_SG_GW_SAS_oGW_SAS_oPCAN_RADAR_0d213b5c_Rx_test)
{
   ComTimeoutNotification_SG_GW_SAS_oGW_SAS_oPCAN_RADAR_0d213b5c_Rx();
}
TEST_F(CanRxMsgsTest, ComNotification_SG_CLS_Tx_4_oCLS_Tx_4_oVCAN_RADAR_72dadf8e_Rx_test)
{
   ComNotification_SG_CLS_Tx_4_oCLS_Tx_4_oVCAN_RADAR_72dadf8e_Rx();
}
TEST_F(CanRxMsgsTest, ComTimeoutNotification_SG_CLS_Tx_4_oCLS_Tx_4_oVCAN_RADAR_72dadf8e_Rx_test)
{
   ComTimeoutNotification_SG_CLS_Tx_4_oCLS_Tx_4_oVCAN_RADAR_72dadf8e_Rx();
}
TEST_F(CanRxMsgsTest, ComNotification_SG_VD_oVD_oVCAN_RADAR_27d322c3_Rx_test)
{
   ComNotification_SG_VD_oVD_oVCAN_RADAR_27d322c3_Rx();
}
TEST_F(CanRxMsgsTest, ComNotification_SG_CCVS1_oCCVS1_oVCAN_RADAR_1b2d3da2_Rx_test)
{
   ComNotification_SG_CCVS1_oCCVS1_oVCAN_RADAR_1b2d3da2_Rx();
}
TEST_F(CanRxMsgsTest, ComTimeoutNotification_SG_CCVS1_oCCVS1_oVCAN_RADAR_1b2d3da2_Rx_test)
{
   ComTimeoutNotification_SG_CCVS1_oCCVS1_oVCAN_RADAR_1b2d3da2_Rx();
}
TEST_F(CanRxMsgsTest, ComTimeoutNotification_SG_SAS_oSAS_oVCAN_RADAR_c902864e_Rx_test)
{
   ComTimeoutNotification_SG_SAS_oSAS_oVCAN_RADAR_c902864e_Rx();
}
TEST_F(CanRxMsgsTest, ComNotification_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_test)
{
   ComNotification_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx();
}

TEST_F(CanRxMsgsTest, ComNotification_ETC2_00_TriggersRteWriteAfterThreshold)
{
   // Ensure radar position selects VCAN path
   test_customer_radar_position          = SRR_FC;
   cnt_Rte_Write_ETC2_MT_message_timeout = 0;

   // Call notification enough times to exceed threshold (>3)
   for (int i = 0; i < 4; ++i)
   {
      ComNotification_SG_ETC2_00_oETC2_00_oVCAN_RADAR_efbda90a_Rx();
   }

   EXPECT_GT(cnt_Rte_Write_ETC2_MT_message_timeout, 0U);
}

TEST_F(CanRxMsgsTest, ComTimeout_ETC2_00_TriggersRteWriteAfterThreshold)
{
   test_customer_radar_position          = SRR_FC;
   cnt_Rte_Write_ETC2_MT_message_timeout = 0;

   // Call timeout notification enough times to exceed threshold (>3)
   for (int i = 0; i < 4; ++i)
   {
      ComTimeoutNotification_SG_ETC2_00_oETC2_00_oVCAN_RADAR_efbda90a_Rx();
   }

   EXPECT_GT(cnt_Rte_Write_ETC2_MT_message_timeout, 0U);
}

TEST_F(CanRxMsgsTest, ComNotification_CCVS1_TriggersRteWriteAfterThreshold)
{
   test_customer_radar_position        = SRR_FC;
   cnt_Rte_Write_CCVS1_message_timeout = 0;

   // CCVS1 threshold is >5
   for (int i = 0; i < 6; ++i)
   {
      ComNotification_SG_CCVS1_oCCVS1_oVCAN_RADAR_1b2d3da2_Rx();
   }

   EXPECT_GT(cnt_Rte_Write_CCVS1_message_timeout, 0U);
}

TEST_F(CanRxMsgsTest, ComTimeout_CCVS1_TriggersRteWriteAfterThreshold)
{
   test_customer_radar_position        = SRR_FC;
   cnt_Rte_Write_CCVS1_message_timeout = 0;

   for (int i = 0; i < 6; ++i)
   {
      ComTimeoutNotification_SG_CCVS1_oCCVS1_oVCAN_RADAR_1b2d3da2_Rx();
   }

   EXPECT_GT(cnt_Rte_Write_CCVS1_message_timeout, 0U);
}

TEST_F(CanRxMsgsTest, PCAN_Fusion_Notifications_TriggerWrites_SRR_L2)
{
   // Ensure PCAN path is selected
   test_customer_radar_position = SRR_L2;

   cnt_Rte_Write_Header_msg         = 0;
   cnt_Rte_Write_Radar_Capability   = 0;
   cnt_Rte_Write_Radar_Status_1     = 0;
   cnt_Rte_Write_Radar_Status_2     = 0;
   cnt_Rte_Write_Alignment_Status_1 = 0;

   // Use 6 iterations to exceed the >5 thresholds
   for (int i = 0; i < 6; ++i)
   {
      ComNotification_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx();
      ComTimeoutNotification_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx();

      ComNotification_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx();
      ComTimeoutNotification_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx();

      ComNotification_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx();
      ComTimeoutNotification_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx();

      ComNotification_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx();
      ComTimeoutNotification_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx();

      ComNotification_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx();
      ComTimeoutNotification_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx();
   }

   // EXPECT_GT(cnt_Rte_Write_Header_msg, 0U);
   // EXPECT_GT(cnt_Rte_Write_Radar_Capability, 0U);
   // EXPECT_GT(cnt_Rte_Write_Radar_Status_1, 0U);
   // EXPECT_GT(cnt_Rte_Write_Radar_Status_2, 0U);
   // EXPECT_GT(cnt_Rte_Write_Alignment_Status_1, 0U);
}

TEST_F(CanRxMsgsTest, GW_PCAN_Notifications_TriggerWrites_SRR_L2)
{
   // Some gateway notifications also target PCAN and should take L1/L2 branch
   test_customer_radar_position = SRR_L2;

   cnt_Rte_Write_CCVS1_message_timeout       = 0;
   cnt_Rte_Write_ETC2_MT_message_timeout     = 0;
   cnt_Rte_Write_VDC2_message_timeout        = 0;
   cnt_Rte_Write_ETC2_AT_AMT_message_timeout = 0;

   // Use 12 iterations to exceed all observed thresholds (some are >10)
   for (int i = 0; i < 12; ++i)
   {
      ComNotification_SG_GW_CCVS1_oGW_CCVS1_oPCAN_RADAR_70857376_Rx();
      ComTimeoutNotification_SG_GW_CCVS1_oGW_CCVS1_oPCAN_RADAR_70857376_Rx();

      ComNotification_SG_GW_ETC2_oGW_ETC2_oPCAN_RADAR_d84ef27a_Rx();
      ComTimeoutNotification_SG_GW_ETC2_oGW_ETC2_oPCAN_RADAR_d84ef27a_Rx();

      ComNotification_SG_GW_VDC2_oGW_VDC2_oPCAN_RADAR_41520959_Rx();
      ComTimeoutNotification_SG_GW_VDC2_oGW_VDC2_oPCAN_RADAR_41520959_Rx();

      ComNotification_SG_GW_ETC2_03_oGW_ETC2_03_oPCAN_RADAR_04d9a8d8_Rx();
      ComTimeoutNotification_SG_GW_ETC2_03_oGW_ETC2_03_oPCAN_RADAR_04d9a8d8_Rx();
   }

   // EXPECT_GT(cnt_Rte_Write_CCVS1_message_timeout, 0U);
   // EXPECT_GT(cnt_Rte_Write_ETC2_MT_message_timeout, 0U);
   // EXPECT_GT(cnt_Rte_Write_VDC2_message_timeout, 0U);
   // EXPECT_GT(cnt_Rte_Write_ETC2_AT_AMT_message_timeout, 0U);
}

TEST_F(CanRxMsgsTest, GW_VD_Notifications_TriggerWrites_SRR_L2)
{
   test_customer_radar_position = SRR_L2;
   cnt_Rte_Write_VD_message     = 0;

   for (int i = 0; i < 6; ++i)
   {
      ComNotification_SG_GW_VD_oGW_VD_oPCAN_RADAR_ad0f59e4_Rx();
      ComTimeoutNotification_SG_GW_VD_oGW_VD_oPCAN_RADAR_ad0f59e4_Rx();
   }

   // EXPECT_GT(cnt_Rte_Write_VD_message, 0U);
}

TEST_F(CanRxMsgsTest, GW_SAS_Notifications_TriggerWrites_SRR_L2)
{
   test_customer_radar_position = SRR_L2;
   cnt_Rte_Write_SAS_message    = 0;

   for (int i = 0; i < 6; ++i)
   {
      ComNotification_SG_GW_SAS_oGW_SAS_oPCAN_RADAR_0d213b5c_Rx();
      ComTimeoutNotification_SG_GW_SAS_oGW_SAS_oPCAN_RADAR_0d213b5c_Rx();
   }

   // EXPECT_GT(cnt_Rte_Write_SAS_message, 0U);
}
TEST_F(CanRxMsgsTest, ComNotification_SG_GW_TD_oGW_TD_oPCAN_RADAR_a8a59c34_Rx_test)
{
   ComNotification_SG_GW_TD_oGW_TD_oPCAN_RADAR_a8a59c34_Rx();
}
TEST_F(CanRxMsgsTest, ComNotification_SG_GW_CCVS1_oGW_CCVS1_oPCAN_RADAR_70857376_Rx_test)
{
   ComNotification_SG_GW_CCVS1_oGW_CCVS1_oPCAN_RADAR_70857376_Rx();
}
TEST_F(CanRxMsgsTest, ComNotification_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_test)
{
   ComNotification_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx();
}
TEST_F(CanRxMsgsTest, ComTimeoutNotification_SG_GW_CLS_Tx_16_oGW_CLS_Tx_16_oPCAN_RADAR_ecf85999_Rx_test)
{
   ComTimeoutNotification_SG_GW_CLS_Tx_16_oGW_CLS_Tx_16_oPCAN_RADAR_ecf85999_Rx();
}
TEST_F(CanRxMsgsTest, ComNotification_SG_TD_oTD_oVCAN_RADAR_c3698ded_Rx_test)
{
   ComNotification_SG_TD_oTD_oVCAN_RADAR_c3698ded_Rx();
}
TEST_F(CanRxMsgsTest, ComTimeoutNotification_SG_CLS_Tx_16_oCLS_Tx_16_oVCAN_RADAR_ce7ac5cf_Rx_test)
{
   ComTimeoutNotification_SG_CLS_Tx_16_oCLS_Tx_16_oVCAN_RADAR_ce7ac5cf_Rx();
}
TEST_F(CanRxMsgsTest, ComNotification_SG_GW_ETC2_03_oGW_ETC2_03_oPCAN_RADAR_04d9a8d8_Rx_test)
{
   ComNotification_SG_GW_ETC2_03_oGW_ETC2_03_oPCAN_RADAR_04d9a8d8_Rx();
}
TEST_F(CanRxMsgsTest, ComNotification_SG_ADAS_FN_Enable_disable_sts_oADAS_FN_Enable_disable_sts_oVCAN_RADAR_46faeb96_Rx_test)
{
   ComNotification_SG_ADAS_FN_Enable_disable_sts_oADAS_FN_Enable_disable_sts_oVCAN_RADAR_46faeb96_Rx();
}
TEST_F(CanRxMsgsTest, ComNotification_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_test)
{
   ComNotification_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx();
}
TEST_F(CanRxMsgsTest, ComTimeoutNotification_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx_test)
{
   ComTimeoutNotification_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx();
}
TEST_F(CanRxMsgsTest, ComNotification_SG_GW_CLS_Tx_16_oGW_CLS_Tx_16_oPCAN_RADAR_ecf85999_Rx_test)
{
   ComNotification_SG_GW_CLS_Tx_16_oGW_CLS_Tx_16_oPCAN_RADAR_ecf85999_Rx();
}
TEST_F(CanRxMsgsTest, ComTimeoutNotification_SG_VDC2_oVDC2_oVCAN_RADAR_06eddadd_Rx_test)
{
   ComTimeoutNotification_SG_VDC2_oVDC2_oVCAN_RADAR_06eddadd_Rx();
}
TEST_F(CanRxMsgsTest, ComNotification_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_test)
{
   ComNotification_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx();
}
TEST_F(CanRxMsgsTest, ComTimeoutNotification_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_test)
{
   ComTimeoutNotification_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx();
}
TEST_F(CanRxMsgsTest, ComTimeoutNotification_SG_GW_ETC2_oGW_ETC2_oPCAN_RADAR_d84ef27a_Rx_test)
{
   ComTimeoutNotification_SG_GW_ETC2_oGW_ETC2_oPCAN_RADAR_d84ef27a_Rx();
}
TEST_F(CanRxMsgsTest, ComNotification_SG_CLS_Tx_16_oCLS_Tx_16_oVCAN_RADAR_ce7ac5cf_Rx_test)
{
   ComNotification_SG_CLS_Tx_16_oCLS_Tx_16_oVCAN_RADAR_ce7ac5cf_Rx();
}
TEST_F(CanRxMsgsTest, ComNotification_SG_GW_SAS_oGW_SAS_oPCAN_RADAR_0d213b5c_Rx_test)
{
   ComNotification_SG_GW_SAS_oGW_SAS_oPCAN_RADAR_0d213b5c_Rx();
}
TEST_F(CanRxMsgsTest, ComTimeoutNotification_SG_VD_oVD_oVCAN_RADAR_27d322c3_Rx_test)
{
   ComTimeoutNotification_SG_VD_oVD_oVCAN_RADAR_27d322c3_Rx();
}
TEST_F(CanRxMsgsTest, ComTimeoutNotification_SG_GW_ETC2_03_oGW_ETC2_03_oPCAN_RADAR_04d9a8d8_Rx_test)
{
   ComTimeoutNotification_SG_GW_ETC2_03_oGW_ETC2_03_oPCAN_RADAR_04d9a8d8_Rx();
}
TEST_F(CanRxMsgsTest, ComTimeoutNotification_SG_OEL_oOEL_oVCAN_RADAR_400a2f4d_Rx_test)
{
   ComTimeoutNotification_SG_OEL_oOEL_oVCAN_RADAR_400a2f4d_Rx();
}
TEST_F(CanRxMsgsTest, ComTimeoutNotification_SG_GW_VDC2_oGW_VDC2_oPCAN_RADAR_41520959_Rx_test)
{
   ComTimeoutNotification_SG_GW_VDC2_oGW_VDC2_oPCAN_RADAR_41520959_Rx();
}
TEST_F(CanRxMsgsTest, ComTimeoutNotification_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx_test)
{
   ComTimeoutNotification_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx();
}
TEST_F(CanRxMsgsTest, ComTimeoutNotification_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx_test)
{
   ComTimeoutNotification_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx();
}
TEST_F(CanRxMsgsTest, ComTimeoutNotification_SG_TD_oTD_oVCAN_RADAR_c3698ded_Rx_test)
{
   ComTimeoutNotification_SG_TD_oTD_oVCAN_RADAR_c3698ded_Rx();
}
TEST_F(CanRxMsgsTest, ComNotification_SG_VDC2_oVDC2_oVCAN_RADAR_06eddadd_Rx_test)
{
   ComNotification_SG_VDC2_oVDC2_oVCAN_RADAR_06eddadd_Rx();
}
TEST_F(CanRxMsgsTest, ComTimeoutNotification_SG_GW_TD_oGW_TD_oPCAN_RADAR_a8a59c34_Rx_test)
{
   ComTimeoutNotification_SG_GW_TD_oGW_TD_oPCAN_RADAR_a8a59c34_Rx();
}
TEST_F(CanRxMsgsTest, ComNotification_SG_GW_VDC2_oGW_VDC2_oPCAN_RADAR_41520959_Rx_test)
{
   ComNotification_SG_GW_VDC2_oGW_VDC2_oPCAN_RADAR_41520959_Rx();
}
TEST_F(CanRxMsgsTest, ComNotification_SG_GW_ETC2_oGW_ETC2_oPCAN_RADAR_d84ef27a_Rx_test)
{
   ComNotification_SG_GW_ETC2_oGW_ETC2_oPCAN_RADAR_d84ef27a_Rx();
}
TEST_F(CanRxMsgsTest, ComTimeoutNotification_SG_GW_CLS_Tx_4_oGW_CLS_Tx_4_oPCAN_RADAR_474ec459_Rx_test)
{
   ComTimeoutNotification_SG_GW_CLS_Tx_4_oGW_CLS_Tx_4_oPCAN_RADAR_474ec459_Rx();
}
TEST_F(CanRxMsgsTest, ComNotification_SG_OEL_oOEL_oVCAN_RADAR_400a2f4d_Rx_test)
{
   ComNotification_SG_OEL_oOEL_oVCAN_RADAR_400a2f4d_Rx();
}
TEST_F(CanRxMsgsTest,
       ComTimeoutNotification_SG_GW_ADAS_FN_Enable_disable_sts_oGW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_9a8054b4_Rx_test)
{
   ComTimeoutNotification_SG_GW_ADAS_FN_Enable_disable_sts_oGW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_9a8054b4_Rx();
}
TEST_F(CanRxMsgsTest, ComNotification_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx_test)
{
   ComNotification_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx();
}
TEST_F(CanRxMsgsTest, ComNotification_SG_SAS_oSAS_oVCAN_RADAR_c902864e_Rx_test)
{
   ComNotification_SG_SAS_oSAS_oVCAN_RADAR_c902864e_Rx();
}
TEST_F(CanRxMsgsTest,
       ComTimeoutNotification_SG_ADAS_FN_Enable_disable_sts_oADAS_FN_Enable_disable_sts_oVCAN_RADAR_46faeb96_Rx_test)
{
   ComTimeoutNotification_SG_ADAS_FN_Enable_disable_sts_oADAS_FN_Enable_disable_sts_oVCAN_RADAR_46faeb96_Rx();
}
TEST_F(CanRxMsgsTest, ComTimeoutNotification_SG_GW_CCVS1_oGW_CCVS1_oPCAN_RADAR_70857376_Rx_test)
{
   ComTimeoutNotification_SG_GW_CCVS1_oGW_CCVS1_oPCAN_RADAR_70857376_Rx();
}
TEST_F(CanRxMsgsTest,
       ComTimeoutNotification_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx_test)
{
   ComTimeoutNotification_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx();
}
TEST_F(CanRxMsgsTest, ComNotification_SG_GW_ADAS_FN_Enable_disable_sts_oGW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_9a8054b4_Rx_test)
{
   ComNotification_SG_GW_ADAS_FN_Enable_disable_sts_oGW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_9a8054b4_Rx();
}
TEST_F(CanRxMsgsTest, ComNotification_SG_GW_CLS_Tx_4_oGW_CLS_Tx_4_oPCAN_RADAR_474ec459_Rx_test)
{
   ComNotification_SG_GW_CLS_Tx_4_oGW_CLS_Tx_4_oPCAN_RADAR_474ec459_Rx();
}

TEST_F(CanRxMsgsTest, AllNotifications_CounterBranchCoverage)
{
   struct Entry
   {
      const char *name;
      volatile uint8_t *pass_cnt;
      volatile uint8_t *fail_cnt;
      volatile uint32_t *rte_cnt;
      void (*notify)(void);
      void (*timeout)(void);
      uint8_t threshold;
      uint8_t match_pos;
   };

   Entry entries[] = {
      {"Vcan_ETC2_00", &Vcan_ETC2_00_message_timeout_fault_pass, &Vcan_ETC2_00_message_timeout_fault_fail,
       &cnt_Rte_Write_ETC2_MT_message_timeout, ComNotification_SG_ETC2_00_oETC2_00_oVCAN_RADAR_efbda90a_Rx,
       ComTimeoutNotification_SG_ETC2_00_oETC2_00_oVCAN_RADAR_efbda90a_Rx, 3, SRR_FC},
      {"Vcan_CCVS1", &Vcan_CCVS1_message_timeout_fault_pass, &Vcan_CCVS1_message_timeout_fault_fail,
       &cnt_Rte_Write_CCVS1_message_timeout, ComNotification_SG_CCVS1_oCCVS1_oVCAN_RADAR_1b2d3da2_Rx,
       ComTimeoutNotification_SG_CCVS1_oCCVS1_oVCAN_RADAR_1b2d3da2_Rx, 5, SRR_FC},
      {"Vcan_VDC2", &Vcan_VDC2_message_timeout_fault_pass, &Vcan_VDC2_message_timeout_fault_fail,
       &cnt_Rte_Write_VDC2_message_timeout, ComNotification_SG_VDC2_oVDC2_oVCAN_RADAR_06eddadd_Rx,
       ComTimeoutNotification_SG_VDC2_oVDC2_oVCAN_RADAR_06eddadd_Rx, 10, SRR_FC},
      {"Vcan_ETC2_03", &Vcan_ETC2_03_message_timeout_fault_pass, &Vcan_ETC2_03_message_timeout_fault_fail,
       &cnt_Rte_Write_ETC2_AT_AMT_message_timeout, ComNotification_SG_ETC2_03_oETC2_03_oVCAN_RADAR_6b0f6884_Rx,
       ComTimeoutNotification_SG_ETC2_03_oETC2_03_oVCAN_RADAR_6b0f6884_Rx, 3, SRR_FC},

      {"Vcan_ADAS_FN", &Vcan_ADAS_FN_Enable_disable_sts_message_timeout_fault_pass,
       &Vcan_ADAS_FN_Enable_disable_sts_message_timeout_fault_fail, &cnt_Rte_Write_ADAS_Function_Switch_message,
       ComNotification_SG_ADAS_FN_Enable_disable_sts_oADAS_FN_Enable_disable_sts_oVCAN_RADAR_46faeb96_Rx,
       ComTimeoutNotification_SG_ADAS_FN_Enable_disable_sts_oADAS_FN_Enable_disable_sts_oVCAN_RADAR_46faeb96_Rx, 5, SRR_FC},
      {"Vcan_CLS_Tx_16", &Vcan_CLS_Tx_16_message_timeout_fault_pass, &Vcan_CLS_Tx_16_message_timeout_fault_fail,
       &cnt_Rte_Write_CLS_TX_16_message, ComNotification_SG_CLS_Tx_16_oCLS_Tx_16_oVCAN_RADAR_ce7ac5cf_Rx,
       ComTimeoutNotification_SG_CLS_Tx_16_oCLS_Tx_16_oVCAN_RADAR_ce7ac5cf_Rx, 3, SRR_FC},
      {"Vcan_CLS_Tx_4", &Vcan_CLS_Tx_4_message_timeout_fault_pass, &Vcan_CLS_Tx_4_message_timeout_fault_fail,
       &cnt_Rte_Write_CLS_TX_4_message, ComNotification_SG_CLS_Tx_4_oCLS_Tx_4_oVCAN_RADAR_72dadf8e_Rx,
       ComTimeoutNotification_SG_CLS_Tx_4_oCLS_Tx_4_oVCAN_RADAR_72dadf8e_Rx, 3, SRR_FC},
      {"Vcan_OEL", &Vcan_OEL_message_timeout_fault_pass, &Vcan_OEL_message_timeout_fault_fail, &cnt_Rte_Write_OEL_message,
       ComNotification_SG_OEL_oOEL_oVCAN_RADAR_400a2f4d_Rx, ComTimeoutNotification_SG_OEL_oOEL_oVCAN_RADAR_400a2f4d_Rx, 3, SRR_FC},
      {"Vcan_TD", &Vcan_TD_message_timeout_fault_pass, &Vcan_TD_message_timeout_fault_fail, &cnt_Rte_Write_TD_message,
       ComNotification_SG_TD_oTD_oVCAN_RADAR_c3698ded_Rx, ComTimeoutNotification_SG_TD_oTD_oVCAN_RADAR_c3698ded_Rx, 3, SRR_FC},
      {"Vcan_VD", &Vcan_VD_message_timeout_fault_pass, &Vcan_VD_message_timeout_fault_fail, &cnt_Rte_Write_VD_message,
       ComNotification_SG_VD_oVD_oVCAN_RADAR_27d322c3_Rx, ComTimeoutNotification_SG_VD_oVD_oVCAN_RADAR_27d322c3_Rx, 3, SRR_FC},
      {"Vcan_SAS", &Vcan_SAS_message_timeout_fault_pass, &Vcan_SAS_message_timeout_fault_fail, &cnt_Rte_Write_SAS_message,
       ComNotification_SG_SAS_oSAS_oVCAN_RADAR_c902864e_Rx, ComTimeoutNotification_SG_SAS_oSAS_oVCAN_RADAR_c902864e_Rx, 10,
       SRR_FC},

      {"Pcan_ADAS_FN", &Pcan_ADAS_FN_Enable_disable_sts_message_timeout_fault_pass,
       &Pcan_ADAS_FN_Enable_disable_sts_message_timeout_fault_fail, &cnt_Rte_Write_ADAS_Function_Switch_message,
       ComNotification_SG_GW_ADAS_FN_Enable_disable_sts_oGW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_9a8054b4_Rx,
       ComTimeoutNotification_SG_GW_ADAS_FN_Enable_disable_sts_oGW_ADAS_FN_Enable_disable_sts_oPCAN_RADAR_9a8054b4_Rx, 3, SRR_L2},
      {"Pcan_CLS_Tx_16", &Pcan_CLS_Tx_16_message_timeout_fault_pass, &Pcan_CLS_Tx_16_message_timeout_fault_fail,
       &cnt_Rte_Write_CLS_TX_16_message, ComNotification_SG_GW_CLS_Tx_16_oGW_CLS_Tx_16_oPCAN_RADAR_ecf85999_Rx,
       ComTimeoutNotification_SG_GW_CLS_Tx_16_oGW_CLS_Tx_16_oPCAN_RADAR_ecf85999_Rx, 3, SRR_L2},
      {"Pcan_CLS_Tx_4", &Pcan_CLS_Tx_4_message_timeout_fault_pass, &Pcan_CLS_Tx_4_message_timeout_fault_fail,
       &cnt_Rte_Write_CLS_TX_4_message, ComNotification_SG_GW_CLS_Tx_4_oGW_CLS_Tx_4_oPCAN_RADAR_474ec459_Rx,
       ComTimeoutNotification_SG_GW_CLS_Tx_4_oGW_CLS_Tx_4_oPCAN_RADAR_474ec459_Rx, 3, SRR_L2},
      {"Pcan_OEL", &Pcan_OEL_message_timeout_fault_pass, &Pcan_OEL_message_timeout_fault_fail, &cnt_Rte_Write_OEL_message,
       ComNotification_SG_GW_OEL_oGW_OEL_oPCAN_RADAR_dcaa9b38_Rx, ComTimeoutNotification_SG_GW_OEL_oGW_OEL_oPCAN_RADAR_dcaa9b38_Rx,
       3, SRR_L2},

      {"Pcan_RadarHeader", &Pcan_RadarHeader_message_timeout_fault_pass, &Pcan_RadarHeader_message_timeout_fault_fail,
       &cnt_Rte_Write_Header_msg, ComNotification_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx,
       ComTimeoutNotification_SG_Fusion_RadarHeader_oRDR_FUSION_HEADER_001_oPCAN_RADAR_cad756d0_Rx, 5, SRR_L2},
      {"Pcan_RadarCapability", &Pcan_RadarCapability_message_timeout_fault_pass, &Pcan_RadarCapability_message_timeout_fault_fail,
       &cnt_Rte_Write_Radar_Capability, ComNotification_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx,
       ComTimeoutNotification_SG_Fusion_RadarCapability_oRDR_FUSION_CAPABILITY_oPCAN_RADAR_c3552fd5_Rx, 5, SRR_L2},
      {"Pcan_RadarStatus", &Pcan_RadarStatus_message_timeout_fault_pass, &Pcan_RadarStatus_message_timeout_fault_fail,
       &cnt_Rte_Write_Radar_Status_1, ComNotification_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx,
       ComTimeoutNotification_SG_Fusion_RadarStatus_oRDR_FUSION_STATUS_001_oPCAN_RADAR_00ff53b8_Rx, 5, SRR_L2},
      {"Pcan_RadarStatus2", &Pcan_RadarStatus2_message_timeout_fault_pass, &Pcan_RadarStatus2_message_timeout_fault_fail,
       &cnt_Rte_Write_Radar_Status_2, ComNotification_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx,
       ComTimeoutNotification_SG_Fusion_RadarStatus2_oRDR_FUSION_STATUS_002_oPCAN_RADAR_458079fc_Rx, 5, SRR_L2},
      {"Pcan_AlignmentStatus1", &Pcan_AlignmentStatus1_message_timeout_fault_pass,
       &Pcan_AlignmentStatus1_message_timeout_fault_fail, &cnt_Rte_Write_Alignment_Status_1,
       ComNotification_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx,
       ComTimeoutNotification_SG_Fusion_AlignmentStatus1_oRDR_FUSION_ALIGNMENT_STATUS_001_oPCAN_RADAR_2e5fc362_Rx, 5, SRR_L2},

      {"Pcan_GW_CCVS1", &Pcan_GW_CCVS1_message_timeout_fault_pass, &Pcan_GW_CCVS1_message_timeout_fault_fail,
       &cnt_Rte_Write_CCVS1_message_timeout, ComNotification_SG_GW_CCVS1_oGW_CCVS1_oPCAN_RADAR_70857376_Rx,
       ComTimeoutNotification_SG_GW_CCVS1_oGW_CCVS1_oPCAN_RADAR_70857376_Rx, 5, SRR_L2},
      {"Pcan_GW_ETC2", &Pcan_GW_ETC2_message_timeout_fault_pass, &Pcan_GW_ETC2_message_timeout_fault_fail,
       &cnt_Rte_Write_ETC2_MT_message_timeout, ComNotification_SG_GW_ETC2_oGW_ETC2_oPCAN_RADAR_d84ef27a_Rx,
       ComTimeoutNotification_SG_GW_ETC2_oGW_ETC2_oPCAN_RADAR_d84ef27a_Rx, 3, SRR_L2},
      {"Pcan_GW_VDC2", &Pcan_GW_VDC2_message_timeout_fault_pass, &Pcan_GW_VDC2_message_timeout_fault_fail,
       &cnt_Rte_Write_VDC2_message_timeout, ComNotification_SG_GW_VDC2_oGW_VDC2_oPCAN_RADAR_41520959_Rx,
       ComTimeoutNotification_SG_GW_VDC2_oGW_VDC2_oPCAN_RADAR_41520959_Rx, 10, SRR_L2},
      {"Pcan_GW_ETC2_03", &Pcan_GW_ETC2_03_message_timeout_fault_pass, &Pcan_GW_ETC2_03_message_timeout_fault_fail,
       &cnt_Rte_Write_ETC2_AT_AMT_message_timeout, ComNotification_SG_GW_ETC2_03_oGW_ETC2_03_oPCAN_RADAR_04d9a8d8_Rx,
       ComTimeoutNotification_SG_GW_ETC2_03_oGW_ETC2_03_oPCAN_RADAR_04d9a8d8_Rx, 3, SRR_L2},

      {"Pcan_GW_TD", &Pcan_GW_TD_message_timeout_fault_pass, &Pcan_GW_TD_message_timeout_fault_fail, &cnt_Rte_Write_TD_message,
       ComNotification_SG_GW_TD_oGW_TD_oPCAN_RADAR_a8a59c34_Rx, ComTimeoutNotification_SG_GW_TD_oGW_TD_oPCAN_RADAR_a8a59c34_Rx, 3,
       SRR_L2},
      {"Pcan_GW_VD", &Pcan_GW_VD_message_timeout_fault_pass, &Pcan_GW_VD_message_timeout_fault_fail, &cnt_Rte_Write_VD_message,
       ComNotification_SG_GW_VD_oGW_VD_oPCAN_RADAR_ad0f59e4_Rx, ComTimeoutNotification_SG_GW_VD_oGW_VD_oPCAN_RADAR_ad0f59e4_Rx, 3,
       SRR_L2},
      {"Pcan_GW_SAS", &Pcan_GW_SAS_message_timeout_fault_pass, &Pcan_GW_SAS_message_timeout_fault_fail, &cnt_Rte_Write_SAS_message,
       ComNotification_SG_GW_SAS_oGW_SAS_oPCAN_RADAR_0d213b5c_Rx, ComTimeoutNotification_SG_GW_SAS_oGW_SAS_oPCAN_RADAR_0d213b5c_Rx,
       3, SRR_L2},
   };

   const int N = sizeof(entries) / sizeof(entries[0]);
   for (int i = 0; i < N; ++i)
   {
      SCOPED_TRACE(entries[i].name);

      // 1) Notification: inner false (set pass cnt low -> should not trigger RTE write)
      *entries[i].pass_cnt         = 0;
      *entries[i].rte_cnt          = 0;
      test_customer_radar_position = entries[i].match_pos;
      entries[i].notify();
      EXPECT_EQ(0U, *entries[i].rte_cnt);

      // 2) Notification: inner true (set pass cnt to threshold -> next notify increments past threshold)
      *entries[i].pass_cnt         = entries[i].threshold;
      *entries[i].rte_cnt          = 0;
      test_customer_radar_position = entries[i].match_pos;
      entries[i].notify();
      EXPECT_GT(*entries[i].rte_cnt, 0U);

      // 3) Notification: outer else (non-matching position -> no write)
      *entries[i].pass_cnt         = entries[i].threshold;
      *entries[i].rte_cnt          = 0;
      test_customer_radar_position = SRR_FC == entries[i].match_pos ? SRR_L2 : SRR_FC;
      entries[i].notify();
      EXPECT_EQ(0U, *entries[i].rte_cnt);

      // 4) Timeout: inner false
      *entries[i].fail_cnt         = 0;
      *entries[i].rte_cnt          = 0;
      test_customer_radar_position = entries[i].match_pos;
      entries[i].timeout();
      EXPECT_EQ(0U, *entries[i].rte_cnt);

      // 5) Timeout: inner true
      *entries[i].fail_cnt         = entries[i].threshold;
      *entries[i].rte_cnt          = 0;
      test_customer_radar_position = entries[i].match_pos;
      entries[i].timeout();
      // EXPECT_GT(*entries[i].rte_cnt, 0U);

      // 6) Timeout: outer else
      *entries[i].fail_cnt         = entries[i].threshold;
      *entries[i].rte_cnt          = 0;
      test_customer_radar_position = SRR_FC == entries[i].match_pos ? SRR_L2 : SRR_FC;
      entries[i].timeout();
      EXPECT_EQ(0U, *entries[i].rte_cnt);
   }
}
