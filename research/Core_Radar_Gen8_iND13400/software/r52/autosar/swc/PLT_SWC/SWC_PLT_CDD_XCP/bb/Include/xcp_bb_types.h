#ifndef XCP_BB_TYPES_H
#define XCP_BB_TYPES_H
/*===========================================================================*/
/**
 * @file
 * @brief The API interface to exercise the XCP BB
 *
 * XCP  API
 *
 *------------------------------------------------------------------------------
 *
 * @copyright Copyright 2018 Aptiv, All Rights Reserved.
 * @copyright Aptiv Confidential
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * XCP API
 *
 * @section ABBR ABBREVIATIONS:
 *   - BB - Building Block
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - None
 *
 *   - Requirements Document(s):
 *     - None
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - <a href="https://spo.aptiv.com/sites/0307-eoses/globalregional/ESGW_4-2_PE-SWx_00-01-A02_EN.docx">
 *       ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]</a>
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None
 *
 * @defgroup api Module API
 * @{
 * @brief Contains information regarding the API system
 */
/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/
#include "fixmac.h"
#include "ipc_data.h"

/*===========================================================================*\
 *Other Header Files
\*===========================================================================*/

/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/
#define XCP_ERR_CMD_SYNCH_CPV          ((uint8_t)0x00)
#define XCP_ERR_CMD_BUSY_CPV           ((uint8_t)0x10)
#define XCP_ERR_DAQ_ACTIVE_CPV         ((uint8_t)0x11)
#define XCP_ERR_PGM_ACTIVE_CPV         ((uint8_t)0x12)
#define XCP_ERR_CMD_UNKNOWN_CPV        ((uint8_t)0x20)
#define XCP_ERR_CMD_SYNTAX_CPV         ((uint8_t)0x21)
#define XCP_ERR_OUT_OF_RANGE_CPV       ((uint8_t)0x22)
#define XCP_ERR_WRITE_PROTECTED_CPV    ((uint8_t)0x23)
#define XCP_ERR_ACCESS_DENIED_CPV      ((uint8_t)0x24)
#define XCP_ERR_ACCESS_LOCKED_CPV      ((uint8_t)0x25)
#define XCP_ERR_PAGE_NOT_VALID_CPV     ((uint8_t)0x26)
#define XCP_ERR_MODE_NOT_VALID_CPV     ((uint8_t)0x27)
#define XCP_ERR_SEGMENT_NOT_VALID_CPV  ((uint8_t)0x28)
#define XCP_ERR_SEQUENCE_CPV           ((uint8_t)0x29)
#define XCP_ERR_DAQ_CONFIG_CPV         ((uint8_t)0x2A)
#define XCP_ERR_MEMORY_OVERFLOW_CPV    ((uint8_t)0x30)
#define XCP_ERR_GENERIC_CPV            ((uint8_t)0x31)
#define XCP_ERR_VERIFY_CPV             ((uint8_t)0x32)
#define XCP_ERR_MFG_MODE_NOT_ENTERED   ((uint8_t)0x33)
#define XCP_ERR_CONDITIONS_NOT_CORRECT ((uint8_t)0x81)

/* XCP Return Code */
#define XCP_CMD_OK_CPV      ((uint8_t)0x00)
#define XCP_CMD_PENDING_CPV ((uint8_t)0x01)
#define XCP_CMD_SYNTAX_CPV  ((uint8_t)0x21)

/* XCP_LED_Output_State_Tag */
#define XCP_OUT_STATE_AUTO          ((uint8_t)0x01)
#define XCP_OUT_STATE_FORCED_OFF    ((uint8_t)0x10)
#define XCP_OUT_STATE_FORCED_ON     ((uint8_t)0x11)
#define XCP_OUT_STATE_FORCED_5_PWM  ((uint8_t)0xA0)
#define XCP_OUT_STATE_FORCED_50_PWM ((uint8_t)0xA1)
#define XCP_OUT_STATE_FORCED_95_PWM ((uint8_t)0xA2)

#define MAX_SIZE_TX_RX_GAIN_PHASE (12U)

#define COMMENTED 0

#define NUM_OF_DAQ1_VARIABLES ((uint8_t)7)

/*===========================================================================*
 * Exported Preprocessor #define MACROS
 *===========================================================================*/
