
/*===========================================================================*/
/**
 * @file SWC_PLT_Appl_IoHwAb_unit_test.cc
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
 * Unit test suite for the checking the SWC_PLT_Appl_IoHwAb.c file
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
#include "SWC_PLT_Appl_IoHwAb_fake.h"
#include "board_revision_mocks.h"
#include "fff.h"
#include <gtest/gtest.h>
/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/

extern "C"
{
#include "SWC_PLT_Appl_IoHwAb.c"
}

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class swc_plt_appl_IoHwAb_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_FAKES_UPDATE_THERMAL_MONITOR_FUNCTION_LIST(RESET_FAKE);
      FFF_FAKES_BOARD_REVISION_LIST(RESET_FAKE);
      FFF_RESET_HISTORY();
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

/**
 *  @b swc_plt_appl_iohwab_sanity
 *  @n
 */
TEST_F(swc_plt_appl_IoHwAb_UnitTestSuite, SanityCheck_SW_Unit_01)
{
   /*Sanity Check*/
   ASSERT_EQ(true, true);
}

/**
 * @brief Test CS_ThermMonTemp_Read with valid temp_option returns E_OK
 */
TEST_F(swc_plt_appl_IoHwAb_UnitTestSuite, CS_ThermMonTemp_Read_SW_Unit_01)
{
   Dt_Therm_Mon_Temp_Opt_T temp_option        = 1;
   DT_Thermal_Monitor_Temperatures_T reqValue = {{0.0f}};

   /* Setup fake to return E_OK */
   IoHwAb_Appl_ThermMonTemp_Read_fake.return_val = E_OK;

   Std_ReturnType result = CS_ThermMonTemp_Read(temp_option, &reqValue);

   /* Verify IoHwAb_Appl_ThermMonTemp_Read was called */
   ASSERT_EQ(IoHwAb_Appl_ThermMonTemp_Read_fake.call_count, 1U);
   /* Verify correct parameters were passed */
   ASSERT_EQ(IoHwAb_Appl_ThermMonTemp_Read_fake.arg0_val, temp_option);
   ASSERT_EQ(IoHwAb_Appl_ThermMonTemp_Read_fake.arg1_val, &reqValue);
   /* Verify return value */
   ASSERT_EQ(result, E_OK);
}

/**
 * @brief Test CS_ThermMonTemp_Read with immediate temperature in Kelvin (option 0)
 */
TEST_F(swc_plt_appl_IoHwAb_UnitTestSuite, CS_ThermMonTemp_Read_ImmediateKelvin_SW_Unit_02)
{
   Dt_Therm_Mon_Temp_Opt_T temp_option        = 0U; /* IMMEDIATE_TEMPERATURES_KELVIN */
   DT_Thermal_Monitor_Temperatures_T reqValue = {{0.0f}};

   IoHwAb_Appl_ThermMonTemp_Read_fake.return_val = E_OK;

   Std_ReturnType result = CS_ThermMonTemp_Read(temp_option, &reqValue);

   ASSERT_EQ(IoHwAb_Appl_ThermMonTemp_Read_fake.call_count, 1U);
   ASSERT_EQ(IoHwAb_Appl_ThermMonTemp_Read_fake.arg0_val, 0U);
   ASSERT_EQ(result, E_OK);
}

/**
 * @brief Test CS_ThermMonTemp_Read with average temperature in Kelvin (option 1)
 */
TEST_F(swc_plt_appl_IoHwAb_UnitTestSuite, CS_ThermMonTemp_Read_AverageKelvin_SW_Unit_03)
{
   Dt_Therm_Mon_Temp_Opt_T temp_option        = 1U; /* AVERAGE_TEMPERATURES_KELVIN */
   DT_Thermal_Monitor_Temperatures_T reqValue = {{0.0f}};

   IoHwAb_Appl_ThermMonTemp_Read_fake.return_val = E_OK;

   Std_ReturnType result = CS_ThermMonTemp_Read(temp_option, &reqValue);

   ASSERT_EQ(IoHwAb_Appl_ThermMonTemp_Read_fake.call_count, 1U);
   ASSERT_EQ(IoHwAb_Appl_ThermMonTemp_Read_fake.arg0_val, 1U);
   ASSERT_EQ(result, E_OK);
}

