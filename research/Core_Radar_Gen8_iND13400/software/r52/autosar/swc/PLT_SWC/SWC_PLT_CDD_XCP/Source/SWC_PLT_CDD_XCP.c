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
 *             File:  SWC_PLT_CDD_XCP.c
 *           Config:  Gen8_iND13400.dpa
 *        SW-C Type:  SWC_PLT_CDD_XCP
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  C-Code implementation template for SW-C <SWC_PLT_CDD_XCP>
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
 * Dt_AlignmentModeIn_T
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Dt_ITV_EVENT
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Dt_ITV_VALUE
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Dt_Therm_Mon_Temp_Opt_T
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Dt_XCP_NvM_Control_T
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Dt_XCP_SIM_MODE
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Idt_XCP_Data_Flash_Process_T
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Idt_XCP_Op_Mode_T
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * XCP_Status_T
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_SWC_PLT_CDD_XCP.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "reuse.h"

#include "reuse.h"

#include "Fault_Lib_Plt.h"
#include "Fault_Lib_Prj.h"
#include "Fls.h"
#include "SWC_PLT_CDD_XCP.h"
#include "WdgM.h"
#include "Xcp.h"
#include "board_revision.h"
#include "boot_interface.h"
#include "dd_gpt.h"
#include "dd_mmic.h"
#include "dsp_setup.h"
#include "ipc_data.h"
#include "ipc_mss.h"
#include "radar_data.h"
#include "smc_cal.h"
#include "usc_cal.h"
#include "versions.h"
#include "xcp_bb.h"

#define XCP_CHIP_ID_LENGTH ((uint8_t)16U)

/* Single Look - F1 0B */
volatile XCP_Single_Look_T XCP_Single_Look_Mode = {CODED_FALSE, 0U};
/* Force Radar Radiate F1 02 */
static uint8_t XCP_Force_Radiate         = (uint8_t)XCP_FORCE_RADIATE_NORMAL_OPERATION;
static uint8_t *XCP_Chip_Id_MMIC_Version = NULL;
/* Cw mode F1 14 */
uint8_t XCP_CW_Mode = CODED_FALSE;
/* F1 01*/
static uint8_t xcp_operation_mode = XCP_OPCMD_NORMAL_MODE;

static Idt_Type_MMIC_Temperature XCP_Tx_Temp;
static DT_Thermal_Monitor_Temperatures_T XCP_Mcu_Temp;
static uint8_t XCP_Num_Tx_Sensors  = 1U;
static uint8_t XCP_Num_Mcu_Sensors = 0U;

/* ADC Data*/
static Dt_RawAdcData_T XCP_Raw_Adc_Data_UnFilt;
static Dt_RawAdcDataFilt_T XCP_Raw_Adc_Filtered_Data;
static uint8_t xcp_adc_validity_flag_status = CODED_FALSE;
static uint8_t xcp_adc_trigger_flag         = CODED_FALSE;
static uint8_t XCP_Analog_Inputs            = 24U;

/* Fault Injection varaibles F1 12 */
Dt_Fault_Injection xcp_dt_fault_injection;
static XCP_Inject_Fault_T xcp_inject_fault;

/* F1 0D */
static uint8_t xcp_read_hardware_version;

/* F1 04 */
static uint8_t xcp_clear_faults = CODED_FALSE;

/* F1 1F*/
static XCP_LED_Output_Cntrl_T XCP_Out_Output_State;
static Dt_XCP_Set_Output XCP_Set_Output;

/*Override ADC count and MCU Temp     F1 0F*/
static uint8_t XCP_Itv_ADC_State = 0U;

/*F1 97*/
static Dt_ID_data XCP_Mcu_ID;

/* F1 0C */
static Idt_Cal_Version_Info_Type XCP_Cal_Version;
static uint8 *xcp_sw_ver[XCP_MAX_SW_VER]            = {NULL};
static uint8_t XCP_En_Cust_Sw_Len                   = CODED_FALSE;
static uint8_t XCP_Customer_Id                      = 0x0;
static boolean previous_xcp_stop_msg_cmnd_requested = FALSE;
static boolean previous_xcp_stop_msg_cmnd_req_vcan  = FALSE;
static volatile Dt_XCP_NvM_Control_T xcp_nvm_status;
static Idt_XCP_Data_Flash_Process_T xcp_nvm_cmnd_status = XCP_NVM_STATUS_SUCCESS;

/* Variable which define the Action to override fault memory F1 11 */
static volatile XCP_Fault_Override_T XCP_FaultOverride = {XCP_AUTO_MODE, 0, 0};

/* F1 9A*/
uint16_t xcp_target_range_idx[NUM_LOOKS][XCP_NO_OF_TARGET_SELECTION];
uint16_t xcp_target_doppler_idx[NUM_LOOKS][XCP_NO_OF_TARGET_SELECTION];
uint8_t xcp_target_select_cmd;

/* DID F1 13 */
static Dt_Xcp_Read_Write_Did_T Xcp_Did_Read_Data;
static Dt_Xcp_Read_Write_Did_T Xcp_Did_Write_Data;
static uint8_t xcp_did_cmd_recvd = CODED_FALSE;

#if (ENABLE_SIT_TEST_STUBS == STD_ON)
volatile uint8 xcp_force_test         = 1;
volatile uint8 F1_12_interface_test   = 0;
volatile uint8 Injection_control_test = 0;
volatile uint8 Failure_Type_test      = 0;
#endif

/*F1 12 : Fake Fault Injection*/
/*Fault list for Mode Maanger -1 (MM1 ) Domain*/
static const XCP_Fault_Inj_Handler_T MM1_FaultHandlers[] = {XCP_MM1_FAULT_ENTRY_64};
/*Fault list for Mode Maanger -2 (MM2 ) Domain*/
static const XCP_Fault_Inj_Handler_T MM2_FaultHandlers[] = {{NULL, XCP_MM2_RESERVED_0, 0x00, 0x00, 0x00, 0x00}};
/*Fault list for Mode Maanger -3 (MM3) Domain*/
static const XCP_Fault_Inj_Handler_T MM3_FaultHandlers[] = {
   {CS_MCU_Safety_Fault_Injection, XCP_MM3_MCU_STARTUP_FAULT, 0x00, 0x00, 0x00, 0x01},      /*MCU Startup Failure Type :0*/
   {CS_MCU_Safety_Fault_Injection, XCP_MM3_REPETITIVE_RESET_FAULT, 0x01, 0x01, 0x00, 0x06}, /*Repetitive Resets Failute Type :1*/
   {CS_Signal_Integrity_Fault_Injection_Read, XCP_MM3_SIGNAL_INTIGRITY_FAULT, 0x02, 0x02, 0x00,
    0x01},                                                              /*Signal Intigrity Failute Type : 2*/
   {CS_IPC_Fault_Injection, XCP_MM3_IPC_FAULT, 0x03, 0x03, 0x00, 0x02}, /*IPC Fault Failure Type:3*/
   {CS_External_Watchdog_Fault_Injection_Read, XCP_MM3_PMIC_MCU_COMMUNICATION_FAULT, 0x04, 0x04, 0x00,
    0x03}, /*PMIC-MCU Communication Fault Type:4*/
   {CS_External_Watchdog_Fault_Injection_Read, XCP_MM3_EXT_WATCHDOG_FAULT, 0x05, 0x05, 0x00,
    0x01} /*External Watchdog Fault Type:5*/
};

/*Fault list for Mode Maanger -4 (MM4) Domain*/
static const XCP_Fault_Inj_Handler_T MM4_FaultHandlers[] = {
   {CS_WdgHandler_Fault_Injection_Read, XCP_MM4_WATCHDOG_FAULT, 0x00, 0x00, 0x00,
    0x03}, /*Watchdog(Internal and External) Handler Failure Type:0*/
   {NULL, XCP_MM4_RESERVED_1, 0x00, 0x00, 0x00, 0x00},
   {NULL, XCP_MM4_RESERVED_2, 0x00, 0x00, 0x00, 0x00},
   {NULL, XCP_MM4_RESERVED_3, 0x00, 0x00, 0x00, 0x00},
   {NULL, XCP_MM4_RESERVED_4, 0x00, 0x00, 0x00, 0x00},
   {CS_Modemanager_Fault_Injection_Read, XCP_MM4_OPRTN_TRANSITIONS_FAULT, 0x05, 0x05, 0x00,
    0x05}, /*Test OperationMode transitions (startup and shutdown transitions) :5*/
   {CS_Modemanager_Fault_Injection_Read, XCP_MM4_EXTERNAL_INTERFACES_FAULT, 0x06, 0x06, 0x00,
    0x06} /*Modify external interfaces from integrator :6*/
};

static const XCP_Fault_Inj_Handler_T RSV_FaultHandlers[] = {{NULL, XCP_RSV_RESERVED_0, 0x00, 0x00, 0x00, 0x00}};
static const XCP_Fault_Inj_Handler_T RC1_FaultHandlers[] = {
   {NULL, XCP_RC1_RESERVED_0, 0x00, 0x00, 0x00, 0x00},
   {NULL, XCP_RC1_RESERVED_1, 0x00, 0x00, 0x00, 0x00},
   {NULL, XCP_RC1_RESERVED_2, 0x00, 0x00, 0x00, 0x00},
   {CS_Radar_control_Fault_Injection_Read, XCP_RC1_SENSOR_DEAD_FAULT, 0x03, 0x03, 0x01, 0x01}, /*Sensor Dead Fault 0x03*/
   {CS_Radar_control_Fault_Injection_Read, XCP_RC1_SAFETY_INTIGRITY_FAULT, 0x04, 0x04, 0x01,
    0x02},                                                                                      /*Safety Integrity  Fault 0x04*/
   {CS_Radar_control_Fault_Injection_Read, XCP_RC1_SAFE_STARTUP_FAULT, 0x05, 0x05, 0x01, 0x01}, /*Safe Startup Fault 0x05*/
   {NULL, XCP_RC1_RESERVED_6, 0x00, 0x00, 0x00, 0x00},
   {CS_Radar_control_Fault_Injection_Read, XCP_RC1_MMIC_UNDER_TEMP_FAULT, 0x07, 0x07, 0x01,
    0x02}, /*MMIC Under Temperature Fault 0x07*/
   {CS_Radar_control_Fault_Injection_Read, XCP_RC1_MMIC_OVER_TEMP_FAULT, 0x08, 0x08, 0x01,
    0x02},                                                                                   /*MMIC Over Temperature Fault 0x08*/
   {CS_Radar_control_Fault_Injection_Read, XCP_RC1_MMIC_ID_FAULT, 0x09, 0x09, 0x01, 0x01},   /*MMIC ID Fault 0x09*/
   {CS_Radar_control_Fault_Injection_Read, XCP_RC1_LOOKINDEX_STALE, 0x0A, 0x0A, 0x01, 0x02}, /*LookIndex Stale Fault 0x0A*/
   {NULL, XCP_RC1_RESERVED_11, 0x00, 0x00, 0x00, 0x00},
   {CS_Radar_control_Fault_Injection_Read, XCP_RC1_DETECTION_PROCESSING_LOOP_OVERRUN_FAULT, 0x0C, 0x0C, 0x01,
    0x02}, /*Detection processing loop overrun Fault 0x0C*/
   {CS_Radar_control_Fault_Injection_Read, XCP_RC1_SMC_CHECKSUM_FAULT, 0x0D, 0x0D, 0x01, 0x01},   /*SMC Checksum Fault 0x0D*/
   {CS_Radar_control_Fault_Injection_Read, XCP_RC1_USC_VALIDATION_FAULT, 0x0E, 0x0E, 0x01, 0x01}, /*USC Validation Fault 0x0E*/
   {CS_Radar_control_Fault_Injection_Read, XCP_RC1_LOOPBACK_TEST_FAULT, 0x0F, 0x0F, 0x01, 0x02},  /*Loopback Fault 0x0F*/
   {CS_Radar_control_Fault_Injection_Read, XCP_RC1_FUNCTIONAL_CONFIGURATION_FAULT, 0x10, 0x10, 0x01,
    0x01} /*Functional Configuration Fault 0x10*/
};
static const XCP_Fault_Inj_Handler_T RC2_FaultHandlers[] = {
   {CS_Radar_control_Fault_Injection_Read, XCP_RC2_ACQUISITION_OVERFLOW_FAULT, 0x01, 0x01, 0x01, 0x03},
   /*Data Aquisition Fault 0*/                                                                    /*Acquisition Overflow Fault*/
   {CS_Radar_control_Fault_Injection_Read, XCP_RC2_MMIC_TEMP_SET_FAULT, 0x02, 0x02, 0x01, 0x03}}; /* MMIC temperature set Fault*/
static const XCP_Fault_Inj_Handler_T RC3_FaultHandlers[] = {{NULL, XCP_RC3_RESERVED_0, 0x00, 0x00, 0x00, 0x00}};
static const XCP_Fault_Inj_Handler_T RC4_FaultHandlers[] = {{NULL, XCP_RC4_RESERVED_0, 0x00, 0x00, 0x00, 0x00}};

static const XCP_Fault_Inj_Handler_T PT1_FaultHandlers[] = {
   {CS_PlatformTime_Fault_Injection, XCP_PT1_PLATFORM_TIME_FAULT, 0x00, 0x02, 0x00, 0x02}}; /* Platform Time Fault*/
/*Fault Domain Config table */

static const XCP_Fault_Injection_Config_Table_T Fault_Domain_Table[] = {
   XCP_FAULT_INJECTION_ELEMENT(MM1), /* Mode Manager 1 Sys Domain :0 */
   XCP_FAULT_INJECTION_ELEMENT(MM2), /* Mode Manager 2 Sys Domain :1 */
   XCP_FAULT_INJECTION_ELEMENT(MM3), /* Mode Manager 3 Sys Domain :2 */
   XCP_FAULT_INJECTION_ELEMENT(MM4), /* Mode Manager 4 Sys Domain :3 */
   XCP_FAULT_INJECTION_ELEMENT(RSV), /* RSV Sys Domain            :4 */
   XCP_FAULT_INJECTION_ELEMENT(RC1), /* RC1 Sys Domain            :5 */
   XCP_FAULT_INJECTION_ELEMENT(RC2), /* RC2 Sys Domain            :6 */
   XCP_FAULT_INJECTION_ELEMENT(RC3), /* RC3 Sys Domain            :7 */
   XCP_FAULT_INJECTION_ELEMENT(RC4), /* RC4 Sys Domain            :8 */
   XCP_FAULT_INJECTION_ELEMENT(PT1), /* PT1 Sys Domain            :9 */
};

/*F1 30 */
static XCP_Write_Alignment_T xcp_write_alignment = {CODED_FALSE, 0, 0, (uint8_t)XCP_WRITE_ALIGNMENT_IDLE, CODED_FALSE};
static uint8_t xcp_select_alignment_typedic_status;
static Dt_Write_Alignment_NvM_Data_T xcp_align_nvm_data;
static Xcp_Write_Alignment_NvM_Data_T xcp_align_nvm_temp_data;
static uint8_t *xcp_write_alignment_memory[2] = {(uint8_t *)&xcp_select_alignment_typedic_status,
                                                 (uint8_t *)&xcp_align_nvm_temp_data};
/*F1 31 */
static Dt_Write_Alignment_NvM_Data_T xcp_nvm_read_data;
static Dt_Initial_Alignment_Result_T xcp_read_align_intial_res;
static Dt_Initial_Alignment_Performance_Result_T xcp_read_align_perf_res;
static Dt_Auto_Alignment_Result_T xcp_read_auto_align_res;

static uint8_t AlignmentModeOut;
static Xcp_Write_Alignment_NvM_Data_T xcp_align_nvm_temp_read;
static Xcp_Initial_Alignment_Result_T xcp_align_init_read;
static Xcp_Auto_Alignment_Result_T_1 xcp_align_auto_read;
static Xcp_Auto_Alignment_Result_T_2 xcp_align_auto_read_2;
static uint8_t *xcp_Read_alignment_memory[6] = {(uint8_t *)&AlignmentModeOut,    (uint8_t *)&xcp_align_nvm_temp_read,
                                                (uint8_t *)&xcp_align_init_read, (uint8_t *)&xcp_read_align_perf_res,
                                                (uint8_t *)&xcp_align_auto_read, (uint8_t *)&xcp_align_auto_read_2};

/* F7/F8 XCP SEED Key*/
#define ReadSystemTimer() ((Gpt_ValueType)Gpt_GetTimeElapsed(GptConf_GptChannelConfiguration_StbM_Local_Timer_Ch))

/*F1 B0/C0/D0/E0*/
static Customer_fault_T *Xcp_Fault_Test_Completed_Table;
static Customer_fault_T *Xcp_Active_Fault_Latched_Table;
static Customer_fault_T *Xcp_Appl_Active_Fault_Table;
static Customer_fault_T *Xcp_History_Fault_Table;

/* Check sum*/
static uint8 *xcp_checksum[XCP_MAX_CHKSM] = {NULL};
static uint32_t XCP_Keep_Alive_Checksum;

/*usc/smc */
static uint8_t xcp_flash_wr_page_data[XCP_FLASH_PAGE_SIZE];
static uint16_t xcp_flash_wr_data_index          = 0;
static uint32_t xcp_flash_wr_page_addr           = 0x0;
static uint8_t XCP_Flash_Erase_Prgm_Cmd_Recevied = CODED_FALSE;
XCP_USC_SMC_Seq_T xcp_usc_smc_data;
static bool xcp_flash_wr_page_start = FALSE;

uint8_t xcp_trigger_rfbist_calibration = CODED_FALSE;
static uint8_t XCP_Rfbist_Calib_Status = XCP_RFBIST_CALIBRATION_INVALID;
/* Rfbist debug data*/
static XCP_RFBIST_Debug_Data_T xcp_rfbist_debug_data[XCP_RFBIST_DEBUG_CMD_SUPPORT] = {
   {NULL, 0U, 0U, 0U, 0U}, {NULL, 0U, 0U, 0U, 0U}, {NULL, 0U, 0U, 0U, 0U}, {NULL, 0U, 0U, 0U, 0U},
   {NULL, 0U, 0U, 0U, 0U}, {NULL, 0U, 0U, 0U, 0U}, {NULL, 0U, 0U, 0U, 0U}, {NULL, 0U, 0U, 0U, 0U},
   {NULL, 0U, 0U, 0U, 0U}, {NULL, 0U, 0U, 0U, 0U}, {NULL, 0U, 0U, 0U, 0U}};

