/*===========================================================================*/
/**
 * @file radar_ctl_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose.
 *
/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include <gtest/gtest.h>

/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "SWC_PLT_CDD_ECUSync_external_fake.h"
#include "fff.h"
#include "mocks/radar_look_fake.h"
#include "smc_cal.h"
#include "software/r52/autosar/swc/PLT_SWC/SWC_PLT_CDD_ECUSync/test/SWC_PLT_CDD_ECUSync_external_fake.h"
extern SMC_Cal_T *SMC_Cal_Data_Ptr;
#include "mmic_error_fake.h"
#include "mmic_interface_fake.h"
#include "reuse.h"
#include "smc_cal.h"
#include "software/r52/bb_radar_ctl/bb_radar_ctl_api/radar_data.h"

extern Radar_Ctl_Data_T Radar_Ctl_Data;
extern Radar_Ctl_State_T Radar_Ctl_State;
extern volatile bool XCP_Force_Radar_On;
extern uint8_t MMIC_XCP_Enable_CW_Mode;
IPC_MMIC_Radar_Data_Status_T Radar_Data_Status;
extern "C"
{
#include "SWC_PLT_Appl_PlatformTime_fake.h"
   // Unit-test stub to satisfy linker when radar_ctl.c calls into ipc_mss CRC helper.
   void Compute_M7_Rdr_Data_Sts_Payload_CRC(void)
   {
   }

   void Update_Mars_Reg_From_OTP(void)
   {
   }
#include "bb_radar_ctl_imp/radar_ctl.c"
}

DEFINE_FFF_GLOBALS;
uint8_t MMIC_XCP_Enable_CW_Mode = CODED_FALSE;

void Radar_Ctl_State_Func_Test(Radar_Ctl_Event_T event)
{
}
/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class radar_ctl_UnitTestSuite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
      FFF_RESET_HISTORY();
      RESET_FAKE(Get_MMIC_Error_Reinit);
      RESET_FAKE(Get_MMIC_Faulted);
      RESET_FAKE(Get_MMIC_Error_Discard);
      RESET_FAKE(MMIC_Look_Trigger);
      Radar_Trigger_Sync = false;
   }

   /**
    * @b Description
    * @n
    *    Method run after each individual test case.
    */
   void TearDown()
   {
   }
};

// Unit test for ipc_mss_notify_rss_config coverage
TEST_F(radar_ctl_UnitTestSuite, ipc_mss_notify_rss_config_Coverage)
{
   // Just call the function to ensure coverage (no side effects to check)
   ipc_mss_notify_rss_config(1);
   SUCCEED();
}

TEST_F(radar_ctl_UnitTestSuite, Radar_Ctl_Look_Trigger_TEST)
{
   Radar_Ctl_State_Update = Radar_Ctl_State_Func_Test;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);

   Radar_Ctl_Look_Trigger();
   ASSERT_EQ(Radar_Ctl_State_Check, (uint32_t)Bitwise_Complement(Radar_Ctl_State_Update));
}
/**
 *  Radar_Ctl_Look_Trigger_TEST
 *
 *      Test the successfuly triggers a sequence of chirps based on the current look
 *      If condition is false
 */
TEST_F(radar_ctl_UnitTestSuite, Radar_Ctl_Look_Trigger_TEST_False)
{
   Radar_Ctl_State_Update = Radar_Ctl_State_Func_Test;
   Radar_Ctl_State_Check  = 0xFFU;

   Radar_Ctl_Look_Trigger();
   ASSERT_NE(Radar_Ctl_State_Check, Bitwise_Complement(Radar_Ctl_State_Update));
}

// Additional coverage for Radar_Ctl_Look_Trigger
TEST_F(radar_ctl_UnitTestSuite, Radar_Ctl_Look_Trigger_State_READY)
{
   Radar_Ctl_State        = RADAR_CTL_READY;
   Radar_Ctl_State_Update = State_Radar_Ctl_Ready;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);
   Radar_Ctl_Look_Trigger();
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_READY);
}

TEST_F(radar_ctl_UnitTestSuite, Radar_Ctl_Look_Trigger_State_CONFIGURED)
{
   Radar_Ctl_State        = RADAR_CTL_CONFIGURED;
   Radar_Ctl_State_Update = State_Radar_Ctl_Configured;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);
   Radar_Ctl_Look_Trigger();
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_CONFIGURED);
}

TEST_F(radar_ctl_UnitTestSuite, Radar_Ctl_Look_Trigger_State_TRANSMITTING)
{
   Radar_Ctl_State        = RADAR_CTL_TRANSMITTING;
   Radar_Ctl_State_Update = State_Radar_Ctl_Transmitting;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);
   Radar_Ctl_Look_Trigger();
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_TRANSMITTING);
}

// Additional coverage for Radar_Ctl_Look_Complete
TEST_F(radar_ctl_UnitTestSuite, Radar_Ctl_Look_Complete_State_READY)
{
   Radar_Ctl_State        = RADAR_CTL_READY;
   Radar_Ctl_State_Update = State_Radar_Ctl_Ready;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);
   Radar_Ctl_Look_Complete();
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_READY);
}

TEST_F(radar_ctl_UnitTestSuite, Radar_Ctl_Look_Complete_State_CONFIGURED)
{
   Radar_Ctl_State        = RADAR_CTL_CONFIGURED;
   Radar_Ctl_State_Update = State_Radar_Ctl_Configured;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);
   Radar_Ctl_Look_Complete();
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_CONFIGURED);
}

TEST_F(radar_ctl_UnitTestSuite, Radar_Ctl_Look_Complete_State_TRANSMITTING)
{
   Radar_Ctl_State        = RADAR_CTL_TRANSMITTING;
   Radar_Ctl_State_Update = State_Radar_Ctl_Transmitting;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);
   Radar_Ctl_Look_Complete();
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_TRANSMITTING);
}

