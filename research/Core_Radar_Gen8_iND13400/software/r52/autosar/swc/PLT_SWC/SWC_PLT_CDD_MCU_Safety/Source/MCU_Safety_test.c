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
 *             File:  MCU_Safety_test.c

 *********************************************************************************************************************/
#include "Rte_SWC_PLT_CDD_MCU_Safety.h"
#include "SWC_PLT_CDD_MCU_Safety.h"
#include "dd_cmu.h"
#include "reuse.h"

#if (ENABLE_SQT_TEST_STUBS == STD_ON)
   /* BOR AMUX test stub */
   #define AMUX_CTRL_ADDR        (*(volatile uint32 *)(0x89002030U))
   #define SET_AMUX_CTRL_BIT_0P8 (1U << 14)
   #define SET_AMUX_CTRL_BIT_1P8 (1U << 15)
   #define TEST_STUB_TRIM_0P8    (1U)
   #define TEST_STUB_TRIM_1P8    (2U)

volatile int MCU_Safety_Test_Stub          = 0;
volatile uint8 Test_Stub_Mcu_Startup_Fault = 0;
volatile uint8 Test_stub_Trim_value        = 0;
volatile uint8 Test_RMON_Variable          = 0;
/* 0=no override, 1=simulate pass, 2=simulate fail */
volatile uint8 MCU_Safety_LBIST_Test_Stub = 0U;
volatile uint8_t exception_test           = 0;
volatile uint8_t CMU_Test_Stub            = 0;
volatile uint8_t Test_Clock_Monitor       = 0;

/* Forward declarations */
void Test_Rmon_ForceReset(void);
#endif
#if (ENABLE_SIT_TEST_STUBS == STD_ON)
volatile uint8_t test_log_resetreason = 0;
#endif
/******************************************************************************
 * Name:  IllegalInstructionExceptionTest
 *   This function is used to test the IllegalInstruction exception
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 *
 * Add Polarion Work Item Link to the intended line (if using Resource Link
 * for traceability)
 * Syntax:
 * @wi.<LinkRoleAsSingleWord> <PolarionProjectID>/<workitemID>
 * example:
 * @wi.implemented PDP2.0_playground/WI-5001
 *
 ******************************************************************************/
#if (ENABLE_SQT_TEST_STUBS == STD_ON)
void IllegalInstructionExceptionTest(void)
{
   __asm volatile("udf #0");
}
#endif
/******************************************************************************
 * Name:  DataAbortExceptionTest
 *   This function is used to test the DataAbortException exception
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 *
 * Add Polarion Work Item Link to the intended line (if using Resource Link
 * for traceability)
 * Syntax:
 * @wi.<LinkRoleAsSingleWord> <PolarionProjectID>/<workitemID>
 * example:
 * @wi.implemented PDP2.0_playground/WI-5001
 *
 ******************************************************************************/
#if (ENABLE_SQT_TEST_STUBS == STD_ON)
void DataAbortExceptionTest(void)
{
   __asm("MOV R9, #0xFFFFFFFF ");
   __asm("LDR R10, [R9] ");
}
#endif
/******************************************************************************
 * Name:  PreftechAbort_ExceptionTest
 *   This function is used to test  Prefetch Exception abort
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 *
 * Add Polarion Work Item Link to the intended line (if using Resource Link
 * for traceability)
 * Syntax:
 * @wi.<LinkRoleAsSingleWord> <PolarionProjectID>/<workitemID>
 * example:
 * @wi.implemented PDP2.0_playground/WI-5001
 *
 ******************************************************************************/
#if (ENABLE_SQT_TEST_STUBS == STD_ON)
void PreftechAbort_ExceptionTest(void)
{
   __asm("mov r0, #0xFFFFFFFF ");
   __asm("mov PC, r0");
}
#endif
/******************************************************************************
 * Name:  CMU_Test
 *   This function is used to test  Clock Monitoring Unit
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 *
 * Add Polarion Work Item Link to the intended line (if using Resource Link
 * for traceability)
 * Syntax:
 * @wi.<LinkRoleAsSingleWord> <PolarionProjectID>/<workitemID>
 * example:
 * @wi.implemented PDP2.0_playground/WI-5001
 *
 ******************************************************************************/
