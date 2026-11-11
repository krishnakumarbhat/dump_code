#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../src/OLP_wrapper.cpp"
#include "OLP_wrapper.h"
#include "f360_radar_tracker.h"
#include "fff.h"

F360_Host_Calib_T F360_Host_Calib_stub;
F360_Host_T F360_Host_stub;
F360_Object_Log_Output_T SAE_Object_Log;
D2M_Msg_T IPC_D2M_Msg_Buffer_stub;

extern "C"
{
#include "ipc.h"
}

DEFINE_FFF_GLOBALS;

void OLP_Init(void)
{
}

Olp_Calibration_T Olp_Cals;
Olp_Calibration_T *Olp_Get_Cal_Ptr(void)
{
   return (&Olp_Cals);
}

void OLP_Main_Run_50ms(Olp_Data_T *olp_data_ptr)
{
}

D2M_Msg_T *Get_SP_Post_Proc_IPC_D2M_Msg_Buffer(void)
{
   return &IPC_D2M_Msg_Buffer_stub;
}

// FAKE_VALUE_FUNC(uint8_t *, Get_F360_Reduced_Objects_Log_Data_Ptr);
//  FAKE_VALUE_FUNC(Olp_Calibration_T *, Olp_Get_Cal_Ptr);

extern "C"
{
   uint32_t timing_helpers_get_time_usec(void)
   {
      uint32_t value;
      return value;
   }
}

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class OLP_Wrapper_unit_test : public testing::Test
{
   void SetUp() override
   {
      std::cout << "Setup called\n";
   }

   void TearDown() override
   {
      std::cout << "Teardown called\n";
   }
};

TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_01)
{
   olp_Init();
}

Olp_Data_T olp_data_ref;

TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_02)
{
   OLP_Update_Vehicle_Data(olp_data_ref);
}

Olp_Calibration_T Olp_Cals_Cust_ptr;
TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_03)
{
   OLP_Update_Customer_Cals(&Olp_Cals_Cust_ptr);
}

float time_since_created = 2;
TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_04)
{
   unsigned char ret_val;

   ret_val = getAge(time_since_created);
   EXPECT_EQ(ret_val, 40.0);
}

uint8_t Status;
TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_05)
{
   F360_Map_Object_Status(Status);
}

TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_05_1)
{
   F360_Map_Object_Status(1);
}

TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_05_2)
{
   F360_Map_Object_Status(2);
}

TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_05_3)
{
   F360_Map_Object_Status(3);
}

TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_05_4)
{
   F360_Map_Object_Status(4);
}

TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_05_5)
{
   F360_Map_Object_Status(5);
}
TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_05_6)
{
   F360_Map_Object_Status(6);
}

uint8_t Class;
TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_06)
{
   F360_Map_Object_Class(Class);
}

TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_06_1)
{
   F360_Map_Object_Class(1);
}

TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_06_2)
{
   F360_Map_Object_Class(2);
}

TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_06_3)
{
   F360_Map_Object_Class(3);
}

TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_06_4)
{
   F360_Map_Object_Class(4);
}

TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_06_5)
{
   F360_Map_Object_Class(5);
}

TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_06_6)
{
   F360_Map_Object_Class(6);
}

TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_06_7)
{
   F360_Map_Object_Class(7);
}

TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_06_8)
{
   F360_Map_Object_Class(8);
}

TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_06_9)
{
   F360_Map_Object_Class(9);
}

TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_06_10)
{
   F360_Map_Object_Class(10);
}

TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_06_11)
{
   F360_Map_Object_Class(11);
}

TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_07)
{
   F360_Object_Log_Output_T f360_Obj;
   Olp_Data_T olp_data_ref;
   f360_Obj.object[0].reducedID = 10;
   f360_Obj.object[0].f_moving  = 1;

   OLP_Update_Object_Data(f360_Obj, olp_data_ref);
}

TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_08)
{
   Olp_Data_T olp_data_ref;
   Olp_Stream_T olp_objects_log_ptr;
   OLP_Log_Object_Data(olp_data_ref);
}

TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_09)
{
   Get_Olp_Objects_Data();
}

// TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_10)
// {
//    Mem_Pool_T mem_pool;
//    Feature_Handler_OLP_Wrapper_Memory_Init(&mem_pool);
// }

TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_10)
{
   Olp_Main();
}
// TEST_F(OLP_Wrapper_unit_test, UT_OLP_TC_07)
// {
// 	Reduced_Objects_Log_T x;
// 	Reduced_Objects_Log_T *F360_Reduced_Objects = &x;
// 	Olp_Main_Hook();
// }