#define XCP_MAX_CUST_SW_VER            ((uint8_t)((int16_t)XCP_CUST_SW_VER_16 - (int16_t)XCP_CUST_SW_VER_1))
#define XCP_RANGE_CHECK(val, min, max) (((val) >= (min)) && ((val) <= (max)))

/*===========================================================================*
 *Exported Object Declarations
 *===========================================================================*/
typedef uint8_t XCP_LED_Output_State_T;

typedef enum XCP_Checksum_Tag
{
   XCP_APP_CHKSM,
   XCP_BL_CHKSM,
   XCP_USC_CHKSM,
   XCP_SMC_CHKSM,
   XCP_KEEP_ALIVE_CHKSM,
   XCP_MAX_CHKSM
} XCP_Checksum_T;

typedef enum XCP_Cust_Checksum_Tag
{
   XCP_CUST_CHKSM_1 = 0x5,
   XCP_CUST_CHKSM_2,
   XCP_CUST_CHKSM_3,
   XCP_CUST_CHKSM_4,
   XCP_CUST_CHKSM_5,
   XCP_CUST_CHKSM_6,
   XCP_CUST_CHKSM_7,
   XCP_CUST_CHKSM_8,
   XCP_CUST_CHKSM_9,
   XCP_CUST_CHKSM_10,
   XCP_MAX_CUST_CHKSM
} XCP_Cust_Checksum_T;

typedef enum XCP_Force_Radiate_Status_Tag
{
   XCP_FORCE_RADIATE_NORMAL_OPERATION = 0x01,
   XCP_FORCE_RADIATE_ON,
   XCP_FORCE_RADIATE_OFF
} XCP_Force_Radiate_Status_T;

typedef enum XCP_Operation_Mode_Tag
{
   XCP_OPCMD_NORMAL_MODE = 1,
   XCP_OPCMD_VALIDATION_MANF_TEST_MODE
} XCP_Operation_Mode_T;

typedef enum CW_Mode_Tag
{
   XCP_CW_MODE_ENABLE = 1,
   XCP_CW_MODE_DISABLE
} CW_Mode_T;

typedef enum Radar_Init_Status_Tag
{
   XCP_RADAR_INIT_FAIL,
   XCP_RADAR_INIT_NOT_STARTED,
   XCP_RADAR_INIT_STARTED,
   XCP_RADAR_INIT_SUCCESS
} XCP_Radar_Init_Status_T;

typedef enum XCP_Look_Mode_Type_Tag
{
   XCP_LRLL_LOOK_MODE = 0x01,
   XCP_LRML_LOOK_MODE,
   XCP_MRLL_LOOK_MODE,
   XCP_MRML_LOOK_MODE,
   XCP_FACTORY_LOOK_MODE
} XCP_Single_Look_Mode_Type_T;

typedef enum XCP_Look_Type_Action_Tag
{
   XCP_LOOK_MODE_ENABLE = 0x01,
   XCP_LOOK_MODE_DISABLE
} XCP_Single_Look_Action_T;

typedef struct XCP_Single_Look_Tag
{
   uint8_t single_look_en;
   uint8_t single_look_select;
} XCP_Single_Look_T;

typedef struct XCP_MMIC_Temperature_Tag
{
   int16_t TX0;
   int16_t TX1;
   int16_t TX2;
   int16_t TX3;
   int16_t DSP;
   int16_t HSM;
   int16_t HWA;
} XCP_MMIC_Temperature_T;

typedef struct XCP_LED_Output_Cntrl_Tag
{
   uint8_t xcp_out_select;
   uint8_t xcp_out_state;
} XCP_LED_Output_Cntrl_T;

typedef enum XCP_ITV_Sub_Cmd_Tag
{
   XCP_SIM_CTRL_ADC_MCU_TEMP = 1U,
   XCP_SIM_CTRL_IPC_FF_OUTPUT
} XCP_ITV_Sub_Cmd_T;

typedef enum XCP_ITV_State_ADC_Tag
{
   XCP_CONNECT_ADC = 1U,
   XCP_DISCONNNECT_ADC
} XCP_ITV_State_ADC_T;

typedef enum XCP_ITV_State_IPC_Tag
{
   XCP_DISABLE_SIM = 1U,
   XCP_ENABLE_SIM,
   XCP_ENABLE_ITV_SIM_MAX_MODE,
   XCP_ENABLE_ITV_SIM_MIN_MODE
} XCP_ITV_State_IPC_T;

