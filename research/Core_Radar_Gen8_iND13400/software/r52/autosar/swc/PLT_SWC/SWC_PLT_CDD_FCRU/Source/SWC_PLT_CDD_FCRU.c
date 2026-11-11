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
 * SWC_PLT_CDD_FCRU.c
 *           Config:  Gen8_iND13400.dpa
 *        SW-C Type:  SWC_PLT_CDD_FCRU
 *
 *        Generator:
 * MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *
 * Description:  C-Code implementation template for SW-C <SWC_PLT_CDD_FCRU>

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

#include "Rte_SWC_PLT_CDD_FCRU.h"

/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/

#include "SWC_PLT_CDD_FCRU_Cfg.h"
#include "SWC_PLT_CDD_FailSafe.h"
#include "board_revision.h"
#include "boot_interface.h"

/* definition for FCRU configuration variables */
uint32 Rst_Ena_Config0 = RST_ENA_CONFIG0;
uint32 Rst_Ena_Config1 = RST_ENA_CONFIG1;
uint32 Pin_Ena_Config0 = PIN_ENA_CONFIG0;
uint32 Pin_Ena_Config1 = PIN_ENA_CONFIG1;

static void Init_FCRU_Config_By_Board_Revision(void)
{
#if 0 /*Todo some boards without Ethernet showed below failures. Reverting these since these are nomore observed*/
   if (BOARD_REV_B0CVAL != Get_Board_Revision())
   {
      Rst_Ena_Config1 |= (ENABLE_FCRU_FAULT_55 | ENABLE_FCRU_FAULT_57 | ENABLE_FCRU_FAULT_58);
      Pin_Ena_Config1 |= (ENABLE_FCRU_FAULT_55 | ENABLE_FCRU_FAULT_57 | ENABLE_FCRU_FAULT_58);
   }
#endif
}

uint8 Get_LBIST_Availability_In_HW(void);

/* Function declaration for FCRU fault Disable function */
void FCRU_Disable_Faulty_channel(uint8 fault_num);

#if (ENABLE_SIT_TEST_STUBS == TRUE)
volatile uint8 Test_Injection_Control_FCRU = 0;
volatile uint8 Test_Failure_Type_FCRU      = 0;
#endif
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
 * uint8: Integer in interval [0...255] (standard type)
 *

 * *********************************************************************************************************************/

#define SWC_PLT_CDD_FCRU_START_SEC_CODE
#include "SWC_PLT_CDD_FCRU_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 *
 * Runnable Entity Name: CS_FCRU_Fault_Injection
 *

 * *---------------------------------------------------------------------------------------------------------------------
 *
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for
 * OperationPrototype <Read> of PortPrototype <CS_FCRU_Fault_Injection>
 *

 * **********************************************************************************************************************
 *
 *
 * Runnable prototype:
 * ===================
 *   void CS_FCRU_Fault_Injection(uint8 Injection_control, uint8 Failure_Type)
 *

 * *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol:
 * CS_FCRU_Fault_Injection_doc

 * *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_FCRU_CODE)
CS_FCRU_Fault_Injection(uint8 Injection_control, uint8 Failure_Type) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
   * DO
    * NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
   *
    * Symbol: CS_FCRU_Fault_Injection

    * *********************************************************************************************************************/
#if (ENABLE_SIT_TEST_STUBS == TRUE)
   Test_Injection_Control_FCRU = Injection_control;
   Test_Failure_Type_FCRU      = Failure_Type;
#endif

