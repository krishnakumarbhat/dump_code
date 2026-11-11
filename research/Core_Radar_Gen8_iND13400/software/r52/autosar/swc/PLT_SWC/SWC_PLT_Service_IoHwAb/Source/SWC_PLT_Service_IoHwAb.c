/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  SWC_PLT_Service_IoHwAb.c
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.37.00
 *                    RTE Core Version 4.37.00
 *          License:  CBD2400670
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PLT_Service_IoHwAb>
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/* PRQA S 0857 EOF */       /* MD_MSR_Dir1.1 */
/* PRQA S 0614 EOF */       /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2982 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2983 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2880 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */

#include "Rte_SWC_PLT_Service_IoHwAb.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Dio.h"
#include "Dio_Cfg.h"
#include "Port_Cfg.h"
#include "SWC_PLT_Service_IoHwAb.h"
#include "dio_wrapper.h"
#include "string.h"
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define SWC_PLT_Service_IoHwAb_START_SEC_CODE
#include "SWC_PLT_Service_IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_RawAdcCount_Read
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Read> of PortPrototype <CS_RawAdcCount>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CS_RawAdcCount_Read(Dt_RawAdcData_T *RawAdcData)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Pi_RawAdcCount_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PLT_Service_IoHwAb_CODE)
CS_RawAdcCount_Read(P2VAR(Dt_RawAdcData_T, AUTOMATIC, RTE_SWC_PLT_SERVICE_IOHWAB_APPL_VAR)
                       RawAdcData) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_RawAdcCount_Read (returns application error)
    *********************************************************************************************************************/
   IoHwAb_RawAdcCount_Read(RawAdcData);
   return RTE_E_OK;

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_Update_Thermal_Mon_Temps_Read
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Read> of PortPrototype <CS_Update_Thermal_Mon_Temps>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CS_Update_Thermal_Mon_Temps_Read(DT_Thermal_mon_mes_results_T *therm_temp_results)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Pi_Update_Thermal_Mon_Temps_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PLT_Service_IoHwAb_CODE)
CS_Update_Thermal_Mon_Temps_Read(P2VAR(DT_Thermal_mon_mes_results_T, AUTOMATIC, RTE_SWC_PLT_SERVICE_IOHWAB_APPL_VAR)
                                    therm_temp_results) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_Update_Thermal_Mon_Temps_Read (returns application error)
    *********************************************************************************************************************/
   Update_Thermal_Monitor_Values(therm_temp_results);
   return RTE_E_OK;

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Get_FloatingPinPosition_FaultStatus
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <FaultStatus> of PortPrototype <Pi_Get_FloatingPinPosition>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Get_FloatingPinPosition_FaultStatus(uint8 *Status)
 *
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Service_IoHwAb_CODE)
Get_FloatingPinPosition_FaultStatus(P2VAR(uint8, AUTOMATIC, RTE_SWC_PLT_SERVICE_IOHWAB_APPL_VAR)
                                       Status) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Get_STM_TimeStamp
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get_STM_TimeStamp> of PortPrototype <Pp_Get_STM_TimeStamp>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Get_STM_TimeStamp(uint32 *arg)
 *
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Service_IoHwAb_CODE)
Get_STM_TimeStamp(P2VAR(uint32, AUTOMATIC, RTE_SWC_PLT_SERVICE_IOHWAB_APPL_VAR)
                     arg) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Pp_PWMDutyCycle
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <PWMDutyCycle> of PortPrototype <Pp_PWMDutyCycle>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Pp_PWMDutyCycle(uint8 DutyCycle)
 *
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Service_IoHwAb_CODE) Pp_PWMDutyCycle(uint8 DutyCycle) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Service_IoHwAb_ADCFilter_5ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Rp_ADC_XCP_Req_De_ADC_XCP_Req(uint8 *data)
 *
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Service_IoHwAb_CODE)
RE_PLT_Service_IoHwAb_ADCFilter_5ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Service_IoHwAb_ADCFilter_5ms
    *********************************************************************************************************************/
   IoHwAb_Adc_Main_5ms();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Service_IoHwAb_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Service_IoHwAb_CODE) RE_PLT_Service_IoHwAb_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_Service_IoHwAb_Main_5ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 5ms
 *
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Service_IoHwAb_CODE) RE_PLT_Service_IoHwAb_Main_5ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_Service_IoHwAb_Main_5ms
    *********************************************************************************************************************/
   IoHwAb_Adc_Main_5ms();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Set_DIO_LED_SRC_PULL
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Write> of PortPrototype <Pp_Set_DIO_LED_SRC_PULL>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Set_DIO_LED_SRC_PULL(uint8 Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Pi_Set_DIO_LED_SRC_PULL_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PLT_Service_IoHwAb_CODE)
Set_DIO_LED_SRC_PULL(uint8 Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: Set_DIO_LED_SRC_PULL (returns application error)
    *********************************************************************************************************************/

   return RTE_E_OK;

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

#define SWC_PLT_Service_IoHwAb_STOP_SEC_CODE
#include "SWC_PLT_Service_IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*====================================================================================================================*\
* FUNCTION: IoHwAb_ADC_PosPin_Prj_cbk
*=======================================================================================================================
* RETURN VALUE: void
*
* PARAMETERS: IoHwAb_Adc_PosPin_Hw_Ckt_T
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
* To control the Enable/Disable of Position pins Hardware Circuit control
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
void IoHwAb_ADC_PosPin_Prj_cbk(IoHwAb_Adc_PosPin_Hw_Ckt_T PosPinHwCkt_Control)
{
   switch (PosPinHwCkt_Control)
   {
      case Init_EnablePosGndCkt:
         /*Temporarily added here needs to be called from Sensor Pos Module*/
         /* Set POS_GND_EN to high to enable POGND_ADC, POS_GND_ADC_B */
         (void)Dio_Wrapper_WriteChannel(DioConf_DioChannel_A2_A3_POS_GND_EN, STD_HIGH);
         break;

      case EnablePosGndCkt:
         /*Temporarily added here needs to be called from Sensor Pos Module*/
         /* Set POS_GND_EN to high to enable POGND_ADC, POS_GND_ADC_B */
         (void)Dio_Wrapper_WriteChannel(DioConf_DioChannel_A2_A3_POS_GND_EN, STD_HIGH);
         break;

      case Init_DisablePosGndCkt:
         /*Temporarily added here needs to be called from Sensor Pos Module*/
         /* Setting the GND pos Enable pin to zero */
         (void)Dio_Wrapper_WriteChannel(DioConf_DioChannel_A2_A3_POS_GND_EN, STD_LOW);
         break;

      case DisablePosGndCkt:
         /*Temporarily added here needs to be called from Sensor Pos Module*/
         /* Setting the GND pos Enable pin to zero */
         (void)Dio_Wrapper_WriteChannel(DioConf_DioChannel_A2_A3_POS_GND_EN, STD_LOW);
         break;

      default:
         break;
   }

} /* IoHwAb_ADC_PosPin_Prj_cbk() */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0315:  MISRA rule: Dir1.1
     Reason:     Pointer cast to void because generic access is necessary.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameters are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3226:  MISRA rule: Rule13.4
     Reason:     Needed for function like macro to do arithmetic operations in sub macros
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_TestCode:
     Reason:     This justification is used within the generated test code by the Rte Analyzer.
     Risk:       No functional risk.
     Prevention: Not required.

*/