/* Stop Periodic Msgs Interface Control */
static uint8_t xcp_normal_stop_periodic_status;
static uint8_t xcp_pcan_stop_periodic_status;
static uint8_t xcp_vcan_stop_periodic_status;
static uint8_t xcp_ethernet_platform_stop_periodic_status;
static uint8_t xcp_ethernet_project_stop_periodic_status;
static uint8_t *xcp_stop_periodic_message_interface[XCP_COMM_INTERFACES_MAX] = {
   &xcp_normal_stop_periodic_status, &xcp_pcan_stop_periodic_status, &xcp_vcan_stop_periodic_status,
   &xcp_ethernet_platform_stop_periodic_status, &xcp_ethernet_project_stop_periodic_status};

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
static FUNC(uint8, XCP_CODE) SWC_Xcp_UserCommand(Xcp_ChannelType XcpChannel, P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) Cmmd);
static void SWC_XCP_Update_Inject_Fault_Cmnd(void);
static Dt_ForceRadiate SWC_XCP_Update_Force_Radiate_Cmd(void);
/* Stop Periodic Msgs Interface Control */
static void SWC_XCP_Update_Normal_Stop_Periodic_Cmnd(void);
static void SWC_XCP_Update_PCAN_Stop_Periodic_Cmnd(void);
static void SWC_XCP_Update_VCAN_Stop_Periodic_Cmnd(void);
static void SWC_XCP_Update_Ethernet_Platform_Stop_Periodic_Cmnd(void);
static void SWC_XCP_Update_Ethernet_Project_Stop_Periodic_Cmnd(void);
static void SWC_XCP_Update_Clear_Faults_Cmnd(void);
static void SWC_XCP_Update_Fault_table(void);
volatile uint16_t *SWC_Get_XCP_Target_Doppler_Idx(void);
volatile uint16_t *SWC_Get_XCP_Target_Range_Idx(void);
volatile uint8_t *SWC_Get_XCP_Target_Select_Enable(void);
static void swc_xcp_copy_alignment_bufferto_nvm(void);
static void swc_xcp_copy_alignment_nvmto_buffer(void);
static void swc_xcp_copy_align_init_to_buffer(void);
static void swc_xcp_copy_align_auto_to_buffer(void);
static void SWC_XCP_Update_Write_Alignment(void);
static void SWC_XCP_Update_Write_DID(void);
static FUNC(void, XCP_CODE) SWC_Xcp_SendNegResp(Xcp_ChannelType XcpChannel, uint8 ErrorCode);
static FUNC(uint8_t, XCP_CODE) SWC_Xcp_Program_Access_Check(uint32_t address, uint32 size);
static uint8_t SWC_Xcp_Flash_sequence(void);
static void SWC_Read_XCP_Rfbist_Debug_Data(void);

/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Injection_Control: Integer in interval [0...255]
 * NCFF_Channel_Number: Integer in interval [0...255]
 * Return: Boolean
 * Rte_DT_DT_Thermal_Monitor_Temperatures_T_0_0: Real in interval [-FLT_MAX...FLT_MAX] with single precision
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * sint16: Integer in interval [-32768...32767] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dt_AlignmentModeIn_T: Enumeration of integer in interval [0...255] with enumerators
 *   OFF (0U)
 *   AUTOALIGNMENT (1U)
 *   SHORT_TRACK_ALIGNMENT (2U)
 *   SERVICE_ALIGNMEMT (3U)
 *   STATIC_ALIGNMENT (4U)
 * Dt_ForceRadiate: Enumeration of integer in interval [0...255] with enumerators
 *   FORCE_OFF (0U)
 *   FORCE_ON (1U)
 *   NO_FORCE (2U)
 * Dt_ITV_EVENT: Enumeration of integer in interval [0...255] with enumerators
 *   RESERVED_01 (1U)
 *   RESERVED_02 (2U)
 *   RESERVED_03 (3U)
 *   RESERVED_04 (4U)
 *   RESERVED_05 (5U)
 *   RESERVED_06 (6U)
 *   RESERVED_07 (7U)
 *   FEATURE_FUNCTIONS_ACSF_OUTPUT_BYPASS (8U)
 *   DSP_SIMULATE_DETECTION (9U)
 *   BLOCKAGE_WRAPPER_OUTPUT_BYPASS (10U)
 *   DOWN_SELECT_OBJECT_OUTPUT_BYPASS (11U)
 *   ALIGN_WRAPPER_OUTPUT_BYPASS (12U)
 *   RSDS_TRACKER_ALGORITHM_BYPASS (13U)
 *   YAW_RATE_PROCESSING_OUTPUT_BYPASS (14U)
 *   MNR_BLOCKAGE_OUTPUT_BYPASS (15U)
 *   ANGLE_DETECTION_ALGORITHM_BYPASS (16U)
 *   FEATURE_FUNCTIONS_VISOB_OUTPUT_BYPASS (17U)
 *   FEATURE_FUNCTIONS_ABA_INPUT_BYPASS (17U)
 *   XCP_TRACKER_OUTPUT (18U)
 *   FEATURE_FUNCTIONS_ABA_OUTPUT_BYPASS (19U)
 *   FEATURE_FUNCTIONS_ASW_OUTPUT_BYPASS (20U)
 *   FEATURE_FUNCTIONS_FENCES_OUTPUT_BYPASS (21U)
 *   FEATURE_FUNCTIONS_RECW_OUTPUT_BYPASS (22U)
 *   FEATURE_FUNCTIONS_LCDA_OUTPUT_BYPASS (23U)
 *   FEATURE_FUNCTIONS_CTA_OUTPUT_BYPASS (24U)
 *   FEATURE_FUNCTIONS_OH_OUTPUT_BYPASS (25U)
 *   FEATURE_FUNCTIONS_TRACKER_OUTPUT_BYPASS (26U)
 *   IGNORE_D2A_IPC_DATA (27U)
 *   IGNORE_H2A_IPC_DATA (28U)
 *   A2D_TO_IPC_BUFFER_BYPASS (28U)
 *   A2H_TO_IPC_BUFFER_BYPASS (29U)
 * Dt_ITV_VALUE: Enumeration of integer in interval [0...255] with enumerators
 *   Enable (170U)
 *   Disable (85U)
 * Dt_Therm_Mon_Temp_Opt_T: Enumeration of integer in interval [0...255] with enumerators
 *   IMMEDIATE_TEMPERATURES_KELVIN (0U)
 *   AVERAGE_TEMPERATURES_KELVIN (1U)
 *   IMMEDIATE_TEMPERATURES_CELCIUS (2U)
 *   AVERAGE_TEMPERATURES_CELCIUS (3U)
 *   IMMEDIATE_TEMPERATURES_FAHRENHEIT (4U)
 *   AVERAGE_TEMPERATURES_FAHRENHEIT (5U)
 * Dt_XCP_NvM_Control_T: Enumeration of integer in interval [0...255] with enumerators
 *   XCP_ERASE_KAM (1U)
 *   XCP_SET_KAM_DEFAULT (2U)
 *   XCP_ERASE_kAM_AND_SET_KAM_DEFAULT (3U)
 *   XCP_SAVE_RAM_TO_KAM (4U)
 *   XCP_VERIFY_KAM_STATUS (5U)
 *   XCP_ERASE_KAM_BLOCKS (6U)
 * Dt_XCP_SIM_MODE: Enumeration of integer in interval [0...255] with enumerators
 *   XCP_DI_SIM (1U)
 *   XCP_EN_SIM (2U)
 *   XCP_EN_ITV_SIM_MAX_MODE (3U)
 *   XCP_EN_ITV_SIM_MIN_MODE (4U)
 * Idt_XCP_Data_Flash_Process_T: Enumeration of integer in interval [0...255] with enumerators
 *   XCP_NVM_STATUS_PENDING (1U)
 *   XCP_NVM_STATUS_SUCCESS (2U)
 *   XCP_NVM_STATUS_FAIL (3U)
 * Idt_XCP_Op_Mode_T: Enumeration of integer in interval [0...255] with enumerators
 *   XCP_OP_MODE_NORMAL (1U)
 *   XCP_OP_MODE_MANF (2U)
 * Rte_DT_Dt_Auto_Alignment_Result_T_12: Enumeration of integer in interval [0...255] with enumerators
 *   OFF (0U)
 *   ACTIVE (1U)
 *   PAUSED (2U)
 *   FAILED (3U)
 * Rte_DT_Dt_Auto_Alignment_Result_T_13: Enumeration of integer in interval [0...255] with enumerators
 *   INVALID_INPUT (0U)
 *   SENSOR_FACING_UPWARDS (1U)
 *   SENSOR_FACING_DOWNWARDS (2U)
 *   SENSOR_FACING_RIGHT (3U)
 *   SENSOR_FACING_LEFT (4U)
 *   VELOCITY_TOO_LOW (5U)
 *   YAW_RATE_TOO_HIGH (6U)
 *   VEHICLE_IN_RESERVE (7U)
 *   INVALID_VEHICLE_SIGNAL (8U)
 *   TARGETS_TOO_LOW (9U)
 *   QUALITY_TOO_LOW (10U)
 *   ALIGNMENT_BLOCKAGE (11U)
 *   NONE (255U)
 * Rte_DT_Dt_XCP_Set_Output_0: Enumeration of integer in interval [0...255] with enumerators
 *   Idt_XCP_LED_STATE_AUTO (1U)
 *   Idt_XCP_LED_STATE_FORCED_OFF (16U)
 *   Idt_XCP_LED_STATE_FORCED_ON (17U)
 *   Idt_XCP_LED_STATE_FORCED_5_PWM (160U)
 *   Idt_XCP_LED_STATE_FORCED_50_PWM (161U)
 *   Idt_XCP_LED_STATE_FORCED_95_PWM (162U)
 * Rte_DT_Dt_XCP_Set_Output_1: Enumeration of integer in interval [0...255] with enumerators
 *   Idt_XCP_LED_SELECT_SOURCE_PULL (1U)
 *   Idt_XCP_LED_SELECT_SOURCE_EN (2U)
 * Rte_DT_Idt_XCP_Fault_Override_T_0: Enumeration of integer in interval [0...255] with enumerators
 *   FAULT_OVERRIDE_AUTO_MODE (1U)
 *   FAULT_OVERRIDE_SET_FAULT_MODE (2U)
 *   FAULT_OVERRIDE_CLEAR_FAULT_MODE (3U)
 * Rte_DT_Idt_XCP_LED_Output_Cntrl_T_0: Enumeration of integer in interval [0...255] with enumerators
 *   Idt_XCP_LED_SELECT_SOURCE_PULL (1U)
 *   Idt_XCP_LED_SELECT_SOURCE_EN (2U)
 * Rte_DT_Idt_XCP_LED_Output_Cntrl_T_1: Enumeration of integer in interval [0...255] with enumerators
 *   Idt_XCP_LED_STATE_AUTO (1U)
 *   Idt_XCP_LED_STATE_FORCED_OFF (16U)
 *   Idt_XCP_LED_STATE_FORCED_ON (17U)
 *   Idt_XCP_LED_STATE_FORCED_5_PWM (160U)
 *   Idt_XCP_LED_STATE_FORCED_50_PWM (161U)
 *   Idt_XCP_LED_STATE_FORCED_95_PWM (162U)
 * XCP_Status_T: Enumeration of integer in interval [0...1] with enumerators
 *   XCP_DISABLE (0U)
 *   XCP_ENABLE (1U)
 *
 * Array Types:
 * ============
 * Dt_Fault_T: Array with 16 element(s) of type uint8
 * Rte_DT_DT_Thermal_Monitor_Temperatures_T_0: Array with 2 element(s) of type Rte_DT_DT_Thermal_Monitor_Temperatures_T_0_0
 * Rte_DT_Dt_ID_data_0: Array with 16 element(s) of type uint8
 * Rte_DT_Dt_ID_data_1: Array with 8 element(s) of type uint8
 * Rte_DT_Dt_Xcp_Read_Write_Did_T_2: Array with 61 element(s) of type uint8
 * Rte_DT_Idt_XCP_Target_Select_T_1: Array with 12 element(s) of type uint16
 * Rte_DT_Idt_XCP_Target_Select_T_2: Array with 12 element(s) of type uint16
 *
 * Record Types:
 * =============
 * DT_Thermal_Monitor_Temperatures_T: Record with elements
 *   temperature of type Rte_DT_DT_Thermal_Monitor_Temperatures_T_0
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
 * Dt_Auto_Alignment_Result_T: Record with elements
 *   StartAzimuth of type float32
 *   StartElevation of type float32
 *   AACurrentAzimuth of type float32
 *   AACurrentElevation of type float32
 *   AAAzimuthStd of type float32
 *   AAElevationStd of type float32
 *   AzimuthError_positiveRead of type float32
 *   AzimuthError_negativeRead of type float32
 *   ElevationError_positive_Read of type float32
 *   ElevationError_negative_Read of type float32
 *   RollError_positive_Read of type float32
 *   RollError_negative of type float32
 *   AlignmentAutoStatus of type Rte_DT_Dt_Auto_Alignment_Result_T_12
 *   AutoAlignmentFailRootCause of type Rte_DT_Dt_Auto_Alignment_Result_T_13
 *   StartRoll of type float32
 *   AACurrentRoll of type float32
 *   AARollStd of type float32
 * Dt_Customer_SW_Version: Record with elements
 *   Customer_SW_Version of type Dt_Version_Info
 *   Customer_BL_Version of type Dt_Version_Info
 *   Customer_BM_Version of type Dt_Version_Info
 * Dt_Fault_Injection: Record with elements
 *   Sys_Domain of type uint8
 *   Failure_Type of type uint8
 *   Inject_Control of type uint8
 * Dt_ID_data: Record with elements
 *   MCU_ID of type Rte_DT_Dt_ID_data_0
 *   Unique_ID of type Rte_DT_Dt_ID_data_1
 * Dt_Initial_Alignment_Performance_Result_T: Record with elements
 *   MeasuredRange of type float32
 *   MeasuredRangeStd of type float32
 *   MeasuredRangeRate of type float32
 *   MeasuredRangeRateStd of type float32
 *   MeasuredAmp of type float32
 *   MeasuredAmpStd of type float32
 *   DistanceAbsolute of type uint32
 *   DistanceEffective of type uint32
 *   AverageNumberOfDetections of type float32
 *   DurationAbsolute of type uint32
 *   DurationEffective of type uint32
 *   AverageSpeed of type float32
 *   VehicleCondition of type uint8
 * Dt_Initial_Alignment_Result_T: Record with elements
 *   AlignmentAzimuth of type float32
 *   AlignmentElevation of type float32
 *   AzimuthStd of type float32
 *   ElevationStd of type float32
 *   CalTime of type float32
 *   AlignmentStaticStatus of type uint8
 *   AlignmentServiceStatus of type uint8
 *   AlignmentShortTrackStatus of type uint8
 *   ProgressPercent of type uint8
 *   AlignmentError of type uint8
 *   AlignmentRoll of type float32
 *   RollStd of type float32
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
 * Dt_Version_Info: Record with elements
 *   Major_Version of type uint8
 *   Minor_Version of type uint8
 *   Patch_Version of type uint8
 * Dt_Write_Alignment_NvM_Data_T: Record with elements
 *   AACurrentAzimuth of type float32
 *   AACurrentElevation of type float32
 *   AACurrentRoll of type float32
 *   InitialAlignmentResultAzimuth of type float32
 *   InitialAlignmentResultElevation of type float32
 *   InitialAlignmentResultRoll of type float32
 *   InitialLastSuccessfulAlignmentMode of type float32
 *   ElevationUpdates of type float32
 *   AzimuthUpdates of type float32
 *   RollUpdates of type float32
 *   InitialAlignmentResultElevationUpdates of type float32
 *   InitialAlignmentResultHostSpeedCompensationFactor of type float32
 *   HostSpeedCompensationFactor of type float32
 *   InitialAlignmentResultAzimuthUpdates of type float32
 *   InitialAlignmentResultRollUpdates of type float32
 *   AlignmentModeOut of type uint8
 * Dt_XCP_Hw_Interface_Cntrl: Record with elements
 *   Output_Select_F1_1F_IN of type uint8
 *   Output_State_F1_1F_IN of type uint8
 * Dt_XCP_Set_Output: Record with elements
 *   xcp_set_output_state of type Rte_DT_Dt_XCP_Set_Output_0
 *   xcp_set_output_select of type Rte_DT_Dt_XCP_Set_Output_1
 * Dt_Xcp_Read_Write_Did_T: Record with elements
 *   ServiceId of type uint8
 *   Did of type uint16
 *   Data of type Rte_DT_Dt_Xcp_Read_Write_Did_T_2
 * Idt_Cal_Version_Info_Type: Record with elements
 *   SMC_MajorVersion of type uint8
 *   SMC_PlatformRevision of type uint8
 *   SMC_Compatablity of type uint8
 *   USC_MajorVersion of type uint8
 *   USC_PlatformRevision of type uint8
 *   USC_Compatablity of type uint8
 *   Julian_Year of type uint8
 *   Julian_Date of type uint16
 * Idt_SW_Version_Info_T: Record with elements
 *   SwReleaseRevision of type uint8
 *   SwMajorRevision of type uint8
 *   SwMinorRevision of type uint8
 *   SwFieldRevision of type uint8
 *   DbcMajorRevision of type uint8
 *   DbcMinorRevision of type uint8
 *   FBLMajorRevision of type uint8
 *   FBLMinorRevision of type uint8
 *   FBLPromoteRevision of type uint8
 *   BMMajorRevision of type uint8
 *   BMMinorRevision of type uint8
 *   BMFieldRevision of type uint8
 *   ASRMajorRevision of type uint8
 *   ASRMinorRevision of type uint8
 *   ASRfieldRevision of type uint8
 * Idt_Type_MMIC_Temperature: Record with elements
 *   MMIC_TX0_Temp of type sint16
 *   MMIC_TX1_Temp of type sint16
 *   MMIC_TX2_Temp of type sint16
 *   MMIC_TX3_Temp of type sint16
 *   MMIC_RX0_Temp of type sint16
 *   MMIC_PVT_Temp of type sint16
 *   MMIC_Quad_Temp of type sint16
 * Idt_XCP_Fault_Override_T: Record with elements
 *   action of type Rte_DT_Idt_XCP_Fault_Override_T_0
 *   byte_pos of type uint8
 *   bit_pos of type uint8
 * Idt_XCP_LED_Output_Cntrl_T: Record with elements
 *   xcp_led_select of type Rte_DT_Idt_XCP_LED_Output_Cntrl_T_0
 *   xcp_led_state of type Rte_DT_Idt_XCP_LED_Output_Cntrl_T_1
 * Idt_XCP_RFBIST_Status_T: Record with elements
 *   MMIC_1_LNA_Status of type uint8
 *   MMIC_1_MIXER_Status of type uint8
 *   MMIC_2_LNA_Status of type uint8
 *   MMIC_2_MIXER_Status of type uint8
 * Idt_XCP_Single_Look_T: Record with elements
 *   single_look_en of type uint8
 *   single_look_select of type uint8
 * Idt_XCP_Target_Select_T: Record with elements
 *   xcp_target_select_cmnd of type uint8
 *   xcp_target_range_idx of type Rte_DT_Idt_XCP_Target_Select_T_1
 *   xcp_target_doppler_idx of type Rte_DT_Idt_XCP_Target_Select_T_2
 *
 *********************************************************************************************************************/

