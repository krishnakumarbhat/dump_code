/*===========================================================================*/
/**
 * @file program_flow_monitor_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for program_flow_monitor.c
 * Goal: Achieve 90%+ code coverage
 *
 * Covers:
 *   - PFM_Update_Stage: valid sequential stage transitions
 *   - PFM_Update_Stage: invalid (out-of-order) stage → error path
 *   - PFM_Update_Stage: buffer-index wrapping (buf_idx >= PFM_BUFFER_INDEX)
 *   - PFM_Update_Stage: full cycle wrap (SP_POST → RANGE_CONFIG)
 *   - PFM_Get_Status: returns current flow status
 *   - PFM_Get_Fail_Count: returns accumulated fail count
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - program_flow_monitor Unit Test Design
 *   - Applicable Standards:
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 */
/*==========================================================================*/

/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "fff.h"
#include "program_flow_monitor_fake.h"
#include <gtest/gtest.h>

DEFINE_FFF_GLOBALS

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
extern "C"
{
#include "program_flow_monitor.c"
}

/*===========================================================================*
 * Helper: reset all module-level statics between tests
 *===========================================================================*/
static void ResetPFMState(void)
{
   /* Reset the previous-stage buffer to initial value */
   for (uint32_t i = 0U; i < PFM_BUFFER_INDEX; i++)
   {
      PFM_Prev_Stage[i] = PFM_SYSTEM_INIT_DONE_STAGE;
   }
   PFM_Flow_Status   = PFM_NO_ERROR;
   PFM_Fail_Count    = 0U;
   PFM_Success_Count = 0U;
}

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class ProgramFlowMonitor_UnitTestSuite : public testing::Test
{
 protected:
   void SetUp() override
   {
      FFF_RESET_HISTORY();
      ResetPFMState();
   }

   void TearDown() override
   {
   }
};

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

/**
 * @brief Verify initial status is PFM_NO_ERROR.
 */
TEST_F(ProgramFlowMonitor_UnitTestSuite, PFM_GetStatus_InitialState_ReturnsNoError)
{
   EXPECT_EQ(PFM_Get_Status(), PFM_NO_ERROR);
}

/**
 * @brief Verify initial fail count is 0.
 */
TEST_F(ProgramFlowMonitor_UnitTestSuite, PFM_GetFailCount_InitialState_ReturnsZero)
{
   EXPECT_EQ(PFM_Get_Fail_Count(), 0U);
}

/**
 * @brief Verify initial success count is 0.
 */
TEST_F(ProgramFlowMonitor_UnitTestSuite, PFM_GetSuccessCount_InitialState_ReturnsZero)
{
   EXPECT_EQ(PFM_Get_Success_Count(), 0U);
}

/**
 * @brief Verify PFM_Get_Success_Count reflects manually set value.
 * Because PFM_Success_Count is module-level static (accessible due to
 * direct #include of program_flow_monitor.c), we can write it directly and
 * verify the getter exposes the same value.
 */
TEST_F(ProgramFlowMonitor_UnitTestSuite, PFM_GetSuccessCount_AfterManualSet_ReturnsValue)
{
   PFM_Success_Count = 7U;

   EXPECT_EQ(PFM_Get_Success_Count(), 7U);
}

/**
 * @brief Verify PFM_Get_Success_Count returns uint32_t width (no truncation
 * of a value that would overflow uint16_t).
 */
TEST_F(ProgramFlowMonitor_UnitTestSuite, PFM_GetSuccessCount_LargeValue_NoTruncation)
{
   PFM_Success_Count = 0x00010001U; /* > UINT16_MAX */

   EXPECT_EQ(PFM_Get_Success_Count(), 0x00010001U);
}

/**
 * @brief First valid transition: SYSTEM_INIT_DONE → RANGE_CONFIG_DONE.
 * Verifies that calling PFM_Update_Stage with the correct next stage does NOT set error.
 */
