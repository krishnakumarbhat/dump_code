#include "fff.h"
#include <gtest/gtest.h>

extern "C"
{
#include "sh_comm.h"
#include "sh_interface.h"
#include "sh_interface_fff.h"
}

DEFINE_FFF_GLOBALS;

class SH_Interface_Unit_Test_Suite : public testing::Test
{
 protected:
   void SetUp() override
   {
      FFF_FAKES_SH_INTERFACE_LIST(RESET_FAKE);
   }
};
#if 0
/******************************************************************************
 *. Name: ShComm.GetSHOutputDataPtr_ReturnsSharedOutputStorage
 *.    Verifies the module exposes a stable output block for integration code.
 *.
 *. Parameters: void
 *. Return Value: void
 *.
 *. Traceability Information:
 *. Place references to requirements and design IDs here.
 *.
 *. JIRA Issues:
 ******************************************************************************/
TEST(ShComm, GetSHOutputDataPtr_ReturnsSharedOutputStorage)
{
   SH_Output_T *output_ptr = Get_SH_Output_Data_Ptr();

   ASSERT_NE(nullptr, output_ptr);
   output_ptr->sh_stream_error = Get_Stream_Error;

   EXPECT_EQ(output_ptr, Get_SH_Output_Data_Ptr());
   EXPECT_EQ(Get_Stream_Error, Get_SH_Output_Data_Ptr()->sh_stream_error);
}
#endif
TEST_F(SH_Interface_Unit_Test_Suite, Update_SH_Input_Interface_AssignsExpectedFunctionPointers)
{
   SH_Input_T sh_input_data = {0};

   Get_SH_Input_Data_Ptr_fake.return_val = &sh_input_data;

   Update_SH_Input_Interface();

   EXPECT_EQ(Get_Status_Calibration_Disable_CDC_Logging, sh_input_data.calibration_disable_cdc_logging_fptr);
   EXPECT_EQ(Get_XCP_Over_ETH_Status, sh_input_data.xcp_over_eth_status_fptr);
   EXPECT_EQ(DisableAllInterrupts, sh_input_data.disable_allinterrupts_fptr);
   EXPECT_EQ(EnableAllInterrupts, sh_input_data.enable_allinterrupts_fptr);
   EXPECT_EQ(Get_Platform_ustime, sh_input_data.ustime_logging_fptr);
   EXPECT_EQ(Get_Platform_Elapsed_ustime, sh_input_data.elapsed_ustime_logging_fptr);
   EXPECT_EQ(Send_Stream_Internal, sh_input_data.send_stream_internal_fptr);
   EXPECT_EQ(Get_Req_En_Dis_CDC_Stream, sh_input_data.req_en_dis_cdc_stream_fptr);
#ifdef TRACKER_ENABLED
   EXPECT_EQ(Get_Tracker_Ref_Index, sh_input_data.tracker_ref_index_fptr);
#endif
}
