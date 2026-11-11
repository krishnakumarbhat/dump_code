/*===========================================================================*/
/**
 * @file xcp_bb.c
 *
 *  Add a one line description of the implementation.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (c) 2020 Aptiv. All rights reserved.
 * Confidential - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *   This file contains the implementation of the XCP user commands
 *
 *  XCP Building Block implementation providing initialization and periodic task handling for radar measurement and calibration
 *protocol interface.
 *
 * @section ABBR ABBREVIATIONS:
 *   -  List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     -  Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     -  Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - <a href="https://spo.aptiv.com/sites/0307-eoses/globalregional/ESGW_4-2_PE-SWx_00-01-A02_EN.docx">
 *       ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]</a>
 *     -  Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   -  List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */

/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/

/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/
#include "xcp_bb.h"
#include "xcp_bb_types.h"

/*===========================================================================*\
 * Local Preprocessor #define Constants
\*===========================================================================*/

/*===========================================================================*\
 * Local Preprocessor #define MACROS
\*===========================================================================*/

/*===========================================================================*\
 * Local Type Declarations
\*===========================================================================*/

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/

/*===========================================================================*\
 * Local Object Definitions
\*===========================================================================*/
static XCP_BB_Input_Params_T XCP_BB_Input_Params_Initialise = {
   NULL, /*xcp_operation_mode_ptr*/
   NULL, /*xcp_clear_faults_ptr*/
   NULL, /* xcp_get_raw_adc_data_ptr */
   NULL, /* xcp_get_adc_validity_flag_ptr */
   NULL, /* xcp_get_adc_trigger_flag_ptr */
   0,    /* num_analog_inputs */
   0,    /* num_fault_bytes */
   NULL, /* history_fault_table_ptr */
   NULL, /* active_fault_table_ptr */
   NULL, /* active_fault_latch_table_ptr */
   NULL, /* xcp_force_radiate_ptr */

   NULL, /* xcp_chksm_trigger_flag_ptr */
   0,    /* xcp_chksm_trigger_mode */
   NULL, /* xcp_checksum_ptr */
   NULL, /* xcp_cust_checksum_ptr */
   0,    /* xcp_radar_radiate_cmd */
   NULL, /* xcp_cw_mode_ptr */
   NULL, /* xcp_get_tx_temp_ptr */
   0,    /* xcp_num_mmic */
   NULL, /* xcp_fault_test_completed_ptr */
   NULL, /* xcp_look_mode_ptr */
   0,    /* xcp_num_cust_spec_chcksm */
   0,    /* xcp_radar_init_status */
   0,    /* xcp_num_sw_version_bytes */
   0,    /* xcp_customer_id */
   0,    /* xcp_num_max_dets */
   0,    /* xcp_sw_ver_len */
   NULL, /* xcp_get_mcu_temp_ptr */
   0,    /* xcp_num_mcu_sensor */
   0U,   /*xcp_num_of_looks*/
   0U,   /*xcp_target_selection_num*/
   0U,   /*xcp_max_number_range_bin*/
   0U,   /*xcp_max_number_doppler_bin*/
   NULL, /*xcp_target_select_enable_ptr*/
   NULL, /* xcp_copy_target_report_fptr */
   NULL, /* xcp_look_en_status_fptr */
   0,    /* xcp_MMIC_ChipID_Length */
   0,    /* xcp_current_look */
   NULL, /*xcp_out_set_output_state*/
   NULL, /*xcp_set_override_var_ptr*/
   NULL, /*xcp_get_override_var_ptr*/
   NULL, /* xcp_get_mcu_id_ptr */
   NULL, /* xcp_get_unique_id_ptr */
   NULL, /*xcp_target_range_idx_ptr*/
   NULL, /*xcp_target_doppler_idx_ptr*/

   NULL, /*xcp_chksm_flash_status*/
   NULL, /*xcp_itv_adc_state*/
   NULL, /*xcp_itv_ipc_state*/
   NULL, /*xcp_itv_ipc_event_state*/
   NULL, /*xcp_itv_ipc_value_state*/
   NULL, /*xcp_get_raw_adc_filtered_data_ptr*/
   NULL, /*xcp_fault_override_ptr*/
   NULL, /*xcp_nvm_ptr*/
   NULL, /*xcp_nvm_prev_operation_status_ptr*/
   NULL, /*xcp_sw_ver_ptr*/
   NULL, /*xcp_cust_sw_ver_ptr*/
   NULL, /* xcp_MMIC_A_ChipID_ptr */
   NULL, /*xcp_MMIC_B_ChipID_ptr*/
   NULL, /* xcp_inject_fault_data */
   NULL, /* xcp_interface_cntrl_ptr */
   NULL, /*Get_XCP_Stop_Periodic_Message_Ptr*/
   NULL, /* xcp_bb_daq_info_params_ptr */
   NULL, /*xcp_input_did_ptr*/
   NULL, /*xcp_output_did_ptr*/
   NULL, /*xcp_did_recvd_ptr*/
   NULL, /*xcp_write_align_memory_ptr*/
   NULL, /*xcp_wrtie_align_data_ptr*/
   NULL, /*xcp_read_align_memory_ptr*/
   NULL, /*xcp_tx_rx_gain_phase_value_ptr*/
   NULL, /*xcp_hil_mode_ptr*/
   NULL, /*xcp_read_hardware_version_ptr*/
   NULL, /*xcp_elec_chip_if_id_fptr*/
   NULL, /*xcp_read_electronic_chipid*/
   0,    /* xcp_electronic_chip_id_max */
   NULL, /*xcp_phase_rotator_calib_fptr*/
   NULL, /*xcp_trigger_rfbist_calib_ptr*/
   0,    /*xcp_get_rfbist_calib_status*/
   NULL  /*xcp_rfbist_debug_fptr*/

};

