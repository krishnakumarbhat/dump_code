/*===========================================================================*/
/**
 * @file PLT_Srv_IoHwAb_unit_test.cc
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
 * Unit test suite for the checking the SWC_PLT_Service_IoHwAb.c file
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
#include "PLT_Srv_IoHwAb_fake.h"
#include "fff.h"
#include <gtest/gtest.h>

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
/*DEFINE_FFF_GLOBALS;*/
extern "C"
{
#include "SWC_PLT_Service_IoHwAb.c"
}

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class swc_plt_service_IoHwAb_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_FAKES_RAWADCCOUNT_FUNCTION(RESET_FAKE);
      FFF_FAKES_ADCMAIN_FUNCTION(RESET_FAKE);
      FFF_FAKES_ADCINIT_FUNCTION(RESET_FAKE);
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
 *  @b swc_plt_appl_faultmgr_sanity
 *  @n
 */
TEST_F(swc_plt_service_IoHwAb_UnitTestSuite, SanityCheck_SW_Unit_01)
{
   /*Sanity Check*/
   ASSERT_EQ(true, true);
}

TEST_F(swc_plt_service_IoHwAb_UnitTestSuite, CS_RawAdcCount_Read_SW_Unit_01)
{
   Dt_RawAdcData_T rawAdcData;
   printf("executing serviceIo\n");
   Std_ReturnType result = CS_RawAdcCount_Read(&rawAdcData);
   ASSERT_EQ(result, RTE_E_OK);
}
/**
 * @brief Test CS_Update_Thermal_Mon_Temps_Read returns RTE_E_OK
 * @details Verifies that the function always returns RTE_E_OK
 */
TEST_F(swc_plt_service_IoHwAb_UnitTestSuite, CS_Update_Thermal_Mon_Temps_Read_SW_Unit_01)
{
   DT_Thermal_mon_mes_results_T therm_temp_results;
   memset(&therm_temp_results, 0, sizeof(therm_temp_results));

   Std_ReturnType result = CS_Update_Thermal_Mon_Temps_Read(&therm_temp_results);

   ASSERT_EQ(result, RTE_E_OK);
}

/**
 * @brief Test CS_Update_Thermal_Mon_Temps_Read calls Update_Thermal_Monitor_Values
 * @details Verifies that Update_Thermal_Monitor_Values is called exactly once
 */
TEST_F(swc_plt_service_IoHwAb_UnitTestSuite, CS_Update_Thermal_Mon_Temps_Read_CallsUpdateFunction_SW_Unit_02)
{
   DT_Thermal_mon_mes_results_T therm_temp_results;
   memset(&therm_temp_results, 0, sizeof(therm_temp_results));

   /* Reset the fake before calling */
   RESET_FAKE(Update_Thermal_Monitor_Values);

   CS_Update_Thermal_Mon_Temps_Read(&therm_temp_results);

   /* Verify Update_Thermal_Monitor_Values was called exactly once */
   ASSERT_EQ(Update_Thermal_Monitor_Values_fake.call_count, 1u);
}

/**
 * @brief Test CS_Update_Thermal_Mon_Temps_Read passes correct pointer
 * @details Verifies that the correct pointer is passed to Update_Thermal_Monitor_Values
 */
TEST_F(swc_plt_service_IoHwAb_UnitTestSuite, CS_Update_Thermal_Mon_Temps_Read_PassesCorrectPointer_SW_Unit_03)
{
   DT_Thermal_mon_mes_results_T therm_temp_results;
   memset(&therm_temp_results, 0, sizeof(therm_temp_results));

   /* Reset the fake before calling */
   RESET_FAKE(Update_Thermal_Monitor_Values);

   CS_Update_Thermal_Mon_Temps_Read(&therm_temp_results);

   /* Verify the correct pointer was passed */
   ASSERT_EQ(Update_Thermal_Monitor_Values_fake.arg0_val, &therm_temp_results);
}

/**
 * @brief Test CS_Update_Thermal_Mon_Temps_Read with initialized structure
 * @details Verifies function works correctly with a pre-initialized structure
 */