#if (TRUE == XCP_FAULT_INJECTION)
   if (IC_INJECT_FAULT == Injection_control)
   {
      if ((Failure_Type <= MAX_FCRU_FAULT_NUM))
      {
         Inject_FCRU_Fault(Failure_Type);
      }
      else
      {
         /* Invalid Fault Number, Do nothing */
      }
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
 * Runnable Entity Name: RE_PLT_FCRU_Init
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
 * Rte_Write_Pp_PMU_FaultB_PinIntegrity_De_PMU_FaultB_PinIntegrityStat(uint8 data)
 *
 * Client/Server Interfaces:
 *
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType
 * Rte_Call_CS_Get_RepetativeReset_Faultnum_Operation(uint8 *faultnum)
 *     Synchronous Server Invocation. Timeout: None
 *

 * *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol:
 * RE_PLT_FCRU_Init_doc

 * *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_FCRU_CODE) RE_PLT_FCRU_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
   * DO
    * NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
   *
    * Symbol: RE_PLT_FCRU_Init

    * *********************************************************************************************************************/

   uint8 Repetative_reset_faultnum;
   uint8 Lbist_availability_status = CODED_FALSE;

   Lbist_availability_status = Get_LBIST_Availability_In_HW();

   /* Configure Active and Inactive state for PMU_FaultB Pin */
   CONFIG_PMU_FAULTB_PIN(PMU_FAULTB_CONFIG);

   /* Log the last FCRU reset reason */
   Log_Last_FCRU_Reset_Reason();

   /* Get the Repetative Reset Fault Number from Failsafe SWC */
   Rte_Call_CS_Get_RepetativeReset_Faultnum_Operation(&Repetative_reset_faultnum);

   if (Repetative_reset_faultnum != NO_FCRU_REPETATIVE_RESET)
   {
      /* Disable the faulty channel in FCRU */
      FCRU_Disable_Faulty_channel(Repetative_reset_faultnum);
   }
   Init_FCRU_Config_By_Board_Revision();
   /* Update self reset reg */
   CONFIG_FCRU_RST_EN_00(Rst_Ena_Config0);
   CONFIG_FCRU_RST_EN_01(Rst_Ena_Config1);

   /* Check the board version and Configure PMU_FaultB reaction only for B-Sample and EDU boards
      UT Comment : Both condition can not be true and branch Can not be covered */
   // Once Board Version is conformed where PMU_FaultB and MCU_ERR is removed, varient condition will be added again
   if (CODED_TRUE == Lbist_availability_status)
   {
      /* Update PMU_FaultB reg */
      CONFIG_FCRU_PIN_EN_00(Pin_Ena_Config0);
      CONFIG_FCRU_PIN_EN_01(Pin_Ena_Config1);
   }
   else
   {
      /* Avoid Chandra PMU_FAULTB as this will assert PMIC MCU_ERR pin */
      CONFIG_FCRU_PIN_EN_00(0);
      CONFIG_FCRU_PIN_EN_01(0);
   }

   /* Update Capture Bypass reg */
   CONFIG_FCRU_CAP_BYP_00(CAP_BYP_CONFIG0);
   CONFIG_FCRU_CAP_BYP_01(CAP_BYP_CONFIG1);

   /**********************************************************************************************************************
   * DO
    * NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!

    * *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 *
 * Runnable Entity Name: RE_PLT_FCRU_Main_50ms
 *

 * *---------------------------------------------------------------------------------------------------------------------
 *
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *

 * **********************************************************************************************************************
 *
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType
 * Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason(uint8 reset_reason)
 *     Synchronous Server Invocation.
 * Timeout: None
 *

 * *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol:
 * RE_PLT_FCRU_Main_50ms_doc

 * *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_FCRU_CODE) RE_PLT_FCRU_Main_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
   * DO
    * NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
   *
    * Symbol: RE_PLT_FCRU_Main_50ms

    * *********************************************************************************************************************/
#if (STD_ON == ENABLE_SQT_TEST_STUBS)
   FCRU_Functionality_Test();
#endif

#if (STD_ON == ENABLE_SIT_TEST_STUBS)
   FCRU_Integration_Test();
#endif
   /**********************************************************************************************************************
   * DO
    * NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!

    * *********************************************************************************************************************/
}

#define SWC_PLT_CDD_FCRU_STOP_SEC_CODE
#include "SWC_PLT_CDD_FCRU_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/
#if 0
/******************************************************************************
 * Name:  Clear_FCRU_Fault_Status
 *    This function clears the fault status of the specified fault from FCRU_DIAG registers
 *
 * Shared Variables: none
 *
 * Parameters: failure_type, fault_num
 *
 * Return Value: void
 *
 * Design Information:
 *
 *
 * Change References:
 *
 *
 ******************************************************************************/