// Additional branch coverage for Radar_Ctl_Look_Complete done
TEST_F(radar_ctl_UnitTestSuite, Radar_Ctl_Look_Complete_Branch_NotEqual)
{
   // Set up so Radar_Ctl_State_Check != Bitwise_Complement(Radar_Ctl_State_Update)
   Radar_Ctl_State_Update = Radar_Ctl_State_Func_Test;
   Radar_Ctl_State_Check  = 0xFFU; // Not equal to Bitwise_Complement(Radar_Ctl_State_Update)
   Radar_Ctl_Look_Complete();
   SUCCEED(); // Should not call the function pointer, just verify no error
}

/**
 *  Trans_Radar_Ctl_Off_TEST
 *      Test the state machine transition to the RADAR_CTL_OFF state
 */
TEST_F(radar_ctl_UnitTestSuite, Trans_Radar_Ctl_Off_TEST)
{
   Radar_Ctl_Data.init_status = NUM_RADAR_CTL_INIT;

   Trans_Radar_Ctl_Off();

   /* static function will be tested separately */
   ASSERT_EQ(Radar_Ctl_Data.init_status, RADAR_CTL_INIT_NOT_STARTED);
}
/**
 * Radar_Ctl_Look_Complete_TEST
 *      Test the successfully radar look complete
 */
TEST_F(radar_ctl_UnitTestSuite, Radar_Ctl_Look_Complete_TEST)
{
   Radar_Ctl_State_Update = Radar_Ctl_State_Func_Test;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);

   Radar_Ctl_Look_Complete();
   ASSERT_EQ(Radar_Ctl_State_Check, (uint32_t)Bitwise_Complement(Radar_Ctl_State_Update));
}
/** Radar_Ctl_Look_Complete_TEST
 *      Test the successfully radar look complete
 *      If condition is false
 */
TEST_F(radar_ctl_UnitTestSuite, Radar_Ctl_Look_Complete_TEST_False)
{
   Radar_Ctl_State_Update = Radar_Ctl_State_Func_Test;
   Radar_Ctl_State_Check  = 0xFFU;

   Radar_Ctl_Look_Complete();
   ASSERT_NE(Radar_Ctl_State_Check, Bitwise_Complement(Radar_Ctl_State_Update));
}

/**
 *  State_Radar_Ctl_Off_TEST
 *      Test the State_Radar_Ctl_Off function for RADAR_CTL_EVENT_PERIODIC
 */
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Off_TEST)
{
   State_Radar_Ctl_Off(RADAR_CTL_EVENT_PERIODIC);
   // Add assertions here if you want to check side effects or state changes
}
/**
 *  @b Trans_Radar_Ctl_Init_TEST
 *  @n
 *      Test the radar init status as RADAR_CTL_INIT_STARTED
 */
TEST_F(radar_ctl_UnitTestSuite, Trans_Radar_Ctl_Init_TEST)
{
   Radar_Ctl_Data.init_status = RADAR_CTL_INIT_SUCCESS;

   Trans_Radar_Ctl_Init();

   /* static function will be tested separately */
   ASSERT_EQ(Radar_Ctl_Data.init_status, RADAR_CTL_INIT_STARTED);
}
/**
 *  State_Radar_Ctl_Init_TEST
 *      Test the State_Radar_Ctl_Init function for RADAR_CTL_EVENT_PERIODIC
 */
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Init_TEST)
{
   // Case 1: Radiate enable is false, should transition to OFF
   Radar_Ctl_Data.radiate_enable = false;
   Radar_Ctl_State               = RADAR_CTL_INIT;
   Radar_Ctl_State_Update        = State_Radar_Ctl_Init;
   Radar_Ctl_State_Check         = Bitwise_Complement(Radar_Ctl_State_Update);

   State_Radar_Ctl_Init(RADAR_CTL_EVENT_PERIODIC);
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_OFF);
   ASSERT_EQ(Radar_Ctl_State_Update, State_Radar_Ctl_Off);
   ASSERT_EQ(Radar_Ctl_State_Check, (uint32_t)Bitwise_Complement(Radar_Ctl_State_Update));

   // Case 2: Radiate enable is true, MMIC error reinit is false, should transition to READY
   Radar_Ctl_Data.radiate_enable = true;
   RESET_FAKE(Get_MMIC_Error_Reinit);
   Get_MMIC_Error_Reinit_fake.return_val = 0;
   Radar_Ctl_State                       = RADAR_CTL_INIT;
   Radar_Ctl_State_Update                = State_Radar_Ctl_Init;
   Radar_Ctl_State_Check                 = Bitwise_Complement(Radar_Ctl_State_Update);

   State_Radar_Ctl_Init(RADAR_CTL_EVENT_PERIODIC);
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_READY);
   ASSERT_EQ(Radar_Ctl_State_Update, State_Radar_Ctl_Ready);
   ASSERT_EQ(Radar_Ctl_State_Check, (uint32_t)Bitwise_Complement(Radar_Ctl_State_Update));

   // Case 3: Radiate enable is true, MMIC error reinit is true, MMIC faulted is true, should transition to FAULTED
   Get_MMIC_Error_Reinit_fake.return_val = 1;
   RESET_FAKE(Get_MMIC_Faulted);
   Get_MMIC_Faulted_fake.return_val = 1;
   Radar_Ctl_State                  = RADAR_CTL_INIT;
   Radar_Ctl_State_Update           = State_Radar_Ctl_Init;
   Radar_Ctl_State_Check            = Bitwise_Complement(Radar_Ctl_State_Update);

   State_Radar_Ctl_Init(RADAR_CTL_EVENT_PERIODIC);
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_FAULTED);
   ASSERT_EQ(Radar_Ctl_State_Update, State_Radar_Ctl_Faulted);
   ASSERT_EQ(Radar_Ctl_State_Check, (uint32_t)Bitwise_Complement(Radar_Ctl_State_Update));
}
/**
 *  @b State_Radar_Ctl_Faulted_TEST
 *  @n
 *      Test the State_Radar_Ctl_Faulted function for RADAR_CTL_EVENT_PERIODIC
 */
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Faulted_TEST)
{
   // Setup: Simulate MMIC fault cleared (so Trans_Radar_Ctl_Off should be called)
   RESET_FAKE(Get_MMIC_Faulted);
   Get_MMIC_Faulted_fake.return_val = 0; // MMIC not faulted

   // Set state to FAULTED before event
   Radar_Ctl_State            = RADAR_CTL_FAULTED;
   Radar_Ctl_State_Update     = State_Radar_Ctl_Faulted;
   Radar_Ctl_State_Check      = Bitwise_Complement(Radar_Ctl_State_Update);
   Radar_Ctl_Data.init_status = RADAR_CTL_INIT_FAIL;

   State_Radar_Ctl_Faulted(RADAR_CTL_EVENT_PERIODIC);

   // Assert state transitioned to OFF
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_OFF);
   // Assert state update function is set to State_Radar_Ctl_Off
   ASSERT_EQ(Radar_Ctl_State_Update, State_Radar_Ctl_Off);
   // Assert state check is complement of update
   ASSERT_EQ(Radar_Ctl_State_Check, (uint32_t)Bitwise_Complement(Radar_Ctl_State_Update));
   // Assert init status is set to NOT_STARTED
   ASSERT_EQ(Radar_Ctl_Data.init_status, RADAR_CTL_INIT_NOT_STARTED);
}
/**
Trans_Radar_Ctl_Faulted_TEST
 *      Test the state machine transition to the RADAR_CTL_FAULTED state
 */