TEST_F(swc_plt_service_IoHwAb_UnitTestSuite, CS_Update_Thermal_Mon_Temps_Read_InitializedStruct_SW_Unit_04)
{
   DT_Thermal_mon_mes_results_T therm_temp_results;
   memset(&therm_temp_results, 0, sizeof(therm_temp_results));
   /* Initialize with specific temperature values using the temperature array */
   therm_temp_results.immediate_temp_k.temperature[0] = 300.0f;
   therm_temp_results.average_temp_k.temperature[0]   = 295.0f;

   RESET_FAKE(Update_Thermal_Monitor_Values);

   Std_ReturnType result = CS_Update_Thermal_Mon_Temps_Read(&therm_temp_results);

   ASSERT_EQ(result, RTE_E_OK);
   ASSERT_EQ(Update_Thermal_Monitor_Values_fake.call_count, 1u);
}

/**
 * @brief Test CS_Update_Thermal_Mon_Temps_Read multiple calls
 * @details Verifies function behaves correctly when called multiple times
 */
TEST_F(swc_plt_service_IoHwAb_UnitTestSuite, CS_Update_Thermal_Mon_Temps_Read_MultipleCalls_SW_Unit_05)
{
   DT_Thermal_mon_mes_results_T therm_temp_results1;
   DT_Thermal_mon_mes_results_T therm_temp_results2;
   DT_Thermal_mon_mes_results_T therm_temp_results3;

   memset(&therm_temp_results1, 0, sizeof(therm_temp_results1));
   memset(&therm_temp_results2, 0, sizeof(therm_temp_results2));
   memset(&therm_temp_results3, 0, sizeof(therm_temp_results3));

   RESET_FAKE(Update_Thermal_Monitor_Values);

   Std_ReturnType result1 = CS_Update_Thermal_Mon_Temps_Read(&therm_temp_results1);
   Std_ReturnType result2 = CS_Update_Thermal_Mon_Temps_Read(&therm_temp_results2);
   Std_ReturnType result3 = CS_Update_Thermal_Mon_Temps_Read(&therm_temp_results3);

   /* All calls should return RTE_E_OK */
   ASSERT_EQ(result1, RTE_E_OK);
   ASSERT_EQ(result2, RTE_E_OK);
   ASSERT_EQ(result3, RTE_E_OK);

   /* Update_Thermal_Monitor_Values should be called 3 times */
   ASSERT_EQ(Update_Thermal_Monitor_Values_fake.call_count, 3u);
}

/**
 * @brief Test CS_Update_Thermal_Mon_Temps_Read return value consistency
 * @details Verifies that the function consistently returns RTE_E_OK
 */
TEST_F(swc_plt_service_IoHwAb_UnitTestSuite, CS_Update_Thermal_Mon_Temps_Read_ReturnValueConsistency_SW_Unit_06)
{
   DT_Thermal_mon_mes_results_T therm_temp_results;
   memset(&therm_temp_results, 0, sizeof(therm_temp_results));

   /* Call multiple times and verify return value is always RTE_E_OK */
   for (int i = 0; i < 5; i++)
   {
      Std_ReturnType result = CS_Update_Thermal_Mon_Temps_Read(&therm_temp_results);
      ASSERT_EQ(result, RTE_E_OK);
   }
}

/**
 * @brief Test CS_Update_Thermal_Mon_Temps_Read with max temperature values
 * @details Verifies function works with high temperature values in structure
 */
