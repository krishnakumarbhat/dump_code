/**
 * @file xcp_bb_fake.h
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
#ifndef XCP_BB_FAKE_H_
#define XCP_BB_FAKE_H_

#include "fff.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "xcp_bb_types.h"

   DECLARE_FAKE_VALUE_FUNC(uint8_t, xcp_user_command, const uint8_t *, uint8_t *, uint8_t *);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Pending_Cmnd_Status);
   DECLARE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_Operation_Mode_Ptr);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Num_Fault_Bytes);
   DECLARE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_Force_Radiate_Ptr);
   DECLARE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_CW_Mode_Ptr);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Num_Analog_Inputs);
   DECLARE_FAKE_VALUE_FUNC(volatile uint16_t *, Get_XCP_Raw_ADC_Data);
   DECLARE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_ADC_Validity_Flag_Ptr);
   DECLARE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_ADC_Trigger_Ptr);
   DECLARE_FAKE_VALUE_FUNC(volatile int16_t *, Get_XCP_Tx_Temperature_Data);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Num_Tx_Sensors);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Radar_Radiate_Cmd);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Radar_Init_Status);
   DECLARE_FAKE_VALUE_FUNC(volatile XCP_Single_Look_T *, Get_XCP_Single_Look_Mode);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, SWC_XCP_Get_Look_En_Status, uint8_t);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Num_Of_Looks);
   DECLARE_FAKE_VALUE_FUNC(XCP_Look_Enable_Status_fptr_T, Get_XCP_Look_Enable_Status_Fptr);
   DECLARE_FAKE_VALUE_FUNC(XCP_Copy_Trgt_Rprts_fptr_T, Get_XCP_Copy_Target_Report_Fptr);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Current_Look);
   DECLARE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_MCU_ID_Ptr);
   DECLARE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_Unique_ID_Ptr);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Target_Selection_Num);
   DECLARE_FAKE_VALUE_FUNC(uint16_t, Get_XCP_Max_Num_Of_Range_Bin);
   DECLARE_FAKE_VALUE_FUNC(volatile uint16_t *, Get_XCP_Target_Range_Index);
   DECLARE_FAKE_VALUE_FUNC(volatile uint16_t *, Get_XCP_Target_Doppler_Index);
   DECLARE_FAKE_VALUE_FUNC(uint16_t, Get_XCP_Max_Num_Of_Doppler_Bin);
   DECLARE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_ITV_ADC_State);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Num_MCU_Sensors);
   DECLARE_FAKE_VALUE_FUNC(void *, Get_XCP_Raw_ADC_Filitered_Data);
   DECLARE_FAKE_VALUE_FUNC(volatile float32_t *, Get_XCP_MCU_Temperature_Data);
   DECLARE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_Clear_Faults_Ptr);
   DECLARE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_Read_Hardware_Version);
   DECLARE_FAKE_VALUE_FUNC(uint16_t, Get_XCP_num_max_dets);
   DECLARE_FAKE_VALUE_FUNC(void *, Get_XCP_Daq_Info_Ptr);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_MMIC_ChipID_Length);
   DECLARE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_MMIC_A_ChipID);
   DECLARE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_MMIC_B_ChipID);
   /* Get sw version function prototypes*/
   DECLARE_FAKE_VALUE_FUNC(uint8_t **, Get_XCP_Software_Version);
   /* customer specific sw version function prototypes*/
   DECLARE_FAKE_VALUE_FUNC(uint8_t **, Get_XCP_Cust_SW_Version);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Customer_ID);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_En_Cust_Sw_Len);
   DECLARE_FAKE_VALUE_FUNC(volatile XCP_Fault_Override_T *, Get_XCP_Memory_Fault_Override);
   DECLARE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_Target_Select_Enable);
   DECLARE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_NVM_Ptr);
   DECLARE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_NVM_Previous_Operation_Status);
   DECLARE_FAKE_VALUE_FUNC(XCP_LED_Output_Cntrl_T *, Get_XCP_LED_Output_State);
   DECLARE_FAKE_VALUE_FUNC(volatile uint16_t *, Get_XCP_Write_Override_Var);
   DECLARE_FAKE_VALUE_FUNC(volatile uint16_t *, Get_XCP_Read_Override_Var);
   DECLARE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_ITV_IPC_State);
   /* Get sw version function prototypes*/
   DECLARE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_Transceiver_Calib_Trigger);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Rfbist_Calib_Status);

   DECLARE_FAKE_VALUE_FUNC(uint8_t **, Get_XCP_Write_Align_Memory_Ptr);
   DECLARE_FAKE_VALUE_FUNC(XCP_Write_Alignment_T *, Get_XCP_Write_Align_Data_Ptr);
   DECLARE_FAKE_VALUE_FUNC(uint8_t **, Get_XCP_Read_Align_Memory_Ptr);
   DECLARE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_History_Table_Ptr);
   DECLARE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_Active_Table_Ptr);
   DECLARE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_Active_Latched_Table_Ptr);
   DECLARE_FAKE_VALUE_FUNC(volatile uint8_t *, Get_XCP_Fault_Test_Completed);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Num_Cust_Spec_Checksum);
   DECLARE_FAKE_VALUE_FUNC(uint8_t **, Get_XCP_Software_Checksum);
   DECLARE_FAKE_VALUE_FUNC(uint8_t **, Get_XCP_Cust_Checksum);
   DECLARE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_DID_CMD_Recvd_Ptr);
   DECLARE_FAKE_VALUE_FUNC(void *, Get_XCP_In_DID_ptr);
   DECLARE_FAKE_VALUE_FUNC(void *, Get_XCP_Out_DID);
   DECLARE_FAKE_VALUE_FUNC(uint8_t **, Get_XCP_Stop_Periodic_Message_Ptr);
   DECLARE_FAKE_VALUE_FUNC(Xcp_Phase_Rotator_fptr_T, Get_XCP_Phase_Rotator_Fptr);
   DECLARE_FAKE_VALUE_FUNC(xcp_rfbist_debugdata_ptr, Get_XCP_Rfbist_Debug_Data_ptr);