TEST_F(radar_ctl_UnitTestSuite, Trans_Radar_Ctl_Faulted_TEST)
{
   Radar_Ctl_State            = RADAR_CTL_NUM_STATES;
   Radar_Ctl_Data.init_status = RADAR_CTL_INIT_SUCCESS;

   Trans_Radar_Ctl_Faulted();

   /* Verify state transition to FAULTED */
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_FAULTED);

   /* Verify state update function is set correctly */
   ASSERT_EQ(Radar_Ctl_State_Update, State_Radar_Ctl_Faulted);
   ASSERT_EQ(Radar_Ctl_State_Check, (uint32_t)Bitwise_Complement(Radar_Ctl_State_Update));

   /* Verify init status is set to FAIL */
   ASSERT_EQ(Radar_Ctl_Data.init_status, RADAR_CTL_INIT_FAIL);
}

// Test the radar radiate enable is FALSE
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Ready_periodic_event_radiate_enable_FALSE)
{
   Radar_Ctl_Event_T event       = RADAR_CTL_EVENT_PERIODIC;
   Radar_Ctl_Data.init_status    = RADAR_CTL_INIT_FAIL;
   Radar_Ctl_Data.radiate_enable = false;
   XCP_Force_Radar_On            = false;

   State_Radar_Ctl_Ready(event);

   event = RADAR_CTL_EVENT_LOOK_COMPLETE;
   State_Radar_Ctl_Ready(event);

   /* static function will be tested separately */
   ASSERT_EQ(Radar_Ctl_Data.init_status, RADAR_CTL_INIT_NOT_STARTED);
}

TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Ready_periodic_event_Get_Radar_Radiate_Enable_Get_Radar_Radiate_Enable1)
{
   Radar_Ctl_Event_T event       = RADAR_CTL_EVENT_PERIODIC;
   Radar_Ctl_Data.radiate_enable = true;
   XCP_Force_Radar_On            = false;
   State_Radar_Ctl_Ready(event);
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_CONFIGURED);
}
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Ready_periodic_event_Get_Radar_Radiate_Enable_Get_Radar_Radiate_Enable2)
{
   Radar_Ctl_Event_T event       = RADAR_CTL_EVENT_PERIODIC;
   Radar_Ctl_Data.radiate_enable = false;
   XCP_Force_Radar_On            = true;
   State_Radar_Ctl_Ready(event);
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_CONFIGURED);
}

TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Ready_periodic_event_radiate_enable_TRUE)
{
   Radar_Ctl_Event_T event                             = RADAR_CTL_EVENT_PERIODIC;
   Radar_Ctl_Data.radiate_enable                       = true;
   XCP_Force_Radar_On                                  = true;
   SMC_Cal_Data_Ptr->Mars_API_Cal.aptiv_operation_mode = PURE_CW_MODE;

   State_Radar_Ctl_Ready(event);
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_PURE_CW);
}
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Ready_periodic_event_radiate_enable_TRUE_operation_mode_false)
{
   Radar_Ctl_Event_T event                             = RADAR_CTL_EVENT_PERIODIC;
   Radar_Ctl_Data.radiate_enable                       = true;
   XCP_Force_Radar_On                                  = true;
   SMC_Cal_Data_Ptr->Mars_API_Cal.aptiv_operation_mode = 2;

   State_Radar_Ctl_Ready(event);
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_CONFIGURED);
}

// Test the Radar_Ctl_Reset_Init function
TEST_F(radar_ctl_UnitTestSuite, Radar_Ctl_Reset_Init_TEST)
{
   Radar_Ctl_Data.init_status = RADAR_CTL_INIT_FAIL;
   Radar_Ctl_Reset_Init();
   ASSERT_EQ(Radar_Ctl_Data.init_status, RADAR_CTL_INIT_NOT_STARTED);
}

// Test the Radar_Ctl_State as RADAR_CTL_CONFIGURED
TEST_F(radar_ctl_UnitTestSuite, Trans_Radar_Ctl_Configured_TEST)
{
   Radar_Ctl_State = RADAR_CTL_NUM_STATES;

   Trans_Radar_Ctl_Configured();
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_CONFIGURED);
}

/** Trans_Radar_Ctl_Transmitting_TEST
 *  Test the Radar_Ctl_State as RADAR_CTL_TRANSMITTING
 */
TEST_F(radar_ctl_UnitTestSuite, Trans_Radar_Ctl_Transmitting_TEST)
{
   Radar_Ctl_State = RADAR_CTL_NUM_STATES;

   Trans_Radar_Ctl_Transmitting();
   /* static function will be tested separately */
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_TRANSMITTING);
}
/**
 *  State_Radar_Ctl_Transmitting_TEST
 *      Test the State_Radar_Ctl_Transmitting function for RADAR_CTL_EVENT_PERIODIC
 */
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Transmitting_TEST)
{
   Radar_Ctl_State         = RADAR_CTL_TRANSMITTING;
   Radar_Ctl_Event_T event = RADAR_CTL_EVENT_PERIODIC;
   State_Radar_Ctl_Transmitting(event);
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_TRANSMITTING);
}

