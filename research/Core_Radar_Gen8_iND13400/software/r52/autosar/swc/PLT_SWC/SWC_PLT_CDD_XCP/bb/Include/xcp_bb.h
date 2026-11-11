#ifndef XCP_BB_H /* { */
#define XCP_BB_H
/*===========================================================================*/
/**
 * @file xcp_bb.h
 *
 * XCP Building Block interface - function prototypes for initialization, periodic data
 * refresh, command handling, and parameter getter functions.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (c) 2020 Aptiv. All rights reserved.
 * Confidential - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *   Header file exposing the XCP Building Block API for the radar calibration protocol
 *   interface. Declares functions for one-time const pointer initialization
 *   (XCP_BB_Init_Const_Ptr), periodic dynamic data refresh (XCP_BB_Refresh_Dynamic_Data),
 *   periodic task execution (XCP_Periodic_Task), user command dispatching
 *   (XCP_User_Command), and getter function prototypes for all XCP input parameters
 *   supplied by the application layer.
 *
 * @section ABBR ABBREVIATIONS:
 *   - ADC  - Analog-to-Digital Converter
 *   - BB   - Building Block
 *   - CW   - Continuous Wave
 *   - DAQ  - Data Acquisition
 *   - DID  - Data Identifier
 *   - IPC  - Inter-Process Communication
 *   - MCU  - Microcontroller Unit
 *   - MMIC - Monolithic Microwave Integrated Circuit
 *   - NVM  - Non-Volatile Memory
 *   - RTE  - Runtime Environment
 *   - XCP  - Extended Calibration Protocol
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - <a href="https://spo.aptiv.com/sites/0307-eoses/globalregional/ESGW_4-2_PE-SWx_00-01-A02_EN.docx">
 *       ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]</a>
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/
#include "xcp_bb_types.h"

/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/

/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Exported Preprocessor #define MACROS
 *===========================================================================*/

/*===========================================================================*
 * Exported Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Exported Object Declarations
 *===========================================================================*/

/*===========================================================================*
 * Exported Function Prototypes
 *===========================================================================*/
