/*/****************************************************************************
 * Copyright 2020 Aptiv, All Rights Reserved.
 * Aptiv Confidential
 *
 * Version Tracking Header
 * %file_name: iohwab_adc.c
 * %version: 1 %
 * %last_modified_by:  %
 * %date_modified:  %
 *
 ******************************************************************************
 *
 * Module Name:
 *    iohwab_adc.c
 *
 * Description:
 *    This module contains the iohwab_adc implementation.
 *
 * Traces to Software Architecture/Design Document:
 *    SAD_...
 *
 * Implements following software requirements:
 *    WI-xxxxx,...
 *
 * Deviations/Justifications from software standards:
 *    None
 *
 *****************************************************************************/

/*===========================================================================*\
 * Includes
\*===========================================================================*/

#include "Rte_SWC_PLT_Service_IoHwAb.h"
#include "SWC_PLT_Appl_IoHwAb_Cfg.h"
#include "SWC_PLT_Service_IoHwAb.h"
#include "dd_gpt.h"
#include "thermal_monitor.h"
#include "vstdlib.h"
#include <string.h>

static uint16 RawAdc_Count_Io[ADC_CHANNEL_BUFFER];
Adc_ValueGroupType Adc_Results_Buff[ADC_NUM_CHANNEL];
Position_Pins_T lastPins; /* Global variable to store last position pins reading */
static bool Rdi_Log_Board_Connected = false;

#define RDI_LOG_BOARD_CON_VOLTS (0.288F)

/*===========================================================================*\
 * Function Definitions
\*===========================================================================*/

/*****************************************************************************
 *. Name: Init_ADC_Channels
 *.    Initializes the ADC results buffers and the ADC ISR required for the
 *.    ADC MCAL module
 *.
 *. Parameters:void
 *.
 *. Return Value: None.
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
void Init_ADC_Channels(void)
{
   uint32_t timeout_cnt = 1000000U;
   Adc_EnableGroupNotification(AdcConf_AdcGroup_AdcGroup);
   (void)Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup, (Adc_ValueGroupType *)(BUFFER_ADC0_G0));
   Adc_StartGroupConversion(AdcConf_AdcGroup_AdcGroup);
#ifndef UT_SERVICEIO
   {
      while (timeout_cnt > 0U)
      {
         if (ADC_CH_STS == CH_CAPTURE_DONE) /* checking if the capture is done for all the channels */
         {
            Adc_MainFunction();
            break;
         }
         timeout_cnt--;
      }
   }
#endif
   PVT_Monitoring_Init();
}

/**====================================================================================================================
 * FUNCTION: IoHwAb_RawAdcCount_Read
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
 *
 *
 * PRECONDITIONS:
 *
 * POSTCONDITIONS:
 *
 */
/*====================================================================================================================*/
Std_ReturnType IoHwAb_RawAdcCount_Read(Dt_RawAdcData_T *RawAdcData) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /* provide the value of the */
   (void)VStdMemCpy((void *)RawAdcData, (void *)&RawAdc_Count_Io, sizeof(RawAdc_Count_Io));
   RawAdcData->Validity_Flag = CODED_TRUE;
   return RTE_E_OK;
}

/*====================================================================================================================*\
* FUNCTION: IoHwAb_Get_FloatingPinPosition_FaultStatus
*=======================================================================================================================
* RETURN VALUE:
*
* PARAMETERS:
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
*
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/

void IoHwAb_Get_FloatingPinPosition_FaultStatus(uint8 *Status) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /*Do Nothing*/
}

/*====================================================================================================================*\
* FUNCTION: IoHwAb_Get_STM_TimeStamp
*=======================================================================================================================
* RETURN VALUE:
*
* PARAMETERS:
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
*
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
void IoHwAb_Get_STM_TimeStamp(uint32 *arg) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /*Do Nothing*/
}

/*====================================================================================================================*\
* FUNCTION: Platform_Time_Register_set
*=======================================================================================================================
* RETURN VALUE: None
*
* PARAMETERS:
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
*
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
void Platform_Time_Register_set(uint8 fault_type)
{
   /* To be enabled in future implementation*/
