#ifndef MMIC_INTERFACE_H
   #define MMIC_INTERFACE_H
   /*===========================================================================*\
    * FILE: mmic_interface.h
    *===========================================================================
    * Copyright (C) 2024 APTIV, All Rights Reserved.
    * APTIV Confidential
    *---------------------------------------------------------------------------
    *
    * DESCRIPTION:
    * This file contains interfaces for initializing, updating and triggering
    * the mmic device drivers.
    *
    * ABBREVIATIONS:
    *
    *
    * TRACEABILITY INFO:
    *   Design Document(s):
    *
    *
    *   Requirements Document(s):
    *
    *
    *   Applicable Standards (in order of precedence: highest first):
    *   1. C Coding Standards SW REF 264.15D
    *
    * DEVIATIONS FROM STANDARDS:
    *
    *
   \*===========================================================================*/
   /*===========================================================================*\
    * Preprocessor #include directive(s) for standard header files
   \*===========================================================================*/
   #include "reuse.h"

   /*===========================================================================*\
    * Preprocessor #include directive(s) for other header files
   \*===========================================================================*/
   /* ToDo: Include when Radar Ctl module is available */
   // #include "radar_data.h"
   // #include "smc_cal.h"
   #include "crc_calc.h"
   #include "mmic_common_types.h"
   #include "mmic_stream.h"
   #include "radar_look_types.h"
   /*===========================================================================*\
    * Exported preprocessor #define constants (object-like macros)
   \*===========================================================================*/
   #define MMIC_FAIL    (false)
   #define MMIC_SUCCESS (true)

   /*MMIC Data Acq Over or Under flow Error Threhold value*/
   #define MMIC_DAQ_OVER_FLOW_ERR_THRESH    (0x6U)
   #define MMIC_SENSOR_DEAD_FAULT_THRESHOLD (6U)
   #define API_ERROR_THRESHOLD              (3U)
   #define MARS_RESET_MECHANISM_ENABLED     /*ToDo: Disable this when the reset mechanism is clearly defined*/

/*===========================================================================*\
 * Exported preprocessor #define macros (i.e. those using # or ## operator)
\*===========================================================================*/

/*===========================================================================*\
 * Exported type declarations (enum, struct, union, typedef)
\*===========================================================================*/
typedef bool MMIC_Result_T;

typedef struct MMIC_Config_Tag
{
   uint16_t num_chirps;
   uint16_t num_samples;
} MMIC_Config_T;

typedef struct MMIC_SFT_ERR_MON
{
   uint8_t BOR_Power_error:2;
   uint8_t Reference_PLL_lock:2;
   uint8_t MCU_error:2;
   uint8_t Synthesizer_error:2;
   uint8_t Rx_ADC:2;
   uint8_t Frame_unit_error:2;
   uint8_t Async_unit_error:2;
   uint8_t Profiler_unit_error:2;
   uint8_t Enable_unit_error:2;
   uint8_t ADC_Sys_PLL_lock:2;
   uint8_t MCU_subsystem_error:2;
   uint8_t MIPI_error:2;
   uint8_t SSI_error:2;
   uint8_t Reference_PLL:2;
   uint8_t Safety_Unit:2;
   uint8_t Safety_Error:2;
} MMIC_SFT_ERR_MON;
typedef enum API_Fault_Type_Tag
{
   API_FAULT_LOOK_CONFIG,
   API_FAULT_LOOK_TRIGGER,
   API_FAULT_LOOK_COMPLETE,
   MAX_API_FAULT_TYPE
} API_Fault_Type_T;
/*===========================================================================*\
 * Exported object declarations
\*===========================================================================*/
extern MMIC_Config_T *MMIC_Config_Ptr;
extern uint8_t MMIC_XCP_Enable_CW_Mode;
extern volatile bool MMIC_Phase_Rotator_Calib_Mode;
extern IPC_MMIC_Radar_Data_Status_T Radar_Data_Status;
extern uint32_t Sensor_Dwell_Time_Duration_Ns;
/*===========================================================================*\
 * Exported function prototypes
\*===========================================================================*/
void MMIC_Reset_Init(void);
void MMIC_Config_Device(void);
void MMIC_Config_Look(void);
void MMIC_Look_Trigger(void);
void MMIC_Look_Complete(void);
   #ifdef MARS_RESET_MECHANISM_ENABLED
void MMIC_Reset_MARS(void);
   #endif