void XCP_BB_Refresh_Dynamic_Data(void);
void XCP_BB_Init_Const_Ptr(void);
uint8_t XCP_Periodic_Task(uint8_t *response, uint8_t *framelength);
uint8_t XCP_User_Command(const uint8_t *cmnd, uint8_t *response, uint8_t *framelength);
uint8_t Get_XCP_Radar_Radiate_Cmd(void);
XCP_Copy_Trgt_Rprts_fptr_T Get_XCP_Copy_Target_Report_Fptr(void);
uint8_t Get_XCP_Current_Look(void);
XCP_Look_Enable_Status_fptr_T Get_XCP_Look_Enable_Status_Fptr(void);
uint16_t Get_XCP_num_max_dets(void);
void *Get_XCP_Daq_Info_Ptr(void);
volatile uint8_t *Get_XCP_Force_Radiate_Ptr(void);
volatile uint8_t *Get_XCP_MMIC_A_ChipID(void);
uint8_t Get_XCP_MMIC_ChipID_Length(void);
uint8_t *Get_XCP_CW_Mode_Ptr(void);
volatile XCP_Single_Look_T *Get_XCP_Single_Look_Mode(void);
uint8_t Get_XCP_Num_Analog_Inputs(void);
volatile uint16_t *Get_XCP_Raw_ADC_Data(void);
uint8_t *Get_XCP_ADC_Validity_Flag_Ptr(void);
uint8_t *Get_XCP_ADC_Trigger_Ptr(void);
void *Get_XCP_Raw_ADC_Filitered_Data(void);
volatile int16_t *Get_XCP_Tx_Temperature_Data(void);
uint8_t Get_XCP_Num_Tx_Sensors(void);
volatile float32_t *Get_XCP_MCU_Temperature_Data(void);
uint8_t Get_XCP_Num_MCU_Sensors(void);
uint8_t *Get_XCP_Operation_Mode_Ptr(void);
uint8_t Get_XCP_Radar_Radiate_Cmd(void);
uint8_t Get_XCP_Radar_Init_Status(void);
XCP_Inject_Fault_T *Get_XCP_Inject_Fault_Data(void);
uint8_t *Get_XCP_Read_Hardware_Version(void);
volatile uint8_t *Get_XCP_Clear_Faults_Ptr(void);
uint8_t *Get_XCP_ITV_ADC_State(void);
uint8_t Get_XCP_num_ambig_per_det(void);
volatile uint8_t *Get_XCP_MCU_ID_Ptr(void);
volatile uint8_t *Get_XCP_Unique_ID_Ptr(void);
volatile uint8_t *Get_XCP_MMIC_B_ChipID(void);
/* Get sw version function prototypes*/
uint8_t **Get_XCP_Software_Version(void);
/* customer specific sw version function prototypes*/
uint8_t **Get_XCP_Cust_SW_Version(void);
uint8_t Get_XCP_Customer_ID(void);
uint8_t Get_XCP_En_Cust_Sw_Len(void);
volatile XCP_Fault_Override_T *Get_XCP_Memory_Fault_Override(void);
uint8_t Get_XCP_Num_Fault_Bytes(void);
uint8_t Get_XCP_Num_Of_Looks(void);
uint8_t Get_XCP_Target_Selection_Num(void);
uint16_t Get_XCP_Max_Num_Of_Range_Bin(void);
volatile uint16_t *Get_XCP_Target_Range_Index(void);
volatile uint16_t *Get_XCP_Target_Doppler_Index(void);
uint16_t Get_XCP_Max_Num_Of_Doppler_Bin(void);
volatile uint8_t *Get_XCP_Target_Select_Enable(void);
volatile uint8_t *Get_XCP_NVM_Ptr(void);
volatile uint8_t *Get_XCP_NVM_Previous_Operation_Status(void);
XCP_LED_Output_Cntrl_T *Get_XCP_LED_Output_State(void);
volatile uint16_t *Get_XCP_Write_Override_Var(void);
volatile uint16_t *Get_XCP_Read_Override_Var(void);
uint8_t **Get_XCP_Write_Align_Memory_Ptr(void);
XCP_Write_Alignment_T *Get_XCP_Write_Align_Data_Ptr(void);
uint8_t **Get_XCP_Read_Align_Memory_Ptr(void);
volatile uint8_t *Get_XCP_History_Table_Ptr(void);
volatile uint8_t *Get_XCP_Active_Table_Ptr(void);
volatile uint8_t *Get_XCP_Active_Latched_Table_Ptr(void);
volatile uint8_t *Get_XCP_Fault_Test_Completed(void);
uint8_t Get_XCP_Num_Cust_Spec_Checksum(void);
uint8_t **Get_XCP_Cust_Checksum(void);
uint8_t **Get_XCP_Software_Checksum(void);
uint8_t *Get_XCP_DID_CMD_Recvd_Ptr(void);
void *Get_XCP_In_DID_ptr(void);
void *Get_XCP_Out_DID(void);
uint8_t **Get_XCP_Stop_Periodic_Message_Ptr(void);
Xcp_Phase_Rotator_fptr_T Get_XCP_Phase_Rotator_Fptr(void);
uint8_t *Get_XCP_Transceiver_Calib_Trigger(void);
uint8_t Get_XCP_Rfbist_Calib_Status(void);
xcp_rfbist_debugdata_ptr Get_XCP_Rfbist_Debug_Data_ptr(void);

#if COMMENTED
extern uint8_t *Get_XCP_HIL_Mode_Ptr(void);
extern volatile uint16_t *Get_XCP_Raw_ADC_Data(void);

extern uint8_t SWC_XCP_Get_Look_En_Status(uint8_t look);
extern uint8_t *Get_XCP_Chksum_Trigger_Ptr(void);
extern uint8_t Get_XCP_Chksum_Trigger_Mode(void);

