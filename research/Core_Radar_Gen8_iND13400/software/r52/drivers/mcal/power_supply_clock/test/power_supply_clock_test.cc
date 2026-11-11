/*===========================================================================*\
 * FILE: power_supply_clock_test.cc
 *===========================================================================
 * Copyright (C) 2024 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 * Unit tests for power_supply_clock module.
 *
 * Tests cover:
 *   - PS_Clock_Init: Verifies both 2MHz and 8MHz dithering are configured
 *   - PS_2MHz_Clk_Dithering: Verifies PWM Channel 0 configuration sequence
 *   - PS_8MHz_Clk_Dithering: Verifies PWM Channel 1 configuration sequence
 *   - Return value propagation on success and failure
 *
 * NOTE: PS_2MHz_Clk_Dithering and PS_8MHz_Clk_Dithering use static local
 *       variables with |= accumulation. Once tainted by an error return,
 *       the static variable remains non-zero for all subsequent calls in
 *       the same process. Tests are ordered so that error-injection tests
 *       run last to avoid polluting other tests.
\*===========================================================================*/

#include <gtest/gtest.h>

#include "fff.h"

DEFINE_FFF_GLOBALS;

/*===========================================================================*\
 * FFF Fakes for PWM driver function pointers
\*===========================================================================*/

/* Enable PS_Clock_Init function for testing (before any header includes) */
#define PS_CLOCK_INIT_ENABLE (1U)

/* PWM Channel 0 (2MHz) fakes */
FAKE_VALUE_FUNC(int32_t, fake_pwm0_Initialize);
FAKE_VALUE_FUNC(int32_t, fake_pwm0_Control, uint32_t, uint32_t);

/* PWM Channel 1 (8MHz) fakes */
FAKE_VALUE_FUNC(int32_t, fake_pwm1_Initialize);
FAKE_VALUE_FUNC(int32_t, fake_pwm1_Control, uint32_t, uint32_t);

/*===========================================================================*\
 * Provide definitions for extern symbols and include source under test
\*===========================================================================*/

extern "C"
{
/* Include mock headers to obtain type definitions */
#include "Driver_PWM.h"
#include "Std_Types.h"

   /* Define the Driver_PWM array used by the source under test */
   ARM_DRIVER_PWM Driver_PWM[2];

   /* Satisfy the extern declaration in power_supply_clock.c (Driver_Pwm) */
   ARM_DRIVER_PWM Driver_Pwm[2];

   /* Individual PWM driver instances used when DEVELOPMENT_ONLY is defined */
   ARM_DRIVER_PWM Driver_Pwm0;
   ARM_DRIVER_PWM Driver_Pwm1;
}

/* Textually include the source file under test */
extern "C"
{
#include "power_supply_clock.c"
}

/*===========================================================================*\
 * Test Fixture
\*===========================================================================*/

class PowerSupplyClockTest : public testing::Test
{
 protected:
   void SetUp() override
   {
      /* Reset all FFF fakes */
      RESET_FAKE(fake_pwm0_Initialize);
      RESET_FAKE(fake_pwm0_Control);
      RESET_FAKE(fake_pwm1_Initialize);
      RESET_FAKE(fake_pwm1_Control);
      FFF_RESET_HISTORY();

      /* Wire FFF fakes into Driver_PWM struct function pointers */
      Driver_PWM[0].Initialize = fake_pwm0_Initialize;
      Driver_PWM[0].Control    = fake_pwm0_Control;
      Driver_PWM[1].Initialize = fake_pwm1_Initialize;
      Driver_PWM[1].Control    = fake_pwm1_Control;

      /* Wire individual PWM driver instances (used with DEVELOPMENT_ONLY) */
      Driver_Pwm0.Initialize = fake_pwm0_Initialize;
      Driver_Pwm0.Control    = fake_pwm0_Control;
      Driver_Pwm1.Initialize = fake_pwm1_Initialize;
      Driver_Pwm1.Control    = fake_pwm1_Control;

      /* Default: all calls succeed */
      fake_pwm0_Initialize_fake.return_val = (int32_t)E_OK;
      fake_pwm0_Control_fake.return_val    = (int32_t)E_OK;
      fake_pwm1_Initialize_fake.return_val = (int32_t)E_OK;
      fake_pwm1_Control_fake.return_val    = (int32_t)E_OK;
   }

   void TearDown() override
   {
   }
};

/*===========================================================================*\
 * PS_Clock_Init Tests
\*===========================================================================*/