#if 0
   #ifndef UNIT_TEST
   /*logic for failure injection to be implemented here */
   if (SET_FAULT == fault_type)
   {
      /*Will set the fault*/
      int mask = 0xFF << 8;
      STM2_CTRL |= (2 << 8);
   }
   else
   {
      /*will clear the fault*/
      int mask = 0xFF << 8;
      STM2_CTRL &= ~mask;
   }
   #endif
#endif
}

/*====================================================================================================================*\
* FUNCTION: IoHwAb_Adc_Main_5ms
*=======================================================================================================================
* RETURN VALUE:
*
* PARAMETERS:
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
*
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
void IoHwAb_Adc_Main_5ms(void)
{
   Adc_MainFunction();
   /* To Read the Raw ADC counts for Hardware unit 0 */
   (void)Read_RawADCdata(ADC_0_GROUP, BUFFER_ADC0_G0);
}

/*====================================================================================================================*\
* FUNCTION: Read_RawADCdata
*=======================================================================================================================
* RETURN VALUE: Std_ReturnType
*
* PARAMETERS: Adc_Group, BufferPtr
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
* To read the ADC raw data
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
void Read_RawADCdata(uint8 Adc_Group, uint16 *BufferPtr)
{
   Adc_GetGroupStatus(ADC_0_GROUP);
   ADC_Read_Group(ADC_0_GROUP);

   /* Read Raw values from ADC */
   BufferPtr[CHANNEL_BOARD_REV] = Get_ADC_Counts(ADC_BOARD_REV);

   BufferPtr[CHANNEL_BATT_ADC] = Get_ADC_Counts(ADC_BATT);

   BufferPtr[CHANNEL_POS_GND_A] = Get_ADC_Counts(ADC_POS_GND_A);

   BufferPtr[CHANNEL_POS_GND_B] = Get_ADC_Counts(ADC_POS_GND_B);

   BufferPtr[CHANNEL_IGN] = Get_ADC_Counts(ADC_IGN);

   BufferPtr[CHANNEL_POS_GND_D] = Get_ADC_Counts(ADC_POS_GND_D);

   BufferPtr[CHANNEL_BATT_I_SENSE] = Get_ADC_Counts(ADC_BATT_I_SENSE);

   BufferPtr[CHANNEL_RDI_DETECT] = Get_ADC_Counts(ADC_RDI_DETECT);

   BufferPtr[CHANNEL_POS_GND_C] = Get_ADC_Counts(ADC_POS_GND_C);

   BufferPtr[CHANNEL_MCU_TEMP] = Get_ADC_Counts(ADC_MCU_TEMP);
}

/******************************************************************************
 *. Name: uint16_t Get_Board_Rev_Cnt(void)
 *.    This function reads ADC_BOARD_REV Pin & returns counts.
 *.
 *. Parameters: None.
 *.
 *. Return Value: uint16_t.
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
uint16_t Get_Board_Rev_Cnt(void)
{
   uint16_t board_rev_count = 0;
   board_rev_count          = Get_ADC_Counts(ADC_BOARD_REV);

   return board_rev_count;
}

/*****************************************************************************
 *. Name: bool Check_RDI_Log_Connection(void)
 *.    This function reads the RDI detect ADC pin to determine if the RDI log
 *.    board is connected.
 *.
 *. Parameters: None.
 *.
 *. Return Value: bool.
 *.
 ******************************************************************************/
bool Check_RDI_Log_Connection(void)
{
   float32_t rdi_detect_adc_volts = (float32_t)Get_ADC_Counts(ADC_RDI_DETECT) * (float32_t)RDI_DETECT_SCALE_FACTOR;
   Board_Revision_T boardRev      = Get_Board_Revision();

   /* Disabling RDI Detect logic for non-ADC HW version. Some of the HW versions for production Intent do not have Pull Up Resistor
    * for ADC pin */
   if ((boardRev == BOARD_REV_A3P0) || (boardRev == BOARD_REV_B0CVAL) || (boardRev == BOARD_REV_B0CVAL_ETH))
   {
      Rdi_Log_Board_Connected = false;
   }
   else
   {
      if (rdi_detect_adc_volts <= (float32_t)RDI_LOG_BOARD_CON_VOLTS)
      {
         Rdi_Log_Board_Connected = true;
      }
      else
      {
         Rdi_Log_Board_Connected = false;
      }
   }

   return Rdi_Log_Board_Connected;
}