#define SWC_PLT_CDD_XCP_START_SEC_CODE
#include "SWC_PLT_CDD_XCP_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CS_Pp_XCP_Enable_Disable_Status
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Status> of PortPrototype <Pp_XCP_Enable_Disable>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CS_Pp_XCP_Enable_Disable_Status(XCP_Status_T XCP_Status)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CS_Pp_XCP_Enable_Disable_Status_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_XCP_CODE)
CS_Pp_XCP_Enable_Disable_Status(XCP_Status_T XCP_Status) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: CS_Pp_XCP_Enable_Disable_Status
    *********************************************************************************************************************/

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_XCP_10ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Pp_DSP_Read_Sensitivity_Factor_De_DSP_Read_Sensitivity_Factor(uint16 *data)
 *   Std_ReturnType Rte_Read_Rp_Alignment_NvM_Data_Alignment_NvM_Data(Dt_Write_Alignment_NvM_Data_T *data)
 *   Std_ReturnType Rte_Read_Rp_Auto_Alignment_Data_Auto_Alignment_Data(Dt_Auto_Alignment_Result_T *data)
 *   Std_ReturnType Rte_Read_Rp_Initial_Alignment_Result_Initial_Alignment_Result(Dt_Initial_Alignment_Result_T *data)
 *   Std_ReturnType
 *Rte_Read_Rp_initial_Alignment_Perform_Result_initial_Alignment_Perform(Dt_Initial_Alignment_Performance_Result_T *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_ADC_XCP_Req_De_ADC_XCP_Req(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_Alignment_Type_Alignment_Type(Dt_AlignmentModeIn_T data)
 *   Std_ReturnType Rte_Write_Pp_Alignment_Write_NvM_Data_Write_Alignment_NvM(const Dt_Write_Alignment_NvM_Data_T *data)
 *   Std_ReturnType Rte_Write_Pp_DSP_Wr_Sensitivity_Factor_De_DSP_Wr_Read_Sensitivity_Factor(uint16 data)
 *   Std_ReturnType Rte_Write_Pp_DSP_XCP_Target_Select_De_DSP_XCP_Target_Select(const Idt_XCP_Target_Select_T *data)
 *   Std_ReturnType Rte_Write_Pp_XCP_Alignment_Flag_De_XCP_Alignment_Flag(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable(const Idt_XCP_Single_Look_T *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CS_Rp_PCAN_stop_periodic_interface_control_stop_periodic_interface_control(uint8 *Pcan_stop_periodic)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CS_Rp_VCAN_stop_periodic_interface_control_Operation(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType
 *Rte_Call_CS_Rp_ethernet_platform_stop_periodic_interface_control_ethernet_platform_stop_periodic_interface_control(uint8
 **Ethernet_plt_stop_periodic) Synchronous Server Invocation. Timeout: None Std_ReturnType
 *Rte_Call_CS_Rp_ethernet_project_stop_periodic_interface_control_Operation(void) Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CS_XCP_FCCU_FakeFault_Inject_Read(NCFF_Channel_Number NCFF_Channel, Injection_Control
 *Injection_control, Return *Return) Synchronous Server Invocation. Timeout: None Returned Application Errors:
 *RTE_E_Pi_NCFFchannel_IC_E_NOT_OK, RTE_E_Pi_NCFFchannel_IC_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_XCP_10ms_doc
 *********************************************************************************************************************/

volatile uint8_t XCP_User_Cmnd_Received = CODED_FALSE;
const uint8_t *xcp_cmd;
static XCP_DAQ_Descriptor_Table_T XCP_Variables_List_DAQ[5][NUM_OF_DAQ1_VARIABLES] = {0};

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_XCP_CODE) RE_XCP_10ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_XCP_10ms
    *********************************************************************************************************************/

   uint8 retValue             = XCP_CMD_OK;
   uint8 retvalue_usc_smc     = XCP_CMD_OK;
   MemIf_StatusType flsStatus = (MemIf_StatusType)0;

   XCP_BB_Refresh_Dynamic_Data(); /* Refresh the dynamic data used by XCP before processing any command */

   if (CODED_TRUE == XCP_User_Cmnd_Received)
   {
      retValue = SWC_Xcp_UserCommand(XCP_CHANNEL_IDX, xcp_cmd);
      if (XCP_CMD_OK == retValue)
      {
         Xcp_SendCrm(XCP_CHANNEL_IDX);
      }
      else if (XCP_CMD_PENDING != retValue)
      {
         /* Ensure USER_COMMAND transactions always terminate with a CRM. */
         SWC_Xcp_SendNegResp(XCP_CHANNEL_IDX, retValue);
      }
      XCP_User_Cmnd_Received = CODED_FALSE;
   }
   if (xcp_usc_smc_data.xcp_usc_smc_initialized == CODED_TRUE)
   {
      retvalue_usc_smc = SWC_Xcp_Flash_sequence();
      if (XCP_CMD_PENDING == retvalue_usc_smc)
      {
         /*Handle Flash Programm or Erase  sequence*/
         if (CODED_TRUE == XCP_Flash_Erase_Prgm_Cmd_Recevied)
         {
            flsStatus = Fls_GetStatus();
            if (MEMIF_IDLE == flsStatus)
            {
               XCP_Flash_Erase_Prgm_Cmd_Recevied        = CODED_FALSE;
               xcp_usc_smc_data.xcp_usc_smc_initialized = CODED_FALSE;
               Xcp_SendCrm(XCP_CHANNEL_IDX);
            }
            else if (MEMIF_UNINIT == flsStatus)
            {
               SWC_Xcp_SendNegResp(XCP_CHANNEL_IDX, XCP_CMD_ERROR);
               XCP_Flash_Erase_Prgm_Cmd_Recevied        = CODED_FALSE;
               xcp_usc_smc_data.xcp_usc_smc_initialized = CODED_FALSE;
            }
            else
            {
               /* Do Nothing*/
            }
         }
      }
      else
      {
         SWC_Xcp_SendNegResp(XCP_CHANNEL_IDX, retvalue_usc_smc);
         XCP_Flash_Erase_Prgm_Cmd_Recevied        = CODED_FALSE;
         xcp_usc_smc_data.xcp_usc_smc_initialized = CODED_FALSE;
      }
   }
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_XCP_50ms
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
 *   Std_ReturnType Rte_Read_Rp_Active_Fault_Latch_Table_De_ActiveFaultLatchTable(uint8 *data)
 *     Argument data: uint8* is of type Dt_Fault_T
 *   Std_ReturnType Rte_Read_Rp_Active_Fault_Table_De_ActiveFaultTable(uint8 *data)
 *     Argument data: uint8* is of type Dt_Fault_T
 *   Std_ReturnType Rte_Read_Rp_Alignment_NvM_Read_Record_De_Write_Alignment_NvM_Data(Dt_Write_Alignment_NvM_Data_T *data)
 *   Std_ReturnType Rte_Read_Rp_Analog_Channel_Count_De_Analog_Channel_Count(uint16 *data)
 *   Std_ReturnType Rte_Read_Rp_Application_Checksum_De_Application_Checksum(uint32 *data)
 *   Std_ReturnType Rte_Read_Rp_Calibration_Version_Info_De_Calibration_Version_Info(Idt_Cal_Version_Info_Type *data)
 *   Std_ReturnType Rte_Read_Rp_Customer_SW_Version_Info_De_Customer_SW_Version_Info(Dt_Customer_SW_Version *data)
 *   Std_ReturnType Rte_Read_Rp_Fault_Enable_Table_De_FaultEnableTable(uint8 *data)
 *     Argument data: uint8* is of type Dt_Fault_T
 *   Std_ReturnType Rte_Read_Rp_Fault_Test_Complete_Table_De_FaultTestCompleteTable(uint8 *data)
 *     Argument data: uint8* is of type Dt_Fault_T
 *   Std_ReturnType Rte_Read_Rp_HistoryFaultTable_De_HistoryFaultTable(uint8 *data)
 *     Argument data: uint8* is of type Dt_Fault_T
 *   Std_ReturnType Rte_Read_Rp_Keep_Alive_Checksum_De_Keep_Alive_Checksum(uint32 *data)
 *   Std_ReturnType Rte_Read_Rp_MCU_Sensor_Count_De_MCU_Sensor_Count(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_MMIC_Count_De_MMIC_Count(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_MMIC_Temperature_De_MMIC_Temperature(Idt_Type_MMIC_Temperature *data)
 *   Std_ReturnType Rte_Read_Rp_MPU_lock_sts_De_MPU_lock_sts(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_NvM_flag_status_Pim_write_status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_PhysicalAdcData_De_PhysicalAdcData(Dt_AdcData_T *data)
 *   Std_ReturnType Rte_Read_Rp_Primary_Bootloader_Checksum_De_Primary_Bootloader_Checksum(uint32 *data)
 *   Std_ReturnType Rte_Read_Rp_Radar_CMD_Radiate_De_Radar_CMD_Radiate(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_Radar_Init_Status_De_Radar_Init_Status(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_Radar_RFBIST_Calib_Status_De_Radar_RFBIST_Calib_Status(Idt_XCP_RFBIST_Status_T *data)
 *   Std_ReturnType Rte_Read_Rp_RawAdc_Data_Filtered_De_RawAdcData(Dt_RawAdcDataFilt_T *data)
 *   Std_ReturnType Rte_Read_Rp_RawAdc_Data_UnFiltered_RawAdcDataUnfiltered(Dt_RawAdcData_T *data)
 *   Std_ReturnType Rte_Read_Rp_SMC_Checksum_De_SMC_Checksum(uint32 *data)
 *   Std_ReturnType Rte_Read_Rp_SW_Version_Info_De_SW_Version_Info(Idt_SW_Version_Info_T *data)
 *   Std_ReturnType Rte_Read_Rp_USC_Checksum_De_USC_Checksum(uint32 *data)
 *   Std_ReturnType Rte_Read_Rp_XCP_DID_RESP_De_XCP_DID_RESP(Dt_Xcp_Read_Write_Did_T *data)
 *   Std_ReturnType Rte_Read_Rp_XCP_Data_Flash_Process_De_Data_Flash_Process(Idt_XCP_Data_Flash_Process_T *data)
 *   Std_ReturnType Rte_Read_s_aptiv_xcp_can_chn_sel_EN_DIS(boolean *data)
 *   Std_ReturnType Rte_Read_s_aptiv_xcp_en_EN_DIS(boolean *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_Hil_Activation_De_Hil_Activation(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_MPU_lock_request_De_MPU_lock_sts(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_UDP_Logging_Enabled_Flag_De_UDP_Logging_Enabled_Flag(boolean data)
 *   Std_ReturnType Rte_Write_Pp_XCP_ADC_MCU_Temp_Override_De_XCP_ADC_MCU_Temp_Override(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_XCP_CW_Mode_De_XCP_CW_Mode(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_XCP_DID_CMD_De_XCP_DID_CMD(const Dt_Xcp_Read_Write_Did_T *data)
 *   Std_ReturnType Rte_Write_Pp_XCP_Ethernet_En_Dis_De_XCP_Ethernet_En_Dis(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_XCP_Fault_Injection_De_Xcp_Fault_Injection(const Dt_Fault_Injection *data)
 *   Std_ReturnType Rte_Write_Pp_XCP_Fault_Override_De_XCP_Fault_Override(const Idt_XCP_Fault_Override_T *data)
 *   Std_ReturnType Rte_Write_Pp_XCP_ForceRadiate_De_XCPForceRadiate(Dt_ForceRadiate data)
 *   Std_ReturnType Rte_Write_Pp_XCP_HIL_Mode_De_XCP_HIL_Mode(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_XCP_Hw_Interface_Cntrl_De_Hw_Interface_Cntrl(const Dt_XCP_Hw_Interface_Cntrl *data)
 *   Std_ReturnType Rte_Write_Pp_XCP_Itv_IPC_Event_State_De_ITV_EVENT(Dt_ITV_EVENT data)
 *   Std_ReturnType Rte_Write_Pp_XCP_Itv_IPC_State_De_XCP_SIM_MODE(Dt_XCP_SIM_MODE data)
 *   Std_ReturnType Rte_Write_Pp_XCP_Itv_IPC_Value_State_De_ITV_VALUE(Dt_ITV_VALUE data)
 *   Std_ReturnType Rte_Write_Pp_XCP_LED_OP_Cntrl_De_XCP_LED_OP_Cntrl(const Idt_XCP_LED_Output_Cntrl_T *data)
 *   Std_ReturnType Rte_Write_Pp_XCP_NvM_Control_De_XCP_NvM_Control(Dt_XCP_NvM_Control_T data)
 *   Std_ReturnType Rte_Write_Pp_XCP_Op_Mode_De_XCP_Op_Mode(Idt_XCP_Op_Mode_T data)
 *   Std_ReturnType Rte_Write_Pp_XCP_PCAN_En_Dis_De_XCP_PCAN_En_Dis(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_XCP_Phase_Rotator_Calibration_De_XCP_Phase_Rotator_Calibration(boolean data)
 *   Std_ReturnType Rte_Write_Pp_XCP_Program_Mode_De_XCP_Program_Mode(boolean data)
 *   Std_ReturnType Rte_Write_Pp_XCP_RFBIST_Calib_Trigger_De_XCP_RFBIST_Calib_Trigger(uint8 data)
 *   Std_ReturnType Rte_Write_Pp_XCP_Set_Output_State_De_XCP_Set_Output(const Dt_XCP_Set_Output *data)
 *   Std_ReturnType Rte_Write_Pp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable(const Idt_XCP_Single_Look_T *data)
 *   Std_ReturnType Rte_Write_Pp_XCP_VCAN_En_Dis_De_XCP_VCAN_En_Dis(uint8 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CS_Alignment_Fault_Injection_read(uint8 Injection_control)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CS_Diag_Fault_Injection_Read(uint8 Injection_Control, uint8 Failure_Type)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CS_External_Watchdog_Fault_Injection_Read(uint8 Injection_control, uint8 Failure_Type)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CS_FCCU_Fault_Injection_Read(uint8 Injection_control, uint8 Failure_Type)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CS_FCRU_Fault_Injection_Read(uint8 Injection_control, uint8 Failure_Type)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CS_FailSafe_Fault_Injection_Read(uint8 Injection_control, uint8 Failure_Type)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CS_IPC_Fault_Injection_Read(uint8 Injection_control, uint8 Failure_Type)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CS_MCU_Safety_Fault_Injection_Read(uint8 Injection_control, uint8 Failure_Type)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CS_Modemanager_Fault_Injection_Read(uint8 Injection_Control, uint8 Failure_Type)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CS_PlatformTime_Fault_Injection_Read(uint8 Injection_control, uint8 Failure_Type)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CS_Radar_control_Fault_Injection_Read(uint8 Injection_control, uint8 Failure_Type)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CS_Signal_Integrity_Fault_Injection_Read(uint8 Injection_Control, uint8 Failure_Type)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CS_ThermMonTemp_Read(Dt_Therm_Mon_Temp_Opt_T temp_option, DT_Thermal_Monitor_Temperatures_T *reqValue)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Pi_ThermMonTemp_E_NOT_OK
 *   Std_ReturnType Rte_Call_CS_Trigger_Clear_Faults_Operation_Operation(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_CS_WdgHandler_Fault_Injection_Read(uint8 Injection_control, uint8 Failure_Type)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_Rp_ECU_Reset_ECU_Soft_Reset(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_Rp_PCAN_Srv_DisableAppTx_Operation(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_Rp_PCAN_Srv_EnableAppTx_Operation(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_Rp_VCAN_Srv_DisableAppTx_Operation(void)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_Rp_VCAN_Srv_EnableAppTx_Operation(void)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_XCP_50ms_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_XCP_CODE) RE_XCP_50ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_XCP_50ms
    *********************************************************************************************************************/

   uint8 retValue        = XCP_CMD_OK;
   uint8_t *res          = Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b;
   uint8_t *frame_length = &(Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength);

   if (CODED_TRUE == Get_XCP_Pending_Cmnd_Status())
   {
      retValue = XCP_Periodic_Task(res, frame_length);

      if (XCP_CMD_OK == retValue)
      {
         Xcp_SendCrm(XCP_CHANNEL_IDX);
         /* (void)Rte_Write_Pp_ADC_XCP_Req_De_ADC_XCP_Req(xcp_adc_trigger_flag); */
      }
   }
#if (ENABLE_SIT_TEST_STUBS == STD_ON)
   if (xcp_force_test == 0)
   {
      XCP_Force_Radiate = 0;
   }
   else if (xcp_force_test == 1)
   {
      XCP_Force_Radiate = 1;
   }
   else if (xcp_force_test == 2)
   {
      XCP_Force_Radiate = 2;
   }
   else
   {
      /*do nothing*/
   }
   (void)Rte_Write_Pp_XCP_ForceRadiate_De_XCPForceRadiate(XCP_Force_Radiate);
#endif
   SWC_XCP_Update_PCAN_Stop_Periodic_Cmnd(); /* This is called here to disble PCAN mesages using global varaible to support
                                                Canape*/

#if (ENABLE_SIT_TEST_STUBS == TRUE)
   switch (F1_12_interface_test)
   {
      case 1:
      {
         (void)Rte_Call_CS_FCRU_Fault_Injection_Read(Injection_control_test, Failure_Type_test);
         break;
      }
      case 2:
      {
         (void)Rte_Call_CS_FailSafe_Fault_Injection_Read(Injection_control_test, Failure_Type_test);
         break;
      }
      case 3:
      {
         (void)Rte_Call_CS_IPC_Fault_Injection_Read(Injection_control_test, Failure_Type_test);
         break;
      }
      case 4:
      {
         (void)Rte_Call_CS_MCU_Safety_Fault_Injection_Read(Injection_control_test, Failure_Type_test);
         break;
      }
      case 7:
      {
         (void)Rte_Call_CS_Modemanager_Fault_Injection_Read(Injection_control_test, Failure_Type_test);
         break;
      }
      case 9:
      {
         (void)Rte_Call_CS_WdgHandler_Fault_Injection_Read(Injection_control_test, Failure_Type_test);
         break;
      }
      case 10:
      {
         (void)Rte_Call_CS_Signal_Integrity_Fault_Injection_Read(Injection_control_test, Failure_Type_test);
         break;
      }
      default:
      {
         break;
      }
   }
#endif

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_XCP_Init
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
 *   Std_ReturnType Rte_Read_Rp_BoardRevision_Xcp_De_BoardRevision_Xcp(uint8 *data)
 *   Std_ReturnType Rte_Read_Rp_ID_data_De_ID_data(Dt_ID_data *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_XCP_Init_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_PLT_CDD_XCP_CODE) RE_XCP_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: RE_XCP_Init
    *********************************************************************************************************************/
   XCP_BB_Init_Const_Ptr();
   SWC_Read_XCP_Rfbist_Debug_Data();

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Trigger_Periodic_XCP_Event
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Trigger_Look_Based_XCP_Event> of PortPrototype
 *<CS_PostRadarProcessing_XCP_Event_Trigger>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Trigger_Periodic_XCP_Event(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_PostRadarProcessing_XCP_Event_Trigger_E_NOT_OK
 *   RTE_E_PostRadarProcessing_XCP_Event_Trigger_E_NOT_OK
 *   RTE_E_PostRadarProcessing_XCP_Event_Trigger_E_OK
 *   RTE_E_PostRadarProcessing_XCP_Event_Trigger_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Trigger_Periodic_XCP_Event_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SWC_PLT_CDD_XCP_CODE) Trigger_Periodic_XCP_Event(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
    * Symbol: Trigger_Periodic_XCP_Event (returns application error)
    *********************************************************************************************************************/

   return RTE_E_OK;

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

#define SWC_PLT_CDD_XCP_STOP_SEC_CODE
#include "SWC_PLT_CDD_XCP_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(uint8, XCP_CODE) SWC_Xcp_Isr_UserCommand(Xcp_ChannelType XcpChannel, P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) Cmmd)
{
   uint8 retValue = XCP_CMD_PENDING;

   /* Add User Command Implementation */
   (void)XcpChannel;
   XCP_User_Cmnd_Received = CODED_TRUE;
   xcp_cmd                = Cmmd;

   return retValue;
}

static FUNC(uint8, XCP_CODE) SWC_Xcp_UserCommand(Xcp_ChannelType XcpChannel, P2CONST(uint8, AUTOMATIC, XCP_APPL_VAR) Cmmd)
{
   uint8 retValue        = XCP_CMD_OK;
   uint8_t *res          = Xcp_ChannelInfo[XcpChannel].ResponseFrame.b;
   uint8_t *frame_length = &(Xcp_ChannelInfo[XcpChannel].ResponseFrameLength);
   Dt_ForceRadiate xcp_force_radiate;

   retValue = XCP_User_Command(Cmmd, res, frame_length);
   if ((XCP_CMD_OK == retValue) || (XCP_CMD_PENDING == retValue))
   {
      xcp_force_radiate = SWC_XCP_Update_Force_Radiate_Cmd();
      (void)Rte_Write_Pp_XCP_NvM_Control_De_XCP_NvM_Control((Dt_XCP_NvM_Control_T)xcp_nvm_status);
      (void)Rte_Write_Pp_XCP_ForceRadiate_De_XCPForceRadiate(xcp_force_radiate);
      XCP_Set_Output.xcp_set_output_select = XCP_Out_Output_State.xcp_out_select;
      XCP_Set_Output.xcp_set_output_state  = XCP_Out_Output_State.xcp_out_state;
      (void)Rte_Write_Pp_XCP_Set_Output_State_De_XCP_Set_Output(&XCP_Set_Output);
      (void)Rte_Write_Pp_XCP_Single_Look_Enable_De_XCP_Single_Look_Enable((const Idt_XCP_Single_Look_T *)&XCP_Single_Look_Mode);
      (void)Rte_Write_Pp_XCP_ADC_MCU_Temp_Override_De_XCP_ADC_MCU_Temp_Override(XCP_Itv_ADC_State);
      SWC_XCP_Update_Inject_Fault_Cmnd();
      SWC_XCP_Update_Normal_Stop_Periodic_Cmnd();
      SWC_XCP_Update_PCAN_Stop_Periodic_Cmnd();
      SWC_XCP_Update_VCAN_Stop_Periodic_Cmnd();
      SWC_XCP_Update_Ethernet_Platform_Stop_Periodic_Cmnd();
      SWC_XCP_Update_Ethernet_Project_Stop_Periodic_Cmnd();
      SWC_XCP_Update_Fault_table();
      SWC_XCP_Update_Clear_Faults_Cmnd();
      SWC_XCP_Update_Write_Alignment();
      SWC_XCP_Update_Write_DID();
   }
   else
   {
   }

   return retValue;
}

/*****************************************************************************
 *. Name: SWC_Xcp_Get_Seed
 *.
 *. Description: Generates a pseudo-random seed for XCP security authentication.
 *.              Creates cryptographic seed using system timer as entropy source
 *.              for seed-key challenge-response protocol. This seed will be used
 *.              by external tools to calculate the corresponding unlock key.
 *. Shared Variables: None
 *.
 *. Parameters:  Length               [IN] Number of bytes to generate (typically 8)
 *.              Global_seed_add      [OUT] Pointer to seed storage array,
 *.                                   filled with generated pseudo-random values
 *.              Seed                 [OUT] Pointer to duplicate seed array,
 *.                                   contains identical values to Global_seed_add
 *.
 *. Return Value: None (void function)
 *.
 *. Design Information:
 *.   - Uses system timer (STM) as hardware entropy source
 *.   - Rotating mask pattern ensures different bytes use different timer bits
 *.   - Timer register address: 0x10 (XCP_STM_1_BASE + offset)
 *.   - Mask rotation prevents identical bytes when timer changes slowly
 *.   - Dual output arrays support different usage patterns in XCP protocol
 *.
 *. Traces to: XCP Protocol Specification - Seed & Key Authentication
 *.            Section: Security Access Control, GET_SEED Command
 *****************************************************************************/
FUNC(void, XCP_CODE) SWC_Xcp_Get_Seed(const uint8 Length, uint8_t *Global_seed_add, uint8_t *Seed)
{
   uint8 i;
   uint32_t shift_temp = 0x000000FFU;

   for (i = 0U; i < Length; i++)
   {
      Global_seed_add[i] = (uint8)(ReadSystemTimer() & (shift_temp << (i % 4)));
      Seed[i]            = Global_seed_add[i];
   }
}

/*****************************************************************************
 *. Name: SWC_Xcp_Unlock
 *.
 *. Description: Validates XCP unlock key against generated seed to grant
 *.              access to protected XCP resources (calibration, measurement,
 *.              programming). Implements seed-key authentication mechanism
 *.              for XCP security protocol.
 *.
 *. Shared Variables: None
 *.
 *. Parameters:  Global_seed_add      [IN/OUT] Pointer to 8-byte seed array,
 *.                                   modified to contain calculated key
 *.              Global_appl_key      [IN/OUT] Pointer to application-provided
 *.                                   key array, cleared after validation
 *.              len                  [IN] Length of key/seed arrays (typically 8)
 *.
 *. Return Value: XCP_CMD_OK          Success - key matches calculated value
 *.               XCP_CMD_ERROR       Failure - key validation failed
 *.
 *. Design Information:
 *.   - Uses 64-bit arithmetic for seed-to-key transformation
 *.   - Magic constant provides cryptographic obfuscation
 *.   - Key is zeroed after use to prevent memory attacks
 *.   - Big-endian byte order assumed for multi-byte values
 *.
 *. Traces to: XCP Protocol Specification - Seed & Key Authentication
 *.            Section: Security Access Control
 *****************************************************************************/
FUNC(uint8, XCP_CODE) SWC_Xcp_Unlock(uint8_t *Global_seed_add, uint8_t *Global_appl_key, uint8_t len)
{
   uint8_t retValue = XCP_CMD_OK;
   uint8_t i;
   uint32_t xcp_seed_msb  = 0U;
   uint32_t xcp_seed_lsb  = 0U;
   uint64_t xcp_seed      = 0U;
   uint64_t calc_key      = 0U;
   uint8_t *calc_key_ptr  = NULL;
   uint64_t *xcp_seed_ptr = NULL;

   xcp_seed_ptr = ((uint64 *)&(Global_seed_add[0]));
   calc_key_ptr = ((uint8 *)&calc_key);
   /* to clear the warning */
   (void)xcp_seed_ptr;

   xcp_seed_msb =
      (uint32_t)((Global_seed_add[0] << 24U) | (Global_seed_add[1] << 16U) | (Global_seed_add[2] << 8U) | (Global_seed_add[3]));
   xcp_seed_lsb =
      (uint32_t)((Global_seed_add[4] << 24U) | (Global_seed_add[5] << 16U) | (Global_seed_add[6] << 8U) | (Global_seed_add[7]));

   xcp_seed = (((uint64)xcp_seed_msb << 32) | (xcp_seed_lsb));
   calc_key = (uint64)(xcp_seed + 0x4e874e874e874e87);

   /* TODO: Start not sure why this is needed to write key to Global_seed_add
      When XcpAppl_Seed is not aligned to 32bit or 64 bit, 64 bit copy causes data abort exception
   *xcp_seed_ptr = calc_key;
     TODO: End */

   /* #10 Checks if the key fits to the prior generated seed and return the resource (XCP_RM_CAL_PAG, XCP_RM_DAQ,
    *     XCP_RM_STIM, XCP_RM_PGM or Invalid=0) to be unlocked. */
   /* The key  */
   for (i = 0U; i < len; i++)
   {
      if (Global_appl_key[i] != calc_key_ptr[i])
      {
         retValue = XCP_CMD_ERROR;
         break;
      }
      /* Delete Key - one time check */
      Global_appl_key[i] = 0U;
   }

   return (retValue);
}

/*****************************************************************************
 *. Name: SWC_Xcp_Reset()
 *.
 *.
 *. Shared Variables: None
 *.
 *. Parameters:  uint8_t xcp_program_start_flag
 *. Return Value: void
 *. Design Information:
 *. Traces to:
 *. Section :
 *. JIRA/Plastic Task: DNP-6744
 *****************************************************************************/
FUNC(void, XCP_CODE) SWC_Xcp_Reset(uint8_t xcp_program_start_flag)
{
   xcp_flash_wr_data_index = 0;
   (void)xcp_program_start_flag;
   (void)Rte_Write_Pp_XCP_Program_Mode_De_XCP_Program_Mode((bool)xcp_program_start_flag);
   (void)Rte_Call_Rp_ECU_Reset_ECU_Soft_Reset();
}

uint8_t SWC_XCP_Get_Look_En_Status(uint8_t look)
{
   uint8_t idx;
   uint8_t look_en_status = CODED_FALSE;
   Radar_Mode_T mode      = Get_Radar_Mode();

   for (idx = 0U; idx < (uint8_t)NUM_LOOKS; idx++)
   {
      if (look == (uint8_t)k_look_order_smc[mode][idx])
      {
         look_en_status = CODED_TRUE;
      }
   }
   return (look_en_status);
}
/*****************************************************************************
 *. Name: SWC_XCP_Copy_Target_Report()
 *.
 *. Shared Variables: None
 *.
 *. Parameters: None
 *. Return Value:  None
 *.
 *. Design Information:
 *. Traces to:
 *. Section :
 *.
 *. JIRA/Plastic Task: DNP - 4134
 *****************************************************************************/
static XCP_Target_Report_T *SWC_XCP_Copy_Target_Report(void)
{
   XCP_Target_Report_T *l_xcp_det_ptr = (XCP_Target_Report_T *)&(Get_IPC_D2M_Sp_Post_Proc_Buffer()->payload.det_data);
   return (l_xcp_det_ptr);
}

XCP_Copy_Trgt_Rprts_fptr_T Get_XCP_Copy_Target_Report_Fptr(void)
{
   return ((XCP_Copy_Trgt_Rprts_fptr_T)SWC_XCP_Copy_Target_Report);
}

uint8_t Get_XCP_Radar_Radiate_Cmd(void)
{
   uint8_t xcp_radar_radiate = CODED_TRUE;
   /* (void)Rte_Read_Pp_Radar_CMD_Radiate_De_Radar_CMD_Radiate((uint8_t*)&xcp_radar_radiate); */
   xcp_radar_radiate = (uint8_t)Get_Radar_Radiate_Enable();
   if (TRUE == xcp_radar_radiate)
   {
      xcp_radar_radiate = CODED_TRUE;
   }
   else
   {
      xcp_radar_radiate = CODED_FALSE;
   }
   return ((uint8_t)xcp_radar_radiate);
}

uint8_t Get_XCP_Radar_Init_Status(void)
{
   /* uint8_t xcp_radar_init_status = 3; */
   /* (void)Rte_Read_Pp_Radar_Init_Status_De_Pi_Radar_Init_Status(&xcp_radar_init_status); */
   return ((uint8_t)Get_Radar_Ctl_Init_Status());
}

/*****************************************************************************
 *. Name: Get_XCP_Current_Look()
 *.
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *. Return Value: None
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
uint8_t Get_XCP_Current_Look(void)
{
   uint8_t l_xcp_current_look;
   D2M_Msg_T *l_xcp_det_ptr = Get_IPC_D2M_Sp_Post_Proc_Buffer();
   l_xcp_current_look       = (uint8_t)l_xcp_det_ptr->payload.rdd_stream_data.look_data.look_id;
   return (l_xcp_current_look);
}

/*****************************************************************************
 *. Name: Get_XCP_Look_Enable_Status_Fptr()
 *.
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *. Return Value: None
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/

XCP_Look_Enable_Status_fptr_T Get_XCP_Look_Enable_Status_Fptr(void)
{
   return (SWC_XCP_Get_Look_En_Status);
}

/*****************************************************************************
 *. Name: Get_XCP_num_max_dets()
 *.
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *. Return Value: None
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
uint16_t Get_XCP_num_max_dets(void)
{
   return ((uint16_t)AF_MAX_NUM_DET);
}

/*****************************************************************************
 *. Name: Get_XCP_num_ambig_per_det()
 *.
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *. Return Value: None
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
uint8_t Get_XCP_num_ambig_per_det(void)
{
   return ((uint8_t)AF_NUM_AMBIG_PER_DET);
}

/*****************************************************************************
 *. Name: Get_XCP_Manufacture_Mode_Variables_List_DAQ()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: volatile XCP_Daq_Descriptor_Table_T*
 *. Design Information:
 *. Traces to:
 *. Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
static void *Get_XCP_Manufacture_Mode_Variables_List_DAQ(void)
{
   return ((void *)XCP_Variables_List_DAQ[0]);
}

/*****************************************************************************
 *. Name: SWC_XCP_Update_Normal_Stop_Periodic_Cmnd()
 *.
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *. Return Value: None
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
static void SWC_XCP_Update_Normal_Stop_Periodic_Cmnd(void)
{
   if ((uint8_t)XCP_STOP_MSG == xcp_normal_stop_periodic_status)
   {
      /* RTE Call to Stop Periodic Msg for Normal Interface */
   }
   else
   {
      /* RTE Call for Normal Mode for Normal/Default Interface */
   }
}

/*****************************************************************************
 *. Name: SWC_XCP_Update_PCAN_Stop_Periodic_Cmnd()
 *.
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *. Return Value: None
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
static void SWC_XCP_Update_PCAN_Stop_Periodic_Cmnd(void)
{
   if (((uint8_t)XCP_STOP_MSG == xcp_pcan_stop_periodic_status) && (previous_xcp_stop_msg_cmnd_requested == FALSE))
   {
      /* RTE Call to Stop Periodic Msg for PCAN */
      Rte_Call_Rp_PCAN_Srv_DisableAppTx_Operation();
      previous_xcp_stop_msg_cmnd_requested = TRUE;
   }
   else if (((uint8_t)XCP_NORMAL_MSG == xcp_pcan_stop_periodic_status) && (previous_xcp_stop_msg_cmnd_requested == TRUE))
   {
      /* RTE Call for Normal Mode for PCAN */
      Rte_Call_Rp_PCAN_Srv_EnableAppTx_Operation();
      previous_xcp_stop_msg_cmnd_requested = FALSE;
   }
   else
   {
      /* do nothing */
   }
}

/*****************************************************************************
 *. Name: SWC_XCP_Update_VCAN_Stop_Periodic_Cmnd()
 *.
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *. Return Value: None
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
static void SWC_XCP_Update_VCAN_Stop_Periodic_Cmnd(void)
{
   if (((uint8_t)XCP_STOP_MSG == xcp_vcan_stop_periodic_status) && (previous_xcp_stop_msg_cmnd_req_vcan == FALSE))
   {
      /* RTE Call to Stop Periodic Msg for VCAN */
      Rte_Call_Rp_VCAN_Srv_DisableAppTx_Operation();
      previous_xcp_stop_msg_cmnd_req_vcan = TRUE;
   }
   else if (((uint8_t)XCP_NORMAL_MSG == xcp_vcan_stop_periodic_status) && (previous_xcp_stop_msg_cmnd_req_vcan == TRUE))
   {
      /* RTE Call for Normal Mode for VCAN */
      Rte_Call_Rp_VCAN_Srv_EnableAppTx_Operation();
      previous_xcp_stop_msg_cmnd_req_vcan = FALSE;
   }
   else
   {
      /* do nothing */
   }
}

/*****************************************************************************
 *. Name: SWC_XCP_Update_Ethernet_Platform_Stop_Periodic_Cmnd()
 *.
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *. Return Value: None
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
static void SWC_XCP_Update_Ethernet_Platform_Stop_Periodic_Cmnd(void)
{
   if ((uint8_t)XCP_STOP_MSG == xcp_ethernet_platform_stop_periodic_status)
   {
      /* RTE Call to Stop Periodic Msg for Ethernet Platform */
      (void)Rte_Write_Pp_XCP_Ethernet_En_Dis_De_XCP_Ethernet_En_Dis((uint8)(XCP_STOP_MSG));
   }
   else
   {
      /* RTE Call for Normal Mode for Ethernet Platform */
      (void)Rte_Write_Pp_XCP_Ethernet_En_Dis_De_XCP_Ethernet_En_Dis((uint8)(XCP_NORMAL_MSG));
   }
}

/*****************************************************************************
 *. Name: SWC_XCP_Update_Ethernet_Project_Stop_Periodic_Cmnd()
 *.
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *. Return Value: None
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
static void SWC_XCP_Update_Ethernet_Project_Stop_Periodic_Cmnd(void)
{
   if ((uint8_t)XCP_STOP_MSG == xcp_ethernet_project_stop_periodic_status)
   {
      /* RTE Call to Stop Periodic Msg for Ethernet Project */
   }
   else
   {
      /* RTE Call for Normal Mode for Ethernet Project */
   }
}

/*****************************************************************************
 *. Name: Get_XCP_Daq_Info_Ptr()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: volatile uint8_t*
 *. Design Information:
 *. Traces to:
 *. Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
void *Get_XCP_Daq_Info_Ptr(void)
{
   D2M_Msg_T *l_xcp_ipc_ptr = Get_IPC_D2M_Sp_Post_Proc_Buffer();

   XCP_DAQ_Descriptor_Table_T(*p_l_xcp_daq_Variables_Info)[7] =
      (XCP_DAQ_Descriptor_Table_T(*)[7])Get_XCP_Manufacture_Mode_Variables_List_DAQ();

   /* Daq 1 */
   p_l_xcp_daq_Variables_Info[0][0].address          = 0; /*Dwell type not implemented yet*/
   p_l_xcp_daq_Variables_Info[0][0].total_size       = 0;
   p_l_xcp_daq_Variables_Info[0][0].event_channel_no = 0;
   p_l_xcp_daq_Variables_Info[0][0].parameter_size   = 0;

   p_l_xcp_daq_Variables_Info[0][1].address          = (uint32_t)&l_xcp_ipc_ptr->payload.rdd_stream_data.look_data.scan_type;
   p_l_xcp_daq_Variables_Info[0][1].total_size       = 2;
   p_l_xcp_daq_Variables_Info[0][1].event_channel_no = 1;
   p_l_xcp_daq_Variables_Info[0][1].parameter_size   = 2; /* uint16_t */

   p_l_xcp_daq_Variables_Info[0][2].address          = (uint32_t)&l_xcp_ipc_ptr->payload.dsp_timing_data.rdd_time;
   p_l_xcp_daq_Variables_Info[0][2].total_size       = 4;
   p_l_xcp_daq_Variables_Info[0][2].event_channel_no = 1;
   p_l_xcp_daq_Variables_Info[0][2].parameter_size   = 4;

   p_l_xcp_daq_Variables_Info[0][3].address          = (uint32_t)&l_xcp_ipc_ptr->payload.rdd_stream_data.rdd_data.cfar_nf_est[0];
   p_l_xcp_daq_Variables_Info[0][3].total_size       = MAX_RANGE_BINS * 2;
   p_l_xcp_daq_Variables_Info[0][3].event_channel_no = 1;
   p_l_xcp_daq_Variables_Info[0][3].parameter_size   = 2; /* uint16_t */

   p_l_xcp_daq_Variables_Info[0][4].address = (uint32_t)&l_xcp_ipc_ptr->payload.rdd_stream_data.rdd_data.rdd1_max_per_range_bin[0];
   p_l_xcp_daq_Variables_Info[0][4].total_size       = MAX_RANGE_BINS * 2;
   p_l_xcp_daq_Variables_Info[0][4].event_channel_no = 1;
   p_l_xcp_daq_Variables_Info[0][4].parameter_size   = 2; /* uint16_t */

   p_l_xcp_daq_Variables_Info[0][5].address          = (uint32_t)&l_xcp_ipc_ptr->payload.rdd_stream_data.rdd_data.bwdep_cr_resp[0];
   p_l_xcp_daq_Variables_Info[0][5].total_size       = MAX_RANGE_BINS * 4;
   p_l_xcp_daq_Variables_Info[0][5].event_channel_no = 1;
   p_l_xcp_daq_Variables_Info[0][5].parameter_size   = 4; /* uint32_t */

   p_l_xcp_daq_Variables_Info[0][6].address          = (uint32_t)&l_xcp_ipc_ptr->payload.xcp_data.rdd1_xcp_rdop_avg_dbin[0];
   p_l_xcp_daq_Variables_Info[0][6].total_size       = MAX_RANGE_BINS * 2;
   p_l_xcp_daq_Variables_Info[0][6].event_channel_no = 1;
   p_l_xcp_daq_Variables_Info[0][6].parameter_size   = 2; /* uint16_t */

   /* Daq 2 */
   p_l_xcp_daq_Variables_Info[1][0].address          = (uint32_t)&l_xcp_ipc_ptr->payload.xcp_data.rdd1_xcp_rdop_avg_rbin[0];
   p_l_xcp_daq_Variables_Info[1][0].total_size       = MAX_DOPPLER_FFT_SIZE * 2;
   p_l_xcp_daq_Variables_Info[1][0].event_channel_no = 1;
   p_l_xcp_daq_Variables_Info[1][0].parameter_size   = 2; /* uint16_t */

   p_l_xcp_daq_Variables_Info[1][1].address          = 0; /*NA*/
   p_l_xcp_daq_Variables_Info[1][1].total_size       = 0;
   p_l_xcp_daq_Variables_Info[1][1].event_channel_no = 0;
   p_l_xcp_daq_Variables_Info[1][1].parameter_size   = 0;

   p_l_xcp_daq_Variables_Info[1][2].address          = (uint32_t)&l_xcp_ipc_ptr->payload.rdd_stream_data.rdd_data.bwdep_cr_resp[0];
   p_l_xcp_daq_Variables_Info[1][2].total_size       = MAX_RANGE_BINS * 4;
   p_l_xcp_daq_Variables_Info[1][2].event_channel_no = 1;
   p_l_xcp_daq_Variables_Info[1][2].parameter_size   = 4; /* uint32_t */

   p_l_xcp_daq_Variables_Info[1][3].address          = 0; /*NA*/
   p_l_xcp_daq_Variables_Info[1][3].total_size       = 0;
   p_l_xcp_daq_Variables_Info[1][3].event_channel_no = 0;
   p_l_xcp_daq_Variables_Info[1][3].parameter_size   = 0;

   p_l_xcp_daq_Variables_Info[1][4].address          = (uint32_t)&l_xcp_ipc_ptr->payload.rdd_stream_data.rdd_data.rdd1_rdop_amp[0];
   p_l_xcp_daq_Variables_Info[1][4].total_size       = MAX_DETS_FIRST_PASS * 2;
   p_l_xcp_daq_Variables_Info[1][4].event_channel_no = 1;
   p_l_xcp_daq_Variables_Info[1][4].parameter_size   = 2; /* uint16_t */

   p_l_xcp_daq_Variables_Info[1][5].address          = (uint32_t)&l_xcp_ipc_ptr->payload.rdd_stream_data.rdd_data.rdd1_dindx[0];
   p_l_xcp_daq_Variables_Info[1][5].total_size       = MAX_DETS_FIRST_PASS * 2;
   p_l_xcp_daq_Variables_Info[1][5].event_channel_no = 1;
   p_l_xcp_daq_Variables_Info[1][5].parameter_size   = 2; /* uint16_t */

   p_l_xcp_daq_Variables_Info[1][6].address          = (uint32_t)&l_xcp_ipc_ptr->payload.rdd_stream_data.rdd_data.rdd1_rindx[0];
   p_l_xcp_daq_Variables_Info[1][6].total_size       = MAX_DETS_FIRST_PASS * 2;
   p_l_xcp_daq_Variables_Info[1][6].event_channel_no = 1;
   p_l_xcp_daq_Variables_Info[1][6].parameter_size   = 2; /* uint16_t */

   /* Daq 3 */
   p_l_xcp_daq_Variables_Info[2][0].address          = (uint32_t)&l_xcp_ipc_ptr->payload.rdd_stream_data.rdd_data.rdd2_range[0];
   p_l_xcp_daq_Variables_Info[2][0].total_size       = MAX_DETS_FIRST_PASS * 4;
   p_l_xcp_daq_Variables_Info[2][0].event_channel_no = 1;
   p_l_xcp_daq_Variables_Info[2][0].parameter_size   = 4; /* uint32_t */

   p_l_xcp_daq_Variables_Info[2][1].address    = (uint32_t)&l_xcp_ipc_ptr->payload.rdd_stream_data.rdd_data.rdd2_range_rate[0];
   p_l_xcp_daq_Variables_Info[2][1].total_size = MAX_DETS_FIRST_PASS * 4;
   p_l_xcp_daq_Variables_Info[2][1].event_channel_no = 1;
   p_l_xcp_daq_Variables_Info[2][1].parameter_size   = 4; /* uint32_t */

   p_l_xcp_daq_Variables_Info[2][2].address    = (uint32_t)&l_xcp_ipc_ptr->payload.rdd_stream_data.rdd_data.min_chirp_scaling;
   p_l_xcp_daq_Variables_Info[2][2].total_size = 1;
   p_l_xcp_daq_Variables_Info[2][2].event_channel_no = 1;
   p_l_xcp_daq_Variables_Info[2][2].parameter_size   = 1;

   p_l_xcp_daq_Variables_Info[2][3].address          = 0;
   p_l_xcp_daq_Variables_Info[2][3].total_size       = 0;
   p_l_xcp_daq_Variables_Info[2][3].event_channel_no = 0;
   p_l_xcp_daq_Variables_Info[2][3].parameter_size   = 0;

   p_l_xcp_daq_Variables_Info[2][4].address          = 0;
   p_l_xcp_daq_Variables_Info[2][4].total_size       = 0;
   p_l_xcp_daq_Variables_Info[2][4].event_channel_no = 0;
   p_l_xcp_daq_Variables_Info[2][4].parameter_size   = 0;

   p_l_xcp_daq_Variables_Info[2][5].address          = 0;
   p_l_xcp_daq_Variables_Info[2][5].total_size       = 0;
   p_l_xcp_daq_Variables_Info[2][5].event_channel_no = 0;
   p_l_xcp_daq_Variables_Info[2][5].parameter_size   = 0;

   p_l_xcp_daq_Variables_Info[2][6].address          = 0;
   p_l_xcp_daq_Variables_Info[2][6].total_size       = 0;
   p_l_xcp_daq_Variables_Info[2][6].event_channel_no = 0;
   p_l_xcp_daq_Variables_Info[2][6].parameter_size   = 0;

   /* Daq 4 */
   p_l_xcp_daq_Variables_Info[3][0].address          = 0;
   p_l_xcp_daq_Variables_Info[3][0].total_size       = 0;
   p_l_xcp_daq_Variables_Info[3][0].event_channel_no = 0;
   p_l_xcp_daq_Variables_Info[3][0].parameter_size   = 0;

   p_l_xcp_daq_Variables_Info[3][1].address          = 0;
   p_l_xcp_daq_Variables_Info[3][1].total_size       = 0;
   p_l_xcp_daq_Variables_Info[3][1].event_channel_no = 0;
   p_l_xcp_daq_Variables_Info[3][1].parameter_size   = 0;

   p_l_xcp_daq_Variables_Info[3][2].address          = 0;
   p_l_xcp_daq_Variables_Info[3][2].total_size       = 0;
   p_l_xcp_daq_Variables_Info[3][2].event_channel_no = 0;
   p_l_xcp_daq_Variables_Info[3][2].parameter_size   = 0;

   p_l_xcp_daq_Variables_Info[3][3].address          = 0;
   p_l_xcp_daq_Variables_Info[3][3].total_size       = 0;
   p_l_xcp_daq_Variables_Info[3][3].event_channel_no = 0;
   p_l_xcp_daq_Variables_Info[3][3].parameter_size   = 0;

   p_l_xcp_daq_Variables_Info[3][4].address          = (uint32_t) & (Radar_Ctl_Data); /* Radar_Ctl_Data */
   p_l_xcp_daq_Variables_Info[3][4].total_size       = sizeof(Radar_Ctl_Data_T);
   p_l_xcp_daq_Variables_Info[3][4].event_channel_no = 1;
   p_l_xcp_daq_Variables_Info[3][4].parameter_size   = 1;

   p_l_xcp_daq_Variables_Info[3][5].address          = (uint32_t) & (Radar_Ctl_State); /* Radar_Ctl_State */
   p_l_xcp_daq_Variables_Info[3][5].total_size       = sizeof(Radar_Ctl_State_T);
   p_l_xcp_daq_Variables_Info[3][5].event_channel_no = 1;
   p_l_xcp_daq_Variables_Info[3][5].parameter_size   = 1;

   p_l_xcp_daq_Variables_Info[3][6].address          = 0; /* NA */
   p_l_xcp_daq_Variables_Info[3][6].total_size       = 0;
   p_l_xcp_daq_Variables_Info[3][6].event_channel_no = 0;
   p_l_xcp_daq_Variables_Info[3][6].parameter_size   = 0;
   return ((void *)p_l_xcp_daq_Variables_Info);
}

/*****************************************************************************
**. Name: Get_XCP_Force_Radiate_Ptr()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: volatile uint8_t
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
volatile uint8_t *Get_XCP_Force_Radiate_Ptr(void)
{
   return &XCP_Force_Radiate;
}

static Dt_ForceRadiate SWC_XCP_Update_Force_Radiate_Cmd(void)
{
   Dt_ForceRadiate xcp_force_radiate = NO_FORCE;
   if (XCP_FORCE_RADIATE_NORMAL_OPERATION == XCP_Force_Radiate)
   {
      xcp_force_radiate = NO_FORCE;
   }
   else if (XCP_FORCE_RADIATE_ON == XCP_Force_Radiate)
   {
      xcp_force_radiate = FORCE_ON;
   }
   else if (XCP_FORCE_RADIATE_OFF == XCP_Force_Radiate)
   {
      xcp_force_radiate = FORCE_OFF;
   }
   else
   {
   }
   return (xcp_force_radiate);
}

/*****************************************************************************
**. Name: Get_XCP_MMIC_A_ChipID()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t*
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
volatile uint8_t *Get_XCP_MMIC_A_ChipID(void)
{
   XCP_Chip_Id_MMIC_Version = (uint8_t *)Get_Chip_Id_Information_Ptr();

   return (XCP_Chip_Id_MMIC_Version);
}

/*****************************************************************************
**. Name: Get_XCP_MMIC_B_ChipID()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t*
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
volatile uint8_t *Get_XCP_MMIC_B_ChipID(void)
{
   return (NULL_PTR);
}

/*****************************************************************************
**. Name: Get_XCP_MMIC_ChipID_Length()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
uint8_t Get_XCP_MMIC_ChipID_Length(void)
{
   return XCP_CHIP_ID_LENGTH;
}

/*****************************************************************************
**. Name: Get_XCP_Single_Look_Mode()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: XCP_Single_Look_T
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
volatile XCP_Single_Look_T *Get_XCP_Single_Look_Mode(void)
{
   return (&XCP_Single_Look_Mode);
}

/*****************************************************************************
 *. Name: Get_XCP_Raw_ADC_Data()
 *. Shared Variables: None
 *. Parameters: void
 *. Return Value: volatile uint16_t *
 *. Design Information:
 *. Traces to:
 *. Section :
 *. JIRA/Plastic Task: DNP-5361
 *****************************************************************************/
volatile uint16_t *Get_XCP_Raw_ADC_Data(void)
{
   Rte_Read_Rp_RawAdc_Data_UnFiltered_RawAdcDataUnfiltered(&XCP_Raw_Adc_Data_UnFilt);
   xcp_adc_validity_flag_status = XCP_Raw_Adc_Data_UnFilt.Validity_Flag;
   return ((uint16_t *)&XCP_Raw_Adc_Data_UnFilt);
}

/*. Name: Get_XCP_Raw_ADC_Filitered_Data()
 *. Shared Variables: None
 *. Parameters:
 *. Return Value: volatile void
 *. Design Information:
 *. Traces to:
 *. Section :
 *. JIRA/Plastic Task:
 *****************************************************************************/

void *Get_XCP_Raw_ADC_Filitered_Data(void)
{
   (void)Rte_Read_Rp_RawAdc_Data_Filtered_De_RawAdcData(&XCP_Raw_Adc_Filtered_Data);
   xcp_adc_validity_flag_status = CODED_TRUE;
   return ((void *)&XCP_Raw_Adc_Filtered_Data);
}

uint8_t Get_XCP_Num_Analog_Inputs(void)
{
   return (XCP_Analog_Inputs);
}

uint8_t *Get_XCP_ADC_Trigger_Ptr(void)
{
   return (&xcp_adc_trigger_flag);
}

uint8_t *Get_XCP_ADC_Validity_Flag_Ptr(void)
{
   return (&xcp_adc_validity_flag_status);
}

/*****************************************************************************
 *. Name: Get_XCP_Operation_Mode_Ptr()
 *.
 *.
 *. Shared Variables: None
 *.
 *. Parameters:  None
 *.
 *. Return Value: uint8_t
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/

uint8_t *Get_XCP_Operation_Mode_Ptr(void)
{
   /* No specific func defined from Project so full implementation is not done*/
   (void)Rte_Write_Pp_XCP_Op_Mode_De_XCP_Op_Mode((Idt_XCP_Op_Mode_T)xcp_operation_mode);
   return (&xcp_operation_mode);
}

/*****************************************************************************
**. Name: Get_XCP_Tx_Temperature_Data()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: int32_t *
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
volatile int16_t *Get_XCP_Tx_Temperature_Data(void)
{
   (void)Rte_Read_Rp_MMIC_Temperature_De_MMIC_Temperature(&XCP_Tx_Temp);

   return ((volatile int16_t *)&(XCP_Tx_Temp));
}
/*****************************************************************************
**. Name: Get_XCP_Num_Tx_Sensors()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
uint8_t Get_XCP_Num_Tx_Sensors(void)
{
   /*(void)Rte_Read_Rp_MMIC_Count_De_MMIC_Count(&XCP_Num_Tx_Sensors);*/

   return (XCP_Num_Tx_Sensors);
}

/*****************************************************************************
**. Name: Get_XCP_MCU_Temperature_Data()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: float32_t *
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
volatile float32_t *Get_XCP_MCU_Temperature_Data(void)
{
   (void)Rte_Call_CS_ThermMonTemp_Read(IMMEDIATE_TEMPERATURES_CELCIUS, &XCP_Mcu_Temp);
   return ((volatile float32_t *)&XCP_Mcu_Temp);
}

/*****************************************************************************
**. Name: Get_XCP_Num_MCU_Sensors()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
uint8_t Get_XCP_Num_MCU_Sensors(void)
{
   (void)Rte_Read_Rp_MCU_Sensor_Count_De_MCU_Sensor_Count(&XCP_Num_Mcu_Sensors);
   return (XCP_Num_Mcu_Sensors);
}

/*****************************************************************************
**. Name: Get_XCP_CW_Mode_Ptr()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t
*. Design Information:
*. Traces to:
*. Section :
*.
*. JIRA/Plastic Task: DNP-5861
*****************************************************************************/
uint8_t *Get_XCP_CW_Mode_Ptr(void)
{
   (void)Rte_Write_Pp_XCP_CW_Mode_De_XCP_CW_Mode(XCP_CW_Mode);
   return (&XCP_CW_Mode);
}

/*****************************************************************************
 *. Name: SWC_XCP_Update_Inject_Fault_Cmnd()
 *.
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *. Return Value: None
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
static void SWC_XCP_Update_Inject_Fault_Cmnd(void)
{
   const XCP_Fault_Inj_Handler_T *fault_handlers = NULL; /*Fault handlers for selected domain*/
   uint8_t fault_count                           = 0U;   /*Array size for selected domain - used as FT upper bound*/
   uint8_t xcp_sys_domain_index                  = 0U;   /*System domain index validated by BB*/
   uint8_t xcp_failure_type                      = 0U;   /*FT value == direct array index (sparse table)*/
   uint8_t xcp_inject_control                    = 0U;

   if (CODED_TRUE == xcp_inject_fault.xcp_cmd_injection_recvd)
   {
      xcp_sys_domain_index = xcp_inject_fault.xcp_sys_domain;   /*System domain index validated by BB*/
      xcp_failure_type     = xcp_inject_fault.xcp_failure_type; /*FT value == direct array index (sparse table)*/
      xcp_inject_control   = xcp_inject_fault.xcp_inject_control;

      /* Copy to RTE-facing global for external visibility */
      xcp_dt_fault_injection.Sys_Domain     = xcp_sys_domain_index;
      xcp_dt_fault_injection.Failure_Type   = xcp_failure_type;
      xcp_dt_fault_injection.Inject_Control = xcp_inject_control;

      if (xcp_sys_domain_index < NUM_ELEMS(Fault_Domain_Table)) /*Sys Domain check: strict < to avoid OOB access*/
      {
         fault_handlers = Fault_Domain_Table[xcp_sys_domain_index].xcp_fault_handlers;
         fault_count    = Fault_Domain_Table[xcp_sys_domain_index].xcp_fault_count; /*fault_count == array size*/

         /*Handler table is sparse: each FT value maps directly to its array index (reserved slots hold NULL ptrs)*/
         if ((NULL != fault_handlers) && (xcp_failure_type < fault_count)) /*NULL guard + OOB guard*/
         {
            if (NULL != fault_handlers[xcp_failure_type].xcp_fault_trigger_rte_fun_ptr) /*Skip reserved NULL entries*/
            {
               fault_handlers[xcp_failure_type].xcp_fault_trigger_rte_fun_ptr(xcp_inject_control,
                                                                              xcp_failure_type); /*Trigger Fault*/
            }
         }
      }
      else
      {
         /* Requested Domain is not configured in Fault Domain Table */
      }

      xcp_inject_fault.xcp_cmd_injection_recvd = CODED_FALSE;
   }
}

/*****************************************************************************
 *. Name: Get_XCP_Inject_Fault_Data()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: uint8_t*
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
XCP_Inject_Fault_T *Get_XCP_Inject_Fault_Data(void)
{
   return (&xcp_inject_fault);
}

/*****************************************************************************
 *. Name: Get_XCP_Fault_Config_Table()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: const XCP_Fault_Injection_Config_Table_T*
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
const XCP_Fault_Injection_Config_Table_T *Get_XCP_Fault_Config_Table(void)
{
   return (Fault_Domain_Table);
}
/*****************************************************************************
 *. Name: Get_XCP_Read_Hardware_Version()
 *.
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *. Return Value: None
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/

uint8_t *Get_XCP_Read_Hardware_Version(void)
{
   // Rte_Read_Rp_BoardRevision_Xcp_De_BoardRevision_Xcp(&xcp_read_hardware_version);
   xcp_read_hardware_version = (uint8_t)Get_Board_Revision();
   return (&xcp_read_hardware_version);
}

/*****************************************************************************
 *. Name: Get_XCP_Clear_Faults_Ptr()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: volatile uint8_t *
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
volatile uint8_t *Get_XCP_Clear_Faults_Ptr(void)
{
   return (&xcp_clear_faults);
}

/*****************************************************************************
**. Name: SWC_XCP_Update_Clear_Faults_Cmnd()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: void
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
static void SWC_XCP_Update_Clear_Faults_Cmnd(void)
{
   if (CODED_TRUE == xcp_clear_faults)
   {
      Clear_Platform_Fault_Arrays();
      Clear_Cust_Fault_Arrays();
      xcp_clear_faults = CODED_FALSE;
   }
}

/*****************************************************************************
 *. Name: Get_XCP_ITV_ADC_State()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: uint8_t*
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
uint8_t *Get_XCP_ITV_ADC_State(void)
{
   return (&XCP_Itv_ADC_State);
}

/*****************************************************************************
 *. Name: Get_XCP_Get_Mcu_Id_Ptr()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: uint8_t*
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
volatile uint8_t *Get_XCP_MCU_ID_Ptr(void)
{
   uint32_t xcp_mcu_id = 0U;

   /* read from specific otp address*/
   xcp_mcu_id = *((uint32_t *)OTP_MCU_ID_ADDR1);
   /*Action point -  Need to add an rte call or global variables to read the ID */
   XCP_Mcu_ID.MCU_ID[0] = (uint8_t)(((xcp_mcu_id) >> 24U) & 0xFF);
   XCP_Mcu_ID.MCU_ID[1] = (uint8_t)(((xcp_mcu_id) >> 16U) & 0xFF);
   XCP_Mcu_ID.MCU_ID[2] = (uint8_t)(((xcp_mcu_id) >> 8U) & 0xFF);
   XCP_Mcu_ID.MCU_ID[3] = (uint8_t)((xcp_mcu_id)&0xFF);
   /* read from specific otp address*/
   xcp_mcu_id           = *((uint32_t *)OTP_MCU_ID_ADDR2);
   XCP_Mcu_ID.MCU_ID[4] = (uint8_t)(((xcp_mcu_id) >> 24U) & 0xFF);
   XCP_Mcu_ID.MCU_ID[5] = (uint8_t)(((xcp_mcu_id) >> 16U) & 0xFF);
   XCP_Mcu_ID.MCU_ID[6] = (uint8_t)(((xcp_mcu_id) >> 8U) & 0xFF);
   XCP_Mcu_ID.MCU_ID[7] = (uint8_t)((xcp_mcu_id)&0xFF);
   /* read from specific otp address*/
   xcp_mcu_id            = *((uint32_t *)OTP_MCU_ID_ADDR3);
   XCP_Mcu_ID.MCU_ID[8]  = (uint8_t)(((xcp_mcu_id) >> 24U) & 0xFF);
   XCP_Mcu_ID.MCU_ID[9]  = (uint8_t)(((xcp_mcu_id) >> 16U) & 0xFF);
   XCP_Mcu_ID.MCU_ID[10] = (uint8_t)(((xcp_mcu_id) >> 8U) & 0xFF);
   XCP_Mcu_ID.MCU_ID[11] = (uint8_t)((xcp_mcu_id)&0xFF);

   return ((volatile uint8_t *)XCP_Mcu_ID.MCU_ID);
}

/*****************************************************************************
 *. Name: Get_XCP_Unique_ID_Ptr()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: volatile uint8_t*
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
volatile uint8_t *Get_XCP_Unique_ID_Ptr(void)
{
   /*Action point - Need to add an rte call or global variables to read the ID */
   return (NULL);
}

/*****************************************************************************
 *. Name: Get_XCP_Software_Version()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *. Return Value: uint8_t**
 *. Design Information:
 *. Traces to:
 *.            Section :
 *. JIRA/Plastic Task:
 *****************************************************************************/
uint8_t **Get_XCP_Software_Version(void)
{
   volatile const Application_Version_T *app_ver_ptr = Get_Application_Version();
   volatile const Bootloader_Version_T *blr_ver_ptr  = Get_Bootloader_Version();
   /* Read AL Radar SW Versions */
   Idt_SW_Version_Info_T xcp_cust_version;
   Rte_Read_Rp_SW_Version_Info_De_SW_Version_Info(&xcp_cust_version);

   XCP_Cal_Version.USC_MajorVersion     = Get_USC_Cal_Major();
   XCP_Cal_Version.USC_PlatformRevision = Get_USC_Cal_Minor();
   XCP_Cal_Version.USC_Compatablity     = Get_USC_Cal_Platform();
   XCP_Cal_Version.SMC_MajorVersion     = Get_SMC_Cal_Major();
   XCP_Cal_Version.SMC_PlatformRevision = Get_SMC_Cal_Minor();
   XCP_Cal_Version.SMC_Compatablity     = Get_SMC_Cal_Platform();

   xcp_sw_ver[XCP_PLT_SW_VER]      = (uint8_t *)(&app_ver_ptr->major);
   xcp_sw_ver[XCP_PLT_BL_VER]      = (uint8_t *)blr_ver_ptr;
   xcp_sw_ver[XCP_SMC_VER]         = (uint8_t *)&XCP_Cal_Version.SMC_MajorVersion;
   xcp_sw_ver[XCP_USC_VER]         = (uint8_t *)&XCP_Cal_Version.USC_MajorVersion;
   xcp_sw_ver[XCP_CUST_SW_VER]     = (uint8_t *)&xcp_cust_version.SwReleaseRevision;
   xcp_sw_ver[XCP_CUSTOMER_BL_VER] = (uint8_t *)&xcp_cust_version.FBLMajorRevision;
   xcp_sw_ver[XCP_CUSTOMER_BM_VER] = (uint8_t *)&xcp_cust_version.BMMajorRevision;
   xcp_sw_ver[XCP_AUTOSAR_VER]     = (uint8_t *)&xcp_cust_version.ASRMajorRevision;
   return ((uint8_t **)&xcp_sw_ver);
}

/*****************************************************************************
 *. Name: Get_XCP_Cust_SW_Version()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: uint8_t**
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
uint8_t **Get_XCP_Cust_SW_Version(void)
{
   return (NULL);
}

/*****************************************************************************
 *. Name: Get_XCP_En_Cust_Sw_Len()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: uint8_t
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
uint8_t Get_XCP_En_Cust_Sw_Len(void)
{
   /* interface to read customer */
   return (XCP_En_Cust_Sw_Len);
}

/*****************************************************************************
 *. Name: Get_XCP_Customer_ID()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: uint8_t
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
uint8_t Get_XCP_Customer_ID(void)
{
   /* XCP_Customer_Id = (uint8_t)NISSAN_GEN5; */
   return (XCP_Customer_Id);
}

/*****************************************************************************

*. Name: Get_XCP_Memory_Fault_Override()
*. Shared Variables: None
*. Parameters:
*. Return Value: volatile XCP_Fault_Override_T*
*. Design Information:
*. Traces to:
*. Section :
*. JIRA/Plastic Task:

*****************************************************************************/
volatile XCP_Fault_Override_T *Get_XCP_Memory_Fault_Override(void)
{
   return ((volatile XCP_Fault_Override_T *)&XCP_FaultOverride);
}

/*****************************************************************************
 *. Name: SWC_XCP_Update_Fault_table()
 *.
 *. Shared Variables: None
 *.
 *. Parameters: None
 *. Return Value:  None
 *.
 *. Design Information:
 *. Traces to:
 *. Section :
 *.
 *. JIRA/Plastic Task: DNP - 4134
 *****************************************************************************/
static void SWC_XCP_Update_Fault_table(void)
{
   (void)Rte_Write_Pp_XCP_Fault_Override_De_XCP_Fault_Override((const Idt_XCP_Fault_Override_T *)&XCP_FaultOverride);
   XCP_FaultOverride.action   = 0;
   XCP_FaultOverride.bit_pos  = 0;
   XCP_FaultOverride.byte_pos = 0;
}

/*****************************************************************************
 *. Name: Get_XCP_Num_Fault_Bytes()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: volatile uint8_t
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
uint8_t Get_XCP_Num_Fault_Bytes(void)
{
   return ((uint8_t)sizeof(Customer_fault_T));
}

/*****************************************************************************

*. Name: Get_XCP_Target_Selection_Num()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t
*. Design Information:
*. Traces to:
*. Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
uint8_t Get_XCP_Target_Selection_Num(void)

{
   return ((uint8_t)XCP_NO_OF_TARGET_SELECTION);
}

/*****************************************************************************

*. Name: Get_XCP_Max_Num_Of_Range_Bin()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t
*. Design Information:
*. Traces to:
*. Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
uint16_t Get_XCP_Max_Num_Of_Range_Bin(void)
{
   return ((uint16_t)MAX_RANGE_BINS);
}

/*****************************************************************************

*. Name: _()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t
*. Design Information:
*. Traces to:
*. Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
uint16_t Get_XCP_Max_Num_Of_Doppler_Bin(void)
{
   return ((uint16_t)MAX_DOPPLER_FFT_SIZE);
}

/*****************************************************************************

*. Name: Get_XCP_Target_Select_Enable()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t
*. Design Information:
*. Traces to:
*. Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
volatile uint8_t *Get_XCP_Target_Select_Enable(void)

{
   return ((volatile uint8_t *)SWC_Get_XCP_Target_Select_Enable());
}

/*****************************************************************************
 *. Name: Get_XCP_Target_Range_Index()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: volatile uint16_t*
 *. Design Information:
 *. Traces to:
 *. Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
volatile uint16_t *Get_XCP_Target_Range_Index(void)
{
   return ((volatile uint16_t *)SWC_Get_XCP_Target_Range_Idx());
}

/*****************************************************************************
 *. Name: Get_XCP_Target_Doppler_Index()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: volatile uint16_t*
 *. Design Information:
 *. Traces to:
 *. Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
volatile uint16_t *Get_XCP_Target_Doppler_Index(void)
{
   return ((volatile uint16_t *)SWC_Get_XCP_Target_Doppler_Idx());
}

/*****************************************************************************
 *. Name: SWC_Get_XCP_Target_Select_Enable()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: uint16_t
 *. Design Information:
 *. Traces to:
 *. Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
volatile uint8_t *SWC_Get_XCP_Target_Select_Enable(void)
{
   M2D_Msg_T *ptr_ipc_mss_to_dss = (M2D_Msg_T *)Get_MSS_IPC_M2D_Msg_Buffer();
   if (ptr_ipc_mss_to_dss != NULL)
   {
      memcpy(&ptr_ipc_mss_to_dss->payload.xcp_info.xcp_target_select_cmd, &xcp_target_select_cmd, sizeof(xcp_target_select_cmd));
   }
   return (&xcp_target_select_cmd);
}

/*****************************************************************************
 *. Name: SWC_Get_XCP_Target_Range_Idx()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: uint16_t
 *. Design Information:
 *. Traces to:
 *. Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
volatile uint16_t *SWC_Get_XCP_Target_Range_Idx(void)
{
   M2D_Msg_T *ptr_ipc_mss_to_dss = (M2D_Msg_T *)Get_MSS_IPC_M2D_Msg_Buffer();
   if (ptr_ipc_mss_to_dss != NULL)
   {
      memcpy(&ptr_ipc_mss_to_dss->payload.xcp_info.xcp_target_range_idx, &xcp_target_range_idx[0][0],
             sizeof(xcp_target_range_idx));
   }
   return (&xcp_target_range_idx[0][0]);
}

/*****************************************************************************
 *. Name: SWC_Get_XCP_Target_Doppler_Idx()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: uint16_t
 *. Design Information:
 *. Traces to:
 *. Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
volatile uint16_t *SWC_Get_XCP_Target_Doppler_Idx(void)
{
   M2D_Msg_T *ptr_ipc_mss_to_dss = (M2D_Msg_T *)Get_MSS_IPC_M2D_Msg_Buffer();
   if (ptr_ipc_mss_to_dss != NULL)
   {
      memcpy(&ptr_ipc_mss_to_dss->payload.xcp_info.xcp_target_doppler_idx, &xcp_target_doppler_idx[0][0],
             sizeof(xcp_target_doppler_idx));
   }
   return (&xcp_target_doppler_idx[0][0]);
}

/*****************************************************************************

*. Name: Get_XCP_Target_Selection_Num()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t
*. Design Information:
*. Traces to:
*. Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/

uint8_t Get_XCP_Num_Of_Looks(void)
{
#if (XCP_EN_FIFTH_LOOK == 1)
   return ((uint8_t)(NUM_LOOKS - 1));
#else
   return ((uint8_t)NUM_LOOKS);
#endif
}
/*****************************************************************************
**. Name: Get_XCP_NVM_Ptr()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t*
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
volatile uint8_t *Get_XCP_NVM_Ptr(void)
{
   return (&xcp_nvm_status);
}

/*****************************************************************************
**. Name: Get_XCP_NVM_Previous_Operation_Status()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t*
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
volatile uint8_t *Get_XCP_NVM_Previous_Operation_Status(void)
{
   /* (void)Rte_Read_Pp_XCP_Data_Flash_Process_De_Data_Flash_Process(&xcp_nvm_cmnd_status); */
   return ((uint8_t *)&xcp_nvm_cmnd_status); /* project specific implementation required */
}
/*****************************************************************************
 *. Name: Get_XCP_LED_Output_State()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: XCP_LED_Output_Cntrl_T*
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
XCP_LED_Output_Cntrl_T *Get_XCP_LED_Output_State(void)
{
   return (&XCP_Out_Output_State);
}

/*****************************************************************************
 *. Name: Get_XCP_Write_Override_Var()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: volatile uint16_t*
 *. Design Information:
 *. Traces to:
 *. Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
volatile uint16_t *Get_XCP_Write_Override_Var(void)
{
   USC_Cal_T *p_usc_cal_data = Get_USC_Cal_Data(); /*temporary changes yet to get the full details */
   if (p_usc_cal_data != NULL)
   {
      return (&p_usc_cal_data->Signal_Calibrations_Cal.k_sensitivity_SF_USC);
   }
   else
   {
      return NULL;
   }
}

/*****************************************************************************
 *. Name: Get_XCP_Read_Override_Var()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: volatile uint16_t*
 *. Design Information:
 *. Traces to:
 *. Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
volatile uint16_t *Get_XCP_Read_Override_Var(void)
{
   USC_Cal_T *p_usc_cal_data = Get_USC_Cal_Data(); /*temporary changes yet to get the full details */
   if (p_usc_cal_data != NULL)
   {
      return (&p_usc_cal_data->Signal_Calibrations_Cal.k_sensitivity_SF_USC);
   }
   else
   {
      return NULL;
   }
}

/*****************************************************************************
**. Name: Get_XCP_Write_Align_Memory_Ptr() F1 30/ 31
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t*
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
uint8_t **Get_XCP_Write_Align_Memory_Ptr(void)
{
   return ((uint8_t **)&xcp_write_alignment_memory);
}

/*****************************************************************************
**. Name: Get_XCP_Write_Align_Data_Ptr()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t*
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
XCP_Write_Alignment_T *Get_XCP_Write_Align_Data_Ptr(void)
{
   if (CODED_TRUE == xcp_write_alignment.cmd_recived)
   {
      if (XCP_WRITE_ALIGNMENT_TYPE == xcp_write_alignment.sub_cmd)
      {
         xcp_write_alignment.write_status = XCP_WRITE_ALIGNMENT_DONE;
      }
      else if (XCP_WRITE_ALIGNMENT_NVM == xcp_write_alignment.sub_cmd)
      {
         Rte_Read_Rp_NvM_flag_status_Pim_write_status(&xcp_write_alignment.write_nvm_flag);
         if (CODED_TRUE == xcp_write_alignment.write_nvm_flag)
         {
            xcp_write_alignment.write_nvm_flag = CODED_FALSE;
            Rte_Write_Pp_XCP_Alignment_Flag_De_XCP_Alignment_Flag(CODED_FALSE);
            xcp_write_alignment.write_status = XCP_WRITE_ALIGNMENT_DONE;
         }
         else
         {
            xcp_write_alignment.write_status = XCP_WRITE_ALIGNMENT_IDLE;
         }
      }
      else
      {
         // do nothing
      }
   }
   else
   {
      Rte_Write_Pp_XCP_Alignment_Flag_De_XCP_Alignment_Flag(CODED_FALSE);
   }
   return (&xcp_write_alignment);
}
/*****************************************************************************
**. Name: swc_xcp_copy_alignment_bufferto_nvm()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t*
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
static void swc_xcp_copy_alignment_bufferto_nvm(void)
{
   xcp_align_nvm_data.AACurrentAzimuth                       = xcp_align_nvm_temp_data.AACurrentAzimuth;
   xcp_align_nvm_data.AACurrentElevation                     = xcp_align_nvm_temp_data.AACurrentElevation;
   xcp_align_nvm_data.AACurrentRoll                          = xcp_align_nvm_temp_data.AACurrentRoll;
   xcp_align_nvm_data.InitialAlignmentResultAzimuth          = xcp_align_nvm_temp_data.InitialAlignmentResultAzimuth;
   xcp_align_nvm_data.InitialAlignmentResultElevation        = xcp_align_nvm_temp_data.InitialAlignmentResultElevation;
   xcp_align_nvm_data.InitialAlignmentResultRoll             = xcp_align_nvm_temp_data.InitialAlignmentResultRoll;
   xcp_align_nvm_data.InitialLastSuccessfulAlignmentMode     = xcp_align_nvm_temp_data.InitialLastSuccessfulAlignmentMode;
   xcp_align_nvm_data.ElevationUpdates                       = xcp_align_nvm_temp_data.ElevationUpdates;
   xcp_align_nvm_data.AzimuthUpdates                         = xcp_align_nvm_temp_data.AzimuthUpdates;
   xcp_align_nvm_data.RollUpdates                            = xcp_align_nvm_temp_data.RollUpdates;
   xcp_align_nvm_data.InitialAlignmentResultElevationUpdates = xcp_align_nvm_temp_data.InitialAlignmentResultElevationUpdates;
   xcp_align_nvm_data.InitialAlignmentResultHostSpeedCompensationFactor =
      xcp_align_nvm_temp_data.InitialAlignmentResultHostSpeedCompensationFactor;
   xcp_align_nvm_data.HostSpeedCompensationFactor          = xcp_align_nvm_temp_data.HostSpeedCompensationFactor;
   xcp_align_nvm_data.InitialAlignmentResultAzimuthUpdates = xcp_align_nvm_temp_data.InitialAlignmentResultAzimuthUpdates;
   xcp_align_nvm_data.InitialAlignmentResultRollUpdates    = xcp_align_nvm_temp_data.InitialAlignmentResultRollUpdates;
}

/*****************************************************************************
**. Name: SWC_XCP_Update_Write_Alignment()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t*
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
static void SWC_XCP_Update_Write_Alignment(void)
{
   if (xcp_write_alignment.cmd_recived == CODED_TRUE)
   {
      if (XCP_WRITE_ALIGNMENT_TYPE == xcp_write_alignment.sub_cmd)
      {
         /* Call respective RTE */
         Rte_Write_Pp_Alignment_Type_Alignment_Type(xcp_select_alignment_typedic_status);
      }
      else if (XCP_WRITE_ALIGNMENT_NVM == xcp_write_alignment.sub_cmd)
      {
         /*Flag indicating write is done*/
         xcp_write_alignment.write_nvm_flag = CODED_TRUE;
         swc_xcp_copy_alignment_bufferto_nvm();
         Rte_Write_Pp_Alignment_Write_NvM_Data_Write_Alignment_NvM(&xcp_align_nvm_data);
         Rte_Write_Pp_XCP_Alignment_Flag_De_XCP_Alignment_Flag(CODED_TRUE);
      }
      else
      {
         // do nothing
      }
   }
   else
   {
      // do nothing
   }
}

