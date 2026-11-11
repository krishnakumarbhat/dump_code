/*===========================================================================*/
/**
 * @file SWC_PLT_CDD_Radar_Control_fake.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Fake/Mock header file for SWC_PLT_CDD_Radar_Control unit testing
 * This file provides mock implementations for all external dependencies
 *
 * @section ABBR ABBREVIATIONS:
 *   - FFF: Fake Function Framework
 *   - MMIC: Monolithic Microwave Integrated Circuit
 *   - MIPI: Mobile Industry Processor Interface
 *   - ADC: Analog-to-Digital Converter
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - SWC_PLT_CDD_Radar_Control Unit Test Design
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 */
/*==========================================================================*/

#ifndef SWC_PLT_CDD_RADAR_CONTROL_FAKE_H
#define SWC_PLT_CDD_RADAR_CONTROL_FAKE_H

#include "fff.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

   typedef union FuSa_Faults_Union_Tag
   {
      uint8_t arr_val[12];
   } FuSa_Faults_Union_T;

   FuSa_Faults_Union_T *Get_Mmic_Fusa_Backup_Fault_Ptr(void);

/*===========================================================================*
 * Stub headers to prevent including real AUTOSAR headers
 *===========================================================================*/
// Prevent inclusion of actual RTE headers by defining their include guards
#define RTE_SWC_PLT_CDD_RADAR_CONTROL_H
#define Rte_SWC_PLT_CDD_Radar_Control_h // Alternative guard format
#define SWC_PLT_CDD_RADAR_CONTROL_MEMMAP_H
#define SWC_PLT_CDD_Radar_Control_MemMap_h // Alternative guard format

// Prevent inclusion of peripheral/driver headers
#define MIPI_WRAPPER_H
#define UART_H
#define DD_GPT_H
#define DD_MIPI_H
#define DD_MMIC_H
#define DSP_SETUP_H
#define MCAL_INIT_H
#define MMIC_ERROR_H
#define MMIC_INTERFACE_H // Prevent mmic_interface.h but we'll include mmic_stream.h below
#define RADAR_CTL_H

#define RADAR_DATA_H
#define CSTRING          // Prevent C++ cstring include
#define _GLIBCXX_CSTRING 1

/* Include real MMIC stream header for proper types */
#include "mmic_stream.h"

/*===========================================================================*
 * AUTOSAR Standard Types
 *===========================================================================*/
#ifndef STD_TYPES_H
   #define STD_TYPES_H
   typedef uint8_t Std_ReturnType;
   #define E_OK     0x00U
   #define E_NOT_OK 0x01U
#endif

#ifndef RTE_TYPE_H
   #define RTE_TYPE_H
   typedef uint8_t uint8; // AUTOSAR type
   typedef uint16_t uint16;
   typedef uint32_t uint32;
   typedef int8_t sint8;
   typedef int16_t sint16;
   typedef int32_t sint32;
#endif

#ifndef OS_ALARM_TYPES_DEFINED
   #define OS_ALARM_TYPES_DEFINED
   typedef uint8_t StatusType;
   typedef uint32_t TickType;
   typedef uint32_t AlarmType;
   #define Rte_Al_TE_SWC_PLT_CDD_Radar_Control_RE_Radar_Ctl_Look_Complete_Post_RFBIST ((AlarmType)24U)
#endif

/*===========================================================================*
 * Constants and Macros
 *===========================================================================*/
#define FUNC(rettype, memclass)              rettype
#define P2VAR(ptrtype, memclass, ptrclass)   ptrtype *
#define P2CONST(ptrtype, memclass, ptrclass) const ptrtype *
#define SWC_PLT_CDD_Radar_Control_CODE
#define SWC_PLT_CDD_Radar_Control_START_SEC_CODE
#define SWC_PLT_CDD_Radar_Control_STOP_SEC_CODE
#define RTE_CODE

#ifdef CODED_TRUE
   #undef CODED_TRUE
#endif
#define CODED_TRUE 0x01U
#ifdef CODED_FALSE
   #undef CODED_FALSE
#endif
#define CODED_FALSE 0x00U
#define TRUE        1
#define FALSE       0
#define NULL_PTR    ((MMIC_Data_Logging_T *)0)

#ifndef RESI_MODE_ENABLE
   #define RESI_MODE_ENABLE 0
#endif

#ifndef ENABLE_SIT_TEST_STUBS
   #define ENABLE_SIT_TEST_STUBS 0
   #define STD_ON                1
   #define STD_OFF               0
#endif