/*****************************************************************************
 *. Name: bool Get_RDI_Log_Board_Connected(void)
 *.    This function returns the cached RDI log board connection status.
 *.
 *. Parameters: None.
 *.
 *. Return Value: bool.
 *.
 ******************************************************************************/
bool Get_RDI_Log_Board_Connected(void)
{
   return Rdi_Log_Board_Connected;
}

/*****************************************************************************
 *. Name: void Hw_Read_Position_Pins(Position_Pins_T *pos_pins)
 *.    This function reads the position pins.
 *.
 *. Parameters: Position_Pins_T * pos_pins
 *.
 *. Return Value: void.
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/

void Hw_Read_Position_Pins(Position_Pins_T *pos_pins)
{
   Std_ReturnType ret_value = E_NOT_OK;
   Adc_StatusType status;
   uint16 ExitCounter = 1000U;

   /* Enable the Dio pin for measuring the pin position values */
   IoHwAb_ADC_PosPin_Prj_cbk(EnablePosGndCkt);

   /* Stopping the group conversion after the enablw pin is enabled */
   Adc_StopGroupConversion(ADC_0_GROUP);

   /* Starting the group conversion for the very first time */
   Adc_StartGroupConversion(ADC_0_GROUP);

   do
   {
      Adc_MainFunction();
      status = Adc_GetGroupStatus(ADC_0_GROUP);
      if ((ADC_COMPLETED == status) || (ADC_STREAM_COMPLETED == status))
      {
         ret_value = ADC_Read_Group(ADC_0_GROUP);
      }
      ExitCounter--;
   } while ((ret_value != (uint16_t)E_OK) && (ExitCounter > NULL_VALUE));

   /* Start by setting the readings to invalid. They will be updated to valid if the A2Ds are read in this build configuration.*/
   memset((void *)pos_pins->pos_gnd_valid, false, sizeof(pos_pins->pos_gnd_valid));

   /* Read POS_GND signal raw value from ADC and calculate physical value */
   pos_pins->pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_A] = Get_ADC_Counts(ADC_POS_GND_A);
   pos_pins->pos_gnd_valid[CHANNEL_POSITION_GND_A]   = true;

   pos_pins->pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_B] = Get_ADC_Counts(ADC_POS_GND_B);
   pos_pins->pos_gnd_valid[CHANNEL_POSITION_GND_B]   = true;

   pos_pins->pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_C] = Get_ADC_Counts(ADC_POS_GND_C);
   pos_pins->pos_gnd_valid[CHANNEL_POSITION_GND_C]   = true;

   pos_pins->pos_gnd_a2d_cnt[CHANNEL_POSITION_GND_D] = Get_ADC_Counts(ADC_POS_GND_D);
   pos_pins->pos_gnd_valid[CHANNEL_POSITION_GND_D]   = true;
   /* Enable the Dio pin for measuring the pin position values */
   IoHwAb_ADC_PosPin_Prj_cbk(DisablePosGndCkt);
}

/*****************************************************************************
 *. Name: void Read_Sensor_Position_Pins(void)
 *.    This function reads sensor position pins.
 *.
 *. Parameters: None.
 *.
 *. Return Value: void.
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/

void Read_Sensor_Position_Pins(void)
{
   Hw_Read_Position_Pins(&lastPins);
}

/*****************************************************************************
 *. Name: Position_Pins_T * Get_Last_Sensor_Position_Pins(void)
 *.    This function returns the last read sensor position pins.
 *.
 *. Parameters: None.
 *.
 *. Return Value: Position_Pins_T*
 *.
 *. Shared Variables: lastPins.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
Position_Pins_T *Get_Last_Sensor_Position_Pins(void)
{
   return &lastPins;
}

/*****************************************************************************
 *. Name: Adc_Selftest
 *.
 *.    ADC MCAL module
 *.
 *. Parameters:void
 *.
 *. Return Value: None.
 *.
 *. Shared Variables: None.
 *.
 *. Design Information:
 *.    (xxx is version no.)
 *.
 *. SCR Information:
 *.
 *.
 ******************************************************************************/