#ifdef __cplusplus
}
#endif

/* Reset fake functions */
#define FFF_FAKES_XCP_BB_FUNCTION(FAKE)                                                                                           \
   FAKE(xcp_user_command)                                                                                                         \
   FAKE(Get_XCP_Pending_Cmnd_Status)                                                                                              \
   FAKE(Get_XCP_Operation_Mode_Ptr)                                                                                               \
   FAKE(Get_XCP_Clear_Faults_Ptr)                                                                                                 \
   FAKE(Get_XCP_Num_Fault_Bytes)                                                                                                  \
   FAKE(Get_XCP_Force_Radiate_Ptr)                                                                                                \
   FAKE(Get_XCP_CW_Mode_Ptr)                                                                                                      \
   FAKE(Get_XCP_Num_Analog_Inputs)                                                                                                \
   FAKE(Get_XCP_Raw_ADC_Data)                                                                                                     \
   FAKE(Get_XCP_ADC_Validity_Flag_Ptr)                                                                                            \
   FAKE(Get_XCP_ADC_Trigger_Ptr)                                                                                                  \
   FAKE(Get_XCP_Tx_Temperature_Data)                                                                                              \
   FAKE(Get_XCP_Num_Tx_Sensors)                                                                                                   \
   FAKE(Get_XCP_Radar_Radiate_Cmd)                                                                                                \
   FAKE(Get_XCP_Radar_Init_Status)                                                                                                \
   FAKE(Get_XCP_num_max_dets)                                                                                                     \
   FAKE(Get_XCP_num_ambig_per_det)                                                                                                \
   FAKE(Get_XCP_Single_Look_Mode)                                                                                                 \
   FAKE(SWC_XCP_Get_Look_En_Status)                                                                                               \
   FAKE(Get_XCP_Num_Of_Looks)                                                                                                     \
   FAKE(Get_XCP_Look_Enable_Status_Fptr)                                                                                          \
   FAKE(Get_XCP_Copy_Target_Report_Fptr)                                                                                          \
   FAKE(Get_XCP_Current_Look)                                                                                                     \
   FAKE(Get_XCP_MCU_ID_Ptr)                                                                                                       \
   FAKE(Get_XCP_Unique_ID_Ptr)                                                                                                    \
   FAKE(Get_XCP_Target_Selection_Num)                                                                                             \
   FAKE(Get_XCP_Max_Num_Of_Range_Bin)                                                                                             \
   FAKE(Get_XCP_Target_Range_Index)                                                                                               \
   FAKE(Get_XCP_Target_Doppler_Index)                                                                                             \
   FAKE(Get_XCP_Max_Num_Of_Doppler_Bin)                                                                                           \
   FAKE(Get_XCP_ITV_ADC_State)                                                                                                    \
   FAKE(Get_XCP_MCU_Temperature_Data)                                                                                             \
   FAKE(Get_XCP_Memory_Fault_Override)                                                                                            \
   FAKE(Get_XCP_Num_MCU_Sensors)                                                                                                  \
   FAKE(Get_XCP_Raw_ADC_Filitered_Data)                                                                                           \
   FAKE(Get_XCP_Read_Hardware_Version)                                                                                            \
   FAKE(Get_XCP_Transceiver_Calib_Trigger)                                                                                        \
   FAKE(Get_XCP_Rfbist_Calib_Status)                                                                                              \
   FAKE(Get_XCP_Read_Electrnoic_Chip_Interface)                                                                                   \
   FAKE(Get_XCP_Num_Electronic_Chip)                                                                                              \
   FAKE(Get_XCP_Lifecycle_COI_fptr)                                                                                               \
   FAKE(Get_XCP_Lifecycle_COIF_fptr)                                                                                              \
   FAKE(Get_XCP_LifeCycle_Read_Data)                                                                                              \
   FAKE(Get_XCP_MMIC_ChipID_Length)                                                                                               \
   FAKE(Get_XCP_MMIC_A_ChipID)                                                                                                    \
   FAKE(Get_XCP_MMIC_B_ChipID)                                                                                                    \
   FAKE(Get_XCP_LifeCycle_Staus)                                                                                                  \
   FAKE(Get_XCP_JTAG_PWD_fptr)                                                                                                    \
   FAKE(Get_XCP_JTAG_PWD_Read)                                                                                                    \
   FAKE(Get_XCP_Daq_Info_Ptr)                                                                                                     \
   FAKE(Get_XCP_Software_Version)                                                                                                 \
   FAKE(Get_XCP_Cust_SW_Version)                                                                                                  \
   FAKE(Get_XCP_Customer_ID)                                                                                                      \
   FAKE(Get_XCP_En_Cust_Sw_Len)                                                                                                   \
   FAKE(Get_XCP_MMIC_ChipID_Length)                                                                                               \
   FAKE(Get_XCP_Target_Select_Enable)                                                                                             \
   FAKE(Get_XCP_NVM_Ptr)                                                                                                          \
   FAKE(Get_XCP_NVM_Previous_Operation_Status)                                                                                    \
   FAKE(Get_XCP_Write_Override_Var)                                                                                               \
   FAKE(Get_XCP_Read_Override_Var)                                                                                                \
   FAKE(Get_XCP_LED_Output_State)                                                                                                 \
   FAKE(Get_XCP_Write_Align_Memory_Ptr)                                                                                           \
   FAKE(Get_XCP_Write_Align_Data_Ptr)                                                                                             \
   FAKE(Get_XCP_History_Table_Ptr)                                                                                                \
   FAKE(Get_XCP_Active_Table_Ptr)                                                                                                 \
   FAKE(Get_XCP_Active_Latched_Table_Ptr)                                                                                         \
   FAKE(Get_XCP_Fault_Test_Completed)                                                                                             \
   FAKE(Get_XCP_Read_Align_Memory_Ptr)                                                                                            \
   FAKE(Get_XCP_Software_Checksum)                                                                                                \
   FAKE(Get_XCP_Num_Cust_Spec_Checksum)                                                                                           \
   FAKE(Get_XCP_Cust_Checksum)                                                                                                    \
   FAKE(Get_XCP_Read_Align_Memory_Ptr)                                                                                            \
   FAKE(Get_XCP_DID_CMD_Recvd_Ptr)                                                                                                \
   FAKE(Get_XCP_In_DID_ptr)                                                                                                       \
   FAKE(Get_XCP_Stop_Periodic_Message_Ptr)                                                                                        \
   FAKE(Get_XCP_Out_DID)                                                                                                          \
   FAKE(Get_XCP_Phase_Rotator_Fptr)                                                                                               \
   FAKE(Get_XCP_Rfbist_Debug_Data_ptr)

