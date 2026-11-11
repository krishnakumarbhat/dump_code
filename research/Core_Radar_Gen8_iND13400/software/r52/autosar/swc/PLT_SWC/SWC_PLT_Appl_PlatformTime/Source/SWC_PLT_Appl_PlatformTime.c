/**********************************************************************************************************************
 *  FILE
 * REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *
 * -------------------------------------------------------------------------------------------------------------------
 *  This
 * file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete
 * and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in
 * series production without applying suitable quality measures.
 *  The template code must be completed as described in the
 * instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with
 * diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before
 * its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE
 * DESCRIPTION
 *
 * -------------------------------------------------------------------------------------------------------------------
 * File:
 * SWC_PLT_Appl_PlatformTime.c
 *           Config:  Gen8_iND13400.dpa
 *        SW-C Type:  SWC_PLT_Appl_PlatformTime
 *
 *
 * Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:
 * PAI19494
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PLT_Appl_PlatformTime>

 * *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 *
 * AUTOSAR Modelling Object Descriptions
 *

 * **********************************************************************************************************************
 *
 *
 * Data Types:
 * ===========
 * Dt_Fault_name_FHTI
 *   uint8 represents integers with a minimum value of 0 and a maximum value of
 * 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting
 * of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *

 * *********************************************************************************************************************/

#include "Rte_SWC_PLT_Appl_PlatformTime.h"
#include "SWC_PLT_Appl_PlatformTime_cfg.h"
#include "chandra_sfrs_base.h"
#include "platformtime.h"
#include "timers_sfrs.h"
#if (TRUE == XCP_FAULT_INJECTION)
   #include "retention_ram_data.h"
#endif
/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *
 * *********************************************************************************************************************/
static uint64_t s_prev_us  = 0ULL;
static uint32_t s_us_carry = 0u;
static uint32_t s_ms_total = 0u;
static uint32_t s_ms_delta = 0u;
/* Cumulative 32-bit hardware counter wraps since first Get_Platform_ustime call.
 * Declared at file scope (not as a local static) so that:
 *  - it is visible to static analysis tools and resets deterministically in tests,
 *  - the XCP unfreeze handler can reset it atomically alongside the other
 *    accumulator state, preventing overflow-count loss across freeze/unfreeze cycles. */
static uint64_t s_ustime_total_over = 0ULL;
#if (TRUE == XCP_FAULT_INJECTION)
/* Controls PlatformTime.usTime freeze injection (Failure Type 0x00).
 * TRUE  : usTime output is held at 0 µs and does not increment.
 * FALSE : nominal usTime operation. */
static uint8_t s_plt_fi_ustime_frozen = FALSE;
/* Controls PlatformTime.usTime resolution injection (Failure Type 0x01).
 * 0x00 : 1 µs resolution (nominal)
 * 0x01 : 0.5 µs resolution
 * 0x02 : 2 µs resolution */
static uint8_t s_plt_fi_ustime_res_ic = 0x00U;
#endif
#if (TRUE == ENABLE_SIT_TEST_STUBS)
volatile uint32 Test_instant_ustime         = 0u;
volatile uint32 Test_elapsed_instant_ustime = 0u;
volatile uint64 Test_start_time             = 0u;
#endif
volatile uint32_t previous_ticks = 0xFFFFFFFF;
volatile uint32_t current_ticks;
/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * Used
 * AUTOSAR Data Types
 *

 * **********************************************************************************************************************
 *
 *
 * Primitive Types:
 * ================
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint64: Integer in
 * interval [0...18446744073709551615] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration
 * Types:
 * ==================
 * Dt_Fault_name_FHTI: Enumeration of integer in interval [0...255] with enumerators
 *
 * SMC_CHECKSUM_FAULT (0U)
 *   USC_VALIDATION_FAULT (1U)
 *   MMIC_B_ID_FAULT (2U)
 *   MMIC_TEMPERATURE_HIGH_FAULT (3U)
 *
 * MMIC_TEMPERATURE_LOW_FAULT (4U)
 *   MMIC_A_SAFESTART (5U)
 *   MMIC_B_SAFESTART (6U)
 *   MMIC_A_SAFETY_INTEGRITY_RFBIST (7U)

 * *   MMIC_A_SENSOR_FAULT (8U)
 *   MMIC_TEMPERATURE_CONSISTANCY_FAILURE (9U)
 *   PLATFORM_TIME_FAULT (10U)
 *
 * TX_BALL_BREAK_FAULT (11U)
 *   BLOCKAGE_ALGO_ERROR_FAULT (12U)
 *   MCU_STARTUP_FAULT (13U)
 *   MCU_REPETATIVE_RESET_FAULT
 * (14U)
 *   A53_TO_CM7_IPC_FAULT (15U)
 *   CM7_TO_DSP_IPC_FAULT (16U)
 *   EDMA_FAULT_CALIBRATION (17U)
 *
 * DSP_TO_A53_IPC_FAULT (18U)
 *   DSP_TO_CM7_IPC_FAULT (19U)
 *   MAX_FAULT_NUMBER (20U)
 *

 * *********************************************************************************************************************/

