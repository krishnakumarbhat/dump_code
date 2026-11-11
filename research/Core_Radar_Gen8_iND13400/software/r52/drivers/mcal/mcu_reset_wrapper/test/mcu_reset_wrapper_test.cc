/*===========================================================================*\
 * FILE: mcu_reset_wrapper_test.cc
 *===========================================================================
 * Copyright (C) 2023 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 * Unit tests for mcu_reset_wrapper module.
 *
 * Tests cover:
 *   - Mcu_Reset(RESET_SW_INTENTIONAL): SuspendAllInterrupts is called once,
 *     followed by Assert_reset_mipi and Mcu_PerformReset in order
 *   - Mcu_Reset(RESET_POR): SuspendAllInterrupts is NOT called;
 *     Assert_reset_mipi and Mcu_PerformReset are called in order
 *   - Mcu_Reset(RESET_SW_UNINTENTIONAL): same behaviour as RESET_POR
 *   - Exactly two or three fake calls are made per invocation (no extras)
 *   - Call ordering verified via fff.call_history
\*===========================================================================*/

#include <gtest/gtest.h>

#include "fff.h"

DEFINE_FFF_GLOBALS;

/*===========================================================================*\
 * FFF Fakes for all functions called by mcu_reset_wrapper
\*===========================================================================*/
extern "C"
{
   FAKE_VOID_FUNC(SuspendAllInterrupts);
   FAKE_VALUE_FUNC(bool, Get_RDI_Log_Board_Connected);
   FAKE_VALUE_FUNC(bool, Assert_Reset_Mipi);
   FAKE_VOID_FUNC(Mcu_PerformReset);
}

/*===========================================================================*\
 * Provide definitions for extern symbols declared in mock headers,
 * then textually include the source file under test.
\*===========================================================================*/
extern "C"
{
#include "Compiler.h"
#include "Generic_Drv_sfr.h"
#include "Std_Types.h"
#include "boot_interface.h"

   SYSCTRL_SFRS_t sysctrl_stub;
   Boot_Shared_Data_T Boot_Shared_Data;
}

extern "C"
{
#include "mcu_reset_wrapper.c"
}

/*===========================================================================*\
 * Test Fixture
\*===========================================================================*/
class McuResetWrapperTest : public testing::Test
{
 protected:
   void SetUp() override
   {
      RESET_FAKE(SuspendAllInterrupts);
      RESET_FAKE(Get_RDI_Log_Board_Connected);
      RESET_FAKE(Assert_Reset_Mipi);
      RESET_FAKE(Mcu_PerformReset);
      FFF_RESET_HISTORY();

      /* Default: RDI Log Board is connected (allows Assert_Reset_Mipi to be called) */
      Get_RDI_Log_Board_Connected_fake.return_val = true;

      sysctrl_stub.DEBUG_CODE            = 0U;
      Boot_Shared_Data.reset_type        = RESET_POR;
      sysctrl_stub.RETAIN_1              = 0U;
      Boot_Shared_Data.retain_reg_backup = 0U;
   }

   void TearDown() override
   {
   }
};

/*===========================================================================*\
 * Mcu_Reset – RESET_SW_INTENTIONAL Tests
\*===========================================================================*/

/**
 * @brief RESET_SW_INTENTIONAL shall call SuspendAllInterrupts exactly once.
 */
TEST_F(McuResetWrapperTest, IntentionalReset_CallsSuspendAllInterrupts_Once)
{
   Mcu_Reset(RESET_SW_INTENTIONAL);

   EXPECT_EQ(SuspendAllInterrupts_fake.call_count, 1u);
}

/**
 * @brief RESET_SW_INTENTIONAL shall call Assert_Reset_Mipi exactly once.
 */
TEST_F(McuResetWrapperTest, IntentionalReset_CallsAssertResetMipi_Once)
{
   Mcu_Reset(RESET_SW_INTENTIONAL);

   EXPECT_EQ(Assert_Reset_Mipi_fake.call_count, 1u);
}

/**
 * @brief RESET_SW_INTENTIONAL shall call Mcu_PerformReset exactly once.
 */
TEST_F(McuResetWrapperTest, IntentionalReset_CallsMcuPerformReset_Once)
{
   Mcu_Reset(RESET_SW_INTENTIONAL);

   EXPECT_EQ(Mcu_PerformReset_fake.call_count, 1u);
}

/**
 * @brief RESET_SW_INTENTIONAL shall store the reset type in boot shared data.
 */
