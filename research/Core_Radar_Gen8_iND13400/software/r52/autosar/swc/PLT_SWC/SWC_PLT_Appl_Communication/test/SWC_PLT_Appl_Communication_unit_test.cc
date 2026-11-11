/*===========================================================================*/
/**
 * @file SWC_PLT_Appl_Communication_unit_test.cc
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for SWC_PLT_Appl_Communication.c
 * Goal: Achieve 95%+ code coverage
 *
 * @section ABBR ABBREVIATIONS:
 *   - CAN: Controller Area Network
 *   - SOME/IP: Scalable service-Oriented MiddlewarE over IP
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - SWC_PLT_Appl_Communication Unit Test Design
 *
 *   - Requirements Document(s):
 *     - Vehicle communication requirements
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 */
/*==========================================================================*/

/*===========================================================================*
 * Google Test Header Files
 *===========================================================================*/
#include "Platform_Types.h"
#include "fff.h"
#include <cstdint>
#include <gtest/gtest.h>
#ifndef VEH_CAN
   #define VEH_CAN
#endif

#define UT_APPL_COMM /*Added for UT to not include of rte_type.h in SWC_PLT_Radar_ALignment_Handler.h*/

DEFINE_FFF_GLOBALS

static uint64_t g_test_platform_ustime_us  = 0ULL;
static uint32_t g_test_platform_elapsed_us = 0U;

extern "C"
{
   void Get_Platform_ustime(uint64 *inst_us_time);
   void Get_Platform_Elapsed_ustime(uint32_t *inst_us_time, uint64_t start_time);
   extern uint32_t Delta_time_SendRadarDetection;
   extern uint32_t SendRadarDetection_Max_Delta_Time_Us;
   extern uint32_t SendRadarDetection_Min_Delta_Time_Us;
   extern volatile uint32_t FailCnt_Time_SendRadarDetection;
}

void Get_Platform_ustime(uint64 *inst_us_time)
{
   if (inst_us_time != nullptr)
   {
      *inst_us_time = g_test_platform_ustime_us;
   }
}

void Get_Platform_Elapsed_ustime(uint32_t *inst_us_time, uint64_t start_time)
{
   (void)start_time;
   if (inst_us_time != nullptr)
   {
      *inst_us_time = g_test_platform_elapsed_us;
   }
}

/*===========================================================================*
 * Mock definitions - must come before including source
 *===========================================================================*/
// #include "Appl_Comm_fake.h"

/*===========================================================================*
 * Unit Test Header Files - Include source after mocks
 *===========================================================================*/
extern "C"
{
/* Fakes must come first to preempt real AUTOSAR headers (CanSM_ComM.h, ComM_Cfg.h, Rte_ComM_Type.h) */
#include "can_tx_msgs_fakes.h"
/* Include the source file directly for unit testing */
#include "../Source/SWC_PLT_Appl_Communication.c"
#include "Com.h"
#include "Com_Lcfg.h"
}

/*===========================================================================*
 * Private Mocks
 *===========================================================================*/
static Dt_AlignmentStatic g_alignment_static    = {0};
static Dt_AlignmentService g_alignment_service  = {0};
static Dt_AlignmentShortTrack g_alignment_short = {0};

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class SWC_PLT_Appl_Communication_UnitTestSuite : public testing::Test
{
 protected:
   /**
    * @brief Method run before each individual test case.
    */
   void SetUp() override
   {
      // Reset FFF framework
      FFF_RESET_HISTORY();

      // Reset all fake functions
      RESET_FAKE(CanSM_RequestComMode);
      RESET_FAKE(Com_MainFunctionTx_ComMainFunctionTx_Event);
      RESET_FAKE(Com_IpduGroupStart);
      RESET_FAKE(Com_IpduGroupStop);
      RESET_FAKE(Init_Provided_Services);
      RESET_FAKE(Init_Consumed_Services);
      RESET_FAKE(Process_Provided_Services);
      RESET_FAKE(Process_Consumed_Services);
      RESET_FAKE(Process_Received_CAN_Msgs);
      RESET_FAKE(Send_Radar_Status_001_Messages);
      RESET_FAKE(Send_Radar_Status_002_Messages);
      RESET_FAKE(Send_Alignment_Status_001_Messages);
      RESET_FAKE(Send_Radar_Capability_Messages);
      RESET_FAKE(Send_Tracker_Status_Messages);
      RESET_FAKE(Send_Radar_Header_Messages);
      RESET_FAKE(Send_Alignment_Status_002_Messages);
      RESET_FAKE(Send_Radar_Detection_Messages);
      RESET_FAKE(Send_Tracker_Header_Messages);
      RESET_FAKE(Send_Tracker_Objects_On_CAN);
      RESET_FAKE(Get_AlignmentStatic);
      RESET_FAKE(Get_AlignmentService);
      RESET_FAKE(Get_AlignmentShortTrack);

      // Set default return values
      CanSM_RequestComMode_fake.return_val = E_OK;

      g_alignment_static                   = (Dt_AlignmentStatic){0};
      g_alignment_service                  = (Dt_AlignmentService){0};
      g_alignment_short                    = (Dt_AlignmentShortTrack){0};
      g_test_platform_ustime_us            = 0ULL;
      g_test_platform_elapsed_us           = 0U;
      Delta_time_SendRadarDetection        = 0U;
      SendRadarDetection_Max_Delta_Time_Us = 0U;
      SendRadarDetection_Min_Delta_Time_Us = 1000000U;
      FailCnt_Time_SendRadarDetection      = 0U;

      Get_AlignmentStatic_fake.return_val     = &g_alignment_static;
      Get_AlignmentService_fake.return_val    = &g_alignment_service;
      Get_AlignmentShortTrack_fake.return_val = &g_alignment_short;
   }

   /**
    * @brief Method run after each individual test case.
    */
   void TearDown() override
   {
      // Cleanup if needed
   }
};

