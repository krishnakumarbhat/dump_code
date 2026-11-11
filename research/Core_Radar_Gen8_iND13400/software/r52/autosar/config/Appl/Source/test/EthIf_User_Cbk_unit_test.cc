/**
 * @file EthIf_User_Cbk_unit_test.cc
 * @brief Unit tests for EthIf_User_Cbk.c
 */

#include <gtest/gtest.h>
extern "C"
{
#include "EthIf_User_Cbk_fakes.h"

   DEFINE_FFF_GLOBALS;

   void User_EthIf_ArpTableAddEntry(uint8_t CtrlIdx, const uint8_t *MacPtr, const uint8_t *IpV4AddrPtr);
   void User_EthIf_CtrlModeIndication(uint8_t CtrlIdx, uint8_t CtrlMode);
   void User_EthIf_TrcvModeIndication(uint8_t TrcvIdx, uint8_t TrcvMode);
   void User_EthIf_SwitchPortModeIndication(EthIf_SwitchPortIdxType PortIdx, uint8_t PortMode);

   extern SMC_Cal_Data_T *SMC_Cal_Data_Ptr;
}

DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, EthIf_SetPhysAddr, uint8_t, const uint8_t *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, SoAd_SetUniqueRemoteAddr, uint16_t, const uint8_t *, uint16_t);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, EthIf_GetPhysAddr, uint8_t, uint8_t *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, SoAd_GetLocalAddr, uint16_t, uint8_t *, uint16_t *, uint8_t *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, SoAd_GetRemoteAddr, uint16_t, uint8_t *, uint16_t *);
DEFINE_FAKE_VALUE_FUNC(boolean, Get_Cal_Load_Status, Log_Cal_Src_T);

class EthIfUserCbkTest : public ::testing::Test
{
 protected:
   void SetUp() override
   {
      RESET_FAKE(EthIf_SetPhysAddr);
      RESET_FAKE(SoAd_SetUniqueRemoteAddr);
      RESET_FAKE(EthIf_GetPhysAddr);
      RESET_FAKE(SoAd_GetLocalAddr);
      RESET_FAKE(SoAd_GetRemoteAddr);
      RESET_FAKE(Get_Cal_Load_Status);
      FFF_RESET_HISTORY();

      EthIf_SetPhysAddr_fake.return_val        = E_OK;
      SoAd_SetUniqueRemoteAddr_fake.return_val = E_OK;
      Get_Cal_Load_Status_fake.return_val      = 0u;
   }
};

TEST_F(EthIfUserCbkTest, ArpTableAddEntry_DoesNothing)
{
   uint8_t mac[6] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05};
   uint8_t ip[4]  = {192, 168, 1, 1};

   User_EthIf_ArpTableAddEntry(0, mac, ip);
   // No assertions - just verify it doesn't crash
}

TEST_F(EthIfUserCbkTest, CtrlModeIndication_DoesNothing)
{
   User_EthIf_CtrlModeIndication(0, 1);
   // No assertions - just verify it doesn't crash
}

TEST_F(EthIfUserCbkTest, TrcvModeIndication_SetsPhysAddr)
{
   User_EthIf_TrcvModeIndication(0, 1);

   EXPECT_EQ(EthIf_SetPhysAddr_fake.call_count, 1);
   EXPECT_EQ(EthIf_SetPhysAddr_fake.arg0_val, 0);
}

TEST_F(EthIfUserCbkTest, TrcvModeIndication_SetsRemoteAddr)
{
   User_EthIf_TrcvModeIndication(0, 1);

   EXPECT_EQ(SoAd_SetUniqueRemoteAddr_fake.call_count, 1);
   EXPECT_EQ(SoAd_SetUniqueRemoteAddr_fake.arg0_val, 0);
   EXPECT_EQ(SoAd_SetUniqueRemoteAddr_fake.arg2_val, 5050);

   // Just verify the call was made with IP address data
   EXPECT_NE(SoAd_SetUniqueRemoteAddr_fake.arg1_val, nullptr);
}

TEST_F(EthIfUserCbkTest, TrcvModeIndication_WithDifferentIndex)
{
   User_EthIf_TrcvModeIndication(1, 2);

   EXPECT_EQ(EthIf_SetPhysAddr_fake.call_count, 1);
   EXPECT_EQ(SoAd_SetUniqueRemoteAddr_fake.call_count, 1);
}

TEST_F(EthIfUserCbkTest, SwitchPortModeIndication_DoesNothing)
{
   User_EthIf_SwitchPortModeIndication(0, 1);
   // No assertions - just verify it doesn't crash
}