#ifndef ENABLE_SQT_TEST_STUBS
   #define ENABLE_SQT_TEST_STUBS 0
#endif
#ifndef Num_Elems
   #define Num_Elems(array) (sizeof(array) / sizeof(array[0]))
#endif
   /*===========================================================================*
    * Data Type Definitions
    *===========================================================================*/
   typedef uint8_t Idt_XCP_Op_Mode_T;
   typedef uint8_t Dt_Fault_name_FHTI;
   typedef uint16_t WdgM_CheckpointIdType;

   typedef enum
   {
      MMIC_Secondary_Clock_Fault     = 0,
      MMIC_Secondary_MCU_Fault       = 1,
      MMIC_Secondary_Register_Fault  = 2,
      MMIC_Secondary_TX_RFBIST_Fault = 3,
      MMIC_Secondary_RX_RFBIST_Fault = 4
   } MMIC_Secondary_Fault_T;

   /* MMIC Error Flags Structure */
   typedef struct
   {
      uint8_t temperature_max_err;
      uint8_t chirp_pll_err;
      uint8_t tx0_ball_brk_err;
      uint8_t tx1_ball_brk_err;
      uint8_t tx2_ball_brk_err;
      uint8_t tx3_ball_brk_err;
      uint8_t sensor_dead_err;
      uint8_t safety_intergrity_err;
      uint8_t MMIC_TemperatureLowFault;
      uint8_t MMIC_SafeStartUp_Error;
      uint8_t MMIC_Transmitter_ID_Fault;
      uint8_t RF_BallBreak;
      uint8_t MMIC_Loop_Back_Test_Fault;
      uint8_t Data_Acquisition_err;
      uint8_t RFE_Freq_Monitor_err;
      uint8_t RFE_Power_Level_err;
      uint8_t RFE_Lock_Step_err;
      uint8_t RFE_CPU_err;
      uint8_t RFE_Voltage_err;
      uint8_t RFE_TX_RFBIST_err;
      uint8_t RFE_RX_RFBIST_err;
      uint8_t MMIC_Error_Recovery_Failure;
      uint8_t MMIC_Id_Unprogrammed_Error;
      uint8_t API_Look_Config_err;
      uint8_t API_Look_Complete_err;
      uint8_t API_Look_Trigger_err;
      uint8_t MMIC_Secondary_Clock_Fault;
      uint8_t MMIC_Secondary_MIPI_Fault;
      uint8_t MMIC_Secondary_Register_Fault;
      uint8_t MMIC_Secondary_MCU_Fault;
   } Dt_MMIC_ErrorFlags;

   /* Radar Core Status Structure */
   typedef struct
   {
      uint8_t RadarInitializatonStatus;
      uint8_t RadarReInitRequired;
      uint8_t IsRadiating;
      uint8_t OperationMode_Radar;
   } Dt_RadarCoreStatus;

   /* MMIC Temperature Structure */
   typedef struct
   {
      int16_t MMIC_TX0_Temp;
      int16_t MMIC_TX1_Temp;
      int16_t MMIC_TX2_Temp;
      int16_t MMIC_TX3_Temp;
      int16_t MMIC_RX0_Temp;
      int16_t MMIC_PVT_Temp;
      int16_t MMIC_Quad_Temp;
   } Idt_Type_MMIC_Temperature;

   /* XCP Single Look Structure */
   typedef struct
   {
      uint8_t single_look_en;
      uint8_t single_look_select;
   } Idt_XCP_Single_Look_T;

   typedef enum API_Fault_Type_Tag
   {
      API_FAULT_LOOK_CONFIG,
      API_FAULT_LOOK_TRIGGER,
      API_FAULT_LOOK_COMPLETE,
      MAX_API_FAULT_TYPE
   } API_Fault_Type_T;

   typedef enum Radar_Ctl_Init_Status_Tag
   {
      RADAR_CTL_INIT_FAIL,
      RADAR_CTL_INIT_NOT_STARTED,
      RADAR_CTL_INIT_STARTED,
      RADAR_CTL_INIT_SUCCESS,
      NUM_RADAR_CTL_INIT
   } Radar_Ctl_Init_Status_T;
   typedef enum XCP_MMIC_FIT_Enable_Tag
   {
      XCP_MMIC_NO_FIT_TEST = 0U,
      XCP_MMIC_ID_FIT_POS_TEST,
      XCP_MMIC_ID_FIT_NEG_TEST,
      XCP_MMIC_OT_DEGRADED_FIT_TEST,
      XCP_MMIC_OT_IDLE_FIT_TEST,
      XCP_MMIC_OT_FAULTED_FIT_TEST,
      XCP_MMIC_HIGH_TEMP_FIT_TEST,
      XCP_MMIC_CHIRP_PLL_UNLOCK_FIT_TEST,
      XCP_MMIC_LOW_TEMP_FIT_TEST,
      XCP_MMIC_BALL_BREAK_FIT_TEST,
      XCP_MMIC_TX_BIST_FIT_TEST,
      XCP_MMIC_RX_BIST_FIT_TEST,
      XCP_MMIC_CPU_FIT_TEST,
      XCP_MMIC_PLD_FIT_TEST,
      XCP_MMIC_FREQ_MON_FIT_TEST,
      XCP_MMIC_LOCK_STEP_FIT_TEST,
      XCP_MMIC_SUPPLY_VOLATGE_FIT_TEST,
      XCP_MMIC_DAQ_MIN_TIME_FIT_TEST,
      XCP_MMIC_DAQ_MAX_TIME_FIT_TEST,
      XCP_MMIC_FUNCTION_CONFIG_FIT_TEST,
      XCP_MMIC_FCCU_FAULT_FIT_TEST,
      XCP_MMIC_SAFE_STARTUP_FIT_TEST,
      XCP_MMIC_MIPI_FAILURE_FIT_TEST,
      XCP_MMIC_API_LOOK_TRIGGER_FIT_TEST,
      XCP_MMIC_API_LOOK_COMPLETE_FIT_TEST,
      XCP_MMIC_SFT_RECOVERABLE_ERROR_FIT_TEST,
      XCP_MMIC_SOURCE_LEVEL_BIST_CONFIG_FIT_TEST,
      XCP_MMIC_MAX_NUMBER_OF_FIT_TEST
   } XCP_MMIC_FIT_Enable_T;

   typedef struct Radar_Ctl_Data_Tag
   {
      Radar_Ctl_Init_Status_T init_status;
      bool radiate_enable;
   } Radar_Ctl_Data_T;

   /* NVM Data Structure for RFE faults */
   typedef struct
   {
      uint32 CORE_BANK_SFT_ERR_MON;
      uint32 CORE_BANK_SFT_ERR_STATUS;
      uint32 CORE_BANK_MCU_STS_MCU_MSSG;
      uint32 FUSA_IRQ0_FLAG_R;
      uint32 FUSA_IRQ1_FLAG_R;
      uint32 FUSA_IRQ2_FLAG_R;
      uint32 Api_ret_val;
      uint32 LOGEN_BANK_CHRP_GEN_ERROR;
      uint32 LOGEN_BANK_LOGEN_ERROR;
      uint32 CPU_SYS_MCU_ERR_0;
      uint32 CPU_SYS_MCU_ERR_1;
      uint32 CPU_SYS_MCU_ERR_2;
      uint32 CPU_SYS_MCU_ERR_3;
      uint32 ASYNC_BANK_ASYNC_ERR1;
      uint32 PROF_BANK_PRF_ERR1;
      uint32 PROF_BANK_PRF_ERR2;
      uint32 RXADC_FUSAMON;
      uint8 maf_status;
   } Dt_Rfe_REC_NREC_Fault;

   /* MMIC Stream structure and types are now from mmic_stream.h */
   /* External global for MMIC stream */
   extern MMIC_Stream_T MMIC_Stream;

   typedef enum Radar_Ctl_State_Tag
   {
      RADAR_CTL_OFF,
      RADAR_CTL_FAULTED,
      RADAR_CTL_INIT,
      RADAR_CTL_READY,
      RADAR_CTL_CONFIGURED,
      RADAR_CTL_TRANSMITTING,
      RADAR_CTL_A2D_INJECTION,
      RADAR_CTL_PURE_CW,
      RADAR_CTL_DEGRADED,
      RADAR_CTL_IDLE,
      RADAR_CTL_NUM_STATES
   } Radar_Ctl_State_T;

   /* Test-global instance (defined in fake.cc) */
   extern Radar_Ctl_Data_T Radar_Ctl_Data;
   extern Radar_Ctl_State_T Radar_Ctl_State;