#if (ENABLE_SQT_TEST_STUBS == STD_ON)
void CMU_Test(void)
{
   switch (Test_Clock_Monitor)
   {
      case 1:
         ADDR_CLK_TOP_CTRL &= ~(CTL_CG_RA_CKEN_MASK);
         break;
      case 2:
         ADDR_CLK_TOP_CTRL &= ~(CTL_CG_DSP_CKEN_MASK);
         break;
      case 3:
         ADDR_CLK_TOP_CTRL &= ~CTL_CG_MIPI_CKEN_MASK;
         break;
      case 4:
         ADDR_CLK_TOP_CTRL &= ~(CTL_CG_SERIAL_CKEN_MASK);
         break;
      default:
         break;
   }
   Test_Clock_Monitor = 0;
   CMU_Test_Stub      = 0;
}
#endif
/******************************************************************************
 * Name:  MCU_Safety_TestManager
 *   This function is used to test all SQT's
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 *
 * Add Polarion Work Item Link to the intended line (if using Resource Link
 * for traceability)
 * Syntax:
 * @wi.<LinkRoleAsSingleWord> <PolarionProjectID>/<workitemID>
 * example:
 * @wi.implemented PDP2.0_playground/WI-5001
 *
 ******************************************************************************/
#if (ENABLE_SQT_TEST_STUBS == STD_ON)
void MCU_Safety_TestManager(void)
{
   if (exception_test == 1)
   {
      IllegalInstructionExceptionTest();
   }

   if (exception_test == 2)
   {
      PreftechAbort_ExceptionTest();
   }
   if (exception_test == 3)
   {
      DataAbortExceptionTest();
   }
   if ((Test_stub_Trim_value == 1U) || (Test_stub_Trim_value == 2U))
   {
      Enable_PMU_BOR();
   }
   if (CMU_Test_Stub == 1)
   {
      CMU_Test();
   }
   if ((Test_RMON_Variable >= RMON_RST_SYS) && (Test_RMON_Variable <= RMON_RST_ART_SER))
   {
      Test_Rmon_ForceReset();
   }
}
#endif
/******************************************************************************
 * Name:  MCU_Safety_Integration_Test
 *   This function is used to test all SIT's
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - reference design document
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
#if (ENABLE_SIT_TEST_STUBS == STD_ON)
void MCU_Safety_Integration_Test(void)
{
   if (test_log_resetreason == 1)
   {
      Rte_Call_CS_MCU_Safety_FailSafe_ResetReason_FailSafe_Log_ResetReason(0xAAU);
   }
}

#endif
/******************************************************************************
 * Name:  Test_MCU_Safety_FaultState
 *   This function includes stub code to verify MCU initialization fault state
 *   interfaces for safety validation
 *
 * Shared Variables: none
 *
 * Parameters: uint8 *   - Pointer to the TR_InitMCU_Fail fault state variable
 *
 * Return Value: none
 *
 * Design Information:
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
#if (ENABLE_SQT_TEST_STUBS == STD_ON)
void Test_MCU_Safety_FaultState(volatile uint8 *tr_init_mcu_fail)
{
   if (MCU_Safety_Test_Stub == 1U)
   {
      *tr_init_mcu_fail = CODED_FALSE;
   }
   if (MCU_Safety_Test_Stub == 2U)
   {
      *tr_init_mcu_fail = CODED_TRUE;
   }
}
#endif
/******************************************************************************
 * Name:  Test_MCU_Safety_SimulateStartupFault
 *   This function injects an MCU startup fault by setting the initialization
 *   status to FAILED when Test_Stub_Mcu_Startup_Fault is set to 1
 *
 * Shared Variables: none
 *
 * Parameters: MCU_InitializationStatus_T *   - Pointer to the MCU init status
 *
 * Return Value: none
 *
 * Design Information:
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
#if (ENABLE_SQT_TEST_STUBS == STD_ON)
void Test_MCU_Safety_SimulateStartupFault(volatile MCU_InitializationStatus_T *mcu_init_status)
{
   if (Test_Stub_Mcu_Startup_Fault == 1U)
   {
      *mcu_init_status = MCUINIT_FAILED;
   }
}
#endif
/******************************************************************************
 * Name:  Test_MCU_Safety_BOR_AMUX
 *   This function exercises the BOR AMUX control lines for 0P8V and 1P8V
 *   BOR trim verification via the AMUX output
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
#if (ENABLE_SQT_TEST_STUBS == STD_ON)
void Test_MCU_Safety_BOR_AMUX(void)
{
   if (Test_stub_Trim_value == TEST_STUB_TRIM_0P8)
   {
      AMUX_CTRL_ADDR |= SET_AMUX_CTRL_BIT_0P8;
   }
   else if (Test_stub_Trim_value == TEST_STUB_TRIM_1P8)
   {
      AMUX_CTRL_ADDR |= SET_AMUX_CTRL_BIT_1P8;
   }
}
#endif
/******************************************************************************
 * Name:  Test_Rmon_ForceReset
 *   This function tests the RMON reset forcing mechanism by writing to the appropriate control registers
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
#if (ENABLE_SQT_TEST_STUBS == STD_ON)

void Test_Rmon_ForceReset(void)
{
   switch (Test_RMON_Variable)
   {
      case RMON_RST_SYS:
         RMON_CTRL0 |= RMON_CTRL0_SYS_FRC;
         RMON_CTRL0 &= ~RMON_CTRL0_SYS_FRC;
         break;

      case RMON_RST_R52_CORE:
         RMON_CTRL0 |= RMON_CTRL0_R52_CORE_FRC;
         RMON_CTRL0 &= ~RMON_CTRL0_R52_CORE_FRC;
         break;

      case RMON_RST_R52_TOP:
         RMON_CTRL0 |= RMON_CTRL0_R52_TOP_FRC;
         RMON_CTRL0 &= ~RMON_CTRL0_R52_TOP_FRC;
         break;

      case RMON_RST_RA:
         CTL_RMON |= CTL_RMON_FRC_RA;
         CTL_RMON &= ~CTL_RMON_FRC_RA;
         break;

      case RMON_RST_MIPI:
         CTL_RMON |= CTL_RMON_FRC_MIPI;
         CTL_RMON &= ~CTL_RMON_FRC_MIPI;
         break;

      case RMON_RST_DSP:
         CTL_RMON |= CTL_RMON_FRC_DSP;
         CTL_RMON &= ~CTL_RMON_FRC_DSP;
         break;

      case RMON_RST_REF:
         CTL_RMON |= CTL_RMON_FRC_REF;
         CTL_RMON &= ~CTL_RMON_FRC_REF;
         break;

      case RMON_RST_ART_SER:
         RMON_CLKGEN_CTRL0 |= CLKGEN_RMON_SER_FRC;
         RMON_CLKGEN_CTRL0 &= ~CLKGEN_RMON_SER_FRC;
         break;

      default:
         /* Invalid input: no action */
         break;
   }
}