/*****************************************************************************
**. Name: swc_xcp_copy_alignment_nvmto_buffer()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t*
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
static void swc_xcp_copy_alignment_nvmto_buffer(void)
{
   xcp_align_nvm_temp_read.AACurrentAzimuth                       = xcp_nvm_read_data.AACurrentAzimuth;
   xcp_align_nvm_temp_read.AACurrentElevation                     = xcp_nvm_read_data.AACurrentElevation;
   xcp_align_nvm_temp_read.AACurrentRoll                          = xcp_nvm_read_data.AACurrentRoll;
   xcp_align_nvm_temp_read.InitialAlignmentResultAzimuth          = xcp_nvm_read_data.InitialAlignmentResultAzimuth;
   xcp_align_nvm_temp_read.InitialAlignmentResultElevation        = xcp_nvm_read_data.InitialAlignmentResultElevation;
   xcp_align_nvm_temp_read.InitialAlignmentResultRoll             = xcp_nvm_read_data.InitialAlignmentResultRoll;
   xcp_align_nvm_temp_read.InitialLastSuccessfulAlignmentMode     = xcp_nvm_read_data.InitialLastSuccessfulAlignmentMode;
   xcp_align_nvm_temp_read.ElevationUpdates                       = xcp_nvm_read_data.ElevationUpdates;
   xcp_align_nvm_temp_read.AzimuthUpdates                         = xcp_nvm_read_data.AzimuthUpdates;
   xcp_align_nvm_temp_read.RollUpdates                            = xcp_nvm_read_data.RollUpdates;
   xcp_align_nvm_temp_read.InitialAlignmentResultElevationUpdates = xcp_nvm_read_data.InitialAlignmentResultElevationUpdates;
   xcp_align_nvm_temp_read.InitialAlignmentResultHostSpeedCompensationFactor =
      xcp_nvm_read_data.InitialAlignmentResultHostSpeedCompensationFactor;
   xcp_align_nvm_temp_read.HostSpeedCompensationFactor          = xcp_nvm_read_data.HostSpeedCompensationFactor;
   xcp_align_nvm_temp_read.InitialAlignmentResultAzimuthUpdates = xcp_nvm_read_data.InitialAlignmentResultAzimuthUpdates;
   xcp_align_nvm_temp_read.InitialAlignmentResultRollUpdates    = xcp_nvm_read_data.InitialAlignmentResultRollUpdates;
   AlignmentModeOut                                             = xcp_nvm_read_data.AlignmentModeOut;
}

/*****************************************************************************
**. Name: swc_xcp_copy_align_auto_to_buffer()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t*
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
static void swc_xcp_copy_align_init_to_buffer(void)
{
   xcp_align_init_read.AlignmentAzimuth          = xcp_read_align_intial_res.AlignmentAzimuth;
   xcp_align_init_read.AlignmentElevation        = xcp_read_align_intial_res.AlignmentElevation;
   xcp_align_init_read.AzimuthStd                = xcp_read_align_intial_res.AzimuthStd;
   xcp_align_init_read.ElevationStd              = xcp_read_align_intial_res.ElevationStd;
   xcp_align_init_read.CalTime                   = xcp_read_align_intial_res.CalTime;
   xcp_align_init_read.AlignmentStaticStatus     = xcp_read_align_intial_res.AlignmentStaticStatus;
   xcp_align_init_read.AlignmentServiceStatus    = xcp_read_align_intial_res.AlignmentServiceStatus;
   xcp_align_init_read.AlignmentShortTrackStatus = xcp_read_align_intial_res.AlignmentShortTrackStatus;
   xcp_align_init_read.ProgressPercent           = xcp_read_align_intial_res.ProgressPercent;
   xcp_align_init_read.AlignmentError            = xcp_read_align_intial_res.AlignmentError;
   xcp_align_init_read.AlignmentRoll             = xcp_read_align_intial_res.AlignmentRoll;
   xcp_align_init_read.RollStd                   = xcp_read_align_intial_res.RollStd;
}

static void swc_xcp_copy_align_auto_to_buffer(void)
{
   xcp_align_auto_read.StartAzimuth                 = xcp_read_auto_align_res.StartAzimuth;
   xcp_align_auto_read.StartElevation               = xcp_read_auto_align_res.StartElevation;
   xcp_align_auto_read.AACurrentAzimuth             = xcp_read_auto_align_res.AACurrentAzimuth;
   xcp_align_auto_read.AACurrentElevation           = xcp_read_auto_align_res.AACurrentElevation;
   xcp_align_auto_read.AAAzimuthStd                 = xcp_read_auto_align_res.AAAzimuthStd;
   xcp_align_auto_read.AAElevationStd               = xcp_read_auto_align_res.AAElevationStd;
   xcp_align_auto_read.AzimuthError_positiveRead    = xcp_read_auto_align_res.AzimuthError_positiveRead;
   xcp_align_auto_read.AzimuthError_negativeRead    = xcp_read_auto_align_res.AzimuthError_negativeRead;
   xcp_align_auto_read.ElevationError_positive_Read = xcp_read_auto_align_res.ElevationError_positive_Read;
   xcp_align_auto_read.ElevationError_negative_Read = xcp_read_auto_align_res.ElevationError_negative_Read;
   xcp_align_auto_read.RollError_negative           = xcp_read_auto_align_res.RollError_negative;
   xcp_align_auto_read.StartRoll                    = xcp_read_auto_align_res.StartRoll;
   xcp_align_auto_read.AACurrentRoll                = xcp_read_auto_align_res.AACurrentRoll;
   xcp_align_auto_read.AARollStd                    = xcp_read_auto_align_res.AARollStd;
   xcp_align_auto_read.RollError_positive_Read      = xcp_read_auto_align_res.RollError_positive_Read;

   xcp_align_auto_read_2.AlignmentAutoStatus        = xcp_read_auto_align_res.AlignmentAutoStatus;
   xcp_align_auto_read_2.AutoAlignmentFailRootCause = xcp_read_auto_align_res.AutoAlignmentFailRootCause;
}

/*****************************************************************************
**. Name: Get_XCP_Read_Align_Memory_Ptr()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t*
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
uint8_t **Get_XCP_Read_Align_Memory_Ptr(void)
{
   Rte_Read_Rp_Alignment_NvM_Read_Record_De_Write_Alignment_NvM_Data(&xcp_nvm_read_data);
   swc_xcp_copy_alignment_nvmto_buffer();
   Rte_Read_Rp_Auto_Alignment_Data_Auto_Alignment_Data(&xcp_read_auto_align_res);
   swc_xcp_copy_align_auto_to_buffer();
   Rte_Read_Rp_Initial_Alignment_Result_Initial_Alignment_Result(&xcp_read_align_intial_res);
   swc_xcp_copy_align_init_to_buffer();
   Rte_Read_Rp_initial_Alignment_Perform_Result_initial_Alignment_Perform(&xcp_read_align_perf_res);
   return ((uint8_t **)&xcp_Read_alignment_memory);
}

/*****************************************************************************
 *. Name: Get_XCP_History_Table_Ptr()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: volatile uint8_t*
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
volatile uint8_t *Get_XCP_History_Table_Ptr(void)
{
   //(void)Rte_Read_Rp_HistoryFaultTable_De_HistoryFaultTable(History_Fault_Table);
   Xcp_History_Fault_Table = Get_Customer_History_Fault_Table();
   return ((uint8_t *)Xcp_History_Fault_Table);
}

/*****************************************************************************
 *. Name: Get_XCP_Active_Latched_Table_Ptr()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: volatile uint8_t*
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
volatile uint8_t *Get_XCP_Active_Latched_Table_Ptr(void)
{
   //(void)Rte_Read_Rp_Active_Fault_Latch_Table_De_ActiveFaultLatchTable(Active_Fault_Latched_Table);
   Xcp_Active_Fault_Latched_Table = Get_Customer_Active_Fault_Latched_Table();
   return ((uint8_t *)Xcp_Active_Fault_Latched_Table);
}

/*****************************************************************************
 *. Name: Get_XCP_Active_Table_Ptr()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: volatile uint8_t*
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
volatile uint8_t *Get_XCP_Active_Table_Ptr(void)
{
   //(void)Rte_Read_Rp_Active_Fault_Table_De_ActiveFaultTable(Appl_Active_Fault_Table);
   Xcp_Appl_Active_Fault_Table = Get_Customer_Active_Fault_Table();
   return ((uint8_t *)Xcp_Appl_Active_Fault_Table);
}

/*****************************************************************************
 *. Name: Get_XCP_Fault_Test_Completed()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: volatile uint8_t*
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
volatile uint8_t *Get_XCP_Fault_Test_Completed(void)
{
   // Rte_Read_Rp_Fault_Test_Complete_Table_De_FaultTestCompleteTable(Fault_Test_Completed_Table);
   Xcp_Fault_Test_Completed_Table = Get_Customer_Fault_Test_Completed_Table();
   return ((uint8_t *)Xcp_Fault_Test_Completed_Table);
}
/*****************************************************************************
 *. Name: Get_XCP_Cust_Checksum(void)
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: uint8_t**
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
uint8_t **Get_XCP_Software_Checksum(void)
{
   /*uint8_t idx = 0;
   for (idx = 0; idx < 2; idx++)
   {
      xcp_checksum[XCP_USC_CHKSM + idx] = (uint8_t *)Get_Calibrations_Checksum(idx);
   }
   (void)Rte_Read_Rp_Application_Checksum_De_Application_Checksum(&XCP_SW_Appl_Checksum);
   (void)Rte_Read_Rp_Primary_Bootloader_Checksum_De_Primary_Bootloader_Checksum(&XCP_SW_Boot_Checksum);
   (void)Rte_Read_Rp_USC_Checksum_De_USC_Checksum(&XCP_Cal_USC_CheckSum);
   (void)Rte_Read_Rp_SMC_Checksum_De_SMC_Checksum(&XCP_Cal_SMC_CheckSum);*/ /*in future if RTE is updated use this*/

   (void)Rte_Read_Rp_Keep_Alive_Checksum_De_Keep_Alive_Checksum(&XCP_Keep_Alive_Checksum);
   xcp_checksum[XCP_KEEP_ALIVE_CHKSM] = (uint8_t *)&XCP_Keep_Alive_Checksum;
   /* Tkey Checksum */
   xcp_checksum[XCP_USC_CHKSM] = (uint8_t *)Get_Calibrations_Checksum(0U);
   xcp_checksum[XCP_SMC_CHKSM] = (uint8_t *)Get_Calibrations_Checksum(1U);

   return ((uint8_t **)&xcp_checksum);
}
/*****************************************************************************
 *. Name: Get_XCP_Cust_Checksum(void)
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: uint8_t**
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
uint8_t **Get_XCP_Cust_Checksum(void)
{
   return (NULL);
}
/*****************************************************************************
 *. Name: Get_XCP_Num_Cust_Spec_Checksum(void)
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: uint8_t
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
uint8_t Get_XCP_Num_Cust_Spec_Checksum(void)
{
   return ((uint8_t)0U);
}

/*****************************************************************************
**. Name: SWC_XCP_Update_Write_DID()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t*
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/

static void SWC_XCP_Update_Write_DID(void)
{
   if (xcp_did_cmd_recvd == CODED_TRUE)
   {
      (void)Rte_Write_Pp_XCP_DID_CMD_De_XCP_DID_CMD(&Xcp_Did_Write_Data);
      xcp_did_cmd_recvd = CODED_FALSE;
   }
}
/*****************************************************************************
**. Name: Get_XCP_DID_CMD_Recvd_Ptr()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t*
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
uint8_t *Get_XCP_DID_CMD_Recvd_Ptr(void)
{
   return (&xcp_did_cmd_recvd);
}

/*****************************************************************************
**. Name: Get_XCP_In_DID_ptr()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t*
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
void *Get_XCP_In_DID_ptr(void)
{
   /** Read interface */
   return ((void *)&Xcp_Did_Write_Data);
}

