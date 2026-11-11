/*===========================================================================*\
 * FILE: dd_cmu_unit_test.cc
 *===========================================================================
 * Copyright (C) 2026 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 * Unit tests for dd_cmu module (Clock Monitoring Unit).
 *
 * Tests cover CMU_Init():
 *   - Sets CTL_CKDET_ENA_MASK in ADDR_CLK_REF_FAIL_DETECTOR
 *   - Sets all four detector-enable bits in ADDR_CTL_ADD_FAIL_DETECTOR
 *     (CTL_CKSYS_DET_ENA_MASK, CTL_CKDSP_DET_ENA_MASK,
 *      CTL_CKRA_DET_ENA_MASK, CTL_CKMIPI_DET_ENA_MASK)
 *   - Sets CTL_CKSER_DET_ENA_MASK in ADDR_CLKGEN_CTRL0
 *   - Preserves pre-existing bits in all three registers (OR semantics)
 *   - Does not write beyond the specified masks (from zero start)
 *   - Is idempotent when called multiple times
 *
 * Strategy: the hardware-register macros in dd_cmu.h dereference physical
 * addresses.  We include dd_cmu.h inside a single extern "C" block (so
 * CMU_Init has C linkage throughout), then #undef and redefine the three
 * register macros to alias file-scope stub variables before including the
 * source.  dd_cmu.c's subsequent #include "dd_cmu.h" is a no-op (guard
 * already set), so the overrides remain in effect for the function body.
\*===========================================================================*/

#include <gtest/gtest.h>
#include <stdint.h>

/*===========================================================================*\
 * Declare host-side stub variables at file scope.
 * These stand in for the physical memory-mapped registers.
\*===========================================================================*/
static volatile uint32_t stub_clk_ref_fail_detector;
static volatile uint32_t stub_ctl_add_fail_detector;
static volatile uint32_t stub_clkgen_ctrl0;

/*===========================================================================*\
 * Include the real header, override the hardware-address macros, then
 * textually include the source - all inside one extern "C" block so that
 * CMU_Init() carries C linkage for both its declaration and definition.
\*===========================================================================*/
extern "C"
{
/* Step 1: include real header - triggers include guard and makes mask
 *         constants visible; CMU_Init() is declared with C linkage here. */
#include "dd_cmu.h"

/* Step 2: redirect the three register macros to our stub variables. */
#undef ADDR_CLK_REF_FAIL_DETECTOR
#undef ADDR_CTL_ADD_FAIL_DETECTOR
#undef ADDR_CLKGEN_CTRL0

#define ADDR_CLK_REF_FAIL_DETECTOR (stub_clk_ref_fail_detector)
#define ADDR_CTL_ADD_FAIL_DETECTOR (stub_ctl_add_fail_detector)
#define ADDR_CLKGEN_CTRL0          (stub_clkgen_ctrl0)

/* Step 3: include source under test - dd_cmu.h re-include is a no-op
 *         (include guard), so our overrides remain active. */
#include "dd_cmu.c"
}

/*===========================================================================*\
 * Mask constant aliases - brought in from dd_cmu.h above; referenced
 * in test assertions for readability.
\*===========================================================================*/

/*===========================================================================*\
 * Test Fixture
\*===========================================================================*/
class CMU_InitTest : public testing::Test
{
 protected:
   void SetUp() override
   {
      stub_clk_ref_fail_detector = 0U;
      stub_ctl_add_fail_detector = 0U;
      stub_clkgen_ctrl0          = 0U;
   }

   void TearDown() override
   {
   }
};

/*===========================================================================*\
 * ADDR_CLK_REF_FAIL_DETECTOR Tests
\*===========================================================================*/

/**
 * @brief CMU_Init shall set CTL_CKDET_ENA_MASK in the reference-clock
 *        failure-detector register when the register starts cleared.
 */