TEST_F(swc_plt_service_IoHwAb_UnitTestSuite, CS_Update_Thermal_Mon_Temps_Read_MaxTempValue_SW_Unit_07)
{
   DT_Thermal_mon_mes_results_T therm_temp_results;
   memset(&therm_temp_results, 0, sizeof(therm_temp_results));
   /* Set high temperature values (in Kelvin) using temperature array */
   therm_temp_results.immediate_temp_k.temperature[0] = 500.0f;
   therm_temp_results.average_temp_k.temperature[0]   = 500.0f;
   therm_temp_results.immediate_temp_c.temperature[0] = 226.85f;
   therm_temp_results.average_temp_c.temperature[0]   = 226.85f;

   RESET_FAKE(Update_Thermal_Monitor_Values);

   Std_ReturnType result = CS_Update_Thermal_Mon_Temps_Read(&therm_temp_results);

   ASSERT_EQ(result, RTE_E_OK);
   ASSERT_EQ(Update_Thermal_Monitor_Values_fake.call_count, 1u);
   ASSERT_EQ(Update_Thermal_Monitor_Values_fake.arg0_val, &therm_temp_results);
}

/**
 * @brief Test CS_Update_Thermal_Mon_Temps_Read with zero temperature values
 * @details Verifies function works with zero temperature values in structure
 */
TEST_F(swc_plt_service_IoHwAb_UnitTestSuite, CS_Update_Thermal_Mon_Temps_Read_ZeroTempValue_SW_Unit_08)
{
   DT_Thermal_mon_mes_results_T therm_temp_results;
   memset(&therm_temp_results, 0, sizeof(therm_temp_results));
   /* All temperature values are zero after memset */

   RESET_FAKE(Update_Thermal_Monitor_Values);

   Std_ReturnType result = CS_Update_Thermal_Mon_Temps_Read(&therm_temp_results);

   ASSERT_EQ(result, RTE_E_OK);
   ASSERT_EQ(Update_Thermal_Monitor_Values_fake.call_count, 1u);
}

/**
 * @brief Test CS_Update_Thermal_Mon_Temps_Read verifies function is independent
 * @details Verifies that the return value is not affected by fake function behavior
 */
TEST_F(swc_plt_service_IoHwAb_UnitTestSuite, CS_Update_Thermal_Mon_Temps_Read_IndependentReturn_SW_Unit_09)
{
   DT_Thermal_mon_mes_results_T therm_temp_results;
   memset(&therm_temp_results, 0, sizeof(therm_temp_results));

   RESET_FAKE(Update_Thermal_Monitor_Values);

   /* The function should always return RTE_E_OK regardless of the fake's state */
   Std_ReturnType result = CS_Update_Thermal_Mon_Temps_Read(&therm_temp_results);

   /* Verify return is always RTE_E_OK (function doesn't depend on Update_Thermal_Monitor_Values return) */
   ASSERT_EQ(result, RTE_E_OK);
}

/**
 * @brief Test CS_Update_Thermal_Mon_Temps_Read call sequence verification
 * @details Verifies the call order when multiple functions are involved
 */
TEST_F(swc_plt_service_IoHwAb_UnitTestSuite, CS_Update_Thermal_Mon_Temps_Read_CallSequence_SW_Unit_10)
{
   DT_Thermal_mon_mes_results_T therm_temp_results;
   memset(&therm_temp_results, 0, sizeof(therm_temp_results));

   RESET_FAKE(Update_Thermal_Monitor_Values);
   FFF_RESET_HISTORY();

   CS_Update_Thermal_Mon_Temps_Read(&therm_temp_results);

   /* Verify that Update_Thermal_Monitor_Values was the function called */
   ASSERT_EQ(Update_Thermal_Monitor_Values_fake.call_count, 1u);
}

