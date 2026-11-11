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
 *             File:  SWC_Appl_Project.c
 *           Config:  Gen8_iND13400.dpa
 *        SW-C Type:  SWC_Appl_Project
 *
 *        Generator:  MICROSAR RTE Generator Version 4.37.00
 *                    RTE Core Version 4.37.00
 *          License:  CBD2400670
 *
 *      Description:  C-Code implementation template for SW-C <SWC_Appl_Project>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * StbM_TimeBaseStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Dio.h"
#include "Rte_SWC_Appl_Project.h"
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (TRUE == ENABLE_SIT_TEST_STUBS)
volatile uint8 Injection_control_signal_integrity = 0;
volatile uint8 Failure_Type_signal_integrity      = 0;
#endif
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Rte_DT_Dt_XCP_Set_Output_0: Integer in interval [0...255]
 * Rte_DT_Dt_XCP_Set_Output_1: Integer in interval [0...255]
 * StbM_TimeBaseStatusType: Integer in interval [0...63]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Record Types:
 * =============
 * Dt_XCP_Set_Output: Record with elements
 *   xcp_set_output_state of type Rte_DT_Dt_XCP_Set_Output_0
 *   xcp_set_output_select of type Rte_DT_Dt_XCP_Set_Output_1
 * StbM_TimeStampType: Record with elements
 *   timeBaseStatus of type StbM_TimeBaseStatusType
 *   nanoseconds of type uint32
 *   seconds of type uint32
 *   secondsHi of type uint16
 *
 *********************************************************************************************************************/

#define SWC_Appl_Project_START_SEC_CODE
#include "SWC_Appl_Project_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* the state for POS_GND_EN pin */
#define SELECT_POS_GND_EN (0x01u)
#define OUTPUT_STATE_HIGH (0x11u)
#define OUTPUT_STATE_LOW  (0x10u)

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_Signal_Integrity_Fault_Injection_Read
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Read> of PortPrototype <CS_Signal_Integrity_Fault_Injection>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CS_Signal_Integrity_Fault_Injection_Read(uint8 Injection_Control, uint8 Failure_Type)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CS_Signal_Integrity_Fault_Injection_Read_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_Appl_Project_CODE)
CS_Signal_Integrity_Fault_Injection_Read(uint8 Injection_Control,
                                         uint8 Failure_Type) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_Signal_Integrity_Fault_Injection_Read
    *********************************************************************************************************************/
#if (ENABLE_SIT_TEST_STUBS == TRUE)
   Injection_control_signal_integrity = Injection_Control;
   Failure_Type_signal_integrity      = Failure_Type;
#endif
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_Appl_Project_Main_50ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Rp_Time_Stamp_De_StbM_TimeStampType(StbM_TimeStampType *data)
 *   Std_ReturnType Rte_Read_Rp_XCP_Set_Output_State_De_XCP_Set_Output(Dt_XCP_Set_Output *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_Appl_Project_Main_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_Appl_Project_CODE) RE_Appl_Project_Main_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_Appl_Project_Main_50ms
    *********************************************************************************************************************/
   Dt_XCP_Set_Output XCP_Set_Output_State;
   Rte_Read_Rp_XCP_Set_Output_State_De_XCP_Set_Output(&XCP_Set_Output_State);
   if (SELECT_POS_GND_EN == XCP_Set_Output_State.xcp_set_output_select)
   {
      if (OUTPUT_STATE_HIGH == XCP_Set_Output_State.xcp_set_output_state)
      {
         Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_A2_A3_POS_GND_EN, STD_HIGH);
      }
      else if (OUTPUT_STATE_LOW == XCP_Set_Output_State.xcp_set_output_state)
      {
         Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_A2_A3_POS_GND_EN, STD_LOW);
      }
      else
      {
         /* No action */
      }
   }
   else
   {
      /* No selection matched except (POS_GND_EN pin) */
   }
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

#define SWC_Appl_Project_STOP_SEC_CODE
#include "SWC_Appl_Project_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

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