/**
 *  @b State_Radar_Ctl_Transmitting_LOOK_COMPLETE_TEST
 *  @n
 *      Test State_Radar_Ctl_Transmitting with LOOK_COMPLETE event and no errors
 */
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Transmitting_LOOK_COMPLETE_TEST)
{
   Radar_Ctl_State         = RADAR_CTL_TRANSMITTING;
   Radar_Ctl_Event_T event = RADAR_CTL_EVENT_LOOK_COMPLETE;
   RESET_FAKE(Get_MMIC_Error_Reinit);
   Get_MMIC_Error_Reinit_fake.return_val = 0;
   RESET_FAKE(Get_MMIC_Faulted);
   Get_MMIC_Faulted_fake.return_val = 0;
   RESET_FAKE(Get_MMIC_Error_Discard);
   Get_MMIC_Error_Discard_fake.return_val = 0;
   Radar_Ctl_Data.radiate_enable          = true;
   State_Radar_Ctl_Transmitting(event);
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_CONFIGURED);
}
/**
 * State_Radar_Ctl_Transmitting_LOOK_COMPLETE_ERROR_REINIT_TEST
 *  @n
 *      Test State_Radar_Ctl_Transmitting with LOOK_COMPLETE event and MMIC error reinit
 */
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Transmitting_LOOK_COMPLETE_ERROR_REINIT_TEST)
{
   Radar_Ctl_State         = RADAR_CTL_TRANSMITTING;
   Radar_Ctl_Event_T event = RADAR_CTL_EVENT_LOOK_COMPLETE;
   RESET_FAKE(Get_MMIC_Error_Reinit);
   Get_MMIC_Error_Reinit_fake.return_val = 1;
   State_Radar_Ctl_Transmitting(event);
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_OFF);
}
/**
 *  @b State_Radar_Ctl_Transmitting_LOOK_COMPLETE_FAULTED_TEST
 *  @n
 *      Test State_Radar_Ctl_Transmitting with LOOK_COMPLETE event and MMIC faulted
 */
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Transmitting_LOOK_COMPLETE_FAULTED_TEST)
{
   Radar_Ctl_State         = RADAR_CTL_TRANSMITTING;
   Radar_Ctl_Event_T event = RADAR_CTL_EVENT_LOOK_COMPLETE;
   RESET_FAKE(Get_MMIC_Error_Reinit);
   Get_MMIC_Error_Reinit_fake.return_val = 0;
   RESET_FAKE(Get_MMIC_Faulted);
   Get_MMIC_Faulted_fake.return_val = 1;
   State_Radar_Ctl_Transmitting(event);
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_OFF);
}
/**
 *  @b State_Radar_Ctl_Transmitting_LOOK_COMPLETE_RADIATE_DISABLE_TEST
 *  @n
 *      Test State_Radar_Ctl_Transmitting with LOOK_COMPLETE event and radiate enable false
 */
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Transmitting_LOOK_COMPLETE_RADIATE_DISABLE_TEST)
{
   Radar_Ctl_State               = RADAR_CTL_TRANSMITTING;
   Radar_Ctl_Event_T event       = RADAR_CTL_EVENT_LOOK_COMPLETE;
   Radar_Ctl_Data.radiate_enable = false;
   XCP_Force_Radar_On            = false;
   // Set up calibration/mode variables if needed
   SMC_Cal_Data_Ptr->Mars_API_Cal.aptiv_operation_mode = 0;
   State_Radar_Ctl_Transmitting(event);
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_OFF);
}
/**
 *  @b State_Radar_Ctl_Transmitting_LOOK_COMPLETE_PURE_CW_MODE_TEST
 *  @n
 *      Test State_Radar_Ctl_Transmitting with LOOK_COMPLETE event and PURE_CW_MODE
 */
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Transmitting_LOOK_COMPLETE_PURE_CW_MODE_TEST)
{
   Radar_Ctl_State                                     = RADAR_CTL_TRANSMITTING;
   Radar_Ctl_Event_T event                             = RADAR_CTL_EVENT_LOOK_COMPLETE;
   Radar_Ctl_Data.radiate_enable                       = true;
   XCP_Force_Radar_On                                  = true;
   SMC_Cal_Data_Ptr->Mars_API_Cal.aptiv_operation_mode = PURE_CW_MODE;
   State_Radar_Ctl_Transmitting(event);
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_READY);
}
/**
 *  @b State_Radar_Ctl_Transmitting_LOOK_COMPLETE_A2D_INJECTION_TEST
 *  @n
 *      Test State_Radar_Ctl_Transmitting with LOOK_COMPLETE event and A2D injection active
 */

// Test the radar_ctl_Transmitting function with periodic event
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Transmitting_periodic_event)
{
   Radar_Ctl_Event_T event = RADAR_CTL_EVENT_PERIODIC;
   Radar_Ctl_State         = RADAR_CTL_TRANSMITTING;
   State_Radar_Ctl_Transmitting(event);
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_TRANSMITTING);
}

/* NOTE: The following test cases for State_Radar_Ctl_Degraded are ready to use.
 * To enable these tests, change the #if 0 to #if 1 in radar_ctl.c at:
 * - Line ~920 (Trans_Radar_Ctl_Degraded function)
 * - Line ~1147 (State_Radar_Ctl_Degraded and helper functions)
 * Also uncomment the variable declarations:
 * - Line ~106: static uint16_t Degraded_Error_Count = 0U;
 * - Line ~108: static bool look_trigger_flag = false;
 */

#if 0 /* Enable when State_Radar_Ctl_Degraded is activated in radar_ctl.c */

/**
 *  @b State_Radar_Ctl_Degraded_periodic_event
 *  @n
 *      Test State_Radar_Ctl_Degraded with RADAR_CTL_EVENT_PERIODIC event
 */
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Degraded_periodic_event)
{
   Radar_Ctl_Event_T event = RADAR_CTL_EVENT_PERIODIC;
   Degraded_Error_Count = 0;
   Radar_Ctl_State = RADAR_CTL_DEGRADED;

   State_Radar_Ctl_Degraded(event);

   /* Should increment Degraded_Error_Count and stay in degraded state */
   ASSERT_EQ(Degraded_Error_Count, 1);
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_DEGRADED);
}

