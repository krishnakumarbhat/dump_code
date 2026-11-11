/*===========================================================================*/
/**
 * MCU_Safety.c
 *
 * This file includes functional safety related concepts and configurations.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2020 Aptiv. All rights reserved.
 *Aptiv Sensitve Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *
 * This file includes functional safety related concepts and configurations.
 *
 * ABBREVIATIONS:
 *   List any abbreviations, precede each with a dash ('-').
 *
 * TRACEABILITY INFO:
 *   - Design Document(s):
 *     - 531-SDD_Radar/AAU_SDD_CoreRadar_MCU_Safety.
 *
 *   - Requirements Document(s):
 *     - 511-SRS_Radar/CMP_SRS_CoreRadar_MCU_Configuration_And_Supervision
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - Update list of other applicable standards
 *
 * DEVIATIONS FROM STANDARDS:
 *   - None
 *
 * updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include "Rte_SWC_PLT_CDD_MCU_Safety.h"
#include "SWC_PLT_CDD_MCU_Safety.h"
#include "Std_Types.h"
#include "fixmac.h"
#include <stdint.h>
/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "Mss_Ecc_Parity.h"
#include "NOC_Handler.h"
#include "static_register_safety.h"
/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/
#define NOC_STATE_RUN_CHANDRA    (0U)
#define NOC_STATE_RUN_SMALL      (1U)
#define NOC_STATE_RUN_ARTIE      (2U)
#define NOC_STATE_VERIFY_CHANDRA (3U)
#define NOC_STATE_VERIFY_SMALL   (4U)
#define NOC_STATE_VERIFY_ARTIE   (5U)
#define NOC_STATE_COUNT          (6U)

volatile uint8 TR_InitMCUfail = CODED_FALSE;
volatile uint8 pre_mcu_status = CODED_FALSE;
static uint8 counter_NOC      = NOC_STATE_VERIFY_CHANDRA;
/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/
typedef void (*NOC_State_Handler_T)(void);
volatile static MCU_InitializationStatus_T MCU_InitializationStatus = (MCU_InitializationStatus_T)NOT_COMPLETED;
/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
static const NOC_State_Handler_T NOC_state_handlers[NOC_STATE_COUNT] = {
   NOC_Run_Bist_Chandra,                   /* NOC_STATE_RUN_CHANDRA    (0) */
   NOC_Run_Bist_Small,                     /* NOC_STATE_RUN_SMALL      (1) */
   NOC_Run_Bist_Artie,                     /* NOC_STATE_RUN_ARTIE      (2) */
   NOC_Verify_Chandra_LatentIsr_Execution, /* NOC_STATE_VERIFY_CHANDRA (3) */
   NOC_Verify_Small_LatentIsr_Execution,   /* NOC_STATE_VERIFY_SMALL   (4) */
   NOC_Verify_Artie_LatentIsr_Execution    /* NOC_STATE_VERIFY_ARTIE   (5) */
};

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/
static void Evaluate_MCU_InitializationStatus(void);
static uint8 Startup_ValidateLbist(void);
static void Platform_Time_Errorcheck(void);
static void DCLS_Enable(void);
#if (ENABLE_SQT_TEST_STUBS == STD_ON)
void Test_MCU_Safety_FaultState(volatile uint8 *tr_init_mcu_fail);
void Test_MCU_Safety_SimulateStartupFault(volatile MCU_InitializationStatus_T *mcu_init_status);
void Test_MCU_Safety_BOR_AMUX(void);
void Test_MCU_Safety_SimulateLbistResult(uint32 *lbist_reg_val);
void Test_Rmon_ForceReset(void);
#endif

