#ifndef XCP_USER_CMDS_H /* { */
#define XCP_USER_CMDS_H
/*===========================================================================*/
/**
 * @file xcp_user_cmds.h
 *
 * Interface declarations for XCP user command handling in the Gen8 iND13400 radar software.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (c) 2020 Aptiv. All rights reserved.
 * Confidential - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * This header defines the XCP user command IDs, command dispatch table macros,
 * and associated types used by the XCP building block (SWC_PLT_Appl_XCP) to
 * handle calibration, diagnostic, and control commands over the XCP protocol.
 * It includes command codes for ADC analog input readout, radar target reporting,
 * fault injection, alignment data, temperature sensing, and NVM/data flash operations.
 *
 * @section ABBR ABBREVIATIONS:
 *   - ADC  - Analog-to-Digital Converter
 *   - CW   - Continuous Wave
 *   - DID  - Data Identifier
 *   - MCU  - Microcontroller Unit
 *   - MMIC - Monolithic Microwave Integrated Circuit
 *   - NVM  - Non-Volatile Memory
 *   - XCP  - Extended Calibration Protocol
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - SWC_PLT_Appl_XCP Software Design Description
 *
 *   - Requirements Document(s):
 *     - WI-268284, WI-277016, WI-277679, WI-287956, WI-287957
 *     - WI-320538, WI-320539, WI-320540, WI-320541, WI-320542
 *     - WI-306245, WI-306246
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - <a href="https://spo.aptiv.com/sites/0307-eoses/globalregional/ESGW_4-2_PE-SWx_00-01-A02_EN.docx">
 *       ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]</a>
 *     - AUTOSAR R20-11 Software Component specification
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/

/*===========================================================================*\
 * Standard Header Files
\*===========================================================================*/
#include "xcp_bb_types.h"

/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/

/*===========================================================================*\
 * Exported Preprocessor #define Constants
\*===========================================================================*/
#define DATA_BYTES_LEN ((uint8_t)64)

