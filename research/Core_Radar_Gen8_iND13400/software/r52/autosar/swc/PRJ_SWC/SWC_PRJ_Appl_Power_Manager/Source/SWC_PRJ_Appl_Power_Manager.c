/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  SWC_PRJ_Appl_Power_Manager.c
 *           Config:  Gen8_iND13400.dpa
 *        SW-C Type:  SWC_PRJ_Appl_Power_Manager
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PRJ_Appl_Power_Manager>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_SWC_PRJ_Appl_Power_Manager.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "SWC_PRJ_Appl_Power_Manager.h"
#include "dio_wrapper.h"
#include "reuse.h"

extern uint8 CustShutdownTaskCompleted;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 *********************************************************************************************************************/

#define SWC_PRJ_Appl_Power_Manager_START_SEC_CODE
#include "SWC_PRJ_Appl_Power_Manager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Power_Manager_5ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Power_Manager_5ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
FUNC(void, SWC_PRJ_Appl_Power_Manager_CODE) RE_Power_Manager_5ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_Power_Manager_5ms
    *********************************************************************************************************************/
   Dt_AdcData_T Read_IoHwAb_AdcData;
   Dt_SystemOperationMode OperationMode_System_Io;
   static Dt_OpModeShutdown OpModeShutdown_Prj = {CODED_FALSE, CODED_FALSE, CODED_FALSE};
   static uint8 shutdown_completed             = CODED_FALSE;
   if ((Get_Board_Revision() == BOARD_REV_A3P0) || (Get_Board_Revision() == BOARD_REV_B0CVAL) ||
       (Get_Board_Revision() == BOARD_REV_B0CVAL_ETH))
   {
      static uint8 low_volt_debounce_cnt           = 0U;
      OpModeShutdown_Prj.CustShutdownTaskCompleted = (uint8)CustShutdownTaskCompleted;
      Rte_Read_Rp_PhysicalAdcData_De_PhysicalAdcData(&Read_IoHwAb_AdcData);
      Rte_Read_Rp_OperationMode_System_De_OperationMode_System(&OperationMode_System_Io);
      if (Read_IoHwAb_AdcData.Adc_Pos_Gnd_C <= Low_IGN_THRESHOLD_VOLTAGE)
      {
         if (low_volt_debounce_cnt < LOW_IGN_DEBOUNCE_CNT)
         {
            low_volt_debounce_cnt++;
         }

         if (low_volt_debounce_cnt >= LOW_IGN_DEBOUNCE_CNT)
         {
            /* Ignition voltage below 5.5V for >= 100ms: inform ModeManager to initiate shutdown */
            OpModeShutdown_Prj.ShutdownRequested       = (uint8)CODED_TRUE;
            OpModeShutdown_Prj.ReturnToNormalRequested = (uint8)CODED_FALSE;
            Rte_Write_Request_ESH_PostRunRequest_0_requestedMode(RELEASED);
         }
      }
      else
      {
         low_volt_debounce_cnt = 0;
         if ((OpModeShutdown_Prj.ShutdownRequested == (uint8)CODED_TRUE) && (OperationMode_System_Io != SHUTDOWN_COMPLETED))
         {
            OpModeShutdown_Prj.ReturnToNormalRequested = (uint8)CODED_TRUE;
         }
      }
      Rte_Write_Pp_OpModeShutdown_De_OpModeShutdown(&OpModeShutdown_Prj);

      if (OperationMode_System_Io == SHUTDOWN_COMPLETED)
      {
         (void)Dio_Wrapper_WriteChannel(DioConf_DioChannel_A3_TOD, STD_LOW);
         shutdown_completed = CODED_TRUE;
      }
      else
      {
         shutdown_completed = CODED_FALSE;
      }
      /* When IGN recovers after shutdown completion, reset SW to become operational again. */
      if ((shutdown_completed == CODED_TRUE) && (Read_IoHwAb_AdcData.Adc_Pos_Gnd_C >= RECOVERED_IGN_THRESHOLD_VOLTAGE))
      {
         Mcu_Reset(RESET_SW_INTENTIONAL);
      }
   }

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Power_Manager_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Power_Manager_Init_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PRJ_Appl_Power_Manager_CODE) RE_Power_Manager_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_Power_Manager_Init
    *********************************************************************************************************************/
   Rte_Write_Request_ESH_PostRunRequest_0_requestedMode(REQUESTED);

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

#define SWC_PRJ_Appl_Power_Manager_STOP_SEC_CODE
#include "SWC_PRJ_Appl_Power_Manager_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameters are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