#endif /*XCP_BB_FAKE_H_*/

#if 0
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_num_ambig_per_det);
   DECLARE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_Chksum_Trigger_Ptr);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Chksum_Trigger_Mode);
   DECLARE_FAKE_VALUE_FUNC(uint8_t *, Get_Flash_checksum_Status);
   DECLARE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_Itv_IPC_Event_State);
   DECLARE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_Itv_IPC_Value_State);
   DECLARE_FAKE_VALUE_FUNC(xcp_gain_phase_data_ptr, Get_XCP_tx_rx_Gain_Phase_fptr);
   DECLARE_FAKE_VALUE_FUNC(XCP_Electronic_Chip_Id_fptr_T, Get_XCP_Read_Electrnoic_Chip_Interface);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_Num_Electronic_Chip);
   DECLARE_FAKE_VALUE_FUNC(xcp_update_lifecycle_fptr, Get_XCP_Lifecycle_COI_fptr);
   DECLARE_FAKE_VALUE_FUNC(xcp_update_lifecycle_fptr, Get_XCP_Lifecycle_COIF_fptr);
   DECLARE_FAKE_VALUE_FUNC(uint8_t, Get_XCP_LifeCycle_Read_Data);
   DECLARE_FAKE_VALUE_FUNC(uint8_t *, Get_XCP_LifeCycle_Staus);
   DECLARE_FAKE_VALUE_FUNC(XCP_JTAG_PWD_T *, Get_XCP_JTAG_PWD_fptr);
   DECLARE_FAKE_VALUE_FUNC(XCP_JTAG_PWD_T *, Get_XCP_JTAG_PWD_Read);
   FAKE(Get_XCP_Chksum_Trigger_Ptr)                                                                                               \
   FAKE(Get_XCP_Chksum_Trigger_Mode)                                                                                              \                                                                                                \                                                                                              \
   FAKE(Get_Flash_checksum_Status)                                                                                                \
   FAKE(Get_XCP_Itv_IPC_State)                                                                                                    \
   FAKE(Get_XCP_Itv_IPC_Event_State)                                                                                              \
   FAKE(Get_XCP_Itv_IPC_Value_State)                                                                                              \                                                                                      \                                                                                                 \
   FAKE(Get_XCP_DID_CMD_Recvd_Ptr)                                                                                                \
   FAKE(Get_XCP_In_DID_ptr)                                                                                                       \
   FAKE(Get_XCP_Out_DID)

#endif