/*===========================================================================*
 * Exported Object Definitions
 *===========================================================================*/
XCP_BB_Input_Params_T *XCP_BB_Input_Params_Ptr = &XCP_BB_Input_Params_Initialise;

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*\
* Function Definitions
\*===========================================================================*/

/**
 * FUNCTION:XCP_BB_Init_Const_Ptr
 *. This function implements initialization of const input parameters
 *
 * \param[in] void
 *
 * \return void
 *
 * \remark
 * \ServID xx
 * \Reentrancy non-reentrant
 * \Synchronism synchronous
 * \Precondition none
 * \Caveats none
 * TRACEABILITY INFO:
 *
 * SDD
 * WorkItem 1 :
 * WorkItem 2 :
 *
 * SRD
 * WorkItem 1 :
 * WorkItem 2 :
 * WorkItem 3 :
 * \\input{XCP_BB_Init_Const_Ptr}
 */

void XCP_BB_Init_Const_Ptr(void)
{
   XCP_BB_Input_Params_T *xcp_bb_input_params = XCP_BB_Input_Params_Ptr;

   /* F1 03 - stop periodic message*/
   xcp_bb_input_params->xcp_stop_periodic_message_ptr = Get_XCP_Stop_Periodic_Message_Ptr();
   /*F1 02 - Force radiate */
   xcp_bb_input_params->xcp_force_radiate_ptr = Get_XCP_Force_Radiate_Ptr();
   /* F1 0F - ITV simulation */
   xcp_bb_input_params->xcp_itv_adc_state = Get_XCP_ITV_ADC_State();
   /* F1 11 - Fault override */
   xcp_bb_input_params->xcp_fault_override_ptr = Get_XCP_Memory_Fault_Override();
   /* F1 04 - clear faults */
   xcp_bb_input_params->xcp_clear_faults_ptr = Get_XCP_Clear_Faults_Ptr();
   /* F1 1F - set output state */
   xcp_bb_input_params->xcp_out_set_output_state = Get_XCP_LED_Output_State();
   /* F1 9B - Phase Rotator Calibration */
   xcp_bb_input_params->xcp_phase_rotator_calib_fptr = Get_XCP_Phase_Rotator_Fptr();
   /* F1 13 - DID command recived*/
   xcp_bb_input_params->xcp_did_recvd_ptr = Get_XCP_DID_CMD_Recvd_Ptr();
   /* Num of fault bytes*/
   xcp_bb_input_params->num_fault_bytes = Get_XCP_Num_Fault_Bytes();
   /* F1 0C - Custemer Id*/
   xcp_bb_input_params->xcp_customer_id = Get_XCP_Customer_ID();
   /* F1 9A */
   xcp_bb_input_params->xcp_max_number_doppler_bin = Get_XCP_Max_Num_Of_Doppler_Bin();
   xcp_bb_input_params->xcp_max_number_range_bin   = Get_XCP_Max_Num_Of_Range_Bin();
   xcp_bb_input_params->xcp_target_selection_num   = Get_XCP_Target_Selection_Num();
   /* F1 0B - single look mode*/
   xcp_bb_input_params->xcp_look_mode_ptr = Get_XCP_Single_Look_Mode();
   /* F1 98 - Get MMIC chip ID*/
   xcp_bb_input_params->xcp_MMIC_ChipID_Length = Get_XCP_MMIC_ChipID_Length();

   /* Address-stable pointers ? address fixed at boot, data changes at source */
   /* ADC */

   xcp_bb_input_params->xcp_get_adc_validity_flag_ptr = Get_XCP_ADC_Validity_Flag_Ptr();
   xcp_bb_input_params->xcp_get_adc_trigger_flag_ptr  = Get_XCP_ADC_Trigger_Ptr();

   /* Function pointers */
   xcp_bb_input_params->xcp_look_en_status_fptr     = Get_XCP_Look_Enable_Status_Fptr();
   xcp_bb_input_params->xcp_copy_target_report_fptr = Get_XCP_Copy_Target_Report_Fptr();

   /* MMIC / CW / operation mode */
   xcp_bb_input_params->xcp_MMIC_A_ChipID_ptr = Get_XCP_MMIC_A_ChipID();

   xcp_bb_input_params->xcp_MMIC_B_ChipID_ptr = Get_XCP_MMIC_B_ChipID();

   /* Fault injection */
   xcp_bb_input_params->xcp_inject_fault_data = Get_XCP_Inject_Fault_Data();
   /* Hardware / ID */
   xcp_bb_input_params->xcp_read_hardware_version_ptr = Get_XCP_Read_Hardware_Version();
   xcp_bb_input_params->xcp_get_mcu_id_ptr            = Get_XCP_MCU_ID_Ptr();
   xcp_bb_input_params->xcp_get_unique_id_ptr         = Get_XCP_Unique_ID_Ptr();
   /* Software version */
   xcp_bb_input_params->xcp_sw_ver_ptr      = Get_XCP_Software_Version();
   xcp_bb_input_params->xcp_cust_sw_ver_ptr = Get_XCP_Cust_SW_Version();

   /* NVM */
   xcp_bb_input_params->xcp_nvm_ptr = Get_XCP_NVM_Ptr();

   /* Override variables */
   xcp_bb_input_params->xcp_set_override_var_ptr = Get_XCP_Write_Override_Var();
   xcp_bb_input_params->xcp_get_override_var_ptr = Get_XCP_Read_Override_Var();

   /* Checksums */
   xcp_bb_input_params->xcp_checksum_ptr      = Get_XCP_Software_Checksum();
   xcp_bb_input_params->xcp_cust_checksum_ptr = Get_XCP_Cust_Checksum();

   /*  Fixed values ? determined by hardware/build config, never change after boot */
   xcp_bb_input_params->num_analog_inputs        = Get_XCP_Num_Analog_Inputs();
   xcp_bb_input_params->xcp_num_mmic             = Get_XCP_Num_Tx_Sensors();
   xcp_bb_input_params->xcp_sw_ver_len           = Get_XCP_En_Cust_Sw_Len();
   xcp_bb_input_params->xcp_num_of_looks         = Get_XCP_Num_Of_Looks();
   xcp_bb_input_params->xcp_num_cust_spec_chcksm = Get_XCP_Num_Cust_Spec_Checksum();

   /* Rfbist debug data */
   xcp_bb_input_params->xcp_rfbist_debug_data_fptr = Get_XCP_Rfbist_Debug_Data_ptr();
}