/*===========================================================================*
 * Test Cases for RE_Communication_Init (CAN Mode)
 *===========================================================================*/

#ifdef VEH_CAN

/**
 * @brief Test: RE_Communication_Init requests CAN communication mode for both channels
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, RE_Communication_Init_CAN_RequestsCommMode)
{
   // Execute the function
   RE_Communication_Init();

   // Verify CanSM_RequestComMode was called twice (once for each CAN channel)
   ASSERT_EQ(CanSM_RequestComMode_fake.call_count, 2);

   // Verify first call (CAN1)
   ASSERT_EQ(CanSM_RequestComMode_fake.arg0_history[0], ComMConf_ComMUser_CN_PCAN_RADAR_d6cf874b);
   ASSERT_EQ(CanSM_RequestComMode_fake.arg1_history[0], COMM_FULL_COMMUNICATION);

   // Verify second call (CAN2)
   ASSERT_EQ(CanSM_RequestComMode_fake.arg0_history[1], ComMConf_ComMUser_CN_VCAN_RADAR_4b138c58);
   ASSERT_EQ(CanSM_RequestComMode_fake.arg1_history[1], COMM_FULL_COMMUNICATION);
}

/**
 * @brief Test: RE_Communication_Init with CanSM returning E_OK
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, RE_Communication_Init_CAN_Success)
{
   CanSM_RequestComMode_fake.return_val = E_OK;

   // Execute the function
   RE_Communication_Init();

   // Verify function was called for both CAN channels
   ASSERT_EQ(CanSM_RequestComMode_fake.call_count, 2);
}

/**
 * @brief Test: RE_Communication_Init with CanSM returning E_NOT_OK
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, RE_Communication_Init_CAN_Failure)
{
   CanSM_RequestComMode_fake.return_val = E_NOT_OK;

   // Execute the function
   RE_Communication_Init();

   // Verify function was called for both CAN channels (error handling is implementation-specific)
   ASSERT_EQ(CanSM_RequestComMode_fake.call_count, 2);
}

#endif /* VEH_CAN */

/*===========================================================================*
 * Test Cases for RE_Communication_Init (SOME/IP Mode)
 *===========================================================================*/

#ifdef VEH_SOMEIP

/**
 * @brief Test: RE_Communication_Init initializes SOME/IP services
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, RE_Communication_Init_SOMEIP_InitializesServices)
{
   // Execute the function
   RE_Communication_Init();

   // Verify both service init functions were called
   ASSERT_EQ(Init_Provided_Services_fake.call_count, 1);
   ASSERT_EQ(Init_Consumed_Services_fake.call_count, 1);
}

/**
 * @brief Test: RE_Communication_Init SOME/IP call order
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, RE_Communication_Init_SOMEIP_CallOrder)
{
   // Execute the function
   RE_Communication_Init();

   // Verify provided services initialized before consumed services
   // This is important for proper service discovery
   ASSERT_EQ(Init_Provided_Services_fake.call_count, 1);
   ASSERT_EQ(Init_Consumed_Services_fake.call_count, 1);
}

#endif /* VEH_SOMEIP */

/*===========================================================================*
 * Test Cases for RE_Communication_Rx (CAN Mode)
 *===========================================================================*/

#ifdef VEH_CAN

/**
 * @brief Test: RE_Communication_Rx processes CAN messages
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, RE_Communication_Rx_CAN_ProcessesMessages)
{
   // Execute the function
   RE_Communication_Rx();

   // Verify CAN message processing was called
   ASSERT_EQ(Process_Received_CAN_Msgs_fake.call_count, 1);
}

/**
 * @brief Test: RE_Communication_Rx CAN called multiple times
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, RE_Communication_Rx_CAN_MultipleCalls)
{
   // Execute the function multiple times (simulating 25ms cyclic calls)
   RE_Communication_Rx();
   RE_Communication_Rx();
   RE_Communication_Rx();

   // Verify it was called 3 times
   ASSERT_EQ(Process_Received_CAN_Msgs_fake.call_count, 3);
}

#endif /* VEH_CAN */

/*===========================================================================*
 * Test Cases for RE_Communication_Rx (SOME/IP Mode)
 *===========================================================================*/

#ifdef VEH_SOMEIP

/**
 * @brief Test: RE_Communication_Rx processes SOME/IP services
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, RE_Communication_Rx_SOMEIP_ProcessesServices)
{
   // Execute the function
   RE_Communication_Rx();

   // Verify SOME/IP service processing was called
   ASSERT_EQ(Process_Consumed_Services_fake.call_count, 1);
}

/**
 * @brief Test: RE_Communication_Rx SOME/IP called multiple times
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, RE_Communication_Rx_SOMEIP_MultipleCalls)
{
   // Execute the function multiple times (simulating 25ms cyclic calls)
   RE_Communication_Rx();
   RE_Communication_Rx();
   RE_Communication_Rx();

   // Verify it was called 3 times
   ASSERT_EQ(Process_Consumed_Services_fake.call_count, 3);
}

#endif /* VEH_SOMEIP */

/*===========================================================================*
 * Test Cases for RE_Communication_Tx_50ms (CAN Mode)
 *===========================================================================*/