#define SWC_PLT_Appl_PlatformTime_START_SEC_CODE
#include "SWC_PLT_Appl_PlatformTime_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 *
 * Runnable Entity Name: CS_Get_Platform_Elapsed_ustime_read
 *
 * This runnable can be invoked concurrently (reentrant
 * implementation).
 *

 * *---------------------------------------------------------------------------------------------------------------------
 *
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for
 * OperationPrototype <read> of PortPrototype <CS_Get_Platform_Elapsed_ustime>
 *

 * **********************************************************************************************************************
 *
 *
 * Runnable prototype:
 * ===================
 *   void CS_Get_Platform_Elapsed_ustime_read(uint32 *inst_us_time, uint64
 * start_time)
 *

 * *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol:
 * CS_Get_Platform_Elapsed_ustime_read_doc

 * *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_PlatformTime_CODE)
CS_Get_Platform_Elapsed_ustime_read(P2VAR(uint32, AUTOMATIC, RTE_SWC_PLT_APPL_PLATFORMTIME_APPL_VAR) inst_us_time,
                                    uint64 start_time) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
   * DO
    * NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
   *
    * Symbol: CS_Get_Platform_Elapsed_ustime_read

    * *********************************************************************************************************************/
#if (TRUE == ENABLE_SIT_TEST_STUBS)
   Test_elapsed_instant_ustime = *inst_us_time;
   Test_start_time             = start_time;
#endif
   Get_Platform_Elapsed_ustime(inst_us_time, start_time);
   /**********************************************************************************************************************
   * DO
    * NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!

    * *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 *
 * Runnable Entity Name: CS_PlatformTime_Fault_Injection
 *

 * *---------------------------------------------------------------------------------------------------------------------
 *
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for
 * OperationPrototype <Read> of PortPrototype <CS_PlatformTime_Fault_Injection>
 *

 * **********************************************************************************************************************
 *
 *
 * Runnable prototype:
 * ===================
 *   void CS_PlatformTime_Fault_Injection(uint8 Injection_control, uint8
 * Failure_Type)
 *

 * *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol:
 * CS_PlatformTime_Fault_Injection_doc

 * *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/
FUNC(void, SWC_PLT_Appl_PlatformTime_CODE)
CS_PlatformTime_Fault_Injection(uint8 Injection_control, uint8 Failure_Type) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
   * DO
    * NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
   *
    * Symbol: CS_PlatformTime_Fault_Injection

    * *********************************************************************************************************************/

