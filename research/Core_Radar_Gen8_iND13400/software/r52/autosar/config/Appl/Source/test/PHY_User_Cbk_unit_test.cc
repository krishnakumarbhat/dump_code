/**
 * @file PHY_User_Cbk_unit_test.cc
 * @brief Unit tests for PHY_User_Cbk.c
 */

#include <gtest/gtest.h>
extern "C"
{
#include "PHY_User_Cbk_fakes.h"

   DEFINE_FFF_GLOBALS;

   void RTL_PHY_Pre_Init(uint8_t TrcvIdx);
   void RTL_PHY_Post_Init(uint8_t TrcvIdx);
}

DEFINE_FAKE_VALUE_FUNC(uint16_t, EthTrcv_30_Rtl9010_Internal_WriteTrcvReg, uint8_t, uint8_t, uint16_t);
DEFINE_FAKE_VALUE_FUNC(uint16_t, EthTrcv_30_Rtl9010_Internal_ReadTrcvReg, uint8_t, uint8_t, uint16_t *);
DEFINE_FAKE_VALUE_FUNC(uint16_t, RTL9010x_Set_OP_state, uint16_t);

class PHYUserCbkTest : public ::testing::Test
{
 protected:
   void SetUp() override
   {
      RESET_FAKE(EthTrcv_30_Rtl9010_Internal_WriteTrcvReg);
      RESET_FAKE(EthTrcv_30_Rtl9010_Internal_ReadTrcvReg);
      RESET_FAKE(RTL9010x_Set_OP_state);
      FFF_RESET_HISTORY();

      RTL9010x_Set_OP_state_fake.return_val = SUCCESS;
   }
};

TEST_F(PHYUserCbkTest, PreInit_CallsSetOPState_WithNormalMode)
{
   RTL_PHY_Pre_Init(0);

   EXPECT_EQ(RTL9010x_Set_OP_state_fake.call_count, 1);
   EXPECT_EQ(RTL9010x_Set_OP_state_fake.arg0_val, OP_CMD_GOTO_NORMAL);
}

TEST_F(PHYUserCbkTest, PreInit_WithSuccessReturn)
{
   RTL9010x_Set_OP_state_fake.return_val = SUCCESS;

   RTL_PHY_Pre_Init(0);

   EXPECT_EQ(RTL9010x_Set_OP_state_fake.call_count, 1);
}

TEST_F(PHYUserCbkTest, PreInit_WithErrorReturn)
{
   RTL9010x_Set_OP_state_fake.return_val = ERROR;

   RTL_PHY_Pre_Init(0);

   EXPECT_EQ(RTL9010x_Set_OP_state_fake.call_count, 1);
}

TEST_F(PHYUserCbkTest, PreInit_WithDifferentTrcvIdx)
{
   RTL_PHY_Pre_Init(1);

   EXPECT_EQ(RTL9010x_Set_OP_state_fake.call_count, 1);
}

TEST_F(PHYUserCbkTest, PostInit_IsEmpty_NoAutosarCalls)
{
   RTL_PHY_Post_Init(0);

   EXPECT_EQ(EthTrcv_30_Rtl9010_Internal_WriteTrcvReg_fake.call_count, 0);
   EXPECT_EQ(EthTrcv_30_Rtl9010_Internal_ReadTrcvReg_fake.call_count, 0);
   EXPECT_EQ(RTL9010x_Set_OP_state_fake.call_count, 0);
}