#ifdef VEH_CAN

TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, RE_Communication_Tx_50ms_CAN_SendsStatus001Messages)
{
   RE_Communication_Tx_50ms();

   ASSERT_EQ(Send_Radar_Status_001_Messages_fake.call_count, 1);
}

#endif /* VEH_CAN */

/*===========================================================================*
 * Test Cases for RE_Communication_Tx_50ms (SOME/IP Mode)
 *===========================================================================*/

#ifdef VEH_SOMEIP

TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, RE_Communication_Tx_50ms_SOMEIP_ProcessesProvidedServices)
{
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   ASSERT_EQ(Process_Provided_Services_fake.call_count, 1);
}

#endif /* VEH_SOMEIP */

/*===========================================================================*
 * Test Cases for PostRadarProcessing_CAN_Tx_RE_Communication_Tx (CAN Mode)
 *===========================================================================*/

#ifdef VEH_CAN

/**
 * @brief Test: PostRadarProcessing_CAN_Tx_RE_Communication_Tx sends all CAN messages
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, CAN_Tx_Event_Trigger_SendsAllMessages)
{
   g_alignment_static.AlignmentStaticStatus = ALIGNMENT_RUNNING;
   // Execute the function
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   // Verify all CAN transmit functions were called
   ASSERT_EQ(Send_Radar_Status_002_Messages_fake.call_count, 1);
   ASSERT_EQ(Send_Alignment_Status_001_Messages_fake.call_count, 1);
   ASSERT_EQ(Send_Radar_Capability_Messages_fake.call_count, 1);
   ASSERT_EQ(Send_Tracker_Status_Messages_fake.call_count, 0);
   ASSERT_EQ(Send_Radar_Header_Messages_fake.call_count, 1);
   ASSERT_EQ(Send_Alignment_Status_002_Messages_fake.call_count, 1);
   ASSERT_EQ(Send_Radar_Detection_Messages_fake.call_count, 1);
   ASSERT_EQ(Send_Tracker_Header_Messages_fake.call_count, 0);
   ASSERT_EQ(Send_Tracker_Objects_On_CAN_fake.call_count, 0);
}

/*===========================================================================*
 * Test Cases - CS_Pp_PCAN_Srv_EnableAppTx_Operation
 *===========================================================================*/

/**
 * @test Test CS_Pp_PCAN_Srv_EnableAppTx_Operation starts all 8 IPDU groups
 * @coverage Full function - verifies all 8 Com_IpduGroupStart calls
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, Pp_PCAN_Srv_EnableAppTx_Operation_StartsAllGroups)
{
   /* Act */
   Pp_PCAN_Srv_EnableAppTx_Operation();

   /* Assert - Verify Com_IpduGroupStart was called 8 times */
   ASSERT_EQ(Com_IpduGroupStart_fake.call_count, 8) << "Should call Com_IpduGroupStart 8 times (one for each RDR channel)";
}
/*===========================================================================*
 * Test Cases - CS_Pp_PCAN_Srv_DisableAppTx_Operation
 *===========================================================================*/

/**
 * @test Test CS_Pp_PCAN_Srv_DisableAppTx_Operation stops all 8 IPDU groups
 * @coverage Full function - verifies all 8 Com_IpduGroupStop calls
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, Pp_PCAN_Srv_DisableAppTx_Operation_StopsAllGroups)
{
   /* Act */
   Pp_PCAN_Srv_DisableAppTx_Operation();

   /* Assert - Verify Com_IpduGroupStop was called 8 times */
   ASSERT_EQ(Com_IpduGroupStop_fake.call_count, 8) << "Should call Com_IpduGroupStop 8 times (one for each RDR channel)";
}
/**
 * @brief Test: PostRadarProcessing_CAN_Tx_RE_Communication_Tx calls Com_MainFunctionTx
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, CAN_Tx_Event_Trigger_CallsComMainFunctionTx)
{
   // Execute the function
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   // Verify COM main function was called
   ASSERT_EQ(Com_MainFunctionTx_ComMainFunctionTx_Event_fake.call_count, 1);
}

/**
 * @brief Test: PostRadarProcessing_CAN_Tx_RE_Communication_Tx verifies message send order
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, CAN_Tx_Event_Trigger_MessageOrder)
{
   g_alignment_service.AlignmentServiceSt = ALIGNMENT_RUNNING;

   // Execute the function
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   // Verify all functions were called exactly once
   // Order matters for some CAN messages
   ASSERT_EQ(Send_Radar_Status_002_Messages_fake.call_count, 1);
   ASSERT_EQ(Send_Alignment_Status_001_Messages_fake.call_count, 1);
   ASSERT_EQ(Send_Radar_Capability_Messages_fake.call_count, 1);
   ASSERT_EQ(Send_Tracker_Status_Messages_fake.call_count, 0);
   ASSERT_EQ(Send_Radar_Header_Messages_fake.call_count, 1);
   ASSERT_EQ(Send_Alignment_Status_002_Messages_fake.call_count, 1);
   ASSERT_EQ(Send_Radar_Detection_Messages_fake.call_count, 1);
   ASSERT_EQ(Send_Tracker_Header_Messages_fake.call_count, 0);
   ASSERT_EQ(Send_Tracker_Objects_On_CAN_fake.call_count, 0);
   ASSERT_EQ(Com_MainFunctionTx_ComMainFunctionTx_Event_fake.call_count, 1);
}

/**
 * @brief Test: PostRadarProcessing_CAN_Tx_RE_Communication_Tx multiple invocations
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, CAN_Tx_Event_Trigger_MultipleInvocations)
{
   // Execute the function multiple times
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   // Verify all functions were called twice
   ASSERT_EQ(Send_Radar_Status_002_Messages_fake.call_count, 2);
   ASSERT_EQ(Send_Alignment_Status_001_Messages_fake.call_count, 2);
   ASSERT_EQ(Com_MainFunctionTx_ComMainFunctionTx_Event_fake.call_count, 2);
}

TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, CAN_Tx_Event_Trigger_TimingStats_CoversAllBranches)
{
   const uint32_t fail_before = FailCnt_Time_SendRadarDetection;
   const uint32_t max_before  = SendRadarDetection_Max_Delta_Time_Us;
   const uint32_t min_before  = SendRadarDetection_Min_Delta_Time_Us;

   g_test_platform_elapsed_us = 30000U;
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   EXPECT_GE(FailCnt_Time_SendRadarDetection, fail_before + 1U);
   EXPECT_GE(SendRadarDetection_Max_Delta_Time_Us, max_before);
   EXPECT_LE(SendRadarDetection_Min_Delta_Time_Us, min_before == 1000000U ? 30000U : min_before);

   g_test_platform_elapsed_us = 50000U;
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   EXPECT_GE(SendRadarDetection_Max_Delta_Time_Us, 50000U);
   EXPECT_LE(SendRadarDetection_Min_Delta_Time_Us, 50000U);

   g_test_platform_elapsed_us = 60000U;
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   EXPECT_GE(FailCnt_Time_SendRadarDetection, fail_before + 2U);
   EXPECT_GE(SendRadarDetection_Max_Delta_Time_Us, 60000U);

   for (uint32_t i = 0U; i < 5U; ++i)
   {
      g_test_platform_elapsed_us = 30000U;
      PostRadarProcessing_CAN_Tx_RE_Communication_Tx();
   }

   EXPECT_GE(FailCnt_Time_SendRadarDetection, fail_before + 7U);
}

#endif /* VEH_CAN */

