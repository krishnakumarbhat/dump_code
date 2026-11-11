/*===========================================================================*/
/**
 * @file SWC_PRJ_Appl_SensorPosition_unit_test.cc
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
 * Unit test suite for the checking the SWC_PRJ_Appl_SensorPosition.c file
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
#include <gtest/gtest.h>

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "Rte_Type.h"

namespace
{
Dt_SensorPosition_Status_T g_sensor_position_nvm;
uint8 g_customer_radar_position;
} // namespace

extern "C"
{
   void CS_ReadNvM_Value_Operation(Dt_SensorPosition_Status_T *sensor_position_record)
   {
      *sensor_position_record = g_sensor_position_nvm;
   }

   uint8_t Get_Customer_Radar_Position(void)
   {
      return g_customer_radar_position;
   }

#include "SWC_PRJ_Appl_SensorPosition.c"
}

extern "C"
{
   uint8 Rte_SWC_PRJ_Appl_SensorPosition_Pp_PinPosition_Mismatch_Fault_Status_De_PinPosition_Mismatch_Fault_Status = 0U;
}

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class SWC_PRJ_Appl_SensorPosition_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      g_sensor_position_nvm.SensorPos_Value       = SENSOR_POSITION_INVALID;
      g_sensor_position_nvm.SensorPos_Lock_Status = SENSOR_POS_UNLOCKED;
      g_customer_radar_position                   = 1U;
      Rte_SWC_PRJ_Appl_SensorPosition_Pp_PinPosition_Mismatch_Fault_Status_De_PinPosition_Mismatch_Fault_Status =
         DIAG_TEST_NOT_COMPLETED;
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
 * Test Cases: CS_Get_Pinposition_Status_Operation
 *===========================================================================*/

/* Empty runnable stub - verify it can be called without fault and leaves the
 * output parameter untouched (no implementation provided yet). */
TEST_F(SWC_PRJ_Appl_SensorPosition_UnitTestSuite, CS_Get_Pinposition_Status_Operation_CanBeCalledWithoutFault)
{
   uint8 sensor_position = 0xAAU;

   CS_Get_Pinposition_Status_Operation(&sensor_position);

   EXPECT_EQ(0xAAU, sensor_position);
}

/*===========================================================================*
 * Test Cases: RE_SensorPosition_50ms
 *===========================================================================*/

TEST_F(SWC_PRJ_Appl_SensorPosition_UnitTestSuite, RE_SensorPosition_50ms_DefaultNvmValueUsesDefaultPosition)
{
   g_sensor_position_nvm.SensorPos_Value       = SENSOR_POS_DEFAULT_VALUE;
   g_sensor_position_nvm.SensorPos_Lock_Status = SENSOR_POS_DEFAULT_VALUE;
   g_customer_radar_position                   = SENSOR_POS_DEFAULT_RL;

   RE_SensorPosition_50ms();

   EXPECT_EQ(DIAG_TEST_PASS,
             Rte_SWC_PRJ_Appl_SensorPosition_Pp_PinPosition_Mismatch_Fault_Status_De_PinPosition_Mismatch_Fault_Status);
}

TEST_F(SWC_PRJ_Appl_SensorPosition_UnitTestSuite, RE_SensorPosition_50ms_LockedPositionMismatchFails)
{
   g_sensor_position_nvm.SensorPos_Value       = 1U;
   g_sensor_position_nvm.SensorPos_Lock_Status = 0U;
   g_customer_radar_position                   = 2U;

   RE_SensorPosition_50ms();

   EXPECT_EQ(DIAG_TEST_FAIL,
             Rte_SWC_PRJ_Appl_SensorPosition_Pp_PinPosition_Mismatch_Fault_Status_De_PinPosition_Mismatch_Fault_Status);
}

TEST_F(SWC_PRJ_Appl_SensorPosition_UnitTestSuite, RE_SensorPosition_50ms_UnlockedPositionMismatchPasses)
{
   g_sensor_position_nvm.SensorPos_Value       = 1U;
   g_sensor_position_nvm.SensorPos_Lock_Status = SENSOR_POS_UNLOCKED;
   g_customer_radar_position                   = 2U;

   RE_SensorPosition_50ms();

   EXPECT_EQ(DIAG_TEST_PASS,
             Rte_SWC_PRJ_Appl_SensorPosition_Pp_PinPosition_Mismatch_Fault_Status_De_PinPosition_Mismatch_Fault_Status);
}

TEST_F(SWC_PRJ_Appl_SensorPosition_UnitTestSuite, RE_SensorPosition_50ms_InvalidNvmValueFails)
{
   g_sensor_position_nvm.SensorPos_Value       = SENSOR_POSITION_INVALID;
   g_sensor_position_nvm.SensorPos_Lock_Status = SENSOR_POS_UNLOCKED;

   RE_SensorPosition_50ms();

   EXPECT_EQ(DIAG_TEST_FAIL,
             Rte_SWC_PRJ_Appl_SensorPosition_Pp_PinPosition_Mismatch_Fault_Status_De_PinPosition_Mismatch_Fault_Status);
}