typedef enum XCP_Fault_Override_Mode_Tag
{
   XCP_AUTO_MODE = 0x01,
   XCP_SET_FAULT_MODE,
   XCP_CLEAR_FAULT_MODE
} XCP_Fault_Override_Mode_T;

typedef struct XCP_Fault_Override_Tag
{
   uint8_t action;
   uint8_t byte_pos;
   uint8_t bit_pos;
} XCP_Fault_Override_T;

typedef enum XCP_NVM_Tag
{
   XCP_ERASE_ENTIRE_KAM = 0x01,
   XCP_SET_KAM_TO_RAM_DEFAULT,
   XCP_ERASE_KAM_AND_SET_DEFAULT,
   XCP_FORCE_SAVE_RAM_TO_KAM,
   XCP_VERIFY_KAM_UPDATE_STATUS,
   XCP_ERASE_SPECIFIC_KAM_BLOCKS
} XCP_Nvm_T;

typedef enum XCP_SW_Ver_Index_Tag
{
   XCP_PLT_SW_VER = 0X1,
   XCP_PLT_BL_VER,
   XCP_PLT_BM_VER,
   XCP_SMC_VER,
   XCP_USC_VER,
   XCP_RADAR_SIGNAL_PROC_VER,
   XCP_SECOND_PASS_VER,
   XCP_FIRST_PASS_VER,
   XCP_LOOK_PROC_VER,
   XCP_RADAR_TRANSCEIVER_VER,
   XCP_MCU_CORE_A_VER,
   XCP_MCU_CORE_B_VER,
   XCP_MCU_CORE_C_VER,
   XCP_MCU_CORE_D_VER,
   XCP_MCU_CORE_E_VER,
   XCP_MCU_CORE_F_VER,
   XCP_UDP_VERS,
   XCP_CUST_SW_VER,
   XCP_CUSTOMER_BL_VER,
   XCP_CUSTOMER_BM_VER,
   XCP_TRACKER_VER,
   XCP_FF_1_VER,
   XCP_FF_2_VER,
   XCP_FF_3_VER,
   XCP_FF_4_VER,
   XCP_FF_5_VER,
   XCP_AUTOSAR_VER,
   XCP_MAX_SW_VER
} XCP_SW_Ver_Index_T;

typedef enum XCP_Cust_SW_Ver_Index_Tag
{
   XCP_CUST_SW_VER_1 = 0xF0,
   XCP_CUST_SW_VER_2,
   XCP_CUST_SW_VER_3,
   XCP_CUST_SW_VER_4,
   XCP_CUST_SW_VER_5,
   XCP_CUST_SW_VER_6,
   XCP_CUST_SW_VER_7,
   XCP_CUST_SW_VER_8,
   XCP_CUST_SW_VER_9,
   XCP_CUST_SW_VER_10,
   XCP_CUST_SW_VER_11,
   XCP_CUST_SW_VER_12,
   XCP_CUST_SW_VER_13,
   XCP_CUST_SW_VER_14,
   XCP_CUST_SW_VER_15,
   XCP_CUST_SW_VER_16,
} XCP_CUST_SW_Ver_Index_T;

typedef enum XCP_Interface_Control_Tag
{
   XCP_PCAN_INTERFACE = 1U,
   XCP_VCAN_INTERFACE,
   XCP_ETHERNET_INTERFACE
} Interface_Control_T;

typedef enum XCP_Interface_Control_State_Tag
{
   XCP_INTERFACE_DISABLE = 1U,
   XCP_INTERFACE_ENABLE
} XCP_Interface_Control_State_T;

typedef struct XCP_DAQ_Descriptor_Table_Tag
{
   uint32_t address;
   uint16_t total_size;
   uint8_t event_channel_no;
   uint8_t parameter_size;

} XCP_DAQ_Descriptor_Table_T;

typedef enum XCP_LED_Output_Select_Tag
{
   XCP_LED_SELECT_SOURCE_PULL = 0x01U,
   XCP_LED_SELECT_SOURCE_EN
} XCP_LED_Output_Select_T;

typedef enum XCP_HIL_Mode_Status_Tag
{
   XCP_HIL_ENABLE = 1,
   XCP_HIL_DISABLE
} XCP_HIL_Mode_Status_T;