/**
 * FUNCTION:XCP_BB_Refresh_Dynamic_Data
 *. This function implements initialization of input parameters
 *
 * \param[in] void
 *
 * \return void
 *
 * \remark
 * \ServID xx
 * \Reentrancy non-reentrant
 * \Synchronism synchronous
 * \Precondition none
 * \Caveats none
 * TRACEABILITY INFO:
 *
 * SDD
 * WorkItem 1 :
 * WorkItem 2 :
 *
 * SRD
 * WorkItem 1 :
 * WorkItem 2 :
 * WorkItem 3 :
 * \\input{XCP_BB_Refresh_Dynamic_Data}
 */
void XCP_BB_Refresh_Dynamic_Data(void)
{
   XCP_BB_Input_Params_T *xcp_bb_input_params = XCP_BB_Input_Params_Ptr;

   /* Group C: Dynamic params ? values change at runtime, refreshed every 10ms */
   xcp_bb_input_params->xcp_radar_radiate_cmd        = Get_XCP_Radar_Radiate_Cmd();
   xcp_bb_input_params->xcp_num_max_dets             = Get_XCP_num_max_dets();
   xcp_bb_input_params->xcp_current_look             = Get_XCP_Current_Look();
   xcp_bb_input_params->xcp_radar_init_status        = Get_XCP_Radar_Init_Status();
   xcp_bb_input_params->xcp_trigger_rfbist_calib_ptr = Get_XCP_Transceiver_Calib_Trigger();
   xcp_bb_input_params->xcp_get_rfbist_calib_status  = Get_XCP_Rfbist_Calib_Status();

   /* Target selection */
   xcp_bb_input_params->xcp_target_range_idx_ptr     = Get_XCP_Target_Range_Index();
   xcp_bb_input_params->xcp_target_doppler_idx_ptr   = Get_XCP_Target_Doppler_Index();
   xcp_bb_input_params->xcp_target_select_enable_ptr = Get_XCP_Target_Select_Enable();

   /*ADC*/
   xcp_bb_input_params->xcp_get_raw_adc_data_ptr          = Get_XCP_Raw_ADC_Data();
   xcp_bb_input_params->xcp_get_raw_adc_filtered_data_ptr = Get_XCP_Raw_ADC_Filitered_Data();

   /* DAQ descriptor table */
   xcp_bb_input_params->xcp_bb_daq_info_params_ptr = Get_XCP_Daq_Info_Ptr();

   xcp_bb_input_params->xcp_cw_mode_ptr        = Get_XCP_CW_Mode_Ptr(); /*CW mode */
   xcp_bb_input_params->xcp_operation_mode_ptr = Get_XCP_Operation_Mode_Ptr();
   /* Temperature */
   xcp_bb_input_params->xcp_get_tx_temp_ptr  = Get_XCP_Tx_Temperature_Data();
   xcp_bb_input_params->xcp_get_mcu_temp_ptr = Get_XCP_MCU_Temperature_Data();

   /* NVM */
   xcp_bb_input_params->xcp_nvm_prev_operation_status_ptr = Get_XCP_NVM_Previous_Operation_Status();
   /* Alignment */
   xcp_bb_input_params->xcp_write_align_memory_ptr = Get_XCP_Write_Align_Memory_Ptr();
   xcp_bb_input_params->xcp_wrtie_align_data_ptr   = Get_XCP_Write_Align_Data_Ptr();
   xcp_bb_input_params->xcp_read_align_memory_ptr  = Get_XCP_Read_Align_Memory_Ptr();
   /* Fault tables */
   xcp_bb_input_params->history_fault_table_ptr      = Get_XCP_History_Table_Ptr();
   xcp_bb_input_params->active_fault_table_ptr       = Get_XCP_Active_Table_Ptr();
   xcp_bb_input_params->active_fault_latch_table_ptr = Get_XCP_Active_Latched_Table_Ptr();
   xcp_bb_input_params->xcp_fault_test_completed_ptr = Get_XCP_Fault_Test_Completed();
   /* DID */
   xcp_bb_input_params->xcp_input_did_ptr  = Get_XCP_In_DID_ptr();
   xcp_bb_input_params->xcp_output_did_ptr = Get_XCP_Out_DID();
   xcp_bb_input_params->xcp_num_mcu_sensor = Get_XCP_Num_MCU_Sensors();

#if COMMENTED
   xcp_bb_input_params->xcp_chksm_trigger_flag_ptr               = Get_XCP_Chksum_Trigger_Ptr();
   xcp_bb_input_params->xcp_chksm_trigger_mode                   = Get_XCP_Chksum_Trigger_Mode();
   xcp_bb_input_params->xcp_current_look                         = Get_XCP_Current_Look();
   xcp_bb_input_params->xcp_chksm_flash_status                   = Get_Flash_checksum_Status();
   xcp_bb_input_params->xcp_itv_ipc_state                        = Get_XCP_Itv_IPC_State();
   xcp_bb_input_params->xcp_itv_ipc_event_state                  = Get_XCP_Itv_IPC_Event_State();
   xcp_bb_input_params->xcp_itv_ipc_value_state                  = Get_XCP_Itv_IPC_Value_State();
   xcp_bb_input_params->xcp_interface_cntrptr                    = Get_XCP_Interface_Enable_Ptr();
   xcp_bb_input_params->xcp_tx_rx_gain_phase_value_ptr           = Get_XCP_Tx_Rx_Gain_Phase_Data();
   xcp_bb_input_params->xcp_himode_ptr                           = Get_XCP_HIL_Mode_Ptr();
   xcp_bb_input_params->xcp_elec_chip_if_id_fptr                 = Get_XCP_Read_Electrnoic_Chip_Interface();
   xcp_bb_input_params->xcp_electronic_chip_id_max               = Get_XCP_Num_Electronic_Chip();
   xcp_bb_input_params->xcp_mmic1_init_status_ptr                = Get_XCP_Mmic1_Init_Status();
   xcp_bb_input_params->xcp_mmic1_persistant_ism_status_ptr      = Get_XCP_Mmic1_Persistant_Ism_Status();
   xcp_bb_input_params->xcp_mmic1_persistant_osm_status_ptr      = Get_XCP_Mmic1_Persistant_Osm_Status();
   xcp_bb_input_params->xcp_mmic1_osm_fault_counters_ptr         = Get_XCP_Mmic1_Osm_Fault_Counters();
   xcp_bb_input_params->xcp_mmic1_mipi_status_fault_counters_ptr = Get_XCP_Mmic1_Mipi_Status_Fault_Counters();
   xcp_bb_input_params->xcp_mmic1_sw_api_id_ptr                  = Get_XCP_Mmic1_Sw_Api_Id();
   xcp_bb_input_params->xcp_mmic2_init_status_ptr                = Get_XCP_Mmic2_Init_Status();
   xcp_bb_input_params->xcp_mmic2_persistant_ism_status_ptr      = Get_XCP_Mmic2_Persistant_Ism_Status();
   xcp_bb_input_params->xcp_mmic2_persistant_osm_status_ptr      = Get_XCP_Mmic2_Persistant_Osm_Status();
   xcp_bb_input_params->xcp_mmic2_osm_fault_counters_ptr         = Get_XCP_Mmic2_Osm_Fault_Counters();
   xcp_bb_input_params->xcp_mmic2_mipi_status_fault_counters_ptr = Get_XCP_Mmic2_Mipi_Status_Fault_Counters();
   xcp_bb_input_params->xcp_mmic2_sw_api_id_ptr                  = Get_XCP_Mmic2_Sw_Api_Id();
   xcp_bb_input_params->xcp_trigger_rfbist_calib_ptr             = Get_XCP_Transceiver_Calib_Trigger();
   xcp_bb_input_params->xcp_get_rfbist_calib_status              = Get_XCP_Rfbist_Calib_Status();

   xcp_bb_input_params->xcp_jtag_pwd_updation         = Get_XCP_JTAG_PWD_fptr();
   xcp_bb_input_params->xcp_jtag_pwd_status           = Get_XCP_JTAG_PWD_Status();
   xcp_bb_input_params->xcp_jtag_pwd_completed        = Get_XCP_JTAG_Completed_State();
   xcp_bb_input_params->xcp_lifecycle_rrm_ptr         = Get_XCP_Lifecycle_RRM_fptr();
   xcp_bb_input_params->xcp_lifecycle_rru2_ptr        = Get_XCP_Lifecycle_RRU_fptr();
   xcp_bb_input_params->xcp_lifecycle_updation_status = Get_XCP_LC_Updation_fptr();
   xcp_bb_input_params->xcp_lifecycle_Read_update     = Get_XCP_LifeCycle_Read_Data();
   xcp_bb_input_params->xcp_MMICA_Lna_result_ptr      = Get_XCP_MMIC1_Lna_Data();
   xcp_bb_input_params->xcp_MMICA_Mixer_result_ptr    = Get_XCP_MMIC1_Mixer_Data();
   xcp_bb_input_params->xcp_MMICB_Lna_result_ptr      = Get_XCP_MMIC2_Lna_Data();
   xcp_bb_input_params->xcp_MMICB_Mixer_result_ptr    = Get_XCP_MMIC2_Mixer_Data();
   xcp_bb_input_params->xcp_dsp_simulation_data       = Get_XCP_DSP_Simulation_Data();
   xcp_bb_input_params->xcp_jtag_pwd_read_cmd         = Get_XCP_Jtag_Pwd_Read_Cmd();
   xcp_bb_input_params->xcp_jtag_pwd_read_data        = Get_XCP_Jtag_Pwd_Read_Data();
#endif
}