static void Clear_FCRU_Fault_Status(uint8 failure_type, uint8 fault_num)
{
   switch (failure_type)
   {
      case PIN_EN_STATUS:
         CLEAR_PIN_EN_FAULT_STATE(fault_num);
         break;

      case RST_EN_STATUS:
         CLEAR_RST_EN_FAULT_STATE(fault_num);
         break;

      case PIN_RST_EN_STATUS:
         CLEAR_PIN_EN_FAULT_STATE(fault_num);
         CLEAR_RST_EN_FAULT_STATE(fault_num);
         break;

      default:
         break;
   }
}
#endif
/******************************************************************************
 * Name:  Inject_FCRU_Fault
 *    This function is used to inject the FCRU fault by writing FCRU_KEY register and FCRU_FORCE_FAULT register
 *
 * Shared Variables: none
 *
 * Parameters: fault_num
 *
 * Return Value: void
 *
 * Design Information:
 *
 *
 *  Change References:
 *
 *
 ******************************************************************************/
void Inject_FCRU_Fault(uint8 fault_num)
{
   FCRU_KEY_ADDR = FCRU_KEY_SET; /* Write Key Value to Key Register */
   INJECT_FCRU_FAULT(fault_num);
   FCRU_KEY_ADDR = FCRU_KEY_CLEAR; /* Clear Key Register by writing invalid key value */
}

/******************************************************************************
 * Name:  Get_FCRU_Fault_Info
 *    This function update the FCRU fault information from FCRU_DIAG registers to the diag_reg_info structure
 *
 * Shared Variables: none
 *
 * Parameters: diag_reg_info
 *
 * Return Value: void
 *
 * Design Information:
 *
 *
 * Change References:
 *
 *
 ******************************************************************************/
static void Get_FCRU_Fault_Info(FCRU_Diag_Info_t *diag_reg_info)
{
   /* Get Fault Information from FCRU_DIAG Registers */
   diag_reg_info->Diag_Pin_En_00 = FCRU_DIAG_00_ADDR;
   diag_reg_info->Diag_Pin_En_01 = FCRU_DIAG_01_ADDR;

   if ((((Boot_Shared_Data.pbl_version_major == FCRU_PBL_MAJOR_VERSION) &&
         Boot_Shared_Data.pbl_version_minor == FCRU_PBL_MINOR_VERSION) &&
        (Boot_Shared_Data.pbl_version_patch >= FCRU_PBL_PATCH_VERSION)) ||
       (((Boot_Shared_Data.pbl_version_major == FCRU_PBL_MAJOR_VERSION) &&
         Boot_Shared_Data.pbl_version_minor > FCRU_PBL_MINOR_VERSION)) ||
       (Boot_Shared_Data.pbl_version_major > FCRU_PBL_MAJOR_VERSION))
   {
      diag_reg_info->Diag_Rst_En_00 = Boot_Shared_Data.fcru_diag2;
      diag_reg_info->Diag_Rst_En_01 = Boot_Shared_Data.fcru_diag3;
   }
   else
   {
      diag_reg_info->Diag_Rst_En_00 = FCRU_DIAG_02_ADDR;
      diag_reg_info->Diag_Rst_En_01 = FCRU_DIAG_03_ADDR;
   }
}
/******************************************************************************
 * Name:  Log_Last_FCRU_Reset_Reason
 *    This function logs the last FCRU reset reason based on the FCRU diag registers
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: void
 *
 * Design Information:
 *
 *
 * Change References:
 *
 *
 ******************************************************************************/

static void Log_Last_FCRU_Reset_Reason(void)
{
   uint8 reset_reason              = 0xFF;
   FCRU_Diag_Info_t FCRU_Diag_Info = {0};

   Get_FCRU_Fault_Info(&FCRU_Diag_Info);

   if (FCRU_Diag_Info.Diag_Rst_En_00 != 0)
   {
      /* Get Fault Number from Diag Register */
      reset_reason = Get_Fault_Number(FCRU_Diag_Info.Diag_Rst_En_00);
      reset_reason = FCRU_RESET_REASON_OFFSET1 + reset_reason; /* Offset for Faults 0 to 31 */
      Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason(reset_reason);
   }
   else if (FCRU_Diag_Info.Diag_Rst_En_01 != 0)
   {
      /* Get Fault Number from Diag Register */
      reset_reason = Get_Fault_Number(FCRU_Diag_Info.Diag_Rst_En_01);
      reset_reason = FCRU_RESET_REASON_OFFSET2 + reset_reason; /* Offset for Faults 32 to 63 */
      Rte_Call_CS_Failsafe_Log_ResetReason_at_Startup_fcru_reset_reason(reset_reason);
   }
   else
   {
      /* No reset reason logged */
   }
}

