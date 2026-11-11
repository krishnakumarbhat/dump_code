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
 *             File:  SWC_PRJ_Appl_SensorPosition.c
 *           Config:  Gen8_iND13400.dpa
 *        SW-C Type:  SWC_PRJ_Appl_SensorPosition
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PRJ_Appl_SensorPosition>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_SWC_PRJ_Appl_SensorPosition.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Fault_Lib_Prj.h"
#include "sensor_position.h"

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
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Record Types:
 * =============
 * Dt_SensorPosition_Status_T: Record with elements
 *   SensorPos_Value of type uint8
 *   SensorPos_Lock_Status of type uint8
 *
 *********************************************************************************************************************/

#define SWC_PRJ_Appl_SensorPosition_START_SEC_CODE
#include "SWC_PRJ_Appl_SensorPosition_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define SENSOR_POS_UNLOCKED       (1U)
#define SENSOR_POS_LOCK_STATE_MAX (1U)
#define SENSOR_POS_DEFAULT_VALUE  (255U)
#define SENSOR_POS_DEFAULT_RL     (1U)

extern uint8_t Get_Customer_Radar_Position(void);

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_Get_Pinposition_Status_Operation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <CS_Get_Pinposition_Status>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CS_Get_Pinposition_Status_Operation(uint8 *Sensor_Position)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CS_Get_Pinposition_Status_Operation_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PRJ_Appl_SensorPosition_CODE)
CS_Get_Pinposition_Status_Operation(P2VAR(uint8, AUTOMATIC, RTE_SWC_PRJ_APPL_SENSORPOSITION_APPL_VAR)
                                       Sensor_Position) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_Get_Pinposition_Status_Operation
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_SensorPosition_50ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_PinPosition_Mismatch_Fault_Status_De_PinPosition_Mismatch_Fault_Status(uint8 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CS_Sensorpos_ReadNvM_Value_Operation(Dt_SensorPosition_Status_T *Sensorpos_Read_Record)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_SensorPosition_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PRJ_Appl_SensorPosition_CODE) RE_SensorPosition_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_SensorPosition_50ms
    *********************************************************************************************************************/
   uint8 PinPosition_Mismatch_Status = DIAG_TEST_PASS;
   Dt_SensorPosition_Status_T Sensor_Position_NVM;
   uint8 Radar_Position;

   (void)Rte_Call_CS_Sensorpos_ReadNvM_Value_Operation(&Sensor_Position_NVM);

   Radar_Position = (uint8)Get_Customer_Radar_Position();

   if ((SENSOR_POS_DEFAULT_VALUE == Sensor_Position_NVM.SensorPos_Value) &&
       (SENSOR_POS_DEFAULT_VALUE == Sensor_Position_NVM.SensorPos_Lock_Status))
   {
      Sensor_Position_NVM.SensorPos_Value       = SENSOR_POS_DEFAULT_RL;
      Sensor_Position_NVM.SensorPos_Lock_Status = SENSOR_POS_UNLOCKED;
   }

   if ((SENSOR_POS_LOCK_STATE_MAX < Sensor_Position_NVM.SensorPos_Lock_Status) ||
       (SENSOR_POSITION_INVALID == Sensor_Position_NVM.SensorPos_Value) ||
       (SENSOR_POSITION_MAX_PINS < Sensor_Position_NVM.SensorPos_Value))
   {
      PinPosition_Mismatch_Status = DIAG_TEST_FAIL;
   }

   if ((Radar_Position != Sensor_Position_NVM.SensorPos_Value) &&
       (SENSOR_POS_UNLOCKED != Sensor_Position_NVM.SensorPos_Lock_Status))
   {
      PinPosition_Mismatch_Status = DIAG_TEST_FAIL;
   }

   (void)Rte_Write_Pp_PinPosition_Mismatch_Fault_Status_De_PinPosition_Mismatch_Fault_Status(PinPosition_Mismatch_Status);

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

#define SWC_PRJ_Appl_SensorPosition_STOP_SEC_CODE
#include "SWC_PRJ_Appl_SensorPosition_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

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
