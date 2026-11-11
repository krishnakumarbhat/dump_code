/**
 * @file xcp_bb_fake.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2022 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Mocks of the functions in xcp_bb.c file.
 *
 * @section ABBR ABBREVIATIONS:
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
#include "xcp_bb_fake.h"

DEFINE_FAKE_VALUE_FUNC(uint8_t, xcp_user_command, const uint8_t *, uint8_t *, uint8_t *);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Pending_Cmnd_Status);
DEFINE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_Operation_Mode_Ptr);
DEFINE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_Clear_Faults_Ptr);
DEFINE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_Force_Radiate_Ptr);
DEFINE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_CW_Mode_Ptr);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Num_Analog_Inputs);
DEFINE_FAKE_VALUE_FUNC(volatile uint16_t *, Get_XCP_Raw_ADC_Data);
DEFINE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_ADC_Validity_Flag_Ptr);
DEFINE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_ADC_Trigger_Ptr);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Radar_Radiate_Cmd);
DEFINE_FAKE_VALUE_FUNC(volatile XCP_Single_Look_T *, Get_XCP_Single_Look_Mode);
DEFINE_FAKE_VALUE_FUNC(uint8_t, SWC_XCP_Get_Look_En_Status, uint8_t);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Num_Of_Looks);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Radar_Init_Status);
DEFINE_FAKE_VALUE_FUNC(XCP_Look_Enable_Status_fptr_T, Get_XCP_Look_Enable_Status_Fptr);
DEFINE_FAKE_VALUE_FUNC(XCP_Copy_Trgt_Rprts_fptr_T, Get_XCP_Copy_Target_Report_Fptr);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Current_Look);
DEFINE_FAKE_VALUE_FUNC(volatile float32_t *, Get_XCP_MCU_Temperature_Data);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Num_MCU_Sensors);
DEFINE_FAKE_VALUE_FUNC(void *, Get_XCP_Raw_ADC_Filitered_Data);
DEFINE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_Read_Hardware_Version);
DEFINE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_ITV_ADC_State);
DEFINE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_MCU_ID_Ptr);
DEFINE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_Unique_ID_Ptr);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Num_Tx_Sensors);
DEFINE_FAKE_VALUE_FUNC(uint16_t, Get_XCP_num_max_dets);
DEFINE_FAKE_VALUE_FUNC(void *, Get_XCP_Daq_Info_Ptr);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_MMIC_ChipID_Length);
DEFINE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_MMIC_A_ChipID);
DEFINE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_MMIC_B_ChipID);
DEFINE_FAKE_VALUE_FUNC(volatile int16_t *, Get_XCP_Tx_Temperature_Data);
/* Get sw version function prototypes*/
DEFINE_FAKE_VALUE_FUNC(uint8_t **, Get_XCP_Software_Version);
/* customer specific sw version function prototypes*/
DEFINE_FAKE_VALUE_FUNC(uint8_t **, Get_XCP_Cust_SW_Version);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_En_Cust_Sw_Len);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Customer_ID);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Num_Fault_Bytes);
DEFINE_FAKE_VALUE_FUNC(volatile XCP_Fault_Override_T *, Get_XCP_Memory_Fault_Override);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Target_Selection_Num);
DEFINE_FAKE_VALUE_FUNC(uint16_t, Get_XCP_Max_Num_Of_Range_Bin);
DEFINE_FAKE_VALUE_FUNC(volatile uint16_t *, Get_XCP_Target_Range_Index);
DEFINE_FAKE_VALUE_FUNC(volatile uint16_t *, Get_XCP_Target_Doppler_Index);
DEFINE_FAKE_VALUE_FUNC(uint16_t, Get_XCP_Max_Num_Of_Doppler_Bin);
DEFINE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_Target_Select_Enable);
DEFINE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_NVM_Ptr);
DEFINE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_NVM_Previous_Operation_Status);
DEFINE_FAKE_VALUE_FUNC(XCP_LED_Output_Cntrl_T *, Get_XCP_LED_Output_State);
DEFINE_FAKE_VALUE_FUNC(volatile uint16_t *, Get_XCP_Write_Override_Var);
DEFINE_FAKE_VALUE_FUNC(volatile uint16_t *, Get_XCP_Read_Override_Var);
DEFINE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_Transceiver_Calib_Trigger);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Rfbist_Calib_Status);
DEFINE_FAKE_VALUE_FUNC(uint8_t **, Get_XCP_Write_Align_Memory_Ptr);
DEFINE_FAKE_VALUE_FUNC(XCP_Write_Alignment_T *, Get_XCP_Write_Align_Data_Ptr);
DEFINE_FAKE_VALUE_FUNC(uint8_t **, Get_XCP_Read_Align_Memory_Ptr);
DEFINE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_History_Table_Ptr);
DEFINE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_Active_Table_Ptr);
DEFINE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_Active_Latched_Table_Ptr);
DEFINE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_Fault_Test_Completed);
DEFINE_FAKE_VALUE_FUNC(uint8_t **, Get_XCP_Cust_Checksum);
DEFINE_FAKE_VALUE_FUNC(uint8_t **, Get_XCP_Software_Checksum);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Num_Cust_Spec_Checksum);
DEFINE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_DID_CMD_Recvd_Ptr);
DEFINE_FAKE_VALUE_FUNC(void *, Get_XCP_In_DID_ptr);
DEFINE_FAKE_VALUE_FUNC(void *, Get_XCP_Out_DID);
DEFINE_FAKE_VALUE_FUNC(uint8_t **, Get_XCP_Stop_Periodic_Message_Ptr);
DEFINE_FAKE_VALUE_FUNC(Xcp_Phase_Rotator_fptr_T, Get_XCP_Phase_Rotator_Fptr);
DEFINE_FAKE_VALUE_FUNC(xcp_rfbist_debugdata_ptr, Get_XCP_Rfbist_Debug_Data_ptr);

#if COMMENTED
DEFINE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_Itv_IPC_Event_State);
DEFINE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_Itv_IPC_Value_State);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_num_ambig_per_det);
DEFINE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_Chksum_Trigger_Ptr);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Chksum_Trigger_Mode);
DEFINE_FAKE_VALUE_FUNC(uint8_t *, Get_Flash_checksum_Status);
DEFINE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_Itv_IPC_State);
DEFINE_FAKE_VALUE_FUNC(xcp_gain_phase_data_ptr, Get_XCP_tx_rx_Gain_Phase_fptr);
DEFINE_FAKE_VALUE_FUNC(XCP_Electronic_Chip_Id_fptr_T, Get_XCP_Read_Electrnoic_Chip_Interface);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Num_Electronic_Chip);
DEFINE_FAKE_VALUE_FUNC(xcp_update_lifecycle_fptr, Get_XCP_Lifecycle_COI_fptr);
DEFINE_FAKE_VALUE_FUNC(xcp_update_lifecycle_fptr, Get_XCP_Lifecycle_COIF_fptr);
DEFINE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_LifeCycle_Read_Data);
DEFINE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_LifeCycle_Staus);
DEFINE_FAKE_VALUE_FUNC(XCP_JTAG_PWD_T *, Get_XCP_JTAG_PWD_fptr);
DEFINE_FAKE_VALUE_FUNC(XCP_JTAG_PWD_T *, Get_XCP_JTAG_PWD_Read);

#endif