/* User Commands Preprocessor #define Constants */
#define XCP_USER_CMD_SET_OPERATION_MODE                ((uint8_t)0x01)
#define XCP_USER_CMD_RADAR_TRANSMITTER_ENABLE          ((uint8_t)0x02)
#define XCP_USER_CMD_STOP_TRANSMITTING_PERIODIC_MSGS   ((uint8_t)0x03)
#define XCP_USER_CMD_CLEAR_INTERNAL_FAULT_CODES        ((uint8_t)0x04)
#define XCP_USER_CMD_ERASE_DATA_FLASH                  ((uint8_t)0x05)
#define XCP_USER_CMD_GET_START_ADDRESS_SIZE_EVENT_INFO ((uint8_t)0x06)
#define XCP_USER_CMD_SINGLE_LOOK_MODE                  ((uint8_t)0x0B)
#define XCP_USER_CMD_GET_SW_VERSION                    ((uint8_t)0x0C)
#define XCP_USER_CMD_READ_HARDWARE_VERSION             ((uint8_t)0x0D)
#define XCP_USER_CMD_DSP_SIMULATION                    ((uint8_t)0x0E)
#define XCP_USER_CMD_ITV_SIMULATION_CONTROL            ((uint8_t)0x0F)
#define XCP_USER_CMD_INTERFACE_CONTROL                 ((uint8_t)0x10)
#define XCP_USER_CMD_OVERRIDE_MEMORY_FAULT             ((uint8_t)0x11)
#define XCP_USER_CMD_FAKE_INJECT_FAULT                 ((uint8_t)0x12)
#define XCP_USER_CMD_READ_WRITE_DID                    ((uint8_t)0x13)
#define XCP_USER_CMD_SET_RADAR_TO_CW_MODE              ((uint8_t)0x14)
#define XCP_USER_CMD_LIFECYCLE_UPDATE                  ((uint8_t)0x15)
#define XCP_USER_CMD_JTAG_PASSWORD_UPDATE              ((uint8_t)0x16)
#define XCP_USER_CMD_JTAG_PASSWORD_READ                ((uint8_t)0x17)
#define XCP_USER_CMD_SET_OUTPUT_STATE                  ((uint8_t)0x1F)
#define XCP_USER_CMD_SET_OVERRIDE_CONTROL_VARIABLE     ((uint8_t)0x22)
#define XCP_USER_CMD_GET_OVERRIDE_CONTROL_VARIABLE     ((uint8_t)0x23)
#define XCP_USER_CMD_WRITE_ALIGNMENT_DATA              ((uint8_t)0x30)
#define XCP_USER_CMD_READ_ALIGNMENT_DATA               ((uint8_t)0x31)
#define XCP_USER_CMD_HIL_MODE                          ((uint8_t)0x50)
#define XCP_USER_CMD_GET_CHECKSUM_RESULTS              ((uint8_t)0x85)
#define XCP_USER_CMD_GET_RADAR_TARGET                  ((uint8_t)0x90)
#define XCP_USER_CMD_ELECTRONIC_CHIP_ID                ((uint8_t)0x96)
#define XCP_USER_CMD_GET_MCU_ID                        ((uint8_t)0x97)
#define XCP_USER_CMD_GET_TRANSCIEVER_CHIP_ID           ((uint8_t)0x98)
#define XCP_USER_CMD_RADAR_TRANSCEIVER_CALIBRATION     ((uint8_t)0x99)
#define XCP_USER_CMD_TARGET_SELECT                     ((uint8_t)0x9A)
#define XCP_USER_CMD_PHASE_ROTATOR_CALIBRATION         ((uint8_t)0x9B)
#define XCP_USER_CMD_GET_MMIC_MCU_TEMP                 ((uint8_t)0x9F)
#define XCP_USER_CMD_GET_HOST_ANALOG_INPUTS_0TO30      ((uint8_t)0xA0)
#define XCP_USER_CMD_GET_HOST_ANALOG_INPUTS_31TO61     ((uint8_t)0xA1)
#define XCP_USER_CMD_GET_FILTERED_ADC_INPUTS_0TO30     ((uint8_t)0xA2)
#define XCP_USER_CMD_GET_FILTERED_ADC_INPUTS_31TO61    ((uint8_t)0xA3)
#define XCP_USER_CMD_GET_MMIC_DEBUG_INFO               ((uint8_t)0xAA)
#define XCP_USER_CMD_GET_FAULT_TEST_COMPLETED          ((uint8_t)0xB0)
#define XCP_USER_CMD_GET_HISTORY_FAULT                 ((uint8_t)0xC0)
#define XCP_USER_CMD_GET_ACTIVE_FAULT                  ((uint8_t)0xD0)
#define XCP_USER_CMD_GET_ACTIVE_FAULT_LATCHED          ((uint8_t)0xE0)
#define XCP_USER_CMD_GET_ENABLED_FAULT_TABLE_BYTES     ((uint8_t)0xF0)
#define XCP_USER_CMD_RADAR_TRANSCEIVER_CALIBRATION     ((uint8_t)0x99)