#define Get_Radar_Ctl_Init_Status() (Radar_Ctl_Data.init_status)

/* Radar Initialization Status */
#define RADAR_SUCCESS     0x01U
#define RADAR_NOT_STARTED 0x00U

   /*===========================================================================*
    * External Variable Declarations (to be mocked)
    *===========================================================================*/
   extern int32_t Offline_Data_Mode_Enabled_Counter;
   extern bool Stream_Handler_Init_Flag;
   extern uint32_t Timestamp_Seconds;
   extern bool isTriggeredOnce;
   extern bool Is_Triggered_Once;
   extern volatile XCP_MMIC_FIT_Enable_T XCP_MMIC_FIT_Enable;
   extern Dt_RadarCoreStatus Radar_Core_Status;

   /* ITF Modes */
   typedef enum
   {
      ITF_ADC_INJECTION_MODE = 1,
      ITF_NORMAL_MODE        = 0
   } ITF_Mode_T;

   extern ITF_Mode_T Offline_Mode_Flag;

   /*===========================================================================*
    * Function Forward Declarations (defined in source file)
    *===========================================================================*/
   void MMIC_Helper_Function(void);
   static void MMIC_Diagnostics(void);

   /*===========================================================================*
    * RTE Mock Function Declarations
    *===========================================================================*/
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_Rp_XCP_CW_Mode_De_XCP_CW_Mode, uint8_t *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_Rp_XCP_Phase_Rotator_Calibration_De_XCP_Phase_Rotator_Calibration, uint8_t *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_Rp_XCP_Op_Mode_De_XCP_Op_Mode, Idt_XCP_Op_Mode_T *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable, Idt_XCP_Single_Look_T *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_Rp_XCP_RFBIST_Calib_Trigger_De_XCP_RFBIST_Calib_Trigger, uint8_t *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_Rp_Command_Radiate_Final_De_CommandRadiate_Final, uint8_t *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_Rp_IsRadiateForced_De_IsRadiateForced, uint8_t *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_Rp_Alignment_M2D_Data_De_Alignment_M2D_Data, void *);

   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_Pp_MMIC_Count_De_MMIC_Count, uint8_t);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_Pp_MMIC_Temperature_De_MMIC_Temperature, const Idt_Type_MMIC_Temperature *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_Pp_Radar_Init_Status_De_Radar_Init_Status, uint8_t);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_Pp_Diag_MMIC_ErrorFlags_De_MMIC_ErrorFlags, const Dt_MMIC_ErrorFlags *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_Pp_RadarCoreStatus_De_RadarCoreStatus, const Dt_RadarCoreStatus *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_Pp_Radar_CMD_Radiate_De_Radar_CMD_Radiate, uint8_t);

   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_CS_Disable_Wdg_Supervised_Entites_Operation, uint8_t);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_ADC_Populate_ADC_Stream);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_Debug_Populate_Debug_Stream);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_Detection_Populate_Detection_Stream);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_Header_Populate_Header_Stream);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_MMIC_Populate_MMIC_Stream);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_RDD_Populate_RDD_Stream);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_Status_Populate_Status_Stream);

   /* NVM-related RTE interfaces */
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_Rp_RFE_NvM_Data_De_RFE_NvM_Data, void *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_Pp_RFE_NvM_Data_De_RFE_NvM_Data, const void *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_CS_Radar_Control_Rfe_R1R2_NvM_Write_NvHandler_Trigger_Write_To_NVM, uint8_t,
                           uint8_t);

   DECLARE_FAKE_VOID_FUNC(Rte_Trigger_SWC_PLT_CDD_ECUSync_Pp_Radar_Ctl_Look_Complete_Trigger);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_CAN_Tx_RE_Communication_Tx);
   DECLARE_FAKE_VALUE_FUNC(int16_t, Get_MMIC_Temp_Tx0);
   DECLARE_FAKE_VALUE_FUNC(int16_t, Get_MMIC_Temp_Tx1);
   DECLARE_FAKE_VALUE_FUNC(int16_t, Get_MMIC_Temp_Tx2);
   DECLARE_FAKE_VALUE_FUNC(int16_t, Get_MMIC_Temp_Tx3);
   DECLARE_FAKE_VALUE_FUNC(int16_t, Get_MMIC_Temp_Rx0);
   DECLARE_FAKE_VALUE_FUNC(int16_t, Get_MMIC_Temp_PVT);
   DECLARE_FAKE_VALUE_FUNC(int16_t, Get_MMIC_Temp_QUAD);
   DECLARE_FAKE_VALUE_FUNC(int16_t, Get_MMIC_Temp_PVT_TSENS);
   DECLARE_FAKE_VALUE_FUNC(Radar_Ctl_State_T, Get_Radar_Ctl_State);

   /*===========================================================================*
    * Radar Control Mock Function Declarations
    *===========================================================================*/
   DECLARE_FAKE_VOID_FUNC(Put_Radar_Radiate_Enable, bool);
   DECLARE_FAKE_VALUE_FUNC(bool, Get_Radar_Radiate_Enable);
   DECLARE_FAKE_VOID_FUNC(Radar_Ctl_Reset_Init);
   DECLARE_FAKE_VOID_FUNC(Radar_Ctl_Look_Complete);
   DECLARE_FAKE_VOID_FUNC(Radar_Ctl_Look_Trigger);
   DECLARE_FAKE_VOID_FUNC(Radar_Ctl_Periodic);
   DECLARE_FAKE_VALUE_FUNC(bool, Get_RDI_Log_Board_Connected);

   /*===========================================================================*
    * MMIC Mock Function Declarations
    *===========================================================================*/
   DECLARE_FAKE_VOID_FUNC(MMIC_Reset_MIPI);
   DECLARE_FAKE_VOID_FUNC(MIPI_Disable);
   DECLARE_FAKE_VALUE_FUNC(bool, Run_DSP_Interaction_State_Machine);
   DECLARE_FAKE_VOID_FUNC(MMIC_Config_MIPI, bool);
   DECLARE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_Transceiver_Calib_Trigger);
   DECLARE_FAKE_VOID_FUNC(Put_Mmic_Bist_Calib_Trigger_Mode, bool);
   DECLARE_FAKE_VALUE_FUNC(bool, Get_MMIC_High_Temperature_Fault);
   DECLARE_FAKE_VALUE_FUNC(bool, Get_MMIC_Low_Temperature_Fault);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_MIPI_Fault);
   DECLARE_FAKE_VALUE_FUNC(bool, Get_MMIC_Faulted);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_MMIC_Daq_Over_Flow_Err);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_MMIC_System_Start_Fault);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_MMIC_Sensor_Dead_Fault);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_MMIC_API_Look_Config_Fault);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_MMIC_API_Look_Trigger_Fault);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_MMIC_API_Look_Complete_Fault);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_MMIC_Secondary_Fault, uint8_t);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_Tx_Rfbist_Fault);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_Rx_Rfbist_Fault);

   DECLARE_FAKE_VOID_FUNC(Put_MMIC_CW_Mode_Flag, uint8_t);
   DECLARE_FAKE_VOID_FUNC(Put_MMIC_Phase_Rotator_Calib_Flag, uint8_t);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_Tx_Id_Fault);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_MMIC_API_Fault, uint8_t);

   /*===========================================================================*
    * MIPI Mock Function Declarations
    *===========================================================================*/
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Deassert_Reset_Mipi);
   DECLARE_FAKE_VALUE_FUNC(bool, MIPI_Enable);
   DECLARE_FAKE_VALUE_FUNC(bool, MIPI_Debugmode_Enable);

   /*===========================================================================*
    * OS Alarm Mock Function Declarations
    *===========================================================================*/
   DECLARE_FAKE_VALUE_FUNC(StatusType, CancelAlarm, AlarmType);
   DECLARE_FAKE_VALUE_FUNC(StatusType, SetRelAlarm, AlarmType, TickType, TickType);