void Update_Radar_Data_Status(void);
void Update_Mmic_Discard_Error(void);
void MMIC_Reset_MIPI(void);
void MMIC_Config_MIPI(void);
uint8_t Get_MMIC_System_Start_Fault(void);
void Check_MMIC_DAQ_OverFlow_Time(Radar_Look_T look_var);
void Update_MMIC_Reinit_Request(uint8_t request_flag);
// static void Mmic_Daq_Cal_Min_Max_Time(void);
void MMIC_Reset_MARS(void);
void Validate_MMIC_Error_Reinit_Count(void);
extern void Rfe_Nvm_Read(MMIC_Data_Logging_T *MMIC_Data_Ptr);
uint8_t Get_MMIC_Low_Temperature_Fault(void);
uint8_t Get_MMIC_High_Temperature_Fault(void);
void Compute_M7_Rdr_Data_Sts_Payload_CRC(void);
   /*===========================================================================*\
    * Exported inline function definitions and #define function-like macros
   \*===========================================================================*/
   #define Get_MMIC_Config_Ptr() (MMIC_Config_Ptr)

   #define Put_MMIC_CW_Mode_Flag(value)             (MMIC_XCP_Enable_CW_Mode = value)
   #define Put_MMIC_Phase_Rotator_Calib_Flag(value) (MMIC_Phase_Rotator_Calib_Mode = value)
   #define Get_MMIC_Operation_Mode()                ((aptiv_operation_mode_smc == 1U) | (CODED_TRUE == MMIC_XCP_Enable_CW_Mode))
   #define CW_MODE_FLAG                             (Get_Radar_Ctl_State() == RADAR_CTL_PURE_CW)

   #define Get_MMIC_Cal_Valid()      (true)
   #define Get_MMIC_Temp_Tx0()       (MMIC_Temperature.temperature_data.tmp_tx0_sens)
   #define Get_MMIC_Temp_Tx1()       (MMIC_Temperature.temperature_data.tmp_tx1_sens)
   #define Get_MMIC_Temp_Tx2()       (MMIC_Temperature.temperature_data.tmp_tx2_sens)
   #define Get_MMIC_Temp_Tx3()       (MMIC_Temperature.temperature_data.tmp_tx3_sens)
   #define Get_MMIC_Temp_Rx0()       (MMIC_Temperature.temperature_data.tmp_rx0_sens)
   #define Get_MMIC_Temp_PVT()       (MMIC_Temperature.temperature_data.tmp_pvt_sens)
   #define Get_MMIC_Temp_QUAD()      (MMIC_Temperature.temperature_data.tmp_quad_sens)
   #define Get_MMIC_Temp_PVT_TSENS() (MMIC_Temperature.temperature_data.tmp_pvt_tsens)
#endif
/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 * Date        userid    (Description on following lines: SCR #, etc.)
 * ----------- --------
 * 10-Apr-2025 ftoobg   EPB-3607: [Gen8] [SWE3] Data discard for the RFE faults - Implementation
 * 21-Jul-2025 qjgws1   EPB-3944: Temporarily bring the mars reset mechanism from tiger team branch.
 * 22-Jul-2025 jjrfgz   EPB-3984: TICS Coding Standard Improvement
 * 29-Dec-2025 ftoobg   EPB-4264: [Gen8][SWE3]MARS safety: API return value handling
 * 11-Oct-2025 njsfs0   EPB-4224: [Gen8] MMIC DAQ Over Flow Fault Implementation
 * 20-Jan-2026 ftoobg   EPB-3952: [Gen8][SWE3] Implement Mars Safety: MMIC Safety Critical Errors Handling
 * 29-Jan-2026 ftoobg   EPB-4354: [GEN8][CRD][SWE3] Provide Timestamp for Start of Acquisition
 * 28-Jan-2026 ftoobg   EPB-4320: [GEN8] Temperature data over XCP.
 * 23-Feb-2026 ftoobg   EPB-4410: [Gen8][SWE6] Mars Safety: MMIC Safety Critical Errors Handling
 * 07-May-2026 djdgwr   EPB-4662: [Gen8] [SWE_3] [R6.0] -(F1 9B) Phase Rotator Calibration In Manufacturing -Implementation
 * 03-Jun-2026 djdgwr   EPB-4540: [Gen8][SWE3] [R6.0]-High and Low Temperature Fault Decode and mapped to the Active Fault Table.
 * 09-Jul-2026  ftoobg  EPB-4770 [Gen8] [R7][SWE3] Use Case: Thermal management and Fault Handling- New strategy (MARS)
 \*===========================================================================*/