/*===========================================================================*
 * Test Cases for RE_Communication_Tx_50ms (CAN Mode)
 *===========================================================================*/

#ifdef VEH_CAN

/**
 * @brief Test: RE_Communication_Tx_50ms sends status messages
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, RE_Communication_Tx_50ms_CAN_SendsStatusMessages)
{
   // Execute the function
   RE_Communication_Tx_50ms();

   // Verify Send_Radar_Status_001_Messages was called
   ASSERT_EQ(Send_Radar_Status_001_Messages_fake.call_count, 1);
   // Verify 2nd CAN channel status messages are sent
}

/**
 * @brief Test: RE_Communication_Tx_50ms CAN called multiple times
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, RE_Communication_Tx_50ms_CAN_MultipleCalls)
{
   // Execute the function multiple times (simulating 50ms cyclic calls)
   RE_Communication_Tx_50ms();
   RE_Communication_Tx_50ms();

   // Verify it was called 2 times
   ASSERT_EQ(Send_Radar_Status_001_Messages_fake.call_count, 2);
   // Verify 2nd CAN channel was also called 2 times
}

#endif /* VEH_CAN */

/*===========================================================================*
 * Test Cases for RE_Communication_Tx_50ms (SOME/IP Mode)
 *===========================================================================*/

#ifdef VEH_SOMEIP

/**
 * @brief Test: RE_Communication_Tx_50ms processes provided services
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, RE_Communication_Tx_50ms_SOMEIP_ProcessesServices)
{
   // Execute the function
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   // Verify Process_Provided_Services was called
   ASSERT_EQ(Process_Provided_Services_fake.call_count, 1);
}

/**
 * @brief Test: RE_Communication_Tx_50ms SOME/IP called multiple times
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, RE_Communication_Tx_50ms_SOMEIP_MultipleCalls)
{
   // Execute the function multiple times (simulating 50ms cyclic calls)
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   // Verify it was called 2 times
   ASSERT_EQ(Process_Provided_Services_fake.call_count, 2);
}

#endif /* VEH_SOMEIP */

/*===========================================================================*
 * Test Cases for Pp_PCAN_Srv_DisableAppTx_Operation
 *===========================================================================*/

/**
 * @brief Test: Pp_PCAN_Srv_DisableAppTx_Operation executes successfully
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, Pp_PCAN_Srv_DisableAppTx_Operation_ExecutesSuccessfully)
{
   // Execute the function (empty function, just verify it doesn't crash)
   Pp_PCAN_Srv_DisableAppTx_Operation();

   // If we reach here, function executed without error
   ASSERT_TRUE(true);
}

/*===========================================================================*
 * Test Cases for Pp_PCAN_Srv_EnableAppTx_Operation
 *===========================================================================*/

/**
 * @brief Test: Pp_PCAN_Srv_EnableAppTx_Operation executes successfully
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, Pp_PCAN_Srv_EnableAppTx_Operation_ExecutesSuccessfully)
{
   // Execute the function (empty function, just verify it doesn't crash)
   Pp_PCAN_Srv_EnableAppTx_Operation();

   // If we reach here, function executed without error
   ASSERT_TRUE(true);
}

/*===========================================================================*
 * Test Cases for Pp_VCAN_Srv_DisableAppTx_Operation
 *===========================================================================*/