/*===========================================================================*\
 * Exported Preprocessor #define MACROS
\*===========================================================================*/
#define XCP_USER_CMD_TABLE(DCS_X)                                                                                                 \
   DCS_X(GET_HOST_ANALOG_INPUTS_0TO30, Get_Host_Analog_Inputs_0to30)                                                              \
   DCS_X(GET_HOST_ANALOG_INPUTS_31TO61, Get_Host_Analog_Inputs_31to61)                                                            \
   DCS_X(GET_FILTERED_ADC_INPUTS_0TO30, Get_Host_Filtered_Analog_Inputs_0to30)                                                    \
   DCS_X(GET_FILTERED_ADC_INPUTS_31TO61, Get_Host_Filtered_Analog_Inputs_31to61)                                                  \
   DCS_X(GET_RADAR_TARGET, Get_Radar_Target)                                                                                      \
   DCS_X(GET_START_ADDRESS_SIZE_EVENT_INFO, Get_Start_Address_Size_Event_Info)                                                    \
   DCS_X(SINGLE_LOOK_MODE, Single_Look_Mode)                                                                                      \
   DCS_X(SET_RADAR_TO_CW_MODE, Set_Radar_To_CW_Mode)                                                                              \
   DCS_X(FAKE_INJECT_FAULT, Inject_Fault)                                                                                         \
   DCS_X(RADAR_TRANSMITTER_ENABLE, Radar_Transmitter_Enable)                                                                      \
   DCS_X(READ_HARDWARE_VERSION, Read_Hardware_Version)                                                                            \
   DCS_X(ITV_SIMULATION_CONTROL, ITV_Simulation_Control)                                                                          \
   DCS_X(SET_OPERATION_MODE, Set_Operation_Mode)                                                                                  \
   DCS_X(CLEAR_INTERNAL_FAULT_CODES, Clear_Internal_Fault_Codes)                                                                  \
   DCS_X(GET_MCU_ID, Get_MCU_ID)                                                                                                  \
   DCS_X(GET_TRANSCIEVER_CHIP_ID, Get_Transciever_Chip_ID)                                                                        \
   DCS_X(GET_MMIC_MCU_TEMP, Get_MMIC_MCU_Temp)                                                                                    \
   DCS_X(GET_SW_VERSION, Get_SW_Version)                                                                                          \
   DCS_X(OVERRIDE_MEMORY_FAULT, Override_Memory_Fault)                                                                            \
   DCS_X(TARGET_SELECT, Target_Select)                                                                                            \
   DCS_X(STOP_TRANSMITTING_PERIODIC_MSGS, Stop_Transmitting_Periodic_Msgs)                                                        \
   DCS_X(SET_OVERRIDE_CONTROL_VARIABLE, Set_Override_Control_Variable)                                                            \
   DCS_X(GET_OVERRIDE_CONTROL_VARIABLE, Get_Override_Control_Variable)                                                            \
   DCS_X(ERASE_DATA_FLASH, Data_Flash)                                                                                            \
   DCS_X(SET_OUTPUT_STATE, Set_Output_State)                                                                                      \
   DCS_X(WRITE_ALIGNMENT_DATA, Write_Alignment_Data)                                                                              \
   DCS_X(GET_HISTORY_FAULT, Get_History_Fault)                                                                                    \
   DCS_X(GET_ACTIVE_FAULT, Get_Active_Fault)                                                                                      \
   DCS_X(GET_ACTIVE_FAULT_LATCHED, Get_Active_Fault_Latched)                                                                      \
   DCS_X(GET_FAULT_TEST_COMPLETED, Get_Fault_Test_Completed)                                                                      \
   DCS_X(READ_ALIGNMENT_DATA, Read_Alignment_Data)                                                                                \
   DCS_X(GET_CHECKSUM_RESULTS, Get_Checksum_Results)                                                                              \
   DCS_X(READ_WRITE_DID, Read_Write_DID)                                                                                          \
   DCS_X(PHASE_ROTATOR_CALIBRATION, Phase_Rotator_Calibration)                                                                    \
   DCS_X(RADAR_TRANSCEIVER_CALIBRATION, Radar_Transceiver_Calibration)

/* not enabled as of now                                                                                                         \
   DCS_X(GET_MMIC_MCU_TEMP, get_mmic_mcu_temp)                                                                                   \
   DCS_X(INTERFACE_CONTROL, interface_control)                                                                                   \
   DCS_X(HIL_MODE, hil_mode)                                                                                                     \
   DCS_X(ELECTRONIC_CHIP_ID, read_electronic_chipid)                                                                             \
   DCS_X(DSP_SIMULATION, dsp_simulation)                                                                                         \
   DCS_X(JTAG_PASSWORD_UPDATE, jtag_password_update)                                                                             \
   DCS_X(LIFECYCLE_UPDATE, lifecycle_update)                                                                                     \
   DCS_X(JTAG_PASSWORD_READ, jtag_password_read)                                                                                 \
   DCS_X(RADAR_TRANSCIEVER_CALIBRATION, radar_transciever_calibration)                                                           \
   DCS_X(GET_MMIC_DEBUG_INFO, get_mmic_debug_info)                                                                               \
   DCS_X(GET_ENABLED_FAULT_TABLE_BYTES, get_enabled_fault_table_bytes) \*/

#define XCP_USER_CMD_ENUM(cmd_idx, cmd_function) XUC_##cmd_idx,
#define XCP_USER_CMD_LIST(cmd_idx, cmd_function) XCP_USER_CMD_##cmd_idx,
#define XCP_USER_CMD_FUNC(cmd_idx, cmd_function) XCP_User_Cmd_##cmd_function,

