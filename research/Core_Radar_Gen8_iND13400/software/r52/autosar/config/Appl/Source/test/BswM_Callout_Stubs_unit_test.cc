/**
 * @file BswM_Callout_Stubs_unit_test.cc
 * @brief Unit tests for BswM_Callout_Stubs.c
 */

#include <gtest/gtest.h>
extern "C"
{
#include "BswM_Callout_fakes.h"

   DEFINE_FFF_GLOBALS;

   void BswM_AL_SetProgrammableInterrupts(void);
   void BswM_ESH_OnEnterPostRun(void);
   void BswM_ESH_OnEnterPrepShutdown(void);
   void BswM_ESH_OnEnterRun(void);
   void BswM_ESH_OnEnterShutdown(void);
   void BswM_ESH_OnEnterWaitForNvm(void);
   void BswM_ESH_OnEnterWakeup(void);
   void BswM_INIT_NvMReadAll(void);
   void Eth_ComM_Init(void);
   void User_CAN_ComPduGroupHandling(void);
   void User_Com_Init(void);
}

DEFINE_FAKE_VOID_FUNC(Gpt_EnableNotification, uint8_t);
DEFINE_FAKE_VOID_FUNC(Gpt_StartTimer, uint8_t, uint32_t);
DEFINE_FAKE_VOID_FUNC(EcuM_SetWakeupEvent, uint32_t);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Mcu_InitClock, uint8_t);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Mcu_DistributePllClock);
DEFINE_FAKE_VOID_FUNC(Sys_Printf_Information, const char *);
DEFINE_FAKE_VOID_FUNC(NvM_ReadAll);
DEFINE_FAKE_VOID_FUNC(NvM_MainFunction);
DEFINE_FAKE_VOID_FUNC(Fee_30_FlexNor_MainFunction);
DEFINE_FAKE_VOID_FUNC(Fls_MainFunction);
DEFINE_FAKE_VOID_FUNC(NvM_GetErrorStatus, uint8_t, NvM_RequestResultType *);
DEFINE_FAKE_VOID_FUNC(ComM_RequestComMode, uint8_t, uint8_t);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_Radar_Position);
DEFINE_FAKE_VOID_FUNC(Com_IpduGroupStart, uint16_t, uint8_t);
DEFINE_FAKE_VOID_FUNC(Com_Init, const void *);

class BswMCalloutTest : public ::testing::Test
{
 protected:
   void SetUp() override
   {
      RESET_FAKE(Gpt_EnableNotification);
      RESET_FAKE(Gpt_StartTimer);
      RESET_FAKE(EcuM_SetWakeupEvent);
      RESET_FAKE(Mcu_InitClock);
      RESET_FAKE(Mcu_DistributePllClock);
      RESET_FAKE(Sys_Printf_Information);
      RESET_FAKE(NvM_ReadAll);
      RESET_FAKE(NvM_MainFunction);
      RESET_FAKE(Fee_30_FlexNor_MainFunction);
      RESET_FAKE(Fls_MainFunction);
      RESET_FAKE(NvM_GetErrorStatus);
      RESET_FAKE(ComM_RequestComMode);
      RESET_FAKE(Get_Radar_Position);
      RESET_FAKE(Com_IpduGroupStart);
      RESET_FAKE(Com_Init);
      FFF_RESET_HISTORY();
   }
};

TEST_F(BswMCalloutTest, SetProgrammableInterrupts_DoesNothing)
{
   BswM_AL_SetProgrammableInterrupts();
}

TEST_F(BswMCalloutTest, OnEnterPostRun_DoesNothing)
{
   BswM_ESH_OnEnterPostRun();
}

TEST_F(BswMCalloutTest, OnEnterPrepShutdown_DoesNothing)
{
   BswM_ESH_OnEnterPrepShutdown();
}

TEST_F(BswMCalloutTest, OnEnterRun_DoesNothing)
{
   BswM_ESH_OnEnterRun();
}

TEST_F(BswMCalloutTest, OnEnterShutdown_DoesNothing)
{
   BswM_ESH_OnEnterShutdown();
}

TEST_F(BswMCalloutTest, OnEnterWaitForNvm_DoesNothing)
{
   BswM_ESH_OnEnterWaitForNvm();
}

TEST_F(BswMCalloutTest, OnEnterWakeup_DoesNothing)
{
   BswM_ESH_OnEnterWakeup();
}

