#include <gtest/gtest.h>

extern "C"
{
#include "Rte_SWC_Appl_Project.h"
#include "SWC_Appl_Project_fake.h"
}

namespace
{
constexpr uint8 kSelectPosGndEn   = 0x01U;
constexpr uint8 kOutputStateHigh  = 0x11U;
constexpr uint8 kOutputStateLow   = 0x10U;
constexpr uint8 kOutputStateOther = 0x00U;

Std_ReturnType ReadXcpSetOutputHigh(Dt_XCP_Set_Output *data)
{
   data->xcp_set_output_state  = kOutputStateHigh;
   data->xcp_set_output_select = kSelectPosGndEn;
   return RTE_E_OK;
}

Std_ReturnType ReadXcpSetOutputLow(Dt_XCP_Set_Output *data)
{
   data->xcp_set_output_state  = kOutputStateLow;
   data->xcp_set_output_select = kSelectPosGndEn;
   return RTE_E_OK;
}

Std_ReturnType ReadXcpSetOutputUnselected(Dt_XCP_Set_Output *data)
{
   data->xcp_set_output_state  = kOutputStateHigh;
   data->xcp_set_output_select = kOutputStateOther;
   return RTE_E_OK;
}

Std_ReturnType ReadXcpSetOutputUnsupportedState(Dt_XCP_Set_Output *data)
{
   data->xcp_set_output_state  = kOutputStateOther;
   data->xcp_set_output_select = kSelectPosGndEn;
   return RTE_E_OK;
}
} // namespace

class SWC_PRJ_Appl_Project_UnitTestSuite : public testing::Test
{
 protected:
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      RESET_FAKE(Rte_Read_SWC_Appl_Project_Rp_XCP_Set_Output_State_De_XCP_Set_Output);
      RESET_FAKE(Dio_WriteChannel);
      FFF_RESET_HISTORY();
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

TEST_F(SWC_PRJ_Appl_Project_UnitTestSuite, Main50msWritesHighWhenPosGndOutputIsHigh)
{
   Rte_Read_SWC_Appl_Project_Rp_XCP_Set_Output_State_De_XCP_Set_Output_fake.custom_fake = ReadXcpSetOutputHigh;

   RE_Appl_Project_Main_50ms();

   EXPECT_EQ(Rte_Read_SWC_Appl_Project_Rp_XCP_Set_Output_State_De_XCP_Set_Output_fake.call_count, 1U);
   EXPECT_EQ(Dio_WriteChannel_fake.call_count, 1U);
   EXPECT_EQ(Dio_WriteChannel_fake.arg0_val, static_cast<Dio_ChannelType>(DioConf_DioChannel_A2_A3_POS_GND_EN));
   EXPECT_EQ(Dio_WriteChannel_fake.arg1_val, STD_HIGH);
}

TEST_F(SWC_PRJ_Appl_Project_UnitTestSuite, Main50msWritesLowWhenPosGndOutputIsLow)
{
   Rte_Read_SWC_Appl_Project_Rp_XCP_Set_Output_State_De_XCP_Set_Output_fake.custom_fake = ReadXcpSetOutputLow;

   RE_Appl_Project_Main_50ms();

   EXPECT_EQ(Rte_Read_SWC_Appl_Project_Rp_XCP_Set_Output_State_De_XCP_Set_Output_fake.call_count, 1U);
   EXPECT_EQ(Dio_WriteChannel_fake.call_count, 1U);
   EXPECT_EQ(Dio_WriteChannel_fake.arg0_val, static_cast<Dio_ChannelType>(DioConf_DioChannel_A2_A3_POS_GND_EN));
   EXPECT_EQ(Dio_WriteChannel_fake.arg1_val, STD_LOW);
}

TEST_F(SWC_PRJ_Appl_Project_UnitTestSuite, Main50msDoesNotWriteWhenOutputSelectDoesNotMatch)
{
   Rte_Read_SWC_Appl_Project_Rp_XCP_Set_Output_State_De_XCP_Set_Output_fake.custom_fake = ReadXcpSetOutputUnselected;

   RE_Appl_Project_Main_50ms();

   EXPECT_EQ(Rte_Read_SWC_Appl_Project_Rp_XCP_Set_Output_State_De_XCP_Set_Output_fake.call_count, 1U);
   EXPECT_EQ(Dio_WriteChannel_fake.call_count, 0U);
}

TEST_F(SWC_PRJ_Appl_Project_UnitTestSuite, Main50msDoesNotWriteWhenOutputStateIsUnsupported)
{
   Rte_Read_SWC_Appl_Project_Rp_XCP_Set_Output_State_De_XCP_Set_Output_fake.custom_fake = ReadXcpSetOutputUnsupportedState;

   RE_Appl_Project_Main_50ms();

   EXPECT_EQ(Rte_Read_SWC_Appl_Project_Rp_XCP_Set_Output_State_De_XCP_Set_Output_fake.call_count, 1U);
   EXPECT_EQ(Dio_WriteChannel_fake.call_count, 0U);
}

TEST_F(SWC_PRJ_Appl_Project_UnitTestSuite, FaultInjectionRunnableExecutes)
{
   CS_Signal_Integrity_Fault_Injection_Read(0x12U, 0x34U);
   SUCCEED();
}