/*****************************************************************************
*. Name: Get_XCP_Out_DID()
*.
+*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t*
. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*****************************************************************************/
void *Get_XCP_Out_DID(void)
{
   (void)Rte_Read_Rp_XCP_DID_RESP_De_XCP_DID_RESP(&Xcp_Did_Read_Data);
   return ((void *)&Xcp_Did_Read_Data);
}

/*****************************************************************************
 *. Name: Get_XCP_Stop_Periodic_message_Ptr()
 *.
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *. Return Value: None
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/

uint8_t **Get_XCP_Stop_Periodic_Message_Ptr(void)
{
   return ((uint8_t **)&xcp_stop_periodic_message_interface);
}

/*****************************************************************************
 *. Name: Get_Xcp_Phase_Rotator_Calibration()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: void
 *. Design Information:
 *. Traces to:
 *. Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/

void Get_Xcp_Phase_Rotator_Calibration(uint8_t cmd)
{
   /* if cmd value 0 = enable
         cmd value 1 = disable */
   boolean phase_rotator_enable[] = {true, false};

   Rte_Write_Pp_XCP_Phase_Rotator_Calibration_De_XCP_Phase_Rotator_Calibration(phase_rotator_enable[cmd]);
}
/*****************************************************************************
 *. Name: Get_Xcp_Phase_Rotator_fptr()
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: void
 *. Design Information:
 *. Traces to:
 *. Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/

Xcp_Phase_Rotator_fptr_T Get_XCP_Phase_Rotator_Fptr(void)
{
   return (&Get_Xcp_Phase_Rotator_Calibration);
}

/*****************************************************************************
 *. Name: SWC_Xcp_Flash_sequence
 *.
 *.
 *. Shared Variables: None
 *.
 *. Parameters:
 *.
 *. Return Value: XCP_CMD_OK          Success.
 *.               XCP_CMD_ERROR RAM   Flash memory erase error
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
static uint8_t SWC_Xcp_Flash_sequence(void)
{
   uint8_t retValue           = XCP_CMD_PENDING; /*Set NRC 1*/
   MemIf_StatusType flsStatus = (MemIf_StatusType)0;
   uint8_t flsEraseStatus     = (uint8_t)E_NOT_OK;

   /* Read the current flash status */
   flsStatus = Fls_GetStatus();

   if ((CODED_TRUE == xcp_usc_smc_data.xcp_usc_smc_check_status) && (MEMIF_IDLE == flsStatus))
   {
      switch (xcp_usc_smc_data.xcp_usc_smc_seq)
      {
         case XCP_USC_SMC_PGM_CLEAR:
            flsEraseStatus = Fls_Erase((uint32_t)((xcp_usc_smc_data.xcp_usc_smc_address) & XCP_FLASH_ADDRESS_MASK),
                                       xcp_usc_smc_data.xcp_usc_smc_size);
            break;
         case XCP_USC_SMC_PGM_WRITE:
            if (XCP_CMD_OK == SWC_Xcp_Program_Access_Check(xcp_flash_wr_page_addr, XCP_FLASH_PAGE_SIZE))
            {
               flsEraseStatus = Fls_Write((uint32_t)(xcp_flash_wr_page_addr & XCP_FLASH_ADDRESS_MASK), xcp_flash_wr_page_data,
                                          XCP_FLASH_PAGE_SIZE);
            }
            else
            {
               retValue = XCP_CMD_OUT_OF_RANGE; /*Set NRC 22*/
            }

            break;
         default:
            break;
      }
      if ((uint8_t)E_OK == flsEraseStatus)
      {
         XCP_Flash_Erase_Prgm_Cmd_Recevied = CODED_TRUE;
      }
      else
      {
         retValue = XCP_CMD_OUT_OF_RANGE; /*Set NRC 22*/
      }
      xcp_usc_smc_data.xcp_usc_smc_check_status = CODED_FALSE;
      xcp_usc_smc_data.xcp_usc_smc_seq          = XCP_USC_SMC_PGM_IDLE;
   }

   return (retValue);
}

