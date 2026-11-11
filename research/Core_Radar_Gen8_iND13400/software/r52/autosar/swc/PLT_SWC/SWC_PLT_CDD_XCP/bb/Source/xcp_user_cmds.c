/*===========================================================================*/
/**
 * @file xcp_user_cmds.c
 *
 *   Add a one line description of the implementation.
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
 *   Add full description here
 *
 * @section ABBR ABBREVIATIONS:
 *   -   List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     -   Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     -   Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - <a href="https://spo.aptiv.com/sites/0307-eoses/globalregional/ESGW_4-2_PE-SWx_00-01-A02_EN.docx">
 *       ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]</a>
 *     -   Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   -   List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/

/*===========================================================================*\
* Standard Header Files
\*===========================================================================*/
#include "xcp_user_cmds.h"
#include "reuse.h"
#include <string.h> /*WARNING:this is for memset and memcpy function*/

/*===========================================================================*\
* Other Header Files
\*===========================================================================*/
#include "radar_look_types.h"

/*===========================================================================*\
 * Local Preprocessor #define Constants
\*===========================================================================*/
#define XCP_POSITIVE_RESPONSE_CPV ((uint8_t)0xFF)
#define XCP_NEGATIVE_RESPONSE_CPV ((uint8_t)0xFE)

#define XCP_DEFAULT_RESPONSE ((uint8_t)0xFF)

#define XCP_MAX_ANALOG_INPUTS_PER_FRAME ((uint8_t)31)
#define XCP_ADC_MAX_WAIT_TIME           ((uint8_t)3)

#define XCP_TARGET_RANGE_RES             (Init_Fixed_Point(0.5F, u0p8_T))
#define XCP_TARGET_RRATE_LIMIT_MAX       ((uint8_t)17)
#define XCP_TRAGET_PHYS_RANAGE_MAX       ((uint8_t)30)
#define XCP_TRAGET_MAX_WAIT_TIME         ((uint8_t)5) /* 5 Radar cycle (250ms)*/
#define XCP_TARGET_RANGE_RESOLUTION      Init_Fixed_Point(200, u8p0_T)
#define XCP_TARGET_RANGE_RATE_RESOLUTION Init_Fixed_Point(200, u8p0_T)
#define XCP_TARGET_AMP_RESOLUTION        Init_Fixed_Point(200, u8p0_T)
#define XCP_TARGET_ANGLE_RESOLUTION      ((uint8_t)100)
#define XCP_TARGET_ELEVATION_RESOLUTION  ((uint8_t)100)
#define XCP_MEMORY_FAULT_BIT_MAX_SIZE    ((uint8_t)8)
#define XCP_TARGET_MAX_LOOK_SIZE         ((uint8_t)0x0F)
#define XCP_TARGET_NO_LOOK               ((uint8_t)0)

#define RAD2DEG (float32_t)(180.0 / 3.14159265358979)

/*macros related to Target Select cmnd*/
#define XCP_TARGET_RANGE_INDEX_SIZE   ((uint8_t)2)
#define XCP_TARGET_DOPPLER_INDEX_SIZE ((uint8_t)2)

/* checksum cal timeout */
#define XCP_CHKSUM_CAL_TIME_OUT ((uint8_t)61)
#define XCP_ADC_MAX_WAIT_TIME   ((uint8_t)3) /* 3 Radar cycle (150ms)*/

#define XCP_RES_LEN_2 ((uint8_t)0x02)
#define XCP_RES_LEN_3 ((uint8_t)0x03)
#define XCP_RES_LEN_4 ((uint8_t)0x04)
#define XCP_RES_LEN_5 ((uint8_t)0x05)
#define XCP_RES_LEN_8 ((uint8_t)0x08)

#define XCP_RES_OFFSET_2 ((uint8_t)0x02)
#define XCP_RES_OFFSET_5 ((uint8_t)0x05)

/*Macros For Checking Sub Command Values */
#define XCP_SUB_CMD_VAL_6 ((uint8_t)0x06)

/* Macro for Sensitivity Scaling Factor F1 22, F1 23*/
#define XCP_SENS_SCALING_FACTOR ((uint8_t)0x01)
#define XCP_CNTRL_VARIABLE      ((uint8_t)0x01)

/* Macro for daq FRAMELENGTH*/
#define XCP_DAQ_FRAMELENGTH ((uint8_t)0x3A)

/* Macro for RFBIST Compuatation*/
#define XCP_GAIN_PHASE_OFFSET_VAL_3 ((uint8_t)0x03)
#define XCP_GAIN_PHASE_OFFSET_VAL_5 ((uint8_t)0x05)

/* Macro for Address size info F1 06*/
#define XCP_MIN_ADDRS_SIZE_INFO ((uint8_t)0x01)
#define XCP_MAX_ADDRS_SIZE_INFO ((uint8_t)0x05)

/* Macro for Address size info F1 06*/
#define XCP_MMIC_DEVICE_1 ((uint8_t)0x01)
#define XCP_MMIC_DEVICE_2 ((uint8_t)0x02)

/* Macro for Force Radiate F1 02*/
#define XCP_FORCE_RADAR_NORMAL_OP ((uint8_t)0x01)
#define XCP_FORCE_RADIATE_ON      ((uint8_t)0x02)
#define XCP_FORCE_RADIATE_OFF     ((uint8_t)0x03)

#define XCP_TARGET_ANGLE_IN_DEGREE        (30.2F)
#define XCP_DETECTION_ELEVATION_IN_DEGREE (1.1F)

#define XCP_MAX_MMIC_TX_TEMP_SENSORS     ((uint8_t)8)
#define XCP_TX_SENSORS_EACH_MMIC         ((uint8_t)7)
#define XCP_MAX_MCU_TEMP_SENSORS         ((uint8_t)2)
#define XCP_MIN_MMIC_MCU_TX_TEMP_SENSORS ((uint8_t)1)

#define XCP_MMIC_MCU_TEMP_OFFSET ((int16_t)50)

/* F1 9F */
#define XCP_MCU_MMIC_TEMP_DEFAULT     ((int16_t)999)
#define XCP_MMIC_MCU_TEMP_FRAMELENGTH ((uint8_t)0x0E)

/* F1 97, F1 98 */
#define XCP_MCU_ID_LEN_IN_BYTES      ((uint8_t)12)
#define XCP_UNIQUE_ID_LEN_IN_BYTES   ((uint8_t)8)
#define XCP_TARGET_CHIPID_MAX_LENGTH ((uint8_t)36)

/* F1 12 */
#define XCP_INJECT_MM_FALUT_SUBCMD  (0x01U)
#define XCP_INJECT_MM3_FALUT_SUBCMD (0x04U)
#define XCP_INJECT_MM4_FALUT_SUBCMD (0x03U)

#define XCP_INJECT_RPD1_FAULT_SUBCMD (0x01U)

/* F1 0F command */
#define XCP_ITV_EVENT_START ((uint8_t)1)
#define XCP_ITV_EVENT_END   ((uint8_t)0x1F)

/* F1 1F command */
#define XCP_OUTPUT_START_PIN ((uint8_t)1)
#define XCP_OUTPUT_END_PIN   ((uint8_t)20)

/* override timeout */
#define XCP_OVERRIDE_TIMEOUT ((uint8_t)61)

/*F1 30/31*/
#define XCP_ALIGNMENT_DATA_LENGTH            ((uint8_t)0x04)
#define XCP_ALIGNMENT_READ_HEADER            ((uint8_t)0x04)
#define XCP_WRITE_ALIGNMENT_TIMEOUT          (101U)
#define XCP_READ_ALIGNMENT_SUBCMD_START      (0x01U)
#define XCP_READ_ALIGNMENT_SUBCMD_END        (0x05U)
#define XCP_WRITE_ALIGNMENT_NO_OF_DATA_TYPES (0x02U)
#define XCP_READ_ALIGNMENT_NO_OF_DATA_TYPES  (0x02U)

/*F1 13 */
/* macros related to Read/Write DID */
#define XCP_DID_MINIMUM_LENGTH   (3U)
#define XCP_DID_MAXIMUM_LENGTH   (61U)
#define XCP_DID_READ_DATA        (0x22U)
#define XCP_DID_READ_DATA_OFFSET (0x40U)
#define XCP_DID_WRITE_DATA       (0x2EU)
#define XCP_WRITE_DID_TIMEOUT    (101U)

/* F1 99*/
/* RFBist Debug data */
#define XCP_RFBIST_DEBUG_DATA_SUBCMD_START ((uint8_t)0x01)
#define XCP_RFBIST_DEBUG_DATA_SUBCMD_END   ((uint8_t)0x0B)

/*===========================================================================*\
 * Local Preprocessor #define MACROS
\*===========================================================================*/
#define MAX_XCP_USER_CMD ((uint8_t)XUC_MAX)

#define XCP_RADAR_LOOK_A ((uint8_t)(RADAR_LOOK_A))
#define XCP_RADAR_LOOK_B ((uint8_t)(RADAR_LOOK_B))
#define XCP_RADAR_LOOK_C ((uint8_t)(RADAR_LOOK_C))
#define XCP_RADAR_LOOK_D ((uint8_t)(RADAR_LOOK_D))

#define USER_CMD_FUNCTION_PROTOTYPE_PARAMS                                                                                        \
   XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd, uint8_t *response, uint8_t *framelength

#define XCP_USER_CMD_FUNC_PROTO(cmd_idx, cmd_function) /* NOLINTNEXTLINE */                                                       \
   static uint8_t XCP_User_Cmd_##cmd_function(USER_CMD_FUNCTION_PROTOTYPE_PARAMS);

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/
XCP_USER_CMD_TABLE(XCP_USER_CMD_FUNC_PROTO)

static uint8_t Get_Analog_Inputs(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd, uint8_t *response,
                                 uint8_t *framelength);
static uint8_t Get_Filtered_Analog_Inputs(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd, uint8_t *response,
                                          uint8_t *framelength);

static bool No_Active_Look(uint8_t *ptr[], const uint8_t size);
static bool Is_Value_Within_Range(s8p7_T value, s8p7_T min, s8p7_T max, bool ignore);
static bool Compute_Target_Parameters(uint8_t *response_ptr, XCP_Target_Info_Valid_Trgt_T *valid_tgt_ptr);
static void Swap_Values_As_Per_Need(s8p7_T *p1, s8p7_T *p2);
static void Debug_Mode_Radar_Target(XCP_Target_Info_Valid_Trgt_T *xcp_valid_target_ptr);
static void Validate_Parameters_Of_XCP_Target(XCP_Target_Info_T *const xcp_target_info_ptr);
static void Search_Valid_Target(volatile XCP_Target_Report_T *xcp_tgt_rep_ptr, XCP_Target_Info_T *const xcp_target_info_ptr,
                                const uint16_t xcp_num_max_dets);

/* periodic tasks */
static uint8_t XCP_ADC_Info_Periodic_Task(XCP_BB_Input_Params_T *const xcp_input_ptr, uint8_t *response, uint8_t *framelength);
static uint8_t XCP_Filtered_ADC_Info_Periodic_Task(XCP_BB_Input_Params_T *const xcp_input_ptr, uint8_t *response,
                                                   uint8_t *framelength);
static uint8_t XCP_Target_Info_Periodic_Task(XCP_BB_Input_Params_T *const xcp_input_ptr, uint8_t *response, uint8_t *framelength);
static uint8_t XCP_Set_Override_Periodic_Task(XCP_BB_Input_Params_T *const xcp_input_ptr, uint8_t *response, uint8_t *framelength);
static uint8_t XCP_Write_Alignment_Periodic_Task(XCP_BB_Input_Params_T *const xcp_input_ptr, uint8_t *response,
                                                 uint8_t *framelength);
static uint8_t XCP_DID_Periodic_Task(XCP_BB_Input_Params_T *const xcp_input_ptr, uint8_t *response, uint8_t *framelength);

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
static XCP_Periodic_User_Cmd_T XCP_Periodic_User_Cmd = {NULL, CODED_FALSE, 0, 0, 0};

static uint8_t XCP_ADC_Quantity          = 0U;
static uint8_t XCP_Filtered_ADC_Quantity = 0U;

/* F1 90 */
static XCP_Target_Info_T XCP_Target_Info = {0};

static const s7p0_T XCP_Rrate_Limit[XCP_TARGET_RRATE_LIMIT_MAX] = {0,  50, 40, 25,  10,  5,   2,   1, 0,
                                                                   -1, -2, -5, -10, -25, -40, -50, 0};

static XCP_Data_Flash_T XCP_Data_Flash = {CODED_FALSE, CODED_FALSE};

static uint16_t XCP_Override_Data = 0U;

/* F1 30 */
/* table hold the no of paramets and data size of the each parameter*/
static uint8_t XCP_Select_Align_Type[2][2] = {/* no_of_parameters, no_of_bytes per parameter , */
                                              {0U, sizeof(float32_t)},
                                              {1U, sizeof(uint8_t)}};

static uint8_t XCP_Nvm_Align_Data[2][2] = {/* no_of_parameters, no_of_bytes, */
                                           {15U, sizeof(float32_t)},
                                           {0U, sizeof(uint8_t)}};

static uint8_t (*XCP_Write_Align_Data_Info[2])[2][2] = {&XCP_Select_Align_Type, &XCP_Nvm_Align_Data};

/* F1 31 */
/* table hold the no of paramets and data size of the each parameter*/
static uint8_t XCP_Read_Align_Mode[2][2] = {/* no_of_parameters, no_of_bytes per parameter , */
                                            {0U, sizeof(float32_t)},
                                            {1U, sizeof(uint8_t)}};

static uint8_t XCP_Read_Align_Nvm[2][2] = {/* no_of_parameters, no_of_bytes per parameter , */
                                           {15U, sizeof(float32_t)},
                                           {0U, sizeof(uint8_t)}};

static uint8_t XCP_Read_Align_Result[2][2] = {/* no_of_parameters, no_of_bytes, */
                                              {7U, sizeof(float32_t)},
                                              {5U, sizeof(uint8_t)}};

static uint8_t XCP_Read_Align_Performance[2][2] = {/* no_of_parameters, no_of_bytes per parameter , */
                                                   {12U, sizeof(float32_t)},
                                                   {1U, sizeof(uint8_t)}};

static uint8_t XCP_Read_Align_Auto_1[2][2] = {/* no_of_parameters, no_of_bytes, */
                                              {15U, sizeof(float32_t)},
                                              {0U, sizeof(uint8_t)}};

static uint8_t XCP_Read_Align_Auto_2[2][2] = {/* no_of_parameters, no_of_bytes, */
                                              {0U, sizeof(float32_t)},
                                              {2U, sizeof(uint8_t)}};

static uint8_t (*XCP_Read_Align_Data_Info[6])[2][2] = {&XCP_Read_Align_Mode,   &XCP_Read_Align_Nvm,
                                                       &XCP_Read_Align_Result, &XCP_Read_Align_Performance,
                                                       &XCP_Read_Align_Auto_1, &XCP_Read_Align_Auto_2};

/* F1 13 */
static XCP_DID_T XCP_DID_Cmd = {0, 0};

static uint8_t XCP_User_Cmd_List[MAX_XCP_USER_CMD] = {XCP_USER_CMD_TABLE(XCP_USER_CMD_LIST)};

static XCP_User_Cmd_Fptr XCP_User_Cmd_Func_List[MAX_XCP_USER_CMD] = {XCP_USER_CMD_TABLE(XCP_USER_CMD_FUNC)};

/*===========================================================================*\
* External Object Declarations
\*===========================================================================*/
XCP_Periodic_User_Cmd_T *const XCP_Periodic_User_Cmd_Ptr = &XCP_Periodic_User_Cmd;

/*===========================================================================*\
 * Local Inline Function Definitions and Function-Like Macros
\*===========================================================================*/
#define XCP_Periodic_Cycle_Cnt (XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt)
#define XCP_Periodic_Cycle_Max (XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max)
#define Is_Cycle_Cnt_Valid     (XCP_Periodic_Cycle_Cnt < XCP_Periodic_Cycle_Max)
#define Is_Cycle_Cnt_Timedout  (XCP_Periodic_Cycle_Cnt == XCP_Periodic_Cycle_Max)

/*===========================================================================*\
* Function Definitions
\*===========================================================================*/
/**
 * FUNCTION:No_Active_Look
 * This function checks if all looks are inactive (disabled) by performing a bitwise OR operation
 * on all look enable status pointers. Returns true if no active looks are found, false otherwise.
 *
 * \param[in] uint8_t **ptr - Pointer to array of pointers to look enable status values
 * \param[in] const uint8_t size - Number of look pointers in the array (typically NUM_ELEMS(ptr))
 *
 * \return bool - true if all looks are inactive (no active looks), false if at least one look is active
 *
 * \remark
 * \ServID xx
 * \Reentrancy non-reentrant
 * \Synchronism synchronous
 * \Precondition ptr must be a valid array of pointers to uint8_t values
 * \Caveats The function returns true only when all referenced values are CODED_FALSE
 * TRACEABILITY INFO:
 *
 */
static bool No_Active_Look(uint8_t *ptr[], const uint8_t size)
{
   uint8_t idx;
   bool result = true;

   for (idx = 0U; idx < size; idx++)
   {
      if (CODED_FALSE != *ptr[idx])
      {
         result = false;
         break;
      }
   }
   return result;
}

/**
 * FUNCTION:Set_XCP_Periodic_User_Cmd
 * This function initializes the periodic user command structure with callback function and timeout parameters.
 * Sets up the periodic task to be executed and tracks the command value for response.
 *
 * \param[in] uint8_t cmd - The XCP user command value to be tracked
 * \param[in] uint8_t max_cnt - Maximum cycle count before timeout (timeout threshold)
 * \param[in] XCP_Periodic_User_Cmd_Task_Fptr fptr - Function pointer to the periodic task handler
 *
 * \return void
 *
 * \remark
 * \ServID xx
 * \Reentrancy non-reentrant
 * \Synchronism synchronous
 * \Precondition fptr must be a valid function pointer or NULL
 * \Caveats If fptr is NULL, xcp_periodic_user_cmd_rcvd is set to CODED_FALSE
 * TRACEABILITY INFO:
 *
 * SDD
 * WorkItem 1 : WI-306246
 *
 * SRD
 * WorkItem 1 : WI-306245
 * \\input{Set_XCP_Periodic_User_Cmd}
 */
static void Set_XCP_Periodic_User_Cmd(uint8_t cmd, uint8_t max_cnt, XCP_Periodic_User_Cmd_Task_Fptr fptr)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cmnd_fptr     = fptr;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = 0U;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max = max_cnt;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = (NULL != fptr) ? CODED_TRUE : CODED_FALSE;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_val  = cmd;
}

/**
 * FUNCTION:Prepare_Negative_Response
 * This function prepares a negative response packet for XCP commands.
 * It sets the response header with negative response code and error code.
 *
 * \param[out] uint8_t *response_ptr - Pointer to response buffer where negative response will be written
 * \param[in] XCP_Err_Code_T error - Error code to be included in the response
 *
 * \return uint8_t - Frame length of the negative response (always 2 bytes)
 *
 * \remark
 * \ServID xx
 * \Reentrancy non-reentrant
 * \Synchronism synchronous
 * \Precondition response_ptr must point to a valid buffer with at least 2 bytes
 * \Caveats None
 * TRACEABILITY INFO:
 *
 * SDD
 * WorkItem 1 : WI-306246
 *
 * SRD
 * WorkItem 1 : WI-306245
 * \\input{Prepare_Negative_Response}
 */