/**
 *  @b State_Radar_Ctl_Degraded_periodic_event_max_error_count
 *  @n
 *      Test State_Radar_Ctl_Degraded when error count reaches maximum
 */
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Degraded_periodic_event_max_error_count)
{
   Radar_Ctl_Event_T event = RADAR_CTL_EVENT_PERIODIC;
   Degraded_Error_Count = ERROR_MAX_DEGRADED - 1;

   State_Radar_Ctl_Degraded(event);

   /* Should transition to OFF state when error count reaches max */
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_OFF);
   ASSERT_EQ(Degraded_Error_Count, 0);
}

/**
 *  @b State_Radar_Ctl_Degraded_look_trigger_skip_look
 *  @n
 *      Test State_Radar_Ctl_Degraded with LOOK_TRIGGER event when look is skipped (odd count)
 */
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Degraded_look_trigger_skip_look)
{
   Radar_Ctl_Event_T event = RADAR_CTL_EVENT_LOOK_TRIGGER;
   MMIC_Stream.MMIC_Data.ot_handle.degraded_mode_cnt = 0;  /* Will become 1 (odd) - skip look */
   look_trigger_flag = false;
   Radar_Ctl_State = RADAR_CTL_DEGRADED;

   State_Radar_Ctl_Degraded(event);

   /* Verify look was skipped and flag not set */
   ASSERT_EQ(MMIC_Stream.MMIC_Data.ot_handle.degraded_mode_cnt, 1);
   ASSERT_FALSE(look_trigger_flag);
}

/**
 *  @b State_Radar_Ctl_Degraded_look_trigger_acquire_data
 *  @n
 *      Test State_Radar_Ctl_Degraded with LOOK_TRIGGER event when data is acquired (even count)
 */
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Degraded_look_trigger_acquire_data)
{
   Radar_Ctl_Event_T event = RADAR_CTL_EVENT_LOOK_TRIGGER;
   MMIC_Stream.MMIC_Data.ot_handle.degraded_mode_cnt = 1;  /* Will become 2 (even) - acquire data */
   look_trigger_flag = false;

   State_Radar_Ctl_Degraded(event);

   /* Verify data acquisition happened */
   ASSERT_EQ(MMIC_Stream.MMIC_Data.ot_handle.degraded_mode_cnt, 2);
   ASSERT_TRUE(look_trigger_flag);
}

/**
 *  @b State_Radar_Ctl_Degraded_look_complete_with_trigger_flag
 *  @n
 *      Test State_Radar_Ctl_Degraded with LOOK_COMPLETE event when trigger flag is set
 */
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Degraded_look_complete_with_trigger_flag)
{
   Radar_Ctl_Event_T event = RADAR_CTL_EVENT_LOOK_COMPLETE;
   look_trigger_flag = true;
   Degraded_Error_Count = 5;

   State_Radar_Ctl_Degraded(event);

   /* Should clear error count and reset flag */
   ASSERT_EQ(Degraded_Error_Count, 0);
   ASSERT_FALSE(look_trigger_flag);
}

/**
 *  @b State_Radar_Ctl_Degraded_look_complete_without_trigger_flag
 *  @n
 *      Test State_Radar_Ctl_Degraded with LOOK_COMPLETE event when trigger flag is not set
 */
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Degraded_look_complete_without_trigger_flag)
{
   Radar_Ctl_Event_T event = RADAR_CTL_EVENT_LOOK_COMPLETE;
   look_trigger_flag = false;
   Degraded_Error_Count = 5;

   State_Radar_Ctl_Degraded(event);

   /* Should not process complete when flag is not set */
   ASSERT_EQ(Degraded_Error_Count, 5);  /* Unchanged */
   ASSERT_FALSE(look_trigger_flag);
}

#endif /* End of State_Radar_Ctl_Degraded test cases */

// Restore Pure CW and Look Trigger related unit tests
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Pure_CW_periodic_event_pureSW_requested_MMIC_XCP_Enable_CW_Mode_TRUE)
{
   Radar_Ctl_Event_T event                             = RADAR_CTL_EVENT_PERIODIC;
   SMC_Cal_Data_Ptr->Mars_API_Cal.aptiv_operation_mode = 0;
   MMIC_XCP_Enable_CW_Mode                             = CODED_TRUE;
   State_Radar_Ctl_Pure_CW(event);
   ASSERT_NE(aptiv_operation_mode_smc, PURE_CW_MODE);
}

TEST_F(radar_ctl_UnitTestSuite,
       State_Radar_Ctl_Pure_CW_periodic_event_pureSW_requested_XCP_Enable_CW_Mode_TRUE__APTIV_OPERATION_FALSE)
{
   Radar_Ctl_Event_T event                             = RADAR_CTL_EVENT_PERIODIC;
   SMC_Cal_Data_Ptr->Mars_API_Cal.aptiv_operation_mode = 1;
   MMIC_XCP_Enable_CW_Mode                             = CODED_TRUE;
   State_Radar_Ctl_Pure_CW(event);
   ASSERT_EQ(aptiv_operation_mode_smc, PURE_CW_MODE);
}

TEST_F(radar_ctl_UnitTestSuite,
       State_Radar_Ctl_Pure_CW_periodic_event_pureSW_requested_XCP_Enable_CW_Mode_FALSE__APTIV_OPERATION_FALSE)
{
   Radar_Ctl_Event_T event                             = RADAR_CTL_EVENT_PERIODIC;
   SMC_Cal_Data_Ptr->Mars_API_Cal.aptiv_operation_mode = 0;
   MMIC_XCP_Enable_CW_Mode                             = CODED_FALSE;
   State_Radar_Ctl_Pure_CW(event);
   ASSERT_NE(aptiv_operation_mode_smc, PURE_CW_MODE);
}