extern uint8_t *Get_Flash_checksum_Status(void);
extern uint8_t *Get_XCP_Itv_IPC_State(void);
extern uint8_t *Get_XCP_Itv_IPC_Event_State(void);
extern uint8_t *Get_XCP_Itv_IPC_Value_State(void);
extern uint8_t **Get_XCP_Interface_Enable_Ptr(void);
extern uint8_t **Get_XCP_Tx_Rx_Gain_Phase_Data(void);
extern XCP_Electronic_Chip_Id_fptr_T Get_XCP_Read_Electrnoic_Chip_Interface(void);
extern uint8_t *Get_XCP_Read_Electronic_Chip_Id(uint8_t interface_id);
extern uint8_t Get_XCP_Num_Electronic_Chip(void);
extern volatile uint8_t *Get_XCP_Mmic2_Sw_Api_Id(void);
extern volatile uint8_t *Get_XCP_Mmic2_Mipi_Status_Fault_Counters(void);
extern volatile uint8_t *Get_XCP_Mmic2_Osm_Fault_Counters(void);
extern volatile uint8_t *Get_XCP_Mmic2_Persistant_Osm_Status(void);
extern volatile uint8_t *Get_XCP_Mmic2_Persistant_Ism_Status(void);
extern volatile uint8_t *Get_XCP_Mmic2_Init_Status(void);
extern volatile uint8_t *Get_XCP_Mmic1_Sw_Api_Id(void);
extern volatile uint8_t *Get_XCP_Mmic1_Mipi_Status_Fault_Counters(void);
extern volatile uint8_t *Get_XCP_Mmic1_Osm_Fault_Counters(void);
extern volatile uint8_t *Get_XCP_Mmic1_Persistant_Osm_Status(void);
extern volatile uint8_t *Get_XCP_Mmic1_Persistant_Ism_Status(void);
extern volatile uint8_t *Get_XCP_Mmic1_Init_Status(void);
extern volatile uint32_t *Get_XCP_App_checksum(void);
extern volatile uint32_t *Get_XCP_primary_btld_checksum(void);
extern volatile uint32_t *Get_XCP_USC_checksum(void);
extern volatile uint32_t *Get_XCP_SMC_checksum(void);
extern volatile uint32_t *Get_XCP_Keep_alive_checksum(void);
extern volatile uint32_t *Get_XCP_cust_specific_checksum(void);

/*customer specific checksum function  function prototypes*/
uint8_t **Get_XCP_Cust_Checksum(void);
/*  sw checksum function prototypes*/

extern volatile uint16_t *Get_XCP_Write_Override_Var(void);
extern volatile uint16_t *Get_XCP_Read_Override_Var(void);

extern uint8_t *Get_XCP_JTAG_PWD_Status(void);
extern uint8_t *Get_XCP_JTAG_PWD_fptr(void);
extern uint8_t *Get_XCP_JTAG_Completed_State(void);
extern XCP_UPDATE_LC_T Get_XCP_Lifecycle_RRU_fptr(void);
extern XCP_UPDATE_LC_T Get_XCP_Lifecycle_RRM_fptr(void);
extern uint8_t *Get_XCP_LC_Updation_fptr(void);
extern uint8_t *Get_XCP_LifeCycle_Read_Data(void);
extern XCP_DSP_Data_Tag_T *Get_XCP_DSP_Simulation_Data(void);
extern uint8_t *Get_DSP_coefficient_parameter(void);
extern bool Get_DSP_Simulation_Enable(void);
extern bool Get_DSP_Simulation_Dynamic_Det_Enable(void);
extern bool Get_DSP_Simulation_Static_Det_Enable(void);
extern uint8_t Get_DSP_User_Num_Detection(void);
extern uint8_t Get_DSP_Det_Test_Case(void);
extern uint16_t Get_Fixed_arc_shaped_targets(void);
extern uint8_t *Get_XCP_Jtag_Pwd_Read_Cmd(void);
extern XCP_JTAG_PWD_T *Get_XCP_Jtag_Pwd_Read_Data(void);
#endif

/*===========================================================================*
 * Exported Inline Function Definitions and #define Function-Like Macros
 *===========================================================================*/

/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 * Date        userid    jira   (Description on following lines: SCR #, etc.)
 * ----------- --------
 * 10-Aug-2024 alkjpl   DNP-3434: Bringing Inital commands to  Gen 8.
 * ===========================================================================*/
/** @} doxygen end group */
#endif /* } XCP_BB_H */
