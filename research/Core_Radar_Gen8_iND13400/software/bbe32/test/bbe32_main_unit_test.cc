/*===========================================================================*/
/**
 * @file bbe32_main_unit_test.cc
 *
 * Unit tests for software/bbe32/main.c
 */
/*==========================================================================*/

#include <chrono>
#include <thread>

#include <gtest/gtest.h>

#include "bbe32_main_fake.h"
#include "fff.h"

DEFINE_FFF_GLOBALS;

/* Define FFF fakes (storage for _fake structs and _reset functions) */
extern "C"
{
   DEFINE_FAKE_VOID_FUNC(Register_Exception_Handlers);
   DEFINE_FAKE_VALUE_FUNC(bool, Mpu_Initialize);
   DEFINE_FAKE_VOID_FUNC(Read_Mpu_Configuration);
   DEFINE_FAKE_VOID_FUNC(Main_Application);
   DEFINE_FAKE_VOID_FUNC(xtos_memep_initrams);
   DEFINE_FAKE_VOID_FUNC(xtos_memep_enable, int);
   DEFINE_FAKE_VALUE_FUNC(uint16_t, Get_Current_Lookindex);
}

/* Rename main() to avoid conflict with the gtest runner's main() */
#define main bbe32_main_entry

extern "C"
{
#include "main.c"
}

#undef main

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class bbe32_main_UnitTestSuite : public ::testing::Test
{
   void SetUp() override
   {
      FFF_RESET_HISTORY();
      RESET_FAKE(Register_Exception_Handlers);
      RESET_FAKE(Mpu_Initialize);
      RESET_FAKE(Read_Mpu_Configuration);
      RESET_FAKE(Main_Application);
      RESET_FAKE(xtos_memep_initrams);
      RESET_FAKE(xtos_memep_enable);
      RESET_FAKE(Get_Current_Lookindex);
   }

   void TearDown() override
   {
   }
};

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

TEST_F(bbe32_main_UnitTestSuite, bbe32_main__Config__SANITY_CHECK_)
{
   ASSERT_EQ(true, true);
}

TEST_F(bbe32_main_UnitTestSuite, main_MpuInitSuccess_CallsAllFunctions)
{
   /* Arrange: MPU initialisation succeeds */
   Mpu_Initialize_fake.return_val = true;

   /* Act */
   bbe32_main_entry();

   /* Assert */
   EXPECT_EQ(Register_Exception_Handlers_fake.call_count, 1U);
   EXPECT_EQ(Mpu_Initialize_fake.call_count, 1U);
   EXPECT_EQ(Read_Mpu_Configuration_fake.call_count, 1U);
   EXPECT_EQ(Main_Application_fake.call_count, 1U);
}

TEST_F(bbe32_main_UnitTestSuite, main_InitializesMemoryEccBeforeExceptionHandlers)
{
   Mpu_Initialize_fake.return_val = true;

   bbe32_main_entry();

   EXPECT_EQ(xtos_memep_initrams_fake.call_count, 1U);
   EXPECT_EQ(xtos_memep_enable_fake.call_count, 1U);
   EXPECT_EQ(xtos_memep_enable_fake.arg0_val, 0);
   ASSERT_GE(fff.call_history_idx, 4U);
   EXPECT_EQ(fff.call_history[0], (void *)xtos_memep_initrams);
   EXPECT_EQ(fff.call_history[1], (void *)xtos_memep_enable);
   EXPECT_EQ(fff.call_history[2], (void *)Register_Exception_Handlers);
}

TEST_F(bbe32_main_UnitTestSuite, main_MpuInitSuccess_ReturnZero)
{
   Mpu_Initialize_fake.return_val = true;

   int result = bbe32_main_entry();

   EXPECT_EQ(result, 0);
}

TEST_F(bbe32_main_UnitTestSuite, main_RegisterExceptionHandlers_CalledFirst)
{
   Mpu_Initialize_fake.return_val = true;

   bbe32_main_entry();

   /* Memory ECC initialization and exception registration precede MPU setup. */
   ASSERT_GE(fff.call_history_idx, 4U);
   EXPECT_EQ(fff.call_history[2], (void *)Register_Exception_Handlers);
   EXPECT_EQ(fff.call_history[3], (void *)Mpu_Initialize);
}

/* Mpu_Initialize returns false — the main() must halt in the while(1) safety
 * loop and must NOT call Read_Mpu_Configuration or Main_Application.
 * The call is driven in a detached thread so the test runner is not blocked. */
TEST_F(bbe32_main_UnitTestSuite, main_MpuInitFail_HaltsAndDoesNotCallDownstream)
{
   /* Arrange: MPU initialisation fails */
   Mpu_Initialize_fake.return_val = false;

   /* Act: run entry point in a separate thread — it will spin in while(1) */
   std::thread t([]() { bbe32_main_entry(); });

   /* Give the thread enough time to reach (and stay inside) the halt loop */
   std::this_thread::sleep_for(std::chrono::milliseconds(50));

   /* Assert: downstream functions must never have been invoked */
   EXPECT_EQ(Register_Exception_Handlers_fake.call_count, 1U);
   EXPECT_EQ(Mpu_Initialize_fake.call_count, 1U);
   EXPECT_EQ(Read_Mpu_Configuration_fake.call_count, 0U);
   EXPECT_EQ(Main_Application_fake.call_count, 0U);

   /* Detach: the thread is intentionally stuck in the safety while(1) loop;
    * it will be cleaned up when the test binary exits. */
   t.detach();
}