/**
 * FUNCTION:XCP_Periodic_Task
 *. This function implements initialization of input parameters
 *
 * \param[in] void
 *
 * \return void
 *
 * \remark
 * \ServID xx
 * \Reentrancy non-reentrant
 * \Synchronism synchronous
 * \Precondition none
 * \Caveats none
 * TRACEABILITY INFO:
 *
 * SDD
 * WorkItem 1 :
 * WorkItem 2 :
 *
 * SRD
 * WorkItem 1 :
 * WorkItem 2 :
 * WorkItem 3 :
 * \\input{XCP_Periodic_Task}
 */
uint8_t XCP_Periodic_Task(uint8_t *response, uint8_t *framelength)
{
   uint8_t ret_value;
   if (NULL != XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cmnd_fptr)
   {
      /* execute corresponding function */
      ret_value = XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cmnd_fptr(XCP_BB_Input_Params_Ptr, response, framelength);
   }
   else
   {
      ret_value = XCP_CMD_SYNTAX_CPV;
   }
   return (ret_value);
}

/*===========================================================================*\
 * Local Function Prototypes
\*===========================================================================*/

/*===========================================================================*\
 * Local Inline Function Definitions and Function-Like Macros
\*===========================================================================*/

/*===========================================================================*\
 * Function Definitions
\*===========================================================================*/

/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 * Date        userid    (Description on following lines: SCR #, etc.)
 * ----------- --------
 * 10-Aug-2024 alkjpl   DNP-3434: Bringing Inital commands to  Gen 8.
 * 04-Sep-2024 alkjpl   DNP-4983: Bringing Up ADC commands (F1 A0/A1/A2/A3)
\*===========================================================================*/
