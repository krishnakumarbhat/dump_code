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
 *             File:  SWC_PLT_Appl_IoHwAb.c
 *           Config:  Gen8_iND13400.dpa
 *        SW-C Type:  SWC_PLT_Appl_IoHwAb
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PLT_Appl_IoHwAb>
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
 * Dt_Therm_Mon_Temp_Opt_T
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 *
 * Runnable Entities:
 * ==================
 * RE_PLT_IoHwAb_Init
 *   This will initialize all static variables in this SWC
 *
 *
 * RE_PLT_IoHwAb_Main_50ms
 *   All the functionalities which are related to 50 ms shall
 *      be called here.
 *
 * RE_PLT_IoHwAb_Main_5ms
 *   All the functionalities which are related to 5 ms shall
 *      be called here.
 *
 *********************************************************************************************************************/

#include "Rte_SWC_PLT_Appl_IoHwAb.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Eth.h"
#include "SchM_Can.h"
#include "SchM_Eth.h"
#include "iohwab_adc_appl.h"
#ifndef UNIT_TEST
   #include "PHY_User_Cbk.h"
#endif
/*****************For Testing, To be Deleted, Start***********************/
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
 * Rte_DT_DT_Thermal_Monitor_Temperatures_T_0_0: Real in interval [-FLT_MAX...FLT_MAX] with single precision
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dt_ECUPosition_Value: Enumeration of integer in interval [0...255] with enumerators
 *   FRONT_LEFT_VALUE (0U)
 *   REAR_LEFT_VALUE (1U)
 *   FRONT_RIGHT_VALUE (2U)
 *   REAR_RIGHT_VALUE (3U)
 *   INVALID_POS_VALUE (255U)
 * Dt_SubState_T: Enumeration of integer in interval [0...255] with enumerators
 *   LO_V2_FROM_LO_Vtemp (0U)
 *   LO_V1_FROM_LO_Vtemp (1U)
 *   LO_V2_FROM_LO_V1 (2U)
 *   NORMV_FROM_LO_VTEMP_TONORM (3U)
 *   NORMV_FROM_LO_V1_TONORM (4U)
 *   NORMV_FROM_LO_V2_TONORM (5U)
 *   HI_V2_FROM_HI_Vtemp (6U)
 *   HI_V1_FROM_HI_Vtemp (7U)
 *   HI_V2_FROM_HI_V1 (8U)
 *   NORMV_FROM_HI_VTEMP_TONORM (9U)
 *   NORMV_FROM_HI_V1_TONORM (10U)
 *   NORMV_FROM_HI_V2_TONORM (11U)
 * Dt_Therm_Mon_Temp_Opt_T: Enumeration of integer in interval [0...255] with enumerators
 *   IMMEDIATE_TEMPERATURES_KELVIN (0U)
 *   AVERAGE_TEMPERATURES_KELVIN (1U)
 *   IMMEDIATE_TEMPERATURES_CELCIUS (2U)
 *   AVERAGE_TEMPERATURES_CELCIUS (3U)
 *   IMMEDIATE_TEMPERATURES_FAHRENHEIT (4U)
 *   AVERAGE_TEMPERATURES_FAHRENHEIT (5U)
 * Dt_VBattState_T: Enumeration of integer in interval [0...255] with enumerators
 *   PowerON (0U)
 *   NORMV (1U)
 *   LO_V1 (2U)
 *   HI_V1 (3U)
 *   LO_V2 (4U)
 *   HI_V2 (5U)
 *   LO_Vtemp (6U)
 *   LO_VTEMP_TONORM (7U)
 *   LO_V1_TONORM (8U)
 *   LO_V2_TONORM (9U)
 *   HI_VTEMP_TONORM (10U)
 *   HI_V1_TONORM (11U)
 *   HI_V2_TONORM (12U)
 *   HI_Vtemp (13U)
 *
 * Array Types:
 * ============
 * Rte_DT_DT_Thermal_Monitor_Temperatures_T_0: Array with 2 element(s) of type Rte_DT_DT_Thermal_Monitor_Temperatures_T_0_0
 *
 * Record Types:
 * =============
 * DT_Thermal_Monitor_Temperatures_T: Record with elements
 *   temperature of type Rte_DT_DT_Thermal_Monitor_Temperatures_T_0
 * DT_Thermal_mon_mes_results_T: Record with elements
 *   immediate_temp_k of type DT_Thermal_Monitor_Temperatures_T
 *   average_temp_k of type DT_Thermal_Monitor_Temperatures_T
 *   immediate_temp_c of type DT_Thermal_Monitor_Temperatures_T
 *   average_temp_c of type DT_Thermal_Monitor_Temperatures_T
 *   immediate_temp_f of type DT_Thermal_Monitor_Temperatures_T
 *   average_temp_f of type DT_Thermal_Monitor_Temperatures_T
 * Dt_AdcData_T: Record with elements
 *   Adc_Board_Rev of type float32
 *   Adc_Batt_Volt of type float32
 *   Adc_Pos_Gnd_A of type float32
 *   Adc_Pos_Gnd_B of type float32
 *   Adc_Pos_Gnd_C of type float32
 *   Adc_Pos_Gnd_D of type float32
 *   Adc_Eth_0v9 of type float32
 *   Adc_Rdi_Detect of type float32
 *   Adc_MMIC_Temp of type float32
 *   Adc_Mcu_Temp of type float32
 *   Validity_Flag of type uint16
 * Dt_EcuPosition_T: Record with elements
 *   ECUPosition_Value of type uint8
 *   Reserved of type uint8
 *   CRC_Value of type uint16
 * Dt_RawAdcDataFilt_T: Record with elements
 *   Adc_Board_Rev of type uint16
 *   Adc_Batt_Volt of type uint16
 *   Adc_Pos_Gnd_A of type uint16
 *   Adc_Pos_Gnd_B of type uint16
 *   Adc_Pos_Gnd_C of type uint16
 *   Adc_Pos_Gnd_D of type uint16
 *   Adc_Eth_0v9 of type uint16
 *   Adc_Rdi_Detect of type uint16
 *   Adc_MMIC_Temp of type uint16
 *   Adc_Mcu_Temp of type uint16
 *   Validity_Flag of type uint8
 *   Pos_Validity_Flag of type uint8
 * Dt_RawAdcData_T: Record with elements
 *   Adc_Board_Rev of type uint16
 *   Adc_Batt_Volt of type uint16
 *   Adc_Pos_Gnd_A of type uint16
 *   Adc_Pos_Gnd_B of type uint16
 *   Adc_Pos_Gnd_C of type uint16
 *   Adc_Pos_Gnd_D of type uint16
 *   Adc_Eth_0v9 of type uint16
 *   Adc_Rdi_Detect of type uint16
 *   Adc_MMIC_Temp of type uint16
 *   Adc_Mcu_Temp of type uint16
 *   Validity_Flag of type uint16
 * TR_AdcMeasurement_T: Record with elements
 *   TR_MCUtemp_Calflt of type boolean
 *   TR_onboardThermistorFault of type boolean
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   Dt_EcuPosition_T *Rte_CData_ECU_Position_ROMDefault(void)
 *
 *********************************************************************************************************************/

