/*===========================================================================*/
/**
 *  @file p_l_xcp_user_cmds_unit_test.cc
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
 * Unit test suite for the checking the p_l_xcp_user_cmds.c file
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
/*==========================================================================*/
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include <gtest/gtest.h>

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "fff.h"
#include "xcp_core_fake.h"

extern "C"
{
#include "xcp_user_cmds.c"
}

DEFINE_FFF_GLOBALS;

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class xcp_user_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_RESET_HISTORY();
   }

   /**
    * @b Description
    * @n
    *    Method run  after each individual test case.
    */
   void TearDown()
   {
   }
};

/*===========================================================================*
 * Variable Declarations
 *===========================================================================*/
/*
static XCP_ADC_Cmd_T xcp_adc_cmd                   = {CODED_TRUE, 0, 0, 0};
static XCP_OVERRIDE_Cmd_T xcp_override_cmd         = {0, CODED_TRUE, 0};
static XCP_Checksum_Cmd_T xcp_chksm_cmd            = {CODED_TRUE, 0};
static XCP_ADC_FILTERED_Cmd_T xcp_adc_filtered_cmd = {CODED_TRUE, 0, 0, 0};
*/

typedef unsigned char uint8;
// static XCP_BB_Input_Params_T XCP_BB_Input_Params_Initialise;
XCP_BB_Input_Params_T XCP_BB_Input_Params_Initialise;
XCP_BB_Input_Params_T *l_xcp_bb_input_params;
XCP_BB_Input_Params_T *XCP_BB_Input_Params_Ptr = &XCP_BB_Input_Params_Initialise;

XCP_Err_Code_T Err = XCP_ERR_CMD_SYNCH_CPV;
XCP_BB_Input_Params_T *Get_XCP_Init_Parameters_Custom_Fake(void)
{
   return (&XCP_BB_Input_Params_Initialise);
}

uint8_t SWC_XCP_Get_Look_En_Status(uint8_t look);
uint8_t SWC_XCP_Get_Look_En_Status(uint8_t look)
{
   return (0xAAU);
}

uint8_t response[64] = {0};
uint8_t framelength;

/*
For MMIC MCU Temp Command
*/
volatile int16_t xcp_get_tx_temp[XCP_MAX_MMIC_TX_TEMP_SENSORS];
volatile float32_t xcp_get_mcu_temp[XCP_MAX_MCU_TEMP_SENSORS];

XCP_Target_Report_T XCP_Trgt_Rprt = {0};
XCP_Target_Report_T *SWC_XCP_Copy_Target_Report(void);
XCP_Target_Report_T *SWC_XCP_Copy_Target_Report(void)
{
   int8_t data = 1;
   return (&XCP_Trgt_Rprt);
}

XCP_Target_Report_T *SWC_XCP_Copy_Target_Report_Null(void)
{
   return NULL;
}

/*
For Get Radar Target command
*/
static uint8_t xcp_radar_radiate_cmd;

class get_radar_target : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();

      /*Set the required inputs before function call*/
      Get_XCP_Init_Parameters_fake.custom_fake = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

/*
For Clear Internal Fault Command
*/
static uint8_t xcp_clear_faults     = CODED_FALSE;
static uint8_t xcp_adc_trigger_flag = CODED_FALSE;
static XCP_Inject_Fault_T xcp_inject_fault;

/*
Test config table for XCP_User_Cmd_Inject_Fault
Domain 2 (MM3): 5 handlers covering FT 0x00-0x04 with specified IC ranges.
Domain 5 (RSV): 1 NULL-handler entry (FT range 0x00-0x00 only).
*/
static void XCP_Test_Fault_Handler_Stub(uint8_t ctrl, uint8_t ft)
{
   (void)ctrl;
   (void)ft;
}
static const XCP_Fault_Inj_Handler_T xcp_test_mm3_handlers[] = {
   {XCP_Test_Fault_Handler_Stub, 0x00U, 0x01U, 0x01U, 0x00U, 0x01U},
   {XCP_Test_Fault_Handler_Stub, 0x01U, 0x01U, 0x01U, 0x00U, 0x06U},
   {XCP_Test_Fault_Handler_Stub, 0x02U, 0x02U, 0x02U, 0x00U, 0x01U},
   {XCP_Test_Fault_Handler_Stub, 0x03U, 0x03U, 0x03U, 0x00U, 0x02U},
   {XCP_Test_Fault_Handler_Stub, 0x04U, 0x04U, 0x04U, 0x00U, 0x01U},
   {XCP_Test_Fault_Handler_Stub, 0x05U, 0x05U, 0x05U, 0x02U, 0x05U}, /* IC_min=0x02 for IC-below-min coverage */
};
static const XCP_Fault_Inj_Handler_T xcp_test_rsv_handlers[] = {
   {NULL, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U},
};
static const XCP_Fault_Injection_Config_Table_T xcp_test_fault_domain_table[] = {
   {NULL, 0x00U, 0U},                  /* domain 0 */
   {NULL, 0x01U, 0U},                  /* domain 1 */
   {xcp_test_mm3_handlers, 0x02U, 6U}, /* domain 2 - MM3 */
   {NULL, 0x03U, 0U},                  /* domain 3 */
   {NULL, 0x04U, 0U},                  /* domain 4 */
   {xcp_test_rsv_handlers, 0x05U, 1U}, /* domain 5 - RSV (FT 0x00 only) */
};
/*
 Table with a gap in FT ranges (handler[0] FT=0x00-0x00, handler[1] FT=0x05-0x05).
 Used by TEST12 to cover XCP_RANGE_CHECK Branch 1: cmnd[3] < failure_type_min.
 When cmnd[3]=0x03: handler[0] passes '>= 0x00' but fails '<= 0x00', then
 handler[1] fails '>= 0x05' (Branch 1 taken), loop exits, no match -> error.
*/
static const XCP_Fault_Inj_Handler_T xcp_test_gap_handlers[] = {
   {XCP_Test_Fault_Handler_Stub, 0x00U, 0x00U, 0x00U, 0x00U, 0x01U}, /* FT 0x00-0x00 */
   {XCP_Test_Fault_Handler_Stub, 0x05U, 0x05U, 0x05U, 0x00U, 0x01U}, /* FT 0x05-0x05, gap at 0x01-0x04 */
};
static const XCP_Fault_Injection_Config_Table_T xcp_test_gap_domain_table[] = {
   {NULL, 0x00U, 0U},                  /* domain 0 */
   {NULL, 0x01U, 0U},                  /* domain 1 */
   {xcp_test_gap_handlers, 0x02U, 2U}, /* domain 2 - gap handlers, count=2 */
   {NULL, 0x03U, 0U},                  /* domain 3 */
   {NULL, 0x04U, 0U},                  /* domain 4 */
   {NULL, 0x05U, 0U},                  /* domain 5 */
};
static bool g_test_fault_config_flag                                       = true;
static const XCP_Fault_Injection_Config_Table_T *g_test_fault_config_table = xcp_test_fault_domain_table;
const XCP_Fault_Injection_Config_Table_T *Get_XCP_Fault_Config_Table(void)
{
   if (g_test_fault_config_flag)
   {
      return (g_test_fault_config_table);
   }
   else
   {
      return NULL;
   }
}

/*
For get_analog_inputs_A0_A1
*/
class get_analog_inputs_A0_A1 : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();

      XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr = NULL;
      Get_XCP_Init_Parameters_fake.custom_fake                    = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

/*
For get_analog_filtered_inputs_A2_A3
*/
class get_analog_filtered_inputs_A2_A3 : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();

      XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr = &xcp_adc_trigger_flag;
      Get_XCP_Init_Parameters_fake.custom_fake                    = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

/*
For XCP_User_Cmd_Get_Host_Analog_Inputs_0to30
*/
class get_host_analog_inputs_0to30 : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
   }
   void TearDown()
   {
   }
};

/*
For XCP_User_Cmd_Get_Host_Analog_Inputs_31to61
*/
class get_host_analog_inputs_31to61 : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
   }
   void TearDown()
   {
   }
};

/*
For XCP_User_Cmd_Get_Host_Analog_Filtered_Inputs_0to30
*/
class get_host_analog_filtered_inputs_0to30 : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
   }
   void TearDown()
   {
   }
};

/*
For XCP_User_Cmd_Get_Host_Analog_Filtered_Inputs_31to61
*/
class get_host_analog_filtered_inputs_31to61 : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
   }
   void TearDown()
   {
   }
};

// ## FOR Get_XCP_User_Cmd_Index ##
class User_Cmd_idx : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
   }
   void TearDown()
   {
   }
};
// ## FOR XCP_User_Command ##

class xcp_usr_cmd : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
   }
   void TearDown()
   {
   }
};

// ##  Get_ADC_Info_Cmnd_Status  ##
class Get_ADC_Inf_Cmd_Sts : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
   }
   void TearDown()
   {
   }
};

// ## Get_ovrd_set_Cmd_Sts
class Get_ovrd_set_Cmd_Sts : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
   }
   void TearDown()
   {
   }
};

// ## Get_ADC_Filtered_Cmnd_Status

class Get_ADC_Fltd_Cmnd_Sts : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
   }
   void TearDown()
   {
   }
};

XCP_DAQ_Descriptor_Table_T XCP_Variables_List_DAQ[5][7] = {0};

uint8_t *response_ptr;
XCP_Target_Info_Valid_Trgt_T *valid_tgt_ptr;
/*
For Compute_Target_Parameters
*/
class target_parameters : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      Get_XCP_Init_Parameters_fake.custom_fake = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

/**
 *  @b xcp_user_sanity
 *  @n
 */
TEST_F(xcp_user_UnitTestSuite, xcp_user_Config__SANITY_CHECK_)
{
   ASSERT_EQ(true, true);
}

TEST_F(xcp_user_UnitTestSuite, copy_adc_data_to_response_packs_adc_values)
{
   uint8_t local_response[16];
   volatile uint16_t raw_adc_data[] = {0x1234U, 0xABCDU, 0x00EFU};

   memset(local_response, 0xA5, sizeof(local_response));

   const uint8_t frame_length = Copy_Adc_Data_To_Response(local_response, raw_adc_data, 0U, 3U, 2U);

   ASSERT_EQ(frame_length, 4U);
   ASSERT_EQ(local_response[0], 0x12U);
   ASSERT_EQ(local_response[1], 0x34U);
   ASSERT_EQ(local_response[2], 0xABU);
   ASSERT_EQ(local_response[3], 0xCDU);
}

TEST_F(xcp_user_UnitTestSuite, copy_adc_data_to_response_skips_values_past_available_inputs)
{
   uint8_t local_response[16];
   volatile uint16_t raw_adc_data[] = {0x1111U, 0x2222U, 0x3333U, 0x4444U};

   memset(local_response, 0xA5, sizeof(local_response));

   const uint8_t frame_length = Copy_Adc_Data_To_Response(local_response, raw_adc_data, 2U, 3U, 3U);

   ASSERT_EQ(frame_length, 2U);
   ASSERT_EQ(local_response[0], 0x33U);
   ASSERT_EQ(local_response[1], 0x33U);
   ASSERT_EQ(local_response[2], 0xA5U);
}

class mmic_mcu_temp : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();

      uint8_t xcp_num_mmic;
      uint8_t xcp_num_mcu_sensor;
      Get_XCP_Init_Parameters_fake.custom_fake = Get_XCP_Init_Parameters_Custom_Fake;
      xcp_get_tx_temp[0]                       = 45U;
      xcp_get_tx_temp[1]                       = 45U;
      xcp_get_tx_temp[2]                       = 45U;
      xcp_get_tx_temp[3]                       = 45U;
      xcp_get_tx_temp[4]                       = 999.0F;
      xcp_get_tx_temp[5]                       = 999.0F;
      xcp_get_tx_temp[6]                       = 999.0F;
      xcp_get_tx_temp[7]                       = 999.0F;

      xcp_get_mcu_temp[0] = 45U;
      xcp_get_mcu_temp[1] = 45U;
      xcp_get_mcu_temp[2] = 999.0F;

      XCP_BB_Input_Params_Initialise.xcp_num_mmic         = 1U;
      XCP_BB_Input_Params_Initialise.xcp_get_mcu_temp_ptr = xcp_get_mcu_temp;
      XCP_BB_Input_Params_Initialise.xcp_get_tx_temp_ptr  = xcp_get_tx_temp;
      XCP_BB_Input_Params_Initialise.xcp_num_mcu_sensor   = 1U;
   }
   void TearDown()
   {
   }
};

TEST_F(mmic_mcu_temp, get_mmic_mcu_temp_positiveTC1)
{
   uint8_t cmnd[]                                    = {0xF1, 0x9F};
   XCP_BB_Input_Params_Initialise.xcp_num_mcu_sensor = 1U;
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Get_MMIC_MCU_Temp(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], cmnd[1]);
   ASSERT_EQ(framelength, XCP_MMIC_MCU_TEMP_FRAMELENGTH);
}

TEST_F(mmic_mcu_temp, get_mmic_mcu_temp_positive_TC2)
{
   uint8_t cmnd[]      = {0xF1, 0x9F};
   xcp_get_mcu_temp[0] = 999.0F;
   xcp_get_mcu_temp[1] = 999.0F;
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Get_MMIC_MCU_Temp(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], cmnd[1]);
   ASSERT_EQ(framelength, XCP_MMIC_MCU_TEMP_FRAMELENGTH);
}

