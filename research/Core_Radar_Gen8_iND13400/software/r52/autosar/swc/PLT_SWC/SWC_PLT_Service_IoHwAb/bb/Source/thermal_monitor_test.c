/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes SQT test code that must be tested and/or adapted during BSW integration.
 *  The template code is only intended for testing SQT testcases.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.

 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  thermal_monitor_test.c
 *
 *  DESCRIPTION:
 *    This file contains SQT test stubs for PVT thermal monitoring.
 *    - Test_Stub_PVT_Alarm_Threshold: Controls PVT alarm threshold testing for FCRU4/FCRU5
 *
 *********************************************************************************************************************/
#include "reuse.h"
#include "thermal_monitor.h"
/*===========================================================================*\
 * Test Stub Variables for PVT Alarm Threshold Testing
 * When Test_Stub_PVT_Alarm_Threshold is set to 1U or 2U, the alarm thresholds are
 * lowered to allow testing of FCRU4/FCRU5 reset behavior when temperature
 * crosses above 147 degree C threshold.
 *
 * Normal threshold: 0x39E (926 raw) = 147 degree C
 * Test threshold:   Lower value to trigger alarm at current temperature
 *
 * Test_Stub_PVT_Alarm_Threshold values:
 *   0U = Normal operation (no test)
 *   1U = Test PVT0 alarm (FCRU FAULT_04)
 *   2U = Test PVT1 alarm (FCRU FAULT_05)
\*===========================================================================*/
#if (ENABLE_SQT_TEST_STUBS == TRUE)
volatile uint8 Test_Stub_PVT_Alarm_Threshold = 0U;

   /* Test threshold raw value to trigger alarm - must be LOWER than actual temperature!
    * Alarm triggers when: accumulated_temp > threshold
    * 0x26 (38 raw) = ~-37 degree C - will always trigger (any temp > -37C)
    * 0x100 (256 raw) = ~25 degree C - will trigger at room temp since junction is warmer
    * 0x39E (926 raw) = 147 degree C - normal production threshold (won't trigger at room temp)
    */
   #define TEST_STUB_PVT_ALARM_THR (0x26U) /* -37 degree C - will always trigger reset */
#endif

/******************************************************************************
 * Name:  Thermal_Monitor_Test_PVT0_Alarm
 *   This function applies test stub threshold to PVT0 for FCRU4 testing.
 *   When called, it sets PVT0 alarm thresholds to a very low value so that
 *   the current temperature triggers the alarm, causing FCRU FAULT_04 reset.
 *
 * Shared Variables: Test_Stub_PVT_Alarm_Threshold
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *   - When Test_Stub_PVT_Alarm_Threshold == 1U, PVT0 threshold is lowered
 *   - Alarm triggers when accumulated_temp > threshold
 *   - FCRU4 monitors PVT0 alarm signal and triggers MCU reset
 *
 ******************************************************************************/
#if (ENABLE_SQT_TEST_STUBS == TRUE)
void Thermal_Monitor_Test_PVT0_Alarm(void)
{
   if (Test_Stub_PVT_Alarm_Threshold == 1U)
   {
      /* Set very low threshold so current temperature triggers alarm */
      /* Must set both ALARM0 and ALARM1 thresholds - FCRU4 monitors the alarm signal */
      PVT0_CTRL4_ADDR = TEST_STUB_PVT_ALARM_THR * CTRL_PVT0_ACC_LEN;
      PVT0_CTRL4_ADDR |= ((TEST_STUB_PVT_ALARM_THR * CTRL_PVT0_ACC_LEN) << CTL_PVT0_ALARM1_THR_OFFSET);
   }
}
#endif

/******************************************************************************
 * Name:  Thermal_Monitor_Test_PVT1_Alarm
 *   This function applies test stub threshold to PVT1 for FCRU5 testing.
 *   When called, it sets PVT1 alarm thresholds to a very low value so that
 *   the current temperature triggers the alarm, causing FCRU FAULT_05 reset.
 *
 * Shared Variables: Test_Stub_PVT_Alarm_Threshold
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *   - When Test_Stub_PVT_Alarm_Threshold == 2U, PVT1 threshold is lowered
 *   - Alarm triggers when accumulated_temp > threshold
 *   - FCRU5 monitors PVT1 alarm signal and triggers MCU reset
 *
 ******************************************************************************/
#if (ENABLE_SQT_TEST_STUBS == TRUE)
void Thermal_Monitor_Test_PVT1_Alarm(void)
{
   if (Test_Stub_PVT_Alarm_Threshold == 2U)
   {
      /* Set very low threshold so current temperature triggers alarm */
      PVT1_CTRL4_ADDR = TEST_STUB_PVT_ALARM_THR * CTRL_PVT1_ACC_LEN;
      PVT1_CTRL4_ADDR |= ((TEST_STUB_PVT_ALARM_THR * CTRL_PVT1_ACC_LEN) << CTL_PVT1_ALARM1_THR_OFFSET);
   }
}
#endif
#if (ENABLE_SQT_TEST_STUBS == TRUE)
/******************************************************************************
 * Name:  Thermal_Monitor_TestManager
 *   This function is the main entry point for all thermal monitor SQT tests.
 *   It should be called periodically (e.g., from a scheduler or main loop)
 *   during SQT testing. The test manager checks the test stub variables and
 *   executes the appropriate test functions.
 *
 * Shared Variables: Test_Stub_PVT_Alarm_Threshold
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *   How to use:
 *   1. Set Test_Stub_PVT_Alarm_Threshold = 1U (via XCP/debugger) for PVT0/FCRU4 test
 *   2. Set Test_Stub_PVT_Alarm_Threshold = 2U (via XCP/debugger) for PVT1/FCRU5 test
 *   3. Call Thermal_Monitor_TestManager() - it will execute the appropriate test
 *
 *   Call Location Options:
 *   - From IoHwAb periodic runnable (e.g., RE_IoHwAb_10ms)
 *   - From a dedicated SQT test task
 *   - Manually via debugger breakpoint
 *
 ******************************************************************************/
void Thermal_Monitor_TestManager(void)
{
   /*------------------------------------------------------------------------
    * Test 1: PVT0 Alarm Threshold Test (FCRU4)
    * When Test_Stub_PVT_Alarm_Threshold == 1U, lowers PVT0 threshold
    * to trigger FCRU FAULT_04 reset
    *------------------------------------------------------------------------*/
   if (Test_Stub_PVT_Alarm_Threshold == 1U)
   {
      Thermal_Monitor_Test_PVT0_Alarm();
   }
   /*------------------------------------------------------------------------
    * Test 2: PVT1 Alarm Threshold Test (FCRU5)
    * When Test_Stub_PVT_Alarm_Threshold == 2U, lowers PVT1 threshold
    * to trigger FCRU FAULT_05 reset
    *------------------------------------------------------------------------*/
   else if (Test_Stub_PVT_Alarm_Threshold == 2U)
   {
      Thermal_Monitor_Test_PVT1_Alarm();
   }
}
#endif