#define SWC_PLT_Appl_IoHwAb_START_SEC_CODE
#include "SWC_PLT_Appl_IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_Platform_register_set
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <fault_type> of PortPrototype <CS_Platform_register_set>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CS_Platform_register_set(uint8 fault_type)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CS_Platform_register_set_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_IoHwAb_CODE)
CS_Platform_register_set(uint8 fault_type) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_Platform_register_set
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_ThermMonTemp_Read
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Read> of PortPrototype <CS_ThermMonTemp>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CS_ThermMonTemp_Read(Dt_Therm_Mon_Temp_Opt_T temp_option, DT_Thermal_Monitor_Temperatures_T *reqValue)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Pi_ThermMonTemp_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CS_ThermMonTemp_Read_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PLT_Appl_IoHwAb_CODE)
CS_ThermMonTemp_Read(Dt_Therm_Mon_Temp_Opt_T temp_option,
                     P2VAR(DT_Thermal_Monitor_Temperatures_T, AUTOMATIC, RTE_SWC_PLT_APPL_IOHWAB_APPL_VAR)
                        reqValue) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_ThermMonTemp_Read (returns application error)
    *********************************************************************************************************************/
   Std_ReturnType retval = RTE_E_OK;
   retval                = IoHwAb_Appl_ThermMonTemp_Read(temp_option, reqValue);
   return retval;

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_IoHwAb_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Rp_ECUPos_Value_De_ECUPos_Value(Dt_ECUPosition_Value *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_ADC_Measurement_interface_Element(const TR_AdcMeasurement_T *data)
 *   Std_ReturnType Rte_Write_Pp_BoardRevision_Xcp_De_BoardRevision_Xcp(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_Board_Revision_De_Board_Revision(uint8 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_IoHwAb_Init_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_IoHwAb_CODE) RE_PLT_IoHwAb_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_IoHwAb_Init
    *********************************************************************************************************************/

   IoHwAb_Appl_Init();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_IoHwAb_Main_10ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_IoHwAb_Main_10ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_IoHwAb_CODE) RE_PLT_IoHwAb_Main_10ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_IoHwAb_Main_10ms
    *********************************************************************************************************************/

   Can_MainFunction_Mode();
   Eth_MainFunction();

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_IoHwAb_Main_50ms
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
 *   Std_ReturnType Rte_Read_Rp_XCP_ADC_MCU_Temp_Override_De_XCP_ADC_MCU_Temp_Override(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_MCU_Sensor_Count_De_MCU_Sensor_Count(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_PhysicalAdcData_De_PhysicalAdcData(const Dt_AdcData_T *data)
 *   Std_ReturnType Rte_Write_Pp_RawAdc_Data_Filtered_De_RawAdcData(const Dt_RawAdcDataFilt_T *data)
 *   Std_ReturnType Rte_Write_Pp_RawAdc_Data_UnFiltered_RawAdcDataUnfiltered(const Dt_RawAdcData_T *data)
 *   Std_ReturnType Rte_Write_Pp_SubState_De_SubState(Dt_SubState_T data)
 *   Std_ReturnType Rte_Write_Pp_TimeLeft_To_NextState_De_TimeLeft_To_NextState(uint16 data)
 *   Std_ReturnType Rte_Write_Pp_Vbatt_State_De_Vbatt_State(Dt_VBattState_T data)
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_Pp_DcmSessionPrecondition_Mode_De_DcmSessionPrecondition_Mode(uint8 mode)
 *   Modes of Rte_ModeType_DcmSessionPrecondition_Mode:
 *   - RTE_MODE_DcmSessionPrecondition_Mode_HI_V1
 *   - RTE_MODE_DcmSessionPrecondition_Mode_HI_V1_TONORM
 *   - RTE_MODE_DcmSessionPrecondition_Mode_HI_V2
 *   - RTE_MODE_DcmSessionPrecondition_Mode_HI_V2_TONORM
 *   - RTE_MODE_DcmSessionPrecondition_Mode_HI_VTEMP_TONORM
 *   - RTE_MODE_DcmSessionPrecondition_Mode_HI_Vtemp
 *   - RTE_MODE_DcmSessionPrecondition_Mode_LO_V1
 *   - RTE_MODE_DcmSessionPrecondition_Mode_LO_V1_TONORM
 *   - RTE_MODE_DcmSessionPrecondition_Mode_LO_V2
 *   - RTE_MODE_DcmSessionPrecondition_Mode_LO_V2_TONORM
 *   - RTE_MODE_DcmSessionPrecondition_Mode_LO_VTEMP_TONORM
 *   - RTE_MODE_DcmSessionPrecondition_Mode_LO_Vtemp
 *   - RTE_MODE_DcmSessionPrecondition_Mode_NORMV
 *   - RTE_MODE_DcmSessionPrecondition_Mode_PowerON
 *   - RTE_TRANSITION_DcmSessionPrecondition_Mode
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CS_Update_Thermal_Mon_Temps_Read(DT_Thermal_mon_mes_results_T *therm_temp_results)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Pi_Update_Thermal_Mon_Temps_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_IoHwAb_Main_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#ifndef UNIT_TEST
volatile uint8_t gDebug_read_tja_registers = 0U;
#endif
__attribute__((optnone)) FUNC(void, SWC_PLT_Appl_IoHwAb_CODE)
   RE_PLT_IoHwAb_Main_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_IoHwAb_Main_50ms
    *********************************************************************************************************************/

   IoHwAb_Appl_Main_50ms();
#ifndef UNIT_TEST
   if (gDebug_read_tja_registers)
   {
      TJA1103_Debug_Reg_Readout();
      gDebug_read_tja_registers = 0U;
   }
#endif
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_PLT_IoHwAb_Main_5ms
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
 *   Std_ReturnType Rte_Read_Rp_XCP_ADC_MCU_Temp_Override_De_XCP_ADC_MCU_Temp_Override(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_Analog_Channel_Count_De_Analog_Channel_Count(uint16 data)
 *   Std_ReturnType Rte_Write_Pp_PhysicalAdcData_De_PhysicalAdcData(const Dt_AdcData_T *data)
 *   Std_ReturnType Rte_Write_Pp_RawAdc_Data_Filtered_De_RawAdcData(const Dt_RawAdcDataFilt_T *data)
 *   Std_ReturnType Rte_Write_Pp_RawAdc_Data_UnFiltered_RawAdcDataUnfiltered(const Dt_RawAdcData_T *data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CS_RawAdcCount_Read(Dt_RawAdcData_T *RawAdcData)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Pi_RawAdcCount_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_PLT_IoHwAb_Main_5ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_Appl_IoHwAb_CODE) RE_PLT_IoHwAb_Main_5ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_PLT_IoHwAb_Main_5ms
    *********************************************************************************************************************/

   IoHwAb_Appl_Main_5ms();
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

#define SWC_PLT_Appl_IoHwAb_STOP_SEC_CODE
#include "SWC_PLT_Appl_IoHwAb_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#if 0
/***  Start of saved code (symbol: documentation area:RE_IoHwAb_10ms_doc)  **********************************/
/*****************For Testing, To be Deleted, Start***********************/
volatile uint8 Read_Reg_En             = 0;
volatile uint8 Read_Reg_En_Normal      = 0;
volatile uint16 Read_MDIO_Data         = 0;
volatile uint16 Read_MDIO_Data_Normal  = 0;
uint8 dummy_eth_data[10]               = {0, 1, 0xF, 0xE, 0xF, 0xE, 0xF, 0xE, 0xF, 0xE};
volatile Std_ReturnType soad_tr_result = 2U;
volatile uint32 max_frames_per_5ms     = 1;
volatile uint32 Max_frame_transmitted_5ms, frame_transmitted_5ms;
volatile uint32 Eth_Transmit_Fail, Eth_Transmit_Success;
PduInfoType pduInfo;
volatile uint8 Eth_Transmit_En                = 0;
volatile uint8 RTL9010xx_Debug_Reg_Readout_En = 0;
/*****************For Testing, To be Deleted, End*************************/

   #define ETH_IF_EXAMPLE_CTRLIDX    (0u)
   #define ETH_IF_EXAMPLE_RX_FIFOIDX (0u)
uint8_t RxReadStatus;
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:RE_IoHwAb_50ms_doc)  **********************************/
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:RE_IoHwAb_5ms_doc)  ***********************************/
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:RE_IoHwAb_Init_doc)  **********************************/
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:RE_IoHwAb_10ms)  *********************************/
   Can_MainFunction_Mode();
   Eth_MainFunction();/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:RE_IoHwAb_50ms)  *********************************/
   /*****************For Testing, To be Deleted, Start***********************/

   if (Read_Reg_En)
   {
      Read_Reg_En    = 0;
      Read_MDIO_Data = mdio_read(0x02);
   }

   if (Read_Reg_En_Normal)
   {
      Read_Reg_En_Normal    = 0;
      Read_MDIO_Data_Normal = normal_mdio_read(0x10, 0xA42);
   }

   if (RTL9010xx_Debug_Reg_Readout_En)
   {
      RTL9010xx_Debug_Reg_Readout_En = 0;
      RTL9010xx_Debug_Reg_Readout();
   }

   if (Eth_Transmit_En)
   {
      /* Test Ethernet */

      uint32 idx;

      pduInfo.SduLength  = 255U; // 1472U;
      pduInfo.SduDataPtr = &dummy_eth_data[0];

      for (idx = 0; idx < max_frames_per_5ms; idx++)
      {
         dummy_eth_data[0]++; /* Increase the rolling counter */
         soad_tr_result = SoAd_IfTransmit(SoAdConf_SoAdPduRoute_RDR_LOGGING_TX, &pduInfo);

         if (soad_tr_result != E_OK)
         {
            Eth_Transmit_Fail++;
         }
         else
         {
            Eth_Transmit_Success++;
            frame_transmitted_5ms++;
         }
      }

      /* capture the max number of transmitted sent per cycle */
      Max_frame_transmitted_5ms =
         (Max_frame_transmitted_5ms < frame_transmitted_5ms) ? frame_transmitted_5ms : Max_frame_transmitted_5ms;
      /* reset the counter of transmitted frames per cycle*/
      frame_transmitted_5ms = 0;
   }
   /*****************For Testing, To be Deleted, End*************************//***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:RE_IoHwAb_5ms)  **********************************/
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:RE_IoHwAb_Init)  *********************************/
/***  End of saved code  ************************************************************************************/
#endif

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