TEST_F(CMU_InitTest, CMU_Init_SetsRefClockDetectorEnableBit)
{
   CMU_Init();

   EXPECT_EQ(stub_clk_ref_fail_detector & CTL_CKDET_ENA_MASK, CTL_CKDET_ENA_MASK);
}

/**
 * @brief CMU_Init shall not modify bits other than CTL_CKDET_ENA_MASK in
 *        the reference-clock failure-detector register (from a zero start).
 */
TEST_F(CMU_InitTest, CMU_Init_OnlySetsExpectedBit_InRefClockDetectorRegister)
{
   CMU_Init();

   EXPECT_EQ(stub_clk_ref_fail_detector & ~CTL_CKDET_ENA_MASK, 0U);
}

/**
 * @brief CMU_Init shall preserve pre-existing bits in the reference-clock
 *        failure-detector register (OR semantics).
 */
TEST_F(CMU_InitTest, CMU_Init_PreservesExistingBits_InRefClockDetectorRegister)
{
   const uint32_t existing_bits = 0xFFFFFFFEU; /* all bits except bit 0 */
   stub_clk_ref_fail_detector   = existing_bits;

   CMU_Init();

   EXPECT_EQ(stub_clk_ref_fail_detector, existing_bits | CTL_CKDET_ENA_MASK);
}

/*===========================================================================*\
 * ADDR_CTL_ADD_FAIL_DETECTOR Tests
\*===========================================================================*/

/**
 * @brief CMU_Init shall set CTL_CKSYS_DET_ENA_MASK in the additional
 *        failure-detector register.
 */
TEST_F(CMU_InitTest, CMU_Init_SetsSysClockDetectorEnableBit)
{
   CMU_Init();

   EXPECT_EQ(stub_ctl_add_fail_detector & CTL_CKSYS_DET_ENA_MASK, CTL_CKSYS_DET_ENA_MASK);
}

/**
 * @brief CMU_Init shall set CTL_CKDSP_DET_ENA_MASK in the additional
 *        failure-detector register.
 */
TEST_F(CMU_InitTest, CMU_Init_SetsDspClockDetectorEnableBit)
{
   CMU_Init();

   EXPECT_EQ(stub_ctl_add_fail_detector & CTL_CKDSP_DET_ENA_MASK, CTL_CKDSP_DET_ENA_MASK);
}

/**
 * @brief CMU_Init shall set CTL_CKRA_DET_ENA_MASK in the additional
 *        failure-detector register.
 */
TEST_F(CMU_InitTest, CMU_Init_SetsRaClockDetectorEnableBit)
{
   CMU_Init();

   EXPECT_EQ(stub_ctl_add_fail_detector & CTL_CKRA_DET_ENA_MASK, CTL_CKRA_DET_ENA_MASK);
}

/**
 * @brief CMU_Init shall set CTL_CKMIPI_DET_ENA_MASK in the additional
 *        failure-detector register.
 */
TEST_F(CMU_InitTest, CMU_Init_SetsMipiClockDetectorEnableBit)
{
   CMU_Init();

   EXPECT_EQ(stub_ctl_add_fail_detector & CTL_CKMIPI_DET_ENA_MASK, CTL_CKMIPI_DET_ENA_MASK);
}

/**
 * @brief CMU_Init shall set all four detector-enable bits in the additional
 *        failure-detector register in a single call.
 */
TEST_F(CMU_InitTest, CMU_Init_SetsAllAddFailDetectorBitsSimultaneously)
{
   const uint32_t expected_mask =
      CTL_CKSYS_DET_ENA_MASK | CTL_CKDSP_DET_ENA_MASK | CTL_CKRA_DET_ENA_MASK | CTL_CKMIPI_DET_ENA_MASK;

   CMU_Init();

   EXPECT_EQ(stub_ctl_add_fail_detector & expected_mask, expected_mask);
}