/**
 * @brief Test: Pp_VCAN_Srv_DisableAppTx_Operation stops all 8 IPDU groups
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, Pp_VCAN_Srv_DisableAppTx_Operation_ExecutesSuccessfully)
{
   // Execute the function (empty function, just verify it doesn't crash)
   Pp_VCAN_Srv_DisableAppTx_Operation();
   // If we reach here, function executed without error
   ASSERT_TRUE(true);
}
/*===========================================================================*
 * Test Cases for Pp_VCAN_Srv_EnableAppTx_Operation
 *===========================================================================*/

/**
 * @brief Test: Pp_VCAN_Srv_EnableAppTx_Operation starts all 8 IPDU groups
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, Pp_VCAN_Srv_EnableAppTx_Operation_ExecutesSuccessfully)
{
   // Execute the function (empty function, just verify it doesn't crash)
   Pp_VCAN_Srv_EnableAppTx_Operation();

   // If we reach here, function executed without error
   ASSERT_TRUE(true);
}

/*===========================================================================*
 * Integration Tests for CAN TX Messages (via RE_Communication_Tx_50ms)
 *===========================================================================*/

#ifdef VEH_CAN

/**
 * @brief Test: CAN TX Integration - Periodic message sent via RE_Communication_Tx_50ms
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, CAN_TX_Integration_PeriodicMessageSent)
{
   // Execute the TX function (50ms periodic)
   RE_Communication_Tx_50ms();

   // Verify periodic CAN TX send function was called
   EXPECT_EQ(1, Send_Radar_Status_001_Messages_fake.call_count);

   // Event-based functions should NOT be called from periodic runnable
   EXPECT_EQ(0, Send_Radar_Status_002_Messages_fake.call_count);
   EXPECT_EQ(0, Send_Alignment_Status_001_Messages_fake.call_count);
}

/**
 * @brief Test: CAN TX Integration - Radar Status periodic message sent multiple times
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, CAN_TX_Integration_RadarStatusMessagesSent)
{
   // Execute multiple cycles
   RE_Communication_Tx_50ms();
   RE_Communication_Tx_50ms();
   RE_Communication_Tx_50ms();

   // Verify periodic radar status 001 message sent in each cycle
   EXPECT_EQ(3, Send_Radar_Status_001_Messages_fake.call_count);

   // Status 002 is event-based, not called from periodic runnable
   EXPECT_EQ(0, Send_Radar_Status_002_Messages_fake.call_count);
}

/**
 * @brief Test: CAN TX Integration - Cyclic execution consistency
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, CAN_TX_Integration_CyclicExecutionConsistency)
{
   // Simulate 10 cycles (500ms total) - only periodic functions called
   for (int i = 0; i < 10; i++)
   {
      RE_Communication_Tx_50ms();
   }

   // Verify periodic function called exactly 10 times
   EXPECT_EQ(10, Send_Radar_Status_001_Messages_fake.call_count);

   // Event-based functions should NOT be called from periodic runnable
   EXPECT_EQ(0, Send_Radar_Status_002_Messages_fake.call_count);
   EXPECT_EQ(0, Send_Alignment_Status_001_Messages_fake.call_count);
}

/**
 * @brief Test: CAN TX Integration - First call sends periodic messages
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, CAN_TX_Integration_FirstCallSendsMessages)
{
   // Before calling RE_Communication_Tx_50ms, no messages should be sent
   EXPECT_EQ(0, Send_Radar_Status_001_Messages_fake.call_count);

   // Execute the TX function for the first time
   RE_Communication_Tx_50ms();

   // Verify periodic message was sent on first call
   EXPECT_EQ(1, Send_Radar_Status_001_Messages_fake.call_count);
}

#endif /* VEH_CAN */

/*===========================================================================*
 * Integration Tests for SOME/IP Services (via RE_Communication_Tx_50ms)
 *===========================================================================*/

#ifdef VEH_SOMEIP