/*===========================================================================*
 * DSP Mock Function Declarations
 *===========================================================================*/
/* No additional DSP functions needed beyond those already declared */

/*===========================================================================*
 * UART Mock Function Declarations (for RESI mode)
 *===========================================================================*/
#if RESI_MODE_ENABLE
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, Uart_SendData, const char *, uint32_t, uint32_t);
   DECLARE_FAKE_VOID_FUNC(Initialize_Frame_Start_Output_Gpio);
   DECLARE_FAKE_VOID_FUNC(Trigger_Frame_Start_To_Resi);
   DECLARE_FAKE_VOID_FUNC(RESI_Mode_Put_Next_Look);
#endif

/*===========================================================================*
 * Test Stub Function Declarations
 *===========================================================================*/
#if ((ENABLE_SQT_TEST_STUBS == STD_ON) || (ENABLE_SIT_TEST_STUBS == STD_ON))
   DECLARE_FAKE_VOID_FUNC(Test_MMIC_Error_Flags_Set, Dt_MMIC_ErrorFlags *);
#endif

   /*===========================================================================*
    * External Variables (defined in radar_ctl.c)
    *===========================================================================*/
   extern int32_t Offline_Data_Mode_Enabled_Counter;
   extern bool Stream_Handler_Init_Flag;

#ifdef __cplusplus
}
#endif

#endif /* SWC_PLT_CDD_RADAR_CONTROL_FAKE_H */