/**
 * @brief Verify PS_Clock_Init configures both PWM channels
 */
TEST_F(PowerSupplyClockTest, PS_Clock_Init_ConfiguresBothPwmChannels)
{
   PS_Clock_Init();

   /* PWM Channel 0 (2MHz) shall be initialized */
   EXPECT_EQ(fake_pwm0_Initialize_fake.call_count, 1u);
   EXPECT_GT(fake_pwm0_Control_fake.call_count, 0u);

   /* PWM Channel 1 (8MHz) shall be initialized */
   EXPECT_EQ(fake_pwm1_Initialize_fake.call_count, 1u);
   EXPECT_GT(fake_pwm1_Control_fake.call_count, 0u);
}

/*===========================================================================*\
 * PS_2MHz_Clk_Dithering Tests (PWM Channel 0)
\*===========================================================================*/

/**
 * @brief Verify 2MHz dithering calls Initialize exactly once
 */
TEST_F(PowerSupplyClockTest, PS_2MHz_Dithering_CallsInitializeOnce)
{
   PS_Clock_Init();

   EXPECT_EQ(fake_pwm0_Initialize_fake.call_count, 1u);
}

/**
 * @brief Verify 2MHz dithering makes exactly 9 Control calls
 *
 * Expected Control call sequence:
 *   1. DISABLE
 *   2. MODE_STAIRCASE | PRESCALER_DIV_1 | DITHER_DISABLE
 *   3. STAIRCASE_EOC_ENABLE
 *   4. STAIRCASE_EOC_COUNT
 *   5. DITHER_STEP
 *   6. SLOPE_STEP
 *   7. SLOPE_STEP_MAX_PERIOD
 *   8. SLOPE_STEP_MIN_PERIOD
 *   9. ENABLE
 */
TEST_F(PowerSupplyClockTest, PS_2MHz_Dithering_MakesNineControlCalls)
{
   PS_Clock_Init();

   EXPECT_EQ(fake_pwm0_Control_fake.call_count, 9u);
}

/**
 * @brief Verify 2MHz dithering disables PWM before configuration and
 *        enables it after configuration
 */
TEST_F(PowerSupplyClockTest, PS_2MHz_Dithering_DisableBeforeConfigEnableAfter)
{
   PS_Clock_Init();

   /* First Control call: ARM_PWM_DISABLE */
   EXPECT_EQ(fake_pwm0_Control_fake.arg0_history[0], ARM_PWM_DISABLE);
   EXPECT_EQ(fake_pwm0_Control_fake.arg1_history[0], 1u);

   /* Last Control call: ARM_PWM_ENABLE */
   EXPECT_EQ(fake_pwm0_Control_fake.arg0_history[8], ARM_PWM_ENABLE);
   EXPECT_EQ(fake_pwm0_Control_fake.arg1_history[8], 1u);
}

/**
 * @brief Verify all 2MHz dithering Control call parameters are correct
 */