/******************************************************************************
 * Name:  Get_Fault_Number
 *    This function returns the fault number from the diag register
 *
 * Shared Variables: none
 *
 * Parameters: diag_reg
 *
 * Return Value: fault_num
 *
 * Design Information:
 *
 *
 * Change References:
 *
 *
 ******************************************************************************/
static uint8 Get_Fault_Number(uint32 diag_reg)
{
   uint8 fault_num = 0;
   uint8 i;

   for (i = 0; i < 32; i++)
   {
      if ((diag_reg >> i) & 0x01)
      {
         fault_num = i;
         break;
      }
   }
   return fault_num;
}

/******************************************************************************
 * Name:  FCRU_Clear_All_Fault_Status
 *    This function clears all the fault status from FCRU diag registers by writing 1 to all bits of Fault Clear registers
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: void
 *
 * Design Information:
 *
 *
 * Change References:
 *
 *
 ******************************************************************************/
void FCRU_Clear_All_Fault_Status(void)
{
   /* Clear all DIAG Registers */
   FCRU_CTRL_04_ADDR = SET_ALL_BITS;
   FCRU_CTRL_05_ADDR = SET_ALL_BITS;
   FCRU_CTRL_06_ADDR = SET_ALL_BITS;
   FCRU_CTRL_07_ADDR = SET_ALL_BITS;
}

/******************************************************************************
 * Name:  Get_LBIST_Availability_In_HW
 *    This function checks the availability of LBIST in the hardware
 *
 * Shared Variables: none
 *
 * Parameters: none
 *
 * Return Value: uint8
 *
 * Design Information:
 *
 *
 * Change References:
 *
 *
 ******************************************************************************/
uint8 Get_LBIST_Availability_In_HW(void)
{
   uint32 regVal;
   uint8 status = CODED_FALSE; /* default to not available */

   regVal = *((volatile uint32 *)LBIST_SEQ_STAT0_ADDR);

   /* Check if LBIST test ran and failed */
   if ((regVal & LBIST_AVAILABLE) == LBIST_AVAILABLE)
   {
      status = (uint8)CODED_TRUE; /* LBIST available */
   }
   else
   {
      status = (uint8)CODED_FALSE; /* LBIST not available */
   }
   return status;
}

/******************************************************************************
 * Name:  FCRU_Disable_Faulty_channel
 *    This function disables the faulty channel in the FCRU
 *
 * Shared Variables: none
 *
 * Parameters: fault_num
 *
 * Return Value: void
 *
 * Design Information:
 *
 *
 * Change References:
 *
 *
 ******************************************************************************/
void FCRU_Disable_Faulty_channel(uint8 fault_num)
{
   uint8 FCRU_Resetnum;

   /* extract the FCRU faulty channel number from reset reason number */
   FCRU_Resetnum = fault_num - FCRU_RESET_REASON_OFFSET1;

   if (FCRU_Resetnum > 31U)
   {
      /* if FCRU fault number is > 31 then disable the fault reaction by clearing the fault bit in FCRU_CTRL01 and FCRU_CTRL03
       * registers */
      Rst_Ena_Config1 &= ~((uint32)1U << (FCRU_Resetnum - 32U));
      Pin_Ena_Config1 &= ~((uint32)1U << (FCRU_Resetnum - 32U));
   }
   else
   {
      /* if FCRU fault number is <= 31 then disable the fault reaction by clearing the fault bit in FCRU_CTRL00 and FCRU_CTRL02
       * registers */
      Rst_Ena_Config0 &= ~((uint32)1U << FCRU_Resetnum);
      Pin_Ena_Config0 &= ~((uint32)1U << FCRU_Resetnum);
   }
}
/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT
 * CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!

 * *********************************************************************************************************************/

#if 0
/***  Start of saved code (symbol: documentation area:CS_FCRU_Fault_Injection_Read_doc)  ********************/
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:CS_FCRU_Fault_Injection_Read)  *******************/
/***  End of saved code  ************************************************************************************/
#endif

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