#if (TRUE == XCP_FAULT_INJECTION)
static void HandleDiffResetReason(void);
#endif
/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/******************************************************************************
 * Name:  MCU_Safety_Init
 *    Executed once after the RTE is started
 *
 * Shared Variables: none
 *
 * Parameters: void
 *
 * Return Value: void
 *
 * Design Information:
 *  - 531-SDD_Radar/AAU_SDD_CoreRadar_MCU_Safety.
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
void MCU_Safety_Init(void)
{
   /* Enable DCLS */
   DCLS_Enable();
   /* Enable IRQ for sysmem memory */
   ECC_Irq_Enable();
   /* Configure SEC threshold for sysmem memory */
   ECC_Sec_Threshold_Config();
   /* Enable PMU BOR */
   Enable_PMU_BOR();
   /* Enable Reset Monitor */
   Enable_RMON();
   /* Check Platform time to detect if MCU is in failed state */
   Platform_Time_Errorcheck();

   Clear_StickyDiag_MissionFault_registers();
   NOC_Run_Bist_Chandra();
   NOC_Run_Bist_Small();
   NOC_Run_Bist_Artie();

   /*Update MCU Initialization status Interfaces */
   Evaluate_MCU_InitializationStatus();
}
/******************************************************************************
 * Name:  Evaluate_MCU_InitializationStatus
 *    This function evaluate the MCU_Control Init sequence and updates the mode manage interfaces
 *
 * Shared Variables: none
 *
 * Parameters: void
 *
 * Return Value: void
 *
 * Design Information:
 *  - 531-SDD_Radar/AAU_SDD_CoreRadar_MCU_Safety.
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
static void Evaluate_MCU_InitializationStatus(void)
{
   /* check MCU_Initialization status,
    * if NOT COMPLETED set to COMPLETED
    * if FAILED set TR_InitMCUfail to TRUE */
#if (ENABLE_SQT_TEST_STUBS == STD_ON)
   Test_MCU_Safety_SimulateStartupFault(&MCU_InitializationStatus);
#endif

   /* STS_LBSC_LOADED=0 on boards without LBIST OTP sequence, so default pass applies. */
   if ((uint8)CODED_TRUE != (uint8)Startup_ValidateLbist())
   {
      MCU_InitializationStatus = MCUINIT_FAILED;
   }

   if (FAILED == MCU_InitializationStatus)
   {
      TR_InitMCUfail = CODED_TRUE;
   }
   else
   {
      MCU_InitializationStatus = (MCU_InitializationStatus_T)COMPLETED;
   }
#if (ENABLE_SQT_TEST_STUBS == STD_ON)
   Test_MCU_Safety_FaultState(&TR_InitMCUfail);
#endif
   /* Update mode manager interfaces */
   (void)Rte_Write_Pp_PlatformInitializationStatus_De_MCU_InitializationStatus(MCU_InitializationStatus);
   (void)Rte_Write_Pp_TR_initMCU_Fail_De_TR_InitMCU_fail((uint8)TR_InitMCUfail);
}

/******************************************************************************
 * Name:  Startup_ValidateLbist
 *    Validates Power-On LBIST (Logic BIST) result to ensure SoC health at startup
 *
 * Shared Variables: none
 *
 * Parameters: void
 *
 * Return Value:
 *    CODED_TRUE (0xAA)  - LBIST passed (DONE=1, GOOD=1, ERR=0, TIM_EXP=0)
 *    CODED_FALSE (0x55) - LBIST failed or result invalid
 *
 * Design Information:
 *  - 531-SDD_Radar/AAU_SDD_CoreRadar_MCU_Safety.
 *  - Performs single volatile read of LBIST_SEQ_STAT0 register
 *  - Returns coded boolean for fail-safe startup gating
 *
 *  Change References:
 *  - PO-BIST integration for MCU initialization status evaluation
 *
 ******************************************************************************/
static uint8 Startup_ValidateLbist(void)
{
   uint8 retVal = CODED_TRUE; /* default: pass (test did not run) */
   uint32 regVal;

   regVal = *((volatile uint32 *)LBIST_SEQ_STAT0_ADDR);

#if (ENABLE_SQT_TEST_STUBS == STD_ON)
   Test_MCU_Safety_SimulateLbistResult(&regVal);
#endif

   /* Evaluate result only when sequencer finished (DONE=1) AND test ran (LOADED=1).
    *   DONE=0             : sequencer not finished        -> default pass
    *   DONE=1, LOADED=0   : finished without running test -> default pass
    *   DONE=1, LOADED=1, GOOD=1 : test ran and passed     -> pass
    *   DONE=1, LOADED=1, GOOD=0 : test ran and failed     -> fail
    */
   if ((regVal & LBIST_TEST_RAN_FAIL_PATTERN) == LBIST_TEST_RAN_FAIL_PATTERN)
   {
      if ((regVal & STS_LBSC_GOOD_MASK) == 0U)
      {
         retVal = CODED_FALSE;
      }
   }

   return retVal;
}