TEST_F(BswMCalloutTest, InitNvMReadAll_CallsNvMReadAll)
{
   NvM_GetErrorStatus_fake.custom_fake = [](uint8_t, NvM_RequestResultType *status)
   {
      static int call_count = 0;
      *status               = (call_count++ < 2) ? NVM_REQ_PENDING : NVM_REQ_OK;
   };

   BswM_INIT_NvMReadAll();

   EXPECT_EQ(NvM_ReadAll_fake.call_count, 1);
   EXPECT_GE(NvM_MainFunction_fake.call_count, 3);
   EXPECT_GE(Fee_30_FlexNor_MainFunction_fake.call_count, 3);
   EXPECT_GE(Fls_MainFunction_fake.call_count, 3);
}

TEST_F(BswMCalloutTest, EthCommInit_RequestsFullCommunication)
{
   Eth_ComM_Init();

   EXPECT_EQ(ComM_RequestComMode_fake.call_count, 1);
   EXPECT_EQ(ComM_RequestComMode_fake.arg0_val, ComMConf_ComMChannel_cnctr_RDR_RdrNet_5172a59b);
   EXPECT_EQ(ComM_RequestComMode_fake.arg1_val, COMM_FULL_COMMUNICATION);
}

TEST_F(BswMCalloutTest, UserCANComPduGroupHandling_Position1_StartsRDR01Groups)
{
   Get_Radar_Position_fake.return_val = 1;

   User_CAN_ComPduGroupHandling();

   EXPECT_EQ(Com_IpduGroupStart_fake.call_count, 2);
   EXPECT_EQ(Com_IpduGroupStart_fake.arg0_history[0], ComConf_ComIPduGroup_RDR01_oPCAN_RADAR_Rx_e0e717e1);
   EXPECT_EQ(Com_IpduGroupStart_fake.arg0_history[1], ComConf_ComIPduGroup_RDR01_oPCAN_RADAR_Tx_b6bdb067);
}

TEST_F(BswMCalloutTest, UserCANComPduGroupHandling_Position2_StartsRDR02Groups)
{
   Get_Radar_Position_fake.return_val = 2;

   User_CAN_ComPduGroupHandling();

   EXPECT_EQ(Com_IpduGroupStart_fake.call_count, 2);
   EXPECT_EQ(Com_IpduGroupStart_fake.arg0_history[0], ComConf_ComIPduGroup_RDR02_oPCAN_RADAR_Rx_c92fa313);
   EXPECT_EQ(Com_IpduGroupStart_fake.arg0_history[1], ComConf_ComIPduGroup_RDR02_oPCAN_RADAR_Tx_9f750495);
}

TEST_F(BswMCalloutTest, UserCANComPduGroupHandling_Position3_StartsRDR03Groups)
{
   Get_Radar_Position_fake.return_val = 3;

   User_CAN_ComPduGroupHandling();

   EXPECT_EQ(Com_IpduGroupStart_fake.call_count, 2);
   EXPECT_EQ(Com_IpduGroupStart_fake.arg0_history[0], ComConf_ComIPduGroup_RDR03_oPCAN_RADAR_Rx_67473282);
   EXPECT_EQ(Com_IpduGroupStart_fake.arg0_history[1], ComConf_ComIPduGroup_RDR03_oPCAN_RADAR_Tx_311d9504);
}

TEST_F(BswMCalloutTest, UserCANComPduGroupHandling_Position4_StartsRDR04Groups)
{
   Get_Radar_Position_fake.return_val = 4;

   User_CAN_ComPduGroupHandling();

   EXPECT_EQ(Com_IpduGroupStart_fake.call_count, 2);
   EXPECT_EQ(Com_IpduGroupStart_fake.arg0_history[0], ComConf_ComIPduGroup_RDR04_oPCAN_RADAR_Rx_9abecaf7);
   EXPECT_EQ(Com_IpduGroupStart_fake.arg0_history[1], ComConf_ComIPduGroup_RDR04_oPCAN_RADAR_Tx_cce46d71);
}