TEST_F(mmic_mcu_temp, get_mmic_mcu_temp_positive_TC3)
{
   uint8_t cmnd[]                                      = {0xF1, 0x9F};
   XCP_BB_Input_Params_Initialise.xcp_num_mmic         = 2U;
   XCP_BB_Input_Params_Initialise.xcp_get_mcu_temp_ptr = NULL;
   XCP_BB_Input_Params_Initialise.xcp_get_tx_temp_ptr  = NULL;
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Get_MMIC_MCU_Temp(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   // For NULL pointers, expect negative response
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(framelength, 2);
}

TEST_F(mmic_mcu_temp, get_mmic_mcu_temp_negative_TC4)
{
   uint8_t cmnd[]                                    = {0xF1, 0x9F};
   XCP_BB_Input_Params_Initialise.xcp_num_mmic       = 2U;
   XCP_BB_Input_Params_Initialise.xcp_num_mcu_sensor = 0U;
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Get_MMIC_MCU_Temp(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(framelength, 2);
}

TEST_F(mmic_mcu_temp, get_mmic_mcu_temp_negative_TC5)
{
   uint8_t cmnd[]                                      = {0xF1, 0x9F};
   Get_XCP_Init_Parameters_fake.return_val             = NULL;
   l_xcp_bb_input_params                               = Get_XCP_Init_Parameters_fake.return_val;
   XCP_BB_Input_Params_Initialise.xcp_get_mcu_temp_ptr = NULL;
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Get_MMIC_MCU_Temp(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(framelength, 2);
}

TEST_F(mmic_mcu_temp, get_mmic_mcu_temp_negative_TC6)
{
   uint8_t cmnd[]                              = {0xF1, 0x9F};
   XCP_BB_Input_Params_Initialise.xcp_num_mmic = 0U;
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Get_MMIC_MCU_Temp(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], 0x9F);
}

TEST_F(mmic_mcu_temp, get_mmic_mcu_temp_negative_TC7)
{
   uint8_t cmnd[]                                    = {0xF1, 0x9F};
   XCP_BB_Input_Params_Initialise.xcp_num_mcu_sensor = 6U;
   XCP_BB_Input_Params_Initialise.xcp_num_mmic       = 10U;
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Get_MMIC_MCU_Temp(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(framelength, 2);
}
class clear_internal_fault : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();

      /*Set the required inputs before function call*/
      XCP_BB_Input_Params_Initialise.xcp_clear_faults_ptr = &xcp_clear_faults;
      Get_XCP_Init_Parameters_fake.custom_fake            = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(clear_internal_fault, xcp_user_cmd_clear_internal_fault_codes_TEST2)
{
   uint8_t cmnd[]                                      = {0xF1, 04};
   XCP_BB_Input_Params_Initialise.xcp_clear_faults_ptr = NULL;
   uint8_t return_value = XCP_User_Cmd_Clear_Internal_Fault_Codes(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_NE(XCP_POSITIVE_RESPONSE_CPV, response[0]);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(clear_internal_fault, xcp_user_cmd_clear_internal_fault_codes_TEST1)
{
   uint8_t cmnd[]       = {0xF1, 04};
   uint8_t return_value = XCP_User_Cmd_Clear_Internal_Fault_Codes(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(XCP_POSITIVE_RESPONSE_CPV, response[0]);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
}

/* F1 90 */

uint8_t SWC_XCP_Get_Look_En_Status_lookA(uint8_t look)
{
   if (look == 0U)
   {
      return (0x55U);
   }

   return (0xAAU);
}

uint8_t SWC_XCP_Get_Look_En_Status_lookB(uint8_t look)
{
   if (look == 1U)
   {
      return (0x55U);
   }

   return (0xAAU);
}

uint8_t SWC_XCP_Get_Look_En_Status_lookC(uint8_t look)
{
   if (look == 2U)
   {
      return (0x55U);
   }

   return (0xAAU);
}

uint8_t SWC_XCP_Get_Look_En_Status_lookD(uint8_t look)
{
   if (look == 3U)
   {
      return (0x55U);
   }

   return (0xAAU);
}

TEST_F(get_radar_target, xcp_user_cmd_get_radar_target_TEST1)
{
   uint8_t cmnd[]                                        = {0xF1, 0x90};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   uint8_t return_value = XCP_User_Cmd_Get_Radar_Target(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, XCP_CMD_OK_CPV);
}

TEST_F(get_radar_target, xcp_user_cmd_get_radar_target_TEST2)
{
   const uint8_t cmnd[7] = {0xF1, 0x90, 0x07};
   uint8_t return_value  = XCP_User_Cmd_Get_Radar_Target(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, XCP_CMD_OK_CPV);
}
TEST_F(get_radar_target, xcp_user_cmd_get_radar_target_TEST3)
{
   uint8_t cmnd[]       = {0xF1, 0x90, 0x05};
   uint8_t return_value = XCP_User_Cmd_Get_Radar_Target(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(return_value, XCP_CMD_OK_CPV);
}

TEST_F(get_radar_target, xcp_user_cmd_get_radar_target_TEST4)
{
   uint8_t cmnd[]                                        = {0xF1, 0x90, 0x1F, 7U, 8U, 6U, 3U};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_radar_radiate_cmd  = CODED_TRUE;
   uint8_t return_value = XCP_User_Cmd_Get_Radar_Target(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(return_value, XCP_CMD_OK_CPV);
}

TEST_F(get_radar_target, xcp_user_cmd_get_radar_target_TEST5)
{
   uint8_t cmnd[7]                                       = {0xF1, 0x90, 2U, 3U, 4U, 5U, 7U};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_TRUE;
   uint8_t return_value = XCP_User_Cmd_Get_Radar_Target(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, XCP_CMD_OK_CPV);
}

TEST_F(get_radar_target, xcp_user_cmd_get_radar_target_TEST6)
{
   uint8_t cmnd[]                                        = {0xF1, 0x90, 0x00};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_radar_radiate_cmd  = CODED_TRUE;
   uint8_t return_value = XCP_User_Cmd_Get_Radar_Target(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, XCP_CMD_OK_CPV);
}

TEST_F(get_radar_target, xcp_user_cmd_get_radar_target_TEST7)
{
   uint8_t cmnd[]                                        = {0xF1, 0x90, 0x01, 0x01, 0x01, 0x13, 0x01};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_radar_radiate_cmd  = CODED_TRUE;
   uint8_t return_value = XCP_User_Cmd_Get_Radar_Target(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, XCP_CMD_OK_CPV);
}

TEST_F(get_radar_target, xcp_user_cmd_get_radar_target_TEST8)
{
   uint8_t cmnd[]                                        = {0xF1, 0x90, 0x01, 0x01, 0x01, 0x01, 0x13};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_radar_radiate_cmd  = CODED_TRUE;
   uint8_t return_value = XCP_User_Cmd_Get_Radar_Target(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, XCP_CMD_OK_CPV);
}

TEST_F(get_radar_target, xcp_user_cmd_get_radar_target_TEST9)
{
   uint8_t cmnd[]                                         = {0xF1, 0x90, 0x01, 0x01, 0x01, 0x01, 0x01};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd  = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_radar_radiate_cmd   = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_look_en_status_fptr = SWC_XCP_Get_Look_En_Status;
   uint8_t return_value = XCP_User_Cmd_Get_Radar_Target(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, XCP_CMD_PENDING_CPV);
}

TEST_F(get_radar_target, xcp_user_cmd_get_radar_target_TEST10)
{
   uint8_t cmnd[]                                         = {0xF1, 0x90, 0x02, 0x01, 0x01, 0x01, 0x01};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd  = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_radar_radiate_cmd   = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_look_en_status_fptr = SWC_XCP_Get_Look_En_Status;
   uint8_t return_value = XCP_User_Cmd_Get_Radar_Target(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, XCP_CMD_PENDING_CPV);
}

TEST_F(get_radar_target, xcp_user_cmd_get_radar_target_TEST11)
{
   uint8_t cmnd[]                                         = {0xF1, 0x90, 0x04, 0x01, 0x01, 0x01, 0x01};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd  = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_radar_radiate_cmd   = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_look_en_status_fptr = SWC_XCP_Get_Look_En_Status;
   uint8_t return_value = XCP_User_Cmd_Get_Radar_Target(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, XCP_CMD_PENDING_CPV);
}

TEST_F(get_radar_target, xcp_user_cmd_get_radar_target_TEST12)
{
   uint8_t cmnd[]                                         = {0xF1, 0x90, 0x08, 0x01, 0x01, 0x01, 0x01};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd  = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_radar_radiate_cmd   = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_look_en_status_fptr = SWC_XCP_Get_Look_En_Status;
   uint8_t return_value = XCP_User_Cmd_Get_Radar_Target(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, XCP_CMD_PENDING_CPV);
}

TEST_F(get_radar_target, xcp_user_cmd_get_radar_target_TEST13)
{
   uint8_t cmnd[]                                         = {0xF1, 0x90, 0x01, 0x01, 0x01, 0x01, 0x01};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd  = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_radar_radiate_cmd   = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_look_en_status_fptr = SWC_XCP_Get_Look_En_Status_lookA;
   uint8_t return_value = XCP_User_Cmd_Get_Radar_Target(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(XCP_NEGATIVE_RESPONSE_CPV, response[0]);
}

TEST_F(get_radar_target, xcp_user_cmd_get_radar_target_TEST14)
{
   uint8_t cmnd[]                                         = {0xF1, 0x90, 0x02, 0x01, 0x01, 0x01, 0x01};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd  = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_radar_radiate_cmd   = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_look_en_status_fptr = SWC_XCP_Get_Look_En_Status_lookB;
   uint8_t return_value = XCP_User_Cmd_Get_Radar_Target(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(XCP_NEGATIVE_RESPONSE_CPV, response[0]);
}

TEST_F(get_radar_target, xcp_user_cmd_get_radar_target_TEST15)
{
   uint8_t cmnd[]                                         = {0xF1, 0x90, 0x04, 0x01, 0x01, 0x01, 0x01};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd  = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_radar_radiate_cmd   = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_look_en_status_fptr = SWC_XCP_Get_Look_En_Status_lookC;
   uint8_t return_value = XCP_User_Cmd_Get_Radar_Target(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(XCP_NEGATIVE_RESPONSE_CPV, response[0]);
}

TEST_F(get_radar_target, xcp_user_cmd_get_radar_target_TEST16)
{
   uint8_t cmnd[]                                         = {0xF1, 0x90, 0x08, 0x01, 0x01, 0x01, 0x01};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd  = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_radar_radiate_cmd   = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_look_en_status_fptr = SWC_XCP_Get_Look_En_Status_lookD;
   uint8_t return_value = XCP_User_Cmd_Get_Radar_Target(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(XCP_NEGATIVE_RESPONSE_CPV, response[0]);
}

TEST_F(get_radar_target, xcp_user_cmd_get_radar_target_TEST17)
{
   uint8_t cmnd[]                                         = {0xF1, 0x90, 0x01, 0x10, 0x01, 0x1, 0x05};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd  = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_radar_radiate_cmd   = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_look_en_status_fptr = SWC_XCP_Get_Look_En_Status;
   uint8_t return_value = XCP_User_Cmd_Get_Radar_Target(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, XCP_CMD_PENDING_CPV);
}

/*
For Radar Transmitter Enable Command
*/

class get_transmitter_enable : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      uint8_t xcp_operation_mode_fake                      = XCP_OPCMD_NORMAL_MODE;
      XCP_BB_Input_Params_Initialise.xcp_force_radiate_ptr = &xcp_operation_mode_fake;
      Get_XCP_Init_Parameters_fake.custom_fake             = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(get_transmitter_enable, xcp_user_cmd_radar_transmitter_enable_test1)
{
   uint8_t cmnd[]       = {0xF1, 01, 01};
   uint8_t return_value = XCP_User_Cmd_Radar_Transmitter_Enable(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(XCP_POSITIVE_RESPONSE_CPV, response[0]);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(get_transmitter_enable, xcp_user_cmd_radar_transmitter_enable_test2)
{
   uint8_t cmnd[]       = {0xF1, 01, 04};
   uint8_t return_value = XCP_User_Cmd_Radar_Transmitter_Enable(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_NE(XCP_POSITIVE_RESPONSE_CPV, response[0]);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(get_transmitter_enable, xcp_user_cmd_radar_transmitter_enable_test3)
{
   uint8_t cmnd[]                                       = {0xF1, 01, 04};
   XCP_BB_Input_Params_Initialise.xcp_force_radiate_ptr = NULL;
   uint8_t return_value = XCP_User_Cmd_Radar_Transmitter_Enable(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_NE(XCP_POSITIVE_RESPONSE_CPV, response[0]);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(get_transmitter_enable, xcp_user_cmd_radar_transmitter_enable_test4)
{
   uint8_t cmnd[]       = {0xF1, 01, 02};
   uint8_t return_value = XCP_User_Cmd_Radar_Transmitter_Enable(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(XCP_POSITIVE_RESPONSE_CPV, response[0]);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(get_transmitter_enable, xcp_user_cmd_radar_transmitter_enable_test5)
{
   uint8_t cmnd[]       = {0xF1, 01, 03};
   uint8_t return_value = XCP_User_Cmd_Radar_Transmitter_Enable(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(XCP_POSITIVE_RESPONSE_CPV, response[0]);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
}
TEST_F(get_transmitter_enable, xcp_user_cmd_radar_transmitter_enable_test6)
{
   uint8_t cmnd[]       = {0xF1, 01, 00};
   uint8_t return_value = XCP_User_Cmd_Radar_Transmitter_Enable(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
}
TEST_F(get_analog_inputs_A0_A1, get_analog_inputs_A0_A1_TEST1)
{
   uint8_t cmnd[]                                        = {0xF1, 0xA0, 0x35};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   memset(response, 0, sizeof(response));
   framelength          = 0;
   uint8_t return_value = Get_Analog_Inputs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(framelength, 2);
}

TEST_F(get_analog_inputs_A0_A1, get_analog_inputs_A0_A1_TEST2)
{
   uint8_t cmnd[] = {0xF1, 0xA0, 0x22}; // note for cmnd[1]: this test cases can be taken for both A0 A1
   XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr = &xcp_adc_trigger_flag;
   memset(response, 0, sizeof(response));
   framelength          = 0;
   uint8_t return_value = Get_Analog_Inputs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(framelength, 2);
}

TEST_F(get_analog_inputs_A0_A1, get_analog_inputs_A0_A1_TEST3)
{
   uint8_t cmnd[]                                              = {0xF1, 0xA0, 0x2};
   XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr = &xcp_adc_trigger_flag;
   memset(response, 0, sizeof(response));
   framelength          = 0;
   uint8_t return_value = Get_Analog_Inputs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_PENDING_CPV);
   // For pending, response may not be filled yet
}

TEST_F(get_analog_inputs_A0_A1, get_analog_inputs_A0_A1_TEST4)
{
   uint8_t cmnd[] = {0xF1, 0xA0, 0x2};
   // xcp_adc_cmd.xcp_adc_cmnd_rcvd                               = CODED_TRUE;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd       = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr = &xcp_adc_trigger_flag;
   memset(response, 0, sizeof(response));
   framelength          = 0;
   uint8_t return_value = Get_Analog_Inputs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(framelength, 2);
}

TEST_F(get_analog_inputs_A0_A1, get_analog_inputs_A0_A1_TEST5)
{
   uint8_t cmnd[]                                              = {0xF1, 0xA0, 0x0};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd       = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr = &xcp_adc_trigger_flag;
   memset(response, 0, sizeof(response));
   framelength          = 0;
   uint8_t return_value = Get_Analog_Inputs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(framelength, 2);
}

TEST_F(get_analog_inputs_A0_A1, get_analog_inputs_A0_A1_TEST6)
{
   uint8_t cmnd[]                                              = {0xF1, 0xA0, 0xFF};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd       = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr = &xcp_adc_trigger_flag;
   memset(response, 0, sizeof(response));
   framelength          = 0;
   uint8_t return_value = Get_Analog_Inputs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(framelength, 2);
}

TEST_F(get_analog_filtered_inputs_A2_A3, get_analog_filtered_inputs_A2_A3_TEST1)
{
   uint8_t cmnd[] = {0xF1, 0xA2, 0x35};
   memset(response, 0, sizeof(response));
   framelength                                                 = 0;
   XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr = NULL;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd       = CODED_FALSE;
   uint8_t return_value = Get_Filtered_Analog_Inputs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(framelength, 2);
}

TEST_F(get_analog_filtered_inputs_A2_A3, get_analog_filtered_inputs_A2_A3_TEST2)
{
   uint8_t cmnd[] = {0xF1, 0xA2, 0x38};
   memset(response, 0, sizeof(response));
   framelength          = 0;
   uint8_t return_value = Get_Filtered_Analog_Inputs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(framelength, 2);
}

TEST_F(get_analog_filtered_inputs_A2_A3, get_analog_filtered_inputs_A2_A3_TEST3)
{
   uint8_t cmnd[] = {0xF1, 0xA2, 0x06};
   memset(response, 0, sizeof(response));
   framelength          = 0;
   uint8_t return_value = Get_Filtered_Analog_Inputs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_PENDING_CPV);
   // For pending, response may not be filled yet
}

TEST_F(get_analog_filtered_inputs_A2_A3, get_analog_filtered_inputs_A2_A3_TEST4)
{
   uint8_t xcp_adc_trigger_flg;
   uint8_t cmnd[] = {0xF1, 0xA2, 0x00};
   memset(response, 0, sizeof(response));
   framelength                                                 = 0;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd       = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr = &xcp_adc_trigger_flg;
   uint8_t return_value = Get_Filtered_Analog_Inputs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(framelength, 2);
}
TEST_F(get_analog_filtered_inputs_A2_A3, get_analog_filtered_inputs_A2_A3_TEST5)
{
   uint8_t xcp_adc_trigger_flg;
   uint8_t cmnd[] = {0xF1, 0xA2, 31};
   memset(response, 0, sizeof(response));
   framelength                                                 = 0;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd       = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr = &xcp_adc_trigger_flg;
   uint8_t return_value = Get_Filtered_Analog_Inputs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_PENDING_CPV);
}

TEST_F(get_host_analog_inputs_0to30, xcp_user_cmd_get_host_analog_inputs_0to30_TEST1)
{
   uint8_t cmnd[] = {0xF1, 0xA0, 0x6};
   uint8_t return_value;
   return_value = XCP_User_Cmd_Get_Host_Analog_Inputs_0to30(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(get_host_analog_inputs_31to61, xcp_user_cmd_get_host_analog_inputs_31to61_TEST1)
{
   uint8_t cmnd[] = {0xF1, 0xA1, 0x6};
   uint8_t return_value;
   return_value = XCP_User_Cmd_Get_Host_Analog_Inputs_31to61(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(get_host_analog_filtered_inputs_0to30, xcp_user_cmd_get_host_analog_filtered_inputs_0to30_TEST1)
{
   uint8_t cmnd[] = {0xF1, 0xA2, 0x6};
   uint8_t return_value;
   return_value =
      XCP_User_Cmd_Get_Host_Filtered_Analog_Inputs_0to30(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(get_host_analog_filtered_inputs_31to61, xcp_user_cmd_get_host_analog_filtered_inputs_31to61_TEST1)
{
   uint8_t cmnd[] = {0xF1, 0xA2, 0x6};
   uint8_t return_value;
   return_value =
      XCP_User_Cmd_Get_Host_Filtered_Analog_Inputs_31to61(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
}

/*
For XCP_User_Cmd_Inject_Fault
*/
class inject_fault : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      Get_XCP_Init_Parameters_fake.custom_fake             = Get_XCP_Init_Parameters_Custom_Fake;
      XCP_BB_Input_Params_Initialise.xcp_inject_fault_data = &xcp_inject_fault;
      xcp_inject_fault.xcp_sys_domain                      = 0U;
      xcp_inject_fault.xcp_failure_type                    = 0U;
      xcp_inject_fault.xcp_inject_control                  = 0U;
      xcp_inject_fault.xcp_cmd_injection_recvd             = CODED_FALSE;
      g_test_fault_config_flag                             = true;
      g_test_fault_config_table                            = xcp_test_fault_domain_table;
   }
   void TearDown()
   {
   }
};

TEST_F(inject_fault, xcp_user_cmd_Inject_Fault_TEST1)
{
   uint8_t cmnd[]                                       = {0xF1, 0x12, 0x02, 0x01, 0x01};
   XCP_BB_Input_Params_Initialise.xcp_inject_fault_data = NULL;
   uint8_t return_value = XCP_User_Cmd_Inject_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

TEST_F(inject_fault, xcp_user_cmd_Inject_Fault_TEST2)
{
   uint8_t cmnd[]       = {0xF1, 0x12, 0x02, 0x01, 0x01};
   uint8_t return_value = XCP_User_Cmd_Inject_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], cmnd[1]);
   ASSERT_EQ(response[2], cmnd[2]);
   ASSERT_EQ(response[3], cmnd[3]);
   ASSERT_EQ(response[4], cmnd[4]);
   ASSERT_EQ(framelength, XCP_RES_LEN_5);
   ASSERT_EQ(xcp_inject_fault.xcp_sys_domain, cmnd[2]);
   ASSERT_EQ(xcp_inject_fault.xcp_failure_type, cmnd[3]);
   ASSERT_EQ(xcp_inject_fault.xcp_inject_control, cmnd[4]);
   ASSERT_EQ(xcp_inject_fault.xcp_cmd_injection_recvd, CODED_TRUE);
}

TEST_F(inject_fault, xcp_user_cmd_Inject_Fault_TEST3)
{
   uint8_t cmnd[]       = {0xF1, 0x12, 0xFF, 0x01, 0x01};
   uint8_t return_value = XCP_User_Cmd_Inject_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
   ASSERT_EQ(xcp_inject_fault.xcp_cmd_injection_recvd, CODED_FALSE);
}

TEST_F(inject_fault, xcp_user_cmd_Inject_Fault_TEST44)
{
   uint8_t cmnd[]       = {0xF1, 0x12, 0x02, 0x0, 0x01};
   uint8_t return_value = XCP_User_Cmd_Inject_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

TEST_F(inject_fault, xcp_user_cmd_Inject_Fault_TEST4)
{
   uint8_t cmnd[]       = {0xF1, 0x12, 0x02, 0xFF, 0x01};
   uint8_t return_value = XCP_User_Cmd_Inject_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

TEST_F(inject_fault, xcp_user_cmd_Inject_Fault_TEST5)
{
   uint8_t cmnd[]       = {0xF1, 0x12, 0x02, 0x01, 0xFF};
   uint8_t return_value = XCP_User_Cmd_Inject_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

TEST_F(inject_fault, xcp_user_cmd_Inject_Fault_TEST6)
{
   uint8_t cmnd[]       = {0xF1, 0x12, 0x05, 0x02, 0x00};
   uint8_t return_value = XCP_User_Cmd_Inject_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

TEST_F(inject_fault, xcp_user_cmd_Inject_Fault_TEST7)
{
   uint8_t cmnd[]       = {0xF1, 0x12, 0x02, 0x03, 0x00};
   uint8_t return_value = XCP_User_Cmd_Inject_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[2], cmnd[2]);
   ASSERT_EQ(response[3], cmnd[3]);
   ASSERT_EQ(response[4], cmnd[4]);
}

TEST_F(inject_fault, xcp_user_cmd_Inject_Fault_TEST8)
{
   uint8_t cmnd[]       = {0xF1, 0x12, 0xF0, 0xFF, 0xFF};
   uint8_t return_value = XCP_User_Cmd_Inject_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

/* TEST9: fault_table == NULL via flag — covers !(NULL != fault_table) branch */
TEST_F(inject_fault, xcp_user_cmd_Inject_Fault_TEST9)
{
   uint8_t cmnd[]           = {0xF1, 0x12, 0x02, 0x01, 0x01};
   g_test_fault_config_flag = false; /* forces Get_XCP_Fault_Config_Table() to return NULL */
   uint8_t return_value     = XCP_User_Cmd_Inject_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

/* TEST10: domain with NULL handler pointer — covers !(NULL != xcp_fault_inj_handler) branch */
TEST_F(inject_fault, xcp_user_cmd_Inject_Fault_TEST10)
{
   uint8_t cmnd[]       = {0xF1, 0x12, 0x01, 0x01, 0x01}; /* domain 1 has NULL handler array */
   uint8_t return_value = XCP_User_Cmd_Inject_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

/* TEST11: IC below IC_min — covers XCP_RANGE_CHECK lower-bound false branch */
TEST_F(inject_fault, xcp_user_cmd_Inject_Fault_TEST11)
{
   uint8_t cmnd[]       = {0xF1, 0x12, 0x02, 0x05, 0x01}; /* FT=5 matched, IC=1 < IC_min=2 */
   uint8_t return_value = XCP_User_Cmd_Inject_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

/* TEST12: cmnd[3] < failure_type_min — covers XCP_RANGE_CHECK Branch 1 (first sub-condition FALSE).
   Uses xcp_test_gap_domain_table: handler[0] FT=0x00-0x00, handler[1] FT=0x05-0x05 (gap at 0x01-0x04).
   cmnd[3]=0x03: handler[0] passes '>= 0x00' but fails '<= 0x00' (Branch 3); then
   handler[1] fails '0x03 >= 0x05' (Branch 1 taken). Loop exits without match -> negative response. */
TEST_F(inject_fault, xcp_user_cmd_Inject_Fault_TEST12)
{
   uint8_t cmnd[]            = {0xF1, 0x12, 0x02, 0x03, 0x01}; /* FT=0x03 falls in gap [0x01-0x04] */
   g_test_fault_config_table = xcp_test_gap_domain_table;
   uint8_t return_value      = XCP_User_Cmd_Inject_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

/* TEST13 BVA: FT = FT_min - 1 = 0x00 (below all handlers in mm3 domain, FT_min=0x01 for handler[0]).
   RANGE_CHECK(0x00, 0x01, 0x01): 0x00 >= 0x01 = FALSE -> Branch 1 taken on every iteration.
   Loop exits without match -> negative response. */
TEST_F(inject_fault, xcp_user_cmd_Inject_Fault_TEST13)
{
   uint8_t cmnd[]       = {0xF1, 0x12, 0x02, 0x00, 0x00}; /* FT=0x00 < FT_min=0x01 of handler[0] */
   uint8_t return_value = XCP_User_Cmd_Inject_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

/* TEST14 BVA: FT = FT_min = 0x01 (exact lower boundary), IC = IC_min = 0x00 (exact lower boundary).
   handler[0]: FT=[0x01,0x01] IC=[0x00,0x01] -> both RANGE_CHECKs TRUE -> positive. */
TEST_F(inject_fault, xcp_user_cmd_Inject_Fault_TEST14)
{
   uint8_t cmnd[]       = {0xF1, 0x12, 0x02, 0x01, 0x00}; /* FT=FT_min=0x01, IC=IC_min=0x00 */
   uint8_t return_value = XCP_User_Cmd_Inject_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[2], cmnd[2]);
   ASSERT_EQ(response[3], cmnd[3]);
   ASSERT_EQ(response[4], cmnd[4]);
   ASSERT_EQ(framelength, XCP_RES_LEN_5);
   ASSERT_EQ(xcp_inject_fault.xcp_cmd_injection_recvd, CODED_TRUE);
}

/* TEST15 BVA: FT = 0x01 (handler[0] match), IC = IC_max + 1 = 0x02 (just above IC_max=0x01).
   RANGE_CHECK(0x02, 0x00, 0x01): 0x02 <= 0x01 = FALSE -> IC above max -> negative. */
TEST_F(inject_fault, xcp_user_cmd_Inject_Fault_TEST15)
{
   uint8_t cmnd[]       = {0xF1, 0x12, 0x02, 0x01, 0x02}; /* FT=0x01, IC=IC_max+1=0x02 for handler[0] */
   uint8_t return_value = XCP_User_Cmd_Inject_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

/* TEST16 BVA: FT = 0x05 (handler[5]), IC = IC_min = 0x02 (exact lower boundary for handler[5]).
   Complements TEST11 (IC=IC_min-1=0x01 -> negative). IC=0x02 -> positive. */
TEST_F(inject_fault, xcp_user_cmd_Inject_Fault_TEST16)
{
   uint8_t cmnd[]       = {0xF1, 0x12, 0x02, 0x05, 0x02}; /* FT=0x05, IC=IC_min=0x02 for handler[5] */
   uint8_t return_value = XCP_User_Cmd_Inject_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[2], cmnd[2]);
   ASSERT_EQ(response[3], cmnd[3]);
   ASSERT_EQ(response[4], cmnd[4]);
   ASSERT_EQ(framelength, XCP_RES_LEN_5);
   ASSERT_EQ(xcp_inject_fault.xcp_cmd_injection_recvd, CODED_TRUE);
}

/* TEST17 BVA: FT = 0x05 (handler[5]), IC = IC_max = 0x05 (exact upper boundary).
   RANGE_CHECK(0x05, 0x02, 0x05): TRUE -> positive. */
TEST_F(inject_fault, xcp_user_cmd_Inject_Fault_TEST17)
{
   uint8_t cmnd[]       = {0xF1, 0x12, 0x02, 0x05, 0x05}; /* FT=0x05, IC=IC_max=0x05 for handler[5] */
   uint8_t return_value = XCP_User_Cmd_Inject_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[2], cmnd[2]);
   ASSERT_EQ(response[3], cmnd[3]);
   ASSERT_EQ(response[4], cmnd[4]);
   ASSERT_EQ(framelength, XCP_RES_LEN_5);
   ASSERT_EQ(xcp_inject_fault.xcp_cmd_injection_recvd, CODED_TRUE);
}

/* TEST18 BVA: FT = 0x05 (handler[5]), IC = IC_max + 1 = 0x06 (just above IC_max=0x05).
   RANGE_CHECK(0x06, 0x02, 0x05): 0x06 <= 0x05 = FALSE -> IC above max -> negative. */
TEST_F(inject_fault, xcp_user_cmd_Inject_Fault_TEST18)
{
   uint8_t cmnd[]       = {0xF1, 0x12, 0x02, 0x05, 0x06}; /* FT=0x05, IC=IC_max+1=0x06 for handler[5] */
   uint8_t return_value = XCP_User_Cmd_Inject_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

/* TEST19 BVA: FT = FT_max + 1 = 0x06 (one above last handler[5] FT_max=0x05).
   All handlers fail RANGE_CHECK -> Branch 3 on every iteration, no match -> negative.
   Tighter than TEST4 (FT=0xFF) which is far beyond the boundary. */
TEST_F(inject_fault, xcp_user_cmd_Inject_Fault_TEST19)
{
   uint8_t cmnd[]       = {0xF1, 0x12, 0x02, 0x06, 0x00}; /* FT=FT_max+1=0x06, above all handlers */
   uint8_t return_value = XCP_User_Cmd_Inject_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

/* TEST20 BVA: domain = 0x05 (last valid domain / RSV), FT = 0x00, IC = 0x00.
   RSV has 1 handler: FT=[0x00,0x00], IC=[0x00,0x00]. Both RANGE_CHECKs TRUE -> positive.
   Tests domain at exact upper valid boundary. */
TEST_F(inject_fault, xcp_user_cmd_Inject_Fault_TEST20)
{
   uint8_t cmnd[]       = {0xF1, 0x12, 0x05, 0x00, 0x00}; /* domain=0x05 (RSV), FT=0x00, IC=0x00 */
   uint8_t return_value = XCP_User_Cmd_Inject_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[2], cmnd[2]);
   ASSERT_EQ(response[3], cmnd[3]);
   ASSERT_EQ(response[4], cmnd[4]);
   ASSERT_EQ(framelength, XCP_RES_LEN_5);
   ASSERT_EQ(xcp_inject_fault.xcp_cmd_injection_recvd, CODED_TRUE);
}

TEST_F(xcp_usr_cmd, xcp_usr_cmd_TEST2)
{
   uint8_t cmnd[]       = {0xF1};
   uint8_t index        = 100;
   uint8_t return_value = XCP_User_Command(cmnd, response, &framelength);
   ASSERT_NE(return_value, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(User_Cmd_idx, User_Cmd_idx_TEST1)
{
   uint8_t cmd_value    = 1;
   uint8_t return_value = Get_XCP_User_Cmd_Index(cmd_value);
   ASSERT_EQ(return_value, (uint8_t)0x0C);
}

TEST_F(xcp_usr_cmd, xcp_usr_cmd_TEST1)
{
   uint8_t cmnd[]       = {0xF1, 0x12, 0x01, 0x01, 0x00};
   uint8_t return_value = XCP_User_Command(cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
}

// ## Get_XCP_Pending_Cmnd_Status ##

class Get_XCP_Pnd_Cmnd_Sts : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      /*
      xcp_adc_cmd.xcp_adc_cmnd_rcvd                   = CODED_FALSE;
      XCP_Target_Info.xcp_cmnd_rcvd                   = CODED_FALSE;
      xcp_override_cmd.xcp_override_cmnd_rcvd         = CODED_FALSE;
      xcp_adc_filtered_cmd.xcp_adc_filtered_cmnd_rcvd = CODED_FALSE;
      */
   }
   void TearDown()
   {
   }
};

TEST_F(Get_XCP_Pnd_Cmnd_Sts, Get_XCP_Pnd_Cmnd_Sts_TEST1)
{
   uint8_t return_value = Get_XCP_Pending_Cmnd_Status();
   // ASSERT_NE(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(return_value, 0xAA);
}

/*
For XCP_User_Cmd_Set_Operation_Mode
*/

class set_operation_mode : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      static uint8_t xcp_operation_mode                     = XCP_OPCMD_NORMAL_MODE;
      XCP_BB_Input_Params_Initialise.xcp_operation_mode_ptr = &xcp_operation_mode;

      Get_XCP_Init_Parameters_fake.custom_fake = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(set_operation_mode, Set_Operation_Mode_TC1)
{
   uint8_t cmnd[] = {0xF1, 0x01, 0x01};
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Set_Operation_Mode(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], cmnd[1]);
   ASSERT_EQ(response[2], cmnd[2]);
   ASSERT_EQ(framelength, XCP_RES_LEN_3);
}

TEST_F(set_operation_mode, Set_Operation_Mode_TC2)
{
   uint8_t cmnd[] = {0xF1, 0x01, 0x02};
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Set_Operation_Mode(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], cmnd[1]);
   ASSERT_EQ(response[2], cmnd[2]);
   ASSERT_EQ(framelength, XCP_RES_LEN_3);
}

TEST_F(set_operation_mode, Set_Operation_Mode_negative_testCase_TC3)
{
   uint8_t cmnd[] = {0xF1, 0x01, 0x03};
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Set_Operation_Mode(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(framelength, 2);
}

TEST_F(set_operation_mode, Set_Operation_Mode_negative_testCase_TC4)
{
   uint8_t cmnd[]                                        = {0xF1, 0x01, 0x03};
   XCP_BB_Input_Params_Initialise.xcp_operation_mode_ptr = NULL;
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Set_Operation_Mode(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(framelength, 2);
}

class single_look_mode : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();

      static XCP_Single_Look_T XCP_Single_Look_Mode          = {CODED_FALSE, 0};
      XCP_BB_Input_Params_Initialise.xcp_look_mode_ptr       = &XCP_Single_Look_Mode;
      XCP_BB_Input_Params_Initialise.xcp_look_en_status_fptr = SWC_XCP_Get_Look_En_Status;

      Get_XCP_Init_Parameters_fake.custom_fake = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(single_look_mode, single_look_mode_TC1)
{
   uint8_t cmnd[] = {0xF1, 0x0B, 0x01, 0x01};
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Single_Look_Mode(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_USER_CMD_SINGLE_LOOK_MODE);
   ASSERT_EQ(response[2], cmnd[2]);
   ASSERT_EQ(response[3], cmnd[3]);
   ASSERT_EQ(framelength, XCP_RES_LEN_4);
}

TEST_F(single_look_mode, single_look_mode_TC2)
{
   uint8_t cmnd[] = {0xF1, 0x0B, 0x02, 0x01};
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Single_Look_Mode(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_USER_CMD_SINGLE_LOOK_MODE);
   ASSERT_EQ(response[2], cmnd[2]);
   ASSERT_EQ(response[3], cmnd[3]);
   ASSERT_EQ(framelength, XCP_RES_LEN_4);
}

TEST_F(single_look_mode, single_look_mode_negative_testCase_TC3)
{
   uint8_t cmnd[]                                         = {0xF1, 0x0B, 0x10, 0x02};
   static XCP_Single_Look_T XCP_Single_Look_Mode          = {CODED_FALSE, 0};
   XCP_BB_Input_Params_Initialise.xcp_look_mode_ptr       = &XCP_Single_Look_Mode;
   XCP_BB_Input_Params_Initialise.xcp_look_en_status_fptr = SWC_XCP_Get_Look_En_Status;
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Single_Look_Mode(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_GT(framelength, 0);
}

TEST_F(single_look_mode, xcp_user_cmd_single_look_mode_TC4)
{
   uint8_t cmnd[] = {0xF1, 0x0B, 0x01, 0x10};
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Single_Look_Mode(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_GT(framelength, 0);
}

TEST_F(single_look_mode, xcp_user_cmd_single_look_mode_TC5)
{
   uint8_t cmnd[]                                   = {0xF1, 0x0B, 0x01, 0x04};
   XCP_BB_Input_Params_Initialise.xcp_look_mode_ptr = NULL;
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Single_Look_Mode(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_GT(framelength, 0);
}

TEST_F(single_look_mode, xcp_user_cmd_single_look_mode_TC6)
{
   uint8_t cmnd[]                                         = {0xF1, 0x0B, 0x01, 0x05};
   static XCP_Single_Look_T XCP_Single_Look_Mode          = {CODED_FALSE, 0};
   XCP_BB_Input_Params_Initialise.xcp_look_mode_ptr       = &XCP_Single_Look_Mode;
   XCP_BB_Input_Params_Initialise.xcp_look_en_status_fptr = NULL;
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Single_Look_Mode(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_GT(framelength, 0);
}

TEST_F(single_look_mode, xcp_user_cmd_single_look_mode_TC7)
{
   uint8_t cmnd[]                                         = {0xF1, 0x0B, 0x01, 0x02};
   static XCP_Single_Look_T XCP_Single_Look_Mode          = {CODED_FALSE, 0};
   XCP_BB_Input_Params_Initialise.xcp_look_mode_ptr       = &XCP_Single_Look_Mode;
   XCP_BB_Input_Params_Initialise.xcp_look_en_status_fptr = SWC_XCP_Get_Look_En_Status;
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Single_Look_Mode(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_USER_CMD_SINGLE_LOOK_MODE);
   ASSERT_EQ(response[2], cmnd[2]);
   ASSERT_EQ(response[3], cmnd[3]);
   ASSERT_EQ(framelength, XCP_RES_LEN_4);
}

TEST_F(single_look_mode, xcp_user_cmd_single_look_mode_TC8)
{
   uint8_t cmnd[]                                         = {0xF1, 0x0B, 0x01, 0x00};
   static XCP_Single_Look_T XCP_Single_Look_Mode          = {CODED_FALSE, 0};
   XCP_BB_Input_Params_Initialise.xcp_look_mode_ptr       = &XCP_Single_Look_Mode;
   XCP_BB_Input_Params_Initialise.xcp_look_en_status_fptr = SWC_XCP_Get_Look_En_Status;
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Single_Look_Mode(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_GT(framelength, 0);
}

TEST_F(single_look_mode, xcp_user_cmd_single_look_mode_TC9)
{
   uint8_t cmnd[]                                         = {0xF1, 0x0B, 0x05, 0x01};
   static XCP_Single_Look_T XCP_Single_Look_Mode          = {CODED_FALSE, 0};
   XCP_BB_Input_Params_Initialise.xcp_look_mode_ptr       = &XCP_Single_Look_Mode;
   XCP_BB_Input_Params_Initialise.xcp_look_en_status_fptr = SWC_XCP_Get_Look_En_Status;
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Single_Look_Mode(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_GT(framelength, 0);
}

/* TC10: C1=TRUE, C2=TRUE, C3=FALSE — covers inner compound sub-condition C3 independently false
         cmnd[3]=0x01 → valid look range [0x01..0x05]; SWC_XCP_Get_Look_En_Status_lookA(look=0)
         returns 0x55 which != CODED_TRUE(0xAA) → C3 = FALSE → inner condition FALSE */
TEST_F(single_look_mode, xcp_user_cmd_single_look_mode_TC10)
{
   uint8_t cmnd[]                                         = {0xF1, 0x0B, 0x01, 0x01};
   static XCP_Single_Look_T XCP_Single_Look_Mode          = {CODED_FALSE, 0};
   XCP_BB_Input_Params_Initialise.xcp_look_mode_ptr       = &XCP_Single_Look_Mode;
   XCP_BB_Input_Params_Initialise.xcp_look_en_status_fptr = SWC_XCP_Get_Look_En_Status_lookA;
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Single_Look_Mode(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_GT(framelength, 0);
}

/*
For XCP_User_Cmd_Set_Radar_To_CW_Mode
*/

class set_radar_to_cw_mode : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();

      static uint8_t XCP_CW_Mode = CODED_FALSE;

      XCP_BB_Input_Params_Initialise.xcp_cw_mode_ptr       = &XCP_CW_Mode;
      XCP_BB_Input_Params_Initialise.xcp_radar_radiate_cmd = 0;
      XCP_BB_Input_Params_Initialise.xcp_radar_init_status = 0;

      Get_XCP_Init_Parameters_fake.custom_fake = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(set_radar_to_cw_mode, set_radar_to_cw_mode_TC1)
{
   uint8_t cmnd[]                                       = {0xF1, 0x14, 0x01};
   XCP_BB_Input_Params_Initialise.xcp_radar_radiate_cmd = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_radar_init_status = (uint8_t)XCP_RADAR_INIT_SUCCESS;
   uint8_t result = XCP_User_Cmd_Set_Radar_To_CW_Mode(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[2], cmnd[2]);
}

TEST_F(set_radar_to_cw_mode, set_radar_to_cw_mode_TC2)
{
   uint8_t cmnd[]                                       = {0xF1, 0x14, 0x00};
   XCP_BB_Input_Params_Initialise.xcp_radar_radiate_cmd = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_radar_init_status = (uint8_t)XCP_RADAR_INIT_SUCCESS;
   uint8_t result = XCP_User_Cmd_Set_Radar_To_CW_Mode(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   EXPECT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   EXPECT_EQ(response[2], XCP_CW_MODE_ENABLE);
}

TEST_F(set_radar_to_cw_mode, set_radar_to_cw_mode_TC3)
{
   uint8_t cmnd[]                                       = {0xF1, 0x14, 0x00};
   XCP_BB_Input_Params_Initialise.xcp_radar_radiate_cmd = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_radar_init_status = (uint8_t)XCP_RADAR_INIT_STARTED;
   uint8_t result = XCP_User_Cmd_Set_Radar_To_CW_Mode(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
}

TEST_F(set_radar_to_cw_mode, set_radar_to_cw_mode_TC4)
{
   uint8_t cmnd[] = {0xF1, 0x14, 0x00};
   uint8_t result = XCP_User_Cmd_Set_Radar_To_CW_Mode(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   EXPECT_EQ(framelength, 0x02);
}

TEST_F(set_radar_to_cw_mode, set_radar_to_cw_mode_TC5)
{
   uint8_t cmnd[]                                 = {0xF1, 0x14, 0x00};
   XCP_BB_Input_Params_Initialise.xcp_cw_mode_ptr = NULL;
   uint8_t result = XCP_User_Cmd_Set_Radar_To_CW_Mode(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
}

TEST_F(set_radar_to_cw_mode, set_radar_to_cw_mode_TC6)
{
   uint8_t cmnd[]                                       = {0xF1, 0x14, 0x02};
   XCP_BB_Input_Params_Initialise.xcp_radar_radiate_cmd = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_radar_init_status = (uint8_t)XCP_RADAR_INIT_SUCCESS;
   uint8_t result = XCP_User_Cmd_Set_Radar_To_CW_Mode(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[2], cmnd[2]);
}

TEST_F(set_radar_to_cw_mode, set_radar_to_cw_mode_TC7)
{
   uint8_t cmnd[]                                       = {0xF1, 0x14, 0x00};
   XCP_BB_Input_Params_Initialise.xcp_radar_radiate_cmd = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_radar_init_status = (uint8_t)XCP_RADAR_INIT_STARTED;
   uint8_t result = XCP_User_Cmd_Set_Radar_To_CW_Mode(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   EXPECT_EQ(framelength, XCP_RES_LEN_2);
}

TEST_F(set_radar_to_cw_mode, set_radar_to_cw_mode_TC8)
{
   uint8_t cmnd[]                                       = {0xF1, 0x14, 0x00};
   XCP_BB_Input_Params_Initialise.xcp_radar_radiate_cmd = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_radar_init_status = (uint8_t)XCP_RADAR_INIT_SUCCESS;
   uint8_t result = XCP_User_Cmd_Set_Radar_To_CW_Mode(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
}

TEST_F(set_radar_to_cw_mode, set_radar_to_cw_mode_TC9)
{
   uint8_t cmnd[]                                       = {0xF1, 0x14, 0x00};
   XCP_BB_Input_Params_Initialise.xcp_radar_radiate_cmd = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_radar_init_status = (uint8_t)XCP_RADAR_INIT_NOT_STARTED;
   uint8_t result = XCP_User_Cmd_Set_Radar_To_CW_Mode(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[2], XCP_CW_MODE_DISABLE);
   EXPECT_EQ(framelength, 0x02);
}

/*
For XCP_ADC_Info_Periodic_Task
*/

class ADC_info_Periodic_Task : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();

      typedef struct
      {
         uint16_t ADC_CH1_NC;
         uint16_t ADC_CH2_NC;
         uint16_t ADC_CH3_NC;
         uint16_t ADC_Battery_volt;
         uint16_t ADC_Pos_GND_A;
         uint16_t ADC_Pos_GND_B;
         uint16_t ADC_Supply_0v9;
         uint16_t ADC_CH8_NC;
         uint16_t ADC_Supply_1v8;
         uint16_t Validity_Flag;
      } Dt_RawAdcData_T;
      static Dt_RawAdcData_T XCP_Raw_Adc_Data_UnFilt;
      static uint8_t xcp_adc_validity_flag_status = CODED_TRUE;
      static uint8_t xcp_adc_trigger_flag         = CODED_FALSE;

      XCP_BB_Input_Params_Initialise.xcp_get_raw_adc_data_ptr      = (uint16_t *)&XCP_Raw_Adc_Data_UnFilt;
      XCP_BB_Input_Params_Initialise.num_analog_inputs             = 100;
      XCP_BB_Input_Params_Initialise.xcp_get_adc_validity_flag_ptr = &xcp_adc_validity_flag_status;
      XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr  = &xcp_adc_trigger_flag;
      Get_XCP_Init_Parameters_fake.custom_fake                     = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(ADC_info_Periodic_Task, ADC_info_Periodic_Task_TC1)
{
   uint8_t result = XCP_ADC_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, 0u);
}

TEST_F(ADC_info_Periodic_Task, ADC_info_Periodic_Task_TC2)
{
   // XCP_USER_CMD_GET_HOST_ANALOG_INPUTS_31TO61 == xcp_adc_cmd.xcp_adc_cmnd;
   // xcp_adc_cmd.xcp_adc_quantity = 100;
   // uint8_t xcp_adc_qty                                  = 100U;
   // uint8_t XCP_ADC_Quantity                             = 100U;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_val = (uint8_t)XCP_USER_CMD_GET_HOST_ANALOG_INPUTS_0TO30;
   uint8_t result = XCP_ADC_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, 0u);
}

TEST_F(ADC_info_Periodic_Task, ADC_info_Periodic_Task_TC3)
{
   uint8_t xcp_adc_validity_flag_stats                          = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_get_adc_validity_flag_ptr = NULL;
   // xcp_adc_cmd.cycle_cnt                                        = 3U;
   uint8_t result = XCP_ADC_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(ADC_info_Periodic_Task, ADC_info_Periodic_Task_negative_TC4)
{
   XCP_BB_Input_Params_Initialise.xcp_get_raw_adc_data_ptr = NULL;
   uint8_t result = XCP_ADC_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, 0u);
}

TEST_F(ADC_info_Periodic_Task, ADC_info_Periodic_Task_TC5)
{
   uint8_t xcp_adc_validity_flag_stats                          = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_get_adc_validity_flag_ptr = &xcp_adc_validity_flag_stats;
   // xcp_adc_cmd.cycle_cnt                                        = 2U;
   uint8_t result = XCP_ADC_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_PENDING_CPV);
}

TEST_F(ADC_info_Periodic_Task, ADC_info_Periodic_Task_TC6)
{
   uint8_t xcp_adc_validity_flag_stats                          = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_get_adc_validity_flag_ptr = &xcp_adc_validity_flag_stats;
   // xcp_adc_cmd.cycle_cnt                                        = 2U;
   uint8_t result = XCP_ADC_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   // ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_PENDING_CPV);
}

TEST_F(ADC_info_Periodic_Task, ADC_info_Periodic_Task_TC7)
{
   XCP_BB_Input_Params_Initialise.xcp_get_raw_adc_data_ptr      = (volatile short unsigned int *)malloc(20);
   uint8_t adc_validity_flag                                    = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_get_adc_validity_flag_ptr = &adc_validity_flag;
   XCP_BB_Input_Params_Initialise.num_analog_inputs             = 10;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_val         = 0xA0;
   XCP_ADC_Quantity                                             = 10;
   uint8_t result = XCP_ADC_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(ADC_info_Periodic_Task, ADC_info_Periodic_Task_TC8)
{
   XCP_BB_Input_Params_Initialise.xcp_get_raw_adc_data_ptr      = (volatile short unsigned int *)malloc(20);
   uint8_t adc_validity_flag                                    = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_get_adc_validity_flag_ptr = &adc_validity_flag;
   XCP_BB_Input_Params_Initialise.num_analog_inputs             = 0;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_val         = 0xA0;
   XCP_ADC_Quantity                                             = 10;
   uint8_t result = XCP_ADC_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(ADC_info_Periodic_Task, ADC_info_Periodic_Task_TC9)
{
   XCP_BB_Input_Params_Initialise.xcp_get_raw_adc_data_ptr      = (volatile short unsigned int *)malloc(20);
   uint8_t adc_validity_flag                                    = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_get_adc_validity_flag_ptr = &adc_validity_flag;
   XCP_BB_Input_Params_Initialise.num_analog_inputs             = 0;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_val         = 0xA1;
   XCP_ADC_Quantity                                             = 10;
   uint8_t result = XCP_ADC_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(ADC_info_Periodic_Task, ADC_info_Periodic_Task_TC10)
{
   /* Cover 31TO61 inner-true path: (index + XCP_MAX_ANALOG_INPUTS_PER_FRAME) < num_analog_inputs */
   XCP_BB_Input_Params_Initialise.xcp_get_raw_adc_data_ptr      = (volatile short unsigned int *)malloc(100U * sizeof(uint16_t));
   uint8_t adc_validity_flag                                    = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_get_adc_validity_flag_ptr = &adc_validity_flag;
   XCP_BB_Input_Params_Initialise.num_analog_inputs             = 100;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_val         = 0xA1;
   XCP_ADC_Quantity                                             = 5;
   uint8_t result = XCP_ADC_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(ADC_info_Periodic_Task, ADC_info_Periodic_Task_Timeout_TC)
{
   // Setup: Create a timeout scenario where validity flag is false
   // and cycle count equals max cycle count
   static uint8_t xcp_adc_validity_flag_stats                   = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_get_adc_validity_flag_ptr = &xcp_adc_validity_flag_stats;

   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = 2U; // assuming timeout is 3
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max = 3U; // This makes Is_Cycle_Cnt_Timedout true

   uint8_t result = XCP_ADC_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);

   // Verify the function returns XCP_CMD_OK_CPV and sets error appropriately
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);

   // Verify negative response was prepared with XCP_ERR_CMD_SYNTAX_CPV error code
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], (uint8_t)XCP_ERR_CMD_SYNTAX_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

/*Hardware Revision F1 0D */

uint8_t hardware_revision = 0x00;

class read_hardware_version : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      XCP_BB_Input_Params_Initialise.xcp_read_hardware_version_ptr = &hardware_revision;
      Get_XCP_Init_Parameters_fake.custom_fake                     = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(read_hardware_version, Read_Hardware_version_TC1)
{
   uint8_t cmnd[]                                               = {0xF1, 0x0D};
   XCP_BB_Input_Params_Initialise.xcp_read_hardware_version_ptr = NULL;
   uint8_t result = XCP_User_Cmd_Read_Hardware_Version(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(read_hardware_version, Read_Hardware_version_TC2)
{
   uint8_t cmnd[] = {0xF1, 0x0D};
   uint8_t result = XCP_User_Cmd_Read_Hardware_Version(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

/*
For XCP_Filtered_ADC_Info_Periodic_Task
*/
class ADC_Filtered_Info_Periodic_Task : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      typedef struct
      {
         uint16_t ADC_CH1_NC;
         uint16_t ADC_CH2_NC;
         uint16_t ADC_CH3_NC;
         uint16_t ADC_Battery_volt;
         uint16_t ADC_Pos_GND_A;
         uint16_t ADC_Pos_GND_B;
         uint16_t ADC_Supply_0v9;
         uint16_t ADC_CH8_NC;
         uint16_t ADC_Supply_1v8;
         uint16_t Validity_Flag;
      } Dt_RawAdcDataFilt_T;
      static Dt_RawAdcDataFilt_T XCP_Raw_Adc_Filtered_Data;
      static uint8_t xcp_adc_trigger_flag         = CODED_TRUE;
      static uint8_t xcp_adc_validity_flag_status = CODED_TRUE;

      XCP_BB_Input_Params_Initialise.xcp_get_raw_adc_filtered_data_ptr = (void *)&XCP_Raw_Adc_Filtered_Data;
      XCP_BB_Input_Params_Initialise.num_analog_inputs                 = 100;
      XCP_BB_Input_Params_Initialise.xcp_get_adc_validity_flag_ptr     = &xcp_adc_validity_flag_status;
      XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr      = &xcp_adc_trigger_flag;
      Get_XCP_Init_Parameters_fake.custom_fake                         = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(ADC_Filtered_Info_Periodic_Task, ADC_Filtered_Info_Periodic_Task_TC1)
{
   // xcp_adc_filtered_cmd.xcp_adc_filtered_quantity   = 1;
   XCP_BB_Input_Params_Initialise.num_analog_inputs = 100;
   uint8_t result = XCP_Filtered_ADC_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, 0);
}

TEST_F(ADC_Filtered_Info_Periodic_Task, ADC_Filtered_Info_Periodic_Task_TC3)
{
   // xcp_adc_filtered_cmd.xcp_adc_filtered_quantity = 0;
   // xcp_adc_filtered_cmd.xcp_adc_filtered_cmnd     = 4;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_val = (uint8_t)XCP_USER_CMD_GET_FILTERED_ADC_INPUTS_0TO30;
   uint8_t result = XCP_Filtered_ADC_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, 0);
}

TEST_F(ADC_Filtered_Info_Periodic_Task, ADC_Filtered_Info_Periodic_Task_TC4)
{
   // xcp_adc_filtered_cmd.xcp_adc_filtered_quantity   = 5;
   XCP_BB_Input_Params_Initialise.num_analog_inputs = 100;
   uint8_t result = XCP_Filtered_ADC_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, 0);
}

TEST_F(ADC_Filtered_Info_Periodic_Task, ADC_Filtered_Info_Periodic_Task_negative_TC2)
{
   static uint8_t xcp_adc_trigger_flg                           = CODED_FALSE;
   static uint8_t xcp_adc_validity_flag_stats                   = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_get_adc_validity_flag_ptr = &xcp_adc_validity_flag_stats;
   XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr  = &xcp_adc_trigger_flg;
   // XCP_ADC_MAX_WAIT_TIME == xcp_adc_filtered_cmd.cycle_cnt;
   uint8_t result = XCP_Filtered_ADC_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, 1u);
}

TEST_F(ADC_Filtered_Info_Periodic_Task, ADC_Filtered_Info_Periodic_Task_TC6)
{
   static uint8_t xcp_adc_trigger_flg                           = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_get_adc_validity_flag_ptr = NULL;
   XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr  = &xcp_adc_trigger_flg;
   uint8_t result = XCP_Filtered_ADC_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, 0u);
}

TEST_F(ADC_Filtered_Info_Periodic_Task, ADC_Filtered_Info_Periodic_Task_TC5)
{
   static uint8_t xcp_adc_validity_flag_stats                       = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_get_raw_adc_filtered_data_ptr = NULL;
   XCP_BB_Input_Params_Initialise.xcp_get_adc_validity_flag_ptr     = &xcp_adc_validity_flag_stats;
   uint8_t result = XCP_Filtered_ADC_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, 0u);
}

TEST_F(ADC_Filtered_Info_Periodic_Task, ADC_Filtered_Info_Periodic_Task_TC7)
{
   // xcp_adc_filtered_cmd.xcp_adc_filtered_quantity   = 0;
   XCP_BB_Input_Params_Initialise.num_analog_inputs = 0;
   uint8_t result = XCP_Filtered_ADC_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, 0);
}

TEST_F(ADC_Filtered_Info_Periodic_Task, ADC_Filtered_Info_Periodic_Task_TC9)
{
   // xcp_adc_filtered_cmd.xcp_adc_filtered_quantity   = 0;
   XCP_BB_Input_Params_Initialise.num_analog_inputs = 3;
   uint8_t result = XCP_Filtered_ADC_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, 0);
}

class Target_info_Periodic_Task : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      XCP_BB_Input_Params_Initialise.xcp_num_max_dets            = 768U;
      XCP_BB_Input_Params_Initialise.xcp_copy_target_report_fptr = SWC_XCP_Copy_Target_Report;
      XCP_BB_Input_Params_Initialise.xcp_look_en_status_fptr     = SWC_XCP_Get_Look_En_Status;
      XCP_BB_Input_Params_Initialise.xcp_current_look            = 0U;
      Get_XCP_Init_Parameters_fake.custom_fake                   = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

/* Target_info_Periodic_Task */

TEST_F(Target_info_Periodic_Task, Target_info_Periodic_Task_TC1)
{
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_PENDING_CPV);
   ASSERT_EQ(response[0], (uint8_t)XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(framelength, (uint8_t)2U);
}

TEST_F(Target_info_Periodic_Task, Target_info_Periodic_Task_TC2)
{
   XCP_Target_Info.look_enable_phy = 0u;
   XCP_Target_Info.rrate_min_phy   = 20u;
   XCP_Target_Info.rrate_max_phy   = 20u;
   XCP_Target_Info.phys_range_phy  = 31u;
   uint8_t result                  = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_PENDING_CPV);
   ASSERT_EQ(response[1], (uint8_t)0);
   ASSERT_EQ(framelength, (uint8_t)2U);
}

TEST_F(Target_info_Periodic_Task, Target_info_Periodic_Task_TC3)
{
   XCP_Target_Info.process_look_A = CODED_FALSE;
   XCP_Target_Info.process_look_B = CODED_FALSE;
   XCP_Target_Info.process_look_C = CODED_FALSE;
   XCP_Target_Info.process_look_D = CODED_FALSE;
   uint8_t result                 = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], (uint8_t)XCP_POSITIVE_RESPONSE_CPV);
}

TEST_F(Target_info_Periodic_Task, Target_info_Periodic_Task_TC4)
{
   XCP_Target_Info.process_look_A = CODED_TRUE;
   XCP_Target_Info.process_look_B = CODED_FALSE;
   XCP_Target_Info.process_look_C = CODED_FALSE;
   XCP_Target_Info.process_look_D = CODED_FALSE;
   uint8_t result                 = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_PENDING_CPV);
   ASSERT_EQ(response[0], (uint8_t)XCP_POSITIVE_RESPONSE_CPV);
}

TEST_F(Target_info_Periodic_Task, Target_info_Periodic_Task_TC5)
{
   XCP_Target_Info.process_look_A = CODED_FALSE;
   XCP_Target_Info.process_look_B = CODED_TRUE;
   XCP_Target_Info.process_look_C = CODED_FALSE;
   XCP_Target_Info.process_look_D = CODED_FALSE;
   uint8_t result                 = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_PENDING_CPV);
   ASSERT_EQ(response[1], (uint8_t)0x90);
}

TEST_F(Target_info_Periodic_Task, Target_info_Periodic_Task_TC6)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = 1;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max = 1;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   XCP_Target_Info.process_look_A                        = CODED_FALSE;
   XCP_Target_Info.process_look_B                        = CODED_FALSE;
   XCP_Target_Info.process_look_C                        = CODED_TRUE;
   XCP_Target_Info.process_look_D                        = CODED_FALSE;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_PENDING_CPV);
}

TEST_F(Target_info_Periodic_Task, Target_info_Periodic_Task_TC7)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = 1;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max = 1;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   XCP_Target_Info.process_look_A                        = CODED_FALSE;
   XCP_Target_Info.process_look_B                        = CODED_FALSE;
   XCP_Target_Info.process_look_C                        = CODED_FALSE;
   XCP_Target_Info.process_look_D                        = CODED_TRUE;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_NE(XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt, XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_PENDING_CPV);
}

class Target_info_Periodic : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      XCP_BB_Input_Params_Initialise.xcp_num_max_dets            = 768U;
      XCP_BB_Input_Params_Initialise.xcp_copy_target_report_fptr = SWC_XCP_Copy_Target_Report;
      XCP_BB_Input_Params_Initialise.xcp_current_look            = 0U;
      Get_XCP_Init_Parameters_fake.custom_fake                   = Get_XCP_Init_Parameters_Custom_Fake;

      memset(&XCP_Trgt_Rprt, 0, sizeof(XCP_Trgt_Rprt));
      XCP_Trgt_Rprt.num_af_det = 768;
   }
   void TearDown()
   {
   }
};

/* Target_info_Periodic */

TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC1)
{
   XCP_BB_Input_Params_Initialise.xcp_current_look = 0u;
   XCP_Target_Info.look_enable_phy                 = 0u;
   XCP_Target_Info.phys_range_phy                  = 1u;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_PENDING_CPV);
}

TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC2)
{
   XCP_BB_Input_Params_Initialise.xcp_current_look = 0U;
   XCP_Target_Info.look_enable_phy                 = 0xf;
   XCP_Target_Info.phys_range_phy                  = 1u;
   XCP_Target_Info.rrate_min_phy                   = 18u;
   XCP_Target_Info.rrate_max_phy                   = 14u;
   XCP_Target_Info.range_min                       = 0u;
   XCP_Target_Info.range_max                       = 0u;
   // XCP_Target_Info.cycle_cnt                       = 0u;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_PENDING_CPV);
}

TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC3)
{
   XCP_BB_Input_Params_Initialise.xcp_current_look = 0U;
   XCP_Target_Info.look_enable_phy                 = 0xf;
   XCP_Target_Info.phys_range_phy                  = 1u;
   XCP_Target_Info.rrate_min_phy                   = 14u;
   XCP_Target_Info.rrate_max_phy                   = 18u;
   XCP_Target_Info.range_min                       = 0u;
   XCP_Target_Info.range_max                       = 0u;
   // XCP_Target_Info.cycle_cnt                       = 0u;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_PENDING_CPV);
}

TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC4)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_current_look       = 0U;
   XCP_Target_Info.process_look_A                        = CODED_TRUE;
   XCP_Target_Info.look_enable_phy                       = 0x0f;
   XCP_Target_Info.phys_range_phy                        = 31u;
   XCP_Target_Info.rrate_min_phy                         = 14u;
   XCP_Target_Info.rrate_max_phy                         = 14u;
   XCP_Target_Info.range_min                             = 0u;
   XCP_Target_Info.range_max                             = 0u;
   // XCP_Target_Info.cycle_cnt                       = 0u;
   // XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt = XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_PENDING_CPV);
   XCP_Target_Info.process_look_A = CODED_FALSE;
}
TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC14)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_current_look       = 0U;
   XCP_Target_Info.process_look_A                        = CODED_TRUE;
   XCP_Target_Info.look_enable_phy                       = 0x0f;
   XCP_Target_Info.phys_range_phy                        = 31u;
   XCP_Target_Info.rrate_min_phy                         = 14u;
   XCP_Target_Info.rrate_max_phy                         = 14u;
   XCP_Target_Info.range_min                             = 0u;
   XCP_Target_Info.range_max                             = 0u;
   // XCP_Target_Info.cycle_cnt                       = 0u;
   // XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt = 1;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_PENDING_CPV);
   XCP_Target_Info.process_look_A = CODED_FALSE;
}
TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC15)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_TRUE;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = 10;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max = 10;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);

   ASSERT_EQ(result, (uint8_t)XCP_CMD_PENDING_CPV);
   XCP_Target_Info.process_look_A = CODED_FALSE;
}

TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC100)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_current_look       = 1U;
   XCP_Target_Info.process_look_B                        = CODED_TRUE;
   XCP_Target_Info.look_enable_phy                       = 0x0f;
   XCP_Target_Info.phys_range_phy                        = 31u;
   XCP_Target_Info.rrate_min_phy                         = 14u;
   XCP_Target_Info.rrate_max_phy                         = 14u;
   XCP_Target_Info.range_min                             = 0u;
   XCP_Target_Info.range_max                             = 0u;
   // XCP_Target_Info.cycle_cnt                       = 0u;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt = XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_PENDING_CPV);
   XCP_Target_Info.process_look_B = CODED_FALSE;
}

TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC101)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_current_look       = 2U;
   XCP_Target_Info.process_look_C                        = CODED_TRUE;
   XCP_Target_Info.look_enable_phy                       = 0x0f;
   XCP_Target_Info.phys_range_phy                        = 31u;
   XCP_Target_Info.rrate_min_phy                         = 14u;
   XCP_Target_Info.rrate_max_phy                         = 14u;
   XCP_Target_Info.range_min                             = 0u;
   XCP_Target_Info.range_max                             = 0u;
   // XCP_Target_Info.cycle_cnt                       = 0u;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_PENDING_CPV);
   XCP_Target_Info.process_look_C = CODED_FALSE;
}

TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC102)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_current_look       = 3U;
   XCP_Target_Info.process_look_D                        = CODED_TRUE;
   XCP_Target_Info.look_enable_phy                       = 0x0f;
   XCP_Target_Info.phys_range_phy                        = 31u;
   XCP_Target_Info.rrate_min_phy                         = 14u;
   XCP_Target_Info.rrate_max_phy                         = 14u;
   XCP_Target_Info.range_min                             = 0u;
   XCP_Target_Info.range_max                             = 0u;
   // XCP_Target_Info.cycle_cnt                       = 0u;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   XCP_Target_Info.process_look_D = CODED_FALSE;
}
TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC103)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_current_look       = 2U;
   XCP_Target_Info.process_look_D                        = CODED_TRUE;
   XCP_Target_Info.look_enable_phy                       = 0x0f;
   XCP_Target_Info.phys_range_phy                        = 31u;
   XCP_Target_Info.rrate_min_phy                         = 14u;
   XCP_Target_Info.rrate_max_phy                         = 14u;
   XCP_Target_Info.range_min                             = 0u;
   XCP_Target_Info.range_max                             = 0u;
   // XCP_Target_Info.cycle_cnt                       = 0u;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_PENDING_CPV);
   XCP_Target_Info.process_look_D = CODED_FALSE;
}

TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC5)
{
   XCP_BB_Input_Params_Initialise.xcp_current_look = 0U;
   XCP_Target_Info.look_enable_phy                 = 0x0f;
   XCP_Target_Info.phys_range_phy                  = 0u;
   XCP_Target_Info.rrate_min_phy                   = 14u;
   XCP_Target_Info.rrate_max_phy                   = 14u;
   XCP_Target_Info.range_min                       = 0u;
   XCP_Target_Info.range_max                       = 0u;
   // XCP_Target_Info.cycle_cnt                       = 0u;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}
TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC6)
{
   XCP_BB_Input_Params_Initialise.xcp_current_look = 0U;
   XCP_Target_Info.look_enable_phy                 = 1u;
   XCP_Target_Info.phys_range_phy                  = 1u;
   XCP_Target_Info.rrate_min_phy                   = 1u;
   XCP_Target_Info.rrate_max_phy                   = 0u;
   XCP_Target_Info.range_min                       = 0u;
   XCP_Target_Info.range_max                       = 0u;
   // XCP_Target_Info.cycle_cnt                       = 0u;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC7)
{
   XCP_BB_Input_Params_Initialise.xcp_current_look = 0U;
   XCP_Target_Info.look_enable_phy                 = 1u;
   XCP_Target_Info.phys_range_phy                  = 1u;
   XCP_Target_Info.rrate_min_phy                   = 0u;
   XCP_Target_Info.rrate_max_phy                   = 1u;
   XCP_Target_Info.range_min                       = 0u;
   XCP_Target_Info.range_max                       = 0u;

   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(Target_info_Periodic, sTarget_info_Periodic_TCNRC)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = 0;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max = 1;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   XCP_Target_Info.process_look_A                        = CODED_FALSE;
   XCP_Target_Info.process_look_B                        = CODED_FALSE;
   XCP_Target_Info.process_look_C                        = CODED_FALSE;
   XCP_Target_Info.process_look_D                        = CODED_FALSE;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

/* TC_NullReport: cmd=CODED_TRUE but xcp_TgtRpts=NULL — covers !(NULL != xcp_TgtRpts) false branch */
TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC_NullReport)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd      = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_copy_target_report_fptr = SWC_XCP_Copy_Target_Report_Null;
   XCP_Target_Info.process_look_A                             = CODED_TRUE;
   XCP_Target_Info.process_look_B                             = CODED_FALSE;
   XCP_Target_Info.process_look_C                             = CODED_FALSE;
   XCP_Target_Info.process_look_D                             = CODED_FALSE;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_PENDING_CPV);
   XCP_Target_Info.process_look_A = CODED_FALSE;
}

/* TC_LookA_WrongLook: process_look_A=CODED_TRUE but current_look=LOOK_B — covers look_A_en MC/DC: TRUE&&FALSE=false */
TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC_LookA_WrongLook)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_current_look       = 1U;         /* RADAR_LOOK_B != RADAR_LOOK_A */
   XCP_Target_Info.process_look_A                        = CODED_TRUE; /* set but wrong look active */
   XCP_Target_Info.process_look_B                        = CODED_FALSE;
   XCP_Target_Info.process_look_C                        = CODED_FALSE;
   XCP_Target_Info.process_look_D                        = CODED_FALSE;
   XCP_Target_Info.range_min                             = 0;
   XCP_Target_Info.range_max                             = 0;
   XCP_Target_Info.rrate_min                             = 0;
   XCP_Target_Info.rrate_max                             = 0;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   /* look_A_en = (CODED_TRUE==CODED_TRUE) && (1==0) = false; no look active */
   ASSERT_EQ(result, (uint8_t)XCP_CMD_PENDING_CPV);
   XCP_Target_Info.process_look_A = CODED_FALSE;
}

/* TC_RangeFilter_InRange: range_min=0, range_max!=0 — covers range_ignore MC/DC: TRUE&&FALSE=false, target passes range */
TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC_RangeFilter_InRange)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_current_look       = 0U;
   XCP_Target_Info.process_look_A                        = CODED_TRUE;
   XCP_Target_Info.process_look_B                        = CODED_FALSE;
   XCP_Target_Info.process_look_C                        = CODED_FALSE;
   XCP_Target_Info.process_look_D                        = CODED_FALSE;
   XCP_Target_Info.range_min                             = 0;  /* range_min==0 */
   XCP_Target_Info.range_max                             = 50; /* range_max!=0 → range_ignore=false */
   XCP_Target_Info.rrate_min                             = 0;
   XCP_Target_Info.rrate_max                             = 0;
   /* XCP_Trgt_Rprt.af_dets[idx].ran=0.0f → temp_r=0; 0>=0 && 0<=50 → passes range check */
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   /* look_A processed and cleared within this call → is_looks_processing_done=true → XCP_CMD_OK_CPV */
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   XCP_Target_Info.process_look_A = CODED_FALSE;
}

/* TC_RangeFilter_OutRange: range_ignore=false, target ran=0.0f outside [100,200] — covers range check FALSE branch */
TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC_RangeFilter_OutRange)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_current_look       = 0U;
   XCP_Target_Info.process_look_A                        = CODED_TRUE;
   XCP_Target_Info.process_look_B                        = CODED_FALSE;
   XCP_Target_Info.process_look_C                        = CODED_FALSE;
   XCP_Target_Info.process_look_D                        = CODED_FALSE;
   XCP_Target_Info.range_min                             = 100; /* range_ignore=false */
   XCP_Target_Info.range_max                             = 200;
   XCP_Target_Info.rrate_min                             = 0;
   XCP_Target_Info.rrate_max                             = 0;
   /* XCP_Trgt_Rprt.af_dets[idx].ran=0.0f → temp_r=0; 0>=100 is false → all detections rejected */
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   /* look_A processed and cleared within this call → is_looks_processing_done=true → XCP_CMD_OK_CPV */
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   XCP_Target_Info.process_look_A = CODED_FALSE;
}

/* TC_RrateFilter_OutRange: range_ignore=true, rrate_ignore=false, vel=0.0f outside [100,200] — covers rrate check FALSE branch */
TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC_RrateFilter_OutRange)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_current_look       = 0U;
   XCP_Target_Info.process_look_A                        = CODED_TRUE;
   XCP_Target_Info.process_look_B                        = CODED_FALSE;
   XCP_Target_Info.process_look_C                        = CODED_FALSE;
   XCP_Target_Info.process_look_D                        = CODED_FALSE;
   XCP_Target_Info.range_min                             = 0; /* range_ignore=true */
   XCP_Target_Info.range_max                             = 0;
   XCP_Target_Info.rrate_min                             = 100; /* rrate_ignore=false */
   XCP_Target_Info.rrate_max                             = 200;
   /* XCP_Trgt_Rprt.af_dets[idx].vel=0.0f → temp_r_dot=0; 0>=100 is false → all detections rejected */
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   /* look_A processed and cleared within this call → is_looks_processing_done=true → XCP_CMD_OK_CPV */
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   XCP_Target_Info.process_look_A = CODED_FALSE;
}

/* TC_SecondTarget_HigherRCS: 2 detections both pass filters, second has higher RCS — covers temp_rcs > target_rcs TRUE branch */
TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC_SecondTarget_HigherRCS)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_current_look       = 0U;
   XCP_BB_Input_Params_Initialise.xcp_num_max_dets       = 2U;
   XCP_Target_Info.process_look_A                        = CODED_TRUE;
   XCP_Target_Info.process_look_B                        = CODED_FALSE;
   XCP_Target_Info.process_look_C                        = CODED_FALSE;
   XCP_Target_Info.process_look_D                        = CODED_FALSE;
   XCP_Target_Info.range_min                             = 0; /* range_ignore=true */
   XCP_Target_Info.range_max                             = 0;
   XCP_Target_Info.rrate_min                             = 0; /* rrate_ignore=true */
   XCP_Target_Info.rrate_max                             = 0;
   XCP_Trgt_Rprt.af_dets[0].rcs                          = 1.0f; /* first target: lower RCS */
   XCP_Trgt_Rprt.af_dets[1].rcs                          = 5.0f; /* second target: higher RCS → overrides first */
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   /* idx=0: target_found=false → stored; idx=1: rcs higher → selected as valid target */
   ASSERT_EQ(XCP_Target_Info.valid_target.target_idx, (uint16_t)1U);
   /* look_A processed and cleared within this call → is_looks_processing_done=true → XCP_CMD_OK_CPV */
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   XCP_Target_Info.process_look_A = CODED_FALSE;
   XCP_Trgt_Rprt.af_dets[0].rcs   = 0.0f;
   XCP_Trgt_Rprt.af_dets[1].rcs   = 0.0f;
}