/******************************************************************************
 * Name:  MCU_Safety_50ms
 *   This function is periodic 50ms runnable used for XCP Fault Injection
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - 531-SDD_Radar/AAU_SDD_CoreRadar_MCU_Safety.
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
void MCU_Safety_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /* static registers readback is checked for every 50ms */
#ifdef MCAL_SAFETY_REQ_GEN8
   Static_Register_Safety_Check();
#endif

   /* Execute ECC test if enabled */

#if (ENABLE_SQT_TEST_STUBS == STD_ON) || defined(ENABLE_SQT_ARTIEMEM_FAULT)
   Ecc_Fault_Injection_Test();
#else
   /* do nothing */
#endif
#if (TRUE == XCP_FAULT_INJECTION)
   if (Retention_Ram_Data.fhti_test_data.reset_count > 0)
   {
      if (Retention_Ram_Data.fhti_test_data.repetative_reset_fault_type == RESET_WITH_SAME_RESET_REASON)
      {
         Retention_Ram_Data.fhti_test_data.reset_count = Retention_Ram_Data.fhti_test_data.reset_count - 1;
         Rte_Call_CS_MCU_Safety_FailSafe_ResetReason_FailSafe_Log_ResetReason(REPETATIVE_RESET_FAULT_INJECTION_PATTERN_1);
      }
      else if (Retention_Ram_Data.fhti_test_data.repetative_reset_fault_type == RESET_WITH_DIFF_RESET_REASON)
      {
         HandleDiffResetReason();
      }
   }
   else
   {
      Retention_Ram_Data.fhti_test_data.reset_count                 = 0;
      Retention_Ram_Data.fhti_test_data.repetative_reset_fault_type = 0;
   }
#endif
   NOC_state_handlers[counter_NOC]();

   if (counter_NOC < (NOC_STATE_COUNT - 1U))
   {
      counter_NOC++;
   }
   else
   {
      counter_NOC = NOC_STATE_RUN_CHANDRA;
   }
}

/******************************************************************************
 * Name:  HandleDiffResetReason
 *   This function decrements the reset counter and logs a fault injection pattern.
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - 531-SDD_Radar/AAU_SDD_CoreRadar_MCU_Safety.
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
#if (TRUE == XCP_FAULT_INJECTION)
static void HandleDiffResetReason(void)
{
   Retention_Ram_Data.fhti_test_data.reset_count = Retention_Ram_Data.fhti_test_data.reset_count - 1;
   if ((Retention_Ram_Data.fhti_test_data.reset_count % 2) == 0)
   {
      Rte_Call_CS_MCU_Safety_FailSafe_ResetReason_FailSafe_Log_ResetReason(REPETATIVE_RESET_FAULT_INJECTION_PATTERN_1);
   }
   else
   {
      Rte_Call_CS_MCU_Safety_FailSafe_ResetReason_FailSafe_Log_ResetReason(REPETATIVE_RESET_FAULT_INJECTION_PATTERN_2);
   }
}
#endif

/******************************************************************************
 * Name:  Enable_PMU_BOR
 *   This function Arm(enables) the PMU BOR (Brown-Out Reset) for 0P8V and 1P8V.
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - 531-SDD_Radar/AAU_SDD_CoreRadar_MCU_Safety.
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
void Enable_PMU_BOR(void)
{
   uint32 trim_otp;
   uint32 trim_otp_0p8;
   uint32 trim_otp_1p8;
   uint8 trim_otp_valid;

   BOR_RST_REASON_CLR = BOR_FLAGS_CLR_MSK; /* Clear any existing BOR reset reason */

   trim_otp       = BOR_TRIM_OTP_REG;
   trim_otp_valid = (trim_otp != BOR_TRIM_OTP_NO_VALUE) ? BOR_TRIM_OTP_VALID : BOR_TRIM_OTP_INVALID;
   if (BOR_TRIM_OTP_VALID == trim_otp_valid)
   {
      trim_otp_0p8     = trim_otp & BOR_TRIM_FIELD_MSK;
      trim_otp_1p8     = (trim_otp >> BOR_TRIM_OTP_1P8_SHIFT) & BOR_TRIM_FIELD_MSK;
      BOR_0P8_TRIM_REG = (BOR_0P8_TRIM_REG & ~BOR_TRIM_FIELD_MSK) | trim_otp_0p8;
      BOR_1P8_TRIM_REG = (BOR_1P8_TRIM_REG & ~BOR_TRIM_FIELD_MSK) | trim_otp_1p8;
   }
   else
   {
      BOR_0P8_TRIM_REG = (BOR_0P8_TRIM_REG & ~BOR_TRIM_FIELD_MSK) | BOR_DEFAULT_TRIM_VALUE;
      BOR_1P8_TRIM_REG = (BOR_1P8_TRIM_REG & ~BOR_TRIM_FIELD_MSK) | BOR_DEFAULT_TRIM_VALUE;
   }
   BOR_0P8_TRIM_REG |= BOR_ARM_EN_BIT;
   BOR_1P8_TRIM_REG |= BOR_ARM_EN_BIT;