#endif

/******************************************************************************
 * Name:  Test_MCU_Safety_SimulateLbistResult
 *   This function injects a simulated LBIST register value to force a pass or
 *   fail result in Startup_ValidateLbist without requiring hardware state.
 *   MCU_Safety_LBIST_Test_Stub == 1 simulates a passing LBIST result.
 *   MCU_Safety_LBIST_Test_Stub == 2 simulates a failing LBIST result.
 *
 * Shared Variables: none
 *
 * Parameters: uint32 *   - Pointer to the LBIST register value to override
 *
 * Return Value: none
 *
 * Design Information:
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
#if (ENABLE_SQT_TEST_STUBS == STD_ON)
void Test_MCU_Safety_SimulateLbistResult(uint32 *lbist_reg_val)
{
   if (MCU_Safety_LBIST_Test_Stub == 1U)
   {
      *lbist_reg_val = LBIST_PASS_VALUE; /* Inject passing LBIST result: DONE=1, LOADED=1, GOOD=1 (0x07) */
   }
   else if (MCU_Safety_LBIST_Test_Stub == 2U)
   {
      *lbist_reg_val = LBIST_TEST_RAN_FAIL_PATTERN; /* Inject failing LBIST result: DONE=1, LOADED=1, GOOD=0 (0x03) */
   }
}
#endif
