/*===========================================================================*/
/**
 * @file SWC_PLT_CDD_Radar_Control_fake.cc
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
 * Fake/Mock implementation file for SWC_PLT_CDD_Radar_Control unit testing
 * This file defines all fake function implementations using FFF
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 */
/*==========================================================================*/

#include "SWC_PLT_CDD_Radar_Control_fake.h"

/*===========================================================================*
 * External Variable Definitions
 *===========================================================================*/
/* Define the test-global Radar_Ctl_Data instance declared in the header */
Radar_Ctl_Data_T Radar_Ctl_Data              = {RADAR_CTL_INIT_NOT_STARTED, false};
Radar_Ctl_State_T Radar_Ctl_State            = RADAR_CTL_OFF;
MMIC_Stream_T MMIC_Stream                    = {0}; // Initialize all fields to zero
static FuSa_Faults_Union_T fusa_backup_fault = {0};

FuSa_Faults_Union_T *Get_Mmic_Fusa_Backup_Fault_Ptr(void)
{
   return &fusa_backup_fault;
}

int32_t Offline_Data_Mode_Enabled_Counter = 0;
bool Stream_Handler_Init_Flag             = false;
uint32_t Timestamp_Seconds                = 0;
bool isTriggeredOnce                      = false;
bool Is_Triggered_Once                    = false;
ITF_Mode_T Offline_Mode_Flag              = ITF_NORMAL_MODE;
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_Rp_XCP_CW_Mode_De_XCP_CW_Mode, uint8_t *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_Rp_XCP_Phase_Rotator_Calibration_De_XCP_Phase_Rotator_Calibration, uint8_t *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_Rp_XCP_Op_Mode_De_XCP_Op_Mode, Idt_XCP_Op_Mode_T *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_Rp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable, Idt_XCP_Single_Look_T *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_Rp_XCP_RFBIST_Calib_Trigger_De_XCP_RFBIST_Calib_Trigger, uint8_t *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_Rp_Command_Radiate_Final_De_CommandRadiate_Final, uint8_t *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_Rp_IsRadiateForced_De_IsRadiateForced, uint8_t *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_Rp_Alignment_M2D_Data_De_Alignment_M2D_Data, void *);

DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_Pp_MMIC_Count_De_MMIC_Count, uint8_t);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_Pp_MMIC_Temperature_De_MMIC_Temperature, const Idt_Type_MMIC_Temperature *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_Pp_Radar_Init_Status_De_Radar_Init_Status, uint8_t);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_Pp_Diag_MMIC_ErrorFlags_De_MMIC_ErrorFlags, const Dt_MMIC_ErrorFlags *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_Pp_RadarCoreStatus_De_RadarCoreStatus, const Dt_RadarCoreStatus *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_Pp_Radar_CMD_Radiate_De_Radar_CMD_Radiate, uint8_t);

DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_CS_Disable_Wdg_Supervised_Entites_Operation, uint8_t);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_ADC_Populate_ADC_Stream);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_Debug_Populate_Debug_Stream);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_Detection_Populate_Detection_Stream);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_Header_Populate_Header_Stream);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_MMIC_Populate_MMIC_Stream);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_RDD_Populate_RDD_Stream);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_Status_Populate_Status_Stream);

/* NVM-related RTE fake function definitions */
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Read_Rp_RFE_NvM_Data_De_RFE_NvM_Data, void *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Write_Pp_RFE_NvM_Data_De_RFE_NvM_Data, const void *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_CS_Radar_Control_Rfe_R1R2_NvM_Write_NvHandler_Trigger_Write_To_NVM, uint8_t,
                       uint8_t);

DEFINE_FAKE_VOID_FUNC(Rte_Trigger_SWC_PLT_CDD_ECUSync_Pp_Radar_Ctl_Look_Complete_Trigger);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Rte_Call_PostRadarProcessing_CAN_Tx_RE_Communication_Tx);

/*===========================================================================*
 * Radar Control Fake Function Definitions
 *===========================================================================*/
DEFINE_FAKE_VOID_FUNC(Put_Radar_Radiate_Enable, bool);
DEFINE_FAKE_VALUE_FUNC(bool, Get_Radar_Radiate_Enable);
DEFINE_FAKE_VOID_FUNC(Radar_Ctl_Reset_Init);
DEFINE_FAKE_VOID_FUNC(Radar_Ctl_Look_Complete);
DEFINE_FAKE_VOID_FUNC(Radar_Ctl_Look_Trigger);
DEFINE_FAKE_VOID_FUNC(Radar_Ctl_Periodic);
DEFINE_FAKE_VALUE_FUNC(bool, Get_RDI_Log_Board_Connected);