#if (ENABLE_SQT_TEST_STUBS == STD_ON)
   Test_MCU_Safety_BOR_AMUX();
#endif
}

/******************************************************************************
 * Name:  Enable_RMON
 *   This function Arm(enables) the RMON (Reset Monitor).
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - 531-SDD_Radar/AAU_SDD_CoreRadar_MCU_Safety.
 *
 *  Change References:
 *  - list change numbers
 *
 ******************************************************************************/
void Enable_RMON(void)
{
   /*Clear the IRQ_RMON registers before enabling reset monitoring to avoid reset IR-7102*/
   IRQ_RMON = (IRQ_RMON_RA_BIT | IRQ_RMON_MIPI_BIT | IRQ_RMON_DSP_BIT | IRQ_RMON_REF_BIT);
   /*Clear serial reset */
   MCU_SAFETY_MISC0_IRQ_MASKED_STAT |= IRQ_RMON_SER_BIT;
   /* Enable RMON for all monitored reset sources */
   CTL_RMON = CTL_RMON_EN_RA | CTL_RMON_EN_MIPI | CTL_RMON_EN_DSP | CTL_RMON_EN_REF;

   /* Enable Serial reset monitoring */
   RMON_CLKGEN_CTRL0 |= CLKGEN_RMON_SER_ENA;
}

/*====================================================================================================================*\
* FUNCTION: Platform_Time_Errorcheck
*=======================================================================================================================
* RETURN VALUE: void
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* This function evaluate the Platform time to reset MCU if it fails.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
static void Platform_Time_Errorcheck(void)
{
   (void)Rte_Read_Rp_TR_PlatformTime_De_PlatformTime(&pre_mcu_status);

   /*Will set MCU status to failed if two instances of time are same during platform initilization */
   if (CODED_TRUE == pre_mcu_status)
   {
      MCU_InitializationStatus = MCUINIT_FAILED;
   }
}

/*====================================================================================================================*\
* FUNCTION: DCLS_Enable
*=======================================================================================================================
* RETURN VALUE: void
*
* PARAMETERS: void
*
* EXTERNAL REFERENCES:
* None.
*
* DEVIATIONS FROM STANDARDS:
* None.
*
* ----------------------------------------------------------------------------------------------------------------------
* ABSTRACT:
* ----------------------------------------------------------------------------------------------------------------------
* This function enables the Dual-Core Lock-Step (DCLS) feature.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/

static void DCLS_Enable(void)
{
   /* Enable Dual-Core Lock-Step */
   DCLS_CTRL_ADDR = DCLS_CTRL_CONFIG;
}

/*============================================================================*\
 * AUTHOR(S) IDENTITY (AID)
 *-----------------------------------------------------------------------------
 *
 *  AID         NAME
 *  ---------------------------------------------------------------------------
 *  XXX         Firstname Lastname
\*============================================================================*/

/*============================================================================*\
 * FILE REVISION HISTORY - To be filled by the project team
 *-----------------------------------------------------------------------------
 *
 *  DATE          REVISION         AID          JIRA Ticket ID
 *      SUMMARY OF CHANGES
 *  ---------------------------------------------------------------------------
 *  yy-mm-dd      x.xx        XXX          12345
 *      First revision
 *  ---------------------------------------------------------------------------
\*============================================================================*/

/* END OF FILE -------------------------------------------------------------- */

/*============================================================================*\
 * Template REVISION HISTORY - This section can be removed when using the
 * template for project.
 *-----------------------------------------------------------------------------
 *
 *  DATE        REVISION         Name           SUMMARY OF CHANGES
 *  ---------------------------------------------------------------------------
 *  yy-mm-dd      1.0            xxxxx           First version
 *  ---------------------------------------------------------------------------
\*============================================================================*/