#if (TRUE == XCP_FAULT_INJECTION)
   switch (Failure_Type)
   {
      case 0x00U:
      {
         /* XCP Fault Injection: Failure Type 0x00 - PlatformTime.usTime freeze control.
          * IC=0x01 : Set PlatformTime.usTime to 0 µs and prevent it from incrementing.
          * IC=0x00 : Restore PlatformTime.usTime to nominal behavior at 1 µs resolution. */
         if (Injection_control == 0x01U)
         {
            /* Freeze flag written inside exclusive area to eliminate data race
             * with the concurrent reader in Get_Platform_ustime. Also persisted
             * to no-init retention RAM (Retention_Ram_Data survives warm resets;
             * only cleared on Power-On reset - see Retention_Ram_Data_Init() in
             * main.c) so the freeze is re-applied by Get_PlatformTime_Init after
             * the next system reset. */
            Rte_Enter_PlatformTime_ExclusiveArea();
            s_plt_fi_ustime_frozen                                      = TRUE;
            Retention_Ram_Data.fhti_test_data.plt_usTime_freeze_pending = 1u;
            Rte_Exit_PlatformTime_ExclusiveArea();
         }
         else if (Injection_control == 0x00U)
         {
            uint64_t us_snap = 0ULL;
            /* Clear freeze flag and its retained copy atomically, and reset the
             * usTime resolution scaling to nominal (1 µs), so that "restore
             * nominal usTime behavior" holds even if a prior Failure Type 0x01
             * command had left a non-nominal resolution active. */
            Rte_Enter_PlatformTime_ExclusiveArea();
            s_plt_fi_ustime_frozen                                      = FALSE;
            s_plt_fi_ustime_res_ic                                      = 0x00U;
            Retention_Ram_Data.fhti_test_data.plt_usTime_freeze_pending = 0u;
            Rte_Exit_PlatformTime_ExclusiveArea();
            /* Re-baseline the ms accumulator after restoring nominal usTime:
             *  - s_ustime_total_over is reset so the overflow counter starts
             *    fresh; no accumulated overflows from the freeze period persist.
             *  - s_prev_us is set to the current (real) usTime so subsequent
             *    ms accumulation steps compute correct deltas immediately.
             *  - s_ms_total is intentionally preserved so PlatformTime.msTime
             *    resumes smoothly from its pre-freeze value. */
            Get_Platform_ustime(&us_snap);
            Rte_Enter_PlatformTime_ExclusiveArea();
            s_ustime_total_over = 0ULL;
            s_prev_us           = us_snap;
            s_us_carry          = 0u;
            s_ms_delta          = 0u;
            Rte_Exit_PlatformTime_ExclusiveArea();
         }
         else
         {
            /* invalid IC - no action */
         }
         break;
      }

      case 0x01U:
         /* XCP Fault Injection: Failure Type 0x01 - PlatformTime.usTime resolution control.
          * IC=0x00 : Set PlatformTime.usTime resolution to 1 µs (nominal operation).
          * IC=0x01 : Set PlatformTime.usTime resolution to 0.5 µs.
          * IC=0x02 : Set PlatformTime.usTime resolution to 2 µs. */
         if ((Injection_control == 0x00U) || (Injection_control == 0x01U) || (Injection_control == 0x02U))
         {
            /* Resolution flag written inside exclusive area to eliminate data race
             * with the concurrent reader in Get_Platform_ustime. */
            Rte_Enter_PlatformTime_ExclusiveArea();
            s_plt_fi_ustime_res_ic = Injection_control;
            Rte_Exit_PlatformTime_ExclusiveArea();
         }
         else
         {
            /* invalid IC - no action */
         }
         break;

      case 0x02U:
      {
         /* XCP Fault Injection: Failure Type 0x02 - PlatformTime.msTime direct override.
          * IC=0x00 : Set PlatformTime.msTime to 0 ms.
          * IC=0x01 : Set PlatformTime.msTime to 1 209 540 000 ms.
          * Get_Platform_ustime is called OUTSIDE the exclusive area to prevent a
          * nested exclusive area entry; it manages its own area internally.
          * All shared ms accumulator state is written atomically in a single EA. */
         uint64_t us_snap = 0ULL;
         if ((Injection_control == 0x00U) || (Injection_control == 0x01U))
         {
            Get_Platform_ustime(&us_snap);
            Rte_Enter_PlatformTime_ExclusiveArea();
            s_prev_us  = us_snap;
            s_us_carry = 0u;
            s_ms_delta = 0u;
            if (Injection_control == 0x01U)
            {
               s_ms_total = 1209540000u; /* set PlatformTime.msTime to 1 209 540 000 ms, then resume counting up from there */
            }
            else
            {
               s_ms_total = 0u; /* set PlatformTime.msTime to 0 ms, then resume counting up from there */
            }
            Rte_Exit_PlatformTime_ExclusiveArea();
         }
         else
         {
            /* invalid IC - no action */
         }
         break;
      }

      default:
         /* no action */
         break;
   }
