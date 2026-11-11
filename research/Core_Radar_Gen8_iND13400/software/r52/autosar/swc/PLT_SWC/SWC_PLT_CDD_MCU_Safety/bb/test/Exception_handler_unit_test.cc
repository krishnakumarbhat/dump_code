/*===========================================================================*/
/**
 * @file Exception_Handler_mocks.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2022 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for the checking the MCU_Safety.c file
 *
 * @section ABBR ABBREVIATIONS:
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/

#include "fff.h"
#include "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_FailSafe/test/FailSafe_callout_fake.h"
#include <gtest/gtest.h>
/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
// Boot_Shared_Data_T Boot_Shared_Data;
// extern uint32_t __USER_EXCEPTION_STACK_END;
DEFINE_FFF_GLOBALS;
extern "C"
{
#include "Exception_handler.c"

   void Log_ExceptionReason_Info(Dt_Memory_Exception_Info_T *Exception_Context, uint16 Resnum)
   {
      (void)Exception_Context;
      (void)Resnum;
   }
}

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class Exception_HandlerTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *     Method run before each individual test case.
    */
   void SetUp()
   {
      RESET_FAKE(FailSafe_Log_ResetReason);
      FFF_RESET_HISTORY();

      Exception_Context.IsMemException_Occured  = FALSE;
      Exception_Context.ExceptionCausingAddress = 0U;
      Exception_Context.MemoryExceptionAddress  = 0U;
      Exception_Context.ExceptionType           = 0U;
      Exception_Context.StackPointer            = 0U;
      Exception_Context.ExceptionStatusRegister = 0U;

      gException_R14Value  = 0U;
      gException_R13Value  = 0U;
      gException_SPSRValue = 0U;
      gException_IFARValue = 0U;
      gException_DFARValue = 0U;
      gLastCPSRvalue       = 0U;
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

/*===========================================================================*
 * Test Cases
 *===========================================================================*/
TEST_F(Exception_HandlerTestSuite, ExceptionHandler_Illegal_Instruction_SetsContextAndLogsResetReason)
{
   gException_R14Value  = 0x1000U;
   gException_IFARValue = 0x2222U;
   gException_R13Value  = 0x3333U;
   gException_SPSRValue = 0x4444U;

   ExceptionHandler_Illegal_Instruction();

   ASSERT_EQ(1u, FailSafe_Log_ResetReason_fake.call_count);
   ASSERT_EQ(MCU_FAILSAFE_UNDEF_INSTRUCTION_EXCEPTION, FailSafe_Log_ResetReason_fake.arg0_val);
   ASSERT_EQ(FALSE, Exception_Context.IsMemException_Occured);
   ASSERT_EQ(0x0FFEU, Exception_Context.ExceptionCausingAddress);
   ASSERT_EQ(0x2222U, Exception_Context.MemoryExceptionAddress);
   ASSERT_EQ(MCU_FAILSAFE_UNDEF_INSTRUCTION_EXCEPTION, Exception_Context.ExceptionType);
   ASSERT_EQ(0x3333U, Exception_Context.StackPointer);
   ASSERT_EQ(0x4444U, Exception_Context.ExceptionStatusRegister);
}

TEST_F(Exception_HandlerTestSuite, ExceptionHandler_Abort_Prefetch_UsesIFARPath)
{
   gException_R14Value  = 0x2000U;
   gException_IFARValue = 0x1234U;
   gException_DFARValue = 0x5678U;
   gException_R13Value  = 0x1111U;
   gException_SPSRValue = 0x2222U;

   ExceptionHandler_Abort_Prefetch();

   ASSERT_EQ(1u, FailSafe_Log_ResetReason_fake.call_count);
   ASSERT_EQ(MCU_FAILSAFE_ABORT_PREFETCH_EXCEPTION, FailSafe_Log_ResetReason_fake.arg0_val);
   ASSERT_EQ(TRUE, Exception_Context.IsMemException_Occured);
   ASSERT_EQ(0x1FFCU, Exception_Context.ExceptionCausingAddress);
   ASSERT_EQ(0x1234U, Exception_Context.MemoryExceptionAddress);
   ASSERT_EQ(MCU_FAILSAFE_ABORT_PREFETCH_EXCEPTION, Exception_Context.ExceptionType);
   ASSERT_EQ(0x1111U, Exception_Context.StackPointer);
   ASSERT_EQ(0x2222U, Exception_Context.ExceptionStatusRegister);
}

TEST_F(Exception_HandlerTestSuite, ExceptionHandler_Abort_Data_UsesDFARPathWhenIFARIsZero)
{
   gException_R14Value  = 0x3000U;
   gException_IFARValue = 0U;
   gException_DFARValue = 0x5678U;
   gException_R13Value  = 0xAAAAU;
   gException_SPSRValue = 0xBBBBU;

   ExceptionHandler_Abort_Data();

   ASSERT_EQ(1u, FailSafe_Log_ResetReason_fake.call_count);
   ASSERT_EQ(MCU_FAILSAFE_ABORT_DATA_EXCEPTION, FailSafe_Log_ResetReason_fake.arg0_val);
   ASSERT_EQ(TRUE, Exception_Context.IsMemException_Occured);
   ASSERT_EQ(0x2FF8U, Exception_Context.ExceptionCausingAddress);
   ASSERT_EQ(0x5678U, Exception_Context.MemoryExceptionAddress);
   ASSERT_EQ(MCU_FAILSAFE_ABORT_DATA_EXCEPTION, Exception_Context.ExceptionType);
   ASSERT_EQ(0xAAAAU, Exception_Context.StackPointer);
   ASSERT_EQ(0xBBBBU, Exception_Context.ExceptionStatusRegister);
}

TEST_F(Exception_HandlerTestSuite, GetExceptionInfo_ASM_DoesNotChangeValuesInUnitTestBuild)
{
   gException_SPSRValue = 0x1111U;
   gException_IFARValue = 0x2222U;
   gException_DFARValue = 0x3333U;
   gLastCPSRvalue       = 0x4444U;

   GetExceptionInfo_ASM(MCU_FAILSAFE_ABORT_PREFETCH_EXCEPTION);

   ASSERT_EQ(0x1111U, gException_SPSRValue);
   ASSERT_EQ(0x2222U, gException_IFARValue);
   ASSERT_EQ(0x3333U, gException_DFARValue);
   ASSERT_EQ(0x4444U, gLastCPSRvalue);
}

TEST_F(Exception_HandlerTestSuite, GetExceptionInfo_UndefInstruction_SetsExpectedContext)
{
   gException_R14Value  = 0x1000U;
   gException_IFARValue = 0x2000U;
   gException_DFARValue = 0x3000U;
   gException_R13Value  = 0x4000U;
   gException_SPSRValue = 0x5000U;

   GetExceptionInfo(MCU_FAILSAFE_UNDEF_INSTRUCTION_EXCEPTION);

   ASSERT_EQ(FALSE, Exception_Context.IsMemException_Occured);
   ASSERT_EQ(0x0FFEU, Exception_Context.ExceptionCausingAddress);
   ASSERT_EQ(0x2000U, Exception_Context.MemoryExceptionAddress);
   ASSERT_EQ(MCU_FAILSAFE_UNDEF_INSTRUCTION_EXCEPTION, Exception_Context.ExceptionType);
   ASSERT_EQ(0x4000U, Exception_Context.StackPointer);
   ASSERT_EQ(0x5000U, Exception_Context.ExceptionStatusRegister);
}

TEST_F(Exception_HandlerTestSuite, GetExceptionInfo_MemoryException_SetsFaultAddress)
{
   gException_R14Value  = 0x6000U;
   gException_IFARValue = 0x7000U;
   gException_DFARValue = 0x8000U;
   gException_R13Value  = 0x9000U;
   gException_SPSRValue = 0xA000U;

   GetExceptionInfo(MCU_FAILSAFE_ABORT_PREFETCH_EXCEPTION);

   ASSERT_EQ(TRUE, Exception_Context.IsMemException_Occured);
   ASSERT_EQ(0x5FFCU, Exception_Context.ExceptionCausingAddress);
   ASSERT_EQ(0x7000U, Exception_Context.MemoryExceptionAddress);
   ASSERT_EQ(MCU_FAILSAFE_ABORT_PREFETCH_EXCEPTION, Exception_Context.ExceptionType);
   ASSERT_EQ(0x9000U, Exception_Context.StackPointer);
   ASSERT_EQ(0xA000U, Exception_Context.ExceptionStatusRegister);
}

TEST_F(Exception_HandlerTestSuite, Set_Fault_Address_UsesIFAR_WhenIFARIsNonZero)
{
   gException_R14Value  = 0x3000U;
   gException_IFARValue = 0x1234U;
   gException_DFARValue = 0x5678U;

   Set_Fault_Address();

   ASSERT_EQ(0x2FFCU, Exception_Context.ExceptionCausingAddress);
   ASSERT_EQ(0x1234U, Exception_Context.MemoryExceptionAddress);
}

TEST_F(Exception_HandlerTestSuite, Set_Fault_Address_UsesDFAR_WhenIFARIsZero)
{
   gException_R14Value  = 0x3000U;
   gException_IFARValue = 0U;
   gException_DFARValue = 0x5678U;

   Set_Fault_Address();

   ASSERT_EQ(0x2FF8U, Exception_Context.ExceptionCausingAddress);
   ASSERT_EQ(0x5678U, Exception_Context.MemoryExceptionAddress);
}

TEST_F(Exception_HandlerTestSuite, Set_Fault_Address_DoesNothingWhenBothAddressesAreZero)
{
   Exception_Context.ExceptionCausingAddress = 0xAAAAU;
   Exception_Context.MemoryExceptionAddress  = 0xBBBBU;
   gException_IFARValue                      = 0U;
   gException_DFARValue                      = 0U;

   Set_Fault_Address();

   ASSERT_EQ(0xAAAAU, Exception_Context.ExceptionCausingAddress);
   ASSERT_EQ(0xBBBBU, Exception_Context.MemoryExceptionAddress);
}