/*****************************************************************************
 *. Name: SWC_Xcp_SendNegResp()
 *.
 *.
 *. Shared Variables: None
 *.
 *. Parameters: XcpChannel            The channel from which the data should be send.
 *.             ErrorCode             Pointer to response string.
 *. Return Value:  None
 *.
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
static FUNC(void, XCP_CODE) SWC_Xcp_SendNegResp(Xcp_ChannelType XcpChannel, uint8 ErrorCode)
{
   /* ----- Implementation ----------------------------------------------- */
   /* #10 Prepare a default error response with the error codes as parameter. */
   Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[0]  = XCP_PID_ERR;
   Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrame.b[1]  = ErrorCode;
   Xcp_ChannelInfo[XCP_CHANNEL_IDX].ResponseFrameLength = 0x02;
   (void)XcpChannel;
   Xcp_SendCrm(XCP_CHANNEL_IDX);
}

/*****************************************************************************
 *. Name: SWC_Xcp_Program_Access_Check
 *.
 *.
 *. Shared Variables: None
 *.
 *. Parameters:  addrees              Flash start address to erase
 *.              size                 Length
 *. Return Value: XCP_CMD_OK          Success.
 *.               XCP_CMD_ERROR RAM   Flash memory erase error
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
static FUNC(uint8_t, XCP_CODE) SWC_Xcp_Program_Access_Check(uint32_t address, uint32 size)
{
   uint8_t retValue = XCP_CMD_OK;
   if ((address >= (USC_CAL_PTP_START_ADDR) && (address + ((uint32)size - 1)) <= USC_CAL_PTP_END_ADDR) ||
       ((address >= SMC_CAL_PTP_START_ADDR) && (address + ((uint32)size - 1)) <= SMC_CAL_PTP_END_ADDR))
   {
      retValue = XCP_CMD_OK;
   }
   else
   {
      retValue = XCP_CMD_DENIED;
   }
   return (retValue);
}

/*****************************************************************************
 *. Name: SWC_Xcp_Erase_Flash
 *.
 *.
 *. Shared Variables: None
 *.
 *. Parameters:  addrees              Flash start address to erase
 *.              size                 Length
 *. Return Value: XCP_CMD_OK          Success.
 *.               XCP_CMD_ERROR RAM   Flash memory erase error
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
FUNC(uint8_t, XCP_CODE) SWC_Xcp_Erase_Flash(uint8_t *address, uint32 size)
{
   uint8_t retValue = XCP_CMD_DENIED;

   if (XCP_CMD_OK == SWC_Xcp_Program_Access_Check((uint32_t)address, size))
   {
      /* Flash Clear should be performed only flash algorithm is idle and status of
        flash will be check in 10ms timer */
      WdgM_SetMode(WDGIF_SLOW_MODE, 0); // Use slow mode instead of OFF to maintain DSP monitoring
      /* Flag will be true throughout the program clear and write per request */
      xcp_usc_smc_data.xcp_usc_smc_initialized = CODED_TRUE;
      /* Address of the Flash clear*/
      xcp_usc_smc_data.xcp_usc_smc_address = (uint32_t)address;
      /* Size of the Flash clear*/
      xcp_usc_smc_data.xcp_usc_smc_size = size;
      /* Flag will be true till the Flash status is idle*/
      xcp_usc_smc_data.xcp_usc_smc_check_status = CODED_TRUE;
      /* Current sequence */
      xcp_usc_smc_data.xcp_usc_smc_seq = XCP_USC_SMC_PGM_CLEAR;
      retValue                         = XCP_CMD_PENDING;
   }
   else
   {
      retValue = XCP_CMD_DENIED;
   }
   return (retValue);
}