#endif
   /**********************************************************************************************************************
   * DO
    * NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!

    * *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 *
 * Runnable Entity Name: Get_PlatformTime_ms_read
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *

 * *---------------------------------------------------------------------------------------------------------------------
 *
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for
 * OperationPrototype <read> of PortPrototype <Get_PlatformTime_ms>
 *

 * **********************************************************************************************************************
 *
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_PlatformTime_ExclusiveArea(void)
 *   void
 * Rte_Exit_PlatformTime_ExclusiveArea(void)
 *

 * **********************************************************************************************************************
 *
 *
 * Runnable prototype:
 * ===================
 *   void Get_PlatformTime_ms_read(uint32 *instant_mstime)
 *

 * *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol:
 * Get_PlatformTime_ms_read_doc

 * *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_PlatformTime_CODE)
Get_PlatformTime_ms_read(P2VAR(uint32, AUTOMATIC, RTE_SWC_PLT_APPL_PLATFORMTIME_APPL_VAR)
                            instant_mstime) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
   * DO
    * NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
   *
    * Symbol: Get_PlatformTime_ms_read

    * *********************************************************************************************************************/
   Get_Platform_mstime(instant_mstime);

   /**********************************************************************************************************************
   * DO
    * NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!

    * *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 *
 * Runnable Entity Name: Get_PlatfromTime_us_read
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *

 * *---------------------------------------------------------------------------------------------------------------------
 *
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for
 * OperationPrototype <read> of PortPrototype <Get_PlatfromTime_us>
 *

 * **********************************************************************************************************************
 *
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType
 * Rte_Call_CS_Platform_register_set_fault_type(uint8 fault_type)
 *     Synchronous Server Invocation. Timeout: None
 *
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_PlatformTime_ExclusiveArea(void)
 *   void
 * Rte_Exit_PlatformTime_ExclusiveArea(void)
 *

 * **********************************************************************************************************************
 *
 *
 * Runnable prototype:
 * ===================
 *   void Get_PlatfromTime_us_read(uint64 *instant_ustime)
 *

 * *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol:
 * Get_PlatfromTime_us_read_doc

 * *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_PlatformTime_CODE)
Get_PlatfromTime_us_read(P2VAR(uint64, AUTOMATIC, RTE_SWC_PLT_APPL_PLATFORMTIME_APPL_VAR)
                            instant_ustime) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
   * DO
    * NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
   *
    * Symbol: Get_PlatfromTime_us_read

    * *********************************************************************************************************************/
#if (TRUE == ENABLE_SIT_TEST_STUBS)
   Test_instant_ustime = *instant_ustime;
#endif
   Get_Platform_ustime(instant_ustime);
   /**********************************************************************************************************************
   * DO
    * NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!

    * *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 *
 * Runnable Entity Name: RE_Evaluate_Plt_Time_Init
 *

 * *---------------------------------------------------------------------------------------------------------------------
 *
 *
 * Executed once after the RTE is started
 *

 * **********************************************************************************************************************
 *
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType
 * Rte_Write_Pp_TR_platform_Time_De_PlatformTime(uint8 data)
 *

 * *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol:
 * RE_Evaluate_Plt_Time_Init_doc

 * *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_PlatformTime_CODE) RE_Evaluate_Plt_Time_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
   * DO
    * NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
   *
    * Symbol: RE_Evaluate_Plt_Time_Init

    * *********************************************************************************************************************/
   Platform_Ustime_Errorcheck();
   /**********************************************************************************************************************
   * DO
    * NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!

    * *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 *
 * Runnable Entity Name: RE_PLT_PlatformTime_50ms
 *

 * *---------------------------------------------------------------------------------------------------------------------
 *
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *

 * *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol:
 * RE_PLT_PlatformTime_50ms_doc

 * *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_PlatformTime_CODE) RE_PLT_PlatformTime_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
   * DO
    * NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
   *
    * Symbol: RE_PLT_PlatformTime_50ms

    * *********************************************************************************************************************/
#if (TRUE == ENABLE_SQT_TEST_STUBS)
   PlatformTime_Functionality_Test();
#endif

   /**********************************************************************************************************************
   * DO
    * NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!

    * *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 *
 * Runnable Entity Name: RE_PLT_PlatformTime_Init
 *

 * *---------------------------------------------------------------------------------------------------------------------
 *
 *
 * Executed once after the RTE is started
 *

 * **********************************************************************************************************************
 *
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType
 * Rte_Write_Pp_Fault_name_For_FHTI_Testing_De_Fault_name_FHTI(Dt_Fault_name_FHTI data)
 *

 * *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol:
 * RE_PLT_PlatformTime_Init_doc

 * *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_PlatformTime_CODE) RE_PLT_PlatformTime_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
   * DO
    * NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
   *
    * Symbol: RE_PLT_PlatformTime_Init

    * *********************************************************************************************************************/
   Get_PlatformTime_Init();
   /**********************************************************************************************************************
   * DO
    * NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!

    * *********************************************************************************************************************/
}