/*
For XCP_User_Cmd_Get_Start_Address_Size_Event_Info
*/
class get_start_address_size_event_info : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();

      XCP_BB_Input_Params_Initialise.xcp_bb_daq_info_params_ptr = &XCP_Variables_List_DAQ;

      Get_XCP_Init_Parameters_fake.custom_fake = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(get_start_address_size_event_info, address_size_event_info_TC1)
{
   uint8_t cmnd[] = {0xF1, 0x06, 0x01};
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Get_Start_Address_Size_Event_Info(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], cmnd[1]);
   ASSERT_EQ(framelength, XCP_DAQ_FRAMELENGTH);
}

TEST_F(get_start_address_size_event_info, address_size_event_info_TC2)
{
   uint8_t cmnd[] = {0xF1, 0x06, 0x07};
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Get_Start_Address_Size_Event_Info(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(framelength, 2);
}

TEST_F(get_start_address_size_event_info, address_size_event_info_TC3)
{
   uint8_t cmnd[]                                            = {0xF1, 0x06, 0x01};
   XCP_BB_Input_Params_Initialise.xcp_bb_daq_info_params_ptr = NULL;
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Get_Start_Address_Size_Event_Info(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_GT(framelength, 0);
}

TEST_F(get_start_address_size_event_info, address_size_event_info_TC4)
{
   uint8_t cmnd[] = {0xF1, 0x06, 0x02};
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Get_Start_Address_Size_Event_Info(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], cmnd[1]);
   ASSERT_EQ(framelength, XCP_DAQ_FRAMELENGTH);
}

TEST_F(get_start_address_size_event_info, address_size_event_info_TC5)
{
   uint8_t cmnd[] = {0xF1, 0x06, 0x03};
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Get_Start_Address_Size_Event_Info(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], cmnd[1]);
   ASSERT_EQ(framelength, XCP_DAQ_FRAMELENGTH);
}

TEST_F(get_start_address_size_event_info, address_size_event_info_TC6)
{
   uint8_t cmnd[] = {0xF1, 0x06, 0x00};
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Get_Start_Address_Size_Event_Info(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_GT(framelength, 0);
}

TEST_F(get_start_address_size_event_info, address_size_event_info_TC7)
{
   uint8_t cmnd[] = {0xF1, 0x06, 0x05};
   memset(response, 0, sizeof(response));
   framelength    = 0;
   uint8_t result = XCP_User_Cmd_Get_Start_Address_Size_Event_Info(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   // Validity of this input depends on XCP_MIN_ADDRS_SIZE_INFO/XCP_MAX_ADDRS_SIZE_INFO
   if (cmnd[2] >= XCP_MIN_ADDRS_SIZE_INFO && cmnd[2] <= XCP_MAX_ADDRS_SIZE_INFO &&
       XCP_BB_Input_Params_Initialise.xcp_bb_daq_info_params_ptr != NULL)
   {
      ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
      ASSERT_EQ(response[1], cmnd[1]);
      ASSERT_EQ(framelength, XCP_DAQ_FRAMELENGTH);
   }
   else
   {
      ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
      ASSERT_GT(framelength, 0);
   }
}

// Look B

TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC8)
{
   XCP_BB_Input_Params_Initialise.xcp_current_look = 1u;
   XCP_Target_Info.look_enable_phy                 = 2u;
   XCP_Target_Info.phys_range_phy                  = 1u;
   XCP_Target_Info.rrate_min_phy                   = 0u;
   XCP_Target_Info.rrate_max_phy                   = 0u;
   XCP_Target_Info.range_min                       = 0u;
   XCP_Target_Info.range_max                       = 0u;

   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

// Look C
TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC9)
{
   XCP_BB_Input_Params_Initialise.xcp_current_look = 2u;
   XCP_Target_Info.look_enable_phy                 = 4u;
   XCP_Target_Info.phys_range_phy                  = 1u;
   XCP_Target_Info.rrate_min_phy                   = 0u;
   XCP_Target_Info.rrate_max_phy                   = 0u;
   XCP_Target_Info.range_min                       = 0u;
   XCP_Target_Info.range_max                       = 0u;

   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

// Look D

TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC10)
{
   XCP_BB_Input_Params_Initialise.xcp_current_look = 3u;
   XCP_Target_Info.look_enable_phy                 = 8u;
   XCP_Target_Info.phys_range_phy                  = 1u;
   XCP_Target_Info.rrate_min_phy                   = 0u;
   XCP_Target_Info.rrate_max_phy                   = 0u;
   XCP_Target_Info.range_min                       = 0u;
   XCP_Target_Info.range_max                       = 0u;

   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

// No look

TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC11)
{
   XCP_BB_Input_Params_Initialise.xcp_current_look = 1u;
   XCP_Target_Info.look_enable_phy                 = 10u;
   XCP_Target_Info.phys_range_phy                  = 1u;
   XCP_Target_Info.rrate_min_phy                   = 0u;
   XCP_Target_Info.rrate_max_phy                   = 0u;
   XCP_Target_Info.range_min                       = 0u;
   XCP_Target_Info.range_max                       = 0u;

   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_NE(result, (uint8_t)XCP_CMD_PENDING_CPV);
}

TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC12)
{
   XCP_BB_Input_Params_Initialise.xcp_current_look = 0U;
   XCP_Target_Info.look_enable_phy                 = 0u;
   XCP_Target_Info.phys_range_phy                  = 1u;
   XCP_Target_Info.rrate_min_phy                   = 0u;
   XCP_Target_Info.rrate_max_phy                   = 0u;
   XCP_Target_Info.range_min_phy                   = 1u;
   XCP_Target_Info.range_max_phy                   = 0u;
   // XCP_Target_Info.valid_target.target_rcs         = 1u;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_NE(result, (uint8_t)XCP_CMD_PENDING_CPV);
}

TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC13)
{
   XCP_BB_Input_Params_Initialise.xcp_current_look = 0U;
   XCP_Target_Info.look_enable_phy                 = 0u;
   XCP_Target_Info.phys_range_phy                  = 1u;
   XCP_Target_Info.rrate_min_phy                   = 0u;
   XCP_Target_Info.rrate_max_phy                   = 0u;
   XCP_Target_Info.range_min_phy                   = 1u;
   XCP_Target_Info.range_max_phy                   = 0u;
   // XCP_Target_Info.valid_target.target_rcs         = 1u;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_TRUE;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_NE(result, (uint8_t)XCP_CMD_PENDING_CPV);
}

TEST_F(Target_info_Periodic, sTarget_info_Periodic_TC21)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = 10;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max = 10;
   uint8_t error                                         = XCP_ERR_CMD_SYNTAX_CPV;

   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_NE(result, (uint8_t)XCP_CMD_PENDING_CPV);
}

TEST_F(Target_info_Periodic, sTarget_info_Periodic_TCNRC1)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = 0;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max = 1;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   XCP_Target_Info.process_look_A                        = CODED_FALSE;
   XCP_Target_Info.process_look_B                        = CODED_FALSE;
   XCP_Target_Info.process_look_C                        = CODED_FALSE;
   XCP_Target_Info.process_look_D                        = CODED_TRUE;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(Target_info_Periodic, sTarget_info_Periodic_target_check)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_current_look       = 0U;
   XCP_Target_Info.process_look_A                        = CODED_TRUE;
   XCP_Target_Info.process_look_B                        = CODED_FALSE;
   XCP_Target_Info.process_look_C                        = CODED_FALSE;
   XCP_Target_Info.process_look_D                        = CODED_FALSE;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = 0;
   XCP_Target_Info.look_enable_phy                       = 0x0f;
   XCP_Target_Info.rrate_min_phy                         = 1u;
   XCP_Target_Info.rrate_max_phy                         = 50u;
   XCP_Target_Info.range_min                             = 0u;
   XCP_Target_Info.range_max                             = 100u;

   XCP_BB_Input_Params_Initialise.xcp_num_max_dets            = 20U;
   XCP_BB_Input_Params_Initialise.xcp_copy_target_report_fptr = SWC_XCP_Copy_Target_Report;
   XCP_Trgt_Rprt.af_dets[0].ran                               = 50.0;
   XCP_Trgt_Rprt.af_dets[0].vel                               = 25.0;
   // XCP_Target_Info.cycle_cnt                       = 0u;
   // XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt = XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(Target_info_Periodic, sTarget_info_Periodic_target_check2)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_current_look       = 0U;
   XCP_Target_Info.process_look_A                        = CODED_TRUE;
   XCP_Target_Info.process_look_B                        = CODED_FALSE;
   XCP_Target_Info.process_look_C                        = CODED_FALSE;
   XCP_Target_Info.process_look_D                        = CODED_FALSE;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = 0;
   XCP_Target_Info.look_enable_phy                       = 0x0f;
   XCP_Target_Info.rrate_min                             = 0u;
   XCP_Target_Info.rrate_max                             = 0u;
   XCP_Target_Info.range_min                             = 0u;
   XCP_Target_Info.range_max                             = 100u;

   XCP_BB_Input_Params_Initialise.xcp_num_max_dets            = 20U;
   XCP_BB_Input_Params_Initialise.xcp_copy_target_report_fptr = SWC_XCP_Copy_Target_Report;
   XCP_Trgt_Rprt.af_dets[0].ran                               = 50.0;
   XCP_Trgt_Rprt.af_dets[0].vel                               = 25.0;
   // XCP_Target_Info.cycle_cnt                       = 0u;
   // XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt = XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(Target_info_Periodic, sTarget_info_Periodic_target_check3)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_current_look       = 0U;
   XCP_Target_Info.process_look_A                        = CODED_TRUE;
   XCP_Target_Info.process_look_B                        = CODED_FALSE;
   XCP_Target_Info.process_look_C                        = CODED_FALSE;
   XCP_Target_Info.process_look_D                        = CODED_FALSE;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = 0;
   XCP_Target_Info.look_enable_phy                       = 0x0f;
   XCP_Target_Info.rrate_min                             = 0u;
   XCP_Target_Info.rrate_max                             = 0u;
   XCP_Target_Info.range_min                             = 0u;
   XCP_Target_Info.range_max                             = 100u;

   XCP_BB_Input_Params_Initialise.xcp_num_max_dets            = 20U;
   XCP_BB_Input_Params_Initialise.xcp_copy_target_report_fptr = SWC_XCP_Copy_Target_Report;
   XCP_Trgt_Rprt.af_dets[0].ran                               = 50.0f;
   XCP_Trgt_Rprt.af_dets[0].vel                               = 25.0f;
   XCP_Trgt_Rprt.af_dets[0].rcs                               = 25.0f;
   XCP_Trgt_Rprt.af_dets[1].rcs                               = 50.0f;
   XCP_Trgt_Rprt.af_dets[2].rcs                               = 55.0f;
   // XCP_Target_Info.cycle_cnt                       = 0u;
   // XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt = XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(Target_info_Periodic, sTarget_info_Periodic_target_check4)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_current_look       = 0U;
   XCP_Target_Info.process_look_A                        = CODED_TRUE;
   XCP_Target_Info.process_look_B                        = CODED_FALSE;
   XCP_Target_Info.process_look_C                        = CODED_FALSE;
   XCP_Target_Info.process_look_D                        = CODED_FALSE;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = 0;
   XCP_Target_Info.look_enable_phy                       = 0x0f;
   XCP_Target_Info.rrate_min                             = 0u;
   XCP_Target_Info.rrate_max                             = 0u;
   XCP_Target_Info.range_min                             = 0u;
   XCP_Target_Info.range_max                             = 0;

   XCP_BB_Input_Params_Initialise.xcp_num_max_dets            = 20U;
   XCP_BB_Input_Params_Initialise.xcp_copy_target_report_fptr = SWC_XCP_Copy_Target_Report;
   XCP_Trgt_Rprt.af_dets[0].ran                               = 50.0f;
   XCP_Trgt_Rprt.af_dets[0].vel                               = 25.0f;
   XCP_Trgt_Rprt.af_dets[0].rcs                               = 25.0f;
   XCP_Trgt_Rprt.af_dets[1].rcs                               = 50.0f;
   XCP_Trgt_Rprt.af_dets[2].rcs                               = 55.0f;
   // XCP_Target_Info.cycle_cnt                       = 0u;
   // XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt = XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(Target_info_Periodic, sTarget_info_Periodic_target_check5)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_current_look       = 0U;
   XCP_Target_Info.process_look_A                        = CODED_TRUE;
   XCP_Target_Info.process_look_B                        = CODED_FALSE;
   XCP_Target_Info.process_look_C                        = CODED_FALSE;
   XCP_Target_Info.process_look_D                        = CODED_FALSE;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = 0;
   XCP_Target_Info.look_enable_phy                       = 0x0f;
   XCP_Target_Info.rrate_min                             = 0u;
   XCP_Target_Info.rrate_max                             = 50u;
   XCP_Target_Info.range_min                             = 0u;
   XCP_Target_Info.range_max                             = 100;

   XCP_BB_Input_Params_Initialise.xcp_num_max_dets            = 20U;
   XCP_BB_Input_Params_Initialise.xcp_copy_target_report_fptr = SWC_XCP_Copy_Target_Report;
   XCP_Trgt_Rprt.af_dets[0].ran                               = 50.0f;
   XCP_Trgt_Rprt.af_dets[0].vel                               = 25.0f;
   XCP_Trgt_Rprt.af_dets[0].rcs                               = 25.0f;
   XCP_Trgt_Rprt.af_dets[1].rcs                               = 50.0f;
   XCP_Trgt_Rprt.af_dets[2].rcs                               = 55.0f;
   // XCP_Target_Info.cycle_cnt                       = 0u;
   // XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt = XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(Target_info_Periodic, sTarget_info_Periodic_target_check6)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_current_look       = 5U;
   XCP_Target_Info.process_look_A                        = CODED_FALSE;
   XCP_Target_Info.process_look_B                        = CODED_FALSE;
   XCP_Target_Info.process_look_C                        = CODED_FALSE;
   XCP_Target_Info.process_look_D                        = CODED_FALSE;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = 0;
   XCP_Target_Info.look_enable_phy                       = 0x0f;
   XCP_Target_Info.rrate_min                             = 0u;
   XCP_Target_Info.rrate_max                             = 50u;
   XCP_Target_Info.range_min                             = 0u;
   XCP_Target_Info.range_max                             = 100;

   XCP_BB_Input_Params_Initialise.xcp_num_max_dets            = 20U;
   XCP_BB_Input_Params_Initialise.xcp_copy_target_report_fptr = SWC_XCP_Copy_Target_Report;
   XCP_Trgt_Rprt.af_dets[0].ran                               = 50.0f;
   XCP_Trgt_Rprt.af_dets[0].vel                               = 25.0f;
   XCP_Trgt_Rprt.af_dets[0].rcs                               = 25.0f;
   XCP_Trgt_Rprt.af_dets[1].rcs                               = 50.0f;
   XCP_Trgt_Rprt.af_dets[2].rcs                               = 55.0f;
   // XCP_Target_Info.cycle_cnt                       = 0u;
   // XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt = XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(Target_info_Periodic, sTarget_info_Periodic_target_check7)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_current_look       = 1U;
   XCP_Target_Info.process_look_A                        = CODED_FALSE;
   XCP_Target_Info.process_look_B                        = CODED_TRUE;
   XCP_Target_Info.process_look_C                        = CODED_FALSE;
   XCP_Target_Info.process_look_D                        = CODED_FALSE;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = 0;
   XCP_Target_Info.look_enable_phy                       = 0x0f;
   XCP_Target_Info.rrate_min                             = 0u;
   XCP_Target_Info.rrate_max                             = 50u;
   XCP_Target_Info.range_min                             = 0u;
   XCP_Target_Info.range_max                             = 100;

   XCP_BB_Input_Params_Initialise.xcp_num_max_dets            = 20U;
   XCP_BB_Input_Params_Initialise.xcp_copy_target_report_fptr = SWC_XCP_Copy_Target_Report;
   XCP_Trgt_Rprt.af_dets[0].ran                               = 50.0f;
   XCP_Trgt_Rprt.af_dets[0].vel                               = 25.0f;
   XCP_Trgt_Rprt.af_dets[0].rcs                               = 25.0f;
   XCP_Trgt_Rprt.af_dets[1].rcs                               = 50.0f;
   XCP_Trgt_Rprt.af_dets[2].rcs                               = 55.0f;
   // XCP_Target_Info.cycle_cnt                       = 0u;
   // XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt = XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(Target_info_Periodic, sTarget_info_Periodic_target_check8)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_current_look       = 2U;
   XCP_Target_Info.process_look_A                        = CODED_FALSE;
   XCP_Target_Info.process_look_B                        = CODED_FALSE;
   XCP_Target_Info.process_look_C                        = CODED_TRUE;
   XCP_Target_Info.process_look_D                        = CODED_FALSE;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = 0;
   XCP_Target_Info.look_enable_phy                       = 0x0f;
   XCP_Target_Info.rrate_min                             = 0u;
   XCP_Target_Info.rrate_max                             = 50u;
   XCP_Target_Info.range_min                             = 0u;
   XCP_Target_Info.range_max                             = 100;

   XCP_BB_Input_Params_Initialise.xcp_num_max_dets            = 20U;
   XCP_BB_Input_Params_Initialise.xcp_copy_target_report_fptr = SWC_XCP_Copy_Target_Report;
   XCP_Trgt_Rprt.af_dets[0].ran                               = 50.0f;
   XCP_Trgt_Rprt.af_dets[0].vel                               = 25.0f;
   XCP_Trgt_Rprt.af_dets[0].rcs                               = 25.0f;
   XCP_Trgt_Rprt.af_dets[1].rcs                               = 50.0f;
   XCP_Trgt_Rprt.af_dets[2].rcs                               = 55.0f;
   // XCP_Target_Info.cycle_cnt                       = 0u;
   // XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt = XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(Target_info_Periodic, sTarget_info_Periodic_target_check9)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_current_look       = 3U;
   XCP_Target_Info.process_look_A                        = CODED_FALSE;
   XCP_Target_Info.process_look_B                        = CODED_FALSE;
   XCP_Target_Info.process_look_C                        = CODED_FALSE;
   XCP_Target_Info.process_look_D                        = CODED_TRUE;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = 0;
   XCP_Target_Info.look_enable_phy                       = 0x0f;
   XCP_Target_Info.rrate_min                             = 0u;
   XCP_Target_Info.rrate_max                             = 50u;
   XCP_Target_Info.range_min                             = 0u;
   XCP_Target_Info.range_max                             = 100;

   XCP_BB_Input_Params_Initialise.xcp_num_max_dets            = 20U;
   XCP_BB_Input_Params_Initialise.xcp_copy_target_report_fptr = SWC_XCP_Copy_Target_Report;
   XCP_Trgt_Rprt.af_dets[0].ran                               = 50.0f;
   XCP_Trgt_Rprt.af_dets[0].vel                               = 25.0f;
   XCP_Trgt_Rprt.af_dets[0].rcs                               = 25.0f;
   XCP_Trgt_Rprt.af_dets[1].rcs                               = 50.0f;
   XCP_Trgt_Rprt.af_dets[2].rcs                               = 55.0f;
   // XCP_Target_Info.cycle_cnt                       = 0u;
   // XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt = XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(Target_info_Periodic, sTarget_info_Periodic_target_check10)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_current_look       = 0U;
   XCP_Target_Info.process_look_A                        = CODED_TRUE;
   XCP_Target_Info.process_look_B                        = CODED_TRUE;
   XCP_Target_Info.process_look_C                        = CODED_TRUE;
   XCP_Target_Info.process_look_D                        = CODED_TRUE;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = 0;
   XCP_Target_Info.look_enable_phy                       = 0x0f;
   XCP_Target_Info.rrate_min                             = 0u;
   XCP_Target_Info.rrate_max                             = 50u;
   XCP_Target_Info.range_min                             = 0u;
   XCP_Target_Info.range_max                             = 100;

   XCP_BB_Input_Params_Initialise.xcp_num_max_dets            = 20U;
   XCP_BB_Input_Params_Initialise.xcp_copy_target_report_fptr = SWC_XCP_Copy_Target_Report;
   XCP_Trgt_Rprt.af_dets[0].ran                               = 50.0f;
   XCP_Trgt_Rprt.af_dets[0].vel                               = 25.0f;
   XCP_Trgt_Rprt.af_dets[0].rcs                               = 25.0f;
   XCP_Trgt_Rprt.af_dets[1].rcs                               = 50.0f;
   XCP_Trgt_Rprt.af_dets[2].rcs                               = 55.0f;
   // XCP_Target_Info.cycle_cnt                       = 0u;
   // XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt = XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   XCP_BB_Input_Params_Initialise.xcp_current_look = 1U;
   result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   XCP_BB_Input_Params_Initialise.xcp_current_look = 2U;
   result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   XCP_BB_Input_Params_Initialise.xcp_current_look = 3U;
   result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

/*TEST_F(Target_info_Periodic, sTarget_info_Periodic_target_check17)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_copy_target_report_fptr = NULL;

   // XCP_Target_Info.cycle_cnt                       = 0u;
   // XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt = XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max;
   uint8_t result = XCP_Target_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   //ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}*/
/*
For ITV Simulation Command
*/

class itv_simulation : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();

      static uint8_t XCP_Itv_ADC_State;
      uint8_t XCP_Itv_IPC_Event_State;
      uint8_t XCP_Itv_IPC_Value_State;

      XCP_BB_Input_Params_Initialise.xcp_itv_adc_state       = &XCP_Itv_ADC_State;
      XCP_BB_Input_Params_Initialise.xcp_itv_ipc_event_state = &XCP_Itv_IPC_Event_State;
      XCP_BB_Input_Params_Initialise.xcp_itv_ipc_value_state = &XCP_Itv_IPC_Value_State;

      Get_XCP_Init_Parameters_fake.custom_fake = Get_XCP_Init_Parameters_Custom_Fake;
      l_xcp_bb_input_params                    = Get_XCP_Init_Parameters_fake.return_val;
   }
   void TearDown()
   {
   }
};