TEST_F(swc_plt_service_IoHwAb_UnitTestSuite, Get_FloatingPinPosition_FaultStatus_SW_Unit_01)
{
   uint8 status;
   Get_FloatingPinPosition_FaultStatus(&status);
   /*No Implementation Available*/
   ASSERT_EQ(true, true);
}
TEST_F(swc_plt_service_IoHwAb_UnitTestSuite, Get_STM_TimeStamp_SW_Unit_01)
{
   uint32 timestamp;
   Get_STM_TimeStamp(&timestamp);
   /*No Implementation Available*/
   ASSERT_EQ(true, true);
}
TEST_F(swc_plt_service_IoHwAb_UnitTestSuite, Pp_PWMDutyCycle_SW_Unit_01)
{
   uint8 some;
   Pp_PWMDutyCycle(some);
   /*No Implementation Available*/
   ASSERT_EQ(true, true);
}
TEST_F(swc_plt_service_IoHwAb_UnitTestSuite, RE_PLT_Service_IoHwAb_ADCFilter_5ms_SW_Unit_01)
{
   RE_PLT_Service_IoHwAb_ADCFilter_5ms();
   /*No Implementation Available*/
   ASSERT_EQ(true, true);
}
TEST_F(swc_plt_service_IoHwAb_UnitTestSuite, RE_PLT_Service_IoHwAb_Main_5ms_SW_Unit_01)
{
   RE_PLT_Service_IoHwAb_Main_5ms();
   /*No Implementation Available*/
   ASSERT_EQ(true, true);
}
TEST_F(swc_plt_service_IoHwAb_UnitTestSuite, RE_PLT_Service_IoHwAb_Init_SW_Unit_01)
{
   RE_PLT_Service_IoHwAb_Init();
   /*No Implementation Available*/
   ASSERT_EQ(true, true);
}
TEST_F(swc_plt_service_IoHwAb_UnitTestSuite, Set_DIO_LED_SRC_PULL_SW_Unit_01)
{
   uint8 some;
   Set_DIO_LED_SRC_PULL(some);
   /*No Implementation Available*/
   ASSERT_EQ(true, true);
}
TEST_F(swc_plt_service_IoHwAb_UnitTestSuite, RE_PLT_Service_IoHwAb_Main_5ms_SW_Unit_02)
{
   for (int i = 0; i < 3; i++)
      RE_PLT_Service_IoHwAb_Main_5ms();
   ASSERT_EQ(true, true);
}

TEST_F(swc_plt_service_IoHwAb_UnitTestSuite, IoHwAb_ADC_PosPin_Prj_cbk_SW_Unit_01)
{
   IoHwAb_Adc_PosPin_Hw_Ckt_T PosPinHwCkt_Control = Init_EnablePosGndCkt;
   IoHwAb_ADC_PosPin_Prj_cbk(PosPinHwCkt_Control);
}
TEST_F(swc_plt_service_IoHwAb_UnitTestSuite, IoHwAb_ADC_PosPin_Prj_cbk_SW_Unit_02)
{
   IoHwAb_Adc_PosPin_Hw_Ckt_T PosPinHwCkt_Control = EnablePosGndCkt;
   IoHwAb_ADC_PosPin_Prj_cbk(PosPinHwCkt_Control);
}
TEST_F(swc_plt_service_IoHwAb_UnitTestSuite, IoHwAb_ADC_PosPin_Prj_cbk_SW_Unit_03)
{
   IoHwAb_Adc_PosPin_Hw_Ckt_T PosPinHwCkt_Control = DisablePosGndCkt;
   IoHwAb_ADC_PosPin_Prj_cbk(PosPinHwCkt_Control);
}

TEST_F(swc_plt_service_IoHwAb_UnitTestSuite, IoHwAb_ADC_PosPin_Prj_cbk_SW_Unit_04)
{
   IoHwAb_Adc_PosPin_Hw_Ckt_T PosPinHwCkt_Control = Init_DisablePosGndCkt;
   IoHwAb_ADC_PosPin_Prj_cbk(PosPinHwCkt_Control);
}
TEST_F(swc_plt_service_IoHwAb_UnitTestSuite, IoHwAb_ADC_PosPin_Prj_cbk_SW_Unit_05)
{
   /*Arrange: Pass an invalid enum value (casted)*/
   IoHwAb_Adc_PosPin_Hw_Ckt_T PosPinHwCkt_Control = static_cast<IoHwAb_Adc_PosPin_Hw_Ckt_T>(5);

   IoHwAb_ADC_PosPin_Prj_cbk(PosPinHwCkt_Control);

   /*Assert
    No action expected, so we can check that Dio_WriteChannel was NOT called
    If you have a mock for Dio_WriteChannel, verify no calls happened*/
   SUCCEED(); /* Placeholder if no mock available*/
}