TEST_F(PowerSupplyClockTest, PS_2MHz_Dithering_AllControlParametersCorrect)
{
   PS_Clock_Init();

   /* Call 0: ARM_PWM_DISABLE, 1 */
   EXPECT_EQ(fake_pwm0_Control_fake.arg0_history[0], ARM_PWM_DISABLE);
   EXPECT_EQ(fake_pwm0_Control_fake.arg1_history[0], 1u);

   /* Call 1: ARM_PWM_MODE_STAIRCASE | ARM_PWM_PRESCALER_DIV_1 | ARM_PWM_DITHER_DISABLE, 0 */
   EXPECT_EQ(fake_pwm0_Control_fake.arg0_history[1], (ARM_PWM_MODE_STAIRCASE | ARM_PWM_PRESCALER_DIV_1 | ARM_PWM_DITHER_DISABLE));
   EXPECT_EQ(fake_pwm0_Control_fake.arg1_history[1], 0u);

   /* Call 2: ARM_PWM_STAIRCASE_EOC_ENABLE, 0x1 */
   EXPECT_EQ(fake_pwm0_Control_fake.arg0_history[2], ARM_PWM_STAIRCASE_EOC_ENABLE);
   EXPECT_EQ(fake_pwm0_Control_fake.arg1_history[2], 0x1u);

   /* Call 3: ARM_PWM_STAIRCASE_EOC_COUNT, 0xFF */
   EXPECT_EQ(fake_pwm0_Control_fake.arg0_history[3], ARM_PWM_STAIRCASE_EOC_COUNT);
   EXPECT_EQ(fake_pwm0_Control_fake.arg1_history[3], 0xFFu);

   /* Call 4: ARM_PWM_DITHER_STEP, 0x1 */
   EXPECT_EQ(fake_pwm0_Control_fake.arg0_history[4], ARM_PWM_DITHER_STEP);
   EXPECT_EQ(fake_pwm0_Control_fake.arg1_history[4], 0x1u);

   /* Call 5: ARM_PWM_SLOPE_STEP, 0x2 */
   EXPECT_EQ(fake_pwm0_Control_fake.arg0_history[5], ARM_PWM_SLOPE_STEP);
   EXPECT_EQ(fake_pwm0_Control_fake.arg1_history[5], 0x2u);

   /* Call 6: ARM_PWM_SLOPE_STEP_MAX_PERIOD, 0x93 */
   EXPECT_EQ(fake_pwm0_Control_fake.arg0_history[6], ARM_PWM_SLOPE_STEP_MAX_PERIOD);
   EXPECT_EQ(fake_pwm0_Control_fake.arg1_history[6], 0x93u);

   /* Call 7: ARM_PWM_SLOPE_STEP_MIN_PERIOD, 0x61 */
   EXPECT_EQ(fake_pwm0_Control_fake.arg0_history[7], ARM_PWM_SLOPE_STEP_MIN_PERIOD);
   EXPECT_EQ(fake_pwm0_Control_fake.arg1_history[7], 0x61u);

   /* Call 8: ARM_PWM_ENABLE, 1 */
   EXPECT_EQ(fake_pwm0_Control_fake.arg0_history[8], ARM_PWM_ENABLE);
   EXPECT_EQ(fake_pwm0_Control_fake.arg1_history[8], 1u);
}

/*===========================================================================*\
 * PS_8MHz_Clk_Dithering Tests (PWM Channel 1)
\*===========================================================================*/

/**
 * @brief Verify 8MHz dithering calls Initialize exactly once
 */
TEST_F(PowerSupplyClockTest, PS_8MHz_Dithering_CallsInitializeOnce)
{
   PS_Clock_Init();

   EXPECT_EQ(fake_pwm1_Initialize_fake.call_count, 1u);
}

/**
 * @brief Verify 8MHz dithering makes exactly 9 Control calls
 */
TEST_F(PowerSupplyClockTest, PS_8MHz_Dithering_MakesNineControlCalls)
{
   PS_Clock_Init();

   EXPECT_EQ(fake_pwm1_Control_fake.call_count, 9u);
}

/**
 * @brief Verify 8MHz dithering disables PWM before configuration and
 *        enables it after configuration
 */
TEST_F(PowerSupplyClockTest, PS_8MHz_Dithering_DisableBeforeConfigEnableAfter)
{
   PS_Clock_Init();

   /* First Control call: ARM_PWM_DISABLE */
   EXPECT_EQ(fake_pwm1_Control_fake.arg0_history[0], ARM_PWM_DISABLE);
   EXPECT_EQ(fake_pwm1_Control_fake.arg1_history[0], 1u);

   /* Last Control call: ARM_PWM_ENABLE */
   EXPECT_EQ(fake_pwm1_Control_fake.arg0_history[8], ARM_PWM_ENABLE);
   EXPECT_EQ(fake_pwm1_Control_fake.arg1_history[8], 1u);
}

/**
 * @brief Verify all 8MHz dithering Control call parameters are correct
 *
 * Note: 8MHz uses different SLOPE_STEP, MAX_PERIOD, and MIN_PERIOD values
 *       compared to 2MHz.
 */