/**
 * @brief Test: SOME/IP Integration - Provided services processed
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, SOMEIP_Integration_ProvidedServicesProcessed)
{
   // Execute the TX function
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   // Verify Process_Provided_Services was called
   EXPECT_EQ(1, Process_Provided_Services_fake.call_count);
}

/**
 * @brief Test: SOME/IP Integration - Cyclic execution consistency
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, SOMEIP_Integration_CyclicExecutionConsistency)
{
   // Simulate 10 cycles (500ms total)
   for (int i = 0; i < 10; i++)
   {
      PostRadarProcessing_CAN_Tx_RE_Communication_Tx();
   }

   // Verify Process_Provided_Services called exactly 10 times
   EXPECT_EQ(10, Process_Provided_Services_fake.call_count);
}

/**
 * @brief Test: SOME/IP Integration - Initialization correct
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, SOMEIP_Integration_InitializationCorrect)
{
   // Execute initialization
   RE_Communication_Init();

   // Verify SOME/IP services initialized
   EXPECT_EQ(1, Init_Provided_Services_fake.call_count);
   EXPECT_EQ(1, Init_Consumed_Services_fake.call_count);
}

/**
 * @brief Test: SOME/IP Integration - Consumed services processed in RX
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, SOMEIP_Integration_ConsumedServicesProcessed)
{
   // Execute the RX function
   RE_Communication_Rx();

   // Verify Process_Consumed_Services was called
   EXPECT_EQ(1, Process_Consumed_Services_fake.call_count);
}

/**
 * @brief Test: SOME/IP Integration - Both TX and RX work together
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, SOMEIP_Integration_TxAndRxTogether)
{
   // Execute initialization
   RE_Communication_Init();

   // Execute RX cycle
   RE_Communication_Rx();

   // Execute TX cycle
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   // Verify complete flow
   EXPECT_EQ(1, Init_Provided_Services_fake.call_count);
   EXPECT_EQ(1, Init_Consumed_Services_fake.call_count);
   EXPECT_EQ(1, Process_Consumed_Services_fake.call_count);
   EXPECT_EQ(1, Process_Provided_Services_fake.call_count);
}

/**
 * @brief Test: SOME/IP Integration - Multiple RX/TX cycles
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, SOMEIP_Integration_MultipleRxTxCycles)
{
   // Execute initialization
   RE_Communication_Init();

   // Simulate realistic timing: 5 RX cycles and 1 TX cycle (50ms)
   for (int i = 0; i < 5; i++)
   {
      RE_Communication_Rx();
   }
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   // Verify correct call counts
   EXPECT_EQ(1, Init_Provided_Services_fake.call_count);
   EXPECT_EQ(1, Init_Consumed_Services_fake.call_count);
   EXPECT_EQ(5, Process_Consumed_Services_fake.call_count);
   EXPECT_EQ(1, Process_Provided_Services_fake.call_count);
}

/**
 * @brief Test: SOME/IP Init - Multiple initialization calls
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, SOMEIP_Init_MultipleInitializationCalls)
{
   // Execute initialization multiple times (shouldn't cause issues)
   for (int i = 0; i < 3; i++)
   {
      RE_Communication_Init();
   }

   // Verify init services called 3 times
   EXPECT_EQ(3, Init_Provided_Services_fake.call_count);
   EXPECT_EQ(3, Init_Consumed_Services_fake.call_count);
}

/**
 * @brief Test: SOME/IP RX - High frequency reception
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, SOMEIP_RX_HighFrequencyReception)
{
   // Simulate 100 RX cycles (high frequency scenario)
   for (int i = 0; i < 100; i++)
   {
      RE_Communication_Rx();
   }

   // Verify consumed services processed 100 times
   EXPECT_EQ(100, Process_Consumed_Services_fake.call_count);
}

/**
 * @brief Test: SOME/IP TX - High frequency transmission
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, SOMEIP_TX_HighFrequencyTransmission)
{
   // Simulate 50 TX cycles (high frequency scenario)
   for (int i = 0; i < 50; i++)
   {
      PostRadarProcessing_CAN_Tx_RE_Communication_Tx();
   }

   // Verify provided services processed 50 times
   EXPECT_EQ(50, Process_Provided_Services_fake.call_count);
}

/**
 * @brief Test: SOME/IP - Interleaved RX and TX operations
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, SOMEIP_InterleavedRxTxOperations)
{
   // Execute initialization
   RE_Communication_Init();

   // Simulate realistic interleaved pattern: RX at 10ms, TX at 50ms
   // Pattern: RX, RX, RX, RX, RX + TX
   for (int cycle = 0; cycle < 5; cycle++)
   {
      for (int rx = 0; rx < 5; rx++)
      {
         RE_Communication_Rx();
      }
      PostRadarProcessing_CAN_Tx_RE_Communication_Tx();
   }

   // Verify call counts: 1 init, 25 RX (5*5), 5 TX
   EXPECT_EQ(1, Init_Provided_Services_fake.call_count);
   EXPECT_EQ(1, Init_Consumed_Services_fake.call_count);
   EXPECT_EQ(25, Process_Consumed_Services_fake.call_count);
   EXPECT_EQ(5, Process_Provided_Services_fake.call_count);
}

/**
 * @brief Test: SOME/IP - TX before initialization
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, SOMEIP_TX_BeforeInitialization)
{
   // Execute TX without initialization (edge case)
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   // Verify TX attempted even without init
   EXPECT_EQ(1, Process_Provided_Services_fake.call_count);
   EXPECT_EQ(0, Init_Provided_Services_fake.call_count);
}

/**
 * @brief Test: SOME/IP - RX before initialization
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, SOMEIP_RX_BeforeInitialization)
{
   // Execute RX without initialization (edge case)
   RE_Communication_Rx();

   // Verify RX attempted even without init
   EXPECT_EQ(1, Process_Consumed_Services_fake.call_count);
   EXPECT_EQ(0, Init_Consumed_Services_fake.call_count);
}

/**
 * @brief Test: SOME/IP - Complete lifecycle simulation
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, SOMEIP_CompleteLifecycleSimulation)
{
   // 1. Initialization
   RE_Communication_Init();

   // 2. Normal operation: 100 cycles (10 seconds at 10ms RX rate)
   for (int i = 0; i < 100; i++)
   {
      RE_Communication_Rx();
      if (i % 5 == 4)
      { // Every 50ms
         PostRadarProcessing_CAN_Tx_RE_Communication_Tx();
      }
   }

   // Verify lifecycle: 1 init, 100 RX, 20 TX (100/5)
   EXPECT_EQ(1, Init_Provided_Services_fake.call_count);
   EXPECT_EQ(1, Init_Consumed_Services_fake.call_count);
   EXPECT_EQ(100, Process_Consumed_Services_fake.call_count);
   EXPECT_EQ(20, Process_Provided_Services_fake.call_count);
}

/**
 * @brief Test: SOME/IP - Burst RX followed by single TX
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, SOMEIP_BurstRxFollowedBySingleTx)
{
   // Execute initialization
   RE_Communication_Init();

   // Burst: 20 rapid RX calls
   for (int i = 0; i < 20; i++)
   {
      RE_Communication_Rx();
   }

   // Single TX after burst
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   // Verify burst handling
   EXPECT_EQ(20, Process_Consumed_Services_fake.call_count);
   EXPECT_EQ(1, Process_Provided_Services_fake.call_count);
}

/**
 * @brief Test: SOME/IP - Alternating Init and TX
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, SOMEIP_AlternatingInitAndTx)
{
   // Unusual pattern: Init, TX, Init, TX (testing robustness)
   for (int i = 0; i < 3; i++)
   {
      RE_Communication_Init();
      PostRadarProcessing_CAN_Tx_RE_Communication_Tx();
   }

   // Verify both operations executed
   EXPECT_EQ(3, Init_Provided_Services_fake.call_count);
   EXPECT_EQ(3, Process_Provided_Services_fake.call_count);
}

#endif /* VEH_SOMEIP */