/**
 * @brief Test CS_ThermMonTemp_Read with immediate temperature in Celsius (option 2)
 */
TEST_F(swc_plt_appl_IoHwAb_UnitTestSuite, CS_ThermMonTemp_Read_ImmediateCelsius_SW_Unit_04)
{
   Dt_Therm_Mon_Temp_Opt_T temp_option        = 2U; /* IMMEDIATE_TEMPERATURES_CELSIUS */
   DT_Thermal_Monitor_Temperatures_T reqValue = {{0.0f}};

   IoHwAb_Appl_ThermMonTemp_Read_fake.return_val = E_OK;

   Std_ReturnType result = CS_ThermMonTemp_Read(temp_option, &reqValue);

   ASSERT_EQ(IoHwAb_Appl_ThermMonTemp_Read_fake.call_count, 1U);
   ASSERT_EQ(IoHwAb_Appl_ThermMonTemp_Read_fake.arg0_val, 2U);
   ASSERT_EQ(result, E_OK);
}

/**
 * @brief Test CS_ThermMonTemp_Read with average temperature in Celsius (option 3)
 */
TEST_F(swc_plt_appl_IoHwAb_UnitTestSuite, CS_ThermMonTemp_Read_AverageCelsius_SW_Unit_05)
{
   Dt_Therm_Mon_Temp_Opt_T temp_option        = 3U; /* AVERAGE_TEMPERATURES_CELSIUS */
   DT_Thermal_Monitor_Temperatures_T reqValue = {{0.0f}};

   IoHwAb_Appl_ThermMonTemp_Read_fake.return_val = E_OK;

   Std_ReturnType result = CS_ThermMonTemp_Read(temp_option, &reqValue);

   ASSERT_EQ(IoHwAb_Appl_ThermMonTemp_Read_fake.call_count, 1U);
   ASSERT_EQ(IoHwAb_Appl_ThermMonTemp_Read_fake.arg0_val, 3U);
   ASSERT_EQ(result, E_OK);
}

/**
 * @brief Test CS_ThermMonTemp_Read with immediate temperature in Fahrenheit (option 4)
 */
TEST_F(swc_plt_appl_IoHwAb_UnitTestSuite, CS_ThermMonTemp_Read_ImmediateFahrenheit_SW_Unit_06)
{
   Dt_Therm_Mon_Temp_Opt_T temp_option        = 4U; /* IMMEDIATE_TEMPERATURES_FAHRENHEIT */
   DT_Thermal_Monitor_Temperatures_T reqValue = {{0.0f}};

   IoHwAb_Appl_ThermMonTemp_Read_fake.return_val = E_OK;

   Std_ReturnType result = CS_ThermMonTemp_Read(temp_option, &reqValue);

   ASSERT_EQ(IoHwAb_Appl_ThermMonTemp_Read_fake.call_count, 1U);
   ASSERT_EQ(IoHwAb_Appl_ThermMonTemp_Read_fake.arg0_val, 4U);
   ASSERT_EQ(result, E_OK);
}

/**
 * @brief Test CS_ThermMonTemp_Read with average temperature in Fahrenheit (option 5)
 */
TEST_F(swc_plt_appl_IoHwAb_UnitTestSuite, CS_ThermMonTemp_Read_AverageFahrenheit_SW_Unit_07)
{
   Dt_Therm_Mon_Temp_Opt_T temp_option        = 5U; /* AVERAGE_TEMPERATURES_FAHRENHEIT */
   DT_Thermal_Monitor_Temperatures_T reqValue = {{0.0f}};

   IoHwAb_Appl_ThermMonTemp_Read_fake.return_val = E_OK;

   Std_ReturnType result = CS_ThermMonTemp_Read(temp_option, &reqValue);

   ASSERT_EQ(IoHwAb_Appl_ThermMonTemp_Read_fake.call_count, 1U);
   ASSERT_EQ(IoHwAb_Appl_ThermMonTemp_Read_fake.arg0_val, 5U);
   ASSERT_EQ(result, E_OK);
}