TEST_F(PowerSupplyClockTest, PS_8MHz_Dithering_AllControlParametersCorrect)
{
   PS_Clock_Init();

   /* Call 0: ARM_PWM_DISABLE, 1 */
   EXPECT_EQ(fake_pwm1_Control_fake.arg0_history[0], ARM_PWM_DISABLE);
   EXPECT_EQ(fake_pwm1_Control_fake.arg1_history[0], 1u);

   /* Call 1: ARM_PWM_MODE_STAIRCASE | ARM_PWM_PRESCALER_DIV_1 | ARM_PWM_DITHER_DISABLE, 0 */
   EXPECT_EQ(fake_pwm1_Control_fake.arg0_history[1], (ARM_PWM_MODE_STAIRCASE | ARM_PWM_PRESCALER_DIV_1 | ARM_PWM_DITHER_DISABLE));
   EXPECT_EQ(fake_pwm1_Control_fake.arg1_history[1], 0u);

   /* Call 2: ARM_PWM_STAIRCASE_EOC_ENABLE, 0x1 */
   EXPECT_EQ(fake_pwm1_Control_fake.arg0_history[2], ARM_PWM_STAIRCASE_EOC_ENABLE);
   EXPECT_EQ(fake_pwm1_Control_fake.arg1_history[2], 0x1u);

   /* Call 3: ARM_PWM_STAIRCASE_EOC_COUNT, 0xFF */
   EXPECT_EQ(fake_pwm1_Control_fake.arg0_history[3], ARM_PWM_STAIRCASE_EOC_COUNT);
   EXPECT_EQ(fake_pwm1_Control_fake.arg1_history[3], 0xFFu);

   /* Call 4: ARM_PWM_DITHER_STEP, 0x1 */
   EXPECT_EQ(fake_pwm1_Control_fake.arg0_history[4], ARM_PWM_DITHER_STEP);
   EXPECT_EQ(fake_pwm1_Control_fake.arg1_history[4], 0x1u);

   /* Call 5: ARM_PWM_SLOPE_STEP, 0x1 (differs from 2MHz: 0x2) */
   EXPECT_EQ(fake_pwm1_Control_fake.arg0_history[5], ARM_PWM_SLOPE_STEP);
   EXPECT_EQ(fake_pwm1_Control_fake.arg1_history[5], 0x1u);

   /* Call 6: ARM_PWM_SLOPE_STEP_MAX_PERIOD, 0x22 (differs from 2MHz: 0x93) */
   EXPECT_EQ(fake_pwm1_Control_fake.arg0_history[6], ARM_PWM_SLOPE_STEP_MAX_PERIOD);
   EXPECT_EQ(fake_pwm1_Control_fake.arg1_history[6], 0x22u);

   /* Call 7: ARM_PWM_SLOPE_STEP_MIN_PERIOD, 0x1D (differs from 2MHz: 0x61) */
   EXPECT_EQ(fake_pwm1_Control_fake.arg0_history[7], ARM_PWM_SLOPE_STEP_MIN_PERIOD);
   EXPECT_EQ(fake_pwm1_Control_fake.arg1_history[7], 0x1Du);

   /* Call 8: ARM_PWM_ENABLE, 1 */
   EXPECT_EQ(fake_pwm1_Control_fake.arg0_history[8], ARM_PWM_ENABLE);
   EXPECT_EQ(fake_pwm1_Control_fake.arg1_history[8], 1u);
}

/*===========================================================================*\
 * Return Value Tests - Success Cases
 * (Must run BEFORE error-injection tests due to static local variable)
\*===========================================================================*/

/**
 * @brief Verify PS_2MHz_Clk_Dithering returns E_OK when all calls succeed
 */
TEST_F(PowerSupplyClockTest, PS_2MHz_Dithering_ReturnsOkOnSuccess)
{
   Std_ReturnType result = PS_2MHz_Clk_Dithering();

   EXPECT_EQ(result, E_OK);
}

/**
 * @brief Verify PS_8MHz_Clk_Dithering returns E_OK when all calls succeed
 */
TEST_F(PowerSupplyClockTest, PS_8MHz_Dithering_ReturnsOkOnSuccess)
{
   Std_ReturnType result = PS_8MHz_Clk_Dithering();

   EXPECT_EQ(result, E_OK);
}

/*===========================================================================*\
 * Return Value Tests - Error Propagation
 *
 * WARNING: These tests MUST run last because they permanently taint the
 * static local return_value variable (|= accumulation). Once non-zero,
 * subsequent calls to the same function always return non-zero.
\*===========================================================================*/

/**
 * @brief Verify PS_2MHz_Clk_Dithering propagates Initialize failure
 */
TEST_F(PowerSupplyClockTest, PS_2MHz_Dithering_PropagatesInitializeError)
{
   fake_pwm0_Initialize_fake.return_val = (int32_t)E_NOT_OK;

   Std_ReturnType result = PS_2MHz_Clk_Dithering();

   EXPECT_NE(result, E_OK);
}

/**
 * @brief Verify PS_8MHz_Clk_Dithering propagates Control failure
 */
TEST_F(PowerSupplyClockTest, PS_8MHz_Dithering_PropagatesControlError)
{
   fake_pwm1_Control_fake.return_val = (int32_t)E_NOT_OK;

   Std_ReturnType result = PS_8MHz_Clk_Dithering();

   EXPECT_NE(result, E_OK);
}