#define SWC_PLT_Appl_PlatformTime_STOP_SEC_CODE
#include "SWC_PLT_Appl_PlatformTime_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/

/* Tick-to-microsecond conversion for the nominal 250 MHz clock (4 ns/tick).
 * Centralised here so the formula is not duplicated across #if/#else paths. */
#define PLT_NOMINAL_TICKS_TO_US(ticks) (((ticks)*4ULL) / 1000ULL)

/*====================================================================================================================*/
/**
 * FUNCTION: PlatformTime_Init
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function is used for initialization of required variables.
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/

void Get_PlatformTime_Init(void)
{
#if (TRUE == XCP_FAULT_INJECTION)
   /* Re-apply a PlatformTime.usTime freeze fault that was requested via
    * CS_PlatformTime_Fault_Injection before a system reset occurred.
    * Retention_Ram_Data survives warm resets (only cleared on Power-On reset;
    * see Retention_Ram_Data_Init() in main.c), so this restores the freeze
    * state across the reset boundary. */
   if (Retention_Ram_Data.fhti_test_data.plt_usTime_freeze_pending == 1u)
   {
      s_plt_fi_ustime_frozen = TRUE;
   }
#endif
   Get_Platform_ustime(&Plt_Timer_Start_Ustime);
   Platform_Ms_FromUstime_Init();
}

/*====================================================================================================================*/

/*====================================================================================================================*/
/**
 * FUNCTION: Platform_Ustime_Errorcheck
 *======================================================================================================================
 * RETURN VALUE  void
 * PARAMETERS:
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function shall give platform microsecond time during RE_Evaluate_platform_init runnable call.
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/

void Platform_Ustime_Errorcheck(void)
{
   uint8_t tr_platformtime     = CODED_FALSE;
   uint64 plt_timer_end_ustime = 0;
   Get_Platform_ustime(&plt_timer_end_ustime);
   /* Check microsecond time at two different points are same */
   if (Plt_Timer_Start_Ustime == plt_timer_end_ustime)
   {
      tr_platformtime = CODED_TRUE;
   }
#if (TRUE == ENABLE_SIT_TEST_STUBS)
   PlatformTime_Integration_Test(&tr_platformtime);
#endif
   (void)Rte_Write_Pp_TR_platform_Time_De_PlatformTime(tr_platformtime);
}

/*====================================================================================================================*/
/**
 * FUNCTION: Get_Platform_ustime
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function shall give platform microsecond time when requested by other software component.
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/

void Get_Platform_ustime(uint64 *inst_us_time)
{
   /* A single exclusive area covers the entire function body.
    *  - In XCP builds it atomically reads both FI state flags alongside the
    *    hardware counter, preventing a data race with the concurrent writer
    *    in CS_PlatformTime_Fault_Injection.
    *  - Callers must not hold the PlatformTime exclusive area when calling
    *    this function; nested exclusive area entries are not supported. */
   uint64_t ticks64;
   uint8_t overflow8      = 0u;
   uint64_t us_from_ticks = 0ULL;
   uint64_t overflow_us   = 0ULL;
#if (TRUE == XCP_FAULT_INJECTION)
   uint8_t fi_frozen;
   uint8_t fi_res_ic;
#endif

   Rte_Enter_PlatformTime_ExclusiveArea();