/*****************************************************************************
 *. Name: SWC_Xcp_Program_Address_Update
 *.
 *.
 *. Shared Variables: None
 *.
 *. Parameters:  addrees              Flash start address to check
 *.
 *. Return Value: void
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
static void SWC_Xcp_Program_Address_Update(uint32_t address)
{
   if (address == USC_CAL_PTP_START_ADDR)
   {
      xcp_flash_wr_page_addr = USC_CAL_PTP_START_ADDR;
   }
   else if (address == SMC_CAL_PTP_START_ADDR)
   {
      xcp_flash_wr_page_addr = SMC_CAL_PTP_START_ADDR;
   }
   else
   {
      xcp_flash_wr_page_addr = xcp_flash_wr_page_addr + XCP_FLASH_PAGE_SIZE;
   }
}

/*****************************************************************************
 *. Name: SWC_Xcp_Program_Flash
 *.
 *.
 *. Shared Variables: None
 *.
 *. Parameters:  addrees              Flash start address to erase
 *.              size                 Length
 *. Return Value: XCP_CMD_OK          Success.
 *.               XCP_CMD_ERROR RAM   Flash memory erase error
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
FUNC(uint8_t, XCP_CODE) SWC_Xcp_Program_Flash(uint8_t *address, uint8_t *data, uint8_t size, uint8_t blockRemainder)
{
   uint8_t retValue = XCP_CMD_ERROR;
   uint8_t index = 0, max_index = 0;
   uint8_t flash_page_size = 0;
   uint32_t flash_page_add = 0;
   flash_page_add          = (uint32_t)address;
   flash_page_size         = (uint8_t)(blockRemainder + size);

   if ((XCP_FLASH_PAGE_SIZE - 1U) == flash_page_size)
   {
      SWC_Xcp_Program_Address_Update(flash_page_add);
      xcp_flash_wr_page_start = TRUE;
      xcp_flash_wr_data_index = 0U;
   }
   else
   {
      /* Do Nothing*/
   }

   if ((TRUE == xcp_flash_wr_page_start) && ((XCP_FLASH_PAGE_SIZE - 1U) == (xcp_flash_wr_data_index + flash_page_size)))
   {
      retValue  = XCP_CMD_OK;
      max_index = (XCP_PROGRAM_CMD_MAX_SIZE(XCP_CHANNEL_IDX) > size) ? (uint8_t)(size + 1U) : size;
      for (index = 0U; index < max_index; index++)
      {
         xcp_flash_wr_page_data[xcp_flash_wr_data_index] = data[index];
         xcp_flash_wr_data_index++;
      }
      if (XCP_FLASH_PAGE_SIZE == xcp_flash_wr_data_index)
      {
         /* Flash write should be performed only flash algorithm is idle and status of
          flash will be check in 10ms timer*/
         /* Flag will be true throughout the program clear and write per request*/
         xcp_usc_smc_data.xcp_usc_smc_initialized = CODED_TRUE;
         /* Current sequence */
         xcp_usc_smc_data.xcp_usc_smc_seq = XCP_USC_SMC_PGM_WRITE;
         /* Flag will be true till the Flash status is idle*/
         xcp_usc_smc_data.xcp_usc_smc_check_status = CODED_TRUE;
         retValue                                  = XCP_CMD_PENDING;
         xcp_flash_wr_page_start                   = FALSE;
      }
      else
      {
         /* Do Nothing*/
      }
   }
   else
   {
      /* Do Nothing*/
   }
   return (retValue);
}