TEST_F(ProgramFlowMonitor_UnitTestSuite, PFM_UpdateStage_ValidFirstTransition_NoError)
{
   PFM_Update_Stage(PFM_RANGE_CONFIG_DONE_STAGE, 0U);

   EXPECT_EQ(PFM_Get_Status(), PFM_NO_ERROR);
   EXPECT_EQ(PFM_Get_Fail_Count(), 0U);
}

/**
 * @brief Full valid sequential cycle: RANGE_CONFIG → RFFT → DFFT → SP_POST.
 * No error should be reported during a correct sequence.
 */
TEST_F(ProgramFlowMonitor_UnitTestSuite, PFM_UpdateStage_ValidFullSequence_NoError)
{
   PFM_Update_Stage(PFM_RANGE_CONFIG_DONE_STAGE, 0U);
   PFM_Update_Stage(PFM_RFFT_DONE_STAGE, 0U);
   PFM_Update_Stage(PFM_DFFT_DONE_STAGE, 0U);
   PFM_Update_Stage(PFM_SP_POST_DONE_STAGE, 0U);

   EXPECT_EQ(PFM_Get_Status(), PFM_NO_ERROR);
   EXPECT_EQ(PFM_Get_Fail_Count(), 0U);
}

/**
 * @brief After SP_POST_DONE, the cycle wraps back to RANGE_CONFIG_DONE (not SYSTEM_INIT).
 * Verifies the wrap-around skip of SYSTEM_INIT_DONE_STAGE.
 */
TEST_F(ProgramFlowMonitor_UnitTestSuite, PFM_UpdateStage_CycleWrap_ValidTransition_NoError)
{
   /* Complete first cycle */
   PFM_Update_Stage(PFM_RANGE_CONFIG_DONE_STAGE, 0U);
   PFM_Update_Stage(PFM_RFFT_DONE_STAGE, 0U);
   PFM_Update_Stage(PFM_DFFT_DONE_STAGE, 0U);
   PFM_Update_Stage(PFM_SP_POST_DONE_STAGE, 0U);

   /* After SP_POST, expected next is RANGE_CONFIG (not SYSTEM_INIT) */
   PFM_Update_Stage(PFM_RANGE_CONFIG_DONE_STAGE, 0U);

   EXPECT_EQ(PFM_Get_Status(), PFM_NO_ERROR);
   EXPECT_EQ(PFM_Get_Fail_Count(), 0U);
}

/**
 * @brief Passing wrong stage triggers invalid flow error.
 * Verifies that an out-of-order stage results in PFM_INVALID_FLOW_ERROR.
 */
TEST_F(ProgramFlowMonitor_UnitTestSuite, PFM_UpdateStage_InvalidStage_SetsErrorStatus)
{
   /* From SYSTEM_INIT_DONE, expected is RANGE_CONFIG_DONE; pass RFFT instead */
   PFM_Update_Stage(PFM_RFFT_DONE_STAGE, 0U);

   EXPECT_EQ(PFM_Get_Status(), PFM_INVALID_FLOW_ERROR);
}

/**
 * @brief Fail count increments on each invalid stage transition.
 */
TEST_F(ProgramFlowMonitor_UnitTestSuite, PFM_UpdateStage_MultipleInvalidStages_IncrementFailCount)
{
   PFM_Update_Stage(PFM_RFFT_DONE_STAGE, 0U);    /* invalid */
   PFM_Update_Stage(PFM_SP_POST_DONE_STAGE, 0U); /* invalid */

   EXPECT_EQ(PFM_Get_Fail_Count(), 2U);
   EXPECT_EQ(PFM_Get_Status(), PFM_INVALID_FLOW_ERROR);
}

/**
 * @brief Buffer index out of bounds wraps via modulo.
 * buf_idx = PFM_BUFFER_INDEX should wrap to index 0.
 */