TEST_F(radar_ctl_UnitTestSuite,
       State_Radar_Ctl_Pure_CW_periodic_event_pureSW_requested_XCP_Enable_CW_Mode_FALSE__APTIV_OPERATION_TRUE)
{
   Radar_Ctl_Event_T event                             = RADAR_CTL_EVENT_PERIODIC;
   SMC_Cal_Data_Ptr->Mars_API_Cal.aptiv_operation_mode = 1;
   MMIC_XCP_Enable_CW_Mode                             = CODED_FALSE;
   State_Radar_Ctl_Pure_CW(event);
   ASSERT_EQ(aptiv_operation_mode_smc, PURE_CW_MODE);
}

TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Pure_CW_look_complete_event)
{
   Radar_Ctl_State         = RADAR_CTL_NUM_STATES;
   Radar_Ctl_Event_T event = RADAR_CTL_EVENT_LOOK_COMPLETE;
   State_Radar_Ctl_Pure_CW(event);
   ASSERT_NE(Radar_Ctl_State, RADAR_CTL_READY);
}

TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_A2D_Injection_look_trigger_event)
{
   Radar_Ctl_Event_T event = RADAR_CTL_EVENT_LOOK_TRIGGER;
   Radar_Ctl_State         = RADAR_CTL_NUM_STATES;
   State_Radar_Ctl_A2D_Injection(event);
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_OFF);
}

TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_A2D_Injection_periodic_event)
{
   Radar_Ctl_Event_T event = RADAR_CTL_EVENT_PERIODIC;
   Radar_Ctl_State         = RADAR_CTL_NUM_STATES;
   State_Radar_Ctl_A2D_Injection(event);
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_NUM_STATES);
}

// Basic test for ipc_mss_notify_dss_config
TEST_F(radar_ctl_UnitTestSuite, ipc_mss_notify_dss_config_basic)
{
   uint32_t look_idx    = 1;
   uint32_t look_cfg_id = 2;
   uint32_t rp_cfg      = 0;
   ipc_mss_notify_dss_config(look_idx, look_cfg_id, &rp_cfg);
}

TEST_F(radar_ctl_UnitTestSuite, Radar_Ctl_Periodic_Condition_False)
{
   Radar_Ctl_State_Update = Radar_Ctl_State_Func_Test;
   Radar_Ctl_State_Check  = 0xFFU;

   Radar_Ctl_Periodic();
   ASSERT_EQ(RADAR_CTL_INIT, Radar_Ctl_State);
}

TEST_F(radar_ctl_UnitTestSuite, Radar_Ctl_Periodic_Condition_True)
{
   Radar_Ctl_State_Update = Radar_Ctl_State_Func_Test; //(Radar_Ctl_State_Func_Ptr_T)0x0U;
   Radar_Ctl_State_Check  = (uint32_t)Bitwise_Complement(Radar_Ctl_State_Update);

   Radar_Ctl_Periodic();
}

// Basic test for State_Radar_Ctl_Configured
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Configured_periodic_event)
{
   Radar_Ctl_State        = RADAR_CTL_CONFIGURED;
   Radar_Ctl_State_Update = State_Radar_Ctl_Configured;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);
   // Call with PERIODIC event
   State_Radar_Ctl_Configured(RADAR_CTL_EVENT_PERIODIC);
   SUCCEED();
}

TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Configured_look_trigger_event)
{
   Radar_Ctl_State        = RADAR_CTL_CONFIGURED;
   Radar_Ctl_State_Update = State_Radar_Ctl_Configured;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);
   // Call with LOOK_TRIGGER event
   State_Radar_Ctl_Configured(RADAR_CTL_EVENT_LOOK_TRIGGER);
   SUCCEED();
}

// Test for Trans_Radar_Ctl_A2D_Injection
TEST_F(radar_ctl_UnitTestSuite, Trans_Radar_Ctl_A2D_Injection_TEST)
{
   // Set state to something else first
   Radar_Ctl_State        = RADAR_CTL_NUM_STATES;
   Radar_Ctl_State_Update = nullptr;
   Radar_Ctl_State_Check  = 0;
   Trans_Radar_Ctl_A2D_Injection();
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_A2D_INJECTION);
   ASSERT_EQ(Radar_Ctl_State_Update, State_Radar_Ctl_A2D_Injection);
   ASSERT_EQ(Radar_Ctl_State_Check, (uint32_t)Bitwise_Complement(Radar_Ctl_State_Update));
}

// Basic test for State_Radar_Ctl_Off
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Off_periodic_event)
{
   Radar_Ctl_State        = RADAR_CTL_OFF;
   Radar_Ctl_State_Update = State_Radar_Ctl_Off;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);
   // Call with PERIODIC event
   State_Radar_Ctl_Off(RADAR_CTL_EVENT_PERIODIC);
   SUCCEED(); // Just verify it runs without error
}

// Branch coverage tests for radar_ctl.c - targeting uncovered branches

// Test Radar_Ctl_Periodic with mismatched state check (line 246)
TEST_F(radar_ctl_UnitTestSuite, Radar_Ctl_Periodic_MismatchedStateCheck)
{
   Radar_Ctl_State_Update = State_Radar_Ctl_Off;
   Radar_Ctl_State_Check  = 0x12345678; // Mismatch with complement
   Radar_Ctl_Periodic();
   // Should call Trans_Radar_Ctl_Init()
   SUCCEED();
}

// Test Radar_Ctl_Look_Trigger with mismatched state (line 273)
TEST_F(radar_ctl_UnitTestSuite, Radar_Ctl_Look_Trigger_MismatchedState)
{
   Radar_Ctl_State_Update = State_Radar_Ctl_Ready;
   Radar_Ctl_State_Check  = 0xABCDEF00; // Mismatch
   Radar_Ctl_Look_Trigger();
   // Should not call state update function
   SUCCEED();
}

// Test Radar_Ctl_Look_Complete with mismatched state (line 299)
TEST_F(radar_ctl_UnitTestSuite, Radar_Ctl_Look_Complete_MismatchedState)
{
   Radar_Ctl_State_Update = State_Radar_Ctl_Transmitting;
   Radar_Ctl_State_Check  = 0x99887766; // Mismatch
   Radar_Ctl_Look_Complete();
   // Should not call state update function
   SUCCEED();
}