#if (TRUE == XCP_FAULT_INJECTION)
   /* Read both FI flags atomically inside the exclusive area */
   fi_frozen = s_plt_fi_ustime_frozen;
   fi_res_ic = s_plt_fi_ustime_res_ic;

   if (fi_frozen == TRUE)
   {
      /* PlatformTime.usTime freeze is active: output is fixed at 0 µs and must
       * not increment. The hardware counter is bypassed so s_ustime_total_over
       * is not advanced. The unfreeze handler resets s_ustime_total_over to 0
       * ensuring no overflow counts are lost regardless of freeze duration. */
      *inst_us_time = 0ULL;
   }
   else
   {
#endif
      ticks64 = GET_TIMER_CNT_VALUE_TICKS(&overflow8); /* ticks within current wrap */
      s_ustime_total_over += (uint64_t)overflow8;      /* accumulate wraps           */

#if (TRUE == XCP_FAULT_INJECTION)
      /* Apply the injected usTime resolution scaling to the tick-to-µs conversion.
       * The scaling factor is set by the Failure Type 0x01 injection command. */
      switch (fi_res_ic)
      {
         case 0x01U: /* 0.5 µs resolution: effective rate is 2 ns/tick  */
            us_from_ticks = (ticks64 * 2ULL) / 1000ULL;
            break;
         case 0x02U: /* 2 µs resolution:   effective rate is 8 ns/tick  */
            us_from_ticks = (ticks64 * 8ULL) / 1000ULL;
            break;
         default: /* 1 µs resolution (nominal): 4 ns/tick            */
            us_from_ticks = PLT_NOMINAL_TICKS_TO_US(ticks64);
            break;
      }
#else
   us_from_ticks = PLT_NOMINAL_TICKS_TO_US(ticks64); /* 4 ns/tick -> µs */
#endif
      overflow_us   = s_ustime_total_over * (uint64_t)OVER_FLOW_TIME_VALUE;
      *inst_us_time = overflow_us + us_from_ticks;
#if (TRUE == XCP_FAULT_INJECTION)
   }
#endif

   Rte_Exit_PlatformTime_ExclusiveArea();
}

/*====================================================================================================================*/
/**
 * FUNCTION: Get_Platform_Elapsed_ustime
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS: uint64 *inst_us_time, uint64 start_time
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 *  This function returns the elapsed platform time in microseconds since the provided start_time.
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/

void Get_Platform_Elapsed_ustime(uint32_t *inst_us_time, uint64_t start_time)
{
   uint64 end_time;
   Get_Platform_ustime(&end_time);

   if (start_time > end_time)
   {
      /* Wrap-around: timer rolled over at OVER_FLOW_TIME_VALUE microseconds */
      *inst_us_time = (uint32_t)((OVER_FLOW_TIME_VALUE - start_time) + end_time);
   }
   else
   {
      *inst_us_time = (uint32_t)(end_time - start_time);
   }
}

/*====================================================================================================================*/
/**
 * FUNCTION: Get_Platform_mstime
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function shall give platform millisecond time when requested by other software component.
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/

void Get_Platform_mstime(uint32_t *inst_ms_time)
{
   /*
    * Millisecond time is derived from the microsecond source using an accumulator
    * that preserves sub-ms residuals between calls. This avoids reading any
    * separate ms hardware counter and keeps the result monotonic.
    */
   Platform_Get_Ms_Total_FromUstime(inst_ms_time);
}

/**
 * FUNCTION: Get_Platform_Elapsed_mstime
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS: uint32_t *inst_ms_time, uint64 start_time
 *
 * EXTERNAL REFERENCES:
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function returns the elapsed platform time in milliseconds since the provided start_time.
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 *====================================================================================================================*/
void Get_Platform_Elapsed_mstime(uint32_t *inst_ms_time, uint32_t start_time)
{
   uint32_t end_time;
   Get_Platform_mstime(&end_time);
   if (start_time > end_time)
   {
      *inst_ms_time = end_time + (PLATFORMTIME_MAX - start_time);
   }
   else
   {
      *inst_ms_time = (end_time - start_time);
   }
}

/*====================================================================================================================*/
/**
 * FUNCTION: Platform_Ms_FromUstime_Init
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function shall do the initialization for getting the millisecond value from microsecond value.
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/

void Platform_Ms_FromUstime_Init(void)
{
   /* Get_Platform_ustime is called OUTSIDE the exclusive area to prevent a nested
    * exclusive area entry: Get_Platform_ustime manages its own exclusive area
    * internally.  Only the writes to shared accumulator state need protection. */
   uint64 us_time;
   Get_Platform_ustime(&us_time);
   Rte_Enter_PlatformTime_ExclusiveArea();
   s_prev_us  = us_time;
   s_us_carry = 0u;
   s_ms_total = 0u;
   s_ms_delta = 0u;
   Rte_Exit_PlatformTime_ExclusiveArea();
}