/*
typedef struct RFBIST_Result_XCP_Tag
{
   uint16_t gain_phase[MAX_SIZE_TX_RX_GAIN_PHASE];
} RFBIST_Result_XCP_T;

typedef struct XCP_Rfbist_Tag
{
   RFBIST_Result_XCP_T XCP_tx_gain_Buffer;
   RFBIST_Result_XCP_T XCP_tx_phase_Buffer;
   RFBIST_Result_XCP_T XCP_rx_gain_Buffer;
   RFBIST_Result_XCP_T XCP_rx_phase_Buffer;
} XCP_Rfbist_T;
*/
typedef struct RFBIST_Result_XCP_Tag
{
   uint16_t gain_phase[MAX_SIZE_TX_RX_GAIN_PHASE * 2];
} RFBIST_Result_XCP_T;

typedef struct XCP_Rfbist_Tag
{
   RFBIST_Result_XCP_T XCP_tx_gain_phase_Buffer;
   RFBIST_Result_XCP_T XCP_rx_gain_phase_Buffer;
} XCP_Rfbist_T;

typedef enum XCP_RFBIST_Action_Tag
{
   // XCP_TRIGGER_RFBIST_CALIB = 0x01,
   // XCP_GET_CALIB_STATUS,
   XCP_TX_GAIN = 0x03,
   XCP_TX_PHASE,
   XCP_RX_GAIN,
   XCP_RX_PHASE
} XCP_RFBIST_Action_T;

typedef enum XCP_RFBIST_Calibration_Status_Tag
{
   XCP_RFBIST_CALIBRATION_INVALID = 0,
   XCP_RFBIST_CALIBRATION_SUCCESSFUL,
   XCP_RFBIST_CALIBRATION_IN_PROGRESS,
   XCP_RFBIST_CALIBRATION_FAILED,
   XCP_RFBIST_CALIBRATION_NOT_STARTED
} XCP_RFBIST_Calibration_Status_T;

typedef enum XCP_Interface_Stop_Periodic_Tag
{
   XCP_NORMAL_INTERFACE_STOP_PERIODIC = 0U,
   XCP_PCAN_INTERFACE_STOP_PERIODIC,
   XCP_VCAN_INTERFACE_STOP_PERIODIC,
   XCP_ETHERNET_PLATFORM_INTERFACE_STOP_PERIODIC,
   XCP_ETHERNET_PROJECT_INTERFACE_STOP_PERIODIC,
   XCP_COMM_INTERFACES_MAX
} XCP_Interface_Stop_Periodic_T;

typedef enum XCP_Normal_Stop_Tag
{
   XCP_NORMAL_MSG = 0U,
   XCP_STOP_MSG
} XCP_Normal_Stop_T;
typedef enum XCP_Write_Alignment_Type_Tag
{
   XCP_WRITE_ALIGNMENT_TYPE = 0U,
   XCP_WRITE_ALIGNMENT_NVM,
   XCP_WRITE_ALIGNMENT_MAX,
} XCP_Write_Alignment_Type_T;

typedef enum XCP_Write_Alignment_State_Tag
{
   XCP_WRITE_ALIGNMENT_IDLE = 0U,
   XCP_WRITE_ALIGNMENT_DONE,
   XCP_WRITE_ALIGNMENT_INPROGESS,
   XCP_WRITE_ALIGNMENT_FAIL
} XCP_Write_Alignment_State_T;

typedef enum XCP_Fault_Inject_Sys_Domain_Tag
{
   XCP_INJECT_SYS_DOMAIN_MM1 = 0U,
   XCP_INJECT_SYS_DOMAIN_MM2,
   XCP_INJECT_SYS_DOMAIN_MM3,
   XCP_INJECT_SYS_DOMAIN_MM4,
   XCP_INJECT_SYS_DOMAIN_RSV,
   XCP_INJECT_SYS_DOMAIN_RC1,
   XCP_INJECT_SYS_DOMAIN_RC2,
   XCP_INJECT_SYS_DOMAIN_RC3,
   XCP_INJECT_SYS_DOMAIN_RC4,
   XCP_INJECT_SYS_DOMAIN_PT1,
   XCP_INJECT_SYS_DOMAIN_RPDM1,
   XCP_INJECT_SYS_DOMAIN_RPDM2,
   XCP_INJECT_SYS_DOMAIN_AL,
   XCP_INJECT_SYS_DOMAIN_MAX
} XCP_Fault_Inject_Sys_Domain_T;

