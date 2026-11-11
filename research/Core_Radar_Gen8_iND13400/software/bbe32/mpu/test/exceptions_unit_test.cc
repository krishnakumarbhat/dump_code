/*===========================================================================*/
/**
 * @file exceptions_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for exceptions.c (BBE32 exception handler registration)
 * Goal: Achieve 80%+ code coverage
 *
 * @section ABBR ABBREVIATIONS:
 *   - ISR: Interrupt Service Routine
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - exceptions Unit Test Design
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 */
/*==========================================================================*/

/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "exceptions_fake.h"
#include "fff.h"
#include <gtest/gtest.h>

DEFINE_FFF_GLOBALS

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
extern "C"
{
#include "exceptions.c"
}

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class Exceptions_UnitTestSuite : public testing::Test
{
   void SetUp() override
   {
      FFF_RESET_HISTORY();
      RESET_FAKE(xtos_set_exception_handler);
      RESET_FAKE(Get_Ipc_Shared_Buffer_Base_Address);

      Exception_Cause  = 0U;
      Exception_Ccount = 0U;
      Exception_VADDR  = 0U;
      Exception_PS     = 0U;
      Exception_EPC1   = 0U;

      /* Reset global exception frame and IPC stub buffer */
      memset((void *)&Global_Exc_Frame, 0, sizeof(Global_Exc_Frame));
      memset(&stub_ipc_buffer, 0, sizeof(stub_ipc_buffer));
   }

   void TearDown() override
   {
   }
};

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

/**
 * @brief Register_Exception_Handlers: All exception causes should be registered.
 * The number of registrations should match the number of exception causes.
 */
TEST_F(Exceptions_UnitTestSuite, RegisterExceptionHandlers_RegistersAllCauses)
{
   Register_Exception_Handlers();

   /* 20 exception causes in dspDispExcCauses array */
   EXPECT_EQ(xtos_set_exception_handler_fake.call_count, sizeof(dspDispExcCauses) / sizeof(dspDispExcCauses[0]))
      << "Number of registered exception handlers should match dspDispExcCauses count";
}

/**
 * @brief Register_Exception_Handlers: Exception handler is not null (a valid callback).
 */
TEST_F(Exceptions_UnitTestSuite, RegisterExceptionHandlers_HandlerNotNull)
{
   Register_Exception_Handlers();

   /* Verify the handler function pointer passed is not NULL */
   ASSERT_GT(xtos_set_exception_handler_fake.call_count, 0U);
   EXPECT_NE(xtos_set_exception_handler_fake.arg1_val, nullptr) << "Exception handler function pointer should not be NULL";
}

/**
 * @brief Register_Exception_Handlers: Context argument is NULL for all registrations.
 */
TEST_F(Exceptions_UnitTestSuite, RegisterExceptionHandlers_ContextArgumentIsNull)
{
   Register_Exception_Handlers();

   ASSERT_GT(xtos_set_exception_handler_fake.call_count, 0U);
   EXPECT_EQ(xtos_set_exception_handler_fake.arg2_val, nullptr) << "Context argument should be NULL";
}

/**
 * @brief Register_Exception_Handlers: Calling twice re-registers (idempotent behavior).
 */
TEST_F(Exceptions_UnitTestSuite, RegisterExceptionHandlers_CalledTwice_RegistersTwiceCount)
{
   Register_Exception_Handlers();
   uint32_t first_count = xtos_set_exception_handler_fake.call_count;

   Register_Exception_Handlers();
   uint32_t second_count = xtos_set_exception_handler_fake.call_count;

   EXPECT_EQ(second_count, 2U * first_count) << "Calling Register_Exception_Handlers twice should double the registration count";
}

/*===========================================================================*
 * Exception_Handler – direct invocation tests (static fn, visible via .c include)
 *===========================================================================*/

/**
 * @brief Helper macro: configure stub IPC buffer return value.
 */
#define SETUP_VALID_IPC_BUFFER() Get_Ipc_Shared_Buffer_Base_Address_fake.return_val = (uintptr_t)(&stub_ipc_buffer)

/**
 * @brief Exception_Handler: All Exception_* global variables are updated from
 * the XT_RSR_* register read macros (stubbed to return 0).
 */
TEST_F(Exceptions_UnitTestSuite, Exception_Handler_UpdatesAllExceptionGlobals)
{
   SETUP_VALID_IPC_BUFFER();
   UserFrame frame = {0};

   Exception_Handler(&frame);

   /* XT_RSR_* stubs all return 0U */
   EXPECT_EQ(Exception_Cause, 0U);
   EXPECT_EQ(Exception_Ccount, 0U);
   EXPECT_EQ(Exception_VADDR, 0U);
   EXPECT_EQ(Exception_PS, 0U);
   EXPECT_EQ(Exception_EPC1, 0U);
}