TEST_F(BswMCalloutTest, UserCANComPduGroupHandling_Position5_StartsRDR05Groups)
{
   Get_Radar_Position_fake.return_val = 5;

   User_CAN_ComPduGroupHandling();

   EXPECT_EQ(Com_IpduGroupStart_fake.call_count, 2);
   EXPECT_EQ(Com_IpduGroupStart_fake.arg0_history[0], ComConf_ComIPduGroup_RDR05_oPCAN_RADAR_Rx_34d65b66);
   EXPECT_EQ(Com_IpduGroupStart_fake.arg0_history[1], ComConf_ComIPduGroup_RDR05_oPCAN_RADAR_Tx_628cfce0);
}

TEST_F(BswMCalloutTest, UserCANComPduGroupHandling_Position6_StartsRDR06Groups)
{
   Get_Radar_Position_fake.return_val = 6;

   User_CAN_ComPduGroupHandling();

   EXPECT_EQ(Com_IpduGroupStart_fake.call_count, 2);
   EXPECT_EQ(Com_IpduGroupStart_fake.arg0_history[0], ComConf_ComIPduGroup_RDR06_oPCAN_RADAR_Rx_1d1eef94);
   EXPECT_EQ(Com_IpduGroupStart_fake.arg0_history[1], ComConf_ComIPduGroup_RDR06_oPCAN_RADAR_Tx_4b444812);
}

TEST_F(BswMCalloutTest, UserCANComPduGroupHandling_Position7_StartsRDR07Groups)
{
   Get_Radar_Position_fake.return_val = 7;

   User_CAN_ComPduGroupHandling();

   EXPECT_EQ(Com_IpduGroupStart_fake.call_count, 2);
   EXPECT_EQ(Com_IpduGroupStart_fake.arg0_history[0], ComConf_ComIPduGroup_RDR07_oPCAN_RADAR_Rx_b3767e05);
   EXPECT_EQ(Com_IpduGroupStart_fake.arg0_history[1], ComConf_ComIPduGroup_RDR07_oPCAN_RADAR_Tx_e52cd983);
}

TEST_F(BswMCalloutTest, UserCANComPduGroupHandling_Position8_StartsRDR08Groups)
{
   Get_Radar_Position_fake.return_val = 8;

   User_CAN_ComPduGroupHandling();

   EXPECT_EQ(Com_IpduGroupStart_fake.call_count, 2);
   EXPECT_EQ(Com_IpduGroupStart_fake.arg0_history[0], ComConf_ComIPduGroup_RDR08_oPCAN_RADAR_Rx_3d9c193f);
   EXPECT_EQ(Com_IpduGroupStart_fake.arg0_history[1], ComConf_ComIPduGroup_RDR08_oPCAN_RADAR_Tx_6bc6beb9);
}

TEST_F(BswMCalloutTest, UserCANComPduGroupHandling_DefaultPosition_StartsRDR01Groups)
{
   Get_Radar_Position_fake.return_val = 99; // Invalid position

   User_CAN_ComPduGroupHandling();

   EXPECT_EQ(Com_IpduGroupStart_fake.call_count, 2);
   EXPECT_EQ(Com_IpduGroupStart_fake.arg0_history[0], ComConf_ComIPduGroup_RDR01_oPCAN_RADAR_Rx_e0e717e1);
   EXPECT_EQ(Com_IpduGroupStart_fake.arg0_history[1], ComConf_ComIPduGroup_RDR01_oPCAN_RADAR_Tx_b6bdb067);
}

TEST_F(BswMCalloutTest, UserCANComPduGroupHandling_Position0_UsesDefault)
{
   Get_Radar_Position_fake.return_val = 0;

   User_CAN_ComPduGroupHandling();

   EXPECT_EQ(Com_IpduGroupStart_fake.call_count, 2);
   EXPECT_EQ(Com_IpduGroupStart_fake.arg0_history[0], ComConf_ComIPduGroup_RDR01_oPCAN_RADAR_Rx_e0e717e1);
   EXPECT_EQ(Com_IpduGroupStart_fake.arg0_history[1], ComConf_ComIPduGroup_RDR01_oPCAN_RADAR_Tx_b6bdb067);
}

TEST_F(BswMCalloutTest, UserComInit_CallsComInitWithConfig)
{
   User_Com_Init();

   EXPECT_EQ(Com_Init_fake.call_count, 1);
   EXPECT_EQ(Com_Init_fake.arg0_val, EcuM_GlobalPCConfig_Ptr->CfgPtr_Com_Init);
}