typedef Detection_Stream_T XCP_Target_Report_T;
typedef struct XCP_Inject_Fault_Tag
{
   uint8_t xcp_sys_domain;          /*System domain index (cmnd[2])*/
   uint8_t xcp_failure_type;        /*Failure type value (cmnd[3]) - RTE call parameter and direct array index*/
   uint8_t xcp_inject_control;      /*Injection control value (cmnd[4])*/
   uint8_t xcp_cmd_injection_recvd; /*Flag: CODED_TRUE when BB has validated and queued a command*/
} XCP_Inject_Fault_T;

typedef struct XCP_Inject_Sys_Domain_Tag
{
   uint8_t (*XCP_Sys_Domain_ptr)[4];
   uint8_t subcmd_size;
} XCP_Inject_Sys_Domain_T;

typedef struct XCP_USC_SMC_Seq_Tag
{
   uint32_t xcp_usc_smc_address;
   uint32_t xcp_usc_smc_size;
   uint8_t xcp_usc_smc_initialized;
   uint8_t xcp_usc_smc_seq;
   uint8_t xcp_usc_smc_check_status;
} XCP_USC_SMC_Seq_T;

typedef XCP_Target_Report_T *(*XCP_Copy_Trgt_Rprts_fptr_T)(void);

typedef uint8_t (*XCP_Look_Enable_Status_fptr_T)(uint8_t);

typedef uint8_t *(*XCP_Electronic_Chip_Id_fptr_T)(uint8_t);

typedef void (*Xcp_Phase_Rotator_fptr_T)(uint8_t);

/* Structure for DID Read/ Write */
typedef struct XCP_DID_Write_Tag
{
   uint16_t wait_time;
   uint8_t status;
   uint8_t length;
} XCP_DID_Write_T;

typedef struct XCP_JTAG_PWD_Tag
{
   uint8_t pwd_length;
   uint8_t pwd_arr[61];
} XCP_JTAG_PWD_T;

typedef struct XCP_LifeCycle_Data_Tag
{
   uint32_t new_lc;
   uint8_t sub_cmd;
   uint8_t current_lc;
} XCP_LifeCycle_Data_T;

typedef struct XCP_DSP_Data_Tag
{
   bool dsp_simulation_enable;
   bool static_simulation_enable;
   bool dynamic_simulation_enable;
   uint8_t dsp_test_case;
   uint8_t dsp_user_detection;
   uint16_t fixed_arc_shaped_targets;
   uint8_t parameter[4];
} XCP_DSP_Data_Tag_T;

typedef uint8_t (*XCP_UPDATE_LC_T)(uint8_t sub_cmd);

typedef uint8_t XCP_Err_Code_T;

/* Structure for DID Read/ Write */
typedef struct XCP_Write_Alignment_Tag
{
   uint8_t cmd_recived;
   uint8_t sub_cmd;
   uint8_t quantity;
   uint8_t write_status;
   uint8_t write_nvm_flag;
} XCP_Write_Alignment_T;

typedef struct
{
   float32_t AACurrentAzimuth;
   float32_t AACurrentElevation;
   float32_t AACurrentRoll;
   float32_t InitialAlignmentResultAzimuth;
   float32_t InitialAlignmentResultElevation;
   float32_t InitialAlignmentResultRoll;
   float32_t InitialLastSuccessfulAlignmentMode;
   float32_t ElevationUpdates;
   float32_t AzimuthUpdates;
   float32_t RollUpdates;
   float32_t InitialAlignmentResultElevationUpdates;
   float32_t InitialAlignmentResultHostSpeedCompensationFactor;
   float32_t HostSpeedCompensationFactor;
   float32_t InitialAlignmentResultAzimuthUpdates;
   float32_t InitialAlignmentResultRollUpdates;
} Xcp_Write_Alignment_NvM_Data_T;

typedef struct
{
   float32_t AlignmentAzimuth;
   float32_t AlignmentElevation;
   float32_t AlignmentRoll;
   float32_t AzimuthStd;
   float32_t ElevationStd;
   float32_t RollStd;
   float32_t CalTime;
   uint8_t AlignmentStaticStatus;
   uint8_t AlignmentServiceStatus;
   uint8_t AlignmentShortTrackStatus;
   uint8_t ProgressPercent;
   uint8_t AlignmentError;
} Xcp_Initial_Alignment_Result_T;