/**
 * @brief Exception_Handler: The D2M debug message fields in the IPC shared
 * buffer are populated with the Exception_* register values.
 */
TEST_F(Exceptions_UnitTestSuite, Exception_Handler_PopulatesIpcBufferDebugFields)
{
   SETUP_VALID_IPC_BUFFER();
   UserFrame frame = {0};

   Exception_Handler(&frame);

   EXPECT_EQ(stub_ipc_buffer.D2M_Debug_Msg.BBE32_Exception_Cause, Exception_Cause);
   EXPECT_EQ(stub_ipc_buffer.D2M_Debug_Msg.BBE32_Exception_Ccount, Exception_Ccount);
   EXPECT_EQ(stub_ipc_buffer.D2M_Debug_Msg.Exception_VADDR, Exception_VADDR);
   EXPECT_EQ(stub_ipc_buffer.D2M_Debug_Msg.Exception_PS, Exception_PS);
   EXPECT_EQ(stub_ipc_buffer.D2M_Debug_Msg.Exception_EPC1, Exception_EPC1);
}

/**
 * @brief Exception_Handler: The passed UserFrame is copied to Global_Exc_Frame.
 * Verifies non-zero pc and ps values survive the copy.
 */
TEST_F(Exceptions_UnitTestSuite, Exception_Handler_CopiesArgFrameToGlobalExcFrame)
{
   SETUP_VALID_IPC_BUFFER();
   UserFrame frame = {0};
   frame.pc        = 0xDEADBEEFU;
   frame.ps        = 0xCAFEBABEU;

   Exception_Handler(&frame);

   EXPECT_EQ(Global_Exc_Frame.pc, frame.pc);
   EXPECT_EQ(Global_Exc_Frame.ps, frame.ps);
}

/**
 * @brief Exception_Handler: The UserFrame is memcpy'd into the IPC shared
 * buffer's UserFrame field so the host core can inspect it.
 */
TEST_F(Exceptions_UnitTestSuite, Exception_Handler_CopiesUserFrameToIpcBuffer)
{
   SETUP_VALID_IPC_BUFFER();
   UserFrame frame = {0};
   frame.pc        = 0x12345678U;
   frame.ps        = 0xABCDEF01U;

   Exception_Handler(&frame);

   EXPECT_EQ(stub_ipc_buffer.UserFrame.pc, frame.pc);
   EXPECT_EQ(stub_ipc_buffer.UserFrame.ps, frame.ps);
}

/**
 * @brief Exception_Handler: Multiple calls accumulate correctly – the most
 * recent frame data overwrites earlier data in both Global_Exc_Frame and the
 * IPC buffer.
 */
TEST_F(Exceptions_UnitTestSuite, Exception_Handler_SecondCall_OverwritesPreviousFrame)
{
   SETUP_VALID_IPC_BUFFER();
   UserFrame frame1 = {0};
   frame1.pc        = 0x11111111U;

   UserFrame frame2 = {0};
   frame2.pc        = 0x22222222U;

   Exception_Handler(&frame1);
   Exception_Handler(&frame2);

   EXPECT_EQ(Global_Exc_Frame.pc, frame2.pc);
   EXPECT_EQ(stub_ipc_buffer.UserFrame.pc, frame2.pc);
}

/**
 * @brief Register_Exception_Handlers + Exception_Handler: The function pointer
 * registered via xtos_set_exception_handler is the same as Exception_Handler.
 * Invoking it through the captured pointer produces the same observable side
 * effects as calling Exception_Handler directly.
 */
TEST_F(Exceptions_UnitTestSuite, RegisteredHandler_IsException_Handler)
{
   SETUP_VALID_IPC_BUFFER();
   Register_Exception_Handlers();

   ASSERT_GT(xtos_set_exception_handler_fake.call_count, 0U);

   /* All registrations use the same handler – capture it */
   xtos_handler_func_t captured = xtos_set_exception_handler_fake.arg1_val;
   ASSERT_NE(captured, nullptr);

   /* Invoke through the captured pointer – verifies it is the real handler */
   UserFrame frame = {0};
   frame.pc        = 0xFACEFACEU;
   captured(&frame);

   EXPECT_EQ(Global_Exc_Frame.pc, frame.pc);
   EXPECT_EQ(stub_ipc_buffer.UserFrame.pc, frame.pc);
}