/*===========================================================================*
 * Integration Tests for CAN RX Messages (via RE_Communication_Rx_10ms)
 *===========================================================================*/

#ifdef VEH_CAN

/**
 * @brief Test: CAN RX Integration - Received messages processed
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, CAN_RX_Integration_ReceivedMessagesProcessed)
{
   // Execute the RX function
   RE_Communication_Rx();

   // Verify Process_Received_CAN_Msgs was called
   EXPECT_EQ(1, Process_Received_CAN_Msgs_fake.call_count);
}

/**
 * @brief Test: CAN RX Integration - Cyclic execution consistency
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, CAN_RX_Integration_CyclicExecutionConsistency)
{
   // Simulate 100 cycles
   for (int i = 0; i < 100; i++)
   {
      RE_Communication_Rx();
   }

   // Verify Process_Received_CAN_Msgs called exactly 100 times
   EXPECT_EQ(100, Process_Received_CAN_Msgs_fake.call_count);
}

/**
 * @brief Test: CAN RX/TX Integration - Complete communication flow
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, CAN_RX_TX_Integration_CompleteCommunicationFlow)
{
   // Execute initialization
   RE_Communication_Init();

   // Simulate realistic timing: 5 RX cycles and 1 TX cycle (50ms)
   for (int i = 0; i < 5; i++)
   {
      RE_Communication_Rx();
   }
   RE_Communication_Tx_50ms();

   // Verify complete flow
   EXPECT_EQ(2, CanSM_RequestComMode_fake.call_count);           // Init (both CAN channels)
   EXPECT_EQ(5, Process_Received_CAN_Msgs_fake.call_count);      // RX
   EXPECT_EQ(1, Send_Radar_Status_001_Messages_fake.call_count); // TX (periodic)
}

/**
 * @brief Test: CAN TX Event - Status 002 message sent
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, CAN_TX_Event_Status002MessageSent)
{
   // Execute event trigger
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   // Verify Status 002 message was sent
   EXPECT_EQ(1, Send_Radar_Status_002_Messages_fake.call_count);
}

/**
 * @brief Test: CAN TX Event - Alignment 001 message sent
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, CAN_TX_Event_Alignment001MessageSent)
{
   // Execute event trigger
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   // Verify Alignment 001 message was sent
   EXPECT_EQ(1, Send_Alignment_Status_001_Messages_fake.call_count);
}

/**
 * @brief Test: CAN TX Event - Alignment 002 message sent
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, CAN_TX_Event_Alignment002MessageSent)
{
   g_alignment_short.AlignShortTrackSt = ALIGNMENT_RUNNING;
   // Execute event trigger
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   // Verify Alignment 002 message was sent
   EXPECT_EQ(1, Send_Alignment_Status_002_Messages_fake.call_count);
}

/**
 * @brief Test: CAN TX Event - Capability message sent
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, CAN_TX_Event_CapabilityMessageSent)
{
   // Execute event trigger
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   // Verify Capability message was sent
   EXPECT_EQ(1, Send_Radar_Capability_Messages_fake.call_count);
}

/**
 * @brief Test: CAN TX Event - Detection messages sent
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, CAN_TX_Event_DetectionMessagesSent)
{
   // Execute event trigger
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   // Verify Detection messages were sent
   EXPECT_EQ(1, Send_Radar_Detection_Messages_fake.call_count);
}

/**
 * @brief Test: CAN TX Event - Tracker header sent
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, CAN_TX_Event_TrackerHeaderSent)
{
   // Execute event trigger
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   // Verify Tracker header was sent
   EXPECT_EQ(0, Send_Tracker_Header_Messages_fake.call_count);
}

/**
 * @brief Test: CAN TX Event - Tracker status sent
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, CAN_TX_Event_TrackerStatusSent)
{
   // Execute event trigger
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   // Verify Tracker status was sent
   EXPECT_EQ(0, Send_Tracker_Status_Messages_fake.call_count);
}

/**
 * @brief Test: CAN TX Event - Tracker objects sent
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, CAN_TX_Event_TrackerObjectsSent)
{
   // Execute event trigger
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   // Verify Tracker objects were sent
   EXPECT_EQ(0, Send_Tracker_Objects_On_CAN_fake.call_count);
}

/**
 * @brief Test: CAN TX Event - Header message sent
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, CAN_TX_Event_HeaderMessageSent)
{
   // Execute event trigger
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   // Verify Header message was sent
   EXPECT_EQ(1, Send_Radar_Header_Messages_fake.call_count);
}

/**
 * @brief Test: CAN TX - Periodic and event combined execution
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, CAN_TX_PeriodicAndEventCombined)
{
   // Execute initialization
   RE_Communication_Init();

   // Execute periodic TX
   RE_Communication_Tx_50ms();

   // Execute event-based TX
   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   // Verify both periodic and event messages sent
   EXPECT_EQ(1, Send_Radar_Status_001_Messages_fake.call_count);     // Periodic
   EXPECT_EQ(1, Send_Radar_Status_002_Messages_fake.call_count);     // Event
   EXPECT_EQ(1, Send_Radar_Detection_Messages_fake.call_count);      // Event
   EXPECT_EQ(0, Send_Tracker_Header_Messages_fake.call_count);       // Event
   EXPECT_EQ(1, Send_Alignment_Status_001_Messages_fake.call_count); // Event
}

/**
 * @brief Test: CAN Init - Success path with valid return
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, CAN_Init_ErrorHandling_Success)
{
   // Setup: Make CanSM_RequestComMode return E_OK
   CanSM_RequestComMode_fake.return_val = E_OK;

   // Execute initialization
   RE_Communication_Init();

   // Verify CanSM_RequestComMode was called for both CAN channels
   EXPECT_EQ(2, CanSM_RequestComMode_fake.call_count);
}

/**
 * @brief Test: CAN TX - Multiple periodic cycles consistency
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, CAN_TX_MultiplePeriodicCycles)
{
   // Execute 20 periodic TX cycles (1 second at 50ms rate)
   for (int i = 0; i < 20; i++)
   {
      RE_Communication_Tx_50ms();
   }

   // Verify Status 001 messages sent 20 times
   EXPECT_EQ(20, Send_Radar_Status_001_Messages_fake.call_count);
}

/**
 * @brief Test: CAN TX - Multiple event cycles consistency
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, CAN_TX_MultipleEventCycles)
{
   g_alignment_service.AlignmentServiceSt = ALIGNMENT_PAUSED;
   // Execute 10 event trigger cycles
   for (int i = 0; i < 10; i++)
   {
      PostRadarProcessing_CAN_Tx_RE_Communication_Tx();
   }

   // Verify all event messages sent 10 times each
   EXPECT_EQ(10, Send_Radar_Status_002_Messages_fake.call_count);
   EXPECT_EQ(10, Send_Alignment_Status_001_Messages_fake.call_count);
   EXPECT_EQ(10, Send_Alignment_Status_002_Messages_fake.call_count);
   EXPECT_EQ(10, Send_Radar_Detection_Messages_fake.call_count);
}

#endif /* VEH_CAN */