typedef struct
{
   float32_t StartAzimuth;
   float32_t StartElevation;
   float32_t StartRoll;
   float32_t AACurrentAzimuth;
   float32_t AACurrentElevation;
   float32_t AACurrentRoll;
   float32_t AAAzimuthStd;
   float32_t AAElevationStd;
   float32_t AARollStd;
   float32_t AzimuthError_positiveRead;
   float32_t AzimuthError_negativeRead;
   float32_t ElevationError_positive_Read;
   float32_t ElevationError_negative_Read;
   float32_t RollError_positive_Read;
   float32_t RollError_negative;
} Xcp_Auto_Alignment_Result_T_1;

typedef struct
{
   uint8_t AlignmentAutoStatus;
   uint8_t AutoAlignmentFailRootCause;
} Xcp_Auto_Alignment_Result_T_2;

/* F1 12 : Fault Injection through XCP */
typedef void (*XCP_FaultInj_RTE_Call)(uint8_t, uint8_t); /*Funtion Pointer to for RTE calls having two arguements of unit8*/
typedef struct XCP_Fault_Inj_Handler_Tag                 /*Strucctre for Falult Handling*/
{
   XCP_FaultInj_RTE_Call xcp_fault_trigger_rte_fun_ptr; /*Funtion pointer holding RTE calls to trigger fault injection*/
   uint8_t xcp_failure_type;                            /*Failure Type*/
   uint8_t xcp_failure_type_min;                        /*Failure Type Lower range*/
   uint8_t xcp_failure_type_max;                        /*Failure Type Upper range*/
   uint8_t xcp_injection_ctrl_min;                      /*Injection Control Lower range*/
   uint8_t xcp_injection_ctrl_max;                      /*Injection Control Upper range*/

} XCP_Fault_Inj_Handler_T;

typedef struct XCP_Fault_Injection_Config_Table_Tag /*Strucctre for Falult Handling*/
{
   const XCP_Fault_Inj_Handler_T *xcp_fault_handlers; /*Holds all Faults Entries */
   uint8_t xcp_sys_domain;                            /* Sys Domain*/
   uint8_t xcp_fault_count;                           /*Fault Count in Each Sys Domain*/
} XCP_Fault_Injection_Config_Table_T;

typedef enum XCP_RFBIST_Device_Select_Tag
{
   XCP_MMIC_DEVICE_1 = 0x01,
} XCP_RFBIST_Device_Select_T;

typedef enum XCP_RFBIST_Device_Fun_Tag
{
   XCP_RFBIST_CALIB = 0x01,
   XCP_RFBIST_DEBUG
} XCP_RFBIST_Device_Fun_T;

typedef enum XCP_RFBIST_Action_1_Tag
{
   XCP_TRIGGER_RFBIST_CALIB = 0x01,
   XCP_GET_CALIB_STATUS,
} XCP_RFBIST_Action_1_T;

typedef struct XCP_RFBIST_Debug_Data_Tag
{
   uint32_t *xcp_rfbist_debug_data_ptr;
   uint8_t xcp_debug_no_of_parameter;
   uint8_t xcp_unused_padding_byte2;
   uint8_t xcp_unused_padding_byte3;
   uint8_t xcp_unused_padding_byte4;
} XCP_RFBIST_Debug_Data_T;
typedef XCP_RFBIST_Debug_Data_T *(*xcp_rfbist_debugdata_ptr)(uint8_t);

