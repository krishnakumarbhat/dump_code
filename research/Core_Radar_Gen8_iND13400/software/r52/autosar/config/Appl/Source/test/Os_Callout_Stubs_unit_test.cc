/**
 * @file Os_Callout_Stubs_unit_test.cc
 * @brief Unit tests for Os_Callout_Stubs.c
 */

#include <gtest/gtest.h>
extern "C"
{
#include "Os_Callout_fakes.h"

   DEFINE_FFF_GLOBALS;

   void StartupHook(void);
   void ShutdownHook(StatusType Fatalerror);
   void ErrorHook(StatusType Error);
   ProtectionReturnType ProtectionHook(StatusType Fatalerror);
   void PreTaskHook(void);
   void PostTaskHook(void);
   void Os_PanicHook(Os_PanicStatusType Status);
}

DEFINE_FAKE_VOID_FUNC(Printf_Information, const char *);
DEFINE_FAKE_VOID_FUNC(FailSafe_Log_ResetReason, uint16_t);
DEFINE_FAKE_VOID_FUNC(EcuM_Shutdown);
DEFINE_FAKE_VALUE_FUNC(StatusType, Os_GetDetailedError, Os_ErrorInformationType *);

class OsCalloutTest : public ::testing::Test
{
 protected:
   void SetUp() override
   {
      RESET_FAKE(Printf_Information);
      RESET_FAKE(FailSafe_Log_ResetReason);
      RESET_FAKE(EcuM_Shutdown);
      RESET_FAKE(Os_GetDetailedError);
      FFF_RESET_HISTORY();
   }
};

TEST_F(OsCalloutTest, StartupHook_DoesNothing)
{
   StartupHook();
   // No assertions - just verify it doesn't crash
}

TEST_F(OsCalloutTest, ShutdownHook_LogsResetReason)
{
   ShutdownHook(0x1234);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, 0x1234);
}

TEST_F(OsCalloutTest, ShutdownHook_CallsEcuMShutdown)
{
   ShutdownHook(0x5678);
   EXPECT_EQ(EcuM_Shutdown_fake.call_count, 1);
}

TEST_F(OsCalloutTest, ErrorHook_ProtectionMemory_LogsError)
{
   Os_ErrorInformationType error        = {E_OS_PROTECTION_MEMORY};
   Os_GetDetailedError_fake.custom_fake = [](Os_ErrorInformationType *err) -> StatusType
   {
      err->DetailedError = E_OS_PROTECTION_MEMORY;
      return 0;
   };

   ErrorHook(0);

   EXPECT_EQ(Os_GetDetailedError_fake.call_count, 1);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, E_OS_PROTECTION_MEMORY);
}

TEST_F(OsCalloutTest, ErrorHook_ProtectionException_LogsError)
{
   Os_GetDetailedError_fake.custom_fake = [](Os_ErrorInformationType *err) -> StatusType
   {
      err->DetailedError = E_OS_PROTECTION_EXCEPTION;
      return 0;
   };

   ErrorHook(0);

   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, E_OS_PROTECTION_EXCEPTION);
}

TEST_F(OsCalloutTest, ErrorHook_SysOverload_DoesNotLog)
{
   Os_GetDetailedError_fake.custom_fake = [](Os_ErrorInformationType *err) -> StatusType
   {
      err->DetailedError = E_OS_SYS_OVERLOAD;
      return 0;
   };

   ErrorHook(0);

   EXPECT_EQ(Os_GetDetailedError_fake.call_count, 1);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 0);
}

TEST_F(OsCalloutTest, ErrorHook_OtherError_LogsError)
{
   const uint32_t OTHER_ERROR           = 0x9999;
   Os_GetDetailedError_fake.custom_fake = [](Os_ErrorInformationType *err) -> StatusType
   {
      err->DetailedError = 0x9999;
      return 0;
   };

   ErrorHook(0);

   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 1);
   EXPECT_EQ(FailSafe_Log_ResetReason_fake.arg0_val, OTHER_ERROR);
}

TEST_F(OsCalloutTest, ProtectionHook_ReturnsShutdown)
{
   ProtectionReturnType result = ProtectionHook(0x1111);
   EXPECT_EQ(result, PRO_SHUTDOWN);
}

TEST_F(OsCalloutTest, PreTaskHook_DoesNothing)
{
   PreTaskHook();
   // No assertions - just verify it doesn't crash
}

TEST_F(OsCalloutTest, PostTaskHook_DoesNothing)
{
   PostTaskHook();
   // No assertions - just verify it doesn't crash
}

TEST_F(OsCalloutTest, Os_PanicHook_DoesNothing)
{
   Os_PanicHook(OS_PANIC_UNKNOWN);
   // No assertions - just verify it doesn't crash
}

TEST_F(OsCalloutTest, MultipleShutdownCalls_AccumulateCallCount)
{
   ShutdownHook(1);
   ShutdownHook(2);
   ShutdownHook(3);

   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 3);
   EXPECT_EQ(EcuM_Shutdown_fake.call_count, 3);
}

TEST_F(OsCalloutTest, ErrorHook_MultipleDifferentErrors_LoggedCorrectly)
{
   Os_GetDetailedError_fake.custom_fake = [](Os_ErrorInformationType *err) -> StatusType
   {
      static int call = 0;
      if (call++ == 0)
         err->DetailedError = E_OS_PROTECTION_MEMORY;
      else
         err->DetailedError = 0x5555;
      return 0;
   };

   ErrorHook(0);
   ErrorHook(0);

   EXPECT_EQ(FailSafe_Log_ResetReason_fake.call_count, 2);
}