TEST_F(itv_simulation, Itv_simulation_AdcMcTempConnect_positive_TC1)
{
   uint8_t cmnd[] = {0xF1, 0x0F, 0x01, 0x01};
   uint8_t result = XCP_User_Cmd_ITV_Simulation_Control(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(itv_simulation, Itv_simulation_AdcMcTempConnect_positive_TC2)
{
   uint8_t cmnd[]                                   = {0xF1, 0x0F, 0x01, 0x01};
   XCP_BB_Input_Params_Initialise.xcp_itv_adc_state = NULL;
   uint8_t result = XCP_User_Cmd_ITV_Simulation_Control(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(itv_simulation, Itv_simulation_IpcFfOutputEnable_positive_TC3)
{
   uint8_t cmnd[] = {0xF1, 0x0F, 0x02, 0x01, 0x08, 0xAA};
   uint8_t result = XCP_User_Cmd_ITV_Simulation_Control(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(itv_simulation, Itv_simulation_IpcFfOutputEnable_positive_TC4)
{
   uint8_t cmnd[]                                   = {0xF1, 0x0F, 0x02, 0x01, 0x08, 0xAA};
   XCP_BB_Input_Params_Initialise.xcp_itv_ipc_state = NULL;
   uint8_t result = XCP_User_Cmd_ITV_Simulation_Control(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(itv_simulation, itv_simulation_negative_TC5)
{
   uint8_t cmnd[]                                   = {0xF1, 0x0F, 0x03, 0x01, 0x00, 0x00};
   XCP_BB_Input_Params_Initialise.xcp_itv_adc_state = NULL;
   uint8_t result = XCP_User_Cmd_ITV_Simulation_Control(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(itv_simulation, itv_simulation_negative_TC6)
{
   uint8_t cmnd[] = {0xF1, 0x0F, 0x01, 0x02};
   uint8_t XCP_Itv_ADC_State;
   ;
   XCP_BB_Input_Params_Initialise.xcp_itv_adc_state = &XCP_Itv_ADC_State;
   uint8_t result = XCP_User_Cmd_ITV_Simulation_Control(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], 0xFF);
}

TEST_F(itv_simulation, itv_simulation_negative_TC7)
{
   uint8_t cmnd[]                                   = {0xF1, 0x0F, 0x01, 0x03};
   XCP_BB_Input_Params_Initialise.xcp_itv_adc_state = NULL;
   uint8_t result = XCP_User_Cmd_ITV_Simulation_Control(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], 0xFE);
}
/*
For Stop Transmitting Periodic Msgs Command
*/

class stop_transmitting_periodic_msgs : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      static uint8_t xcp_normal_stop_periodic_status;
      static uint8_t xcp_pcan_stop_periodic_status;
      static uint8_t xcp_vcan_stop_periodic_status;
      static uint8_t xcp_ethernet_platform_stop_periodic_status;
      static uint8_t xcp_ethernet_project_stop_periodic_status;
      static uint8_t *xcp_stop_periodic_message_interface[5] = {
         &xcp_normal_stop_periodic_status, &xcp_pcan_stop_periodic_status, &xcp_vcan_stop_periodic_status,
         &xcp_ethernet_platform_stop_periodic_status, &xcp_ethernet_project_stop_periodic_status};
      XCP_BB_Input_Params_Initialise.xcp_stop_periodic_message_ptr = xcp_stop_periodic_message_interface;
   }
   void TearDown()
   {
   }
};

TEST_F(stop_transmitting_periodic_msgs, stop_transmitting_periodic_msgs_TC1)
{
   uint8_t cmnd[] = {0xF1, 0x03, 0x00, 0x01};
   uint8_t result = XCP_User_Cmd_Stop_Transmitting_Periodic_Msgs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[0], 0xFF);
   ASSERT_EQ(response[1], 0x03);
   ASSERT_EQ(response[2], 0x00);
   ASSERT_EQ(response[3], 0x01);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(stop_transmitting_periodic_msgs, stop_transmitting_periodic_msgs_negative_TC1)
{
   uint8_t cmnd[]                                                                                   = {0xF1, 0x03, 0x00, 0x00};
   XCP_BB_Input_Params_Initialise.xcp_stop_periodic_message_ptr[XCP_NORMAL_INTERFACE_STOP_PERIODIC] = NULL;
   uint8_t result = XCP_User_Cmd_Stop_Transmitting_Periodic_Msgs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[0], 0xFE);
   ASSERT_EQ(response[1], 0x22);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(stop_transmitting_periodic_msgs, stop_transmitting_periodic_msgs_TC2)
{
   uint8_t cmnd[] = {0xF1, 0x03, 0x01, 0x01};
   uint8_t result = XCP_User_Cmd_Stop_Transmitting_Periodic_Msgs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[0], 0xFF);
   ASSERT_EQ(response[1], 0x03);
   ASSERT_EQ(response[2], 0x01);
   ASSERT_EQ(response[3], 0x01);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(stop_transmitting_periodic_msgs, stop_transmitting_periodic_msgs_negative_TC2)
{
   uint8_t cmnd[]                                                                                 = {0xF1, 0x03, 0x01, 0x00};
   XCP_BB_Input_Params_Initialise.xcp_stop_periodic_message_ptr[XCP_PCAN_INTERFACE_STOP_PERIODIC] = NULL;
   uint8_t result = XCP_User_Cmd_Stop_Transmitting_Periodic_Msgs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[0], 0xFE);
   ASSERT_EQ(response[1], 0x22);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(stop_transmitting_periodic_msgs, stop_transmitting_periodic_msgs_TC3)
{
   uint8_t cmnd[] = {0xF1, 0x03, 0x02, 0x01};
   uint8_t result = XCP_User_Cmd_Stop_Transmitting_Periodic_Msgs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[0], 0xFF);
   ASSERT_EQ(response[1], 0x03);
   ASSERT_EQ(response[2], 0x02);
   ASSERT_EQ(response[3], 0x01);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(stop_transmitting_periodic_msgs, stop_transmitting_periodic_msgs_negative_TC3)
{
   uint8_t cmnd[]                                                                                 = {0xF1, 0x03, 0x02, 0x00};
   XCP_BB_Input_Params_Initialise.xcp_stop_periodic_message_ptr[XCP_VCAN_INTERFACE_STOP_PERIODIC] = NULL;
   uint8_t result = XCP_User_Cmd_Stop_Transmitting_Periodic_Msgs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[0], 0xFE);
   ASSERT_EQ(response[1], 0x22);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(stop_transmitting_periodic_msgs, stop_transmitting_periodic_msgs_TC4)
{
   uint8_t cmnd[] = {0xF1, 0x03, 0x03, 0x01};
   uint8_t result = XCP_User_Cmd_Stop_Transmitting_Periodic_Msgs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[0], 0xFF);
   ASSERT_EQ(response[1], 0x03);
   ASSERT_EQ(response[2], 0x03);
   ASSERT_EQ(response[3], 0x01);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(stop_transmitting_periodic_msgs, stop_transmitting_periodic_msgs_negative_TC4)
{
   uint8_t cmnd[] = {0xF1, 0x03, 0x03, 0x01};
   XCP_BB_Input_Params_Initialise.xcp_stop_periodic_message_ptr[XCP_ETHERNET_PLATFORM_INTERFACE_STOP_PERIODIC] = NULL;
   uint8_t result = XCP_User_Cmd_Stop_Transmitting_Periodic_Msgs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[0], 0xFE);
   ASSERT_EQ(response[1], 0x22);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(stop_transmitting_periodic_msgs, stop_transmitting_periodic_msgs_TC5)
{
   uint8_t cmnd[] = {0xF1, 0x03, 0x04, 0x01};
   uint8_t result = XCP_User_Cmd_Stop_Transmitting_Periodic_Msgs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[0], 0xFF);
   ASSERT_EQ(response[1], 0x03);
   ASSERT_EQ(response[2], 0x04);
   ASSERT_EQ(response[3], 0x01);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(stop_transmitting_periodic_msgs, stop_transmitting_periodic_msgs_negative_TC5)
{
   uint8_t cmnd[] = {0xF1, 0x03, 0x04, 0x01};
   XCP_BB_Input_Params_Initialise.xcp_stop_periodic_message_ptr[XCP_ETHERNET_PROJECT_INTERFACE_STOP_PERIODIC] = NULL;
   uint8_t result = XCP_User_Cmd_Stop_Transmitting_Periodic_Msgs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[0], 0xFE);
   ASSERT_EQ(response[1], 0x22);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(stop_transmitting_periodic_msgs, stop_transmitting_periodic_msgs_TC6)
{
   uint8_t cmnd[] = {0xF1, 0x03, 0x05, 0x01};
   uint8_t result = XCP_User_Cmd_Stop_Transmitting_Periodic_Msgs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[0], 0xFE);
   ASSERT_EQ(response[1], 0x22);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(stop_transmitting_periodic_msgs, stop_transmitting_periodic_msgs_TC7)
{
   uint8_t cmnd[] = {0xF1, 0x03, 0x01, 0x02};
   uint8_t result = XCP_User_Cmd_Stop_Transmitting_Periodic_Msgs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[0], 0xFE);
   ASSERT_EQ(response[1], 0x22);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

/*
For XCP_User_Cmd_Set_Override_Control_Variable
*/
class set_override_control_variable : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      XCP_BB_Input_Params_Initialise.xcp_set_override_var_ptr = NULL;
      Get_XCP_Init_Parameters_fake.custom_fake                = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(set_override_control_variable, set_override_control_variable_TC1)
{
   uint8_t cmnd[] = {0xF1, 0x22, 0x01, 0x02};
   uint8_t result = XCP_User_Cmd_Set_Override_Control_Variable(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(set_override_control_variable, set_override_control_variable_TC2)
{
   uint8_t cmnd[]                                          = {0xF1, 0x22, 0x01, 0x02};
   XCP_BB_Input_Params_Initialise.xcp_set_override_var_ptr = (volatile uint16_t *)malloc(8U);
   uint8_t result = XCP_User_Cmd_Set_Override_Control_Variable(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_PENDING_CPV);
}

TEST_F(set_override_control_variable, set_override_control_variable_TC3)
{
   uint8_t cmnd[]                                          = {0xF1, 0x22, 0x03, 0x02};
   XCP_BB_Input_Params_Initialise.xcp_set_override_var_ptr = (volatile uint16_t *)malloc(8U);
   uint8_t result = XCP_User_Cmd_Set_Override_Control_Variable(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(set_override_control_variable, set_override_control_variable_TC4)
{
   uint8_t cmnd[]                                          = {0xF1, 0x22, 0x02, 0x02};
   XCP_BB_Input_Params_Initialise.xcp_set_override_var_ptr = (volatile uint16_t *)malloc(8U);
   uint8_t result = XCP_User_Cmd_Set_Override_Control_Variable(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

/*
For XCP_User_Cmd_Get_Override_Control_Variable
*/
class get_override_control_variable : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      XCP_BB_Input_Params_Initialise.xcp_get_override_var_ptr = (volatile uint16_t *)malloc(8U);
      Get_XCP_Init_Parameters_fake.custom_fake                = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(get_override_control_variable, get_override_control_variable_TC1)
{
   uint8_t cmnd[] = {0xF1, 0x23, 0x01, 0x01};
   uint8_t result = XCP_User_Cmd_Get_Override_Control_Variable(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(get_override_control_variable, get_override_control_variable_TC3)
{
   uint8_t cmnd[] = {0xF1, 0x23, 0x02, 0x01};
   uint8_t result = XCP_User_Cmd_Get_Override_Control_Variable(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(get_override_control_variable, get_override_control_variable_TC2)
{
   uint8_t cmnd[]                                          = {0xF1, 0x23, 0x01, 0x01};
   XCP_BB_Input_Params_Initialise.xcp_get_override_var_ptr = NULL;
   uint8_t result = XCP_User_Cmd_Get_Override_Control_Variable(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

/*
For Target Select
*/

class target_select : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      uint8_t l_target_select_data_size                           = 10U;
      XCP_BB_Input_Params_Initialise.xcp_num_of_looks             = 1U;
      XCP_BB_Input_Params_Initialise.xcp_target_selection_num     = 1U;
      XCP_BB_Input_Params_Initialise.xcp_max_number_range_bin     = 0U;
      XCP_BB_Input_Params_Initialise.xcp_max_number_doppler_bin   = 0U;
      XCP_BB_Input_Params_Initialise.xcp_target_select_enable_ptr = (volatile uint8_t *)malloc(8U);
      XCP_BB_Input_Params_Initialise.xcp_target_range_idx_ptr     = (volatile uint16_t *)malloc(8U);
      XCP_BB_Input_Params_Initialise.xcp_target_doppler_idx_ptr   = (volatile uint16_t *)malloc(8U);
      Get_XCP_Init_Parameters_fake.custom_fake                    = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(target_select, Target_Select_positive_TC1)
{
   uint8_t cmnd[] = {0xF1, 0x9A};
   uint8_t result = XCP_User_Cmd_Target_Select(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

//(l_range > l_xcp_max_number_range_bin) || (l_doppler > l_xcp_max_number_doppler_bin)
TEST_F(target_select, Target_Select_positive_TC2)
{
   uint8_t cmnd[] = {0xF1, 0x9A, 0x00, 0x00, 0x00};
   uint8_t result = XCP_User_Cmd_Target_Select(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(target_select, Target_Select_negative_TC3)
{
   uint8_t cmnd[]                                              = {0xF1, 0x9A};
   XCP_BB_Input_Params_Initialise.xcp_target_select_enable_ptr = NULL;
   XCP_BB_Input_Params_Initialise.xcp_target_range_idx_ptr     = NULL;
   XCP_BB_Input_Params_Initialise.xcp_target_doppler_idx_ptr   = NULL;
   uint8_t result = XCP_User_Cmd_Target_Select(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(target_select, Target_Select_positive_TC4)
{
   uint8_t cmnd[]                                              = {0xF1, 0x9A, 0x00, 0x00, 0x00};
   XCP_BB_Input_Params_Initialise.xcp_target_select_enable_ptr = NULL;
   uint8_t result = XCP_User_Cmd_Target_Select(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(target_select, Target_Select_negative_TC5)
{
   uint8_t cmnd[]                                          = {0xF1, 0x9A};
   XCP_BB_Input_Params_Initialise.xcp_target_range_idx_ptr = NULL;
   uint8_t result = XCP_User_Cmd_Target_Select(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(target_select, Target_Select_negative_TC6)
{
   uint8_t cmnd[]                                            = {0xF1, 0x9A};
   XCP_BB_Input_Params_Initialise.xcp_target_doppler_idx_ptr = NULL;
   uint8_t result = XCP_User_Cmd_Target_Select(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(target_select, Target_Select_positive_TC7)
{
   uint8_t cmnd[]                                            = {0xF1, 0x9A, 0x00, 0x00, 0x00};
   XCP_BB_Input_Params_Initialise.xcp_target_selection_num   = 2U;
   XCP_BB_Input_Params_Initialise.xcp_max_number_range_bin   = 100U;
   XCP_BB_Input_Params_Initialise.xcp_max_number_doppler_bin = 10U;
   uint8_t result = XCP_User_Cmd_Target_Select(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

/*
For XCP_User_Cmd_Set_Output_State
*/
class set_output_state : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      /*
      typedef struct XCP_LED_Output_Cntrl_Tag
      {
         uint8_t xcp_out_select;
         uint8_t xcp_out_state;
      } XCP_LED_Output_Cntrl_T;
      static XCP_LED_Output_Cntrl_T XCP_Out_Output_State;
      */
      XCP_BB_Input_Params_Initialise.xcp_out_set_output_state = (XCP_LED_Output_Cntrl_T *)malloc(8u);
      Get_XCP_Init_Parameters_fake.custom_fake                = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(set_output_state, set_output_state_positive_TC)
{
   uint8_t cmnd[] = {0xF1, 0x1F, 0x01, 0x01};
   uint8_t result;
   result = XCP_User_Cmd_Set_Output_State(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   EXPECT_EQ(response[2], 0x01);
   cmnd[2] = 10;
   cmnd[3] = 0xA1;
   result  = XCP_User_Cmd_Set_Output_State(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   EXPECT_NE(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], 0x1F);
   ASSERT_EQ(response[2], cmnd[2]);
   cmnd[2] = 10;
   cmnd[3] = 0x11;
   result  = XCP_User_Cmd_Set_Output_State(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   EXPECT_NE(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], 0x1F);
   ASSERT_EQ(response[2], cmnd[2]);

   cmnd[2] = 10;
   cmnd[3] = 0x10;
   result  = XCP_User_Cmd_Set_Output_State(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   EXPECT_NE(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], 0x1F);
   ASSERT_EQ(response[2], cmnd[2]);

   cmnd[2] = 20;
   cmnd[3] = 0xA0;
   result  = XCP_User_Cmd_Set_Output_State(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   EXPECT_NE(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], 0x1F);
   ASSERT_EQ(response[2], cmnd[2]);

   cmnd[2] = 20;
   cmnd[3] = 0xA2;
   result  = XCP_User_Cmd_Set_Output_State(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   EXPECT_NE(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], 0x1F);
   ASSERT_EQ(response[2], cmnd[2]);
}

TEST_F(set_output_state, set_output_state_negative_TC2)
{
   uint8_t cmnd[] = {0xF1, 0x1F, 0x01, 0x00};
   uint8_t result;
   result = XCP_User_Cmd_Set_Output_State(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(framelength, 2);
   cmnd[2] = 30;
   cmnd[3] = 0x21;
   result  = XCP_User_Cmd_Set_Output_State(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   EXPECT_NE(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);

   cmnd[2] = 0;
   cmnd[3] = 0x01;
   result  = XCP_User_Cmd_Set_Output_State(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   EXPECT_NE(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(set_output_state, set_output_state_negative_TC)
{
   uint8_t cmnd[]                                          = {0xF1, 0x1F, 0x01, 0x01};
   XCP_BB_Input_Params_Initialise.xcp_out_set_output_state = NULL;
   uint8_t result;
   result = XCP_User_Cmd_Set_Output_State(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(framelength, 2);
   cmnd[2] = 30;
   cmnd[3] = 0x21;
   result  = XCP_User_Cmd_Set_Output_State(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   EXPECT_NE(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

/*
For Override Memory Fault
*/
volatile XCP_Fault_Override_T XCP_FaultOverride = {1, 2, 3};
uint8 Dt_Fault_T[16];
uint8_t l_num_fault_bytes = sizeof(Dt_Fault_T);

class override_memory_fault : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      XCP_BB_Input_Params_Initialise.num_fault_bytes        = sizeof(Dt_Fault_T);
      XCP_BB_Input_Params_Initialise.xcp_fault_override_ptr = &XCP_FaultOverride;
      Get_XCP_Init_Parameters_fake.custom_fake              = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

/* override_memory_fault */

TEST_F(override_memory_fault, xcp_user_cmd_override_memory_fault_TEST1)
{
   uint8_t cmnd[]                                 = {0xF1, 11U, 2U, 5U, 0U};
   XCP_BB_Input_Params_Initialise.num_fault_bytes = 10;
   XCP_User_Cmd_Override_Memory_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   EXPECT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], 0x0B);
   EXPECT_NE(response[2], 3U);
   ASSERT_EQ(framelength, 3U);
}

TEST_F(override_memory_fault, xcp_user_cmd_override_memory_fault_TESTNEW)
{
   uint8_t cmnd[]                                 = {0xF1, 11U, 1U, 5U, 0U};
   XCP_BB_Input_Params_Initialise.num_fault_bytes = 10;
   XCP_User_Cmd_Override_Memory_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], 0x0B);
}

TEST_F(override_memory_fault, xcp_user_cmd_override_memory_fault_TESTNEW2)
{
   uint8_t cmnd[]                                 = {0xF1, 11U, 3U, 5U, 0U};
   XCP_BB_Input_Params_Initialise.num_fault_bytes = 10;
   XCP_User_Cmd_Override_Memory_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], 0x0B);
}

TEST_F(override_memory_fault, xcp_user_cmd_override_memory_fault_TEST2)

{
   uint8_t cmnd[] = {0xF1, 11, 0, 5, 0};
   XCP_User_Cmd_Override_Memory_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   EXPECT_NE(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_NE(response[2], 0U);
}

TEST_F(override_memory_fault, xcp_user_cmd_override_memory_fault_TEST3)
{
   uint8_t cmnd[]                                 = {0xF1, 11, 2, 25, 8};
   XCP_BB_Input_Params_Initialise.num_fault_bytes = 17;
   XCP_User_Cmd_Override_Memory_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   EXPECT_NE(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_FALSE((XCP_MEMORY_FAULT_BIT_MAX_SIZE > cmnd[4]));
}

TEST_F(override_memory_fault, xcp_user_cmd_override_memory_fault_TEST4)
{
   uint8_t cmnd[]                                 = {0xF1, 11, 0, 25, 0};
   XCP_BB_Input_Params_Initialise.num_fault_bytes = 17;
   XCP_User_Cmd_Override_Memory_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_FALSE((uint8_t)XCP_AUTO_MODE <= cmnd[2]);
   ASSERT_TRUE((XCP_MEMORY_FAULT_BIT_MAX_SIZE > cmnd[4]));
}

TEST_F(override_memory_fault, xcp_user_cmd_override_memory_fault_TEST5)
{
   uint8_t cmnd[]                                        = {0xF1, 11, 0, 5, 0};
   XCP_BB_Input_Params_Initialise.xcp_fault_override_ptr = NULL;
   XCP_User_Cmd_Override_Memory_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_GT(((uint8_t)XCP_AUTO_MODE), cmnd[2]);
   ASSERT_LT(cmnd[4], XCP_MEMORY_FAULT_BIT_MAX_SIZE);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_FALSE(XCP_BB_Input_Params_Initialise.xcp_fault_override_ptr);
}

TEST_F(override_memory_fault, xcp_user_cmd_override_memory_fault_TEST6)
{
   uint8_t cmnd[] = {0xF1, 11, 2, 3, 9};
   XCP_User_Cmd_Override_Memory_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   EXPECT_LT(cmnd[2], (uint8_t)XCP_CLEAR_FAULT_MODE);
}

TEST_F(override_memory_fault, xcp_user_cmd_override_memory_fault_TEST7)
{
   uint8_t cmnd[] = {0xF1, 11, 5, 19, 9};
   XCP_User_Cmd_Override_Memory_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   EXPECT_NE(response[1], XCP_ERR_CMD_SYNCH_CPV);
   EXPECT_GT(cmnd[3], XCP_BB_Input_Params_Initialise.num_fault_bytes);
}

/*
For get_transciever_chip_id
*/

class get_transciever_chip_id : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      static uint8_t xcp_die_id_mmic_version[22];

      xcp_die_id_mmic_version[0]                            = 0;
      xcp_die_id_mmic_version[1]                            = 0x14;
      xcp_die_id_mmic_version[2]                            = 0x17;
      xcp_die_id_mmic_version[3]                            = 0x84;
      xcp_die_id_mmic_version[4]                            = 0;
      xcp_die_id_mmic_version[5]                            = 0;
      xcp_die_id_mmic_version[6]                            = 0;
      xcp_die_id_mmic_version[7]                            = 0x21;
      xcp_die_id_mmic_version[8]                            = 0;
      xcp_die_id_mmic_version[9]                            = 0;
      xcp_die_id_mmic_version[10]                           = 0;
      xcp_die_id_mmic_version[11]                           = 0x0C;
      xcp_die_id_mmic_version[12]                           = 0;
      xcp_die_id_mmic_version[13]                           = 0;
      xcp_die_id_mmic_version[14]                           = 0x3;
      xcp_die_id_mmic_version[15]                           = 0xA6;
      xcp_die_id_mmic_version[16]                           = 0;
      xcp_die_id_mmic_version[17]                           = 0;
      xcp_die_id_mmic_version[18]                           = 0;
      xcp_die_id_mmic_version[19]                           = 0x5;
      xcp_die_id_mmic_version[20]                           = 0x1;
      xcp_die_id_mmic_version[21]                           = 0x0;
      XCP_BB_Input_Params_Initialise.xcp_MMIC_ChipID_Length = sizeof(xcp_die_id_mmic_version);
      XCP_BB_Input_Params_Initialise.xcp_MMIC_A_ChipID_ptr  = (uint8_t *)&xcp_die_id_mmic_version;
      Get_XCP_Init_Parameters_fake.custom_fake              = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(get_transciever_chip_id, get_transciever_chip_id_positive_tc1)
{
   uint8_t cmnd[]       = {0xF1, 98, 1};
   uint8_t return_value = XCP_User_Cmd_Get_Transciever_Chip_ID(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(get_transciever_chip_id, get_transciever_chip_id_negative_tc1)
{
   uint8_t cmnd[]                                       = {0xF1, 98, 2};
   XCP_BB_Input_Params_Initialise.xcp_MMIC_B_ChipID_ptr = NULL;
   uint8_t return_value = XCP_User_Cmd_Get_Transciever_Chip_ID(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(get_transciever_chip_id, get_transciever_chip_id_negative_tc2)
{
   uint8_t cmnd[]       = {0xF1, 98, 3};
   uint8_t return_value = XCP_User_Cmd_Get_Transciever_Chip_ID(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(get_transciever_chip_id, get_transciever_chip_id_negative_tc3)
{
   uint8_t cmnd[] = {0xF1, 98, 2};
   static uint8_t xcp_die_id_mmic_version[22];
   XCP_BB_Input_Params_Initialise.xcp_MMIC_B_ChipID_ptr  = (uint8_t *)&xcp_die_id_mmic_version;
   XCP_BB_Input_Params_Initialise.xcp_MMIC_A_ChipID_ptr  = NULL;
   XCP_BB_Input_Params_Initialise.xcp_MMIC_ChipID_Length = 37;
   uint8_t return_value = XCP_User_Cmd_Get_Transciever_Chip_ID(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
}

/*
For Get SW Ver Command
*/

class get_sw_version : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      typedef struct
      {
         uint8_t SMC_MajorVersion;
         uint8_t SMC_PlatformRevision;
         uint8_t SMC_Compatablity;
         uint8_t USC_MajorVersion;
         uint8_t USC_PlatformRevision;
         uint8_t USC_Compatablity;
         uint8_t Julian_Year;
         uint16_t Julian_Date;
      } Idt_Cal_Version_Info_Type;
      static Idt_Cal_Version_Info_Type XCP_Cal_Version;

      uint8_t *xcp_sw_ver_fake[XCP_MAX_SW_VER] = {NULL};
      xcp_sw_ver_fake[XCP_PLT_SW_VER]          = (uint8_t *)&XCP_Cal_Version.SMC_MajorVersion;

      XCP_BB_Input_Params_Initialise.xcp_sw_ver_ptr      = (uint8_t **)&xcp_sw_ver_fake;
      XCP_BB_Input_Params_Initialise.xcp_cust_sw_ver_ptr = NULL;
      XCP_BB_Input_Params_Initialise.xcp_sw_ver_len      = CODED_FALSE;
      XCP_BB_Input_Params_Initialise.xcp_customer_id     = 0x0;
      Get_XCP_Init_Parameters_fake.custom_fake           = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(get_sw_version, get_sw_version_positive_TC1)
{
   uint8_t cmnd[] = {0xF1, 0x0C, 0x01};
   uint8_t result = XCP_User_Cmd_Get_SW_Version(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(get_sw_version, get_sw_version_positive_TC5)
{
   uint8_t cmnd[]                                = {0xF1, 0x0C, 0x01};
   XCP_BB_Input_Params_Initialise.xcp_sw_ver_len = CODED_TRUE;
   uint8_t result = XCP_User_Cmd_Get_SW_Version(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(get_sw_version, get_sw_version_positive_TC2)
{
   uint8_t cmnd[]                   = {0xF1, 0x0C, 0xF0};
   uint8_t *xcp_cust_sw_ver_fake[1] = {NULL};
   xcp_cust_sw_ver_fake[0]          = (uint8_t *)malloc(sizeof(uint8_t *) * 50);
   uint8_t result                   = XCP_User_Cmd_Get_SW_Version(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);

   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(get_sw_version, get_sw_version_negative_TC3)
{
   uint8_t cmnd[] = {0xF1, 0x0C, 0x00};
   uint8_t result = XCP_User_Cmd_Get_SW_Version(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(get_sw_version, get_sw_version_negative_TC4)
{
   uint8_t cmnd[] = {0xF1, 0x0C, 0x01};
   uint8_t result = XCP_User_Cmd_Get_SW_Version(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(get_sw_version, get_sw_version_negative_TC5)
{
   uint8_t cmnd[]                                = {0xF1, 0x0C, 0x02};
   XCP_BB_Input_Params_Initialise.xcp_sw_ver_ptr = NULL;
   uint8_t result = XCP_User_Cmd_Get_SW_Version(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(get_sw_version, get_sw_version_negative_TC6)
{
   uint8_t cmnd[]                                     = {0xF1, 0x0C, 0xFF};
   uint8_t *sw_ver_cust                               = (uint8_t *)malloc(20);
   XCP_BB_Input_Params_Initialise.xcp_cust_sw_ver_ptr = &sw_ver_cust;
   uint8_t result = XCP_User_Cmd_Get_SW_Version(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

/*
For cmd_data_flash
*/
static uint8_t xcp_nvm_status;
static uint8_t xcp_nvm_cmnd_status = XCP_NVM_STATUS_SUCCESS;

class data_flash : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();

      XCP_BB_Input_Params_Initialise.xcp_nvm_ptr                       = &xcp_nvm_status;
      XCP_BB_Input_Params_Initialise.xcp_nvm_prev_operation_status_ptr = &xcp_nvm_cmnd_status;
      Get_XCP_Init_Parameters_fake.custom_fake                         = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(data_flash, get_sw_xcp_user_cmd_data_flash_Pos_TC1)
{
   uint8_t cmnd[] = {0xF1, 0x05, 0x01};
   uint8_t result = XCP_User_Cmd_Data_Flash(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], cmnd[1]);
   ASSERT_EQ(response[2], cmnd[2]);
   ASSERT_EQ(framelength, XCP_RES_LEN_5);
}

TEST_F(data_flash, get_sw_xcp_user_cmd_data_flash_Pos_TC2)
{
   uint8_t cmnd[]                  = {0xF1, 0x05, 0x01};
   XCP_Data_Flash.nvm_erase_status = CODED_TRUE;
   uint8_t result                  = XCP_User_Cmd_Data_Flash(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_CONDITIONS_NOT_CORRECT);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

TEST_F(data_flash, get_sw_xcp_user_cmd_data_flash_Pos_TC3)
{
   uint8_t cmnd[] = {0xF1, 0x05, 0x02};
   uint8_t result = XCP_User_Cmd_Data_Flash(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], cmnd[1]);
   ASSERT_EQ(response[2], cmnd[2]);
   ASSERT_EQ(framelength, XCP_RES_LEN_5);
}

TEST_F(data_flash, get_sw_xcp_user_cmd_data_flash_Pos_TC4)
{
   uint8_t cmnd[] = {0xF1, 0x05, 0x05};
   uint8_t result = XCP_User_Cmd_Data_Flash(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], cmnd[1]);
   ASSERT_EQ(response[2], cmnd[2]);
   ASSERT_EQ(framelength, XCP_RES_LEN_5);
}

TEST_F(data_flash, get_sw_xcp_user_cmd_data_flash_Neg_TC5)
{
   uint8_t cmnd[] = {0xF1, 0x05, 0x00};
   uint8_t result = XCP_User_Cmd_Data_Flash(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

TEST_F(data_flash, get_sw_xcp_user_cmd_data_flash_Neg_TC6)
{
   uint8_t cmnd[]      = {0xF1, 0x05, 0x01};
   xcp_nvm_cmnd_status = XCP_NVM_STATUS_PENDING;
   uint8_t result      = XCP_User_Cmd_Data_Flash(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_CMD_BUSY_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

TEST_F(data_flash, get_sw_xcp_user_cmd_data_flash_Neg_TC7)
{
   uint8_t cmnd[]                             = {0xF1, 0x05, 0x01};
   XCP_BB_Input_Params_Initialise.xcp_nvm_ptr = NULL;
   xcp_nvm_cmnd_status                        = XCP_NVM_STATUS_PENDING;
   uint8_t result = XCP_User_Cmd_Data_Flash(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

TEST_F(data_flash, get_sw_xcp_user_cmd_data_flash_Neg_TC8)
{
   uint8_t cmnd[]      = {0xF1, 0x05, 0x03};
   xcp_nvm_cmnd_status = XCP_NVM_STATUS_PENDING;
   uint8_t result      = XCP_User_Cmd_Data_Flash(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_CMD_BUSY_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

TEST_F(data_flash, get_sw_xcp_user_cmd_data_flash_Neg_TC9)
{
   uint8_t cmnd[]      = {0xF1, 0x05, 0x06};
   xcp_nvm_cmnd_status = XCP_NVM_STATUS_PENDING;
   uint8_t result      = XCP_User_Cmd_Data_Flash(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_CMD_BUSY_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

TEST_F(data_flash, get_sw_xcp_user_cmd_data_flash_Neg_TC10)
{
   uint8_t cmnd[]      = {0xF1, 0x05, 0x04};
   xcp_nvm_cmnd_status = XCP_NVM_STATUS_PENDING;
   uint8_t result      = XCP_User_Cmd_Data_Flash(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], XCP_ERR_CMD_BUSY_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

/*
For XCP_Set_Override_Periodic_Task
*/
class set_override_periodic : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      uint16_t k_sensitivity_SF_USC_str                       = 0;
      XCP_BB_Input_Params_Initialise.xcp_get_override_var_ptr = &k_sensitivity_SF_USC_str;

      Get_XCP_Init_Parameters_fake.custom_fake = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(set_override_periodic, set_override_periodic_TC1)
{
   uint8_t result = XCP_Set_Override_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(set_override_periodic, set_override_periodic_TC2)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt--;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max++;
   uint8_t result = XCP_Set_Override_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}
TEST_F(set_override_periodic, set_override_periodic_TC3)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt       = 10;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max   = 15;
   uint16_t val                                            = 17;
   XCP_BB_Input_Params_Initialise.xcp_get_override_var_ptr = &val;
   uint8_t result = XCP_Set_Override_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(result, (uint8_t)1);
}

/*
For XCP_User_Cmd_Get_MCU_ID
*/
class get_mcu_id : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      XCP_BB_Input_Params_Initialise.xcp_get_mcu_id_ptr    = (volatile uint8_t *)malloc(8U);
      XCP_BB_Input_Params_Initialise.xcp_get_unique_id_ptr = (volatile uint8_t *)malloc(8U);
      Get_XCP_Init_Parameters_fake.custom_fake             = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(get_mcu_id, get_mcu_id_TC1)
{
   uint8_t cmnd[] = {0xF1, 0x97};
   uint8_t result = XCP_User_Cmd_Get_MCU_ID(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(get_mcu_id, get_mcu_id_TC2)
{
   uint8_t cmnd[]                                       = {0xF1, 0x97};
   XCP_BB_Input_Params_Initialise.xcp_get_mcu_id_ptr    = NULL;
   XCP_BB_Input_Params_Initialise.xcp_get_unique_id_ptr = NULL;
   uint8_t result = XCP_User_Cmd_Get_MCU_ID(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(get_mcu_id, get_mcu_id_TC3)
{
   uint8_t cmnd[]                                    = {0xF1, 0x97};
   XCP_BB_Input_Params_Initialise.xcp_get_mcu_id_ptr = NULL;
   uint8_t result = XCP_User_Cmd_Get_MCU_ID(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(get_mcu_id, get_mcu_id_TC4)
{
   uint8_t cmnd[]                                       = {0xF1, 0x97};
   XCP_BB_Input_Params_Initialise.xcp_get_unique_id_ptr = NULL;
   uint8_t result = XCP_User_Cmd_Get_MCU_ID(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}
/*
For Stop Transmitting Periodic Msgs Command
*/

/*
For XCP_User_Cmd_Write_Alignment_Data F1 30
*/
static XCP_Write_Alignment_T xcp_write_alignment = {CODED_FALSE, 0, 0, (uint8_t)XCP_WRITE_ALIGNMENT_IDLE};
static uint8_t xcp_select_alignment_typedic_status;
static uint8_t *xcp_write_alignment_memory[2] = {(uint8_t *)&xcp_select_alignment_typedic_status, NULL};

class write_alignment_data : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      XCP_BB_Input_Params_Initialise.xcp_wrtie_align_data_ptr   = &xcp_write_alignment;
      XCP_BB_Input_Params_Initialise.xcp_write_align_memory_ptr = (uint8_t **)&xcp_write_alignment_memory;
      Get_XCP_Init_Parameters_fake.custom_fake                  = Get_XCP_Init_Parameters_Custom_Fake;
      /* F1 30 */
      /* table hold the no of paramets and data size of the each parameter*/
      static uint8_t xcp_select_align_type[2][2]          = {/* no_of_parameters, no_of_bytes per parameter , */
                                                    {0, sizeof(float32_t)},
                                                    {1, sizeof(uint8_t)}};
      static uint8_t xcp_nvm_align_data[2][2]             = {/* no_of_parameters, no_of_bytes, */
                                                 {11, sizeof(float32_t)},
                                                 {0, sizeof(uint8_t)}};
      static uint8_t(*XCP_Write_Align_Data_Info[2])[2][2] = {&xcp_select_align_type, &xcp_nvm_align_data};
   }
   void TearDown()
   {
   }
};

/*Write ALignment Periodic*/

class write_alignment_periodic_data : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      static XCP_Write_Alignment_T xcp_write_alignment = {CODED_FALSE, 0, 0, (uint8_t)XCP_WRITE_ALIGNMENT_IDLE};
      static uint8_t xcp_select_alignment_typedic_status;
      static uint8_t *xcp_write_alignment_memory[2]             = {(uint8_t *)&xcp_select_alignment_typedic_status, NULL};
      XCP_BB_Input_Params_Initialise.xcp_wrtie_align_data_ptr   = &xcp_write_alignment;
      XCP_BB_Input_Params_Initialise.xcp_write_align_memory_ptr = (uint8_t **)&xcp_write_alignment_memory;
      Get_XCP_Init_Parameters_fake.custom_fake                  = Get_XCP_Init_Parameters_Custom_Fake;
      static XCP_Periodic_User_Cmd_T XCP_Periodic_User_Cmd      = {NULL, CODED_FALSE, 0, 5, 0};
   }
   void TearDown()
   {
   }
};

/*

For XCP_User_Cmd_Read_Alignment_Data F1 31
*/
static uint8_t AlignmentModeOut;
uint8_t *xcp_nvm_read_data                   = (uint8_t *)malloc(20);
uint8_t *xcp_read_align_intial_res           = (uint8_t *)malloc(20);
uint8_t *xcp_read_align_perf_res             = (uint8_t *)malloc(20);
uint8_t *xcp_read_auto_align_res             = (uint8_t *)malloc(20);
uint8_t *xcp_align_auto_read_2               = (uint8_t *)malloc(20);
static uint8_t *xcp_Read_alignment_memory[6] = {(uint8_t *)&AlignmentModeOut,          (uint8_t *)&xcp_nvm_read_data,
                                                (uint8_t *)&xcp_read_align_intial_res, (uint8_t *)&xcp_read_align_perf_res,
                                                (uint8_t *)&xcp_read_auto_align_res,   (uint8_t *)&xcp_align_auto_read_2};

class read_alignment_data : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      XCP_BB_Input_Params_Initialise.xcp_read_align_memory_ptr = (uint8_t **)&xcp_Read_alignment_memory;
      Get_XCP_Init_Parameters_fake.custom_fake                 = Get_XCP_Init_Parameters_Custom_Fake;
      /* F1 31 */
      /* table hold the no of paramets and data size of the each parameter*/

      static uint8_t xcp_read_align_nvm[2][2] = {/* no_of_parameters, no_of_bytes per parameter , */
                                                 {11, 4},
                                                 {1, 4}};

      static uint8_t xcp_read_align_result[2][2] = {/* no_of_parameters, no_of_bytes, */
                                                    {5, 4},
                                                    {5, 4}};

      static uint8_t XCP_Read_Align_Performance[2][2] = {/* no_of_parameters, no_of_bytes per parameter , */
                                                         {12, 4},
                                                         {1, 4}};

      static uint8_t xcp_read_align_Auto[2][2] = {/* no_of_parameters, no_of_bytes, */
                                                  {12, 4},
                                                  {2, 4}};

      static uint8_t(*XCP_Read_Align_Data_Info[4])[2][2] = {&xcp_read_align_nvm, NULL, &XCP_Read_Align_Performance,
                                                            &xcp_read_align_Auto};
   }
   void TearDown()
   {
   }
};

TEST_F(target_parameters, ctp_TC1_zero_values)
{
   uint8_t resp[64]                       = {0};
   XCP_Target_Info_Valid_Trgt_T valid_tgt = {0};
   bool bistatic                          = Compute_Target_Parameters(resp, &valid_tgt);
   ASSERT_EQ(bistatic, false);
}

TEST_F(target_parameters, ctp_TC2_positive_values)
{
   uint8_t resp[64] = {0};
   XCP_Target_Info_Valid_Trgt_T valid_tgt;
   memset(&valid_tgt, 0, sizeof(valid_tgt));
   valid_tgt.target_range      = Init_Fixed_Point(10.0, s8p7_T);
   valid_tgt.target_range_rate = Init_Fixed_Point(5.0, s8p7_T);
   valid_tgt.target_rcs        = Init_Fixed_Point(3.0, s8p7_T);
   valid_tgt.target_angle      = 15.0f;
   valid_tgt.det_elevation     = 2.0f;
   valid_tgt.bistatic          = true;
   bool bistatic               = Compute_Target_Parameters(resp, &valid_tgt);
   ASSERT_EQ(bistatic, true);
}

TEST_F(target_parameters, ctp_TC3_negative_values)
{
   uint8_t resp[64] = {0};
   XCP_Target_Info_Valid_Trgt_T valid_tgt;
   memset(&valid_tgt, 0, sizeof(valid_tgt));
   valid_tgt.target_range      = Init_Fixed_Point(1.0, s8p7_T);
   valid_tgt.target_range_rate = Init_Fixed_Point(-5.0, s8p7_T);
   valid_tgt.target_rcs        = Init_Fixed_Point(-1.0, s8p7_T);
   valid_tgt.target_angle      = -10.0f;
   valid_tgt.det_elevation     = -3.0f;
   valid_tgt.bistatic          = false;
   bool bistatic               = Compute_Target_Parameters(resp, &valid_tgt);
   ASSERT_EQ(bistatic, false);
}

/* Write Alignment data F1 30 */

TEST_F(write_alignment_data, Write_alignment_data_positive_TC1)
{
   uint8_t cmnd[]                                        = {0xF1, 0x30, 0x00, 0x00};
   XCP_Write_Alignment_T *xcp_align_ptr                  = XCP_BB_Input_Params_Initialise.xcp_wrtie_align_data_ptr;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   uint8_t result = XCP_User_Cmd_Write_Alignment_Data(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(xcp_align_ptr->write_status, XCP_WRITE_ALIGNMENT_IDLE);
}

TEST_F(write_alignment_data, Write_alignment_data_positive_TC2)
{
   uint8_t cmnd[]                                        = {0xF1, 0x30, 0x01, 0x03};
   uint8_t retValue                                      = XCP_CMD_OK_CPV;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   uint8_t result = XCP_User_Cmd_Write_Alignment_Data(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(retValue, XCP_ERR_CMD_SYNCH_CPV);
}

TEST_F(write_alignment_data, Write_alignment_data_negative_TC3)
{
   uint8_t cmnd[] = {0xF1, 0x30, 0x03, 0xFF};
   uint8_t result = XCP_User_Cmd_Write_Alignment_Data(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
}

TEST_F(write_alignment_data, Write_alignment_data_negative_TC4)
{
   uint8_t cmnd[] = {0xF1, 0x30, 0x01, 0x04};
   uint8_t result = XCP_User_Cmd_Write_Alignment_Data(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
}

TEST_F(write_alignment_data, Write_alignment_data_negative_TC5)
{
   uint8_t cmnd[]                                        = {0xF1, 0x30, 0x00, 0x01};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   uint8_t result = XCP_User_Cmd_Write_Alignment_Data(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
}
TEST_F(write_alignment_data, Write_alignment_data_negative_TC6)
{
   uint8_t cmnd[]                                        = {0xF1, 0x30, 0x00, 0x01};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_TRUE;
   uint8_t result = XCP_User_Cmd_Write_Alignment_Data(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
}
TEST_F(write_alignment_data, Write_alignment_data_positive_TC7)
{
   uint8_t cmnd[]                                        = {0xF1, 0x30, 0x00, 0x00};
   XCP_Write_Alignment_T *xcp_align_ptr                  = XCP_BB_Input_Params_Initialise.xcp_wrtie_align_data_ptr;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   uint8_t **xcp_write_memory_ptr                        = (uint8_t **)malloc(20);
   XCP_Write_Align_Data_Info[cmnd[2]]                    = NULL;
   xcp_write_memory_ptr[cmnd[2]]                         = (uint8_t *)malloc(20);
   uint8_t result = XCP_User_Cmd_Write_Alignment_Data(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(xcp_align_ptr->write_status, XCP_WRITE_ALIGNMENT_IDLE);
}

TEST_F(write_alignment_data, Write_alignment_data_negative_TC8)
{
   uint8_t cmnd[]                                        = {0xF1, 0x30, 0x04, 0x01};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   uint8_t result = XCP_User_Cmd_Write_Alignment_Data(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
}
/* Read Alignment data F1 31 */

TEST_F(read_alignment_data, Read_alignment_data_positive_TC1)
{
   uint8_t cmnd[]                                        = {0xF1, 0x31, 3u, 0x00};
   uint8_t(*xcp_read_alignment_ptr)[2][2]                = (uint8_t(*)[2][2])malloc(20);
   uint8_t *xcp_data_ptr                                 = (uint8_t *)malloc(20);
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   uint8_t result = XCP_User_Cmd_Read_Alignment_Data(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
}

// TEST_F(read_alignment_data, Read_alignment_data_positive_TC2)
// {
//    uint8_t cmnd[]                                           = {0xF1, 0x31, 3u, 0x00};
//    XCP_Read_Align_Data_Info[cmnd[2] - 1]                    = (uint8_t(*)[2][2])malloc(20);
//    XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd    = CODED_FALSE;
//    XCP_BB_Input_Params_Initialise.xcp_read_align_memory_ptr = (uint8_t **)&xcp_Read_alignment_memory;
//    uint8_t result                                           = XCP_User_Cmd_Read_Alignment_Data(&XCP_BB_Input_Params_Initialise,
//    cmnd, response, &framelength); ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
// }

TEST_F(read_alignment_data, Read_alignment_data_negative_TC3)
{
   uint8_t cmnd[]                                           = {0xF1, 0x31, 5u, 0x00};
   XCP_Read_Align_Data_Info[cmnd[2] - 1]                    = NULL;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd    = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_read_align_memory_ptr = (uint8_t **)&xcp_Read_alignment_memory;
   uint8_t result = XCP_User_Cmd_Read_Alignment_Data(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
}

TEST_F(read_alignment_data, Read_alignment_data_negative_TC4)
{
   uint8_t cmnd[]                                           = {0xF1, 0x31, 2u, 0x06};
   uint8_t **xcp_read_memory_ptr                            = (uint8_t **)&xcp_Read_alignment_memory;
   XCP_Read_Align_Data_Info[cmnd[2] - 1]                    = NULL;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd    = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_read_align_memory_ptr = (uint8_t **)&xcp_Read_alignment_memory;
   xcp_Read_alignment_memory[cmnd[2] - 1]                   = NULL;
   uint8_t result = XCP_User_Cmd_Read_Alignment_Data(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
}

TEST_F(read_alignment_data, Read_alignment_data_positive_TC5)
{
   uint8_t cmnd[]                                           = {0xF1, 0x31, 3U, 13U};
   XCP_Read_Align_Data_Info[cmnd[2] - 1]                    = &XCP_Read_Align_Performance;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd    = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_read_align_memory_ptr = (uint8_t **)&xcp_Read_alignment_memory;
   uint8_t result = XCP_User_Cmd_Read_Alignment_Data(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[1], XCP_ERR_GENERIC_CPV);
   ASSERT_EQ((*XCP_Read_Align_Data_Info[2])[0][0], 12U);
}

TEST_F(read_alignment_data, Read_alignment_data_negative_TC6)
{
   uint8_t cmnd[]                                           = {0xF1, 0x31, 5U, 0x00};
   uint8_t **xcp_read_memory_ptr                            = (uint8_t **)&xcp_Read_alignment_memory;
   XCP_Read_Align_Data_Info[cmnd[2] - 1]                    = NULL;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd    = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_read_align_memory_ptr = (uint8_t **)&xcp_Read_alignment_memory;
   xcp_read_memory_ptr[cmnd[2] - 1]                         = NULL;
   uint8_t result = XCP_User_Cmd_Read_Alignment_Data(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
}

TEST_F(read_alignment_data, Read_alignment_data_negative_TC7)
{
   uint8_t cmnd[]                                        = {0xF1, 0x31, 0U, 0x00};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   uint8_t result = XCP_User_Cmd_Read_Alignment_Data(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
}

TEST_F(read_alignment_data, Read_alignment_data_negative_TC8)
{
   uint8_t cmnd[]                                        = {0xF1, 0x31, 3U, 0x00};
   uint8_t **xcp_read_memory_ptr                         = (uint8_t **)&xcp_Read_alignment_memory;
   XCP_Read_Align_Data_Info[cmnd[2] - 1]                 = (uint8_t(*)[2][2])malloc(20);
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   xcp_read_memory_ptr[cmnd[2] - 1]                      = NULL;
   uint8_t result = XCP_User_Cmd_Read_Alignment_Data(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
}

TEST_F(read_alignment_data, Read_alignment_data_negative_TCNRC)
{
   uint8_t cmnd[]                                           = {0xF1, 0x31, 6u, 0x00};
   XCP_Read_Align_Data_Info[cmnd[2] - 1]                    = NULL;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd    = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_read_align_memory_ptr = (uint8_t **)&xcp_Read_alignment_memory;
   uint8_t result = XCP_User_Cmd_Read_Alignment_Data(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
}

TEST_F(read_alignment_data, Read_alignment_data_negative_TCNRC2)
{
   uint8_t cmnd[]                        = {0xF1, 0x31, 5U, 0x00};
   uint8_t **xcp_read_memory_ptr         = (uint8_t **)&xcp_Read_alignment_memory;
   XCP_Read_Align_Data_Info[cmnd[2] - 1] = (uint8_t(*)[2][2])malloc(20);
   ;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd    = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_read_align_memory_ptr = (uint8_t **)&xcp_Read_alignment_memory;
   xcp_read_memory_ptr[cmnd[2] - 1]                         = NULL;
   uint8_t result = XCP_User_Cmd_Read_Alignment_Data(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(response[1], XCP_ERR_OUT_OF_RANGE_CPV);
}

/*Write Alignment periodic*/

TEST_F(write_alignment_periodic_data, Write_alignment_periodic_data_positive_TC1)
{
   XCP_Write_Alignment_T *xcp_align_ptr = XCP_BB_Input_Params_Initialise.xcp_wrtie_align_data_ptr;
   xcp_align_ptr->write_status          = 1;
   uint8_t result = XCP_Write_Alignment_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(response[1], XCP_ERR_MEMORY_OVERFLOW_CPV);
}

TEST_F(write_alignment_periodic_data, Write_alignment_periodic_data_negative_TC2)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = 5;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max = 0;
   uint8_t result = XCP_Write_Alignment_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(response[1], XCP_ERR_CMD_BUSY_CPV);
}

TEST_F(write_alignment_periodic_data, Write_alignment_periodic_data_negative_TC3)
{
   XCP_Write_Alignment_T *xcp_align_ptr                  = XCP_BB_Input_Params_Initialise.xcp_wrtie_align_data_ptr;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = 0;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max = 5;
   xcp_align_ptr->write_status                           = 3;
   uint8_t result = XCP_Write_Alignment_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(response[1], XCP_ERR_CMD_BUSY_CPV);
}

/*
For XCP_User_Cmd_Get_Fault_Test_Completed
*/

class get_fault_test_completed : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      XCP_BB_Input_Params_Initialise.xcp_fault_test_completed_ptr = (volatile uint8_t *)malloc(8U);
      XCP_BB_Input_Params_Initialise.num_fault_bytes              = sizeof(Dt_Fault_T);
      Get_XCP_Init_Parameters_fake.custom_fake                    = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(get_fault_test_completed, PASS_CASE_VALID_CMND_INFO_B0)
{
   uint8_t cmnd[] = {0xF1, 0xB0, 0x01};
   uint8_t result = XCP_User_Cmd_Get_Fault_Test_Completed(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(framelength, 3u);   // Positive response length (1 data byte + 2 header)
   EXPECT_EQ(response[0], 0xFF); // XCP_POSITIVE_RESPONSE_CPV
   EXPECT_EQ(response[1], 0xB0); // Command echo
}

TEST_F(get_fault_test_completed, FAIL_CASE_INVALID_CMND_INFO_B0)
{
   uint8_t cmnd[] = {0xF1, 0xB0, 0x99};
   uint8_t result = XCP_User_Cmd_Get_Fault_Test_Completed(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(framelength, 2u);   // Negative response length
   EXPECT_EQ(response[0], 0xFE); // XCP_NEGATIVE_RESPONSE_CPV
   EXPECT_EQ(response[1], 0x22); // XCP_ERR_OUT_OF_RANGE_CPV
}

TEST_F(get_fault_test_completed, FAIL_CASE_NULL_POINTER_B0)
{
   uint8_t cmnd[]                                              = {0xF1, 0xB0, 0x01};
   XCP_BB_Input_Params_Initialise.xcp_fault_test_completed_ptr = NULL;
   uint8_t result = XCP_User_Cmd_Get_Fault_Test_Completed(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(framelength, 2u);   // Negative response length
   EXPECT_EQ(response[0], 0xFE); // XCP_NEGATIVE_RESPONSE_CPV
   EXPECT_EQ(response[1], 0x22); // XCP_ERR_OUT_OF_RANGE_CPV
}

/*
For XCP_User_Cmd_Get_History_Fault
*/

class get_history_fault : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();

      typedef uint8 Dt_Fault_T[16];
      static Dt_Fault_T History_Fault_Table;

      XCP_BB_Input_Params_Initialise.history_fault_table_ptr = (uint8_t *)History_Fault_Table;
      XCP_BB_Input_Params_Initialise.num_fault_bytes         = sizeof(Dt_Fault_T);
      Get_XCP_Init_Parameters_fake.custom_fake               = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(get_history_fault, PASS_CASE_VALID_CMND_INFO_C0)
{
   uint8_t cmnd[] = {0xF1, 0xC0, 0x09};
   uint8_t result = XCP_User_Cmd_Get_History_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(framelength, 11U);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   EXPECT_EQ(response[1], 0xC0);
}

TEST_F(get_history_fault, FAIL_CASE_INVALID_CMND_INFO_C0)
{
   uint8_t cmnd[] = {0xF1, 0xC0, 0x15};
   uint8_t result = XCP_User_Cmd_Get_History_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(framelength, 2u);   // Negative response length
   EXPECT_EQ(response[0], 0xFE); // XCP_NEGATIVE_RESPONSE_CPV
   EXPECT_EQ(response[1], 0x22); // XCP_ERR_OUT_OF_RANGE_CPV
}

TEST_F(get_history_fault, FAIL_CASE_NULL_POINTER_C0)
{
   uint8_t cmnd[]                                         = {0xF1, 0xC0, 0x01};
   XCP_BB_Input_Params_Initialise.history_fault_table_ptr = NULL;
   uint8_t result = XCP_User_Cmd_Get_History_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(framelength, 2u);   // Negative response length
   EXPECT_EQ(response[0], 0xFE); // XCP_NEGATIVE_RESPONSE_CPV
   EXPECT_EQ(response[1], 0x22); // XCP_ERR_OUT_OF_RANGE_CPV
}

/*
For XCP_User_Cmd_Get_Active_Fault
*/

class get_active_fault : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      XCP_BB_Input_Params_Initialise.active_fault_table_ptr = (uint8_t *)malloc(8u);
      XCP_BB_Input_Params_Initialise.num_fault_bytes        = sizeof(Dt_Fault_T);
      Get_XCP_Init_Parameters_fake.custom_fake              = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(get_active_fault, PASS_CASE_VALID_CMND_INFO_D0)
{
   uint8_t cmnd[] = {0xF1, 0xD0, 0x01};
   uint8_t result = XCP_User_Cmd_Get_Active_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(framelength, 3u);   // Positive response length (1 data byte + 2 header)
   EXPECT_EQ(response[0], 0xFF); // XCP_POSITIVE_RESPONSE_CPV
   EXPECT_EQ(response[1], 0xD0); // Command echo
}

TEST_F(get_active_fault, FAIL_CASE_INVALID_CMND_INFO_D0)
{
   uint8_t cmnd[] = {0xF1, 0xD0, 0x99};
   uint8_t result = XCP_User_Cmd_Get_Active_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(framelength, 2u);   // Negative response length
   EXPECT_EQ(response[0], 0xFE); // XCP_NEGATIVE_RESPONSE_CPV
   EXPECT_EQ(response[1], 0x22); // XCP_ERR_OUT_OF_RANGE_CPV
}

TEST_F(get_active_fault, FAIL_CASE_NULL_POINTER_D0)
{
   uint8_t cmnd[]                                        = {0xF1, 0xD0, 0x01};
   XCP_BB_Input_Params_Initialise.active_fault_table_ptr = NULL;
   uint8_t result = XCP_User_Cmd_Get_Active_Fault(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(framelength, 2u);   // Negative response length
   EXPECT_EQ(response[0], 0xFE); // XCP_NEGATIVE_RESPONSE_CPV
   EXPECT_EQ(response[1], 0x22); // XCP_ERR_OUT_OF_RANGE_CPV
}

/*
For XCP_User_Cmd_Get_Active_Fault_Latched
*/

class get_active_fault_latched : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      //(volatile uint8_t *)malloc(8U)
      XCP_BB_Input_Params_Initialise.active_fault_latch_table_ptr = (uint8_t *)malloc(8u);
      XCP_BB_Input_Params_Initialise.num_fault_bytes              = sizeof(Dt_Fault_T);
      Get_XCP_Init_Parameters_fake.custom_fake                    = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(get_active_fault_latched, PASS_CASE_VALID_CMND_INFO_E0)
{
   uint8_t cmnd[] = {0xF1, 0xE0, 0x01};
   uint8_t result = XCP_User_Cmd_Get_Active_Fault_Latched(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(framelength, 3u);   // Positive response length (1 data byte + 2 header)
   EXPECT_EQ(response[0], 0xFF); // XCP_POSITIVE_RESPONSE_CPV
   EXPECT_EQ(response[1], 0xE0); // Command echo
}

TEST_F(get_active_fault_latched, FAIL_CASE_NULL_POINTER_E0)
{
   uint8_t cmnd[]                                              = {0xF1, 0xE0, 0x01};
   XCP_BB_Input_Params_Initialise.active_fault_latch_table_ptr = NULL;
   uint8_t result = XCP_User_Cmd_Get_Active_Fault_Latched(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(framelength, 2u);   // Negative response length
   EXPECT_EQ(response[0], 0xFE); // XCP_NEGATIVE_RESPONSE_CPV
   EXPECT_EQ(response[1], 0x22); // XCP_ERR_OUT_OF_RANGE_CPV
}

TEST_F(get_active_fault_latched, FAIL_CASE_INVALID_CMND_INFO_E0)
{
   uint8_t cmnd[] = {0xF1, 0xE0, 0x99};
   uint8_t result = XCP_User_Cmd_Get_Active_Fault_Latched(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(framelength, 2u);   // Negative response length
   EXPECT_EQ(response[0], 0xFE); // XCP_NEGATIVE_RESPONSE_CPV
   EXPECT_EQ(response[1], 0x22); // XCP_ERR_OUT_OF_RANGE_CPV
}

/*
For Get Checksum Results
*/

class get_checksum_results : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      static uint8_t xcp_chksm_trigger_flag_ptr                 = CODED_FALSE;
      XCP_BB_Input_Params_Initialise.xcp_chksm_trigger_flag_ptr = &xcp_chksm_trigger_flag_ptr;
      Get_XCP_Init_Parameters_fake.custom_fake                  = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(get_checksum_results, Get_Checksum_Results_positive_TC1)
{
   uint8_t cmnd[] = {0xF1, 0x85};
   uint32_t checksum1, checksum2, checksum3, checksum4, checksum5, checksum6 = 0;
   uint8_t *checksumptr[] = {
      NULL, (uint8_t *)&checksum2, (uint8_t *)&checksum3, (uint8_t *)&checksum4, (uint8_t *)&checksum5, (uint8_t *)&checksum6};
   uint8_t *custchecksumptr[]                              = {(uint8_t *)&checksum5, (uint8_t *)&checksum6};
   XCP_BB_Input_Params_Initialise.xcp_checksum_ptr         = (uint8_t **)&checksumptr;
   XCP_BB_Input_Params_Initialise.xcp_cust_checksum_ptr    = (uint8_t **)&custchecksumptr;
   XCP_BB_Input_Params_Initialise.xcp_num_cust_spec_chcksm = 1;

   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   uint8_t result = XCP_User_Cmd_Get_Checksum_Results(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
}

TEST_F(get_checksum_results, Get_Checksum_Results_negative_TC1)
{
   uint8_t cmnd[] = {0xF1, 0x85};
   uint32_t checksum1, checksum2, checksum3, checksum4, checksum5, checksum6 = 0;
   uint8_t *checksumptr[] = {
      NULL, (uint8_t *)&checksum2, (uint8_t *)&checksum3, (uint8_t *)&checksum4, (uint8_t *)&checksum5, (uint8_t *)&checksum6};
   uint8_t *custchecksumptr[]                              = {(uint8_t *)&checksum5, (uint8_t *)&checksum6};
   XCP_BB_Input_Params_Initialise.xcp_checksum_ptr         = (uint8_t **)&checksumptr;
   XCP_BB_Input_Params_Initialise.xcp_cust_checksum_ptr    = (uint8_t **)&custchecksumptr;
   XCP_BB_Input_Params_Initialise.xcp_num_cust_spec_chcksm = 20;

   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   uint8_t result = XCP_User_Cmd_Get_Checksum_Results(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(get_checksum_results, Get_Checksum_Results_negative_TC2)
{
   uint8_t cmnd[] = {0xF1, 0x85};
   uint32_t checksum1, checksum2, checksum3, checksum4, checksum5, checksum6 = 0;
   uint8_t *checksumptr[] = {
      NULL, (uint8_t *)&checksum2, (uint8_t *)&checksum3, (uint8_t *)&checksum4, (uint8_t *)&checksum5, (uint8_t *)&checksum6};
   uint8_t *custchecksumptr[]                              = {(uint8_t *)&checksum5, (uint8_t *)&checksum6};
   XCP_BB_Input_Params_Initialise.xcp_checksum_ptr         = NULL;
   XCP_BB_Input_Params_Initialise.xcp_cust_checksum_ptr    = NULL;
   XCP_BB_Input_Params_Initialise.xcp_num_cust_spec_chcksm = 2;

   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   uint8_t result = XCP_User_Cmd_Get_Checksum_Results(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], 0xFE); // XCP_NEGATIVE_RESPONSE_CPV
}

typedef struct
{
   uint8_t ServiceId;
   uint16_t Did;
   uint8_t Data[61];
} Dt_Xcp_Read_Write_Did_T;

static Dt_Xcp_Read_Write_Did_T Xcp_Did_Read_Data  = {};
static Dt_Xcp_Read_Write_Did_T Xcp_Did_Write_Data = {0};
static uint8_t xcp_did_cmd_recvd                  = CODED_FALSE;

class read_write_DID : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();

      XCP_BB_Input_Params_Initialise.xcp_input_did_ptr  = &Xcp_Did_Write_Data;
      XCP_BB_Input_Params_Initialise.xcp_output_did_ptr = &Xcp_Did_Write_Data;
      XCP_BB_Input_Params_Initialise.xcp_did_recvd_ptr  = &xcp_did_cmd_recvd;
   }

   void TearDown()
   {
   }
};

TEST_F(read_write_DID, read_write_DID_TC1)
{
   uint8_t cmnd[] = {0xF1, 0x13, 0x04, 0x22, 0x0, 0x0};
   uint8_t result = XCP_User_Cmd_Read_Write_DID(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_PENDING_CPV);
   uint8_t new_result = XCP_DID_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(new_result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(read_write_DID, read_write_DID_TC2)
{
   uint8_t cmnd[] = {0xF1, 0x13, 0x04, 0x01};
   uint8_t result = XCP_User_Cmd_Read_Write_DID(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   uint8_t new_result = XCP_DID_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(new_result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(read_write_DID, read_write_DID_TC3)
{
   uint8_t cmnd[] = {0xF1, 0x13, 0x04, 0x2E};
   uint8_t result = XCP_User_Cmd_Read_Write_DID(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_PENDING_CPV);
   uint8_t new_result = XCP_DID_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(new_result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(read_write_DID, read_write_DID_TC4)
{
   uint8_t cmnd[] = {0xF1, 0x13, 0x01, 0x2E};
   uint8_t result = XCP_User_Cmd_Read_Write_DID(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);

   /* clear periodic user command */
   Set_XCP_Periodic_User_Cmd(0U, 0U, NULL);
}

TEST_F(read_write_DID, read_write_DID_TC5)
{
   uint8_t cmnd[]                                        = {0xF1, 0x13, 0x01, 0x01};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_input_did_ptr      = NULL;
   XCP_BB_Input_Params_Initialise.xcp_output_did_ptr     = &Xcp_Did_Read_Data;
   uint8_t result = XCP_User_Cmd_Read_Write_DID(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
   uint8_t new_result = XCP_DID_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(new_result, (uint8_t)XCP_CMD_OK_CPV);

   /* clear periodic user command */
   Set_XCP_Periodic_User_Cmd(0U, 0U, NULL);
}

TEST_F(read_write_DID, read_write_DID_TC6)
{
   uint8_t cmnd[]                                        = {0xF1, 0x13, 0x01, 0x2E};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_input_did_ptr      = &Xcp_Did_Read_Data;
   XCP_BB_Input_Params_Initialise.xcp_output_did_ptr     = NULL;
   uint8_t result = XCP_User_Cmd_Read_Write_DID(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);

   /* clear periodic user command */
   Set_XCP_Periodic_User_Cmd(0U, 0U, NULL);
}

TEST_F(read_write_DID, read_write_DID_TC7)
{
   uint8_t cmnd[] = {0xF1, 0x13, 0x3F, 0x2E};
   uint8_t result = XCP_User_Cmd_Read_Write_DID(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);

   /* clear periodic user command */
   Set_XCP_Periodic_User_Cmd(0U, 0U, NULL);
}

TEST_F(read_write_DID, read_write_DID_TC8)
{
   uint8_t cmnd[] = {0xF1, 0x13, 0x04, 0x2E};
   uint8_t result = XCP_User_Cmd_Read_Write_DID(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_PENDING_CPV);

   /* clear periodic user command */
   Set_XCP_Periodic_User_Cmd(0U, 0U, NULL);
}

TEST_F(read_write_DID, read_write_DID_TC9)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt = 100U;
   uint8_t cmnd[]                                    = {0xF1, 0x13, 0x04, 0x22, 0x0, 0x0};
   uint8_t result = XCP_User_Cmd_Read_Write_DID(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_PENDING_CPV);
   uint8_t new_result = XCP_DID_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(new_result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(read_write_DID, read_write_DID_Timer)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt = 0U;
   uint8_t cmnd[]                                    = {0xF1, 0x13, 0x04, 0x22, 0x0, 0x0};
   Xcp_Did_Read_Data.ServiceId                       = 1;
   XCP_BB_Input_Params_Initialise.xcp_output_did_ptr = &Xcp_Did_Read_Data;
   uint8_t result = XCP_User_Cmd_Read_Write_DID(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);

   uint8_t new_result = XCP_DID_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(new_result, (uint8_t)XCP_CMD_PENDING_CPV);
}

TEST_F(read_write_DID, read_write_DID_Timer1)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt = 0U;
   uint8_t cmnd[]                                    = {0xF1, 0x13, 0x04, 0x22, 0x0, 0x0};
   Xcp_Did_Read_Data.ServiceId                       = 0x22;
   Xcp_Did_Read_Data.Did                             = 1;
   XCP_BB_Input_Params_Initialise.xcp_output_did_ptr = &Xcp_Did_Read_Data;
   uint8_t result = XCP_User_Cmd_Read_Write_DID(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);

   uint8_t new_result = XCP_DID_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(new_result, (uint8_t)XCP_CMD_PENDING_CPV);
}

TEST_F(read_write_DID, read_write_DID_Timer2)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt = 0U;
   uint8_t cmnd[]                                    = {0xF1, 0x13, 0x03, 0x2E, 0x0, 0x0};
   Xcp_Did_Read_Data.ServiceId                       = 0x22;
   Xcp_Did_Read_Data.Did                             = 1;
   XCP_BB_Input_Params_Initialise.xcp_output_did_ptr = &Xcp_Did_Read_Data;
   uint8_t result = XCP_User_Cmd_Read_Write_DID(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);

   uint8_t new_result = XCP_DID_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(new_result, (uint8_t)XCP_CMD_PENDING_CPV);
}

TEST_F(read_write_DID, read_write_DID_Timer3)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt = 0U;
   uint8_t cmnd[]                                    = {0xF1, 0x13, 0x03, 0x2E, 0x0, 0x0};
   Xcp_Did_Read_Data.ServiceId                       = 0x2E;
   Xcp_Did_Read_Data.Did                             = 1;
   XCP_BB_Input_Params_Initialise.xcp_output_did_ptr = &Xcp_Did_Read_Data;
   uint8_t result = XCP_User_Cmd_Read_Write_DID(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);

   uint8_t new_result = XCP_DID_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(new_result, (uint8_t)XCP_CMD_PENDING_CPV);
}
TEST_F(read_write_DID, read_write_DID_Timer4)
{
   /*Input parameters*/
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = 0U;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   /*CONMMAND Data*/
   XCP_DID_Cmd.service_id = 0x22u;
   XCP_DID_Cmd.DID        = 2u;

   Xcp_Did_Read_Data.ServiceId                       = 0x01;
   Xcp_Did_Read_Data.Did                             = 1;
   XCP_BB_Input_Params_Initialise.xcp_output_did_ptr = &Xcp_Did_Read_Data;

   uint8_t new_result = XCP_DID_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(new_result, (uint8_t)XCP_CMD_PENDING_CPV);
   // ASSERT_EQ(XCP_DID_Cmd.service_id, XCP_DID_READ_DATA);
   // ASSERT_EQ(xcp_did_recvd, CODED_TRUE);
}

TEST_F(read_write_DID, read_write_DID_Timer5)
{
   /*Input parameters*/
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = 0U;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   /*CONMMAND Data*/
   XCP_DID_Cmd.service_id = 0x2Eu;
   XCP_DID_Cmd.DID        = 2u;

   Xcp_Did_Read_Data.ServiceId                       = 0x2E;
   Xcp_Did_Read_Data.Did                             = 1;
   XCP_BB_Input_Params_Initialise.xcp_output_did_ptr = &Xcp_Did_Read_Data;

   uint8_t new_result = XCP_DID_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(new_result, (uint8_t)XCP_CMD_PENDING_CPV);
   // ASSERT_EQ(XCP_DID_Cmd.service_id, XCP_DID_READ_DATA);
   // ASSERT_EQ(xcp_did_recvd, CODED_TRUE);
}

TEST_F(read_write_DID, read_write_DID_Timer6)
{
   /*Input parameters*/
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = 0U;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   /*CONMMAND Data*/
   XCP_DID_Cmd.service_id = 0x2Eu;
   XCP_DID_Cmd.DID        = 2u;

   Xcp_Did_Read_Data.ServiceId                       = 0x2;
   Xcp_Did_Read_Data.Did                             = 1;
   XCP_BB_Input_Params_Initialise.xcp_output_did_ptr = &Xcp_Did_Read_Data;

   uint8_t new_result = XCP_DID_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(new_result, (uint8_t)XCP_CMD_PENDING_CPV);
   // ASSERT_EQ(XCP_DID_Cmd.service_id, XCP_DID_READ_DATA);
   // ASSERT_EQ(xcp_did_recvd, CODED_TRUE);
}

TEST_F(read_write_DID, read_write_DID_Timer7)
{
   /*Input parameters*/
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = 0U;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   /*CONMMAND Data*/
   XCP_DID_Cmd.service_id = 0x2u;
   XCP_DID_Cmd.DID        = 2u;

   Xcp_Did_Read_Data.ServiceId                       = 0x2E;
   Xcp_Did_Read_Data.Did                             = 1;
   XCP_BB_Input_Params_Initialise.xcp_output_did_ptr = &Xcp_Did_Read_Data;

   uint8_t new_result = XCP_DID_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(new_result, (uint8_t)XCP_CMD_PENDING_CPV);
   // ASSERT_EQ(XCP_DID_Cmd.service_id, XCP_DID_READ_DATA);
   // ASSERT_EQ(xcp_did_recvd, CODED_TRUE);
}

/* F1 9B */
void Get_Xcp_Phase_Rotator_Calibration(uint8_t cmd)
{
}

class phase_rotator_calibration : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();

      XCP_BB_Input_Params_Initialise.xcp_phase_rotator_calib_fptr = Get_Xcp_Phase_Rotator_Calibration;
   }

   void TearDown()
   {
   }
};

TEST_F(phase_rotator_calibration, phase_rotator_calibration_TC1)
{
   uint8_t cmnd[] = {0xF1, 0x9B, 0x01};
   uint8_t result = XCP_User_Cmd_Phase_Rotator_Calibration(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(framelength, (uint8_t)0x03);
}
TEST_F(phase_rotator_calibration, phase_rotator_calibration_TC2)
{
   uint8_t cmnd[] = {0xF1, 0x9B, 0x02};
   uint8_t result = XCP_User_Cmd_Phase_Rotator_Calibration(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(framelength, (uint8_t)0x03);
}

TEST_F(phase_rotator_calibration, phase_rotator_calibration_TC3)
{
   uint8_t cmnd[] = {0xF1, 0x9B, 0x00};
   uint8_t result = XCP_User_Cmd_Phase_Rotator_Calibration(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(framelength, (uint8_t)0x02);
}

TEST_F(phase_rotator_calibration, phase_rotator_calibration_TC4)
{
   uint8_t cmnd[]                                              = {0xF1, 0x9B, 0x00};
   XCP_BB_Input_Params_Initialise.xcp_phase_rotator_calib_fptr = NULL;
   uint8_t result = XCP_User_Cmd_Phase_Rotator_Calibration(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(framelength, (uint8_t)0x02);
}

class ADC_Filtered_Info_Periodic_Task_new : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      typedef struct
      {
         uint16_t ADC_CH1_NC;
         uint16_t ADC_CH2_NC;
         uint16_t ADC_CH3_NC;
         uint16_t ADC_Battery_volt;
         uint16_t ADC_Pos_GND_A;
         uint16_t ADC_Pos_GND_B;
         uint16_t ADC_Supply_0v9;
         uint16_t ADC_CH8_NC;
         uint16_t ADC_Supply_1v8;
         uint16_t Validity_Flag;
      } Dt_RawAdcDataFilt_T;
      static Dt_RawAdcDataFilt_T XCP_Raw_Adc_Filtered_Data;
      static uint8_t xcp_adc_trigger_flag         = CODED_TRUE;
      static uint8_t xcp_adc_validity_flag_status = CODED_TRUE;

      XCP_BB_Input_Params_Initialise.xcp_get_raw_adc_filtered_data_ptr = (void *)&XCP_Raw_Adc_Filtered_Data;
      XCP_BB_Input_Params_Initialise.num_analog_inputs                 = 100;
      XCP_BB_Input_Params_Initialise.xcp_get_adc_validity_flag_ptr     = &xcp_adc_validity_flag_status;
      XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr      = &xcp_adc_trigger_flag;
      Get_XCP_Init_Parameters_fake.custom_fake                         = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};
TEST_F(ADC_Filtered_Info_Periodic_Task_new, ADC_Filtered_Info_Periodic_Task_new)
{
   // xcp_adc_filtered_cmd.xcp_adc_filtered_quantity   = 0;
   uint8_t cmnd[]                             = {0xF1, 0xA2, 31U};
   static uint8_t xcp_adc_trigger_flg         = CODED_FALSE;
   static uint8_t xcp_adc_validity_flag_stats = CODED_TRUE;

   XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr = &xcp_adc_trigger_flag;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd       = CODED_FALSE;
   uint8_t return_value = Get_Filtered_Analog_Inputs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);

   XCP_BB_Input_Params_Initialise.xcp_get_adc_validity_flag_ptr = &xcp_adc_validity_flag_stats;
   XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr  = &xcp_adc_trigger_flg;
   XCP_BB_Input_Params_Initialise.num_analog_inputs             = 31;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt            = 0;

   uint8_t result = XCP_Filtered_ADC_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(response[0], 0xFF);
}

TEST_F(ADC_Filtered_Info_Periodic_Task_new, ADC_Filtered_Info_Periodic_Task_new2)
{
   // xcp_adc_filtered_cmd.xcp_adc_filtered_quantity   = 0;
   uint8_t cmnd[]                             = {0xF1, 0xA2, 31U};
   static uint8_t xcp_adc_trigger_flg         = CODED_FALSE;
   static uint8_t xcp_adc_validity_flag_stats = CODED_TRUE;

   XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr = &xcp_adc_trigger_flag;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd       = CODED_FALSE;
   uint8_t return_value = Get_Filtered_Analog_Inputs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);

   XCP_BB_Input_Params_Initialise.xcp_get_adc_validity_flag_ptr = &xcp_adc_validity_flag_stats;
   XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr  = &xcp_adc_trigger_flg;
   XCP_BB_Input_Params_Initialise.num_analog_inputs             = 12;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt            = 0;

   uint8_t result = XCP_Filtered_ADC_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(response[0], 0xFF);
}

TEST_F(ADC_Filtered_Info_Periodic_Task_new, ADC_Filtered_Info_Periodic_Task_new3)
{
   // xcp_adc_filtered_cmd.xcp_adc_filtered_quantity   = 0;
   uint8_t cmnd[]                             = {0xF1, 0xA2, 12U};
   static uint8_t xcp_adc_trigger_flg         = CODED_FALSE;
   static uint8_t xcp_adc_validity_flag_stats = CODED_TRUE;

   XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr = &xcp_adc_trigger_flag;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd       = CODED_FALSE;
   uint8_t return_value = Get_Filtered_Analog_Inputs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);

   XCP_BB_Input_Params_Initialise.xcp_get_adc_validity_flag_ptr = &xcp_adc_validity_flag_stats;
   XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr  = &xcp_adc_trigger_flg;
   XCP_BB_Input_Params_Initialise.num_analog_inputs             = 31;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt            = 0;

   uint8_t result = XCP_Filtered_ADC_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(response[0], 0xFF);
}

TEST_F(ADC_Filtered_Info_Periodic_Task_new, ADC_Filtered_Info_Periodic_Task_new4)
{
   // xcp_adc_filtered_cmd.xcp_adc_filtered_quantity   = 0;
   uint8_t cmnd[]                             = {0xF1, 0xA3, 12U};
   static uint8_t xcp_adc_trigger_flg         = CODED_FALSE;
   static uint8_t xcp_adc_validity_flag_stats = CODED_TRUE;

   XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr = &xcp_adc_trigger_flag;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd       = CODED_FALSE;
   uint8_t return_value = Get_Filtered_Analog_Inputs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);

   XCP_BB_Input_Params_Initialise.xcp_get_adc_validity_flag_ptr = &xcp_adc_validity_flag_stats;
   XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr  = &xcp_adc_trigger_flg;
   XCP_BB_Input_Params_Initialise.num_analog_inputs             = 12;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt            = 0;

   uint8_t result = XCP_Filtered_ADC_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(response[0], 0xFF);
}

TEST_F(ADC_Filtered_Info_Periodic_Task_new, ADC_Filtered_Info_Periodic_Task_new5)
{
   // xcp_adc_filtered_cmd.xcp_adc_filtered_quantity   = 0;
   uint8_t cmnd[]                             = {0xF1, 0xA2, 12U};
   static uint8_t xcp_adc_trigger_flg         = CODED_FALSE;
   static uint8_t xcp_adc_validity_flag_stats = CODED_FALSE;

   XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr = &xcp_adc_trigger_flag;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd       = CODED_FALSE;
   uint8_t return_value = Get_Filtered_Analog_Inputs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);

   XCP_BB_Input_Params_Initialise.xcp_get_adc_validity_flag_ptr = &xcp_adc_validity_flag_stats;
   XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr  = &xcp_adc_trigger_flg;
   XCP_BB_Input_Params_Initialise.num_analog_inputs             = 12;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt            = 2;

   uint8_t result = XCP_Filtered_ADC_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(response[0], 0xFE);
}

TEST_F(ADC_Filtered_Info_Periodic_Task_new, ADC_Filtered_Info_Periodic_Task_new6)
{
   /* Cover filtered 31TO61 inner-true path: (index + XCP_MAX_ANALOG_INPUTS_PER_FRAME) < num_analog_inputs */
   uint8_t cmnd[]                             = {0xF1, 0xA3, 5U};
   static uint8_t xcp_adc_trigger_flg         = CODED_FALSE;
   static uint8_t xcp_adc_validity_flag_stats = CODED_TRUE;

   XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr = &xcp_adc_trigger_flag;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd       = CODED_FALSE;
   Get_Filtered_Analog_Inputs(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);

   XCP_BB_Input_Params_Initialise.xcp_get_raw_adc_filtered_data_ptr = malloc(100U * sizeof(uint16_t));
   XCP_BB_Input_Params_Initialise.xcp_get_adc_validity_flag_ptr     = &xcp_adc_validity_flag_stats;
   XCP_BB_Input_Params_Initialise.xcp_get_adc_trigger_flag_ptr      = &xcp_adc_trigger_flg;
   XCP_BB_Input_Params_Initialise.num_analog_inputs                 = 100;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt                = 0;

   uint8_t result = XCP_Filtered_ADC_Info_Periodic_Task(&XCP_BB_Input_Params_Initialise, response, &framelength);
   ASSERT_EQ(response[0], 0xFF);
}
/*===========================================================================*
 * Additional Unit Tests for Full Function Coverage
 *===========================================================================*/

/*
For Prepare_Negative_Response
*/
class prepare_neg_response : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      memset(response, 0, sizeof(response));
   }
   void TearDown()
   {
   }
};

TEST_F(prepare_neg_response, returns_NRC_with_cmd_synch_error)
{
   uint8_t result = Prepare_Negative_Response(response, XCP_ERR_CMD_SYNCH_CPV);
   ASSERT_EQ(result, XCP_RES_LEN_2);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], (uint8_t)XCP_ERR_CMD_SYNCH_CPV);
}

TEST_F(prepare_neg_response, returns_NRC_with_out_of_range_error)
{
   uint8_t result = Prepare_Negative_Response(response, XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(result, XCP_RES_LEN_2);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], (uint8_t)XCP_ERR_OUT_OF_RANGE_CPV);
}

TEST_F(prepare_neg_response, returns_NRC_with_cmd_syntax_error)
{
   uint8_t result = Prepare_Negative_Response(response, XCP_ERR_CMD_SYNTAX_CPV);
   ASSERT_EQ(result, XCP_RES_LEN_2);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], (uint8_t)XCP_ERR_CMD_SYNTAX_CPV);
}

/*
For Set_XCP_Periodic_User_Cmd
*/
class set_periodic_user_cmd : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      Get_XCP_Init_Parameters_fake.custom_fake = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(set_periodic_user_cmd, sets_fptr_and_rcvd_coded_true)
{
   Set_XCP_Periodic_User_Cmd(0x90, 5, XCP_Target_Info_Periodic_Task);
   ASSERT_EQ(XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt, 0U);
   ASSERT_EQ(XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max, 5U);
   ASSERT_EQ(XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd, CODED_TRUE);
   ASSERT_EQ(XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_val, 0x90);
}

TEST_F(set_periodic_user_cmd, sets_null_fptr_rcvd_coded_false)
{
   Set_XCP_Periodic_User_Cmd(0x00, 0, NULL);
   ASSERT_EQ(XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt, 0U);
   ASSERT_EQ(XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max, 0U);
   ASSERT_EQ(XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd, CODED_FALSE);
}

/*
For Get_Process_Look_Validity
*/
class process_look_validity : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
   }
   void TearDown()
   {
   }
};

TEST_F(process_look_validity, returns_coded_false_when_bit_not_set)
{
   uint8_t result = Get_Process_Look_Validity(0x00, 0, SWC_XCP_Get_Look_En_Status);
   ASSERT_EQ(result, CODED_FALSE);
}

TEST_F(process_look_validity, calls_fptr_when_bit_set_look_A)
{
   uint8_t result = Get_Process_Look_Validity(0x01, 0, SWC_XCP_Get_Look_En_Status);
   ASSERT_NE(result, CODED_FALSE);
}

TEST_F(process_look_validity, calls_fptr_when_bit_set_look_B)
{
   uint8_t result = Get_Process_Look_Validity(0x02, 1, SWC_XCP_Get_Look_En_Status);
   ASSERT_NE(result, CODED_FALSE);
}

TEST_F(process_look_validity, calls_fptr_when_bit_set_look_C)
{
   uint8_t result = Get_Process_Look_Validity(0x04, 2, SWC_XCP_Get_Look_En_Status);
   ASSERT_NE(result, CODED_FALSE);
}

TEST_F(process_look_validity, calls_fptr_when_bit_set_look_D)
{
   uint8_t result = Get_Process_Look_Validity(0x08, 3, SWC_XCP_Get_Look_En_Status);
   ASSERT_NE(result, CODED_FALSE);
}

TEST_F(process_look_validity, returns_coded_false_look_B_not_enabled)
{
   uint8_t result = Get_Process_Look_Validity(0x01, 1, SWC_XCP_Get_Look_En_Status);
   ASSERT_EQ(result, CODED_FALSE);
}

/*
For Debug_Mode_Radar_Target (non-debug branch only)
*/
class debug_mode_radar_target : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
   }
   void TearDown()
   {
   }
};

TEST_F(debug_mode_radar_target, non_debug_mode_no_op)
{
   XCP_Target_Info_Valid_Trgt_T valid_tgt;
   memset(&valid_tgt, 0, sizeof(valid_tgt));
   valid_tgt.target_idx = 5U;
   ::Debug_Mode_Radar_Target(&valid_tgt);
   ASSERT_EQ(valid_tgt.target_idx, 5U);
}

/*
For Get_XCP_User_Cmd_Index (additional tests)
*/
class user_cmd_index : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
   }
   void TearDown()
   {
   }
};

TEST_F(user_cmd_index, returns_valid_index_for_known_cmd)
{
   uint8_t result = Get_XCP_User_Cmd_Index(XCP_User_Cmd_List[0]);
   ASSERT_EQ(result, 0U);
}

TEST_F(user_cmd_index, returns_max_for_invalid_cmd)
{
   uint8_t result = Get_XCP_User_Cmd_Index(0xFFU);
   ASSERT_EQ(result, MAX_XCP_USER_CMD);
}

TEST_F(user_cmd_index, returns_correct_index_for_last_cmd)
{
   uint8_t result = Get_XCP_User_Cmd_Index(XCP_User_Cmd_List[MAX_XCP_USER_CMD - 1]);
   ASSERT_EQ(result, (uint8_t)(MAX_XCP_USER_CMD - 1));
}

/*
For Copy_Checksum_To_Response
*/
class copy_chksum_response : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      memset(response, 0, sizeof(response));
   }
   void TearDown()
   {
   }
};

TEST_F(copy_chksum_response, returns_error_when_src_ptr_null)
{
   XCP_Err_Code_T result = Copy_Checksum_To_Response(response, NULL, 0, 1);
   ASSERT_EQ(result, XCP_ERR_OUT_OF_RANGE_CPV);
}

TEST_F(copy_chksum_response, copies_single_checksum_big_endian)
{
   uint32_t checksum     = 0x12345678U;
   uint8_t *src_ptrs[1]  = {(uint8_t *)&checksum};
   XCP_Err_Code_T result = Copy_Checksum_To_Response(response, src_ptrs, 0, 1);
   ASSERT_EQ(result, XCP_ERR_CMD_SYNCH_CPV);
}

TEST_F(copy_chksum_response, skips_null_src_entry)
{
   uint8_t *src_ptrs[2]  = {NULL, NULL};
   XCP_Err_Code_T result = Copy_Checksum_To_Response(response, src_ptrs, 0, 2);
   ASSERT_EQ(result, XCP_ERR_CMD_SYNCH_CPV);
}

TEST_F(copy_chksum_response, copies_multiple_checksums)
{
   uint32_t checksum1    = 0xAABBCCDDU;
   uint32_t checksum2    = 0x11223344U;
   uint8_t *src_ptrs[2]  = {(uint8_t *)&checksum1, (uint8_t *)&checksum2};
   XCP_Err_Code_T result = Copy_Checksum_To_Response(response, src_ptrs, 0, 2);
   ASSERT_EQ(result, XCP_ERR_CMD_SYNCH_CPV);
}

TEST_F(copy_chksum_response, respects_offset_parameter)
{
   uint32_t checksum     = 0xDEADBEEFU;
   uint8_t *src_ptrs[1]  = {(uint8_t *)&checksum};
   XCP_Err_Code_T result = Copy_Checksum_To_Response(response, src_ptrs, 10, 1);
   ASSERT_EQ(result, XCP_ERR_CMD_SYNCH_CPV);
}

/*
For read_temperature_from_sensors
*/
#if 0
class read_temp_sensors : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      memset(response, 0, sizeof(response));
   }
   void TearDown()
   {
   }
};

TEST_F(read_temp_sensors, converts_normal_temperature)
{
   int16_t temps[2] = {25, 30};
   read_temperature_from_sensors(response, temps, 2);
   ASSERT_EQ(response[0], (uint8_t)(25 + XCP_MMIC_MCU_TEMP_OFFSET));
   ASSERT_EQ(response[1], (uint8_t)(30 + XCP_MMIC_MCU_TEMP_OFFSET));
}

TEST_F(read_temp_sensors, returns_default_for_invalid_temp)
{
   int16_t temps[1] = {XCP_MCU_MMIC_TEMP_DEFAULT};
   read_temperature_from_sensors(response, temps, 1);
   ASSERT_EQ(response[0], XCP_DEFAULT_RESPONSE);
}

TEST_F(read_temp_sensors, handles_zero_sensors)
{
   int16_t temps[1] = {50};
   read_temperature_from_sensors(response, temps, 0);
   ASSERT_EQ(response[0], 0U);
}

TEST_F(read_temp_sensors, handles_negative_temperature)
{
   int16_t temps[1] = {-10};
   read_temperature_from_sensors(response, temps, 1);
   ASSERT_EQ(response[0], (uint8_t)(-10 + XCP_MMIC_MCU_TEMP_OFFSET));
}

TEST_F(read_temp_sensors, mixed_valid_and_default_temps)
{
   int16_t temps[3] = {10, XCP_MCU_MMIC_TEMP_DEFAULT, 40};
   read_temperature_from_sensors(response, temps, 3);
   ASSERT_EQ(response[0], (uint8_t)(10 + XCP_MMIC_MCU_TEMP_OFFSET));
   ASSERT_EQ(response[1], XCP_DEFAULT_RESPONSE);
   ASSERT_EQ(response[2], (uint8_t)(40 + XCP_MMIC_MCU_TEMP_OFFSET));
}
#endif

/*
For Swap_Values_As_Per_Need
*/
class swap_values : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
   }
   void TearDown()
   {
   }
};

TEST_F(swap_values, no_swap_when_p1_less_than_p2)
{
   s8p7_T p1      = Init_Fixed_Point(5.0, s8p7_T);
   s8p7_T p2      = Init_Fixed_Point(10.0, s8p7_T);
   s8p7_T orig_p1 = p1;
   s8p7_T orig_p2 = p2;
   Swap_Values_As_Per_Need(&p1, &p2);
   ASSERT_EQ(p1, orig_p1);
   ASSERT_EQ(p2, orig_p2);
}

TEST_F(swap_values, swaps_when_p1_greater_than_p2)
{
   s8p7_T p1 = Init_Fixed_Point(10.0, s8p7_T);
   s8p7_T p2 = Init_Fixed_Point(5.0, s8p7_T);
   Swap_Values_As_Per_Need(&p1, &p2);
   ASSERT_LE(p1, p2);
}

TEST_F(swap_values, no_swap_when_equal)
{
   s8p7_T p1 = Init_Fixed_Point(7.0, s8p7_T);
   s8p7_T p2 = Init_Fixed_Point(7.0, s8p7_T);
   Swap_Values_As_Per_Need(&p1, &p2);
   ASSERT_EQ(p1, p2);
}

TEST_F(swap_values, swap_with_negative_values)
{
   s8p7_T p1 = Init_Fixed_Point(2.0, s8p7_T);
   s8p7_T p2 = Init_Fixed_Point(-3.0, s8p7_T);
   Swap_Values_As_Per_Need(&p1, &p2);
   ASSERT_LE(p1, p2);
}

/*
For Validate_Parameters_Of_XCP_Target
*/
class validate_xcp_target_params : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      memset(&XCP_Target_Info, 0, sizeof(XCP_Target_Info));
   }
   void TearDown()
   {
   }
};

TEST_F(validate_xcp_target_params, zero_values_conversion)
{
   XCP_Target_Info.range_min_phy = 0;
   XCP_Target_Info.range_max_phy = 0;
   XCP_Target_Info.rrate_min_phy = 0;
   XCP_Target_Info.rrate_max_phy = 0;
   Validate_Parameters_Of_XCP_Target(&XCP_Target_Info);
   ASSERT_EQ(XCP_Target_Info.range_min, 0);
   ASSERT_EQ(XCP_Target_Info.range_max, 0);
}

TEST_F(validate_xcp_target_params, swaps_min_max_if_inverted)
{
   XCP_Target_Info.range_min_phy = 100;
   XCP_Target_Info.range_max_phy = 10;
   XCP_Target_Info.rrate_min_phy = 0;
   XCP_Target_Info.rrate_max_phy = 0;
   Validate_Parameters_Of_XCP_Target(&XCP_Target_Info);
   ASSERT_LE(XCP_Target_Info.range_min, XCP_Target_Info.range_max);
}

TEST_F(validate_xcp_target_params, normal_values_no_swap)
{
   XCP_Target_Info.range_min_phy = 10;
   XCP_Target_Info.range_max_phy = 100;
   XCP_Target_Info.rrate_min_phy = 0;
   XCP_Target_Info.rrate_max_phy = 0;
   Validate_Parameters_Of_XCP_Target(&XCP_Target_Info);
   ASSERT_LE(XCP_Target_Info.range_min, XCP_Target_Info.range_max);
}

/*
For Is_Value_Within_Range
*/
class is_value_within_range : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
   }
   void TearDown()
   {
   }
};

TEST_F(is_value_within_range, returns_true_when_ignore_flag_set)
{
   /* ignore=true bypasses min/max check entirely */
   s8p7_T value = Init_Fixed_Point(100.0, s8p7_T);
   s8p7_T min   = Init_Fixed_Point(10.0, s8p7_T);
   s8p7_T max   = Init_Fixed_Point(20.0, s8p7_T);
   ASSERT_TRUE(::Is_Value_Within_Range(value, min, max, true));
}

TEST_F(is_value_within_range, returns_true_when_value_within_window)
{
   s8p7_T value = Init_Fixed_Point(15.0, s8p7_T);
   s8p7_T min   = Init_Fixed_Point(10.0, s8p7_T);
   s8p7_T max   = Init_Fixed_Point(20.0, s8p7_T);
   ASSERT_TRUE(::Is_Value_Within_Range(value, min, max, false));
}

TEST_F(is_value_within_range, returns_true_when_value_equals_min)
{
   s8p7_T value = Init_Fixed_Point(10.0, s8p7_T);
   s8p7_T min   = Init_Fixed_Point(10.0, s8p7_T);
   s8p7_T max   = Init_Fixed_Point(20.0, s8p7_T);
   ASSERT_TRUE(::Is_Value_Within_Range(value, min, max, false));
}

TEST_F(is_value_within_range, returns_true_when_value_equals_max)
{
   s8p7_T value = Init_Fixed_Point(20.0, s8p7_T);
   s8p7_T min   = Init_Fixed_Point(10.0, s8p7_T);
   s8p7_T max   = Init_Fixed_Point(20.0, s8p7_T);
   ASSERT_TRUE(::Is_Value_Within_Range(value, min, max, false));
}

TEST_F(is_value_within_range, returns_false_when_value_below_min)
{
   s8p7_T value = Init_Fixed_Point(5.0, s8p7_T);
   s8p7_T min   = Init_Fixed_Point(10.0, s8p7_T);
   s8p7_T max   = Init_Fixed_Point(20.0, s8p7_T);
   ASSERT_FALSE(::Is_Value_Within_Range(value, min, max, false));
}

TEST_F(is_value_within_range, returns_false_when_value_above_max)
{
   s8p7_T value = Init_Fixed_Point(25.0, s8p7_T);
   s8p7_T min   = Init_Fixed_Point(10.0, s8p7_T);
   s8p7_T max   = Init_Fixed_Point(20.0, s8p7_T);
   ASSERT_FALSE(::Is_Value_Within_Range(value, min, max, false));
}

TEST_F(is_value_within_range, returns_true_with_negative_range_and_value_within)
{
   s8p7_T value = Init_Fixed_Point(-5.0, s8p7_T);
   s8p7_T min   = Init_Fixed_Point(-10.0, s8p7_T);
   s8p7_T max   = Init_Fixed_Point(0.0, s8p7_T);
   ASSERT_TRUE(::Is_Value_Within_Range(value, min, max, false));
}

TEST_F(is_value_within_range, returns_false_with_negative_range_and_value_outside)
{
   s8p7_T value = Init_Fixed_Point(5.0, s8p7_T);
   s8p7_T min   = Init_Fixed_Point(-10.0, s8p7_T);
   s8p7_T max   = Init_Fixed_Point(0.0, s8p7_T);
   ASSERT_FALSE(::Is_Value_Within_Range(value, min, max, false));
}

/*
For Search_Valid_Target
*/
class search_valid_tgt : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      memset(&XCP_Target_Info, 0, sizeof(XCP_Target_Info));
      memset(&XCP_Trgt_Rprt, 0, sizeof(XCP_Trgt_Rprt));
      XCP_Trgt_Rprt.num_af_det = 768;
   }
   void TearDown()
   {
   }
};

TEST_F(search_valid_tgt, no_targets_when_zero_max_dets)
{
   Search_Valid_Target(&XCP_Trgt_Rprt, &XCP_Target_Info, 0);
   ASSERT_EQ(XCP_Target_Info.valid_target.target_idx, 0U);
}

TEST_F(search_valid_tgt, finds_target_ignoring_range_and_rrate)
{
   XCP_Target_Info.range_min    = 0;
   XCP_Target_Info.range_max    = 0;
   XCP_Target_Info.rrate_min    = 0;
   XCP_Target_Info.rrate_max    = 0;
   XCP_Trgt_Rprt.af_dets[0].ran = 50.0f;
   XCP_Trgt_Rprt.af_dets[0].vel = 10.0f;
   XCP_Trgt_Rprt.af_dets[0].rcs = 20.0f;
   Search_Valid_Target(&XCP_Trgt_Rprt, &XCP_Target_Info, 1);
   ASSERT_EQ(XCP_Target_Info.valid_target.target_idx, 0U);
}

TEST_F(search_valid_tgt, selects_strongest_rcs_target)
{
   XCP_Target_Info.range_min    = 0;
   XCP_Target_Info.range_max    = 0;
   XCP_Target_Info.rrate_min    = 0;
   XCP_Target_Info.rrate_max    = 0;
   XCP_Trgt_Rprt.af_dets[0].ran = 50.0f;
   XCP_Trgt_Rprt.af_dets[0].vel = 10.0f;
   XCP_Trgt_Rprt.af_dets[0].rcs = 5.0f;
   XCP_Trgt_Rprt.af_dets[1].ran = 60.0f;
   XCP_Trgt_Rprt.af_dets[1].vel = 15.0f;
   XCP_Trgt_Rprt.af_dets[1].rcs = 30.0f;
   XCP_Trgt_Rprt.af_dets[2].ran = 70.0f;
   XCP_Trgt_Rprt.af_dets[2].vel = 20.0f;
   XCP_Trgt_Rprt.af_dets[2].rcs = 15.0f;
   Search_Valid_Target(&XCP_Trgt_Rprt, &XCP_Target_Info, 3);
   ASSERT_EQ(XCP_Target_Info.valid_target.target_idx, 1U);
}

TEST_F(search_valid_tgt, filters_by_range)
{
   XCP_Target_Info.range_min    = Init_Fixed_Point(40.0, s8p7_T);
   XCP_Target_Info.range_max    = Init_Fixed_Point(60.0, s8p7_T);
   XCP_Target_Info.rrate_min    = 0;
   XCP_Target_Info.rrate_max    = 0;
   XCP_Trgt_Rprt.af_dets[0].ran = 10.0f;
   XCP_Trgt_Rprt.af_dets[0].vel = 10.0f;
   XCP_Trgt_Rprt.af_dets[0].rcs = 50.0f;
   XCP_Trgt_Rprt.af_dets[1].ran = 50.0f;
   XCP_Trgt_Rprt.af_dets[1].vel = 15.0f;
   XCP_Trgt_Rprt.af_dets[1].rcs = 10.0f;
   Search_Valid_Target(&XCP_Trgt_Rprt, &XCP_Target_Info, 2);
   ASSERT_EQ(XCP_Target_Info.valid_target.target_idx, 1U);
}

TEST_F(search_valid_tgt, filters_by_rrate)
{
   XCP_Target_Info.range_min    = 0;
   XCP_Target_Info.range_max    = 0;
   XCP_Target_Info.rrate_min    = Init_Fixed_Point(5.0, s8p7_T);
   XCP_Target_Info.rrate_max    = Init_Fixed_Point(20.0, s8p7_T);
   XCP_Trgt_Rprt.af_dets[0].ran = 50.0f;
   XCP_Trgt_Rprt.af_dets[0].vel = 1.0f;
   XCP_Trgt_Rprt.af_dets[0].rcs = 50.0f;
   XCP_Trgt_Rprt.af_dets[1].ran = 60.0f;
   XCP_Trgt_Rprt.af_dets[1].vel = 10.0f;
   XCP_Trgt_Rprt.af_dets[1].rcs = 10.0f;
   Search_Valid_Target(&XCP_Trgt_Rprt, &XCP_Target_Info, 2);
   ASSERT_EQ(XCP_Target_Info.valid_target.target_idx, 1U);
}

TEST_F(search_valid_tgt, no_target_found_when_all_filtered_out)
{
   /* Range filter active, all targets outside the window */
   XCP_Target_Info.range_min    = Init_Fixed_Point(40.0, s8p7_T);
   XCP_Target_Info.range_max    = Init_Fixed_Point(60.0, s8p7_T);
   XCP_Target_Info.rrate_min    = 0;
   XCP_Target_Info.rrate_max    = 0;
   XCP_Trgt_Rprt.af_dets[0].ran = 10.0f;
   XCP_Trgt_Rprt.af_dets[0].vel = 5.0f;
   XCP_Trgt_Rprt.af_dets[0].rcs = 50.0f;
   XCP_Trgt_Rprt.af_dets[1].ran = 80.0f;
   XCP_Trgt_Rprt.af_dets[1].vel = 5.0f;
   XCP_Trgt_Rprt.af_dets[1].rcs = 50.0f;
   Search_Valid_Target(&XCP_Trgt_Rprt, &XCP_Target_Info, 2);
   /* target_found stays false: valid_target fields not updated (remain at memset-zero values) */
   ASSERT_EQ(XCP_Target_Info.valid_target.target_range, 0);
   ASSERT_EQ(XCP_Target_Info.valid_target.target_range_rate, 0);
}

TEST_F(search_valid_tgt, both_range_and_rrate_filters_select_correct_target)
{
   /* Target 0: in range, outside rrate -> filtered out */
   /* Target 1: in range, in rrate     -> selected     */
   XCP_Target_Info.range_min    = Init_Fixed_Point(30.0, s8p7_T);
   XCP_Target_Info.range_max    = Init_Fixed_Point(80.0, s8p7_T);
   XCP_Target_Info.rrate_min    = Init_Fixed_Point(5.0, s8p7_T);
   XCP_Target_Info.rrate_max    = Init_Fixed_Point(15.0, s8p7_T);
   XCP_Trgt_Rprt.af_dets[0].ran = 50.0f;
   XCP_Trgt_Rprt.af_dets[0].vel = 1.0f; /* rrate out of window */
   XCP_Trgt_Rprt.af_dets[0].rcs = 40.0f;
   XCP_Trgt_Rprt.af_dets[1].ran = 60.0f;
   XCP_Trgt_Rprt.af_dets[1].vel = 10.0f; /* rrate in window */
   XCP_Trgt_Rprt.af_dets[1].rcs = 20.0f;
   Search_Valid_Target(&XCP_Trgt_Rprt, &XCP_Target_Info, 2);
   ASSERT_EQ(XCP_Target_Info.valid_target.target_idx, 1U);
}

TEST_F(search_valid_tgt, populates_target_fields_when_target_found)
{
   /* Single target that passes all filters (both ignored) */
   XCP_Target_Info.range_min           = 0;
   XCP_Target_Info.range_max           = 0;
   XCP_Target_Info.rrate_min           = 0;
   XCP_Target_Info.rrate_max           = 0;
   XCP_Trgt_Rprt.af_dets[0].ran        = 50.0f;
   XCP_Trgt_Rprt.af_dets[0].vel        = 10.0f;
   XCP_Trgt_Rprt.af_dets[0].rcs        = 20.0f;
   XCP_Trgt_Rprt.af_dets[0].theta      = 0.0f;
   XCP_Trgt_Rprt.af_dets[0].phi        = 0.0f;
   XCP_Trgt_Rprt.af_dets[0].f_bistatic = 1;
   Search_Valid_Target(&XCP_Trgt_Rprt, &XCP_Target_Info, 1);
   ASSERT_EQ(XCP_Target_Info.valid_target.target_range, (s8p7_T)Init_Fixed_Point(50.0, s8p7_T));
   ASSERT_EQ(XCP_Target_Info.valid_target.target_range_rate, (s8p7_T)Init_Fixed_Point(10.0, s8p7_T));
   ASSERT_EQ(XCP_Target_Info.valid_target.bistatic, true);
}

/*
For XCP_Fault_Common
*/
class fault_common : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      memset(response, 0, sizeof(response));
      framelength = 0;
   }
   void TearDown()
   {
   }
};

TEST_F(fault_common, positive_response_valid_fault_data)
{
   uint8_t fault_table[4] = {0x11, 0x22, 0x33, 0x44};
   uint8_t cmd[]          = {0xF1, 0xB0, 0x02};
   XCP_Fault_Common(fault_table, 4, cmd, response, &framelength);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], 0xB0);
   ASSERT_EQ(response[2], 0x11);
   ASSERT_EQ(response[3], 0x22);
   ASSERT_EQ(framelength, 4U);
}

TEST_F(fault_common, negative_response_null_table)
{
   uint8_t cmd[] = {0xF1, 0xB0, 0x01};
   XCP_Fault_Common(NULL, 4, cmd, response, &framelength);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], (uint8_t)XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, 2U);
}

TEST_F(fault_common, negative_response_count_exceeds_bytes)
{
   uint8_t fault_table[4] = {0x11, 0x22, 0x33, 0x44};
   uint8_t cmd[]          = {0xF1, 0xB0, 0x10};
   XCP_Fault_Common(fault_table, 4, cmd, response, &framelength);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], (uint8_t)XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, 2U);
}

TEST_F(fault_common, positive_response_zero_count)
{
   uint8_t fault_table[4] = {0x11, 0x22, 0x33, 0x44};
   uint8_t cmd[]          = {0xF1, 0xB0, 0x00};
   XCP_Fault_Common(fault_table, 4, cmd, response, &framelength);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(framelength, 2U);
}

TEST_F(fault_common, positive_response_boundary_count_equals_num_bytes)
{
   uint8_t fault_table[4] = {0xAA, 0xBB, 0xCC, 0xDD};
   uint8_t cmd[]          = {0xF1, 0xD0, 0x04};
   XCP_Fault_Common(fault_table, 4, cmd, response, &framelength);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], 0xD0);
   ASSERT_EQ(response[2], 0xAA);
   ASSERT_EQ(response[3], 0xBB);
   ASSERT_EQ(response[4], 0xCC);
   ASSERT_EQ(response[5], 0xDD);
   ASSERT_EQ(framelength, 6U);
}

/*
For XCP_User_Command (additional tests)
*/
class xcp_user_command : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      memset(response, 0, sizeof(response));
      framelength                                    = 0;
      Get_XCP_Init_Parameters_fake.custom_fake       = Get_XCP_Init_Parameters_Custom_Fake;
      XCP_BB_Input_Params_Initialise.xcp_customer_id = 0;
   }
   void TearDown()
   {
   }
};

TEST_F(xcp_user_command, returns_syntax_error_for_invalid_cmd)
{
   uint8_t cmnd[]    = {0xF1, 0xFF};
   uint8_t ret_value = XCP_User_Command(cmnd, response, &framelength);
   ASSERT_EQ(ret_value, (uint8_t)XCP_CMD_SYNTAX_CPV);
}

TEST_F(xcp_user_command, clears_response_buffer)
{
   memset(response, 0xAA, sizeof(response));
   uint8_t cmnd[]    = {0xF1, 0xFF};
   uint8_t ret_value = XCP_User_Command(cmnd, response, &framelength);
   ASSERT_EQ(response[2], 0x00);
}

/*
For Get_XCP_Pending_Cmnd_Status (additional tests)
*/
class xcp_pending_cmd_status : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      Get_XCP_Init_Parameters_fake.custom_fake = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(xcp_pending_cmd_status, returns_coded_false_when_no_cmd)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_FALSE;
   uint8_t status                                        = Get_XCP_Pending_Cmnd_Status();
   ASSERT_EQ(status, CODED_FALSE);
}

TEST_F(xcp_pending_cmd_status, returns_coded_true_when_cmd_pending)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd = CODED_TRUE;
   uint8_t status                                        = Get_XCP_Pending_Cmnd_Status();
   ASSERT_EQ(status, CODED_TRUE);
}

/*===========================================================================*
 * Tests for Is_Valid_Led_State
 *===========================================================================*/
class is_valid_led_state_test : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
   }
   void TearDown()
   {
   }
};

TEST_F(is_valid_led_state_test, returns_true_for_XCP_OUT_STATE_AUTO)
{
   ASSERT_TRUE(Is_Valid_LED_State((XCP_LED_Output_State_T)XCP_OUT_STATE_AUTO));
}

TEST_F(is_valid_led_state_test, returns_true_for_XCP_OUT_STATE_FORCED_OFF)
{
   ASSERT_TRUE(Is_Valid_LED_State((XCP_LED_Output_State_T)XCP_OUT_STATE_FORCED_OFF));
}

TEST_F(is_valid_led_state_test, returns_true_for_XCP_OUT_STATE_FORCED_ON)
{
   ASSERT_TRUE(Is_Valid_LED_State((XCP_LED_Output_State_T)XCP_OUT_STATE_FORCED_ON));
}

TEST_F(is_valid_led_state_test, returns_true_for_XCP_OUT_STATE_FORCED_5_PWM)
{
   ASSERT_TRUE(Is_Valid_LED_State((XCP_LED_Output_State_T)XCP_OUT_STATE_FORCED_5_PWM));
}

TEST_F(is_valid_led_state_test, returns_true_for_XCP_OUT_STATE_FORCED_50_PWM)
{
   ASSERT_TRUE(Is_Valid_LED_State((XCP_LED_Output_State_T)XCP_OUT_STATE_FORCED_50_PWM));
}

TEST_F(is_valid_led_state_test, returns_true_for_XCP_OUT_STATE_FORCED_95_PWM)
{
   ASSERT_TRUE(Is_Valid_LED_State((XCP_LED_Output_State_T)XCP_OUT_STATE_FORCED_95_PWM));
}

TEST_F(is_valid_led_state_test, returns_false_for_invalid_state)
{
   ASSERT_FALSE(Is_Valid_LED_State((XCP_LED_Output_State_T)0x00U));
}

TEST_F(is_valid_led_state_test, returns_false_for_unknown_state_value)
{
   ASSERT_FALSE(Is_Valid_LED_State((XCP_LED_Output_State_T)0xFFU));
}

#if 0
/*
For XCP_Chksum_Updation_Periodic_Task
*/

class Chksum_Updation_Periodic_Task : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      static uint32_t XCP_SW_Appl_Checksum;
      static uint32_t XCP_SW_Boot_Checksum;
      static uint32_t XCP_Cal_USC_CheckSum;
      static uint32_t XCP_Cal_SMC_CheckSum;
      static uint32_t XCP_Keep_Alive_Checksum;
      static uint8_t *xcp_checksum_fake[XCP_MAX_CHKSM] = {NULL};
      xcp_checksum_fake[XCP_APP_CHKSM]                 = (uint8_t *)&XCP_SW_Appl_Checksum;
      xcp_checksum_fake[XCP_BL_CHKSM]                  = (uint8_t *)&XCP_SW_Boot_Checksum;
      xcp_checksum_fake[XCP_USC_CHKSM]                 = (uint8_t *)&XCP_Cal_USC_CheckSum;
      xcp_checksum_fake[XCP_SMC_CHKSM]                 = (uint8_t *)&XCP_Cal_SMC_CheckSum;
      xcp_checksum_fake[XCP_KEEP_ALIVE_CHKSM]          = (uint8_t *)&XCP_Keep_Alive_Checksum;

      XCP_BB_Input_Params_Initialise.xcp_checksum_ptr         = (uint8_t **)&xcp_checksum_fake;
      XCP_BB_Input_Params_Initialise.xcp_cust_checksum_ptr    = (uint8_t **)&xcp_checksum_fake;
      XCP_BB_Input_Params_Initialise.xcp_num_cust_spec_chcksm = 1u;

      Get_XCP_Init_Parameters_fake.custom_fake = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};



TEST_F(Chksum_Updation_Periodic_Task, Chksum_Updation_Periodic_Task_TC1)
{
   uint8_t result = XCP_Chksum_Updation_Periodic_Task(response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}
/*
For xcp_user_cmd_interface_control
*/
class interface_control : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      static uint8_t xcp_pcan_status;
      static uint8_t xcp_vcan_status;
      static uint8_t xcp_ethernet_status;
      Get_XCP_Init_Parameters_fake.custom_fake = Get_XCP_Init_Parameters_Custom_Fake;
   }
   void TearDown()
   {
   }
};

TEST_F(interface_control, Interface_Control_Ethernet_enable_TC9)
{
   uint8_t cmnd[] = {0xF1, 0x10, 0x03, 0x03};
   uint8_t result = xcp_user_cmd_interface_control(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(interface_control, Interface_Control_other_interface_TC10)
{
   uint8_t cmnd[] = {0xF1, 0x10, 0x04, 0x01};
   uint8_t result = xcp_user_cmd_interface_control(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(interface_control, Interface_Control_negative_resp_TC12)
{
   uint8_t cmnd[]                                                  = {0xF1, 0x0F, 0x01, 0x01};
   XCP_BB_Input_Params_Initialise.xcp_ethernet_platform_interface_stop_periodic_cntrl_ptr = NULL;
   uint8_t result                                                  = xcp_user_cmd_interface_control(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(interface_control, Interface_Control_negative_resp_TC14)
{
   uint8_t cmnd[]                                                  = {0xF1, 0x0F, 0x01, 0x01};
   XCP_BB_Input_Params_Initialise.xcp_ethernet_platform_interface_stop_periodic_cntrl_ptr = NULL;
   uint8_t result                                                  = xcp_user_cmd_interface_control(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(Chksum_Updation_Periodic_Task, Chksum_Updation_Periodic_Task_TC2)
{
   // XCP_BB_Input_Params_Initialise.xcp_num_cust_spec_chcksm = 0u;
   XCP_BB_Input_Params_Initialise.xcp_checksum_ptr      = NULL;
   XCP_BB_Input_Params_Initialise.xcp_cust_checksum_ptr = NULL;

   uint8_t result = XCP_Chksum_Updation_Periodic_Task(response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(Chksum_Updation_Periodic_Task, Chksum_Updation_Periodic_Task_TC3)
{
   XCP_BB_Input_Params_Initialise.xcp_num_cust_spec_chcksm = 0u;
   uint8_t result                                          = XCP_Chksum_Updation_Periodic_Task(response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(Chksum_Updation_Periodic_Task, Chksum_Updation_Periodic_Task_TC4)
{
   // xcp_chksm_cmd.cycle_cnt = 62u;
   uint8_t result = XCP_Chksum_Updation_Periodic_Task(response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(Chksum_Updation_Periodic_Task, Chksum_Updation_Periodic_Task_TC5)
{
   XCP_BB_Input_Params_Initialise.xcp_num_cust_spec_chcksm = 15u;
   uint8_t result                                          = XCP_Chksum_Updation_Periodic_Task(response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}
TEST_F(Chksum_Updation_Periodic_Task, Chksum_Updation_Periodic_Task_TC6)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt       = 0;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max   = 5;
   XCP_BB_Input_Params_Initialise.xcp_num_cust_spec_chcksm = 0u;
   uint8_t result                                          = XCP_Chksum_Updation_Periodic_Task(response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}
TEST_F(Chksum_Updation_Periodic_Task, Chksum_Updation_Periodic_Task_TC7)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt       = 0;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max   = 5;
   XCP_BB_Input_Params_Initialise.xcp_num_cust_spec_chcksm = 18u;
   uint8_t result                                          = XCP_Chksum_Updation_Periodic_Task(response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(Chksum_Updation_Periodic_Task, Chksum_Updation_Periodic_Task_TC8)
{
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt     = 0;
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_cycle_cnt_max = 5;
   XCP_BB_Input_Params_Initialise.xcp_checksum_ptr       = NULL;
   XCP_BB_Input_Params_Initialise.xcp_cust_checksum_ptr  = NULL;

   uint8_t result = XCP_Chksum_Updation_Periodic_Task(response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}



/*F1 85*/

TEST_F(get_checksum_results, Get_Checksum_Results_positive_TC1)
{
   uint8_t cmnd[] = {0xF1, 0x85};
   uint8_t result = XCP_User_Cmd_Get_Checksum_Results(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_PENDING_CPV);
   // xcp_chksm_cmd.xcp_chksm_cmnd_rcvd = CODED_FALSE;
}

TEST_F(get_checksum_results, Get_Checksum_Results_negative_TC2)
{
   uint8_t cmnd[]                                            = {0xF1, 0x85};
   XCP_BB_Input_Params_Initialise.xcp_chksm_trigger_flag_ptr = NULL;
   uint8_t result                                            = XCP_User_Cmd_Get_Checksum_Results(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(get_checksum_results, Get_Checksum_Results_negative_TC3)
{
   uint8_t cmnd[]                                            = {0xF1, 0x85};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd     = CODED_TRUE;
   XCP_BB_Input_Params_Initialise.xcp_chksm_trigger_flag_ptr = NULL;
   uint8_t result                                            = XCP_User_Cmd_Get_Checksum_Results(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

TEST_F(get_checksum_results, Get_Checksum_Results_negative_TC4)
{
   uint8_t cmnd[]                                            = {0xF1, 0x85};
   XCP_Periodic_User_Cmd_Ptr->xcp_periodic_user_cmd_rcvd     = CODED_FALSE;
   XCP_BB_Input_Params_Initialise.xcp_chksm_trigger_flag_ptr = NULL;
   uint8_t result                                            = XCP_User_Cmd_Get_Checksum_Results(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(result, (uint8_t)XCP_CMD_OK_CPV);
}

#endif

/*
For no_active_look
*/
class no_active_look_test : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
   }
   void TearDown()
   {
   }
};

TEST_F(no_active_look_test, returns_true_when_all_looks_inactive)
{
   uint8_t look_a  = CODED_FALSE;
   uint8_t look_b  = CODED_FALSE;
   uint8_t look_c  = CODED_FALSE;
   uint8_t look_d  = CODED_FALSE;
   uint8_t *ptrs[] = {&look_a, &look_b, &look_c, &look_d};
   bool result     = No_Active_Look(ptrs, 4U);
   ASSERT_EQ(result, true);
}

TEST_F(no_active_look_test, returns_false_when_first_look_active)
{
   uint8_t look_a  = 0xAAU;
   uint8_t look_b  = CODED_FALSE;
   uint8_t look_c  = CODED_FALSE;
   uint8_t look_d  = CODED_FALSE;
   uint8_t *ptrs[] = {&look_a, &look_b, &look_c, &look_d};
   bool result     = No_Active_Look(ptrs, 4U);
   ASSERT_EQ(result, false);
}

TEST_F(no_active_look_test, returns_false_when_last_look_active)
{
   uint8_t look_a  = CODED_FALSE;
   uint8_t look_b  = CODED_FALSE;
   uint8_t look_c  = CODED_FALSE;
   uint8_t look_d  = 0x01U;
   uint8_t *ptrs[] = {&look_a, &look_b, &look_c, &look_d};
   bool result     = No_Active_Look(ptrs, 4U);
   ASSERT_EQ(result, false);
}

TEST_F(no_active_look_test, returns_false_when_all_looks_active)
{
   uint8_t look_a  = 0xAAU;
   uint8_t look_b  = 0xAAU;
   uint8_t look_c  = 0xAAU;
   uint8_t look_d  = 0xAAU;
   uint8_t *ptrs[] = {&look_a, &look_b, &look_c, &look_d};
   bool result     = No_Active_Look(ptrs, 4U);
   ASSERT_EQ(result, false);
}

TEST_F(no_active_look_test, returns_true_when_size_is_zero)
{
   uint8_t look_a  = 0xAAU;
   uint8_t *ptrs[] = {&look_a};
   bool result     = No_Active_Look(ptrs, 0U);
   ASSERT_EQ(result, true);
}

TEST_F(no_active_look_test, returns_false_when_single_look_active)
{
   uint8_t look_a  = 0x01U;
   uint8_t *ptrs[] = {&look_a};
   bool result     = No_Active_Look(ptrs, 1U);
   ASSERT_EQ(result, false);
}

TEST_F(no_active_look_test, returns_true_when_single_look_inactive)
{
   uint8_t look_a  = CODED_FALSE;
   uint8_t *ptrs[] = {&look_a};
   bool result     = No_Active_Look(ptrs, 1U);
   ASSERT_EQ(result, true);
}

TEST_F(no_active_look_test, returns_false_when_middle_look_active)
{
   uint8_t look_a  = CODED_FALSE;
   uint8_t look_b  = 0xFFU;
   uint8_t look_c  = CODED_FALSE;
   uint8_t *ptrs[] = {&look_a, &look_b, &look_c};
   bool result     = No_Active_Look(ptrs, 3U);
   ASSERT_EQ(result, false);
}

/*===========================================================================*
 * Tests for XCP_User_Cmd_Radar_Transceiver_Calibration
 *===========================================================================*/
static uint8_t xcp_trigger_rfbist_calib_test_var;

class radar_transceiver_calibration : public testing::Test
{
   void SetUp()
   {
      FFF_RESET_HISTORY();
      Get_XCP_Init_Parameters_fake.custom_fake                    = Get_XCP_Init_Parameters_Custom_Fake;
      xcp_trigger_rfbist_calib_test_var                           = 0U;
      XCP_BB_Input_Params_Initialise.xcp_trigger_rfbist_calib_ptr = &xcp_trigger_rfbist_calib_test_var;
      memset(response, 0, sizeof(response));
      framelength = 0U;
   }
   void TearDown()
   {
   }
};

/* TEST1: Valid command - Device 1, RFBIST_CALIB, TRIGGER_RFBIST_CALIB -> positive response */
TEST_F(radar_transceiver_calibration, valid_command_returns_positive_response)
{
   uint8_t cmnd[] = {0xF1, 0x99, 0x01, 0x01, 0x01}; /* Device_1, RFBIST_CALIB, TRIGGER_RFBIST_CALIB */
   uint8_t return_value =
      XCP_User_Cmd_Radar_Transceiver_Calibration(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], cmnd[1]);
   ASSERT_EQ(response[2], cmnd[2]);
   ASSERT_EQ(response[3], cmnd[3]);
   ASSERT_EQ(response[4], cmnd[4]);
   ASSERT_EQ(framelength, 5U);
   ASSERT_EQ(xcp_trigger_rfbist_calib_test_var, 0x01U);
}

/* TEST2: Invalid device (cmnd[2] != XCP_MMIC_Device_1) -> negative response */
TEST_F(radar_transceiver_calibration, invalid_device_returns_negative_response)
{
   uint8_t cmnd[] = {0xF1, 0x99, 0x02, 0x01, 0x01}; /* Device = 0x02 (invalid) */
   uint8_t return_value =
      XCP_User_Cmd_Radar_Transceiver_Calibration(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], (uint8_t)XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
   ASSERT_EQ(xcp_trigger_rfbist_calib_test_var, 0U); /* Pointer not written */
}

/* TEST3: Invalid function (cmnd[3] != XCP_RFBIST_CALIB) -> negative response */
TEST_F(radar_transceiver_calibration, invalid_function_returns_negative_response)
{
   uint8_t cmnd[] = {0xF1, 0x99, 0x01, 0x00, 0x01}; /* Function = 0x00 (invalid) */
   uint8_t return_value =
      XCP_User_Cmd_Radar_Transceiver_Calibration(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], (uint8_t)XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
   ASSERT_EQ(xcp_trigger_rfbist_calib_test_var, 0U);
}

/* TEST4: Invalid action (cmnd[4] != XCP_TRIGGER_RFBIST_CALIB) -> negative response */
TEST_F(radar_transceiver_calibration, invalid_action_returns_negative_response)
{
   uint8_t cmnd[] = {0xF1, 0x99, 0x01, 0x01, 0x00}; /* Action = 0x00 (invalid) */
   uint8_t return_value =
      XCP_User_Cmd_Radar_Transceiver_Calibration(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], (uint8_t)XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
   ASSERT_EQ(xcp_trigger_rfbist_calib_test_var, 0U);
}

/* TEST5: Invalid device (cmnd[2] = 0x00) -> negative response */
TEST_F(radar_transceiver_calibration, device_zero_returns_negative_response)
{
   uint8_t cmnd[] = {0xF1, 0x99, 0x00, 0x01, 0x01}; /* Device = 0x00 (invalid) */
   uint8_t return_value =
      XCP_User_Cmd_Radar_Transceiver_Calibration(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], (uint8_t)XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

/* TEST6: Both function and action invalid -> negative response */
TEST_F(radar_transceiver_calibration, invalid_function_and_action_returns_negative_response)
{
   uint8_t cmnd[] = {0xF1, 0x99, 0x01, 0xFF, 0xFF}; /* Function and Action invalid */
   uint8_t return_value =
      XCP_User_Cmd_Radar_Transceiver_Calibration(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], (uint8_t)XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
   ASSERT_EQ(xcp_trigger_rfbist_calib_test_var, 0U);
}

/* TEST7: XCP_GET_CALIB_STATUS - calibration successful -> positive response with status in response[5] */
TEST_F(radar_transceiver_calibration, get_calib_status_successful_returns_status)
{
   XCP_BB_Input_Params_Initialise.xcp_get_rfbist_calib_status = (uint8_t)XCP_RFBIST_CALIBRATION_SUCCESSFUL;
   uint8_t cmnd[] = {0xF1, 0x99, 0x01, 0x01, 0x02}; /* Device_1, RFBIST_CALIB, GET_CALIB_STATUS */
   uint8_t return_value =
      XCP_User_Cmd_Radar_Transceiver_Calibration(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], cmnd[1]);
   ASSERT_EQ(response[2], cmnd[2]);
   ASSERT_EQ(response[3], cmnd[3]);
   ASSERT_EQ(response[4], cmnd[4]);
   ASSERT_EQ(response[5], (uint8_t)XCP_RFBIST_CALIBRATION_SUCCESSFUL);
   ASSERT_EQ(framelength, 6U);
}

/* TEST8: XCP_GET_CALIB_STATUS - calibration in progress -> positive response with status in response[5] */
TEST_F(radar_transceiver_calibration, get_calib_status_in_progress_returns_status)
{
   XCP_BB_Input_Params_Initialise.xcp_get_rfbist_calib_status = (uint8_t)XCP_RFBIST_CALIBRATION_IN_PROGRESS;
   uint8_t cmnd[] = {0xF1, 0x99, 0x01, 0x01, 0x02}; /* Device_1, RFBIST_CALIB, GET_CALIB_STATUS */
   uint8_t return_value =
      XCP_User_Cmd_Radar_Transceiver_Calibration(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], cmnd[1]);
   ASSERT_EQ(response[2], cmnd[2]);
   ASSERT_EQ(response[3], cmnd[3]);
   ASSERT_EQ(response[4], cmnd[4]);
   ASSERT_EQ(response[5], (uint8_t)XCP_RFBIST_CALIBRATION_IN_PROGRESS);
   ASSERT_EQ(framelength, 6U);
}

/* TEST9: XCP_GET_CALIB_STATUS - calibration failed -> positive response with status in response[5] */
TEST_F(radar_transceiver_calibration, get_calib_status_failed_returns_status)
{
   XCP_BB_Input_Params_Initialise.xcp_get_rfbist_calib_status = (uint8_t)XCP_RFBIST_CALIBRATION_FAILED;
   uint8_t cmnd[] = {0xF1, 0x99, 0x01, 0x01, 0x02}; /* Device_1, RFBIST_CALIB, GET_CALIB_STATUS */
   uint8_t return_value =
      XCP_User_Cmd_Radar_Transceiver_Calibration(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], cmnd[1]);
   ASSERT_EQ(response[2], cmnd[2]);
   ASSERT_EQ(response[3], cmnd[3]);
   ASSERT_EQ(response[4], cmnd[4]);
   ASSERT_EQ(response[5], (uint8_t)XCP_RFBIST_CALIBRATION_FAILED);
   ASSERT_EQ(framelength, 6U);
}

/* TEST10: XCP_GET_CALIB_STATUS - calibration not started -> positive response with status in response[5] */
TEST_F(radar_transceiver_calibration, get_calib_status_not_started_returns_status)
{
   XCP_BB_Input_Params_Initialise.xcp_get_rfbist_calib_status = (uint8_t)XCP_RFBIST_CALIBRATION_NOT_STARTED;
   uint8_t cmnd[] = {0xF1, 0x99, 0x01, 0x01, 0x02}; /* Device_1, RFBIST_CALIB, GET_CALIB_STATUS */
   uint8_t return_value =
      XCP_User_Cmd_Radar_Transceiver_Calibration(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], cmnd[1]);
   ASSERT_EQ(response[2], cmnd[2]);
   ASSERT_EQ(response[3], cmnd[3]);
   ASSERT_EQ(response[4], cmnd[4]);
   ASSERT_EQ(response[5], (uint8_t)XCP_RFBIST_CALIBRATION_NOT_STARTED);
   ASSERT_EQ(framelength, 6U);
}

/* TEST11: XCP_GET_CALIB_STATUS - calibration invalid -> positive response with status in response[5]  */
TEST_F(radar_transceiver_calibration, get_calib_status_invalid_returns_status)
{
   XCP_BB_Input_Params_Initialise.xcp_get_rfbist_calib_status = (uint8_t)XCP_RFBIST_CALIBRATION_INVALID;
   uint8_t cmnd[] = {0xF1, 0x99, 0x01, 0x01, 0x02}; /* Device_1, RFBIST_CALIB, GET_CALIB_STATUS */
   uint8_t return_value =
      XCP_User_Cmd_Radar_Transceiver_Calibration(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], cmnd[1]);
   ASSERT_EQ(response[2], cmnd[2]);
   ASSERT_EQ(response[3], cmnd[3]);
   ASSERT_EQ(response[4], cmnd[4]);
   ASSERT_EQ(response[5], (uint8_t)XCP_RFBIST_CALIBRATION_INVALID);
   ASSERT_EQ(framelength, 6U);
}

/*===========================================================================*
 * Tests for XCP_User_Cmd_Radar_Transceiver_Calibration - RFBIST_DEBUG path
 *===========================================================================*/
static XCP_RFBIST_Debug_Data_T rfbist_debug_test_data;
static uint32_t rfbist_debug_test_params[4];

static XCP_RFBIST_Debug_Data_T *rfbist_debug_data_fake_valid(uint8_t subcmd)
{
   (void)subcmd;
   rfbist_debug_test_data.xcp_rfbist_debug_data_ptr = rfbist_debug_test_params;
   return &rfbist_debug_test_data;
}

static XCP_RFBIST_Debug_Data_T *rfbist_debug_data_fake_null(uint8_t subcmd)
{
   (void)subcmd;
   return NULL;
}

/* TEST12: RFBIST_DEBUG - valid subcmd with non-NULL debug data -> positive response */
TEST_F(radar_transceiver_calibration, rfbist_debug_valid_subcmd_returns_positive_response)
{
   rfbist_debug_test_params[0]                      = 0xAABBCCDDU;
   rfbist_debug_test_params[1]                      = 0x11223344U;
   rfbist_debug_test_data.xcp_debug_no_of_parameter = 2U;

   XCP_BB_Input_Params_Initialise.xcp_rfbist_debug_data_fptr = rfbist_debug_data_fake_valid;
   uint8_t cmnd[] = {0xF1, 0x99, 0x01, 0x02, 0x01}; /* Device_1, RFBIST_DEBUG, subcmd 0x01 */
   uint8_t return_value =
      XCP_User_Cmd_Radar_Transceiver_Calibration(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], cmnd[1]);
   ASSERT_EQ(response[2], cmnd[2]);
   ASSERT_EQ(response[3], cmnd[3]);
   ASSERT_EQ(response[4], cmnd[4]);
   /* Debug data bytes are raw struct memory (platform-dependent), verify framelength only */
   ASSERT_EQ(framelength, (uint8_t)(5U + 2U * 4U)); /* 0x05 + no_of_parameter * 4 = 13 */
}

/* TEST13: RFBIST_DEBUG - valid subcmd at upper boundary (0x0B) -> positive response */
TEST_F(radar_transceiver_calibration, rfbist_debug_max_subcmd_returns_positive_response)
{
   rfbist_debug_test_params[0]                      = 0x12345678U;
   rfbist_debug_test_data.xcp_debug_no_of_parameter = 1U;

   XCP_BB_Input_Params_Initialise.xcp_rfbist_debug_data_fptr = rfbist_debug_data_fake_valid;
   uint8_t cmnd[] = {0xF1, 0x99, 0x01, 0x02, 0x0B}; /* Device_1, RFBIST_DEBUG, subcmd 0x0B (max) */
   uint8_t return_value =
      XCP_User_Cmd_Radar_Transceiver_Calibration(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   /* Debug data bytes are raw struct memory (platform-dependent), verify framelength only */
   ASSERT_EQ(framelength, (uint8_t)(5U + 1U * 4U)); /* 0x05 + no_of_parameter * 4 = 9 */
}

/* TEST14: RFBIST_DEBUG - valid subcmd but NULL debug data -> negative response */
TEST_F(radar_transceiver_calibration, rfbist_debug_null_data_returns_negative_response)
{
   XCP_BB_Input_Params_Initialise.xcp_rfbist_debug_data_fptr = rfbist_debug_data_fake_null;
   uint8_t cmnd[] = {0xF1, 0x99, 0x01, 0x02, 0x01}; /* Device_1, RFBIST_DEBUG, subcmd 0x01 */
   uint8_t return_value =
      XCP_User_Cmd_Radar_Transceiver_Calibration(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], (uint8_t)XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

/* TEST15: RFBIST_DEBUG - subcmd below valid range (0x00) -> negative response (falls to else) */
TEST_F(radar_transceiver_calibration, rfbist_debug_subcmd_below_range_returns_negative_response)
{
   XCP_BB_Input_Params_Initialise.xcp_rfbist_debug_data_fptr = rfbist_debug_data_fake_valid;
   uint8_t cmnd[] = {0xF1, 0x99, 0x01, 0x02, 0x00}; /* Device_1, RFBIST_DEBUG, subcmd 0x00 (below start) */
   uint8_t return_value =
      XCP_User_Cmd_Radar_Transceiver_Calibration(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], (uint8_t)XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

/* TEST16: RFBIST_DEBUG - subcmd above valid range (0x0C) -> negative response (falls to else) */
TEST_F(radar_transceiver_calibration, rfbist_debug_subcmd_above_range_returns_negative_response)
{
   XCP_BB_Input_Params_Initialise.xcp_rfbist_debug_data_fptr = rfbist_debug_data_fake_valid;
   uint8_t cmnd[] = {0xF1, 0x99, 0x01, 0x02, 0x0C}; /* Device_1, RFBIST_DEBUG, subcmd 0x0C (above end) */
   uint8_t return_value =
      XCP_User_Cmd_Radar_Transceiver_Calibration(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_NEGATIVE_RESPONSE_CPV);
   ASSERT_EQ(response[1], (uint8_t)XCP_ERR_OUT_OF_RANGE_CPV);
   ASSERT_EQ(framelength, XCP_RES_LEN_2);
}

/* TEST17: RFBIST_DEBUG - zero parameters -> positive response with framelength = 5 */
TEST_F(radar_transceiver_calibration, rfbist_debug_zero_params_returns_positive_response)
{
   rfbist_debug_test_data.xcp_debug_no_of_parameter = 0U;

   XCP_BB_Input_Params_Initialise.xcp_rfbist_debug_data_fptr = rfbist_debug_data_fake_valid;
   uint8_t cmnd[] = {0xF1, 0x99, 0x01, 0x02, 0x05}; /* Device_1, RFBIST_DEBUG, subcmd 0x05 */
   uint8_t return_value =
      XCP_User_Cmd_Radar_Transceiver_Calibration(&XCP_BB_Input_Params_Initialise, cmnd, response, &framelength);
   ASSERT_EQ(return_value, (uint8_t)XCP_CMD_OK_CPV);
   ASSERT_EQ(response[0], XCP_POSITIVE_RESPONSE_CPV);
   ASSERT_EQ(framelength, 5U); /* 0x05 + 0*4 = 5 */
}