uint8_t Adc_Selftest(void)
{
   /* To be enabled in future implementation*/
#if 0
   uint8_t retvalue    = E_NOT_OK;
   uint32_t u32timeout = ADC_SELF_TEST_TIMEOUT_COUNTER;
   uint8_t msr_status;
   uint8_t endof_s_alg;
   uint8_t statusof_s_alg;
   uint8_t adc_0_result = E_OK;
   #ifndef UNIT_TEST
   /* 1. Program NCMR0 to select channels to be converted for normal conversion.*/
   IP_ADC_0->NCMR0 = ADC_NCMR0_CH0_MASK;
   /* 2. Program MCR[MODE] = 1 to select Scan mode.*/
   IP_ADC_0->MCR = ADC_MCR_MODE_MASK;
   /* 3. Enable the self-testing channel by setting STCR2[EN]. */
   IP_ADC_0->STCR2 = ADC_STCR2_EN_MASK;
   /* set watchdog timeout of 10ms for self test */
   IP_ADC_0->STBRR = ADC_STBRR_WDT(ADC_WDG_10MS);
   /* Enable AWDE for comparision of converted values during algorithm S against threshold values */
   IP_ADC_0->STAW0R = ADC_STAW0R_AWDE_MASK;
   /* Enable the WDTE bit for algorithm S, so that end of algorithm completion can be detected  */
   IP_ADC_0->STAW0R = ADC_STAW0R_WDTE_MASK;
   /* 4. Start the normal conversion by setting MCR[NSTART]. */
   IP_ADC_0->MCR = ADC_MCR_NSTART_MASK;
   /* check self test s0 is performed */
   msr_status = ((IP_ADC_0->MSR & ADC_MSR_SELF_TEST_S_MASK) == ADC_MSR_SELF_TEST_S_MASK);

   while (ADC_MSR_SELFSTART_S != msr_status)
   {
      if (u32timeout > (uint32_t)0UL)
      {
         u32timeout--;
      }
      else
      {
         break;
      }
      msr_status = ((IP_ADC_0->MSR & ADC_MSR_SELF_TEST_S_MASK) == ADC_MSR_SELF_TEST_S_MASK);
   }
   /*check if algorithm ended . STSR1[WDG_EOA_S] == 1*/
   endof_s_alg = ((IP_ADC_0->STSR1 & ADC_STSR1_WDG_EOA_S_MASK) == ADC_STSR1_WDG_EOA_S_MASK);

   u32timeout = ADC_SELF_TEST_TIMEOUT_COUNTER;

   while (STD_HIGH != endof_s_alg)
   {
      if (u32timeout > (uint32_t)0UL)
      {
         u32timeout--;
      }
      else
      {
         break;
      }
      endof_s_alg = ((IP_ADC_0->STSR1 & ADC_STSR1_WDG_EOA_S_MASK) == ADC_STSR1_WDG_EOA_S_MASK);
   }
   if ((STD_HIGH == endof_s_alg))
   {
      AdcSelfTestCompleted = E_OK;
   }
   if ((uint32_t)0UL == u32timeout || AdcSelfTestCompleted == ADC_SELF_TEST_FAIL)
   {
      adc_0_result = E_NOT_OK;
   }
   /*Check if there are any errors in completed algorithm S*/
   statusof_s_alg = ((IP_ADC_0->STSR1 & ADC_STSR1_ERR_S0_MASK) == ADC_STSR1_ERR_S0_MASK);

   if (STD_HIGH == statusof_s_alg)
   {
      /*If there are no errors set return value as E_OK*/
      adc_0_result = E_NOT_OK;
   }
   if (E_OK == adc_0_result)
   {
      retvalue = E_OK;
   }
   return retvalue;
   #endif
#endif
   return 0;
}

/*====================================================================================================================*\
* FUNCTION: IoHwAb_AdcNotification
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
* Adc notification funtion.
*
* PRECONDITIONS:
*
* POSTCONDITIONS:
*
\*====================================================================================================================*/
void IoHwAb_AdcNotification(void)
{
   if (ADC_STREAM_COMPLETED == Adc_GetGroupStatus(AdcConf_AdcGroup_AdcGroup))
   {
      Adc_ReadGroup(AdcConf_AdcGroup_AdcGroup, Adc_Results_Buff);
   }
}

/************************************************************************************************************************************
 *  Revision History
 *
 *   Date          SCR			  Name             Description
 *   ----          ----		  ----------- ---------------------------------------------------------------------------------------
 * 10-April-25    EEG-5727     Keerthi          Service_IoHwAb Bringup
 * *************************************************************************************************************************************/