TEST_F(EthIfUserCbkTest, TrcvModeIndication_CallOrder_PhysAddrBeforeRemoteAddr)
{
   User_EthIf_TrcvModeIndication(0, 1);

   EXPECT_EQ(fff.call_history[0], (void *)Get_Cal_Load_Status);
   EXPECT_EQ(fff.call_history[1], (void *)EthIf_SetPhysAddr);
   EXPECT_EQ(fff.call_history[2], (void *)SoAd_SetUniqueRemoteAddr);
}

TEST_F(EthIfUserCbkTest, MultipleTrcvIndications_AccumulateCalls)
{
   User_EthIf_TrcvModeIndication(0, 1);
   User_EthIf_TrcvModeIndication(0, 1);

   EXPECT_EQ(EthIf_SetPhysAddr_fake.call_count, 2);
   EXPECT_EQ(SoAd_SetUniqueRemoteAddr_fake.call_count, 2);
}

TEST_F(EthIfUserCbkTest, TrcvModeIndication_CalLoadStatusTrue_UsesDefaultAddress)
{
   Get_Cal_Load_Status_fake.return_val = 1u;

   User_EthIf_TrcvModeIndication(0, 1);

   ASSERT_NE(EthIf_SetPhysAddr_fake.arg1_val, nullptr);
   EXPECT_EQ(EthIf_SetPhysAddr_fake.arg1_val[5], 71u);
   EXPECT_EQ(Get_Cal_Load_Status_fake.call_count, 1);
   EXPECT_EQ(Get_Cal_Load_Status_fake.arg0_val, SMC);
}

TEST_F(EthIfUserCbkTest, GetSensorMacAddress_CalLoadStatusFalse_UsesSmcLsb)
{
   Get_Cal_Load_Status_fake.return_val = 0u;
   User_EthIf_TrcvModeIndication(2u, 1u);

   ASSERT_NE(EthIf_SetPhysAddr_fake.arg1_val, nullptr);
   EXPECT_EQ(EthIf_SetPhysAddr_fake.arg1_val[5], SMC_Cal_Data_Ptr->Vehicle_Configuration_Cal.k_sensor_ethernet_lsb_list[5]);
   EXPECT_EQ(Get_Cal_Load_Status_fake.call_count, 1);
   EXPECT_EQ(Get_Cal_Load_Status_fake.arg0_val, SMC);
}

TEST_F(EthIfUserCbkTest, GetSensorIpAddress_CalLoadStatusTrue_UsesDefaultLsb)
{
   Get_Cal_Load_Status_fake.return_val = 1u;
   User_EthIf_TrcvModeIndication(0u, 1u);

   ASSERT_NE(SoAd_SetUniqueRemoteAddr_fake.arg1_val, nullptr);
   uint32_t ip = 0u;
   memcpy(&ip, SoAd_SetUniqueRemoteAddr_fake.arg1_val, sizeof(ip));
   EXPECT_EQ(ip, 0x4701A8C0u);
   EXPECT_EQ(Get_Cal_Load_Status_fake.call_count, 1);
   EXPECT_EQ(Get_Cal_Load_Status_fake.arg0_val, SMC);
}

TEST_F(EthIfUserCbkTest, GetSensorIpAddress_CalLoadStatusFalse_UsesSmcDestinationIp)
{
   Get_Cal_Load_Status_fake.return_val = 0u;
   User_EthIf_TrcvModeIndication(1u, 1u);

   ASSERT_NE(SoAd_SetUniqueRemoteAddr_fake.arg1_val, nullptr);
   uint32_t ip = 0u;
   memcpy(&ip, SoAd_SetUniqueRemoteAddr_fake.arg1_val, sizeof(ip));
   uint32_t expected = ((uint32_t)SMC_Cal_Data_Ptr->Vehicle_Configuration_Cal.k_destination_ip[3] << 24u) |
                       ((uint32_t)SMC_Cal_Data_Ptr->Vehicle_Configuration_Cal.k_destination_ip[2] << 16u) |
                       ((uint32_t)SMC_Cal_Data_Ptr->Vehicle_Configuration_Cal.k_destination_ip[1] << 8u) |
                       ((uint32_t)SMC_Cal_Data_Ptr->Vehicle_Configuration_Cal.k_destination_ip[0]);

   EXPECT_EQ(ip, expected);
   EXPECT_EQ(Get_Cal_Load_Status_fake.call_count, 1);
   EXPECT_EQ(Get_Cal_Load_Status_fake.arg0_val, SMC);
}