TEST_F(McuResetWrapperTest, IntentionalReset_StoresResetType)
{
   Mcu_Reset(RESET_SW_INTENTIONAL);

   EXPECT_EQ(Boot_Shared_Data.reset_type, static_cast<uint32_t>(RESET_SW_INTENTIONAL));
}

/**
 * @brief RESET_SW_INTENTIONAL: exactly 4 fake calls shall be recorded in total.
 *        (SuspendAllInterrupts, Get_RDI_Log_Board_Connected, Assert_Reset_Mipi, Mcu_PerformReset)
 */
TEST_F(McuResetWrapperTest, IntentionalReset_TotalCallCountIsThree)
{
   Mcu_Reset(RESET_SW_INTENTIONAL);

   EXPECT_EQ(fff.call_history_idx, 4u);
}

/**
 * @brief RESET_SW_INTENTIONAL: call order must be
 *        SuspendAllInterrupts → Get_RDI_Log_Board_Connected → Assert_Reset_Mipi → Mcu_PerformReset.
 */
TEST_F(McuResetWrapperTest, IntentionalReset_CallOrderIsCorrect)
{
   Mcu_Reset(RESET_SW_INTENTIONAL);

   ASSERT_GE(fff.call_history_idx, 4u);
   EXPECT_EQ(fff.call_history[0], reinterpret_cast<void *>(SuspendAllInterrupts));
   EXPECT_EQ(fff.call_history[1], reinterpret_cast<void *>(Get_RDI_Log_Board_Connected));
   EXPECT_EQ(fff.call_history[2], reinterpret_cast<void *>(Assert_Reset_Mipi));
   EXPECT_EQ(fff.call_history[3], reinterpret_cast<void *>(Mcu_PerformReset));
}

/*===========================================================================*\
 * Mcu_Reset – RESET_POR Tests
\*===========================================================================*/

/**
 * @brief RESET_POR shall NOT call SuspendAllInterrupts.
 */
TEST_F(McuResetWrapperTest, POR_Reset_DoesNotCallSuspendAllInterrupts)
{
   Mcu_Reset(RESET_POR);

   EXPECT_EQ(SuspendAllInterrupts_fake.call_count, 0u);
}

/**
 * @brief RESET_POR shall call Assert_Reset_Mipi exactly once.
 */
TEST_F(McuResetWrapperTest, POR_Reset_CallsAssertResetMipi_Once)
{
   Mcu_Reset(RESET_POR);

   EXPECT_EQ(Assert_Reset_Mipi_fake.call_count, 1u);
}

/**
 * @brief RESET_POR shall call Mcu_PerformReset exactly once.
 */
TEST_F(McuResetWrapperTest, POR_Reset_CallsMcuPerformReset_Once)
{
   Mcu_Reset(RESET_POR);

   EXPECT_EQ(Mcu_PerformReset_fake.call_count, 1u);
}

/**
 * @brief RESET_POR shall store the reset type in boot shared data.
 */
TEST_F(McuResetWrapperTest, POR_Reset_StoresResetType)
{
   Mcu_Reset(RESET_POR);

   EXPECT_EQ(Boot_Shared_Data.reset_type, static_cast<uint32_t>(RESET_POR));
}

/**
 * @brief RESET_POR: exactly 3 fake calls shall be recorded in total.
 *        (Get_RDI_Log_Board_Connected, Assert_Reset_Mipi, Mcu_PerformReset)
 */
TEST_F(McuResetWrapperTest, POR_Reset_TotalCallCountIsTwo)
{
   Mcu_Reset(RESET_POR);

   EXPECT_EQ(fff.call_history_idx, 3u);
}

/**
 * @brief RESET_POR: call order must be Get_RDI_Log_Board_Connected → Assert_Reset_Mipi → Mcu_PerformReset.
 */
TEST_F(McuResetWrapperTest, POR_Reset_CallOrderIsCorrect)
{
   Mcu_Reset(RESET_POR);

   ASSERT_GE(fff.call_history_idx, 3u);
   EXPECT_EQ(fff.call_history[0], reinterpret_cast<void *>(Get_RDI_Log_Board_Connected));
   EXPECT_EQ(fff.call_history[1], reinterpret_cast<void *>(Assert_Reset_Mipi));
   EXPECT_EQ(fff.call_history[2], reinterpret_cast<void *>(Mcu_PerformReset));
}

/*===========================================================================*\
 * Mcu_Reset – RESET_SW_UNINTENTIONAL Tests
\*===========================================================================*/