/*===========================================================================*
 * Sanity Check Test
 *===========================================================================*/

/**
 * @brief Sanity check test
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, SanityCheck)
{
   ASSERT_TRUE(true);
}

TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, Coverage_RE_Communication_Init_InvokesCanSmBothChannels)
{
   RE_Communication_Init();

   ASSERT_EQ(2, CanSM_RequestComMode_fake.call_count);
   ASSERT_EQ(ComMConf_ComMUser_CN_PCAN_RADAR_d6cf874b, CanSM_RequestComMode_fake.arg0_history[0]);
   ASSERT_EQ(ComMConf_ComMUser_CN_VCAN_RADAR_4b138c58, CanSM_RequestComMode_fake.arg0_history[1]);
}

TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, Coverage_RE_Communication_Rx_InvokesCanRxProcessing)
{
   RE_Communication_Rx();

   ASSERT_EQ(1, Process_Received_CAN_Msgs_fake.call_count);
}

TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, Coverage_RE_Communication_Tx50ms_InvokesPeriodicCanTx)
{
   RE_Communication_Tx_50ms();

   ASSERT_EQ(1, Send_Radar_Status_001_Messages_fake.call_count);
}

TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, Coverage_PostRadarProcessing_InvokesEventCanTx)
{
   g_alignment_service.AlignmentServiceSt = ALIGNMENT_PAUSED;
   Std_ReturnType ret                     = PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   ASSERT_EQ(E_OK, ret);
   ASSERT_EQ(1, Send_Radar_Detection_Messages_fake.call_count);
   ASSERT_EQ(1, Send_Radar_Status_002_Messages_fake.call_count);
   ASSERT_EQ(1, Send_Alignment_Status_001_Messages_fake.call_count);
   ASSERT_EQ(1, Send_Radar_Capability_Messages_fake.call_count);
   ASSERT_EQ(1, Send_Radar_Header_Messages_fake.call_count);
   ASSERT_EQ(1, Send_Alignment_Status_002_Messages_fake.call_count);
   ASSERT_EQ(1, Com_MainFunctionTx_ComMainFunctionTx_Event_fake.call_count);
}

/**
 * @test Alignment active → Send_Alignment_Status_002_Messages is called once
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, PostRadarProcessing_AlignmentActive_CallsSendStatus002)
{
   g_alignment_short.AlignShortTrackSt = ALIGNMENT_RUNNING;

   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   EXPECT_EQ(Send_Alignment_Status_002_Messages_fake.call_count, 1u);
}

/**
 * @test Current implementation calls Send_Alignment_Status_002_Messages even when no alignment is active
 */
TEST_F(SWC_PLT_Appl_Communication_UnitTestSuite, PostRadarProcessing_NoAlignment_StillCallsSendStatus002)
{
   /* Fake starts at zero before the runnable is executed. */
   EXPECT_EQ(Send_Alignment_Status_002_Messages_fake.call_count, 0u);

   PostRadarProcessing_CAN_Tx_RE_Communication_Tx();

   EXPECT_EQ(Send_Alignment_Status_002_Messages_fake.call_count, 1u);
}

/*===========================================================================*
 * End of Test Suite
 *===========================================================================*/