/*===========================================================================*
 * Exported Type Declarations
 *===========================================================================*/
typedef enum XCP_User_Cmd_Tag
{
   XCP_USER_CMD_TABLE(XCP_USER_CMD_ENUM) XUC_MAX
} XCP_User_Cmd_T;

typedef uint8_t (*const XCP_User_Cmd_Fptr)(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd, uint8_t *response,
                                           uint8_t *framelength);

typedef enum XCP_Special_Operation_Mode_Tag
{
   XCP_NORMAL_MODE,
   XCP_VALIDATION_MANUFACTURING_TEST_MODE,
   XCP_CW_MODE,
   XCP_OVERRIDE_OPERATION_MESSAGE_MODE,
   XCP_USC_PROGRAMMING_MODE,
   XCP_SMC_PROGRAMMING_MODE,
   XCP_OTP_PROGRAMMING_MODE,
   XCP_INVALID_MODE
} XCP_Special_Operation_Mode_T;

typedef union XCP_Target_Info_Res_Tag
{
   uint8_t data[DATA_BYTES_LEN];
   struct
   {
      uint8_t response;               /* Byte 0 */
      uint8_t subcmd_code;            /* Byte 1 */
      uint8_t lrll_target_range_msb;  /* Byte 2 */
      uint8_t lrll_target_range_lsb;  /* Byte 3 */
      uint8_t lrll_target_rcs_msb;    /* Byte 4 */
      uint8_t lrll_target_rcs_lsb;    /* Byte 5 */
      uint8_t lrll_target_rdot_msb;   /* Byte 6 */
      uint8_t lrll_target_rdot_lsb;   /* Byte 7 */
      uint8_t lrll_target_az_ang_msb; /* Byte 8 */
      uint8_t lrll_target_az_ang_lsb; /* Byte 9 */
      uint8_t lrll_target_el_ang_msb; /* Byte 10 */
      uint8_t lrll_target_el_ang_lsb; /* Byte 11 */

      uint8_t lrml_target_range_msb;  /* Byte 12 */
      uint8_t lrml_target_range_lsb;  /* Byte 13 */
      uint8_t lrml_target_rcs_msb;    /* Byte 14 */
      uint8_t lrml_target_rcs_lsb;    /* Byte 15 */
      uint8_t lrml_target_rdot_msb;   /* Byte 16 */
      uint8_t lrml_target_rdot_lsb;   /* Byte 17 */
      uint8_t lrml_target_az_ang_msb; /* Byte 18 */
      uint8_t lrml_target_az_ang_lsb; /* Byte 19 */
      uint8_t lrml_target_el_ang_msb; /* Byte 20 */
      uint8_t lrml_target_el_ang_lsb; /* Byte 21 */

      uint8_t mrll_target_range_msb;  /* Byte 22 */
      uint8_t mrll_target_range_lsb;  /* Byte 23 */
      uint8_t mrll_target_rcs_msb;    /* Byte 24 */
      uint8_t mrll_target_rcs_lsb;    /* Byte 25 */
      uint8_t mrll_target_rdot_msb;   /* Byte 26 */
      uint8_t mrll_target_rdot_lsb;   /* Byte 27 */
      uint8_t mrll_target_az_ang_msb; /* Byte 28 */
      uint8_t mrll_target_az_ang_lsb; /* Byte 29 */
      uint8_t mrll_target_el_ang_msb; /* Byte 30 */
      uint8_t mrll_target_el_ang_lsb; /* Byte 31 */

      uint8_t mrml_target_range_msb;  /* Byte 32 */
      uint8_t mrml_target_range_lsb;  /* Byte 33 */
      uint8_t mrml_target_rcs_msb;    /* Byte 34 */
      uint8_t mrml_target_rcs_lsb;    /* Byte 35 */
      uint8_t mrml_target_rdot_msb;   /* Byte 36 */
      uint8_t mrml_target_rdot_lsb;   /* Byte 37 */
      uint8_t mrml_target_az_ang_msb; /* Byte 38 */
      uint8_t mrml_target_az_ang_lsb; /* Byte 39 */
      uint8_t mrml_target_el_ang_msb; /* Byte 40 */
      uint8_t mrml_target_el_ang_lsb; /* Byte 41 */

      bool bistatic_flag_lrll; /* Byte 42*/
      bool bistatic_flag_lrml; /* Byte 43*/
      bool bistatic_flag_mrll; /* Byte 44*/
      bool bistatic_flag_mrml; /* Byte 45*/
   } byte;
} XCP_Target_Info_Res_T;