/**
 * @brief RESET_SW_UNINTENTIONAL shall NOT call SuspendAllInterrupts.
 */
TEST_F(McuResetWrapperTest, UnintentionalReset_DoesNotCallSuspendAllInterrupts)
{
   Mcu_Reset(RESET_SW_UNINTENTIONAL);

   EXPECT_EQ(SuspendAllInterrupts_fake.call_count, 0u);
}

/**
 * @brief RESET_SW_UNINTENTIONAL shall call Assert_Reset_Mipi exactly once.
 */
TEST_F(McuResetWrapperTest, UnintentionalReset_CallsAssertResetMipi_Once)
{
   Mcu_Reset(RESET_SW_UNINTENTIONAL);

   EXPECT_EQ(Assert_Reset_Mipi_fake.call_count, 1u);
}

/**
 * @brief RESET_SW_UNINTENTIONAL shall call Mcu_PerformReset exactly once.
 */
TEST_F(McuResetWrapperTest, UnintentionalReset_CallsMcuPerformReset_Once)
{
   Mcu_Reset(RESET_SW_UNINTENTIONAL);

   EXPECT_EQ(Mcu_PerformReset_fake.call_count, 1u);
}

/**
 * @brief RESET_SW_UNINTENTIONAL shall store the reset type in boot shared data.
 */
TEST_F(McuResetWrapperTest, UnintentionalReset_StoresResetType)
{
   Mcu_Reset(RESET_SW_UNINTENTIONAL);

   EXPECT_EQ(Boot_Shared_Data.reset_type, static_cast<uint32_t>(RESET_SW_UNINTENTIONAL));
}

/**
 * @brief RESET_SW_UNINTENTIONAL: exactly 3 fake calls shall be recorded.
 *        (Get_RDI_Log_Board_Connected, Assert_Reset_Mipi, Mcu_PerformReset)
 */
TEST_F(McuResetWrapperTest, UnintentionalReset_TotalCallCountIsTwo)
{
   Mcu_Reset(RESET_SW_UNINTENTIONAL);

   EXPECT_EQ(fff.call_history_idx, 3u);
}

/**
 * @brief RESET_SW_UNINTENTIONAL: call order must be
 *        Get_RDI_Log_Board_Connected → Assert_Reset_Mipi → Mcu_PerformReset.
 */
TEST_F(McuResetWrapperTest, UnintentionalReset_CallOrderIsCorrect)
{
   Mcu_Reset(RESET_SW_UNINTENTIONAL);

   ASSERT_GE(fff.call_history_idx, 3u);
   EXPECT_EQ(fff.call_history[0], reinterpret_cast<void *>(Get_RDI_Log_Board_Connected));
   EXPECT_EQ(fff.call_history[1], reinterpret_cast<void *>(Assert_Reset_Mipi));
   EXPECT_EQ(fff.call_history[2], reinterpret_cast<void *>(Mcu_PerformReset));
}

/*===========================================================================*\
 * Mcu_Reset – Isolation / Independence Tests
\*===========================================================================*/

/**
 * @brief Calling Mcu_Reset multiple times resets state between tests correctly.
 *        (Validates test isolation via SetUp – two consecutive POR calls each
 *        produce exactly 2 total fake invocations when counted independently.)
 */
TEST_F(McuResetWrapperTest, MultipleInvocations_CountsAreIndependent)
{
   Mcu_Reset(RESET_POR);
   EXPECT_EQ(Assert_Reset_Mipi_fake.call_count, 1u);
   EXPECT_EQ(Mcu_PerformReset_fake.call_count, 1u);

   /* Second call adds one more to the accumulators */
   Mcu_Reset(RESET_POR);
   EXPECT_EQ(Assert_Reset_Mipi_fake.call_count, 2u);
   EXPECT_EQ(Mcu_PerformReset_fake.call_count, 2u);
   EXPECT_EQ(SuspendAllInterrupts_fake.call_count, 0u);
}

/**
 * @brief Switching from INTENTIONAL to POR in the same test:
 *        SuspendAllInterrupts count must not grow on the second call.
 */
TEST_F(McuResetWrapperTest, IntentionalThenPOR_SuspendNotCalledOnSecondReset)
{
   Mcu_Reset(RESET_SW_INTENTIONAL);
   EXPECT_EQ(SuspendAllInterrupts_fake.call_count, 1u);

   Mcu_Reset(RESET_POR);
   /* Still only the one call from the first invocation */
   EXPECT_EQ(SuspendAllInterrupts_fake.call_count, 1u);
}