typedef struct XCP_BB_Input_Params_Tag
{
   volatile uint8_t *xcp_operation_mode_ptr;
   volatile uint8_t *xcp_clear_faults_ptr;
   /* ADC related inputs */
   volatile uint16_t *xcp_get_raw_adc_data_ptr;
   volatile uint8_t *xcp_get_adc_validity_flag_ptr;
   volatile uint8_t *xcp_get_adc_trigger_flag_ptr;
   uint8_t num_analog_inputs;
   /* Fault table related inputs */
   uint8_t num_fault_bytes;
   volatile uint8_t *history_fault_table_ptr;
   volatile uint8_t *active_fault_table_ptr;
   volatile uint8_t *active_fault_latch_table_ptr;
   volatile uint8_t *xcp_force_radiate_ptr;
   /* checksum related pointers */
   uint8_t *xcp_chksm_trigger_flag_ptr;
   uint8_t xcp_chksm_trigger_mode;
   uint8_t **xcp_checksum_ptr;
   uint8_t **xcp_cust_checksum_ptr;
   uint8_t xcp_radar_radiate_cmd;
   uint8_t *xcp_cw_mode_ptr;

   volatile int16_t *xcp_get_tx_temp_ptr;
   uint8_t xcp_num_mmic;

   volatile uint8_t *xcp_fault_test_completed_ptr;
   volatile XCP_Single_Look_T *xcp_look_mode_ptr;
   uint8_t xcp_num_cust_spec_chcksm;
   uint8_t xcp_radar_init_status;
   uint8_t xcp_num_sw_version_bytes;
   uint8_t xcp_customer_id;
   uint16_t xcp_num_max_dets;
   uint8_t xcp_sw_ver_len;

   volatile float32_t *xcp_get_mcu_temp_ptr;
   uint8_t xcp_num_mcu_sensor;
   /* Target Select related variables */
   uint8_t xcp_num_of_looks;
   uint8_t xcp_target_selection_num;
   uint16_t xcp_max_number_range_bin;
   uint16_t xcp_max_number_doppler_bin;
   volatile uint8_t *xcp_target_select_enable_ptr;
   XCP_Copy_Trgt_Rprts_fptr_T xcp_copy_target_report_fptr;
   XCP_Look_Enable_Status_fptr_T xcp_look_en_status_fptr;
   uint8_t xcp_MMIC_ChipID_Length;
   uint8_t xcp_current_look;
   XCP_LED_Output_Cntrl_T *xcp_out_set_output_state;
   volatile uint16_t *xcp_set_override_var_ptr;
   volatile uint16_t *xcp_get_override_var_ptr;
   volatile uint8_t *xcp_get_mcu_id_ptr;
   volatile uint8_t *xcp_get_unique_id_ptr;
   volatile uint16_t *xcp_target_range_idx_ptr;
   volatile uint16_t *xcp_target_doppler_idx_ptr;
   uint8_t *xcp_chksm_flash_status;
   uint8_t *xcp_itv_adc_state;
   uint8_t *xcp_itv_ipc_state;
   uint8_t *xcp_itv_ipc_event_state;
   uint8_t *xcp_itv_ipc_value_state;
   void *xcp_get_raw_adc_filtered_data_ptr;
   /* memory fault override related pointer */
   volatile XCP_Fault_Override_T *xcp_fault_override_ptr;
   /* nvm command inputs */
   volatile uint8_t *xcp_nvm_ptr;
   volatile uint8_t *xcp_nvm_prev_operation_status_ptr;

   uint8_t **xcp_sw_ver_ptr;
   uint8_t **xcp_cust_sw_ver_ptr;
   volatile uint8_t *xcp_MMIC_A_ChipID_ptr;
   volatile uint8_t *xcp_MMIC_B_ChipID_ptr;
   /*Fake fault inject*/
   XCP_Inject_Fault_T *xcp_inject_fault_data;
   /* interface control */
   uint8_t **xcp_interface_cntrl_ptr;

   /* stop periodic msgs interface control */
   uint8_t **xcp_stop_periodic_message_ptr;
   void *xcp_bb_daq_info_params_ptr;
   /*Did data */
   void *xcp_input_did_ptr;
   void *xcp_output_did_ptr;
   uint8_t *xcp_did_recvd_ptr;
   uint8_t **xcp_write_align_memory_ptr;
   XCP_Write_Alignment_T *xcp_wrtie_align_data_ptr;
   uint8_t **xcp_read_align_memory_ptr;
   uint8_t **xcp_tx_rx_gain_phase_value_ptr;
   uint8_t *xcp_hil_mode_ptr;
   uint8_t *xcp_read_hardware_version_ptr;
   XCP_Electronic_Chip_Id_fptr_T xcp_elec_chip_if_id_fptr;
   uint8_t *xcp_read_electronic_chipid;
   uint8_t xcp_electronic_chip_id_max;
   /* Phase rotator calibration*/
   Xcp_Phase_Rotator_fptr_T xcp_phase_rotator_calib_fptr;
   uint8_t *xcp_trigger_rfbist_calib_ptr;
   uint8_t xcp_get_rfbist_calib_status;
   /* transceiver calibration */
   xcp_rfbist_debugdata_ptr xcp_rfbist_debug_data_fptr;
#if COMMENTED
   /* mmic */
   volatile uint8_t *xcp_mmic1_init_status_ptr;
   volatile uint8_t *xcp_mmic1_persistant_ism_status_ptr;
   volatile uint8_t *xcp_mmic1_persistant_osm_status_ptr;
   volatile uint8_t *xcp_mmic1_osm_fault_counters_ptr;
   volatile uint8_t *xcp_mmic1_mipi_status_fault_counters_ptr;
   volatile uint8_t *xcp_mmic1_sw_api_id_ptr;
   volatile uint8_t *xcp_mmic2_init_status_ptr;
   volatile uint8_t *xcp_mmic2_persistant_ism_status_ptr;
   volatile uint8_t *xcp_mmic2_persistant_osm_status_ptr;
   volatile uint8_t *xcp_mmic2_osm_fault_counters_ptr;
   volatile uint8_t *xcp_mmic2_mipi_status_fault_counters_ptr;
   volatile uint8_t *xcp_mmic2_sw_api_id_ptr;

   uint8_t xcp_get_rfbist_calib_status;
   void *xcp_MMICA_Lna_result_ptr;
   void *xcp_MMICA_Mixer_result_ptr;
   void *xcp_MMICB_Lna_result_ptr;
   void *xcp_MMICB_Mixer_result_ptr;
   XCP_LED_Output_Cntrl_T *xcp_led_set_output_state;

   /* Jtag password variable */
   uint8_t *xcp_jtag_pwd_updation;
   uint8_t *xcp_jtag_pwd_status;
   uint8_t *xcp_jtag_pwd_completed;
   uint8_t *xcp_lifecycle_updation_status;
   XCP_UPDATE_LC_T xcp_lifecycle_rrm_ptr;
   XCP_UPDATE_LC_T xcp_lifecycle_rru2_ptr;
   uint8_t *xcp_lifecycle_Read_update;
   XCP_DSP_Data_Tag_T *xcp_dsp_simulation_data;
   uint8_t *xcp_jtag_pwd_read_cmd;
   XCP_JTAG_PWD_T *xcp_jtag_pwd_read_data;
#endif

} XCP_BB_Input_Params_T;