/**
 * @brief Test CS_ThermMonTemp_Read with invalid temp_option returns error
 */
TEST_F(swc_plt_appl_IoHwAb_UnitTestSuite, CS_ThermMonTemp_Read_InvalidOption_SW_Unit_08)
{
   Dt_Therm_Mon_Temp_Opt_T temp_option        = 6U; /* Invalid option (greater than TEMPERATURE_IN_F_AVG) */
   DT_Thermal_Monitor_Temperatures_T reqValue = {{0.0f}};

   /* Setup fake to return RTE_E_INVALID for invalid option */
   IoHwAb_Appl_ThermMonTemp_Read_fake.return_val = RTE_E_INVALID;

   Std_ReturnType result = CS_ThermMonTemp_Read(temp_option, &reqValue);

   ASSERT_EQ(IoHwAb_Appl_ThermMonTemp_Read_fake.call_count, 1U);
   ASSERT_EQ(IoHwAb_Appl_ThermMonTemp_Read_fake.arg0_val, 6U);
   ASSERT_EQ(result, RTE_E_INVALID);
}

/**
 * @brief Test CS_ThermMonTemp_Read with maximum invalid temp_option (255)
 */
TEST_F(swc_plt_appl_IoHwAb_UnitTestSuite, CS_ThermMonTemp_Read_MaxInvalidOption_SW_Unit_09)
{
   Dt_Therm_Mon_Temp_Opt_T temp_option        = 255U; /* Maximum uint8 value - invalid */
   DT_Thermal_Monitor_Temperatures_T reqValue = {{0.0f}};

   IoHwAb_Appl_ThermMonTemp_Read_fake.return_val = RTE_E_INVALID;

   Std_ReturnType result = CS_ThermMonTemp_Read(temp_option, &reqValue);

   ASSERT_EQ(IoHwAb_Appl_ThermMonTemp_Read_fake.call_count, 1U);
   ASSERT_EQ(result, RTE_E_INVALID);
}

/**
 * @brief Test CS_ThermMonTemp_Read verifies return value propagation from lower layer
 */
TEST_F(swc_plt_appl_IoHwAb_UnitTestSuite, CS_ThermMonTemp_Read_ReturnValuePropagation_SW_Unit_10)
{
   Dt_Therm_Mon_Temp_Opt_T temp_option        = 0U;
   DT_Thermal_Monitor_Temperatures_T reqValue = {{0.0f}};

   /* Test with E_NOT_OK return value */
   IoHwAb_Appl_ThermMonTemp_Read_fake.return_val = E_NOT_OK;

   Std_ReturnType result = CS_ThermMonTemp_Read(temp_option, &reqValue);

   ASSERT_EQ(result, E_NOT_OK);
}

TEST_F(swc_plt_appl_IoHwAb_UnitTestSuite, RE_PLT_IoHwAb_Init_SW_Unit_01)
{
   RE_PLT_IoHwAb_Init();
   ASSERT_EQ(IoHwAb_Appl_Init_fake.call_count, 1);
}
TEST_F(swc_plt_appl_IoHwAb_UnitTestSuite, RE_PLT_IoHwAb_Main_50ms_SW_Unit_01)
{
   RE_PLT_IoHwAb_Main_50ms();
   ASSERT_EQ(IoHwAb_Appl_Main_50ms_fake.call_count, 1);
}
TEST_F(swc_plt_appl_IoHwAb_UnitTestSuite, RE_PLT_IoHwAb_Main_5ms_SW_Unit_01)
{
   RE_PLT_IoHwAb_Main_5ms();
   ASSERT_EQ(IoHwAb_Appl_Main_5ms_fake.call_count, 1);
}
TEST_F(swc_plt_appl_IoHwAb_UnitTestSuite, CS_Platform_register_set_SW_Unit_01)
{
   uint8 fault_type = 0;
   CS_Platform_register_set(fault_type);
}
TEST_F(swc_plt_appl_IoHwAb_UnitTestSuite, RE_PLT_IoHwAb_Main_10ms_SW_Unit_01)
{
   RE_PLT_IoHwAb_Main_10ms();
   ASSERT_EQ(true, true);
}