TEST_F(ProgramFlowMonitor_UnitTestSuite, PFM_UpdateStage_BufIdxWrapsCorrectly_UsesIndex0)
{
   /* buf_idx = PFM_BUFFER_INDEX should be treated as index 0 */
   PFM_Update_Stage(PFM_RANGE_CONFIG_DONE_STAGE, PFM_BUFFER_INDEX);

   EXPECT_EQ(PFM_Get_Status(), PFM_NO_ERROR);
}

/**
 * @brief Large buf_idx value wraps via modulo to a valid slot.
 */
TEST_F(ProgramFlowMonitor_UnitTestSuite, PFM_UpdateStage_LargeBufIdx_WrapsToValidSlot)
{
   /* buf_idx = 100 → 100 % 4 = 0 */
   PFM_Update_Stage(PFM_RANGE_CONFIG_DONE_STAGE, 100U);

   EXPECT_EQ(PFM_Get_Status(), PFM_NO_ERROR);
   EXPECT_EQ(PFM_Get_Fail_Count(), 0U);
}

/**
 * @brief Different buffer slots are independent.
 * A valid transition on slot 1 should not affect slot 0.
 */
TEST_F(ProgramFlowMonitor_UnitTestSuite, PFM_UpdateStage_IndependentBufferSlots)
{
   /* Slot 0: valid transition */
   PFM_Update_Stage(PFM_RANGE_CONFIG_DONE_STAGE, 0U);
   /* Slot 1: also valid from its own initial state */
   PFM_Update_Stage(PFM_RANGE_CONFIG_DONE_STAGE, 1U);

   EXPECT_EQ(PFM_Get_Status(), PFM_NO_ERROR);
   EXPECT_EQ(PFM_Get_Fail_Count(), 0U);
}

/**
 * @brief Invalid transition on slot 1 does not corrupt slot 0.
 */
TEST_F(ProgramFlowMonitor_UnitTestSuite, PFM_UpdateStage_InvalidOnSlot1_DoesNotAffectSlot0)
{
   /* Slot 0: valid */
   PFM_Update_Stage(PFM_RANGE_CONFIG_DONE_STAGE, 0U);
   /* Slot 1: invalid */
   PFM_Update_Stage(PFM_SP_POST_DONE_STAGE, 1U);

   EXPECT_EQ(PFM_Get_Fail_Count(), 1U);

   /* Slot 0 can still progress validly */
   PFM_Flow_Status = PFM_NO_ERROR;
   PFM_Update_Stage(PFM_RFFT_DONE_STAGE, 0U);
   EXPECT_EQ(PFM_Get_Status(), PFM_NO_ERROR);
}

/**
 * @brief PFM_Get_Status reflects the most recent error state.
 */
TEST_F(ProgramFlowMonitor_UnitTestSuite, PFM_GetStatus_AfterError_ReturnsInvalidFlowError)
{
   PFM_Update_Stage(PFM_SP_POST_DONE_STAGE, 0U); /* invalid */
   EXPECT_EQ(PFM_Get_Status(), PFM_INVALID_FLOW_ERROR);
}

/**
 * @brief Verify the SYSTEM_INIT_DONE stage is never a valid update target
 *        after the initial state (cycle should skip it and return RANGE_CONFIG).
 */
TEST_F(ProgramFlowMonitor_UnitTestSuite, PFM_UpdateStage_SystemInitNotValidAfterSPPost_SetsError)
{
   /* Complete a cycle */
   PFM_Update_Stage(PFM_RANGE_CONFIG_DONE_STAGE, 0U);
   PFM_Update_Stage(PFM_RFFT_DONE_STAGE, 0U);
   PFM_Update_Stage(PFM_DFFT_DONE_STAGE, 0U);
   PFM_Update_Stage(PFM_SP_POST_DONE_STAGE, 0U);

   /* After SP_POST, SYSTEM_INIT_DONE is NOT a valid update (cycle skips it) */
   PFM_Update_Stage(PFM_SYSTEM_INIT_DONE_STAGE, 0U);
   EXPECT_EQ(PFM_Get_Status(), PFM_INVALID_FLOW_ERROR);
}