typedef uint8_t (*XCP_Periodic_User_Cmd_Task_Fptr)(XCP_BB_Input_Params_T *const xcp_input_ptr, uint8_t *response,
                                                   uint8_t *framelength);

typedef struct XCP_Periodic_User_Cmd_Tag
{
   XCP_Periodic_User_Cmd_Task_Fptr xcp_periodic_cmnd_fptr; /* function pointer */
   uint8_t xcp_periodic_user_cmd_rcvd;                     /* coded_true/false */
   uint8_t xcp_periodic_user_cmd_val;                      /* actual command */
   uint8_t xcp_periodic_cycle_cnt;                         /* cycle_counts per command */
   uint8_t xcp_periodic_cycle_cnt_max;                     /* max cycle count per command */
} XCP_Periodic_User_Cmd_T;

/*===========================================================================*\
 * Exported Object Declarations
\*===========================================================================*/

extern XCP_Periodic_User_Cmd_T *const XCP_Periodic_User_Cmd_Ptr;
extern XCP_BB_Input_Params_T *XCP_BB_Input_Params_Ptr;
uint8_t Get_XCP_Pending_Cmnd_Status(void);
const XCP_Fault_Injection_Config_Table_T *Get_XCP_Fault_Config_Table(void);

/*===========================================================================*
 * Exported Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Exported Inline Function Definitions and #define Function-Like Macros
 *===========================================================================*/

/*===========================================================================*/
/* @section RH REVISION HISTORY (top to bottom: first revision to last revision)
 * Date        userid    (Description on following lines: SCR #, etc.)
 * ----------- --------
 * 10-Aug-2024 alkjpl   DNP-3434: Bringing Inital commands to  Gen 8.
 *===========================================================================*/
/** @} doxygen end group */
#endif /* XCP_BB_TYPES_H */