typedef struct XCP_Target_Info_Valid_Trgt_Tag
{
   s8p7_T target_range;
   s8p7_T target_range_rate;
   float target_angle;
   s8p7_T target_rcs;
   s8p7_T target_elevation;
   float det_elevation;
   uint16_t target_idx;
   bool bistatic;
} XCP_Target_Info_Valid_Trgt_T;

typedef struct XCP_Target_Info_Tag
{
   XCP_Target_Info_Res_T response;
   XCP_Target_Info_Valid_Trgt_T valid_target;

   s8p7_T range_min;
   s8p7_T range_max;
   s8p7_T rrate_min;
   s8p7_T rrate_max;

   uint8_t look_enable_phy;
   uint8_t range_min_phy;
   uint8_t range_max_phy;
   uint8_t rrate_min_phy;
   uint8_t rrate_max_phy;
   uint8_t phys_range_phy;

   uint8_t process_look_A;
   uint8_t process_look_B;
   uint8_t process_look_C;
   uint8_t process_look_D;

} XCP_Target_Info_T;

typedef enum XCP_Debug_Device_Tag
{
   XCP_DEVICE_MCU_RRU2 = 1,
   XCP_DEVICE_MMIC1,
   XCP_DEVICE_MMIC2,
   XCP_DEVICE_MCU_RRM
} XCP_Debug_Device_T;

typedef enum XCP_Debug_Data_Tag
{
   XCP_DATA_MMIC_INIT_STATUS = 1,
   XCP_DATA_PERSISTANT_ISM_STATUS,
   XCP_DATA_PERSISTANT_OSM_STATUS,
   XCP_DATA_OSM_FAULT_COUNTERS,
   XCP_DATA_MIPI_STATUS_FAULT_COUNTERS,
   XCP_DATA_SW_API_ID
} XCP_Debug_Data_T;

typedef enum XCP_Data_Flash_Process_Tag
{
   XCP_NVM_STATUS_PENDING = 1,
   XCP_NVM_STATUS_SUCCESS,
   XCP_NVM_STATUS_FAIL
} XCP_Data_Flash_Process_T;

typedef struct XCP_Data_Flash_Tag
{
   uint8_t nvm_cmnd;
   uint8_t nvm_erase_status;
} XCP_Data_Flash_T;

typedef struct XCP_DID_Tag
{
   uint16_t DID;
   uint8_t service_id;
} XCP_DID_T;

typedef struct XCP_JTAG_Cmd_Tag
{
   uint8_t xcp_jtag_cmnd_rcvd;
   uint8_t cycle_cnt;
} XCP_JTAG_Cmd_T;

typedef struct XCP_LifeCycle_Cmd_Tag
{
   uint8_t xcp_LC_cmnd_rcvd;
   uint8_t cycle_cnt;
   uint8_t sub_cmd;
} XCP_LifeCycle_Cmd_T;

typedef struct XCP_DID_Data_Cmd_Tag
{
   uint16_t DID;
   uint8_t service_id;
   uint8_t Data[61];
} XCP_DID_Data_Cmd_T;

/*===========================================================================*\
 * Exported Object Declarations
\*===========================================================================*/

/*===========================================================================*\
 * Exported Function Prototypes
\*===========================================================================*/

/*===========================================================================*\
 * Exported Inline Function Definitions and #define Function-Like Macros
\*===========================================================================*/

/*===========================================================================*\
* File Revision History (top to bottom: first revision to last revision)
*===========================================================================
*
* Date        userid      jira ticket   (Description on following lines: SCR #, etc.)
* ----------- --------
* 10-Aug-2024 alkjpl   DNP-3434: Bringing Inital commands to  Gen 8.
* 04-Sep-2024 alkjpl   DNP-4983: Bringing Up ADC commands (F1 A0/A1/A2/A3)
\*===========================================================================*/
#endif /* } XCP_USER_CMDS_H */
