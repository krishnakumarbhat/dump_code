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
 *             File:  SWC_PLT_Appl_RTM.c
 *           Config:  Gen8_iND13400.dpa
 *        SW-C Type:  SWC_PLT_Appl_RTM
 *
 *        Generator:  MICROSAR RTE Generator Version 4.37.00
 *                    RTE Core Version 4.37.00
 *          License:  CBD2400670
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PLT_Appl_RTM>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_SWC_PLT_Appl_RTM.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Gpt.h"
#include "Rtm.h"
#include "Rtm_Cbk.h"
#include "Rtm_Cfg.h"
#include "dd_gpt.h"
#include <string.h>

#define RTMTASKTOMEASURE 8

typedef struct
{
   float32 min_usec;
   float32 max_usec;
   float32 min_msec;
   float32 max_msec;
} Rtm_Result_T;

static Dt_CPU_Load CPU_Load_C0;
void Rtm_Enable_Mp(void);

const uint8 rtmtask_names[RTMTASKTOMEASURE] = {RtmConf_RtmMeasurementPoint_Appl_Task_Communication,
                                               RtmConf_RtmMeasurementPoint_Appl_Task_High_Prio,
                                               RtmConf_RtmMeasurementPoint_Appl_Task_Logging,
                                               RtmConf_RtmMeasurementPoint_Radar_Ctrl_Task,
                                               RtmConf_RtmMeasurementPoint_BSW_Task,
                                               RtmConf_RtmMeasurementPoint_Appl_Task_Fast,
                                               RtmConf_RtmMeasurementPoint_Appl_Task,
                                               RtmConf_RtmMeasurementPoint_Appl_IPC_Task};
Dt_RTM_parameters_T taskmeasuresument_points[RTMTASKTOMEASURE];

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
 * uint32: Integer in interval [0...4294967295] (standard type)
 *
 * Record Types:
 * =============
 * Dt_CPU_Load: Record with elements
 *   CPU_Load of type uint32
 *   CPU_Load_Max of type uint32
 *   CPU_Load_Min of type uint32
 *   CPU_Load_Avg of type uint32
 * Dt_RTM_parameters_T: Record with elements
 *   Runtime_average of type uint32
 *   Runtime_overall of type uint32
 *   Runtime_MAX of type uint32
 *   Runtime_MIN of type uint32
 *
 *********************************************************************************************************************/

#define SWC_PLT_Appl_RTM_START_SEC_CODE
#include "SWC_PLT_Appl_RTM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_Rtm_task_measurement
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <CS_Rtm_task_measurement>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CS_Rtm_task_measurement(Dt_RTM_parameters_T *destination)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CS_Rtm_task_measurement_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_RTM_CODE)
CS_Rtm_task_measurement(P2VAR(Dt_RTM_parameters_T, AUTOMATIC, RTE_SWC_PLT_APPL_RTM_APPL_VAR)
                           destination) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_Rtm_task_measurement
    *********************************************************************************************************************/
   memcpy(destination, taskmeasuresument_points, sizeof(taskmeasuresument_points));

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_RTM_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_CPU_Load_De_CPU_Load(const Dt_CPU_Load *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_RTM_Init_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_RTM_CODE) RE_RTM_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_RTM_Init
    *********************************************************************************************************************/

   Rtm_InitMemory();

   /* TODO: Short term disable RTM due to Sporadic Rtm_Schuedule stuck loop */
   /* RTM vector Manual:  Disable the RTM at runtime by setting the variable Rtm_ControlState to
      RTM_CONTROL_STATE_DISABLED (= 0). This lock must be done after the call to
      Rtm_InitMemory but before the call to Rtm_Init. */

   Rtm_Init();

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_RTM_Main_50ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_RTM_Main_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_RTM_CODE) RE_RTM_Main_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_RTM_Main_50ms
    *********************************************************************************************************************/

   uint8 rtm_index               = 0;
   static boolean rtm_mp_enabled = FALSE;

   if (rtm_mp_enabled)
   {
      Rtm_GetMeasurementItem(RtmConf_RtmMeasurementPoint_Rtm_CpuLoadMeasurement, RTM_ITEM_CPU_LOAD_CURRENT,
                             &(CPU_Load_C0.CPU_Load));
      Rtm_GetMeasurementItem(RtmConf_RtmMeasurementPoint_Rtm_CpuLoadMeasurement, RTM_ITEM_CPU_LOAD_AVERAGE,
                             &(CPU_Load_C0.CPU_Load_Avg));
      Rtm_GetMeasurementItem(RtmConf_RtmMeasurementPoint_Rtm_CpuLoadMeasurement, RTM_ITEM_MIN, &(CPU_Load_C0.CPU_Load_Min));
      Rtm_GetMeasurementItem(RtmConf_RtmMeasurementPoint_Rtm_CpuLoadMeasurement, RTM_ITEM_MAX, &(CPU_Load_C0.CPU_Load_Max));

      (void)Rte_Write_Pp_CPU_Load_De_CPU_Load(&CPU_Load_C0);

      for (rtm_index = 0; rtm_index < RTMTASKTOMEASURE; rtm_index++)
      {
         Rtm_GetMeasurementItem(rtmtask_names[rtm_index], RTM_ITEM_RUNTIME_AVERAGE,
                                &(taskmeasuresument_points[rtm_index].Runtime_average));
         Rtm_GetMeasurementItem(rtmtask_names[rtm_index], RTM_ITEM_RUNTIME_OVERALL,
                                &(taskmeasuresument_points[rtm_index].Runtime_overall));
         Rtm_GetMeasurementItem(rtmtask_names[rtm_index], RTM_ITEM_MIN, &(taskmeasuresument_points[rtm_index].Runtime_MIN));
         Rtm_GetMeasurementItem(rtmtask_names[rtm_index], RTM_ITEM_MAX, &(taskmeasuresument_points[rtm_index].Runtime_MAX));
      }
   }
   else
   {
      Rtm_Enable_Mp();
      rtm_mp_enabled = TRUE;
   }

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

#define SWC_PLT_Appl_RTM_STOP_SEC_CODE
#include "SWC_PLT_Appl_RTM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

uint32_t Get_CPU_Load_C0(void)
{
   return CPU_Load_C0.CPU_Load;
}
void Rtm_Enable_Mp(void)
{
   (void)memset(&Rtm_Ctrl[0], 0xFF, RTM_CTRL_VECTOR_LEN);
}

Rtm_TimestampType Rtm_GetTimeMeasurement(void)
{
   Rtm_TimestampType Timer_Value = 0;

   Timer_Value = (Rtm_TimestampType)(RTM_MEASUREMENT_MAX_VAL - (Rtm_TimestampType)Gpt_GetTimeElapsed(GPT_PHY_TMR_4));

   return Timer_Value;
}
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