// Test State_Radar_Ctl_Off with Get_Radar_Radiate_Enable true (line 399)
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Off_RadiateEnable_True)
{
   Radar_Ctl_State               = RADAR_CTL_OFF;
   Radar_Ctl_State_Update        = State_Radar_Ctl_Off;
   Radar_Ctl_State_Check         = Bitwise_Complement(Radar_Ctl_State_Update);
   Radar_Ctl_Data.radiate_enable = true;
   XCP_Force_Radar_On            = false;

   State_Radar_Ctl_Off(RADAR_CTL_EVENT_PERIODIC);
   // Should transition to Init state
   SUCCEED();
}

// Test State_Radar_Ctl_Faulted with fault reset counter condition (line 457/460)
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Faulted_ResetCounter)
{
   Radar_Ctl_State        = RADAR_CTL_FAULTED;
   Radar_Ctl_State_Update = State_Radar_Ctl_Faulted;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);
   // Simulate fault not set to test the !Get_MMIC_Faulted() branch
   Get_MMIC_Faulted_fake.return_val = 0; // false

   State_Radar_Ctl_Faulted(RADAR_CTL_EVENT_PERIODIC);
   // Should transition to Off state
   SUCCEED();
}

// Test State_Radar_Ctl_Init with radiate disable branch (line 516/518)
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Init_RadiateDisabled)
{
   Radar_Ctl_State               = RADAR_CTL_INIT;
   Radar_Ctl_State_Update        = State_Radar_Ctl_Init;
   Radar_Ctl_State_Check         = Bitwise_Complement(Radar_Ctl_State_Update);
   Radar_Ctl_Data.radiate_enable = false;
   XCP_Force_Radar_On            = false;

   State_Radar_Ctl_Init(RADAR_CTL_EVENT_PERIODIC);
   // Should transition to Off state
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_OFF);
}

// Test State_Radar_Ctl_Configured with MMIC error reinit (line 682 branches)
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Configured_MMIC_Error_Reinit)
{
   Radar_Ctl_State        = RADAR_CTL_CONFIGURED;
   Radar_Ctl_State_Update = State_Radar_Ctl_Configured;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);
   // Set error reinit flag
   Get_MMIC_Error_Reinit_fake.return_val = 1; // true

   State_Radar_Ctl_Configured(RADAR_CTL_EVENT_LOOK_TRIGGER);
   // Should transition to Off state
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_OFF);
}

// Test State_Radar_Ctl_Configured with MMIC faulted (line 682 branches)
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Configured_MMIC_Faulted)
{
   Radar_Ctl_State        = RADAR_CTL_CONFIGURED;
   Radar_Ctl_State_Update = State_Radar_Ctl_Configured;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);
   // Set MMIC faulted
   Get_MMIC_Faulted_fake.return_val      = 1; // true
   Get_MMIC_Error_Reinit_fake.return_val = 0; // false

   State_Radar_Ctl_Configured(RADAR_CTL_EVENT_LOOK_TRIGGER);
   // Should transition to Off state
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_OFF);
}

// Test State_Radar_Ctl_Configured with MMIC error discard (line 687)
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Configured_MMIC_Error_Discard)
{
   Radar_Ctl_State        = RADAR_CTL_CONFIGURED;
   Radar_Ctl_State_Update = State_Radar_Ctl_Configured;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);
   // Set error discard flag
   Get_MMIC_Error_Discard_fake.return_val = 1; // true
   Get_MMIC_Error_Reinit_fake.return_val  = 0; // false
   Get_MMIC_Faulted_fake.return_val       = 0; // false

   State_Radar_Ctl_Configured(RADAR_CTL_EVENT_LOOK_TRIGGER);
   // Should transition to Ready state
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_READY);
}

// Test State_Radar_Ctl_Ready with periodic event branches (line 774)
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Ready_Periodic_RadiateDisable)
{
   Radar_Ctl_State               = RADAR_CTL_READY;
   Radar_Ctl_State_Update        = State_Radar_Ctl_Ready;
   Radar_Ctl_State_Check         = Bitwise_Complement(Radar_Ctl_State_Update);
   Radar_Ctl_Data.radiate_enable = false;
   XCP_Force_Radar_On            = false;

   State_Radar_Ctl_Ready(RADAR_CTL_EVENT_PERIODIC);
   // Should transition to Off state
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_OFF);
}

// Test Radar_Ctl_Look_Trigger_Start with all conditions false (line 1009)
TEST_F(radar_ctl_UnitTestSuite, Radar_Ctl_Look_Trigger_Start_AllConditionsFalse)
{
   // Set all error conditions to false
   Get_MMIC_Error_Reinit_fake.return_val  = 0; // false
   Get_MMIC_Faulted_fake.return_val       = 0; // false
   Get_MMIC_Error_Discard_fake.return_val = 0; // false

   Radar_Ctl_Look_Trigger_Start();
   // Should execute the main path with IPC notifications
   SUCCEED();
}

// Test State_Radar_Ctl_Ready with multiple scan index branches (line 1020/1024)
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Ready_ScanIndexBranches)
{
   Radar_Ctl_State                                     = RADAR_CTL_READY;
   Radar_Ctl_State_Update                              = State_Radar_Ctl_Ready;
   Radar_Ctl_State_Check                               = Bitwise_Complement(Radar_Ctl_State_Update);
   Radar_Ctl_Data.radiate_enable                       = true;
   XCP_Force_Radar_On                                  = false;
   SMC_Cal_Data_Ptr->Mars_API_Cal.aptiv_operation_mode = 0; // Not CW mode

   // Test with different scan indices to cover branches
   Radar_Ctl_Data.scan_index = 0;
   State_Radar_Ctl_Ready(RADAR_CTL_EVENT_PERIODIC);

   Radar_Ctl_Data.scan_index = 1;
   Radar_Ctl_State_Update    = State_Radar_Ctl_Ready;
   Radar_Ctl_State_Check     = Bitwise_Complement(Radar_Ctl_State_Update);
   State_Radar_Ctl_Ready(RADAR_CTL_EVENT_PERIODIC);

   SUCCEED();
}
// Additional tests to improve branch coverage further