/*****************************************************************************
**. Name: Get_XCP_Transceiver_Calib_Trigger()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t*
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*. JIRA/Plastic Task:
*****************************************************************************/
uint8_t *Get_XCP_Transceiver_Calib_Trigger(void)
{
   (void)Rte_Write_Pp_XCP_RFBIST_Calib_Trigger_De_XCP_RFBIST_Calib_Trigger(xcp_trigger_rfbist_calibration);
   return (&xcp_trigger_rfbist_calibration);
}

/*****************************************************************************
**. Name: Get_XCP_Rfbist_Calib_Status()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: uint8_t*
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*. JIRA/Plastic Task:
*****************************************************************************/
uint8_t Get_XCP_Rfbist_Calib_Status(void)
{
   XCP_Rfbist_Calib_Status = MMIC_Stream.MMIC_Data.RFBIST_Zero_Hr_Ref_Data.Rfbist_Calibration_Status;
   return (XCP_Rfbist_Calib_Status);
}

/*****************************************************************************
**. Name: Read_XCP_Rfbist_Debug_Data()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: none
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*. JIRA/Plastic Task:
*****************************************************************************/
static void SWC_Read_XCP_Rfbist_Debug_Data(void)
{
   uint32_t *ptr = NULL;
   ptr           = (uint32_t *)Get_RF_Inject_RX_Diag_Raw_Value_Ptr();
   /*RF inject rx Diag raw value */
   xcp_rfbist_debug_data[0U].xcp_rfbist_debug_data_ptr = ptr;
   xcp_rfbist_debug_data[0U].xcp_debug_no_of_parameter = 14U;

   ptr += 14U; // ptr increase for next 14 bytes of data
   xcp_rfbist_debug_data[1U].xcp_rfbist_debug_data_ptr = ptr;
   xcp_rfbist_debug_data[1U].xcp_debug_no_of_parameter = 14U;

   ptr += 14U; // ptr increase for next 14 bytes of data
   xcp_rfbist_debug_data[2U].xcp_rfbist_debug_data_ptr = ptr;
   xcp_rfbist_debug_data[2U].xcp_debug_no_of_parameter = 4U;

   /* Rx moise info diag raw value*/
   ptr                                                 = (uint32_t *)Get_RX_Noise_Info_Diag_Raw_Value_Ptr();
   xcp_rfbist_debug_data[3U].xcp_rfbist_debug_data_ptr = ptr;
   xcp_rfbist_debug_data[3U].xcp_debug_no_of_parameter = 8U;

   /* IFVGA Diag Raw value */
   ptr                                                 = (uint32_t *)Get_IFVGA_Diag_Raw_Value_Ptr();
   xcp_rfbist_debug_data[4U].xcp_rfbist_debug_data_ptr = ptr;
   xcp_rfbist_debug_data[4U].xcp_debug_no_of_parameter = 14U;

   ptr += 14U; // ptr increase for next 14 bytes of data
   xcp_rfbist_debug_data[5U].xcp_rfbist_debug_data_ptr = ptr;
   xcp_rfbist_debug_data[5U].xcp_debug_no_of_parameter = 14U;

   ptr += 14U; // ptr increase for next 14 bytes of data
   xcp_rfbist_debug_data[6U].xcp_rfbist_debug_data_ptr = ptr;
   xcp_rfbist_debug_data[6U].xcp_debug_no_of_parameter = 14U;

   ptr += 14U; // ptr increase for next 14 bytes of data
   xcp_rfbist_debug_data[7U].xcp_rfbist_debug_data_ptr = ptr;
   xcp_rfbist_debug_data[7U].xcp_debug_no_of_parameter = 6U;

   /* Lookback Diag Raw value*/
   ptr                                                 = (uint32_t *)Get_Loopback_Diag_Raw_Value_Ptr();
   xcp_rfbist_debug_data[8U].xcp_rfbist_debug_data_ptr = ptr;
   xcp_rfbist_debug_data[8U].xcp_debug_no_of_parameter = 14U;

   ptr += 14U; // ptr increase for next 14 bytes of data
   xcp_rfbist_debug_data[9U].xcp_rfbist_debug_data_ptr = ptr;
   xcp_rfbist_debug_data[9U].xcp_debug_no_of_parameter = 14U;

   ptr += 14U; // ptr increase for next 14 bytes of data
   xcp_rfbist_debug_data[10U].xcp_rfbist_debug_data_ptr = ptr;
   xcp_rfbist_debug_data[10U].xcp_debug_no_of_parameter = 4U;
}

/*****************************************************************************
**. Name: Get_XCP_Rfbist_Debug_Data()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: XCP_RFBIST_Debug_Data_T*
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*. JIRA/Plastic Task:
*****************************************************************************/
XCP_RFBIST_Debug_Data_T *Get_XCP_Rfbist_Debug_Data(uint8_t cmd)
{
   return (&xcp_rfbist_debug_data[cmd]);
}
/*****************************************************************************
**. Name: Get_XCP_Rfbist_Debug_Data()
*.
*. Shared Variables: None
*.
*. Parameters:
*.
*. Return Value: xcp_rfbist_debugdata_ptr*
*. Design Information:
*. Traces to:
*.            Section :
*.
*. JIRA/Plastic Task:
*. JIRA/Plastic Task:
*****************************************************************************/
xcp_rfbist_debugdata_ptr Get_XCP_Rfbist_Debug_Data_ptr(void)
{
   return (Get_XCP_Rfbist_Debug_Data);
}
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