/*====================================================================================================================*/
/**
 * FUNCTION: Platform_Ms_FromUstime_Update
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function shall calculate millisecond value based on microsecond value.
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/

/*--------------------------------------------------------------------------------------------------------------------
 * FUNCTION: Plt_Ms_Accumulate (file-private)
 *
 * Performs the core ms accumulation arithmetic using a pre-read usTime snapshot.
 * This function must be called with the PlatformTime exclusive area held.
 * It does NOT call Get_Platform_ustime, so it introduces no nested EA entry.
 *--------------------------------------------------------------------------------------------------------------------*/
static void Plt_Ms_Accumulate(uint64_t curr_us)
{
   uint64_t delta_us = 0ULL;
   uint64_t total_us;

   if (s_prev_us == 0ULL)
   {
      /* First accumulation after init: establish baseline without creating a delta. */
      s_prev_us  = curr_us;
      s_ms_delta = 0u;
   }

   if (curr_us >= s_prev_us)
   {
      delta_us = curr_us - s_prev_us;
   }
   else
   {
      /* Time moved backward; re-baseline. */
      s_prev_us  = curr_us;
      s_us_carry = 0u;
      s_ms_delta = 0u;
   }

   total_us   = delta_us + (uint64_t)s_us_carry;
   s_ms_delta = (uint32_t)(total_us / 1000ULL); /* full milliseconds        */
   s_us_carry = (uint32_t)(total_us % 1000ULL); /* sub-ms remainder (µs)    */
   s_ms_total += s_ms_delta;
   s_prev_us = curr_us;
}

void Platform_Ms_FromUstime_Update(void)
{
   /* Get_Platform_ustime is called OUTSIDE the exclusive area; it manages its own.
    * The accumulation logic runs atomically inside the exclusive area via
    * Plt_Ms_Accumulate, which never calls Get_Platform_ustime. */
   uint64_t curr_us = 0ULL;
   Get_Platform_ustime(&curr_us);
   Rte_Enter_PlatformTime_ExclusiveArea();
   Plt_Ms_Accumulate(curr_us);
   Rte_Exit_PlatformTime_ExclusiveArea();
}

/*====================================================================================================================*/
/**
 * FUNCTION: Platform_Get_Ms_Total_FromUstime
 *======================================================================================================================
 * RETURN VALUE
 *
 * PARAMETERS:
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function shall provides the total milliseconds value.
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/

void Platform_Get_Ms_Total_FromUstime(uint32_t *total_ms)
{
   /* Get_Platform_ustime is called OUTSIDE the exclusive area to prevent a nested
    * exclusive area entry; it manages its own area internally.
    * Plt_Ms_Accumulate and the s_ms_total read are performed atomically inside
    * a single exclusive area, ensuring a consistent snapshot is returned. */
   uint64_t curr_us = 0ULL;
   Get_Platform_ustime(&curr_us);
   Rte_Enter_PlatformTime_ExclusiveArea();
   Plt_Ms_Accumulate(curr_us);
   *total_ms = s_ms_total;
   Rte_Exit_PlatformTime_ExclusiveArea();
}

/*====================================================================================================================*/
/**
 * FUNCTION: Get_Timer_Cnt_Value_Ticks
 *======================================================================================================================
 * RETURN VALUE: uint64 timer count in Ticks
 *
 * PARAMETERS: overflow_count
 *
 * EXTERNAL REFERENCES:
 *
 *
 * DEVIATIONS FROM STANDARDS:
 * None.
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * ABSTRACT:
 * ---------------------------------------------------------------------------------------------------------------------
 * This function shall provides the timer count value in ticks.
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/

uint64_t Get_Timer_Cnt_Value_Ticks(uint8 *overflow_count)
{
   volatile TIMERS_SFRS_t *pGPT = (volatile TIMERS_SFRS_t *)TIMERS_base;
#ifndef UNITTEST
   /*Get ticks from Platform Timer*/
   current_ticks = (uint64_t)pGPT->TIMER4CURRENTVAL;
   if (current_ticks > previous_ticks)
   {
      *overflow_count = *overflow_count + 1;
   }
#endif
   previous_ticks = current_ticks;
   return (0xFFFFFFFF - current_ticks);
}

/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012
 * violations and justifications

 * *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence
 * from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.

 * Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule:
 * Rule2.7
     Reason:     The parameters are not used by the code in all possible code variants.
     Risk:       No functional
 * risk.
     Prevention: Not required.

*/