/*============================================================================*
 * MMIC Fake Function Definitions
 *===========================================================================*/
DEFINE_FAKE_VOID_FUNC(MMIC_Reset_MIPI);
DEFINE_FAKE_VOID_FUNC(MIPI_Disable);
DEFINE_FAKE_VALUE_FUNC(bool, Run_DSP_Interaction_State_Machine);
DEFINE_FAKE_VOID_FUNC(MMIC_Config_MIPI, bool);
DEFINE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_Transceiver_Calib_Trigger);
DEFINE_FAKE_VOID_FUNC(Put_Mmic_Bist_Calib_Trigger_Mode, bool);
DEFINE_FAKE_VALUE_FUNC(bool, Get_MMIC_High_Temperature_Fault);
DEFINE_FAKE_VALUE_FUNC(bool, Get_MMIC_Low_Temperature_Fault);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_MIPI_Fault);
DEFINE_FAKE_VALUE_FUNC(bool, Get_MMIC_Faulted);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_MMIC_Daq_Over_Flow_Err);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_MMIC_System_Start_Fault);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_MMIC_Sensor_Dead_Fault);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_MMIC_API_Look_Config_Fault);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_MMIC_API_Look_Trigger_Fault);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_MMIC_API_Look_Complete_Fault);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_MMIC_Secondary_Fault, uint8_t);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_Tx_Rfbist_Fault);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_Rx_Rfbist_Fault);

DEFINE_FAKE_VOID_FUNC(Put_MMIC_CW_Mode_Flag, uint8_t);
DEFINE_FAKE_VOID_FUNC(Put_MMIC_Phase_Rotator_Calib_Flag, uint8_t);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_Tx_Id_Fault);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_MMIC_API_Fault, uint8_t);
DEFINE_FAKE_VALUE_FUNC(int16_t, Get_MMIC_Temp_Tx0);
DEFINE_FAKE_VALUE_FUNC(int16_t, Get_MMIC_Temp_Tx1);
DEFINE_FAKE_VALUE_FUNC(int16_t, Get_MMIC_Temp_Tx2);
DEFINE_FAKE_VALUE_FUNC(int16_t, Get_MMIC_Temp_Tx3);
DEFINE_FAKE_VALUE_FUNC(int16_t, Get_MMIC_Temp_Rx0);
DEFINE_FAKE_VALUE_FUNC(int16_t, Get_MMIC_Temp_PVT);
DEFINE_FAKE_VALUE_FUNC(int16_t, Get_MMIC_Temp_QUAD);
DEFINE_FAKE_VALUE_FUNC(int16_t, Get_MMIC_Temp_PVT_TSENS);
DEFINE_FAKE_VALUE_FUNC(Radar_Ctl_State_T, Get_Radar_Ctl_State);

/*===========================================================================*
 * MIPI Fake Function Definitions
 *===========================================================================*/
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Deassert_Reset_Mipi);
DEFINE_FAKE_VALUE_FUNC(bool, MIPI_Enable);
DEFINE_FAKE_VALUE_FUNC(bool, MIPI_Debugmode_Enable);

/*===========================================================================*
 * OS Alarm Fake Function Definitions
 *===========================================================================*/
DEFINE_FAKE_VALUE_FUNC(StatusType, CancelAlarm, AlarmType);
DEFINE_FAKE_VALUE_FUNC(StatusType, SetRelAlarm, AlarmType, TickType, TickType);

/*===========================================================================*
 * UART Fake Function Definitions (for RESI mode)
 *===========================================================================*/
#if RESI_MODE_ENABLE
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, Uart_SendData, const char *, uint32_t, uint32_t);
DEFINE_FAKE_VOID_FUNC(Initialize_Frame_Start_Output_Gpio);
DEFINE_FAKE_VOID_FUNC(Trigger_Frame_Start_To_Resi);
DEFINE_FAKE_VOID_FUNC(RESI_Mode_Put_Next_Look);
#endif

/*============================================================================*
 * Test Stub Fake Function Definitions
 *===========================================================================*/
#if ((ENABLE_SQT_TEST_STUBS == STD_ON) || (ENABLE_SIT_TEST_STUBS == STD_ON))
DEFINE_FAKE_VOID_FUNC(Test_MMIC_Error_Flags_Set, Dt_MMIC_ErrorFlags *);
#endif