static uint8_t Prepare_Negative_Response(uint8_t *response_ptr, XCP_Err_Code_T error)
{
   uint8_t resp_index         = 0U;
   response_ptr[resp_index++] = XCP_NEGATIVE_RESPONSE_CPV;
   response_ptr[resp_index++] = (uint8_t)error;
   return (resp_index);
}

/**
 * FUNCTION:Get_Process_Look_Validity
 * This function checks if a radar look is enabled using bit mask operation.
 * Returns CODED_TRUE if bit is set, CODED_FALSE if bit is clear.
 *
 * \param[in] uint8_t cmd - Command byte containing look enable bitmask
 * \param[in] uint8_t look_enum - Look enumeration value to check
 * \param[in] XCP_Look_Enable_Status_fptr_T fptr - Function pointer to check SMC enablement
 *
 * \return uint8_t - CODED_TRUE if look is enabled, CODED_FALSE otherwise
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
 *
 * SRD
 * WorkItem 1 :
 * \\input{Get_Process_Look_Validity}
 */
static uint8_t Get_Process_Look_Validity(uint8_t cmd, uint8_t look_enum, XCP_Look_Enable_Status_fptr_T fptr)
{
   uint8_t ret_value;
   uint8_t mask = cmd & (uint8_t)MASK_BIT(look_enum);

   if (mask > 0U)
   {
      /* check for the SMC enablement */
      ret_value = (*fptr)(look_enum);
   }
   else
   {
      ret_value = CODED_FALSE;
   }

   return ret_value;
}

/**
 * FUNCTION:Debug_Mode_Radar_Target
 * This function populates the valid target structure with debug mode test values
 * when XCP_DEBUG_MODE is defined. Otherwise, no operation is performed.
 *
 * \param[in,out] XCP_Target_Info_Valid_Trgt_T *xcp_valid_target_ptr - Pointer to valid target structure
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
 *
 * SRD
 * WorkItem 1 :
 * \\input{Debug_Mode_Radar_Target}
 */
static void Debug_Mode_Radar_Target(XCP_Target_Info_Valid_Trgt_T *xcp_valid_target_ptr)
{
#ifdef XCP_DEBUG_MODE
   xcp_valid_target_ptr->target_idx        = 2U;
   xcp_valid_target_ptr->target_angle      = XCP_TARGET_ANGLE_IN_DEGREE;
   xcp_valid_target_ptr->det_elevation     = XCP_DETECTION_ELEVATION_IN_DEGREE;
   xcp_valid_target_ptr->target_range      = Init_Fixed_Point(20.05, s8p7_T);
   xcp_valid_target_ptr->target_range_rate = Init_Fixed_Point(1.13, s8p7_T);
   xcp_valid_target_ptr->target_rcs        = Init_Fixed_Point(11, s8p7_T);
#else
   xcp_valid_target_ptr->target_idx += 0U;
#endif
}

/**
 * FUNCTION:Get_XCP_User_Cmd_Index
 *. This function implements logic to fetch xcp user command index
 *
 * \param[in] const uint8_t cmd_value
 *
 * \return uint8_t
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
 *
 * SRD
 * WorkItem 1 :
 * \\input{XCP_User_Command}
 */
static uint8_t Get_XCP_User_Cmd_Index(const uint8_t cmd_value)
{
   uint8_t i;
   uint8_t ret_value = MAX_XCP_USER_CMD;
   bool flag         = false;

   for (i = 0U; i < MAX_XCP_USER_CMD; i++)
   {
      if (!flag)
      {
         if (XCP_User_Cmd_List[i] == cmd_value)
         {
            ret_value = i;
            flag      = true;
         }
      }
   }
   return ret_value;
}

/**
 * FUNCTION:XCP_User_Cmd_Get_Host_Analog_Inputs_0to30
 * This function implements xcp command to get host analog input values 0 to 30.
 * Command: XCP_USER_CMD_GET_HOST_ANALOG_INPUTS_0TO30 (F1 A0)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr - Pointer to XCP building block input parameters
 * \param[in] const uint8_t *cmnd - Pointer to received command buffer
 * \param[out] uint8_t *response - Pointer to response buffer
 * \param[out] uint8_t *framelength - Pointer to response frame length
 *
 * \return uint8_t - Command status
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
 *
 * SRD
 * WorkItem 1 :
 * \\input{XCP_User_Cmd_Get_Host_Analog_Inputs_0to30}
 */
static uint8_t XCP_User_Cmd_Get_Host_Analog_Inputs_0to30(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd,
                                                         uint8_t *response, uint8_t *framelength)
{
   uint8_t ret_value;
   ret_value = Get_Analog_Inputs(xcp_input_ptr, cmnd, response, framelength);
   return ret_value;
}

/**
 * FUNCTION:XCP_User_Cmd_Get_Host_Analog_Inputs_31to61
 * This function implements xcp command to get host analog input values 31 to 61.
 * Command: XCP_USER_CMD_GET_HOST_ANALOG_INPUTS_31TO61 (F1 A1)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr - Pointer to XCP building block input parameters
 * \param[in] const uint8_t *cmnd - Pointer to received command buffer
 * \param[out] uint8_t *response - Pointer to response buffer
 * \param[out] uint8_t *framelength - Pointer to response frame length
 *
 * \return uint8_t - Command status
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
 *
 * SRD
 * WorkItem 1 :
 * \\input{XCP_User_Cmd_Get_Host_Analog_Inputs_31to61}
 */
static uint8_t XCP_User_Cmd_Get_Host_Analog_Inputs_31to61(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd,
                                                          uint8_t *response, uint8_t *framelength)
{
   uint8_t ret_value;
   ret_value = Get_Analog_Inputs(xcp_input_ptr, cmnd, response, framelength);
   return ret_value;
}

/**
 * FUNCTION:XCP_User_Cmd_Get_Host_Filtered_Analog_Inputs_0to30
 * This function implements xcp command to get host analog filtered input values 0 to 30.
 * Command: XCP_USER_CMD_GET_FILTERED_ADC_INPUTS_0TO30 (F1 A2)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr - Pointer to XCP building block input parameters
 * \param[in] const uint8_t *cmnd - Pointer to received command buffer
 * \param[out] uint8_t *response - Pointer to response buffer
 * \param[out] uint8_t *framelength - Pointer to response frame length
 *
 * \return uint8_t - Command status
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
 *
 * SRD
 * WorkItem 1 :
 * \\input{XCP_User_Cmd_Get_Host_Filtered_Analog_Inputs_0to30}
 */
static uint8_t XCP_User_Cmd_Get_Host_Filtered_Analog_Inputs_0to30(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd,
                                                                  uint8_t *response, uint8_t *framelength)
{
   uint8_t ret_value;
   ret_value = Get_Filtered_Analog_Inputs(xcp_input_ptr, cmnd, response, framelength);
   return ret_value;
}

/**
 * FUNCTION:XCP_User_Cmd_Get_Host_Filtered_Analog_Inputs_31to61
 * This function implements xcp command to get host analog filtered input values 31 to 61.
 * Command: XCP_USER_CMD_GET_FILTERED_ADC_INPUTS_31TO61 (F1 A3)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr - Pointer to XCP building block input parameters
 * \param[in] const uint8_t *cmnd - Pointer to received command buffer
 * \param[out] uint8_t *response - Pointer to response buffer
 * \param[out] uint8_t *framelength - Pointer to response frame length
 *
 * \return uint8_t - Command status
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
 *
 * SRD
 * WorkItem 1 :
 * \\input{XCP_User_Cmd_Get_Host_Filtered_Analog_Inputs_31to61}
 */
static uint8_t XCP_User_Cmd_Get_Host_Filtered_Analog_Inputs_31to61(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd,
                                                                   uint8_t *response, uint8_t *framelength)
{
   uint8_t ret_value;
   ret_value = Get_Filtered_Analog_Inputs(xcp_input_ptr, cmnd, response, framelength);
   return ret_value;
}

/**
 * FUNCTION:Compute_Target_Parameters
 * This function computes and formats target parameters (range, RCS, range rate, azimuth angle,
 * elevation angle) into the response buffer with proper fixed-point scaling and resolution.
 *
 * \param[out] uint8_t *response_ptr - Pointer to response buffer where target data will be written
 * \param[in] XCP_Target_Info_Valid_Trgt_T *valid_tgt_ptr - Pointer to valid target information structure
 *
 * \return bool - Bistatic flag of the valid target
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
 *
 * SRD
 * WorkItem 1 :
 * \\input{Compute_Target_Parameters}
 */
static bool Compute_Target_Parameters(uint8_t *response_ptr, XCP_Target_Info_Valid_Trgt_T *valid_tgt_ptr)
{
   u10p6_T tempu10p6;
   u16p0_T tempu16p0;
   s15p0_T temps15p0;
   s10p5_T temps8p7;
   float32_t floattemp;
   s15p0_T temp_rrate_s15p0;
   s15p0_T temp_elev_s15p0;
   uint8_t cnt = 0U;
   int32_t temp_calc;

   tempu10p6 =
      (u10p6_T)(Fix(valid_tgt_ptr->target_range, s8p7_T,
                    u10p6_T)); /* polyspace RTE:UNR [Justified:Low] "Justification is available in the share point document "*/
   tempu16p0 =
      (u16p0_T)Fix((uint32_t)tempu10p6 * (u16p0_T)XCP_TARGET_RANGE_RESOLUTION, u26p6_T,
                   u16p0_T); /* polyspace RTE:UNR [Justified:Low] "Justification is available in the share point document "*/

   /* Byte 2 - target_range_msb */
   response_ptr[cnt++] = GET_BYTE(tempu16p0, 1U);

   /* Byte 3 target_range_lsb */
   response_ptr[cnt++] = GET_BYTE(tempu16p0, 0U);

   /* Byte 4 - target_rcs_msb */
   floattemp = Fix2Float(valid_tgt_ptr->target_rcs, s8p7_T);
   temps15p0 =
      (s15p0_T)Float2Fix((floattemp * XCP_TARGET_AMP_RESOLUTION),
                         s15p0_T); /* polyspace RTE:UNR [Justified:Low] "Justification is available in the share point document "*/

   response_ptr[cnt++] = GET_BYTE((uint16_t)temps15p0, 1U);

   /* Byte 5 - target_rcs_lsb*/
   response_ptr[cnt++] = GET_BYTE((uint16_t)temps15p0, 0U);

   temps8p7 = valid_tgt_ptr->target_range_rate;

   temp_calc = ((int32_t)temps8p7) * ((int32_t)XCP_TARGET_RANGE_RATE_RESOLUTION);
   temp_rrate_s15p0 =
      (s15p0_T)Fix(temp_calc, s24p7_T, s15p0_T); /* polyspace RTE:UNR [Justified:Low] "Justification available in sharepoint" */

   /* Byte 6 - target_rdot_msb*/
   response_ptr[cnt++] = GET_BYTE((uint16_t)temp_rrate_s15p0, 1U);

   /* Byte 7 - target_rdot_lsb */
   response_ptr[cnt++] = GET_BYTE((uint16_t)temp_rrate_s15p0, 0U);

   /* Byte 8 - target_az_ang_msb*/
   temps15p0 = Float2Fix((valid_tgt_ptr->target_angle * XCP_TARGET_ANGLE_RESOLUTION), s15p0_T);

   response_ptr[cnt++] = GET_BYTE((uint16_t)temps15p0, 1U);

   /* Byte 9 - target_az_ang_lsb*/
   response_ptr[cnt++] = GET_BYTE((uint16_t)temps15p0, 0U);

   /* message byte 4 -- elevation:  float degree -> 0.1 resolution ->  s7p0_T*/
   temp_elev_s15p0 = Float2Fix((valid_tgt_ptr->det_elevation * XCP_TARGET_ELEVATION_RESOLUTION),
                               s15p0_T); /* polyspace RTE:OVFL [Justified:Low] "The Float2Fix is standard function used
                                           project wide and has no impact" */

   /* Byte 10 - target_el_ang_msb*/
   response_ptr[cnt++] = GET_BYTE((uint16_t)temp_elev_s15p0, 1U);

   /* Byte 11 - target_el_ang_lsb */
   response_ptr[cnt++] = GET_BYTE((uint16_t)temp_elev_s15p0, 0U);

   return valid_tgt_ptr->bistatic;
}

/**
 * FUNCTION:Copy_Checksum_To_Response
 * This function copies checksum values to the response buffer in big-endian format.
 * Utilized by XCP_Chksum_Updation_Periodic_Task which in turn is utilized by
 * xcp_user_cmd_get_checksum_results (F1 85).
 *
 * \param[out] uint8_t *dst_ptr - Pointer to destination response buffer
 * \param[in] uint8_t **src_ptr - Pointer to array of checksum source pointers
 * \param[in] uint8_t offset - Starting offset index in the destination buffer
 * \param[in] const uint8_t max - Maximum number of checksums to copy
 *
 * \return XCP_Err_Code_T - XCP_ERR_CMD_SYNCH_CPV on success, XCP_ERR_OUT_OF_RANGE_CPV on failure
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
 *
 * SRD
 * WorkItem 1 :
 * \\input{Copy_Checksum_To_Response}
 */