/**
 * @brief CMU_Init shall not modify bits beyond the four expected masks in
 *        the additional failure-detector register (from a zero start).
 */
TEST_F(CMU_InitTest, CMU_Init_OnlySetsExpectedBits_InAddFailDetectorRegister)
{
   const uint32_t expected_mask =
      CTL_CKSYS_DET_ENA_MASK | CTL_CKDSP_DET_ENA_MASK | CTL_CKRA_DET_ENA_MASK | CTL_CKMIPI_DET_ENA_MASK;

   CMU_Init();

   EXPECT_EQ(stub_ctl_add_fail_detector & ~expected_mask, 0U);
}

/**
 * @brief CMU_Init shall preserve pre-existing bits in the additional
 *        failure-detector register (OR semantics).
 */
TEST_F(CMU_InitTest, CMU_Init_PreservesExistingBits_InAddFailDetectorRegister)
{
   const uint32_t existing_bits = 0xFFFF0000U;
   const uint32_t expected_mask =
      CTL_CKSYS_DET_ENA_MASK | CTL_CKDSP_DET_ENA_MASK | CTL_CKRA_DET_ENA_MASK | CTL_CKMIPI_DET_ENA_MASK;
   stub_ctl_add_fail_detector = existing_bits;

   CMU_Init();

   EXPECT_EQ(stub_ctl_add_fail_detector, existing_bits | expected_mask);
}

/*===========================================================================*\
 * ADDR_CLKGEN_CTRL0 Tests
\*===========================================================================*/

/**
 * @brief CMU_Init shall set CTL_CKSER_DET_ENA_MASK in the CLKGEN_CTRL0
 *        register.
 */
TEST_F(CMU_InitTest, CMU_Init_SetsSerdesClockDetectorEnableBit)
{
   CMU_Init();

   EXPECT_EQ(stub_clkgen_ctrl0 & CTL_CKSER_DET_ENA_MASK, CTL_CKSER_DET_ENA_MASK);
}

/**
 * @brief CMU_Init shall not modify bits other than CTL_CKSER_DET_ENA_MASK
 *        in the CLKGEN_CTRL0 register (from a zero start).
 */
TEST_F(CMU_InitTest, CMU_Init_OnlySetsExpectedBit_InClkgenCtrl0Register)
{
   CMU_Init();

   EXPECT_EQ(stub_clkgen_ctrl0 & ~CTL_CKSER_DET_ENA_MASK, 0U);
}

/**
 * @brief CMU_Init shall preserve pre-existing bits in the CLKGEN_CTRL0
 *        register (OR semantics).
 */
TEST_F(CMU_InitTest, CMU_Init_PreservesExistingBits_InClkgenCtrl0Register)
{
   const uint32_t existing_bits = ~CTL_CKSER_DET_ENA_MASK; /* all bits except serdes mask */
   stub_clkgen_ctrl0            = existing_bits;

   CMU_Init();

   EXPECT_EQ(stub_clkgen_ctrl0, existing_bits | CTL_CKSER_DET_ENA_MASK);
}

/*===========================================================================*\
 * Idempotency / Multiple-call Tests
\*===========================================================================*/

/**
 * @brief CMU_Init shall be idempotent: calling it a second time must not
 *        change the register values already written by the first call.
 */
TEST_F(CMU_InitTest, CMU_Init_IsIdempotent_WhenCalledMultipleTimes)
{
   CMU_Init();

   const uint32_t after_first_ref  = stub_clk_ref_fail_detector;
   const uint32_t after_first_ctl  = stub_ctl_add_fail_detector;
   const uint32_t after_first_clkg = stub_clkgen_ctrl0;

   CMU_Init();

   EXPECT_EQ(stub_clk_ref_fail_detector, after_first_ref);
   EXPECT_EQ(stub_ctl_add_fail_detector, after_first_ctl);
   EXPECT_EQ(stub_clkgen_ctrl0, after_first_clkg);
}