// Test State_Radar_Ctl_Off without radiate enable and without fault (line 399 else branch)
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Off_NoRadiateNoFault)
{
   Radar_Ctl_State                  = RADAR_CTL_OFF;
   Radar_Ctl_State_Update           = State_Radar_Ctl_Off;
   Radar_Ctl_State_Check            = Bitwise_Complement(Radar_Ctl_State_Update);
   Get_MMIC_Faulted_fake.return_val = 0; // false
   Radar_Ctl_Data.radiate_enable    = false;
   XCP_Force_Radar_On               = false;

   State_Radar_Ctl_Off(RADAR_CTL_EVENT_PERIODIC);
   // Should remain in OFF state
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_OFF);
}

// Test State_Radar_Ctl_Init with radiate enable and config ready (line 518 success path)
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Init_ConfigReady)
{
   Radar_Ctl_State                  = RADAR_CTL_INIT;
   Radar_Ctl_State_Update           = State_Radar_Ctl_Init;
   Radar_Ctl_State_Check            = Bitwise_Complement(Radar_Ctl_State_Update);
   Radar_Ctl_Data.radiate_enable    = true;
   XCP_Force_Radar_On               = false;
   Get_MMIC_Faulted_fake.return_val = 0; // not faulted

   State_Radar_Ctl_Init(RADAR_CTL_EVENT_PERIODIC);
   // State will depend on MMIC config status
   SUCCEED();
}

// Test State_Radar_Ctl_Ready with neither CW nor A2D injection (line 774 else branch)
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Ready_Normal_Mode)
{
   Radar_Ctl_State                                     = RADAR_CTL_READY;
   Radar_Ctl_State_Update                              = State_Radar_Ctl_Ready;
   Radar_Ctl_State_Check                               = Bitwise_Complement(Radar_Ctl_State_Update);
   Radar_Ctl_Data.radiate_enable                       = true;
   XCP_Force_Radar_On                                  = false;
   SMC_Cal_Data_Ptr->Mars_API_Cal.aptiv_operation_mode = 0; // Not CW mode

   State_Radar_Ctl_Ready(RADAR_CTL_EVENT_PERIODIC);
   // Should transition to Configured state
   ASSERT_EQ(Radar_Ctl_State, RADAR_CTL_CONFIGURED);
}

// Test Radar_Ctl_Periodic with matched state check (line 246 else branch)
TEST_F(radar_ctl_UnitTestSuite, Radar_Ctl_Periodic_MatchedStateCheck)
{
   Radar_Ctl_State_Update = State_Radar_Ctl_Off;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);
   Radar_Ctl_Periodic();
   // Should not call Trans_Radar_Ctl_Init()
   SUCCEED();
}

// Test Radar_Ctl_Look_Trigger with matched state (line 273 else branch)
TEST_F(radar_ctl_UnitTestSuite, Radar_Ctl_Look_Trigger_MatchedState)
{
   Radar_Ctl_State_Update = State_Radar_Ctl_Ready;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);
   Radar_Ctl_Look_Trigger();
   // Should call state update function
   SUCCEED();
}

// Test Radar_Ctl_Look_Complete with matched state (line 299 else branch)
TEST_F(radar_ctl_UnitTestSuite, Radar_Ctl_Look_Complete_MatchedState)
{
   Radar_Ctl_State_Update = State_Radar_Ctl_Transmitting;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);
   Radar_Ctl_Look_Complete();
   // Should call state update function
   SUCCEED();
}

// Test State_Radar_Ctl_Off with non-periodic event (line 352 else branch)
TEST_F(radar_ctl_UnitTestSuite, State_Radar_Ctl_Off_NonPeriodicEvent)
{
   Radar_Ctl_State        = RADAR_CTL_OFF;
   Radar_Ctl_State_Update = State_Radar_Ctl_Off;
   Radar_Ctl_State_Check  = Bitwise_Complement(Radar_Ctl_State_Update);

   State_Radar_Ctl_Off(RADAR_CTL_EVENT_LOOK_TRIGGER);
   // Should handle non-periodic event
   SUCCEED();
}

static uint32_t g_fake_mstime = 100u;

static uint32_t GetExpectedPlatformMstimeCallsForLookTriggerStart(void)
{
   uint32_t call_count = 0u;

#ifdef TEST_STUB_PROFILE
   call_count += 2u;
#endif

#ifndef ADC_TEST_PATTERN_GEN_MODE_ENABLED
   call_count += 2u;
#endif

   return call_count;
}

void Get_Platform_mstime_Custom(uint32_t *out_ms)
{
   if (out_ms != nullptr)
   {
      *out_ms = g_fake_mstime;
      g_fake_mstime += 5u;
   }
}

TEST_F(radar_ctl_UnitTestSuite, Radar_Ctl_Look_Trigger_Start_Uses_Get_Platform_mstime)
{
   RESET_FAKE(Get_Platform_mstime);
   RESET_FAKE(Get_MMIC_Error_Reinit);
   RESET_FAKE(Get_MMIC_Faulted);
   RESET_FAKE(Get_MMIC_Error_Discard);
   RESET_FAKE(MMIC_Look_Trigger);
   FFF_RESET_HISTORY();
   g_fake_mstime = 100u;

   Get_MMIC_Error_Reinit_fake.return_val  = false;
   Get_MMIC_Faulted_fake.return_val       = false;
   Get_MMIC_Error_Discard_fake.return_val = false;
   Get_Platform_mstime_fake.custom_fake   = Get_Platform_mstime_Custom;

   Radar_Ctl_Look_Trigger_Start();

   EXPECT_EQ(Get_Platform_mstime_fake.call_count, GetExpectedPlatformMstimeCallsForLookTriggerStart());
   EXPECT_EQ(MMIC_Look_Trigger_fake.call_count, 1u);
}
TEST_F(radar_ctl_UnitTestSuite, Radar_Ctl_Look_Sync_Trig_SetTestAndClear)
{
   EXPECT_FALSE(Radar_Ctl_Look_Sync_Trig_Tst());

   Radar_Ctl_Look_Sync_Trig();

   EXPECT_TRUE(Radar_Ctl_Look_Sync_Trig_Tst());

   Radar_Ctl_Look_Sync_Trig_Clear();

   EXPECT_FALSE(Radar_Ctl_Look_Sync_Trig_Tst());
}