static XCP_Err_Code_T Copy_Checksum_To_Response(uint8_t *dst_ptr, uint8_t **src_ptr, uint8_t offset, const uint8_t max)
{
   uint8_t *xcp_cksm_ptr = NULL;
   int8_t rev            = 0;
   uint8_t index         = offset;
   uint8_t checksum_cnt  = 0U;
   XCP_Err_Code_T error  = XCP_ERR_CMD_SYNCH_CPV;

   if (NULL != src_ptr)
   {
      for (checksum_cnt = 0U; checksum_cnt < max; checksum_cnt++)
      {
         xcp_cksm_ptr = src_ptr[checksum_cnt];

         if (xcp_cksm_ptr != NULL)
         {
            /* converting to Big endian - wiser to use sizeof operator for scalability */
            for (rev = 3; rev >= 0; rev--)
            {
               dst_ptr[index++] = xcp_cksm_ptr[rev];
            }
         }
         else
         {
            index += 4; /* Skip 4 bytes if pointer is NULL*/
         }
      }
   }
   else
   {
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   return (error);
}

/**
 * FUNCTION:Get_Analog_Inputs
 * This function implements to get analog input values of 0 to 61 values
 * Command: XCP_User_Cmd_Get_Host_Analog_Inputs_0to30 (F1 A0 - to get analog input values of 0 to 30 values)
 * Command: XCP_USER_CMD_GET_HOST_ANALOG_INPUTS_31TO61 (F1 A1 - to get analog input values of 31 to 61 values)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-277960
 * WorkItem 2 : WI-277958
 *
 * SRD
 * WorkItem 1 : WI-268284
 * WorkItem 2 : WI-277016
 * WorkItem 3 : WI-277679
 * WorkItem 4 : WI-287956
 * WorkItem 5 : WI-287957
 * \\input{Get_Analog_Inputs}
 */
static uint8_t Get_Analog_Inputs(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd, uint8_t *response,
                                 uint8_t *framelength)
{
   uint8_t ret_value                          = XCP_CMD_OK_CPV;
   XCP_Err_Code_T error                       = XCP_ERR_CMD_SYNCH_CPV;
   volatile uint8_t *xcp_adc_trigger_flag_ptr = xcp_input_ptr->xcp_get_adc_trigger_flag_ptr;

   if ((CODED_FALSE == Get_XCP_Pending_Cmnd_Status()) && (NULL != xcp_adc_trigger_flag_ptr) &&
       (XCP_RANGE_CHECK(cmnd[2], 0x01U, XCP_MAX_ANALOG_INPUTS_PER_FRAME)))
   {
      /* capture the event */
      Set_XCP_Periodic_User_Cmd(cmnd[1], XCP_ADC_MAX_WAIT_TIME, &XCP_ADC_Info_Periodic_Task);

      XCP_ADC_Quantity          = cmnd[2];
      *xcp_adc_trigger_flag_ptr = CODED_TRUE;
      ret_value                 = XCP_CMD_PENDING_CPV;
   }
   else
   {
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   { /* response already filled */
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }
   return (ret_value);
}

/**
 * FUNCTION:Get_Filtered_Analog_Inputs
 * This function implements to get analog input values of 0 to 61 filtered values
 * Command: XCP_USER_CMD_GET_FILTERED_ADC_INPUTS_0TO30 (F1 A2 - to get analog input values of 0 to 30 filtered values)
 * Command: XCP_USER_CMD_GET_ADC_FILTERED_INPUTS_31TO61 (F1 A3 - to get analog input values of 31 to 61 filtered values)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-320538
 * WorkItem 2 : WI-320541
 * WorkItem 3 : WI-320542
 * WorkItem 4 : WI-320539
 * WorkItem 5 : WI-320540
 * \\input{Get_Filtered_Analog_Inputs}
 */
static uint8_t Get_Filtered_Analog_Inputs(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd, uint8_t *response,
                                          uint8_t *framelength)
{
   uint8_t ret_value                          = XCP_CMD_OK_CPV;
   XCP_Err_Code_T error                       = XCP_ERR_CMD_SYNCH_CPV;
   volatile uint8_t *xcp_adc_trigger_flag_ptr = xcp_input_ptr->xcp_get_adc_trigger_flag_ptr;

   if (CODED_FALSE == Get_XCP_Pending_Cmnd_Status())
   {
      if ((NULL != xcp_adc_trigger_flag_ptr) && (XCP_RANGE_CHECK(cmnd[2], 0x01U, XCP_MAX_ANALOG_INPUTS_PER_FRAME)))
      {
         /* capture the event */
         Set_XCP_Periodic_User_Cmd(cmnd[1], XCP_ADC_MAX_WAIT_TIME, &XCP_Filtered_ADC_Info_Periodic_Task);

         XCP_Filtered_ADC_Quantity = cmnd[2];
         *xcp_adc_trigger_flag_ptr = CODED_TRUE;
         ret_value                 = XCP_CMD_PENDING_CPV;
      }
      else
      {
         error = XCP_ERR_OUT_OF_RANGE_CPV;
      }
   }
   else
   {
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   { /* response already filled */
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }
   return (ret_value);
}

/*****************************************************************************
 *. Name: Copy_Adc_Data_To_Response
 *. This function copies ADC data to the response packet
 *. Shared Variables: uint8_t* ,uint16_t*
 *.
 *. Parameters:
 *.   response - pointer to response buffer
 *.   raw_adc_ptr - pointer to raw ADC data
 *.   adc_data_offset - offset into ADC data
 *.   num_inputs - number of ADC inputs
 *.   adc_qty - quantity of ADC values to copy
 *.   cmd - command byte
 *.
 *. Return Value: uint8_t - response index (number of bytes written)
 *. Design Information:
 *. Traces to:
 *.            Section :
 *.
 *. JIRA/Plastic Task:
 *****************************************************************************/
static uint8_t Copy_Adc_Data_To_Response(uint8_t *response, volatile uint16_t *raw_adc_ptr, const uint8_t adc_data_offset,
                                         const uint8_t num_inputs, const uint8_t adc_qty)
{
   uint8_t index;
   uint8_t adc_data_index;
   uint8_t resp_index = 0U;

   for (index = 0U; index < adc_qty; index++)
   {
      adc_data_index = index + adc_data_offset;
      if (adc_data_index < num_inputs)
      {
         response[resp_index++] = GET_BYTE(raw_adc_ptr[adc_data_index], 1U);
         response[resp_index++] = GET_BYTE(raw_adc_ptr[adc_data_index], 0U);
      }
   }

   return resp_index;
}

/*****************************************************************************
 *. Name: XCP_ADC_Info_Periodic_Task
 *. This periodic function is being utilized by Get_Analog_Inputs (F1 A0 / F1 A1)
 *. Shared Variables: uint8_t* ,uint8_t*
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
static uint8_t XCP_ADC_Info_Periodic_Task(XCP_BB_Input_Params_T *const xcp_input_ptr, uint8_t *response, uint8_t *framelength)
{
   uint8_t ret_value    = XCP_CMD_OK_CPV;
   XCP_Err_Code_T error = XCP_ERR_CMD_SYNCH_CPV;

   volatile uint16_t *xcp_get_raw_adc_data_ptr     = xcp_input_ptr->xcp_get_raw_adc_data_ptr;
   const uint8_t num_analog_inputs                 = xcp_input_ptr->num_analog_inputs;
   volatile uint8_t *xcp_get_adc_validity_flag_ptr = xcp_input_ptr->xcp_get_adc_validity_flag_ptr;
   volatile uint8_t *xcp_adc_trigger_flag_ptr      = xcp_input_ptr->xcp_get_adc_trigger_flag_ptr;

   uint8_t resp_index = 0U;
   uint8_t adc_data_offset;
   const uint8_t xcp_adc_qty = XCP_ADC_Quantity;
   const uint8_t cmd         = XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_val;

   const void *adc_info_ptr_list[] = {(const void *)xcp_get_raw_adc_data_ptr,
                                      (const void *)xcp_get_adc_validity_flag_ptr}; /*NULL Pointer check */

   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt++;

   /* Check for NULL pointers in the list */
   if (NULL_PTR_CHECK(adc_info_ptr_list))
   {
      if (CODED_TRUE == (*xcp_get_adc_validity_flag_ptr))
      {
         adc_data_offset = (XCP_USER_CMD_GET_HOST_ANALOG_INPUTS_0TO30 == cmd) ? 0U : XCP_MAX_ANALOG_INPUTS_PER_FRAME;

         /* Generating Positive response packet */
         response[resp_index++] = XCP_POSITIVE_RESPONSE_CPV;
         response[resp_index++] = cmd;

         resp_index += Copy_Adc_Data_To_Response(&response[resp_index], xcp_get_raw_adc_data_ptr, adc_data_offset,
                                                 num_analog_inputs, xcp_adc_qty);

         /* same as (XCP_ADC_Quantity * 2U + 2U) */
         *framelength = resp_index;

         /* clear periodic user command */
         Set_XCP_Periodic_User_Cmd(0U, 0U, NULL);

         XCP_ADC_Quantity          = 0U;
         *xcp_adc_trigger_flag_ptr = CODED_FALSE;
      }
      else
      { /*time out*/
         if (Is_Cycle_Cnt_Timedout)
         {
            error = XCP_ERR_CMD_SYNTAX_CPV;
         }
         else
         {
            ret_value = XCP_CMD_PENDING_CPV;
         }
      }
   }
   else
   {
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }
   if (XCP_ERR_CMD_SYNCH_CPV == error)
   {
      /* Do Nothing*/
   }
   else
   { /* negative response */
      *framelength = Prepare_Negative_Response(response, error);

      /* clear periodic user command */
      Set_XCP_Periodic_User_Cmd(0U, 0U, NULL);

      XCP_ADC_Quantity          = 0U;
      *xcp_adc_trigger_flag_ptr = CODED_FALSE;
   }
   return (ret_value);
}

/*****************************************************************************
 *. Name: XCP_Filtered_ADC_Info_Periodic_Task
 *. This periodic function is being utilized by Get_Filtered_Analog_Inputs (F1 A2 / F1 A3)
 *. Shared Variables: uint8_t* ,uint8_t*
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
static uint8_t XCP_Filtered_ADC_Info_Periodic_Task(XCP_BB_Input_Params_T *const xcp_input_ptr, uint8_t *response,
                                                   uint8_t *framelength)
{
   uint8_t ret_value    = XCP_CMD_OK_CPV;
   XCP_Err_Code_T error = XCP_ERR_CMD_SYNCH_CPV;

   volatile uint16_t *xcp_get_raw_adc_data_ptr     = (volatile uint16_t *)xcp_input_ptr->xcp_get_raw_adc_filtered_data_ptr;
   const uint8_t num_analog_inputs                 = xcp_input_ptr->num_analog_inputs;
   volatile uint8_t *xcp_get_adc_validity_flag_ptr = xcp_input_ptr->xcp_get_adc_validity_flag_ptr;
   volatile uint8_t *xcp_adc_trigger_flag_ptr      = xcp_input_ptr->xcp_get_adc_trigger_flag_ptr;

   uint8_t resp_index = 0U;
   uint8_t adc_data_offset;

   const uint8_t xcp_adc_qty = XCP_Filtered_ADC_Quantity;
   const uint8_t cmd         = XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_val;

   const void *adc_info_ptr_list[] = {(const void *)xcp_get_raw_adc_data_ptr, (const void *)xcp_get_adc_validity_flag_ptr};

   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt++;

   /*Check for NULL pointers before dereferencing */
   if (NULL_PTR_CHECK(adc_info_ptr_list))
   {
      if (CODED_TRUE == (*xcp_get_adc_validity_flag_ptr))
      {
         adc_data_offset = (XCP_USER_CMD_GET_FILTERED_ADC_INPUTS_0TO30 == cmd) ? 0U : XCP_MAX_ANALOG_INPUTS_PER_FRAME;

         /* Generating Positive response packet */
         response[resp_index++] = XCP_POSITIVE_RESPONSE_CPV;
         response[resp_index++] = cmd;

         resp_index += Copy_Adc_Data_To_Response(&response[resp_index], xcp_get_raw_adc_data_ptr, adc_data_offset,
                                                 num_analog_inputs, xcp_adc_qty);

         /* same as (XCP_Filtered_ADC_Quantity * 2U + 2U) */
         *framelength = resp_index;

         /* clear periodic user command */
         Set_XCP_Periodic_User_Cmd(0U, 0U, NULL);

         XCP_Filtered_ADC_Quantity = 0U;
         *xcp_adc_trigger_flag_ptr = CODED_FALSE;
      }
      else
      { /*time out*/
         if (Is_Cycle_Cnt_Timedout)
         {
            error = XCP_ERR_CMD_SYNTAX_CPV;
         }
         else
         {
            ret_value = XCP_CMD_PENDING_CPV;
         }
      }
   }
   else
   {
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }
   if (XCP_ERR_CMD_SYNCH_CPV == error)
   {
      /* Do Nothing*/
   }
   else
   { /* negative response */
      *framelength = Prepare_Negative_Response(response, error);

      /* clear periodic user command */
      Set_XCP_Periodic_User_Cmd(0U, 0U, NULL);

      XCP_Filtered_ADC_Quantity = 0U;
      *xcp_adc_trigger_flag_ptr = CODED_FALSE;
   }
   return (ret_value);
}

/**
 * FUNCTION:Swap_Values_As_Per_Need
 * This function swaps two fixed-point values if the first value is greater than the second.
 * Used to ensure min/max ordering is correct.
 *
 * \param[in,out] s8p7_T *p1 - Pointer to first fixed-point value
 * \param[in,out] s8p7_T *p2 - Pointer to second fixed-point value
 *
 * \return void
 *
 * \remark
 * \ServID xx
 * \Reentrancy non-reentrant
 * \Synchronism synchronous
 * \Precondition p1 and p2 must be valid pointers to s8p7_T values
 * \Caveats Values are swapped in-place if p1 > p2
 * TRACEABILITY INFO:
 *
 * SDD
 * WorkItem 1 : WI-284177
 *
 * SRD
 * WorkItem 1 : WI-278648
 * WorkItem 2 : WI-278649
 * WorkItem 3 : WI-278650
 * \\input{Swap_Values_As_Per_Need}
 */
static void Swap_Values_As_Per_Need(s8p7_T *p1, s8p7_T *p2)
{
   s8p7_T temp;
   if (*p1 > *p2)
   {
      temp = *p1;
      *p1  = *p2;
      *p2  = temp;
   }
}

/**
 * FUNCTION:Validate_Parameters_Of_XCP_Target
 * This function validates and converts XCP target parameters from physical units to fixed-point representation.
 * It converts range and range-rate limits and swaps min/max values if necessary.
 *
 * \param[in,out] XCP_Target_Info_T *const xcp_target_info_ptr - Pointer to target info structure containing physical parameters
 *
 * \return void
 *
 * \remark
 * \ServID xx
 * \Reentrancy non-reentrant
 * \Synchronism synchronous
 * \Precondition xcp_target_info_ptr must be valid and contain initialized range/rrate physical values
 * \Caveats Range and rate-of-range limits are swapped if min > max
 * TRACEABILITY INFO:
 *
 * SDD
 * WorkItem 1 : WI-284177
 *
 * SRD
 * WorkItem 1 : WI-278648
 * WorkItem 2 : WI-278649
 * WorkItem 3 : WI-278650
 * \\input{Validate_Parameters_Of_XCP_Target}
 */
static void Validate_Parameters_Of_XCP_Target(XCP_Target_Info_T *const xcp_target_info_ptr)
{
   /* coverity[NO_EFFECT tag:SUPPRESS] */
   xcp_target_info_ptr->range_min =
      (s8p7_T)Fix((uint16_t)((uint32_t)xcp_target_info_ptr->range_min_phy * XCP_TARGET_RANGE_RES), u8p8_T, s8p7_T);

   xcp_target_info_ptr->range_max =
      (s8p7_T)Fix((uint16_t)((uint32_t)xcp_target_info_ptr->range_max_phy * XCP_TARGET_RANGE_RES), u8p8_T, s8p7_T);

   xcp_target_info_ptr->rrate_min = (s8p7_T)Fix(XCP_Rrate_Limit[xcp_target_info_ptr->rrate_min_phy], s7p0_T, s8p7_T);

   xcp_target_info_ptr->rrate_max = (s8p7_T)Fix(XCP_Rrate_Limit[xcp_target_info_ptr->rrate_max_phy], s7p0_T, s8p7_T);

   /* swap min and max if need be - range */
   Swap_Values_As_Per_Need(&xcp_target_info_ptr->range_min, &xcp_target_info_ptr->range_max);

   /* swap min and max if need be - rrate */
   Swap_Values_As_Per_Need(&xcp_target_info_ptr->rrate_min, &xcp_target_info_ptr->rrate_max);
}

/**
 * FUNCTION:XCP_User_Cmd_Get_Radar_Target
 * This function implements to report target info
 * Command: XCP_USER_CMD_GET_RADAR_TARGET (F1 90)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-284177
 *
 * SRD
 * WorkItem 1 : WI-278648
 * WorkItem 2 : WI_278649
 * WorkItem 3 : WI_278650
 * \\input{XCP_User_Cmd_Get_Radar_Target}
 */
static uint8_t XCP_User_Cmd_Get_Radar_Target(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd, uint8_t *response,
                                             uint8_t *framelength)
{
   uint8_t ret_value             = XCP_CMD_OK_CPV;
   XCP_Err_Code_T error          = XCP_ERR_CMD_SYNCH_CPV;
   uint8_t xcp_radar_radiate_cmd = xcp_input_ptr->xcp_radar_radiate_cmd;

   uint8_t *active_look[] = {&XCP_Target_Info.process_look_A, &XCP_Target_Info.process_look_B, &XCP_Target_Info.process_look_C,
                             &XCP_Target_Info.process_look_D};

   XCP_Look_Enable_Status_fptr_T xcp_look_en_status_fptr = xcp_input_ptr->xcp_look_en_status_fptr;

   if (CODED_FALSE == Get_XCP_Pending_Cmnd_Status())
   {
      if (CODED_TRUE == xcp_radar_radiate_cmd)
      {
         XCP_Target_Info.look_enable_phy = cmnd[2U];
         XCP_Target_Info.range_min_phy   = cmnd[3U];
         XCP_Target_Info.range_max_phy   = cmnd[4U];
         XCP_Target_Info.rrate_min_phy   = cmnd[5U];
         XCP_Target_Info.rrate_max_phy   = cmnd[6U];

         /*if conditions are okay Raise NRC*/
         /* Look Enable range: 0-15 (bitmask: bit 0=Look A, bit 1=Look B, bit 2=Look C, bit 3=Look D) */

         /*Target Rate Limit check*/
         if (((cmnd[2] > XCP_TARGET_MAX_LOOK_SIZE) || (cmnd[2] == XCP_TARGET_NO_LOOK)) ||
             ((cmnd[5] >= (XCP_TARGET_RRATE_LIMIT_MAX - 1U)) || (cmnd[6] >= (XCP_TARGET_RRATE_LIMIT_MAX - 1U))))
         {
            error = XCP_ERR_OUT_OF_RANGE_CPV;
         }
         else
         {
            XCP_Target_Info.process_look_A = Get_Process_Look_Validity(cmnd[2], XCP_RADAR_LOOK_A, xcp_look_en_status_fptr);
            XCP_Target_Info.process_look_B = Get_Process_Look_Validity(cmnd[2], XCP_RADAR_LOOK_B, xcp_look_en_status_fptr);
            XCP_Target_Info.process_look_C = Get_Process_Look_Validity(cmnd[2], XCP_RADAR_LOOK_C, xcp_look_en_status_fptr);
            XCP_Target_Info.process_look_D = Get_Process_Look_Validity(cmnd[2], XCP_RADAR_LOOK_D, xcp_look_en_status_fptr);

            if (No_Active_Look(active_look, (uint8_t)NUM_ELEMS(active_look)))
            { /* No look is selected for processing */
               error = XCP_ERR_DAQ_ACTIVE_CPV;
            }
            else
            { /* At least one look is selected for processing */
               /* valid parameters */
               Validate_Parameters_Of_XCP_Target(&XCP_Target_Info);

               /*Clear the buffers before copying data from */
               memset(&XCP_Target_Info.response.data, 0, sizeof(XCP_Target_Info_Res_T));
               memset(&XCP_Target_Info.valid_target, 0, sizeof(XCP_Target_Info_Valid_Trgt_T));

               /* set xcp user cmd received */
               Set_XCP_Periodic_User_Cmd(cmnd[1], XCP_TRAGET_MAX_WAIT_TIME, &XCP_Target_Info_Periodic_Task);

               ret_value = XCP_CMD_PENDING_CPV;
            }
         }
      }
      else
      {
         error = XCP_ERR_ACCESS_DENIED_CPV;
      }
   }
   else
   {
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   { /* response updated by periodic function */
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }
   return (ret_value);
}

/**
 * FUNCTION:Is_Value_Within_Range
 * This function checks whether a given value falls within the specified min/max filter window,
 * or if the filter is bypassed (ignore flag is set).
 *
 * \param[in] s8p7_T value - The value to check
 * \param[in] s8p7_T min - Minimum bound of the filter window
 * \param[in] s8p7_T max - Maximum bound of the filter window
 * \param[in] bool ignore - If true, the filter is bypassed and the value always passes
 *
 * \return bool - true if value is within window or filter is bypassed, false otherwise
 */
static bool Is_Value_Within_Range(s8p7_T value, s8p7_T min, s8p7_T max, bool ignore)
{
   return ((ignore) || (XCP_RANGE_CHECK(value, min, max)));
}

/**
 * FUNCTION:Search_Valid_Target
 * This function searches for the valid target within specified range and range-rate limits
 * and extracts target parameters including range, velocity, RCS, angle and elevation.
 *
 * \param[in] volatile XCP_Target_Report_T *xcp_tgt_rep_ptr - Pointer to target report data
 * \param[in] XCP_Target_Info_T *const xcp_target_info_ptr - Pointer to target info structure containing filter limits
 * \param[in] const uint16_t xcp_num_max_dets - Maximum number of detections to search
 *
 * \return void
 *
 * \remark
 * \ServID xx
 * \Reentrancy non-reentrant
 * \Synchronism synchronous
 * \Precondition Target report pointer must be valid and contain detection data
 * \Caveats If both range_min and range_max are zero, range filtering is disabled
 * TRACEABILITY INFO:
 *
 * SDD
 * WorkItem 1 : WI-284176
 *
 * SRD
 * WorkItem 1 : WI-278648
 * WorkItem 2 : WI-278649
 * WorkItem 3 : WI-278650
 * \\input{Search_Valid_Target}
 */
static void Search_Valid_Target(volatile XCP_Target_Report_T *xcp_tgt_rep_ptr, XCP_Target_Info_T *const xcp_target_info_ptr,
                                const uint16_t xcp_num_max_dets)
{
   uint16_t idx, n;
   bool target_found = false;

   s8p7_T temp_r;
   s8p7_T temp_rcs;
   s8p7_T temp_rdot;

   s8p7_T range_min = xcp_target_info_ptr->range_min;
   s8p7_T range_max = xcp_target_info_ptr->range_max;
   s8p7_T rrate_min = xcp_target_info_ptr->rrate_min;
   s8p7_T rrate_max = xcp_target_info_ptr->rrate_max;

   /* If both min & max are zero, ignore that filter (process all targets regardless) */
   bool range_ignore = ((0 == range_min) && (0 == range_max));
   bool rrate_ignore = ((0 == rrate_min) && (0 == rrate_max));

   XCP_Target_Info_Valid_Trgt_T *xcp_valid_target_ptr = &xcp_target_info_ptr->valid_target;

   /* Initialize to minimum representable value so the first matching target always wins */
   xcp_valid_target_ptr->target_rcs = (s8p7_T)INT16_MIN;

   n = MIN(xcp_num_max_dets, xcp_tgt_rep_ptr->num_af_det);
   for (idx = 0; idx < n; idx++)
   {
      temp_r    = (s8p7_T)Float2Fix(xcp_tgt_rep_ptr->af_dets[idx].ran, s8p7_T);
      temp_rdot = (s8p7_T)Float2Fix(xcp_tgt_rep_ptr->af_dets[idx].vel, s8p7_T);

      if (Is_Value_Within_Range(temp_r, range_min, range_max, range_ignore) &&
          Is_Value_Within_Range(temp_rdot, rrate_min, rrate_max, rrate_ignore))
      {
         temp_rcs = (s8p7_T)Float2Fix(xcp_tgt_rep_ptr->af_dets[idx].rcs, s8p7_T);

         if (temp_rcs > xcp_valid_target_ptr->target_rcs)
         {
            xcp_valid_target_ptr->target_rcs = temp_rcs;
            xcp_valid_target_ptr->target_idx = idx;
            target_found                     = true;
         }
      }
   }

   if (target_found)
   {
      idx = xcp_valid_target_ptr->target_idx;

      xcp_valid_target_ptr->target_range      = (s8p7_T)Float2Fix(xcp_tgt_rep_ptr->af_dets[idx].ran, s8p7_T);
      xcp_valid_target_ptr->target_range_rate = (s8p7_T)Float2Fix(xcp_tgt_rep_ptr->af_dets[idx].vel, s8p7_T);
      xcp_valid_target_ptr->bistatic          = (bool)xcp_tgt_rep_ptr->af_dets[idx].f_bistatic;
      xcp_valid_target_ptr->target_angle      = xcp_tgt_rep_ptr->af_dets[idx].theta * RAD2DEG;
      xcp_valid_target_ptr->det_elevation     = xcp_tgt_rep_ptr->af_dets[idx].phi * RAD2DEG;
   }
}

/**
 * FUNCTION:XCP_Target_Info_Periodic_Task
 * This function implements to report target information
 * This periodic function is being utilized by xcp_user_cmd_get_radar_target (F1 90)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-284176
 *
 * SRD
 * WorkItem 1 : WI-278648
 * WorkItem 2 : WI_278649
 * WorkItem 3 : WI_278650
 * \\input{XCP_Target_Info_Periodic_Task}
 */
static uint8_t XCP_Target_Info_Periodic_Task(XCP_BB_Input_Params_T *const xcp_input_ptr, uint8_t *response, uint8_t *framelength)
{
   uint8_t ret_value    = XCP_CMD_OK_CPV;
   XCP_Err_Code_T error = XCP_ERR_CMD_SYNCH_CPV;

   const uint16_t xcp_num_max_dets                  = xcp_input_ptr->xcp_num_max_dets;
   uint8_t xcp_current_look                         = xcp_input_ptr->xcp_current_look;
   XCP_Copy_Trgt_Rprts_fptr_T xcp_copy_targets_fptr = xcp_input_ptr->xcp_copy_target_report_fptr;
   volatile XCP_Target_Report_T *xcp_tgt_rep_ptr    = (*xcp_copy_targets_fptr)();
   XCP_Target_Info_Res_T *xcp_resp_ptr              = &XCP_Target_Info.response;
   uint8_t cmd                                      = XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd;

   uint8_t index = 0xFF;

   bool is_looks_processing_done = false;

   bool *bistatic_ptr[]    = {&xcp_resp_ptr->byte.bistatic_flag_lrll, &xcp_resp_ptr->byte.bistatic_flag_lrml,
                           &xcp_resp_ptr->byte.bistatic_flag_mrll, &xcp_resp_ptr->byte.bistatic_flag_mrml};
   uint8_t *tgt_rng_ptr[]  = {&xcp_resp_ptr->byte.lrll_target_range_msb, &xcp_resp_ptr->byte.lrml_target_range_msb,
                             &xcp_resp_ptr->byte.mrll_target_range_msb, &xcp_resp_ptr->byte.mrml_target_range_msb};
   uint8_t *process_look[] = {&XCP_Target_Info.process_look_A, &XCP_Target_Info.process_look_B, &XCP_Target_Info.process_look_C,
                              &XCP_Target_Info.process_look_D};

   /* periodic cycle counter */
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt++;

   if ((CODED_TRUE == cmd) && (NULL != xcp_tgt_rep_ptr))
   {
      if ((xcp_current_look <= XCP_RADAR_LOOK_D) && (CODED_TRUE == *process_look[xcp_current_look]))
      {
         index = xcp_current_look;

         Search_Valid_Target(xcp_tgt_rep_ptr, &XCP_Target_Info, xcp_num_max_dets);

         Debug_Mode_Radar_Target(&XCP_Target_Info.valid_target);

         *bistatic_ptr[index] = Compute_Target_Parameters(tgt_rng_ptr[index], &XCP_Target_Info.valid_target);

         /* done with processing this particular look */
         *process_look[index] = CODED_FALSE;
      }
      else
      {
         /* no looks selected - not selecting the target */
      }
   }
   else
   { /* negative response */
   }

   /* true if all looks are processed */
   is_looks_processing_done = No_Active_Look(process_look, (uint8_t)NUM_ELEMS(process_look));

   if (Is_Cycle_Cnt_Timedout)
   { /* timeout check */
      if (is_looks_processing_done)
      { /* no timeout */
      }
      else
      { /* time out */
         error = XCP_ERR_CMD_SYNTAX_CPV;
      }
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   {
      if (is_looks_processing_done)
      { /* no timeout - all look processed -copy the positive respose - clear the flags */
         /* Generating Positive response packet */
         xcp_resp_ptr->byte.response    = XCP_POSITIVE_RESPONSE_CPV;
         xcp_resp_ptr->byte.subcmd_code = XCP_USER_CMD_GET_RADAR_TARGET;

         *framelength = sizeof(XCP_Target_Info.response.data);
         memcpy(response, &XCP_Target_Info.response.data, *framelength);

         /* clear periodic user command */
         Set_XCP_Periodic_User_Cmd(0U, 0U, NULL);
      }
      else
      { /* no timeout - not all look processed - waiting to send response */
         ret_value = XCP_CMD_PENDING_CPV;
      }
   }
   else
   { /* negative response */
      *framelength = Prepare_Negative_Response(response, error);

      /* clear periodic user command */
      Set_XCP_Periodic_User_Cmd(0U, 0U, NULL);
   }

   return (ret_value);
}

/**
 * FUNCTION:XCP_User_Cmd_Get_Start_Address_Size_Event_Info
 * This function implements xcp command to get start address, size and event info.
 * Command: XCP_USER_CMD_GET_START_ADDRESS_SIZE_EVENT_INFO (F1 06)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-278644
 * WorkItem 2 : WI-278643
 * WorkItem 3 : WI-278642
 * \\input{xcp_user_cmd_erase_data_flash}
 */
static uint8_t XCP_User_Cmd_Get_Start_Address_Size_Event_Info(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd,
                                                              uint8_t *response, uint8_t *framelength)
{
   XCP_Err_Code_T error = XCP_ERR_CMD_SYNCH_CPV;
   XCP_DAQ_Descriptor_Table_T(*xcp_daq_info_ptr)[NUM_OF_DAQ1_VARIABLES];
   uint8_t i, temp;
   uint8_t resp_index = 2U;
   XCP_DAQ_Descriptor_Table_T daq_data;

   xcp_daq_info_ptr = (XCP_DAQ_Descriptor_Table_T(*)[NUM_OF_DAQ1_VARIABLES])xcp_input_ptr->xcp_bb_daq_info_params_ptr;

   (void)memset(&daq_data, 0, sizeof(daq_data)); /* zeros all 4 members explicitly */

   if ((xcp_daq_info_ptr != NULL) && (XCP_RANGE_CHECK(cmnd[2], XCP_MIN_ADDRS_SIZE_INFO, XCP_MAX_ADDRS_SIZE_INFO)))
   {
      temp = (uint8_t)(cmnd[2] - 1U);
      for (i = 0U; i < NUM_OF_DAQ1_VARIABLES; i++)
      {
         daq_data.address          = xcp_daq_info_ptr[temp][i].address;
         daq_data.total_size       = xcp_daq_info_ptr[temp][i].total_size;
         daq_data.event_channel_no = xcp_daq_info_ptr[temp][i].event_channel_no;
         daq_data.parameter_size   = xcp_daq_info_ptr[temp][i].parameter_size;

         /* address */
         response[resp_index++] = GET_BYTE(daq_data.address, 0U);
         response[resp_index++] = GET_BYTE(daq_data.address, 1U);
         response[resp_index++] = GET_BYTE(daq_data.address, 2U);
         response[resp_index++] = GET_BYTE(daq_data.address, 3U);

         /* total size */
         response[resp_index++] = GET_BYTE(daq_data.total_size, 0U);
         response[resp_index++] = GET_BYTE(daq_data.total_size, 1U);

         response[resp_index++] = (daq_data.event_channel_no);
         response[resp_index++] = (daq_data.parameter_size);
      }
   }
   else
   {
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   {
      response[0]  = XCP_POSITIVE_RESPONSE_CPV;
      response[1]  = cmnd[1];
      *framelength = XCP_DAQ_FRAMELENGTH;
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }

   return (XCP_CMD_OK_CPV);
}

/**
 * FUNCTION:XCP_User_Cmd_Single_Look_Mode
 * This function implements xcp command(F1 0B) support to enble/disable the individual look mode
 * Command: XCP_USER_CMD_SINGLE_LOOK_MODE (F1 0B)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-289963
 *
 * SRD
 * WorkItem 1 : WI-289863
 * WorkItem 2 : WI-289865
 * WorkItem 3 : WI-289864
 * \\input{XCP_User_Cmd_Single_Look_Mode}
 */
static uint8_t XCP_User_Cmd_Single_Look_Mode(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd, uint8_t *response,
                                             uint8_t *framelength)
{
   uint8_t temp, resp_index;
   XCP_Err_Code_T error                                  = XCP_ERR_CMD_SYNCH_CPV;
   volatile XCP_Single_Look_T *xcp_look_mode_ptr         = xcp_input_ptr->xcp_look_mode_ptr;
   XCP_Look_Enable_Status_fptr_T xcp_look_en_status_fptr = xcp_input_ptr->xcp_look_en_status_fptr;

   const void *temp_ptr_list[] = {(const void *)xcp_look_mode_ptr, (const void *)xcp_look_en_status_fptr};

   if ((NULL_PTR_CHECK(temp_ptr_list)) && (XCP_RANGE_CHECK(cmnd[2], XCP_LOOK_MODE_ENABLE, XCP_LOOK_MODE_DISABLE)) &&
       (XCP_RANGE_CHECK(cmnd[3], (uint8_t)XCP_LRLL_LOOK_MODE, (uint8_t)XCP_FACTORY_LOOK_MODE)))
   {
      temp = (uint8_t)(cmnd[3] - 1U);

      if ((CODED_TRUE == (*xcp_look_en_status_fptr)(temp)))
      {
         if ((uint8_t)XCP_LOOK_MODE_ENABLE == cmnd[2])
         {
            /* Update look_mode_type with valid values */
            xcp_look_mode_ptr->single_look_en     = CODED_TRUE;
            xcp_look_mode_ptr->single_look_select = cmnd[3];
         }
         else
         { /* XCP_LOOK_MODE_DISABLE */
            xcp_look_mode_ptr->single_look_en = CODED_FALSE;
         }
      }
      else
      { /* negative response, if command parameter(s) are invalid. */
         error = XCP_ERR_OUT_OF_RANGE_CPV;
      }
   }
   else
   { /* negative response, if pointer(s) are pointing to nothing. */
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   { /* positive response */
      resp_index             = 0U;
      response[resp_index++] = XCP_POSITIVE_RESPONSE_CPV;
      response[resp_index++] = cmnd[1];
      response[resp_index++] = cmnd[2];
      response[resp_index++] = cmnd[3];
      *framelength           = resp_index;
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }

   return (XCP_CMD_OK_CPV);
}

/**
 * FUNCTION:XCP_User_Cmd_Get_MMIC_MCU_Temp
 * This function implements xcp command to read transmitter temperature
 * Command: XCP_USER_CMD_GET_MMIC_MCU_TEMP (F1 9F)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-277961
 *
 * SRD
 * WorkItem 1 : WI-268287
 * WorkItem 2 : WI-277667
 * WorkItem 3 : WI-277669
 * WorkItem 3 : WI-277671
 * \\input{XCP_User_Cmd_Get_MMIC_MCU_Temp}
 */
static uint8_t XCP_User_Cmd_Get_MMIC_MCU_Temp(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd, uint8_t *response,
                                              uint8_t *framelength)
{
   XCP_Err_Code_T error             = XCP_ERR_CMD_SYNCH_CPV;
   volatile int16_t *tx_temp_ptr    = xcp_input_ptr->xcp_get_tx_temp_ptr; /* already poiniting to Tx memeber */
   volatile float32_t *mcu_temp_ptr = xcp_input_ptr->xcp_get_mcu_temp_ptr;
   uint8_t num_mcu_sensor           = xcp_input_ptr->xcp_num_mcu_sensor;
   uint8_t num_tx_sensor            = (uint8_t)(XCP_TX_SENSORS_EACH_MMIC * xcp_input_ptr->xcp_num_mmic);
   uint8_t index                    = 0;
   int16_t temperature;

   const void *temp_ptr_list[] = {(const void *)tx_temp_ptr, (const void *)mcu_temp_ptr}; /*NULL Pointer check */

   if (NULL_PTR_CHECK(temp_ptr_list))
   {
      /* Filling the response with Initial value 0xFF according to WI-263927 */
      memset(&response[0], XCP_DEFAULT_RESPONSE, XCP_MMIC_MCU_TEMP_FRAMELENGTH);

      response[0] = XCP_POSITIVE_RESPONSE_CPV;
      response[1] = cmnd[1];

      if (XCP_RANGE_CHECK(num_tx_sensor, XCP_MIN_MMIC_MCU_TX_TEMP_SENSORS, XCP_MAX_MMIC_TX_TEMP_SENSORS) ||
          XCP_RANGE_CHECK(num_mcu_sensor, XCP_MIN_MMIC_MCU_TX_TEMP_SENSORS, XCP_MAX_MCU_TEMP_SENSORS))
      {
         for (index = 0U; index < num_mcu_sensor; index++)
         {
            temperature = (int16_t)mcu_temp_ptr[index];
            temperature += XCP_MMIC_MCU_TEMP_OFFSET;
            response[XCP_RES_OFFSET_2 + index] = (uint8_t)temperature;
         }

         for (index = 0U; index < num_tx_sensor; index++)
         { /* Ensure tx_temp_ptr is apropriate */
            temperature = (int16_t)tx_temp_ptr[index];
            temperature += XCP_MMIC_MCU_TEMP_OFFSET;
            response[XCP_RES_OFFSET_5 + index] = (uint8_t)temperature;
         }
      }
      else
      {
         error = XCP_ERR_OUT_OF_RANGE_CPV;
      }
      /* Framelength assigned 13U according to WI-263927 */
      *framelength = XCP_MMIC_MCU_TEMP_FRAMELENGTH;
   }
   else
   {
      /* negative response */
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   { /* response already filled */
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }
   return (XCP_CMD_OK_CPV);
}

/**
 * FUNCTION:XCP_User_Cmd_Set_Operation_Mode
 * This function implements to report mmic debug information
 * Command: XCP_USER_CMD_SET_OPERATION_MODE (F1 01)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-287382
 *
 * SRD
 * WorkItem 1 : WI-286731
 * WorkItem 2 : WI-286732
 * WorkItem 3 : WI-286733
 * WorkItem 4 : WI-288118
 * \\input{XCP_User_Cmd_Set_Operation_Mode}
 */
static uint8_t XCP_User_Cmd_Set_Operation_Mode(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd, uint8_t *response,
                                               uint8_t *framelength)
{
   uint8_t resp_index;
   XCP_Err_Code_T error                     = XCP_ERR_CMD_SYNCH_CPV;
   volatile uint8_t *xcp_operation_mode_ptr = xcp_input_ptr->xcp_operation_mode_ptr;

   if ((NULL != xcp_operation_mode_ptr) &&
       (XCP_RANGE_CHECK(cmnd[2], (uint8_t)XCP_OPCMD_NORMAL_MODE, (uint8_t)XCP_OPCMD_VALIDATION_MANF_TEST_MODE)))
   {
      *xcp_operation_mode_ptr = cmnd[2];
   }
   else
   {
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   {
      resp_index             = 0U;
      response[resp_index++] = XCP_POSITIVE_RESPONSE_CPV;
      response[resp_index++] = cmnd[1];
      response[resp_index++] = cmnd[2];
      *framelength           = resp_index;
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }
   return (XCP_CMD_OK_CPV);
}

/**
 * FUNCTION:XCP_User_Cmd_Set_Radar_To_CW_Mode
 * This function implements xcp command to enable and disable cw mode.
 * Command: XCP_USER_CMD_SET_RADAR_TO_CW_MODE (F1 14)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-288029
 *
 * SRD
 * WorkItem 1 : WI- 291089
 * WorkItem 2 : WI- 291090
 * WorkItem 3 : WI- 291091
 * \\input{XCP_User_Cmd_Set_Radar_To_CW_Mode}
 */
static uint8_t XCP_User_Cmd_Set_Radar_To_CW_Mode(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd,
                                                 uint8_t *response, uint8_t *framelength)
{
   uint8_t resp_index;
   XCP_Err_Code_T error          = XCP_ERR_CMD_SYNCH_CPV;
   uint8_t *xcp_cw_mode_ptr      = xcp_input_ptr->xcp_cw_mode_ptr;
   uint8_t xcp_radar_radiate_cmd = xcp_input_ptr->xcp_radar_radiate_cmd;
   uint8_t xcp_radar_init_status = xcp_input_ptr->xcp_radar_init_status;

   if (xcp_cw_mode_ptr != NULL)
   {
      if ((CODED_TRUE == xcp_radar_radiate_cmd) && ((uint8_t)XCP_RADAR_INIT_SUCCESS == xcp_radar_init_status))
      {
         if ((uint8_t)XCP_CW_MODE_ENABLE == cmnd[2])
         {
            *xcp_cw_mode_ptr = CODED_TRUE;
         }
         else if ((uint8_t)XCP_CW_MODE_DISABLE == cmnd[2])
         {
            *xcp_cw_mode_ptr = CODED_FALSE;
         }
         else
         {
            error = XCP_ERR_OUT_OF_RANGE_CPV;
         }
      }
      else
      {
         if ((CODED_FALSE == xcp_radar_radiate_cmd) && ((uint8_t)XCP_RADAR_INIT_STARTED == xcp_radar_init_status))
         {
            error = XCP_ERR_CMD_BUSY_CPV;
         }

         else
         {
            error = XCP_ERR_CONDITIONS_NOT_CORRECT;
         }
      }
   }
   else
   {
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   {
      resp_index             = 0U;
      response[resp_index++] = XCP_POSITIVE_RESPONSE_CPV;
      response[resp_index++] = cmnd[1];
      response[resp_index++] = cmnd[2];
      *framelength           = resp_index;
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }
   return (XCP_CMD_OK_CPV);
}

/**
 * FUNCTION:XCP_User_Cmd_Radar_Transmitter_Enable
 * This function implements xcp command to enable and disable transmitter ON and OFF.
 * Command: XCP_USER_CMD_RADAR_TRANSMITTER_ENABLE (F1 02)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-277959
 *
 * SRD
 * WorkItem 1 : WI-268199
 * WorkItem 2 : WI-268203
 * WorkItem 3 : WI-268207
 * WorkItem 4 : WI-268223
 * WorkItem 5 : WI-297716
 * WorkItem 6 : WI-297715
 * \\input{XCP_User_Cmd_Radar_Transmitter_Enable}
 */
static uint8_t XCP_User_Cmd_Radar_Transmitter_Enable(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd,
                                                     uint8_t *response, uint8_t *framelength)
{
   uint8_t resp_index;
   XCP_Err_Code_T error                    = XCP_ERR_CMD_SYNCH_CPV;
   volatile uint8_t *xcp_force_radiate_ptr = xcp_input_ptr->xcp_force_radiate_ptr;

   if ((xcp_force_radiate_ptr != NULL) && (XCP_RANGE_CHECK(cmnd[2], XCP_FORCE_RADAR_NORMAL_OP, XCP_FORCE_RADIATE_OFF)))
   {
      *xcp_force_radiate_ptr = cmnd[2];
   }
   else
   {
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   {
      resp_index             = 0U;
      response[resp_index++] = XCP_POSITIVE_RESPONSE_CPV;
      response[resp_index++] = cmnd[1];
      response[resp_index++] = cmnd[2];
      *framelength           = resp_index;
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }
   return (XCP_CMD_OK_CPV);
}

/**
 * FUNCTION:XCP_User_Cmd_Inject_Fault
 * This function implements xcp command to Fake inject fault
 * Command: XCP_USER_CMD_FAKE_INJECT_FAULT (F1 12)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 *
 * SRD
 * WorkItem 1 : WI-335498
 * WorkItem 2 : WI-335502
 * WorkItem 3 : WI-335501
 * WorkItem 4 : WI-335503
 * WorkItem 5 : WI-335504
 * WorkItem 6 : WI-335505
 * \\input{XCP_User_Cmd_Inject_Fault}
 */
static uint8_t XCP_User_Cmd_Inject_Fault(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd, uint8_t *response,
                                         uint8_t *framelength)
{
   uint8_t resp_index;
   uint8_t ret_value          = XCP_CMD_OK_CPV;
   XCP_Err_Code_T error       = XCP_ERR_OUT_OF_RANGE_CPV;
   uint8_t index              = 0;
   uint8_t sys_domain_idx     = 0;
   uint8_t failure_count      = 0;
   uint8_t failure_type_min   = 0;
   uint8_t failure_type_max   = 0;
   uint8_t injection_ctrl_min = 0;
   uint8_t injection_ctrl_max = 0;

   const XCP_Fault_Inj_Handler_T *xcp_fault_inj_handler = NULL; /*Fault handlers for requested system domain*/

   XCP_Inject_Fault_T *xcp_inject_data                   = xcp_input_ptr->xcp_inject_fault_data;
   const XCP_Fault_Injection_Config_Table_T *fault_table = Get_XCP_Fault_Config_Table(); /*Get fault injection config table */
   const void *inject_fault_ptr_list[]                   = {(const void *)xcp_inject_data, (const void *)fault_table};

   /*NULL pointer check for fault injection config table and inject data structure*/
   if (NULL_PTR_CHECK(inject_fault_ptr_list))
   {
      if (cmnd[2] < (uint8_t)XCP_INJECT_SYS_DOMAIN_MAX)
      {
         sys_domain_idx        = (uint8_t)(cmnd[2]);
         failure_count         = fault_table[sys_domain_idx].xcp_fault_count;    /*Faults count in requested domain */
         xcp_fault_inj_handler = fault_table[sys_domain_idx].xcp_fault_handlers; /*Fault handlers for requested system domain*/

         /*Syntax check for F1 12 */
         /*Byte 2: Sys Domain ; Byte 3: Failure Type ; Byte 4: Injection Control */
         if (NULL != xcp_fault_inj_handler) /*NULL guard before dereferencing handler list*/
         {
            for (index = 0U; index < failure_count; index++)
            {
               failure_type_min = xcp_fault_inj_handler[index].xcp_failure_type_min; /*Failure type Min Range */
               failure_type_max = xcp_fault_inj_handler[index].xcp_failure_type_max; /*Failure type Max Range*/

               /*Find the handler matching the requested failure type*/
               if (XCP_RANGE_CHECK(cmnd[3], failure_type_min, failure_type_max))
               {
                  injection_ctrl_min = xcp_fault_inj_handler[index].xcp_injection_ctrl_min; /*Injection Control type Min Range*/
                  injection_ctrl_max = xcp_fault_inj_handler[index].xcp_injection_ctrl_max; /*Injection Control type Max Range*/

                  /*Validate injection control for this handler*/
                  if (XCP_RANGE_CHECK(cmnd[4], injection_ctrl_min, injection_ctrl_max))
                  { /*Syntax check passed - trigger injection*/
                     error = XCP_ERR_CMD_SYNCH_CPV;
                  }
                  else
                  { /*Injection control out of range for this failure type*/
                     error = XCP_ERR_OUT_OF_RANGE_CPV;
                  }
                  break; /*Handler entry found - stop searching regardless of inject control result*/
               }
            }
            /* If loop completes without break, no handler matched cmnd[3] - error stays XCP_ERR_OUT_OF_RANGE_CPV */
         }
      }
   }
   else
   {
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   {
      resp_index             = 0U;
      response[resp_index++] = XCP_POSITIVE_RESPONSE_CPV;
      response[resp_index++] = cmnd[1];
      response[resp_index++] = cmnd[2];
      response[resp_index++] = cmnd[3];
      response[resp_index++] = cmnd[4];
      *framelength           = resp_index;

      xcp_inject_data->xcp_sys_domain          = cmnd[2];
      xcp_inject_data->xcp_failure_type        = cmnd[3]; /*FT value - direct index into sparse handler array in SWC*/
      xcp_inject_data->xcp_inject_control      = cmnd[4]; /*IC value - direct index into sparse handler array in SWC*/
      xcp_inject_data->xcp_cmd_injection_recvd = CODED_TRUE;
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }

   return (ret_value);
}

/**
 * FUNCTION:XCP_User_Cmd_Read_Hardware_Version
 * This function reads hardware version
 * Command:  XCP_USER_CMD_READ_HARDWARE_VERSION (F1 0D)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-
 *
 * SRD
 * WorkItem 1 : WI-361626
 * WorkItem 2 : WI-361627
 * \\input{XCP_User_Cmd_Read_Hardware_Version}
 */
static uint8_t XCP_User_Cmd_Read_Hardware_Version(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd,
                                                  uint8_t *response, uint8_t *framelength)
{
   XCP_Err_Code_T error               = XCP_ERR_CMD_SYNCH_CPV;
   uint8_t *xcp_read_hardware_version = xcp_input_ptr->xcp_read_hardware_version_ptr;
   uint8_t resp_index;

   if (xcp_read_hardware_version == NULL)
   {
      error = XCP_ERR_CMD_SYNTAX_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   {
      resp_index             = 0U;
      response[resp_index++] = XCP_POSITIVE_RESPONSE_CPV;
      response[resp_index++] = cmnd[1];
      response[resp_index++] = *xcp_read_hardware_version;
      *framelength           = resp_index;
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }
   return (XCP_CMD_OK_CPV);
}

/**
 * FUNCTION:XCP_User_Cmd_Clear_Internal_Fault_Codes
 * This function implements to clear faults
 * Command: XCP_USER_CMD_CLEAR_INTERNAL_FAULT_CODES (F1 04)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-285748
 *
 * SRD
 * WorkItem 1 : WI-284242
 * \\input{XCP_User_Cmd_Clear_Internal_Fault_Codes}
 */
static uint8_t XCP_User_Cmd_Clear_Internal_Fault_Codes(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd,
                                                       uint8_t *response, uint8_t *framelength)
{
   uint8_t resp_index;
   XCP_Err_Code_T error                   = XCP_ERR_CMD_SYNCH_CPV;
   volatile uint8_t *xcp_clear_faults_ptr = xcp_input_ptr->xcp_clear_faults_ptr;

   if (xcp_clear_faults_ptr != NULL)
   {
      *xcp_clear_faults_ptr = CODED_TRUE;
   }
   else
   {
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   {
      resp_index             = 0U;
      response[resp_index++] = XCP_POSITIVE_RESPONSE_CPV;
      response[resp_index++] = cmnd[1];
      *framelength           = resp_index;
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }
   return (XCP_CMD_OK_CPV);
}

/**
 * FUNCTION:XCP_User_Cmd_ITV_Simulation_Control
 * This function implements enable or disable the updating of IPC and Feature function outputs as well as algorithm running in ECU
 * Command: XCP_USER_CMD_ITV_SIMULATION_CONTROL (F1 0F)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-288877
 *
 * SRD
 * WorkItem 1 : WI-288839
 * WorkItem 2 : WI-288840
 * WorkItem 3 : WI-288841
 * \\input{XCP_User_Cmd_ITV_Simulation_Control}
 */
static uint8_t XCP_User_Cmd_ITV_Simulation_Control(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd,
                                                   uint8_t *response, uint8_t *framelength)
{
   uint8_t resp_index;
   uint8_t *xcp_itv_adc_state = xcp_input_ptr->xcp_itv_adc_state;
   XCP_Err_Code_T error       = XCP_ERR_CMD_SYNCH_CPV;

   if (((uint8_t)XCP_SIM_CTRL_ADC_MCU_TEMP == cmnd[2]) &&
       (XCP_RANGE_CHECK(cmnd[3], (uint8_t)XCP_CONNECT_ADC, (uint8_t)XCP_DISCONNNECT_ADC)) && (NULL != xcp_itv_adc_state))
   {
      *xcp_itv_adc_state = cmnd[3];
   }
   else
   {
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   {
      resp_index             = 0U;
      response[resp_index++] = XCP_POSITIVE_RESPONSE_CPV;
      response[resp_index++] = cmnd[1];
      response[resp_index++] = cmnd[2];
      response[resp_index++] = cmnd[3];
      *framelength           = resp_index;
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }
   return (XCP_CMD_OK_CPV);
}

/**
 * FUNCTION:XCP_User_Cmd_Get_MCU_ID
 * This function implements read mcu ID over xcp
 * Command: XCP_USER_CMD_GET_MCU_ID (F1 97)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-285749
 *
 * SRD
 * WorkItem 1 : WI-268371
 * WorkItem 2 : WI-301637
 * WorkItem 3 : WI-304381
 * \\input{XCP_User_Cmd_Get_MCU_ID}
 */
static uint8_t XCP_User_Cmd_Get_MCU_ID(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd, uint8_t *response,
                                       uint8_t *framelength)
{
   XCP_Err_Code_T error                    = XCP_ERR_CMD_SYNCH_CPV;
   volatile uint8_t *xcp_get_mcu_id_ptr    = xcp_input_ptr->xcp_get_mcu_id_ptr;
   volatile uint8_t *xcp_get_unique_id_ptr = xcp_input_ptr->xcp_get_unique_id_ptr;
   uint8_t index                           = 0U;
   uint8_t offset                          = 2U; /* Reserve space for response code and command code */

   /* Fail fast: both pointers invalid */
   if ((NULL == xcp_get_mcu_id_ptr) && (NULL == xcp_get_unique_id_ptr))
   {
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }
   else
   {
      /* Copy MCU ID — always at offset 2 */
      if (xcp_get_mcu_id_ptr != NULL)
      {
         for (index = 0U; index < XCP_MCU_ID_LEN_IN_BYTES; index++)
         {
            response[offset++] = xcp_get_mcu_id_ptr[index];
         }
      }
      else
      {
         /* MCU ID absent: advance offset to Unique ID's fixed position
            to preserve the protocol response layout */
         offset = 2U + XCP_MCU_ID_LEN_IN_BYTES;
      }
      /* Copy Unique ID — always at fixed offset 2 + XCP_MCU_ID_LEN_IN_BYTES */
      if (xcp_get_unique_id_ptr != NULL)
      {
         for (index = 0U; index < XCP_UNIQUE_ID_LEN_IN_BYTES; index++)
         {
            response[offset++] = xcp_get_unique_id_ptr[index];
         }
      }
      *framelength = offset;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   {
      response[0] = XCP_POSITIVE_RESPONSE_CPV;
      response[1] = cmnd[1];
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }
   return (XCP_CMD_OK_CPV);
}

/**
 * FUNCTION:XCP_User_Cmd_Get_Transciever_Chip_ID
 * This function implements xcp command(F1 98) to get transceiver Chip ID
 * Command: XCP_USER_CMD_GET_TRANSCIEVER_CHIP_ID (F1 98)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-297891
 *
 * SRD
 * WorkItem 1 : WI-286042
 * WorkItem 2 : WI-286043
 * WorkItem 3 : WI-286044
 * \\input{XCP_User_Cmd_Get_Transciever_Chip_ID}
 */
static uint8_t XCP_User_Cmd_Get_Transciever_Chip_ID(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd,
                                                    uint8_t *response, uint8_t *framelength)
{
   XCP_Err_Code_T error                       = XCP_ERR_CMD_SYNCH_CPV;
   volatile uint8_t *xcp_get_mmic_chip_id_ptr = NULL;
   uint8_t mmic_chip_id_length                = xcp_input_ptr->xcp_MMIC_ChipID_Length;
   uint8_t index                              = 0;

   if (XCP_MMIC_DEVICE_1 == cmnd[2])
   { /* Transceiver Device 1 */
      xcp_get_mmic_chip_id_ptr = xcp_input_ptr->xcp_MMIC_A_ChipID_ptr;
   }
   else if (XCP_MMIC_DEVICE_2 == cmnd[2])
   { /* Transceiver Device 2 */
      xcp_get_mmic_chip_id_ptr = xcp_input_ptr->xcp_MMIC_B_ChipID_ptr;
   }
   else
   { /* negative response, if Command syntax valid but command�parameter(s) out of range. */
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if ((NULL != xcp_get_mmic_chip_id_ptr) && (mmic_chip_id_length <= XCP_TARGET_CHIPID_MAX_LENGTH))
   { /* receive ChipID Info */
      for (index = 0; index < mmic_chip_id_length; index++)
      {
         response[index + (uint8_t)3] = (uint8_t)(xcp_get_mmic_chip_id_ptr[index]);
      }
   }
   else
   { /* negative response, if Command syntax valid but command�parameter(s) out of range. */
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   { /* positive response */
      response[0]  = XCP_POSITIVE_RESPONSE_CPV;
      response[1]  = cmnd[1];
      response[2]  = cmnd[2];
      *framelength = (uint8_t)(index + 3);
   }
   else
   { /* negative response */
      *framelength = Prepare_Negative_Response(response, error);
   }

   return (XCP_CMD_OK_CPV);
}

/**
 * FUNCTION:XCP_User_Cmd_Get_SW_Version
 * This function implements read software version over xcp
 * Command: XCP_USER_CMD_GET_SW_VERSION (F1 0C)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-285896
 *
 * SRD
 * WorkItem 1 : WI-285744
 * WorkItem 2 : WI-285745
 * WorkItem 3 : WI-285746
 * \\input{XCP_User_Cmd_Get_SW_Version}
 */
static uint8_t XCP_User_Cmd_Get_SW_Version(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd, uint8_t *response,
                                           uint8_t *framelength)
{
   XCP_Err_Code_T error           = XCP_ERR_CMD_SYNCH_CPV;
   uint8_t *sw_version_ptr        = NULL;
   uint8_t **xcp_sw_ver           = xcp_input_ptr->xcp_sw_ver_ptr;
   uint8_t **xcp_cust_sw_ver      = xcp_input_ptr->xcp_cust_sw_ver_ptr;
   uint8_t xcp_en_cust_sw_ver_len = xcp_input_ptr->xcp_sw_ver_len;
   uint8_t xcp_customer_id        = xcp_input_ptr->xcp_customer_id;

   if ((cmnd[2] >= (uint8_t)XCP_PLT_SW_VER) && (cmnd[2] < (uint8_t)XCP_MAX_SW_VER))
   {
      if (NULL != xcp_sw_ver)
      {
         sw_version_ptr = xcp_sw_ver[cmnd[2]];
      }
   }
   else if (cmnd[2] >= (uint8_t)XCP_CUST_SW_VER_1)
   {
      if (NULL != xcp_cust_sw_ver)
      {
         sw_version_ptr = xcp_cust_sw_ver[(cmnd[2] - (uint8_t)XCP_CUST_SW_VER_1)];
      }
   }
   else
   {
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (sw_version_ptr != NULL)
   {
      memcpy(&response[4], sw_version_ptr, 3);
      if (CODED_TRUE == xcp_en_cust_sw_ver_len)
      {
         response[7] = sw_version_ptr[3];
      }
      else
      {
         response[7] = 0xFF;
      }
   }
   else
   {
      memset(&response[4], 0xFF, 4);
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   {
      response[0]  = XCP_POSITIVE_RESPONSE_CPV;
      response[1]  = cmnd[1];
      response[2]  = cmnd[2];
      response[3]  = xcp_customer_id;
      *framelength = 8U; /* +4 bytes of sw version */
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }
   return (XCP_CMD_OK_CPV);
}

/**
 * FUNCTION:XCP_User_Cmd_Stop_Transmitting_Periodic_Msgs
 * This function implements xcp command to enable and disable transmitter ON and OFF.
 * Command: XCP_USER_CMD_STOP_TRANSMITTING_PERIODIC_MSGS (F1 03)
 *
 * \param[in] const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-
 *
 * SRD
 * WorkItem 1 : WI- 353350
 * WorkItem 2 : WI- 353426
 * WorkItem 3 : WI- 353425
 * WorkItem 4 : WI- 353424
 * \\input{XCP_User_Cmd_Stop_Transmitting_Periodic_Msgs}
 */
static uint8_t XCP_User_Cmd_Stop_Transmitting_Periodic_Msgs(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd,
                                                            uint8_t *response, uint8_t *framelength)
{
   XCP_Err_Code_T error                   = XCP_ERR_CMD_SYNCH_CPV;
   uint8_t **xcp_stop_period_messagel_ptr = xcp_input_ptr->xcp_stop_periodic_message_ptr;

   if ((cmnd[2] < ((uint8_t)XCP_COMM_INTERFACES_MAX)) && (cmnd[3] <= ((uint8_t)XCP_STOP_MSG)))
   {
      if (xcp_stop_period_messagel_ptr[cmnd[2]] != NULL)
      {
         *xcp_stop_period_messagel_ptr[cmnd[2]] = cmnd[3];
      }
      else
      {
         error = XCP_ERR_OUT_OF_RANGE_CPV;
      }
   }
   else
   {
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   {
      response[0]  = XCP_POSITIVE_RESPONSE_CPV;
      response[1]  = cmnd[1];
      response[2]  = cmnd[2]; /* interface */
      response[3]  = cmnd[3]; /* interface normal or stop */
      *framelength = XCP_RES_LEN_4;
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }
   return (XCP_CMD_OK_CPV);
}

/**
 * FUNCTION:XCP_User_Cmd_Override_Memory_Fault
 * This function implements xcp command(F1 11) to override memory Fault Table
 * Command: XCP_USER_CMD_OVERRIDE_MEMORY_FAULT (F1 11)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-288709
 *
 * SRD
 * WorkItem 1 : WI-268356
 * WorkItem 2 : WI-268374
 * WorkItem 3 : WI-288441
 * \\input{XCP_User_Cmd_Override_Memory_Fault}
 */
static uint8_t XCP_User_Cmd_Override_Memory_Fault(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd,
                                                  uint8_t *response, uint8_t *framelength)
{
   uint8_t resp_index;
   uint8_t num_fault_bytes                                      = xcp_input_ptr->num_fault_bytes;
   volatile XCP_Fault_Override_T *xcp_Memory_Fault_Override_ptr = xcp_input_ptr->xcp_fault_override_ptr;
   XCP_Err_Code_T error                                         = XCP_ERR_CMD_SYNCH_CPV;

   if ((xcp_Memory_Fault_Override_ptr != NULL) &&
       (XCP_RANGE_CHECK(cmnd[2], (uint8_t)XCP_AUTO_MODE, (uint8_t)XCP_CLEAR_FAULT_MODE)) && (cmnd[3] < num_fault_bytes) &&
       (cmnd[4] < XCP_MEMORY_FAULT_BIT_MAX_SIZE))
   {
      /* Update action, byte_pos and bit_pos with valid values */
      xcp_Memory_Fault_Override_ptr->action   = cmnd[2];
      xcp_Memory_Fault_Override_ptr->byte_pos = cmnd[3];
      xcp_Memory_Fault_Override_ptr->bit_pos  = cmnd[4];
   }
   else
   { /* negative response, if pointer(s) are pointing to nothing. */
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   { /* positive response */
      resp_index             = 0U;
      response[resp_index++] = XCP_POSITIVE_RESPONSE_CPV;
      response[resp_index++] = cmnd[1];
      response[resp_index++] = cmnd[2];
      *framelength           = resp_index;
   }
   else
   { /* negative response */
      *framelength = Prepare_Negative_Response(response, error);
   }

   return (XCP_CMD_OK_CPV);
}

/**
 * FUNCTION:XCP_User_Cmd_Target_Select
 * This function implements xcp command(F1 9A) to select 3 target bins to focus on.
 * Command: XCP_USER_CMD_TARGET_SELECT (F1 9A)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-295861
 *
 * SRD
 * WorkItem 1 : WI-295830
 * WorkItem 2 : WI-295831
 * WorkItem 3 : WI-295833
 * WorkItem 4 : WI-295832
 * \\input{XCP_User_Cmd_Target_Select}
 */
static uint8_t XCP_User_Cmd_Target_Select(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd, uint8_t *response,
                                          uint8_t *framelength)
{
   XCP_Err_Code_T error                           = XCP_ERR_CMD_SYNCH_CPV;
   uint8_t xcp_num_of_looks                       = xcp_input_ptr->xcp_num_of_looks;
   uint8_t xcp_target_selection_num               = xcp_input_ptr->xcp_target_selection_num;
   uint16_t xcp_max_number_range_bin              = xcp_input_ptr->xcp_max_number_range_bin;
   uint16_t xcp_max_number_doppler_bin            = xcp_input_ptr->xcp_max_number_doppler_bin;
   volatile uint8_t *xcp_target_select_enable_ptr = xcp_input_ptr->xcp_target_select_enable_ptr;
   volatile uint16_t *xcp_target_range_idx_ptr    = xcp_input_ptr->xcp_target_range_idx_ptr;
   volatile uint16_t *xcp_target_doppler_idx_ptr  = xcp_input_ptr->xcp_target_doppler_idx_ptr;
   uint8_t resp_index, index = 0, index2 = 0, target_select_data_size = 0;
   uint16_t range = 0, doppler = 0;
   bool xcp_max_range_flag = false;

   const void *target_select_ptr_list[] = {(const void *)xcp_target_select_enable_ptr, (const void *)xcp_target_range_idx_ptr,
                                           (const void *)xcp_target_doppler_idx_ptr};

   if (NULL_PTR_CHECK(target_select_ptr_list)) /* Check if pointers for target select are not NULL */
   {
      /* Target_Select_Datasize = 3 targets * 4 looks * (2 bytes range index + 2 bytes doppler index)*/
      target_select_data_size = (uint8_t)((xcp_target_selection_num) * (xcp_num_of_looks) *
                                          (XCP_TARGET_RANGE_INDEX_SIZE + XCP_TARGET_DOPPLER_INDEX_SIZE));

      /* Default enable Target_select */
      *xcp_target_select_enable_ptr = CODED_TRUE;

      for (index = 2U; ((index < (target_select_data_size + 2U)) && (!xcp_max_range_flag)); index += 4U)
      { /* check range and dopper value is valid */
         range   = (uint16_t)((cmnd[index + (uint8_t)1U] << 8U) | (cmnd[index]));
         doppler = (uint16_t)((cmnd[index + (uint8_t)3U] << 8U) | (cmnd[index + 2U]));

         if ((range > xcp_max_number_range_bin) || (doppler > xcp_max_number_doppler_bin))
         {
            /*negative response, if recieved range or doppler value is not valid */
            error = XCP_ERR_OUT_OF_RANGE_CPV;
            /* Disable Target_select */
            *xcp_target_select_enable_ptr = CODED_FALSE;
            /* fill range and doppler index with 0x00 value*/
            memset((uint16_t *)xcp_target_range_idx_ptr, 0U, (target_select_data_size / XCP_TARGET_RANGE_INDEX_SIZE));
            memset((uint16_t *)xcp_target_doppler_idx_ptr, 0U, (target_select_data_size / XCP_TARGET_DOPPLER_INDEX_SIZE));
            xcp_max_range_flag = true;
         }
         else
         { /* copy local range and doppler value to global varaibles if valid*/
            xcp_target_range_idx_ptr[index2]   = range;
            xcp_target_doppler_idx_ptr[index2] = doppler;
         }
         index2++;
      }
   }
   else
   {
      /* negative response, if Command syntax valid but command�parameter(s) out of range */
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   { /* positive response */
      resp_index             = 0U;
      response[resp_index++] = XCP_POSITIVE_RESPONSE_CPV;
      response[resp_index++] = cmnd[1];
      *framelength           = resp_index;
   }
   else
   { /* negative response */
      *framelength = Prepare_Negative_Response(response, error);
   }

   return (XCP_CMD_OK_CPV);
}

/**
 * FUNCTION:XCP_User_Cmd_Data_Flash
 * This function implements xcp command to enable and disable transmitter ON and OFF.
 * Command: XCP_USER_CMD_ERASE_DATA_FLASH (F1 05)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-286962
 *
 * SRD
 * WorkItem 1 : WI-278644
 * WorkItem 2 : WI-278643
 * WorkItem 3 : WI-278642
 * WorkItem 4 : WI-281553
 * \\input{XCP_User_Cmd_Data_Flash}
 */
static uint8_t XCP_User_Cmd_Data_Flash(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd, uint8_t *response,
                                       uint8_t *framelength)
{
   XCP_Err_Code_T error                     = XCP_ERR_CMD_SYNCH_CPV;
   volatile uint8_t *xcp_nvm_ptr            = xcp_input_ptr->xcp_nvm_ptr;
   volatile uint8_t *xcp_nvm_cmd_status_ptr = xcp_input_ptr->xcp_nvm_prev_operation_status_ptr;
   uint8_t resp_index;

   if ((xcp_nvm_ptr != NULL) && XCP_RANGE_CHECK(cmnd[2], XCP_ERASE_ENTIRE_KAM, XCP_ERASE_SPECIFIC_KAM_BLOCKS))
   {
      if ((uint8_t)XCP_VERIFY_KAM_UPDATE_STATUS == cmnd[2])
      {
         *xcp_nvm_ptr = (uint8_t)XCP_VERIFY_KAM_UPDATE_STATUS;
         response[3]  = XCP_Data_Flash.nvm_cmnd;
         response[4]  = *xcp_nvm_cmd_status_ptr;
      }
      else
      { /* XCP_ERASE_ENTIRE_KAM / XCP_SET_KAM_TO_RAM_DEFAULT / XCP_ERASE_KAM_AND_SET_DEFAULT /
            XCP_FORCE_SAVE_RAM_TO_KAM / XCP_ERASE_SPECIFIC_KAM_BLOCKS */
         if (*xcp_nvm_cmd_status_ptr != (uint8_t)XCP_NVM_STATUS_PENDING)
         {
            if ((uint8_t)XCP_ERASE_ENTIRE_KAM == cmnd[2])
            {
               if (CODED_FALSE == XCP_Data_Flash.nvm_erase_status)
               {
                  *xcp_nvm_ptr                    = (uint8_t)XCP_ERASE_ENTIRE_KAM;
                  XCP_Data_Flash.nvm_cmnd         = (uint8_t)XCP_ERASE_ENTIRE_KAM;
                  XCP_Data_Flash.nvm_erase_status = CODED_TRUE;
               }
               else
               {
                  error = XCP_ERR_CONDITIONS_NOT_CORRECT;
               }
            }
            else
            {
               *xcp_nvm_ptr            = cmnd[2];
               XCP_Data_Flash.nvm_cmnd = cmnd[2];
            }
         }
         else
         {
            error = XCP_ERR_CMD_BUSY_CPV;
         }
      }
   }
   else
   {
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   {
      resp_index             = 0U;
      response[resp_index++] = XCP_POSITIVE_RESPONSE_CPV;
      response[resp_index++] = cmnd[1];
      response[resp_index++] = cmnd[2];
      *framelength           = XCP_RES_LEN_5; /*??  + 2 bytes extra */
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }
   return (XCP_CMD_OK_CPV);
}

/**
 * FUNCTION: Is_Valid_LED_State
 * This function validates the LED output state
 *
 * \param[in] XCP_LED_Output_State_T state - LED output state to validate
 *
 * \return bool - true if state is valid, false otherwise
 */
static bool Is_Valid_LED_State(XCP_LED_Output_State_T state)
{
   bool ret_value = false;
   switch (state)
   { /* All the valid states for LED output */
      case XCP_OUT_STATE_AUTO:
      case XCP_OUT_STATE_FORCED_OFF:
      case XCP_OUT_STATE_FORCED_ON:
      case XCP_OUT_STATE_FORCED_5_PWM:
      case XCP_OUT_STATE_FORCED_50_PWM:
      case XCP_OUT_STATE_FORCED_95_PWM:
         ret_value = true;
         break;
      default:
         /* No action */
         break;
   }
   return ret_value;
}
/**
 * FUNCTION:XCP_User_Cmd_Set_Output_State
 * This function sets the output led state
 * Command: XCP_USER_CMD_SET_OUTPUT_STATE (F1 1F)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-289151
 *
 * SRD
 * WorkItem 1 : WI-287976
 * WorkItem 2 : WI-287977
 * \\input{XCP_User_Cmd_Set_Output_State}
 */
static uint8_t XCP_User_Cmd_Set_Output_State(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd, uint8_t *response,
                                             uint8_t *framelength)
{
   XCP_Err_Code_T error                             = XCP_ERR_CMD_SYNCH_CPV;
   XCP_LED_Output_Cntrl_T *xcp_out_set_output_state = xcp_input_ptr->xcp_out_set_output_state;
   XCP_LED_Output_State_T led_state                 = (XCP_LED_Output_State_T)cmnd[3];
   uint8_t output_pin_num                           = cmnd[2]; /* output pin number received from command */

   if ((NULL != xcp_out_set_output_state) && (XCP_RANGE_CHECK(output_pin_num, XCP_OUTPUT_START_PIN, XCP_OUTPUT_END_PIN)) &&
       (Is_Valid_LED_State(led_state)))
   {
      xcp_out_set_output_state->xcp_out_select = output_pin_num;
      xcp_out_set_output_state->xcp_out_state  = led_state;
   }
   else
   {
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   {
      response[0]  = XCP_POSITIVE_RESPONSE_CPV;
      response[1]  = cmnd[1];
      response[2]  = cmnd[2];
      response[3]  = cmnd[3];
      *framelength = 4;
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }
   return (XCP_CMD_OK_CPV);
}

/**
 * FUNCTION:XCP_User_Cmd_Set_Override_Control_Variable
 * This function implements xcp command to set the override variable (F1 22).
 * Command: XCP_USER_CMD_SET_OVERRIDE_CONTROL_VARIABLE (F1 22)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-296305
 *
 * SRD
 * WorkItem 1 : WI- 268258
 * WorkItem 2 : WI- 268262
 * WorkItem 3 : WI- 268266
 * \\input{XCP_User_Cmd_Set_Override_Control_Variable}
 */
static uint8_t XCP_User_Cmd_Set_Override_Control_Variable(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd,
                                                          uint8_t *response, uint8_t *framelength)
{
   uint8_t ret_value                           = XCP_CMD_OK_CPV;
   XCP_Err_Code_T error                        = XCP_ERR_CMD_SYNCH_CPV;
   volatile uint16_t *xcp_set_override_var_ptr = xcp_input_ptr->xcp_set_override_var_ptr;
   uint16_t sensitivity_factor                 = 0U;

   if ((CODED_FALSE == Get_XCP_Pending_Cmnd_Status()) && (xcp_set_override_var_ptr != NULL))
   {
      if (XCP_CNTRL_VARIABLE == cmnd[2])
      { /* recieved Ctrl_Variable is valid */
         sensitivity_factor        = (uint16_t)((cmnd[3] << 8U) | (cmnd[4]));
         *xcp_set_override_var_ptr = sensitivity_factor;

         XCP_Override_Data = sensitivity_factor;
         Set_XCP_Periodic_User_Cmd(cmnd[1], XCP_OVERRIDE_TIMEOUT, &XCP_Set_Override_Periodic_Task);
         ret_value = XCP_CMD_PENDING_CPV;
      }
      else
      { /* negative response, if recieved Ctrl_Variable is Invalid */
         error = XCP_ERR_OUT_OF_RANGE_CPV;
      }
   }
   else
   { /* negative response, if Command syntax valid but command�parameter(s) out of range */
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   { /* Positive Response  will be sent in periodic task*/
   }
   else
   { /* negative response */
      *framelength = Prepare_Negative_Response(response, error);

      /* clear periodic user command */
      Set_XCP_Periodic_User_Cmd(0U, 0U, NULL);

      XCP_Override_Data = 0U;
   }
   return (ret_value);
}

/**
 * FUNCTION:XCP_Set_Override_Periodic_Task
 * This function implements xcp command to set the override variable (F1 22).
 * This periodic function is being utilized by xcp_user_cmd_set_override_control_variable (F1 22)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-296305
 *
 * SRD
 * WorkItem 1 : WI- 268258
 * WorkItem 2 : WI- 268262
 * WorkItem 3 : WI- 268266
 * \\input{xcp_user_cmd_set_override_control_variable}
 */
static uint8_t XCP_Set_Override_Periodic_Task(XCP_BB_Input_Params_T *const xcp_input_ptr, uint8_t *response, uint8_t *framelength)
{
   uint8_t resp_index;
   uint8_t ret_value                           = XCP_CMD_PENDING_CPV;
   volatile uint16_t *xcp_get_override_var_ptr = xcp_input_ptr->xcp_get_override_var_ptr;

   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt++;

   if (Is_Cycle_Cnt_Valid)
   {
      if (*xcp_get_override_var_ptr == XCP_Override_Data)
      {
         /* Update the positive response */
         resp_index             = 0U;
         response[resp_index++] = XCP_POSITIVE_RESPONSE_CPV;
         response[resp_index++] = XCP_USER_CMD_SET_OVERRIDE_CONTROL_VARIABLE;
         response[resp_index++] = XCP_SENS_SCALING_FACTOR;
         response[resp_index++] = GET_BYTE((*xcp_get_override_var_ptr), 1U);
         response[resp_index++] = GET_BYTE((*xcp_get_override_var_ptr), 0U);

         *framelength = resp_index;
         ret_value    = XCP_CMD_OK_CPV;

         /* clear periodic user command */
         Set_XCP_Periodic_User_Cmd(0U, 0U, NULL);

         XCP_Override_Data = 0U;
      }
   }
   else
   {
      /* Update the negative response */
      *framelength = Prepare_Negative_Response(response, XCP_ERR_CMD_BUSY_CPV);
      ret_value    = XCP_CMD_OK_CPV;

      /* clear periodic user command */
      Set_XCP_Periodic_User_Cmd(0U, 0U, NULL);

      XCP_Override_Data = 0U;
   }
   return (ret_value);
}

/**
 * FUNCTION:XCP_User_Cmd_Get_Override_Control_Variable
 * This function implements xcp command to get the override variable (F1 23).
 * Command: XCP_USER_CMD_GET_OVERRIDE_CONTROL_VARIABLE (F1 23)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-296304
 * WorkItem 2 :
 *
 * SRD
 * WorkItem 1 : WI- 268243
 * WorkItem 2 : WI- 268246
 * WorkItem 3 : WI- 268250
 * \\input{XCP_User_Cmd_Get_Override_Control_Variable}
 */
static uint8_t XCP_User_Cmd_Get_Override_Control_Variable(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd,
                                                          uint8_t *response, uint8_t *framelength)
{
   XCP_Err_Code_T error                        = XCP_ERR_CMD_SYNCH_CPV;
   volatile uint16_t *xcp_get_override_var_ptr = xcp_input_ptr->xcp_get_override_var_ptr;
   uint8_t resp_index;

   if (NULL != xcp_get_override_var_ptr)
   {
      if (XCP_CNTRL_VARIABLE == cmnd[2])
      { /* recieved Ctrl_Variable is valid */
         response[3] = GET_BYTE((*xcp_get_override_var_ptr), 1U);
         response[4] = GET_BYTE((*xcp_get_override_var_ptr), 0U);
      }
      else
      { /* negative response, if recieved Ctrl_Variable is Invalid */
         error = XCP_ERR_OUT_OF_RANGE_CPV;
      }
   }
   else
   { /* negative response, if Command syntax valid but command�parameter(s) out of range */
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   { /* positive response */
      resp_index             = 0U;
      response[resp_index++] = XCP_POSITIVE_RESPONSE_CPV;
      response[resp_index++] = cmnd[1];
      response[resp_index++] = cmnd[2];
      *framelength           = XCP_RES_LEN_5; /*??  + 2 bytes of control variable value */
   }
   else
   { /* negative response */
      *framelength = Prepare_Negative_Response(response, error);
   }
   return (XCP_CMD_OK_CPV);
}

/**
 * FUNCTION:XCP_User_Cmd_Write_Alignment_Data
 * This function implements xcp command to write data to alignment parameters.
 * Command: XCP_USER_CMD_WRITE_ALIGNMENT_DATA (F1 30)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-
 *
 * SRD
 * WorkItem 1 : WI-
 * WorkItem 2 : WI-
 * WorkItem 3 : WI-
 * WorkItem 4 : WI-
 * \\input{XCP_User_Cmd_Write_Alignment_Data}
 */
static uint8_t XCP_User_Cmd_Write_Alignment_Data(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd,
                                                 uint8_t *response, uint8_t *framelength)
{
   uint8_t ret_value                       = XCP_CMD_OK_CPV;
   XCP_Err_Code_T error                    = XCP_ERR_CMD_SYNCH_CPV;
   uint8_t **xcp_write_memory_ptr          = xcp_input_ptr->xcp_write_align_memory_ptr;
   XCP_Write_Alignment_T *xcp_align_ptr    = xcp_input_ptr->xcp_wrtie_align_data_ptr;
   uint8_t(*xcp_write_alignment_ptr)[2][2] = NULL;
   uint8_t *xcp_data_ptr                   = NULL;
   uint8_t xcp_data_index                  = 0x04U;
   uint8_t no_of_para_types                = 0;
   uint8_t index_p                         = 0;
   uint8_t index_s                         = 0;
   uint8_t index_m                         = 0;

   if ((Get_XCP_Pending_Cmnd_Status() == CODED_FALSE) && (cmnd[2] < (uint8_t)XCP_WRITE_ALIGNMENT_MAX))
   {
      /*Get the ptr dat for the respective subcmd*/
      xcp_write_alignment_ptr = XCP_Write_Align_Data_Info[cmnd[2]];
      xcp_data_ptr            = xcp_write_memory_ptr[cmnd[2]];
      if ((NULL != xcp_write_alignment_ptr) && (NULL != xcp_data_ptr))
      {
         /*Check for the quantity - zeorth index data in 2d array holding the no of parameters*/
         if (cmnd[3] == ((*xcp_write_alignment_ptr)[0][0] + (*xcp_write_alignment_ptr)[1][0]))
         {
            /* run the loop for data type  (4bytes and 1 byte )*/
            do
            {
               /* loop for no of parameter per data type*/
               for (index_p = 0x00U; index_p < (*xcp_write_alignment_ptr)[no_of_para_types][0]; index_p++)
               {
                  (void)index_p;
                  /*loop run for size of data type */
                  for (index_s = 0x00U; index_s < (*xcp_write_alignment_ptr)[no_of_para_types][1]; index_s++)
                  {
                     xcp_data_ptr[index_m] = cmnd[xcp_data_index + index_s];
                     index_m++;
                  }
                  /*increment to next data element*/
                  xcp_data_index += XCP_ALIGNMENT_DATA_LENGTH;
               }
               no_of_para_types++;
            } while (no_of_para_types < XCP_WRITE_ALIGNMENT_NO_OF_DATA_TYPES);
         }
         else
         {
            error = XCP_ERR_OUT_OF_RANGE_CPV;
         }
      }
   }
   else
   {
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   {
      Set_XCP_Periodic_User_Cmd(cmnd[1], XCP_WRITE_ALIGNMENT_TIMEOUT, &XCP_Write_Alignment_Periodic_Task);
      xcp_align_ptr->cmd_recived  = CODED_TRUE;
      xcp_align_ptr->sub_cmd      = cmnd[2];
      xcp_align_ptr->quantity     = cmnd[3];
      xcp_align_ptr->write_status = (uint8_t)XCP_WRITE_ALIGNMENT_IDLE;
      ret_value                   = XCP_CMD_PENDING_CPV;
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }
   return (ret_value);
}

/**
 * FUNCTION:XCP_User_Cmd_Read_Alignment_Data
 * This function implements xcp command to write data to alignment parameters.
 * Command: XCP_USER_CMD_READ_ALIGNMENT_DATA (F1 31)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-
 *
 * SRD
 * WorkItem 1 : WI-
 * WorkItem 2 : WI-
 * WorkItem 3 : WI-
 * WorkItem 4 : WI-
 * \\input{XCP_User_Cmd_Read_Alignment_Data}
 */
static uint8_t XCP_User_Cmd_Read_Alignment_Data(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd, uint8_t *response,
                                                uint8_t *framelength)
{
   uint8_t ret_value                      = XCP_CMD_OK_CPV;
   XCP_Err_Code_T error                   = XCP_ERR_CMD_SYNCH_CPV;
   uint8_t **xcp_read_memory_ptr          = xcp_input_ptr->xcp_read_align_memory_ptr;
   uint8_t(*xcp_read_alignment_ptr)[2][2] = NULL;
   uint8_t *xcp_data_ptr                  = NULL;
   uint8_t xcp_data_index                 = 4U;
   uint8_t no_of_para_types               = 0U;
   uint8_t index_p                        = 0U;
   uint8_t index_s                        = 0U;
   uint8_t index_m                        = 0U;

   if ((Get_XCP_Pending_Cmnd_Status() == CODED_FALSE) && (cmnd[2] <= (uint8_t)XCP_READ_ALIGNMENT_SUBCMD_END))
   {
      /*Get the ptr dat for the respective subcmd*/
      xcp_read_alignment_ptr = XCP_Read_Align_Data_Info[cmnd[2]];
      xcp_data_ptr           = xcp_read_memory_ptr[cmnd[2]];

      if ((NULL != xcp_read_alignment_ptr) && (NULL != xcp_data_ptr))
      {
         /*Check for the quantity - zeorth index data in 2d array holding the no of parameters*/
         if (cmnd[3] == ((*xcp_read_alignment_ptr)[0][0] + (*xcp_read_alignment_ptr)[1][0]))
         {
            /* run the loop for data type  (4bytes and 1 byte )*/
            do
            {
               /* loop for no of parameter per data type*/
               for (index_p = 0; index_p < (*xcp_read_alignment_ptr)[no_of_para_types][0]; index_p++)
               {
                  (void)index_p;
                  /*loop run for size of data type */
                  for (index_s = 0; index_s < (*xcp_read_alignment_ptr)[no_of_para_types][1]; index_s++)
                  {
                     response[xcp_data_index + index_s] = xcp_data_ptr[index_m];
                     index_m++;
                  }
                  /* if data type is uint8_t fill remaining bytes are zero as per Requirement*/
                  if ((*xcp_read_alignment_ptr)[no_of_para_types][1] == sizeof(uint8_t))
                  {
                     response[xcp_data_index + 1] = 0x00U;
                     response[xcp_data_index + 2] = 0x00U;
                     response[xcp_data_index + 3] = 0x00U;
                  }
                  /*in crement to next data element */
                  xcp_data_index += XCP_ALIGNMENT_DATA_LENGTH;
               }
               /* Increment for the next data type*/
               no_of_para_types++;

            } while (no_of_para_types < XCP_READ_ALIGNMENT_NO_OF_DATA_TYPES);
         }
         else
         {
            error = XCP_ERR_OUT_OF_RANGE_CPV;
         }
      }
      else
      {
         error = XCP_ERR_OUT_OF_RANGE_CPV;
      }
   }
   else
   {
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   {
      response[0] = XCP_POSITIVE_RESPONSE_CPV;
      response[1] = cmnd[1];
      response[2] = cmnd[2]; /* sub interface */
      response[3] = cmnd[3]; /* quantity */
      /* length - each data is 4 bytes and header is 4 bytes */
      *framelength = (uint8_t)((cmnd[3] * XCP_ALIGNMENT_DATA_LENGTH) + XCP_ALIGNMENT_READ_HEADER);
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }
   return (ret_value);
}

/*****************************************************************************
 *. Name: XCP_Write_Alignment_Periodic_Task
 *. This periodic function is being utilized by xcp_user_cmd_write_alignment_data (F1 30)
 *. Shared Variables: uint8_t* ,uint8_t*
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
static uint8_t XCP_Write_Alignment_Periodic_Task(XCP_BB_Input_Params_T *const xcp_input_ptr, uint8_t *response,
                                                 uint8_t *framelength)
{
   uint8_t ret_value                    = XCP_CMD_PENDING_CPV;
   XCP_Write_Alignment_T *xcp_align_ptr = xcp_input_ptr->xcp_wrtie_align_data_ptr;

   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt++;

   if (Is_Cycle_Cnt_Valid)
   {
      if ((uint8_t)XCP_WRITE_ALIGNMENT_DONE == xcp_align_ptr->write_status)
      {
         /* Update the positive response */
         uint8_t resp_index     = 0U;
         response[resp_index++] = XCP_POSITIVE_RESPONSE_CPV;
         response[resp_index++] = XCP_USER_CMD_WRITE_ALIGNMENT_DATA;
         response[resp_index++] = xcp_align_ptr->sub_cmd;
         response[resp_index++] = xcp_align_ptr->quantity;
         *framelength           = resp_index;
         ret_value              = XCP_CMD_OK_CPV;

         /* clear periodic user command */
         Set_XCP_Periodic_User_Cmd(0U, 0U, NULL);

         xcp_align_ptr->cmd_recived    = CODED_FALSE;
         xcp_align_ptr->sub_cmd        = 0;
         xcp_align_ptr->quantity       = 0;
         xcp_align_ptr->write_status   = (uint8_t)XCP_WRITE_ALIGNMENT_IDLE;
         xcp_align_ptr->write_nvm_flag = CODED_FALSE;
      }
   }
   else
   {
      /* Update the negative response */
      *framelength                  = Prepare_Negative_Response(response, XCP_ERR_CMD_BUSY_CPV);
      xcp_align_ptr->cmd_recived    = CODED_FALSE;
      xcp_align_ptr->sub_cmd        = 0;
      xcp_align_ptr->quantity       = 0;
      xcp_align_ptr->write_status   = (uint8_t)XCP_WRITE_ALIGNMENT_IDLE;
      xcp_align_ptr->write_nvm_flag = CODED_FALSE;
      ret_value                     = XCP_CMD_OK_CPV;

      /* clear periodic user command */
      Set_XCP_Periodic_User_Cmd(0U, 0U, NULL);
   }
   return (ret_value);
}

/**
 * FUNCTION:XCP_Fault_Common
 * This function implements common logic for reading fault table data and preparing
 * the XCP response. Used by history fault, active fault, and active fault latched commands.
 *
 * \param[in] volatile uint8_t *fault_table_ptr - Pointer to the fault table data
 * \param[in] uint8_t num_fault_bytes - Maximum number of fault bytes available
 * \param[in] const uint8_t *cmd - Pointer to received command buffer
 * \param[out] uint8_t *resp_ptr - Pointer to response buffer
 * \param[out] uint8_t *frame_length - Pointer to response frame length
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
 *
 * SRD
 * WorkItem 1 :
 * \\input{XCP_Fault_Common}
 */
static void XCP_Fault_Common(volatile uint8_t *fault_table_ptr, uint8_t num_fault_bytes, const uint8_t *cmd, uint8_t *resp_ptr,
                             uint8_t *frame_length)
{
   uint8_t fault_cnt;
   XCP_Err_Code_T error = XCP_ERR_CMD_SYNCH_CPV;

   if ((fault_table_ptr != NULL) && (cmd[2] <= num_fault_bytes))
   {
      resp_ptr[0] = XCP_POSITIVE_RESPONSE_CPV;
      resp_ptr[1] = cmd[1];
      for (fault_cnt = 0; fault_cnt < cmd[2]; fault_cnt++)
      {
         resp_ptr[fault_cnt + 2] = fault_table_ptr[fault_cnt];
      }
      *frame_length = (uint8_t)(cmd[2] + 2);
   }
   else
   {
      /* negative response */
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   { /* response already filled */
   }
   else
   {
      *frame_length = Prepare_Negative_Response(resp_ptr, error);
   }
}

/**
 * FUNCTION:XCP_User_Cmd_Get_Fault_Test_Completed
 * This function implements xcp command to report fault test completed.
 * Command: XCP_USER_CMD_GET_FAULT_TEST_COMPLETED (F1 B0)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-289978
 *
 * SRD
 * WorkItem 1 : WI-289965
 * WorkItem 2 : WI-289966
 * WorkItem 3 : WI-289967
 * \\input{XCP_User_Cmd_Get_Fault_Test_Completed}
 */
static uint8_t XCP_User_Cmd_Get_Fault_Test_Completed(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd,
                                                     uint8_t *response, uint8_t *framelength)
{
   XCP_Err_Code_T error                       = XCP_ERR_CMD_SYNCH_CPV;
   volatile uint8_t *fault_test_completed_ptr = xcp_input_ptr->xcp_fault_test_completed_ptr;
   uint8_t num_fault_bytes                    = xcp_input_ptr->num_fault_bytes;
   uint8_t flag_Loopcnt                       = 0;

   if ((fault_test_completed_ptr != NULL) && (cmnd[2] <= num_fault_bytes))
   {
      /* fill the response buffer */
      for (flag_Loopcnt = 0U; flag_Loopcnt < cmnd[2]; flag_Loopcnt++)
      {
         response[flag_Loopcnt + 2U] = fault_test_completed_ptr[flag_Loopcnt];
      }
   }
   else
   {
      /* negative response, if l_fault_test_completed_ptr is null */
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   { /* positive response */
      response[0]  = XCP_POSITIVE_RESPONSE_CPV;
      response[1]  = cmnd[1];
      *framelength = (uint8_t)(cmnd[2] + 2);
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }
   return (XCP_CMD_OK_CPV);
}

/**
 * FUNCTION:XCP_User_Cmd_Get_History_Fault
 * This function implements xcp command to read transmitter temperature
 * Command: XCP_USER_CMD_GET_HISTORY_FAULT (F1 C0)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-278103
 *
 * SRD
 * WorkItem 1 : WI-277707
 * WorkItem 2 : WI-277708
 * WorkItem 3 : WI-277712
 * \\input{XCP_User_Cmd_Get_History_Fault}
 */
static uint8_t XCP_User_Cmd_Get_History_Fault(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd, uint8_t *response,
                                              uint8_t *framelength)
{
   XCP_Fault_Common(xcp_input_ptr->history_fault_table_ptr, xcp_input_ptr->num_fault_bytes, cmnd, response, framelength);
   return (XCP_CMD_OK_CPV);
}

/**
 * FUNCTION:XCP_User_Cmd_Get_Active_Fault
 * This function implements xcp command to read transmitter temperature
 * Command: XCP_USER_CMD_GET_ACTIVE_FAULT (F1 D0)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-278105
 *
 * SRD
 * WorkItem 1 : WI-277710
 * WorkItem 2 : WI-277709
 * WorkItem 3 : WI-277711
 * \\input{XCP_User_Cmd_Get_Active_Fault}
 */
static uint8_t XCP_User_Cmd_Get_Active_Fault(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd, uint8_t *response,
                                             uint8_t *framelength)
{
   XCP_Fault_Common(xcp_input_ptr->active_fault_table_ptr, xcp_input_ptr->num_fault_bytes, cmnd, response, framelength);
   return (XCP_CMD_OK_CPV);
}

/**
 * FUNCTION:XCP_User_Cmd_Get_Active_Fault_Latched
 * This function implements xcp command to read transmitter temperature
 * Command: XCP_USER_CMD_GET_ACTIVE_FAULT_LATCHED (F1 E0)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-278107
 *
 * SRD
 * WorkItem 1 : WI-277714
 * WorkItem 2 : WI-277716
 * WorkItem 3 : WI-277715
 * \\input{XCP_User_Cmd_Get_Active_Fault_Latched}
 */
static uint8_t XCP_User_Cmd_Get_Active_Fault_Latched(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd,
                                                     uint8_t *response, uint8_t *framelength)
{
   XCP_Fault_Common(xcp_input_ptr->active_fault_latch_table_ptr, xcp_input_ptr->num_fault_bytes, cmnd, response, framelength);
   return (XCP_CMD_OK_CPV);
}

/**
 * FUNCTION:XCP_User_Cmd_Get_Checksum_Results
 *. This function implements to report mmic debug information
 *
 * \param[in] const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-281163
 *
 * SRD
 * WorkItem 1 : WI-280174
 * WorkItem 2 : WI_280175
 * \\input{XCP_User_Cmd_Get_Checksum_Results}
 */
static uint8_t XCP_User_Cmd_Get_Checksum_Results(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd,
                                                 uint8_t *response, uint8_t *framelength)
{
   uint8_t ret_value                = XCP_CMD_OK_CPV;
   XCP_Err_Code_T error             = XCP_ERR_CMD_SYNCH_CPV;
   uint8_t **xcp_checksum_ptr       = xcp_input_ptr->xcp_checksum_ptr;
   uint8_t **xcp_cust_checksum_ptr  = xcp_input_ptr->xcp_cust_checksum_ptr;
   uint8_t xcp_num_cust_spec_chcksm = xcp_input_ptr->xcp_num_cust_spec_chcksm;
   uint8_t checksum_cnt             = 0U;
   uint8_t index                    = 2U;

   checksum_cnt = (uint8_t)XCP_MAX_CHKSM;
   error        = Copy_Checksum_To_Response(response, xcp_checksum_ptr, index, checksum_cnt);

   if ((0U != xcp_num_cust_spec_chcksm) && (xcp_num_cust_spec_chcksm < ((uint8_t)XCP_MAX_CUST_CHKSM)))
   {
      index += ((uint8_t)(4 * checksum_cnt)); /*  sizeof(each checksum) = 4; */
      checksum_cnt = xcp_num_cust_spec_chcksm;
      error        = Copy_Checksum_To_Response(response, xcp_cust_checksum_ptr, index, checksum_cnt);
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   {
      response[0] = XCP_POSITIVE_RESPONSE_CPV;
      response[1] = XCP_USER_CMD_GET_CHECKSUM_RESULTS;
      /* response already filled */
      *framelength = DATA_BYTES_LEN;
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }

   return (ret_value);
}

/**
 * FUNCTION:XCP_User_Cmd_Read_Write_DID
 *. This function implements xcp command to read or write the DID
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-
 *
 * SRD
 * WorkItem 1 : WI-307985
 * WorkItem 2 : WI-307983
 * WorkItem 3 : WI-307984
 * WorkItem 3 : WI-307986
 * \\input{XCP_User_Cmd_Read_Write_DID}
 */
static uint8_t XCP_User_Cmd_Read_Write_DID(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd, uint8_t *response,
                                           uint8_t *framelength)
{
   uint8_t ret_value                      = XCP_CMD_OK_CPV;
   XCP_Err_Code_T error                   = XCP_ERR_CMD_SYNCH_CPV;
   XCP_DID_Data_Cmd_T *xcp_input_did_ptr  = (XCP_DID_Data_Cmd_T *)xcp_input_ptr->xcp_input_did_ptr;
   XCP_DID_Data_Cmd_T *xcp_output_did_ptr = (XCP_DID_Data_Cmd_T *)xcp_input_ptr->xcp_output_did_ptr;
   uint8_t *xcp_did_cmd_recvd             = xcp_input_ptr->xcp_did_recvd_ptr;
   uint8_t xcp_length                     = 0;
   uint8_t index                          = 0;
   const void *did_ptr_list[] = {(const void *)xcp_input_did_ptr, (const void *)xcp_output_did_ptr}; /* NULL pointer check */

   if ((Get_XCP_Pending_Cmnd_Status() != CODED_FALSE) || /* check if any pending command is in progress */
       (!NULL_PTR_CHECK(did_ptr_list)) ||                /* check for null pointer */
       (!XCP_RANGE_CHECK(cmnd[2], XCP_DID_MINIMUM_LENGTH, XCP_DID_MAXIMUM_LENGTH)) || /* check for valid length of command */
       !((cmnd[3] == XCP_DID_READ_DATA) || (cmnd[3] == XCP_DID_WRITE_DATA)))          /* check for valid service id */
   { /* negative response, if any of the above check fails */
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }
   else
   { /* Update the global variable with received DID command details to be used in the periodic task */
      /* service id */
      XCP_DID_Cmd.service_id        = cmnd[3];
      XCP_DID_Cmd.DID               = (uint16_t)(((uint16_t)cmnd[4] << 8) | (cmnd[5]));
      xcp_input_did_ptr->service_id = cmnd[3];
      xcp_input_did_ptr->DID        = XCP_DID_Cmd.DID;
      /* length of data */
      xcp_length = (uint8_t)(cmnd[2] - 3U);

      for (index = 0; index < xcp_length; index++)
      {
         xcp_input_did_ptr->Data[index] = cmnd[XCP_SUB_CMD_VAL_6 + index];
      }

      *xcp_did_cmd_recvd = CODED_TRUE;
      Set_XCP_Periodic_User_Cmd(cmnd[1], XCP_WRITE_DID_TIMEOUT, &XCP_DID_Periodic_Task);
      ret_value = XCP_CMD_PENDING_CPV;
   }
   if (XCP_ERR_CMD_SYNCH_CPV == error)
   {
      /* update in the timer for write sequence */
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error); /* negative response */
                                                                 /* clear the global variable as command is not accepted */
   }

   return (ret_value);
}

/**
 * FUNCTION:xcp_user_cmd_read_write_data_identifier
 *. This function implements xcp command to update the response
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-
 *
 * SRD
 * WorkItem 1 : WI-307985
 * WorkItem 2 : WI-307983
 * WorkItem 3 : WI-307984
 * WorkItem 3 : WI-307986
 * \\input{XCP_Write_DID_Periodic_Task}
 */
static uint8_t XCP_DID_Periodic_Task(XCP_BB_Input_Params_T *const xcp_input_ptr, uint8_t *response, uint8_t *framelength)
{
   uint8_t data_idx          = 0U;
   uint8_t resp_idx          = 0U;
   uint8_t ret_val           = XCP_CMD_PENDING_CPV;
   uint8_t xcp_out_serviceID = 0U;
   uint16_t xcp_out_DID      = 0U;

   XCP_DID_Data_Cmd_T *xcp_output_did_ptr = (XCP_DID_Data_Cmd_T *)xcp_input_ptr->xcp_output_did_ptr;

   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt++;

   if (Is_Cycle_Cnt_Valid)
   {
      if (XCP_DID_READ_DATA == XCP_DID_Cmd.service_id)
      {
         xcp_out_serviceID = xcp_output_did_ptr->service_id;
         xcp_out_DID       = xcp_output_did_ptr->DID;

         if ((xcp_out_serviceID == XCP_DID_Cmd.service_id) && (xcp_out_DID == XCP_DID_Cmd.DID))
         {
            resp_idx = 0U;
            /* Update the positive response */
            response[resp_idx++] = XCP_POSITIVE_RESPONSE_CPV;
            response[resp_idx++] = XCP_USER_CMD_READ_WRITE_DID;
            response[resp_idx++] = (uint8_t)(DATA_BYTES_LEN - 3U); /* response, cmd, length */
            response[resp_idx++] = (uint8_t)(XCP_DID_READ_DATA + XCP_DID_READ_DATA_OFFSET);
            /*DID */
            response[resp_idx++] = GET_BYTE(XCP_DID_Cmd.DID, 1U);
            response[resp_idx++] = GET_BYTE(XCP_DID_Cmd.DID, 0U);

            for (data_idx = 0U; resp_idx < DATA_BYTES_LEN; data_idx++)
            {
               response[resp_idx++] = xcp_output_did_ptr->Data[data_idx];
            }

            *framelength = resp_idx; /* DATA_BYTES_LEN */
            ret_val      = XCP_CMD_OK_CPV;

            XCP_DID_Cmd.service_id = 0U;
            XCP_DID_Cmd.DID        = 0U;

            /* clear periodic user command */
            Set_XCP_Periodic_User_Cmd(0U, 0U, NULL);
         }
      }
      else if (XCP_DID_WRITE_DATA == XCP_DID_Cmd.service_id)
      {
         xcp_out_serviceID = xcp_output_did_ptr->service_id;
         xcp_out_DID       = xcp_output_did_ptr->DID;

         if ((xcp_out_serviceID == XCP_DID_Cmd.service_id) && (xcp_out_DID == XCP_DID_Cmd.DID))
         {
            resp_idx = 0U;
            /* Update the positive response */
            response[resp_idx++] = XCP_POSITIVE_RESPONSE_CPV;
            response[resp_idx++] = XCP_USER_CMD_READ_WRITE_DID;
            response[resp_idx++] = 3U;
            response[resp_idx++] = (uint8_t)(XCP_DID_WRITE_DATA + 0x40U);
            response[resp_idx++] = GET_BYTE(XCP_DID_Cmd.DID, 1U);
            response[resp_idx++] = GET_BYTE(XCP_DID_Cmd.DID, 0U);

            *framelength = resp_idx;

            ret_val = XCP_CMD_OK_CPV;

            XCP_DID_Cmd.service_id = 0U;
            XCP_DID_Cmd.DID        = 0U;

            /* clear periodic user command */
            Set_XCP_Periodic_User_Cmd(0U, 0U, NULL);
         }
      }
      else
      {
         /* Do Nothing */
      }
   }
   else
   {
      /* Update the negative response */
      *framelength = Prepare_Negative_Response(response, XCP_ERR_GENERIC_CPV);

      ret_val = XCP_CMD_OK_CPV;

      XCP_DID_Cmd.service_id = 0U;
      XCP_DID_Cmd.DID        = 0U;

      /* clear periodic user command */
      Set_XCP_Periodic_User_Cmd(0U, 0U, NULL);
   }

   return (ret_val);
}

/**
 * FUNCTION:XCP_User_Cmd_Phase_Rotator_Calibration
 *. This function implements to enable/disable the phase rotator calibration
 *
 * \param[in] const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-
 *
 * SRD
 * WorkItem 1 : WI-411094
 * WorkItem 2 : WI_411905
 * \\input{XCP_User_Cmd_Phase_Rotator_Calibration}
 */
static uint8_t XCP_User_Cmd_Phase_Rotator_Calibration(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd,
                                                      uint8_t *response, uint8_t *framelength)
{
   uint8_t temp;
   uint8_t ret_value    = XCP_CMD_OK_CPV;
   XCP_Err_Code_T error = XCP_ERR_CMD_SYNCH_CPV;

   Xcp_Phase_Rotator_fptr_T xcp_phase_rotator_fptr = xcp_input_ptr->xcp_phase_rotator_calib_fptr;

   if ((xcp_phase_rotator_fptr != NULL) && (XCP_RANGE_CHECK(cmnd[2], 0x01U, 0x02U)))
   {
      temp = (uint8_t)(cmnd[2] - 1U);
      /* if cmd[2] value 1 = enable
            cmd[2] value 2 = disable
            parameter should be pass as (cmd[2] -1 )*/
      xcp_phase_rotator_fptr(temp);
   }
   else
   {
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   {
      response[0]  = XCP_POSITIVE_RESPONSE_CPV;
      response[1]  = XCP_USER_CMD_PHASE_ROTATOR_CALIBRATION;
      response[2]  = cmnd[2];
      *framelength = 3;
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }

   return (ret_value);
}

/**
 * FUNCTION:XCP_User_Cmd_Radar_Transceiver_Calibration
 * This function implements xcp command to trigger and get calibration status
 * Command: XCP_USER_CMD_RADAR_TRANSCEIVER_CALIBRATION (F1 99)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-293026
 *
 * SRD
 * WorkItem 1 : WI-268201
 * WorkItem 2 : WI-292951
 * WorkItem 3 : WI-292952
 * \\input{XCP_User_Cmd_Radar_Transceiver_Calibration}
 */
static uint8_t XCP_User_Cmd_Radar_Transceiver_Calibration(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd,
                                                          uint8_t *response, uint8_t *framelength)
{
   XCP_Err_Code_T error                           = XCP_ERR_CMD_SYNCH_CPV;
   volatile uint8_t *xcp_trigger_rfbist_calib_ptr = xcp_input_ptr->xcp_trigger_rfbist_calib_ptr;
   uint8_t xcp_rfbist_status                      = xcp_input_ptr->xcp_get_rfbist_calib_status;
   xcp_rfbist_debugdata_ptr xcp_rfbist_debug_fptr = xcp_input_ptr->xcp_rfbist_debug_data_fptr;
   uint32_t *debug_data_ptr                       = NULL;
   XCP_RFBIST_Debug_Data_T *debug_info            = NULL;
   uint8_t resp_idx                               = 0U;
   uint8_t index                                  = 0U;

   if ((XCP_MMIC_DEVICE_1 == cmnd[2]))
   {
      if (XCP_RFBIST_CALIB == cmnd[3])
      {
         switch (cmnd[4])
         {
            case XCP_TRIGGER_RFBIST_CALIB:
               *xcp_trigger_rfbist_calib_ptr = cmnd[4];
               *framelength                  = 5U;
               break;
            case XCP_GET_CALIB_STATUS:
               response[5U] = xcp_rfbist_status;
               *framelength = 6U;
               break;
            default:
               error = XCP_ERR_OUT_OF_RANGE_CPV;
               break;
         }
      }
      else if ((XCP_RFBIST_DEBUG == cmnd[3]) &&
               (XCP_RANGE_CHECK(cmnd[4], XCP_RFBIST_DEBUG_DATA_SUBCMD_START, XCP_RFBIST_DEBUG_DATA_SUBCMD_END)))
      {
         debug_info = xcp_rfbist_debug_fptr(cmnd[4] - 1U);
         if (debug_info != NULL)
         {
            debug_data_ptr = (uint32_t *)debug_info->xcp_rfbist_debug_data_ptr;
         }
         resp_idx = 0x05U;
         if (debug_data_ptr != NULL)
         {
            for (index = 0; index < debug_info->xcp_debug_no_of_parameter; index++)
            {
               response[resp_idx++] = GET_BYTE(*debug_data_ptr, 3U);
               response[resp_idx++] = GET_BYTE(*debug_data_ptr, 2U);
               response[resp_idx++] = GET_BYTE(*debug_data_ptr, 1U);
               response[resp_idx++] = GET_BYTE(*debug_data_ptr, 0U);
               debug_data_ptr++;
            }
            *framelength = resp_idx;
         }
         else
         {
            error = XCP_ERR_OUT_OF_RANGE_CPV;
         }
      }
      else
      {
         error = XCP_ERR_OUT_OF_RANGE_CPV;
      }
   }
   else
   {
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   {
      response[0] = XCP_POSITIVE_RESPONSE_CPV;
      response[1] = cmnd[1];
      response[2] = cmnd[2];
      response[3] = cmnd[3];
      response[4] = cmnd[4];
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }
   return (XCP_CMD_OK_CPV);
}

#if COMMENTED

/**
 * FUNCTION:xcp_user_cmd_interface_control
 * This function implements xcp command to enable and disable transmitter ON and OFF.
 * Command: XCP_USER_CMD_INTERFACE_CONTROL (F1 10)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-278094
 *
 * SRD
 * WorkItem 1 : WI- 277845
 * WorkItem 2 : WI- 287929
 * WorkItem 3 : WI- 287930
 * WorkItem 4 : WI- 288000
 * \\input{xcp_user_cmd_interface_control}
 */
static uint8_t xcp_user_cmd_interface_control(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd, uint8_t *response,
                                              uint8_t *framelength)
{
   uint8_t temp;
   XCP_Err_Code_T error             = XCP_ERR_CMD_SYNCH_CPV;
   uint8_t **xcp_interface_ctrl_ptr = xcp_input_ptr->xcp_interface_cntrl_ptr;

   if ((XCP_RANGE_CHECK(cmnd[2], (uint8_t)XCP_PCAN_INTERFACE, (uint8_t)XCP_ETHERNET_INTERFACE)) &&
       (XCP_RANGE_CHECK(cmnd[3], (uint8_t)XCP_INTERFACE_DISABLE, (uint8_t)XCP_INTERFACE_ENABLE)))
   {
      temp = (uint8_t)(cmnd[2] - 1U);
      if (xcp_interface_ctrl_ptr[temp] != NULL)
      {
         *xcp_interface_ctrl_ptr[temp] = cmnd[3];
      }
      else
      {
         error = XCP_ERR_OUT_OF_RANGE_CPV;
      }
   }
   else
   {
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   {
      resp_index             = 0U;
      response[resp_index++] = XCP_POSITIVE_RESPONSE_CPV;
      response[resp_index++] = cmnd[1];
      response[resp_index++] = cmnd[2]; /* interface */
      response[resp_index++] = cmnd[3]; /* interface enable or disable*/
      *framelength           = resp_index;
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }

   return (XCP_CMD_OK_CPV);
}

/**
 * FUNCTION:xcp_user_cmd_hil_mode
 * This function enables or disables HIL mode of operation
 * Command:  XCP_USER_CMD_HIL_MODE (F1 50)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-291280
 *
 * SRD
 * WorkItem 1 : WI-291274
 * WorkItem 2 : WI_291281
 * WorkItem 3 : WI-291273
 * \\input{xcp_user_cmd_hil_mode}
 */
static uint8_t xcp_user_cmd_hil_mode(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd, uint8_t *response,
                                     uint8_t *framelength)
{
   XCP_Err_Code_T error      = XCP_ERR_CMD_SYNCH_CPV;
   uint8_t *xcp_hil_mode_ptr = xcp_input_ptr->xcp_hil_mode_ptr;

   if ((xcp_hil_mode_ptr != NULL) && (XCP_RANGE_CHECK(cmnd[2], XCP_HIL_ENABLE, XCP_HIL_DISABLE)))
   {
      if ((uint8_t)XCP_HIL_ENABLE == cmnd[2])
      {
         *xcp_hil_mode_ptr = CODED_TRUE;
      }
      else
      {
         *xcp_hil_mode_ptr = CODED_FALSE;
      }
   }
   else
   {
      error = XCP_ERR_CMD_SYNTAX_CPV; /* XCP_ERR_OUT_OF_RANGE_CPV */
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   {
      resp_index             = 0U;
      response[resp_index++] = XCP_POSITIVE_RESPONSE_CPV;
      response[resp_index++] = cmnd[1];
      response[resp_index++] = cmnd[2];
      *framelength           = resp_index;
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }
   return (XCP_CMD_OK_CPV);
}

/*
 * FUNCTION:XCP_Chksum_Updation_Periodic_Task
 * This function implements to update the positive or negative resonse
 * This periodic function is being utilized by xcp_user_cmd_get_checksum_results (F1 85)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 *
 * SRD
 * WorkItem 1 : WI-307720
 * WorkItem 2 : WI_307724
 * WorkItem 3 : WI_307732
 * \\input{XCP_JTAG_PWD_Periodic_Task}
 */
static uint8_t XCP_Chksum_Updation_Periodic_Task(XCP_BB_Input_Params_T *const xcp_input_ptr, uint8_t *response,
                                                 uint8_t *framelength)
{
   uint8_t ret_value                = XCP_CMD_OK_CPV;
   XCP_Err_Code_T error             = XCP_ERR_CMD_SYNCH_CPV;
   uint8_t **xcp_checksum_ptr       = xcp_input_ptr->xcp_checksum_ptr;
   uint8_t **xcp_cust_checksum_ptr  = xcp_input_ptr->xcp_cust_checksum_ptr;
   uint8_t xcp_num_cust_spec_chcksm = xcp_input_ptr->xcp_num_cust_spec_chcksm;

   uint8_t checksum_cnt = 0U;
   uint8_t index        = 2U;

   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt++;

   if (Is_Cycle_Cnt_Valid)
   {
      checksum_cnt = (uint8_t)XCP_MAX_CHKSM;
      error        = Copy_Checksum_To_Response(response, xcp_checksum_ptr, index, checksum_cnt);

      if ((0U != xcp_num_cust_spec_chcksm) && (xcp_num_cust_spec_chcksm < ((uint8_t)XCP_MAX_CUST_CHKSM)))
      {
         index += ((uint8_t)(4 * checksum_cnt)); /*  sizeof(each checksum) = 4; */
         checksum_cnt = xcp_num_cust_spec_chcksm;
         error        = Copy_Checksum_To_Response(response, xcp_cust_checksum_ptr, index, checksum_cnt);
      }
   }
   else
   {
      error = XCP_ERR_OUT_OF_RANGE_CPV;
   }

   if (XCP_ERR_CMD_SYNCH_CPV == error)
   {
      response[0]  = XCP_POSITIVE_RESPONSE_CPV;
      response[1]  = XCP_USER_CMD_GET_CHECKSUM_RESULTS;
      *framelength = DATA_BYTES_LEN;

      /* reset periodic user command */
      Set_XCP_Periodic_User_Cmd(0U, 0U, NULL);
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);

      /* reset periodic user command */
      Set_XCP_Periodic_User_Cmd(0U, 0U, NULL);
   }

   return (ret_value);
}
/**
 * FUNCTION:xcp_user_cmd_read_electronic_chipid
 * This function reads electronic chip id
 * Command:  XCP_USER_CMD_READ_ELECTRONIC_CHIPID (F1 96)
 *
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 *
 * SRD
 * WorkItem 1 :
 * WorkItem 2 :
 * \\input{xcp_user_cmd_read_electronic_chipid}
 */
static uint8_t xcp_user_cmd_read_electronic_chipid(XCP_BB_Input_Params_T *const xcp_input_ptr, const uint8_t *cmnd,
                                                   uint8_t *response, uint8_t *framelength)
{
   XCP_Err_Code_T error                           = XCP_ERR_CMD_SYNCH_CPV;
   XCP_Electronic_Chip_Id_fptr_T xcp_interface_id = xcp_input_ptr->xcp_elec_chip_if_id_fptr;
   uint8_t *xcp_read_electronic_chipid            = NULL;
   uint8_t electronic_chip_id_max                 = xcp_input_ptr->xcp_electronic_chip_id_max;

   if ((xcp_interface_id != NULL) && (cmnd[2U] <= electronic_chip_id_max))
   {
      xcp_read_electronic_chipid = (*xcp_interface_id)(cmnd[2U]);
   }
   else
   {
      error = XCP_ERR_CMD_SYNTAX_CPV;
   }

   if ((XCP_ERR_CMD_SYNCH_CPV == error) && (xcp_read_electronic_chipid != NULL))
   {
      memcpy(&response[2], xcp_read_electronic_chipid, 62U);
      response[0]  = XCP_POSITIVE_RESPONSE_CPV;
      response[1]  = cmnd[1];
      *framelength = DATA_BYTES_LEN;
   }
   else
   {
      *framelength = Prepare_Negative_Response(response, error);
   }
   return (XCP_CMD_OK_CPV);
}
#endif

/**
 * FUNCTION:XCP_User_Command
 * This function implements xcp user commands sent to the Program
 * \param[in] XCP_BB_Input_Params_T *const xcp_input_ptr,  const uint8_t* cmnd, uint8_t* response, uint8_t* framelength
 *
 * \return uint8_t
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
 * WorkItem 1 : WI-306246
 *
 * SRD
 * WorkItem 1 : WI-306245
 * \\input{XCP_User_Command}
 */
uint8_t XCP_User_Command(const uint8_t *cmnd, uint8_t *response, uint8_t *framelength)
{
   uint8_t index;
   uint8_t ret_value;

   memset(response, 0, 64U);

   index = Get_XCP_User_Cmd_Index(cmnd[1U]);

   if (index < MAX_XCP_USER_CMD)
   { /* call the corresponding function */
      ret_value = XCP_User_Cmd_Func_List[index](XCP_BB_Input_Params_Ptr, cmnd, response, framelength);
   }
   else
   {
      ret_value = XCP_CMD_SYNTAX_CPV;
   }

   return (ret_value);
}

/*****************************************************************************
 *. Name: Get_XCP_Pending_Cmnd_Status()
 *. This periodic function is being utilized by xcp_user_cmd_get_checksum_results, Get_Analog_Inputs,
    xcp_user_cmd_get_radar_target, xcp_user_cmd_set_override_control_variable and Get_Filtered_Analog_Inputs
 *. Shared Variables: void
 *.
 *. Parameters:
 *.
 *. Return Value: uint8_t
 *. Design Information:
 *. Traces to:
 *.
 *. JIRA/Plastic Task:
 *.            Section :
 *****************************************************************************/
uint8_t Get_XCP_Pending_Cmnd_Status(void)
{
   uint8_t status = XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd;
   return (status);
}

/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 * Date        userid    (Description on following lines: SCR #, etc.)
 * ----------- --------
 * 10-Aug-2024 alkjpl   DNP-3434: Bringing Inital commands to  Gen 8.
 * 04-Sep-2024 alkjpl   DNP-4983: Bringing Up ADC commands (F1 A0/A1/A2/A3)
 * 24-Oct-2024 alkjpl   DNP-5466: Bringing Up of F1 0B
 * 21-Mar-2025 hzgbb0   CUW-4299: Replace a few fixed-point macros that aren't present in reuse BB
 *
 *===========================================================================*/
